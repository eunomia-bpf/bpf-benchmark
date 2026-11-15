"""Compile the real map-table helper consumer through normal B; compare host semantics."""
import argparse
import ctypes as c
import hashlib
import json
import mmap
from pathlib import Path
import resource
import struct
import subprocess
import sys
from datetime import datetime, timezone

ROOT = Path(__file__).resolve().parents[2]


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []
    result = dict(started=datetime.now(timezone.utc).isoformat(),
                  scope='Same-source KPROBE map-table/helper consumer: normal B compilation and host semantics')

    def run(command):
        command = list(map(str, command))
        completed = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=completed.returncode,
                             stdout=completed.stdout, stderr=completed.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        completed.check_returncode()
        return completed.stdout

    try:
        source = ROOT/'kprog/test/native_map_lookup_table.c'
        run(['clang-18', '-target', 'bpf', '-O2', '-g', '-I/usr/include/x86_64-linux-gnu',
             '-I'+str(ROOT/'vendor/libbpf/src'), '-c', source, '-o', args.build/'original.bpf.o'])
        for name, path in [('native', args.build/'lookup.native.o'), ('proof', args.build/'trusted_x86.proof.o')]:
            (args.output/(name+'.disassembly')).write_text(run(['objdump', '-dr', '-Mintel', path]))
            (args.output/(name+'.relocations')).write_text(run(['readelf', '-rW', path]))
        sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog'), str(ROOT/'kprog/x86/micro-prog')]
        import trusted_specializer as worker
        gen = worker.gen
        body, functions, exit_addr, data = gen.parse_proof_object_program('trusted_x86', args.build)
        bindings = [dict(native_symbol=f'map{n}', value_offset=None) for n in range(8)]
        host_prelude = '''#if !defined(__bpf__) && !defined(__BPF__)
extern void *map_table_host_lookup(void *, const void *);
#define bpf_map_lookup_elem map_table_host_lookup
#endif'''
        generated = args.build/'trusted_x86.bpf.c'
        text = gen.render_program('trusted_x86', body, functions, kind='raw',
            program_section='kprobe/map_lookup_table', exit_addr=exit_addr, rodata16=data,
            trusted_map_bindings=bindings, source_prelude=host_prelude)
        generated.write_text(text.replace('#include "../x86_sim_local_bpf.h"',
            '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
        worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), generated,
                                 args.build/'trusted_x86.bpf.o', run, bounds_compiler=args.bounds)
        result['b_compiled'] = True
        layout = json.loads(args.kernel_layout.read_text())['array']
        size = max(layout['value']+8, *(layout[name]+4 for name in ['map_type', 'max_entries', 'elem_size', 'index_mask']))
        adapter = args.build/'host-input.c'
        adapter.write_text('''#include <stdlib.h>
#include <stdint.h>
#include <string.h>
unsigned int helper_calls;
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1) return 0; abort(); }
'''+''.join(f'unsigned char map{n}[{size}];\n' for n in range(8))+'''
void *map_table_host_lookup(void *map, const void *key) {
    unsigned int index;
    memcpy(&index, key, 4);
    helper_calls++;
    if (index != 0) abort();
'''+f'    if (*(unsigned int *)((char *)map+{layout["map_type"]}) != {layout["array_type"]}) abort();\n'
   +f'    if (index >= *(unsigned int *)((char *)map+{layout["max_entries"]})) return 0;\n'
   +f'    return (char *)map+{layout["value"]};\n'+'}\n')
        shared = args.build/'shared-simulator.so'
        run(['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I'+str(ROOT/'vendor/libbpf/src'),
             generated, adapter, '-o', shared])
        library = c.CDLL(str(shared))
        model = library.trusted_x86_x86_sim_xdp
        model.argtypes, model.restype = [c.c_void_p], c.c_uint32
        calls = c.c_uint.in_dll(library, 'helper_calls')
        maps = {f'map{n}': (c.c_ubyte*size).in_dll(library, f'map{n}') for n in range(8)}
        code = bytearray((args.build/'lookup.kernel.bin').read_bytes())
        for line in (args.build/'lookup.map-patches.tsv').read_text().splitlines():
            name, offset = line.split('\t')
            code[int(offset):int(offset)+8] = c.addressof(maps[name]).to_bytes(8, 'little')
        code.append(0xc3)
        # Generic-helper relocations bind to an explicit trap. Every host map
        # is ARRAY, so these cases must use normal ARRAY LTO or its NULL path.
        trap = len(code)
        code.extend(b'\x0f\x0b')
        for offset in json.loads((args.build/'lookup.helper-slots.json').read_text()):
            if code[offset] != 0xe8:
                raise ValueError('Native helper relocation lost CALL slot')
            struct.pack_into('<i', code, offset+1, trap-(offset+5))
        cases = []
        with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
            memory.write(code)
            native = c.CFUNCTYPE(c.c_uint32, c.c_void_p)(c.addressof(c.c_char.from_buffer(memory)))
            for seed in range(4):
                for missing in (False, True):
                    for n, storage in enumerate(maps.values()):
                        for field, value in [('map_type', layout['array_type']), ('max_entries', 0 if missing else 1),
                                             ('elem_size', 8), ('index_mask', 0)]:
                            struct.pack_into('<I', storage, layout[field], value)
                        struct.pack_into('<Q', storage, layout['value'], ((seed+1)*0x9e3779b97f4a7c15+n*37)&((1<<64)-1))
                    for index in range(16):
                        context = (c.c_uint64*11)(*([0]*10+[index]))
                        expected = (0 if missing or index >= 8 else ((seed+1)*0x9e3779b97f4a7c15+index*37)&0xffffffff)
                        actual_native = native(context)
                        calls.value = 0
                        actual_model = model(context)
                        expected_calls = int(index < 8)
                        if (actual_native, actual_model, calls.value) != (expected, expected, expected_calls):
                            raise ValueError(f'Map lookup mismatch: {seed}/{missing}/{index}/{actual_native}/{actual_model}/{calls.value}')
                        cases.append(dict(seed=seed, missing=missing, index=index, native=actual_native,
                                          simulator=actual_model, expected=expected, model_helper_calls=calls.value))
            del native
        result['host_cases'] = cases
        result['hashes'] = {name: hashlib.sha256(path.read_bytes()).hexdigest() for name, path in [
            ('source', source), ('native', args.build/'lookup.native.o'), ('proof', args.build/'trusted_x86.proof.o'),
            ('bpf', args.build/'trusted_x86.bpf.o'), ('bounds', args.bounds)]}
        result['compiled'] = True
    except Exception as error:
        result.update(compiled=False, error=str(error))
        raise
    finally:
        result.update(finished=datetime.now(timezone.utc).isoformat(),
                      address_space_limit_bytes=resource.getrlimit(resource.RLIMIT_AS)[0])
        (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'kernel-layout', 'bounds'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
