"""Execute full-pointer code tables and compile their ordinary shared-body B."""
import argparse
import ctypes as c
import hashlib
import json
import mmap
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, capture_output=True, text=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (a.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()

    proof = a.build/'absolute.proof.o'
    previous_proof = hashlib.sha256(proof.read_bytes()).hexdigest()
    run([a.linker, '--input', a.build/'absolute.native.o', '--symbol', 'absolute_table',
         '--mode', 'proof', '--preserve-entry-abi', '--output', proof])
    if hashlib.sha256(proof.read_bytes()).hexdigest() != previous_proof:
        raise ValueError('published CLI proof differs from the tested library proof')
    plan = a.build/'absolute-plan.json'
    plan.write_text(json.dumps(dict(version=1, kernel_layout=json.loads(a.kernel_layout.read_text()))))
    run([a.linker, '--input', proof, '--symbol', 'absolute_table', '--mode', 'kernel',
         '--output', a.build/'absolute.bin', '--output-relocs', a.build/'absolute.relocs',
         '--output-map-patches', a.build/'absolute.maps', '--link-plan', plan])
    if (a.build/'absolute.maps').read_bytes():
        raise ValueError('local code table acquired a map capability')

    sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    gen = worker.gen
    body, functions, exit_addr, data = gen.parse_proof_object_program('absolute', a.build)
    source = gen.render_program('absolute_model', body, functions, kind='raw',
        program_section='kprobe/absolute_table', exit_addr=exit_addr, rodata16=data,
        source_prelude='''#if !defined(__bpf__) && !defined(__BPF__)
extern void absolute_unresolved(void);
#define __x86_sim_unresolved_indirect_target absolute_unresolved
#endif''')
    generated = a.build/'absolute.bpf.c'
    generated.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
        '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
    adapter = a.build/'absolute-input.c'
    adapter.write_text('''#include <stdlib.h>
void absolute_unresolved(void) { abort(); }
unsigned long native_lab_entry_input(unsigned int kind) {
    if (kind == 1 || kind == 6) return 0; /* Explicit host fixture choices. */
    abort();
}
''')
    library = a.build/'absolute.so'
    run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I'+str(ROOT/'vendor/libbpf/src'),
         generated, adapter, '-o', library])
    model = c.CDLL(str(library)).absolute_model_x86_sim_xdp
    model.argtypes, model.restype = [c.c_void_p], c.c_uint32
    metadata = json.loads((a.build/'rust-result.json').read_text())
    pointers = [dict(offset=offset, kind=kind, target=target) for offset, kind, target in
                struct.iter_unpack('<IIQ', (a.build/'absolute.relocs').read_bytes())]
    if pointers != metadata['runtime_image_pointers']:
        raise ValueError('published CLI image pointers differ from tested library binding')
    binary = (a.build/'absolute.bin').read_bytes() + b'\xc3'
    rows = []
    with mmap.mmap(-1, len(binary), prot=mmap.PROT_READ|mmap.PROT_WRITE|mmap.PROT_EXEC) as memory:
        base = c.addressof(c.c_char.from_buffer(memory))
        memory.write(binary)
        for pointer in pointers:
            if pointer['kind'] != 12 or not 0 <= pointer['target'] < len(binary)-1:
                raise ValueError('invalid image-relative code pointer')
            c.c_uint64.from_address(base+pointer['offset']).value = base+pointer['target']
        native = c.CFUNCTYPE(c.c_uint64, c.c_void_p)(base)
        for seed in range(64):
            values = [(seed*0x9e3779b97f4a7c15+i*0xd1b54a32d192ed03)&((1<<64)-1) for i in range(9)]
            expected = [values[1]+17, values[2]*3, values[3]^0x1234, values[4]-29,
                        values[5]|0x8000, values[6]&0x7fff, values[7]+71, values[8]*5]
            for index in [*range(15), (1<<64)-1]:
                values[0] = index
                ctx = (c.c_uint64*9)(*values)
                oracle = (expected[index] if index < 8 else 0)&((1<<64)-1)
                before = bytes(ctx)
                actual = native(ctx)
                if bytes(ctx) != before:
                    raise ValueError(f'native table changed readonly context {seed}/{index}')
                simulated = model(ctx)
                if bytes(ctx) != before:
                    raise ValueError(f'simulator table changed readonly context {seed}/{index}')
                if actual != oracle or simulated != oracle&0xffffffff:
                    raise ValueError(f'absolute table {seed}/{index}: {actual}/{simulated} != {oracle}')
                rows.append(dict(seed=seed, index=index, native=actual, simulator_u32=simulated, expected=oracle))
    worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), generated,
        a.build/'absolute.bpf.o', run, bounds_compiler=a.bounds)
    paths = [a.build/name for name in ['absolute.native.o', 'absolute.proof.o', 'absolute.bin', 'absolute.bpf.o']]
    (a.output/'result.json').write_text(json.dumps(dict(native_cases=len(rows),
        shared_simulator_cases=len(rows), normal_b_compiled=True, image_pointers=pointers,
        cases=rows, sha256={p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
        scope='Native host image-relative binding and shared-C/normal-B compilation; no kernel installation or application claim.'),indent=2)+'\n')
    print(f'{len(rows)} native + {len(rows)} shared simulator cases; normal B compiled')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ['build', 'output', 'bounds', 'linker', 'kernel-layout']:
        p.add_argument('--'+name, type=Path, required=True)
    main(p.parse_args())
