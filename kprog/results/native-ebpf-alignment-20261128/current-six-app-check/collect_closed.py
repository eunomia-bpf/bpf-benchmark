"""Collect only completed immutable cases of1481233; no new guest or automatic equality verdict."""
from pathlib import Path
import collections,hashlib,importlib.util,json,re,struct,subprocess,sys,time,traceback,types
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;CASES=HERE/'cases';CASES.mkdir(exist_ok=True);now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def src(p):return dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p))
m=types.ModuleType('matplotlib');m.use=lambda *a,**k:None;mp=types.ModuleType('matplotlib.pyplot');m.pyplot=mp;sys.modules['matplotlib']=m;sys.modules['matplotlib.pyplot']=mp;sp=importlib.util.spec_from_file_location('frozen_six_eval',ROOT/'kprog/docs/archive/native_eval_20260529.py');ne=importlib.util.module_from_spec(sp);sys.modules[sp.name]=ne;sp.loader.exec_module(ne)
def requests(log,app):
 infos={};rows=[];skips=[];unknown=[]
 for no,line in enumerate(log.read_text().splitlines(),1):
  pre=re.match(r'^\[([\d.]+) pid=(\d+) tid=(\d+)\] (.*)',line)
  if not pre:continue
  tm,pid,tid,msg=pre.groups();who=(int(pid),int(tid));z=re.match(r'native-loader jit-info (original|native) fd=(\d+) id=(\d+) type=(\d+) name=(\S*) tag=(\S+) jited_len=(\d+) xlated_len=(\d+)',msg)
  if z:
   kind,fd,ident,typ,name,tag,jit,xlat=z.groups();infos[(*who,kind,int(fd))]=dict(id=int(ident),name=name,type=int(typ),tag=tag,jited_len=int(jit),xlated_len=int(xlat),line=no);continue
  a=re.match(r'native-loader replaced prog=(\S*) original_fd=(\d+) native_fd=(\d+)',msg)
  if a:
   name,ofd,nfd=a.groups();original=infos.get((*who,'original',int(ofd)));native=infos.get((*who,'native',int(nfd)));post=(app.get('post_rejit') or {}).get('bpf',{}).get(str(native['id'])) if native else None;rows.append(dict(line=no,time=float(tm),pid=who[0],tid=who[1],name=name,status='installed',execution_path='direct_unbound_current_entry',original_fd=int(ofd),native_fd=int(nfd),original=original,native=native,post_counters=post,text=line));continue
  if 'native-loader failed' in msg:rows.append(dict(line=no,time=float(tm),pid=who[0],tid=who[1],status='failed',execution_path='failed',text=line));continue
  if 'native-loader skipped feature probe' in msg:skips.append(dict(line=no,text=line));continue
  if msg.startswith('native-loader ') and 'jit-info ' not in msg:unknown.append(dict(line=no,text=line))
 return dict(requests=rows,success_id_associations_complete=all(x.get('original') is not None and x.get('native') is not None for x in rows if x['status']=='installed'),terminal_counts_complete=not unknown,counts=dict(checked=0,direct_installed=sum(x['status']=='installed' for x in rows),failed=sum(x['status']=='failed' for x in rows),feature_probes_skipped=len(skips)),feature_probes=skips,unclassified_native_loader_lines=unknown,scope='Counts TERMINAL shim replacement/failure events, not repeated jit-info or simultaneousprogram count. Frozen guestentry explicitly unsets REQUIRE_BOUND_PROOF; CAPI FdLoadOptions defaults trusted_service_fd=-1 and routes load_from_fd unbound. No checkedB/stock-verifier admission is claimed. Original/nativeIDs require actual samePID/TID/fd info rows; unknown associations stayNone.')
def workers(phase):
 out=[]
 for w in phase.get('workloads',[]):
  components=w.get('components',[w]);out.extend(components)
 return out

