/*
 * Host cross-check for the x86 simulator's routing of the `DIV` arm (STEP
 * 0115).
 *
 * The routed arm is the `X86_OP_DIV` branch of `X86_SIM_L_EXEC`, which now
 * selects its quotient/remainder body through the generated `KPROG_X86_DIV_ARM`
 * contract: the byte case at the resolved 8-bit width (divides the low word of
 * `RAX` by the byte divisor and packs the quotient and remainder into `RAX`),
 * the word/dword cases at the 16/32-bit widths (divide `RDX:RAX` and write
 * both registers), and the qword case at every other code (divides `RDX:RAX`,
 * with the complete 128-bit dividend). Zero divisor or a quotient outside the
 * destination width raises a fault before any architectural register write. This oracle drives the real `X86_SIM_L_EXEC` body
 * and restates the effect from the raw register cells and the resolved width;
 * the two must agree on the value *and* tag of every one of the 16 cells, and
 * no third cell may move. It also checks that the routed selector and the
 * generated contract agree. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf test_x86_div_route_host.c -o /tmp/t_div_route
 *   /tmp/t_div_route
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include <setjmp.h>
static jmp_buf divide_fault;
static __u64 fault_values[16];
static __u8 fault_tags[16];
static unsigned fault_flags;

#include "../x86/x86_sim_local_bpf.h"
#include "x86_no_helpers_host.h"

/* Observe the simulator fault at its call site before leaving its local state.
 * Snapshot globals remain defined across longjmp, even if a buggy handler
 * changed a register before raising the fault. No native faulting DIV runs. */
#undef X86_SIM_L_DIVIDE_FAULT
#define X86_SIM_L_DIVIDE_FAULT() do { \
    for (unsigned fault_i = 0; fault_i < 16; ++fault_i) { \
        fault_values[fault_i] = (__u64)(long)X86_SIM_L_REG_VALUE(fault_i); \
        fault_tags[fault_i] = X86_SIM_L_REG_TAG(fault_i); \
    } \
    fault_flags = __x86_cf | __x86_zf | __x86_sf | __x86_of | __x86_af | __x86_pf; \
    longjmp(divide_fault, 1); \
} while (0)


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

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so the quotient and
 * remainder writes' scalarization is observable. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The resolved width code the body operates at: the absent code (0) falls back
 * to the 64-bit default, every other code is used as decoded. */
static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

/* The partial-register writeback the quotient/remainder writes perform: the
 * low `width` bytes are replaced, the higher bytes of an 8- or 16-bit write are
 * kept, and a 32-bit write zeroes the upper half. */
static __u64 model_partial_write(__u64 old, __u64 v, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (old & ~0xffULL) | (v & 0xffULL);
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (width == X86_WIDTH_32)
		return v & 0xffffffffULL;
	return v;
}

/* Restate the routed arm's effect on the modeled register file: the byte case
 * packs quotient and remainder into `RAX` with one 16-bit write, the wider
 * cases write `RAX` (quotient) and `RDX` (remainder) at the access width, and
 * all faults preserve every cell. Every successful written cell is scalarized. */
static int model_div(unsigned srcreg, unsigned flags)
{
    unsigned w = resolve_width(flags);
    unsigned bits = w == X86_WIDTH_8 ? 8 : w == X86_WIDTH_16 ? 16 : w == X86_WIDTH_32 ? 32 : 64;
    __u64 mask = bits == 64 ? ~0ULL : (1ULL << bits)-1;
    __u64 divisor = mreg[srcreg] & mask;
    __u64 rax = mreg[X86_RAX], rdx = mreg[X86_RDX];
    __uint128_t dividend = bits == 8 ? (__u16)rax :
        ((__uint128_t)(rdx & mask) << bits) | (rax & mask);
    if (divisor == 0 || dividend / divisor > mask)
        return 1;
    __u64 q = dividend / divisor, rem = dividend % divisor;
    if (bits == 8) {
        mreg[X86_RAX] = model_partial_write(rax, (rem << 8) | q, X86_WIDTH_16);
        mtag[X86_RAX] = X86_SIM_TAG_SCALAR;
    } else {
        mreg[X86_RAX] = model_partial_write(rax, q, w);
        mreg[X86_RDX] = model_partial_write(rdx, rem, w);
        mtag[X86_RAX] = mtag[X86_RDX] = X86_SIM_TAG_SCALAR;
    }
    return 0;
}

/* Plant a case's operands in the simulator state and the model file: the
 * divisor at `srcreg`, the chosen dividend in `RAX`/`RDX`, the deterministic
 * pattern everywhere else. A macro so it expands in the checker's scope. */
#define PLANT_REGS(RAX, RDX, SRCREG, DIVISOR)                              \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_v = __pl_i == X86_RAX ? (RAX)          \
				: __pl_i == X86_RDX ? (RDX)               \
				: __pl_i == (SRCREG) ? (DIVISOR)          \
				: pattern_reg(__pl_i);                    \
			__u8 __pl_t = pattern_tag(__pl_i);                \
			X86_SIM_L_WRITE_REG_PTR_TAG(__pl_i,               \
				(void *)(long)__pl_v, __pl_t);            \
			mreg[__pl_i] = __pl_v;                            \
			mtag[__pl_i] = __pl_t;                            \
		}                                                         \
	} while (0)

