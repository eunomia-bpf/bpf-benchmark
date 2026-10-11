/*
 * Host cross-check for the AArch64 simulator's *routing* of its dispatcher's
 * sixteen singleton opcode gates through the machine-checked one-member
 * membership contract (generated/arm64_dispatch_singleton.h, STEP 0126).
 *
 * The macros under test are the real generated membership macros
 * KPROG_ARM64_DISP_<NAME>_HANDLED(OP), reached through the real dispatcher
 * `ARM64_SIM_L_EXEC` of `../arm64/arm64_sim_local_bpf.h`. Each singleton owns
 * its own dispatcher arm; the oracle drives every member with operands that
 * exercise the arm's observable, computes the whole post-state with an
 * independent model, and requires the two to agree exactly. A membership macro
 * that stopped naming its opcode would send the opcode to the unsupported arm
 * (caught by the call counter and by the state diverging) or into the wrong arm
 * (caught by the state diverging).
 *
 * The sixteen singletons are NOP, MOVK, BITFIELD, CMN_IMM, CMN_REG,
 * TST_BIC_REG, BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0, STORE_D0, LOAD_Q0,
 * STORE_Q0 and FMOV. The observable each arm owns:
 *
 *   - NOP writes nothing; the whole state is identical to the planted one.
 *   - MOVK / BITFIELD / BICS_REG / LOAD / FMOV-to-register write a destination
 *     through the width-narrowed register write.
 *   - CMN_IMM / CMN_REG / TST_BIC_REG write only NZCV.
 *   - STORE / STP / STORE_D0 / STORE_Q0 move register state into memory.
 *   - LDP / LOAD_D0 / LOAD_Q0 move memory into registers (LDP into a register
 *     pair, the vector loads into `__a64_v0` / `__a64_v0_hi`).
 *   - FMOV with a vector direction writes `__a64_v0` instead of a register.
 *
 * A non-member opcode (RET) must reach the unsupported arm exactly once and
 * leave the state unchanged, so the counter is not vacuously zero.
 *
 * The memory family is driven across the addressing modes the arms share - the
 * base register (scalar heap, stack-tagged, ABI-tagged, and the stack pointer),
 * the pre/post writeback flag pairs, the index register presence, and the
 * immediate - so a misroute that selected the wrong arm shows up as a differing
 * byte, field or tag.
 *
 * The model below independently restates every arm over a flat, little-endian
 * byte image with its own register file, flags and stack arena, reusing the
 * already-proved generated sub-contracts (MOD/BITFIELD/MOVK value composition,
 * the add/logic flag composition, the D0/Q0 and LDP/STP lane plans). Every value
 * the arms can touch is compared after each case: all 31 general registers
 * (value and provenance tag), the stack pointer, NZCV, both SIMD quarters
 * `__a64_v0` / `__a64_v0_hi`, the whole 160-byte stack image with its 20 slot
 * tags, and the whole 4 KiB memory window byte for byte.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_dispatch_singleton_route_host.c -o build/test_arm64_dispatch_singleton_route_host &&
 *   ./build/test_arm64_dispatch_singleton_route_host
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

/* The simulator header expects this hook. Its call count is the observable that
 * a member reached its own arm and a non-member did not. */
static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

/* The model's own unsupported hook, so a generated sub-contract that took its
 * default arm is caught without touching the simulator's counter. */
static unsigned long model_unsupported_calls;
static void model_unsupported(void)
{
	model_unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* ---- Model state ------------------------------------------------------- */

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static __u64 m_v0;
static __u64 m_v0_hi;
static __u8 m_n;
static __u8 m_z;
static __u8 m_c;
static __u8 m_v;

/* The memory window the base registers point into. `heap` is the simulator's
 * backing store; `heap_exp` is the model's expected image. The two are
 * separate arrays so the simulator's writes stay observable. */
#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define ABI_BASE_OFF 2048U
#define RELOC_BASE_OFF 3072U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

/* The stack arena image, indexed exactly as `ARM64_SIM_L_STACK_*` index it
 * (bias included). */
#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

/* The stack base pointer value the oracle plants: with the simulator's
 * `ARM64_SIM_STACK_BIAS` of 96, an access at offset 0 lands at arena index 32,
 * leaving room for the driven immediates and the second lane / slot. */
#define STACK_BASE_VAL (-64LL)

/* The index register value: nonzero so the addressing mode is observable, and
 * small so every derived offset stays inside the planted windows. */
#define INDEX_VALUE 1ULL

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `ARM64_SIM_TAG_SCALAR`, so a form that
 * scalarizes changes the destination tag. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* ------------------------------------------------------------------ */
/* The flat little-endian byte image and the model's own read/write.    */
/* ------------------------------------------------------------------ */

/* Raw offset of an address into the simulator's memory window. */
static unsigned long heap_off(__u64 addr)
{
	return (unsigned long)(addr - (__u64)(unsigned long)heap);
}

/* Assemble `width` little-endian bytes from the model image. This is an
 * independent restatement of `KPROG_ARM64_LOAD_BYTES` for the four width
 * codes (whose numeric value is exactly the byte count). */
static __u64 img_load(const __u8 *base, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)base[i] << (8U * i);
	return v;
}

