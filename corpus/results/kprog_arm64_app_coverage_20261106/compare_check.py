"""Regenerate the unchanged event dispatcher using the composed CMP/B.GT."""
import json
from pathlib import Path
import shutil
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
import coverage

phase = Path(sys.argv[1]).resolve()
phase.mkdir(exist_ok=True)
sources = phase/'sources'
sources.mkdir(exist_ok=True)
name = 'trace_event_type_switch_dispatch'
original = next(row for row in coverage.records(HERE/'register-cells-v2') if row['name']==name)
proofs = Path(original['proof']).parent
gen.generate_one(gen.Bench(name, name+'_xdp', 'xdp'), gen.MICRO_PROGRAMS, sources, proofs)
coverage.freeze_simulator(phase)
(phase/'inputs').mkdir(exist_ok=True)
data = phase/'inputs'/(name+'.mem')
shutil.copy2(original['input_file'], data)
row = dict(original, source=str(sources/(name+'.bpf.c')), input_file=str(data),
           note='CMP/B.GT composition; unchanged linked native proof, original input and goldens')
(phase/'programs.jsonl').write_text(json.dumps(row)+'\n')
print(f'generated {name}: original input and expected result retained')
