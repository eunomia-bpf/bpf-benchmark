"""Inspect Cilium shift helper callers and actual captured configuration facts."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import collections,hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;SHIFTS=OUT.parent
INV=ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory'
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
SSA=r'%[-a-zA-Z$._0-9]+'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def split_args(s):
 parts=[];start=0;depth=0
 for i,c in enumerate(s):
  if c in '([{<':depth+=1
  elif c in ')]}>':depth-=1
  elif c==',' and depth==0:parts.append(s[start:i].strip());start=i+1
 parts.append(s[start:].strip());return parts
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,objects=[],commands=[],captured_plan_constants=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 programs=json.loads((INV/'programs.json').read_text());all_config_names=set()
 for record in prep['objects']:
  path=ROOT/record['object'];assert sha(path)==record['sha256'];a=json.loads((SHIFTS/record['shift_record']).read_text());targets={s['function'] for s in a['shift_sites'] if s['classification']=='review-required' and s['function']!='rol32'}
  with path.open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  p=subprocess.run(['opt-18','-passes=mem2reg','-S','-o','-','-'],input=bc,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits);label=record['architecture']+'-'+path.stem;(OUT/(label+'.stderr')).write_bytes(p.stderr);r['commands'].append(dict(object=record['object'],args=['opt-18','-passes=mem2reg','-S','-o','-','-'],exit=p.returncode,cpu=16,address_space_bytes=48*1024**3,stderr=label+'.stderr'));assert p.returncode==0,p.stderr.decode()
  text=p.stdout.decode();functions={};current=None
  for no,l in enumerate(text.splitlines(),1):
   if l.startswith('define '):current=re.search(r'@([^ (]+)\(',l)[1];functions[current]=[]
   if current:functions[current].append(dict(line=no,ir=l))
   if l=='}':current=None
  assert targets<=functions.keys(),targets-functions.keys();calls=[]
  for caller,lines in functions.items():
   defs={m[1]:row for row in lines if (m:=re.match(r'\s*('+SSA+r') = ',row['ir']))}
   for row in lines:
    m=re.search(r'\bcall\b[^@\n]*@([^ (]+)\((.*)\)',row['ir'])
    if not m or m[1] not in targets:continue
    args=split_args(m[2]);item=dict(caller=caller,callee=m[1],line=row['line'],ir=row['ir'],arguments=args)
    position={'ipcache_lookup4':2,'ipv6_addr_clear_suffix':1,'ipv4_is_in_subnet':2}.get(m[1])
    if position is not None:
     arg=args[position];constant=re.fullmatch(r'i32(?: noundef)? (-?\d+)',arg);item['prefix_argument']=dict(position=position,ir=arg,integer=int(constant[1]) if constant else None)
     todo=re.findall(SSA,arg);seen=set()
     while todo:
      v=todo.pop()
      if v in seen or v not in defs:continue
      seen.add(v);todo.extend(re.findall(SSA,defs[v]['ir'].split(' = ',1)[-1]))
     item['prefix_definitions']={v:defs[v] for v in sorted(seen)}
    calls.append(item)
  configs=sorted({n for f in targets for row in functions[f] for n in re.findall(r'@(__config_[A-Za-z0-9_]+)',row['ir'])});all_config_names.update(configs)
  rows=[x for x in programs if x['object']==record['object']];roots=[dict(program=x['program'],resolution=x['symbol_resolution'],candidates=[dict(symbol=n,present=n in functions) for n in x['symbol_candidates']]) for x in rows];assert all(c['present'] for x in roots for c in x['candidates'])
  result=dict(object=record['object'],object_sha256=record['sha256'],architecture=record['architecture'],frontend_ir_sha256=hashlib.sha256(bc).hexdigest(),analysis_ir_sha256=hashlib.sha256(p.stdout).hexdigest(),original_shift_sites=record['review_sites'],target_functions={f:functions[f] for f in sorted(targets)},direct_callers=calls,referenced_config_names=configs,manifest_roots=roots,scope='Only mem2reg analysis of actual native frontend. All selected manifest candidates retained. Shift guards/flags/calls are evidence, not automatic path/source-C validity or installed-code equivalence.')
  dest=OUT/(label+'.json');dest.write_text(json.dumps(result,indent=2)+'\n');r['objects'].append(dict(object=record['object'],file=dest.name,sha256=sha(dest),bytes=dest.stat().st_size,targets=sorted(targets),calls=len(calls),program_rows=len(roots)));assert sha(path)==record['sha256'];save()
 plans=json.loads((ROOT/'kprog/results/native-ebpf-alignment-20261128/runtime-plan-audit/runtime-plans.json').read_text())
 for p in plans['plans']:
  if p['app']!='cilium':continue
  const=[c for c in p['constants'] if c['name'] in all_config_names]
  if const:r['captured_plan_constants'].append(dict(architecture=p['architecture'],cache_key=p['cache_key'],entry=p['entry'],constants=const,plan_origin=p['plan_origin'],proof_origin=p['proof_origin'],scope='Actual recorded values for this captured plan; not ARM values or a binding to every staged helper/caller.'))
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 for record in prep['objects']:assert sha(ROOT/record['object'])==record['sha256']
 r.update(controller_status=0,program_rows=sum(x['program_rows'] for x in r['objects']),scope='Cilium caller/guard/config evidence collection only. No optimizer beyond mem2reg, replacement P, native compile, source/flags/app/kernel/image/root/workload/timing change.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
