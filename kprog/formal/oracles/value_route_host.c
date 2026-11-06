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

static __u64 width_bits(__u8 width)
{
	switch (width) {
	case ARM64_WIDTH_64:
		return 64U;
	case ARM64_WIDTH_32:
		return 32U;
	case ARM64_WIDTH_16:
		return 16U;
	case ARM64_WIDTH_8:
		return 8U;
	}
	return 64U;
}

/* Architectural unary: complement or negation, narrowed. */
static __u64 unary_oracle(unsigned op, __u64 src, __u8 width)
{
	__u64 mask = narrow_mask(width);

	return (op == ARM64_OP_MVN ? ~src : 0ULL - src) & mask;
}

/* Architectural condition-gated negation: NE over seeded NZCV (c==1,z==0 ->
 * NE holds), so taken = (cond == ARM64_COND_NE). */
static __u64 cneg_oracle(unsigned taken, __u64 src, __u8 width)
{
	__u64 mask = narrow_mask(width);

	return (taken ? 0ULL - src : src) & mask;
}

/* Architectural EXTR: concatenate SRC:SRC2 and rotate right by the masked
 * amount, narrowed by the caller. */
static __u64 extr_oracle(__u64 hi, __u64 lo, __u64 amount, __u8 width)
{
	__u64 bits = width_bits(width);
	__u64 k = amount & (bits - 1U);
	__u64 mask = narrow_mask(width);
	__u64 out;

	if (k == 0U)
		out = lo;
	else
		out = ((lo & mask) >> k) | (hi << (bits - k));
	return out & mask;
}

static __u64 extrev_oracle(unsigned op, __u64 src, __u8 width)
{
	__u64 out = src;
	__u64 mask = narrow_mask(width);

	switch (op) {
	case ARM64_OP_REV:
		out = width == ARM64_WIDTH_32 ?
		      __builtin_bswap32((__u32)src) :
		      __builtin_bswap64(src);
		break;
	case ARM64_OP_REV16:
		out = (out & 0xff00ff00ff00ff00ULL) >> 8 |
		      (out & 0x00ff00ff00ff00ffULL) << 8;
		break;
	case ARM64_OP_SXTH:
		out = (__u64)(__s64)(__s16)src;
		break;
	case ARM64_OP_SXTW:
		out = (__u64)(__s64)(__s32)src;
		break;
	case ARM64_OP_SXTB:
		out = (__u64)(__s64)(__s8)src;
		break;
	}
	return out & mask;
}

/* Architectural bitfield ops with the AUX byte fields. */
static __u64 bitfield_oracle(unsigned kind, __u64 src, __u64 dst,
	__u8 lsbv, __u8 bitsv, __u8 width)
{
	__u64 mask = bitsv == 0U ? 0ULL :
		     (bitsv >= 64U ? ~0ULL : (1ULL << bitsv) - 1ULL);
	__u64 sr = lsbv >= 64U ? 0ULL : src >> lsbv;
	__u64 sl = lsbv >= 64U ? 0ULL : src << lsbv;
	__u64 field = lsbv >= 64U ? 0ULL : mask << lsbv;

	switch (kind) {
	case 0U: /* UBFX */
		return sr & mask;
	case 1U: /* SBFX */
		if (bitsv == 0U)
			return 0ULL;
		return ((sr & mask) ^ (1ULL << (bitsv - 1U))) -
		       (1ULL << (bitsv - 1U));
	case 2U: /* UBFIZ */
		return sl & field;
	case 3U: /* BFXIL */
		return ((dst & ~mask) | (sr & mask)) & narrow_mask(width);
	case 4U: /* BFI */
		return ((dst & ~field) | (sl & field)) & narrow_mask(width);
	}
	return 0;
}

