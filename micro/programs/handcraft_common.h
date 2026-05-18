#ifndef MICRO_PROGRAMS_HANDCRAFT_COMMON_H
#define MICRO_PROGRAMS_HANDCRAFT_COMMON_H

#include "micro_handcraft.h"

#include <linux/bpf.h>

#define HC_RAW(CODE, DST, SRC, OFF, IMM) \
    ((struct bpf_insn){ .code = (CODE), .dst_reg = (DST), .src_reg = (SRC), .off = (OFF), .imm = (IMM) })

#define HC_LD_IMM64_RAW(DST, SRC, IMM) \
    HC_RAW(BPF_LD | BPF_DW | BPF_IMM, DST, SRC, 0, (__s32)(__u64)(IMM)), \
    HC_RAW(0, 0, 0, 0, (__s32)((__u64)(IMM) >> 32))

#define HC_LDX(SIZE, DST, SRC, OFF) HC_RAW(BPF_LDX | (SIZE) | BPF_MEM, DST, SRC, OFF, 0)
#define HC_ST(SIZE, DST, OFF, IMM) HC_RAW(BPF_ST | (SIZE) | BPF_MEM, DST, 0, OFF, IMM)
#define HC_STX(SIZE, DST, SRC, OFF) HC_RAW(BPF_STX | (SIZE) | BPF_MEM, DST, SRC, OFF, 0)
#define HC_MOV64_REG(DST, SRC) HC_RAW(BPF_ALU64 | BPF_MOV | BPF_X, DST, SRC, 0, 0)
#define HC_MOV64_IMM(DST, IMM) HC_RAW(BPF_ALU64 | BPF_MOV | BPF_K, DST, 0, 0, IMM)
#define HC_ALU64_IMM(OP, DST, IMM) HC_RAW(BPF_ALU64 | (OP) | BPF_K, DST, 0, 0, IMM)
#define HC_ALU64_REG(OP, DST, SRC) HC_RAW(BPF_ALU64 | (OP) | BPF_X, DST, SRC, 0, 0)
#define HC_JMP_REG(OP, DST, SRC, OFF) HC_RAW(BPF_JMP | (OP) | BPF_X, DST, SRC, OFF, 0)
#define HC_CALL(PC_DELTA) HC_RAW(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_CALL, 0, (PC_DELTA) - 1)
#define HC_EXIT() HC_RAW(BPF_JMP | BPF_EXIT, 0, 0, 0, 0)

#define HC_KINSN_CALL(SELECTOR) HC_RAW(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL, 0, SELECTOR)
#define HC_KINSN_WIRE_PAYLOAD(PAYLOAD) \
    ((((__u64)(PAYLOAD) & 0xf) > BPF_REG_10) ? \
     ((__u64)BPF_REG_10 | (((__u64)(PAYLOAD) & 0xf) << 4) | (((__u64)(PAYLOAD) >> 4) << 8)) : \
     (__u64)(PAYLOAD))
#define HC_KINSN_SIDECAR(PAYLOAD) \
    HC_RAW(BPF_ALU64 | BPF_MOV | BPF_K, \
           (__u8)(HC_KINSN_WIRE_PAYLOAD(PAYLOAD) & 0xf), \
           BPF_PSEUDO_KINSN_SIDECAR, \
           (__s16)((HC_KINSN_WIRE_PAYLOAD(PAYLOAD) >> 4) & 0xffff), \
           (__s32)((HC_KINSN_WIRE_PAYLOAD(PAYLOAD) >> 20) & 0xffffffffU))
#define HC_KINSN(PAYLOAD, SELECTOR) \
    HC_KINSN_SIDECAR(PAYLOAD), \
    HC_KINSN_CALL(SELECTOR)

#define HC_REG_IMM_PAYLOAD(DST, IMM) ((__u64)(DST) | ((__u64)(__u32)(IMM) << 8))
#define HC_REG_PAYLOAD(REG) ((__u64)(REG))
#define HC_CMOV_STACK_PAYLOAD(DST, SRC) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(HC_FLAG_STACK) << 12))
#define HC_CMOV_ARCH_STACK_PAYLOAD(DST, SRC) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(HC_FLAG_ARCH_STACK) << 12))
#define HC_SETCC_STACK_PAYLOAD(DST) ((__u64)(DST) | ((__u64)(HC_FLAG_STACK) << 16))
#define HC_SETCC_ARCH_STACK_PAYLOAD(DST) \
    ((__u64)(DST) | ((__u64)(HC_FLAG_ARCH_STACK) << 16))
