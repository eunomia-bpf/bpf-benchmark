/* SPDX-License-Identifier: GPL-2.0 */
/*
 * kinsn_common.h — shared macros for BpfReJIT kinsn kernel modules
 *
 * Eliminates boilerplate: includes, BTF kfunc set declaration,
 * inline-ops registration, module init/exit, and MODULE_* metadata.
 *
 * Usage for a single-kfunc module:
 *
 *   // Define the kfunc, emit callback, and ops struct as usual, then:
 *   KINSN_KFUNC_SET(bpf_rotate, bpf_rotate64);
 *   DEFINE_KINSN_MODULE(bpf_rotate, "bpf_rotate64", &rotate_ops,
 *                       "BpfReJIT kinsn: ROTATE (ROL) inline kfunc");
 *
 * Usage for a multi-kfunc module:
 *
 *   KINSN_KFUNC_SET_START(bpf_endian)
 *   KINSN_KFUNC_ID(bpf_endian_load16)
 *   KINSN_KFUNC_ID(bpf_endian_load32)
 *   KINSN_KFUNC_ID(bpf_endian_load64)
 *   KINSN_KFUNC_SET_END(bpf_endian)
 *
 *   static const struct kinsn_ops_entry endian_entries[] = {
 *       { "bpf_endian_load16", &endian_load16_ops },
 *       { "bpf_endian_load32", &endian_load32_ops },
 *       { "bpf_endian_load64", &endian_load64_ops },
 *   };
 *   DEFINE_KINSN_MODULE_MULTI(bpf_endian, endian_entries,
 *       "BpfReJIT kinsn: ENDIAN_LOAD inline kfunc");
 */

#ifndef _KINSN_COMMON_H
#define _KINSN_COMMON_H

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---------- BTF kfunc set helpers ---------- */

/*
 * Declare a BTF kfunc set with a single kfunc.
 * Expands BTF_KFUNCS_START/BTF_ID_FLAGS/BTF_KFUNCS_END + id_set struct.
 */
#define KINSN_KFUNC_SET(prefix, kfunc_name)				\
	BTF_KFUNCS_START(prefix##_kfunc_ids)				\
	BTF_ID_FLAGS(func, kfunc_name, KF_INLINE_EMIT);		\
	BTF_KFUNCS_END(prefix##_kfunc_ids)				\
									\
	static const struct btf_kfunc_id_set prefix##_kfunc_set = {	\
		.owner = THIS_MODULE,					\
		.set   = &prefix##_kfunc_ids,				\
	}

/*
 * For multi-kfunc modules, use START/ID/END triplet manually.
 */
#define KINSN_KFUNC_SET_START(prefix)					\
	BTF_KFUNCS_START(prefix##_kfunc_ids)

#define KINSN_KFUNC_ID(kfunc_name)					\
	BTF_ID_FLAGS(func, kfunc_name, KF_INLINE_EMIT);

#define KINSN_KFUNC_SET_END(prefix)					\
	BTF_KFUNCS_END(prefix##_kfunc_ids)				\
									\
	static const struct btf_kfunc_id_set prefix##_kfunc_set = {	\
		.owner = THIS_MODULE,					\
		.set   = &prefix##_kfunc_ids,				\
	};

/* ---------- Single-kfunc module macro ---------- */

/*
 * DEFINE_KINSN_MODULE — complete module definition for a single kfunc.
 *
 * @prefix:     module prefix (e.g. bpf_rotate)
 * @kfunc_str:  kfunc name as a string literal (e.g. "bpf_rotate64")
 * @ops_ptr:    pointer to bpf_kfunc_inline_ops (e.g. &rotate_ops)
 * @desc:       MODULE_DESCRIPTION string
 */
#define DEFINE_KINSN_MODULE(prefix, kfunc_str, ops_ptr, desc)		\
									\
static int __init prefix##_init(void)					\
{									\
	int ret;							\
									\
	ret = bpf_register_kfunc_inline_ops(kfunc_str, ops_ptr);	\
	if (ret)							\
		return ret;						\
									\
	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,		\
					&prefix##_kfunc_set);		\
	if (ret)							\
		bpf_unregister_kfunc_inline_ops(kfunc_str);		\
									\
	return ret;							\
}									\
									\
static void __exit prefix##_exit(void)					\
{									\
	bpf_unregister_kfunc_inline_ops(kfunc_str);			\
}									\
									\
module_init(prefix##_init);						\
module_exit(prefix##_exit);						\
									\
MODULE_DESCRIPTION(desc);						\
MODULE_LICENSE("GPL");							\
MODULE_AUTHOR("BpfReJIT")

/* ---------- Multi-kfunc module macro ---------- */

/*
 * Describes one (name, ops) pair for multi-kfunc modules.
 */
struct kinsn_ops_entry {
	const char *kfunc_name;
	struct bpf_kfunc_inline_ops *ops;
};

/*
 * DEFINE_KINSN_MODULE_MULTI — complete module definition for N kfuncs.
 *
 * @prefix:     module prefix (e.g. bpf_endian)
 * @entries:    array name of struct kinsn_ops_entry[]
 * @desc:       MODULE_DESCRIPTION string
 *
 * Init registers ops in order; on failure, unwinds what was registered.
 * Exit unregisters all in reverse order.
 */
#define DEFINE_KINSN_MODULE_MULTI(prefix, entries, desc)		\
									\
static int __init prefix##_init(void)					\
{									\
	int ret, i;							\
	const int n = ARRAY_SIZE(entries);				\
									\
	for (i = 0; i < n; i++) {					\
		ret = bpf_register_kfunc_inline_ops(			\
			entries[i].kfunc_name, entries[i].ops);		\
		if (ret)						\
			goto err_unwind;				\
	}								\
									\
	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,		\
					&prefix##_kfunc_set);		\
	if (ret)							\
		goto err_unwind;					\
									\
	return 0;							\
									\
err_unwind:								\
	while (--i >= 0)						\
		bpf_unregister_kfunc_inline_ops(			\
			entries[i].kfunc_name);				\
	return ret;							\
}									\
									\
static void __exit prefix##_exit(void)					\
{									\
	int i;								\
	const int n = ARRAY_SIZE(entries);				\
									\
	for (i = n - 1; i >= 0; i--)					\
		bpf_unregister_kfunc_inline_ops(			\
			entries[i].kfunc_name);				\
}									\
									\
module_init(prefix##_init);						\
module_exit(prefix##_exit);						\
									\
MODULE_DESCRIPTION(desc);						\
MODULE_LICENSE("GPL");							\
MODULE_AUTHOR("BpfReJIT")

#endif /* _KINSN_COMMON_H */
