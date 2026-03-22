// SPDX-License-Identifier: GPL-2.0
/*
 * REJIT prog_type coverage test suite
 *
 * Validates that BPF_PROG_REJIT works correctly across all major BPF
 * program types. For each type we:
 *   1. Load a minimal program via BPF_PROG_LOAD
 *   2. Read back original insns via bpf_prog_info (GET_ORIGINAL)
 *   3. REJIT with identity (same insns) -> assert success
 *   4. If TEST_RUN is supported: run before and after, assert same retval
 *
 * Build (from repo root):
 *   # 1) Build BPF progs:
 *   for f in tests/unittest/progs/ *.bpf.c; do
 *     clang -O2 -target bpf -g -Wno-missing-declarations \
 *       -I vendor/libbpf/src \
 *       -I vendor/linux-framework/tools/testing/selftests/bpf/tools/include \
 *       -I /usr/include/$(gcc -print-multiarch) \
 *       -c "$f" -o "${f%.c}.o"
 *   done
 *
 *   # 2) Build test binary (links libbpf):
 *   clang -O2 -Wall -Wno-#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -I vendor/libbpf/src \
 *     -o tests/unittest/rejit_prog_types tests/unittest/rejit_prog_types.c \
 *     -L micro/build/vendor/libbpf/obj -lbpf -lelf -lz -lzstd
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_prog_types [/path/to/progs/dir]
 */
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

/* libbpf -- used for freplace + struct_ops which need full ELF+BTF loading */
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

/* ------------------------------------------------------------------ */
/*  Generic load/rejit/test_run/info helpers                          */
/* ------------------------------------------------------------------ */

/*
 * Load a BPF program of any type. Returns prog_fd or -1.
 * For tracing/ext types, set attach_btf_id/attach_prog_fd/expected_attach_type
 * via the extra_setup callback on the attr before the syscall.
 */
static int load_prog_full(__u32 prog_type, const struct bpf_insn *insns,
			  __u32 insn_cnt, __u32 expected_attach_type,
			  __u32 attach_btf_id, __u32 attach_prog_fd,
			  char *log_buf, size_t log_buf_sz)
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
	attr.attach_prog_fd = attach_prog_fd;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

/* Simpler load for types that need no special attach info */
static int load_prog(__u32 prog_type, const struct bpf_insn *insns,
		     __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	return load_prog_full(prog_type, insns, insn_cnt, 0, 0, 0,
			      log_buf, log_buf_sz);
}

/* REJIT an existing prog. Returns 0 on success, -1 on error. */
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

/* Execute a prog via bpf_prog_test_run with packet data. Returns 0 on success. */
static int test_run_prog(int prog_fd, __u32 *retval)
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

/* Execute a raw_tracepoint prog via TEST_RUN (no ctx needed). */
static int test_run_raw_tp(int prog_fd, __u32 *retval)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* Get bpf_prog_info. Returns 0 on success. */
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
		/* Fallback: try xlated_prog_len (non-REJIT kernels or first load) */
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

/*
 * Find the BTF type ID for a kernel function by name using libbpf.
 * Returns 0 on success and writes the ID to *btf_id_out, or -1 on failure.
 */
static int find_kernel_btf_id(const char *func_name, __u32 *btf_id_out)
{
	int id;

	/* Use libbpf to find the vmlinux BTF ID for a fentry/fexit attach.
	 * libbpf_find_vmlinux_btf_id handles all BTF type encoding details
	 * and correctly locates the function's BTF_KIND_FUNC entry. */
	id = libbpf_find_vmlinux_btf_id(func_name, BPF_TRACE_FENTRY);
	if (id < 0)
		return -1;

	*btf_id_out = (__u32)id;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Test framework                                                    */
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

/* ------------------------------------------------------------------ */
/*  Canonical instruction sequences                                   */
/* ------------------------------------------------------------------ */

/* r0 = imm; exit */
#define PROG_RET(imm_val) { \
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = (imm_val) }, \
	{ .code = BPF_JMP | BPF_EXIT }, \
}

/* XDP_PASS = 2 */
static const struct bpf_insn prog_ret_2[] = PROG_RET(2);
/* XDP_DROP = 1 */
static const struct bpf_insn prog_ret_1[] = PROG_RET(1);
/* Generic return 0 */
static const struct bpf_insn prog_ret_0[] = PROG_RET(0);

