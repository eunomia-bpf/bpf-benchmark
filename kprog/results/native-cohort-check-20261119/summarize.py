"""Read actual service completions and corpus status from a finished functional run."""
import json
from pathlib import Path
import re
import sys
import tarfile

raw = Path(sys.argv[1])
output = Path(sys.argv[2])
records = []
for log in sorted(raw.glob('state/*/requests/requests.jsonl')):
    for line in log.read_text().splitlines():
        row = json.loads(line)
        item = {key: row[key] for key in [
            'request_id', 'source_prog_id', 'prog_id', 'status', 'execution_path',
            'b_generated', 'b_stock_passed', 'simulator_failure', 'error'
        ] if key in row}
        archive = Path(row['artifact_archive'] if row['status'] == 0 else row['failure_archive'])
        with tarfile.open(archive) as request:
            item['symbol'] = request.extractfile('request/kernel.entry').read().decode('ascii')
            item['prog_type'] = json.load(request.extractfile('request/kernel.facts.json'))['prog_type']
        records.append(item)
corpus = []
for name in sorted(set(re.findall(r'x86_kvm_corpus_\d+_\d+_\d+', (raw / 'run.log').read_text()))):
    path = Path('/workspaces/repository/corpus/results') / name / 'details/result.json'
    result = json.loads(path.read_text())
    corpus.append(dict(path=str(path), **{key: result[key] for key in [
        'status', 'suite_name', 'samples', 'workload_seconds'
    ]}))
summary = dict(
    raw=str(raw), source_commit=(raw / 'source-commit').read_text().strip(),
    host_exit=int((raw / 'host-exit-code').read_text()),
    requests=len(records), programs=len({r['source_prog_id'] for r in records}),
    native_installed=sum(r['status'] == 0 for r in records),
    b_generated=sum(r.get('b_generated') is True for r in records),
    b_stock_passed=sum(r.get('b_stock_passed') is True for r in records),
    checked_native=sum(r.get('execution_path') == 'checked-sim-c' for r in records),
    direct_native=sum(r.get('execution_path') == 'direct-native' for r in records),
    failed=sum(r['status'] != 0 for r in records),
    requests_detail=records, corpus=corpus,
    scope='Canonical checked-corpus functional coverage (1 x 10 s); no official timing gain.'
)
output.write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps({k: v for k, v in summary.items() if k not in ['requests_detail', 'corpus']}))
print(json.dumps(corpus))
