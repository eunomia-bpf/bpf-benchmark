"""One frozen BCC stats0 check with read-only host own-vCPU and guest task observations."""
from pathlib import Path
import hashlib,json,os,subprocess,traceback,time
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;OUT=HERE/'host-task-check';RAW=Path('/workspaces/kprog-raw/perf/bcc-stats-alignment-20261128/host-task-check');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();sha=lambda b:hashlib.sha256(b).hexdigest();image='sha256:6b88c0ba4c2253a3eadc999048dc39789185f7516b86a70ec14d098418610e11';assert not OUT.exists() and not RAW.exists();OUT.mkdir();RAW.mkdir(parents=True);r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='host-task-check',raw=str(RAW),cases=[],scope='Coordinator11:20 BCC alignment cause. Existing PMU/code pair had asymmetric recurring native-cache copies. One stats0 check retains allnormaltools/image/flags/frozen1x10s/64G. Same readonlyguestproc observer plus host own-QEMU per-thread schedstat/process CPU snapshots; prior pair showed nativegueststeal8.7-9.9percent in BOTHstatsmodes, source5819bd1ed. Identify hostvCPU waiting/collider if visible, not repeat throughput acceptance. NoPMU/cache/code/mapcopies or settingschanges.')
def readproc(p):
 try:return p.read_text()
 except OSError as e:return dict(errno=e.errno)
def host_snapshot(owner):
 stamp=time.monotonic();processes=[];parents={}
 for p in Path('/proc').iterdir():
  if not p.name.isdigit():continue
  stat=readproc(p/'stat');comm=readproc(p/'comm')
  if not isinstance(stat,str) or not isinstance(comm,str):continue
  a=stat[stat.rindex(')')+2:].split()
  if len(a)<37:continue
  pid=int(p.name);parents[pid]=int(a[1]);processes.append(dict(pid=pid,ppid=int(a[1]),comm=comm.strip(),stat=stat,schedstat=readproc(p/'schedstat')))
 descendants={owner}
 for _ in range(len(parents)+1):
  new=descendants|{pid for pid,ppid in parents.items() if ppid in descendants}
  if new==descendants:break
  descendants=new
 qemus=[]
 for row in processes:
  if row['pid'] not in descendants or not row['comm'].startswith('qemu-system'):continue
  pid=row['pid'];threads=[];tasks=Path('/proc')/str(pid)/'task'
  try:entries=list(tasks.iterdir())
  except OSError:entries=[]
  for p in entries:
   if not p.name.isdigit():continue
   t=dict(tid=int(p.name),comm=readproc(p/'comm'),stat=readproc(p/'stat'),schedstat=readproc(p/'schedstat'),wchan=readproc(p/'wchan'))
   try:t['affinity']=sorted(os.sched_getaffinity(int(p.name)))
   except OSError as e:t['affinity']=dict(errno=e.errno)
   threads.append(t)
  qemus.append(dict(pid=pid,ppid=row['ppid'],threads=threads,cgroup=readproc(Path('/proc')/str(pid)/'cgroup')))
 return dict(monotonic=stamp,realtime=time.time(),snapshot_finished_monotonic=time.monotonic(),host_cpu_stat=readproc(Path('/proc/stat')),host_cpu_pressure=readproc(Path('/proc/pressure/cpu')),observer_cpu=list(os.times()),visible_main_processes=processes,own_qemu=qemus)

def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
(LANE/'bcc-host-task-check.json').write_text(json.dumps(dict(pid=os.getpid(),result=str(OUT),raw=str(RAW)),indent=2)+'\n')
try:
 save();template=ROOT/'kprog/results/native-ebpf-alignment-20261128/observe-check.template.sh';observer=HERE/'observe_tasks.py';script=template.read_text();r['source_sha256']={str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in [Path(__file__),template,observer,ROOT/'kprog/perf/one-image/Makefile']};script='#!/bin/bash\n# Low-I/O task-state observation around the unchanged frozen10sBCCcheck.\n'+script[script.index('set -u\n'):];a=script.index('mkdir -p /var/tmp/linkcache /var/tmp/map-observe');b=script.index('make -f $M guest',a);script=script[:a]+'python3 '+str(observer)+' /var/tmp/bcc-task-states.jsonl &\n'+script[b:];old='exec 8>$L/image; flock -s 8';assert script.count(old)==1;script=script.replace(old,old+'\nexec 7>$L/batch; flock -x 7');old='$V/map-observe; do';assert script.count(old)==2;script=script.replace(old,'$V/map-observe $V/bcc-task-states.jsonl; do');assert 'perf kvm' not in script and 'nsenter' not in script and 'dump-prog.py' not in script
 for stats in [0]:
  assert subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip()==image;assert subprocess.check_output(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','rev-parse','HEAD'],text=True).strip().startswith('2689a430');d=RAW/('stats'+str(stats));d.mkdir();assert script.count('BPFREJIT_CORPUS_BPF_STATS=1')==1;s=script.replace('BPFREJIT_CORPUS_BPF_STATS=1','BPFREJIT_CORPUS_BPF_STATS='+str(stats));p=d/'observe.sh';p.write_text(s);subprocess.run(['bash','-n',str(p)],check=True);row=dict(stats=stats,started_utc=now(),raw=str(d),recipe_sha256=sha(p.read_bytes()),command=['bash',str(p),'bcc/set',str(d)]);r['cases'].append(row);save()
  with (d/'controller.log').open('wb') as log, (d/'host-tasks.jsonl').open('x') as host:
   host.write(json.dumps(dict(kind='header',owner_pid=os.getpid(),clock_ticks=os.sysconf('SC_CLK_TCK'),host_release=os.uname().release,pid_namespace=readproc(Path('/proc/self/status')),cgroup=readproc(Path('/proc/self/cgroup')),scope='Readonly host19; allvisible mainprocess stat/schedstat and own-descendantQEMU allthreads/affinity/wchan every0.5s. Namespace may omit external contenders. NoPMU/stacks or scheduler/config writes.'))+'\n');host.flush()
   child=subprocess.Popen(row['command'],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT)
   while child.poll() is None:
    host.write(json.dumps(host_snapshot(os.getpid()))+'\n');host.flush();time.sleep(0.5)
   row['returncode']=child.wait()
  row['ended_utc']=now()
  for n in ['guest-exit.txt','profile-image.txt','profile-source.txt','run_dir']:
   if (d/n).exists():row[n]=(d/n).read_text().strip()
  row['image_matches']=row.get('profile-image.txt')==image;row['task_capture_exists']=(d/'bcc-task-states.jsonl').exists();save()
 r.update(controller_status=int(any(x['returncode']!=0 or x.get('guest-exit.txt')!='0' or not x['image_matches'] or not x['task_capture_exists'] for x in r['cases'])),phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
