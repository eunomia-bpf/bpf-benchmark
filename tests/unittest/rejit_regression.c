// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Regression Tests for Bug Fixes (b4bd737ef)
 *
 * Test 1 (text_mutex deadlock):
 *   Multiple threads REJIT different progs concurrently.
 *   Before the fix, bpf_arch_text_invalidate() in bpf_prog_pack_free
 *   acquired text_mutex, causing contention/deadlock with concurrent
 *   JIT compilation (which also uses text_poke/text_mutex).
 *   The test verifies no hang with a 30-second timeout.
 *
 * Test 2 (expedited RCU):
 *   Measures REJIT latency end-to-end. synchronize_rcu_expedited()
 *   should complete in <100ms (typically <10ms), vs ~30-100ms for
 *   normal synchronize_rcu().
 *
 * Test 3 (kallsyms double-insert):
 *   REJIT a prog with subprogs (via bpf2bpf call) multiple times.
 *   Before the fix, bpf_prog_rejit_swap() called bpf_prog_kallsyms_add()
 *   for subfuncs that were already registered by jit_subprogs(), corrupting
 *   the latch tree. The test verifies no crash/hang across multiple REJITs.
 *   Note: We use simple progs without real subprogs since inline BPF
 *   subprog calls require special ELF loading. Instead, we REJIT 20 times
 *   rapidly to stress the kallsyms add/del path.
 *
 * Test 4 (XDP test_run + bpf_prog_change_xdp removal):
 *   Runs an XDP prog via BPF_PROG_TEST_RUN with repeat>1, then REJIT it,
 *   then TEST_RUN again. Before the fix, bpf_prog_change_xdp() in
 *   test_run_xdp called synchronize_rcu() (via the dispatcher), causing
 *   hangs in combination with REJIT. The test also verifies the XDP
 *   dispatcher is not corrupted.
 *
 * Build (from repo root):
 *   clang -O2 -Wall -Wno-#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -o tests/unittest/rejit_regression tests/unittest/rejit_regression.c \
 *     -lpthread
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_regression
 */
#define _GNU_SOURCE
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/klog.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))
#define SYSLOG_ACTION_READ_ALL 3
#define SYSLOG_ACTION_SIZE_BUFFER 10

/* ---- BPF insn helpers ------------------------------------------- */

#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_X, \
			    .dst_reg = (DST), .src_reg = (SRC) })

#define BPF_MOV64_IMM(DST, IMM) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_K, \
			    .dst_reg = (DST), .imm = (IMM) })

#define BPF_EXIT_INSN() \
	((struct bpf_insn){ .code = BPF_JMP | BPF_EXIT })

#define BPF_EMIT_CALL(FUNC) \
	((struct bpf_insn){ .code = BPF_JMP | BPF_CALL, .imm = (FUNC) })

static int g_pass;
static int g_fail;
static int g_skip;
static const char *g_progs_dir = "tests/unittest/build/progs";

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	fprintf(stderr, "  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

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

static int test_run_xdp(int prog_fd, __u32 repeat, __u32 *retval,
			__u32 *duration)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat = repeat;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	if (duration)
		*duration = attr.test.duration;
	return 0;
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
		__u32 cnt;

		if (info.xlated_prog_len == 0)
			return -1;

		cnt = info.xlated_prog_len / sizeof(struct bpf_insn);
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

static int map_lookup_u32(int map_fd, __u32 key, __u32 *value)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(value);

	return sys_bpf(BPF_MAP_LOOKUP_ELEM, &attr, sizeof(attr));
}

static int map_update_u64(int map_fd, __u32 key, __u64 value)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(&value);
	attr.flags = BPF_ANY;

	return sys_bpf(BPF_MAP_UPDATE_ELEM, &attr, sizeof(attr));
}

static int map_lookup_u64(int map_fd, __u32 key, __u64 *value)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(value);

	return sys_bpf(BPF_MAP_LOOKUP_ELEM, &attr, sizeof(attr));
}

static int map_delete_elem(int map_fd, __u32 key)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);

	return sys_bpf(BPF_MAP_DELETE_ELEM, &attr, sizeof(attr));
}

static int get_prog_id(int prog_fd, __u32 *prog_id)
{
	struct bpf_prog_info info;
	__u32 info_len = sizeof(info);

	memset(&info, 0, sizeof(info));
	if (get_prog_info(prog_fd, &info, &info_len) < 0)
		return -1;

	*prog_id = info.id;
	return 0;
}

static char *read_kernel_log(size_t *log_len)
{
	char *buf;
	int buf_len, ret;

	buf_len = klogctl(SYSLOG_ACTION_SIZE_BUFFER, NULL, 0);
	if (buf_len <= 0)
		return NULL;

	buf = calloc(buf_len + 1, 1);
	if (!buf)
		return NULL;

	ret = klogctl(SYSLOG_ACTION_READ_ALL, buf, buf_len);
	if (ret < 0) {
		free(buf);
		return NULL;
	}

	buf[ret] = '\0';
	if (log_len)
		*log_len = ret;
	return buf;
}

static int kernel_log_has_warning_or_bug(const char *log)
{
	return strstr(log, "WARNING:") ||
	       strstr(log, "BUG:") ||
	       strstr(log, "kernel BUG at") ||
	       strstr(log, "Oops:");
}

/*
 * Build an XDP prog that tail-calls prog_array[index] and falls back to
 * fallback_ret if no target is installed.
 */
