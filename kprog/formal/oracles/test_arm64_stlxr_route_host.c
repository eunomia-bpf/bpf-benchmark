/* Exercise the real exclusive-store handler for both explicit outcomes.
 * Failure must preserve every byte, success writes exactly its width, status
 * is zero-extended at 32 bits and the source register remains unchanged.
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
#include <stdlib.h>
#include <string.h>

static unsigned failure;
unsigned long native_lab_exclusive_failure_choice(unsigned int site)
{
	if (site != 0) abort();
	return failure;
}

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

	for (failure = 0; failure < 2; failure++)
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
				__u64 want_status = failure;
				unsigned char expected[sizeof(scratch)];

				DECL_STATE();
				SEED_STATE();
				memset(scratch, 0xa5, sizeof(scratch));
				memcpy(expected, scratch, sizeof(scratch));
				if (!failure)
					for (unsigned byte = 0; byte < width; byte++)
						expected[byte] = (unsigned char)(value >> (byte * 8));

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

				/* A W-register status write clears the high half. */
				if (status != want_status) {
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

				if (memcmp(scratch, expected, sizeof(scratch)) != 0) {
					printf("MEMORY w=%u failure=%u value=%#llx\n",
					       width, failure, (unsigned long long)value);
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
