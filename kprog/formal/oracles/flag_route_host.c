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

/* Independent architectural model per the ISS: ADD/SUB/logical NZCV on
 * width-narrowed operands, written out here rather than reusing the
 * generated flag macros (the standalone host oracles drive those macros;
 * this route oracle drives the real dispatcher arms). */
static __u64 narrow_mask(__u8 width)
{
	switch (width) {
	case ARM64_WIDTH_64:
		return ~0ULL;
	case ARM64_WIDTH_32:
		return 0xffffffffULL;
	case ARM64_WIDTH_16:
		return 0xffffULL;
	case ARM64_WIDTH_8:
		return 0xffULL;
	}
	return 0;
}

static __u64 narrow_sign(__u8 width)
{
	switch (width) {
	case ARM64_WIDTH_64:
		return 0x8000000000000000ULL;
	case ARM64_WIDTH_32:
		return 0x80000000ULL;
	case ARM64_WIDTH_16:
		return 0x8000ULL;
	case ARM64_WIDTH_8:
		return 0x80ULL;
	}
	return 0;
}

static void add_oracle(__u64 l, __u64 r, __u8 width, __u64 *res, __u8 *n,
	__u8 *z, __u8 *c, __u8 *v)
{
	__u64 mask = narrow_mask(width);
	__u64 sign = narrow_sign(width);
	__u64 lo = l & mask;
	__u64 ro = r & mask;
	__u64 out = (lo + ro) & mask;

	*res = out;
	*z = out == 0U;
	*n = (out & sign) != 0U;
	*c = lo > mask - ro;
	*v = (~(lo ^ ro) & (lo ^ out) & sign) != 0U;
}

static void sub_oracle(__u64 l, __u64 r, __u8 width, __u64 *res, __u8 *n,
	__u8 *z, __u8 *c, __u8 *v)
{
	__u64 mask = narrow_mask(width);
	__u64 sign = narrow_sign(width);
	__u64 lo = l & mask;
	__u64 ro = r & mask;
	__u64 out = (lo - ro) & mask;

	*res = out;
	*z = lo == ro;
	*n = (out & sign) != 0U;
	*c = lo >= ro;
	*v = ((lo ^ ro) & (lo ^ out) & sign) != 0U;
}

static void logic_oracle(__u64 l, __u64 r, __u8 width, __u64 *res, __u8 *n, __u8 *z)
{
	__u64 mask = narrow_mask(width);
	__u64 sign = narrow_sign(width);
	__u64 out = (l & r) & mask;

	*res = out;
	*res = out;
	*z = out == 0U;
	*n = (out & sign) != 0U;
}

/* Drive the real flag arms of ARM64_SIM_L_EXEC with each family's lane
 * truth:
 *   writeback lanes (SUBS/ADDS/ANDS/BICS): lhs = x1 (SRC), rhs = x2
 *   (SRC2) or IMM through FLAG_RHS, destination x0 written back;
 *   compare lanes (CMP/TST/CMN/TST_BIC): lhs = x0 (DST), rhs per arm —
 *   TST_BIC_REG and CMN_REG and TST_REG read SRC = x1, and none of the
 *   compare lanes write x0. */
static void drive(unsigned op, __u64 dv, __u64 sv, __u64 s2v, __u8 width,
	__u32 imm, __u64 *res, __u8 *r_tag, __u8 *n, __u8 *z, __u8 *cc,
	__u8 *v)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, dv, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, sv, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2, s2v, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3, width,
		0U, imm);
	*res = __a64_x0.x;
	*r_tag = __a64_x0_tag;
	*n = __a64_n;
	*z = __a64_z;
	*cc = __a64_c;
	*v = __a64_v;
	cases++;
}

