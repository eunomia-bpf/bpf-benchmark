#!/usr/bin/env python3
"""Tetragon native payload with the credential-commit unit, for the census follow-up.

The step5 producer (audit-recovery/native-inputs.py; helper-call payload of
65c73b03c/558b8851b in /var/tmp/kprog-tmp/C/audit-recovery/native-inputs-helper-call)
compiles Tetragon with native-only.mk from the committed producer archive
current-abi-app-payloads/tetragon/producer.tar.gz. That snapshot predates
5dbd5d481, which added the bpf_execve_bprm_commit_creds compile to
vendor/bpf/Makefile, so the payload carries 62 objects and no native P for
tg_kp_bprm_committing_creds. This script runs the same snapshot with that one
5dbd5d481 line, the same make arguments, plugin, linker and paired source, into
/var/tmp/kprog-tmp/replay-claude/tetragon-credential; then it compares the other
62 objects and the cel library with the helper-call payload byte for byte and
writes the manifest with the same writer options.
"""
from pathlib import Path
import filecmp
import json
import shutil
import subprocess
import tarfile

ROOT = Path('/workspaces/repository')
STEP5 = Path('/var/tmp/kprog-tmp/C/audit-recovery/native-inputs-helper-call')
PAIRED = Path('/var/tmp/kprog-tmp/C/audit-recovery/paired-source/tetragon')
LINKER = Path('/var/tmp/kprog-tmp/C/stock-entry/native-link-target/release/native-link')
OUT = Path('/var/tmp/kprog-tmp/replay-claude/tetragon-credential')
ANCHOR = 'for name in bpf_execve_event bpf_exit bpf_fork; do'


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def run(command, name):
    write(OUT / (name + '.command.json'), [str(v) for v in command])
    with (OUT / (name + '.log')).open('w') as output:
        result = subprocess.run([str(v) for v in command], cwd=ROOT / 'vendor/bpf',
                                stdout=output, stderr=subprocess.STDOUT)
    (OUT / (name + '.exit')).write_text(str(result.returncode) + '\n')
    result.check_returncode()


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    archive_path = 'corpus/results/kprog_app_coverage_20261109/current-abi-app-payloads/tetragon/producer.tar.gz'
    stream = subprocess.Popen(['git', 'show', 'HEAD:' + archive_path], cwd=ROOT, stdout=subprocess.PIPE)
    with tarfile.open(fileobj=stream.stdout, mode='r|gz') as archive:
        for member in archive:
            if member.name == 'native-only.mk':
                snapshot = archive.extractfile(member).read().decode()
    stream.stdout.close()
    if stream.wait():
        raise RuntimeError('committed producer export failed')
    line = next(l for l in (ROOT / 'vendor/bpf/Makefile').read_text().splitlines()
                if l.strip().startswith('compile_native bpf_execve_bprm_commit_creds '))
    lines = snapshot.splitlines(keepends=True)
    anchor = next(i for i, l in enumerate(lines) if l.strip() == ANCHOR + ' \\')
    lines.insert(anchor, line + '\n')
    makefile = OUT / 'native-only-credential.mk'
    if makefile.exists():
        makefile.chmod(0o644)
    makefile.write_text(''.join(lines))
    makefile.chmod(0o444)
    plugin = STEP5 / 'native_division.so'
    native = OUT / 'native'
    common = ['taskset', '-c', '8-19', 'make', '-C', ROOT / 'vendor/bpf', '-f', makefile,
              'ARCH=x86', 'KERNEL_RELEASE=7.0.0-rc2+', 'CLANG=clang-18',
              'LLVM_CONFIG=llvm-config-18', 'LLVM_NM=llvm-nm-18',
              'NATIVE_OUT=' + str(native), 'NATIVE_STAGE_ROOT=' + str(OUT / 'stage'),
              'NATIVE_DIVISION_PLUGIN=' + str(plugin), 'NATIVE_LINK=' + str(LINKER),
              'NATIVE_ARCH_CFLAGS=-march=native -mno-red-zone -mgeneral-regs-only -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mno-sse4a -msoft-float',
              '-o', str(plugin), '-o', 'tetragon/bpf/include/vmlinux_generated_x86.h']
    run(common + ['native-tetragon'], 'tetragon')
    cel = OUT / 'cel-defaults.bpf.o'
    run(['make', '-C', ROOT / 'vendor/bpf', cel, 'TETRAGON_CEL_SOURCE_LIBRARY=' + str(cel)], 'cel')
    payload = OUT / 'payload'
    payload.mkdir(exist_ok=True)
    for source in (native / 'tetragon').glob('*.native.o'):
        shutil.copy2(source, payload / source.name)
    step5 = STEP5 / 'payloads/tetragon'
    built = sorted(p.name for p in payload.glob('*.native.o'))
    previous = sorted(p.name for p in step5.glob('*.native.o'))
    comparison = dict(
        snapshot=archive_path, inserted_line=line.strip(), objects=len(built),
        step5_objects=len(previous), added=sorted(set(built) - set(previous)),
        absent=sorted(set(previous) - set(built)),
        identical=sorted(n for n in previous if n in built and
                         filecmp.cmp(step5 / n, payload / n, shallow=False)),
        cel_identical=filecmp.cmp(STEP5 / 'cel-defaults.bpf.o', cel, shallow=False))
    comparison['differing'] = sorted(set(previous) & set(built) - set(comparison['identical']))
    command = ['python3', ROOT / 'vendor/bpf/write_native_manifest.py', '--llvm-nm', 'llvm-nm-18',
               '--app', 'tetragon', '--output', payload / 'manifest.json',
               '--dedupe-program', 'last', '--source-object-root', PAIRED,
               '--helper-disambiguate', '174', '--source-library', cel,
               '--bpftool', ROOT / 'vendor/build/x86/bpftool/bin/bpftool']
    for source in sorted(payload.glob('*.native.o')):
        command += ['--object', source]
    run(command, 'manifest-tetragon')
    key = lambda e: json.dumps(e, sort_keys=True)
    mine = json.loads((payload / 'manifest.json').read_text())
    theirs = json.loads((step5 / 'manifest.json').read_text())
    mine_records = {key(e) for e in mine['objects']}
    their_records = {key(e) for e in theirs['objects']}
    comparison.update(
        manifest_records=len(mine['objects']), step5_manifest_records=len(theirs['objects']),
        step5_records_kept=len(their_records & mine_records),
        step5_records_absent=[json.loads(e) for e in sorted(their_records - mine_records)],
        added_records=[json.loads(e) for e in sorted(mine_records - their_records)],
        map_rules_equal=mine.get('map_rules') == theirs.get('map_rules'))
    write(OUT / 'comparison.json', comparison)
    print(json.dumps({k: v for k, v in comparison.items() if k != 'identical'}, indent=2))


if __name__ == '__main__':
    main()
