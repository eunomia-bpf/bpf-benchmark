/* Catch eager/repeated coordinate input requests, stale cache use, dropped
 * high address bits, and SP writes that change the wrong register/stack facts. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c/Arm64Address.c"

static const __u64 input_sp = 0xfedcba9876543210ULL;
static const __u64 input_return = 0x123456789abcdef0ULL;
static unsigned requests[4], request_count;
static unsigned long cases;
unsigned long native_lab_entry_input(unsigned kind)
{
	if (request_count == 4 || (kind != 1 && kind != 3)) abort();
	requests[request_count++] = kind;
	return kind == 1 ? input_sp : input_return;
}
void arm64_sim_unsupported_opcode(void) { abort(); }
static void check(int condition, const char *what)
{
	if (!condition) {
		fprintf(stderr, "ARM address cache case %lu: %s\n", cases, what);
		exit(1);
	}
}
static struct kprog_arm64_coordinates initial(__u8 sv, __u8 rv, __u64 seed)
{
	return (struct kprog_arm64_coordinates){seed ^ 0xa55aa55a5aa55aa5ULL,
		seed ^ 0x8000000000000001ULL, -35, sv, rv};
}
static void check_coordinates(struct kprog_arm64_coordinates a,
                              struct kprog_arm64_coordinates b)
{
	check(a.sp_base == b.sp_base && a.return_base == b.return_base &&
	      a.stack_offset == b.stack_offset && a.sp_valid == b.sp_valid &&
	      a.return_valid == b.return_valid, "coordinate state/frame");
}
static __u64 expected_base(struct kprog_arm64_coordinates *s, unsigned tag)
{
	if (tag == 4) {
		if (!s->sp_valid) { s->sp_base = input_sp; s->sp_valid = 1; }
		return s->sp_base;
	}
	if (tag == 10) {
		if (!s->return_valid) { s->return_base = input_return; s->return_valid = 1; }
		return s->return_base;
	}
	return 0;
}
int main(void)
{
	/* The original ternary tag expression has unsigned-int type, even though
	 * its values fit in a byte. Preserve that public macro promotion contract. */
	{
		__u8 *__a64_tag_cells[31];
		_Static_assert(_Generic(ARM64_SIM_L_REG_TAG(0), __u32: 1, default: 0),
		               "ARM tag facade must retain unsigned-int type");
	}
	const __u8 valid[] = {0, 1, 2, 255};
	const __u64 values[] = {0, 1, ~0ULL, 0x8000000000000000ULL,
		0x12345678ffffffffULL, 0xfedcba9876543210ULL};
	for (unsigned si = 0; si < 4; ++si) for (unsigned ri = 0; ri < 4; ++ri)
	for (unsigned vi = 0; vi < 6; ++vi) for (unsigned tag = 0; tag < 256; ++tag) {
		struct kprog_arm64_coordinates s = initial(valid[si], valid[ri], values[vi]), want = s;
		request_count = 0;
		__u64 base = expected_base(&want, tag);
		check(kprog_arm64_materialize(&s, values[vi], tag) == values[vi] + base, "materialized bits");
		unsigned fresh = (tag == 4 && !valid[si]) || (tag == 10 && !valid[ri]);
		check(request_count == fresh && (!fresh || requests[0] == (tag == 4 ? 1U : 3U)), "lazy input identity/count");
		check_coordinates(s, want);
		check(kprog_arm64_unmaterialize(&s, values[vi] + base, tag) == values[vi], "inverse/wrapping bits");
		check(request_count == fresh, "cached inverse refetched input");
		check_coordinates(s, want);
		s = initial(valid[si], valid[ri], values[vi]); request_count = 0;
		check(kprog_arm64_unmaterialize(&s, values[vi] + base, tag) == values[vi], "cold inverse bits");
		check(request_count == fresh && (!fresh || requests[0] == (tag == 4 ? 1U : 3U)), "cold inverse input identity/count");
		check_coordinates(s, want); cases++;
	}
	union arm64_sim_gpr regs[31], before[31]; __u8 tags[31], before_tags[31];
	const __u64 reg_ids[] = {0, 15, 30, 31, 32, 33, 255, 256, 0x100000020ULL, ~0ULL};
	for (unsigned tag = 0; tag < 256; ++tag) for (unsigned r = 0; r < 10; ++r) {
		for (unsigned i = 0; i < 31; ++i) { regs[i].x = values[i % 6] ^ i; tags[i] = tag; }
		memcpy(before, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		struct kprog_arm64_coordinates s = initial(0, 0, reg_ids[r]), want = s;
		unsigned source_tag = reg_ids[r] == 32 ? 4 : reg_ids[r] < 31 ? tag : 0;
		__u64 raw = reg_ids[r] == 32 ? (__u64)s.stack_offset : reg_ids[r] < 31 ? regs[reg_ids[r]].x : 0;
		request_count = 0;
		__u64 expected = raw + expected_base(&want, source_tag);
		check(kprog_arm64_read_reg(&s, regs, tags, reg_ids[r]) == expected, "full-width register/SP/ZR selection");
		check_coordinates(s, want);
		check(!memcmp(before, regs, sizeof(regs)) && !memcmp(before_tags, tags, sizeof(tags)), "read register frame"); cases++;
	}
	volatile __u8 bytes[ARM64_SIM_STACK_BYTES]; __u8 expected_bytes[ARM64_SIM_STACK_BYTES];
	__u64 tag_storage[ARM64_SIM_TAG_STORAGE_BYTES(ARM64_SIM_STACK_BYTES) / 8];
	__u8 *stack_tags = (__u8 *)tag_storage, expected_tags[sizeof(tag_storage)];
	const __s64 targets[] = {-36, -35, -10, 0, 63, 64, 0x7fffffffffffffffLL, (-0x7fffffffffffffffLL - 1)};
	for (unsigned tag = 0; tag < 256; ++tag) for (unsigned ti = 0; ti < 8; ++ti)
	for (unsigned si = 0; si < 4; ++si) for (unsigned ri = 0; ri < 4; ++ri) {
		for (unsigned i = 0; i < 31; ++i) { regs[i].x = values[i % 6] ^ i; tags[i] = i; }
		memcpy(before, regs, sizeof(regs)); memcpy(before_tags, tags, sizeof(tags));
		for (unsigned i = 0; i < sizeof(bytes); ++i) bytes[i] = expected_bytes[i] = i * 17U + 3U;
		for (unsigned i = 0; i < sizeof(tag_storage); ++i) stack_tags[i] = expected_tags[i] = 0x80U + i;
		struct kprog_arm64_coordinates s = initial(valid[si], valid[ri], ti), want = s;
		__u64 sp_base = valid[si] ? s.sp_base : input_sp, ret_base = valid[ri] ? s.return_base : input_return;
		__u64 pointer = (__u64)targets[ti] + (tag == 4 ? 0 : sp_base) - (tag == 10 ? ret_base : 0);
		request_count = 0;
		kprog_arm64_write_ptr(&s, regs, tags, bytes, stack_tags, 32, (void *)(uintptr_t)pointer, tag);
		unsigned expected_requests[2], count = 0;
		if (tag == 10 && !valid[ri]) { want.return_base = input_return; want.return_valid = 1; expected_requests[count++] = 3; }
		if (tag != 4 && !valid[si]) { want.sp_base = input_sp; want.sp_valid = 1; expected_requests[count++] = 1; }
		check(request_count == count && !memcmp(requests, expected_requests, count * sizeof(unsigned)), "SP input order/cache independence");
		want.stack_offset = targets[ti]; check_coordinates(s, want);
		if (targets[ti] > -35) {
			for (unsigned i = 0; i < sizeof(bytes); ++i) {
				__s64 offset = (__s64)i - ARM64_SIM_STACK_BIAS;
				if (offset >= -35 && offset < targets[ti]) expected_bytes[i] = 0;
			}
			for (unsigned w = 0; w < KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES); ++w)
				if ((__s64)(w * 8) - ARM64_SIM_STACK_BIAS < targets[ti] &&
				    (__s64)(w * 8 + 8) - ARM64_SIM_STACK_BIAS > -35) expected_tags[w] = 0;
		}
		for (unsigned i = 0; i < sizeof(bytes); ++i) check(bytes[i] == expected_bytes[i], "released byte interval");
		check(!memcmp(stack_tags, expected_tags, sizeof(tag_storage)), "released ghost facts/padding frame");
		check(!memcmp(before, regs, sizeof(regs)) && !memcmp(before_tags, tags, sizeof(tags)), "SP write register frame"); cases++;
	}
	printf("ARM coordinate/cache and SP frame checks: %lu cases\n", cases);
	return 0;
}
