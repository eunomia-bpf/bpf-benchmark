"""Compile every captured non-Cilium ARM input with the common live producer."""
import fcntl
import hashlib
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import time
import traceback

ROOT = Path('/workspaces/repository')
HERE = Path(__file__).resolve().parent
LANE = Path('/workspaces/.agent-state/kprog-lanes/perf')
sys.path.insert(0, str(ROOT/'kprog'))
from arm64.trusted_specializer import b_flags

def now():
    return subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip()
token = subprocess.check_output(['date', '-u', '+%Y%m%dT%H%M%SZ'], text=True).strip()
OUT = HERE/('cross-app-'+token)
OUT.mkdir()
RAW = Path('/workspaces/kprog-raw/perf/arm64-loadtime-20261127')/('cross-app-'+token)
RAW.mkdir()
record = dict(started_utc=now(), pid=os.getpid(), raw=str(RAW),
              revision=subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(),
              producer_sha256=hashlib.sha256((ROOT/'kprog/arm64/trusted_specializer.py').read_bytes()).hexdigest(),
              scope='All archived BCC/Katran/OTel inputs and all Tetragon request archives completed at inventory time. Identical actual producer qualifier profile and b_flags; cold frontend/object compilation only. Stock verification/native install/full startup are not measured. Active guest evidence stays unchanged.',
              inventory=[], cases=[])
def save():
    (OUT/'controller.json').write_text(json.dumps(record, indent=2)+'\n')
def run(command, path):
    start = time.monotonic()
    with path.with_suffix('.stdout').open('wb') as stdout, path.with_suffix('.stderr').open('wb') as stderr:
        child = subprocess.Popen([str(x) for x in command], cwd=ROOT, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr)
        _, status, usage = os.wait4(child.pid, 0)
        child.returncode = os.waitstatus_to_exitcode(status)
    return dict(command=[str(x) for x in command], returncode=child.returncode,
                wall_seconds=time.monotonic()-start, max_rss_kib=usage.ru_maxrss,
                user_seconds=usage.ru_utime, system_seconds=usage.ru_stime)
