/* Independent public Linux helper-ID-to-slot oracle. All4097 original IDs
 * remain covered, including the gaps in the sparse70 table. The production
 * switch is checked separately with actual typed helper-call host stubs. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/* Independent public Linux helper identities. */
#define X86_SIM_HELPER_bpf_map_lookup_elem 1ULL
#define X86_SIM_HELPER_bpf_map_update_elem 2ULL
#define X86_SIM_HELPER_bpf_map_delete_elem 3ULL
#define X86_SIM_HELPER_bpf_probe_read 4ULL
#define X86_SIM_HELPER_bpf_ktime_get_ns 5ULL
#define X86_SIM_HELPER_bpf_trace_printk 6ULL
#define X86_SIM_HELPER_bpf_get_prandom_u32 7ULL
#define X86_SIM_HELPER_bpf_get_smp_processor_id 8ULL
#define X86_SIM_HELPER_bpf_skb_store_bytes 9ULL
#define X86_SIM_HELPER_bpf_l3_csum_replace 10ULL
#define X86_SIM_HELPER_bpf_l4_csum_replace 11ULL
#define X86_SIM_HELPER_bpf_tail_call 12ULL
#define X86_SIM_HELPER_bpf_get_current_pid_tgid 14ULL
#define X86_SIM_HELPER_bpf_get_current_uid_gid 15ULL
#define X86_SIM_HELPER_bpf_get_current_comm 16ULL
#define X86_SIM_HELPER_bpf_skb_get_tunnel_key 20ULL
#define X86_SIM_HELPER_bpf_skb_set_tunnel_key 21ULL
#define X86_SIM_HELPER_bpf_redirect 23ULL
#define X86_SIM_HELPER_bpf_perf_event_output 25ULL
#define X86_SIM_HELPER_bpf_skb_load_bytes 26ULL
#define X86_SIM_HELPER_bpf_get_stackid 27ULL
#define X86_SIM_HELPER_bpf_csum_diff 28ULL
#define X86_SIM_HELPER_bpf_skb_change_type 32ULL
#define X86_SIM_HELPER_bpf_get_current_task 35ULL
#define X86_SIM_HELPER_bpf_probe_write_user 36ULL
#define X86_SIM_HELPER_bpf_current_task_under_cgroup 37ULL
#define X86_SIM_HELPER_bpf_skb_change_tail 38ULL
#define X86_SIM_HELPER_bpf_skb_pull_data 39ULL
#define X86_SIM_HELPER_bpf_skb_change_head 43ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_head 44ULL
#define X86_SIM_HELPER_bpf_probe_read_str 45ULL
#define X86_SIM_HELPER_bpf_get_socket_cookie 46ULL
#define X86_SIM_HELPER_bpf_skb_adjust_room 50ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_meta 54ULL
#define X86_SIM_HELPER_bpf_override_return 58ULL
#define X86_SIM_HELPER_bpf_xdp_adjust_tail 65ULL
#define X86_SIM_HELPER_bpf_get_stack 67ULL
#define X86_SIM_HELPER_bpf_skb_load_bytes_relative 68ULL
#define X86_SIM_HELPER_bpf_fib_lookup 69ULL
#define X86_SIM_HELPER_bpf_get_current_cgroup_id 80ULL
#define X86_SIM_HELPER_bpf_sk_lookup_udp 85ULL
#define X86_SIM_HELPER_bpf_sk_release 86ULL
#define X86_SIM_HELPER_bpf_map_push_elem 87ULL
#define X86_SIM_HELPER_bpf_map_pop_elem 88ULL
#define X86_SIM_HELPER_bpf_sk_fullsock 95ULL
#define X86_SIM_HELPER_bpf_skc_lookup_tcp 99ULL
#define X86_SIM_HELPER_bpf_strtol 105ULL
#define X86_SIM_HELPER_bpf_send_signal 109ULL
#define X86_SIM_HELPER_bpf_probe_read_user 112ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel 113ULL
#define X86_SIM_HELPER_bpf_probe_read_user_str 114ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel_str 115ULL
#define X86_SIM_HELPER_bpf_jiffies64 118ULL
#define X86_SIM_HELPER_bpf_get_netns_cookie 122ULL
#define X86_SIM_HELPER_bpf_sk_assign 124ULL
#define X86_SIM_HELPER_bpf_ktime_get_boot_ns 125ULL
#define X86_SIM_HELPER_bpf_ringbuf_output 130ULL
#define X86_SIM_HELPER_bpf_copy_from_user 148ULL
#define X86_SIM_HELPER_bpf_redirect_neigh 152ULL
#define X86_SIM_HELPER_bpf_redirect_peer 155ULL
#define X86_SIM_HELPER_bpf_get_current_task_btf 158ULL
#define X86_SIM_HELPER_bpf_ktime_get_coarse_ns 160ULL
#define X86_SIM_HELPER_bpf_check_mtu 163ULL
#define X86_SIM_HELPER_bpf_get_func_ip 173ULL
#define X86_SIM_HELPER_bpf_get_attach_cookie 174ULL
#define X86_SIM_HELPER_bpf_task_pt_regs 175ULL
#define X86_SIM_HELPER_bpf_loop 181ULL
#define X86_SIM_HELPER_bpf_get_func_ret 184ULL
#define X86_SIM_HELPER_bpf_xdp_load_bytes 189ULL
#define X86_SIM_HELPER_bpf_ima_file_hash 193ULL

