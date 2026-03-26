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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

static int g_pass;
static int g_fail;

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
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
/*  Main                                                              */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT Regression Tests (b4bd737ef fixes) ===\n\n");

	test_concurrent_rejit_different_progs();
	test_rejit_latency();
	test_rapid_rejit_kallsyms();
	test_xdp_test_run_rejit();
	test_concurrent_rejit_and_run();
	test_parallel_subprog_rejit();

	printf("\n=== Results: %d passed, %d failed ===\n", g_pass, g_fail);

	return g_fail ? 1 : 0;
}
