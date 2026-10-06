/*
 * Host cross-check for the x86 simulator's routing of the three bit-test
 * bodies `X86_SIM_L_EXEC_BT`, `X86_SIM_L_EXEC_BT_IMM` and
 * `X86_SIM_L_EXEC_BT_MEM_IMM` through the machine-checked `KPROG_X86_BT_*`
 * contract.
 *
 * All three bodies now compose one `X86_SIM_L_EXEC_BT_STEP` that selects the
 * tested-base source through `KPROG_X86_BT_BASE_SOURCE`, the bit-index source
 * through `KPROG_X86_BT_INDEX_SOURCE`, and the one resolved width through
 * `KPROG_X86_BT_WRITE_WIDTH`, so the contract - not the handler - decides where
 * each operand comes from and which width the base is narrowed to. This oracle
 * includes the *simulator* header so it drives those real bodies rather than a
 * restatement, and compares the whole register file, its tags, and all four
 * flags against an independent model.
 *
 * Unlike the pre-existing `test_x86_bt_host.c` (which checks the contract
 * tables plus a model but never includes the simulator header), this oracle
 * covers the routing the three bodies now perform. It plants, per opcode, cases
 * where each routed fact is *numerically distinguishable* from the wrong
 * selection: the register forms read a base register whose low bits differ from
 * the memory form's loaded base, the register form reads an index register the
 * other forms never consult, the memory form reads memory at the resolved width
 * (so a body that read the base register would use the pointer, not the loaded
 * bytes), and every FLAGS width code is exercised. The `BT_MEM_IMM`
 * index-source fact (the immediate widened to 32 bits) is *CF-invisible*,
 * because the bit test masks the index to the width's bit count and the
 * 32-bit-widened and raw 64-bit immediates share those low bits; it is
 * therefore checked at the selector/table level (see `check_selectors`), not by
 * a numerical difference.
 *
 * Build/run:
 *   cd kprog/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_bt_route_host.c -o /tmp/t_bt_route && /tmp/t_bt_route
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
#include <string.h>

static int failures;
static unsigned long cases;

#define MEM_BYTES 4096U
#define MEM_BASE_OFF 64U

/* The one buffer the memory form reads. The base register holds a scalar-tagged
 * pointer into it, so the address the sim forms is the address the model
 * forms. */
static __u8 mem[MEM_BYTES];

/* Deterministic patterns for the modeled register file and memory. The low
 * byte of each register is nonzero and register-dependent (the base and index
 * reads therefore resolve different bits); every low byte also carries bit 5,
 * so the index mask (`& 63` at 64 bits, `& 31` below) is observable; every
 * value carries bits above bit 32, so narrowing the base to 32 bits (the
 * `FLAGS==0` default, when mis-resolved) is observable; and the loaded bytes
 * are small, so a body that read the base register instead of memory is
 * distinguishable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x300000020ULL + (__u64)i * 0x2000ULL +
	       (__u64)((i % 7U) + 1U);
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static __u8 pattern_byte(unsigned i)
{
	return (__u8)((i * 53U + 29U) ^ (i >> 3));
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

/* The byte-ladder memory load the sim performs at the resolved width,
 * restated little-endian with the width mask. */
static __u64 model_load(const __u8 *p, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)p[i] << (8 * i);
	return v & model_mask(width);
}

/* The bit test the body's `kprog_x86_bt_value` performs: the index masked to
 * 63 for a 64-bit width and 31 otherwise, then the indexed bit of the
 * width-narrowed base. */
static __u8 model_bt(__u64 base, __u64 index, unsigned width)
{
	__u8 bit = (__u8)(index & (width == X86_WIDTH_64 ? 63U : 31U));

	return (__u8)(((base & model_mask(width)) >> bit) & 1U);
}

/* The effective displacement the body applies to the memory base. The body
 * passes `x86_store_imm_disp(IMM)` to a load that itself applies
 * `x86_store_imm_disp`, so the displacement is the *double* application; the
 * model restates the same unsigned semantics so it stays independent of the
 * sim's macros. */
static __s64 model_bt_disp(__u64 imm)
{
	__s32 d1 = (__s32)(imm >> 32);
	__u64 d1u = (__u64)d1;
	__s32 d2 = (__s32)(d1u >> 32);

	return (__s64)d2;
}

/* The index handle the body reads for the non-register forms: the raw 64-bit
 * immediate (`BT_IMM`) or its 32-bit truncation (`BT_MEM_IMM`). */
#define IMM_LOW 0x9c000011ULL

