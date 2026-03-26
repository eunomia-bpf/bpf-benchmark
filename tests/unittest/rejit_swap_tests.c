// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT swap/rollback regression tests
 *
 * T1: metadata consistency across REJIT with different instruction lengths
 * T2: repeated REJIT of XDP program with behavioral verification
 * T3: concurrent bpf_prog_get_info_by_fd() + REJIT
 * T4: tail-call reachability transition stays behaviorally consistent
 * T5: orig_prog_insns is updated to the latest REJIT bytecode
 *
 * Notes:
 * - bpf_prog_info does not expose prog->len or aux->tail_call_reachable
 *   directly. These tests use orig_prog_len/xlated_prog_len plus observable
 *   post-REJIT behavior as the userspace-visible consistency signal.
 * - T1 and T2 use XDP programs (no attach needed) to avoid kprobe/fentry
 *   availability issues in VM environments.
 *
 * Build:
 *   make -C tests/unittest
 *
 * Run:
 *   sudo tests/unittest/build/rejit_swap_tests
 */
#define _GNU_SOURCE
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

/* ---- BPF instruction helpers ------------------------------------- */

#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){.code = BPF_ALU64 | BPF_MOV | BPF_X, \
			   .dst_reg = DST, .src_reg = SRC})

#define BPF_MOV64_IMM(DST, IMM) \
	((struct bpf_insn){.code = BPF_ALU64 | BPF_MOV | BPF_K, \
			   .dst_reg = DST, .imm = IMM})

#define BPF_EXIT_INSN() \
	((struct bpf_insn){.code = BPF_JMP | BPF_EXIT})

#define BPF_EMIT_CALL(FUNC) \
	((struct bpf_insn){.code = BPF_JMP | BPF_CALL, .imm = FUNC})

/* ---- Simple test framework --------------------------------------- */

static int g_pass;
static int g_fail;
static int g_skip;

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s (errno=%d: %s)\n", \
		name, reason, errno, strerror(errno)); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	printf("  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

/* ---- Syscall helpers --------------------------------------------- */

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

static int create_prog_array_map(__u32 max_entries)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_PROG_ARRAY;
	attr.key_size = 4;
	attr.value_size = 4;
	attr.max_entries = max_entries;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

static int map_update_prog_fd(int map_fd, __u32 key, int prog_fd)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(&prog_fd);
	attr.flags = BPF_ANY;

	return sys_bpf(BPF_MAP_UPDATE_ELEM, &attr, sizeof(attr));
}

static int map_delete_elem(int map_fd, __u32 key)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);

	return sys_bpf(BPF_MAP_DELETE_ELEM, &attr, sizeof(attr));
}

static int get_prog_info(int prog_fd, struct bpf_prog_info *info,
			 __u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd = prog_fd;
	attr.info.info = ptr_to_u64(info);
	attr.info.info_len = *info_len;

	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	*info_len = attr.info.info_len;
	return 0;
}

static int get_original_insns(int prog_fd, struct bpf_insn **out_insns)
{
	struct bpf_prog_info info;
	__u32 info_len;
	struct bpf_insn *insns;

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0)
		return -1;

	if (info.orig_prog_len == 0) {
		if (info.xlated_prog_len == 0)
			return -1;

		__u32 cnt = info.xlated_prog_len / sizeof(struct bpf_insn);
		insns = calloc(cnt, sizeof(*insns));
		if (!insns)
			return -1;

		memset(&info, 0, sizeof(info));
		info.xlated_prog_insns = ptr_to_u64(insns);
		info.xlated_prog_len = cnt * sizeof(*insns);
		info_len = sizeof(info);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			free(insns);
			return -1;
		}

		*out_insns = insns;
		return cnt;
	}

	{
		__u32 cnt = info.orig_prog_len / sizeof(struct bpf_insn);

		insns = calloc(cnt, sizeof(*insns));
		if (!insns)
			return -1;

		memset(&info, 0, sizeof(info));
		info.orig_prog_insns = ptr_to_u64(insns);
		info.orig_prog_len = cnt * sizeof(*insns);
		info_len = sizeof(info);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			free(insns);
			return -1;
		}

		*out_insns = insns;
		return cnt;
	}
}

/* ---- Generic REJIT / load helpers -------------------------------- */

