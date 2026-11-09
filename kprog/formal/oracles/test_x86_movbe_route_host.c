/*
 * Host cross-check for the x86 simulator's routing of the `MOVBE_LOAD` and
 * `MOVBE_STORE` handlers (`X86_SIM_L_EXEC_MOVBE_LOAD`,
 * `X86_SIM_L_EXEC_MOVBE_STORE`) through the generated `KPROG_X86_MOVBE_*`
 * contract.
 *
 * Both bodies formerly restated the contract inline — the width fallback and
 * (for the store) the stack-pointer arm selection. They now resolve those
 * through the machine-checked macros (`KPROG_X86_MOVBE_WIDTH` / `_DISP` /
 * `_ARM`), so the bodies and the Lean refinement share one MOVBE
 * implementation. This complements `test_x86_movbe_host.c`, which tests the
 * contract plus an independent model but never includes the simulator header.
 *
 * This oracle includes the *simulator* header (so the real macros are under
 * test). The store half drives the real body over every width, flat and
 * indexed addressing, and the stack and memory arms, and compares the *entire*
 * resulting modeled memory and stack against an independent byte model built
 * from the raw inputs. The load half drives the real body over every width,
 * both source arms, and checks the written destination register value and tag
 * against an independent byte model. It also checks the routed arm selector
 * and the resolved width directly. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_movbe_route_host.c -o /tmp/t_mbr && /tmp/t_mbr
 */
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"
#include "x86_no_helpers_host.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* Manual memory scenes use the raw host context profile. */
static const __u8 __x86_sim_abi_kind = X86_SIM_ABI_KIND_RAW;

/* Backing storage for the memory arm; a fixed pattern distinct from the
 * modeled stack keeps a misroute between the two arms observable. */
static __u8 heap[64];
static __u8 exp_heap[64];

static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* Independent little-endian width store, written as an explicit byte loop so it
 * never leans on the simulator's memory or stack macro. */
static void put_le(__u8 *b, __u64 v, __u8 width)
{
	unsigned i;

	if (!width)
		width = X86_WIDTH_64;
	for (i = 0; i < width; i++)
		b[i] = (__u8)(v >> (8 * i));
}

/* Independent byte reversal, written as an explicit loop: the low `width`
 * bytes are emitted most-significant first, so combined with the little-endian
 * memory access they land big-endian. */
static __u64 bswap_model(__u64 v, __u8 width)
{
	__u64 out = 0;
	unsigned i;

	if (!width)
		width = X86_WIDTH_64;
	for (i = 0; i < width; i++)
		out = (out << 8) | ((v >> (8 * i)) & 0xffU);
	return out;
}

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

/*
 * Store scenario. `dst` selects both the arm (RSP -> stack, other GPR ->
 * memory) and the memory-arm base pointer; `index_reg` (or X86_REG_NONE) and
 * `scale_log2` set the addressing mode; `src_reg` supplies the stored value
 * and `imm` the whole-field displacement.
 */
static void check_store(const char *what, __u8 dst, __u8 src_reg, __u8 flags,
			__u8 index_reg, __u64 index_val, __u8 scale_log2,
			__u64 src_val, __u64 imm)
{
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U);
	__u8 width;
	__s64 disp, off;
	__u64 value;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xa0U + i);

	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(src_reg, src_val, X86_WIDTH_64);

	if (dst != X86_REG_NONE && dst != X86_RSP) {
		/* The destination register holds the memory-arm base pointer. */
		X86_SIM_L_WRITE_REG_PTR_TAG(dst, heap, X86_SIM_TAG_SCALAR);
	}

	/* ---- independent model ---- */
	width = flags ? flags : X86_WIDTH_64;
	disp = (__s64)imm;
	value = bswap_model(src_val, width);
	off = disp;
	if (index_reg != X86_REG_NONE)
		off += (__s64)(index_val << scale_log2);

	for (i = 0; i < sizeof(heap); i++)
		exp_heap[i] = heap[i];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp_stack[i] = __x86_stack_mem.b[i];
	if (dst == X86_RSP) {
		__u32 stack_index =
			(__u32)((off + (__s64)X86_SIM_STACK_BYTES) & 0xffffffff);
		/* base_ptr is null for the modeled RSP, so OFF is just `off`. */
		put_le(&exp_stack[stack_index], value, width);
	} else {
		put_le(&exp_heap[(unsigned long)off], value, width);
	}

	/* ---- run the real body ---- */
	if (dst == X86_RSP) __x86_rsp.ptr = (void *)(long)-(__s64)X86_SIM_STACK_BYTES;
    X86_SIM_L_EXEC_MOVBE_STORE(dst, src_reg, flags, aux, imm + (dst == X86_RSP ? X86_SIM_STACK_BYTES : 0U));

	/* ---- compare the whole modeled state ---- */
	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(dst=%u width=%u disp=%lld off=%lld)\n",
			       what, i, heap[i], exp_heap[i], dst, width,
			       (long long)disp, (long long)off);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s stack[%u]=0x%02x want=0x%02x "
			       "(dst=%u width=%u disp=%lld off=%lld)\n",
			       what, i, __x86_stack_mem.b[i], exp_stack[i],
			       dst, width, (long long)disp, (long long)off);
			failures++;
			return;
		}
	}
}

