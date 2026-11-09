/* MOV/MOVZX/MOVSX memory loads against actual production macros and CPU:
 * signed stack values, partial/numeric RSP writes, ABI pointer destination,
 * captured address aliases, all GPR cells/tags and unchanged flags/buffers. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 512U
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#ifndef __always_inline
#define __always_inline inline
#endif
#include "../x86/x86_sim_local_bpf.h"
#include "x86_no_helpers_host.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static __u8 heap[512],native_stack[512];
static const __u64 values[]={0,1,15,16,31,32,63,64,255,256,0x7f,0x80,0x7fff,0x8000,0x7fffffff,0x80000000ULL,0x7fffffffffffffffULL,0x8000000000000000ULL,0xffffffffffffffffULL};
#define NVALUES (sizeof(values)/sizeof(values[0]))
static const unsigned operations[]={X86_OP_MOV_LOAD,X86_OP_MOV_LOAD_SCALAR,X86_OP_MOVSX_LOAD};
unsigned long native_lab_entry_input(unsigned kind){(void)kind;abort();}
unsigned long native_lab_exclusive_failure_choice(unsigned site){(void)site;abort();}
static __u64 flagword(unsigned seed){return ((seed&1)?1:0)|((seed&2)?4:0)|((seed&4)?16:0)|((seed&8)?64:0)|((seed&16)?128:0)|((seed&32)?2048:0);}
static void put(__u8 *p,unsigned width,__u64 value){for(unsigned i=0;i<width;i++)p[i]=value>>(i*8);}
static __u64 seed(unsigned reg){return 0x1122334455667788ULL+reg*0x102030405ULL;}
struct observation{__u64 before[16],after[16],raw_before[16],raw_after[16],flags;__u8 tags_before[16],tags_after[16],heap[512],stack[512];};
struct cpu_result{__u64 value,flags;};
#define LOAD(OP,ST,DT) do{DT value;asm volatile("pushq %[old]; popfq; " OP " %[memory],%[value]; pushfq; popq %[flags]" :[value]"=&r"(value),[flags]"=&r"(out.flags):[memory]"m"(*(const ST *)address),[old]"r"(old|2):"cc","memory");out.value=value;}while(0)
static struct cpu_result cpu(unsigned source,unsigned target,unsigned sign,const __u8 *address,__u64 old){struct cpu_result out;
 if(sign){if(source==1&&target==2)LOAD("movsbw",__u8,__u16);else if(source==1&&target==4)LOAD("movsbl",__u8,__u32);else if(source==1&&target==8)LOAD("movsbq",__u8,__u64);else if(source==2&&target==4)LOAD("movswl",__u16,__u32);else if(source==2&&target==8)LOAD("movswq",__u16,__u64);else if(source==4&&target==8)LOAD("movslq",__u32,__u64);else abort();}
 else if(source==1&&target==1)LOAD("movb",__u8,__u8);else if(source==1&&target==2)LOAD("movzbw",__u8,__u16);else if(source==1&&target==4)LOAD("movzbl",__u8,__u32);else if(source==1&&target==8)LOAD("movzbq",__u8,__u64);else if(source==2&&target==2)LOAD("movw",__u16,__u16);else if(source==2&&target==4)LOAD("movzwl",__u16,__u32);else if(source==2&&target==8)LOAD("movzwq",__u16,__u64);else if(source==4&&(target==4||target==8))LOAD("movl",__u32,__u32);else if(source==8&&target==8)LOAD("movq",__u64,__u64);else abort();return out;}
static unsigned abi_tag(unsigned kind,__s64 off){if(kind==KPROG_ABI_KIND_XDP){if(off==KPROG_ABI_XDP_DATA_OFF)return X86_SIM_TAG_PACKET;if(off==KPROG_ABI_XDP_DATA_END_OFF)return X86_SIM_TAG_PACKET_END;return X86_SIM_TAG_SCALAR;}if(off==KPROG_ABI_SKB_DATA_OFF)return X86_SIM_TAG_PACKET;if(off==KPROG_ABI_SKB_DATA_END_OFF)return X86_SIM_TAG_PACKET_END;return X86_SIM_TAG_SCALAR;}
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned direct,unsigned op,unsigned flags,unsigned dst,
 unsigned profile,unsigned source_width,unsigned memory_mode,unsigned index_mode,int displacement,__u64 left,__u64 right,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=flagseed&1?KPROG_ABI_KIND_XDP:KPROG_ABI_KIND_SKB;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 X86_SIM_L_WRITE_REG_WIDTH(X86_R8,2,X86_WIDTH_64);
 unsigned base=profile==1?X86_RSP:X86_RDI;
 if(profile==0||profile==3)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&heap[256],profile==3?X86_SIM_TAG_ABI:X86_SIM_TAG_SCALAR);
 if(profile==2)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 if(dst!=X86_RSP&&dst!=X86_RDX&&dst!=base&&dst!=X86_R8)X86_SIM_L_WRITE_REG_WIDTH(dst,left,X86_WIDTH_64);
 unsigned width=flags?flags:8,index=index_mode?X86_R8:X86_REG_NONE,scale=index_mode?index_mode-1:0;
 unsigned offset=((profile==0||profile==3)?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);}
 put(profile==1||profile==2?(__u8 *)(void *)__x86_stack_mem.b+offset:heap+offset,source_width,right);
 __u64 old=flagword(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->before[reg]=X86_SIM_L_READ_REG(reg);out->tags_before[reg]=X86_SIM_L_REG_TAG(reg);out->raw_before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 __u32 aux=X86_MEM_AUX_FULL(index,scale,memory_mode?source_width:0);
 if(direct)X86_SIM_L_EXEC_MOV_LOAD(op,dst,base,flags,aux,(__u64)(__s64)displacement);
 else X86_SIM_L_EXEC(op,dst,base,flags,aux,(__u64)(__s64)displacement);
 for(unsigned reg=0;reg<16;reg++){out->after[reg]=X86_SIM_L_READ_REG(reg);out->tags_after[reg]=X86_SIM_L_REG_TAG(reg);out->raw_after[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
static unsigned long xdp_cases;
#define XDP_SITE(OFF,VALUE) do{X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD,X86_RSP,X86_RDI,8,X86_MEM_AUX_FULL(X86_REG_NONE,0,8),OFF);if(X86_SIM_L_READ_REG(X86_RSP)!=(__u64)(VALUE)||(__u64)(long)__x86_rsp.ptr!=(__u64)(VALUE)-__x86_native_stack_base||X86_SIM_L_REG_TAG(X86_RSP)!=X86_SIM_TAG_SCALAR){fprintf(stderr,"live XDP RSP got=%llx expected=%llx raw=%llx base=%llx\n",X86_SIM_L_READ_REG(X86_RSP),(__u64)(VALUE),(__u64)(long)__x86_rsp.ptr,__x86_native_stack_base);exit(1);}}while(0)
static void xdp_rsp(void){for(unsigned fs=0;fs<64;fs++)for(unsigned vi=0;vi<NVALUES;vi++){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=KPROG_ABI_KIND_XDP;
 struct xdp_md ctx={};ctx.data=(__u32)values[vi];ctx.data_end=(__u32)~values[vi];struct xdp_md copy=ctx;
 __x86_native_stack_base=0x100000;__x86_sim_is_xdp=1;__x86_sim_helper_ctx=&ctx;X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&ctx,X86_SIM_TAG_ABI);
 __u64 old=flagword(fs);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 XDP_SITE(KPROG_ABI_XDP_DATA_OFF,ctx.data);XDP_SITE(KPROG_ABI_XDP_DATA_END_OFF,ctx.data_end);
 __u64 flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 if(flags!=old||memcmp(&ctx,&copy,sizeof(ctx))||X86_SIM_L_REG_VALUE(X86_RDI)!=(void *)&ctx||X86_SIM_L_REG_TAG(X86_RDI)!=X86_SIM_TAG_ABI)abort();xdp_cases+=2;
 }}
int main(void){const unsigned widths[]={0,1,2,4,8},sources[]={1,2,4,8};unsigned long cases=0;xdp_rsp();
 for(unsigned oi=0;oi<3;oi++)for(unsigned wi=0;wi<5;wi++)for(unsigned si=0;si<4;si++)for(unsigned memory_mode=0;memory_mode<2;memory_mode++){
  unsigned op=operations[oi],width=widths[wi]?widths[wi]:8,source=sources[si],sign=op==X86_OP_MOVSX_LOAD;
  if(source>width||(sign&&source==width)||(!memory_mode&&source!=width))continue;
  for(unsigned dst=0;dst<16;dst++)for(unsigned profile=0;profile<4;profile++)for(unsigned fs=0;fs<64;fs++)for(unsigned li=0;li<NVALUES;li++){
   unsigned index_mode=(li+fs)%5,scale=index_mode?index_mode-1:0;int displacement=li&1?-16:16;if(profile==1)displacement+=32;
   unsigned offset=((profile==0||profile==3)?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);unsigned stack=profile==1||profile==2;
   struct observation a,b;__u64 left=values[(li+fs)%NVALUES];
   simulate(&a,1,op,widths[wi],dst,profile,source,memory_mode,index_mode,displacement,left,values[li],fs);simulate(&b,0,op,widths[wi],dst,profile,source,memory_mode,index_mode,displacement,left,values[li],fs);
   if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"direct/interpreter op=%u src=%u width=%u dst=%u profile=%u\n",op,source,width,dst,profile);return 1;}
   for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);}put(stack?native_stack+offset:heap+offset,source,values[li]);
   struct cpu_result expected=cpu(source,width,sign,stack?native_stack+offset:heap+offset,flagword(fs));
   __u64 mask=width==8?~0ULL:(1ULL<<(width*8))-1,write=expected.value&mask;if(width==1||width==2)write|=a.before[dst]&~mask;
   /* Released stack bytes follow the fixed host fresh word0. */
  if(dst==X86_RSP){__s64 released=(__s64)(write-(__u64)(long)&native_stack[512]);for(unsigned i=0;i<512;i++)if((__s64)i-512<released)native_stack[i]=0;}
   if(memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||a.flags!=flagword(fs)||((expected.flags^flagword(fs))&0x8d5)){fprintf(stderr,"CPU flags/memory op=%u source=%u width=%u dst=%u profile=%u li=%u\n",op,source,width,dst,profile,li);return 1;}
   for(unsigned reg=0;reg<16;reg++){
    __u64 want=reg==dst?write:a.before[reg],raw=reg==dst?(reg==X86_RSP?write-(__u64)(long)&native_stack[512]:write):a.raw_before[reg];
    unsigned tag=reg==dst?X86_SIM_TAG_SCALAR:a.tags_before[reg];
    if(reg==dst&&reg!=X86_RSP&&op==X86_OP_MOV_LOAD&&profile==3&&source==8&&width==8)tag=abi_tag(fs&1?KPROG_ABI_KIND_XDP:KPROG_ABI_KIND_SKB,displacement+(index_mode?(2U<<scale):0));
    if(a.after[reg]!=want||a.raw_after[reg]!=raw||a.tags_after[reg]!=tag){fprintf(stderr,"CPU register op=%u source=%u width=%u dst=%u reg=%u profile=%u li=%u got=%llx expected=%llx tag=%u expectedtag=%u\n",op,source,width,dst,reg,profile,li,a.after[reg],want,a.tags_after[reg],tag);return 1;}
   }cases++;
  }
 }printf("x86 MOV memory frame host/CPU cross-check: OK (%lu cases, %lu live XDP RSP cases)\n",cases,xdp_cases);return 0;
}
