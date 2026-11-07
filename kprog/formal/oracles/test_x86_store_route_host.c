/*
 * Host cross-check for the x86 simulator's routing of the shared `MOV_STORE`
 * handler (`X86_SIM_L_EXEC_STORE`) through the generated `KPROG_X86_STORE_*`
 * contract (STEP 0078).
 *
 * The store body formerly restated the whole contract inline — the width
 * fallback, the two displacement slices, the two value sources, the AUX
 * source-shift gate, and the stack-pointer arm selection. It now resolves each
 * through the machine-checked macros, so the body and the Lean refinement
 * (`X86StoreHandler.lean`) share one store implementation.
 *
 * This oracle includes the *simulator* header (so the real
 * `X86_SIM_L_EXEC_STORE` is the macro under test), drives it over the
 * immediate/register forms, every width, the flat and indexed addressing modes,
 * the register-form AUX source shift, and the stack and memory arms, and
 * compares the *entire* resulting modeled memory and modeled stack against an
 * independent byte model built from the raw inputs. It also checks the routed
 * arm selector against the contract. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_store_route_host.c -o /tmp/t_str && /tmp/t_str
 */
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>
#include "x86_no_helpers_host.h"

static int failures;
static unsigned long cases;

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

/* Independent restatement of the width-aware immediate rule the store's
 * immediate form consumes. */
static __u64 imm_value(__u64 v, __u8 width)
{
	if (width == X86_WIDTH_64 && (v & 0x80000000ULL))
		return (v & 0xffffffffULL) | 0xffffffff00000000ULL;
	return v & 0xffffffffULL;
}

/* Independent restatement of the displacement form: the immediate form takes
 * the sign-extended high half, the register form the whole field. */
static __s64 disp_of(int is_imm, __u64 imm)
{
	return is_imm ? (__s64)(__s32)(imm >> 32) : (__s64)imm;
}

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

/*
 * One scenario. `dst` selects both the arm (RSP -> stack, other GPR -> memory)
 * and the memory-arm base pointer; `index_reg` (or X86_REG_NONE) and
 * `scale_log2` set the addressing mode; `src_shift` is the register form's AUX
 * source shift; `src_reg` supplies the register-form value; `is_imm`/`imm`
 * drive both the displacement slice and the value source.
 */
static void check_store(const char *what, __u8 dst, __u8 src_reg, __u8 flags,
			__u8 index_reg, __u64 index_val, __u8 scale_log2,
			__u8 src_shift, __u64 src_val, int is_imm, __u64 imm)
{
	__u8 op = is_imm ? X86_OP_MOV_STORE_IMM : X86_OP_MOV_STORE_REG;
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U) |
		    ((__u32)src_shift << 24);
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

	/* The register-form AUX source shift is the top byte of the AUX word; for
	 * the immediate form the store must ignore it. */
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(src_reg, src_val, X86_WIDTH_64);

	if (dst != X86_REG_NONE && dst != X86_RSP) {
		/* The destination register holds the memory-arm base pointer. */
		X86_SIM_L_WRITE_REG_PTR_TAG(dst, heap, X86_SIM_TAG_SCALAR);
	}

	/* ---- independent model ---- */
	width = flags ? flags : X86_WIDTH_64;
	disp = disp_of(is_imm, imm);
	value = is_imm ? imm_value(imm, width) : src_val;
	if (!is_imm)
		value >>= src_shift;
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
	X86_SIM_L_EXEC_STORE(op, dst, src_reg, flags, aux, imm);

	/* ---- compare the whole modeled state ---- */
	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(dst=%u is_imm=%d width=%u disp=%lld off=%lld)\n",
			       what, i, heap[i], exp_heap[i], dst, is_imm,
			       width, (long long)disp, (long long)off);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s stack[%u]=0x%02x want=0x%02x "
			       "(dst=%u is_imm=%d width=%u disp=%lld off=%lld)\n",
			       what, i, __x86_stack_mem.b[i], exp_stack[i],
			       dst, is_imm, width, (long long)disp,
			       (long long)off);
			failures++;
			return;
		}
	}
}

/* The routed arm selector must equal the contract's classification. */
static void check_store_src_macro(void)
{
	static const __u8 regs[] = { X86_RSP, X86_RAX, X86_RBX, X86_RDI,
				     X86_R15, X86_REG_NONE };
	unsigned i;

	for (i = 0; i < sizeof(regs) / sizeof(regs[0]); i++) {
		__u8 want = KPROG_X86_STORE_ARM(regs[i] == X86_RSP);

		cases++;
		if (X86_SIM_L_MEM_STORE_SRC(regs[i]) != want) {
			printf("MISMATCH store_src reg=%u got=%u want=%u\n",
			       regs[i], X86_SIM_L_MEM_STORE_SRC(regs[i]), want);
			failures++;
		}
		cases++;
		if ((regs[i] == X86_RSP) !=
		    (want == KPROG_X86_STORE_ARM_STACK)) {
			printf("MISMATCH store_src arm reg=%u\n", regs[i]);
			failures++;
		}
	}
}

