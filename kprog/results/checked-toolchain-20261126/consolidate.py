"""Replace old temporary tool copies by atomic aliases to the sole base."""
import json
import os
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
BASE=Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 aliases=[],removed=[],commands=[])
with tarfile.open(HERE/'tools-before.tar.gz') as archive:
 for member,path in [('tmp/cc_compile-sim-ir',Path('/tmp/cc_compile-sim-ir')),
                     ('tmp/cc_context-lower',Path('/tmp/cc_context-lower')),
                     ('base/context-lower.prev-before-contextfold',BASE/'context-lower.prev-before-contextfold')]:
  if archive.extractfile(member).read()!=path.read_bytes():raise AssertionError('unarchived tool change: '+str(path))
record['archive_members_compared']=3
receipt=HERE/'consolidation.json'
def save():receipt.write_text(json.dumps(record,indent=2)+'\n')
save()
for path,target in [(Path('/tmp/cc_compile-sim-ir'),BASE/'compile-sim-ir'),
                    (Path('/tmp/cc_context-lower'),BASE/'context-lower')]:
 temporary=path.with_name(path.name+'.alias-new')
 temporary.symlink_to(target)
 os.replace(temporary,path)
 record['aliases'].append(dict(path=str(path),target=str(path.resolve())))
 save()
old=BASE/'context-lower.prev-before-contextfold'
old.unlink();record['removed'].append(str(old));save()
for path in [BASE/'compile-sim-ir',BASE/'context-lower',Path('/tmp/cc_compile-sim-ir')]:
 command=[str(path),'--help'];r=subprocess.run(command,text=True,capture_output=True)
 record['commands'].append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 save();r.check_returncode()
record['scope']='One-time base/tool alias cleanup after archive comparisons; no image/kernel/app or timing change.'
save();print(json.dumps(dict(aliases=record['aliases'],removed=record['removed']),indent=2))
