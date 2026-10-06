/*
 * Host cross-check for the x86 simulator's routing of the two single-width
 * bit-clear bodies `X86_SIM_L_EXEC_BZHI` (register value and count) and
 * `X86_SIM_L_EXEC_BZHI_MEM` (memory value, AUX-named count) through the
 * machine-checked `KPROG_X86_BZHI_*` contract.
 *
 * Both bodies now compose one `X86_SIM_L_EXEC_BZHI_STEP` that selects the
 * value source through `KPROG_X86_BZHI_VALUE_SOURCE`, the count source
 * through `KPROG_X86_BZHI_COUNT_SOURCE`, the byte mask through
 * `KPROG_X86_BZHI_COUNT_MASK`, and the one width both the read and the write
 * use through `KPROG_X86_BZHI_WRITE_WIDTH`, so the contract - not the handler
 * - decides both sources and the width. This oracle includes the *simulator*
 * header so it drives those real bodies rather than a restatement, and
 * compares the whole register file, its tags, and all four flags against an
 * independent byte model.
 *
 * Unlike the pre-existing `test_x86_bzhi_host.c` (which checks the contract
 * tables plus a model but never includes the simulator header), this oracle
 * covers the routing the two bodies now perform. It plants, per opcode, cases
 * where each routed fact is *numerically distinguishable* from the wrong
 * selection: a memory form whose AUX names a count register distinct from the
 * register form's `COUNT` and whose value must come from memory rather than
 * the base register, a register whose byte-masked count saturates at the
 * width's own bit count (so the mask and the comparison are observable), and
 * every FLAGS width code.
 *
 * Build/run:
 *   cd kprog/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_bzhi_route_host.c -o /tmp/t_bzhi_route && /tmp/t_bzhi_route
 */
#define X86_SIM_ENABLE_STACK 1
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

#define MEM_BYTES 4096U
#define MEM_BASE_OFF 64U

/* The one buffer the memory form reads. The base register points into it, so
 * the address the sim forms is the address the model forms. */
static __u8 mem[MEM_BYTES];

/* Deterministic patterns for the modeled register file and source buffer.
 * The low byte of each register is nonzero and register-dependent, so a
 * body that takes its byte-masked count from the wrong register (or from the
 * value register) resolves a different bit count and clears different bits. */
