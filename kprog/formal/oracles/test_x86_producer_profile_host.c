/* Catch producer frame/fact-reference drift and lost stack provenance. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include KPROG_X86_PROGRAM_SOURCE

_Static_assert(X86_SIM_STACK_BYTES == PROFILE, "producer frame bound changed");
#define COUNT_FACT(I) +1
_Static_assert(0 X86_SIM_STACK_VALUE_WORDS(COUNT_FACT) == PROFILE/8,
               "producer scalar fact count changed");
#undef COUNT_FACT
static __u64 entropy, sp_base, values[256];
static unsigned kinds[256], count, sp_calls;
static void require(int ok)
{ if (!ok) { fputs("x86 producer profile mismatch\n", stderr); exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	require(count < 256 && (kind == NATIVE_LAB_INPUT_SP || kind == NATIVE_LAB_INPUT_UNSPECIFIED));
	__u64 value;
	if (kind == NATIVE_LAB_INPUT_SP) { ++sp_calls; value = sp_base; }
	else { entropy ^= entropy << 13; entropy ^= entropy >> 7; entropy ^= entropy << 17; value = entropy; }
	kinds[count] = kind; values[count++] = value; return value;
}
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p, __u8 kind, __u32 off)
{ (void)p; (void)kind; (void)off; abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p; abort(); }
__u64 kprog_c_atomic_fetch(void *p, __u64 v, __u32 width, __u32 op, __u32 order)
{ (void)p; (void)v; (void)width; (void)op; (void)order; abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t align)
{ require(align == 1); memcpy(dst, src, size); }

static void check_live_facts(void)
{
	X86_SIM_ENTRY_RAW(NULL);
	X86_SIM_BIND_INLINE();
	/* Compare every bound reference with its actual separately named local.
	 * The constructor must not inspect uninitialized private bytes. */
#define CHECK_FACT(I) \
	require(__x86_inline_bindings.values[I].tag == &X86_SIM_L_SV_TAG(I) && \
	        __x86_inline_bindings.values[I].pointer == &X86_SIM_L_SV_PTR(I) && \
	        X86_SIM_L_SV_TAG(I) == 0 && X86_SIM_L_SV_PTR(I) == NULL);
	X86_SIM_STACK_VALUE_WORDS(CHECK_FACT)
#undef CHECK_FACT
	__x86_rsp.ptr = (void *)(intptr_t)-PROFILE;
	for (unsigned i = 0; i < PROFILE/8; ++i) {
		unsigned offset = PROFILE-8-i*8;
		__x86_stack_mem.q[i] = sp_base + offset - PROFILE;
		*__x86_inline_bindings.values[i].tag = X86_SIM_TAG_STACK;
		*__x86_inline_bindings.values[i].pointer = (void *)&__x86_stack_mem.b[offset];
	}
	for (unsigned i = 0; i < PROFILE/8; ++i) {
		unsigned offset = PROFILE-8-i*8;
		__x86_rsi.ptr = (void *)&__x86_stack_mem.b[i*8];
		__x86_rsi_tag = X86_SIM_TAG_STACK;
		X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64,
		    X86_MEM_AUX(X86_REG_NONE,0), 0);
		require(__x86_rax_tag == X86_SIM_TAG_STACK &&
		        __x86_rax.ptr == (void *)&__x86_stack_mem.b[offset]);
	}
	x86_sim_inline_clear_values(&__x86_inline_bindings);
#define CHECK_CLEARED(I) require(X86_SIM_L_SV_TAG(I) == 0 && X86_SIM_L_SV_PTR(I) == NULL);
	X86_SIM_STACK_VALUE_WORDS(CHECK_CLEARED)
#undef CHECK_CLEARED
	for (unsigned i = 0; i < PROFILE/8; ++i)
		require(__x86_stack_mem.q[i] == sp_base - 8 - i*8);
}

int main(int argc, char **argv)
{
	int capture = argc == 2 && !strcmp(argv[1], "--capture");
	require(argc == 1 || capture);
	for (unsigned seed = 1; seed <= 32; ++seed) {
		entropy = seed; count = sp_calls = 0;
		sp_base = 0xfedcba9800011000ULL + ((__u64)seed << 8);
		__u64 expected = sp_base - PROFILE + 16;
		__u32 got = KPROG_X86_PROGRAM_ENTRY(NULL);
		require(got == (__u32)(expected ^ (expected >> 32)) &&
		        count == 24 + PROFILE/8 && sp_calls == 1);
		if (capture) {
			const __u32 header[] = {seed, got, count};
			require(fwrite(header, sizeof(header), 1, stdout) == 1 &&
			        fwrite(kinds, sizeof(*kinds), count, stdout) == count &&
			        fwrite(values, sizeof(*values), count, stdout) == count);
		}
		count = sp_calls = 0;
		check_live_facts();
		require(count == 24 && sp_calls == 1);
	}
	fprintf(stderr, "x86 producer profile %u: 32 high64 return/input cases and %u live fact reads\n",
	        PROFILE, 32U*(PROFILE/8));
	return 0;
}
