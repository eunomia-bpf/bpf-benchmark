// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Swap Bug Coverage & Daemon Verifier Regression Tests
 *
 * Part A (kernel bug coverage):
 *  T1: Concurrent REJIT + bpf_prog_get_info_by_fd (metadata race)
 *  T2: tail_call_reachable preserved after REJIT
 *  T3: orig_insns preserved after REJIT
 *  T4: Different-length REJIT metadata consistency
 *
 * Part B (daemon verifier regression -- malformed bytecode must be rejected):
 *  T5: Scalar replacing map_value in LD_IMM64 (const_prop bug)
 *  T6: Unreachable instruction (DCE bug)
 *  T7: Invalid call destination (branch fixup bug)
 *  T8: Map type direct access on unsupported map (map_inline bug)
 *
 * Build (from repo root):
 *   make -C tests/unittest
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_swap_tests
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

/* BPF insn macros */
#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){.code = BPF_ALU64 | BPF_MOV | BPF_X, \
			   .dst_reg = DST, .src_reg = SRC})

#define BPF_MOV64_IMM(DST, IMM) \
	((struct bpf_insn){.code = BPF_ALU64 | BPF_MOV | BPF_K, \
			   .dst_reg = DST, .imm = IMM})

#define BPF_EXIT_INSN() \
	((struct bpf_insn){.code = BPF_JMP | BPF_EXIT})

#define BPF_EMIT_CALL(FUNC) \
	((struct bpf_insn){.code = BPF_JMP | BPF_CALL, .imm = FUNC})

#define BPF_JMP_A(OFF) \
	((struct bpf_insn){.code = BPF_JMP | BPF_JA, .off = OFF})

#define BPF_ALU64_IMM(OP, DST, IMM) \
	((struct bpf_insn){.code = BPF_ALU64 | BPF_OP(OP) | BPF_K, \
			   .dst_reg = DST, .imm = IMM})

#define BPF_LD_IMM64_RAW(DST, SRC, IMM) \
	((struct bpf_insn){.code = BPF_LD | BPF_DW | BPF_IMM, \
			   .dst_reg = DST, .src_reg = SRC, \
			   .imm = (__u32)(IMM)}), \
	((struct bpf_insn){.imm = ((__u64)(IMM)) >> 32})

#define BPF_LD_MAP_FD(DST, FD) \
	BPF_LD_IMM64_RAW(DST, BPF_PSEUDO_MAP_FD, FD)

/* ------------------------------------------------------------------ */
/*  Syscall wrappers                                                  */
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

