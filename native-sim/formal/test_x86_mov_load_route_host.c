/*
 * Host cross-check for the x86 simulator's routing of the shared `MOV_LOAD`
 * handler composition through the machine-checked KPROG_X86_MOV_LOAD_* and
 * KPROG_X86_MEM_READ_SRC contracts.
 *
 * The simulator's `X86_SIM_L_EXEC_MOV_LOAD` no longer restates the width
 * resolution, the read-source dispatch or the ABI carry-arm predicate; it
 * resolves them through the generated contracts and then performs the load.
 * This oracle drives the REAL body over the three load opcodes, every
 * FLAGS/AUX width code, flat and indexed addressing, and the stack / ABI /
 * ordinary arms, and compares the whole modeled register file (bits and tags),
 * the heap and the stack against an independent byte model written from the
 * raw fields. The ABI pointer arm's tag refinement is checked separately by
 * `test_x86_mov_load_map_ptr_host.c`; here the carry-arm selection only needs
 * to agree with the contract.
 *
 * Build (see native-sim/formal/Makefile `check`):
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_mov_load_route_host.c -o build/test_x86_mov_load_route_host
 * Exit status is 0 on an exact match, 1 on any mismatch.
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

static int failures;
static unsigned long cases;

/* Backing storage for the memory arms; a fixed pattern distinct from the
 * modeled stack keeps a misroute between the two arms observable. */
static __u8 heap[256];

/* Independent little-endian width load, written as an explicit byte loop so it
 * never leans on the simulator's memory or stack macro. */
static __u64 model_load(const __u8 *base, __s64 off, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)base[off + i] << (8 * i);
	return v & KPROG_X86_WIDTH_MASK(width);
}

/* Independent little-endian stack load: the frame slot is addressed from the
 * `off + CAPACITY` index the stack contract fixes. */
static __u64 model_stack_load(const __u8 *sb, __s64 off, unsigned width)
{
	__u32 index = (__u32)(off + (__s64)X86_SIM_STACK_BYTES);
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)sb[index + i] << (8 * i);
	return v & KPROG_X86_WIDTH_MASK(width);
}

static __u64 model_ptr_load(const __u8 *base, __s64 off)
{
	void *p;

	memcpy(&p, &base[off], sizeof(p));
	return (__u64)(unsigned long)p;
}

static __u64 model_sign_extend(__u64 value, unsigned width)
{
	__u64 narrowed = value & KPROG_X86_WIDTH_MASK(width);

	if (narrowed & KPROG_X86_WIDTH_SIGN_MASK(width))
		return narrowed | ~KPROG_X86_WIDTH_MASK(width);
	return narrowed;
}

/* The partial-register writeback the sim performs: 8- and 16-bit writes keep
 * the destination's upper bytes, a 32-bit write zeroes the upper half, and a
 * 64-bit write replaces the register. */
static __u64 model_write(__u64 old, __u64 value, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (width == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value;
}

static __u8 model_abi_tag(unsigned kind, __s64 off)
{
	if (kind == KPROG_ABI_KIND_XDP) {
		if (off == KPROG_ABI_XDP_DATA_OFF)
			return X86_SIM_TAG_PACKET;
		if (off == KPROG_ABI_XDP_DATA_END_OFF)
			return X86_SIM_TAG_PACKET_END;
		return X86_SIM_TAG_SCALAR;
	}
	if (off == KPROG_ABI_SKB_DATA_OFF)
		return X86_SIM_TAG_PACKET;
	if (off == KPROG_ABI_SKB_DATA_END_OFF)
		return X86_SIM_TAG_PACKET_END;
	return X86_SIM_TAG_SCALAR;
}

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x40U + i);
}

/*
 * One scenario. `src` holds the base register (its tag is `base_tag`; for the
 * stack arm the base pointer is null, as the modeled RSP holds no address and
 * the frame offset carries the slot). `index_reg` (or X86_REG_NONE) and
 * `scale_log2` select the addressing mode; `kind` is the ABI kind the
 * pointer-carry arm tags from. The rule is the independent byte model of the
 * handler; the body must reproduce it exactly.
 */
