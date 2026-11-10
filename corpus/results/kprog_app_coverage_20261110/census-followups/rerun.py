#!/usr/bin/env python3
"""Resubmit named bodies of the master-grouped resident census after a fix.

Each body runs exactly as census.py rerun_type0 runs it: one representative row,
the census inputs (native object, source BPF object, kernel, native-link,
stock module), the driver and model sources from /workspaces/repository, and a
stock-runtime directory holding libnative_loader.so and trusted-native-loader.
Load-only; native execution requests: 0. Outcomes are classified with the
census functions and reported for every member instance next to its census row.

  rerun.py run <label> --runtime <dir> --bodies <body-prefix>...
  rerun.py publish <label>
"""
from pathlib import Path
import argparse
import collections
import concurrent.futures
import datetime
import importlib.util
import io
import json
import os
import queue
import shutil
import subprocess
import sys
import tarfile
import threading

ROOT = Path('/workspaces/repository')
CENSUS = Path('/var/tmp/kprog-tmp/census-claude')
I = CENSUS / 'inputs'
PUBLISHED = ROOT / 'corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped'
OUT = Path('/var/tmp/kprog-tmp/replay-claude/census')
RESULTS = Path(__file__).resolve().parent
VNG = '/opt/virtme-ng/bin/vng'
GUEST_MEMORY = '4G'
HOST_CPUS = '8-19'
# Host B compile scheduling through the KPROG_REAL_CLANG hook of
# kprog/stock-path/bin/clang (same clang binary and argv): two large and two
# small compiles at once, each starting while host MemAvailable >= the pool's
# figure, so host available memory stays above about 30 GiB.
LARGE_SOURCE_BYTES = 400_000
POOLS = dict(large=(2, 48), small=(2, 34))


def write(path, value):
    Path(path).write_text(json.dumps(value, indent=2) + '\n')


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def tools():
    OUT.mkdir(parents=True, exist_ok=True)
    bindir = OUT / 'bin'
    bindir.mkdir(exist_ok=True)
    (bindir / 'vng').write_text('\n'.join([
        '#!/usr/bin/python3', 'import json, os, sys', 'from pathlib import Path',
        'a = sys.argv[1:]',
        "a[a.index('--memory') + 1] = '" + GUEST_MEMORY + "'",
        "w = next(x.split('=', 2)[2] for x in a if x.startswith('--rwdir=/mnt='))",
        "Path(w, 'effective-vng-command.json').write_text(json.dumps(['" + VNG + "'] + a, indent=2) + chr(10))",
        "os.execv('" + VNG + "', ['" + VNG + "'] + a)", '']))
    (bindir / 'clang-gate').write_text('\n'.join([
        '#!/bin/bash', 'source=; previous=',
        'for argument in "$@"; do [ "$previous" = -c ] && source=$argument; previous=$argument; done',
        'size=$(stat -c %s "$source" 2>/dev/null || echo 0)',
        'pool=small; slots=%d; need=%d' % POOLS['small'],
        '[ "$size" -gt %d ] && pool=large && slots=%d && need=%d' % ((LARGE_SOURCE_BYTES,) + POOLS['large']),
        'while true; do',
        "  avail=$(awk '/MemAvailable/{print int($2/1048576)}' /proc/meminfo)",
        '  if [ "$avail" -ge "$need" ]; then',
        '    for i in $(seq 0 $((slots - 1))); do',
        '      exec 9>' + str(OUT) + '/clang-$pool-$i',
        '      if flock -n 9; then exec /usr/lib/llvm-18/bin/clang "$@"; fi',
        '      exec 9>&-', '    done', '  fi', '  sleep 5', 'done', '']))
    for name in ['vng', 'clang-gate']:
        (bindir / name).chmod(0o755)
    os.environ['PATH'] = str(bindir) + ':' + os.environ['PATH']
    os.environ['KPROG_REAL_CLANG'] = str(bindir / 'clang-gate')
    (OUT / 'tmp').mkdir(exist_ok=True)
    os.environ['TMPDIR'] = str(OUT / 'tmp')


