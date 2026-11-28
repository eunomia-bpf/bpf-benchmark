"""Review the one completed low-I/O pair; task observations are not historical causal proof."""
from pathlib import Path
import collections,hashlib,json,re,statistics
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;OUT=HERE/'host-task-check';TOOLS={'capable','biosnoop','vfsstat','opensnoop','syscount','tcpconnect','tcplife','runqlat'}
def source(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest())
def task(t):
 s=t.get('stat');sched=t.get('schedstat');status=t.get('status','')
 if not isinstance(s,str):return None
 a=s[s.rindex(')')+2:].split()
 if len(a)<37:return None
 d=dict(pid=t['pid'],comm=t['comm'],state=a[0],ppid=int(a[1]),start_ticks=int(a[19]),user_ticks=int(a[11]),system_ticks=int(a[12]),child_user_ticks=int(a[13]),child_system_ticks=int(a[14]),processor=int(a[36]),wchan=t.get('wchan'))
 if isinstance(sched,str):
  z=sched.split()
  if len(z)==3:d['sched']=list(map(int,z))
 if isinstance(status,str):
  for key in ['voluntary_ctxt_switches','nonvoluntary_ctxt_switches','Threads','Cpus_allowed_list']:
   m=re.search(r'^'+key+r':\s*(\S+)',status,re.M)
   if m:d[key]=m[1]
 d['stack']=t.get('stack');return d
def counters(text):return list(map(int,text.splitlines()[0].split()[1:]))
def cpu_rows(app,phase):
 pat=re.compile(r'metrc: \[\d+\]\s+(\S+)\s+(\d+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s*$');out=[]
 for w in app[phase]['workloads']:
  rows={}
  for l in w['stdout'].splitlines():
   a=pat.search(l)
   if a:rows[a[1]]=dict(bogo_ops=int(a[2]),real_seconds=float(a[3]),user_seconds=float(a[4]),system_seconds=float(a[5]),wall_ops_per_second=float(a[6]),cpu_ops_per_second=float(a[7]),raw=l)
  out.append(dict(duration_s=w['duration_s'],command=w['command'],rows=rows))
 return out
def parse_host_task(t):
 if not isinstance(t.get('comm'),str):return None
 z=dict(t);z['pid']=t.get('tid',t.get('pid'));z['comm']=t['comm'].strip();return task(z)
def summarize_host_group(obs,hz):
 first,last=obs[0][1],obs[-1][1];result=dict(pid=first['pid'],comm=first['comm'],start_ticks=first['start_ticks'],ppid=first['ppid'],observations=len(obs),first=obs[0][0],last=obs[-1][0],span_s=obs[-1][0]-obs[0][0],cpu_s=((last['user_ticks']+last['system_ticks'])-(first['user_ticks']+first['system_ticks']))/hz,processors=dict(collections.Counter(t['processor'] for _,t in obs)),wchan=dict(collections.Counter(t['wchan'] for _,t in obs if isinstance(t.get('wchan'),str))))
 if 'sched' in first and 'sched' in last:result['sched_delta']=dict(run_s=(last['sched'][0]-first['sched'][0])/1e9,runqueue_wait_s=(last['sched'][1]-first['sched'][1])/1e9,timeslices=last['sched'][2]-first['sched'][2])
 return result

