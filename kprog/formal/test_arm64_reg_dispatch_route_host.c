/*
 * Host cross-check for the AArch64 simulator's routing of the decoded
 * register number through the generated dispatch-cell contract (STEP 0108).
 *
 * The writeback body `ARM64_SIM_L_WRITE_REG_WIDTH` and the read bodies
 * `ARM64_SIM_L_READ_REG` / `ARM64_SIM_L_READ_REG_PTR` dispatch on the register
 * number through the hand-written `ARM64_SIM_L_FOR_EACH_GPR` order; the
 * generated `KPROG_ARM64_GPR_CELL(REG)` names the dispatch cell that number
 * binds to. This oracle drives the real simulator state over the full
 * register-number range, observes which of its own 31 GPR cells each write
 * changes, and checks that the changed cell is exactly the cell the generated
 * contract names, against an independent model that maps the number to the
 * literal `x<n>` cell itself. The generated `_Static_assert`s additionally pin
 * the hand-written `ARM64_X<n>` decode to the generated table at compile time.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_reg_dispatch_route_host.c -o /tmp/t_ardr
 *   /tmp/t_ardr
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

/* The independent binding: the dispatch cell index a decoded register number
 * names, or -1 when the number is not a general-purpose register (the zero
 * register `31`, the stack pointer `32`, or the no-register sentinel `0xff`). */
static int model_cell(int reg)
{
	return reg >= 0 && reg < 31 ? reg : -1;
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

/* Seed every GPR scalar from `pattern_reg`, so a write routed to the wrong cell
 * is caught by the changed-cell observation. */
#define ORA_SEED(IDX) ARM64_SIM_L_WRITE_REG_WIDTH(IDX, pattern_reg(IDX), \
						  ARM64_WIDTH_64);

/* Capture all 31 GPR `.x` cells into `ARR` (caller-declared `__u64[31]`). */
#define ORA_SNAPSHOT_X(ARR)                                                 \
	do {                                                                \
		__u64 *__p = (ARR);                                        \
		unsigned __i = 0;                                          \
		ARM64_SIM_L_FOR_EACH_GPR(ORA_CAPTURE_X)                    \
	} while (0)

/* Capture all 31 GPR `.ptr` cells into `ARR` (caller-declared `void *[31]`). */
#define ORA_SNAPSHOT_PTR(ARR)                                               \
	do {                                                                \
		void **__p = (ARR);                                        \
		unsigned __i = 0;                                          \
		ARM64_SIM_L_FOR_EACH_GPR(ORA_CAPTURE_PTR)                  \
	} while (0)

/* Drive `ARM64_SIM_L_WRITE_REG_WIDTH` for one register number and check that the
 * one changed GPR cell is exactly the cell the generated contract names. */
static void check_width(unsigned reg, __u64 value, unsigned width)
{
	__u64 before[31];
	__u64 after[31];
	int want_cell = model_cell((int)reg);
	unsigned gen_cell = KPROG_ARM64_GPR_CELL((__u8)reg);
	__u64 masked = KPROG_ARM64_APPLY_WIDTH((value), (width));
	int changed = -1;
	unsigned j;

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
		(void)__a64_sp;

		ORA_FOR_EACH_IDX(ORA_SEED)
		ORA_SNAPSHOT_X(before);

		ARM64_SIM_L_WRITE_REG_WIDTH(reg, value, width);
		ORA_SNAPSHOT_X(after);

		/* Identify the single changed cell, if the write was routed to a
		 * GPR cell at all (the zero register, the sentinel and SP change
		 * none of the 31 GPR cells). */
		for (j = 0; j < 31U; j++) {
			if (after[j] != before[j]) {
				if (changed >= 0) {
					printf("MISMATCH width reg=%u multiple "
					       "cells changed (%d and %u)\n",
					       reg, changed, j);
					failures++;
				}
				changed = (int)j;
			}
		}

		if (want_cell < 0) {
			if (changed >= 0 && reg != ARM64_SP) {
				printf("MISMATCH width reg=%u non-GPR "
				       "changed cell %s\n",
				       reg, gpr_names[changed]);
				failures++;
			}
		} else if (changed != want_cell) {
			printf("MISMATCH width reg=%u changed cell got=%d "
			       "want=%d\n", reg, changed, want_cell);
			failures++;
		} else {
			if (after[want_cell] != masked) {
				printf("MISMATCH width reg=%u cell=%s "
				       "got=0x%llx want=0x%llx\n", reg,
				       gpr_names[want_cell],
				       (unsigned long long)after[want_cell],
				       (unsigned long long)masked);
				failures++;
			}
			/* The generated dispatch contract names this cell. */
			if ((int)gen_cell != want_cell) {
				printf("MISMATCH width reg=%u generated "
				       "cell=%u sim cell=%d\n", reg,
				       gen_cell, want_cell);
				failures++;
			}
		}
	}
}

/* Drive `ARM64_SIM_L_READ_REG` for one register number and check the value it
 * yields against the seeded cell the independent model names. */
static void check_read(unsigned reg, __s64 sp_value)
{
	int want_cell = model_cell((int)reg);
	__u64 want;
	__u64 got;

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
		__a64_sp = sp_value;

		if (reg == ARM64_SP) {
			want = (__u64)sp_value;
		} else if (want_cell >= 0) {
			want = pattern_reg((unsigned)want_cell);
		} else {
			/* The zero register and the no-register
			 * sentinel read as zero. */
			want = 0;
		}

		got = ARM64_SIM_L_READ_REG(reg);
		if (got != want) {
			printf("MISMATCH read reg=%u got=0x%llx want=0x%llx\n",
			       reg, (unsigned long long)got,
			       (unsigned long long)want);
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

	/* The generated count and the cell selector must line up with the sim's
	 * hand-written decode. */
	cases++;
	if (KPROG_ARM64_GPR_COUNT != 31U ||
	    KPROG_ARM64_GPR_CELL(ARM64_X0) != 0U ||
	    KPROG_ARM64_GPR_CELL(ARM64_X15) != 15U ||
	    KPROG_ARM64_GPR_CELL(ARM64_X30) != 30U) {
		printf("MISMATCH dispatch constant drift\n");
		failures++;
	}

	/* Drive the routed writeback body over the full register-number range,
	 * all four widths and several values, then the routed read body. */
	for (reg = 0; reg <= 0xffU; reg++) {
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
				check_width(reg, values[vi], widths[wi]);
			}
		}
		check_read(reg, (__s64)0x7ffffff00LL);
	}

	if (failures != 0) {
		printf("arm64 reg dispatch route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 reg dispatch route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
