/*
 * Copyright (c) 2017-2019, NVIDIA CORPORATION.  All rights reserved.
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
/*
 * Function/Macro naming determines intended use:
 *
 *     <x>_r(void) : Returns the offset for register <x>.
 *
 *     <x>_o(void) : Returns the offset for element <x>.
 *
 *     <x>_w(void) : Returns the word offset for word (4 byte) element <x>.
 *
 *     <x>_<y>_s(void) : Returns size of field <y> of register <x> in bits.
 *
 *     <x>_<y>_f(u32 v) : Returns a value based on 'v' which has been shifted
 *         and masked to place it at field <y> of register <x>.  This value
 *         can be |'d with others to produce a full register value for
 *         register <x>.
 *
 *     <x>_<y>_m(void) : Returns a mask for field <y> of register <x>.  This
 *         value can be ~'d and then &'d to clear the value of field <y> for
 *         register <x>.
 *
 *     <x>_<y>_<z>_f(void) : Returns the constant value <z> after being shifted
 *         to place it at field <y> of register <x>.  This value can be |'d
 *         with others to produce a full register value for <x>.
 *
 *     <x>_<y>_v(u32 r) : Returns the value of field <y> from a full register
 *         <x> value 'r' after being shifted to place its LSB at bit 0.
 *         This value is suitable for direct comparison with other unshifted
 *         values appropriate for use in field <y> of register <x>.
 *
 *     <x>_<y>_<z>_v(void) : Returns the constant value for <z> defined for
 *         field <y> of register <x>.  This value is suitable for direct
 *         comparison with unshifted values appropriate for use in field <y>
 *         of register <x>.
 */
#ifndef NVGPU_HW_FB_GV100_H
#define NVGPU_HW_FB_GV100_H

#include <nvgpu/types.h>
#include <nvgpu/safe_ops.h>

#define fb_fbhub_num_active_ltcs_r()                               (0x00100800U)
#define fb_fbhub_num_active_ltcs_use_nvlink_f(v)       ((U32(v) & 0xffU) << 16U)
#define fb_fbhub_num_active_ltcs_use_nvlink_m()              (U32(0xffU) << 16U)
#define fb_fbhub_num_active_ltcs_use_nvlink_v(r)          (((r) >> 16U) & 0xffU)
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_f(v, i)\
		((U32(v) & 0x1U) << (16U + (i)*1U))
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_m(i)\
		(U32(0x1U) << (16U + (i)*1U))
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_v(r, i)\
		(((r) >> (16U + i*1U)) & 0x1U)
