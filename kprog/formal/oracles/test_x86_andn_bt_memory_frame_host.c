/* ANDN/BT memory bodies against actual direct/interpreter routes and CPU:
 * high32 displacement, low immediate/index, AUX base and memory width,
 * incoming aliases, numeric RSP/STACK, actual PF write and full frame. */
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
unsigned long native_lab_entry_input(unsigned kind){(void)kind;abort();}
unsigned long native_lab_exclusive_failure_choice(unsigned site){(void)site;abort();}
static __u64 flagword(unsigned seed){return ((seed&1)?1:0)|((seed&2)?4:0)|((seed&4)?16:0)|((seed&8)?64:0)|((seed&16)?128:0)|((seed&32)?2048:0);}
static void put(__u8 *p,unsigned width,__u64 value){for(unsigned i=0;i<width;i++)p[i]=value>>(i*8);}
static __u64 seed(unsigned reg){return 0x1122334455667788ULL+reg*0x102030405ULL;}
struct observation{__u64 before[16],after[16],raw_before[16],raw_after[16],flags;__u8 tags_before[16],tags_after[16],heap[512],stack[512];};
struct cpu_result{__u64 value,flags;};
#define ANDN(TYPE,SUFFIX) do{TYPE value;asm volatile("pushq %[old]; popfq; andn" SUFFIX " %[memory],%[first],%[value]; pushfq; popq %[flags]" :[value]"=&r"(value),[flags]"=&r"(out.flags):[memory]"m"(*(const TYPE *)address),[first]"r"((TYPE)first),[old]"r"(old|2):"cc","memory");out.value=value;}while(0)
#define BT(IMM,TYPE,SUFFIX) do{asm volatile("pushq %[old]; popfq; bt" SUFFIX " $" IMM ",%[memory]; pushfq; popq %[flags]" :[flags]"=&r"(out.flags):[memory]"m"(*(const TYPE *)address),[old]"r"(old|2):"cc","memory");out.value=0;}while(0)
#define BTCASE(N) case N:if(width==2)BT(#N,__u16,"w");else if(width==4)BT(#N,__u32,"l");else BT(#N,__u64,"q");break
static struct cpu_result cpu(unsigned form,unsigned width,const __u8 *address,__u64 first,unsigned index,__u64 old){struct cpu_result out;
 if(form==0){if(width==4)ANDN(__u32,"l");else ANDN(__u64,"q");}
 else switch(index){BTCASE(0);BTCASE(1);BTCASE(15);BTCASE(16);BTCASE(31);BTCASE(32);BTCASE(63);BTCASE(64);BTCASE(127);BTCASE(128);BTCASE(255);default:abort();}
 return out;
}
static const unsigned indices[]={0,1,15,16,31,32,63,64,127,128,255};
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned specialized,unsigned form,unsigned count_index,unsigned flags,unsigned dst,
 unsigned profile,unsigned index_mode,int displacement,__u64 left,__u64 right,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned count_reg=(flagseed+count_index)%16;
 X86_SIM_L_WRITE_REG_WIDTH(count_reg,left,X86_WIDTH_64);
 X86_SIM_L_WRITE_REG_WIDTH(X86_R8,2,X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned base=profile==1?X86_RSP:X86_RDI;
 if(profile==0||profile==3)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&heap[256],profile==3?X86_SIM_TAG_ABI:X86_SIM_TAG_SCALAR);
 if(profile==2)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 if(dst!=X86_RSP&&dst!=X86_RDX&&dst!=base&&dst!=X86_R8&&dst!=count_reg)X86_SIM_L_WRITE_REG_WIDTH(dst,left,X86_WIDTH_64);
 unsigned width=flags?flags:8,index=index_mode?X86_R8:X86_REG_NONE,scale=index_mode?index_mode-1:0;
 unsigned offset=((profile==0||profile==3)?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);}
 put(profile==1||profile==2?(__u8 *)(void *)__x86_stack_mem.b+offset:heap+offset,width,right);
 __u64 old=flagword(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->before[reg]=X86_SIM_L_READ_REG(reg);out->tags_before[reg]=X86_SIM_L_REG_TAG(reg);out->raw_before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 __u32 aux=X86_MEM_AUX_FULL(index,scale,form?(flagseed^0xa5):(count_index?width:0))|X86_MEM_AUX_ALU_OP(form?(flagseed^0x5a):base);
 __u64 packed=((__u64)(__u32)displacement<<32)|0x3a659800U|(form?indices[count_index]:(flagseed^0x5a));
 if(specialized){
  if(form)X86_SIM_L_EXEC_BT_MEM_IMM(base,flags,aux,packed);
  else X86_SIM_L_EXEC_ANDN_MEM(dst,count_reg,flags,aux,packed);
 }else{unsigned opcode=form?X86_OP_BT_MEM_IMM:X86_OP_ANDN_MEM;X86_SIM_L_EXEC(opcode,form?base:dst,count_reg,flags,aux,packed);}
 for(unsigned reg=0;reg<16;reg++){out->after[reg]=X86_SIM_L_READ_REG(reg);out->tags_after[reg]=X86_SIM_L_REG_TAG(reg);out->raw_after[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
int main(void){const unsigned widths[]={0,2,4,8};unsigned long cases=0;
 if(!__builtin_cpu_supports("bmi")){fprintf(stderr,"BMI1 hardware required\n");return 1;}
 for(unsigned wi=0;wi<4;wi++)for(unsigned form=0;form<2;form++){
 if(!form&&widths[wi]==2)continue;
 for(unsigned ci=0;ci<(form?sizeof(indices)/sizeof(indices[0]):2);ci++)for(unsigned dst=0;dst<16;dst++)for(unsigned profile=0;profile<4;profile++)
 for(unsigned fs=0;fs<64;fs++)for(unsigned li=0;li<NVALUES;li++){
  unsigned width=widths[wi]?widths[wi]:8,index_mode=(li+ci+fs)%5,scale=index_mode?index_mode-1:0;
  int displacement=(li+ci)&1?-16:16;if(profile==1)displacement+=32;unsigned offset=((profile==0||profile==3)?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
  struct observation a,b;__u64 left=values[(li+fs)%NVALUES];
  simulate(&a,1,form,ci,widths[wi],dst,profile,index_mode,displacement,left,values[li],fs);
  simulate(&b,0,form,ci,widths[wi],dst,profile,index_mode,displacement,left,values[li],fs);
  if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"direct/interpreter width=%u form=%u dst=%u profile=%u field=%u\n",width,form,dst,profile,ci);return 1;}
  for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);}unsigned stack=profile==1||profile==2;put(stack?native_stack+offset:heap+offset,width,values[li]);
  __u64 first=a.before[(fs+ci)%16];struct cpu_result expected=cpu(form,width,stack?native_stack+offset:heap+offset,first,form?indices[ci]:0,flagword(fs));
  __u64 write=width==4?(__u32)expected.value:expected.value;
  __u64 flagmask=form?1:0x8c1,flags=(flagword(fs)&~flagmask)|(expected.flags&flagmask);
  if(!form)flags &= ~(4ULL|16ULL);
  /* Released stack bytes use the fixed host fresh word0; live bytes retain exact CPU comparison. */
  if(dst==X86_RSP&&!form){__s64 released=(__s64)(write-(__u64)(long)&native_stack[512]);for(unsigned i=0;i<512;i++)if((__s64)i-512<released)native_stack[i]=0;}
  if(memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||a.flags!=flags){
   fprintf(stderr,"CPU flags/memory width=%u form=%u dst=%u profile=%u fs=%u source=%u field=%u got=%llx expected=%llx\n",width,form,dst,profile,fs,li,ci,a.flags,flags);return 1;}
  for(unsigned reg=0;reg<16;reg++){
   unsigned writing=!form&&reg==dst;__u64 want=writing?write:a.before[reg],raw=writing?(reg==X86_RSP?write-(__u64)(long)&native_stack[512]:write):a.raw_before[reg];
   unsigned tag=writing?X86_SIM_TAG_SCALAR:a.tags_before[reg];
   if(a.after[reg]!=want||a.raw_after[reg]!=raw||a.tags_after[reg]!=tag){fprintf(stderr,"CPU register width=%u form=%u dst=%u reg=%u profile=%u source=%u field=%u got=%llx expected=%llx\n",width,form,dst,reg,profile,li,ci,a.after[reg],want);return 1;}
  }cases++;
 }}
 printf("x86 ANDN/BT memory frame direct/interpreter/CPU cross-check: OK (%lu cases)\n",cases);return 0;
}
