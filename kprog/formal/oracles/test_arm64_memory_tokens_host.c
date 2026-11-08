/* Compare generated memory tokens with the actual dispatcher, complete register/
 * tag/vector/flag snapshots and independent byte stores. Catch base/data/status
 * swaps, source-width drift, lost writeback and an exclusive site/result drift. */
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;
#ifndef __always_inline
#define __always_inline inline
#endif
#include "../arm64/arm64_sim_local_bpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static __u64 scratch[64], choice, choice_site;
static unsigned calls;
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{
 if (site != choice_site) abort();
 calls++;
 return choice;
}
static void arm64_sim_unsupported_opcode(void) { abort(); }
struct snapshot {
 __u64 regs[31], vectors[64], source, data, sp, lr;
 __u8 tags[31], flags[4], bytes[sizeof(scratch)];
 unsigned calls;
};
#define SAVE_REG(R,N) out->regs[R]=__a64_##N.x; out->tags[R]=__a64_##N##_tag;
#define SEED_REG(R,N) __a64_##N.x=0x98fedcba76543210ULL+(R)*0x102030405ULL;
#define DIRECT(OP) ARM64_SIM_DIRECT_##OP(dst,src,index,255,flags,aux,imm)
static void run(struct snapshot *out, unsigned token, int direct, unsigned reg,
                unsigned flags, unsigned mode, unsigned indexed, unsigned shift,
                unsigned negative)
{
 ARM64_SIM_L_DECLARE_STATE();
 __u8 __a64_sim_abi_kind=KPROG_ABI_KIND_XDP;
 ARM64_SIM_L_DECLARE_STACK();
 ARM64_SIM_L_FOR_EACH_GPR(SEED_REG)
 __a64_numeric_sp=0x123400000ULL; __a64_numeric_sp_valid=1;
 __a64_numeric_return=0x567800000ULL; __a64_numeric_return_valid=1;
 __a64_sp=32; __a64_lr=0x8877665544332211ULL;
 __a64_n=1; __a64_z=0; __a64_c=1; __a64_v=1;
 for(unsigned i=0;i<32;i++) { __a64_vectors[i].lo=0x123456789abcdef0ULL+i; __a64_vectors[i].hi=0x876543210fedcba9ULL-i; }
 for(unsigned i=0;i<sizeof(scratch);i++) ((__u8 *)scratch)[i]=(__u8)(0x85+i*7);
 ARM64_SIM_L_WRITE_REG_PTR_TAG(4, ((__u8 *)scratch)+128, ARM64_SIM_TAG_MAP_VALUE);
 ARM64_SIM_L_WRITE_REG_WIDTH(5,1,8);
 unsigned dst=token==1?4:reg, src=token==1?reg:token==5?1:4;
 unsigned index=token==5?4:indexed?5:255;
 __u32 aux=(mode<<24)|(shift<<16)|(ARM64_MOD_LSL<<8);
 __u64 imm=token==5?choice_site:negative?(__u64)-8:8;
 unsigned widths[]={ARM64_OP_LOAD,ARM64_OP_STORE,ARM64_OP_LDRSB,ARM64_OP_LDRSH,ARM64_OP_LDRSW,ARM64_OP_STLXR};
 unsigned op=widths[token];
 memset(out,0,sizeof(*out)); calls=0;
 out->source=ARM64_SIM_L_READ_REG(src);
 if(direct) {
  switch(token) {
   case 0: DIRECT(ARM64_OP_LOAD); break;
   case 1: DIRECT(ARM64_OP_STORE); break;
   case 2: DIRECT(ARM64_OP_LDRSB); break;
   case 3: DIRECT(ARM64_OP_LDRSH); break;
   case 4: DIRECT(ARM64_OP_LDRSW); break;
   case 5: DIRECT(ARM64_OP_STLXR); break;
   default: abort();
  }
 } else ARM64_SIM_L_EXEC(op,dst,src,index,255,flags,aux,imm);
 ARM64_SIM_L_FOR_EACH_GPR(SAVE_REG)
 for(unsigned i=0;i<32;i++) { out->vectors[i*2]=__a64_vectors[i].lo; out->vectors[i*2+1]=__a64_vectors[i].hi; }
 out->sp=(__u64)__a64_sp; out->lr=__a64_lr;
 out->flags[0]=__a64_n; out->flags[1]=__a64_z; out->flags[2]=__a64_c; out->flags[3]=__a64_v;
 out->data=ARM64_SIM_L_READ_REG(reg);out->calls=calls;
 memcpy(out->bytes,scratch,sizeof(scratch));
 (void)__a64_sim_abi_kind;
}
int main(void)
{
 const unsigned widths[]={0,1,2,4,8};
 const __u64 outcomes[]={0,1};
 unsigned long cases=0;
 for(unsigned token=0;token<6;token++)
 for(unsigned w=0;w<5;w++) {
  unsigned flags=widths[w],width=flags?flags:8;
  if(token>=2 && width<4) continue;
  for(unsigned regn=0;regn<34;regn++)
  for(unsigned mode=0;mode<4;mode++)
  for(unsigned indexed=0;indexed<2;indexed++)
  for(unsigned shift=0;shift<4;shift++)
  for(unsigned negative=0;negative<2;negative++)
  for(unsigned outcome=0;outcome<(token==5?2:1);outcome++) {
   unsigned reg=regn==33?255:regn;
   /* Canonical native writeback field validity separates load data/base. */
   if(token!=1 && token!=5 && reg==4 && mode) continue;
   choice=outcomes[outcome];choice_site=0x7654321;
   struct snapshot a,b;run(&a,token,0,reg,flags,mode,indexed,shift,negative);
   run(&b,token,1,reg,flags,mode,indexed,shift,negative);
   if(memcmp(&a,&b,sizeof(a))) { fprintf(stderr,"token=%u width=%u reg=%u mode=%u index=%u shift=%u outcome=%u\n",token,width,reg,mode,indexed,shift,outcome);return 1; }
   __u8 expected[sizeof(scratch)];for(unsigned i=0;i<sizeof(expected);i++) expected[i]=(__u8)(0x85+i*7);
   int delta=negative?-8:8;
   unsigned address=128+(token==5?0:((mode&1)?delta:0)+(indexed?(1<<shift):0)+(mode?0:delta));
   __u64 source=a.source+((token==1 && reg==4 && (mode&1))?delta:0);
   if(token==1 || (token==5 && !choice)) for(unsigned i=0;i<width;i++) expected[address+i]=(__u8)(source>>(i*8));
   if(memcmp(expected,a.bytes,sizeof(expected))) { fprintf(stderr,"byte store token=%u width=%u\n",token,width);return 1; }
   if(a.calls!=(token==5)) return 1;
   if(token==5 && reg!=31 && reg!=255 && a.data!=(choice!=0)) return 1;
   cases++;
  }
 }
 printf("arm64 memory tokens host cross-check: OK (%lu cases)\n",cases);
 return 0;
}
