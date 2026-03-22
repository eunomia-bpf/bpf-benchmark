// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Safety & Correctness Test Suite
 *
 * Validates the core safety claim (Insight 3): the kernel verifier provides
 * identical safety guarantees for REJIT submissions as for initial program
 * loads. A failed REJIT must never affect the running program.
 *
 * Negative tests (10+):  malicious/invalid bytecode rejected via REJIT
 * Correctness tests (5+): semantic-preserving transforms, identity, rollback
 *
 * Build (from repo root):
 *   clang -O2 -Wall -Wno-\#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -o tests/rejit_safety_tests tests/rejit_safety_tests.c -lpthread
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_safety_tests
 */
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

/* BPF_MAXINSNS from bpf_common.h is only 4096 (cBPF). The eBPF verifier
 * allows up to 1M instructions for privileged loaders.  We use a much
 * smaller oversized value that still exceeds the 4096 cBPF limit. */
#ifndef BPF_MAXINSNS
#define BPF_MAXINSNS 4096
#endif

static int g_pass;
static int g_fail;

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

/* Load a simple XDP program. Returns prog_fd or -1. */
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

/* REJIT an existing prog.  Returns 0 on success, -1 on error (check errno). */
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

/* Execute an XDP program via bpf_prog_test_run. Returns 0 on success. */
static int test_run_xdp(int prog_fd, __u32 *retval)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd     = prog_fd;
	attr.test.data_in     = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat      = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* Get bpf_prog_info for a prog fd. Returns 0 on success. */
static int get_prog_info(int prog_fd, struct bpf_prog_info *info,
			 __u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd   = prog_fd;
	attr.info.info      = ptr_to_u64(info);
	attr.info.info_len  = *info_len;

	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	*info_len = attr.info.info_len;
	return 0;
}

/* ----- Canonical "good" programs ----------------------------------- */

/* Returns XDP_PASS (2) */
static const struct bpf_insn prog_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_DROP (1) */
static const struct bpf_insn prog_xdp_drop[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_TX (3) via r0 = 1 + 2 (4 insns) */
static const struct bpf_insn prog_xdp_tx_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1, .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0, .src_reg = BPF_REG_1 },
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

/* ------------------------------------------------------------------ */
/*  Test framework macros                                             */
/* ------------------------------------------------------------------ */

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

/* ================================================================== */
/*  PART A: Negative Tests -- REJIT must reject invalid bytecode      */
/* ================================================================== */

/*
 * Helper for negative tests.  Pattern:
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
	/* errno should be EINVAL, EACCES, or similar -- we just check ret<0 */

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

/* N01: Empty program (insn_cnt = 0) */
static int test_neg_empty_program(void)
{
	/* No instructions at all */
	return run_negative_test("N01_empty_program", NULL, 0);
}

/* N02: Unknown opcode -- all-zero instruction has opcode 0x00 which is
 * BPF_LD | BPF_W | BPF_IMM in cBPF, but in eBPF context an all-zero
 * instruction with no exit will fail verification. */
static int test_neg_unknown_opcode(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = 0xff, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N02_unknown_opcode", bad, ARRAY_SIZE(bad));
}

/* N03: No BPF_EXIT -- program with only an ALU instruction, no exit */
static int test_neg_no_exit(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 1 },
	};
	return run_negative_test("N03_no_exit", bad, ARRAY_SIZE(bad));
}

/* N04: Uninitialized R0 -- just BPF_EXIT without setting R0 */
static int test_neg_uninit_r0(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N04_uninit_r0", bad, ARRAY_SIZE(bad));
}

