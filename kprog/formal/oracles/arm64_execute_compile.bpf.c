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
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)(long)-32,ARM64_SIM_TAG_STACK);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->mark);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,2,255,8,0,16);
	ARM64_SIM_LIBC_MEMSET();
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)(long)-16,ARM64_SIM_TAG_STACK);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X1,(void *)(long)-32,ARM64_SIM_TAG_STACK);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,2,255,8,0,16);
	ARM64_SIM_LIBC_MEMCPY();
	result^=__a64_vectors[31].hi;
	ARM64_SIM_A64_JCC(ctx->mark%15,64,32,jcc_taken);
	result^=1;
jcc_taken:
	ARM64_SIM_A64_CBZ_W(ARM64_X3,32,64,cbz_taken);
	result^=2;
cbz_taken:
	ARM64_SIM_A64_TBNZ(ARM64_X4,63,64,32,tbz_taken);
	result^=4;
tbz_taken:
	ARM64_SIM_A64_CMP_GT(ARM64_OP_CMP_REG,ARM64_X3,ARM64_X4,8,0,0,cmp_taken);
	result^=8;
cmp_taken:
	ARM64_SIM_A64_CALL(callee,0x40);
continuation:
	result^=__a64_stack.b[80];
	__a64_x0.x=result;__a64_x0_tag=ARM64_SIM_TAG_SCALAR;__a64_sp=0;
	ARM64_SIM_RET();
callee:
	ARM64_SIM_A64_RET_TO(ARM64_X30,case 0x40: goto continuation;);

}
char LICENSE[] SEC("license")="GPL";

/* Compile all four changed void forms and three native XDP refresh paths. */
SEC("xdp") int arm64_helper_compile(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	__a64_sp=-32;__u64 observed=0;
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)ctx,ARM64_SIM_TAG_MAP_VALUE);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_ringbuf_submit();observed^=__a64_vectors[31].hi;
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)ctx,ARM64_SIM_TAG_MAP_VALUE);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_ringbuf_discard();observed^=__a64_vectors[31].hi;
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)(long)-16,ARM64_SIM_TAG_STACK);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_ringbuf_submit_dynptr();observed^=__a64_vectors[31].hi;
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)(long)-16,ARM64_SIM_TAG_STACK);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_ringbuf_discard_dynptr();observed^=__a64_vectors[31].hi;
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,__a64_sim_helper_abi_base,ARM64_SIM_TAG_ABI);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_xdp_adjust_head();observed^=ARM64_SIM_L_XDP_NUMERIC((__u64)(long)__a64_sim_abi.data);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,__a64_sim_helper_abi_base,ARM64_SIM_TAG_ABI);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_xdp_adjust_meta();observed^=ARM64_SIM_L_XDP_NUMERIC((__u64)(long)__a64_sim_abi.data_end);
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,__a64_sim_helper_abi_base,ARM64_SIM_TAG_ABI);
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM,1,255,8,0,ctx->rx_queue_index);
	ARM64_SIM_BPF_CALL_bpf_xdp_adjust_tail();observed^=ARM64_SIM_L_XDP_NUMERIC((__u64)(long)__a64_sim_abi.data);
	return (__u32)observed;
}
