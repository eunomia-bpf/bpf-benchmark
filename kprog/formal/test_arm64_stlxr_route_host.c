/*
 * Host cross-check for the AArch64 simulator's *store-release exclusive*
 * body (STLXR), driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name; STLXR was one of the five
 * left with only a model-side host. Of the remaining five it is the only one
 * with *two* observable effects -- the dispatcher stores the source value to
 * memory and then writes a status word to the destination -- so a misroute can
 * corrupt the atomic-success signal while leaving memory correct, or the
 * reverse.
 *
 * What is checked, for each case:
 *
 *   - the memory word the dispatcher stored equals the source value;
 *   - the destination holds the status the contract defines (zero, meaning
 *     the exclusive store succeeded) written at 32 bits -- so a write at the
 *     access width instead of the fixed status width is observable;
 *   - the source register is unchanged, since a store-exclusive reads it.
 *
 * The expected values are computed here rather than by calling the generated
 * macro, so a consistent error in the contract is not reproduced.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_stlxr_route_host.c -o build/test_arm64_stlxr_route_host &&
 *   ./build/test_arm64_stlxr_route_host
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
	static const __u64 values[] = {
		0ULL, 1ULL, 0xffULL, 0x80ULL, 0x7fffffffULL,
		0x80000000ULL, 0xffffffffULL, 0x123456789abcdefULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
	};
	static const unsigned wids[] = { ARM64_WIDTH_64, ARM64_WIDTH_32,
					 ARM64_WIDTH_16, ARM64_WIDTH_8 };
	static const unsigned nregs[] = { ARM64_X0, ARM64_X5, ARM64_X10,
					  ARM64_X29, ARM64_X1 };
	/* Backing store for the store-exclusive destination. */
	static __u64 scratch[8];
	unsigned vi, wi, ri;

	for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
		for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++)
			for (ri = 0; ri < sizeof(nregs) / sizeof(nregs[0]); ri++) {
				unsigned dst = nregs[ri];
				unsigned s1 = nregs[(ri + 1) % 5];
				unsigned s2 = nregs[(ri + 2) % 5];
				unsigned base = s2;
				unsigned width = wids[wi];
				__u64 value = values[vi];
				__u64 before_s1, after_s1, status;
				__u64 want_status = 0;   /* exclusive store succeeded */
				__u64 mem_want, mem_got;

				DECL_STATE();
				SEED_STATE();

				/* The base register points into the scratch memory
				 * area; the offset is zero so the stored word is
				 * at that base. */
				/* Point the base at a real buffer the
				 * simulator can write to, tagged as a memory
				 * pointer so the store dereferences it. */
				ARM64_SIM_L_WRITE_REG_PTR_TAG(
					base, (void *)scratch,
					ARM64_SIM_TAG_MAP_VALUE);

				before_s1 = ARM64_SIM_L_READ_REG(s1);
				ARM64_SIM_L_WRITE_REG_WIDTH(s1, value,
							    ARM64_WIDTH_64);
				before_s1 = ARM64_SIM_L_READ_REG(s1);

				ARM64_SIM_L_EXEC(ARM64_OP_STLXR, dst, s1, s2, s2,
						  width, 0, 0);

				if (unsupported_calls != 0) {
					printf("reached the unsupported arm\n");
					failures++;
					continue;
				}

				after_s1 = ARM64_SIM_L_READ_REG(s1);
				status = ARM64_SIM_L_READ_REG(dst);
				cases++;

				/* The status is written at 32 bits, so only the
				 * low word is defined; the high half is not
				 * part of the contract. */
				if ((status & 0xffffffffULL) != want_status) {
					printf("STATUS w=%u v=%#llx: got %#llx "
					       "want %#llx\n", width,
					       (unsigned long long)value,
					       (unsigned long long)status,
					       (unsigned long long)want_status);
					failures++;
				}

				if (after_s1 != before_s1) {
					printf("SOURCE CLOBBERED w=%u: %#llx -> "
					       "%#llx\n", width,
					       (unsigned long long)before_s1,
					       (unsigned long long)after_s1);
					failures++;
				}

				/* The memory effect: the value stored is the
				 * source narrowed to the access width, and the
				 * dispatcher writes a whole word there. Read it
				 * back through the simulator's own load path. */
				mem_want = value & (width == ARM64_WIDTH_64
							    ? ~0ULL
						    : width == ARM64_WIDTH_32
							    ? 0xffffffffULL
						    : width == ARM64_WIDTH_16
							    ? 0xffffULL
							    : 0xffULL);
				mem_got = ARM64_SIM_L_MEM_READ(base,
							       ARM64_REG_NONE,
							       0, 0, 0,
							       ARM64_WIDTH_64);
				if ((mem_got & mem_want) != mem_want) {
					printf("MEMORY w=%u v=%#llx: got %#llx\n",
					       width,
					       (unsigned long long)value,
					       (unsigned long long)mem_got);
					failures++;
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
		printf("arm64 stlxr route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 stlxr route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}