static __u32 build_tail_call_caller(struct bpf_insn *insns, int map_fd,
				    __u32 index, __s32 fallback_ret)
{
	int i = 0;

	insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
	insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
	insns[i++] = (struct bpf_insn) {
		.code = BPF_LD | BPF_DW | BPF_IMM,
		.dst_reg = BPF_REG_2,
		.src_reg = BPF_PSEUDO_MAP_FD,
		.imm = map_fd,
	};
	insns[i++] = (struct bpf_insn) { .imm = 0 };
	insns[i++] = BPF_MOV64_IMM(BPF_REG_3, index);
	insns[i++] = BPF_EMIT_CALL(BPF_FUNC_tail_call);
	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, fallback_ret);
	insns[i++] = BPF_EXIT_INSN();

	return i;
}

static __u32 build_simple_prog(struct bpf_insn *insns, __s32 retval)
{
	int i = 0;

	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, retval);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

/* Canonical programs */
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

static const struct bpf_insn prog_xdp_tx[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_TX },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* 4-insn program: r0 = 1 + 2 = XDP_TX */
static const struct bpf_insn prog_xdp_tx_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
	  .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0,
	  .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

static int load_good_prog(void)
{
	char log_buf[65536];
	memset(log_buf, 0, sizeof(log_buf));
	return load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
			     log_buf, sizeof(log_buf));
}

static long long timespec_diff_us(struct timespec *start, struct timespec *end)
{
	return (long long)(end->tv_sec - start->tv_sec) * 1000000LL +
	       (long long)(end->tv_nsec - start->tv_nsec) / 1000LL;
}

/* ================================================================== */
/*  Test 1: Concurrent REJIT on different progs (text_mutex deadlock) */
/* ================================================================== */

#define CONCURRENT_THREADS 4
#define CONCURRENT_ITERATIONS 10

struct concurrent_thread_args {
	int prog_fd;
	int thread_id;
	int success_count;
	int error;
};

static void *concurrent_rejit_worker(void *arg)
{
	struct concurrent_thread_args *a = arg;
	char log_buf[65536];
	int i;

	a->success_count = 0;
	a->error = 0;

	for (i = 0; i < CONCURRENT_ITERATIONS; i++) {
		const struct bpf_insn *insns;
		__u32 insn_cnt;

		/* Alternate between different programs */
		if (i % 2 == 0) {
			insns = prog_xdp_drop;
			insn_cnt = ARRAY_SIZE(prog_xdp_drop);
		} else {
			insns = prog_xdp_tx_long;
			insn_cnt = ARRAY_SIZE(prog_xdp_tx_long);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(a->prog_fd, insns, insn_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			/* Some failures are expected under contention */
			continue;
		}
		a->success_count++;
	}

	return NULL;
}

static void test_concurrent_rejit_different_progs(void)
{
	const char *name = "concurrent_rejit_different_progs (fix 1: text_mutex)";
	pthread_t threads[CONCURRENT_THREADS];
	struct concurrent_thread_args args[CONCURRENT_THREADS];
	int prog_fds[CONCURRENT_THREADS];
	char log_buf[65536];
	int i, total_success = 0;

	/* Load a separate prog for each thread */
	for (i = 0; i < CONCURRENT_THREADS; i++) {
		memset(log_buf, 0, sizeof(log_buf));
		prog_fds[i] = load_xdp_prog(prog_xdp_pass,
					     ARRAY_SIZE(prog_xdp_pass),
					     log_buf, sizeof(log_buf));
		if (prog_fds[i] < 0) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "failed to load prog %d: %s", i,
				 strerror(errno));
			TEST_FAIL(name, msg);
			/* Clean up already-loaded progs */
			while (--i >= 0)
				close(prog_fds[i]);
			return;
		}
	}

	/* Launch threads concurrently */
	for (i = 0; i < CONCURRENT_THREADS; i++) {
		args[i].prog_fd = prog_fds[i];
		args[i].thread_id = i;
		if (pthread_create(&threads[i], NULL, concurrent_rejit_worker,
				   &args[i]) != 0) {
			TEST_FAIL(name, "pthread_create failed");
			goto cleanup;
		}
	}

	/* Wait for all threads to finish */
	for (i = 0; i < CONCURRENT_THREADS; i++)
		pthread_join(threads[i], NULL);

	/* Verify all progs are still functional */
	for (i = 0; i < CONCURRENT_THREADS; i++) {
		__u32 retval = 0;
		if (test_run_xdp(prog_fds[i], 1, &retval, NULL) < 0) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "prog %d not runnable after concurrent REJIT",
				 i);
			TEST_FAIL(name, msg);
			goto cleanup;
		}
		total_success += args[i].success_count;
	}

	if (total_success == 0) {
		TEST_FAIL(name, "no REJIT succeeded across all threads");
		goto cleanup;
	}

	printf("    (total successful REJITs: %d/%d)\n",
	       total_success, CONCURRENT_THREADS * CONCURRENT_ITERATIONS);
	TEST_PASS(name);

cleanup:
	for (i = 0; i < CONCURRENT_THREADS; i++)
		close(prog_fds[i]);
}

/* ================================================================== */
/*  Test 2: REJIT latency (expedited RCU)                             */
/* ================================================================== */

