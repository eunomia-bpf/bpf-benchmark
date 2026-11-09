"""Compile the complete application native inputs for the fixed-model replay."""
from pathlib import Path
import hashlib
import json
import shlex
import shutil
import subprocess
import tarfile
import sys
import importlib.util

ROOT = Path('/workspaces/repository')
STATE = Path('/var/tmp/kprog-tmp/C/audit-recovery/native-inputs')
PAIRED = Path('/var/tmp/kprog-tmp/C/audit-recovery/paired-source/tetragon')
LINKER = Path('/var/tmp/kprog-tmp/C/stock-entry/native-link-target/release/native-link')


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def run(command, name):
    write(STATE / (name + '.command.json'), [str(v) for v in command])
    with (STATE / (name + '.log')).open('w') as output:
        result = subprocess.run([str(v) for v in command], cwd=ROOT / 'vendor/bpf',
                                stdout=output, stderr=subprocess.STDOUT)
    (STATE / (name + '.exit')).write_text(str(result.returncode) + '\n')
    result.check_returncode()


def main():
    STATE.mkdir(parents=True, exist_ok=True)
    archive_path = 'corpus/results/kprog_app_coverage_20261109/current-abi-app-payloads/tetragon/producer.tar.gz'
    stream = subprocess.Popen(['git', 'show', 'HEAD:' + archive_path],
                              cwd=ROOT, stdout=subprocess.PIPE)
    with tarfile.open(fileobj=stream.stdout, mode='r|gz') as archive:
        for member in archive:
            if member.name == 'native-only.mk':
                with (STATE / 'native-only.mk').open('wb') as output:
                    shutil.copyfileobj(archive.extractfile(member), output)
    stream.stdout.close()
    if stream.wait():
        raise RuntimeError('committed producer export failed')
    (STATE / 'native-only.mk').chmod(0o444)
    plugin = STATE / 'native_division.so'
    flags = shlex.split(subprocess.check_output(
        ['llvm-config-18', '--cxxflags', '--ldflags', '--system-libs', '--libs', 'core', 'passes'],
        text=True))
    run(['clang-18', '-x', 'c++', '-fPIC', '-shared',
         ROOT / 'vendor/bpf/native_division.cpp', *flags, '-O2', '-o', plugin], 'plugin')
    native = STATE / 'native'
    common = ['make', '-C', ROOT / 'vendor/bpf', '-f', STATE / 'native-only.mk',
              'ARCH=x86', 'KERNEL_RELEASE=7.0.0-rc2+', 'CLANG=clang-18',
              'LLVM_CONFIG=llvm-config-18', 'LLVM_NM=llvm-nm-18',
              'NATIVE_OUT=' + str(native), 'NATIVE_STAGE_ROOT=' + str(STATE / 'stage'),
              'NATIVE_DIVISION_PLUGIN=' + str(plugin), 'NATIVE_LINK=' + str(LINKER),
              'NATIVE_ARCH_CFLAGS=-march=native -mno-red-zone -mgeneral-regs-only -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mno-sse4a -msoft-float',
              '-o', str(plugin), '-o', 'tetragon/bpf/include/vmlinux_generated_x86.h']
    run(common + ['native-tetragon'], 'tetragon')
    run(common + [native / 'tracee/tracee.native.o',
                  native / 'tracee/lsm_support/kprobe_check.native.o',
                  native / 'tracee/lsm_support/lsm_check.native.o'], 'tracee')
    run(common + [native / 'otel/otelcol-ebpf-profiler.native.o'], 'otel')
    cilium()
    manifests()


