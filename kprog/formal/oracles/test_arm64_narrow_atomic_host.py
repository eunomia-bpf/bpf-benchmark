"""Compare actual narrow kfunc effects with integer updates and adjacent bytes."""
from pathlib import Path
import subprocess,sys
R=Path(__file__).resolve().parents[3];O=Path(sys.argv[1]);O.mkdir(parents=True,exist_ok=True)
s=(R/'kinsn/module/arm64/bpf_arm64_native_lab.c').read_text()
a=s.index('#define ARM64_NATIVE_NARROW_RMW');b=s.index('#undef ARM64_NATIVE_NARROW_RMW',a)
code='''#include <stdint.h>
#include <stdio.h>
#define __bpf_kfunc
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
'''+s[a:b]+'''
int main(void) {
 unsigned long cases=0; unsigned errors=0;
 const unsigned orders[]={__ATOMIC_RELAXED,__ATOMIC_ACQUIRE,__ATOMIC_RELEASE,__ATOMIC_ACQ_REL};
 const u64 values[]={0,1,0xff,0x100,0xffff,0x123456789abcdef0ULL};
 for(unsigned width=1;width<=2;++width)
  for(unsigned old=0;old<(width==1?256:65536);++old)
   for(unsigned v=0;v<6;++v)
    for(unsigned op=0;op<3;++op)
     for(unsigned o=0;o<4;++o) {
      union { u16 h[3]; u8 b[6]; } mem={.b={0x12,0x34,0,0,0x56,0x78}};
      unsigned mask=width==1?255:65535;
      unsigned value=values[v]&mask;
      unsigned expected=(op==0?old+value:op==1?old|value:old&value)&mask;
      u64 result;
      if(width==1) { mem.b[2]=old;mem.b[3]=0xab;result=bpf_arm64_native_lab_atomic8(&mem.b[2],values[v],op,orders[o]); }
      else { mem.h[1]=old;result=bpf_arm64_native_lab_atomic16(&mem.h[1],values[v],op,orders[o]); }
      unsigned actual=width==1?mem.b[2]:mem.h[1];
      if(result!=old || actual!=expected || mem.b[0]!=0x12 || mem.b[1]!=0x34 || mem.b[4]!=0x56 || mem.b[5]!=0x78 || (width==1 && mem.b[3]!=0xab)) ++errors;
      ++cases;
     }
 printf("arm64 narrow atomic kfunc host: %lu cases, %u discrepancies\\n",cases,errors);
 return !!errors;
}
'''
(O/'atomic.c').write_text(code)
subprocess.run(['gcc','-O2','-fsanitize=undefined','-fno-sanitize-recover=all',str(O/'atomic.c'),'-o',str(O/'atomic')],check=True)
subprocess.run([str(O/'atomic')],check=True)
