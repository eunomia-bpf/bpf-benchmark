/*
 * Host cross-check for the AArch64 simulator's routing of the effective
 * instruction width through the machine-checked `generated/arm64_width.h`
 * contract (STEP 0106).
 *
 * The `ARM64_SIM_L_EXEC` dispatcher resolves the instruction width once, at its
 * prologue, from the raw width code carried in its FLAGS word:
 *
 *     __u8 __a64_l_width = ARM64_SIM_L_EFFECTIVE_WIDTH(FLAGS);
 *
 * and every arm below that line operates at that effective width. The contract
 * states the whole meaning of the resolution: an absent code (0) names the
 * 64-bit width, and every other code names itself.
 *
 * Because the resolved width is the only width that reaches any body, driving
 * the dispatcher with a raw code and with its effective code must produce
 * identical whole state. For the four real codes (1, 2, 4, 8) the effective
 * code is the code itself, which still exercises the routed path; for the
 * absent code (0) the effective code is 8, so the equality that matters - a raw
 * 0 driving the machine exactly as a raw 8 does - is the real regression
 * tripwire.
 *
 * The fifteen scenarios below each drive one supported dispatcher arm that
 * reads `__a64_l_width`, so a resolution that stopped short of the 64-bit
 * fallback (or a body that restated the width from the raw FLAGS) shows up as a
 * differing field between the two frames. After every pair the oracle compares
 * all 31 general registers (value and provenance tag), the stack pointer, NZCV,
 * the LR and the two SIMD quarters, plus the whole 160-byte stack arena with
 * its 20 slot tags. Exit 1 on any mismatch.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_width_effective_route_host.c -o build/test_arm64_width_effective_route_host &&
 *   ./build/test_arm64_width_effective_route_host
 */

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
#include <string.h>

/* The simulator header expects this hook; the oracle drives only fully
 * supported arms, so the no-op stub is never the reason for a difference. */
static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

/* The contract's whole meaning: an absent code names 64 bits. Derived from the
 * raw code, never from the generated macro. */
static __u8 eff_of(__u8 code)
{
	return code ? code : ARM64_WIDTH_64;
}

/* A deterministic per-register value, with high bits set so a 64-bit write and
 * a narrow write are distinguishable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `ARM64_SIM_TAG_SCALAR`, so any form that
 * scalarizes a destination changes its tag. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* ---- Whole-state snapshot ---------------------------------------------- */

struct snap {
	__u64 x[31];
	__u8 t[31];
	__s64 sp;
	__u8 n, z, c, v;
	__u64 lr, v0, v0_hi;
	__u8 stack[ARM64_SIM_STACK_BYTES];
	__u8 stack_tag[KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES)];
};

