"""Reproduce host-name lookup on the real stock-accepted ARM lowered IR."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile
import types
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog'))
import trusted_compile as current
raw=Path('/workspaces/kprog-raw/perf/arm64-checked-control-20261127/20261127T001949Z')
with tarfile.open(raw/'xdp/service.tar.gz') as outer:
 member=next(m for m in outer.getmembers() if m.name.endswith('.failure.tar.gz'))
 with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as inner:
  member=next(m for m in inner.getmembers() if m.name.endswith('/checked-simulator.native.bc'))
  payload=inner.extractfile(member).read()
fixture=raw/'host-name-lookup.native.bc';fixture.write_bytes(payload)
command=['llvm-nm-18','-u','-j',str(fixture)]
old=types.ModuleType('old_broker');old.__file__=str(ROOT/'kprog/trusted_compile.py');sys.modules[old.__name__]=old
source=subprocess.check_output(['git','show','3599f1bfa:kprog/trusted_compile.py'],cwd=ROOT,text=True)
exec(compile(source,old.__file__,'exec'),old.__dict__)
try:before=old.execute_command(dict(command=command),raw)
except Exception as error:before=dict(exception=repr(error))
after=current.execute_command(dict(command=command),raw)
absolute=current.execute_command(dict(command=['/usr/bin/llvm-nm-18',*command[1:]]),raw)
try:missing=current.execute_command(dict(command=['kprog-deliberately-absent-tool']),raw)
except Exception as error:missing=dict(exception=repr(error))
record=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),command=command,before=before,after=after,absolute=absolute,missing=missing)
(HERE/'broker-lookup-result.json').write_text(json.dumps(record,indent=2)+'\n')
assert 'FileNotFoundError' in before['exception']
assert after['returncode']==absolute['returncode']==0
assert after['stdout']==absolute['stdout'] and after['stderr']==absolute['stderr']
assert 'FileNotFoundError' in missing['exception']
print('Old name lookup fails; current name/absolute real LLVM invocation agree; missing tool still fails')