/*
 * Load scenario. `src_reg` selects the arm (RSP -> stack read, other GPR ->
 * ordinary load); `dst` receives the byte-reversed value. The source bytes are
 * planted independently at the effective address, then the written register
 * value and tag are compared against the byte model.
 */
static void check_load(const char *what, __u8 dst, __u8 src_reg, __u8 flags,
		       __u8 index_reg, __u64 index_val, __u8 scale_log2,
		       __s64 disp, __u64 prior_dst)
{
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U);
	__u64 imm = (__u64)disp;
	__u8 width = flags ? flags : X86_WIDTH_64;
	__s64 off = disp;
	__u64 raw = 0, value, mask, expect, got;
	__u8 tag;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xa0U + i);
	if (index_reg != X86_REG_NONE) {
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
		off += (__s64)(index_val << scale_log2);
	}
	X86_SIM_L_WRITE_REG_WIDTH(dst, prior_dst, X86_WIDTH_64);
	if (src_reg != X86_REG_NONE && src_reg != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(src_reg, heap, X86_SIM_TAG_SCALAR);

	/* ---- plant the source bytes at the effective address ---- */
	if (src_reg == X86_RSP) {
		__u32 stack_index =
			(__u32)((off + (__s64)X86_SIM_STACK_BYTES) & 0xffffffff);
		for (i = 0; i < width; i++) {
			__u8 b = (__u8)(0x40U + i);
			__x86_stack_mem.b[stack_index + i] = b;
			raw |= (__u64)b << (8 * i);
		}
	} else {
		for (i = 0; i < width; i++) {
			__u8 b = (__u8)(0x40U + i);
			heap[off + i] = b;
			raw |= (__u64)b << (8 * i);
		}
	}

	/* ---- independent model of the writeback ---- */
	value = bswap_model(raw, width);
	/* Every width below 64 zero-extends the written value into the register;
	 * width 64 writes the full register. */
	mask = width == X86_WIDTH_64 ? ~0ULL : ((1ULL << (8 * width)) - 1);
	expect = width == X86_WIDTH_32 ? (value & mask)
				       : (prior_dst & ~mask) | (value & mask);

	/* ---- run the real body ---- */
	if (src_reg == X86_RSP) __x86_rsp.ptr = (void *)(long)-(__s64)X86_SIM_STACK_BYTES;
    X86_SIM_L_EXEC_MOVBE_LOAD(dst, src_reg, flags, aux, imm + (src_reg == X86_RSP ? X86_SIM_STACK_BYTES : 0U));

	got = X86_SIM_L_READ_REG_WIDTH_SHIFT(dst, X86_WIDTH_64, 0U);
	tag = X86_SIM_L_REG_TAG(dst);
	cases++;
	if (got != expect) {
		printf("MISMATCH %s reg=0x%llx want=0x%llx "
		       "(dst=%u src=%u width=%u off=%lld)\n",
		       what, (unsigned long long)got,
		       (unsigned long long)expect, dst, src_reg, width,
		       (long long)off);
		failures++;
	}
	cases++;
	if (tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH %s tag=%u want scalar (dst=%u)\n",
		       what, tag, dst);
		failures++;
	}
}

/* Numeric native observations are independent of the implementation readers. */
static __u64 native_cell(const __u64 *r, const __u8 *tags, unsigned reg,
                         __u64 arena, __u64 base)
{
	return reg == X86_RSP ? r[reg] + base :
		tags[reg] == X86_SIM_TAG_STACK ? r[reg] - arena + base : r[reg];
}

