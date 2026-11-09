/* REP MOVS complete numeric/raw/tag/vector/flag frame against real x86 REP:
 * every bounded count, element width/default, flag combination and sequential
 * overlap direction, with heap/ABI/private-stack pointer origins. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 2048U
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
#define BYTES 2048U
static __u8 source[BYTES],destination[BYTES],native_source[BYTES],native_destination[BYTES],native_stack[BYTES];
unsigned long native_lab_entry_input(unsigned kind){(void)kind;abort();}
unsigned long native_lab_exclusive_failure_choice(unsigned site){(void)site;abort();}
static __u64 flagword(unsigned seed){return ((seed&1)?1:0)|((seed&2)?4:0)|((seed&4)?16:0)|((seed&8)?64:0)|((seed&16)?128:0)|((seed&32)?2048:0);}
static __u64 cell(unsigned r){return 0x1020304050607080ULL+r*0x100020003ULL;}
static __u8 byte(unsigned i,unsigned image,unsigned seed){return (__u8)((i*(seed*16+137)+image*71+seed*23)^(i>>4));}
struct observation{__u64 before[16],after[16],raw_before[16],raw_after[16],flags,lo,hi;__u8 tags_before[16],tags_after[16],source[BYTES],destination[BYTES],stack[BYTES];};
/* Profiles: separate heap, forward overlap both directions, exact alias,
 * stack source, stack destination, stack overlap and ABI-tagged separate heap. */
static void locations(unsigned profile,unsigned seed,unsigned *si,unsigned *di,unsigned *so,unsigned *dof){
 *si=0;*di=1;*so=640+seed;*dof=640+seed;
 if(profile==1||profile==2||profile==3){*di=0;*dof=profile==1?*so-1-seed:profile==2?*so+1+seed:*so;}
 if(profile==4)*si=2;
 if(profile==5)*di=2;
 if(profile==6){*si=2;*di=2;*dof=*so+1+seed;}
}
static __attribute__((noinline,noclone)) void simulate(struct observation *out,unsigned direct,unsigned flags,unsigned count,unsigned profile,unsigned seed,unsigned fs){
 X86_SIM_L_DECLARE_STATE();X86_SIM_L_DECLARE_STACK();__u8 __x86_sim_abi_kind=0;
 __x86_native_stack_base=(__u64)(long)&native_stack[BYTES];
 for(unsigned r=0;r<16;r++)X86_SIM_L_WRITE_REG_WIDTH(r,cell(r),8);
 __x86_rsp.ptr=(void *)(long)-(__s64)BYTES;X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX,(void *)&__x86_stack_mem.b[128],X86_SIM_TAG_STACK);
 unsigned si,di,so,dof;locations(profile,seed,&si,&di,&so,&dof);
 __u8 *images[]={source,destination,(__u8 *)(void *)__x86_stack_mem.b};
 for(unsigned i=0;i<BYTES;i++)for(unsigned n=0;n<3;n++)images[n][i]=byte(i,n,seed);
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI,images[si]+so,si==2?X86_SIM_TAG_STACK:profile==7?X86_SIM_TAG_ABI:X86_SIM_TAG_SCALAR);
 X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI,images[di]+dof,di==2?X86_SIM_TAG_STACK:profile==7?X86_SIM_TAG_ABI:X86_SIM_TAG_SCALAR);
 X86_SIM_L_WRITE_REG_WIDTH(X86_RCX,count,8);__x86_xmm0_lo=0x8877665544332211ULL+seed;__x86_xmm0_hi=~__x86_xmm0_lo;
 __u64 old=flagword(fs);__x86_cf=!!(old&1);__x86_pf=!!(old&4);__x86_af=!!(old&16);__x86_zf=!!(old&64);__x86_sf=!!(old&128);__x86_of=!!(old&2048);
 memset(out,0,sizeof(*out));for(unsigned r=0;r<16;r++){out->before[r]=X86_SIM_L_READ_REG(r);out->raw_before[r]=(__u64)(long)X86_SIM_L_REG_VALUE(r);out->tags_before[r]=X86_SIM_L_REG_TAG(r);}
 if(direct)X86_SIM_L_EXEC_REP_MOVS(flags,count);else X86_SIM_RUN_OP(X86_OP_REP_MOVS,fs,fs^0xff,flags,0x12345678U^seed,count);
 for(unsigned r=0;r<16;r++){out->after[r]=X86_SIM_L_READ_REG(r);out->raw_after[r]=(__u64)(long)X86_SIM_L_REG_VALUE(r);out->tags_after[r]=X86_SIM_L_REG_TAG(r);}
 out->flags=__x86_cf|((__u64)__x86_pf<<2)|((__u64)__x86_af<<4)|((__u64)__x86_zf<<6)|((__u64)__x86_sf<<7)|((__u64)__x86_of<<11);out->lo=__x86_xmm0_lo;out->hi=__x86_xmm0_hi;
 memcpy(out->source,source,BYTES);memcpy(out->destination,destination,BYTES);for(unsigned i=0;i<BYTES;i++)out->stack[i]=__x86_stack_mem.b[i];
}
struct cpu_result{__u8 *source,*destination;__u64 count,flags;};
static struct cpu_result cpu(unsigned width,unsigned count,__u8 *src,__u8 *dst,__u64 old){struct cpu_result out;out.source=src;out.destination=dst;out.count=count;
#define CPU(OP) asm volatile("pushq %[old]; popfq; rep " OP "; pushfq; popq %[flags]" : "+S"(out.source),"+D"(out.destination),"+c"(out.count),[flags]"=&r"(out.flags):[old]"r"(old|2):"memory","cc")
 switch(width){case 1:CPU("movsb");break;case 2:CPU("movsw");break;case 4:CPU("movsl");break;default:CPU("movsq");}return out;}