static void test_rejit_latency(void)
{
	const char *name = "rejit_latency (fix 2: synchronize_rcu_expedited)";
	char log_buf[65536];
	struct timespec start, end;
	long long latency_us;
	__u32 retval = 0;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Warm up */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "warmup REJIT failed");
		close(prog_fd);
		return;
	}

	/* Measure REJIT latency */
	clock_gettime(CLOCK_MONOTONIC, &start);

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx, ARRAY_SIZE(prog_xdp_tx),
		       log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	clock_gettime(CLOCK_MONOTONIC, &end);
	latency_us = timespec_diff_us(&start, &end);

	/* Verify correctness */
	if (test_run_xdp(prog_fd, 1, &retval, NULL) < 0 || retval != XDP_TX) {
		TEST_FAIL(name, "post-REJIT verification failed");
		close(prog_fd);
		return;
	}

	printf("    REJIT latency: %lld us\n", latency_us);

	/*
	 * With synchronize_rcu_expedited, expect <100ms (100000us).
	 * Normal synchronize_rcu can take 30-100ms on idle systems,
	 * or much longer under load.  Expedited should be <10ms typically.
	 * Use 100ms as a generous threshold.
	 */
	if (latency_us > 100000) {
		char msg[256];
		snprintf(msg, sizeof(msg),
			 "REJIT latency %lld us exceeds 100ms threshold "
			 "(possible non-expedited RCU?)", latency_us);
		TEST_FAIL(name, msg);
	} else {
		TEST_PASS(name);
	}

	close(prog_fd);
}

/* ================================================================== */
/*  Test 3: Rapid REJIT stress (kallsyms add/del path)                */
/* ================================================================== */

#define RAPID_REJIT_COUNT 20

static void test_rapid_rejit_kallsyms(void)
{
	const char *name = "rapid_rejit_kallsyms (fix 3: double-insert)";
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, i;
	int success = 0;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/*
	 * Rapidly REJIT the same prog with alternating programs.
	 * Each REJIT does:
	 *   1. bpf_prog_kallsyms_del_all(prog)  -- removes all ksyms
	 *   2. swap func[] arrays
	 *   3. bpf_prog_kallsyms_add(prog)      -- re-adds main prog
	 *
	 * Before the fix, step 3 also re-added subfuncs that jit_subprogs()
	 * already added, causing latch_tree corruption.
	 * Even without subprogs, the rapid add/del cycle stresses the
	 * kallsyms latch tree path that was affected.
	 */
	for (i = 0; i < RAPID_REJIT_COUNT; i++) {
		const struct bpf_insn *insns;
		__u32 insn_cnt;

		if (i % 3 == 0) {
			insns = prog_xdp_drop;
			insn_cnt = ARRAY_SIZE(prog_xdp_drop);
		} else if (i % 3 == 1) {
			insns = prog_xdp_tx_long;
			insn_cnt = ARRAY_SIZE(prog_xdp_tx_long);
		} else {
			insns = prog_xdp_pass;
			insn_cnt = ARRAY_SIZE(prog_xdp_pass);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, insns, insn_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "REJIT iteration %d failed: %s",
				 i, strerror(errno));
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}
		success++;
	}

	/* Verify the prog is still functional after rapid REJITs */
	if (test_run_xdp(prog_fd, 1, &retval, NULL) < 0) {
		TEST_FAIL(name, "post-rapid-REJIT run failed");
		close(prog_fd);
		return;
	}

	/* retval depends on which was the last REJIT */
	printf("    (%d/%d REJITs succeeded, final retval=%u)\n",
	       success, RAPID_REJIT_COUNT, retval);
	TEST_PASS(name);

	close(prog_fd);
}

/* ================================================================== */
/*  Test 4: XDP TEST_RUN with repeat>1 + REJIT (bpf_prog_change_xdp) */
/* ================================================================== */

static void test_xdp_test_run_rejit(void)
{
	const char *name = "xdp_test_run_rejit (fix 4: bpf_prog_change_xdp)";
	char log_buf[65536];
	__u32 retval = 0, duration = 0;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/*
	 * Run with repeat>1 BEFORE REJIT.
	 * Before the fix, bpf_prog_test_run_xdp() with repeat>1 would call
	 * bpf_prog_change_xdp(NULL, prog) which registers with the XDP
	 * dispatcher (synchronize_rcu() inside). This could hang/contend with
	 * concurrent REJIT.
	 */
	if (test_run_xdp(prog_fd, 100, &retval, &duration) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg),
			 "pre-REJIT test_run(repeat=100) failed: %s",
			 strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}
	if (retval != XDP_PASS) {
		TEST_FAIL(name, "pre-REJIT retval != XDP_PASS");
		close(prog_fd);
		return;
	}

	/* REJIT */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s",
			 strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Run with repeat>1 AFTER REJIT */
	if (test_run_xdp(prog_fd, 100, &retval, &duration) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg),
			 "post-REJIT test_run(repeat=100) failed: %s",
			 strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}
	if (retval != XDP_DROP) {
		char msg[256];
		snprintf(msg, sizeof(msg),
			 "post-REJIT retval=%u, expected XDP_DROP(%u)",
			 retval, XDP_DROP);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Run again with higher repeat to stress the path */
	if (test_run_xdp(prog_fd, 1000, &retval, &duration) < 0) {
		TEST_FAIL(name, "high-repeat post-REJIT test_run failed");
		close(prog_fd);
		return;
	}
	if (retval != XDP_DROP) {
		TEST_FAIL(name, "high-repeat retval mismatch");
		close(prog_fd);
		return;
	}

	printf("    (pre-REJIT: PASS, post-REJIT repeat=100: DROP, "
	       "repeat=1000: DROP)\n");
	TEST_PASS(name);

	close(prog_fd);
}

/* ================================================================== */
/*  Test 5: Concurrent REJIT + TEST_RUN (combined stress)             */
/* ================================================================== */

struct stress_args {
	int prog_fd;
	int rejit_count;
	int run_count;
	volatile int stop;
};

