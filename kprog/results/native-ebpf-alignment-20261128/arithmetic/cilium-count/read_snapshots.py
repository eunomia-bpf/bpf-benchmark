"""Read only already-captured Cilium service map queries, preserving provenance."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,tarfile,traceback,collections
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
BASE=ROOT/'kprog/results/native-ebpf-alignment-20261128/runtime-plan-audit'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,snapshots=[],archive_parts=[],scope='Captured x86 metadata only. Map name/shape/query candidates, not actual original program-map binding, mid-invocation observations or ARM runtime proof.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
def hexdata(value):
 if isinstance(value,str):
  try:return bytes.fromhex(value.removeprefix('0x'))
  except ValueError:return None
 if isinstance(value,list) and all(isinstance(x,int) and 0<=x<256 for x in value):return bytes(value)
 return None
try:
 prep=json.loads((OUT/'preparation.json').read_text())
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
 src=json.loads((BASE/'sources.json').read_text());archive=next(x for x in src['archives'] if x['architecture']=='x86' and x['group']=='five');wanted={x['member']:x for x in src['members'] if x['architecture']=='x86' and x['app']=='cilium' and x['member'].endswith('/snapshot.json')};r['expected_snapshots']=len(wanted);seen=set();save()
 for x in archive['parts']:
  p=ROOT/x['path'];assert p.stat().st_size==x['bytes'] and sha(p)==x['sha256'];r['archive_parts'].append(x)
 cat=subprocess.Popen(['cat',*[str(ROOT/x['path']) for x in archive['parts']]],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL);dec=subprocess.Popen(['zstd','-d','-c'],stdin=cat.stdout,stdout=subprocess.PIPE);cat.stdout.close()
 with tarfile.open(fileobj=dec.stdout,mode='r|') as tf:
  for member in tf:
   if not member.isfile():continue
   name=str(Path(*Path(member.name).parts[1:]))
   if name not in wanted:continue
   data=tf.extractfile(member).read();expected=wanted[name];assert len(data)==expected['bytes'] and hashlib.sha256(data).hexdigest()==expected['sha256'];assert name not in seen;seen.add(name);snap=json.loads(data);maps=[]
   for m in snap['maps']:
    if m['name'] not in ['cilium_lb4_services_v2','cilium_lb4_services_v2'[:15]]:continue
    queries=[]
    for q in m.get('queries',[]):
     item=dict(raw=q);value=hexdata(q.get('value'));key=hexdata(q.get('key_hex',q.get('key')))
     if q.get('returncode')==0 and value is not None and len(value)==12:
      item['decoded_value']=dict(count_u16_le_at4=int.from_bytes(value[4:6],'little'),value_hex=value.hex(),scope='Candidate value layout12/count4 verified in actual bothISA DWARF; backend-slot identity must be established separately.')
      if key is not None and len(key)==12:item['decoded_key']=dict(backend_slot_u16_le_at6=int.from_bytes(key[6:8],'little'),key_hex=key.hex(),scope='Field offset from recorded native declaration. Frontend slot0 only when explicit12-byte key captured.')
     queries.append(item)
    maps.append(dict(shape={k:m[k] for k in ['id','name','type','key_size','value_size','max_entries','flags']},queries=queries))
   r['snapshots'].append(dict(source=expected,uptime=snap['uptime'],programs=snap['programs'],service_map_candidates=maps));save()
 dec.stdout.close();assert cat.wait()==0 and dec.wait()==0;assert seen==set(wanted),(len(seen),len(wanted))
 maps=[m for s in r['snapshots'] for m in s['service_map_candidates']];queries=[q for m in maps for q in m['queries']];r.update(controller_status=0,verified_snapshots=len(seen),service_map_observations=len(maps),unique_shapes=list({json.dumps(m['shape'],sort_keys=True):m['shape'] for m in maps}.values()),query_returncodes=dict(collections.Counter(str(q['raw'].get('returncode')) for q in queries)),successful_value_candidates=sum('decoded_value' in q for q in queries),explicit_frontend_key_value_candidates=sum('decoded_value' in q and q.get('decoded_key',{}).get('backend_slot_u16_le_at6')==0 for q in queries))
 for n,h in prep['source_sha256'].items():assert sha(ROOT/n)==h,n
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
