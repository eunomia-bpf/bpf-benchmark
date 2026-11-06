/*
 * Host cross-check for the x86 simulator's routing of the `LOAD_XMM0` and
 * `STORE_XMM0` handlers (`X86_SIM_L_EXEC_LOAD_XMM0`,
 * `X86_SIM_L_EXEC_STORE_XMM0`) through the generated `KPROG_X86_XMM0_*`
 * contract.
 *
 * Both bodies formerly restated the contract inline — the stack-pointer arm
 * selection, the lane offsets, and (for the load) the `X86_REG_NONE` absolute
 * base form with its discarded offset. They now resolve the arm through
 * `KPROG_X86_XMM0_ARM`, the lane offsets through `KPROG_X86_XMM0_LANE_OFFSET`,
 * the ordinary-arm base form through `KPROG_X86_XMM0_BASE_FORM` /
 * `_ADDS_DISP` / `_BASE_PTR`, so the bodies and the Lean refinement share one
 * XMM0 implementation. This complements `test_x86_xmm0_host.c`, which tests
 * the contract plus an independent model but never includes the simulator
 * header.
 *
 * This oracle includes the *simulator* header (so the real macros are under
 * test). The load half plants two known lanes at the effective address and
 * compares the written XMM0 pair against an independent byte model; the store
 * half drives the real body and compares the *entire* resulting modeled memory
 * and stack against an independent byte model. Both halves cover the stack
 * arm, an ordinary register base, the `X86_REG_NONE` base form (load: raw
 * absolute immediate with the offset discarded; store: null base with the
 * offset added), and indexed addressing. It also checks the routed arm
 * selector, the lane offsets, and the base-form macro directly. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_xmm0_route_host.c -o /tmp/t_x0r && /tmp/t_x0r
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

static int failures;
static unsigned long cases;

/* Backing storage for the memory arm; a fixed pattern distinct from the
 * modeled stack keeps a misroute between the two arms observable. */
static __u8 heap[128];
static __u8 exp_heap[128];

static __u8 exp_stack[X86_SIM_STACK_BYTES];

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

/* The stack arena is declared per-scenario by X86_SIM_L_DECLARE_STACK, so it
 * is patterned in the scenario itself; a pattern distinct from the heap keeps
 * a misroute between the two arms observable. */
static void fill_stack(__u8 *stack_bytes)
{
	unsigned i;

	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		stack_bytes[i] = (__u8)(0xa0U + i);
}

/* Independent little-endian 8-byte lane store, written as an explicit byte
 * loop so it never leans on the simulator's memory or stack macro. */
static void put_lane(__u8 *b, __u64 v)
{
	unsigned i;

	for (i = 0; i < KPROG_X86_XMM0_LANE_BYTES; i++)
		b[i] = (__u8)(v >> (8 * i));
}

/* Independent little-endian 8-byte lane read. */
static __u64 get_lane(const __u8 *b)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < KPROG_X86_XMM0_LANE_BYTES; i++)
		v |= (__u64)b[i] << (8 * i);
	return v;
}

/*
 * Load scenario. `src` selects the arm (RSP -> stack read, other GPR ->
 * ordinary register base, X86_REG_NONE -> raw absolute immediate). The two
 * lanes are planted independently at the effective address, then the written
 * XMM0 pair is compared against the byte model.
 */
static void check_load(const char *what, __u8 src, __u64 imm,
		       __u8 index_reg, __u64 index_val, __u8 scale_log2)
{
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U);
	void *base_ptr;
	__u8 base_is_none = (src == X86_REG_NONE);
	__u8 adds_disp;
	__s64 disp = x86_simm(imm);
	__s64 off = disp;
	__u64 plant_lo = 0x1122334455667788ULL;
	__u64 plant_hi = 0x99aabbccddeeff00ULL;
	unsigned long ea;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	fill_stack(__x86_stack_mem.b);
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	if (!base_is_none && src != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(src, heap, X86_SIM_TAG_SCALAR);

	off += index_reg != X86_REG_NONE
		       ? (__s64)(index_val << scale_log2)
		       : 0;

	/* ---- independent model of the effective address and the lanes ---- */
	base_ptr = base_is_none ? (void *)(long)imm
				: (src == X86_RSP ? X86_SIM_L_READ_REG_PTR(src)
						  : heap);
	/* The load's X86_REG_NONE absolute-immediate form *discards* the
	 * addressing offset; every register base adds it. */
	adds_disp = !base_is_none;
	if (src == X86_RSP) {
		__u32 idx = X86_SIM_L_STACK_INDEX(
			(base_is_none ? disp : off));
		put_lane(&__x86_stack_mem.b[idx], plant_lo);
		put_lane(&__x86_stack_mem.b[idx + KPROG_X86_XMM0_LANE_OFFSET(1)],
			 plant_hi);
	} else {
		ea = (unsigned long)base_ptr +
		     (adds_disp ? (unsigned long)off : 0UL);
		put_lane(&heap[ea - (unsigned long)heap], plant_lo);
		put_lane(&heap[ea - (unsigned long)heap +
			       KPROG_X86_XMM0_LANE_OFFSET(1)], plant_hi);
	}

	/* ---- run the real body ---- */
	X86_SIM_L_EXEC_LOAD_XMM0(src, aux, imm);

	cases++;
	if (__x86_xmm0_lo != plant_lo || __x86_xmm0_hi != plant_hi) {
		printf("MISMATCH %s lo=0x%llx want=0x%llx hi=0x%llx want=0x%llx "
		       "(src=%u imm=0x%llx off=%lld)\n", what,
		       (unsigned long long)__x86_xmm0_lo,
		       (unsigned long long)plant_lo,
		       (unsigned long long)__x86_xmm0_hi,
		       (unsigned long long)plant_hi, src,
		       (unsigned long long)imm, (long long)off);
		failures++;
	}
}

