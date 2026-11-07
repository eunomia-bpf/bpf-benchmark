#!/usr/bin/env python3
"""Replay F's original RBX regression; execute only after actual JIT preservation."""
from pathlib import Path
import argparse,json,os,re,subprocess,sys
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/tv'))
from extract_checked import decode
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('build',type=Path);parser.add_argument('out',type=Path)
a=parser.parse_args();b=a.build.resolve();out=a.out.resolve();out.mkdir(parents=True,exist_ok=True)
manifest=out/'manifest.json'
manifest.write_text(json.dumps({'objects':[dict(program='neg_source',source_btf_symbol='neg_source',native_object=str(b/'callee_saved_clobber.native.o'),symbol='entry',simulator_object=str(b/'callee_saved_clobber.bpf.o'),simulator_program='callee_saved_clobber_x86_sim_xdp')]},indent=2)+'\n')
base=[str(b/'bound-probe'),str(b/'companion.bpf.o'),str(manifest)]
env=dict(os.environ,BPFREJIT_NATIVE_LOADER_TV_DIR=str(out/'load-only'))
loaded=subprocess.run(base,cwd=ROOT/'kprog/fidelity',env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
(out/'load-only.log').write_bytes(loaded.stdout)
if loaded.returncode:raise RuntimeError('load failed: '+loaded.stdout.decode())
captures=list((out/'load-only').glob('*/load.json'))
if len(captures)!=1:raise ValueError('one actual bound-load capture required')
capture=captures[0].parent
_,metadata=decode((capture/'checked.snapshot.bin').read_bytes())
if metadata['binding'][4]!=1 or not metadata['generation']:raise ValueError('actual binding must preserve RBX')
native=(capture/'native.bin').read_bytes();jit=(capture/'jit.bin').read_bytes();start=jit.find(native)
if (capture/'native.relocs').read_bytes() or start<0 or jit.find(native,start+1)>=0:raise ValueError('one unrelocated complete body required')
disasm=subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64','-Mintel','--insn-width=16',str(capture/'jit.bin')],text=True)
(out/'actual-jit.asm').write_text(disasm)
operations=[]
for line in disasm.splitlines():
 match=re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+(push|pop)\s+rbx\s*$',line)
 if match:operations.append([int(match[1],16),match[2]])
if not any(offset<start and op=='push' for offset,op in operations) or not any(offset>=start+len(native) and op=='pop' for offset,op in operations):raise AssertionError('RBX must be saved/restored outside native body before execution')
# Only this inspected, repaired program may now execute.
env['BPFREJIT_NATIVE_LOADER_TV_DIR']=str(out/'execution')
executed=subprocess.run(base+['0','2'],cwd=ROOT/'kprog/fidelity',env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
(out/'execution.log').write_bytes(executed.stdout)
if executed.returncode or b'native_bound result=0 retval=2' not in executed.stdout:raise RuntimeError('preserved execution failed: '+executed.stdout.decode())
row=dict(assembly='mov rbx,0x123456789abcdef0; mov eax,2; ret',abi_mask=metadata['binding'][4],generation=metadata['generation'],native_offset=start,native_size=len(native),rbx_operations=operations,load='passed',jit_preservation='passed',execution='passed',packet_result=0,retval=2,guest_uname=list(os.uname()))
(out/'outcomes.json').write_text(json.dumps(row,indent=2)+'\n');print(json.dumps(row),flush=True)
