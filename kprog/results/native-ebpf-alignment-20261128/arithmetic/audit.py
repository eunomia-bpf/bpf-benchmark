"""Inventory actual div/mod IR sites; retain value and guard evidence, not verdicts."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;os.sched_setaffinity(0,{19})
INV=ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory'
SSA=r'%[-a-zA-Z$._0-9]+';VAL=r'(?:'+SSA+r'|-?\d+|undef|poison|true|false)'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
SOURCE={}
def location(line,meta):
 m=re.search(r'!dbg !(\d+)',line)
 if not m:return None
 ident=m[1];loc=meta.get(ident,'');ln=re.search(r'line: (\d+)',loc);col=re.search(r'column: (\d+)',loc);seen=set();fileid=None
 while ident not in seen:
  seen.add(ident);node=meta.get(ident,'');mf=re.search(r'file: !(\d+)',node)
  if mf:fileid=mf[1];break
  ms=re.search(r'scope: !(\d+)',node)
  if not ms:break
  ident=ms[1]
 result=dict(debug_location=loc,line=int(ln[1]) if ln else None,column=int(col[1]) if col else None)
 node=meta.get(fileid,'');mf=re.search(r'filename: "([^"]*)"',node);md=re.search(r'directory: "([^"]*)"',node)
 if not mf:return result
 path=Path(mf[1]);path=path if path.is_absolute() else Path(md[1] if md else '')/path;path=path.resolve();result['file']=str(path)
 if path.is_relative_to(ROOT) and path.is_file():
  if str(path) not in SOURCE:SOURCE[str(path)]=dict(sha256=sha(path),lines=path.read_text(errors='replace').splitlines())
  s=SOURCE[str(path)];result['current_file_sha256']=s['sha256'];n=result['line']
  if n:result['current_source_excerpt']='\n'.join(f'{i+1}: {s["lines"][i]}' for i in range(max(0,n-5),min(len(s['lines']),n+5)))
 return result

def finite(v,width,defs,trail=frozenset()):
 if v in ['true','false']:return {int(v=='true')}
 if re.fullmatch(r'-?\d+',v):return {int(v)%(1<<width)}
 if v in trail or v not in defs:return None
 rhs=defs[v]['ir'].split(' = ',1)[-1];trail=trail|{v};m=re.match(r'select i1 [^,]+, i(\d+) ('+VAL+r'), i\d+ ('+VAL+r')(?:,|$)',rhs)
 if m:
  a=finite(m[2],int(m[1]),defs,trail);b=finite(m[3],int(m[1]),defs,trail);return None if a is None or b is None else a|b
 m=re.match(r'phi i(\d+) (.*)',rhs)
 if m:
  vals=re.findall(r'\[\s*('+VAL+r'),',m[2]);count=m[2].count('[')
  if not vals or len(vals)!=count:return None
  results=[finite(x,int(m[1]),defs,trail) for x in vals];return None if any(x is None for x in results) else set().union(*results)
 m=re.match(r'(zext|sext|trunc) i(\d+) ('+VAL+r') to i(\d+)(?:,|$)',rhs)
 if m:
  values=finite(m[3],int(m[2]),defs,trail)
  if values is None:return None
  src=int(m[2]);dst=int(m[4]);return {(x-(1<<src) if m[1]=='sext' and x&(1<<(src-1)) else x)%(1<<dst) for x in values}
 return None

def slice_ssa(v,defs):
 seen=set();pending=[v]
 while pending:
  x=pending.pop()
  if x in seen or x not in defs:continue
  seen.add(x);pending.extend(re.findall(SSA,defs[x]['ir'].split(' = ',1)[-1]))
 return sorted(seen)

def analyze(text):
 lines=text.splitlines();meta={m[1]:m[2] for l in lines if (m:=re.match(r'!(\d+) = (.*)',l))};functions={};cur=None;block=None;all_sites=[];unparsed=[]
 for no,line in enumerate(lines,1):
  if line.startswith('define '):
   name=re.search(r'@([^ (]+)\(',line)[1];cur=dict(name=name,definitions={},blocks={'<entry>':[]},calls=set(),other_calls=[],sites=[]);functions[name]=cur;block='<entry>';continue
  if line=='}':cur=None;continue
  if cur is None:continue
  mb=re.match(r'^([-a-zA-Z$._0-9]+):',line)
  if mb:block=mb[1];cur['blocks'][block]=[];continue
  cur['blocks'][block].append(dict(line=no,ir=line));lhs=re.match(r'\s*('+SSA+r') = ',line)
  if lhs:cur['definitions'][lhs[1]]=dict(line=no,block=block,ir=line)
  direct=re.findall(r'\bcall\b[^@\n]*@([^ (]+)\(',line);cur['calls'].update(direct)
  if 'call ' in line and not direct:cur['other_calls'].append(dict(line=no,block=block,ir=line,kind='inline-asm' if ' asm ' in line else 'unresolved-indirect-call'))
  if not re.search(r'= (sdiv|udiv|srem|urem)\b',line):continue
  m=re.search(r'= (sdiv|udiv|srem|urem)( exact)? i(\d+) ('+VAL+r'), ('+VAL+r')(?:,|$)',line)
  if not m:unparsed.append(dict(function=cur['name'],line=no,ir=line));continue
  site=dict(function=cur['name'],line=no,block=block,ir=line,opcode=m[1],exact=bool(m[2]),width=int(m[3]),numerator=m[4],denominator=m[5],source=location(line,meta));cur['sites'].append(len(all_sites));all_sites.append(site)
 summaries={}
 for name,f in functions.items():
  defs=f['definitions'];dynamic=False
  for i in f['sites']:
   site=all_sites[i];v=site['denominator'];values=finite(v,site['width'],defs);site['finite_denominator_bitpatterns']=sorted(values) if values is not None else None;site['may_be_zero_from_finite_values']=0 in values if values is not None else None;site['may_be_minus_one_from_finite_values']=(1<<site['width'])-1 in values if values is not None else None;site['denominator_definition']=defs.get(v);site['denominator_ssa_slice']=slice_ssa(v,defs)
   if v.startswith('%') or values is None or 0 in values or (site['opcode'].startswith('s') and (1<<site['width'])-1 in values):dynamic=True
  entry=next((b for b,rows in f['blocks'].items() if any(x['ir'].strip() and not x['ir'].lstrip().startswith(';') for x in rows)), '<entry>')
  record=dict(entry_label=entry,defined_calls=sorted(f['calls']&functions.keys()),other_calls=f['other_calls'],arith_site_indices=f['sites'])
  if dynamic:
   record['ssa_definitions']=defs;record['blocks']={b:dict(successor_labels=sorted(set(re.findall(r'label %([-a-zA-Z$._0-9]+)','\n'.join(x['ir'] for x in rows)))),branch_instructions=[x for x in rows if re.search(r'\b(br |switch |indirectbr |invoke |callbr )',x['ir'])],comparisons=[x for x in rows if re.search(r'= (icmp|fcmp) ',x['ir'])]) for b,rows in f['blocks'].items()}
  summaries[name]=record
 return dict(functions=summaries,arith_sites=all_sites,unparsed_arithmetic=unparsed,scope='Scalar div/mod and defined direct calls only. Finite SSA constants are value facts; CFG/comparison/SSA slices are guard-review evidence, not automatic safety, reachability or semantic proof. Current source excerpts are not historical source equality.')

r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,commands=[],objects=[],source_sha256={})
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(args,data,label):
 p=subprocess.run(args,cwd=ROOT,input=data,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits);(OUT/(label+'.stderr')).write_bytes(p.stderr);r['commands'].append(dict(args=args,input='ELF .llvmbc section; object recorded in phase row',exit=p.returncode,cpu=16,address_space_bytes=48*1024**3,stderr=label+'.stderr'));return p
try:
 prep=json.loads((OUT/'preparation.json').read_text());r['source_sha256']=prep['source_sha256']
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 objects=json.loads((INV/'objects.json').read_text());programs=json.loads((INV/'programs.json').read_text());index={}
 for n,old in objects.items():
  path=ROOT/n;assert sha(path)==old['sha256'];arch=n.split('/')[3];app=n.split('/')[5];label=arch+'-'+app+'-'+path.stem
  with path.open('rb') as f:
   section=ELFFile(f).get_section_by_name('.llvmbc');assert section is not None,n;bc=section.data()
  record=dict(object=n,sha256=old['sha256'],architecture=arch,app=app,frontend_ir_sha256=hashlib.sha256(bc).hexdigest(),phases={});index[n]={}
  for phase,args in [('frontend',['llvm-dis-18','-o','-','-']),('optimized',['opt-18','-passes=default<O3>','-S','-o','-','-'])]:
   p=run(args,bc,label+'-'+phase);assert p.returncode==0,(n,phase,p.returncode);a=analyze(p.stdout.decode());a.update(object=n,object_sha256=old['sha256'],architecture=arch,app=app,phase=phase,analysis_ir_sha256=hashlib.sha256(p.stdout).hexdigest());dest=OUT/(label+'-'+phase+'.json');dest.write_text(json.dumps(a,indent=2)+'\n')
   sites=a['arith_sites'];record['phases'][phase]=dict(file=dest.name,bytes=dest.stat().st_size,sha256=sha(dest),scalar_sites=len(sites),dynamic_operands=sum(x['denominator'].startswith('%') for x in sites),finite_nonzero_sites=sum(x['finite_denominator_bitpatterns'] is not None and 0 not in x['finite_denominator_bitpatterns'] for x in sites),unparsed=len(a['unparsed_arithmetic']))
   index[n][phase]={fn:dict(calls=v['defined_calls'],sites=v['arith_site_indices']) for fn,v in a['functions'].items()}
  r['objects'].append(record);assert sha(path)==old['sha256'];save()
 coverage=[]
 for row in programs:
  phases={}
  for phase,calls in index[row['object']].items():
   candidates=[]
   for symbol in row['symbol_candidates']:
    seen=set();pending=[symbol] if symbol in calls else []
    while pending:
     fn=pending.pop()
     if fn in seen:continue
     seen.add(fn);pending.extend(calls[fn]['calls'])
    candidates.append(dict(symbol=symbol,present=symbol in calls,reachable_defined_functions=sorted(seen),arith_site_indices=sorted(set(i for f in seen for i in calls[f]['sites']))))
   phases[phase]=candidates
  coverage.append(dict(architecture=row['architecture'],app=row['app'],program=row['program'],object=row['object'],symbol_resolution=row['symbol_resolution'],phases=phases,scope='All manifest symbol candidates retained. Defined-call reachability only, not actual input/branch/installed-code proof. OptimizedIR is analysis without live frozen values; not replacement P.'))
 (OUT/'per-program.json').write_text(json.dumps(coverage,indent=2)+'\n');r['program_rows']=len(coverage)
 r['current_source_excerpts']={n:dict(sha256=x['sha256'],unchanged_at_end=sha(Path(n))==x['sha256']) for n,x in SOURCE.items()}
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 for n,old in objects.items():assert sha(ROOT/n)==old['sha256'],n
 r.update(controller_status=0,scope='Census complete only. No divisor-edge/workload equivalence or guard proof. Source/P/manifests/cache/root/image/app/kernel/settings/flags/benchmark untouched.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
