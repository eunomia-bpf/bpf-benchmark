const volatile unsigned live_value __attribute__((section(".rodata.config"))) = 7;
const volatile unsigned other_value __attribute__((section(".rodata.config"))) = 8;

__attribute__((noinline)) unsigned shared_read(void) { return live_value; }
unsigned entry(void *ctx) { return shared_read() + 1; }
unsigned other_entry(void *ctx) { return other_value; }
