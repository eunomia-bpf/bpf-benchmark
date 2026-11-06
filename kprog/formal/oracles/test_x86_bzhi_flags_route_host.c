/*
 * Host cross-check for the x86 simulator's *routing* of the `BZHI`/`BZHI_MEM`
 * flag block through the generated `KPROG_X86_SET_BZHI_FLAGS` contract.
 *
 * The pre-existing `test_x86_bzhi_route_host.c` drives both bodies and models
 * the whole flag block, but it plants one count/scalar pair whose byte-masked
 * count is always >= the width's bit count and whose source is always
 * nonzero, so `CF` is constant 1 and `ZF` is constant 0 there: it cannot
 * observe the two comparisons the flag block actually performs. This oracle
 * sweeps the count across every width's bit count and drives the source to
 * values whose bit-clear result is zero, so both the `CF` (`count >= bits`)
 * and `ZF` (`result == 0`) boundaries are numerically exercised.
 *
 * It includes the *simulator* header and runs the real bodies through the
 * dispatcher, comparing all four flags and the whole register file against an
 * independent byte model.
 *
 * Build/run:
 *   cd kprog/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_bzhi_flags_route_host.c -o /tmp/t_bzhi_flags_route && \
 *       /tmp/t_bzhi_flags_route
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

static int failures;
static unsigned long cases;

#define MEM_BYTES 4096U
#define MEM_BASE_OFF 64U

static __u8 mem[MEM_BYTES];

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

/* The width mask, restated from the raw codes rather than the generated
 * x86_width.h. */
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

/* The partial-register writeback the body performs. */
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
 * Run one flag-block case through the real routed body and compare the whole
 * state against the independent model. `op_is_mem` selects `BZHI_MEM` (1) vs
 * `BZHI` (0); `count_val` is planted in the register the opcode's contract
 * names as its count source; `src_val` is the register form's source (the
 * memory form ignores it and reads the buffer at `disp`).
 */
static void check_step(unsigned op_is_mem, unsigned flags, unsigned src_reg,
		       unsigned count_reg, unsigned dst_reg, __u64 src_val,
		       __u64 count_val, __s64 disp)
{
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 imm = (__u64)(__s64)disp;
	__u32 aux = op_is_mem ?
		(X86_MEM_AUX_FULL(X86_REG_NONE, 0U, flags) |
		 X86_REG_AUX_SRC_SHIFT(count_reg)) :
		flags;
	__u64 value;
	__u64 result;
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
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	for (i = 0; i < 16U; i++) {
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)pattern_reg(i),
					    pattern_tag(i));
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}
	/* The register form's source: the requested value, so its bit-clear
	 * result (and therefore ZF) is exercised on both sides of zero. */
	value = src_val;
	if (!op_is_mem) {
		X86_SIM_L_WRITE_REG_PTR_TAG(src_reg, (void *)(long)src_val,
					    pattern_tag(src_reg));
		mreg[src_reg] = src_val;
		mtag[src_reg] = pattern_tag(src_reg);
	}
	/* The count source register gets the requested byte-masked count; its
	 * upper bytes carry 0x5a so a mask wider than 0xff is caught. */
	count_val = 0x5a5a5a5a000ULL | (count_val & 0xffULL);
	X86_SIM_L_WRITE_REG_PTR_TAG(count_reg, (void *)(long)count_val,
				    pattern_tag(count_reg));
	mreg[count_reg] = count_val;
	mtag[count_reg] = pattern_tag(count_reg);

	if (op_is_mem) {
		X86_SIM_L_WRITE_REG_PTR_TAG(src_reg,
					    (void *)(long)(mem + MEM_BASE_OFF),
					    X86_SIM_TAG_SCALAR);
		mreg[src_reg] = (__u64)(long)(mem + MEM_BASE_OFF);
		mtag[src_reg] = X86_SIM_TAG_SCALAR;
	}
	for (i = 0; i < MEM_BYTES; i++)
		mem[i] = pattern_byte(i);

	/* A nonzero starting flag state, so a cleared flag is a real
	 * transition. */
	__x86_cf = 1U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;

	/* ---- independent model of the bit-clear and its flag block ---- */
	if (op_is_mem)
		value = model_load((const __u8 *)(long)mreg[src_reg] + disp, w);
	result = model_bzhi(value, count_val, w);
	mreg[dst_reg] = model_write(mreg[dst_reg], result, w);
	mtag[dst_reg] = X86_SIM_TAG_SCALAR;
	mcf = (__u8)((count_val & 0xffULL) >= model_bits(w));
	mzf = (__u8)(result == 0U);
	msf = 0U;
	mof = 0U;

	/* ---- run the real routed body ---- */
	if (op_is_mem)
		X86_SIM_L_EXEC(X86_OP_BZHI_MEM, dst_reg, src_reg, flags, aux,
			       imm);
	else
		X86_SIM_L_EXEC(X86_OP_BZHI, dst_reg, src_reg, flags, count_reg,
			       0ULL);

	/* ---- compare the whole register file ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH mem=%u flags=%u src=%u cnt=%u dst=%u "
			       "count=0x%llx reg%u: got 0x%llx want 0x%llx\n",
			       op_is_mem, flags, src_reg, count_reg, dst_reg,
			       (unsigned long long)count_val, i,
			       (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH mem=%u flags=%u reg%u tag: got %u "
			       "want %u\n", op_is_mem, flags, i, got_tag,
			       mtag[i]);
			failures++;
			return;
		}
	}

	/* ---- compare the flags ---- */
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH mem=%u flags=%u src=%u cnt=%u dst=%u "
		       "count=0x%llx flags: got cf=%u zf=%u sf=%u of=%u "
		       "want cf=%u zf=%u sf=%u of=%u\n",
		       op_is_mem, flags, src_reg, count_reg, dst_reg,
		       (unsigned long long)count_val, __x86_cf, __x86_zf,
		       __x86_sf, __x86_of, mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed flag wrapper's opcodes must agree with the raw codes the arms
 * are dispatched under. */
