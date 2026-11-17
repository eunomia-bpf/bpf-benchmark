#!/usr/bin/env python3
"""Compare actual captured helper targets relative to the same kernel helper."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import subprocess
import sys

out = Path('kprog/results/helper-context-query-20261117')
raw = Path(sys.argv[1])
symbols = {}
for line in Path('/workspaces/.agent-state/kprog-ck/build-x86/System.map').read_text().splitlines():
    address, kind, name = line.split()
    symbols[name] = int(address, 16)
anchor = 'bpf_ktime_get_ns'
by_delta = defaultdict(list)
for name, address in symbols.items():
    if name.startswith('bpf_'):
        by_delta[address-symbols[anchor]].append(name)

reports = {}
for mode in ('control', 'query'):
    index = json.loads((out / f'{mode}.json').read_text())
    records = []
    for row in index['captures']:
        plan = json.loads(Path(row['plan']).read_text())
        helpers = {r['name']: r['addr'] for r in plan['helpers']}
        disassembly = subprocess.run(['objdump', '-dr', row['proof']], check=True,
                                     capture_output=True, text=True).stdout
        (raw / mode / (Path(row['capture']).name+'-proof.txt')).write_text(disassembly)
        used = sorted(set(re.findall(r'R_X86_64_PLT32\s+(bpf_\w+)', disassembly)))
        targets = {}
        for name, address in helpers.items():
            if not name.startswith('bpf_'):
                continue
            delta = address-helpers[anchor]
            targets[name] = dict(address=address, relative_to_ktime=delta,
                                 kernel_names=by_delta.get(delta, []))
        records.append(dict(symbol=row['symbol'], capture=row['capture'],
                            linker_returncode=row['linker_returncode'],
                            used_named_helpers=used, targets=targets))
    guest_log = (raw / mode / 'guest.log').read_text()
    runs = re.findall(r'"artifact_run_dir": "([^"]+)"', guest_log)
    corpus_run = Path(runs[-1]) if runs else None
    app = json.loads((corpus_run / 'details/apps/bcc__set.json').read_text()) if corpus_run else None
    phase_counts = {}
    if app:
        for phase in ('baseline', 'post_rejit'):
            programs = app.get(phase, {}).get('bpf', {})
            phase_counts[phase] = dict(programs=len(programs),
                total_calls=sum(p['run_cnt_delta'] for p in programs.values()),
                by_name=[dict(id=p['id'], name=p['name'], type=p['type'],
                              calls=p['run_cnt_delta']) for p in programs.values()])
    reports[mode] = dict(guest_returncode=index['guest_returncode'],
                         corpus_run=str(corpus_run) if corpus_run else None,
                         app_status=app.get('status') if app else None,
                         phase_counts=phase_counts,
                         capture_errors=index['capture_errors'], requests=records)

control = defaultdict(list)
for row in reports['control']['requests']:
    control[row['symbol']].append(row)
comparisons = []
for row in reports['query']['requests']:
    for before in control[row['symbol']]:
        differences = []
        for name in sorted(set(before['targets']) | set(row['targets'])):
            a, b = before['targets'].get(name), row['targets'].get(name)
            if a is None or b is None or a['relative_to_ktime'] != b['relative_to_ktime']:
                differences.append(dict(helper=name, control=a, query=b,
                    used_named_relocation=name in before['used_named_helpers'] or name in row['used_named_helpers']))
        comparisons.append(dict(symbol=row['symbol'], control_capture=before['capture'],
            query_capture=row['capture'], target_differences=differences))
result = dict(anchor=anchor, source_system_map='/workspaces/.agent-state/kprog-ck/build-x86/System.map',
    raw=str(raw), modes=reports, comparisons=comparisons,
    scope='Captured target selection and named PLT32 use only. No native execution, B/stock verification, '
          'output equivalence or official performance gain is inferred from address differences.')
(out / 'targets.json').write_text(json.dumps(result, indent=2)+'\n')
lines = []
for mode, data in reports.items():
    statuses = Counter(str(r['linker_returncode']) for r in data['requests'])
    lines.append(f'{mode}: guest rc={data["guest_returncode"]}, requests={len(data["requests"])}, '
                 f'link statuses={dict(statuses)}, archive errors={len(data["capture_errors"])}')
for row in comparisons:
    used = [r for r in row['target_differences'] if r['used_named_relocation']]
    if used:
        lines.append(row['symbol'])
        for diff in used:
            a, b = diff['control'], diff['query']
            lines.append(f'  {diff["helper"]}: {a["kernel_names"] if a else None} -> '
                         f'{b["kernel_names"] if b else None}')
(out / 'targets-summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