def run(label, runtime, prefixes, workers):
    tools()
    head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip()
    driver = ROOT / 'kprog/corpus_resident_verifier.py'
    census = load('census_classes', driver)
    groups = json.loads((CENSUS / 'groups.json').read_text())['groups']
    selected = [g for g in groups if any(g['body_sha256'].startswith(p) for p in prefixes)]
    if len(selected) != len(prefixes):
        raise SystemExit('bodies found %d of %d' % (len(selected), len(prefixes)))
    base = OUT / label
    base.mkdir(parents=True, exist_ok=True)
    path = base / 'bodies.json'
    results = json.loads(path.read_text()) if path.exists() else dict(
        label=label, model_head=head, runtime=str(runtime), driver=str(driver), bodies={})
    pending = queue.Queue()
    for entry in sorted(selected, key=lambda g: g['proof_bytes']):
        if entry['body_sha256'] not in results['bodies']:
            pending.put(entry)
    lock = threading.Lock()

    def one(entry):
        work = base / entry['body_sha256'][:16]
        if not (work / 'stock-results.json').exists():
            work.mkdir(parents=True, exist_ok=True)
            inventory = json.loads((I / 'run-inventory.json').read_text())
            resources = json.loads((I / 'resource-index.json').read_text())
            row = json.loads(json.dumps(entry['representative']))
            resource = dict(next(r for r in resources['programs'] if
                                 (r['application'], r['source_prog_id']) ==
                                 (row['application'], row['source_prog_id'])))
            for candidate in row['native_candidates']:
                source = Path(candidate['native_object'])
                if not (work / source.name).exists():
                    shutil.copy2(source, work / source.name)
                candidate['native_object'] = str(work / source.name)
            source = Path(resource['bpf_object'])
            if not (work / source.name).exists():
                shutil.copy2(source, work / source.name)
            resource['bpf_object'] = str(work / source.name)
            inventory.update(programs=[row], instances=1, source_head=head)
            resources['programs'] = [resource]
            write(work / 'run-inventory.json', inventory)
            write(work / 'resource-index.json', resources)
            write(work / 'provenance.json', dict(model_head=head, label=label,
                body_sha256=entry['body_sha256'], weighted_instances=len(entry['members']),
                host_cpu=HOST_CPUS, guest_cpus=1, kernel_image=str(I / 'bzImage'),
                model_source=str(ROOT), runtime=str(runtime)))
            if not (work / 'source').exists():
                (work / 'source').symlink_to(ROOT, target_is_directory=True)
            (work / 'stock-runtime').mkdir(exist_ok=True)
            for name in ['kprog_stock.ko', 'libnative_loader.so', 'trusted-native-loader']:
                origin = Path(runtime) / name if (Path(runtime) / name).exists() else I / 'stock-runtime' / name
                if not (work / 'stock-runtime' / name).exists():
                    shutil.copy2(origin, work / 'stock-runtime' / name)
            if not (work / 'native-link').exists():
                shutil.copy2(I / 'native-link', work / 'native-link')
            (work / 'stock-compile-proxy').write_text('#!/bin/sh\nexec python3 ' + str(driver) +
                ' compile --scratch ' + str(work) + ' "$@"\n')
            (work / 'stock-compile-proxy').chmod(0o755)
            (work / 'stock-guest.sh').write_text('#!/bin/bash\nset -e\nD=' + str(work) +
                '\nmountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug\n'
                'mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf\n'
                'insmod "$D/stock-runtime/kprog_stock.ko"\n'
                'export CLANG="$D/stock-compile-proxy" PYTHONDONTWRITEBYTECODE=1\n'
                'python3 ' + str(driver) + ' guest --scratch "$D"\n')
            with (work / 'controller.log').open('w') as log:
                subprocess.run(['taskset', '-c', HOST_CPUS, sys.executable, '-B', str(driver),
                                'namespace', '--scratch', str(work)],
                               stdout=log, stderr=subprocess.STDOUT)
        if (work / 'stock-results.json').exists():
            outcome = json.loads((work / 'stock-results.json').read_text())['programs'][0]
            outcome['compiler_failures'] = census.compiler_failures(outcome)
            outcome['failure_class'] = census.failure_class(outcome)
        else:
            outcome = dict(source_prog_id=entry['representative']['source_prog_id'],
                           name=entry['representative']['name'], stage='transport_failed',
                           diagnostic=(work / 'controller.log').read_text())
        return dict(outcome=outcome, worker=str(work), model_head=head)

    def worker():
        while True:
            try:
                entry = pending.get_nowait()
            except queue.Empty:
                return
            started = datetime.datetime.now(datetime.timezone.utc).isoformat()
            record = one(entry)
            with lock:
                record.update(started=started,
                              finished=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                              instances=len(entry['members']),
                              member_ids=[m['source_prog_id'] for m in entry['members']],
                              application=entry['representative']['application'],
                              symbol=entry['representative']['native_candidates'][0]['symbol'])
                results['bodies'][entry['body_sha256']] = record
                write(path, results)
                print(len(results['bodies']), len(selected), record['application'], record['symbol'],
                      record['outcome']['stage'], record['outcome'].get('failure_class'), flush=True)

    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as pool:
        for job in [pool.submit(worker) for _ in range(workers)]:
            job.result()
    write(base / 'complete.json', dict(bodies=len(results['bodies']), selected=len(selected)))


