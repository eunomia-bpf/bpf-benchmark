/*
 * Host cross-check for the x86 simulator's routing of the memory read-path
 * dispatch through the generated KPROG_X86_MEM_READ_SRC contract (STEP 0077).
 *
 * `X86_SIM_L_READ_MEM_VALUE` in `x86_sim_local_bpf.h` formerly restated the
 * stack-pointer / ABI-tag / ordinary-load predicate ladder inline (and
 * `X86_SIM_L_EXEC_MOV_LOAD` re-derived it against the opcode and write width).
 * Both now classify through the machine-checked `KPROG_X86_MEM_READ_SRC`, so
 * the sim's LEA/ALU/CMP/test reads share one dispatch with the Lean
 * refinement — exactly the arm64 read path's shape, which already routes
 * through `KPROG_ARM64_MEM_READ_SRC`.
 *
 * This oracle includes the *simulator* header (so the real
 * `X86_SIM_L_READ_MEM_VALUE` is the macro under test), builds the three source
 * kinds the contract names — a stack read at RSP, an ABI pointer load, and an
 * ordinary load — and checks the routed value against an independent byte
 * reader; it also checks that a misroute (e.g. an ABI-tagged base off width 64
 * taking the pointer arm) is observable and that the routed value equals an
 * explicit switch on `KPROG_X86_MEM_READ_SRC`. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_mem_dispatch_route_host.c -o /tmp/t_mdr && /tmp/t_mdr
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

/* DECLARE_STATE's tag initializers are written by the register-write path but
 * not read back here, so reference them to keep the build warning-free. */
#define X86_SIM_TEST_VOID_TAG(REG, NAME) (void)__x86_##NAME##_tag;

/* Backing storage for the ordinary/ABI arms; a fixed pattern distinct from the
 * modeled stack keeps a misroute between the two arms observable. */
static __u8 heap[64];
static void *ptr_cell;

/* Mask helper kept local so the oracle does not lean on the width contract. */
#define X86_SIM_ORACLE_MASK(WIDTH)                                   \
	((__u64)((WIDTH) == X86_WIDTH_8 ? 0xffULL :                  \
		 (WIDTH) == X86_WIDTH_16 ? 0xffffULL :              \
		 (WIDTH) == X86_WIDTH_32 ? 0xffffffffULL : 0xffffffffffffffffULL))

/* Independent little-endian byte reader, masked to WIDTH. Written as an
 * explicit byte assemble, never the simulator's stack or memory macro. */
static __u64 le_read(const __u8 *b, __u8 width)
{
	__u64 v = (__u64)b[0];

	if (!width)
		width = X86_WIDTH_64;
	if (width >= X86_WIDTH_16)
		v |= (__u64)b[1] << 8;
	if (width >= X86_WIDTH_32) {
		v |= (__u64)b[2] << 16;
		v |= (__u64)b[3] << 24;
	}
	if (width == X86_WIDTH_64) {
		unsigned i;

		for (i = 4; i < 8; i++)
			v |= (__u64)b[i] << (8 * i);
	}
	return v & X86_SIM_ORACLE_MASK(width);
}


/* Independent value the contract says the router must produce, given the
 * register tag and the computed effective address. */
static __u64 contract_value(__u8 src, const __u8 *addr, const __u8 *stack_base,
			    __s64 stack_off, __u8 width)
{
	switch (src) {
	case KPROG_X86_MEM_SRC_STACK:
		return le_read(stack_base + stack_off, width);
	case KPROG_X86_MEM_SRC_ABI_PTR_LOAD: {
		void *p = *(void **)(const void *)addr;

		return (__u64)(unsigned long)p;
	}
	default:
		return le_read(addr, width);
	}
}

/* Run one scenario through the simulator macro and compare with the
 * independent value; also compare with an explicit switch on the contract. */
