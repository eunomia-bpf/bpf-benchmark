/* Included by the two-architecture kernel regression guest. */
#include "../../kinsn/module/include/native_lab_input.h"

static struct bpf_insn native_input(unsigned kind)
{
	return (struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_K,
		.src_reg = NATIVE_LAB_INPUT_SRC, .off = kind,
		.imm = NATIVE_LAB_INPUT_ABI };
}

static void input_program(const char *name, const struct bpf_insn *insns,
			  size_t count, int reject, unsigned expected)
{
	char log[16384] = {0};
	LIBBPF_OPTS(bpf_prog_load_opts, opts,
		.log_buf = log, .log_size = sizeof(log), .log_level = 2);
	int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_input", "GPL", insns, count, &opts);
	if ((fd < 0) != reject) {
		fprintf(stderr, "%s: fd=%d errno=%d\n%s", name, fd, errno, log);
		exit(1);
	}
	if (!reject) {
		struct bpf_prog_info info = {0};
		uint32_t length = sizeof(info);
		if (bpf_obj_get_info_by_fd(fd, &info, &length))
			fatal("proof input JIT info");
		assert(info.jited_prog_len);
		unsigned char packet[64] = {0};
		LIBBPF_OPTS(bpf_test_run_opts, run,
			.data_in = packet, .data_size_in = sizeof(packet), .repeat = 1);
		if (bpf_prog_test_run_opts(fd, &run))
			fatal("proof input execution");
		if (run.retval != expected) {
			fprintf(stderr, "%s: returned %u expected %u\n%s", name, run.retval, expected, log);
			exit(1);
		}
		if (close(fd))
			fatal("close proof input program");
	}
	printf("%s: PASS (%s)\n", name, reject ? "rejected" : "JIT execution");
}

static void native_input_regressions(void)
{
	const struct bpf_insn exit = { .code = BPF_JMP | BPF_EXIT };
	for (unsigned kind = 1; kind <= 3; kind++) {
		char name[96];
		/* Inputs must be real, stable invocation values, not ABI imm=2. */
		struct bpf_insn stable[] = {
			native_input(kind),
			{ .code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 6 },
			native_input(kind),
			{ .code = BPF_ALU64 | BPF_XOR | BPF_X, .src_reg = 6 }, exit,
		};
		snprintf(name, sizeof(name), "native input %u stable across reads", kind);
		input_program(name, stable, 5, 0, 0);
		struct bpf_insn nonzero[] = {
			native_input(kind),
			{ .code = BPF_ALU64 | BPF_RSH | BPF_K, .imm = 32 },
			{ .code = BPF_JMP | BPF_JEQ | BPF_K, .imm = 0, .off = 1 },
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 2 }, exit,
		};
		snprintf(name, sizeof(name), "native input %u actual nonzero address", kind);
		input_program(name, nonzero, 5, 0, 2);
		/* An ordinary MOV imm=2 would prune the invalid scalar access. */
		struct bpf_insn unsafe[] = {
			native_input(kind),
			{ .code = BPF_JMP | BPF_JEQ | BPF_K, .imm = 2, .off = 1 },
			{ .code = BPF_LDX | BPF_B | BPF_MEM }, exit,
		};
		snprintf(name, sizeof(name), "native input %u cannot prune unsafe branch as ABI constant", kind);
		input_program(name, unsafe, 4, 1, 0);
	}
	struct bpf_insn numeric[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .imm = 0x89abcdef },
		{ .imm = 0x12345678 }, native_input(NATIVE_LAB_INPUT_NUMERIC),
		{ .code = BPF_JMP | BPF_JEQ | BPF_X, .src_reg = 1, .off = 2 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 2 }, exit,
	};
	input_program("numeric input preserves all 64 source bits", numeric, 8, 0, 2);
	struct bpf_insn uninitialized[] = {
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_prandom_u32 },
		native_input(NATIVE_LAB_INPUT_NUMERIC), exit,
	};
	input_program("numeric input cannot read helper-clobbered R1", uninitialized, 3, 1, 0);
	struct bpf_insn invalid[] = { native_input(0), exit };
	input_program("native input rejects kind zero", invalid, 2, 1, 0);
	invalid[0].off = 5;
	input_program("native input rejects unknown kind", invalid, 2, 1, 0);
	invalid[0] = native_input(1); invalid[0].imm = 1;
	input_program("native input rejects old ABI", invalid, 2, 1, 0);
	invalid[0].imm = 3;
	input_program("native input rejects unknown ABI", invalid, 2, 1, 0);
	invalid[0] = native_input(1); invalid[0].dst_reg = 1;
	input_program("native input rejects destination mismatch", invalid, 2, 1, 0);
}

static void bound_native_input_regressions(void)
{
	for (unsigned kind = 1; kind <= 4; kind++) {
		char name[96];
		struct bpf_insn body[] = { native_input(kind), proof };
		seal_single_proof(body, 2);
		snprintf(name, sizeof(name), "bound native proof input %u", kind);
		load(generation(), 0, 0, name);
	}
}

static void native_input_blinding_regressions(void)
{
	char saved[16] = {0};
	int fd = open("/proc/sys/net/core/bpf_jit_harden", O_RDWR);
	if (fd < 0)
		fatal("open JIT hardening sysctl");
	ssize_t count = read(fd, saved, sizeof(saved));
	if (count <= 0 || lseek(fd, 0, SEEK_SET) < 0 || write(fd, "2", 1) != 1)
		fatal("enable constant blinding");
	puts("native inputs with forced constant blinding:");
	native_input_regressions();
	if (lseek(fd, 0, SEEK_SET) < 0 || write(fd, saved, count) != count || close(fd))
		fatal("restore JIT hardening sysctl");
}
