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

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

#define QUIET_GPR_ONE(REG, NAME) \
	(void)sizeof(__a64_##NAME); \
	(void)sizeof(__a64_##NAME##_tag);

#define DECL_STATE() \
	ARM64_SIM_L_DECLARE_STATE(); \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP; \
	(void)__a64_sim_abi_kind; \
	ARM64_SIM_L_DECLARE_STACK(); \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE); \
	(void)__a64_lr

#define SEED_GPR_ONE(REG, NAME) \
	do { \
		__a64_##NAME.ptr = (void *)(long)(0x9e3779b97f4a7c15ULL * ((REG) + 1U)); \
		__a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR; \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

#define SEED_FLAGS() \
	do { \
		__a64_n = 1; \
		__a64_z = 0; \
		__a64_c = 1; \
		__a64_v = 0; \
	} while (0)

/* Architectural multiply value, written here rather than reusing the
 * generated macro (the standalone host oracle already drives that macro; this
 * route oracle drives the simulator arm and restates the meaning itself). */
static __u64 mul_oracle(unsigned op, __u64 a, __u64 b, __u64 c)
{
	switch (op) {
	case ARM64_OP_MADD:
		return c + a * b;
	case ARM64_OP_MSUB:
		return c - a * b;
	case ARM64_OP_MUL:
		return a * b;
	case ARM64_OP_UMULL:
		return (__u64)(__u32)a * (__u64)(__u32)b;
	case ARM64_OP_UDIV:
		return b ? a / b : 0;
	case ARM64_OP_UMULH:
		return (__u64)(((unsigned __int128)a * (unsigned __int128)b)
			       >> 64);
	case ARM64_OP_UMADDL:
		return (__u64)(__u32)a * (__u64)(__u32)b + c;
	case ARM64_OP_SMADDL:
		return (__u64)((__s64)(__s32)a * (__s64)(__s32)b + (__s64)c);
	}
	return 0;
}

/* Drive the real MUL arm of ARM64_SIM_L_EXEC: seed x1/x2/x3 with the three
 * operands, dispatch OP with the destination x0, and observe the value, the
 * writeback width, the destination tag, and the whole modeled flags file.
 * Every scenario pins a fact ISS-only mutation of a sim route line, a
 * generated-family distortion, or the writeback arms can break. */
static void drive(unsigned op, __u64 a, __u64 b, __u64 c, __u8 w,
	__u64 *val, __u8 *tag, __u8 *n, __u8 *z, __u8 *cc, __u8 *v)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, a, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2, b, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, c, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3, w, 0U, 0U);
	*val = __a64_x0.x;
	*tag = __a64_x0_tag;
	*n = __a64_n;
	*z = __a64_z;
	*cc = __a64_c;
	*v = __a64_v;
	cases++;
}

