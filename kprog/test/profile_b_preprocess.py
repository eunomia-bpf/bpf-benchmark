"""Measure current small scale inputs at the real Clang preprocessing stage."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog/fidelity'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/test')]
import scale
import trusted_specializer as worker
from measure_preprocessor_expansion import measure_stream
from elftools.elf.elffile import ELFFile


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    args.build.mkdir(parents=True, exist_ok=True)
    records = []
    for size in args.sizes:
        for pointer in (False, True):
            for indirect in (False, True):
                name = f'n{size}_{"ptr" if pointer else "scalar"}_{"indirect" if indirect else "direct"}'
                commands = []

                def run(command, stage):
                    log = args.output/(name+'.'+stage+'.log')
                    status = scale.run(command, log)
                    command_record = json.loads(log.with_suffix(log.suffix+'.resources.json').read_text())
                    commands.append(command_record)
                    (args.output/(name+'.commands.json')).write_text(json.dumps(commands, indent=2)+'\n')
                    if status: raise RuntimeError(f'{name}/{stage} exited {status}; see {log}')

                assembly, _ = scale.assembly(size, pointer, indirect)
                native_source, native = args.build/(name+'.S'), args.build/(name+'.native.o')
                native_source.write_text(assembly)
                run(['cc', '-c', native_source, '-o', native], 'native')
                run(['objdump', '-dr', '-Mintel', '--insn-width=16', native], 'objdump')
                instructions = scale.encoder.parse_asm_text((args.output/(name+'.objdump.log')).read_text())
                text = scale.encoder.render_program(name, instructions)
                source, expanded = args.build/(name+'.bpf.c'), args.build/(name+'.bpf.i')
                source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',
                    '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
                # These small inputs fit one normal production piece. This
                # measures the same frontend flags/macros; no backend is run.
                run([ROOT/'kprog/stock-path/bin/clang', *worker.COMPILE_FLAGS, '-E', source, '-o', expanded], 'preprocess')
                with expanded.open('rb') as stream:
                    record = measure_stream(source, stream, expanded.stat().st_size)
                calls = Counter()
                switches = 0
                with expanded.open() as stream:
                    for line in stream:
                        switches += line.count('switch (')
                        calls.update(re.findall(r'\bbpf_[A-Za-z0-9_]+\s*\(', line))
                record.update(name=name, requested_native_instructions=size, native_instructions=len(instructions),
                    native_sha256=digest(native), generated_sha256=digest(source), preprocessed_sha256=digest(expanded),
                    helper_call_like_tokens=dict(calls), switch_tokens=switches,
                    scope='Current generator and real one-piece Clang -E only; no new B compilation or kernel acceptance')
                if args.compile:
                    compiled = args.build/(name+'.bpf.o')
                    worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), source, compiled,
                        lambda command: run(command, 'compile-'+str(len(commands))),
                        bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
                    with compiled.open('rb') as stream:
                        elf = ELFFile(stream)
                        record['allocated_sections'] = {section.name: dict(bytes=section.data_size,
                            sha256=hashlib.sha256(section.data()).hexdigest())
                            for section in elf.iter_sections() if section['sh_flags'] & 2}
                        depths, code_bytes = [], 0
                        for section in elf.iter_sections():
                            if not section['sh_flags'] & 4:
                                continue
                            code = section.data()
                            code_bytes += len(code)
                            for opcode, registers, offset, immediate in struct.iter_unpack('<BBhi', code):
                                kind = opcode & 7
                                if kind in (1, 2, 3) and opcode & 0xe0 in (0x60, 0xc0):
                                    base = registers >> 4 if kind == 1 else registers & 15
                                    if base == 10 and offset < 0:
                                        depths.append(-offset)
                        record['bpf_code_bytes'] = code_bytes
                        record['deepest_direct_fp_access'] = max(depths, default=0)
                        # This observes direct R10 accesses, not every derived
                        # stack address; it is a lower bound on frame size.
                    record['scope'] += '; normal production B backend compiled, not submitted to kernel'
                records.append(record)
                (args.output/'result.json').write_text(json.dumps(records, indent=2)+'\n')
                print(json.dumps(dict(name=name, expanded=record['preprocessed_bytes'],
                    source=record['generated_c_bytes'], helpers=dict(calls), switches=switches)), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compile', action='store_true', help='Also compile through the normal production B pipeline')
    parser.add_argument('--sizes', nargs='+', type=int, required=True)
    for name in ('build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
