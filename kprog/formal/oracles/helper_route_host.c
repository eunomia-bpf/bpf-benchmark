/*
 * Route host cross-check for the AArch64 simulator's BPF helper-call body
 * family `ARM64_SIM_BPF_CALL_*` in `../arm64/arm64_sim_local_bpf.h`
 * (STEP 0454, mutation battery 0454).
 *
 * Every helper body is a `do{..}while(0)` sequence of argument reads
 * (`ARM64_SIM_L_READ_REG_PTR` raw, `ARM64_SIM_L_HELPER_ARG_PTR` with the
 * stack-arena redirect, `ARM64_SIM_L_READ_REG` scalar) and one X0 commit
 * (`ARM64_SIM_L_WRITE_REG_WIDTH` 64/32-bit, or `ARM64_SIM_L_WRITE_REG_PTR_TAG`
 * with a provenance tag). All61 original body scenes remain, now using real
 * typed calls and nonzero returns. Per-CPU lookup and copy-from-task check their
 * distinct public ABIs, including their additional arguments.
 *
 * This oracle defines each native `bpf_*` helper as a capturing stub (the
 * `__BPF_HELPERS__` guard kills libbpf's fake helper consts), plants the
 * full register file plus the stack-arena image and word tags, drives the
 * real macro, and compares three observable layers against an independent
 * model: the captured stub lanes (each lane's landed value — which
 * distinguishes raw-ptr vs arena-redirect vs scalar read), the X0 value +
 * provenance tag after the commit, and every other register cell + SP +
 * NZCV. A body reading the wrong lane, skipping the arena redirect,
 * misnaming the native, widening or narrowing the commit, or painting the
 * wrong tag falls out as a capture, value, or tag difference.
 *
 * Stack-arena convention (both sides agree by construction): each
 * stack-tagged argument is planted at a valid distinct arena offset, so its redirected pointer
 * points into `__a64_stack.b` at that offset, independently of its contents.
 * Output buffers use bounded lengths, and an independent byte-interval model
 * checks every stack byte and whole-word provenance tag after each call.
 * Raw-pointer lanes pass the register value through unchanged. A body that
 * reads the wrong lane gets a peripheral byte (or reg pattern) and fails
 * the compare.
 *
 * Build and run: make -C kprog/formal check
 */

#define __BPF_HELPERS__ 1
#define ARM64_SIM_ENABLE_STACK 1

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#pragma GCC diagnostic push
/* The -O2 const-folding of the -Warray-bounds pass trips over the
 * unreachable sentinel-lane pointer reads of the sibling dispatcher arms
 * inside the shared generated load/store byte ladders
 * (`generated/arm64_load_bytes.h`, a `(void *)0 + offset` load through the
 * register sentinel that no reachable helper arm dereferences). Every other
 * fact stays under the same -Werror wall. */
#pragma GCC diagnostic ignored "-Warray-bounds"
#define ORA_MAP_PTR 0x0000123400005678ULL
#define ORA_UPD_RET (-7LL)
#define ORA_DEL_RET 3LL
#define ORA_KTIME 0xaabbccddeeff0011ULL
#define ORA_KTIME_BOOT 0x1122334455667788ULL
#define ORA_PROBE (-9LL)
#define ORA_PERF 5LL
#define ORA_SKB (-3LL)
#define ORA_CSUM 11LL

#include "generated_helper_calls.h"
#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The success fixture executes a real bounded copy as well as capturing the
 * public ABI. Default failures retain the original capture-only scenes. */
static int probe_succeeds;
static long capture_probe_kernel(void *dst, __u32 size, const void *src)
{
    long result = bpf_probe_read_kernel(dst, size, src);
    if (probe_succeeds) {
        memcpy(dst, src, size);
        return 0;
    }
    return result;
}
#define bpf_probe_read_kernel capture_probe_kernel

/* The host environment reports the production callback as a failed scene. */
static void arm64_sim_unsupported_opcode(void)
{
    fputs("unexpected helper-route unsupported opcode\n", stderr);
    exit(1);
}

static int failures;
static unsigned long cases;

/* Per-scene capture scratch so rows never read stale lanes. Value-only:
 * a pointer lane lands the pointer bit pattern the stub actually
 * received (raw register value, or the arena byte address after the
 * redirect), a value lane lands the register bit pattern. */
#define last_val ora_arguments
#define last_n ora_argc

static void capture_reset(void)
{
	unsigned i;
	for (i = 0; i < 5; i++) last_val[i] = 0xabcdefabcdefabcdULL;
	last_n = 0;
	ora_called = 0;
}

/* ------------------------------------------------------------ */
/* Model state.                                                  */
/* ------------------------------------------------------------ */

static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;

/* The stack-arena image and its word tags, the model-side mirror of the
 * sim's own `__a64_stack.b` / `__a64_stack_tag`. A helper-argument lane
 * resolves `&__a64_stack.b[ARM64_SIM_STACK_BIAS + reg]` exactly when the
 * argument register's provenance tag is the stack tag. */
#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

static void reset_arena_model(void)
{
    unsigned i;
    for (i = 0; i < STACK_BYTES; i++) stk_img[i] = (__u8)(0xc0U + i * 7U);
    for (i = 0; i < STACK_SLOTS; i++) stk_tag_img[i] = (__u8)(1U + i % 5U);
}

/* Literal helper identities and public argument positions are independent of
 * production's FULL_WRITES table. Only stack outputs need bounded fixture sizes;
 * nonstack cases retain their original full-width ABI argument patterns. */
