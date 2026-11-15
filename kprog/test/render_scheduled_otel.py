"""Measure current OTel proof-to-shared-C lowering without a large backend job."""
import argparse
import hashlib
import json
from pathlib import Path
import sys
import time

ROOT=Path(__file__).resolve().parents[2]

def main(args):
    sys.path[:0]=[str(ROOT/'kprog'),str(ROOT/'kprog/x86'),str(ROOT/'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    args.output.mkdir(parents=True,exist_ok=True)
    proof=args.build/'otel.proof.o'
    result=dict(proof=str(proof),proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(),
        scope='Actual current OTel production proof to shared simulator C only; no B backend, source-context binding, kernel acceptance or application execution')
    started=time.monotonic()
    try:
        body,functions,exit_addr,data=worker.gen.parse_proof_object_program('otel',args.build)
        result.update(native_instructions=len(body),functions=len(functions))
        source=worker.gen.render_program('otel_hotspot_model',body,functions,kind='raw',
            program_section='kprobe/otel_hotspot',exit_addr=exit_addr,rodata16=data)
        generated=args.build/'otel.bpf.c'
        generated.write_text(source.replace('#include "../x86_sim_local_bpf.h"','#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
        result.update(generated=True,generated_c_bytes=generated.stat().st_size,
            generated_sha256=hashlib.sha256(generated.read_bytes()).hexdigest())
    except (ValueError,RuntimeError) as error:
        result.update(generated=False,error=str(error))
        raise
    finally:
        result['wall_seconds']=time.monotonic()-started
        (args.output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
        print(json.dumps(result),flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('build','output'):p.add_argument('--'+name,type=Path,required=True)
    main(p.parse_args())
