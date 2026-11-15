"""Read the completed frozen two-start control, retaining missing BPF counters."""
import json
from pathlib import Path
import re
import shutil
from statistics import mean

ROOT = Path(__file__).resolve().parents[4]
out = Path(__file__).resolve().parent
run = ROOT/'corpus/results/x86_kvm_corpus_20261115_062302_565500'
raw = Path('/workspaces/kprog-raw/perf/20261115-isolated-aa')
app = json.loads((run/'details/apps/katran.json').read_text())
rows = {}
for phase in ('baseline', 'post_rejit'):
    samples = []
    for workload in app[phase]['workloads']:
        threads = []
        for component in workload['components']:
            sent = re.search(r'pkts-sofar:\s*(\d+)\s+errors:\s*(\d+)', component['stdout'])
            rate = re.search(r'\n\s*(\d+)pps\b', component['stdout'])
            if sent is None or rate is None:
                raise ValueError('pktgen measurement missing from completed control')
            threads.append(dict(sent=int(sent[1]), errors=int(sent[2]), pps=int(rate[1])))
        samples.append(dict(duration_s=workload['duration_s'], threads=threads,
            sent=sum(t['sent'] for t in threads), errors=sum(t['errors'] for t in threads),
            pktgen_pps=sum(t['pps'] for t in threads)))
    rows[phase] = dict(samples=samples, bpf=app[phase]['bpf'],
        mean_pktgen_pps=mean(s['pktgen_pps'] for s in samples))
ratio = rows['post_rejit']['mean_pktgen_pps']/rows['baseline']['mean_pktgen_pps']
result = dict(app_status=app['status'], app_error=app['error'], rejit_result=app['rejit_result'],
    arms=rows, post_over_baseline_throughput=ratio,
    per_invocation_ratio=None,
    limitation='Both BPF counter dictionaries are empty despite stats=true. Program IDs/bytes and per-call drift were not observed. Same configured image and disabled shim establish a workload-throughput A/A only.')
(out/'result.json').write_text(json.dumps(result, indent=2)+'\n')
for source, name in [(run/'metadata.json', 'metadata.json'), (run/'details/result.json', 'framework-result.json'),
                     (run/'details/apps/katran.json', 'katran-raw.json'),
                     (raw/'job/make.log', 'make.log'), (raw/'job/exit-code', 'exit-code')]:
    shutil.copyfile(source, out/name)
print(json.dumps(result, indent=2))
