/* Detect lost producer rank mappings, upper payload bits and extra inputs. */
#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../build/arm64_payload_profile.bpf.c"

_Static_assert(ARM64_SIM_STACK_BYTES == 32 && ARM64_SIM_STACK_BIAS == 32 &&
               ARM64_SIM_STACK_PAYLOAD_WORDS == 3, "fixture lost its sparse producer layout");
static __u64 entropy, sp_base, return_base, values[512];
static unsigned events[512], count, sp_calls, return_calls;
static void require(int ok)
{ if (!ok) { fputs("ARM producer payload profile mismatch\n", stderr); exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	require(count < 512 && (kind == 1 || kind == 3 || kind == 6));
	__u64 value;
	if (kind == 1) { ++sp_calls; value = sp_base; }
	else if (kind == 3) { ++return_calls; value = return_base; }
	else { entropy ^= entropy << 13; entropy ^= entropy >> 7; entropy ^= entropy << 17; value = entropy; }
	events[count] = kind; values[count++] = value; return value;
}
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{ (void)site; abort(); }
void arm64_sim_unsupported_opcode(void) { abort(); }
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p, __u8 kind, __u32 off)
{ (void)p; (void)kind; (void)off; abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p; abort(); }
__u64 kprog_c_atomic_fetch(void *p, __u64 v, __u32 width, __u32 op, __u32 order)
{ (void)p; (void)v; (void)width; (void)op; (void)order; abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t align)
{ require(align == 1); memcpy(dst, src, size); }
int main(int argc, char **argv)
{
	int capture = argc == 2 && !strcmp(argv[1], "--capture");
	require(argc == 1 || capture);
	for (unsigned seed = 1; seed <= 16; ++seed) {
		entropy = seed; count = sp_calls = return_calls = 0;
		sp_base = 0xfedcba9800011000ULL + ((__u64)seed << 8);
		return_base = 0x1234567800022000ULL + seed * 0x101;
		__u64 expected = (sp_base - 16) ^ return_base;
		__u32 got = arm64_payload_profile_arm64_sim_xdp(NULL);
		require(got == (__u32)(expected ^ (expected >> 32)) &&
		        count == 304 && sp_calls == 1 && return_calls == 1);
		if (capture) {
			const __u32 header[] = {seed, got, count};
			require(fwrite(header, sizeof(header), 1, stdout) == 1 &&
			        fwrite(events, sizeof(*events), count, stdout) == count &&
			        fwrite(values, sizeof(*values), count, stdout) == count);
		}
	}
	fputs("ARM producer sparse profile: 16 high64 payload/return/input cases\n", stderr);
	return 0;
}
