"""Diagnostic artifact census; no workload, ratio, or native-binding claims."""
import concurrent.futures
import csv
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile

ROOT = Path(__file__).resolve().parents[3]


def records(directory):
    return [json.loads(line) for line in (directory / 'programs.jsonl').read_text().splitlines()]


def inventory(directory):
    root = ROOT / 'vendor/build/native-bpf/arm64/stage'
    rows = []
    for manifest in sorted(directory.glob('*.json')):
        data = json.loads(manifest.read_text())
        app = data['app']
        for entry in data['objects']:
            stem = Path(entry['native_object']).name.removesuffix('.native.o')
            symbol = entry.get('symbol', entry['program'])
            exact = root / app / f'{stem}.{symbol}.proof.o'
            short = root / app / f'{symbol}.proof.o'
            candidates = ([exact] if exact.exists() else [short] if short.exists() else
                          sorted(set((root / app).glob(f'{stem}.{symbol}*.proof.o')) |
                                 set((root / app).glob(f'{symbol}*.proof.o'))))
            rows.append(dict(app=app, program=entry['program'], native_object=entry['native_object'],
                             symbol=entry.get('symbol', ''),
                             pairing='unique' if len(candidates) == 1 else 'missing' if not candidates else 'ambiguous',
                             candidates=';'.join(p.name for p in candidates)))
    with (directory / 'pairing.csv').open('w') as out:
        writer = csv.DictWriter(out, fieldnames=['app', 'program', 'native_object', 'symbol',
                                                'pairing', 'candidates'], lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    print(f'{len(rows)} manifest entries; ' + ', '.join(
        f"{sum(row['pairing'] == status for row in rows)} {status}" for status in ['unique', 'ambiguous', 'missing']))
    return 0


def freeze_simulator(directory):
    snapshot = directory / 'simulator'
    if not snapshot.exists():
        snapshot.mkdir()
        for name in ['arm64_sim.h', 'arm64_sim_local_bpf.h']:
            shutil.copy2(ROOT / 'kprog/arm64' / name, snapshot / name)
        shutil.copytree(ROOT / 'kprog/formal/generated', directory / 'formal/generated')


def compile_one(row, directory):
    log = directory / 'compile' / (row['name'] + '.json')
    if log.exists():
        return json.loads(log.read_text())
    source = directory / 'compile-sources' / (row['name'] + '.bpf.c')
    source.write_text(Path(row['source']).read_text().replace(
        '#include "../arm64_sim_local_bpf.h"',
        f'#include "{directory}/simulator/arm64_sim_local_bpf.h"'))
    command = ['clang', '-g', '-O2', '-mcpu=v4', '-target', 'bpf', '-mllvm',
               '-bpf-stack-size=4096', '-D__TARGET_ARCH_arm64',
               '-I', str(ROOT / 'vendor/libbpf/include/uapi'),
               '-I', str(ROOT / 'vendor/libbpf/src'),
               '-I', '/usr/include/x86_64-linux-gnu',
               '-I', str(ROOT / 'kprog/arm64/micro-prog'), '-c', str(source),
               '-o', str(directory / 'objects' / (row['name'] + '.bpf.o'))]
    try:
        result = subprocess.run(command, text=True, capture_output=True, timeout=120)
        code, stdout, stderr = result.returncode, result.stdout, result.stderr
    except subprocess.TimeoutExpired as error:
        code = 124
        stdout = (error.stdout or b'').decode(errors='replace')
        stderr = (error.stderr or b'').decode(errors='replace') + '\ncompile timeout after 120s\n'
    record = dict(row, command=command, returncode=code, stdout=stdout, stderr=stderr)
    log.write_text(json.dumps(record) + '\n')
    return record


def compile_all(directory):
    for name in ['compile', 'objects', 'compile-sources']:
        (directory / name).mkdir(exist_ok=True)
    rows = [row for row in records(directory) if row['stage'] == 'generate' and row['ok']]
    freeze_simulator(directory)
    failures = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        futures = [pool.submit(compile_one, row, directory) for row in rows]
        for count, future in enumerate(concurrent.futures.as_completed(futures), 1):
            row = future.result()
            failures += row['returncode'] != 0
            print(f"compile {count}/{len(rows)} {row['name']}: {row['returncode']}", flush=True)
    print(f'compile: {failures}/{len(rows)} failures', flush=True)
    return int(failures != 0)


def summarize(directory):
    rows = []
    counts = {}
    for row in records(directory):
        if row['stage'] != 'generate':
            continue
        name = row['name']
        app = Path(row['proof']).parent.name
        status, detail = 'generation_failed', row['note']
        if row['ok']:
            status, detail = 'compile_pending', ''
            log = directory / 'compile' / (name + '.json')
            if log.exists():
                compiled = json.loads(log.read_text())
                status = 'compile_failed' if compiled['returncode'] else 'verify_pending'
                detail = compiled['stderr']
                rc = directory / 'verify' / (name + '.rc')
                if not compiled['returncode'] and rc.exists():
                    accepted = int(rc.read_text()) == 0
                    verifier = directory / 'verify' / (name + '.verifier.log')
                    status = ('verifier_accepted' if accepted else 'verifier_rejected'
                              if verifier.exists() and verifier.stat().st_size else 'load_failed')
                    detail = (directory / 'verify' / (name + '.stderr')).read_text()
        cause = ''
        if status.endswith('_failed') or status == 'verifier_rejected':
            causes = ['unsupported arm64 instruction', 'unsupported indirect call', 'undeclared function',
                      'unsupported opcode', 'arm64_sim_unsupported_opcode', 'stack limit',
                      'stack frame', 'compile timeout', 'unknown func', 'invalid mem access',
                      'BPF program is too large', 'infinite loop', 'loop is not bounded',
                      'unresolved extern', 'unrecognized extern']
            cause = next((c for c in causes if c.lower() in detail.lower()), 'other (see raw log)')
        rows.append(dict(app=app, name=name, proof=row['proof'], source=row['source'], status=status, cause=cause))
        counts.setdefault(app, {}).setdefault(status, 0)
        counts[app][status] += 1
    with (directory / 'coverage.csv').open('w') as out:
        writer = csv.DictWriter(out, fieldnames=['app', 'name', 'proof', 'source', 'status', 'cause'], lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    statuses = ['generation_failed', 'compile_pending', 'compile_failed', 'verify_pending',
                'verifier_accepted', 'verifier_rejected', 'load_failed']
    lines = ['Artifact census (all entries use the harness XDP ABI; no app execution is implied).', '',
             '| App | Objects | ' + ' | '.join(statuses) + ' |',
             '| --- | ---: | ' + ' | '.join(['---:'] * len(statuses)) + ' |']
    for app, count in sorted(counts.items()):
        lines.append('| ' + app + ' | ' + str(sum(count.values())) + ' | ' +
                     ' | '.join(str(count.get(s, 0)) for s in statuses) + ' |')
    (directory / 'table.md').write_text('\n'.join(lines) + '\n')
    print('\n'.join(lines))
    with tarfile.open(directory / 'generated-sources.tar.gz', 'w:gz') as archive:
        for run_dir in sorted({Path(row['source']).parent for row in rows}):
            archive.add(run_dir, arcname=run_dir.name)
        if (directory / 'compile-sources').exists():
            archive.add(directory / 'compile-sources', arcname='compile-sources')
    if (directory / 'simulator').exists():
        with tarfile.open(directory / 'simulator-snapshot.tar.gz', 'w:gz') as archive:
            for name in ['simulator', 'formal']:
                archive.add(directory / name, arcname=name)
    if (directory / 'objects').exists():
        with tarfile.open(directory / 'compiled-objects.tar.gz', 'w:gz') as archive:
            for log in sorted((directory / 'compile').glob('*.json')):
                row = json.loads(log.read_text())
                if row['returncode'] == 0:
                    obj = directory / 'objects' / (row['name'] + '.bpf.o')
                    archive.add(obj, arcname=obj.name)
    return 0


def package(directory, build, base):
    root = build / 'root'
    if root.exists():
        shutil.rmtree(root)
    root.mkdir(parents=True)
    with base.open('rb') as source:
        unpack = subprocess.run(['gzip', '-dc'], stdin=source, capture_output=True, check=True)
    subprocess.run(['cpio', '-id', '--quiet', '--no-absolute-filenames',
                    'bin/busybox', 'lib/*', 'dev/console'], cwd=root, input=unpack.stdout, check=True)
    for name in ['proc', 'sys', 'results', 'objects', 'tmp']:
        (root / name).mkdir(exist_ok=True)
    (root / 'bin/sh').symlink_to('busybox')
    shutil.copy2(ROOT / 'kprog/loader/target/aarch64-unknown-linux-gnu/debug/reversesim-loader', root / 'loader')
    shutil.copy2('/usr/aarch64-linux-gnu/lib/libgcc_s.so.1', root / 'lib/libgcc_s.so.1')
    names = []
    for log in sorted((directory / 'compile').glob('*.json')):
        row = json.loads(log.read_text())
        if row['returncode'] == 0:
            name = row['name']
            shutil.copy2(directory / 'objects' / (name + '.bpf.o'), root / 'objects')
            names.append(name)
    if not names:
        raise RuntimeError('no compiled artifacts to load')
    script = ['#!/bin/sh', 'export PATH=/bin', 'busybox mount -t proc proc /proc || exit 1',
              'busybox mount -t sysfs sysfs /sys || exit 1',
              'busybox mount -t 9p -o trans=virtio results /results || exit 1',
              'ulimit -l unlimited || exit 1', 'status=0']
    for name in names:
        script.extend([f'echo load {name}',
                       f'busybox timeout 60 /loader --object /objects/{name}.bpf.o '
                       f'--program {name}_arm64_sim_xdp --load-only '
                       f'--verifier-log /results/{name}.verifier.log '
                       f'>/results/{name}.stdout 2>/results/{name}.stderr',
                       'rc=$?', f'echo "$rc" >/results/{name}.rc',
                       'if [ "$rc" != 0 ]; then status=1; fi'])
    script.extend(['echo "$status" >/results/guest-status', 'busybox sync', 'busybox poweroff -f'])
    (root / 'init').write_text('\n'.join(script) + '\n')
    (root / 'init').chmod(0o755)
    files = '\n'.join(['.'] + sorted(str(p.relative_to(root)) for p in root.rglob('*'))) + '\n'
    archive = subprocess.run(['cpio', '-o', '-H', 'newc', '--quiet'], cwd=root,
                             input=files.encode(), capture_output=True, check=True)
    with (build / 'initramfs.cpio.gz').open('wb') as out:
        subprocess.run(['gzip', '-c'], input=archive.stdout, stdout=out, check=True)
    print(f'packaged {len(names)} diagnostic artifacts in {build}')
    return 0


if __name__ == '__main__':
    action, path, *rest = sys.argv[1:]
    directory = Path(path).resolve()
    if action == 'compile':
        code = compile_all(directory)
    elif action == 'summarize':
        code = summarize(directory)
    elif action == 'package':
        code = package(directory, *map(Path, rest))
    elif action == 'inventory':
        code = inventory(directory)
    else:
        raise ValueError(action)
    raise SystemExit(code)
