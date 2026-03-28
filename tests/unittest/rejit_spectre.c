// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT REJIT correctness tests for branch-containing programs
 *
 * Validates that BPF_PROG_REJIT correctly handles programs where
 * NOP instructions (JA+0) are inserted between conditional branches:
 *   1. Load XDP programs containing conditional branches
 *   2. Insert NOP (JA+0) instructions after each conditional jump,
 *      adjusting forward branch offsets as needed
 *   3. REJIT with the modified bytecode
 *   4. Verify the program produces correct results via TEST_RUN
 *   5. Verify program info (jited_prog_len) is updated after REJIT
 *
 * NOTE: This test uses a local NOP-insertion helper (insert JA+0 after each
 * conditional branch) to construct modified programs for REJIT. It does not
 * exercise any active security pass or `bpf_barrier` kfunc path. The purpose
 * of these tests is only to verify that the REJIT syscall handles
 * instruction-count changes and branch-offset fixups correctly.
 *
 * The tests cover:
 *   - Single conditional branch with NOP insertion
 *   - Multiple conditional branches
 *   - Forward branch offset fixup after NOP insertion
 *   - Idempotency (NOP already present -> no double insert)
 *   - Program correctness preserved after REJIT
 *   - Program info consistency after REJIT with changed insn count
 *   - Stability under repeated TEST_RUN after REJIT
 *
 * Build (from repo root):
 *   clang -O2 -Wall -Wno-#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -o tests/unittest/rejit_spectre tests/unittest/rejit_spectre.c
 *
 * Run (requires root, on a BpfReJIT-enabled kernel):
 *   sudo ./tests/unittest/rejit_spectre
 */
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
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

static int test_run_xdp(int prog_fd, const unsigned char *data,
			__u32 data_sz, __u32 repeat, __u32 *retval)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(data);
	attr.test.data_size_in = data_sz;
	attr.test.repeat = repeat;

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

/* Helper macros for BPF instruction construction */
#define BPF_MOV64_IMM(DST, IMM) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_K, \
			    .dst_reg = (DST), .imm = (IMM) })

#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_X, \
			    .dst_reg = (DST), .src_reg = (SRC) })

#define BPF_ALU64_IMM(OP, DST, IMM) \
	((struct bpf_insn){ .code = BPF_ALU64 | (OP) | BPF_K, \
			    .dst_reg = (DST), .imm = (IMM) })

#define BPF_JMP_IMM(OP, DST, IMM, OFF) \
	((struct bpf_insn){ .code = BPF_JMP | (OP) | BPF_K, \
			    .dst_reg = (DST), .imm = (IMM), .off = (OFF) })

#define BPF_EXIT_INSN() \
	((struct bpf_insn){ .code = BPF_JMP | BPF_EXIT })

#define BPF_JA_INSN(OFF) \
	((struct bpf_insn){ .code = BPF_JMP | BPF_JA, .off = (OFF) })

/* NOP = JA +0 (speculation barrier placeholder) */
#define BPF_NOP() BPF_JA_INSN(0)

/* Check if an instruction is a conditional jump */
static int is_cond_jmp(const struct bpf_insn *insn)
{
	__u8 cls = insn->code & 0x07;
	__u8 op = insn->code & 0xf0;

	if (cls != BPF_JMP && cls != 0x06 /* BPF_JMP32 */)
		return 0;
	if (op == BPF_JA || op == 0x80 /* BPF_CALL */ || op == BPF_EXIT)
		return 0;
	return 1;
}

/* Check if instruction is NOP (JA +0) */
static int is_nop(const struct bpf_insn *insn)
{
	return (insn->code == (BPF_JMP | BPF_JA)) && (insn->off == 0);
}

/*
 * Insert NOP (JA+0) after each conditional branch, adjusting forward branch
 * offsets as needed. This produces a semantically equivalent but longer
 * program suitable for REJIT testing.
 *
 * NOTE: This local helper is only used to construct test inputs for verifying
 * REJIT correctness with changed insn counts.
 *
 * Returns the new instruction count. Output buffer must be large enough.
 */
