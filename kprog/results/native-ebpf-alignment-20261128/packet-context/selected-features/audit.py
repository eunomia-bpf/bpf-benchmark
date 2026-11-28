"""Audit selected Cilium feature macros and direct XDP scratch pointer uses."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;os.sched_setaffinity(0,{19})
INV=ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
def run(args,data=None):
 p=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL if data is None else None,input=data,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits)
 r['commands'].append(dict(args=args,exit=p.returncode,cpu=16,address_space_bytes=48*1024**3));return p
PTR=r'%[-a-zA-Z$._0-9]+'
def scratch_accesses(text):
 funcs={};name=None
 for lineno,line in enumerate(text.splitlines(),1):
  if line.startswith('define '):name=re.search(r'@([^ (]+)\(',line).group(1);funcs[name]=[]
  elif line=='}':name=None
  elif name:funcs[name].append((lineno,line))
 result=[]
 for fn,lines in funcs.items():
  roots={}
  for no,l in lines:
   m=re.match(r'\s*('+PTR+r') = (?:tail )?call ptr @bpf_map_lookup_elem\(ptr[^,]*@cilium_xdp_scratch,',l)
   if m:roots[m[1]]={0}
  if not roots:continue
  offsets=dict(roots);geps={}
  while True:
   changed=False
   for no,l in lines:
    m=re.match(r'\s*('+PTR+r') = getelementptr(?: inbounds)? i(8|16|32|64), ptr ('+PTR+r'), i\d+ (-?\d+)(?:,\s*!.*)?$',l)
    if m and m[3] in offsets:
     vals={x+int(m[2])//8*int(m[4]) for x in offsets[m[3]]};geps[no]=True
     if m[1] not in offsets:offsets[m[1]]=vals;changed=True
   if not changed:break
  accesses=[];unknown=[];uses=[]
  for no,l in lines:
   rhs=l.split(' = ',1)[-1];used=set(re.findall(PTR,rhs))&offsets.keys()
   if not used:continue
   uses.append(dict(line=no,ir=l))
   if no in geps or '@llvm.dbg.' in l or re.search(r'\bicmp (eq|ne) ptr ',l):continue
   m=re.search(r'\b(load|store) (?:volatile )?i(\d+).*?, ptr ('+PTR+r')(?:,|$)',l)
   if m and m[3] in offsets and used=={m[3]}:
    width=(int(m[2])+7)//8
    accesses.append(dict(line=no,operation=m[1],offsets=sorted(offsets[m[3]]),width=width,ir=l))
   else:unknown.append(dict(line=no,ir=l,reason='Pointer use not recognized; downstream range not established.'))
  result.append(dict(function=fn,lookup_roots=list(roots),accesses=accesses,unresolved=unknown,uses=uses,all_direct_uses_recognized=not unknown,max_access_end=max((x+v['width'] for v in accesses for x in v['offsets']),default=None),min_access_offset=min((x for v in accesses for x in v['offsets']),default=None)))
 return result

def declaration_size(text):
 meta={m[1]:m[2] for l in text.splitlines() if (m:=re.match(r'!(\d+) = (.*)',l))}
 line=next((l for l in text.splitlines() if l.startswith('@cilium_xdp_scratch =')),None)
 if line is None:return None
 trace=[]
 def ref(n,field):
  v=meta[n];trace.append('!'+n+' = '+v);return re.search(field+r': !(\d+)',v)[1]
 ident=re.search(r'!dbg !(\d+)',line)[1];ident=ref(ident,'var');ident=ref(ident,'type');members=ref(ident,'elements');trace.append('!'+members+' = '+meta[members])
 field=next(n for n in re.findall(r'!(\d+)',meta[members]) if 'name: "value_size"' in meta[n]);ident=ref(field,'baseType')
 while 'DW_TAG_array_type' not in meta[ident]:ident=ref(ident,'baseType')
 ident=ref(ident,'elements');trace.append('!'+ident+' = '+meta[ident]);counts=[]
 for n in re.findall(r'!(\d+)',meta[ident]):
  trace.append('!'+n+' = '+meta[n]);m=re.search(r'count: (\d+)',meta[n]);
  if m:counts.append(int(m[1]))
 assert len(counts)==1,counts
 return dict(value_size=counts[0],debug_type_trace=trace)

r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,commands=[],objects=[],source_sha256={})
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 inventory=json.loads((INV/'objects.json').read_text());prep=json.loads((OUT/'preparation.json').read_text());r['source_sha256']=prep['source_sha256']
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 for n,x in inventory.items():
  if '/cilium/' not in n or Path(n).name=='cilium_placeholders.native.o':continue
  p=ROOT/n;assert sha(p)==x['sha256'];c=x['embedded_compile_command'];src=ROOT/'vendor/bpf/cilium/bpf'/c[c.index('-main-file-name')+1];assert src.is_file();label=n.split('/')[3]+'-'+p.stem
  args=['clang-18']+[v for v in c if v not in ['','-emit-obj','-fembed-bitcode=all']]+['-E','-dM',str(src)]
  proc=run(args);(OUT/(label+'-macros.txt')).write_bytes(proc.stdout);(OUT/(label+'-preprocess.stderr')).write_bytes(proc.stderr);assert proc.returncode==0,(n,proc.returncode)
  macros=proc.stdout.decode();enabled=bool(re.search(r'^#define ENABLE_BANDWIDTH_MANAGER(?:\s|$)',macros,re.M))
  with p.open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  raw=run(['llvm-dis-18','-o','-','-'],bc);assert raw.returncode==0
  decl=declaration_size(raw.stdout.decode());opt=run(['opt-18','-passes=default<O3>','-S','-o','-','-'],bc);(OUT/(label+'-opt.stderr')).write_bytes(opt.stderr);assert opt.returncode==0
  access=scratch_accesses(opt.stdout.decode());rec=dict(object=n,sha256=x['sha256'],architecture=n.split('/')[3],source=str(src.relative_to(ROOT)),preprocess_returncode=proc.returncode,bandwidth_manager_defined=enabled,embedded_frontend_ir_sha256=hashlib.sha256(bc).hexdigest(),analysis_optimized_ir_sha256=hashlib.sha256(opt.stdout).hexdigest(),scratch_declaration=decl,scratch_direct_functions=access,scope='Default O3 IR analysis from retained actual frontend IR, not replacement P or installed code. Direct uses only; unknown uses retained, not authorized as safe.')
  (OUT/(label+'-analysis.json')).write_text(json.dumps(rec,indent=2)+'\n');r['objects'].append(rec);save();assert sha(p)==x['sha256']
 # Saved runtime plans offer shape/name candidates, not exact program-map ID binding.
 planpath=ROOT/'kprog/results/native-ebpf-alignment-20261128/runtime-plan-audit/runtime-plans.json';plans=json.loads(planpath.read_text());r['runtime_plans_sha256']=sha(planpath);r['scratch_plan_candidates']=[dict(architecture=p['architecture'],entry=p['entry'],cache_key=p['cache_key'],origin=p['plan_origin'],maps=[m for m in p['lookup_maps'] if m['name'] in ['cilium_xdp_scratch','cilium_xdp_scra']]) for p in plans['plans'] if p['app']=='cilium' and any(m['name'] in ['cilium_xdp_scratch','cilium_xdp_scra'] for m in p['lookup_maps'])]
 rows=json.loads((INV/'programs.json').read_text());byobj={x['object']:x for x in r['objects']};coverage=[]
 for row in rows:
  if row['app']!='cilium':continue
  x=byobj.get(row['object']);coverage.append(dict(architecture=row['architecture'],program=row['program'],object=row['object'],symbol_resolution=row['symbol_resolution'],symbol_candidates=row['symbol_candidates'],audited_object=x is not None,bandwidth_manager_defined=x['bandwidth_manager_defined'] if x else None,scratch_functions=[v for v in x['scratch_direct_functions'] if v['function'] in row['symbol_candidates']] if x else [],scope='Only static object/selected symbol candidates; transitive/installed binding separate. Placeholder objects explicitly unanalysed.'))
 (OUT/'per-program.json').write_text(json.dumps(coverage,indent=2)+'\n');r['program_rows']=len(coverage)
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 r['controller_status']=0
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
