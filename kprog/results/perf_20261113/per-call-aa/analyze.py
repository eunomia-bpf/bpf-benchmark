"""Analyze a recorded A/A without changing or filtering framework counters."""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re
from statistics import mean, median


def analyze(run, app_name):
    path = run/'details/apps'/(app_name+'.json')
    app = json.loads(path.read_text())
    arms = {}
    groups = {}
    for phase in ('baseline', 'post_rejit'):
        data = app[phase]
        programs = []
        grouped = defaultdict(list)
        for key, program in data['bpf'].items():
            row = dict(program)
            runs, elapsed = row['run_cnt_delta'], row['run_time_ns_delta']
            row['ns_per_invocation'] = elapsed/runs if runs else None
            programs.append(row)
            # These are observed shape facts, not a hash of the program bytes.
            shape = tuple(row[k] for k in ('name', 'type', 'bytes_jited', 'bytes_xlated'))
            grouped[shape].append(row)
        rates = []
        counts = []
        for workload in data['workloads']:
            threads = []
            for component in workload['components']:
                sent = re.search(r'pkts-sofar:\s*(\d+)\s+errors:\s*(\d+)', component['stdout'])
                pps = re.search(r'\n\s*(\d+)pps\b', component['stdout'])
                if sent is None or pps is None:
                    raise ValueError('Missing raw pktgen fields')
                threads.append(dict(sent=int(sent[1]), errors=int(sent[2]), pps=int(pps[1])))
            rates.append(sum(t['pps'] for t in threads))
            counts.append(dict(duration_s=workload['duration_s'], threads=threads))
        runs = sum(p['run_cnt_delta'] for p in programs)
        elapsed = sum(p['run_time_ns_delta'] for p in programs)
        arms[phase] = dict(programs=programs, total_run_cnt=runs, total_run_time_ns=elapsed,
            aggregate_ns_per_invocation=elapsed/runs if runs else None,
            samples=counts, pktgen_pps=rates, mean_pps=mean(rates), median_pps=median(rates))
        groups[phase] = grouped
    pairs = []
    for shape in sorted(set(groups['baseline']) | set(groups['post_rejit'])):
        first, later = [groups[phase].get(shape, []) for phase in ('baseline', 'post_rejit')]
        ratio = None
        if len(first) == len(later) == 1:
            a, b = first[0]['ns_per_invocation'], later[0]['ns_per_invocation']
            if a is not None and b is not None and b != 0:
                ratio = a/b
        pairs.append(dict(observed_shape=shape, first_ids=[p['id'] for p in first],
            later_ids=[p['id'] for p in later], first_over_later_ns_per_invocation=ratio))
    first, later = [arms[phase] for phase in ('baseline', 'post_rejit')]
    a, b = first['aggregate_ns_per_invocation'], later['aggregate_ns_per_invocation']
    return dict(run=str(run), app_status=app['status'], app_error=app['error'],
        input_sha256=hashlib.sha256(path.read_bytes()).hexdigest(), arms=arms, observed_shape_pairs=pairs,
        later_over_first_mean_pps=later['mean_pps']/first['mean_pps'],
        later_over_first_median_pps=later['median_pps']/first['median_pps'],
        first_over_later_aggregate_ns_per_invocation=a/b if a is not None and b else None,
        scope='All recorded programs retained, including zero-run and unmatched/ambiguous shapes. Shape pairing is not byte identity. Aggregated per-call time uses the entire recorded counter window, excluding runner warmup. Ratios are analysis only, not native gains or automatic equal-work certification.')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run', type=Path, required=True)
    parser.add_argument('--app', default='katran')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = analyze(args.run, args.app)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('arms','observed_shape_pairs')}))
