"""Check sliced anonymous-table symbols through the normal B compiler and simulator."""
import argparse
import ctypes as c
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()

    sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    gen = worker.gen
    body, functions, exit_addr, data = gen.parse_proof_object_program('shared', args.build)
    generated = args.build/'shared.bpf.c'
    source = gen.render_program('shared_model', body, functions, kind='raw', program_section='kprobe/shared_table',
        exit_addr=exit_addr, rodata16=data, source_prelude='''#if !defined(__bpf__) && !defined(__BPF__)
extern void shared_table_unresolved(void);
#define __x86_sim_unresolved_indirect_target shared_table_unresolved
#endif''')
    generated.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
        '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
    obj = args.build/'shared.bpf.o'
    worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), generated, obj, run, bounds_compiler=args.bounds)
    adapter = args.build/'shared-host-input.c'
    adapter.write_text('''#include <stdlib.h>
void shared_table_unresolved(void) { abort(); }
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1) return 0; abort(); }
''')
    shared = args.build/'shared-model.so'
    run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I'+str(ROOT/'vendor/libbpf/src'), generated, adapter, '-o', shared])
    model = c.CDLL(str(shared)).shared_model_x86_sim_xdp
    model.argtypes, model.restype = [c.c_void_p], c.c_uint32
    cases = []
    # The Rust roundtrip leaves the second root as the single canonical proof.
    for seed in range(4):
        values = [seed*0x9e3779b9+i*71 for i in range(9)]
        expected = [values[1]+29, values[2]*3, values[3]^(29+0x1234), values[4]-29,
                    values[5]|0x8000, values[6]&0x7fff, values[7]+29*7, values[8]*5]
        for index in range(16):
            values[0] = index
            actual = model((c.c_uint64*9)(*values))
            oracle = (expected[index] if index < 8 else 0)&0xffffffff
            if actual != oracle: raise ValueError(f'Sliced table simulator mismatch {seed}/{index}: {actual} != {oracle}')
            cases.append(dict(seed=seed, index=index, actual=actual, expected=oracle))
    (args.output/'result.json').write_text(json.dumps(dict(b_compiled=True, shared_simulator_cases=cases,
        proof_sha256=hashlib.sha256((args.build/'shared.proof.o').read_bytes()).hexdigest(),
        bpf_sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),
        scope='Sliced shared-rodata proof through normal B and full shared simulator; no kernel load or app execution'), indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'bounds'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
