#!/usr/bin/env python3
"""Build unsafe native fixtures through production specialization; record every outcome."""
import argparse
from collections import OrderedDict
import importlib.util
import json
import os
import re
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
X86_MAP = 'mov rsi, QWORD PTR [rdi]; mov rax, QWORD PTR [rdi+8]; lea rdx, [rsi+4]; cmp rdx, rax; ja 1f; mov rdi, QWORD PTR [rip+neg_map@GOTPCREL]; call bpf_map_lookup_elem; '
ARM_MAP = 'ldr x1, [x0]; ldr x2, [x0, #8]; add x3, x1, #4; cmp x3, x2; b.hi 1f; adrp x0, :got:neg_map; ldr x0, [x0, :got_lo12:neg_map]; bl bpf_map_lookup_elem; '
FIXTURES = {
    'x86': {
        'past_data_end_read': 'mov rax, QWORD PTR [rdi+8]; movzx eax, BYTE PTR [rax]; ret',
        'past_data_end_write': 'mov rax, QWORD PTR [rdi+8]; mov BYTE PTR [rax], 1; mov eax, 2; ret',
        'missing_data_end_check': 'mov rax, QWORD PTR [rdi]; movzx eax, BYTE PTR [rax]; ret',
        'map_value_oob': X86_MAP + 'test rax, rax; je 1f; mov rax, QWORD PTR [rax+8]; ret; 1: mov eax, 0; ret',
        'nullable_map_dereference': X86_MAP + 'mov rax, QWORD PTR [rax]; ret; 1: mov eax, 0; ret',
        'invalid_helper_argument': 'mov rdi, 1; mov rsi, 0; call bpf_map_lookup_elem; ret',
        'stack_oob': 'mov rax, QWORD PTR [rsp-1024]; ret',
        'uninitialized_stack': 'mov rax, QWORD PTR [rsp-8]; ret',
        'unbounded_loop': '1: jmp 1b',
        'unbounded_indirect_jump': 'mov rax, QWORD PTR [rdi]; jmp rax',
        'unsupported_instruction': 'ud2; ret',
    },
    'arm64': {
        'past_data_end_read': 'ldr x1, [x0, #8]; ldrb w0, [x1]; ret',
        'past_data_end_write': 'ldr x1, [x0, #8]; mov w2, #1; strb w2, [x1]; mov w0, #2; ret',
        'missing_data_end_check': 'ldr x1, [x0]; ldrb w0, [x1]; ret',
        'map_value_oob': ARM_MAP + 'cbz x0, 1f; ldr x0, [x0, #8]; ret; 1: mov x0, #0; ret',
        'nullable_map_dereference': ARM_MAP + 'ldr x0, [x0]; ret; 1: mov x0, #0; ret',
        'invalid_helper_argument': 'mov x0, #1; mov x1, #0; bl bpf_map_lookup_elem; ret',
        'stack_oob': 'ldr x0, [sp, #1024]; ret',
        'uninitialized_stack': 'ldur x0, [sp, #-8]; ret',
        'unbounded_loop': '1: b 1b',
        'unbounded_indirect_jump': 'ldr x1, [x0]; br x1',
        'unsupported_instruction': 'brk #0; ret',
    },
}


