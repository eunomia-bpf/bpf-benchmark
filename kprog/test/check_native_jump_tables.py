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

    def kernel_command(source, destination):
        return [args.linker, '--input', source, '--symbol', 'jump_table', '--mode', 'kernel',
                '--output', destination, '--output-relocs', args.build/'jump-table.relocs',
                '--output-map-patches', args.build/'jump-table.maps']

    failure = run(kernel_command(bad, args.build/'jump-table-invalid.bin'), check=False)
    if failure.returncode == 0 or 'interior instruction' not in failure.stderr:
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
    result = dict(source_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
                  proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(),
                  native_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
                  proof_targets=actual, expected_targets=expected, interior_target_rejected=True,
                  host_executions=executions, b_generation=b_status,
                  scope='Host native execution/proof relocation binding; no kernel/app acceptance or timing')
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    run(['objdump', '-dr', '-Mintel', proof])
    print(json.dumps(dict(proof_targets=len(actual), host_executions=len(executions), b_generation=b_status)))


if __name__ == '__main__':
    main()
