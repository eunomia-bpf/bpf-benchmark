/*
 * Route host cross-check for the AArch64 BPF helper-argument pointer
 * contract (STEP 0139).
 *
 * The routed helper `ARM64_SIM_L_HELPER_ARG_PTR` in
 * `arm64/arm64_sim_local_bpf.h` resolves the pointer a BPF helper call
 * receives in a register argument by selecting its source through the
 * generated contract `generated/arm64_helper_arg_ptr.h`: the stack arena
 * pointer when the argument register's provenance tag is the stack tag, the
 * register's raw pointer otherwise. This oracle declares the full register
 * file, plants each register's pointer and provenance tag, drives the real
 * helper, and compares the pointer it returns to an independent model that
 * restates the 2-way selection over the raw fact. The generated selector's
 * own fact table is also crossed against the independent statement. Exit 1
 * on mismatch.
 *
 * Build/run (from kprog/formal):
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_helper_arg_ptr_route_host.c -o /tmp/t_hap_route
 *   /tmp/t_hap_route
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
#include "guarded_memory_host.h"

static __s64 __a64_sp;
/* Bind the actual invocation-local state to the route drivers. Entry
 * snapshots must be captured at function scope, as in generated B. */
static union arm64_sim_gpr *const *host_cells;
static __u8 *const *host_tag_cells;
#define __a64_cells host_cells
#define __a64_tag_cells host_tag_cells
static __u64 *host___a64_numeric_sp;
#define __a64_numeric_sp (*host___a64_numeric_sp)
static __u64 *host___a64_numeric_return;
#define __a64_numeric_return (*host___a64_numeric_return)
static __u8 *host___a64_numeric_sp_valid;
#define __a64_numeric_sp_valid (*host___a64_numeric_sp_valid)
static __u8 *host___a64_numeric_return_valid;
#define __a64_numeric_return_valid (*host___a64_numeric_return_valid)
static __u8 *host___a64_sim_is_xdp;
#define __a64_sim_is_xdp (*host___a64_sim_is_xdp)
static void * *host___a64_sim_helper_ctx;
#define __a64_sim_helper_ctx (*host___a64_sim_helper_ctx)
static void * *host___a64_sim_helper_abi_base;
#define __a64_sim_helper_abi_base (*host___a64_sim_helper_abi_base)
typedef union {
    __u8 b[ARM64_SIM_STACK_BYTES];
    __u64 q[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
} host_stack_arena;
static volatile host_stack_arena *host_stack;
/* The guarded arena supplies the bytes; entry-private metadata is fresh. */
static __u8 __a64_stack_tag[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
static __u8 __a64_stack_scalar_valid[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)];
#define __a64_stack (*host_stack)
static void access_boundary(void *argument)
{
    (void)argument;
    volatile unsigned char value=*(volatile unsigned char *)ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X1);
    (void)value;
}

static int failures;
static unsigned long cases;

/* The model's parallel register file: the pointer value and provenance tag of
 * every general-purpose register, plus the stack pointer. */
static void *mptr[31];
static __u8 mtag[31];
static __s64 msp;

/* The register's pointer and tag as the helper reads them: `ARM64_SP` always
 * reads the stack pointer and its stack tag. */
static void *m_reg_ptr(unsigned reg)
{
	return reg == ARM64_SP ? (void *)(long)msp : mptr[reg];
}

static __u8 m_reg_tag(unsigned reg)
{
	return reg == ARM64_SP ? ARM64_SIM_TAG_STACK : mtag[reg];
}

/* The independent 2-way pointer selection: the stack arena pointer exactly
 * when the register's provenance tag is the stack tag, the register's raw
 * pointer otherwise. Restated from the raw fact with no reference to the
 * generated selector. */
static void *model_arg_ptr(unsigned reg)
{
	void *ptr = m_reg_ptr(reg);

	if (m_reg_tag(reg) == ARM64_SIM_TAG_STACK)
		return (void *)&__a64_stack.b[
			(__s64)ARM64_SIM_STACK_BIAS +
			(__s64)(long)ptr];
	return ptr;
}

/* Plant the simulator's register file and the model's in lockstep. */
static void plant(unsigned reg, void *ptr, __u8 tag)
{
	if (reg == ARM64_SP) {
		__a64_sp = (__s64)(long)ptr;
		msp = (__s64)(long)ptr;
		return;
	}
	ARM64_SIM_L_WRITE_REG_PTR_TAG(reg, ptr, tag);
	mptr[reg] = ptr;
	mtag[reg] = tag;
}

/* Drive the real helper at one register and compare the pointer it returns to
 * the independent model. */
static void drive(unsigned reg)
{
	void *got = ARM64_SIM_L_HELPER_ARG_PTR(reg);
	void *want = model_arg_ptr(reg);

	cases++;
	if (got != want) {
		printf("MISMATCH helper arg ptr reg=%u tag=%u ptr=%p "
		       "got=%p want=%p\n", reg, m_reg_tag(reg),
		       m_reg_ptr(reg), got, want);
		failures++;
	}
}

/* The generated selector must name the same source the independent 2-way
 * statement names, at every fact value the helper feeds it. */
