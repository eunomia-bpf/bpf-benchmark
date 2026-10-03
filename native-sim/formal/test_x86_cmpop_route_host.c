/*
 * Host cross-check for the x86 simulator's routing of the `CMP_IMM` /
 * `CMP_REG` / `TEST_IMM` / `TEST_REG` bodies through the machine-checked
 * `KPROG_X86_CMPOP_*` contract.
 *
 * The two families `X86_SIM_L_EXEC_CMP_IMM_OP[_AUX]` and
 * `X86_SIM_L_EXEC_CMP_REG_OP[_AUX]` now compose one
 * `X86_SIM_L_EXEC_CMP_REG_STEP` that selects the right-hand-side source
 * through `KPROG_X86_CMPOP_RHS_SOURCE`, the flag kind through
 * `KPROG_X86_CMPOP_FLAG_KIND`, and the one resolved width through
 * `KPROG_X86_CMPOP_WRITE_WIDTH`, so the contract - not the handler - decides
 * where the right-hand side comes from, which flags are produced, and which
 * width both operands are read at. This oracle includes the *simulator*
 * header so it drives those real bodies rather than a restatement, and
 * compares the whole register file, its tags, and all four flags against an
 * independent model.
 *
 * Unlike the pre-existing `test_x86_cmpop_host.c` (which checks the contract
 * tables plus a model but never includes the simulator header), this oracle
 * covers the routing the four bodies now perform. It plants, per opcode,
 * cases where each routed fact is *numerically distinguishable* from the
 * wrong selection:
 *
 *   * the register forms read `SRC` at the `AUX` source lane while the
 *     immediate forms read the decoded immediate, and the planted `SRC`
 *     registers differ from the immediate at every width and lane, so a body
 *     that resolves the wrong right-hand side reports different flags;
 *   * the `CMP` opcodes produce zero-borrow subtraction flags and the `TEST`
 *     opcodes the logical flags of the width-narrowed conjunction, so a body
 *     that resolves the wrong flag kind clears `CF`/`OF` (or fails to) and
 *     moves `SF`;
 *   * every `FLAGS` width code is exercised across both `AUX` lanes, and the
 *     planted register values carry bits above bit 32, so a body that resolves
 *     the wrong width narrows differently.
 *
 * All four bodies write no register: the oracle requires the whole register
 * file and its tags to survive untouched and only the four flags to move.
 *
 * Build/run:
 *   cd native-sim/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_cmpop_route_host.c -o /tmp/t_cmpop_route && /tmp/t_cmpop_route
 */
#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* Deterministic register pattern: register-dependent and monotone in the
 * index, with every low word distinct from the driven immediate and every
 * value carrying bits above bit 32, so the immediate/register split, the
 * subtraction order, and the width narrowing (64 versus 32/16/8) are all
 * numerically observable in the flags. */