static void check_one(const char *what, __u8 base_reg, __u8 base_tag,
		      __u64 base_value, __u8 width, __s64 disp, __u8 index_reg,
		      __u64 index_value, __u8 scale_log2, int store_disp)
{
	__u32 aux = KPROG_X86_MEM_AUX(
		index_reg, scale_log2, width, 0U);
	__u8 is_rsp = base_reg == X86_RSP;
	__u8 src;
	__u64 imm = (__u64)disp;

	__s64 eff_off;
	__u64 routed, want;
	__u8 *addr;
	const __u8 *stack_base;
	__s64 stack_off;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_stack_mem;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)0;

	if (base_reg != X86_REG_NONE) {
		if (base_tag == X86_SIM_TAG_ABI)
			X86_SIM_L_WRITE_REG_PTR_TAG(base_reg, (void *)base_value,
						    X86_SIM_TAG_ABI);
		else
			X86_SIM_L_WRITE_REG_WIDTH(base_reg, base_value,
						  X86_WIDTH_64);
	}
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_value, X86_WIDTH_64);

	/* Fill the modeled stack with a fixed pattern distinct from the heap so
	 * a misroute into the stack arm is observable; the same for the heap. */
	{
		unsigned i;

		for (i = 0; i < X86_SIM_STACK_BYTES; i++)
			__x86_stack_mem.b[i] = (__u8)(0xa0U + i);
		for (i = 0; i < sizeof(heap); i++)
			heap[i] = (__u8)(0x30U + i);
	}

	if (store_disp)
		imm = ((__u64)(__u32)(__s32)disp) << 32;
	routed = X86_SIM_L_READ_MEM_VALUE(base_reg, aux, imm, width,
					  store_disp);

	/* The independent effective offset: displacement plus the scaled index,
	 * exactly the composed address the read path forms. */
	eff_off = disp;
	if (index_reg != X86_REG_NONE)
		eff_off += (__s64)(index_value << scale_log2);
	addr = (__u8 *)(unsigned long)base_value + eff_off;
	/* The stack arm ignores the base pointer and addresses through the
	 * capacity-relative index, so base_value must not shift it. */
	stack_off = eff_off + (__s64)X86_SIM_STACK_BYTES;
	src = KPROG_X86_MEM_READ_SRC(is_rsp, base_tag, width);
	stack_base = __x86_stack_mem.b;
	want = contract_value(src, addr, stack_base, stack_off, width);

	cases++;
	if (routed != want) {
		printf("MISMATCH %s: base_reg=%u tag=%u width=%u disp=%lld "
		       "idx_reg=%u src=%u routed=0x%llx want=0x%llx\n",
		       what, base_reg, base_tag, width, (long long)disp,
		       index_reg, src, (unsigned long long)routed,
		       (unsigned long long)want);
		failures++;
	}
}

/* The gate probe: an ABI-tagged base at width < 64 must fall through to an
 * ordinary load. A router that dropped the width-64 gate would take the pointer
 * arm and read a full 64-bit pointer, which this arrangement makes different
 * from the masked ordinary load. */
static void check_abi_width_gate(void)
{
	__u64 cell = 0xdeadbeefcafef00dULL;
	__u8 widths[3] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32 };
	unsigned i;

	*(__u64 *)heap = cell;
	ptr_cell = heap; /* a valid pointer at a known cell */

	for (i = 0; i < 3; i++) {
		__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, widths[i], 0U);
		__u64 routed, byte_read;

		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_stack_mem;
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)0;
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, heap, X86_SIM_TAG_ABI);

		routed = X86_SIM_L_READ_MEM_VALUE(X86_RDI, aux, 0, widths[i], 0);
		byte_read = le_read(heap, widths[i]) &
			    X86_SIM_ORACLE_MASK(widths[i]);

		cases++;
		if (routed != byte_read) {
			printf("MISMATCH abi width gate width=%u routed=0x%llx "
			       "byte=0x%llx\n",
			       widths[i], (unsigned long long)routed,
			       (unsigned long long)byte_read);
			failures++;
		}
		if (KPROG_X86_MEM_READ_SRC(0U, X86_SIM_TAG_ABI, widths[i]) !=
		    KPROG_X86_MEM_SRC_NORMAL_LOAD) {
			printf("MISMATCH contract abi off-width %u not normal\n",
			       widths[i]);
			failures++;
		}
		if (routed == cell) {
			printf("MISMATCH abi width gate width=%u read full "
			       "pointer\n", widths[i]);
			failures++;
		}
	}
}

