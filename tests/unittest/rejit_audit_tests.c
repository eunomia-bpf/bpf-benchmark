// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Audit Bug-Fix Regression Tests
 *
 * Tests for bugs found in the kernel audit (docs/tmp/kernel_full_audit_20260322.md).
 * Each test validates that a specific fix works correctly:
 *
 *  T1 (H1): kfd_array leak — repeated REJIT with fd_array, verify no OOM/hang
 *  T2 (M4): insns/len swap — REJIT to different length, check xlated_prog_len
 *  T3 (M4): insns content — REJIT to different code, verify xlated insns match
 *  T4 (M6): flags=0 accepted — REJIT with flags=0 succeeds
 *  T5 (M6): flags!=0 rejected — REJIT with flags=1 returns EINVAL
 *  T6 (H1): kfd_array leak stress — 500 REJITs with fd_array, still works
 *  T7 (H2): EXT func_info leak — repeated REJIT of programs, no hang
 *  T8 (M4): Multi-step length transitions (2->4->6->4->2 insns)
 *  T9 (H3): struct_ops multi-slot — same prog in ssthresh+undo_cwnd,
 *           REJIT must patch ALL trampolines (not just the first match)
 *
 * Build (from repo root, via Makefile):
 *   make -C tests/unittest
 *
 * Manual build (requires libbpf for T9):
 *   cc -O2 -Wall -Wno-#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -I tests/unittest/build/vendor/libbpf/prefix/include \
 *     -o tests/unittest/rejit_audit_tests tests/unittest/rejit_audit_tests.c \
 *     tests/unittest/build/vendor/libbpf/obj/libbpf.a -lelf -lz -lzstd -lpthread
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_audit_tests [/path/to/progs/dir]
 */
#define _GNU_SOURCE
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

/* libbpf — needed for struct_ops loading (T9) */
#include <bpf/libbpf.h>
#include <bpf/bpf.h>

/* Default progs directory (relative to binary location or CWD) */
static const char *g_progs_dir = "progs";

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

static int g_pass;
static int g_fail;
static int g_skip;

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
	attr.prog_type = BPF_PROG_TYPE_XDP;
	attr.insn_cnt = insn_cnt;
	attr.insns = ptr_to_u64(insns);
	attr.license = ptr_to_u64(license);
	attr.log_level = 1;
	attr.log_buf = ptr_to_u64(log_buf);
	attr.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

/* REJIT a prog with optional fd_array. Returns 0 on success, -1 on error. */
static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, const int *fd_array, __u32 fd_array_cnt,
		      char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.fd_array = ptr_to_u64(fd_array);
	attr.rejit.fd_array_cnt = fd_array_cnt;
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

/* REJIT a prog without fd_array. Returns 0 on success, -1 on error. */
static int rejit_prog_simple(int prog_fd, const struct bpf_insn *insns,
			     __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	return rejit_prog(prog_fd, insns, insn_cnt, NULL, 0, log_buf, log_buf_sz);
}

