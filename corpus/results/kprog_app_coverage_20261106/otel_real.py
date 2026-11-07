"""Pair every actual OTel load with original ELF-backed map/global declarations."""
from pathlib import Path
import json
import re
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
out=HERE/(sys.argv[1] if len(sys.argv)>1 else 'otel-real-1');out.mkdir()
for n in ['native','original','sources','objects']:(out/n).mkdir()
native=out/'native/otel.native.o';shutil.copy2(ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o',native)
original=out/'original/tracer.bpf.o'
commands=[]
def run(args):
 args=list(map(str,args));r=subprocess.run(args,text=True,capture_output=True)
 commands.append(dict(command=args,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 if r.returncode:raise ValueError(r.stderr)
 return r.stdout
run(['llvm-objcopy','--strip-debug','--remove-section=.eh_frame',ROOT/'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64',original])
header=out/'original/declarations.h'
variables=set(run([HERE/'original-btf-declarations',original,header]).splitlines())
with original.open('rb') as stream:
 elf=ELFFile(stream);symbols=elf.get_section_by_name('.symtab')
 funcs={s.name:elf.get_section(s['st_shndx']).name for s in symbols.iter_symbols() if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int)}
loads=[json.loads(l) for l in (HERE/'startup-x86/otelcol-ebpf-profiler/loads.jsonl').read_text().splitlines()]
rows=[];manifest=[]
for loaded in loads:
 if loaded['errno']:continue
 # These two successful nonresident loads are profiler/libbpf feature tests,
 # not application programs. Retain their complete inventory separately.
 if not loaded['resident'] and (not loaded['name'] or loaded['name']=='probe_bpf_perf_'):continue
 candidates=[n for n in funcs if n==loaded['full_name'] or n==loaded['name']]
 if not candidates:candidates=[n for n in funcs if n[:15]==loaded['name']]
 if len(candidates)!=1:raise ValueError(('actual OTel source entry not unique',loaded,candidates))
 symbol=candidates[0];name='otel_'+symbol;proof=out/'native'/(name+'.proof.o');source=out/'sources'/(name+'.bpf.c')
 row=dict(name=name,proof=str(proof),source=str(source),stage='generate',ok=False,note='',original_id=loaded['id'],original_name=symbol,original_object=str(original),program_type=loaded['type'],program_section=funcs[symbol],compiler_flags=['-g','-mcpu=v4'],simulator_object=str(out/'objects'/(name+'.linked.bpf.o')))
 try:
  run([ROOT/'kprog/x86/native_lab/native_link/target-c-tail/release/native-link','--input',native,'--symbol',symbol,'--mode','proof','--preserve-entry-abi','--output',proof])
  insns,subs,end,rodata=gen.parse_proof_object_program(name,out/'native')
  text=gen.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section=funcs[symbol],original_source=header,original_symbols=variables)
  text=text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{out}/simulator/kprog/x86/x86_sim_local_bpf.h"').replace('X86_SIM_LICENSE();','')
  source.write_text(text);row['ok']=True
 except ValueError as error:row['note']=str(error)
 rows.append(row)
 manifest.append(dict(program=loaded['name'],source_btf_symbol=symbol,prog_type=loaded['type'],source_bytecode_len=loaded['insn_count']*8,native_object=str(native),symbol=symbol,simulator_object=str(out/'objects'/(name+'.linked.bpf.o')),simulator_program=name+'_x86_sim_xdp'))
(out/'programs.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
(out/'manifest.json').write_text(json.dumps(dict(objects=manifest),indent=2)+'\n')
(out/'load-pairing.json').write_text(json.dumps(loads,indent=2)+'\n')
seen=set()
def freeze(path):
 path=path.resolve()
 if path in seen:return
 seen.add(path);target=out/'simulator'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(path,target)
 for inc in re.findall(r'^#include "([^"]+)"',path.read_text(),re.M):
  child=(path.parent/inc).resolve()
  if child.is_file():freeze(child)
freeze(ROOT/'kprog/x86/x86_sim_local_bpf.h')
print(sum(r['ok'] for r in rows),'/',len(rows),'actual OTel programs generate, including transient read_task_struct; all startup loads retained',flush=True)
for r in rows:
 if not r['ok']:print(r['name'],r['note'],flush=True)
raise SystemExit(int(any(not r['ok'] for r in rows)))
