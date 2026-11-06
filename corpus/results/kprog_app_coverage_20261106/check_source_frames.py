"""Catch helper-only frame underallocation and unsafe return-slot overlap."""
import json
from pathlib import Path
import re
import resource
import struct
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
OUT=HERE/'source-frame-cpu';OUT.mkdir()
def run(args):
 args=list(map(str,args));r=subprocess.run(args,capture_output=True,text=True,timeout=120,
   preexec_fn=lambda:resource.setrlimit(resource.RLIMIT_CORE,(0,0)))
 with (OUT/'commands.jsonl').open('a') as stream:
  stream.write(json.dumps(dict(command=args,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))+'\n')
 return r
def insn(code,dst=0,src=0,off=0,imm=0):return struct.pack('<BBhi',code,dst|(src<<4),off,imm)
exit=insn(0x95)
zero=insn(0xb7,imm=0)
fixtures={
 'helper8':((HERE/'bcc-capture-12/bpfrejit_1716_7e4864ff1af3e9d4.bpf').read_bytes(),8),
 'derived24':(insn(0xbf,1,10)+insn(0x07,1,imm=-8)+insn(0xbf,2,1)+insn(0x07,2,imm=-16)+insn(0x7a,2,imm=42)+zero+exit,24),
 'join24':(insn(0x85,imm=7)+insn(0xbf,1,10)+insn(0x15,0,off=2,imm=0)+insn(0x07,1,imm=-8)+insn(0x05,off=1)+insn(0x07,1,imm=-24)+insn(0x7a,1,imm=42)+zero+exit,24),
 'loop512':(insn(0xbf,1,10)+insn(0xb7,2,imm=3)+insn(0x07,1,imm=-8)+insn(0x17,2,imm=1)+insn(0x55,2,off=-3,imm=0)+insn(0x7a,1,imm=42)+zero+exit,512),
 'spill512':(insn(0xbf,1,10)+insn(0x7b,10,1,off=-8)+insn(0x79,2,10,off=-8)+insn(0x07,2,imm=-24)+insn(0x7a,2,imm=42)+zero+exit,512),
}
for name,(raw,expected) in fixtures.items():
 source=OUT/(name+'.bpf.bin');source.write_bytes(raw);ir=OUT/(name+'.ll')
 r=run([HERE/'lift-bpf-ir',source,ir])
 if r.returncode:raise RuntimeError(r.stderr)
 text=ir.read_text()
 if f'%stackBegin = alloca i8, i32 {expected}, align 8' not in text or f'%stackEnd = getelementptr i8, ptr %stackBegin, i32 {expected}' not in text:
  raise RuntimeError((name,'allocation/top disagree with source-derived extent',expected))
 print(name,'source frame extent/top',expected,'PASS',flush=True)
stub=OUT/'helper.c';stub.write_text('''#include <stddef.h>
#include <stdlib.h>
#include <string.h>
unsigned observed_calls;
long bpf_probe_read_kernel(void *buffer, unsigned size, const void *source) {
 if (size != 8 || source != NULL) abort();
 ++observed_calls; memset(buffer, 0, size); return -14;
}
''')
for name,case in [('before','bcc_trace_read'),('after','bcc_trace_frame_cfg')]:
 shared=OUT/(name+'.so')
 r=run(['cc','-shared','-fPIC',stub,HERE/'startup-lift'/case/'entry.native.o','-o',shared])
 if r.returncode:raise RuntimeError(r.stderr)
 script='''import ctypes,sys
m=ctypes.CDLL(sys.argv[1]);f=m.bpf_main;f.argtypes=[ctypes.c_void_p];f.restype=ctypes.c_uint64
v=f(None);calls=ctypes.c_uint.in_dll(m,"observed_calls").value
print("retval",v,"helper_calls",calls,flush=True)
if v!=(1<<64)-14 or calls!=1:raise SystemExit(2)
'''
 r=run([sys.executable,'-c',script,shared])
 if name=='before' and r.returncode!=-11:raise RuntimeError(('old one-byte frame did not reproduce SIGSEGV',r.returncode,r.stdout,r.stderr))
 if name=='after' and r.returncode:raise RuntimeError(('correct frame failed',r.returncode,r.stdout,r.stderr))
 print(name,'actual CPU helper-write/return',r.returncode,r.stdout.strip(),flush=True)
