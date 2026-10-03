/*
 * Host cross-check for the AArch64 simulator's routing of its AUX lane
 * decoders through the machine-checked `generated/arm64_aux.h` layout
 * (STEP 0093). The decoders under test are the real simulator macros
 * `ARM64_SIM_L_MOD`, `_SHIFT`, `_MEM_INDEX`, `_MEM_FLAGS`, `_BITFIELD_LSB`,
 * `_BITFIELD_WIDTH` and `_CCMP_NZCV`, each of which is a thin alias of a
 * generated `KPROG_ARM64_AUX_B*` decoder.
 *
 * The contract facts this oracle pins, each planted so a wrong lane is
 * numerically distinguishable:
 *
 *   - Lane roles: the ALU opcode / memory index / bitfield kind / shift kind
 *     byte is lane 0; the source modifier / bitfield LSB / CCMP NZCV byte is
 *     lane 1; the shift amount / bitfield width / MOVK column byte is lane 2;
 *     the memory-flag byte is lane 3.
 *   - Every decoder is checked twice: against the simulator macro under test,
 *     and (independently) against a local `(aux >> 8k) & 0xff` restatement of
 *     the byte it must return. A decoder pointed at the wrong lane differs from
 *     the intended field value; a packer and decoder that are wrong *together*
 *     differ from the independent restatement.
 *   - The `ARM64_REG_NONE` sentinel is a lane-0 byte: a memory operand with no
 *     index reads `0xff` back through `ARM64_SIM_L_MEM_INDEX`.
 *
 * Build and run:
 *   cd native-sim/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_aux_route_host.c -o build/test_arm64_aux_route_host &&
 *   ./build/test_arm64_aux_route_host
 */

#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>

/* The simulator header's unsupported-opcode hook is declared inside the
 * dispatch macro; the oracle drives only the AUX lane macros, which never
 * expand it. */

static int failures;
static unsigned long cases;

/* Independent byte-lane extractors, written here rather than reusing the
 * generated decoders. */
static __u32 f0(__u32 aux) { return (aux >> 0) & 0xffU; }
static __u32 f1(__u32 aux) { return (aux >> 8) & 0xffU; }
static __u32 f2(__u32 aux) { return (aux >> 16) & 0xffU; }
static __u32 f3(__u32 aux) { return (aux >> 24) & 0xffU; }

/* A decoder result must equal both the intended field value and the independent
 * restatement of the lane it is routed to. */
static void check(const char *what, unsigned long got, unsigned long want,
		  unsigned long lane, __u32 aux)
{
	cases++;
	if (got != want) {
		printf("MISMATCH %s: aux=0x%08x got=%lu want=%lu\n", what, aux,
		       got, want);
		failures++;
	}
	cases++;
	if (got != lane) {
		printf("MISMATCH %s (lane): aux=0x%08x got=%lu lane=%lu\n", what,
		       aux, got, lane);
		failures++;
	}
}

/* ALU operand: opcode lane 0, modifier lane 1, shift amount lane 2. */
static void check_alu(__u32 opcode, __u32 mod, __u32 shift)
{
	__u32 aux = ARM64_AUX_ALU(opcode, mod, shift);

	check("alu.mod", ARM64_SIM_L_MOD(aux), mod & 0xffU, f1(aux), aux);
	check("alu.shift", ARM64_SIM_L_SHIFT(aux), shift & 0xffU, f2(aux), aux);
	check("alu.index", ARM64_SIM_L_MEM_INDEX(aux), opcode & 0xffU, f0(aux),
	      aux);
}

/* Memory operand: index lane 0, modifier lane 1, shift lane 2, flags lane 3. */
static void check_mem(__u32 index, __u32 mod, __u32 shift, __u32 flags)
{
	__u32 aux = ARM64_AUX_MEM(index, mod, shift, flags);

	check("mem.index", ARM64_SIM_L_MEM_INDEX(aux), index & 0xffU, f0(aux),
	      aux);
	check("mem.mod", ARM64_SIM_L_MOD(aux), mod & 0xffU, f1(aux), aux);
	check("mem.shift", ARM64_SIM_L_SHIFT(aux), shift & 0xffU, f2(aux), aux);
	check("mem.flags", ARM64_SIM_L_MEM_FLAGS(aux), flags & 0xffU, f3(aux),
	      aux);
}

/* Bitfield operand: kind lane 0, LSB lane 1, width lane 2. */
static void check_bitfield(__u32 op, __u32 lsb, __u32 width)
{
	__u32 aux = ARM64_AUX_BITFIELD(op, lsb, width);

	check("bf.lsb", ARM64_SIM_L_BITFIELD_LSB(aux), lsb & 0xffU, f1(aux),
	      aux);
	check("bf.width", ARM64_SIM_L_BITFIELD_WIDTH(aux), width & 0xffU,
	      f2(aux), aux);
}

/* CCMP operand: condition lane 0, NZCV lane 1. The condition and NZCV are
 * distinct so a swap of the two lanes is observable. */
static void check_ccmp(__u32 cond, __u32 nzcv)
{
	__u32 aux = ARM64_AUX_CCMP(cond, nzcv);

	check("ccmp.nzcv", ARM64_SIM_L_CCMP_NZCV(aux), nzcv & 0xffU, f1(aux),
	      aux);
}

/* Shift-kind operand: the kind is lane 0 (shared with the ALU opcode); the
 * shift handler switches on the low byte, so lane 0 must read it back. */
static void check_shift_kind(__u32 kind)
{
	__u32 aux = ARM64_AUX_SHIFT(kind);

	check("shift.kind", KPROG_ARM64_AUX_B0(aux), kind & 0xffU, f0(aux), aux);
}

/* MOVK operand: insertion column lane 2, read back through L_SHIFT. */
static void check_movk(__u32 col)
{
	__u32 aux = ARM64_AUX_MOVK(col);

	check("movk.column", ARM64_SIM_L_SHIFT(aux), col & 0xffU, f2(aux), aux);
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
		for (j = 0; j < nbytes; j++) {
			check_movk(bytes[i]);
			check_shift_kind(bytes[i]);
			check_ccmp(bytes[i], bytes[j]);
		}
	}

	/* Sentinel: "no index register" reads back through the index decoder. */
	check("reg_none",
	      ARM64_SIM_L_MEM_INDEX(
		      ARM64_AUX_MEM(ARM64_REG_NONE, 0U, 0U, 0U)),
	      ARM64_REG_NONE, f0(ARM64_AUX_MEM(ARM64_REG_NONE, 0U, 0U, 0U)),
	      ARM64_AUX_MEM(ARM64_REG_NONE, 0U, 0U, 0U));

	/* Exhaustive over each lane: 256 values, other lanes zero, all four
	 * decoders agree with the independent restatement. */
	for (l = 0; l < 256U; l++) {
		__u32 aux = ARM64_AUX_MEM((__u32)l, 0U, 0U, 0U);
		check("lane0", ARM64_SIM_L_MEM_INDEX(aux), l, f0(aux), aux);
		aux = ARM64_AUX_MEM(0U, (__u32)l, 0U, 0U);
		check("lane1", ARM64_SIM_L_MOD(aux), l, f1(aux), aux);
		aux = ARM64_AUX_MEM(0U, 0U, (__u32)l, 0U);
		check("lane2", ARM64_SIM_L_SHIFT(aux), l, f2(aux), aux);
		aux = ARM64_AUX_MEM(0U, 0U, 0U, (__u32)l);
		check("lane3", ARM64_SIM_L_MEM_FLAGS(aux), l, f3(aux), aux);
	}

	if (failures != 0) {
		printf("arm64 aux route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 aux route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
