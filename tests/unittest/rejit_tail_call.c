// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT tail_call (poke_tab) test suite
 *
 * Tests:
 *  1. REJIT a caller prog that has a tail_call (poke_tab update)
 *  2. REJIT a target prog in a PROG_ARRAY (target-side update)
 *
 * Build (from repo root):
 *   clang -O2 -Wall -Wno-#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -o tests/unittest/rejit_tail_call tests/unittest/rejit_tail_call.c
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_tail_call
 */
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

/* ---- BPF insn macros (from tools/include/linux/filter.h) ---- */
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

/* LD_IMM64 is two insns */
#define BPF_LD_IMM64_RAW(DST, SRC, IMM)                            \
	((struct bpf_insn){.code = BPF_LD | BPF_DW | BPF_IMM,      \
			   .dst_reg = DST, .src_reg = SRC,          \
			   .imm = (__u32)(IMM)}),                    \
	((struct bpf_insn){.imm = ((__u64)(IMM)) >> 32})

#define BPF_LD_MAP_FD(DST, FD) \
	BPF_LD_IMM64_RAW(DST, BPF_PSEUDO_MAP_FD, FD)

/* XDP actions */
#ifndef XDP_ABORTED
#define XDP_ABORTED 0
#define XDP_DROP    1
#define XDP_PASS    2
#define XDP_TX      3
#endif

/* ---- syscall wrappers ---- */

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

static int load_xdp_prog(struct bpf_insn *insns, __u32 insn_cnt,
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

static int rejit_prog(int prog_fd, struct bpf_insn *insns,
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

static int test_run_xdp_prog(int prog_fd, __u32 *retval)
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

static int map_delete_elem(int map_fd, __u32 key)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);

	return sys_bpf(BPF_MAP_DELETE_ELEM, &attr, sizeof(attr));
}

/*
 * Build a caller XDP prog that does:
 *   r6 = r1           (save ctx)
 *   r1 = r6           (restore ctx for tail_call)
 *   r2 = map_fd       (LD_IMM64 with BPF_PSEUDO_MAP_FD)
 *   r3 = 0            (tail_call index)
 *   call bpf_tail_call (#12)
 *   r0 = fallback_ret
 *   exit
 *
 * Returns insn_cnt. Caller must provide insns array with >= 8 entries.
 */
static __u32 build_tail_call_caller(struct bpf_insn *insns, int map_fd,
				    __u32 index, __s32 fallback_ret)
{
	int i = 0;

	/* Save ctx */
	insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);

	/* Set up tail_call args */
	insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);

	/* r2 = map_fd (LD_IMM64, two insns) */
	insns[i++] = (struct bpf_insn){
		.code = BPF_LD | BPF_DW | BPF_IMM,
		.dst_reg = BPF_REG_2,
		.src_reg = BPF_PSEUDO_MAP_FD,
		.imm = map_fd,
	};
	insns[i++] = (struct bpf_insn){.imm = 0};

	insns[i++] = BPF_MOV64_IMM(BPF_REG_3, index);

	/* call bpf_tail_call */
	insns[i++] = BPF_EMIT_CALL(12);

	/* Fallback: return value if tail_call didn't fire */
	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, fallback_ret);
	insns[i++] = BPF_EXIT_INSN();

	return i;
}

/*
 * Build a simple target XDP prog that returns a given value.
 *   r0 = retval
 *   exit
 */
static __u32 build_simple_prog(struct bpf_insn *insns, __s32 retval)
{
	int i = 0;
	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, retval);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

/* ================================================================
 * Test 1: REJIT a caller prog with tail_call (poke_tab update)
 *
 * Scenario:
 *   - caller prog does tail_call(map, 0) with fallback = XDP_DROP
 *   - target prog returns XDP_PASS
 *   - REJIT caller with same tail_call but fallback = XDP_ABORTED
 *   - Verify tail_call still works after REJIT (returns XDP_PASS)
 *   - Remove target from map, verify fallback changed to XDP_ABORTED
 * ================================================================ */
