/*
 * Host cross-check for the x86 simulator's routing of the effective-width
 * resolution through the generated `KPROG_X86_WIDTH_EFFECTIVE` contract
 * (STEP 0105).
 *
 * The simulator resolves a decoded width code that may be "absent" (code 0)
 * inline across its register reads/writes, stack traffic, flag production, and
 * every ALU/move/compare/IMUL/MULX body: `WIDTH ? WIDTH : X86_WIDTH_64`. Those
 * restatements now route through `X86_SIM_L_EFFECTIVE_WIDTH`, whose kernel is
 * the generated `KPROG_X86_WIDTH_EFFECTIVE` macro and the Lean `effective`
 * def in `KProgFormal/X86Width.lean`. This oracle includes the *simulator*
 * header (so the real routed macros are under test), sweeps the full width-code
 * byte range against an independent `code ? code : 64` model, and drives every
 * routed body.
 *
 * Two checks per routed body:
 *   - an independent value/state model deriving the effective code from the
 *     raw code (`eff_of`), for the width-sensitive observables;
 *   - the contract's observable, that the absent code 0 behaves exactly as the
 *     64-bit code on the whole modeled register/flag/stack/heap state.
 *
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_width_effective_route_host.c -o /tmp/t_xwer && /tmp/t_xwer
 */
#define X86_SIM_ENABLE_STACK
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

static __u8 heap[64];

/* ---- Independent contract model ---------------------------------------- */

/* The contract's whole meaning: an absent code names 64 bits. Derived from the
 * raw code, never from the generated macro. */
static __u8 eff_of(__u8 code)
{
	return code ? code : X86_WIDTH_64;
}

static __u64 mask_of(__u8 width)
{
	switch (width) {
	case X86_WIDTH_8:
		return 0xffULL;
	case X86_WIDTH_16:
		return 0xffffULL;
	case X86_WIDTH_32:
		return 0xffffffffULL;
	default:
		return ~0ULL;
	}
}

static __u64 sign_of(__u8 width)
{
	switch (width) {
	case X86_WIDTH_8:
		return 0x80ULL;
	case X86_WIDTH_16:
		return 0x8000ULL;
	case X86_WIDTH_32:
		return 0x80000000ULL;
	default:
		return 0x8000000000000000ULL;
	}
}

static __u32 bits_of(__u8 width)
{
	switch (width) {
	case X86_WIDTH_8:
		return 8U;
	case X86_WIDTH_16:
		return 16U;
	case X86_WIDTH_32:
		return 32U;
	default:
		return 64U;
	}
}

static __u64 ext_of(__u64 v, __u8 width)
{
	switch (eff_of(width)) {
	case X86_WIDTH_8:
		return (__u64)(__s64)(__s8)v;
	case X86_WIDTH_16:
		return (__u64)(__s64)(__s16)v;
	case X86_WIDTH_32:
		return (__u64)(__s64)(__s32)v;
	default:
		return v;
	}
}

static __u64 abs_of(__u64 v, __u8 width)
{
	__u8 e = eff_of(width);
	__u64 n = v & mask_of(e);

	if (n & sign_of(e))
		return ((~n) + 1) & mask_of(e);
	return n;
}

static __u8 cnt_of(__u64 rhs, __u8 width)
{
	return (__u8)(rhs & (eff_of(width) == X86_WIDTH_64 ? 63U : 31U));
}

/* Independent little-endian load/store over a raw width code (0 -> 64). */
static __u64 le_load(const __u8 *b, __u8 width)
{
	__u8 w = eff_of(width);
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < w; i++)
		v |= (__u64)b[i] << (8 * i);
	return v;
}

static void le_store(__u8 *b, __u64 v, __u8 width)
{
	__u8 w = eff_of(width);
	unsigned i;

	for (i = 0; i < w; i++)
		b[i] = (__u8)(v >> (8 * i));
}

/* The write helper's partial-register model: the 8-bit form byte-patches the
 * lane named by BYTE_SHIFT, the 16-bit form sets the low word from VALUE, and
 * 32/64 zero-extend or replace. Only the 8-bit form consults BYTE_SHIFT. */
static void *model_reg_ptr(void *old, __u64 value, __u8 width, __u8 byte_shift)
{
	union {
		void *ptr;
		__u8 b[8];
	} u;

	switch (eff_of(width)) {
	case X86_WIDTH_64:
		return (void *)(__u64)value;
	case X86_WIDTH_32:
		return (void *)(__u64)(__u32)value;
	default:
		u.ptr = old;
		if (eff_of(width) == X86_WIDTH_8) {
			u.b[byte_shift == 8U ? 1 : 0] = (__u8)value;
		} else {
			u.b[0] = (__u8)value;
			u.b[1] = (__u8)(value >> 8);
		}
		return u.ptr;
	}
}

/* The register read helper: a byte-8 read takes the lane shift, every other
 * width ignores it, and the value is width-masked. */
