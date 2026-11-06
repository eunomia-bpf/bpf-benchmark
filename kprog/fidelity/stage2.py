#!/usr/bin/env python3
"""Check the configured helper/map workloads through real bound simulator proofs."""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import sys

import yaml

ROOT = Path(__file__).resolve().parents[2]
from tcb import includes, imports


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


def build(directory, arch):
    directory.mkdir(parents=True, exist_ok=True)
    snapshot = directory / 'snapshot'
    for path in includes(ROOT / f'kprog/{arch}/{arch}_sim_local_bpf.h') | imports(Path(encoder.__file__)):
        target = snapshot / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(path.read_bytes())
    config = ROOT / 'micro/config/micro_stage2.yaml'
    benches = encoder.load_benches(config)
    failed = False
    for bench in benches:
        name = bench.name
        native = ROOT / f'kprog/test/build-{arch}/{name}.native.o'
        proof = directory / f'{name}.proof.o'
        row = dict(name=name, native_object=str(native), stage='native_link')
        rc = command([ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
                      '--input', native, '--symbol', name, '--output', proof, '--mode', 'proof'],
                     directory / f'{name}.link.log')
        if not rc:
            try:
                if arch == 'x86':
                    source = encoder.write_one(bench, ROOT / 'kprog/test', directory, directory)
                else:
                    functions, rodata = encoder.parse_native_linked_program(bench, directory)
                    source = directory/f'{name}.bpf.c'
                    source.write_text(encoder.render_program(name, bench.symbol, functions, bench.kind,
                        prelude=encoder.source_prelude(ROOT/f'kprog/test/{name}.bpf.c'),
                        rodata16=rodata, linked_exit=True))
            except ValueError as error:
                row.update(stage='specialization_rejected', error=str(error))
                rc = 1
            else:
                text = source.read_text().replace(f'#include "../{arch}_sim_local_bpf.h"',
                    f'#include "{snapshot}/kprog/{arch}/{arch}_sim_local_bpf.h"').replace(
                    '#include "../../test/include/native_helpers.h"',
                    f'#include "{ROOT}/kprog/test/include/native_helpers.h"')
                source.write_text(text)
                rc = command(['clang', '-g', '-O2', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096',
                              f'-D__TARGET_ARCH_{arch}', '-I'+str(ROOT/'vendor/libbpf/include/uapi'),
                              '-I'+str(ROOT/'vendor/libbpf/src'), '-I/usr/include/x86_64-linux-gnu',
                              '-c', source, '-o', directory/f'{name}.bpf.o'], directory/f'{name}.compile.log')
                row['stage'] = 'compiler_rejected' if rc else 'compiled'
        row['returncode'] = rc
        (directory/f'{name}.build.json').write_text(json.dumps(row, indent=2)+'\n')
        print(f"{name}: {row['stage']} rc={rc}", flush=True)
        failed |= rc != 0
    return int(failed)


def check(directory, out, arch):
    out.mkdir(parents=True, exist_ok=True)
    config = yaml.safe_load((ROOT/'micro/config/micro_stage2.yaml').read_text())
    failed = False
    for bench in config['benchmarks']:
        name = bench['name']
        row = json.loads((directory/f'{name}.build.json').read_text())
        if row['stage'] == 'compiled':
            plan = {'objects':[dict(program=name[:15], native_object=row['native_object'], symbol=name,
                                    simulator_object=str(directory/f'{name}.bpf.o'),
                                    simulator_program=f'{name}_{arch}_sim_xdp')]}
            manifest = out/f'{name}.manifest.json'
            manifest.write_text(json.dumps(plan, indent=2)+'\n')
            args = [ROOT/f'kprog/fidelity/build-{arch}/bound-probe', ROOT/f'kprog/test/build-{arch}/{name}.bpf.o',
                    manifest, str(bench['expected_result']), str(bench.get('expected_retval',2))]
            row['command'] = [str(a) for a in args]
            row['returncode'] = command(args, out/f'{name}.log')
            row['stage'] = 'passed' if row['returncode'] == 0 else 'failed'
        (out/f'{name}.json').write_text(json.dumps(row, indent=2)+'\n')
        print(f"{name}: {row['stage']}", flush=True)
        failed |= row['stage'] != 'passed'
    return int(failed)


