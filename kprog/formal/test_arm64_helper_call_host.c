/*
 * Host cross-check for the AArch64 simulator's BPF *helper call* bodies.
 *
 * Why this host exists. The simulator defines 61 helper-call macros, one per
 * helper it recognises, and none of them had ever been executed: no host in
 * the tree mentions ARM64_SIM_BPF_CALL_bpf_* at all. That is the largest
 * unexecuted surface in the simulator, and it is where the model meets the
 * real kernel interface.
 *
 * Making them runnable takes one non-obvious step. `bpf_helpers.h` declares
 * each helper as a `static ... const` function *pointer* initialised to the
 * helper's id -- a small integer, not an address -- so calling one directly
 * jumps to address 5 and faults. A host therefore renames each pointer before
 * including the simulator header and supplies its own definition under the
 * original name. Measured: without the rename the first call is a SIGSEGV at
 * address 5; with it the body runs and writes x0.
 *
 * What is checked, for all 61 macros: that each is callable, that it writes
 * x0 (a body doing nothing leaves the sentinel), and that the eighteen which
 * forward to a real `bpf_*` call reach it exactly once -- so the forwarding
 * arms are exercised rather than merely well-formed.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_helper_call_host.c -o build/test_arm64_helper_call_host &&
 *   ./build/test_arm64_helper_call_host
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

#define bpf_ktime_get_boot_ns bpf_ktime_get_boot_ns_defs
#define bpf_ktime_get_ns bpf_ktime_get_ns_defs
#define bpf_l3_csum_replace bpf_l3_csum_replace_defs
#define bpf_l4_csum_replace bpf_l4_csum_replace_defs
#define bpf_map_delete_elem bpf_map_delete_elem_defs
#define bpf_map_lookup_elem bpf_map_lookup_elem_defs
#define bpf_map_update_elem bpf_map_update_elem_defs
#define bpf_perf_event_output bpf_perf_event_output_defs
#define bpf_probe_read bpf_probe_read_defs
#define bpf_probe_read_kernel bpf_probe_read_kernel_defs
#define bpf_probe_read_kernel_str bpf_probe_read_kernel_str_defs
#define bpf_probe_read_str bpf_probe_read_str_defs
#define bpf_probe_read_user bpf_probe_read_user_defs
#define bpf_probe_read_user_str bpf_probe_read_user_str_defs
#define bpf_sk_fullsock bpf_sk_fullsock_defs
#define bpf_skb_load_bytes bpf_skb_load_bytes_defs
#define bpf_skb_load_bytes_relative bpf_skb_load_bytes_relative_defs
#define bpf_skb_store_bytes bpf_skb_store_bytes_defs

#define ARM64_SIM_ENABLE_STACK 1
#include "../arm64/arm64_sim_local_bpf.h"
#undef bpf_ktime_get_boot_ns
#undef bpf_ktime_get_ns
#undef bpf_l3_csum_replace
#undef bpf_l4_csum_replace
#undef bpf_map_delete_elem
#undef bpf_map_lookup_elem
#undef bpf_map_update_elem
#undef bpf_perf_event_output
#undef bpf_probe_read
#undef bpf_probe_read_kernel
#undef bpf_probe_read_kernel_str
#undef bpf_probe_read_str
#undef bpf_probe_read_user
#undef bpf_probe_read_user_str
#undef bpf_sk_fullsock
#undef bpf_skb_load_bytes
#undef bpf_skb_load_bytes_relative
#undef bpf_skb_store_bytes

#include <stdio.h>

/* Sentinels distinct from any constant the bodies write, so a macro that did
 * nothing shows up in x0. */
/* The stub return value must differ from the sentinel planted in
 * x0, or a helper that writes only the return value looks unwritten. */
static __u64 sentinel_num = 0x5EED5EED5EED5EEDULL;
static __u64 stub_return = 0x1234ABCD5678EF00ULL;
static void *sentinel_ptr = (void *)0x5EED0000;