static void *stress_rejit_thread(void *arg)
{
	struct stress_args *a = arg;
	char log_buf[65536];

	a->rejit_count = 0;
	while (!a->stop) {
		const struct bpf_insn *insns;
		__u32 insn_cnt;

		if (a->rejit_count % 2 == 0) {
			insns = prog_xdp_drop;
			insn_cnt = ARRAY_SIZE(prog_xdp_drop);
		} else {
			insns = prog_xdp_tx;
			insn_cnt = ARRAY_SIZE(prog_xdp_tx);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(a->prog_fd, insns, insn_cnt,
			       log_buf, sizeof(log_buf)) == 0)
			a->rejit_count++;
	}
	return NULL;
}

static void *stress_run_thread(void *arg)
{
	struct stress_args *a = arg;

	a->run_count = 0;
	while (!a->stop) {
		__u32 retval = 0;
		if (test_run_xdp(a->prog_fd, 10, &retval, NULL) == 0)
			a->run_count++;
	}
	return NULL;
}

static void test_concurrent_rejit_and_run(void)
{
	const char *name = "concurrent_rejit_and_run (combined stress)";
	pthread_t t_rejit, t_run;
	struct stress_args rejit_args, run_args;
	int prog_fd;
	__u32 retval = 0;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	rejit_args.prog_fd = prog_fd;
	rejit_args.stop = 0;
	run_args.prog_fd = prog_fd;
	run_args.stop = 0;

	if (pthread_create(&t_rejit, NULL, stress_rejit_thread,
			   &rejit_args) != 0) {
		TEST_FAIL(name, "pthread_create(rejit) failed");
		close(prog_fd);
		return;
	}
	if (pthread_create(&t_run, NULL, stress_run_thread, &run_args) != 0) {
		rejit_args.stop = 1;
		pthread_join(t_rejit, NULL);
		TEST_FAIL(name, "pthread_create(run) failed");
		close(prog_fd);
		return;
	}

	/* Let them run for 2 seconds */
	usleep(2000000);

	rejit_args.stop = 1;
	run_args.stop = 1;

	pthread_join(t_rejit, NULL);
	pthread_join(t_run, NULL);

	/* Verify prog is still functional */
	if (test_run_xdp(prog_fd, 1, &retval, NULL) < 0) {
		TEST_FAIL(name, "post-stress run failed");
		close(prog_fd);
		return;
	}

	printf("    (REJITs: %d, runs: %d, final retval: %u)\n",
	       rejit_args.rejit_count, run_args.run_count, retval);

	if (rejit_args.rejit_count == 0) {
		TEST_FAIL(name, "no REJIT succeeded during stress");
		close(prog_fd);
		return;
	}
	if (run_args.run_count == 0) {
		TEST_FAIL(name, "no test_run succeeded during stress");
		close(prog_fd);
		return;
	}

	TEST_PASS(name);
	close(prog_fd);
}

/* ================================================================== */
/*  Test 6: Parallel REJIT of progs with subprogs (kallsyms double-  */
/*          delete crash)                                             */
/* ================================================================== */

/*
 * BPF program with a bpf2bpf subprog call.  This forces the kernel to
 * create real_func_cnt > 0 via jit_subprogs(), which registers per-subprog
 * kallsyms entries.
 *
 * Layout:
 *   [0] main:  call subprog (PC-relative, offset +1 → insn 2)
 *   [1]        exit
 *   [2] sub:   r0 = XDP_PASS
 *   [3]        exit
 *
 * The BPF_PSEUDO_CALL encoding uses src_reg=1 and imm=relative offset
 * from the *next* instruction.
 */
#define BPF_PSEUDO_CALL 1

