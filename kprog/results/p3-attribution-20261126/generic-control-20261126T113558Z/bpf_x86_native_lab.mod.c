#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

KSYMTAB_FUNC(kprog_htab_elem_k2, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k4, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k8, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k12, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k14, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k16, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k20, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k24, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k32, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k36, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k38, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k40, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k41, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k48, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k64, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k88, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k224, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k256, "_gpl", "");
KSYMTAB_FUNC(kprog_htab_elem_k260, "_gpl", "");

SYMBOL_CRC(kprog_htab_elem_k2, 0x595027b6, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k4, 0x5cec29f8, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k8, 0x57943564, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k12, 0xf3655513, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k14, 0xf6d95b5d, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k16, 0xf5b2a167, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k20, 0x5506c445, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k24, 0x53d13031, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k32, 0x356ae75b, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k36, 0x33bd132f, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k38, 0x3baef589, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k40, 0xc46714dc, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k41, 0xc5d2e9c1, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k48, 0xc9c8fc34, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k64, 0x04bf52e0, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k88, 0x307a5b47, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k224, 0xb166773c, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k256, 0x406b84bb, "_gpl");
SYMBOL_CRC(kprog_htab_elem_k260, 0xe0dfe199, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x037a0cba, "kfree" },
	{ 0xd9a78ac9, "kmalloc_caches" },
	{ 0xca0ffbb5, "__kmalloc_cache_noprof" },
	{ 0xdc50aae2, "__ref_stack_chk_guard" },
	{ 0xad136c5b, "debugfs_create_dir" },
	{ 0x28438631, "debugfs_create_file_full" },
	{ 0x96848186, "scnprintf" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xc6cbbc89, "capable" },
	{ 0x6a5cc518, "__kmalloc_noprof" },
	{ 0x36dcb0a8, "validate_usercopy_range" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x81a4ceb2, "mutex_lock" },
	{ 0xeb5546a2, "mutex_unlock" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x19dee613, "__fortify_panic" },
	{ 0xe2f93174, "vmemdup_user" },
	{ 0x67c42c12, "bpf_prog_get_type_dev" },
	{ 0x8746b6ad, "__kvmalloc_node_noprof" },
	{ 0x7ffe98f8, "bpf_prog_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x4f53d667, "debugfs_remove" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xf309591e, "bpf_map_get" },
	{ 0x7e2af37f, "bpf_map_put" },
	{ 0xc98c5f59, "bpf_native_image_arm" },
	{ 0x47cfd825, "kstrtouint_from_user" },
	{ 0xb7db4763, "default_llseek" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x51d8d65c, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C393DC40394B232D0E51D4B");
