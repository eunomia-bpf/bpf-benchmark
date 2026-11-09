/* SHIFTX/RORX memory forms against actual generic production bodies and CPU:
 * packed displacement/payload, incoming count/address aliases, numeric RSP
 * and STACK writeback, complete registers/tags/flags and memory images. */
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
#define SHIFT(OP,TYPE,SUFFIX) do{TYPE value;asm volatile("pushq %[old]; popfq; " OP SUFFIX " %[count],%[memory],%[value]; pushfq; popq %[flags]" :[value]"=&r"(value),[flags]"=&r"(out.flags):[memory]"m"(*(const TYPE *)address),[count]"r"((TYPE)count),[old]"r"(old|2):"cc","memory");out.value=value;}while(0)
#define ROT(IMM,TYPE,SUFFIX) do{TYPE value;asm volatile("pushq %[old]; popfq; rorx" SUFFIX " $" IMM ",%[memory],%[value]; pushfq; popq %[flags]" :[value]"=&r"(value),[flags]"=&r"(out.flags):[memory]"m"(*(const TYPE *)address),[old]"r"(old|2):"cc","memory");out.value=value;}while(0)
#define ROTCASE(N) case N:if(width==4)ROT(#N,__u32,"l");else ROT(#N,__u64,"q");break
static struct cpu_result cpu(unsigned form,unsigned width,const __u8 *address,__u64 count,__u64 old){struct cpu_result out;
 if(form==0){if(width==4)SHIFT("shlx",__u32,"l");else SHIFT("shlx",__u64,"q");}
 else if(form==1){if(width==4)SHIFT("shrx",__u32,"l");else SHIFT("shrx",__u64,"q");}
 else if(form==2){if(width==4)SHIFT("sarx",__u32,"l");else SHIFT("sarx",__u64,"q");}
 else switch(count){ROTCASE(0);ROTCASE(1);ROTCASE(15);ROTCASE(16);ROTCASE(31);ROTCASE(32);ROTCASE(63);ROTCASE(64);ROTCASE(127);ROTCASE(128);ROTCASE(255);default:abort();}
 return out;
}
static const unsigned rotations[]={0,1,15,16,31,32,63,64,127,128,255};
static const unsigned shifts[]={X86_ALU_SHL,X86_ALU_SHR,X86_ALU_SAR};
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned specialized,unsigned form,unsigned count_index,unsigned flags,unsigned dst,
 unsigned profile,unsigned index_mode,int displacement,__u64 left,__u64 right,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned count_reg=(flagseed+count_index)%16;
 X86_SIM_L_WRITE_REG_WIDTH(count_reg,values[count_index%NVALUES],X86_WIDTH_64);
 X86_SIM_L_WRITE_REG_WIDTH(X86_R8,2,X86_WIDTH_64);
 __x86_rsp.ptr=(void *)(long)-512;
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned base=profile==1?X86_RSP:X86_RDI;
 if(profile==0)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,&heap[256],X86_SIM_TAG_SCALAR);
 if(profile==2)X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 if(dst!=X86_RSP&&dst!=X86_RDX&&dst!=base&&dst!=X86_R8&&dst!=count_reg)X86_SIM_L_WRITE_REG_WIDTH(dst,left,X86_WIDTH_64);
 unsigned width=flags?flags:8,index=index_mode?X86_R8:X86_REG_NONE,scale=index_mode?index_mode-1:0;
 unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);}
 put(profile?(__u8 *)(void *)__x86_stack_mem.b+offset:heap+offset,width,right);
 __u64 old=flagword(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->before[reg]=X86_SIM_L_READ_REG(reg);out->tags_before[reg]=X86_SIM_L_REG_TAG(reg);out->raw_before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 __u32 aux=X86_MEM_AUX_FULL(index,scale,flagseed^0xa5)|X86_MEM_AUX_ALU_OP(form==3?(flagseed^0x5a):count_reg);
 __u64 packed=((__u64)(__u32)displacement<<32)|0x5a36b700U|(form==3?rotations[count_index]:shifts[form]);
 if(specialized){
  if(form==3)X86_SIM_RUN_OP(X86_OP_RORX_MEM,dst,base,flags,aux,packed);
  else X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM,dst,base,flags,aux,packed);
 }else{unsigned opcode=form==3?X86_OP_RORX_MEM:X86_OP_SHIFTX_MEM;X86_SIM_L_EXEC(opcode,dst,base,flags,aux,packed);}
 for(unsigned reg=0;reg<16;reg++){out->after[reg]=X86_SIM_L_READ_REG(reg);out->tags_after[reg]=X86_SIM_L_REG_TAG(reg);out->raw_after[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
int main(void){const unsigned widths[]={0,4,8};unsigned long cases=0;
 if(!__builtin_cpu_supports("bmi2")){fprintf(stderr,"BMI2 hardware required\n");return 1;}
 for(unsigned wi=0;wi<3;wi++)for(unsigned form=0;form<4;form++)
 for(unsigned ci=0;ci<(form==3?sizeof(rotations)/sizeof(rotations[0]):NVALUES);ci++)
 for(unsigned dst=0;dst<16;dst++)for(unsigned profile=0;profile<3;profile++)
 for(unsigned fs=0;fs<64;fs++)for(unsigned li=0;li<NVALUES;li++){
  unsigned width=widths[wi]?widths[wi]:8,index_mode=(li+ci+fs)%5,scale=index_mode?index_mode-1:0;
  int displacement=(li+ci)&1?-16:16;if(profile==1)displacement+=32;unsigned offset=(profile==0?256:profile==1?0:160)+displacement+(index_mode?(2U<<scale):0);
  struct observation a,b;__u64 left=values[(li+fs)%NVALUES];
  simulate(&a,1,form,ci,widths[wi],dst,profile,index_mode,displacement,left,values[li],fs);
  simulate(&b,0,form,ci,widths[wi],dst,profile,index_mode,displacement,left,values[li],fs);
  if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"specialized/interpreter width=%u form=%u dst=%u profile=%u count=%u\n",width,form,dst,profile,ci);return 1;}
  for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);}put(profile?native_stack+offset:heap+offset,width,values[li]);
  __u64 count=form==3?rotations[ci]:a.before[(fs+ci)%16];
  struct cpu_result expected=cpu(form,width,profile?native_stack+offset:heap+offset,count,flagword(fs));
  __u64 write=width==4?(__u32)expected.value:expected.value;
  /* Released stack bytes use the fixed host fresh word0; live bytes retain exact CPU comparison. */
  if(dst==X86_RSP){__s64 released=(__s64)(write-(__u64)(long)&native_stack[512]);for(unsigned i=0;i<512;i++)if((__s64)i-512<released)native_stack[i]=0;}
  if(memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||a.flags!=flagword(fs)||((expected.flags^flagword(fs))&0x8d5)){
   fprintf(stderr,"CPU flags/memory width=%u form=%u dst=%u profile=%u fs=%u source=%u count=%u got=%llx expected=%llx\n",width,form,dst,profile,fs,li,ci,a.flags,flagword(fs));return 1;}
  for(unsigned reg=0;reg<16;reg++){
   __u64 want=reg==dst?write:a.before[reg],raw=reg==dst?(reg==X86_RSP?write-(__u64)(long)&native_stack[512]:write):a.raw_before[reg];
   unsigned tag=reg==dst?X86_SIM_TAG_SCALAR:a.tags_before[reg];
   if(a.after[reg]!=want||a.raw_after[reg]!=raw||a.tags_after[reg]!=tag){fprintf(stderr,"CPU register width=%u form=%u dst=%u reg=%u profile=%u source=%u count=%u got=%llx expected=%llx\n",width,form,dst,reg,profile,li,ci,a.after[reg],want);fprintf(stderr,"actual count=%llx beforedst=%llx cpu=%llx flags=%llx\n",count,a.before[dst],expected.value,expected.flags);return 1;}
  }cases++;
 }
 printf("x86 BMI memory frame specialized/interpreter/CPU cross-check: OK (%lu cases)\n",cases);return 0;
}
