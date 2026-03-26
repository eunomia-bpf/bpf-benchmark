// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Verifier Negative Tests — Daemon Bug Regression Suite
 *
 * Each test constructs malformed bytecode that mimics a specific daemon
 * optimizer bug and submits it via BPF_PROG_REJIT.  The kernel verifier
 * MUST reject every submission.  A PASS means the verifier correctly
 * blocked the bad bytecode.
 *
 * T1: scalar replacing map_value  (const_prop lost BPF_PSEUDO_MAP_FD)
 * T2: unreachable insn after dead-code elimination
 * T3: invalid call destination    (branch fixup miscalculation)
 * T4: BPF_PSEUDO_MAP_VALUE on unsupported map type (PERF_EVENT_ARRAY)
 *
 * Build:
 *   make -C tests/unittest build/rejit_verifier_negative_tests
 *
 * Run (requires root, BpfReJIT-enabled kernel):
 *   sudo tests/unittest/build/rejit_verifier_negative_tests
 */
#define _GNU_SOURCE
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

static int g_pass;
static int g_fail;

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s (errno=%d: %s)\n", \
		name, reason, errno, strerror(errno)); \
	g_fail++; \
} while (0)

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

/* Load a simple XDP program.  Returns prog_fd or -1. */
static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			  char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type    = BPF_PROG_TYPE_XDP;
	attr.insn_cnt     = insn_cnt;
	attr.insns        = ptr_to_u64(insns);
	attr.license      = ptr_to_u64(license);
	attr.log_level    = 1;
	attr.log_buf      = ptr_to_u64(log_buf);
	attr.log_size     = log_buf_sz;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

/* REJIT an existing prog.  Returns 0 on success, -1 on error. */
static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns    = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_buf  = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

/* REJIT with fd_array support.  Returns 0 on success, -1 on error. */
static int rejit_prog_with_fd_array(int prog_fd,
				    const struct bpf_insn *insns,
				    __u32 insn_cnt,
				    const int *fd_array, __u32 fd_array_cnt,
				    char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd      = prog_fd;
	attr.rejit.insn_cnt     = insn_cnt;
	attr.rejit.insns        = ptr_to_u64(insns);
	attr.rejit.log_level    = 1;
	attr.rejit.log_buf      = ptr_to_u64(log_buf);
	attr.rejit.log_size     = log_buf_sz;
	attr.rejit.fd_array     = ptr_to_u64(fd_array);
	attr.rejit.fd_array_cnt = fd_array_cnt;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

/* Execute an XDP program via bpf_prog_test_run. Returns 0 on success. */
static int test_run_xdp(int prog_fd, __u32 *retval)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd      = prog_fd;
	attr.test.data_in      = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat       = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* Create a BPF_MAP_TYPE_PERF_EVENT_ARRAY map.  Returns map fd or -1. */
static int create_perf_event_array_map(__u32 max_entries)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type    = BPF_MAP_TYPE_PERF_EVENT_ARRAY;
	attr.key_size    = 4;
	attr.value_size  = 4;
	attr.max_entries = max_entries;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

/* ----- Canonical "good" programs ----------------------------------- */

/* Returns XDP_PASS (2) */
static const struct bpf_insn prog_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Helper: load the canonical XDP_PASS program, return fd or -1 */
static int load_good_prog(void)
{
	char log_buf[65536];

	memset(log_buf, 0, sizeof(log_buf));
	return load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
			     log_buf, sizeof(log_buf));
}

/* Helper: verify the given prog fd returns expected_retval via test_run */
static int verify_retval(int prog_fd, __u32 expected)
{
	__u32 retval = 0;

	if (test_run_xdp(prog_fd, &retval) < 0)
		return -1;
	if (retval != expected)
		return -1;
	return 0;
}

/*
 * Generic negative-test runner.
 *  1. Load a good program, verify it returns XDP_PASS.
 *  2. Attempt REJIT with the given bad bytecode.
 *  3. Assert REJIT fails (returns < 0).
 *  4. Assert the original program still returns XDP_PASS.
 */
