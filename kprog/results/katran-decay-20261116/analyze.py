"""Katran's per-thread packetgen series and separately scoped arm counters.

The frozen runner snapshots BPF counters once around the whole sample loop.
It does not retain per-sample ns/call. Packetgen errors are reported attempts,
not established BPF drops; keep their raw counts separate from throughput.
"""
import json
from pathlib import Path
import re
import subprocess
import sys

run, output = Path(sys.argv[1]), Path(sys.argv[2])
app = json.loads((run / 'details/apps/katran.json').read_text())
contract = json.loads((run / 'details/result.json').read_text())
report = dict(scope=__doc__, run=str(run), app_status=app['status'],
    stamp=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    bpf_stats=contract['bpf_stats'], samples=contract['samples'],
    workload_seconds=contract['workload_seconds'], phases={})
for phase in ['baseline', 'post_rejit']:
    data = app[phase]
    calls = sum(p['run_cnt_delta'] for p in data['bpf'].values())
    time_ns = sum(p['run_time_ns_delta'] for p in data['bpf'].values())
    samples = []
    for index, workload in enumerate(data['workloads']):
        threads = []
        for component in workload['components']:
            stdout = component['stdout']
            pps = int(re.findall(r'(\d+)pps\b', stdout)[-1])
            errors = int(re.findall(r'\berrors:\s*(\d+)', stdout)[-1])
            elapsed, packets = re.findall(r'Result: OK:\s*(\d+)\(c\d+\+d\d+\) usec,\s*(\d+)', stdout)[-1]
            queue_min, queue_max = re.findall(r'queue_map_min:\s*(\d+)\s+queue_map_max:\s*(\d+)', stdout)[-1]
            threads.append(dict(thread=component['config']['thread_id'], reported_pps=pps,
                reported_errors=errors, reported_packets=int(packets),
                queue_map_range=[int(queue_min), int(queue_max)],
                current_queue=int(re.findall(r'cur_queue_map:\s*(\d+)', stdout)[-1]),
                reported_kernel_duration_us=int(elapsed), wrapper_duration_s=component['duration_s'],
                component_returncode=component['returncode']))
        samples.append(dict(index=index, threads=threads,
            reported_pps=sum(t['reported_pps'] for t in threads),
            reported_errors=sum(t['reported_errors'] for t in threads),
            reported_packets=sum(t['reported_packets'] for t in threads)))
    report['phases'][phase] = dict(samples=samples, counter_scope='one full-arm window across all samples',
        calls=calls, run_time_ns=time_ns, aggregate_ns_per_call=time_ns / calls if calls else None,
        per_sample_ns_per_call='not retained by the frozen entry', programs=data['bpf'])
output.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report, indent=2))
