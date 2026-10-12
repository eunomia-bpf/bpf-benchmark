// SPDX-License-Identifier: GPL-2.0
/* Empty placeholder so the June-module arm does not also load the current
 * bpf_x86_bmi2_shift (SHLX/SHRX/BZHI), which did not exist in June. */
#include <linux/module.h>
static int __init stub_init(void) { return 0; }
static void __exit stub_exit(void) { }
module_init(stub_init);
module_exit(stub_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("placeholder: June kinsn set has no BMI2 shift module");
