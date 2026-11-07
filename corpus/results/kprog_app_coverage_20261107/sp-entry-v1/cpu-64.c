#include <stdint.h>
#include <stdio.h>
#include "x86_sim_local_bpf.h"
static unsigned long long rng=0x82a40f5cb0139a7dULL;
static unsigned long long next(void){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
int main(void){
 unsigned long cases=0,bad=0;
 const unsigned long long bases[]={0,0x00007ffe42c11950ULL,0xfffffffffffffff0ULL,0x8000000000000000ULL,0x7ffffffffffffff0ULL};
 for(unsigned op=0;op<2;op++)for(unsigned base_idx=0;base_idx<5;base_idx++)for(unsigned i=0;i<1024;i++){
  unsigned long long base=bases[base_idx],offset=next(),imm=(unsigned long long)(long long)(int)next(),native=base+offset,flags;
  if(i<16){offset=-(unsigned long long)i*8;imm=i;native=base+offset;}
  if(op==0)__asm__ volatile("addq %[rhs],%[value];pushfq;popq %[flags]" : [value]"+r"(native),[flags]"=r"(flags):[rhs]"r"(imm):"cc");
  else __asm__ volatile("subq %[rhs],%[value];pushfq;popq %[flags]" : [value]"+r"(native),[flags]"=r"(flags):[rhs]"r"(imm):"cc");
  X86_SIM_L_DECLARE_STATE();
#ifndef BEFORE
  __x86_native_stack_base=base;
#endif
  __x86_rsp.ptr=(void *)(long)offset;
  if(op==0)X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_ADD,imm);
  else X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_SUB,imm);
  unsigned long long got=(unsigned)__x86_cf|((unsigned)__x86_pf<<2)|((unsigned)__x86_af<<4)|((unsigned)__x86_zf<<6)|((unsigned)__x86_sf<<7)|((unsigned)__x86_of<<11);
  int mismatch=((got^flags)&0x8d5ULL)!=0 || (unsigned long long)(uintptr_t)__x86_rsp.ptr+base!=native;
  if(mismatch&&bad<3)printf("mismatch op=%u base=%llx offset=%llx imm=%llx gotflags=%llx cpuflags=%llx\n",op,base,offset,imm,got,flags&0x8d5ULL);
  bad+=mismatch;cases++;
 }
 printf("native CPU ADD/SUB direct-SP cases=%lu mismatches=%lu\n",cases,bad);return !!bad;
}