static void check_frame(unsigned store, unsigned flags, unsigned data_reg,
                        unsigned base_kind, unsigned index_kind, unsigned scale,
                        __u64 native_base, unsigned via)
{
	__u8 h[192], eh[192], es[X86_SIM_STACK_BYTES], tags[16];
	__u64 r[16], arena, base, index, target, disp, value = 0, old, mask;
	unsigned width = flags ? flags : 8, i, bad;
	unsigned br = base_kind == 0 ? X86_RSP : base_kind == 3 ? X86_REG_NONE : X86_RBP;
	unsigned ir = index_kind == 0 ? X86_REG_NONE : index_kind == 1 ? X86_RCX :
		index_kind == 2 ? X86_RSP : X86_RBP;
	__u32 aux = ir | (scale << 8) | (0xd3U << 16) | (0x9aU << 24);
	__u8 *memory;
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_sim_abi; (void)__x86_sim_skb_ctx; (void)__x86_sim_abi_kind;
	(void)__x86_sim_ret_addr; (void)__x86_sim_helper_abi_base;
	arena = (__u64)(unsigned long)&__x86_stack_mem.b[X86_SIM_STACK_BYTES];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) es[i] = __x86_stack_mem.b[i] = (__u8)(i * 37 + 11);
	for (i = 0; i < sizeof(h); i++) eh[i] = h[i] = (__u8)(i * 19 + 0xa7);
	for (i = 0; i < 16; i++) {
		r[i] = 0x123456789abcdef0ULL + i * 0x10101; tags[i] = X86_SIM_TAG_SCALAR;
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(unsigned long)r[i], tags[i]);
	}
	r[X86_RSP] = (__u64)-32; r[X86_RCX] = 3;
	r[X86_RBP] = base_kind == 2 ? arena - 40 : (__u64)(unsigned long)&h[48];
	tags[X86_RBP] = base_kind == 2 ? X86_SIM_TAG_STACK : X86_SIM_TAG_SCALAR;
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP, (void *)(unsigned long)r[X86_RSP], tags[X86_RSP]);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RCX, (void *)(unsigned long)r[X86_RCX], tags[X86_RCX]);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBP, (void *)(unsigned long)r[X86_RBP], tags[X86_RBP]);
	__x86_native_stack_base = native_base;
	__x86_cf = 1; __x86_zf = 0; __x86_sf = 1; __x86_of = 1; __x86_pf = 0; __x86_af = 1;
	__x86_xmm0_lo = 0x12345678abcdef01ULL; __x86_xmm0_hi = 0xfedcba9876543210ULL;
	base = br == X86_REG_NONE ? 0 : r[br];
	index = ir == X86_REG_NONE ? 0 : native_cell(r, tags, ir, arena, native_base);
	target = base_kind == 0 ? (__u64)-16 : base_kind == 2 ? arena - 16 : (__u64)(unsigned long)&h[96];
	disp = target - base - (ir == X86_REG_NONE ? 0 : index << scale);
	memory = base_kind == 0 || base_kind == 2 ? &es[X86_SIM_STACK_BYTES - 16] : &eh[96];
    __u64 prior_sp = r[X86_RSP];
	if (store) {
		value = native_cell(r, tags, data_reg, arena, native_base);
		for (i = 0; i < width; i++) memory[i] = (__u8)(value >> (8 * (width - i - 1)));
	} else {
		for (i = 0; i < width; i++) value = (value << 8) | memory[i];
		old = native_cell(r, tags, data_reg, arena, native_base);
		mask = width == 8 ? ~0ULL : (1ULL << (8 * width)) - 1;
		value = width == 4 ? value : (old & ~mask) | (value & mask);
		r[data_reg] = data_reg == X86_RSP ? value - native_base : value;
		tags[data_reg] = X86_SIM_TAG_SCALAR;
	}
    /* Native RSP writeback releases only this private interval. */
    if (!store && data_reg == X86_RSP && (__s64)r[X86_RSP] > (__s64)prior_sp)
        for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
            __s64 at = (__s64)i - (__s64)X86_SIM_STACK_BYTES;
            if (at >= (__s64)prior_sp && at < (__s64)r[X86_RSP]) es[i] = 0;
        }
	if (via)
		X86_SIM_L_EXEC(store ? X86_OP_MOVBE_STORE : X86_OP_MOVBE_LOAD,
			store ? br : data_reg, store ? data_reg : br, flags, aux, disp);
	else if (store) X86_SIM_L_EXEC_MOVBE_STORE(br, data_reg, flags, aux, disp);
	else X86_SIM_L_EXEC_MOVBE_LOAD(data_reg, br, flags, aux, disp);
	bad = memcmp(h, eh, sizeof(h)) != 0;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) bad |= es[i] != __x86_stack_mem.b[i];
	cases++;
	if (bad) { printf("MISMATCH MOVBE frame memory\n"); failures++; return; }
	for (i = 0; i < 16; i++) {
		cases += 2;
		if ((__u64)(unsigned long)X86_SIM_L_REG_VALUE(i) != r[i] || X86_SIM_L_REG_TAG(i) != tags[i]) {
			printf("MISMATCH MOVBE frame reg%u store=%u width=%u data=%u base=%u index=%u\n", i, store, width, data_reg, base_kind, index_kind);
			failures++; return;
		}
	}
	cases++;
	if (__x86_cf != 1 || __x86_zf != 0 || __x86_sf != 1 || __x86_of != 1 || __x86_pf != 0 || __x86_af != 1 ||
	    __x86_xmm0_lo != 0x12345678abcdef01ULL || __x86_xmm0_hi != 0xfedcba9876543210ULL) {
		printf("MISMATCH MOVBE frame flags/vector\n"); failures++;
	}
}

