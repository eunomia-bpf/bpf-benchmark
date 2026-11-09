/*
 * Host cross-check for the x86 simulator's routing of the shared
 * `CMP_MEM` / `TEST_MEM` (and the register-form siblings) handler-composition
 * contract.
 *
 * The four memory-form `CMP` / `TEST` opcodes previously restated their own
 * left-hand-side load, right-hand-side selection, displacement form and flag
 * production inline; they now all expand the one machine-checked
 * `X86_SIM_L_EXEC_CMP_STEP` contract, selected by
 * `KPROG_X86_CMPOP_{LHS_SOURCE,DISP_KIND,RHS_SOURCE,FLAG_KIND,WRITE_WIDTH}`.
 *
 * This oracle drives the real routed bodies (`X86_SIM_L_EXEC_CMP_MEM`, and the
 * dispatcher's `X86_SIM_L_EXEC` arm) over a modelled register file, stack and
 * heap and compares the whole post-state against an independent model of the
 * contract that shares no code with the simulator: the width mask/bits, the
 * immediate widening, the two displacement forms, the memory load and the flag
 * production are all restated from the raw opcode and width codes.
 *
 * Build:
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_cmp_mem_route_host.c -o build/test_x86_cmp_mem_route_host
 * Run:
 *   ./build/test_x86_cmp_mem_route_host
 */
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"
#include "x86_no_helpers_host.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* The value planted into the heap for the ABI pointer-load arm; a distinct
 * pattern keeps a misclassified arm numerically observable. */
static __u64 abi_ptr_value;

/* The heap sits at a fixed origin inside a larger array so a negative
 * displacement still lands inside the modeled bytes. */
#define HEAP_ORIGIN 32

static __u8 heap[64] __attribute__((aligned(8)));
static __u8 exp_heap[64];
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* Independent little-endian width load, written as an explicit byte loop so it
 * never leans on the simulator's memory or stack macro. */
static __u64 load_le(const __u8 *b, __s64 off, __u8 width)
{
	unsigned n = width == X86_WIDTH_8 ? 1U :
		     width == X86_WIDTH_16 ? 2U :
		     width == X86_WIDTH_32 ? 4U : 8U;
	__u64 v = 0;
	unsigned k;

	for (k = 0; k < n; k++)
		v |= (__u64)b[off + (__s64)k] << (8U * k);
	return v;
}

/* Independent restatement of the width-aware immediate rule: the low 32 bits,
 * sign-extended only under the 64-bit width. */
static __u64 model_imm(__u64 v, __u8 width)
{
	if (width == X86_WIDTH_64 && (v & 0x80000000ULL) != 0ULL)
		return (v & 0xffffffffULL) | 0xffffffff00000000ULL;
	return v & 0xffffffffULL;
}

/* The displacement form: the register-RHS memory opcode (`CMP_MEM_REG`) takes
 * the whole immediate as a signed displacement, the other three take the high
 * 32 bits as a store displacement. Restated from the raw opcode codes. */
static __s64 disp_of(__u8 op, __u64 imm)
{
	return op == X86_OP_CMP_MEM_REG ? (__s64)imm
					: (__s64)(__s32)(imm >> 32);
}

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

/* The width mask and bit count, restated from the raw codes rather than taken
 * from the generated x86_width.h. */