/* Scatter `APPLY_WIDTH(VALUE, WIDTH)` as `width` little-endian bytes. */
static void img_store(__u8 *base, unsigned width, __u64 value)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);
	unsigned i;

	for (i = 0; i < width; i++)
		base[i] = (__u8)(v >> (8U * i));
}

static __u64 heap_read(__u64 addr, unsigned width)
{
	return img_load(&heap_exp[heap_off(addr)], width);
}

static void heap_write(__u64 addr, unsigned width, __u64 value)
{
	img_store(&heap_exp[heap_off(addr)], width, value);
}

/* `ARM64_SIM_L_STACK_READ`: a 64-bit access at a qword-aligned slot reads the
 * slot as a word, every other access assembles bytes. */
static __u64 stack_read(__u32 idx, unsigned width)
{
	if (width == ARM64_WIDTH_64 && (idx & 7U) == 0U)
		return img_load(&stk_exp[idx], ARM64_WIDTH_64);
	return img_load(&stk_exp[idx], width);
}

/* `ARM64_SIM_L_STACK_READ_TAG`: the slot tag only survives a qword-aligned
 * 64-bit access; every other access is scalar. */
static __u8 stack_read_tag(__u32 idx, unsigned width)
{
	return KPROG_ARM64_STACK_TAG(width == ARM64_WIDTH_64,
				     (idx & 7U) == 0U)
		       ? stk_tag_exp[idx >> 3]
		       : ARM64_SIM_TAG_SCALAR;
}

/* `ARM64_SIM_L_STACK_WRITE_TAG`: the qword-aligned 64-bit case stores the word
 * and the slot tag; the byte case scatters `width` bytes and, at a qword
 * boundary, drops the slot tag to scalar. */
static void stack_write(__u32 idx, unsigned width, __u64 value, __u8 tag)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);

	if (KPROG_ARM64_STACK_TAG(width == ARM64_WIDTH_64, (idx & 7U) == 0U)) {
		img_store(&stk_exp[idx], ARM64_WIDTH_64, v);
		stk_tag_exp[idx >> 3] = tag;
	} else {
		if ((idx & 7U) == 0U)
			stk_tag_exp[idx >> 3] = ARM64_SIM_TAG_SCALAR;
		img_store(&stk_exp[idx], width, v);
	}
}

/* The base register's value and provenance tag, as the memory macros read
 * them. */
static __u64 m_base_val(unsigned base)
{
	return base == ARM64_SP ? (__u64)msp : mreg[base];
}

static __u8 m_base_tag(unsigned base)
{
	return base == ARM64_SP ? ARM64_SIM_TAG_STACK : mtag[base];
}

/* The register file as the arm bodies read it: the stack pointer, zero for the
 * zero register and the no-register sentinel, the stored value otherwise. */
static __u64 m_reg(unsigned reg)
{
	if (reg == ARM64_SP)
		return (__u64)msp;
	if (reg >= 31U)
		return 0;
	return mreg[reg];
}

static __u8 m_rtag(unsigned reg)
{
	if (reg == ARM64_SP)
		return ARM64_SIM_TAG_STACK;
	if (reg >= 31U)
		return ARM64_SIM_TAG_SCALAR;
	return mtag[reg];
}

/* `ARM64_SIM_L_MEM_BASE_OFF` with the source modifier the oracle drives at its
 * identity (MOD == 0), so the index register contributes its raw value. */
static __s64 model_base_off(unsigned aux, unsigned index, __s64 imm)
{
	return (__s64)KPROG_ARM64_MEM_OFFSET(
		(__u64)(ARM64_SIM_L_MEM_FLAGS(aux) &
			(ARM64_MEM_PRE | ARM64_MEM_POST)),
		index != ARM64_REG_NONE,
		(__u64)imm,
		index != ARM64_REG_NONE ? mreg[index] : 0ULL);
}

