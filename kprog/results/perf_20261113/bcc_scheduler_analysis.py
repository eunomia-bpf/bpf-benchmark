"""Retained BCC scheduler counts beside each stressor's actual work and CPU time."""
import argparse
import json
from pathlib import Path
import tarfile


def workload_samples(phase):
    rows = []
    for workload in phase['workloads']:
        metrics = {}
        for line in workload['stdout'].splitlines():
            if 'stress-ng: metrc:' not in line:
                continue
            fields = line.split('] ', 1)[1].split()
            if fields[0] in {'syscall', 'cap', 'set', 'sockfd'}:
                ops, seconds, user, system, wall_rate, cpu_rate = map(float, fields[1:])
                metrics[fields[0]] = dict(ops=ops, seconds=seconds, cpu_seconds=user+system,
                    wall_rate=wall_rate, cpu_rate=cpu_rate)
        rows.append(dict(command=workload['command'], duration=workload['duration_s'], metrics=metrics))
    return rows


def package(image):
    with tarfile.open(image) as outer:
        manifest = json.load(outer.extractfile('manifest.json'))[0]
        for layer in reversed(manifest['Layers']):
            with tarfile.open(fileobj=outer.extractfile(layer)) as inner:
                names = {m.name.lstrip('./'): m for m in inner.getmembers()}
                if 'var/lib/dpkg/status' in names:
                    text = inner.extractfile(names['var/lib/dpkg/status']).read().decode()
                    for block in text.split('\n\n'):
                        if block.startswith('Package: stress-ng\n'):
                            return dict(line.split(': ', 1) for line in block.splitlines()
                                        if line.startswith(('Package:', 'Version:', 'Architecture:')))
                    raise ValueError('stress-ng absent from image package status')
    raise ValueError('image lacks package status')


def analyze(run):
    app = json.loads((run/'details/apps/bcc__set.json').read_text())
    metadata = json.loads((run/'metadata.json').read_text())
    phases = {}
    for name in ('baseline', 'post_rejit'):
        phase = app[name]
        samples = workload_samples(phase)
        groups = {}
        for program in phase['bpf'].values():
            key = program['type']+'/'+program['name']
            group = groups.setdefault(key, dict(ids=[], calls=0, ns=0))
            group['ids'].append(program['id'])
            group['calls'] += program['run_cnt_delta']
            group['ns'] += program['run_time_ns_delta']
        totals = {stressor: {key: sum(s['metrics'][stressor][key] for s in samples)
                            for key in ('ops', 'cpu_seconds')}
                  for stressor in samples[0]['metrics']}
        switches = next(g['calls'] for k, g in groups.items() if k.endswith('/sched_switch'))
        phases[name] = dict(samples=samples, stressor_totals=totals, program_groups=groups,
            switches_per_sockfd_operation=switches/totals['sockfd']['ops'])
    before, after = (phases[n] for n in ('baseline', 'post_rejit'))
    return dict(run=str(run), status=app['status'], samples=metadata['samples'],
        workload_seconds=metadata['workload_seconds'], phases=phases,
        native_over_baseline_calls={key: after['program_groups'][key]['calls']/value['calls']
            if value['calls'] else None for key, value in before['program_groups'].items()},
        native_over_baseline_stressor_totals={stressor: {
            key: after['stressor_totals'][stressor][key]/value
            for key, value in metrics.items()} for stressor, metrics in before['stressor_totals'].items()})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run', type=Path, action='append', required=True)
    parser.add_argument('--image', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    rows = [analyze(run) for run in args.run]
    result = dict(runs=rows, image=str(args.image), current_image_package=package(args.image),
        source='https://github.com/ColinIanKing/stress-ng/blob/V0.17.06/stress-sockfd.c',
        scope='All recorded program identities retained in type/name groups; no threshold or exclusions. Ratios show changed work, not historical per-task attribution. Current image package status is read without executing it.')
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output/'analysis.json').write_text(json.dumps(result, indent=2)+'\n')
    for row in rows:
        print(row['run'], row['native_over_baseline_calls']['tracing/sched_switch'])


if __name__ == '__main__':
    main()
