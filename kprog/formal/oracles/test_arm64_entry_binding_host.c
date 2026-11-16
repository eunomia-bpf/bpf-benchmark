/* Catch entry cell/ABI misbinding, eager inputs, pointer truncation and
 * storage/view aliases. Never read private bytes or payload before writing.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "../c/Arm64Entry.h"

static __u64 state, draws[98];
static unsigned draw_count, cases, calls, cast_calls, field_calls, refuse;
static __u8 kind;
static void *context, *cast_result;
static unsigned char packet[32], kernel_context[256];
static struct xdp_md xdp;
static struct __sk_buff skb;
static jmp_buf rejected;

static void check(int ok, const char *what)
{
	if (!ok) { fprintf(stderr, "ARM entry case %u: %s\n", cases, what); exit(1); }
}
unsigned long native_lab_entry_input(unsigned int input)
{
	check(input == NATIVE_LAB_INPUT_UNSPECIFIED && draw_count < 98, "input kind/count");
	state ^= state << 13; state ^= state >> 7; state ^= state << 17;
	draws[draw_count++] = state;
	return state;
}
void arm64_sim_unsupported_opcode(void) { abort(); }
void *kprog_c_context_pointer(const void *ctx, __u8 abi, __u32 off)
{
	check(ctx == &xdp && abi == KPROG_ABI_KIND_XDP, "context import identity/kind");
	check(draw_count == 0 && field_calls < 2, "fields precede state inputs");
	check(off == (field_calls ? __builtin_offsetof(struct xdp_md, data_end) :
	                          __builtin_offsetof(struct xdp_md, data)), "field order/offset");
	if (++field_calls == refuse) longjmp(rejected, 1);
	return packet + (field_calls == 1 ? 0 : sizeof(packet));
}
static void *cast_context(void *ctx)
{
	check(ctx == context && draw_count == 98 && cast_calls++ == 0, "cast after state inputs");
	if (refuse) longjmp(rejected, 1);
	return cast_result;
}
static __u32 continuation(struct kprog_arm64_entry *e)
{
	check(calls++ == 0 && draw_count == 98, "single continuation after all draws");
	check(*e->abi_kind == kind && *e->is_xdp == (kind == KPROG_ABI_KIND_XDP), "entry kind");
	check(*e->helper_context == context, "helper context identity");
	check(e->cells[0]->ptr == (kind == KPROG_ABI_KIND_SKB ? cast_result : context), "x0 live pointer");
	check(*e->skb_context == (kind == KPROG_ABI_KIND_SKB ? context : NULL), "skb context");
	check(*e->helper_abi_base == (kind == KPROG_ABI_KIND_XDP ? e->abi :
	                            kind == KPROG_ABI_KIND_SKB ? cast_result : context), "helper ABI identity");
	for (unsigned i = 0; i < 31; ++i) {
		check(*e->tag_cells[i] == (i == 0 ? ARM64_SIM_TAG_ABI :
		                         i == 30 ? ARM64_SIM_TAG_RETURN : ARM64_SIM_TAG_SCALAR), "register tag");
		if (i) check(e->cells[i]->x == (i == 30 ? 0 : draws[i]), "register draw/order");
		for (unsigned j = 0; j < i; ++j)
			check(e->cells[i] != e->cells[j] && e->tag_cells[i] != e->tag_cells[j], "distinct register cells");
	}
	check(!*e->sp_base && !*e->return_base && !*e->sp && !*e->lr &&
	      !*e->sp_valid && !*e->return_valid, "initial coordinates");
	*e->sp_base = 17; *e->return_base = 29; *e->sp = -8; *e->lr = 37;
	*e->sp_valid = 1;
	check(*e->sp_base == 17 && *e->return_base == 29 && *e->sp == -8 &&
	      *e->lr == 37 && !*e->return_valid, "coordinate reference aliases");
	check(*e->n == (draws[30] & 1) && *e->z == (draws[31] & 1) &&
	      *e->c == (draws[32] & 1) && *e->v == (draws[33] & 1), "flag input order");
	*e->n = 1; *e->z = 2; *e->c = 3; *e->v = 4;
	check(*e->n == 1 && *e->z == 2 && *e->c == 3 && *e->v == 4, "independent flag references");
	for (unsigned i = 0; i < 32; ++i) {
		check(*e->vector_lo[i] == draws[34 + 2*i] &&
		      *e->vector_hi[i] == draws[35 + 2*i], "vector lane binding/order");
		*e->vector_lo[i] = i; *e->vector_hi[i] = 64 + i;
	}
	for (unsigned i = 0; i < 32; ++i)
		check(*e->vector_lo[i] == i && *e->vector_hi[i] == 64+i, "independent vector lanes");
	check(e->capacity == ARM64_SIM_STACK_BYTES && e->bias == ARM64_SIM_STACK_BIAS &&
	      e->payload_words == KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES) &&
	      e->tag_bytes == ARM64_SIM_TAG_STORAGE_BYTES(ARM64_SIM_STACK_BYTES), "storage profile");
	for (unsigned i = 0; i < e->tag_bytes; ++i) check(e->stack_tags[i] == 0, "initialized stack tags");
	/* Write before read, including the partial final q word's allocated padding. */
	e->words[0] = 0x8877665544332211ULL;
	check(e->bytes[0] == 0x11 && (e->capacity < 8 || e->bytes[7] == 0x88), "shared byte/word arena");
	for (unsigned i = 0; i < e->payload_words; ++i) e->payload[i] = i + 100;
	for (unsigned i = 0; i < e->payload_words; ++i) check(e->payload[i] == i+100, "live payload");
	check(e->words[0] == 0x8877665544332211ULL, "payload does not alias byte arena");
	if (kind == KPROG_ABI_KIND_XDP) {
		struct arm64_sim_xdp_abi *abi = e->abi;
		for (unsigned i = 0; i < 5; ++i) check(abi->cb[i] == 0, "initialized XDP cb");
#if ADAPTER
		check(abi->data == packet && abi->data_end == packet+sizeof(packet), "full-pointer XDP initializer");
		check(field_calls == 2, "exactly two context imports");
#else
		check(abi->data == (void *)(uintptr_t)xdp.data &&
		      abi->data_end == (void *)(uintptr_t)xdp.data_end, "native UAPI field initializer");
#endif
	} else {
		const unsigned char *abi = e->abi;
		for (unsigned i = 0; i < sizeof(struct arm64_sim_skb_abi); ++i)
			check(abi[i] == 0, "zero-initialized non-XDP ABI");
	}
	void *base = *e->helper_abi_base;
	*e->helper_context = packet;
	check(*e->helper_abi_base == base, "independent helper-context references");
	return 0xfedc0000U + cases;
}
int main(void)
{
	for (unsigned seed = 1; seed <= 64; ++seed) {
		for (unsigned mode = 0; mode < 7; ++mode) {
			state = seed; draw_count = calls = cast_calls = field_calls = refuse = 0;
			kind = mode < 2 ? ARM64_SIM_ABI_KIND_RAW : mode < 5 ? KPROG_ABI_KIND_XDP : KPROG_ABI_KIND_SKB;
			context = mode == 0 ? NULL : kind == ARM64_SIM_ABI_KIND_RAW ? kernel_context :
			          kind == KPROG_ABI_KIND_XDP ? (void *)&xdp : (void *)&skb;
			xdp.data = mode == 2 ? 0 : mode == 3 ? 0xffffffffU : 0x12345678U;
			xdp.data_end = xdp.data ^ 0x87654321U;
			cast_result = mode == 5 ? context : kernel_context;
			__u32 result = kind == ARM64_SIM_ABI_KIND_RAW ? kprog_arm64_entry_raw(context, continuation) :
			               kind == KPROG_ABI_KIND_XDP ? kprog_arm64_entry_xdp(context, continuation) :
			               kprog_arm64_entry_skb(context, cast_context, continuation);
			check(result == 0xfedc0000U + cases && calls == 1 &&
			      cast_calls == (kind == KPROG_ABI_KIND_SKB), "continuation result/cast count");
			++cases;
		}
	}
	/* Refusal leaves no continuation call. Keep jump state in static storage. */
	draw_count = calls = cast_calls = 0; refuse = 1; context = &skb;
	if (!setjmp(rejected)) { kprog_arm64_entry_skb(context, cast_context, continuation); abort(); }
	check(draw_count == 98 && cast_calls == 1 && calls == 0, "cast refusal prefix");
#if ADAPTER
	for (refuse = 1; refuse <= 2; ++refuse) {
		draw_count = calls = field_calls = 0;
		if (!setjmp(rejected)) { kprog_arm64_entry_xdp(&xdp, continuation); abort(); }
		check(draw_count == 0 && calls == 0 && field_calls == refuse, "field refusal prefix");
	}
#endif
	printf("ARM entry: %u initialized live-view continuations; cast/context refusal prefixes pass\n", cases);
	return 0;
}
