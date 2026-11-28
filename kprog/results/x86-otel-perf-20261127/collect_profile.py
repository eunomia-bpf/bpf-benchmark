"""Collect the completed PMU observation with explicit limits and verified archives."""
import hashlib,json,os,re,struct,subprocess,tarfile,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
out=Path(json.loads((LANE/'otel-performance-profile.json').read_text())['result']);c=json.loads((out/'controller.json').read_text());assert c['controller_status']==0
raw=Path(c['raw']);run=Path(c['run_dir']);d=json.loads((out/'pmu-analysis.json').read_text())
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
record=dict(pid=os.getpid(),started_utc=now(),controller_status=None,raw=str(raw))
def save():(out/'collection-controller.json').write_text(json.dumps(record,indent=2)+'\n')
try:
 save()
 def member(group,n):
  if group=='unwinder':return n.startswith('bpf_prog_') and n.split('_',3)[-1][:15]=='perf_unwind_nat'
  if group=='hash-named functions':return n.startswith('kprog_htab_elem_') or n in ['__htab_map_lookup_elem','lookup_nulls_elem_raw','htab_map_hash']
  return n==group
 groups={}
 for name in ['unwinder','trie_lookup_elem','array_map_lookup_elem','hash-named functions','copy_from_user_nofault']:
  g={ph:dict(samples=sum(v['samples'] for n,v in d['phases'][ph]['symbols'].items() if member(name,n)),sampled_period_per_entry=sum(v['period_per_entry_call'] for n,v in d['phases'][ph]['symbols'].items() if member(name,n))) for ph in ['baseline','post_rejit']}
  g['native_over_ebpf']=g['post_rejit']['sampled_period_per_entry']/g['baseline']['sampled_period_per_entry'];groups[name]=g
 boot={line.split()[2]:int(line.split()[0],16) for line in (raw/'kallsyms.txt').read_text().splitlines() if len(line.split())>=3}
 objects=[];inventory=[]
 for p in sorted((raw/'linkcache/native_kernel_link_cache').glob('*.proof.o')):
  if not re.fullmatch(r'[0-9a-f]{16}\.proof\.o',p.name):continue
  nm=subprocess.run(['llvm-nm-18','--defined-only',str(p)],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
  target=nm.returncode==0 and any(line.split()[-1:] == ['perf_unwind_native'] for line in nm.stdout.splitlines())
  inventory.append(dict(path=str(p.relative_to(raw)),bytes=p.stat().st_size,sha256=sha(p),nm_returncode=nm.returncode,nm_diagnostic=nm.stderr,selected_symbol_present=target))
  if target:objects.append(p)
 record['proof_inventory']=inventory;save()
 (out/'proof-inventory.json').write_text(json.dumps(inventory,indent=2)+'\n')
 assert len(objects)==1,objects;obj=objects[0]
 prefix=obj.name.split('.')[0];blob=obj.with_name(prefix+'.blob.bin');relocs=obj.with_name(prefix+'.relocs.bin');trie=boot['trie_lookup_elem']
 input_proof=obj;optimized=list(obj.parent.glob(prefix+'*.frozen.proof.o'));assert len(optimized)<=1,optimized
 if optimized:obj=optimized[0]
 direct=[dict(offset=a,kind=b,target=t) for a,b,t in struct.iter_unpack('<IIQ',relocs.read_bytes()) if t==trie]
 plans=[]
 for p in obj.parent.glob(prefix+'*.link-plan.json'):
  plan=json.loads(p.read_text());plans.append(dict(path=str(p.relative_to(raw)),trie_helper=[h for h in plan['helpers'] if h['name']=='trie_lookup_elem'],lookup_sites=plan['lookup_sites']))
 diagnosis=dict(utc=now(),corpus_status='ok',image=c['profile-image.txt'],entry_counters=d['entry_counters'],entry_per_call_speedup=d['entry_per_call_speedup'],groups=groups,own_qemu_pid=d['own_qemu_pid'],phase_windows=d['windows'],native_unwinder=dict(input_proof=str(input_proof.relative_to(raw)),optimized_proof=str(obj.relative_to(raw)) if optimized else None,object_sha256=sha(obj),blob_bytes=blob.stat().st_size,blob_sha256=sha(blob),direct_trie_relocations=direct,plans=plans),interpretation='Group directions are specific to this observation. PMU differences identify residual work to investigate; they do not establish a causal per-call latency or justify changing a kernel function.',limits='Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.')
 (out/'diagnosis.json').write_text(json.dumps(diagnosis,indent=2)+'\n')
 entry=d['entry_counters']; ebpf=entry['baseline']; native=entry['post_rejit']
 md=f'# Current-image OTel PMU observation\n\nBoth corpus phases succeeded. Entry: eBPF{ebpf['ns_per_call']:.2f}ns, native{native['ns_per_call']:.2f}ns, diagnostic ratio{d['entry_per_call_speedup']:.5f}x. This does not replace full timing.\n\n| Group | eBPF sampled periods / entry | Native | Native / eBPF |\n|---|---:|---:|---:|\n'
 for name,g in groups.items():md+=f'| {name} | {g["baseline"]["sampled_period_per_entry"]:.2f} | {g["post_rejit"]["sampled_period_per_entry"]:.2f} | {g["native_over_ebpf"]:.3f} |\n'
 md+='\n'+diagnosis['interpretation']+'\n\n'+diagnosis['limits']+'\n\nThe native unwind blob has '+str(len(direct))+' direct relocations to the boot trie_lookup_elem address. An inlined native trie body may have no samples at the external kernel symbol; inspect the installed code and work records before interpretation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.\n'
 (out/'README.md').write_text(md)
 sources={str(p.relative_to(ROOT)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in run.rglob('*') if p.is_file()}
 with tarfile.open(raw/'corpus-source.tar.gz','w:gz') as t:
  for p in run.rglob('*'):
   if p.is_file():t.add(p,arcname=str(p.relative_to(ROOT)))
 (out/'corpus-source-files.json').write_text(json.dumps(sources,indent=2)+'\n')
 files={str(p.relative_to(raw)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in raw.rglob('*') if p.is_file()};assert not any(p.is_symlink() for p in raw.rglob('*'))
 with (out/'archive.log').open('wb') as log:
  a=subprocess.Popen(['tar','-C',str(raw.parent),'-cf','-',raw.name],stdout=subprocess.PIPE,stderr=log);b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close();z=subprocess.Popen(['split','-b','48000000','-',str(out/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[a.wait(),b.wait(),z.wait()];assert codes==[0,0,0]
 parts=sorted(out.glob('evidence.tar.zst.part-*'));a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();check={}
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   p=Path(m.name)
   if m.isfile():check[str(Path(*p.parts[1:]))]=dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest())
 b.stdout.close();assert a.wait()==b.wait()==0 and files==check
 record.update(controller_status=0,verified_files=len(files),files=files,archive_returncodes=codes,parts=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=sha(p)) for p in parts])
except Exception:record.update(controller_status=1,exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save();print(json.dumps({k:record.get(k) for k in ['controller_status','verified_files','exception']}),flush=True)
raise SystemExit(record['controller_status'])
