/*
 * Host cross-check for the AArch64 simulator's routing of the write-register
 * destination-presence test through the generated contract (STEP 0103).
 *
 * The three writeback bodies `ARM64_SIM_L_WRITE_REG_WIDTH`,
 * `ARM64_SIM_L_WRITE_REG_PTR` and `ARM64_SIM_L_WRITE_REG_PTR_TAG` each guard
 * their GPR dispatch on `KPROG_ARM64_REG_WRITABLE(REG)` instead of restating
 * `(REG) != ARM64_XZR && (REG) != ARM64_REG_NONE`. This oracle drives all three
 * over the full register-number range plus the `SP` branch, and observes which
 * of the simulator's own state cells change against an independent model that
 * writes only when the number is neither `31` nor `0xff` (with `SP` handled by
 * the separate `(REG) == ARM64_SP` branch). Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_reg_presence_route_host.c -o /tmp/t_arpr
 *   /tmp/t_arpr
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
#define ORA_CAPTURE_PTR(REG, NAME) __p[__i++] = __a64_##NAME.ptr;
#define ORA_CAPTURE_TAG(REG, NAME) __t[__i++] = __a64_##NAME##_tag;

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

/* Capture all 31 GPR `.ptr` and `_tag` cells (caller-declared `void *[31]`,
 * `__u8[31]`). */
#define ORA_SNAPSHOT_PTR(ARR, TAGARR)                                       \
	do {                                                                \
		void **__p = (ARR);                                        \
		__u8 *__t = (TAGARR);                                      \
		unsigned __i = 0;                                          \
		ARM64_SIM_L_FOR_EACH_GPR(ORA_CAPTURE_PTR)                  \
		__i = 0;                                                   \
		ARM64_SIM_L_FOR_EACH_GPR(ORA_CAPTURE_TAG)                  \
	} while (0)

/* Drive `ARM64_SIM_L_WRITE_REG_WIDTH` for one register number and check that
 * exactly the model-predicted cells changed. */
static void check_width(unsigned reg, __u64 value, unsigned width, __s64 sp_value)
{
	__u64 before[31];
	__u64 after[31];
	__s64 sp_before;
	unsigned j;
	int want = model_writable(reg);
	__u64 masked = KPROG_ARM64_APPLY_WIDTH((value), (width));

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
			__u64 expect = before[j];

			if (reg == ARM64_SP) {
				/* The SP branch leaves GPRs alone. */
				;
			} else if (want && reg == j) {
				expect = masked;
			}
			if (after[j] != expect) {
				printf("MISMATCH width reg=%u cell=%s "
				       "got=0x%llx want=0x%llx\n",
				       reg, gpr_names[j],
				       (unsigned long long)after[j],
				       (unsigned long long)expect);
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

/* Drive `ARM64_SIM_L_WRITE_REG_PTR` / `_TAG` for one register number and check
 * that exactly the model-predicted `ptr`+tag cells changed. `tagged` selects the
 * tag-carrying form; `tag` is the tag it installs. */
static void check_ptr(unsigned reg, void *ptr, __u8 tag, int tagged)
{
	void *pbefore[31];
	__u8 tbefore[31];
	void *pafter[31];
	__u8 tafter[31];
	unsigned j;
	int want = model_writable(reg);
	__u8 want_tag = tagged ? tag : ARM64_SIM_TAG_SCALAR;

	cases++;
	{
		ARM64_SIM_L_DECLARE_STATE();
		ARM64_SIM_L_DECLARE_STACK();
		(void)__a64_n;
		(void)__a64_z;
		(void)__a64_c;
		(void)__a64_v;
		(void)__a64_lr;
		(void)__a64_v0;
		(void)__a64_v0_hi;

		ORA_FOR_EACH_IDX(ORA_SEED)
		ORA_SNAPSHOT_PTR(pbefore, tbefore);

		if (tagged) {
			ARM64_SIM_L_WRITE_REG_PTR_TAG(reg, ptr, tag);
		} else {
			ARM64_SIM_L_WRITE_REG_PTR(reg, ptr);
		}
		ORA_SNAPSHOT_PTR(pafter, tafter);

		for (j = 0; j < 31U; j++) {
			if (want && reg == j) {
				if (pafter[j] != ptr) {
					printf("MISMATCH ptr reg=%u cell=%s "
					       "got=%p want=%p\n",
					       reg, gpr_names[j], pafter[j], ptr);
					failures++;
				}
				if (tafter[j] != want_tag) {
					printf("MISMATCH ptr reg=%u cell=%s "
					       "tag got=%u want=%u\n",
					       reg, gpr_names[j],
					       (unsigned)tafter[j],
					       (unsigned)want_tag);
					failures++;
				}
			} else {
				if (pafter[j] != pbefore[j]) {
					printf("MISMATCH ptr reg=%u cell=%s "
					       "clobbered\n",
					       reg, gpr_names[j]);
					failures++;
				}
				if (tafter[j] != tbefore[j]) {
					printf("MISMATCH ptr reg=%u cell=%s "
					       "tag clobbered\n",
					       reg, gpr_names[j]);
					failures++;
				}
			}
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

	/* The generated constants must line up with the sim's register decode. */
	cases++;
	if (KPROG_ARM64_REG_XZR != ARM64_XZR ||
	    KPROG_ARM64_REG_NONE != ARM64_REG_NONE) {
		printf("MISMATCH constant drift: xzr %u vs %u, none %u vs %u\n",
		       (unsigned)KPROG_ARM64_REG_XZR, (unsigned)ARM64_XZR,
		       (unsigned)KPROG_ARM64_REG_NONE,
		       (unsigned)ARM64_REG_NONE);
		failures++;
	}

	/* Drive the three routed writeback bodies over the full register range,
	 * all four widths, several values, and both pointer forms. */
	for (reg = 0; reg <= 0xffU; reg++) {
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
				check_width(reg, values[vi], widths[wi],
					    (__s64)0x7ffffff00LL);
			}
		}
		check_ptr(reg, (void *)(unsigned long)(0x1000U + reg),
			  ARM64_SIM_TAG_SCALAR, 0);
		check_ptr(reg, (void *)(unsigned long)(0x2000U + reg),
			  ARM64_SIM_TAG_MAP_PTR, 1);
	}

	if (failures != 0) {
		printf("arm64 reg presence route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 reg presence route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
