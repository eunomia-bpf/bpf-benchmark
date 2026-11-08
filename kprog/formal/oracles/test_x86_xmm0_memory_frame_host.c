/* XMM0 two-lane moves against actual production routes and MOVUPS/MOVAPS:
 * all base cells, absolute indexed SIB, RSP/STACK/ABI, complete GPR/tag/flag
 * and vector frames, three full byte images and alignment-safe native moves. */
#define _GNU_SOURCE
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
#include <sys/mman.h>
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
struct observation{__u64 before[16],after[16],raw_before[16],raw_after[16],flags,lo,hi;__u8 tags_before[16],tags_after[16],heap[512],stack[512],absolute[512];};
static __u8 *absolute;
static __u8 native_absolute[512];
struct pair{__u64 lo,hi;};
struct cpu_result{struct pair pair;__u64 flags;};
static struct cpu_result cpu(unsigned store,unsigned aligned,__u8 *address,struct pair input,__u64 old){struct cpu_result out;out.pair=input;
#define CPU_LOAD(OP) asm volatile("pushq %[old]; popfq; " OP " %[memory],%%xmm0; movups %%xmm0,%[out]; pushfq; popq %[flags]" :[out]"=m"(out.pair),[flags]"=&r"(out.flags):[memory]"m"(*(const struct pair *)address),[old]"r"(old|2):"xmm0","cc","memory")
#define CPU_STORE(OP) asm volatile("pushq %[old]; popfq; movups %[in],%%xmm0; " OP " %%xmm0,%[memory]; pushfq; popq %[flags]" :[memory]"=m"(*(struct pair *)address),[flags]"=&r"(out.flags):[in]"m"(input),[old]"r"(old|2):"xmm0","cc","memory")
 if(store){if(aligned)CPU_STORE("movaps");else CPU_STORE("movups");}
 else{if(aligned)CPU_LOAD("movaps");else CPU_LOAD("movups");}return out;
}
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned direct,unsigned store,unsigned base_reg,unsigned profile,unsigned index_mode,int displacement,unsigned misalignment,unsigned li,unsigned flagseed){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[512];
 for(unsigned reg=0;reg<16;reg++)X86_SIM_L_WRITE_REG_WIDTH(reg,seed(reg),8);
 __x86_rsp.ptr=(void *)(long)-256;X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);
 unsigned base=profile==3?X86_REG_NONE:base_reg,index_reg=base==X86_R8?X86_R9:X86_R8;
 X86_SIM_L_WRITE_REG_WIDTH(index_reg,16,8);
 if(base!=X86_REG_NONE&&base!=X86_RSP){if(profile==1)X86_SIM_L_WRITE_REG_PTR_TAG(base,(void *)&__x86_stack_mem.b[160],X86_SIM_TAG_STACK);else X86_SIM_L_WRITE_REG_PTR_TAG(base,&heap[256],profile==2?X86_SIM_TAG_ABI:X86_SIM_TAG_SCALAR);}
 unsigned scale=index_mode?index_mode-1:0,index=index_mode?index_reg:X86_REG_NONE;
 unsigned origin=profile==3?128:base==X86_RSP?256:profile==1?160:256;
 unsigned offset=origin+displacement+misalignment+(index_mode?(16U<<scale):0);
 for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);__x86_stack_mem.b[i]=(__u8)(i*7+0x85);absolute[i]=(__u8)(i*7+0x85);}
 __u8 *memory=profile==3?absolute:base==X86_RSP||profile==1?(__u8 *)(void *)__x86_stack_mem.b:heap;
 put(memory+offset,8,values[li]);put(memory+offset+8,8,values[(li+7)%NVALUES]);
 __x86_xmm0_lo=values[(li+5)%NVALUES];__x86_xmm0_hi=~values[(li+9)%NVALUES];
 __u64 old=flagword(flagseed);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned reg=0;reg<16;reg++){out->before[reg]=X86_SIM_L_READ_REG(reg);out->tags_before[reg]=X86_SIM_L_REG_TAG(reg);out->raw_before[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 __u32 aux=X86_MEM_AUX_FULL(index,scale,flagseed^0xa5)|X86_MEM_AUX_ALU_OP(flagseed^0x5a);
 __u64 immediate=profile==3?(__u64)(long)(absolute+origin+displacement+misalignment):(__u64)(__s64)(displacement+(int)misalignment);
 if(direct){if(store)X86_SIM_L_EXEC_STORE_XMM0(base,aux,immediate);else X86_SIM_L_EXEC_LOAD_XMM0(base,aux,immediate);}
 else{unsigned opcode=store?X86_OP_STORE_XMM0:X86_OP_LOAD_XMM0;X86_SIM_L_EXEC(opcode,store?base:flagseed,store?flagseed:base,flagseed,aux,immediate);}
 for(unsigned reg=0;reg<16;reg++){out->after[reg]=X86_SIM_L_READ_REG(reg);out->tags_after[reg]=X86_SIM_L_REG_TAG(reg);out->raw_after[reg]=(__u64)(long)X86_SIM_L_REG_VALUE(reg);}
 out->lo=__x86_xmm0_lo;out->hi=__x86_xmm0_hi;out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);
 memcpy(out->heap,heap,512);memcpy(out->absolute,absolute,512);for(unsigned i=0;i<512;i++)out->stack[i]=__x86_stack_mem.b[i];
}
int main(void){unsigned long cases=0,aligned_cases=0;
 absolute=mmap((void *)0x10000000,4096,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED_NOREPLACE,-1,0);if(absolute==MAP_FAILED){perror("XMM fixture mmap");return 1;}
 for(unsigned store=0;store<2;store++)for(unsigned base=0;base<16;base++)for(unsigned profile=0;profile<4;profile++)for(unsigned im=0;im<5;im++)for(unsigned fs=0;fs<64;fs++)for(unsigned li=0;li<NVALUES;li++){
  unsigned scale=im?im-1:0,origin=profile==3?128:base==X86_RSP?256:profile==1?160:256,misalignment=li%16;int displacement=li&1?-32:32;
  unsigned offset=origin+displacement+misalignment+(im?(16U<<scale):0),stack=profile!=3&&(base==X86_RSP||profile==1);
  struct observation a,b;simulate(&a,1,store,base,profile,im,displacement,misalignment,li,fs);simulate(&b,0,store,base,profile,im,displacement,misalignment,li,fs);
  if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"XMM direct/interpreter store=%u base=%u profile=%u index=%u\n",store,base,profile,im);return 1;}
  for(unsigned i=0;i<512;i++){heap[i]=(__u8)(i*7+0x85);native_stack[i]=(__u8)(i*7+0x85);native_absolute[i]=(__u8)(i*7+0x85);}
  __u8 *memory=profile==3?native_absolute:stack?native_stack:heap;put(memory+offset,8,values[li]);put(memory+offset+8,8,values[(li+7)%NVALUES]);
  unsigned aligned=!((__u64)(long)(memory+offset)&15)&&(fs&1);struct pair input={values[(li+5)%NVALUES],~values[(li+9)%NVALUES]};struct cpu_result expected=cpu(store,aligned,memory+offset,input,flagword(fs));
  if(a.lo!=expected.pair.lo||a.hi!=expected.pair.hi||a.flags!=flagword(fs)||((expected.flags^flagword(fs))&0x8d5)||memcmp(a.heap,heap,512)||memcmp(a.stack,native_stack,512)||memcmp(a.absolute,native_absolute,512)){fprintf(stderr,"XMM CPU/frame store=%u base=%u profile=%u index=%u source=%u\n",store,base,profile,im,li);return 1;}
  for(unsigned r=0;r<16;r++)if(a.after[r]!=a.before[r]||a.raw_after[r]!=a.raw_before[r]||a.tags_after[r]!=a.tags_before[r]){fprintf(stderr,"XMM GPR frame r=%u\n",r);return 1;}
  cases++;aligned_cases+=aligned;
 }
 munmap(absolute,4096);printf("x86 XMM0 full frame direct/interpreter/CPU cross-check: OK (%lu cases, %lu aligned MOVAPS)\n",cases,aligned_cases);return 0;
}
