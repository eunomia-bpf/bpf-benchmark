/*
 * Host cross-check for the x86-64 `SETCC` handler (`X86_OP_SETCC`, `0x16`),
 * the body `X86_SIM_L_EXEC_SETCC`.
 *
 * Part 1 verifies the generated condition table KPROG_X86_SETCC_COND_MATCHED
 * against the raw `X86_CC_*` codes, and sweeps the whole 256-value raw byte
 * space so the unsupported codes are pinned to KPROG_X86_SETCC_COND_NONE.
 *
 * Part 2 verifies the generated lane table KPROG_X86_SETCC_LANE against the
 * write helper's equality test: only a destination shift of exactly 8 selects
 * the high byte, and the sweep covers the whole 256-value byte space.
 *
 * Part 3 drives the whole handler over a deterministic register file:
 * it decodes the AUX payload and destination-shift bytes through the generated
 * AUX decoders, resolves the condition through the generated condition macro
 * and the real KPROG_X86_EVAL_CC expression, selects the byte lane through the
 * generated lane macro, and writes through the generated register write
 * contract KPROG_X86_WRITE_REG8. Every byte and the tag of every register must
 * match a hand-written model of the C body byte for byte.
 *
 * The point of this oracle is what this handler does NOT do: it resolves the
 * condition with the flags as given (no flag computation), it fixes the write
 * width at 8 regardless of the AUX source-shift byte, it scalarizes the
 * destination tag unconditionally (unlike CMOV's pointer-preserving w64 arm),
 * it reads the condition from the AUX payload byte (unlike CMOV, which reads
 * the whole AUX word), and the lane test is an equality rather than a
 * truthiness test, so a destination shift of 9 selects the low byte.
 *
 * The raw-byte-to-condition expression mapping is the obligation this oracle
 * carries: the generated condition table is swept here against the real
 * KPROG_X86_EVAL_CC expression for all 16 raw flag combinations and all 256
 * raw condition bytes, including the unsupported parity codes 10 and 11.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_setcc_host.c -o /tmp/t_sc && /tmp/t_sc
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

/* The generated headers define __always_inline functions in the kernel build;
 * provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_REG_NONE 0xffU
#define X86_RSP 4U

#define X86_OP_SETCC 0x16U

#define X86_CC_O 0U
#define X86_CC_NO 1U
#define X86_CC_B 2U
#define X86_CC_AE 3U
#define X86_CC_E 4U
#define X86_CC_NE 5U
#define X86_CC_BE 6U
#define X86_CC_A 7U
#define X86_CC_S 8U
#define X86_CC_NS 9U
#define X86_CC_L 12U
#define X86_CC_GE 13U
#define X86_CC_LE 14U
#define X86_CC_G 15U

#define X86_SIM_TAG_SCALAR 0U
#define X86_SIM_TAG_ABI 1U
#define X86_SIM_TAG_PACKET 2U
#define X86_SIM_TAG_STACK 4U
#define X86_SIM_TAG_MAP_PTR 5U
#define X86_SIM_TAG_HELPER_ID 7U

#include "generated/x86_setcc.h"
#include "generated/x86_cond.h"
#include "generated/x86_reg_lane_aux.h"
#include "generated/x86_reg_write.h"
#include "generated/x86_width.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, laid out the way the write helper    */
/* expects: a byte view, a 16-bit view and a pointer view over the     */
/* same eight bytes, plus the tag byte.                                */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U

struct oracle_reg {
	union {
		__u8 b[8];
		__u16 w;
		void *ptr;
	} u;
	__u8 tag;
};

static struct oracle_reg oracle_regs[ORACLE_REGS];
static struct oracle_reg pristine_regs[ORACLE_REGS];
static struct oracle_reg result_regs[ORACLE_REGS];

