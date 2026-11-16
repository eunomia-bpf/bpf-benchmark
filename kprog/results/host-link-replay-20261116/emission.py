"""Emit current-P proofs with captured plans, including all fresh Tracee loads.

Fresh capture ownership is explicit: the only adapter job after the four hash
cases is this result's Tracee capture. Names are unique in the Tracee inventory;
other apps keep the inventory's previously resolved source-file pairing.
"""
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path('/workspaces/repository')
raw = Path(sys.argv[1])
old = Path('/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication')
inventory = json.loads((old / 'report.json').read_text())['entries']
proofs = json.loads((raw / 'proofs-initial/report.json').read_text())['entries']
linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
hash_results = ROOT / 'kprog/results/shared-hash-regression-20261116'
prior = {'link-ie2fmz97', 'link-is5ndi7x'}
for case in ['otel-shared', 'otel-copy']:
    prior.update(Path(r['capture']).name for r in json.loads((hash_results / (case + '.link-inputs.json')).read_text()))
captures = ROOT / 'corpus/results/shared-hash-regression-20261116/captures'
tracee = []
for folder in sorted(captures.iterdir()):
    if folder.name in prior:
        continue
    adapter = json.loads((folder / 'adapter.json').read_text())
    tracee.append(dict(app='tracee', symbol=adapter['argv'][adapter['argv'].index('--symbol') + 1],
        folder=str(folder), plan=str(folder / 'link-plan.json'), adapter=adapter))
(raw / 'tracee-inputs.json').write_text(json.dumps(tracee, indent=2) + '\n')
otel = json.loads((hash_results / 'otel-shared.link-inputs.json').read_text())
requests = []
for i, entry in enumerate(inventory):
    if entry['app'] == 'tracee':
        plans = [r['plan'] for r in tracee if r['symbol'] == entry['symbol']]
    elif entry['app'] == 'otelcol-ebpf-profiler':
        plans = [str(Path(r['capture']) / 'link-plan.json') for r in otel if r['symbol'] == entry['symbol']]
    elif entry['app'] == 'katran' and entry['symbol'] == 'balancer_ingress':
        plans = [str(captures / 'link-ie2fmz97/link-plan.json')]
    else:
        plans = [r['command'][r['command'].index('--link-plan') + 1] for r in entry['kernel_replays']]
    for j, plan in enumerate(plans):
        requests.append(dict(index=i, request=j, app=entry['app'], symbol=entry['symbol'],
            native=entry['native'], plan=plan, proof_status=proofs[i]['status']))
unknown = [r for r in tracee if not any(e['app'] == 'tracee' and e['symbol'] == r['symbol'] for e in inventory)]
if len(sys.argv) > 2 and sys.argv[2] == '--dry-run':
    print(json.dumps(dict(requests=dict(Counter(r['app'] for r in requests)),
                         fresh_tracee=len(tracee), unmatched_tracee=unknown), indent=2))
    sys.exit(0)
output = Path(sys.argv[2]) if len(sys.argv) > 2 else raw / 'emission-initial'
output.mkdir(exist_ok=False)


def emit(row):
    row = dict(row)
    folder = output / (str(row['index']) + '-' + str(row['request']))
    folder.mkdir()
    if row['proof_status'] != 'ok':
        row['status'] = 'proof_error'
        return row
    command = [str(linker), '--input', str(raw / 'proofs-initial' / str(row['index']) / 'entry.proof.o'),
        '--symbol', row['symbol'], '--mode', 'kernel', '--link-plan', row['plan'],
        '--output', str(folder / 'image.blob'), '--output-relocs', str(folder / 'image.relocs'),
        '--output-map-patches', str(folder / 'image.maps'), '--output-abi', str(folder / 'image.abi')]
    (folder / 'command.json').write_text(json.dumps(command, indent=2) + '\n')
    with (folder / 'stdout').open('w') as stdout, (folder / 'stderr').open('w') as stderr:
        child = subprocess.run(command, stdout=stdout, stderr=stderr)
    row.update(command=command, returncode=child.returncode, status='ok' if child.returncode == 0 else 'kernel_error')
    if row['status'] == 'ok':
        row['payload_bytes'] = (folder / 'image.blob').stat().st_size
    (folder / 'result.json').write_text(json.dumps(row, indent=2) + '\n')
    print(json.dumps(dict(app=row['app'], symbol=row['symbol'], status=row['status'])), flush=True)
    return row


with ThreadPoolExecutor(max_workers=2) as pool:
    rows = list(pool.map(emit, requests))
summary = {app: dict(Counter(r['status'] for r in rows if r['app'] == app))
           for app in sorted({r['app'] for r in rows})}
result = dict(scope=__doc__, summary=summary, unmatched_tracee=unknown, entries=rows)
(output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(summary, indent=2))
sys.exit(0 if not unknown and all(r['status'] == 'ok' for r in rows) else 2)