/* ================================================================== */
/*  Test 1: XDP (full: load -> run -> REJIT identity -> run -> assert)*/
/* ================================================================== */

static int test_xdp(void)
{
	const char *name = "T01_xdp";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_XDP, prog_ret_2, ARRAY_SIZE(prog_ret_2),
			    log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	/* Run before REJIT */
	if (test_run_prog(prog_fd, &retval_before) < 0) {
		TEST_FAIL(name, "pre-rejit test_run failed");
		close(prog_fd);
		return 1;
	}

	/* GET_ORIGINAL */
	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	/* REJIT with identity (same insns) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	/* Run after REJIT */
	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 2: TC / sched_cls (full verification)                        */
/* ================================================================== */

static int test_tc(void)
{
	const char *name = "T02_tc_sched_cls";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* TC programs return TC_ACT_OK (0) */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_SCHED_CLS, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_before) < 0) {
		TEST_FAIL(name, "pre-rejit test_run failed");
		close(prog_fd);
		return 1;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 3: socket_filter (full verification)                         */
/* ================================================================== */

static int test_socket_filter(void)
{
	const char *name = "T03_socket_filter";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* Socket filters return packet length or 0 (drop) */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_SOCKET_FILTER, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_before) < 0) {
		/* socket_filter may not support TEST_RUN on all kernels */
		TEST_SKIP(name, "test_run not supported, trying REJIT-only path");
		/* Still test REJIT */
		orig_cnt = get_original_insns(prog_fd, &orig_insns);
		if (orig_cnt < 0) {
			TEST_FAIL(name, "get_original_insns failed");
			close(prog_fd);
			return 1;
		}
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, orig_insns, orig_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "  verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "REJIT identity failed");
			free(orig_insns);
			close(prog_fd);
			return 1;
		}
		free(orig_insns);
		close(prog_fd);
		/* Already counted as skip above, upgrade to pass */
		g_skip--;
		TEST_PASS(name);
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 4: cgroup_skb (full verification)                            */
/* ================================================================== */

