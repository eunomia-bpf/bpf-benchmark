#ifndef XVM_ABI_H
#define XVM_ABI_H

#define XVM_MAGIC 0x314d5658U /* "XVM1" little-endian */

#define XVM_OUTPUT_OFF 0U
#define XVM_HEADER_OFF 8U
#define XVM_CODE_OFF 16U
#define XVM_INSN_SIZE 16U
#define XVM_MAX_INSNS 32U
#define XVM_MAX_PACKET_SIZE (XVM_CODE_OFF + XVM_MAX_INSNS * XVM_INSN_SIZE)

#define XVM_OP_MOV_IMM64 0x01U
#define XVM_OP_MOV_REG64 0x02U
#define XVM_OP_ADD_IMM64 0x03U
#define XVM_OP_ADD_REG64 0x04U
#define XVM_OP_XOR_REG32 0x05U
#define XVM_OP_RET 0xffU

#define XVM_RAX 0U
#define XVM_RCX 1U
#define XVM_RDX 2U
#define XVM_RBX 3U
#define XVM_RSP 4U
#define XVM_RBP 5U
#define XVM_RSI 6U
#define XVM_RDI 7U
#define XVM_R8 8U
#define XVM_R9 9U
#define XVM_R10 10U
#define XVM_R11 11U
#define XVM_R12 12U
#define XVM_R13 13U
#define XVM_R14 14U
#define XVM_R15 15U

#endif
