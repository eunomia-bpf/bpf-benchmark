"""Count completed service bodies beside the framework's tracked program IDs."""
import io
import json
from pathlib import Path
import sys
import tarfile

service_path, run, output = map(Path, sys.argv[1:4])
programs = {}
with tarfile.open(service_path) as service:
    requests = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    for row in requests:
        archive = Path(row.get('artifact_archive') or row['failure_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+archive).read())) as request:
            members = set(request.getnames())
            entry = request.extractfile('request/kernel.entry').read().decode()
            facts = json.load(request.extractfile('request/kernel.facts.json'))
            key = (row['native_sha256'], entry, facts['prog_type'])
            program = programs.setdefault(key, dict(native_sha256=key[0], entry=entry, prog_type=key[2], attempts=[]))
            attempt = dict(request_id=row['request_id'], status=row['status'],
                native_installed=row['status'] == 0 and row.get('prog_id',0) > 0,
                b_generated=row.get('b_generated', 'request/generated/trusted_x86.bpf.o' in members),
                b_stock_passed=row.get('b_stock_passed', 'request/checked-simulator-verification.json' in members),
                execution_path=row.get('execution_path'), request_archive=archive)
            for name in ('simulator-failure.json','error.json'):
                if 'request/'+name in members:
                    detail = json.load(request.extractfile('request/'+name))
                    attempt[name] = {k:detail[k] for k in ('stage','error') if k in detail}
            if 'request/verify.stderr' in members:
                attempt['verifier_tail'] = request.extractfile('request/verify.stderr').read().decode().splitlines()[-8:]
            program['attempts'].append(attempt)
values = sorted(programs.values(),key=lambda p:(p['entry'],p['prog_type'],p['native_sha256']))
app_files = list((run/'details/apps').glob('*.json'))
app, = [json.loads(path.read_text()) for path in app_files]
report = dict(app=app['app'], app_status=app['status'], app_error=app.get('error'),
    service_archive=str(service_path), framework_run=str(run), request_attempts=len(requests),
    programs=len(values), native_installed=sum(any(a['native_installed'] for a in p['attempts']) for p in values),
    b_generated=sum(any(a['b_generated'] for a in p['attempts']) for p in values),
    b_stock_passed=sum(any(a['b_stock_passed'] for a in p['attempts']) for p in values),
    tracked_program_ids={phase:len((app.get(phase) or {}).get('bpf',{})) for phase in ('baseline','post_rejit')},
    definition='Programs are distinct native ELF SHA256/entry/type bodies submitted to the service; missing manifest entries do not submit a request. Tracked active IDs and request attempts are separate observations.',
    bodies=values)
output.write_text(json.dumps(report,indent=2)+'\n')
print({k:v for k,v in report.items() if k not in {'bodies','definition'}})
