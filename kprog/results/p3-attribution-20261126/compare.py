"""Post-hoc 05-29 ns/call calculation and program-name/type mix, never runner code."""
import collections
import json
from pathlib import Path
import sys

rows = []
for target in sys.argv[1:]:
    run = Path(target)
    sources = sorted((run / 'details/apps').glob('*.json'))
    if len(sources) != 1:
        raise ValueError('expected one app record: ' + target)
    app = json.loads(sources[0].read_text())
    metadata = json.loads((run / 'metadata.json').read_text())
    row = dict(run=str(run), app=app['app'], status=app['status'], error=app['error'],
               metadata={k: metadata.get(k) for k in ('samples', 'workload_seconds', 'bpf_stats')})
    for phase in ('baseline', 'post_rejit'):
        records = list(app[phase]['bpf'].values())
        # Match native_eval_20260529.py:bpf_aggregate exactly, including its existing >=100 filter.
        retained = [r for r in records if r.get('run_cnt_delta', 0) >= 100]
        count = sum(r['run_cnt_delta'] for r in retained)
        elapsed = sum(r['run_time_ns_delta'] for r in retained)
        groups = collections.defaultdict(lambda: dict(calls=0, time_ns=0, ids=[]))
        for record in retained:
            key = record['name'] + ':' + str(record['type'])
            groups[key]['calls'] += record['run_cnt_delta']
            groups[key]['time_ns'] += record['run_time_ns_delta']
            groups[key]['ids'].append(record['id'])
        for group in groups.values():
            group['ns_per_call'] = group['time_ns'] / group['calls']
            group['call_share'] = group['calls'] / count
            group['time_share'] = group['time_ns'] / elapsed if elapsed else None
        row[phase] = dict(ns_per_call=elapsed / count if count else None, calls=count, time_ns=elapsed,
                          retained=len(retained), records=len(records),
                          groups=dict(sorted(groups.items(), key=lambda pair: -pair[1]['time_ns'])))
    rows.append(row)
print(json.dumps(rows, indent=2))
