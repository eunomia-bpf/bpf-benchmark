"""Catch distinct-global alias assumptions for two offsets of one source map."""
import ctypes
import json
from pathlib import Path
import subprocess
import struct
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
OUT=HERE/'source-map-alias';OUT.mkdir()
raw=OUT/'source.bpf.bin'
source=(HERE/'bcc-capture-12/bpfrejit_1931_918b4f57cc8f3b1e.bpf').read_bytes()
# Preserve the actual map probe's LDDW16+store42, then read the same address
# using LDDW0+load16. Different LLVM objects could invent disjoint storage.
source=source[:24]+struct.pack('<BBhi',0x18,0x22,0,9)+bytes(8)+struct.pack('<BBhi',0x79,0x20,16,0)+struct.pack('<BBhi',0x95,0,0,0)
raw.write_bytes(source)
command=[sys.executable,str(HERE/'lift_startup_proofs.py'),'bcc_map_alias',str(raw),'socket']
r=subprocess.run(command,capture_output=True,text=True,timeout=120)
(OUT/'generate.json').write_text(json.dumps(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr),indent=2)+'\n')
if r.returncode:raise RuntimeError(r.stderr)
case=HERE/'startup-lift/bcc_map_alias'
bindings=json.loads((case/'source-map-bindings.json').read_text())
entry=json.loads((case/'manifest-entry.json').read_text())
if len(bindings)!=1 or entry['source_bytecode_hex']!=source.hex() or 'source_map_fd_sites' in entry:
 raise RuntimeError('multi-site source alias identity was weakened')
ir=(case/'native.opt.ll').read_text()
if ir.count('external local_unnamed_addr global [0 x i8]')!=1:
 raise RuntimeError('one source map became distinct sized native objects')
# Execute the generated native code against real storage; check the store, return
# and all neighboring bytes, rather than only checking its IR spelling.
shim=OUT/'storage.c';shim.write_text('unsigned char __native_source_map_0[32];\n')
shared=OUT/'native.so';command=['cc','-shared','-fPIC',str(shim),str(case/'entry.native.o'),'-o',str(shared)]
r=subprocess.run(command,capture_output=True,text=True,timeout=120)
(OUT/'link.json').write_text(json.dumps(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr),indent=2)+'\n')
if r.returncode:raise RuntimeError(r.stderr)
library=ctypes.CDLL(str(shared));storage=(ctypes.c_ubyte*32).in_dll(library,'__native_source_map_0')
for i in range(32):storage[i]=0xa5
function=library.bpf_main;function.argtypes=[ctypes.c_void_p];function.restype=ctypes.c_uint64
result=function(None)
if result!=42 or bytes(storage)!=struct.pack('<Q',42)+b'\xa5'*24:
 raise RuntimeError((result,bytes(storage).hex()))
print('same source map at offsets16/0: one native object, exact multi-site FD selector, actual CPU return42/store8/neighbors PASS')
# The incomplete-extent and alias-aware frontend must keep the actual one-site
# probe's native and proof instructions unchanged from T's bound KVM input.
for filename,section in [('entry.native.o','.text'),('bpf_main.proof.o','.text'),('entry.bpf.o','socket')]:
 bodies=[]
 for name in ('bcc_map_value','bcc_map_value_v2','bcc_map_value_v3'):
  with (HERE/'startup-lift'/name/filename).open('rb') as stream:
   bodies.append(ELFFile(stream).get_section_by_name(section).data())
 if not bodies[0] or any(body!=bodies[0] for body in bodies[1:]):
  raise RuntimeError((filename,'one-site native/proof instructions changed'))
print('one-site incomplete extent/alias canonicalization preserves exact native and proof instructions of bound KVM input: PASS')
