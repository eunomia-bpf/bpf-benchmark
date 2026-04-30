// SPDX-License-Identifier: GPL-2.0
/*
 * REJIT Pass Correctness Test Suite
 *
 * Validates that identity REJIT (re-submitting the same original insns)
 * preserves correctness for all 16 BPF test programs under
 * tests/unittest/progs/.  Each program targets a specific daemon
 * optimization pass pattern.
 *
 * For each BPF program the test:
 *   1. Loads the .bpf.o via libbpf (with maps, BTF, subprogs)
 *   2. Runs BPF_PROG_TEST_RUN to capture the stock return value
 *   3. Reads back original insns via bpf_prog_info (GET_ORIGINAL)
 *   4. Submits those insns through BPF_PROG_REJIT (identity REJIT)
 *   5. Runs BPF_PROG_TEST_RUN again to capture post-REJIT return value
 *   6. Asserts stock == REJIT return value
 *
 * For struct_ops and fentry programs that cannot be directly TEST_RUN'd,
 * we verify that REJIT is accepted by the verifier (step 4 succeeds).
 *
 * Build (from repo root, via Makefile):
 *   make -C tests/unittest
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_pass_correctness [/path/to/progs/dir]
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

/* libbpf — needed for loading .bpf.o with maps, BTF, struct_ops */
#include <bpf/libbpf.h>
#include <bpf/bpf.h>

/* Default progs directory (relative to binary location or CWD) */
static const char *g_progs_dir = "progs";
static const char *g_test_filter;

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

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

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

/* ------------------------------------------------------------------ */
/*  REJIT helper                                                      */
/* ------------------------------------------------------------------ */

static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_size = log_buf_sz;
	attr.rejit.log_buf = ptr_to_u64(log_buf);

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

/* ------------------------------------------------------------------ */
/*  prog_info / GET_ORIGINAL helpers                                  */
/* ------------------------------------------------------------------ */

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
		/* Fallback: try xlated_prog_len */
		if (info.xlated_prog_len == 0)
			return -1;

		__u32 insn_cnt = info.xlated_prog_len / sizeof(struct bpf_insn);
		insns = calloc(insn_cnt, sizeof(struct bpf_insn));
		if (!insns)
			return -1;

		memset(&info, 0, sizeof(info));
		info_len = sizeof(info);
		info.xlated_prog_len = insn_cnt * sizeof(struct bpf_insn);
		info.xlated_prog_insns = ptr_to_u64(insns);
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			free(insns);
			return -1;
		}

		*out_insns = insns;
		return insn_cnt;
	}

	__u32 insn_cnt = info.orig_prog_len / sizeof(struct bpf_insn);
	insns = calloc(insn_cnt, sizeof(struct bpf_insn));
	if (!insns)
		return -1;

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	info.orig_prog_len = insn_cnt * sizeof(struct bpf_insn);
	info.orig_prog_insns = ptr_to_u64(insns);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		free(insns);
		return -1;
	}

	*out_insns = insns;
	return insn_cnt;
}

/* ------------------------------------------------------------------ */
/*  BPF_PROG_TEST_RUN helpers                                         */
/* ------------------------------------------------------------------ */

/*
 * Run an XDP prog with packet data via BPF_PROG_TEST_RUN.
 * Provides a minimal valid 64-byte packet.
 */
