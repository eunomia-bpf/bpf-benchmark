// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Adversarial Bytecode Tests
 *
 * Targeted adversarial patterns that a compromised daemon might attempt.
 * Each test constructs a specific verifier-rejected pattern and verifies:
 *   (1) REJIT rejects it
 *   (2) The original program remains unchanged
 *
 * This directly proves the OSDI paper's Insight 3 (fail-safe): the kernel
 * verifier provides identical safety guarantees for REJIT as for initial load.
 *
 * Test categories:
 *   A01-A04: Memory safety violations
 *   A05-A07: Control flow violations
 *   A08-A10: Type safety violations
 *   A11-A13: Privilege escalation attempts
 *   A14-A16: Resource exhaustion / abuse
 *   A17-A20: Compound / creative attacks
 *
 * Usage: sudo ./adversarial_rejit
 */
#include "common.h"
#include <fcntl.h>
#include <sys/wait.h>

/* ================================================================== */
/*  A01-A04: Memory Safety Violations                                  */
/* ================================================================== */

/* A01: OOB map access -- read from map pointer + out-of-bounds offset.
 * Simulated by dereferencing r1 (ctx ptr) at a large offset. */
static int test_a01_oob_ctx_access(void)
{
	static const struct bpf_insn bad[] = {
		/* r2 = *(u64*)(r1 + 4096) -- way beyond XDP ctx */
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_2, .src_reg = BPF_REG_1, .off = 4096 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A01_oob_ctx_access", bad, ARRAY_SIZE(bad));
}

/* A02: Stack overflow -- write beyond the 512-byte stack limit */
static int test_a02_stack_overflow(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		/* *(u64*)(r10 - 520) = r0  -- beyond 512 byte limit */
		{ .code = BPF_STX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_10, .src_reg = BPF_REG_0, .off = -520 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A02_stack_overflow", bad, ARRAY_SIZE(bad));
}

/* A03: Read uninitialized stack memory */
static int test_a03_uninit_stack_read(void)
{
	static const struct bpf_insn bad[] = {
		/* r0 = *(u64*)(r10 - 8) -- never written */
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_10, .off = -8 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A03_uninit_stack_read", bad, ARRAY_SIZE(bad));
}

/* A04: NULL pointer dereference -- use r0 (=0) as pointer */
static int test_a04_null_ptr_deref(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_2, .imm = 0 },
		/* r0 = *(u64*)(r2 + 0) -- r2 is scalar 0, not pointer */
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_2, .off = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A04_null_ptr_deref", bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  A05-A07: Control Flow Violations                                   */
/* ================================================================== */

/* A05: Infinite loop -- backward unconditional jump */
static int test_a05_infinite_loop(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		/* JA -1: infinite loop */
		{ .code = BPF_JMP | BPF_JA, .off = -1 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A05_infinite_loop", bad, ARRAY_SIZE(bad));
}

/* A06: Jump out of bounds -- forward jump past end of program */
static int test_a06_jump_oob(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		/* JA +100: way past end */
		{ .code = BPF_JMP | BPF_JA, .off = 100 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A06_jump_oob", bad, ARRAY_SIZE(bad));
}

/* A07: Unreachable code after unconditional jump (dead code that looks
 * like it would do something bad) */
static int test_a07_unreachable_with_bad_code(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* JA +2: skip next 2 insns */
		{ .code = BPF_JMP | BPF_JA, .off = 2 },
		/* These are unreachable -- verifier still rejects invalid opcodes */
		{ .code = 0xff },
		{ .code = 0xfe },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A07_unreachable_bad_code", bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  A08-A10: Type Safety Violations                                    */
/* ================================================================== */

/* A08: Uninitialized register use -- use r5 (never set) in ALU */
static int test_a08_uninit_register(void)
{
	static const struct bpf_insn bad[] = {
		/* r0 = r5 -- r5 never initialized */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_5 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A08_uninit_register", bad, ARRAY_SIZE(bad));
}

/* A09: Invalid register index (R15) -- only R0-R10 are valid */
static int test_a09_invalid_register(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = 15, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A09_invalid_register", bad, ARRAY_SIZE(bad));
}

/* A10: Scalar used as pointer -- try to dereference a known scalar */
static int test_a10_scalar_as_pointer(void)
{
	static const struct bpf_insn bad[] = {
		/* r2 = 0x41414141 (scalar) */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_2, .imm = 0x41414141 },
		/* r0 = *(u64*)(r2 + 0) -- scalar used as ptr */
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_2, .off = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A10_scalar_as_pointer", bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  A11-A13: Privilege Escalation Attempts                             */
/* ================================================================== */

/* A11: Call non-existent helper */
static int test_a11_bad_helper_call(void)
{
	static const struct bpf_insn bad[] = {
		/* call helper 0xFFFF (nonexistent) */
		{ .code = BPF_JMP | BPF_CALL, .imm = 0xFFFF },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A11_bad_helper_call", bad, ARRAY_SIZE(bad));
}

/* A12: Call wrong-type helper -- bpf_override_return is kprobe-only */
static int test_a12_wrong_type_helper(void)
{
	static const struct bpf_insn bad[] = {
		/* call bpf_override_return (#58) -- kprobe-only, invalid for XDP */
		{ .code = BPF_JMP | BPF_CALL, .imm = 58 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A12_wrong_type_helper", bad, ARRAY_SIZE(bad));
}

/* A13: Pointer leak to map value -- store ctx pointer to stack,
 * then try to treat it as map value */
static int test_a13_pointer_leak(void)
{
	static const struct bpf_insn bad[] = {
		/* *(u64*)(r10 - 8) = r1  -- leak ctx ptr to stack */
		{ .code = BPF_STX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_10, .src_reg = BPF_REG_1, .off = -8 },
		/* r2 = *(u64*)(r10 - 8) -- load it back */
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_2, .src_reg = BPF_REG_10, .off = -8 },
		/* r0 = r2  -- try to return the pointer as scalar */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_2 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A13_pointer_leak", bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  A14-A16: Resource Exhaustion / Abuse                               */
/* ================================================================== */

/* A14: Oversized program -- exceed BPF_MAXINSNS (4096 for cBPF limit check) */
static int test_a14_oversized_program(void)
{
	const char *name = "A14_oversized_program";
	const __u32 cnt = 4098;  /* BPF_MAXINSNS + 2 */
	struct bpf_insn *bad;
	__u32 i;
	int ret;

	bad = calloc(cnt, sizeof(struct bpf_insn));
	if (!bad) {
		TEST_FAIL(name, "malloc failed");
		return 1;
	}
	for (i = 0; i < cnt - 1; i++) {
		bad[i].code = BPF_ALU64 | BPF_MOV | BPF_K;
		bad[i].dst_reg = BPF_REG_0;
		bad[i].imm = 0;
	}
	bad[cnt - 1].code = BPF_JMP | BPF_EXIT;

	ret = run_negative_test(name, bad, cnt);
	free(bad);
	return ret;
}

/* A15: Illegal opcode */
static int test_a15_illegal_opcode(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = 0xff, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A15_illegal_opcode", bad, ARRAY_SIZE(bad));
}

/* A16: Empty program (0 instructions) */
static int test_a16_empty_program(void)
{
	return run_negative_test("A16_empty_program", NULL, 0);
}

/* ================================================================== */
/*  A17-A20: Compound / Creative Attacks                               */
/* ================================================================== */

/* A17: Truncated LD_IMM64 -- provide only first half of 16-byte insn */
static int test_a17_truncated_ld_imm64(void)
{
	static const struct bpf_insn bad[] = {
		/* LD_IMM64 first half only */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_0, .src_reg = 0, .off = 0, .imm = 42 },
		/* This should be the second half but is EXIT */
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A17_truncated_ld_imm64", bad, ARRAY_SIZE(bad));
}

/* A18: Write to read-only register R10 (frame pointer) */
static int test_a18_write_r10(void)
{
	static const struct bpf_insn bad[] = {
		/* r10 = 0 -- cannot write to R10 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_10, .imm = 0 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A18_write_r10", bad, ARRAY_SIZE(bad));
}

/* A19: Division by zero */
static int test_a19_div_by_zero(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 42 },
		/* r0 /= 0 */
		{ .code = BPF_ALU64 | BPF_DIV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("A19_div_by_zero", bad, ARRAY_SIZE(bad));
}

/* A20: Repeated failed REJITs -- ensure N consecutive bad REJITs don't
 * corrupt the original program */
static int test_a20_repeated_bad_rejits(void)
{
	const char *name = "A20_repeated_bad_rejits";
	char log_buf[65536];
	int prog_fd, i;

	/* Various bad bytecodes */
	static const struct bpf_insn bad_patterns[][3] = {
		/* Infinite loop */
		{
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 0 },
			{ .code = BPF_JMP | BPF_JA, .off = -1 },
			{ .code = BPF_JMP | BPF_EXIT },
		},
		/* Bad opcode */
		{
			{ .code = 0xff },
			{ .code = BPF_JMP | BPF_EXIT },
			{ .code = 0 },  /* padding */
		},
		/* Uninitialized R0 */
		{
			{ .code = BPF_JMP | BPF_EXIT },
			{ .code = 0 },  /* padding */
			{ .code = 0 },  /* padding */
		},
		/* Stack overflow */
		{
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 0 },
			{ .code = BPF_STX | BPF_MEM | BPF_DW,
			  .dst_reg = BPF_REG_10, .src_reg = BPF_REG_0,
			  .off = -600 },
			{ .code = BPF_JMP | BPF_EXIT },
		},
		/* Illegal helper */
		{
			{ .code = BPF_JMP | BPF_CALL, .imm = 0xFFFF },
			{ .code = BPF_JMP | BPF_EXIT },
			{ .code = 0 },  /* padding */
		},
	};

	prog_fd = neg_load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Verify original works */
	if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-test run failed");
		close(prog_fd);
		return 1;
	}

	/* Hammer with 50 bad REJITs (cycling through patterns) */
	for (i = 0; i < 50; i++) {
		int pat = i % ARRAY_SIZE(bad_patterns);
		__u32 cnt;

		/* Determine actual insn count (skip zero padding) */
		if (bad_patterns[pat][2].code != 0)
			cnt = 3;
		else if (bad_patterns[pat][1].code != 0)
			cnt = 2;
		else
			cnt = 1;

		memset(log_buf, 0, sizeof(log_buf));
		if (neg_rejit_prog(prog_fd, bad_patterns[pat], cnt,
				   log_buf, sizeof(log_buf)) >= 0) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "bad REJIT pattern %d unexpectedly succeeded at iteration %d",
				 pat, i);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	/* After 50 bad REJITs, verify original is still intact */
	for (i = 0; i < 10; i++) {
		if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "original corrupted after 50 bad REJITs (check %d)",
				 i);
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
/*  Differential correctness test                                      */
/* ================================================================== */

/*
 * D01: Load a computation program, run N times, REJIT with equivalent
 * program, run N more times, verify all results match.
 */
static int test_d01_differential_correctness(void)
{
	const char *name = "D01_differential_correctness";
	char log_buf[65536];
	int prog_fd, i;
	__u32 pre_results[20], post_results[20];
	__u32 retval;

	prog_fd = neg_load_xdp_prog(good_xdp_compute, ARRAY_SIZE(good_xdp_compute),
				     log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load compute prog");
		return 1;
	}

	/* Run 20 times before REJIT */
	for (i = 0; i < 20; i++) {
		retval = 0;
		if (neg_test_run_xdp(prog_fd, &retval) < 0) {
			TEST_FAIL(name, "pre-rejit run failed");
			close(prog_fd);
			return 1;
		}
		pre_results[i] = retval;
	}

	/* REJIT with an equivalent program (same semantics, different encoding):
	 * r0 = (42 * 3 + 7) & 0xFF = 133
	 * Encode as: r0 = 126; r0 += 7; r0 &= 0xFF; exit
	 */
	{
		static const struct bpf_insn equiv[] = {
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 126 },
			{ .code = BPF_ALU64 | BPF_ADD | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 7 },
			{ .code = BPF_ALU64 | BPF_AND | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 0xFF },
			{ .code = BPF_JMP | BPF_EXIT },
		};

		memset(log_buf, 0, sizeof(log_buf));
		if (neg_rejit_prog(prog_fd, equiv, ARRAY_SIZE(equiv),
				   log_buf, sizeof(log_buf)) < 0) {
			char buf[256];
			snprintf(buf, sizeof(buf), "REJIT with equiv prog failed: %s",
				 strerror(errno));
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	/* Run 20 times after REJIT */
	for (i = 0; i < 20; i++) {
		retval = 0;
		if (neg_test_run_xdp(prog_fd, &retval) < 0) {
			TEST_FAIL(name, "post-rejit run failed");
			close(prog_fd);
			return 1;
		}
		post_results[i] = retval;
	}

	/* Compare: all results must be GOOD_XDP_COMPUTE_RESULT */
	for (i = 0; i < 20; i++) {
		if (pre_results[i] != GOOD_XDP_COMPUTE_RESULT) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "pre-rejit[%d] = %u, expected %u",
				 i, pre_results[i], GOOD_XDP_COMPUTE_RESULT);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
		if (post_results[i] != GOOD_XDP_COMPUTE_RESULT) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "post-rejit[%d] = %u, expected %u",
				 i, post_results[i], GOOD_XDP_COMPUTE_RESULT);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/*
 * D02: Fail-safe differential -- try bad REJIT on a computation program
 * and verify results are identical before and after the failed attempt.
 */
static int test_d02_failsafe_differential(void)
{
	const char *name = "D02_failsafe_differential";
	char log_buf[65536];
	int prog_fd, i;
	__u32 retval;

	prog_fd = neg_load_xdp_prog(good_xdp_compute, ARRAY_SIZE(good_xdp_compute),
				     log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load compute prog");
		return 1;
	}

	/* Run 10 times, all must return 133 */
	for (i = 0; i < 10; i++) {
		retval = 0;
		if (neg_test_run_xdp(prog_fd, &retval) < 0 ||
		    retval != GOOD_XDP_COMPUTE_RESULT) {
			TEST_FAIL(name, "pre-rejit compute mismatch");
			close(prog_fd);
			return 1;
		}
	}

	/* Attempt bad REJIT (infinite loop) -- must fail */
	{
		static const struct bpf_insn bad[] = {
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
			  .dst_reg = BPF_REG_0, .imm = 0 },
			{ .code = BPF_JMP | BPF_JA, .off = -1 },
			{ .code = BPF_JMP | BPF_EXIT },
		};
		memset(log_buf, 0, sizeof(log_buf));
		if (neg_rejit_prog(prog_fd, bad, ARRAY_SIZE(bad),
				   log_buf, sizeof(log_buf)) >= 0) {
			TEST_FAIL(name, "bad REJIT unexpectedly succeeded");
			close(prog_fd);
			return 1;
		}
	}

	/* Run 10 more times -- must still return 133 */
	for (i = 0; i < 10; i++) {
		retval = 0;
		if (neg_test_run_xdp(prog_fd, &retval) < 0) {
			char buf[64];
			snprintf(buf, sizeof(buf), "post-rejit run %d failed", i);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
		if (retval != GOOD_XDP_COMPUTE_RESULT) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "post-rejit[%d] = %u, expected %u",
				 i, retval, GOOD_XDP_COMPUTE_RESULT);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/*
 * D03: Mixed good/bad REJIT sequence -- interleave valid REJITs with
 * invalid ones, verify behavior at every step.
 */
static int test_d03_mixed_good_bad_sequence(void)
{
	const char *name = "D03_mixed_good_bad_sequence";
	char log_buf[65536];
	int prog_fd;
	__u32 expected;

	/* Bad bytecodes */
	static const struct bpf_insn bad_loop[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_JA, .off = -1 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	static const struct bpf_insn bad_opcode[] = {
		{ .code = 0xff },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	prog_fd = neg_load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}
	expected = XDP_PASS;

	/* Step 1: verify initial */
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 1 failed");
		close(prog_fd);
		return 1;
	}

	/* Step 2: bad REJIT (loop) -- should fail */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, bad_loop, ARRAY_SIZE(bad_loop),
			   log_buf, sizeof(log_buf)) >= 0) {
		TEST_FAIL(name, "step 2 bad REJIT should have failed");
		close(prog_fd);
		return 1;
	}
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 2 original corrupted");
		close(prog_fd);
		return 1;
	}

	/* Step 3: good REJIT to XDP_DROP */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, good_xdp_drop, ARRAY_SIZE(good_xdp_drop),
			   log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "step 3 good REJIT failed");
		close(prog_fd);
		return 1;
	}
	expected = XDP_DROP;
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 3 retval wrong");
		close(prog_fd);
		return 1;
	}

	/* Step 4: bad REJIT (opcode) -- should fail, current remains DROP */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, bad_opcode, ARRAY_SIZE(bad_opcode),
			   log_buf, sizeof(log_buf)) >= 0) {
		TEST_FAIL(name, "step 4 bad REJIT should have failed");
		close(prog_fd);
		return 1;
	}
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 4 program corrupted");
		close(prog_fd);
		return 1;
	}

	/* Step 5: good REJIT to XDP_TX */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, good_xdp_tx, ARRAY_SIZE(good_xdp_tx),
			   log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "step 5 good REJIT failed");
		close(prog_fd);
		return 1;
	}
	expected = XDP_TX;
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 5 retval wrong");
		close(prog_fd);
		return 1;
	}

	/* Step 6: bad REJIT again */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, bad_loop, ARRAY_SIZE(bad_loop),
			   log_buf, sizeof(log_buf)) >= 0) {
		TEST_FAIL(name, "step 6 bad REJIT should have failed");
		close(prog_fd);
		return 1;
	}
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 6 program corrupted");
		close(prog_fd);
		return 1;
	}

	/* Step 7: good REJIT back to XDP_PASS */
	memset(log_buf, 0, sizeof(log_buf));
	if (neg_rejit_prog(prog_fd, good_xdp_pass, ARRAY_SIZE(good_xdp_pass),
			   log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "step 7 good REJIT failed");
		close(prog_fd);
		return 1;
	}
	expected = XDP_PASS;
	if (neg_verify_retval(prog_fd, expected) < 0) {
		TEST_FAIL(name, "step 7 roundtrip failed");
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
	printf("=== BpfReJIT Adversarial Bytecode Tests ===\n\n");

	printf("--- Memory Safety Violations ---\n");
	test_a01_oob_ctx_access();
	test_a02_stack_overflow();
	test_a03_uninit_stack_read();
	test_a04_null_ptr_deref();

	printf("\n--- Control Flow Violations ---\n");
	test_a05_infinite_loop();
	test_a06_jump_oob();
	test_a07_unreachable_with_bad_code();

	printf("\n--- Type Safety Violations ---\n");
	test_a08_uninit_register();
	test_a09_invalid_register();
	test_a10_scalar_as_pointer();

	printf("\n--- Privilege Escalation Attempts ---\n");
	test_a11_bad_helper_call();
	test_a12_wrong_type_helper();
	test_a13_pointer_leak();

	printf("\n--- Resource Exhaustion / Abuse ---\n");
	test_a14_oversized_program();
	test_a15_illegal_opcode();
	test_a16_empty_program();

	printf("\n--- Compound / Creative Attacks ---\n");
	test_a17_truncated_ld_imm64();
	test_a18_write_r10();
	test_a19_div_by_zero();
	test_a20_repeated_bad_rejits();

	printf("\n--- Differential Correctness ---\n");
	test_d01_differential_correctness();
	test_d02_failsafe_differential();
	test_d03_mixed_good_bad_sequence();

	printf("\n=== Summary: %d passed, %d failed, %d skipped ===\n",
	       g_pass, g_fail, g_skip);

	if (g_fail) {
		fprintf(stderr, "SOME TESTS FAILED\n");
		return 1;
	}

	printf("ALL TESTS PASSED\n");
	return 0;
}