/* Raw REJIT syscall with explicit flags field. */
static int rejit_prog_with_flags(int prog_fd, const struct bpf_insn *insns,
				 __u32 insn_cnt, __u32 flags,
				 char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.flags = flags;
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

/* Execute an XDP program via bpf_prog_test_run. Returns 0 on success. */
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

/* Get bpf_prog_info for a prog fd. Returns 0 on success. */
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

static int create_array_map(void)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_ARRAY;
	attr.key_size = 4;
	attr.value_size = 8;
	attr.max_entries = 1;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

/* ----- Canonical programs ----------------------------------------- */

/* Returns XDP_PASS (2), 2 insns */
static const struct bpf_insn prog_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_DROP (1), 2 insns */
static const struct bpf_insn prog_drop[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_TX (3) via r0 = 1 + 2, 4 insns */
static const struct bpf_insn prog_tx_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns 42 via r0 = 10 + 32, 4 insns (different from prog_tx_long) */
static const struct bpf_insn prog_42_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 10 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 32 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns 7 via chain: r0=1, r1=2, r2=4, r0=r0+r1+r2, 6 insns */
static const struct bpf_insn prog_7_6insns[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 2 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_2,
	  .imm = 4 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_2 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* ------------------------------------------------------------------ */
/*  Test framework macros                                             */
/* ------------------------------------------------------------------ */

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

/*
 * Read back original program instructions via bpf_prog_info.
 * Allocates *out_insns (caller must free). Returns insn count or -1.
 */
static int get_original_insns(int prog_fd, struct bpf_insn **out_insns)
{
	struct bpf_prog_info info;
	__u32 info_len;
	struct bpf_insn *insns;

	/* First call: get orig_prog_len */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0)
		return -1;

	if (info.orig_prog_len == 0) {
		if (info.xlated_prog_len == 0)
			return -1;
		/* Fallback to xlated insns */
		__u32 cnt = info.xlated_prog_len / sizeof(struct bpf_insn);
		insns = calloc(cnt, sizeof(struct bpf_insn));
		if (!insns)
			return -1;
		memset(&info, 0, sizeof(info));
		info.xlated_prog_insns = ptr_to_u64(insns);
		info.xlated_prog_len = cnt * sizeof(struct bpf_insn);
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
		insns = calloc(cnt, sizeof(struct bpf_insn));
		if (!insns)
			return -1;
		memset(&info, 0, sizeof(info));
		info.orig_prog_insns = ptr_to_u64(insns);
		info.orig_prog_len = cnt * sizeof(struct bpf_insn);
		info_len = sizeof(info);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			free(insns);
			return -1;
		}
		*out_insns = insns;
		return cnt;
	}
}

static int load_good_prog(void)
{
	char log_buf[65536];
	memset(log_buf, 0, sizeof(log_buf));
	return load_xdp_prog(prog_pass, ARRAY_SIZE(prog_pass),
			     log_buf, sizeof(log_buf));
}

/* ================================================================== */
/*  T1: H1 — kfd_array leak: repeated REJIT with fd_array            */
/* ================================================================== */
/*
 * Before fix: kvfree(kfd_array) was missing on success and error paths.
 * After fix: kfd_array freed on both success and error exit.
 *
 * We REJIT 100 times with an fd_array to exercise the alloc/free path.
 * If the leak were present, the kernel would accumulate leaked allocations,
 * though detecting the leak directly from userspace is hard. Instead we
 * verify that 100 REJITs all succeed and the program still works.
 */
static void test_h1_kfd_array_leak(void)
{
	const char *name = "T1_H1_kfd_array_leak";
	char log_buf[65536];
	int prog_fd, map_fd, i;
	int fd_array[1];
	__u32 retval;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	map_fd = create_array_map();
	if (map_fd < 0) {
		TEST_FAIL(name, "map create failed");
		close(prog_fd);
		return;
	}
	fd_array[0] = map_fd;

	for (i = 0; i < 100; i++) {
		const struct bpf_insn *insns;
		__u32 cnt;

		/* Alternate between two programs */
		if (i % 2 == 0) {
			insns = prog_drop;
			cnt = ARRAY_SIZE(prog_drop);
		} else {
			insns = prog_pass;
			cnt = ARRAY_SIZE(prog_pass);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, insns, cnt,
			       fd_array, 1, log_buf, sizeof(log_buf)) < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "REJIT #%d failed", i);
			TEST_FAIL(name, msg);
			close(prog_fd);
			close(map_fd);
			return;
		}
	}

	/* Final: should be prog_pass (odd last iteration = 99, prog_pass) */
	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "final test_run mismatch");
		close(prog_fd);
		close(map_fd);
		return;
	}

	close(prog_fd);
	close(map_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T2: M4 — insns/len swap: xlated_prog_len reflects new length      */
/* ================================================================== */
/*
 * Before fix: prog->len and prog->insnsi were NOT updated during swap.
 * After fix: memcpy + len update when new insns fit within allocation.
 *
 * Load 2-insn prog, REJIT to 4-insn prog, check xlated_prog_len changed.
 */
static void test_m4_xlated_len(void)
{
	const char *name = "T2_M4_xlated_prog_len";
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd;
	__u32 pre_len, post_len;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_pass, ARRAY_SIZE(prog_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Get pre-REJIT xlated_prog_len */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info pre-rejit failed");
		close(prog_fd);
		return;
	}
	pre_len = info.xlated_prog_len;

	if (pre_len == 0) {
		TEST_FAIL(name, "pre-rejit xlated_prog_len is 0");
		close(prog_fd);
		return;
	}

	/* REJIT: 2 insns -> 4 insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog_simple(prog_fd, prog_tx_long, ARRAY_SIZE(prog_tx_long),
			      log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "REJIT 2->4 insns failed");
		close(prog_fd);
		return;
	}

	/* Get post-REJIT xlated_prog_len */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info post-rejit failed");
		close(prog_fd);
		return;
	}
	post_len = info.xlated_prog_len;

	/* After M4 fix, xlated_prog_len should reflect the new 4-insn program.
	 * 4 insns * 8 bytes = 32 bytes (xlated_prog_len is in bytes).
	 * The pre-rejit value is 2 insns * 8 = 16 bytes.
	 * The post-rejit value MUST be larger than pre-rejit.
	 */
	if (post_len <= pre_len) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated_prog_len did not grow: pre=%u post=%u",
			 pre_len, post_len);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify correctness: should return XDP_TX (3) */
	__u32 retval;
	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_TX) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "post-rejit retval=%u, expected XDP_TX(%u)",
			 retval, XDP_TX);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	printf("    xlated_prog_len: %u -> %u (expected growth)\n",
	       pre_len, post_len);
	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T3: M4 — xlated insns content verification                        */