static __u64 model_mask(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

static unsigned model_bits(__u8 width)
{
	if (width == X86_WIDTH_8)
		return 8U;
	if (width == X86_WIDTH_16)
		return 16U;
	if (width == X86_WIDTH_32)
		return 32U;
	return 64U;
}

/* The zero-borrow subtraction the `CMP` opcodes write, restated from the raw
 * codes. */
static void model_sub_flags(__u64 lhs, __u64 rhs, __u8 width,
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
static void model_logic_flags(__u64 lhs, __u64 rhs, __u8 width,
			      __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u64 value = (lhs & rhs) & model_mask(width);

	*cf = 0U;
	*zf = (__u8)(value == 0);
	*sf = (__u8)((value >> (model_bits(width) - 1U)) & 1U);
	*of = 0U;
}

/*
 * Run one memory-form compare/test body over the modelled state and compare
 * the whole post-state against the independent model.
 *
 * `op` is one of `X86_OP_CMP_MEM_IMM` / `TEST_MEM_IMM` / `CMP_MEM_REG` /
 * `TEST_MEM_REG`; `flags` is the opcode's FLAGS width code; `base_reg` is the
 * register the addressed memory operand is based on (`X86_RSP` -> the modeled
 * stack, otherwise the pointer planted in the register); `base_tag` is the
 * provenance tag planted with that pointer; `src_reg` is the register the
 * `_REG` forms read their right-hand side from; `index_reg`/`index_val`/
 * `scale_log2` describe the addressing index; `src_val` is the plant value of
 * the source register; `imm` is the opcode immediate; `via_dispatch` is true
 * to drive the `X86_SIM_L_EXEC` arm instead of the body directly.
 */
static void check_mem(const char *what, __u8 op, __u8 flags, __u8 base_reg,
		      __u8 base_tag, __u8 src_reg, __u8 index_reg,
		      __u64 index_val, __u8 scale_log2, __u64 src_val,
		      __u64 imm, int via_dispatch)
{
	__u8 width = flags ? flags : X86_WIDTH_64;
	unsigned is_test = (op == X86_OP_TEST_MEM_IMM ||
			    op == X86_OP_TEST_MEM_REG);
	unsigned is_reg = (op == X86_OP_CMP_MEM_REG ||
			   op == X86_OP_TEST_MEM_REG);
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U);
	__s64 disp, off;
	__u64 lhs, rhs;
	__u8 mcf, mzf, msf, mof;
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xa0U + i);

	/* Plant the modelled operands. The ABI arm dereferences the addressed
	 * word as a pointer, so both candidate displacements name a planted
	 * slot, and the register plant comes after the pattern fill so it is
	 * never clobbered. */
	if (base_tag == X86_SIM_TAG_ABI) {
		*(void **)(void *)(heap + HEAP_ORIGIN) =
			(void *)(long)abi_ptr_value;
		*(void **)(void *)(heap + HEAP_ORIGIN + 8) =
			(void *)(long)abi_ptr_value;
	}
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	if (is_reg)
		X86_SIM_L_WRITE_REG_WIDTH(src_reg, src_val, X86_WIDTH_64);
	if (base_reg != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(base_reg, heap + HEAP_ORIGIN,
					    base_tag);

    if (base_reg == X86_RSP) __x86_rsp.ptr = (void *)(long)-(__s64)X86_SIM_STACK_BYTES;
	/* ---- independent model ---- */
	disp = disp_of(op, imm);
	off = disp;
	if (index_reg != X86_REG_NONE)
		off += (__s64)(index_val << scale_log2);

	for (i = 0; i < sizeof(heap); i++)
		exp_heap[i] = heap[i];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp_stack[i] = __x86_stack_mem.b[i];
	for (i = 0; i < 16U; i++) {
		mreg[i] = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		mtag[i] = X86_SIM_L_REG_TAG(i);
	}

	if (base_reg == X86_RSP) {
		/* The modeled RSP base pointer is null, so the stack index is
		 * just the signed offset shifted by the frame capacity. */
		__u32 stack_index =
			(__u32)((off + (__s64)X86_SIM_STACK_BYTES) & 0xffffffff);

		lhs = load_le(exp_stack, (__s64)stack_index, width);
	} else if (base_tag == X86_SIM_TAG_ABI && width == X86_WIDTH_64) {
		lhs = (__u64)(long)*(void **)(void *)
			(&exp_heap[HEAP_ORIGIN + off]);
	} else {
		lhs = load_le(exp_heap, (__s64)HEAP_ORIGIN + off, width);
	}

	rhs = is_reg ? src_val : model_imm(imm, width);
	if (is_test)
		model_logic_flags(lhs, rhs, width, &mcf, &mzf, &msf, &mof);
	else
		model_sub_flags(lhs, rhs, width, &mcf, &mzf, &msf, &mof);

    __u64 driven_imm = imm;
    if (base_reg == X86_RSP)
        driven_imm = op == X86_OP_CMP_MEM_REG ? imm + X86_SIM_STACK_BYTES :
            (__u32)imm | ((__u64)(__u32)(__s32)(disp + X86_SIM_STACK_BYTES) << 32);
	/* ---- run the real body ---- */
	if (via_dispatch)
		X86_SIM_L_EXEC(op, base_reg, src_reg, flags, aux, driven_imm);
	else
		X86_SIM_L_EXEC_CMP_MEM(op, base_reg, src_reg, flags, aux, driven_imm);

	/* ---- compare the whole modeled state: no register or memory write ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH %s op=0x%02x flags=%u reg%u: "
			       "got 0x%llx want 0x%llx\n",
			       what, op, flags, i, (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH %s op=0x%02x flags=%u reg%u tag: "
			       "got %u want %u\n",
			       what, op, flags, i, got_tag, mtag[i]);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s op=0x%02x heap[%u]=0x%02x "
			       "want=0x%02x (disp=%lld off=%lld)\n",
			       what, op, i, heap[i], exp_heap[i],
			       (long long)disp, (long long)off);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s op=0x%02x stack[%u]=0x%02x "
			       "want=0x%02x (disp=%lld off=%lld)\n",
			       what, op, i, __x86_stack_mem.b[i],
			       exp_stack[i], (long long)disp, (long long)off);
			failures++;
			return;
		}
	}

	/* ---- compare the flags: all four are written ---- */
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH %s op=0x%02x flags=%u: got cf=%u zf=%u sf=%u "
		       "of=%u want cf=%u zf=%u sf=%u of=%u "
		       "(lhs=0x%llx rhs=0x%llx width=%u)\n",
		       what, op, flags, __x86_cf, __x86_zf, __x86_sf,
		       __x86_of, mcf, mzf, msf, mof,
		       (unsigned long long)lhs, (unsigned long long)rhs, width);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_CMPOP_LHS_SOURCE(0U) != KPROG_X86_CMPOP_LHS_REGISTER ||
	    KPROG_X86_CMPOP_LHS_SOURCE(1U) != KPROG_X86_CMPOP_LHS_MEMORY) {
		printf("MISMATCH lhs source selector\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_DISP_KIND(0U) != KPROG_X86_CMPOP_DISP_STORE ||
	    KPROG_X86_CMPOP_DISP_KIND(1U) != KPROG_X86_CMPOP_DISP_SIMM) {
		printf("MISMATCH disp kind selector\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_OP_CMP_IMM_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_CMP_REG_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_TEST_REG_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_REGISTER ||
	    KPROG_X86_CMPOP_OP_CMP_MEM_IMM_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_MEMORY ||
	    KPROG_X86_CMPOP_OP_TEST_MEM_IMM_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_MEMORY ||
	    KPROG_X86_CMPOP_OP_CMP_MEM_REG_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_MEMORY ||
	    KPROG_X86_CMPOP_OP_TEST_MEM_REG_LHS_SOURCE !=
		    KPROG_X86_CMPOP_LHS_MEMORY) {
		printf("MISMATCH per-opcode lhs table\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMPOP_OP_CMP_MEM_IMM_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_STORE ||
	    KPROG_X86_CMPOP_OP_TEST_MEM_IMM_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_STORE ||
	    KPROG_X86_CMPOP_OP_TEST_MEM_REG_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_STORE ||
	    KPROG_X86_CMPOP_OP_CMP_MEM_REG_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_SIMM ||
	    KPROG_X86_CMPOP_OP_CMP_IMM_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_SIMM ||
	    KPROG_X86_CMPOP_OP_CMP_REG_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_SIMM ||
	    KPROG_X86_CMPOP_OP_TEST_IMM_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_SIMM ||
	    KPROG_X86_CMPOP_OP_TEST_REG_DISP_KIND !=
		    KPROG_X86_CMPOP_DISP_SIMM) {
		printf("MISMATCH per-opcode disp table\n");
		failures++;
	}
}


/* Complete numeric frames pin displacement asymmetry and all six flags. */
static __u64 compare_native_cell(const __u64 *r, const __u8 *tags, unsigned reg,
                                  __u64 arena, __u64 base)
{
    return reg == X86_RSP ? r[reg] + base :
        tags[reg] == X86_SIM_TAG_STACK ? r[reg] - arena + base : r[reg];
}

static void check_compare_frame(unsigned mode, unsigned flags, unsigned data_reg,
                                 unsigned base_kind, unsigned index_kind, unsigned scale,
                                 __u64 native_base, unsigned seed, unsigned fv, unsigned via)
{
    static const unsigned operations[] = {X86_OP_CMP_MEM_IMM, X86_OP_TEST_MEM_IMM,
        X86_OP_CMP_MEM_REG, X86_OP_TEST_MEM_REG, X86_OP_CMP_REG_MEM};
    static const __u32 low[] = {0U, 0x7fffffffU, 0x80000001U, 0xffffffffU};
    __u8 h[192], eh[192], es[X86_SIM_STACK_BYTES], tags[16], ef[6];
    __u64 r[16], arena, base, index, target, disp, encoded, sample, left, right, result, mask, sign;
    unsigned width = flags ? flags : 8, bits = width * 8, i, bad, parity = 0;
    unsigned packed = mode != 2 && mode != 4, test = mode == 1 || mode == 3;
    unsigned br = base_kind == 0 ? X86_RSP : base_kind == 3 ? X86_REG_NONE : X86_RBP;
    unsigned ir = index_kind == 0 ? X86_REG_NONE : index_kind == 1 ? X86_RCX :
        index_kind == 2 ? (packed ? X86_RDX : X86_RSP) : X86_RBP;
    __u32 aux = ir | (scale << 8) | (0xd3U << 16) | (0x9aU << 24);
    __u8 *memory;
    X86_SIM_L_DECLARE_STATE();
    struct x86_sim_xdp_abi __x86_sim_abi = {};
    struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
    __u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
    X86_SIM_L_DECLARE_STACK();
    (void)__x86_sim_abi; (void)__x86_sim_skb_ctx; (void)__x86_sim_abi_kind;
    (void)__x86_sim_ret_addr; (void)__x86_sim_helper_abi_base;
    mask = width == 8 ? ~0ULL : (1ULL << bits) - 1; sign = 1ULL << (bits - 1);
    arena = (__u64)(unsigned long)&__x86_stack_mem.b[X86_SIM_STACK_BYTES];
    for (i = 0; i < X86_SIM_STACK_BYTES; i++) es[i] = __x86_stack_mem.b[i] = (__u8)(i * 37 + 11);
    for (i = 0; i < sizeof(h); i++) eh[i] = h[i] = (__u8)(i * 19 + 0xa7);
    for (i = 0; i < 16; i++) {r[i] = 0x123456789abcdef0ULL + i * 0x10101; tags[i] = X86_SIM_TAG_SCALAR;}
    r[X86_RSP] = (__u64)-32; r[X86_RCX] = 3; r[X86_RDX] = 5;
    r[X86_RBP] = base_kind == 2 ? arena - 40 : (__u64)(unsigned long)&h[48];
    tags[X86_RBP] = base_kind == 2 ? X86_SIM_TAG_STACK : X86_SIM_TAG_SCALAR;
    for (i = 0; i < 16; i++) X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(unsigned long)r[i], tags[i]);
    __x86_native_stack_base = native_base;
    for (i = 0; i < 6; i++) ef[i] = (fv >> i) & 1;
    __x86_cf = ef[0]; __x86_zf = ef[1]; __x86_sf = ef[2]; __x86_of = ef[3]; __x86_pf = ef[4]; __x86_af = ef[5];
    __x86_xmm0_lo = 0x12345678abcdef01ULL; __x86_xmm0_hi = 0xfedcba9876543210ULL;
    base = br == X86_REG_NONE ? 0 : r[br];
    index = ir == X86_REG_NONE ? 0 : compare_native_cell(r, tags, ir, arena, native_base);
    target = base_kind == 0 ? (__u64)-17 : base_kind == 2 ? arena - 17 : (__u64)(unsigned long)&h[97];
    disp = target - base - (ir == X86_REG_NONE ? 0 : index << scale);
    encoded = packed ? ((__u64)(__u32)disp << 32) | low[seed & 3] : disp;
    if (packed && (__u64)(__s64)(__s32)(encoded >> 32) != disp) {
        printf("MISMATCH compare fixture signed32 displacement\n"); failures++; return;
    }
    right = mode < 2 ? low[seed & 3] : compare_native_cell(r, tags, data_reg, arena, native_base);
    if (mode < 2 && width == 8 && (right & 0x80000000ULL)) right |= 0xffffffff00000000ULL;
    sample = seed == 0 ? 0 : seed == 1 ? 1 : seed == 2 ? ~0ULL : seed == 3 ? sign - 1 :
        seed == 4 ? sign : seed == 5 ? 0xf : seed == 6 ? 0x10 : right;
    memory = base_kind == 0 || base_kind == 2 ? &es[X86_SIM_STACK_BYTES - 17] : &eh[97];
    for (i = 0; i < width; i++) memory[i] = (__u8)(sample >> (i * 8));
    if (base_kind == 0 || base_kind == 2)
        for (i = 0; i < width; i++) __x86_stack_mem.b[X86_SIM_STACK_BYTES - 17 + i] = memory[i];
    else for (i = 0; i < width; i++) h[97 + i] = memory[i];
    left = sample & mask; right &= mask;
    if (mode == 4) {__u64 saved = left; left = right; right = saved;}
    result = test ? (left & right) : (left - right) & mask;
    ef[0] = test ? 0 : left < right;
    ef[1] = result == 0; ef[2] = (result & sign) != 0;
    ef[3] = test ? 0 : ((left ^ right) & (left ^ result) & sign) != 0;
    if (!test) ef[5] = ((left ^ right ^ result) >> 4) & 1;
    for (i = 0; i < 8; i++) parity ^= (result >> i) & 1;
    ef[4] = !parity;
    if (via) X86_SIM_L_EXEC(operations[mode], mode == 4 ? data_reg : br,
        mode == 4 ? br : data_reg, flags, aux, encoded);
    else if (mode == 4) X86_SIM_L_EXEC_CMP_REG_MEM(data_reg, br, flags, aux, encoded);
    else X86_SIM_L_EXEC_CMP_MEM(operations[mode], br, data_reg, flags, aux, encoded);
    bad = memcmp(h, eh, sizeof(h)) != 0;
    for (i = 0; i < X86_SIM_STACK_BYTES; i++) bad |= es[i] != __x86_stack_mem.b[i];
    cases++;
    if (bad) {printf("MISMATCH compare preserved memory\n"); failures++; return;}
    for (i = 0; i < 16; i++) {
        cases += 2;
        if ((__u64)(unsigned long)X86_SIM_L_REG_VALUE(i) != r[i] || X86_SIM_L_REG_TAG(i) != tags[i]) {
            printf("MISMATCH compare preserved reg%u\n", i); failures++; return;
        }
    }
    cases++;
    if (__x86_cf != ef[0] || __x86_zf != ef[1] || __x86_sf != ef[2] || __x86_of != ef[3] || __x86_pf != ef[4] || __x86_af != ef[5] ||
        __x86_xmm0_lo != 0x12345678abcdef01ULL || __x86_xmm0_hi != 0xfedcba9876543210ULL) {
        printf("MISMATCH compare flags/vector mode=%u width=%u reg=%u seed=%u flags=%u\n", mode, width, data_reg, seed, fv); failures++;
    }
}

static void check_compare_frames(void)
{
    static const unsigned widths[] = {0, 1, 2, 4, 8}, regs[] = {0, 4, 5, 15};
    static const __u64 bases[] = {0, 0x7fffffffef91ULL, 0xfffffffffffffff9ULL};
    unsigned wi, mode, reg, bk, ik, sc, bi, via, seed, fv, whole;
    for (wi = 0; wi < 5; wi++) for (mode = 0; mode < 5; mode++) {
        whole = mode == 2 || mode == 4;
        for (reg = 0; reg < 16; reg++) for (bk = 0; bk < (whole ? 4U : 3U); bk++)
        for (ik = 0; ik < (whole ? 4U : 3U); ik++) for (sc = 0; sc < 4; sc++)
        for (bi = 0; bi < 3; bi++) for (via = 0; via < 2; via++) for (seed = 0; seed < 4; seed++)
            check_compare_frame(mode, widths[wi], reg, bk, ik, sc, bases[bi], seed, (seed * 13) & 63, via);
    }
    for (wi = 0; wi < 5; wi++) for (mode = 0; mode < 5; mode++) for (reg = 0; reg < 4; reg++)
    for (bk = 0; bk < 2; bk++) for (via = 0; via < 2; via++) for (seed = 0; seed < 8; seed++) for (fv = 0; fv < 64; fv++)
        check_compare_frame(mode, widths[wi], regs[reg], bk, 0, 0, bases[2], seed, fv, via);
}

int main(void)
{
	static const __u8 mem_ops[4] = { X86_OP_CMP_MEM_IMM, X86_OP_TEST_MEM_IMM,
					 X86_OP_CMP_MEM_REG, X86_OP_TEST_MEM_REG };
	static const __u8 widths[4] = { X86_WIDTH_8, X86_WIDTH_16,
					X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 scales[4] = { 0, 1, 2, 3 };
	unsigned i, j;

	/* The immediate whose high 32 bits are zero but whose whole value is 8:
	 * the store-displacement forms read at offset 0, the register-RHS form
	 * (`CMP_MEM_REG`, whole immediate) at offset 8. The heap bytes there
	 * differ, so a wrong displacement form reads the wrong byte. */
	const __u64 twin_imm = 8ULL;

	/* The immediate whose high half is -8 and whose whole value is -8: both
	 * displacement forms then agree, exercising the negative sign
	 * extension. */
	const __u64 neg_imm_store = ((__u64)0xfffffff8ULL << 32) | 0x00000011ULL;
	const __u64 neg_imm_whole = (__u64)(__s64)-8;

	fill_patterns();

	/* ---- stack arm: all four opcodes, every width, flat addressing ---- */
	for (i = 0; i < 4U; i++) {
		__u64 imm = mem_ops[i] == X86_OP_CMP_MEM_REG ?
			neg_imm_whole : neg_imm_store;

		for (j = 0; j < 4U; j++)
			check_mem("stack", mem_ops[i], widths[j], X86_RSP,
				  X86_SIM_TAG_SCALAR, X86_RCX, X86_REG_NONE,
				  0, 0, 0x1122334455667788ULL, imm, (int)(j & 1U));
	}

	/* ---- heap arm: the displacement-form discrimination, every width ---- */
	for (i = 0; i < 4U; i++) {
		for (j = 0; j < 4U; j++)
			check_mem("heap/disp", mem_ops[i], widths[j], X86_RAX,
				  X86_SIM_TAG_SCALAR, X86_RCX, X86_REG_NONE,
				  0, 0, 0x1122334455667788ULL, twin_imm, 0);
	}

	/* ---- heap arm: indexed addressing, every scale (width 32) ---- */
	for (i = 0; i < 4U; i++) {
		__u64 imm = mem_ops[i] == X86_OP_CMP_MEM_REG ?
			(__u64)(__s64)8 : twin_imm;

		for (j = 0; j < 4U; j++)
			check_mem("heap/index", mem_ops[i], X86_WIDTH_32, X86_RAX,
				  X86_SIM_TAG_SCALAR, X86_RCX, X86_RDI,
				  1ULL, scales[j], 0x0102030405060708ULL,
				  imm, 0);
	}

	/* ---- heap arm: 8-bit lane addressing stays in the heap ---- */
	for (i = 0; i < 4U; i++) {
		__u64 imm = mem_ops[i] == X86_OP_CMP_MEM_REG ?
			neg_imm_whole : neg_imm_store;

		check_mem("heap/neg", mem_ops[i], X86_WIDTH_64, X86_RAX,
			  X86_SIM_TAG_SCALAR, X86_RCX, X86_REG_NONE, 0, 0,
			  0xaabbccddeeff0011ULL, imm, 1);
	}

	/* ---- ABI pointer-load arm: tag ABI at the 64-bit width ---- */
	for (i = 0; i < 4U; i++) {
		__u64 imm = mem_ops[i] == X86_OP_CMP_MEM_REG ?
			(__u64)(__s64)8 : twin_imm;

		abi_ptr_value = 0xdeadbeefcafef00dULL;
		check_mem("heap/abi", mem_ops[i], X86_WIDTH_64, X86_RBX,
			  X86_SIM_TAG_ABI, X86_RCX, X86_REG_NONE, 0, 0,
			  0x9988776655443322ULL, imm, (int)(i & 1U));
	}

	/* ---- register-RHS forms: whole 64-bit source read at every width ---- */
	for (i = 0; i < 2U; i++) {
		__u8 op = i == 0U ? X86_OP_CMP_MEM_REG : X86_OP_TEST_MEM_REG;

		for (j = 0; j < 4U; j++)
			check_mem("heap/reg-rhs", op, widths[j], X86_RAX,
				  X86_SIM_TAG_SCALAR, X86_R9, X86_REG_NONE,
				  0, 0, 0x1234567890abcdefULL, twin_imm, 0);
	}

	check_compare_frames();
	check_selectors();

	if (failures != 0) {
		printf("x86 cmp mem route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 cmp mem route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
