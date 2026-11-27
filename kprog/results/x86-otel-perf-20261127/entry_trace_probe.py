"""Compare actual frontend entry helper traces, without claiming benchmark equivalence."""
import fcntl,hashlib,json,os,resource,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
token=now().replace('-','').replace(':','');out=HERE/('entry-trace-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127')/out.name;raw.mkdir()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,raw=str(raw),scope='Original actual P versus current frozen-LTO re-emission, deterministic helper boundary trace; debug test, no performance or whole-app equivalence claim.')
def save():(out/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(label,cmd):
 r.setdefault('commands',[]).append(dict(label=label,argv=list(map(str,cmd))));save()
 with (raw/(label+'.log')).open('wb') as f:rc=subprocess.run(list(map(str,cmd)),stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT).returncode
 r['commands'][-1]['returncode']=rc;save();assert rc==0,(label,rc)
try:
 save();(LANE/'otel-entry-trace.json').write_text(json.dumps(dict(result=str(out),raw=str(raw),pid=os.getpid()),indent=2)+'\n');os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552))
 with (LANE.parent/'locks/timing').open('a') as timing,(LANE.parent/'locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH|fcntl.LOCK_NB);fcntl.flock(image,fcntl.LOCK_SH|fcntl.LOCK_NB)
  cache=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127/20261127T195100Z/linkcache/native_kernel_link_cache');plan=json.loads(next(cache.glob('99d6a07ff2e5d4b3*.link-plan.json')).read_text());facts={x['name']:x['hex'] for x in plan['const_values']};(raw/'immutable.json').write_text(json.dumps(facts)+'\n')
  source=ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o';r['input_sha256']=hashlib.sha256(source.read_bytes()).hexdigest();r['facts']=facts
  compiler='/opt/bpf-benchmark/native-bpf/x86_64/kprog-perf-context-lto';cmd=['docker','run','--rm','--cpuset-cpus','16','-v','/workspaces:/workspaces','--entrypoint','prlimit','bpf-benchmark/kprog:current','--as=51539607552','--',compiler,'--x86-cmov-converter-force-all',str(source),'--symbol','native_tracer_entry','--kernel-btf','/sys/kernel/btf/vmlinux','--prog-type','0','--immutable-globals',str(raw/'immutable.json'),'-o',str(raw/'optimized.o')];run('reemission',cmd)
  run('build-harness',['clang-18','-O2','-rdynamic',HERE/'entry_trace_stub.c','-ldl','-o',raw/'harness'])
  for label,p in [('original',source),('optimized',raw/'optimized.o')]:
   run('link-'+label,['clang-18','-shared','-Wl,-Bsymbolic',p,'-o',raw/(label+'.so')])
   for present in [False,True]:run(label+('-present' if present else '-missing'),[raw/'harness',raw/(label+'.so'),*(['present'] if present else [])])
  r['traces_equal']={state:(raw/('original-'+state+'.log')).read_bytes()==(raw/('optimized-'+state+'.log')).read_bytes() for state in ['missing','present']};r['controller_status']=0
except Exception:r.update(controller_status=1,exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
