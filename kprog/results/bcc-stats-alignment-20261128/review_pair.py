"""Review completed pair metrics, CPU accounting, in-phase RO values and actual hot JIT code."""
from pathlib import Path
import collections,hashlib,importlib.util,json,os,re,subprocess,sys,types
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;PAIR=HERE/'paired-profile';sha=lambda b:hashlib.sha256(b).hexdigest();m=types.ModuleType('matplotlib');m.use=lambda *a,**k:None;p=types.ModuleType('matplotlib.pyplot');m.pyplot=p;sys.modules['matplotlib']=m;sys.modules['matplotlib.pyplot']=p;spec=importlib.util.spec_from_file_location('frozen_pair_eval',ROOT/'kprog/docs/archive/native_eval_20260529.py');ne=importlib.util.module_from_spec(spec);sys.modules[spec.name]=ne;spec.loader.exec_module(ne)
def src(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=sha(b))
def clockwork(app):
 pat=re.compile(r'metrc: \[\d+\]\s+(\S+)\s+(\d+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s*$');ph={}
 for phase in ['baseline','post_rejit']:
  samples=[]
  for w in app[phase]['workloads']:
   rows={}
   for l in w['stdout'].splitlines():
    a=pat.search(l)
    if a:rows[a[1]]=dict(bogo_ops=int(a[2]),real_seconds=float(a[3]),user_seconds=float(a[4]),system_seconds=float(a[5]),wall_ops_per_second=float(a[6]),cpu_ops_per_second=float(a[7]),raw_line=l)
   samples.append(dict(duration_s=w['duration_s'],parsed_metrics=ne.workload_metric(w),cpu_rows=rows))
  ph[phase]=samples
 return ph
c=json.loads((PAIR/'controller.json').read_text());assert c['pid']==1454977 and c['controller_status']==0 and len(c['cases'])==2;report=dict(profile_pid=c['pid'],profile_started=c['started_utc'],profile_ended=c['ended_utc'],scope='Same actual completed pair, no rerun. Native code shape/RO probes and workload CPU accounting are separate observations; no global configuration parity or causal throughput claim.',cases=[],long_run_cpu_accounting={})
for case in c['cases']:
 assert case['guest-exit.txt']=='0' and case['image_matches'];raw=Path(case['raw']);run=Path(case['run_dir']);appfile=run/'details/apps/bcc__set.json';app=json.loads(appfile.read_text());assert app['status']=='ok';phases={};boot={}
 for l in (raw/'kallsyms.txt').read_text().splitlines():
  f=l.split()
  if len(f)>=3:boot[int(f[0],16)]=f[2]
 for phase in ['baseline','post_rejit']:
  log=(run/'details/shim-logs'/('bcc__set.'+phase+'.log')).read_text();start=max(float(t) for t in re.findall(r'^\[([\d.]+) .*cmd=measure_start',log,re.M));end=min(float(t) for t in re.findall(r'^\[([\d.]+) .*cmd=measure_finish',log,re.M));mid=(start+end)/2;snaps=[p for p in (raw/'map-observe').glob('*/snapshot.json') if start<=float(p.parent.name)<end];snap=min(snaps,key=lambda p:abs(float(p.parent.name)-mid));data=json.loads(snap.read_text());ro=[x for x in data['maps'] if '.rodata' in x['name']];syms=dict(boot);ks=min([p for p in raw.glob('kallsyms-bpf-*.txt') if start<=float(p.name[len('kallsyms-bpf-'):-4])<end],key=lambda p:abs(float(p.name[len('kallsyms-bpf-'):-4])-mid))
  for l in ks.read_text().splitlines():
   f=l.split()
   if len(f)>=3:syms[int(f[0],16)]=f[2]
  codes=[]
  for name in ['sys_enter','sys_exit','sched_switch']:
   progs=[z for z in app[phase]['bpf'].values() if z['name']==name];assert len(progs)==1;prog=progs[0];candidates=[p for p in (raw/'progdump').glob('*/prog-'+str(prog['id'])+'-'+name+'.jited.bin') if start<=float(p.parent.name)<end];jit=min(candidates,key=lambda p:abs(float(p.parent.name)-mid));b=jit.read_bytes();assert len(b)==prog['bytes_jited'];fp=jit.with_name(jit.name.replace('.jited.bin','.funcs.txt'));funcs=[dict(address=int(a,16),bytes=int(n)) for a,n in (l.split() for l in fp.read_text().splitlines())];assert funcs;assert sum(f['bytes'] for f in funcs)==len(b);sections=[];raw_at=0
   for fi,fun in enumerate(funcs):
    fd=os.memfd_create('actual-bcc-jit')
    try:
     os.write(fd,b[raw_at:raw_at+fun['bytes']]);os.lseek(fd,0,os.SEEK_SET);args=['objdump','-D','-b','binary','-m','i386:x86-64','--no-show-raw-insn','--adjust-vma='+hex(fun['address']),f'/proc/self/fd/{fd}'];proc=subprocess.run(args,pass_fds=(fd,),stdin=subprocess.DEVNULL,capture_output=True,text=True);assert proc.returncode==0,proc.stderr;sections.append('# FUNCTION'+str(fi)+' raw_offset='+str(raw_at)+'\n'+proc.stdout)
    finally:os.close(fd)
    raw_at+=fun['bytes']
   disassembly='\n'.join(sections)
   shape=[];unknown=[]
   for l in disassembly.splitlines():
    a=re.match(r'\s*([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$',l)
    if not a:continue
    op,operand=a[2],a[3] or ''
    def normalize(v):
     addr=int(v[0],16)
     for fi,fun in enumerate(funcs):
      if fun['address']<=addr<fun['address']+fun['bytes']:return 'FUNC'+str(fi)+'+'+hex(addr-fun['address'])
     if addr in syms:return 'SYMBOL('+syms[addr]+')'
     if addr>=0xffff800000000000:unknown.append(hex(addr));return 'UNRESOLVED_HIGH_LITERAL'
     return v[0]
    shape.append(op+' '+re.sub(r'0x[0-9a-f]+',normalize,operand))
   codes.append(dict(name=name,program=prog,jit=src(jit),function_addresses=funcs,funcs_origin=src(fp),disassembly=disassembly,normalized_instruction_shape=shape,unresolved_high_literals=unknown,scope='Normalization retains low constants and resolves exact captured symbols/local branch offsets. Unknown high literals only identify shape; their binding/content equality is NOT established.'))
  phases[phase]=dict(window=dict(start=start,end=end,duration=end-start),map_snapshot=src(snap),map_count=len(data['maps']),readonly_maps=ro,symbol_snapshot=src(ks),hot_code=codes)
 report['cases'].append(dict(stats=case['stats'],guest_exit=case['guest-exit.txt'],perf_exit=case.get('perf-exit.txt'),image=case['profile-image.txt'],app_status=app['status'],app_origin=src(appfile),workload_cpu=clockwork(app),phases=phases))