static unsigned long host_calls_ktime_get_boot_ns;
static unsigned long host_calls_ktime_get_ns;
static unsigned long host_calls_l3_csum_replace;
static unsigned long host_calls_l4_csum_replace;
static unsigned long host_calls_map_delete_elem;
static unsigned long host_calls_map_lookup_elem;
static unsigned long host_calls_map_update_elem;
static unsigned long host_calls_perf_event_output;
static unsigned long host_calls_probe_read;
static unsigned long host_calls_probe_read_kernel;
static unsigned long host_calls_probe_read_kernel_str;
static unsigned long host_calls_probe_read_str;
static unsigned long host_calls_probe_read_user;
static unsigned long host_calls_probe_read_user_str;
static unsigned long host_calls_sk_fullsock;
static unsigned long host_calls_skb_load_bytes;
static unsigned long host_calls_skb_load_bytes_relative;
static unsigned long host_calls_skb_store_bytes;

static __u64 bpf_ktime_get_boot_ns(void) { host_calls_ktime_get_boot_ns++; return stub_return; }
static __u64 bpf_ktime_get_ns(void) { host_calls_ktime_get_ns++; return stub_return; }
static long bpf_l3_csum_replace(struct __sk_buff *skb, __u32 offset, __u64 from, __u64 to, __u64 size) { host_calls_l3_csum_replace++; return stub_return; }
static long bpf_l4_csum_replace(struct __sk_buff *skb, __u32 offset, __u64 from, __u64 to, __u64 flags) { host_calls_l4_csum_replace++; return stub_return; }
static long bpf_map_delete_elem(void *map, const void *key) { host_calls_map_delete_elem++; return stub_return; }
static void * bpf_map_lookup_elem(void *map, const void *key) { host_calls_map_lookup_elem++; return sentinel_ptr; }
static long bpf_map_update_elem(void *map, const void *key, const void *value, __u64 flags) { host_calls_map_update_elem++; return stub_return; }
static long bpf_perf_event_output(void *ctx, void *map, __u64 flags, void *data, __u64 size) { host_calls_perf_event_output++; return stub_return; }
static long bpf_probe_read(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read++; return stub_return; }
static long bpf_probe_read_kernel(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read_kernel++; return stub_return; }
static long bpf_probe_read_kernel_str(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read_kernel_str++; return stub_return; }
static long bpf_probe_read_str(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read_str++; return stub_return; }
static long bpf_probe_read_user(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read_user++; return stub_return; }
static long bpf_probe_read_user_str(void *dst, __u32 size, const void *unsafe_ptr) { host_calls_probe_read_user_str++; return stub_return; }
static struct bpf_sock * bpf_sk_fullsock(struct bpf_sock *sk) { host_calls_sk_fullsock++; return sentinel_ptr; }
static long bpf_skb_load_bytes(const void *skb, __u32 offset, void *to, __u32 len) { host_calls_skb_load_bytes++; return stub_return; }
static long bpf_skb_load_bytes_relative(const void *skb, __u32 offset, void *to, __u32 len, __u32 start_header) { host_calls_skb_load_bytes_relative++; return stub_return; }
static long bpf_skb_store_bytes(struct __sk_buff *skb, __u32 offset, const void *from, __u32 len, __u64 flags) { host_calls_skb_store_bytes++; return stub_return; }

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

