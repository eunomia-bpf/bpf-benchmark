"""Read-only alignment evidence at1/8s of each actual shim phase; code/cache once per phase."""
from pathlib import Path
import json,os,re,shutil,subprocess,sys,time,traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;APP=sys.argv[1];OUT=Path(sys.argv[2]);OUT.mkdir();CORPUS=ROOT/'corpus/results';previous={p.name for p in CORPUS.iterdir()};key=APP.replace('/','__');state=dict(app=APP,started_monotonic=time.monotonic(),scope='Existing frozencheck only; readonly map/prog-array/RO+programstats at1/8s after first actual shimstart, actualJIT/cache once at1s. Common schedule allapps; OTel additionally records its existing unwindmetrics/trie/percpurecord probes. Not throughputacceptance.',phases={});offsets={};buffers={};run=None

def save():
 p=OUT/'observer.json.tmp';p.write_text(json.dumps(state,indent=2)+'\n');os.replace(p,OUT/'observer.json')
def command(cmd,path):
 with path.open('wb') as f:r=subprocess.run(cmd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
 return dict(command=cmd,returncode=r.returncode,log=str(path.relative_to(OUT)))
def snapshot(phase,label,rec):
 p=OUT/(phase+'-'+label);p.mkdir();r=dict(started_monotonic=time.monotonic(),path=p.name,commands=[],linkcache=[]);rec.setdefault('snapshots',[]).append(r);save()
 try:
  (p/'cpu-stat.txt').write_text(Path('/proc/stat').read_text());(p/'kallsyms.txt').write_text(Path('/proc/kallsyms').read_text());(p/'clock.txt').write_text(str(time.time())+' '+str(time.monotonic())+'\n')
  r['commands'].append(command(['python3',str(ROOT/'kprog/results/x86-otel-perf-20261127/observe_otel_maps.py'),str(p/'maps'),'all-maps'],p/'maps.log'))
  if APP=='otelcol-ebpf-profiler/profiling':r['commands'].append(command(['python3',str(ROOT/'kprog/results/x86-otel-perf-20261127/observe_otel_maps.py'),str(p/'unwind-maps')],p/'unwind-maps.log'))
  if label=='start':
   r['commands'].append(command(['python3',str(HERE/'dump_all.py'),'',str(p/'progs')],p/'progs.log'))
   ids=subprocess.run(['docker','ps','-q'],stdin=subprocess.DEVNULL,text=True,capture_output=True);r['docker_ps_returncode']=ids.returncode
   for cid in ids.stdout.split():
    a=subprocess.run(['docker','inspect','-f','{{.State.Pid}}',cid],stdin=subprocess.DEVNULL,text=True,capture_output=True)
    if a.returncode:r['linkcache'].append(dict(container=cid,inspect_returncode=a.returncode));continue
    pid=int(a.stdout.strip());src=Path('/proc')/str(pid)/'root/tmp/native_kernel_link_cache';dest=p/'linkcache'/cid;row=dict(container=cid,pid=pid,source_exists=src.exists());r['linkcache'].append(row)
    if src.exists():shutil.copytree(src,dest,symlinks=True);row['copied_files']=sum(x.is_file() for x in dest.rglob('*'))
 except Exception:r['exception']=traceback.format_exc()
 finally:r['ended_monotonic']=time.monotonic();save()
save()
while True:
 try:
  if run is None:
   candidates=[p for p in CORPUS.iterdir() if p.is_dir() and p.name not in previous and (p/'details/shim-logs').exists() and any(x.name.startswith(key+'.') for x in (p/'details/shim-logs').iterdir())]
   if len(candidates)==1:run=candidates[0];state['run']=str(run);save()
   elif len(candidates)>1:state['ambiguous_runs']=[str(p) for p in candidates];save()
  if run is not None:
   for phase in ['baseline','post_rejit']:
    path=run/'details/shim-logs'/(key+'.'+phase+'.log')
    if not path.exists():continue
    with path.open() as f:f.seek(offsets.get(phase,0));text=buffers.get(phase,'')+f.read();offsets[phase]=f.tell()
    lines=text.split('\n');buffers[phase]=lines.pop();rec=state['phases'].setdefault(phase,dict(shim_log=str(path),start_times=[],finish_times=[]))
    changed=False
    for l in lines:
     a=re.match(r'^\[([\d.]+) .*cmd=(measure_start|measure_finish)',l)
     if a:rec['start_times' if a[2]=='measure_start' else 'finish_times'].append(float(a[1]));changed=True
    if changed:save()
    if not rec['start_times']:continue
    for label,delay in [('start',1),('late',8)]:
     if any(x.get('label')==label for x in rec.get('decisions',[])):continue
     if time.monotonic()<min(rec['start_times'])+delay:continue
     decision=dict(label=label,monotonic=time.monotonic(),already_finished=bool(rec['finish_times']));rec.setdefault('decisions',[]).append(decision);save()
     if not rec['finish_times']:snapshot(phase,label,rec)
  time.sleep(0.25)
 except Exception:state['exception']=traceback.format_exc();save();time.sleep(0.5)
