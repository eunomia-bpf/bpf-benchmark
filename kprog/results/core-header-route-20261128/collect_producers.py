"""Archive the completed producer attempt before replacing its build metadata."""
from pathlib import Path
import hashlib,json,subprocess,tarfile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
def seal(p):
 b=p.read_bytes();return dict(path=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest())
controller=OUT/'producer-regeneration-controller.json'
r=json.loads(controller.read_text());assert r['status']=='complete' and r['pid']==1584215
files=[controller,OUT/'producer-regeneration-job.log']
review=[]
for c in r['architectures']:
 for stream in ['stdout','stderr']:
  x=c['build'][stream];p=Path(x['path']);assert seal(p)==x;files.append(p)
 for x in c['after_objects'].values():
  assert seal(Path(x['path']))=={k:x[k] for k in ['path','bytes','sha256']}
 for x in c['tables']:
  p=Path(x['path']);assert seal(p)=={k:x[k] for k in ['path','bytes','sha256']}
  files.extend([p,Path(str(p)[:-len('.json')]+'.h')])
 native=Path(c['native'])
 files.extend(p for p in native.rglob('*') if p.is_file() and any(q.startswith('core-answers-') for q in p.parts))
 review.append(dict(arch=c['arch'],returncode=c['build']['returncode'],before_objects=len(c['before_objects']),after_objects=len(c['after_objects']),tables=len(c['tables']),queries=sum(x.get('queries',0) for x in c['tables']),zero_query_executable_comparisons=c['zero_query_executable_comparisons'],kernel_unchanged=c['kernel_unchanged']))
archive=OUT/'producer-failed-records.tar.zst';assert not archive.exists()
members=[dict(name=str(p.relative_to(ROOT)),**seal(p)) for p in sorted(set(files))]
with archive.open('wb') as f:
 z=subprocess.Popen(['zstd','-q','-c'],stdin=subprocess.PIPE,stdout=f)
 with tarfile.open(fileobj=z.stdin,mode='w|') as tar:
  for x in members:tar.add(x['path'],arcname=x['name'],recursive=False)
 z.stdin.close();assert z.wait()==0
by={x['name']:x for x in members};seen=set()
z=subprocess.Popen(['zstd','-q','-dc',str(archive)],stdout=subprocess.PIPE)
with tarfile.open(fileobj=z.stdout,mode='r|') as tar:
 for m in tar:
  assert m.isfile() and m.name in by and m.name not in seen
  b=tar.extractfile(m).read();x=by[m.name]
  assert len(b)==x['bytes'] and hashlib.sha256(b).hexdigest()==x['sha256'];seen.add(m.name)
assert z.wait()==0 and seen==set(by)
for x in members:assert seal(Path(x['path']))=={k:x[k] for k in ['path','bytes','sha256']}
(OUT/'producer-failed-archive.json').write_text(json.dumps(dict(archive=seal(archive),members=members,every_member_and_original_verified=True),indent=2)+'\n')
(OUT/'producer-failed-review.json').write_text(json.dumps(dict(controller_pid=r['pid'],ended_utc=r['ended_utc'],architectures=review,findings=['Tracee reused intermediate query text with different concrete types and deltas (88 vs 280 on x86).','Tetragon preserve_access_index wraps a scalar assignment, not just pointer addresses.'],image_unchanged=True,all_architectures_build=False),indent=2)+'\n')
print(json.dumps(dict(archive=seal(archive),members=len(members),architectures=[{k:v for k,v in x.items() if k!='zero_query_executable_comparisons'} for x in review]),indent=2))