/* `ARM64_SIM_L_MEM_READ`, restated over the flat image. */
static __u64 model_mem_read(unsigned base, unsigned index, unsigned aux,
			    __s64 imm, __s64 extra, unsigned width)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
	__u8 tag = m_base_tag(base);
	__u64 bv = m_base_val(base);
	__u8 src = KPROG_ARM64_MEM_READ_SRC(base == ARM64_SP, tag, width);

	if (src == KPROG_ARM64_MEM_SRC_STACK)
		return stack_read((__u32)(ARM64_SIM_STACK_BIAS +
					  ((__s64)bv + off)), width);
	if (src == KPROG_ARM64_MEM_SRC_ABI_PTR_LOAD)
		return heap_read(bv + (__u64)off, width);
	if (src == KPROG_ARM64_MEM_SRC_RELOC_PTR)
		return bv;
	return heap_read(bv + (__u64)off, width);
}

/* `ARM64_SIM_L_MEM_READ_TAG`, restated over the flat image. */
static __u8 model_mem_read_tag(unsigned base, unsigned index, unsigned aux,
			       __s64 imm, __s64 extra, unsigned width)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
	__u8 tag = m_base_tag(base);
	__u8 src = KPROG_ARM64_MEM_READ_TAG(base == ARM64_SP, tag, width);

	if (src == KPROG_ARM64_MEM_TAG_STACK)
		return stack_read_tag((__u32)(ARM64_SIM_STACK_BIAS +
					      ((__s64)m_base_val(base) + off)),
				      width);
	if (src == KPROG_ARM64_MEM_TAG_ABI)
		return KPROG_ABI_LOAD_TAG(KPROG_ABI_KIND_XDP, off,
					  ARM64_SIM_TAG_SCALAR,
					  ARM64_SIM_TAG_PACKET,
					  ARM64_SIM_TAG_PACKET_END);
	if (src == KPROG_ARM64_MEM_TAG_MAP_PTR)
		return ARM64_SIM_TAG_MAP_PTR;
	return ARM64_SIM_TAG_SCALAR;
}

/* `ARM64_SIM_L_MEM_WRITE`, restated over the flat image. */
static void model_mem_write(unsigned base, unsigned index, unsigned aux,
			    __s64 imm, __s64 extra, unsigned width,
			    __u64 value, __u8 tag)
{
	__s64 off = model_base_off(aux, index, imm) + extra;
	__u8 t = m_base_tag(base);

	if (base == ARM64_SP || t == ARM64_SIM_TAG_STACK) {
		__s64 b = (__s64)m_base_val(base);

		stack_write((__u32)(ARM64_SIM_STACK_BIAS + (b + off)), width,
			    value, tag);
	} else {
		heap_write(m_base_val(base) + (__u64)off, width, value);
	}
}

/* `ARM64_SIM_L_MEM_PRE` / `ARM64_SIM_L_MEM_POST` writeback. */
static void model_writeback(unsigned base, __s64 imm)
{
	if (base == ARM64_SP)
		msp += imm;
	else
		mreg[base] = mreg[base] + (__u64)imm;
}

/* `ARM64_SIM_L_WRITE_REG_WIDTH`, restated against the model register file. */
static void model_write_reg_width(unsigned reg, __u64 value, unsigned width)
{
	__u64 next = KPROG_ARM64_APPLY_WIDTH(value, width);

	if (reg == ARM64_SP) {
		msp = (__s64)next;
	} else if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		if (width == ARM64_WIDTH_32)
			mreg[reg] = (__u32)next;
		else
			mreg[reg] = next;
		mtag[reg] = ARM64_SIM_TAG_SCALAR;
	}
}

/* `ARM64_SIM_L_WRITE_REG_PTR_TAG`, restated against the model register file. */
static void model_write_reg_ptr_tag(unsigned reg, __u64 value, __u8 tag)
{
	if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		mreg[reg] = value;
		mtag[reg] = tag;
	}
}

/* The shared `ARM64_SIM_L_DQ_MEM_STEP` body, with direction, lane count and
 * lane plan restated from the generated per-opcode constants. */
