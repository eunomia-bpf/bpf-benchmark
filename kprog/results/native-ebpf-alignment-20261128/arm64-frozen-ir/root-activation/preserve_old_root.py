from pathlib import Path
import os,hashlib,json,tarfile,subprocess
root=Path.cwd();base=root/'.cache/qemu-arm64-root';out=root/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/root-activation';out.mkdir(exist_ok=True)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
prior=json.loads((out.parent/'runtime-refresh/old-root-results-inventory.json').read_text());keep={};checked=[];symlinks=[]
for rel in ['root','home','tmp','var/tmp','run','mnt','media','srv','opt','workspaces']:
 p=base/rel;row=dict(path=rel,regular_files=0,bytes=0,host_matches=0,previously_preserved=0,newly_preserved=0)
 for d,ds,fs in os.walk(p,followlinks=False):
  for n in ds+fs:
   q=Path(d)/n
   if q.is_symlink():symlinks.append(dict(path=str(q.relative_to(base)),target=str(q.readlink())))
  for n in fs:
   q=Path(d)/n
   if q.is_symlink() or not q.is_file():continue
   assert q.resolve().is_relative_to(base.resolve());key=str(q.relative_to(base));h=sha(q);size=q.stat().st_size;row['regular_files']+=1;row['bytes']+=size
   if key in prior['files']:
    assert prior['files'][key]['sha256']==h and prior['files'][key]['bytes']==size;row['previously_preserved']+=1;continue
   host=Path('/'+key)
   if rel=='workspaces' and host.is_file() and sha(host)==h:row['host_matches']+=1;continue
   keep[key]=dict(bytes=size,sha256=h);row['newly_preserved']+=1
 checked.append(row)
for q in base.iterdir():
 if q.is_file() and not q.is_symlink() and q.name not in ['.dockerenv'] and q.name not in prior['files']:keep[q.name]=dict(bytes=q.stat().st_size,sha256=sha(q))
a=out/'old-root-additional-data.tar.gz'
with tarfile.open(a,'w:gz') as t:
 for key in keep:t.add(base/key,arcname=key,recursive=False)
with tarfile.open(a,'r:gz') as t:got={m.name:dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest()) for m in t.getmembers() if m.isfile()}
assert keep==got
processes=[]
for p in Path('/proc').iterdir():
 if p.name.isdigit():
  try:
   exe=(p/'exe').readlink();cmd=(p/'cmdline').read_bytes().replace(b'\0',b' ').decode(errors='replace')
   if 'qemu-system-aarch64' in exe.name:processes.append(dict(pid=int(p.name),cmd=cmd))
  except (OSError,PermissionError):pass
assert not processes
r=dict(time_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),canonical_root=str(base.resolve()),temporary_root=str(root/'.cache/qemu-arm64-root.tmp'),root_is_symlink=base.is_symlink(),checked_user_runtime_locations=checked,symlinks_not_followed=symlinks,previous_preservation='runtime-refresh/old-root-results-inventory.json',additional_files=keep,additional_archive=dict(path=str(a.relative_to(root)),bytes=a.stat().st_size,sha256=sha(a)),all_archive_members_sha_size_fileset_verified=True,active_arm_guests=processes,scope='Non-OS user/runtime/workspace locations and top-level diagnostics inspected; matching host framework files and previously verified result/control archive are preserved in place outside root; all other regular files archived. OS/tool/module rebuildable files replaced from existing canonical image. No guest or root replacement yet.')
(out/'preflight.json').write_text(json.dumps(r,indent=2)+'\n')
(out/'README.md').write_text('''# Canonical ARM root activation

Refresh only the existing .cache/qemu-arm64-root from the already-validated b278 ARM image/tar, using the frozen arm64-qemu-root Makefile rule. No new base/tag/kernel/framework or guest is created by this step. The image prerequisite is marked old so successful image/component/P/kernel builds are not repeated. Root replacement runs with timingSH/imageEX and CPUs16,18; no other ARM guest may use it.

The previous runtime-refresh result already preserves all36 old corpus result files and three root controls. preflight.json inventories the remaining non-OS user/runtime/workspace locations and symlinks without following them. Matching host files remain outside this disposable exported image root; additional regular files and top-level diagnostics are preserved in a byte/SHA/size/fileset-verified archive before the existing rule replaces it. Protected kernel/native stage and x86 image hashes must stay unchanged; all four activated ARM runtime payload hashes must match the already verified image. This is root activation only, not kernel/runtime/work acceptance. The following step is the affected ARM OTel functional check with actual installed-code and unwind-work observations.
''')
print(json.dumps(dict(checked=checked,extra_files=len(keep),extra_bytes=sum(v['bytes'] for v in keep.values()),archive=r['additional_archive'],active_arm_guests=processes)))
