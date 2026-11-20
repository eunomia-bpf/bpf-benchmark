#include <stdint.h>
extern unsigned char map_a[];
extern void *bpf_map_lookup_elem(void *, const void *);
unsigned stock_entry(void *ctx)
{
    (void)ctx;
    const uint32_t key[]={96,0x5a5a5a5a,0x5a5a5a5a,0x5a5a5a5a};
    const uint32_t *value=bpf_map_lookup_elem(map_a,key);
    return value ? *value : 0;
}