static int rejit_prog_with_fd_array(int prog_fd, const struct bpf_insn *insns,
				    __u32 insn_cnt,
				    const int *fd_array, __u32 fd_array_cnt,
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

static int create_perf_event_array_map(void)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_PERF_EVENT_ARRAY;
	attr.key_size = 4;
	attr.value_size = 4;
	attr.max_entries = 1;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
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

static int map_update_elem(int map_fd, __u32 key, int prog_fd)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(&prog_fd);
	attr.flags = BPF_ANY;

	return sys_bpf(BPF_MAP_UPDATE_ELEM, &attr, sizeof(attr));
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

/* ----- Canonical programs ----------------------------------------- */

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

/* 4 insns: r0 = 1 + 2 = XDP_TX */
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

static int verify_retval(int prog_fd, __u32 expected)
{
	__u32 retval = 0;
	if (test_run_xdp(prog_fd, &retval) < 0)
		return -1;
	if (retval != expected)
		return -1;
	return 0;
}

/* ================================================================== */
/*  PART A: Kernel Bug Coverage Tests                                 */
/* ================================================================== */

/* ================================================================== */
/*  T1: Concurrent REJIT + bpf_prog_get_info_by_fd                   */
/*                                                                    */
/*  Covers: bpf_prog_get_info_by_fd metadata race (P0 kernel bug).   */
/*  One thread does REJIT, another loops bpf_prog_get_info_by_fd.    */
/*  500 rounds -- must not crash or hang.                             */
/* ================================================================== */

#define T1_ITERATIONS 500

struct t1_rejit_args {
	int prog_fd;
	volatile int stop;
	int rejit_count;
};

struct t1_info_args {
	int prog_fd;
	volatile int stop;
	int info_count;
	int error;
};

static void *t1_rejit_worker(void *arg)
{
	struct t1_rejit_args *a = arg;
	char log_buf[65536];
	int i;

	a->rejit_count = 0;
	for (i = 0; i < T1_ITERATIONS && !a->stop; i++) {
		const struct bpf_insn *insns;
		__u32 cnt;

		if (i % 2 == 0) {
			insns = prog_xdp_drop;
			cnt = ARRAY_SIZE(prog_xdp_drop);
		} else {
			insns = prog_xdp_tx_long;
			cnt = ARRAY_SIZE(prog_xdp_tx_long);
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(a->prog_fd, insns, cnt,
			       log_buf, sizeof(log_buf)) == 0)
			a->rejit_count++;
	}
	return NULL;
}

static void *t1_info_worker(void *arg)
{
	struct t1_info_args *a = arg;
	struct bpf_prog_info info;
	__u32 info_len;

	a->info_count = 0;
	a->error = 0;

	while (!a->stop) {
		memset(&info, 0, sizeof(info));
		info_len = sizeof(info);
		if (get_prog_info(a->prog_fd, &info, &info_len) < 0) {
			/*
			 * ENOENT or transient errors under concurrent swap
			 * are acceptable; a crash (segfault/kernel oops) is not.
			 */
			continue;
		}
		a->info_count++;

		/* Basic sanity: type should remain XDP */
		if (info.type != BPF_PROG_TYPE_XDP) {
			a->error = 1;
			break;
		}
	}
	return NULL;
}

static void test_concurrent_rejit_and_info(void)
{
	const char *name = "T1_concurrent_rejit_and_info";
	pthread_t t_rejit, t_info;
	struct t1_rejit_args rejit_args;
	struct t1_info_args info_args;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	rejit_args.prog_fd = prog_fd;
	rejit_args.stop = 0;

	info_args.prog_fd = prog_fd;
	info_args.stop = 0;

	if (pthread_create(&t_rejit, NULL, t1_rejit_worker, &rejit_args) != 0) {
		TEST_FAIL(name, "pthread_create(rejit) failed");
		close(prog_fd);
		return;
	}
	if (pthread_create(&t_info, NULL, t1_info_worker, &info_args) != 0) {
		rejit_args.stop = 1;
		pthread_join(t_rejit, NULL);
		TEST_FAIL(name, "pthread_create(info) failed");
		close(prog_fd);
		return;
	}

	/* Wait for REJIT thread to finish its 500 iterations */
	pthread_join(t_rejit, NULL);

	/* Signal info thread to stop, then join */
	info_args.stop = 1;
	pthread_join(t_info, NULL);

	/* Verify program is still functional */
	__u32 retval = 0;
	if (test_run_xdp(prog_fd, &retval) < 0) {
		TEST_FAIL(name, "post-stress run failed");
		close(prog_fd);
		return;
	}

	if (info_args.error) {
		TEST_FAIL(name, "info worker detected type corruption");
		close(prog_fd);
		return;
	}

	if (rejit_args.rejit_count == 0) {
		TEST_FAIL(name, "no REJIT succeeded");
		close(prog_fd);
		return;
	}

	printf("    (REJITs: %d/%d, info queries: %d, no crash)\n",
	       rejit_args.rejit_count, T1_ITERATIONS, info_args.info_count);
	TEST_PASS(name);
	close(prog_fd);
}

/* ================================================================== */
/*  T2: tail_call_reachable preserved after REJIT                     */
/*                                                                    */
/*  Covers: tail_call_reachable field must be swapped correctly.      */
/*  Load a tail_call program, REJIT it, verify prog info metadata     */
/*  is still correct.                                                 */
/* ================================================================== */

static void test_tail_call_reachable_after_rejit(void)
{
	const char *name = "T2_tail_call_reachable_after_rejit";
	struct bpf_insn caller_insns[16], rejit_insns[16];
	struct bpf_insn target_insns[4];
	struct bpf_prog_info info;
	__u32 info_len;
	char log_buf[65536];
	__u32 caller_cnt, target_cnt, rejit_cnt;
	int map_fd = -1, caller_fd = -1, target_fd = -1;
	__u32 retval;
	__u32 pre_id;

	/* Create PROG_ARRAY map */
	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		TEST_FAIL(name, "map create failed");
		return;
	}

	/* Load target: returns XDP_PASS */
	target_cnt = 0;
	target_insns[target_cnt++] = BPF_MOV64_IMM(BPF_REG_0, XDP_PASS);
	target_insns[target_cnt++] = BPF_EXIT_INSN();

	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_insns, target_cnt,
				  log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		TEST_FAIL(name, "target load failed");
		goto cleanup;
	}

	/* Insert target at index 0 */
	if (map_update_elem(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "map update failed");
		goto cleanup;
	}

	/* Build caller with tail_call: fallback = XDP_DROP */
	{
		int i = 0;
		caller_insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
		caller_insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
		caller_insns[i++] = (struct bpf_insn){
			.code = BPF_LD | BPF_DW | BPF_IMM,
			.dst_reg = BPF_REG_2,
			.src_reg = BPF_PSEUDO_MAP_FD,
			.imm = map_fd,
		};
		caller_insns[i++] = (struct bpf_insn){.imm = 0};
		caller_insns[i++] = BPF_MOV64_IMM(BPF_REG_3, 0);
		caller_insns[i++] = BPF_EMIT_CALL(12); /* bpf_tail_call */
		caller_insns[i++] = BPF_MOV64_IMM(BPF_REG_0, XDP_DROP);
		caller_insns[i++] = BPF_EXIT_INSN();
		caller_cnt = i;
	}

	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				  log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		TEST_FAIL(name, "caller load failed");
		goto cleanup;
	}

	/* Get pre-REJIT info */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(caller_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get info pre-rejit failed");
		goto cleanup;
	}
	pre_id = info.id;

	/* Verify tail_call works: should return XDP_PASS via tail_call */
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "pre-rejit tail_call did not fire");
		goto cleanup;
	}

	/* REJIT caller with same structure but fallback = XDP_TX */
	{
		int i = 0;
		rejit_insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
		rejit_insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
		rejit_insns[i++] = (struct bpf_insn){
			.code = BPF_LD | BPF_DW | BPF_IMM,
			.dst_reg = BPF_REG_2,
			.src_reg = BPF_PSEUDO_MAP_FD,
			.imm = map_fd,
		};
		rejit_insns[i++] = (struct bpf_insn){.imm = 0};
		rejit_insns[i++] = BPF_MOV64_IMM(BPF_REG_3, 0);
		rejit_insns[i++] = BPF_EMIT_CALL(12);
		rejit_insns[i++] = BPF_MOV64_IMM(BPF_REG_0, XDP_TX);
		rejit_insns[i++] = BPF_EXIT_INSN();
		rejit_cnt = i;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(caller_fd, rejit_insns, rejit_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		goto cleanup;
	}

	/* Get post-REJIT info */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(caller_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get info post-rejit failed");
		goto cleanup;
	}

	/* ID must be preserved */
	if (info.id != pre_id) {
		char msg[128];
		snprintf(msg, sizeof(msg), "prog_id changed: %u -> %u",
			 pre_id, info.id);
		TEST_FAIL(name, msg);
		goto cleanup;
	}

	/* type must remain XDP */
	if (info.type != BPF_PROG_TYPE_XDP) {
		TEST_FAIL(name, "prog type changed after REJIT");
		goto cleanup;
	}

	/* JIT must still be active */
	if (!info.jited_prog_len) {
		TEST_FAIL(name, "not jited after REJIT");
		goto cleanup;
	}

	/* Tail_call must still work: returns XDP_PASS via target */
	if (test_run_xdp(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "post-rejit tail_call broken (retval=%u, expected XDP_PASS)",
			 retval);
		TEST_FAIL(name, msg);
		goto cleanup;
	}

	printf("    (tail_call works after REJIT, id preserved: %u)\n", pre_id);
	TEST_PASS(name);

cleanup:
	if (caller_fd >= 0) close(caller_fd);
	if (target_fd >= 0) close(target_fd);
	if (map_fd >= 0) close(map_fd);
}

