"""Check the scalar-only shared-rodata proof through normal B and shared C."""
import argparse
import ctypes as c
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    sys.path[:0] = [str(ROOT / 'kprog/x86'), str(ROOT / 'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    commands = []

    def run(command):
        command = list(map(str, command))
        r = subprocess.run(command, capture_output=True, text=True)
        commands.append(dict(command=command, returncode=r.returncode, stdout=r.stdout, stderr=r.stderr))
        (a.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        r.check_returncode()

    body, functions, exit_addr, data = worker.gen.parse_proof_object_program('scalar', a.build)
    source = worker.gen.render_program('scalar_model', body, functions, kind='raw',
        program_section='kprobe/scalar_data', exit_addr=exit_addr, rodata16=data)
    src, obj = a.build / 'scalar.bpf.c', a.build / 'scalar.bpf.o'
    src.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
        '#include ' + json.dumps(str(ROOT / 'kprog/x86/x86_sim_local_bpf.h'))))
    worker.compile_simulator(str(ROOT / 'kprog/stock-path/bin/clang'), src, obj, run, bounds_compiler=a.bounds)
    adapter = a.build / 'input.c'
    adapter.write_text('''#include <stdlib.h>
/* Fixture choices: zero native SP origin and zero free-input words. */
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1 || kind == 6) return 0; abort(); }
''')
    shared = a.build / 'scalar-model.so'
    run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I' + str(ROOT / 'vendor/libbpf/src'),
         src, adapter, '-o', shared])
    function = c.CDLL(str(shared)).scalar_model_x86_sim_xdp
    function.argtypes, function.restype = [c.c_void_p], c.c_uint32
    rows = []
    for index in list(range(32)) + [(1 << 63) + n for n in range(32)]:
        context = (c.c_uint64 * 1)(index)
        actual, expected = function(context), 0x12340000 + ((index & 7) + 1) * 0x101
        if actual != expected:
            raise ValueError(f'Scalar data/index/interior origin mismatch: {index}: {actual} != {expected}')
        rows.append(dict(index=index, actual=actual, expected=expected))
    record = dict(cases=rows, b_compiled=True, proof_sha256=hashlib.sha256((a.build / 'scalar.proof.o').read_bytes()).hexdigest(),
                  bpf_sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),
                  scope='Normal B compilation and shared-C host execution; no kernel/app acceptance')
    (a.output / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
    print('scalar rodata: normal B compiled; 64 shared-C cases match independent values')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ['build', 'output', 'bounds']:
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
