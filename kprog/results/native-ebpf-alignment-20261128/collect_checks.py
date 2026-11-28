"""Preserve the finite alignment pass, including failures and partial semantic evidence."""
from pathlib import Path
import hashlib,json,os,re,select,subprocess,sys,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(sys.argv[1]).resolve();meta=OUT/'controller.json'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='own-check-dependency')
def save():(OUT/'collection-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 c=json.loads(meta.read_text());r['check_pid']=c['pid'];save()
 if c['phase']=='checks':
  try:fd=os.pidfd_open(c['pid'])
  except ProcessLookupError:fd=None
  if fd is not None:select.select([fd],[],[]);os.close(fd)
 c=json.loads(meta.read_text());assert c['phase'] in ['finished','failed'];raw=Path(c['raw']);r.update(phase='collecting',raw=str(raw));save();summary=dict(check_controller_status=c['controller_status'],image=c.get('image'),checks=[],otel_reused=c['reuse_otel'],scope='One10s/stats1 current-image check per app. No PMU/tuning/fulltiming. Workload outputs, active program counts and sampled maps establish only the evidence they directly contain; no automatic equal-work verdict.')
 sources={}
 for x in c['checks']:
  row=dict(x);row['apps']=[];d=Path(x['raw']);row['observer_snapshots']=len(list((d/'map-observe').glob('*/snapshot.json')));rp=x.get('run');run=Path(rp) if rp else None
  if run and run.is_dir():
   for p in run.rglob('*'):
    if p.is_file():sources[str(p.relative_to(ROOT))]=dict(bytes=p.stat().st_size,sha256=sha(p))
   for p in sorted((run/'details/apps').glob('*.json')):
    a=json.loads(p.read_text());app=dict(app=a['app'],status=a['status'],error=a.get('error'),phases={})
    for ph in ['baseline','post_rejit']:
     arm=a.get(ph,{});bpf=arm.get('bpf',{});app['phases'][ph]=dict(programs=bpf,active_programs=sum(v.get('run_cnt_delta',0)>0 for v in bpf.values()),workloads=arm.get('workloads',[]))
    row['apps'].append(app)
   logs=list((run/'details/shim-logs').glob('*.post_rejit.log'));text='\n'.join(p.read_text() for p in logs);row['native_replacements']=text.count('native-loader replaced prog=');row['native_failures']=text.count('native-loader failed');row['failure_lines']=[s for s in text.splitlines() if 'native-loader failed' in s]
  summary['checks'].append(row)
 (OUT/'check-summary.json').write_text(json.dumps(summary,indent=2)+'\n');(OUT/'corpus-source-files.json').write_text(json.dumps(sources,indent=2)+'\n')
 with tarfile.open(raw/'corpus-source.tar.gz','w:gz') as t:
  for p in sorted(sources):t.add(ROOT/p,arcname=p)
 files={str(p.relative_to(raw)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in raw.rglob('*') if p.is_file()};assert not any(p.is_symlink() for p in raw.rglob('*'))
 with (OUT/'archive.log').open('wb') as log:
  a=subprocess.Popen(['tar','-C',str(raw.parent),'-cf','-',raw.name],stdout=subprocess.PIPE,stderr=log);b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close();z=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[a.wait(),b.wait(),z.wait()];assert codes==[0,0,0]
 parts=sorted(OUT.glob('evidence.tar.zst.part-*'));a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();check={}
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   if m.isfile():check[str(Path(*Path(m.name).parts[1:]))]=dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest())
 b.stdout.close();assert a.wait()==b.wait()==0 and check==files
 r.update(controller_status=0,phase='finished',verified_files=len(files),files=files,archive_returncodes=codes,parts=[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=sha(p)) for p in parts])
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['phase','controller_status','verified_files','exception']}),flush=True)
raise SystemExit(r['controller_status'])
