"""Retain ARM loader build products before refreshing/consolidating them."""
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
paths=[ROOT/'kprog/libnativeloader/build-arm64',ROOT/'runner/build-arm64-llvmbpf/native_loader']
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),members=[])
with tarfile.open(HERE/'loader-before.tar.gz','w:gz') as archive:
 for index,base in enumerate(paths):
  for p in sorted(base.rglob('*')):
   if p.is_file():
    member=str(Path(str(index))/p.relative_to(base));stat=p.stat()
    archive.add(p,arcname=member,recursive=False)
    record['members'].append(dict(path=str(p),member=member,bytes=stat.st_size,mtime_ns=stat.st_mtime_ns))
with tarfile.open(HERE/'loader-before.tar.gz') as archive:
 for item in record['members']:
  if archive.extractfile(item['member']).read()!=Path(item['path']).read_bytes():raise AssertionError(item['path'])
record['scope']='Current ARM loader target and obsolete duplicate captured before in-place build; no kernel/image or test result.'
(HERE/'loader-before.json').write_text(json.dumps(record,indent=2)+'\n')
print('retained',len(record['members']),'build files')