static __u64 read_at(__u64 value, __u8 width, __u8 byte_shift)
{
	__u8 e = eff_of(width);

	if (e == X86_WIDTH_8)
		value >>= byte_shift;
	return value & mask_of(e);
}

static __u64 alu_of(__u8 alu, __u64 lhs, __u64 rhs, __u8 width)
{
	__u8 e = eff_of(width);

	switch (alu) {
	case X86_ALU_ADD:
		return lhs + rhs;
	case X86_ALU_ADC:
		return lhs + rhs;
	case X86_ALU_SUB:
		return lhs - rhs;
	case X86_ALU_SBB:
		return lhs - rhs;
	case X86_ALU_XOR:
		return lhs ^ rhs;
	case X86_ALU_OR:
		return lhs | rhs;
	case X86_ALU_AND:
		return lhs & rhs;
	case X86_ALU_SHL:
		return ((lhs & mask_of(e)) << cnt_of(rhs, e)) & mask_of(e);
	case X86_ALU_SHR:
		return (lhs & mask_of(e)) >> cnt_of(rhs, e);
	case X86_ALU_SAR: {
		__u64 m = mask_of(e);
		__u64 n = lhs & m;
		__u8 c = cnt_of(rhs, e);

		if (c == 0)
			return n;
		{
			__u64 s = n >> c;

			if (n & sign_of(e))
				s |= m ^ (m >> c);
			return s;
		}
	}
	case X86_ALU_IMUL:
		return lhs * rhs;
	case X86_ALU_INC:
		return lhs + 1;
	case X86_ALU_DEC:
		return lhs - 1;
	case X86_ALU_NOT:
		return ~lhs;
	case X86_ALU_NEG:
		return (__u64)(-(__s64)lhs);
	default:
		return lhs;
	}
}

/* ---- Independent flag production --------------------------------------- */

static void m_logic(__u64 res, __u8 width, __u8 *cf, __u8 *zf, __u8 *sf,
		    __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 v = res & mask_of(e);

	*cf = 0;
	*zf = (v == 0);
	*sf = (__u8)((v >> (bits_of(e) - 1)) & 1);
	*of = 0;
}

static void m_sub(__u64 a0, __u64 b0, __u64 r0, __u8 width, __u8 *cf,
		  __u8 *zf, __u8 *sf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 m = mask_of(e);
	__u64 a = a0 & m, b = b0 & m, r = r0 & m, s = sign_of(e);

	*cf = (a < b);
	*zf = (a == b);
	*sf = ((r & s) != 0);
	*of = (((a ^ b) & ((a ^ r) & s)) != 0);
}

static void m_add(__u64 a0, __u64 b0, __u64 r0, __u8 width, __u8 *cf,
		  __u8 *zf, __u8 *sf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 m = mask_of(e);
	__u64 a = a0 & m, b = b0 & m, r = r0 & m, s = sign_of(e);

	*cf = (r < a);
	*zf = (r == 0);
	*sf = ((r & s) != 0);
	*of = (((~(a ^ b)) & ((a ^ r) & s)) != 0);
}

static void m_adc(__u64 a0, __u64 b0, __u8 carry, __u64 r0, __u8 width,
		  __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 m = mask_of(e);
	__u64 a = a0 & m, b = b0 & m, r = r0 & m, s = sign_of(e);

	*cf = ((r < a) || (carry && r == a));
	*zf = (r == 0);
	*sf = ((r & s) != 0);
	*of = (((~(a ^ b)) & ((a ^ r) & s)) != 0);
}

static void m_sbb(__u64 a0, __u64 b0, __u8 borrow, __u64 r0, __u8 width,
		  __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 m = mask_of(e);
	__u64 a = a0 & m, b = b0 & m, r = r0 & m, s = sign_of(e);

	*cf = ((a < b) || (borrow && a == b));
	*zf = (r == 0);
	*sf = ((r & s) != 0);
	*of = (((a ^ b) & ((a ^ r) & s)) != 0);
}

static void m_imul(__u64 lhs, __u64 rhs, __u8 width, __u8 *cf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u64 a_abs = abs_of(lhs, e);
	__u64 b_abs = abs_of(rhs, e);
	__u64 sign = 1ULL << (bits_of(e) - 1);
	__u64 limit = (((lhs ^ rhs) & sign) != 0) ? sign : sign - 1;
	__u8 ov = (a_abs != 0 && b_abs > limit / a_abs);

	*cf = ov;
	*of = ov;
}