controller=json.loads((OUT/'controller.json').read_text());assert controller['pid']==1467959 and controller['controller_status']==0 and len(controller['cases'])==1
report=dict(scope='Existing host+guest check1467959 only. Direct-process CPU deltas and sampled waits, no new guest. Snapshot intervals omit process startup/exit tails and are not a causal decomposition of the historical180s anomaly.',controller=source(OUT/'controller.json'),cases=[])
for case in controller['cases']:
 assert case['returncode']==0 and case['guest-exit.txt']=='0' and case['image_matches'];raw=Path(case['raw']);run=Path(case['run_dir']);run=run if run.is_absolute() else ROOT/run;af=run/'details/apps/bcc__set.json';app=json.loads(af.read_text());assert app['status']=='ok';mf=run/'metadata.json';meta=json.loads(mf.read_text());assert meta['bpf_stats']==bool(case['stats']) and meta['samples']==1 and meta['workload_seconds']==10
 capture=raw/'bcc-task-states.jsonl';snaps=[];bad=[];header=None
 with capture.open() as f:
  for no,l in enumerate(f,1):
   try:d=json.loads(l)
   except json.JSONDecodeError as e:bad.append(dict(line=no,error=str(e)));continue
   if d['kind']=='header':assert header is None;header=d
   else:snaps.append(d)
 assert header and snaps and all(a['monotonic']<b['monotonic'] for a,b in zip(snaps,snaps[1:]));hz=header['clock_ticks'];observer=header['observer_pid'];phases={}
 for phase in ['baseline','post_rejit']:
  log=run/'details/shim-logs'/('bcc__set.'+phase+'.log');text=log.read_text();starts=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_start',text,re.M)];ends=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_finish',text,re.M)];assert len(starts)==8 and len(ends)==8;start=max(starts);end=min(ends);ss=[s for s in snaps if start<=s['monotonic']<end];assert len(ss)>=10;groups=collections.defaultdict(list);errors=collections.Counter()
  for s in ss:
   for t in s['tasks']:
    if not(t['comm'].startswith('stress-ng') or t['comm'] in TOOLS or t['pid']==observer):continue
    d=task(t)
    if d is None:errors['unreadable_stat']+=1;continue
    groups[(d['pid'],d['start_ticks'])].append((s['monotonic'],d))
  rows=[]
  for ident,obs in sorted(groups.items()):
   first,last=obs[0][1],obs[-1][1];span=obs[-1][0]-obs[0][0];w=collections.Counter();states=collections.Counter();stacks=collections.Counter();read_errors=collections.Counter()
   for tm,d in obs:
    states[d['state']]+=1
    if isinstance(d['wchan'],str):w[d['wchan'].strip()]+=1
    else:read_errors['wchan']+=1
    if isinstance(d.get('stack'),str):
     frames=[re.sub(r'^\[<[^>]*>\] ','',x) for x in d['stack'].splitlines()];stacks['; '.join(frames[:4]) or 'empty/running']+=1
    elif 'stack' in d and d['stack'] is not None:read_errors['stack']+=1
   row=dict(pid=ident[0],start_ticks=ident[1],comm=first['comm'],ppid=first['ppid'],observations=len(obs),first=obs[0][0],last=obs[-1][0],span_s=span,direct_user_s=(last['user_ticks']-first['user_ticks'])/hz,direct_system_s=(last['system_ticks']-first['system_ticks'])/hz,states=dict(states),wchan=dict(w),sampled_stacks=dict(stacks),read_errors=dict(read_errors),cpu_allowed=first.get('Cpus_allowed_list'),threads=first.get('Threads'),first_processor=first['processor'],last_processor=last['processor'])
   if 'sched' in first and 'sched' in last:row['sched_delta']=dict(run_s=(last['sched'][0]-first['sched'][0])/1e9,runqueue_wait_s=(last['sched'][1]-first['sched'][1])/1e9,timeslices=last['sched'][2]-first['sched'][2])
   for key in ['voluntary_ctxt_switches','nonvoluntary_ctxt_switches']:
    if key in first and key in last:row[key+'_delta']=int(last[key])-int(first[key])
   rows.append(row)
  dt=ss[-1]['monotonic']-ss[0]['monotonic'];cd=[b-a for a,b in zip(counters(ss[0]['cpu_stat']),counters(ss[-1]['cpu_stat']))];oc=[b-a for a,b in zip(ss[0]['observer_cpu'],ss[-1]['observer_cpu'])]
  phases[phase]=dict(shim_log=source(log),window=dict(start=start,end=end,span_s=end-start,start_spread_s=max(starts)-min(starts),end_spread_s=max(ends)-min(ends)),snapshots=len(ss),sampled_first=ss[0]['monotonic'],sampled_last=ss[-1]['monotonic'],max_snapshot_gap_s=max(b['monotonic']-a['monotonic'] for a,b in zip(ss,ss[1:])),cpu_stat_delta_ticks=cd,cpu_stat_names=['user','nice','system','idle','iowait','irq','softirq','steal','guest','guest_nice'][:len(cd)],cpu_stat_span_s=dt,observer_user_s=oc[0],observer_system_s=oc[1],tasks=rows,parse_errors=dict(errors),workloads=cpu_rows(app,phase))
 report['cases'].append(dict(stats=case['stats'],image=case['profile-image.txt'],app_status=app['status'],app=source(af),metadata=source(mf),capture=source(capture),capture_header=header,snapshots_total=len(snaps),malformed_lines=bad,phases=phases))
