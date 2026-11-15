"""Execute checked native code compiled from the already-stock-accepted table B."""
import argparse
import ctypes
import hashlib
import json
import mmap
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    accepted = json.loads(args.accepted.read_text())
    if digest(args.build/'trusted_x86.bpf.o') != accepted['bpf_sha256']:
        raise ValueError('Current B differs from the retained stock-accepted input')
    sys.path.insert(0, str(ROOT/'kprog'))
    from trusted_service import adapter
    worker = adapter(1)
    source = args.build/'trusted_x86.bpf.i'
    frontend = args.build/'trusted_x86.bpf.bounds-input.bc'
    artifacts = dict(simulator_preprocessed=str(source), simulator_program='trusted_x86_x86_sim_xdp',
        native_object=str(args.build/'table.native.o'), symbol='jump_table', context_kind='raw',
        simulator_frontend=dict(path=str(frontend), source_sha256=digest(source), ir_sha256=digest(frontend)))
    compiled = worker.compile_checked_simulator(artifacts, args.linker, args.compiler)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result.stdout

    binary = args.build/'checked-table.bin'
    # The real loader adds this direct-value capability for checked C. Bind it
    # explicitly in the host test as well, rather than using a shared-object
    # link that bypasses the normal native linker/map-patch ABI.
    unspecified = ctypes.c_uint64(0)
    plan = json.loads((args.build/'plan.json').read_text())
    plan['maps'] = [dict(name='kprog_unspecified_input', addr=ctypes.addressof(unspecified))]
    plan_path = args.build/'checked-table-plan.json'
    plan_path.write_text(json.dumps(plan, indent=2)+'\n')
    run([args.linker, '--input', compiled['native_proof_object'], '--symbol', compiled['symbol'],
         '--mode', 'kernel', '--link-plan', plan_path, '--output', binary,
         '--output-relocs', args.build/'checked-table.relocs',
         '--output-map-patches', args.build/'checked-table.maps', '--output-abi', args.build/'checked-table.abi'])
    if (args.build/'checked-table.relocs').read_bytes():
        raise ValueError('Local checked table unexpectedly requires helper relocation')
    cases = []
    code = bytearray(binary.read_bytes())
    patches = (args.build/'checked-table.maps').read_text().splitlines()
    if len(patches) != 1 or patches[0].split('\t')[0] != 'kprog_unspecified_input':
        raise ValueError('Checked native lost its exact private input-map capability')
    offset = int(patches[0].split('\t')[1])
    code[offset:offset+8] = ctypes.addressof(unspecified).to_bytes(8, 'little')
    code.append(0xc3)
    with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as memory:
        memory.write(code)
        execute = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64))(
            ctypes.addressof(ctypes.c_char.from_buffer(memory)))
        for seed in range(32):
            values = [(seed*0x9e3779b97f4a7c15+i*0xd1b54a32d192ed03) & ((1<<64)-1) for i in range(11)]
            oracle = [values[0]+17, values[1]*3, values[2]^0x1234, values[3]-29,
                      values[4]|0x8000, values[5]&0x7fff, values[6]+71, values[7]*5]
            for index in range(16):
                unspecified.value = (seed*0xfedcba9876543210+index) & ((1<<64)-1)
                values[10] = index
                actual = execute((ctypes.c_uint64*11)(*values))
                expected = (oracle[index] if index < 8 else 0) & 0xffffffff
                if actual != expected:
                    raise ValueError(f'Checked native mismatch {seed}/{index}: {actual} != {expected}')
                cases.append(dict(seed=seed, index=index, actual=actual, expected=expected))
    native = Path(compiled['native_object'])
    with native.open('rb') as stream:
        elf = ELFFile(stream)
        native_bytes = sum(section['sh_size'] for section in elf.iter_sections() if section['sh_flags'] & 4)
    result = dict(cases=cases, bpf_sha256=accepted['bpf_sha256'], checked_native_sha256=digest(native),
        checked_kernel_image_sha256=digest(binary), compiler_sha256=digest(args.compiler),
        checked_native_code_bytes=native_bytes, source_frontend_reused=True,
        private_input_capability=plan['maps'][0], private_input_patch_offset=offset,
        scope='Host execution of checked native after real prior B stock acceptance; no checked-native kernel installation or timing')
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    run(['objdump', '-dr', '-Mintel', native])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output', 'linker', 'compiler', 'accepted'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
