extern char system_analysis;
extern char with_debug_output;
#define ARM64_SIM_ENABLE_STACK 1
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

#define ARM64_SIM_C_HELPER_bpf_get_current_pid_tgid 1U
#define ARM64_SIM_C_HELPER_bpf_map_lookup_elem 2U
#define ARM64_SIM_C_HELPER_bpf_probe_read_kernel 3U
#define ARM64_SIM_C_HELPER_bpf_trace_printk 4U

#include "../arm64_sim_local_bpf.h"

#define ARM64_SIM_C_CALL_HELPER(ID) \
	do { \
		switch (ID) { \
		case ARM64_SIM_C_HELPER_bpf_get_current_pid_tgid: ARM64_SIM_BPF_CALL_bpf_get_current_pid_tgid(); break; \
		case ARM64_SIM_C_HELPER_bpf_map_lookup_elem: ARM64_SIM_BPF_CALL_bpf_map_lookup_elem(); break; \
		case ARM64_SIM_C_HELPER_bpf_probe_read_kernel: ARM64_SIM_BPF_CALL_bpf_probe_read_kernel(); break; \
		case ARM64_SIM_C_HELPER_bpf_trace_printk: ARM64_SIM_BPF_CALL_bpf_trace_printk(); break; \
		default: ARM64_SIM_L_UNSUPPORTED_OPCODE(); break; \
		} \
	} while (0)

static const __u64 __arm64_rodata_0[2] = {8367798494427701574ULL, 7142819378486190191ULL};

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} system_analysis_0 SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} with_debug_output_1 SEC(".maps");

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

static const struct arm64_sim_compact_step __arm64_sim_steps_otelcol_ebpf_profiler_read_kernel_memory[] = {
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_SUB, ARM64_MOD_NONE, 0), 64ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_STORE, ARM64_SP, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 44ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ADRP_GOT, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)&system_analysis_0), 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 1ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X9, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 44ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X0, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X1, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 44ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_HELPER, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, ARM64_SIM_C_HELPER_bpf_map_lookup_elem },
	{ ARM64_SIM_C_CBZ, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 31U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X20, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 14ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X19, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_HELPER, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, ARM64_SIM_C_HELPER_bpf_get_current_pid_tgid },
	{ ARM64_SIM_C_OP, ARM64_OP_CMP_REG, ARM64_X20, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(0, ARM64_MOD_LSR, 32), 0, 0U, 0, 0 },
	{ ARM64_SIM_C_JCC, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 35U, ARM64_COND_NE, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_STORE, ARM64_X19, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X0, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 12ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X8, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 128ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X10, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 113ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X1, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 128ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X2, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_HELPER, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, ARM64_SIM_C_HELPER_bpf_probe_read_kernel },
	{ ARM64_SIM_C_CBZ, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 31U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ADRP_GOT, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)&with_debug_output_1), 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_CBNZ, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0, 40U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 4294967295ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 64ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_JMP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 54U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X0, ARM64_XZR, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_SP, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 64ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_JMP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 54U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ADRP_RODATA, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, ((__u64)(long)__arm64_rodata_0), 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_ALU_IMM, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_ALU(ARM64_ALU_ADD, ARM64_MOD_NONE, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X0, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LDP, ARM64_X9, ARM64_X10, ARM64_X8, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X1, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 32ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_STP, ARM64_SP, ARM64_X9, ARM64_X10, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LDP, ARM64_X9, ARM64_X8, ARM64_X8, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X10, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_STP, ARM64_SP, ARM64_X9, ARM64_X8, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 16ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X8, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 32ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_IMM, ARM64_X9, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_32, 0, 6ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_LOAD, ARM64_X2, ARM64_X19, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL, 0U, 0, 0 },
	{ ARM64_SIM_C_HELPER, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, ARM64_SIM_C_HELPER_bpf_trace_printk },
	{ ARM64_SIM_C_JMP, ARM64_OP_NOP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 30U, 0, 0 },
	{ ARM64_SIM_C_OP, ARM64_OP_MOV_REG, ARM64_X7, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0, 0U, 0, 0 },
};

SEC("xdp")
int otelcol_ebpf_profiler_read_kernel_memory_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	__u32 __a64_c_pc = 0;
	__u32 __a64_c_guard_limit = 440U;
	#pragma clang loop unroll(disable)
	for (__u32 __a64_c_guard = 0; __a64_c_guard < __a64_c_guard_limit; __a64_c_guard++) {
		if (__a64_c_pc >= 55U)
			break;
		const struct arm64_sim_compact_step *__a64_c_step = &__arm64_sim_steps_otelcol_ebpf_profiler_read_kernel_memory[__a64_c_pc];
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
			case ARM64_OP_ADRP_RODATA:
				ARM64_SIM_L_EXEC(ARM64_OP_ADRP_RODATA, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_ALU_IMM:
				ARM64_SIM_L_EXEC(ARM64_OP_ALU_IMM, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_CMP_REG:
				ARM64_SIM_L_EXEC(ARM64_OP_CMP_REG, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_LDP:
				ARM64_SIM_L_EXEC(ARM64_OP_LDP, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_LOAD:
				ARM64_SIM_L_EXEC(ARM64_OP_LOAD, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_MOV_IMM:
				ARM64_SIM_L_EXEC(ARM64_OP_MOV_IMM, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_MOV_REG:
				ARM64_SIM_L_EXEC(ARM64_OP_MOV_REG, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_NOP:
				ARM64_SIM_L_EXEC(ARM64_OP_NOP, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_STORE:
				ARM64_SIM_L_EXEC(ARM64_OP_STORE, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
				break;
			case ARM64_OP_STP:
				ARM64_SIM_L_EXEC(ARM64_OP_STP, __a64_c_dst, __a64_c_src, __a64_c_src2, __a64_c_src3, __a64_c_width, __a64_c_aux, __a64_c_imm);
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
