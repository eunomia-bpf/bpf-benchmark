from pathlib import Path
import json,subprocess,sys,shutil,tarfile,traceback,resource
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
G=Path(__file__).resolve().parent;C=Path('/workspaces/.agent-state/kprog-lanes/C');R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/bcc-native-profile-runtime';V=Path(json.loads((G/'inputs.json').read_text())['virtual_directory'])
def save(**d):(G/'status.json').write_text(json.dumps(d,indent=2)+'\n')
def notice(s):
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/A/V/S11/S15 '+datetime.now(timezone.utc).isoformat()+': '+s+'\n')
try:
 save(state='original38')
 command=['unshare','--mount','--propagation','private','python3',str(G/'mount.py'),'make','-f',str(G/'safety-control/Makefile'),'safety']
 with(G/'original38.log').open('w')as f:check=subprocess.run(command,stdout=f,stderr=subprocess.STDOUT)
 (G/'original38.exit').write_text(str(check.returncode)+'\n')
 rows=json.loads((G/'safety-control/safety/outcomes.json').read_text())if(G/'safety-control/safety/outcomes.json').exists()else[]
 safety=dict(make_exit=check.returncode,cases=len(rows),stages={s:sum(x['stage']==s for x in rows)for s in sorted({x['stage']for x in rows})},negative_native_executions=0)
 (G/'original38.json').write_text(json.dumps(safety,indent=2)+'\n')
 save(state='building_private_image',original38=safety)
 with(G/'image.log').open('w')as f:p=subprocess.run(['make','-f',str(G/'Makefile'),'image'],stdout=f,stderr=subprocess.STDOUT)
 (G/'image.exit').write_text(str(p.returncode)+'\n');p.check_returncode()
 save(state='running_complete_six_app_startup')
 notice('Current matched kernel/module with complete8object stable-config BCC producer, Katran control and corrected Tracee tail-frame linker begins actual startup on20-23. Base is R restored03cc5c15b546; framework/workload bytes retained, paired Tracee/Tetragon app artifacts recorded. One sample2s functional cohort; every actual request/verifier/startup/work stream retained. Source and command at '+str(G)+'.')
 command=['make','-f',str(G/'Makefile'),'corpus','STATE='+str(V),'CPUS=20-23','VM_CPUS=4','VM_MEM=12G','SAMPLES=1','WORKLOAD_DURATION=2']
 (G/'command.json').write_text(json.dumps(command,indent=2)+'\n')
 with(G/'run.log').open('w')as f:p=subprocess.run(['unshare','--mount','--propagation','private','python3',str(G/'mount.py'),*command],cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (G/'run.exit').write_text(str(p.returncode)+'\n')
 collector=(C/'design-only/remaining-apps/collect.py').read_text().replace("D=Path(__file__).parent;R=Path('/workspaces/repository');key=sys.argv[1];A=D/key","D=Path("+repr(str(G.parent))+");R=Path('/workspaces/repository');key=sys.argv[1];A=D/key")
 (G/'collect.py').write_text(collector)
 with(G/'collect.log').open('w')as f:q=subprocess.run([sys.executable,str(G/'collect.py'),G.name],stdout=f,stderr=subprocess.STDOUT)
 (G/'collect.exit').write_text(str(q.returncode)+'\n');q.check_returncode()
 I=G.parent/'collected'/G.name;O.mkdir(parents=True,exist_ok=True)
 for f in I.iterdir():
  if f.is_file():shutil.copy2(f,O/f.name)
 d=json.loads((O/'coverage.json').read_text());result=dict(original38=safety,inputs=json.loads((G/'inputs.json').read_text()),make_exit=p.returncode,**{k:d[k]for k in ['application','native_requests','generated','compiled','installed','failed']},app_outcomes=[dict(application=x['application'],status=x['app']['status'],error=x['app'].get('error'))for x in d['results']])
 (O/'summary.json').write_text(json.dumps(result,indent=2)+'\n');(O/'README.md').write_text('# BCC native profile, Katran and corrected Tracee tail-frame replay\n\nThis cohort pairs the matched46125883be kernel/module, current shim and first-attempt-log loader, helper-output-range model, complete8object BCC native profile37fea6858 and reaching-helper tail-frame linker7f906c429. Original38 fixture bytes retain their published definitions; raw outcomes accompany the runtime. Katran control and Tracee current paired source retain their input artifacts. The baseline image is R restored03cc5c15b546 with its frozen May29 workload/launcher. Tracee/Tetragon retain their paired application-source artifacts. Actual make'+str(p.returncode)+', requests'+str(d['native_requests'])+', generated'+str(d['generated'])+', compiled'+str(d['compiled'])+', installed'+str(d['installed'])+', failures'+str(d['failed'])+'. Every actual startup outcome and work stream is retained in coverage.json and the raw archives. One sample2s is functional coverage; R owns full restored-May29 timing.\n')
 with tarfile.open(O/'runtime-inputs.tar.gz','w:gz')as t:
  for n in ['original38.json','original38.log','original38.exit','safety-control','inputs.json','controller.py','Makefile','mount.py','guest.py','source.tar','runtime','image/Dockerfile','image.log','image.exit','command.json','run.log','run.exit','summary.json','collect.py','collect.log','collect.exit']:
   if(G/n).exists():t.add(G/n,arcname=n)
 sys.path.insert(0,str(C));from publish_owned import publish
 commit=publish([str(p.relative_to(R))for p in O.iterdir()if p.is_file()],'Measure complete BCC native profile and corrected tail-frame runtime',G/'publication.json');save(state='finished',commit=commit,original38=safety,result={k:result[k]for k in ['native_requests','generated','compiled','installed','failed']});notice('PUSHED '+commit+' native-profile complete BCC/Katran/Tracee actual startup result '+repr({k:result[k]for k in ['native_requests','generated','compiled','installed','failed']})+'. Every request/work/error retained; next simulator/front-end work follows actual error classes.')
except BaseException as e:save(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
