#!/usr/bin/env python3
"""Render the post-hoc CSV/JSON analysis as reviewable tables."""
import collections
import csv
import json
from pathlib import Path
import statistics

root = Path(__file__).resolve().parent
analysis = json.loads((root / 'analysis.json').read_text())

def rows(name):
    with (root / name).open() as f:
        return list(csv.DictReader(f))

def extent(s):
    return f"{s['median']:.3f} [{s['min']:.3f}, {s['max']:.3f}]; IQR [{s['q1']:.3f}, {s['q3']:.3f}]"

out = ['# Detailed post-hoc results', '',
       'All completed scheduled phases are included. Ratios below are ratios of arm medians; paired-ratio distributions are also shown. PPS is the sum of the two kernel pktgen **generated** rates, not receiver goodput. Pooled ns/run is sum(run_time_ns_delta)/sum(run_cnt_delta) within each phase. Entry time includes its tail-call chain; zero run counts do not imply an unused tail program. No minimum-count filter is applied.', '',
       '## Overall and restart controls', '',
       '| Source / experiment | JIT ns/run | Second-arm ns/run | JIT/second ns ratio | JIT PPS | Second-arm PPS | Second/JIT PPS ratio |',
       '|---|---|---|---|---|---|---|']
for label, groups in analysis.items():
    for group, v in groups.items():
        a = v['baseline']; b = v['post_rejit']
        ns = lambda x: extent(x['ns_per_run']) if x['ns_per_run'] else 'stats off'
        ratio = f"{v['ratio_of_median_ns']:.6f}" if v['ratio_of_median_ns'] else '—'
        out.append(f"| {label} {group} | {ns(a)} | {ns(b)} | {ratio} | {extent(a['pps'])} | {extent(b['pps'])} | {v['ratio_of_median_pps']:.6f} |")
out += ['', 'Median [min, max]; IQR [Q1, Q3]. Each group has five pairs. For controls, the second arm is JIT after the same stop/restart sequence.', '',
        '| Source / experiment | Paired JIT/second ns ratios | Paired second/JIT PPS ratios |', '|---|---|---|']
for label, groups in analysis.items():
    for group, v in groups.items():
        out.append(f"| {label} {group} | {extent(v['paired_ns_ratio']) if v['paired_ns_ratio'] else 'stats off'} | {extent(v['paired_pps_ratio'])} |")

out += ['', '## Per-program timing', '',
        'Attachment keys identify the same endpoint/interface role across fresh starts; IDs change. Unbound-name rows combine same-name records and report their multiplicity. Full individual program IDs, names, raw counters, code sizes and dump coverage remain in programs.csv. No undefined ns/run is replaced by zero.', '',
        '| Source | Control? | Arm | Attachment or name/type | Records | Median run count | Total run count | ns/run median [min, max]; IQR |',
        '|---|---|---|---|---|---|---|---|']
for r in rows('program-summary.csv'):
    timing = 'undefined (zero counts)'
    if r['ns_median']:
        timing = extent({k: float(r['ns_'+k]) for k in ['median', 'min', 'max', 'q1', 'q3']})
    out.append(f"| {r['label']} | {r['control']} | {r['phase']} | {r['key']} | {r['records']} | {r['median_run_cnt']} | {r['total_run_cnt']} | {timing} |")

out += ['', '## Program-set differences', '',
        'Names below are the kernel BPF names (at most 15 characters), with program type. Name multiplicities are an inventory check, not proof of bytecode identity. all-loaded-end includes original/native copies and observer iterator programs. The exact difference for each pair and both snapshot times is in inventory-differences.csv; every inventory row is in inventories.csv.', '',
        '| Source | Control? | Inventory | Name | Type | Observed (JIT, second) multiplicities when different |',
        '|---|---|---|---|---|---|']
diff = collections.defaultdict(set)
for r in rows('inventory-differences.csv'):
    if r['scope'] == 'all-loaded-start':
        continue  # The CSV retains both times; the table shows tracked/end.
    key = tuple(r[k] for k in ['label', 'control', 'scope', 'name', 'type'])
    diff[key].add((int(r['baseline_count']), int(r['post_count'])))
for key, counts in sorted(diff.items()):
    out.append('| ' + ' | '.join(key) + ' | ' + ', '.join(f'({a}, {b})' for a,b in sorted(counts)) + ' |')

out += ['', '## Verdicts and receiver counters', '',
        'Cilium metrics reason 133 is DROP_POLICY. reason 0 contains both ingress and egress forwards, so it is not a single packet goodput total. Receiver count is the sum of eth0 RX packet deltas in bpfbench-cepa/cepb; the start snapshot follows warmup. Small residual counters can contain control packets. The metric key ABI and all packet/byte counters are preserved in verdicts.csv and map dumps.', '',
        '| Source / experiment | JIT policy drops | Second policy drops | JIT receiver packets | Second receiver packets |',
        '|---|---|---|---|---|']
for label, groups in analysis.items():
    for group,v in groups.items():
        a=v['baseline'];b=v['post_rejit']
        out.append(f"| {label} {group} | {extent(a['policy_drops'])} | {extent(b['policy_drops'])} | {extent(a['receiver_packets'])} | {extent(b['receiver_packets'])} |")

out += ['', '## Host load', '',
        'Every phase has its own host CPU and pod data in host-load-by-pod.csv. Values use the measurement window and 2-second samples. Pod labels are unavailable inside this Workspace; raw cgroup UIDs identify the other Workspaces. One CPU core is one second of CPU use per second of wall time.', '',
        '| Source | Cgroup / host core | Median CPU cores [min, max] |', '|---|---|---|']
load=collections.defaultdict(list)
for r in rows('host-load-by-pod.csv'):
    load[(r['label'],r['cgroup'])].append(float(r['average_cpu_cores']))
for (label,cgroup), values in sorted(load.items()):
    out.append(f'| {label} | {cgroup} | {statistics.median(values):.6f} [{min(values):.6f}, {max(values):.6f}] |')
(root/'tables.md').write_text('\n'.join(out)+'\n')
