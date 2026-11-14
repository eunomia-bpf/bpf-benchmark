/* Detect wrong complete-consumer routing, suppressed offsets, lost cold input
 * order, typed/raw load width, relocation rejection and private-store frames. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "../c/Arm64Addressing.h"
static unsigned long cases;
static unsigned requests[32], wanted[32], count, wanted_count, copies;
static __u64 entropy, expected_entropy;
static const void *copy_source;
static void *copy_destination;
static size_t copy_size, copy_alignment;
static jmp_buf rejected;
static int allow_reject;
static void check(int ok, const char *what)
{
	if (!ok) { fprintf(stderr, "ARM memory adapter=%u case=%lu: %s\n", ADAPTER, cases, what); exit(1); }
}
static __u64 fresh(__u64 *s) { *s ^= *s << 13; *s ^= *s >> 7; *s ^= *s << 17; return *s; }
unsigned long native_lab_entry_input(unsigned kind)
{
	check(count < 32, "input overflow"); requests[count++] = kind;
	if (kind == 1) return 2;
	if (kind == 3) return 3;
	check(kind == 6, "unexpected input kind"); return fresh(&entropy);
}
void arm64_sim_unsupported_opcode(void)
{
	if (allow_reject) longjmp(rejected, 1);
	check(0, "unexpected rejection"); abort();
}
void kprog_c_trap(void) { check(0, "unexpected platform trap"); abort(); }
void *kprog_c_context_pointer(const void *ctx, __u8 kind, __u32 off)
{
	(void)ctx; (void)kind; (void)off; check(0, "unselected context operation"); abort();
}
__u64 kprog_c_pointer_bits(const void *p) { (void)p; check(0, "unselected projection"); abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t alignment)
{
	copies++; copy_source = src; copy_destination = dst; copy_size = size; copy_alignment = alignment;
	memcpy(dst, src, size);
}
static __u64 coordinate(struct kprog_arm64_coordinates *c, unsigned kind)
{
	__u64 *value = kind == 1 ? &c->sp_base : &c->return_base;
	__u8 *valid = kind == 1 ? &c->sp_valid : &c->return_valid;
	if (!*valid) { *value = kind == 1 ? 2 : 3; *valid = 1; wanted[wanted_count++] = kind; }
	return *value;
}
static __u64 free_value(void) { wanted[wanted_count++] = 6; return fresh(&expected_entropy); }
static __u64 mask(unsigned width) { return width == 8 ? ~0ULL : (1ULL << (width * 8)) - 1; }
static __u64 little(const __u8 *bytes, unsigned width)
{
	__u64 result = 0;
	for (unsigned i = 0; i < width; i++) result |= (__u64)bytes[i] << (i * 8);
	return result;
}
static void inputs_equal(struct kprog_arm64_coordinates *actual, struct kprog_arm64_coordinates *expected)
{
	check(actual->sp_base == expected->sp_base && actual->return_base == expected->return_base && actual->stack_offset == expected->stack_offset && actual->sp_valid == expected->sp_valid && actual->return_valid == expected->return_valid, "coordinate state/cache frame");
	check(count == wanted_count && !memcmp(requests, wanted, count * sizeof(*requests)) && entropy == expected_entropy, "exact input order/identity/laziness");
}
int main(void)
{
	static __u64 arena[48], before_arena[48], packed[6], before_packed[6], payload[48], expected_payload[48];
	static __u8 raw[512], expected_raw[512], tags[31], before_tags[31];
	static union arm64_sim_gpr regs[31], before_regs[31];
	static struct kprog_arm64_coordinates c, expected_c;
	static struct kprog_arm64_addressing a, before_a;
	const unsigned bases[] = {0, 15, 30, 32}, widths[] = {1, 2, 4, 8}, source_tags[] = {0, 4, 10, 255};
	for (unsigned bi = 0; bi < 4; bi++) for (unsigned tag = 0; tag < 256; tag++)
	for (unsigned wi = 0; wi < 4; wi++) for (unsigned mode = 0; mode < 4; mode++)
	for (unsigned profile = 0; profile < 3; profile++) {
		unsigned base = bases[bi], width = widths[wi], capacity = profile == 0 ? 160 : profile == 1 ? 200 : 376;
		__s64 bias = profile == 0 ? 96 : profile == 1 ? 160 : 0x100000100LL;
		unsigned stack = base == 32 || tag == 4, index = cases % 3 == 0 ? 255 : 5;
		unsigned index_tag = cases % 3 == 1 ? 4 : cases % 3 == 2 ? 10 : 0, shift = mode & 1;
		__s64 extra = (__s64)(cases % 9) - 4;
		__u64 imm = mode ? 0xfedcba9876543210ULL : (__u64)((__s64)(cases % 7) - 3);
		__u32 aux = (mode << 24) | (shift << 16) | (ARM64_MOD_LSL << 8);
		c = (struct kprog_arm64_coordinates){5, 7, -bias + 64, (__u8)((wi + mode) % 3), (__u8)((wi + mode + 1) % 3)};
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, capacity, bias, NULL, NULL, 0, 255, arena};
		before_a = a;
		for (unsigned i = 0; i < 31; i++) { regs[i].x = i; tags[i] = (__u8)(i * 7); }
		if (base < 31) { regs[base].ptr = stack ? (void *)(intptr_t)(-bias + 64) : raw + 200; tags[base] = tag; }
		regs[5].x = cases % 4; tags[5] = index_tag;
		for (unsigned i = 0; i < sizeof(arena); i++) ((__u8 *)arena)[i] = (__u8)(cases + i * 17);
		for (unsigned i = 0; i < sizeof(raw); i++) raw[i] = (__u8)(cases + i * 31);
		for (unsigned i = 0; i < sizeof(packed); i++) ((__u8 *)packed)[i] = (__u8)(cases + i * 13);
		for (unsigned i = 0; i < 48; i++) payload[i] = 0x123456789abcdef0ULL ^ i;
		memcpy(before_arena, arena, sizeof(arena)); memcpy(expected_raw, raw, sizeof(raw)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload)); memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		/* Observations are per operation; cache/entropy persist. */
		count = wanted_count = copies = 0; entropy = expected_entropy = cases + 0x9e3779b97f4a7c15ULL; expected_c = c;
		__u64 index_value = index == 255 ? 0 : regs[5].x + (index_tag == 4 ? coordinate(&expected_c, 1) : index_tag == 10 ? coordinate(&expected_c, 3) : 0);
		__s64 off = (__s64)((mode ? 0 : imm) + (index_value << shift)) + extra;
		__u64 expected_value = 0;
		unsigned at = 64 + off;
		int rejects = !stack && tag == 7 && width == 8 && off != 0;
		if (stack) expected_value = off < 0 ? free_value() & mask(width) : little((__u8 *)arena + at, width);
		else if (tag == 7 && width == 8) expected_value = (uintptr_t)regs[base].ptr;
		else expected_value = little(raw + 200 + off, width);
		allow_reject = rejects;
		if (setjmp(rejected) == 0) {
			check(kprog_arm64_memory_read(&a, base, index, aux, imm, extra, width) == expected_value, "whole read value/width/routing");
			check(!rejects, "missing relocation-offset rejection");
		}
		allow_reject = 0;
		inputs_equal(&c, &expected_c);
		check(copies == (unsigned)(ADAPTER && !stack && !(tag == 7 && width == 8)), "read access count/source selection");
		if (copies) check(copy_source == raw + 200 + off && copy_size == width && copy_alignment == 1, "raw/typed read address/complete window");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "read whole-memory frame");
		count = wanted_count = copies = 0;
		__u64 value = 0xfedcba9876543210ULL ^ (cases * 0x123456789ULL);
		unsigned source_tag = source_tags[(tag + wi + mode) % 4];
		if (stack) {
			for (unsigned i = 0; i < width; i++) ((__u8 *)before_arena)[at + i] = (__u8)(value >> (i * 8));
			if (width == 8 && !(at & 7)) {
				if (source_tag == 4 || source_tag == 10) expected_payload[at / 8] = value - coordinate(&expected_c, source_tag == 4 ? 1 : 3);
				((__u8 *)before_packed)[at / 8] = source_tag;
			} else { ((__u8 *)before_packed)[at / 8] = 0; ((__u8 *)before_packed)[(at + width - 1) / 8] = 0; }
			for (unsigned i = 0; i < width && off + i < 0; i++) { ((__u8 *)before_arena)[at + i] = (__u8)free_value(); ((__u8 *)before_packed)[(at + i) / 8] = 0; }
		} else for (unsigned i = 0; i < width; i++) expected_raw[200 + off + i] = (__u8)(value >> (i * 8));
		kprog_arm64_memory_write(&a, base, index, aux, imm, extra, width, value, source_tag);
		inputs_equal(&c, &expected_c);
		check(copies == (unsigned)(ADAPTER && !stack), "store access count/source selection");
		if (copies) check(copy_destination == raw + 200 + off && copy_size == width && copy_alignment == 1, "raw store address/complete window");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "store complete byte/tag/payload frame");
		check(!memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)), "GPR/tag frame");
		check(!memcmp(&a, &before_a, sizeof(a)), "addressing storage/profile frame");
		cases++;
	}
	printf("ARM complete memory adapter %u: %lu routing/cache/input/frame/rejection cases\n", ADAPTER, cases);
	return 0;
}
