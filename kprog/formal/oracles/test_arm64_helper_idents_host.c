/*
 * Host cross-check for the AArch64 artifact encoder's BPF helper-ident
 * table contract (`generated/arm64_helper_idents.h`).
 *
 * The module under test fixes the 61 kernel ids the AArch64 simulator
 * recognizes (`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`,
 * `HELPER_IDENTS`), maps each id to its 1-based position in the id-sorted
 * table, and pins the five sim-header forwarding targets to the 1-based
 * lexicographic rank their target occupies over the full 61-name table.
 *
 * This oracle restates the 61 row ids, names, and ordinals, the out-of-range
 * default, the counts, and the five delegate ranks by hand and drives the
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

/* The 61 row kernel ids, in the specification's id-sorted order. */
static const int row_ids[61] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 21, 23, 25, 26,
	27, 28, 31, 32, 33, 35, 37, 38, 39, 43,
	44, 45, 46, 50, 65, 67, 68, 69, 80, 95,
	112, 113, 114, 115, 118, 122, 125, 127, 148, 152,
	158, 161, 174, 175, 183, 184, 185, 186, 191, 193,
	195,
};

/* The helper name each row kernel id denotes, in specification order. */
static const char *const row_names[61] = {
	"bpf_map_lookup_elem", "bpf_map_update_elem",
	"bpf_map_delete_elem", "bpf_probe_read",
	"bpf_ktime_get_ns", "bpf_trace_printk",
	"bpf_get_prandom_u32", "bpf_get_smp_processor_id",
	"bpf_skb_store_bytes", "bpf_l3_csum_replace",
	"bpf_l4_csum_replace", "bpf_tail_call",
	"bpf_clone_redirect", "bpf_get_current_pid_tgid",
	"bpf_get_current_uid_gid", "bpf_get_current_comm",
	"bpf_skb_set_tunnel_key", "bpf_redirect",
	"bpf_perf_event_output", "bpf_skb_load_bytes",
	"bpf_get_stackid", "bpf_csum_diff",
	"bpf_skb_change_proto", "bpf_skb_change_type",
	"bpf_skb_under_cgroup", "bpf_get_current_task",
	"bpf_current_task_under_cgroup", "bpf_skb_change_tail",
	"bpf_skb_pull_data", "bpf_skb_change_head",
	"bpf_xdp_adjust_head", "bpf_probe_read_str",
	"bpf_get_socket_cookie", "bpf_skb_adjust_room",
	"bpf_xdp_adjust_tail", "bpf_get_stack",
	"bpf_skb_load_bytes_relative", "bpf_fib_lookup",
	"bpf_get_current_cgroup_id", "bpf_sk_fullsock",
	"bpf_probe_read_user", "bpf_probe_read_kernel",
	"bpf_probe_read_user_str", "bpf_probe_read_kernel_str",
	"bpf_jiffies64", "bpf_get_netns_cookie",
	"bpf_ktime_get_boot_ns", "bpf_seq_write",
	"bpf_copy_from_user", "bpf_redirect_neigh",
	"bpf_get_current_task_btf", "bpf_ima_inode_hash",
	"bpf_get_attach_cookie", "bpf_task_pt_regs",
	"bpf_get_func_arg", "bpf_get_func_ret",
	"bpf_get_func_arg_cnt", "bpf_get_retval",
	"bpf_copy_from_user_task", "bpf_ima_file_hash",
	"bpf_map_lookup_percpu_elem",
};

/* The 1-based by-ID ordinal each row kernel id must select. */
static const unsigned row_ordinals[61] = {
	1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U,
	11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U,
	21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U,
	31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U,
	41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U,
	51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U,
	61U,
};
#define ROW_COUNT 61U

/* The five forwarding macros, by source kernel id, with the target helper
 * each one runs and the target's 1-based lexicographic rank over the full
 * 61-name table. */
static const int delegate_ids[5] = {
	158, 175, 191, 193, 195,
};
static const char *const delegate_targets[5] = {
	"bpf_get_current_task", "bpf_get_current_task",
	"bpf_copy_from_user", "bpf_ima_inode_hash",
	"bpf_map_lookup_elem",
};
static const unsigned delegate_ranks[5] = {
	11U, 11U, 2U, 25U, 32U,
};
#define DELEGATE_COUNT 5U

/* The generated row selector must return each row kernel id's ordinal. */
static void check_rows(void)
{
	for (unsigned i = 0; i < ROW_COUNT; i++) {
		unsigned got = KPROG_ARM64_HELPER_ROW(row_ids[i]);
		cases++;
		if (got != row_ordinals[i]) {
			printf("row %u (kernel id %d, %s) selects %u, want %u\n",
			       i + 1U, row_ids[i], row_names[i],
			       got, row_ordinals[i]);
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
	cases++;
	if (KPROG_ARM64_HELPER_DELEGATE_COUNT != DELEGATE_COUNT) {
		printf("KPROG_ARM64_HELPER_DELEGATE_COUNT is %u, want %u\n",
		       KPROG_ARM64_HELPER_DELEGATE_COUNT, DELEGATE_COUNT);
		failures++;
	}
}

/* The generated delegate constants must pin each forwarding target's rank. */
static void check_delegates(void)
{
	const unsigned got[DELEGATE_COUNT] = {
		KPROG_ARM64_HELPER_DELEGATE_BPF_GET_CURRENT_TASK_BTF,
		KPROG_ARM64_HELPER_DELEGATE_BPF_TASK_PT_REGS,
		KPROG_ARM64_HELPER_DELEGATE_BPF_COPY_FROM_USER_TASK,
		KPROG_ARM64_HELPER_DELEGATE_BPF_IMA_FILE_HASH,
		KPROG_ARM64_HELPER_DELEGATE_BPF_MAP_LOOKUP_PERCPU_ELEM,
	};
	for (unsigned i = 0; i < DELEGATE_COUNT; i++) {
		cases++;
		if (got[i] != delegate_ranks[i]) {
			printf("delegate %u (kernel id %d, target %s) is %u, "
			       "want %u\n", i + 1U, delegate_ids[i],
			       delegate_targets[i], got[i],
			       delegate_ranks[i]);
			failures++;
		}
	}
}

int main(void)
{
	check_rows();
	check_out_of_range();
	check_count();
	check_delegates();

	if (failures != 0) {
		printf("arm64 helper idents host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 helper idents host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
