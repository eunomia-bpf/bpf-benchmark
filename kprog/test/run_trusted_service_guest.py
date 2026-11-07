"""Run the real trusted queue/worker/compiler/loader/native positive control."""
import json
import hashlib
import os
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[2]
OUT=ROOT/'corpus/results/kprog_app_coverage_20261107/trusted-service'
OUT.mkdir(exist_ok=True)
state=OUT/'requests'
state.mkdir(mode=0o700)
service=subprocess.Popen([sys.executable,ROOT/'kprog/trusted_service.py',
    '--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer',
    '--state',state,'--native-link',ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
    '--loader',ROOT/'kprog/libnativeloader/build/trusted-native-loader'],
    text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
log=''
try:
    line=service.stdout.readline();log+=line
    if not line or not json.loads(line).get('ready'):
        raise RuntimeError('trusted service did not register: '+line)
    result=subprocess.run([ROOT/'kprog/libnativeloader/build/trusted-service-client',
        ROOT/'kprog/libnativeloader/build/trusted-native.o'],text=True,capture_output=True)
    (OUT/'client.stdout').write_text(result.stdout)
    (OUT/'client.stderr').write_text(result.stderr)
    result.check_returncode()
    summary=json.loads(result.stdout)
    assert summary['ok'] and summary['retval']==2
    line=service.stdout.readline();log+=line
    completion=json.loads(line)
    if completion['status'] or completion['prog_id'] != summary['native_prog_id']:
        raise RuntimeError('service evidence did not finish for the completed native request')
    summary['request_id']=completion['request_id']
    summary['artifact_sha256']={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in (
        ROOT/'kprog/tv/build-kernel-x86/arch/x86/boot/bzImage',
        ROOT/'kprog/tv/build-x86/bpf_x86_native_lab.ko',
        ROOT/'kprog/libnativeloader/build/trusted-native.o',
        ROOT/'kprog/libnativeloader/build/trusted-service-client')}
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
finally:
    service.terminate()
    tail=service.communicate()[0];log+=tail
    (OUT/'service.log').write_text(log)
