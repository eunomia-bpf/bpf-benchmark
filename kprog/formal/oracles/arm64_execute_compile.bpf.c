/* Compile the actual dispatcher, including live condition selection. */
#define ARM64_SIM_ENABLE_STACK 1
#include "../../arm64/arm64_sim_local_bpf.h"
SEC("socket") int arm64_execute_compile(struct __sk_buff *ctx)
{
	ARM64_SIM_ENTRY_RAW(ctx);
	__a64_sp=-32;
	__a64_n=ctx->mark&1; __a64_z=ctx->priority&1;
	__a64_c=ctx->hash&1; __a64_v=(ctx->hash>>1)&1;
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,ARM64_SP,8,0,ctx->mark);
	ARM64_SIM_RUN_OP(ARM64_OP_MOVK,1,255,8,ARM64_AUX_MOVK(16),ctx->priority);
	ARM64_SIM_RUN_OP(ARM64_OP_ADD_IMM,2,ARM64_SP,8,0,16);
	ARM64_SIM_RUN_OP3(ARM64_OP_ALU_REG,3,1,2,255,8,ARM64_AUX_ALU(ARM64_ALU_ADD,ARM64_MOD_LSL,0),0);
	ARM64_SIM_RUN_OP3(ARM64_OP_MUL,4,1,3,255,8,0,0);
	ARM64_SIM_RUN_OP(ARM64_OP_CMP_REG,4,1,8,ARM64_AUX_ALU(0,ARM64_MOD_LSL,0),0);
	ARM64_SIM_RUN_OP3(ARM64_OP_CSEL,5,1,2,255,8,ARM64_COND_EQ,0);
	ARM64_SIM_RUN_OP3(ARM64_OP_CNEG,6,5,255,255,8,ARM64_COND_GE,0);
	ARM64_SIM_RUN_OP3(ARM64_OP_ORN_REG,7,6,3,255,4,ARM64_AUX_ALU(0,ARM64_MOD_LSL,1),0);
	ARM64_SIM_RUN_OP3(ARM64_OP_FMOV,0,7,3,255,8,ARM64_FMOV_D_FROM_X,0);
	ARM64_SIM_RUN_OP(ARM64_OP_CNT,0,0,8,16,0);
	ARM64_SIM_RUN_OP(ARM64_OP_UADDLV,0,0,8,16,0);
	__u64 result=ARM64_SIM_L_READ_REG(5)^ARM64_SIM_L_READ_REG(7)^__a64_vectors[3].lo;
	result^=__a64_v0;
	result^=KPROG_ARM64_EVAL_COND(ctx->priority%15,__a64_n,__a64_z,__a64_c,__a64_v,ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return (__u32)result;
}
char LICENSE[] SEC("license")="GPL";
