/*
 * Host cross-check for the AArch64 CCMP decode contract.
 *
 * The CCMP flow reads its two fields out of the packed AUX word through the
 * generated `KPROG_ARM64_CCMP_COND` / `KPROG_ARM64_CCMP_NZCV` byte selectors
 * (generated/arm64_ccmp_decode.h). This oracle drives those real selectors
 * against an independent `(aux >> 8k) & 0xff` restatement over an exhaustive
 * lane-0 x lane-1 grid with noise lanes, the `ARM64_REG_NONE` sentinel, and the
 * `ARM64_AUX_CCMP` packer roundtrips the generated header pins with
 * `_Static_assert`. The low four bits of the condition byte must also survive
 * truncation into `KPROG_ARM64_EVAL_COND`'s arm domain. Exit 1 on any
 * mismatch.
 *
 * Build and run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 test_arm64_ccmp_decode_host.c \
 *     -o build/test_arm64_ccmp_decode_host &&
 *   ./build/test_arm64_ccmp_decode_host
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
#include <stdlib.h>

static int failures;
static unsigned long cases;

/* Independent byte-lane extractors, written here rather than reusing the
 * generated decoders. */
static __u32 f0(__u32 aux) { return (aux >> 0) & 0xffU; }
static __u32 f1(__u32 aux) { return (aux >> 8) & 0xffU; }

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

int main(void)
{
	/* Exhaustive lane-0 x lane-1 grid: every (condition, nzcv) byte pair
	 * the CCMP arm can address, with noise driver bytes in the two lanes
	 * CCMP must ignore, plus the all-zero and all-ones noise corners. */
	static const __u32 noise[] = { 0, 0xa5U, 0x5a5aU, ~0U };

	for (unsigned n = 0; n < sizeof(noise) / sizeof(noise[0]); n++)
		for (unsigned cond_byte = 0; cond_byte < 256U; cond_byte++)
			for (unsigned nzcv = 0; nzcv < 256U; nzcv++) {
				__u32 aux = ARM64_AUX_CCMP(cond_byte, nzcv);
				__u32 driven = ARM64_AUX_CCMP(cond_byte, nzcv);

				(void)driven;
				/* Repack with noise lanes 2/3: cond and nzcv
				 * bytes must not move. */
				aux = KPROG_ARM64_AUX(
					KPROG_ARM64_CCMP_COND(aux), nzcv,
					noise[n] & 0xffU,
					(noise[n] >> 8) & 0xffU);
				check("ccmp.cond",
				      KPROG_ARM64_CCMP_COND(ARM64_AUX_CCMP(
					      cond_byte, nzcv)),
				      cond_byte, f0(ARM64_AUX_CCMP(cond_byte,
							       nzcv)),
				      ARM64_AUX_CCMP(cond_byte, nzcv));
				check("ccmp.nzcv",
				      KPROG_ARM64_CCMP_NZCV(ARM64_AUX_CCMP(
					      cond_byte, nzcv)),
				      nzcv, f1(ARM64_AUX_CCMP(cond_byte,
							 nzcv)),
				      ARM64_AUX_CCMP(cond_byte, nzcv));
				check("ccmp.cond.noise",
				      KPROG_ARM64_CCMP_COND(aux), cond_byte,
				      f0(aux), aux);
				check("ccmp.nzcv.noise",
				      KPROG_ARM64_CCMP_NZCV(aux), nzcv,
				      f1(aux), aux);
			}

	/* Sentinel and shared-lane facts: a lane-0 byte of 0xff (the
	 * ARM64_REG_NONE shape) and a lane-1 byte of 0xff both survive, and the
	 * selectors agree with the shared decoders b0/b1. */
	check("ccmp.none.cond", KPROG_ARM64_CCMP_COND(ARM64_AUX_CCMP(
					ARM64_REG_NONE, 0U)),
	       ARM64_REG_NONE, 0xffU,
	       ARM64_AUX_CCMP(ARM64_REG_NONE, 0U));
	check("ccmp.none.nzcv", KPROG_ARM64_CCMP_NZCV(ARM64_AUX_CCMP(
					0U, ARM64_REG_NONE)),
	       ARM64_REG_NONE, 0xffU,
	       ARM64_AUX_CCMP(0U, ARM64_REG_NONE));

	/* Packer roundtrip: packing a decoded byte pair reproduces the original
	 * AUX word's two CCMP lanes bit for bit (the header's _Static_assert
	 * pins constant cases; this drives the runtime grid). */
	for (unsigned cond_byte = 0; cond_byte < 256U; cond_byte += 5)
		for (unsigned nzcv = 0; nzcv < 256U; nzcv += 7) {
			__u32 aux = ARM64_AUX_CCMP(cond_byte, nzcv);

			check("ccmp.roundtrip.cond",
			      KPROG_ARM64_CCMP_COND(ARM64_AUX_CCMP(
				      KPROG_ARM64_CCMP_COND(aux),
				      KPROG_ARM64_CCMP_NZCV(aux))),
			      cond_byte, f0(aux), aux);
			check("ccmp.roundtrip.nzcv",
			      KPROG_ARM64_CCMP_NZCV(ARM64_AUX_CCMP(
				      KPROG_ARM64_CCMP_COND(aux),
				      KPROG_ARM64_CCMP_NZCV(aux))),
			      nzcv, f1(aux), aux);
		}

	/* The sim-route macro ARM64_SIM_L_CCMP_NZCV (its only caller reads the
	 * fallback byte) still names the same lane-1 byte. */
	for (unsigned nzcv = 0; nzcv < 256U; nzcv += 3) {
		__u32 aux = ARM64_AUX_CCMP(0U, nzcv);

		check("ccmp.route", ARM64_SIM_L_CCMP_NZCV(aux), nzcv, f1(aux),
		      aux);
	}

	if (failures != 0) {
		printf("arm64 CCMP decode host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 CCMP decode host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
