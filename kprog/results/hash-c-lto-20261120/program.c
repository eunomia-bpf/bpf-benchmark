extern unsigned char map_a[];
extern void *bpf_map_lookup_elem(void *,const void *);
unsigned hash_fixture(void *ctx)
{
    (void)ctx;
    unsigned long key=0x5a5a5a5a5a5a5a5aUL;
    const unsigned *value=bpf_map_lookup_elem(map_a,&key);
    return value ? *value : 0;
}
