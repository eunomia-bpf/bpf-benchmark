/*
 * Host cross-check for the x86-64 helper-id -> helper-body dispatch contract
 * (STEP 0113).
 *
 * The module under test is `generated/x86_helper_dispatch.h`. It fixes the
 * ladder slot the simulator's hand-written `X86_SIM_BPF_CALL_ID` ladder
 * dispatches each decoded 64-bit BPF helper id to: the seven armed helpers
 * `bpf_map_lookup_elem .. bpf_ktime_get_ns` are the ids `1 .. 7` in that
 * ladder order, so slot `i` is helper id `i + 1`, and every other id
 * (the zero id, the named-but-unarmed ids `8 .. 21`, and every id above them)
 * reaches the default zero-write arm.
 *
 * The simulator binds a helper id to a body by the hand-written `if/else-if`
 * ladder; the generated header's `_Static_assert`s pin each
 * `X86_SIM_HELPER_bpf_*` id define to the generated `helperIds` table. This
 * oracle drives the contract's `KPROG_X86_HELPER_SLOT` /
 * `KPROG_X86_HELPER_COUNT`, restates the binding from the raw helper ids, and
 * the two must agree on every id; the drift checks additionally pin the
 * hand-written id defines to the generated table at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_helper_dispatch_host.c -o /tmp/t_xhd
 *   /tmp/t_xhd
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/* The hand-written helper-id defines the generated drift checks bind to. */
#define X86_SIM_HELPER_bpf_map_lookup_elem 1ULL
#define X86_SIM_HELPER_bpf_map_update_elem 2ULL
#define X86_SIM_HELPER_bpf_map_delete_elem 3ULL
#define X86_SIM_HELPER_bpf_get_current_uid_gid 4ULL
#define X86_SIM_HELPER_bpf_get_current_pid_tgid 5ULL
#define X86_SIM_HELPER_bpf_get_smp_processor_id 6ULL
#define X86_SIM_HELPER_bpf_ktime_get_ns 7ULL
#define X86_SIM_HELPER_bpf_current_task_under_cgroup 8ULL
#define X86_SIM_HELPER_bpf_get_current_comm 9ULL
#define X86_SIM_HELPER_bpf_get_current_cgroup_id 10ULL
#define X86_SIM_HELPER_bpf_get_stackid 11ULL
#define X86_SIM_HELPER_bpf_perf_event_output 12ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel 13ULL
#define X86_SIM_HELPER_bpf_probe_read_kernel_str 14ULL
#define X86_SIM_HELPER_bpf_probe_read_user_str 15ULL
#define X86_SIM_HELPER_bpf_get_stack 16ULL
#define X86_SIM_HELPER_bpf_copy_from_user_str 17ULL
#define X86_SIM_HELPER_bpf_attach_map 18ULL
#define X86_SIM_HELPER_bpf_attach_tmp_map 19ULL
#define X86_SIM_HELPER_bpf_prog_load_map 20ULL
#define X86_SIM_HELPER_bpf_get_current_task 21ULL

#include "generated/x86_helper_dispatch.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent binding: the armed helper id `n` in `1 .. 7` names ladder
 * slot `n - 1`; every other id names no slot, reported as -1. */
static long model_slot(unsigned long long id)
{
	return id >= 1ULL && id <= 7ULL ? (long)(id - 1ULL) : -1L;
}

int main(void)
{
	unsigned long long id;

	cases++;
	if (KPROG_X86_HELPER_COUNT != 7U) {
		printf("MISMATCH count got=%u want=7\n",
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
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_uid_gid) != 3U ||
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_ktime_get_ns) != 6U ||
	    KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_get_current_task) !=
	        KPROG_X86_HELPER_SLOT_NONE) {
		printf("MISMATCH dispatch slot drift\n");
		failures++;
	}

	/* The named-but-unarmed helper ids all reach the default arm. */
	cases++;
	for (id = 8ULL; id <= 21ULL; id++) {
		if (KPROG_X86_HELPER_SLOT((__u64)id) !=
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