static __u64 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	unsigned j;

	for (i = 0; i < ORACLE_REGS; i++) {
		for (j = 0; j < 8; j++)
			oracle_regs[i].u.b[j] =
				(__u8)oracle_synthetic((__u64)i * 8U + j);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

/* The condition expression table, restated from the raw codes rather than
 * taken from the generated x86_cond.h. */
static __u8 oracle_eval_cc(__u8 cc, int cf, int zf, int sf, int of)
{
	switch (cc) {
	case X86_CC_O:
		return (__u8)of;
	case X86_CC_NO:
		return (__u8)!of;
	case X86_CC_B:
		return (__u8)cf;
	case X86_CC_AE:
		return (__u8)!cf;
	case X86_CC_E:
		return (__u8)zf;
	case X86_CC_NE:
		return (__u8)!zf;
	case X86_CC_BE:
		return (__u8)(cf || zf);
	case X86_CC_A:
		return (__u8)(!cf && !zf);
	case X86_CC_S:
		return (__u8)sf;
	case X86_CC_NS:
		return (__u8)!sf;
	case X86_CC_L:
		return (__u8)(sf != of);
	case X86_CC_GE:
		return (__u8)(sf == of);
	case X86_CC_LE:
		return (__u8)(zf || (sf != of));
	case X86_CC_G:
		return (__u8)(!zf && (sf == of));
	default:
		return 0U;
	}
}

/* The modeled write helper, restated: the equality test on the byte shift, the
 * byte selected, and the unconditional scalar tag. */
static void oracle_write_reg8(unsigned reg, __u8 value, __u8 byte_shift)
{
	if (byte_shift == 8U)
		oracle_regs[reg].u.b[1] = value;
	else
		oracle_regs[reg].u.b[0] = value;
	oracle_regs[reg].tag = X86_SIM_TAG_SCALAR;
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated condition table vs. the raw codes.            */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const __u8 accepted[14] = {
		X86_CC_O,  X86_CC_NO, X86_CC_B,  X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A,  X86_CC_S,  X86_CC_NS,
		X86_CC_L,  X86_CC_GE, X86_CC_LE, X86_CC_G,
	};
	unsigned cases = 0;
	unsigned i;
	unsigned cc;

	/* The 14 accepted codes fold back to their own code; every other byte in
	 * the 256-value space folds to KPROG_X86_SETCC_COND_NONE. */
	for (cc = 0; cc < 256U; cc++) {
		int is_accepted = 0;
		__u32 got = KPROG_X86_SETCC_COND_MATCHED((__u8)cc);

		for (i = 0; i < 14U; i++)
			if (accepted[i] == cc)
				is_accepted = 1;
		if (is_accepted) {
			if (got != (__u32)cc) {
				fprintf(stderr,
					"cond mismatch cc=%u got=%u want=%u\n",
					cc, got, cc);
				return 0;
			}
		} else if (got != KPROG_X86_SETCC_COND_NONE) {
			fprintf(stderr,
				"unsupported cc=%u got=%u want NONE\n",
				cc, got);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the generated lane table vs. the oracle.                    */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	unsigned cases = 0;
	unsigned shift;

	for (shift = 0; shift < 256U; shift++) {
		__u8 want = (shift == 8U) ? KPROG_X86_SETCC_LANE_HIGH
					  : KPROG_X86_SETCC_LANE_LOW;
		__u8 got = KPROG_X86_SETCC_LANE((__u8)shift);

		if (got != want) {
			fprintf(stderr, "lane mismatch shift=%u got=%u want=%u\n",
				shift, got, want);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: the full handler composition vs. the hand-written body.     */
/*                                                                    */
/* `contract_step` decodes, resolves, selects and writes through       */
/* the generated contracts; `model_step` restates the body from the    */
/* raw fields. They must agree byte for byte in every register, tag    */
/* included.                                                          */
/* ------------------------------------------------------------------ */

struct setcc_effect {
	__u32 cond;
	__u8 lane;
	__u8 value;
};

/* flags is a nibble: bit 0 = cf, bit 1 = zf, bit 2 = sf, bit 3 = of. */
static struct setcc_effect contract_step(unsigned reg, __u32 aux, __u8 flags)
{
	__u8 payload = KPROG_X86_REG_LANE_AUX_PAYLOAD(aux);
	__u8 dst_shift = KPROG_X86_REG_LANE_AUX_DST_SHIFT(aux);
	__u8 lane = KPROG_X86_SETCC_LANE(dst_shift);
	__u8 byte_shift = (lane == KPROG_X86_SETCC_LANE_HIGH) ? 8U : 0U;
	__u8 value = (__u8)KPROG_X86_EVAL_CC(payload, ((flags >> 0) & 1U),
					     ((flags >> 1) & 1U),
					     ((flags >> 2) & 1U),
					     ((flags >> 3) & 1U));
	struct setcc_effect r;

	r.cond = KPROG_X86_SETCC_COND_MATCHED(payload);
	r.lane = lane;
	r.value = value;

	/* The resolved width is the 8-bit code, so the write is the 8-bit one. */
	KPROG_X86_WRITE_REG8(oracle_regs[reg].u, oracle_regs[reg].tag, value,
			     byte_shift, X86_SIM_TAG_SCALAR);
	return r;
}

static struct setcc_effect model_step(unsigned reg, __u32 aux, __u8 flags)
{
	__u8 payload = (__u8)(aux & 0xffU);
	__u8 dst_shift = (__u8)((aux >> 8) & 0xffU);
	__u8 lane = (dst_shift == 8U) ? KPROG_X86_SETCC_LANE_HIGH
				      : KPROG_X86_SETCC_LANE_LOW;
	__u8 byte_shift = (dst_shift == 8U) ? 8U : 0U;
	__u8 value = oracle_eval_cc(payload, (flags >> 0) & 1U,
				    (flags >> 1) & 1U, (flags >> 2) & 1U,
				    (flags >> 3) & 1U);
	struct setcc_effect r;

	r.lane = lane;
	r.value = value;
	if ((payload == X86_CC_O) || (payload == X86_CC_NO) ||
	    (payload == X86_CC_B) || (payload == X86_CC_AE) ||
	    (payload == X86_CC_E) || (payload == X86_CC_NE) ||
	    (payload == X86_CC_BE) || (payload == X86_CC_A) ||
	    (payload == X86_CC_S) || (payload == X86_CC_NS) ||
	    (payload == X86_CC_L) || (payload == X86_CC_GE) ||
	    (payload == X86_CC_LE) || (payload == X86_CC_G))
		r.cond = payload;
	else
		r.cond = KPROG_X86_SETCC_COND_NONE;

	oracle_write_reg8(reg, value, byte_shift);
	return r;
}

static unsigned part3(void)
{
	unsigned cases = 0;
	unsigned reg;
	unsigned payload;
	unsigned shift;
	unsigned flags;

	for (reg = 0; reg < ORACLE_REGS; reg++) {
		for (payload = 0; payload < 256U; payload++) {
			for (shift = 0; shift < 8U; shift++) {
				for (flags = 0; flags < 16U; flags++) {
					__u32 aux =
						KPROG_X86_REG_LANE_AUX(payload,
								       shift,
								       0U);
					struct setcc_effect got;
					struct setcc_effect want;

					if (KPROG_X86_REG_LANE_AUX_PAYLOAD(aux) !=
						    payload ||
					    KPROG_X86_REG_LANE_AUX_DST_SHIFT(
						    aux) != shift) {
						fprintf(stderr,
							"aux roundtrip "
							"payload=%u shift=%u "
							"aux=%x\n",
							payload, shift, aux);
						return 0;
					}

					oracle_restore_pristine();
					got = contract_step(reg, aux,
							    (__u8)flags);
					memcpy(result_regs, oracle_regs,
					       sizeof(oracle_regs));
					oracle_restore_pristine();
					want = model_step(reg, aux,
							  (__u8)flags);
					if (got.cond != want.cond ||
					    got.lane != want.lane ||
					    got.value != want.value ||
					    memcmp(result_regs, oracle_regs,
						   sizeof(oracle_regs))) {
						fprintf(stderr,
							"handler mismatch reg=%u "
							"aux=%x flags=%u "
							"got=(%u,%u,%u) "
							"want=(%u,%u,%u)\n",
							reg, aux, flags,
							got.cond, got.lane,
							got.value, want.cond,
							want.lane, want.value);
						return 0;
					}
					cases++;
				}
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 4: the full destination-shift sweep, so the lane equality is   */
/* exercised at every value the field can carry, not just 0 and 8.     */
/* ------------------------------------------------------------------ */

static unsigned part4(void)
{
	unsigned cases = 0;
	unsigned reg;
	unsigned payload;
	unsigned shift;

	for (reg = 0; reg < ORACLE_REGS; reg++) {
		for (payload = 0; payload < 16U; payload++) {
			for (shift = 0; shift < 256U; shift++) {
				__u32 aux = KPROG_X86_REG_LANE_AUX(
					payload, shift, payload);
				struct setcc_effect got;
				struct setcc_effect want;

				oracle_restore_pristine();
				got = contract_step(reg, aux, 0x5U);
				memcpy(result_regs, oracle_regs,
				       sizeof(oracle_regs));
				oracle_restore_pristine();
				want = model_step(reg, aux, 0x5U);
				if (got.cond != want.cond ||
				    got.lane != want.lane ||
				    got.value != want.value ||
				    memcmp(result_regs, oracle_regs,
					   sizeof(oracle_regs))) {
					fprintf(stderr,
						"lane sweep mismatch reg=%u "
						"aux=%x got=(%u,%u,%u) "
						"want=(%u,%u,%u)\n",
						reg, aux, got.cond, got.lane,
						got.value, want.cond,
						want.lane, want.value);
					return 0;
				}
				cases++;
			}
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 6: the generated 8-bit write helper vs. the oracle, swept over */
/* every byte shift the field can carry. A truthiness test would keep  */
/* the low byte for a shift of 9; the equality test does not.          */
/* ------------------------------------------------------------------ */

static unsigned part6(void)
{
	unsigned cases = 0;
	unsigned shift;

	for (shift = 0; shift < 256U; shift++) {
		struct oracle_reg got;
		struct oracle_reg want;

		memset(&got, 0xa5, sizeof(got));
		got.tag = X86_SIM_TAG_MAP_PTR;
		memset(&want, 0xa5, sizeof(want));
		want.tag = X86_SIM_TAG_MAP_PTR;

		KPROG_X86_WRITE_REG8(got.u, got.tag, 0x3cU, (__u8)shift,
				     X86_SIM_TAG_SCALAR);
		if (shift == 8U)
			want.u.b[1] = 0x3cU;
		else
			want.u.b[0] = 0x3cU;
		want.tag = X86_SIM_TAG_SCALAR;

		if (got.u.b[0] != (shift == 8U ? 0xa5U : 0x3cU) ||
		    got.u.b[1] != (shift == 8U ? 0x3cU : 0xa5U) ||
		    got.tag != X86_SIM_TAG_SCALAR ||
		    memcmp(got.u.b, want.u.b, 8U)) {
			fprintf(stderr,
				"write8 mismatch shift=%u b0=%02x b1=%02x tag=%u\n",
				shift, got.u.b[0], got.u.b[1], got.tag);
			return 0;
		}
		cases++;
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 5: pins on the asymmetries the composition is about.           */
/* ------------------------------------------------------------------ */

static unsigned part5(void)
{
	unsigned cases = 0;
	static const __u8 accepted_probe[8] = { 0U, 1U, 3U, 7U, 8U, 12U, 14U, 15U };
	unsigned i;

	/* Pin 1: 8 selects the high byte, 9 selects the low byte — the test is an
	 * equality, not a truthiness test. */
	oracle_restore_pristine();
	(void)contract_step(0, KPROG_X86_REG_LANE_AUX(5U, 8U, 0U), 0x0U);
	if (oracle_regs[0].u.b[1] != 1U || oracle_regs[0].u.b[0] !=
						   pristine_regs[0].u.b[0])
		return 0;
	oracle_restore_pristine();
	(void)contract_step(0, KPROG_X86_REG_LANE_AUX(5U, 9U, 0U), 0x0U);
	if (oracle_regs[0].u.b[0] != 1U || oracle_regs[0].u.b[1] !=
						   pristine_regs[0].u.b[1])
		return 0;
	cases++;

	/* Pin 2: the destination tag is scalarized even when the register held a
	 * pointer tag, because the byte write always writes the scalar tag. */
	oracle_restore_pristine();
	oracle_regs[3].tag = X86_SIM_TAG_MAP_PTR;
	(void)contract_step(3, KPROG_X86_REG_LANE_AUX(5U, 0U, 0U), 0x0U);
	if (oracle_regs[3].tag != X86_SIM_TAG_SCALAR)
		return 0;
	cases++;

	/* Pin 3: the write width is fixed at 8, so the upper seven bytes of the
	 * destination survive whatever the source-shift byte says. */
	oracle_restore_pristine();
	(void)contract_step(7, KPROG_X86_REG_LANE_AUX(5U, 0U, 0xffU), 0x0U);
	if (memcmp(&oracle_regs[7].u.b[1], &pristine_regs[7].u.b[1], 7U) != 0)
		return 0;
	cases++;

	/* Pin 4: the condition is read from the AUX payload byte — a payload of 4
	 * is `e`, a payload of 5 is `ne` — and the destination-shift byte does not
	 * influence the resolved condition. */
	oracle_restore_pristine();
	(void)contract_step(1, KPROG_X86_REG_LANE_AUX(4U, 0U, 0U), 0x1U);
	if (oracle_regs[1].u.b[0] != 0U)
		return 0;
	oracle_restore_pristine();
	(void)contract_step(1, KPROG_X86_REG_LANE_AUX(5U, 0U, 0U), 0x1U);
	if (oracle_regs[1].u.b[0] != 1U)
		return 0;
	cases++;

	/* Pin 5: an unsupported parity code writes 0, the KPROG_X86_EVAL_CC
	 * default, and does so through the same 8-bit write path. */
	oracle_restore_pristine();
	(void)contract_step(2, KPROG_X86_REG_LANE_AUX(10U, 0U, 0U), 0xfU);
	if (oracle_regs[2].u.b[0] != 0U)
		return 0;
	if (oracle_regs[2].tag != X86_SIM_TAG_SCALAR)
		return 0;
	cases++;

	/* Pin 6: every accepted code reproduces the raw KPROG_X86_EVAL_CC
	 * expression for all 16 flag combinations. */
	for (i = 0; i < 8U; i++) {
		unsigned f;

		for (f = 0; f < 16U; f++) {
			__u8 raw = (__u8)KPROG_X86_EVAL_CC(
				accepted_probe[i], ((f >> 0) & 1U),
				((f >> 1) & 1U), ((f >> 2) & 1U),
				((f >> 3) & 1U));
			__u8 model = oracle_eval_cc(accepted_probe[i],
						    (f >> 0) & 1U,
						    (f >> 1) & 1U,
						    (f >> 2) & 1U,
						    (f >> 3) & 1U);

			if (raw != model) {
				fprintf(stderr,
					"cc expression mismatch cc=%u f=%u "
					"raw=%u model=%u\n",
					accepted_probe[i], f, raw, model);
				return 0;
			}
			cases++;
		}
	}

	/* Pin 7: `set ne` on the zero flag writes 0; on a clear zero flag writes
	 * 1. */
	oracle_restore_pristine();
	(void)contract_step(4, KPROG_X86_REG_LANE_AUX(5U, 8U, 0U), 0x2U);
	if (oracle_regs[4].u.b[1] != 0U)
		return 0;
	oracle_restore_pristine();
	(void)contract_step(4, KPROG_X86_REG_LANE_AUX(5U, 8U, 0U), 0x0U);
	if (oracle_regs[4].u.b[1] != 1U)
		return 0;
	cases++;

	return cases;
}

int main(void)
{
	unsigned p1, p2, p3, p4, p5, p6;

	oracle_reset();
	oracle_snapshot_pristine();

	p1 = part1();
	if (!p1) {
		fprintf(stderr, "part 1 failed\n");
		return 1;
	}
	p2 = part2();
	if (!p2) {
		fprintf(stderr, "part 2 failed\n");
		return 1;
	}
	p3 = part3();
	if (!p3) {
		fprintf(stderr, "part 3 failed\n");
		return 1;
	}
	p4 = part4();
	if (!p4) {
		fprintf(stderr, "part 4 failed\n");
		return 1;
	}
	p5 = part5();
	if (!p5) {
		fprintf(stderr, "part 5 failed\n");
		return 1;
	}
	p6 = part6();
	if (!p6) {
		fprintf(stderr, "part 6 failed\n");
		return 1;
	}

	printf("x86 setcc handler host cross-check: OK (%u cases)\n",
	       p1 + p2 + p3 + p4 + p5 + p6);
	return 0;
}
