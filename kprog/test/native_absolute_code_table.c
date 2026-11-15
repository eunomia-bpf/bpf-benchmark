/* Label-address tables retain full pointer relocations under the unified flags. */
unsigned long absolute_table(const volatile unsigned long *ctx)
{
    static void *const targets[] = {&&a, &&b, &&c, &&d, &&e, &&f, &&g, &&h};
    unsigned long index = ctx[0];
    if (index >= 8) return 0;
    goto *targets[index];
a: return ctx[1] + 17;
b: return ctx[2] * 3;
c: return ctx[3] ^ 0x1234;
d: return ctx[4] - 29;
e: return ctx[5] | 0x8000;
f: return ctx[6] & 0x7fff;
g: return ctx[7] + 71;
h: return ctx[8] * 5;
}
