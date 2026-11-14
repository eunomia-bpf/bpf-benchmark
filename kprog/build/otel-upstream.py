#!/usr/bin/env python3
"""Retain original OTel frontend IR, with its upstream flags and dependencies."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import importlib.util
import json
from pathlib import Path
import shlex
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def compile_unit(unit, output):
    upstream = ROOT / 'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf'
    source = (upstream / (unit + '.ebpf.c')).resolve(strict=True)
    if source.parent != upstream:
        raise ValueError('source must be in the canonical upstream support/ebpf directory')
    prefix = output / unit
    # Original OTel uses an x86 C frontend, LLVM linking, then llc -march=bpf.
    # DEPS= prevents implicit dependency-file rebuilds while printing FLAGS.
    flags_command = ['make', '-s', '--no-print-directory', '-C', str(upstream),
                     '-f', str(HERE / 'otel-flags.mk'), 'DEPS=', 'TARGET_ARCH=amd64',
                     'OTEL_SOURCE=' + source.name, 'flags']
    result = subprocess.run(flags_command, capture_output=True, text=True)
    prefix.with_suffix('.flags.stdout').write_text(result.stdout)
    prefix.with_suffix('.flags.stderr').write_text(result.stderr)
    result.check_returncode()
    flags = shlex.split(result.stdout)
    command = ['clang-18', *flags, '-MMD', '-MP', '-MF', str(prefix.with_suffix('.d')),
               '-o', str(prefix.with_suffix('.bc'))]
    record = dict(unit=unit, source=str(source), source_sha256=digest(source),
                  makefile_sha256=digest(upstream / 'Makefile'), flags_command=flags_command,
                  flags=flags, frontend_command=command, cwd=str(upstream),
                  scope='Unchanged upstream frontend IR only; final linked BPF reference comparison and native translation are separate steps.')
    result = subprocess.run(command, cwd=upstream, capture_output=True, text=True)
    prefix.with_suffix('.stdout').write_text(result.stdout)
    prefix.with_suffix('.stderr').write_text(result.stderr)
    record['returncode'] = result.returncode
    prefix.with_suffix('.json').write_text(json.dumps(record, indent=2) + '\n')
    result.check_returncode()
    # -MP adds empty dependency target rules after the first logical line.
    rule = prefix.with_suffix('.d').read_text().replace('\\\n', '').splitlines()[0]
    dependencies = shlex.split(rule.split(':', 1)[1])
    record['dependencies'] = [dict(path=str((upstream / path).resolve()),
                                   sha256=digest(upstream / path)) for path in dependencies]
    prefix.with_suffix('.json').write_text(json.dumps(record, indent=2) + '\n')
    return record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--unit')
    mode.add_argument('--all', action='store_true')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--bpf-reference', type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    if args.unit:
        compile_unit(args.unit, args.output)
        return
    upstream = ROOT / 'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf'
    units = sorted(path.name.removesuffix('.ebpf.c') for path in upstream.glob('*.ebpf.c'))
    report = dict(completed=[], failures=[], reference=str(args.bpf_reference))
    report_path = args.output / 'build-report.json'
    with ThreadPoolExecutor(max_workers=4) as pool:
        pending = {pool.submit(compile_unit, unit, args.output): unit for unit in units}
        for future in as_completed(pending):
            unit = pending[future]
            try:
                report['completed'].append(future.result())
                print(json.dumps(dict(unit=unit, returncode=0)), flush=True)
            except Exception as error:
                report['failures'].append(dict(unit=unit, error=str(error)))
                print(json.dumps(dict(unit=unit, error=str(error))), flush=True)
            report_path.write_text(json.dumps(report, indent=2) + '\n')
    if report['failures']:
        raise SystemExit(1)
    if args.bpf_reference:
        linked = args.output / 'tracer.linked.bc'
        bpf = args.output / 'tracer.bpf.o'
        commands = [
            ['llvm-link-18', *[str(args.output / (unit + '.bc')) for unit in units], '-o', str(linked)],
            ['llc-18', '-march=bpf', '-mcpu=v2', '-filetype=obj', str(linked), '-o', str(bpf)],
            ['llvm-strip-18', '--strip-debug', '--enable-deterministic-archives', str(bpf)],
        ]
        report['backend_commands'] = []
        for index, command in enumerate(commands):
            result = subprocess.run(command, capture_output=True, text=True)
            (args.output / ('backend-%d.stdout' % index)).write_text(result.stdout)
            (args.output / ('backend-%d.stderr' % index)).write_text(result.stderr)
            report['backend_commands'].append(dict(argv=command, returncode=result.returncode))
            report_path.write_text(json.dumps(report, indent=2) + '\n')
            result.check_returncode()
        spec = importlib.util.spec_from_file_location('compare', HERE / 'cilium-object-compare.py')
        compare = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(compare)
        report['bpf_comparison'] = compare.compare(args.bpf_reference, bpf)
        report_path.write_text(json.dumps(report, indent=2) + '\n')


if __name__ == '__main__':
    main()
