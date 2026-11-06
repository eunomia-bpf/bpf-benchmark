/* MOVZX/MOVSX memory accesses use source width, independently of writeback. */
#include "../x86/x86_sim_local_bpf.h"
#define MOVX(NAME, OP, SOURCE, TARGET)                                    \
__attribute__((used,noinline)) __u64 NAME(const __u8 *pointer)             \
{                                                                       \
	X86_SIM_ENTRY_RAW(pointer);                                      \
	X86_SIM_L_EXEC_MOV_LOAD(OP, X86_RAX, X86_RDI, TARGET,               \
		X86_MEM_AUX_FULL(X86_REG_NONE, 0, SOURCE), 3);              \
	return X86_SIM_L_READ_REG(X86_RAX);                                \
}
#define WIDTHS(KIND, OP)                                                \
MOVX(KIND##_1_2, OP, 1, 2)                                              \
MOVX(KIND##_1_4, OP, 1, 4)                                              \
MOVX(KIND##_1_8, OP, 1, 8)                                              \
MOVX(KIND##_2_4, OP, 2, 4)                                              \
MOVX(KIND##_2_8, OP, 2, 8)                                              \
MOVX(KIND##_4_8, OP, 4, 8)
WIDTHS(zx, X86_OP_MOV_LOAD)
WIDTHS(sx, X86_OP_MOVSX_LOAD)
