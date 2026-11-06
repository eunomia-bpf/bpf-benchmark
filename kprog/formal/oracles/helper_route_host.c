/*
 * Route host cross-check for the AArch64 simulator's BPF helper-call body
 * family `ARM64_SIM_BPF_CALL_*` in `../arm64/arm64_sim_local_bpf.h`
 * (STEP 0454, mutation battery 0454).
 *
 * Every helper body is a `do{..}while(0)` sequence of argument reads
 * (`ARM64_SIM_L_READ_REG_PTR` raw, `ARM64_SIM_L_HELPER_ARG_PTR` with the
 * stack-arena redirect, `ARM64_SIM_L_READ_REG` scalar) and one X0 commit
 * (`ARM64_SIM_L_WRITE_REG_WIDTH` 64/32-bit, or `ARM64_SIM_L_WRITE_REG_PTR_TAG`
 * with a provenance tag). The 61 macros span: the map lookup/update/delete
 * shapes (update carries a 4th scalar lane), 42 static-zero shapes (40 wide
 * + 2 narrow 32-bit) sharing the boilerplate `WRITE_REG_WIDTH(X0, 0, W)`,
 * the task pointer-tag shape (+2 aliases), the two native ktime shapes, the
 * 3-lane probe-read chain (+4 str variants + user/copy aliases), the 5-lane
 * perf/skb-store/csum shapes, the 4- and 5-lane skb-load shapes, and the
 * sk_fullsock pointer-return shape.
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
 * Stack-arena convention (both sides agree by construction): every
 * stack-tagged argument is planted at offset 12, so its redirected pointer
 * reads `&__a64_stack.b[ARM64_SIM_STACK_BIAS + 12]` — one deterministic
 * byte (`arena_val()`), never dependant on planted contents beyond that.
 * Raw-pointer lanes pass the register value through unchanged. A body that
 * reads the wrong lane gets a peripheral byte (or reg pattern) and fails
 * the compare.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -Werror -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      build/helper_route_host.c -o build/mut_helperroute &&
 *   ./build/mut_helperroute
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
#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* Per-scene capture scratch so rows never read stale lanes. Value-only:
 * a pointer lane lands the pointer bit pattern the stub actually
 * received (raw register value, or the arena byte address after the
 * redirect), a value lane lands the register bit pattern. */
static __u64 last_val[6];
static unsigned last_n;

static void capture_reset(void)
{
	unsigned i;

	for (i = 0; i < 6; i++) {
		last_val[i] = 0xabcdefabcdefabcdULL;
	}
	last_n = 0;
}

/* Capturing native stubs. The macro builders stamp one lane per parameter
 * into `last_val`, in declaration order; the per-body capture row then
 * names exactly those lanes' expected values. All fixed returns are
 * numerically distinct so a misnamed native shows in both the X0 compare
 * and the capture row. */
