"""Catch language inference or descriptor loss in measured normal B transport."""
import argparse
import hashlib
import io
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'kprog/x86'))
import trusted_specializer as worker
from memory_b_pipeline import MemoryPipeline, post_pei_frames


def check_frame_observer():
    # A nonzero subprogram frame must survive even when another frame is zero;
    # direct R10 offsets cannot substitute for the allocated stackSize field.
    mir = "---\nname: 'hotspot'\nframeInfo:\n  stackSize: 576\n...\n---\nname: leaf\nframeInfo:\n  stackSize: 0\n...\n"
    if post_pei_frames(mir) != {'hotspot': 576, 'leaf': 0}:
        raise ValueError('Lost a post-PEI subprogram frame')
    for malformed in ('---\nname: missing\nframeInfo: {}\n', '---\n', mir+mir):
        try:
            post_pei_frames(malformed)
        except ValueError:
            continue
        raise ValueError('Incomplete or duplicate MIR frames silently accepted')


def allocated(data):
    return {s.name:hashlib.sha256(s.data()).hexdigest()
            for s in ELFFile(io.BytesIO(data)).iter_sections() if s['sh_flags'] & 2}


def main(a):
    check_frame_observer()
    a.output.mkdir(parents=True,exist_ok=True)
    commands=[]
    def run(command,data,name,fds):
        command=list(map(str,command))
        result=subprocess.run(command,input=data,capture_output=True,pass_fds=fds)
        (a.output/(name+'.stderr')).write_bytes(result.stderr)
        if name.startswith('backend-'):(a.output/(name+'.stdout')).write_bytes(result.stdout)
        commands.append(dict(command=command,returncode=result.returncode))
        (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        result.check_returncode()
        return result.stdout
    pipeline=MemoryPipeline()
    try:
        result=pipeline.compile(worker,a.frontend.read_bytes(),a.bounds,run,a.output/'lowering.json')
        result['allocated_equal_normal_file_pipeline']=(
            {name:value['sha256'] for name,value in result['allocated_sections'].items()}
            == allocated(a.object.read_bytes()))
        if not result['allocated_equal_normal_file_pipeline']:
            raise ValueError('Anonymous stage transport changes allocated B sections')
    finally:pipeline.close()
    (a.output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result))


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('frontend','object','bounds','output'):p.add_argument('--'+name,type=Path,required=True)
    main(p.parse_args())
