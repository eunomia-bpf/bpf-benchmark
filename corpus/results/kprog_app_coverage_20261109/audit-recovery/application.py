"""Run the frozen six-app startup through the fixed stock-path model."""
from pathlib import Path
import argparse
import json
import os
import shutil
import subprocess
import sys

ROOT = Path('/workspaces/repository')
HERE = Path(__file__).resolve().parent
G = Path('/var/tmp/kprog-tmp/C/audit-recovery/application')
V = Path('/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/coherent-six-app-runtime')
BASE = 'bpf-benchmark/kprog-paper-may29:r'
IMAGE = 'bpf-benchmark/kprog-coherent-six:c-20261109'
STOCK = Path('/var/tmp/kprog-tmp/C/stock-entry')
INPUTS = Path('/var/tmp/kprog-tmp/C/audit-recovery')


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def run(command, name):
    write(G / (name + '.command.json'), [str(v) for v in command])
    with (G / (name + '.log')).open('w') as output:
        result = subprocess.run([str(v) for v in command], cwd=ROOT,
                                stdout=output, stderr=subprocess.STDOUT)
    (G / (name + '.exit')).write_text(str(result.returncode) + '\n')
    result.check_returncode()


def image(epoch):
    G.mkdir(parents=True, exist_ok=True)
    context = G / 'image'
    context.mkdir(exist_ok=True)
    runtime = epoch / 'runtime'
    (STOCK / 'shim-build').mkdir(exist_ok=True)
    run(['make', '-C', ROOT / 'bpfopt/shim',
         'SHIM_SO=' + str(STOCK / 'shim-build/libbpfrejit_shim.so'),
         STOCK / 'shim-build/libbpfrejit_shim.so'], 'shim-build')
    for source, name in [
        (runtime / 'kprog_stock.ko', 'bpf_kprog_stock.ko'),
        (runtime / 'native-link', 'native-link'),
        (runtime / 'libnative_loader.so', 'libnative_loader.so'),
        (STOCK / 'shim-build/libbpfrejit_shim.so', 'libbpfrejit_shim.so'),
        (INPUTS / 'native-inputs/native_compat.h', 'native_compat.h'),
        (INPUTS / 'native-inputs/native_division.so', 'native_division.so'),
        (ROOT / 'runner/libs/cilium_native_build.py', 'cilium_native_build.py'),
        (STOCK / 'loader-offsets/kernel_offsets.h', 'kernel_offsets.h'),
        (INPUTS / 'paired-source/tracee/tracee.bpf.o', 'tracee.bpf.o')]:
        shutil.copy2(source, context / name)
    shutil.copytree(INPUTS / 'native-inputs/payloads', context / 'native-bpf',
                    dirs_exist_ok=True)
    shutil.copytree(INPUTS / 'paired-source/tetragon', context / 'tetragon-bpf',
                    dirs_exist_ok=True)
    run(['make', '-C', '/var/tmp/kprog-tmp/CK/linux',
         'O=' + str(STOCK / 'kernel-build'), '-j4', 'modules_install',
         'INSTALL_MOD_PATH=' + str(context / 'modules'),
         'INSTALL_MOD_STRIP=1', 'DEPMOD=true'], 'modules-install')
    lines = [
        'FROM ' + BASE,
        'RUN cp -a /paper-tree/. /workspaces/repository/ && rm -f /artifacts/kinsn/*.ko',
        'COPY native-bpf/ /artifacts/user/native-bpf/x86_64/',
        'COPY tetragon-bpf/ /artifacts/user/repo-artifacts/x86_64/tetragon/',
        'COPY tracee.bpf.o /artifacts/tracee/tracee.bpf.o',
        'COPY libnative_loader.so libbpfrejit_shim.so /usr/local/lib/bpfrejit/',
        'COPY native-link /usr/local/bin/native-link',
        'COPY native_compat.h native_division.so /usr/local/lib/bpfrejit/native/',
        'COPY cilium_native_build.py /workspaces/repository/runner/libs/cilium_native_build.py',
        'COPY kernel_offsets.h /artifacts/kernel/kernel_offsets.h',
        'COPY bpf_kprog_stock.ko /artifacts/kinsn/bpf_kprog_stock.ko',
        'COPY modules/ /artifacts/',
        'ENV BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1',
        'ENV BPFREJIT_CORPUS_APP_TIMEOUT=0 BPFREJIT_CORPUS_REJIT_TIMEOUT=0',
        'ENV CLANG=/usr/lib/llvm-18/bin/clang SKIP_REJIT=norejit',
        '',
    ]
    (context / 'Dockerfile').write_text('\n'.join(lines))
    run(['docker', 'build', '-t', IMAGE, context], 'image-build')
    run(['docker', 'save', '-o', G / 'runtime.image.tar', IMAGE], 'image-save')
    write(G / 'image.json', dict(
        model=epoch.name, base=BASE, image=IMAGE,
        runtime_adapter_head=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        image_id=subprocess.check_output(
            ['docker', 'image', 'inspect', IMAGE, '--format', '{{.Id}}'], text=True).strip(),
        upstream_tracee_support_and_binary=True,
        workload='9f3855f6f', native_inputs=json.loads(
            (INPUTS / 'native-inputs/complete.json').read_text())))


