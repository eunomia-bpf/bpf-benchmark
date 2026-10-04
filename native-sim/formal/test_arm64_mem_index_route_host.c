/*
 * Host cross-check for the AArch64 simulator's routing of the load/store
 * address-offset body through the machine-checked generated memory-index
 * presence contract `generated/arm64_mem_index.h` (STEP 0102).
 *
 * The body under test is the real simulator macro `ARM64_SIM_L_MEM_BASE_OFF`,
 * which resolves its `HAS_INDEX` flag and its index-value selector from
 * `KPROG_ARM64_MEM_INDEX_PRESENT(INDEX)` instead of a restated sentinel
 * comparison. The oracle drives the macro directly and compares against an
 * independent model that restates the presence test (`INDEX != ARM64_REG_NONE`)
 * and the offset accumulation from the raw `AUX` flag byte, so a misroute that
 * selects the wrong index source shows up as a differing offset.
 *
 * The facts each case plants, and the misroute it makes numerically
 * distinguishable:
 *
 *   - Presence follows the `INDEX` operand: an index register contributes its
 *     value, the sentinel `ARM64_REG_NONE` (`0xff`) contributes nothing. A body
 *     that reads the *wrong* byte -- e.g. the `AUX` index lane when it disagrees
 *     with the operand -- is caught by the deliberately mismatched forms below.
 *   - The sentinel takes the displacement-only arm: the offset is the immediate
 *     (or zero under pre/post suppression) and a poisoned register file cannot
 *     leak into it.
 *   - The offset suppression is still sourced from the raw flag byte, so a body
 *     that loses the pre/post suppression folds the immediate into the address.
 *   - The index value is the plain source modifier identity the oracle drives
 *     (`MOD == ARM64_MOD_NONE`, `SHIFT == 0`), so the model's index term is just
 *     the register value.
 *
 * Build and run:
 *   cd native-sim/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mem_index_route_host.c -o build/test_arm64_mem_index_route_host &&
 *   ./build/test_arm64_mem_index_route_host
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

/* The simulator header expects this hook; the oracle drives only fully
 * supported arms, so the no-op stub is never the reason for a difference. */
static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

/* The register file the independent model tracks, parallel to the simulator's
 * own GPR state. */
static __u64 mreg[31];

/* The independent top-byte flag decode and suppression, restated from the raw
 * `AUX` word (never from the generated macros). */
static __u32 model_flags(__u32 aux)
{
	return (__u32)((aux >> 24) & 0xffU);
}

static int model_suppress(__u32 aux)
{
	__u32 f = model_flags(aux);

	return (f & ARM64_MEM_PRE) != 0U || (f & ARM64_MEM_POST) != 0U;
}

/* The independent presence test: an addressing mode carries an index register
 * exactly when its index operand is not the sentinel. */
static int model_present(unsigned index)
{
	return index != ARM64_REG_NONE;
}

static __u64 model_index_value(unsigned index)
{
	return model_present(index) ? mreg[index] : 0ULL;
}

/* `ARM64_SIM_L_MEM_BASE_OFF`, restated with the independent presence test, the
 * independent suppression and the identity source modifier the oracle drives. */
static __s64 model_base_off(__u32 aux, unsigned index, __s64 imm)
{
	return (__s64)KPROG_ARM64_MEM_OFFSET(
		(__u64)model_suppress(aux),
		(__u64)model_present(index),
		(__u64)imm,
		model_index_value(index));
}

