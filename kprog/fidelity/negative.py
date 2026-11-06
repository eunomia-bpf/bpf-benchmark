#!/usr/bin/env python3
"""Build unsafe native fixtures through production specialization; record every outcome."""
import argparse
from collections import OrderedDict
import importlib.util
import json
import os
import re
import shutil
from pathlib import Path
import subprocess
import sys
from tcb import includes, imports

ROOT = Path(__file__).resolve().parents[2]
X86_MAP = 'mov rsi, QWORD PTR [rdi]; mov rax, QWORD PTR [rdi+8]; lea rdx, [rsi+4]; cmp rdx, rax; ja 1f; mov rdi, QWORD PTR [rip+neg_map@GOTPCREL]; call bpf_map_lookup_elem; '
ARM_MAP = 'ldr x1, [x0]; ldr x2, [x0, #8]; add x3, x1, #4; cmp x3, x2; b.hi 1f; str x30, [sp, #-16]!; adrp x0, :got:neg_map; ldr x0, [x0, :got_lo12:neg_map]; bl bpf_map_lookup_elem; ldr x30, [sp], #16; '
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
        'unsupported_instruction': 'ud2; mov eax, 2; ret',
        'immediate_push_branch': 'mov eax, 2; push 1; pop rcx; test rcx, rcx; jz 1f; xor edx, edx; mov eax, DWORD PTR [rdx]; 1: ret',
        'entry_return_slot_overwrite': 'mov QWORD PTR [rsp], 0; mov eax, 2; ret',
        'stack_base_flags': 'mov eax, 2; sub rsp, 8; add rsp, 8; jz 1f; xor ecx, ecx; mov eax, DWORD PTR [rcx]; 1: ret',
        'undefined_entry_register': 'test rax, rax; je 1f; mov rax, QWORD PTR [rdi+8]; movzx eax, BYTE PTR [rax]; ret; 1: mov eax, 2; ret',
        'undefined_entry_flags': 'jnc 1f; mov rax, QWORD PTR [rdi+8]; movzx eax, BYTE PTR [rax]; ret; 1: mov eax, 2; ret',
        'helper_clobbered_register': 'push rbx; mov rbx, rdi; xor esi, esi; call bpf_get_current_uid_gid; test rsi, rsi; je 1f; mov rax, QWORD PTR [rbx+8]; movzx eax, BYTE PTR [rax]; jmp 2f; 1: mov eax, 2; 2: pop rbx; ret',
    },
    'arm64': {
        'past_data_end_read': 'ldr x1, [x0, #8]; ldrb w0, [x1]; ret',
        'past_data_end_write': 'ldr x1, [x0, #8]; mov w2, #1; strb w2, [x1]; mov w0, #2; ret',
        'missing_data_end_check': 'ldr x1, [x0]; ldrb w0, [x1]; ret',
        'map_value_oob': ARM_MAP + 'cbz x0, 1f; ldr x0, [x0, #8]; ret; 1: mov x0, #0; ret',
        'nullable_map_dereference': ARM_MAP + 'ldr x0, [x0]; ret; 1: mov x0, #0; ret',
        'invalid_helper_argument': 'str x30, [sp, #-16]!; mov x0, #1; mov x1, #0; bl bpf_map_lookup_elem; ldr x30, [sp], #16; ret',
        'stack_oob': 'ldr x0, [sp, #1024]; ret',
        'uninitialized_stack': 'ldur x0, [sp, #-8]; ret',
        'unbounded_loop': '1: b 1b',
        'unbounded_indirect_jump': 'ldr x1, [x0]; br x1',
        'unsupported_instruction': 'brk #0; ret',
        'misaligned_sp': 'sub sp, sp, #16; mov w1, #0x2222; str x1, [sp]; add sp, sp, #1; ldrb w0, [sp]; sub sp, sp, #1; add sp, sp, #16; ret',
        'overlapping_load_pair': 'sub sp, sp, #16; mov x1, #2; stp x1, x1, [sp]; ldp x1, x1, [sp]; add sp, sp, #16; mov w0, w1; ret',
        'writeback_load_overlap': 'sub sp, sp, #16; mov x2, #2; stp x2, x2, [sp]; mov x1, sp; ldr x1, [x1], #8; add sp, sp, #16; mov w0, #2; ret',
        'writeback_store_overlap': 'sub sp, sp, #16; mov x2, #2; stp x2, x2, [sp]; mov x1, sp; str x1, [x1], #8; add sp, sp, #16; mov w0, #2; ret',
        'unpaired_stxr_failure': 'sub sp, sp, #16; mov x1, #2; str x1, [sp]; mov x2, sp; stxr w0, x1, [x2]; cbz w0, 1f; mov x3, #0; ldr w0, [x3]; 1: add sp, sp, #16; mov w0, #2; ret',
        'unpaired_stlxr_failure': 'sub sp, sp, #16; mov x1, #2; str x1, [sp]; mov x2, sp; stlxr w0, x1, [x2]; cbz w0, 1f; mov x3, #0; ldr w0, [x3]; 1: add sp, sp, #16; mov w0, #2; ret',
        'paired_stxr_failure': 'sub sp, sp, #16; mov x1, #2; str x1, [sp]; mov x2, sp; ldxr x1, [x2]; stxr w0, x1, [x2]; cbz w0, 1f; mov x3, #0; ldr w0, [x3]; 1: add sp, sp, #16; mov w0, #2; ret',
        'paired_stlxr_failure': 'sub sp, sp, #16; mov x1, #2; str x1, [sp]; mov x2, sp; ldaxr x1, [x2]; stlxr w0, x1, [x2]; cbz w0, 1f; mov x3, #0; ldr w0, [x3]; 1: add sp, sp, #16; mov w0, #2; ret',
        'entry_return_address_flags': 'mov w0, #2; cmp x30, #0; b.eq 1f; mov x1, #0; ldr w0, [x1]; 1: ret',
        'return_register_overwrite': 'mov x30, #0; mov w0, #2; ret',
        'stack_base_flags': 'mov w0, #2; sub sp, sp, #16; add sp, sp, #16; cmp sp, #0; b.eq 1f; mov x1, #0; ldr w0, [x1]; 1: ret',
        'undefined_entry_register': 'cbz x1, 1f; ldr x1, [x0, #8]; ldrb w0, [x1]; ret; 1: mov w0, #2; ret',
        'undefined_entry_flags': 'b.cc 1f; ldr x1, [x0, #8]; ldrb w0, [x1]; ret; 1: mov w0, #2; ret',
        'helper_clobbered_register': 'stp x19, x30, [sp, #-16]!; mov x19, x0; mov x1, #0; bl bpf_get_current_uid_gid; cbz x1, 1f; ldr x1, [x19, #8]; ldrb w0, [x1]; b 2f; 1: mov w0, #2; 2: ldp x19, x30, [sp], #16; ret',
    },
}


