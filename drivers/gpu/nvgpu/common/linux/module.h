/*
 * Copyright (c) 2011-2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */
#ifndef __NVGPU_COMMON_LINUX_MODULE_H__
#define __NVGPU_COMMON_LINUX_MODULE_H__

struct gk20a;
struct device;

int gk20a_pm_finalize_poweron(struct device *dev);
void gk20a_remove_support(struct gk20a *g);

extern struct class nvgpu_class;

#endif
