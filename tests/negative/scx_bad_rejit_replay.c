// SPDX-License-Identifier: GPL-2.0
/*
 * Replay the previously observed bad rewritten bytecode for scx_rusty's
 * rusty_exit struct_ops program directly through BPF_PROG_REJIT.
 *
 * Original bug: daemon incorrectly folded map-value pointer arithmetic
 * into plain LD_IMM64 scalars (src_reg=0 instead of BPF_PSEUDO_MAP_VALUE).
 * The verifier must reject this -- proves Insight 3 (fail-safe).
 *
 * Self-contained: creates its own maps and prog, no external dependencies.
 */
#include "common.h"

#ifndef BPF_PSEUDO_MAP_VALUE
#define BPF_PSEUDO_MAP_VALUE 2
#endif

static int create_array_map(__u32 value_size, __u32 max_entries)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_ARRAY;
	attr.key_size = 4;
	attr.value_size = value_size;
	attr.max_entries = max_entries;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

int main(void)
{
	char log_buf[1 << 20];
	int prog_fd, map_fd0, map_fd1, map_fd2;
	int ret, failed = 0;

	printf("=== scx_bad_rejit_replay (self-contained) ===\n");

	/* Create maps matching the original scx_rusty layout */
	map_fd0 = create_array_map(1024, 1);  /* offset 424 + 144 + 8 */
	if (map_fd0 < 0) {
		perror("create map0");
		return 1;
	}
	map_fd1 = create_array_map(8192, 1);  /* offset 4912 + 4 */
	if (map_fd1 < 0) {
		perror("create map1");
		close(map_fd0);
		return 1;
	}
	map_fd2 = create_array_map(64, 1);    /* offset 0 */
	if (map_fd2 < 0) {
		perror("create map2");
		close(map_fd1);
		close(map_fd0);
		return 1;
	}

	/* Load a good XDP program as REJIT target */
	prog_fd = neg_load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL("setup", "cannot load base prog");
		close(map_fd2);
		close(map_fd1);
		close(map_fd0);
		return 1;
	}

	/* Verify original works before REJIT attempt */
	if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL("setup", "base prog run failed");
		close(prog_fd);
		close(map_fd2);
		close(map_fd1);
		close(map_fd0);
		return 1;
	}

	/*
	 * Bad bytecode from the original scx_rusty daemon bug.
	 * Two sites have src_reg=0 instead of BPF_PSEUDO_MAP_VALUE,
	 * meaning map-value pointer + offset was folded into a plain scalar.
	 */
	struct bpf_insn bad[] = {
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_6,
		  .src_reg = BPF_REG_1, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3,
		  .src_reg = BPF_REG_6, .off = 24, .imm = 0 },

		/* valid map-value refs */
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_7,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },

		/* BUG: bad fold of map-value pointer + 16 into plain scalar */
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = 0, .off = 0, .imm = map_fd0 + 16 },
		{ .code = 0, .imm = 424 },

		{ .code = BPF_ALU | BPF_MOV | BPF_K, .dst_reg = BPF_REG_2,
		  .src_reg = 0, .off = 0, .imm = 128 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 115 },

		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },

		/* BUG: bad fold of map-value pointer + 144 into plain scalar */
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = 0, .off = 0, .imm = map_fd0 + 144 },
		{ .code = 0, .imm = 424 },

		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3,
		  .src_reg = BPF_REG_6, .off = 48, .imm = 0 },
		{ .code = BPF_ALU | BPF_MOV | BPF_K, .dst_reg = BPF_REG_2,
		  .src_reg = 0, .off = 0, .imm = 1024 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 115 },

		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd1 },
		{ .code = 0, .imm = 4912 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_2,
		  .src_reg = BPF_REG_1, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3,
		  .src_reg = BPF_REG_6, .off = 56, .imm = 0 },
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd2 },
		{ .code = 0, .imm = 0 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 115 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1,
		  .src_reg = 0, .off = 0, .imm = 1 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_REG_6, .off = 8, .imm = 0 },
		{ .code = BPF_STX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_7,
		  .src_reg = BPF_REG_1, .off = 8, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_1,
		  .src_reg = BPF_REG_6, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_0,
		  .src_reg = BPF_REG_7, .off = 0, .imm = 0 },
		{ .code = BPF_STX | BPF_ATOMIC | BPF_W, .dst_reg = BPF_REG_7,
		  .src_reg = BPF_REG_1, .off = 0, .imm = 241 },
		{ .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0,
		  .off = 0, .imm = 0 },
	};

	memset(log_buf, 0, sizeof(log_buf));
	ret = neg_rejit_prog(prog_fd, bad, ARRAY_SIZE(bad), log_buf, sizeof(log_buf));

	if (ret >= 0) {
		TEST_FAIL("bad_mapval_fold", "REJIT unexpectedly succeeded");
		failed = 1;
	} else {
		TEST_PASS("bad_mapval_fold");
	}

	/* Verify original program still works after failed REJIT */
	if (neg_verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL("post_rejit_check", "original program changed!");
		failed = 1;
	} else {
		TEST_PASS("post_rejit_check");
	}

	if (log_buf[0] != '\0')
		printf("verifier_log (first 512 chars):\n%.512s\n", log_buf);

	printf("\n%d passed, %d failed\n", g_pass, g_fail);

	close(prog_fd);
	close(map_fd2);
	close(map_fd1);
	close(map_fd0);
	return failed ? 1 : 0;
}