static void check_contract(void)
{
	cases++;
	if (X86_OP_BZHI != 0x34U || X86_OP_BZHI_MEM != 0x35U) {
		printf("MISMATCH opcode codes\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	/* Counts that straddle every width's bit count (8/16/32/64), so the
	 * CF boundary `count >= bits` is exercised on both sides. */
	static const __u64 counts[14] = {
		0ULL, 1ULL, 7ULL, 8ULL, 9ULL, 15ULL, 16ULL, 17ULL,
		31ULL, 32ULL, 33ULL, 63ULL, 64ULL, 0xffULL,
	};
	/* Sources whose bit-clear result is zero for the low counts (the ZF
	 * boundary) and nonzero for the high ones. */
	static const __u64 sources[4] = {
		0x00000000000000ffULL, 0xffffffffffffffffULL,
		0x0000000000000001ULL, 0x8000000000000000ULL,
	};
	static const __s64 disps[2] = { 0, 4 };
	static const unsigned src_regs[2] = { X86_RAX, X86_RSI };
	static const unsigned count_regs[2] = { X86_R8, X86_R9 };
	static const unsigned dst_regs[2] = { X86_RCX, X86_RDX };
	unsigned op;
	unsigned fi;
	unsigned ci;
	unsigned si;
	unsigned di;

	for (op = 0; op < 2U; op++) {
		for (fi = 0; fi < 5U; fi++) {
			for (ci = 0; ci < 14U; ci++) {
				for (si = 0; si < 4U; si++) {
					for (di = 0; di < 2U; di++) {
						check_step(op, flags_codes[fi],
							   src_regs[si & 1U],
							   count_regs[si & 1U],
							   dst_regs[di],
							   sources[si],
							   counts[ci],
							   disps[op ?
								 (ci & 1U) :
								 0U]);
					}
				}
			}
		}
	}

	check_contract();

	if (failures != 0) {
		printf("x86 bzhi flags route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 bzhi flags route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
