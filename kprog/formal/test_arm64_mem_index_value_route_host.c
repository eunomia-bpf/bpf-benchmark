/*
 * Route host cross-check for the AArch64 simulator's routing of its memory
 * address offset's index value through the machine-checked
 * `generated/arm64_mem_index_value.h` contract (STEP 0142). The body under test
 * is the real simulator macro `ARM64_SIM_L_MEM_BASE_OFF`, driven directly at
 * both index-value sources.
 *
 * The contract fact this oracle exercises, planted so a wrong selection is
 * numerically distinguishable: a memory address offset adds the *source-modified
 * index register value* exactly when the addressing mode carries an index
 * register, and contributes the literal *zero* when it does not (the sentinel
 * index operand). The oracle plants a *nonzero* value in the index register and
 * seeds the whole register file with a distinct per-register pattern, so a body
 * that collapsed the selection (always the index value, or always zero) or
 * swapped its arms shows up as a differing offset: at a present index the offset
 * must carry the planted register value, at the sentinel it must be the
 * immediate alone regardless of the register file.
 *
 * The model below restates the index-value source selection from the raw
 * `index != ARM64_REG_NONE` fact (never from the generated selector) and the
 * independent flag decode/suppression, so a misroute shows up as a differing
 * offset.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mem_index_value_route_host.c -o build/test_arm64_mem_index_value_route_host &&
 *   ./build/test_arm64_mem_index_value_route_host
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

/* The independent index-presence fact: an addressing mode carries an index
 * register exactly when its index operand is not the sentinel. */
static int model_present(unsigned index)
{
	return index != ARM64_REG_NONE;
}

/* The independent index-value source selection, restated from the raw fact:
 * the index register's own value exactly when the mode carries an index
 * register, a literal zero otherwise. */
static __u64 model_index_value(unsigned index)
{
	return model_present(index) ? mreg[index] : 0ULL;
}

/* `ARM64_SIM_L_MEM_BASE_OFF`, restated with the independent presence fact, the
 * independent index-value selection, the independent suppression and the
 * identity source modifier/shift the oracle drives. */
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

/* The generated selector must name the same source the independent 2-way
 * statement names, at the raw fact the offset computes (the presence test). */
static void check_selector(void)
{
	static const unsigned raws[] = { 0U, 1U, 5U, 31U, 254U, 255U };
	unsigned i;

	cases++;
	if (KPROG_ARM64_MEM_INDEX_VALUE_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_MEM_INDEX_VALUE_COUNT);
		failures++;
	}

	for (i = 0; i < sizeof(raws) / sizeof(raws[0]); i++) {
		unsigned pres = KPROG_ARM64_MEM_INDEX_PRESENT(raws[i]);
		unsigned got = KPROG_ARM64_MEM_INDEX_VALUE(pres);
		unsigned want = pres ? KPROG_ARM64_MEM_INDEX_VALUE_REGISTER
				     : KPROG_ARM64_MEM_INDEX_VALUE_ZERO;

		cases++;
		if (got != want) {
			printf("MISMATCH selector raw=%u pres=%u got=%u "
			       "want=%u\n", raws[i], pres, got, want);
			failures++;
		}
		cases++;
		if ((got == KPROG_ARM64_MEM_INDEX_VALUE_REGISTER) !=
		    (pres != 0U)) {
			printf("MISMATCH selector/presence raw=%u\n", raws[i]);
			failures++;
		}
	}
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
		1ULL, 8ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0xfffffffffffffff8ULL,
	};
	static const __s64 imms[] = {
		0, 8, -4, 64, 0x7fffffff, -0x80000000LL,
	};
	size_t ia, la, fl, rv, im;

	check_selector();

	/* The routed offset body: for every index operand, `AUX` index lane
	 * (deliberately allowed to disagree with the operand), raw flag byte,
	 * nonzero register value and immediate, the real
	 * `ARM64_SIM_L_MEM_BASE_OFF` must equal the independent model. */
	for (ia = 0; ia < sizeof(index_args) / sizeof(index_args[0]); ia++) {
		unsigned index = index_args[ia];

		for (la = 0; la < sizeof(lane0_args) /
				     sizeof(lane0_args[0]); la++) {
			__u8 lane0 = (__u8)lane0_args[la];

			for (fl = 0; fl < sizeof(flags_set) /
					     sizeof(flags_set[0]); fl++) {
				__u32 aux = ARM64_AUX_MEM(lane0, ARM64_MOD_NONE,
							  0U, flags_set[fl]);

				for (rv = 0; rv < sizeof(reg_values) /
						     sizeof(reg_values[0]); rv++) {
					__u64 value = reg_values[rv];

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
					 * misroute that reads another register
					 * is observable, then plant the
					 * nonzero value at the index. */
					{
						unsigned j;

						for (j = 0; j < 31U; j++) {
							__u64 pv =
								pattern_reg(j);

							ARM64_SIM_L_WRITE_REG_WIDTH(
								j, pv,
								ARM64_WIDTH_64);
							mreg[j] = pv;
						}
					}
					if (model_present(index)) {
						ARM64_SIM_L_WRITE_REG_WIDTH(
							index, value,
							ARM64_WIDTH_64);
						mreg[index] = value;
					}

					for (im = 0; im < sizeof(imms) /
							     sizeof(imms[0]); im++) {
						__s64 imm = imms[im];
						__s64 got;
						__s64 want;

						got = ARM64_SIM_L_MEM_BASE_OFF(
							aux, index, imm);
						want = model_base_off(aux,
								      index,
								      imm);
						cases++;
						if (got != want) {
							printf("MISMATCH routed "
							       "offset index=%u "
							       "lane0=%u flags=%u "
							       "rv=0x%llx "
							       "imm=%lld "
							       "got=%lld "
							       "want=%lld\n",
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

	/* The sources are numerically distinguishable: at a present index the
	 * offset must differ from the immediate by the planted register value,
	 * at the sentinel it must equal the immediate regardless of the
	 * register file. */
	{
		__u32 aux = ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0U, 0U);
		__s64 imm = 0x1000;
		__u64 planted = 0x123455;

		ARM64_SIM_L_DECLARE_STATE();
		ARM64_SIM_L_DECLARE_STACK();
		(void)__a64_n;
		(void)__a64_z;
		(void)__a64_c;
		(void)__a64_v;
		(void)__a64_lr;
		(void)__a64_v0;
		(void)__a64_v0_hi;

		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, planted,
					    ARM64_WIDTH_64);
		mreg[ARM64_X1] = planted;

		cases++;
		if (ARM64_SIM_L_MEM_BASE_OFF(aux, ARM64_X1, imm) !=
		    imm + (__s64)planted) {
			printf("MISMATCH present offset did not carry the "
			       "index value\n");
			failures++;
		}
		cases++;
		if (ARM64_SIM_L_MEM_BASE_OFF(aux, ARM64_REG_NONE, imm) != imm) {
			printf("MISMATCH sentinel offset not disp-only\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 mem index value route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 mem index value route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