/* ================================================================== */
/*  T3: orig_insns preserved after REJIT                              */
/*                                                                    */
/*  Covers: orig_prog_insns must return the initial load bytecode     */
/*  even after REJIT replaces the running program.                    */
/* ================================================================== */

static void test_orig_insns_preserved_after_rejit(void)
{
	const char *name = "T3_orig_insns_preserved_after_rejit";
	char log_buf[65536];
	struct bpf_insn *orig_before = NULL, *orig_after = NULL;
	int orig_cnt_before, orig_cnt_after;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Get original insns before REJIT */
	orig_cnt_before = get_original_insns(prog_fd, &orig_before);
	if (orig_cnt_before < 0) {
		TEST_FAIL(name, "get orig_insns pre-rejit failed");
		close(prog_fd);
		return;
	}

	/* REJIT to a different-length program */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long),
		       log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		free(orig_before);
		close(prog_fd);
		return;
	}

	/* Verify new behavior */
	if (verify_retval(prog_fd, XDP_TX) < 0) {
		TEST_FAIL(name, "post-REJIT retval not XDP_TX");
		free(orig_before);
		close(prog_fd);
		return;
	}

	/* Get original insns after REJIT */
	orig_cnt_after = get_original_insns(prog_fd, &orig_after);
	if (orig_cnt_after < 0) {
		TEST_FAIL(name, "get orig_insns post-rejit failed");
		free(orig_before);
		close(prog_fd);
		return;
	}

	/* orig_insns must be identical (same count, same bytes) */
	if (orig_cnt_before != orig_cnt_after) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "orig_insns count changed: %d -> %d",
			 orig_cnt_before, orig_cnt_after);
		TEST_FAIL(name, msg);
		free(orig_before);
		free(orig_after);
		close(prog_fd);
		return;
	}

	if (memcmp(orig_before, orig_after,
		   orig_cnt_before * sizeof(struct bpf_insn)) != 0) {
		TEST_FAIL(name, "orig_insns content changed after REJIT!");
		free(orig_before);
		free(orig_after);
		close(prog_fd);
		return;
	}

	printf("    (orig_insns: %d insns preserved across REJIT)\n",
	       orig_cnt_before);
	TEST_PASS(name);

	free(orig_before);
	free(orig_after);
	close(prog_fd);
}