static void m_shift(__u64 a0, __u64 rhs, __u64 r0, __u8 alu, __u8 width,
		    __u8 *cf, __u8 *zf, __u8 *sf, __u8 *of)
{
	__u8 e = eff_of(width);
	__u32 bits = bits_of(e);
	__u64 m = mask_of(e);
	__u64 a = a0 & m, r = r0 & m;
	__u8 count = cnt_of(rhs, e);
	__u64 sign = 1ULL << (bits - 1);

	if (count == 0)
		return;
	if (alu == X86_ALU_ROL) {
		*cf = (__u8)(r & 1);
		if (count == 1)
			*of = (__u8)((((r & sign) != 0) ^ (*cf)) != 0);
	} else {
		*zf = (r == 0);
		*sf = ((r & sign) != 0);
		if (alu == X86_ALU_SHL) {
			*cf = (__u8)(count <= bits
					     ? (((a >> (bits - count)) & 1) != 0)
					     : 0);
			if (count == 1)
				*of = (__u8)((*sf) ^ (*cf));
		} else if (alu == X86_ALU_SHR) {
			*cf = (__u8)(count <= bits
					     ? (((a >> (count - 1)) & 1) != 0)
					     : 0);
			if (count == 1)
				*of = (__u8)((a & sign) != 0);
		} else {
			*cf = (__u8)(count <= bits
					     ? (((a >> (count - 1)) & 1) != 0)
					     : ((a & sign) != 0));
			if (count == 1)
				*of = 0;
		}
	}
}

/* ---- Whole-state snapshot ---------------------------------------------- */

struct snap {
	void *p[16];
	__u8 t[16];
	__u8 cf, zf, sf, of;
	__u8 stack[X86_SIM_STACK_BYTES];
	__u8 heap[64];
};

#define SNAP_ONE(REG, NAME)                                                \
	do {                                                               \
		__p[__i] = __x86_##NAME.ptr;                               \
		__t[__i] = __x86_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define SNAP_ALL(P, T)                                                     \
	do {                                                               \
		void **__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(SNAP_ONE)                           \
	} while (0)

#define CAPTURE_ALL(S)                                                     \
	do {                                                               \
		unsigned __c;                                              \
		SNAP_ALL((S)->p, (S)->t);                                  \
		(S)->cf = __x86_cf;                                        \
		(S)->zf = __x86_zf;                                        \
		(S)->sf = __x86_sf;                                        \
		(S)->of = __x86_of;                                        \
		for (__c = 0; __c < X86_SIM_STACK_BYTES; __c++)            \
			(S)->stack[__c] = __x86_stack_mem.b[__c];          \
		for (__c = 0; __c < sizeof(heap); __c++)                   \
			(S)->heap[__c] = heap[__c];                        \
	} while (0)
/* The scenarios drive the routed bodies twice with the raw and the effective
 * code and require identical state. A stack-pointer value derived from a
 * per-call local arena would differ between the two frames, so one shared
 * arena stands in for the frame and is zeroed by DECL_STATE below. */
#undef X86_SIM_L_DECLARE_STACK
#define X86_SIM_L_DECLARE_STACK()
static union {
	__u8 b[X86_SIM_STACK_BYTES];
	__u64 q[(X86_SIM_STACK_BYTES + 7U) / 8U];
} __x86_stack_mem;

/* Quiet one declared local without evaluating it: an unevaluated `sizeof`
 * counts as a use for -Wunused-variable/-Wunused-but-set-variable while
 * keeping the register cells live for the driven bodies. */
#define QUIET_GPR_ONE(REG, NAME)                                           \
	(void)sizeof(__x86_##NAME);                                        \
	(void)sizeof(__x86_##NAME##_tag);

/* Declare and quiet the register file and the untouched control/depth
 * registers so every scenario compiles warning-free, and reset the shared
 * stack arena. */
#define DECL_STATE()                                                       \
	X86_SIM_L_DECLARE_STATE();                                         \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__x86_sim_abi_kind;                                          \
	(void)__x86_cf;                                                    \
	(void)__x86_zf;                                                    \
	(void)__x86_sf;                                                    \
	(void)__x86_of;                                                    \
	(void)__x86_xmm0_lo;                                               \
	(void)__x86_xmm0_hi;                                               \
	(void)__x86_sim_ret_addr;                                          \
	X86_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE);                             \
	memset(__x86_stack_mem.b, 0, X86_SIM_STACK_BYTES)

/* Seed every GPR cell inside the caller's own DECL_STATE() scope, so the
 * scenario's locals are the ones the driven body mutates. */
#define SEED_GPRS() X86_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)

#define SEED_GPR_ONE(REG, NAME)                                            \
	do {                                                               \
		__x86_##NAME.ptr =                                         \
			(void *)(__u64)(0x1000U + (__u64)(REG) * 0x100U + 0x77U);\
		__x86_##NAME##_tag = X86_SIM_TAG_SCALAR;                   \
	} while (0);


static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

static void fill_stack(__u8 *s)
{
	unsigned i;

	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		s[i] = (__u8)(0xa0U + i);
}

static int snap_eq(const struct snap *a, const struct snap *b, const char *what,
		   __u8 w)
{
	unsigned j;
	int bad = 0;

	for (j = 0; j < 16U; j++) {
		if (a->p[j] != b->p[j] || a->t[j] != b->t[j]) {
			printf("MISMATCH %s width=%u cell=%u ptr=%p/%p tag=%u/%u\n",
			       what, w, j, a->p[j], b->p[j], (unsigned)a->t[j],
			       (unsigned)b->t[j]);
			bad = 1;
		}
	}
	if (a->cf != b->cf || a->zf != b->zf || a->sf != b->sf ||
	    a->of != b->of) {
		printf("MISMATCH %s width=%u flags %u%u%u%u/%u%u%u%u\n", what, w,
		       a->cf, a->zf, a->sf, a->of, b->cf, b->zf, b->sf, b->of);
		bad = 1;
	}
	for (j = 0; j < X86_SIM_STACK_BYTES; j++) {
		if (a->stack[j] != b->stack[j]) {
			printf("MISMATCH %s width=%u stack[%u]=0x%02x/0x%02x\n",
			       what, w, j, a->stack[j], b->stack[j]);
			bad = 1;
		}
	}
	for (j = 0; j < sizeof(heap); j++) {
		if (a->heap[j] != b->heap[j]) {
			printf("MISMATCH %s width=%u heap[%u]=0x%02x/0x%02x\n",
			       what, w, j, a->heap[j], b->heap[j]);
			bad = 1;
		}
	}
	return !bad;
}

/* The contract's observable: the raw code and its effective code drive the
 * whole modeled state identically. */
static void check_equiv(const char *what, void (*fn)(__u8, struct snap *),
			__u8 w)
{
	struct snap a, b;

	fn(w, &a);
	fn(eff_of(w), &b);
	cases++;
	if (!snap_eq(&a, &b, what, w))
		failures++;
}

/* ---- Scenario runners (drive the routed bodies) ------------------------- */

static void scn_reg_read(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX,
		X86_SIM_L_READ_REG_WIDTH_SHIFT(X86_RAX, w, 8), X86_WIDTH_64);
	CAPTURE_ALL(s);
}

static void scn_reg_write(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT(X86_RAX, 0xa1b2c3d4e5f60718ULL, w, 8);
	CAPTURE_ALL(s);
}

static void scn_stack_write(__u8 w, struct snap *s)
{
	DECL_STATE();

	fill_stack(__x86_stack_mem.b);
	X86_SIM_L_STACK_WRITE((__s64)-8, w, 0x1122334455667788ULL);
	CAPTURE_ALL(s);
}

static void scn_stack_read(__u8 w, struct snap *s)
{
	DECL_STATE();

	fill_stack(__x86_stack_mem.b);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX,
		X86_SIM_L_STACK_READ((__s64)-8, w), X86_WIDTH_64);
	CAPTURE_ALL(s);
}