#define fb_fbhub_num_active_ltcs_use_nvlink_peer___size_1_v()      (0x00000008U)
#define fb_fbhub_num_active_ltcs_use_nvlink_peer___size_1_f(i)\
		((0x0U << (32U +((i)*1U))))
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_enabled_v()       (0x00000001U)
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_enabled_f(i)\
		((0x1U << (32U +((i)*1U))))
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_disabled_v()      (0x00000000U)
#define fb_fbhub_num_active_ltcs_use_nvlink_peer_disabled_f(i)\
		((0x0U << (32U +((i)*1U))))
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_f(v)\
				((U32(v) & 0x1U) << 25U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_m()      (U32(0x1U) << 25U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_v(r)  (((r) >> 25U) & 0x1U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_use_read_v()  (0x00000000U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_use_read_f()         (0x0U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_use_rmw_v()   (0x00000001U)
#define fb_fbhub_num_active_ltcs_hub_sys_atomic_mode_use_rmw_f()    (0x2000000U)
#define fb_mmu_ctrl_r()                                            (0x00100c80U)
#define fb_mmu_ctrl_pri_fifo_empty_v(r)                    (((r) >> 15U) & 0x1U)
#define fb_mmu_ctrl_pri_fifo_empty_false_f()                              (0x0U)
#define fb_mmu_ctrl_pri_fifo_space_v(r)                   (((r) >> 16U) & 0xffU)
#define fb_mmu_ctrl_atomic_capability_mode_f(v)         ((U32(v) & 0x3U) << 24U)
#define fb_mmu_ctrl_atomic_capability_mode_m()                (U32(0x3U) << 24U)
#define fb_mmu_ctrl_atomic_capability_mode_v(r)            (((r) >> 24U) & 0x3U)
#define fb_mmu_ctrl_atomic_capability_mode_l2_v()                  (0x00000000U)
#define fb_mmu_ctrl_atomic_capability_mode_l2_f()                         (0x0U)
#define fb_mmu_ctrl_atomic_capability_mode_atomic_v()              (0x00000001U)
#define fb_mmu_ctrl_atomic_capability_mode_atomic_f()               (0x1000000U)
#define fb_mmu_ctrl_atomic_capability_mode_rmw_v()                 (0x00000002U)
#define fb_mmu_ctrl_atomic_capability_mode_rmw_f()                  (0x2000000U)
#define fb_mmu_ctrl_atomic_capability_mode_power_v()               (0x00000003U)
#define fb_mmu_ctrl_atomic_capability_mode_power_f()                (0x3000000U)
#define fb_hsmmu_pri_mmu_ctrl_r()                                  (0x001fac80U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_f(v)\
				((U32(v) & 0x3U) << 24U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_m()      (U32(0x3U) << 24U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_v(r)  (((r) >> 24U) & 0x3U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_l2_v()        (0x00000000U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_l2_f()               (0x0U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_atomic_v()    (0x00000001U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_atomic_f()     (0x1000000U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_rmw_v()       (0x00000002U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_rmw_f()        (0x2000000U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_power_v()     (0x00000003U)
#define fb_hsmmu_pri_mmu_ctrl_atomic_capability_mode_power_f()      (0x3000000U)
#define fb_hsmmu_pri_mmu_debug_ctrl_r()                            (0x001facc4U)
#define fb_hsmmu_pri_mmu_debug_ctrl_debug_v(r)             (((r) >> 16U) & 0x1U)
#define fb_hsmmu_pri_mmu_debug_ctrl_debug_m()                 (U32(0x1U) << 16U)
#define fb_hsmmu_pri_mmu_debug_ctrl_debug_enabled_f()                 (0x10000U)
#define fb_hsmmu_pri_mmu_debug_ctrl_debug_disabled_f()                    (0x0U)
#define fb_hshub_num_active_ltcs_r()                               (0x001fbc20U)
#define fb_hshub_num_active_ltcs_use_nvlink_f(v)       ((U32(v) & 0xffU) << 16U)
#define fb_hshub_num_active_ltcs_use_nvlink_m()              (U32(0xffU) << 16U)
#define fb_hshub_num_active_ltcs_use_nvlink_v(r)          (((r) >> 16U) & 0xffU)
#define fb_hshub_num_active_ltcs_use_nvlink_peer_f(v, i)\
		((U32(v) & 0x1U) << (16U + (i)*1U))
#define fb_hshub_num_active_ltcs_use_nvlink_peer_m(i)\
		(U32(0x1U) << (16U + (i)*1U))
#define fb_hshub_num_active_ltcs_use_nvlink_peer_v(r, i)\
		(((r) >> (16U + i*1U)) & 0x1U)
#define fb_hshub_num_active_ltcs_use_nvlink_peer___size_1_v()      (0x00000008U)
#define fb_hshub_num_active_ltcs_use_nvlink_peer___size_1_f(i)\
		((0x0U << (32U +((i)*1U))))
#define fb_hshub_num_active_ltcs_use_nvlink_peer_enabled_v()       (0x00000001U)
#define fb_hshub_num_active_ltcs_use_nvlink_peer_enabled_f(i)\
		((0x1U << (32U +((i)*1U))))
#define fb_hshub_num_active_ltcs_use_nvlink_peer_disabled_v()      (0x00000000U)
#define fb_hshub_num_active_ltcs_use_nvlink_peer_disabled_f(i)\
		((0x0U << (32U +((i)*1U))))
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_f(v)\
				((U32(v) & 0x1U) << 25U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_m()      (U32(0x1U) << 25U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_v(r)  (((r) >> 25U) & 0x1U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_use_read_v()  (0x00000000U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_use_read_f()         (0x0U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_use_rmw_v()   (0x00000001U)
#define fb_hshub_num_active_ltcs_hub_sys_atomic_mode_use_rmw_f()    (0x2000000U)
#define fb_priv_mmu_phy_secure_r()                                 (0x00100ce4U)
#define fb_mmu_invalidate_pdb_r()                                  (0x00100cb8U)
#define fb_mmu_invalidate_pdb_aperture_vid_mem_f()                        (0x0U)
#define fb_mmu_invalidate_pdb_aperture_sys_mem_f()                        (0x2U)
#define fb_mmu_invalidate_pdb_addr_f(v)            ((U32(v) & 0xfffffffU) << 4U)
#define fb_mmu_invalidate_r()                                      (0x00100cbcU)
#define fb_mmu_invalidate_all_va_true_f()                                 (0x1U)
#define fb_mmu_invalidate_all_pdb_true_f()                                (0x2U)
#define fb_mmu_invalidate_hubtlb_only_s()                                   (1U)
#define fb_mmu_invalidate_hubtlb_only_f(v)               ((U32(v) & 0x1U) << 2U)
#define fb_mmu_invalidate_hubtlb_only_m()                      (U32(0x1U) << 2U)
#define fb_mmu_invalidate_hubtlb_only_v(r)                  (((r) >> 2U) & 0x1U)
#define fb_mmu_invalidate_hubtlb_only_true_f()                            (0x4U)
#define fb_mmu_invalidate_replay_s()                                        (3U)
#define fb_mmu_invalidate_replay_f(v)                    ((U32(v) & 0x7U) << 3U)
#define fb_mmu_invalidate_replay_m()                           (U32(0x7U) << 3U)
#define fb_mmu_invalidate_replay_v(r)                       (((r) >> 3U) & 0x7U)
#define fb_mmu_invalidate_replay_none_f()                                 (0x0U)
#define fb_mmu_invalidate_replay_start_f()                                (0x8U)
#define fb_mmu_invalidate_replay_start_ack_all_f()                       (0x10U)
#define fb_mmu_invalidate_replay_cancel_global_f()                       (0x20U)
#define fb_mmu_invalidate_sys_membar_s()                                    (1U)
#define fb_mmu_invalidate_sys_membar_f(v)                ((U32(v) & 0x1U) << 6U)
#define fb_mmu_invalidate_sys_membar_m()                       (U32(0x1U) << 6U)
#define fb_mmu_invalidate_sys_membar_v(r)                   (((r) >> 6U) & 0x1U)
#define fb_mmu_invalidate_sys_membar_true_f()                            (0x40U)
#define fb_mmu_invalidate_ack_s()                                           (2U)
#define fb_mmu_invalidate_ack_f(v)                       ((U32(v) & 0x3U) << 7U)
#define fb_mmu_invalidate_ack_m()                              (U32(0x3U) << 7U)
#define fb_mmu_invalidate_ack_v(r)                          (((r) >> 7U) & 0x3U)
#define fb_mmu_invalidate_ack_ack_none_required_f()                       (0x0U)
#define fb_mmu_invalidate_ack_ack_intranode_f()                         (0x100U)
#define fb_mmu_invalidate_ack_ack_globally_f()                           (0x80U)
#define fb_mmu_invalidate_cancel_client_id_s()                              (6U)
#define fb_mmu_invalidate_cancel_client_id_f(v)         ((U32(v) & 0x3fU) << 9U)
#define fb_mmu_invalidate_cancel_client_id_m()                (U32(0x3fU) << 9U)
#define fb_mmu_invalidate_cancel_client_id_v(r)            (((r) >> 9U) & 0x3fU)
#define fb_mmu_invalidate_cancel_gpc_id_s()                                 (5U)
#define fb_mmu_invalidate_cancel_gpc_id_f(v)           ((U32(v) & 0x1fU) << 15U)
#define fb_mmu_invalidate_cancel_gpc_id_m()                  (U32(0x1fU) << 15U)
#define fb_mmu_invalidate_cancel_gpc_id_v(r)              (((r) >> 15U) & 0x1fU)
#define fb_mmu_invalidate_cancel_client_type_s()                            (1U)
#define fb_mmu_invalidate_cancel_client_type_f(v)       ((U32(v) & 0x1U) << 20U)
#define fb_mmu_invalidate_cancel_client_type_m()              (U32(0x1U) << 20U)
#define fb_mmu_invalidate_cancel_client_type_v(r)          (((r) >> 20U) & 0x1U)
#define fb_mmu_invalidate_cancel_client_type_gpc_f()                      (0x0U)
#define fb_mmu_invalidate_cancel_client_type_hub_f()                 (0x100000U)
#define fb_mmu_invalidate_cancel_cache_level_s()                            (3U)
#define fb_mmu_invalidate_cancel_cache_level_f(v)       ((U32(v) & 0x7U) << 24U)
#define fb_mmu_invalidate_cancel_cache_level_m()              (U32(0x7U) << 24U)
#define fb_mmu_invalidate_cancel_cache_level_v(r)          (((r) >> 24U) & 0x7U)
#define fb_mmu_invalidate_cancel_cache_level_all_f()                      (0x0U)
#define fb_mmu_invalidate_cancel_cache_level_pte_only_f()           (0x1000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde0_f()         (0x2000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde1_f()         (0x3000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde2_f()         (0x4000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde3_f()         (0x5000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde4_f()         (0x6000000U)
#define fb_mmu_invalidate_cancel_cache_level_up_to_pde5_f()         (0x7000000U)
#define fb_mmu_invalidate_trigger_s()                                       (1U)
#define fb_mmu_invalidate_trigger_f(v)                  ((U32(v) & 0x1U) << 31U)
#define fb_mmu_invalidate_trigger_m()                         (U32(0x1U) << 31U)
#define fb_mmu_invalidate_trigger_v(r)                     (((r) >> 31U) & 0x1U)
#define fb_mmu_invalidate_trigger_true_f()                         (0x80000000U)
#define fb_mmu_debug_wr_r()                                        (0x00100cc8U)
#define fb_mmu_debug_wr_aperture_s()                                        (2U)
#define fb_mmu_debug_wr_aperture_f(v)                    ((U32(v) & 0x3U) << 0U)
#define fb_mmu_debug_wr_aperture_m()                           (U32(0x3U) << 0U)
#define fb_mmu_debug_wr_aperture_v(r)                       (((r) >> 0U) & 0x3U)
#define fb_mmu_debug_wr_aperture_vid_mem_f()                              (0x0U)
#define fb_mmu_debug_wr_aperture_sys_mem_coh_f()                          (0x2U)
#define fb_mmu_debug_wr_aperture_sys_mem_ncoh_f()                         (0x3U)
#define fb_mmu_debug_wr_vol_false_f()                                     (0x0U)
#define fb_mmu_debug_wr_vol_true_v()                               (0x00000001U)
#define fb_mmu_debug_wr_vol_true_f()                                      (0x4U)
#define fb_mmu_debug_wr_addr_f(v)                  ((U32(v) & 0xfffffffU) << 4U)
#define fb_mmu_debug_wr_addr_alignment_v()                         (0x0000000cU)
#define fb_mmu_debug_rd_r()                                        (0x00100cccU)
#define fb_mmu_debug_rd_aperture_vid_mem_f()                              (0x0U)
#define fb_mmu_debug_rd_aperture_sys_mem_coh_f()                          (0x2U)
#define fb_mmu_debug_rd_aperture_sys_mem_ncoh_f()                         (0x3U)
#define fb_mmu_debug_rd_vol_false_f()                                     (0x0U)
#define fb_mmu_debug_rd_addr_f(v)                  ((U32(v) & 0xfffffffU) << 4U)
#define fb_mmu_debug_rd_addr_alignment_v()                         (0x0000000cU)
#define fb_mmu_debug_ctrl_r()                                      (0x00100cc4U)
#define fb_mmu_debug_ctrl_debug_v(r)                       (((r) >> 16U) & 0x1U)
#define fb_mmu_debug_ctrl_debug_m()                           (U32(0x1U) << 16U)
#define fb_mmu_debug_ctrl_debug_enabled_v()                        (0x00000001U)
#define fb_mmu_debug_ctrl_debug_enabled_f()                           (0x10000U)
#define fb_mmu_debug_ctrl_debug_disabled_v()                       (0x00000000U)
#define fb_mmu_debug_ctrl_debug_disabled_f()                              (0x0U)
#define fb_niso_cfg1_r()                                           (0x00100c14U)
#define fb_niso_cfg1_sysmem_nvlink_f(v)                 ((U32(v) & 0x1U) << 17U)
#define fb_niso_cfg1_sysmem_nvlink_m()                        (U32(0x1U) << 17U)
#define fb_niso_cfg1_sysmem_nvlink_v(r)                    (((r) >> 17U) & 0x1U)
#define fb_niso_cfg1_sysmem_nvlink_enabled_v()                     (0x00000001U)
#define fb_niso_cfg1_sysmem_nvlink_enabled_f()                        (0x20000U)
#define fb_niso_flush_sysmem_addr_r()                              (0x00100c10U)
#define fb_niso_intr_r()                                           (0x00100a20U)
#define fb_niso_intr_hub_access_counter_notify_m()             (U32(0x1U) << 0U)
#define fb_niso_intr_hub_access_counter_notify_pending_f()                (0x1U)
#define fb_niso_intr_hub_access_counter_error_m()              (U32(0x1U) << 1U)
#define fb_niso_intr_hub_access_counter_error_pending_f()                 (0x2U)
#define fb_niso_intr_mmu_replayable_fault_notify_m()          (U32(0x1U) << 27U)
#define fb_niso_intr_mmu_replayable_fault_notify_pending_f()        (0x8000000U)
#define fb_niso_intr_mmu_replayable_fault_overflow_m()        (U32(0x1U) << 28U)
#define fb_niso_intr_mmu_replayable_fault_overflow_pending_f()     (0x10000000U)
#define fb_niso_intr_mmu_nonreplayable_fault_notify_m()       (U32(0x1U) << 29U)
#define fb_niso_intr_mmu_nonreplayable_fault_notify_pending_f()    (0x20000000U)
#define fb_niso_intr_mmu_nonreplayable_fault_overflow_m()     (U32(0x1U) << 30U)
#define fb_niso_intr_mmu_nonreplayable_fault_overflow_pending_f()  (0x40000000U)
#define fb_niso_intr_mmu_other_fault_notify_m()               (U32(0x1U) << 31U)
#define fb_niso_intr_mmu_other_fault_notify_pending_f()            (0x80000000U)
#define fb_niso_intr_en_r(i)\
		(nvgpu_safe_add_u32(0x00100a24U, nvgpu_safe_mult_u32((i), 4U)))
#define fb_niso_intr_en__size_1_v()                                (0x00000002U)
#define fb_niso_intr_en_hub_access_counter_notify_f(v)   ((U32(v) & 0x1U) << 0U)
#define fb_niso_intr_en_hub_access_counter_notify_enabled_f()             (0x1U)
#define fb_niso_intr_en_hub_access_counter_error_f(v)    ((U32(v) & 0x1U) << 1U)
#define fb_niso_intr_en_hub_access_counter_error_enabled_f()              (0x2U)
#define fb_niso_intr_en_mmu_replayable_fault_notify_f(v)\
				((U32(v) & 0x1U) << 27U)
#define fb_niso_intr_en_mmu_replayable_fault_notify_enabled_f()     (0x8000000U)
#define fb_niso_intr_en_mmu_replayable_fault_overflow_f(v)\
				((U32(v) & 0x1U) << 28U)
#define fb_niso_intr_en_mmu_replayable_fault_overflow_enabled_f()  (0x10000000U)
#define fb_niso_intr_en_mmu_nonreplayable_fault_notify_f(v)\
				((U32(v) & 0x1U) << 29U)
#define fb_niso_intr_en_mmu_nonreplayable_fault_notify_enabled_f() (0x20000000U)
#define fb_niso_intr_en_mmu_nonreplayable_fault_overflow_f(v)\
				((U32(v) & 0x1U) << 30U)
#define fb_niso_intr_en_mmu_nonreplayable_fault_overflow_enabled_f()\
				(0x40000000U)
#define fb_niso_intr_en_mmu_other_fault_notify_f(v)     ((U32(v) & 0x1U) << 31U)
#define fb_niso_intr_en_mmu_other_fault_notify_enabled_f()         (0x80000000U)
#define fb_niso_intr_en_set_r(i)\
		(nvgpu_safe_add_u32(0x00100a2cU, nvgpu_safe_mult_u32((i), 4U)))
#define fb_niso_intr_en_set__size_1_v()                            (0x00000002U)
#define fb_niso_intr_en_set_hub_access_counter_notify_m()      (U32(0x1U) << 0U)
#define fb_niso_intr_en_set_hub_access_counter_notify_set_f()             (0x1U)
#define fb_niso_intr_en_set_hub_access_counter_error_m()       (U32(0x1U) << 1U)
#define fb_niso_intr_en_set_hub_access_counter_error_set_f()              (0x2U)
#define fb_niso_intr_en_set_mmu_replayable_fault_notify_m()   (U32(0x1U) << 27U)
#define fb_niso_intr_en_set_mmu_replayable_fault_notify_set_f()     (0x8000000U)
#define fb_niso_intr_en_set_mmu_replayable_fault_overflow_m() (U32(0x1U) << 28U)
#define fb_niso_intr_en_set_mmu_replayable_fault_overflow_set_f()  (0x10000000U)
#define fb_niso_intr_en_set_mmu_nonreplayable_fault_notify_m()\
				(U32(0x1U) << 29U)
#define fb_niso_intr_en_set_mmu_nonreplayable_fault_notify_set_f() (0x20000000U)
#define fb_niso_intr_en_set_mmu_nonreplayable_fault_overflow_m()\
				(U32(0x1U) << 30U)
#define fb_niso_intr_en_set_mmu_nonreplayable_fault_overflow_set_f()\
				(0x40000000U)
#define fb_niso_intr_en_set_mmu_other_fault_notify_m()        (U32(0x1U) << 31U)
#define fb_niso_intr_en_set_mmu_other_fault_notify_set_f()         (0x80000000U)
#define fb_niso_intr_en_clr_r(i)\
		(nvgpu_safe_add_u32(0x00100a34U, nvgpu_safe_mult_u32((i), 4U)))
#define fb_niso_intr_en_clr__size_1_v()                            (0x00000002U)
#define fb_niso_intr_en_clr_hub_access_counter_notify_m()      (U32(0x1U) << 0U)
#define fb_niso_intr_en_clr_hub_access_counter_notify_set_f()             (0x1U)
#define fb_niso_intr_en_clr_hub_access_counter_error_m()       (U32(0x1U) << 1U)
#define fb_niso_intr_en_clr_hub_access_counter_error_set_f()              (0x2U)
#define fb_niso_intr_en_clr_mmu_replayable_fault_notify_m()   (U32(0x1U) << 27U)
#define fb_niso_intr_en_clr_mmu_replayable_fault_notify_set_f()     (0x8000000U)
#define fb_niso_intr_en_clr_mmu_replayable_fault_overflow_m() (U32(0x1U) << 28U)
#define fb_niso_intr_en_clr_mmu_replayable_fault_overflow_set_f()  (0x10000000U)
#define fb_niso_intr_en_clr_mmu_nonreplayable_fault_notify_m()\
				(U32(0x1U) << 29U)
#define fb_niso_intr_en_clr_mmu_nonreplayable_fault_notify_set_f() (0x20000000U)
#define fb_niso_intr_en_clr_mmu_nonreplayable_fault_overflow_m()\
				(U32(0x1U) << 30U)
#define fb_niso_intr_en_clr_mmu_nonreplayable_fault_overflow_set_f()\
				(0x40000000U)
#define fb_niso_intr_en_clr_mmu_other_fault_notify_m()        (U32(0x1U) << 31U)
#define fb_niso_intr_en_clr_mmu_other_fault_notify_set_f()         (0x80000000U)
#define fb_niso_intr_en_clr_mmu_non_replay_fault_buffer_v()        (0x00000000U)
#define fb_niso_intr_en_clr_mmu_replay_fault_buffer_v()            (0x00000001U)
#define fb_mmu_fault_buffer_lo_r(i)\
		(nvgpu_safe_add_u32(0x00100e24U, nvgpu_safe_mult_u32((i), 20U)))
#define fb_mmu_fault_buffer_lo__size_1_v()                         (0x00000002U)
#define fb_mmu_fault_buffer_lo_addr_mode_f(v)            ((U32(v) & 0x1U) << 0U)
#define fb_mmu_fault_buffer_lo_addr_mode_v(r)               (((r) >> 0U) & 0x1U)
#define fb_mmu_fault_buffer_lo_addr_mode_virtual_v()               (0x00000000U)
#define fb_mmu_fault_buffer_lo_addr_mode_virtual_f()                      (0x0U)
#define fb_mmu_fault_buffer_lo_addr_mode_physical_v()              (0x00000001U)
#define fb_mmu_fault_buffer_lo_addr_mode_physical_f()                     (0x1U)
#define fb_mmu_fault_buffer_lo_phys_aperture_f(v)        ((U32(v) & 0x3U) << 1U)
#define fb_mmu_fault_buffer_lo_phys_aperture_v(r)           (((r) >> 1U) & 0x3U)
#define fb_mmu_fault_buffer_lo_phys_aperture_sys_coh_v()           (0x00000002U)
#define fb_mmu_fault_buffer_lo_phys_aperture_sys_coh_f()                  (0x4U)
#define fb_mmu_fault_buffer_lo_phys_aperture_sys_nocoh_v()         (0x00000003U)
#define fb_mmu_fault_buffer_lo_phys_aperture_sys_nocoh_f()                (0x6U)
#define fb_mmu_fault_buffer_lo_phys_vol_f(v)             ((U32(v) & 0x1U) << 3U)
#define fb_mmu_fault_buffer_lo_phys_vol_v(r)                (((r) >> 3U) & 0x1U)
#define fb_mmu_fault_buffer_lo_addr_f(v)            ((U32(v) & 0xfffffU) << 12U)
#define fb_mmu_fault_buffer_lo_addr_v(r)               (((r) >> 12U) & 0xfffffU)
#define fb_mmu_fault_buffer_hi_r(i)\
		(nvgpu_safe_add_u32(0x00100e28U, nvgpu_safe_mult_u32((i), 20U)))
#define fb_mmu_fault_buffer_hi__size_1_v()                         (0x00000002U)
#define fb_mmu_fault_buffer_hi_addr_f(v)          ((U32(v) & 0xffffffffU) << 0U)
#define fb_mmu_fault_buffer_hi_addr_v(r)             (((r) >> 0U) & 0xffffffffU)
#define fb_mmu_fault_buffer_get_r(i)\
		(nvgpu_safe_add_u32(0x00100e2cU, nvgpu_safe_mult_u32((i), 20U)))
#define fb_mmu_fault_buffer_get__size_1_v()                        (0x00000002U)
#define fb_mmu_fault_buffer_get_ptr_f(v)             ((U32(v) & 0xfffffU) << 0U)
#define fb_mmu_fault_buffer_get_ptr_m()                    (U32(0xfffffU) << 0U)
#define fb_mmu_fault_buffer_get_ptr_v(r)                (((r) >> 0U) & 0xfffffU)
#define fb_mmu_fault_buffer_get_getptr_corrupted_f(v)   ((U32(v) & 0x1U) << 30U)
#define fb_mmu_fault_buffer_get_getptr_corrupted_m()          (U32(0x1U) << 30U)
#define fb_mmu_fault_buffer_get_getptr_corrupted_clear_v()         (0x00000001U)
#define fb_mmu_fault_buffer_get_getptr_corrupted_clear_f()         (0x40000000U)
#define fb_mmu_fault_buffer_get_overflow_f(v)           ((U32(v) & 0x1U) << 31U)
#define fb_mmu_fault_buffer_get_overflow_m()                  (U32(0x1U) << 31U)
#define fb_mmu_fault_buffer_get_overflow_clear_v()                 (0x00000001U)
#define fb_mmu_fault_buffer_get_overflow_clear_f()                 (0x80000000U)
#define fb_mmu_fault_buffer_put_r(i)\
		(nvgpu_safe_add_u32(0x00100e30U, nvgpu_safe_mult_u32((i), 20U)))
#define fb_mmu_fault_buffer_put__size_1_v()                        (0x00000002U)
#define fb_mmu_fault_buffer_put_ptr_f(v)             ((U32(v) & 0xfffffU) << 0U)
#define fb_mmu_fault_buffer_put_ptr_v(r)                (((r) >> 0U) & 0xfffffU)
#define fb_mmu_fault_buffer_put_getptr_corrupted_f(v)   ((U32(v) & 0x1U) << 30U)
#define fb_mmu_fault_buffer_put_getptr_corrupted_v(r)      (((r) >> 30U) & 0x1U)
#define fb_mmu_fault_buffer_put_getptr_corrupted_yes_v()           (0x00000001U)
#define fb_mmu_fault_buffer_put_getptr_corrupted_yes_f()           (0x40000000U)
#define fb_mmu_fault_buffer_put_getptr_corrupted_no_v()            (0x00000000U)
#define fb_mmu_fault_buffer_put_getptr_corrupted_no_f()                   (0x0U)
#define fb_mmu_fault_buffer_put_overflow_f(v)           ((U32(v) & 0x1U) << 31U)
#define fb_mmu_fault_buffer_put_overflow_v(r)              (((r) >> 31U) & 0x1U)
#define fb_mmu_fault_buffer_put_overflow_yes_v()                   (0x00000001U)
#define fb_mmu_fault_buffer_put_overflow_yes_f()                   (0x80000000U)
#define fb_mmu_fault_buffer_size_r(i)\
		(nvgpu_safe_add_u32(0x00100e34U, nvgpu_safe_mult_u32((i), 20U)))
#define fb_mmu_fault_buffer_size__size_1_v()                       (0x00000002U)
#define fb_mmu_fault_buffer_size_val_f(v)            ((U32(v) & 0xfffffU) << 0U)
#define fb_mmu_fault_buffer_size_val_v(r)               (((r) >> 0U) & 0xfffffU)
#define fb_mmu_fault_buffer_size_overflow_intr_f(v)     ((U32(v) & 0x1U) << 29U)
#define fb_mmu_fault_buffer_size_overflow_intr_v(r)        (((r) >> 29U) & 0x1U)
#define fb_mmu_fault_buffer_size_overflow_intr_enable_v()          (0x00000001U)
#define fb_mmu_fault_buffer_size_overflow_intr_enable_f()          (0x20000000U)
#define fb_mmu_fault_buffer_size_set_default_f(v)       ((U32(v) & 0x1U) << 30U)
#define fb_mmu_fault_buffer_size_set_default_v(r)          (((r) >> 30U) & 0x1U)
#define fb_mmu_fault_buffer_size_set_default_yes_v()               (0x00000001U)
#define fb_mmu_fault_buffer_size_set_default_yes_f()               (0x40000000U)
#define fb_mmu_fault_buffer_size_enable_f(v)            ((U32(v) & 0x1U) << 31U)
#define fb_mmu_fault_buffer_size_enable_m()                   (U32(0x1U) << 31U)
#define fb_mmu_fault_buffer_size_enable_v(r)               (((r) >> 31U) & 0x1U)
#define fb_mmu_fault_buffer_size_enable_true_v()                   (0x00000001U)
#define fb_mmu_fault_buffer_size_enable_true_f()                   (0x80000000U)
#define fb_mmu_fault_addr_lo_r()                                   (0x00100e4cU)
#define fb_mmu_fault_addr_lo_phys_aperture_f(v)          ((U32(v) & 0x3U) << 0U)
#define fb_mmu_fault_addr_lo_phys_aperture_v(r)             (((r) >> 0U) & 0x3U)
#define fb_mmu_fault_addr_lo_phys_aperture_sys_coh_v()             (0x00000002U)
#define fb_mmu_fault_addr_lo_phys_aperture_sys_coh_f()                    (0x2U)
#define fb_mmu_fault_addr_lo_phys_aperture_sys_nocoh_v()           (0x00000003U)
#define fb_mmu_fault_addr_lo_phys_aperture_sys_nocoh_f()                  (0x3U)
#define fb_mmu_fault_addr_lo_addr_f(v)              ((U32(v) & 0xfffffU) << 12U)
#define fb_mmu_fault_addr_lo_addr_v(r)                 (((r) >> 12U) & 0xfffffU)
#define fb_mmu_fault_addr_hi_r()                                   (0x00100e50U)
#define fb_mmu_fault_addr_hi_addr_f(v)            ((U32(v) & 0xffffffffU) << 0U)
#define fb_mmu_fault_addr_hi_addr_v(r)               (((r) >> 0U) & 0xffffffffU)
#define fb_mmu_fault_inst_lo_r()                                   (0x00100e54U)
#define fb_mmu_fault_inst_lo_engine_id_v(r)               (((r) >> 0U) & 0x1ffU)
#define fb_mmu_fault_inst_lo_aperture_v(r)                 (((r) >> 10U) & 0x3U)
#define fb_mmu_fault_inst_lo_aperture_sys_coh_v()                  (0x00000002U)
#define fb_mmu_fault_inst_lo_aperture_sys_nocoh_v()                (0x00000003U)
#define fb_mmu_fault_inst_lo_addr_f(v)              ((U32(v) & 0xfffffU) << 12U)
#define fb_mmu_fault_inst_lo_addr_v(r)                 (((r) >> 12U) & 0xfffffU)
#define fb_mmu_fault_inst_hi_r()                                   (0x00100e58U)
#define fb_mmu_fault_inst_hi_addr_v(r)               (((r) >> 0U) & 0xffffffffU)
#define fb_mmu_fault_info_r()                                      (0x00100e5cU)
#define fb_mmu_fault_info_fault_type_v(r)                  (((r) >> 0U) & 0x1fU)
#define fb_mmu_fault_info_replayable_fault_v(r)             (((r) >> 7U) & 0x1U)
#define fb_mmu_fault_info_client_v(r)                      (((r) >> 8U) & 0x7fU)
#define fb_mmu_fault_info_access_type_v(r)                 (((r) >> 16U) & 0xfU)
#define fb_mmu_fault_info_client_type_v(r)                 (((r) >> 20U) & 0x1U)
#define fb_mmu_fault_info_gpc_id_v(r)                     (((r) >> 24U) & 0x1fU)
#define fb_mmu_fault_info_protected_mode_v(r)              (((r) >> 29U) & 0x1U)
#define fb_mmu_fault_info_replayable_fault_en_v(r)         (((r) >> 30U) & 0x1U)
#define fb_mmu_fault_info_valid_v(r)                       (((r) >> 31U) & 0x1U)
#define fb_mmu_fault_status_r()                                    (0x00100e60U)
#define fb_mmu_fault_status_dropped_bar1_phys_m()              (U32(0x1U) << 0U)
#define fb_mmu_fault_status_dropped_bar1_phys_set_v()              (0x00000001U)
#define fb_mmu_fault_status_dropped_bar1_phys_set_f()                     (0x1U)
#define fb_mmu_fault_status_dropped_bar1_phys_clear_v()            (0x00000001U)
#define fb_mmu_fault_status_dropped_bar1_phys_clear_f()                   (0x1U)
#define fb_mmu_fault_status_dropped_bar1_virt_m()              (U32(0x1U) << 1U)
#define fb_mmu_fault_status_dropped_bar1_virt_set_v()              (0x00000001U)
#define fb_mmu_fault_status_dropped_bar1_virt_set_f()                     (0x2U)
#define fb_mmu_fault_status_dropped_bar1_virt_clear_v()            (0x00000001U)
#define fb_mmu_fault_status_dropped_bar1_virt_clear_f()                   (0x2U)
#define fb_mmu_fault_status_dropped_bar2_phys_m()              (U32(0x1U) << 2U)
#define fb_mmu_fault_status_dropped_bar2_phys_set_v()              (0x00000001U)
#define fb_mmu_fault_status_dropped_bar2_phys_set_f()                     (0x4U)
#define fb_mmu_fault_status_dropped_bar2_phys_clear_v()            (0x00000001U)
#define fb_mmu_fault_status_dropped_bar2_phys_clear_f()                   (0x4U)
#define fb_mmu_fault_status_dropped_bar2_virt_m()              (U32(0x1U) << 3U)
#define fb_mmu_fault_status_dropped_bar2_virt_set_v()              (0x00000001U)
#define fb_mmu_fault_status_dropped_bar2_virt_set_f()                     (0x8U)
#define fb_mmu_fault_status_dropped_bar2_virt_clear_v()            (0x00000001U)
#define fb_mmu_fault_status_dropped_bar2_virt_clear_f()                   (0x8U)
#define fb_mmu_fault_status_dropped_ifb_phys_m()               (U32(0x1U) << 4U)
#define fb_mmu_fault_status_dropped_ifb_phys_set_v()               (0x00000001U)
#define fb_mmu_fault_status_dropped_ifb_phys_set_f()                     (0x10U)
#define fb_mmu_fault_status_dropped_ifb_phys_clear_v()             (0x00000001U)
#define fb_mmu_fault_status_dropped_ifb_phys_clear_f()                   (0x10U)
#define fb_mmu_fault_status_dropped_ifb_virt_m()               (U32(0x1U) << 5U)
#define fb_mmu_fault_status_dropped_ifb_virt_set_v()               (0x00000001U)
#define fb_mmu_fault_status_dropped_ifb_virt_set_f()                     (0x20U)
#define fb_mmu_fault_status_dropped_ifb_virt_clear_v()             (0x00000001U)
#define fb_mmu_fault_status_dropped_ifb_virt_clear_f()                   (0x20U)
#define fb_mmu_fault_status_dropped_other_phys_m()             (U32(0x1U) << 6U)
#define fb_mmu_fault_status_dropped_other_phys_set_v()             (0x00000001U)
#define fb_mmu_fault_status_dropped_other_phys_set_f()                   (0x40U)
#define fb_mmu_fault_status_dropped_other_phys_clear_v()           (0x00000001U)
#define fb_mmu_fault_status_dropped_other_phys_clear_f()                 (0x40U)
#define fb_mmu_fault_status_dropped_other_virt_m()             (U32(0x1U) << 7U)
#define fb_mmu_fault_status_dropped_other_virt_set_v()             (0x00000001U)
#define fb_mmu_fault_status_dropped_other_virt_set_f()                   (0x80U)
#define fb_mmu_fault_status_dropped_other_virt_clear_v()           (0x00000001U)
#define fb_mmu_fault_status_dropped_other_virt_clear_f()                 (0x80U)
#define fb_mmu_fault_status_replayable_m()                     (U32(0x1U) << 8U)
#define fb_mmu_fault_status_replayable_set_v()                     (0x00000001U)
#define fb_mmu_fault_status_replayable_set_f()                          (0x100U)
#define fb_mmu_fault_status_replayable_reset_f()                          (0x0U)
#define fb_mmu_fault_status_non_replayable_m()                 (U32(0x1U) << 9U)
#define fb_mmu_fault_status_non_replayable_set_v()                 (0x00000001U)
#define fb_mmu_fault_status_non_replayable_set_f()                      (0x200U)
#define fb_mmu_fault_status_non_replayable_reset_f()                      (0x0U)
#define fb_mmu_fault_status_replayable_error_m()              (U32(0x1U) << 10U)
#define fb_mmu_fault_status_replayable_error_set_v()               (0x00000001U)
#define fb_mmu_fault_status_replayable_error_set_f()                    (0x400U)
#define fb_mmu_fault_status_replayable_error_reset_f()                    (0x0U)
#define fb_mmu_fault_status_non_replayable_error_m()          (U32(0x1U) << 11U)
#define fb_mmu_fault_status_non_replayable_error_set_v()           (0x00000001U)
#define fb_mmu_fault_status_non_replayable_error_set_f()                (0x800U)
#define fb_mmu_fault_status_non_replayable_error_reset_f()                (0x0U)
#define fb_mmu_fault_status_replayable_overflow_m()           (U32(0x1U) << 12U)
#define fb_mmu_fault_status_replayable_overflow_set_v()            (0x00000001U)
#define fb_mmu_fault_status_replayable_overflow_set_f()                (0x1000U)
#define fb_mmu_fault_status_replayable_overflow_reset_f()                 (0x0U)
#define fb_mmu_fault_status_non_replayable_overflow_m()       (U32(0x1U) << 13U)
#define fb_mmu_fault_status_non_replayable_overflow_set_v()        (0x00000001U)
#define fb_mmu_fault_status_non_replayable_overflow_set_f()            (0x2000U)
#define fb_mmu_fault_status_non_replayable_overflow_reset_f()             (0x0U)
#define fb_mmu_fault_status_replayable_getptr_corrupted_m()   (U32(0x1U) << 14U)
#define fb_mmu_fault_status_replayable_getptr_corrupted_set_v()    (0x00000001U)
#define fb_mmu_fault_status_replayable_getptr_corrupted_set_f()        (0x4000U)
#define fb_mmu_fault_status_non_replayable_getptr_corrupted_m()\
				(U32(0x1U) << 15U)
#define fb_mmu_fault_status_non_replayable_getptr_corrupted_set_v()\
				(0x00000001U)
#define fb_mmu_fault_status_non_replayable_getptr_corrupted_set_f()    (0x8000U)
#define fb_mmu_fault_status_busy_m()                          (U32(0x1U) << 30U)
#define fb_mmu_fault_status_busy_true_v()                          (0x00000001U)
#define fb_mmu_fault_status_busy_true_f()                          (0x40000000U)
#define fb_mmu_fault_status_valid_m()                         (U32(0x1U) << 31U)
#define fb_mmu_fault_status_valid_set_v()                          (0x00000001U)
#define fb_mmu_fault_status_valid_set_f()                          (0x80000000U)
#define fb_mmu_fault_status_valid_clear_v()                        (0x00000001U)
#define fb_mmu_fault_status_valid_clear_f()                        (0x80000000U)
#define fb_mmu_local_memory_range_r()                              (0x00100ce0U)
#define fb_mmu_local_memory_range_lower_scale_v(r)          (((r) >> 0U) & 0xfU)
#define fb_mmu_local_memory_range_lower_mag_v(r)           (((r) >> 4U) & 0x3fU)
#define fb_mmu_local_memory_range_ecc_mode_v(r)            (((r) >> 30U) & 0x1U)
#define fb_niso_scrub_status_r()                                   (0x00100b20U)
#define fb_niso_scrub_status_flag_v(r)                      (((r) >> 0U) & 0x1U)
#define fb_mmu_priv_level_mask_r()                                 (0x00100cdcU)
#define fb_mmu_priv_level_mask_write_violation_f(v)      ((U32(v) & 0x1U) << 7U)
#define fb_mmu_priv_level_mask_write_violation_m()             (U32(0x1U) << 7U)
#define fb_mmu_priv_level_mask_write_violation_v(r)         (((r) >> 7U) & 0x1U)
#define fb_hshub_config0_r()                                       (0x001fbc00U)
#define fb_hshub_config0_sysmem_nvlink_mask_f(v)      ((U32(v) & 0xffffU) << 0U)
#define fb_hshub_config0_sysmem_nvlink_mask_m()             (U32(0xffffU) << 0U)
#define fb_hshub_config0_sysmem_nvlink_mask_v(r)         (((r) >> 0U) & 0xffffU)
#define fb_hshub_config0_peer_pcie_mask_f(v)         ((U32(v) & 0xffffU) << 16U)
#define fb_hshub_config0_peer_pcie_mask_v(r)            (((r) >> 16U) & 0xffffU)
#define fb_hshub_config1_r()                                       (0x001fbc04U)
#define fb_hshub_config1_peer_0_nvlink_mask_f(v)        ((U32(v) & 0xffU) << 0U)
#define fb_hshub_config1_peer_0_nvlink_mask_v(r)           (((r) >> 0U) & 0xffU)
#define fb_hshub_config1_peer_1_nvlink_mask_f(v)        ((U32(v) & 0xffU) << 8U)
#define fb_hshub_config1_peer_1_nvlink_mask_v(r)           (((r) >> 8U) & 0xffU)
#define fb_hshub_config1_peer_2_nvlink_mask_f(v)       ((U32(v) & 0xffU) << 16U)
#define fb_hshub_config1_peer_2_nvlink_mask_v(r)          (((r) >> 16U) & 0xffU)
#define fb_hshub_config1_peer_3_nvlink_mask_f(v)       ((U32(v) & 0xffU) << 24U)
#define fb_hshub_config1_peer_3_nvlink_mask_v(r)          (((r) >> 24U) & 0xffU)
#define fb_hshub_config2_r()                                       (0x001fbc08U)
#define fb_hshub_config2_peer_4_nvlink_mask_f(v)        ((U32(v) & 0xffU) << 0U)
#define fb_hshub_config2_peer_4_nvlink_mask_v(r)           (((r) >> 0U) & 0xffU)
#define fb_hshub_config2_peer_5_nvlink_mask_f(v)        ((U32(v) & 0xffU) << 8U)
#define fb_hshub_config2_peer_5_nvlink_mask_v(r)           (((r) >> 8U) & 0xffU)
#define fb_hshub_config2_peer_6_nvlink_mask_f(v)       ((U32(v) & 0xffU) << 16U)
#define fb_hshub_config2_peer_6_nvlink_mask_v(r)          (((r) >> 16U) & 0xffU)
#define fb_hshub_config2_peer_7_nvlink_mask_f(v)       ((U32(v) & 0xffU) << 24U)
#define fb_hshub_config2_peer_7_nvlink_mask_v(r)          (((r) >> 24U) & 0xffU)
#define fb_hshub_config6_r()                                       (0x001fbc18U)
#define fb_hshub_config7_r()                                       (0x001fbc1cU)
#define fb_hshub_config7_nvlink_logical_0_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 0U)
#define fb_hshub_config7_nvlink_logical_0_physical_portmap_v(r)\
				(((r) >> 0U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_1_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 4U)
#define fb_hshub_config7_nvlink_logical_1_physical_portmap_v(r)\
				(((r) >> 4U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_2_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 8U)
#define fb_hshub_config7_nvlink_logical_2_physical_portmap_v(r)\
				(((r) >> 8U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_3_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 12U)
#define fb_hshub_config7_nvlink_logical_3_physical_portmap_v(r)\
				(((r) >> 12U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_4_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 16U)
#define fb_hshub_config7_nvlink_logical_4_physical_portmap_v(r)\
				(((r) >> 16U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_5_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 20U)
#define fb_hshub_config7_nvlink_logical_5_physical_portmap_v(r)\
				(((r) >> 20U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_6_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 24U)
#define fb_hshub_config7_nvlink_logical_6_physical_portmap_v(r)\
				(((r) >> 24U) & 0xfU)
#define fb_hshub_config7_nvlink_logical_7_physical_portmap_f(v)\
				((U32(v) & 0xfU) << 28U)
#define fb_hshub_config7_nvlink_logical_7_physical_portmap_v(r)\
				(((r) >> 28U) & 0xfU)
#define fb_hshub_nvl_cfg_priv_level_mask_r()                       (0x001fbc50U)
#define fb_hshub_nvl_cfg_priv_level_mask_write_protection_f(v)\
				((U32(v) & 0x7U) << 4U)
#define fb_hshub_nvl_cfg_priv_level_mask_write_protection_v(r)\
				(((r) >> 4U) & 0x7U)
#endif