static int writer_destination(unsigned id)
{
    switch (id) {
    case 4: case 16: case 45: case 112: case 113: case 114: case 115: case 148: return 0;
    case 26: case 68: return 2;
    case 67: return 1;
    default: return -1;
    }
}

static unsigned writer_length(unsigned id)
{
    return id == 67 ? 2 : (id == 26 || id == 68) ? 3 : 1;
}

static __u64 fixture_result(unsigned id)
{
    return id == 113 && probe_succeeds ? 0 : ora_expected_result(id);
}

static void model_helper_effect(unsigned id, __u64 result)
{
    int destination = writer_destination(id);
    unsigned i;
    __u8 old_tags[STACK_SLOTS];
    __u64 length, start, end, source;
    int copy;
    if (destination < 0 || mtag[destination] != 4U) return;
    length = (__u32)mreg[writer_length(id)];
    start = 96 + (__s64)mreg[destination];
    end = start + length;
    if (start > STACK_BYTES || end > STACK_BYTES || end < start) {
        fprintf(stderr, "helper route fixture output outside arena: helper%u\n", id);
        exit(1);
    }
    copy = (id == 4 || id == 112 || id == 113 || id == 148) && result == 0 && mtag[2] == 4U;
    source = 96 + (__s64)mreg[2];
    if (copy && (source > STACK_BYTES || length > STACK_BYTES - source)) {
        fprintf(stderr, "helper route fixture source outside arena: helper%u\n", id);
        exit(1);
    }
    memcpy(old_tags, stk_tag_img, sizeof(old_tags));
    for (i = 0; i < STACK_SLOTS; i++) {
        __u64 word = 8U * i;
        if (length && start < word + 8 && word < end) {
            stk_tag_img[i] = 0;
            if (copy && start <= word && word + 8 <= end && !((source + word - start) & 7U))
                stk_tag_img[i] = old_tags[(source + word - start) / 8];
        }
    }
    if (id == 113 && probe_succeeds) memcpy(stk_img + start, stk_img + source, length);
}

/* A deterministic register pattern: distinct per index, never zero (so a
 * stale zero-write arm cannot alias a planted pointer), high bits set (so
 * a 64-bit-vs-narrow commit is observable). */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

/* Non-scalar tag pattern: never SCALAR, so a tag repaint on any cell is
 * observable even when the pointer bytes survive. */
static __u8 pattern_tag(unsigned i)
{
	/* numeric literals: a TAG-define repaint in the header must make
	 * the sim diverge, so the model cannot share the symbol */
	static const __u8 tags[5] = { 4U, 1U, 2U, 5U, 6U };

	return tags[i % 5U];
}

#define QUIET_GPR(REG, NAME)                                               \
	do {                                                               \
		(void)__a64_##NAME;                                        \
		(void)__a64_##NAME##_tag;                                  \
	} while (0);

/* Runtime-cell register write: the plant loop indexes cells by number,
 * so the write goes through a `FOR_EACH_GPR` switch that names the cell
 * locals directly (a runtime-index `ARM64_SIM_L_WRITE_REG_*` references
 * cell locals the switch cannot see). */
#define PLANT_WRITE(REG, NAME)                                             \
	case REG:                                                          \
		__a64_##NAME.ptr = __a64_plant_ptr;                        \
		__a64_##NAME##_tag = __a64_plant_tag;                      \
		break;

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_sp;                                                    \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR);                               \
	(void)__a64_lr;                                                    \
	(void)__a64_v0;                                                    \
	(void)__a64_v0_hi;

#define INIT_ARENA()                                                       \
	do {                                                               \
		unsigned __ai_i;                                           \
		reset_arena_model();                                      \
		for (__ai_i = 0; __ai_i < STACK_BYTES; __ai_i++)            \
			__a64_stack.b[__ai_i] = stk_img[__ai_i];           \
		for (__ai_i = 0; __ai_i < STACK_SLOTS; __ai_i++)            \
			__a64_stack_tag[__ai_i] = stk_tag_img[__ai_i];     \
	} while (0)

/* Plant the simulator and model register files with the identical
 * pattern; the caller pins lanes afterwards (see the plant_* helpers).
 * The sim-side write goes through a `FOR_EACH_GPR` switch that names the
 * cell locals directly (a runtime-index `ARM64_SIM_L_WRITE_REG_*` cannot
 * see the cell locals). */
#define PLANT_STATE()                                                      \
	do {                                                               \
		unsigned __pl_i;                                           \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                  \
			void *__a64_plant_ptr =                            \
				(void *)(long)pattern_reg(__pl_i);         \
			__u8 __a64_plant_tag = pattern_tag(__pl_i);         \
			switch (__pl_i) {                                  \
			ARM64_SIM_L_FOR_EACH_GPR(PLANT_WRITE)               \
			default: break;                                    \
			}                                                  \
			mreg[__pl_i] = pattern_reg(__pl_i);                \
			mtag[__pl_i] = pattern_tag(__pl_i);                \
		}                                                          \
		__a64_sp = -96LL;                                          \
		msp = -96LL;                                               \
	} while (0)

#define COMPARE_GOT(REG, NAME)                                             \
	case REG:                                                          \
		__cs_got = __a64_##NAME.x;                                 \
		__cs_tag = __a64_##NAME##_tag;                             \
		break;

