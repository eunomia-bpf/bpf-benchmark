"""Read actual packet context declarations, typed GEPs and defined call graphs."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;os.sched_setaffinity(0,{19})
INV=ROOT/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/alignment-inventory'
NAMES=['__sk_buff','xdp_md','__native_skb_net_device']
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
def textattr(d,n):
 a=d.attributes.get(n);return a.value.decode(errors='replace') if a and isinstance(a.value,bytes) else a.value if a else None
def layout_dwarf(elf):
 layouts=[]
 for cu in elf.get_dwarf_info().iter_CUs():
  for d in cu.iter_DIEs():
   name=textattr(d,'DW_AT_name')
   if d.tag!='DW_TAG_structure_type' or name not in NAMES or 'DW_AT_byte_size' not in d.attributes:continue
   fields=[]
   for m in d.iter_children():
    if m.tag!='DW_TAG_member':continue
    t=m.get_DIE_from_attribute('DW_AT_type');seen=set()
    while t.tag in ['DW_TAG_typedef','DW_TAG_const_type','DW_TAG_volatile_type','DW_TAG_restrict_type'] and t.offset not in seen:
     seen.add(t.offset);t=t.get_DIE_from_attribute('DW_AT_type')
    fields.append(dict(name=textattr(m,'DW_AT_name'),offset=textattr(m,'DW_AT_data_member_location'),type_kind=t.tag))
   item=dict(name=name,size=textattr(d,'DW_AT_byte_size'),fields=fields)
   if item not in layouts:layouts.append(item)
 return layouts

def btf_fields(types,name):
 byid={t['id']:t for t in types};matches=[t for t in types if t.get('kind')=='STRUCT' and t.get('name')==name];result=[]
 def walk(t,base,seen):
  if t['id'] in seen:return
  seen=seen|{t['id']}
  for m in t.get('members',[]):
   off=base+m['bits_offset'];kind=byid[m['type_id']]
   while kind.get('kind') in ['TYPEDEF','CONST','VOLATILE','RESTRICT','TYPE_TAG']:kind=byid[kind['type_id']]
   if m['name'] not in ['', '(anon)']:result.append(dict(name=m['name'],bits_offset=off,bitfield_size=m.get('bitfield_size',0)))
   elif kind.get('kind') in ['STRUCT','UNION']:walk(kind,off,seen)
 for t in matches:walk(t,0,set())
 return dict(type_declarations=matches,fields=result)

def offsets(btf,typ,field):return sorted(set(x['bits_offset']//8 for x in btf[typ]['fields'] if x['name']==field and not x['bits_offset']%8))
def compare(layout,field,btf):
 name=field['name'];off=field['offset'];typ=layout['name']
 if not name:return dict(status='anonymous-container-not-a-semantic-field')
 if name.startswith('__'):return dict(status='private-padding')
 if typ=='xdp_md' and next((x for x in layout['fields'] if x['name']=='data'),{}).get('type_kind')!='DW_TAG_pointer_type':
  target={'ingress_ifindex':['xdp_buff.rxq','xdp_rxq_info.dev','net_device.ifindex'],'rx_queue_index':['xdp_buff.rxq','xdp_rxq_info.queue_index'],'egress_ifindex':['xdp_buff.txq','xdp_txq_info.dev','net_device.ifindex']}.get(name,[])
  return dict(status='public-XDP-view-requires-conversion',rule=target,scope='Known ingress rule fixed in common source6c8fdc70f; raw staged frontend IR predates load-time conversion. Other uses need selected-use review.')
 typ={'__sk_buff':'sk_buff','xdp_md':'xdp_buff','__native_skb_net_device':'net_device'}[typ]
 target='skb_iif' if field['name']=='ingress_ifindex' else field['name'];expected=offsets(btf,typ,target)
 if layout['name']=='__sk_buff' and name=='cb':expected=sorted(set(a+b for a in expected for b in offsets(btf,'qdisc_skb_cb','data')))
 return dict(status=('declared-offset-matches' if expected==[off] else 'declared-offset-differs' if expected else 'kernel-field-not-resolved'),kernel_type=typ,kernel_field=target,expected_offsets=expected,native_offset=off,scope='Declaration comparison only; pointer origin and runtime/width/bit semantics separate.')

def split_elements(s):
 parts=[];start=0;depth=0
 for i,c in enumerate(s):
  if c in '[{<(':depth+=1
  elif c in ']}>)':depth-=1
  elif c==',' and depth==0:parts.append(s[start:i].strip());start=i+1
 parts.append(s[start:].strip());return parts

def analyze(text,layouts,btf):
 defs={};counts={};uses=[];unresolved=[];other_calls=[];fn=None
 for no,line in enumerate(text.splitlines(),1):
  mt=re.match(r'%struct\.('+('|'.join(NAMES))+r')(?:\.\d+)? = type \{ (.*) \}',line)
  if mt:counts[line.split(' = ',1)[0]]=len(split_elements(mt[2]))
  if line.startswith('define '):fn=re.search(r'@([^ (]+)\(',line)[1];defs[fn]=set()
  elif line=='}':fn=None
  if fn:
   direct=re.findall(r'\bcall\b[^@\n]*@([^ (]+)\(',line);defs[fn].update(direct)
   if 'call ' in line and not direct:other_calls.append(dict(function=fn,line=no,ir=line,kind='inline-asm' if ' asm ' in line else 'unresolved-indirect-call'))
   m=re.search(r'getelementptr(?: inbounds)? (%struct\.('+('|'.join(NAMES))+r')(?:\.\d+)?), ptr [^,]+, i\d+ 0, i32 (\d+)',line)
   if not m:
    if 'getelementptr' in line and any('%struct.'+n in line for n in NAMES):unresolved.append(dict(function=fn,line=no,ir=line,reason='GEP shape outside constant first-level field model.'))
    continue
   candidates=[x for x in layouts if x['name']==m[2] and len(x['fields'])==counts.get(m[1])];idx=int(m[3]);item=dict(function=fn,line=no,ir=line,llvm_type=m[1],llvm_element_count=counts.get(m[1]),field_index=idx,layout_candidates=[])
   for x in candidates:
    if idx<len(x['fields']):f=x['fields'][idx];item['layout_candidates'].append(dict(field=f,layout_size=x['size'],comparison=compare(x,f,btf)))
   if not item['layout_candidates']:unresolved.append(item)
   uses.append(item)
 return dict(other_call_instructions=other_calls,defined_calls={k:sorted(v&defs.keys()) for k,v in defs.items()},typed_field_geps=uses,unresolved_ordinal_maps=unresolved,llvm_struct_element_counts=counts)

if __name__ == '__main__':
 r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,commands=[],objects=[],source_sha256={},kernel_layouts={})
 def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
 def run(args,data=None,cpu=16):
  def child():
   resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{cpu})
  p=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL if data is None else None,input=data,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=child)
  r['commands'].append(dict(args=args,cpu=cpu,address_space_bytes=48*1024**3,exit=p.returncode));return p
 try:
  prep=json.loads((OUT/'preparation.json').read_text());r['source_sha256']=prep['source_sha256']
  for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
  inventory=json.loads((INV/'objects.json').read_text());programs=json.loads((INV/'programs.json').read_text());layout_by_arch={};analyses={}
  for arch in ['x86','arm64']:
   kernel=Path(f'/workspaces/.agent-state/kprog-ck/build-{arch}/vmlinux');args=[str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'-j','btf','dump','file',str(kernel),'format','raw'];p=run(args,cpu=19);(OUT/(arch+'-btf.stderr')).write_bytes(p.stderr);assert p.returncode==0
   types=json.loads(p.stdout)['types'];names=['sk_buff','qdisc_skb_cb','xdp_buff','xdp_md','xdp_rxq_info','xdp_txq_info','net_device','skb_shared_info'];btf={n:btf_fields(types,n) for n in names};layout_by_arch[arch]=btf;r['kernel_layouts'][arch]=dict(path=str(kernel),sha256=sha(kernel),fields_file=arch+'-btf.json');(OUT/(arch+'-btf.json')).write_text(json.dumps(btf,indent=2)+'\n');save()
  for n,old in inventory.items():
   if not any('/'+a+'/' in n for a in ['cilium','katran']) or Path(n).name=='cilium_placeholders.native.o':continue
   path=ROOT/n;assert sha(path)==old['sha256'];arch=n.split('/')[3];app=n.split('/')[5];label=arch+'-'+app+'-'+path.stem
   with path.open('rb') as f:
    elf=ELFFile(f);layouts=layout_dwarf(elf);bc=elf.get_section_by_name('.llvmbc').data()
   p=run(['llvm-dis-18','-o','-','-'],bc);(OUT/(label+'-llvm-dis.stderr')).write_bytes(p.stderr);assert p.returncode==0
   result=analyze(p.stdout.decode(),layouts,layout_by_arch[arch]);result.update(object=n,sha256=old['sha256'],architecture=arch,app=app,declared_layouts=layouts,frontend_ir_sha256=hashlib.sha256(bc).hexdigest())
   for x in result['declared_layouts']:
    for f in x['fields']:f['kernel_comparison']=compare(x,f,layout_by_arch[arch])
   dest=OUT/(label+'.json');dest.write_text(json.dumps(result,indent=2)+'\n');analyses[n]=result;r['objects'].append(dict(object=n,sha256=old['sha256'],analysis_file=dest.name,typed_geps=len(result['typed_field_geps']),unresolved_ordinal_maps=len(result['unresolved_ordinal_maps']),defined_functions=len(result['defined_calls'])));assert sha(path)==old['sha256'];save()
  coverage=[]
  for row in programs:
   if row['app'] not in ['cilium','katran']:continue
   result=analyses.get(row['object']);items=[]
   if result:
    calls=result['defined_calls']
    for symbol in row['symbol_candidates']:
     seen=set();pending=[symbol] if symbol in calls else []
     while pending:
      name=pending.pop()
      if name in seen:continue
      seen.add(name);pending.extend(calls[name])
     items.append(dict(symbol=symbol,present=symbol in calls,reachable_defined_functions=sorted(seen),typed_field_gep_indices=[i for i,v in enumerate(result['typed_field_geps']) if v['function'] in seen]))
   coverage.append(dict(architecture=row['architecture'],app=row['app'],program=row['program'],object=row['object'],symbol_resolution=row['symbol_resolution'],audited_object=result is not None,candidates=items,scope='Defined direct-call reachability only; field ordinal map is count-checked DWARF correspondence, not entry-context origin or live branch proof. Other context types, raw/zero-offset accesses, indirect/asm effects remain separate.'))
  (OUT/'per-program.json').write_text(json.dumps(coverage,indent=2)+'\n');r['program_rows']=len(coverage)
  for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
  r.update(controller_status=0,scope='Metadata census completed, not a semantic equality verdict. Unresolved fields/calls and missing candidate symbols remain explicit. No source/P/image/root/kernel/app/timing changes.')
 except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
 finally:r['ended_utc']=now();save()
 raise SystemExit(r['controller_status'])
