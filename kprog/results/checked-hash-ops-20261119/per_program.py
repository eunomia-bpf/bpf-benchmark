"""Retain every program's aggregate counters; no call-count admission gate."""
import json
from pathlib import Path
import sys

source, output = map(Path, sys.argv[1:])
app = json.loads(source.read_text())
phases = {}
for phase in ['baseline', 'post_rejit']:
    rows = []
    for record in app[phase]['bpf'].values():
        calls = record['run_cnt_delta']
        rows.append(dict(record, ns_per_call=record['run_time_ns_delta']/calls if calls else None))
    phases[phase] = sorted(rows, key=lambda row: row['run_time_ns_delta'], reverse=True)
output.write_text(json.dumps(dict(source=str(source), phases=phases,
    scope='All per-program phase aggregates, including zero-call records. '
          'The raw data has no per-sample BPF-time split; no growth-over-time '
          'or body/helper/map attribution is inferred.'), indent=2)+'\n')
