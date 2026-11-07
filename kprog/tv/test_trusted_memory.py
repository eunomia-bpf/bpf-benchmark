"""Exercise shared inline-memory binding through the common trusted service."""
from pathlib import Path
import hashlib
import io
import json
import subprocess
import sys
import tarfile
import time

ROOT=Path(__file__).resolve().parents[2]


def clients():
    for case in ['8','32','96','unsafe']:
        obj=ROOT/('kprog/tv/build/trusted-memory-'+case+'.o')
        result=subprocess.run([str(ROOT/'kprog/libnativeloader/build/trusted-service-client'),str(obj)],
            capture_output=True,text=True)
        print(json.dumps(dict(case=case,object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),
            returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)),flush=True)
        if case=='unsafe':
            if result.returncode==0:
                raise RuntimeError('unsafe destination reached native execution')
        else:
            result.check_returncode()
            actual=json.loads(result.stdout)
            if not actual['ok'] or actual['retval']!=2 or actual['prebuilt_proof']:
                raise RuntimeError('bound copy/fill bytes or pointer result differs')


def main():
    archive=ROOT/'kprog/tv/build'/('trusted-memory-service-'+str(time.time_ns())+'.tar.gz')
    subprocess.run([
        sys.executable,str(ROOT/'kprog/trusted_service.py'),'--arch','1',
        '--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer',
        '--state',str(ROOT/'kprog/tv/build/trusted-memory-state'),
        '--native-link',str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'),
        '--loader',str(ROOT/'kprog/libnativeloader/build/trusted-native-loader'),
        '--results',str(archive),'--run',sys.executable,str(Path(__file__).resolve()),'--clients'],check=True)
    success=[]
    failure=[]
    with tarfile.open(archive,'r:gz') as outer:
        for member in outer:
            if member.name.endswith('.success.tar.gz'):
                success.append(member.name)
            if member.name.endswith('.failure.tar.gz'):
                with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read()),mode='r:gz') as terminal:
                    stderr=terminal.extractfile('request/load.stderr').read().decode()
                    if 'BPF_PROG_LOAD native_lab stub' not in stderr or 'invalid mem access' not in stderr:
                        raise RuntimeError('unsafe control requires actual verifier scalar-address rejection: '+stderr[:2000])
                    failure.append(dict(name=member.name,stderr=stderr))
    if len(success)!=3 or len(failure)!=1:
        raise RuntimeError('expected three bound controls and one verifier rejection')
    print(json.dumps(dict(archive=str(archive.relative_to(ROOT)),sha256=hashlib.sha256(archive.read_bytes()).hexdigest(),
        successes=success,verifier_rejections=failure)),flush=True)
    print('trusted inline-memory binding: PASS',flush=True)


if __name__=='__main__':
    clients() if sys.argv[1:]==['--clients'] else main()