static void check_load(const char *what, __u8 op, __u8 dst, __u8 src,
		       __u8 base_tag, __u8 flags, __u8 aux_width,
		       __u8 index_reg, __u64 index_val, __u8 scale_log2,
		       __u64 imm, unsigned kind)
{
	__u32 aux = KPROG_X86_MEM_AUX(index_reg, scale_log2, aux_width, 0U);
	__u8 mem_before[16], tag_before[16];
	__u8 width, mem;
	__s64 off;
	__u64 dst_old, want_bits;
	__u8 want_tag;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	__u8 __x86_sim_abi_kind = (__u8)kind;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xb0U + i);

	/* Setup order: destination sentinel first, then the index register, then
	 * the base last, so a destination that aliases either still ends up with
	 * the base/index value the handler must observe (it reads the base before
	 * writing the destination). */
	X86_SIM_L_WRITE_REG_WIDTH(dst, 0xdeadbeefcafef00dULL, X86_WIDTH_64);
	if (index_reg != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(index_reg, index_val, X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_PTR_TAG(src, src == X86_RSP ? (void *)0
							: (void *)heap,
				    base_tag);

	for (i = 0; i < 16; i++) {
		mem_before[i] = (__u8)X86_SIM_L_READ_REG(i);
		tag_before[i] = X86_SIM_L_REG_TAG(i);
	}
	dst_old = X86_SIM_L_READ_REG(dst);

	/* ---- independent model ---- */
	width = flags ? flags : X86_WIDTH_64;
	mem = aux_width ? aux_width : width;
	off = (__s64)imm;
	if (index_reg != X86_REG_NONE)
		off += (__s64)(index_val << scale_log2);

	if (src == X86_RSP) {
		want_bits = model_write(dst_old,
					model_stack_load(__x86_stack_mem.b,
							 off, mem), width);
		want_tag = X86_SIM_TAG_SCALAR;
	} else if (op == X86_OP_MOV_LOAD && mem == X86_WIDTH_64 &&
		   width == X86_WIDTH_64 && base_tag == X86_SIM_TAG_ABI) {
		want_bits = model_ptr_load(heap, off);
		want_tag = model_abi_tag(kind, off);
	} else {
		__u64 v = model_load(heap, off, mem);

		if (op == X86_OP_MOVSX_LOAD)
			v = model_sign_extend(v, mem);
		want_bits = model_write(dst_old, v, width);
		want_tag = X86_SIM_TAG_SCALAR;
	}

	/* ---- run the real body ---- */
	X86_SIM_L_EXEC_MOV_LOAD(op, dst, src, flags, aux, imm);

	/* ---- compare the whole modeled state ---- */
	cases++;
	for (i = 0; i < 16; i++) {
		if (i == dst) {
			if (X86_SIM_L_READ_REG(dst) != want_bits ||
			    X86_SIM_L_REG_TAG(dst) != want_tag) {
				printf("MISMATCH %s dst=%u got=(0x%llx,%u) "
				       "want=(0x%llx,%u)\n", what, dst,
				       (unsigned long long)X86_SIM_L_READ_REG(dst),
				       X86_SIM_L_REG_TAG(dst),
				       (unsigned long long)want_bits, want_tag);
				failures++;
				return;
			}
			continue;
		}
		if ((__u8)X86_SIM_L_READ_REG(i) != mem_before[i] ||
		    X86_SIM_L_REG_TAG(i) != tag_before[i]) {
			printf("MISMATCH %s clobber reg=%u "
			       "got=(0x%02x,%u) want=(0x%02x,%u)\n", what, i,
			       (__u8)X86_SIM_L_READ_REG(i), X86_SIM_L_REG_TAG(i),
			       mem_before[i], tag_before[i]);
			failures++;
			return;
		}
	}
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != (__u8)(0x40U + i)) {
			printf("MISMATCH %s heap[%u] modified\n", what, i);
			failures++;
			return;
		}
	}
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != (__u8)(0xb0U + i)) {
			printf("MISMATCH %s stack[%u] modified\n", what, i);
			failures++;
			return;
		}
	}
}

/* The routed read-source selector must equal an independent restatement of the
 * predicate ladder the contract fixes. */
