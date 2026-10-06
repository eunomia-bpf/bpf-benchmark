/*
 * Host cross-check for the packed AArch64 AUX (operand) word layout.
 *
 * The simulator packs four bytes into one 32-bit AUX word through the generated
 * `KPROG_ARM64_AUX` packer, which `arm64/arm64_sim.h` aliases its `ARM64_AUX*`
 * macros to. This oracle drives those real sim-path packers and compares every
 * byte against an independent restatement `(aux >> 8k) & 0xff`, over a grid of
 * byte values, an exhaustive sweep of each byte lane, and the `ARM64_REG_NONE`
 * sentinel. It also checks the per-opcode aliasing: the source modifier, the
 * bitfield LSB and the CCMP NZCV all live in lane 1; the shift amount, the
 * bitfield width and the MOVK column all live in lane 2. Exit 1 on any
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 test_arm64_aux_host.c \
 *     -o /tmp/t_a64aux && /tmp/t_a64aux
 */

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

#include "../arm64/arm64_sim.h"

#include <stdio.h>

/* Independent byte-lane extractors (not the simulator's ARM64_SIM_L_*). */
static __u32 f0(__u32 aux) { return (aux >> 0) & 0xffU; }
static __u32 f1(__u32 aux) { return (aux >> 8) & 0xffU; }
static __u32 f2(__u32 aux) { return (aux >> 16) & 0xffU; }
static __u32 f3(__u32 aux) { return (aux >> 24) & 0xffU; }

static int failures;
static unsigned long cases;

static void check(const char *what, unsigned long got, unsigned long want,
		  __u32 aux)
{
	cases++;
	if (got != want) {
		printf("MISMATCH %s: aux=0x%08x got=%lu want=%lu\n", what, aux,
		       got, want);
		failures++;
	}
}

/* The shared memory-opcode packer: index in lane 0, modifier in lane 1, shift
 * in lane 2, flags in lane 3. */
static void check_mem(__u32 index, __u32 mod, __u32 shift, __u32 flags)
{
	__u32 aux = ARM64_AUX_MEM(index, mod, shift, flags);

	check("mem.b0", f0(aux), index & 0xffU, aux);
	check("mem.b1", f1(aux), mod & 0xffU, aux);
	check("mem.b2", f2(aux), shift & 0xffU, aux);
	check("mem.b3", f3(aux), flags & 0xffU, aux);
}

/* The ALU-opcode packer: opcode in lane 0, modifier in lane 1, shift in lane 2,
 * lane 3 clear. ARM64_AUX and ARM64_AUX_ALU are the same layout. */
static void check_alu(__u32 alu, __u32 mod, __u32 shift)
{
	__u32 aux = ARM64_AUX_ALU(alu, mod, shift);
	__u32 aux3 = ARM64_AUX(alu, mod, shift);

	check("alu.b0", f0(aux), alu & 0xffU, aux);
	check("alu.b1", f1(aux), mod & 0xffU, aux);
	check("alu.b2", f2(aux), shift & 0xffU, aux);
	check("alu.b3", f3(aux), 0U, aux);
	check("alu.arm64_aux_eq", aux3, aux, aux);
}

/* ARM64_AUX_SHIFT puts the shift kind in lane 0: the shift handler passes the
 * whole AUX word to the shared `KPROG_ARM64_SHIFT_VALUE`, whose case labels are
 * the low-byte `ARM64_SHIFT_LSL/LSR/ASR/ROR` codes (the lane-0 role shared with
 * the ALU opcode and the memory index). The shift *amount* is an immediate or a
 * register, not an AUX byte. */
static void check_shift(__u32 kind)
{
	__u32 aux = ARM64_AUX_SHIFT(kind);

	check("shift.b0", f0(aux), kind & 0xffU, aux);
	check("shift.b1", f1(aux), 0U, aux);
	check("shift.b2", f2(aux), 0U, aux);
	check("shift.b3", f3(aux), 0U, aux);
}

/* ARM64_AUX_MOVK puts the insertion column in lane 2 only. */
static void check_movk(__u32 col)
{
	__u32 aux = ARM64_AUX_MOVK(col);

	check("movk.b0", f0(aux), 0U, aux);
	check("movk.b1", f1(aux), 0U, aux);
	check("movk.b2", f2(aux), col & 0xffU, aux);
	check("movk.b3", f3(aux), 0U, aux);
}

/* The bitfield packer: kind in lane 0, LSB in lane 1, width in lane 2. */
static void check_bitfield(__u32 op, __u32 lsb, __u32 width)
{
	__u32 aux = ARM64_AUX_BITFIELD(op, lsb, width);

	check("bf.b0", f0(aux), op & 0xffU, aux);
	check("bf.b1", f1(aux), lsb & 0xffU, aux);
	check("bf.b2", f2(aux), width & 0xffU, aux);
	check("bf.b3", f3(aux), 0U, aux);
}

