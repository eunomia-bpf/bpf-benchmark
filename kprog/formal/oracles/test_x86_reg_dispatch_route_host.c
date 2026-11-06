/*
 * Host cross-check for the x86-64 simulator's routing of the decoded register
 * number through the generated dispatch-cell contract (STEP 0112).
 *
 * The writeback body `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` (and the tag/pointer
 * dispatch macros) dispatch on the register number through the hand-written
 * `X86_SIM_L_FOR_EACH_GPR` order, and the read body `X86_SIM_L_READ_REG`
 * resolves the register through the independent hand-written
 * `X86_SIM_L_REG_VALUE` ternary chain; the generated `KPROG_X86_GPR_CELL(REG)`
 * names the dispatch cell that number binds to. This oracle drives the real
 * simulator state over the full register-number range, observes which of its
 * own 16 GPR cells each write changes (via the cell tag, so a same-byte write
 * is still observed), and checks that the changed cell is exactly the cell the
 * generated contract names, against an independent model that maps the number
 * to the literal `r<n>` cell itself. It also checks the routed read body,
 * which resolves through the *second* hand-written order. The generated
 * `_Static_assert`s additionally pin the hand-written `X86_R<n>` decode to the
 * generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_reg_dispatch_route_host.c -o /tmp/t_xrdr
 *   /tmp/t_xrdr
 */

#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent binding: the dispatch cell index a decoded register number
 * names, or -1 when the number is not a general-purpose register (every byte
 * `16..255`, including the no-register sentinel `0xff`). */
static int model_cell(int reg)
{
	return reg >= 0 && reg < 16 ? reg : -1;
}

/* A deterministic per-register pattern, with high bits set so a 64-bit write
 * and a 32-bit write are distinguishable, and never zero so a partial write is
 * detectable against the tag byte as well. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag planted in every cell before a write, so a write routed to a
 * cell flips that cell's tag to the scalar tag and the target is observable
 * even when a partial write leaves the pointer bytes unchanged. */
#define ORA_MARK_TAG 0x7fU

static const char *gpr_names[16] = {
	"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
	"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
};

/* Capture every GPR pointer cell and tag cell; the `X86_SIM_L_FOR_EACH_GPR`
 * order is register numbers 0..15, so cell index == register number. */
#define ORA_CAPTURE(REG, NAME)                                             \
	do {                                                               \
		__p[__i] = __x86_##NAME.ptr;                               \
		__t[__i] = __x86_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define ORA_SNAPSHOT(P, T)                                                 \
	do {                                                               \
		void **__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_CAPTURE)                        \
	} while (0)

/* Seed every GPR cell from `pattern_reg` and mark its tag, so a write routed to
 * the wrong cell is caught by the changed-cell observation. */
#define ORA_SEED(REG, NAME)                                                \
	do {                                                               \
		__x86_##NAME.ptr = (void *)(__u64)pattern_reg(__i);        \
		__x86_##NAME##_tag = ORA_MARK_TAG;                         \
		__i++;                                                     \
	} while (0);

#define ORA_SEED_ALL()                                                     \
	do {                                                               \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_SEED)                           \
	} while (0)

/* Drive `X86_SIM_L_WRITE_REG_WIDTH` for one register number and check that the
 * one changed GPR cell is exactly the cell the generated contract names. */
static void check_width(unsigned reg, __u64 value, unsigned width)
{
	void *before[16], *after[16];
	__u8 btag[16], atag[16];
	int want_cell = model_cell((int)reg);
	unsigned gen_cell = KPROG_X86_GPR_CELL((__u8)reg);
	int changed = -1;
	unsigned j;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();
		ORA_SNAPSHOT(before, btag);

		X86_SIM_L_WRITE_REG_WIDTH(reg, value, width);
		ORA_SNAPSHOT(after, atag);

		/* Identify the single changed cell, if the write was routed to a
		 * GPR cell at all (a non-GPR number changes none of the 16). */
		for (j = 0; j < 16U; j++) {
			if (atag[j] != btag[j] || after[j] != before[j]) {
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
			if (changed >= 0) {
				printf("MISMATCH width reg=%u non-GPR changed "
				       "cell %s\n", reg, gpr_names[changed]);
				failures++;
			}
		} else if (changed != want_cell) {
			printf("MISMATCH width reg=%u changed cell got=%d "
			       "want=%d\n", reg, changed, want_cell);
			failures++;
		} else if ((int)gen_cell != want_cell) {
			printf("MISMATCH width reg=%u generated cell=%u sim "
			       "cell=%d\n", reg, gen_cell, want_cell);
			failures++;
		}
	}
}

/* Drive `X86_SIM_L_READ_REG` for one register number and check the value it
 * yields against the seeded cell the independent model names. The read path
 * resolves the register through the *second* hand-written order, so this pins
 * that order too. */
static void check_read(unsigned reg)
{
	int want_cell = model_cell((int)reg);
	__u64 want;
	__u64 got;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();

		/* A non-GPR number reads as the null pointer cast to a
		 * scalar; a GPR reads the seeded pattern. */
		want = want_cell >= 0 ? pattern_reg((unsigned)want_cell) : 0ULL;

		got = X86_SIM_L_READ_REG(reg);
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
		X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	__u32 reg;
	size_t vi, wi;

	/* The generated count and the cell selector must line up with the
	 * sim's hand-written decode. */
	cases++;
	if (KPROG_X86_GPR_COUNT != 16U ||
	    KPROG_X86_GPR_CELL(X86_RAX) != 0U ||
	    KPROG_X86_GPR_CELL(X86_RSP) != 4U ||
	    KPROG_X86_GPR_CELL(X86_R8) != 8U ||
	    KPROG_X86_GPR_CELL(X86_R15) != 15U) {
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
		check_read(reg);
	}

	if (failures != 0) {
		printf("x86 reg dispatch route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 reg dispatch route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