def manifests():
    native = STATE / 'native'
    cel = STATE / 'cel-defaults.bpf.o'
    run(['make', '-C', ROOT / 'vendor/bpf', cel,
         'TETRAGON_CEL_SOURCE_LIBRARY=' + str(cel)], 'cel')
    writer = ['python3', ROOT / 'vendor/bpf/write_native_manifest.py',
              '--llvm-nm', 'llvm-nm-18']
    rows = []
    for app, directory in [('tetragon', 'tetragon'), ('tracee', 'tracee'),
                           ('otelcol-ebpf-profiler', 'otel')]:
        target = STATE / 'payloads' / app
        target.mkdir(parents=True, exist_ok=True)
        for source in (native / directory).rglob('*.native.o'):
            shutil.copy2(source, target / source.name)
        command = writer + ['--app', app, '--output', target / 'manifest.json']
        objects = sorted(target.glob('*.native.o'))
        if app == 'tetragon':
            command += ['--dedupe-program', 'last', '--source-object-root', PAIRED,
                        '--helper-disambiguate', '174', '--source-library', cel,
                        '--bpftool', ROOT / 'vendor/build/x86/bpftool/bin/bpftool']
        elif app == 'tracee':
            command += ['--dedupe-program', 'last']
        for source in objects:
            option = ('--data-object' if app == 'otelcol-ebpf-profiler' and
                      source.name != 'otelcol-ebpf-profiler.native.o' else '--object')
            command += [option, source]
        run(command, 'manifest-' + directory)
        rows.append(dict(application=app, directory=str(target), objects=len(objects),
                         manifest_entries=len(json.loads((target / 'manifest.json').read_text())['objects']),
                         files={p.name: hashlib.sha256(p.read_bytes()).hexdigest()
                                for p in target.iterdir() if p.is_file()}))
        write(STATE / 'progress.json', rows)
    cilium_dir = STATE / 'payloads/cilium'
    rows.append(dict(application='cilium', directory=str(cilium_dir),
        objects=len(list(cilium_dir.rglob('*.native.o'))),
        manifest_entries=len(json.loads((cilium_dir / 'manifest.json').read_text())['objects'])))
    write(STATE / 'complete.json', rows)


def cilium():
    archive_path = 'corpus/results/kprog_app_coverage_20261109/current-abi-app-payloads/cilium/producer.tar.gz'
    inputs = STATE / 'cilium-input'
    inputs.mkdir(exist_ok=True)
    process = subprocess.Popen(['git', 'show', 'HEAD:' + archive_path],
                               cwd=ROOT, stdout=subprocess.PIPE)
    with tarfile.open(fileobj=process.stdout, mode='r|gz') as archive:
        for member in archive:
            if member.name.startswith('native-bpf/cilium/'):
                archive.extract(member, inputs, filter='data')
    process.stdout.close()
    if process.wait():
        raise RuntimeError('committed Cilium input export failed')
    for path in inputs.rglob('*'):
        if path.is_file():
            path.chmod(path.stat().st_mode & ~0o222)
    base = inputs / 'native-bpf/cilium'
    target = STATE / 'payloads/cilium'
    shutil.copytree(base, target, dirs_exist_ok=True)
    spec = importlib.util.spec_from_file_location(
        'cilium_native_build', ROOT / 'runner/libs/cilium_native_build.py')
    builder = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(builder)
    compat = STATE / 'native_compat.h'
    shutil.copy2(ROOT / 'vendor/bpf/native_compat.h', compat)
    compat.chmod(0o444)
    rows = []
    for parity in sorted((base / 'parity').glob('*/*/parity.json')):
        data = json.loads(parity.read_text())
        directory = parity.parent
        overlay = directory / 'native-abi-overlay'
        source = overlay / (directory.parent.name + '.c')
        headers = STATE / 'cilium-headers' / directory.name
        headers.mkdir(parents=True, exist_ok=True)
        for record in data['headers']:
            shutil.copy2(directory / record['archive'], headers / Path(record['source']).name)
        args = []
        for arg in data['bpf_command'][1:]:
            if arg.startswith('-I/var/tmp/ciliumrunner_'):
                arg = '-I' + str(headers)
            elif arg.startswith('-I/var/lib/cilium/bpf'):
                arg = arg.replace('/var/lib/cilium/bpf', str(overlay))
            elif arg.startswith('/var/lib/cilium/bpf/'):
                arg = str(source)
            args.append(arg)
        old_output = data['native_command'][data['native_command'].index('-o') + 1]
        relative = old_output.split('/details/cilium-native-config/', 1)[1]
        output = target / relative
        output.parent.mkdir(parents=True, exist_ok=True)
        output.chmod(0o644)
        extras = [arg for arg in data['native_command'] if arg.startswith('-DBPFBENCH_')]
        command = ['clang-18', *builder.native_compile_args(args, output,
            compat, overlay, source, extras)]
        run(command, 'cilium-' + directory.parent.name + '-' + directory.name)
        rows.append(dict(family=directory.parent.name, configuration=directory.name,
                         output=str(output), sha256=hashlib.sha256(output.read_bytes()).hexdigest()))
    write(STATE / 'cilium-compiles.json', rows)


if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'finish':
        cilium()
        manifests()
    else:
        main()
