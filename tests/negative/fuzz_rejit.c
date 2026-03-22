// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Fuzz Test — Random Bytecode Fuzzing
 *
 * Proves the OSDI paper's fail-safe claim: even if the daemon is compromised
 * and sends arbitrary bytecode via BPF_PROG_REJIT, the kernel verifier rejects
 * all invalid programs and the original program remains unaffected.
 *
 * Strategy:
 *   Round N: load a legit XDP program -> generate random bytecode -> REJIT
 *            -> verify rejection -> verify original still works
 *
 * Three fuzzing modes:
 *   Mode 1: Fully random BPF instructions (pure chaos)
 *   Mode 2: Valid program skeleton with random mutations (realistic bugs)
 *   Mode 3: Random splicing of valid instruction fragments
 *
 * Usage:
 *   sudo ./fuzz_rejit [rounds] [seed]
 *     rounds: number of fuzz iterations (default: 10000)
 *     seed:   RNG seed (default: time-based)
 */
#include "common.h"

/* Maximum instructions for a fuzzed program */
#define MAX_FUZZ_INSNS 64

/* ------------------------------------------------------------------ */
/*  Mode 1: Fully random bytecode                                      */
/* ------------------------------------------------------------------ */

static void gen_fully_random(struct bpf_insn *insns, __u32 *cnt)
{
	__u32 n = 1 + (fuzz_rand32() % MAX_FUZZ_INSNS);
	__u32 i;

	for (i = 0; i < n; i++) {
		insns[i].code = (uint8_t)fuzz_rand32();
		insns[i].dst_reg = (uint8_t)(fuzz_rand32() & 0xf);
		insns[i].src_reg = (uint8_t)(fuzz_rand32() & 0xf);
		insns[i].off = (int16_t)fuzz_rand32();
		insns[i].imm = (int32_t)fuzz_rand32();
	}
	*cnt = n;
}

/* ------------------------------------------------------------------ */
/*  Mode 2: Valid skeleton + random mutations                          */
/* ------------------------------------------------------------------ */

/* Start with a valid program and randomly mutate 1-3 instructions */
static void gen_mutated_valid(struct bpf_insn *insns, __u32 *cnt)
{
	/* Base: a simple valid-ish program structure */
	static const struct bpf_insn base[] = {
		/* r0 = 42 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 42 },
		/* r1 = r0 */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X,
		  .dst_reg = BPF_REG_1, .src_reg = BPF_REG_0 },
		/* r0 += r1 */
		{ .code = BPF_ALU64 | BPF_ADD | BPF_X,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_1 },
		/* r0 &= 0xff */
		{ .code = BPF_ALU64 | BPF_AND | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0xff },
		/* if r0 > 0 goto +1 */
		{ .code = BPF_JMP | BPF_JGT | BPF_K,
		  .dst_reg = BPF_REG_0, .off = 1, .imm = 0 },
		/* r0 = XDP_DROP */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = XDP_DROP },
		/* exit */
		{ .code = BPF_JMP | BPF_EXIT },
	};

	__u32 n = ARRAY_SIZE(base);
	__u32 mutations, i;

	memcpy(insns, base, sizeof(base));
	*cnt = n;

	/* Apply 1-3 random mutations */
	mutations = 1 + (fuzz_rand32() % 3);
	for (i = 0; i < mutations; i++) {
		__u32 idx = fuzz_rand32() % n;
		__u32 field = fuzz_rand32() % 5;

		switch (field) {
		case 0: /* mutate opcode */
			insns[idx].code = (uint8_t)fuzz_rand32();
			break;
		case 1: /* mutate dst_reg */
			insns[idx].dst_reg = (uint8_t)(fuzz_rand32() & 0xf);
			break;
		case 2: /* mutate src_reg */
			insns[idx].src_reg = (uint8_t)(fuzz_rand32() & 0xf);
			break;
		case 3: /* mutate offset */
			insns[idx].off = (int16_t)fuzz_rand32();
			break;
		case 4: /* mutate imm */
			insns[idx].imm = (int32_t)fuzz_rand32();
			break;
		}
	}
}