static void scn_logic_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_LOGIC_FLAGS(0x8000000000000000ULL, w);
	CAPTURE_ALL(s);
}

static void scn_sub_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_SUB_FLAGS(0x0000000000000005ULL, 0x0000000000000006ULL,
				0xffffffffffffffffULL, w);
	CAPTURE_ALL(s);
}

static void scn_add_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_ADD_FLAGS(0x7fffffffffffffffULL, 1ULL,
				0x8000000000000000ULL, w);
	CAPTURE_ALL(s);
}

static void scn_adc_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_ADC_FLAGS(0x00000000000000ffULL, 0ULL, 1ULL, 0ULL, w);
	CAPTURE_ALL(s);
}

static void scn_sbb_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_SBB_FLAGS(0x0000000000000000ULL, 1ULL, 1ULL,
				0xfffffffffffffffeULL, w);
	CAPTURE_ALL(s);
}

static void scn_imul_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 0;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 0;
	X86_SIM_L_SET_IMUL_FLAGS(0x00000000000000ffULL, 0x0000000000000002ULL, w);
	CAPTURE_ALL(s);
}

static void scn_shift_flags(__u8 w, struct snap *s)
{
	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 0;
	__x86_sf = 0;
	__x86_of = 1;
	X86_SIM_L_SET_SHIFT_FLAGS(0x80000000000000ffULL, 1ULL,
				  0x00000000000001feULL, X86_ALU_SHL, w);
	CAPTURE_ALL(s);
}

static void scn_read_mem(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX,
		X86_SIM_L_READ_MEM_VALUE(X86_RAX, aux, 8, w, 0), X86_WIDTH_64);
	CAPTURE_ALL(s);
}

static void scn_store_stack(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	fill_stack(__x86_stack_mem.b);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX, 0x0f0e0d0c0b0a0908ULL,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, w, aux,
			     (__u64)-8);
	CAPTURE_ALL(s);
}

static void scn_store_mem(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX, 0x0f0e0d0c0b0a0908ULL,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, w, aux, 4);
	CAPTURE_ALL(s);
}

static void scn_lea(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, w, aux, 8);
	CAPTURE_ALL(s);
}

static void scn_alu_imm(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, w,
		KPROG_X86_REG_LANE_AUX(X86_ALU_SHL, 0U, 0U), 1ULL);
	CAPTURE_ALL(s);
}

