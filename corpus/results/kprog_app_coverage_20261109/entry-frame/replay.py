"""Reuse the published safety/census drivers with a paired stock entry ABI."""
from pathlib import Path
import argparse
import concurrent.futures
import hashlib
import importlib.util
import json
import os
import shutil
import subprocess
import sys
import tarfile
import threading

ROOT = Path('/workspaces/repository')
STATE = Path('/var/tmp/kprog-tmp/C/stock-entry')
NATIVE_LINK = STATE / 'native-link-target/release/native-link'


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def bind(source, target):
    subprocess.run(['mount', '--bind', str(source), str(target)], check=True)


def link(source, target):
    if not os.path.lexists(target):
        target.symlink_to(source)


def prepare(epoch):
    source = epoch / 'source'
    source.mkdir(parents=True, exist_ok=True)
    revision = epoch.name
    tracked = subprocess.check_output(['git', 'ls-tree', '-r', '--name-only', revision,
                                      '--', 'kprog'], cwd=ROOT, text=True).splitlines()
    selected = [p for p in tracked if (
        (Path(p).parent == Path('kprog') and p.endswith('.py')) or
        p.startswith(('kprog/x86/micro-prog/', 'kprog/formal/generated/',
                      'kprog/stock-path/')) and p.endswith(('.py', '.sh', '.h')) or
        Path(p).parent == Path('kprog/x86') and p.endswith(('.py', '.h')) or
        p in ['kprog/stock-path/bin/clang', 'kprog/selftests/submit.py',
              'kprog/fidelity/negative.py',
              'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py'])]
    archive = subprocess.Popen(['git', 'archive', revision, '--', *selected],
                               cwd=ROOT, stdout=subprocess.PIPE)
    with tarfile.open(fileobj=archive.stdout, mode='r|') as stream:
        stream.extractall(source, filter='data')
    archive.stdout.close()
    if archive.wait():
        raise RuntimeError('committed source export failed')
    for path in source.rglob('*'):
        if path.is_file():
            path.chmod(path.stat().st_mode & ~0o222)
    for suite, original in [('isa48', Path('/var/tmp/kprog-tmp/S17/x86-input')),
                            ('selftests315', ROOT / 'kprog/selftests/build')]:
        work = epoch / suite
        inputs = work / ('x86-input' if suite == 'isa48' else 'table')
        inputs.mkdir(parents=True, exist_ok=True)
        rows = []
        for path in sorted(original.iterdir()):
            if path.is_file() and path.suffix in {'.json', '.o'}:
                target = inputs / path.name
                shutil.copy2(path, target)
                rows.append(dict(name=target.name, bytes=target.stat().st_size,
                                 sha256=hashlib.sha256(target.read_bytes()).hexdigest()))
        write(work / 'inputs.json', rows)
    tail = epoch / 'tail'
    tail.mkdir(exist_ok=True)
    rows = []
    for source in [Path('/var/tmp/kprog-tmp/S17/frameprobe/client'),
                   Path('/var/tmp/kprog-tmp/S17/tail/tail.bpf.o'),
                   Path('/var/tmp/kprog-tmp/S17/tail/tail.native.o')]:
        target = tail / source.name
        shutil.copy2(source, target)
        rows.append(dict(name=target.name, sha256=hashlib.sha256(target.read_bytes()).hexdigest()))
    write(tail / 'inputs.json', rows)
    for work in [epoch / name for name in ['isa48', 'selftests315', 'tail']]:
        lines = ['#!/bin/sh', 'exec python3 ' +
                 str(ROOT / 'kprog/corpus_resident_verifier.py') + ' compile --scratch ' +
                 str(work) + ' "$@"', '']
        (work / 'stock-compile-proxy').write_text(chr(10).join(lines))
        (work / 'stock-compile-proxy').chmod(0o755)
    write(epoch / 'provenance.json', dict(model_head=revision,
          kernel_base='35ea2cde39fc88b01f2f49b2a357e7cf7102e4c8',
          kernel_patch='kprog/stock-path/x86-entry-frame.patch',
          kernel_image=str(STATE / 'kernel-build/arch/x86/boot/bzImage'),
          native_link=str(NATIVE_LINK),
          isa_cases=48, upstream_programs=315, census_bodies=27, census_instances=275))


