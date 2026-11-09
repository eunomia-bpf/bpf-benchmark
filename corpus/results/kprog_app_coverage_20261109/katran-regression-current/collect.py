from pathlib import Path
import sys,json,tarfile,io,hashlib
D=Path('/var/tmp/kprog-tmp/C');R=Path('/workspaces/repository');key=sys.argv[1];A=D/key
s=json.loads((A/'summary.json').read_text());rows=[]
with tarfile.open(A/s['archive'])as t:
 names=set(t.getnames())
 ledger=t.extractfile('corpus/requests/requests.jsonl').read().splitlines()if 'corpus/requests/requests.jsonl'in names else []
 for line in ledger:
  item=json.loads(line);name=Path(item.get('artifact_archive',item.get('failure_archive'))).name
  with tarfile.open(fileobj=io.BytesIO(t.extractfile('corpus/requests/'+name).read()))as q:
   files=set(q.getnames());load=q.extractfile('request/load.stderr').read().decode(errors='replace')if 'request/load.stderr'in files else ''
   tails=[l for l in load.splitlines()if len(l)<300 and any(x in l.lower()for x in ['invalid','processed ','misaligned','unbounded','math between','type=','stack','expected'])]
   rows.append(dict(request_id=item['request_id'],status=item['status'],entry=q.extractfile('request/kernel.entry').read().decode().strip(),native_sha256=item['native_sha256'],native_sha256_matches=hashlib.sha256(q.extractfile('request/kernel.native.o').read()).hexdigest()==item['native_sha256'],generated='request/generated/trusted_x86.bpf.c'in files,compiled='request/generated/trusted_x86.bpf.o'in files,error=item.get('error'),verifier_excerpt=tails[-12:]))
 result=dict(application=s['apps'],native_requests=len(rows),generated=sum(r['generated']for r in rows),compiled=sum(r['compiled']for r in rows),installed=sum(r['status']==0 for r in rows),failed=sum(r['status']!=0 for r in rows),programs=rows,summary=s)
 outputs=[]
 for m in s.get('corpus_metadata',[]):
  root=A/'corpus-results'/Path(m['path']).parent.name
  for appname in s['apps'].split(','):
   appfile=root/'details/apps'/(appname.replace('/','__')+'.json')
   if appfile.exists():outputs.append(dict(metadata=m,application=appname,app=json.loads(appfile.read_text())))
 result['results']=outputs
O=D/'collected'/key;O.mkdir(parents=True,exist_ok=True)
(O/'coverage.json').write_text(json.dumps(result,indent=2)+'\n')
with tarfile.open(O/'service.tar.gz','x:gz')as t:t.add(A/s['archive'],arcname=s['archive'])
with tarfile.open(O/'result.tar.gz','x:gz')as t:
 for m in s.get('corpus_metadata',[]):t.add(A/'corpus-results'/Path(m['path']).parent.name,arcname=Path(m['path']).parent.name)
print(json.dumps({k:v for k,v in result.items()if k not in ['programs','summary','results']},indent=2))
for r in rows:print(r['entry'],r['status'],r['verifier_excerpt'][-2:])