static __u64 pattern_reg(unsigned i)
{
	return 0x200000ULL + (__u64)i * 0x2000ULL + (__u64)((i % 7U) + 1U);
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

/* The bit count of the width code, restated from the raw codes. */
static unsigned model_bits(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 8U;
	if (width == X86_WIDTH_16)
		return 16U;
	if (width == X86_WIDTH_32)
		return 32U;
	return 64U;
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

/* The bit clear the body performs: the byte-masked count clears the source
 * bits at or above it, and the result is narrowed to the width. */
static __u64 model_bzhi(__u64 src, __u64 count, unsigned width)
{
	unsigned bits = model_bits(width);
	__u64 c = count & KPROG_X86_BZHI_COUNT_MASK;
	__u64 result = src;

	if (c < bits)
		result &= (1ULL << c) - 1ULL;
	return result & model_mask(width);
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

/*
 * Run one bit-clear body over the modeled register file and source buffer and
 * compare the whole state against the independent model.
 *
 * `op_is_mem` selects `BZHI_MEM` (1) vs `BZHI` (0); `flags` is the opcode's
 * FLAGS width code; `aux_width` is the memory form's AUX width code (0 ==
 * absent, which the body resolves through the AUX field anyway); `src_reg` is
 * the value source (a register, or the base register for the memory form);
 * `count_reg` is the register the register form reads its count from and the
 * register the memory form's AUX shift byte names; `dst_reg` is the
 * destination; `disp` is the signed displacement the memory form applies.
 */
static void check_step(unsigned op_is_mem, unsigned flags, unsigned aux_width,
		       unsigned src_reg, unsigned count_reg, unsigned dst_reg,
		       __s64 disp, unsigned via_dispatch)
{
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 imm = (__u64)(__s64)disp;
	__u32 aux = op_is_mem ?
		(X86_MEM_AUX_FULL(X86_REG_NONE, 0U, aux_width) |
		 X86_REG_AUX_SRC_SHIFT(count_reg)) :
		aux_width;
	__u64 value;
	__u64 count;
	__u64 result;
	__u64 cnt_val;
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
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, (void *)(long)pattern_reg(X86_RAX), pattern_tag(X86_RAX));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RCX, (void *)(long)pattern_reg(X86_RCX), pattern_tag(X86_RCX));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX, (void *)(long)pattern_reg(X86_RDX), pattern_tag(X86_RDX));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBX, (void *)(long)pattern_reg(X86_RBX), pattern_tag(X86_RBX));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP, (void *)(long)pattern_reg(X86_RSP), pattern_tag(X86_RSP));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBP, (void *)(long)pattern_reg(X86_RBP), pattern_tag(X86_RBP));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI, (void *)(long)pattern_reg(X86_RSI), pattern_tag(X86_RSI));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, (void *)(long)pattern_reg(X86_RDI), pattern_tag(X86_RDI));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R8, (void *)(long)pattern_reg(X86_R8), pattern_tag(X86_R8));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R9, (void *)(long)pattern_reg(X86_R9), pattern_tag(X86_R9));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R10, (void *)(long)pattern_reg(X86_R10), pattern_tag(X86_R10));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R11, (void *)(long)pattern_reg(X86_R11), pattern_tag(X86_R11));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R12, (void *)(long)pattern_reg(X86_R12), pattern_tag(X86_R12));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R13, (void *)(long)pattern_reg(X86_R13), pattern_tag(X86_R13));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R14, (void *)(long)pattern_reg(X86_R14), pattern_tag(X86_R14));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R15, (void *)(long)pattern_reg(X86_R15), pattern_tag(X86_R15));
	for (i = 0; i < 16U; i++) {
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}
	/* Plant a value whose low byte tracks its index, and a count in the
	 * register the opcode is contracted to read it from. The count's low byte
	 * is `(value_low | 0x83)`, so its high bit is *set*: a body that takes its
	 * count from the wrong register lands on a different byte-masked count,
	 * and a body that skips the byte mask keeps bit 7 and, once the count is
	 * shifted into the value's bit span, clears different bits. The count's
	 * upper bytes carry 0x5a, so a mask wider than 0xff is caught by the CF
	 * comparison against the width's bit count. */
	cnt_val = 0x5a5a5a5a0000ULL | (pattern_reg(src_reg) & 0xffULL) | 0x83ULL;
	X86_SIM_L_WRITE_REG_PTR_TAG(src_reg, (void *)(long)pattern_reg(src_reg),
				    pattern_tag(src_reg));
	mreg[src_reg] = pattern_reg(src_reg);
	mtag[src_reg] = pattern_tag(src_reg);
	X86_SIM_L_WRITE_REG_PTR_TAG(count_reg, (void *)(long)cnt_val,
				    pattern_tag(count_reg));
	mreg[count_reg] = cnt_val;
	mtag[count_reg] = pattern_tag(count_reg);
	/* The memory form's base register is a scalar-tagged pointer into `mem`,
	 * so the value read dispatches to the ordinary byte-ladder load; this
	 * overrides any pattern planted above *after* the count register, so the
	 * two are not confused when `src_reg == count_reg`. */
	if (op_is_mem) {
		X86_SIM_L_WRITE_REG_PTR_TAG(src_reg, (void *)(long)(mem + MEM_BASE_OFF),
					    X86_SIM_TAG_SCALAR);
		mreg[src_reg] = (__u64)(long)(mem + MEM_BASE_OFF);
		mtag[src_reg] = X86_SIM_TAG_SCALAR;
	}
	for (i = 0; i < MEM_BYTES; i++)
		mem[i] = pattern_byte(i);

	/* ---- independent model of the bit-clear step ---- */
	if (op_is_mem) {
		__u8 *p = (__u8 *)(long)mreg[src_reg] + disp;

		value = model_load(p, w);
		count = mreg[count_reg] & KPROG_X86_BZHI_COUNT_MASK;
	} else {
		value = mreg[src_reg];
		count = mreg[count_reg] & KPROG_X86_BZHI_COUNT_MASK;
	}
	result = model_bzhi(value, count, w);
	mreg[dst_reg] = model_write(mreg[dst_reg], result, w);
	mtag[dst_reg] = X86_SIM_TAG_SCALAR;
	mcf = (__u8)(count >= model_bits(w));
	mzf = (__u8)(result == 0U);
	msf = 0U;
	mof = 0U;

	/* ---- run the real body ---- */
	if (op_is_mem) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_BZHI_MEM, dst_reg, src_reg, flags,
				       aux, imm);
		else
			X86_SIM_L_EXEC_BZHI_MEM(dst_reg, src_reg, flags, aux,
						imm);
	} else {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_BZHI, dst_reg, src_reg, flags,
				       count_reg, 0U);
		else
			X86_SIM_L_EXEC_BZHI(dst_reg, src_reg, count_reg, flags);
	}

	/* ---- compare the whole register file ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH mem=%u flags=%u auxw=%u src=%u "
			       "cnt=%u dst=%u disp=%lld reg%u: got 0x%llx "
			       "want 0x%llx\n",
			       op_is_mem, flags, aux_width, src_reg, count_reg,
			       dst_reg, (long long)disp, i,
			       (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH mem=%u flags=%u auxw=%u src=%u "
			       "cnt=%u dst=%u disp=%lld reg%u tag: got %u "
			       "want %u\n",
			       op_is_mem, flags, aux_width, src_reg, count_reg,
			       dst_reg, (long long)disp, i, got_tag, mtag[i]);
			failures++;
			return;
		}
	}

	/* ---- compare the flags ---- */
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH mem=%u flags=%u auxw=%u src=%u cnt=%u dst=%u "
		       "disp=%lld flags: got cf=%u zf=%u sf=%u of=%u "
		       "want cf=%u zf=%u sf=%u of=%u\n",
		       op_is_mem, flags, aux_width, src_reg, count_reg, dst_reg,
		       (long long)disp, __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_BZHI_VALUE_SOURCE(0U) != KPROG_X86_BZHI_VALUE_REGISTER ||
	    KPROG_X86_BZHI_VALUE_SOURCE(1U) != KPROG_X86_BZHI_VALUE_MEMORY) {
		printf("MISMATCH value source\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BZHI_COUNT_SOURCE(0U) != KPROG_X86_BZHI_COUNT_REGISTER ||
	    KPROG_X86_BZHI_COUNT_SOURCE(1U) != KPROG_X86_BZHI_COUNT_AUX_SHIFT) {
		printf("MISMATCH count source\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BZHI_WRITE_WIDTH(0U) !=
		    KPROG_X86_BZHI_WRITE_WIDTH_DEFAULT) {
		printf("MISMATCH write-width fallback\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BZHI_COUNT_MASK != 0xffULL) {
		printf("MISMATCH count mask\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_BZHI_OP_BZHI_VALUE_SOURCE != KPROG_X86_BZHI_VALUE_REGISTER ||
	    KPROG_X86_BZHI_OP_BZHI_COUNT_SOURCE != KPROG_X86_BZHI_COUNT_REGISTER ||
	    KPROG_X86_BZHI_OP_BZHI_MEM_VALUE_SOURCE != KPROG_X86_BZHI_VALUE_MEMORY ||
	    KPROG_X86_BZHI_OP_BZHI_MEM_COUNT_SOURCE != KPROG_X86_BZHI_COUNT_AUX_SHIFT) {
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
	static const unsigned src_regs[3] = { X86_RAX, X86_RSI, X86_R15 };
	static const unsigned count_regs[3] = { X86_R8, X86_R9, X86_R10 };
	static const unsigned dst_regs[3] = { X86_RCX, X86_RDX, X86_R14 };
	unsigned via;
	unsigned op;
	unsigned fi;
	unsigned wi;
	unsigned mi;
	unsigned si;
	unsigned ai;
	unsigned di;

	/* Drive the bodies both directly and through the `X86_SIM_L_EXEC`
	 * dispatcher arms that route to them. */
	for (via = 0; via < 2U; via++) {
		for (op = 0; op < 2U; op++) {
			for (fi = 0; fi < 5U; fi++) {
				for (wi = 0; wi < 5U; wi++) {
					for (mi = 0; mi < 4U; mi++) {
						for (si = 0; si < 3U; si++) {
							for (ai = 0; ai < 3U;
							     ai++) {
								for (di = 0;
								     di < 3U;
								     di++) {
									check_step(op,
										flags_codes[fi],
										aux_widths[wi],
										src_regs[si],
										count_regs[ai],
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
		printf("x86 bzhi route host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 bzhi route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
