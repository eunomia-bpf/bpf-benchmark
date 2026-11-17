#!/usr/bin/env python3
"""Read retained OTel phase counters; no new run or counter export."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
rows = []
for candidate, run in [('Os', '010914_990572'), ('O2', '020132_158734')]:
    directory = repo / ('corpus/results/x86_kvm_corpus_20261117_' + run)
    detail = directory / 'details'
    app = json.loads((detail / 'apps/otelcol-ebpf-profiler__profiling.json').read_text())
    phases = {}
    for phase in ('baseline', 'post_rejit'):
        entries = [p for p in app[phase]['bpf'].values() if p['name'] == 'native_tracer_e']
        record = entries[0]
        phases[phase] = dict(record=record,
                             ns_per_invocation=record['run_time_ns_delta'] / record['run_cnt_delta'],
                             positive_count_programs=[p['name'] for p in app[phase]['bpf'].values()
                                                      if p['run_cnt_delta']])
    log = (detail / 'shim-logs/otelcol-ebpf-profiler__profiling.post_rejit.log').read_text()
    # Describe retained artifact availability, without inferring counter values.
    scrapes = [str(path.relative_to(directory)) for path in detail.rglob('*')
               if path.is_file() and ('collector-8888' in path.name or 'collector-6060' in path.name)]
    rows.append(dict(candidate=candidate, run=str(directory), app_status=app['status'],
                     phases=phases, native_replacement_events=log.count('native-loader replaced prog='),
                     native_failure_events=log.count('native-loader failed prog='),
                     retained_collector_scrapes=scrapes))
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Raw entry counters and scrape availability only. Entry counts do not measure unwind attempts, and tail-program zero counts do not prove tail nonexecution. O2 equal-work status and cause remain unresolved.',
              candidates=rows)
(here / 'otel-flag-paths.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps([dict(candidate=row['candidate'],
                      native_ns_per_invocation=row['phases']['post_rejit']['ns_per_invocation'],
                      native_replacements=row['native_replacement_events']) for row in rows]))
