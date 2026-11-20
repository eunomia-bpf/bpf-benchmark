"""Retain the completed OTel diagnostic, including failures and raw counters."""
import io
import json
from pathlib import Path
import re
import subprocess
import tarfile

here = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120/otel-20261120T025007Z')
app_run = Path('/workspaces/repository/corpus/results/x86_kvm_corpus_20261120_025243_099920')
app = json.loads((app_run/'details/apps/otelcol-ebpf-profiler__profiling.json').read_text())
rows = []
with tarfile.open(raw/'service.tar.gz') as service:
    journal = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    for record in journal:
        name = Path(record['artifact_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+name).read())) as capsule:
            artifact = json.load(capsule.extractfile('request/generated/artifacts.json'))
            row = {key: record[key] for key in ['request_id', 'source_prog_id', 'execution_path', 'status', 'b_generated', 'b_stock_passed']}
            row['symbol'] = artifact['symbol']
            if record['b_stock_passed']:
                ir = subprocess.run(['llvm-dis-18', '-o', '-', '-'],
                    input=capsule.extractfile('request/generated/checked-simulator.native.bc').read(),
                    capture_output=True, check=True).stdout.decode()
                row['lpm_static_sites'] = sum('call ptr @__kprog_array_lookup(' in line and
                    '@pid_page_to_mapping_info,' in line for line in ir.splitlines())
            else:
                failure = json.load(capsule.extractfile('request/simulator-failure.json'))
                row['failure_stage'] = failure['stage']
                row['verifier_tail'] = failure.get('stderr', '').splitlines()[-12:]
            rows.append(row)
phases = {}
for phase in ['baseline', 'post_rejit']:
    counters = app[phase]['bpf']
    count = sum(p['run_cnt_delta'] for p in counters.values())
    elapsed = sum(p['run_time_ns_delta'] for p in counters.values())
    components = []
    for component in app[phase]['workloads'][0]['components']:
        matches = re.findall(r'ops=(\d+) elapsed_s=([\d.]+)', component['stderr'])
        components.append(dict(name=component['workload_name'], returncode=component['returncode'],
            self_counters=[dict(ops=int(ops), elapsed_s=float(seconds),
                ops_per_second=int(ops)/float(seconds)) for ops, seconds in matches]))
    phases[phase] = dict(run_cnt=count, run_time_ns=elapsed, ns_per_call=elapsed/count,
                        programs=counters, workload_components=components)
result = dict(source_revision='0ca3869fa', raw=str(raw), app_run=str(app_run),
    app_status=app['status'], app_error=app['error'], requests=rows, phases=phases,
    ebpf_over_native_per_call=phases['baseline']['ns_per_call']/phases['post_rejit']['ns_per_call'],
    scope='One frozen 10-second diagnostic per arm, CPU20-23, current image, installed tools. Mixed checked/direct execution; regression retained, no causal isolation or speedup claim. Tail-call child counts are zero; entry counters include their time. Static LPM sites are not dynamic frequencies. Component throughput is reported separately; no aggregate workload rate exists.')
(here/'app-result.json').write_text(json.dumps(result, indent=2)+'\n')
with tarfile.open(here/'app-evidence.tar.gz', 'w:gz') as archive:
    archive.add(raw, arcname='otel-20261120T025007Z')
    archive.add(app_run, arcname=app_run.name)
print(json.dumps(dict(status=app['status'], installed=len(rows),
    checked=sum(row['b_stock_passed'] for row in rows),
    lpm_static_sites=sum(row.get('lpm_static_sites', 0) for row in rows),
    ns_per_call={phase: value['ns_per_call'] for phase, value in phases.items()}), indent=2))
