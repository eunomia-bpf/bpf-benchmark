#!/usr/bin/env python3
"""Remove only pushed unused PERF indexes and hash-identical archived raw copies."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,stat,struct,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');OUT=Path(__file__).resolve().parent
BASE=ROOT/'kprog/results/native-ebpf-alignment-20261128';J=None

def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return h.hexdigest()
def seal(p):
 s=p.stat();return dict(path=str(p),size=s.st_size,sha256=sha(p),allocated=s.st_blocks*512)
def event(kind,**values):
 J.write(json.dumps(dict(time=now(),event=kind,**values))+'\n');J.flush()
def save(c):
 q=OUT/'controller.tmp';q.write_text(json.dumps(c,indent=2)+'\n');q.replace(OUT/'controller.json')
def git(*args):return subprocess.check_output(['git',*args],cwd=ROOT)
def live_refs():
 refs=set();errors=[];pids=set()
 for d in Path('/proc').iterdir():
  if not d.name.isdigit():continue
  pids.add(int(d.name))
  try:
   if d.stat().st_uid!=os.getuid():continue
   env=(d/'environ').read_bytes()
   for v in env.split(b'\0'):
    if v.startswith(b'GIT_INDEX_FILE='):refs.add(os.fsdecode(v.split(b'=',1)[1]))
   for f in (d/'fd').iterdir():
    try:refs.add(os.readlink(f))
    except FileNotFoundError:pass
   for line in (d/'maps').read_text().splitlines():
    fields=line.split(None,5)
    if len(fields)==6 and fields[5].startswith('/'):refs.add(fields[5])
  except (FileNotFoundError,ProcessLookupError):pass
  except PermissionError:errors.append(int(d.name))
 return refs,pids,errors

def index_tree(path):
 data=path.read_bytes();assert hashlib.sha1(data[:-20]).digest()==data[-20:],'bad index checksum'
 magic,version,count=struct.unpack_from('>4sII',data);assert magic==b'DIRC' and version in (2,3,4)
 at=12;previous=b'';root={}
 for _ in range(count):
  start=at;mode=struct.unpack_from('>I',data,at+24)[0];oid=data[at+40:at+60];flags=struct.unpack_from('>H',data,at+60)[0];at+=62
  assert not flags&0x3000,'unmerged index';assert mode in (0o100644,0o100755,0o120000,0o160000),'sparse/unknown index mode'
  if flags&0x4000:assert version>=3;at+=2
  if version==4:
   n=data[at]&127;more=data[at]&128;at+=1
   while more:n=((n+1)<<7)+(data[at]&127);more=data[at]&128;at+=1
   assert n<=len(previous)
   end=data.index(0,at);name=previous[:len(previous)-n]+data[at:end];at=end+1;previous=name
  else:
   end=data.index(0,at);name=data[at:end];at=start+((end+1-start+7)//8)*8
  assert name and not name.startswith(b'/') and b'..' not in name.split(b'/')
  node=root;parts=name.split(b'/')
  for part in parts[:-1]:node=node.setdefault(part,{})
  assert parts[-1] not in node;node[parts[-1]]=(mode,oid)
 def tree(node):
  rows=[]
  for name,value in node.items():
   if isinstance(value,dict):mode,oid=0o40000,tree(value)
   else:mode,oid=value
   rows.append((name+(b'/' if mode==0o40000 else b''),format(mode,'o').encode()+b' '+name+b'\0'+oid))
  body=b''.join(row for _,row in sorted(rows));return hashlib.sha1(b'tree '+str(len(body)).encode()+b'\0'+body).digest()
 return tree(root).hex(),count

def remove(p,expected,category,c):
 s=p.lstat();assert stat.S_ISREG(s.st_mode) and not p.is_symlink()
 if s.st_nlink!=1:event('retained',path=str(p),reason='hardlinked',category=category);return
 assert s.st_size==expected['size'] and sha(p)==expected['sha256']
 event('verified-before-unlink',path=str(p),category=category,sha256=expected['sha256'],size=s.st_size,allocated=s.st_blocks*512)
 p.unlink();assert not p.exists()
 c[category+'_files']+=1;c[category+'_logical_bytes']+=s.st_size;c[category+'_allocated_bytes']+=s.st_blocks*512
 event('unlinked',path=str(p),category=category);save(c)

def main():
 global J
 assert not (OUT/'controller.json').exists(),'preserve previous cleanup, do not rerun blindly'
 J=(OUT/'journal.jsonl').open('x');c=dict(pid=os.getpid(),started=now(),status='running',latest_resume='COORDINATOR2026-11-28T14:39Z',index_files=0,index_logical_bytes=0,index_allocated_bytes=0,raw_files=0,raw_logical_bytes=0,raw_allocated_bytes=0);save(c)
 try:
  assert (LANE/'STOP').exists();assert git('branch','--show-current').strip()==b'master'
  c['recipe']=seal(Path(__file__));c['workspace_free_before']=os.statvfs(ROOT).f_bavail*os.statvfs(ROOT).f_frsize
  with (Path('/workspaces/.agent-state/kprog-lanes/locks/git')).open('w') as lock:
   fcntl.flock(lock,fcntl.LOCK_EX)
   remote=git('ls-remote','origin','refs/heads/master').split()[0].decode();log=git('log',remote,'--format=%T %H').decode().splitlines();trees={};pushed=set()
   for line in log:t,h=line.split();trees.setdefault(t,h);pushed.add(h)
   c['pushed_remote_master']=remote;shared=seal(ROOT/'.git/index');refs,pids,errors=live_refs();c['reader_scan_unreadable_same_uid']=errors
   for p in sorted(LANE.glob('*.index')):
    if p.is_symlink() or p.resolve().parent!=LANE:continue
    match=re.search(r'-(\d+)\.index$',p.name)
    if errors or str(p) in refs or Path(str(p)+'.lock').exists() or match and int(match[1]) in pids:
     event('retained',path=str(p),reason='active-reader/pid/lock or uncertain reader scan');continue
    before=seal(p)
    try:tree,count=index_tree(p)
    except Exception as e:event('retained',path=str(p),reason='index format/state not proven: '+str(e));continue
    if tree not in trees:event('retained',path=str(p),reason='snapshot not equal to pushed commit tree',tree=tree);continue
    assert seal(p)==before
    event('pushed-index-proof',path=str(p),tree=tree,commit=trees[tree],entries=count,remote=remote)
    remove(p,before,'index',c)
   assert seal(ROOT/'.git/index')==shared;c['shared_index_unchanged']=shared
  c['pushed_commits']=len(pushed);save(c)
  def published(path,commit,digest=None):
   assert commit in pushed,('archive commit not in pushed ancestry',commit)
   expected=hashlib.sha256(git('show',commit+':'+str(path.relative_to(ROOT)))).hexdigest()
   assert sha(path)==expected and (digest is None or expected==digest),path
   return expected
  def verify_stream(args,expected):
   seen=set();log=(OUT/'archive-stream.stderr').open('ab')
   proc=subprocess.Popen(args,stdout=subprocess.PIPE,stderr=log,stdin=subprocess.DEVNULL)
   try:
    with tarfile.open(fileobj=proc.stdout,mode='r|') as tar:
     for member in tar:
      assert member.isfile() and member.name in expected and member.name not in seen
      h=hashlib.sha256();n=0;f=tar.extractfile(member)
      for data in iter(lambda:f.read(1024*1024),b''):h.update(data);n+=len(data)
      x=expected[member.name];assert n==x['size'] and h.hexdigest()==x['sha256'],member.name;seen.add(member.name)
    while proc.stdout.read(1024*1024):pass
   except Exception:
    proc.stdout.close();proc.terminate();proc.wait();raise
   assert proc.wait()==0 and seen==set(expected);log.close()
  refs,_,errors=live_refs()
  full=BASE/'current-six-app-check/collections/20261128T135218Z-1485279/archive'
  control=full/'controller.json';proof=full/'collection-verification.json';commit='d9da8d73bac331e967df91418753b58dc6a3783e'
  published(control,commit);published(proof,commit);d=json.loads(control.read_text());v=json.loads(proof.read_text())
  assert d['controller_status']==0 and d['file_count']==6891 and v['archive_controller_sha256']==sha(control)
  parts=[]
  for x in v['parts']:
   p=ROOT/x['path'];published(p,commit,x['sha256']);assert p.stat().st_size==x['bytes'];parts.append(str(p))
  expected={name:dict(size=x['bytes'],sha256=x['sha256']) for name,x in d['files'].items()}
  verify_stream(['bash','-o','pipefail','-c','cat "$@" | zstd -q -d -c','archive',*parts],expected)
  collection=json.loads(Path(d['collection']['path']).read_text())
  roots=[Path('/workspaces/kprog-raw/perf/current-six-app-check-20261128')]+[Path(x['case']['run_dir']) for x in collection['new_cases']]
  groups=[dict(name='current-six-app-check',count=len(expected),commit=commit,files=[(Path(x['original_path']),expected[name]) for name,x in d['files'].items()],roots=roots)]
  cb=BASE/'core-field-predicates';manifest=cb/'census-archive.json';commit='884deec68a97439245a9eeba0565bfc7d1bfd2d3'
  published(manifest,commit);m=json.loads(manifest.read_text());archive=Path(m['archive']['path']);published(archive,commit,m['archive']['sha256'])
  assert m['every_decompressed_member_and_original_verified'] and m['member_count']==692
  expected={x['name']:dict(size=x['size'],sha256=x['sha256']) for x in m['members']}
  verify_stream(['zstd','-q','-d','-c',str(archive)],expected)
  groups.append(dict(name='core-census',count=len(expected),commit=commit,files=[(cb/name,x) for name,x in expected.items()],roots=[cb/'run']))
  tracked={str(ROOT/os.fsdecode(p)) for p in git('ls-files','-z').split(b'\0') if p}
  c['archives']=[]
  for group in groups:
   record=dict(name=group['name'],commit=group['commit'],verified_members=group['count'],eligible_files=0)
   # Full archive/member verification precedes any removal in this group.
   event('archive-verified',**record);os.fsync(J.fileno())
   for p,x in group['files']:
    if not any(p.is_relative_to(r) for r in group['roots']):continue
    if str(p) in tracked or 'prior-staging' in p.parts:continue
    if not p.exists():event('already-absent',path=str(p),category='raw');continue
    assert not p.is_symlink() and any(p.resolve().is_relative_to(r.resolve()) for r in group['roots'])
    if errors or any(r==str(p) for r in refs):event('retained',path=str(p),reason='active or uncertain reader scan',category='raw');continue
    remove(p,x,'raw',c);record['eligible_files']+=1
   c['archives'].append(record);save(c)
  c['retained_named_tmp_scratch']=[dict(path=p,reason='retain until exact ownership/rebuild provenance established; not a verified archived duplicate') for p in ['/tmp/otel4_o0.llvm.ll','/tmp/otel4_o0.ll','/tmp/o8.ll','/tmp/o8.bc','/tmp/t72.ll','/tmp/t72.bc','/tmp/pkall','/tmp/arch'] if Path(p).exists()]
  c['workspace_free_after']=os.statvfs(ROOT).f_bavail*os.statvfs(ROOT).f_frsize
  c['space_claim_scope']='removed logical/allocated file bytes, not physical host-node or Longhorn replica reclamation'
  c.update(status='complete',returncode=0)
 except Exception:c.update(status='failed',returncode=1,exception=traceback.format_exc())
 c['finished']=now();save(c);J.flush();os.fsync(J.fileno());J.close();return c['returncode']
if __name__=='__main__':raise SystemExit(main())
