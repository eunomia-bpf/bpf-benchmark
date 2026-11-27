"""Collect the finite ARM paired sweep, publish evidence, then verify raw dedup."""
import ast
import collections
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import select
import shutil
import subprocess
import sys
import tarfile
import tempfile
import traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());OUT=Path(run['result']);RAW=Path(run['raw'])
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def git(*args,env=None,input=None):return subprocess.check_output(['git',*args],cwd=ROOT,env=env,input=input)
def digest(path):
 h=hashlib.sha256()
 with path.open('rb') as f:
  for data in iter(lambda:f.read(1048576),b''):h.update(data)
 return h.hexdigest()
def entries():return {x.split(b'\t',1)[1]:x.split(b'\t',1)[0] for x in git('ls-files','--stage','-z').split(b'\0') if x}
def publish(paths,note,title,receipt):
 note=note.encode()
 for p in [ROOT/'COORDINATION.md',LANE.parent/'COORDINATION.md']:
  with p.open('ab') as f:f.write(note)
 def blob(data):return git('hash-object','-w','--stdin',input=data).decode().strip()
 owned=set(paths);excluded=lambda p:p==b'COORDINATION.md' or p.decode() in owned
 with (LANE.parent/'locks/git').open('a') as lock:
  fcntl.flock(lock,fcntl.LOCK_EX);prior=entries();coord=git('show',':COORDINATION.md')
  fd,index=tempfile.mkstemp(prefix='perf-scalar-collect-',dir=LANE);os.close(fd);shutil.copyfile(ROOT/'.git/index',index);env=dict(os.environ,GIT_INDEX_FILE=index)
  try:
   for raw in git('diff','--cached','--name-only','-z',env=env).split(b'\0'):
    if not raw:continue
    path=raw.decode();entry=git('ls-tree','HEAD','--',path).decode().strip()
    if entry:
     mode,kind,rest=entry.split(' ',2);git('update-index','--cacheinfo',mode,rest.split('\t')[0],path,env=env)
    else:git('update-index','--force-remove','--',path,env=env)
   git('add','-f','--',*paths,env=env);base=git('show','HEAD:COORDINATION.md');assert note not in base
   git('update-index','--cacheinfo','100644',blob(base+note),'COORDINATION.md',env=env)
   subprocess.run(['git','commit','-m',title],cwd=ROOT,env=env,check=True);subprocess.run(['git','push'],cwd=ROOT,env=env,check=True)
   subprocess.run(['git','add','-f','--',*paths],cwd=ROOT,check=True);assert note not in coord;git('update-index','--cacheinfo','100644',blob(coord+note),'COORDINATION.md')
   after=entries();assert {p:v for p,v in prior.items() if not excluded(p)}=={p:v for p,v in after.items() if not excluded(p)},'peer staged entry changed'
   result=dict(commit=git('rev-parse','HEAD').decode().strip(),remote=git('ls-remote','origin','refs/heads/master').decode().strip());(LANE/receipt).write_text(json.dumps(result,indent=2)+'\n');return result
  finally:os.unlink(index)

if '--cleanup-receipt' in sys.argv:
 cleanup=json.loads((LANE/'scalar-raw-cleanup.log').read_text());path=ROOT/cleanup['receipt'];r=json.loads(path.read_text())
 note=f'\n- LANE PERF {now()}: Fullscalar145publication verified-duplicate cleanup result removed_allocated_bytes={r["removed_allocated_bytes"]};actions={[(x["raw"],x["status"]) for x in r["actions"]]}. Existingraw_dedup verifiedcommittedGitblob/everyfileSHA-size-fileset beforedeletion;archivepartsretained,stage2ownRAW/FORMAL090610/rawexports untouched. Actualreceipt{cleanup["receipt"]};retained/mismatchcasesarenotsuccess.\n'
 result=publish([cleanup['receipt']],note,'Record verified raw dedup after ARM scalar sweep','scalar-cleanup-publication.json');print(json.dumps(result));raise SystemExit(0)


