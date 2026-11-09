/*
 * Host cross-check for the AArch64 artifact encoder's BPF helper-ident
 * table contract (`generated/arm64_helper_idents.h`).
 *
 * The module under test fixes the 92 kernel ids the AArch64 simulator
 * recognizes (`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`,
 * `HELPER_IDENTS`), maps each id to its 1-based position in the id-sorted
 * table. Each helper invokes its actual Linux ID, without aliases.
 *
 * This oracle restates the 92 row ids, names, and ordinals, the out-of-range
 * default and count by hand and drives the
 * generated macros and `_Static_assert`s against them. The generated
 * `_Static_assert`s run at compile time; this oracle is the value-level
 * pin. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_helper_idents_host.c -o /tmp/t_arm_hids
 *   /tmp/t_arm_hids
 */

#include <stdio.h>

#include "generated/arm64_helper_idents.h"

static int failures;
static unsigned long cases;

/* The 92 row kernel ids, in the specification's id-sorted order. */
static const int row_ids[92] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 20, 21, 23, 25, 26,
	27, 28, 31, 32, 33, 35, 36, 37, 38, 39, 43,
	44, 45, 46, 50, 54, 58, 65, 67, 68, 69, 80, 85, 86, 87, 88, 95, 99, 105, 109,
	112, 113, 114, 115, 118, 122, 124, 125, 127, 130, 131, 132, 133, 148, 152,
	154, 155, 158, 160, 161, 163, 173, 174, 175, 181, 182, 183, 184, 185, 186, 188, 189, 190, 191, 193,
	194, 195, 197, 198, 199, 200,
};

/* The helper name each row kernel id denotes, in specification order. */
static const char *const row_names[92] = {
	"bpf_map_lookup_elem", "bpf_map_update_elem",
	"bpf_map_delete_elem", "bpf_probe_read",
	"bpf_ktime_get_ns", "bpf_trace_printk",
	"bpf_get_prandom_u32", "bpf_get_smp_processor_id",
	"bpf_skb_store_bytes", "bpf_l3_csum_replace",
	"bpf_l4_csum_replace", "bpf_tail_call",
	"bpf_clone_redirect", "bpf_get_current_pid_tgid",
	"bpf_get_current_uid_gid", "bpf_get_current_comm",
	"bpf_skb_get_tunnel_key", "bpf_skb_set_tunnel_key", "bpf_redirect",
	"bpf_perf_event_output", "bpf_skb_load_bytes",
	"bpf_get_stackid", "bpf_csum_diff",
	"bpf_skb_change_proto", "bpf_skb_change_type",
	"bpf_skb_under_cgroup", "bpf_get_current_task", "bpf_probe_write_user",
	"bpf_current_task_under_cgroup", "bpf_skb_change_tail",
	"bpf_skb_pull_data", "bpf_skb_change_head",
	"bpf_xdp_adjust_head", "bpf_probe_read_str",
	"bpf_get_socket_cookie", "bpf_skb_adjust_room", "bpf_xdp_adjust_meta", "bpf_override_return",
	"bpf_xdp_adjust_tail", "bpf_get_stack",
	"bpf_skb_load_bytes_relative", "bpf_fib_lookup",
	"bpf_get_current_cgroup_id", "bpf_sk_lookup_udp", "bpf_sk_release", "bpf_map_push_elem", "bpf_map_pop_elem", "bpf_sk_fullsock", "bpf_skc_lookup_tcp", "bpf_strtol", "bpf_send_signal",
	"bpf_probe_read_user", "bpf_probe_read_kernel",
	"bpf_probe_read_user_str", "bpf_probe_read_kernel_str",
	"bpf_jiffies64", "bpf_get_netns_cookie",
	"bpf_sk_assign", "bpf_ktime_get_boot_ns", "bpf_seq_write", "bpf_ringbuf_output",
	"bpf_ringbuf_reserve", "bpf_ringbuf_submit", "bpf_ringbuf_discard",
	"bpf_copy_from_user", "bpf_redirect_neigh",
	"bpf_this_cpu_ptr", "bpf_redirect_peer", "bpf_get_current_task_btf", "bpf_ktime_get_coarse_ns", "bpf_ima_inode_hash", "bpf_check_mtu", "bpf_get_func_ip",
	"bpf_get_attach_cookie", "bpf_task_pt_regs", "bpf_loop", "bpf_strncmp",
	"bpf_get_func_arg", "bpf_get_func_ret",
	"bpf_get_func_arg_cnt", "bpf_get_retval",
	"bpf_xdp_get_buff_len",
	"bpf_xdp_load_bytes",
	"bpf_xdp_store_bytes",
	"bpf_copy_from_user_task", "bpf_ima_file_hash",
	"bpf_kptr_xchg",
	"bpf_map_lookup_percpu_elem",
	"bpf_dynptr_from_mem",
	"bpf_ringbuf_reserve_dynptr",
	"bpf_ringbuf_submit_dynptr",
	"bpf_ringbuf_discard_dynptr",

};

#define ROW_COUNT 92U

/* The generated row selector must return each row kernel id's ordinal. */
static void check_rows(void)
{
	for (unsigned i = 0; i < ROW_COUNT; i++) {
		unsigned got = KPROG_ARM64_HELPER_ROW(row_ids[i]);
		cases++;
		if (got != i + 1U) {
			printf("row %u (kernel id %d, %s) selects %u, want %u\n",
			       i + 1U, row_ids[i], row_names[i],
			       got, i + 1U);
			failures++;
		}
	}
}

/* A kernel id past the table must reach the 0 default. */
static void check_out_of_range(void)
{
	unsigned got = KPROG_ARM64_HELPER_ROW(0x100);
	cases++;
	if (got != 0U) {
		printf("out-of-range kernel id 0x100 selects %u, want 0\n",
		       got);
		failures++;
	}
}

/* The generated counts must match the hand counts. */
static void check_count(void)
{
	cases++;
	if (KPROG_ARM64_HELPER_IDENTS_COUNT != ROW_COUNT) {
		printf("KPROG_ARM64_HELPER_IDENTS_COUNT is %u, want %u\n",
		       KPROG_ARM64_HELPER_IDENTS_COUNT, ROW_COUNT);
		failures++;
	}
}

int main(void)
{
	check_rows();
	check_out_of_range();
	check_count();

	if (failures != 0) {
		printf("arm64 helper idents host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 helper idents host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
