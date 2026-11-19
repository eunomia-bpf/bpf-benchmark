"""Separate stock acceptance from native execution in the actual service journal."""
from collections import Counter
import json
from pathlib import Path
import sys
import tarfile

archive_path = Path(sys.argv[1])
output = Path(sys.argv[2])
reported = {row['request_id']: row['class'] for row in json.loads(
    Path('kprog/results/cilium-packet-bounds-20261119/requests.json').read_text())}
with tarfile.open(archive_path) as archive:
    journal = [json.loads(line) for line in archive.extractfile('service/requests/requests.jsonl')]
    rows = []
    for request in journal:
        request_id = request['request_id']
        name = Path(request['artifact_archive'] if 'artifact_archive' in request else request['failure_archive']).name
        capsule_path = 'service/requests/'+name
        with tarfile.open(fileobj=archive.extractfile(capsule_path)) as capsule:
            names = capsule.getnames()
            failure = json.load(capsule.extractfile('request/simulator-failure.json')) \
                if 'request/simulator-failure.json' in names else {}
            generated = 'request/generated/trusted_x86.bpf.o' in names
            verification = json.load(capsule.extractfile('request/checked-simulator-verification.json')) \
                if 'request/checked-simulator-verification.json' in names else None
            terminal_stderr = capsule.extractfile('request/load-direct.stderr').read().decode() \
                if request['status'] != 0 and 'request/load-direct.stderr' in names else None
        stderr = failure.get('stderr', '')
        if request.get('b_stock_passed') is True:
            category = 'stock_passed'
        elif 'invalid access to packet' in stderr:
            category = 'packet_rejected'
        elif 'only read is supported' in stderr:
            category = 'store_rejected'
        elif failure.get('stage') == 'generation':
            category = 'generation_failed'
        else:
            category = 'other_failure'
        row = dict(request_id=request_id, category=category,
                   journal_status=request['status'], phase=request.get('phase'),
                   execution_path=request.get('execution_path'),
                   b_generated=request.get('b_generated'),
                   b_stock_passed=request.get('b_stock_passed'),
                   capsule=capsule_path, capsule_b_generated=generated,
                   failure_stage=failure.get('stage'),
                   reported_class=reported.get(request_id))
        if category == 'generation_failed':
            row['error'] = failure['error']
        if category == 'stock_passed':
            row['verification_record'] = verification
        if terminal_stderr is not None:
            row['terminal_stderr'] = terminal_stderr
        rows.append(row)

result = dict(source_archive=str(archive_path),
              journal='service/requests/requests.jsonl',
              counts=dict(Counter(row['category'] for row in rows)),
              execution_paths=dict(Counter(row['execution_path'] or 'unreported' for row in rows)),
              requests=rows,
              scope='Historical journal, inner capsule failures and stock-verification receipts; no new execution or acceptance.')
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(counts=result['counts'], execution_paths=result['execution_paths'])))