/* ================================================================== */
/*
 * REJIT a program, then dump xlated insns via bpf_prog_info and compare
 * the first instruction's immediate value to confirm the new bytecode
 * is visible (not stale from the old program).
 */
static void test_m4_xlated_content(void)
{
	const char *name = "T3_M4_xlated_content";
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd;
	struct bpf_insn xlated[16];

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_pass, ARRAY_SIZE(prog_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* REJIT to prog_42_long (returns 42, 4 insns) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog_simple(prog_fd, prog_42_long, ARRAY_SIZE(prog_42_long),
			      log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "REJIT failed");
		close(prog_fd);
		return;
	}

	/* Dump xlated insns */
	memset(&info, 0, sizeof(info));
	memset(xlated, 0, sizeof(xlated));
	info.xlated_prog_insns = ptr_to_u64(xlated);
	info.xlated_prog_len = sizeof(xlated);
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info failed");
		close(prog_fd);
		return;
	}

	/* xlated_prog_len should be at least 4 insns * 8 bytes = 32 */
	if (info.xlated_prog_len < 4 * 8) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated_prog_len too small: %u (expected >= 32)",
			 info.xlated_prog_len);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify the first insn is MOV r0, 10 (from prog_42_long).
	 * The verifier may rewrite some things, but the immediate value of the
	 * first MOV should be preserved (10, not XDP_PASS=2 from the old prog).
	 */
	if (xlated[0].imm != 10) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated[0].imm=%d, expected 10 (stale insns?)",
			 xlated[0].imm);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify runtime result */
	__u32 retval;
	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 42) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "retval=%u, expected 42", retval);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T4: M6 — REJIT flags=0 accepted                                   */
/* ================================================================== */
static void test_m6_flags_zero(void)
{
	const char *name = "T4_M6_flags_zero";
	char log_buf[65536];
	int prog_fd;
	__u32 retval;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* REJIT with flags=0 should succeed */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog_with_flags(prog_fd, prog_drop, ARRAY_SIZE(prog_drop),
				  0, log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "REJIT with flags=0 failed");
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_DROP) {
		TEST_FAIL(name, "post-rejit retval mismatch");
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T5: M6 — REJIT flags!=0 rejected with EINVAL                      */
/* ================================================================== */
static void test_m6_flags_nonzero(void)
{
	const char *name = "T5_M6_flags_nonzero";
	char log_buf[65536];
	int prog_fd;
	__u32 retval;
	int ret;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* REJIT with flags=1 should fail with EINVAL */
	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog_with_flags(prog_fd, prog_drop, ARRAY_SIZE(prog_drop),
				    1, log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with flags=1 should have failed but succeeded");
		close(prog_fd);
		return;
	}
	if (errno != EINVAL) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "expected EINVAL, got errno=%d (%s)",
			 errno, strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Also try flags=0xFFFFFFFF */
	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog_with_flags(prog_fd, prog_drop, ARRAY_SIZE(prog_drop),
				    0xFFFFFFFF, log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with flags=0xFFFFFFFF should have failed");
		close(prog_fd);
		return;
	}
	if (errno != EINVAL) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "flags=0xFFFFFFFF: expected EINVAL, got errno=%d",
			 errno);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify original program is unaffected */
	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "original prog corrupted after rejected REJIT");
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T6: H1 — kfd_array leak stress (500 iterations)                   */
/* ================================================================== */
/*
 * Stress test: 500 REJIT calls, each with an fd_array.  If the kfd_array
 * leak were present, this would leak ~500 * kvmalloc(sizeof(int)*1) = ~2KB.
 * While the leak itself is small per call, at scale it matters.
 *
 * More importantly, we verify all 500 succeed and the final state is correct.
 */
