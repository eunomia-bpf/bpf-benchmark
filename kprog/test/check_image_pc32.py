"""Exercise the shipped linker's PC32 map binding inside the test guest.

ELFs travel on stdin/stdout; no source or image filesystem is copied into a
private tree. Executions use a userspace array, not a live kernel map.
"""
import argparse
import ctypes as c
import hashlib
import json
import mmap
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile


def main(a):
    commands = []

    def run(command, data=None, name='command'):
        command = list(map(str, command))
        result = subprocess.run(command, input=data, capture_output=True)
        (a.output/(name+'.stderr')).write_bytes(result.stderr)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout_sha256=hashlib.sha256(result.stdout).hexdigest(),
                             stderr=str(a.output/(name+'.stderr'))))
        (a.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result

    native = a.build/'non-pic.native.o'
    with native.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name('.symtab')
        pc32 = [r['r_offset'] for section in elf.iter_sections() if section['sh_type'] == 'SHT_RELA'
                and section.name == '.rela.text' for r in section.iter_relocations()
                if r['r_info_type'] == 2 and symbols.get_symbol(r['r_info_sym']).name == 'test_map']
    if len(pc32) != 1:
        raise ValueError('fixture does not contain exactly one PC32 test_map reference')
    identity = run(['docker', 'run', '--rm', a.image, 'sha256sum', '/usr/local/bin/native-link'], name='identity')
    shipped = identity.stdout.decode().split()[0]
    expected = hashlib.sha256(a.repo_linker.read_bytes()).hexdigest()
    if shipped != expected:
        raise ValueError(f'image linker {shipped} differs from repository {expected}')
    proof_result = run(['docker', 'run', '--rm', '-i', a.image, 'native-link',
        '--input', '/dev/stdin', '--symbol', 'entry', '--mode', 'proof', '--output', '/dev/stdout'],
        native.read_bytes(), 'proof')
    proof = a.build/'non-pic.proof.o'
    proof.write_bytes(proof_result.stdout)
    values = (c.c_uint64*7)(0, 0, 0, 0, 101, 202, 303)
    address = c.addressof(values)
    if address <= 0xffffffff:
        raise ValueError('map pointer does not exercise the upper 32 bits')
    plan = dict(version=1, kernel_layout=json.loads(a.kernel_layout.read_text()),
        helpers=[dict(name='bpf_map_lookup_elem', addr=0x1234)],
        maps=[dict(name='test_map', addr=address)], lookup_maps=[dict(name='test_map',
            kind='array', target_addr=0, key_offset=0, max_entries=3, elem_size=8,
            index_mask=3, value_offset=32, percpu_base_addr=0)])
    (a.output/'plan.json').write_text(json.dumps(plan, indent=2)+'\n')
    shell = 'exec native-link --input /dev/stdin --symbol entry --mode kernel --output /dev/stdout --output-map-patches /dev/stderr --output-relocs /dev/stderr --output-abi /dev/null --link-plan <(printf "%s" "$PC32_PLAN")'
    linked = run(['docker', 'run', '--rm', '-i', '-e', 'PC32_PLAN='+json.dumps(plan),
                  a.image, 'bash', '-c', shell], proof.read_bytes(), 'kernel')
    patches = [line.split('\t') for line in linked.stderr.decode().splitlines() if line.startswith('test_map\t')]
    if len(patches) != 1:
        raise ValueError('image linker did not emit one full-width map binding')
    offset = int(patches[0][1])
    code = bytearray(linked.stdout)
    if code[offset:offset+8] != bytes(8):
        raise ValueError('map patch slot is not a complete zeroed pointer')
    (a.build/'known-map.bin').write_bytes(code)
    code[offset:offset+8] = address.to_bytes(8, 'little')
    code.append(0xc3)
    cases = []
    with mmap.mmap(-1, len(code), prot=mmap.PROT_READ|mmap.PROT_WRITE|mmap.PROT_EXEC) as memory:
        memory.write(code)
        function = c.CFUNCTYPE(c.c_uint64, c.POINTER(c.c_uint32))(c.addressof(c.c_char.from_buffer(memory)))
        for key in [0, 1, 2, 3, 4, 0xffffffff]:
            actual = function(c.byref(c.c_uint32(key)))
            oracle = [101, 202, 303][key] if key < 3 else 0
            if actual != oracle:
                raise ValueError(f'PC32 image output {key}: {actual} != {oracle}')
            cases.append(dict(key=key, actual=actual, expected=oracle))
    (a.output/'result.json').write_text(json.dumps(dict(image=a.image, image_linker_sha256=shipped,
        repository_linker_sha256=expected, native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
        proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(), pc32_offsets=pc32,
        map_address=address, full_pointer_patch_offset=offset, cases=cases,
        scope='Guest userspace execution of image-linked code; not a kernel map or application load.'),indent=2)+'\n')
    print('shipped linker matches repository; PC32 map -> full pointer; six guest executions pass')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', required=True)
    for name in ['build', 'output', 'kernel-layout', 'repo-linker']:
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