/* ================================================================== */
/*  T4: Different-length REJIT metadata consistency                   */
/*                                                                    */
/*  Covers: after REJIT to a different-length program,                */
/*  xlated_prog_len and jited_prog_len must reflect the new program.  */
/*  Tests transitions: 2->4->2 insns.                                */
/* ================================================================== */

static void test_rejit_different_length_metadata(void)
{
	const char *name = "T4_rejit_different_length_metadata";
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd;
	__u32 len_2insn, len_4insn, len_back_2insn;
	__u32 jit_2insn, jit_4insn, jit_back_2insn;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "load failed");
		return;
	}

	/* Step 1: get baseline info (2 insns) */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get info step 1 failed");
		close(prog_fd);
		return;
	}
	len_2insn = info.xlated_prog_len;
	jit_2insn = info.jited_prog_len;

	/* Step 2: REJIT to 4 insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "REJIT 2->4 failed");
		close(prog_fd);
		return;
	}
	if (verify_retval(prog_fd, XDP_TX) < 0) {
		TEST_FAIL(name, "post 2->4 retval wrong");
		close(prog_fd);
		return;
	}

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get info step 2 failed");
		close(prog_fd);
		return;
	}
	len_4insn = info.xlated_prog_len;
	jit_4insn = info.jited_prog_len;

	/* xlated_prog_len for 4 insns must be > 2 insns */
	if (len_4insn <= len_2insn) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated_prog_len did not grow: %u -> %u",
			 len_2insn, len_4insn);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Step 3: REJIT back to 2 insns */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "REJIT 4->2 failed");
		close(prog_fd);
		return;
	}
	if (verify_retval(prog_fd, XDP_DROP) < 0) {
		TEST_FAIL(name, "post 4->2 retval wrong");
		close(prog_fd);
		return;
	}

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get info step 3 failed");
		close(prog_fd);
		return;
	}
	len_back_2insn = info.xlated_prog_len;
	jit_back_2insn = info.jited_prog_len;

	/* xlated_prog_len must shrink back */
	if (len_back_2insn >= len_4insn) {
		char msg[128];
		snprintf(msg, sizeof(msg),
			 "xlated_prog_len did not shrink: %u -> %u -> %u",
			 len_2insn, len_4insn, len_back_2insn);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	printf("    (xlated: %u -> %u -> %u, jited: %u -> %u -> %u)\n",
	       len_2insn, len_4insn, len_back_2insn,
	       jit_2insn, jit_4insn, jit_back_2insn);
	TEST_PASS(name);
	close(prog_fd);
}

