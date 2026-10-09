/*
 * Host cross-check for the x86-64 simulator's routing of a decoded helper id
 * through the generated helper-dispatch contract (STEP 0113).
 *
 * The runtime body `X86_SIM_BPF_CALL_ID` dispatches a 64-bit helper id through
 * the hand-written `if/else-if` ladder; `X86_SIM_BPF_CALL_REG` reads the id out
 * of a register and calls it, and the chain's `X86_OP_CALL_REG` arm is exactly
 * `X86_SIM_BPF_CALL_REG((SRC))`. This oracle drives the real simulator state
 * over the whole named id space (the armed ids `1 .. 7`, the zero id, and the
 * named-but-unarmed ids `8 .. 21`) and compares the *whole* changed register
 * state against an independent hand-written id -> body model. A helper that
 * was inserted, dropped, or swapped on either side shows up as a differing
 * register value or tag. The generated header's `_Static_assert`s additionally
 * pin the hand-written id defines to the generated table at compile time.
 *
 * The four helpers that call into the host (`map_lookup_elem` (1),
 * `map_update_elem` (2), `map_delete_elem` (3), `ktime_get_ns` (7)) are served
 * by callable stubs defined here with fixed returns, so the oracle can predict
 * the register value the ladder leaves. `bpf_helpers.h` is skipped
 * (`__BPF_HELPERS__`) so its fake function-pointer consts are not used, and the
 * ids `4/5/6` write a constant without calling the host. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_helper_dispatch_route_host.c -o /tmp/t_xhdr
 *   /tmp/t_xhdr
 */

#define __BPF_HELPERS__ 1
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

/* The host-calling helpers, stubbed with fixed returns. The update and delete
 * returns also give two distinct result values so a call that aliases its
 * planted seed is still caught. */
#define ORA_MAP_PTR ((void *)0x0000123400005678ULL)
#define ORA_UPD_RET ((long)-7LL)
#define ORA_DEL_RET ((long)3LL)
#define ORA_KTIME 0xaabbccddeeff0011ULL

static void *bpf_map_lookup_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	return ORA_MAP_PTR;
}

static long bpf_map_update_elem(void *map, const void *key,
				const void *value, __u64 flags)
{
	(void)map;
	(void)key;
	(void)value;
	(void)flags;
	return ORA_UPD_RET;
}

static long bpf_map_delete_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	return ORA_DEL_RET;
}

static __u64 bpf_ktime_get_ns(void)
{
	return ORA_KTIME;
}

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* A deterministic per-register pattern, with high bits set so a 64-bit write
 * and a narrow write are distinguishable, and never zero. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag planted in every cell before a call, so the RAX tag change
 * is observable even when a write leaves the pointer bytes unchanged. */
#define ORA_MARK_TAG 0x7fU

static const char *gpr_names[16] = {
	"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
	"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
};

#define ORA_CAPTURE(REG, NAME)                                             \
	do {                                                               \
		__p[__i] = __x86_##NAME.ptr;                               \
		__t[__i] = __x86_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define ORA_SNAPSHOT(P, T)                                                 \
	do {                                                               \
		void **__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_CAPTURE)                        \
	} while (0)

#define ORA_SEED(REG, NAME)                                                \
	do {                                                               \
		__x86_##NAME.ptr = (void *)(__u64)pattern_reg(__i);        \
		__x86_##NAME##_tag = ORA_MARK_TAG;                         \
		__i++;                                                     \
	} while (0);

#define ORA_SEED_ALL()                                                     \
	do {                                                               \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_SEED)                           \
	} while (0)

/* The independent id -> body classification: the seven armed `X86_SIM_BPF_CALL_*`
 * bodies in `bpf_map_lookup_elem .. bpf_ktime_get_ns` order, and the default
 * zero-write arm for every other id. */
enum ora_body {
	ORA_DEFAULT, ORA_LOOKUP, ORA_UPDATE, ORA_DELETE,
	ORA_UID_GID, ORA_PID_TGID, ORA_SMP_ID, ORA_KTIME_ID,
};

static enum ora_body model_body(unsigned long long id)
{
	if (id == 1ULL)
		return ORA_LOOKUP;
	if (id == 2ULL)
		return ORA_UPDATE;
	if (id == 3ULL)
		return ORA_DELETE;
	if (id == 4ULL)
		return ORA_UID_GID;
	if (id == 5ULL)
		return ORA_PID_TGID;
	if (id == 6ULL)
		return ORA_SMP_ID;
	if (id == 7ULL)
		return ORA_KTIME_ID;
	return ORA_DEFAULT;
}

/* The RAX value and tag each body leaves, from the fixed stub returns. */
static void model_rax(enum ora_body b, __u64 *val, __u8 *tag)
{
	switch (b) {
	case ORA_LOOKUP:
		*val = (__u64)(long)ORA_MAP_PTR;
		*tag = X86_SIM_TAG_MAP_VALUE;
		return;
	case ORA_UPDATE:
		*val = (__u64)ORA_UPD_RET;
		*tag = X86_SIM_TAG_SCALAR;
		return;
	case ORA_DELETE:
		*val = (__u64)ORA_DEL_RET;
		*tag = X86_SIM_TAG_SCALAR;
		return;
	case ORA_UID_GID:
	case ORA_PID_TGID:
	case ORA_SMP_ID:
	case ORA_DEFAULT:
		*val = 0ULL;
		*tag = X86_SIM_TAG_SCALAR;
		return;
	case ORA_KTIME_ID:
		*val = ORA_KTIME;
		*tag = X86_SIM_TAG_SCALAR;
		return;
	}
}

