/* Execute the real entry up to the mapping/tail-call boundary with deterministic helpers. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
static void *per_cpu_records,*metrics,*pid_page_to_mapping_info,*reported_pids;
static unsigned char record[65536] __attribute__((aligned(64))),metric[65536],mapping[256];
static unsigned lookup_count; static int present;
uint64_t bpf_get_current_pid_tgid(void){return ((uint64_t)0x1234<<32)|0x5678;}
uint64_t ktime_get_mono_fast_ns(void){return 123456789;}
uint64_t bpf_ktime_get_ns(void){return 123456789;}
uint64_t bpf_get_current_comm(void *p,uint32_t n){memset(p,0,n);return 0;}
uint64_t bpf_get_stackid(void *ctx,void *map,uint64_t flags){return 7;}
void *bpf_map_lookup_elem(void *map,void *key){
 if(map==per_cpu_records){printf("lookup record %08x\n",*(uint32_t*)key);return record;}
 if(map==metrics){printf("lookup metric %u\n",*(uint32_t*)key);return metric;}
 if(map==pid_page_to_mapping_info){unsigned char *k=key;printf("lookup mapping");for(int i=0;i<16;i++)printf(" %02x",k[i]);puts("");return present==2 || (present && lookup_count++==0)?mapping:NULL;}
 if(map==reported_pids){puts("lookup reported");return metric;}
 puts("lookup other");return NULL;
}
uint64_t bpf_tail_call(void *ctx,void *map,uint32_t slot){printf("tailcall %u\n",slot);return 0;}
uint64_t bpf_probe_read_user(void *dst,uint32_t n,const void *src){printf("read user %u\n",n);memset(dst,0,n);return 0;}
uint64_t bpf_probe_read_kernel(void *dst,uint32_t n,const void *src){printf("read kernel %u\n",n);memset(dst,0,n);return 0;}
uint64_t bpf_get_current_task(void){return (uintptr_t)record;}
uint64_t bpf_perf_event_output(void*a,void*b,uint64_t c,void*d,uint64_t e){puts("perf output");return 0;}
uint64_t bpf_map_update_elem(void*a,void*b,void*c,uint64_t d){puts("map update");return 0;}
uint64_t bpf_map_delete_elem(void*a,void*b){puts("map delete");return 0;}
uint64_t bpf_trace_printk(void*a,uint32_t b,...){puts("DEBUG PRINT");return 0;}

int main(int argc,char **argv){
 void *lib=dlopen(argv[1],RTLD_LAZY|RTLD_LOCAL);if(!lib){puts(dlerror());return 1;}
 per_cpu_records=dlsym(lib,"per_cpu_records");metrics=dlsym(lib,"metrics");pid_page_to_mapping_info=dlsym(lib,"pid_page_to_mapping_info");reported_pids=dlsym(lib,"reported_pids");
 int (*native_tracer_entry)(void*)=dlsym(lib,"native_tracer_entry");if(!native_tracer_entry)return 2;
 present=argc>2;uint64_t regs[32]={0};regs[16]=0x123456789;regs[17]=0x33;regs[19]=0x7fff12345678;regs[20]=0x2b;
 struct {void*regs;void*data;} ctx={regs,record};
 int rc=native_tracer_entry(&ctx);printf("return %d\n",rc);return 0;
}
void configure_maps(void *a,void *b,void *c,void*d,int flag){
 per_cpu_records=a;metrics=b;pid_page_to_mapping_info=c;reported_pids=d;present=flag;lookup_count=0;
 memset(record,0,sizeof(record));memset(metric,0,sizeof(metric));memset(mapping,0,sizeof(mapping));if(flag==2)mapping[15]=1;setvbuf(stdout,NULL,_IONBF,0);
}
void *record_address(void){return record;}
void *metric_address(void){return metric;}