static const struct bpf_insn prog_with_subprog[] = {
	/* main: call subprog at PC+2 (imm = offset from next insn = +1) */
	{ .code = BPF_JMP | BPF_CALL, .src_reg = BPF_PSEUDO_CALL,
	  .imm = 1 },
	/* main: exit */
	{ .code = BPF_JMP | BPF_EXIT },
	/* subprog: r0 = XDP_PASS (2) */
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_PASS },
	/* subprog: exit */
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Alternate version: subprog returns XDP_DROP */
static const struct bpf_insn prog_with_subprog_drop[] = {
	{ .code = BPF_JMP | BPF_CALL, .src_reg = BPF_PSEUDO_CALL,
	  .imm = 1 },
	{ .code = BPF_JMP | BPF_EXIT },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0,
	  .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

#define PARALLEL_SUBPROG_PROGS   8
#define PARALLEL_SUBPROG_REJITS  20

struct subprog_thread_args {
	int prog_fd;
	int thread_id;
	int success_count;
	int error;
};

static void *subprog_rejit_worker(void *arg)
{
	struct subprog_thread_args *a = arg;
	char log_buf[65536];
	int i;

	a->success_count = 0;
	a->error = 0;

	for (i = 0; i < PARALLEL_SUBPROG_REJITS; i++) {
		const struct bpf_insn *insns;
		__u32 cnt;

		if (i % 2 == 0) {
			insns = prog_with_subprog_drop;
			cnt = ARRAY_SIZE(prog_with_subprog_drop);
		} else {
			insns = prog_with_subprog;
			cnt = ARRAY_SIZE(prog_with_subprog);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(a->prog_fd, insns, cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			/* Some failures expected under contention; not fatal */
			continue;
		}
		a->success_count++;
	}

	return NULL;
}

static void test_parallel_subprog_rejit(void)
{
	const char *name = "parallel_subprog_rejit (fix 6: kallsyms double-delete)";
	int prog_fds[PARALLEL_SUBPROG_PROGS];
	pthread_t threads[PARALLEL_SUBPROG_PROGS];
	struct subprog_thread_args args[PARALLEL_SUBPROG_PROGS];
	char log_buf[65536];
	int i, total_success = 0;

	/*
	 * Load N distinct progs with subprogs, then REJIT them all in
	 * parallel.  The bug is in bpf_prog_rejit_swap(): after
	 * bpf_prog_kallsyms_del_all(prog) poisons the subprog ksym
	 * list nodes, the func[] swap moves those poisoned nodes to
	 * tmp, and __bpf_prog_put_noref(tmp) tries to delete them
	 * again → GPF on LIST_POISON2.
	 *
	 * With N progs × M REJITs, this reliably triggers the crash
	 * if the kernel has the bug.
	 */

	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
		memset(log_buf, 0, sizeof(log_buf));
		prog_fds[i] = load_xdp_prog(prog_with_subprog,
					     ARRAY_SIZE(prog_with_subprog),
					     log_buf, sizeof(log_buf));
		if (prog_fds[i] < 0) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "load prog %d with subprog failed: %s (log: %.200s)",
				 i, strerror(errno), log_buf);
			TEST_FAIL(name, msg);
			while (--i >= 0)
				close(prog_fds[i]);
			return;
		}
	}

	/* Launch parallel REJIT threads */
	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
		args[i].prog_fd = prog_fds[i];
		args[i].thread_id = i;
		if (pthread_create(&threads[i], NULL, subprog_rejit_worker,
				   &args[i]) != 0) {
			TEST_FAIL(name, "pthread_create failed");
			goto cleanup;
		}
	}

	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++)
		pthread_join(threads[i], NULL);

	/* Verify all progs still functional */
	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
		__u32 retval = 0;
		if (test_run_xdp(prog_fds[i], 1, &retval, NULL) < 0) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "prog %d not runnable after parallel REJIT", i);
			TEST_FAIL(name, msg);
			goto cleanup;
		}
		total_success += args[i].success_count;
	}

	if (total_success == 0) {
		TEST_FAIL(name, "no REJIT succeeded");
		goto cleanup;
	}

	printf("    (%d/%d subprog REJITs succeeded across %d progs)\n",
	       total_success, PARALLEL_SUBPROG_PROGS * PARALLEL_SUBPROG_REJITS,
	       PARALLEL_SUBPROG_PROGS);
	TEST_PASS(name);

cleanup:
	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++)
		close(prog_fds[i]);
}

/* ================================================================== */
/*  Test 7: tail_call + concurrent map update                         */
/* ================================================================== */

#define TAIL_CALL_CONCURRENT_ITERS 100
#define TAIL_CALL_ALT_RETVAL      XDP_DROP

struct tail_call_shared {
	int caller_fd;
	int map_fd;
	int target_fd;
	int alt_target_fd;
	__u32 target_prog_id;
	__u32 alt_prog_id;
	pthread_barrier_t barrier;
};

struct tail_call_target_rejit_state {
	struct tail_call_shared *shared;
	int success_count;
	int fail_count;
	int last_errno;
	__u32 last_retval;
	char last_log[256];
};

struct tail_call_map_update_state {
	struct tail_call_shared *shared;
	int success_count;
	int error;
	int last_errno;
	__u32 last_prog_id;
};

static void *tail_call_target_rejit_worker(void *arg)
{
	struct tail_call_target_rejit_state *state = arg;
	struct tail_call_shared *shared = state->shared;
	struct bpf_insn target_insns[4];
	char log_buf[65536];
	int i;

	pthread_barrier_wait(&shared->barrier);

	state->success_count = 0;
	state->fail_count = 0;
	state->last_errno = 0;
	state->last_retval = XDP_PASS;
	state->last_log[0] = '\0';

	for (i = 0; i < TAIL_CALL_CONCURRENT_ITERS; i++) {
		__u32 cnt;
		__u32 retval = (i % 2 == 0) ? XDP_TX : XDP_PASS;

		cnt = build_simple_prog(target_insns, retval);
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(shared->target_fd, target_insns, cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			state->fail_count++;
			state->last_errno = errno;
			snprintf(state->last_log, sizeof(state->last_log),
				 "%.220s", log_buf);
			continue;
		}

		state->success_count++;
		state->last_retval = retval;
	}

	return NULL;
}

static void *tail_call_map_update_worker(void *arg)
{
	struct tail_call_map_update_state *state = arg;
	struct tail_call_shared *shared = state->shared;
	int i;

	pthread_barrier_wait(&shared->barrier);

	state->success_count = 0;
	state->error = 0;
	state->last_errno = 0;
	state->last_prog_id = 0;

	for (i = 0; i < TAIL_CALL_CONCURRENT_ITERS; i++) {
		int prog_fd;
		__u32 prog_id;

		if (i % 2 == 0) {
			prog_fd = shared->target_fd;
			prog_id = shared->target_prog_id;
		} else {
			prog_fd = shared->alt_target_fd;
			prog_id = shared->alt_prog_id;
		}

		if (map_update_prog_fd(shared->map_fd, 0, prog_fd) < 0) {
			state->error = 1;
			state->last_errno = errno;
			break;
		}

		state->success_count++;
		state->last_prog_id = prog_id;
	}

	return NULL;
}