/* N05: Out-of-bounds stack access -- store to offset -520 (beyond 512 limit) */
static int test_neg_oob_stack(void)
{
	static const struct bpf_insn bad[] = {
		/* r0 = 0 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		/* *(u64 *)(r10 - 520) = r0  -- stack overflow */
		{ .code = BPF_STX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_10, .src_reg = BPF_REG_0, .off = -520 },
		/* r0 = 0 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N05_oob_stack", bad, ARRAY_SIZE(bad));
}

/* N06: Backward jump (infinite loop) -- JA -1 creates an infinite loop */
static int test_neg_backward_jump(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		/* JA -1: jump back to self */
		{ .code = BPF_JMP | BPF_JA, .off = -1 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N06_backward_jump", bad, ARRAY_SIZE(bad));
}

/* N07: Illegal helper call -- call helper 0xFFFF (nonexistent) */
static int test_neg_illegal_helper(void)
{
	static const struct bpf_insn bad[] = {
		/* call unknown helper */
		{ .code = BPF_JMP | BPF_CALL, .imm = 0xFFFF },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N07_illegal_helper", bad, ARRAY_SIZE(bad));
}

/* N08: Oversized program -- submit BPF_MAXINSNS + 1 instructions
 * (all r0=0 NOPs + exit). The verifier should reject due to size. */
static int test_neg_oversized_program(void)
{
	const char *name = "N08_oversized_program";
	/* Allocate (BPF_MAXINSNS + 2) instructions: 4097 MOV + 1 EXIT */
	const __u32 cnt = BPF_MAXINSNS + 2;
	struct bpf_insn *bad;
	__u32 i;
	int ret;

	bad = calloc(cnt, sizeof(struct bpf_insn));
	if (!bad) {
		TEST_FAIL(name, "malloc failed");
		return 1;
	}
	for (i = 0; i < cnt - 1; i++) {
		bad[i].code    = BPF_ALU64 | BPF_MOV | BPF_K;
		bad[i].dst_reg = BPF_REG_0;
		bad[i].imm     = 0;
	}
	bad[cnt - 1].code = BPF_JMP | BPF_EXIT;

	ret = run_negative_test(name, bad, cnt);
	free(bad);
	return ret;
}

/* N09: Invalid register (R11+) -- use reserved register field */
static int test_neg_invalid_register(void)
{
	static const struct bpf_insn bad[] = {
		/* dst_reg = 15 (only 0-10 valid) */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 15, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N09_invalid_register", bad, ARRAY_SIZE(bad));
}

/* N10: Invalid prog_fd -- REJIT with fd = -1 */
static int test_neg_bad_prog_fd(void)
{
	const char *name = "N10_bad_prog_fd";
	char log_buf[65536];
	int ret;

	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(-1, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
			 log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with fd=-1 unexpectedly succeeded");
		return 1;
	}
	/* Should get EBADF */
	if (errno != EBADF && errno != EINVAL) {
		char buf[128];
		snprintf(buf, sizeof(buf), "unexpected errno %d (%s), expected EBADF",
			 errno, strerror(errno));
		TEST_FAIL(name, buf);
		return 1;
	}

	TEST_PASS(name);
	return 0;
}

/* N11: Non-BPF fd -- REJIT with fd pointing to a regular file */
static int test_neg_non_bpf_fd(void)
{
	const char *name = "N11_non_bpf_fd";
	char log_buf[65536];
	int fd, ret;

	fd = open("/dev/null", O_RDONLY);
	if (fd < 0) {
		TEST_FAIL(name, "cannot open /dev/null");
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
			 log_buf, sizeof(log_buf));
	close(fd);

	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with non-BPF fd unexpectedly succeeded");
		return 1;
	}

	TEST_PASS(name);
	return 0;
}

/* N12: Truncated LD_IMM64 -- odd insn_cnt leaving the 16-byte LD_IMM64 split */
static int test_neg_truncated_ld_imm64(void)
{
	/* LD_IMM64 needs 2 insns (16 bytes). Provide only the first half. */
	static const struct bpf_insn bad[] = {
		/* LD_IMM64 first half: code = BPF_LD | BPF_DW | BPF_IMM */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_0, .src_reg = 0, .off = 0, .imm = 42 },
		/* Missing second half! Instead we put exit -- verifier should
		 * reject because the LD_IMM64 pair is incomplete. */
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N12_truncated_ld_imm64", bad, ARRAY_SIZE(bad));
}

/* N13: Privilege escalation -- XDP program calling bpf_probe_read_kernel
 * (helper #113), which is not allowed for XDP prog type */
static int test_neg_wrong_helper_for_prog_type(void)
{
	static const struct bpf_insn bad[] = {
		/* Set up arguments for bpf_probe_read_kernel(dst, size, src):
		 * r1 = r10 - 8 (dst on stack)
		 * r2 = 8 (size)
		 * r3 = 0 (src = NULL, would fail anyway)
		 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X,
		  .dst_reg = BPF_REG_1, .src_reg = BPF_REG_10 },
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K,
		  .dst_reg = BPF_REG_1, .imm = -8 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_2, .imm = 8 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_3, .imm = 0 },
		/* call bpf_probe_read_kernel (#113) -- not allowed for XDP */
		{ .code = BPF_JMP | BPF_CALL, .imm = 113 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N13_wrong_helper_for_prog_type",
				 bad, ARRAY_SIZE(bad));
}

/* N14: Unprivileged REJIT -- fork a child, drop to nobody, try REJIT.
 * Expects EPERM. */
static int test_neg_unprivileged_rejit(void)
{
	const char *name = "N14_unprivileged_rejit";
	int prog_fd;
	pid_t pid;
	int status;

	/* Load a good program as root first */
	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	pid = fork();
	if (pid < 0) {
		TEST_FAIL(name, "fork failed");
		close(prog_fd);
		return 1;
	}

	if (pid == 0) {
		/* Child: drop privileges to nobody (uid 65534) */
		char log_buf[65536];
		int ret;

		if (setresuid(65534, 65534, 65534) < 0) {
			fprintf(stderr, "  %s: setresuid failed: %s\n",
				name, strerror(errno));
			_exit(2);
		}

		memset(log_buf, 0, sizeof(log_buf));
		ret = rejit_prog(prog_fd, prog_xdp_drop,
				 ARRAY_SIZE(prog_xdp_drop),
				 log_buf, sizeof(log_buf));
		if (ret >= 0) {
			fprintf(stderr, "  %s: unprivileged REJIT succeeded!\n",
				name);
			_exit(1);
		}
		if (errno != EPERM && errno != EACCES) {
			fprintf(stderr, "  %s: unexpected errno %d (%s)\n",
				name, errno, strerror(errno));
			_exit(1);
		}
		/* Good -- REJIT was rejected */
		_exit(0);
	}

	/* Parent: wait for child */
	waitpid(pid, &status, 0);
	close(prog_fd);

	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		TEST_PASS(name);
		return 0;
	} else if (WIFEXITED(status) && WEXITSTATUS(status) == 2) {
		/* Could not setresuid -- likely not root. Skip. */
		printf("  SKIP  %s (cannot drop privileges)\n", name);
		return 0;
	} else {
		TEST_FAIL(name, "child reported failure");
		return 1;
	}
}

/* N15: REJIT failure does not change original program
 * (explicit multi-step verification) */
static int test_neg_original_survives_failed_rejit(void)
{
	const char *name = "N15_original_survives_failed_rejit";
	char log_buf[65536];
	__u32 retval;
	int prog_fd, i;

	/* Bad bytecode: backward jump (infinite loop) */
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_JA, .off = -1 },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Run 5 times before REJIT to confirm baseline */
	for (i = 0; i < 5; i++) {
		if (verify_retval(prog_fd, XDP_PASS) < 0) {
			TEST_FAIL(name, "pre-rejit verification failed");
			close(prog_fd);
			return 1;
		}
	}

	/* Attempt 3 different bad REJITs -- all should fail */
	for (i = 0; i < 3; i++) {
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, bad, ARRAY_SIZE(bad),
			       log_buf, sizeof(log_buf)) >= 0) {
			TEST_FAIL(name, "bad REJIT unexpectedly succeeded");
			close(prog_fd);
			return 1;
		}
	}

	/* Run 5 times after failed REJITs -- must still return XDP_PASS */
	for (i = 0; i < 5; i++) {
		retval = 0;
		if (test_run_xdp(prog_fd, &retval) < 0) {
			TEST_FAIL(name, "post-rejit run failed");
			close(prog_fd);
			return 1;
		}
		if (retval != XDP_PASS) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "post-rejit retval %u != XDP_PASS on iteration %d",
				 retval, i);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  PART B: Correctness Verification Tests                            */
/* ================================================================== */

/* C01: Identity transform -- REJIT with the exact same bytecode */
static int test_cor_identity_transform(void)
{
	const char *name = "C01_identity_transform";
	char log_buf[65536];
	int prog_fd;

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

	/* REJIT with the identical bytecode */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "identity REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* Must still return XDP_PASS */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "post-identity-rejit run returned wrong value");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C02: Semantic-preserving transform -- insert a NOP (r0 = r0 + 0) before exit */
static int test_cor_nop_insertion(void)
{
	const char *name = "C02_nop_insertion";
	char log_buf[65536];
	int prog_fd;

	/* Original: r0 = XDP_PASS; exit  (2 insns) */
	/* Replacement: r0 = XDP_PASS; r0 += 0; exit  (3 insns, same semantics) */
	static const struct bpf_insn prog_with_nop[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* NOP: r0 += 0 */
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};

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
	if (rejit_prog(prog_fd, prog_with_nop, ARRAY_SIZE(prog_with_nop),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "nop-insertion REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "post-nop-rejit run returned wrong value");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C03: REJIT preserves prog_info metadata (type, id remain consistent) */
static int test_cor_prog_info_after_rejit(void)
{
	const char *name = "C03_prog_info_after_rejit";
	char log_buf[65536];
	struct bpf_prog_info info_before, info_after;
	__u32 info_len;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Snapshot info before REJIT */
	memset(&info_before, 0, sizeof(info_before));
	info_len = sizeof(info_before);
	if (get_prog_info(prog_fd, &info_before, &info_len) < 0) {
		TEST_FAIL(name, "get_info pre-rejit failed");
		close(prog_fd);
		return 1;
	}

	/* REJIT to a different-length program (4 insns, returns XDP_TX) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_TX) < 0) {
		TEST_FAIL(name, "post-rejit retval wrong");
		close(prog_fd);
		return 1;
	}

	/* Snapshot info after REJIT */
	memset(&info_after, 0, sizeof(info_after));
	info_len = sizeof(info_after);
	if (get_prog_info(prog_fd, &info_after, &info_len) < 0) {
		TEST_FAIL(name, "get_info post-rejit failed");
		close(prog_fd);
		return 1;
	}

	/* prog_type must remain XDP */
	if (info_after.type != info_before.type) {
		char buf[128];
		snprintf(buf, sizeof(buf), "prog_type changed: %u -> %u",
			 info_before.type, info_after.type);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* prog ID must remain the same (in-place update) */
	if (info_after.id != info_before.id) {
		char buf[128];
		snprintf(buf, sizeof(buf), "prog_id changed: %u -> %u",
			 info_before.id, info_after.id);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* JIT should still be active */
	if (!info_after.jited_prog_len) {
		TEST_FAIL(name, "program no longer JIT'ed after REJIT");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C04: Multiple consecutive REJITs -- REJIT the same prog 3 times */
static int test_cor_multiple_rejits(void)
{
	const char *name = "C04_multiple_rejits";
	char log_buf[65536];
	int prog_fd, i;

	struct {
		const struct bpf_insn *insns;
		__u32 cnt;
		__u32 expected;
	} steps[] = {
		{ prog_xdp_drop,    ARRAY_SIZE(prog_xdp_drop),    XDP_DROP },
		{ prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long), XDP_TX },
		{ prog_xdp_pass,    ARRAY_SIZE(prog_xdp_pass),    XDP_PASS },
	};

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "initial run failed");
		close(prog_fd);
		return 1;
	}

	for (i = 0; i < 3; i++) {
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, steps[i].insns, steps[i].cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			char buf[256];
			snprintf(buf, sizeof(buf), "REJIT step %d failed: %s",
				 i, strerror(errno));
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
		if (verify_retval(prog_fd, steps[i].expected) < 0) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "step %d: expected %u, got different", i,
				 steps[i].expected);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C05: REJIT round-trip -- REJIT to DROP, then REJIT back to PASS,
 * verify result matches the original exactly */
static int test_cor_rejit_roundtrip(void)
{
	const char *name = "C05_rejit_roundtrip";
	char log_buf[65536];
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Phase 1: verify original */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "phase 1 (original) failed");
		close(prog_fd);
		return 1;
	}

	/* Phase 2: REJIT to XDP_DROP */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "phase 2 REJIT->DROP failed");
		close(prog_fd);
		return 1;
	}
	if (verify_retval(prog_fd, XDP_DROP) < 0) {
		TEST_FAIL(name, "phase 2 run (DROP) wrong");
		close(prog_fd);
		return 1;
	}

	/* Phase 3: REJIT back to original (XDP_PASS) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "phase 3 REJIT->PASS failed");
		close(prog_fd);
		return 1;
	}
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "phase 3 run (PASS) wrong -- roundtrip failed!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  main                                                               */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT Safety & Correctness Test Suite ===\n\n");

	printf("--- Negative Tests (REJIT rejects invalid bytecode) ---\n");
	test_neg_empty_program();                  /* N01 */
	test_neg_unknown_opcode();                 /* N02 */
	test_neg_no_exit();                        /* N03 */
	test_neg_uninit_r0();                      /* N04 */
	test_neg_oob_stack();                      /* N05 */
	test_neg_backward_jump();                  /* N06 */
	test_neg_illegal_helper();                 /* N07 */
	test_neg_oversized_program();              /* N08 */
	test_neg_invalid_register();               /* N09 */
	test_neg_bad_prog_fd();                    /* N10 */
	test_neg_non_bpf_fd();                     /* N11 */
	test_neg_truncated_ld_imm64();             /* N12 */
	test_neg_wrong_helper_for_prog_type();     /* N13 */
	test_neg_unprivileged_rejit();             /* N14 */
	test_neg_original_survives_failed_rejit(); /* N15 */

	printf("\n--- Correctness Verification Tests ---\n");
	test_cor_identity_transform();             /* C01 */
	test_cor_nop_insertion();                  /* C02 */
	test_cor_prog_info_after_rejit();          /* C03 */
	test_cor_multiple_rejits();                /* C04 */
	test_cor_rejit_roundtrip();                /* C05 */

	printf("\n=== Summary: %d passed, %d failed ===\n", g_pass, g_fail);

	if (g_fail) {
		fprintf(stderr, "SOME TESTS FAILED\n");
		return 1;
	}

	printf("ALL TESTS PASSED\n");
	return 0;
}