static int load_prog_full(__u32 prog_type, const struct bpf_insn *insns,
			  __u32 insn_cnt, __u32 expected_attach_type,
			  __u32 attach_btf_id, char *log_buf,
			  size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type = prog_type;
	attr.insn_cnt = insn_cnt;
	attr.insns = ptr_to_u64(insns);
	attr.license = ptr_to_u64(license);
	attr.log_level = 1;
	attr.log_buf = ptr_to_u64(log_buf);
	attr.log_size = log_buf_sz;
	attr.expected_attach_type = expected_attach_type;
	attr.attach_btf_id = attach_btf_id;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			 char *log_buf, size_t log_buf_sz)
{
	return load_prog_full(BPF_PROG_TYPE_XDP, insns, insn_cnt, 0, 0,
			      log_buf, log_buf_sz);
}

static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static int test_run_xdp(int prog_fd, __u32 *retval)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* ---- Canonical XDP programs -------------------------------------- */

static const struct bpf_insn prog_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

static const struct bpf_insn prog_xdp_drop[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

static const struct bpf_insn prog_xdp_tx_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* XDP_ABORTED = 0 */
static const struct bpf_insn prog_xdp_aborted[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_ABORTED },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* A 5-insn program returning XDP_REDIRECT (4) for length variety */
static const struct bpf_insn prog_xdp_5insn[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 0 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 4 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 0 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* ---- Tail-call program builders ---------------------------------- */

static __u32 build_simple_prog(struct bpf_insn *insns, __s32 retval)
{
	int i = 0;

	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, retval);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

static __u32 build_tail_call_caller(struct bpf_insn *insns, int map_fd,
				    __u32 index, __s32 fallback_ret)
{
	int i = 0;

	insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
	insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
	insns[i++] = (struct bpf_insn){
		.code = BPF_LD | BPF_DW | BPF_IMM,
		.dst_reg = BPF_REG_2,
		.src_reg = BPF_PSEUDO_MAP_FD,
		.imm = map_fd,
	};
	insns[i++] = (struct bpf_insn){ .imm = 0 };
	insns[i++] = BPF_MOV64_IMM(BPF_REG_3, index);
	insns[i++] = BPF_EMIT_CALL(BPF_FUNC_tail_call);
	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, fallback_ret);
	insns[i++] = BPF_EXIT_INSN();

	return i;
}

/* ---- T3 concurrent get_info + REJIT helper ----------------------- */

struct info_rejit_args {
	int prog_fd;
	volatile int info_err;
	volatile int rejit_err;
};

static void *info_query_worker(void *arg)
{
	struct info_rejit_args *a = arg;
	int i;

	for (i = 0; i < 1000; i++) {
		struct bpf_prog_info info;
		struct bpf_insn xlated[64];
		struct bpf_insn orig[64];
		__u32 info_len = sizeof(info);

		memset(&info, 0, sizeof(info));
		memset(xlated, 0, sizeof(xlated));
		memset(orig, 0, sizeof(orig));
		info.xlated_prog_insns = ptr_to_u64(xlated);
		info.xlated_prog_len = sizeof(xlated);
		info.orig_prog_insns = ptr_to_u64(orig);
		info.orig_prog_len = sizeof(orig);

		if (get_prog_info(a->prog_fd, &info, &info_len) < 0) {
			a->info_err = errno ? errno : EIO;
			break;
		}
		if (info.xlated_prog_len == 0 || info.orig_prog_len == 0) {
			a->info_err = EIO;
			break;
		}
	}

	return NULL;
}

static void *rejit_stress_worker(void *arg)
{
	struct info_rejit_args *a = arg;
	char log_buf[65536];
	int i;

	for (i = 0; i < 1000; i++) {
		const struct bpf_insn *insns;
		__u32 cnt;

		if (i % 2 == 0) {
			insns = prog_xdp_drop;
			cnt = ARRAY_SIZE(prog_xdp_drop);
		} else {
			insns = prog_xdp_tx_long;
			cnt = ARRAY_SIZE(prog_xdp_tx_long);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(a->prog_fd, insns, cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			a->rejit_err = errno ? errno : EIO;
			break;
		}
	}

	return NULL;
}

/* ================================================================== */
/*  T1: metadata consistency across REJIT with different lengths       */
/* ================================================================== */
/*
 * Load an XDP program, REJIT it between programs of different instruction
 * counts, and verify that orig_prog_len and xlated_prog_len stay consistent
 * with the most recently applied bytecode after each step.
 *
 * Uses XDP programs (no attach needed) to avoid kprobe/fentry availability
 * issues in VM environments.
 */
static void test_t1_rollback_metadata_consistency(void)
{
	const char *name = "T1_metadata_consistency_across_rejit";
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd;
	__u32 retval;

	struct {
		const char *label;
		const struct bpf_insn *insns;
		__u32 insn_cnt;
		__u32 expected_retval;
	} steps[] = {
		/* Step 0: REJIT to 4-insn prog (XDP_TX=3) */
		{ "xdp_tx_long", prog_xdp_tx_long,
		  ARRAY_SIZE(prog_xdp_tx_long), XDP_TX },
		/* Step 1: REJIT to 2-insn prog (XDP_DROP=1) */
		{ "xdp_drop", prog_xdp_drop,
		  ARRAY_SIZE(prog_xdp_drop), XDP_DROP },
		/* Step 2: REJIT to 5-insn prog (XDP_REDIRECT=4) */
		{ "xdp_5insn", prog_xdp_5insn,
		  ARRAY_SIZE(prog_xdp_5insn), 4 },
		/* Step 3: REJIT back to 2-insn prog (XDP_PASS=2) */
		{ "xdp_pass", prog_xdp_pass,
		  ARRAY_SIZE(prog_xdp_pass), XDP_PASS },
	};
	int i;

	/* Load initial XDP_PASS program */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "initial load failed");
		return;
	}

	/* Verify initial state */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "initial get_info failed");
		goto out;
	}
	if (info.xlated_prog_len != ARRAY_SIZE(prog_xdp_pass) * sizeof(struct bpf_insn)) {
		TEST_FAIL(name, "initial xlated_prog_len mismatch");
		goto out;
	}

	for (i = 0; i < (int)(sizeof(steps) / sizeof(steps[0])); i++) {
		__u32 expected_len = steps[i].insn_cnt * sizeof(struct bpf_insn);

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, steps[i].insns, steps[i].insn_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    REJIT failed at step %d (%s): %s\n",
				i, steps[i].label, strerror(errno));
			TEST_FAIL(name, "REJIT failed");
			goto out;
		}

		/* Verify behavior */
		if (test_run_xdp(prog_fd, &retval) < 0 ||
		    retval != steps[i].expected_retval) {
			fprintf(stderr, "    step %d (%s): retval=%u expected=%u\n",
				i, steps[i].label, retval,
				steps[i].expected_retval);
			TEST_FAIL(name, "behavior mismatch after REJIT");
			goto out;
		}

		/* Verify metadata consistency */
		memset(&info, 0, sizeof(info));
		info_len = sizeof(info);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			TEST_FAIL(name, "get_info failed after REJIT");
			goto out;
		}

		if (info.orig_prog_len != expected_len) {
			fprintf(stderr, "    step %d (%s): orig_prog_len=%u expected=%u\n",
				i, steps[i].label, info.orig_prog_len,
				expected_len);
			TEST_FAIL(name, "orig_prog_len mismatch");
			goto out;
		}
		if (info.xlated_prog_len != expected_len) {
			fprintf(stderr, "    step %d (%s): xlated_prog_len=%u expected=%u\n",
				i, steps[i].label, info.xlated_prog_len,
				expected_len);
			TEST_FAIL(name, "xlated_prog_len mismatch");
			goto out;
		}
		if (info.jited_prog_len == 0) {
			TEST_FAIL(name, "jited_prog_len is 0 after REJIT");
			goto out;
		}
	}

	TEST_PASS(name);

