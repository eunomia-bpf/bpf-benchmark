"""Catch BMI2 value/count swaps, truncated results and changed defined flags.

Compare the actual native CPU against encoder-produced shared simulator C;
also compile every fixture through the normal B pipeline. All generated
products have one canonical path, overwritten on the next check.
"""
import argparse
import ctypes as c
import hashlib
import json
from pathlib import Path
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def allocated(path):
    with path.open('rb') as stream:
        return {s.name: s.data() for s in ELFFile(stream).iter_sections() if s['sh_flags'] & 2}


def main(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    sys.path[:0] = [str(ROOT / 'kprog/x86'), str(ROOT / 'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    gen = worker.gen
    commands = []

    def run(command):
        command = list(map(str, command))
        r = subprocess.run(command, capture_output=True, text=True)
        commands.append(dict(command=command, returncode=r.returncode,
                             stdout=r.stdout, stderr=r.stderr))
        (a.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        r.check_returncode()

    run(['clang-18', '-c', ROOT / 'kprog/test/native_bmi2.S', '-o', a.build / 'native.o'])
    run(['clang-18', '-shared', a.build / 'native.o', '-o', a.build / 'native.so'])
    native = c.CDLL(str(a.build / 'native.so'))
    adapter = a.build / 'input.c'
    adapter.write_text('''#include <stdlib.h>
/* Fixture choices: zero native SP origin and zero free-input words. */
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1 || kind == 6) return 0; abort(); }
''')
    values = [0, 1, 0x80000000, 0xffffffff, 0x8000000000000000,
              0xffffffffffffffff, 0x1234567887654321]
    counts = [0, 1, 7, 31, 32, 33, 63, 64, 65, 255, 256, 0x1234000000000021]
    observations = []
    for op in ('shlx', 'shrx', 'sarx', 'bzhi'):
        for width in (32, 64):
            for operand in ('reg', 'mem'):
                name = f'{op}{width}{operand}'
                run([a.linker, '--input', a.build / 'native.o', '--symbol', name,
                     '--mode', 'proof', '--preserve-entry-abi', '--output', a.build / f'{name}.proof.o'])
                body, functions, exit_addr, data = gen.parse_proof_object_program(name, a.build)
                source = gen.render_program(name, body, functions, kind='raw',
                                            program_section='kprobe/bmi2', exit_addr=exit_addr, rodata16=data)
                src = a.build / f'{name}.bpf.c'
                bpf = a.build / f'{name}.bpf.o'
                include = '#include ' + json.dumps(str(ROOT / 'kprog/x86/x86_sim_local_bpf.h'))
                src.write_text(source.replace('#include "../x86_sim_local_bpf.h"', include))
                worker.compile_simulator(str(ROOT / 'kprog/stock-path/bin/clang'), src, bpf, run,
                                         bounds_compiler=a.bounds)
                library = a.build / f'{name}.so'
                run(['clang-18', '-shared', '-fPIC', '-O2', '-w',
                     '-I' + str(ROOT / 'vendor/libbpf/src'), src, adapter, '-o', library])
                actual = getattr(native, name)
                model = getattr(c.CDLL(str(library)), name + '_x86_sim_xdp')
                for function in (actual, model):
                    function.argtypes, function.restype = [c.c_void_p], c.c_uint32
                cases = []
                for value in values:
                    for count in counts:
                        for mode in (0, 1, 2):
                            # Memory operands intentionally differ from the
                            # base slot: dropping the packed displacement
                            # must fail even when count/width are right.
                            input_data = (c.c_uint64 * 4)(value, count, mode, value ^ 0xa55a1234deadbeef)
                            expected, observed = actual(input_data), model(input_data)
                            if expected != observed:
                                raise ValueError(f'{name} value={value:#x} count={count:#x} mode={mode}: '
                                                 f'native={expected:#x}, simulator={observed:#x}')
                            cases.append(dict(value=value, count=count, mode=mode, result=observed))
                observations.append(dict(symbol=name, cases=cases, b_compiled=True,
                    bpf_sha256=hashlib.sha256(bpf.read_bytes()).hexdigest()))
                (a.output / 'result.json').write_text(json.dumps(dict(fixtures=observations,
                    scope='Native CPU/shared simulator equivalence and normal B compilation; no kernel acceptance'),
                    indent=2) + '\n')
                print(f'{name}: {len(cases)} native/simulator cases; normal B compiled', flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'linker', 'bounds'):
        parser.add_argument('--' + name, type=Path, required=True)
    main(parser.parse_args())
