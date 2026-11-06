"""Pair the actual Katran startup's resident entry with its native/source objects."""
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
phase=HERE/(sys.argv[1] if len(sys.argv)==2 else 'katran-real-1');phase.mkdir()
for name in ('native','original','upstream','sources'):(phase/name).mkdir()
upstream=phase/'upstream'
shutil.copytree(ROOT/'vendor/bpf/katran/katran/lib/bpf',upstream/'katran/lib/bpf')
shutil.copytree(ROOT/'vendor/bpf/katran/katran/lib/linux_includes',upstream/'katran/lib/linux_includes')
wrapper=upstream/'proof-input.bpf.c'
# Use the public helper ABI and unchanged upstream map declarations. The old
# Katran helper header otherwise redeclares those same Linux helper variables.
wrapper.write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n#define __BPF_HELPERS_H\n#include "katran/lib/bpf/balancer.c"\n')
loads=[json.loads(line) for line in (HERE/'startup-x86/katran/loads.jsonl').read_text().splitlines()]
resident=[row for row in loads if row['resident']]
rows=[];entries=[]
for loaded in resident:
 symbol=loaded['full_name']
 native=phase/'native/balancer.native.o';shutil.copy2(ROOT/'vendor/build/native-bpf/x86/stage/katran/balancer.native.o',native)
 original=phase/'original/balancer.bpf.o';shutil.copy2(ROOT/'vendor/build/x86/katran/bpf/balancer.bpf.o',original)
 with original.open('rb') as stream:
  elf=ELFFile(stream);symbols={s.name for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name}
 name='katran_'+symbol;proof=phase/'native'/(name+'.proof.o')
 command=[str(ROOT/'kprog/x86/native_lab/native_link/target-c-tail/release/native-link'),'--input',str(native),'--symbol',symbol,'--mode','proof','--preserve-entry-abi','--output',str(proof)]
 r=subprocess.run(command,capture_output=True,text=True,timeout=120)
 (phase/'commands.jsonl').write_text(json.dumps(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))+'\n')
 if r.returncode:raise RuntimeError(r.stderr)
 insns,subs,end,rodata=gen.parse_proof_object_program(name,phase/'native')
 source=phase/'sources'/(name+'.bpf.c')
 text=gen.render_program(name,insns,subs,'xdp',exit_addr=end,rodata16=rodata,
   original_source=wrapper,original_symbols=symbols)
 source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{phase}/simulator/kprog/x86/x86_sim_local_bpf.h"'))
 rows.append(dict(name=name,proof=str(proof),source=str(source),stage='generate',ok=True,note='',
   original_id=loaded['id'],original_name=symbol,original_object=str(original),program_type=loaded['type'],
   program_section='xdp',compiler_flags=['-g','-D__x86_64__','-I'+str(upstream)]))
 entries.append(dict(program=loaded['name'],source_btf_symbol=symbol,prog_type=loaded['type'],source_bytecode_len=loaded['insn_count']*8,
   native_object=str(native),symbol=symbol,simulator_object=str(phase/'objects'/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp'))
(phase/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
(phase/'manifest.json').write_text(json.dumps(dict(objects=entries),indent=2)+'\n')
(phase/'load-pairing.json').write_text(json.dumps(loads,indent=2)+'\n')
seen=set()
def freeze(path):
 path=path.resolve()
 if path in seen:return
 seen.add(path);target=phase/'simulator'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(path,target)
 for include in re.findall(r'^#include "([^\"]+)"',path.read_text(),re.M):
  child=(path.parent/include).resolve()
  if child.is_file():freeze(child)
freeze(ROOT/'kprog/x86/x86_sim_local_bpf.h')
print(len(rows),'actual resident Katran entries generated; all',len(loads),'startup loads retained')
