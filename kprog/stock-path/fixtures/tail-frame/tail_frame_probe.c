#include <linux/module.h>
#include <linux/bpf.h>
#include <linux/filter.h>
#include <linux/rcupdate.h>
#include <net/xdp.h>
extern struct bpf_prog *bpf_prog_by_id(u32 id);
static unsigned int prog_id;
module_param(prog_id, uint, 0400);
static int __init tail_frame_probe_init(void)
{
    const u64 sentinel = 0x17a5a55a3712cafeULL;
    register u64 saved asm("r12") = sentinel;
    unsigned long sp_before, sp_after, bp_before, bp_after;
    unsigned char packet[64] = {};
    struct xdp_buff ctx = {
        .data = packet, .data_end = packet + sizeof(packet),
        .data_meta = packet, .data_hard_start = packet,
        .frame_sz = sizeof(packet),
    };
    struct bpf_prog *prog = bpf_prog_by_id(prog_id);
    u32 value;
    if (IS_ERR(prog))
        return PTR_ERR(prog);
    migrate_disable();
    rcu_read_lock();
    asm volatile("mov %%rsp,%0; mov %%rbp,%1"
                 : "=m"(sp_before), "=m"(bp_before) : : "memory");
    asm volatile("" : "+r"(saved) : : "memory");
    value = bpf_prog_run_xdp(prog, &ctx);
    asm volatile("" : "+r"(saved) : : "memory");
    asm volatile("mov %%rsp,%0; mov %%rbp,%1"
                 : "=m"(sp_after), "=m"(bp_after) : : "memory");
    rcu_read_unlock();
    migrate_enable();
    bpf_prog_put(prog);
    pr_info("stock_tail_frame: retval=%u r12_preserved=%u rsp_preserved=%u rbp_preserved=%u\n",
            value, saved == sentinel, sp_after == sp_before, bp_after == bp_before);
    return value == 2 && saved == sentinel && sp_after == sp_before &&
           bp_after == bp_before ? 0 : -EUCLEAN;
}
static void __exit tail_frame_probe_exit(void) { }
module_init(tail_frame_probe_init);
module_exit(tail_frame_probe_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Stock native tail frame observation");