static void expect(unsigned op, __u64 a, __u64 b, __u64 c, __u64 want,
	__u8 tag, __u8 n, __u8 z, __u8 cc, __u8 v)
{
	__u64 got;
	__u8 got_tag, n2, z2, c2, v2;

	drive(op, a, b, c, ARM64_WIDTH_64, &got, &got_tag, &n2, &z2, &c2, &v2);
	if (got != want) {
		printf("MISMATCH op=%u a=0x%llx b=0x%llx c=0x%llx got=0x%llx "
		       "want=0x%llx\n", op, (unsigned long long)a,
		       (unsigned long long)b, (unsigned long long)c,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
	if (got_tag != tag) {
		printf("MISMATCH op=%u tag got=%u want=%u\n", op, got_tag,
		       tag);
		failures++;
	}
	if (n2 != n || z2 != z || c2 != cc || v2 != v) {
		printf("MISMATCH op=%u flags %u%u%u%u/%u%u%u%u\n", op, n2, z2,
		       c2, v2, n, z, cc, v);
		failures++;
	}
	cases++;
}

int main(void)
{
	/* Seed flags 1 0 1 0; every mul arm must keep them (81 fixed seeds x
	 * 8 ops firstly against the oracle). */
	static const unsigned family[] = {
		ARM64_OP_MADD, ARM64_OP_MSUB, ARM64_OP_MUL, ARM64_OP_UMULL,
		ARM64_OP_UDIV, ARM64_OP_UMULH, ARM64_OP_UMADDL,
		ARM64_OP_SMADDL,
	};
	static const __u64 seeds[][3] = {
		{0x0000000000000000ULL, 0x0000000000000000ULL,
		 0x0000000000000000ULL},
		{0x0000000000000003ULL, 0x0000000000000002ULL,
		 0x0000000000000001ULL},
		{0x00000000deadbeefULL, 0x00000000cafebabeULL,
		 0x00000000000000ffULL},
		{0x7fffffffffffffffULL, 0x7fffffffffffffffULL,
		 0x0000000000000000ULL},
		{0x8000000000000000ULL, 0x0000000000000002ULL,
		 0x0000000000000001ULL},
		{0xffffffffffffffffULL, 0x00000000000000ffULL,
		 0xffffffffffffffffULL},
		{0x00000000ffffffffULL, 0x00000000ffffffffULL,
		 0x00000000ffffffffULL},
		{0xffffffff00000000ULL, 0x00000000ffffffffULL,
		 0x0000000000000000ULL},
		{0x123456789abcdef0ULL, 0x0fedcba987654321ULL,
		 0x0055000000aa0000ULL},
	};

	for (unsigned i = 0; i < sizeof(seeds) / sizeof(seeds[0]); i++)
		for (unsigned k = 0; k < sizeof(family) / sizeof(family[0]);
		     k++) {
			__u64 want = mul_oracle(family[k], seeds[i][0],
					seeds[i][1], seeds[i][2]);

			expect(family[k], seeds[i][0], seeds[i][1],
			       seeds[i][2], want, ARM64_SIM_TAG_SCALAR, 1, 0, 1,
			       0);
		}

	/* Divide-by-zero result of zero through the routed arm. */
	expect(ARM64_OP_UDIV, 0xdeadbeefcafebabeULL, 0U, 7U, 0U,
	       ARM64_SIM_TAG_SCALAR, 1, 0, 1, 0);

	/* Unsupported opcode reaches the unsupported hook, not a silent
	 * zero. */
	{
		__u64 val;
		__u8 tag, n, z, c, v;
		unsigned long before = unsupported_calls;

		drive(70U, 1U, 2U, 3U, ARM64_WIDTH_64, &val, &tag, &n, &z, &c,
		      &v);
		if (unsupported_calls == before) {
			printf("MISMATCH unsupported call missing\n");
			failures++;
		}
		cases++;
	}

	/* Width writeback: at the 32-bit code the routed MUL value is
	 * truncated to 32 bits and the write arms stay in sync with the
	 * contract's APPLY_WIDTH; the seeded x0 cell shows the narrowing. */
	{
		__u64 v64;
		__u8 tag, n, z, c, vq;

		drive(ARM64_OP_MUL, 0x9e3779b97f4a7c15ULL, 0x1234ULL, 0U,
		      ARM64_WIDTH_32, &v64, &tag, &n, &z, &c, &vq);
		if (v64 != (0x7f4a7c15ULL * 0x1234ULL & 0xffffffffULL)) {
			printf("MISMATCH mul w32 got=0x%llx want=0x%llx\n",
			       (unsigned long long)v64,
			       (unsigned long long)(0x7f4a7c15ULL *
						    0x1234ULL &
						    0xffffffffULL));
			failures++;
		}
		if (tag != ARM64_SIM_TAG_SCALAR) {
			printf("MISMATCH mul w32 tag\n");
			failures++;
		}
		cases++;
	}

	if (failures) {
		printf("arm64 mul route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 mul route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
