"""Compile the recovered corpus with one ARM flag set and two capped workers."""
import concurrent.futures
import fcntl
import hashlib
import json
import os
from pathlib import Path
import queue
import subprocess
import sys
import tarfile
import threading
import time
import traceback

ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
sys.path.insert(0,str(ROOT/'kprog'))
from arm64.trusted_specializer import b_flags

def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
run=json.loads((LANE/'scalar-run.json').read_text());OUT=Path(run['result']);RAW=Path(run['raw'])
prepared=json.loads((OUT/'prepare-controller.json').read_text());assert prepared['controller_status']==0
pilot='--pilot' in sys.argv
flags=list(map(str,b_flags(sysroot=ROOT/'.cache/qemu-arm64-root')))
assert flags==json.loads((ROOT/'kprog/results/arm64-loadtime-20261127/cross-app-20261127T141857Z/controller.json').read_text())['common_flags']
paths=[ROOT/'kprog/arm64/trusted_specializer.py',ROOT/'kprog/arm64/arm64_sim_local_bpf.h',ROOT/'kprog/arm64/arm64_sim_direct.h',*sorted((ROOT/'kprog/formal/generated').glob('arm64*.h'))]
headers={str(p):sha(p) for p in paths}
record=dict(started_utc=now(),pid=os.getpid(),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),raw=str(RAW),result=str(OUT),common_flags=flags,source_sha256=headers,cases=[],scope='One general BPF-only ARM kernel/untyped read route. All145 captured generatedB inputs,117 originally refused and28 accepted controls; samearchitecture flags/48GiBAS/two compiler workers CPU16and18. ActualARMstock/native/stage2 acceptance remains separate. Pilot is request49/Tetragon1 scalar failure only, followed by the complete corpus with identical sources.',pilot=pilot)
receipt=OUT/('pilot-controller.json' if pilot else 'compile-controller.json')
def save():receipt.write_text(json.dumps(record,indent=2)+'\n')
def drift():return [p for p,h in headers.items() if sha(Path(p))!=h]
cpus=queue.Queue()
for cpu in [16,18]:cpus.put(cpu)
local=threading.local()
def init():local.cpu=cpus.get()
def command(args,path):
    cmd=['prlimit','--as=51539607552','taskset','-c',str(local.cpu),*map(str,args)];start=time.monotonic()
    with path.with_suffix('.stdout').open('wb') as out,path.with_suffix('.stderr').open('wb') as err:
        child=subprocess.Popen(cmd,stdin=subprocess.DEVNULL,stdout=out,stderr=err,cwd=ROOT)
        _,status,usage=os.wait4(child.pid,0);child.returncode=os.waitstatus_to_exitcode(status)
    return dict(command=cmd,returncode=child.returncode,wall_seconds=time.monotonic()-start,max_rss_kib=usage.ru_maxrss,user_seconds=usage.ru_utime,system_seconds=usage.ru_stime)
def compile_one(item):
    row=dict(index=item['index'],app=item['app'],request=item['request'],symbol=item['symbol'],original_stock_passed=item['original_stock_passed'],baseline_object=item['baseline_object'],baseline_kind=item['baseline_kind'],commands=[],started_utc=now())
    case=RAW/str(item['index']);source=case/'after.bpf.c';ir=case/'after.frontend.bc';obj=case/'after.bpf.o'
    try:
        assert sha(source)==item['normalized_source_sha256'];assert not drift(),'header drift'
        row['baseline_sha256']=sha(case/item['baseline_object']);row['source_sha256']=sha(source)
        for label,args in [('frontend',['-emit-llvm','-c',source,'-o',ir]),('object',['-c',ir,'-o',obj])]:
            step=command([ROOT/'kprog/stock-path/bin/clang',*flags,*args],case/('probe-'+label));row['commands'].append(step)
            if step['returncode']:row['status']=label+'-failed';break
        else:row.update(status='compiled',object_sha256=sha(obj),object_bytes=obj.stat().st_size)
    except Exception:row.update(status='exception',exception=traceback.format_exc())
    row['ended_utc']=now();return row
try:
    save()
    with (LANE.parent/'locks/timing').open('a') as timing,(LANE.parent/'locks/image').open('a') as image:
        fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_SH)
        assert not drift()
        snapshot=RAW/('pilot-source.tar' if pilot else 'compile-source.tar')
        with tarfile.open(snapshot,'w') as archive:
            for path in [*paths,Path(__file__)]:archive.add(path,arcname=str(path.relative_to(ROOT)))
        record['source_archive_sha256']=sha(snapshot)
        items=prepared['inputs']
        if pilot:items=[x for x in items if x['app']=='tetragon/observer' and x['request']==1];assert len(items)==1
        elif (OUT/'pilot-controller.json').exists():
            prior=json.loads((OUT/'pilot-controller.json').read_text())
            assert prior['controller_status']==0 and prior['source_sha256']==headers and prior['common_flags']==flags
            for row in prior['cases']:
                assert row['object_sha256']==sha(RAW/str(row['index'])/'after.bpf.o')
                record['cases'].append(dict(row,reused_pilot=True))
            done={x['index'] for x in record['cases']};items=[x for x in items if x['index'] not in done]
        save()
        with concurrent.futures.ThreadPoolExecutor(max_workers=2,initializer=init) as pool:
            for row in pool.map(compile_one,items):
                record['cases'].append(row);save();print(json.dumps({k:row[k] for k in ['index','app','symbol','status']}),flush=True)
        record['header_drift']=drift();record['controller_status']=int(bool(record['header_drift']) or any(x['status']!='compiled' for x in record['cases']))
except Exception:record.update(controller_status=1,exception=traceback.format_exc())
finally:
    record['ended_utc']=now();save()
    with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM scalar-memory '+('pilot' if pilot else 'all145')+' compilation ended status '+str(record['controller_status'])+'. Read '+str(receipt)+'; compiler completion is not stock/native/stage2 acceptance. Preserve raw inputs until committed archive/full-file SHA verification.\n')
    print(json.dumps(dict(receipt=str(receipt),status=record['controller_status'],cases=len(record['cases']),exception=record.get('exception'))),flush=True)
raise SystemExit(record['controller_status'])