record=dict(pid=os.getpid(),raw=str(RAW),started_utc=now(),phase='waiting-for-existing-pipeline',scope='All145 captured B paired stock loads,117 originalrefusals+28acceptedcontrols. Fresh empty map shapes/production relocations; kernel acceptance is distinct from native install/stage2/runtime performance. No new compiler/guest/source/flags changes.',controller_status=None)
def save():(OUT/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
try:
 save();launch=json.loads((OUT/'stage2-queued.json').read_text());pid=launch['dependency_pid'];record['dependency_pid']=pid;save()
 try:fd=os.pidfd_open(pid)
 except ProcessLookupError:fd=None
 if fd is not None:
  try:
   stat=Path('/proc/'+str(pid)+'/stat').read_text();assert stat.rsplit(')',1)[1].split()[19]==launch['dependency_start_ticks'],'dependency PID reused'
   poll=select.poll();poll.register(fd,select.POLLIN);poll.poll()
  finally:os.close(fd)
 compiled=json.loads((OUT/'compile-controller.json').read_text());assert compiled['controller_status']==0 and len(compiled['cases'])==145
 stock=json.loads((OUT/'all145-stock-controller.json').read_text());cases=stock['stock']['cases'];assert len(cases)==145 and len({x['index'] for x in cases})==145
 record.update(phase='collecting-completed-pipeline',compile_status=compiled['controller_status'],stock_execution_status=stock['controller_status'],stock_guest_status=stock.get('guest_status'),header_drift=compiled['header_drift']);save()
 patterns_path=ROOT/'kprog/results/arm64-checked-corpus-20261127/refusals.py';tree=ast.parse(patterns_path.read_text());patterns=ast.literal_eval(next(n.value for n in tree.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='PATTERNS' for t in n.targets)))
 original=json.loads((patterns_path.parent/'refusals.json').read_text());families={(r['app'],r['request']):r['family'] for r in original['stock_refusals']};prepared={x['index']:x for x in json.loads((OUT/'prepare-controller.json').read_text())['inputs']}
 outcomes=[]
 for case in sorted(cases,key=lambda c:c['index']):
  item=prepared[case['index']];row={k:case[k] for k in ['index','app','request','symbol','original_stock_passed']};row['original_family']=families.get((case['app'],case['request']));row['baseline_kind']=item['baseline_kind']
  for phase in ['before','after']:
   load=case['loads'][phase];path=RAW/str(case['index'])/('stock-'+phase+'.verifier.log');text=path.read_text() if path.exists() else ''
   status='accepted' if load['returncode']==0 and load.get('result',{}).get('stock_loaded') is True else 'refused' if load['returncode']==2 and load.get('result',{}).get('stock_loaded') is False else 'preparation-error'
   family=None;diagnostics=[]
   if status=='refused':
    family='unclassified'
    for name,pattern in patterns:
     matches=[line for line in text.splitlines() if re.search(pattern,line)]
     if matches:family=name;diagnostics=matches;break
   row[phase]=dict(status=status,returncode=load['returncode'],errno=load.get('result',{}).get('errno'),family=family,diagnostics=diagnostics,verifier_tail=text.splitlines()[-8:],verifier_sha256=digest(path) if path.exists() else None,preparation_error=load.get('preparation_error'))
  row['before_matches_original']=None if row['before']['status']=='preparation-error' else (row['before']['status']=='accepted')==row['original_stock_passed'];outcomes.append(row)
 def stats(rows):return dict(requests=len(rows),before=dict(collections.Counter(r['before']['status'] for r in rows)),after=dict(collections.Counter(r['after']['status'] for r in rows)),transitions=dict(collections.Counter(r['before']['status']+' -> '+r['after']['status'] for r in rows)),after_families=dict(collections.Counter(r['after']['family'] for r in rows if r['after']['status']=='refused')),fixture_before_disagreements=sum(r['before_matches_original'] is False for r in rows))
 summary=dict(all=stats(outcomes),original_refused=stats([r for r in outcomes if not r['original_stock_passed']]),accepted_controls=stats([r for r in outcomes if r['original_stock_passed']]),apps={app:stats([r for r in outcomes if r['app']==app]) for app in sorted({r['app'] for r in outcomes})})
 (OUT/'outcomes.json').write_text(json.dumps(dict(utc=now(),scope=record['scope'],summary=summary,requests=outcomes),indent=2)+'\n')
 with (OUT/'outcomes.tsv').open('w') as f:
  cols=['index','app','request','symbol','original_stock_passed','original_family','before_status','before_family','after_status','after_family','before_matches_original'];f.write('\t'.join(cols)+'\n')
  for r in outcomes:
   flat=dict(r,before_status=r['before']['status'],before_family=r['before']['family'],after_status=r['after']['status'],after_family=r['after']['family']);f.write('\t'.join(str(flat.get(k,'')) for k in cols)+'\n')
 (OUT/'stock-outcome.md').write_text('# ARM scalar-memory paired verifier outcomes\n\n'+json.dumps(summary,indent=2)+'\n\nAll145 originally generated B inputs, including117 refusals and28 accepted controls. Five original generation failures are not B inputs. Before objects are qualified controls and after objects use the general probe-read route with the unchanged common ARM flags. Preparation failures are separate from kernel refusals; fixture-before disagreements with original live outcomes are retained. Fresh maps do not establish live application binding, native install, stage2 workload or frozen startup success. Queued Tetragon stage2 is collected separately. Full per-request diagnostics and original/new families are in outcomes.json/tsv.\n')
 with tarfile.open(RAW/'collection-source.tar','w') as t:
  for p in [Path(__file__),patterns_path]:t.add(p,arcname=str(p.relative_to(ROOT)))
 files={str(p.relative_to(RAW)):dict(bytes=p.stat().st_size,sha256=digest(p)) for p in sorted(RAW.rglob('*')) if p.is_file()};assert not any(p.is_symlink() for p in RAW.rglob('*'))
 with (OUT/'archive.log').open('wb') as log:
  a=subprocess.Popen(['tar','-C',str(RAW.parent),'-cf','-',RAW.name],stdout=subprocess.PIPE,stderr=log);b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close();c=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[a.wait(),b.wait(),c.wait()];assert codes==[0,0,0]
 parts=sorted(OUT.glob('evidence.tar.zst.part-*'));a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();found={}
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   path=Path(m.name);assert path.parts[0]==RAW.name and not path.is_absolute() and '..' not in path.parts
   if m.isdir():continue
   assert m.isfile();h=hashlib.sha256();stream=t.extractfile(m)
   for data in iter(lambda:stream.read(1048576),b''):h.update(data)
   found[str(Path(*path.parts[1:]))]=dict(bytes=m.size,sha256=h.hexdigest())
 b.stdout.close();assert a.wait()==b.wait()==0 and files==found
 record.update(phase='finished',summary=summary,archive_returncodes=codes,verified_files=len(files),archive_files=files,parts=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=digest(p)) for p in parts],controller_status=0,ended_utc=now());save()
 paths=[str(p.relative_to(ROOT)) for p in [OUT/'controller.json',OUT/'compile-controller.json',OUT/'all145-stock-controller.json',OUT/'outcomes.json',OUT/'outcomes.tsv',OUT/'stock-outcome.md',OUT/'archive.log',*parts]]
 note=f'\n- LANE PERF {now()}: Completed full145scalarcommonflags pairedARMstock collection:all={summary["all"]},original117={summary["original_refused"]},controls28={summary["accepted_controls"]};stockexecutionstatus={stock["controller_status"]}. Preparationerrorsdistinct,fixture-beforedisagreementsretained;freshmapacceptancenotnative/stage2/workload. {len(files)}rawfilesSHA-size-filesetmatchedarchivesat{OUT.relative_to(ROOT)};privatepublicationthenexistingverifieddedupfollows. QueuedTetragon1073302actualresultseparate;itsRAW/FORMAL090610/rawexports/frozen/peerunchanged.\n'
 publication=publish(paths,note,'Record complete ARM scalar probe paired verifier outcomes','scalar-collection-publication.json')
 print(json.dumps(dict(status=0,result=str(OUT),publication=publication,summary=summary)),flush=True)
except Exception:
 record.update(controller_status=1,phase='failed',exception=traceback.format_exc(),ended_utc=now());save();print(record['exception'],flush=True)
finally:
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM scalar full145 evidence collector ended status '+str(record['controller_status'])+'. Read '+str(OUT/'controller.json')+'/outcomes.json and publication/cleanup receipts. Native/stage2 workload remains separate. On collector/publication failure preserve RAW and repair forward without rerunning the finished sweep.\n')
raise SystemExit(record['controller_status'])
