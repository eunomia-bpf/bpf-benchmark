"""Run the real trusted queue/worker/compiler/loader/native positive control."""
import json
import hashlib
import os
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[2]
CASE=sys.argv[1] if len(sys.argv)==2 else 'control'
if CASE not in {'control','bcc'}:raise ValueError('unknown trusted service case')
OUT=ROOT/'corpus/results/kprog_app_coverage_20261107'/('trusted-service-bcc' if CASE=='bcc' else 'trusted-service')
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
    environment=dict(os.environ)
    if CASE=='bcc':
        environment.update(LD_PRELOAD=str(ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so'),
            BPFREJIT_SHIM_NATIVE_LOADER='1',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
            BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1',
            BPFREJIT_NATIVE_LOADER_SO=str(ROOT/'kprog/libnativeloader/build/libnative_loader.so'),
            BPFREJIT_SHIM_NATIVE_MANIFEST=str(ROOT/'vendor/build/native-bpf/x86/stage/bcc/manifest.json'),
            BPFREJIT_SHIM_LOG=str(OUT/'shim.log'))
        argv=[ROOT/'vendor/build/x86/bcc/bin/vfsstat','-v','1','1']
    else:
        argv=[ROOT/'kprog/libnativeloader/build/trusted-service-client',
              ROOT/'kprog/libnativeloader/build/trusted-native.o']
    result=subprocess.run(argv,env=environment,text=True,capture_output=True)
    (OUT/'client.stdout').write_text(result.stdout)
    (OUT/'client.stderr').write_text(result.stderr)
    if result.returncode:
        (OUT/'summary.json').write_text(json.dumps(dict(ok=False,returncode=result.returncode),indent=2))
    result.check_returncode()
    if CASE=='bcc':
        records=[json.loads(line) for line in (state/'requests.jsonl').read_text().splitlines()]
        if not records or any(record['status'] for record in records):
            raise RuntimeError('BCC did not complete all required trusted native requests')
        for record in records:log+=service.stdout.readline()
        summary=dict(ok=True,app='bcc/vfsstat',completed_requests=records)
    else:
        summary=json.loads(result.stdout)
        assert summary['ok'] and summary['retval']==2
        line=service.stdout.readline();log+=line
        completion=json.loads(line)
        if completion['status'] or completion['prog_id'] != summary['native_prog_id']:
            raise RuntimeError('service evidence did not finish for the completed native request')
        summary['request_id']=completion['request_id']
    inputs=[ROOT/'kprog/tv/build-kernel-x86/arch/x86/boot/bzImage',
            ROOT/'kprog/tv/build-x86/bpf_x86_native_lab.ko',Path(argv[0])]
    if CASE=='bcc':
        inputs.extend([ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so',
            ROOT/'kprog/libnativeloader/build/libnative_loader.so',
            ROOT/'vendor/build/native-bpf/x86/stage/bcc/manifest.json',
            ROOT/'vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o'])
    else:inputs.append(ROOT/'kprog/libnativeloader/build/trusted-native.o')
    summary['artifact_sha256']={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
finally:
    service.terminate()
    tail=service.communicate()[0];log+=tail
    (OUT/'service.log').write_text(log)
