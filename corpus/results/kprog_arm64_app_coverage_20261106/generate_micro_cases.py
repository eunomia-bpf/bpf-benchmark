"""Generate all original micro proofs and preserve their input/golden contracts."""
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
(phase/'sources').mkdir(exist_ok=True)
(phase/'inputs').mkdir(exist_ok=True)
benches = {bench.name: bench for bench in gen.load_benches(gen.CONFIG)}
rows = []
for original in coverage.records(HERE/'register-cells-v2'):
    row = dict(original)
    name = row['name']
    gen.generate_one(benches[name], gen.MICRO_PROGRAMS, phase/'sources', Path(row['proof']).parent)
    data = phase/'inputs'/Path(row['input_file']).name
    shutil.copy2(row['input_file'], data)
    row.update(source=str(phase/'sources'/(name+'.bpf.c')), input_file=str(data),
               note='all original micro native artifacts, inputs and golden outputs; current composed generator')
    rows.append(row)
(phase/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
coverage.freeze_simulator(phase)
print(f'{len(rows)} unchanged native artifacts and original input/golden contracts generated')
