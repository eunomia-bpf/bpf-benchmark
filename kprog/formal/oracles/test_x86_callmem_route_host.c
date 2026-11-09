/* Actual simulator copy/fill routing against full-count byte effects.
 * Fixed counts above 1024 and register counts above IMM must not truncate.
 * Copy fixtures use disjoint valid buffers; this is not a kernel memcpy
 * overlap contract. Every destination byte and the returned pointer/tag match.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static __u64 fresh_values[16];
static unsigned fresh_cursor, incoming_flags, generic_route;
static __u64 fresh_word(void) { return fresh_values[(fresh_cursor++) & 15U]; }
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() fresh_word()

static int failures;
static unsigned long cases;

/* The heap the four bodies read and write, plus the whole-buffer expectation. */
#define HEAP_BYTES 4096U
static __u8 heap[HEAP_BYTES];
static __u8 exp_heap[HEAP_BYTES];

static void fill_pattern(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = (__u8)((i * 29U + 7U) ^ (i >> 3));
}

/* Snapshot the heap into the expectation buffer before a case runs. */
static void snapshot_expect(void)
{
	memcpy(exp_heap, heap, HEAP_BYTES);
}

/*
 * Run one block-copy / block-fill body over the modeled heap and compare the
 * whole buffer plus the result-register write against an independent byte
 * model and complete caller-clobber frame.
 *
 * `op_is_copy` selects `MEMCPY` (copy) vs `MEMSET` (fill); `op_is_reg` selects
 * the `*_REG` opcodes (length from `RDX`) vs the
 * immediate opcodes (length from the artifact).
 * `imm` is the instruction-immediate artifact. The destination is always at
 * heap offset 0; a copy reads its source from `SRC_OFF`.
 */
#define DST_OFF 0U
#define SRC_OFF 2048U

static void check_op(const char *what, int op_is_copy, int op_is_reg,
		     __u64 imm, __u64 rdx, __u64 fill_value, __u8 rdi_tag)
{

	__u64 count = op_is_reg ? rdx : imm;
	void *dst_ptr = (void *)(heap + DST_OFF);
	void *src_ptr = (void *)(heap + SRC_OFF);
	__u64 ea;
	unsigned i;
	__u64 old_raw[16];
	__u8 old_tags[16];
	static const unsigned caller_regs[8] = {1, 2, 6, 7, 8, 9, 10, 11};

	X86_SIM_L_DECLARE_STATE();
	__u8 __x86_sim_abi_kind = 0;
    X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	for (i = 0; i < 16; i++) {
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(unsigned long)(0x123456780000ULL + i * 37U), i & 7U);
		fresh_values[i] = (0x9e3779b97f4a7c15ULL * (i + 1U)) ^ imm ^ (rdx << 7) ^ incoming_flags;
	}
	__x86_cf = incoming_flags & 1U; __x86_zf = (incoming_flags >> 1) & 1U;
	__x86_sf = (incoming_flags >> 2) & 1U; __x86_of = (incoming_flags >> 3) & 1U;
	__x86_pf = (incoming_flags >> 4) & 1U; __x86_af = (incoming_flags >> 5) & 1U;
	__x86_xmm0_lo = 0x123456789abcdef0ULL;
	__x86_xmm0_hi = 0xfedcba9876543210ULL;
	fill_pattern();
	snapshot_expect();

	/* Plant the destination pointer (RDI), the source pointer / fill value
	 * (RSI), and, for the register-count opcodes, the length (RDX). */
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, dst_ptr, rdi_tag);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI,
				    op_is_copy ? src_ptr
					       : (void *)(long)fill_value,
				    op_is_copy ? X86_SIM_TAG_MAP_VALUE : X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, rdx, X86_WIDTH_64);

	/* ---- independent byte model of the bounded region ---- */
	for (i = 0; (__u64)i < count; i++) {
		if (op_is_copy)
			exp_heap[DST_OFF + i] = heap[SRC_OFF + i];
		else
			exp_heap[DST_OFF + i] = (__u8)(fill_value & 0xffULL);
	}

	for (i = 0; i < 16; i++) { old_raw[i] = (__u64)(unsigned long)X86_SIM_L_READ_REG_PTR(i); old_tags[i] = X86_SIM_L_REG_TAG(i); }
	fresh_cursor = 0;
	/* ---- run the real body ---- */
	if (generic_route) {
		unsigned op = op_is_copy ? (op_is_reg ? X86_OP_CALL_MEMCPY_REG : X86_OP_CALL_MEMCPY) :
			(op_is_reg ? X86_OP_CALL_MEMSET_REG : X86_OP_CALL_MEMSET);
		X86_SIM_L_EXEC(op, 0, 255, 37, 0xfeU, imm);
	} else if (op_is_copy && !op_is_reg)
		X86_SIM_L_EXEC_CALL_MEMCPY(imm);
	else if (op_is_copy && op_is_reg)
		X86_SIM_L_EXEC_CALL_MEMCPY_REG(imm);
	else if (!op_is_copy && !op_is_reg)
		X86_SIM_L_EXEC_CALL_MEMSET(imm);
	else
		X86_SIM_L_EXEC_CALL_MEMSET_REG(imm);

	/* ---- compare the whole heap ---- */
	cases++;
	for (i = 0; i < HEAP_BYTES; i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(copy=%d reg=%d imm=0x%llx rdx=%llu)\n",
			       what, i, heap[i], exp_heap[i], op_is_copy,
			       op_is_reg, (unsigned long long)imm,
			       (unsigned long long)rdx);
			failures++;
			return;
		}
	}

	/* ---- the result register is the destination pointer with RDI's tag */
	cases++;
	ea = (__u64)(unsigned long)X86_SIM_L_READ_REG_PTR(X86_RAX);
	if (ea != (__u64)(unsigned long)dst_ptr) {
		printf("MISMATCH %s rax=0x%llx want=0x%llx\n", what,
		       (unsigned long long)ea,
		       (unsigned long long)(unsigned long)dst_ptr);
		failures++;
	}
	cases++;
	if (X86_SIM_L_REG_TAG(X86_RAX) != rdi_tag) {
		printf("MISMATCH %s rax tag=%u want=%u\n", what,
		       X86_SIM_L_REG_TAG(X86_RAX), rdi_tag);
		failures++;
	}
	cases++;
	for (i = 0; i < 16; i++) {
		__u64 expected = i == X86_RAX ? (__u64)(unsigned long)dst_ptr : old_raw[i];
		__u8 tag = i == X86_RAX ? rdi_tag : old_tags[i];
		for (unsigned j = 0; j < 8; j++) if (i == caller_regs[j]) { expected = fresh_values[j]; tag = X86_SIM_TAG_SCALAR; }
		if ((__u64)(unsigned long)X86_SIM_L_READ_REG_PTR(i) != expected || X86_SIM_L_REG_TAG(i) != tag) {
			printf("MISMATCH %s full caller frame r%u route%u flags%u\n", what, i, generic_route, incoming_flags); failures++; return;
		}
	}
	if (fresh_cursor != 16 || __x86_cf != (fresh_values[8]&1) || __x86_zf != (fresh_values[9]&1) ||
	    __x86_sf != (fresh_values[10]&1) || __x86_of != (fresh_values[11]&1) ||
	    __x86_pf != (fresh_values[12]&1) || __x86_af != (fresh_values[13]&1) ||
	    __x86_xmm0_lo != fresh_values[14] || __x86_xmm0_hi != fresh_values[15]) {
		printf("MISMATCH %s kind6 stream/flag/vector frame route%u flags%u\n", what, generic_route, incoming_flags); failures++;
	}
}