for stats,run in [('off','x86_kvm_corpus_20261128_061040_622818'),('on','x86_kvm_corpus_20261128_085002_496250')]:
 p=ROOT/'corpus/results'/run/'details/apps/bcc__set.json';report['long_run_cpu_accounting'][stats]=dict(source=src(p),samples=clockwork(json.loads(p.read_text())))
comparisons=[]
for phase in ['baseline','post_rejit']:
 a=report['cases'][0]['phases'][phase];b=report['cases'][1]['phases'][phase]
 for name in ['sys_enter','sys_exit','sched_switch']:
  x=next(z for z in a['hot_code'] if z['name']==name);y=next(z for z in b['hot_code'] if z['name']==name);comparisons.append(dict(phase=phase,name=name,equal_shape=x['normalized_instruction_shape']==y['normalized_instruction_shape'],bytes_off=x['jit']['bytes'],bytes_on=y['jit']['bytes'],unresolved_high_literal_counts=[len(x['unresolved_high_literals']),len(y['unresolved_high_literals'])]))
report['code_shape_comparison']=comparisons;report['limits']=['The2s observer copies full native cache. Baseline has little/no native cache; its volume and resulting tracing/I/O work can be asymmetric. Do not attribute observed short-profile slowdowns solely to native instructions.','Long-run sockfd CPU-time and CPU-normalized ops are descriptive reported metrics, not a causal proof of who blocked/descheduled the worker.','PMU exit143 is not clean0; a separate queued analysis must validate decoding, explicit ownQEMU and actual phase coverage.','RO values only cover observed queried rodata; same shapes/values do not prove all configs, HASH map contents or dynamic work.'];report['reader_correction']='Initial reader treated concatenated JIT subprograms as one contiguous VMA. Original recipe/report retained; corrected per-function byte lengths/actual bases, no profile rerun.';(PAIR/'case-review.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(report['cases']),shapes=comparisons),indent=2))
