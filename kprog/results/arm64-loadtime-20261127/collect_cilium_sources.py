"""Archive a completed source comparison and verify every captured source file."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
pointer=json.loads((LANE/'cilium-source-comparison.json').read_text());OUT=Path(pointer['result']);RAW=Path(pointer['raw']);comparison=json.loads((OUT/'comparison.json').read_text());assert comparison['controller_status']==0 and not Path('/proc/'+str(comparison['pid'])).exists()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
with tarfile.open(RAW/'analysis-sources.tar','w') as t:
 for p in [HERE/'compare_cilium_sources.py',Path(__file__)]:t.add(p,arcname=str(p.relative_to(ROOT)))
files={str(p.relative_to(RAW)):dict(bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in sorted(RAW.rglob('*')) if p.is_file()}
with (OUT/'archive.log').open('wb') as log:
 a=subprocess.Popen(['tar','-C',str(RAW.parent),'-cf','-',RAW.name],stdout=subprocess.PIPE,stderr=log)
 b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close()
 c=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[a.wait(),b.wait(),c.wait()];assert codes==[0,0,0]
parts=sorted(OUT.glob('evidence.tar.zst.part-*'));a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();found={}
with tarfile.open(fileobj=b.stdout,mode='r|') as t:
 for m in t:
  path=Path(m.name);assert path.parts[0]==RAW.name
  if m.isdir():continue
  assert m.isfile();data=t.extractfile(m).read();found[str(Path(*path.parts[1:]))]=dict(bytes=len(data),sha256=hashlib.sha256(data).hexdigest())
b.stdout.close();assert a.wait()==b.wait()==0;assert files==found
record=dict(pid=os.getpid(),raw=str(RAW),controller_status=0,ended_utc=now(),summary=comparison['summary'],archive_returncodes=codes,verified_files=len(found),archive_files=files,parts=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in parts])
(OUT/'controller.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(result=str(OUT),files=len(found),parts=record['parts'])),flush=True)
