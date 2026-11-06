/*
 * Host cross-check for the x86 simulator's routing of the move-with-extension
 * register-source op-step result (STEP 0157).
 *
 * Drives the *inline* MOVX register arm body of the routed dispatcher
 * `X86_SIM_L_EXEC` in `x86/x86_sim_local_bpf.h` (the last remaining x86
 * dispatcher arm from the Steps 0154/0155/0156 route family whose body route
 * was not yet closed) -- the same body the member opcodes
 * `X86_OP_MOVZX_REG` (0x20) and `X86_OP_MOVSX_REG` (0x21) of the dispatcher's
 * `movxReg` family arm execute -- and compares its whole effect (the sixteen
 * register values, their tags, and the four flag bytes) against an
 * independent model restated from the raw macros:
 *
 *   - the body reads the source register whole at 64 bits, resolves the
 *     extension width through the generated `KPROG_X86_MOVX_SRC_WIDTH`
 *     contract (the decoded AUX source-width lane unless it is the absent
 *     code, in which case the FLAGS-resolved effective width), selects the
 *     extension function through the generated `KPROG_X86_MOVX_SHAPE`
 *     contract on the opcode (the sign extension at `X86_OP_MOVSX_REG`, the
 *     zero extension at every other opcode), and writes the widened value
 *     back with the plain width-local partial-register write;
 *   - every form writes no flag byte: the four planted flag bytes must be
 *     returned unchanged in both directions; no memory write exists;
 *   - the widened values are restated from the generated width and sign
 *     contracts' independent formulas (never the macro's own helpers), so a
 *     wrong shape selection, a wrong source-width lane, a dropped
 *     absent-code fallback, or a narrowed writeback is numerically
 *     distinguishable.
 *
 * Every case is driven through the real dispatcher arm `X86_SIM_L_EXEC` (the
 * body is inline in the dispatcher, so the dispatch route is the only body
 * route), with the register file, tags, and flags planted before the run and
 * compared after it.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_movx_route_host.c \
 *      -o build/test_x86_movx_route_host \
 *      && ./build/test_x86_movx_route_host
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

static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mcf, mzf, msf, mof;

#define DST_REG X86_R9
#define SRC_REG X86_R10

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

static __u64 width_sign(unsigned width)
{
	return width == X86_WIDTH_8 ? 0x80ULL :
	       width == X86_WIDTH_16 ? 0x8000ULL :
	       width == X86_WIDTH_32 ? 0x80000000ULL :
	       0x8000000000000000ULL;
}

/* The independent zero extension: mask to the source width (a width-8 mask
 * is already the byte the model needs).  */
static __u64 model_zero_extend(__u64 value, unsigned width)
{
	return value & width_mask(width);
}

/* The independent sign extension: narrow to the source width, then fan the
 * sign bit across the rest of the 64-bit lane. */
static __u64 model_sign_extend(__u64 value, unsigned width)
{
	__u64 narrowed = value & width_mask(width);

	if (narrowed & width_sign(width))
		return narrowed | ~width_mask(width);
	return narrowed;
}

/* The independent width-local partial-register write the body's
 * `X86_SIM_L_WRITE_REG_WIDTH` writeback performs at destination shift
 * zero: the byte code writes one byte lane (the returned value's lane
 * zero), the word code writes the low word preserving the upper bytes, the
 * dword code zero-extends, and the qword code writes the lane. The write
 * also scalarizes the destination tag. */
static __u64 model_partial_write(__u64 old, __u64 value, unsigned width)
{
	unsigned w = resolve_width(width);
	__u64 mask = width_mask(w);

	if (w == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (w == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (w == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value & mask;
}

/* ---- The routed body's whole effect for one op --------------------------- */

/* The route oracle mirrors the inline dispatcher arm exactly: the effective
 * width resolves from the FLAGS code, the source width resolves through the
 * restated absent-code fallback, the extension shape selects on the raw
 * opcode (sign at 0x21, zero everywhere else), the source lane reads whole,
 * and the writeback is the width-local partial-register write with no flag
 * write. */
static void model_movx_step(unsigned op, unsigned width_code, unsigned aux)
{
	unsigned w = resolve_width(width_code);
	unsigned src_w =
		((__u8)aux) == 0U ? w : ((__u8)aux);
	__u64 value = mreg[SRC_REG];

	if (op == X86_OP_MOVSX_REG)
		value = model_sign_extend(value, src_w);
	else
		value = model_zero_extend(value, src_w);

	mreg[DST_REG] = model_partial_write(mreg[DST_REG], value, w);
	mtag[DST_REG] = X86_SIM_TAG_SCALAR;
}

#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
                                                                      \
			/* The source register drives the body's 64-bit     \
			 * read, so its lane holds the driven value and     \
			 * not pattern noise. */                            \
			if (SRC_REG == __pl_i)                             \
				__pl_value = src_value;                    \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)__pl_value,                 \
				__pl_tag);                                \
			mreg[__pl_i] = __pl_value;                         \
			mtag[__pl_i] = __pl_tag;                           \
		}                                                         \
	} while (0)

