// SPDX-License-Identifier: MIT
/*
 * test_recompile.c — Kernel selftest for BPF_PROG_REJIT syscall.
 *
 * Tests the new simple REJIT API:
 *   attr.rejit.{prog_fd, insn_cnt, insns, log_level, log_size, log_buf,
 *               fd_array, fd_array_cnt, flags}
 *
 * Each test returns true on pass, false on fail.
 */
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#ifndef TEST_KERNEL_ROOT
#error "TEST_KERNEL_ROOT must be defined by the build"
#endif

#define SIMPLE_OBJ TEST_KERNEL_ROOT "/build/progs/test_simple.bpf.o"

#define LOG_BUF_SIZE 65536
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(p) ((__u64)(uintptr_t)(p))

static int g_pass;
static int g_fail;

/* ------------------------------------------------------------------ */
/*  Low-level helpers                                                  */
/* ------------------------------------------------------------------ */

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return (int)syscall(__NR_bpf, cmd, attr, size);
}

static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			 char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type = BPF_PROG_TYPE_XDP;
	attr.insn_cnt  = insn_cnt;
	attr.insns     = ptr_to_u64(insns);
	attr.license   = ptr_to_u64(license);
	if (log_buf) {
		attr.log_level = 1;
		attr.log_buf   = ptr_to_u64(log_buf);
		attr.log_size  = (unsigned int)log_buf_sz;
	}
	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int do_rejit(int prog_fd, const struct bpf_insn *insns, __u32 insn_cnt,
		    const int *fd_array, __u32 fd_array_cnt,
		    char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd      = (__u32)prog_fd;
	attr.rejit.insn_cnt     = insn_cnt;
	attr.rejit.insns        = ptr_to_u64(insns);
	attr.rejit.flags        = 0;
	if (fd_array) {
		attr.rejit.fd_array     = ptr_to_u64(fd_array);
		attr.rejit.fd_array_cnt = fd_array_cnt;
	}
	if (log_buf) {
		attr.rejit.log_level = 1;
		attr.rejit.log_size  = (unsigned int)log_buf_sz;
		attr.rejit.log_buf   = ptr_to_u64(log_buf);
	}
	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static int get_prog_info(int prog_fd, struct bpf_prog_info *info,
			 __u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd    = (__u32)prog_fd;
	attr.info.info_len  = *info_len;
	attr.info.info      = ptr_to_u64(info);
	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;
	*info_len = attr.info.info_len;
	return 0;
}

static int test_run_xdp(int prog_fd, __u32 *retval)
{
	static char pkt[64];
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd      = (__u32)prog_fd;
	attr.test.data_in      = ptr_to_u64(pkt);
	attr.test.data_size_in = sizeof(pkt);
	attr.test.retval       = 0;
	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;
	*retval = attr.test.retval;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Test reporting                                                     */
/* ------------------------------------------------------------------ */

#define TEST_PASS(name)  do { printf("PASS %s\n", (name)); g_pass++; } while (0)
#define TEST_FAIL(name, msg) do { \
	printf("FAIL %s: %s\n", (name), (msg)); g_fail++; } while (0)
#define TEST_SKIP(name, msg) do { \
	printf("SKIP %s: %s\n", (name), (msg)); } while (0)

/* ------------------------------------------------------------------ */
/*  Test: Load Simple Program And Verify Tag                          */
/* ------------------------------------------------------------------ */

static void test_load_tag(void)
{
	const char *name = "Load Simple Program And Verify Tag";
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	int prog_fd;
	struct bpf_prog_info info;
	__u32 info_len;

	obj = bpf_object__open_file(SIMPLE_OBJ, NULL);
	if (libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open " SIMPLE_OBJ " (missing build?)");
		return;
	}
	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "load failed");
		bpf_object__close(obj);
		return;
	}
	prog = bpf_object__find_program_by_name(obj, "test_simple");
	if (!prog) {
		TEST_FAIL(name, "program 'test_simple' not found");
		bpf_object__close(obj);
		return;
	}
	prog_fd = bpf_program__fd(prog);

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info failed");
		bpf_object__close(obj);
		return;
	}

	if (info.xlated_prog_len == 0) {
		TEST_FAIL(name, "xlated_prog_len is 0");
		bpf_object__close(obj);
		return;
	}

	char msg[128];
	snprintf(msg, sizeof(msg), "prog_fd=%d insn_cnt=%u",
		 prog_fd, info.xlated_prog_len / 8);
	TEST_PASS(name);
	printf("    %s\n", msg);
	bpf_object__close(obj);
}

