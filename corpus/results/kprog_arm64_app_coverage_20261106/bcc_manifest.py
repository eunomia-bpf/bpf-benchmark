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
pairs=json.loads((phase/'pairing.json').read_text())
fields=('program','prog_type','source_bytecode_len','source_btf_symbol')
keys=set();prepared=[]
for pair in pairs:
    keyrow=dict(loads[pair['original_id']],source_btf_symbol=pair['original_name'])
    key=tuple(keyrow[k] for k in fields)
    if key in keys:raise ValueError(f'ambiguous captured BCC selector: {key}')
    keys.add(key)
    native=Path(pair['native_object']);native_proof=Path(pair['native_proof']);source=Path(pair['simulator_object'])
    for artifact in (native,native_proof,source):
        if not artifact.is_file():raise ValueError(f'missing paired artifact: {artifact}')
    record=json.loads((phase/'compile'/(source.stem.removesuffix('.bpf')+'.json')).read_text())
    if record['returncode']:raise ValueError(f'proof is not compiled: {source}')
    prepared.append((pair,keyrow,native,native_proof,source))
# Validate the entire payload before changing the next runtime's staging area.
stage=ROOT/'kprog/arm64/build/app-verified-stage'
if not stage.exists():shutil.copytree(ROOT/'vendor/build/native-bpf/arm64/stage',stage)
path=stage/'bcc/manifest.json';prior=json.loads(path.read_text())
(phase/'prior-manifest.json').write_text(json.dumps(prior,indent=2)+'\n')
proofs=stage/'bcc/simulator';proofs.mkdir(exist_ok=True)
objects=[]
for pair,keyrow,native,native_proof,source in prepared:
    shutil.copy2(native,stage/'bcc'/native.name)
    stem=native.name.removesuffix('.native.o')
    shutil.copy2(native_proof,stage/'bcc'/(stem+'.'+pair['symbol']+'.proof.o'))
    target=proofs/source.name;shutil.copy2(source,target)
    objects.append(dict(keyrow,native_object=native.name,symbol=pair['symbol'],
        simulator_object='simulator/'+target.name,simulator_program=pair['simulator_program']))
retained=[entry for entry in prior['objects'] if tuple(entry.get(k) for k in fields) not in keys]
manifest=dict(prior,version=1,app='bcc',objects=retained+objects)
path.write_text(json.dumps(manifest,indent=2)+'\n')
(phase/'verified-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(f'{len(objects)} exact captured BCC entries refreshed; {len(retained)} other startup selectors retained')
