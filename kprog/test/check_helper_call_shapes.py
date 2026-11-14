"""Compare named, adjacent and hoisted helper calls through the real linker."""
import argparse
import ctypes
import json
import mmap
from pathlib import Path
import struct
import subprocess


def check(args):
    args.output.mkdir(parents=True, exist_ok=True)
    args.build.mkdir(parents=True, exist_ok=True)
    commands, results = [], []
    count = [0]
    signature = ctypes.CFUNCTYPE(ctypes.c_uint64)

    def helper():
        count[0] += 1
        return 100 + count[0]

    callback = signature(helper)
    target = ctypes.cast(callback, ctypes.c_void_p).value
    plan = args.build/'plan.json'
    plan.write_text(json.dumps(dict(version=1, helpers=[dict(name='bpf_get_prandom_u32', addr=target)])))
    flags = ['--abi-load-sites', 'true', '--runtime-map-lookups', '--runtime-known-map-lookups', '--local-memory-routines',
             '--runtime-probe-read-layout', args.layouts/'runtime-probe-read-layout.json',
             '--runtime-probe-read-strings', '--runtime-percpu-loads',
             '--runtime-hash-layout', args.layouts/'runtime-hash-layout.json',
             '--runtime-lpm-layout', args.layouts/'runtime-lpm-layout.json',
             '--runtime-array-layout', args.layouts/'runtime-array-layout.json', '--runtime-array-shared']

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()

    for label, intervening, calls in [('adjacent', '', 1), ('separated', 'xor r10d,r10d\n', 1),
                                       ('hoisted', '', 2)]:
        outputs = []
        for named in (True, False):
            if named:
                body = (intervening+'call bpf_get_prandom_u32\n')*calls
            elif label == 'hoisted':
                body = 'mov rbx,7\n'+'call rbx\n'*calls
            else:
                body = 'mov rax,7\n'+intervening+'call rax\n'
            source = '.intel_syntax noprefix\n.text\n.global entry\n.type entry,@function\nentry:\npush rbx\n'+body+'pop rbx\nret\n.size entry,.-entry\n.section .note.GNU-stack,"",@progbits\n'
            # Replace each product in place; observations stay in the raw directory.
            assembly = args.build/'fixture.S'
            assembly.write_text(source)
            obj, proof = args.build/'fixture.o', args.build/'fixture.proof.o'
            run(['cc', '-c', assembly, '-o', obj])
            run([args.linker, *flags, '--input', obj, '--symbol', 'entry', '--mode', 'proof',
                 '--preserve-entry-abi', '--output', proof])
            run([args.linker, *flags, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
                 '--link-plan', plan, '--output', args.build/'image.bin',
                 '--output-relocs', args.build/'image.relocs',
                 '--output-map-patches', args.build/'image.maps', '--output-abi', args.build/'image.abi'])
            output = {suffix: (args.build/('image.'+suffix)).read_bytes()
                      for suffix in ('bin', 'relocs', 'maps', 'abi')}
            outputs.append(output)
            blob = bytearray(output['bin'])
            image = mmap.mmap(-1, len(blob)+1, prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC)
            address = ctypes.addressof(ctypes.c_char.from_buffer(image))
            for offset in range(0, len(output['relocs']), 16):
                patch, kind, destination = struct.unpack_from('<IIQ', output['relocs'], offset)
                if kind != 1 or destination != target:
                    raise ValueError('Unexpected helper relocation')
                struct.pack_into('<i', blob, patch+1, target-(address+patch+5))
            image.write(blob+b'\xc3')
            count[0] = 0
            function = signature(address)
            actual = function()
            del function
            image.close()
            if actual != 100+calls or count[0] != calls:
                raise ValueError(f'{label}/{named}: helper result/count changed')
            results.append(dict(shape=label, named=named, assembly=source,
                                result=actual, calls=count[0], bytes=len(blob)))
        if outputs[0] != outputs[1]:
            raise ValueError(f'Named and numeric runtime output differs for {label}')
    result = dict(cases=results, runtime_image_relocations_maps_abi_equal=True,
                  combined_lto_options=True, linker=str(args.linker))
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('linker', 'layouts', 'build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    check(parser.parse_args())
