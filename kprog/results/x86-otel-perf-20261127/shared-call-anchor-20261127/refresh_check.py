"""Replace the sole runtime image with the branch-anchor linker repair, then observe the frozen OTel check."""
import fcntl,hashlib,json,os,resource,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');LOCKS=LANE.parent/'locks'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='image-refresh',source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),scope='In-place sole-image linker replacement with existing frozen runtime recipe and unchanged compiled P/kernel inputs, then one frozen effective1x10s OTel stats-on diagnostic with actual in-phase code capture. No full timing.')
def save():(HERE/'refresh-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save()
 assert (HERE/'build.exit').read_text().strip()=='0' and (HERE/'offline.exit').read_text().strip()=='0'
 with (LOCKS/'timing').open('a') as timing,(LOCKS/'image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX)
  def image_id():return subprocess.check_output(['docker','image','inspect','bpf-benchmark/kprog:current','--format','{{.Id}}'],text=True).strip()
  r['old_image']=image_id();kernel=Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage');r['kernel_sha256']=sha(kernel)
  linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link';r['linker_sha256']=sha(linker)
  stage=ROOT/'vendor/build/native-bpf/x86/stage';inputs={str(p.relative_to(stage)):sha(p) for p in stage.rglob('*') if p.is_file()};r['native_input_sha256']=inputs;save()
  targets=['host-kinsn-x86','host-rust-x86','host-shim-x86','host-source-apps-x86','host-runner-x86','host-micro-programs-x86','host-stage2-programs-x86','host-x86-sim-proofs','host-bpfopt-llvm-x86','host-native-bpf-x86','host-kernel-x86']
  cmd=['make','-C',str(ROOT),'-o',str(kernel)]
  for target in targets:cmd+=['-o',target]
  cmd+=['x86-runner-runtime-image-tar','HOST_KERNEL_BUILD_DIR_X86=/workspaces/.agent-state/kprog-ck/build-x86','X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/kprog:current','X86_RUNTIME_KERNEL_IMAGE='+str(kernel),'JOBS=2','IMAGE_BUILD_JOBS=2'];r['command']=cmd;save()
  def build_limits():
   resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
  with (HERE/'image-refresh.log').open('wb') as log:rc=subprocess.run(cmd,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=build_limits).returncode
  r['image_returncode']=rc;save();assert rc==0,rc
  r['new_image']=image_id();r['kernel_unchanged']=sha(kernel)==r['kernel_sha256'];r['native_inputs_unchanged']=inputs=={str(p.relative_to(stage)):sha(p) for p in stage.rglob('*') if p.is_file()};assert r['kernel_unchanged'] and r['native_inputs_unchanged'];save()
  # The old untagged image is a rebuildable product; retain all evidence and
  # use the new current image as the sole kprog runtime.
  if r['old_image']!=r['new_image']:
   present=set(subprocess.check_output(['docker','image','ls','--no-trunc','--quiet'],text=True).splitlines())
   if r['old_image'] in present:
    retired=subprocess.run(['docker','image','rm',r['old_image']],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);r['old_image_retirement']=dict(returncode=retired.returncode,output=retired.stdout);assert retired.returncode==0
   else:r['old_image_retirement']=dict(returncode=0,output='Already absent in successful current image inventory')
   save()
 r['phase']='otel-check';save()
 with (HERE/'profile-launch.log').open('wb') as log:rc=subprocess.run(['taskset','-c','19','python3',str(HERE.parent/'profile_check.py'),'perf_unwind_nat','observe-maps'],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
 r['profile_controller_returncode']=rc;r['profile']=json.loads((LANE/'otel-performance-profile.json').read_text());r['controller_status']=int(rc!=0);r['phase']='finished'
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 r['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nFrozen-scalar linker sole-image refresh/check ended status '+str(r['controller_status'])+'. Read '+str(HERE/'refresh-controller.json')+' and actual image/guest/corpus/code records. Image build alone is not installed-code or performance acceptance.\n')
 print(json.dumps({k:r.get(k) for k in ['pid','phase','controller_status','new_image','profile','exception']}),flush=True)
raise SystemExit(r['controller_status'])
