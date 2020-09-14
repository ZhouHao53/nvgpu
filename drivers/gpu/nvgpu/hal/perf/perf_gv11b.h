/*
 * Copyright (c) 2018-2020, NVIDIA CORPORATION.  All rights reserved.
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

#ifndef NVGPU_GV11B_PERF
#define NVGPU_GV11B_PERF

#ifdef CONFIG_NVGPU_DEBUGGER

#include <nvgpu/types.h>

struct gk20a;
struct nvgpu_mem;

bool gv11b_perf_get_membuf_overflow_status(struct gk20a *g);
u32 gv11b_perf_get_membuf_pending_bytes(struct gk20a *g);
void gv11b_perf_set_membuf_handled_bytes(struct gk20a *g,
	u32 entries, u32 entry_size);

void gv11b_perf_membuf_reset_streaming(struct gk20a *g);

void gv11b_perf_enable_membuf(struct gk20a *g, u32 size, u64 buf_addr);
void gv11b_perf_disable_membuf(struct gk20a *g);

void gv11b_perf_bind_mem_bytes_buffer_addr(struct gk20a *g, u64 buf_addr);

int gv11b_perf_update_get_put(struct gk20a *g, u64 bytes_consumed, bool update_available_bytes,
		u64 *put_ptr, bool *overflowed);

void gv11b_perf_init_inst_block(struct gk20a *g, struct nvgpu_mem *inst_block);
void gv11b_perf_deinit_inst_block(struct gk20a *g);

u32 gv11b_perf_get_pmmsys_per_chiplet_offset(void);
u32 gv11b_perf_get_pmmgpc_per_chiplet_offset(void);
u32 gv11b_perf_get_pmmfbp_per_chiplet_offset(void);

const u32 *gv11b_perf_get_hwpm_sys_perfmon_regs(u32 *count);
const u32 *gv11b_perf_get_hwpm_gpc_perfmon_regs(u32 *count);
const u32 *gv11b_perf_get_hwpm_fbp_perfmon_regs(u32 *count);

#endif /* CONFIG_NVGPU_DEBUGGER */
#endif