def layouts_from_object(obj):
 from elftools.elf.elffile import ELFFile
 def scalar(d):
  while d.tag in ['DW_TAG_typedef','DW_TAG_const_type','DW_TAG_volatile_type','DW_TAG_restrict_type']:d=d.get_DIE_from_attribute('DW_AT_type')
  a=d.attributes;return dict(size=a['DW_AT_byte_size'].value if 'DW_AT_byte_size' in a else None,signed=a['DW_AT_encoding'].value in [5,6] if 'DW_AT_encoding' in a else False)
 layouts={}
 with obj.open('rb') as f:
  dwarf=ELFFile(f).get_dwarf_info()
  for name in ['PerCPURecord','Trace','UnwindState']:
   variants=[]
   for cu in dwarf.iter_CUs():
    for d in cu.iter_DIEs():
     if d.tag!='DW_TAG_structure_type' or d.attributes.get('DW_AT_name') is None or d.attributes['DW_AT_name'].value.decode()!=name or 'DW_AT_byte_size' not in d.attributes:continue
     fields={}
     for ch in d.iter_children():
      if ch.tag=='DW_TAG_member' and 'DW_AT_name' in ch.attributes and 'DW_AT_data_member_location' in ch.attributes:
       loc=ch.attributes['DW_AT_data_member_location'].value;assert isinstance(loc,int);fields[ch.attributes['DW_AT_name'].value.decode()]=dict(offset=loc,**scalar(ch.get_DIE_from_attribute('DW_AT_type')))
     variants.append(dict(size=d.attributes['DW_AT_byte_size'].value,fields=fields))
   unique={json.dumps(x,sort_keys=True):x for x in variants};assert len(unique)==1,(name,len(unique));layouts[name]=next(iter(unique.values()))
 return layouts

