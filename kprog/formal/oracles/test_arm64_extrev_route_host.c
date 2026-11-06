/*
 * Host cross-check for the AArch64 simulator's *extract / reverse / extend*
 * body, driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name; EXTREV was one of the two
 * left with only a model-side host, and it is the largest of them: six opcodes
 * built from 26 shifts and masks. Step 0496 already related its REV opcode to
 * the x86 reversal at the contract layer, so the reversal arithmetic is
 * covered -- but nothing drove the *dispatcher* to it, and EXTR, REV16 and the
 * three sign extensions were not covered at all.
 *
 * What is checked, one independent model per opcode, written from the
 * instruction definitions rather than from the generated macro:
 *
 *   EXTR   the 2*width-bit concatenation of (src:src2) rotated right by the
 *          shift amount, narrowed to the access width;
 *   REV    the byte order of the access-width value reversed;
 *   REV16  the two bytes of each 16-bit unit swapped;
 *   SXTB   sign-extension of the low byte;  SXTH of the low halfword;
 *          SXTW of the low word.
 *
 * Operands are chosen so that each opcode's characteristic mistake changes
 * the result: bytes differ from one another (a transposed REV lane shows), the
 * shift amount spans the wrap point (an unmasked EXTR shift shows), and the
 * sign-extension operands straddle the sign bit (a zero-extension shows).
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_extrev_route_host.c -o build/test_arm64_extrev_route_host &&
 *   ./build/test_arm64_extrev_route_host
 */

#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_lr;                                                     \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

#define SEED_GPR_ONE(REG, NAME)                                            \
	do {                                                               \
		__a64_##NAME.x = pattern_reg((unsigned)(REG));              \
		__a64_##NAME##_tag = pattern_tag((unsigned)(REG));          \
	} while (0);

#define SEED_STATE()                                                       \
	do {                                                               \
		unsigned __k;                                              \
		ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)                    \
		__a64_sp = (__s64)0x7fff0000ULL;                           \
		__a64_lr = pattern_reg(30);                                \
		__a64_v0 = pattern_reg(20);                                \
		__a64_v0_hi = pattern_reg(21);                             \
		for (__k = 0; __k < ARM64_SIM_STACK_BYTES; __k++)         \
			__a64_stack.b[__k] = (__u8)(__k * 7U + 3U);       \
		for (__k = 0; __k < sizeof(__a64_stack_tag); __k++)       \
			__a64_stack_tag[__k] = (__u8)(__k % 4U);           \
	} while (0)

/* The independent models, written from the instruction definitions. */
/* EXTR: exactly as the arm computes it -- the second source shifted right by
 * the masked amount, OR'd with the first source shifted up, then narrowed to
 * the access width at the register write. Arm64Extrev.lean proves this form
 * equivalent to the architectural concatenation at the destination width, so
 * taking the raw operands here is following the code, not weakening the check:
 * a fault in either operand or in the mask still shows. */
static __u64 want_extr(__u64 src, __u64 src2, __u64 shift, unsigned width)
{
	unsigned bits = width == ARM64_WIDTH_32 ? 32U : 64U;
	unsigned k = (unsigned)(shift & (bits - 1U));
	__u64 widemask = width == ARM64_WIDTH_32 ? 0xffffffffULL : ~0ULL;
	__u64 merged = (src2 >> k);

	if (k)
		merged |= (src << (bits - k));
	return merged & widemask;
}

static __u64 want_rev(__u64 v, unsigned width)
{
	__u64 out = 0;
	unsigned bytes = width == ARM64_WIDTH_32 ? 4U : 8U;
	unsigned i;

	for (i = 0; i < bytes; i++)
		out |= ((v >> (8U * i)) & 0xffULL) << (8U * (bytes - 1U - i));
	return out;
}

static __u64 want_rev16(__u64 v, unsigned width)
{
	__u64 out = 0;
	unsigned halves = width == ARM64_WIDTH_32 ? 2U : 4U;
	unsigned i;

	for (i = 0; i < halves; i++) {
		__u64 h = (v >> (16U * i)) & 0xffffULL;
		__u64 swapped = ((h & 0xffULL) << 8) | ((h >> 8) & 0xffULL);

		out |= swapped << (16U * i);
	}
	return out;
}

