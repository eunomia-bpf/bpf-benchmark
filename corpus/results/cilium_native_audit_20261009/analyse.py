#!/usr/bin/env python3
"""Offline analysis only; does not execute benchmarks or change source/results."""
import csv
import json
import math
import pathlib
import re
import shutil
import statistics
import subprocess
import sys

ROOT = pathlib.Path(sys.argv[1]).resolve() if len(sys.argv) > 1 else pathlib.Path.cwd()
OUT = pathlib.Path(__file__).resolve().parent
DATA = OUT / 'data'


def write_csv(name, rows):
    with (DATA / name).open('w') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)


def load(path):
    return json.loads((ROOT / path).read_text())


pins = json.loads((DATA / 'commit-pins.json').read_text())
sizes = []
reports = []
program_errors = []
for pin in pins:
    path = pin['run']
    raw = load(path + '/details/result.json')
    for b in raw.get('benchmarks', []):
        for run in b['runs']:
            for index, s in enumerate(run.get('samples', [])):
                sizes.append(dict(run=path, benchmark=b['name'], runtime=run['runtime'],
                                  sample=s.get('sample_index', index),
                                  bytes_jited=s.get('jited_prog_len'),
                                  native_code_bytes=s.get('code_size', {}).get('native_code_bytes'),
                                  bytes_xlated=s.get('xlated_prog_len'),
                                  bpf_bytecode_bytes=s.get('code_size', {}).get('bpf_bytecode_bytes')))
                for prog in s.get('rejit_result', {}).get('per_program', {}).values():
                    if prog.get('status') == 'error':
                        program_errors.append(dict(run=path, benchmark=b['name'], runtime=run['runtime'],
                                                   sample=s.get('sample_index', index), program_id=prog.get('prog_id'),
                                                   status=prog['status'], error=prog.get('error_message')))
                    for q in prog.get('passes', []):
                        summary = q.get('bpfopt_summary')
                        if summary is None:
                            summary = {}
                        reports.append(dict(run=path, benchmark=b['name'], runtime=run['runtime'],
                                            sample=s.get('sample_index', index),
                                            program=prog.get('program', {}).get('prog_name', ''),
                                            program_id=prog.get('prog_id'), pass_name=summary.get('pass'),
                                            sites_matched=summary.get('sites_matched'),
                                            sites_applied=summary.get('sites_applied'),
                                            calls=json.dumps(summary.get('kinsn_calls_by_name', {}), sort_keys=True),
                                            policy=json.dumps(summary.get('kinsn_policy', {}), sort_keys=True),
                                            command=q.get('step', {}).get('command'),
                                            status=q.get('status'), error=q.get('error')))
write_csv('micro-code-sizes.csv', sizes)
write_csv('micro-site-reports.csv', reports)
if program_errors:
    write_csv('micro-program-errors.csv', program_errors)


def med_sizes(path, runtime):
    result = {}
    for b in load(path + '/details/result.json')['benchmarks']:
        for r in b['runs']:
            if r['runtime'] == runtime:
                result[b['name']] = statistics.median(s['code_size']['native_code_bytes'] for s in r['samples'])
    return result


size_comparisons = []
size_summary = {}
for arch, cand, base, rt in [
    ('x86', 'micro/results/x86_kvm_micro_20260519_114214_364050',
     'micro/results/x86_kvm_micro_20260526_210351_224315', 'kernel'),
    ('arm64', 'micro/results/aws_arm64_micro_20260606_001225_821028',
     'micro/results/aws_arm64_micro_20260606_001225_821028', 'kernel_rejit'),
]:
    a, b = med_sizes(cand, rt), med_sizes(base, 'kernel')
    if set(a) != set(b):
        raise RuntimeError(f'{arch}: unmatched size population')
    ratios = []
    for key in sorted(a):
        ratios.append(a[key] / b[key])
        size_comparisons.append(dict(architecture=arch, benchmark=key, baseline_bytes=b[key],
                                     candidate_bytes=a[key], ratio=a[key] / b[key],
                                     baseline_run=base, candidate_run=cand, candidate_runtime=rt))
    size_summary[arch] = dict(cases=len(ratios), ratio=math.exp(statistics.mean(map(math.log, ratios))))
write_csv('paper-code-size-comparison.csv', size_comparisons)

programs, traffic, totals = [], [], {}
for token in ['033517_489159', '040554_604387']:
    run = 'corpus/results/x86_kvm_corpus_20260529_' + token
    app = load(run + '/details/apps/cilium__agent.json')
    dest = DATA / 'raw' / pathlib.Path(run).name
    (dest / 'details/apps').mkdir(parents=True, exist_ok=True)
    for rel in ['metadata.json', 'details/result.json', 'details/progress.json', 'details/apps/cilium__agent.json']:
        shutil.copyfile(ROOT / run / rel, dest / rel)
    for phase in ['baseline', 'post_rejit']:
        data = app[phase]
        count = elapsed = 0
        for p in data['bpf'].values():
            n, t = p['run_cnt_delta'], p['run_time_ns_delta']
            count += n
            elapsed += t
            programs.append(dict(run=run, phase=phase, **p, ns_per_run=t / n if n else ''))
        pps, packets = [], []
        for sample, workload in enumerate(data['workloads']):
            sample_pps = sample_packets = 0
            for c in workload['components']:
                stdout = c['stdout']
                p = re.search(r'(\d+)pps', stdout)
                n = re.search(r'pkts-sofar:\s*(\d+)', stdout)
                error = re.findall(r'errors:\s*(\d+)', stdout)
                if not p or not n or not error:
                    raise RuntimeError('Missing pktgen raw metrics')
                p, n = int(p[1]), int(n[1])
                sample_pps += p
                sample_packets += n
                traffic.append(dict(run=run, phase=phase, sample=sample, direction=c['workload_name'],
                                    pps=p, packets=n, pktgen_errors=int(error[-1]),
                                    duration_s=c['duration_s'], config=json.dumps(c['config'], sort_keys=True)))
            pps.append(sample_pps)
            packets.append(sample_packets)
        totals[token + '/' + phase] = dict(programs=len(data['bpf']), run_cnt=count,
                                          run_time_ns=elapsed, ns_per_run=elapsed / count if count else None,
                                          pps_samples=pps, median_pps=statistics.median(pps),
                                          min_pps=min(pps), max_pps=max(pps), packets=sum(packets))
write_csv('old-programs.csv', programs)
write_csv('old-traffic.csv', traffic)
totals['stats_on_cost_ratio'] = totals['033517_489159/baseline']['ns_per_run'] / totals['033517_489159/post_rejit']['ns_per_run']
totals['stats_off_throughput_ratio'] = totals['040554_604387/post_rejit']['median_pps'] / totals['040554_604387/baseline']['median_pps']
totals['paper_code_size_ratios'] = size_summary
(DATA / 'old-analysis.json').write_text(json.dumps(totals, indent=2) + '\n')
print(json.dumps(totals, indent=2))
