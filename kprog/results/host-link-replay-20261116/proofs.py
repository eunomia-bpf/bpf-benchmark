"""Extract current-P entry proofs using the runtime loader's ABI contract.

The retained inventory identifies canonical source P and captured contexts.
Candidate ELF symbols are not runtime program counts. Kernel emission and B
stock verification are separate steps; no unavailable runtime facts are made up.
"""
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path('/workspaces/repository')
INVENTORY = Path('/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication/report.json')
LINKER = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
COMPILER = ROOT / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
KERNEL = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
entries = json.loads(INVENTORY.read_text())['entries']
if sys.argv[1] == '--dry-run':
    print(json.dumps(dict(entries=dict(Counter(e['app'] for e in entries)),
        context_conversions=sum(e['context_lto'] is not None for e in entries),
        linker=str(LINKER), compiler=str(COMPILER), kernel_btf=str(KERNEL),
        preserve_entry_abi=False, workers=2), indent=2))
    sys.exit(0)
output = Path(sys.argv[1])
output.mkdir(parents=True, exist_ok=False)


def invoke(command, folder, label):
    (folder / (label + '.command.json')).write_text(json.dumps(command, indent=2) + '\n')
    with (folder / (label + '.stdout')).open('w') as stdout, (folder / (label + '.stderr')).open('w') as stderr:
        child = subprocess.run(command, stdout=stdout, stderr=stderr)
    return dict(command=command, returncode=child.returncode,
                stdout=str(folder / (label + '.stdout')), stderr=str(folder / (label + '.stderr')))


def extract(item):
    index, entry = item
    folder = output / str(index)
    folder.mkdir()
    native = Path(entry['native'])
    row = dict(index=index, app=entry['app'], native=str(native), symbol=entry['symbol'],
        source_files=entry['source_files'], captured_contexts=entry['captured_contexts'],
        runtime_fact_scope='PERF_EVENT conversion where recorded; no supplied immutable/map-template/function-body sidecars')
    if entry['context_lto'] is not None:
        converted = folder / 'physical.native.o'
        row['context_lto'] = invoke([str(COMPILER), str(native), '--symbol', entry['symbol'],
            '--kernel-btf', str(KERNEL), '--prog-type', '7', '-o', str(converted)], folder, 'context')
        if row['context_lto']['returncode'] != 0:
            row['status'] = 'context_error'
            (folder / 'result.json').write_text(json.dumps(row, indent=2) + '\n')
            return row
        native = converted
    proof = folder / 'entry.proof.o'
    # Exactly native_loader_entry_data.hpp:33-43; the old retained replay used
    # preserve-entry-abi, which does not match runtime proof extraction.
    row['proof'] = invoke([str(LINKER), '--input', str(native), '--symbol', entry['symbol'],
        '--output', str(proof), '--mode', 'proof'], folder, 'proof')
    row['status'] = 'ok' if row['proof']['returncode'] == 0 else 'proof_error'
    if row['status'] == 'ok':
        row['proof_bytes'] = proof.stat().st_size
    (folder / 'result.json').write_text(json.dumps(row, indent=2) + '\n')
    print(json.dumps(dict(index=index, app=row['app'], symbol=row['symbol'], status=row['status'])), flush=True)
    return row


with ThreadPoolExecutor(max_workers=2) as pool:
    rows = list(pool.map(extract, enumerate(entries)))
summary = {app: dict(Counter(r['status'] for r in rows if r['app'] == app))
           for app in sorted({r['app'] for r in rows})}
result = dict(scope=__doc__, inventory=str(INVENTORY), summary=summary, entries=rows)
(output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(summary, indent=2))
sys.exit(0 if all(r['status'] == 'ok' for r in rows) else 2)