/* Drive `X86_SIM_BPF_CALL_ID(id)`, capture the whole register file, and check
 * that RAX is exactly what the independent model names and that no other
 * register or tag changed. */
static void check_id(unsigned long long id)
{
	void *before[16], *after[16];
	__u8 btag[16], atag[16];
	__u64 want_val;
	__u8 want_tag;
	int changed = -1;
	unsigned j;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();
		ORA_SNAPSHOT(before, btag);

		X86_SIM_BPF_CALL_ID((__u64)id);
		ORA_SNAPSHOT(after, atag);

		for (j = 0; j < 16U; j++) {
			if (atag[j] != btag[j] || after[j] != before[j]) {
				if (changed >= 0) {
					printf("MISMATCH id=%llu multiple "
					       "cells changed (%d and %u)\n",
					       id, changed, j);
					failures++;
				}
				changed = (int)j;
			}
		}

		if (changed != 0) {
			printf("MISMATCH id=%llu changed cell got=%d (%s) "
			       "want=0 (rax)\n", id, changed,
			       changed >= 0 ? gpr_names[changed] : "none");
			failures++;
			return;
		}

		model_rax(model_body(id), &want_val, &want_tag);
		if ((__u64)(long)after[0] != want_val || atag[0] != want_tag) {
			printf("MISMATCH id=%llu rax=0x%llx tag=%u want=0x%llx "
			       "tag=%u\n", id,
			       (unsigned long long)(__u64)(long)after[0],
			       atag[0], (unsigned long long)want_val,
			       want_tag);
			failures++;
		}
	}
}

/* Drive `X86_SIM_BPF_CALL_REG(REG)` with the register planted to `id`, and
 * check the same RAX result. This is the exact body the chain's
 * `X86_OP_CALL_REG` arm runs. */
static void check_reg(unsigned reg, unsigned long long id)
{
	void *before[16], *after[16];
	__u8 btag[16], atag[16];
	__u64 want_val;
	__u8 want_tag;
	int changed = -1;
	unsigned j;
	unsigned long long eff_id = (reg < 16U) ? id : 0ULL;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();
		X86_SIM_L_WRITE_REG_PTR_TAG(reg, (void *)(__u64)id,
					    ORA_MARK_TAG);
		ORA_SNAPSHOT(before, btag);
		X86_SIM_BPF_CALL_REG(reg);
		ORA_SNAPSHOT(after, atag);

		for (j = 0; j < 16U; j++) {
			if (atag[j] != btag[j] || after[j] != before[j]) {
				if (changed >= 0) {
					printf("MISMATCH reg=%u id=%llu multiple "
					       "cells changed (%d and %u)\n",
					       reg, id, changed, j);
					failures++;
				}
				changed = (int)j;
			}
		}

		/* The plant set `reg`; the fresh snapshot already holds it, so
		 * the call must change only RAX (cell 0). */
		if (changed != 0) {
			printf("MISMATCH reg=%u id=%llu changed cell got=%d "
			       "want=0 (rax)\n", reg, id, changed);
			failures++;
			return;
		}

		model_rax(model_body(eff_id), &want_val, &want_tag);
		if ((__u64)(long)after[0] != want_val || atag[0] != want_tag) {
			printf("MISMATCH reg=%u id=%llu rax=0x%llx tag=%u "
			       "want=0x%llx tag=%u\n", reg, id,
			       (unsigned long long)(__u64)(long)after[0],
			       atag[0], (unsigned long long)want_val,
			       want_tag);
			failures++;
		}
	}
}

int main(void)
{
	unsigned long long id;
	unsigned reg;

	/* The generated count and the slot selector must line up with the
	 * sim's hand-written ladder. */
	cases++;
	if (KPROG_X86_HELPER_COUNT != 7U ||
	    KPROG_X86_HELPER_SLOT(1ULL) != 0U ||
	    KPROG_X86_HELPER_SLOT(7ULL) != 6U ||
	    KPROG_X86_HELPER_SLOT(8ULL) != KPROG_X86_HELPER_SLOT_NONE) {
		printf("MISMATCH helper dispatch constant drift\n");
		failures++;
	}

	/* Drive the ladder over the whole named id space and a way past it. */
	for (id = 0; id <= 64ULL; id++)
		check_id(id);

	/* Drive the routed call-register body for every register number, each
	 * planted to every armed id plus a default id. */
	{
		static const unsigned long long ids[] = {
			0ULL, 1ULL, 2ULL, 3ULL, 4ULL, 5ULL, 6ULL, 7ULL,
			8ULL, 21ULL, 22ULL,
		};
		size_t ii;

		for (reg = 0; reg <= 0xffU; reg++)
			for (ii = 0; ii < sizeof(ids) / sizeof(ids[0]); ii++)
				check_reg(reg, ids[ii]);
	}

	if (failures != 0) {
		printf("x86 helper dispatch route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 helper dispatch route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
