/* Detect wrong complete-consumer routing, suppressed offsets, lost cold input
 * order, typed/raw load width, relocation rejection and private-store frames. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "../c/Arm64Addressing.h"
static unsigned long cases;
static unsigned requests[512], wanted[512], count, wanted_count, copies;
static __u64 entropy, expected_entropy;
static const void *copy_source;
static void *copy_destination;
static size_t copy_size, copy_alignment;
static const void *copy_sources[4];
static void *copy_destinations[4];
static size_t copy_sizes[4];
static unsigned copy_reject_at;
static jmp_buf rejected;
static int allow_reject, force_draw;
static __u64 draw_value;
static void check(int ok, const char *what)
{
	if (!ok) { fprintf(stderr, "ARM memory adapter=%u case=%lu: %s\n", ADAPTER, cases, what); exit(1); }
}
static __u64 fresh(__u64 *s) { *s ^= *s << 13; *s ^= *s >> 7; *s ^= *s << 17; return *s; }
unsigned long native_lab_entry_input(unsigned kind)
{
	check(count < 512, "input overflow"); requests[count++] = kind;
	if (kind == 1) return 2;
	if (kind == 3) return 3;
	check(kind == 6, "unexpected input kind"); return force_draw ? draw_value : fresh(&entropy);
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
	check(copies < 4, "too many memory operations");
	copy_sources[copies] = src; copy_destinations[copies] = dst; copy_sizes[copies] = size;
	copies++; copy_source = src; copy_destination = dst; copy_size = size; copy_alignment = alignment;
	if (copy_reject_at && copies == copy_reject_at) { check(allow_reject, "unexpected copy rejection"); longjmp(rejected, 2); }
	memcpy(dst, src, size);
}
static __u64 coordinate(struct kprog_arm64_coordinates *c, unsigned kind)
{
	__u64 *value = kind == 1 ? &c->sp_base : &c->return_base;
	__u8 *valid = kind == 1 ? &c->sp_valid : &c->return_valid;
	if (!*valid) { *value = kind == 1 ? 2 : 3; *valid = 1; wanted[wanted_count++] = kind; }
	return *value;
}
static __u64 free_value(void) { wanted[wanted_count++] = 6; return force_draw ? draw_value : fresh(&expected_entropy); }
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
/* Independent register effects used by the two-destination tests. */
static void expected_write(struct kprog_arm64_coordinates *c, union arm64_sim_gpr *r,
                           __u8 *t, __u8 *bytes, __u8 *packed, unsigned capacity,
                           __s64 bias, __u64 dst, __u64 value, unsigned width,
                           unsigned tag, int preserve)
{
	if (!preserve) value &= mask(width);
	if (dst < 31) { r[dst].x = value; t[dst] = preserve ? tag : 0; }
	else if (dst == 32) {
		__s64 old = c->stack_offset;
		if (preserve && tag == 4) c->stack_offset = (__s64)value;
		else {
			if (preserve && tag == 10) value += coordinate(c, 3);
			c->stack_offset = (__s64)(value - coordinate(c, 1));
		}
		if (c->stack_offset > old) {
			for (unsigned i = 0; i < capacity; i++) if ((__s64)i - bias >= old && (__s64)i - bias < c->stack_offset) bytes[i] = (__u8)free_value();
			for (unsigned i = 0; i < (capacity + 7) / 8; i++) if ((__s64)(i * 8) - bias < c->stack_offset && (__s64)(i * 8 + 8) - bias > old) packed[i] = 0;
		}
	}
}
static void expected_stack_store(struct kprog_arm64_coordinates *c, __u8 *bytes,
                                 __u8 *packed, __u64 *payload, __s64 bias,
                                 __s64 off, unsigned width, __u64 value, unsigned tag)
{
	unsigned at = (unsigned)(off + bias);
	value &= mask(width);
	for (unsigned i = 0; i < width; i++) bytes[at + i] = (__u8)(value >> (i * 8));
	if (width == 8 && !(at & 7)) {
		if (tag == 4 || tag == 10) payload[at / 8] = value - coordinate(c, tag == 4 ? 1 : 3);
		packed[at / 8] = tag;
	} else { packed[at / 8] = 0; packed[(at + width - 1) / 8] = 0; }
	for (unsigned i = 0; i < width && off + i < c->stack_offset; i++) { bytes[at + i] = (__u8)free_value(); packed[(at + i) / 8] = 0; }
}
/* The native instruction front must retain an after-include caller hook. */
static unsigned override_visits;
#undef ARM64_SIM_L_READ_FAULT
#define ARM64_SIM_L_READ_FAULT(BASE, INDEX, AUX, IMM) (++override_visits, 73)
static void check_native_hook(void)
{
	int result;
	ARM64_SIM_L_READ_FAULT_CALL_INTO(result, 255, 255, 0, 0);
	check(result == 73 && override_visits == 1, "native fault-hook override");
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
	const __u64 fault_bases[] = {0, 15, 30, 31, 32, 33, 255, 0x100000020ULL, ~0ULL};
	const __u64 values[] = {0, 4095, 4096, ~0ULL, 0x12345678ffffffffULL, 0x8000000000000000ULL};
	const __u64 draws[] = {0, 1, 0x8000000000000000ULL, ~0ULL};
	unsigned long start = cases;
	force_draw = 1;
	for (unsigned bi = 0; bi < 9; bi++) for (unsigned tag = 0; tag < 256; tag++)
	for (unsigned vi = 0; vi < 6; vi++) for (unsigned mode = 0; mode < 4; mode++)
	for (unsigned di = 0; di < 4; di++) {
		__u64 base = fault_bases[bi], index = mode & 2 ? 10 : 255, imm = values[(vi + 2) % 6];
		unsigned index_tag = vi % 3 == 0 ? 0 : vi % 3 == 1 ? 4 : 10;
		__u32 aux = (mode << 24) | ((mode & 1) << 16) | (ARM64_MOD_LSL << 8);
		c = (struct kprog_arm64_coordinates){5, 7, -80, (__u8)(mode & 1), (__u8)(mode & 2)};
		if (base < 31) { regs[base].x = values[vi]; tags[base] = tag; }
		regs[10].x = values[(vi + 1) % 6]; tags[10] = index_tag;
		a.is_xdp = vi % 3 == 0 ? 0 : vi % 3 == 1 ? 1 : 255;
		a.abi_kind = (tag + mode) % 4 == 3 ? 255 : (tag + mode) % 4; before_a = a;
		memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		count = wanted_count = copies = 0; expected_c = c; expected_entropy = entropy; draw_value = draws[di];
		unsigned effective_tag = base == 32 ? 4 : base < 31 ? tag : 0;
		int expected_fault = 0;
		if (base != 32 && effective_tag != 4 && effective_tag != 7 && !((a.is_xdp || a.abi_kind == 1) && effective_tag == 1)) {
			if (effective_tag == 0) {
				__u64 index_value = index == 255 ? 0 : regs[10].x + (index_tag == 4 ? coordinate(&expected_c, 1) : index_tag == 10 ? coordinate(&expected_c, 3) : 0);
				__u64 offset = (mode ? 0 : imm) + (index_value << (mode & 1));
				expected_fault = ((base < 31 ? regs[base].x : 0) + offset + (mode & 1 ? imm : 0)) < 4096;
			}
			if (!expected_fault) { wanted[wanted_count++] = 6; expected_fault = draw_value != 0; }
		}
		check(kprog_arm64_read_fault(&a, base, index, aux, imm) == expected_fault, "fault domain/low page/pre delta/nonzero normalization");
		inputs_equal(&c, &expected_c);
		check(!copies && !memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)), "fault query GPR/profile/access frame");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "fault query complete-memory frame");
		cases++;
	}
	printf("ARM fault predicate adapter %u: %lu lazy/domain/address/input/frame cases\n", ADAPTER, cases - start);
	start = cases;
	const unsigned ops[] = {ARM64_OP_LOAD, ARM64_OP_LDRSB, ARM64_OP_LDRSH, ARM64_OP_LDRSW, ARM64_OP_STORE};
	const unsigned destinations[] = {0, 15, 30, 31, 32, 255}, flags[] = {0, 1, 2, 4, 8};
	for (unsigned oi = 0; oi < 5; oi++) for (unsigned ri = 0; ri < 6; ri++)
	for (unsigned fi = 0; fi < 5; fi++) for (unsigned mode = 0; mode < 4; mode++)
	for (unsigned di = 0; di < 2; di++) {
		unsigned data = destinations[ri], width = flags[fi] ? flags[fi] : 8, op = ops[oi], store = op == ARM64_OP_STORE;
		__u32 aux = mode << 24;
		c = (struct kprog_arm64_coordinates){5, 7, -80, (__u8)(mode & 1), 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		for (unsigned i = 0; i < 31; i++) { regs[i].x = 0xfedcba9876543210ULL ^ i; tags[i] = 0; }
		regs[15].ptr = raw + 200; tags[15] = 6;
		for (unsigned i = 0; i < sizeof(raw); i++) raw[i] = (__u8)(cases + i * 31);
		memcpy(expected_raw, raw, sizeof(raw)); memcpy(before_arena, arena, sizeof(arena)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload)); memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		count = wanted_count = copies = 0; expected_entropy = entropy; draw_value = di;
		int fault = !store && di, rejects = data == 15 && mode && !fault;
		if (!store) wanted[wanted_count++] = 6;
		if (!rejects) {
			if (mode & 1 && !fault) before_regs[15].ptr = raw + 208;
			if (store) {
				__u64 value = data == 32 ? (__u64)c.stack_offset + coordinate(&expected_c, 1) : data < 31 ? before_regs[data].x : 0;
				for (unsigned i = 0; i < width; i++) expected_raw[(mode == 2 ? 200 : 208) + i] = (__u8)(value >> (i * 8));
			} else {
				unsigned load_width = op == ARM64_OP_LOAD ? width : op == ARM64_OP_LDRSB ? 1 : op == ARM64_OP_LDRSH ? 2 : 4;
				__u64 value = fault ? 0 : little(raw + (mode == 2 ? 200 : 208), load_width);
				if (op != ARM64_OP_LOAD && (value & (1ULL << (load_width * 8 - 1)))) value |= ~mask(load_width);
				value &= mask(fault ? 8 : width);
				if (data < 31) { before_regs[data].x = value; before_tags[data] = 0; }
				else if (data == 32) {
					__s64 old = expected_c.stack_offset;
					expected_c.stack_offset = (__s64)(value - coordinate(&expected_c, 1));
					if (expected_c.stack_offset > old) {
						for (unsigned i = 0; i < a.capacity; i++) if ((__s64)i - a.bias >= old && (__s64)i - a.bias < expected_c.stack_offset) { ((__u8 *)before_arena)[i] = (__u8)draw_value; wanted[wanted_count++] = 6; }
						for (unsigned i = 0; i < (a.capacity + 7) / 8; i++) if ((__s64)(i * 8) - a.bias < expected_c.stack_offset && (__s64)(i * 8 + 8) - a.bias > old) ((__u8 *)before_packed)[i] = 0;
					}
				}
			}
			if (mode & 2 && !fault) before_regs[15].ptr = raw + (mode == 3 ? 216 : 208);
		}
		allow_reject = rejects;
		if (setjmp(rejected) == 0) {
			if (store) kprog_arm64_store(&a, 15, data, 255, aux, 8, flags[fi]);
			else if (op == ARM64_OP_LOAD) kprog_arm64_load(&a, data, 15, 255, aux, 8, flags[fi]);
			else kprog_arm64_signed_load(&a, op, data, 15, 255, aux, 8, flags[fi]);
			check(!rejects, "missing scalar writeback-overlap rejection");
		}
		allow_reject = 0;
		inputs_equal(&c, &expected_c);
		check(copies == (unsigned)(ADAPTER && !fault && !rejects), "fault/overlap precedes transfer");
		check(!memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)), "scalar instruction register/tag/writeback/profile frame");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "scalar instruction complete-memory frame");
		cases++;
	}
	printf("ARM scalar memory adapter %u: %lu transfer/recovery/writeback/frame cases\n", ADAPTER, cases - start);
	start = cases;
	const unsigned targets[] = {0, 15, 30, 31, 255};
	for (unsigned tag = 0; tag < 256; tag++) for (unsigned ti = 0; ti < 5; ti++) {
		unsigned dst = targets[ti];
		c = (struct kprog_arm64_coordinates){0xfedcba9876543210ULL, 0x123456789abcdef0ULL, -80, 0, 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		arena[2] = values[tag % 6]; payload[2] = values[(tag + 1) % 6]; ((__u8 *)packed)[2] = tag;
		memcpy(before_arena, arena, sizeof(arena)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload));
		memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		if (dst < 31) { before_regs[dst].x = tag == 4 || tag == 10 ? payload[2] : arena[2]; before_tags[dst] = tag; }
		count = wanted_count = copies = 0; expected_entropy = entropy;
		kprog_arm64_load(&a, dst, 32, 255, 0, 0, 8);
		inputs_equal(&c, &expected_c);
		check(!copies && !memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)), "whole pointer/tag/relative payload writeback");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "whole pointer load memory frame");
		cases++;
	}
	printf("ARM load provenance adapter %u: %lu tag/payload/ignored-destination cases\n", ADAPTER, cases - start);
	start = cases;
	const unsigned operand_tags[] = {0, 4, 10};
	for (unsigned si = 0; si < 3; si++) for (unsigned ii = 0; ii < 3; ii++) for (unsigned mode = 0; mode < 4; mode++) {
		c = (struct kprog_arm64_coordinates){5, 7, -80, 0, 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		regs[15].ptr = raw + 200; tags[15] = 6; regs[0].x = 0xfedcba9876543210ULL; tags[0] = operand_tags[si]; regs[10].x = 1; tags[10] = operand_tags[ii];
		memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags)); memcpy(expected_raw, raw, sizeof(raw));
		count = wanted_count = copies = 0; expected_entropy = entropy;
		__u64 offset = regs[10].x + (tags[10] == 4 ? coordinate(&expected_c, 1) : tags[10] == 10 ? coordinate(&expected_c, 3) : 0);
		__u64 value = regs[0].x + (tags[0] == 4 ? coordinate(&expected_c, 1) : tags[0] == 10 ? coordinate(&expected_c, 3) : 0);
		unsigned address = (mode == 2 ? 200 : 208) + offset;
		for (unsigned i = 0; i < 8; i++) expected_raw[address + i] = (__u8)(value >> (i * 8));
		if (mode) before_regs[15].ptr = raw + (mode == 3 ? 216 : 208);
		kprog_arm64_store(&a, 15, 0, 10, mode << 24, 8, 8);
		inputs_equal(&c, &expected_c);
		check(copies == ADAPTER && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)), "indexed store address/value/input ordering/frame");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "indexed store private-memory frame");
		cases++;
	}
	printf("ARM indexed store adapter %u: %lu source/index cold-input order cases\n", ADAPTER, cases - start);
	start = cases;
	static __u64 vectors[64], expected_vectors[64];
	const unsigned transfers[] = {ARM64_OP_LDP, ARM64_OP_STP, ARM64_OP_LOAD_D0, ARM64_OP_LOAD_Q0, ARM64_OP_STORE_D0, ARM64_OP_STORE_Q0};
	const __u64 fields[][2] = {{0,1},{15,0},{0,15},{30,31},{31,30},{32,0},{0,32},{255,1},{1,255},{1,1},{32,32},{0x100000020ULL,1}};
	for (unsigned oi = 0; oi < 6; oi++) for (unsigned ri = 0; ri < (oi < 2 ? 12 : 1); ri++)
	for (unsigned fi = 0; fi < (oi < 2 ? 5 : 1); fi++) for (unsigned mode = 0; mode < 4; mode++)
	for (unsigned di = 0; di < 4; di++) {
		unsigned pair = oi < 2, load = oi == 0 || oi == 2 || oi == 3;
		unsigned width = pair && flags[fi] ? flags[fi] : 8, lanes = oi == 2 || oi == 4 ? 1 : 2;
		__u64 first = fields[ri][0], second = fields[ri][1];
		int rejects = pair && ((load && first == second) || (mode && (first == 15 || second == 15)));
		int fault = load && di && !rejects;
		c = (struct kprog_arm64_coordinates){5, 7, -80, 0, 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		for (unsigned i = 0; i < 31; i++) { regs[i].x = 0xfedcba9876543210ULL ^ i; tags[i] = i == 0 ? 10 : i == 1 ? 4 : 0; }
		regs[15].ptr = raw + 200; tags[15] = 6;
		for (unsigned i = 0; i < sizeof(raw); i++) raw[i] = (__u8)(cases + i * 31);
		for (unsigned i = 0; i < 64; i++) vectors[i] = 0x123456789abcdef0ULL ^ ((__u64)i * 0x11223344556677ULL);
		memcpy(expected_vectors, vectors, sizeof(vectors)); memcpy(expected_raw, raw, sizeof(raw)); memcpy(before_arena, arena, sizeof(arena)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload)); memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		count = wanted_count = copies = 0; expected_entropy = entropy; draw_value = draws[di];
		if (load && !rejects) wanted[wanted_count++] = 6;
		if (!rejects) {
			if (!fault && mode & 1) before_regs[15].ptr = raw + 208;
			if (fault && pair) {
				expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, first, 0, 8, 0, 0);
				expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, second, 0, 8, 0, 0);
			} else if (!fault) {
				unsigned address = mode == 2 ? 200 : 208;
				__u64 loaded[2] = {little(raw + address, width), lanes > 1 ? little(raw + address + width, width) : 0};
				if (pair && load) {
					expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, first, loaded[0], width, 0, 0);
					expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, second, loaded[1], width, 0, 0);
				} else if (load) { expected_vectors[0] = loaded[0]; expected_vectors[1] = lanes > 1 ? loaded[1] : 0; }
				else for (unsigned slot = 0; slot < lanes; slot++) {
					__u64 reg = slot ? second : first, value = pair ? reg == 32 ? (__u64)expected_c.stack_offset + coordinate(&expected_c, 1) : reg < 31 ? before_regs[reg].x + (before_tags[reg] == 4 ? coordinate(&expected_c, 1) : before_tags[reg] == 10 ? coordinate(&expected_c, 3) : 0) : 0 : vectors[slot];
					for (unsigned i = 0; i < width; i++) expected_raw[address + slot * width + i] = (__u8)(value >> (i * 8));
				}
				if (mode & 2) before_regs[15].ptr = raw + (mode == 3 ? 216 : 208);
			}
		}
		allow_reject = rejects;
		if (setjmp(rejected) == 0) {
			if (pair) kprog_arm64_pair_step(&a, transfers[oi], load ? first : 255, load ? second : first, load ? 255 : second, 15, 255, mode << 24, 8, flags[fi]);
			else kprog_arm64_vector_step(&a, &vectors[0], &vectors[1], transfers[oi], 15, 255, mode << 24, 8);
			check(!rejects, "missing pair duplicate/overlap rejection");
		}
		allow_reject = 0; inputs_equal(&c, &expected_c);
		check(copies == (unsigned)(ADAPTER && !fault && !rejects ? lanes : 0), "pair/vector fault/rejection/slot access count");
		for (unsigned slot = 0; slot < copies; slot++) check(copy_sizes[slot] == width && (load ? copy_sources[slot] : copy_destinations[slot]) == raw + (mode == 2 ? 200 : 208) + slot * width && copy_alignment == 1, "pair/vector ordered complete memory windows");
		check(!memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)) && !memcmp(vectors, expected_vectors, sizeof(vectors)), "pair/vector GPR/tag/SIMD/profile/writeback frame");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "pair/vector whole memory frame");
		cases++;
	}
	printf("ARM pair/vector adapter %u: %lu transfer/recovery/overlap/writeback/frame cases\n", ADAPTER, cases - start);
	start = cases;
	const unsigned slot_tags[][2] = {{0,0},{2,3},{4,10},{10,4},{255,1},{0,4},{4,0}};
	const __u64 private_fields[][2] = {{0,1},{32,1},{0,32},{31,30},{15,1}};
	force_draw = 0;
	for (unsigned oi = 0; oi < 6; oi++) for (unsigned ti = 0; ti < 7; ti++) for (unsigned ii = 0; ii < 4; ii++)
	for (unsigned ri = 0; ri < (oi < 2 ? 5 : 1); ri++) for (unsigned fi = 0; fi < (oi < 2 ? 5 : 1); fi++) for (unsigned released = 0; released < 2; released++) {
		unsigned pair = oi < 2, load = oi == 0 || oi == 2 || oi == 3;
		unsigned width = pair && flags[fi] ? flags[fi] : 8, lanes = oi == 2 || oi == 4 ? 1 : 2, index = ii == 0 ? 255 : 10;
		__u64 first = private_fields[ri][0], second = private_fields[ri][1];
		c = (struct kprog_arm64_coordinates){5, 7, released ? -56 : -80, 0, 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		for (unsigned i = 0; i < 31; i++) { regs[i].x = 0xfedcba9876543210ULL ^ i; tags[i] = i == 0 ? 10 : i == 1 ? 4 : 0; }
		regs[15].ptr = (void *)(intptr_t)-80; tags[15] = 4; regs[10].x = 0; tags[10] = ii < 2 ? 0 : ii == 2 ? 4 : 10;
		for (unsigned i = 0; i < sizeof(arena); i++) ((__u8 *)arena)[i] = (__u8)(cases + i * 17);
		for (unsigned i = 0; i < sizeof(packed); i++) ((__u8 *)packed)[i] = (__u8)(cases + i * 13);
		((__u8 *)packed)[2] = slot_tags[ti][0]; ((__u8 *)packed)[3] = slot_tags[ti][1];
		for (unsigned i = 0; i < 48; i++) payload[i] = (__u64)(-64 + (__s64)i * 8);
		for (unsigned i = 0; i < 64; i++) vectors[i] = 0x123456789abcdef0ULL ^ ((__u64)i * 0x11223344556677ULL);
		memcpy(expected_vectors, vectors, sizeof(vectors)); memcpy(expected_raw, raw, sizeof(raw)); memcpy(before_arena, arena, sizeof(arena)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload)); memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		count = wanted_count = copies = 0; expected_entropy = entropy = cases + 0x9e3779b97f4a7c15ULL;
		__u64 loaded[2] = {0}, loaded_tags[2] = {0};
		if (load) {
			for (unsigned slot = 0; slot < lanes; slot++) {
				__u64 part = index == 255 ? 0 : tags[10] == 4 ? coordinate(&expected_c, 1) : tags[10] == 10 ? coordinate(&expected_c, 3) : 0;
				__s64 off = -80 + part + slot * width;
				loaded[slot] = off < expected_c.stack_offset ? free_value() & mask(width) : little((__u8 *)arena + off + a.bias, width);
			}
			for (unsigned slot = 0; slot < lanes; slot++) {
				__u64 part = index == 255 ? 0 : tags[10] == 4 ? coordinate(&expected_c, 1) : tags[10] == 10 ? coordinate(&expected_c, 3) : 0;
				__s64 off = -80 + part + slot * width; unsigned at = off + a.bias;
				loaded_tags[slot] = width == 8 && !(at & 7) && off >= expected_c.stack_offset ? ((__u8 *)packed)[at / 8] : 0;
				if (pair && (loaded_tags[slot] == 4 || loaded_tags[slot] == 10)) loaded[slot] = payload[at / 8];
			}
			if (pair) {
				expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, first, loaded[0], width, loaded_tags[0], width == 8 && loaded_tags[0]);
				expected_write(&expected_c, before_regs, before_tags, (__u8 *)before_arena, (__u8 *)before_packed, a.capacity, a.bias, second, loaded[1], width, loaded_tags[1], width == 8 && loaded_tags[1]);
			} else { expected_vectors[0] = loaded[0]; expected_vectors[1] = lanes > 1 ? loaded[1] : 0; }
		} else for (unsigned slot = 0; slot < lanes; slot++) {
			__u64 part = index == 255 ? 0 : tags[10] == 4 ? coordinate(&expected_c, 1) : tags[10] == 10 ? coordinate(&expected_c, 3) : 0;
			__u64 reg = slot ? second : first;
			unsigned tag = pair ? reg == 32 ? 4 : reg < 31 ? tags[reg] : 0 : 0;
			__u64 value = pair ? reg == 32 ? (__u64)expected_c.stack_offset + coordinate(&expected_c, 1) : reg < 31 ? regs[reg].x + (tag == 4 ? coordinate(&expected_c, 1) : tag == 10 ? coordinate(&expected_c, 3) : 0) : 0 : vectors[slot];
			expected_stack_store(&expected_c, (__u8 *)before_arena, (__u8 *)before_packed, expected_payload, a.bias, -80 + part + slot * width, width, value, tag);
		}
		if (pair) kprog_arm64_pair_step(&a, transfers[oi], load ? first : 255, load ? second : first, load ? 255 : second, 15, index, 0, 0, flags[fi]);
		else kprog_arm64_vector_step(&a, &vectors[0], &vectors[1], transfers[oi], 15, index, 0, 0);
		inputs_equal(&c, &expected_c);
		check(!copies && !memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)) && !memcmp(vectors, expected_vectors, sizeof(vectors)), "private pair/vector live GPR/SIMD/tag/payload writeback");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "private pair/vector byte/tag/payload frame");
		cases++;
	}
	printf("ARM private pair/vector adapter %u: %lu provenance/released/coordinate/order/frame cases\n", ADAPTER, cases - start);
