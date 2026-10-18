/*
 * Host cross-check for the x86 simulator's routing of the effective-address
 * op-step result (STEP 0159).
 *
 * Drives the *inline* LEA arm body of the routed dispatcher `X86_SIM_L_EXEC`
 * in `x86/x86_sim_local_bpf.h` -- the same body the member opcode
 * `X86_OP_LEA` (0x09) of the dispatcher's `lea` family arm executes -- and
 * compares its whole effect (the sixteen register values, their tags, the
 * four flag bytes, and the memory images) against an independent model
 * restated from the raw macros and the generated contracts:
 *
 *   - the body computes the addressing offset through the machine-checked
 *     `X86_SIM_L_MEM_OFFSET` chain: the sign-extended immediate
 *     ("displacement") plus, exactly when the AUX index byte is present,
 *     the index register lane value scaled by the AUX scale lane, in
 *     64-bit wrapping signed arithmetic (`KPROG_X86_MEM_OFFSET`);
 *   - the body has four exits: (1) the `X86_LEA_AUX_RODATA` fast path --
 *     at the 64-bit resolved width with a NONE source register it writes
 *     the RAW immediate (the whole 64-bit artifact, not a pointer plus the
 *     offset) as a scalar; the AUX bits only gate the arm, the offset is
 *     never consumed by this exit; (2) at 64 bits with the stack pointer
 *     as the source lane it rebinds the address through the stack arena
 *     (`X86_SIM_L_STACK_PTR` against `KPROG_X86_STACK_INDEX`'s 32-bit
 *     window wrap over the 128-byte capacity) and stamps the
 *     `X86_SIM_TAG_STACK` tag; (3) at 64 bits with any other present
 *     source it is the raw 64-bit pointer add (`KPROG_PTR_ADD64_BITS`)
 *     with the source tag carried through unchanged
 *     (`KPROG_PTR_ADD64_TAG`); (4) at any narrower width it scalarizes:
 *     the pointer add is computed as a plain byte offset and written back
 *     through the width-local partial-register write, which zero-extends
 *     the dword form and preserves upper lanes at byte and word, always
 *     with the scalar tag;
 *   - a NONE source register resolves the source pointer and tag to
 *     `0`/scalar (the base contribution is the null pointer's zero bits);
 *   - the body writes no flag byte and no memory byte: the planted flag
 *     bytes, the stack arena image, and the heap image must all come back
 *     unchanged.
 *
 * The case algebra: 3 source roots (NONE, the stack pointer, a general
 * register) x 5 width codes (the absent code plus the four real codes) x 4
 * addressing modes (no index, an RODATA gate, an index at scale 1, an
 * index at scale 8) x 4 immediate artifacts x 2 destination lanes x 2
 * flag seeds = 960 cases, each comparing 16 register values + 16 tags + 1
 * memory image + 1 flag row = 34 rows, so 32,640 rows plus the one
 * opcode-code selector row = 32,641 rows in `make check`.
 *
 * Every case is driven through the real dispatcher arm `X86_SIM_L_EXEC` (the
 * body is inline in the dispatcher, so the dispatch route is the only body
 * route), with the register file, tags, flags, heap, and stack arena planted
 * before the run and compared after it. Exit 1 on mismatch.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_lea_route_host.c \
 *      -o build/test_x86_lea_route_host \
 *      && ./build/test_x86_lea_route_host
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

/* A small heap the planted general registers may address; the LEA body only
 * ever forms addresses and never dereferences them, so the image must come
 * back unchanged -- proving no arm writes memory through the formed
 * pointer. */
#define HEAP_BYTES 4096U
static __u8 heap[HEAP_BYTES];
static __u8 exp_heap[HEAP_BYTES];
/* Byte image of the stack arena a case must leave untouched. */
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* The operand lanes: `SRC_REG` is the general mapped-pointer source (its
 * lane value participates in the pointer add), `INDEX_REG` the byte-lane
 * the AUX index byte names. */
#define SRC_REG X86_RCX
#define RSP_PLANT ((void *)(long)-64LL)
#define GENERAL_BASE 0x00005a0000000000ULL
#define GENERAL_BASE_TAG X86_SIM_TAG_MAP_VALUE
#define INDEX_REG X86_RDI
#define INDEX_VALUE 7ULL

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

