"""Resolve SAME1454977 completed guest-mode PMU by explicit process ownership and phase."""
from pathlib import Path
import bisect,collections,hashlib,importlib.util,json,os,re,resource,subprocess,sys,time,traceback,types
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;PAIR=HERE/'paired-profile';OUT=PAIR/'analysis';assert not OUT.exists();OUT.mkdir();os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def source(p):return dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p))
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='waiting-for-same-pair',scope='Offline analysis only of1454977. Stats0 disabled counters are never a denominator; ownQEMU from recorded process ancestry, phase-specific symbols and sample-period sums. No profile rerun or image/source change.',cases=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save()
 while True:
  c=json.loads((PAIR/'controller.json').read_text());assert c['pid']==1454977
  if c['controller_status'] is not None:break
  time.sleep(5)
 assert len(c['cases'])==2 and all(x.get('guest-exit.txt')=='0' and x.get('image_matches') for x in c['cases']),c
 owner=json.loads((PAIR/'pmu-owner-evidence.json').read_text());r['owner_evidence']=source(PAIR/'pmu-owner-evidence.json');r['profile_controller']=source(PAIR/'controller.json');r['phase']='resolve-pmu';save();m=types.ModuleType('matplotlib');m.use=lambda *a,**k:None;p=types.ModuleType('matplotlib.pyplot');m.pyplot=p;sys.modules['matplotlib']=m;sys.modules['matplotlib.pyplot']=p;spec=importlib.util.spec_from_file_location('frozen_bcc_eval',ROOT/'kprog/docs/archive/native_eval_20260529.py');ne=importlib.util.module_from_spec(spec);sys.modules[spec.name]=ne;spec.loader.exec_module(ne)
 pattern=re.compile(r'^\d+ (\d+) \S+ \[\S+\]: PERF_RECORD_SAMPLE\(IP, 0x([45])\): (\d+)/(\d+): 0x([0-9a-f]+) period: (\d+)')
 for case in c['cases']:
  stats=case['stats'];raw=Path(case['raw']);run=Path(case['run_dir']);appfile=run/'details/apps/bcc__set.json';app=json.loads(appfile.read_text());assert app['status']=='ok';qemu=owner['cases'][str(stats)]['qemu_pid'];grt,gup=map(float,(raw/'clock.txt').read_text().split());hoff=float((raw/'host-rt-minus-uptime.txt').read_text());boot={}
  for l in (raw/'kallsyms.txt').read_text().splitlines():
   f=l.split()
   if len(f)>=3 and f[1] in 'tTwW':boot[int(f[0],16)]=f[2]
  windows={};tables={};work={};snaps=[(float(p.name[len('kallsyms-bpf-'):-4]),p) for p in raw.glob('kallsyms-bpf-*.txt')]
  for phase in ['baseline','post_rejit']:
   text=(run/'details/shim-logs'/('bcc__set.'+phase+'.log')).read_text();starts=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_start',text,re.M)];ends=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_finish',text,re.M)];assert starts and ends;start,end=max(starts),min(ends);assert end>start;windows[phase]=dict(start=start,end=end,duration=end-start,all_start_spread=max(starts)-min(starts),all_end_spread=max(ends)-min(ends));inside=[x for x in snaps if start<=x[0]<end];assert inside;_,snapshot=min(inside,key=lambda x:abs(x[0]-(start+end)/2));syms=dict(boot)
   for l in snapshot.read_text().splitlines():
    f=l.split()
    if len(f)>=3:syms[int(f[0],16)]=f[2]
   tables[phase]=(syms,sorted(syms),source(snapshot));samples=ne.phase_samples(app,phase);assert len(samples)==1 and samples[0][2]==0;work[phase]=dict(total_ops_per_second=samples[0][0],by_stressor=samples[0][1],bpf_aggregate=ne.bpf_aggregate(app,phase) if stats else None)
  def resolve(phase,ip):
   if ip<0xffff800000000000:return '[guest-user]',0
   syms,keys,_=tables[phase];i=bisect.bisect_right(keys,ip)-1;return (syms[keys[i]],ip-keys[i]) if i>=0 else ('[unknown]',0)
  counts=collections.defaultdict(collections.Counter);periods=collections.defaultdict(collections.Counter);pids=collections.defaultdict(collections.Counter);hot=collections.defaultdict(collections.Counter);timebounds={};total=0
  err=OUT/('stats'+str(stats)+'-perf-report.stderr');args=['/workspaces/.agent-state/kprog-ck/perf-tool/perf','report','-D','-i',str(raw/'host-perf.data')]
  with err.open('wb') as ef:
   p=subprocess.Popen(args,stdout=subprocess.PIPE,stderr=ef,text=True,stdin=subprocess.DEVNULL)
   for line in p.stdout:
    a=pattern.match(line)
    if not a:continue
    total+=1;t=int(a[1])/1e9+hoff-grt+gup;pid=int(a[3]);ip=int(a[5],16);period=int(a[6])
    for phase,w in windows.items():
     if not w['start']<=t<w['end']:continue
     pids[phase][pid]+=1
     if pid!=qemu:continue
     name,offset=resolve(phase,ip);counts[phase][name]+=1;periods[phase][name]+=period;timebounds.setdefault(phase,[t,t]);timebounds[phase][0]=min(timebounds[phase][0],t);timebounds[phase][1]=max(timebounds[phase][1],t)
     if name.startswith('bpf_prog_'):hot[phase,name][offset]+=period
   rc=p.wait()
  assert rc==0,(rc,err.read_text()[-1200:]);phases={}
  for phase,w in windows.items():
   assert sum(counts[phase].values())>0 and any(n.startswith('bpf_prog_') for n in counts[phase]);phases[phase]=dict(window=w,symbol_snapshot=tables[phase][2],own_qemu_pid=qemu,pid_sample_counts=dict(pids[phase]),own_sample_time_bounds=timebounds[phase],sample_count=sum(counts[phase].values()),period_sum=sum(periods[phase].values()),workload=work[phase],symbols={n:dict(samples=counts[phase][n],period_sum=v,periods_per_second=v/w['duration'],periods_per_total_bogo_op=v/(w['duration']*work[phase]['total_ops_per_second'])) for n,v in periods[phase].items()},hot_bpf_offsets={n:dict(v.most_common(30)) for (ph,n),v in hot.items() if ph==phase})
  result=dict(stats=stats,profile_guest_exit=case['guest-exit.txt'],profile_perf_exit=case.get('perf-exit.txt'),perf_report_returncode=rc,perf_report_command=args,scope='perf exit is retained explicitly (e.g.143); report0/readable samples do not prove clean capture completion. Own-QEMU and in-phase BPF samples required. PMU/skid/observer and sequential-case limits apply.',inputs=[source(appfile),source(raw/'host-perf.data'),source(raw/'clock.txt'),source(raw/'host-rt-minus-uptime.txt')],total_guest_samples=total,phases=phases);dest=OUT/('stats'+str(stats)+'-pmu.json');dest.write_text(json.dumps(result,indent=2)+'\n');r['cases'].append(dict(stats=stats,result=source(dest),guest_exit=case['guest-exit.txt'],perf_exit=case.get('perf-exit.txt'),perf_report_returncode=rc,throughput_ratio=work['post_rejit']['total_ops_per_second']/work['baseline']['total_ops_per_second'],sockfd_ratio=work['post_rejit']['by_stressor']['sockfd']/work['baseline']['by_stressor']['sockfd']));save()
 r.update(controller_status=0,phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
