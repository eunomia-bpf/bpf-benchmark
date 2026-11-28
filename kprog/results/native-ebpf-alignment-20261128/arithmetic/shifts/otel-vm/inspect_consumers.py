"""Read actual OTel native shift helpers; preserve source-input and artifact limits."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BASE=OUT.parent
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
SSA=r'%[-a-zA-Z$._0-9]+'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,objects=[],commands=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 for obj in prep['objects']:
  path=ROOT/obj['object'];assert sha(path)==obj['sha256'];old=json.loads((BASE/obj['shift_record']).read_text());targets={s['function'] for s in old['shift_sites'] if s['classification']=='review-required'}
  with path.open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  args=['opt-18','-passes=mem2reg','-S','-o','-','-'];p=subprocess.run(args,input=bc,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits);label=obj['architecture'];(OUT/(label+'.stderr')).write_bytes(p.stderr);r['commands'].append(dict(object=obj['object'],args=args,exit=p.returncode,cpu=16,address_space_bytes=48*1024**3,stderr=label+'.stderr'));assert p.returncode==0,p.stderr.decode();functions={};cur=None
  for no,l in enumerate(p.stdout.decode().splitlines(),1):
   if l.startswith('define '):cur=re.search(r'@([^ (]+)\(',l)[1];functions[cur]=[]
   if cur:functions[cur].append(dict(line=no,ir=l))
   if l=='}':cur=None
  assert targets<=functions.keys();calls=[]
  for caller,rows in functions.items():
   defs={m[1]:row for row in rows if (m:=re.match(r'\s*('+SSA+r') = ',row['ir']))}
   for row in rows:
    m=re.search(r'\bcall\b[^@\n]*@([^ (]+)\((.*)\)',row['ir'])
    if not m or m[1] not in targets:continue
    rec=dict(caller=caller,callee=m[1],line=row['line'],ir=row['ir'])
    if re.match(r'unwinder_(is_done|mark_done)(?:\.\d+)?$',m[1]):
     n=re.search(r', i32 noundef (-?\d+|'+SSA+r')\)',row['ir']);assert n,row['ir'];v=n[1];rec['unwinder_argument']=v;rec['unwinder_integer']=int(v) if re.fullmatch(r'-?\d+',v) else None;seen=set();todo=[v]
     while todo:
      x=todo.pop()
      if x in seen or x not in defs:continue
      seen.add(x);todo.extend(re.findall(SSA,defs[x]['ir'].split(' = ',1)[-1]))
     rec['argument_definitions']={x:defs[x] for x in sorted(seen)}
    calls.append(rec)
  result=dict(architecture=obj['architecture'],object=obj['object'],object_sha256=obj['sha256'],analysis_ir_sha256=hashlib.sha256(p.stdout).hexdigest(),target_functions={n:functions[n] for n in sorted(targets)},direct_callers=calls,original_review_sites=[s for s in old['shift_sites'] if s['classification']=='review-required'],scope='Actual native frontend mem2reg helper/caller evidence only; no new P or traditional BPF/JIT equivalence claim.')
  dest=OUT/(label+'-consumers.json');dest.write_text(json.dumps(result,indent=2)+'\n');r['objects'].append(dict(object=obj['object'],file=dest.name,sha256=sha(dest),bytes=dest.stat().st_size,functions=len(targets),calls=len(calls)));assert sha(path)==obj['sha256'];save()
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 r.update(controller_status=0,scope='Two native frontend inspections complete; source/VM-input/installed/native-eBPF equivalence remains a separate review. No compiler/codegen/guest/app/root/image/kernel/flags/benchmark changes.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