/* The three routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_CALLMEM_KIND(1) != KPROG_X86_CALLMEM_COPY ||
	    KPROG_X86_CALLMEM_KIND(0) != KPROG_X86_CALLMEM_FILL) {
		printf("MISMATCH kind copy=%u fill=%u\n",
		       KPROG_X86_CALLMEM_KIND(1), KPROG_X86_CALLMEM_KIND(0));
		failures++;
	}
	cases++;
	if (KPROG_X86_CALLMEM_COUNT_SOURCE(1) != KPROG_X86_CALLMEM_COUNT_REG ||
	    KPROG_X86_CALLMEM_COUNT_SOURCE(0) != KPROG_X86_CALLMEM_COUNT_IMM) {
		printf("MISMATCH count source\n");
		failures++;
	}

}

int main(void)
{
	__u8 tags[] = { X86_SIM_TAG_SCALAR, X86_SIM_TAG_MAP_VALUE };
	unsigned t;

	for (incoming_flags = 0; incoming_flags < 64; incoming_flags++)
	for (generic_route = 0; generic_route < 2; generic_route++) {
	/* Full-count cases, including sizes beyond the removed simulator cap. */
	check_op("memcpy/imm", 1, 0, 16, 0, 0, X86_SIM_TAG_SCALAR);
	/* Full requested length; IMM is ignored by register-count forms. */
	check_op("memcpy/imm/over", 1, 0, 2000, 0, 0, X86_SIM_TAG_SCALAR);
	/* Full requested length; IMM is ignored by register-count forms. */
	check_op("memcpy/imm/small", 1, 0, 4, 0, 0, X86_SIM_TAG_SCALAR);
	/* Full requested length; IMM is ignored by register-count forms. */
	check_op("memcpy/reg", 1, 1, 32, 16, 0, X86_SIM_TAG_SCALAR);
	check_op("memcpy/reg/zero", 1, 1, 32, 0, 0, X86_SIM_TAG_SCALAR);
	/* Full requested length; IMM is ignored by register-count forms. */
	check_op("memcpy/reg/over", 1, 1, 8, 2000, 0, X86_SIM_TAG_SCALAR);

	/* ---- fill opcodes: one masked byte to every element ---- */
	/* MEMSET: immediate count, flat; a value wider than 8 bits must be
	 * truncated to its low byte. */
	check_op("memset/imm", 0, 0, 24, 0, 0x1122334455667788ULL,
		 X86_SIM_TAG_SCALAR);
	check_op("memset/imm/over", 0, 0, 2000, 0, 0xabcdef0123456789ULL,
		 X86_SIM_TAG_SCALAR);
	check_op("memset/imm/small", 0, 0, 4, 0, 0xffffffffffffffffULL,
		 X86_SIM_TAG_SCALAR);
	check_op("memset/reg", 0, 1, 32, 16, 0x0f0f0f0f0f0f0f0fULL,
		 X86_SIM_TAG_SCALAR);
	check_op("memset/reg/zero", 0, 1, 32, 0, 0x5555555555555555ULL,
		 X86_SIM_TAG_SCALAR);
	check_op("memset/reg/over", 0, 1, 8, 2000, 0x99aabbccddeeff00ULL,
		 X86_SIM_TAG_SCALAR);

	/* ---- the RDI tag follows the result register write ---- */
	for (t = 0; t < sizeof(tags) / sizeof(tags[0]); t++) {
		check_op("memcpy/tag", 1, 0, 16, 0, 0, tags[t]);
		check_op("memset/tag", 0, 1, 32, 16, 0x42ULL, tags[t]);
	}

	check_selectors();
	}

	if (failures != 0) {
		printf("x86 callmem route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 callmem route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
