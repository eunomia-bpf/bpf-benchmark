/*
 * Host cross-check for the packed x86-64 AUX word layout.
 *
 * The simulator packs four fields into one 32-bit AUX word (index byte, scale
 * exponent, memory-width code / register source lane, and ALU-opcode / shift /
 * condition byte) through the generated `KPROG_X86_MEM_AUX` packer, which
 * `x86/x86_sim.h` aliases its `X86_MEM_AUX*` / `X86_REG_AUX_*` macros to. This
 * oracle drives those real sim-path macros and compares every field against an
 * independent restatement `(aux >> 8k) & 0xff`, over a grid of byte values and
 * the `X86_REG_NONE` sentinel. Exit 1 on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_mem_aux_host.c \
 *     -o /tmp/t_xma && /tmp/t_xma
 */

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;
#define __always_inline inline
#include "../x86/x86_sim.h"

#include <stdio.h>

static int failures;

static void check_field(const char *what, unsigned long got, unsigned long want,
			__u32 aux)
{
	if (got != want) {
		printf("MISMATCH %s: aux=0x%08x got=%lu want=%lu\n", what, aux,
		       got, want);
		failures++;
	}
}

static void check_packed(__u32 index, __u32 scale, __u32 width, __u32 op,
			 unsigned long cases)
{
	__u32 aux = X86_MEM_AUX_FULL(index, scale, width);
	__u32 aux_op = aux | X86_MEM_AUX_ALU_OP(op);

	check_field("index", X86_MEM_AUX_INDEX(aux_op), index & 0xffU, aux_op);
	check_field("scale", X86_MEM_AUX_SCALE_LOG2(aux_op), scale & 0xffU,
		    aux_op);
	check_field("mem_width", X86_MEM_AUX_MEM_WIDTH(aux_op), width & 0xffU,
		    aux_op);
	check_field("alu_op", X86_MEM_AUX_GET_ALU_OP(aux_op), op & 0xffU,
		    aux_op);
	check_field("src_shift", X86_REG_AUX_GET_SRC_SHIFT(aux_op), op & 0xffU,
		    aux_op);
	check_field("op_slot", X86_MEM_AUX_ALU_OP(op), (op & 0xffU) << 24,
		    aux_op);
	check_field("src_shift_slot", X86_REG_AUX_SRC_SHIFT(op),
		    (op & 0xffU) << 24, aux_op);
	check_field("pack_eq_full", X86_MEM_AUX(index, scale) |
					 X86_MEM_AUX_MEM_WIDTH(aux) << 16,
		    aux, aux);
	(void)cases;
}

int main(void)
{
	static const __u32 bytes[] = { 0U,   1U,	  2U,	 3U,	7U,   8U,  15U,
				       16U,  31U, 32U,	 63U,	64U,  0x7fU, 0x80U,
				       0xaaU, 0xabU, 0xdeU, 0xfeU, 0xffU };
	const size_t nbytes = sizeof(bytes) / sizeof(bytes[0]);
	unsigned long cases = 0;
	size_t i, j, k, l;

	for (i = 0; i < nbytes; i++) {
		for (j = 0; j < nbytes; j++) {
			for (k = 0; k < nbytes; k++) {
				check_packed(bytes[i], bytes[j], bytes[k], 0U,
					     cases);
				cases++;
			}
		}
	}
	for (l = 0; l < nbytes; l++)
		check_packed(0U, 0U, 0U, bytes[l], cases), cases++;

	/* Sentinel: "no index register" packs and reads back as 0xff. */
	check_field("index_none", X86_MEM_AUX_INDEX(X86_MEM_AUX(
					 X86_REG_NONE, 0U)),
		    X86_REG_NONE, X86_REG_NONE);
	check_field("index_none_define", KPROG_X86_MEM_AUX_INDEX_NONE, 0xffU,
		    0xffU);
	cases++;

	/* The two byte-shift opcodes share the top AUX byte, so a full store AUX
	 * carrying a source lane reads it back through the shift accessor. */
	check_packed(0U, 0U, 8U, 8U, cases);
	cases++;

	/* Exhaustive over each single field byte: 256 values, other fields zero. */
	for (l = 0; l < 256U; l++) {
		__u32 aux = X86_MEM_AUX_FULL(l, 0U, 0U);
		check_field("index_exh", X86_MEM_AUX_INDEX(aux), l, aux);
		aux = X86_MEM_AUX_FULL(0U, l, 0U);
		check_field("scale_exh", X86_MEM_AUX_SCALE_LOG2(aux), l, aux);
		aux = X86_MEM_AUX_FULL(0U, 0U, l);
		check_field("width_exh", X86_MEM_AUX_MEM_WIDTH(aux), l, aux);
		aux = X86_MEM_AUX_ALU_OP(l);
		check_field("op_exh", X86_MEM_AUX_GET_ALU_OP(aux), l, aux);
		cases += 4;
	}

	if (failures) {
		printf("x86 memory aux host cross-check: %d FAILURES\n", failures);
		return 1;
	}
	printf("x86 memory aux host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