/* ------------------------------------------------------------------ */
/*  Mode 3: Random splice of valid instruction fragments               */
/* ------------------------------------------------------------------ */

static void gen_spliced_fragments(struct bpf_insn *insns, __u32 *cnt)
{
	/* Pool of individually valid BPF instructions */
	static const struct bpf_insn pool[] = {
		/* ALU ops */
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_1, .imm = 1 },
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 7 },
		{ .code = BPF_ALU64 | BPF_SUB | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 3 },
		{ .code = BPF_ALU64 | BPF_AND | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0xff },
		{ .code = BPF_ALU64 | BPF_OR | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0x10 },
		{ .code = BPF_ALU64 | BPF_XOR | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 0xaa },
		{ .code = BPF_ALU64 | BPF_LSH | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 3 },
		{ .code = BPF_ALU64 | BPF_RSH | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 2 },
		{ .code = BPF_ALU64 | BPF_MUL | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 5 },
		{ .code = BPF_ALU | BPF_MOV | BPF_K,
		  .dst_reg = BPF_REG_0, .imm = 99 },
		/* Jumps */
		{ .code = BPF_JMP | BPF_JA, .off = 0 },
		{ .code = BPF_JMP | BPF_JEQ | BPF_K,
		  .dst_reg = BPF_REG_0, .off = 0, .imm = 0 },
		{ .code = BPF_JMP | BPF_JGT | BPF_K,
		  .dst_reg = BPF_REG_0, .off = 0, .imm = 100 },
		/* Memory (stack) */
		{ .code = BPF_STX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_10, .src_reg = BPF_REG_0, .off = -8 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW,
		  .dst_reg = BPF_REG_0, .src_reg = BPF_REG_10, .off = -8 },
		/* Exit */
		{ .code = BPF_JMP | BPF_EXIT },
		/* Helper calls (invalid for XDP) */
		{ .code = BPF_JMP | BPF_CALL, .imm = 58 },  /* bpf_override_return */
		/* Bad opcodes */
		{ .code = 0xff },
		{ .code = 0x00 },
	};
	__u32 pool_sz = ARRAY_SIZE(pool);
	__u32 n = 2 + (fuzz_rand32() % (MAX_FUZZ_INSNS - 2));
	__u32 i;

	for (i = 0; i < n; i++)
		insns[i] = pool[fuzz_rand32() % pool_sz];

	/* Randomly decide whether to terminate with EXIT */
	if (fuzz_rand32() % 2) {
		insns[n - 1].code = BPF_JMP | BPF_EXIT;
	}

	*cnt = n;
}

/* ------------------------------------------------------------------ */
/*  Main fuzz loop                                                     */
/* ------------------------------------------------------------------ */

