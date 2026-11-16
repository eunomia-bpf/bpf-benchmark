"""Read installed bytes and invocation costs from retained BCC/OTel runs."""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CASES = [
    ('bcc', 'current-stats-off', '20261116_105138_635552'),
    ('bcc', 'retained-stats-on', '20261116_060435_731340'),
    ('otel', 'named-array', '20261114_030302_441920'),
    ('otel', 'typed-hash', '20261114_033202_840307'),
    ('otel', 'read-hash-array-lpm', '20261114_112435_142525'),
    ('otel', 'combined-codegen-lto', '20261114_145101_018174'),
    ('otel', 'corrected-all-lto', '20261114_174202_766748'),
    ('otel', 'current-stats-off', '20261116_102445_806916'),
]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
rows = []
for app, configuration, run in CASES:
    filename = 'bcc__set.json' if app == 'bcc' else 'otelcol-ebpf-profiler__profiling.json'
    path = ROOT/'corpus/results'/('x86_kvm_corpus_'+run)/'details/apps'/filename
    data = json.loads(path.read_text())
    row = dict(app=app, configuration=configuration, source=str(path), phases={})
    for phase in ('baseline', 'post_rejit'):
        programs = data[phase]['bpf']
        row['phases'][phase] = dict(programs=programs, count=len(programs),
            installed_bytes=sum(p['bytes_jited'] for p in programs.values()),
            named_groups={})
        groups = row['phases'][phase]['named_groups']
        for program in programs.values():
            group = groups.setdefault(program['name'], dict(ids=[], calls=0, ns=0, bytes=0))
            group['ids'].append(program['id'])
            group['calls'] += program['run_cnt_delta']
            group['ns'] += program['run_time_ns_delta']
            group['bytes'] += program['bytes_jited']
        for group in groups.values():
            group['ns_per_call'] = group['ns']/group['calls'] if group['calls'] else None
    row['native_over_jit_installed_bytes'] = (
        row['phases']['post_rejit']['installed_bytes']/row['phases']['baseline']['installed_bytes'])
    rows.append(row)
(args.output/'analysis.json').write_text(json.dumps(dict(runs=rows,
    scope='Every recorded program retained, no run-count filter. Named groups preserve colliding IDs. Installed bytes are BPF info bytes_jited; historical configurations are not isolated component comparisons.'), indent=2)+'\n')
