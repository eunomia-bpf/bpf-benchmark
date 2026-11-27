"""Remove only raw duplicates verified against unchanged committed archives."""
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tarfile

ROOT=Path('/workspaces/repository')
HERE=Path(__file__).resolve().parent
BASE=Path('/workspaces/kprog-raw/perf')
PROFILE_BASE=BASE/'arm64-loadtime-20261127'
REV=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
TOKEN=subprocess.check_output(['date','-u','+%Y%m%dT%H%M%SZ'],text=True).strip()
OUT=HERE/('raw-dedup-'+TOKEN+'.json')
record=dict(utc=now(),git_revision=REV,authority='Coordinator 2026-11-27T12:19Z: remove verified raw duplicates after SHA256 match against committed Git archives; preserve archive parts.',actions=[],free_before_bytes=shutil.disk_usage(BASE).free)
def save():OUT.write_text(json.dumps(record,indent=2)+'\n')
def digest_file(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for block in iter(lambda:f.read(1024*1024),b''):h.update(block)
    return h.hexdigest()
def digest_stream(stream):
    h=hashlib.sha256()
    for block in iter(lambda:stream.read(1024*1024),b''):h.update(block)
    return h.hexdigest()
def committed(parts):
    if not parts:raise ValueError('No archive parts')
    rows=[]
    for p in parts:
        rel=str(p.relative_to(ROOT));entry=subprocess.check_output(['git','ls-tree',REV,'--',rel],cwd=ROOT,text=True).strip()
        if not entry:raise ValueError('Archive is not committed: '+rel)
        oid=entry.split()[2];actual=subprocess.check_output(['git','hash-object','--',str(p)],cwd=ROOT,text=True).strip()
        if oid!=actual:raise ValueError('Archive differs from committed blob: '+rel)
        rows.append(dict(path=rel,git_blob=oid,bytes=p.stat().st_size,sha256=digest_file(p)))
    return rows
def safe_path(path):
    resolved=path.resolve()
    if not resolved.is_relative_to(BASE) or resolved==BASE or path.is_symlink():raise ValueError('Raw target outside intended root or symlink')
    return resolved
save()
copies=[(BASE/'20261113-tetragon-manifest-native/full-initial.tar.gz',sorted((ROOT/'kprog/results/perf_20261113').glob('tetragon-manifest-native-initial.tar.gz.part*'))),
        (BASE/'20261113-tetragon-public-data/full-compiler.tar.gz',sorted((ROOT/'kprog/results/perf_20261113').glob('tetragon-public-data.tar.gz.part*'))),
        (BASE/'20261114-tetragon-native-frame/full-host-evidence.tar.gz',sorted((ROOT/'kprog/results/perf_20261113').glob('tetragon-native-frame-host.tar.gz.part*'))),
        (BASE/'20261113-core/core-host-full.tar.gz',sorted((ROOT/'kprog/results/perf_20261113').glob('core-host.tar.gz.part*')))]
for p in HERE.glob('early-promote-*/controller.json'):
    r=json.loads(p.read_text());raw=Path(r['raw']);copies.append((raw/'canonical-stages.tar.gz',sorted(p.parent.glob('canonical-stages.tar.gz.part-*'))))
for path,parts in copies:
    row=dict(raw=str(path),kind='archive-file-copy')
    try:
        path=safe_path(path)
        if not path.exists():row['status']='already-absent'
        else:
            row['archives']=committed(parts);raw_sha=digest_file(path);h=hashlib.sha256()
            for p in parts:
                with p.open('rb') as f:
                    for block in iter(lambda:f.read(1024*1024),b''):h.update(block)
            row.update(raw_sha256=raw_sha,archive_stream_sha256=h.hexdigest(),allocated_bytes=path.stat().st_blocks*512)
            if raw_sha!=h.hexdigest():raise ValueError('Raw copy does not match committed archive bytes')
            row['status']='verified';record['actions'].append(row);save();path.unlink();row['status']='removed'
    except Exception as error:row.update(status='retained',reason=str(error))
    if row not in record['actions']:record['actions'].append(row)
    save()
for controller in sorted(HERE.glob('*/controller.json')):
    r=json.loads(controller.read_text());raw=Path(r.get('raw','/'))
    if raw.parent!=PROFILE_BASE or not re.fullmatch(r'\d{8}T\d{6}Z',raw.name) or r.get('controller_status') is None:continue
    row=dict(raw=str(raw),kind='completed-profile-directory',controller=str(controller.relative_to(ROOT)))
    try:
        raw=safe_path(raw)
        if not raw.exists():row['status']='already-absent'
        else:
            parts=sorted(controller.parent.glob('evidence.tar.zst.part-*'))
            compression='zstd' if parts else 'gzip'
            if not parts:parts=[controller.parent/'evidence.tar.gz']
            row['archives']=committed(parts)
            files={}
            for directory,dirs,names in os.walk(raw,followlinks=False):
                for name in [*dirs,*names]:
                    p=Path(directory)/name
                    if p.is_symlink():raise ValueError('Raw symlink requires separate link-target audit')
                for name in names:
                    p=Path(directory)/name;files[str(p.relative_to(raw))]=dict(bytes=p.stat().st_size,sha256=digest_file(p),allocated_bytes=p.stat().st_blocks*512)
            a=subprocess.Popen(['cat',*[str(p) for p in parts]],stdout=subprocess.PIPE)
            if compression=='zstd':
                b=subprocess.Popen(['zstd','-d','-c'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();stream=b.stdout;mode='r|'
            else:b=None;stream=a.stdout;mode='r|gz'
            archived={}
            with tarfile.open(fileobj=stream,mode=mode) as t:
                for member in t:
                    path=Path(member.name)
                    if path.is_absolute() or '..' in path.parts or not path.parts or path.parts[0]!=raw.name:raise ValueError('Archive path does not bind this raw root')
                    if member.isdir():continue
                    if not member.isfile():raise ValueError('Archive links/special files need separate audit')
                    rel=str(Path(*path.parts[1:]));archived[rel]=dict(bytes=member.size,sha256=digest_stream(t.extractfile(member)))
            for block in iter(lambda:stream.read(1024*1024),b''):pass
            if b is not None and b.wait()!=0:raise ValueError('Archive decompression failed')
            if a.wait()!=0:raise ValueError('Archive part stream failed')
            if set(files)!=set(archived):raise ValueError('File sets differ: raw-only='+str(sorted(set(files)-set(archived)))+' archive-only='+str(sorted(set(archived)-set(files))))
            if any(files[p]['bytes']!=archived[p]['bytes'] or files[p]['sha256']!=archived[p]['sha256'] for p in files):raise ValueError('A file SHA256 or size differs')
            row.update(files=files,allocated_bytes=sum(f['allocated_bytes'] for f in files.values()),status='verified')
            record['actions'].append(row);save();safe_path(raw);shutil.rmtree(raw);row['status']='removed'
    except Exception as error:row.update(status='retained',reason=str(error))
    if row not in record['actions']:record['actions'].append(row)
    save()
record.update(ended_utc=now(),free_after_bytes=shutil.disk_usage(BASE).free,removed_allocated_bytes=sum(r.get('allocated_bytes',0) for r in record['actions'] if r['status']=='removed'))
save();print(json.dumps(dict(receipt=str(OUT.relative_to(ROOT)),removed_allocated_bytes=record['removed_allocated_bytes'],free_before_bytes=record['free_before_bytes'],free_after_bytes=record['free_after_bytes'],actions=[dict(raw=r['raw'],status=r['status'],reason=r.get('reason')) for r in record['actions']]),indent=2))