#define DECLARE_SIM_STATE()                                                \
	X86_SIM_L_DECLARE_STATE();                                        \
	struct x86_sim_xdp_abi __x86_sim_abi = {};                        \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;       \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                     \
	(void)__x86_sim_abi;                                              \
	(void)__x86_sim_skb_ctx;                                          \
	(void)__x86_sim_abi_kind;                                         \
	X86_SIM_L_DECLARE_STACK();                                        \
	(void)__x86_xmm0_lo;                                              \
	(void)__x86_xmm0_hi;                                              \
	(void)__x86_sim_ret_addr;                                         \
	(void)__x86_stack_mem;

/* The flag file is planted at both extremes, so a body that reads, restores,
 * or writes a flag rather than preserving it is distinguishable in both
 * directions. */
static const __u8 pre_flag[2] = { 0U, 1U };

#define STAGE_FLAGS(FV)                                                    \
	do {                                                               \
		__x86_cf = pre_flag[fv];                                  \
		__x86_zf = pre_flag[fv];                                  \
		__x86_sf = pre_flag[fv];                                  \
		__x86_of = pre_flag[fv];                                  \
		mcf = pre_flag[fv];                                       \
		mzf = pre_flag[fv];                                       \
		msf = pre_flag[fv];                                       \
		mof = pre_flag[fv];                                       \
	} while (0)

static const char *route_ctx;

#define COMPARE_ALL()                                                      \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u: got 0x%llx "   \
				       "want 0x%llx\n", route_ctx,         \
				       (unsigned)__ca_i,                   \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u tag: got %u "   \
				       "want %u\n", route_ctx,             \
				       (unsigned)__ca_i, __ca_tag,         \
				       mtag[__ca_i]);                      \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

#define CHECK_FLAG_STATE(OP, WIDTH, AUX, FV)                               \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			printf("MISMATCH %s op=0x%02x width=%u "          \
			       "aux=0x%02x fv=%u: flags written "         \
			       "got %u/%u/%u/%u want %u/%u/%u/%u\n",      \
			       route_ctx, (OP), (WIDTH), (AUX), (FV),     \
			       __x86_cf, __x86_zf, __x86_sf, __x86_of,    \
			       mcf, mzf, msf, mof);                       \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* One case of the MOVX register form: plant registers and flags, run the
 * real dispatched body, and compare the register file, tags, and the
 * unchanged flag bytes against the model. The body is inline in the
 * dispatcher, so every case drives the real `X86_SIM_L_EXEC` arm. */
static void check_movx_route(unsigned op, unsigned width_code, unsigned aux,
			     unsigned fv, __u64 src_value)
{
	DECLARE_SIM_STATE();
	(void)__x86_sim_abi_kind;

	PLANT_REGS();
	STAGE_FLAGS(fv);

	route_ctx = (op == X86_OP_MOVSX_REG) ? "movsx" : "movzx";
	model_movx_step(op, width_code, aux);

	/* The whole immediate artifact field is an unused operand slot for
	 * the MOVX register arm; the dispatcher chain expands it in the
	 * shared store/CMOV arms, so pass a 64-bit lvalue (the warning-free
	 * form the other route oracles use). */
	{
		__u64 imm = 0ULL;

		/* ---- run the real routed body ---- */
		X86_SIM_L_EXEC(op, DST_REG, SRC_REG, width_code, aux, imm);
	}

	COMPARE_ALL();
	CHECK_FLAG_STATE(op, width_code, aux, fv);
}

/* The two MOVX register opcode codes must still name the dispatcher's
 * `movxReg` family arm, so the route oracle cannot silently rotate the
 * opcode space the body macro consumes. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_MOVZX_REG != 0x20U || X86_OP_MOVSX_REG != 0x21U) {
		printf("MISMATCH x86 movx reg opcode code drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Six source-width AUX codes: the absent code (whose absence must
	 * fall back to the effective width), the four real width codes, and
	 * -- as a boundary probe -- the byte value just past a real width
	 * code (any width body applies the plain byte mask; the model
	 * restates the mask, not the decode). */
	static const unsigned aux_codes[6] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
		33U,
	};
	/* Six left operands: zero, one, the 8-bit sign bit, an all-lanes
	 * pattern, the 32-bit sign bit, and the all-ones lane. */
	static const __u64 src_values[6] = {
		0ULL, 1ULL, 0x80ULL, 0x1122334455667788ULL,
		0x80000000ULL, 0xffffffffffffffffULL,
	};
	static const unsigned ops[2] = {
		X86_OP_MOVZX_REG, X86_OP_MOVSX_REG,
	};
	unsigned op;
	unsigned w;
	unsigned a;
	unsigned s;
	unsigned fv;

	check_selectors();

	for (op = 0; op < 2U; op++) {
		for (w = 0; w < 5U; w++) {
			for (a = 0; a < 6U; a++) {
				for (s = 0; s < 6U; s++) {
					for (fv = 0; fv < 2U; fv++) {
						check_movx_route(
							ops[op],
							width_codes[w],
							aux_codes[a],
							fv,
							src_values[s]);
					}
				}
			}
		}
	}

	if (failures == 0)
		printf("x86 movx reg route host cross-check: OK "
		       "(%lu cases)\n",
		       cases);
	else
		printf("x86 movx reg route host cross-check: FAIL "
		       "(%lu cases, %d failures)\n",
		       cases, failures);
	return failures == 0 ? 0 : 1;
}
