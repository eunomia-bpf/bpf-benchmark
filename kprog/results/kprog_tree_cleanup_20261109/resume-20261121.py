#!/usr/bin/env python3
"""Preserve closed result output; retain active and source-owned paths in place."""
import collections, datetime, gzip, hashlib, json, os, re, shutil, subprocess, sys, time
from pathlib import Path
REPO=Path('/workspaces/repository')
REPORT=REPO/'kprog/results/kprog_tree_cleanup_20261109'
TEMP=Path('/var/tmp/kprog-tmp/S19/recheck-20261121')
RAW=Path('/workspaces/kprog-raw/cleanup/S19-20261121')
STATE=Path('/workspaces/.agent-state/kprog-lanes')
os.chdir(REPO)
def git(*args):return subprocess.check_output(['git',*args])
def save(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,indent=2)+'\n')
def digest(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(4194304),b''):h.update(b)
 return h.hexdigest()
def live():
 opened=[];commands=[];files=set();roots=set()
 for q in Path('/proc').iterdir():
  if not q.name.isdigit() or int(q.name) in [os.getpid(),os.getppid()]:continue
  try:
   args=(q/'cmdline').read_bytes().split(b'\0');commands.append((q.name,b' '.join(args).decode(errors='replace')))
   for a in args:
    p=Path(os.fsdecode(a))
    if (p.suffix in ['.py','.sh','.mk','.json','.yaml','.yml'] or p.name.lower()=='makefile') and p.is_file():
     files.add(str(p));roots.add(str(p.parent))
     files.update(str(f) for f in p.parent.iterdir() if f.is_file() and f.suffix in ['.json','.yaml','.yml'])
   if args and Path(os.fsdecode(args[0])).name in ['make','gmake']:
    default=Path(os.readlink(q/'cwd'))/'Makefile'
    if default.is_file():files.add(str(default));roots.add(str(default.parent))
   for fd in list((q/'fd').iterdir())+[q/'cwd',q/'exe']:
    try:opened.append((q.name,os.readlink(fd)))
    except OSError:pass
  except (OSError,PermissionError):pass
 return {'opened':opened,'commands':commands,'files':sorted(files),'roots':sorted(roots)}
def group(u):
 if u.startswith('corpus/results/otel-eq'):return 'otel-captures'
 if u.startswith('corpus/results/tet-eq'):return 'tetragon-captures'
 if u.startswith('corpus/results/perf-') and 'timing' in u:return 'performance-timing'
 if u.startswith('corpus/results/perf-'):return 'performance-captures'
 if u.startswith(('corpus/results/x86_kvm_corpus_','corpus/results/arm64_qemu_corpus_')):return 'numbered-runs'
 if u.startswith('corpus/results/'):return 'other-corpus-captures'
 if u.startswith('micro/results/'):return 'micro-captures'
 return 'legacy-result-captures'
def root_hold(u,e):
 root=str(REPO/u);holds=[]
 for pid,p in e['opened']:
  if p==root or p.startswith(root+'/'):holds.append('open:'+pid)
 for pid,c in e['commands']:
  if u in c or '/'+u.rsplit('/',1)[-1] in c:holds.append('command:'+pid)
 return holds