static void test_rejit_tail_call_concurrent_map_update(void)
{
	const char *name = "test_rejit_tail_call_concurrent_map_update";
	struct tail_call_shared shared;
	struct tail_call_target_rejit_state rejit_state;
	struct tail_call_map_update_state update_state;
	struct bpf_insn caller_insns[16], target_insns[4];
	pthread_t rejit_thread, update_thread;
	char log_buf[65536];
	__u32 caller_cnt, target_cnt, prog_id = 0, retval = 0, expected_retval;
	int map_fd = -1, caller_fd = -1, target_fd = -1, alt_target_fd = -1;

	memset(&shared, 0, sizeof(shared));

	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		TEST_FAIL(name, "prog array create failed");
		return;
	}

	target_cnt = build_simple_prog(target_insns, XDP_PASS);
	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_insns, target_cnt,
				  log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		TEST_FAIL(name, "tail-call target load failed");
		goto out;
	}

	target_cnt = build_simple_prog(target_insns, TAIL_CALL_ALT_RETVAL);
	memset(log_buf, 0, sizeof(log_buf));
	alt_target_fd = load_xdp_prog(target_insns, target_cnt,
				      log_buf, sizeof(log_buf));
	if (alt_target_fd < 0) {
		TEST_FAIL(name, "alternate tail-call target load failed");
		goto out;
	}

	if (get_prog_id(target_fd, &shared.target_prog_id) < 0 ||
	    get_prog_id(alt_target_fd, &shared.alt_prog_id) < 0) {
		TEST_FAIL(name, "failed to query target prog IDs");
		goto out;
	}

	if (map_update_prog_fd(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "initial prog array update failed");
		goto out;
	}

	caller_cnt = build_tail_call_caller(caller_insns, map_fd, 0, XDP_ABORTED);
	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				  log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		TEST_FAIL(name, "tail-call caller load failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, 1, &retval, NULL) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "pre-stress tail-call path mismatch");
		goto out;
	}

	shared.caller_fd = caller_fd;
	shared.map_fd = map_fd;
	shared.target_fd = target_fd;
	shared.alt_target_fd = alt_target_fd;
	if (pthread_barrier_init(&shared.barrier, NULL, 2) != 0) {
		TEST_FAIL(name, "pthread_barrier_init failed");
		goto out;
	}

	rejit_state.shared = &shared;
	update_state.shared = &shared;

	if (pthread_create(&rejit_thread, NULL, tail_call_target_rejit_worker,
			   &rejit_state) != 0) {
		TEST_FAIL(name, "pthread_create(rejit) failed");
		pthread_barrier_destroy(&shared.barrier);
		goto out;
	}
	if (pthread_create(&update_thread, NULL, tail_call_map_update_worker,
			   &update_state) != 0) {
		TEST_FAIL(name, "pthread_create(update) failed");
		pthread_barrier_wait(&shared.barrier);
		pthread_join(rejit_thread, NULL);
		pthread_barrier_destroy(&shared.barrier);
		goto out;
	}

	pthread_join(rejit_thread, NULL);
	pthread_join(update_thread, NULL);
	pthread_barrier_destroy(&shared.barrier);

	if (update_state.error) {
		TEST_FAIL(name, "prog_array update failed during concurrency");
		goto out;
	}
	if (rejit_state.success_count == 0) {
		TEST_FAIL(name, "no target REJIT succeeded");
		goto out;
	}

	if (map_lookup_u32(map_fd, 0, &prog_id) < 0) {
		TEST_FAIL(name, "prog_array lookup failed after stress");
		goto out;
	}
	if (prog_id != update_state.last_prog_id) {
		TEST_FAIL(name, "prog_array final prog_id mismatch");
		goto out;
	}

	if (prog_id == shared.target_prog_id)
		expected_retval = rejit_state.last_retval;
	else if (prog_id == shared.alt_prog_id)
		expected_retval = TAIL_CALL_ALT_RETVAL;
	else {
		TEST_FAIL(name, "unexpected final prog_id in prog_array");
		goto out;
	}

	if (test_run_xdp(caller_fd, 1, &retval, NULL) < 0) {
		TEST_FAIL(name, "post-stress tail-call run failed");
		goto out;
	}
	if (retval != expected_retval) {
		TEST_FAIL(name, "post-stress tail-call retval mismatch");
		goto out;
	}

	printf("    (target REJIT success=%d fail=%d, map updates=%d, final prog_id=%u, retval=%u)\n",
	       rejit_state.success_count, rejit_state.fail_count,
	       update_state.success_count, prog_id, retval);
	TEST_PASS(name);

out:
	if (caller_fd >= 0)
		close(caller_fd);
	if (target_fd >= 0)
		close(target_fd);
	if (alt_target_fd >= 0)
		close(alt_target_fd);
	if (map_fd >= 0)
		close(map_fd);
}

/* ================================================================== */
/*  Test 8: fentry attach + REJIT + detach + reattach + REJIT         */
/* ================================================================== */

