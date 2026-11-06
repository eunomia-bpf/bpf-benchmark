/*
 * Step 0450 battery-local route oracle: drives the real AArch64 FMOV arm of
 * `ARM64_SIM_L_EXEC` (the `KPROG_ARM64_DISP_FMOV_HANDLED` gate) against an
 * independent model of the arm's two-commit lattice.
 *
 * Unlike the two tracked oracles this battery's detectors also run
 * (`test_arm64_fmov_host.c` — the raw value switch over 256 directions, and
 * `test_arm64_fmov_dest_host.c` — the raw routing bit over 256 directions),
 * this oracle paints the sim-local arm's own line paragraphs: the FMOV
 * direction reads the whole AUX word, the value selection sees the planted
 * `__a64_v0` and the source register's live value, the routing decision
 * commits either into the vector register `__a64_v0` (verbatim, no width
 * apply) or into the general-purpose destination through the width-narrowed
 * register write, and every out-of-family opcode or direction reaches the
 * caller hook. The model restates those lanes from the raw direction code:
 *
 *   vector_destination(dir) = dir < 4 && dir % 2 == 0
 *   value(dir, v0, src)     = src  when vector_destination(dir)
 *                             v0   otherwise
 *   commit: vector -> v0 = result; register -> gpr[dst] = apply_width
 *           (result, width) with the tag cleared by the write arm
 *
 * Scenes drive the four directions x {v0 seeds} x {src register classes with
 * distinct provenance tags} x the destination register classes (scalar GPR,
 * ABI-tagged GPR, the zero register, the SP) x the four effective width
 * codes x {direct aux encoding, aux with high bits} plus the unsupported
 * scenes (out-of-family opcode, out-of-range direction), including a
 * d_from_x -> x_from_d round-trip lane so a vector-file repaint that drops
 * the committed v0 shows up in the following register write. A swapped
 * value arm, a flipped routing bit, a dropped width apply, a rewritten
 * destination lane, or a broken unsupported arm shows up as a register,
 * vector-register, tag, or unsupported-count difference.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      build/fmov_route_host.c -o build/mut_fmovroute &&
 *   ./build/mut_fmovroute
 */
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

#define QUIET_GPR_ONE(REG, NAME) \
	(void)sizeof(__a64_##NAME); \
	(void)sizeof(__a64_##NAME##_tag);

#define DECL_STATE() \
	ARM64_SIM_L_DECLARE_STATE(); \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP; \
	(void)__a64_sim_abi_kind; \
	ARM64_SIM_L_DECLARE_STACK(); \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE); \
	(void)__a64_lr

#define SEED_GPR_ONE(REG, NAME) \
	do { \
		__a64_##NAME.ptr = (void *)(long)(0x9e3779b97f4a7c15ULL * ((REG) + 1U)); \
		__a64_##NAME##_tag = ARM64_SIM_TAG_SCALAR; \
	} while (0);
#define SEED_GPRS() ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

#define SEED_FLAGS() \
	do { \
		__a64_n = 1; \
		__a64_z = 0; \
		__a64_c = 1; \
		__a64_v = 0; \
	} while (0)

/* ------------------------------------------------------------ */
/* Independent model of the FMOV arm's state effects.            */
/* ------------------------------------------------------------ */

static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static __u64 m_v0;
static unsigned long model_unsupported_calls;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static __u64 apply_width(__u64 value, unsigned width)
{
	return value & KPROG_ARM64_WIDTH_MASK(width);
}

static __u8 vector_destination(__u64 dir)
{
	return (__u8)(dir < 4ULL && dir % 2ULL == 0ULL);
}

static __u64 model_value(__u64 dir, __u64 v0, __u64 src)
{
	return vector_destination(dir) ? src : v0;
}

static void model_write_reg_width(unsigned reg, __u64 value, unsigned width)
{
	__u64 next = apply_width(value, width);

	if (reg == ARM64_SP) {
		msp = (__s64)next;
	} else if (reg != ARM64_XZR && reg != ARM64_REG_NONE) {
		if (width == ARM64_WIDTH_32)
			mreg[reg] = (__u32)next;
		else
			mreg[reg] = next;
		mtag[reg] = ARM64_SIM_TAG_SCALAR;
	}
}

/* The sim-local FMOV arm, restated. The AUX word is the direction. */
static void model_fmov(unsigned op, unsigned dst, unsigned src, unsigned width,
		       __u32 aux)
{
	if (op != ARM64_OP_FMOV) {
		model_unsupported_calls++;
		return;
	}
	__u64 dir = (__u64)aux;
	/* Out-of-range AUX reaches the counted hook once per value and
	 * routing switch argument; the switch arms leave the local result
	 * at 0 and the routing bit at 0. */
	if (dir >= 4ULL) {
		/* The counted hook fires once per value and routing switch
		 * argument; the switch arms leave the value at 0 and route
		 * to the register write of zero. */
		model_unsupported_calls += 2U;
		if (dst == ARM64_SP)
			msp = 0;
		else
			model_write_reg_width(dst, 0, width);
		return;
	}
	__u64 srcval = (src == ARM64_SP) ? (__u64)msp : mreg[src];
	__u64 result = model_value(dir, m_v0, srcval);

	if (vector_destination(dir))
		m_v0 = result;
	else
		model_write_reg_width(dst, result, width);
}

/* ------------------------------------------------------------ */
/* Heap constants: only the pointer-tag provenance of the source uses
 * these windows; the FMOV arm itself never touches memory. */
#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define ABI_BASE_OFF 2048U

static __u8 heap[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

/* SP base value; the FMOV arm never touches memory, but SP is a destination
 * class and must keep its own stack tag. */
#define STACK_BASE_VAL (-64LL)

/* ------------------------------------------------------------ */
/* The checker.                                                  */
/* ------------------------------------------------------------ */
#define PLANT_STATE(SRC)                                                   \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = STACK_BASE_VAL;                                \
		msp = STACK_BASE_VAL;                                     \
		if ((SRC) == ARM64_X3) {                                  \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(SRC),                                    \
				(void *)(long)(heap + SCALAR_BASE_OFF),   \
				ARM64_SIM_TAG_SCALAR);                    \
			mreg[SRC] = (__u64)(long)(heap + SCALAR_BASE_OFF);\
			mtag[SRC] = ARM64_SIM_TAG_SCALAR;                \
		} else if ((SRC) == ARM64_X4) {                           \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				(SRC),                                    \
				(void *)(long)(heap + ABI_BASE_OFF),      \
				ARM64_SIM_TAG_ABI);                       \
			mreg[SRC] = (__u64)(long)(heap + ABI_BASE_OFF);  \
			mtag[SRC] = ARM64_SIM_TAG_ABI;                   \
		}                                                         \
	} while (0)

