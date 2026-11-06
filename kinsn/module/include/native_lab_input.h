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
#endif
#endif