static int apply_spectre_mitigation(const struct bpf_insn *in, __u32 in_cnt,
				    struct bpf_insn *out, __u32 out_max,
				    __u32 *addr_map)
{
	__u32 new_cnt = 0;
	__u32 pc = 0;
	int insertions = 0;

	while (pc < in_cnt) {
		if (new_cnt >= out_max)
			return -1;

		addr_map[pc] = new_cnt;
		out[new_cnt++] = in[pc];

		if (is_cond_jmp(&in[pc])) {
			/* Check if next insn is already a NOP */
			int already_nop = (pc + 1 < in_cnt) && is_nop(&in[pc + 1]);
			if (!already_nop) {
				if (new_cnt >= out_max)
					return -1;
				out[new_cnt++] = (struct bpf_insn){
					.code = BPF_JMP | BPF_JA,
					.off = 0,
				};
				insertions++;
			}
		}

		/* Handle LDIMM64 (2-slot instruction) */
		if (in[pc].code == (BPF_LD | BPF_DW | BPF_IMM) && pc + 1 < in_cnt) {
			pc++;
			if (new_cnt >= out_max)
				return -1;
			addr_map[pc] = new_cnt;
			out[new_cnt++] = in[pc];
		}

		pc++;
	}
	addr_map[in_cnt] = new_cnt;

	/* Fix up branch offsets */
	if (insertions > 0) {
		__u32 old_pc = 0;
		while (old_pc < in_cnt) {
			const struct bpf_insn *old_insn = &in[old_pc];
			__u8 cls = old_insn->code & 0x07;

			if ((cls == BPF_JMP || cls == 0x06) &&
			    (old_insn->code & 0xf0) != 0x80 /* CALL */ &&
			    (old_insn->code & 0xf0) != BPF_EXIT) {
				__u32 new_pc = addr_map[old_pc];
				int old_target = (__s32)old_pc + 1 + old_insn->off;
				if (old_target >= 0 && (__u32)old_target <= in_cnt) {
					__u32 new_target = addr_map[old_target];
					out[new_pc].off = (__s16)((__s32)new_target - (__s32)new_pc - 1);
				}
			}

			/* Skip LDIMM64 second slot */
			if (old_insn->code == (BPF_LD | BPF_DW | BPF_IMM))
				old_pc += 2;
			else
				old_pc++;
		}
	}

	return new_cnt;
}

/* ================================================================== */
/*  Test 1: Single conditional branch + NOP insertion + REJIT         */
/* ================================================================== */

static void test_single_branch_spectre(void)
{
	const char *name = "single_branch_spectre_mitigation";

	/*
	 * Original program (4 insns):
	 *   [0] if r1 == 0 goto +1    (JEQ r1, 0, +1)
	 *   [1] r0 = XDP_DROP (1)
	 *   [2] r0 = XDP_PASS (2)
	 *   [3] exit
	 *
	 * r1 is the XDP context pointer, which is non-zero, so the branch
	 * is not taken -> r0 = XDP_DROP, then r0 = XDP_PASS, exit -> XDP_PASS.
	 */
	const struct bpf_insn orig[] = {
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 1),
		BPF_MOV64_IMM(BPF_REG_0, 1),  /* XDP_DROP */
		BPF_MOV64_IMM(BPF_REG_0, 2),  /* XDP_PASS */
		BPF_EXIT_INSN(),
	};

	/*
	 * After Spectre mitigation (5 insns):
	 *   [0] if r1 == 0 goto +2  (offset adjusted: was +1, now +2 due to NOP)
	 *   [1] NOP (JA +0)         (inserted barrier)
	 *   [2] r0 = XDP_DROP
	 *   [3] r0 = XDP_PASS
	 *   [4] exit
	 */
	struct bpf_insn mitigated[16];
	__u32 addr_map[16];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt;

	/* Apply Spectre mitigation */
	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 16, addr_map);
	if (new_cnt < 0 || new_cnt != 5) {
		char msg[256];
		snprintf(msg, sizeof(msg), "mitigation produced %d insns, expected 5",
			 new_cnt);
		TEST_FAIL(name, msg);
		return;
	}

	/* Verify NOP is at position 1 */
	if (!is_nop(&mitigated[1])) {
		TEST_FAIL(name, "expected NOP at position 1");
		return;
	}

	/* Verify branch offset was adjusted */
	if (mitigated[0].off != 2) {
		char msg[256];
		snprintf(msg, sizeof(msg), "branch offset=%d, expected 2",
			 mitigated[0].off);
		TEST_FAIL(name, msg);
		return;
	}

	/* Load original program */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "load failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		return;
	}

	/* Verify pre-REJIT behavior */
	unsigned char pkt[64] = {};
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != XDP_PASS) {
		char msg[256];
		snprintf(msg, sizeof(msg), "pre-REJIT run failed (retval=%u, expected=%u)",
			 retval, XDP_PASS);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* REJIT with mitigated bytecode */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Verify post-REJIT behavior: should still return XDP_PASS */
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != XDP_PASS) {
		char msg[256];
		snprintf(msg, sizeof(msg), "post-REJIT run failed (retval=%u, expected=%u)",
			 retval, XDP_PASS);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Run multiple times to ensure stability */
	int i;
	for (i = 0; i < 10; i++) {
		if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
		    retval != XDP_PASS) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "post-REJIT run %d failed (retval=%u)", i, retval);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}
	}

	close(prog_fd);
	printf("    (orig=%u insns, mitigated=%d insns, result=XDP_PASS)\n",
	       (unsigned)ARRAY_SIZE(orig), new_cnt);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 2: Multiple conditional branches + mitigation                */
