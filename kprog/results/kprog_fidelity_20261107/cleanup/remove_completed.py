#!/usr/bin/env python3
"""Delete only F-owned completed artifacts after checking publication/readers."""
from pathlib import Path
import bisect,hashlib,json,os,shutil,subprocess
R=Path('/workspaces/repository');OUT=R/'kprog/results/kprog_fidelity_20261107/cleanup';S=Path('/workspaces/.agent-state/kprog-lanes/F')
plan=json.loads((OUT/'remove-plan.json').read_text());paths=json.loads((OUT/'publish-paths.json').read_text())
commit=(OUT/'published-commit.txt').read_text().strip()
subprocess.run(['git','merge-base','--is-ancestor',commit,'origin/master'],cwd=R,check=True)
for rel in paths:
 p=R/rel
 assert p.is_file(),rel
 want=subprocess.check_output(['git','rev-parse','HEAD:'+rel],cwd=R,text=True).strip()
 got=subprocess.check_output(['git','hash-object','--',rel],cwd=R,text=True).strip()
 assert got==want,rel
tracked=set(subprocess.check_output(['git','ls-tree','-r','--name-only','HEAD'],cwd=R,text=True).splitlines())
ordered_tracked=sorted(tracked)
files=[R/p for p in plan['files']];dirs=[R/p for p in plan['build_dirs']]+[S]
for p in files:
 assert p.is_relative_to(R/'kprog/results') and str(p.relative_to(R)) not in tracked
for p in dirs:
 if p==S:assert p.resolve()==S
 else:
  assert p.parent==R/'kprog/fidelity' and p.name.startswith('build') and not p.is_symlink()
  prefix=str(p.relative_to(R))+'/'
  pos=bisect.bisect_left(ordered_tracked,prefix)
  assert pos==len(ordered_tracked) or not ordered_tracked[pos].startswith(prefix)
roots=[str(p)+'/' for p in dirs];file_names={str(p) for p in files}
def matches(p):
 if p==str(S/'STOP'):return False
 if not p.startswith(('/workspaces/repository/kprog/','/workspaces/.agent-state/kprog-lanes/F')):return False
 return p in file_names or any(p==x[:-1] or p.startswith(x) for x in roots)
readers=[];errors=[]
for proc in Path('/proc').iterdir():
 if not proc.name.isdigit() or int(proc.name)==os.getpid():continue
 try:
  cwd=os.readlink(proc/'cwd')
  if matches(cwd):readers.append((proc.name,'cwd',cwd))
  args=(proc/'cmdline').read_bytes().replace(b'\0',b' ').decode(errors='replace')
  if any(x in args for x in roots) or any(x in args for x in file_names):readers.append((proc.name,'command',args[:1000]))
  for fd in (proc/'fd').iterdir():
   try:target=os.readlink(fd)
   except FileNotFoundError:continue
   if matches(target):readers.append((proc.name,'fd',target))
  for line in (proc/'maps').read_text().splitlines():
   parts=line.split(None,5)
   if len(parts)==6 and matches(parts[5]):readers.append((proc.name,'mapped',parts[5]))
 except (FileNotFoundError,ProcessLookupError):continue
 except PermissionError as e:errors.append(str(e))
assert not errors,errors
assert not readers,readers
allocated=0;count=0
for p in files:
 if p.exists():allocated+=p.lstat().st_blocks*512;count+=1
for p in dirs:
 for base,dnames,fnames in os.walk(p,followlinks=False):
  for name in fnames:
   q=Path(base)/name
   if q==S/'STOP':continue
   allocated+=q.lstat().st_blocks*512;count+=1
for p in files:
 if p.exists():p.unlink()
for p in dirs:
 if p==S:
  for child in p.iterdir():
   if child.name=='STOP':continue
   if child.is_dir() and not child.is_symlink():shutil.rmtree(child)
   else:child.unlink()
 elif p.exists():shutil.rmtree(p)
S.mkdir(parents=True,exist_ok=True)
(OUT/'deletion-audit.json').write_text(json.dumps(dict(published_commit=commit,deleted_entries=count,allocated_bytes=allocated,reader_scan='no matching command/cwd/fd/mapping; no permission errors',shared_caches='untouched',build_dirs=plan['build_dirs']),indent=2)+'\n')
print('Removed completed F data:',count,'entries',allocated,'allocated bytes; shared caches untouched')