/* A width-absent opcode must store 64 bits, and the stack arm must use the
 * same resolved width as the memory arm (no second width). */
static void check_width_default(void)
{
	static const __u8 widths[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	unsigned i;

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		__u8 flags = widths[i];
		__u8 want = flags ? flags : X86_WIDTH_64;

		cases++;
		if (KPROG_X86_STORE_WIDTH(flags) != want) {
			printf("MISMATCH store_width flags=%u got=%u want=%u\n",
			       flags, KPROG_X86_STORE_WIDTH(flags), want);
			failures++;
		}
	}
}


/* Full numeric-frame checks exercise both the shared body and dispatcher.
The model reads old source/base/index cells before any guest byte update. */
static __u64 store_native_cell(const __u64 *r, const __u8 *tags, unsigned reg,
                                __u64 arena, __u64 base)
{
    return reg == X86_RSP ? r[reg] + base :
        tags[reg] == X86_SIM_TAG_STACK ? r[reg] - arena + base : r[reg];
}

static void check_store_frame(unsigned immediate, unsigned flags, unsigned data_reg,
                               unsigned shift, unsigned base_kind, unsigned index_kind,
                               unsigned scale, __u64 native_base, unsigned artifact, unsigned via)
{
    static const __u32 low[] = {0U, 0x7fffffffU, 0x80000001U, 0xffffffffU};
    __u8 h[192], eh[192], es[X86_SIM_STACK_BYTES], tags[16];
    __u64 r[16], arena, base, index, target, disp, value, encoded;
    unsigned width = flags ? flags : 8, i, bad, slot = 16 + (artifact & 1);
    unsigned br = base_kind == 0 ? X86_RSP : base_kind == 3 ? X86_REG_NONE : X86_RBP;
    unsigned ir = index_kind == 0 ? X86_REG_NONE : index_kind == 1 ? X86_RCX :
        index_kind == 2 ? (immediate ? X86_RDX : X86_RSP) : (immediate ? X86_RBX : X86_RBP);
    __u32 aux = ir | (scale << 8) | (0xd3U << 16) | ((immediate ? 0xa3U : shift) << 24);
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
    }
    r[X86_RSP] = (__u64)-32; r[X86_RCX] = 3; r[X86_RDX] = 5; r[X86_RBX] = 2;
    r[X86_RBP] = base_kind == 2 ? arena - 40 : (__u64)(unsigned long)&h[48];
    tags[X86_RBP] = base_kind == 2 ? X86_SIM_TAG_STACK : X86_SIM_TAG_SCALAR;
    for (i = 0; i < 16; i++)
        X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(unsigned long)r[i], tags[i]);
    __x86_native_stack_base = native_base;
    __x86_cf = 1; __x86_zf = 0; __x86_sf = 1; __x86_of = 1; __x86_pf = 0; __x86_af = 1;
    __x86_xmm0_lo = 0x12345678abcdef01ULL; __x86_xmm0_hi = 0xfedcba9876543210ULL;
    base = br == X86_REG_NONE ? 0 : r[br];
    index = ir == X86_REG_NONE ? 0 : store_native_cell(r, tags, ir, arena, native_base);
    target = base_kind == 0 ? -(__u64)slot : base_kind == 2 ? arena - slot : (__u64)(unsigned long)&h[96 + (artifact & 1)];
    disp = target - base - (ir == X86_REG_NONE ? 0 : index << scale);
    encoded = immediate ? ((__u64)(__u32)disp << 32) | low[artifact] : disp;
    memory = base_kind == 0 || base_kind == 2 ? &es[X86_SIM_STACK_BYTES - slot] : &eh[96 + (artifact & 1)];
    if (immediate) {
        /* The packed displacement must equal this fixture's complete delta. */
        if ((__u64)(__s64)(__s32)(encoded >> 32) != disp) {
            printf("MISMATCH immediate store fixture displacement\n"); failures++; return;
        }
        value = low[artifact];
        if (width == 8 && (value & 0x80000000ULL)) value |= 0xffffffff00000000ULL;
    } else value = store_native_cell(r, tags, data_reg, arena, native_base) >> shift;
    for (i = 0; i < width; i++) memory[i] = (__u8)(value >> (8 * i));
    if (via)
        X86_SIM_L_EXEC(immediate ? X86_OP_MOV_STORE_IMM : X86_OP_MOV_STORE_REG,
            br, immediate ? X86_REG_NONE : data_reg, flags, aux, encoded);
    else X86_SIM_L_EXEC_STORE(immediate ? X86_OP_MOV_STORE_IMM : X86_OP_MOV_STORE_REG,
            br, immediate ? X86_REG_NONE : data_reg, flags, aux, encoded);
    bad = memcmp(h, eh, sizeof(h)) != 0;
    for (i = 0; i < X86_SIM_STACK_BYTES; i++) bad |= es[i] != __x86_stack_mem.b[i];
    cases++;
    if (bad) {
        printf("MISMATCH store frame memory imm=%u width=%u src=%u shift=%u base=%u index=%u scale=%u via=%u\n",
            immediate, width, data_reg, shift, base_kind, index_kind, scale, via);
        failures++; return;
    }
    for (i = 0; i < 16; i++) {
        cases += 2;
        if ((__u64)(unsigned long)X86_SIM_L_REG_VALUE(i) != r[i] || X86_SIM_L_REG_TAG(i) != tags[i]) {
            printf("MISMATCH store frame preserved reg%u\n", i); failures++; return;
        }
    }
    cases++;
    if (__x86_cf != 1 || __x86_zf != 0 || __x86_sf != 1 || __x86_of != 1 || __x86_pf != 0 || __x86_af != 1 ||
        __x86_xmm0_lo != 0x12345678abcdef01ULL || __x86_xmm0_hi != 0xfedcba9876543210ULL) {
        printf("MISMATCH store frame flags/vector\n"); failures++;
    }
}