def publish(label):
    classes = load('census_controller', PUBLISHED / 'census.py')
    base = OUT / label
    results = json.loads((base / 'bodies.json').read_text())
    previous = {(r['application'], r['source_prog_id']): r for r in
                json.loads((PUBLISHED / 'instances.json').read_text())['programs']}
    target = RESULTS / label
    target.mkdir(parents=True, exist_ok=True)
    bodies, rows = [], []
    for body, record in sorted(results['bodies'].items()):
        outcome = record['outcome']
        message, context = classes.verifier_message(outcome.get('diagnostic', ''))
        label_class = outcome.get('failure_class', outcome['stage'])
        if outcome['stage'] == 'installed':
            primary = 'installed'
        elif outcome['stage'] == 'verifier_rejected' and message:
            primary = classes.message_class(message)
        else:
            primary = classes.stage_class(outcome, label_class)
        bodies.append(dict(body_sha256=body, application=record['application'],
            symbol=record['symbol'], instances=record['instances'], member_ids=record['member_ids'],
            stage=outcome['stage'], failure_class=primary, verifier_message=message,
            error_context=classes.error_context(outcome, context),
            generated=outcome.get('generated'), compiled=outcome.get('compiled'),
            started=record['started'], finished=record['finished']))
        for member in record['member_ids']:
            before = previous[(record['application'], member)]
            rows.append(dict(application=record['application'], source_prog_id=member,
                name=before['name'], body_sha256=body,
                census=dict(stage=before['stage'], failure_class=before['failure_class']),
                recheck=dict(stage=outcome['stage'], failure_class=primary,
                             generated=bool(outcome.get('generated')),
                             compiled=bool(outcome.get('compiled')))))
    summary = dict(label=label, model_head=results['model_head'], runtime=results['runtime'],
        native_execution_requests=0, bodies=bodies, instances=rows,
        census_classes=dict(collections.Counter(r['census']['failure_class'] for r in rows)),
        recheck_classes=dict(collections.Counter(r['recheck']['failure_class'] for r in rows)))
    write(target / 'result.json', summary)
    raw = io.BytesIO()
    with tarfile.open(fileobj=raw, mode='w:gz') as archive:
        archive.add(base / 'bodies.json', arcname='bodies.json')
        for work in sorted(p for p in base.iterdir() if p.is_dir() and (p / 'provenance.json').exists()):
            for name in ['controller.log', 'stock-console.log', 'stock-service.log',
                         'stock-compiler.log', 'stock-host.log', 'effective-vng-command.json',
                         'stock-command.json', 'stock-guest.exit', 'stock-guest.sh', 'provenance.json',
                         'run-inventory.json', 'resource-index.json', 'stock-results.json',
                         'stock-state/requests.jsonl', 'stock-compiler/jobs.jsonl']:
                if (work / name).exists():
                    archive.add(work / name, arcname=work.name + '/' + name)
            for request in sorted((work / 'stock-state').glob('*.tar.gz')):
                archive.add(request, arcname=work.name + '/stock-state/' + request.name)
    paths = classes.store(target, 'raw.tar.gz', raw.getvalue())
    print(json.dumps(dict(census=summary['census_classes'], recheck=summary['recheck_classes'],
                          files=[str(p) for p in paths]), indent=2))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['run', 'publish'])
    parser.add_argument('label')
    parser.add_argument('--runtime', type=Path, default=I / 'stock-runtime')
    parser.add_argument('--bodies', nargs='*', default=[])
    parser.add_argument('--workers', type=int, default=2)
    args = parser.parse_args()
    if args.mode == 'run':
        run(args.label, args.runtime, args.bodies, args.workers)
    else:
        publish(args.label)


if __name__ == '__main__':
    main()
