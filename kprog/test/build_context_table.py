"""Compile the single-context table fixture through the normal B compiler."""
import argparse
import ctypes
import hashlib
import json
import mmap
from pathlib import Path
import resource
import subprocess
import sys
from datetime import datetime, timezone
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def main(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []
    result = dict(started=datetime.now(timezone.utc).isoformat(),
                  scope='Single-context KPROBE fixture; host execution and normal B compilation only')

    def run(command):
        command = list(map(str, command))
        completed = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=completed.returncode,
                             stdout=completed.stdout, stderr=completed.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        completed.check_returncode()
        return completed.stdout

    try:
        source = ROOT/'kprog/test/native_jump_table_context.c'
        native, proof = args.build/'table.native.o', args.build/'trusted_x86.proof.o'
        flags = ['-target', 'x86_64-linux-gnu', '-O3', '-march=native', '-foptimize-sibling-calls',
                 '-fomit-frame-pointer', '-mno-red-zone', '-mgeneral-regs-only', '-fno-stack-protector']
        run(['clang-18', *flags, '-g', '-c', source, '-o', native])
        run(['clang-18', '-target', 'bpf', '-O2', '-g', '-I/usr/include/x86_64-linux-gnu',
             '-I'+str(ROOT/'vendor/libbpf/src'), '-c', source, '-o', args.build/'original.bpf.o'])
        run([args.linker, '--input', native, '--symbol', 'jump_table', '--mode', 'proof',
             '--preserve-entry-abi', '--output', proof])
        with proof.open('rb') as stream:
            elf = ELFFile(stream)
            section = elf.get_section_by_name('.rela.native_link_rodata')
            if section is None or section.num_relocations() != 8:
                raise ValueError('Fixture did not retain eight actual code-table relocations')
        plan = args.build/'plan.json'
        plan.write_text(json.dumps(dict(version=1, kernel_layout=json.loads(args.kernel_layout.read_text()))))
        binary = args.build/'table.bin'
        run([args.linker, '--input', proof, '--symbol', 'jump_table', '--mode', 'kernel',
             '--link-plan', plan, '--output', binary, '--output-relocs', args.build/'table.relocs',
             '--output-map-patches', args.build/'table.maps', '--output-abi', args.build/'table.abi'])
        if (args.build/'table.relocs').read_bytes() or (args.build/'table.maps').read_bytes():
            raise ValueError('Local table unexpectedly needs a runtime resource binding')
        code = binary.read_bytes()+b'\xc3'
        executions = []
        with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
            memory.write(code)
            function = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64))(
                ctypes.addressof(ctypes.c_char.from_buffer(memory)))
            for seed in range(32):
                values = [(seed*0x9e3779b97f4a7c15+i*0xd1b54a32d192ed03) & ((1<<64)-1) for i in range(11)]
                oracle = [values[0]+17, values[1]*3, values[2]^0x1234, values[3]-29,
                          values[4]|0x8000, values[5]&0x7fff, values[6]+71, values[7]*5]
                for index in range(16):
                    values[10] = index
                    context = (ctypes.c_uint64*11)(*values)
                    actual = function(context)
                    expected = (oracle[index] if index < 8 else 0) & 0xffffffff
                    if actual != expected:
                        raise ValueError(f'Native single-context mismatch {seed}/{index}: {actual} != {expected}')
                    executions.append(dict(seed=seed, index=index, actual=actual, expected=expected))
        result['host_executions'] = executions
        sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog'), str(ROOT/'kprog/x86/micro-prog')]
        import trusted_specializer as worker
        generator = worker.gen
        body, functions, exit_address, data = generator.parse_proof_object_program('trusted_x86', args.build)
        generated = args.build/'trusted_x86.bpf.c'
        text = generator.render_program('trusted_x86', body, functions, kind='raw',
            program_section='kprobe/jump_table', exit_addr=exit_address, rodata16=data,
            source_prelude='''#if !defined(__bpf__) && !defined(__BPF__)
extern void context_table_unresolved(void);
#define __x86_sim_unresolved_indirect_target context_table_unresolved
#endif''')
        text = text.replace('#include "../x86_sim_local_bpf.h"',
                            '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h')))
        generated.write_text(text)
        worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), generated,
                                 args.build/'trusted_x86.bpf.o', run, bounds_compiler=args.bounds)
        result['b_compiled'] = True
        adapter = args.build/'host-input.c'
        adapter.write_text('''#include <stdlib.h>
void context_table_unresolved(void) { abort(); }
unsigned long native_lab_entry_input(unsigned int kind) {
    if (kind == 1) return 0; /* Explicit zero-origin host stack fixture. */
    abort();
}
''')
        shared = args.build/'shared-simulator.so'
        run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I'+str(ROOT/'vendor/libbpf/src'),
             generated, adapter, '-o', shared])
        model = ctypes.CDLL(str(shared)).trusted_x86_x86_sim_xdp
        model.argtypes = [ctypes.POINTER(ctypes.c_uint64)]
        model.restype = ctypes.c_uint32
        model_executions = []
        for row in executions:
            values = [(row['seed']*0x9e3779b97f4a7c15+i*0xd1b54a32d192ed03) & ((1<<64)-1) for i in range(11)]
            values[10] = row['index']
            actual = model((ctypes.c_uint64*11)(*values))
            if actual != row['expected']:
                raise ValueError('Shared single-context simulator mismatch: '+str(row))
            model_executions.append(dict(seed=row['seed'], index=row['index'], actual=actual, expected=row['expected']))
        result['shared_simulator_executions'] = model_executions
        result.update(compiled=True, entry='trusted_x86_x86_sim_xdp', source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
            native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
            proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(),
            bpf_sha256=hashlib.sha256((args.build/'trusted_x86.bpf.o').read_bytes()).hexdigest(),
            linker_sha256=hashlib.sha256(args.linker.read_bytes()).hexdigest(),
            bounds_sha256=hashlib.sha256(args.bounds.read_bytes()).hexdigest())
    except Exception as error:
        result.update(compiled=False, error=str(error))
        raise
    finally:
        result.update(finished=datetime.now(timezone.utc).isoformat(),
                      address_space_limit_bytes=resource.getrlimit(resource.RLIMIT_AS)[0])
        (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'linker', 'kernel-layout', 'bounds'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
