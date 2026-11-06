"""Retain load-only counterexamples for the old partial-store tag behavior."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage

ROOT=Path(__file__).resolve().parents[3]
phase=Path(sys.argv[1]).resolve();phase.mkdir();(phase/'sources').mkdir()
original=phase.parent/'return-byte-forgery'
rows=[]
for row in coverage.records(original):
    if row['name'] not in {'partial_saved_lr','crossword_saved_lr'}: continue
    row={k:v for k,v in row.items() if k not in {'input_file','expected_result','expected_retval','result_channel','cgroup_skb_input'}}
    target=phase/'sources'/Path(row['source']).name
    shutil.copy2(row['source'],target);row['source']=str(target)
    rows.append(row)
if len(rows)!=2: raise RuntimeError('both partial-store counterexamples are required')
(phase/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
coverage.freeze_simulator(phase)
p=phase/'simulator/arm64_sim_local_bpf.h';current=p.read_text()
old=subprocess.check_output(['git','show','ceed44baf:kprog/arm64/arm64_sim_local_bpf.h'],text=True,cwd=ROOT)
begin='#define ARM64_SIM_L_STACK_WRITE_TAG(';end='#define ARM64_SIM_L_STACK_WRITE('
p.write_text(current[:current.index(begin)]+old[old.index(begin):old.index(end)]+current[current.index(end):])
print('two unsafe native partial-LR writes retained as proof-load-only cases; no native code executes')