static void model_dq(unsigned op, unsigned base, unsigned index, unsigned aux,
		     __s64 imm, __u64 *v0, __u64 *v0_hi)
{
	unsigned idx = KPROG_ARM64_DQ_MEM_INDEX(op);
	unsigned access;
	unsigned lanes;

	if (idx == KPROG_ARM64_DQ_MEM_OP_LOAD_D0_INDEX) {
		access = KPROG_ARM64_DQ_MEM_OP_LOAD_D0_ACCESS;
		lanes = KPROG_ARM64_DQ_MEM_OP_LOAD_D0_LANES;
	} else if (idx == KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_INDEX) {
		access = KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_ACCESS;
		lanes = KPROG_ARM64_DQ_MEM_OP_LOAD_Q0_LANES;
	} else if (idx == KPROG_ARM64_DQ_MEM_OP_STORE_D0_INDEX) {
		access = KPROG_ARM64_DQ_MEM_OP_STORE_D0_ACCESS;
		lanes = KPROG_ARM64_DQ_MEM_OP_STORE_D0_LANES;
	} else {
		access = KPROG_ARM64_DQ_MEM_OP_STORE_Q0_ACCESS;
		lanes = KPROG_ARM64_DQ_MEM_OP_STORE_Q0_LANES;
	}

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
		model_writeback(base, imm);
	if (access == KPROG_ARM64_DQ_MEM_ACCESS_LOAD) {
		*v0 = model_mem_read(base, index, aux, imm, 0,
				     KPROG_ARM64_DQ_MEM_LANE_STRIDE);
		if (lanes > 1U)
			*v0_hi = model_mem_read(base, index, aux, imm,
				KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE,
				KPROG_ARM64_DQ_MEM_LANE_STRIDE);
	} else {
		model_mem_write(base, index, aux, imm, 0,
				KPROG_ARM64_DQ_MEM_LANE_STRIDE, *v0,
				ARM64_SIM_TAG_SCALAR);
		if (lanes > 1U)
			model_mem_write(base, index, aux, imm,
				KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE,
				KPROG_ARM64_DQ_MEM_LANE_STRIDE, *v0_hi,
				ARM64_SIM_TAG_SCALAR);
	}
	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
		model_writeback(base, imm);
}

/* The shared `ARM64_SIM_L_PAIR_MEM_STEP` body, with direction, slot count and
 * slot stride restated from the generated per-opcode constants and the
 * caller's access width. */
static void model_pair(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned base, unsigned index, unsigned aux, __s64 imm,
		       unsigned width)
{
	unsigned access = KPROG_ARM64_PAIR_MEM_INDEX(op) ==
				  KPROG_ARM64_PAIR_MEM_OP_LDP_INDEX
			  ? KPROG_ARM64_PAIR_MEM_OP_LDP_ACCESS
			  : KPROG_ARM64_PAIR_MEM_OP_STP_ACCESS;
	unsigned slots = KPROG_ARM64_PAIR_MEM_SLOT_COUNT;
	unsigned hi = width;

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
		model_writeback(base, imm);

	if (access == KPROG_ARM64_PAIR_MEM_ACCESS_LOAD) {
		__u64 v0 = model_mem_read(base, index, aux, imm, 0, width);
		__u64 v1 = slots > 1U
			   ? model_mem_read(base, index, aux, imm, hi, width)
			   : 0;
		__u8 t0 = model_mem_read_tag(base, index, aux, imm, 0, width);
		__u8 t1 = slots > 1U
			  ? model_mem_read_tag(base, index, aux, imm, hi, width)
			  : 0;
		__u64 mask = KPROG_ARM64_PAIR_LOAD_TAG_ROUTE(op, t0, t1, width,
							    model_unsupported());

		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_LOW(mask))
			model_write_reg_ptr_tag(dst, v0, t0);
		else
			model_write_reg_width(dst, v0, width);
		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_HIGH(mask))
			model_write_reg_ptr_tag(src, v1, t1);
		else
			model_write_reg_width(src, v1, width);
	} else {
		model_mem_write(base, index, aux, imm, 0, width,
				m_base_val(src), m_base_tag(src));
		if (slots > 1U)
			model_mem_write(base, index, aux, imm, hi, width,
					m_base_val(src2), m_base_tag(src2));
	}

	if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
		model_writeback(base, imm);
}

/* ------------------------------------------------------------------ */
/* The independent arm model.                                          */
/* ------------------------------------------------------------------ */

/* One dispatcher arm of `ARM64_SIM_L_EXEC`, restated over the model state.
 * Every arm this oracle drives is total over its operands at the values the
 * oracle plants, so the model's unsupported hook must stay untouched. */