static void check_read_src_macro(void)
{
	static const __u8 regs[] = { X86_RSP, X86_RAX, X86_RBX, X86_RDI,
				     X86_R15 };
	static const __u8 tags[] = { X86_SIM_TAG_SCALAR, X86_SIM_TAG_ABI,
				     X86_SIM_TAG_STACK, X86_SIM_TAG_MAP_PTR };
	static const __u8 widths[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	unsigned ri, ti, wi;

	for (ri = 0; ri < sizeof(regs) / sizeof(regs[0]); ri++) {
		for (ti = 0; ti < sizeof(tags) / sizeof(tags[0]); ti++) {
			for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]);
			     wi++) {
				__u8 reg = regs[ri];
				__u8 tag = tags[ti];
				__u8 w = widths[wi];
				__u8 want;

				X86_SIM_L_DECLARE_STATE();
				X86_SIM_L_WRITE_REG_PTR_TAG(reg, 0, tag);

				if (reg == X86_RSP)
					want = KPROG_X86_MEM_SRC_STACK;
				else if (tag == X86_SIM_TAG_ABI &&
					 w == X86_WIDTH_64)
					want = KPROG_X86_MEM_SRC_ABI_PTR_LOAD;
				else
					want = KPROG_X86_MEM_SRC_NORMAL_LOAD;

				cases++;
				if (X86_SIM_L_MEM_READ_SRC(reg, w) != want) {
					printf("MISMATCH read_src reg=%u tag=%u "
					       "w=%u got=%u want=%u\n", reg, tag,
					       w, X86_SIM_L_MEM_READ_SRC(reg, w),
					       want);
					failures++;
				}
			}
		}
	}
}

/* The routed arm selector the handler consults must equal an independent
 * restatement of the closed arm table, including the RSP-first precedence. */
