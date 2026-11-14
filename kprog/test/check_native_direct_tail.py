"""Exercise direct native function tail calls through the production linker."""
import argparse
import ctypes
import json
import mmap
import os
from pathlib import Path
import struct
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('linker', type=Path)
    parser.add_argument('fixture', type=Path)
    parser.add_argument('library', type=Path)
    parser.add_argument('reference', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    # The control library's uncalled external_entry is intentionally unresolved.
    library = ctypes.CDLL(str(args.library), mode=os.RTLD_LAZY | os.RTLD_LOCAL)
    value = ctypes.c_uint.in_dll(library, 'live_value')
    helper_type = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.c_uint64)
    external = helper_type(lambda n: n * 3 + 17)
    external_address = ctypes.cast(external, ctypes.c_void_p).value
    records = []

    def command(argv, name):
        with (args.output / (name + '.stdout')).open('wb') as stdout, \
                (args.output / (name + '.stderr')).open('wb') as stderr:
            subprocess.run(list(map(str, argv)), stdout=stdout, stderr=stderr, check=True)

    def link(binary, entry, label):
        base = args.output / label
        proof = base.with_suffix('.proof.o')
        command([binary, '--input', args.fixture, '--symbol', entry, '--mode', 'proof',
                 '--output', proof], label + '-proof')
        plan = base.with_suffix('.plan.json')
        plan.write_text(json.dumps(dict(version=1,
            helpers=[dict(name='real_external', addr=external_address)],
            maps=[dict(name='live_value', addr=0)], lookup_sites=[], lookup_maps=[], update_sites=[])) + '\n')
        command([binary, '--input', proof, '--symbol', entry, '--mode', 'kernel',
                 '--link-plan', plan, '--output', base.with_suffix('.bin'),
                 '--output-relocs', base.with_suffix('.relocs'),
                 '--output-map-patches', base.with_suffix('.maps'),
                 '--output-abi', base.with_suffix('.abi')], label + '-kernel')
        return base

    for entry in ['entry', 'nested', 'global_tail', 'external_entry', 'decoded_entry', 'stack_entry', 'plain_entry']:
        base = link(args.linker, entry, entry)
        blob = bytearray(base.with_suffix('.bin').read_bytes())
        # A host RET stands in for the BPF JIT epilogue at the end label.
        image = mmap.mmap(-1, len(blob) + 1, prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC)
        address = ctypes.addressof(ctypes.c_char.from_buffer(image))
        map_names = []
        for line in base.with_suffix('.maps').read_text().splitlines():
            if not line:
                continue
            fields = line.split('\t')
            # The production map patch table is symbol name, offset.
            name, offset = fields[0], int(fields[1])
            if name != 'live_value':
                raise AssertionError('unrelated data capability: ' + name)
            struct.pack_into('<Q', blob, offset, ctypes.addressof(value))
            map_names.append(name)
        relocations = base.with_suffix('.relocs').read_bytes()
        for offset in range(0, len(relocations), 16):
            patch, kind, target = struct.unpack_from('<IIQ', relocations, offset)
            if kind != 1 or target != external_address:
                raise AssertionError('unexpected native relocation')
            struct.pack_into('<i', blob, patch + 1, target - (address + patch + 5))
        image.write(blob + b'\xc3')
        function = helper_type(address)
        control = getattr(library, entry)
        control.argtypes = [ctypes.c_uint64]
        control.restype = ctypes.c_uint64
        samples = []
        for configured in [37, 71]:
            value.value = configured
            for argument in [0, 1, 7, 4096]:
                expected = argument * 3 + 17 if entry == 'external_entry' else control(argument)
                actual = function(argument)
                if actual != expected:
                    raise AssertionError(f'{entry}({argument}) config={configured}: {actual} != {expected}')
                samples.append(dict(argument=argument, configured=configured, actual=actual, expected=expected))
        del function
        image.close()
        records.append(dict(entry=entry, samples=samples, maps=map_names))

    reference = link(args.reference, 'plain_entry', 'plain-reference')
    plain = args.output / 'plain_entry'
    for suffix in ['.proof.o', '.bin', '.relocs', '.maps', '.abi']:
        if reference.with_suffix(suffix).read_bytes() != plain.with_suffix(suffix).read_bytes():
            raise AssertionError('unaffected default output changed: ' + suffix)
    (args.output / 'results.json').write_text(json.dumps(dict(cases=records,
        unaffected_default_identical=True), indent=2) + '\n')
    print('direct tail entry/nested/decoded/external/global execution and unaffected default bytes: PASS')


if __name__ == '__main__':
    main()
