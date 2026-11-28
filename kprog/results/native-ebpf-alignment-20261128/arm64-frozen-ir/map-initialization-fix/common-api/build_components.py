"""Build only the corrected ARM app and its existing integration-test target."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;APP=ROOT/'vendor/repos/opentelemetry-ebpf-profiler';LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def product(p):return dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p),elf_machine=int.from_bytes(p.read_bytes()[18:20],'little'))
def protected():
 paths=[p for p in (ROOT/'vendor/build/native-bpf/arm64/stage').rglob('*') if p.is_file()]+[ROOT/'vendor/build/x86/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler',ROOT/'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.arm64',ROOT/'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64',ROOT/'.cache/qemu-arm64-root/usr/local/bin/otelcol-ebpf-profiler',Path('/workspaces/.agent-state/kprog-ck/build-arm64/arch/arm64/boot/Image'),Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage')]
 return {str(p):sha(p) for p in paths}
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='preflight',scope='Common-API corrected ARM Go app and integration test binary; production source changed since1301921, so new compilation is required; compile48GiB/max2/16,18 outside timing/image locks. No kernel/nativeP/BPF asset generation/x86 app or image/guest/framework/settings change.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 os.sched_setaffinity(0,{19});source=json.loads((OUT/'source-preparation.json').read_text());r['source_sha256']=source['source_sha256']
 for name,h in r['source_sha256'].items():assert sha(APP/name)==h,name
 backup=json.loads((OUT.parent/'products-before.json').read_text());archive=ROOT/backup['archive']['path'];assert sha(archive)==backup['archive']['sha256'];assert subprocess.check_output(['git','show','HEAD:'+str(archive.relative_to(ROOT))])==archive.read_bytes()
 r['protected_before']=protected();r['image_ids_before']={tag:subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip() for tag in ['bpf-benchmark/kprog:current','bpf-benchmark/runner-runtime:arm64']};save()
 for label,script in [('integration_compile','build-regression.sh'),('app_compile','build-arm-app.sh')]:
  r['phase']=label;save()
  with (OUT/(label+'.log')).open('wb') as log:r[label+'_returncode']=subprocess.run(['bash',str(OUT.parent/script)],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  save()
  if r[label+'_returncode']==0:
   p=APP/'support/tracer.test' if label=='integration_compile' else ROOT/'vendor/build/arm64/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler';r[label+'_product']=product(p);assert r[label+'_product']['elf_machine']==183
 for name,h in r['source_sha256'].items():assert sha(APP/name)==h,name
 r['protected_after']=protected();r['image_ids_after']={tag:subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip() for tag in r['image_ids_before']};assert r['protected_before']==r['protected_after'] and r['image_ids_before']==r['image_ids_after']
 r['controller_status']=0 if r['integration_compile_returncode']==r['app_compile_returncode']==0 else 1;r['phase']='finished-runtime-regression-and-work-check-pending' if r['controller_status']==0 else 'finished-build-failure-receipts-retained'
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','integration_compile_returncode','app_compile_returncode','exception']}),flush=True)
raise SystemExit(r['controller_status'])
