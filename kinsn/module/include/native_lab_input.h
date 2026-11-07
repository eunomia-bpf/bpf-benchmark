/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_INPUT_H
#define NATIVE_LAB_INPUT_H

/* Private proof ISA, not a helper call. Entry values refer to the native body
 * after its host JIT prologue; NUMERIC preserves R1 bits without provenance.
 * Cached source-function bases additionally require the certified ABI mapping.
 */
#define NATIVE_LAB_INPUT_ABI 2
#define NATIVE_LAB_INPUT_SRC 9
#define NATIVE_LAB_INPUT_SP 1
#define NATIVE_LAB_INPUT_CODE 2
#define NATIVE_LAB_INPUT_RETURN 3
#define NATIVE_LAB_INPUT_NUMERIC 4
#define NATIVE_LAB_INPUT_EXCLUSIVE_FAILURE 5

#ifdef __KERNEL__
static inline bool bpf_native_input_candidate(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_MOV | BPF_K) &&
	       insn->src_reg == NATIVE_LAB_INPUT_SRC;
}
#endif

#if defined(__bpf__)
#define NATIVE_LAB_ENTRY_INPUT(kind) ({ \
	register unsigned long __native_value asm("r0"); \
	asm volatile(".8byte %c1" : "=r"(__native_value) : \
		"i"(0x00000002000090b7UL | ((unsigned long)(kind) << 16))); \
	__native_value; \
})
#define NATIVE_LAB_NUMERIC(value) ({ \
	register unsigned long __native_value asm("r0"); \
	register unsigned long __native_pointer asm("r1") = (unsigned long)(value); \
	asm volatile(".8byte 0x00000002000490b7" : "=r"(__native_value) : \
		"r"(__native_pointer)); \
	__native_value; \
})
#define NATIVE_LAB_EXCLUSIVE_FAILURE(site) ({ \
	register unsigned long __native_value asm("r0"); \
	asm volatile(".8byte %c1" : "=r"(__native_value) : \
		"i"(0x00000000000590b7UL | ((unsigned long)(unsigned int)(site) << 32))); \
	__native_value; \
})
#elif !defined(__KERNEL__)
#include <stdio.h>
#include <stdlib.h>
/* Host simulators must supply an explicit outcome for each dynamic visit.
 * There is deliberately no constant-success or random fallback.
 */
extern unsigned long native_lab_entry_input(unsigned int kind);
#define NATIVE_LAB_ENTRY_INPUT(kind) native_lab_entry_input(kind)
extern unsigned long native_lab_exclusive_failure_choice(unsigned int site);
#define NATIVE_LAB_EXCLUSIVE_FAILURE(site) ({ \
	unsigned long __native_failure = native_lab_exclusive_failure_choice(site); \
	if (__native_failure > 1) { \
		fputs("native exclusive failure choice must be 0 or 1\n", stderr); \
		exit(1); \
	} \
	__native_failure; \
})
#endif
#endif