/* A no-index AUX must ignore whatever register file content sits behind the
 * (unused) index byte. */
static void check_no_index_ignores_regs(void)
{
	__u32 aux = KPROG_X86_MEM_AUX(KPROG_X86_MEM_AUX_INDEX_NONE, 3U,
				      X86_WIDTH_64, 0U);
	__u64 routed, want;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_stack_mem;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)0;
	X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0xffffffffffffffffULL,
				  X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX, (__u64)(unsigned long)heap,
				  X86_WIDTH_64);
	{
		unsigned i;

		for (i = 0; i < sizeof(heap); i++)
			heap[i] = (__u8)(0x11U + i);
	}
	routed = X86_SIM_L_READ_MEM_VALUE(X86_RBX, aux, 0, X86_WIDTH_64, 0);
	want = le_read(heap, X86_WIDTH_64);

	cases++;
	if (routed != want) {
		printf("MISMATCH no-index routed=0x%llx want=0x%llx\n",
		       (unsigned long long)routed, (unsigned long long)want);
		failures++;
	}
}

/* Drive the second routed site, `X86_SIM_L_EXEC_MOV_LOAD`, whose stack/ABI/
 * ordinary arm selection now comes from the same contract, and compare the
 * written value and register tag against an independent expectation.
 *
 * KIND_NORMAL: load `mem_width` bytes at heap+disp.
 * KIND_MOVSX:  sign-extend that load to 64 bits.
 * KIND_ABI:    load a pointer from heap+disp and stamp the packet tag.
 * KIND_ABI_OFFW: ABI base off width 64, so the ordinary arm masks to flags.
 * KIND_STACK:  read `mem_width` bytes from the modeled stack at capacity+disp
 *              (the stack helper ignores the pointer value and adds the
 *              capacity offset to the displacement). */
enum { KIND_NORMAL, KIND_MOVSX, KIND_ABI, KIND_ABI_OFFW, KIND_STACK };

static void check_mov_load(const char *what, __u8 op, __u8 dst, __u8 src,
			   __u8 flags, __u8 mem_width, __s64 disp, int src_abi,
			   int kind)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, mem_width, 0U);
	__u64 src_val = (__u64)(unsigned long)heap;
	__u64 want_value;
	__u8 want_tag;
	__u64 got_value;
	__u8 got_tag;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_stack_mem;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xa0U + i);
	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0xb0U + i);

	switch (kind) {
	case KIND_NORMAL:
		want_value = le_read(heap + disp, flags);
		break;
	case KIND_MOVSX:
		want_value = (__u64)(__s64)(signed char)le_read(heap + disp, 1);
		break;
	case KIND_ABI:
		want_value = *(__u64 *)(void *)(heap + disp);
		break;
	case KIND_ABI_OFFW:
		want_value = le_read(heap + disp, flags) & 0xffffffffULL;
		break;
	default:
		src_val = 0;
		want_value = le_read(__x86_stack_mem.b +
				     (X86_SIM_STACK_BYTES + disp), flags);
		break;
	}
	want_tag = kind == KIND_ABI ?
		KPROG_ABI_LOAD_TAG(KPROG_ABI_KIND_XDP, disp, X86_SIM_TAG_SCALAR,
				   X86_SIM_TAG_PACKET, X86_SIM_TAG_PACKET_END) :
		X86_SIM_TAG_SCALAR;

	if (src != X86_REG_NONE) {
		if (src_abi)
			X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)src_val,
						    X86_SIM_TAG_ABI);
		else
			X86_SIM_L_WRITE_REG_WIDTH(src, src_val, X86_WIDTH_64);
	}

	X86_SIM_L_EXEC_MOV_LOAD(op, dst, src, flags, aux, (__u64)disp);

	got_value = X86_SIM_L_READ_REG(dst);
	got_tag = X86_SIM_L_REG_TAG(dst);

	cases++;
	if (got_value != want_value) {
		printf("MISMATCH %s: mov_load value dst=%u src=%u flags=%u "
		       "mw=%u disp=%lld got=0x%llx want=0x%llx\n",
		       what, dst, src, flags, mem_width, (long long)disp,
		       (unsigned long long)got_value,
		       (unsigned long long)want_value);
		failures++;
	}
	cases++;
	if (got_tag != want_tag) {
		printf("MISMATCH %s: mov_load tag dst=%u got=%u want=%u\n",
		       what, dst, got_tag, want_tag);
		failures++;
	}
}

