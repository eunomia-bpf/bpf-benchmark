/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_EXCLUSIVE_H
#define NATIVE_LAB_EXCLUSIVE_H

#include <linux/bpf.h>
#include "native_lab_input.h"

static inline bool native_lab_exclusive_marker(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_MOV | BPF_K) &&
	       insn->src_reg == NATIVE_LAB_INPUT_SRC &&
	       insn->off == NATIVE_LAB_INPUT_EXCLUSIVE_FAILURE;
}

/* Match actual immutable bytes, not a claimed mnemonic, width or order bit.
 * A marker in an LDDW continuation is never an instruction.
 */
static inline bool native_lab_exclusive_match(const unsigned char *native,
		__u32 size, __u32 offset, const struct bpf_insn *proof,
		__u32 count, __u32 index, __u32 source_pc)
{
	__u32 word, i = 0, status, source, base;

	if ((offset | source_pc) & 3 || offset > size || size - offset < 4 ||
	    index >= count)
		return false;
	word = (__u32)native[offset] | ((__u32)native[offset + 1] << 8) |
	       ((__u32)native[offset + 2] << 16) | ((__u32)native[offset + 3] << 24);
	if ((word & 0xbfe07c00U) != 0x88007c00U)
		return false;
	status = (word >> 16) & 31;
	source = word & 31;
	base = (word >> 5) & 31;
	if (status == source || (status == base && base != 31))
		return false;
	while (i < index)
		i += proof[i].code == (BPF_LD | BPF_DW | BPF_IMM) ? 2 : 1;
	return i == index && native_lab_exclusive_marker(&proof[index]) &&
	       proof[index].dst_reg == BPF_REG_0 &&
	       (__u32)proof[index].imm == source_pc;
}
#endif
