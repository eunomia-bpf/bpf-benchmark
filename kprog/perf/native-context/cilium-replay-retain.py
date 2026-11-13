#!/usr/bin/env python3
"""Keep source-replay byte comparisons, including mismatches and all link logs."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil
import tarfile


def digest(path): return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build',type=Path,required=True)
    parser.add_argument('--raw',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    snapshot=args.raw/'build-evidence'
    shutil.copytree(args.build,snapshot)
    units=[]
    for name in ['bpf_lxc','bpf_host','bpf_xdp']:
        record=json.loads((snapshot/(name+'.json')).read_text())
        comparison=json.loads((snapshot/(name+'-comparison.json')).read_text())
        links=json.loads((snapshot/(name+'-links/report.json')).read_text())
        units.append(dict(unit=name,source_inputs=record,comparison=comparison,offline_links=links))
    archive=args.output.with_suffix('.tar.gz')
    with tarfile.open(archive,'x:gz') as target: target.add(args.raw,arcname=args.raw.name)
    files=0
    with tarfile.open(archive) as target:
        for member in target.getmembers():
            if not member.isfile(): continue
            with target.extractfile(member) as stream:
                if hashlib.sha256(stream.read()).hexdigest()!=digest(args.raw.parent/member.name): raise ValueError('archive bytes differ: '+member.name)
            files+=1
    receipt=dict(recorded_at=datetime.now(timezone.utc).isoformat(),raw=str(args.raw),
                 compiler_protocol_commit='c4135e82c',units=units,verifier_submissions=0,native_installs=0,
                 conclusion='Fresh TC host/endpoint direct source builds match all allocated sections and relocations. XDP remains different; generated feature config was not captured in the first job. Both direct and extra-optimized IR outputs are retained.',
                 limits=['No new compiler candidate executed in an application.',
                         'XDP feature-header explanation awaits actual generated config capture/replay.',
                         'Existing successful offline links do not certify matching configuration or equal work.'],
                 archive=dict(path=str(archive),bytes=archive.stat().st_size,sha256=digest(archive),files_byte_compared=files))
    with args.output.open('x') as output: json.dump(receipt,output,indent=2);output.write('\n')


if __name__=='__main__': main()