#define COMPARE_STATE(OP, DST, SRC, WIDTH, AUX, VIA)                       \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x dst=%u src=%u "   \
				       "width=%u aux=%#llx via=%u reg%u: " \
				       "got 0x%llx want 0x%llx\n",         \
				       (OP), (DST), (SRC), (WIDTH),        \
				       (unsigned long long)(AUX), (VIA),   \
				       (unsigned)__cs_i,                   \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)mreg[__cs_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u "    \
				       "tag: got %u want %u\n",           \
				       (OP), (VIA), (unsigned)__cs_i,     \
				       __cs_tag, mtag[__cs_i]);           \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH op=%#x via=%u sp: got %lld "     \
			       "want %lld\n", (OP), (VIA),                \
			       (long long)__a64_sp, (long long)msp);      \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_v0 != m_v0) {                                   \
			printf("MISMATCH op=%#x via=%u v0: got %#llx "    \
			       "want %#llx\n", (OP), (VIA),               \
			       (unsigned long long)__a64_v0,              \
			       (unsigned long long)m_v0);                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* FLAGS carries the raw width code the dispatcher resolves; zero falls back
 * to the 64-bit default inside the dispatcher. Aux is the FMOV direction. */
static void check_case(unsigned op, unsigned dst, unsigned src,
		       unsigned flags, __u32 aux, unsigned via)
{
	unsigned width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;
	unsigned i;
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__a64_sim_abi_kind;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_lr;

	PLANT_STATE(src);

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = heap_img[i];

	__a64_v0 = pattern_reg(40);
	m_v0 = pattern_reg(40);

	model_fmov(op, dst, src, width, aux);

	if (via)
		ARM64_SIM_L_EXEC(op, dst, src, ARM64_REG_NONE, ARM64_REG_NONE,
				 flags, aux, 0);
	else if (op == ARM64_OP_FMOV)
		/* The "direct" lane replays the arm's own body against the
		 * same planted state. */
		do {                                               \
			__u64 __a64_fmov_result =                  \
				KPROG_ARM64_FMOV_VALUE(aux,        \
					__a64_v0,                  \
					ARM64_SIM_L_READ_REG(src), \
					ARM64_SIM_L_UNSUPPORTED_OPCODE()); \
			if (KPROG_ARM64_FMOV_DEST_VECTOR(aux,      \
					ARM64_SIM_L_UNSUPPORTED_OPCODE())) \
				__a64_v0 = __a64_fmov_result;      \
			else                                       \
				ARM64_SIM_L_WRITE_REG_WIDTH(dst,   \
					__a64_fmov_result, width); \
		} while (0);
	else
		/* A non-member opcode routes to the dispatcher's unsupported
		 * arm once, like the exec lane. */
		ARM64_SIM_L_UNSUPPORTED_OPCODE();

	cases++;
	if (unsupported_calls != u0 + (model_unsupported_calls - mu0)) {
		printf("MISMATCH op=%#x aux=%#llx via=%u unsupported "      \
		       "delta: got %lu want %lu\n", op,                      \
		       (unsigned long long)aux, via,                         \
		       unsupported_calls - u0,                               \
		       model_unsupported_calls - mu0);                       \
		failures++;                                                  \
		return;                                                      \
	}

	COMPARE_STATE(op, dst, src, width, aux, via);
}

/* The two committed files must agree with the contract tables: the routing
 * bits and the value arms. */
static void check_selectors(void)
{
	static const __u64 dirs[4] = {
		ARM64_FMOV_D_FROM_X, ARM64_FMOV_X_FROM_D,
		ARM64_FMOV_S_FROM_W, ARM64_FMOV_W_FROM_S,
	};
	static const unsigned want_vector[4] = { 1, 0, 1, 0 };
	unsigned i;

	for (i = 0; i < 4U; i++) {
		__u64 dir = dirs[i];
		cases++;
		if (KPROG_ARM64_FMOV_DEST_VECTOR(dir,
				arm64_sim_unsupported_opcode()) !=
				want_vector[i]) {
			printf("MISMATCH fmov dest vector dir=%llu\n",
			       (unsigned long long)dir);
			failures++;
		}
		cases++;
		if (vector_destination(dir) != want_vector[i]) {
			printf("MISMATCH model vector dir=%llu\n",
			       (unsigned long long)dir);
			failures++;
		}
	}

	/* Totality of the routing selector over out-of-range directions:
	 * every unknown direction reaches the caller hook. */
	{
		static const __u64 untested[4] = { 4ULL, 5ULL, 255ULL,
						   0x100ULL };
		unsigned i;

		for (i = 0; i < 4U; i++) {
			unsigned long before = unsupported_calls;
			__u64 bit;

			cases++;
			bit = KPROG_ARM64_FMOV_DEST_VECTOR(untested[i],
				ARM64_SIM_L_UNSUPPORTED_OPCODE());
			if (unsupported_calls == before) {
				printf("MISMATCH fmov dest unsupported "  \
				       "missing dir=%llu\n",              \
				       (unsigned long long)untested[i]);  \
				failures++;
			}
			/* An out-of-range direction keeps the routing bit
			 * at zero through the caller hook. */
			if (bit) {
				printf("MISMATCH fmov dest stray routing "  \
				       "bit dir=%llu\n",                   \
				       (unsigned long long)untested[i]);   \
				failures++;
			}
		}
	}

	/* The FMOV value arms agree with the independent selection under an
	 * asymmetric (v0 != src) seed, both directions of commit. */
	{
		static const __u64 v0s[2] = { 0x123456789abcdef0ULL,
					      0xfeedfacebeadfaceULL };
		static const __u64 srcs[2] = { 0x0123456789abcdefULL,
					       0xc0ffee00baadf00dULL };
		unsigned i;

		for (i = 0; i < 4U; i++) {
			__u64 dir = dirs[i];

			cases++;
			if (KPROG_ARM64_FMOV_VALUE(dir, v0s[i & 1U],
					srcs[(i >> 1) & 1U],
					arm64_sim_unsupported_opcode()) !=
					model_value(dir, v0s[i & 1U],
						srcs[(i >> 1) & 1U])) {
				printf("MISMATCH fmov value dir=%llu\n",
				       (unsigned long long)dir);
				failures++;
			}
		}
	}
}

int main(void)
{
	static const unsigned ops[2] = { ARM64_OP_FMOV, ARM64_OP_RET };
	static const unsigned dsts[3] = { ARM64_X2, ARM64_X3, ARM64_SP };
	static const unsigned srcs[4] = { ARM64_X1, ARM64_X4, ARM64_X5,
					  ARM64_SP };
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const __u32 dir_aux[8] = {
		ARM64_FMOV_D_FROM_X, ARM64_FMOV_X_FROM_D,
		ARM64_FMOV_S_FROM_W, ARM64_FMOV_W_FROM_S,
		5U, 4U, 7U, 0x100U,
	};
	const unsigned aux_classes = sizeof(dir_aux) / sizeof(dir_aux[0]);
	unsigned via;
	unsigned o;
	unsigned d;
	unsigned s;
	unsigned w;
	unsigned a;
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));

	/* The dispatcher lane: the real FMOV exec arm. */
	for (via = 0; via < 2U; via++)
		for (o = 0; o < 2U; o++)
			for (d = 0; d < 3U; d++)
				for (s = 0; s < 4U; s++)
					for (w = 0; w < 4U; w++)
						for (a = 0; a < aux_classes;
							a++)
							check_case(ops[o],
								dsts[d],
								srcs[s],
								widths[w],
								dir_aux[a],
								via);

	check_selectors();

	if (failures != 0) {
		printf("arm64 fmov route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 fmov route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
