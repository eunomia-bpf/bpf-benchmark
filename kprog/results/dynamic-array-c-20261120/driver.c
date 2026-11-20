/* Detect dynamic ARRAY dispatch, wrong key width/alignment, stride/mask,
 * eager key reads for other types, and wrong map callback/arguments. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
_Alignas(8) unsigned char counts[65536], other[65536], ops_a[4096], ops_b[4096];
extern unsigned char same[65536] __attribute__((alias("counts")));
extern void *selected(const void *), *selected_alias(const void *);
extern void *unselected(const void *), *dynamic(void *, const void *);
static unsigned callbacks, generic, expected_callback;
static void *expected_map;
static const void *expected_key;
static void set32(void *map, unsigned off, unsigned value)
{ memcpy((char *)map+off, &value, sizeof(value)); }
static unsigned get32(const void *map, unsigned off)
{ unsigned value; memcpy(&value, (const char *)map+off, sizeof(value)); return value; }
static void *array_reference(void *map, const void *key)
{
    unsigned index; memcpy(&index, key, sizeof(index));
    return index < get32(map,LIMIT) ? (char *)map+VALUES+
        (uint64_t)get32(map,STRIDE)*(index&get32(map,MASK)) : NULL;
}
static void *callback(void *map, const void *key, unsigned identity)
{
    assert(map==expected_map && key==expected_key && identity==expected_callback);
    ++callbacks;
    return get32(map,TYPE)==2 ? array_reference(map,key) : (char *)map+identity;
}
static void *callback_a(void *map, const void *key) { return callback(map,key,17); }
static void *callback_b(void *map, const void *key) { return callback(map,key,29); }
__attribute__((weak)) void *bpf_map_lookup_elem(void *map, const void *key)
{
    void *ops; void *(*lookup)(void *,const void *);
    ++generic; memcpy(&ops,(char *)map+OPS,sizeof(ops));
    memcpy(&lookup,(char *)ops+LOOKUP,sizeof(lookup));
    return lookup(map,key);
}
int main(void)
{
    void *a=ops_a,*b=ops_b; void *(*ca)(void *,const void *)=callback_a;
    void *(*cb)(void *,const void *)=callback_b;
    memcpy(counts+OPS,&a,sizeof(a)); memcpy(other+OPS,&b,sizeof(b));
    memcpy(ops_a+LOOKUP,&ca,sizeof(ca)); memcpy(ops_b+LOOKUP,&cb,sizeof(cb));
    long page=sysconf(_SC_PAGESIZE); assert(page>0);
    char *keys=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(keys!=MAP_FAILED && !mprotect(keys+page,page,PROT_NONE));
    unsigned values[]={0,1,2,7,8,9,0x80000000U,0xffffffffU};
    unsigned strides[]={0,1,8,13,5000}, cases=0, dynamic_array=0;
    set32(counts,TYPE,2); set32(other,TYPE,2);
    for(unsigned n=0;n<=9;++n) for(unsigned s=0;s<5;++s)
    for(unsigned mask=3;mask<=7;mask+=4) for(unsigned align=0;align<4;++align)
    for(unsigned k=0;k<8;++k) {
        char *key=keys+page-4-align; memcpy(key,&values[k],4);
        set32(counts,LIMIT,n);set32(counts,STRIDE,strides[s]);set32(counts,MASK,mask);
        set32(other,LIMIT,n);set32(other,STRIDE,strides[s]);set32(other,MASK,mask);
        expected_key=key;expected_map=counts;expected_callback=17;
        void *want=array_reference(counts,key);
        assert(selected(key)==want && selected_alias(key)==want);
        assert(dynamic(counts,key)==want);++dynamic_array;
        expected_map=other;expected_callback=29;
        want=array_reference(other,key);
        assert(dynamic(other,key)==want && unselected(key)==want);dynamic_array+=2;
        cases+=5;
    }
    assert(callbacks==(BEFORE ? dynamic_array : 0));
    assert(generic==(BEFORE ? dynamic_array : 0));
    unsigned types[]={0,1,6,11,13,0xffffffffU};
    unsigned initial=callbacks;
    for(unsigned t=0;t<6;++t) {
        /* Other map methods need not read the key: a premature ARRAY key load faults. */
        set32(other,TYPE,types[t]);expected_key=keys+page;expected_map=other;expected_callback=29;
        assert(dynamic(other,expected_key)==other+29 && unselected(expected_key)==other+29);
        expected_map=counts;expected_callback=17;set32(counts,TYPE,types[t]);
        assert(dynamic(counts,expected_key)==counts+17);cases+=3;
    }
    assert(callbacks-initial==18);
    assert(generic==(BEFORE ? dynamic_array+18 : 0));
    assert(!munmap(keys,page*2));
    printf("%u cases; ARRAY callbacks %u, other callbacks %u, generic helper calls %u\n",
           cases,initial,callbacks-initial,generic);
}