/* The CCMP packer: condition in lane 0, NZCV in lane 1. */
static void check_ccmp(__u32 cond, __u32 nzcv)
{
	__u32 aux = ARM64_AUX_CCMP(cond, nzcv);

	check("ccmp.b0", f0(aux), cond & 0xffU, aux);
	check("ccmp.b1", f1(aux), nzcv & 0xffU, aux);
	check("ccmp.b2", f2(aux), 0U, aux);
	check("ccmp.b3", f3(aux), 0U, aux);
}

int main(void)
{
	static const __u32 bytes[] = { 0U,   1U,	  2U,	 3U,	7U,   8U,  15U,
				       16U,  31U, 32U,	 63U,	64U,  0x7fU, 0x80U,
				       0xaaU, 0xabU, 0xdeU, 0xfeU, 0xffU };
	const size_t nbytes = sizeof(bytes) / sizeof(bytes[0]);
	size_t i, j, k, l;

	for (i = 0; i < nbytes; i++) {
		for (j = 0; j < nbytes; j++) {
			for (k = 0; k < nbytes; k++) {
				check_alu(bytes[i], bytes[j], bytes[k]);
				check_bitfield(bytes[i], bytes[j], bytes[k]);
			}
		}
	}
	for (i = 0; i < nbytes; i++) {
		for (j = 0; j < nbytes; j++) {
			for (k = 0; k < nbytes; k++) {
				for (l = 0; l < nbytes; l++)
					check_mem(bytes[i], bytes[j], bytes[k],
						  bytes[l]);
			}
		}
	}
	for (i = 0; i < nbytes; i++) {
		check_shift(bytes[i]);
		check_movk(bytes[i]);
		check_ccmp(bytes[i], bytes[i]);
	}

	/* Sentinel: "no index register" packs into lane 0 and reads back 0xff. */
	check("reg_none.b0", f0(ARM64_AUX_MEM(ARM64_REG_NONE, 0U, 0U, 0U)),
	      ARM64_REG_NONE, ARM64_REG_NONE);
	check("reg_none.define", KPROG_ARM64_AUX_REG_NONE, 0xffU, 0xffU);

	/* Per-opcode aliasing: lane 1 is the source modifier, bitfield LSB and
	 * CCMP NZCV; lane 2 is the bitfield width, MOVK column, and the shift
	 * *amount* packed by the ALU modifier. (The shift *kind* is lane 0, checked
	 * by check_shift above.) */
	for (l = 0; l < 256U; l++) {
		__u32 v = (__u32)l;
		__u32 alu = ARM64_AUX_ALU(0U, v, 0U);
		__u32 bf = ARM64_AUX_BITFIELD(0U, v, 0U);
		__u32 cc = ARM64_AUX_CCMP(0U, v);
		__u32 alu_l2 = ARM64_AUX_ALU(0U, 0U, v);
		__u32 bw = ARM64_AUX_BITFIELD(0U, 0U, v);
		__u32 mk = ARM64_AUX_MOVK(v);

		/* Lane 1 shared across the three modifier-like fields. */
		check("alias.alu_l1", f1(alu), v, alu);
		check("alias.bf_l1", f1(bf), v, bf);
		check("alias.ccmp_l1", f1(cc), v, cc);
		check("alias.l1_equal", f1(alu), f1(bf), alu);
		check("alias.l1_equal_cc", f1(bf), f1(cc), bf);
		/* Lane 2 shared across the three shift-amount-like fields. */
		check("alias.alu_amount_l2", f2(alu_l2), v, alu_l2);
		check("alias.bfw_l2", f2(bw), v, bw);
		check("alias.movk_l2", f2(mk), v, mk);
		check("alias.l2_equal", f2(alu_l2), f2(bw), alu_l2);
		check("alias.l2_equal_movk", f2(bw), f2(mk), bw);
	}

	/* Exhaustive over each single lane byte: 256 values, other lanes zero. */
	for (l = 0; l < 256U; l++) {
		__u32 aux = ARM64_AUX_MEM((__u32)l, 0U, 0U, 0U);
		check("mem.b0_exh", f0(aux), l, aux);
		aux = ARM64_AUX_MEM(0U, (__u32)l, 0U, 0U);
		check("mem.b1_exh", f1(aux), l, aux);
		aux = ARM64_AUX_MEM(0U, 0U, (__u32)l, 0U);
		check("mem.b2_exh", f2(aux), l, aux);
		aux = ARM64_AUX_MEM(0U, 0U, 0U, (__u32)l);
		check("mem.b3_exh", f3(aux), l, aux);
	}

	if (failures) {
		printf("arm64 aux host cross-check: %d FAILURES\n", failures);
		return 1;
	}
	printf("arm64 aux host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
