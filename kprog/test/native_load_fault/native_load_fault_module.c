// SPDX-License-Identifier: GPL-2.0
/* Guest fixture: invoke one loaded LSM program with valid and NULL file args. */
#include <linux/bpf.h>
#include <linux/filter.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/rcupdate.h>

static unsigned int prog_id;
static unsigned long observed_control, observed_null, extable_count;
module_param(prog_id, uint, 0400);
module_param(observed_control, ulong, 0444);
module_param(observed_null, ulong, 0444);
module_param(extable_count, ulong, 0444);

static int __init native_load_fault_init(void)
{
    struct bpf_prog *prog = bpf_prog_by_id(prog_id);
    struct inode inode = { .i_ino = 0x1234abcd };
    struct file file = { .f_pos = 0x1234abcd, .f_inode = &inode };
    unsigned long args[2] = { (unsigned long)&file, 0 };
    if (IS_ERR(prog)) return PTR_ERR(prog);
    extable_count = prog->aux->num_exentries;
    rcu_read_lock();
    observed_control = bpf_prog_run(prog, args);
    args[0] = 0;
    observed_null = bpf_prog_run(prog, args);
    rcu_read_unlock();
    pr_info("native_load_fault: prog=%u extable=%lu control=%lx null=%lx\n",
            prog_id, extable_count, observed_control, observed_null);
    bpf_prog_put(prog);
    return 0;
}
static void __exit native_load_fault_exit(void) { }
module_init(native_load_fault_init);
module_exit(native_load_fault_exit);
MODULE_LICENSE("GPL");
