#define SEC(x) __attribute__((section(x), used))
typedef unsigned long long u64;
SEC("classifier") int f(void *ctx) {
  u64 r = 24 - (u64)ctx;   /* 64-bit const - ctx pointer */
  if (r < 8) return 1;
  return (int)r;
}