static void scn_alu_reg(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, w,
		KPROG_X86_REG_LANE_AUX(X86_ALU_ADD, 0U, 0U));
	CAPTURE_ALL(s);
}

static void scn_alu_mem(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_ALU_ADD);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, 0U, w, aux, 4);
	CAPTURE_ALL(s);
}

static void scn_alu_mem_unary(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_ALU_NOT);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, w, aux, 4);
	CAPTURE_ALL(s);
}

static void scn_alu_mem_imm(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_ALU_SUB);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, w, aux, 0x0000000300000001ULL);
	CAPTURE_ALL(s);
}

static void scn_alu_mem_reg(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_ALU_AND);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0x0000ffff0000ffffULL,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, w, aux, 4);
	CAPTURE_ALL(s);
}

static void scn_imul_imm(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0x0000000000000003ULL,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RCX, w, 0x00000000fffffffdULL);
	CAPTURE_ALL(s);
}

static void scn_imul_mem_imm(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RCX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RAX, X86_RCX, w, aux,
				    0x0000000200000003ULL);
	CAPTURE_ALL(s);
}

static void scn_mulx(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, 0x0123456789abcdefULL,
				  X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0xfedcba9876543210ULL,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RBX, w);
	CAPTURE_ALL(s);
}

static void scn_cmp_mem(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, 0U, w, aux,
			       0x0000000000000005ULL);
	CAPTURE_ALL(s);
}

static void scn_cmp_reg_mem(__u8 w, struct snap *s)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);

	DECL_STATE();

	SEED_GPRS();
	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RCX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, w, aux, 4);
	CAPTURE_ALL(s);
}

static void scn_mov_imm(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, w, 0xcafebabedeadbeefULL);
	CAPTURE_ALL(s);
}

static void scn_mov_imm_aux(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_MOV_IMM_AUX(X86_RAX, w,
		KPROG_X86_REG_LANE_AUX(0U, 8U, 0U), 0xcafebabedeadbeefULL);
	CAPTURE_ALL(s);
}

static void scn_mov_reg(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, w);
	CAPTURE_ALL(s);
}

static void scn_mov_reg_stack(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RSP, (__u64)(__s64)-32,
				  X86_WIDTH_64);
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSP, w);
	CAPTURE_ALL(s);
}

static void scn_mov_reg_aux(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_MOV_REG_AUX(X86_RAX, X86_RCX, w,
		KPROG_X86_REG_LANE_AUX(0U, 8U, 0U));
	CAPTURE_ALL(s);
}

static void scn_movx_reg(__u8 w, struct snap *s)
{
	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RCX, w, 0U);
	CAPTURE_ALL(s);
}

static void scn_exec_mov_imm(__u8 w, struct snap *s)
{
	DECL_STATE();

	__u64 imm = 0x0123456789abcdefULL;

	SEED_GPRS();
	X86_SIM_L_EXEC(X86_OP_MOV_IMM, X86_RAX, 0U, w, 0U, imm);
	CAPTURE_ALL(s);
}

/* ---- Exact width-resolution checks -------------------------------------- */

static __u32 stack_idx(__s64 off)
{
	return X86_SIM_L_STACK_INDEX(off);
}

static void check_contract_sweep(void)
{
	__u32 b;

	/* Exhaustive over the decoded code byte against the independent model. */
	for (b = 0; b <= 0xffU; b++) {
		cases++;
		if (X86_SIM_L_EFFECTIVE_WIDTH((__u8)b) != eff_of((__u8)b)) {
			printf("MISMATCH effective code=%u got=%u want=%u\n", b,
			       X86_SIM_L_EFFECTIVE_WIDTH((__u8)b),
			       eff_of((__u8)b));
			failures++;
		}
	}
	cases++;
	if (KPROG_X86_WIDTH_ABSENT_CODE != 0U) {
		printf("MISMATCH absent code %u\n",
		       (unsigned)KPROG_X86_WIDTH_ABSENT_CODE);
		failures++;
	}
	cases++;
	if (KPROG_X86_WIDTH_EFFECTIVE_DEFAULT != X86_WIDTH_64) {
		printf("MISMATCH effective default %u\n",
		       (unsigned)KPROG_X86_WIDTH_EFFECTIVE_DEFAULT);
		failures++;
	}
}

static void check_reg_read(__u8 w)
{
	__u64 val = 0x8899aabbccddeeffULL;
	__u64 got, want;

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, val, X86_WIDTH_64);
	got = X86_SIM_L_READ_REG_WIDTH_SHIFT(X86_RAX, w, 8);
	want = read_at(val, w, 8);
	cases++;
	if (got != want) {
		printf("MISMATCH reg_read width=%u got=0x%llx want=0x%llx\n", w,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

static void check_reg_write(__u8 w)
{
	__u64 val = 0xa1b2c3d4e5f60718ULL;
	void *want;

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH_SHIFT(X86_RAX, val, w, 8);
	want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U), val,
			     w, 8);
	cases++;
	if (__x86_rax.ptr != want || __x86_rax_tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH reg_write width=%u got=%p want=%p tag=%u\n", w,
		       __x86_rax.ptr, want, (unsigned)__x86_rax_tag);
		failures++;
	}
}

