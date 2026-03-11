/* SPDX-License-Identifier: MIT */
/*
 * bpf_jit_scanner/scanner.h — scan xlated BPF bytecode for JIT optimization sites
 *
 * All functions operate on raw xlated BPF bytecode as returned by
 * BPF_OBJ_GET_INFO_BY_FD with info.xlated_prog_insns.  Each instruction
 * is exactly 8 bytes in the standard BPF encoding:
 *
 *   u8  code
 *   u8  regs  (dst_reg:4 | src_reg:4, lower nibble = dst)
 *   s16 off
 *   s32 imm
 *
 * All scan functions return the number of rules written into @rules on
 * success, or a negative errno-compatible value on error.
 *
 * Rules are appended in instruction-index order.  The caller must supply
 * a rules buffer large enough to hold all results.  Pass max_rules=0 with
 * rules=NULL to get a count without storing results (not yet supported —
 * just pass a generously sized buffer).
 *
 * This is the low-level matcher API.  If you need overlap arbitration,
 * static features, config-driven native_choice selection, or future
 * profile-guided decisions, use the C++ PolicyEngine in engine.hpp.
 */

#ifndef BPF_JIT_SCANNER_SCANNER_H
#define BPF_JIT_SCANNER_SCANNER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * bpf_jit_scan_cmov() - scan for conditional-select (cmov) patterns
 * @xlated:    raw xlated BPF bytecode
 * @len:       length in bytes (must be a multiple of 8)
 * @rules:     output array
 * @max_rules: capacity of @rules
 *
 * Recognizes two patterns:
 *   Diamond: jcc+2, mov, ja+1, mov  (4-insn)
 *   Compact: mov, jcc+1, mov        (3-insn)
 *
 * Returns number of rules written, or negative on error.
 */
int bpf_jit_scan_cmov(const uint8_t *xlated, uint32_t len,
                      struct bpf_jit_scan_rule *rules, uint32_t max_rules);

/**
 * bpf_jit_scan_wide_mem() - scan for byte-load ladder patterns
 * @xlated:    raw xlated BPF bytecode
 * @len:       length in bytes
 * @rules:     output array
 * @max_rules: capacity of @rules
 *
 * Recognizes high-byte-first (clang) and low-byte-first (generic) patterns
 * for 2-byte, 4-byte, and 8-byte loads built from individual ldxb instructions.
 *
 * Returns number of rules written, or negative on error.
 */
int bpf_jit_scan_wide_mem(const uint8_t *xlated, uint32_t len,
                          struct bpf_jit_scan_rule *rules, uint32_t max_rules);

/**
 * bpf_jit_scan_rotate() - scan for rotate idioms
 * @xlated:    raw xlated BPF bytecode
 * @len:       length in bytes
 * @use_rorx:  if true, emit RORX (BMI2) instead of ROR
 * @rules:     output array
 * @max_rules: capacity of @rules
 *
 * Recognizes four variants:
 *   4-insn classic:          mov, lsh, rsh, or
 *   4-insn commuted:         mov, rsh, lsh, or
 *   5-insn two-copy:         mov, rsh, mov, lsh, or
 *   6-insn masked 32-bit:    mov, and, rsh, mov, lsh, or
 *
 * When @use_rorx is true the native_choice is BPF_JIT_ROT_RORX and
 * cpu_features_required includes BPF_JIT_X86_BMI2.
 *
 * Returns number of rules written, or negative on error.
 */
int bpf_jit_scan_rotate(const uint8_t *xlated, uint32_t len,
                        bool use_rorx,
                        struct bpf_jit_scan_rule *rules, uint32_t max_rules);

/**
 * bpf_jit_scan_addr_calc() - scan for address-calculation (LEA) patterns
 * @xlated:    raw xlated BPF bytecode
 * @len:       length in bytes
 * @rules:     output array
 * @max_rules: capacity of @rules
 *
 * Recognizes: mov64 dst,idx  ;  lsh64 dst,K (K in {1,2,3})  ;  add64 dst,base
 *
 * Returns number of rules written, or negative on error.
 */
int bpf_jit_scan_addr_calc(const uint8_t *xlated, uint32_t len,
                           struct bpf_jit_scan_rule *rules, uint32_t max_rules);

/**
 * bpf_jit_scan_bitfield_extract() - scan for bitfield extract idioms
 * @xlated:    raw xlated BPF bytecode
 * @len:       length in bytes
 * @rules:     output array
 * @max_rules: capacity of @rules
 *
 * Recognizes:
 *   rsh{32,64} dst, shift ; and{32,64} dst, mask
 *   and{32,64} dst, mask ; rsh{32,64} dst, shift
 * and the corresponding 3-insn reg-copy forms:
 *   mov{32,64} dst, src ; <pair above>
 *
 * Returns number of rules written, or negative on error.
 */
int bpf_jit_scan_bitfield_extract(const uint8_t *xlated, uint32_t len,
                                  struct bpf_jit_scan_rule *rules,
                                  uint32_t max_rules);

/**
 * bpf_jit_scan_all() - scan for all enabled pattern families
 * @xlated:     raw xlated BPF bytecode
 * @len:        length in bytes
 * @scan_flags: OR of BPF_JIT_SCAN_* bits (use BPF_JIT_SCAN_ALL for everything)
 * @use_rorx:   if true and BPF_JIT_SCAN_ROTATE set, request RORX
 * @rules:      output array
 * @max_rules:  capacity of @rules
 *
 * Runs all enabled scanners in order
 * (cmov, wide_mem, rotate, addr_calc, bitfield_extract) and collects
 * results into @rules.
 *
 * Returns total number of rules written across all families, or negative
 * on error (ENOBUFS if the combined result would exceed @max_rules).
 */
int bpf_jit_scan_all(const uint8_t *xlated, uint32_t len,
                     uint32_t scan_flags, bool use_rorx,
                     struct bpf_jit_scan_rule *rules, uint32_t max_rules);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BPF_JIT_SCANNER_SCANNER_H */
