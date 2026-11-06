"""Pair all captured BCC entries using exact source BTF entry/type/bytecode-length selectors."""
import json
from pathlib import Path
import re
import shutil
import sys
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
phase=Path(sys.argv[1]).resolve()
run=ROOT/'corpus/results/arm64_qemu_corpus_19700101_000006_886537'
pending={};loads={}
for line in (run/'details/shim-logs/bcc__set.baseline.log').read_text().splitlines():
 m=re.match(r'\[[^ ]+ pid=(\d+) tid=(\d+)\] (.*)',line)
 if not m:continue
 pid,tid,text=m.groups();key=pid,tid
 m=re.match(r'BPF_PROG_LOAD type=(\d+) \([^)]+\) name=(.*?) insn_cnt=(\d+) ',text)
 if m:pending[key]=dict(prog_type=int(m[1]),program=m[2],source_bytecode_len=int(m[3])*8)
 m=re.fullmatch(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)',text)
 if m:
  row=pending.pop(key)
  if int(m[1])>=0:loads[int(m[3])]=row
stage=ROOT/'kprog/arm64/build/app-verified-stage'
if not stage.exists():shutil.copytree(ROOT/'vendor/build/native-bpf/arm64/stage',stage)
proofs=stage/'bcc/simulator';proofs.mkdir(exist_ok=True)
objects=[];keys=set()
for pair in json.loads((phase/'pairing.json').read_text()):
 keyrow=dict(loads[pair['original_id']],source_btf_symbol=pair['original_name'])
 key=tuple(keyrow[k] for k in ['program','prog_type','source_bytecode_len','source_btf_symbol'])
 if key in keys:raise ValueError(f'ambiguous captured BCC selector: {key}')
 keys.add(key)
 native=Path(pair['native_object'])
 if not native.is_file(): raise ValueError(f'missing paired native ELF: {native}')
 shutil.copy2(native,stage/'bcc'/native.name)
 native_proof=Path(pair['native_proof'])
 if not native_proof.is_file(): raise ValueError(f'missing paired native proof ELF: {native_proof}')
 stem=native.name.removesuffix('.native.o')
 shutil.copy2(native_proof,stage/'bcc'/(stem+'.'+pair['symbol']+'.proof.o'))
 source=Path(pair['simulator_object'])
 record=json.loads((phase/'compile'/(source.stem.removesuffix('.bpf')+'.json')).read_text())
 if record['returncode'] or not source.is_file():raise ValueError(f'proof is not compiled: {source}')
 target=proofs/source.name;shutil.copy2(source,target)
 objects.append(dict(keyrow,native_object=Path(pair['native_object']).name,symbol=pair['symbol'],
   simulator_object='simulator/'+target.name,simulator_program=pair['simulator_program']))
manifest=dict(version=1,app='bcc',objects=objects)
(stage/'bcc/manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
(phase/'verified-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(f'{len(objects)} captured entries have distinct exact full-BTF/type/bytecode-length selectors and compiled simulator proofs')