/* Architectural shift by the width-masked amount. */
static __u64 shift_oracle(unsigned kind, __u64 value, __u64 amount,
	__u8 width)
{
	__u64 mask = narrow_mask(width);
	__u64 k = amount & (width == ARM64_WIDTH_32 ? 31ULL : 63ULL);

	if (k == 0U)
		return value & mask;
	switch (kind) {
	case 0U: /* LSL */
		return (value << k) & mask;
	case 1U: /* LSR */
		return (value & mask) >> k;
	case 2U: /* ASR */
		if (width == ARM64_WIDTH_32)
			return (__u64)((__s32)value >> k) & mask;
		return (__u64)((__s64)value >> k) & mask;
	case 3U: /* ROR */
		if (width == ARM64_WIDTH_32) {
			__u32 w32 = (__u32)value;

			return ((__u64)((w32 >> k) | (w32 << (32U - k)))) &
			       mask;
		}
		return ((value >> k) | (value << (64U - k))) & mask;
	}
	return 0;
}

/* The generated KPROG_ARM64_MOD_VALUE arm re-derived: modifier MOD applies
 * SHIFT lanes (lsl/lsr/asr/ror masked by width, extend arms unmasked). */
static __u64 mod_oracle(__u64 v, __u8 mod, __u8 shift, __u8 width)
{
	__u64 mask = narrow_mask(width);
	__u8 amount = (__u8)(shift & (width == ARM64_WIDTH_32 ? 31U : 63U));

	switch (mod) {
	case 0U:
		return v & mask;
	case 1U:
		return (v << amount) & mask;
	case 2U:
		return (v & mask) >> amount;
	case 3U:
		return width == ARM64_WIDTH_32 ?
		       (__u64)((__s64)(__s32)v >> amount) :
		       (__u64)((__s64)v >> amount);
	case 4U:
		if (width == ARM64_WIDTH_32) {
			__u32 w32 = (__u32)v;

			return amount ? (__u64)((w32 >> amount) |
						(w32 << (32U - amount))) :
				       (__u64)w32;
		}
		return amount ? (v >> amount) | (v << (64U - amount)) : v;
	case 5U:
		return (__u64)(__u32)v << shift;
	case 6U:
		return (__u64)(__s64)(__s32)v << shift;
	case 7U:
		return (__u64)(__u16)v << shift;
	case 8U:
		return (__u64)(__s64)(__s16)v << shift;
	case 9U:
		return (__u64)(__u8)v << shift;
	case 10U:
		return (__u64)(__s64)(__s8)v << shift;
	}
	return v & mask;
}

/* Architectural complemented OR, narrowed. */
static __u64 orn_oracle(__u64 lhs, __u64 rhs, __u8 width)
{
	return (lhs | ~rhs) & narrow_mask(width);
}