out:
	close(prog_fd);
}

/* ================================================================== */
/*  T2: repeated REJIT of XDP program with behavioral verification     */
/* ================================================================== */
/*
 * Load an XDP program and REJIT it repeatedly (8 rounds) alternating between
 * different programs. Every REJIT must produce the correct behavior when run
 * via BPF_PROG_TEST_RUN and the metadata must stay consistent.
 *
 * Uses XDP programs (no attach needed) to avoid kprobe/fentry availability
 * issues in VM environments.
 */
static void test_t2_repeated_attached_rejit_concept(void)
{
	const char *name = "T2_repeated_xdp_rejit";
	char log_buf[65536];
	int prog_fd;
	__u32 retval;
	int i;

	struct {
		const struct bpf_insn *insns;
		__u32 insn_cnt;
		__u32 expected_retval;
	} variants[] = {
		{ prog_xdp_drop,     ARRAY_SIZE(prog_xdp_drop),     XDP_DROP },
		{ prog_xdp_tx_long,  ARRAY_SIZE(prog_xdp_tx_long),  XDP_TX },
		{ prog_xdp_pass,     ARRAY_SIZE(prog_xdp_pass),     XDP_PASS },
		{ prog_xdp_aborted,  ARRAY_SIZE(prog_xdp_aborted),  XDP_ABORTED },
	};
	int nvar = (int)(sizeof(variants) / sizeof(variants[0]));

	/* Load initial XDP_PASS program */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* REJIT 8 rounds, cycling through variants */
	for (i = 0; i < 8; i++) {
		int vi = i % nvar;

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, variants[vi].insns,
			       variants[vi].insn_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    round %d REJIT failed: %s\n",
				i, strerror(errno));
			TEST_FAIL(name, "REJIT failed");
			close(prog_fd);
			return;
		}

		if (test_run_xdp(prog_fd, &retval) < 0 ||
		    retval != variants[vi].expected_retval) {
			fprintf(stderr, "    round %d: retval=%u expected=%u\n",
				i, retval, variants[vi].expected_retval);
			TEST_FAIL(name, "behavior mismatch");
			close(prog_fd);
			return;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T3: concurrent get_info + REJIT                                   */
/* ================================================================== */
/*
 * One thread continuously snapshots prog info (including xlated/original
 * instruction buffers) while another thread REJITs the same XDP program.
 * The loop runs 1000 rounds. The kernel must not crash and neither syscall may
 * fail.
 */
static void test_t3_concurrent_info_query_and_rejit(void)
{
	const char *name = "T3_concurrent_info_query_and_rejit";
	pthread_t info_thread, rejit_thread;
	struct info_rejit_args args;
	char log_buf[65536];
	int prog_fd;
	__u32 retval;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	memset(&args, 0, sizeof(args));
	args.prog_fd = prog_fd;

	if (pthread_create(&info_thread, NULL, info_query_worker, &args) != 0) {
		TEST_FAIL(name, "pthread_create(info) failed");
		close(prog_fd);
		return;
	}
	if (pthread_create(&rejit_thread, NULL, rejit_stress_worker, &args) != 0) {
		TEST_FAIL(name, "pthread_create(rejit) failed");
		pthread_join(info_thread, NULL);
		close(prog_fd);
		return;
	}

	pthread_join(info_thread, NULL);
	pthread_join(rejit_thread, NULL);

	if (args.info_err) {
		TEST_FAIL(name, "bpf_prog_get_info_by_fd failed under concurrency");
		close(prog_fd);
		return;
	}
	if (args.rejit_err) {
		TEST_FAIL(name, "REJIT failed under concurrent info polling");
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_TX) {
		TEST_FAIL(name, "final program behavior mismatch");
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T4: tail_call poke_tab consistency after REJIT                     */
/* ================================================================== */
/*
 * REJIT of a tail-call caller requires the new bytecode to have the same
 * poke_tab pattern (same map, same index). This test verifies:
 *   1. Load a tail-call caller (fallback = XDP_DROP) with target in map.
 *   2. Verify tail-call works (returns target's XDP_TX).
 *   3. REJIT the caller with same tail-call but different fallback (XDP_ABORTED).
 *   4. Verify tail-call still works after REJIT.
 *   5. Remove target from map, verify new fallback (XDP_ABORTED).
 *   6. Re-insert target, REJIT again with fallback = XDP_PASS.
 *   7. Verify tail-call path and new fallback.
 */
static void test_t4_tail_call_reachable_transition(void)
{
	const char *name = "T4_tail_call_poke_tab_consistency";
	struct bpf_insn caller_insns[16], rejit_insns[16], target_prog[4];
	char log_buf[65536];
	__u32 caller_cnt, rejit_cnt, target_cnt, retval;
	int map_fd = -1, caller_fd = -1, target_fd = -1;

	/* 1. Create PROG_ARRAY map */
	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		TEST_FAIL(name, "prog array create failed");
		return;
	}

	/* 2. Load target prog: returns XDP_TX */
	target_cnt = build_simple_prog(target_prog, XDP_TX);
	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_prog, target_cnt,
				  log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		TEST_FAIL(name, "target load failed");
		goto out;
	}

	/* 3. Insert target into map at index 0 */
	if (map_update_prog_fd(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "prog array update failed");
		goto out;
	}

	/* 4. Load caller: tail_call(map, 0), fallback = XDP_DROP */
	caller_cnt = build_tail_call_caller(caller_insns, map_fd, 0, XDP_DROP);
	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				  log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		fprintf(stderr, "    caller load failed: %s\n%s\n",
			strerror(errno), log_buf);
		TEST_FAIL(name, "caller load failed");
		goto out;
	}

	/* 5. Run: tail_call should fire, returning target's XDP_TX */
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_TX) {
		fprintf(stderr, "    pre-rejit: retval=%u expected=%u\n",
			retval, XDP_TX);
		TEST_FAIL(name, "pre-rejit tail-call path mismatch");
		goto out;
	}

	/* 6. REJIT caller: same tail_call but fallback = XDP_ABORTED */
	rejit_cnt = build_tail_call_caller(rejit_insns, map_fd, 0, XDP_ABORTED);
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(caller_fd, rejit_insns, rejit_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    REJIT #1 failed: %s\n%s\n",
			strerror(errno), log_buf);
		TEST_FAIL(name, "REJIT to XDP_ABORTED fallback failed");
		goto out;
	}

	/* 7. Tail-call should still work -> XDP_TX from target */
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_TX) {
		fprintf(stderr, "    post-rejit#1 with target: retval=%u expected=%u\n",
			retval, XDP_TX);
		TEST_FAIL(name, "tail-call broken after first REJIT");
		goto out;
	}

	/* 8. Remove target from map -> fallback fires */
	if (map_delete_elem(map_fd, 0) < 0) {
		TEST_FAIL(name, "prog array delete failed");
		goto out;
	}
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_ABORTED) {
		fprintf(stderr, "    post-rejit#1 fallback: retval=%u expected=%u\n",
			retval, XDP_ABORTED);
		TEST_FAIL(name, "fallback mismatch after first REJIT");
		goto out;
	}

	/* 9. Re-insert target, REJIT again with fallback = XDP_PASS */
	if (map_update_prog_fd(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "prog array reinsert failed");
		goto out;
	}
	rejit_cnt = build_tail_call_caller(rejit_insns, map_fd, 0, XDP_PASS);
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(caller_fd, rejit_insns, rejit_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    REJIT #2 failed: %s\n%s\n",
			strerror(errno), log_buf);
		TEST_FAIL(name, "REJIT to XDP_PASS fallback failed");
		goto out;
	}

	/* 10. Tail-call should still work -> XDP_TX from target */
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_TX) {
		fprintf(stderr, "    post-rejit#2 with target: retval=%u expected=%u\n",
			retval, XDP_TX);
		TEST_FAIL(name, "tail-call broken after second REJIT");
		goto out;
	}

	/* 11. Remove target -> new fallback XDP_PASS */
	if (map_delete_elem(map_fd, 0) < 0) {
		TEST_FAIL(name, "prog array second delete failed");
		goto out;
	}
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		fprintf(stderr, "    post-rejit#2 fallback: retval=%u expected=%u\n",
			retval, XDP_PASS);
		TEST_FAIL(name, "fallback mismatch after second REJIT");
		goto out;
	}

	TEST_PASS(name);