/* Full-file compare: every register value + provenance tag + the stack
 * pointer + NZCV, sim side against the model side. VIA names the scene;
 * `return` from the enclosing scene on first mismatch. The per-cell read
 * goes through a `FOR_EACH_GPR` switch that names the cell locals
 * directly (a runtime-index `ARM64_SIM_L_READ_REG` cannot see the cell
 * locals). */
#define COMPARE_REG_STATE(VIA)                                             \
	do {                                                               \
		unsigned __cs_i;                                           \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                  \
			__u64 __cs_got = 0;                                \
			__u8 __cs_tag = 0U;               \
			__u64 __cs_want = __cs_i > 0 && __cs_i < 19 ? 0 : mreg[__cs_i]; \
			__u8 __cs_want_tag = __cs_i > 0 && __cs_i < 19 ? 0 : mtag[__cs_i]; \
			switch (__cs_i) {                                  \
			ARM64_SIM_L_FOR_EACH_GPR(COMPARE_GOT)               \
			default: break;                                    \
			}                                                  \
			cases++;                                           \
			if (__cs_got != __cs_want) {                    \
				printf("MISMATCH %s reg%u: got 0x%llx "     \
				       "want 0x%llx\n", (VIA),             \
				       (unsigned)__cs_i,                   \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)__cs_want);  \
				failures++;                                \
				return;                                    \
			}                                                  \
			cases++;                                           \
			if (__cs_tag != __cs_want_tag) {                    \
				printf("MISMATCH %s reg%u tag: got %u "     \
				       "want %u\n", (VIA),                 \
				       (unsigned)__cs_i, __cs_tag,         \
				       __cs_want_tag);                      \
				failures++;                                \
				return;                                    \
			}                                                  \
		}                                                          \
		for (__cs_i = 0; __cs_i < STACK_BYTES; __cs_i++) {           \
			cases++;                                           \
			if (__a64_stack.b[__cs_i] != stk_img[__cs_i]) {      \
				printf("MISMATCH %s arena byte%u\n", (VIA), __cs_i); \
				failures++; return;                         \
			}                                                  \
		}                                                          \
		for (__cs_i = 0; __cs_i < STACK_SLOTS; __cs_i++) {           \
			cases++;                                           \
			if (__a64_stack_tag[__cs_i] != stk_tag_img[__cs_i]) { \
				printf("MISMATCH %s arena tag%u: got%u want%u\n", \
				 (VIA), __cs_i, __a64_stack_tag[__cs_i], stk_tag_img[__cs_i]); \
				failures++; return;                         \
			}                                                  \
		}                                                          \
		cases++;                                                   \
		if (__a64_sp != msp) {                                     \
			printf("MISMATCH %s sp: got %lld want %lld\n",     \
			       (VIA), (long long)__a64_sp,                 \
			       (long long)msp);                            \
			failures++;                                        \
			return;                                            \
		}                                                          \
		cases++;                                                   \
		if (__a64_n != 0U || __a64_z != 0U || __a64_c != 0U ||      \
		    __a64_v != 0U) {                                       \
			printf("MISMATCH %s nzcv drifted\n", (VIA));       \
			failures++;                                        \
			return;                                            \
		}                                                          \
	} while (0)

/* The scene's expected X0 commit (value + provenance tag). */
static __u64 want_x0;
static __u8 want_x0_tag;

static void expect_commit(__u64 val, __u8 tag)
{
	want_x0 = val;
	want_x0_tag = tag;
}

/* Commit-lane compare: X0 value + provenance tag against the scene's model
 * row (the width-truncation and tag-paint semantics live here). */
#define COMPARE_X0(VIA)                                                    \
	do {                                                               \
		cases++;                                                   \
		if (__a64_x0.x != want_x0) {                               \
			printf("MISMATCH %s x0: got 0x%llx want 0x%llx\n",  \
			       (VIA),                                      \
			       (unsigned long long)__a64_x0.x,             \
			       (unsigned long long)want_x0);               \
			failures++;                                        \
			return;                                            \
		}                                                          \
		cases++;                                                   \
		if (__a64_x0_tag != want_x0_tag) {                         \
			printf("MISMATCH %s x0 tag: got %u want %u\n",      \
			       (VIA), __a64_x0_tag, want_x0_tag);           \
			failures++;                                        \
			return;                                            \
		}                                                          \
	} while (0)

/* Capture-layer compare: the stub must have recorded exactly the lane
 * values the model names, in order, with exactly `n` lanes. */
static void compare_capture(const char *via, const __u64 *v, unsigned n, unsigned identity)
{
	unsigned i;

	cases++;
	if (ora_called != identity) {
		printf("MISMATCH %s helper identity: got %u want %u\n", via, ora_called, identity);
		failures++;
		return;
	}
	if (last_n != n) {
		printf("MISMATCH %s capture lanes: got %u want %u\n", via,
		       last_n, n);
		failures++;
		return;
	}
	for (i = 0; i < n; i++) {
		if (last_val[i] != v[i]) {
			printf("MISMATCH %s lane %u: got 0x%llx want "
			       "0x%llx\n", via, i,
			       (unsigned long long)last_val[i],
			       (unsigned long long)v[i]);
			failures++;
			return;
		}
	}
}

/* ------------------------------------------------------------ */
/* Lane plants. Each names the sim and model sides at once via    */
/* direct cell-local writes inside the scene's DECL_STATE scope;  */
/* a runtime-index `ARM64_SIM_L_WRITE_REG_*` cannot see the cell  */
/* locals, so the scene pins each register by its macro name.     */
/* ------------------------------------------------------------ */