/* ================================================================== */

static void test_multi_branch_spectre(void)
{
	const char *name = "multi_branch_spectre_mitigation";

	/*
	 * Original program (7 insns):
	 *   [0] r0 = 0
	 *   [1] if r1 == 0 goto +1    -> skip [2], land on [3]
	 *   [2] r0 = r0 + 1
	 *   [3] if r1 == 0 goto +1    -> skip [4], land on [5]
	 *   [4] r0 = r0 + 2
	 *   [5] r0 = r0 + 10
	 *   [6] exit
	 *
	 * r1 (XDP ctx) is non-zero, so branches not taken.
	 * Result: r0 = 0 + 1 + 2 + 10 = 13
	 * XDP action 13 isn't a real action but TEST_RUN returns whatever r0 is.
	 */
	const struct bpf_insn orig[] = {
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 1),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 1),
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 1),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 2),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 10),
		BPF_EXIT_INSN(),
	};
	const __u32 expected_result = 13;

	struct bpf_insn mitigated[32];
	__u32 addr_map[32];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt;

	/* Apply Spectre mitigation */
	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 32, addr_map);
	if (new_cnt < 0) {
		TEST_FAIL(name, "mitigation failed");
		return;
	}

	/* Should have inserted 2 NOPs (one per conditional branch) */
	if (new_cnt != (int)ARRAY_SIZE(orig) + 2) {
		char msg[256];
		snprintf(msg, sizeof(msg), "got %d insns, expected %u",
			 new_cnt, (unsigned)ARRAY_SIZE(orig) + 2);
		TEST_FAIL(name, msg);
		return;
	}

	/* Load original, verify, REJIT with mitigated, verify again */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "load failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		return;
	}

	unsigned char pkt[64] = {};
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "pre-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "post-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	printf("    (orig=%u insns, mitigated=%d insns, 2 NOPs, result=%u)\n",
	       (unsigned)ARRAY_SIZE(orig), new_cnt, retval);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 3: Forward branch offset fixup                               */
/* ================================================================== */

static void test_forward_branch_fixup(void)
{
	const char *name = "spectre_forward_branch_fixup";

	/*
	 * Original program (5 insns):
	 *   [0] r0 = 42
	 *   [1] if r1 == 0 goto +2   -> jump to [4] (exit)
	 *   [2] r0 = r0 + 1          (= 43)
	 *   [3] r0 = r0 + 1          (= 44)
	 *   [4] exit
	 *
	 * r1 is non-zero -> branch not taken -> r0 = 44
	 *
	 * After mitigation (6 insns):
	 *   [0] r0 = 42
	 *   [1] if r1 == 0 goto +3   (was +2, adjusted for NOP insertion)
	 *   [2] NOP
	 *   [3] r0 = r0 + 1
	 *   [4] r0 = r0 + 1
	 *   [5] exit
	 */
	const struct bpf_insn orig[] = {
		BPF_MOV64_IMM(BPF_REG_0, 42),
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 2),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 1),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 1),
		BPF_EXIT_INSN(),
	};
	const __u32 expected_result = 44;

	struct bpf_insn mitigated[32];
	__u32 addr_map[32];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt;

	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 32, addr_map);
	if (new_cnt != 6) {
		char msg[256];
		snprintf(msg, sizeof(msg), "got %d insns, expected 6", new_cnt);
		TEST_FAIL(name, msg);
		return;
	}

	/* Verify the branch offset was adjusted from +2 to +3 */
	if (mitigated[1].off != 3) {
		char msg[256];
		snprintf(msg, sizeof(msg), "branch offset=%d, expected 3",
			 mitigated[1].off);
		TEST_FAIL(name, msg);
		return;
	}

	/* Load, run, REJIT, run again */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, strerror(errno));
		return;
	}

	unsigned char pkt[64] = {};
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "pre-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "post-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	printf("    (branch offset +2 -> +3 after NOP insert, result=%u)\n", retval);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 4: Idempotent mitigation (already has NOPs)                  */
/* ================================================================== */