static void check_stack_roundtrip(__u8 w)
{
	__u64 val = 0x1122334455667788ULL;
	__u8 exp[X86_SIM_STACK_BYTES];
	__u32 m = stack_idx((__s64)-8);
	__u8 e = eff_of(w);
	__u64 got, want;
	unsigned i;

	DECL_STATE();

	fill_stack(__x86_stack_mem.b);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp[i] = __x86_stack_mem.b[i];
	if (e == X86_WIDTH_64 && (m & 7U) == 0U) {
		le_store(&exp[m], val, X86_WIDTH_64);
	} else {
		__u64 n = val & mask_of(e);

		exp[m] = (__u8)n;
		if (e >= X86_WIDTH_16)
			exp[m + 1] = (__u8)(n >> 8);
		if (e >= X86_WIDTH_32)
			exp[m + 2] = (__u8)(n >> 16), exp[m + 3] = (__u8)(n >> 24);
		if (e == X86_WIDTH_64)
			exp[m + 4] = (__u8)(n >> 32), exp[m + 5] = (__u8)(n >> 40),
			exp[m + 6] = (__u8)(n >> 48), exp[m + 7] = (__u8)(n >> 56);
	}
	X86_SIM_L_STACK_WRITE((__s64)-8, w, val);
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp[i]) {
			printf("MISMATCH stack_write width=%u idx=%u got=0x%02x want=0x%02x\n",
			       w, i, __x86_stack_mem.b[i], exp[i]);
			failures++;
			break;
		}
	}

	fill_stack(__x86_stack_mem.b);
	want = le_load(&__x86_stack_mem.b[m], e);
	if (e == X86_WIDTH_64 && (m & 7U) == 0U)
		want = le_load(&__x86_stack_mem.b[m], X86_WIDTH_64);
	got = X86_SIM_L_STACK_READ((__s64)-8, w);
	cases++;
	if (got != want) {
		printf("MISMATCH stack_read width=%u got=0x%llx want=0x%llx\n", w,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

static void check_read_mem(__u8 w)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	__u64 got, want;

	DECL_STATE();

	fill_patterns();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	got = X86_SIM_L_READ_MEM_VALUE(X86_RAX, aux, 8, w, 0);
	want = le_load(heap + 8, eff_of(w));
	cases++;
	if (got != want) {
		printf("MISMATCH read_mem width=%u got=0x%llx want=0x%llx\n", w,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

static void check_store_stack(__u8 w)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	__u8 exp[X86_SIM_STACK_BYTES];
	__u32 m = stack_idx((__s64)-8);
	__u64 value = 0x0f0e0d0c0b0a0908ULL;
	unsigned i;

	DECL_STATE();

	fill_stack(__x86_stack_mem.b);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp[i] = __x86_stack_mem.b[i];
	le_store(&exp[m], value, eff_of(w));
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX, value, X86_WIDTH_64);
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, w, aux,
			     (__u64)-8);
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp[i]) {
			printf("MISMATCH store_stack width=%u idx=%u got=0x%02x want=0x%02x\n",
			       w, i, __x86_stack_mem.b[i], exp[i]);
			failures++;
			break;
		}
	}
}

static void check_store_mem(__u8 w)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	__u8 exp[64];
	__u64 value = 0x0f0e0d0c0b0a0908ULL;
	unsigned i;

	DECL_STATE();

	fill_patterns();
	for (i = 0; i < 64U; i++)
		exp[i] = heap[i];
	le_store(&exp[4], value, eff_of(w));
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_SCALAR);
	X86_SIM_L_WRITE_REG_WIDTH(X86_RBX, value, X86_WIDTH_64);
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, w, aux, 4);
	cases++;
	for (i = 0; i < 64U; i++) {
		if (heap[i] != exp[i]) {
			printf("MISMATCH store_mem width=%u idx=%u got=0x%02x want=0x%02x\n",
			       w, i, heap[i], exp[i]);
			failures++;
			break;
		}
	}
}

static void check_lea(__u8 w)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	void *want;
	__u8 e = eff_of(w);

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBX, heap, X86_SIM_TAG_SCALAR);
	if (e == X86_WIDTH_64)
		want = (void *)(heap + 8);
	else
		want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U),
				     (__u64)(long)(heap + 8), e, 0U);
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, w, aux, 8);
	cases++;
	if (__x86_rax.ptr != want || __x86_rax_tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH lea width=%u got=%p want=%p\n", w,
		       __x86_rax.ptr, want);
		failures++;
	}
}

