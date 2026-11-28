from pathlib import Path
import hashlib,json,subprocess,tarfile
OUT=Path(__file__).resolve().parent;c=json.loads((OUT/'controller.json').read_text());RAW=Path(c['raw']);expected=json.loads((OUT/'raw-file-manifest.json').read_text());parts=sorted(OUT.glob('evidence.tar.zst.part-*'));assert parts
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
a=subprocess.Popen(['cat',*[str(p) for p in parts]],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();got={}
with tarfile.open(fileobj=b.stdout,mode='r|') as t:
 for m in t:
  if not m.isfile():continue
  name=str(Path(m.name).relative_to(RAW.name));h=hashlib.sha256();f=t.extractfile(m)
  for data in iter(lambda:f.read(1048576),b''):h.update(data)
  got[name]=dict(bytes=m.size,sha256=h.hexdigest())
b.stdout.close();codes=[a.wait(),b.wait()];assert codes==[0,0] and got==expected
actual={str(p.relative_to(RAW)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in RAW.rglob('*') if p.is_file() and not p.is_symlink()};assert actual==expected
r=dict(archive_parts=[dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p)) for p in parts],files=len(expected),logical_bytes=sum(x['bytes'] for x in expected.values()),archive_and_RAW_all_file_SHA_size_fileset_verified=True,raw_retained=True,root_observer_copy_retained=True,no_guest_rerun=True)
(OUT/'archive-verification.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r))
