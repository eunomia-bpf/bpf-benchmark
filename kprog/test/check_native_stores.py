"""Compare native CPU stores with full shared-C memory/flags and normal B."""
import argparse
import ctypes as c
import hashlib
import json
from pathlib import Path
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    sys.path[:0] = [str(ROOT / 'kprog/x86'), str(ROOT / 'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    gen = worker.gen
    commands, observations = [], []

    def run(command):
        command = list(map(str, command))
        r = subprocess.run(command, capture_output=True, text=True)
        commands.append(dict(command=command, returncode=r.returncode,
                             stdout=r.stdout, stderr=r.stderr))
        (a.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        r.check_returncode()

    run(['clang-18', '-c', ROOT / 'kprog/test/native_stores.S', '-o', a.build / 'native.o'])
    run(['clang-18', '-shared', a.build / 'native.o', '-o', a.build / 'native.so'])
    native = c.CDLL(str(a.build / 'native.so'))
    adapter = a.build / 'input.c'
    adapter.write_text('''#include <stdlib.h>
/* Fixture choices: zero native SP origin and zero free-input words. */
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1 || kind == 6) return 0; abort(); }
''')
    identity = dict(native_sha256=digest(a.build / 'native.o'), linker_sha256=digest(a.linker),
                    header_sha256=digest(ROOT / 'kprog/x86/x86_sim_local_bpf.h'))
    values = [0, 1, 0x80, 0xffff, 0x80000000, 0x8000000000000000,
              0xffffffffffffffff, 0x1234567887654321]
    for width in (1, 2, 4, 8):
        for operand in ('reg', 'imm'):
            for address in ('flat', 'index'):
                name = f'store{width}{operand}{address}'
                run([a.linker, '--input', a.build / 'native.o', '--symbol', name,
                     '--mode', 'proof', '--preserve-entry-abi', '--output', a.build / f'{name}.proof.o'])
                body, functions, exit_addr, data = gen.parse_proof_object_program(name, a.build)
                source = gen.render_program(name, body, functions, kind='raw',
                    program_section='kprobe/stores', exit_addr=exit_addr, rodata16=data)
                src, bpf = a.build / f'{name}.bpf.c', a.build / f'{name}.bpf.o'
                src.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
                    '#include ' + json.dumps(str(ROOT / 'kprog/x86/x86_sim_local_bpf.h'))))
                worker.compile_simulator(str(ROOT / 'kprog/stock-path/bin/clang'), src, bpf, run,
                                         bounds_compiler=a.bounds)
                library = a.build / f'{name}.so'
                run(['clang-18', '-shared', '-fPIC', '-O2', '-w',
                     '-I' + str(ROOT / 'vendor/libbpf/src'), src, adapter, '-o', library])
                actual, model = getattr(native, name), getattr(c.CDLL(str(library)), name + '_x86_sim_xdp')
                for function in (actual, model):
                    function.argtypes, function.restype = [c.c_void_p], c.c_uint32
                cases = []
                for value in values:
                    for index in (0, 1, 3, 7):
                        initial = [value, index, *[0x9e3779b97f4a7c15 ^ i for i in range(14)]]
                        native_data, sim_data = (c.c_uint64 * 16)(*initial), (c.c_uint64 * 16)(*initial)
                        expected, observed = actual(native_data), model(sim_data)
                        if expected != observed or bytes(native_data) != bytes(sim_data):
                            raise ValueError(f'{name} value={value:#x} index={index}: native flags={expected}, '
                                f'sim flags={observed}, memory equal={bytes(native_data) == bytes(sim_data)}')
                        cases.append(dict(value=value, index=index, flags=observed,
                                          memory_hex=bytes(sim_data).hex()))
                with bpf.open('rb') as stream:
                    allocated = {s.name: hashlib.sha256(s.data()).hexdigest()
                                 for s in ELFFile(stream).iter_sections() if s['sh_flags'] & 2}
                observations.append(dict(symbol=name, cases=cases, b_compiled=True,
                    allocated_sha256=allocated, bpf_sha256=digest(bpf)))
                (a.output / 'result.json').write_text(json.dumps(dict(inputs=identity, fixtures=observations,
                    scope='Actual native CPU/shared-C full memory+CF/ZF/SF/OF, normal B compilation; no kernel acceptance'),
                    indent=2) + '\n')
                print(f'{name}: {len(cases)} memory/flag cases; normal B compiled', flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'linker', 'bounds'):
        parser.add_argument('--' + name, type=Path, required=True)
    main(parser.parse_args())
