// SPDX-License-Identifier: GPL-2.0
/*
 * Shared helpers for BpfReJIT negative / adversarial tests.
 *
 * Provides: syscall wrappers, canonical good programs, test framework macros.
 */
#ifndef NEGATIVE_COMMON_H
#define NEGATIVE_COMMON_H

#define _GNU_SOURCE
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/*  Macros                                                            */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

/* ------------------------------------------------------------------ */
/*  Syscall wrappers                                                  */
/* ------------------------------------------------------------------ */

static inline int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr,
			   unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

/* Load an XDP program. Returns prog_fd or -1. */
static int neg_load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			      char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type = BPF_PROG_TYPE_XDP;
	attr.insn_cnt = insn_cnt;
	attr.insns = ptr_to_u64(insns);
	attr.license = ptr_to_u64(license);
	attr.log_level = 1;
	attr.log_buf = ptr_to_u64(log_buf);
	attr.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

/* REJIT an existing prog. Returns 0 on success, -1 on error. */
static int neg_rejit_prog(int prog_fd, const struct bpf_insn *insns,
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

/* Execute an XDP program via bpf_prog_test_run. Returns 0 on success. */
static int neg_test_run_xdp(int prog_fd, __u32 *retval)
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

/* Create BPF_MAP_TYPE_ARRAY: key=4, value=8, max_entries=1 */
static int neg_create_array_map(void)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_ARRAY;
	attr.key_size = 4;
	attr.value_size = 8;
	attr.max_entries = 1;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

/* ------------------------------------------------------------------ */
/*  Canonical programs                                                 */
/* ------------------------------------------------------------------ */

/* Returns XDP_PASS (2) */
static const struct bpf_insn good_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_DROP (1) */
static const struct bpf_insn good_xdp_drop[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_TX (3) via r0 = 1 + 2, 4 insns */
static const struct bpf_insn good_xdp_tx[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1, .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X,
	  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* A computation program: r0 = ((42 * 3) + 7) & 0xFF = 133 */
static const struct bpf_insn good_xdp_compute[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = 42 },
	{ .code = BPF_ALU64 | BPF_MUL | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = 3 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = 7 },
	{ .code = BPF_ALU64 | BPF_AND | BPF_K,
	  .dst_reg = BPF_REG_0, .imm = 0xFF },
	{ .code = BPF_JMP | BPF_EXIT },
};
#define GOOD_XDP_COMPUTE_RESULT 133

/* Load the canonical XDP_PASS program, return fd or -1 */
static int neg_load_good_prog(void)
{
	char log_buf[65536];
	memset(log_buf, 0, sizeof(log_buf));
	return neg_load_xdp_prog(good_xdp_pass, ARRAY_SIZE(good_xdp_pass),
				  log_buf, sizeof(log_buf));
}

/* Verify the given prog fd returns expected_retval via test_run */
static int neg_verify_retval(int prog_fd, __u32 expected)
{
	__u32 retval = 0;
	if (neg_test_run_xdp(prog_fd, &retval) < 0)
		return -1;
	if (retval != expected)
		return -1;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Test framework                                                     */
/* ------------------------------------------------------------------ */

static int g_pass;
static int g_fail;
static int g_skip;

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", (name)); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", (name), (reason)); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	printf("  SKIP  %s: %s\n", (name), (reason)); \
	g_skip++; \
} while (0)

/*
 * Generic negative test pattern:
 *  1. Load a good XDP_PASS program
 *  2. Verify it returns XDP_PASS
 *  3. Attempt REJIT with bad bytecode -- must fail
 *  4. Verify original still returns XDP_PASS
 */
static int run_negative_test(const char *name,
			     const struct bpf_insn *bad_insns,
			     __u32 bad_insn_cnt)
{
	char log_buf[65536];
	int prog_fd, ret;

	prog_fd = neg_load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	ret = neg_rejit_prog(prog_fd, bad_insns, bad_insn_cnt,
			     log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT unexpectedly succeeded");
		close(prog_fd);
		return 1;
	}

	if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "original program changed after failed REJIT!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* Simple PRNG for fuzz tests (xorshift64) */
static uint64_t fuzz_rng_state;

static void fuzz_seed(uint64_t seed)
{
	fuzz_rng_state = seed ? seed : 0xdeadbeefcafe1234ULL;
}

static uint64_t fuzz_rand64(void)
{
	uint64_t x = fuzz_rng_state;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	fuzz_rng_state = x;
	return x;
}

static uint32_t fuzz_rand32(void)
{
	return (uint32_t)(fuzz_rand64() >> 16);
}

#endif /* NEGATIVE_COMMON_H */
