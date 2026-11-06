/*
 * Host cross-check for the AArch64 simulator's *routing* of its dispatcher's
 * eight dispatch families through the machine-checked opcode-membership contract
 * (generated/arm64_dispatch_family.h, STEP 0125).
 *
 * The macros under test are the real generated membership macros
 * KPROG_ARM64_<F>_HANDLED(OP), reached through the real dispatcher
 * `ARM64_SIM_L_EXEC` of `../arm64/arm64_sim_local_bpf.h`. Each family selects an
 * immediate and a register opcode through one arm; the oracle drives both
 * members of every family with operand sets that agree - the immediate equal to
 * the register the register member would read - and requires the two drives to
 * leave the *whole modeled state* identical, the definitional meaning of the
 * pair sharing one arm. A membership macro that stopped naming a member would
 * send that member to the unsupported arm (caught by the call counter, and by
 * the frames diverging) or into the wrong arm (caught by the frames diverging).
 *
 * After the pair is confirmed equal the oracle also checks the arm actually did
 * its work: a family that writes a destination must have changed it, and a
 * flags-only family (CMP/TST/CCMP) must have left the destination untouched. A
 * non-member opcode must reach the unsupported arm exactly, so the counter is
 * not vacuously zero.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_dispatch_family_route_host.c -o build/test_arm64_dispatch_family_route_host &&
 *   ./build/test_arm64_dispatch_family_route_host
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

/* The simulator header expects this hook. Its call count is the observable
 * that a member reached its arm and a non-member did not: a member that fell
 * through to the unsupported arm shows up here *and* as a diverging frame. */
static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

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

#define QUIET_GPR_ONE(REG, NAME)                                           \
	(void)sizeof(__a64_##NAME);                                        \
	(void)sizeof(__a64_##NAME##_tag);

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

#define SEED_GPR_ONE(REG, NAME)                                            \
	do {                                                               \
		__a64_##NAME.ptr =                                         \
			(void *)(long)pattern_reg((unsigned)(REG));        \
		__a64_##NAME##_tag = pattern_tag((unsigned)(REG));         \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

/* Seed the flags to a sentinel that no arm restates, so a flags-only arm's
 * NZCV write is observable in the frame. */
#define SEED_FLAGS()                                                       \
	do {                                                               \
		__a64_n = 1;                                               \
		__a64_z = 1;                                               \
		__a64_c = 1;                                               \
		__a64_v = 1;                                               \
	} while (0)

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
		printf("MISMATCH %s width=%u lr=%llx/%llx v0=%llx/%llx "
		       "v0_hi=%llx/%llx\n",
		       what, w,
		       (unsigned long long)a->lr,
		       (unsigned long long)b->lr,
		       (unsigned long long)a->v0,
		       (unsigned long long)b->v0,
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

/* The rhs value carried as an immediate by the family's IMM member and seeded
 * into the source register the REG member would read. */
#define RHS 0xdeadbeefcafebabeULL
/* The shift amount for the SHIFT family (small enough to be a legal amount). */
#define SHIFT_AMOUNT 3U

/* ---- Per-family scenarios (drive the dispatcher arms) ------------------ */

/* ALU_IMM / ALU_REG ADD: the rhs is the immediate or the second source. */
static void scn_alu_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ALU_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(ARM64_ALU_ADD, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_alu_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ALU_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(ARM64_ALU_ADD, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* SHIFT_IMM / SHIFT_REG LSL: the amount is the immediate or the second source. */
static void scn_shift_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, SHIFT_AMOUNT, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_SHIFT_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, ARM64_AUX_SHIFT(ARM64_SHIFT_LSL),
			 SHIFT_AMOUNT);
	CAPTURE_ALL(s);
}

static void scn_shift_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, SHIFT_AMOUNT, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_SHIFT_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, ARM64_AUX_SHIFT(ARM64_SHIFT_LSL),
			 0U);
	CAPTURE_ALL(s);
}

/* SUBS_IMM / SUBS_REG: lhs from SRC, rhs from the immediate or SRC2. */
static void scn_subs_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_SUBS_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_subs_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_SUBS_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* ADDS_IMM / ADDS_REG. */
static void scn_adds_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ADDS_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_adds_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ADDS_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* CMP_IMM / CMP_REG: lhs from DST, rhs from the immediate or SRC. */
static void scn_cmp_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_CMP_IMM, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_cmp_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_CMP_REG, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* TST_IMM / TST_REG: lhs from DST, rhs from the immediate or SRC. */
static void scn_tst_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_TST_IMM, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_tst_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_TST_REG, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* ANDS_REG / ANDS_IMM: lhs from SRC, rhs from SRC2 or the immediate. */
static void scn_ands_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ANDS_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_ands_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_ANDS_REG, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w,
			 ARM64_AUX(0U, ARM64_MOD_NONE, 0U), 0U);
	CAPTURE_ALL(s);
}