static void check_mov_imm(__u8 w)
{
	__u64 val = 0xcafebabedeadbeefULL;
	void *want;

	DECL_STATE();

	SEED_GPRS();
	want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U), val,
			     w, 0U);
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, w, val);
	cases++;
	if (__x86_rax.ptr != want || __x86_rax_tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH mov_imm width=%u got=%p want=%p\n", w,
		       __x86_rax.ptr, want);
		failures++;
	}
}

static void check_mov_reg(__u8 w)
{
	void *src;
	void *want;
	__u8 e = eff_of(w);

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0x0000ffffffff0000ULL,
				  X86_WIDTH_64);
	src = (void *)(__u64)0x0000ffffffff0000ULL;
	if (e == X86_WIDTH_64)
		want = src;
	else
		want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U),
				     (__u64)(long)src, e, 0U);
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, w);
	cases++;
	if (__x86_rax.ptr != want || __x86_rax_tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH mov_reg width=%u got=%p want=%p tag=%u\n", w,
		       __x86_rax.ptr, want, (unsigned)__x86_rax_tag);
		failures++;
	}
}

/* ALU_MEM is register-destination with a memory source: DST holds the left
 * operand and receives the result, SRC's effective address supplies the right
 * operand at the resolved width. */
static void check_alu_mem_add(__u8 w)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_ALU_ADD);
	__u8 e = eff_of(w);
	void *want;
	__u64 lhs, rhs, result;

	DECL_STATE();

	fill_patterns();
	SEED_GPRS();
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RCX, heap, X86_SIM_TAG_SCALAR);
	lhs = 0x1000U + 0 * 0x100U + 0x77U;
	rhs = le_load(heap + 4, e);
	result = alu_of(X86_ALU_ADD, lhs, rhs, e);
	want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U),
			     result, e, 0U);
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, w, aux, 4);
	cases++;
	if (__x86_rax.ptr != want || __x86_rax_tag != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH alu_mem_add width=%u got=%p want=%p\n", w,
		       __x86_rax.ptr, want);
		failures++;
	}
}

static void check_imul_imm(__u8 w)
{
	void *want;
	__u64 lhs, rhs, result;
	__u8 e = eff_of(w);

	DECL_STATE();

	SEED_GPRS();
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0x0000000000000003ULL,
				  X86_WIDTH_64);
	lhs = 0x0000000000000003ULL;
	rhs = ext_of(0x00000000fffffffdULL, e);
	result = lhs * rhs;
	want = model_reg_ptr((void *)(__u64)(0x1000U + 0 * 0x100U + 0x77U),
			     result, e, 0U);
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RCX, w, 0x00000000fffffffdULL);
	cases++;
	if (__x86_rax.ptr != want) {
		printf("MISMATCH imul_imm width=%u got=%p want=%p\n", w,
		       __x86_rax.ptr, want);
		failures++;
	}
}

/* ---- Exact flag-setter checks ------------------------------------------- */

#define CHECK_FLAGS(what, w, ecf, ezf, esf, eof)                          \
	do {                                                              \
		cases++;                                                  \
		if (__x86_cf != (ecf) || __x86_zf != (ezf) ||             \
		    __x86_sf != (esf) || __x86_of != (eof))               \
			printf("MISMATCH %s width=%u flags %u%u%u%u "     \
			       "want %u%u%u%u\n",                        \
			       what, w, __x86_cf, __x86_zf, __x86_sf,     \
			       __x86_of, (unsigned)(ecf), (unsigned)(ezf),\
			       (unsigned)(esf), (unsigned)(eof)),         \
				failures++;                               \
	} while (0)

static void check_logic_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_LOGIC_FLAGS(0x8000000000000000ULL, w);
	m_logic(0x8000000000000000ULL, w, &cf, &zf, &sf, &of);
	CHECK_FLAGS("logic_flags", w, cf, zf, sf, of);
}

static void check_sub_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_SUB_FLAGS(5ULL, 6ULL, 0xffffffffffffffffULL, w);
	m_sub(5ULL, 6ULL, 0xffffffffffffffffULL, w, &cf, &zf, &sf, &of);
	CHECK_FLAGS("sub_flags", w, cf, zf, sf, of);
}

static void check_add_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_ADD_FLAGS(0x7fffffffffffffffULL, 1ULL,
				0x8000000000000000ULL, w);
	m_add(0x7fffffffffffffffULL, 1ULL, 0x8000000000000000ULL, w, &cf, &zf,
	      &sf, &of);
	CHECK_FLAGS("add_flags", w, cf, zf, sf, of);
}

static void check_adc_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_ADC_FLAGS(0xffULL, 0ULL, 1ULL, 0ULL, w);
	m_adc(0xffULL, 0ULL, 1, 0ULL, w, &cf, &zf, &sf, &of);
	CHECK_FLAGS("adc_flags", w, cf, zf, sf, of);
}

