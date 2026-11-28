"""Compare the actual May29 stats-on counters with Nov28; inspect retained Cilium code."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import collections,csv,difflib,hashlib,io,json,os,subprocess
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
os.sched_setaffinity(0,{19})
def seal(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest())
runs={'cilium':{'may29':'x86_kvm_corpus_20260529_033517_489159','nov28':'x86_kvm_corpus_20261128_091645_012670'},
      'tetragon':{'may29':'x86_kvm_corpus_20260529_045551_393389','nov28':'x86_kvm_corpus_20261128_094333_560478'}}
result={'scope':'Raw actual-run counters, all records preserved; >=100 is the original May29 parser aggregate, not a new filter. Cross-run IDs/truncated names do not pair attachments. Object comparison is static, relocations unapplied, not May29 installed bytes.','runs':{},'cilium_objects':{}}
allrows=[]
for app,versions in runs.items():
 result['runs'][app]={}
 for version,run in versions.items():
  p=next((ROOT/'corpus/results'/run/'details/apps').glob('*.json'));j=json.loads(p.read_text());v={'input':seal(p),'metadata':seal(ROOT/'corpus/results'/run/'metadata.json'),'status':j['status'],'phases':{}};result['runs'][app][version]=v
  for phase in ['baseline','post_rejit']:
   rows=list(j[phase]['bpf'].values());retained=[r for r in rows if r.get('run_cnt_delta',0)>=100]
   n=sum(r.get('run_cnt_delta',0) for r in retained);t=sum(r.get('run_time_ns_delta',0) for r in retained)
   groups=collections.defaultdict(lambda:dict(calls=0,time_ns=0,instances=0))
   for r in rows:
    calls=r.get('run_cnt_delta',0);elapsed=r.get('run_time_ns_delta',0)
    allrows.append([app,version,phase,r['id'],r['name'],r['type'],calls,elapsed,elapsed/calls if calls else '',int(calls>=100),r.get('bytes_jited'),r.get('bytes_xlated')])
    if calls>=100:
     g=groups[r['name']];g['calls']+=calls;g['time_ns']+=elapsed;g['instances']+=1
   for g in groups.values():g.update(ns_per_call=g['time_ns']/g['calls'],call_fraction=g['calls']/n,aggregate_contribution_ns=g['time_ns']/n)
   v['phases'][phase]=dict(total_programs=len(rows),retained_programs=len(retained),positive_programs=sum(r.get('run_cnt_delta',0)>0 for r in rows),calls=n,time_ns=t,ns_per_call=t/n,groups=groups)
  v['per_call_speedup']=v['phases']['baseline']['ns_per_call']/v['phases']['post_rejit']['ns_per_call']
with (OUT/'per-program.tsv').open('w') as f:
 w=csv.writer(f,delimiter='\t',lineterminator='\n');w.writerow(['app','version','phase','id','truncated_name','type','calls','time_ns','ns_per_call','may29_parser_retained','jited_bytes','xlated_bytes']);w.writerows(allrows)
for label,p in [('retained-reference',Path('/workspaces/kprog-raw/paper-tree-untracked/vendor/build/native-bpf/x86/stage/cilium/bpf_lxc.native.o')),('current-stage',ROOT/'vendor/build/native-bpf/x86/stage/cilium/bpf_lxc.native.o')]:
 b=p.read_bytes();e=ELFFile(io.BytesIO(b));tab=e.get_section_by_name('.symtab');s=next(s for s in tab.iter_symbols() if s.name=='cil_from_container');sec=e.get_section(s['st_shndx']);start=s['st_value']-sec['sh_addr'];code=sec.data()[start:start+s['st_size']]
 dis=subprocess.check_output(['llvm-objdump','-dr','--no-show-raw-insn','--disassemble-symbols=cil_from_container',str(p)],text=True)
 dwarf=subprocess.check_output(['llvm-dwarfdump','--debug-info',str(p)],text=True)
 (OUT/(label+'.dis')).write_text(dis)
 producer=[line.strip() for line in dwarf.splitlines() if 'DW_AT_producer' in line or 'DW_AT_comp_dir' in line][:4]
 result['cilium_objects'][label]=dict(input=seal(p),symbol='cil_from_container',symbol_bytes=len(code),symbol_sha256=hashlib.sha256(code).hexdigest(),dwarf_provenance=producer,perf_event_output_relocation_count=dis.count('R_X86_64_PLT32\tbpf_perf_event_output'))
old=(OUT/'retained-reference.dis').read_text().splitlines(True);new=(OUT/'current-stage.dis').read_text().splitlines(True)
(OUT/'cilium-entry.diff').write_text(''.join(difflib.unified_diff(old,new,fromfile='retained-reference',tofile='current-stage')))
for filename,path,a,b in [('may29-branch-source.txt','native-sim/x86/native_lab/native_link/src/x86.rs',550,625),('may29-tail-expansion-source.txt','native-sim/x86/native_lab/native_link/src/x86.rs',1330,1430),('may29-native-options.txt','vendor/bpf/Makefile',20,100)]:
 text=subprocess.check_output(['git','show','82ec89cb4:'+path],cwd=ROOT,text=True).splitlines()
 (OUT/filename).write_text('\n'.join(f'{i}: {line}' for i,line in enumerate(text,1) if a<=i<=b)+'\n')
result['tetragon_evidence_gap']='No Tetragon object is present anywhere in the specified retained paper-tree-untracked root. May29 corpus has counters/metadata but no tracked shim logs or code captures. The retained-reference Cilium DWARF comp_dir is October09 reproduction; exact May29 installed-byte identity is not established.'
(OUT/'counter-analysis.json').write_text(json.dumps(result,indent=2)+'\n')
for app,versions in result['runs'].items():
 for version,v in versions.items():
  print(app,version,v['per_call_speedup'],[(ph,p['ns_per_call']) for ph,p in v['phases'].items()])
