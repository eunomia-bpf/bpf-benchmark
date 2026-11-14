#!/usr/bin/env python3
"""Translate original OTel linked frontend IR through explicit native lowerings."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['original', 'output', 'retarget', 'public-layout', 'physical-layout',
                 'perf-context', 'perf-layout']:
        parser.add_argument('--' + name, type=Path, required=True)
    parser.add_argument("--combined-codegen", action="store_true",
                        help="Target host CPU, force CMOV conversion, allow sibling calls; retain jump-table restriction")
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    original = args.original.resolve(strict=True)
    native = args.output / 'tracer.native.bc'
    inlined = args.output / 'tracer.inlined.bc'
    physical = args.output / 'tracer.physical.bc'
    obj = args.output / 'tracer.native.o'
    codegen = physical
    if args.combined_codegen:
        codegen = args.output / 'tracer.codegen.bc'
    commands = [
        [str(args.retarget), str(original), '--public-layout', str(args.public_layout),
         '--physical-layout', str(args.physical_layout), '--native-codegen',
         '--helper-names', str(args.output / 'helper-names.json'), '-o', str(native)],
        ['opt-18', '-passes=always-inline', str(native), '-o', str(inlined)],
        [str(args.perf_context), str(inlined), '--layout', str(args.perf_layout),
         '-o', str(physical)],
        ['clang-18', '-target', 'x86_64-linux-gnu', '-O3', '-g', '-fPIC',
         *([] if args.combined_codegen else ['-fno-optimize-sibling-calls']),
         '-fomit-frame-pointer', '-mno-red-zone', '-mgeneral-regs-only', '-fno-stack-protector',
         *(['-march=native', '-mllvm', '-x86-cmov-converter-force-all=true',
            '-foptimize-sibling-calls', '-fno-jump-tables'] if args.combined_codegen else
           ['-fno-jump-tables']),
         '-c', str(codegen), '-o', str(obj)],
        ['llvm-objdump-18', '-dr', str(obj)],
    ]
    inputs = [original, args.retarget, args.public_layout, args.physical_layout,
              args.perf_context, args.perf_layout, args.output / 'helper-names.json']
    report = dict(combined_codegen=args.combined_codegen, inputs=[dict(path=str(p), sha256=hashlib.sha256(p.read_bytes()).hexdigest())
                          for p in inputs], commands=[],
                  scope='Original upstream linked IR, explicit helper/global native retargeting and physical PERF_EVENT context. No source overlay, application installation or equal-work claim.')
    for index, command in enumerate(commands):
        if index == 3 and args.combined_codegen:
            # Earlier BPF/frontend attributes override driver flags; relax only
            # sibling-call restriction, retaining all semantic IR. Jump tables
            # stay disabled: OTel emits anonymous .data.rel.ro tables of live map
            # pointers, which the current linker cannot bind as DATASEC resources.
            # The rejected all-flags object and exact failure are retained in raw.
            ir = subprocess.check_output(['llvm-dis-18', str(physical), '-o', '-'], text=True)
            relaxed = {a: ir.count(a) for a in
                       ['"disable-tail-calls"="true"']}
            for attribute in relaxed:
                ir = chr(10).join(line.replace(attribute, attribute.replace('true', 'false'))
                                  if line.startswith('attributes #') else line
                                  for line in ir.splitlines()) + chr(10)
            (args.output/'tracer.codegen.ll').write_text(ir)
            subprocess.run(['llvm-as-18', str(args.output/'tracer.codegen.ll'),
                            '-o', str(codegen)], check=True)
            report['relaxed_codegen_attributes'] = relaxed
            report['codegen_input_sha256'] = hashlib.sha256(codegen.read_bytes()).hexdigest()
        result = subprocess.run(command, capture_output=True)
        (args.output / ('step-%d.stdout' % index)).write_bytes(result.stdout)
        (args.output / ('step-%d.stderr' % index)).write_bytes(result.stderr)
        report['commands'].append(dict(argv=command, returncode=result.returncode))
        (args.output / 'native-report.json').write_text(json.dumps(report, indent=2) + '\n')
        print(json.dumps(dict(step=index, returncode=result.returncode)), flush=True)
        result.check_returncode()


if __name__ == '__main__':
    main()
