"""Catch language inference or descriptor loss in measured normal B transport."""
import argparse
import hashlib
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import time
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
        started=time.monotonic()
        with (a.output/(name+'.stderr')).open('wb') as errors:
            process=subprocess.Popen(command,stdin=subprocess.PIPE,stdout=subprocess.PIPE,
                                     stderr=errors,pass_fds=fds)
            process.stdin.write(data)
            process.stdin.close()
            stdout=process.stdout.read()
            _,status,usage=os.wait4(process.pid,0)
            process.returncode=os.waitstatus_to_exitcode(status)
        if name.startswith('backend-'):(a.output/(name+'.stdout')).write_bytes(stdout)
        commands.append(dict(command=command,returncode=process.returncode,
            wall_seconds=time.monotonic()-started,user_seconds=usage.ru_utime,
            system_seconds=usage.ru_stime,max_rss_kib=usage.ru_maxrss,
            stdout_bytes=len(stdout),stdout_sha256=hashlib.sha256(stdout).hexdigest()))
        (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if process.returncode:
            raise subprocess.CalledProcessError(process.returncode,command)
        return stdout
    pipeline=MemoryPipeline()
    try:
        frontend=a.frontend.read_bytes()
        result=pipeline.compile(worker,frontend,a.bounds,run,a.output/'lowering.json')
        result.update(frontend_sha256=hashlib.sha256(frontend).hexdigest(),
            bounds_sha256=hashlib.sha256(a.bounds.read_bytes()).hexdigest(),
            reference_object_sha256=hashlib.sha256(a.object.read_bytes()).hexdigest())
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
