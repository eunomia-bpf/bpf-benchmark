#!/usr/bin/env python3
"""Read retained link outputs; no linking, builds, guests or admission checks."""
import collections
import json
from pathlib import Path
import struct
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
RAW = Path('/workspaces/kprog-raw/perf/20261116-inner-array-lto/libbpf')
blob = RAW / 'otel-typed.blob'
data = blob.read_bytes()
ranges = []
for line in (RAW / 'otel-typed-kernel.log').read_text().splitlines():
    if line.startswith('native-link-lto-range '):
        ranges.append(json.loads(line.split(' ', 1)[1]))
array = next(r for r in ranges if r['piece'] == 'runtime_array')
lpm = next(r for r in ranges if r['piece'] == 'lpm_lookup')
call = array['start'] + 57
destination = call + 5 + int.from_bytes(data[call + 1:call + 5], 'little', signed=True)
tracee = json.loads((REPO / 'kprog/results/host-link-replay-20261116/tracee-inputs.json').read_text())
counts = collections.Counter()
examples = {}
for entry in tracee:
    folder = Path(entry['folder'])
    plan = json.loads((folder / 'link-plan.json').read_text())
    names = collections.defaultdict(list)
    for helper in plan['helpers']:
        names[helper['addr']].append(helper['name'])
    for offset, kind, target in struct.iter_unpack('<IIQ', (folder / 'shared.relocs').read_bytes()):
        aliases = sorted(n for n in names[target] if 'probe_read' in n)
        if kind == 1 and aliases:
            key = '/'.join(aliases)
            counts[key] += 1
            examples.setdefault(key, dict(symbol=entry['symbol'], folder=str(folder), offset=offset))
result = {
    'recorded_utc': subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    'review_source_commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=REPO, text=True).strip(),
    'typed_unwinder': {'blob': str(blob), 'payload_bytes': len(data), 'ranges': ranges,
                      'array_fallback_call': call, 'array_fallback_destination': destination,
                      'lpm_start': lpm['start']},
    'tracee': {'inputs': 'kprog/results/host-link-replay-20261116/tracee-inputs.json',
               'captured_programs': len(tracee), 'remaining_static_helper_call_sites': dict(counts),
               'examples': examples,
               'scope': 'Static relocation sites in retained per-entry blobs, not dynamic call counts; shared callee text may recur across entries.'},
}
(HERE / 'evidence.json').write_text(json.dumps(result, indent=2) + '\n')
selected = [r for r in ranges if r['piece'] in ('runtime_array', 'probe_read', 'lpm_lookup')]
with (HERE / 'typed-unwinder.disassembly.txt').open('w') as output:
    output.write('Retained host-linked payload; external helper E8 slots are not yet kernel patched.\n')
    for region in selected:
        output.write('\n' + json.dumps(region) + '\n')
        subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
                        '--start-address=' + str(region['start']), '--stop-address=' + str(region['end']),
                        str(blob)], stdout=output, check=True)
print(json.dumps({'payload_bytes': len(data), 'array_fallback': hex(destination),
                  'tracee_static_sites': dict(counts)}))
