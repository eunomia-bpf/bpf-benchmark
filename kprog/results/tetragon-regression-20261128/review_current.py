"""Join the completed current-code inspection to its captured relocations and kallsyms."""
from pathlib import Path
import collections,hashlib,json,re,struct,subprocess,tarfile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;sha=lambda b:hashlib.sha256(b).hexdigest()
r=json.loads((OUT/'current-code-controller.json').read_text());assert r['pid']==1444133 and r['controller_status']==0 and r['verified_archive_members']==14;data=Path(r['records']).read_bytes();assert len(data)==r['records_bytes'] and sha(data)==r['records_sha256'];x=json.loads(data)
meta=json.loads((ROOT/r['archive_manifest']['path']).read_text());wanted={'tetragon__observer/kallsyms.txt','tetragon__observer/kallsyms-bpf-272.08.txt'}|{next(z['member'] for n,z in p['origins'].items() if n.endswith('.relocs.bin')) for p in x['records']};assert len(wanted)==4
for part in meta['parts']:b=(ROOT/part['path']).read_bytes();assert len(b)==part['bytes'] and sha(b)==part['sha256']
a=subprocess.Popen(['cat',*[str(ROOT/p['path']) for p in meta['parts']]],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();read={}
with tarfile.open(fileobj=b.stdout,mode='r|') as tf:
 for m in tf:
  if not m.isfile():continue
  rel=str(Path(*Path(m.name).parts[1:]))
  if rel not in wanted:continue
  z=tf.extractfile(m).read();v=meta['files'][rel];assert len(z)==v['bytes'] and sha(z)==v['sha256'];assert rel not in read;read[rel]=z
b.stdout.close();assert a.wait()==b.wait()==0 and set(read)==wanted
symbols=collections.defaultdict(list)
for l in (read['tetragon__observer/kallsyms.txt']+b'\n'+read['tetragon__observer/kallsyms-bpf-272.08.txt']).decode().splitlines():
 f=l.split()
 if len(f)>=3:
  z=dict(type=f[1],name=f[2],module=f[3] if len(f)>3 else None)
  if z not in symbols[int(f[0],16)]:symbols[int(f[0],16)].append(z)
review=dict(inspection_pid=r['pid'],scope=r['scope'],inspection_record=dict(path=r['records'],sha256=r['records_sha256'],bytes=r['records_bytes']),additional_join='Read exactly4new fields from the existing archive: two reloc tables, initial kernel kallsyms and late module/BPF snapshot; no mem2reg/proof/blob inspection rerun or new guest.',additional_origins=[dict(member=n,**meta['files'][n]) for n in sorted(wanted)],records=[])
for p in x['records']:
 n=next(z['member'] for name,z in p['origins'].items() if name.endswith('.relocs.bin'));relocs=read[n];assert len(relocs)%16==0;blob=bytes.fromhex(p['blob_hex']);calls=[]
 for at in range(0,len(relocs),16):
  offset,kind,target=struct.unpack_from('<IIQ',relocs,at);assert kind==1 and blob[offset]==0xe8;assert target in symbols;calls.append(dict(offset=offset,offset_hex=hex(offset),kind=kind,target=hex(target),symbols=symbols[target]))
 assert len(calls)==7
 sites=[dict(index=i,**s,target_hex=hex(s['target_addr']),target_symbols=symbols[s['target_addr']]) for i,s in enumerate(p['plan']['lookup_sites'])];assert all(s['target_symbols'] for s in sites)
 review['records'].append(dict(cache_key=p['cache_key'],blob_bytes=p['blob_bytes'],blob_sha256=p['blob_sha256'],const_values=p['plan']['const_values'],lookup_sites=sites,actual_sideband_calls=calls,map_literal_patch_sites=p['map_patches'],task_inline_blocks=[dict(start='0x16e',end='0x181'),dict(start='0x296',end='0x2a9')],tail_call_block=dict(start='0x479',end='0x4d2',index=2,target_bpf_func_offset=72,target_entry_offset=12),scope='Canonical blob plus target call relocs/plan; final bound map pointers and long-run installed bytes are not inferred from0 placeholders or length.'))
assert review['records'][0]['blob_sha256']==review['records'][1]['blob_sha256'];assert review['records'][0]['actual_sideband_calls']==review['records'][1]['actual_sideband_calls']
(OUT/'current-review.json').write_text(json.dumps(review,indent=2)+'\n');print(json.dumps(dict(inspection=r['pid'],records=len(review['records']),calls=review['records'][0]['actual_sideband_calls']),indent=2))
