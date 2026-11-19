#include "../../x86/x86_sim_local_bpf.h"

#define OP(NAME, OPERATION, WIDTH) \
__u64 NAME##WIDTH(void *address, __u64 value, __u8 carry) \
{ return x86_sim_locked_rmw(address,value,WIDTH,OPERATION,carry); }
#define WIDTH(W) \
OP(add,X86_ALU_ADD,W) OP(sub,X86_ALU_SUB,W) OP(adc,X86_ALU_ADC,W) \
OP(sbb,X86_ALU_SBB,W) OP(and,X86_ALU_AND,W) OP(or,X86_ALU_OR,W) \
OP(xor,X86_ALU_XOR,W) OP(inc,X86_ALU_INC,W) OP(dec,X86_ALU_DEC,W) \
OP(not,X86_ALU_NOT,W) OP(neg,X86_ALU_NEG,W)
WIDTH(4)
WIDTH(8)
