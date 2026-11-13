#!/usr/bin/env python3
"""Compile unchanged upstream Tetragon using its own BPF build flags."""
import argparse
import hashlib
import json
from pathlib import Path
import shlex
import subprocess
import importlib.util

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--unit', required=True)
    parser.add_argument('--source', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--reference', type=Path, required=True)
    args = parser.parse_args()
    upstream = ROOT / 'vendor/repos/tetragon/bpf'
    source = args.source.resolve()
    if not source.is_relative_to(upstream):
        parser.error('source must be in the canonical upstream Tetragon checkout')
    args.output.mkdir(parents=True, exist_ok=True)
    name = args.output / args.unit
    stem, _, variant = args.unit.rpartition('_')
    if not (variant.startswith('v') and variant[1:].isdigit()):
        variant = ''
    flag_command = ['make', '--no-print-directory', '-s', '-C', str(upstream),
                    '-f', str(HERE / 'tetragon-flags.mk'), 'BPF_TARGET_ARCH=x86',
                    'DEBUG=0', 'UNIT=' + args.unit, 'VARIANT=' + variant, 'flags']
    base = subprocess.run(flag_command, capture_output=True, text=True)
    name.with_suffix('.flags.stdout').write_text(base.stdout)
    name.with_suffix('.flags.stderr').write_text(base.stderr)
    base.check_returncode()
    flags = shlex.split(base.stdout)
    record = dict(unit=args.unit, source=str(source), source_sha256=digest(source),
                  makefiles=[dict(path=str(p), sha256=digest(p)) for p in (upstream / 'Makefile', upstream / 'Makefile.defs')],
                  flag_command=flag_command, flags=flags, compiler_cwd=str(upstream),
                  reference=dict(path=str(args.reference), sha256=digest(args.reference)), commands=[])
    for label, extra, output in [('ir', ['-emit-llvm'], name.with_suffix('.bc')),
                                 ('direct', [], name.with_suffix('.direct.bpf.o'))]:
        command = ['clang-18', *flags, '-MD', '-MF', str(name.with_suffix('.' + label + '.d')),
                   *extra, '-c', str(source), '-o', str(output)]
        result = subprocess.run(command, cwd=upstream, capture_output=True, text=True)
        name.with_suffix('.' + label + '.stdout').write_text(result.stdout)
        name.with_suffix('.' + label + '.stderr').write_text(result.stderr)
        record['commands'].append(dict(label=label, argv=command, returncode=result.returncode))
        name.with_suffix('.source.json').write_text(json.dumps(record, indent=2) + '\n')
        result.check_returncode()
    dependencies = shlex.split(name.with_suffix('.ir.d').read_text().replace('\\\n', '').split(':', 1)[1])
    record['dependencies'] = [dict(path=str((upstream / p).resolve()), sha256=digest(upstream / p)) for p in dependencies]
    spec = importlib.util.spec_from_file_location('compare', HERE / 'cilium-object-compare.py')
    compare = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(compare)
    record['direct_comparison'] = compare.compare(args.reference, name.with_suffix('.direct.bpf.o'))
    name.with_suffix('.source.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({key: record['direct_comparison'][key]
                      for key in ('all_allocated_sections_equal', 'relocations_equal')}))


if __name__ == '__main__':
    main()
