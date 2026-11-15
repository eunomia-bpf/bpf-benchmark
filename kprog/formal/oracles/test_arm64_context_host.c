/* Catch packet-pointer truncation, wrong context/field identity, partial-read
 * shifts, cb translation, extra memory operations and damaged state frames.
 * The supplied platform operations are fixture interpretations, not kernel
 * executions or proofs of the Clight/native-memory relation. */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c/Arm64Addressing.h"

static unsigned long cases;
static unsigned field_calls, bit_calls, copies;
static void *context_key;
static __u8 context_kind, observed_kind;
static __u32 observed_field;
static const void *observed_context, *observed_pointer, *copy_source;
static void *copy_destination;
static size_t copy_size, copy_alignment;
static __u64 pointer_values[3];
static void check(int ok, const char *what)
{
	if (!ok) { fprintf(stderr, "ARM context case %lu: %s\n", cases, what); exit(1); }
}
unsigned long native_lab_entry_input(unsigned kind)
{
	(void)kind; check(0, "unexpected coordinate/free input"); abort();
}
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{
	(void)site; fputs("unexpected exclusive choice in nonexclusive fixture\n", stderr); abort();
}
__u64 kprog_c_atomic_fetch(void *address, __u64 value, __u32 width, __u32 operation, __u32 order)
{
	(void)address; (void)value; (void)width; (void)operation; (void)order;
	fputs("unexpected atomic in nonatomic fixture\n", stderr); abort();
}
void arm64_sim_unsupported_opcode(void) { check(0, "unexpected opcode rejection"); abort(); }
void kprog_c_trap(void) { check(0, "unexpected platform trap"); abort(); }
void *kprog_c_context_pointer(const void *context, __u8 kind, __u32 offset)
{
	field_calls++; observed_context = context; observed_kind = kind; observed_field = offset;
	check(context == context_key && kind == context_kind, "platform context identity/kind");
	if (kind == KPROG_ABI_KIND_XDP) {
		if (offset == offsetof(struct xdp_md, data)) return (void *)(uintptr_t)pointer_values[0];
		if (offset == offsetof(struct xdp_md, data_end)) return (void *)(uintptr_t)pointer_values[1];
		if (offset == offsetof(struct xdp_md, data_meta)) return (void *)(uintptr_t)pointer_values[2];
	} else if (kind == KPROG_ABI_KIND_SKB) {
		if (offset == offsetof(struct __sk_buff, data)) return (void *)(uintptr_t)pointer_values[0];
		if (offset == offsetof(struct __sk_buff, data_end)) return (void *)(uintptr_t)pointer_values[1];
	}
	check(0, "unsupported platform field"); abort();
}
__u64 kprog_c_pointer_bits(const void *pointer)
{
	bit_calls++; observed_pointer = pointer;
	return (uintptr_t)pointer;
}
void __builtin_memcpy_aligned(void *destination, const void *source, size_t size, size_t alignment)
{
	copies++; copy_destination = destination; copy_source = source; copy_size = size; copy_alignment = alignment;
	memcpy(destination, source, size);
}
static __u64 little(const __u8 *bytes, unsigned length)
{
	__u64 result = 0;
	for (unsigned i = 0; i < length; i++) result |= (__u64)bytes[i] << (i * 8);
	return result;
}
static void reset_observations(void) { field_calls = bit_calls = copies = 0; }
static void no_context_access(void) { check(!field_calls && !bit_calls, "unselected context/scalar projection"); }

