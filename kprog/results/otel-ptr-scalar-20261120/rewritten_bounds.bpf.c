#define SEC(x) __attribute__((section(x), used))
typedef unsigned long long u64;
SEC("classifier") int f(void *ctx) {
  /* 24 - d < 8  <=>  16 < d < 25  <=>  (d - 17) < 8, d >= 17 */
  if ((u64)ctx > 0x18) return 2;         /* d < 25 */
  if ((u64)ctx < 0x11) return 3;         /* d > 16 */
  return 1;
}