/* Compare the whole register file after a case: every cell must match the
 * model in value and tag, so no third cell moved. */
#define COMPARE_ALL(SRCREG, FLAGS)                                         \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH src=%u flags=%u reg%u: "  \
				       "got 0x%llx want 0x%llx\n",         \
				       (SRCREG), (FLAGS), (unsigned)__ca_i,\
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH src=%u flags=%u reg%u tag: "\
				       "got %u want %u\n",                 \
				       (SRCREG), (FLAGS), (unsigned)__ca_i,\
				       __ca_tag, mtag[__ca_i]);            \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/* Run one `DIV` case over the modeled register file and compare. */
static void check_div(unsigned srcreg, unsigned flags, __u64 rax, __u64 rdx,
		      __u64 divisor)
{
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

	PLANT_REGS(rax, rdx, srcreg, divisor);

	/* ---- independent model ---- */
    int expected_fault = model_div(srcreg, flags);

    /* ---- run the real routed arm, retaining every overflow/zero case ---- */
    if (setjmp(divide_fault) == 0) {
        X86_SIM_L_EXEC(X86_OP_DIV, X86_RCX, srcreg, flags, 0U, 0ULL);
        if (expected_fault) {
            printf("MISMATCH src=%u flags=%u missing divide fault\n", srcreg, flags);
            failures++;
            return;
        }
    } else {
        cases++;
        if (!expected_fault || fault_flags != 0) {
            printf("MISMATCH src=%u flags=%u unexpected/modified divide fault\n", srcreg, flags);
            failures++;
            return;
        }
        for (unsigned i = 0; i < 16; ++i) {
            cases += 2;
            if (fault_values[i] != mreg[i] || fault_tags[i] != mtag[i]) {
                printf("MISMATCH src=%u flags=%u divide fault wrote reg%u\n", srcreg, flags, i);
                failures++;
                return;
            }
        }
        return;
    }

    COMPARE_ALL(srcreg, flags);

	/* The divide never touches the flags. */
	cases++;
	if (__x86_cf != 0U || __x86_zf != 0U || __x86_sf != 0U ||
	    __x86_of != 0U) {
		printf("MISMATCH src=%u flags=%u flags moved\n", srcreg, flags);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	static const unsigned widths[] = {
		X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	size_t i;

	cases++;
	if (KPROG_X86_DIV_ARM_COUNT != 4U) {
		printf("MISMATCH div contract constant drift\n");
		failures++;
	}

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		unsigned w = widths[i];
		unsigned arm = KPROG_X86_DIV_ARM((__u8)w);
		int want = w == X86_WIDTH_8 ? (int)KPROG_X86_DIV_ARM_B8
			: w == X86_WIDTH_16 ? (int)KPROG_X86_DIV_ARM_B16
			: w == X86_WIDTH_32 ? (int)KPROG_X86_DIV_ARM_B32
			: (int)KPROG_X86_DIV_ARM_B64;

		cases++;
		if (arm != (unsigned)want) {
			printf("MISMATCH div selector width=%u got=%u want=%d\n",
			       w, arm, want);
			failures++;
		}
	}
}

int main(void)
{
	/* The resolved width codes, including the absent code 0. */
	static const unsigned flags_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Include zero, narrow truncation and every original nonzero divisor. */
	static const __u64 divisors[] = {
        0ULL,
		1ULL, 2ULL, 7ULL, 0xffULL, 0x01010101ULL,
		0x0102030405060708ULL, 0xffffffffffffffffULL,
	};
	/* Dividends spanning the truncation and overflow boundaries. */
	static const __u64 dividends[7] = {
		0ULL, 1ULL, 0xffffULL, 0xffffffffULL, 0x7fffffffffffffffULL,
		0xffffffffffffffffULL, 0x9f5abf2108f64a04ULL,
	};
	/* The high half, including zero and nonzero full-width dividends. */
	static const __u64 highs[3] = {
		0ULL, 1ULL, 0xffffffffffffffffULL,
	};
	static const unsigned srcregs[] = { X86_RCX, X86_RBX, X86_RAX, X86_RDX };
	unsigned f;
	unsigned s;
	unsigned a;
	unsigned h;
	unsigned d;

	check_selectors();

	for (f = 0; f < 5U; f++)
		for (s = 0; s < sizeof(srcregs)/sizeof(srcregs[0]); s++)
			for (a = 0; a < 7U; a++)
				for (h = 0; h < 3U; h++)
					for (d = 0; d < sizeof(divisors)/sizeof(divisors[0]); d++)
						check_div(srcregs[s],
							  flags_codes[f],
							  dividends[a],
							  highs[h],
							  divisors[d]);

	if (failures != 0) {
		printf("x86 div route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 div route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