def build(arch, out):
    sys.path.insert(0, str(ROOT / 'kprog' / arch / 'micro-prog'))
    spec = importlib.util.spec_from_file_location('encoder', ROOT / 'kprog' / arch / 'micro-prog/generate_micro_sim_proofs.py')
    enc = importlib.util.module_from_spec(spec)
    sys.modules['encoder'] = enc
    spec.loader.exec_module(enc)
    out.mkdir(parents=True, exist_ok=True)
    snapshot = out.resolve()/'snapshot'
    for path in includes(ROOT/f'kprog/{arch}/{arch}_sim_local_bpf.h') | imports(Path(enc.__file__)):
        target = snapshot/path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    rows = []
    for name, assembly in FIXTURES[arch].items():
        source = ('.intel_syntax noprefix\n' if arch == 'x86' else '') + '.text\n.global entry\n.type entry, %function\nentry:\n' + assembly.replace('; ', '\n') + '\n.size entry, .-entry\n'
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
                if 'neg_map' in assembly:
                    # Pair the generated declaration with the actual original
                    # map identity, as the x86 prelude already does.
                    if proof.count('} neg_map_0 SEC(".maps");') != 1:
                        raise RuntimeError('expected original neg_map declaration')
                    proof = proof.replace('neg_map_0', 'neg_map')
        except ValueError as error:
            row.update(stage='specialization_rejected', message=str(error))
            rows.append(row)
            continue
        proof = proof.replace(f'#include "../{arch}_sim_local_bpf.h"', f'#include "{snapshot}/kprog/{arch}/{arch}_sim_local_bpf.h"')
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