int main(void){unsigned long cases=0,overlap=0;const unsigned flags[]={0,1,2,4,8};
 for(unsigned w=0;w<5;w++)for(unsigned count=0;count<=64;count++)for(unsigned profile=0;profile<8;profile++)for(unsigned seed=0;seed<4;seed++)for(unsigned fs=0;fs<64;fs++){
  unsigned width=flags[w]?flags[w]:8,si,di,so,dof;locations(profile,seed,&si,&di,&so,&dof);struct observation a,b;
  simulate(&a,1,flags[w],count,profile,seed,fs);simulate(&b,0,flags[w],count,profile,seed,fs);
  if(memcmp(&a,&b,sizeof(a))){fprintf(stderr,"REP direct/interpreter width=%u count=%u profile=%u\n",width,count,profile);return 1;}
  __u8 *images[]={native_source,native_destination,native_stack};for(unsigned i=0;i<BYTES;i++)for(unsigned n=0;n<3;n++)images[n][i]=byte(i,n,seed);
  struct cpu_result result=cpu(width,count,images[si]+so,images[di]+dof,flagword(fs));
  if(result.count||result.source!=images[si]+so+count*width||result.destination!=images[di]+dof+count*width||((result.flags^flagword(fs))&0x8d5)||a.flags!=flagword(fs)||a.lo!=0x8877665544332211ULL+seed||a.hi!=~a.lo||memcmp(a.source,native_source,BYTES)||memcmp(a.destination,native_destination,BYTES)||memcmp(a.stack,native_stack,BYTES)){fprintf(stderr,"REP CPU/memory frame width=%u count=%u profile=%u seed=%u flags=%u\n",width,count,profile,seed,fs);return 1;}
  for(unsigned r=0;r<16;r++){
   __u64 delta=r==6||r==7?count*width:0,expected=r==1?0:a.before[r]+delta,raw=r==1?0:a.raw_before[r]+delta;unsigned tag=r==1?X86_SIM_TAG_SCALAR:a.tags_before[r];
   if(a.after[r]!=expected||a.raw_after[r]!=raw||a.tags_after[r]!=tag){fprintf(stderr,"REP register frame r=%u width=%u count=%u profile=%u\n",r,width,count,profile);return 1;}
  }
  cases++;overlap+=si==di;
 }
 printf("x86 REP full frame direct/interpreter/CPU cross-check: OK (%lu cases, %lu same-image overlap/alias)\n",cases,overlap);return 0;
}
