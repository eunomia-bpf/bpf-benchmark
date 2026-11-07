"""Lift upstream Tetragon's observed mixed-call probe without a native renderer."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,struct,subprocess,sys
R=Path(__file__).resolve().parents[4];D=Path(__file__).resolve().parent
sys.path.insert(0,str(R/'kprog'));from helper_abi import helper_idents
sys.path.insert(0,str(R/'kprog/arm64/micro-prog'));import generate_micro_sim_proofs as gen
code=[(0xbf,0x16,0,0),(0x85,0x10,0,7),(0xbf,0x61,0,0),(0x18,0x12,0,6),(0,0,0,0),(0xb7,3,0,0),(0x85,0,0,12),(0xb7,0,0,0),(0x95,0,0,0),(0xb7,0,0,0),(0x95,0,0,0)]
raw=b''.join(struct.pack('<BBhi',*x) for x in code);normalized=bytearray(raw);struct.pack_into('<i',normalized,3*8+4,0)
def fnv(data):
 value=14695981039346656037
 for byte in data:value=((value^byte)*1099511628211)&((1<<64)-1)
 return f'{value:016x}'
assert fnv(raw)=='ca47d4f26feca335' and fnv(normalized)=='7f60b6fbd3faebcf'
source=R/'vendor/repos/tetragon/pkg/bpf/detect_linux.go';version=subprocess.check_output(['git','-C',str(source.parents[2]),'rev-parse','HEAD'],text=True).strip();assert version=='8ca052908600a83c4fad7429a3023a921bc15851'
(D/'source.bpf.bin').write_bytes(raw);commands=[]
def run(args):
 args=list(map(str,args));done=subprocess.run(args,text=True,capture_output=True)
 commands.append({'command':args,'returncode':done.returncode,'stdout':done.stdout,'stderr':done.stderr});(D/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');done.check_returncode();return done
ir=D/'native.ll';opt=D/'native.opt.ll';run([R/'corpus/results/kprog_app_coverage_20261106/lift-bpf-ir',D/'source.bpf.bin',ir])
text=ir.read_text();old='__llvmbpf_pseudo_map_fd_00000006';name='__native_source_map_3';declaration='@'+old+' = external global i8';assert text.count(declaration)==1
text=text.replace(declaration+'\n','');text=re.sub('@'+old+r'\b','@'+name,text);text+='\n@'+name+' = external global [0 x i8]\n';names=helper_idents();text=re.sub(r'_bpf_helper_ext_([0-9]+)',lambda m:names[int(m[1])],text);ir.write_text(text)
run(['opt-18','-O3','-S',ir,'-o',opt]);native=D/'mixed.native.o'
run(['llc-18','-mtriple=aarch64-linux-gnu','-mcpu=generic','-mattr=+reserve-x18,+reserve-x26,+reserve-x27,+reserve-x28','-filetype=obj','-O=3','-relocation-model=pic',opt,'-o',native])
link=R/'kprog/arm64/build/app-native-link/release/native-link';proof=D/'mixed.proof.o';run([link,'--input',native,'--symbol','bpf_main','--mode','proof','--preserve-entry-abi','--output',proof])
funcs,data=gen.parse_native_linked_program(gen.Bench('mixed','bpf_main','raw'),D)
rendered=gen.render_program('mixed','bpf_main',funcs,'raw',rodata16=data,linked_exit=True,program_section='raw_tracepoint/kprog_mixed_probe',trusted_map_bindings=[dict(native_symbol=name,value_offset=None)])
source_c=D/'mixed.bpf.c';source_c.write_text(rendered.replace('#include "../arm64_sim_local_bpf.h"','#include '+json.dumps(str(R/'kprog/arm64/arm64_sim_local_bpf.h'))))
run(['clang','-g','-O2','-mcpu=v4','-target','bpf','-D__TARGET_ARCH_arm64','-I'+str(R/'vendor/libbpf/include/uapi'),'-I'+str(R/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',source_c,'-o',D/'mixed.bpf.o'])
entry={'program':'','prog_type':17,'source_bytecode_hex':normalized.hex(),'source_map_fd_sites':[3],'source_map_bindings':[{'native_symbol':name,'source_insn':3}],'native_object':str(native),'symbol':'bpf_main'}
(D/'manifest-entry.json').write_text(json.dumps(entry,indent=2)+'\n')
record={'utc':datetime.now(timezone.utc).isoformat(),'scope':'Upstream reconstructed source with two observed hash matches; runtime full-byte selector match and verifier/application execution pending','upstream_commit':version,'upstream_source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'source_raw_hash':fnv(raw),'source_normalized_hash':fnv(normalized),'source_sha256':hashlib.sha256(raw).hexdigest(),'source_insns':len(code),'runtime_fd_site':3,'native_sha256':hashlib.sha256(native.read_bytes()).hexdigest(),'native_proof_sha256':hashlib.sha256(proof.read_bytes()).hexdigest(),'proof_generated_and_compiled':True,'proof_bpf_sha256':hashlib.sha256((D/'mixed.bpf.o').read_bytes()).hexdigest(),'frontend_sha256':hashlib.sha256((R/'corpus/results/kprog_app_coverage_20261106/lift-bpf-ir').read_bytes()).hexdigest(),'native_link_sha256':hashlib.sha256(link.read_bytes()).hexdigest(),'commands':commands,'kernel_or_verifier_changed':False}
(D/'summary.json').write_text(json.dumps(record,indent=2)+'\n');print('upstream mixed-call probe: observed raw/policy hashes match, generic LLVM native and ARM proof compilation PASS')
