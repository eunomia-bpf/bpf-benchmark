/* SPDX-License-Identifier: GPL-2.0 */
/*
 * kinsn_common.h - shared helpers for first-class v2 kinsn modules
 */

#ifndef _KINSN_COMMON_H
#define _KINSN_COMMON_H

#include <linux/bpf.h>
#include <linux/filter.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>

static __always_inline u8 kinsn_payload_reg(u64 payload, u8 shift)
{
	return (payload >> shift) & 0xf;
}

static __always_inline u8 kinsn_payload_u8(u64 payload, u8 shift)
{
	return (payload >> shift) & 0xff;
}

static __always_inline s16 kinsn_payload_s16(u64 payload, u8 shift)
{
	return (s16)((payload >> shift) & 0xffff);
}

static __always_inline u8 kinsn_bpf_size_bits(u8 size)
{
	switch (size) {
	case BPF_H:
		return 16;
	case BPF_W:
		return 32;
	case BPF_DW:
		return 64;
	default:
		return 0;
	}
}

#ifdef CONFIG_X86_64
static __always_inline u8 kinsn_x86_reg_code(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_0:
	case BPF_REG_5:
		return 0;
	case BPF_REG_4:
		return 1;
	case BPF_REG_3:
		return 2;
	case BPF_REG_6:
		return 3;
	case BPF_REG_7:
	case BPF_REG_10:
		return 5;
	case BPF_REG_2:
	case BPF_REG_8:
		return 6;
	case BPF_REG_1:
	case BPF_REG_9:
		return 7;
	default:
		return 0xff;
	}
}

static __always_inline bool kinsn_x86_reg_ext(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_5:
	case BPF_REG_7:
	case BPF_REG_8:
	case BPF_REG_9:
		return true;
	default:
		return false;
	}
}

static __always_inline bool kinsn_x86_reg_valid(u8 bpf_reg)
{
	return kinsn_x86_reg_code(bpf_reg) != 0xff;
}
#endif

#ifdef CONFIG_ARM64
static __always_inline u8 kinsn_arm64_reg(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_0:
		return 7;
	case BPF_REG_1:
		return 0;
	case BPF_REG_2:
		return 1;
	case BPF_REG_3:
		return 2;
	case BPF_REG_4:
		return 3;
	case BPF_REG_5:
		return 4;
	case BPF_REG_6:
		return 19;
	case BPF_REG_7:
		return 20;
	case BPF_REG_8:
		return 21;
	case BPF_REG_9:
		return 22;
	case BPF_REG_10:
		return 25;
	default:
		return 0xff;
	}
}
#endif

#define BPF_KINSN_DESC_ENTRY(sym)					\
	{ .name = #sym, .desc = &(sym) }

#define DEFINE_KINSN_V2_MODULE(prefix, desc, ...)			\
static const struct bpf_kinsn_id prefix##_kinsns[] = {			\
	__VA_ARGS__							\
};									\
									\
static const struct bpf_kinsn_set prefix##_set = {			\
	.owner = THIS_MODULE,						\
	.cnt = ARRAY_SIZE(prefix##_kinsns),				\
	.ids = prefix##_kinsns,						\
};									\
									\
static int __init prefix##_init(void)					\
{									\
	return register_bpf_kinsn_set(&prefix##_set);			\
}									\
									\
static void __exit prefix##_exit(void)					\
{									\
	unregister_bpf_kinsn_set(&prefix##_set);			\
}									\
									\
module_init(prefix##_init);						\
module_exit(prefix##_exit);						\
									\
MODULE_DESCRIPTION(desc);						\
MODULE_LICENSE("GPL");							\
MODULE_AUTHOR("BpfReJIT")

#endif /* _KINSN_COMMON_H */