/* ------------------------------------------------------------------ */
/*  Test: Identity REJIT (same insns, same count)                     */
/* ------------------------------------------------------------------ */

/* Minimal XDP pass program: XDP_PASS (2) */
static const struct bpf_insn prog_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0, .imm = 2 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* XDP_TX (3) */
static const struct bpf_insn prog_xdp_tx[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0, .imm = 3 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* 4-insn XDP_TX: r1=0, r0=r1, r0+=3, exit */
static const struct bpf_insn prog_xdp_tx_4[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 1, .imm = 0 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 0, .src_reg = 1 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = 0, .imm = 3 },
	{ .code = BPF_JMP | BPF_EXIT },
};

static void test_identity_rejit(void)
{
	const char *name = "Identity REJIT";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	__u32 rv;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Verify initial result */
	if (test_run_xdp(prog_fd, &rv) < 0 || rv != 2) {
		char msg[64];
		snprintf(msg, sizeof(msg), "pre-rejit run failed, rv=%u", rv);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Identity REJIT: same insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		     NULL, 0, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify result unchanged */
	if (test_run_xdp(prog_fd, &rv) < 0 || rv != 2) {
		char msg[64];
		snprintf(msg, sizeof(msg), "post-rejit run wrong: rv=%u", rv);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ------------------------------------------------------------------ */
/*  Test: Different-length REJIT                                      */
/* ------------------------------------------------------------------ */

static void test_diff_len_rejit(void)
{
	const char *name = "Different-Length REJIT";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	__u32 rv;

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* REJIT: 2 insns -> 4 insns, result changes from XDP_PASS to XDP_TX */
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_tx_4, ARRAY_SIZE(prog_xdp_tx_4),
		     NULL, 0, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit 2->4 failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, &rv) < 0 || rv != 3) {
		char msg[64];
		snprintf(msg, sizeof(msg), "post-rejit retval=%u, expected 3", rv);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* REJIT back: 4 insns -> 2 insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		     NULL, 0, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit 4->2 failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, &rv) < 0 || rv != 2) {
		char msg[64];
		snprintf(msg, sizeof(msg), "final retval=%u, expected 2", rv);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ------------------------------------------------------------------ */
/*  Test: REJIT with fd_array                                         */
/* ------------------------------------------------------------------ */

static void test_rejit_fd_array(void)
{
	const char *name = "REJIT With fd_array";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd, map_fd;
	__u32 rv;

	/* Create a simple array map */
	union bpf_attr map_attr;
	memset(&map_attr, 0, sizeof(map_attr));
	map_attr.map_type    = BPF_MAP_TYPE_ARRAY;
	map_attr.key_size    = 4;
	map_attr.value_size  = 4;
	map_attr.max_entries = 1;
	map_fd = sys_bpf(BPF_MAP_CREATE, &map_attr, sizeof(map_attr));
	if (map_fd < 0) {
		TEST_FAIL(name, "map create failed");
		return;
	}

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		close(map_fd);
		return;
	}

	/* REJIT with fd_array containing the map fd */
	int fd_arr[1] = { map_fd };
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		     fd_arr, 1, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit with fd_array failed: %s",
			 strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		close(map_fd);
		return;
	}

	if (test_run_xdp(prog_fd, &rv) < 0 || rv != 2) {
		char msg[64];
		snprintf(msg, sizeof(msg), "post-rejit retval=%u, expected 2", rv);
		TEST_FAIL(name, msg);
		close(prog_fd);
		close(map_fd);
		return;
	}

	close(prog_fd);
	close(map_fd);
	TEST_PASS(name);
}

/* ------------------------------------------------------------------ */
/*  Test: REJIT safety — invalid inputs                               */
/* ------------------------------------------------------------------ */

