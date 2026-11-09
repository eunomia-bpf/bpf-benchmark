from pathlib import Path
import sys,json,subprocess,tarfile,hashlib,os,resource,traceback
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');G=Path('/var/tmp/kprog-tmp/C/generated-micro-source-refresh');O=R/'corpus/results/kprog_app_coverage_20261109/generated-micro-source-refresh';G.mkdir(exist_ok=True);h=sys.argv[1]
def state(**d):(G/'status.json').write_text(json.dumps(d,indent=2)+'\n')
try:
 files=json.loads((O/'sources.json').read_text());E=G/'committed-source';E.mkdir()
 paths=files+['kprog/x86/x86_sim.h','kprog/x86/x86_sim_local_bpf.h','kprog/formal/generated','kinsn/module/include/native_lab_input.h']
 p=subprocess.Popen(['git','archive',h,'--',*paths],cwd=R,stdout=subprocess.PIPE)
 with tarfile.open(fileobj=p.stdout,mode='r|')as t:t.extractall(E,filter='data')
 p.stdout.close();p.wait()
 for p in E.rglob('*'):
  if p.is_file():p.chmod(0o444)
 for p in sorted([p for p in E.rglob('*')if p.is_dir()],key=lambda p:len(p.parts),reverse=True):p.chmod(0o555)
 E.chmod(0o555);rows=[];(G/'objects').mkdir()
 state(state='compiling',source_commit=h,total=len(files))
 for n in files:
  src=E/n;obj=G/'objects'/(src.stem+'.o');cmd=['clang-18','-g','-O2','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(R/'vendor/libbpf/include/uapi'),'-I'+str(R/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(src),'-o',str(obj)]
  with(G/'objects'/(src.stem+'.log')).open('w')as f:q=subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT)
  row=dict(source=n,source_sha256=hashlib.sha256(src.read_bytes()).hexdigest(),command=cmd,exit=q.returncode)
  if obj.exists():row['object_sha256']=hashlib.sha256(obj.read_bytes()).hexdigest()
  rows.append(row);(G/'compiled.json').write_text(json.dumps(rows,indent=2)+'\n');print(n,q.returncode,flush=True)
 result=dict(source_commit=h,entries=len(rows),compiled=sum(x['exit']==0 for x in rows),rows=rows);(O/'compiled.json').write_text(json.dumps(result,indent=2)+'\n')
 with tarfile.open(O/'raw.tar.gz','w:gz')as t:
  for n in ['committed-source','objects','compiled.json']:t.add(G/n,arcname=n)
 sys.path.insert(0,str(O.parent));from publish_owned import publish
 commit=publish([str((O/n).relative_to(R))for n in ['compiled.json','raw.tar.gz']],'Record complete generated x86 simulator source compilation',G/'publication.json');state(state='finished',commit=commit,source_commit=h,entries=len(rows),compiled=result['compiled'])
 with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR S19/V/R '+datetime.now(timezone.utc).isoformat()+': PUSHED '+commit+' generated source refresh compiler receipt, read-only Git'+h+' exact43sources, compiled'+str(result['compiled'])+'/'+str(len(rows))+'. Original workloads/fixtures retained; source/backlog publication uses master and git commit -F -- exact paths.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
