#ifndef ARM64_SIM_LOCAL_BPF_H
#define ARM64_SIM_LOCAL_BPF_H

#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "arm64_sim.h"

#define ARM64_SIM_L_FOR_EACH_GPR(X)                                         \
	X(ARM64_X0, x0)                                                     \
	X(ARM64_X1, x1)                                                     \
	X(ARM64_X2, x2)                                                     \
	X(ARM64_X3, x3)                                                     \
	X(ARM64_X4, x4)                                                     \
	X(ARM64_X5, x5)                                                     \
	X(ARM64_X6, x6)                                                     \
	X(ARM64_X7, x7)                                                     \
	X(ARM64_X8, x8)                                                     \
	X(ARM64_X9, x9)                                                     \
	X(ARM64_X10, x10)                                                   \
	X(ARM64_X11, x11)                                                   \
	X(ARM64_X12, x12)                                                   \
	X(ARM64_X13, x13)                                                   \
	X(ARM64_X14, x14)                                                   \
	X(ARM64_X15, x15)                                                   \
	X(ARM64_X16, x16)                                                   \
	X(ARM64_X17, x17)                                                   \
	X(ARM64_X18, x18)                                                   \
	X(ARM64_X19, x19)                                                   \
	X(ARM64_X20, x20)                                                   \
	X(ARM64_X21, x21)                                                   \
	X(ARM64_X22, x22)                                                   \
	X(ARM64_X23, x23)                                                   \
	X(ARM64_X24, x24)                                                   \
	X(ARM64_X25, x25)                                                   \
	X(ARM64_X26, x26)                                                   \
	X(ARM64_X27, x27)                                                   \
	X(ARM64_X28, x28)                                                   \
	X(ARM64_X29, x29)                                                   \
	X(ARM64_X30, x30)

union arm64_sim_gpr {
	void *ptr;
	__u64 x;
	__u32 w;
};

struct arm64_sim_xdp_abi {
	void *data;
	void *data_end;
	__u32 cb[5];
};

#define ARM64_SIM_L_DECLARE_REG(REG, NAME)                                  \
	union arm64_sim_gpr __a64_##NAME = { .x = 0 };

#define ARM64_SIM_L_DECLARE_STATE()                                         \
	ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_DECLARE_REG)                  \
	__u8 __a64_n = 0;                                                  \
	__u8 __a64_z = 0;                                                  \
	__u8 __a64_c = 0;                                                  \
	__u8 __a64_v = 0

#define ARM64_SIM_ENTRY_XDP(CTX)                                            \
	struct arm64_sim_xdp_abi __a64_sim_abi = {                         \
		.data = (void *)(long)(CTX)->data,                         \
		.data_end = (void *)(long)(CTX)->data_end,                 \
	};                                                               \
	ARM64_SIM_L_DECLARE_STATE();                                      \
	__a64_x0.ptr = &__a64_sim_abi

#define ARM64_SIM_L_READ_REG_CASE(REG, NAME)                                \
	case REG:                                                          \
		__a64_l_value = __a64_##NAME.x;                          \
		break;

#define ARM64_SIM_L_READ_REG(REG)                                           \
	({                                                                 \
		__u64 __a64_l_value = 0;                                  \
		switch (REG) {                                            \
		ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_READ_REG_CASE)       \
		case ARM64_XZR:                                           \
			__a64_l_value = 0;                                \
			break;                                            \
		}                                                          \
		__a64_l_value;                                            \
	})

#define ARM64_SIM_L_WRITE_REG64_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = __a64_l_next;                          \
		break;

#define ARM64_SIM_L_WRITE_REG32_CASE(REG, NAME)                             \
	case REG:                                                          \
		__a64_##NAME.x = (__u32)__a64_l_next;                   \
		break;

#define ARM64_SIM_L_WRITE_REG(REG, VALUE, WIDTH)                             \
	do {                                                               \
		__u64 __a64_l_next = arm64_apply_width((VALUE), (WIDTH)); \
		if ((REG) != ARM64_XZR) {                                  \
			if ((WIDTH) == ARM64_WIDTH_32) {                  \
				switch (REG) {                            \
				ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG32_CASE)\
				}                                         \
			} else {                                            \
				switch (REG) {                            \
				ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG64_CASE)\
				}                                         \
			}                                                   \
		}                                                          \
	} while (0)

#define ARM64_SIM_L_UNSUPPORTED_OPCODE()                                     \
	do {                                                               \
		extern void arm64_sim_unsupported_opcode(void);           \
		arm64_sim_unsupported_opcode();                           \
	} while (0)

#define ARM64_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)                     \
	do {                                                               \
		(void)(AUX);                                               \
		if ((OP) == ARM64_OP_NOP) {                                \
		} else if ((OP) == ARM64_OP_MOV_IMM) {                     \
			ARM64_SIM_L_WRITE_REG((DST), (IMM), (FLAGS));      \
		} else if ((OP) == ARM64_OP_MOV_REG) {                     \
			ARM64_SIM_L_WRITE_REG((DST),                    \
					      ARM64_SIM_L_READ_REG(SRC),    \
					      (FLAGS));                    \
		} else if ((OP) == ARM64_OP_ADD_IMM) {                     \
			ARM64_SIM_L_WRITE_REG((DST),                    \
					      ARM64_SIM_L_READ_REG(SRC) + (IMM),\
					      (FLAGS));                    \
		} else if ((OP) == ARM64_OP_SUB_IMM) {                     \
			ARM64_SIM_L_WRITE_REG((DST),                    \
					      ARM64_SIM_L_READ_REG(SRC) - (IMM),\
					      (FLAGS));                    \
		} else {                                                    \
			ARM64_SIM_L_UNSUPPORTED_OPCODE();                  \
		}                                                           \
	} while (0)

#define ARM64_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM)                     \
	do {                                                               \
		ARM64_SIM_L_EXEC((OP), (DST), (SRC), (FLAGS), (AUX), (IMM));\
	} while (0)

#define ARM64_SIM_RET()                                                     \
	do {                                                               \
		return (__u32)__a64_x0.x;                                  \
	} while (0)

#define ARM64_SIM_LICENSE()                                                 \
	char LICENSE[] SEC("license") = "GPL"

#endif
