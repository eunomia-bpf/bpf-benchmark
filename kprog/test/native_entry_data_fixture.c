const volatile unsigned live_value __attribute__((section(".rodata.config"))) = 7;
const volatile unsigned other_value __attribute__((section(".rodata.config"))) = 8;

__attribute__((noinline)) unsigned shared_read(void) { return live_value; }
unsigned entry(void *ctx) { return shared_read() + 1; }
unsigned other_entry(void *ctx) { return other_value; }

#if defined(__bpf__) || defined(__BPF__)
#define MUTABLE_SECTION(name) __attribute__((section(name), used))
char mutable_license[] MUTABLE_SECTION("license") = "GPL";
#else
#define MUTABLE_SECTION(name)
#endif

// Internal mutable variables use PC32 section-symbol relocations, including
// the five-byte RIP bias of a trailing immediate byte store.
static volatile unsigned char mutable_flag;
static volatile unsigned mutable_bias = 7;
MUTABLE_SECTION("socket") unsigned mutable_entry(void *ctx)
{
    (void)ctx;
    unsigned previous = mutable_flag;
    mutable_flag = previous + 1;
    return mutable_bias + mutable_flag;
}
MUTABLE_SECTION("socket") unsigned mutable_immediate(void *ctx)
{
    (void)ctx;
    mutable_flag = 9;
    return mutable_flag;
}
