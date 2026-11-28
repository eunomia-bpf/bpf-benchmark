"""Decode this ARM run using the actual P DWARF; preserve sparse/non-atomic limits."""
from pathlib import Path
import hashlib,json,re,struct
from elftools.elf.elffile import ELFFile
OUT=Path(__file__).resolve().parent;ROOT=Path('/workspaces/repository');c=json.loads((OUT/'controller.json').read_text());RAW=Path(c['raw']);RUN=Path(c['corpus_paths'][0]);app=json.loads((RUN/'details/apps/otelcol-ebpf-profiler__profiling.json').read_text());obj=ROOT/'vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o'
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
      location=ch.attributes['DW_AT_data_member_location'].value;assert isinstance(location,int)
      fields[ch.attributes['DW_AT_name'].value.decode()]=dict(offset=location,**scalar(ch.get_DIE_from_attribute('DW_AT_type')))
    variants.append(dict(size=d.attributes['DW_AT_byte_size'].value,fields=fields))
  unique={json.dumps(x,sort_keys=True):x for x in variants};assert len(unique)==1,(name,len(unique));layouts[name]=next(iter(unique.values()))
def field(data,typename,key,base=0):
 f=layouts[typename]['fields'][key];return int.from_bytes(data[base+f['offset']:base+f['offset']+f['size']],'little',signed=f['signed'])
report=dict(raw=str(RAW),run=str(RUN),source_object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),layouts=layouts,phases={})
for phase in ['baseline','post_rejit']:
 log=(RUN/('details/shim-logs/otelcol-ebpf-profiler__profiling.'+phase+'.log')).read_text();start,end=[float(re.search(r'^\[([\d.]+) .*cmd='+cmd,log,re.M)[1]) for cmd in ['measure_start','measure_finish']];entry=[v for v in app[phase]['bpf'].values() if v['name']=='native_tracer_e'];assert len(entry)==1;entry=entry[0];rows=[]
 for p in sorted((RAW/'observations/data/map-observe').glob('*/snapshot.json'),key=lambda p:float(p.parent.name)):
  d=json.loads(p.read_text());stamp=float(d['uptime'])
  if not start<=stamp<=end:continue
  progs={v['id']:v for v in d['programs']};row=dict(uptime=stamp,entry_present=entry['id'] in progs,stress_pids=d['stress_pids'],metrics=[],records=[],program_arrays=[],pid_mapping_queries=[])
  for m in d['maps']:
   if m['name']=='metrics':row['metrics'].append(dict(map_id=m['id'],values={q['key']:sum(struct.unpack('<'+'Q'*(len(q['value'])//16),bytes.fromhex(q['value']))) for q in m['queries'] if q['returncode']==0}))
   elif m['name']=='perf_progs':row['program_arrays'].append(dict(map_id=m['id'],targets=[dict(slot=q['key'],id=struct.unpack('<I',bytes.fromhex(q['value']))[0],program=progs.get(struct.unpack('<I',bytes.fromhex(q['value']))[0])) for q in m['queries'] if q['returncode']==0]))
   elif m['name']=='pid_page_to_mapping_info'[:15]:row['pid_mapping_queries'].append(dict(map_id=m['id'],queries=m['queries']))
   elif m['name']=='per_cpu_records':
    assert m['value_size']==layouts['PerCPURecord']['size'];stride=(m['value_size']+7)//8*8
    for q in m['queries']:
     if q['returncode']:continue
     data=(p.parent/q['file']).read_bytes();assert len(data)%stride==0
     for cpu in range(len(data)//stride):
      b=data[cpu*stride:(cpu+1)*stride];t=layouts['PerCPURecord']['fields']['trace']['offset'];u=layouts['PerCPURecord']['fields']['state']['offset'];row['records'].append(dict(cpu=cpu,map_id=m['id'],pid=field(b,'Trace','pid',t),stack_len=field(b,'Trace','stack_len',t),pc=field(b,'UnwindState','pc',u),error_metric=field(b,'UnwindState','error_metric',u),unwind_error=field(b,'UnwindState','unwind_error',u),tail_calls=field(b,'PerCPURecord','tailCalls')))
  rows.append(row)
 components=[v for w in app[phase]['workloads'] for v in w.get('components',[])];active=[x for x in rows if x['entry_present']];metrics={}
 for key in [5,6]:
  values=[dict(uptime=x['uptime'],map_id=m['map_id'],value=m['values'].get(key)) for x in active for m in x['metrics']];metrics[str(key)]=values
 report['phases'][phase]=dict(window=[start,end],entry=entry,worker_returncodes=[x['returncode'] for x in components],snapshots=rows,active_snapshots=len(active),metrics=metrics,max_stack_len=max([v['stack_len'] for x in active for v in x['records']],default=None),max_tail_calls=max([v['tail_calls'] for x in active for v in x['records']],default=None),native_installs=[s for s in log.splitlines() if 'native-loader replaced prog=' in s],native_failures=[s for s in log.splitlines() if 'native-loader failed' in s])
report['limits']='Sparse non-atomic snapshots, cumulative per-map counters and socket envelope including startup/teardown. Entry-absent rows remain in full data; active observations are reported separately. Work engagement is not event-delivery, complete interpreter coverage, exact dynamic parity or a performance acceptance. No retry/exclusion is based on counts or ratio.'
(OUT/'work-analysis.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:dict(entry_id=v['entry']['id'],calls=v['entry']['run_cnt_delta'],active_snapshots=v['active_snapshots'],worker_returncodes=v['worker_returncodes'],metrics=v['metrics'],max_stack=v['max_stack_len'],max_tail=v['max_tail_calls'],installs=len(v['native_installs']),failures=len(v['native_failures'])) for k,v in report['phases'].items()},indent=2))
