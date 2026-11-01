/*
 * Host cross-check for the AArch64 simulator's *address-generation* body
 * (ADRP with a GOT or RODATA relocation), driven through the real dispatcher
 * `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name; ADRP was one of the three
 * left with only a model-side host. It is the most forgiving-looking and least
 * forgiving of them: the arm writes the immediate as a pointer, so the *value*
 * is simply copied, and the only thing the opcode decides is which kind of
 * pointer it is. A dispatcher that swapped the two arms would leave the
 * address byte-identical and label it as a different pointer class -- a fault
 * that no value comparison can see, and one that changes later behaviour
 * rather than this instruction's result.
 *
 * What is checked, for both relocation opcodes:
 *
 *   - the destination's address bits equal the immediate exactly (no
 *     arithmetic is expected here, unlike the ALU families);
 *   - the destination's *tag* is the one the opcode names, and the two
 *     opcodes select different tags -- so swapping the arms is visible;
 *   - a non-member opcode reaches the unsupported arm.
 *
 * The expected tags are written here from the simulator's tag vocabulary
 * rather than read back out of the contract, so a changed mapping shows up.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_adrp_route_host.c -o build/test_arm64_adrp_route_host &&
 *   ./build/test_arm64_adrp_route_host
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

int main(void)
{
	static const __u64 imms[] = {
		0ULL, 0x1000ULL, 0xfffff000ULL, 0x7fffffffffffULL,
		0xffffffffffffffffULL, 0x123456789abcdefULL,
	};
	static const unsigned nregs[] = { ARM64_X0, ARM64_X5, ARM64_X10,
					  ARM64_X29, ARM64_X1 };
	unsigned ii, ri;

	for (ii = 0; ii < sizeof(imms) / sizeof(imms[0]); ii++)
		for (ri = 0; ri < sizeof(nregs) / sizeof(nregs[0]); ri++) {
			unsigned dst = nregs[ri];
			__u64 imm = imms[ii];
			unsigned oi;

			for (oi = 0; oi < 2U; oi++) {
				unsigned op = oi == 0 ? ARM64_OP_ADRP_GOT
						      : ARM64_OP_ADRP_RODATA;
				/* Written from the tag vocabulary, not read
				 * back from the contract. */
				__u8 want_tag = oi == 0 ? 7U : 8U;
				__u64 got_addr;
				__u8 got_tag;

				DECL_STATE();
				SEED_STATE();

				ARM64_SIM_L_EXEC(op, dst, dst, dst, dst,
						  ARM64_WIDTH_64, 0, imm);

				if (unsupported_calls != 0) {
					printf("op %#x reached the unsupported "
					       "arm\n", op);
					failures++;
					continue;
				}

				got_addr = (__u64)(long)ARM64_SIM_L_READ_REG_PTR(dst);
				got_tag = ARM64_SIM_L_REG_TAG(dst);
				cases++;

				if (got_addr != imm) {
					printf("ADDRESS op=%#x imm=%#llx: got "
					       "%#llx\n", op,
					       (unsigned long long)imm,
					       (unsigned long long)got_addr);
					failures++;
				}
				if (got_tag != want_tag) {
					printf("TAG op=%#x imm=%#llx: got %u "
					       "want %u\n", op,
					       (unsigned long long)imm,
					       got_tag, want_tag);
					failures++;
				}
			}
		}

	/* The two arms must select different tags, or the check above could
	 * pass with both arms identical. */
	{
		DECL_STATE();
		SEED_STATE();
		ARM64_SIM_L_EXEC(ARM64_OP_ADRP_GOT, ARM64_X0, ARM64_X0,
				  ARM64_X0, ARM64_X0, ARM64_WIDTH_64, 0,
				  0x1000ULL);
		{
			__u8 tag_got = ARM64_SIM_L_REG_TAG(ARM64_X0);

			ARM64_SIM_L_EXEC(ARM64_OP_ADRP_RODATA, ARM64_X1,
					  ARM64_X1, ARM64_X1, ARM64_X1,
					  ARM64_WIDTH_64, 0, 0x1000ULL);
			cases++;
			if (tag_got == ARM64_SIM_L_REG_TAG(ARM64_X1)) {
				printf("both ADRP arms select tag %u, so a swap "
				       "is invisible\n", tag_got);
				failures++;
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
		printf("arm64 adrp route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 adrp route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}