"""One frozen ARM OTel functional cell with independent code/map observations."""
from pathlib import Path
import fcntl,hashlib,json,os,re,resource,shutil,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');BASE=ROOT/'.cache/qemu-arm64-root';RAW=Path(sys.argv[1]);K=Path('/workspaces/.agent-state/kprog-ck/build-arm64')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def image(tag):return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip()
def protected():
 activation=json.loads((OUT.parent/'fixed-app-activation/controller.json').read_text());return {p:sha(Path(p)) for p in activation['protected_after']}
r=dict(pid=os.getpid(),started_utc=now(),phase='preflight',controller_status=None,raw=str(RAW),scope='SAME frozen ARM corpus OTel 1x10s/stats-on functional cell, Cortex-A57/4vCPU/8G/TCG; actual code/map observations only, not timing/performance acceptance.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
r['host_address_space_limit']=list(resource.getrlimit(resource.RLIMIT_AS))
status=1;original=None;lock=None
try:
 assert not RAW.exists();RAW.mkdir(parents=True);os.sched_setaffinity(0,{16,18,19});save()
 lock=(LANE.parent/'locks/image').open('a');fcntl.flock(lock,fcntl.LOCK_EX)
 for p in Path('/proc').iterdir():
  if p.name.isdigit():
   try:exe=(p/'exe').readlink()
   except OSError:continue
   assert 'qemu-system-aarch64' not in exe.name,('active ARM guest',p.name)
 activation=json.loads((OUT.parent/'fixed-app-activation/controller.json').read_text());assert activation['controller_status']==0
 for row in activation['image_payload_verified']:assert sha(BASE/row['path'].lstrip('/'))==row['sha256']
 r.update(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),protected_before=protected(),arm_image_before=image('bpf-benchmark/runner-runtime:arm64'),x86_image_before=image('bpf-benchmark/kprog:current'))
 original=(BASE/'qemu-init').read_bytes();assert original==(ROOT/'runner/scripts/qemu-arm64-init').read_bytes();(OUT/'original-init.sh').write_bytes(original);(BASE/'qemu-original-init').write_bytes(original);(BASE/'qemu-original-init').chmod(0o755)
 obs=BASE/'perf-observe';assert not obs.exists();obs.mkdir()
 for name in ['observe_guest.py','observe_maps.py','dump_prog.py']:shutil.copy2(OUT/name,obs/name)
 (BASE/'qemu-init').write_bytes((OUT/'observer-init.sh').read_bytes());(BASE/'qemu-init').chmod(0o755)
 r['observer_sources_sha256']={n:sha(OUT/n) for n in ['observe_guest.py','observe_maps.py','dump_prog.py','observer-init.sh']}
 results=ROOT/'corpus/results';before={p.name for p in results.iterdir() if p.is_dir()};r['phase']='guest';r['guest_started_utc']=now()
 command=['make','-f',str(ROOT/'kprog/perf/one-image-arm64/Makefile'),'corpus','APPS=otelcol-ebpf-profiler/profiling','SAMPLES=1','WORKLOAD_DURATION=10','BPFREJIT_CORPUS_BPF_STATS=1','JOBS=2'];r['command']=command;save()
 fcntl.flock(lock,fcntl.LOCK_SH)
 with (RAW/'guest.log').open('wb') as log:r['make_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
 r['guest_status']=(BASE/'qemu-status').read_text().strip();r['guest_ended_utc']=now();r['phase']='collect';save()
 shutil.copytree(obs,RAW/'observations',symlinks=True)
 new=sorted(p for p in results.iterdir() if p.is_dir() and p.name not in before and p.name.startswith('arm64_qemu_corpus_'));r['corpus_paths']=[str(p) for p in new];r['app_statuses']=[]
 for p in new:
  shutil.copytree(p,RAW/'corpus'/p.name)
  q=p/'details/apps/otelcol-ebpf-profiler__profiling.json'
  if q.exists():r['app_statuses'].append(json.loads(q.read_text()).get('status'))
 r.update(protected_after=protected(),arm_image_after=image('bpf-benchmark/runner-runtime:arm64'),x86_image_after=image('bpf-benchmark/kprog:current'))
 assert r['protected_before']==r['protected_after'] and r['arm_image_before']==r['arm_image_after'] and r['x86_image_before']==r['x86_image_after']
 assert r['make_returncode']==0 and r['guest_status']=='0' and r['app_statuses']==['ok']
 status=0;r['phase']='finished-manual-code-work-audit-pending'
except Exception:r.update(phase='failed',exception=traceback.format_exc())
finally:
 if original is not None and BASE.exists():
  (BASE/'qemu-init').write_bytes(original);(BASE/'qemu-init').chmod(0o755);r['original_init_restored']=sha(BASE/'qemu-init')==hashlib.sha256(original).hexdigest()
 if lock is not None:fcntl.flock(lock,fcntl.LOCK_UN);lock.close()
 r.update(controller_status=status,ended_utc=now());save()
 if RAW.exists():
  files={str(p.relative_to(RAW)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in RAW.rglob('*') if p.is_file() and not p.is_symlink()};(OUT/'raw-file-manifest.json').write_text(json.dumps(files,indent=2)+'\n')
  try:
   os.sched_setaffinity(0,{19})
   with (OUT/'archive.log').open('wb') as log:
    a=subprocess.Popen(['tar','-C',str(RAW.parent),'-cf','-',RAW.name],stdout=subprocess.PIPE,stderr=log);b=subprocess.Popen(['zstd','-T1','-3','-c'],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close();c=subprocess.Popen(['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')],stdin=b.stdout,stderr=log);b.stdout.close();codes=[c.wait(),b.wait(),a.wait()][::-1]
   r['archive_returncodes']=codes;assert codes==[0,0,0]
  except Exception:r['archive_exception']=traceback.format_exc()
  save()
 print(json.dumps({k:r.get(k) for k in ['pid','controller_status','phase','make_returncode','guest_status','app_statuses','exception','archive_returncodes']}),flush=True)
raise SystemExit(status)
