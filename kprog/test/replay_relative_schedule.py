"""Replay an archived real request through production table lowering."""
import argparse
from dataclasses import asdict
import hashlib
import json
from pathlib import Path
import sys
import subprocess
import tarfile
import traceback

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86'), str(ROOT/'kprog/x86/micro-prog')]
import trusted_specializer as worker


def main(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    with tarfile.open(args.archive) as archive:
        proof = archive.extractfile('request/generated/trusted_x86.proof.o').read()
        metadata = json.load(archive.extractfile('request/generation.metadata.json'))
        functions = json.load(archive.extractfile('request/generated/kernel-functions.json'))
        entry = archive.extractfile('request/kernel.entry').read().decode()
    path = args.build/'replay.proof.o'
    path.write_bytes(proof)
    body, subs, end, data = worker.gen.parse_proof_object_program('replay', args.build)
    result = dict(entry=entry, proof_sha256=hashlib.sha256(proof).hexdigest(),
        instructions=len(body), source_archive=str(args.archive), generated=False)
    try:
        source = worker.gen.render_program('trusted_x86', body, subs,
            kind=worker.context_kind(metadata['prog_type']), program_section=metadata['section'],
            exit_addr=end, rodata16=data,
            trusted_map_bindings=[dict(native_symbol=m['name'], value_offset=m.get('value_offset'))
                                 for m in metadata['maps']], kernel_functions=functions)
    except ValueError as error:
        result['error'] = str(error)
        frame = error.__traceback__
        while frame:
            values = frame.tb_frame.f_locals
            if frame.tb_frame.f_code.co_name == 'lower_relative_tables' and 'candidate' in values:
                candidate = values['candidate']
                result['candidate'] = dict(symbol=candidate['symbol'], scratch=candidate['scratch'],
                    window=[asdict(i) for i in candidate['window']],
                    scheduled=[asdict(i) for i in candidate['scheduled']])
                if 'instruction' in values: result['offending_instruction'] = asdict(values['instruction'])
            frame = frame.tb_next
        (args.output/'traceback.txt').write_text(traceback.format_exc())
    else:
        path = args.build/'replay.bpf.c'
        path.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
            '#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
        result.update(generated=True, generated_c_bytes=path.stat().st_size,
            generated_c_sha256=hashlib.sha256(path.read_bytes()).hexdigest())
        if args.compile:
            def run(command):
                completed = subprocess.run(list(map(str,command)), text=True, capture_output=True)
                with (args.output/'commands.jsonl').open('a') as log:
                    log.write(json.dumps(dict(command=list(map(str,command)), returncode=completed.returncode,
                        stdout=completed.stdout, stderr=completed.stderr))+'\n')
                completed.check_returncode()
            obj = args.build/'replay.bpf.o'
            try:
                worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), path, obj, run,
                    bounds_compiler=args.bounds)
                result.update(b_generated=True, object_bytes=obj.stat().st_size,
                    object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest())
            finally:
                (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
                with tarfile.open(args.output/'build.tar.gz','w:gz') as archive:
                    archive.add(args.build, arcname='build')
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in {'candidate','offending_instruction'}}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('archive', 'build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--compile', action='store_true')
    parser.add_argument('--bounds', type=Path)
    main(parser.parse_args())
