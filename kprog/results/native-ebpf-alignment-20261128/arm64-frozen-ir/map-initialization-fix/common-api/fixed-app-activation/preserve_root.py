from pathlib import Path
import fcntl,hashlib,json,os,tarfile,subprocess
root=Path.cwd();base=root/'.cache/qemu-arm64-root';lane=Path('/workspaces/.agent-state/kprog-lanes/perf');out=root/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/map-initialization-fix/common-api/fixed-app-activation';out.mkdir(exist_ok=True)
with (lane.parent/'locks/image').open('a') as lock:
 fcntl.flock(lock,fcntl.LOCK_SH|fcntl.LOCK_NB)
 for p in Path('/proc').iterdir():
  if p.name.isdigit():
   try:exe=(p/'exe').readlink()
   except OSError:continue
   assert 'qemu-system-aarch64' not in exe.name,p.name
 assert base.resolve()==root/'.cache/qemu-arm64-root' and not base.is_symlink()
 keep={};host={};symlinks=[];checked=[]
 def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
 for rel in ['root','home','tmp','var/tmp','run','mnt','media','srv','opt','workspaces','perf-observe']:
  checked.append(rel)
  for d,ds,fs in os.walk(base/rel,followlinks=False):
   for n in ds+fs:
    p=Path(d)/n
    if p.is_symlink():symlinks.append(dict(path=str(p.relative_to(base)),target=str(p.readlink())))
   for n in fs:
    p=Path(d)/n
    if p.is_symlink() or not p.is_file():continue
    key=str(p.relative_to(base));row=dict(bytes=p.stat().st_size,sha256=sha(p));hp=Path('/'+key)
    if rel=='workspaces' and hp.is_file() and hp.stat().st_size==row['bytes'] and sha(hp)==row['sha256']:host[key]=row
    else:keep[key]=row
 for p in base.iterdir():
  if p.is_file() and not p.is_symlink() and p.name!='.dockerenv':keep[p.name]=dict(bytes=p.stat().st_size,sha256=sha(p))
 archive=out/'root-data-before.tar.gz';assert not archive.exists()
 with tarfile.open(archive,'w:gz') as t:
  for n in sorted(keep):t.add(base/n,arcname=n,recursive=False)
 with tarfile.open(archive,'r:gz') as t:got={m.name:dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest()) for m in t.getmembers() if m.isfile()}
 assert got==keep
 r=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),canonical_root=str(base),checked_locations=checked,archived_files=keep,host_matching_files=host,symlinks_not_followed=symlinks,archive=dict(path=str(archive.relative_to(root)),bytes=archive.stat().st_size,sha256=sha(archive)),scope='All regular files in listed user/runtime locations plus root-level controls preserved; workspaces files matching existing host paths retained there. Canonical OS/tool/module tree is rebuildable from current image. Current raw051309 and prior archives remain retained.')
 (out/'root-preflight.json').write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps(dict(archived_files=len(keep),raw_bytes=sum(x['bytes'] for x in keep.values()),host_matching_files=len(host),archive=r['archive'])))
with (lane.parent/'locks/image').open('a') as lock:
 try:fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);availability='imageEX available'
 except BlockingIOError:availability='imageEX currently held shared by active owner; activation remains prepared'
 print(availability);(out/'resource-status.txt').write_text(subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()+' '+availability+'\n')