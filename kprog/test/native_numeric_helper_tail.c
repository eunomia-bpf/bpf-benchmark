__attribute__((section("kprobe/test")))
unsigned int numeric_tail(unsigned long *ctx)
{
    return ctx[0] ? ((unsigned int (*)(void))7)() :
                    ((unsigned int (*)(void))8)();
}
char _license[] __attribute__((section("license"))) = "GPL";