/* The routed arm selector must equal the contract's classification. */
static void check_source_macro(void)
{
	static const __u8 regs[] = { X86_RSP, X86_RAX, X86_RBX, X86_RDI,
				     X86_R15, X86_REG_NONE };
	unsigned i;

	for (i = 0; i < sizeof(regs) / sizeof(regs[0]); i++) {
		__u8 want = KPROG_X86_MOVBE_ARM(regs[i] == X86_RSP);

		cases++;
		if (X86_SIM_L_MEM_MOVBE_SRC(regs[i]) != want) {
			printf("MISMATCH movbe_src reg=%u got=%u want=%u\n",
			       regs[i], X86_SIM_L_MEM_MOVBE_SRC(regs[i]), want);
			failures++;
		}
		cases++;
		if ((regs[i] == X86_RSP) !=
		    (want == KPROG_X86_MOVBE_ARM_STACK)) {
			printf("MISMATCH movbe_src arm reg=%u\n", regs[i]);
			failures++;
		}
	}
}

/* A width-absent opcode must resolve to 64 bits, the one width that drives the
 * byte reversal and the memory access for both MOVBE forms. */
static void check_width_default(void)
{
	static const __u8 widths[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	unsigned i;

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		__u8 flags = widths[i];
		__u8 want = flags ? flags : X86_WIDTH_64;

		cases++;
		if (KPROG_X86_MOVBE_WIDTH(flags) != want) {
			printf("MISMATCH movbe_width flags=%u got=%u want=%u\n",
			       flags, KPROG_X86_MOVBE_WIDTH(flags), want);
			failures++;
		}
	}
}

int main(void)
{
	static const __u8 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	unsigned i, j;

	fill_patterns();

	/* ---- store: memory arm, each width, flat addressing at disp 0 ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("store/mem", X86_RAX, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0,
			    0x1020304050607080ULL, 0);

	/* store: memory arm, indexed addressing, each scale; EA in the heap. */
	for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
		check_store("store/mem/index", X86_RAX, X86_RCX, X86_WIDTH_32,
			    X86_RDI, 1ULL, scales[j],
			    0x0123456789abcdefULL, 0);

	/* store: displacement is the whole field sign-extended. */
	check_store("store/mem/disp", X86_RAX, X86_RCX, X86_WIDTH_64,
		    X86_REG_NONE, 0, 0, 0x8899aabbccddeeffULL, (__u64)4);

	/* store: stack arm, each width, flat addressing inside the frame. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("store/stack", X86_RSP, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0,
			    0x0102030405060708ULL, (__u64)-8);

	/* store: stack arm, indexed addressing stays within the frame. */
	check_store("store/stack/index", X86_RSP, X86_RCX, X86_WIDTH_8,
		    X86_RDI, 1ULL, 0, 0x77ULL, (__u64)-8);

	/* ---- load: memory arm, each width, flat addressing ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_load("load/mem", X86_RAX, X86_RCX, widths[i],
			   X86_REG_NONE, 0, 0, 0, 0xf0f0f0f0f0f0f0f0ULL);

	/* load: memory arm, indexed addressing, each scale. */
	for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
		check_load("load/mem/index", X86_RAX, X86_RCX, X86_WIDTH_16,
			   X86_RDI, 1ULL, scales[j], 0,
			   0x0f0f0f0f0f0f0f0fULL);

	/* load: stack arm, each width, flat addressing inside the frame. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_load("load/stack", X86_RDX, X86_RSP, widths[i],
			   X86_REG_NONE, 0, 0, -8, 0x1111111111111111ULL);

	/* load: stack arm, indexed addressing stays within the frame. */
	check_load("load/stack/index", X86_RDX, X86_RSP, X86_WIDTH_8,
		   X86_RDI, 1ULL, 0, -8, 0x2222222222222222ULL);

	{
		static const unsigned fw[] = {0, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64};
		static const __u64 nb[] = {0, 0x7fffffffef91ULL, 0xfffffffffffffff9ULL};
		unsigned st, via, wi, dr, bk, ik, sc, bi;
		for (st = 0; st < 2; st++) for (via = 0; via < 2; via++)
		for (wi = 0; wi < 4; wi++) for (dr = 0; dr < 16; dr++)
		for (bk = 0; bk < 4; bk++) for (ik = 0; ik < 4; ik++)
		for (sc = 0; sc < 4; sc++) for (bi = 0; bi < 3; bi++)
			check_frame(st, fw[wi], dr, bk, ik, sc, nb[bi], via);
	}

	check_source_macro();
	check_width_default();

	if (failures != 0) {
		printf("x86 movbe route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 movbe route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
