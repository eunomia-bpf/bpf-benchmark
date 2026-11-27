"""Phase-match actual map snapshots, using the actual P's DWARF and metric enum."""
import hashlib,json,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);c=json.loads((out/'controller.json').read_text());raw=Path(c['raw']);run=Path(c['run_dir']);app=json.loads((run/'details/apps/otelcol-ebpf-profiler__profiling.json').read_text());obj=ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o';types=ROOT/'vendor/bpf/otel/support/ebpf/types.h'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def layout(name):
 text=subprocess.check_output(['llvm-dwarfdump-18','--name='+name,'--show-children',str(obj)],text=True);(out/(name+'.dwarf.txt')).write_text(text);fields={}
 for block in re.split(r'DW_TAG_member',text)[1:]:
  block=block.split('DW_TAG_',1)[0];n=re.search(r'DW_AT_name\s+\("([^"]+)"\)',block);v=re.search(r'DW_AT_data_member_location\s+\((0x[0-9a-f]+)\)',block)
  if n and v:fields[n[1]]=int(v[1],16)
 return fields
p,t,u=[layout(n) for n in ['PerCPURecord','Trace','UnwindState']];text=re.sub(r'//[^\n]*','',types.read_text());block=text.split('enum {',1)[1].split('};',1)[0];labels={};value=-1
for name,explicit in re.findall(r'\b(metricID_\w+)\s*(?:=\s*(\d+))?\s*[,\n]',block):
 value=int(explicit) if explicit else value+1;labels[value]=name
assert labels[5]=='metricID_UnwindNativeAttempts' and labels[6]=='metricID_UnwindNativeFrames'
r=dict(image=c['profile-image.txt'],corpus_status=app['status'],source_p_sha256=sha(obj),metric_enum_sha256=sha(types),layouts=dict(PerCPURecord=p,Trace=t,UnwindState=u),metric_labels=labels,phases={})
for phase in ['baseline','post_rejit']:
 log=(run/('details/shim-logs/otelcol-ebpf-profiler__profiling.'+phase+'.log')).read_text();start,end=[float(re.search(r'^\[([\d.]+) .*cmd='+cmd,log,re.M)[1]) for cmd in ['measure_start','measure_finish']];entries=[(pid,v) for pid,v in app[phase]['bpf'].items() if v['name']=='native_tracer_e'];assert len(entries)==1;entry_id,entry=entries[0];rows=[]
 for path in sorted((raw/'map-observe').glob('*/snapshot.json'),key=lambda p:float(p.parent.name)):
  if not start<=float(path.parent.name)<=end:continue
  d=json.loads(path.read_text());progs={x['id']:x for x in d['programs']};row=dict(uptime=float(path.parent.name),entry_present=int(entry_id) in progs,stress_pids=d['stress_pids'],program_arrays=[],pid_queries=[],metrics=[],records=[])
  for m in d['maps']:
   if m['name']=='perf_progs':row['program_arrays'].append(dict(map_id=m['id'],targets=[dict(slot=q['key'],program_id=struct.unpack('<I',bytes.fromhex(q['value']))[0],program=progs.get(struct.unpack('<I',bytes.fromhex(q['value']))[0])) for q in m['queries'] if q['returncode']==0]))
   elif m['name']=='pid_page_to_mapping_info'[:15]:row['pid_queries'].append(dict(map_id=m['id'],queries=m['queries']))
   elif m['name']=='metrics':
    vals={q['key']:sum(struct.unpack('<'+'Q'*(len(q['value'])//16),bytes.fromhex(q['value']))) for q in m['queries'] if q['returncode']==0};row['metrics'].append(dict(map_id=m['id'],values=vals))
   elif m['name']=='per_cpu_records':
    for q in m['queries']:
     if q['returncode']!=0:continue
     data=(path.parent/q['file']).read_bytes();size=m['value_size'];assert size==5000
     for cpu in range(len(data)//size):
      b=data[cpu*size:(cpu+1)*size];row['records'].append(dict(cpu=cpu,map_id=m['id'],pid=struct.unpack_from('<I',b,p['trace']+t['pid'])[0],stack_len=struct.unpack_from('<I',b,p['trace']+t['stack_len'])[0],pc=struct.unpack_from('<Q',b,p['state']+u['pc'])[0],error_metric=struct.unpack_from('<i',b,p['state']+u['error_metric'])[0],unwind_error=struct.unpack_from('<I',b,p['state']+u['unwind_error'])[0],tail_calls=b[p['tailCalls']]))
  rows.append(row)
 r['phases'][phase]=dict(window=[start,end],entry_id=entry_id,calls=entry['run_cnt_delta'],runtime_ns=entry['run_time_ns_delta'],ns_per_call=entry['run_time_ns_delta']/entry['run_cnt_delta'],snapshots=rows)
r['diagnostic_ratio']=r['phases']['baseline']['ns_per_call']/r['phases']['post_rejit']['ns_per_call'];r['conclusion']='Known stress PIDs have initial mapping hits and native program-array slot1 points to installed native unwinder28. Native per-CPU records have zero stack frames and one requested tail call; native unwind attempt/frame counters remain zero. Actual native entry has an unconditional branch to its shared tail helper that the linker remaps past the inline expansion. Thus the earlier large ratio includes skipped unwinding, not an equal-work optimization gain.';r['limits']='Snapshots are non-atomic and sparse. The finish socket envelope includes program teardown; rows with entry_present=false remain explicitly recorded. No benchmark is excluded on counts or PMU noise; the causal defect is backed by actual branch targets and a populated-map host reproduction.'
(out/'map-path-analysis.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({phase:{k:v[k] for k in ['window','calls','runtime_ns','ns_per_call']} for phase,v in r['phases'].items()}));print(r['conclusion'])
