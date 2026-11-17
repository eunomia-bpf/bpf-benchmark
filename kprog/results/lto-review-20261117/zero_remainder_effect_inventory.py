#!/usr/bin/env python3
"""Read completed coordinator runs; no framework changes or benchmark execution."""
from collections import defaultdict
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
RUNS = (
    ('otelcol-ebpf-profiler__profiling', '035907_339709', '051422_856006'),
    ('bcc__set', '041017_749964', '052524_924865'),
    ('tracee__monitor', '044227_741393', '053609_920585'),
)
PREFIX = re.compile(r'^\[([^]]+) pid=(\d+) tid=(\d+)\] (.*)$')
INFO = re.compile(r'native-loader jit-info (original|native) fd=(\d+) id=(\d+) '
                  r'type=(\d+) name=(\S*) tag=\S+ jited_len=(\d+)')


def read_run(app, suffix):
    run = REPO / ('corpus/results/x86_kvm_corpus_20261117_' + suffix)
    data = json.loads((run / 'details/apps' / (app + '.json')).read_text())
    phases = {}
    for phase in ('baseline', 'post_rejit'):
        records = list(data[phase]['bpf'].values())
        # Existing docs/archive/native_eval_20260529.py:194-204 analysis.
        selected = [r for r in records if r['run_cnt_delta'] >= 100]
        calls = sum(r['run_cnt_delta'] for r in selected)
        elapsed = sum(r['run_time_ns_delta'] for r in selected)
        phases[phase] = dict(records=len(records), selected=len(selected), calls=calls,
                             elapsed_ns=elapsed, ns_per_call=elapsed / calls)
    pending, installed = {}, {}
    log = run / 'details/shim-logs' / (app + '.post_rejit.log')
    for line in log.read_text().splitlines():
        match = PREFIX.match(line)
        if not match:
            continue
        _, pid, tid, message = match.groups()
        key = (pid, tid)
        if match := INFO.match(message):
            kind, fd, prog, type_id, name, size = match.groups()
            pending.setdefault(key, {})[kind] = dict(id=int(prog), type=int(type_id),
                                                     name=name, bytes=int(size))
        if message.startswith('native-loader replaced prog='):
            pair = pending.pop(key)
            installed[pair['native']['id']] = pair
    groups = defaultdict(lambda: dict(count=0, original_bytes=0, native_bytes=0))
    for pair in installed.values():
        original, native = pair['original'], pair['native']
        group = groups[(original['type'], original['name'], original['bytes'])]
        group['count'] += 1
        group['original_bytes'] += original['bytes']
        group['native_bytes'] += native['bytes']
    return dict(run=str(run.relative_to(REPO)), phases=phases,
                cumulative_replacement_programs=len(installed),
                original_bytes=sum(p['original']['bytes'] for p in installed.values()),
                native_bytes=sum(p['native']['bytes'] for p in installed.values())), groups


apps = []
for app, first, second in RUNS:
    before, a = read_run(app, first)
    after, b = read_run(app, second)
    groups = [dict(type=k[0], name=k[1], original_program_bytes=k[2],
                   before=a.get(k), after=b.get(k)) for k in sorted(a.keys() | b.keys())]
    row = dict(app=app, before=before, after=after, groups=groups,
               native_byte_delta=after['native_bytes'] - before['native_bytes'],
               baseline_ns_ratio=after['phases']['baseline']['ns_per_call'] / before['phases']['baseline']['ns_per_call'],
               native_ns_ratio=after['phases']['post_rejit']['ns_per_call'] / before['phases']['post_rejit']['ns_per_call'])
    apps.append(row)
    print(app, 'native byte delta', row['native_byte_delta'],
          'after/before baseline ns', round(row['baseline_ns_ratio'], 4),
          'native ns', round(row['native_ns_ratio'], 4))

result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Completed coordinator run pairs, cumulative replacement populations. IDs are joined only within a boot; cross-run groups are type/name/original-size multisets, not proof of program identity. This inventory uses the existing >=100-call reporting convention, adds no admission check and discards no run. Tracee first post-change run retained; second run belongs to coordinator. No PMU/body/helper/map attribution or causal speedup inferred.', apps=apps)
(HERE / 'zero-remainder-effects.json').write_text(json.dumps(result, indent=2) + '\n')