static void model_exec(unsigned op, unsigned dst, unsigned src, unsigned src2,
		       unsigned src3, unsigned width, __u32 aux, __s64 imm)
{
	switch (op) {
	case ARM64_OP_NOP:
		break;
	case ARM64_OP_MOVK:
		model_write_reg_width(dst,
			KPROG_ARM64_MOVK_INSERT(m_reg(dst), (__u64)imm,
						KPROG_ARM64_AUX_B2(aux),
						model_unsupported()),
			width);
		break;
	case ARM64_OP_BITFIELD:
		model_write_reg_width(dst,
			KPROG_ARM64_BITFIELD_VALUE(
				KPROG_ARM64_AUX_B0(aux), m_reg(src),
				m_reg(dst), KPROG_ARM64_AUX_B1(aux),
				KPROG_ARM64_AUX_B2(aux), model_unsupported()),
			width);
		break;
	case ARM64_OP_CMN_IMM:
		KPROG_ARM64_SET_ADD_FLAGS(m_n, m_z, m_c, m_v, m_reg(dst),
					  (__u64)imm, width);
		break;
	case ARM64_OP_CMN_REG:
		KPROG_ARM64_SET_ADD_FLAGS(m_n, m_z, m_c, m_v, m_reg(dst),
			KPROG_ARM64_MOD_VALUE(KPROG_ARM64_AUX_B1(aux),
					      m_reg(src),
					      KPROG_ARM64_AUX_B2(aux),
					      width),
			width);
		break;
	case ARM64_OP_TST_BIC_REG: {
		__u64 rhs = KPROG_ARM64_MOD_VALUE(KPROG_ARM64_AUX_B1(aux),
						  m_reg(src),
						  KPROG_ARM64_AUX_B2(aux),
						  width);
		KPROG_ARM64_SET_LOGIC_FLAGS(m_n, m_z, m_c, m_v,
			KPROG_ALU64_RESULT(ARM64_ALU_BIC, m_reg(dst), rhs,
					   model_unsupported()),
			width);
		break;
	}
	case ARM64_OP_BICS_REG: {
		__u64 rhs = KPROG_ARM64_MOD_VALUE(KPROG_ARM64_AUX_B1(aux),
						  m_reg(src2),
						  KPROG_ARM64_AUX_B2(aux),
						  width);
		__u64 value = KPROG_ALU64_RESULT(ARM64_ALU_BIC, m_reg(src),
						 rhs, model_unsupported());

		KPROG_ARM64_SET_LOGIC_FLAGS(m_n, m_z, m_c, m_v, value, width);
		model_write_reg_width(dst, value, width);
		break;
	}
	case ARM64_OP_LOAD: {
		__u64 value;
		__u8 tag;

		if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
			model_writeback(src, imm);
		value = model_mem_read(src, src2, aux, imm, 0, width);
		tag = model_mem_read_tag(src, src2, aux, imm, 0, width);
		if (KPROG_ARM64_LOAD_TAG_PRESERVE(op, tag, width,
						  model_unsupported()))
			model_write_reg_ptr_tag(dst, value, tag);
		else
			model_write_reg_width(dst, value, width);
		if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
			model_writeback(src, imm);
		break;
	}
	case ARM64_OP_STORE:
		if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_PRE)
			model_writeback(dst, imm);
		model_mem_write(dst, src2, aux, imm, 0, width, m_reg(src),
				m_rtag(src));
		if (ARM64_SIM_L_MEM_FLAGS(aux) & ARM64_MEM_POST)
			model_writeback(dst, imm);
		break;
	case ARM64_OP_LDP:
		model_pair(op, dst, src, ARM64_REG_NONE, src2, src3, aux, imm,
			   width);
		break;
	case ARM64_OP_STP:
		model_pair(op, ARM64_REG_NONE, src, src2, dst, src3, aux, imm,
			   width);
		break;
	case ARM64_OP_LOAD_D0:
	case ARM64_OP_LOAD_Q0:
		model_dq(op, src, src2, aux, imm, &m_v0, &m_v0_hi);
		break;
	case ARM64_OP_STORE_D0:
	case ARM64_OP_STORE_Q0:
		model_dq(op, dst, src2, aux, imm, &m_v0, &m_v0_hi);
		break;
	case ARM64_OP_FMOV: {
		__u64 result = KPROG_ARM64_FMOV_VALUE(aux, m_v0, m_reg(src),
						      model_unsupported());

		if (KPROG_ARM64_FMOV_DEST_VECTOR(aux, model_unsupported()))
			m_v0 = result;
		else
			model_write_reg_width(dst, result, width);
		break;
	}
	default:
		model_unsupported();
		break;
	}
	(void)src3;
}