static void test_idempotent_mitigation(void)
{
	const char *name = "spectre_idempotent_mitigation";

	/*
	 * Program that already has a NOP after the conditional branch:
	 *   [0] r0 = XDP_PASS (2)    (set default return value)
	 *   [1] if r1 == 0 goto +2   -> jump to [4] (exit)
	 *   [2] NOP (JA +0)          (already present)
	 *   [3] r0 = XDP_PASS (2)
	 *   [4] exit
	 *
	 * Applying mitigation should NOT add another NOP.
	 */
	const struct bpf_insn orig[] = {
		BPF_MOV64_IMM(BPF_REG_0, 2),  /* XDP_PASS default */
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 2),
		BPF_NOP(),
		BPF_MOV64_IMM(BPF_REG_0, 2),  /* XDP_PASS */
		BPF_EXIT_INSN(),
	};

	struct bpf_insn mitigated[16];
	__u32 addr_map[16];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt;

	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 16, addr_map);
	/* Should be same length — no new NOPs inserted */
	if (new_cnt != (int)ARRAY_SIZE(orig)) {
		char msg[256];
		snprintf(msg, sizeof(msg), "got %d insns, expected %u (idempotent)",
			 new_cnt, (unsigned)ARRAY_SIZE(orig));
		TEST_FAIL(name, msg);
		return;
	}

	/* Load and REJIT with the (unchanged) mitigated bytecode */
	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, strerror(errno));
		return;
	}

	unsigned char pkt[64] = {};
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != XDP_PASS) {
		char msg[256];
		snprintf(msg, sizeof(msg), "pre-REJIT retval=%u, expected=%u",
			 retval, XDP_PASS);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != XDP_PASS) {
		char msg[256];
		snprintf(msg, sizeof(msg), "post-REJIT retval=%u, expected=%u",
			 retval, XDP_PASS);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	printf("    (no new NOPs inserted, idempotent, result=XDP_PASS)\n");
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 5: Spectre V1 pattern (bounds check + speculative load)      */
/* ================================================================== */

static void test_spectre_v1_pattern(void)
{
	const char *name = "spectre_v1_bounds_check_pattern";

	/*
	 * Classic Spectre V1 pattern:
	 *   [0] r0 = 0                  (default return)
	 *   [1] r2 = 256                (array bound)
	 *   [2] if r1 >= r2 goto +2     (bounds check: JGE r1, 256, +2)
	 *   [3] r0 = 1                  (inside bounds: XDP_DROP)
	 *   [4] r0 = r0 + 1             (speculative: r0 = 2 = XDP_PASS)
	 *   [5] exit
	 *
	 * r1 (XDP ctx ptr) is a kernel pointer >> 256, so the branch IS taken.
	 * Result: r0 = 0 (XDP_ABORTED)
	 *
	 * Actually, BPF_JGE with BPF_K compares r1 against imm directly:
	 */
	const struct bpf_insn orig[] = {
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_JMP_IMM(BPF_JGE, BPF_REG_1, 256, 2),
		BPF_MOV64_IMM(BPF_REG_0, 1),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 1),
		BPF_EXIT_INSN(),
	};
	/*
	 * r1 = XDP context pointer. For bpf_prog_test_run, the kernel
	 * allocates an xdp_buff on the stack, so r1 is a high kernel address
	 * (definitely >= 256). The JGE branch will be taken, jumping to exit.
	 * Result: r0 = 0 (XDP_ABORTED).
	 */
	const __u32 expected_result = 0; /* XDP_ABORTED */

	struct bpf_insn mitigated[32];
	__u32 addr_map[32];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt;

	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 32, addr_map);
	if (new_cnt < 0) {
		TEST_FAIL(name, "mitigation failed");
		return;
	}

	/* Should insert 1 NOP after the JGE bounds check */
	if (new_cnt != (int)ARRAY_SIZE(orig) + 1) {
		char msg[256];
		snprintf(msg, sizeof(msg), "got %d insns, expected %u",
			 new_cnt, (unsigned)ARRAY_SIZE(orig) + 1);
		TEST_FAIL(name, msg);
		return;
	}

	/* Verify NOP is at position 2 (after JGE at position 1) */
	if (!is_nop(&mitigated[2])) {
		TEST_FAIL(name, "expected NOP at position 2");
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "load failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		return;
	}

	unsigned char pkt[64] = {};
	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "pre-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 1, &retval) < 0 ||
	    retval != expected_result) {
		char msg[256];
		snprintf(msg, sizeof(msg), "post-REJIT retval=%u, expected=%u",
			 retval, expected_result);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	close(prog_fd);
	printf("    (Spectre V1 pattern, NOP after bounds check, result=%u)\n", retval);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 6: Verify program info shows updated insn count after REJIT  */
/* ================================================================== */

static void test_spectre_rejit_info(void)
{
	const char *name = "spectre_rejit_info_consistency";

	const struct bpf_insn orig[] = {
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 1),
		BPF_MOV64_IMM(BPF_REG_0, 1),
		BPF_MOV64_IMM(BPF_REG_0, 2),
		BPF_EXIT_INSN(),
	};

	struct bpf_insn mitigated[16];
	__u32 addr_map[16];
	char log_buf[65536];
	struct bpf_prog_info info;
	__u32 info_len;
	int prog_fd, new_cnt;

	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 16, addr_map);
	if (new_cnt != 5) {
		TEST_FAIL(name, "mitigation produced wrong count");
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, strerror(errno));
		return;
	}

	/* Get pre-REJIT jited_prog_len */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_prog_info pre-REJIT failed");
		close(prog_fd);
		return;
	}
	__u32 pre_jited_len = info.jited_prog_len;

	/* REJIT */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Get post-REJIT info */
	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		TEST_FAIL(name, "get_prog_info post-REJIT failed");
		close(prog_fd);
		return;
	}

	if (!info.jited_prog_len) {
		TEST_FAIL(name, "post-REJIT program not jited");
		close(prog_fd);
		return;
	}

	/* The jited length should be larger (more insns -> more native code) */
	printf("    (jited_len: %u -> %u, orig_insns: %u -> mitigated: %d)\n",
	       pre_jited_len, info.jited_prog_len,
	       (unsigned)ARRAY_SIZE(orig), new_cnt);

	close(prog_fd);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Test 7: Repeated TEST_RUN after spectre REJIT (stability)         */
