/* SPDX-License-Identifier: MIT */
/*
 * Shared ABI constants for the v5 BPF JIT policy format.
 */

#ifndef BPF_JIT_SCANNER_TYPES_H
#define BPF_JIT_SCANNER_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BPF_JIT_POLICY_MAGIC    0x4A495450U
#define BPF_JIT_POLICY_VERSION_2 2
#define BPF_JIT_POLICY_VERSION  BPF_JIT_POLICY_VERSION_2
#define BPF_JIT_ARCH_X86_64     1

#define BPF_JIT_RK_PATTERN      6

#define BPF_JIT_CF_ROTATE             1
#define BPF_JIT_CF_WIDE_MEM           2
#define BPF_JIT_CF_ADDR_CALC          3
#define BPF_JIT_CF_COND_SELECT        4
#define BPF_JIT_CF_BITFIELD_EXTRACT   5
#define BPF_JIT_CF_ZERO_EXT_ELIDE     6
#define BPF_JIT_CF_ENDIAN_FUSION      7

#define BPF_JIT_SEL_CMOVCC      1
#define BPF_JIT_SEL_BRANCH      2

#define BPF_JIT_WMEM_WIDE_LOAD  1
#define BPF_JIT_WMEM_BYTE_LOADS 2

#define BPF_JIT_ROT_ROR         1
#define BPF_JIT_ROT_RORX        2
#define BPF_JIT_ROT_SHIFT       3

#define BPF_JIT_ACALC_LEA       1
#define BPF_JIT_ACALC_SHIFT_ADD 2

#define BPF_JIT_BFX_EXTRACT     1

#define BPF_JIT_ZEXT_ELIDE      1

#define BPF_JIT_ENDIAN_MOVBE    1

#define BPF_JIT_ENDIAN_LOAD_SWAP 0
#define BPF_JIT_ENDIAN_SWAP_STORE 1

#define BPF_JIT_X86_CMOV        (1U << 0)
#define BPF_JIT_X86_BMI2        (1U << 1)
#define BPF_JIT_X86_MOVBE       (1U << 2)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BPF_JIT_SCANNER_TYPES_H */