/* ------------------------------------------------------------------ */
/* The checker.                                                        */
/* ------------------------------------------------------------------ */

/* Plant the simulator and model register files, flags, SIMD quarters and both
 * memory images with the identical pattern, and anchor the shared base, index
 * and value registers. Written as a macro so it expands in the checker's own
 * state scope. */
#define PLANT_ALL()                                                        \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = STACK_BASE_VAL;                                \
		msp = STACK_BASE_VAL;                                     \
		__a64_v0 = pattern_reg(40);                               \
		m_v0 = __a64_v0;                                          \
		__a64_v0_hi = pattern_reg(41);                            \
		m_v0_hi = __a64_v0_hi;                                    \
		__a64_n = m_n = 1;                                        \
		__a64_z = m_z = 1;                                        \
		__a64_c = m_c = 1;                                        \
		__a64_v = m_v = 1;                                        \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X5),                 \
			(void *)(long)INDEX_VALUE, ARM64_SIM_TAG_SCALAR);  \
		mreg[ARM64_X5] = INDEX_VALUE;                             \
		mtag[ARM64_X5] = ARM64_SIM_TAG_SCALAR;                    \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X6),                 \
			(void *)(long)(heap + SCALAR_BASE_OFF),            \
			ARM64_SIM_TAG_SCALAR);                             \
		mreg[ARM64_X6] = (__u64)(long)(heap + SCALAR_BASE_OFF);   \
		mtag[ARM64_X6] = ARM64_SIM_TAG_SCALAR;                    \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X7),                 \
			(void *)(long)STACK_BASE_VAL, ARM64_SIM_TAG_STACK);\
		mreg[ARM64_X7] = (__u64)STACK_BASE_VAL;                   \
		mtag[ARM64_X7] = ARM64_SIM_TAG_STACK;                     \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X8),                 \
			(void *)(long)(heap + ABI_BASE_OFF),               \
			ARM64_SIM_TAG_ABI);                                \
		mreg[ARM64_X8] = (__u64)(long)(heap + ABI_BASE_OFF);      \
		mtag[ARM64_X8] = ARM64_SIM_TAG_ABI;                       \
		for (__pl_i = 0; __pl_i < HEAP_BYTES; __pl_i++) {         \
			heap[__pl_i] = heap_img[__pl_i];                  \
			heap_exp[__pl_i] = heap_img[__pl_i];              \
		}                                                         \
		for (__pl_i = 0; __pl_i < STACK_BYTES; __pl_i++) {        \
			__a64_stack.b[__pl_i] = stk_img[__pl_i];          \
			stk_exp[__pl_i] = stk_img[__pl_i];                \
		}                                                         \
		for (__pl_i = 0; __pl_i < STACK_SLOTS; __pl_i++) {        \
			__a64_stack_tag[__pl_i] = stk_tag_img[__pl_i];    \
			stk_tag_exp[__pl_i] = stk_tag_img[__pl_i];        \
		}                                                         \
	} while (0)

