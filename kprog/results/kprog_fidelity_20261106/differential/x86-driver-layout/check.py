"""Catch state-layout or observer regressions while adding the Arm vector bank."""
import csv
import json
from pathlib import Path
import subprocess
import sys

out = Path(__file__).resolve().parent
run = subprocess.run([sys.argv[1], '16', str(out)], text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
(out/'run.log').write_text(run.stdout)
if run.returncode != 1:
    raise RuntimeError(f'expected retained SP differences, got rc{run.returncode}: {run.stdout}')
with (out.parent/'x86-after-lea-complete/forms.tsv').open() as file:
    baseline = list(csv.DictReader(file, delimiter='\t'))
with (out/'forms.tsv').open() as file:
    current = list(csv.DictReader(file, delimiter='\t'))
if len(current) != len(baseline):
    raise RuntimeError('form count changed')
changes = [dict(before=a, after=b) for a,b in zip(baseline,current)
           if a['assembly'] != b['assembly'] or a['opcode'] != b['opcode']
           or (int(a['mismatches']) != 0) != (int(b['mismatches']) != 0)]
(out/'layout-outcomes.json').write_text(json.dumps(dict(forms=len(current), cases=16*len(current), changed_rows=changes), indent=2)+'\n')
if changes:
    raise RuntimeError(f'{len(changes)} rows changed agreement with the CPU')
print(f'{len(current)} forms: unchanged CPU agreement after driver layout extension')
