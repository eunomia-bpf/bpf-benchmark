"""Collect completed upstream app counters and registered-service evidence.

This is offline accounting. Missing counter observations stay explicit and
never become a reason to reject a completed benchmark result.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import io
import json
from pathlib import Path
import tarfile


def sha256(path):
    value = hashlib.sha256()
    with path.open('rb') as source:
        while block := source.read(1024 * 1024):
            value.update(block)
    return value.hexdigest()


def read_json(archive, name):
    return json.load(archive.extractfile(name))


def summarize(app, service):
    requests = [json.loads(line) for line in service.extractfile(
        'service/requests/requests.jsonl').read().decode().splitlines()]
    counters = {} if app['post_rejit'] is None else app['post_rejit']['bpf']
    programs = []
    for request in requests:
        record = dict(request)
        archive_key = 'artifact_archive' if request['status'] == 0 else 'failure_archive'
        retained = request.get(archive_key)
        record.update(stock_load=None, stock_verification=None, generation_returncodes=None)
        if retained:
            name = 'service/requests/' + Path(retained).name
            with tarfile.open(fileobj=io.BytesIO(service.extractfile(name).read())) as inner:
                names = set(inner.getnames())
                if 'request/verify.stdout' in names:
                    output = inner.extractfile('request/verify.stdout').read().decode().strip()
                    if output:
                        record['stock_verification'] = json.loads(output)
                if 'request/load.stdout' in names:
                    output = inner.extractfile('request/load.stdout').read().decode().strip()
                    if output:
                        record['stock_load'] = json.loads(output)
                if 'request/generated/commands.jsonl' in names:
                    record['generation_returncodes'] = [json.loads(line)['returncode'] for line in
                        inner.extractfile('request/generated/commands.jsonl').read().decode().splitlines()]
        record['counters'] = counters.get(str(request['prog_id'])) if request['status'] == 0 else None
        programs.append(record)
    installed = {r['prog_id'] for r in requests if r['status'] == 0}
    # LTO first verifies B, then compiles and installs. A later failure cannot
    # erase that verification; successful verify+load is still one program.
    verified = {r['source_prog_id'] for r in programs
                if any(r[phase] is not None and r[phase]['status'] == 0
                       for phase in ('stock_verification','stock_load'))}
    return dict(application=app['app'], application_status=app['status'], application_error=app['error'],
        service_summary=read_json(service, 'service/summary.json'), attempts=len(requests),
        loaded=len({r['source_prog_id'] for r in requests if r['source_prog_id'] > 0}),
        verified=len(verified), installed=len(installed),
        run=sum(int(counters[str(prog)]['run_cnt_delta'] > 0) for prog in installed if str(prog) in counters),
        installed_without_counter=sorted(prog for prog in installed if str(prog) not in counters),
        native_counter_ids_without_install=sorted(int(prog) for prog in counters if int(prog) not in installed),
        baseline_counter_programs=len(app['baseline']['bpf']),
        native_counter_programs=len(counters), programs=programs)


def collect(raw, corpus, captures, prefix, exit_file, application):
    output = raw/'collection'
    output.mkdir()
    # Select the requested application, retaining every program and zero count.
    app = json.loads((corpus/'details/apps'/(application.replace('/','__')+'.json')).read_text())
    with tarfile.open(raw/'control/service.tar.gz') as service:
        result = summarize(app, service)
    result.update(recorded=datetime.now(timezone.utc).isoformat(), raw_directory=str(raw),
        corpus_run_directory=str(corpus), capture_directory=str(captures),
        make_exit_code=int((raw/exit_file).read_text()) if (raw/exit_file).exists() else None,
        launch_receipt=json.loads((raw/'launch-receipt.json').read_text()),
        corpus_metadata=json.loads((corpus/'metadata.json').read_text()),
        scope='Actual upstream two-start verified-B run; workload run means positive recorded native run_cnt_delta',
        raw_removed=False)
    archive = output/'full-evidence.tar.gz'
    with tarfile.open(archive, 'x:gz') as destination:
        for path in sorted(raw.iterdir()):
            if path != output:
                destination.add(path, arcname='raw/'+path.name)
        destination.add(corpus, arcname='corpus')
        destination.add(captures, arcname='captures')
    size = archive.stat().st_size
    record = dict(raw_archive=str(archive), sha256=sha256(archive), bytes=size)
    # Raw evidence stays under /workspaces/kprog-raw; Git receives the receipt.
    result['archive'] = record
    text = json.dumps(result, indent=2)+'\n'
    (output/'receipt.json').write_text(text)
    Path(str(prefix)+'-receipt.json').write_text(text)
    print(json.dumps({key:result[key] for key in
        ('application','application_status','make_exit_code','loaded','verified','installed','run',
         'installed_without_counter','native_counter_ids_without_install')}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for option in ('raw','corpus','captures','prefix'):
        parser.add_argument('--'+option, type=Path, required=True)
    parser.add_argument('--exit-file', default='exit-code')
    parser.add_argument('--app', required=True)
    args = parser.parse_args()
    collect(args.raw, args.corpus, args.captures, args.prefix, args.exit_file, args.app)