#if ADAPTER
	/* Failure of the second adapter copy checks C's actual partial prefix;
	 * it is not an assertion of native exception recovery semantics. */
	start = cases;
	const unsigned partial_ops[] = {ARM64_OP_LDP, ARM64_OP_STP, ARM64_OP_LOAD_Q0, ARM64_OP_STORE_Q0};
	force_draw = 1; draw_value = 0;
	for (unsigned oi = 0; oi < 4; oi++) for (unsigned mode = 0; mode < 4; mode++) {
		unsigned pair = oi < 2, load = oi == 0 || oi == 2;
		c = (struct kprog_arm64_coordinates){5, 7, -80, 0, 0}; expected_c = c;
		a = (struct kprog_arm64_addressing){&c, regs, tags, (__u8 *)arena, (__u8 *)packed, payload, 160, 96, NULL, NULL, 0, 255, arena}; before_a = a;
		regs[15].ptr = raw + 200; tags[15] = 6; regs[0].x = 0x12345678ffffffffULL; regs[1].x = 0xfedcba9876543210ULL; tags[0] = tags[1] = 0;
		vectors[0] = regs[0].x; vectors[1] = regs[1].x;
		memcpy(before_regs, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags)); memcpy(expected_vectors, vectors, sizeof(vectors)); memcpy(expected_raw, raw, sizeof(raw)); memcpy(before_arena, arena, sizeof(arena)); memcpy(before_packed, packed, sizeof(packed)); memcpy(expected_payload, payload, sizeof(payload));
		unsigned address = mode == 2 ? 200 : 208;
		if (mode & 1) before_regs[15].ptr = raw + 208;
		if (!pair && load) expected_vectors[0] = little(raw + address, 8);
		if (!load) for (unsigned i = 0; i < 8; i++) expected_raw[address + i] = (__u8)((pair ? regs[0].x : vectors[0]) >> (i * 8));
		count = wanted_count = copies = 0; expected_entropy = entropy; if (load) wanted[wanted_count++] = 6;
		copy_reject_at = 2; allow_reject = 1;
		int result = setjmp(rejected);
		if (!result) {
			if (pair) kprog_arm64_pair_step(&a, partial_ops[oi], load ? 0 : 255, load ? 1 : 0, load ? 255 : 1, 15, 255, mode << 24, 8, 8);
			else kprog_arm64_vector_step(&a, &vectors[0], &vectors[1], partial_ops[oi], 15, 255, mode << 24, 8);
			check(0, "second copy unexpectedly returned");
		}
		check(result == 2 && copies == 2, "second adapter failure class/count"); copy_reject_at = 0; allow_reject = 0;
		inputs_equal(&c, &expected_c);
		check(!memcmp(&a, &before_a, sizeof(a)) && !memcmp(regs, before_regs, sizeof(regs)) && !memcmp(tags, before_tags, sizeof(tags)) && !memcmp(vectors, expected_vectors, sizeof(vectors)), "pair/vector read-commit/pre/post failure prefix");
		check(!memcmp(arena, before_arena, sizeof(arena)) && !memcmp(raw, expected_raw, sizeof(raw)) && !memcmp(packed, before_packed, sizeof(packed)) && !memcmp(payload, expected_payload, sizeof(payload)), "pair/vector partial-store memory prefix");
		cases++;
	}
	printf("ARM pair/vector adapter failure: %lu second-operation prefix cases\n", cases - start);
#endif
	check_native_hook();
	return 0;
}