/* drive(): seed x1=sv x2=s2v, dst x0=dv, lead lanes per arm, exec, read x0. */
static void drive(unsigned op, __u64 dv, __u64 sv, __u64 s2v, __u8 width,
	__u32 aux, __u32 imm, __u64 *res, __u8 *r_tag)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, dv, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1, sv, ARM64_WIDTH_64);
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2, s2v, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(op, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3,
			width, aux, imm);
	*res = __a64_x0.x;
	*r_tag = __a64_x0_tag;
	cases++;
}
static void expect2(const char *what, unsigned op, __u64 dv, __u64 sv,
	__u64 s2v, __u8 width, __u32 aux, __u32 imm, __u64 want,
	int wb, __u32 kind, __u64 amt)
{
	__u64 got;
	__u8 tag;

	drive(op, dv, sv, s2v, width, aux, imm, &got, &tag);
	if (wb && got != want) {
		printf("MISMATCH %s kind=%u amt=%llu w=%u got=0x%llx want=0x%llx\n",
		       what, kind, (unsigned long long)amt, width,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
	if (tag != ARM64_SIM_TAG_SCALAR) {
		printf("MISMATCH %s tag %u\n", what, tag);
		failures++;
	}
	cases++;
}

static void expect(const char *what, unsigned op, __u64 dv, __u64 sv,
	__u64 s2v, __u8 width, __u32 aux, __u32 imm, __u64 want,
	int wb)
{
	__u64 got;
	__u8 tag;

	drive(op, dv, sv, s2v, width, aux, imm, &got, &tag);
	if (wb && got != want) {
		printf("MISMATCH %s val got=0x%llx want=0x%llx\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
	if (tag != ARM64_SIM_TAG_SCALAR) {
		printf("MISMATCH %s tag %u\n", what, tag);
		failures++;
	}
	cases++;
}

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
		{0x1234567890abcdefULL, 0xfedcba0987654321ULL,
		 0x0f0f0f0f0f0f0f0fULL},
	};
	/* shift amounts never zero and never the masked-off tail */
	static const __u32 amounts[] = { 1U, 5U, 17U, 33U };

	for (unsigned w = 0; w < 4; w++) {
		__u8 width = w == 0 ? ARM64_WIDTH_64 : w == 1 ?
			     ARM64_WIDTH_32 : w == 2 ? ARM64_WIDTH_16 :
			     ARM64_WIDTH_8;

		for (unsigned i = 0; i < sizeof(seeds) / sizeof(seeds[0]);
		     i++) {
			/* unary: dst = f(x1) */
			expect("mvn", ARM64_OP_MVN, seeds[i][1], seeds[i][0],
			       0U, width, 0U, 0U,
			       unary_oracle(ARM64_OP_MVN, seeds[i][0], width),
			       1);
			expect("neg", ARM64_OP_NEG, seeds[i][1], seeds[i][0],
			       0U, width, 0U, 0U,
			       unary_oracle(ARM64_OP_NEG, seeds[i][0], width),
			       1);
			/* cneg: cond NE (code 1) in AUX B0, seeded NZCV
			 * n=1 z=0 c=1 v=0 -> NE holds -> taken */
			expect("cneg_taken", ARM64_OP_CNEG, seeds[i][1],
			       seeds[i][0], 0U, width, 1U, 0U,
			       cneg_oracle(1, seeds[i][0], width), 1);
			/* cond EQ (code 0) -> not taken -> dst = src */
			expect("cneg_not", ARM64_OP_CNEG, seeds[i][1],
			       seeds[i][0], 0U, width, 0U, 0U,
			       cneg_oracle(0, seeds[i][0], width), 1);
			/* extrev without lane change */
			expect("sxth", ARM64_OP_SXTH, seeds[i][1],
			       seeds[i][0], 0U, width, 0U, 0U,
			       extrev_oracle(ARM64_OP_SXTH, seeds[i][0],
					     width), 1);
			expect("sxtw", ARM64_OP_SXTW, seeds[i][1],
			       seeds[i][0], 0U, width, 0U, 0U,
			       extrev_oracle(ARM64_OP_SXTW, seeds[i][0],
					     width), 1);
			expect("sxtb", ARM64_OP_SXTB, seeds[i][1],
			       seeds[i][0], 0U, width, 0U, 0U,
			       extrev_oracle(ARM64_OP_SXTB, seeds[i][0],
					     width), 1);
			expect("rev", ARM64_OP_REV, seeds[i][1], seeds[i][0],
			       0U, width, 0U, 0U,
			       extrev_oracle(ARM64_OP_REV, seeds[i][0], width),
			       1);
			expect("rev16", ARM64_OP_REV16, seeds[i][1],
			       seeds[i][0], 0U, width, 0U, 0U,
			       extrev_oracle(ARM64_OP_REV16, seeds[i][0],
					     width), 1);
			/* EXTR rotates x2:x1 by the masked immediate */
			expect("extr", ARM64_OP_EXTR, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, 5U,
			       extr_oracle(seeds[i][0], seeds[i][2], 5U, width),
			       1);
			expect("extr0", ARM64_OP_EXTR, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, 0U,
			       extr_oracle(seeds[i][0], seeds[i][2], 0U, width),
			       1);
			/* orn: dst = x1 | ~x2 */
			expect("orn", ARM64_OP_ORN_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width, 0U, 0U,
			       orn_oracle(seeds[i][0], seeds[i][2], width), 1);
			/* orn_mod: x1 | ~(x2 lsr 3) via AUX MOD=2 SHIFT=3 */
			expect("orn_mod", ARM64_OP_ORN_REG, seeds[i][1],
			       seeds[i][0], seeds[i][2], width,
			       (0U) | (2U << 8) | (3U << 16), 0U,
			       orn_oracle(seeds[i][0],
					  mod_oracle(seeds[i][2], 2U,
						     3U, width), width), 1);
			expect("ubfx", ARM64_OP_BITFIELD, seeds[i][1],
			       seeds[i][0], 0U, width,
			       (0U) | (4U << 8) | (8U << 16), 0U,
			       bitfield_oracle(0, seeds[i][0],
					       seeds[i][1], 4U, 8U, width), 1);
			/* BFXIL: keep x2 low bits below the field, drop
			 * x2 bits 8..15 in favor of x1 bits 12..15 -> low */
			expect("bfxil", ARM64_OP_BITFIELD, seeds[i][1],
			       seeds[i][0], seeds[i][2], width,
			       (3U) | (4U << 8) | (8U << 16), 0U,
			       bitfield_oracle(3, seeds[i][0], seeds[i][1],
					       4U, 8U, width), 1);
			/* BFI: drop x1 bits 8..15 onto x2 field at lsb 4 */
			expect("bfi", ARM64_OP_BITFIELD, seeds[i][1],
			       seeds[i][0], seeds[i][2], width,
			       (4U) | (4U << 8) | (8U << 16), 0U,
			       bitfield_oracle(4, seeds[i][0], seeds[i][1],
					       4U, 8U, width), 1);
			/* shifts by immediate and register amounts, all kinds */
			for (unsigned kind = 0; kind < 4; kind++) {
				for (unsigned a = 0;
				     a < sizeof(amounts) /
				     sizeof(amounts[0]); a++) {
					__u64 immamt =
						 (__u64)amounts[a],
						 regamt = seeds[i][2];

					expect2("shift_imm",
						ARM64_OP_SHIFT_IMM,
						seeds[i][1], seeds[i][0], 0U,
						width, kind, immamt,
						shift_oracle(kind,
							     seeds[i][0],
							     immamt, width),
						1, kind, immamt);
					expect2("shift_reg",
						ARM64_OP_SHIFT_REG,
						seeds[i][1], seeds[i][0],
						regamt, width, kind, 7U,
						shift_oracle(kind,
							     seeds[i][0],
							     regamt, width),
						1, kind, regamt);
				}
			}
		}
	}

	/* width narrowing of every writeback at w32 with a high bit set */
	{
		__u64 src = 0x12345678deadbeefULL;
		__u64 want;

		want = unary_oracle(ARM64_OP_MVN, src, ARM64_WIDTH_32);
		expect("mvn_w32_narrow", ARM64_OP_MVN, 0x100000000ULL, src,
		       0U, ARM64_WIDTH_32, 0U, 0U, want, 1);
		/* the writeback must keep bit 32 only if the narrowed value
		 * route re-wrote the full register: with the mutant dropping
		 * the narrow chain bit 32 would flip; with the correct arm
		 * the narrowed low 32 bits mask the sentinel bit away */
	}

	/* EXTR preserves: lsb==widthish masks */
	{
		__u64 got;
		__u8 tag;
		__u64 sentinel = 0x10000000000000b0ULL;

		drive(ARM64_OP_BITFIELD, sentinel, 5U, 0U, ARM64_WIDTH_64,
		      (4U) | (0U << 8) | (0U << 16), 0U, &got, &tag);
		if (got != sentinel) {
			printf("MISMATCH bitfield_bfi_zero_rows 0x%llx\n",
			       (unsigned long long)got);
			failures++;
		}
		cases++;
	}

	/* unsupported default: an out-of-family opcode reaches the hook */
	{
		__u64 got;
		__u8 tag;
		unsigned long before = unsupported_calls;

		drive(70U, 1U, 2U, 0U, ARM64_WIDTH_64, 0U, 0U, &got, &tag);
		if (unsupported_calls == before) {
			printf("MISMATCH unsupported call missing\n");
			failures++;
		}
		cases++;
	}

	if (failures) {
		printf("arm64 value route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 value route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
