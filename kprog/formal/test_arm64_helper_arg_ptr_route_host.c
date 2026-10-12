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

ARM64_SIM_L_DECLARE_STATE();
ARM64_SIM_L_DECLARE_STACK();

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

int main(void)
{
	/* The stack-tagged pointer values keep the biased arena index in
	 * bounds: `ARM64_SIM_STACK_BIAS + ptr` in [0, ARM64_SIM_STACK_BYTES). */
	static const __s64 stack_ptrs[] = {
		96 - 96, 96 - 64, 96 - 32, 96 - 8, 96, 96 + 32, 96 + 56,
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

	if (failures) {
		printf("arm64 helper arg ptr route host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 helper arg ptr route host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