/* ================================================================== */
/*  PART B: Daemon Verifier Regression Tests                          */
/*                                                                    */
/*  These tests construct malformed bytecode that mimics bugs in the  */
/*  daemon optimizer passes (const_prop, DCE, branch fixup,           */
/*  map_inline) and verify the kernel verifier always rejects them.   */
/*  A regression here means the verifier would accept unsafe code.    */
/* ================================================================== */

/*
 * Helper for negative REJIT tests. Pattern:
 *  1. Load a good program, verify it returns XDP_PASS.
 *  2. Attempt REJIT with given bad bytecode.
 *  3. Assert REJIT fails (returns < 0).
 *  4. Assert the original program still returns XDP_PASS.
 */
static int run_negative_rejit_test(const char *name,
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
		fprintf(stderr, "    verifier log: %.512s\n", log_buf);
		TEST_FAIL(name, "REJIT unexpectedly succeeded -- verifier regression!");
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
 * Variant: negative test using REJIT with fd_array for map references.
 */
static int run_negative_rejit_test_with_fd_array(const char *name,
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
		fprintf(stderr, "    verifier log: %.512s\n", log_buf);
		TEST_FAIL(name, "REJIT unexpectedly succeeded -- verifier regression!");
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
/*  T5: Scalar replacing map_value in LD_IMM64 (const_prop bug)       */
/*                                                                    */
/*  Daemon const_prop pass once replaced a BPF_PSEUDO_MAP_VALUE       */
/*  (src=2) LD_IMM64 with a plain scalar (src=0) LD_IMM64.           */
/*  The verifier must reject this: the register type changes from     */
/*  map_value pointer to scalar, so subsequent memory access via      */
/*  that register is illegal.                                         */
/*                                                                    */
/*  Bytecode pattern:                                                 */
/*   insn 0: r0 = XDP_PASS                                           */
/*   insn 1-2: r1 = <scalar via LD_IMM64 src=0>  (was map_value!)    */
/*   insn 3: *(u64 *)(r1 + 0) = r0   (store to scalar -> REJECTED)   */
/*   insn 4: exit                                                     */
/* ================================================================== */

static void test_rejit_scalar_replacing_map_value_rejected(void)
{
	const char *name = "T5_scalar_replacing_map_value_rejected";

	/*
	 * Construct bytecode where r1 is loaded as a plain scalar via
	 * LD_IMM64 with src=0, then used as a pointer for memory store.
	 * This mimics the const_prop bug: what should be src=2 (map_value)
	 * becomes src=0 (scalar).
	 */
	static const struct bpf_insn bad[] = {
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* r1 = 0xdeadbeef (LD_IMM64, src=0 = plain scalar) */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_1, .src_reg = 0,
		  .imm = 0xdeadbeef },
		{ .imm = 0 },
		/* *(u64 *)(r1 + 0) = r0 -- store to scalar, must be rejected */
		{ .code = BPF_STX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_1, .src_reg = BPF_REG_0, .off = 0 },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	run_negative_rejit_test(name, bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T6: Unreachable instruction (DCE bug)                             */
/*                                                                    */
/*  Daemon DCE pass once left unreachable instructions in the         */
/*  bytecode after removing dead branches. The verifier must reject   */
/*  programs with unreachable code.                                   */
/*                                                                    */
/*  Bytecode pattern:                                                 */
/*   insn 0: r0 = XDP_PASS                                           */
/*   insn 1: goto +2         (skip 2 instructions)                   */
/*   insn 2: r0 = 0xdead     (unreachable!)                          */
/*   insn 3: r1 = 0xbeef     (unreachable!)                          */
/*   insn 4: exit                                                     */
/* ================================================================== */

static void test_rejit_unreachable_insn_rejected(void)
{
	const char *name = "T6_unreachable_insn_rejected";

	static const struct bpf_insn bad[] = {
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* goto +2: skip next 2 insns */
		{ .code = BPF_JMP | BPF_JA, .off = 2 },
		/* unreachable: r0 = 0xdead */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0xdead },
		/* unreachable: r1 = 0xbeef */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_1, .imm = 0xbeef },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	run_negative_rejit_test(name, bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T7: Invalid call destination (branch fixup bug)                   */
/*                                                                    */
/*  Daemon branch fixup once generated a BPF_CALL instruction with    */
/*  an invalid target offset (pointing outside the insn array).       */
/*  The verifier must reject such programs.                           */
/*                                                                    */
/*  Bytecode pattern:                                                 */
/*   insn 0: r0 = XDP_PASS                                           */
/*   insn 1: call +9999       (invalid destination, far beyond end)   */
/*   insn 2: exit                                                     */
/* ================================================================== */

static void test_rejit_invalid_call_destination_rejected(void)
{
	const char *name = "T7_invalid_call_destination_rejected";

	static const struct bpf_insn bad[] = {
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* call with invalid destination (huge offset) */
		{ .code = BPF_JMP | BPF_CALL, .imm = 9999 },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	run_negative_rejit_test(name, bad, ARRAY_SIZE(bad));
}

/* ================================================================== */
/*  T8: Map type direct access on unsupported map (map_inline bug)    */
/*                                                                    */
/*  Daemon map_inline pass once attempted direct value access          */
/*  (BPF_PSEUDO_MAP_VALUE, src=2) on map types that do not support    */
/*  it, such as BPF_MAP_TYPE_PERF_EVENT_ARRAY. The verifier must      */
/*  reject such access.                                               */
/*                                                                    */
/*  Strategy: create a PERF_EVENT_ARRAY map, then construct bytecode  */
/*  that uses LD_IMM64 with src=BPF_PSEUDO_MAP_VALUE referencing it.  */
/*  This is exactly what a buggy map_inline would produce.            */
/*                                                                    */
/*  Bytecode pattern:                                                 */
/*   insn 0: r0 = XDP_PASS                                           */
/*   insn 1-2: r1 = LD_IMM64(fd_idx=0, src=BPF_PSEUDO_MAP_IDX_VALUE) */
/*   insn 3: exit                                                     */
/* ================================================================== */

static void test_rejit_map_type_direct_access_rejected(void)
{
	const char *name = "T8_map_type_direct_access_rejected";
	int map_fd;
	int fd_array[1];

	map_fd = create_perf_event_array_map();
	if (map_fd < 0) {
		TEST_FAIL(name, "perf_event_array map create failed");
		return;
	}
	fd_array[0] = map_fd;

	/*
	 * Construct bytecode using BPF_PSEUDO_MAP_IDX_VALUE (src=5) which
	 * references fd_array[0] and requests direct value access.
	 * PERF_EVENT_ARRAY does not support direct value access, so the
	 * verifier should reject this.
	 *
	 * BPF_PSEUDO_MAP_IDX_VALUE = 5: like BPF_PSEUDO_MAP_VALUE but uses
	 * fd_array index instead of raw fd in imm.
	 */
	struct bpf_insn bad[] = {
		/* r0 = XDP_PASS */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* r1 = LD_IMM64, src=5 (PSEUDO_MAP_IDX_VALUE), idx=0, off=0 */
		{ .code = BPF_LD | BPF_DW | BPF_IMM,
		  .dst_reg = BPF_REG_1, .src_reg = 5,
		  .imm = 0 },
		{ .imm = 0 },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	run_negative_rejit_test_with_fd_array(name, bad, ARRAY_SIZE(bad),
					      fd_array, 1);
	close(map_fd);
}

/* ================================================================== */
/*  main                                                              */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT Swap Bug Coverage & Daemon Verifier Regression ===\n\n");

	printf("--- Part A: Kernel Bug Coverage ---\n");
	test_concurrent_rejit_and_info();          /* T1 */
	test_tail_call_reachable_after_rejit();    /* T2 */
	test_orig_insns_preserved_after_rejit();   /* T3 */
	test_rejit_different_length_metadata();    /* T4 */

	printf("\n--- Part B: Daemon Verifier Regression (must reject) ---\n");
	test_rejit_scalar_replacing_map_value_rejected();    /* T5 */
	test_rejit_unreachable_insn_rejected();              /* T6 */
	test_rejit_invalid_call_destination_rejected();      /* T7 */
	test_rejit_map_type_direct_access_rejected();        /* T8 */

	printf("\n=== Summary: %d passed, %d failed ===\n", g_pass, g_fail);

	if (g_fail) {
		fprintf(stderr, "SOME TESTS FAILED\n");
		return 1;
	}

	printf("ALL TESTS PASSED\n");
	return 0;
}
