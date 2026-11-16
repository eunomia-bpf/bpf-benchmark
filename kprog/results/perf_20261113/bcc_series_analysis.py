#!/usr/bin/env python3
"""Read retained stress-ng wall/CPU rates without changing the workload."""
import argparse
import json
from pathlib import Path
import statistics

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--run', type=Path, required=True)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
app = json.loads((args.run/'details/apps/bcc__set.json').read_text())
phases = {}
for phase in ['baseline', 'post_rejit']:
    samples = []
    for workload in app[phase]['workloads']:
        metrics = {}
        for line in workload['stdout'].splitlines():
            if 'stress-ng: metrc:' not in line:
                continue
            fields = line.split('] ', 1)[1].split()
            if fields[0] not in ['syscall', 'cap', 'set', 'sockfd']:
                continue
            ops, seconds, user, system, wall_rate, cpu_rate = map(float, fields[1:])
            metrics[fields[0]] = dict(ops=ops, seconds=seconds, user_seconds=user,
                                     system_seconds=system, wall_ops_per_second=wall_rate,
                                     cpu_ops_per_second=cpu_rate, cpu_seconds=user+system)
        samples.append(dict(metrics=metrics, total_wall_ops_per_second=sum(
            value['wall_ops_per_second'] for value in metrics.values())))
    phases[phase] = samples
native = phases['post_rejit']
changes = {}
for stressor in native[0]['metrics']:
    first, last = [sample['metrics'][stressor] for sample in [native[0], native[-1]]]
    changes[stressor] = {key: last[key]/first[key] for key in
                         ['wall_ops_per_second', 'cpu_ops_per_second', 'cpu_seconds']}
log = args.run/'details/shim-logs/bcc__set.post_rejit.log'
events = [line for line in log.read_text().splitlines() if 'native-loader replaced' in line]
times = [float(line.split()[0][1:]) for line in events]
result = dict(run=str(args.run), status=app['status'], error=app['error'], phases=phases,
              native_last_over_first=changes,
              ratio_of_phase_median_total_wall_rate=statistics.median(s['total_wall_ops_per_second'] for s in native)/
                  statistics.median(s['total_wall_ops_per_second'] for s in phases['baseline']),
              replacement_count=len(events), replacement_first_boot_seconds=min(times),
              replacement_last_boot_seconds=max(times),
              programs={p:len(app[p]['bpf']) for p in phases},
              scope='Stats off; no per-program time or scheduler/steal attribution. Stress-ng CPU times include its own accounting and rounding.')
args.output.mkdir(parents=True, exist_ok=True)
(args.output/'analysis.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:result[k] for k in ['ratio_of_phase_median_total_wall_rate',
    'native_last_over_first','replacement_count','replacement_first_boot_seconds','replacement_last_boot_seconds']},indent=2))
