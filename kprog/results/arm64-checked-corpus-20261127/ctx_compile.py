"""Compile the actual modified-context request with one common backend control."""
import io
from elftools.elf.elffile import ELFFile
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
raw=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T012418Z/bcc-set')
out=raw/'ctx20-diagnostic';out.mkdir(exist_ok=True)
with tarfile.open(raw/'service.tar.gz') as outer:
 with tarfile.open(fileobj=io.BytesIO(outer.extractfile('service/requests/7.success.tar.gz').read())) as inner:
  files={Path(m.name).name:m for m in inner.getmembers() if m.isfile()}
  for name in ['trusted_arm64.bpf.frontend.bc','trusted_arm64.bpf.o','trusted_arm64.bpf.c','generation.metadata.json','kernel.facts.json']:
   (out/name).write_bytes(inner.extractfile(files[name]).read())
  receipt=json.loads(inner.extractfile(files['trusted_arm64.bpf.o.compiler.json']).read())
command=receipt['command'];source=command.index('-c')+1;output=command.index('-o')+1
command[source]=str(out/'trusted_arm64.bpf.frontend.bc')
record=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),source='Actual request7 inet_sock_set_state saved frontend IR',cases=[])
for name,flags in [('normal',[]),('no-avoid-speculation',['-mllvm','-bpf-disable-avoid-speculation'])]:
 case=out/name;case.mkdir(exist_ok=True);cmd=command.copy();cmd[output]=str(case/'replay.bpf.o');cmd+=flags
 r=subprocess.run(cmd,text=True,capture_output=True);record['cases'].append(dict(name=name,command=cmd,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr));r.check_returncode()
 disasm=subprocess.check_output(['llvm-objdump-18','-d',str(case/'replay.bpf.o')],text=True);(case/'disassembly.txt').write_text(disasm)
record['normal_matches_original']=(out/'normal/replay.bpf.o').read_bytes()==(out/'trusted_arm64.bpf.o').read_bytes()
record['control_matches_normal']=(out/'normal/replay.bpf.o').read_bytes()==(out/'no-avoid-speculation/replay.bpf.o').read_bytes()
def executable_sections(path):
 with path.open('rb') as handle:
  elf=ELFFile(handle)
  return {section.name:section.data() for section in elf.iter_sections() if section['sh_flags'] & 4}
original=executable_sections(out/'trusted_arm64.bpf.o')
normal=executable_sections(out/'normal/replay.bpf.o')
control=executable_sections(out/'no-avoid-speculation/replay.bpf.o')
record['executable_sections']={name:len(data) for name,data in original.items()}
record['normal_code_matches_original']=original==normal
record['control_code_matches_normal']=normal==control

(HERE/'ctx20-compile.json').write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(HERE/'ctx20-compile.tar.gz','w:gz') as archive:archive.add(out,arcname='ctx20-diagnostic')
print('Normal equals original:',record['normal_matches_original'],'control equals normal:',record['control_matches_normal'])