static int run_negative_test(const char *name,
			     const struct bpf_insn *bad_insns,
			     __u32 bad_insn_cnt)
{
	char log_buf[65536];
	int prog_fd, ret;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Pre-REJIT: original works */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	/* Attempt REJIT with bad bytecode -- should fail */
	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(prog_fd, bad_insns, bad_insn_cnt,
			 log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT unexpectedly succeeded");
		close(prog_fd);
		return 1;
	}

	/* Post-REJIT: original must still work identically */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "original program changed after failed REJIT!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/*
 * Negative-test runner with fd_array support.
 * Same pattern as run_negative_test but passes fd_array to REJIT.
 */
static int run_negative_test_fd_array(const char *name,
				      const struct bpf_insn *bad_insns,
				      __u32 bad_insn_cnt,
				      const int *fd_array,
				      __u32 fd_array_cnt)
{
	char log_buf[65536];
	int prog_fd, ret;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog_with_fd_array(prog_fd, bad_insns, bad_insn_cnt,
				       fd_array, fd_array_cnt,
				       log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT unexpectedly succeeded");
		close(prog_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "original program changed after failed REJIT!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  T1: scalar replacing map_value must be rejected                   */
/* ================================================================== */
/*
 * Daemon bug: const_prop replaced LD_IMM64 src=BPF_PSEUDO_MAP_FD (1)
 * with src=0 (plain scalar), destroying the map_value pointer type.
 * The verifier must reject the resulting program because a subsequent
 * helper call receives a scalar where it expects a map pointer/value.
 *
 * We construct:
 *   r1 = <LD_IMM64 with src=0, imm=0x12345678>  (plain scalar, NOT map ref)
 *   r2 = 0
 *   r3 = 8
 *   call bpf_probe_read_kernel (#113) -- expects (dst=PTR, size, src=PTR)
 *                                        but r1 is a scalar
 *   r0 = XDP_PASS
 *   exit
 *
 * Note: bpf_probe_read_kernel arg1 expects a pointer (stack, map_value, etc).
 * Passing a plain scalar will cause the verifier to reject.
 */
static int test_t1_scalar_replaces_map_value(void)
{
	const struct bpf_insn bad[] = {
		/* r1 = 0x12345678 via LD_IMM64 with src_reg=0 (plain scalar) */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_1, .src_reg = 0,
		  .off = 0, .imm = 0x12345678 },
		{ .code = 0, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 0 },  /* LD_IMM64 continuation */

		/* r2 = r10 (fp) */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X,
		  .dst_reg = BPF_REG_2, .src_reg = BPF_REG_10 },
		/* r2 -= 8 => stack pointer */
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K,
		  .dst_reg = BPF_REG_2, .imm = -8 },
		/* *(u64 *)(r10 - 8) = 0 (init stack) */
		{ .code = BPF_ST | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_10, .off = -8, .imm = 0 },

		/* r3 = 8 (size) */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_3, .imm = 8 },

		/* call bpf_probe_read_kernel(r1=scalar, r2=stack, r3=8)
		 * r1 should be PTR but is scalar => rejected */
		{ .code = BPF_JMP | BPF_CALL, .imm = 113 },

		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	return run_negative_test("T1_scalar_replaces_map_value",
				 bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T2: unreachable insn must be rejected                             */
/* ================================================================== */
/*
 * Daemon bug: const_prop folded a branch, DCE removed the dead block
 * body but left unreachable instructions (or the block boundary was
 * off-by-one).  The verifier rejects programs with instructions that
 * are never visited during abstract interpretation.
 *
 * We construct:
 *   r0 = XDP_PASS
 *   JA +2            (skip next 2 insns)
 *   r1 = 0xdead      (unreachable)
 *   r2 = 0xbeef      (unreachable)
 *   exit
 *
 * The verifier walks all reachable paths.  Instructions at offset 2
 * and 3 are never reached, which the verifier must flag.
 */
static int test_t2_unreachable_insn(void)
{
	const struct bpf_insn bad[] = {
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* JA +2 => skip 2 insns to exit */
		{ .code = BPF_JMP | BPF_JA, .off = 2 },
		/* dead insn 1 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_1, .imm = 0xdead },
		/* dead insn 2 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_2, .imm = 0xbeef },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	return run_negative_test("T2_unreachable_insn",
				 bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T3: invalid call destination must be rejected                     */
/* ================================================================== */
/*
 * Daemon bug: branch fixup miscalculated the BPF_CALL target after
 * instruction insertion/deletion, producing a call to a non-existent
 * helper function.
 *
 * We construct:
 *   call helper 99999 (does not exist)
 *   r0 = XDP_PASS
 *   exit
 *
 * The verifier must reject the unknown helper ID.
 */
static int test_t3_invalid_call_dest(void)
{
	const struct bpf_insn bad[] = {
		/* call helper 99999 -- nonexistent */
		{ .code = BPF_JMP | BPF_CALL, .imm = 99999 },
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	return run_negative_test("T3_invalid_call_dest",
				 bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T4: BPF_PSEUDO_MAP_VALUE on PERF_EVENT_ARRAY must be rejected     */
/* ================================================================== */
/*
 * Daemon bug: map_inline optimization generated BPF_PSEUDO_MAP_VALUE
 * (direct value access) for a map type that does not support it
 * (e.g. PERF_EVENT_ARRAY).  Only ARRAY and certain other map types
 * support direct value access.
 *
 * We construct:
 *   LD_IMM64 r0, src=BPF_PSEUDO_MAP_IDX_VALUE, imm=fd_array_idx=0
 *     (second half: imm=0, i.e. offset 0 into the "value")
 *   r0 = XDP_PASS
 *   exit
 *
 * fd_array[0] = perf_event_array map fd
 *
 * The verifier must reject because PERF_EVENT_ARRAY does not support
 * direct value access (map_direct_value_addr is NULL for this type).
 */
static int test_t4_pseudo_map_value_unsupported_map(void)
{
	const char *name = "T4_pseudo_map_value_unsupported_map";
	int map_fd;
	int fd_array[1];
	int ret;

	/* Create a PERF_EVENT_ARRAY map -- does not support direct value */
	map_fd = create_perf_event_array_map(1);
	if (map_fd < 0) {
		TEST_FAIL(name, "cannot create PERF_EVENT_ARRAY map");
		return 1;
	}
	fd_array[0] = map_fd;

	/*
	 * LD_IMM64 with src=BPF_PSEUDO_MAP_IDX_VALUE (6), imm=0 (fd_array index 0)
	 * Second insn: imm=0 (offset 0 into the map value)
	 *
	 * For a map that supports direct value (e.g. ARRAY with max_entries=1),
	 * this would produce a PTR_TO_MAP_VALUE.  For PERF_EVENT_ARRAY it must
	 * be rejected since map_direct_value_addr is not implemented.
	 */
	const struct bpf_insn bad[] = {
		/* LD_IMM64: r1 = &map_value[0] (attempted) */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_1, .src_reg = BPF_PSEUDO_MAP_IDX_VALUE,
		  .off = 0, .imm = 0 },
		{ .code = 0, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 0 },  /* LD_IMM64 continuation: offset 0 */

		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	ret = run_negative_test_fd_array(name, bad, ARRAY_SIZE(bad),
					 fd_array, ARRAY_SIZE(fd_array));

	close(map_fd);
	return ret;
}

/* ================================================================== */
/*  Main                                                              */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT Verifier Negative Tests (Daemon Bug Regression) ===\n\n");

	test_t1_scalar_replaces_map_value();
	test_t2_unreachable_insn();
	test_t3_invalid_call_dest();
	test_t4_pseudo_map_value_unsupported_map();

	printf("\n=== Summary: %d passed, %d failed ===\n", g_pass, g_fail);

	if (g_fail) {
		fprintf(stderr, "SOME TESTS FAILED\n");
		return 1;
	}

	printf("ALL TESTS PASSED\n");
	return 0;
}
