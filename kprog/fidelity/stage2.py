#!/usr/bin/env python3
"""Check the configured helper/map workloads through real bound simulator proofs."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

import yaml

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as encoder
from tcb import includes


def command(args, log):
    try:
        completed = subprocess.run([str(a) for a in args], text=True, stdout=subprocess.PIPE,
                                   stderr=subprocess.STDOUT, timeout=300)
    except subprocess.TimeoutExpired as error:
        output = error.stdout or b''
        log.write_text((output.decode(errors='replace') if isinstance(output, bytes) else output)
                       +'\ncommand exceeded 300 seconds\n')
        return 124
    log.write_text(completed.stdout)
    return completed.returncode


def build(directory):
    directory.mkdir(parents=True, exist_ok=True)
    snapshot = directory / 'snapshot'
    for path in includes(ROOT / 'kprog/x86/x86_sim_local_bpf.h'):
        target = snapshot / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(path.read_bytes())
    config = ROOT / 'micro/config/micro_stage2.yaml'
    benches = encoder.load_benches(config)
    failed = False
    for bench in benches:
        name = bench.name
        native = ROOT / f'kprog/test/build-x86/{name}.native.o'
        proof = directory / f'{name}.proof.o'
        row = dict(name=name, native_object=str(native), stage='native_link')
        rc = command([ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
                      '--input', native, '--symbol', name, '--output', proof, '--mode', 'proof'],
                     directory / f'{name}.link.log')
        if not rc:
            try:
                source = encoder.write_one(bench, ROOT / 'kprog/test', directory, directory)
            except ValueError as error:
                row.update(stage='specialization_rejected', error=str(error))
                rc = 1
            else:
                text = source.read_text().replace('#include "../x86_sim_local_bpf.h"',
                    f'#include "{snapshot}/kprog/x86/x86_sim_local_bpf.h"').replace(
                    '#include "../../test/include/native_helpers.h"',
                    f'#include "{ROOT}/kprog/test/include/native_helpers.h"')
                source.write_text(text)
                rc = command(['clang', '-g', '-O2', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096',
                              '-D__TARGET_ARCH_x86', '-I'+str(ROOT/'vendor/libbpf/include/uapi'),
                              '-I'+str(ROOT/'vendor/libbpf/src'), '-I/usr/include/x86_64-linux-gnu',
                              '-c', source, '-o', directory/f'{name}.bpf.o'], directory/f'{name}.compile.log')
                row['stage'] = 'compiler_rejected' if rc else 'compiled'
        row['returncode'] = rc
        (directory/f'{name}.build.json').write_text(json.dumps(row, indent=2)+'\n')
        print(f"{name}: {row['stage']} rc={rc}", flush=True)
        failed |= rc != 0
    return int(failed)


def check(directory, out):
    out.mkdir(parents=True, exist_ok=True)
    config = yaml.safe_load((ROOT/'micro/config/micro_stage2.yaml').read_text())
    failed = False
    for bench in config['benchmarks']:
        name = bench['name']
        row = json.loads((directory/f'{name}.build.json').read_text())
        if row['stage'] == 'compiled':
            plan = {'objects':[dict(program=name[:15], native_object=row['native_object'], symbol=name,
                                    simulator_object=str(directory/f'{name}.bpf.o'),
                                    simulator_program=f'{name}_x86_sim_xdp')]}
            manifest = out/f'{name}.manifest.json'
            manifest.write_text(json.dumps(plan, indent=2)+'\n')
            args = [ROOT/'kprog/fidelity/build-x86/bound-probe', ROOT/f'kprog/test/build-x86/{name}.bpf.o',
                    manifest, str(bench['expected_result']), str(bench.get('expected_retval',2))]
            row['command'] = [str(a) for a in args]
            row['returncode'] = command(args, out/f'{name}.log')
            row['stage'] = 'passed' if row['returncode'] == 0 else 'failed'
        (out/f'{name}.json').write_text(json.dumps(row, indent=2)+'\n')
        print(f"{name}: {row['stage']}", flush=True)
        failed |= row['stage'] != 'passed'
    return int(failed)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('mode', choices=['build','check'])
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--out', type=Path)
    args = parser.parse_args()
    if args.mode == 'build':
        return build(args.build.resolve())
    if args.out is None:
        parser.error('check requires --out')
    return check(args.build.resolve(), args.out.resolve())


if __name__ == '__main__':
    raise SystemExit(main())