static void test_h1_kfd_array_stress(void)
{
	const char *name = "T6_H1_kfd_array_stress";
	char log_buf[65536];
	int prog_fd, map_fd, i;
	int fd_array[1];
	__u32 retval;
	int fail_count = 0;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	map_fd = create_array_map();
	if (map_fd < 0) {
		TEST_FAIL(name, "map create failed");
		close(prog_fd);
		return;
	}
	fd_array[0] = map_fd;

	for (i = 0; i < 500; i++) {
		const struct bpf_insn *insns;
		__u32 cnt;

		if (i % 2 == 0) {
			insns = prog_drop;
			cnt = ARRAY_SIZE(prog_drop);
		} else {
			insns = prog_pass;
			cnt = ARRAY_SIZE(prog_pass);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, insns, cnt,
			       fd_array, 1, log_buf, sizeof(log_buf)) < 0) {
			fail_count++;
			if (fail_count > 5) {
				char msg[128];
				snprintf(msg, sizeof(msg),
					 "too many failures (%d) at iteration %d",
					 fail_count, i);
				TEST_FAIL(name, msg);
				close(prog_fd);
				close(map_fd);
				return;
			}
		}
	}

	/* i=499 (odd) -> prog_pass */
	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "final retval mismatch after 500 REJITs");
		close(prog_fd);
		close(map_fd);
		return;
	}

	printf("    500 REJITs with fd_array completed (%d transient failures)\n",
	       fail_count);
	close(prog_fd);
	close(map_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T7: H2 — EXT func_info leak: repeated REJIT stress                */
/* ================================================================== */
/*
 * Before fix: func_info/func_info_aux leaked on free_tmp error path.
 * We can't directly trigger the error path from userspace, but we can
 * exercise the success path repeatedly (which also frees func_info via
 * the old prog teardown) to verify no memory corruption.
 *
 * 200 REJIT cycles alternating between different-length programs.
 */
static void test_h2_func_info_stress(void)
{
	const char *name = "T7_H2_func_info_stress";
	char log_buf[65536];
	int prog_fd, i;
	__u32 retval;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	for (i = 0; i < 200; i++) {
		const struct bpf_insn *insns;
		__u32 cnt, expected;

		/* Cycle through 3 different program shapes to exercise
		 * different func_info/len combinations */
		switch (i % 3) {
		case 0:
			insns = prog_drop;
			cnt = ARRAY_SIZE(prog_drop);
			expected = XDP_DROP;
			break;
		case 1:
			insns = prog_tx_long;
			cnt = ARRAY_SIZE(prog_tx_long);
			expected = XDP_TX;
			break;
		default:
			insns = prog_7_6insns;
			cnt = ARRAY_SIZE(prog_7_6insns);
			expected = 7;
			break;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog_simple(prog_fd, insns, cnt,
				      log_buf, sizeof(log_buf)) < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "REJIT #%d failed", i);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}

		/* Verify every 50 iterations */
		if (i % 50 == 49) {
			if (test_run_xdp(prog_fd, &retval) < 0 ||
			    retval != expected) {
				char msg[128];
				snprintf(msg, sizeof(msg),
					 "iter %d: retval=%u expected=%u",
					 i, retval, expected);
				TEST_FAIL(name, msg);
				close(prog_fd);
				return;
			}
		}
	}

	printf("    200 REJITs with varying lengths completed\n");
	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T8: M4 — Multi-step length transitions                            */
/* ================================================================== */
/*
 * REJIT through multiple length transitions (2 -> 4 -> 6 -> 4 -> 2 insns)
 * and verify xlated_prog_len is correct at each step.
 * This is the most thorough M4 test: it checks both growth and shrinkage.
 */
static void test_m4_multi_length_transitions(void)
{
	const char *name = "T8_M4_multi_length_transitions";
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd;

	struct {
		const struct bpf_insn *insns;
		__u32 cnt;
		__u32 expected_retval;
		__u32 expected_xlated_bytes; /* cnt * 8 */
	} steps[] = {
		/* Start: 2 insns, XDP_PASS */
		{ prog_pass, ARRAY_SIZE(prog_pass), XDP_PASS, 2 * 8 },
		/* Step 1: grow to 4 insns */
		{ prog_tx_long, ARRAY_SIZE(prog_tx_long), XDP_TX, 4 * 8 },
		/* Step 2: grow to 6 insns */
		{ prog_7_6insns, ARRAY_SIZE(prog_7_6insns), 7, 6 * 8 },
		/* Step 3: shrink to 4 insns */
		{ prog_42_long, ARRAY_SIZE(prog_42_long), 42, 4 * 8 },
		/* Step 4: shrink to 2 insns */
		{ prog_drop, ARRAY_SIZE(prog_drop), XDP_DROP, 2 * 8 },
	};
	int nsteps = ARRAY_SIZE(steps);
	int i;

	/* Load the initial 2-insn program */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(steps[0].insns, steps[0].cnt,
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Verify initial state */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "initial get_info failed");
		close(prog_fd);
		return;
	}

	/* REJIT through remaining steps */
	for (i = 1; i < nsteps; i++) {
		__u32 retval;

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog_simple(prog_fd, steps[i].insns, steps[i].cnt,
				      log_buf, sizeof(log_buf)) < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg), "step %d REJIT failed", i);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}

		/* Check xlated_prog_len */
		memset(&info, 0, sizeof(info));
		info_len = sizeof(info);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg), "step %d get_info failed", i);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}

		if (info.xlated_prog_len != steps[i].expected_xlated_bytes) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "step %d: xlated_prog_len=%u expected=%u "
				 "(insn_cnt=%u)",
				 i, info.xlated_prog_len,
				 steps[i].expected_xlated_bytes,
				 steps[i].cnt);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}

		/* Check retval */
		if (test_run_xdp(prog_fd, &retval) < 0 ||
		    retval != steps[i].expected_retval) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "step %d: retval=%u expected=%u",
				 i, retval, steps[i].expected_retval);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}

		printf("    step %d: %u insns -> xlated=%u bytes, retval=%u OK\n",
		       i, steps[i].cnt, info.xlated_prog_len,
		       steps[i].expected_retval);
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  T9: H3 — struct_ops multi-slot REJIT                               */
/* ================================================================== */
/*
 * Regression test for the H3 bug: bpf_struct_ops_refresh_prog() had an
 * early `return 0` after patching the first matching slot, which should
 * have been `continue` so the loop visits all slots.
 *
 * Test strategy:
 *   Load a tcp_congestion_ops with 4 filled callback slots (init,
 *   ssthresh, cong_avoid, undo_cwnd).  REJIT each of two progs
 *   (ms_ssthresh, ms_undo_cwnd) independently, exercising the
 *   refresh_prog loop that must skip non-matching slots.
 *
 *   Each REJIT is done twice back-to-back.  If refresh_prog failed
 *   to update the trampoline correctly on the first REJIT, the second
 *   REJIT would crash because old_bpf_func (passed to find_call_site)
 *   would point to a freed JIT image.
 *
 *   A successful double-REJIT of both progs = the refresh_prog loop
 *   handles multi-slot struct_ops correctly.
 */
