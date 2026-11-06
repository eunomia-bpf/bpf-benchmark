/*
 * Host cross-check for the AArch64 simulator's routing of the write-register
 * width body selection through the generated contract (STEP 0144).
 *
 * The writeback body `ARM64_SIM_L_WRITE_REG_WIDTH` masks its value to the
 * access width (`KPROG_ARM64_APPLY_WIDTH`), then selects the writeback body
 * through the generated 2-way selector `KPROG_ARM64_WRITE_ARM` instead of a hand
 * `if ((WIDTH) == ARM64_WIDTH_32)`: the 32-bit code reaches the truncating
 * `ARM64_SIM_L_WRITE_REG32_CASE` body, every other width code the full-value
 * `ARM64_SIM_L_WRITE_REG64_CASE` body. This oracle drives the routed body over
 * the full register-number range, all four width codes, and several values, and
 * observes which of the simulator's own state cells change against an
 * independent model that masks first and then truncates exactly when the width
 * code is 4. Because the value is masked before the body choice, the two bodies
 * differ only where the width code is not the 32-bit code (the full body carries
 * the 64-bit-masked value and the truncating body drops its upper 32 bits), so
 * the model's width-body-sensitive expectation catches a wrong selector code or
 * a swapped body assignment. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_write_arm_route_host.c -o /tmp/t_awar
 *   /tmp/t_awar
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

/* The independent destination-presence test, restated from the literal register
 * numbers rather than the generated macros. */
static int model_writable(unsigned reg)
{
	return reg != 31U && reg != 0xffU;
}

/* The independent width body choice: the 32-bit truncating body exactly when
 * the resolved width code is the 32-bit code, the full-value body otherwise. */
static int model_narrow(unsigned width)
{
	return width == 4U;
}

/* A deterministic per-register pattern, with high bits set so a 64-bit write
 * and a 32-bit write are distinguishable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static const char *gpr_names[31] = {
	"x0",  "x1",  "x2",  "x3",  "x4",  "x5",  "x6",  "x7",
	"x8",  "x9",  "x10", "x11", "x12", "x13", "x14", "x15",
	"x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23",
	"x24", "x25", "x26", "x27", "x28", "x29", "x30",
};

/* Sequence the register numbers 0..30 through `X`, mirroring the
 * `ARM64_SIM_L_FOR_EACH_GPR` order so a captured array lines up cell-for-cell. */
#define ORA_FOR_EACH_IDX(X)                                                 \
	X(0) X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9)                  \
	X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19)        \
	X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30)

#define ORA_CAPTURE_X(REG, NAME) __p[__i++] = __a64_##NAME.x;

/* Seed every GPR scalar from `pattern_reg`, so a write routed to the wrong cell
 * is caught by the capture compare. */
#define ORA_SEED(IDX) ARM64_SIM_L_WRITE_REG_WIDTH(IDX, pattern_reg(IDX), \
						  ARM64_WIDTH_64);

/* Capture all 31 GPR `.x` cells into `ARR` (caller-declared `__u64[31]`). */
#define ORA_SNAPSHOT_X(ARR)                                                 \
	do {                                                                \
		__u64 *__p = (ARR);                                        \
		unsigned __i = 0;                                          \
		ARM64_SIM_L_FOR_EACH_GPR(ORA_CAPTURE_X)                    \
	} while (0)

/* Drive `ARM64_SIM_L_WRITE_REG_WIDTH` for one register number and check that
 * exactly the model-predicted cells changed. The model masks the value to the
 * width, then truncates it to 32 bits exactly when the width code is the 32-bit
 * code — the width-body-sensitive expectation the routed selector must match. */
static void check_width(unsigned reg, __u64 value, unsigned width, __s64 sp_value)
{
	__u64 before[31];
	__u64 after[31];
	__s64 sp_before;
	unsigned j;
	int want = model_writable(reg);
	__u64 masked = KPROG_ARM64_APPLY_WIDTH((value), (width));
	__u64 expect = model_narrow(width) ? (__u64)(__u32)masked : masked;

	cases++;
	{
		ARM64_SIM_L_DECLARE_STATE();
		ARM64_SIM_L_DECLARE_STACK();
		(void)__a64_n;
		(void)__a64_z;
		(void)__a64_c;
		(void)__a64_v;
		(void)__a64_lr;
		(void)__a64_v0_hi;

		ORA_FOR_EACH_IDX(ORA_SEED)
		ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_SP, 0, ARM64_WIDTH_64);
		__a64_sp = sp_value;
		ORA_SNAPSHOT_X(before);
		sp_before = __a64_sp;

		ARM64_SIM_L_WRITE_REG_WIDTH(reg, value, width);
		ORA_SNAPSHOT_X(after);

		for (j = 0; j < 31U; j++) {
			__u64 cell = before[j];

			if (reg == ARM64_SP) {
				/* The SP branch leaves GPRs alone. */
				;
			} else if (want && reg == j) {
				cell = expect;
			}
			if (after[j] != cell) {
				printf("MISMATCH width reg=%u cell=%s "
				       "got=0x%llx want=0x%llx\n",
				       reg, gpr_names[j],
				       (unsigned long long)after[j],
				       (unsigned long long)cell);
				failures++;
			}
		}

		if (reg == ARM64_SP) {
			__s64 sp_expect = (__s64)masked;

			if (__a64_sp != sp_expect) {
				printf("MISMATCH width reg=SP sp got=%lld "
				       "want=%lld\n",
				       (long long)__a64_sp,
				       (long long)sp_expect);
				failures++;
			}
		} else if (__a64_sp != sp_before) {
			printf("MISMATCH width reg=%u clobbered sp\n", reg);
			failures++;
		}
	}
}

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 0xffffffffffffffffULL, 0x8000000000000000ULL,
		0xdeadbeefcafef00dULL, 0x123456789ULL,
	};
	static const unsigned widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	__u32 reg;
	size_t vi, wi;

	/* Destination presence over the full register-number range against the
	 * independent literal test. */
	for (reg = 0; reg <= 0xffU; reg++) {
		__u8 want = model_writable(reg) ? 1U : 0U;
		__u8 got = KPROG_ARM64_REG_WRITABLE((__u8)reg);

		cases++;
		if (got != want) {
			printf("MISMATCH routed present reg=%u got=%u want=%u\n",
			       reg, got, want);
			failures++;
		}
	}

	/* The generated constants must line up with the sim's width decode. */
	cases++;
	if (KPROG_ARM64_WRITE_ARM_W32 != ARM64_WIDTH_32) {
		printf("MISMATCH constant drift: arm width32 %u vs width32 %u\n",
		       (unsigned)KPROG_ARM64_WRITE_ARM_W32,
		       (unsigned)ARM64_WIDTH_32);
		failures++;
	}

	/* Drive the routed writeback body over the full register range, all four
	 * widths, and several values. */
	for (reg = 0; reg <= 0xffU; reg++) {
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
				check_width(reg, values[vi], widths[wi],
					    (__s64)0x7ffffff00LL);
			}
		}
	}

	if (failures != 0) {
		printf("arm64 write arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 write arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