static void check_sbb_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 1;
	X86_SIM_L_SET_SBB_FLAGS(0ULL, 1ULL, 1ULL, 0xfffffffffffffffeULL, w);
	m_sbb(0ULL, 1ULL, 1, 0xfffffffffffffffeULL, w, &cf, &zf, &sf, &of);
	CHECK_FLAGS("sbb_flags", w, cf, zf, sf, of);
}

static void check_imul_flags(__u8 w)
{
	__u8 cf, of;

	DECL_STATE();

	__x86_cf = 0;
	__x86_zf = 1;
	__x86_sf = 1;
	__x86_of = 0;
	X86_SIM_L_SET_IMUL_FLAGS(0xffULL, 2ULL, w);
	m_imul(0xffULL, 2ULL, w, &cf, &of);
	cases++;
	if (__x86_cf != cf || __x86_of != of || __x86_zf != 1 ||
	    __x86_sf != 1) {
		printf("MISMATCH imul_flags width=%u cf=%u of=%u zf=%u sf=%u "
		       "want cf=%u of=%u\n", w, __x86_cf, __x86_of, __x86_zf,
		       __x86_sf, cf, of);
		failures++;
	}
}

static void check_shift_flags(__u8 w)
{
	__u8 cf, zf, sf, of;

	DECL_STATE();

	__x86_cf = 1;
	__x86_zf = 0;
	__x86_sf = 0;
	__x86_of = 1;
	X86_SIM_L_SET_SHIFT_FLAGS(0x80000000000000ffULL, 1ULL,
				  0x00000000000001feULL, X86_ALU_SHL, w);
	cf = __x86_cf;
	zf = __x86_zf;
	sf = __x86_sf;
	of = __x86_of;
	m_shift(0x80000000000000ffULL, 1ULL, 0x00000000000001feULL,
		X86_ALU_SHL, w, &cf, &zf, &sf, &of);
	CHECK_FLAGS("shift_flags", w, cf, zf, sf, of);
}

int main(void)
{
	static const __u8 widths[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	unsigned i;

	check_contract_sweep();

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		__u8 w = widths[i];

		check_reg_read(w);
		check_reg_write(w);
		check_stack_roundtrip(w);
		check_read_mem(w);
		check_store_stack(w);
		check_store_mem(w);
		check_lea(w);
		check_mov_imm(w);
		check_mov_reg(w);
		check_alu_mem_add(w);
		check_imul_imm(w);

		check_logic_flags(w);
		check_sub_flags(w);
		check_add_flags(w);
		check_adc_flags(w);
		check_sbb_flags(w);
		check_imul_flags(w);
		check_shift_flags(w);
	}

	/* The contract's observable on every routed body: code 0 == code 64. */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		__u8 w = widths[i];

		check_equiv("reg_read", scn_reg_read, w);
		check_equiv("reg_write", scn_reg_write, w);
		check_equiv("stack_write", scn_stack_write, w);
		check_equiv("stack_read", scn_stack_read, w);
		check_equiv("logic_flags", scn_logic_flags, w);
		check_equiv("sub_flags", scn_sub_flags, w);
		check_equiv("add_flags", scn_add_flags, w);
		check_equiv("adc_flags", scn_adc_flags, w);
		check_equiv("sbb_flags", scn_sbb_flags, w);
		check_equiv("imul_flags", scn_imul_flags, w);
		check_equiv("shift_flags", scn_shift_flags, w);
		check_equiv("read_mem", scn_read_mem, w);
		check_equiv("store_stack", scn_store_stack, w);
		check_equiv("store_mem", scn_store_mem, w);
		check_equiv("lea", scn_lea, w);
		check_equiv("alu_imm", scn_alu_imm, w);
		check_equiv("alu_reg", scn_alu_reg, w);
		check_equiv("alu_mem", scn_alu_mem, w);
		check_equiv("alu_mem_unary", scn_alu_mem_unary, w);
		check_equiv("alu_mem_imm", scn_alu_mem_imm, w);
		check_equiv("alu_mem_reg", scn_alu_mem_reg, w);
		check_equiv("imul_imm", scn_imul_imm, w);
		check_equiv("imul_mem_imm", scn_imul_mem_imm, w);
		check_equiv("mulx", scn_mulx, w);
		check_equiv("cmp_mem", scn_cmp_mem, w);
		check_equiv("cmp_reg_mem", scn_cmp_reg_mem, w);
		check_equiv("mov_imm", scn_mov_imm, w);
		check_equiv("mov_imm_aux", scn_mov_imm_aux, w);
		check_equiv("mov_reg", scn_mov_reg, w);
		check_equiv("mov_reg_stack", scn_mov_reg_stack, w);
		check_equiv("mov_reg_aux", scn_mov_reg_aux, w);
		check_equiv("movx_reg", scn_movx_reg, w);
		check_equiv("exec_mov_imm", scn_exec_mov_imm, w);
	}

	if (failures != 0) {
		printf("x86 width effective route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 width effective route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
