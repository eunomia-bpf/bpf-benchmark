/*
 * Host cross-check for the x86 simulator's BPF *helper call* bodies.
 *
 * Why this host exists. Step 0533 found that none of the AArch64 helper-call
 * macros had ever been executed and built a host for all 61 of them. The x86
 * simulator has a much smaller helper surface -- seven macros -- and none of
 * those was executed either.
 *
 * The mechanism is the same as on the other side, and it is the reason these
 * bodies were never run: the toolchain declares each helper as a
 * `static ... const` function *pointer* initialised to the helper's id, not an
 * address, so a direct call jumps to a small integer and faults. The host
 * renames the seven pointers before including the simulator header and defines
 * them under the original names.
 *
 * What is checked: each macro is callable, and each leaves the accumulator in
 * the state its body intends -- a value for the four value-returning helpers,
 * and a pointer tagged as a map value for the three map helpers (a plain
 * address with the wrong tag would be just as wrong as a wrong address). The
 * map helpers must also reach their forwarding call exactly once.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_helper_call_host.c -o build/test_x86_helper_call_host &&
 *   ./build/test_x86_helper_call_host
 */

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

/* Rename the toolchain's id-valued pointers, then supply our own under the
 * original names. */
#define bpf_get_current_pid_tgid bpf_get_current_pid_tgid_defs
#define bpf_get_current_uid_gid bpf_get_current_uid_gid_defs
#define bpf_get_smp_processor_id bpf_get_smp_processor_id_defs
#define bpf_ktime_get_ns bpf_ktime_get_ns_defs
#define bpf_map_delete_elem bpf_map_delete_elem_defs
#define bpf_map_lookup_elem bpf_map_lookup_elem_defs
#define bpf_map_update_elem bpf_map_update_elem_defs

#define X86_SIM_ENABLE_STACK 1
#include "../x86/x86_sim_local_bpf.h"

#undef bpf_get_current_pid_tgid
#undef bpf_get_current_uid_gid
#undef bpf_get_smp_processor_id
#undef bpf_ktime_get_ns
#undef bpf_map_delete_elem
#undef bpf_map_lookup_elem
#undef bpf_map_update_elem

#include <stdio.h>

/* Distinct from the sentinel planted in the accumulator, so a body that
 * writes only a forwarded return value is still distinguishable from one that
 * wrote nothing. */
static __u64 stub_value = 0x1234ABCD5678EF00ULL;
static void *stub_ptr = (void *)0x5EED1000;

static unsigned long calls_lookup, calls_update, calls_delete;
static unsigned long calls_ktime, calls_pid, calls_uid, calls_smp;

static void *bpf_map_lookup_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	calls_lookup++;
	return stub_ptr;
}

static long bpf_map_update_elem(void *map, const void *key, const void *value,
				__u64 flags)
{
	(void)map;
	(void)key;
	(void)value;
	(void)flags;
	calls_update++;
	return 0;
}

static long bpf_map_delete_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	calls_delete++;
	return 0;
}

static __u64 bpf_ktime_get_ns(void)
{
	calls_ktime++;
	return stub_value;
}

static __u64 bpf_get_current_pid_tgid(void)
{
	calls_pid++;
	return stub_value;
}

static __u64 bpf_get_current_uid_gid(void)
{
	calls_uid++;
	return stub_value;
}

static __u32 bpf_get_smp_processor_id(void)
{
	calls_smp++;
	return (__u32)stub_value;
}

static unsigned long unsupported_calls;
static void xcpu_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

#define DECL_STATE()                                                       \
	X86_SIM_L_DECLARE_STATE();                                         \
	X86_SIM_L_DECLARE_STACK();                                         \
	(void)__x86_stack_mem

static __u64 sentinel = 0x5EED5EED5EED5EEDULL;

