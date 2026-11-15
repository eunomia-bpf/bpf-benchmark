"""Measure current OTel production frontend stages with matching captured metadata."""
import argparse
import fcntl
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'kprog/fidelity'),str(ROOT/'kprog/x86'),str(ROOT/'kprog/test')]
import scale
import trusted_specializer as worker
from measure_preprocessor_expansion import measure_stream


def digest(path):
    with path.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()


def main(a):
    a.output.mkdir(parents=True,exist_ok=True);a.build.mkdir(parents=True,exist_ok=True)
    metadata=json.loads(a.metadata.read_text());entry=a.entry.read_text().strip()
    if entry!='perf_unwind_hotspot' or metadata['prog_type']!=7:
        raise ValueError('Captured entry/type do not identify this perf hotspot measurement')
    if metadata['kernel_kfunc_context']:
        raise ValueError('This captured measurement requires a kernel-function ABI inventory')
    worker.declarations(metadata)
    record=dict(entry=entry,metadata=str(a.metadata),metadata_sha256=digest(a.metadata),prog_type=metadata['prog_type'],
        provenance='Current unified-flag native object plus historical matching perf-entry map/type metadata; no fresh application capture or equal-work claim',
        scope='Production proof, render and chunk preprocessing only; no LLVM B backend or kernel submission')
    commands=[];started=time.monotonic()
    def run(command):
        log=a.output/f'command-{len(commands):03d}.log'
        code=scale.run(command,log)
        commands.append(json.loads(log.with_suffix(log.suffix+'.resources.json').read_text()))
        (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if code:raise subprocess.CalledProcessError(code,list(map(str,command)))
    try:
        # Shared kernel/native/linker inputs are consumed only in this block.
        # The expensive optimized LLVM stage below uses our canonical CPP and
        # system toolchain, so it must not hold up another lane's image writer.
        lock_path=Path('/workspaces/.agent-state/kprog-lanes/locks/image')
        with lock_path.open('a') as capture_lock:
            fcntl.flock(capture_lock.fileno(),fcntl.LOCK_SH)
            record['input_lock_wait_seconds']=time.monotonic()-started
            release=Path('/workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release').read_text().strip()
            native=ROOT/f'vendor/build/native-bpf/x86/{release}/native/otel/otelcol-ebpf-profiler.native.o'
            linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
            record.update(native=str(native),native_sha256=digest(native),linker_sha256=digest(linker))
            record.update(simulator_header_sha256=digest(ROOT/'kprog/x86/x86_sim_local_bpf.h'),
                          specializer_sha256=digest(ROOT/'kprog/x86/trusted_specializer.py'),
                          source_head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip())
            proof=a.build/'trusted_x86.proof.o'
            run([linker,'--input',native,'--symbol',entry,'--mode','proof','--preserve-entry-abi','--output',proof])
            record['proof_sha256']=digest(proof)
            insns,functions,exit_addr,data=worker.gen.parse_native_linked_program('trusted_x86',a.build)
            record.update(native_instructions=len(insns),maps=len(metadata['maps']))
            source=a.build/'trusted_x86.bpf.c'
            text=worker.gen.render_program('trusted_x86',insns,functions,kind=worker.context_kind(metadata['prog_type']),
                exit_addr=exit_addr,rodata16=data,program_section=metadata['section'],
                trusted_map_bindings=[dict(native_symbol=m['name'],value_offset=m.get('value_offset')) for m in metadata['maps']])
            source.write_text(text.replace('#include "../x86_sim_local_bpf.h"','#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
            record['source_sha256']=digest(source)
            expanded=worker.preprocess_simulator(str(ROOT/'kprog/stock-path/bin/clang'),source,run)
            with expanded.open('rb') as stream:record.update(measure_stream(source,stream,expanded.stat().st_size))
            record.update(preprocessed_sha256=digest(expanded),completed=True)
        record['input_lock_released_before_frontend']=True
        if a.frontend:
            # This is the exact first LLVM stage of compile_simulator, with
            # the same flags/product path. Stop here to isolate its resource
            # cost before bounds/MIR/packing, rather than running a huge B
            # backend without knowing which stage still grows.
            initial=source.with_suffix('.bounds-input.bc')
            record.update(completed=False,frontend_completed=False,
                scope='Production proof/render/chunk CPP and normal optimized LLVM frontend; no bounds, MIR, B backend or kernel submission')
            (a.output/'result.json').write_text(json.dumps(record,indent=2)+'\n')
            run([ROOT/'kprog/stock-path/bin/clang',*worker.COMPILE_FLAGS,
                 '-emit-llvm','-c',expanded,'-o',initial])
            record.update(completed=True,frontend_completed=True,frontend_bytes=initial.stat().st_size,
                          frontend_sha256=digest(initial))
    except (OSError,ValueError,RuntimeError,subprocess.CalledProcessError) as error:
        record.update(completed=False,error=str(error));raise
    finally:
        record['wall_seconds']=time.monotonic()-started
        (a.output/'result.json').write_text(json.dumps(record,indent=2)+'\n')
        print(json.dumps(record),flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('build','output','metadata','entry'):p.add_argument('--'+n,type=Path,required=True)
    p.add_argument('--frontend',action='store_true',help='Also measure the exact normal optimized LLVM frontend stage')
    main(p.parse_args())
