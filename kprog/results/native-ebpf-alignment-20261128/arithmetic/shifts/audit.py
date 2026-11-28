"""Inspect actual embedded frontend shifts, preserving candidates and provenance."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import collections,hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
INV=ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory'
SSA=r'%[-a-zA-Z$._0-9]+';VALUE=r'(?:'+SSA+r'|-?\d+|undef|poison|true|false)'
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def upper(v,width,defs,trail=frozenset()):
 if v in ['true','false']:return int(v=='true')
 if re.fullmatch(r'-?\d+',v):return int(v)%(1<<width)
 if v in trail or v not in defs:return None
 rhs=defs[v]['ir'].split(' = ',1)[-1];trail=trail|{v}
 m=re.match(r'and i(\d+) ('+VALUE+r'), ('+VALUE+r')(?:,|$)',rhs)
 if m:
  values=[upper(x,int(m[1]),defs,trail) for x in [m[2],m[3]]]
  known=[x for x in values if x is not None];return min(known) if known else None
 m=re.match(r'select i1 [^,]+, i(\d+) ('+VALUE+r'), i\d+ ('+VALUE+r')(?:,|$)',rhs)
 if m:
  values=[upper(x,int(m[1]),defs,trail) for x in [m[2],m[3]]]
  return max(values) if all(x is not None for x in values) else None
 m=re.match(r'phi i(\d+) (.*)',rhs)
 if m:
  vals=re.findall(r'\[\s*('+VALUE+r'),',m[2])
  if not vals or len(vals)!=m[2].count('['):return None
  bounds=[upper(x,int(m[1]),defs,trail) for x in vals];return max(bounds) if all(x is not None for x in bounds) else None
 m=re.match(r'(zext|trunc) i(\d+) ('+VALUE+r') to i(\d+)(?:,|$)',rhs)
 if m:
  bound=upper(m[3],int(m[2]),defs,trail)
  return min(bound,(1<<int(m[4]))-1) if bound is not None else None
 return None

def analyze(text):
 lines=text.splitlines();meta={m[1]:m[2] for l in lines if (m:=re.match(r'!(\d+) = (.*)',l))};functions={};sites=[];unparsed=[];cur=None;block='<entry>'
 for no,l in enumerate(lines,1):
  if l.startswith('define '):
   name=re.search(r'@([^ (]+)\(',l)[1];cur=dict(name=name,defs={},blocks={'<entry>':[]},calls=set(),sites=[],other_calls=[]);functions[name]=cur;block='<entry>';continue
  if l=='}':cur=None;continue
  if cur is None:continue
  m=re.match(r'^([-a-zA-Z$._0-9]+):',l)
  if m:block=m[1];cur['blocks'][block]=[];continue
  cur['blocks'][block].append(dict(line=no,ir=l));lhs=re.match(r'\s*('+SSA+r') = ',l)
  if lhs:cur['defs'][lhs[1]]=dict(line=no,block=block,ir=l)
  direct=re.findall(r'\bcall\b[^@\n]*@([^ (]+)\(',l);cur['calls'].update(direct)
  if 'call ' in l and not direct:cur['other_calls'].append(dict(line=no,block=block,ir=l))
  if not re.search(r'= (shl|lshr|ashr)\b',l):continue
  m=re.search(r'= (shl|lshr|ashr)((?: (?:nuw|nsw|exact))*) i(\d+) ('+VALUE+r'), ('+VALUE+r')(?:,|$)',l)
  if not m:unparsed.append(dict(function=cur['name'],line=no,ir=l));continue
  debug=re.search(r'!dbg !(\d+)',l);loc=meta.get(debug[1],'') if debug else '';ident=debug[1] if debug else None;seen=set();fileid=None
  while ident and ident not in seen:
   seen.add(ident);node=meta.get(ident,'');mf=re.search(r'file: !(\d+)',node);ms=re.search(r'scope: !(\d+)',node)
   if mf:fileid=mf[1];break
   ident=ms[1] if ms else None
  cur['sites'].append(len(sites));sites.append(dict(function=cur['name'],line=no,block=block,ir=l,opcode=m[1],flags=m[2].split(),width=int(m[3]),shifted_value=m[4],amount=m[5],debug_location=loc,debug_file=meta.get(fileid,'')))
 summaries={}
 for name,f in functions.items():
  for i in f['sites']:
   s=sites[i];s['amount_unsigned_upper_bound']=upper(s['amount'],s['width'],f['defs']);s['classification']='bounded-below-width' if s['amount_unsigned_upper_bound'] is not None and s['amount_unsigned_upper_bound']<s['width'] else 'review-required'
   if s['amount'].startswith('%'):
    seen=set();todo=[s['amount']]
    while todo:
     v=todo.pop()
     if v in seen or v not in f['defs']:continue
     seen.add(v);todo.extend(re.findall(SSA,f['defs'][v]['ir'].split(' = ',1)[-1]))
    s['amount_definitions']={v:f['defs'][v] for v in sorted(seen)}
  rec=dict(defined_calls=sorted(f['calls']&functions.keys()),other_calls=f['other_calls'],shift_site_indices=f['sites'])
  if any(sites[i]['classification']=='review-required' for i in f['sites']):
   rec['cfg']={b:dict(successors=sorted(set(re.findall(r'label %([-a-zA-Z$._0-9]+)','\n'.join(x['ir'] for x in rows)))),control=[x for x in rows if re.search(r'\b(br |switch |indirectbr |invoke |callbr )|= (icmp|fcmp) ',x['ir'])]) for b,rows in f['blocks'].items()}
  summaries[name]=rec
 return dict(functions=summaries,shift_sites=sites,unparsed_shifts=unparsed,scope='Frontend scalar shifts and defined-call candidates. Upper bounds describe defined operand values only, not absence of poison, C source validity, runtime reachability, corresponding eBPF instructions, or installed-code equivalence.')

r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,objects=[],commands=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 objects=json.loads((INV/'objects.json').read_text());programs=json.loads((INV/'programs.json').read_text());index={}
 for n,old in objects.items():
  path=ROOT/n;assert sha(path)==old['sha256'],n;arch=n.split('/')[3];app=n.split('/')[5];label=arch+'-'+app+'-'+path.stem
  with path.open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  p=subprocess.run(['llvm-dis-18','-o','-','-'],input=bc,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits);(OUT/(label+'.stderr')).write_bytes(p.stderr);r['commands'].append(dict(object=n,args=['llvm-dis-18','-o','-','-'],exit=p.returncode,cpu=16,address_space_bytes=48*1024**3,stderr=label+'.stderr'));assert p.returncode==0,(n,p.returncode)
  a=analyze(p.stdout.decode());a.update(object=n,object_sha256=old['sha256'],architecture=arch,app=app,frontend_ir_sha256=hashlib.sha256(bc).hexdigest(),analysis_ir_sha256=hashlib.sha256(p.stdout).hexdigest());dest=OUT/(label+'.json');dest.write_text(json.dumps(a,indent=2)+'\n');index[n]=a['functions'];counts=collections.Counter(x['classification'] for x in a['shift_sites'])
  r['objects'].append(dict(object=n,object_sha256=old['sha256'],file=dest.name,bytes=dest.stat().st_size,sha256=sha(dest),shift_sites=len(a['shift_sites']),classifications=dict(counts),unparsed=len(a['unparsed_shifts'])));assert sha(path)==old['sha256'];save()
 coverage=[]
 for row in programs:
  funcs=index[row['object']];candidates=[]
  for symbol in row['symbol_candidates']:
   seen=set();todo=[symbol] if symbol in funcs else []
   while todo:
    f=todo.pop()
    if f in seen:continue
    seen.add(f);todo.extend(funcs[f]['defined_calls'])
   candidates.append(dict(symbol=symbol,present=symbol in funcs,reachable_functions=sorted(seen),shift_site_indices=sorted({i for f in seen for i in funcs[f]['shift_site_indices']})))
  coverage.append({**{k:row[k] for k in ['architecture','app','program','object','symbol_resolution']},'candidates':candidates})
 (OUT/'per-program.json').write_text(json.dumps(coverage,indent=2)+'\n')
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 for n,old in objects.items():assert sha(ROOT/n)==old['sha256'],n
 r.update(controller_status=0,program_rows=len(coverage),source_sha256=prep['source_sha256'],scope='Frontend census complete only; amounts requiring review are not defects. No optimizer/native P build, guest, timing, workload, kernel, application, flags, loader, image or root change.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