#define HC_FLAG_STACK 5
#define HC_FLAG_ARCH_STACK 6
#define HC_X86_RAX BPF_REG_0
#define HC_X86_RDI BPF_REG_1
#define HC_X86_RSI BPF_REG_2
#define HC_X86_RDX BPF_REG_3
#define HC_X86_RCX BPF_REG_4
#define HC_X86_R8 BPF_REG_5
#define HC_X86_RBX BPF_REG_6
#define HC_X86_R13 BPF_REG_7
#define HC_X86_R14 BPF_REG_8
#define HC_X86_R15 BPF_REG_9
#define HC_X86_R9 11
#define HC_X86_R10 12
#define HC_X86_R11 13
#define HC_X86_R12 14
#define HC_X86_RBP BPF_REG_10
#define HC_X86_RSP 15
#define HC_REG_REG_PAYLOAD(DST, SRC) ((__u64)(DST) | ((__u64)(SRC) << 4))
#define HC_X86_FORM_RR 1
#define HC_X86_FORM_IMM 2
#define HC_X86_FORM_SIB_RR 3
#define HC_X86_FORM_MEM 4
#define HC_X86_FORM_SIB 5
#define HC_X86_FORM_STORE 6
#define HC_X86_FORM_STORE_IMM 7
#define HC_X86_FORM_FRAME 8
#define HC_X86_FORM_ARCH_MEM 9
#define HC_X86_FORM_ARCH_STORE 10
#define HC_X86_FORM_ARCH_STORE_IMM 11
#define HC_X86_FORM_ARCH_RR 12
#define HC_X86_FORM_ARCH_IMM 13
#define HC_X86_FORM_ARCH_SIB 14
#define HC_X86_FORM_ARCH_TO_BPF_RR 15
#define HC_X86_FORM_BPF_TO_ARCH_RR HC_X86_FORM_SIB_RR
#define HC_X86_ALU_FORM_RR HC_X86_FORM_RR
#define HC_X86_ALU_FORM_IMM HC_X86_FORM_IMM
/* Payloads carry only x86 operands; verifier scratch is private to kinsn modules. */
#define HC_X86_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_FORM_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_ARCH_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_FORM_ARCH_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_ARCH_TO_BPF_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_FORM_ARCH_TO_BPF_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_BPF_TO_ARCH_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_FORM_BPF_TO_ARCH_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_IMM_PAYLOAD(DST, IMM) \
    ((__u64)(HC_X86_FORM_IMM) | ((__u64)(DST) << 4) | ((__u64)(__u32)(IMM) << 8))
#define HC_X86_ARCH_IMM_PAYLOAD(DST, IMM) \
    ((__u64)(HC_X86_FORM_ARCH_IMM) | ((__u64)(DST) << 4) | ((__u64)(__u32)(IMM) << 8))
#define HC_X86_FRAME_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_FORM_FRAME) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_ROTATE_PAYLOAD(DST, SRC, SHIFT) \
    ((__u64)(HC_X86_FORM_IMM) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8) | \
     ((__u64)(__u8)(SHIFT) << 12))
#define HC_ROTATE_ARCH_PAYLOAD(DST, SRC, SHIFT) \
    ((__u64)(HC_X86_FORM_ARCH_IMM) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8) | \
     ((__u64)(__u8)(SHIFT) << 12))
#define HC_ROTATE_CL_PAYLOAD(DST, CNT) HC_X86_RR_PAYLOAD(DST, CNT)
#define HC_ROTATE_ARCH_CL_PAYLOAD(DST, CNT) HC_X86_ARCH_RR_PAYLOAD(DST, CNT)
#define HC_X86_CMP_SIB_RR_PAYLOAD(BASE, INDEX, SCALE, OFF, RHS) \
    ((__u64)(HC_X86_FORM_SIB_RR) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(RHS) << 16) | ((__u64)(__u16)(OFF) << 20))
#define HC_X86_CMP_MEM_IMM_PAYLOAD(BASE, OFF, IMM) \
    ((__u64)(HC_X86_FORM_MEM) | ((__u64)(BASE) << 4) | \
     ((__u64)(__u16)(OFF) << 8) | ((__u64)(__u32)(IMM) << 24))
#define HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD(BASE, OFF, IMM) \
    ((__u64)(HC_X86_FORM_ARCH_MEM) | ((__u64)(BASE) << 4) | \
     ((__u64)(__u16)(OFF) << 8) | ((__u64)(__u32)(IMM) << 24))
#define HC_X86_MEM_PAYLOAD(REG, BASE, OFF) \
    ((__u64)(HC_X86_FORM_MEM) | ((__u64)(REG) << 4) | \
     ((__u64)(BASE) << 8) | ((__u64)(__u16)(OFF) << 12))
#define HC_X86_ARCH_MEM_PAYLOAD(REG, BASE, OFF) \
    ((__u64)(HC_X86_FORM_ARCH_MEM) | ((__u64)(REG) << 4) | \
     ((__u64)(BASE) << 8) | ((__u64)(__u16)(OFF) << 12))