static int test_run_xdp(int prog_fd, __u32 *retval)
{
	/* Minimal Ethernet frame: dst(6) + src(6) + ethertype(2) + payload */
	unsigned char pkt[64];
	union bpf_attr attr;

	memset(pkt, 0, sizeof(pkt));
	/* Set some non-zero bytes so packet-reading progs see data */
	pkt[0] = 0x01; pkt[1] = 0x02; pkt[2] = 0x03; pkt[3] = 0x04;
	pkt[4] = 0x05; pkt[5] = 0x06; pkt[6] = 0x07; pkt[7] = 0x08;
	/* Ethertype = 0x0800 (IPv4) at offset 12-13 */
	pkt[12] = 0x08; pkt[13] = 0x00;
	/* Fill some payload for progs that read data bytes */
	pkt[14] = 0xAA; pkt[15] = 0xBB; pkt[16] = 0xCC; pkt[17] = 0xDD;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(pkt);
	attr.test.data_size_in = sizeof(pkt);
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Test case descriptors                                             */
/* ------------------------------------------------------------------ */

enum prog_category {
	CAT_XDP,		/* XDP, supports TEST_RUN with packet */
	CAT_STRUCT_OPS,		/* struct_ops, no TEST_RUN */
	CAT_FENTRY,		/* fentry/tracing, no TEST_RUN */
};

struct test_prog_desc {
	const char *test_name;
	const char *obj_file;	/* basename of .bpf.o under progs/ */
	const char *prog_name;	/* BPF function name inside the object */
	enum prog_category cat;
	/*
	 * For fentry programs, the kernel function to attach to.
	 * NULL for generic tracing programs and non-fentry types.
	 */
	const char *fentry_target;
};

static const struct test_prog_desc test_progs[] = {
	{
		.test_name = "T01_rotate",
		.obj_file = "test_rotate.bpf.o",
		.prog_name = "test_rotate",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T02_rotate_masked_low",
		.obj_file = "test_rotate_masked_low.bpf.o",
		.prog_name = "test_rotate_masked_low",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T03_subprog_rotate",
		.obj_file = "test_subprog_rotate.bpf.o",
		.prog_name = "test_subprog_rotate",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T04_wide_mem",
		.obj_file = "test_wide.bpf.o",
		.prog_name = "test_wide",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T05_endian_fusion",
		.obj_file = "test_endian_fusion.bpf.o",
		.prog_name = "test_endian_fusion",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T06_cond_select",
		.obj_file = "test_simple.bpf.o",
		.prog_name = "test_simple",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T07_diamond",
		.obj_file = "test_diamond.bpf.o",
		.prog_name = "test_diamond",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T08_branch_flip",
		.obj_file = "test_branch_flip.bpf.o",
		.prog_name = "test_branch_flip",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T09_bitfield_extract",
		.obj_file = "test_bitfield_extract.bpf.o",
		.prog_name = "test_bitfield_extract",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T10_bitfield_extract_boundary",
		.obj_file = "test_bitfield_extract_boundary.bpf.o",
		.prog_name = "test_bitfield_extract_boundary",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T11_addr_calc",
		.obj_file = "test_addr_calc.bpf.o",
		.prog_name = "test_addr_calc",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T12_cross_subprog_boundary",
		.obj_file = "test_cross_subprog_boundary.bpf.o",
		.prog_name = "test_cross_subprog_boundary",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T13_interior_edge",
		.obj_file = "test_interior_edge.bpf.o",
		.prog_name = "test_interior_edge",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T14_struct_ops_tcp",
		.obj_file = "test_struct_ops_tcp.bpf.o",
		.prog_name = "rejit_cc_ssthresh",
		.cat = CAT_STRUCT_OPS,
	},
	{
		.test_name = "T15_trampoline_fentry",
		.obj_file = "test_trampoline_fentry.bpf.o",
		.prog_name = "test_simple_fentry",
		.cat = CAT_FENTRY,
		.fentry_target = "bpf_fentry_test1",
	},
	{
		.test_name = "T16_zero_applied_noop_select",
		.obj_file = "test_zero_applied_noop_select.bpf.o",
		.prog_name = "test_zero_applied_noop_select",
		.cat = CAT_XDP,
	},
	{
		.test_name = "T17_tracepoint_subprog",
		.obj_file = "test_tracepoint_subprog.bpf.o",
		.prog_name = "test_tracepoint_subprog",
		.cat = CAT_FENTRY,
	},
};

/* ------------------------------------------------------------------ */
/*  Generic test runner for a single XDP program                      */
/* ------------------------------------------------------------------ */

static int test_xdp_prog(const struct test_prog_desc *desc)
{
	const char *name = desc->test_name;
	char obj_path[512];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	char log_buf[65536];
	__u32 retval_before, retval_after;

	snprintf(obj_path, sizeof(obj_path), "%s/%s", g_progs_dir,
		 desc->obj_file);

	/* 1. Open and load */
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open .bpf.o (file missing?)");
		return 0;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "load failed (kernel feature not supported?)");
		bpf_object__close(obj);
		return 0;
	}

	prog = bpf_object__find_program_by_name(obj, desc->prog_name);
	if (!prog) {
		TEST_FAIL(name, "program not found in object");
		bpf_object__close(obj);
		return 1;
	}
	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "program has no valid fd");
		bpf_object__close(obj);
		return 1;
	}

	/* 2. TEST_RUN before REJIT */
	if (test_run_xdp(prog_fd, &retval_before) < 0) {
		TEST_FAIL(name, "pre-REJIT test_run failed");
		bpf_object__close(obj);
		return 1;
	}

	/* 3. GET_ORIGINAL */
	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		bpf_object__close(obj);
		return 1;
	}

	printf("    %s: %d orig insns, stock retval=%u\n",
	       name, orig_cnt, retval_before);

	/* 4. REJIT with identity (same insns) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	/* 5. TEST_RUN after REJIT */
	if (test_run_xdp(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-REJIT test_run failed");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	/* 6. Compare */
	if (retval_before != retval_after) {
		fprintf(stderr,
			"    retval mismatch: stock=%u rejit=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	free(orig_insns);
	bpf_object__close(obj);
	TEST_PASS(name);
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Generic test runner for struct_ops programs                       */
/* ------------------------------------------------------------------ */

static int test_struct_ops_prog(const struct test_prog_desc *desc)
{
	const char *name = desc->test_name;
	char obj_path[512];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	char log_buf[65536];

	snprintf(obj_path, sizeof(obj_path), "%s/%s", g_progs_dir,
		 desc->obj_file);

	/* 1. Open and load via libbpf (handles BTF + struct_ops magic) */
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open .bpf.o (file missing?)");
		return 0;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name,
			  "load failed (struct_ops kernel mismatch?)");
		bpf_object__close(obj);
		return 0;
	}

	/* 2. Find the target callback prog */
	prog = bpf_object__find_program_by_name(obj, desc->prog_name);
	if (!prog) {
		TEST_FAIL(name, "program not found in object");
		bpf_object__close(obj);
		return 1;
	}
	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "program has no valid fd");
		bpf_object__close(obj);
		return 1;
	}

	/* 3. GET_ORIGINAL */
	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		bpf_object__close(obj);
		return 1;
	}

	printf("    %s: %d orig insns (struct_ops, no TEST_RUN)\n",
	       name, orig_cnt);

	/* 4. REJIT — verify the verifier accepts identity REJIT */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	free(orig_insns);
	bpf_object__close(obj);
	TEST_PASS(name);
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Generic test runner for fentry/tracing programs                   */
/* ------------------------------------------------------------------ */