#define SNAP_ONE(REG, NAME)                                                \
	do {                                                               \
		__p[__i] = __a64_##NAME.x;                                 \
		__t[__i] = __a64_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define SNAP_ALL(P, T)                                                     \
	do {                                                               \
		__u64 *__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		ARM64_SIM_L_FOR_EACH_GPR(SNAP_ONE)                         \
	} while (0)

#define CAPTURE_ALL(S)                                                     \
	do {                                                               \
		SNAP_ALL((S)->x, (S)->t);                                  \
		(S)->sp = __a64_sp;                                        \
		(S)->n = __a64_n;                                          \
		(S)->z = __a64_z;                                          \
		(S)->c = __a64_c;                                          \
		(S)->v = __a64_v;                                          \
		(S)->lr = __a64_lr;                                        \
		(S)->v0 = __a64_v0;                                        \
		(S)->v0_hi = __a64_v0_hi;                                  \
		memcpy((S)->stack, __a64_stack.b, ARM64_SIM_STACK_BYTES);  \
		memcpy((S)->stack_tag, __a64_stack_tag,                    \
		       sizeof((S)->stack_tag));                            \
	} while (0)

/* Quiet one declared local without evaluating it: an unevaluated `sizeof`
 * counts as a use for -Wunused-variable while keeping the register cells live
 * for the driven bodies. */
#define QUIET_GPR_ONE(REG, NAME)                                           \
	(void)sizeof(__a64_##NAME);                                        \
	(void)sizeof(__a64_##NAME##_tag);

/* Declare and quiet the register file, the flags, the LR and the SIMD quarters
 * so every scenario compiles warning-free. The stack arena is declared in scope
 * by ARM64_SIM_L_DECLARE_STACK, so each frame gets its own zero-initialized
 * image and the snapshot's stack fields compare trivially. */
#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_n;                                                     \
	(void)__a64_z;                                                     \
	(void)__a64_c;                                                     \
	(void)__a64_v;                                                     \
	(void)__a64_lr;                                                    \
	(void)__a64_v0;                                                    \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp;                                                    \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE)

/* Seed every GPR cell inside the caller's own DECL_STATE() scope, so the
 * scenario's locals are the ones the driven body mutates. */
#define SEED_GPR_ONE(REG, NAME)                                            \
	do {                                                               \
		__a64_##NAME.ptr =                                         \
			(void *)(long)pattern_reg((unsigned)(REG));        \
		__a64_##NAME##_tag = pattern_tag((unsigned)(REG));         \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)


static int snap_eq(const struct snap *a, const struct snap *b, const char *what,
		   __u8 w)
{
	unsigned j;
	int bad = 0;

	for (j = 0; j < 31U; j++) {
		if (a->x[j] != b->x[j] || a->t[j] != b->t[j]) {
			printf("MISMATCH %s width=%u cell=%u x=0x%llx/0x%llx "
			       "tag=%u/%u\n", what, w, j,
			       (unsigned long long)a->x[j],
			       (unsigned long long)b->x[j],
			       (unsigned)a->t[j], (unsigned)b->t[j]);
			bad = 1;
		}
	}
	if (a->sp != b->sp) {
		printf("MISMATCH %s width=%u sp=%lld/%lld\n", what, w,
		       (long long)a->sp, (long long)b->sp);
		bad = 1;
	}
	if (a->n != b->n || a->z != b->z || a->c != b->c || a->v != b->v) {
		printf("MISMATCH %s width=%u flags %u%u%u%u/%u%u%u%u\n", what, w,
		       a->n, a->z, a->c, a->v, b->n, b->z, b->c, b->v);
		bad = 1;
	}
	if (a->lr != b->lr || a->v0 != b->v0 || a->v0_hi != b->v0_hi) {
		printf("MISMATCH %s width=%u lr/v0 %llx %llx/%llx "
		       "%llx %llx/%llx\n", what, w,
		       (unsigned long long)a->lr,
		       (unsigned long long)a->v0,
		       (unsigned long long)b->v0,
		       (unsigned long long)a->v0_hi,
		       (unsigned long long)a->v0_hi,
		       (unsigned long long)b->v0_hi);
		bad = 1;
	}
	for (j = 0; j < ARM64_SIM_STACK_BYTES; j++) {
		if (a->stack[j] != b->stack[j]) {
			printf("MISMATCH %s width=%u stack[%u]=0x%02x/0x%02x\n",
			       what, w, j, a->stack[j], b->stack[j]);
			bad = 1;
		}
	}
	for (j = 0; j < sizeof(a->stack_tag); j++) {
		if (a->stack_tag[j] != b->stack_tag[j]) {
			printf("MISMATCH %s width=%u stack_tag[%u]=%u/%u\n", what,
			       w, j, a->stack_tag[j], b->stack_tag[j]);
			bad = 1;
		}
	}
	return !bad;
}

/* The contract's observable: the raw code and its effective code drive the
 * whole modeled state identically. */
static void check_equiv(const char *what, void (*fn)(__u8, struct snap *),
			__u8 w)
{
	struct snap a, b;

	fn(w, &a);
	fn(eff_of(w), &b);
	cases++;
	if (!snap_eq(&a, &b, what, w))
		failures++;
}

/* ---- Scenario runners (drive the routed dispatcher arms) ---------------- */

/* MOV_IMM: the width-narrowed scalar write drops the source provenance. */
static void scn_mov_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_MOV_IMM, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, 0U, 0x123456789abcu);
	CAPTURE_ALL(s);
}

/* MOV_REG: the tag-copy write at doubleword width, the width-narrowed scalar
 * write otherwise. */
static void scn_mov_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_MOV_REG, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, 0U, 0U);
	CAPTURE_ALL(s);
}

/* MOVK: inserts the immediate at the AUX low-byte column 16, then narrows. */
static void scn_movk(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_MOVK, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, ARM64_AUX_MOVK(16U), 0x7fU);
	CAPTURE_ALL(s);
}

/* ALU_IMM ADD: RHS is the immediate, and the non-scalar source routes ADD at
 * doubleword width through the pointer write. */
static void scn_alu_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(ARM64_ALU_ADD, ARM64_MOD_NONE, 0U), 0x99U);
	CAPTURE_ALL(s);
}

/* ALU_REG ADD: RHS comes from the second source register. */
static void scn_alu_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_ALU_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(ARM64_ALU_ADD, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* SHIFT_IMM LSL: the shift kind is the AUX low byte, the amount the immediate. */
static void scn_shift_lsl(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_SHIFT_IMM, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, ARM64_AUX_SHIFT(ARM64_SHIFT_LSL), 3U);
	CAPTURE_ALL(s);
}

/* SHIFT_IMM ROR: the width-guarded rotate. */
static void scn_shift_ror(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_SHIFT_IMM, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, ARM64_AUX_SHIFT(ARM64_SHIFT_ROR), 5U);
	CAPTURE_ALL(s);
}

