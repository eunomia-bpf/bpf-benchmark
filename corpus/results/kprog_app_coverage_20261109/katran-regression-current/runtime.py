from pathlib import Path
import subprocess,json,sys,tarfile,os,shutil,select,hashlib,traceback,resource
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');D=R/'corpus/results/kprog_app_coverage_20261109/katran-regression-current';G=Path('/var/tmp/kprog-tmp/C/katran-regression-runtime');C=Path('/workspaces/.agent-state/kprog-lanes/C');V=C/'design-only/remaining-apps/katran-regression-runtime';h=sys.argv[1];OUT=D/'application'
def state(**d):(G/'status.json').write_text(json.dumps(d,indent=2)+'\n')
def run(cmd,name):
 with(G/(name+'.log')).open('w')as f:p=subprocess.run([str(x)for x in cmd],cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (G/(name+'.exit')).write_text(str(p.returncode)+'\n');return p
try:
 state(state='read_only_committed_export',source_commit=h)
 E=G/('committed-'+h[:12]);E.mkdir();reference=Path('/var/tmp/kprog-tmp/C/signed-idiv/committed-2942313a7508');files=[str(p.relative_to(reference))for p in reference.rglob('*')if p.is_file()];paths=files+[str(D.relative_to(R)/n)for n in ['Makefile','guest.py','mount.py','Dockerfile','collect.py','runtime.py']]
 p=subprocess.Popen(['git','archive',h,'--',*paths],cwd=R,stdout=subprocess.PIPE)
 with tarfile.open(fileobj=p.stdout,mode='r|')as t:t.extractall(E,filter='data')
 p.stdout.close();p.wait()
 for p in E.rglob('*'):
  if p.is_file():p.chmod(0o444)
 for p in sorted([p for p in E.rglob('*')if p.is_dir()],key=lambda p:len(p.parts),reverse=True):p.chmod(0o555)
 E.chmod(0o555);(G/'source-files.json').write_text(json.dumps(files)+'\n');(G/'export-directory').write_text(str(E)+'\n');ED=E/D.relative_to(R)
 results=G/'corpus-results';mirror=results/D.relative_to(R/'corpus/results');mirror.parent.mkdir(parents=True);mirror.symlink_to(ED,target_is_directory=True)
 shutil.copytree(Path('/var/tmp/kprog-tmp/C/coherent-six-app-runtime/runtime'),G/'runtime')
 image=G/'image';image.mkdir();shutil.copytree(Path('/var/tmp/kprog-tmp/C/katran-regression-current/producer/native/katran'),image/'native-bpf');shutil.copy2(Path('/var/tmp/kprog-tmp/C/katran-regression-current/producer/native_division.so'),image/'native_division.so');shutil.copy2(Path('/var/tmp/kprog-tmp/C/katran-regression-current/shim/libbpfrejit_shim.so'),image/'libbpfrejit_shim.so');shutil.copy2(Path('/var/tmp/kprog-tmp/C/master-x86-runtime/kernel-build/.config'),image/'config')
 state(state='building_image',source_commit=h);run(['make','-f',ED/'Makefile','image'],'image').check_returncode()
 state(state='complete_katran_with_per_program_fallback',source_commit=h)
 command=['unshare','--mount','--propagation','private','python3',ED/'mount.py','make','-f',ED/'Makefile','corpus','STATE='+str(V),'APPS=katran','CPUS=20-23','VM_CPUS=4','VM_MEM=12G','SAMPLES=1','WORKLOAD_DURATION=2'];(G/'command.json').write_text(json.dumps([str(x)for x in command],indent=2)+'\n');p=run(command,'run')
 run(['python3',ED/'collect.py',G.name],'collect').check_returncode();raw=G.parent/'collected'/G.name;OUT.mkdir(exist_ok=True)
 for q in raw.iterdir():
  if q.is_file():shutil.copy2(q,OUT/q.name)
 data=json.loads((OUT/'coverage.json').read_text());result=dict(source_commit=h,make_exit=p.returncode,**{k:data[k]for k in ['native_requests','generated','compiled','installed','failed']},app_outcomes=[dict(application=x['application'],status=x['app']['status'],error=x['app'].get('error'))for x in data['results']]);(OUT/'summary.json').write_text(json.dumps(result,indent=2)+'\n');(OUT/'README.md').write_text('# Current master selected Katran runtime\n\nThe complete rebuilt4object native producer runs with source'+h+', matching kernel/module461258 artifacts, updated failure-pass-through shim and current loader/linker. Runtime source is a read-only committed export. Original May29 framework/workload bytes retain their definitions; generated corpus directories and service requests stay in /var/tmp/kprog-tmp/C. Baseline/native work and every native fallback remain in the raw result. One2s functional sample precedes R unbound throughput timing.\n\nActual requests'+str(result['native_requests'])+'/generated'+str(result['generated'])+'/compiled'+str(result['compiled'])+'/installed'+str(result['installed'])+'/failed'+str(result['failed'])+'.\n')
 with tarfile.open(OUT/'runtime-inputs.tar.gz','w:gz')as t:
  for n in ['command.json','source-files.json','export-directory','runtime','image.log','image.exit','run.log','run.exit','collect.log','collect.exit','summary.json']:t.add(G/n,arcname=n)
 sys.path.insert(0,str(D.parent));from publish_owned import publish
 commit=publish([str(q.relative_to(R))for q in OUT.iterdir()if q.is_file()],'Measure current-master Katran with the restored complete native producer',G/'publication.json');state(state='finished',commit=commit,source_commit=h,result=result)
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/A/V '+datetime.now(timezone.utc).isoformat()+': PUSHED '+commit+' selected Katran currentmaster functional result '+repr(result)+'. Complete4objectP/current shim, original eBPF fallback per failed program, source readonly'+h+', matched runtime and raw work/counters retained. R owns unbound timing.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