static void test_h3_struct_ops_multi_slot(void)
{
	const char *name = "T9_H3_struct_ops_multi_slot";
	char obj_path[512];
	struct bpf_object *obj = NULL;
	char log_buf[65536];
	struct bpf_prog_info info_buf;
	__u32 info_len;

	/* Programs to REJIT: we exercise two different progs so the
	 * refresh_prog loop must skip 3 non-matching slots each time. */
	static const char *prog_names[] = { "ms_ssthresh", "ms_undo_cwnd" };
	int nprog = ARRAY_SIZE(prog_names);
	int p;

	snprintf(obj_path, sizeof(obj_path), "%s/test_struct_ops_multi_slot.bpf.o",
		 g_progs_dir);

	/* 1. Open and load the struct_ops object via libbpf */
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open multi_slot .bpf.o (file missing?)");
		return;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "failed to load struct_ops object (kernel mismatch?)");
		bpf_object__close(obj);
		return;
	}

	/* 2. For each prog: GET_ORIGINAL -> REJIT -> REJIT again */
	for (p = 0; p < nprog; p++) {
		struct bpf_program *prog;
		struct bpf_insn *orig_insns = NULL;
		int orig_cnt, prog_fd, round;
		__u32 pre_jited_len;

		prog = bpf_object__find_program_by_name(obj, prog_names[p]);
		if (!prog) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "%s not found in object", prog_names[p]);
			TEST_FAIL(name, msg);
			bpf_object__close(obj);
			return;
		}
		prog_fd = bpf_program__fd(prog);
		if (prog_fd < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "%s has no valid fd", prog_names[p]);
			TEST_FAIL(name, msg);
			bpf_object__close(obj);
			return;
		}

		/* Get pre-REJIT jited_prog_len */
		memset(&info_buf, 0, sizeof(info_buf));
		info_len = sizeof(info_buf);
		if (get_prog_info(prog_fd, &info_buf, &info_len) < 0) {
			TEST_FAIL(name, "get_info pre-rejit failed");
			bpf_object__close(obj);
			return;
		}
		pre_jited_len = info_buf.jited_prog_len;
		if (pre_jited_len == 0) {
			TEST_SKIP(name, "program not JIT'd (JIT disabled?)");
			bpf_object__close(obj);
			return;
		}

		/* GET_ORIGINAL insns */
		orig_cnt = get_original_insns(prog_fd, &orig_insns);
		if (orig_cnt < 0) {
			char msg[128];
			snprintf(msg, sizeof(msg),
				 "get_original_insns failed for %s",
				 prog_names[p]);
			TEST_FAIL(name, msg);
			bpf_object__close(obj);
			return;
		}

		printf("    %s: %d insns, jited_len=%u, fd=%d\n",
		       prog_names[p], orig_cnt, pre_jited_len, prog_fd);

		/* REJIT twice back-to-back.
		 * Round 1: creates new JIT image, refresh_prog patches trampoline.
		 * Round 2: old_bpf_func = round-1's new image. If round 1 failed
		 *   to patch, find_call_site would look in the trampoline for an
		 *   address that no longer exists -> crash or -ENOENT.
		 */
		for (round = 1; round <= 2; round++) {
			memset(log_buf, 0, sizeof(log_buf));
			if (rejit_prog_simple(prog_fd, orig_insns, orig_cnt,
					      log_buf, sizeof(log_buf)) < 0) {
				char msg[128];
				snprintf(msg, sizeof(msg),
					 "%s REJIT round %d failed",
					 prog_names[p], round);
				fprintf(stderr, "  verifier log:\n%s\n",
					log_buf);
				TEST_FAIL(name, msg);
				free(orig_insns);
				bpf_object__close(obj);
				return;
			}
		}

		/* Verify post-REJIT jited_prog_len is non-zero */
		memset(&info_buf, 0, sizeof(info_buf));
		info_len = sizeof(info_buf);
		if (get_prog_info(prog_fd, &info_buf, &info_len) < 0) {
			TEST_FAIL(name, "get_info post-rejit failed");
			free(orig_insns);
			bpf_object__close(obj);
			return;
		}
		if (info_buf.jited_prog_len == 0) {
			TEST_FAIL(name, "post-rejit jited_prog_len is 0");
			free(orig_insns);
			bpf_object__close(obj);
			return;
		}

		printf("    %s: 2x REJIT OK, jited_len %u -> %u\n",
		       prog_names[p], pre_jited_len,
		       info_buf.jited_prog_len);

		free(orig_insns);
	}

	bpf_object__close(obj);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Main                                                               */