static int test_fentry_prog(const struct test_prog_desc *desc)
{
	const char *name = desc->test_name;
	char obj_path[512];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	char log_buf[65536];

	snprintf(obj_path, sizeof(obj_path), "%s/%s", g_progs_dir,
		 desc->obj_file);

	/* 1. Open (but do not load yet — need to set attach target first) */
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open .bpf.o (file missing?)");
		return 0;
	}

	/* 2. Find the program and set its attach target */
	prog = bpf_object__find_program_by_name(obj, desc->prog_name);
	if (!prog) {
		TEST_FAIL(name, "program not found in object");
		bpf_object__close(obj);
		return 1;
	}

	if (desc->fentry_target) {
		if (bpf_program__set_attach_target(prog, 0,
						   desc->fentry_target) < 0) {
			TEST_SKIP(name,
				  "set_attach_target failed (kernel BTF mismatch?)");
			bpf_object__close(obj);
			return 0;
		}
	}

	/* 3. Load */
	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name,
			  "load failed (fentry/tracing not supported?)");
		bpf_object__close(obj);
		return 0;
	}

	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "program has no valid fd");
		bpf_object__close(obj);
		return 1;
	}

	/* 4. GET_ORIGINAL */
	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		bpf_object__close(obj);
		return 1;
	}

	printf("    %s: %d orig insns (fentry, no TEST_RUN)\n",
	       name, orig_cnt);

	/* 5. REJIT — verify the verifier accepts identity REJIT */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	free(orig_insns);
	bpf_object__close(obj);
	TEST_PASS(name);
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Dispatcher                                                        */
/* ------------------------------------------------------------------ */

static int run_test(const struct test_prog_desc *desc)
{
	if (g_test_filter && strcmp(desc->test_name, g_test_filter) != 0)
		return 0;

	switch (desc->cat) {
	case CAT_XDP:
		return test_xdp_prog(desc);
	case CAT_STRUCT_OPS:
		return test_struct_ops_prog(desc);
	case CAT_FENTRY:
		return test_fentry_prog(desc);
	default:
		TEST_SKIP(desc->test_name, "unknown category");
		return 0;
	}
}

/* ------------------------------------------------------------------ */
/*  main                                                              */
/* ------------------------------------------------------------------ */

static int libbpf_print_fn(enum libbpf_print_level level, const char *format,
			    va_list args)
{
	if (level <= LIBBPF_WARN)
		return vfprintf(stderr, format, args);
	return 0;
}

int main(int argc, char *argv[])
{
	size_t i;

	/* Optional arg: path to directory containing .bpf.o progs */
	if (argc > 1)
		g_progs_dir = argv[1];
	if (argc > 2)
		g_test_filter = argv[2];

	libbpf_set_print(libbpf_print_fn);

	printf("=== REJIT pass correctness test suite ===\n");
	printf("  progs_dir = %s\n\n", g_progs_dir);
	if (g_test_filter)
		printf("  test_filter = %s\n\n", g_test_filter);

	printf("--- XDP programs (full TEST_RUN verification) ---\n");
	for (i = 0; i < ARRAY_SIZE(test_progs); i++) {
		if (test_progs[i].cat == CAT_XDP)
			run_test(&test_progs[i]);
	}

	printf("\n--- struct_ops programs (REJIT verifier acceptance) ---\n");
	for (i = 0; i < ARRAY_SIZE(test_progs); i++) {
		if (test_progs[i].cat == CAT_STRUCT_OPS)
			run_test(&test_progs[i]);
	}

	printf("\n--- fentry/tracing programs (REJIT verifier acceptance) ---\n");
	for (i = 0; i < ARRAY_SIZE(test_progs); i++) {
		if (test_progs[i].cat == CAT_FENTRY)
			run_test(&test_progs[i]);
	}

	printf("\n=== Summary: %d PASS, %d FAIL, %d SKIP (total %d) ===\n",
	       g_pass, g_fail, g_skip, g_pass + g_fail + g_skip);

	return g_fail ? 1 : 0;
}