static void check_store_frames(void)
{
    static const unsigned widths[] = {0, 1, 2, 4, 8};
    static const __u64 bases[] = {0, 0x7fffffffef91ULL, 0xfffffffffffffff9ULL};
    unsigned wi, reg, bk, ik, sc, bi, via, artifact;
    for (wi = 0; wi < 5; wi++) for (bk = 0; bk < 4; bk++)
    for (ik = 0; ik < 4; ik++) for (sc = 0; sc < 4; sc++)
    for (bi = 0; bi < 3; bi++) for (via = 0; via < 2; via++) {
        for (reg = 0; reg < 16; reg++)
            check_store_frame(0, widths[wi], reg, 0, bk, ik, sc, bases[bi], reg & 3, via);
        if (widths[wi] == 1) for (reg = 0; reg < 4; reg++)
            check_store_frame(0, 1, reg, 8, bk, ik, sc, bases[bi], reg, via);
        if (bk < 3) for (artifact = 0; artifact < 4; artifact++)
            check_store_frame(1, widths[wi], X86_REG_NONE, 0, bk, ik, sc, bases[bi], artifact, via);
    }
}

int main(void)
{
	static const __u8 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	static const __s64 stack_disps[] = { -64, -32, -16, -8 };
	unsigned i, j;

	fill_patterns();

	/* Memory arm: register form, each width, flat addressing at disp 0. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("mem/reg", X86_RAX, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0, 0,
			    0x1122334455667788ULL >> (8 * (8 - widths[i])),
			    0, 0);

	/* Memory arm: immediate form, each width, flat addressing. The high half
	 * of the immediate is the displacement, so it is kept at 0; the low half
	 * has its sign bit set to exercise the width-64 sign extension. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("mem/imm", X86_RAX, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0, 0, 0, 1,
			    0x000000008899aabbULL);

	/* Memory arm: indexed addressing, each scale; EA stays in the heap. */
	for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
		check_store("mem/index", X86_RAX, X86_RCX, X86_WIDTH_32,
			    X86_RDI, 1ULL, scales[j], 0,
			    0x0123456789abcdefULL, 0, 0);

	/* Immediate-form split: the high 32 bits are the displacement and the low
	 * 32 the value, so the two slices must not be conflated. */
	for (i = 0; i < 4; i++)
		check_store("mem/imm-split", X86_RAX, X86_RCX, X86_WIDTH_32,
			    X86_REG_NONE, 0, 0, 0, 0, 1,
			    0x0000000300000004ULL);

	/* Stack arm: register form, each width, flat addressing. */
	for (i = 0; i < sizeof(stack_disps) / sizeof(stack_disps[0]); i++)
		check_store("stack/reg", X86_RSP, X86_RCX, X86_WIDTH_8,
			    X86_REG_NONE, 0, 0, 0, 0x99ULL, 0,
			    (__u64)stack_disps[i]);

	/* Every stack write is kept strictly inside the frame: the stack index is
	 * `off + CAPACITY`, so a displacement of -8 leaves room for a width-64
	 * word. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("stack/reg-w", X86_RSP, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0, 0, 0x0102030405060708ULL, 0,
			    (__u64)-8);

	/* Stack arm: immediate form. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
		check_store("stack/imm", X86_RSP, X86_RCX, widths[i],
			    X86_REG_NONE, 0, 0, 0, 0, 1,
			    0x0000000000abcd00ULL | ((__u64)(__s32)-8 << 32));

	/* Stack arm: register form with a nonzero AUX source shift. */
	check_store("stack/regshift", X86_RSP, X86_RCX, X86_WIDTH_32,
		    X86_REG_NONE, 0, 0, 4, 0x0f0f0f0f0f0f0f0fULL, 0,
		    (__u64)-8);

	/* Stack arm: indexed addressing stays within the frame. */
	check_store("stack/index", X86_RSP, X86_RCX, X86_WIDTH_8,
		    X86_RDI, 1ULL, 0, 0, 0x77ULL, 0, (__u64)-8);

	check_store_frames();
	check_store_src_macro();
	check_width_default();

	if (failures != 0) {
		printf("x86 store route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 store route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
