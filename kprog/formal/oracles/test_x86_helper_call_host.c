/*
 * Host cross-check for the x86 simulator's BPF *helper call* bodies.
 *
 * Checks the original seven direct call macros, including nonzero PID/UID/CPU
 * returns. The full sparse Linux-ID ladder has its own typed ABI host.
 * Toolchain helper pointers encode small integer IDs, so this host renames
 * them before inclusion and supplies callable capture functions instead.
 * Lookup returns a tagged pointer; update/delete and the four other helpers
 * return scalars. Every forwarding call is counted and checked.
 * Run through make -C kprog/formal check.
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

#undef X86_SIM_L_UNSUPPORTED_HELPER
#define X86_SIM_L_UNSUPPORTED_HELPER() xcpu_sim_unsupported_opcode()

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

	/* PID/UID/CPU must reach the real typed helper call, not return a fake
	 * constant. Preserve the original return canary and count each call. */
	TRY_VALUE(ktime_get_ns, calls_ktime);
	TRY_VALUE(get_current_pid_tgid, calls_pid);
	TRY_VALUE(get_current_uid_gid, calls_uid);
	TRY_VALUE(get_smp_processor_id, calls_smp);

	/* Also check the full return value, including CPU-ID32-bit widening. */
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

	TRY_CONST(get_current_pid_tgid, stub_value);
	TRY_CONST(get_current_uid_gid, stub_value);
	TRY_CONST(get_smp_processor_id, (__u32)stub_value);

	/* Lookup returns a map pointer; update/delete return scalar status. */
#define TRY_MAP(NAME, COUNTER, WANT_TAG)                                             \
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
		if (__x86_rax_tag != (WANT_TAG)) { failures++; }           \
		if (unsupported_calls) {                                   \
			printf("%-28s reached the unsupported hook\n",      \
			       #NAME);                                     \
			failures++;                                        \
			unsupported_calls = 0;                             \
		}                                                          \
	} while (0)

	TRY_MAP(map_lookup_elem, calls_lookup, X86_SIM_TAG_MAP_VALUE);
	TRY_MAP(map_update_elem, calls_update, X86_SIM_TAG_SCALAR);
	TRY_MAP(map_delete_elem, calls_delete, X86_SIM_TAG_SCALAR);

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

    /* The failure route records an error and preserves the accumulator;
     * check_helper_errors.py separately checks real compilation rejection. */
    {
        DECL_STATE();
        __x86_rax.ptr = (void *)(long)sentinel;
        X86_SIM_BPF_CALL_ID(13ULL);
        cases++;
        if (unsupported_calls != 1 || (__u64)(long)__x86_rax.ptr != sentinel) {
            printf("unarmed helper did not preserve the failure boundary\n");
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