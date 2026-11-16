/* Execute the actual closed RAW fixture, including its CALL/RET table.
 * Compare return values and the complete entry/free-input stream across C
 * bindings. Heap/stack addresses never enter the captured observation.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c/Arm64Entry.h"
int arm64_execute_compile(struct __sk_buff *);
static __u64 state, values[1024];
static unsigned events[1024], count;
static void require(int ok)
{ if (!ok) { fputs("closed ARM program observation failed\n", stderr); exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	require(count < 1024 && (kind == 1 || kind == 3 || kind == 6));
	state ^= state << 13; state ^= state >> 7; state ^= state << 17;
	__u64 value = kind == 1 ? 0x10000 : kind == 3 ? 0x20000 : state;
	events[count] = kind; values[count++] = value; return value;
}
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{ (void)site; abort(); }
void arm64_sim_unsupported_opcode(void) { abort(); }
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p, __u8 kind, __u32 off)
{ (void)p; (void)kind; (void)off; abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p; abort(); }
__u64 kprog_c_atomic_fetch(void *p, __u64 v, __u32 w, __u32 op, __u32 order)
{ (void)p; (void)v; (void)w; (void)op; (void)order; abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t align)
{ require(align == 1); memcpy(dst, src, size); }
int main(void)
{
	const __u32 marks[] = {0, 1, 2, 14, 15, 0x80000000U, 0xffffffffU};
	unsigned cases = 0;
	for (unsigned seed = 1; seed <= 8; ++seed)
		for (unsigned mi = 0; mi < sizeof(marks)/sizeof(*marks); ++mi)
			for (unsigned priority = 0; priority < 15; ++priority) {
				struct __sk_buff context = {0};
				context.mark = marks[mi]; context.priority = priority;
				context.hash = seed * 0x81234567U;
				state = seed; count = 0;
				__u32 result = arm64_execute_compile(&context);
				const __u32 header[] = {seed, context.mark, priority, context.hash, result, count};
				require(fwrite(header, sizeof(header), 1, stdout) == 1 &&
				        fwrite(events, sizeof(*events), count, stdout) == count &&
				        fwrite(values, sizeof(*values), count, stdout) == count);
				++cases;
			}
	fprintf(stderr, "ARM closed RAW program: %u return/input-stream observations\n", cases);
	return 0;
}