def replay(epoch):
    os.unshare(os.CLONE_NEWNS)
    subprocess.run(['mount', '--make-rprivate', '/'], check=True)
    alias = V.resolve()
    subprocess.run(['mount', '--bind', str(G), str(alias)], check=True)
    for source in (epoch / 'source').rglob('*'):
        if source.is_file():
            subprocess.run(['mount', '--bind', str(source),
                            str(ROOT / source.relative_to(epoch / 'source'))], check=True)
    results = G / 'corpus-results'
    results.mkdir(exist_ok=True)
    subprocess.run(['mount', '--bind', str(results), str(ROOT / 'corpus/results')], check=True)
    runtime = G / 'runtime'
    runtime.mkdir(exist_ok=True)
    for name in ['native-link', 'trusted-native-loader']:
        shutil.copy2(epoch / 'runtime' / name, runtime / name)
    shutil.copy2(epoch / 'runtime/kprog_stock.ko', runtime / 'bpf_x86_native_lab.ko')
    guest_source = 'corpus/results/kprog_app_coverage_20261109/coherent-six-app-runtime-queue/guest.py'
    guest = G / 'guest.py'
    adapter = json.loads((G / 'image.json').read_text())['runtime_adapter_head']
    guest.write_bytes(subprocess.check_output(['git', 'show', adapter + ':' + guest_source],
                                              cwd=ROOT))
    guest.chmod(0o444)
    proxy = G / 'stock-compile-proxy'
    proxy.write_text('#!/bin/sh\nexec python3 ' + str(ROOT / 'kprog/corpus_resident_verifier.py') +
                     ' compile --scratch ' + str(alias) + ' "$@"\n')
    proxy.chmod(0o755)
    lines = [
        '#!/bin/bash', 'set -e',
        'install -d ' + str(alias),
        'mount --bind /mnt ' + str(alias),
        'export CLANG=' + str(alias / 'stock-compile-proxy'),
        'export PYTHONDONTWRITEBYTECODE=1 BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_INSTALL_SKIP_KINSN=1',
        'python3 /mnt/guest.py --samples 1 --duration 2 --apps ' +
        'bcc/set,katran,cilium/agent,otelcol-ebpf-profiler/profiling,tracee/monitor,tetragon/observer' +
        ' --state ' + str(V), '',
    ]
    (G / 'bootstrap.sh').write_text('\n'.join(lines))
    (G / 'var-tmp').mkdir(exist_ok=True)
    broker_command = [sys.executable, str(ROOT / 'kprog/trusted_compile.py'),
        'serve', '--scope', str(alias), '--state', str(alias / 'stock-compiler'),
        '--clang', str(epoch / 'source/kprog/stock-path/bin/clang')]
    write(G / 'compiler.command.json', broker_command)
    with (G / 'compiler.log').open('w') as output:
        broker = subprocess.Popen(broker_command, stdout=output, stderr=subprocess.STDOUT)
        try:
            command = ['taskset', '-c', '20-23', 'vng', '--run', str(epoch / 'runtime/bzImage'),
                '--cwd', str(ROOT), '--rwdir', str(ROOT), '--rwdir=/mnt=' + str(G),
                '--rwdir=/var/tmp=' + str(G / 'var-tmp'),
                '--overlay-rwdir', '/tmp', '--overlay-rwdir', '/run',
                '--overlay-rwdir', '/usr/local', '--disable-monitor',
                '--cpus', '4', '--memory', '12G', '--qemu-opts=-cpu host,+smap',
                '--exec', 'bash /mnt/bootstrap.sh']
            run(command, 'application')
        finally:
            (alias / 'stock-compiler/STOP').touch()
            broker.wait()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['image', 'run'])
    parser.add_argument('--revision', required=True)
    args = parser.parse_args()
    revision = subprocess.check_output(['git', 'rev-parse', args.revision],
                                       cwd=ROOT, text=True).strip()
    epoch = STOCK / 'replays' / revision
    if args.mode == 'image':
        image(epoch)
    else:
        replay(epoch)


if __name__ == '__main__':
    main()
