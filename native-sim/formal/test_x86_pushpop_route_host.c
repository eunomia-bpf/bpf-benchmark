/*
 * Host cross-check for the x86 simulator's routing of the two stack-transfer
 * bodies `X86_SIM_L_EXEC_PUSH` and `X86_SIM_L_EXEC_POP` through the
 * machine-checked `KPROG_X86_PUSH_*` contract.
 *
 * Both bodies now compose one `X86_SIM_L_EXEC_PUSH_POP_STEP` that selects the
 * step direction through `KPROG_X86_PUSH_STEP_DIRECTION`, the body that
 * honours the `FLAGS` code through `KPROG_X86_PUSH_WIDTH_SOURCE`, the absent
 * `FLAGS` default through `KPROG_X86_PUSH_FLAGS_WIDTH`, and the stack step
 * amount through `KPROG_X86_PUSH_STACK_STEP`. This oracle includes the
 * *simulator* header so it drives those real bodies rather than a
 * restatement, and compares the whole register file, the whole stack frame,
 * the stack pointer, and the flags against an independent byte model.
 *
 * Unlike the pre-existing `test_x86_pushpop_host.c` (which checks the
 * contract tables plus a model but never includes the simulator header), this
 * oracle covers the routing the two bodies now perform. It plants, per
 * opcode, cases where each routed fact is *numerically distinguishable* from
 * the wrong selection: a `PUSH` carrying a narrow `FLAGS` code must still move
 * the stack pointer by eight and store all eight bytes, a `POP` carrying the
 * absent code must still read and write eight bytes, and a direction swap
 * must move the stack pointer the opposite way.
 *
 * Build/run:
 *   cd native-sim/formal
 *   gcc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *       -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *       test_x86_pushpop_route_host.c -o /tmp/t_ppr && /tmp/t_ppr
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

#define FRAME X86_SIM_STACK_BYTES

/* Deterministic patterns for the modeled register file and stack frame. */
static __u64 pattern_reg(unsigned i)
{
	return 0x100000ULL + (__u64)i * 0x1000ULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static __u8 pattern_byte(unsigned i)
{
	return (__u8)((i * 37U + 11U) ^ (i >> 2));
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

/* The stack helper's store, restated: the frame index is the stack-relative
 * offset biased by the frame size, and the value is width-masked and written
 * little-endian. */
static void model_store(__u8 *frame, __s64 off, unsigned width, __u64 value)
{
	__u32 index = (__u32)((__s64)off + FRAME);
	__u64 narrowed = value & model_mask(width);
	unsigned i;

	for (i = 0; i < width; i++)
		frame[index + i] = (__u8)(narrowed >> (8 * i));
}

/* The stack helper's load, restated. */
static __u64 model_load(const __u8 *frame, __s64 off, unsigned width)
{
	__u32 index = (__u32)((__s64)off + FRAME);
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)frame[index + i] << (8 * i);
	return v & model_mask(width);
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

/* Plant every register in the sim with the deterministic model value. */

/*
 * Run one stack-transfer body over the modeled register file and frame and
 * compare the whole state against the independent model.
 *
 * `op_is_pop` selects `POP` (1) vs `PUSH` (0); `flags` is the opcode's FLAGS
 * code; `src` is the register `PUSH` reads; `dst` is the register `POP`
 * writes; `rsp` is the stack pointer before the step.
 */
static void check_step(const char *what, unsigned op_is_pop, unsigned flags,
		       unsigned src, unsigned dst, __s64 rsp,
		       unsigned via_dispatch)
{
	__u64 mreg[16];
	__u8 mtag[16];
	__u8 mframe[FRAME];
	__s64 mrsp = rsp;
	unsigned i;
	unsigned w = op_is_pop ? (flags ? flags : X86_WIDTH_64) : X86_WIDTH_64;

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
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP, (void *)(long)rsp, pattern_tag(X86_RSP));
	for (i = 0; i < 16U; i++) {
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}
	mreg[X86_RSP] = (__u64)(long)rsp;
	for (i = 0; i < FRAME; i++) {
		__u8 b = pattern_byte(i);

		mframe[i] = b;
		__x86_stack_mem.b[i] = b;
	}

	/* ---- independent model of the stack-transfer step ---- */
	if (!op_is_pop) {
		__u64 value = mreg[src];

		mreg[X86_RSP] = (__u64)((__s64)mreg[X86_RSP] - 8);
		model_store(mframe, (__s64)mreg[X86_RSP], X86_WIDTH_64,
			    value);
	} else {
		__u64 value = model_load(mframe, (__s64)mreg[X86_RSP], w);

		mreg[dst] = model_write(mreg[dst], value, w);
		mtag[dst] = X86_SIM_TAG_SCALAR;
		mreg[X86_RSP] = (__u64)((__s64)mreg[X86_RSP] + 8);
	}
	mrsp = (__s64)mreg[X86_RSP];

	/* ---- run the real body ---- */
	if (!op_is_pop) {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_PUSH, X86_REG_NONE, src, 0U, 0U,
				       0U);
		else
			X86_SIM_L_EXEC_PUSH(src);
	} else {
		if (via_dispatch)
			X86_SIM_L_EXEC(X86_OP_POP, dst, X86_REG_NONE, flags,
				       0U, 0U);
		else
			X86_SIM_L_EXEC_POP(dst, flags);
	}

	/* ---- compare the stack pointer ---- */
	cases++;
	if ((__s64)(long)__x86_rsp.ptr != mrsp) {
		printf("MISMATCH %s pop=%u flags=%u rsp=%lld: got %lld want %lld\n",
		       what, op_is_pop, flags, (long long)rsp,
		       (long long)(__s64)(long)__x86_rsp.ptr, (long long)mrsp);
		failures++;
		return;
	}

	/* ---- compare the whole register file ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH %s pop=%u flags=%u rsp=%lld reg%u: "
			       "got 0x%llx want 0x%llx\n",
			       what, op_is_pop, flags, (long long)rsp, i,
			       (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH %s pop=%u flags=%u rsp=%lld reg%u tag: "
			       "got %u want %u\n",
			       what, op_is_pop, flags, (long long)rsp, i,
			       got_tag, mtag[i]);
			failures++;
			return;
		}
	}

	/* ---- compare the whole stack frame ---- */
	cases++;
	for (i = 0; i < FRAME; i++) {
		if (__x86_stack_mem.b[i] != mframe[i]) {
			printf("MISMATCH %s pop=%u flags=%u rsp=%lld "
			       "frame[%u]=0x%02x want=0x%02x\n",
			       what, op_is_pop, flags, (long long)rsp, i,
			       __x86_stack_mem.b[i], mframe[i]);
			failures++;
			return;
		}
	}

	/* ---- neither body writes a flag ---- */
	cases++;
	if (__x86_cf != 0 || __x86_zf != 0 || __x86_sf != 0 || __x86_of != 0) {
		printf("MISMATCH %s pop=%u flags=%u rsp=%lld wrote a flag\n",
		       what, op_is_pop, flags, (long long)rsp);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_PUSH_STEP_DIRECTION(0U) !=
		    KPROG_X86_PUSH_STEP_PRE_DECREMENT ||
	    KPROG_X86_PUSH_STEP_DIRECTION(1U) !=
		    KPROG_X86_PUSH_STEP_POST_INCREMENT) {
		printf("MISMATCH step direction\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_PUSH_WIDTH_SOURCE(0U) !=
		    KPROG_X86_PUSH_WIDTH_HARDCODED_64 ||
	    KPROG_X86_PUSH_WIDTH_SOURCE(1U) !=
		    KPROG_X86_PUSH_WIDTH_FLAGS_OR_64) {
		printf("MISMATCH width source\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_PUSH_FLAGS_WIDTH(0U) != KPROG_X86_PUSH_FLAGS_RESOLVED ||
	    KPROG_X86_PUSH_FLAGS_WIDTH(1U) != KPROG_X86_PUSH_FLAGS_ABSENT) {
		printf("MISMATCH flags width\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_PUSH_STACK_STEP != 8U) {
		printf("MISMATCH stack step=%u\n", KPROG_X86_PUSH_STACK_STEP);
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 rsp_values[5] = { -8, -16, -24, -32, -56 };
	static const unsigned src_regs[3] = { X86_RAX, X86_RSP, X86_R15 };
	static const unsigned dst_regs[3] = { X86_RCX, X86_RSP, X86_RDX };
	unsigned op;
	unsigned fi;
	unsigned ri;
	unsigned si;
	unsigned di;
	unsigned via;

	/* Drive the bodies both directly and through the `X86_SIM_L_EXEC`
	 * dispatcher arms that route to them. */
	for (via = 0; via < 2U; via++) {
		for (op = 0; op < 2U; op++) {
			for (fi = 0; fi < 5U; fi++) {
				for (ri = 0; ri < 5U; ri++) {
					for (si = 0; si < 3U; si++) {
						for (di = 0; di < 3U; di++) {
							check_step(
								op ? "pop"
								   : "push",
								op,
								flags_codes[fi],
								src_regs[si],
								dst_regs[di],
								rsp_values[ri],
								via);
						}
					}
				}
			}
		}
	}

	check_selectors();

	if (failures != 0) {
		printf("x86 pushpop route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 pushpop route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
