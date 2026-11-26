"""Retain installed and temporary tool evidence before an in-place refresh."""
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
BASE=Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
paths=[BASE/'compile-sim-ir',BASE/'context-lower',BASE/'context-lower.prev-before-contextfold',
       Path('/tmp/cc_compile-sim-ir'),Path('/tmp/cc_context-lower')]
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),files=[],commands=[])
with tarfile.open(HERE/'tools-before.tar.gz','w:gz') as archive:
 for path in paths:
  member=('tmp/' if str(path).startswith('/tmp/') else 'base/')+path.name
  stat=path.stat()
  record['files'].append(dict(path=str(path),member=member,bytes=stat.st_size,mtime_ns=stat.st_mtime_ns))
  archive.add(path,arcname=member)
with tarfile.open(HERE/'tools-before.tar.gz') as archive:
 for row in record['files']:
  if archive.extractfile(row['member']).read()!=Path(row['path']).read_bytes():raise AssertionError(row['path'])
for path in [BASE/'compile-sim-ir',BASE/'context-lower',Path('/tmp/cc_compile-sim-ir')]:
 command=[str(path),'--help']
 r=subprocess.run(command,text=True,capture_output=True)
 record['commands'].append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 r.check_returncode()
record['context_copies_equal']=(BASE/'context-lower').read_bytes()==Path('/tmp/cc_context-lower').read_bytes()
record['scope']='Compiler capabilities and retained build products; no app, kernel or timing result.'
(HERE/'tools-before.json').write_text(json.dumps(record,indent=2)+'\n')
print('archived',len(record['files']),'context equal',record['context_copies_equal'])