/* Compare the whole simulator state against the model image. */
#define COMPARE_STATE(NAME, OP, WIDTH, AUX, IMM)                           \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH %s op=%#x width=%u aux=%#x " \
				       "imm=%lld reg%u: got 0x%llx want "     \
				       "0x%llx\n", (NAME), (OP), (WIDTH),     \
				       (AUX), (long long)(IMM),               \
				       (unsigned)__cs_i,                      \
				       (unsigned long long)__cs_got,          \
				       (unsigned long long)mreg[__cs_i]);     \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH %s op=%#x reg%u tag: got "   \
				       "%u want %u\n", (NAME), (OP),          \
				       (unsigned)__cs_i, __cs_tag,            \
				       mtag[__cs_i]);                         \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH %s op=%#x sp: got %lld want %lld\n",\
			       (NAME), (OP), (long long)__a64_sp,          \
			       (long long)msp);                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_v0 != m_v0 || __a64_v0_hi != m_v0_hi) {         \
			printf("MISMATCH %s op=%#x v0: got 0x%llx/0x%llx "    \
			       "want 0x%llx/0x%llx\n", (NAME), (OP),         \
			       (unsigned long long)__a64_v0,                 \
			       (unsigned long long)__a64_v0_hi,              \
			       (unsigned long long)m_v0,                     \
			       (unsigned long long)m_v0_hi);                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_n != m_n || __a64_z != m_z || __a64_c != m_c || \
		    __a64_v != m_v) {                                     \
			printf("MISMATCH %s op=%#x flags %u%u%u%u/%u%u%u%u\n",\
			       (NAME), (OP), __a64_n, __a64_z, __a64_c,      \
			       __a64_v, m_n, m_z, m_c, m_v);                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (memcmp(heap, heap_exp, HEAP_BYTES) != 0 ||            \
		    memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0 ||   \
		    memcmp(__a64_stack_tag, stk_tag_exp, STACK_SLOTS) != 0) {\
			printf("MISMATCH %s op=%#x width=%u aux=%#x imm=%lld " \
			       "memory image\n", (NAME), (OP), (WIDTH),      \
			       (AUX), (long long)(IMM));                     \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* Drive one arm through the real dispatcher and compare the whole state to the
 * model's independent computation. `member` selects the expected unsupported
 * delta: 0 for a singleton opcode (its own arm), 1 for a non-member. */
static void run_case(unsigned op, unsigned dst, unsigned src, unsigned src2,
		     unsigned src3, unsigned width, __u32 aux, __s64 imm,
		     int member, const char *name)
{
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;

	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_lr;

	PLANT_ALL();

	model_exec(op, dst, src, src2, src3, width, aux, imm);
	ARM64_SIM_L_EXEC(op, dst, src, src2, src3, width, aux, imm);

	cases++;
	if (member) {
		if (unsupported_calls != u0) {
			printf("MISMATCH %s op=%#x width=%u reached the "
			       "unsupported arm\n", name, op, width);
			failures++;
		}
		cases++;
		if (model_unsupported_calls != mu0) {
			printf("MISMATCH %s op=%#x width=%u model took an "
			       "unsupported sub-contract arm\n", name, op,
			       width);
			failures++;
		}
	} else {
		if (unsupported_calls != u0 + 1UL) {
			printf("MISMATCH %s op=%#x width=%u unsupported delta=%lu"
			       "\n", name, op, width,
			       unsupported_calls - u0);
			failures++;
		}
	}

	COMPARE_STATE(name, op, width, aux, imm);
}

/* Drive one member of the memory family with the base/index/flags/immediate
 * combination the caller selected. */
static void run_mem_family(unsigned op, unsigned width, unsigned base,
			   unsigned flags, unsigned index, __s64 imm)
{
	__u32 aux = (__u32)ARM64_AUX_MEM(index, ARM64_MOD_NONE, 0U, flags);

	switch (op) {
	case ARM64_OP_LOAD:
		run_case(op, ARM64_X2, base, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "load");
		break;
	case ARM64_OP_STORE:
		run_case(op, base, ARM64_X2, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "store");
		break;
	case ARM64_OP_LDP:
		run_case(op, ARM64_X2, ARM64_X3, base, index, width, aux, imm,
			 1, "ldp");
		break;
	case ARM64_OP_STP:
		run_case(op, base, ARM64_X2, ARM64_X3, index, width, aux, imm,
			 1, "stp");
		break;
	case ARM64_OP_LOAD_D0:
		run_case(op, ARM64_X2, base, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "loadD0");
		break;
	case ARM64_OP_LOAD_Q0:
		run_case(op, ARM64_X2, base, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "loadQ0");
		break;
	case ARM64_OP_STORE_D0:
		run_case(op, base, ARM64_X2, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "storeD0");
		break;
	default: /* ARM64_OP_STORE_Q0 */
		run_case(op, base, ARM64_X2, index, ARM64_REG_NONE, width,
			 aux, imm, 1, "storeQ0");
		break;
	}
}

int main(void)
{
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const unsigned mem_ops[8] = {
		ARM64_OP_LOAD, ARM64_OP_STORE, ARM64_OP_LDP, ARM64_OP_STP,
		ARM64_OP_LOAD_D0, ARM64_OP_STORE_D0, ARM64_OP_LOAD_Q0,
		ARM64_OP_STORE_Q0,
	};
	static const unsigned bases[4] = {
		ARM64_X6, ARM64_X7, ARM64_X8, ARM64_SP,
	};
	static const unsigned flag_sets[4] = {
		0U,
		ARM64_MEM_PRE,
		ARM64_MEM_POST,
		ARM64_MEM_PRE | ARM64_MEM_POST,
	};
	static const unsigned index_regs[2] = {
		ARM64_REG_NONE, ARM64_X5,
	};
	static const __s64 imms[3] = { 0, 8, -8 };
	static const unsigned movk_shifts[4] = { 0U, 16U, 32U, 48U };
	static const unsigned bitfield_kinds[5] = {
		ARM64_BITFIELD_UBFX, ARM64_BITFIELD_SBFX, ARM64_BITFIELD_UBFIZ,
		ARM64_BITFIELD_BFXIL, ARM64_BITFIELD_BFI,
	};
	static const unsigned bitfield_fields[3][2] = {
		{ 0U, 8U }, { 4U, 16U }, { 8U, 32U },
	};
	static const unsigned src_mods[3] = {
		ARM64_MOD_NONE, ARM64_MOD_LSL, ARM64_MOD_ASR,
	};
	static const unsigned fmov_dirs[4] = {
		ARM64_FMOV_D_FROM_X, ARM64_FMOV_X_FROM_D,
		ARM64_FMOV_S_FROM_W, ARM64_FMOV_W_FROM_S,
	};
	unsigned i;
	unsigned k;
	unsigned o;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	for (k = 0; k < sizeof(widths) / sizeof(widths[0]); k++) {
		__u8 width = (__u8)widths[k];

		/* NOP: no arm writes anything, the whole state must be the
		 * planted one. */
		run_case(ARM64_OP_NOP, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_X4, width, 0U, 0, 1, "nop");

		/* MOVK: every architectural column, inserting a nonzero
		 * immediate into a nonzero destination. */
		for (i = 0; i < 4U; i++)
			run_case(ARM64_OP_MOVK, ARM64_X2, ARM64_X1, ARM64_X3,
				 ARM64_X4, width,
				 (__u32)ARM64_AUX_MOVK(movk_shifts[i]),
				 (__s64)0xbeef, 1, "movk");

		/* BITFIELD: every kind across three field placements. */
		for (i = 0; i < 5U; i++)
			for (k = 0; k < 3U; k++)
				run_case(ARM64_OP_BITFIELD, ARM64_X2, ARM64_X1,
					 ARM64_X3, ARM64_X4, width,
					 (__u32)ARM64_AUX_BITFIELD(
						 bitfield_kinds[i],
						 bitfield_fields[k][0],
						 bitfield_fields[k][1]),
					 0, 1, "bitfield");

		/* CMN_IMM: flags only, immediate rhs. */
		run_case(ARM64_OP_CMN_IMM, ARM64_X2, ARM64_X1, ARM64_X3,
			 ARM64_X4, width, 0U, (__s64)0x1234, 1, "cmnImm");

		/* CMN_REG / TST_BIC_REG / BICS_REG: the register rhs through
		 * the source modifier. */
		for (i = 0; i < 3U; i++) {
			__u32 aux = (__u32)ARM64_AUX(0U, src_mods[i], 3U);

			run_case(ARM64_OP_CMN_REG, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, aux, 0, 1,
				 "cmnReg");
			run_case(ARM64_OP_TST_BIC_REG, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, aux, 0, 1,
				 "tstBicReg");
			run_case(ARM64_OP_BICS_REG, ARM64_X2, ARM64_X1,
				 ARM64_X3, ARM64_X4, width, aux, 0, 1,
				 "bicsReg");
		}

		/* FMOV: all four directions. AUX carries the raw direction
		 * code, exactly as the dispatcher passes it. */
		for (i = 0; i < 4U; i++)
			run_case(ARM64_OP_FMOV, ARM64_X2, ARM64_X1, ARM64_X3,
				 ARM64_X4, width, fmov_dirs[i], 0, 1, "fmov");

		/* The memory family: every opcode across the base register,
		 * writeback flag pair, index presence and immediate. */
		for (o = 0; o < 8U; o++)
			for (i = 0; i < 4U; i++)
				for (k = 0; k < 4U; k++)
					run_mem_family(mem_ops[o], width,
						       bases[i], flag_sets[k],
						       index_regs[
							       (o + k) & 1U],
						       imms[(i + o) % 3U]);

		/* A non-member opcode must reach the unsupported arm exactly
		 * once and leave the state unchanged. */
		run_case(ARM64_OP_RET, ARM64_X2, ARM64_X1, ARM64_X3, ARM64_X4,
			 width, 0U, 0, 0, "nonmember");
	}

	if (failures != 0) {
		printf("arm64 dispatch singleton route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 dispatch singleton route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