def namespace(epoch):
    os.unshare(os.CLONE_NEWNS)
    subprocess.run(['mount', '--make-rprivate', '/'], check=True)
    for path in (epoch / 'source').rglob('*'):
        if path.is_file():
            bind(path, ROOT / path.relative_to(epoch / 'source'))
    for name in ['libnative_loader.so', 'trusted-native-loader']:
        bind((STATE / 'loader') / name,
             ROOT / 'kprog/libnativeloader/build' / name)
    bind(NATIVE_LINK,
         ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link')


def safety(epoch, suite):
    namespace(epoch)
    work = epoch / suite
    write(work / 'runtime.json', {str(p): hashlib.sha256(p.read_bytes()).hexdigest()
        for p in [STATE / 'kernel-build/arch/x86/boot/bzImage',
                  STATE / 'module/kprog_stock.ko', NATIVE_LINK,
                  STATE / 'loader/libnative_loader.so',
                  STATE / 'loader/trusted-native-loader']})
    if suite == 'selftests315':
        bind(work / 'table', ROOT / 'kprog/selftests/build')
    for source, name in [(STATE / 'module/kprog_stock.ko', 'kprog_stock.ko'),
                         (NATIVE_LINK, 'native-link'),
                         (Path('/var/tmp/kprog-tmp/S17/bp/bound-probe'), 'bound-probe')]:
        shutil.copy2(source, work / name)
    output = work / 'out'
    output.mkdir(exist_ok=True)
    guest = work / 'guest.sh'
    if suite == 'isa48':
        command = ('python3 ' + str(ROOT / 'kprog/stock-path/run_safety.py') +
            ' check --out ' + str(output) + ' --inputs /mnt/x86-input --cases /mnt/x86-input/cases.json')
    elif suite == 'selftests315':
        command = ('python3 ' + str(ROOT / 'kprog/selftests/submit.py') +
            ' --arch x86 --table ' + str(work / 'table') + ' --out ' + str(output))
    else:
        shutil.copy2(STATE / 'frame-probe/tail_frame_probe.ko', work / 'tail_frame_probe.ko')
        command = ('/mnt/client /mnt/tail.bpf.o /mnt/tail.native.o /mnt/native-link ' +
                   str(output / 'native.bin') + ' /mnt/tail_frame_probe.ko')
    lines = ['#!/bin/bash', 'set -e', 'install -d ' + str(work),
        'mount --bind /mnt ' + str(work),
        'mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf',
        'export KPROG_STOCK_MODULE=/mnt/kprog_stock.ko',
        'export KPROG_STOCK_LOADER=' + str(ROOT / 'kprog/libnativeloader/build'),
        'export KPROG_STOCK_BOUND_PROBE=/mnt/bound-probe',
        'export KPROG_STOCK_NATIVE_LINK=/mnt/native-link',
        'OUT=' + str(output),
        '. ' + str(ROOT / 'kprog/stock-path/guest/common.sh'),
        'export TMPDIR=' + str(work) + ' CLANG=' + str(work / 'stock-compile-proxy')]
    if suite == 'tail':
        lines.append('start_service')
    lines += ['set +e', command + ' > "$OUT/suite.log" 2>&1', 'result=$?']
    if suite == 'tail':
        lines.append('stop_service')
    lines += ['printf "%s' + chr(92) + 'n" "$result" > "$OUT/suite.exit"',
              'dmesg > "$OUT/dmesg"', 'exit "$result"', '']
    guest.write_text(chr(10).join(lines))
    with (work / 'stock-compiler.log').open('w') as log:
        compiler = subprocess.Popen([sys.executable, str(ROOT / 'kprog/trusted_compile.py'),
            'serve', '--scope', str(work), '--state', str(work / 'stock-compiler'),
            '--clang', str(epoch / 'source/kprog/stock-path/bin/clang')],
            stdout=log, stderr=subprocess.STDOUT)
        try:
            invocation = ['taskset', '-c', '20-23', 'vng', '--run',
                str(STATE / 'kernel-build/arch/x86/boot/bzImage'), '--cpus', '2',
                '--memory', '4G', '--rwdir=/mnt=' + str(work),
                '--exec', 'bash /mnt/guest.sh', '--qemu-opts=-cpu host,+smap']
            write(work / 'command.json', invocation)
            with (work / 'console.log').open('w') as console:
                result = subprocess.run(invocation, stdout=console, stderr=subprocess.STDOUT)
            (work / 'guest.exit').write_text(str(result.returncode) + '\n')
            return result.returncode
        finally:
            (work / 'stock-compiler/STOP').touch()
            compiler.wait()


def census(epoch):
    namespace(epoch)
    original = Path('/var/tmp/kprog-tmp/A/resident-census-linked')
    inputs = epoch / 'census-inputs'
    inputs.mkdir(exist_ok=True)
    for name in ['run-inventory.json', 'resource-index.json']:
        data = json.loads((original / name).read_text())
        if name == 'run-inventory.json':
            data['source_head'] = epoch.name
            data['kernel_image'] = str(STATE / 'kernel-build/arch/x86/boot/bzImage')
        write(inputs / name, data)
    link(epoch / 'source', inputs / 'source')
    shutil.copy2(NATIVE_LINK, inputs / 'native-link')
    runtime = inputs / 'stock-runtime'
    runtime.mkdir(exist_ok=True)
    shutil.copy2(STATE / 'module/kprog_stock.ko', runtime / 'kprog_stock.ko')
    for name in ['libnative_loader.so', 'trusted-native-loader']:
        shutil.copy2(STATE / 'loader' / name, runtime / name)
    scratch = epoch / 'census'
    scratch.mkdir(exist_ok=True)
    link(epoch / 'source', scratch / 'controller-source')
    grouped = module('entry_groups', ROOT / 'kprog/corpus_resident_groups.py')
    baseline = json.loads(Path('/var/tmp/kprog-tmp/A/resident-census-groups/groups.json').read_text())
    groups = [dict(body_sha256=g['body_sha256'], representative=g['representative'],
                   members=[dict(source_prog_id=m['source_prog_id']) for m in g['members']])
              for g in baseline['groups']]
    lock = threading.Lock()
    def run(cpu, assigned):
        for group in assigned:
            result = grouped.shard(scratch, inputs, group, cpu)
            with lock:
                group.update(result)
                write(scratch / 'groups.json', dict(model_head=epoch.name, groups=groups))
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        jobs = [pool.submit(run, cpu, groups[i::4]) for i, cpu in enumerate(range(20, 24))]
        for job in concurrent.futures.as_completed(jobs):
            job.result()
    write(scratch / 'complete.json', dict(bodies=len(groups), instances=275,
                                         native_execution_requests=0))
    return 0


def main():
    global NATIVE_LINK
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['prepare', 'isa48', 'selftests315', 'tail', 'census'])
    parser.add_argument('--revision', default='HEAD')
    parser.add_argument('--native-link', type=Path, default=NATIVE_LINK)
    args = parser.parse_args()
    NATIVE_LINK = args.native_link
    revision = subprocess.check_output(['git', 'rev-parse', args.revision],
                                       cwd=ROOT, text=True).strip()
    epoch = STATE / 'replays' / revision
    if args.mode == 'prepare':
        prepare(epoch)
        return 0
    return census(epoch) if args.mode == 'census' else safety(epoch, args.mode)


if __name__ == '__main__':
    raise SystemExit(main())
