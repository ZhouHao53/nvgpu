/*
 * Copyright (c) 2020-2022, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <nvgpu/log.h>
#include <nvgpu/io.h>
#include <nvgpu/soc.h>
#include <nvgpu/bug.h>
#include <nvgpu/gk20a.h>
#include <nvgpu/cic_mon.h>
#include <nvgpu/nvgpu_err.h>

#include "bus_ga10b.h"

#include <nvgpu/hw/ga10b/hw_bus_ga10b.h>

static u32 bus_intr0_pri_mask(void)
{
	u32 mask = bus_intr_0_pri_fecserr_m() |
		bus_intr_0_pri_timeout_m();

	return mask;
}

static u32 bus_intr_0_fb_mask(void)
{
	u32 mask = bus_intr_0_fb_req_timeout_m() |
		bus_intr_0_fb_ack_timeout_m() |
		bus_intr_0_fb_ack_extra_m() |
		bus_intr_0_fb_rdata_timeout_m() |
		bus_intr_0_fb_rdata_extra_m();

	return mask;
}

int ga10b_bus_init_hw(struct gk20a *g)
{
	u32 intr_en_mask = 0;

	/*
	 * pbus: pri related interrupts which are generated when fecs could
	 * communicate error back to host. This is the case of non-posted
	 * transactions (generally reads)
	 * pri_fecserr: This bit is set when a pri request returns from fecs
	 * with error status.
	 * pri_timeout: This bit is set when a pri request to anywhere is
	 * discarded due to timeout.
	 * priv_ring: pri error in pri hub that could not be reported to host
	 * (error on a posted transaction generally writes).
	 */
	intr_en_mask =  bus_intr_en_0_pri_fecserr_m() |
			bus_intr_en_0_pri_timeout_m() |
			bus_intr_en_0_fb_req_timeout_m() |
			bus_intr_en_0_fb_ack_timeout_m() |
			bus_intr_en_0_fb_ack_extra_m() |
			bus_intr_en_0_fb_rdata_timeout_m() |
			bus_intr_en_0_fb_rdata_extra_m() |
			bus_intr_en_0_sw_m() |
			bus_intr_en_0_posted_deadlock_timeout_m() |
			bus_intr_en_0_mpmu_m() |
			bus_intr_en_0_access_timeout_m();

	nvgpu_log_info(g, "bus fb_timeout=0x%x",
		bus_fb_timeout_period_v(nvgpu_readl(g,  bus_fb_timeout_r())));

	nvgpu_cic_mon_intr_stall_unit_config(g, NVGPU_CIC_INTR_UNIT_BUS, NVGPU_CIC_INTR_ENABLE);

	nvgpu_writel(g, bus_intr_en_0_r(), intr_en_mask);
	return 0;
}

void ga10b_bus_isr(struct gk20a *g)
{
	u32 bus_intr_0 = 0U;
	u32 err_type = GPU_HOST_PBUS_TIMEOUT_ERROR;
	u32 bus_intr_0_handled = 0U;

	bus_intr_0 = nvgpu_readl(g, bus_intr_0_r());

	/*
	 * These bits signal that a PRI transaction has failed or timed out
	 * pri_fecserr_m(): fecs initiated PRI transaction failed.
	 * pri_timeout_m(): PRI transaction timed out.
	 */
	if ((bus_intr_0 & bus_intr0_pri_mask()) != 0U) {
		if ((bus_intr_0 & bus_intr_0_pri_fecserr_m()) != 0U) {
			err_type = GPU_HOST_PBUS_FECS_ERROR;
		}
		g->ops.ptimer.isr(g);

		bus_intr_0_handled |= (bus_intr_0 & bus_intr0_pri_mask());
	}

	/*
	 * These bits indicate fatal errors in the CPU-to-Frame buffer memory.
	 */
	if ((bus_intr_0 & bus_intr_0_fb_mask()) != 0U) {
		nvgpu_err(g, "errors detected on FB access path, status: 0x%08x",
				bus_intr_0 & bus_intr_0_fb_mask());
		bus_intr_0_handled |= (bus_intr_0 & bus_intr_0_fb_mask());
	}

	/*
	 * Indicates a software interrupt, generated by writing 1 to
	 * NV_PBUS_SW_INTR_0.
	 */
	if ((bus_intr_0 & bus_intr_0_sw_m()) != 0U) {
		nvgpu_err(g, "software interrupt");
		bus_intr_0_handled |= bus_intr_0_sw_m();
	}

	/*
	 * This bit is set when a deadlock on the posted path is detected.
	 */
	if ((bus_intr_0 & bus_intr_0_posted_deadlock_timeout_m()) != 0U) {
		nvgpu_err(g, "deadlock on posted transaction");
		bus_intr_0_handled |= bus_intr_0_posted_deadlock_timeout_m();
	}

	/*
	 * Indicates an interrupt from mpmu
	 */
	if ((bus_intr_0 & bus_intr_0_mpmu_m()) != 0U) {
		nvgpu_err(g, "interrupt from MPMU");
		bus_intr_0_handled |= bus_intr_0_mpmu_m();
	}

	/*
	 * Indicates that a request from a sideband requester has timed out.
	 */
	if ((bus_intr_0 & bus_intr_0_access_timeout_m()) != 0U) {
		nvgpu_err(g, "access timeout detected on sideband requester");
		bus_intr_0_handled |= bus_intr_0_access_timeout_m();
	}

	if (bus_intr_0 != bus_intr_0_handled) {
		nvgpu_err(g, "unhandled interrupts, status: 0x%x",
				bus_intr_0 & ~bus_intr_0_handled);
	}

	nvgpu_report_err_to_sdl(g, err_type);
	nvgpu_writel(g, bus_intr_0_r(), bus_intr_0);
}