/*
 * Store scenario. `dst` selects the arm (RSP -> stack write, other GPR ->
 * ordinary register base, X86_REG_NONE -> null base). The whole modeled memory
 * and stack are compared against an independent byte model.
 */
static void check_store(const char *what, __u8 dst, __u64 imm,
			__u64 lo, __u64 hi, __u8 index_reg, __u64 index_val,
			__u8 scale_log2)
{
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, 0U, 0U);
	void *base_ptr;
	__u8 base_is_none = (dst == X86_REG_NONE);
	__s64 disp = x86_simm(imm);
	__s64 off = disp;
	unsigned long ea;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	fill_stack(__x86_stack_mem.b);
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	if (!base_is_none && dst != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(dst, heap, X86_SIM_TAG_SCALAR);
	__x86_xmm0_lo = lo;
	__x86_xmm0_hi = hi;

	off += index_reg != X86_REG_NONE
		       ? (__s64)(index_val << scale_log2)
		       : 0;

	/* The store's X86_REG_NONE null-base form *adds* the offset to the null
	 * base; every register base adds it to the register value. */
	base_ptr = base_is_none ? (void *)0
				: (dst == X86_RSP ? X86_SIM_L_READ_REG_PTR(dst)
						  : heap);

	/* ---- independent model ---- */
	for (i = 0; i < sizeof(heap); i++)
		exp_heap[i] = heap[i];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp_stack[i] = __x86_stack_mem.b[i];
	if (dst == X86_RSP) {
		__u32 idx = X86_SIM_L_STACK_INDEX(off);
		put_lane(&exp_stack[idx], lo);
		put_lane(&exp_stack[idx + KPROG_X86_XMM0_LANE_OFFSET(1)], hi);
	} else {
		ea = (unsigned long)base_ptr + (unsigned long)off;
		put_lane(&exp_heap[ea - (unsigned long)heap], lo);
		put_lane(&exp_heap[ea - (unsigned long)heap +
				   KPROG_X86_XMM0_LANE_OFFSET(1)], hi);
	}

	/* ---- run the real body ---- */
	X86_SIM_L_EXEC_STORE_XMM0(dst, aux, imm);

	/* ---- compare the whole modeled state ---- */
	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(dst=%u imm=0x%llx off=%lld)\n", what, i,
			       heap[i], exp_heap[i], dst,
			       (unsigned long long)imm, (long long)off);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s stack[%u]=0x%02x want=0x%02x "
			       "(dst=%u imm=0x%llx off=%lld)\n", what, i,
			       __x86_stack_mem.b[i], exp_stack[i], dst,
			       (unsigned long long)imm, (long long)off);
			failures++;
			return;
		}
	}
}

/* The routed arm selector must equal the contract's classification. */
static void check_arm_macro(void)
{
	static const __u8 regs[] = { X86_RSP, X86_RAX, X86_RBX, X86_RDI,
				     X86_R15, X86_REG_NONE };
	unsigned i;

	for (i = 0; i < sizeof(regs) / sizeof(regs[0]); i++) {
		__u8 want = KPROG_X86_XMM0_ARM(regs[i] == X86_RSP);

		cases++;
		if (X86_SIM_L_MEM_XMM0_ARM(regs[i]) != want) {
			printf("MISMATCH xmm0_arm reg=%u got=%u want=%u\n",
			       regs[i], X86_SIM_L_MEM_XMM0_ARM(regs[i]), want);
			failures++;
		}
		cases++;
		if ((regs[i] == X86_RSP) !=
		    (want == KPROG_X86_XMM0_ARM_STACK)) {
			printf("MISMATCH xmm0_arm reg=%u\n", regs[i]);
			failures++;
		}
	}
}

