"""Compile the complete paired Tetragon P input with native map lowering."""
from pathlib import Path
import argparse
import hashlib
import json
import os
import shlex
import shutil
import subprocess
import tarfile

ROOT = Path('/workspaces/repository')
STATE = Path('/var/tmp/kprog-tmp/C/map-lookup-native/tetragon')
INPUT = 'corpus/results/kprog_app_coverage_20261109/current-abi-app-payloads/tetragon/producer.tar.gz'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def run(command, log):
    write(log.with_suffix('.command.json'), [str(v) for v in command])
    with log.open('w') as output:
        result = subprocess.run(command, cwd=ROOT / 'vendor/bpf', stdout=output,
                                stderr=subprocess.STDOUT)
    log.with_suffix('.exit').write_text(str(result.returncode) + '\n')
    result.check_returncode()


def prepare():
    STATE.mkdir(parents=True, exist_ok=True)
    export = STATE / 'committed-input'
    export.mkdir(exist_ok=True)
    blob = subprocess.check_output(['git', 'rev-parse', 'HEAD:' + INPUT],
                                   cwd=ROOT, text=True).strip()
    process = subprocess.Popen(['git', 'show', blob], cwd=ROOT, stdout=subprocess.PIPE)
    with tarfile.open(fileobj=process.stdout, mode='r|gz') as archive:
        for member in archive:
            if member.name.startswith('source/tetragon/') or member.name in {
                    'native-only.mk', 'source/native_compat.h', 'inputs.json'}:
                archive.extract(member, export, filter='data')
    process.stdout.close()
    if process.wait():
        raise RuntimeError('committed producer input export failed')
    files = {str(p.relative_to(export)): sha(p) for p in export.rglob('*') if p.is_file()}
    for path in export.rglob('*'):
        if path.is_file():
            path.chmod(path.stat().st_mode & ~0o222)
    flags = shlex.split(subprocess.check_output(
        ['llvm-config-18', '--cxxflags', '--ldflags', '--system-libs', '--libs',
         'core', 'passes'], text=True))
    layout = json.loads(Path('/var/tmp/kprog-tmp/C/map-lookup-native/btf-layout.json').read_text())
    offsets = layout['offsets']
    macros = {'K_BPF_MAP_MAX_ENTRIES_OFFSET': offsets['bpf_map.max_entries'],
              'K_BPF_ARRAY_VALUE_OFFSET': offsets['bpf_array.value'],
              'K_BPF_ARRAY_ELEM_SIZE_OFFSET': offsets['bpf_array.elem_size'],
              'K_BPF_ARRAY_INDEX_MASK_OFFSET': offsets['bpf_array.index_mask']}
    for label in ['control', 'candidate']:
        directory = STATE / label
        directory.mkdir(exist_ok=True)
        command = ['clang-18', '-x', 'c++', '-fPIC', '-shared',
                   str(ROOT / 'vendor/bpf/native_division.cpp'), *flags, '-O2']
        if label == 'candidate':
            command += ['-D' + key + '=' + str(value) for key, value in macros.items()]
        command += ['-o', str(directory / 'native_division.so')]
        run(command, directory / 'plugin.log')
    jit = STATE / 'jit'
    jit.mkdir(exist_ok=True)
    for path in Path('/var/tmp/kprog-tmp/C/current-abi-app-payloads/paired-tetragon-bpf').glob('*.o'):
        shutil.copy2(path, jit / path.name)
    write(STATE / 'inputs.json', dict(committed_input_blob=blob, input_path=INPUT,
          source_epoch=json.loads((export / 'inputs.json').read_text()),
          source_files=files, plugin_source_sha256=sha(ROOT / 'vendor/bpf/native_division.cpp'),
          producer_head=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT,
                                                text=True).strip(),
          layout=layout, jit_files={p.name: sha(p) for p in jit.iterdir()}))


def build():
    source = STATE / 'committed-input'
    for local, target in [(source / 'source/tetragon', ROOT / 'vendor/bpf/tetragon/bpf'),
                          (source / 'source/native_compat.h', ROOT / 'vendor/bpf/native_compat.h')]:
        subprocess.run(['mount', '--bind', str(local), str(target)], check=True)
        subprocess.run(['mount', '-o', 'remount,bind,ro', str(target)], check=True)
    header = source / 'source/tetragon/include/vmlinux_generated_x86.h'
    library = STATE / 'cel-defaults.bpf.o'
    run(['make', '-C', str(ROOT / 'vendor/bpf'), str(library),
         'TETRAGON_CEL_SOURCE_LIBRARY=' + str(library)], STATE / 'cel.log')
    for label in ['control', 'candidate']:
        directory = STATE / label
        plugin = directory / 'native_division.so'
        run(['make', '-C', str(ROOT / 'vendor/bpf'), '-f', str(source / 'native-only.mk'),
             '-o', str(header), '-o', str(plugin), 'native-tetragon', 'ARCH=x86',
             'KERNEL_RELEASE=7.0.0-rc2+', 'NATIVE_OUT=' + str(directory / 'native'),
             'NATIVE_STAGE_ROOT=' + str(directory / 'stage'),
             'NATIVE_DIVISION_PLUGIN=' + str(plugin), 'TETRAGON_VMLINUX_H=' + str(header),
             'NATIVE_LINK=/var/tmp/kprog-tmp/C/stock-entry/native-link-before'],
            directory / 'compile.log')
        native = directory / 'native/tetragon'
        command = ['python3', str(ROOT / 'vendor/bpf/write_native_manifest.py'),
            '--app', 'tetragon', '--llvm-nm', 'llvm-nm-18', '--dedupe-program', 'last',
            '--source-object-root', str(STATE / 'jit'), '--helper-disambiguate', '174',
            '--source-library', str(library), '--output', str(native / 'manifest.json')]
        for path in sorted(native.glob('*.native.o')):
            command += ['--object', str(path)]
        run(command, directory / 'manifest.log')
        write(directory / 'complete.json', dict(native_objects=len(list(native.glob('*.native.o'))),
              manifest_entries=len(json.loads((native / 'manifest.json').read_text())['objects']),
              map_lowered_sites=(directory / 'compile.log').read_text().count('native-map-lowering:'),
              percpu_lowered_sites=(directory / 'compile.log').read_text().count('native-map-lowering: percpu-array ')))
    write(STATE / 'complete.json', {label: json.loads((STATE / label / 'complete.json').read_text())
                                  for label in ['control', 'candidate']})


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['prepare', 'build'])
    arguments = parser.parse_args()
    prepare() if arguments.mode == 'prepare' else build()