def audit():
 rows=json.load(open(TEMP/'status.json'));units=collections.defaultdict(list)
 for st,p in rows:
  if st=='??' and '/results/' in p:units['/'.join(p.split('/')[:3])].append(p)
 e=live();save(TEMP/'process-evidence.json',e)
 needles=TEMP/'needles.txt';needles.write_text('\n'.join(u.rsplit('/',1)[-1] for u in units)+'\n')
 keys={u.rsplit('/',1)[-1]:u for u in units};pattern=re.compile('|'.join(re.escape(x) for x in sorted(keys,key=len,reverse=True)))
 hits=collections.defaultdict(list);active=collections.defaultdict(list)
 def search(args,active_input=False):
  p=subprocess.Popen(['grep','-nHIF','-f',str(needles),*args],stdout=subprocess.PIPE,stderr=open(TEMP/'reference-errors.log','a'),text=True,errors='replace')
  for line in p.stdout:
   a=line.rstrip('\n').split(':',2)
   if len(a)!=3 or not a[1].isdigit():continue
   f,n,s=a
   for k in set(pattern.findall(s)):
    u=keys[k];r=[f,int(n),s[:1200]];hits[u].append(r)
    if active_input or f in e['files'] or any(f.startswith(r+'/') for r in e['roots'] if r.startswith(str(STATE))):active[u].append(r)
  rc=p.wait()
  if rc not in [0,1]:raise RuntimeError(('reference search',rc,args[:3]))
 if e['files']:search(e['files'],True)
 search(['-r',str(STATE)]+['--include=*.'+x for x in ['json','jsonl','py','sh','mk','md','yaml','yml','tsv','txt','log']]+['--exclude-dir='+x for x in ['.git','.lake','target','node_modules','build']])
 result=[]
 for u,paths in units.items():
  holds=root_hold(u,e);sources=[p for p in paths if Path(p).suffix in ['.py','.sh','.lean','.md','.rs']]
  if sources:holds.append('source-owner')
  if active[u]:holds.append('active-control-input')
  recent=False
  for r,ds,fs in os.walk(u,followlinks=False):
   for f in fs:
    try:
     if time.time()-os.lstat(os.path.join(r,f)).st_mtime<3600:recent=True;break
    except OSError:pass
   if recent:break
  if recent:holds.append('recent')
  result.append({'unit':u,'group':group(u),'paths':paths,'count':len(paths),'hold':sorted(set(holds)),'sources':sources,'references':hits[u],'active_references':active[u]})
  print('AUDIT',len(paths),u,sorted(set(holds)),flush=True)
 save(TEMP/'audit.json',result);print('AUDIT COMPLETE',len(result),flush=True)
def commit(paths,message):
 assert git('branch','--show-current').decode().strip()=='master'
 (TEMP/'precommit-status.txt').write_bytes(git('status','--short','--branch','--',*paths))
 subprocess.run(['git','diff','--check','--',*paths],check=True)
 subprocess.run(['git','add','-f','--',*paths],check=True)
 msg=TEMP/'commit-message';msg.write_text(message+'\n')
 subprocess.run(['git','commit','-F',str(msg),'--',*paths],check=True)
 subprocess.run(['git','show','--stat','--oneline','HEAD'],check=True)
 subprocess.run(['git','push','origin','master'],check=True)
 return git('rev-parse','HEAD').decode().strip()
def move(which):
 a=json.load(open(TEMP/'audit.json'));units=[x for x in a if x['group']==which and not x['hold']];receipts=[];deferred=[];patterns=[]
 RAW.mkdir(parents=True,exist_ok=True);link=TEMP.parent/'preserved-20261121'
 if not link.exists():link.symlink_to(RAW,target_is_directory=True)
 assert link.resolve()==RAW
 journal=RAW/(which+'-journal.jsonl')
 assert not journal.exists(),('existing move journal',str(journal))
 with journal.open('w') as j:
  for x in units:
   u=x['unit'];hold=root_hold(u,live())
   for r,ds,fs in os.walk(u,followlinks=False):
    for f in fs:
     try:
      if time.time()-os.lstat(os.path.join(r,f)).st_mtime<3600:hold.append('recent-descendant');break
     except OSError:pass
    if hold:break
   if hold:deferred.append({'unit':u,'hold':hold});continue
   tracked=set(os.fsdecode(b) for b in git('ls-tree','-r','--name-only','-z','HEAD','--',u).split(b'\0') if b)
   tracked.update(os.fsdecode(b) for b in git('ls-files','-z','--',u).split(b'\0') if b)
   count=0
   for p in x['paths']:
    src=REPO/p
    if p in tracked or not src.exists():continue
    assert not src.is_symlink(),p
    st=src.stat();assert time.time()-st.st_mtime>=3600,p
    h=digest(src);assert (src.stat().st_mtime_ns,src.stat().st_size)==(st.st_mtime_ns,st.st_size),p
    dst=RAW/'preserved'/p;dst.parent.mkdir(parents=True,exist_ok=True);assert not dst.exists(),str(dst)
    row={'path':p,'bytes':st.st_size,'mtime_ns':st.st_mtime_ns,'sha256':h,'preserved':str(dst)}
    j.write(json.dumps(row)+'\n');j.flush()
    shutil.move(src,dst);assert digest(dst)==h,p
    receipts.append(row);count+=1
   if count:patterns.append('/'+u+('/' if (REPO/u).is_dir() else ''))
   print('MOVED',which,u,count,flush=True)
 if not receipts:print('PROTECTED',which,deferred,flush=True);return
 ig=REPO/'.gitignore';old=ig.read_text();ps=[p for p in patterns if p not in old.splitlines()]
 if ps:ig.write_text(old.rstrip()+'\n\n# Closed capture outputs on persistent storage, S19 '+which+' 2026-11-21.\n'+'\n'.join(ps)+'\n')
 out=REPORT/('resume-20261121-'+which+'.json.gz')
 with gzip.open(out,'wt') as f:json.dump(receipts,f,indent=2);f.write('\n')
 info={'group':which,'moved_paths':len(receipts),'moved_bytes':sum(x['bytes'] for x in receipts),'closed_units':len(patterns),'deferred':deferred}
 save(RAW/(which+'-result.json'),info)
 with (REPORT/'resume-20261121.md').open('a') as f:f.write('\n'+which+': '+str(len(receipts))+' raw paths / '+str(info['moved_bytes'])+' bytes preserved across '+str(len(patterns))+' closed units. Each source and destination SHA-256 matches; receipt `'+out.name+'`. Deferred units: '+str(len(deferred))+'.\n')
 cs=commit(['.gitignore',str(out.relative_to(REPO)),str((REPORT/'resume-20261121.md').relative_to(REPO))],'Preserve closed '+which+' outputs on persistent storage')
 with (STATE/'COORDINATION.md').open('a') as f:f.write('\n- S19 '+datetime.datetime.now(datetime.timezone.utc).isoformat()+': Published '+which+' '+cs+'; '+str(len(receipts))+' raw files preserve their SHA-256 at '+str(RAW)+'. Current source and active inputs retain their owners.\n')
 print('PUBLISHED',json.dumps(info),cs,flush=True)