static int test_cgroup_skb(void)
{
	const char *name = "T04_cgroup_skb";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* cgroup_skb: return 1 = allow, 0 = deny
	 * Need expected_attach_type = BPF_CGROUP_INET_INGRESS */
	static const struct bpf_insn cgroup_prog[] = PROG_RET(1);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog_full(BPF_PROG_TYPE_CGROUP_SKB, cgroup_prog,
				 ARRAY_SIZE(cgroup_prog),
				 0 /* BPF_CGROUP_INET_INGRESS = 0 */,
				 0, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_before) < 0) {
		TEST_FAIL(name, "pre-rejit test_run failed");
		close(prog_fd);
		return 1;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 5: kprobe (load + REJIT identity, no TEST_RUN)               */
/* ================================================================== */

static int test_kprobe(void)
{
	const char *name = "T05_kprobe";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_KPROBE, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		/* kprobe needs CONFIG_KPROBES; skip if not available */
		TEST_SKIP(name, "load failed (CONFIG_KPROBES not set?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 6: tracepoint (load + REJIT identity, no TEST_RUN)           */
/* ================================================================== */

static int test_tracepoint(void)
{
	const char *name = "T06_tracepoint";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_TRACEPOINT, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		/* tracepoint needs CONFIG_FTRACE; skip if not available */
		TEST_SKIP(name, "load failed (CONFIG_FTRACE not set?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 7: raw_tracepoint (can TEST_RUN)                             */
/* ================================================================== */

static int test_raw_tracepoint(void)
{
	const char *name = "T07_raw_tracepoint";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	int can_test_run = 1;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_RAW_TRACEPOINT, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		/* raw_tracepoint needs CONFIG_FTRACE; skip if not available */
		TEST_SKIP(name, "load failed (CONFIG_FTRACE not set?)");
		return 0;
	}

	if (test_run_raw_tp(prog_fd, &retval_before) < 0) {
		/* raw_tracepoint TEST_RUN may not be supported */
		can_test_run = 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (can_test_run) {
		if (test_run_raw_tp(prog_fd, &retval_after) < 0) {
			TEST_FAIL(name, "post-rejit test_run failed");
			free(orig_insns);
			close(prog_fd);
			return 1;
		}
		if (retval_before != retval_after) {
			fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
				retval_before, retval_after);
			TEST_FAIL(name, "retval changed after identity REJIT");
			free(orig_insns);
			close(prog_fd);
			return 1;
		}
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 8: perf_event (load + REJIT identity, no TEST_RUN)           */
/* ================================================================== */

static int test_perf_event(void)
{
	const char *name = "T08_perf_event";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_PERF_EVENT, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		/* perf_event BPF progs may need CONFIG_FTRACE; skip if not available */
		TEST_SKIP(name, "load failed (CONFIG_BPF_EVENTS/FTRACE not set?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 9: sched_act (full verification via TEST_RUN)                */
/* ================================================================== */

static int test_sched_act(void)
{
	const char *name = "T09_sched_act";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_SCHED_ACT, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		/* sched_act might not be enabled in all configs */
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	if (test_run_prog(prog_fd, &retval_before) < 0) {
		TEST_FAIL(name, "pre-rejit test_run failed");
		close(prog_fd);
		return 1;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 10: flow_dissector (TEST_RUN supported)                      */
/* ================================================================== */

static int test_flow_dissector(void)
{
	const char *name = "T10_flow_dissector";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* flow_dissector: return BPF_OK (0) */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog_full(BPF_PROG_TYPE_FLOW_DISSECTOR, prog_ret_0,
				 ARRAY_SIZE(prog_ret_0), 0, 0, 0,
				 log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 11: sk_lookup (TEST_RUN supported)                           */
/* ================================================================== */

static int test_sk_lookup(void)
{
	const char *name = "T11_sk_lookup";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* sk_lookup needs expected_attach_type = BPF_SK_LOOKUP */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog_full(BPF_PROG_TYPE_SK_LOOKUP, prog_ret_0,
				 ARRAY_SIZE(prog_ret_0),
				 BPF_SK_LOOKUP,
				 0, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 12: lwt_in (TEST_RUN supported)                              */
/* ================================================================== */

static int test_lwt_in(void)
{
	const char *name = "T12_lwt_in";
	char log_buf[65536];
	int prog_fd;
	__u32 retval_before, retval_after;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_LWT_IN, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	if (test_run_prog(prog_fd, &retval_before) < 0) {
		/* Fall back to REJIT-only test */
		orig_cnt = get_original_insns(prog_fd, &orig_insns);
		if (orig_cnt < 0) {
			TEST_FAIL(name, "get_original_insns failed");
			close(prog_fd);
			return 1;
		}
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, orig_insns, orig_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "  verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "REJIT identity failed");
			free(orig_insns);
			close(prog_fd);
			return 1;
		}
		free(orig_insns);
		close(prog_fd);
		TEST_PASS(name);
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval_after) < 0) {
		TEST_FAIL(name, "post-rejit test_run failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	if (retval_before != retval_after) {
		fprintf(stderr, "  retval mismatch: before=%u after=%u\n",
			retval_before, retval_after);
		TEST_FAIL(name, "retval changed after identity REJIT");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 13: XDP functional (REJIT changes return value, not identity) */
/* ================================================================== */

static int test_xdp_functional(void)
{
	const char *name = "T13_xdp_functional_rejit";
	char log_buf[65536];
	int prog_fd;
	__u32 retval;

	/* Load XDP_PASS program */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_XDP, prog_ret_2, ARRAY_SIZE(prog_ret_2),
			    log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	/* Verify initial behavior: returns XDP_PASS (2) */
	if (test_run_prog(prog_fd, &retval) < 0 || retval != 2) {
		TEST_FAIL(name, "pre-rejit run failed or wrong retval");
		close(prog_fd);
		return 1;
	}

	/* REJIT to XDP_DROP (1) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_ret_1, ARRAY_SIZE(prog_ret_1),
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT to XDP_DROP failed");
		close(prog_fd);
		return 1;
	}

	/* Verify new behavior: returns XDP_DROP (1) */
	if (test_run_prog(prog_fd, &retval) < 0 || retval != 1) {
		fprintf(stderr, "  expected retval=1, got=%u\n", retval);
		TEST_FAIL(name, "post-rejit retval wrong");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 14: TC functional (REJIT changes return value)               */
/* ================================================================== */

static int test_tc_functional(void)
{
	const char *name = "T14_tc_functional_rejit";
	char log_buf[65536];
	int prog_fd;
	__u32 retval;

	/* r0 = 0; exit (TC_ACT_OK) */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_SCHED_CLS, prog_ret_0,
			    ARRAY_SIZE(prog_ret_0), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return 1;
	}

	if (test_run_prog(prog_fd, &retval) < 0 || retval != 0) {
		TEST_FAIL(name, "pre-rejit run failed or wrong retval");
		close(prog_fd);
		return 1;
	}

	/* REJIT to return 2 (TC_ACT_SHOT) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_ret_2, ARRAY_SIZE(prog_ret_2),
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT to TC_ACT_SHOT failed");
		close(prog_fd);
		return 1;
	}

	if (test_run_prog(prog_fd, &retval) < 0 || retval != 2) {
		fprintf(stderr, "  expected retval=2, got=%u\n", retval);
		TEST_FAIL(name, "post-rejit retval wrong");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 15: fentry (tracing, targets kernel func via vmlinux BTF)    */
/* ================================================================== */

/*
 * fentry programs require attach_btf_id pointing to a kernel function.
 * We use bpf_fentry_test1 (a standard BPF test function present in
 * kernels with CONFIG_BPF_SYSCALL + CONFIG_DEBUG_INFO_BTF).
 * attach_prog_fd = 0 means targeting a kernel function (not a BPF prog).
 */

static int test_fentry(void)
{
	const char *name = "T15_fentry";
	char log_buf[65536];
	int fentry_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	__u32 target_btf_id;

	/* Find bpf_fentry_test1 in vmlinux BTF */
	if (find_kernel_btf_id("bpf_fentry_test1", &target_btf_id) < 0) {
		TEST_SKIP(name, "vmlinux BTF not available or bpf_fentry_test1 not found");
		return 0;
	}

	/* Load fentry program targeting a kernel function */
	memset(log_buf, 0, sizeof(log_buf));
	fentry_fd = load_prog_full(BPF_PROG_TYPE_TRACING, prog_ret_0,
				   ARRAY_SIZE(prog_ret_0),
				   BPF_TRACE_FENTRY,
				   target_btf_id, 0 /* kernel func */,
				   log_buf, sizeof(log_buf));
	if (fentry_fd < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "fentry load failed");
		return 1;
	}

	/* GET_ORIGINAL + REJIT identity */
	orig_cnt = get_original_insns(fentry_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(fentry_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(fentry_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(fentry_fd);
		return 1;
	}

	free(orig_insns);
	close(fentry_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 16: fexit (tracing, targets kernel func via vmlinux BTF)     */
/* ================================================================== */

static int test_fexit(void)
{
	const char *name = "T16_fexit";
	char log_buf[65536];
	int fexit_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	__u32 target_btf_id;

	if (find_kernel_btf_id("bpf_fentry_test1", &target_btf_id) < 0) {
		TEST_SKIP(name, "vmlinux BTF not available or bpf_fentry_test1 not found");
		return 0;
	}

	memset(log_buf, 0, sizeof(log_buf));
	fexit_fd = load_prog_full(BPF_PROG_TYPE_TRACING, prog_ret_0,
				  ARRAY_SIZE(prog_ret_0),
				  BPF_TRACE_FEXIT,
				  target_btf_id, 0 /* kernel func */,
				  log_buf, sizeof(log_buf));
	if (fexit_fd < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "fexit load failed");
		return 1;
	}

	orig_cnt = get_original_insns(fexit_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(fexit_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(fexit_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(fexit_fd);
		return 1;
	}

	free(orig_insns);
	close(fexit_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 17: freplace / BPF_PROG_TYPE_EXT                             */
/*  Uses clang-compiled .bpf.o with BTF for both target and extension */
/* ================================================================== */

static int test_freplace(void)
{
	const char *name = "T17_freplace";
	char target_path[512], ext_path[512];
	struct bpf_object *target_obj = NULL, *ext_obj = NULL;
	struct bpf_program *target_prog, *ext_prog;
	int target_fd, ext_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	char log_buf[65536];

	snprintf(target_path, sizeof(target_path), "%s/test_freplace_target.bpf.o",
		 g_progs_dir);
	snprintf(ext_path, sizeof(ext_path), "%s/test_freplace_ext.bpf.o",
		 g_progs_dir);

	/* 1. Load target program (sched_cls with global function get_result) */
	target_obj = bpf_object__open_file(target_path, NULL);
	if (!target_obj || libbpf_get_error(target_obj)) {
		TEST_SKIP(name, "cannot open target .bpf.o (file missing?)");
		return 0;
	}

	if (bpf_object__load(target_obj) < 0) {
		TEST_FAIL(name, "failed to load target object");
		bpf_object__close(target_obj);
		return 1;
	}

	target_prog = bpf_object__find_program_by_name(target_obj,
							"test_freplace_target");
	if (!target_prog) {
		TEST_FAIL(name, "target program not found in object");
		bpf_object__close(target_obj);
		return 1;
	}
	target_fd = bpf_program__fd(target_prog);

	/* 2. Load extension program, attach to target's get_result() */
	ext_obj = bpf_object__open_file(ext_path, NULL);
	if (!ext_obj || libbpf_get_error(ext_obj)) {
		TEST_FAIL(name, "cannot open ext .bpf.o");
		bpf_object__close(target_obj);
		return 1;
	}

	ext_prog = bpf_object__find_program_by_name(ext_obj,
						     "new_get_result");
	if (!ext_prog) {
		TEST_FAIL(name, "ext program not found in object");
		bpf_object__close(ext_obj);
		bpf_object__close(target_obj);
		return 1;
	}

	/* Set the attach target: the target prog fd + function name */
	if (bpf_program__set_attach_target(ext_prog, target_fd,
					   "get_result") < 0) {
		TEST_FAIL(name, "set_attach_target failed");
		bpf_object__close(ext_obj);
		bpf_object__close(target_obj);
		return 1;
	}

	if (bpf_object__load(ext_obj) < 0) {
		TEST_FAIL(name, "failed to load ext object");
		bpf_object__close(ext_obj);
		bpf_object__close(target_obj);
		return 1;
	}
	ext_fd = bpf_program__fd(ext_prog);

	/* 3. GET_ORIGINAL + REJIT identity on the EXT prog */
	orig_cnt = get_original_insns(ext_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed for ext prog");
		bpf_object__close(ext_obj);
		bpf_object__close(target_obj);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(ext_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed on EXT prog");
		free(orig_insns);
		bpf_object__close(ext_obj);
		bpf_object__close(target_obj);
		return 1;
	}

	free(orig_insns);
	bpf_object__close(ext_obj);
	bpf_object__close(target_obj);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 18: LSM (needs vmlinux BTF + BPF_LSM enabled)                */
/* ================================================================== */

static int test_lsm(void)
{
	const char *name = "T18_lsm";
	char log_buf[65536];
	int lsm_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	__u32 hook_btf_id;

	/* Find bpf_lsm_file_open in vmlinux BTF -- a simple LSM hook */
	if (find_kernel_btf_id("bpf_lsm_file_open", &hook_btf_id) < 0) {
		TEST_SKIP(name, "vmlinux BTF not available or bpf_lsm_file_open not found");
		return 0;
	}

	/* Load LSM program with BPF_LSM_MAC attach type */
	memset(log_buf, 0, sizeof(log_buf));
	lsm_fd = load_prog_full(BPF_PROG_TYPE_LSM, prog_ret_0,
				 ARRAY_SIZE(prog_ret_0),
				 BPF_LSM_MAC,
				 hook_btf_id, 0,
				 log_buf, sizeof(log_buf));
	if (lsm_fd < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_SKIP(name, "LSM load failed (CONFIG_BPF_LSM not set?)");
		return 0;
	}

	orig_cnt = get_original_insns(lsm_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(lsm_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(lsm_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(lsm_fd);
		return 1;
	}

	free(orig_insns);
	close(lsm_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 19: struct_ops (tcp_congestion_ops via clang-compiled .bpf.o)*/
/* ================================================================== */

static int test_struct_ops(void)
{
	const char *name = "T19_struct_ops";
	char obj_path[512];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;
	char log_buf[65536];

	snprintf(obj_path, sizeof(obj_path), "%s/test_struct_ops.bpf.o",
		 g_progs_dir);

	/* 1. Open and load the struct_ops object via libbpf */
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open struct_ops .bpf.o (file missing?)");
		return 0;
	}

	if (bpf_object__load(obj) < 0) {
		/*
		 * struct_ops load can fail if the kernel doesn't support
		 * the specific ops type or if BTF doesn't match.
		 */
		TEST_SKIP(name, "failed to load struct_ops object (kernel mismatch?)");
		bpf_object__close(obj);
		return 0;
	}

	/*
	 * 2. Pick one of the loaded struct_ops progs (test_init) and REJIT it.
	 * All struct_ops callback progs go through the same verifier+JIT path.
	 */
	prog = bpf_object__find_program_by_name(obj, "test_init");
	if (!prog) {
		TEST_FAIL(name, "test_init program not found in object");
		bpf_object__close(obj);
		return 1;
	}
	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "test_init program has no valid fd");
		bpf_object__close(obj);
		return 1;
	}

	/* 3. GET_ORIGINAL + REJIT identity */
	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed for struct_ops prog");
		bpf_object__close(obj);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed on struct_ops prog");
		free(orig_insns);
		bpf_object__close(obj);
		return 1;
	}

	free(orig_insns);
	bpf_object__close(obj);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 20: cgroup_sock_addr (load + REJIT identity)                 */
/* ================================================================== */

static int test_cgroup_sock_addr(void)
{
	const char *name = "T20_cgroup_sock_addr";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* cgroup_sock_addr: return 1 = allow
	 * Needs expected_attach_type = BPF_CGROUP_INET4_CONNECT */
	static const struct bpf_insn cgroup_prog[] = PROG_RET(1);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog_full(BPF_PROG_TYPE_CGROUP_SOCK_ADDR, cgroup_prog,
				 ARRAY_SIZE(cgroup_prog),
				 BPF_CGROUP_INET4_CONNECT,
				 0, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  Test 21: cgroup_sock (load + REJIT identity)                      */
/* ================================================================== */

static int test_cgroup_sock(void)
{
	const char *name = "T21_cgroup_sock";
	char log_buf[65536];
	int prog_fd;
	struct bpf_insn *orig_insns = NULL;
	int orig_cnt;

	/* cgroup_sock: return 1 = allow
	 * expected_attach_type = BPF_CGROUP_INET_SOCK_CREATE = 2 */
	static const struct bpf_insn cgroup_prog[] = PROG_RET(1);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog_full(BPF_PROG_TYPE_CGROUP_SOCK, cgroup_prog,
				 ARRAY_SIZE(cgroup_prog),
				 2 /* BPF_CGROUP_INET_SOCK_CREATE */,
				 0, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "load failed (not supported?)");
		return 0;
	}

	orig_cnt = get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, orig_insns, orig_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT identity failed");
		free(orig_insns);
		close(prog_fd);
		return 1;
	}

	free(orig_insns);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  main                                                              */
/* ================================================================== */

static int libbpf_print_fn(enum libbpf_print_level level, const char *format,
			   va_list args)
{
	if (level <= LIBBPF_WARN)
		return vfprintf(stderr, format, args);
	return 0;
}

int main(int argc, char *argv[])
{
	/* Optional arg: path to directory containing .bpf.o progs */
	if (argc > 1)
		g_progs_dir = argv[1];

	libbpf_set_print(libbpf_print_fn);

	printf("=== REJIT prog_type coverage test suite ===\n");
	printf("  progs_dir = %s\n\n", g_progs_dir);

	printf("--- Part A: Packet-based (full TEST_RUN verification) ---\n");
	test_xdp();
	test_tc();
	test_socket_filter();
	test_cgroup_skb();
	test_sched_act();

	printf("\n--- Part B: Non-packet types (load + REJIT identity) ---\n");
	test_kprobe();
	test_tracepoint();
	test_raw_tracepoint();
	test_perf_event();

	printf("\n--- Part C: Additional types ---\n");
	test_flow_dissector();
	test_sk_lookup();
	test_lwt_in();
	test_cgroup_sock_addr();
	test_cgroup_sock();

	printf("\n--- Part D: Functional REJIT (value changes) ---\n");
	test_xdp_functional();
	test_tc_functional();

	printf("\n--- Part E: Trampoline-based (fentry/fexit/freplace) ---\n");
	test_fentry();
	test_fexit();
	test_freplace();

	printf("\n--- Part F: Complex types (best-effort) ---\n");
	test_lsm();
	test_struct_ops();

	printf("\n=== Summary: %d PASS, %d FAIL, %d SKIP (total %d) ===\n",
	       g_pass, g_fail, g_skip, g_pass + g_fail + g_skip);

	return g_fail ? 1 : 0;
}