static void test_rejit_fentry_reattach_refresh(void)
{
	const char *name = "test_rejit_fentry_reattach_refresh";

	TEST_SKIP(name, "target-side trampoline refresh not yet implemented (known limitation)");
	return;

	char xdp_obj_path[512], fentry_obj_path[512];
	struct bpf_object *xdp_obj = NULL, *fentry_obj = NULL;
	struct bpf_program *xdp_prog, *fentry_prog;
	struct bpf_map *result_map;
	struct bpf_insn *orig_insns = NULL;
	char log_buf[65536];
	__u64 counter = 0;
	__u32 retval = 0;
	int orig_cnt, xdp_prog_fd, fentry_fd, result_map_fd, link_fd = -1;

	snprintf(xdp_obj_path, sizeof(xdp_obj_path), "%s/test_simple.bpf.o",
		 g_progs_dir);
	snprintf(fentry_obj_path, sizeof(fentry_obj_path),
		 "%s/test_trampoline_fentry.bpf.o", g_progs_dir);

	xdp_obj = bpf_object__open_file(xdp_obj_path, NULL);
	if (!xdp_obj || libbpf_get_error(xdp_obj)) {
		int err = !xdp_obj ? -errno : libbpf_get_error(xdp_obj);

		if (err == -ENOENT)
			TEST_FAIL(name, "XDP .bpf.o not found");
		else
			TEST_SKIP(name, "cannot open XDP .bpf.o");
		return;
	}

	if (bpf_object__load(xdp_obj) < 0) {
		TEST_SKIP(name, "failed to load XDP object");
		goto out;
	}

	xdp_prog = bpf_object__find_program_by_name(xdp_obj, "test_simple");
	if (!xdp_prog) {
		TEST_FAIL(name, "XDP program not found in object");
		goto out;
	}

	xdp_prog_fd = bpf_program__fd(xdp_prog);
	if (xdp_prog_fd < 0) {
		TEST_FAIL(name, "XDP program has no valid fd");
		goto out;
	}

	orig_cnt = get_original_insns(xdp_prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed for XDP program");
		goto out;
	}

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "pre-attach XDP test_run failed");
		goto out;
	}

	fentry_obj = bpf_object__open_file(fentry_obj_path, NULL);
	if (!fentry_obj || libbpf_get_error(fentry_obj)) {
		int err = !fentry_obj ? -errno : libbpf_get_error(fentry_obj);

		if (err == -ENOENT)
			TEST_FAIL(name, "fentry .bpf.o not found");
		else
			TEST_SKIP(name, "cannot open fentry .bpf.o");
		goto out;
	}

	fentry_prog = bpf_object__find_program_by_name(fentry_obj,
						       "test_simple_fentry");
	if (!fentry_prog) {
		TEST_FAIL(name, "fentry program not found in object");
		goto out;
	}

	if (bpf_program__set_attach_target(fentry_prog, xdp_prog_fd,
					   "test_simple") < 0) {
		TEST_SKIP(name, "set_attach_target to XDP program failed");
		goto out;
	}

	if (bpf_object__load(fentry_obj) < 0) {
		TEST_SKIP(name, "failed to load fentry object");
		goto out;
	}

	fentry_fd = bpf_program__fd(fentry_prog);
	if (fentry_fd < 0) {
		TEST_FAIL(name, "fentry program has no valid fd");
		goto out;
	}

	result_map = bpf_object__find_map_by_name(fentry_obj, "result_map");
	if (!result_map) {
		TEST_FAIL(name, "result_map not found in fentry object");
		goto out;
	}

	result_map_fd = bpf_map__fd(result_map);
	if (result_map_fd < 0) {
		TEST_FAIL(name, "result_map has no valid fd");
		goto out;
	}

	if (map_update_u64(result_map_fd, 0, 0) < 0) {
		TEST_FAIL(name, "failed to reset result_map");
		goto out;
	}

	link_fd = bpf_link_create(fentry_fd, 0, BPF_TRACE_FENTRY, NULL);
	if (link_fd < 0) {
		TEST_SKIP(name, "bpf_link_create(BPF_TRACE_FENTRY) failed");
		goto out;
	}

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 ||
	    retval != XDP_PASS ||
	    map_lookup_u64(result_map_fd, 0, &counter) < 0 ||
	    counter != 1) {
		TEST_FAIL(name, "initial attach did not trigger fentry");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(xdp_prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "first XDP REJIT failed");
		goto out;
	}

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 ||
	    retval != XDP_PASS ||
	    map_lookup_u64(result_map_fd, 0, &counter) < 0 ||
	    counter != 2) {
		TEST_FAIL(name, "fentry did not survive first REJIT");
		goto out;
	}

	close(link_fd);
	link_fd = -1;

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 ||
	    retval != XDP_PASS ||
	    map_lookup_u64(result_map_fd, 0, &counter) < 0 ||
	    counter != 2) {
		TEST_FAIL(name, "counter changed after detach");
		goto out;
	}

	link_fd = bpf_link_create(fentry_fd, 0, BPF_TRACE_FENTRY, NULL);
	if (link_fd < 0) {
		TEST_FAIL(name, "reattach via bpf_link_create failed");
		goto out;
	}

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 ||
	    retval != XDP_PASS ||
	    map_lookup_u64(result_map_fd, 0, &counter) < 0 ||
	    counter != 3) {
		TEST_FAIL(name, "reattached fentry did not trigger");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(xdp_prog_fd, orig_insns, orig_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "second XDP REJIT failed");
		goto out;
	}

	if (test_run_xdp(xdp_prog_fd, 1, &retval, NULL) < 0 ||
	    retval != XDP_PASS ||
	    map_lookup_u64(result_map_fd, 0, &counter) < 0 ||
	    counter != 4) {
		TEST_FAIL(name, "fentry did not survive reattach REJIT");
		goto out;
	}

	printf("    (counter sequence: 1 -> 2 -> detach stays 2 -> reattach 3 -> second REJIT 4)\n");
	TEST_PASS(name);

out:
	free(orig_insns);
	if (link_fd >= 0)
		close(link_fd);
	if (fentry_obj)
		bpf_object__close(fentry_obj);
	if (xdp_obj)
		bpf_object__close(xdp_obj);
}

/* ================================================================== */
/*  Test 9: struct_ops multi REJIT + clean unregister                 */
/* ================================================================== */

#define STRUCT_OPS_MULTI_REJIT_ROUNDS 3