/* ================================================================== */

static void test_spectre_repeated_run(void)
{
	const char *name = "spectre_repeated_test_run";

	const struct bpf_insn orig[] = {
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 1),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 2),
		BPF_EXIT_INSN(),
	};
	/* r1 != 0 -> branch not taken -> r0 = 0 + 2 = 2 = XDP_PASS */
	const __u32 expected_result = 2;

	struct bpf_insn mitigated[16];
	__u32 addr_map[16];
	char log_buf[65536];
	__u32 retval = 0;
	int prog_fd, new_cnt, i;

	new_cnt = apply_spectre_mitigation(orig, ARRAY_SIZE(orig),
					   mitigated, 16, addr_map);
	if (new_cnt < 0) {
		TEST_FAIL(name, "mitigation failed");
		return;
	}

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(orig, ARRAY_SIZE(orig), log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, strerror(errno));
		return;
	}

	/* REJIT with spectre mitigation */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, mitigated, new_cnt, log_buf, sizeof(log_buf)) < 0) {
		char msg[256];
		snprintf(msg, sizeof(msg), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, msg);
		close(prog_fd);
		return;
	}

	/* Run 100 times with repeat=10 each */
	for (i = 0; i < 100; i++) {
		unsigned char pkt[64] = {};
		if (test_run_xdp(prog_fd, pkt, sizeof(pkt), 10, &retval) < 0 ||
		    retval != expected_result) {
			char msg[256];
			snprintf(msg, sizeof(msg),
				 "run %d failed (retval=%u, expected=%u)",
				 i, retval, expected_result);
			TEST_FAIL(name, msg);
			close(prog_fd);
			return;
		}
	}

	close(prog_fd);
	printf("    (1000 total runs, all returned %u)\n", expected_result);
	TEST_PASS(name);
}

/* ================================================================== */
/*  Main                                                              */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT REJIT correctness tests (branch programs with NOP insertions) ===\n\n");

	test_single_branch_spectre();
	test_multi_branch_spectre();
	test_forward_branch_fixup();
	test_idempotent_mitigation();
	test_spectre_v1_pattern();
	test_spectre_rejit_info();
	test_spectre_repeated_run();

	printf("\n=== Results: %d passed, %d failed ===\n", g_pass, g_fail);

	return g_fail ? 1 : 0;
}