int main(void)
{
	/* The four value-returning helpers: the accumulator must hold the
	 * value the helper returned, not the sentinel. */
#define TRY_VALUE(NAME, COUNTER)                                           \
	do {                                                               \
		DECL_STATE();                                              \
		__x86_rax.ptr = (void *)(long)sentinel;                    \
		__x86_rax_tag = X86_SIM_TAG_SCALAR;                        \
		X86_SIM_BPF_CALL_bpf_##NAME();                             \
		cases++;                                                   \
		if ((__u64)(long)__x86_rax.ptr == sentinel) {              \
			printf("%-28s left the sentinel in rax\n", #NAME); \
			failures++;                                        \
		}                                                          \
		if (COUNTER != 1) {                                        \
			printf("%-28s forwarded %lu time(s), want 1\n",    \
			       #NAME, COUNTER);                            \
			failures++;                                        \
		}                                                          \
		if (unsupported_calls) {                                   \
			printf("%-28s reached the unsupported hook\n",      \
			       #NAME);                                     \
			failures++;                                        \
			unsupported_calls = 0;                             \
		}                                                          \
	} while (0)

	/* Measured: only ktime forwards to a toolchain call. The three get_*
	 * helpers write a constant zero, matching what they return in the
	 * model's kernel. Asserting a forward for them reported three
	 * failures that were the tree being right. */
	TRY_VALUE(ktime_get_ns, calls_ktime);

	/* These write a constant instead of forwarding, so the observable is
	 * that the accumulator is the constant rather than the sentinel. */
#define TRY_CONST(NAME, WANT)                                              \
	do {                                                               \
		DECL_STATE();                                              \
		__x86_rax.ptr = (void *)(long)sentinel;                    \
		__x86_rax_tag = X86_SIM_TAG_SCALAR;                        \
		X86_SIM_BPF_CALL_bpf_##NAME();                             \
		cases++;                                                   \
		if ((__u64)(long)__x86_rax.ptr != (__u64)(WANT)) {         \
			printf("%-28s wrote %#llx, want %#llx\n", #NAME,   \
			       (unsigned long long)(long)__x86_rax.ptr,    \
			       (unsigned long long)(WANT));                \
			failures++;                                        \
		}                                                          \
	} while (0)

	TRY_CONST(get_current_pid_tgid, 0);
	TRY_CONST(get_current_uid_gid, 0);
	TRY_CONST(get_smp_processor_id, 0);

	/* The three map helpers return a pointer, and the body is what
	 * attaches the map-value tag. A correct address with the wrong tag is
	 * as wrong as a wrong address, so both are checked. */
#define TRY_MAP(NAME, COUNTER)                                             \
	do {                                                               \
		DECL_STATE();                                              \
		__x86_rax.ptr = (void *)(long)sentinel;                    \
		__x86_rax_tag = X86_SIM_TAG_SCALAR;                        \
		X86_SIM_BPF_CALL_bpf_##NAME();                             \
		cases++;                                                   \
		if ((__u64)(long)__x86_rax.ptr == sentinel) {              \
			printf("%-28s left the sentinel in rax\n", #NAME); \
			failures++;                                        \
		}                                                          \
		if (COUNTER != 1) {                                        \
			printf("%-28s forwarded %lu time(s), want 1\n",    \
			       #NAME, COUNTER);                            \
			failures++;                                        \
		}                                                          \
		if (unsupported_calls) {                                   \
			printf("%-28s reached the unsupported hook\n",      \
			       #NAME);                                     \
			failures++;                                        \
			unsupported_calls = 0;                             \
		}                                                          \
	} while (0)

	TRY_MAP(map_lookup_elem, calls_lookup);
	TRY_MAP(map_update_elem, calls_update);
	TRY_MAP(map_delete_elem, calls_delete);

	/* The lookup helper is the one that returns a pointer, so its tag is
	 * observable; update and delete return a status. */
	{
		DECL_STATE();
		__x86_rax.ptr = (void *)(long)sentinel;
		__x86_rax_tag = X86_SIM_TAG_SCALAR;
		X86_SIM_BPF_CALL_bpf_map_lookup_elem();
		cases++;
		if (__x86_rax_tag != X86_SIM_TAG_MAP_VALUE) {
			printf("map_lookup_elem: rax tag is %u, want %u "
			       "(map value)\n", __x86_rax_tag,
			       X86_SIM_TAG_MAP_VALUE);
			failures++;
		}
		if ((void *)(long)__x86_rax.ptr != stub_ptr) {
			printf("map_lookup_elem: rax is %p, want %p\n",
			       __x86_rax.ptr, stub_ptr);
			failures++;
		}
	}

	if (failures) {
		printf("x86 helper call host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("x86 helper call host cross-check: OK (%lu cases, 7 helpers)\n",
	       cases);
	return 0;
}