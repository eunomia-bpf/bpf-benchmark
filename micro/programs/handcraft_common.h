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

#define HC_ROTATE_PAYLOAD(DST, SRC, SHIFT) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(SHIFT) << 8))
#define HC_ROTATE_CL_PAYLOAD(DST, CNT) ((__u64)(DST) | ((__u64)(CNT) << 4))
#define HC_REG_IMM_PAYLOAD(DST, IMM) ((__u64)(DST) | ((__u64)(__u32)(IMM) << 8))
#define HC_REG_PAYLOAD(REG) ((__u64)(REG))
#define HC_TEST_PAYLOAD(REG) ((__u64)(REG))
#define HC_CMOV_PAYLOAD(DST, SRC, COND) ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(COND) << 8))
#define HC_CMOV_STACK_PAYLOAD(DST, SRC) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(HC_FLAG_STACK) << 12))
#define HC_SETCC_PAYLOAD(DST, COND) ((__u64)(DST) | ((__u64)(COND) << 4))
#define HC_SETCC_STACK_PAYLOAD(DST) ((__u64)(DST) | ((__u64)(HC_FLAG_STACK) << 16))
#define HC_CMOV_CMP_RR_PAYLOAD(DST, SRC, LHS, RHS, KIND) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(LHS) << 8) | ((__u64)(KIND) << 12) | ((__u64)(RHS) << 16))
#define HC_CMOV_CMP_IMM_PAYLOAD(DST, SRC, LHS, IMM, KIND) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(LHS) << 8) | ((__u64)(KIND) << 12) | ((__u64)(__u32)(IMM) << 16))
#define HC_SETCC_CMP_RR_PAYLOAD(DST, LHS, RHS, KIND) \
    ((__u64)(DST) | ((__u64)(LHS) << 4) | ((__u64)(KIND) << 16) | ((__u64)(RHS) << 20))
#define HC_SETCC_CMP_IMM_PAYLOAD(DST, LHS, IMM, KIND) \
    ((__u64)(DST) | ((__u64)(LHS) << 4) | ((__u64)(KIND) << 16) | ((__u64)(__u32)(IMM) << 20))
#define HC_FLAG_CMP_RR64 1
#define HC_FLAG_CMP_IMM64 2
#define HC_FLAG_CMP_RR32 3
#define HC_FLAG_CMP_IMM32 4
#define HC_FLAG_STACK 5
#define HC_X86_R9 11
#define HC_X86_R10 12
#define HC_X86_R11 13
#define HC_X86_R12 14
#define HC_REG_REG_PAYLOAD(DST, SRC) ((__u64)(DST) | ((__u64)(SRC) << 4))
#define HC_X86_ALU_FORM_RR 1
#define HC_X86_ALU_FORM_IMM 2
/* Payloads carry only x86 operands; verifier scratch is private to kinsn modules. */
#define HC_X86_ALU_RR_PAYLOAD(DST, SRC) \
    ((__u64)(HC_X86_ALU_FORM_RR) | ((__u64)(DST) << 4) | ((__u64)(SRC) << 8))
#define HC_X86_ALU_IMM_PAYLOAD(DST, IMM) \
    ((__u64)(HC_X86_ALU_FORM_IMM) | ((__u64)(DST) << 4) | ((__u64)(__u32)(IMM) << 8))
#define HC_REG_COND_PAYLOAD(DST, COND) ((__u64)(DST) | ((__u64)(COND) << 4))
#define HC_SHD_PAYLOAD(DST, SRC, IMM) \
    ((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(__u8)(IMM) << 8))
#define HC_NOT_NARROW_PAYLOAD(DST) HC_REG_PAYLOAD(DST)
#define HC_MEM_PAYLOAD(REG, BASE, OFF) \
    ((__u64)(REG) | ((__u64)(BASE) << 4) | ((__u64)(__u16)(OFF) << 8))
#define HC_ALU_MEM_PAYLOAD(DST, BASE, OFF) HC_MEM_PAYLOAD(DST, BASE, OFF)
#define HC_STORE_IMM_PAYLOAD(BASE, OFF, IMM) \
    ((__u64)(BASE) | ((__u64)(__u16)(OFF) << 4) | ((__u64)(__u8)(IMM) << 20))
#define HC_POPCNT_PAYLOAD(DST, SRC) HC_REG_REG_PAYLOAD(DST, SRC)
#define HC_SIB_PAYLOAD(DST, BASE, INDEX, SCALE, OFF) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(__u16)(OFF) << 16))
#define HC_ALU_SIB_PAYLOAD(DST, BASE, INDEX, SCALE, OFF) \
    HC_SIB_PAYLOAD(DST, BASE, INDEX, SCALE, OFF)
#define HC_CMP_SIB_RR_PAYLOAD(BASE, INDEX, SCALE, OFF, RHS) \
    ((__u64)(BASE) | ((__u64)(INDEX) << 4) | ((__u64)(SCALE) << 8) | \
     ((__u64)(RHS) << 12) | ((__u64)(__u16)(OFF) << 16))
#define HC_MOVBE_SIB_PAYLOAD(DST, BASE, INDEX, SCALE, OFF) \
    HC_SIB_PAYLOAD(DST, BASE, INDEX, SCALE, OFF)

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
