/* Catch wrong per-CPU pointer stride, key overread/alignment, bounds/mask,
 * wrong CPU translation argument and assumptions that map names cannot alias. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
_Alignas(8) unsigned char counts[4096],other[4096];
extern unsigned char same[4096] __attribute__((alias("counts")));
static unsigned char values[32][512];
static const void *expected_base;
static unsigned cpu_offset,cpu_calls,generic_calls;
extern void *selected(const void *),*selected_alias(const void *),*unselected(const void *);
extern void *dynamic(void *,const void *);
void *bpf_this_cpu_ptr(const void *base)
{
    assert(base==expected_base);++cpu_calls;
    return (unsigned char *)base+cpu_offset;
}
void *bpf_map_lookup_elem(void *map,const void *key)
{ assert(key);++generic_calls;return map; }
static void word(unsigned offset,unsigned value) { memcpy(counts+offset,&value,4); }
int main(void)
{
    long page=sysconf(_SC_PAGESIZE);assert(page>0);
    unsigned char *keyspace=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(keyspace!=MAP_FAILED && !mprotect(keyspace+page,page,PROT_NONE));
    for(unsigned i=0;i<32;++i) { void *base=values[i];memcpy(counts+PPTRS+i*sizeof(base),&base,sizeof(base)); }
    unsigned keys[]={0,1,2,3,16,17,31,0x80000000U,0xffffffffU};
    unsigned offsets[]={0,64,192},masks[]={3,31},cases=0;
    word(STRIDE,5000); /* elem_size is not the pptr table stride. */
    for(unsigned n=0;n<=17;++n) for(unsigned m=0;m<2;++m)
    for(unsigned c=0;c<3;++c) for(unsigned a=0;a<4;++a) for(unsigned k=0;k<9;++k) {
        word(LIMIT,n);word(MASK,masks[m]);cpu_offset=offsets[c];cpu_calls=0;
        unsigned char *key=keyspace+page-4-a;memcpy(key,&keys[k],4);
        expected_base=values[keys[k]&masks[m]];
        void *want=keys[k]<n ? (unsigned char *)expected_base+cpu_offset : NULL;
        assert(selected(key)==want && selected_alias(key)==want);
        assert(cpu_calls==(keys[k]<n ? 2U : 0U) && generic_calls==0);cases+=2;
    }
    unsigned key=0;
    assert(unselected(&key)==other && dynamic(counts,&key)==counts && generic_calls==2);
    assert(!munmap(keyspace,page*2));
    printf("%u per-CPU ARRAY/alias/boundary/unaligned-key cases, two generic calls\n",cases);
}
