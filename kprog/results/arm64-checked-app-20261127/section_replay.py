"""Replay the actual failed two-section ARM native object through both proof passes."""
import json
from pathlib import Path
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
raw=Path('/workspaces/kprog-raw/perf/arm64-checked-app-20261127/20261127T004645Z/bcc-opensnoop')
out=raw/'section-replay';out.mkdir(exist_ok=True)
linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
source=raw/'replay-checked-simulator.native.o';plan=raw/'replay-2193062d650c4491.tmp.568.link-plan.json'
symbol='trusted_arm64_arm64_sim_xdp'
commands=[
 [str(linker),'--input',str(source),'--symbol',symbol,'--mode','proof','--preserve-entry-abi','--output',str(out/'checked.proof.o')],
 [str(linker),'--input',str(out/'checked.proof.o'),'--symbol',symbol,'--mode','proof','--output',str(out/'loader.proof.o')],
 [str(linker),'--input',str(out/'loader.proof.o'),'--symbol',symbol,'--mode','kernel','--link-plan',str(plan),'--output',str(out/'kernel.bin')]]
rows=[]
for command in commands:
 r=subprocess.run(command,text=True,capture_output=True);rows.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr));r.check_returncode()
with (out/'checked.proof.o').open('rb') as file:
 elf=ELFFile(file);text=elf.get_section_by_name('.text').data();word=int.from_bytes(text[0xbc:0xc0],'little')
 disp=(word>>5)&0x7ffff
 if disp&(1<<18):disp-=1<<19
 target=0xbc+disp*4
 assert target==0x94
 symbols=[dict(name=x.name,address=x['st_value'],size=x['st_size']) for x in elf.get_section_by_name('.symtab').iter_symbols() if x['st_info']['type']=='STT_FUNC']
record=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),commands=rows,branch_offset=0xbc,corrected_target=target,old_corrupt_target=0x778,symbols=symbols,kernel_bytes=(out/'kernel.bin').stat().st_size,scope='Actual failed object; host proof/preserved ABI, loader proof, kernel link. No runtime claim.')
(HERE/'section-replay.json').write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(HERE/'section-replay.tar.gz','w:gz') as archive:
 archive.add(out,arcname='section-replay');archive.add(source,arcname=source.name);archive.add(plan,arcname=plan.name)
print('All three actual-object link stages pass; branch0xbc targets0x94; kernel bytes',record['kernel_bytes'])
