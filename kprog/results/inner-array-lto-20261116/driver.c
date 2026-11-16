#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned char outer_a[1], outer_b[1], outer_c[1];
static unsigned char arrays[3][2048];
static const uint32_t limits[] = {1,5,17}, strides[] = {8,24,16}, masks[] = {0,7,31};
static unsigned calls, fail_outer;
struct context { uint32_t selector, key; };
extern uintptr_t ENTRY(struct context *);

static void put32(unsigned char *where, uint32_t value) { memcpy(where, &value, 4); }
static void *expected(unsigned which, uint32_t key)
{
    return key < limits[which] ? arrays[which] + VALUE_OFFSET + (key & masks[which])*strides[which] : NULL;
}
void *bpf_map_lookup_elem(void *map, const void *key)
{
    ++calls;
    void *outer[] = {outer_a, outer_b, outer_c};
    for (unsigned i=0; i<3; ++i) {
        if (map == outer[i]) return fail_outer ? NULL : arrays[i];
        if (map == arrays[i]) { uint32_t index; memcpy(&index,key,4); return expected(i,index); }
    }
    return (void *)(uintptr_t)0xdeadbeef;
}
int main(void)
{
    for (unsigned i=0; i<3; ++i) {
        put32(arrays[i]+LIMIT_OFFSET,limits[i]); put32(arrays[i]+STRIDE_OFFSET,strides[i]);
        put32(arrays[i]+MASK_OFFSET,masks[i]);
    }
    unsigned vectors=0;
    for (unsigned selector=0; selector<9; ++selector)
        for (unsigned key=0; key<20; ++key)
            for (fail_outer=0; fail_outer<2; ++fail_outer) {
                unsigned which = SELECT_ENTRY ? ((selector&1) ? 0 : 1) : selector%3;
                struct context ctx={selector,key}; calls=0;
                void *value=(void *)ENTRY(&ctx);
                void *want=fail_outer ? NULL : expected(which,key);
                unsigned want_calls=fail_outer ? 1 : EXPECT_CALLS;
                if (value != want || calls != want_calls) {
                    fprintf(stderr,"selector=%u key=%u null=%u value=%p expected=%p calls=%u expected=%u\n",
                        selector,key,fail_outer,value,want,calls,want_calls);
                    return 1;
                }
                ++vectors;
            }
    printf("%u vectors pass\n",vectors);
    return 0;
}