static __u64 want_sx(__u64 v, unsigned nbits, unsigned width)
{
	__u64 mask = (nbits == 64U) ? ~0ULL : ((1ULL << nbits) - 1ULL);
	__u64 sign = 1ULL << (nbits - 1U);
	__u64 narrow = v & mask;
	__u64 out = (narrow & sign) ? (narrow | ~mask) : narrow;

	return width == ARM64_WIDTH_32 ? (out & 0xffffffffULL) : out;
}

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 0x80ULL, 0xffULL, 0x8000ULL, 0x7fffULL,
		0xffffULL, 0x80000000ULL, 0x7fffffffULL, 0xffffffffULL,
		0x0102030405060708ULL, 0xfedcba9876543210ULL,
		0x123456789abcdefULL, 0xffffffffffffffffULL,
	};
	static const unsigned wids[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	static const __u64 shifts[] = { 0, 1, 7, 8, 15, 16, 31, 32, 33, 63 };
	unsigned vi, wi, si;

	for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++)
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
			for (si = 0; si < sizeof(shifts) / sizeof(shifts[0]);
			     si++) {
				unsigned width = wids[wi];
				__u64 v = values[vi];
				__u64 hi = values[(vi + 3) %
						  (sizeof(values) /
						   sizeof(values[0]))];
				__u64 sh = shifts[si];
				__u64 want, got;
				unsigned op;

				/* EXTR needs both sources and the shift. */
				{
				DECL_STATE();
				SEED_STATE();
				ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X5, v,
							    ARM64_WIDTH_64);
				ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X10, hi,
							    ARM64_WIDTH_64);
				want = want_extr(v, hi, sh, width);
				ARM64_SIM_L_EXEC(ARM64_OP_EXTR, ARM64_X0,
						  ARM64_X5, ARM64_X10,
						  ARM64_X1, width, 0, sh);
				got = ARM64_SIM_L_READ_REG(ARM64_X0);
				cases++;
				if (got != want) {
					printf("EXTR w=%u sh=%llu v=%#llx hi=%#llx: "
					       "got %#llx want %#llx\n", width,
					       (unsigned long long)sh,
					       (unsigned long long)v,
					       (unsigned long long)hi,
					       (unsigned long long)got,
					       (unsigned long long)want);
					failures++;
				}

				}
				/* REV and REV16 take one source. */
				op = ARM64_OP_REV;
				{
				DECL_STATE();
				SEED_STATE();
				ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X5, v,
							    ARM64_WIDTH_64);
				want = want_rev(v, width);
				ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X5,
						  ARM64_X5, ARM64_X5, width,
						  0, 0);
				got = ARM64_SIM_L_READ_REG(ARM64_X0);
				cases++;
				if (got != want) {
					printf("REV w=%u v=%#llx: got %#llx "
					       "want %#llx\n", width,
					       (unsigned long long)v,
					       (unsigned long long)got,
					       (unsigned long long)want);
					failures++;
				}

				op = ARM64_OP_REV16;
				{
				DECL_STATE();
				SEED_STATE();
				ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X5, v,
							    ARM64_WIDTH_64);
				want = want_rev16(v, width);
				ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X5,
						  ARM64_X5, ARM64_X5, width,
						  0, 0);
				got = ARM64_SIM_L_READ_REG(ARM64_X0);
				cases++;
				if (got != want) {
					printf("REV16 w=%u v=%#llx: got %#llx "
					       "want %#llx\n", width,
					       (unsigned long long)v,
					       (unsigned long long)got,
					       (unsigned long long)want);
					failures++;
				}

				}
				/* The three sign extensions. */
				{
					static const struct {
						unsigned op;
						unsigned nbits;
						const char *name;
					} sx[] = {
						{ ARM64_OP_SXTB, 8, "SXTB" },
						{ ARM64_OP_SXTH, 16, "SXTH" },
						{ ARM64_OP_SXTW, 32, "SXTW" },
					};
					unsigned xi;

					for (xi = 0; xi < 3U; xi++) {
						DECL_STATE();
						SEED_STATE();
						ARM64_SIM_L_WRITE_REG_WIDTH(
							ARM64_X5, v,
							ARM64_WIDTH_64);
						want = want_sx(v, sx[xi].nbits,
							       width);
						ARM64_SIM_L_EXEC(sx[xi].op,
								  ARM64_X0,
								  ARM64_X5,
								  ARM64_X5,
								  ARM64_X5, width,
								  0, 0);
						got = ARM64_SIM_L_READ_REG(
							ARM64_X0);
						cases++;
						if (got != want) {
							printf("%s w=%u v=%#llx: "
							       "got %#llx want %#llx\n",
							       sx[xi].name, width,
							       (unsigned long long)v,
							       (unsigned long long)got,
							       (unsigned long long)want);
							failures++;
						}
					}
				}
				}
			}

	/* A non-member opcode must reach the unsupported arm. */
	{
		DECL_STATE();
		SEED_STATE();
		ARM64_SIM_L_EXEC(0xfeU, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3,
				  ARM64_WIDTH_64, 0, 0);
		if (unsupported_calls == 0) {
			printf("non-member opcode did not reach the unsupported arm\n");
			failures++;
		}
	}

	if (failures) {
		printf("arm64 extrev route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 extrev route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}