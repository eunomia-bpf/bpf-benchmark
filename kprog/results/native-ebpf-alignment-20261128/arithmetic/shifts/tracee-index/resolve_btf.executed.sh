set -e
cd /workspaces/repository
taskset -c 19 python3 - <<'PY'
from pathlib import Path
import hashlib,json,subprocess
out=Path('kprog/results/native-ebpf-alignment-20261128/arithmetic/shifts/tracee-index');p=out/'inspect_consumers.py';s=p.read_text();executed=out/'inspect_consumers.executed.py';assert not executed.exists();executed.write_text(s);p.write_text(s.replace("if not m.get('name') or m.get('name') in", "if m.get('name') in ['', '(anon)'] or m.get('name') in"));compile(p.read_text(),str(p),'exec')
prep=json.loads((out/'preparation.json').read_text());prep['original_inspection_recipe_sha256']=prep.pop('recipe_sha256');prep['corrected_reader_sha256']=hashlib.sha256(p.read_bytes()).hexdigest();prep['reader_correction']='Initial BTF closure omitted named(anon) members. Native consumer records are unchanged; only the two BTF dumps are reread into addenda with full raw-BTF SHA equality.';(out/'preparation.json').write_text(json.dumps(prep,indent=2)+'\n')
for arch in ['x86','arm64']:
 old=json.loads((out/(arch+'-btf-facts.json')).read_text());args=['vendor/build/x86/bpftool/bin/bpftool','-j','btf','dump','file',old['kernel'],'format','raw'];p=subprocess.run(args,capture_output=True);assert p.returncode==0,p.stderr.decode();assert hashlib.sha256(p.stdout).hexdigest()==old['raw_btf_sha256'];types=json.loads(p.stdout)['types'];byid={t['id']:t for t in types}
 def resolve(i):
  while byid[i].get('kind') in ['TYPEDEF','CONST','VOLATILE','RESTRICT','TYPE_TAG']:i=byid[i]['type_id']
  return byid[i]
 def fields(t,base=0):
  result=[]
  for m in t.get('members',[]):
   off=base+m['bits_offset'];child=resolve(m['type_id'])
   if m.get('name') in ['', '(anon)'] and child.get('kind') in ['STRUCT','UNION']:result.extend(fields(child,off))
   else:result.append(dict(name=m['name'],bits_offset=off,type_id=m['type_id'],type_kind=child.get('kind')))
  return result
 facts={}
 for name in ['trace_event_call','sock_common']:
  ts=[t for t in types if t.get('kind')=='STRUCT' and t.get('name')==name];assert len(ts)==1;facts[name]=dict(type=ts[0],fields=fields(ts[0]))
 names={m['name'] for m in facts['trace_event_call']['fields']};assert 'filter' not in names and 'module' in names
 enums=[t for t in types if t.get('kind') in ['ENUM','ENUM64'] and any(v.get('name') in ['TRACE_EVENT_FL_KPROBE','TRACE_EVENT_FL_UPROBE'] for v in t.get('values',[]))]
 result=dict(command=args,returncode=p.returncode,stderr=p.stderr.decode(),raw_btf_sha256=old['raw_btf_sha256'],original_file=arch+'-btf-facts.json',normalized_anonymous_names=['','(anon)'],facts=facts,trace_flag_enums=enums,field_exists=dict(filter=False,module=True))
 (out/(arch+'-btf-anonymous-addendum.json')).write_text(json.dumps(result,indent=2)+'\n');print(arch,result['field_exists'],'state',[m for m in facts['sock_common']['fields'] if m['name']=='skc_state'],'ENUMS',[(v['name'],v['val']) for t in enums for v in t['values'] if 'KPROBE' in v['name'] or 'UPROBE' in v['name']])
PY