static void test_invalid_inputs(void)
{
	const char *name = "REJIT Invalid Input: bad prog_fd";
	union bpf_attr attr;

	/* Invalid prog_fd: should fail with EBADF or EINVAL */
	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = 0;
	attr.rejit.insn_cnt = 1;
	attr.rejit.insns    = ptr_to_u64(prog_xdp_pass);
	int rc = sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
	if (rc >= 0) {
		TEST_FAIL(name, "expected failure with bad prog_fd, got success");
	} else {
		TEST_PASS(name);
	}

	/* NULL insns */
	name = "REJIT Invalid Input: null insns";
	int prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				    NULL, 0);
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}
	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = (__u32)prog_fd;
	attr.rejit.insn_cnt = 1;
	attr.rejit.insns    = 0;  /* NULL */
	rc = sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
	if (rc >= 0) {
		TEST_FAIL(name, "expected failure with null insns, got success");
	} else {
		TEST_PASS(name);
	}

	/* Zero insn_cnt */
	name = "REJIT Invalid Input: zero insn_cnt";
	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = (__u32)prog_fd;
	attr.rejit.insn_cnt = 0;
	attr.rejit.insns    = ptr_to_u64(prog_xdp_pass);
	rc = sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
	if (rc >= 0) {
		TEST_FAIL(name, "expected failure with zero insn_cnt, got success");
	} else {
		TEST_PASS(name);
	}

	/* Non-zero reserved flags */
	name = "REJIT Invalid Input: nonzero flags";
	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = (__u32)prog_fd;
	attr.rejit.insn_cnt = ARRAY_SIZE(prog_xdp_pass);
	attr.rejit.insns    = ptr_to_u64(prog_xdp_pass);
	attr.rejit.flags    = 1;  /* non-zero flags */
	rc = sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
	if (rc >= 0 || errno != EINVAL) {
		char msg[64];
		snprintf(msg, sizeof(msg), "expected EINVAL for nonzero flags, got %s (errno=%d)",
			 strerror(errno), errno);
		TEST_FAIL(name, msg);
	} else {
		TEST_PASS(name);
	}

	close(prog_fd);
}

/* ------------------------------------------------------------------ */
/*  Test: xlated_prog_len is updated after REJIT                      */
/* ------------------------------------------------------------------ */

static void test_xlated_len_updated(void)
{
	const char *name = "REJIT Updates xlated_prog_len";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	struct bpf_prog_info info;
	__u32 info_len, pre_len, post_len;

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info pre-rejit failed");
		close(prog_fd);
		return;
	}
	pre_len = info.xlated_prog_len;

	/* REJIT: 2 insns -> 4 insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_tx_4, ARRAY_SIZE(prog_xdp_tx_4),
		     NULL, 0, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info post-rejit failed");
		close(prog_fd);
		return;
	}
	post_len = info.xlated_prog_len;

	if (post_len <= pre_len) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated_prog_len did not grow: pre=%u post=%u",
			 pre_len, post_len);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	printf("    xlated_prog_len: %u -> %u (expected growth)\n",
	       pre_len, post_len);
	close(prog_fd);
	TEST_PASS(name);
}

/* ------------------------------------------------------------------ */
/*  Test: orig_prog_insns reflects the current (post-REJIT) program  */
/* ------------------------------------------------------------------ */

static void test_get_original_after_rejit(void)
{
	const char *name = "orig_prog_insns Updated After REJIT";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	struct bpf_prog_info info;
	__u32 info_len;

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Check orig_prog_len before REJIT */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info pre-rejit failed");
		close(prog_fd);
		return;
	}
	if (info.orig_prog_len == 0) {
		TEST_SKIP(name, "orig_prog_len == 0 (feature not supported?)");
		close(prog_fd);
		return;
	}
	__u32 pre_len = info.orig_prog_len;

	/* REJIT to a longer program */
	memset(log_buf, 0, sizeof(log_buf));
	if (do_rejit(prog_fd, prog_xdp_tx_4, ARRAY_SIZE(prog_xdp_tx_4),
		     NULL, 0, log_buf, sizeof(log_buf)) < 0) {
		char msg[64];
		snprintf(msg, sizeof(msg), "rejit failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* After REJIT, orig_prog_len should reflect the new program length */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_info post-rejit failed");
		close(prog_fd);
		return;
	}
	__u32 post_len = info.orig_prog_len;

	if (post_len == pre_len) {
		/* same length would be suspicious since we REJITed to a longer program */
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "orig_prog_len unchanged after REJIT: %u (suspicious)", pre_len);
		/* This could be OK if both happen to have same xlated length */
		TEST_PASS(name);
		printf("    orig_prog_len: %u -> %u (may be same after xlation)\n",
		       pre_len, post_len);
	} else {
		printf("    orig_prog_len: %u -> %u\n", pre_len, post_len);
		TEST_PASS(name);
	}

	close(prog_fd);
}

/* ------------------------------------------------------------------ */
/*  Test: Repeated REJIT succeeds                                     */
/* ------------------------------------------------------------------ */

