#!/usr/bin/env python3
"""Exercise native compiler thunk identities and same-field relocation on both ISAs."""
import argparse
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('linker', type=Path)
parser.add_argument('output', type=Path)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
args.linker = args.linker.resolve()
os.sched_setaffinity(0, set(range(8, 24)))


def run(command):
    result = subprocess.run([str(x) for x in command], capture_output=True, text=True)
    with (args.output / 'commands.jsonl').open('a') as log:
        log.write(json.dumps(dict(command=[str(x) for x in command],
                                 returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr)) + '\n')
    result.check_returncode()
    return result.stdout


# The additive kernel patch also applies to the current published kernel epoch.
from apply_kernel_patch import apply
kernel = args.output / 'kernel'
target = kernel / 'arch/x86/net/bpf_jit_comp.c'
target.parent.mkdir(parents=True, exist_ok=True)
target.write_bytes((ROOT / 'vendor/linux-framework/arch/x86/net/bpf_jit_comp.c').read_bytes())
patch = (ROOT / 'kprog/tv/native-branch-thunks.patch').read_bytes()
apply(kernel, patch)
first = target.read_bytes()
apply(kernel, patch)
assert target.read_bytes() == first


registers = ['rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi',
             'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15']
rows = []
for selector, reg in enumerate(registers):
    if reg == 'rsp':
        continue
    for transfer in ['call', 'jmp']:
        folder = args.output / (transfer + '-' + reg)
        folder.mkdir(exist_ok=True)
        source = folder / 'native.S'
        source.write_text('.intel_syntax noprefix\n.text\n.global entry\n.type entry,@function\n'
                          'entry:\nendbr64\nlea ' + reg + ',[rip+target]\n' + transfer +
                          ' __x86_indirect_thunk_' + reg + '\njmp __x86_return_thunk\n'
                          '.size entry,.-entry\n.type target,@function\ntarget:\nendbr64\n'
                          'mov eax,2\njmp __x86_return_thunk\n.size target,.-target\n')
        native, proof = folder / 'native.o', folder / 'native.proof.o'
        run(['clang-18', '-c', source, '-o', native])
        run([args.linker, '--input', native, '--symbol', 'entry', '--mode', 'proof',
             '--preserve-entry-abi', '--output', proof])
        blob, relocs = folder / 'native.bin', folder / 'native.relocs'
        run([args.linker, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
             '--output', blob, '--output-relocs', relocs])
        data = blob.read_bytes()
        records = list(struct.iter_unpack('<IIQ', relocs.read_bytes()))
        thunk = [(off, target) for off, kind, target in records if kind == 12]
        assert (next(target & 0xff for off, target in thunk if target != 16)) == selector
        assert any(target == 16 for off, target in thunk)
        for off, target in thunk:
            assert data[off - 1] in {0xe8, 0xe9}
            assert bool(target & 0x100) == (data[off - 1] == 0xe8)
            assert data[off:off + 4] == bytes(4)
        assert data[:4] == bytes.fromhex('f30f1efa')
        rows.append(dict(transfer=transfer, register=reg, thunks=thunk))

# RSP uses the existing external-symbol generation path and its distinct
# kernel transient-stack semantics stays in the universal platform relation.
rsp = args.output / 'rsp.S'
rsp.write_text('.text\n.global entry\n.type entry,@function\nentry:\n'
               'jmp __x86_indirect_thunk_rsp\n.size entry,.-entry\n')
run(['clang-18', '-c', rsp, '-o', rsp.with_suffix('.o')])
rsp_proof = args.output / 'rsp.proof.o'
run([args.linker, '--input', rsp.with_suffix('.o'), '--symbol', 'entry',
     '--mode', 'proof', '--preserve-entry-abi', '--output', rsp_proof])
unsupported = subprocess.run([str(args.linker), '--input', str(rsp_proof),
    '--symbol', 'entry', '--mode', 'kernel', '--output', str(rsp.with_suffix('.bin'))],
    capture_output=True, text=True)
(args.output / 'rsp-generation.txt').write_text(unsupported.stdout + unsupported.stderr)
assert unsupported.returncode and '__x86_indirect_thunk_rsp' in unsupported.stderr


# A thunked tail helper declares the complete JIT callee-save frame.
tail_native, tail_proof = args.output / 'tail.native.o', args.output / 'tail.proof.o'
run(['clang-18', '-c', ROOT / 'kprog/test/tail_call_frame/native.S', '-o', tail_native])
run([args.linker, '--input', tail_native, '--symbol', 'entry', '--mode', 'proof',
     '--preserve-entry-abi', '--output', tail_proof])
with tail_proof.open('rb') as stream:
    abi = ELFFile(stream).get_section_by_name('.native_link_abi').data().decode()
assert 'callee_saved_mask\t15\n' in abi
asm = run(['objdump', '-dr', '-Mintel', tail_native])
assert re.search(r'\b(?:call|jmp)\s+(?:[er][a-z0-9]+|QWORD PTR)', asm) is None


source = args.output / 'compiled.c'
source.write_text('__attribute__((noinline)) static unsigned long target(void *x) '
                  '{ __asm__ volatile(""); return 2; }\n'
                  'unsigned long entry(void *x) { unsigned long (*f)(void *) = target; '
                  '__asm__("" : "+r"(f)); return f(x); }\n')
compiled = {}
for arch, flags, objdump in [
    ('x86', ['-mno-red-zone', '-mretpoline-external-thunk',
             '-mfunction-return=thunk-extern', '-fcf-protection=branch'], 'objdump'),
    ('arm64', ['--target=aarch64-linux-gnu', '-mbranch-protection=bti', '-mcmodel=tiny'],
     'aarch64-linux-gnu-objdump'),
]:
    native = args.output / (arch + '.native.o')
    run(['clang-18', '-O2', '-fPIC', '-mgeneral-regs-only', '-fno-optimize-sibling-calls',
         *flags, '-c', source, '-o', native])
    asm = run([objdump, '-dr', *(['-Mintel'] if arch == 'x86' else []), native])
    (args.output / (arch + '.asm')).write_text(asm)
    if arch == 'x86':
        assert '__x86_indirect_thunk_' in asm and '__x86_return_thunk' in asm
        assert 'endbr64' in asm
        assert re.search(r'\b(?:call|jmp)\s+(?:[er][a-z0-9]+|QWORD PTR)', asm) is None
        assert re.search(r'\bret\b', asm) is None
    else:
        assert 'bti' in asm and 'blr' in asm
    sys.path.insert(0, str(ROOT / 'kprog' / arch))
    module = importlib.util.spec_from_file_location('branch_' + arch,
        ROOT / 'kprog' / arch / 'trusted_specializer.py')
    adapter = importlib.util.module_from_spec(module)
    module.loader.exec_module(adapter)
    result = adapter.specialize(native.read_bytes(), 'entry',
        dict(prog_type=6, section='xdp', maps=[]),
        args.output / (arch + '-specialize'), args.linker)
    compiled[arch] = result
summary = dict(register_transfer_cases=rows, compiled=compiled)
(args.output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
print('native branch hardening: 30 register-transfer layouts and both compiled B adapters PASS')