static int test_rejit_tail_call_caller(void)
{
	struct bpf_insn caller_insns[16], target_insns[4], rejit_insns[16];
	char log_buf[65536];
	__u32 caller_cnt, target_cnt, rejit_cnt;
	int map_fd = -1, caller_fd = -1, target_fd = -1;
	__u32 retval;
	int ret = 1;

	/* 1. Create PROG_ARRAY map */
	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		fprintf(stderr, "  map create failed: %s\n", strerror(errno));
		goto out;
	}

	/* 2. Load target prog: returns XDP_PASS */
	target_cnt = build_simple_prog(target_insns, XDP_PASS);
	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_insns, target_cnt,
				   log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		fprintf(stderr, "  target load failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 3. Insert target into map at index 0 */
	if (map_update_elem(map_fd, 0, target_fd) < 0) {
		fprintf(stderr, "  map update failed: %s\n", strerror(errno));
		goto out;
	}

	/* 4. Load caller prog: tail_call(map, 0), fallback = XDP_DROP */
	caller_cnt = build_tail_call_caller(caller_insns, map_fd, 0, XDP_DROP);
	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				   log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		fprintf(stderr, "  caller load failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 5. Run caller: should return XDP_PASS via tail_call */
	if (test_run_xdp_prog(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		fprintf(stderr, "  pre-rejit run: expected %u, got %u (%s)\n",
			XDP_PASS, retval, strerror(errno));
		goto out;
	}

	/* 6. REJIT caller: same tail_call but fallback = XDP_ABORTED */
	rejit_cnt = build_tail_call_caller(rejit_insns, map_fd, 0, XDP_ABORTED);
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(caller_fd, rejit_insns, rejit_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  REJIT failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 7. Run caller: tail_call should still work -> XDP_PASS */
	if (test_run_xdp_prog(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		fprintf(stderr, "  post-rejit run with target: expected %u, got %u (%s)\n",
			XDP_PASS, retval, strerror(errno));
		goto out;
	}

	/* 8. Remove target from map */
	if (map_delete_elem(map_fd, 0) < 0) {
		fprintf(stderr, "  map delete failed: %s\n", strerror(errno));
		goto out;
	}

	/* 9. Run caller: tail_call fails -> new fallback XDP_ABORTED */
	if (test_run_xdp_prog(caller_fd, &retval) < 0 || retval != XDP_ABORTED) {
		fprintf(stderr, "  post-rejit run without target: expected %u, got %u (%s)\n",
			XDP_ABORTED, retval, strerror(errno));
		goto out;
	}

	ret = 0;
out:
	if (caller_fd >= 0) close(caller_fd);
	if (target_fd >= 0) close(target_fd);
	if (map_fd >= 0) close(map_fd);
	return ret;
}

/* ================================================================
 * Test 2: REJIT a target prog in a PROG_ARRAY
 *
 * Scenario:
 *   - caller does tail_call(map, 0)
 *   - target returns XDP_PASS
 *   - REJIT target to return XDP_TX
 *   - Re-insert target into map (simulates daemon's map update)
 *   - Verify caller now gets XDP_TX via tail_call
 * ================================================================ */
static int test_rejit_tail_call_target(void)
{
	struct bpf_insn caller_insns[16], target_insns[4], rejit_insns[4];
	char log_buf[65536];
	__u32 caller_cnt, target_cnt, rejit_cnt;
	int map_fd = -1, caller_fd = -1, target_fd = -1;
	__u32 retval;
	int ret = 1;

	/* 1. Create PROG_ARRAY map */
	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		fprintf(stderr, "  map create failed: %s\n", strerror(errno));
		goto out;
	}

	/* 2. Load target prog: returns XDP_PASS */
	target_cnt = build_simple_prog(target_insns, XDP_PASS);
	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_insns, target_cnt,
				   log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		fprintf(stderr, "  target load failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 3. Insert target into map at index 0 */
	if (map_update_elem(map_fd, 0, target_fd) < 0) {
		fprintf(stderr, "  map update failed: %s\n", strerror(errno));
		goto out;
	}

	/* 4. Load caller prog: tail_call(map, 0), fallback = XDP_DROP */
	caller_cnt = build_tail_call_caller(caller_insns, map_fd, 0, XDP_DROP);
	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				   log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		fprintf(stderr, "  caller load failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 5. Run caller: should return XDP_PASS via tail_call */
	if (test_run_xdp_prog(caller_fd, &retval) < 0 || retval != XDP_PASS) {
		fprintf(stderr, "  pre-rejit run: expected %u, got %u (%s)\n",
			XDP_PASS, retval, strerror(errno));
		goto out;
	}

	/* 6. REJIT target: now returns XDP_TX.
	 *    The kernel's REJIT path automatically patches all callers'
	 *    direct-jump poke sites (two-phase: remove old, insert new).
	 *    No map re-insert needed.
	 */
	rejit_cnt = build_simple_prog(rejit_insns, XDP_TX);
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(target_fd, rejit_insns, rejit_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "  REJIT target failed: %s\n%s\n",
			strerror(errno), log_buf);
		goto out;
	}

	/* 7. Run caller: should now return XDP_TX via updated tail_call */
	if (test_run_xdp_prog(caller_fd, &retval) < 0 || retval != XDP_TX) {
		fprintf(stderr, "  post-rejit run: expected %u, got %u (%s)\n",
			XDP_TX, retval, strerror(errno));
		goto out;
	}

	ret = 0;
out:
	if (caller_fd >= 0) close(caller_fd);
	if (target_fd >= 0) close(target_fd);
	if (map_fd >= 0) close(map_fd);
	return ret;
}

int main(void)
{
	int fails = 0;

	printf("=== BpfReJIT tail_call tests ===\n\n");

	printf("test_rejit_tail_call_caller: ");
	fflush(stdout);
	if (test_rejit_tail_call_caller() == 0)
		printf("PASS\n");
	else {
		printf("FAIL\n");
		fails++;
	}

	printf("test_rejit_tail_call_target: ");
	fflush(stdout);
	if (test_rejit_tail_call_target() == 0)
		printf("PASS\n");
	else {
		printf("FAIL\n");
		fails++;
	}

	printf("\n%d/%d tests passed\n", 2 - fails, 2);
	return fails ? 1 : 0;
}