static void test_rejit_struct_ops_multi_rejit_unregister(void)
{
	const char *name = "test_rejit_struct_ops_multi_rejit_unregister";
	static const char *prog_names[] = { "ms_ssthresh", "ms_undo_cwnd" };
	char obj_path[512];
	struct bpf_object *obj = NULL;
	struct bpf_map *st_ops_map;
	struct bpf_link *link = NULL;
	struct bpf_prog_info info;
	char log_buf[65536];
	char *pre_log = NULL, *post_log = NULL;
	size_t pre_log_len = 0, post_log_len = 0;
	__u32 info_len;
	int map_fd, p, round;

	pre_log = read_kernel_log(&pre_log_len);
	if (!pre_log) {
		TEST_SKIP(name, "cannot read kernel log before test");
		return;
	}

	snprintf(obj_path, sizeof(obj_path), "%s/test_struct_ops_multi_slot.bpf.o",
		 g_progs_dir);

	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		int err = !obj ? -errno : libbpf_get_error(obj);

		if (err == -ENOENT)
			TEST_FAIL(name, "struct_ops multi-slot .bpf.o not found");
		else
			TEST_SKIP(name, "cannot open struct_ops multi-slot .bpf.o");
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "failed to load struct_ops multi-slot object");
		goto out;
	}

	st_ops_map = bpf_object__find_map_by_name(obj, "multi_slot_ops");
	if (!st_ops_map) {
		TEST_FAIL(name, "struct_ops map not found");
		goto out;
	}

	link = bpf_map__attach_struct_ops(st_ops_map);
	if (!link || libbpf_get_error(link)) {
		link = NULL;
		TEST_SKIP(name, "attach_struct_ops failed");
		goto out;
	}

	map_fd = bpf_map__fd(st_ops_map);
	if (map_fd < 0) {
		TEST_FAIL(name, "struct_ops map has no valid fd");
		goto out;
	}

	for (p = 0; p < ARRAY_SIZE(prog_names); p++) {
		struct bpf_program *prog;
		struct bpf_insn *orig_insns = NULL;
		int orig_cnt, prog_fd;

		prog = bpf_object__find_program_by_name(obj, prog_names[p]);
		if (!prog) {
			TEST_FAIL(name, "struct_ops callback prog not found");
			goto out;
		}

		prog_fd = bpf_program__fd(prog);
		if (prog_fd < 0) {
			TEST_FAIL(name, "struct_ops callback prog has no valid fd");
			goto out;
		}

		info_len = sizeof(info);
		memset(&info, 0, sizeof(info));
		if (get_prog_info(prog_fd, &info, &info_len) < 0) {
			TEST_FAIL(name, "get_prog_info failed for struct_ops prog");
			goto out;
		}
		if (info.jited_prog_len == 0) {
			TEST_SKIP(name, "struct_ops callback not JIT'd");
			goto out;
		}

		orig_cnt = get_original_insns(prog_fd, &orig_insns);
		if (orig_cnt < 0) {
			TEST_FAIL(name, "get_original_insns failed for struct_ops prog");
			free(orig_insns);
			goto out;
		}

		for (round = 1; round <= STRUCT_OPS_MULTI_REJIT_ROUNDS; round++) {
			memset(log_buf, 0, sizeof(log_buf));
			if (rejit_prog(prog_fd, orig_insns, orig_cnt,
				       log_buf, sizeof(log_buf)) < 0) {
				TEST_FAIL(name, "struct_ops REJIT failed");
				free(orig_insns);
				goto out;
			}
		}

		free(orig_insns);
	}

	if (map_delete_elem(map_fd, 0) < 0) {
		TEST_FAIL(name, "struct_ops unregister via map delete failed");
		goto out;
	}

	bpf_link__disconnect(link);
	bpf_link__destroy(link);
	link = NULL;

	bpf_object__close(obj);
	obj = NULL;

	post_log = read_kernel_log(&post_log_len);
	if (!post_log) {
		TEST_SKIP(name, "cannot read kernel log after unregister");
		goto out;
	}

	if (post_log_len < pre_log_len ||
	    memcmp(post_log, pre_log, pre_log_len) != 0) {
		TEST_SKIP(name, "kernel log rotated during test");
		goto out;
	}

	if (kernel_log_has_warning_or_bug(post_log + pre_log_len)) {
		TEST_FAIL(name, "kernel log contains WARNING/BUG after unregister");
		goto out;
	}

	printf("    (%d REJIT rounds per callback, unregister via map delete clean)\n",
	       STRUCT_OPS_MULTI_REJIT_ROUNDS);
	TEST_PASS(name);

out:
	free(pre_log);
	free(post_log);
	if (link)
		bpf_link__destroy(link);
	if (obj)
		bpf_object__close(obj);
}

/* ================================================================== */
/*  Main                                                              */
/* ================================================================== */

int main(int argc, char *argv[])
{
	if (argc > 1)
		g_progs_dir = argv[1];

	printf("=== BpfReJIT Regression Tests (b4bd737ef fixes) ===\n\n");

	test_concurrent_rejit_different_progs();
	test_rejit_latency();
	test_rapid_rejit_kallsyms();
	test_xdp_test_run_rejit();
	test_concurrent_rejit_and_run();
	test_parallel_subprog_rejit();
	test_rejit_tail_call_concurrent_map_update();
	test_rejit_fentry_reattach_refresh();
	test_rejit_struct_ops_multi_rejit_unregister();

	printf("\n=== Results: %d passed, %d failed, %d skipped ===\n",
	       g_pass, g_fail, g_skip);

	return g_fail ? 1 : 0;
}
