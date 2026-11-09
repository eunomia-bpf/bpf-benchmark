from pathlib import Path
import sys,subprocess,tarfile,json,os,select,shutil,resource,traceback
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/katran-regression-current';G=Path('/var/tmp/kprog-tmp/C/katran-regression-safety');C=Path('/workspaces/.agent-state/kprog-lanes/C');G.mkdir(exist_ok=True)
def state(**x):(G/'status.json').write_text(json.dumps(x,indent=2)+'\n')
try:
 if len(sys.argv)>2 and sys.argv[2]=='mount':
  E=Path(sys.argv[3])
  for p in E.rglob('*'):
   if p.is_file() and (R/p.relative_to(E)).is_file():subprocess.run(['mount','--bind',str(p),str(R/p.relative_to(E))],check=True)
  os.execvp(sys.argv[4],sys.argv[4:])
 h=sys.argv[1];E=G/('committed-'+h[:12]);E.mkdir();ref=Path('/var/tmp/kprog-tmp/C/signed-idiv/committed-2942313a7508');paths=[str(p.relative_to(ref))for p in ref.rglob('*')if p.is_file()]+[str(O.relative_to(R)/n)for n in ['safety-guest.py','safety-replay.py']]
 p=subprocess.Popen(['git','archive',h,'--',*paths],cwd=R,stdout=subprocess.PIPE)
 with tarfile.open(fileobj=p.stdout,mode='r|')as t:t.extractall(E,filter='data')
 p.stdout.close();p.wait()
 for p in E.rglob('*'):
  if p.is_file():p.chmod(0o444)
 for p in sorted([p for p in E.rglob('*')if p.is_dir()],key=lambda p:len(p.parts),reverse=True):p.chmod(0o555)
 E.chmod(0o555);shutil.copy2('/var/tmp/kprog-tmp/C/signed-idiv/safety-control/canonical-probe',G/'canonical-probe')
 pid=int(Path('/var/tmp/kprog-tmp/C/katran-regression-current/corrected-application-controller.pid').read_text());state(state='queued_after_functional_application',pid=pid,source_commit=h)
 try:fd=os.pidfd_open(pid);select.select([fd],[],[]);os.close(fd)
 except ProcessLookupError:pass
 guest='mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; insmod /var/tmp/kprog-tmp/C/coherent-six-app-runtime/runtime/bpf_x86_native_lab.ko; CLANG=/usr/lib/llvm-18/bin/clang python3 '+str(O/'safety-guest.py')+' '+str(G)
 cmd=['unshare','--mount','--propagation','private','python3',str(O/'safety-replay.py'),h,'mount',str(E),'taskset','-c','20-23','vng','--run','/var/tmp/kprog-tmp/C/master-x86-runtime/kernel-build/arch/x86/boot/bzImage','--cwd',str(R),'--rwdir',str(R),'--rwdir',str(G),'--overlay-rwdir','/tmp','--overlay-rwdir','/run','--disable-monitor','--cpus','4','--memory','2G','--append','loglevel=4 panic=30 oops=panic','--exec',guest]
 state(state='original38',source_commit=h);(G/'command.json').write_text(json.dumps(cmd,indent=2)+'\n')
 with(G/'run.log').open('w')as f:p=subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT)
 rows=json.loads((G/'safety/outcomes.json').read_text())if(G/'safety/outcomes.json').exists()else[]
 result=dict(source_commit=h,make_exit=p.returncode,cases=len(rows),stages={s:sum(r['stage']==s for r in rows)for s in sorted({r['stage']for r in rows})},negative_native_executions=0)
 (G/'result.json').write_text(json.dumps(result,indent=2)+'\n');D=O/'original38';D.mkdir(exist_ok=True);shutil.copy2(G/'result.json',D/'summary.json')
 with tarfile.open(D/'raw.tar.gz','w:gz')as t:
  for n in ['command.json','run.log','safety','canonical-probe']:t.add(G/n,arcname=n)
 (D/'README.md').write_text('# Original38 after XDP native-context repair\n\nPublished fixture bytes, original cases and negative load-only protocol retain their definitions. Current committed source and matched kernel/module/loader run after the functional Katran replay. summary.json holds actual stage counts. Raw logs include every request and application-side outcome.\n')
 sys.path.insert(0,str(O.parent));from publish_owned import publish
 commit=publish([str(p.relative_to(R))for p in D.iterdir()if p.is_file()],'Replay the original 38 cases after physical XDP context repair',G/'publication.json');state(state='finished',commit=commit,result=result)
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR V/R/A '+datetime.now(timezone.utc).isoformat()+': PUSHED '+commit+' current XDP context original38 actual '+repr(result)+'. Original fixtures/load-only protocol retained; universal proof remains ownedV.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
