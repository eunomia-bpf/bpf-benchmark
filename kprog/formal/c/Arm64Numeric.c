/* Clight roots for the same canonical numeric bodies used by the simulator. */
#include "../../arm64/arm64_sim_local_bpf.h"

__u64 kprog_arm64_alu_result(__u64 op, __u64 lhs, __u64 rhs)
{
	__u64 result;
	KPROG_ALU64_RESULT_INTO(result, op, lhs, rhs, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_mod(__u64 mod, __u64 value, __u64 shift, __u64 width)
{
	__u64 result;
	KPROG_ARM64_MOD_VALUE_INTO(result, mod, value, shift, width);
	return result;
}

__u64 kprog_arm64_shift(__u64 shift, __u64 value, __u64 amount, __u64 width)
{
	__u64 result;
	KPROG_ARM64_SHIFT_VALUE_INTO(result, shift, value, amount, width, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_bitfield(__u64 kind, __u64 src, __u64 dst, __u64 lsb, __u64 bits)
{
	__u64 result;
	KPROG_ARM64_BITFIELD_VALUE_INTO(result, kind, src, dst, lsb, bits, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_mul(__u64 op, __u64 lhs, __u64 rhs, __u64 addend)
{
	__u64 result;
	KPROG_ARM64_MUL_VALUE_INTO(result, op, lhs, rhs, addend, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_extrev(__u64 op, __u64 src, __u64 src2, __u64 shift, __u64 width)
{
	__u64 result;
	KPROG_ARM64_EXTREV_VALUE_INTO(result, op, src, src2, shift, width, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_unary(__u64 op, __u64 value, __u64 width)
{
	__u64 result;
	KPROG_ARM64_UNARY_VALUE_INTO(result, op, value, width, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_csel(__u64 op, __u64 src, __u64 src2, __u64 taken)
{
	__u64 result;
	KPROG_ARM64_CSEL_VALUE_INTO(result, op, src, src2, taken, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_cneg(__u64 op, __u64 value, __u64 taken, __u64 width)
{
	__u64 result;
	KPROG_ARM64_CNEG_VALUE_INTO(result, op, value, taken, width, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_fmov(__u64 dir, __u64 v0, __u64 src)
{
	__u64 result;
	KPROG_ARM64_FMOV_VALUE_INTO(result, dir, v0, src, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_fmov_dest(__u64 dir)
{
	__u64 result;
	KPROG_ARM64_FMOV_DEST_VECTOR_INTO(result, dir, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}

__u64 kprog_arm64_imm_operand(__u64 op, __u64 imm, __u64 reg)
{
	__u64 result;
	KPROG_ARM64_IMM_RHS_INTO(result, op, imm, reg);
	return result;
}

__u64 kprog_arm64_adrp(__u64 op)
{
	__u8 result;
	KPROG_ARM64_ADRP_TAG_INTO(result, op, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}