/* MVN: the width-masked complement. */
static void scn_mvn(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_MVN, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, 0U, 0U);
	CAPTURE_ALL(s);
}

/* NEG: the width-masked negation. */
static void scn_neg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_NEG, ARM64_X2, ARM64_X1, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, 0U, 0U);
	CAPTURE_ALL(s);
}

/* CMP_IMM: writes NZCV only, at the width-dependent subtraction. */
static void scn_cmp_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_CMP_IMM, ARM64_X1, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w, 0U, 0x40U);
	CAPTURE_ALL(s);
}

/* CCMP_REG: the condition is false under the zeroed flags, so the fallback
 * NZCV bits from the AUX B1 field are installed. */
static void scn_ccmp_fallback(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_CCMP_REG, ARM64_X1, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX_CCMP(ARM64_COND_EQ, 5U), 0U);
	CAPTURE_ALL(s);
}

/* CCMP_IMM: the always-taken condition installs width-dependent subtraction
 * flags from the immediate. */
static void scn_ccmp_flags(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_CCMP_IMM, ARM64_X1, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX_CCMP(ARM64_COND_AL, 0U),
			 0x8000000000000001ULL);
	CAPTURE_ALL(s);
}

/* CSEL: the raw AUX word is the condition code; under the zeroed flags EQ is
 * false, selecting the second source, and doubleword width routes the tag-copy
 * write. */
static void scn_csel(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_CSEL, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, ARM64_COND_EQ, 0U);
	CAPTURE_ALL(s);
}

/* SUBS_IMM: subtraction with writeback of the result and the flags. */
static void scn_subs_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_SUBS_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, 0U, 0x10U);
	CAPTURE_ALL(s);
}

/* ADDS_IMM: addition with writeback of the result and the flags. */
static void scn_adds_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	ARM64_SIM_L_EXEC(ARM64_OP_ADDS_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, 0U, 0x10U);
	CAPTURE_ALL(s);
}

/* ---- Exact width-resolution checks -------------------------------------- */

static void check_contract_sweep(void)
{
	static const __u8 width_codes[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned i, b;

	cases++;
	if (KPROG_ARM64_WIDTH_ABSENT_CODE != 0U) {
		printf("MISMATCH absent code = %u, want 0\n",
		       (unsigned)KPROG_ARM64_WIDTH_ABSENT_CODE);
		failures++;
	}
	cases++;
	if (KPROG_ARM64_WIDTH_EFFECTIVE_DEFAULT != ARM64_WIDTH_64) {
		printf("MISMATCH default code = %u, want %u\n",
		       (unsigned)KPROG_ARM64_WIDTH_EFFECTIVE_DEFAULT,
		       (unsigned)ARM64_WIDTH_64);
		failures++;
	}

	for (b = 0; b <= 0xffU; b++) {
		__u8 got = (__u8)ARM64_SIM_L_EFFECTIVE_WIDTH(b);
		__u8 want = eff_of((__u8)b);

		cases++;
		if (got != want) {
			printf("MISMATCH effective(%u) = %u, want %u\n", b,
			       (unsigned)got, (unsigned)want);
			failures++;
		}
	}

	for (i = 0; i < sizeof(width_codes); i++) {
		__u8 code = width_codes[i];
		__u8 got = (__u8)ARM64_SIM_L_EFFECTIVE_WIDTH(code);

		cases++;
		if (got != code) {
			printf("MISMATCH effective(%u) = %u, want identity\n",
			       (unsigned)code, (unsigned)got);
			failures++;
		}
	}
}

int main(void)
{
	static const __u8 widths[] = {
		0U, ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32,
		ARM64_WIDTH_64,
	};
	unsigned k;

	check_contract_sweep();

	for (k = 0; k < sizeof(widths); k++) {
		__u8 w = widths[k];

		check_equiv("mov_imm", scn_mov_imm, w);
		check_equiv("mov_reg", scn_mov_reg, w);
		check_equiv("movk", scn_movk, w);
		check_equiv("alu_imm", scn_alu_imm, w);
		check_equiv("alu_reg", scn_alu_reg, w);
		check_equiv("shift_lsl", scn_shift_lsl, w);
		check_equiv("shift_ror", scn_shift_ror, w);
		check_equiv("mvn", scn_mvn, w);
		check_equiv("neg", scn_neg, w);
		check_equiv("cmp_imm", scn_cmp_imm, w);
		check_equiv("ccmp_fallback", scn_ccmp_fallback, w);
		check_equiv("ccmp_flags", scn_ccmp_flags, w);
		check_equiv("csel", scn_csel, w);
		check_equiv("subs_imm", scn_subs_imm, w);
		check_equiv("adds_imm", scn_adds_imm, w);
	}

	if (failures) {
		printf("arm64 width effective route host cross-check: "
		       "FAIL (%d failures)\n", failures);
		return 1;
	}
	printf("arm64 width effective route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
