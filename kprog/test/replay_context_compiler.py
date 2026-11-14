"""Compile an archived generated simulator with optional context B lowering.

Generated C is copied unchanged into cleanable compiler storage. Request facts,
commands and stage outcomes remain in the persistent output directory.
"""
import argparse
from datetime import datetime, timezone
import importlib.util
import json
import os
from pathlib import Path
import resource
import subprocess
import tarfile
import time

ROOT = Path(__file__).resolve().parents[2]


def replay(args):
    args.output.mkdir(parents=True, exist_ok=True)
    args.build.mkdir(parents=True, exist_ok=True)
    start = time.monotonic()
    record = dict(started=datetime.now(timezone.utc).isoformat(), archive=str(args.archive),
                  build=str(args.build), compiler=str(args.tool), scope='Archived generated-C compiler replay')
    (args.output/'started.json').write_text(json.dumps(record, indent=2)+'\n')
    try:
        with tarfile.open(args.archive) as archive:
            member = archive.getmember('request/generated/trusted_x86.bpf.c')
            source = args.build/'trusted_x86.bpf.c'
            source.write_bytes(archive.extractfile(member).read())
            record['generated_c_bytes'] = member.size
            for name in ('kernel.native.o', 'kernel.entry', 'kernel.facts.json', 'generation.metadata.json'):
                (args.output/name).write_bytes(archive.extractfile('request/'+name).read())
        spec = importlib.util.spec_from_file_location('context_replay_worker', ROOT/'kprog/x86/trusted_specializer.py')
        worker = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(worker)
        os.environ['KPROG_BPF_CONTEXT_LOADS'] = '1'
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS'] = '0'

        def run(command):
            command = list(map(str, command))
            began = time.monotonic()
            with (args.output/'current-command.json').open('w') as f:
                json.dump(dict(command=command, started=datetime.now(timezone.utc).isoformat()), f)
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            stdout, stderr = process.communicate()
            row = dict(command=command, returncode=process.returncode,
                       wall_seconds=time.monotonic()-began, stdout=stdout, stderr=stderr)
            with (args.output/'commands.jsonl').open('a') as f:
                f.write(json.dumps(row)+'\n')
            process.check_returncode()

        worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), source,
                                 args.build/'trusted_x86.bpf.o', run, bounds_compiler=args.tool)
        record.update(compiled=True, object=str(args.build/'trusted_x86.bpf.o'),
                      frontend_ir=str(source.with_suffix('.bounds-input.bc')))
    except Exception as error:
        record.update(compiled=False, error=str(error))
        raise
    finally:
        record.update(finished=datetime.now(timezone.utc).isoformat(),
                      wall_seconds=time.monotonic()-start,
                      address_space_limit_bytes=resource.getrlimit(resource.RLIMIT_AS)[0])
        (args.output/'result.json').write_text(json.dumps(record, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('archive', 'build', 'output', 'tool'):
        parser.add_argument('--'+name, type=Path, required=True)
    replay(parser.parse_args())
