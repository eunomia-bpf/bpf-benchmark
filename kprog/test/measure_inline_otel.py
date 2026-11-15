"""Measure the current OTel inline interpreter without replacing a live job's input.

Generated C and preprocessed tokens travel through pipes. Only measurements,
commands and diagnostics persist; no second OTel build directory is created.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog/test')]
import trusted_specializer as worker


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    metadata = json.loads(a.metadata.read_text())
    previous = json.loads(a.previous.read_text())
    proof = a.build/'trusted_x86.proof.o'
    sha = lambda data: hashlib.sha256(data).hexdigest()
    if sha(proof.read_bytes()) != previous['proof_sha256']:
        raise ValueError('Live proof differs from the recorded compiler input')
    if sha(a.metadata.read_bytes()) != previous['metadata_sha256']:
        raise ValueError('Metadata does not match the captured proof measurement')
    if metadata['prog_type'] != 7 or previous['entry'] != 'perf_unwind_hotspot':
        raise ValueError('Expected the actual perf hotspot input')
    if metadata['kernel_kfunc_context']:
        raise ValueError('Kernel function inventory is required for this input')
    worker.declarations(metadata)
    instructions, functions, exit_address, data = worker.gen.parse_native_linked_program('trusted_x86', a.build)
    source = worker.gen.render_program('trusted_x86', instructions, functions,
        kind=worker.context_kind(metadata['prog_type']), exit_addr=exit_address,
        rodata16=data, program_section=metadata['section'],
        trusted_map_bindings=[dict(native_symbol=m['name'], value_offset=m.get('value_offset'))
                              for m in metadata['maps']])
    source = source.replace('#include "../x86_sim_local_bpf.h"',
                            '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))).encode()
    record = dict(source_head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
        entry=previous['entry'], native_sha256=previous['native_sha256'],
        proof_sha256=previous['proof_sha256'], metadata_sha256=previous['metadata_sha256'],
        native_instructions=len(instructions), generated_bytes=len(source), source_sha256=sha(source),
        inline_header_sha256=sha((ROOT/'kprog/x86/x86_sim_inline.h').read_bytes()),
        simulator_header_sha256=sha((ROOT/'kprog/x86/x86_sim_local_bpf.h').read_bytes()),
        commands=[], completed=False,
        scope='Same captured OTel proof/map metadata; streamed current C/CPP and normal-O3 frontend to null, no B/stack/kernel/application result')
    result = a.output/'result.json'

    def run(command, data, name):
        command = list(map(str, command))
        measured = ['/usr/bin/time', '-v', '-o', str(a.output/(name+'.resources.txt')), *command]
        start = time.monotonic()
        process = subprocess.run(measured, input=data, capture_output=True)
        (a.output/(name+'.stderr')).write_bytes(process.stderr)
        record['commands'].append(dict(command=measured, returncode=process.returncode,
            seconds=time.monotonic()-start, stdin_bytes=len(data), stdin_sha256=sha(data),
            stdout_bytes=len(process.stdout), stdout_sha256=sha(process.stdout)))
        result.write_text(json.dumps(record, indent=2)+'\n')
        process.check_returncode()
        return process.stdout

    flags = [str(x) for x in worker.COMPILE_FLAGS]
    clang = ROOT/'kprog/stock-path/bin/clang'
    expanded = run([clang, *flags, '-x', 'c', '-E', '-', '-o', '-'], source, 'preprocess')
    record.update(preprocessed_bytes=len(expanded), preprocessed_sha256=sha(expanded),
                  expansion=len(expanded)/len(source))
    result.write_text(json.dumps(record, indent=2)+'\n')
    if a.frontend:
        run([clang, *flags, '-x', 'cpp-output', '-', '-emit-llvm', '-c', '-o', '/dev/null'],
            expanded, 'frontend')
        record['frontend_completed'] = True
    record['completed'] = True
    result.write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps(record), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'metadata', 'previous', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--frontend', action='store_true')
    main(parser.parse_args())