def package(directory):
    config = yaml.safe_load((ROOT/'micro/config/micro_stage2.yaml').read_text())
    files = {'/init':directory.parent/'stage2-init', '/bound-probe':directory.parent/'bound-probe',
             '/module.ko':ROOT/'kprog/tv/build-arm64/bpf_arm64_native_lab.ko',
             '/native-link':ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'}
    for name in ['libc.so.6','ld-linux-aarch64.so.1','libgcc_s.so.1']:
        files['/lib/'+name] = Path('/usr/aarch64-linux-gnu/lib')/name
    for name in ['libelf.so.1','libz.so.1','libzstd.so.1']:
        files['/lib/'+name] = ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'/name
    cases = []
    for bench in config['benchmarks']:
        name = bench['name']
        row = json.loads((directory/f'{name}.build.json').read_text())
        if row['stage'] != 'compiled': continue
        cases.append(f"{name} {bench['expected_result']} {bench.get('expected_retval',2)}\n")
        for suffix in ['bpf.o','native.o']:
            files[f'/proofs/{name}.{suffix}'] = directory/f'{name}.{suffix}' if suffix == 'bpf.o' else Path(row['native_object'])
        files[f'/proofs/{name}.original.bpf.o'] = ROOT/f'kprog/test/build-arm64/{name}.bpf.o'
        plan = {'objects':[dict(program=name[:15],native_object=f'{name}.native.o',symbol=name,
            simulator_object=f'{name}.bpf.o',simulator_program=f'{name}_arm64_sim_xdp')]}
        manifest = directory/f'{name}.manifest.json'
        manifest.write_text(json.dumps(plan,indent=2)+'\n')
        files[f'/proofs/{name}.manifest.json'] = manifest
    (directory/'cases').write_text(''.join(cases))
    files['/cases'] = directory/'cases'
    lines = [f'dir /{name} 0755 0 0' for name in ['dev','proc','sys','lib','proofs']]+['nod /dev/console 0600 0 0 c 5 1']
    for name,path in files.items():
        if not path.is_file(): raise FileNotFoundError(path)
        lines.append(f'file {name} {path.resolve()} 0755 0 0')
    spec = directory/'initramfs.spec'
    spec.write_text('\n'.join(lines)+'\n')
    with (directory/'stage2.cpio').open('wb') as output:
        subprocess.run([ROOT/'vendor/build/arm64/linux/usr/gen_init_cpio',spec],stdout=output,check=True)


def collect(directory,out):
    text = (out/'guest-console.log').read_text().replace('\r','')
    matches = {name:(message,int(rc)) for name,message,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_0-9]+)\n(.*?)LANE_F_CASE_END \1 (\d+)',text,re.S)}
    failed = False
    for bench in yaml.safe_load((ROOT/'micro/config/micro_stage2.yaml').read_text())['benchmarks']:
        name = bench['name']
        row = json.loads((directory/f'{name}.build.json').read_text())
        if row['stage'] == 'compiled':
            if name not in matches:
                row.update(stage='infrastructure_error',error='missing guest case completion')
            else:
                message,rc = matches[name]
                (out/f'{name}.log').write_text(message)
                row.update(stage='passed' if rc == 0 else 'failed',returncode=rc)
        (out/f'{name}.json').write_text(json.dumps(row,indent=2)+'\n')
        print(f"{name}: {row['stage']}",flush=True)
        failed |= row['stage'] != 'passed'
    return int(failed)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('mode', choices=['build','check','package','collect'])
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--out', type=Path)
    parser.add_argument('--arch', choices=['x86','arm64'], default='x86')
    args = parser.parse_args()
    sys.path.insert(0, str(ROOT/f'kprog/{args.arch}/micro-prog'))
    spec = importlib.util.spec_from_file_location('encoder', ROOT/f'kprog/{args.arch}/micro-prog/generate_micro_sim_proofs.py')
    global encoder
    encoder = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = encoder
    spec.loader.exec_module(encoder)
    if args.mode == 'build':
        return build(args.build.resolve(), args.arch)
    if args.mode == 'package':
        package(args.build.resolve())
        return 0
    if args.out is None:
        parser.error('check requires --out')
    return collect(args.build.resolve(), args.out.resolve()) if args.mode == 'collect' else check(args.build.resolve(), args.out.resolve(), args.arch)


if __name__ == '__main__':
    raise SystemExit(main())
