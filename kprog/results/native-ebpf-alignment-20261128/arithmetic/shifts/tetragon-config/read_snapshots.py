"""Decode only already-captured Tetragon config maps, with explicit binding gaps."""
from pathlib import Path
import collections,hashlib,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
BASE=ROOT/'kprog/results/native-ebpf-alignment-20261128/runtime-plan-audit'
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def decode(value,layout):
 fields=layout['event_config']['fields'];reg=layout['config_reg_arg'];u32=lambda n:int.from_bytes(value[n:n+4],'little')
 result=dict(func_id=u32(fields['func_id']),syscall=u32(fields['syscall']),flags=u32(fields['flags']),slots=[])
 for i in range(8):
  base=fields['reg_arg']+i*reg['size'];size=value[base+reg['fields']['size']];meta=u32(fields['arm']+i*4) if i<5 else None
  result['slots'].append(dict(index=i,register_offset=int.from_bytes(value[base+reg['fields']['offset']:base+reg['fields']['offset']+2],'little'),size=size,shift_u8=(64-size*8)&255,arg_meta=meta,pt_regs=bool(meta&128) if meta is not None else None,preload=bool(meta&256) if meta is not None else None,scope='Only slots0..4 have matching arm[] metadata here. This is a captured value, not a taken path or original program-map identity.'))
 return result
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,snapshots=[],archive_parts=[],map_value_variants=[],plan_candidates=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 plan_archive=json.loads((BASE/'runtime-plans-archive.json').read_text());assert sha(ROOT/plan_archive['path'])==plan_archive['sha256'];assert (BASE/'runtime-plans.json').stat().st_size==plan_archive['uncompressed']['bytes'] and sha(BASE/'runtime-plans.json')==plan_archive['uncompressed']['sha256']
 source=json.loads((BASE/'sources.json').read_text());archive=next(x for x in source['archives'] if x['architecture']=='x86' and x['group']=='five');wanted={x['member']:x for x in source['members'] if x['architecture']=='x86' and x['app']=='tetragon' and x['member'].endswith('/snapshot.json')};r['expected_snapshots']=len(wanted);assert len(wanted)==prep['expected_snapshots'];seen=set();variants={};save()
 for x in archive['parts']:
  p=ROOT/x['path'];assert p.stat().st_size==x['bytes'] and sha(p)==x['sha256'];assert subprocess.check_output(['git','rev-parse','HEAD:'+x['path']],cwd=ROOT,text=True).strip()==x['git_blob'];r['archive_parts'].append(x)
 cat=subprocess.Popen(['cat',*[str(ROOT/x['path']) for x in archive['parts']]],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE);dec=subprocess.Popen(['zstd','-d','-c'],stdin=cat.stdout,stdout=subprocess.PIPE);cat.stdout.close()
 with tarfile.open(fileobj=dec.stdout,mode='r|') as tf:
  for member in tf:
   if not member.isfile():continue
   name=str(Path(*Path(member.name).parts[1:]))
   if name not in wanted:continue
   raw=tf.extractfile(member).read();expected=wanted[name];assert len(raw)==expected['bytes'] and hashlib.sha256(raw).hexdigest()==expected['sha256'];assert name not in seen;seen.add(name);snap=json.loads(raw);maps=[]
   for m in snap['maps']:
    if m['name']!='config_map':continue
    row=dict(shape={k:m[k] for k in ['id','name','type','key_size','value_size','max_entries','flags']},queries=[])
    for q in m.get('queries',[]):
     item=dict(raw=q);data=None
     if isinstance(q.get('value'),str):
      try:data=bytes.fromhex(q['value'])
      except ValueError:pass
     if q.get('returncode')==0 and type(q.get('key')) is int and q['key']==0 and data is not None and m['type']==2 and m['key_size']==4 and len(data)==m['value_size']==prep['layouts']['x86']['event_config']['size']:
      digest=hashlib.sha256(data).hexdigest();key=(m['id'],digest);item['value_sha256']=digest
      if key not in variants:variants[key]=dict(map_id=m['id'],value_sha256=digest,value_hex=data.hex(),decoded=decode(data,prep['layouts']['x86']),observations=[])
      variants[key]['observations'].append(dict(snapshot=name,uptime=snap['uptime']));item['decoded_variant']=dict(map_id=m['id'],value_sha256=digest)
     else:item['decode_status']='not-decoded: retain status/key/shape/value rather than infer zero'
     row['queries'].append(item)
    maps.append(row)
   r['snapshots'].append(dict(source=expected,uptime=snap['uptime'],programs=snap['programs'],config_maps=maps));save()
 dec.stdout.close();assert cat.wait()==0 and dec.wait()==0;assert seen==set(wanted),(len(seen),len(wanted));r['map_value_variants']=list(variants.values())
 plans=json.loads((BASE/'runtime-plans.json').read_text())
 for p in plans['plans']:
  if p['architecture']!='x86' or p['app']!='tetragon':continue
  maps=[dict(name=m['name'],plan_shape=m['plan_shape'],observed_map_id_candidates=[s['id'] for s in m['observed_kernel_name_candidates']]) for m in p['lookup_maps'] if m['name']=='config_map']
  if maps:r['plan_candidates'].append(dict(cache_key=p['cache_key'],entry=p['entry'],proof_origin=p['proof_origin'],plan_origin=p['plan_origin'],maps=maps,scope='Existing same-name/shape candidates only. Native map pointer and original eBPF program-map identity are not resolved by this list.'))
 maps=[m for s in r['snapshots'] for m in s['config_maps']];queries=[q for m in maps for q in m['queries']];slots=[s for v in variants.values() for s in v['decoded']['slots'] if s['arg_meta'] is not None];flagged=[s for s in slots if s['pt_regs']]
 r.update(controller_status=0,verified_snapshots=len(seen),config_map_observations=len(maps),unique_map_ids=sorted({m['shape']['id'] for m in maps}),query_returncodes=dict(collections.Counter(str(q['raw'].get('returncode')) for q in queries)),decoded_map_value_variants=len(variants),flagged_pt_regs_slots=len(flagged),flagged_slot_size_counts=dict(collections.Counter(str(s['size']) for s in flagged)),flagged_slots_outside_resolver_sizes=sum(s['size'] not in [1,2,4,8] for s in flagged),flagged_slots_shift_at_or_above64=sum(s['shift_u8']>=64 for s in flagged),scope='Historical x86 snapshots only. Flagged slot/value classification is not executed-path or original program-map binding, ARM runtime, absence-of-update or full native/eBPF equivalence evidence.')
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
