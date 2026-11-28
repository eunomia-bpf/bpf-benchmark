"""Review the completed same-input CFG correction and archive its closed raw evidence."""
from pathlib import Path
import hashlib,json,os,re,subprocess,tarfile
OUT=Path(__file__).resolve().parent;ROOT=Path('/workspaces/repository');sha=lambda b:hashlib.sha256(b).hexdigest()
def seal(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=sha(b))
j=json.loads((OUT/'cfg-join-controller.json').read_text());assert j['pid']==1555792 and j['status']=='complete' and j['phase']=='passed'
for x in j['sources']+[j['after_linker']]+[v['log'] for v in j['commands']]:
 assert seal(Path(x['path']))==x
assert all(x['returncode']==0 for x in j['commands'])
assert '16 passed; 0 failed' in (OUT/'cfg-join/cargo-test.log').read_text()
def decode(p):
 fd=os.memfd_create('cfg-join-review')
 try:
  os.write(fd,p.read_bytes());os.lseek(fd,0,os.SEEK_SET)
  text=subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64','--no-show-raw-insn',f'/proc/self/fd/{fd}'],pass_fds=(fd,),text=True)
 finally:os.close(fd)
 rows=[]
 for line in text.splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$',line)
  if m:rows.append(dict(offset=int(m[1],16),op=m[2],args=m[3] or ''))
 return rows
reviews=[]
before=[x for x in j['replays'] if x['label']=='before'];after=[x for x in j['replays'] if x['label']=='after']
for old,new in zip(before,after):
 assert old['key']==new['key'] and old['proof']==new['proof'] and old['plan']==new['plan']
 for x in [old,new]:
  for k in ['proof','plan','blob']:assert seal(Path(x[k]['path']))==x[k]
 a=Path(old['blob']['path']).read_bytes();b=Path(new['blob']['path']).read_bytes()
 row=dict(key=old['key'],entry=old['entry'],before_bytes=len(a),after_bytes=len(b),generic_calls=[old['generic_lookup_calls'],new['generic_lookup_calls']],external_calls=[len(old['relocs']),len(new['relocs'])])
 if old['entry']=='generic_kprobe_process_filter':
  assert a==b;row['byte_identical']=True
 else:
  aa=decode(Path(old['blob']['path']));bb=decode(Path(new['blob']['path']))
  calls=[i for i,x in enumerate(bb) if x['op']=='call'];assert len(calls)==7
  removed=set()
  for number in [3,4]:
   i=calls[number];block=bb[i+1:i+4]
   assert [(x['op'],x['args']) for x in [block[0],block[2]]]==[('test','%rax,%rax'),('add','$0x38,%rax')]
   assert block[1]['op']=='je' and int(block[1]['args'],16)==bb[i+4]['offset']
   removed.update(range(i+1,i+4))
  keep=[x for i,x in enumerate(bb) if i not in removed];assert len(aa)==len(keep)
  ai={x['offset']:i for i,x in enumerate(aa)};bi={x['offset']:i for i,x in enumerate(keep)};ai[len(a)]=len(aa);bi[len(b)]=len(keep)
  for i,(x,y) in enumerate(zip(aa,keep)):
   assert x['op']==y['op'],(i,x,y)
   if x['op'].startswith('j') and re.fullmatch(r'0x[0-9a-f]+',x['args']):
    assert int(x['args'],16) in ai and int(y['args'],16) in bi
    assert ai[int(x['args'],16)]==bi[int(y['args'],16)],(i,x,y)
   elif x['op']!='call':assert x['args']==y['args'],(i,x,y)
  changed=[i for i,(x,y) in enumerate(zip(old['relocs'],new['relocs'])) if x['target']!=y['target']]
  assert changed==[3,4]
  plan=json.loads(Path(new['plan']['path']).read_text())
  inner=next(x for x in plan['lookup_maps'] if x['name']=='policy_filter_maps#inner')
  assert all(new['relocs'][i]['target']==inner['target_addr'] for i in changed)
  assert any(x['args']=='$0x2,%edx' and x['op']=='mov' for x in keep)
  assert any(x['op']=='jmp' and x['args']=='*%rcx' for x in keep)
  row.update(added_postprocess_instructions=6,other_instructions_and_branch_targets_unchanged=True,changed_call_indices=changed,all_seven_calls_preserved=True,tail_index2_and_transfer_preserved=True)
 reviews.append(row)
review=dict(pid=j['pid'],ended_utc=j['ended_utc'],source=j['sources'],linker=j['after_linker'],tests='16 passed; 0 failed',rows=reviews,scope='Offline real-input correctness review; no runtime image/guest/performance result. Historical May29 installed-byte and dynamic branch-hit gaps remain.')
(OUT/'cfg-join-review.json').write_text(json.dumps(review,indent=2)+'\n')
files=sorted(p for p in (OUT/'cfg-join').iterdir() if p.is_file())+[OUT/'cfg-join-controller.json',OUT/'cfg-join-job.log',OUT/'cfg-root-before.dis',OUT/'cfg-root-after.dis']
archive=OUT/'cfg-join-records.tar.zst';assert not archive.exists()
members=[dict(name=str(p.relative_to(OUT)),**seal(p)) for p in files]
with archive.open('wb') as f:
 z=subprocess.Popen(['zstd','-q','-c'],stdin=subprocess.PIPE,stdout=f)
 with tarfile.open(fileobj=z.stdin,mode='w|') as tar:
  for x in members:tar.add(x['path'],arcname=x['name'],recursive=False)
 z.stdin.close();assert z.wait()==0
z=subprocess.Popen(['zstd','-q','-dc',str(archive)],stdout=subprocess.PIPE);seen=set();by={x['name']:x for x in members}
with tarfile.open(fileobj=z.stdout,mode='r|') as tar:
 for m in tar:
  assert m.isfile() and m.name in by and m.name not in seen
  b=tar.extractfile(m).read();x=by[m.name];assert len(b)==x['bytes'] and sha(b)==x['sha256'];seen.add(m.name)
while z.stdout.read(1024*1024):pass
assert z.wait()==0 and seen==set(by)
for x in members:assert seal(Path(x['path']))=={k:x[k] for k in ['path','bytes','sha256']}
manifest=dict(archive=seal(archive),members=members,every_member_and_original_verified=True,controller_pid=j['pid'],scope='Only same completed1555792 validation raw outputs. Canonical host tool, original proofs/plans/captures and source excluded and preserved.')
(OUT/'cfg-join-archive.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps(dict(review=reviews,archive=manifest['archive'],members=len(members)),indent=2))