#define PLANT_RAW(REG, NAME, VAL)                                          \
	do {                                                               \
		__a64_##NAME.ptr = (void *)(long)(VAL);                    \
		__a64_##NAME##_tag = 5U;                 \
		mreg[(REG)] = (VAL);                                       \
		mtag[(REG)] = 5U;                        \
	} while (0)

#define PLANT_STACK_TAGGED(REG, NAME, OFF)                                 \
	do {                                                               \
		__a64_##NAME.ptr = (void *)(unsigned long)(OFF);            \
		__a64_##NAME##_tag = 4U;                                   \
		mreg[(REG)] = (OFF);                                       \
		mtag[(REG)] = 4U;                                          \
	} while (0)

#define PLANT_VAL(REG, NAME, VAL)                                          \
	do {                                                               \
		__a64_##NAME.x = (VAL);                                    \
		__a64_##NAME##_tag = 0U;                  \
		mreg[(REG)] = (VAL);                                       \
		mtag[(REG)] = 0U;                         \
	} while (0)

/* The expected captured value of a stack-ARG lane: the arena byte
 * address at `ARM64_SIM_STACK_BIAS + off` (the `READ_REG_PTR`-fed raw
 * pointer passes the register value unchanged, so only ARG lanes get
 * this transform). */
#define ARG_LANE_VALUE(OFF)                                               \
	((__u64)(unsigned long)(void *)&__a64_stack.b[                     \
		KPROG_ARM64_STACK_PTR_INDEX((OFF), ARM64_SIM_STACK_BIAS)])

#define PREPARE_TYPED_HELPER_AT(ID, ADJUST)                                           \
	__u64 typed_raw[5], typed_want[5];                                 \
	unsigned typed_n, typed_j;                                        \
	for (typed_j = 0; typed_j < 5; typed_j++) {                         \
		if ((ADJUST) && (ora_pointer_arguments(ID) & (1U << typed_j)) && \
		    mtag[typed_j] == 4U) {                                \
			void *__a64_plant_ptr = (void *)(long)(12 + typed_j * 8); \
			__u8 __a64_plant_tag = 4U;                         \
			mreg[typed_j] = 12 + typed_j * 8;                  \
			switch (typed_j) { ARM64_SIM_L_FOR_EACH_GPR(PLANT_WRITE) } \
		}                                                        \
		typed_raw[typed_j] =                                      \
			((ora_pointer_arguments(ID) & (1U << typed_j)) &&  \
			 mtag[typed_j] == 4U) ?                            \
			ARG_LANE_VALUE((__s64)mreg[typed_j]) : mreg[typed_j]; \
	}                                                                 \
	model_helper_effect((ID), fixture_result(ID));                    \
	typed_n = ora_expected_arguments((ID), typed_raw, typed_want);      \
	expect_commit(fixture_result(ID), ora_pointer_result(ID) ? 6U : 0U); \
	mreg[0] = fixture_result(ID);                                 \
	mtag[0] = ora_pointer_result(ID) ? 6U : 0U;                         \
	capture_reset()

#define PREPARE_TYPED_HELPER(ID) PREPARE_TYPED_HELPER_AT(ID, 1)

#define CHECK_TYPED_HELPER(VIA, ID) do {                                 \
	compare_capture((VIA), typed_want, typed_n, (ID));                  \
	COMPARE_X0(VIA);                                                  \
	COMPARE_REG_STATE(VIA);                                           \
} while (0)

/* --- map lookup (X0 raw REG, X1 stack ARG) : PTR_TAG MAP_VALUE --- */
static void scene_lookup(const char *via, unsigned percpu)
{
	__u64 v[3];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x5151515151515151ULL);
	PLANT_STACK_TAGGED(ARM64_X1, x1, 12);
	v[0] = mreg[0];
	v[1] = ARG_LANE_VALUE(12);
	if (percpu) { PLANT_VAL(ARM64_X2, x2, 37); v[2] = 37; }
	expect_commit(ORA_MAP_PTR, 6U);

	capture_reset();
	if (percpu)
		ARM64_SIM_BPF_CALL_bpf_map_lookup_percpu_elem();
	else
		ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();

	mreg[0] = ORA_MAP_PTR;
	mtag[0] = 6U;

	compare_capture(via, v, percpu ? 3 : 2, percpu ? 195 : 1);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

static void scene_update(void)
{
	__u64 v[4];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x5252525252525252ULL);
	PLANT_STACK_TAGGED(ARM64_X1, x1, 12);
	PLANT_STACK_TAGGED(ARM64_X2, x2, 20);
	PLANT_VAL(ARM64_X3, x3, 10);
	v[0] = mreg[0];
	v[1] = ARG_LANE_VALUE(12);
	v[2] = ARG_LANE_VALUE(20);
	v[3] = 10;
	expect_commit(ORA_UPD_RET, 0U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_map_update_elem();

	mreg[0] = (__u64)(long)ORA_UPD_RET;
	mtag[0] = 0U;

	compare_capture("map_update", v, 4, 2);
	COMPARE_X0("map_update");
	COMPARE_REG_STATE("map_update");
}

