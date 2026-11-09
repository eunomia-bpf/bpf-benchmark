/* Real CPU memory-source ALU/IMUL against actual direct/interpreter bodies:
 * exact six defined flags, captured aliased addresses, scalarizing writes,
 * complete numeric/tag/raw register cells and unchanged guest buffers. */
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
static const unsigned operations[]={0,1,2,3,4,9,12,15};
unsigned long native_lab_entry_input(unsigned kind){(void)kind;abort();}
unsigned long native_lab_exclusive_failure_choice(unsigned site){(void)site;abort();}
static __u64 flagword(unsigned seed){return ((seed&1)?1:0)|((seed&2)?4:0)|((seed&4)?16:0)|((seed&8)?64:0)|((seed&16)?128:0)|((seed&32)?2048:0);}
static void put(__u8 *p,unsigned width,__u64 value){for(unsigned i=0;i<width;i++)p[i]=value>>(i*8);}
static __u64 seed(unsigned reg){return 0x1122334455667788ULL+reg*0x102030405ULL;}
struct observation{__u64 before[16],after[16],raw_before[16],raw_after[16],flags;__u8 tags_before[16],tags_after[16],heap[512],stack[512];};
struct cpu_result{__u64 value,flags;};
#define CPU(OP,TYPE,SUFFIX) do{TYPE value=(TYPE)left;asm volatile("pushq %[old]; popfq; " OP SUFFIX " %[memory],%[value]; pushfq; popq %[flags]" :[value]"+r"(value),[flags]"=&r"(out.flags):[memory]"m"(*(const TYPE *)address),[old]"r"(old|2):"cc","memory");out.value=value;}while(0)
#define WIDTHS(OP) do{switch(width){case 1:CPU(OP,__u8,"b");break;case 2:CPU(OP,__u16,"w");break;case 4:CPU(OP,__u32,"l");break;case 8:CPU(OP,__u64,"q");break;default:abort();}}while(0)
static struct cpu_result cpu(unsigned op,unsigned width,__u64 left,const __u8 *address,__u64 old){struct cpu_result out;switch(op){
case 0:WIDTHS("add");break;case 1:WIDTHS("sub");break;case 2:WIDTHS("xor");break;case 3:WIDTHS("or");break;case 4:WIDTHS("and");break;case 12:WIDTHS("sbb");break;case 15:WIDTHS("adc");break;
case 9:switch(width){case 2:CPU("imul",__u16,"w");break;case 4:CPU("imul",__u32,"l");break;case 8:CPU("imul",__u64,"q");break;default:abort();}break;default:abort();}return out;}
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned direct,unsigned op,unsigned flags,unsigned dst,
 unsigned profile,unsigned index_mode,int displacement,__u64 left,__u64 right,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 X86_SIM_L_WRITE_REG_WIDTH(X86_R8,2,X86_WIDTH_64);
 unsigned base=profile==1?X86_RSP:X86_RDI;
 if(profile==0)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&heap[256],X86_SIM_TAG_SCALAR);
 if(profile==2)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 if(dst!=X86_RSP&&dst!=X86_RDX&&dst!=base&&dst!=X86_R8)X86_SIM_L_WRITE_REG_WIDTH(dst,left,X86_WIDTH_64);
 unsigned width=flags?flags:8,index=index_mode?X86_R8:X86_REG_NONE,scale=index_mode?index_mode-1:0;
 unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);}
 put(profile?(__u8 *)(void *)__x86_stack_mem.b+offset:heap+offset,width,right);
 __u64 old=flagword(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->before[reg]=X86_SIM_L_READ_REG(reg);out->tags_before[reg]=X86_SIM_L_REG_TAG(reg);out->raw_before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 __u32 aux=X86_MEM_AUX(index,scale)|X86_MEM_AUX_ALU_OP(op);
 if(direct)X86_SIM_L_EXEC_ALU_MEM(dst,base,flags,aux,(__u64)(__s64)displacement);
 else X86_SIM_L_EXEC(X86_OP_ALU_MEM,dst,base,flags,aux,(__u64)(__s64)displacement);
 for(unsigned reg=0;reg<16;reg++){out->after[reg]=X86_SIM_L_READ_REG(reg);out->tags_after[reg]=X86_SIM_L_REG_TAG(reg);out->raw_after[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
int main(void){const unsigned widths[]={0,1,2,4,8};unsigned long cases=0;
 for(unsigned oi=0;oi<8;oi++)for(unsigned wi=0;wi<5;wi++){
  unsigned op=operations[oi],width=widths[wi]?widths[wi]:8;if(op==9&&width==1)continue;
  for(unsigned dst=0;dst<16;dst++)for(unsigned profile=0;profile<3;profile++)for(unsigned fs=0;fs<64;fs++)
  for(unsigned li=0;li<NVALUES;li++)for(unsigned rj=0;rj<(dst==X86_RAX?NVALUES:3);rj++){
   unsigned ri=dst==X86_RAX?rj:rj==0?0:rj==1?li:NVALUES-1,index_mode=(li+ri+fs)%5,scale=index_mode?index_mode-1:0;
   int displacement=(li+ri)&1?-16:16;if(profile==1)displacement+=32;unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
   struct observation a,b;simulate(&a,1,op,widths[wi],dst,profile,index_mode,displacement,values[li],values[ri],fs);simulate(&b,0,op,widths[wi],dst,profile,index_mode,displacement,values[li],values[ri],fs);
   if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"direct/interpreter op=%u width=%u dst=%u profile=%u\n",op,width,dst,profile);return 1;}
   for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);}put(profile?native_stack+offset:heap+offset,width,values[ri]);
   struct cpu_result expected=cpu(op,width,a.before[dst],profile?native_stack+offset:heap+offset,flagword(fs));
   __u64 mask=width==8?~0ULL:(1ULL<<(width*8))-1,write=expected.value&mask;
   if(width==1||width==2)write|=a.before[dst]&~mask;
   __u64 fm=op==9?0x801:op>=2&&op<=4?0x8c5:0x8d5;
   /* Released stack bytes use the fixed host fresh word0; live bytes retain exact CPU comparison. */
  if(dst==X86_RSP){__s64 released=(__s64)(write-(__u64)(long)&native_stack[512]);for(unsigned i=0;i<512;i++)if((__s64)i-512<released)native_stack[i]=0;}
  if(memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||((a.flags^expected.flags)&fm)){fprintf(stderr,"CPU flags/memory op=%u width=%u dst=%u profile=%u fs=%u li=%u ri=%u got=%llx expected=%llx\n",op,width,dst,profile,fs,li,ri,a.flags,expected.flags);return 1;}
   for(unsigned reg=0;reg<16;reg++){
    __u64 want=reg==dst?write:a.before[reg],raw=reg==dst?(reg==X86_RSP?write-(__u64)(long)&native_stack[512]:write):a.raw_before[reg];
    unsigned tag=reg==dst?X86_SIM_TAG_SCALAR:a.tags_before[reg];
    if(a.after[reg]!=want||a.raw_after[reg]!=raw||a.tags_after[reg]!=tag){fprintf(stderr,"CPU register op=%u width=%u dst=%u reg=%u profile=%u li=%u ri=%u\n",op,width,dst,reg,profile,li,ri);return 1;}
   }
   cases++;
  }
 }
 printf("x86 memory-source ALU frame host/CPU cross-check: OK (%lu cases)\n",cases);return 0;
}
