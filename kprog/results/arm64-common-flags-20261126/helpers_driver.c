#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "helpers-layout.h"
_Alignas(8) unsigned char array_map[4096], hash_map[4096], lpm_map[4096], percpu_map[4096];
static _Alignas(8) unsigned char bucket[4096], generic[4096], ops[4096];
static uint64_t cpu_values[2]={91,92}, dynamic_value=123;
static unsigned cpu_calls, method_calls;
extern uint64_t array_entry(const unsigned *), hash_entry(const unsigned *);
extern uint64_t lpm_entry(const void *), percpu_entry(const unsigned *);
extern uint64_t dynamic_entry(void *,const unsigned *);
extern long user_entry(const uint64_t *), kernel_entry(const uint64_t *);
extern long __kprog_probe_read_user(void *,unsigned,const void *);
extern long __kprog_probe_read_kernel(void *,unsigned,const void *);
void *bpf_this_cpu_ptr(const void *p) { ++cpu_calls; return (char *)p+8; }
long copy_from_user_nofault(void *d,const void *s,unsigned long n)
{ if (!s) { memset(d,0xaa,n); return -14; } memcpy(d,s,n); return 0; }
long copy_from_kernel_nofault(void *d,const void *s,unsigned long n)
{ return copy_from_user_nofault(d,s,n); }
static void *method(void *map,const unsigned *key)
{ ++method_calls; return map==generic && *key==0?&dynamic_value:NULL; }
static void u32(void *p,unsigned off,unsigned v) { memcpy((char *)p+off,&v,4); }
static void ptr(void *p,unsigned off,const void *v) { memcpy((char *)p+off,&v,8); }
static void array(void *p,unsigned kind) {
 u32(p,MAP_KIND,kind); u32(p,ARRAY_LIMIT,2); u32(p,ARRAY_STRIDE,8); u32(p,ARRAY_MASK,1);
}
#define CHECK(C) do { ++cases; if (!(C)) { fprintf(stderr,"case %u failed line %u\n",cases,__LINE__); return 1; } } while (0)
int main(void) {
 unsigned cases=0,key; uint64_t values[2]={17,29},value=42,destination;
 array(array_map,2); memcpy(array_map+ARRAY_VALUES,values,sizeof(values));
 array(percpu_map,6); ptr(percpu_map,ARRAY_PPTRS,cpu_values); ptr(percpu_map,ARRAY_PPTRS+8,cpu_values);
 ptr(hash_map,HASH_BUCKETS,bucket); u32(hash_map,HASH_COUNT,1); u32(hash_map,HASH_SEED,0);
 ptr(bucket,HASH_HEAD,(void *)1);
 u32(generic,MAP_KIND,1); ptr(generic,MAP_OPS,ops); ptr(ops,OPS_LOOKUP,(const void *)method);
 for (key=0;key<3;++key) {
  CHECK(array_entry(&key)==(key<2?values[key]:0));
  CHECK(percpu_entry(&key)==(key<2?92:0));
  CHECK(dynamic_entry(array_map,&key)==(key<2?values[key]:0));
 }
 CHECK(cpu_calls==2);
 for (key=0;key<2;++key) {
  unsigned lpm_key[2]={32,key};
  CHECK(hash_entry(&key)==0); CHECK(lpm_entry(lpm_key)==0);
  CHECK(dynamic_entry(generic,&key)==(key==0?123:0));
 }
 CHECK(method_calls==2);
 CHECK(user_entry(&value)==42); CHECK(kernel_entry(&value)==42);
 CHECK(user_entry(NULL)==-14); CHECK(kernel_entry(NULL)==-14);
 destination=123; CHECK(__kprog_probe_read_user(&destination,8,NULL)==-14 && destination==0);
 destination=123; CHECK(__kprog_probe_read_kernel(&destination,8,NULL)==-14 && destination==0);
 printf("%u cases passed (ARRAY/PERCPU/dynamic, empty HASH/LPM, nofault success/error/zeroing)\n",cases);
 return 0;
}