/* CCMP_IMM / CCMP_REG: lhs from DST, rhs from the immediate or SRC; NZCV from
 * the AUX lane. COND_AL makes the compare always apply. */
static void scn_ccmp_imm(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_CCMP_IMM, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX_CCMP(ARM64_COND_AL, 0U), RHS);
	CAPTURE_ALL(s);
}

static void scn_ccmp_reg(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X3, RHS, ARM64_WIDTH_64);
	ARM64_SIM_L_EXEC(ARM64_OP_CCMP_REG, ARM64_X2, ARM64_X3, ARM64_REG_NONE,
			 ARM64_REG_NONE, w,
			 ARM64_AUX_CCMP(ARM64_COND_AL, 0U), 0U);
	CAPTURE_ALL(s);
}

/* A non-member opcode with no arm at all, to prove the unsupported counter is
 * live and not vacuously zero. */
static void scn_nonmember(__u8 w, struct snap *s)
{
	DECL_STATE();
	SEED_GPRS();
	SEED_FLAGS();
	ARM64_SIM_L_EXEC(ARM64_OP_RET, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_REG_NONE, w, 0U, 0U);
	CAPTURE_ALL(s);
}

/* ---- Pair equivalence -------------------------------------------------- */

/* The two members of a family must leave the identical whole state, and neither
 * may reach the unsupported arm. `dst_writes` says whether the family's arm
 * writes its destination, so the arm's work is observable, not merely routed. */
static void check_pair(const char *what, void (*imm)(__u8, struct snap *),
		       void (*reg)(__u8, struct snap *), __u8 w, int dst_writes)
{
	struct snap a, b;
	unsigned long u0 = unsupported_calls;
	unsigned long u1, u2;
	__u64 seeded = pattern_reg(2U);

	imm(w, &a);
	u1 = unsupported_calls;
	reg(w, &b);
	u2 = unsupported_calls;

	cases++;
	if (u1 != u0) {
		printf("MISMATCH %s width=%u imm member reached the unsupported "
		       "arm\n", what, w);
		failures++;
	}
	cases++;
	if (u2 != u1) {
		printf("MISMATCH %s width=%u reg member reached the unsupported "
		       "arm\n", what, w);
		failures++;
	}
	cases++;
	if (!snap_eq(&a, &b, what, w))
		failures++;

	/* The arm's observable: a writing family changed its destination, a
	 * flags-only family left it untouched. */
	cases++;
	if (dst_writes) {
		if (a.x[2] == seeded) {
			printf("MISMATCH %s width=%u writing arm left dst "
			       "unchanged\n", what, w);
			failures++;
		}
	} else {
		if (a.x[2] != seeded) {
			printf("MISMATCH %s width=%u flags-only arm wrote dst "
			       "0x%llx\n", what, w,
			       (unsigned long long)a.x[2]);
			failures++;
		}
	}
}

/* The non-member opcode must reach the unsupported arm exactly once and leave
 * the state unchanged, so the counter is a live observable. */
static void check_nonmember(__u8 w)
{
	struct snap a;
	unsigned long u0 = unsupported_calls;
	__u64 seeded2 = pattern_reg(2U);

	scn_nonmember(w, &a);
	cases++;
	if (unsupported_calls != u0 + 1UL) {
		printf("MISMATCH non-member width=%u unsupported delta=%lu\n", w,
		       unsupported_calls - u0);
		failures++;
	}
	cases++;
	if (a.x[2] != seeded2) {
		printf("MISMATCH non-member width=%u changed dst 0x%llx\n", w,
		       (unsigned long long)a.x[2]);
		failures++;
	}
}

int main(void)
{
	static const __u8 widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned k;

	for (k = 0; k < sizeof(widths); k++) {
		__u8 w = widths[k];

		check_pair("alu", scn_alu_imm, scn_alu_reg, w, 1);
		check_pair("shiftOp", scn_shift_imm, scn_shift_reg, w, 1);
		check_pair("subs", scn_subs_imm, scn_subs_reg, w, 1);
		check_pair("adds", scn_adds_imm, scn_adds_reg, w, 1);
		check_pair("cmp", scn_cmp_imm, scn_cmp_reg, w, 0);
		check_pair("tst", scn_tst_imm, scn_tst_reg, w, 0);
		check_pair("ands", scn_ands_imm, scn_ands_reg, w, 1);
		check_pair("ccmp", scn_ccmp_imm, scn_ccmp_reg, w, 0);

		check_nonmember(w);
	}

	if (failures) {
		printf("arm64 dispatch family route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 dispatch family route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
