"""Catch nontermination while following stack pointers through native copy loops."""
import argparse
import ctypes
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
import trusted_specializer as worker


def check(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()

    assembly = args.build/'copy.S'
    text = '''.intel_syntax noprefix
.text
.global loop_copy
.type loop_copy,@function
loop_copy:
sub rsp,64
mov rsi,rdi
mov rdi,rsp
mov ecx,32
call copy_bytes
mov eax,DWORD PTR [rsp]
add rsp,64
ret
.size loop_copy,.-loop_copy
.type copy_bytes,@function
copy_bytes:
mov al,BYTE PTR [rsi]
mov BYTE PTR [rdi],al
inc rdi
inc rsi
dec ecx
jne copy_bytes
ret
.size copy_bytes,.-copy_bytes
.section .note.GNU-stack,"",@progbits
'''
    if args.step == 'add':
        text = text.replace('inc rdi', 'add rdi,1').replace('inc rsi', 'add rsi,1')
    assembly.write_text(text)
    run(['clang-18', '-c', assembly, '-o', args.build/'copy.native.o'])
    run([args.linker, '--input', args.build/'copy.native.o', '--symbol', 'loop_copy',
         '--mode', 'proof', '--preserve-entry-abi', '--output', args.build/'copy.proof.o'])
    gen = worker.gen
    body, subs, end, data = gen.parse_proof_object_program('copy', args.build)
    returns = set()
    extent = gen.check_definedness([*body, *(i for b in subs.values() for i in b)], {},
                                  end, gen, return_sites=returns)
    if extent != 72 or len(returns) != 1:
        raise ValueError(f'Lost native frame or CALL/RET continuation: {extent}/{returns}')
    source = gen.render_program('copy', body, subs, kind='raw',
        program_section='kprobe/copy', exit_addr=end, rodata16=data,
        source_prelude='''#if !defined(__bpf__) && !defined(__BPF__)
extern void copy_unresolved(void);
#define __x86_sim_unresolved_indirect_target copy_unresolved
#endif''')
    generated = args.build/'copy.bpf.c'
    generated.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
        '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
    adapter = args.build/'input.c'
    adapter.write_text('''#include <stdlib.h>
void copy_unresolved(void) { abort(); }
unsigned long native_lab_entry_input(unsigned kind) {
    if (kind == 1 || kind == 6) return 0;
    abort();
}
''')
    run(['clang-18', '-shared', '-fPIC', '-O3', assembly, '-o', args.build/'native.so'])
    run(['clang-18', '-shared', '-fPIC', '-O2', '-g', '-w', '-I'+str(ROOT/'vendor/libbpf/src'),
         generated, adapter, '-o', args.build/'model.so'])
    native = ctypes.CDLL(str(args.build/'native.so')).loop_copy
    model = ctypes.CDLL(str(args.build/'model.so')).copy_x86_sim_xdp
    for function in (native, model):
        function.argtypes, function.restype = [ctypes.c_void_p], ctypes.c_uint32
    for name, function in [('native', native), ('shared simulator', model)]:
        print('Executing '+name, flush=True)
        for seed in range(64):
            packet = bytes((seed*37 + i*13) & 255 for i in range(32))
            value = ctypes.create_string_buffer(packet)
            expected = int.from_bytes(packet[:4], 'little')
            if function(value) != expected:
                raise ValueError(name+' copy disagrees with the input bytes')
    result = dict(stack_bytes=extent, native_return_continuations=len(returns),
                  native_and_shared_simulator_cases=64)
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for field in ('build', 'output', 'linker'):
        parser.add_argument('--'+field, type=Path, required=True)
    parser.add_argument('--step', choices=('add', 'inc'), default='add')
    check(parser.parse_args())
