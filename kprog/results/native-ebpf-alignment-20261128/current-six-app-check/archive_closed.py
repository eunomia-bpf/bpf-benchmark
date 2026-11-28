"""Full48MBparts of a frozen closed-case collection; never touches activecases/priorstaging."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,sys,tarfile,traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;COLLECTION=Path(sys.argv[1]).resolve();OUT=COLLECTION.parent/'archive';assert not OUT.exists();OUT.mkdir();os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='inventory',scope='Only newcompleted cases in immutable collection of SAME1481233; full ownclosedraw/corpus/review bytes. Exclude/preserve priorstaging, no activecase/globalmutablecontroller/archive recursion, no source/nativeP deletion. Archive status is bytepreservation, not code/work/performance acceptance.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save();c=json.loads(COLLECTION.read_text());assert c['same_chain_pid']==1481233 and c['status']==0 and c['new_cases'];files={'review/collection.json':COLLECTION};r['collection']=dict(path=str(COLLECTION),sha256=sha(COLLECTION));r['cases']=[];r['preserved_prior_staging']=[]
 for item in c['new_cases']:
  case=item['case'];key=case['app'].replace('/','__');raw=Path(case['raw']).resolve();assert raw==Path('/workspaces/kprog-raw/perf/current-six-app-check-20261128')/key;assert case.get('ended_utc') and case.get('run_dir');run=Path(case['run_dir']).resolve();assert run.parent==ROOT/'corpus/results';review=Path(item['review']['path']);assert sha(review)==item['review']['sha256'];r['cases'].append(case['app']);r['preserved_prior_staging'].append(str(raw/'prior-staging'))
  for p in sorted(raw.rglob('*')):
   if 'prior-staging' in p.relative_to(raw).parts:continue
   if p.is_file():assert not p.is_symlink();files['observations/'+key+'/'+str(p.relative_to(raw))]=p
  for p in sorted(run.rglob('*')):
   if p.is_file():assert not p.is_symlink();files[str(p.relative_to(ROOT))]=p
  files['review/'+key+'.json']=review
 assert files;manifest={n:dict(original_path=str(p),bytes=p.stat().st_size,sha256=sha(p)) for n,p in files.items()};r['files']=manifest;r['file_count']=len(files);r['logical_bytes']=sum(v['bytes'] for v in manifest.values());r['phase']='archive';save()
 with (OUT/'pipeline.log').open('wb') as log:
  z=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=log);sp=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=z.stdout,stderr=log);z.stdout.close()
  with tarfile.open(fileobj=z.stdin,mode='w|') as tf:
   for n,p in files.items():
    ti=tarfile.TarInfo(n);ti.size=manifest[n]['bytes'];ti.mode=p.stat().st_mode&0o777
    with p.open('rb') as f:tf.addfile(ti,f)
  z.stdin.close();codes=[z.wait(),sp.wait()];assert codes==[0,0],codes
 parts=sorted(OUT.glob('evidence.tar.zst.part-*'));assert parts;r['parts']=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=sha(p)) for p in parts];r['archive_returncodes']=codes;r['phase']='verify-all-members';save();a=subprocess.Popen(['cat',*[str(p) for p in parts]],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE);z=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();seen=set()
 with tarfile.open(fileobj=z.stdout,mode='r|') as tf:
  for m in tf:
   assert m.isfile() and m.name in manifest and m.name not in seen;h=hashlib.sha256();f=tf.extractfile(m)
   for b in iter(lambda:f.read(1048576),b''):h.update(b)
   v=manifest[m.name];assert m.size==v['bytes'] and h.hexdigest()==v['sha256'];seen.add(m.name)
 z.stdout.close();assert a.wait()==z.wait()==0 and seen==set(manifest)
 for n,p in files.items():assert p.stat().st_size==manifest[n]['bytes'] and sha(p)==manifest[n]['sha256'],n
 r.update(controller_status=0,phase='complete',verified_files=len(seen),all_originals_preserved=True)
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k!='files'}),flush=True)
raise SystemExit(r['controller_status'])
