#!/usr/bin/env python3
"""Run only sequential Make corpus invocations; checkpoint every outcome."""
import argparse
import fcntl
import gzip
import json
import os
from pathlib import Path
import shutil
import subprocess
import threading
import time

p=argparse.ArgumentParser()
p.add_argument('label')
p.add_argument('tree',type=Path)
p.add_argument('--smoke',action='store_true')
p.add_argument('--controls-only',action='store_true')
args=p.parse_args()
lock = open('/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/guest-execution.lock','w')
fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
lock.write(str(os.getpid())+'\n');lock.flush()
output=Path(__file__).resolve().parent
state=output/'reboot-state.json'
def boot():
    return {'pid1_start':subprocess.check_output(['ps','-o','lstart=','-p','1'],text=True).strip(),
            'boot_id':Path('/proc/sys/kernel/random/boot_id').read_text().strip()}
current=boot()
if state.exists():
    saved=json.loads(state.read_text())
else:
    saved={'initial':current,'last':current,'reboots':[]}
if current != saved['last']:
    saved['reboots'].append({'observed_at':time.time(),'previous':saved['last'],'current':current,
                            'running':json.loads((output/'progress.json').read_text())})
    saved['last']=current
    interrupted=json.loads((output/'progress.json').read_text())
    if interrupted.get('status')=='running':
        source=output/interrupted['run']
        aborted=output/'aborted-by-reboot'/str(len(saved['reboots']))/interrupted['run']
        aborted.parent.mkdir(parents=True,exist_ok=True)
        shutil.move(str(source),str(aborted))
        saved['reboots'][-1]['retained_artifacts']=str(aborted)
state.write_text(json.dumps(saved,indent=2)+'\n')
if len(saved['reboots']) >= 2:
    raise SystemExit('second host/container restart observed: stop per operator instruction')

def monitor(dest,stop):
    with gzip.open(dest/'host-load.jsonl.gz','wt') as f:
        while not stop.is_set():
            groups={}
            for path in Path('/sys/fs/cgroup/kubepods.slice').rglob('cpu.stat'):
                if '-pod' in path.parent.name:
                    groups[str(path.parent)]=path.read_text()
            threads={}
            for comm in Path('/proc').glob('[0-9]*/comm'):
                if comm.exists() and 'qemu-system' in comm.read_text():
                    for path in (comm.parent/'task').glob('[0-9]*/status'):
                        if path.exists():threads[str(path)]=path.read_text()
            f.write(json.dumps({'time':time.time(),'proc_stat':Path('/proc/stat').read_text(),
                'loadavg':Path('/proc/loadavg').read_text(),'pod_cpu_stat':groups,
                'qemu_threads':threads,'boot':boot()})+'\n');f.flush()
            stop.wait(2)

for pair in range(1,2 if args.smoke else 6):
    for stats in ([1] if args.smoke else [1,0]):
        for control in ([True] if args.controls_only else ([False] if args.smoke else [False,True])):
            name=f'{args.label}/pair-{pair:02d}-stats-{stats}-'+('control' if control else 'native')
            dest=output/name
            if (dest/'exit.json').exists():
                continue
            dest.mkdir(parents=True,exist_ok=True)
            if any('qemu-system' in path.read_text(errors='replace') for path in Path('/proc').glob('[0-9]*/comm') if path.exists()):
                raise SystemExit('another guest in this workspace is running')
            before=set((args.tree/'corpus/results').iterdir())
            command=['taskset','-c','6,7','make','-C',str(args.tree),'-o','runtime-kernel-image','corpus',
                'PLATFORM=kvm','ARCH=x86','VM_CPUS=4','VM_MEM=24G','BPFREJIT_CORPUS_APPS=cilium/agent',
                'SAMPLES=1','WARMUPS=1','WORKLOAD_DURATION='+('10' if args.smoke else '30'),
                'BPFREJIT_CORPUS_BPF_STATS='+str(stats),'KEEP_WORKDIRS=1','TIMEOUT=1800',
                'VM_EXECUTABLE='+str(output/'vng-audit.py'),
                'RUN_TOKEN=cilium-lab-'+args.label+'-'+str(pair)+'-'+str(stats)+'-'+str(control)]
            command+=['SKIP_REJIT=norejit'] if control or args.label.startswith('paper') else []
            if not control:
                command+=['BPFREJIT_SHIM_NATIVE_LOADER=post']
            if args.label.startswith('paper'):
                command+=['RUNTIME_CONTAINER_IMAGE=bpf-benchmark/cilium-audit-paper:20261009',
                    'RUNTIME_IMAGE_TAR=/tmp/cilium-paper-runtime-20261009.tar']
            elif args.label.startswith('current'):
                command+=['RUNTIME_CONTAINER_IMAGE=bpf-benchmark/cilium-audit-current:20261009',
                    'RUNTIME_IMAGE_TAR=/tmp/cilium-current-runtime-20261009.tar']
            progress={'run':name,'command':command,'started':time.time(),'status':'running','boot':boot()}
            (output/'progress.json').write_text(json.dumps(progress,indent=2)+'\n')
            (dest/'command.json').write_text(json.dumps(progress,indent=2)+'\n')
            env=os.environ.copy();env['CILIUM_AUDIT_RUN']=str(dest)
            for key in ['SKIP_REJIT','BPFREJIT_SHIM_NATIVE_LOADER','BPFREJIT_BENCH_PASSES']:
                env.pop(key,None)
            stop=threading.Event();thread=threading.Thread(target=monitor,args=(dest,stop));thread.start()
            with (dest/'make.log').open('w') as log:
                result=subprocess.run(command,env=env,stdout=log,stderr=subprocess.STDOUT)
            stop.set();thread.join()
            after=set((args.tree/'corpus/results').iterdir())
            created=sorted(after-before)
            for path in created:
                if path.is_dir():shutil.copytree(path,dest/'raw'/path.name)
            app_errors=[]
            for path in (dest/'raw').glob('*/details/apps/*.json'):
                app=json.loads(path.read_text())
                if app.get('status')=='error':app_errors.append(app.get('error'))
            progress.update(status='finished',exit_code=result.returncode,ended=time.time(),result_dirs=[str(x) for x in created])
            progress['app_errors']=app_errors
            (dest/'exit.json').write_text(json.dumps(progress,indent=2)+'\n')
            (output/'progress.json').write_text(json.dumps(progress,indent=2)+'\n')
            print(json.dumps(progress),flush=True)
            if result.returncode or app_errors:
                raise SystemExit(f'corpus invocation failed; retained {dest}; repair before resuming')
