"""Check real clang relative tables through proof and native kernel linking.

Executes emitted code on the host. Does not claim stock B verification or app
timing; the production B generator's status is recorded separately.
"""
import argparse
import ctypes
import hashlib
import importlib.util
import json
import mmap
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
    parser.add_argument('--kernel-layout', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command, check=True):
        result = subprocess.run(list(map(str, command)), text=True, capture_output=True)
        commands.append(dict(command=list(map(str, command)), returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if check:
            result.check_returncode()
        return result

    native = args.build/'jump-table.native.o'
    proof = args.build/'jump-table.proof.o'
    linked = run([args.linker, '--input', native, '--symbol', 'jump_table', '--mode', 'proof',
                  '--output', proof, '--show'])
    source_map = {row['input_offset']: row['output_offset'] for line in linked.stderr.splitlines()
                  if line.startswith('native-link-source-map ')
                  for row in [json.loads(line.split(' ', 1)[1])] if row['symbol'] == 'jump_table'}
    with native.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name('.symtab')
        expected = [source_map[symbols.get_symbol(r['r_info_sym'])['st_value'] +
                               r['r_addend'] - r['r_offset']]
                    for r in elf.get_section_by_name('.rela.rodata').iter_relocations()]
    with proof.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name('.symtab')
        nested = elf.get_section_by_name('.rela.native_link_rodata')
        if nested is None:
            raise ValueError('Proof object dropped its nested table relocations')
        relocations = list(nested.iter_relocations())
        actual = [symbols.get_symbol(r['r_info_sym'])['st_value'] +
                  r['r_addend'] - r['r_offset'] for r in relocations]
        if len(actual) != 8 or actual != expected:
            raise ValueError(f'Proof code-table target mismatch: {actual} vs {expected}')
        # Point one relative entry into an instruction. It must not survive
        # kernel binding even though the surrounding jump-table form matches.
        malformed = bytearray(proof.read_bytes())
        first_addend = nested['sh_offset'] + 16
        struct.pack_into('<q', malformed, first_addend,
                         struct.unpack_from('<q', malformed, first_addend)[0] + 1)
    bad = args.build/'jump-table-interior.proof.o'
    bad.write_bytes(malformed)

    plan = args.build/'jump-table-plan.json'
    plan.write_text(json.dumps(dict(version=1, kernel_layout=json.loads(args.kernel_layout.read_text()))))

    def kernel_command(source, destination):
        return [args.linker, '--input', source, '--symbol', 'jump_table', '--mode', 'kernel',
                '--output', destination, '--output-relocs', args.build/'jump-table.relocs',
                '--output-map-patches', args.build/'jump-table.maps',
                '--link-plan', plan, '--output-abi', args.build/'jump-table.abi']

    failure = run(kernel_command(bad, args.build/'jump-table-invalid.bin'), check=False)
    if failure.returncode == 0 or 'helper CFG branch targets an interior byte' not in failure.stderr:
        raise ValueError('Interior table target was not rejected at its source boundary')
    binary = args.build/'jump-table.bin'
    run(kernel_command(proof, binary))
    if (args.build/'jump-table.relocs').read_bytes() or (args.build/'jump-table.maps').read_bytes():
        raise ValueError('Local relative table acquired an external runtime relocation')
    code = binary.read_bytes() + b'\xc3'
    mask = (1 << 64) - 1
    executions = []
    with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
        memory.write(code)
        function = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint64), ctypes.c_uint32)(
            ctypes.addressof(ctypes.c_char.from_buffer(memory)))
        for seed in range(32):
            values = [(seed * 0x9e3779b97f4a7c15 + i * 0xd1b54a32d192ed03) & mask for i in range(8)]
            array = (ctypes.c_uint64 * 8)(*values)
            oracle = [values[0]+17, values[1]*3, values[2]^0x1234, values[3]-29,
                      values[4]|0x8000, values[5]&0x7fff, values[6]+71, values[7]*5]
            for index in [*range(8), 8, 0xffffffff]:
                actual_value = function(array, index)
                expected_value = (oracle[index] if index < 8 else 0) & mask
                if actual_value != expected_value:
                    raise ValueError(f'Seed{seed}, index{index}: {actual_value} != {expected_value}')
                executions.append(dict(seed=seed, index=index, actual=actual_value, expected=expected_value))

    sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86/micro-prog')]
    spec = importlib.util.spec_from_file_location('table_generator', ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    generator = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = generator
    spec.loader.exec_module(generator)
    try:
        body, subfunctions, exit_address, data = generator.parse_proof_object_program('jump-table', args.build)
        generator.render_program('jump_table', body, subfunctions, exit_addr=exit_address, rodata16=data)
    except (ValueError, RuntimeError, SystemExit) as error:
        b_status = dict(status='not_generated', error=str(error))
    else:
        b_status = dict(status='generated', scope='Generation only; not compiled or stock verified')
    model_executions, refusal_cases = [], []
    if b_status['status'] == 'generated':
        prelude = '''extern unsigned long long table_test_seed;
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() table_test_seed
extern void table_test_unresolved(void);
#define __x86_sim_unresolved_indirect_target table_test_unresolved
'''
        model = args.build/'jump-table-model.c'
        model.write_text(generator.render_program('table_model', body, subfunctions,
            kind='raw', program_section='socket/table_model', exit_addr=exit_address,
            rodata16=data, source_prelude=prelude))
        adapter = args.build/'jump-table-model-input.c'
        adapter.write_text('''#include <stdlib.h>
#include <stdio.h>
unsigned long long table_test_seed;
void table_test_unresolved(void) { abort(); }
unsigned long native_lab_entry_input(unsigned int kind) {
    if (kind == 1) return 0; /* Explicit zero-origin host stack fixture. */
    if (kind == 6) return table_test_seed;
    fprintf(stderr, "unexpected table input kind %u\\n", kind);
    abort();
}
''')
        library = args.build/'jump-table-model.so'
        run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I', ROOT/'kprog/x86/micro-prog',
             '-I', ROOT/'vendor/libbpf/src', model, adapter, '-o', library])
        loaded = ctypes.CDLL(str(library))
        seed_value = ctypes.c_uint64.in_dll(loaded, 'table_test_seed')
        function = loaded.table_model_x86_sim_xdp
        function.argtypes = [ctypes.c_void_p]
        function.restype = ctypes.c_uint32
        for row in executions:
            values = [(row['seed'] * 0x9e3779b97f4a7c15 + i * 0xd1b54a32d192ed03) & mask for i in range(8)]
            array = (ctypes.c_uint64 * 8)(*values)
            seed_value.value = row['index']
            actual_value = function(ctypes.cast(array, ctypes.c_void_p))
            expected_value = row['expected'] & 0xffffffff
            if actual_value != expected_value:
                raise ValueError(f'Shared simulator mismatch: {row}: {actual_value} != {expected_value}')
            model_executions.append(dict(seed=row['seed'], index=row['index'],
                                         actual=actual_value, expected=expected_value))
        flags = ['-target', 'x86_64-linux-gnu', '-O3', '-march=native', '-foptimize-sibling-calls',
                 '-fomit-frame-pointer', '-mno-red-zone', '-mgeneral-regs-only', '-fno-stack-protector']
        for name, define in [('live-flags', 'TEST_TABLE_LIVE_FLAGS'), ('partial-result', 'TEST_TABLE_PARTIAL_RESULT')]:
            negative = args.build/f'{name}.native.o'
            negative_proof = args.build/f'{name}.proof.o'
            run(['clang-18', *flags, '-D'+define, '-c', ROOT/'kprog/test/native_jump_table.c', '-o', negative])
            run([args.linker, '--input', negative, '--symbol', 'jump_table', '--mode', 'proof', '--output', negative_proof])
            negative_body, negative_functions, negative_exit, negative_data = generator.parse_proof_object_program(name, args.build)
            try:
                generator.render_program('negative_table', negative_body, negative_functions,
                    exit_addr=negative_exit, rodata16=negative_data)
            except ValueError as error:
                if 'live register or flag results' not in str(error):
                    raise
                refusal_cases.append(dict(case=name, error=str(error)))
            else:
                raise ValueError(f'{name}: private table state was incorrectly discarded')
    result = dict(source_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
                  proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(),
                  native_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
                  proof_targets=actual, expected_targets=expected, interior_target_rejected=True,
                  host_executions=executions, b_generation=b_status,
                  shared_simulator_executions=model_executions, private_state_refusals=refusal_cases,
                  scope='Host native execution/proof relocation binding; no kernel/app acceptance or timing')
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    run(['objdump', '-dr', '-Mintel', proof])
    print(json.dumps(dict(proof_targets=len(actual), host_executions=len(executions),
                         shared_simulator_executions=len(model_executions), b_generation=b_status)))


if __name__ == '__main__':
    main()