def unwind_evidence(raw,phases):
 obj=ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o';frozen=json.loads((HERE.parent/'ordered-image-refresh/controller.json').read_text());assert sha(obj)==frozen['native_P_inputs'][str(obj.relative_to(ROOT/'vendor/build/native-bpf/x86/stage'))];layouts=layouts_from_object(obj);out=dict(source_object=src(obj),layouts=layouts,metric_keys=dict(UnwindNativeAttempts=5,UnwindNativeFrames=6),phases={})
 def field(data,typ,key,base=0):
  f=layouts[typ]['fields'][key];return int.from_bytes(data[base+f['offset']:base+f['offset']+f['size']],'little',signed=f['signed'])
 for ph,p in phases.items():
  rows=[]
  for snap in p['observations']:
   q=raw/'phase-observe'/snap['path']/'unwind-maps/snapshot.json'
   if not q.exists():continue
   d=json.loads(q.read_text());row=dict(snapshot=src(q),uptime=float(d['uptime']),inside_window=p['window']['start']<=float(d['uptime'])<=p['window']['end'],metrics=[],records=[],program_arrays=[],mapping_queries=[]);progs={x['id']:x for x in d['programs']}
   for m in d['maps']:
    if m['name']=='metrics':row['metrics'].append(dict(map_id=m['id'],values={z['key']:sum(struct.unpack('<'+'Q'*(len(z['value'])//16),bytes.fromhex(z['value']))) for z in m['queries'] if z['returncode']==0}))
    elif m['name']=='perf_progs':row['program_arrays'].append(dict(map_id=m['id'],targets=[dict(slot=z['key'],id=struct.unpack('<I',bytes.fromhex(z['value']))[0],program=progs.get(struct.unpack('<I',bytes.fromhex(z['value']))[0])) for z in m['queries'] if z['returncode']==0]))
    elif m['name']=='pid_page_to_mapping_info'[:15]:row['mapping_queries'].append(dict(map_id=m['id'],queries=m['queries']))
    elif m['name']=='per_cpu_records':
     assert m['value_size']==layouts['PerCPURecord']['size'];stride=(m['value_size']+7)//8*8
     for z in m['queries']:
      if z['returncode']:continue
      data=(q.parent/z['file']).read_bytes();assert len(data)%stride==0
      for cpu in range(len(data)//stride):
       b=data[cpu*stride:(cpu+1)*stride];t=layouts['PerCPURecord']['fields']['trace']['offset'];u=layouts['PerCPURecord']['fields']['state']['offset'];row['records'].append(dict(cpu=cpu,map_id=m['id'],pid=field(b,'Trace','pid',t),stack_len=field(b,'Trace','stack_len',t),pc=field(b,'UnwindState','pc',u),unwind_error=field(b,'UnwindState','unwind_error',u),tail_calls=field(b,'PerCPURecord','tailCalls')))
   rows.append(row)
  active=[r for r in rows if r['inside_window']];series={}
  for metric,key in out['metric_keys'].items():
   groups=collections.defaultdict(list)
   for row in active:
    for m in row['metrics']:groups[m['map_id']].append(dict(uptime=row['uptime'],value=m['values'].get(key)))
   series[metric]=[dict(map_id=mid,observations=vals,growth=vals[-1]['value']-vals[0]['value'] if len(vals)>1 and all(v['value'] is not None for v in vals) else None) for mid,vals in groups.items()]
  out['phases'][ph]=dict(rows=rows,metric_growth=series,max_stack_len=max([v['stack_len'] for x in active for v in x['records']],default=None),max_tail_calls=max([v['tail_calls'] for x in active for v in x['records']],default=None))
 out['limits']='SourceC enum keys5/6, NOT Go exportIDs10/11. Sparse/non-atomic cumulative metrics, stack/tail records and progarraytargets establish observed usefulwork, not exact dynamic parity/interpretercoverage/eventdelivery or performance acceptance. Zero entrycounts on tailcalled programs alone do not establish no work.'
 return out

def collect_case(case,job):
 raw=Path(case['raw']);run=Path(case['run_dir']);appfile=run/'details/apps'/(case['app'].replace('/','__')+'.json');app=json.loads(appfile.read_text());meta=run/'metadata.json';metadata=json.loads(meta.read_text());assert metadata['bpf_stats'] and metadata['samples']==1 and metadata['workload_seconds']==10;obsfile=raw/'phase-observe/observer.json';obs=json.loads(obsfile.read_text());phases={}
 for ph in ['baseline','post_rejit']:
  data=app.get(ph) or {};log=run/'details/shim-logs'/(case['app'].replace('/','__')+'.'+ph+'.log');text=log.read_text() if log.exists() else '';starts=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_start',text,re.M)];ends=[float(x) for x in re.findall(r'^\[([\d.]+) .*cmd=measure_finish',text,re.M)];window=dict(start=max(starts),end=min(ends),start_spread_s=max(starts)-min(starts),end_spread_s=max(ends)-min(ends)) if starts and ends else None;programs=data.get('bpf',{});samples=ne.phase_samples(app,ph) if data else [];observations=[]
  for x in obs.get('phases',{}).get(ph,{}).get('snapshots',[]):
   s=dict(x);p=raw/'phase-observe'/x['path'];s['entire_snapshot_inside_window']=bool(window and window['start']<=x['started_monotonic']<=x['ended_monotonic']<=window['end']);s['map_snapshot']=None;s['jit_files']=[];s['link_cache_files']=[]
   mf=p/'maps/snapshot.json'
   if mf.exists():
    d=json.loads(mf.read_text());s['map_snapshot']=src(mf);s['program_stats']=d['programs'];s['map_metadata']=[{k:v for k,v in m.items() if k not in ['queries']} for m in d['maps']];s['readonly_and_progarray_queries']=[m for m in d['maps'] if m['type']==3 or '.rodata' in m['name'] or '.kconfig' in m['name']];info={v['id']:v for v in d['programs']}
   else:info={}
   for jp in sorted((p/'progs').glob('*.jited.bin')):
    ident=int(re.match(r'prog-(\d+)-',jp.name)[1]);fp=jp.with_name(jp.name.replace('.jited.bin','.funcs.txt'));functions=[dict(address=int(a,16),bytes=int(n)) for a,n in (l.split() for l in fp.read_text().splitlines())] if fp.exists() else [];actual=src(jp);expected=info.get(ident,{}).get('bytes_jited');s['jit_files'].append(dict(id=ident,program=info.get(ident),jit=actual,expected_bytes=expected,size_matches=expected==actual['bytes'] if expected is not None else None,functions=functions,function_sizes_match=sum(x['bytes'] for x in functions)==actual['bytes'],functions_file=src(fp) if fp.exists() else None))
   for p in sorted((p/'linkcache').rglob('*')):
    if p.is_file():s['link_cache_files'].append(src(p))
   observations.append(s)
  phases[ph]=dict(programs=programs,active_programs=sum(v.get('run_cnt_delta',0)>0 for v in programs.values()),workloads=data.get('workloads',[]),workers=workers(data),frozen_samples=[dict(total=z[0],by_stressor=z[1],errors=z[2]) for z in samples],window=window,shim_log=src(log) if log.exists() else None,observations=observations)
 report=dict(collected_utc=now(),scope='Closedcase of SAME1481233 only. Guest/app completion, actual unbound native install events and observedwork evidence are separate. No automatic samework/performance verdict, new guest or source change.',controller_case=case,image=job['image'],kernel_sha256=job['kernel_sha256'],recipe_sources=job['source_sha256'],reader=src(Path(__file__).resolve()),frozen_parser=src(ROOT/'kprog/docs/archive/native_eval_20260529.py'),app_source=src(appfile),metadata_source=src(meta),observer_source=src(obsfile),app_status=app['status'],app_error=app.get('error'),selected_workload=app.get('selected_workload'),phases=phases,native_requests=requests(run/'details/shim-logs'/(case['app'].replace('/','__')+'.post_rejit.log'),app))
 if case['app']=='otelcol-ebpf-profiler/profiling':
  try:report['useful_unwind']=unwind_evidence(raw,phases)
  except Exception:report['useful_unwind_error']=traceback.format_exc()
 report['source_anchors']={}
 for name,ranges in {'kprog/perf/one-image/Makefile':[(113,125)],'kprog/libnativeloader/include/native_loader.hpp':[(49,61)],'kprog/libnativeloader/src/native_loader.cpp':[(3415,3421),(3603,3608)],'kprog/libnativeloader/src/native_loader_trusted.cpp':[(3283,3289)],'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/types.h':[(15,36)]}.items():
  p=ROOT/name;ls=p.read_text().splitlines();report['source_anchors'][name]=dict(sha256=sha(p),lines=[dict(line=i,text=ls[i-1]) for a,b in ranges for i in range(a,b+1)])
 report['limits']=['Stats-on entry counters do not by themselves prove deeperwork/eventdelivery; inspect actualmaps/code/workload outputs.','Map observations retain allmetadata but query only selectedarray/progarray/RO entries; HASHcontents and largepercpuvalues remainunobserved except focusedOTelprobes.','Each snapshot captures data sequentially, can add seconds of work or cross the phase; exact spans/commanderrors and sourceSHA retained.','JIT subprograms have separate actual function VMAs; do not disassemble concatenated raw code as one contiguous addressrange.','Current host schedulingconfound is proven in previoussameimage diagnostics; short numbers are not speedupacceptance.','Direct-native admission is not checkedB/stock-verifier coverage; featureprobe skips are not failed native requests.']
 for x in [report['app_source'],report['metadata_source'],report['observer_source']]:assert sha(Path(x['path']))==x['sha256']
 return report

job=json.loads((HERE/'run/controller.json').read_text());assert job['pid']==1481233;token=now().replace('-','').replace(':','')+'-'+str(__import__('os').getpid());dest=HERE/'collections'/token;dest.mkdir(parents=True);result=dict(utc=now(),same_chain_pid=job['pid'],chain_status_at_collection=job['controller_status'],chain_phase_at_collection=job['phase'],chain_source=job['source_sha256'],new_cases=[],existing_cases=[],skipped_active=[],errors=[])
for case in job['checks']:
 key=case['app'].replace('/','__');target=CASES/key
 if not case.get('ended_utc') or not case.get('run_dir'):result['skipped_active'].append(case['app']);continue
 if (target/'review.json').exists():
  old=json.loads((target/'review.json').read_text());assert old['controller_case']==case and sha(Path(old['app_source']['path']))==old['app_source']['sha256'];result['existing_cases'].append(dict(app=case['app'],review=src(target/'review.json')));continue
 assert not target.exists();target.mkdir()
 try:
  review=collect_case(case,job)
  with (target/'review.json').open('x') as f:f.write(json.dumps(review,indent=2)+'\n')
  result['new_cases'].append(dict(app=case['app'],case=case,review=src(target/'review.json'),native_counts=review['native_requests']['counts'],active_programs={p:d['active_programs'] for p,d in review['phases'].items()},unwind_error=review.get('useful_unwind_error')))
 except Exception:
  e=dict(app=case['app'],case=case,error=traceback.format_exc());(target/'review-error.json').write_text(json.dumps(e,indent=2)+'\n');result['errors'].append(e)
result['status']=int(bool(result['errors']));(dest/'controller.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));print('COLLECTION',dest/'controller.json')
raise SystemExit(result['status'])
