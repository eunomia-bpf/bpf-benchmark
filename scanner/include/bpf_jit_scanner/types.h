/* SPDX-License-Identifier: MIT */
/*
 * bpf_jit_scanner/types.h — shared types for the BPF JIT policy scanner
 *
 * These constants and structs must match what the v4 kernel JIT policy
 * framework expects.  The policy blob format is:
 *
 *   [32-byte header][rule_cnt * 16-byte rule entries]
 *
 * Header layout (little-endian, packed):
 *   u32  magic          (0x4A495450 = "JITP")
 *   u16  version        (1)
 *   u16  hdr_len        (32)
 *   u32  total_len
 *   u32  rule_cnt
 *   u32  insn_cnt       (xlated instruction count)
 *   u8   prog_tag[8]
 *   u16  arch_id        (1 = x86-64)
 *   u16  flags          (0)
 *
 * Rule layout (16 bytes, packed):
 *   u32  site_start     (insn index of first instruction in site)
 *   u16  site_len       (number of instructions in site)
 *   u16  rule_kind      (BPF_JIT_RK_*)
 *   u16  native_choice  (BPF_JIT_SEL_*, BPF_JIT_WMEM_*, etc.)
 *   u16  priority
 *   u32  cpu_features_required  (BPF_JIT_X86_* bits)
 */

#ifndef BPF_JIT_SCANNER_TYPES_H
#define BPF_JIT_SCANNER_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ */
/* Policy blob format constants                                         */
/* ------------------------------------------------------------------ */

#define BPF_JIT_POLICY_MAGIC    0x4A495450U  /* "JITP" */
#define BPF_JIT_POLICY_VERSION  1
#define BPF_JIT_ARCH_X86_64     1

/* ------------------------------------------------------------------ */
/* Rule kinds                                                           */
/* ------------------------------------------------------------------ */

/** Conditional-select: replace branch diamond / compact with cmov */
#define BPF_JIT_RK_COND_SELECT  1
/** Wide memory access: replace byte-load ladder with single wide load */
#define BPF_JIT_RK_WIDE_MEM     2
/** Rotate: replace shift-shift-or idiom with ror/rorx */
#define BPF_JIT_RK_ROTATE       3
/** Address calculation: replace shift-add with LEA */
#define BPF_JIT_RK_ADDR_CALC    4

/* ------------------------------------------------------------------ */
/* Native choice values — COND_SELECT                                   */
/* ------------------------------------------------------------------ */

#define BPF_JIT_SEL_CMOVCC      1  /* use conditional-move instruction  */
#define BPF_JIT_SEL_BRANCH      2  /* keep branch (default)             */

/* ------------------------------------------------------------------ */
/* Native choice values — WIDE_MEM                                      */
/* ------------------------------------------------------------------ */

#define BPF_JIT_WMEM_WIDE_LOAD  1  /* emit single word/dword/qword load */
#define BPF_JIT_WMEM_BYTE_LOADS 2  /* keep byte-by-byte loads           */

/* ------------------------------------------------------------------ */
/* Native choice values — ROTATE                                        */
/* ------------------------------------------------------------------ */

#define BPF_JIT_ROT_ROR         1  /* use ROR instruction               */
#define BPF_JIT_ROT_RORX        2  /* use RORX (BMI2, non-destructive)  */
#define BPF_JIT_ROT_SHIFT       3  /* keep shift-shift-or               */

/* ------------------------------------------------------------------ */
/* Native choice values — ADDR_CALC                                     */
/* ------------------------------------------------------------------ */

#define BPF_JIT_ACALC_LEA       1  /* use LEA                           */
#define BPF_JIT_ACALC_SHIFT_ADD 2  /* keep shift + add                  */

/* ------------------------------------------------------------------ */
/* CPU feature requirement bits                                         */
/* ------------------------------------------------------------------ */

#define BPF_JIT_X86_CMOV  (1U << 0)  /* CMOV (P6+, always present on x86-64) */
#define BPF_JIT_X86_BMI2  (1U << 1)  /* BMI2 (Haswell+, needed for RORX)     */

/* ------------------------------------------------------------------ */
/* Scan flags for bpf_jit_scan_all()                                    */
/* ------------------------------------------------------------------ */

#define BPF_JIT_SCAN_CMOV       (1U << 0)
#define BPF_JIT_SCAN_WIDE_MEM   (1U << 1)
#define BPF_JIT_SCAN_ROTATE     (1U << 2)
#define BPF_JIT_SCAN_ADDR_CALC  (1U << 3)
#define BPF_JIT_SCAN_ALL        (BPF_JIT_SCAN_CMOV | BPF_JIT_SCAN_WIDE_MEM | \
                                 BPF_JIT_SCAN_ROTATE | BPF_JIT_SCAN_ADDR_CALC)

/* ------------------------------------------------------------------ */
/* Rule struct — matches the 16-byte on-wire format                     */
/* ------------------------------------------------------------------ */

/**
 * struct bpf_jit_scan_rule - one JIT optimization rule
 *
 * Identifies a single optimization site in the xlated BPF bytecode and
 * specifies the desired native code emission strategy.
 */
struct bpf_jit_scan_rule {
    uint32_t site_start;            /**< first instruction index of site          */
    uint32_t site_len;              /**< number of instructions in site           */
    uint32_t rule_kind;             /**< BPF_JIT_RK_*                             */
    uint32_t native_choice;         /**< BPF_JIT_SEL_*, BPF_JIT_WMEM_*, etc.     */
    uint32_t cpu_features_required; /**< BPF_JIT_X86_* bitmask (0 = no req)      */
    uint32_t priority;              /**< tie-breaking priority (0 = default)      */
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BPF_JIT_SCANNER_TYPES_H */