#include "generated/x86_helper_dispatch.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* Independent ordered Linux IDs; gaps must never alias another slot. */
static long model_slot(unsigned long long id)
{
    static const unsigned long long ids[] = {1ULL, 2ULL, 3ULL, 4ULL, 5ULL, 6ULL, 7ULL, 8ULL, 9ULL, 10ULL, 11ULL, 12ULL, 14ULL, 15ULL, 16ULL, 20ULL, 21ULL, 23ULL, 25ULL, 26ULL, 27ULL, 28ULL, 32ULL, 35ULL, 36ULL, 37ULL, 38ULL, 39ULL, 43ULL, 44ULL, 45ULL, 46ULL, 50ULL, 54ULL, 58ULL, 65ULL, 67ULL, 68ULL, 69ULL, 80ULL, 85ULL, 86ULL, 87ULL, 88ULL, 95ULL, 99ULL, 105ULL, 109ULL, 112ULL, 113ULL, 114ULL, 115ULL, 118ULL, 122ULL, 124ULL, 125ULL, 130ULL, 148ULL, 152ULL, 155ULL, 158ULL, 160ULL, 163ULL, 173ULL, 174ULL, 175ULL, 181ULL, 184ULL, 189ULL, 193ULL};
    unsigned i;
    for (i = 0; i < sizeof(ids) / sizeof(ids[0]); i++)
        if (id == ids[i]) return (long)i;
    return -1;
}

int main(void)
{
	unsigned long long id;

	cases++;
	if (KPROG_X86_HELPER_COUNT != 70U) {
		printf("MISMATCH count got=%u want=70\n",
		       (unsigned)KPROG_X86_HELPER_COUNT);
		failures++;
	}

	/* The ladder selector returns the armed slot over the whole named id
	 * space and a long way past it, against the independent binding. */
	for (id = 0; id <= 4096ULL; id++) {
		unsigned got = KPROG_X86_HELPER_SLOT((__u64)id);
		long want = model_slot(id);

		cases++;
		if (want < 0) {
			if (got != KPROG_X86_HELPER_SLOT_NONE) {
				printf("MISMATCH unarmed slot id=%llu got=%u\n",
				       id, got);
				failures++;
			}
			continue;
		}
		if (got != (unsigned)want) {
			printf("MISMATCH slot id=%llu got=%u want=%ld\n",
			       id, got, want);
			failures++;
		}
	}

	/* The hand-written id defines the generated drift checks bind to must
	 * roll up to the slot their own number names. */
	cases++;
	if (KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_map_lookup_elem) != 0U ||
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_uid_gid) != 13U ||
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ktime_get_ns) != 4U ||
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_task) != 23U) {
		printf("MISMATCH dispatch slot drift\n");
		failures++;
	}

	/* The named-but-unarmed helper ids all reach the default arm. */
	cases++;
	for (id = 0ULL; id <= 256ULL; id++) {
		if (model_slot(id) < 0 && KPROG_X86_HELPER_SLOT((__u64)id) !=
		    KPROG_X86_HELPER_SLOT_NONE) {
			printf("MISMATCH unarmed named slot id=%llu\n", id);
			failures++;
		}
	}

	if (failures != 0) {
		printf("x86 helper dispatch host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 helper dispatch host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
