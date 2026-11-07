"""Single-vCPU guest; host PMU guest-only perf windows, actual corpus programs."""
import json,os,socket,subprocess,sys,time,traceback
from datetime import datetime,timezone
from pathlib import Path
ROOT=Path('/workspaces/repository');sys.path.insert(0,str(ROOT))
from corpus.profiling.perf_control import PerfCollector
HERE=Path(__file__).resolve().parent;STATE=Path('/workspaces/.agent-state/kprog-lanes/C')
PERF=STATE/'perf-build/perf';variant=sys.argv[1] if len(sys.argv)>1 else 'baseline'
if variant not in ('baseline','tables'):raise ValueError(variant)
image='bpf-benchmark/kprog-map-capture:c-20261107' if variant=='baseline' else 'bpf-benchmark/kprog-perf-tables:c-20261107'
image_tar=str(STATE/('map-capture-runtime.image.tar' if variant=='baseline' else 'perf-tables-runtime.image.tar'))
OUT=HERE/('run-'+variant+'-'+datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ'));OUT.mkdir()
(STATE/'current-perf-run').write_text(str(OUT)+'\n')
QMP=STATE/'perf-qmp.sock'
def occupants(exclude=None):
 busy=[]
 for p in Path('/proc').iterdir():
  if not p.name.isdigit() or int(p.name)==exclude:continue
  try:
   if (p/'comm').read_text().strip()=='qemu-system-x86' and os.sched_getaffinity(int(p.name))&set(range(8)):busy.append(int(p.name))
  except (FileNotFoundError,ProcessLookupError):pass
 return busy
busy=occupants()
if busy:print('queued for timing CPUs; existing QEMU',busy,flush=True)
while busy:
 (OUT/'lease-wait.json').write_text(json.dumps(busy)+chr(10));time.sleep(5);busy=occupants()
if QMP.exists():raise RuntimeError('existing own QMP socket: inspect prior job before restarting')
for n in ['perf-var-tmp','perf-tmp','perf-modules']:(STATE/n).mkdir(exist_ok=True)
cmd=['taskset','-c','0','vng','--run',str(STATE/'frozen-kernel/bzImage'),'--cwd',str(ROOT),'--rwdir',str(ROOT),'--rwdir','/var/tmp='+str(STATE/'perf-var-tmp'),'--rwdir','/tmp='+str(STATE/'perf-tmp'),'--rwdir','/lib/modules='+str(STATE/'perf-modules'),'--disable-monitor','--cpus','1','--memory','8G','--append','loglevel=4 panic=30 oops=panic','--qemu-opts=-qmp unix:'+str(QMP)+',server=on,wait=off','--exec','bash '+str(HERE/'guest.sh')+' '+str(OUT)+' '+image+' '+image_tar]
(OUT/'launch.json').write_text(json.dumps(cmd,indent=2)+'\n')
log=(OUT/'guest.log').open('w');guest=subprocess.Popen(cmd,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
def wait(path):
 while not path.exists():
  if guest.poll() is not None:raise RuntimeError('guest exited before '+str(path))
  if (OUT/'guest-complete.json').exists():raise RuntimeError((OUT/'guest-complete.json').read_text())
  time.sleep(.05)
def qmp_tid():
 s=socket.socket(socket.AF_UNIX);s.connect(str(QMP));f=s.makefile('rwb',buffering=0)
 def reply():
  while True:
   r=json.loads(f.readline())
   if 'return' in r:return r['return']
   if 'error' in r:raise RuntimeError(str(r))
 json.loads(f.readline());f.write(b'{"execute":"qmp_capabilities"}\n');reply();f.write(b'{"execute":"query-cpus-fast"}\n');cpus=reply();s.close()
 if len(cpus)!=1:raise RuntimeError('expected exactly one vCPU')
 tid=cpus[0]['thread-id'];os.sched_setaffinity(tid,{0});(OUT/'vcpu.json').write_text(json.dumps(cpus,indent=2)+'\n');return tid
collector=None
try:
 wait(QMP);tid=qmp_tid();index=0
 qemu_pid=int(next(line.split()[1] for line in Path('/proc/'+str(tid)+'/status').read_text().splitlines() if line.startswith('Tgid:')))
 events='cpu_core/cycles/G,cpu_core/instructions/G,cpu_core/branch-misses/G,cpu_core/iTLB-load-misses/G,cpu_core/L1-icache-load-misses/G'
 while True:
  ready=OUT/f'ready-{index:03d}.json'
  while not ready.exists():
   if (OUT/'guest-complete.json').exists():break
   if guest.poll() is not None:raise RuntimeError('guest exited unexpectedly')
   time.sleep(.05)
  if not ready.exists():break
  meta=json.loads(ready.read_text());prefix=Path(meta['prefix'])
  if occupants(qemu_pid):raise RuntimeError('foreign timing guest overlapped; window not started')
  # Keep FIFO paths below Linux UNIX/path limits and preserve every command.
  ctl=STATE/'perf-control';ack=STATE/'perf-ack'
  if meta['kind']=='stat':
   argv=[str(PERF),'stat','-D','-1','--control=fifo:'+str(ctl)+','+str(ack),'-x',';','-e',events,'-t',str(tid),'-o',str(prefix/'perf-stat.csv')]
  else:
   argv=[str(PERF),'kvm','--guest','--guestkallsyms',str(prefix/'kallsyms.txt'),'record','-D','-1','--control=fifo:'+str(ctl)+','+str(ack),'-e','cpu_core/cycles/G','-c','1000000','-t',str(tid),'-o',str(prefix/'perf.data')]
  (prefix/'perf-command.json').write_text(json.dumps(argv,indent=2)+'\n')
  collector=PerfCollector(argv,ctl,ack,prefix/'perf-stderr.txt');collector.start();collector.enable();(OUT/f'go-{index:03d}').touch()
  wait(OUT/f'done-{index:03d}.json');collector.disable();collector.finish();collector=None
  done=json.loads((OUT/f'done-{index:03d}.json').read_text())
  if not done['ok']:raise RuntimeError(str(done))
  if meta['kind']=='record':
   p=subprocess.run([str(PERF),'script','--guestkallsyms',str(prefix/'kallsyms.txt'),'-i',str(prefix/'perf.data'),'-F','ip,sym,dso'],capture_output=True,text=True)
   (prefix/'samples.txt').write_text(p.stdout);(prefix/'samples-stderr.txt').write_text(p.stderr)
   (prefix/'samples.exit').write_text(str(p.returncode)+'\n')
  (OUT/f'ack-{index:03d}').touch();print('window',index,meta['app'],meta['arm'],meta['scenario'],meta['kind'],'done',flush=True);index+=1
 result=json.loads((OUT/'guest-complete.json').read_text());(OUT/'host-complete.json').write_text(json.dumps(result,indent=2)+'\n')
 guest.wait();raise SystemExit(0 if result['ok'] and guest.returncode==0 else 1)
except BaseException as e:
 if collector:collector.abort()
 (OUT/'abort').touch();(OUT/'host-error.txt').write_text(traceback.format_exc());raise
finally:
 log.close()
 if guest.poll() is not None and QMP.exists():QMP.unlink()
 disk=STATE/'perf-var-tmp/bpf-benchmark-docker.img'
 if guest.poll() is not None and disk.exists():disk.unlink()
