"""Catch merging identical native objects or including relocation addends in map identity."""
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
OUT = HERE / 'readonly-layout'
LINK = ROOT / 'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link'
OUT.mkdir(exist_ok=True)

def run(args):
    result = subprocess.run([str(arg) for arg in args], capture_output=True, text=True, timeout=120)
    with (OUT / 'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(command=[str(arg) for arg in args], status=result.returncode,
                                    stdout=result.stdout, stderr=result.stderr)) + '\n')
    if result.returncode:
        raise RuntimeError(result.stderr)
    return result

payload = bytes((i * 13 + 7) % 256 for i in range(120))
for arch in ('x86', 'arm64'):
    case = OUT / arch
    case.mkdir(exist_ok=True)
    data = '.section .rodata,"a"\n.space 24, 0xe7\n'
    for symbol in ('object_a', 'object_b'):
        data += f'.global {symbol}\n.type {symbol}, @object\n{symbol}:\n.byte ' + ','.join(map(str, payload))
        data += f'\n.size {symbol}, .-{symbol}\n.space 16, 0xc3\n'
    if arch == 'x86':
        code = '''.text
.global entry
.type entry, @function
entry:
leaq object_a+7(%rip), %rax
movzbl (%rax), %eax
leaq object_b+48(%rip), %rcx
movzbl (%rcx), %ecx
addl %ecx, %eax
leaq object_a+80(%rip), %rcx
movzbl (%rcx), %ecx
addl %ecx, %eax
ret
.size entry, .-entry
'''
        triple = 'x86_64-linux-gnu'
    else:
        code = '''.text
.global entry
.type entry, @function
entry:
adrp x0, object_a+7
add x0, x0, :lo12:object_a+7
ldrb w0, [x0]
adrp x1, object_b+48
add x1, x1, :lo12:object_b+48
ldrb w1, [x1]
add w0, w0, w1
adrp x1, object_a+80
add x1, x1, :lo12:object_a+80
ldrb w1, [x1]
add w0, w0, w1
ret
.size entry, .-entry
'''
        triple = 'aarch64-linux-gnu'
    source = case / 'entry.S'
    source.write_text(code + data)
    native = case / 'entry.native.o'
    proof = case / 'entry.proof.o'
    run(['clang-18', '-target', triple, '-c', source, '-o', native])
    run([LINK, '--input', native, '--symbol', 'entry', '--mode', 'proof',
         '--preserve-entry-abi', '--output', proof])
    blob = case / 'entry.bin'
    layout_path = case / 'layout.json'
    run([LINK, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
         '--output', blob, '--output-data-layout', layout_path,
         '--output-abi', case / 'abi.txt', '--output-relocs', case / 'relocs.bin'])
    layout = json.loads(layout_path.read_text())
    assert layout['version'] == 1
    objects = layout['objects']
    assert {item['native_symbol'] for item in objects} == {'object_a', 'object_b'}, objects
    assert len({item['offset'] for item in objects}) == 2, objects
    for item in objects:
        assert item['size'] == 120, item
        assert blob.read_bytes()[item['offset']:item['offset']+120] == payload, item
    offsets = {item['native_symbol']: item['offset'] for item in objects}
    native_bytes = blob.read_bytes()
    expected_targets = [offsets['object_a']+7, offsets['object_b']+48, offsets['object_a']+80]
    if arch == 'x86':
        sites = [0, 10, 22]
        for site, target in zip(sites, expected_targets):
            assert native_bytes[site:site+2] == b'\x48\x8d'
            displacement = int.from_bytes(native_bytes[site+3:site+7], 'little', signed=True)
            assert site+7+displacement == target, (site, target)
    else:
        for site, target in zip([0, 12, 28], expected_targets):
            word = int.from_bytes(native_bytes[site:site+4], 'little')
            assert word & 0x9f000000 == 0x10000000  # ADR replaces the ADRP+ADD pair.
            displacement = ((word >> 29) & 3) | (((word >> 5) & 0x7ffff) << 2)
            if displacement & (1 << 20): displacement -= 1 << 21
            assert site+displacement == target, (site, target)
    with proof.open('rb') as stream:
        elf = ELFFile(stream)
        syms = elf.get_section_by_name('.symtab')
        for item in objects:
            sym, = syms.get_symbol_by_name(item['native_symbol'])
            section = elf.get_section(sym['st_shndx'])
            assert sym['st_size'] == item['size']
            assert section.data()[sym['st_value']:sym['st_value']+120] == payload
    if arch == 'x86':
        sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
        import generate_micro_sim_proofs as gen
        insns, subs, end, rodata = gen.parse_proof_object_program('entry', case)
        text = gen.render_program('entry', insns, subs, 'raw', exit_addr=end,
                                  rodata16=rodata, program_section='socket')
        bpf_source = case / 'entry.bpf.c'
        bpf_source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',
                             f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        bpf_object = case / 'entry.bpf.o'
        run(['clang', '-g', '-O2', '-target', 'bpf', '-Wno-c23-extensions',
             '-I'+str(ROOT / 'vendor/libbpf/src'),
             '-I'+str(ROOT / 'vendor/libbpf/include/uapi'),
             '-I/usr/include/x86_64-linux-gnu', '-c', bpf_source, '-o', bpf_object])
        with bpf_object.open('rb') as stream:
            elf = ELFFile(stream)
            metadata = json.loads(elf.get_section_by_name('.native_lab.rodata').data().rstrip(b'\0'))
            assert metadata['version'] == 1
            assert {item['native_symbol'] for item in metadata['objects']} == {'object_a', 'object_b'}
            for item in metadata['objects']:
                section = elf.get_section_by_name(item['proof_section'])
                assert section.data() == payload and item['size'] == len(section.data())
                sym, = elf.get_section_by_name('.symtab').get_symbol_by_name(item['proof_symbol'])
                assert sym['st_value'] == 0 and sym['st_size'] == item['size']
        (case / 'proof-metadata.json').write_text(json.dumps(metadata, indent=2)+'\n')
    (case / 'inputs.json').write_text(json.dumps({path.name: dict(size=path.stat().st_size)
       for path in (source, native, proof, blob, layout_path)}, indent=2)+'\n')
    print(arch, 'PASS: distinct identical 120-byte objects, whole extents and repeated interior references', flush=True)