/* --- map delete (X0 raw, X1 stack ARG) : WIDTH_64 commit --- */
static void scene_delete(void)
{
	__u64 v[2];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x5353535353535353ULL);
	PLANT_STACK_TAGGED(ARM64_X1, x1, 12);
	v[0] = mreg[0];
	v[1] = ARG_LANE_VALUE(12);
	expect_commit(ORA_DEL_RET, 0U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_map_delete_elem();

	mreg[0] = (__u64)(long)ORA_DEL_RET;
	mtag[0] = 0U;

	compare_capture("map_delete", v, 2, 3);
	COMPARE_X0("map_delete");
	COMPARE_REG_STATE("map_delete");
}

/* --- Tail call and scalar identity helpers, all forwarding real arguments. */
static void scene_identity(const char *via, unsigned which)
{
	static const unsigned ids[] = {12, 15, 8, 80};
	unsigned identity = ids[which];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	/* Seed X0 so both return bits and the scalar tag write are observable. */
	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	/* Model the public argument conversions and actual nonzero return. */
	PREPARE_TYPED_HELPER(identity);
	switch (which) {
	case 0:
		ARM64_SIM_BPF_CALL_bpf_tail_call();
		break;
	case 1:
		ARM64_SIM_BPF_CALL_bpf_get_current_uid_gid();
		break;
	case 2:
		ARM64_SIM_BPF_CALL_bpf_get_smp_processor_id();
		break;
	default:
		ARM64_SIM_BPF_CALL_bpf_get_current_cgroup_id();
		break;
	}

	CHECK_TYPED_HELPER(via, identity);
}

/* --- Jiffies64 has its own callee identity and nonzero return. */
static void scene_jiffies(void)
{
	unsigned identity = 118U;

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	PREPARE_TYPED_HELPER(identity);
	ARM64_SIM_BPF_CALL_bpf_jiffies64();

	CHECK_TYPED_HELPER("jiffies64", identity);
}

/* --- Current-task returns the public integer address type. --- */
static void scene_task(const char *via)
{
	unsigned identity = 35U;

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0x5600000000000000ULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0x5600000000000000ULL;
	mtag[0] = 6U;

	PREPARE_TYPED_HELPER(identity);
	ARM64_SIM_BPF_CALL_bpf_get_current_task();

	CHECK_TYPED_HELPER(via, identity);
}