int main(void)
{
	__u8 bytes[1024], expected[sizeof(bytes)], tags[31] = {0}, original_tags[31];
	__u8 packed[8] = {0}; __u64 payload[8] = {0};
	union arm64_sim_gpr regs[31] = {0}, original_regs[31];
	struct kprog_arm64_coordinates coords = {0x123456789abcdef0ULL, 0xfedcba9876543210ULL, -80, 1, 1};
	struct kprog_arm64_coordinates original_coords = coords;
	struct kprog_arm64_addressing a = {&coords, regs, tags, bytes, packed, payload, sizeof(bytes), 96, bytes + 128, bytes + 512, 0, 0, (volatile __u64 *)bytes};
	struct kprog_arm64_addressing original_a = a;
	const __u64 values[] = {0, 1, ~0ULL, 0x8000000000000000ULL, 0x12345678ffffffffULL, 0xfedcba9876543210ULL};
	const unsigned widths[] = {1, 2, 4, 8};
	const int displacements[] = {-24, -1, 0, 1, 24};
	context_key = a.helper_context;
	for (unsigned kind = 0; kind < 2; kind++) for (unsigned vi = 0; vi < 6; vi++)
	for (unsigned wi = 0; wi < 4; wi++) for (unsigned di = 0; di < 5; di++)
	for (int logical = -16; logical <= 240; logical++) {
		unsigned width = widths[wi]; int displacement = displacements[di];
		context_kind = kind == 0 ? KPROG_ABI_KIND_XDP : KPROG_ABI_KIND_SKB;
		for (unsigned i = 0; i < 3; i++) pointer_values[i] = values[(vi + i) % 6];
		for (unsigned i = 0; i < sizeof(bytes); i++) bytes[i] = (__u8)(cases + i * 17);
		memcpy(expected, bytes, sizeof(bytes));
		__u8 *base = kind == 0 ? a.helper_context : a.helper_abi_base;
		regs[15].ptr = base + displacement; tags[15] = ARM64_SIM_TAG_ABI;
		a.is_xdp = kind == 0; a.abi_kind = context_kind; original_a = a;
		regs[10].x = cases % 4;
		__u64 index = cases % 3 == 0 ? 255 : 10;
		__s64 index_part = index == 255 ? 0 : (__s64)regs[10].x * 2;
		__u32 mode = cases % 4, aux = (mode << 24) | (1U << 16) | (ARM64_MOD_LSL << 8);
		memcpy(original_regs, regs, sizeof(regs)); memcpy(original_tags, tags, sizeof(tags));
		__s64 off = logical - displacement;
		__s64 extra = mode ? off - index_part : -3;
		__u64 imm = mode ? 0xfedcba9876543210ULL : (__u64)(off - index_part - extra);
		int field = -1, lane = 0, cb = 0;
		__u32 physical_field = 0;
		if (kind == 0 && logical >= 0 && logical < 24 && logical % 8 + width <= 8) {
			field = logical / 8; lane = logical % 8;
			physical_field = field == 0 ? offsetof(struct xdp_md, data) : field == 1 ? offsetof(struct xdp_md, data_end) : offsetof(struct xdp_md, data_meta);
		} else if (kind == 1) {
			if (logical >= 208 && logical + width <= 216) { field = 0; lane = logical - 208; physical_field = offsetof(struct __sk_buff, data); }
			else if (logical >= 80 && logical + width <= 88) { field = 1; lane = logical - 80; physical_field = offsetof(struct __sk_buff, data_end); }
			else if (logical >= 48 && logical + width <= 68) cb = 1;
		}
		const __u8 *read_address = cb ? (__u8 *)a.helper_context + offsetof(struct __sk_buff, cb) + logical - 48 : base + logical;
		__u64 wanted = field >= 0 ? pointer_values[field] : little(read_address, width);
		if (field >= 0 && width != 8) wanted = (wanted >> (lane * 8)) & ((1ULL << (width * 8)) - 1);
		for (unsigned composed = 0; composed < 2; composed++) {
			reset_observations();
			__u64 actual = composed ? kprog_arm64_memory_read(&a, 15, index, aux, imm, extra, width) : kind == 0 ? kprog_arm64_xdp_read(&a, 15, off, width) : kprog_arm64_skb_read(&a, 15, off, width);
			check(actual == wanted, "pointer high bits/partial lane/cb/raw value");
			if (field >= 0) {
				check(field_calls == 1 && observed_context == context_key && observed_kind == context_kind && observed_field == physical_field && !copies, "exact selected context operation");
				check(bit_calls == (width != 8), "full pointer retains identity; partial read projects once");
				if (width != 8) check(observed_pointer == (void *)(uintptr_t)pointer_values[field], "projection pointer identity");
		} else {
			no_context_access();
			check(copies == (unsigned)!cb, "cb byte ladder/raw complete-window selection");
			if (!cb) check(copy_source == read_address && copy_size == width && copy_alignment == 1, "raw read address/width/alignment");
		}
		check(!memcmp(bytes, expected, sizeof(bytes)), "read whole-memory frame");
		}

		if (kind == 1) {
			__u8 *write_address = cb ? (__u8 *)a.helper_context + offsetof(struct __sk_buff, cb) + logical - 48 : base + logical;
			for (unsigned i = 0; i < width; i++) expected[write_address - bytes + i] = (__u8)(values[vi] >> (i * 8));
			for (unsigned composed = 0; composed < 2; composed++) {
				reset_observations();
				if (composed) kprog_arm64_memory_write(&a, 15, index, aux, imm, extra, width, values[vi], (__u8)cases);
				else kprog_arm64_skb_write(&a, 15, off, width, values[vi]);
				no_context_access();
				check(copies == (unsigned)!cb, "cb byte ladder/raw store selection");
				if (!cb) check(copy_destination == write_address && copy_size == width && copy_alignment == 1, "raw store address/width/alignment");
				check(!memcmp(bytes, expected, sizeof(bytes)), "store low bits/whole-memory frame");
			}
		}
		check(!memcmp(regs, original_regs, sizeof(regs)) && !memcmp(tags, original_tags, sizeof(tags)), "register/tag frame");
		check(!memcmp(&coords, &original_coords, sizeof(coords)) && !memcmp(&a, &original_a, sizeof(a)), "coordinate/addressing frame");
		for (unsigned i = 0; i < sizeof(packed); i++) check(packed[i] == 0 && payload[i] == 0, "private metadata/payload frame");
		cases++;
	}
	/* The raw byte-ladder interface retains its threshold behavior for every
	 * width byte; context loads above use the four architectural widths. */
	for (unsigned width = 0; width < 256; width++) for (unsigned vi = 0; vi < 6; vi++)
	for (int off = -9; off < 24; off++) {
		unsigned length = width >= 8 ? 8 : width >= 4 ? 4 : width >= 2 ? 2 : 1;
		for (unsigned i = 0; i < sizeof(bytes); i++) bytes[i] = (__u8)(cases + i * 31);
		memcpy(expected, bytes, sizeof(bytes));
		reset_observations();
		check(kprog_arm64_cb_read(bytes + 512, off, width) == little(bytes + 512 + off, length), "cb ladder threshold/little endian");
		check(!memcmp(bytes, expected, sizeof(bytes)), "raw cb read frame");
		for (unsigned i = 0; i < length; i++) expected[512 + off + i] = (__u8)(values[vi] >> (i * 8));
		kprog_arm64_cb_write(bytes + 512, off, width, values[vi]); no_context_access();
		check(!copies && !memcmp(bytes, expected, sizeof(bytes)), "raw cb write byte ladder/whole frame");
		cases++;
	}
	printf("ARM context adapter: %lu pointer/partial/cb/raw/frame cases\n", cases);
	return 0;
}
