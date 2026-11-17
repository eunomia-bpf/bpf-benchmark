#!/usr/bin/env python3
"""Record shared-return jumps in retained ARRAY routines, without rewriting."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
evidence = json.loads((here / 'evidence.json').read_text())['typed_unwinder']
blob = Path(evidence['blob'])
data = blob.read_bytes()
rows = []
for region in evidence['ranges']:
    kind = region['piece']
    if kind not in ('known_array', 'runtime_array'):
        continue
    first, last = region['start'], region['end']
    code = data[first:last]
    marker = bytes.fromhex('eb0231c0c3' if kind == 'known_array' else 'eb0431c0eb00c3')
    local = code.index(marker)
    disassembly = subprocess.check_output([
        'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
        '--no-show-raw-insn', '--start-address=' + str(first),
        '--stop-address=' + str(last), str(blob)], text=True)
    rows.append(dict(piece=kind, start=first, end=last, original_bytes=last-first,
                     marker_offset=first+local, marker_bytes=marker.hex(),
                     successful_path_unconditional_jumps_removable=1,
                     missing_path_unconditional_jumps_removable=0 if kind == 'known_array' else 1,
                     local_bytes_removable_with_separate_returns=1 if kind == 'known_array' else 3,
                     disassembly=disassembly))
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Retained historical OTel helper byte patterns and decoded control flow. Separate-return layout is arithmetic only; no candidate byte vector was emitted or executed. Per-call/app size effects unmeasured; non-ARRAY fallback unaffected.',
    blob=str(blob), routines=rows)
(here / 'array-returns.json').write_text(json.dumps(result, indent=2) + '\n')
print([(r['piece'], r['original_bytes'], r['local_bytes_removable_with_separate_returns'])
       for r in rows])
