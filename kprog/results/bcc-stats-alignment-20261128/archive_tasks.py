"""Archive every closed1465233 raw observation/corpus file and verify every payload."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;PAIR=HERE/'task-state-pair';OUT=PAIR/'archive';assert not OUT.exists();OUT.mkdir();os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def file_sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='inventory',scope='Closed1465233 taskstate captures plus originalcorpus files only. Preserve complete bytes, even incomplete sampledELFs; archival success is not profile/code/PMU validity. Analysis outputs are published separately after review. No source/native capture deletion.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save();c=json.loads((PAIR/'controller.json').read_text());assert c['pid']==1465233 and c['controller_status']==0 and len(c['cases'])==2;raw=Path(c['raw']);files={}
 r['preserved_prior_staging']=[str(p) for p in sorted(raw.glob('*/prior-staging'))];save()
 for p in sorted(raw.rglob('*')):
  if 'prior-staging' in p.relative_to(raw).parts:continue
  if p.is_file():assert not p.is_symlink();files['observations/'+str(p.relative_to(raw))]=p
 for case in c['cases']:
  base=Path(case['run_dir']);assert case['guest-exit.txt']=='0' and case['image_matches']
  for p in sorted(base.rglob('*')):
   if p.is_file():assert not p.is_symlink();files[str(p.relative_to(ROOT))]=p
 files['controller-logs/task-state-job.log']=HERE/'task-state-job.log'
 assert files;manifest={n:dict(original_path=str(p),bytes=p.stat().st_size,sha256=file_sha(p)) for n,p in files.items()};r['files']=manifest;r['file_count']=len(files);r['logical_bytes']=sum(v['bytes'] for v in manifest.values());r['phase']='archive';save()
 with (OUT/'pipeline.log').open('wb') as log:
  z=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=log);sp=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=z.stdout,stderr=log);z.stdout.close()
  with tarfile.open(fileobj=z.stdin,mode='w|') as tf:
   for n,p in files.items():
    v=manifest[n];ti=tarfile.TarInfo(n);ti.size=v['bytes'];ti.mode=p.stat().st_mode&0o777
    with p.open('rb') as f:tf.addfile(ti,f)
  z.stdin.close();codes=[z.wait(),sp.wait()];assert codes==[0,0],codes
 parts=sorted(OUT.glob('evidence.tar.zst.part-*'));assert parts;r['parts']=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=file_sha(p)) for p in parts];r['archive_returncodes']=codes;r['phase']='verify-all-members';save();a=subprocess.Popen(['cat',*[str(p) for p in parts]],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL);z=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();seen=set()
 with tarfile.open(fileobj=z.stdout,mode='r|') as tf:
  for m in tf:
   assert m.isfile() and m.name in manifest and m.name not in seen;h=hashlib.sha256();f=tf.extractfile(m)
   for b in iter(lambda:f.read(1048576),b''):h.update(b)
   v=manifest[m.name];assert m.size==v['bytes'] and h.hexdigest()==v['sha256'];seen.add(m.name)
 z.stdout.close();assert a.wait()==z.wait()==0 and seen==set(manifest)
 for n,p in files.items():assert p.stat().st_size==manifest[n]['bytes'] and file_sha(p)==manifest[n]['sha256'],n
 r.update(controller_status=0,phase='complete',verified_files=len(seen),all_originals_preserved=True)
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k!='files'}),flush=True)
raise SystemExit(r['controller_status'])
