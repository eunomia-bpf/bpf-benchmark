"""Run the kernel-backed service control or actual upstream BCC startup."""
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import queue
import re
import signal
import subprocess
import sys
import tarfile
import tempfile
import threading
import traceback

ROOT=Path(__file__).resolve().parents[2]
CASE=sys.argv[1] if len(sys.argv)==2 else 'control'
if CASE not in {'control','bcc','bcc-set'}:raise ValueError('unknown trusted service case')
OUT=ROOT/'corpus/results/kprog_app_coverage_20261107'/{'control':'trusted-service','bcc':'trusted-service-bcc','bcc-set':'trusted-service-bcc-set'}[CASE]
OUT.mkdir(exist_ok=True)
STAMP=datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
archive=OUT/('run-'+STAMP+'.tar.gz')
summary=dict(ok=False,case=CASE,started=datetime.now(timezone.utc).isoformat(),request_archive=archive.name)

from bcc_set_startup import run_bcc_set

with tempfile.TemporaryDirectory(prefix='.live-',dir=OUT) as temporary:
    live=Path(temporary)
    state=live/'requests'
    state.mkdir(mode=0o700)
    events=queue.Queue()
    reader_errors=[]
    service=subprocess.Popen([sys.executable,ROOT/'kprog/trusted_service.py',
        '--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer',
        '--state',state,'--native-link',ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
        '--loader',ROOT/'kprog/libnativeloader/build/trusted-native-loader'],
        text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,start_new_session=True)
    def collect():
        # Drain continuously: many application loads must not fill stdout and
        # block the persistent service while the app waits for its next proof.
        try:
            with (live/'service.log').open('w') as log:
                for line in service.stdout:
                    log.write(line);log.flush();events.put(line)
        except Exception as error:
            reader_errors.append(str(error))
        finally:
            events.put(None)
    reader=threading.Thread(target=collect)
    reader.start()
    def event():
        line=events.get()
        if line is None:raise RuntimeError('trusted service exited before its expected receipt')
        return json.loads(line)
    try:
        ready=event()
        if not ready.get('ready'):raise RuntimeError('trusted service did not register')
        environment=dict(os.environ)
        if CASE in {'bcc','bcc-set'}:
            environment.update(LD_PRELOAD=str(ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so'),
                BPFREJIT_SHIM_NATIVE_LOADER='1',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
                BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1',
                BPFREJIT_NATIVE_LOADER_SO=str(ROOT/'kprog/libnativeloader/build/libnative_loader.so'),
                BPFREJIT_SHIM_NATIVE_MANIFEST=str(ROOT/'vendor/build/native-bpf/x86/stage/bcc/manifest.json'),
                BPFREJIT_SHIM_LOG=str(live/'shim.log'))
            argv=[ROOT/'vendor/build/x86/bcc/bin/vfsstat','-v','1','1']
        else:
            argv=[ROOT/'kprog/libnativeloader/build/trusted-service-client',
                  ROOT/'kprog/libnativeloader/build/trusted-native.o']
        inputs=[ROOT/'kprog/tv/build-kernel-x86/arch/x86/boot/bzImage',
                ROOT/'kprog/tv/build-x86/bpf_x86_native_lab.ko',Path(argv[0])]
        if CASE in {'bcc','bcc-set'}:
            inputs.extend([ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so',
                ROOT/'kprog/libnativeloader/build/libnative_loader.so',
                ROOT/'vendor/build/native-bpf/x86/stage/bcc/manifest.json',
                ROOT/'vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o'])
        else:inputs.append(ROOT/'kprog/libnativeloader/build/trusted-native.o')
        if CASE=='bcc-set':
            tools=['capable','biosnoop','vfsstat','opensnoop','syscount','tcpconnect','tcplife','runqlat']
            inputs.extend(ROOT/'vendor/build/x86/bcc/bin'/name for name in tools)
            inputs.extend(ROOT/'vendor/build/native-bpf/x86/stage/bcc'/(name+'.native.o') for name in tools)
        summary['artifact_sha256']={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
        if CASE=='bcc-set':
            run_bcc_set(live,environment)
            summary['returncode']=0
        else:
            result=subprocess.run(argv,env=environment,text=True,capture_output=True)
            (live/'client.stdout').write_text(result.stdout)
            (live/'client.stderr').write_text(result.stderr)
            summary['returncode']=result.returncode
            result.check_returncode()
        if CASE in {'bcc','bcc-set'}:
            count=len(re.findall(r'native-loader timings prog=',(live/'shim.log').read_text()))
            if not count:raise RuntimeError('BCC produced no required native replacement receipts')
            records=[event() for _ in range(count)]
            if any(record['status'] for record in records):raise RuntimeError('BCC service request failed')
            summary.update(app='bcc/set' if CASE=='bcc-set' else 'bcc/vfsstat',completed_requests=records)
        else:
            client=json.loads(result.stdout)
            if not client['ok'] or client['retval']!=2:raise RuntimeError('native control result mismatch')
            completion=event()
            if completion['status'] or completion['prog_id']!=client['native_prog_id']:
                raise RuntimeError('service receipt differs from completed native request')
            summary.update(client,request_id=completion['request_id'])
        summary['ok']=True
    except Exception as error:
        summary.update(error=str(error),traceback=traceback.format_exc())
        raise
    finally:
        if service.poll() is None:
            try:os.killpg(service.pid,signal.SIGTERM)
            except ProcessLookupError:
                if service.poll() is None:raise
        service.wait();reader.join()
        if reader_errors:summary.update(ok=False,error='service log collection: '+repr(reader_errors))
        kernel_log=subprocess.run(['dmesg','--raw'],text=True,capture_output=True)
        (live/'kernel.log').write_text(kernel_log.stdout)
        (live/'kernel-log-error.txt').write_text(kernel_log.stderr)
        summary['kernel_log_returncode']=kernel_log.returncode
        summary['finished']=datetime.now(timezone.utc).isoformat()
        (live/'summary.json').write_text(json.dumps(summary,indent=2)+chr(10))
        with tarfile.open(archive,'x:gz') as output:output.add(live,arcname='run')
        summary['archive_sha256']=hashlib.sha256(archive.read_bytes()).hexdigest()
        (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+chr(10))
        if reader_errors:raise RuntimeError('service log collection failed: '+repr(reader_errors))