static void check_arm_macro(void)
{
	static const __u8 codes[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				      X86_WIDTH_32, X86_WIDTH_64 };
	unsigned mi, wi, oi, ti, ri;

	for (ri = 0; ri < 2; ri++) {
		for (mi = 0; mi < sizeof(codes) / sizeof(codes[0]); mi++) {
			for (wi = 0; wi < sizeof(codes) / sizeof(codes[0]);
			     wi++) {
				for (oi = 0; oi < 2; oi++) {
					for (ti = 0; ti < 2; ti++) {
						__u8 mem = codes[mi];
						__u8 write = codes[wi];
						__u8 tag =
							ti ? X86_SIM_TAG_ABI
							   : X86_SIM_TAG_SCALAR;
						__u8 want;

						if (ri == 1)
							want =
							 KPROG_X86_MOV_LOAD_ARM_STACK;
						else if (oi == 1 &&
							 mem == X86_WIDTH_64 &&
							 write == X86_WIDTH_64 &&
							 tag == X86_SIM_TAG_ABI)
							want =
							 KPROG_X86_MOV_LOAD_ARM_ABI_PTR;
						else
							want =
							 KPROG_X86_MOV_LOAD_ARM_ORDINARY;

						cases++;
						if (KPROG_X86_MOV_LOAD_ARM(
							    ri, oi, mem, write,
							    tag) != want) {
							printf("MISMATCH arm "
							       "rsp=%u mov=%u "
							       "mem=%u w=%u "
							       "abi=%u got=%u "
							       "want=%u\n",
							       ri, oi, mem, write,
							       ti,
							       KPROG_X86_MOV_LOAD_ARM(
								       ri, oi, mem,
								       write, tag),
							       want);
							failures++;
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	static const __u8 ops[] = { X86_OP_MOV_LOAD, X86_OP_MOV_LOAD_SCALAR,
				    X86_OP_MOVSX_LOAD };
	static const __u8 flags_codes[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
					    X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 aux_codes[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
					  X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	static const struct {
		__u8 src;
		__u8 tag;
	} bases[] = {
		{ X86_RAX, X86_SIM_TAG_SCALAR },
		{ X86_RDI, X86_SIM_TAG_ABI },
		{ X86_RBX, X86_SIM_TAG_MAP_PTR },
	};
	unsigned oi, fi, ai, ci, si;

	fill_patterns();

	/* Ordinary memory arm: every opcode, width pair and base tag. */
	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]);
		     fi++)
			for (ai = 0;
			     ai < sizeof(aux_codes) / sizeof(aux_codes[0]); ai++)
				for (ci = 0;
				     ci < sizeof(bases) / sizeof(bases[0]);
				     ci++)
					check_load("mem/plain", ops[oi], X86_RDX,
						   bases[ci].src, bases[ci].tag,
						   flags_codes[fi],
						   aux_codes[ai], X86_REG_NONE,
						   0, 0, 16ULL,
						   KPROG_ABI_KIND_XDP);

	/* ABI pointer-carry arm: only MOV_LOAD at both widths 64 carries the
	 * pointer tag; every other combination falls through to a scalar load. */
	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]);
		     fi++)
			for (ai = 0;
			     ai < sizeof(aux_codes) / sizeof(aux_codes[0]); ai++)
				check_load("mem/abi", ops[oi], X86_RDX,
					   X86_RDI, X86_SIM_TAG_ABI,
					   flags_codes[fi], aux_codes[ai],
					   X86_REG_NONE, 0, 0, 8ULL,
					   KPROG_ABI_KIND_XDP);

	/* The ABI tag refinement at the packet/data-end offsets, both kinds. */
	for (ci = 0; ci < 2; ci++) {
		static const __s64 offs[] = { 0, 8, 208, 80 };
		unsigned k;

		for (k = 0; k < sizeof(offs) / sizeof(offs[0]); k++)
			check_load("mem/abi-off", X86_OP_MOV_LOAD, X86_RDX,
				   X86_RDI, X86_SIM_TAG_ABI, X86_WIDTH_64,
				   X86_WIDTH_64, X86_REG_NONE, 0, 0,
				   (__u64)offs[k],
				   ci ? KPROG_ABI_KIND_SKB
				      : KPROG_ABI_KIND_XDP);
	}

	/* Indexed addressing, each scale, on the ordinary arm. */
	for (si = 0; si < sizeof(scales) / sizeof(scales[0]); si++)
		for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]);
		     fi++)
			check_load("mem/index", X86_OP_MOV_LOAD, X86_RDX,
				   X86_RAX, X86_SIM_TAG_SCALAR, flags_codes[fi],
				   X86_WIDTH_16, X86_RCX, 2ULL, scales[si],
				   24ULL, KPROG_ABI_KIND_XDP);

	/* Stack arm: the base is RSP and the read uses the resolved memory
	 * width (not the write width); the displacement keeps the access inside
	 * the 64-byte frame. */
	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]);
		     fi++)
			for (ai = 0;
			     ai < sizeof(aux_codes) / sizeof(aux_codes[0]); ai++)
				check_load("stack", ops[oi], X86_RDX, X86_RSP,
					   X86_SIM_TAG_STACK, flags_codes[fi],
					   aux_codes[ai], X86_REG_NONE, 0, 0,
					   (__u64)-8, KPROG_ABI_KIND_XDP);

	/* Stack arm with an index register carried into the frame offset. */
	check_load("stack/index", X86_OP_MOV_LOAD, X86_RDX, X86_RSP,
		   X86_SIM_TAG_STACK, X86_WIDTH_8, X86_WIDTH_8, X86_RCX, 1ULL,
		   0, (__u64)-16, KPROG_ABI_KIND_XDP);

	/* Destination overlaps the base: the writeback must happen after the
	 * offset is formed, so the carried arm still resolves. */
	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		check_load("overlap/base", ops[oi], X86_RDI, X86_RDI,
			   X86_SIM_TAG_ABI, X86_WIDTH_64, X86_WIDTH_64,
			   X86_REG_NONE, 0, 0, 24ULL, KPROG_ABI_KIND_XDP);

	/* Destination overlaps the index register. */
	check_load("overlap/index", X86_OP_MOV_LOAD, X86_RCX, X86_RAX,
		   X86_SIM_TAG_SCALAR, X86_WIDTH_32, X86_WIDTH_32, X86_RCX,
		   3ULL, 1, 32ULL, KPROG_ABI_KIND_XDP);

	/* Sign extension must not leak high bytes of a narrow load. */
	for (ai = 0; ai < sizeof(aux_codes) / sizeof(aux_codes[0]); ai++)
		check_load("movsx", X86_OP_MOVSX_LOAD, X86_RDX, X86_RAX,
			   X86_SIM_TAG_SCALAR, X86_WIDTH_64, aux_codes[ai],
			   X86_REG_NONE, 0, 0, 40ULL, KPROG_ABI_KIND_XDP);

	check_read_src_macro();
	check_arm_macro();

	if (failures != 0) {
		printf("x86 mov-load route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mov-load route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