static void check_selector(void)
{
	unsigned tagged;

	cases++;
	if (KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT);
		failures++;
	}

	for (tagged = 0; tagged <= 1U; tagged++) {
		unsigned got = KPROG_ARM64_HELPER_ARG_PTR_BODY(tagged);
		unsigned want =
			(tagged == 1U) ?
			KPROG_ARM64_HELPER_ARG_PTR_BODY_STACK_ARENA_PTR :
			KPROG_ARM64_HELPER_ARG_PTR_BODY_RAW_PTR;

		cases++;
		if (got != want) {
			printf("MISMATCH selector tagged=%u got=%u want=%u\n",
			       tagged, got, want);
			failures++;
		}
	}
}

#undef __a64_numeric_sp
#undef __a64_numeric_return
#undef __a64_numeric_sp_valid
#undef __a64_numeric_return_valid
#undef __a64_sim_is_xdp
#undef __a64_sim_helper_ctx
#undef __a64_sim_helper_abi_base
#undef __a64_cells
#undef __a64_tag_cells
int main(void)
{
    ARM64_SIM_L_DECLARE_STATE();
    host_cells = __a64_cells;
    host_tag_cells = __a64_tag_cells;
    host___a64_numeric_sp = &__a64_numeric_sp;
    host___a64_numeric_return = &__a64_numeric_return;
    host___a64_numeric_sp_valid = &__a64_numeric_sp_valid;
    host___a64_numeric_return_valid = &__a64_numeric_return_valid;
    host___a64_sim_is_xdp = &__a64_sim_is_xdp;
    host___a64_sim_helper_ctx = &__a64_sim_helper_ctx;
    host___a64_sim_helper_abi_base = &__a64_sim_helper_abi_base;

    struct host_guarded_memory guarded=host_guarded_memory(ARM64_SIM_STACK_BYTES);
    host_stack=(volatile host_stack_arena *)guarded.data;
	/* The stack-tagged pointer values keep the biased arena index a valid
	 * arena pointer: the biased index `BIAS + ptr` in
	 * [0, STACK_BYTES], one-past-end included, which for the 96 bias and
	 * 160-byte arena means `ptr` in [0, 64]. The previous set was written
	 * as `96 + k`, reading the bias as already included; four of its seven
	 * entries then biased past the arena (indices 184..248), so those
	 * formed addresses outside the frame all along. */
	static const __s64 stack_ptrs[] = {
		0, 8, 16, 32, 48, 56, 64,
	};
	/* Raw pointer values a non-stack-tagged register may carry: none is
	 * array-indexed, so each must pass through unchanged. */
	static const __s64 raw_ptrs[] = {
		0, 1, 0x1000, (__s64)0x7ffffffffff0ULL,
		(__s64)0xffffffffffffffffULL, (__s64)0xdeadbeefcafef00dULL,
	};
	static const __u8 tags[] = {
		ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_STACK,
		ARM64_SIM_TAG_PACKET, ARM64_SIM_TAG_MAP_PTR,
	};
	unsigned reg;
	unsigned t;
	unsigned p;

	cases++;
	if (sizeof(__a64_stack.b) != ARM64_SIM_STACK_BYTES) {
		printf("MISMATCH layout: b=%lu\n",
		       (unsigned long)sizeof(__a64_stack.b));
		failures++;
	}

	check_selector();

	/* Every general-purpose register: plant a raw pointer at each tag; a
	 * stack tag drives the arena pointer, every other tag passes the raw
	 * pointer through. */
	for (reg = 0; reg < 31U; reg++) {
		for (t = 0; t < sizeof(tags) / sizeof(tags[0]); t++) {
			if (tags[t] == ARM64_SIM_TAG_STACK) {
				for (p = 0; p < sizeof(stack_ptrs) /
						sizeof(stack_ptrs[0]); p++) {
					plant(reg, (void *)(long)
					      stack_ptrs[p], tags[t]);
					drive(reg);
				}
			} else {
				for (p = 0; p < sizeof(raw_ptrs) /
						sizeof(raw_ptrs[0]); p++) {
					plant(reg, (void *)(long)
					      raw_ptrs[p], tags[t]);
					drive(reg);
				}
			}
		}
	}

	/* The stack pointer always reads the stack tag, so every in-bounds
	 * offset resolves to the arena pointer. */
	for (p = 0; p < sizeof(stack_ptrs) / sizeof(stack_ptrs[0]); p++) {
		plant(ARM64_SP, (void *)(long)stack_ptrs[p],
		      ARM64_SIM_TAG_STACK);
		drive(ARM64_SP);
	}

    /* Address calculation remains faithful; the actual dereference faults. */
    {
        static const __s64 past_ptrs[]={64,72,160};
        for (unsigned k=0;k<sizeof(past_ptrs)/sizeof(past_ptrs[0]);k++) {
            plant(ARM64_X1,(void *)(long)past_ptrs[k],ARM64_SIM_TAG_STACK);
            cases++;
            if (!host_memory_fault(access_boundary,NULL)) {
                printf("MISMATCH helper pointer dereference off=%lld did not fault\n",(long long)past_ptrs[k]);
                failures++;
            }
        }
    }
    host_guarded_memory_free(guarded);

	if (failures) {
		printf("arm64 helper arg ptr route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 helper arg ptr route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