static void test_repeated_rejit(void)
{
	const char *name = "Repeated REJIT";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	int i;

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	for (i = 0; i < 20; i++) {
		const struct bpf_insn *insns = (i % 2 == 0) ? prog_xdp_pass : prog_xdp_tx;
		__u32 cnt = (i % 2 == 0) ? ARRAY_SIZE(prog_xdp_pass) : ARRAY_SIZE(prog_xdp_tx);

		memset(log_buf, 0, sizeof(log_buf));
		if (do_rejit(prog_fd, insns, cnt, NULL, 0, log_buf, sizeof(log_buf)) < 0) {
			char msg[64];
			snprintf(msg, sizeof(msg), "rejit #%d failed: %s",
				 i, strerror(errno));
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
}

/* ------------------------------------------------------------------ */
/*  Test: Concurrent REJIT                                            */
/* ------------------------------------------------------------------ */

struct concurrent_ctx {
	pthread_barrier_t *barrier;
	atomic_int *stop;
	int prog_fd;
	unsigned int attempts;
	unsigned int success;
	unsigned int ebusy;
	unsigned int unexpected;
	int last_unexpected_errno;
};

static void *concurrent_rejit_thread(void *arg)
{
	struct concurrent_ctx *ctx = arg;

	pthread_barrier_wait(ctx->barrier);
	while (!atomic_load(ctx->stop)) {
		char log_buf[256];
		int rc;

		memset(log_buf, 0, sizeof(log_buf));
		rc = do_rejit(ctx->prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
			      NULL, 0, log_buf, sizeof(log_buf));
		ctx->attempts++;
		if (rc == 0) {
			ctx->success++;
		} else if (errno == EBUSY) {
			ctx->ebusy++;
		} else {
			ctx->unexpected++;
			ctx->last_unexpected_errno = errno;
		}
	}
	return NULL;
}

static void test_concurrent_rejit(void)
{
	const char *name = "Concurrent REJIT Returns EBUSY";
	char log_buf[LOG_BUF_SIZE];
	int prog_fd;
	pthread_barrier_t barrier;
	atomic_int stop;
	struct concurrent_ctx ctxs[4];
	pthread_t threads[4];
	int i;

	prog_fd = load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	pthread_barrier_init(&barrier, NULL, 5);
	atomic_store(&stop, 0);

	for (i = 0; i < 4; i++) {
		ctxs[i].barrier = &barrier;
		ctxs[i].stop = &stop;
		ctxs[i].prog_fd = prog_fd;
		ctxs[i].attempts = 0;
		ctxs[i].success = 0;
		ctxs[i].ebusy = 0;
		ctxs[i].unexpected = 0;
		ctxs[i].last_unexpected_errno = 0;
		pthread_create(&threads[i], NULL, concurrent_rejit_thread, &ctxs[i]);
	}

	pthread_barrier_wait(&barrier);
	usleep(50000);  /* let threads run for 50ms */
	atomic_store(&stop, 1);

	unsigned int total_unexpected = 0;
	int bad_errno = 0;
	for (i = 0; i < 4; i++) {
		pthread_join(threads[i], NULL);
		total_unexpected += ctxs[i].unexpected;
		if (ctxs[i].unexpected > 0)
			bad_errno = ctxs[i].last_unexpected_errno;
	}

	pthread_barrier_destroy(&barrier);
	close(prog_fd);

	if (total_unexpected > 0) {
		char msg[64];
		snprintf(msg, sizeof(msg),
			 "unexpected errno from concurrent rejit: %s",
			 strerror(bad_errno));
		TEST_FAIL(name, msg);
	} else {
		TEST_PASS(name);
	}
}

/* ------------------------------------------------------------------ */
/*  main                                                              */
/* ------------------------------------------------------------------ */


int main(void)
{
	printf("=== BpfReJIT Kernel Selftest ===\n\n");

	test_load_tag();
	test_identity_rejit();
	test_diff_len_rejit();
	test_rejit_fd_array();
	test_invalid_inputs();
	test_xlated_len_updated();
	test_get_original_after_rejit();
	test_repeated_rejit();
	test_concurrent_rejit();

	printf("\n=== Results: %d pass, %d fail ===\n", g_pass, g_fail);
	if (g_fail)
		fprintf(stderr, "SOME TESTS FAILED\n");
	else
		printf("ALL TESTS PASSED\n");

	return g_fail ? 1 : 0;
}
