"""Read actual service completions and corpus status from a finished functional run."""
import io
import json
from pathlib import Path
import re
import sys
import tarfile

raw = Path(sys.argv[1])
output = Path(sys.argv[2])
source_commit = Path(sys.argv[3])
exit_code = Path(sys.argv[4])
run_log = Path(sys.argv[5])
records = []
with tarfile.open(raw / 'service.tar.gz') as service:
    lines = service.extractfile('service/requests/requests.jsonl').read().decode().splitlines()
    for line in lines:
        row = json.loads(line)
        item = {key: row[key] for key in [
            'request_id', 'source_prog_id', 'prog_id', 'status', 'execution_mode', 'execution_path',
            'b_generated', 'b_stock_passed', 'simulator_failure', 'error'
        ] if key in row}
        archive = Path(row['artifact_archive'] if row['status'] == 0 else row['failure_archive'])
        capsule = service.extractfile('service/requests/' + archive.name).read()
        with tarfile.open(fileobj=io.BytesIO(capsule)) as request:
            members = set(request.getnames())
            item['symbol'] = request.extractfile('request/kernel.entry').read().decode('ascii')
            facts = 'request/kernel.facts.json'
            item['prog_type'] = (json.load(request.extractfile(facts))['prog_type']
                                if facts in members or row['status'] == 0 else None)
            if 'request/generated/artifacts.json' in members:
                artifacts = json.load(request.extractfile('request/generated/artifacts.json'))
                obj = artifacts.get('simulator_object')
                if obj and 'request/generated/' + Path(obj).name in members:
                    item.setdefault('b_generated', True)
            if 'request/checked-simulator-verification.json' in members:
                item.setdefault('b_stock_passed', True)
            if 'request/simulator-failure.json' in members:
                item.setdefault('simulator_failure', json.load(request.extractfile('request/simulator-failure.json')))
        records.append(item)
corpus = []
for name in sorted(set(re.findall(r'x86_kvm_corpus_\d+_\d+_\d+', run_log.read_text()))):
    path = Path('/workspaces/repository/corpus/results') / name / 'details/result.json'
    result = json.loads(path.read_text())
    corpus.append(dict(path=str(path), **{key: result[key] for key in [
        'status', 'suite_name', 'samples', 'workload_seconds'
    ]}))
summary = dict(
    raw=str(raw), source_commit=source_commit.read_text().strip(),
    host_exit=int(exit_code.read_text()),
    requests=len(records), programs=len({r['source_prog_id'] for r in records}),
    native_installed=sum(r['status'] == 0 for r in records),
    b_generated=sum(r.get('b_generated') is True for r in records),
    b_stock_passed=sum(r.get('b_stock_passed') is True for r in records),
    checked_native=sum(r.get('execution_path') == 'checked-sim-c' for r in records),
    direct_native=sum(r.get('execution_path') == 'direct-native' for r in records),
    kept_on_ebpf=sum(r['status'] != 0 for r in records),
    failed=sum(r['status'] != 0 for r in records),
    requests_detail=records, corpus=corpus,
    scope='Registered-service completions and corpus status. Execution and B verification are separate: direct_native counts explicit execution_path records, including B failures that still run native. Only failed requests keep the original eBPF program. B counts use explicit flags or retained object/verification receipts; missing evidence is not inferred acceptance. Counts are requests except programs; workload parameters are recorded per corpus run.'
)
output.write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps({k: v for k, v in summary.items() if k not in ['requests_detail', 'corpus']}))
print(json.dumps(corpus))