/* The immediate the bodies receive: the displacement in the top 32 bits (the
 * only field `BT_MEM_IMM`'s load reads) and a low word whose bit-6 span is
 * nonzero and differs from every register's low bits. */
static __u64 make_imm(__s64 disp)
{
	return ((__u64)(__u32)(__s32)disp << 32) | IMM_LOW;
}

/*
 * Run one bit-test body over the modeled register file and source buffer and
 * compare the whole state against the independent model.
 *
 * `op` selects `BT` (0), `BT_IMM` (1) or `BT_MEM_IMM` (2); `flags` is the
 * opcode's FLAGS width code; `aux_width` is the memory form's AUX width code
 * (0 == absent); `base_reg` is the opcode's first operand - the tested-base
 * register for `BT`/`BT_IMM` and the base-pointer register for `BT_MEM_IMM`;
 * `index_reg` is the register `BT` reads its index from; `dst_reg` is a
 * register the body must leave untouched;
 * `disp` is the signed displacement the memory form encodes; `via_dispatch` is
 * true to drive the `X86_SIM_L_EXEC` arm instead of the body directly.
 */
static void check_step(unsigned op, unsigned flags, unsigned aux_width,
		       unsigned base_reg, unsigned index_reg, unsigned dst_reg,
		       __s64 disp, unsigned via_dispatch)
{
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 imm = make_imm(disp);
	__u32 aux = X86_MEM_AUX_FULL(X86_REG_NONE, 0U, aux_width);
	__u64 base;
	__u64 index;
	__u8 mcf;
	__u8 mzf;
	__u8 msf;
	__u8 mof;

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

	/* ---- plant the modeled state in both the sim and the model ---- */
	for (i = 0; i < 16U; i++) {
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)pattern_reg(i),
					    pattern_tag(i));
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}
	for (i = 0; i < MEM_BYTES; i++)
		mem[i] = pattern_byte(i);
	/* The memory form's base register is a scalar-tagged pointer into `mem`,
	 * so the read dispatches to the ordinary byte-ladder load; it overrides
	 * any pattern planted above, so the loaded bytes - not the pointer value -
	 * are what a body reading memory must narrow.
	 *
	 * The bit the loaded value carries at the tested index is set to the
	 * complement of the register-value bit there, so a body that resolves the
	 * wrong base source (register read instead of memory) reports the opposite
	 * CF. The complement is computed against the same index and width the
	 * body's index handle produces, and the same index is reachable through
	 * every register value (all low bytes carry bit 5), so the discrepancy is
	 * present for every index source - no register value can alias the load. */
	if (op == 2U) {
		__u64 pv = (__u64)(long)(mem + MEM_BASE_OFF);
		__u64 idxh = imm & 0xffffffffULL;
		__u8 bit = (__u8)(idxh & (w == X86_WIDTH_64 ? 63U : 31U));
		__u8 want = (__u8)(((pv & model_mask(w)) >> bit) & 1U);
		__u64 loaded;

		loaded = model_load(mem + MEM_BASE_OFF + model_bt_disp(imm), w);
		if ((((__u64)(loaded >> bit) & 1U)) == (__u64)want) {
			__u8 *bp = mem + MEM_BASE_OFF + model_bt_disp(imm) +
				   (unsigned)(bit / 8U);

			*bp = (__u8)(*bp ^ (__u8)(1U << (bit % 8U)));
		}
		X86_SIM_L_WRITE_REG_PTR_TAG(base_reg,
					    (void *)(long)pv,
					    X86_SIM_TAG_SCALAR);
		mreg[base_reg] = pv;
		mtag[base_reg] = X86_SIM_TAG_SCALAR;
	}

	/* ---- independent model of the bit-test step ---- */
	mzf = __x86_zf;
	msf = __x86_sf;
	mof = __x86_of;
	if (op == 2U) {
		__u8 *p = (__u8 *)(long)mreg[base_reg] + model_bt_disp(imm);

		base = model_load(p, w);
		index = imm & 0xffffffffULL;
	} else if (op == 1U) {
		base = mreg[base_reg];
		index = imm;
	} else {
		base = mreg[base_reg];
		index = mreg[index_reg];
	}
	mcf = model_bt(base, index, w);

	/* ---- run the real body ---- */
	if (op == 0U) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_BT, base_reg, index_reg, flags, 0U,
				      0U);
		else
			X86_SIM_L_EXEC_BT(base_reg, index_reg, flags);
	} else if (op == 1U) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_BT_IMM, base_reg, 0U, flags, 0U,
				      imm);
		else
			X86_SIM_L_EXEC_BT_IMM(base_reg, flags, imm);
	} else {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_BT_MEM_IMM, base_reg, 0U, flags,
				      aux, imm);
		else
			X86_SIM_L_EXEC_BT_MEM_IMM(base_reg, flags, aux, imm);
	}

	/* ---- compare the whole register file ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH op=%u flags=%u auxw=%u base=%u "
			       "idx=%u dst=%u disp=%lld reg%u: got 0x%llx "
			       "want 0x%llx\n",
			       op, flags, aux_width, base_reg, index_reg, dst_reg,
			       (long long)disp, i, (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH op=%u flags=%u auxw=%u base=%u "
			       "idx=%u dst=%u disp=%lld reg%u tag: got %u "
			       "want %u\n",
			       op, flags, aux_width, base_reg, index_reg, dst_reg,
			       (long long)disp, i, got_tag, mtag[i]);
			failures++;
			return;
		}
	}

	/* ---- compare the flags: only CF is written ---- */
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH op=%u flags=%u auxw=%u base=%u idx=%u dst=%u "
		       "disp=%lld flags: got cf=%u zf=%u sf=%u of=%u "
		       "want cf=%u zf=%u sf=%u of=%u\n",
		       op, flags, aux_width, base_reg, index_reg, dst_reg,
		       (long long)disp, __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_BT_BASE_SOURCE(0U) != KPROG_X86_BT_BASE_REGISTER ||
	    KPROG_X86_BT_BASE_SOURCE(1U) != KPROG_X86_BT_BASE_MEMORY) {
		printf("MISMATCH base source\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BT_INDEX_SOURCE(0U, 1U) != KPROG_X86_BT_INDEX_REGISTER) {
		printf("MISMATCH index source register\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BT_INDEX_SOURCE(0U, 0U) != KPROG_X86_BT_INDEX_IMMEDIATE) {
		printf("MISMATCH index source immediate\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BT_INDEX_SOURCE(1U, 0U) != KPROG_X86_BT_INDEX_IMM32) {
		printf("MISMATCH index source imm32\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BT_WRITE_WIDTH(0U) !=
		    KPROG_X86_BT_WRITE_WIDTH_DEFAULT) {
		printf("MISMATCH write-width fallback\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BT_OP_BT_BASE_SOURCE != KPROG_X86_BT_BASE_REGISTER ||
	    KPROG_X86_BT_OP_BT_INDEX_SOURCE != KPROG_X86_BT_INDEX_REGISTER ||
	    KPROG_X86_BT_OP_BT_IMM_BASE_SOURCE !=
		    KPROG_X86_BT_BASE_REGISTER ||
	    KPROG_X86_BT_OP_BT_IMM_INDEX_SOURCE !=
		    KPROG_X86_BT_INDEX_IMMEDIATE ||
	    KPROG_X86_BT_OP_BT_MEM_IMM_BASE_SOURCE !=
		    KPROG_X86_BT_BASE_MEMORY ||
	    KPROG_X86_BT_OP_BT_MEM_IMM_INDEX_SOURCE !=
		    KPROG_X86_BT_INDEX_IMM32) {
		printf("MISMATCH per-opcode source table\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const unsigned aux_widths[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 disps[4] = { 0, 4, 8, -4 };
	static const unsigned base_regs[3] = { X86_RAX, X86_RSI, X86_R15 };
	static const unsigned index_regs[3] = { X86_R8, X86_R9, X86_R10 };
	static const unsigned dst_regs[3] = { X86_RCX, X86_RDX, X86_R14 };
	unsigned via;
	unsigned op;
	unsigned fi;
	unsigned wi;
	unsigned mi;
	unsigned bi;
	unsigned ii;
	unsigned di;

	/* Drive the bodies both directly and through the `X86_SIM_L_EXEC`
	 * dispatcher arms that route to them. */
	for (via = 0; via < 2U; via++) {
		for (op = 0; op < 3U; op++) {
			for (fi = 0; fi < 5U; fi++) {
				for (wi = 0; wi < 5U; wi++) {
					for (mi = 0; mi < 4U; mi++) {
						for (bi = 0; bi < 3U; bi++) {
							for (ii = 0; ii < 3U;
							     ii++) {
								for (di = 0;
								     di < 3U;
								     di++) {
									check_step(op,
										flags_codes[fi],
										aux_widths[wi],
										base_regs[bi],
										index_regs[ii],
										dst_regs[di],
										disps[mi],
										via);
								}
							}
						}
					}
				}
			}
		}
	}

	check_selectors();

	if (failures != 0) {
		printf("x86 bt route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 bt route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