def run_bound(arch, build_dir, out, probe, companion):
    manifest=json.loads((build_dir/'build.json').read_text())
    out.mkdir(parents=True,exist_ok=True)
    manifest['guest_uname']=list(os.uname())
    for row in manifest['cases']:
        if row['stage']!='generated':continue
        plan={'objects':[dict(program='neg_source',native_object=str((build_dir/f"{row['name']}.native.o").resolve()),symbol='entry',simulator_object=str((build_dir/f"{row['name']}.bpf.o").resolve()),simulator_program=f"{row['name']}_{arch}_sim_xdp")]}
        plan_path=out/f"{row['name']}.manifest.json"
        plan_path.write_text(json.dumps(plan,indent=2)+'\n')
        command=[str(probe.resolve()),str(companion.resolve()),str(plan_path.resolve())]
        completed=subprocess.run(command,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,timeout=120)
        message=completed.stdout
        (out/f"{row['name']}.log").write_text(message)
        stage=bound_outcome(message,completed.returncode)
        row.update(stage=stage,command=command,returncode=completed.returncode,message=message)
    (out/'outcomes.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps(dict(arch=arch,path='bound',stages={stage:sum(row['stage']==stage for row in manifest['cases']) for stage in sorted({row['stage'] for row in manifest['cases']})})))
    return int(any(row['stage'] in ['accepted_finding','infrastructure_error'] for row in manifest['cases']))


def bound_outcome(message, returncode):
    if returncode == 0:
        return 'accepted_finding'
    if 'BPF_PROG_LOAD native_lab stub:' in message and 'processed ' in message:
        return 'verifier_rejected'
    if 'native_kernel bound proof contains no BPF exit' in message:
        return 'loader_rejected'
    if "failed to find BTF for extern 'arm64_sim_unsupported_opcode'" in message:
        return 'linker_rejected'
    return 'infrastructure_error'


def package(build_dir, bound=False):
    manifest = json.loads((build_dir/'build.json').read_text())
    names = [r['name'] for r in manifest['cases'] if r['stage'] == 'generated']
    (build_dir/'cases').write_text(''.join(name+'\n' for name in names))
    lines = [f'dir /{name} 0755 0 0' for name in ['dev','proc','sys','lib','proofs']]
    lines += ['nod /dev/console 0600 0 0 c 5 1']
    files = {'/init': build_dir.parent/('negative-bound-init' if bound else 'negative-init'), '/cases': build_dir/'cases'}
    if bound:
        files.update({'/bound-probe':build_dir.parent/'bound-probe',
                      '/module.ko':ROOT/'kprog/tv/build-arm64/bpf_arm64_native_lab.ko',
                      '/companion.bpf.o':build_dir.parent/'negative-companion.bpf.o',
                      '/native-link':ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'})
    else:
        files['/loader']=ROOT/'kprog/loader/target/aarch64-unknown-linux-gnu/debug/reversesim-loader'
    for name in ['libc.so.6','ld-linux-aarch64.so.1','libgcc_s.so.1']:
        files['/lib/'+name] = Path('/usr/aarch64-linux-gnu/lib')/name
    for name in ['libelf.so.1','libz.so.1','libzstd.so.1']:
        files['/lib/'+name] = ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'/name
    for name in names:
        files[f'/proofs/{name}.bpf.o'] = build_dir/f'{name}.bpf.o'
        if bound:
            files[f'/proofs/{name}.native.o']=build_dir/f'{name}.native.o'
            plan={'objects':[dict(program='neg_source',native_object=f'{name}.native.o',symbol='entry',simulator_object=f'{name}.bpf.o',simulator_program=f'{name}_arm64_sim_xdp')]}
            manifest=build_dir/f'{name}.manifest.json'
            manifest.write_text(json.dumps(plan,indent=2)+'\n')
            files[f'/proofs/{name}.manifest.json']=manifest
    for dest, src in files.items():
        if not src.is_file():
            raise FileNotFoundError(src)
        lines.append(f'file {dest} {src.resolve()} 0755 0 0')
    spec = build_dir/'initramfs.spec'
    spec.write_text('\n'.join(lines)+'\n')
    with (build_dir.parent/('negative-bound.cpio' if bound else 'negative.cpio')).open('wb') as out:
        subprocess.run([str(ROOT/'vendor/build/arm64/linux/usr/gen_init_cpio'), str(spec)], stdout=out, check=True)


def collect(build_dir, out, bound=False):
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
        stage = bound_outcome(message,rc) if bound else outcome(message,rc)
        row.update(stage=stage, message=message, returncode=rc)
    (out/'outcomes.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(json.dumps(dict(arch=manifest['arch'], stages={stage:sum(r['stage']==stage for r in manifest['cases']) for stage in sorted({r['stage'] for r in manifest['cases']})})))
    return int('LANE_F_SUITE_COMPLETE' not in log or any(r['stage'] in ['infrastructure_error','accepted_finding'] for r in manifest['cases']))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('mode', choices=['build', 'run', 'package', 'collect', 'bound', 'package-bound', 'collect-bound'])
    parser.add_argument('--arch', choices=['x86','arm64'], required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--out', type=Path)
    parser.add_argument('--loader', type=Path)
    parser.add_argument('--probe',type=Path)
    parser.add_argument('--companion',type=Path)
    args = parser.parse_args()
    if args.mode == 'build':
        build(args.arch, args.build)
        return 0
    if args.mode in ['package', 'package-bound']:
        package(args.build,bound=args.mode=='package-bound')
        return 0
    if args.out is None:
        parser.error('run/collect requires --out')
    if args.mode in ['collect', 'collect-bound']:
        return collect(args.build,args.out,bound=args.mode=='collect-bound')
    if args.mode == 'bound':
        if args.probe is None or args.companion is None:parser.error('bound requires --probe and --companion')
        return run_bound(args.arch,args.build,args.out,args.probe,args.companion)
    if args.loader is None:
        parser.error('run requires --loader')
    return run(args.arch, args.build, args.out, args.loader)


if __name__ == '__main__':
    sys.exit(main())