# Join host realtime snapshots to guest CLOCK_MONOTONIC phase windows using the captured guest clock pair.
for ci,case in enumerate(controller['cases']):
 raw=Path(case['raw']);hf=raw/'host-tasks.jsonl';hosts=[];header=None;malformed=[]
 with hf.open() as f:
  for no,l in enumerate(f,1):
   try:x=json.loads(l)
   except json.JSONDecodeError as e:malformed.append(dict(line=no,error=str(e)));continue
   if x.get('kind')=='header':assert header is None;header=x
   else:hosts.append(x)
 assert header and hosts and all(a['monotonic']<b['monotonic'] for a,b in zip(hosts,hosts[1:]));grt,gup=map(float,(raw/'clock.txt').read_text().split());offset=grt-gup;hz=header['clock_ticks'];cr=report['cases'][ci];qids={q['pid'] for x in hosts for q in x['own_qemu']};assert len(qids)==1,qids
 info=dict(capture=source(hf),header=header,snapshots_total=len(hosts),malformed_lines=malformed,clock=source(raw/'clock.txt'),guest_realtime_minus_uptime=offset,host_realtime_minus_monotonic_bounds=[min(x['realtime']-x['monotonic'] for x in hosts),max(x['realtime']-x['monotonic'] for x in hosts)],own_qemu_pid=next(iter(qids)),phases={})
 for phase,g in cr['phases'].items():
  start=g['window']['start']+offset;end=g['window']['end']+offset;ss=[x for x in hosts if start<=x['realtime']<end];assert len(ss)>=8,(phase,len(ss));threads=collections.defaultdict(list);processes=collections.defaultdict(list);affinities=collections.defaultdict(set)
  for x in ss:
   for q in x['own_qemu']:
    assert q['pid']==info['own_qemu_pid']
    for t in q['threads']:
     z=parse_host_task(t)
     if z is None:continue
     key=(z['pid'],z['start_ticks']);threads[key].append((x['realtime'],z))
     if isinstance(t.get('affinity'),list):affinities[key].add(tuple(t['affinity']))
   for t in x['visible_main_processes']:
    z=parse_host_task(t)
    if z:processes[(z['pid'],z['start_ticks'])].append((x['realtime'],z))
  rows=[]
  for key,obs in sorted(threads.items()):
   v=summarize_host_group(obs,hz);v['affinities']=[list(a) for a in sorted(affinities[key])];rows.append(v)
  prows=sorted([summarize_host_group(obs,hz) for obs in processes.values()],key=lambda x:x['cpu_s'],reverse=True);cpu_delta=[b-a for a,b in zip(counters(ss[0]['host_cpu_stat']),counters(ss[-1]['host_cpu_stat']))]
  info['phases'][phase]=dict(realtime_window=[start,end],snapshot_first=ss[0]['realtime'],snapshot_last=ss[-1]['realtime'],snapshots=len(ss),max_snapshot_gap_s=max(b['realtime']-a['realtime'] for a,b in zip(ss,ss[1:])),max_snapshot_enumeration_s=max(x['snapshot_finished_monotonic']-x['monotonic'] for x in ss),own_qemu_threads=rows,visible_process_group_cpu=prows,host_cpu_delta_ticks=cpu_delta,guest_steal_delta_ticks=dict(zip(g['cpu_stat_names'],g['cpu_stat_delta_ticks']))['steal'],scope='ThreadCPU/schedstat for QEMU; /proc/PID/stat CPU includes process threadgroup for visible main process records. Do not sum the process record and its thread records. schedstat/wchan remain per selected task, not threadgroup. Endpoint spans are explicit, not identical to guest sampled endpoints.')
 cr['host']=info
report['proc_stat_semantics']='Linux fs/proc/array.c do_task_stat(whole=1) uses thread_group_cputime_adjusted for /proc/PID/stat, so direct process CPU includes helper threads but excludes children. /proc/PID/task/TID/stat and schedstat/wchan describe the selected task. Prior main-process-only caveat applies to per-thread state/schedstat visibility, not omission of helper-thread CPU from process-group stat counters.'
report['host_limits']=['Current PID namespace may hide other host contenders; absent visible competitor is not absence of contention.','Guest boot-clock alignment uses a single date+uptime pair; host realtime-minus-monotonic bounds and snapshot enumeration durations are retained.','No PMU or historical host wait data are inferred; current host/guest data cannot prove cause of old3x180s anomaly.']

report['limits']=['Main-process /proc entries only, not every thread; tool helper threads can be missed.','One0.5s snapshot enumerates tasks sequentially, so its timestamp is not an atomic per-task instant.','Wait/stack counts are sampled observations, not exact blocked durations.','CPU deltas cover only first-to-last observations of a PID/starttime identity, never child CPU counters; short-lived tasks and tails can be missed.','The observer adds syscalls/9p output and potential BPF work; its own CPU does not bound its kernel/tracing impact.','One10s pair cannot establish the cause of historical3x180s results or throughput acceptance.']
f=OUT/'task-review.json'
with f.open('x') as w:w.write(json.dumps(report,indent=2)+'\n')
for c in report['cases']:
 for phase,d in c['phases'].items():
  print(json.dumps(dict(stats=c['stats'],phase=phase,window=d['window'],snapshots=d['snapshots'],observer_cpu=d['observer_user_s']+d['observer_system_s'],sockfd=[x for x in d['tasks'] if 'sockf' in x['comm']],tools=[dict(comm=x['comm'],cpu=x['direct_user_s']+x['direct_system_s'],wait=x.get('sched_delta')) for x in d['tasks'] if x['comm'] in TOOLS],workload=d['workloads'])))
