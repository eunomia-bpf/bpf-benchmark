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
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE)

#define SEED_GPR_ONE(REG, NAME) \
	do { \
		__a64_##NAME.ptr = (void *)(long)(0x9e3779b97f4a7c15ULL * ((REG) + 1U)); \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

#define SEED_FLAGS() \
	do { \
		__a64_n = 0; \
		__a64_z = 0; \
		__a64_c = 0; \
		__a64_v = 0; \
	} while (0)

static void drive(__u32 cond, __u32 nzcv, __u64 lhs, __u64 rhs, __u8 w,
	__u8 *n, __u8 *z, __u8 *c, __u8 *v)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2, lhs, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, rhs, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_CCMP_IMM, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
		ARM64_REG_NONE, w, ARM64_AUX_CCMP(cond, nzcv), rhs);
	*n = __a64_n;
	*z = __a64_z;
	*c = __a64_c;
	*v = __a64_v;
	cases++;
}

int main(void)
{
	__u8 n, z, c, v;

	/* Untaken: COND_EQ(0) against seeded z=0 -> fallback nzcv byte 0x3
	 * lands as n=0, z=0, c=1, v=1. A cond/nzcv lane or alias swap changes
	 * the byte that lands; a dropped routing read changes it too. */
	drive(0U, 0x3U, 0x55U, 0x77U, ARM64_WIDTH_64, &n, &z, &c, &v);
	if (n != 0 || z != 0 || c != 1 || v != 1) failures++;
	/* Taken: COND_AL, sub flags of (0x55, 0x77): n=1, z=0, c=0, v=0. */
	drive(14U, 0x5U, 0x55U, 0x77U, ARM64_WIDTH_64, &n, &z, &c, &v);
	if (!(n == 1 && z == 0 && c == 0 && v == 0)) failures++;
	/* Taken: COND_NE(1) with seeded z=0, equal operands ->
	 * n=0, z=1, c=1, v=0. */
	drive(1U, 0x9U, 0x55U, 0x55U, ARM64_WIDTH_64, &n, &z, &c, &v);
	if (!(n == 0 && z == 1 && c == 1 && v == 0)) failures++;

	if (failures) {
		printf("arm64 CCMP route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 CCMP route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