out:
	if (target_fd >= 0)
		close(target_fd);
	if (caller_fd >= 0)
		close(caller_fd);
	if (map_fd >= 0)
		close(map_fd);
}

/* ================================================================== */
/*  T5: orig_prog_insns updated after REJIT                            */
/* ================================================================== */
/*
 * After REJIT, GET_ORIGINAL should expose the most recently submitted bytecode,
 * not the original load-time program forever.
 */
static void test_t5_orig_insns_updated_after_rejit(void)
{
	const char *name = "T5_orig_prog_insns_updated";
	struct bpf_insn *orig_insns = NULL;
	char log_buf[65536];
	int prog_fd, orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "first REJIT failed");
		goto out;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt != (int)ARRAY_SIZE(prog_xdp_tx_long) ||
	    memcmp(orig_insns, prog_xdp_tx_long, sizeof(prog_xdp_tx_long)) != 0) {
		TEST_FAIL(name, "orig_prog_insns did not match first REJIT bytecode");
		goto out;
	}
	free(orig_insns);
	orig_insns = NULL;

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "second REJIT failed");
		goto out;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt != (int)ARRAY_SIZE(prog_xdp_drop) ||
	    memcmp(orig_insns, prog_xdp_drop, sizeof(prog_xdp_drop)) != 0) {
		TEST_FAIL(name, "orig_prog_insns did not match second REJIT bytecode");
		goto out;
	}

	TEST_PASS(name);

out:
	free(orig_insns);
	close(prog_fd);
}

/* ================================================================== */
/*  Main                                                               */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT swap/rollback regression tests ===\n");

	printf("\n[T1] metadata consistency across REJIT:\n");
	test_t1_rollback_metadata_consistency();

	printf("\n[T2] repeated XDP REJIT:\n");
	test_t2_repeated_attached_rejit_concept();

	printf("\n[T3] concurrent info query + REJIT:\n");
	test_t3_concurrent_info_query_and_rejit();

	printf("\n[T4] tail_call poke_tab consistency:\n");
	test_t4_tail_call_reachable_transition();

	printf("\n[T5] orig_prog_insns follows latest REJIT:\n");
	test_t5_orig_insns_updated_after_rejit();

	printf("\n=== Summary: %d passed, %d failed, %d skipped ===\n",
	       g_pass, g_fail, g_skip);
	return g_fail ? 1 : 0;
}