def build(arch, out):
    sys.path.insert(0, str(ROOT / 'kprog' / arch / 'micro-prog'))
    spec = importlib.util.spec_from_file_location('encoder', ROOT / 'kprog' / arch / 'micro-prog/generate_micro_sim_proofs.py')
    enc = importlib.util.module_from_spec(spec)
    sys.modules['encoder'] = enc
    spec.loader.exec_module(enc)
    out.mkdir(parents=True, exist_ok=True)
    rows = []
    for name, assembly in FIXTURES[arch].items():
        source = ('.intel_syntax noprefix\n' if arch == 'x86' else '') + '.text\n.global entry\nentry:\n' + assembly.replace('; ', '\n') + '\n'
        (out / f'{name}.S').write_text(source)
        compiler = 'cc' if arch == 'x86' else 'aarch64-linux-gnu-gcc'
        subprocess.run([compiler, '-c', str(out / f'{name}.S'), '-o', str(out / f'{name}.native.o')], check=True)
        command = ['objdump', '-dr', '-Mintel', '--insn-width=16'] if arch == 'x86' else ['aarch64-linux-gnu-objdump', '-dr']
        disassembly = subprocess.check_output(command + [str(out / f'{name}.native.o')], text=True)
        (out / f'{name}.asm').write_text(disassembly)
        insns = enc.parse_asm_text(disassembly) if arch == 'x86' else enc.parse_flat_instructions(disassembly)
        if not insns:
            raise RuntimeError(f'{name}: no instructions decoded')
        row = dict(name=name, assembly=assembly, stage='generated', message='')
        try:
            if arch == 'x86':
                prelude = 'struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); } neg_map SEC(".maps");' if 'neg_map' in assembly else ''
                proof = enc.render_program(name, insns, source_prelude=prelude)
            else:
                proof = enc.render_program(name, 'entry', OrderedDict(entry=insns), 'xdp')
        except ValueError as error:
            row.update(stage='specialization_rejected', message=str(error))
            rows.append(row)
            continue
        proof = proof.replace(f'#include "../{arch}_sim_local_bpf.h"', f'#include "{ROOT}/kprog/{arch}/{arch}_sim_local_bpf.h"')
        path = out / f'{name}.bpf.c'
        path.write_text(proof)
        command = ['clang', '-g', '-O2', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096', f'-D__TARGET_ARCH_{arch}', '-I'+str(ROOT/'vendor/libbpf/include/uapi'), '-I'+str(ROOT/'vendor/libbpf/src'), '-I/usr/include/x86_64-linux-gnu', '-c', str(path), '-o', str(out/f'{name}.bpf.o')]
        completed = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        (out / f'{name}.compile.log').write_text(completed.stdout)
        if completed.returncode:
            row.update(stage='compiler_rejected', message=completed.stdout)
        rows.append(row)
    (out/'build.json').write_text(json.dumps(dict(arch=arch, cases=rows), indent=2)+'\n')
    print(json.dumps(dict(arch=arch, cases=len(rows), stages={stage:sum(r['stage']==stage for r in rows) for stage in sorted({r['stage'] for r in rows})})))


def outcome(message, returncode):
    if returncode == 0:
        return 'accepted_finding'
    if "failed to find BTF for extern 'arm64_sim_unsupported_opcode'" in message:
        return 'linker_rejected'
    if '-- BEGIN PROG LOAD LOG --' in message and 'processed ' in message and 'bpf_object__load failed' in message:
        return 'verifier_rejected'
    return 'infrastructure_error'


def run(arch, build_dir, out, loader):
    manifest = json.loads((build_dir/'build.json').read_text())
    out.mkdir(parents=True, exist_ok=True)
    manifest['guest_uname'] = list(os.uname())
    accepted = 0
    for row in manifest['cases']:
        if row['stage'] != 'generated':
            continue
        command = [str(loader.resolve()), '--object', str((build_dir/f"{row['name']}.bpf.o").resolve()), '--program', f"{row['name']}_{arch}_sim_xdp", '--load-only']
        completed = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=90)
        (out/f"{row['name']}.log").write_text(completed.stdout)
        row.update(command=command, returncode=completed.returncode, message=completed.stdout)
        row['stage'] = outcome(completed.stdout, completed.returncode)
        accepted += row['stage'] == 'accepted_finding'
    (out/'outcomes.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(json.dumps(dict(arch=arch, accepted_findings=accepted, stages={stage:sum(r['stage']==stage for r in manifest['cases']) for stage in sorted({r['stage'] for r in manifest['cases']})})))
    return 1 if accepted or any(r['stage']=='infrastructure_error' for r in manifest['cases']) else 0


def package(build_dir):
    manifest = json.loads((build_dir/'build.json').read_text())
    names = [r['name'] for r in manifest['cases'] if r['stage'] == 'generated']
    (build_dir/'cases').write_text(''.join(name+'\n' for name in names))
    lines = [f'dir /{name} 0755 0 0' for name in ['dev','proc','sys','lib','proofs']]
    lines += ['nod /dev/console 0600 0 0 c 5 1']
    files = {'/init': build_dir.parent/'negative-init', '/loader': ROOT/'kprog/loader/target/aarch64-unknown-linux-gnu/debug/reversesim-loader', '/cases': build_dir/'cases'}
    for name in ['libc.so.6','ld-linux-aarch64.so.1','libgcc_s.so.1']:
        files['/lib/'+name] = Path('/usr/aarch64-linux-gnu/lib')/name
    for name in ['libelf.so.1','libz.so.1','libzstd.so.1']:
        files['/lib/'+name] = ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'/name
    for name in names:
        files[f'/proofs/{name}.bpf.o'] = build_dir/f'{name}.bpf.o'
    for dest, src in files.items():
        if not src.is_file():
            raise FileNotFoundError(src)
        lines.append(f'file {dest} {src.resolve()} 0755 0 0')
    spec = build_dir/'initramfs.spec'
    spec.write_text('\n'.join(lines)+'\n')
    with (build_dir.parent/'negative.cpio').open('wb') as out:
        subprocess.run([str(ROOT/'vendor/build/arm64/linux/usr/gen_init_cpio'), str(spec)], stdout=out, check=True)


def collect(build_dir, out):
    manifest = json.loads((build_dir/'build.json').read_text())
    log = (out/'guest-console.log').read_text().replace('\r','')
    matches = {name:(message,int(rc)) for name,message,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_]+)\n(.*?)LANE_F_CASE_END \1 (\d+)', log, re.S)}
    for row in manifest['cases']:
        if row['stage'] != 'generated':
            continue
        if row['name'] not in matches:
            row.update(stage='infrastructure_error', message='missing guest case completion')
            continue
        message, rc = matches[row['name']]
        (out/f"{row['name']}.log").write_text(message)
        stage = outcome(message,rc)
        row.update(stage=stage, message=message, returncode=rc)
    (out/'outcomes.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(json.dumps(dict(arch=manifest['arch'], stages={stage:sum(r['stage']==stage for r in manifest['cases']) for stage in sorted({r['stage'] for r in manifest['cases']})})))
    return int('LANE_F_SUITE_COMPLETE' not in log or any(r['stage'] in ['infrastructure_error','accepted_finding'] for r in manifest['cases']))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('mode', choices=['build', 'run', 'package', 'collect'])
    parser.add_argument('--arch', choices=['x86','arm64'], required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--out', type=Path)
    parser.add_argument('--loader', type=Path)
    args = parser.parse_args()
    if args.mode == 'build':
        build(args.arch, args.build)
        return 0
    if args.mode == 'package':
        package(args.build)
        return 0
    if args.out is None:
        parser.error('run/collect requires --out')
    if args.mode == 'collect':
        return collect(args.build,args.out)
    if args.loader is None:
        parser.error('run requires --loader')
    return run(args.arch, args.build, args.out, args.loader)


if __name__ == '__main__':
    sys.exit(main())
