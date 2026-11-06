/*
 * Host cross-check for the x86 simulator's routing of the register-write
 * width body selection (STEP 0145).
 *
 * The simulator routes its `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` macro through the
 * generated contract in `generated/x86_write_width_arm.h`: it selects between
 * four GPR writeback bodies on the resolved operand width — the byte body at
 * the 8-bit code, the word body at the 16-bit code, the dword body at the
 * 32-bit code, and the qword body at every other code. This oracle drives the
 * real routed macro over every GPR at every resolved width (including the
 * absent `0`, which the effective-width bridge turns into the qword code),
 * restates each body's *observable* writeback from the raw width, and compares
 * the whole register file value and tag. Every body writes the destination
 * register differently (a single byte lane, the low word, the low dword, or the
 * full register), so a wrong selector code or a swapped body is caught. Exit 1
 * on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I$(LIBBPF_INC) test_x86_write_width_arm_route_host.c -o /tmp/t_wwwr
 *   /tmp/t_wwwr
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

static int failures;
static unsigned long cases;

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[16];
static __u8 mtag[16];

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so the writeback's
 * scalarization is observable. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The resolved width code the body operates at: the absent code (0) falls back
 * to the 64-bit default, every other code is used as decoded. */
static unsigned resolve_width(unsigned width)
{
	return width ? width : X86_WIDTH_64;
}

/* The independent body selector: a resolved width code names the byte/word/
 * dword bodies exactly at their own 8/16/32-bit codes, and the qword body at
 * every other code (including the absent `0`). Each body is named by the
 * generated contract's own code, so the model and the contract cannot drift. */
static unsigned model_arm(unsigned width)
{
	if (width == X86_WIDTH_8)
		return KPROG_X86_WRITE_WIDTH_ARM_B8;
	if (width == X86_WIDTH_16)
		return KPROG_X86_WRITE_WIDTH_ARM_B16;
	if (width == X86_WIDTH_32)
		return KPROG_X86_WRITE_WIDTH_ARM_B32;
	return KPROG_X86_WRITE_WIDTH_ARM_B64;
}

/* The observable writeback each body performs on the destination register: the
 * byte body replaces the single byte lane the destination shift names (keeping
 * the other seven bytes), the word body replaces the low word (keeping the
 * upper six bytes), the dword body replaces the low dword and zeroes the upper
 * half, and the qword body replaces the whole register. */
static __u64 model_writeback(__u64 old, __u64 v, unsigned width, unsigned shift)
{
	if (model_arm(width) == KPROG_X86_WRITE_WIDTH_ARM_B8) {
		unsigned lane = shift == 8U ? 1U : 0U;
		__u64 mask = 0xffULL << (lane * 8U);
		__u64 byte = (v & 0xffULL) << (lane * 8U);

		return (old & ~mask) | byte;
	}
	if (model_arm(width) == KPROG_X86_WRITE_WIDTH_ARM_B16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (model_arm(width) == KPROG_X86_WRITE_WIDTH_ARM_B32)
		return v & 0xffffffffULL;
	return v;
}

/* Plant the deterministic pattern in the simulator state and the model file. */
#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u8 __pl_t = pattern_tag(__pl_i);                \
			X86_SIM_L_WRITE_REG_PTR_TAG(__pl_i,               \
				(void *)(long)pattern_reg(__pl_i), __pl_t);\
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = __pl_t;                            \
		}                                                         \
	} while (0)

/* Compare the whole register file after a case: every cell must match the
 * model in value and tag, so no third cell moved. */
#define COMPARE_ALL(REG, WIDTH, SHIFT)                                     \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH reg=%u width=%u shift=%u r%u: "\
				       "got 0x%llx want 0x%llx\n",         \
				       (REG), (WIDTH), (SHIFT),            \
				       (unsigned)__ca_i,                   \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH reg=%u width=%u shift=%u r%u "\
				       "tag: got %u want %u\n",            \
				       (REG), (WIDTH), (SHIFT),            \
				       (unsigned)__ca_i,                   \
				       __ca_tag, mtag[__ca_i]);            \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/* Run one write case over the modeled register file and compare. */
static void check_write(unsigned reg, unsigned width, unsigned shift, __u64 value)
{
	unsigned w = resolve_width(width);

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	PLANT_REGS();

	/* ---- independent model ---- */
	if (w == X86_WIDTH_8 || w == X86_WIDTH_16 || w == X86_WIDTH_32 ||
	    w == X86_WIDTH_64) {
		mreg[reg] = model_writeback(mreg[reg], value, w, shift);
		mtag[reg] = X86_SIM_TAG_SCALAR;
	} else {
		/* An effective width outside the four codes: the contract's
		 * default qword body replaces the whole register. */
		mreg[reg] = value;
		mtag[reg] = X86_SIM_TAG_SCALAR;
	}

	/* ---- run the real routed macro ---- */
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT(reg, value, width, shift);

	COMPARE_ALL(reg, width, shift);
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	static const unsigned widths[] = {
		X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	size_t i;

	cases++;
	if (KPROG_X86_WRITE_WIDTH_ARM_COUNT != 4U) {
		printf("MISMATCH write width contract constant drift\n");
		failures++;
	}

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		unsigned w = widths[i];
		unsigned arm = KPROG_X86_WRITE_WIDTH_ARM((__u8)w);
		unsigned want = model_arm(w);

		cases++;
		if (arm != want) {
			printf("MISMATCH write width selector width=%u "
			       "got=%u want=%u\n", w, arm, want);
			failures++;
		}
	}

	/* The absent code (and any other non-byte/word/dword code) reaches the
	 * default qword body, exactly as the model does. */
	cases++;
	if (KPROG_X86_WRITE_WIDTH_ARM(0U) != KPROG_X86_WRITE_WIDTH_ARM_B64 ||
	    KPROG_X86_WRITE_WIDTH_ARM(3U) != KPROG_X86_WRITE_WIDTH_ARM_B64 ||
	    KPROG_X86_WRITE_WIDTH_ARM(5U) != KPROG_X86_WRITE_WIDTH_ARM_B64) {
		printf("MISMATCH write width default body drift\n");
		failures++;
	}
}

int main(void)
{
	/* The resolved width codes, including the absent code 0. */
	static const unsigned width_codes[6] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64, 3U,
	};
	/* The destination shifts the byte body can take. */
	static const unsigned shifts[2] = { 0U, 8U };
	/* Values spanning the width truncation boundaries, all with high bits
	 * set so a narrow write is observable against the pattern. */
	static const __u64 values[5] = {
		0ULL, 0xffULL, 0x1234ULL, 0x89abcdefULL, 0xffffffffffffffffULL,
	};
	unsigned r;
	unsigned f;
	unsigned s;
	unsigned v;

	check_selectors();

	for (r = 0; r < 16U; r++)
		for (f = 0; f < 6U; f++)
			for (s = 0; s < 2U; s++)
				for (v = 0; v < 5U; v++)
					check_write(r, width_codes[f], shifts[s],
						    values[v]);

	if (failures != 0) {
		printf("x86 write width route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 write width route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
