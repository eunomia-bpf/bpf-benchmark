"""Measure the current OTel inline interpreter without replacing a live job's input.

Generated C and preprocessed tokens travel through pipes. Only measurements,
commands and diagnostics persist; no second OTel build directory is created.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog/test')]
import trusted_specializer as worker
from memory_b_pipeline import MemoryPipeline


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
        commands=[], completed=False, frontend_requested=a.frontend or a.backend,
        scope='Same captured OTel proof/map metadata; streamed current C/CPP with optional normal-O3 frontend to null; no B/stack/kernel/application result')
    result = a.output/'result.json'

    def run(command, data, name, fds=()):
        command = list(map(str, command))
        start = time.monotonic()
        with (a.output/(name+'.stderr')).open('wb') as errors, ThreadPoolExecutor(max_workers=1) as writer:
            process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=errors, pass_fds=fds)

            def send():
                try:
                    process.stdin.write(data)
                finally:
                    process.stdin.close()

            sent = writer.submit(send)
            stdout = process.stdout.read()
            _, status, usage = os.wait4(process.pid, 0)
            process.returncode = os.waitstatus_to_exitcode(status)
        record['commands'].append(dict(command=command, returncode=process.returncode,
            seconds=time.monotonic()-start, stdin_bytes=len(data), stdin_sha256=sha(data),
            stdout_bytes=len(stdout), stdout_sha256=sha(stdout),
            user_seconds=usage.ru_utime, system_seconds=usage.ru_stime, max_rss_kib=usage.ru_maxrss))
        result.write_text(json.dumps(record, indent=2)+'\n')
        if process.returncode:
            raise subprocess.CalledProcessError(process.returncode, command)
        sent.result()
        if name.startswith('backend-'):
            (a.output/(name+'.stdout')).write_bytes(stdout)
        return stdout

    flags = [str(x) for x in worker.COMPILE_FLAGS]
    clang = ROOT/'kprog/stock-path/bin/clang'
    expanded = run([clang, *flags, '-x', 'c', '-E', '-', '-o', '-'], source, 'preprocess')
    record.update(preprocessed_bytes=len(expanded), preprocessed_sha256=sha(expanded),
                  expansion=len(expanded)/len(source))
    result.write_text(json.dumps(record, indent=2)+'\n')
    if a.frontend or a.backend:
        frontend = run([clang, *flags, '-x', 'cpp-output', '-', '-emit-llvm', '-c', '-o', '-'],
                       expanded, 'frontend')
        record.update(frontend_completed=True, frontend_bytes=len(frontend),
                      frontend_sha256=sha(frontend))
        result.write_text(json.dumps(record, indent=2)+'\n')
        if a.backend:
            pipeline = MemoryPipeline()
            try:
                record['bpf'] = pipeline.compile(worker, frontend,
                    Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'), run,
                    a.output/'lowering.json')
                record['bpf_compiled'] = True
            finally:
                if pipeline.result is not None:
                    record.update(bpf=pipeline.result, bpf_compiled=True)
                    result.write_text(json.dumps(record, indent=2)+'\n')
                pipeline.close()
            record['scope'] = 'Same captured OTel proof/map metadata; normal bounds/MIR/all-pairs/llc via anonymous stage files and post-PEI frame observation; no kernel/application acceptance'
    record['completed'] = True
    result.write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps(record), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'metadata', 'previous', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--frontend', action='store_true')
    parser.add_argument('--backend', action='store_true')
    args = parser.parse_args()
    args.output = args.output/'otel'
    main(args)
