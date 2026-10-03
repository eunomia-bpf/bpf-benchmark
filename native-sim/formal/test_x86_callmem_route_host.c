/*
 * Host cross-check for the x86 simulator's routing of the four block-copy /
 * block-fill bodies `X86_SIM_L_EXEC_CALL_MEMCPY`, `..._MEMCPY_REG`,
 * `..._MEMSET`, and `..._MEMSET_REG` through the machine-checked
 * `KPROG_X86_CALLMEM_*` contract.
 *
 * The four bodies now share one `X86_SIM_L_EXEC_CALL_MEM_STEP` composition
 * that selects the array shape through `KPROG_X86_CALLMEM_KIND`, the
 * copied/filled length's source through `KPROG_X86_CALLMEM_COUNT_SOURCE`, and
 * the array bound through `KPROG_X86_CALLMEM_BOUND_FORM` /
 * `KPROG_X86_CALLMEM_FIXED_BOUND`. This oracle includes the *simulator* header
 * so it drives those real bodies rather than a restatement, and compares the
 * whole modeled heap and the result-register write against an independent
 * byte model.
 *
 * Unlike the pre-existing `test_x86_callmem_host.c` (which checks the contract
 * plus a model but never includes the simulator header), this oracle covers
 * the routing the four bodies now perform. It plants, per opcode, a case where
 * each of the three routed facts is *numerically distinguishable* from the
 * wrong selection: an immediate-count case whose artifact exceeds the literal
 * `1024` bound (so a bound-form swap to the artifact writes a longer region),
 * and a register-count case whose `RDX` exceeds the artifact (so a bound-form
 * swap to the literal, or a count-source swap to the artifact, writes a
 * different region).
 *
 * Build/run:
 *   cd native-sim/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_callmem_route_host.c -o /tmp/t_cmr && /tmp/t_cmr
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
 * model.
 *
 * `op_is_copy` selects `MEMCPY` (copy) vs `MEMSET` (fill); `op_is_reg` selects
 * the `*_REG` opcodes (length from `RDX`, bound from the artifact) vs the
 * immediate opcodes (length from the artifact, bound the literal 1024).
 * `imm` is the instruction-immediate artifact. The destination is always at
 * heap offset 0; a copy reads its source from `SRC_OFF`.
 */
#define DST_OFF 0U
#define SRC_OFF 2048U

static void check_op(const char *what, int op_is_copy, int op_is_reg,
		     __u64 imm, __u64 rdx, __u64 fill_value, __u8 rdi_tag)
{
	__u64 bound = op_is_reg ? imm : (__u64)KPROG_X86_CALLMEM_FIXED_BOUND;
	__u64 count = op_is_reg ? rdx : imm;
	void *dst_ptr = (void *)(heap + DST_OFF);
	void *src_ptr = (void *)(heap + SRC_OFF);
	__u64 ea;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_pattern();
	snapshot_expect();

	/* Plant the destination pointer (RDI), the source pointer / fill value
	 * (RSI), and, for the register-count opcodes, the length (RDX). */
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, dst_ptr, rdi_tag);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI,
				    op_is_copy ? src_ptr
					       : (void *)(long)fill_value,
				    X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, rdx, X86_WIDTH_64);

	/* ---- independent byte model of the bounded region ---- */
	for (i = 0; i < bound && (__u64)i < count; i++) {
		if (op_is_copy)
			exp_heap[DST_OFF + i] = heap[SRC_OFF + i];
		else
			exp_heap[DST_OFF + i] = (__u8)(fill_value & 0xffULL);
	}

	/* ---- run the real body ---- */
	if (op_is_copy && !op_is_reg)
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
	if (X86_SIM_L_REG_TAG(X86_RAX) != X86_SIM_L_REG_TAG(X86_RDI)) {
		printf("MISMATCH %s rax tag=%u want=%u\n", what,
		       X86_SIM_L_REG_TAG(X86_RAX), X86_SIM_L_REG_TAG(X86_RDI));
		failures++;
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
	cases++;
	if (KPROG_X86_CALLMEM_BOUND_FORM(1) != KPROG_X86_CALLMEM_BOUND_IMM ||
	    KPROG_X86_CALLMEM_BOUND_FORM(0) != KPROG_X86_CALLMEM_BOUND_FIXED) {
		printf("MISMATCH bound form\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CALLMEM_FIXED_BOUND != 1024U) {
		printf("MISMATCH fixed bound=%u\n", KPROG_X86_CALLMEM_FIXED_BOUND);
		failures++;
	}
}

int main(void)
{
	__u8 tags[] = { X86_SIM_TAG_SCALAR, X86_SIM_TAG_MAP_VALUE };
	unsigned t;

	/* ---- copy opcodes: source bytes move byte by byte ---- */
	/* MEMCPY: immediate count, flat. */
	check_op("memcpy/imm", 1, 0, 16, 0, 0, X86_SIM_TAG_SCALAR);
	/* MEMCPY: immediate count *larger* than the literal bound, so a
	 * bound-form swap to the artifact would write past 1024 bytes. */
	check_op("memcpy/imm/over", 1, 0, 2000, 0, 0, X86_SIM_TAG_SCALAR);
	/* MEMCPY: immediate count smaller than the bound. */
	check_op("memcpy/imm/small", 1, 0, 4, 0, 0, X86_SIM_TAG_SCALAR);
	/* MEMCPY_REG: register count; artifact is the bound. */
	check_op("memcpy/reg", 1, 1, 32, 16, 0, X86_SIM_TAG_SCALAR);
	check_op("memcpy/reg/zero", 1, 1, 32, 0, 0, X86_SIM_TAG_SCALAR);
	/* MEMCPY_REG with RDX *larger* than the artifact, so both a
	 * bound-form swap (to the literal 1024) and a count-source swap (to
	 * the artifact) write a different region than the artifact-bounded
	 * min(imm, rdx). */
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

	if (failures != 0) {
		printf("x86 callmem route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 callmem route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
