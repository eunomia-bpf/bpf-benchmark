#!/usr/bin/env python3
"""Read completed OTel coordinator runs; keep native time and baseline movement separate."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
APP = 'otelcol-ebpf-profiler__profiling'
rows = []
for stage, suffix in [('zero_remainder', '051422_856006'), ('user_leaf', '063024_376511')]:
    run = REPO / ('corpus/results/x86_kvm_corpus_20261117_' + suffix)
    app = json.loads((run / 'details/apps' / (APP + '.json')).read_text())
    phases = {}
    for phase in ('baseline', 'post_rejit'):
        records = list(app[phase]['bpf'].values())
        selected = [{key: r[key] for key in ('id', 'name', 'type', 'run_cnt_delta', 'run_time_ns_delta')}
                    for r in records if r['run_cnt_delta'] >= 100]
        calls = sum(r['run_cnt_delta'] for r in selected)
        elapsed = sum(r['run_time_ns_delta'] for r in selected)
        phases[phase] = dict(records=len(records), selected=selected, calls=calls,
                             elapsed_ns=elapsed, ns_per_call=elapsed / calls)
    installed = subprocess.check_output([
        'python3', str(REPO / 'kprog/results/flag-tuning-20261117/inst.py'), str(run)], text=True).strip()
    row = dict(stage=stage, run=str(run.relative_to(REPO)), phases=phases,
               per_call_speedup=phases['baseline']['ns_per_call'] / phases['post_rejit']['ns_per_call'],
               installed_cumulative_receipt=installed)
    rows.append(row)
    print(stage, 'ns/call', {phase: round(data['ns_per_call'], 4) for phase, data in phases.items()})
    for phase, data in phases.items():
        print(phase, [(r['name'], r['run_cnt_delta'],
                       round(100 * r['run_time_ns_delta'] / data['elapsed_ns'], 7))
                      for r in data['selected']])

ratios = {phase: rows[1]['phases'][phase]['ns_per_call'] / rows[0]['phases'][phase]['ns_per_call']
          for phase in ('baseline', 'post_rejit')}
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Completed OTel coordinator stats-on 3x60s run pair; existing >=100-call reporting convention. IDs identify records within their own boot only. Installed receipts count cumulative replacements, not measurement snapshots. No causal gain, PMU split, equal-work proof or new admission check is inferred.',
              after_before_ns_ratios=ratios, runs=rows)
(HERE / 'leaf-read-effects.json').write_text(json.dumps(result, indent=2) + '\n')
print('after/before ns ratios:', ratios)
