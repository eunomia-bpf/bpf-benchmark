"""Compare actual generated MUL-r64 C with hardware and independent wide products."""
import ctypes as c
import hashlib
import json
from pathlib import Path
import random
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
functions = []
for source in ['rax', 'rdx', 'rcx', 'r10', 'r11']:
    lines = []
    gen.append_branch_or_ret(lines, gen.NativeInsn(0, 'mul '+source, 'mul', (source,)), {0})
    functions.append('''struct result sim_@(__u64 a, __u64 b, __u64 flags) {
 X86_SIM_L_DECLARE_STATE(); X86_SIM_L_DECLARE_STACK();
 __u64 before[16];
 for (int r=0;r<16;r++) {
  __u64 v = 0x1111111100000000ULL+r;
  if (r==X86_RAX) v=a;
  if (r==X86_RDX || r==X86_RCX || r==X86_R10 || r==X86_R11) v=b;
  X86_SIM_L_WRITE_REG_WIDTH(r,v,X86_WIDTH_64); before[r]=v;
 }
 __x86_cf=flags&1; __x86_pf=(flags>>2)&1; __x86_af=(flags>>4)&1;
 __x86_zf=(flags>>6)&1; __x86_sf=(flags>>7)&1; __x86_of=(flags>>11)&1;
 @BODY@
 __u64 preserved=1;
 for(int r=0;r<16;r++) if(r!=X86_RAX && r!=X86_RDX && X86_SIM_L_READ_REG(r)!=before[r]) preserved=0;
 return (struct result){X86_SIM_L_READ_REG(X86_RAX),X86_SIM_L_READ_REG(X86_RDX),
  __x86_cf|(__x86_pf<<2)|(__x86_af<<4)|(__x86_zf<<6)|(__x86_sf<<7)|(__x86_of<<11),preserved};
}'''.replace('@BODY@', chr(10).join(lines)).replace('@', source))
for source in ['eax', 'DWORD PTR [rcx]', '']:
    try: gen.append_branch_or_ret([],gen.NativeInsn(0,'mul '+source,'mul',(source,)),{0})
    except ValueError: pass
    else: raise AssertionError('Unsupported form silently accepted: '+source)
text = '''#include <stdint.h>
#define X86_SIM_ENABLE_STACK
#include "@HEADER@"
struct result { uint64_t lo,hi,flags,preserved; };
struct result hardware(uint64_t a,uint64_t b) {
 uint64_t hi,flags;
 __asm__ volatile("mulq %[rhs]; pushfq; popq %[flags]"
  : "+a"(a), "=d"(hi), [flags]"=&r"(flags) : [rhs]"r"(b) : "cc", "memory");
 return (struct result){a,hi,flags,1};
}
'''.replace('@HEADER@',str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))+chr(10).join(functions)
source=out/'oracle.c';source.write_text(text)
command=['clang-18','-O2','-shared','-fPIC','-mno-red-zone','-I'+str(ROOT/'vendor/libbpf/src'),'-I'+str(ROOT/'vendor/libbpf/include/uapi'),str(source),'-o',str(out/'oracle.so')]
p=subprocess.run(command,capture_output=True,text=True);(out/'compile.stdout').write_text(p.stdout);(out/'compile.stderr').write_text(p.stderr);p.check_returncode()
class Result(c.Structure): _fields_=[(n,c.c_uint64) for n in ['lo','hi','flags','preserved']]
lib=c.CDLL(str((out/'oracle.so').resolve()));hw=lib.hardware;hw.argtypes=[c.c_uint64,c.c_uint64];hw.restype=Result
edges=[0,1,2,65535,65536,2**32-1,2**32,2**63-1,2**63,2**64-2,2**64-1]
rng=random.Random(20261114);pairs=[(a,b) for a in edges for b in edges]+[(rng.getrandbits(64),rng.getrandbits(64)) for _ in range(10000)]
counts={}
for name in ['rax','rdx','rcx','r10','r11']:
    f=getattr(lib,'sim_'+name);f.argtypes=[c.c_uint64]*3;f.restype=Result
    for a,b in pairs:
        rhs=a if name=='rax' else b;product=a*rhs;want=hw(a,rhs);flags=(a^b)&0x8d5;got=f(a,b,flags)
        assert got.lo==want.lo==product%(2**64) and got.hi==want.hi==product>>64,(name,a,b,'product')
        assert got.flags&0x801==want.flags&0x801==((1|0x800) if product>>64 else 0),(name,a,b,'flags')
        assert got.flags&0xd4==flags&0xd4 and got.preserved,(name,a,b,'preservation')
    counts[name]=len(pairs)
report=dict(vectors=counts,total=sum(counts.values()),compiler=command,generated_c_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),scope='Generated C lowering, hardware MUL and independent Python128-bit product; CF/OF and all other registers/undefined-flag preservation; kernel verifier acceptance is separate.')
(out/'result.json').write_text(json.dumps(report,indent=2)+chr(10));print(json.dumps(report))
