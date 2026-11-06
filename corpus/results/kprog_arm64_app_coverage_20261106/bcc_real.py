"""Construct every captured BCC entry with its real source maps and BPF section."""
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile
import coverage
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir()
linker=Path(sys.argv[2]).resolve()
(phase/'sources').mkdir();(phase/'native').mkdir()
programs=json.loads((ROOT/'corpus/results/arm64_qemu_corpus_19700101_000006_886537/details/bpf-evidence/bcc_set/baseline/program-inventory.json').read_text())
manifest=json.loads((HERE/'inventory/bcc.json').read_text())['objects']
rows=[];paired=[]
for program in programs:
 symbol=program['name']
 candidates=[e for e in manifest if e.get('symbol',e['program'])==symbol]
 if not candidates:
  candidates=[e for e in manifest if symbol.startswith(e['program'])]
 stems={Path(e['native_object']).name.removesuffix('.native.o') for e in candidates}
 if len(stems)!=1: raise ValueError(f'exact native object unresolved for {symbol}: {candidates}')
 stem=stems.pop();original=ROOT/f'vendor/build/.bcc-libbpf/none/arm64/output/{stem}.bpf.o'
 with original.open('rb') as source:
  elf=ELFFile(source);table=elf.get_section_by_name('.symtab')
  symbols={s.name for s in table.iter_symbols() if s.name}
  target=[s for s in table.iter_symbols() if s.name==symbol and s['st_info']['type']=='STT_FUNC']
  if len(target)!=1: raise ValueError(f'original ELF entry {symbol} is not unique')
  section=elf.get_section(target[0]['st_shndx']).name
 name='bcc_'+stem+'_'+symbol
 local=phase/'native'/(name+'.proof.o')
 command=[str(linker),'--input',str(ROOT/f'vendor/build/native-bpf/arm64/stage/bcc/{stem}.native.o'),'--symbol',symbol,'--output',str(local),'--mode','proof']
 result=subprocess.run(command,text=True,capture_output=True)
 (phase/'native'/(name+'.link.json')).write_text(json.dumps(dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr),indent=2)+'\n')
 if result.returncode: raise RuntimeError(result.stderr)
 functions,rodata=gen.parse_native_linked_program(gen.Bench(name,symbol,'raw'),phase/'native')
 source=phase/'sources'/(name+'.bpf.c')
 row=dict(name=name,proof=str(local),source=str(source),stage='generate',ok=False,note='',
          original_object=str(original),original_symbol=symbol,program_type=program['type'],
          program_section=section,original_id=program['id'],compiler_flags=[
           '-I'+str(ROOT/'vendor/bpf/bcc/libbpf-tools/arm64'),
           '-I'+str(ROOT/'vendor/bpf/bcc/libbpf-tools'),
           '-I'+str(ROOT/'vendor/libbpf/include')])
 try:
  text=gen.render_program(name,symbol,functions,'raw',rodata16=rodata,linked_exit=True,
        program_section=section,original_source=ROOT/f'vendor/bpf/bcc/libbpf-tools/{stem}.bpf.c',
        original_symbols=symbols)
  source.write_text(text);row['ok']=True
 except ValueError as error: row['note']=str(error)
 paired.append(dict(original_id=program['id'],original_name=symbol,original_object=str(original),
    program_section=section,native_object=str(ROOT/f'vendor/build/native-bpf/arm64/stage/bcc/{stem}.native.o'),
    symbol=symbol,simulator_object=str(phase/'objects'/(name+'.bpf.o')),
    simulator_program=name+'_arm64_sim_xdp'))
 rows.append(row)
(phase/'programs.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
(phase/'pairing.json').write_text(json.dumps(paired,indent=2)+'\n')
coverage.freeze_simulator(phase)
print(f'{sum(r["ok"] for r in rows)}/{len(rows)} real BCC entries generate; every capture retained')
raise SystemExit(int(any(not r['ok'] for r in rows)))
