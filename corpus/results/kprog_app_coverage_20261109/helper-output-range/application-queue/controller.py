from pathlib import Path
import subprocess,os,select,json,shutil,tarfile,sys,resource,traceback
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
G=Path(__file__).resolve().parent;C=Path('/workspaces/.agent-state/kprog-lanes/C');R=Path('/workspaces/repository');I=json.loads((G/'inputs.json').read_text());V=Path(I['virtual_directory']);P=Path(I['parent_runtime']);O=R/'corpus/results/kprog_app_coverage_20261109/helper-output-range/application'
def state(**d):(G/'status.json').write_text(json.dumps(d,indent=2)+'\n')
def run(cmd,name):
 with(G/(name+'.log')).open('w')as f:p=subprocess.run(cmd,cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (G/(name+'.exit')).write_text(str(p.returncode)+'\n');return p
try:
 state(state='queued_after_matched_four_app',pid=I['queued_after_pid'])
 try:fd=os.pidfd_open(I['queued_after_pid']);select.select([fd],[],[]);os.close(fd)
 except ProcessLookupError:pass
 # Adopt only the parent's closed matching runtime artifact set.
 (G/'image/kinsn').mkdir(exist_ok=True)
 for p in(P/'image/kinsn').glob('*.ko'):shutil.copy2(p,G/'image/kinsn'/p.name)
 shutil.copy2(P/'runtime/bpf_x86_native_lab.ko',G/'runtime/bpf_x86_native_lab.ko')
 state(state='original38')
 command=['unshare','--mount','--propagation','private','python3',str(G/'mount.py'),'make','-f',str(G/'safety-control/Makefile'),'safety'];p=run(command,'original38')
 rows=json.loads((G/'safety-control/safety/outcomes.json').read_text())if(G/'safety-control/safety/outcomes.json').exists()else[];safety=dict(make_exit=p.returncode,cases=len(rows),stages={s:sum(x['stage']==s for x in rows)for s in sorted({x['stage']for x in rows})},negative_native_executions=0);(G/'original38.json').write_text(json.dumps(safety,indent=2)+'\n')
 state(state='application_image',original38=safety);run(['make','-f',str(G/'Makefile'),'image'],'image').check_returncode()
 state(state='whole_bcc',original38=safety)
 command=['make','-f',str(G/'Makefile'),'corpus','STATE='+str(V),'CPUS=20-23','VM_CPUS=4','VM_MEM=12G','APPS=bcc/set','SAMPLES=1','WORKLOAD_DURATION=2'];(G/'command.json').write_text(json.dumps(command,indent=2)+'\n');p=run(['unshare','--mount','--propagation','private','python3',str(G/'mount.py'),*command],'run')
 collector=(C/'design-only/remaining-apps/collect.py').read_text().replace("D=Path(__file__).parent;R=Path('/workspaces/repository');key=sys.argv[1];A=D/key","D=Path("+repr(str(G.parent))+");R=Path('/workspaces/repository');key=sys.argv[1];A=D/key");(G/'collect.py').write_text(collector);run([sys.executable,str(G/'collect.py'),G.name],'collect').check_returncode()
 raw=G.parent/'collected'/G.name;O.mkdir(parents=True,exist_ok=True)
 for f in raw.iterdir():
  if f.is_file():shutil.copy2(f,O/f.name)
 d=json.loads((O/'coverage.json').read_text());r=dict(inputs=I,original38=safety,make_exit=p.returncode,**{k:d[k]for k in ['native_requests','generated','compiled','installed','failed']},app_outcomes=[dict(application=x['application'],status=x['app']['status'],error=x['app'].get('error'))for x in d['results']]);(O/'summary.json').write_text(json.dumps(r,indent=2)+'\n');(O/'README.md').write_text('# Complete BCC helper-output-range representation trial\n\nThe same full eight-object canonicalO3 P producer loads through the private generic helper-output-range model and the corrected matched current-master runtime. Original38 fixture/annotation bytes and negative load-only behavior retain their published definitions. The model preserves original helper calls, native raw accesses, released-frame fault predicates and SysV clobbers; output helper writes invalidate precisely their destination-byte ghost facts and retain the existing caller-frame operation.\n\nActual outcomes '+repr({k:r[k]for k in ['original38','native_requests','generated','compiled','installed','failed','app_outcomes']})+'. Complete startup/work/service/verifier records accompany the raw archives. Canonical production simulator retains its published source during this utility trial. Frozen May29 workload/launcher bytes retained.\n')
 with tarfile.open(O/'runtime-inputs.tar.gz','w:gz')as t:
  for n in ['inputs.json','controller.py','Makefile','guest.py','mount.py','source','runtime','safety-control','original38.json','original38.log','original38.exit','image/Dockerfile','image.log','image.exit','run.log','run.exit','command.json']:t.add(G/n,arcname=n)
 sys.path.insert(0,str(C));from publish_owned import publish
 commit=publish([str(p.relative_to(R))for p in O.iterdir()if p.is_file()],'Measure complete BCC with exact helper output-range representation',G/'publication.json');state(state='finished',commit=commit,original38=safety,result={k:r[k]for k in ['native_requests','generated','compiled','installed','failed','app_outcomes']})
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/A/V '+datetime.now(timezone.utc).isoformat()+': PUSHED '+commit+' wholeBCC helper-output-range private trial '+repr({k:r[k]for k in ['original38','native_requests','generated','compiled','installed','failed','app_outcomes']})+'. Current canonical model retains published source; same nativeP/frozen benchmark and original38 retained.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