/* A deterministic register pattern: distinct per index, with high bits set so a
 * 64-bit-vs-narrow read is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

int main(void)
{
	static const unsigned index_args[] = {
		ARM64_REG_NONE, ARM64_X0, ARM64_X1, ARM64_X15, ARM64_X30,
	};
	static const unsigned lane0_args[] = {
		ARM64_REG_NONE, ARM64_X1, ARM64_REG_NONE,
		ARM64_REG_NONE, ARM64_X1,
	};
	static const unsigned flags_set[] = {
		0U,
		ARM64_MEM_PRE,
		ARM64_MEM_POST,
		ARM64_MEM_PRE | ARM64_MEM_POST,
	};
	static const __u64 reg_values[] = {
		0ULL, 1ULL, 8ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0xfffffffffffffff8ULL,
	};
	static const __s64 imms[] = {
		0, 8, -4, 64, 0x7fffffff, -0x80000000LL,
	};
	unsigned long case_count = 0;
	__u32 byte;
	size_t ia, la, fl, rv, im;

	/* Presence and arm over the whole index-byte range, including the
	 * sentinel boundary and its immediate neighbours. */
	for (byte = 0; byte <= 0xffU; byte++) {
		__u8 want_present = (byte != 0xffU) ? 1U : 0U;
		__u8 got_present = KPROG_ARM64_MEM_INDEX_PRESENT((__u8)byte);

		cases++;
		if (got_present != want_present) {
			printf("MISMATCH routed present byte=%u got=%u want=%u\n",
			       byte, got_present, want_present);
			failures++;
		}
		cases++;
		if (KPROG_ARM64_MEM_INDEX_ARM((__u8)byte) !=
		    (want_present ? KPROG_ARM64_MEM_INDEX_ARM_PRESENT
				  : KPROG_ARM64_MEM_INDEX_ARM_ABSENT)) {
			printf("MISMATCH routed arm byte=%u\n", byte);
			failures++;
		}
	}

	/* The generated sentinel and arm constants must line up with the operand
	 * contract the memory macros already use. */
	cases++;
	if (KPROG_ARM64_MEM_INDEX_SENTINEL != ARM64_REG_NONE ||
	    KPROG_ARM64_MEM_INDEX_SENTINEL != KPROG_ARM64_AUX_REG_NONE) {
		printf("MISMATCH sentinel drift: %u vs %u vs %u\n",
		       (unsigned)KPROG_ARM64_MEM_INDEX_SENTINEL,
		       (unsigned)ARM64_REG_NONE,
		       (unsigned)KPROG_ARM64_AUX_REG_NONE);
		failures++;
	}
	cases++;
	if (KPROG_ARM64_MEM_INDEX_ARM_PRESENT == KPROG_ARM64_MEM_INDEX_ARM_ABSENT) {
		printf("MISMATCH index arms collide\n");
		failures++;
	}

	/* The routed offset body: for every index operand, `AUX` index lane
	 * (deliberately allowed to disagree with the operand), raw flag byte,
	 * register value and immediate, the real `ARM64_SIM_L_MEM_BASE_OFF` must
	 * equal the independent model. */
	for (ia = 0; ia < sizeof(index_args) / sizeof(index_args[0]); ia++) {
		unsigned index = index_args[ia];

		for (la = 0; la < sizeof(lane0_args) / sizeof(lane0_args[0]); la++) {
			__u8 lane0 = (__u8)lane0_args[la];

			for (fl = 0; fl < sizeof(flags_set) / sizeof(flags_set[0]); fl++) {
				__u32 aux = ARM64_AUX_MEM(lane0, ARM64_MOD_NONE, 0U,
							  flags_set[fl]);

				for (rv = 0; rv < sizeof(reg_values) / sizeof(reg_values[0]); rv++) {
					__u64 value = reg_values[rv];
					size_t k;

					for (k = 0; k < sizeof(reg_values) /
								sizeof(reg_values[0]); k++) {
						unsigned other = ARM64_X1;
						__s64 got, want;
						size_t j;

						ARM64_SIM_L_DECLARE_STATE();
						ARM64_SIM_L_DECLARE_STACK();
						(void)__a64_n;
						(void)__a64_z;
						(void)__a64_c;
						(void)__a64_v;
						(void)__a64_lr;
						(void)__a64_v0;
						(void)__a64_v0_hi;

						/* Seed the whole register file so a
						 * misroute that reads another
						 * register is observable. */
						for (j = 0; j < 31U; j++) {
							__u64 pv = pattern_reg((unsigned)j);

							ARM64_SIM_L_WRITE_REG_WIDTH(
								(unsigned)j, pv,
								ARM64_WIDTH_64);
							mreg[j] = pv;
						}
						if (model_present(index)) {
							ARM64_SIM_L_WRITE_REG_WIDTH(
								index, value,
								ARM64_WIDTH_64);
							mreg[index] = value;
						}
						/* A separate register the model
						 * does not consult: a body that
						 * misreads `AUX` lane 0 here is
						 * caught below. */
						ARM64_SIM_L_WRITE_REG_WIDTH(
							other, value ^ 0x5555ULL,
							ARM64_WIDTH_64);
						mreg[other] = value ^ 0x5555ULL;

						for (im = 0; im < sizeof(imms) /
									sizeof(imms[0]); im++) {
							__s64 imm = imms[im];

							got = ARM64_SIM_L_MEM_BASE_OFF(
								aux, index, imm);
							want = model_base_off(aux,
									      index,
									      imm);
							cases++;
							case_count++;
							if (got != want) {
								printf("MISMATCH routed offset "
								       "index=%u lane0=%u flags=%u "
								       "rv=0x%llx imm=%lld "
								       "got=%lld want=%lld\n",
								       index, lane0,
								       flags_set[fl],
								       (unsigned long long)value,
								       (long long)imm,
								       (long long)got,
								       (long long)want);
								failures++;
							}
						}
					}
				}
			}
		}
	}

	/* The sentinel takes the displacement-only arm and ignores a poisoned
	 * register file. */
	{
		__u32 aux = ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0U, 0U);
		__s64 imm = -123;

		ARM64_SIM_L_DECLARE_STATE();
		ARM64_SIM_L_DECLARE_STACK();
		(void)__a64_n;
		(void)__a64_z;
		(void)__a64_c;
		(void)__a64_v;
		(void)__a64_lr;
		(void)__a64_v0;
		(void)__a64_v0_hi;

		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, 0xdeadbeefcafef00dULL,
					    ARM64_WIDTH_64);
		mreg[ARM64_X1] = 0xdeadbeefcafef00dULL;
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2, 0x123456789ULL,
					    ARM64_WIDTH_64);
		mreg[ARM64_X2] = 0x123456789ULL;

		cases++;
		if (ARM64_SIM_L_MEM_BASE_OFF(aux, ARM64_REG_NONE, imm) != imm) {
			printf("MISMATCH sentinel not disp-only\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 mem index route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 mem index route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