#define TRY(NAME)                                                          \
	do {                                                               \
		DECL_STATE();                                              \
		__a64_x0.x = sentinel_num;                                 \
		ARM64_SIM_BPF_CALL_bpf_##NAME();                           \
		cases++;                                                   \
		if (__a64_x0.x == sentinel_num) {                          \
			printf("%-28s left the sentinel: x0 unwritten\n",  \
			       #NAME);                                     \
			failures++;                                        \
		}                                                          \
		if (unsupported_calls) {                                   \
			printf("%-28s reached the unsupported hook\n",     \
			       #NAME);                                     \
			failures++;                                        \
			unsupported_calls = 0;                             \
		}                                                          \
	} while (0)

int main(void)
{
	TRY(clone_redirect);
	TRY(copy_from_user);
	TRY(copy_from_user_task);
	TRY(csum_diff);
	TRY(current_task_under_cgroup);
	TRY(fib_lookup);
	TRY(get_attach_cookie);
	TRY(get_current_cgroup_id);
	TRY(get_current_comm);
	TRY(get_current_pid_tgid);
	TRY(get_current_task);
	TRY(get_current_task_btf);
	TRY(get_current_uid_gid);
	TRY(get_func_arg);
	TRY(get_func_arg_cnt);
	TRY(get_func_ret);
	TRY(get_netns_cookie);
	TRY(get_prandom_u32);
	TRY(get_retval);
	TRY(get_smp_processor_id);
	TRY(get_socket_cookie);
	TRY(get_stack);
	TRY(get_stackid);
	TRY(ima_file_hash);
	TRY(ima_inode_hash);
	TRY(jiffies64);
	TRY(ktime_get_boot_ns);
	TRY(ktime_get_ns);
	TRY(l3_csum_replace);
	TRY(l4_csum_replace);
	TRY(map_delete_elem);
	TRY(map_lookup_elem);
	TRY(map_lookup_percpu_elem);
	TRY(map_update_elem);
	TRY(perf_event_output);
	TRY(probe_read);
	TRY(probe_read_kernel);
	TRY(probe_read_kernel_str);
	TRY(probe_read_str);
	TRY(probe_read_user);
	TRY(probe_read_user_str);
	TRY(redirect);
	TRY(redirect_neigh);
	TRY(seq_write);
	TRY(sk_fullsock);
	TRY(skb_adjust_room);
	TRY(skb_change_head);
	TRY(skb_change_proto);
	TRY(skb_change_tail);
	TRY(skb_change_type);
	TRY(skb_load_bytes);
	TRY(skb_load_bytes_relative);
	TRY(skb_pull_data);
	TRY(skb_set_tunnel_key);
	TRY(skb_store_bytes);
	TRY(skb_under_cgroup);
	TRY(tail_call);
	TRY(task_pt_regs);
	TRY(trace_printk);
	TRY(xdp_adjust_head);
	TRY(xdp_adjust_tail);

#define CHECK_FWD(n) CHECK_FWD_AT(n, 1)
#define CHECK_FWD_AT(n, want)                                             \
	do {                                                               \
		cases++;                                                   \
		if (host_calls_##n != (unsigned long)(want)) {             \
			printf("%-28s forwarded %lu time(s), want %d\n",    \
			       #n, host_calls_##n, (int)(want));           \
			failures++;                                        \
		}                                                          \
	} while (0)

	CHECK_FWD(ktime_get_boot_ns);
	CHECK_FWD(ktime_get_ns);
	CHECK_FWD(l3_csum_replace);
	CHECK_FWD(l4_csum_replace);
	CHECK_FWD(map_delete_elem);
	/* Some macros share a forwarding target: map_lookup_percpu_elem is an
	 * alias of map_lookup_elem, and copy_from_user / copy_from_user_task
	 * both drive the user probe. So the expected count is per *call
	 * site*, not per helper name. */
	CHECK_FWD_AT(map_lookup_elem, 2);
	CHECK_FWD(map_update_elem);
	CHECK_FWD(perf_event_output);
	CHECK_FWD(probe_read);
	CHECK_FWD(probe_read_kernel);
	CHECK_FWD(probe_read_kernel_str);
	CHECK_FWD(probe_read_str);
	CHECK_FWD_AT(probe_read_user, 3);
	CHECK_FWD(probe_read_user_str);
	CHECK_FWD(sk_fullsock);
	CHECK_FWD(skb_load_bytes);
	CHECK_FWD(skb_load_bytes_relative);
	CHECK_FWD(skb_store_bytes);

	if (failures) {
		printf("arm64 helper call host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 helper call host cross-check: OK (%lu cases, 61 helpers)\n",
	       cases);
	return 0;
}
