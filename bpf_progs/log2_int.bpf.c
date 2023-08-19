#include <sys/cdefs.h>
#define u32 unsigned int
#define u64 unsigned long long

u64 __always_inline log2(u32 v) {
  u32 shift, r;

  r = (v > 0xFFFF) << 4;
  v >>= r;
  shift = (v > 0xFF) << 3;
  v >>= shift;
  r |= shift;
  shift = (v > 0xF) << 2;
  v >>= shift;
  r |= shift;
  shift = (v > 0x3) << 1;
  v >>= shift;
  r |= shift;
  r |= (v >> 1);

  return r;
}

u64 __always_inline log2l(u64 v) {
  u32 hi = v >> 32;

  if (hi)
    return log2(hi) + 32;
  else
    return log2(v);
}
_Static_assert(sizeof(u64) == 8, "?");
u64 bpf_main(u64 *nums) {
  u64 hash = 0;
  for (u64 i = 1; i <= nums[0]; i++) {
    hash ^= log2l(nums[i]);
  }
  return hash;
}
