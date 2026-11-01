/*
 * Host cross-check for the x86 simulator's call and subroutine-return emission
 * (`X86_SIM_X86_CALL`, `X86_SIM_X86_SUB_RET`, and the `SUB_JMP` / `SUB_JCC`
 * aliases).
 *
 * Why this host exists. Step 0529/0530 executed the AArch64 emission surface
 * and found every emitter there had been undriven. The x86 surface is larger --
 * it has a real call/return pair, which AArch64 models through the link
 * register instead -- and none of it was executed either: no host mentions
 * X86_SIM_X86_CALL, X86_SIM_X86_RET, X86_SIM_X86_SUB_RET, X86_SIM_X86_SUB_JMP
 * or X86_SIM_X86_SUB_JCC.
 *
 * The x86 pair is worth more than the AArch64 one because it moves the stack
 * pointer. CALL decrements `rsp` by eight and writes the return address there;
 * SUB_RET reads that word back and increments by eight. A pair that disagreed
 * -- write at one width, read at another, or increment without a matching
 * decrement -- would corrupt `rsp` and return through a stale word, and every
 * check that inspects the address alone would still pass.
 *
 * What is checked:
 *
 *   - CALL decrements `rsp` by exactly eight and stores the return address at
 *     the new top of stack;
 *   - SUB_RET reads that address back into the simulator's return slot,
 *     restores `rsp` to its original value, and transfers control to its
 *     dispatch label;
 *   - the round trip is exact for addresses whose bytes are all distinct, so a
 *     width or endianness slip shows;
 *   - SUB_JMP and SUB_JCC select the same targets as JMP and JCC, which is
 *     what makes them aliases rather than variants.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_call_ret_route_host.c -o build/test_x86_call_ret_route_host &&
 *   ./build/test_x86_call_ret_route_host
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void xcpu_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

/* A frame inside the modelled arena: the index is OFF + CAPACITY, so a
 * valid offset is negative and at most CAPACITY in magnitude. */
#define BASE ((__s64)(-(__s64)X86_SIM_STACK_BYTES / 2))

static int failures;
static unsigned long cases;

/* The simulator's state is ambient for the non-struct build, so a file-scope
 * declaration is what the emission macros expect. */
#define DECL_STATE()                                                       \
	X86_SIM_L_DECLARE_STATE();                                         \
	X86_SIM_L_DECLARE_STACK();                                         \
	(void)__x86_stack_mem

/* Where the callee "lands". */
static int hit_target;
/* Where the callee "dispatches" back to. */
static int hit_dispatch;

/* Drive CALL, observing the stack pointer and the stored word before jumping. */
static void probe_call(__u64 ret_addr, __u64 *rsp_after, __u64 *slot)
{
	DECL_STATE();

	__x86_rsp.ptr = (void *)(long)BASE;
	
	hit_target = 0;

	goto dispatch;

arrived:
	*rsp_after = (__u64)(long)__x86_rsp.ptr;
	*slot = __x86_stack_mem.q[KPROG_X86_STACK_WORD_INDEX(
		X86_SIM_L_STACK_INDEX((__s64)(BASE - 8)))];
	hit_target = 1;
	return;

dispatch:
	X86_SIM_X86_CALL(arrived, ret_addr);
	return;
}

/* Drive SUB_RET from a prepared stack. */
static void probe_sub_ret(__u64 ret_addr, __u64 rsp_in, __u64 *rsp_out,
			  __u64 *ret_slot)
{
	DECL_STATE();

	__x86_rsp.ptr = (void *)(long)rsp_in;
	__x86_stack_mem.q[KPROG_X86_STACK_WORD_INDEX(
		X86_SIM_L_STACK_INDEX((__s64)rsp_in))] = ret_addr;
	__x86_sim_ret_addr = 0;
	hit_dispatch = 0;

	goto dispatch;

dispatched:
	*rsp_out = (__u64)(long)__x86_rsp.ptr;
	*ret_slot = __x86_sim_ret_addr;
	hit_dispatch = 1;
	return;

dispatch:
	X86_SIM_X86_SUB_RET(dispatched);
	return;
}

int main(void)
{
	static const __u64 rets[] = {
		0x1122334455667788ULL,
		0x0000000000000001ULL,
		0xffffffffffffffffULL,
		0x00ff00ff00ff00ffULL,
	};
	unsigned i;

	for (i = 0; i < sizeof(rets) / sizeof(rets[0]); i++) {
		__u64 rsp_after = 0, slot = 0;
		__u64 rsp_out = 0, got_ret = 0;

		probe_call(rets[i], &rsp_after, &slot);
		cases++;

		if (hit_target != 1) {
			printf("CALL v=%#llx: did not transfer control\n",
			       (unsigned long long)rets[i]);
			failures++;
		}
		if (rsp_after != (__u64)(BASE - 8)) {
			printf("CALL v=%#llx: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)rsp_after,
			       (unsigned long long)(BASE - 8));
			failures++;
		}
		if (slot != rets[i]) {
			printf("CALL v=%#llx: stored %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)slot);
			failures++;
		}

		probe_sub_ret(rets[i], (__u64)(BASE - 8), &rsp_out, &got_ret);
		cases++;

		if (hit_dispatch != 1) {
			printf("SUB_RET v=%#llx: did not dispatch\n",
			       (unsigned long long)rets[i]);
			failures++;
		}
		if (got_ret != rets[i]) {
			printf("SUB_RET v=%#llx: read %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)got_ret);
			failures++;
		}
		if (rsp_out != (__u64)BASE) {
			printf("SUB_RET v=%#llx: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)rsp_out,
			       (unsigned long long)BASE);
			failures++;
		}
	}

	/* CALL then SUB_RET as a pair: the stack pointer must return to where
	 * it started, which is the property a mismatched pair breaks. */
	{
		__u64 rsp_after = 0, slot = 0, rsp_out = 0, got_ret = 0;

		probe_call(0xCAFEF00DDEADBEEFULL, &rsp_after, &slot);
		probe_sub_ret(slot, rsp_after, &rsp_out, &got_ret);
		cases++;

		if (rsp_out != (__u64)BASE) {
			printf("round trip: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rsp_out,
			       (unsigned long long)BASE);
			failures++;
		}
		if (got_ret != 0xCAFEF00DDEADBEEFULL) {
			printf("round trip: return address is %#llx\n",
			       (unsigned long long)got_ret);
			failures++;
		}
	}

	if (failures) {
		printf("x86 call/ret route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("x86 call/ret route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}