def historical():
 rows=[]
 for p in REPORT.glob('*-moves.json.gz'):
  with gzip.open(p,'rt') as f:rows.extend(json.load(f))
 wanted={x['sha256'] for x in rows};sizes={x['bytes'] for x in rows};matched={};archives=[];errors=[]
 roots=['kprog/results/kprog_fidelity_20261107','corpus/results/kprog_app_coverage_20261107','corpus/results/kprog_arm64_app_coverage_20261107','kprog/results/kprog_tree_cleanup_20261109','micro/results']
 for line in git('ls-tree','-r','-l','HEAD','--',*roots).decode().splitlines():
  meta,name=line.split('\t',1)
  if name.endswith('.tar.gz'):archives.append((meta.split()[2],name))
 class Reader:
  def __init__(self,f):self.f=f;self.h=hashlib.sha256()
  def read(self,n=-1):
   b=self.f.read(n);self.h.update(b);return b
 import tarfile
 for blob,name in archives:
  proc=subprocess.Popen(['git','cat-file','blob',blob],stdout=subprocess.PIPE)
  reader=Reader(proc.stdout)
  try:
   with tarfile.open(fileobj=reader,mode='r|gz') as tar:
    for member in tar:
     if member.isfile() and member.size in sizes:
      h=hashlib.sha256();f=tar.extractfile(member)
      for b in iter(lambda:f.read(4194304),b''):h.update(b)
      v=h.hexdigest()
      if v in wanted and v not in matched:matched[v]={'archive':name,'git_blob':blob,'member':member.name}
  except (tarfile.TarError,EOFError,OSError) as e:errors.append({'archive':name,'diagnostic':str(e)})
  for b in iter(lambda:reader.read(4194304),b''):pass
  assert proc.wait()==0,name
  v=reader.h.hexdigest()
  if v in wanted:matched[v]={'archive':name,'git_blob':blob,'member':'archive bytes'}
  print('HISTORICAL',name,'matched_hashes',len(matched),flush=True)
 result={'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'receipt_files':len(rows),'archive_files_scanned':len(archives),'matched_files':sum(x['sha256'] in matched for x in rows),'diagnostics':errors,'records':[dict(x,published_content=matched.get(x['sha256'])) for x in rows]}
 RAW.mkdir(parents=True,exist_ok=True);save(RAW/'historical-correspondence.json',result)
 with gzip.open(REPORT/'historical-correspondence-20261121.json.gz','wt') as f:json.dump(result,f,indent=2);f.write('\n')
 print('HISTORICAL COMPLETE',result['matched_files'],len(rows),'archives',len(archives),'diagnostics',len(errors),flush=True)
if __name__=='__main__':
 if sys.argv[1]=='audit':audit()
 elif sys.argv[1]=='move':move(sys.argv[2])
 elif sys.argv[1]=='historical':historical()
 else:raise SystemExit('audit | move GROUP')
