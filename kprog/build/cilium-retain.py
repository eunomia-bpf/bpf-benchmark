#!/usr/bin/env python3
"""Retain compiler artifacts, original config data, and all packet experiment logs."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tarfile


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--raw',type=Path,required=True)
    parser.add_argument('--upstream-build',type=Path,required=True)
    parser.add_argument('--packet-build',type=Path,required=True)
    parser.add_argument('--compiler',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    shutil.copytree(args.upstream_build,args.raw/'upstream-evidence')
    shutil.copytree(args.packet_build,args.raw/'packet-evidence')
    shutil.copy2(args.compiler,args.raw/'socket-context-lower')
    units=[]
    for source in sorted(args.upstream_build.glob('*.json')):
        row=json.loads(source.read_text())
        links=args.upstream_build/(source.stem+'-links')/'report.json'
        units.append(dict(unit=source.stem,frontend=row,offline_links=json.loads(links.read_text()),
                          bpf_object_sha256=digest(source.with_suffix('.bpf.o')),
                          native_object_sha256=digest(source.with_suffix('.native.o'))))
    archive=args.output.with_suffix('.tar.gz')
    with tarfile.open(archive,'x:gz') as target:
        target.add(args.raw,arcname=args.raw.name)
        for unit in units:
            for item in unit['frontend']['configuration']:
                target.add(item['replay_path'],arcname='runtime-config/'+unit['unit']+'/'+Path(item['replay_path']).name)
    files=0
    with tarfile.open(archive) as target:
        for item in target.getmembers():
            if not item.isfile(): continue
            if item.name.startswith('runtime-config/'):
                _,name,header=item.name.split('/')
                unit=next(u for u in units if u['unit']==name)
                original=next(Path(h['replay_path']) for h in unit['frontend']['configuration'] if Path(h['replay_path']).name==header)
            else: original=args.raw.parent/item.name
            with target.extractfile(item) as stream:
                if hashlib.sha256(stream.read()).hexdigest()!=digest(original): raise ValueError('archive bytes differ: '+item.name)
            files+=1
    compiler_source=Path(__file__).with_name('socket-context-lower.cpp')
    receipt=dict(recorded_at=datetime.now(timezone.utc).isoformat(),raw=str(args.raw),
                 upstream_revision=subprocess.check_output(['git','-C','vendor/repos/cilium','rev-parse','HEAD'],text=True).strip(),
                 kernel_revision=subprocess.check_output(['git','-C','vendor/linux-framework','rev-parse','HEAD'],text=True).strip(),
                 compiler_commit=subprocess.check_output(['git','log','-1','--format=%H','--',str(compiler_source)],text=True).strip(),
                 compiler_sha256=digest(args.compiler),units=units,
                 socket_code_comparison=json.loads((args.raw/'socket-code-comparison.json').read_text()),
                 host_fixture_log=str(args.raw/'check2.log'),
                 verifier_submissions=0,native_installs=0,application_execution=False,
                 default_path_changed=False,
                 limits=['Retained November9 generated runtime configuration, not a new live capture.',
                         'Host/compiler/linker integration only; no application decisions or throughput equivalence certified.',
                         'D23 original-program helper deployment remains with lane verified.'],
                 archive=dict(path=str(archive),bytes=archive.stat().st_size,sha256=digest(archive),files_byte_compared=files))
    with args.output.open('x') as output: json.dump(receipt,output,indent=2);output.write('\n')


if __name__=='__main__': main()
