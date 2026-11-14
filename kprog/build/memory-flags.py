#!/usr/bin/env python3
"""Compare original native compilation with compiler-only memory thresholds.

Read application sources in place. No injected replacement headers, source
rewrites, default artifact changes, kernel/base/image builds, or workload runs.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import importlib.util
import json
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def inspect(path):
    with path.open('rb') as source:
        elf = ELFFile(source)
        table = elf.get_section_by_name('.symtab')
        undefined = sorted(s.name for s in table.iter_symbols() if s.name and s['st_shndx'] == 'SHN_UNDEF')
        code = {s.name: s.data() for s in elf.iter_sections() if s['sh_flags'] & 4}
    return undefined, code


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--app', choices=['tracee', 'tetragon', 'otel', 'bcc'], required=True)
    parser.add_argument('--only', required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--logs', type=Path, required=True)
    args = parser.parse_args()
    spec = importlib.util.spec_from_file_location('native_units', ROOT / 'vendor/bpf/native_specialize_objects.py')
    native = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(native)
    units = {name: (source, flags) for name, source, flags in native.units_for_app(args.app)}
    source, flags = units[args.only]
    args.output.mkdir(parents=True, exist_ok=True)
    args.logs.mkdir(parents=True, exist_ok=True)
    variants = dict(plain=[], thresholds=['-mllvm', '-max-store-memset=4096',
                                         '-mllvm', '-max-store-memcpy=4096'])

    def build(item):
        name, extra = item
        obj = args.output / f'{args.only}.{name}.o'
        command = ['prlimit', '--as=8589934592', '--', 'clang-18', *native.NATIVE_CFLAGS,
                   *flags, *extra, str(source), '-o', str(obj)]
        with (args.logs / f'{name}.log').open('w') as log:
            print(subprocess.list2cmdline(command), file=log, flush=True)
            subprocess.run(command, check=True, stdout=log, stderr=subprocess.STDOUT)
        undefined, code = inspect(obj)
        return name, dict(command=command, object=str(obj), undefined=undefined,
                          memory_calls=[s for s in undefined if s in ('memset', 'memcpy', 'memmove')],
                          code_section_bytes={k: len(v) for k, v in code.items()})

    with ThreadPoolExecutor(max_workers=2) as workers:
        results = dict(workers.map(build, variants.items()))
    shipped = ROOT / f'vendor/build/native-bpf/x86/stage/{args.app}/{args.only}.native.o'
    results['plain']['code_equal_shipped'] = inspect(Path(results['plain']['object']))[1] == inspect(shipped)[1]
    report = dict(app=args.app, unit=args.only, source=str(source), variants=results,
                  limits=['Compiler-only feasibility, no runtime correctness or performance claim.',
                          'Variable-size operations may still require linker-owned routines.'])
    (args.logs / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
