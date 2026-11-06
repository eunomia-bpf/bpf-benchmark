"""Apply canonical C constant-op specialization to a frozen result phase."""
import json
from pathlib import Path
import re
import shutil
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT/'kprog/arm64'))
from generate_sim_dispatch import render

destination, original = (Path(p).resolve() for p in sys.argv[1:])
destination.mkdir(exist_ok=True)
for name in ['simulator', 'formal']:
    shutil.copytree(original/name, destination/name)
(destination/'sources').mkdir(exist_ok=True)
rows = [json.loads(line) for line in (original/'programs.jsonl').read_text().splitlines()]
header = destination/'simulator/arm64_sim_local_bpf.h'
expected = render(header, destination/'simulator/arm64_sim.h',
                  ROOT/'kprog/arm64/build/constant-dispatch'/destination.name)
(header.parent/'arm64_sim_direct.h').write_text(expected)
text = header.read_text()
if '#include "arm64_sim_direct.h"' not in text:
    last = text.rindex('#endif')
    header.write_text(text[:last]+'#include "arm64_sim_direct.h"\n'+text[last:])
for row in rows:
    source = destination/'sources'/Path(row['source']).name
    source.write_text(Path(row['source']).read_text().replace(
        'ARM64_SIM_RUN_OP3(', 'ARM64_SIM_RUN_KNOWN_OP3('))
    row['source'] = str(source)
    if 'input_file' in row:
        (destination/'inputs').mkdir(exist_ok=True)
        data = destination/'inputs'/Path(row['input_file']).name
        shutil.copy2(row['input_file'], data)
        row['input_file'] = str(data)
    row['note'] = 'mechanical constant-op dispatch; original native proof, input and expected result'
(destination/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
mapping = dict(re.findall(r'#define ARM64_SIM_DIRECT_(ARM64_OP_\w+).*?\nARM64_SIM_DIRECT_BODY_(\d+)', expected))
(destination/'dispatch-map.json').write_text(json.dumps(mapping, indent=2)+'\n')
print(f'{len(mapping)} literal opcodes use unchanged canonical C bodies')
