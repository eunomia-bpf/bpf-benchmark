/* Compare memory ALU direct/interpreter bodies with real x86 arithmetic,
 * six defined flags, complete buffers and unchanged numeric/tag frames. */
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
#include <string.h>
#include <stdlib.h>
static __u8 heap[512],native_stack[512];
static const __u64 values[]={0,1,15,16,31,32,63,64,255,256,0x7f,0x80,0x7fff,0x8000,0x7fffffff,0x80000000ULL,0x7fffffffffffffffULL,0x8000000000000000ULL,0xffffffffffffffffULL};
#define VALUE_COUNT (sizeof(values)/sizeof(values[0]))
static const unsigned operations[]={0,1,2,3,4,5,6,7,8,12,15};
unsigned long native_lab_entry_input(unsigned kind){(void)kind;abort();}
unsigned long native_lab_exclusive_failure_choice(unsigned site){(void)site;abort();}
static void put(__u8 *p,unsigned width,__u64 value){for(unsigned i=0;i<width;i++)p[i]=(__u8)(value>>(i*8));}
static __u64 flags_word(unsigned seed){return ((seed&1)?1:0)|((seed&2)?4:0)|((seed&4)?16:0)|((seed&8)?64:0)|((seed&16)?128:0)|((seed&32)?2048:0);}
struct observation{__u64 numeric[16],flags;__u8 tags[16],heap[512],stack[512];unsigned changed;};
#define EXEC_CPU(OP,TYPE,SUFFIX) do{volatile TYPE *p=(volatile TYPE *)address;asm volatile("pushq %[old]; popfq; " OP SUFFIX " %[right],%[dst]; pushfq; popq %[flags]" :[dst]"+m"(*p),[flags]"=&r"(result):[right]"r"((TYPE)right),[old]"r"(old|2):"cc","memory");}while(0)
#define SHIFT_CPU(OP,TYPE,SUFFIX) do{volatile TYPE *p=(volatile TYPE *)address;asm volatile("pushq %[old]; popfq; " OP SUFFIX " %%cl,%[dst]; pushfq; popq %[flags]" :[dst]"+m"(*p),[flags]"=&r"(result):"c"((__u8)right),[old]"r"(old|2):"cc","memory");}while(0)
#define WIDTHS(M,OP) do{switch(width){case 1:M(OP,__u8,"b");break;case 2:M(OP,__u16,"w");break;case 4:M(OP,__u32,"l");break;case 8:M(OP,__u64,"q");break;default:abort();}}while(0)
static __u64 cpu(unsigned op,unsigned width,__u8 *address,__u64 right,__u64 old){__u64 result;switch(op){
case 0:WIDTHS(EXEC_CPU,"add");break;case 1:WIDTHS(EXEC_CPU,"sub");break;
case 2:WIDTHS(EXEC_CPU,"xor");break;case 3:WIDTHS(EXEC_CPU,"or");break;case 4:WIDTHS(EXEC_CPU,"and");break;
case 5:WIDTHS(SHIFT_CPU,"shl");break;case 6:WIDTHS(SHIFT_CPU,"shr");break;case 7:WIDTHS(SHIFT_CPU,"sar");break;case 8:WIDTHS(SHIFT_CPU,"rol");break;
case 12:WIDTHS(EXEC_CPU,"sbb");break;case 15:WIDTHS(EXEC_CPU,"adc");break;default:abort();}return result;}
static __u64 defined(unsigned op,unsigned width,__u64 right){__u64 mask=0x8d5;if(op>=2&&op<=4)return mask&~16ULL;if(op>=5&&op<=8){unsigned n=right&(width==8?63:31);if(n){if(op!=8)mask&=~16ULL;if(n!=1)mask&=~2048ULL;if((op==5||op==6)&&n>=width*8)mask&=~1ULL;}}return mask;}
static __u64 seed(unsigned reg){return 0x1122334455667788ULL+reg*0x102030405ULL;}
static __u64 immediate(__u64 raw,unsigned width){__u64 v=(__u32)raw;if(width==8&&(v&0x80000000ULL))v|=0xffffffff00000000ULL;return v;}
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned direct,unsigned imm,unsigned op,unsigned flags,
 unsigned profile,unsigned index_mode,int displacement,__u64 left,unsigned ri,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();
 __u32 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),X86_WIDTH_64);
 /* This valid-access oracle owns the complete512-byte native frame. */
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 X86_SIM_L_WRITE_REG_WIDTH(X86_R8,2,X86_WIDTH_64);
 unsigned base=profile==1?X86_RSP:X86_RDI;
 if(profile==0)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&heap[256],X86_SIM_TAG_SCALAR);
 if(profile==2)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned width=flags?flags:8,index=index_mode?X86_R8:X86_REG_NONE,scale=index_mode?index_mode-1:0;
 unsigned source=ri<VALUE_COUNT?X86_RAX:ri==VALUE_COUNT?X86_RSP:ri==VALUE_COUNT+1?X86_RDX:X86_RDI;
 __u64 right=ri<VALUE_COUNT?values[ri]:0;
 if(op>=5&&op<=8){source=X86_RCX;X86_SIM_L_WRITE_REG_WIDTH(X86_RCX,right,X86_WIDTH_64);}
 else if(ri<VALUE_COUNT)X86_SIM_L_WRITE_REG_WIDTH(X86_RAX,right,X86_WIDTH_64);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);}
 unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
 __u8 *target=profile?(__u8 *)(void *)__x86_stack_mem.b+offset:heap+offset;put(target,width,left);
 __u64 old=flags_word(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 __u64 before[16];__u8 tags[16];for(unsigned reg=0;reg<16;reg++){before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);tags[reg]=X86_SIM_L_REG_TAG(reg);}
 __u32 aux=X86_MEM_AUX(index,scale)|X86_MEM_AUX_ALU_OP(op);
 __u64 value=imm?(((__u64)(__u32)displacement<<32)|(__u32)right):(__u64)(__s64)displacement;
 if(direct){if(imm)X86_SIM_L_EXEC_ALU_MEM_IMM(base,flags,aux,value);else X86_SIM_L_EXEC_ALU_MEM_REG(base,source,flags,aux,value);}
 else X86_SIM_L_EXEC(imm?X86_OP_ALU_MEM_IMM:X86_OP_ALU_MEM_REG,base,source,flags,aux,value);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->numeric[reg]=X86_SIM_L_READ_REG(reg);out->tags[reg]=X86_SIM_L_REG_TAG(reg);if(before[reg]!=(__u64)(long)X86_SIM_L_REG_VALUE(reg)||tags[reg]!=out->tags[reg])out->changed++;}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
