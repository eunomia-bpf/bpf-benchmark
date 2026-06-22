extern char stats;
#define ARM64_SIM_C_OP 1U
#define ARM64_SIM_C_JMP 2U
#define ARM64_SIM_C_JCC 3U
#define ARM64_SIM_C_CBZ 4U
#define ARM64_SIM_C_CBNZ 5U
#define ARM64_SIM_C_TBZ 6U
#define ARM64_SIM_C_TBNZ 7U
#define ARM64_SIM_C_CALL 8U
#define ARM64_SIM_C_RET 9U
#define ARM64_SIM_C_HELPER 10U

#include "../arm64_sim_local_bpf.h"

#define ARM64_SIM_C_CALL_HELPER(ID) \
	do { \
		switch (ID) { \
		default: ARM64_SIM_L_UNSUPPORTED_OPCODE(); break; \
		} \
	} while (0)

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} stats_0 SEC(".maps");

struct arm64_sim_compact_step {
	__u8 kind;
	__u8 op;
	__u8 dst;
	__u8 src;
	__u8 src2;
	__u8 src3;
	__u8 width;
	__u32 aux;
	__u64 imm;
	__u32 target;
	__u8 cond;
	__u8 helper;
};

static const struct arm64_sim_compact_step __arm64_sim_steps_bcc_vfsstat_kprobe_vfs_open[] = {
	{ ARM64_SIM_C_OP, ARM64_OP_ADRP_GOT, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)&stats_0), 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 24ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X9, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 1ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_STLXR, ARM64_X10, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0, 0U, 0, 0 },
	{ ARM64_SIM_C_CBNZ, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_X10, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0, 3U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_JMP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 10U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
};

SEC("xdp")
int bcc_vfsstat_kprobe_vfs_open_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	__u32 __a64_c_pc = 0;
	__u32 __a64_c_guard_limit = 88U;
	#pragma clang loop unroll(disable)
	for (__u32 __a64_c_guard = 0; __a64_c_guard < __a64_c_guard_limit; __a64_c_guard++) {
		if (__a64_c_pc >= 11U)
			break;
		const struct arm64_sim_compact_step *__a64_c_step = &__arm64_sim_steps_bcc_vfsstat_kprobe_vfs_open[__a64_c_pc];
		__u8 __a64_c_kind = __a64_c_step->kind;
		__u8 __a64_c_op = __a64_c_step->op;
		__u8 __a64_c_dst = __a64_c_step->dst;
		__u8 __a64_c_src = __a64_c_step->src;
		__u8 __a64_c_src2 = __a64_c_step->src2;
		__u8 __a64_c_src3 = __a64_c_step->src3;
		__u8 __a64_c_width = __a64_c_step->width;
		__u32 __a64_c_aux = __a64_c_step->aux;
		__u64 __a64_c_imm = __a64_c_step->imm;
		__u32 __a64_c_target = __a64_c_step->target;
		__u8 __a64_c_cond = __a64_c_step->cond;
		__u8 __a64_c_helper = __a64_c_step->helper;
		if (__a64_c_kind == ARM64_SIM_C_OP) {
			switch (__a64_c_op) {
			case ARM64_OP_ADRP_GOT:
				ARM64_SIM_L_EXEC(ARM64_OP_ADRP_GOT, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_ALU_IMM:
				ARM64_SIM_L_EXEC(ARM64_OP_ALU_IMM, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_LOAD:
				ARM64_SIM_L_EXEC(ARM64_OP_LOAD, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_MOV_REG:
				ARM64_SIM_L_EXEC(ARM64_OP_MOV_REG, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_NOP:
				ARM64_SIM_L_EXEC(ARM64_OP_NOP, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_STLXR:
				ARM64_SIM_L_EXEC(ARM64_OP_STLXR, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			default:
				ARM64_SIM_L_UNSUPPORTED_OPCODE();
				break;
			}
			__a64_c_pc++;
		} else if (__a64_c_kind == ARM64_SIM_C_JMP) {
			__a64_c_pc = __a64_c_target;
		} else if (__a64_c_kind == ARM64_SIM_C_JCC) {
			__a64_c_pc = ARM64_SIM_L_EVAL_COND(__a64_c_cond) ? __a64_c_target : __a64_c_pc + 1;
		} else if (__a64_c_kind == ARM64_SIM_C_CBZ || __a64_c_kind == ARM64_SIM_C_CBNZ) {
			__u64 __a64_c_value = arm64_apply_width(ARM64_SIM_L_READ_REG(__a64_c_src), __a64_c_width);
			__u8 __a64_c_take = (__a64_c_value == 0) == (__a64_c_kind == ARM64_SIM_C_CBZ);
			__a64_c_pc = __a64_c_take ? __a64_c_target : __a64_c_pc + 1;
		} else if (__a64_c_kind == ARM64_SIM_C_TBZ || __a64_c_kind == ARM64_SIM_C_TBNZ) {
			__u64 __a64_c_value = (ARM64_SIM_L_READ_REG(__a64_c_src) >> (__a64_c_imm & 63ULL)) & 1ULL;
			__u8 __a64_c_take = (__a64_c_value == 0) == (__a64_c_kind == ARM64_SIM_C_TBZ);
			__a64_c_pc = __a64_c_take ? __a64_c_target : __a64_c_pc + 1;
		} else if (__a64_c_kind == ARM64_SIM_C_CALL) {
			__a64_lr = __a64_c_pc + 1;
			__a64_x30.x = __a64_lr;
			__a64_c_pc = __a64_c_target;
		} else if (__a64_c_kind == ARM64_SIM_C_RET) {
			if (__a64_lr) {
				__a64_c_pc = (__u32)__a64_lr;
				__a64_lr = 0;
				continue;
			}
			ARM64_SIM_RET();
		} else if (__a64_c_kind == ARM64_SIM_C_HELPER) {
			ARM64_SIM_C_CALL_HELPER(__a64_c_helper);
			__a64_c_pc++;
		} else {
			ARM64_SIM_L_UNSUPPORTED_OPCODE();
		}
	}
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
