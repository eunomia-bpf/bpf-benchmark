"""Check real clang non-PIC map binding and proof decoding.

Host execution checks emitted code only; this is not kernel/application timing.
Compiled fixture products replace the canonical scratch outputs in place.
"""
import argparse
import ctypes
from dataclasses import replace
import hashlib
import importlib.util
import json
import mmap
from pathlib import Path
import subprocess
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
    parser.add_argument('--kernel-layout', type=Path, required=True)
    args = parser.parse_args()
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command, check=True):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if check:
            result.check_returncode()
        return result

    def digest(path):
        return hashlib.sha256(path.read_bytes()).hexdigest()

    native = args.build/'non-pic.native.o'
    flags = ['-target', 'x86_64-linux-gnu', '-O3', '-march=native', '-foptimize-sibling-calls',
             '-fomit-frame-pointer', '-mno-red-zone', '-mgeneral-regs-only', '-fno-stack-protector']
    run(['clang-18', *flags, '-c', ROOT/'kprog/test/non_pic_map.c', '-o', native])
    disassembly = run(['objdump', '-dr', '-Mintel', native]).stdout
    (args.output/'native.disassembly').write_text(disassembly)
    if not any(kind+'\ttest_map' in disassembly for kind in ['R_X86_64_32', 'R_X86_64_PC32']):
        raise ValueError('Clang fixture did not exercise a direct map-address relocation')
    values = (ctypes.c_uint64*7)(0, 0, 0, 0, 101, 202, 303)
    address = ctypes.addressof(values)
    if address <= 0xffffffff:
        raise ValueError('Host map address does not exercise high pointer bits')
    plan = dict(version=1, kernel_layout=json.loads(args.kernel_layout.read_text()), helpers=[dict(name='bpf_map_lookup_elem', addr=0x1234)],
                maps=[dict(name='test_map', addr=address)], lookup_maps=[dict(name='test_map',
                kind='array', target_addr=0, key_offset=0, max_entries=3, elem_size=8,
                index_mask=3, value_offset=32, percpu_base_addr=0)])
    plan_path = args.build/'plan.json'
    plan_path.write_text(json.dumps(plan, indent=2)+'\n')
    proof = args.build/'non-pic.proof.o'
    run([args.linker, '--input', native, '--symbol', 'entry', '--mode', 'proof',
         '--output', proof])
    body = run(['objdump', '-dr', '-Mintel', proof]).stdout
    (args.output/'proof.disassembly').write_text(body)
    # Exercise the actual B decoder with the same source-map annotation used by
    # generation. No new simulator opcode or synthetic map identity is needed.
    sys.path.insert(0, str(ROOT/'kprog'))
    sys.path.insert(0, str(ROOT/'kprog/x86/micro-prog'))
    spec = importlib.util.spec_from_file_location('non_pic_generator',
        ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    generator = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = generator
    spec.loader.exec_module(generator)
    map_instructions = [i for i in generator.parse_asm_text(body) if i.reloc_symbol == 'test_map']
    if len(map_instructions) != 1:
        raise ValueError('Proof must retain exactly one symbolic map pointer')
    encoded = generator.encode(replace(map_instructions[0], source_pointer=(False, 'proof_map')), {})
    if encoded.op != 'X86_OP_MOV_LOAD_MAP_PTR':
        raise ValueError('Non-PIC proof map does not use the existing map-pointer simulator operation')
    results, plans, helper_calls = [], {}, []

    @ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.c_void_p, ctypes.c_void_p)
    def generic_lookup(map_pointer, key_pointer):
        helper_calls.append((map_pointer, ctypes.c_uint32.from_address(key_pointer).value))
        return 0

    helper_address = ctypes.cast(generic_lookup, ctypes.c_void_p).value
    layout = plan['kernel_layout']['array']
    size = max(layout['value'] + 24, max(layout[k] + 4 for k in
               ['map_type', 'max_entries', 'elem_size', 'index_mask']))
    runtime_map = ctypes.create_string_buffer(size)
    for name, value in [('map_type', layout['array_type']), ('max_entries', 3),
                        ('elem_size', 8), ('index_mask', 3)]:
        struct.pack_into('<I', runtime_map, layout[name], value)
    for index, value in enumerate([101, 202, 303]):
        struct.pack_into('<Q', runtime_map, layout['value'] + index * 8, value)

    # Both links use the full normal fact set. One has an exact named layout;
    # the other must dispatch on the live map type using the boot BTF offsets.
    for label, map_address in [('known-map', address),
                               ('runtime-map', ctypes.addressof(runtime_map))]:
        case_plan = json.loads(json.dumps(plan))
        case_plan['helpers'][0]['addr'] = helper_address
        case_plan['maps'][0]['addr'] = map_address
        if label == 'runtime-map':
            case_plan['lookup_maps'] = []
        plans[label] = case_plan
        plan_path.write_text(json.dumps(case_plan, indent=2)+'\n')
        blob, maps, relocs = [args.build/('image'+suffix) for suffix in ['.bin', '.maps', '.relocs']]
        run([args.linker, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
             '--output', blob, '--output-map-patches', maps, '--output-relocs', relocs,
             '--output-abi', args.build/'native.abi', '--link-plan', plan_path])
        relocations = list(struct.iter_unpack('<IIQ', relocs.read_bytes()))
        if label == 'known-map' and relocations:
            raise ValueError('Named array lookup was not inlined')
        if label == 'runtime-map' and not relocations:
            raise ValueError('Dynamic map lost its generic helper continuation')
        code = bytearray(blob.read_bytes())
        patches = maps.read_text().splitlines()
        if len(patches) != 1:
            raise ValueError('Live map must have one full-width pointer patch')
        name, offset = patches[0].split('\t')
        if name != 'test_map':
            raise ValueError('Map identity changed during normalization')
        code[int(offset):int(offset)+8] = map_address.to_bytes(8, 'little')
        code.append(0xc3)  # Kernel-provided return epilogue in this host harness.
        with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
            entry_address = ctypes.addressof(ctypes.c_char.from_buffer(memory))
            for at, kind, target in relocations:
                if kind != 1 or target != helper_address or code[at] != 0xe8:
                    raise ValueError('Unexpected dynamic helper relocation')
                struct.pack_into('<i', code, at + 1, target - (entry_address + at + 5))
            memory.write(code)
            function = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint32))(entry_address)
            for key in [0, 1, 2, 3, 4, 0xffffffff]:
                actual = function(ctypes.byref(ctypes.c_uint32(key)))
                expected = [101, 202, 303][key] if key < 3 else 0
                if actual != expected or helper_calls:
                    raise ValueError(f'{label}: key {key} returned {actual}, expected {expected}, helpers={helper_calls}')
                results.append(dict(path=label, key=key, actual=actual, expected=expected))
            if label == 'runtime-map':
                struct.pack_into('<I', runtime_map, layout['map_type'], 1)
                actual = function(ctypes.byref(ctypes.c_uint32(7)))
                if actual != 0 or helper_calls != [(map_address, 7)]:
                    raise ValueError('Non-ARRAY dispatch damaged the helper arguments or return')
                results.append(dict(path='runtime-other-type', key=7, actual=actual, expected=0,
                                    helper_calls=helper_calls.copy()))
            del function
    report = dict(current_linker_sha256=digest(args.linker), kernel_layout_sha256=digest(args.kernel_layout),
                  fixture_flags=flags, fixture_sha256=digest(native),
                  proof_sha256=digest(proof), proof_map_operation=encoded.op,
                  plans=plans, host_executions=results, scope='Host code/metadata checks; no kernel or app timing')
    (args.output/'result.json').write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps(dict(host_executions=len(results), proof_map_operation=encoded.op)))


if __name__ == '__main__':
    main()
