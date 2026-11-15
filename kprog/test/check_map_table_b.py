"""Check real nested map relocations through shared simulator capability ops."""
import argparse
import ctypes as c
from dataclasses import replace
import hashlib
import importlib.util
import json
import mmap
from pathlib import Path
import subprocess
import sys
import _ctypes

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86/micro-prog')]
spec = importlib.util.spec_from_file_location('map_table_gen', ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
gen = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = gen
spec.loader.exec_module(gen)


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    commands, cases = [], []
    body, functions, exit_addr, data = gen.parse_proof_object_program('fixture', args.build)
    maps = [dict(native_symbol='map'+str(n), value_offset=None) for n in range(8)]
    prelude = '''#if !defined(__bpf__) && !defined(__BPF__)
extern unsigned long long observed_pointer;
extern unsigned int observed_tag;
#undef X86_SIM_X86_RET
#define X86_SIM_X86_RET() do { observed_pointer=X86_SIM_L_READ_REG(X86_RAX); observed_tag=X86_SIM_L_REG_TAG(X86_RAX); return 0; } while (0)
#endif'''
    for is_value in (False, True):
        bindings = [dict(item, value_offset=0 if is_value else None) for item in maps]
        source = gen.render_program('map_table', body, functions, kind='raw', program_section='socket/map_table',
            exit_addr=exit_addr, rodata16=data, trusted_map_bindings=bindings, source_prelude=prelude)
        source = source.replace('#include "../x86_sim_local_bpf.h"',
            '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h')))
        generated = args.build/'map-table.bpf.c'
        generated.write_text(source)
        adapter = args.build/'model-input.c'
        adapter.write_text('''#include <stdlib.h>
unsigned long long observed_pointer;
unsigned int observed_tag;
unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1) return 0; abort(); }
'''+''.join('unsigned char map'+str(n)+'[32];\n' for n in range(8)))
        shared = args.build/'map-table-model.so'
        command = ['clang-18', '-shared', '-fPIC', '-O2', '-w', '-I'+str(ROOT/'vendor/libbpf/src'),
                   str(generated), str(adapter), '-o', str(shared)]
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        library = c.CDLL(str(shared))
        try:
            addresses = {f'map{n}': c.addressof((c.c_ubyte*32).in_dll(library, f'map{n}')) for n in range(8)}
            code = bytearray((args.build/'fixture.kernel.bin').read_bytes())
            for line in (args.build/'fixture.map-patches.tsv').read_text().splitlines():
                name, offset = line.split('\t')
                code[int(offset):int(offset)+8] = addresses[name].to_bytes(8, 'little')
            code.append(0xc3)
            model = library.map_table_x86_sim_xdp
            model.argtypes, model.restype = [c.c_void_p], c.c_int
            pointer, tag = c.c_uint64.in_dll(library, 'observed_pointer'), c.c_uint.in_dll(library, 'observed_tag')
            with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
                memory.write(code)
                native = c.CFUNCTYPE(c.c_void_p, c.c_void_p)(c.addressof(c.c_char.from_buffer(memory)))
                for index in [*range(8), 8, 0xffffffff]:
                    context = c.c_uint(index)
                    expected = addresses[f'map{index}'] if index < 8 else 0
                    actual_native = native(c.byref(context)) or 0
                    model(c.byref(context))
                    if actual_native != expected or pointer.value != expected or tag.value != ((6 if is_value else 5) if index < 8 else 0):
                        raise ValueError(f'Capability table mismatch: {is_value}/{index}/{actual_native}/{pointer.value}/{tag.value}')
                    cases.append(dict(value_capability=is_value, index=index, native=actual_native,
                                      simulator=pointer.value, tag=tag.value))
                del native
        finally:
            _ctypes.dlclose(library._handle)
    # Independent dataflow negatives: a private table base may not escape, and
    # a branch into the second instruction must not bypass its definition.
    table_load = next(i for i in body if i.mnemonic == 'mov' and len(i.operands) == 2 and '*8' in i.operands[1])
    load_index = body.index(table_load)
    prior = body[load_index-1]
    successor = body[load_index+1]
    full = (1<<64)-1
    live = replace(successor, mnemonic='mov', operands=('rax', prior.operands[0]), reloc_symbol=None,
        reloc_target=None, effects=gen.NativeEffects(((gen.reg_info(prior.operands[0])[0], full),), (('X86_RAX', full),), 0, 0))
    entered = [replace(i, operands=(hex(table_load.addr),), reloc_target=table_load.addr)
               if i.mnemonic == 'ja' else i for i in body]
    negatives = [('live-private-base', [live if i.addr == successor.addr else i for i in body], 'live private address'),
                 ('external-entry', entered, 'external CFG entry'),
                 ('partial-pointer', [replace(i, operands=('eax', i.operands[1].replace('QWORD', 'DWORD')))
                    if i.addr == table_load.addr else i for i in body], 'outside a lowered table')]
    for name, instructions, message in negatives:
        try:
            gen.render_program('negative', instructions, functions, kind='raw', program_section='socket/negative',
                exit_addr=exit_addr, rodata16=data, trusted_map_bindings=maps)
        except ValueError as error:
            if message not in str(error): raise
        else:
            raise ValueError('Map-table dataflow counterexample accepted: '+name)
    try:
        gen.render_program('missing', body, functions, kind='raw', program_section='socket/missing',
            exit_addr=exit_addr, rodata16=data, trusted_map_bindings=maps[:-1])
    except ValueError as error:
        if 'lacks actual source capability' not in str(error): raise
    else:
        raise ValueError('Unbound map capability accepted')
    (args.output/'result.json').write_text(json.dumps(dict(cases=cases, dataflow_negatives=3, missing_capability_rejected=True,
        proof_sha256=hashlib.sha256((args.build/'fixture.proof.o').read_bytes()).hexdigest(),
        scope='Actual native proof and complete shared simulator host capability identity/tag checks; no BPF acceptance or app execution'), indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