static __u64 pattern_reg(unsigned i)
{
	return 0xa5a5000000000000ULL + (__u64)i * 0x100ULL +
	       (__u64)(i + 1U);
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The width mask, restated from the raw codes rather than taken from the
 * generated x86_width.h. */
static __u64 model_mask(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static unsigned model_bits(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 8U;
	if (width == X86_WIDTH_16)
		return 16U;
	if (width == X86_WIDTH_32)
		return 32U;
	return 64U;
}

/* The width/lane register read the bodies perform: an 8-bit read shifts by the
 * byte-lane offset first, every wider read ignores the lane and narrows to its
 * own width. Restated independently of the generated macros. */
static __u64 model_read(__u64 value, unsigned width, unsigned lane)
{
	__u64 shifted = width == X86_WIDTH_8 ? value >> lane : value;

	return shifted & model_mask(width);
}

/* The immediate widening `x86_store_imm_value` performs: the low 32 bits,
 * sign-extended only under the 64-bit width. */
static __u64 model_imm(__u64 value, unsigned width)
{
	if (width == X86_WIDTH_64 && (value & 0x80000000ULL) != 0ULL)
		return (value & 0xffffffffULL) | 0xffffffff00000000ULL;
	return value & 0xffffffffULL;
}

/* The immediate every `_IMM` case is driven with: bit 31 set (so the 64-bit
 * widening sign-extends), and a low byte that no register pattern step
 * collides with. */
#define CASE_IMM 0xA5000011ULL

/* The modelled flag production: the zero-borrow subtraction the `CMP` opcodes
 * write, restated from the raw codes. */
static void model_sub_flags(__u64 lhs, __u64 rhs, unsigned width,
			    __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u64 mask = model_mask(width);
	__u64 sign = 1ULL << (model_bits(width) - 1U);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = (lhs - rhs) & mask;

	*cf = (__u8)(a < b);
	*zf = (__u8)(a == b);
	*sf = (__u8)((r & sign) != 0);
	*of = (__u8)(((a ^ b) & ((a ^ r) & sign)) != 0);
}

/* The logical flags the `TEST` opcodes write: the conjunction narrowed at the
 * width, with `CF = OF = 0`, restated from the raw codes. */
static void model_logic_flags(__u64 lhs, __u64 rhs, unsigned width,
			      __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u64 value = (lhs & rhs) & model_mask(width);

	*cf = 0U;
	*zf = (__u8)(value == 0);
	*sf = (__u8)((value >> (model_bits(width) - 1U)) & 1U);
	*of = 0U;
}

/*
 * Run one compare/test body over the modelled register file and compare the
 * whole state against the independent model.
 *
 * `op` selects `CMP_IMM` (0), `CMP_REG` (1), `TEST_IMM` (2) or `TEST_REG`
 * (3); `flags` is the opcode's FLAGS width code; `dst_shift`/`src_shift` are
 * the `AUX` destination/source lane offsets; `dst_reg` is the destination
 * register the body reads its left-hand side from; `src_reg` is the register
 * the `_REG` forms read their right-hand side from; `via_dispatch` is true to
 * drive the `X86_SIM_L_EXEC` arm instead of the body directly.
 */
static void check_step(unsigned op, unsigned flags, unsigned dst_shift,
		       unsigned src_shift, unsigned dst_reg, unsigned src_reg,
		       unsigned via_dispatch)
{
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u32 aux = KPROG_X86_REG_LANE_AUX(0U, dst_shift, src_shift);
	__u64 lhs;
	__u64 rhs;
	__u8 mcf;
	__u8 mzf;
	__u8 msf;
	__u8 mof;
	unsigned is_test = (op == 2U || op == 3U);
	unsigned is_reg = (op == 1U || op == 3U);

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	X86_SIM_L_DECLARE_STACK();

	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	/* ---- plant the modelled state in both the sim and the model ---- */
	for (i = 0; i < 16U; i++) {
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)pattern_reg(i),
					    pattern_tag(i));
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}

	/* ---- independent model of the compare/test step ---- */
	lhs = model_read(mreg[dst_reg], w, dst_shift);
	rhs = is_reg ? model_read(mreg[src_reg], w, src_shift)
		     : model_imm(CASE_IMM, w);
	if (is_test)
		model_logic_flags(lhs, rhs, w, &mcf, &mzf, &msf, &mof);
	else
		model_sub_flags(lhs, rhs, w, &mcf, &mzf, &msf, &mof);

	/* ---- run the real body ---- */
	if (op == 0U) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_CMP_IMM, dst_reg, 0U, flags, aux,
				      CASE_IMM);
		else
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX(X86_OP_CMP_IMM, dst_reg,
						      flags, aux, CASE_IMM);
	} else if (op == 1U) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_CMP_REG, dst_reg, src_reg, flags,
				      aux, 0U);
		else
			X86_SIM_L_EXEC_CMP_REG_OP_AUX(X86_OP_CMP_REG, dst_reg,
						      src_reg, flags, aux);
	} else if (op == 2U) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_TEST_IMM, dst_reg, 0U, flags, aux,
				      CASE_IMM);
		else
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX(X86_OP_TEST_IMM, dst_reg,
						      flags, aux, CASE_IMM);
	} else {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_TEST_REG, dst_reg, src_reg, flags,
				      aux, 0U);
		else
			X86_SIM_L_EXEC_CMP_REG_OP_AUX(X86_OP_TEST_REG, dst_reg,
						      src_reg, flags, aux);
	}

	/* ---- compare the whole register file: none written ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH op=%u flags=%u dsh=%u ssh=%u dst=%u "
			       "src=%u reg%u: got 0x%llx want 0x%llx\n",
			       op, flags, dst_shift, src_shift, dst_reg,
			       src_reg, i, (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH op=%u flags=%u dsh=%u ssh=%u dst=%u "
			       "src=%u reg%u tag: got %u want %u\n",
			       op, flags, dst_shift, src_shift, dst_reg,
			       src_reg, i, got_tag, mtag[i]);
			failures++;
			return;
		}
	}

	/* ---- compare the flags: all four are written ---- */
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH op=%u flags=%u dsh=%u ssh=%u dst=%u src=%u "
		       "flags: got cf=%u zf=%u sf=%u of=%u want cf=%u zf=%u "
		       "sf=%u of=%u\n",
		       op, flags, dst_shift, src_shift, dst_reg, src_reg,
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_CMPOP_RHS_SOURCE(0U) != KPROG_X86_CMPOP_RHS_IMMEDIATE ||
	    KPROG_X86_CMPOP_RHS_SOURCE(1U) != KPROG_X86_CMPOP_RHS_REGISTER) {
		printf("MISMATCH rhs source selector\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_FLAG_KIND(0U) != KPROG_X86_CMPOP_FLAGS_SUB ||
	    KPROG_X86_CMPOP_FLAG_KIND(1U) != KPROG_X86_CMPOP_FLAGS_LOGIC) {
		printf("MISMATCH flag kind selector\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_WRITE_WIDTH(0U) !=
		    KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT) {
		printf("MISMATCH write-width fallback\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_OP_CMP_IMM_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_IMMEDIATE ||
	    KPROG_X86_CMPOP_OP_CMP_REG_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_IMMEDIATE ||
	    KPROG_X86_CMPOP_OP_TEST_REG_RHS_SOURCE !=
		    KPROG_X86_CMPOP_RHS_REGISTER) {
		printf("MISMATCH per-opcode rhs table\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_OP_CMP_IMM_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_SUB ||
	    KPROG_X86_CMPOP_OP_CMP_REG_FLAG_KIND != KPROG_X86_CMPOP_FLAGS_SUB ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_FLAG_KIND !=
		    KPROG_X86_CMPOP_FLAGS_LOGIC ||
	    KPROG_X86_CMPOP_OP_TEST_REG_FLAG_KIND !=
		    KPROG_X86_CMPOP_FLAGS_LOGIC) {
		printf("MISMATCH per-opcode flag-kind table\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const unsigned dst_shifts[2] = { 0U, 1U };
	static const unsigned src_shifts[2] = { 0U, 1U };
	static const unsigned dst_regs[3] = { X86_RAX, X86_RSI, X86_R15 };
	static const unsigned src_regs[3] = { X86_R8, X86_R9, X86_R10 };
	unsigned via;
	unsigned op;
	unsigned fi;
	unsigned di;
	unsigned si;
	unsigned bi;
	unsigned ci;

	for (via = 0; via < 2U; via++) {
		for (op = 0; op < 4U; op++) {
			for (fi = 0; fi < 5U; fi++) {
				for (di = 0; di < 2U; di++) {
					for (si = 0; si < 2U; si++) {
						for (bi = 0; bi < 3U; bi++) {
							for (ci = 0; ci < 3U;
							     ci++) {
								check_step(op,
									flags_codes[fi],
									dst_shifts[di],
									src_shifts[si],
									dst_regs[bi],
									src_regs[ci],
									via);
							}
						}
					}
				}
			}
		}
	}

	check_selectors();

	if (failures != 0) {
		printf("x86 cmpop route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 cmpop route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