/* The model runs inside the checker scope: every lane the routed body
 * consumes is snapshot from the planted state ONCE, before the model's own
 * writes could overwrite it, and the exit prediction is recorded into this
 * small frame. */
struct model_once {
	__u64 lanes[16];
	__u8 tags[16];
};

/* The width-local partial-register write (`KPROG_X86_WRITE_WIDTH_ARM`
 * ladder at destination shift zero): byte and word preserve the upper
 * lanes, dword zero-extends, qword writes the lane. */
static __u64 model_partial_write(__u64 old, __u64 value, unsigned width)
{
	unsigned w = resolve_width(width);

	if (w == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (w == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (w == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value;
}

/* The arena base the arm materializes (assigned in the checker, where the
 * stack object is in scope); the model adds the generated index to it so a
 * pointer-valued output compares equal. */
static unsigned long stack_arena_base;

/* ---- The routed body's whole effect for one drive ----------------------- */

/* `src_root` selects the source lane: 0 = NONE, 1 = the stack pointer,
 * 2 = the general register. `mode` selects the addressing: 0 = no index
 * (NONE index byte), 1 = the RODATA gate byte, 2 = a real index at scale
 * 1, 3 = a real index at scale 8. The gates mirror the body's two 64-bit
 * decisions, but are restated independently of the macro's own helper
 * macros. */

/* Expands inside the checker scope (it must see the sim's `__x86_*` lanes
 * directly, because the sim's RAW pointer read is a plain macro reference,
 * not a function). Snapshots the lanes ONCE, then writes the exit
 * prediction into `*mo`. */
#define MODEL_ONCE(SRC_ROOT, WIDTH_CODE, AUX, DST, IMM, MO)                 \
	do {                                                           \
		unsigned __mo_w = resolve_width(WIDTH_CODE);          \
		unsigned __mo_aux = (AUX);                            \
		unsigned __mo_src = (SRC_ROOT) == 0U ? X86_REG_NONE :  \
				    (SRC_ROOT) == 1U ? X86_RSP :      \
						       SRC_REG;       \
		__u64 __mo_src_v = (__mo_src == X86_REG_NONE) ? 0 :    \
			(X86_SIM_L_EFFECTIVE_WIDTH(WIDTH_CODE) ==      \
				 X86_WIDTH_32 ?                        \
			 X86_SIM_L_READ_REG(__mo_src) & 0xffffffffUL : \
			 (__u64)(long)X86_SIM_L_READ_REG_PTR(__mo_src));\
		__u8 __mo_src_tag = (__mo_src == X86_REG_NONE) ?      \
			X86_SIM_TAG_SCALAR :                          \
			X86_SIM_L_REG_TAG(__mo_src);                  \
		__s64 __mo_off = X86_SIM_L_MEM_OFFSET(__mo_aux,       \
			x86_simm(IMM));                               \
		unsigned long __mo_result;                            \
		if (__mo_w == X86_WIDTH_64 &&                          \
		    __mo_src == X86_REG_NONE &&                        \
		    __mo_aux == X86_LEA_AUX_RODATA) {                  \
			(MO)->lanes[DST] = (IMM);                     \
			(MO)->tags[DST] = X86_SIM_TAG_SCALAR;         \
		} else if (__mo_w == X86_WIDTH_64 &&                   \
			   __mo_src == X86_RSP) {                      \
			unsigned long __mo_idx =                      \
				(unsigned long)(unsigned int)(        \
					(long)__mo_src_v +            \
					(long)__mo_off +              \
					(long)X86_SIM_STACK_BYTES);   \
			(MO)->lanes[DST] = stack_arena_base +          \
				__mo_idx;                             \
			(MO)->tags[DST] = X86_SIM_TAG_STACK;           \
		} else if (__mo_w == X86_WIDTH_64) {                   \
			__mo_result = (unsigned long)__mo_src_v +      \
				      (unsigned long)__mo_off;         \
			(MO)->lanes[DST] = __mo_result;               \
			(MO)->tags[DST] = __mo_src_tag;               \
		} else {                                               \
			__mo_result = (unsigned long)__mo_src_v +      \
				      (unsigned long)__mo_off;         \
			(MO)->lanes[DST] = model_partial_write(        \
				mreg[DST], (__u64)(long)               \
					__mo_result, WIDTH_CODE);      \
			(MO)->tags[DST] = X86_SIM_TAG_SCALAR;         \
		}                                                      \
	} while (0)

/* Plant the register file: pattern values and pattern tags everywhere, with
 * the three LEA-participating lanes forced -- the general source lane holds
 * the mapped pointer under its mapped tag, the stack lane the signed
 * RSP_PLANT offset under the scalar tag (the arena rebase treats the raw
 * pointer bits as the window offset), and the index lane the small scalar
 * index the AUX mode scales. Expands inside a checker that has declared
 * the simulated register file. */
#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
			if (__pl_i == SRC_REG) {                      \
				__pl_value = GENERAL_BASE;               \
				__pl_tag = GENERAL_BASE_TAG;             \
			}                                                 \
			if (__pl_i == X86_RSP) {                          \
				__pl_value = (__u64)RSP_PLANT;            \
				__pl_tag = X86_SIM_TAG_SCALAR;            \
			}                                                 \
			if (__pl_i == INDEX_REG) {                        \
				__pl_value = INDEX_VALUE;                 \
				__pl_tag = X86_SIM_TAG_SCALAR;            \
			}                                                 \
			X86_SIM_L_WRITE_REG_PTR_TAG(__pl_i,           \
				(void *)(long)__pl_value,             \
				__pl_tag);                            \
			mreg[__pl_i] = __pl_value;                    \
			mtag[__pl_i] = __pl_tag;                      \
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
	(void)__x86_sim_ret_addr;

static void plant_heap_mem(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = (__u8)(0x30U + i);
	memcpy(exp_heap, heap, sizeof(heap));
}

/* The flag file is planted at both extremes, so a body that writes a flag
 * rather than preserving it is distinguishable in both directions. */
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

/* No LEA lane writes memory: both memory images must come back exactly as
 * planted. */
#define COMPARE_MEMORY()                                                   \
	do {                                                               \
		unsigned __cm_i;                                          \
		int __cm_bad = 0;                                         \
		for (__cm_i = 0; __cm_i < HEAP_BYTES; __cm_i++)            \
			if (exp_heap[__cm_i] != heap[__cm_i]) {            \
				__cm_bad = 1;                              \
				break;                                     \
			}                                                 \
		for (__cm_i = 0;                                          \
		     !__cm_bad && __cm_i < X86_SIM_STACK_BYTES;           \
		     __cm_i++)                                            \
			if (__x86_stack_mem.b[__cm_i] !=                   \
			    exp_stack[__cm_i]) {                           \
				__cm_bad = 1;                              \
				break;                                     \
			}                                                 \
		cases++;                                                  \
		if (__cm_bad) {                                           \
			printf("MISMATCH %s: memory image written\n",      \
			       route_ctx);                                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define CHECK_FLAG_STATE(OP, WIDTH, MODE, DST, FV)                         \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			printf("MISMATCH %s op=0x%02x width=%u "          \
			       "mode=%u dst=%u fv=%u: flags written "     \
			       "got %u/%u/%u/%u want %u/%u/%u/%u\n",      \
			       route_ctx, (OP), (WIDTH), (MODE), (DST),   \
			       (FV), __x86_cf, __x86_zf, __x86_sf,        \
			       __x86_of, mcf, mzf, msf, mof);             \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* One case of the LEA body: plant the register file and memory images, run
 * the real dispatched body, and compare the register file, tags, memory
 * images, and flags against the model. The body is inline in the
 * dispatcher, so every case drives the real `X86_SIM_L_EXEC` arm. */
static void check_lea(unsigned src_root, unsigned width_code, unsigned mode,
		      __u64 imm, unsigned dst, unsigned fv)
{
	unsigned aux;
	unsigned src;
	/* The whole immediate artifact field is the addressing displacement /
	 * the raw RODATA write; it must be a 64-bit lvalue, since the
	 * dispatcher chain expands it in the shared store/CMOV arms and a
	 * literal would raise a shift-count-overflow warning there. */
	__u64 imm_artifact = imm;

	switch (mode) {
	case 2U:
		aux = KPROG_X86_MEM_AUX(INDEX_REG, 0U, 0U, 0U);
		break;
	case 3U:
		aux = KPROG_X86_MEM_AUX(INDEX_REG, 3U, 0U, 0U);
		break;
	case 1U:
		aux = X86_LEA_AUX_RODATA;
		break;
	default:
		aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
		break;
	}

	{
		DECLARE_SIM_STATE();
		(void)__x86_sim_abi_kind;

		stack_arena_base =
			(unsigned long)(void *)&__x86_stack_mem.b[0];
		plant_heap_mem();
		memset(__x86_stack_mem.b, 0x11, sizeof(__x86_stack_mem.b));
		memcpy(exp_stack, __x86_stack_mem.b, sizeof(exp_stack));
		PLANT_REGS();
		STAGE_FLAGS(fv);

		src = (src_root == 0U) ? X86_REG_NONE :
		      (src_root == 1U) ? X86_RSP : SRC_REG;
		route_ctx = "lea";
		/* The model precedes the run because its macro must expand
		 * inside the checker scope while the planted register file
		 * is still the PRE state the exits consume. The prediction
		 * lands in `mo`; planting and staging again (the model's
		 * macro leaves the sim untouched) before the run would
		 * discard nothing, so the run then executes the real body
		 * over the same PRE state. */
		struct model_once mo;
		memset(&mo, 0, sizeof(mo));
		MODEL_ONCE(src_root, width_code, aux, dst, imm, &mo);
		(void)src;
		/* The sim's actual macro body performs the exit. */
		X86_SIM_L_EXEC(X86_OP_LEA, dst, src, width_code, aux,
			       imm_artifact);

		mreg[dst] = mo.lanes[dst];
		mtag[dst] = mo.tags[dst];

		COMPARE_ALL();
		COMPARE_MEMORY();
		CHECK_FLAG_STATE(X86_OP_LEA, width_code, mode, dst, fv);
	}
}

/* The LEA opcode code must still name the dispatcher's `lea` family arm, so
 * the route oracle cannot silently rotate the opcode space the body macro
 * consumes. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_LEA != 0x09U) {
		printf("MISMATCH x86 lea opcode code drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned src_roots[3] = { 0U, 1U, 2U };
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const unsigned modes[4] = { 0U, 1U, 2U, 3U };
	/* Four immediate artifacts: zero, a positive displacement below the
	 * window, a negative displacement, and a value shaped so its upper
	 * half is nonzero (the RODATA exit writes the whole artifact, so the
	 * fast path is pinned against a pointer-plus-offset reading). */
	static const __u64 imm_artifacts[4] = {
		0x0000000000000000ULL, 0x0000000000000020ULL,
		0xffffffffffffffe8ULL, 0xfffffff000000000ULL,
	};
	static const unsigned dst_regs[2] = { X86_R9, X86_R10 };
	unsigned s;
	unsigned w;
	unsigned m;
	unsigned d;
	unsigned f;
	unsigned i;

	check_selectors();

	for (s = 0; s < 3U; s++)
		for (w = 0; w < 5U; w++)
			for (m = 0; m < 4U; m++)
				for (d = 0; d < 2U; d++)
					for (f = 0; f < 2U; f++)
						for (i = 0; i < 4U; i++)
							check_lea(
								src_roots[s],
								width_codes[w],
								modes[m],
								imm_artifacts[i],
								dst_regs[d],
								f);

	if (cases != 32641UL) {
		printf("x86 lea route host cross-check: case-count drift "
		       "(got %lu want %lu)\n", cases, 32641UL);
		return 1;
	}
	if (failures == 0)
		printf("x86 lea route host cross-check: OK (%lu cases)\n",
		       cases);
	else
		printf("x86 lea route host cross-check: FAIL "
		       "(%lu cases, %d failures)\n", cases, failures);
	return failures == 0 ? 0 : 1;
}