/* The lane offsets the bodies select are the contract's, 0 and 8. */
static void check_lane_offset(void)
{
	cases++;
	if (KPROG_X86_XMM0_LANE_OFFSET(0) != KPROG_X86_XMM0_LANE_LO ||
	    KPROG_X86_XMM0_LANE_LO != 0U) {
		printf("MISMATCH lane_lo=%u\n", KPROG_X86_XMM0_LANE_OFFSET(0));
		failures++;
	}
	cases++;
	if (KPROG_X86_XMM0_LANE_OFFSET(1) != KPROG_X86_XMM0_LANE_HI ||
	    KPROG_X86_XMM0_LANE_HI != KPROG_X86_XMM0_LANE_BYTES) {
		printf("MISMATCH lane_hi=%u\n", KPROG_X86_XMM0_LANE_OFFSET(1));
		failures++;
	}
}

/* The routed base form must be the load's absolute-immediate form and the
 * store's null-base form, the asymmetry the two bodies depend on. */
static void check_base_form_macro(void)
{
	cases++;
	if (KPROG_X86_XMM0_BASE_FORM(1U) != KPROG_X86_XMM0_BASE_ABS_IMM) {
		printf("MISMATCH load base form=%u\n",
		       KPROG_X86_XMM0_BASE_FORM(1U));
		failures++;
	}
	cases++;
	if (KPROG_X86_XMM0_BASE_FORM(0U) != KPROG_X86_XMM0_BASE_NULL_PLUS_DISP) {
		printf("MISMATCH store base form=%u\n",
		       KPROG_X86_XMM0_BASE_FORM(0U));
		failures++;
	}
}

int main(void)
{
	__u8 regs[] = { X86_RAX, X86_RBX, X86_RDI, X86_R15 };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	unsigned i, j;
	__u64 abs_imm = (__u64)(unsigned long)heap + 8UL;

	fill_patterns();

	/* ---- load: ordinary register base, each base register ---- */
	for (i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		check_load("load/reg", regs[i], 0, X86_REG_NONE, 0, 0);

	/* load: register base with a non-zero displacement. */
	check_load("load/reg/disp", X86_RAX, (__u64)16, X86_REG_NONE, 0, 0);

	/* load: register base, indexed addressing, each scale. */
	for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
		check_load("load/reg/index", X86_RAX, 0, X86_RDI, 1ULL,
			   scales[j]);

	/* load: X86_REG_NONE base is the raw absolute immediate, offset
	 * discarded — a non-zero displacement must not move the read. */
	check_load("load/abs", X86_REG_NONE, abs_imm, X86_REG_NONE, 0, 0);
	check_load("load/abs/disp", X86_REG_NONE, abs_imm, X86_REG_NONE, 0, 0);

	/* load: stack arm, flat and displaced inside the frame. */
	check_load("load/stack", X86_RSP, (__u64)-16, X86_REG_NONE, 0, 0);
	check_load("load/stack/disp", X86_RSP, (__u64)-24, X86_REG_NONE, 0, 0);
	check_load("load/stack/index", X86_RSP, (__u64)-24, X86_RDI, 1ULL, 0);

	/* load: the two base forms coincide unchecked when no index moves the
	 * effective address; an index riding an absolute base separates the
	 * load's raw-immediate reading from the store's null-base reading. */
	check_load("load/abs/index", X86_REG_NONE, abs_imm, X86_RDI, 1ULL, 0);

	/* ---- store: ordinary register base, flat and displaced ---- */
	for (i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		check_store("store/reg", regs[i], 0, 0x1020304050607080ULL,
			    0x8899aabbccddeeffULL, X86_REG_NONE, 0, 0);
	check_store("store/reg/disp", X86_RAX, 16, 0x0102030405060708ULL,
		    0x1112131415161718ULL, X86_REG_NONE, 0, 0);
	for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
		check_store("store/reg/index", X86_RAX, 0, 0x0123456789abcdefULL,
			    0x7777777777777777ULL, X86_RDI, 1ULL, scales[j]);

	/* store: X86_REG_NONE base is the null pointer, offset *added*; the
	 * immediate names the effective address directly. */
	check_store("store/null", X86_REG_NONE, abs_imm,
		    0xdeadbeefcafebabeULL, 0x0011223344556677ULL,
		    X86_REG_NONE, 0, 0);

	/* store: likewise, the null-base offset-add is separated from the
	 * absolute-immediate reading only once an index moves the address. */
	check_store("store/null/index", X86_REG_NONE, abs_imm,
		    0xabcdef0123456789ULL, 0x8899aabbccddeeffULL, X86_RDI, 1ULL,
		    0);

	/* store: stack arm, flat and displaced inside the frame. */
	check_store("store/stack", X86_RSP, (__u64)-16, 0x2222222222222222ULL,
		    0x3333333333333333ULL, X86_REG_NONE, 0, 0);
	check_store("store/stack/disp", X86_RSP, (__u64)-24,
		    0x4444444444444444ULL, 0x5555555555555555ULL,
		    X86_REG_NONE, 0, 0);
	check_store("store/stack/index", X86_RSP, (__u64)-24,
		    0x6666666666666666ULL, 0x7777777777777777ULL, X86_RDI, 1ULL,
		    0);

	check_arm_macro();
	check_lane_offset();
	check_base_form_macro();

	if (failures != 0) {
		printf("x86 xmm0 route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 xmm0 route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