/* --- ktime natives (no lanes, X0 = the native value, SCALAR) --- */
static void scene_ktime(const char *via, unsigned boot)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_VAL(ARM64_X0, x0, 0x5757575757575757ULL);

	expect_commit(boot ? ORA_KTIME_BOOT : ORA_KTIME,
		      0U);
	if (boot) {
		mreg[0] = ORA_KTIME_BOOT;
		mtag[0] = 0U;
	} else {
		mreg[0] = ORA_KTIME;
		mtag[0] = 0U;
	}

	capture_reset();
	if (boot)
		ARM64_SIM_BPF_CALL_bpf_ktime_get_boot_ns();
	else
		ARM64_SIM_BPF_CALL_bpf_ktime_get_ns();

	if (last_n != 0U || ora_called != (boot ? 125U : 5U)) {
		printf("MISMATCH %s captured %u lanes, want 0\n", via,
		       last_n);
		failures++;
		return;
	}
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- probe family (X0 ARG, X1 scalar, X2 raw) + str variants --- */
static void scene_probe(const char *via, unsigned which)
{
	__u64 v[3];
	static const unsigned ids[] = {113, 4, 112, 148, 45, 114, 115};

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_STACK_TAGGED(ARM64_X0, x0, 16);
	PLANT_VAL(ARM64_X1, x1, 28);
	PLANT_RAW(ARM64_X2, x2, 0x5858585858585858ULL);
	v[0] = ARG_LANE_VALUE(16);
	v[1] = 28;
	v[2] = mreg[2];
	expect_commit(ORA_PROBE, 0U);
    model_helper_effect(ids[which], (__u64)(long)ORA_PROBE);

	capture_reset();
	switch (which) {
	case 0:
		ARM64_SIM_BPF_CALL_bpf_probe_read_kernel();
		break;
	case 1:
		ARM64_SIM_BPF_CALL_bpf_probe_read();
		break;
	case 2:
		ARM64_SIM_BPF_CALL_bpf_probe_read_user();
		break;
	case 3:
		ARM64_SIM_BPF_CALL_bpf_copy_from_user();
		break;
	case 4:
		ARM64_SIM_BPF_CALL_bpf_probe_read_str();
		break;
	case 5:
		ARM64_SIM_BPF_CALL_bpf_probe_read_user_str();
		break;
	default:
		ARM64_SIM_BPF_CALL_bpf_probe_read_kernel_str();
		break;
	}

	mreg[0] = (__u64)(long)ORA_PROBE;
	mtag[0] = 0U;

	compare_capture(via, v, 3, ids[which]);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- Copy-from-task forwards all five arguments to its own callee. --- */
static void scene_cfu_task(void)
{
	__u64 v[5];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_STACK_TAGGED(ARM64_X0, x0, 16);
	PLANT_VAL(ARM64_X1, x1, 28);
	PLANT_RAW(ARM64_X2, x2, 0x5858585858585858ULL);
	v[0] = ARG_LANE_VALUE(16);
	v[1] = 28;
	v[2] = mreg[2];
	PLANT_RAW(ARM64_X3, x3, 0x5959595959595959ULL);
	PLANT_VAL(ARM64_X4, x4, 9);
	v[3] = mreg[3]; v[4] = 9;
	expect_commit(ORA_PROBE, 0U);
	mreg[0] = (__u64)(long)ORA_PROBE;
	mtag[0] = 0U;

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_copy_from_user_task();

	compare_capture("copy_from_user_task", v, 5, 191);
	COMPARE_X0("copy_from_user_task");
	COMPARE_REG_STATE("copy_from_user_task");
}

/* --- perf event (X0 raw, X1 raw, X2 scalar, X3 stack ARG, X4 scalar) --- */
static void scene_perf(void)
{
	__u64 v[5];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x0000e00000000001ULL);
	PLANT_RAW(ARM64_X1, x1, 0x5a5a5a5a5a5a5a5aULL);
	PLANT_VAL(ARM64_X2, x2, 3);
	PLANT_STACK_TAGGED(ARM64_X3, x3, 12);
	PLANT_VAL(ARM64_X4, x4, 31);
	v[0] = mreg[0];
	v[1] = mreg[1];
	v[2] = 3;
	v[3] = ARG_LANE_VALUE(12);
	v[4] = 31;
	expect_commit(ORA_PERF, 0U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_perf_event_output();

	mreg[0] = (__u64)(long)ORA_PERF;
	mtag[0] = 0U;

	compare_capture("perf_event", v, 5, 25);
	COMPARE_X0("perf_event");
	COMPARE_REG_STATE("perf_event");
}

/* --- skb store bytes (X0 raw skb, X1 scalar, X2 stack ARG, X3 scalar,
 * X4 scalar) --- */
static void scene_skb_store(void)
{
	__u64 v[5];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x00005d000000cb00ULL);
	PLANT_VAL(ARM64_X1, x1, 9);
	PLANT_STACK_TAGGED(ARM64_X2, x2, 12);
	PLANT_VAL(ARM64_X3, x3, 17);
	PLANT_VAL(ARM64_X4, x4, 0);
	v[0] = mreg[0];
	v[1] = 9;
	v[2] = ARG_LANE_VALUE(12);
	v[3] = 17;
	v[4] = 0;
	expect_commit(ORA_SKB, 0U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_skb_store_bytes();

	mreg[0] = (__u64)(long)ORA_SKB;
	mtag[0] = 0U;

	compare_capture("skb_store", v, 5, 9);
	COMPARE_X0("skb_store");
	COMPARE_REG_STATE("skb_store");
}

/* --- l3/l4 csum replace (5 register lanes, no stack ARG) --- */
static void scene_csum(const char *via, unsigned which)
{
	__u64 v[5];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x00005d000000cb01ULL);
	PLANT_VAL(ARM64_X1, x1, 9);
	PLANT_VAL(ARM64_X2, x2, 20);
	PLANT_VAL(ARM64_X3, x3, 30);
	PLANT_VAL(ARM64_X4, x4, 40);
	v[0] = mreg[0];
	v[1] = 9;
	v[2] = 20;
	v[3] = 30;
	v[4] = 40;
	expect_commit(ORA_CSUM + which, 0U);

	capture_reset();
	if (which == 0)
		ARM64_SIM_BPF_CALL_bpf_l3_csum_replace();
	else
		ARM64_SIM_BPF_CALL_bpf_l4_csum_replace();

	mreg[0] = (__u64)(long)(ORA_CSUM + which);
	mtag[0] = 0U;

	compare_capture(via, v, 5, 10 + which);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- skb load bytes (X0 raw, X1/X3 scalar, X2 stack ARG);
 * relative adds an X4 scalar lane --- */
static void scene_skb_load(const char *via, unsigned relative)
{
	__u64 v[5];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x00005d000000cb02ULL);
	PLANT_VAL(ARM64_X1, x1, 20);
	PLANT_STACK_TAGGED(ARM64_X2, x2, 12);
	PLANT_VAL(ARM64_X3, x3, 33);
	PLANT_VAL(ARM64_X4, x4, 2);
	v[0] = mreg[0];
	v[1] = 20;
	v[2] = ARG_LANE_VALUE(12);
	v[3] = 33;
	v[4] = 2;
	expect_commit(ORA_SKB + relative + 1, 0U);
    model_helper_effect(relative ? 68 : 26, (__u64)(long)(ORA_SKB + relative + 1));

	capture_reset();
	if (relative)
		ARM64_SIM_BPF_CALL_bpf_skb_load_bytes_relative();
	else
		ARM64_SIM_BPF_CALL_bpf_skb_load_bytes();

	mreg[0] = (__u64)(long)(ORA_SKB + relative + 1);
	mtag[0] = 0U;

	compare_capture(via, v, relative ? 5 : 4, relative ? 68 : 26);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- Fullsock returns a tagged helper pointer distinct from its input. --- */
static void scene_fullsock(void)
{
	__u64 v[1];
	static struct bpf_sock sockobj;

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, (__u64)(long)&sockobj);
	v[0] = mreg[0];
	expect_commit(ora_expected_result(95), 6U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_sk_fullsock();

	mreg[0] = ora_expected_result(95);
	mtag[0] = 6U;

	compare_capture("sk_fullsock", v, 1, 95);
	COMPARE_X0("sk_fullsock");
	COMPARE_REG_STATE("sk_fullsock");
}

/* --- All30 original wide-result scenes now check typed calls and framing. --- */
static void scene_wide(const char *via, unsigned which)
{
	static const unsigned ids[] = {14, 16, 183, 184, 185, 186, 174, 161, 127, 6, 23, 13, 21, 28, 33, 31, 32, 38, 39, 43, 44, 65, 46, 50, 69, 152, 122, 37, 27, 67};
	unsigned identity = ids[which];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	PREPARE_TYPED_HELPER(identity);
	switch (which) {
	case 0: ARM64_SIM_BPF_CALL_bpf_get_current_pid_tgid(); break;
	case 1: ARM64_SIM_BPF_CALL_bpf_get_current_comm(); break;
	case 2: ARM64_SIM_BPF_CALL_bpf_get_func_arg(); break;
	case 3: ARM64_SIM_BPF_CALL_bpf_get_func_ret(); break;
	case 4: ARM64_SIM_BPF_CALL_bpf_get_func_arg_cnt(); break;
	case 5: ARM64_SIM_BPF_CALL_bpf_get_retval(); break;
	case 6: ARM64_SIM_BPF_CALL_bpf_get_attach_cookie(); break;
	case 7: ARM64_SIM_BPF_CALL_bpf_ima_inode_hash(); break;
	case 8: ARM64_SIM_BPF_CALL_bpf_seq_write(); break;
	case 9: ARM64_SIM_BPF_CALL_bpf_trace_printk(); break;
	case 10: ARM64_SIM_BPF_CALL_bpf_redirect(); break;
	case 11: ARM64_SIM_BPF_CALL_bpf_clone_redirect(); break;
	case 12: ARM64_SIM_BPF_CALL_bpf_skb_set_tunnel_key(); break;
	case 13: ARM64_SIM_BPF_CALL_bpf_csum_diff(); break;
	case 14: ARM64_SIM_BPF_CALL_bpf_skb_under_cgroup(); break;
	case 15: ARM64_SIM_BPF_CALL_bpf_skb_change_proto(); break;
	case 16: ARM64_SIM_BPF_CALL_bpf_skb_change_type(); break;
	case 17: ARM64_SIM_BPF_CALL_bpf_skb_change_tail(); break;
	case 18: ARM64_SIM_BPF_CALL_bpf_skb_pull_data(); break;
	case 19: ARM64_SIM_BPF_CALL_bpf_skb_change_head(); break;
	case 20: ARM64_SIM_BPF_CALL_bpf_xdp_adjust_head(); break;
	case 21: ARM64_SIM_BPF_CALL_bpf_xdp_adjust_tail(); break;
	case 22: ARM64_SIM_BPF_CALL_bpf_get_socket_cookie(); break;
	case 23: ARM64_SIM_BPF_CALL_bpf_skb_adjust_room(); break;
	case 24: ARM64_SIM_BPF_CALL_bpf_fib_lookup(); break;
	case 25: ARM64_SIM_BPF_CALL_bpf_redirect_neigh(); break;
	case 26: ARM64_SIM_BPF_CALL_bpf_get_netns_cookie(); break;
	case 27: ARM64_SIM_BPF_CALL_bpf_current_task_under_cgroup(); break;
	case 28: ARM64_SIM_BPF_CALL_bpf_get_stackid(); break;
	case 29: ARM64_SIM_BPF_CALL_bpf_get_stack(); break;
	default:
		break;
	}

	CHECK_TYPED_HELPER(via, identity);
}

static void scene_prand(void)
{
	unsigned identity = 7U;

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	PREPARE_TYPED_HELPER(identity);
	ARM64_SIM_BPF_CALL_bpf_get_prandom_u32();

	CHECK_TYPED_HELPER("get_prandom_u32", identity);
}

static void scene_task_file(const char *via, unsigned which)
{
	static const unsigned ids[] = {158, 175, 193};
	unsigned identity = ids[which];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0x5600000000000000ULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0x5600000000000000ULL;
	mtag[0] = 6U;

	PREPARE_TYPED_HELPER(identity);
	switch (which) {
	case 0: ARM64_SIM_BPF_CALL_bpf_get_current_task_btf(); break;
	case 1: ARM64_SIM_BPF_CALL_bpf_task_pt_regs(); break;
	case 2: ARM64_SIM_BPF_CALL_bpf_ima_file_hash(); break;
	default:
		break;
	}

	CHECK_TYPED_HELPER(via, identity);
}

/* Exercise all newly effectful routes with bounded real stack destinations.
 * The probe success/failure pair detects incorrect result-dependent tag copies;
 * misaligned source/destination and zero length cover whole-word boundaries. */
static void scene_writer(unsigned id, __s64 destination, __s64 source, unsigned length, int success)
{
    DECL_STATE();
    PLANT_STATE();
    INIT_ARENA();
    if (writer_destination(id) == 0) {
        PLANT_STACK_TAGGED(ARM64_X0, x0, destination);
        PLANT_VAL(ARM64_X1, x1, length);
        PLANT_STACK_TAGGED(ARM64_X2, x2, source);
    } else if (writer_destination(id) == 2) {
        PLANT_RAW(ARM64_X0, x0, 0x12345678);
        PLANT_STACK_TAGGED(ARM64_X2, x2, destination);
        PLANT_VAL(ARM64_X3, x3, length);
    } else {
        PLANT_RAW(ARM64_X0, x0, 0x12345678);
        PLANT_STACK_TAGGED(ARM64_X1, x1, destination);
        PLANT_VAL(ARM64_X2, x2, length);
    }
    probe_succeeds = success;
    PREPARE_TYPED_HELPER_AT(id, 0);
    switch (id) {
    case 4: ARM64_SIM_BPF_CALL_bpf_probe_read(); break;
    case 16: ARM64_SIM_BPF_CALL_bpf_get_current_comm(); break;
    case 45: ARM64_SIM_BPF_CALL_bpf_probe_read_str(); break;
    case 26: ARM64_SIM_BPF_CALL_bpf_skb_load_bytes(); break;
    case 67: ARM64_SIM_BPF_CALL_bpf_get_stack(); break;
    case 68: ARM64_SIM_BPF_CALL_bpf_skb_load_bytes_relative(); break;
    case 112: ARM64_SIM_BPF_CALL_bpf_probe_read_user(); break;
    case 113: ARM64_SIM_BPF_CALL_bpf_probe_read_kernel(); break;
    case 114: ARM64_SIM_BPF_CALL_bpf_probe_read_user_str(); break;
    case 115: ARM64_SIM_BPF_CALL_bpf_probe_read_kernel_str(); break;
    case 148: ARM64_SIM_BPF_CALL_bpf_copy_from_user(); break;
    }
    probe_succeeds = 0;
    CHECK_TYPED_HELPER("stack writer", id);
}

int main(void)
{

	/* --- map family --- */
	scene_lookup("map_lookup", 0U);
	scene_lookup("map_lookup_percpu_alias", 1U);
	scene_update();
	scene_delete();

	/* --- Original four identity/tail-call scenes. --- */
	scene_identity("zero_tail_call", 0U);
	scene_identity("zero_uid_gid", 1U);
	scene_identity("zero_smp_processor_id", 2U);
	scene_identity("zero_cgroup_id", 3U);

	scene_jiffies();

	/* --- Task identity, with pointer-returning helpers checked below. --- */
	scene_task("get_current_task");

	/* --- ktime natives --- */
	scene_ktime("ktime_get_ns", 0U);
	scene_ktime("ktime_get_boot_ns", 1U);

	/* --- probe family (which 0..6) --- */
	scene_probe("probe_read_kernel", 0U);
	scene_probe("probe_read", 1U);
	scene_probe("probe_read_user", 2U);
	scene_probe("copy_from_user", 3U);
	scene_probe("probe_read_str", 4U);
	scene_probe("probe_read_user_str", 5U);
	scene_probe("probe_read_kernel_str", 6U);

	scene_cfu_task();

	/* --- 5-lane event/skb family --- */
	scene_perf();
	scene_skb_store();
	scene_csum("l3_csum_replace", 0U);
	scene_csum("l4_csum_replace", 1U);

	/* --- skb load family --- */
	scene_skb_load("skb_load_bytes", 0U);
	scene_skb_load("skb_load_bytes_relative", 1U);

	/* --- socket pointer-return shape --- */
	scene_fullsock();
	/* --- Original30 wide-result helper scenes. --- */
	scene_wide("z64_get_current_pid_tgid", 0U);
	scene_wide("z64_get_current_comm", 1U);
	scene_wide("z64_get_func_arg", 2U);
	scene_wide("z64_get_func_ret", 3U);
	scene_wide("z64_get_func_arg_cnt", 4U);
	scene_wide("z64_get_retval", 5U);
	scene_wide("z64_get_attach_cookie", 6U);
	scene_wide("z64_ima_inode_hash", 7U);
	scene_wide("z64_seq_write", 8U);
	scene_wide("z64_trace_printk", 9U);
	scene_wide("z64_redirect", 10U);
	scene_wide("z64_clone_redirect", 11U);
	scene_wide("z64_skb_set_tunnel_key", 12U);
	scene_wide("z64_csum_diff", 13U);
	scene_wide("z64_skb_under_cgroup", 14U);
	scene_wide("z64_skb_change_proto", 15U);
	scene_wide("z64_skb_change_type", 16U);
	scene_wide("z64_skb_change_tail", 17U);
	scene_wide("z64_skb_pull_data", 18U);
	scene_wide("z64_skb_change_head", 19U);
	scene_wide("z64_xdp_adjust_head", 20U);
	scene_wide("z64_xdp_adjust_tail", 21U);
	scene_wide("z64_get_socket_cookie", 22U);
	scene_wide("z64_skb_adjust_room", 23U);
	scene_wide("z64_fib_lookup", 24U);
	scene_wide("z64_redirect_neigh", 25U);
	scene_wide("z64_get_netns_cookie", 26U);
	scene_wide("z64_current_task_under_cgroup", 27U);
	scene_wide("z64_get_stackid", 28U);
	scene_wide("z64_get_stack", 29U);

	/* --- Random-u32 result narrowing. --- */
	scene_prand();

	/* --- Three distinct typed task/file helpers. --- */
	scene_task_file("alias_get_current_task_btf", 0U);
	scene_task_file("alias_task_pt_regs", 1U);
	scene_task_file("alias_ima_file_hash", 2U);

    {
        static const unsigned ids[] = {4,16,26,45,67,68,112,113,114,115,148};
        unsigned j;
        for (j = 0; j < sizeof(ids)/sizeof(ids[0]); j++) scene_writer(ids[j], 8, 32, 8, 0);
        scene_writer(113, 8, 32, 8, 1);
        scene_writer(113, 12, 32, 8, 1);
        scene_writer(113, 8, 36, 8, 1);
        scene_writer(113, 8, 32, 0, 1);
    }
	if (failures != 0) {
		printf("arm64 helper route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 helper route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}

#pragma GCC diagnostic pop
