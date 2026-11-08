/* Compare generated scalar and memory tokens with the actual dispatcher, complete register/
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

#define SCALAR_DIRECT(OP) ARM64_SIM_DIRECT_##OP(dst,src,src2,src3,flags,aux,imm)
static const unsigned scalar_ops[]={ARM64_OP_NOP,ARM64_OP_MOV_IMM,ARM64_OP_MOV_REG,ARM64_OP_MOVK,ARM64_OP_ALU_REG,ARM64_OP_SHIFT_IMM,ARM64_OP_SHIFT_REG,ARM64_OP_MADD,ARM64_OP_MSUB,ARM64_OP_MUL,ARM64_OP_UMULL,ARM64_OP_UDIV,ARM64_OP_MVN,ARM64_OP_NEG,ARM64_OP_EXTR,ARM64_OP_BITFIELD,ARM64_OP_REV,ARM64_OP_REV16,ARM64_OP_SXTH,ARM64_OP_CMP_IMM,ARM64_OP_CMP_REG,ARM64_OP_TST_IMM,ARM64_OP_TST_REG,ARM64_OP_CCMP_IMM,ARM64_OP_CCMP_REG,ARM64_OP_CSEL,ARM64_OP_CINC,ARM64_OP_CSET,ARM64_OP_ADRP_GOT,ARM64_OP_ADRP_RODATA,ARM64_OP_TST_BIC_REG,ARM64_OP_ANDS_REG,ARM64_OP_UMULH,ARM64_OP_SXTW,ARM64_OP_SUBS_IMM,ARM64_OP_ADDS_IMM,ARM64_OP_SUBS_REG,ARM64_OP_CMN_IMM,ARM64_OP_CINV,ARM64_OP_ORN_REG,ARM64_OP_ANDS_IMM,ARM64_OP_CMN_REG,ARM64_OP_UMADDL,ARM64_OP_SXTB,ARM64_OP_CSINV,ARM64_OP_CSINC,ARM64_OP_SMADDL,ARM64_OP_CNEG,ARM64_OP_ADDS_REG,ARM64_OP_BICS_REG,ARM64_OP_CSETM,ARM64_OP_CSNEG};
static void run_scalar(struct snapshot *out, unsigned token, int direct,
                       unsigned dst, unsigned src, unsigned flags, unsigned pattern)
{
 ARM64_SIM_L_DECLARE_STATE();
 __u8 __a64_sim_abi_kind=KPROG_ABI_KIND_XDP;
 ARM64_SIM_L_DECLARE_STACK();
 ARM64_SIM_L_FOR_EACH_GPR(SEED_REG)
 const __u64 values[]={0,1,0xff,0x80000000ULL,0xffffffffULL,
                       0x8000000000000000ULL,0xfffffffffffffffeULL,0xffffffffffffffffULL};
 for(unsigned i=0;i<31;i++) __a64_cells[i]->x^=values[pattern%8];
 __a64_numeric_sp=0x123400000ULL;__a64_numeric_sp_valid=1;
 __a64_numeric_return=0x567800000ULL;__a64_numeric_return_valid=1;
 __a64_sp=32;__a64_lr=0x8877665544332211ULL;
 __a64_n=pattern&1;__a64_z=(pattern>>1)&1;__a64_c=(pattern>>2)&1;__a64_v=(pattern>>3)&1;
 for(unsigned i=0;i<32;i++){__a64_vectors[i].lo=0x123456789abcdef0ULL+i;__a64_vectors[i].hi=0x876543210fedcba9ULL-i;}
 unsigned src2=(src+1)%34,src3=(dst+17)%34;
 if(src2==33)src2=255;
 if(src3==33)src3=255;
 unsigned op=scalar_ops[token],bits=(flags?flags:8)*8,shift=(pattern*7)%bits;
 __u32 aux=(((pattern+dst+src)%11)<<8)|(shift<<16);
 __u64 imm=values[pattern%8];
 switch(op){
  case ARM64_OP_ALU_REG:aux=(pattern+src)%6;break;
  case ARM64_OP_SHIFT_IMM:imm=shift; /* fall through */
  case ARM64_OP_SHIFT_REG:aux=pattern%4;break;
  case ARM64_OP_EXTR:imm=shift;break;
  case ARM64_OP_MOVK:aux=((pattern%(bits/16))*16)<<16;break;
  case ARM64_OP_BITFIELD:{unsigned lsb=pattern%bits;aux=(pattern%5)|(lsb<<8)|((bits-lsb)<<16);break;}
  case ARM64_OP_CCMP_IMM:case ARM64_OP_CCMP_REG:aux=((pattern+src)%15)|((pattern&15)<<8);break;
  case ARM64_OP_CNEG:case ARM64_OP_CSEL:case ARM64_OP_CINC:case ARM64_OP_CSET:
  case ARM64_OP_CSETM:case ARM64_OP_CINV:case ARM64_OP_CSINV:case ARM64_OP_CSINC:
  case ARM64_OP_CSNEG:aux=(pattern+src)%15;break;
 }
 memset(out,0,sizeof(*out));calls=0;
 if(direct){switch(token){
  case 0:SCALAR_DIRECT(ARM64_OP_NOP);break;
  case 1:SCALAR_DIRECT(ARM64_OP_MOV_IMM);break;
  case 2:SCALAR_DIRECT(ARM64_OP_MOV_REG);break;
  case 3:SCALAR_DIRECT(ARM64_OP_MOVK);break;
  case 4:SCALAR_DIRECT(ARM64_OP_ALU_REG);break;
  case 5:SCALAR_DIRECT(ARM64_OP_SHIFT_IMM);break;
  case 6:SCALAR_DIRECT(ARM64_OP_SHIFT_REG);break;
  case 7:SCALAR_DIRECT(ARM64_OP_MADD);break;
  case 8:SCALAR_DIRECT(ARM64_OP_MSUB);break;
  case 9:SCALAR_DIRECT(ARM64_OP_MUL);break;
  case 10:SCALAR_DIRECT(ARM64_OP_UMULL);break;
  case 11:SCALAR_DIRECT(ARM64_OP_UDIV);break;
  case 12:SCALAR_DIRECT(ARM64_OP_MVN);break;
  case 13:SCALAR_DIRECT(ARM64_OP_NEG);break;
  case 14:SCALAR_DIRECT(ARM64_OP_EXTR);break;
  case 15:SCALAR_DIRECT(ARM64_OP_BITFIELD);break;
  case 16:SCALAR_DIRECT(ARM64_OP_REV);break;
  case 17:SCALAR_DIRECT(ARM64_OP_REV16);break;
  case 18:SCALAR_DIRECT(ARM64_OP_SXTH);break;
  case 19:SCALAR_DIRECT(ARM64_OP_CMP_IMM);break;
  case 20:SCALAR_DIRECT(ARM64_OP_CMP_REG);break;
  case 21:SCALAR_DIRECT(ARM64_OP_TST_IMM);break;
  case 22:SCALAR_DIRECT(ARM64_OP_TST_REG);break;
  case 23:SCALAR_DIRECT(ARM64_OP_CCMP_IMM);break;
  case 24:SCALAR_DIRECT(ARM64_OP_CCMP_REG);break;
  case 25:SCALAR_DIRECT(ARM64_OP_CSEL);break;
  case 26:SCALAR_DIRECT(ARM64_OP_CINC);break;
  case 27:SCALAR_DIRECT(ARM64_OP_CSET);break;
  case 28:SCALAR_DIRECT(ARM64_OP_ADRP_GOT);break;
  case 29:SCALAR_DIRECT(ARM64_OP_ADRP_RODATA);break;
  case 30:SCALAR_DIRECT(ARM64_OP_TST_BIC_REG);break;
  case 31:SCALAR_DIRECT(ARM64_OP_ANDS_REG);break;
  case 32:SCALAR_DIRECT(ARM64_OP_UMULH);break;
  case 33:SCALAR_DIRECT(ARM64_OP_SXTW);break;
  case 34:SCALAR_DIRECT(ARM64_OP_SUBS_IMM);break;
  case 35:SCALAR_DIRECT(ARM64_OP_ADDS_IMM);break;
  case 36:SCALAR_DIRECT(ARM64_OP_SUBS_REG);break;
  case 37:SCALAR_DIRECT(ARM64_OP_CMN_IMM);break;
  case 38:SCALAR_DIRECT(ARM64_OP_CINV);break;
  case 39:SCALAR_DIRECT(ARM64_OP_ORN_REG);break;
  case 40:SCALAR_DIRECT(ARM64_OP_ANDS_IMM);break;
  case 41:SCALAR_DIRECT(ARM64_OP_CMN_REG);break;
  case 42:SCALAR_DIRECT(ARM64_OP_UMADDL);break;
  case 43:SCALAR_DIRECT(ARM64_OP_SXTB);break;
  case 44:SCALAR_DIRECT(ARM64_OP_CSINV);break;
  case 45:SCALAR_DIRECT(ARM64_OP_CSINC);break;
  case 46:SCALAR_DIRECT(ARM64_OP_SMADDL);break;
  case 47:SCALAR_DIRECT(ARM64_OP_CNEG);break;
  case 48:SCALAR_DIRECT(ARM64_OP_ADDS_REG);break;
  case 49:SCALAR_DIRECT(ARM64_OP_BICS_REG);break;
  case 50:SCALAR_DIRECT(ARM64_OP_CSETM);break;
  case 51:SCALAR_DIRECT(ARM64_OP_CSNEG);break;
  default:abort();
 }}else ARM64_SIM_L_EXEC(op,dst,src,src2,src3,flags,aux,imm);
 ARM64_SIM_L_FOR_EACH_GPR(SAVE_REG)
 for(unsigned i=0;i<32;i++){out->vectors[i*2]=__a64_vectors[i].lo;out->vectors[i*2+1]=__a64_vectors[i].hi;}
 out->sp=(__u64)__a64_sp;out->lr=__a64_lr;out->calls=calls;
 out->flags[0]=__a64_n;out->flags[1]=__a64_z;out->flags[2]=__a64_c;out->flags[3]=__a64_v;
 memcpy(out->bytes,scratch,sizeof(scratch));(void)__a64_sim_abi_kind;
}
static unsigned long scalar_cases(void)
{
 unsigned long count=0;const unsigned widths[]={0,4,8};
 for(unsigned token=0;token<sizeof(scalar_ops)/sizeof(*scalar_ops);token++)
 for(unsigned w=0;w<3;w++)for(unsigned d=0;d<34;d++)for(unsigned s=0;s<34;s++)
 for(unsigned pattern=0;pattern<16;pattern++){
  struct snapshot a,b;unsigned dst=d==33?255:d,src=s==33?255:s;
  run_scalar(&a,token,0,dst,src,widths[w],pattern);
  run_scalar(&b,token,1,dst,src,widths[w],pattern);
  if(memcmp(&a,&b,sizeof(a))||a.calls){fprintf(stderr,"scalar token=%u op=%u flags=%u dst=%u src=%u pattern=%u\n",token,scalar_ops[token],widths[w],dst,src,pattern);exit(1);}
  count++;
 }
 printf("arm64 scalar tokens host cross-check: OK (%lu cases)\n",count);return count;
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
 scalar_cases();
 return 0;
}