static void check_mov_load_cases(void)
{
	/* Ordinary load: the loaded bytes are written straight through. */
	check_mov_load("mov_load/normal", X86_OP_MOV_LOAD, X86_RCX, X86_RBX,
		       X86_WIDTH_64, X86_WIDTH_64, 0, 0, KIND_NORMAL);

	/* Sign-extending narrow load. */
	check_mov_load("mov_load/movsx", X86_OP_MOVSX_LOAD, X86_RDX, X86_RBX,
		       X86_WIDTH_64, X86_WIDTH_8, 0, 0, KIND_MOVSX);

	/* ABI-tagged base at width 64: the pointer arm loads the pointee and
	 * stamps the packet-derived tag. */
	check_mov_load("mov_load/abi", X86_OP_MOV_LOAD, X86_RCX, X86_RDI,
		       X86_WIDTH_64, X86_WIDTH_64, 0, 1, KIND_ABI);

	/* ABI-tagged base off width 64: the width-64 gate sends it down the
	 * ordinary arm, so no pointer tag is stamped. */
	check_mov_load("mov_load/abi-offwidth", X86_OP_MOV_LOAD, X86_RCX,
		       X86_RDI, X86_WIDTH_32, X86_WIDTH_32, 0, 1,
		       KIND_ABI_OFFW);

	/* Stack base: the stack helper returns the modeled bytes. */
	check_mov_load("mov_load/stack", X86_OP_MOV_LOAD, X86_RCX, X86_RSP,
		       X86_WIDTH_64, X86_WIDTH_64, -8, 0, KIND_STACK);
}

int main(void)
{
	static const __u8 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	/* Displacements keep the modeled stack index (disp + capacity) in
	 * range for a width-64 read. */
	static const __s64 stack_disps[] = { 0, -8, -32, 32, 56 };
	unsigned i, j;

	ptr_cell = heap;

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		__u8 w = widths[i];

		/* RSP is a null base and the stack arm addresses through the
		 * capacity-relative index, so only the offset matters. */
		for (j = 0; j < sizeof(stack_disps) / sizeof(stack_disps[0]); j++)
			check_one("stack", X86_RSP, X86_SIM_TAG_SCALAR, 0ULL, w,
				  stack_disps[j], X86_REG_NONE, 0ULL, 0, 0);
		check_one("stack+idx", X86_RSP, X86_SIM_TAG_SCALAR, 0ULL, w,
			  0, X86_RAX, 4ULL, 1, 0);

		/* Ordinary load, scalar base, with each scale; the EA stays in
		 * the 64-byte heap for every width. */
		for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++)
			check_one("normal", X86_RBX, X86_SIM_TAG_SCALAR,
				  (__u64)(unsigned long)heap, w, 0, X86_RAX,
				  4ULL, scales[j], 0);

		/* Ordinary load with the store-displacement interpretation. */
		check_one("normal/storedisp", X86_RBX, X86_SIM_TAG_SCALAR,
			  (__u64)(unsigned long)heap, w, 3, X86_REG_NONE, 0ULL,
			  0, 1);

		/* ABI-tagged base: pointer arm at width 64, ordinary otherwise. */
		check_one("abi", X86_RDI, X86_SIM_TAG_ABI,
			  (__u64)(unsigned long)&ptr_cell, w, 0, X86_REG_NONE,
			  0ULL, 0, 0);
	}

	check_abi_width_gate();
	check_no_index_ignores_regs();
	check_mov_load_cases();

	if (failures != 0) {
		printf("x86 mem dispatch route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mem dispatch route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
