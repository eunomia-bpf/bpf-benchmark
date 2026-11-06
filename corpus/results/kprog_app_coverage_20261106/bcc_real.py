"""Pair all actual x86 BCC resident load IDs with their exact native entry."""
import json
from pathlib import Path
import re
import shutil
import sys
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir()
for name in ('sources','native','upstream'): (phase/name).mkdir()
upstream=ROOT/'vendor/bpf/bcc/libbpf-tools'
for path in upstream.glob('*.h'):shutil.copy2(path,phase/'upstream'/path.name)
shutil.copy2(upstream/'x86/vmlinux.h',phase/'upstream/vmlinux.h')
loads=[json.loads(line) for line in (HERE/'startup-x86/bcc/loads.jsonl').read_text().splitlines()]
programs={r['id']:r for r in loads if r['resident']}
rows=[];paired=[]
for program in programs.values():
    symbol=program['full_name']
    candidates=list((ROOT/'vendor/build/native-bpf/x86/stage/bcc').glob('*.'+symbol+'.proof.o'))
    if len(candidates)!=1:raise ValueError(f'whole native entry not unique for {symbol}: {candidates}')
    proof=candidates[0];stem=proof.name.removesuffix('.'+symbol+'.proof.o')
    original=ROOT/f'vendor/build/.bcc-libbpf/none/x86/output/{stem}.bpf.o'
    with original.open('rb') as stream:
        elf=ELFFile(stream);table=elf.get_section_by_name('.symtab')
        symbols={s.name for s in table.iter_symbols() if s.name}
        functions=[s for s in table.iter_symbols() if s.name==symbol and s['st_info']['type']=='STT_FUNC']
        if len(functions)!=1:raise ValueError(f'original BPF function not unique: {symbol}')
        section=elf.get_section(functions[0]['st_shndx']).name
    shutil.copy2(upstream/(stem+'.bpf.c'),phase/'upstream'/(stem+'.bpf.c'))
    name='bcc_'+stem+'_'+symbol
    local=phase/'native'/(name+'.proof.o');shutil.copy2(proof,local)
    insns,subs,end,rodata=gen.parse_proof_object_program(name,phase/'native')
    source=phase/'sources'/(name+'.bpf.c')
    row=dict(name=name,proof=str(local),source=str(source),stage='generate',ok=False,note='',
        original_id=program['id'],original_name=symbol,original_object=str(original),program_type=program['type'],
        program_section=section,compiler_flags=['-g','-I'+str(phase/'upstream'),'-I'+str(ROOT/'vendor/libbpf/include')])
    try:
        text=gen.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=rodata,
            program_section=section,original_source=phase/'upstream'/(stem+'.bpf.c'),original_symbols=symbols)
        source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',
            f'#include "{phase}/simulator/kprog/x86/x86_sim_local_bpf.h"'))
        row['ok']=True
    except ValueError as error:row['note']=str(error)
    rows.append(row)
    paired.append(dict(program=program['name'],source_btf_symbol=symbol,prog_type=program['type'],
        source_bytecode_len=program['insn_count']*8,native_object=str(proof.parent/(stem+'.native.o')),
        symbol=symbol,simulator_object=str(phase/'objects'/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp'))
(phase/'programs.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
(phase/'manifest.json').write_text(json.dumps(dict(objects=paired),indent=2)+'\n')
(phase/'load-pairing.json').write_text(json.dumps(list(programs.values()),indent=2)+'\n')
seen=set()
def freeze(path):
    path=path.resolve()
    if path in seen:return
    seen.add(path);target=phase/'simulator'/path.relative_to(ROOT)
    target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(path,target)
    for include in re.findall(r'^#include "([^\"]+)"',path.read_text(),re.M):
        child=(path.parent/include).resolve()
        if child.is_file():freeze(child)
freeze(ROOT/'kprog/x86/x86_sim_local_bpf.h')
for path in [ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py',ROOT/'kprog/x86/micro-prog/x86_abi.py',ROOT/'kprog/helper_abi.py',*list((ROOT/'kprog/x86/micro-prog').glob('generated_*.py'))]:freeze(path)
print(f'{sum(r["ok"] for r in rows)}/{len(rows)} actual BCC entries generate; every load ID retained')
for row in rows:
    if not row['ok']:print(row['name'],row['note'])
raise SystemExit(int(any(not r['ok'] for r in rows)))