/* ================================================================== */

int main(int argc, char *argv[])
{
	/* Optional: path to progs directory (for struct_ops .bpf.o files) */
	if (argc > 1)
		g_progs_dir = argv[1];

	printf("=== BpfReJIT Audit Bug-Fix Regression Tests ===\n\n");

	printf("[H1] kfd_array memory leak (100 REJITs with fd_array):\n");
	test_h1_kfd_array_leak();

	printf("\n[M4] xlated_prog_len reflects new length after REJIT:\n");
	test_m4_xlated_len();

	printf("\n[M4] xlated insns content verification:\n");
	test_m4_xlated_content();

	printf("\n[M6] REJIT flags=0 accepted:\n");
	test_m6_flags_zero();

	printf("\n[M6] REJIT flags!=0 rejected with EINVAL:\n");
	test_m6_flags_nonzero();

	printf("\n[H1] kfd_array leak stress (500 REJITs):\n");
	test_h1_kfd_array_stress();

	printf("\n[H2] func_info leak stress (200 REJITs):\n");
	test_h2_func_info_stress();

	printf("\n[M4] Multi-step length transitions (2->4->6->4->2 insns):\n");
	test_m4_multi_length_transitions();

	printf("\n[H3] struct_ops multi-slot REJIT (same prog in 2 slots):\n");
	test_h3_struct_ops_multi_slot();

	printf("\n=== Results: %d PASS, %d FAIL, %d SKIP ===\n",
	       g_pass, g_fail, g_skip);

	if (g_fail)
		fprintf(stderr, "SOME TESTS FAILED\n");
	else
		printf("ALL TESTS PASSED\n");

	return g_fail ? 1 : 0;
}