int main(void){const unsigned widths[]={0,1,2,4,8};unsigned long count=0;
 for(unsigned imm=0;imm<2;imm++)for(unsigned oi=0;oi<11;oi++)for(unsigned wi=0;wi<5;wi++)
 for(unsigned profile=0;profile<3;profile++)for(unsigned flagseed=0;flagseed<64;flagseed++)
 for(unsigned li=0;li<VALUE_COUNT;li++)for(unsigned ri=0;ri<(imm|| (operations[oi]>=5&&operations[oi]<=8)?VALUE_COUNT:VALUE_COUNT+3);ri++){
  unsigned op=operations[oi],width=widths[wi]?widths[wi]:8,index_mode=(li+ri+flagseed)%5,scale=index_mode?index_mode-1:0;
  int displacement=(li+ri)&1?-16:16;if(profile==1)displacement+=32;unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
  struct observation a,b;simulate(&a,1,imm,op,widths[wi],profile,index_mode,displacement,values[li],ri,flagseed);simulate(&b,0,imm,op,widths[wi],profile,index_mode,displacement,values[li],ri,flagseed);
  if(memcmp(&a,&b,sizeof(a))||a.changed){fprintf(stderr,"direct/interpreter op=%u width=%u profile=%u li=%u ri=%u\n",op,width,profile,li,ri);return 1;}
  __u64 right=ri<VALUE_COUNT?values[ri]:ri==VALUE_COUNT?(__u64)(long)&native_stack[0]:ri==VALUE_COUNT+1?(__u64)(long)&native_stack[160]:profile==0?(__u64)(long)&heap[256]:profile==1?seed(X86_RDI):(__u64)(long)&native_stack[160];
  if(imm)right=immediate(right,width);
  for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);}
  __u8 *target=profile?native_stack+offset:heap+offset;put(target,width,values[li]);__u64 native=cpu(op,width,target,right,flags_word(flagseed)),mask=defined(op,width,right);
  if(memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||((a.flags^native)&mask)){fprintf(stderr,"CPU op=%u width=%u profile=%u flags=%u li=%u ri=%u got=%llx native=%llx mask=%llx\n",op,width,profile,flagseed,li,ri,(unsigned long long)a.flags,(unsigned long long)native,(unsigned long long)mask);return 1;}
  count++;
 }
 printf("x86 memory ALU frame host/CPU cross-check: OK (%lu cases)\n",count);return 0;
}
