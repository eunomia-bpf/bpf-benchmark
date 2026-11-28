#!/usr/bin/env python3
"""Review the closed census, preserve complete raw records, extract actual native IR."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import collections,datetime,hashlib,json,re,resource,subprocess,tarfile
ROOT=Path('/workspaces/repository');BASE=Path(__file__).resolve().parent;RUN=BASE/'run'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return h.hexdigest()
def seal(p):return dict(path=str(p),size=p.stat().st_size,sha256=sha(p))
def write(name,v):(BASE/name).write_text(json.dumps(v,indent=2)+'\n')
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
 import os
 os.sched_setaffinity(0,{16})
c=json.loads((RUN/'controller.json').read_text());assert c['status']=='complete' and c['returncode']==0
assert c['inputs_unchanged'] and c['targets_unchanged'] and c['query_error_cases']==0
for x in c['inputs']:assert seal(Path(x['path']))==x,x['path']
inv=json.loads((RUN/'inventory.json').read_text())
for g in inv:
 assert seal(Path(g['target']['path']))==g['target']
 for x in g['original_bpf_elfs']:assert seal(Path(x['path']))==x
counts=collections.defaultdict(collections.Counter);sites={}
for x in c['cases']:
 assert x['returncode']==0 and x['source_unchanged']
 for k in ('result_file','stderr_file'):assert seal(Path(x[k]['path']))==x[k]
 v=json.loads(Path(x['result']).read_text());assert v['errors']==0
 a=counts[x['arch']+'/'+x['app']];a['objects']+=1
 for k in ('predicate_rows','resolved_false_predicates','changed_byte_offsets','poisoned_relocations','relocation_errors'):a[k]+=x[k]
 for r in v['rows']:
  if r['kind'] not in (2,8,10):continue
  key=(x['arch'],x['app'],r['kind'],re.sub(r'\[\d+\] ','',r['spec']),r['new_val'],r['poison'],r['status'])
  if key not in sites:sites[key]=dict(arch=x['arch'],app=x['app'],kind=r['kind'],spec=key[3],resolved_value=r['new_val'],poison=r['poison'],status=r['status'],record_count=0,object_paths=set(),example=dict(source=x['source'],result=x['result'],row=r))
  sites[key]['record_count']+=1;sites[key]['object_paths'].add(x['source']['path'])
for x in sites.values():x['object_paths']=sorted(x['object_paths'])
write('predicate-sites.json',list(sites.values()))
# These are evidence probes for confirmed mismatch candidates, never compilation selection.
objects=json.loads((ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory/objects.json').read_text())
proofs=[]
for arch in ('x86','arm64'):
 for app,stem,names in [('bcc','biosnoop.native.o',['get_disk']),('tetragon','bpf_execve_event_v61.native.o',['__get_auid','get_task_pid_vnr_by_task']),('tetragon','bpf_cgtracker.native.o',['cgroup_get_parent_id'])]:
  matches=[n for n in objects if n.split('/')[3]==arch and '/'+app+'/' in n and n.endswith('/'+stem)];assert len(matches)==1,matches
  p=ROOT/matches[0];assert sha(p)==objects[matches[0]]['sha256']
  with p.open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  cmd=['llvm-dis-18','-o','-','-'];r=subprocess.run(cmd,input=bc,capture_output=True,preexec_fn=limits);assert r.returncode==0,r.stderr
  ir=r.stdout.decode();functions={}
  for name in names:
   fs=re.findall(r'^define[^\n]*@'+re.escape(name)+r'\([^\n]*\n.*?^}',ir,re.M|re.S);assert len(fs)==1,(p,name)
   functions[name]=fs[0]
  layouts=[s for s in ir.splitlines() if s.startswith(('%struct.task_struct___local =','%struct.request___x =','%struct.pid_link =','%struct.kuid_t ='))]
  proofs.append(dict(arch=arch,app=app,object=seal(p),embedded_ir_sha256=hashlib.sha256(bc).hexdigest(),disassembly_command=cmd,exit=r.returncode,functions=functions,llvm_layouts=layouts))
write('native-function-proofs.json',proofs)
summary=dict(collected=datetime.datetime.now(datetime.timezone.utc).isoformat(),source_controller=seal(RUN/'controller.json'),census_parent_pid=1496738,census_process_pid=c['pid'],finished=c['finished'],objects=len(c['cases']),counts=counts,missing_original_elf_groups=c['missing_original_elf_groups'],all_input_target_and_output_hashes_reverified=True,scope=c['scope'],native_proof_objects=len(proofs),unique_predicate_sites=len(sites))
write('collection-review.json',summary)
# Archive only this closed census's raw records and executable, retaining all originals.
paths=sorted(p for p in RUN.iterdir() if p.is_file())+[BASE/'job.log',BASE/'core-query']
manifest=[dict(name=str(p.relative_to(BASE)),size=p.stat().st_size,sha256=sha(p)) for p in paths]
archive=BASE/'census-records.tar.zst'
with archive.open('wb') as out:
 z=subprocess.Popen(['zstd','-3','-T1','-q','-c'],stdin=subprocess.PIPE,stdout=out)
 try:
  with tarfile.open(fileobj=z.stdin,mode='w|') as tar:
   for p in paths:tar.add(p,arcname=str(p.relative_to(BASE)),recursive=False)
 finally:z.stdin.close()
 assert z.wait()==0
seen=[]
z=subprocess.Popen(['zstd','-q','-d','-c',str(archive)],stdout=subprocess.PIPE)
try:
 with tarfile.open(fileobj=z.stdout,mode='r|') as tar:
  for member in tar:
   assert member.isfile();f=tar.extractfile(member);h=hashlib.sha256();size=0
   for b in iter(lambda:f.read(1024*1024),b''):h.update(b);size+=len(b)
   seen.append(dict(name=member.name,size=size,sha256=h.hexdigest()))
finally:z.stdout.close()
assert z.wait()==0 and seen==manifest
for p,m in zip(paths,manifest):assert p.stat().st_size==m['size'] and sha(p)==m['sha256']
write('census-archive.json',dict(archive=seal(archive),members=manifest,member_count=len(manifest),logical_bytes=sum(x['size'] for x in manifest),every_decompressed_member_and_original_verified=True,originals_deleted=False))
print(json.dumps(summary));print(json.dumps(dict(archive=seal(archive),members=len(manifest))))
