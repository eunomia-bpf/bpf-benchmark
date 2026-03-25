// SPDX-License-Identifier: GPL-2.0
/*
 * Replay the previously observed bad rewritten bytecode for scx_rusty's
 * rusty_exit struct_ops program directly through BPF_PROG_REJIT.
 *
 * This bypasses daemon pass logic entirely so we can answer the kernel
 * safety-boundary question directly: does the current kernel reject the bad
 * input safely, or can it still crash?
 *
 * Usage:
 *   scx_bad_rejit_replay <prog_id> <map_id0> <map_id1> <map_id2>
 */
#include "common.h"

#ifndef BPF_PSEUDO_MAP_VALUE
#define BPF_PSEUDO_MAP_VALUE 2
#endif

static int prog_get_fd_by_id(__u32 id)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_id = id;
	return sys_bpf(BPF_PROG_GET_FD_BY_ID, &attr, sizeof(attr));
}

static int map_get_fd_by_id(__u32 id)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_id = id;
	return sys_bpf(BPF_MAP_GET_FD_BY_ID, &attr, sizeof(attr));
}

static void print_usage(const char *prog)
{
	fprintf(stderr,
		"usage: %s <prog_id> <map_id0> <map_id1> <map_id2>\n",
		prog);
}

int main(int argc, char **argv)
{
	char log_buf[1 << 20];
	__u32 prog_id, map_id0, map_id1, map_id2;
	int prog_fd, map_fd0, map_fd1, map_fd2;
	int ret;

	if (argc != 5) {
		print_usage(argv[0]);
		return 2;
	}

	prog_id = (__u32)strtoul(argv[1], NULL, 0);
	map_id0 = (__u32)strtoul(argv[2], NULL, 0);
	map_id1 = (__u32)strtoul(argv[3], NULL, 0);
	map_id2 = (__u32)strtoul(argv[4], NULL, 0);

	prog_fd = prog_get_fd_by_id(prog_id);
	if (prog_fd < 0) {
		perror("BPF_PROG_GET_FD_BY_ID");
		return 1;
	}

	map_fd0 = map_get_fd_by_id(map_id0);
	if (map_fd0 < 0) {
		perror("BPF_MAP_GET_FD_BY_ID(map0)");
		close(prog_fd);
		return 1;
	}

	map_fd1 = map_get_fd_by_id(map_id1);
	if (map_fd1 < 0) {
		perror("BPF_MAP_GET_FD_BY_ID(map1)");
		close(map_fd0);
		close(prog_fd);
		return 1;
	}

	map_fd2 = map_get_fd_by_id(map_id2);
	if (map_fd2 < 0) {
		perror("BPF_MAP_GET_FD_BY_ID(map2)");
		close(map_fd1);
		close(map_fd0);
		close(prog_fd);
		return 1;
	}

	/*
	 * This is the old bad rusty_exit rewrite observed before rebuilding the
	 * daemon. The bug was that map-value pointer arithmetic got folded into
	 * plain LD_IMM64 scalars at the two marked sites below.
	 */
	struct bpf_insn bad[] = {
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_6, .src_reg = BPF_REG_1, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3, .src_reg = BPF_REG_6, .off = 24, .imm = 0 },

		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_7, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },

		/* bad fold of map-value pointer + 16 into plain scalar ldimm64 */
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = 0, .off = 0, .imm = map_fd0 + 16 },
		{ .code = 0, .imm = 424 },

		{ .code = BPF_ALU | BPF_MOV | BPF_K, .dst_reg = BPF_REG_2, .src_reg = 0, .off = 0, .imm = 128 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 115 },

		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd0 },
		{ .code = 0, .imm = 424 },

		/* bad fold of map-value pointer + 144 into plain scalar ldimm64 */
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = 0, .off = 0, .imm = map_fd0 + 144 },
		{ .code = 0, .imm = 424 },

		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3, .src_reg = BPF_REG_6, .off = 48, .imm = 0 },
		{ .code = BPF_ALU | BPF_MOV | BPF_K, .dst_reg = BPF_REG_2, .src_reg = 0, .off = 0, .imm = 1024 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 115 },

		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd1 },
		{ .code = 0, .imm = 4912 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_2, .src_reg = BPF_REG_1, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_3, .src_reg = BPF_REG_6, .off = 56, .imm = 0 },
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = map_fd2 },
		{ .code = 0, .imm = 0 },
		{ .code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 115 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1, .src_reg = 0, .off = 0, .imm = 1 },
		{ .code = BPF_LDX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_1, .src_reg = BPF_REG_6, .off = 8, .imm = 0 },
		{ .code = BPF_STX | BPF_MEM | BPF_DW, .dst_reg = BPF_REG_7, .src_reg = BPF_REG_1, .off = 8, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_1, .src_reg = BPF_REG_6, .off = 0, .imm = 0 },
		{ .code = BPF_LDX | BPF_MEM | BPF_W, .dst_reg = BPF_REG_0, .src_reg = BPF_REG_7, .off = 0, .imm = 0 },
		{ .code = BPF_STX | BPF_ATOMIC | BPF_W, .dst_reg = BPF_REG_7, .src_reg = BPF_REG_1, .off = 0, .imm = 241 },
		{ .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0 },
	};

	memset(log_buf, 0, sizeof(log_buf));
	ret = neg_rejit_prog(prog_fd, bad, ARRAY_SIZE(bad), log_buf, sizeof(log_buf));

	printf("prog_id=%u map_ids=[%u,%u,%u]\n", prog_id, map_id0, map_id1, map_id2);
	printf("prog_fd=%d map_fds=[%d,%d,%d]\n", prog_fd, map_fd0, map_fd1, map_fd2);
	printf("rejit_ret=%d errno=%d (%s)\n", ret, errno, strerror(errno));
	if (log_buf[0] != '\0')
		printf("verifier_log:\n%s\n", log_buf);

	close(map_fd2);
	close(map_fd1);
	close(map_fd0);
	close(prog_fd);
	return ret < 0 ? 1 : 0;
}