int main(int argc, char **argv)
{
	__u32 rounds = 10000;
	uint64_t seed = 0;
	struct bpf_insn fuzz_insns[MAX_FUZZ_INSNS];
	__u32 fuzz_cnt;
	char log_buf[65536];
	__u32 retval;

	unsigned long total = 0, rejected = 0, accepted = 0;
	unsigned long original_ok = 0, original_fail = 0;
	unsigned long mode_counts[3] = {0, 0, 0};

	if (argc > 1)
		rounds = (__u32)atoi(argv[1]);
	if (argc > 2)
		seed = (uint64_t)strtoull(argv[2], NULL, 0);
	if (seed == 0)
		seed = (uint64_t)time(NULL) ^ (uint64_t)getpid();

	fuzz_seed(seed);

	printf("=== BpfReJIT Fuzz Test ===\n");
	printf("Rounds: %u, Seed: 0x%lx\n\n", rounds, (unsigned long)seed);

	for (__u32 round = 0; round < rounds; round++) {
		int prog_fd, ret;
		__u32 mode = fuzz_rand32() % 3;

		total++;
		mode_counts[mode]++;

		/* Step 1: Load a fresh good program */
		prog_fd = neg_load_good_prog();
		if (prog_fd < 0) {
			fprintf(stderr, "FATAL: cannot load base program at round %u: %s\n",
				round, strerror(errno));
			return 1;
		}

		/* Step 2: Verify it works before fuzzing */
		if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
			fprintf(stderr, "FATAL: base program broken at round %u\n", round);
			close(prog_fd);
			return 1;
		}

		/* Step 3: Generate fuzz bytecode */
		memset(fuzz_insns, 0, sizeof(fuzz_insns));
		switch (mode) {
		case 0:
			gen_fully_random(fuzz_insns, &fuzz_cnt);
			break;
		case 1:
			gen_mutated_valid(fuzz_insns, &fuzz_cnt);
			break;
		case 2:
			gen_spliced_fragments(fuzz_insns, &fuzz_cnt);
			break;
		}

		/* Step 4: Attempt REJIT */
		memset(log_buf, 0, sizeof(log_buf));
		ret = neg_rejit_prog(prog_fd, fuzz_insns, fuzz_cnt,
				     log_buf, sizeof(log_buf));

		if (ret < 0) {
			rejected++;
		} else {
			accepted++;
			/*
			 * A fuzzed program was accepted! This is not necessarily
			 * a bug -- the random bytecode may have been valid. But
			 * we still verify the program runs without crashing.
			 */
			retval = 0;
			if (neg_test_run_xdp(prog_fd, &retval) < 0) {
				fprintf(stderr,
					"WARNING: accepted fuzz prog crashed on run at round %u\n",
					round);
			}
		}

		/* Step 5: Verify original program integrity */
		/*
		 * If REJIT was rejected, the original should still return
		 * XDP_PASS. If REJIT succeeded, the program was replaced,
		 * so we just check it runs.
		 */
		if (ret < 0) {
			/* Failed REJIT -- original must be intact */
			if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
				fprintf(stderr,
					"CRITICAL: Original program corrupted after "
					"rejected REJIT at round %u (mode %u)!\n",
					round, mode);
				close(prog_fd);
				return 1;
			}
			original_ok++;
		} else {
			/* Succeeded REJIT -- just verify it runs */
			retval = 0;
			if (neg_test_run_xdp(prog_fd, &retval) >= 0) {
				original_ok++;
			} else {
				original_fail++;
				fprintf(stderr,
					"WARNING: prog not runnable after accepted "
					"REJIT at round %u\n", round);
			}
		}

		close(prog_fd);

		/* Progress */
		if ((round + 1) % 1000 == 0) {
			printf("  [%u/%u] rejected=%lu accepted=%lu\n",
			       round + 1, rounds, rejected, accepted);
		}
	}

	printf("\n=== Fuzz Test Statistics ===\n");
	printf("Total rounds:    %lu\n", total);
	printf("Rejected (good): %lu (%.1f%%)\n",
	       rejected, total ? 100.0 * rejected / total : 0.0);
	printf("Accepted:        %lu (%.1f%%)\n",
	       accepted, total ? 100.0 * accepted / total : 0.0);
	printf("Original OK:     %lu\n", original_ok);
	printf("Original fail:   %lu\n", original_fail);
	printf("Mode breakdown:  random=%lu mutated=%lu spliced=%lu\n",
	       mode_counts[0], mode_counts[1], mode_counts[2]);
	printf("Seed:            0x%lx\n", (unsigned long)seed);

	if (original_fail > 0) {
		fprintf(stderr, "\nFAIL: %lu original programs were corrupted!\n",
			original_fail);
		return 1;
	}

	printf("\nPASS: kernel verifier + REJIT maintained safety across %lu rounds\n",
	       total);
	return 0;
}
