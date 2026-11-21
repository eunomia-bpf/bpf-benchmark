"""Retire S2 rebuildable outputs after the published raw archive readback."""
from pathlib import Path
import hashlib,json,shutil,subprocess
from datetime import datetime,timezone
R=Path('/workspaces/repository');D=Path(__file__).resolve().parent
S=Path('/var/tmp/kprog-tmp/S2/review-20261121')
assert S.resolve()==S and not S.is_symlink()
receipt=json.loads((S/'final-publication.json').read_text())
subprocess.run(['git','merge-base','--is-ancestor',receipt['commit'],'origin/master'],cwd=R,check=True)
manifest=json.loads((D/'manifest.json').read_text())
stored=subprocess.check_output(['git','show',receipt['commit']+':kprog/results/arm64-recovery-review-20261121/terminal-raw.tar.gz'],cwd=R)
assert hashlib.sha256(stored).hexdigest()==manifest['archive_sha256']
for f in ['safety-driver.exit','hosts-current.exit','micro.exit','guest-driver.exit','replay-publication.json']:
    assert (S/f).exists(),f
removed=[]
for name in ['cargo','loader','module','fixture-module','hosts','micro-objects','negative-objects','sites']:
    p=S/name;assert p.parent.resolve()==S
    if p.exists():
        assert not p.is_symlink()
        files=[q for q in p.rglob('*') if q.is_file()]
        removed.append(dict(path=str(p),files=len(files),bytes=sum(q.stat().st_size for q in files)))
        shutil.rmtree(p)
for p in list(S.iterdir()):
    if p.is_file() and (p.name in {'probe','safety-probe','read-followup','read-recovery','vmlinux.h'} or '.index' in p.name):
        removed.append(dict(path=str(p),files=1,bytes=p.stat().st_size));p.unlink()
dest=Path('/workspaces/kprog-raw/S2/review-20261121');assert not dest.exists()
dest.parent.mkdir(parents=True,exist_ok=True)
files={}
for p in S.rglob('*'):
    if p.is_file() and p.name!='cleanup-driver.log':
        files[str(p.relative_to(S))]=hashlib.sha256(p.read_bytes()).hexdigest()
shutil.move(str(S),str(dest))
for rel,h in files.items():assert hashlib.sha256((dest/rel).read_bytes()).hexdigest()==h
record=dict(utc=datetime.now(timezone.utc).isoformat(),published_result_commit=receipt['commit'],archive_sha256=manifest['archive_sha256'],published_archive_readback=True,removed_rebuildable_outputs=removed,raw_directory=str(dest),raw_file_readbacks=len(files),raw_readback_digest=hashlib.sha256(json.dumps(files,sort_keys=True).encode()).hexdigest(),raw_readbacks_equal=True,retained_active_log='cleanup-driver.log',shared_source_index_cache_kernel_root_retained=True)
(D/'cleanup.json').write_text(json.dumps(record,indent=2)+'\n')
line='\n- S2 '+record['utc']+': Published ARM recovery raw archive '+receipt['commit']+' with all404 member hashes reread. Removed only S2 rebuildable cargo/loader/modules/host and micro objects/site binaries, private indexes, generated vmlinux header and probe executables under /var/tmp/kprog-tmp/S2/review-20261121 ('+str(sum(x['bytes'] for x in removed))+' bytes). All remaining raw inputs/results/logs moved to '+str(dest)+'; '+str(len(files))+' file SHA256 readbacks equal. Full path list: kprog/results/arm64-recovery-review-20261121/cleanup.json. Shared source/index/cache/kernel/root and peer outputs retained.\n'
with (R/'kprog/docs/cleanup-log.md').open('a') as f:f.write(line)
(dest/'cleanup-log-line.txt').write_text(line)
print(json.dumps(record,indent=2))