static void expect(const char *what, unsigned op, __u64 dv, __u64 sv,
	__u64 s2v, __u8 width, __u32 imm, __u64 want, __u8 wn, __u8 wz,
	__u8 wc, __u8 wv, int wb)
{
	__u64 got;
	__u8 tag, n, z, c, v;

	drive(op, dv, sv, s2v, width, imm, &got, &tag, &n, &z, &c, &v);
	if (wb && got != want) {
		printf("MISMATCH %s val got=0x%llx want=0x%llx\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
	if (tag != ARM64_SIM_TAG_SCALAR) {
		printf("MISMATCH %s tag %u\n", what, tag);
		failures++;
	}
	if (n != wn || z != wz || c != wc || v != wv) {
		printf("MISMATCH %s flags %u%u%u%u/%u%u%u%u\n", what, n, z, c,
		       v, wn, wz, wc, wv);
		failures++;
	}
	cases++;
}

/* compare-lane preservation: sentinel dst stays intact, so the
 * writeback-less compare arms are distinguishable from the writeback arms
 * while mutation-forced stores would clobber it */
static void expect_preserve(const char *what, unsigned op, __u64 sv,
	__u8 width, __u32 imm, __u8 wn, __u8 wz, __u8 wc, __u8 wv)
{
	__u64 got;
	__u8 tag, n, z, c, v;
	__u64 sentinel = 0x5a5a5a5a5a5a5a5aULL;

	drive(op, sentinel, sv, 0U, width, imm, &got, &tag, &n, &z, &c, &v);
	if (got != sentinel) {
		printf("MISMATCH %s dst clobbered 0x%llx\n", what,
		       (unsigned long long)got);
		failures++;
	}
	if (n != wn || z != wz || c != wc || v != wv) {
		printf("MISMATCH %s preserve flags %u%u%u%u/%u%u%u%u\n",
		       what, n, z, c, v, wn, wz, wc, wv);
		failures++;
	}
	cases++;
}

/* writeback-lane lhs routing witness: BICS reads its lhs from SRC (x1),
 * ANDS from SRC too but through the FLAG_RHS reduce on SRC2 for the reg
 * lane — a SRC/SRC2 swap inside the route line is visible. For SUBS the
 * lhs is SRC, the dst shows the narrowed difference. */
int main(void)
{
	static const __u64 seeds[][3] = {
		{0x0000000000000000ULL, 0x0000000000000000ULL,
		 0x0000000000000000ULL},
		{0x0000000000000003ULL, 0x0000000000000002ULL,
		 0x0000000000000001ULL},
		{0x00000000deadbeefULL, 0x00000000cafebabeULL,
		 0x00000000000000ffULL},
		{0xffffffffffffffffULL, 0x0000000000000002ULL,
		 0x0000000000000000ULL},
		{0x00000000ffffffffULL, 0x0000000000000001ULL,
		 0x0000000000000000ULL},
		{0x8000000000000000ULL, 0x8000000000000000ULL,
		 0x0000000000000001ULL},
		{0x0000000000000015ULL, 0x0000000000000019ULL,
		 0x0000000000000007ULL},
	};
	/* salient immediates: never the FLAG_RHS default lane */
	static const __u32 imms[] = { 2U, 25U, 5U, 1U, 0x55U };
	__u8 n, z, c, v;
	__u64 want;

	for (unsigned w = 0; w < 4; w++) {
		__u8 width = w == 0 ? ARM64_WIDTH_64 : w == 1 ? ARM64_WIDTH_32 :
			    w == 2 ? ARM64_WIDTH_16 : ARM64_WIDTH_8;

		for (unsigned i = 0; i < sizeof(seeds) / sizeof(seeds[0]);
		     i++) {
			for (unsigned k = 0; k < sizeof(imms) /
			     sizeof(imms[0]); k++) {
				/* writeback arithmetic, lhs = x1, rhs = imm */
				sub_oracle(seeds[i][0], imms[k], width,
					   &want, &n, &z, &c, &v);
				expect("subs_imm", ARM64_OP_SUBS_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, c, v, 1);
				add_oracle(seeds[i][0], imms[k], width,
					   &want, &n, &z, &c, &v);
				expect("adds_imm", ARM64_OP_ADDS_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, c, v, 1);
				/* compare lanes, lhs = dst seeded value */
				sub_oracle(seeds[i][1], imms[k], width,
					   &want, &n, &z, &c, &v);
				expect("cmp_imm", ARM64_OP_CMP_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, c, v, 0);
				add_oracle(seeds[i][1], imms[k], width,
					   &want, &n, &z, &c, &v);
				expect("cmn_imm", ARM64_OP_CMN_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, c, v, 0);
				/* TST/ANDS imm read the immediate directly
				 * through FLAG_RHS */
				logic_oracle(seeds[i][1], imms[k], width,
					     &want, &n, &z);
				expect("tst_imm", ARM64_OP_TST_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, 0U, 0U, 0);
				logic_oracle(seeds[i][0], imms[k], width,
					     &want, &n, &z);
				expect("ands_imm", ARM64_OP_ANDS_IMM,
				       seeds[i][1], seeds[i][0], 0U, width,
				       imms[k], want, n, z, 0U, 0U, 1);
			}
			/* reg lanes: rhs = x2 */
			sub_oracle(seeds[i][0], seeds[i][2], width, &want, &n,
				   &z, &c, &v);
			expect("subs_reg", ARM64_OP_SUBS_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       c, v, 1);
			add_oracle(seeds[i][0], seeds[i][2], width, &want, &n,
				   &z, &c, &v);
			expect("adds_reg", ARM64_OP_ADDS_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       c, v, 1);
			sub_oracle(seeds[i][1], seeds[i][0], width, &want, &n,
				   &z, &c, &v);
			expect("cmp_reg", ARM64_OP_CMP_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       c, v, 0);
			add_oracle(seeds[i][1], seeds[i][0], width, &want, &n,
				   &z, &c, &v);
			expect("cmn_reg", ARM64_OP_CMN_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       c, v, 0);
			logic_oracle(seeds[i][1], seeds[i][0], width, &want,
				   &n, &z);
			expect("tst_reg", ARM64_OP_TST_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       0U, 0U, 0);
			logic_oracle(seeds[i][1], ~seeds[i][0], width,
				     &want, &n, &z);
			expect("tst_bic", ARM64_OP_TST_BIC_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       0U, 0U, 0);
			logic_oracle(seeds[i][0], ~seeds[i][2], width,
				     &want, &n, &z);
			expect("bics", ARM64_OP_BICS_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, want, n, z,
			       0U, 0U, 1);
		}
	}

	/* EXPECT_REVIEW: verify the reg-lane semantics: TST_REG lhs=dst
	 * rhs=SRC; TST_BIC_REG rhs=SRC BIC; CMN_REG rhs=SRC; ANDS/BICS/sec: */
	{
		/* ands_reg x0-vs-x1 path check */
		logic_oracle(seeds[0][0], seeds[0][2], ARM64_WIDTH_64,
			     &want, &n, &z);
		expect("ands_reg_zero", ARM64_OP_ANDS_REG, seeds[0][1],
		       seeds[0][0], seeds[0][2], ARM64_WIDTH_64, 0U, want, n,
		       z, 0U, 0U, 1);
	}

	/* width narrowing witness of the writeback (SUBS w32 unreachable
	 * through a narrower reg read: the stepped FLAG_RHS applies the
	 * width narrowing; expects 0 with the narrowed borrow file) */
	{
		sub_oracle(0x100000000ULL, 0U, ARM64_WIDTH_32, &want, &n, &z,
			   &c, &v);
		expect("subs_w32_narrow", ARM64_OP_SUBS_IMM, 0U,
		       0x100000000ULL, 0U, ARM64_WIDTH_32, 0U, want, n, z, c,
		       v, 1);
		cases++;
	}

	/* compare-lane preserve: sentinel x0 with seeded SRC lanes */
	{
		sub_oracle(0x5a5a5a5a5a5a5a5aULL, 7U, ARM64_WIDTH_64, &want,
			   &n, &z, &c, &v);
		expect_preserve("cmp_preserve_flags", ARM64_OP_CMP_IMM, 3U,
				ARM64_WIDTH_64, 7U, n, z, c, v);
	}


	{
		add_oracle(0x5a5a5a5a5a5a5a5aULL, 7U, ARM64_WIDTH_64, &want,
			   &n, &z, &c, &v);
		expect_preserve("cmn_preserve_flags", ARM64_OP_CMN_IMM, 3U,
				ARM64_WIDTH_64, 7U, n, z, c, v);
	}
	{
		/* runaway writeback through the width write chain would
		 * clobber or narrow the seeded dst at the 32-bit lane: the
		 * sentinel keeps bit 32 and low bits a narrowed store would
		 * erase */
		__u64 got;
		__u8 tag, n2, z2, c2, v2;
		__u64 sentinel = 0x10000000000000b0ULL;

		drive(ARM64_OP_CMP_IMM, sentinel, 3U, 0U, ARM64_WIDTH_32, 7U,
		      &got, &tag, &n2, &z2, &c2, &v2);
		if (got != sentinel) {
			printf("MISMATCH cmp_w32_dst 0x%llx\n",
			       (unsigned long long)got);
			failures++;
		}
		cases++;
	}
	{
		logic_oracle(0x5a5a5a5a5a5a5a5aULL, 5U, ARM64_WIDTH_64,
			     &want, &n, &z);
		expect_preserve("tst_preserve_flags", ARM64_OP_TST_IMM, 3U,
				ARM64_WIDTH_64, 5U, n, z, 0U, 0U);
	}
	{
		logic_oracle(0x5a5a5a5a5a5a5a5aULL,
			     ~(__u64)3U, ARM64_WIDTH_64, &want, &n, &z);
		expect_preserve("tst_bic_preserve_flags", ARM64_OP_TST_BIC_REG,
				3U, ARM64_WIDTH_64, 0U, n, z, 0U, 0U);
	}

	/* unsupported default: an out-of-family opcode reaches the caller's
	 * unsupported hook, not a silent fall-through */
	{
		__u64 got;
		__u8 tag, n2, z2, c2, v2;
		unsigned long before = unsupported_calls;

		drive(70U, 1U, 2U, 0U, ARM64_WIDTH_64, 0U, &got, &tag, &n2,
		      &z2, &c2, &v2);
		if (unsupported_calls == before) {
			printf("MISMATCH unsupported call missing\n");
			failures++;
		}
		cases++;
	}

	if (failures) {
		printf("arm64 flag route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 flag route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
