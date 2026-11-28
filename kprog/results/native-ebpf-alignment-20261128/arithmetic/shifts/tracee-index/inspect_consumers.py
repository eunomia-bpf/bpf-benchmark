"""Inspect actual Tracee consumers and boot-kernel BTF field presence."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BASE=OUT.parent
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():os.sched_setaffinity(0,{16});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def attrs(d,n):
 a=d.attributes.get(n);return a.value.decode() if a and isinstance(a.value,bytes) else a.value if a else None
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,objects=[],commands=[],kernel_btf={})
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 for obj in prep['objects']:
  path=ROOT/obj['object'];assert sha(path)==obj['sha256'];old=json.loads((BASE/obj['shift_record']).read_text());targets={s['function'] for s in old['shift_sites'] if s['classification']=='review-required'};layouts=[]
  with path.open('rb') as f:
   elf=ELFFile(f);bc=elf.get_section_by_name('.llvmbc').data()
   for cu in elf.get_dwarf_info().iter_CUs():
    for d in cu.iter_DIEs():
     if d.tag=='DW_TAG_structure_type' and attrs(d,'DW_AT_name') in ['sock','sock_common'] and 'DW_AT_byte_size' in d.attributes:layouts.append(dict(name=attrs(d,'DW_AT_name'),size=attrs(d,'DW_AT_byte_size'),fields=[dict(name=attrs(m,'DW_AT_name'),offset=attrs(m,'DW_AT_data_member_location'),bit_offset=attrs(m,'DW_AT_data_bit_offset')) for m in d.iter_children() if m.tag=='DW_TAG_member']))
  args=['opt-18','-passes=mem2reg','-S','-o','-','-'];p=subprocess.run(args,input=bc,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limits);label=obj['architecture'];(OUT/(label+'.stderr')).write_bytes(p.stderr);r['commands'].append(dict(object=obj['object'],args=args,exit=p.returncode,cpu=16,address_space_bytes=48*1024**3,stderr=label+'.stderr'));assert p.returncode==0,p.stderr.decode();funcs={};cur=None
  for no,l in enumerate(p.stdout.decode().splitlines(),1):
   if l.startswith('define '):cur=re.search(r'@([^ (]+)\(',l)[1];funcs[cur]=[]
   if cur:funcs[cur].append(dict(line=no,ir=l))
   if l=='}':cur=None
  assert targets<=funcs.keys();aux={x:funcs[x] for x in ['get_sock_state','get_inet_pinet6'] if x in funcs};result=dict(architecture=label,object=obj['object'],object_sha256=obj['sha256'],analysis_ir_sha256=hashlib.sha256(p.stdout).hexdigest(),target_functions={n:funcs[n] for n in sorted(targets)},auxiliary_functions=aux,dwarf_layouts=layouts,original_review_sites=[s for s in old['shift_sites'] if s['classification']=='review-required'])
  dest=OUT/(label+'-consumers.json');dest.write_text(json.dumps(result,indent=2)+'\n');r['objects'].append(dict(object=obj['object'],file=dest.name,sha256=sha(dest),bytes=dest.stat().st_size));assert sha(path)==obj['sha256'];save()
 for arch in ['x86','arm64']:
  kernel=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux';args=[str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'-j','btf','dump','file',str(kernel),'format','raw'];p=subprocess.run(args,stdout=subprocess.PIPE,stderr=subprocess.PIPE);(OUT/(arch+'-btf.stderr')).write_bytes(p.stderr);r['commands'].append(dict(args=args,exit=p.returncode,cpu=19,address_space_bytes=48*1024**3,stderr=arch+'-btf.stderr'));assert p.returncode==0,p.stderr.decode();alltypes=json.loads(p.stdout)['types'];byid={x['id']:x for x in alltypes}
  selected=[t for t in alltypes if t.get('kind')=='STRUCT' and t.get('name') in ['trace_event_call','sock_common']];seen=set();todo=[x['id'] for x in selected];closure=[]
  while todo:
   ident=todo.pop()
   if ident in seen:continue
   seen.add(ident);t=byid[ident];closure.append(t)
   if t.get('kind') in ['STRUCT','UNION']:todo.extend(m['type_id'] for m in t.get('members',[]) if m.get('name') in ['', '(anon)'] or m.get('name') in ['filter','module','skc_state'])
   elif t.get('kind') in ['TYPEDEF','CONST','VOLATILE','RESTRICT','TYPE_TAG']:todo.append(t['type_id'])
  facts=dict(kernel=str(kernel),kernel_sha256=sha(kernel),raw_btf_sha256=hashlib.sha256(p.stdout).hexdigest(),selected_types=selected,anonymous_member_closure=closure);dest=OUT/(arch+'-btf-facts.json');dest.write_text(json.dumps(facts,indent=2)+'\n');r['kernel_btf'][arch]=dict(file=dest.name,sha256=sha(dest),kernel_sha256=facts['kernel_sha256']);save()
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 r.update(controller_status=0,scope='Actual Tracee native frontend and current kernel BTF evidence only. No native build/code generation/guest/P/flags/source/app/kernel/image/root/benchmark change.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
