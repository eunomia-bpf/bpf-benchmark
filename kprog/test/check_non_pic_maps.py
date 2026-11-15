"""Check real clang non-PIC map binding, proof decoding and default parity.

Host execution checks emitted code only; this is not kernel/application timing.
The old/current linker outputs are compared in memory, replacing the canonical
linker build and one scratch proof output in place.
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
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
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

    def proof_identity(path):
        with path.open('rb') as stream:
            elf = ELFFile(stream)
            symbols = elf.get_section_by_name('.symtab')
            allocations, relocations = [], []
            for section in elf.iter_sections():
                if section['sh_flags'] & 2:
                    allocations.append((section.name, hashlib.sha256(section.data()).hexdigest()))
                if section['sh_type'] in {'SHT_REL', 'SHT_RELA'}:
                    for reloc in section.iter_relocations():
                        relocations.append((section.name, reloc['r_offset'], reloc['r_info_type'],
                                            symbols.get_symbol(reloc['r_info_sym']).name,
                                            reloc.entry.get('r_addend', 0)))
            return dict(allocations=sorted(allocations), relocations=sorted(relocations))

    groups = []
    stage = ROOT/'vendor/build/native-bpf/x86/stage'
    for app in ['katran', 'bcc', 'tracee', 'tetragon', 'cilium', 'otelcol-ebpf-profiler']:
        manifest = stage/app/'manifest.json'
        groups.append([(app, manifest.parent/item['native_object'], item.get('symbol', item['program']))
                       for item in json.loads(manifest.read_text())['objects'][:4]])
    cases = [group[i] for i in range(4) for group in groups if i < len(group)][:22]

    def capture(extra):
        rows = []
        for app, source, symbol in cases:
            destination = args.build/'parity.proof.o'
            result = run([args.linker, '--input', source, '--symbol', symbol, '--mode', 'proof',
                          '--output', destination, *extra], check=False)
            row = dict(app=app, source=str(source), source_sha256=digest(source), symbol=symbol,
                       returncode=result.returncode)
            if result.returncode:
                row['stderr'] = result.stderr
            else:
                row['proof'] = proof_identity(destination)
            rows.append(row)
        return rows

    old_binary = digest(args.linker)
    before = capture([])
    run(['make', '-f', ROOT/'kprog/test/native-relocations.mk', 'build'])
    after = capture([])
    # clap's Boolean flag defaults off; an absent flag must match the old path.
    if before != after:
        (args.output/'default-before.json').write_text(json.dumps(before, indent=2)+'\n')
        (args.output/'default-after.json').write_text(json.dumps(after, indent=2)+'\n')
        raise ValueError('Default real-object proof allocations/relocations changed')
    (args.output/'default-parity.json').write_text(json.dumps(dict(
        old_linker_sha256=old_binary, current_linker_sha256=digest(args.linker),
        entries=len(before), equal=True, rows=before), indent=2)+'\n')

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
    plan = dict(version=1, helpers=[dict(name='bpf_map_lookup_elem', addr=0x1234)],
                maps=[dict(name='test_map', addr=address)], lookup_maps=[dict(name='test_map',
                kind='array', target_addr=0, key_offset=0, max_entries=3, elem_size=8,
                index_mask=3, value_offset=32, percpu_base_addr=0)])
    plan_path = args.build/'plan.json'
    plan_path.write_text(json.dumps(plan, indent=2)+'\n')
    proof = args.build/'non-pic.proof.o'
    run([args.linker, '--input', native, '--symbol', 'entry', '--mode', 'proof',
         '--output', proof, '--non-pic-map-addresses'])
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
    results = []
    # The production CLI requires a proof object for kernel mode. Direct
    # rewriting of the four source forms is covered by the Rust emitter tests.
    for label, source in [('proof-roundtrip', proof)]:
        blob, maps, relocs = [args.build/(label+suffix) for suffix in ['.bin', '.maps', '.relocs']]
        run([args.linker, '--input', source, '--symbol', 'entry', '--mode', 'kernel',
             '--output', blob, '--output-map-patches', maps, '--output-relocs', relocs,
             '--link-plan', plan_path, '--non-pic-map-addresses', '--runtime-map-lookups',
             '--runtime-known-map-lookups'])
        if relocs.read_bytes():
            raise ValueError('Named array lookup was not inlined')
        code = bytearray(blob.read_bytes())
        patches = maps.read_text().splitlines()
        if len(patches) != 1:
            raise ValueError('Live map must have one full-width pointer patch')
        name, offset = patches[0].split('\t')
        if name != 'test_map':
            raise ValueError('Map identity changed during normalization')
        offset = int(offset)
        code[offset:offset+8] = address.to_bytes(8, 'little')
        code.append(0xc3)  # Kernel-provided return epilogue in this host harness.
        with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
            memory.write(code)
            function = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint32))(
                ctypes.addressof(ctypes.c_char.from_buffer(memory)))
            for key in [0, 1, 2, 3, 4, 0xffffffff]:
                actual = function(ctypes.byref(ctypes.c_uint32(key)))
                expected = [101, 202, 303][key] if key < 3 else 0
                if actual != expected:
                    raise ValueError(f'{label}: key {key} returned {actual}, expected {expected}')
                results.append(dict(path=label, key=key, actual=actual, expected=expected))
    report = dict(old_linker_sha256=old_binary, current_linker_sha256=digest(args.linker),
                  default_real_object_entries=len(before), default_equal=True,
                  default_statuses=before, fixture_flags=flags, fixture_sha256=digest(native),
                  proof_sha256=digest(proof), proof_map_operation=encoded.op,
                  host_executions=results, scope='Host code/metadata checks; no kernel or app timing')
    (args.output/'result.json').write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps(dict(default_equal=len(before), host_executions=len(results), proof_map_operation=encoded.op)))


if __name__ == '__main__':
    main()
