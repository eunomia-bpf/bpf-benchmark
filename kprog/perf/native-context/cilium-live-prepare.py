#!/usr/bin/env python3
"""Retain a completed live-config run and expose its generated baseline state."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import tarfile


def digest(path): return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--raw',type=Path,required=True)
    parser.add_argument('--capture',type=Path,required=True)
    parser.add_argument('--run',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--baseline-snapshot',default='baseline-0001')
    args=parser.parse_args()
    snapshots=[]
    for path in sorted(args.capture.glob('*-*/cilium-config.tar.gz')):
        with tarfile.open(path) as source:
            index=json.load(source.extractfile('capture.json'))
            if path.parent.name==args.baseline_snapshot:
                state=args.raw/'baseline-state';state.mkdir()
                source.extractall(state,filter='data')
        snapshots.append(dict(path=str(path),bytes=path.stat().st_size,sha256=digest(path),index=index))
    app=json.loads((args.run/'details/apps/cilium__agent.json').read_text())
    shim=args.run/'details/shim-logs/cilium__agent.post_rejit.log'
    archive=args.output.with_suffix('.tar.gz')
    roots=[args.raw,args.capture,args.run]
    with tarfile.open(archive,'x:gz') as target:
        for path in roots: target.add(path,arcname=path.name)
    files=0
    with tarfile.open(archive) as target:
        for member in target.getmembers():
            if not member.isfile(): continue
            name,*rest=Path(member.name).parts
            original=next(path for path in roots if path.name==name).joinpath(*rest)
            with target.extractfile(member) as stream:
                if hashlib.sha256(stream.read()).hexdigest()!=digest(original): raise ValueError('archive bytes differ: '+member.name)
            files+=1
    result=dict(recorded_at=datetime.now(timezone.utc).isoformat(),run=str(args.run),raw=str(args.raw),
                make_exit=int((args.raw/'job/exit-code').read_text()),app_status=app['status'],app_error=app['error'],
                programs={phase:len(app[phase]['bpf']) for phase in ['baseline','post_rejit']},
                native_replacements=shim.read_text().count('native-loader replaced prog='),
                observer_exit=int((args.capture/'observer-exit-code').read_text()),snapshots=snapshots,
                extracted_baseline_snapshot=args.baseline_snapshot,
                limits=['One-sample1s diagnostic; default manifest and objects, not the new upstream compiler candidate.',
                        'Snapshots may catch objects mid-build; each captured length and raw partial bytes are retained.',
                        'No app-decision or throughput equivalence certified.'],
                archive=dict(path=str(archive),bytes=archive.stat().st_size,sha256=digest(archive),files_byte_compared=files))
    with args.output.open('x') as output: json.dump(result,output,indent=2);output.write('\n')


if __name__=='__main__': main()