#define NATIVE0V(NAME, RET, RV)                                            \
	static RET NAME(void)                                              \
	{                                                                  \
		last_n = 0;                                                \
		return (RET)(ORA_##RV);                                    \
	}
#define NATIVE1V(NAME, RET, T0, RV)                                        \
	static RET NAME(T0 a0)                                             \
	{                                                                  \
		last_val[0] = (__u64)(unsigned long)a0;                    \
		last_n = 1;                                                \
		return (RET)(long)(ORA_##RV);                              \
	}
#define NATIVE2V(NAME, RET, T0, T1, RV)                                    \
	static RET NAME(T0 a0, T1 a1)                                      \
	{                                                                  \
		last_val[0] = (__u64)(unsigned long)a0;                    \
		last_val[1] = (__u64)(unsigned long)a1;                    \
		last_n = 2;                                                \
		return (RET)(long)(ORA_##RV);                              \
	}
#define NATIVE3V(NAME, RET, T0, T1, T2, RV)                                \
	static RET NAME(T0 a0, T1 a1, T2 a2)                               \
	{                                                                  \
		last_val[0] = (__u64)(unsigned long)a0;                    \
		last_val[1] = (__u64)(unsigned long)a1;                    \
		last_val[2] = (__u64)(unsigned long)a2;                    \
		last_n = 3;                                                \
		return (RET)(long)(ORA_##RV);                              \
	}
#define NATIVE4V(NAME, RET, T0, T1, T2, T3, RV)                            \
	static RET NAME(T0 a0, T1 a1, T2 a2, T3 a3)                        \
	{                                                                  \
		last_val[0] = (__u64)(unsigned long)a0;                    \
		last_val[1] = (__u64)(unsigned long)a1;                    \
		last_val[2] = (__u64)(unsigned long)a2;                    \
		last_val[3] = (__u64)(unsigned long)a3;                    \
		last_n = 4;                                                \
		return (RET)(long)(ORA_##RV);                              \
	}
#define NATIVE5V(NAME, RET, T0, T1, T2, T3, T4, RV)                        \
	static RET NAME(T0 a0, T1 a1, T2 a2, T3 a3, T4 a4)                 \
	{                                                                  \
		last_val[0] = (__u64)(unsigned long)a0;                    \
		last_val[1] = (__u64)(unsigned long)a1;                    \
		last_val[2] = (__u64)(unsigned long)a2;                    \
		last_val[3] = (__u64)(unsigned long)a3;                    \
		last_val[4] = (__u64)(unsigned long)a4;                    \
		last_n = 5;                                                \
		return (RET)(long)(ORA_##RV);                              \
	}

#define ORA_MAP_PTR 0x0000123400005678ULL
#define ORA_UPD_RET (-7LL)
#define ORA_DEL_RET 3LL
#define ORA_KTIME 0xaabbccddeeff0011ULL
#define ORA_KTIME_BOOT 0x1122334455667788ULL
#define ORA_PROBE (-9LL)
#define ORA_PERF 5LL
#define ORA_SKB (-3LL)
#define ORA_CSUM 11LL

NATIVE2V(bpf_map_lookup_elem, void *, void *, const void *, MAP_PTR)
NATIVE4V(bpf_map_update_elem, long, void *, const void *, const void *,
	 __u64, UPD_RET)
NATIVE2V(bpf_map_delete_elem, long, void *, const void *, DEL_RET)
NATIVE0V(bpf_ktime_get_ns, __u64, KTIME)
NATIVE0V(bpf_ktime_get_boot_ns, __u64, KTIME_BOOT)
NATIVE3V(bpf_probe_read_kernel, long, void *, __u32, const void *, PROBE)
NATIVE3V(bpf_probe_read, long, void *, __u32, const void *, PROBE)
NATIVE3V(bpf_probe_read_user, long, void *, __u32, const void *, PROBE)
NATIVE3V(bpf_probe_read_str, long, void *, __u32, const void *, PROBE)
NATIVE3V(bpf_probe_read_user_str, long, void *, __u32, const void *, PROBE)
NATIVE3V(bpf_probe_read_kernel_str, long, void *, __u32, const void *,
	 PROBE)
NATIVE5V(bpf_perf_event_output, long, void *, void *, __u64, void *, __u64,
	 PERF)
NATIVE5V(bpf_skb_store_bytes, long, struct __sk_buff *, __u32, const void *,
	 __u32, __u64, SKB)
NATIVE5V(bpf_l3_csum_replace, long, struct __sk_buff *, __u32, __u64, __u64,
	 __u64, CSUM + 0)
NATIVE5V(bpf_l4_csum_replace, long, struct __sk_buff *, __u32, __u64, __u64,
	 __u64, CSUM + 1)
NATIVE4V(bpf_skb_load_bytes, long, const struct __sk_buff *, __u32, void *,
	 __u32, SKB + 1)
NATIVE5V(bpf_skb_load_bytes_relative, long, const struct __sk_buff *, __u32,
	 void *, __u32, __u32, SKB + 2)
static struct bpf_sock *bpf_sk_fullsock(struct bpf_sock *sk)
{
	last_val[0] = (__u64)(unsigned long)sk;
	last_n = 1;
	return sk;
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
	(void)__a64_stack.b[0];                                            \
	(void)__a64_stack_tag[0];                                          \
	(void)__a64_sp;                                                    \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR);                               \
	(void)__a64_lr;                                                    \
	(void)__a64_v0;                                                    \
	(void)__a64_v0_hi;

#define INIT_ARENA()                                                       \
	do {                                                               \
		unsigned __ai_i;                                           \
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
			switch (__cs_i) {                                  \
			ARM64_SIM_L_FOR_EACH_GPR(COMPARE_GOT)               \
			default: break;                                    \
			}                                                  \
			cases++;                                           \
			if (__cs_got != mreg[__cs_i]) {                    \
				printf("MISMATCH %s reg%u: got 0x%llx "     \
				       "want 0x%llx\n", (VIA),             \
				       (unsigned)__cs_i,                   \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)mreg[__cs_i]);  \
				failures++;                                \
				return;                                    \
			}                                                  \
			cases++;                                           \
			if (__cs_tag != mtag[__cs_i]) {                    \
				printf("MISMATCH %s reg%u tag: got %u "     \
				       "want %u\n", (VIA),                 \
				       (unsigned)__cs_i, __cs_tag,         \
				       mtag[__cs_i]);                      \
				failures++;                                \
				return;                                    \
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
static void compare_capture(const char *via, const __u64 *v, unsigned n)
{
	unsigned i;

	cases++;
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

/* --- map lookup (X0 raw REG, X1 stack ARG) : PTR_TAG MAP_VALUE --- */
static void scene_lookup(const char *via, unsigned percpu)
{
	__u64 v[2];

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, 0x5151515151515151ULL);
	PLANT_STACK_TAGGED(ARM64_X1, x1, 12);
	v[0] = mreg[0];
	v[1] = ARG_LANE_VALUE(12);
	expect_commit(ORA_MAP_PTR, 6U);

	capture_reset();
	if (percpu)
		ARM64_SIM_BPF_CALL_bpf_map_lookup_percpu_elem();
	else
		ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();

	mreg[0] = ORA_MAP_PTR;
	mtag[0] = 6U;

	compare_capture(via, v, 2);
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

	compare_capture("map_update", v, 4);
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

	compare_capture("map_delete", v, 2);
	COMPARE_X0("map_delete");
	COMPARE_REG_STATE("map_delete");
}

/* --- the static-zero wide shape, driven over 4 distinct body names so a
 * per-name repaint on any of them is caught; no lanes read, no capture. */
static void scene_zero(const char *via, unsigned which)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	/* Seed X0 with a nonzero non-scalar-tag value so the zero-commit and
	 * its tag repaint are both observable. */
	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	/* Both zero shapes mask any seed to zero under KPROG_ARM64_APPLY_WIDTH
	 * and repaint the X0 tag SCALAR: X0 0, SCALAR. */
	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
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

	if (last_n != 0U) {
		printf("MISMATCH %s captured %u lanes, want 0\n", via,
		       last_n);
		failures++;
		return;
	}
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- jiffies64: wide zero shape with a distinct native name, so a
 * per-name repaint inside the jiffies body is observable. */
static void scene_jiffies(void)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_jiffies64();

	if (last_n != 0U) {
		printf("MISMATCH jiffies captured %u lanes, want 0\n", last_n);
		failures++;
		return;
	}
	COMPARE_X0("jiffies64");
	COMPARE_REG_STATE("jiffies64");
}

/* --- task pointer-tag shape (X0 => 0 SCALAR) + its aliases --- */
static void scene_task(const char *via)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0x5600000000000000ULL;
	__a64_x0_tag = 6U;
	mtag[0] = 6U;

	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_get_current_task();

	if (last_n != 0U) {
		printf("MISMATCH %s captured %u lanes, want 0\n", via,
		       last_n);
		failures++;
		return;
	}
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
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

	if (last_n != 0U) {
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

	compare_capture(via, v, 3);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- copy_from_user_task: the alias body forwards to the
 * copy_from_user body (native bpf_probe_read_user); driving the alias
 * name pins the forward arrow, not just the underlying shape. */
static void scene_cfu_task(void)
{
	__u64 v[3];

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
	mreg[0] = (__u64)(long)ORA_PROBE;
	mtag[0] = 0U;

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_copy_from_user_task();

	compare_capture("copy_from_user_task", v, 3);
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

	compare_capture("perf_event", v, 5);
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

	compare_capture("skb_store", v, 5);
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

	compare_capture(via, v, 5);
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

	capture_reset();
	if (relative)
		ARM64_SIM_BPF_CALL_bpf_skb_load_bytes_relative();
	else
		ARM64_SIM_BPF_CALL_bpf_skb_load_bytes();

	mreg[0] = (__u64)(long)(ORA_SKB + relative + 1);
	mtag[0] = 0U;

	compare_capture(via, v, relative ? 5 : 4);
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

/* --- sk fullsock (X0 raw sock REG -> PTR_TAG SCALAR, same pointer) --- */
static void scene_fullsock(void)
{
	__u64 v[1];
	static struct bpf_sock sockobj;

	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	PLANT_RAW(ARM64_X0, x0, (__u64)(long)&sockobj);
	v[0] = mreg[0];
	expect_commit(mreg[0], 0U);

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_sk_fullsock();

	mreg[0] = (__u64)(long)&sockobj;
	mtag[0] = 0U;

	compare_capture("sk_fullsock", v, 1);
	COMPARE_X0("sk_fullsock");
	COMPARE_REG_STATE("sk_fullsock");
}

/* --- 0462: the static-zero 64-bit family (30 undriven helper names,
 * all body text ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, 0, ARM64_WIDTH_64))
 * drives the same zero-write shape per name; a per-name body repaint
 * must move the X0 commit away from 0 or flip the width tag. --- */
static void scene_zero64(const char *via, unsigned which)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
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

	if (last_n != 0U) {
		printf("MISMATCH %s captured %u lanes, want 0\n", via,
		       last_n);
		failures++;
		return;
	}
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

static void scene_prand(void)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0xfeedfacefeedfaceULL;
	__a64_x0_tag = 6U;
	mreg[0] = 0xfeedfacefeedfaceULL;
	mtag[0] = 6U;

	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
	ARM64_SIM_BPF_CALL_bpf_get_prandom_u32();

	if (last_n != 0U) {
		printf("MISMATCH prand captured %u lanes, want 0\n", last_n);
		failures++;
		return;
	}
	COMPARE_X0("get_prandom_u32");
	COMPARE_REG_STATE("get_prandom_u32");
}

static void scene_alias(const char *via, unsigned which)
{
	DECL_STATE();
	PLANT_STATE();
	INIT_ARENA();

	__a64_x0.ptr = (void *)0x5600000000000000ULL;
	__a64_x0_tag = 6U;
	mtag[0] = 6U;

	expect_commit(0, 0U);
	mreg[0] = 0;
	mtag[0] = 0U;

	capture_reset();
	switch (which) {
	case 0: ARM64_SIM_BPF_CALL_bpf_get_current_task_btf(); break;
	case 1: ARM64_SIM_BPF_CALL_bpf_task_pt_regs(); break;
	case 2: ARM64_SIM_BPF_CALL_bpf_ima_file_hash(); break;
	default:
		break;
	}

	if (last_n != 0U) {
		printf("MISMATCH %s captured %u lanes, want 0\n", via,
		       last_n);
		failures++;
		return;
	}
	COMPARE_X0(via);
	COMPARE_REG_STATE(via);
}

int main(void)
{
	unsigned i;

	/* The stack-arena image: deterministic per byte, so every ARG lane
	 * resolves a different byte off its offset and a wrong lane index
	 * cannot alias the right one. */
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xc0U + i * 7U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(1U + (i % 5U));

	/* --- map family --- */
	scene_lookup("map_lookup", 0U);
	scene_lookup("map_lookup_percpu_alias", 1U);
	scene_update();
	scene_delete();

	/* --- the static-zero shapes: four distinct body names for per-name
	 * repaint coverage (the 42-name family shares 2 body texts) --- */
	scene_zero("zero_tail_call", 0U);
	scene_zero("zero_uid_gid", 1U);
	scene_zero("zero_smp_processor_id", 2U);
	scene_zero("zero_cgroup_id", 3U);

	scene_jiffies();

	/* --- task pointer-tag shape (aliases share the body text of
	 * get_current_task, so one drive + the alias rows below) --- */
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
	/* --- 0462: the undriven static-zero 64-bit family (30 names) --- */
	scene_zero64("z64_get_current_pid_tgid", 0U);
	scene_zero64("z64_get_current_comm", 1U);
	scene_zero64("z64_get_func_arg", 2U);
	scene_zero64("z64_get_func_ret", 3U);
	scene_zero64("z64_get_func_arg_cnt", 4U);
	scene_zero64("z64_get_retval", 5U);
	scene_zero64("z64_get_attach_cookie", 6U);
	scene_zero64("z64_ima_inode_hash", 7U);
	scene_zero64("z64_seq_write", 8U);
	scene_zero64("z64_trace_printk", 9U);
	scene_zero64("z64_redirect", 10U);
	scene_zero64("z64_clone_redirect", 11U);
	scene_zero64("z64_skb_set_tunnel_key", 12U);
	scene_zero64("z64_csum_diff", 13U);
	scene_zero64("z64_skb_under_cgroup", 14U);
	scene_zero64("z64_skb_change_proto", 15U);
	scene_zero64("z64_skb_change_type", 16U);
	scene_zero64("z64_skb_change_tail", 17U);
	scene_zero64("z64_skb_pull_data", 18U);
	scene_zero64("z64_skb_change_head", 19U);
	scene_zero64("z64_xdp_adjust_head", 20U);
	scene_zero64("z64_xdp_adjust_tail", 21U);
	scene_zero64("z64_get_socket_cookie", 22U);
	scene_zero64("z64_skb_adjust_room", 23U);
	scene_zero64("z64_fib_lookup", 24U);
	scene_zero64("z64_redirect_neigh", 25U);
	scene_zero64("z64_get_netns_cookie", 26U);
	scene_zero64("z64_current_task_under_cgroup", 27U);
	scene_zero64("z64_get_stackid", 28U);
	scene_zero64("z64_get_stack", 29U);

	/* --- 0462: the single 32-bit zero body --- */
	scene_prand();

	/* --- 0462: the three one-line alias bodies --- */
	scene_alias("alias_get_current_task_btf", 0U);
	scene_alias("alias_task_pt_regs", 1U);
	scene_alias("alias_ima_file_hash", 2U);

	if (failures != 0) {
		printf("arm64 helper route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 helper route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}

#pragma GCC diagnostic pop