try:
    save()
    if len(sys.argv)>1:
        previous=HERE/sys.argv[1]/'controller.json'
        prior=json.loads(previous.read_text())
        record['recovery_of']=str(previous.relative_to(ROOT))
        record['scope']='Retry only input-file exceptions from the original captured compiler inventory, using the immutable completed service archive. Original exception receipts remain unchanged; compiler flags and qualifier profile must match the original replay.'
        for row in prior['cases']:
            if row['status']!='exception':continue
            if 'FileNotFoundError:' not in row.get('exception',''):
                raise RuntimeError('Recovery requires an actual missing original input archive.')
            original=Path(row['archive'])
            outer=original.parents[3]/'service.tar.gz'
            record['inventory'].append(dict(index=row['index'],app=row['app'],archive=str(outer),member='service/requests/'+original.name,original_archive=str(original)))
    else:
        raw_base=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127')
        completed=[('bcc/set',raw_base/'20261127T012418Z/bcc-set/service.tar.gz'),
                   ('katran/balancer',raw_base/'20261127T020053Z/katran/service.tar.gz'),
                   ('otelcol-ebpf-profiler/profiling',raw_base/'20261127T044717Z/otelcol-ebpf-profiler-profiling/service.tar.gz')]
        for app, archive in completed:
            with tarfile.open(archive) as outer:
                members=[member for member in outer.getmembers() if '/requests/' in member.name and member.name.endswith('.tar.gz')]
                for member in sorted(members, key=lambda m:int(Path(m.name).name.split('.')[0])):
                    record['inventory'].append(dict(app=app, archive=str(archive), member=member.name))
        tetra=raw_base/'20261127T091129Z'
        for archive in sorted(tetra.rglob('*.tar.gz')):
            if archive.name.split('.')[0].isdigit() and any(part in archive.name for part in ['.success.', '.failure.']):
                record['inventory'].append(dict(app='tetragon/observer',archive=str(archive),member=None))
    record['coverage_gaps']=['tracee/monitor has no completed ARM checked archive yet; its live stage2 remains queued.', 'Cilium all ten captured requests already compiled in corpus-20261127T115432Z; this job avoids repeating them.']
    header_paths=[ROOT/'kprog/arm64/arm64_sim_local_bpf.h',ROOT/'kprog/arm64/arm64_sim_direct.h',*sorted((ROOT/'kprog/formal/generated').glob('arm64*.h'))]
    record['header_sha256']={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in header_paths}
    with tarfile.open(RAW/'source-headers.tar','w') as t:
        for p in [ROOT/'kprog/arm64/trusted_specializer.py',*header_paths]:t.add(p,arcname=str(p.relative_to(ROOT)))
    flags=[str(x) for x in b_flags(sysroot=ROOT/'.cache/qemu-arm64-root')]
    record['common_flags']=flags
    if 'recovery_of' in record:
        assert flags==prior['common_flags']
        assert record['header_sha256']==prior['header_sha256']
    save()
    with (LANE.parent/'locks/timing').open('a') as lock:
        fcntl.flock(lock,fcntl.LOCK_SH)
        for ordinal,item in enumerate(record['inventory'],1):
            index=item.get('index',ordinal)
            row=dict(item,index=index,started_utc=now(),commands=[])
            case=RAW/str(index)
            case.mkdir()
            try:
                if item['member']:
                    with tarfile.open(item['archive']) as outer:
                        data=outer.extractfile(item['member']).read()
                    archive=tarfile.open(fileobj=io.BytesIO(data))
                else:
                    archive=tarfile.open(item['archive'])
                with archive:
                    files={Path(m.name).name:m for m in archive.getmembers() if m.isfile()}
                    if 'trusted_arm64.bpf.c' not in files:
                        row.update(status='no-frontend-input',reason='Original request archive has no emitted ARM C source.')
                    else:
                        source=archive.extractfile(files['trusted_arm64.bpf.c']).read()
                        receipt=next((m for name,m in files.items() if name.endswith('frontend.compiler.json.broker.json')),None)
                        row['original_frontend']=json.loads(archive.extractfile(receipt).read()) if receipt else None
                        entry=files.get('kernel.entry')
                        row['symbol']=archive.extractfile(entry).read().decode() if entry else None
                        row['original_source_sha256']=hashlib.sha256(source).hexdigest()
                        marker=('#include '+json.dumps(str(ROOT/'kprog/arm64/arm64_sim_local_bpf.h'))).encode()
                        if source.count(marker)!=1 or b'#undef ARM64_SIM_L_READ_REG_RAW_INTO' in source:
                            raise RuntimeError('Archived input is not the original unqualified ARM producer source.')
                        c=case/'trusted_arm64.bpf.c';ir=case/'trusted_arm64.bpf.frontend.bc';obj=case/'trusted_arm64.bpf.o'
                        c.write_bytes(source)
                        row['source_sha256']=hashlib.sha256(source).hexdigest()
                        for label,args in [('frontend',['-emit-llvm','-c',c,'-o',ir]),('object',['-c',ir,'-o',obj])]:
                            command=[ROOT/'kprog/stock-path/bin/clang',*flags,*args]
                            step=run(command,case/label)
                            row['commands'].append(step)
                            if step['returncode']:
                                row['status']=label+'-failed'
                                break
                        else:
                            row['status']='compiled'
            except Exception:
                row.update(status='exception',exception=traceback.format_exc())
            row['ended_utc']=now()
            row['artifact_bytes']={str(p.relative_to(RAW)):p.stat().st_size for p in case.iterdir() if p.is_file()}
            record['cases'].append(row)
            save()
            print(json.dumps(dict(index=index,total=len(record['inventory']),app=row['app'],symbol=row.get('symbol'),status=row['status'])),flush=True)
    record['controller_status']=int(any(case['status']!='compiled' for case in record['cases']))
except Exception:
    record.update(controller_status=1,exception=traceback.format_exc())
finally:
    record['ended_utc']=now()
    save()
    try:
        with (OUT/'archive.log').open('wb') as log:
            a=subprocess.Popen(['tar','-C',str(RAW.parent),'-cf','-',RAW.name],stdout=subprocess.PIPE,stderr=log)
            b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close()
            c=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close()
            codes=[c.wait(),b.wait(),a.wait()][::-1]
        record['archive_returncodes']=codes
        save()
        if any(codes):raise RuntimeError('Cross-app evidence archive failed')
        with (LANE.parent/'locks/git').open('a') as lock,(OUT/'publication.log').open('a') as log:
            fcntl.flock(lock,fcntl.LOCK_EX)
            path=str(OUT.relative_to(ROOT))
            for command in [['git','add','-f','--',path],['git','commit','--only','-m','Record common ARM producer compilation across captured applications','--',path],['git','push']]:
                subprocess.run(command,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT,check=True)
    except Exception:
        record.update(controller_status=1,publication_error=traceback.format_exc())
        save()
    with (LANE/'resume-msg.md').open('a') as f:
        f.write(f'\nARM common producer cross-app compilation finished status {record["controller_status"]}. Read {OUT}/controller.json and raw per-request compiler diagnostics/artifacts. Compare all prior generation failures, record actual cross-app compatibility; stock/native/frozen startup remains separate and queued Cilium/Tracee outcomes still required.\n')
raise SystemExit(record['controller_status'])