#define HC_X86_SIB_PAYLOAD(REG, BASE, INDEX, SCALE, OFF) \
    ((__u64)(HC_X86_FORM_SIB) | ((__u64)(REG) << 4) | ((__u64)(BASE) << 8) | \
     ((__u64)(INDEX) << 12) | ((__u64)(SCALE) << 16) | ((__u64)(__u16)(OFF) << 20))
#define HC_X86_ARCH_SIB_PAYLOAD(REG, BASE, INDEX, SCALE, OFF) \
    ((__u64)(HC_X86_FORM_ARCH_SIB) | ((__u64)(REG) << 4) | ((__u64)(BASE) << 8) | \
     ((__u64)(INDEX) << 12) | ((__u64)(SCALE) << 16) | ((__u64)(__u16)(OFF) << 20))
#define HC_X86_STORE_PAYLOAD(SRC, BASE, OFF) \
    ((__u64)(HC_X86_FORM_STORE) | ((__u64)(SRC) << 4) | \
     ((__u64)(BASE) << 8) | ((__u64)(__u16)(OFF) << 12))
#define HC_X86_ARCH_STORE_PAYLOAD(SRC, BASE, OFF) \
    ((__u64)(HC_X86_FORM_ARCH_STORE) | ((__u64)(SRC) << 4) | \
     ((__u64)(BASE) << 8) | ((__u64)(__u16)(OFF) << 12))
#define HC_X86_STORE_BYTE_PAYLOAD(SRC, BASE, OFF, LANE) \
    (HC_X86_STORE_PAYLOAD(SRC, BASE, OFF) | ((__u64)(LANE) << 28))
#define HC_X86_ARCH_STORE_BYTE_PAYLOAD(SRC, BASE, OFF, LANE) \
    (HC_X86_ARCH_STORE_PAYLOAD(SRC, BASE, OFF) | ((__u64)(LANE) << 28))
#define HC_X86_STORE_IMM_PAYLOAD(BASE, OFF, IMM) \
    ((__u64)(HC_X86_FORM_STORE_IMM) | ((__u64)(BASE) << 4) | \
     ((__u64)(__u16)(OFF) << 8) | ((__u64)(__u32)(IMM) << 24))
#define HC_X86_ARCH_STORE_IMM_PAYLOAD(BASE, OFF, IMM) \
    ((__u64)(HC_X86_FORM_ARCH_STORE_IMM) | ((__u64)(BASE) << 4) | \
     ((__u64)(__u16)(OFF) << 8) | ((__u64)(__u32)(IMM) << 24))
#define HC_X86_ALU_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_ALU_FORM_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_ALU_IMM_PAYLOAD(DST, IMM) \
    ((__u64)(HC_X86_ALU_FORM_IMM) | ((__u64)(DST) << 4) | ((__u64)(__u32)(IMM) << 8))
#define HC_REG_COND_PAYLOAD(DST, COND) ((__u64)(DST) | ((__u64)(COND) << 4))
#define HC_SHD_PAYLOAD(DST, SRC, IMM) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(__u8)(IMM) << 8))
#define HC_SHD_ARCH_PAYLOAD(DST, SRC, IMM) (HC_SHD_PAYLOAD(DST, SRC, IMM) | (1ULL << 16))
#define HC_NOT_NARROW_PAYLOAD(DST) HC_REG_PAYLOAD(DST)
#define HC_REG_IMM_ARCH_PAYLOAD(REG, IMM) (HC_REG_IMM_PAYLOAD(REG, IMM) | (1ULL << 16))
#define HC_INIT_X86_STACK() \
    HC_MOV64_REG(BPF_REG_6, BPF_REG_10), \
    HC_ALU64_IMM(BPF_ADD, BPF_REG_6, -128), \
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -480)
#define HC_XDP_PREFIX(INPUT_SIZE, ABORT_OFF) \
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0), \
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_1, 4), \
    HC_ALU64_IMM(BPF_ADD, BPF_REG_6, 8), \
    HC_MOV64_REG(BPF_REG_2, BPF_REG_6), \
    HC_ALU64_IMM(BPF_ADD, BPF_REG_2, INPUT_SIZE), \
    HC_JMP_REG(BPF_JGE, BPF_REG_7, BPF_REG_2, 2), \
    HC_MOV64_IMM(BPF_REG_0, 0), \
    HC_EXIT()

#define HC_XDP_SUFFIX() \
    HC_STX(BPF_DW, BPF_REG_6, BPF_REG_0, -8), \
    HC_MOV64_IMM(BPF_REG_0, 2), \
    HC_EXIT()

#define HC_EXPORT_PROGRAM(PROG_ARRAY) \
    int micro_handcraft_get_program(struct micro_handcraft_program *out) \
    { \
        out->insns = PROG_ARRAY; \
        out->insn_count = sizeof(PROG_ARRAY) / sizeof((PROG_ARRAY)[0]); \
        return 0; \
    }

#endif
