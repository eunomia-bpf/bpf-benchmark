/*
 * Host cross-check for the packed x86 register-lane AUX contract
 * (generated/x86_reg_lane_aux.h from generate_x86_reg_lane_aux_spec.py).
 *
 * The `X86_SIM_L_EXEC_ALU_IMM` / `X86_SIM_L_EXEC_ALU_REG` bodies and the
 * register/lane read-write macros read the ALU code and the two byte lanes out
 * of a packed AUX word through the generated KPROG_X86_REG_LANE_AUX packer and
 * its three byte decoders. This oracle includes x86_sim.h (so the header is
 * checked as the simulator uses it), drives the *real* generated macros, and
 * compares every field against an independent restatement `(aux >> 8k) & 0xff`
 * over a byte grid and every value of each single field. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_reg_lane_aux_host.c \
 *     -o /tmp/t_xrla && /tmp/t_xrla
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

static void check_packed(__u32 payload, __u32 dst_shift, __u32 src_shift,
			 unsigned long *cases)
{
	__u32 aux = KPROG_X86_REG_LANE_AUX(payload, dst_shift, src_shift);

	check_field("payload", KPROG_X86_REG_LANE_AUX_PAYLOAD(aux),
		    payload & 0xffU, aux);
	check_field("dst_shift", KPROG_X86_REG_LANE_AUX_DST_SHIFT(aux),
		    dst_shift & 0xffU, aux);
	check_field("src_shift", KPROG_X86_REG_LANE_AUX_SRC_SHIFT(aux),
		    src_shift & 0xffU, aux);
	/* Independent restatement: extract each byte by shifting, not by the
	 * generated decoder. */
	check_field("payload>>0", (aux >> 0) & 0xffU, payload & 0xffU, aux);
	check_field("dst_shift>>8", (aux >> 8) & 0xffU, dst_shift & 0xffU, aux);
	check_field("src_shift>>16", (aux >> 16) & 0xffU, src_shift & 0xffU,
		    aux);
	/* The top byte is unused: no field may occupy bits 24-31. */
	check_field("top_byte", (aux >> 24) & 0xffU, 0U, aux);
	(*cases)++;
}

int main(void)
{
	static const __u32 bytes[] = { 0U,   1U,	  2U,	 3U,	7U,   8U,  15U,
				       16U,  31U, 32U,	 63U,	64U,  0x7fU, 0x80U,
				       0xaaU, 0xabU, 0xdeU, 0xfeU, 0xffU };
	const size_t nbytes = sizeof(bytes) / sizeof(bytes[0]);
	unsigned long cases = 0;
	size_t i, j, k, l;

	for (i = 0; i < nbytes; i++)
		for (j = 0; j < nbytes; j++)
			for (k = 0; k < nbytes; k++)
				check_packed(bytes[i], bytes[j], bytes[k],
					     &cases);

	/* Concrete sim pattern: dst lane 8 with no source lane only sets bits
	 * 8-15, so the payload byte stays 0. */
	check_packed(0U, 8U, 0U, &cases);
	/* Both lanes: canonical ALU_REG shape reads dst lane from bits 8-15 and
	 * src lane from bits 16-23. */
	check_packed(0U, 8U, 8U, &cases);

	/* Exhaustive over each single field byte: 256 values, others zero. */
	for (l = 0; l < 256U; l++) {
		check_packed(l, 0U, 0U, &cases);
		check_packed(0U, l, 0U, &cases);
		check_packed(0U, 0U, l, &cases);
	}

	if (failures) {
		printf("x86 register lane aux host cross-check: %d FAILURES\n",
		       failures);
		return 1;
	}
	printf("x86 register lane aux host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
