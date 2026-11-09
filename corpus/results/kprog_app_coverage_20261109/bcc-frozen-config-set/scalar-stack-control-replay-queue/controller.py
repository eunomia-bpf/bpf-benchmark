from pathlib import Path
from datetime import datetime,timezone
import subprocess,sys,json,os,select,hashlib,tarfile,shutil,traceback
G=Path(__file__).resolve().parent;C=Path('/workspaces/.agent-state/kprog-lanes/C');R=Path('/workspaces/repository');D=G.parent;Q=Path('/var/tmp/kprog-tmp/C/bcc-frozen-config-scalar-stack-application');QV=D/Q.name;O=R/'corpus/results/kprog_app_coverage_20261109/bcc-frozen-config-set/scalar-stack-control-replay'
def save(state,**kw):(G/'status.json').write_text(json.dumps(dict(state=state,**kw),indent=2)+'\n')
def notice(t):
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/V/A/S7/S9 '+datetime.now(timezone.utc).isoformat()+': '+t+'\n')
try:
 save('queued_after_complete_bcc_frontend_application')
 try:
  fd=os.pidfd_open(int((Q/'controller.pid').read_text()));select.select([fd],[],[]);os.close(fd)
 except ProcessLookupError:pass
 for proc in Path('/proc').iterdir():
  if proc.name.isdigit():
   try:cmd=(proc/'cmdline').read_bytes().split(b'\0')
   except(FileNotFoundError,ProcessLookupError):continue
   if cmd and cmd[0].endswith(b'qemu-system-x86_64')and any(('path='+str(QV)+',').encode()in arg for arg in cmd):
    try:fd=os.pidfd_open(int(proc.name));select.select([fd],[],[]);os.close(fd)
    except ProcessLookupError:pass
 safety=json.loads((Q/'original38.json').read_text())
 for n in ['original38.json','original38.log','original38.exit']:shutil.copy2(Q/n,G/n)
 inputs=json.loads((G/'inputs.json').read_text());O.mkdir(parents=True,exist_ok=True);arms=[]
 for label in ['control']:
  A=G/(label+'-runtime');AO=O/label;AO.mkdir(exist_ok=True)
  save('application_'+label,original38=safety)
  base=inputs['canonical_base_image'];subprocess.run(['docker','tag',base,'bpf-benchmark/kprog-five-step-tracee:c-runner'],check=True)
  (A/'image/Dockerfile').write_text('FROM bpf-benchmark/kprog-five-step-tracee:c-runner\nCOPY bcc/ /artifacts/user/native-bpf/x86_64/bcc/\n')
  with(A/'image.log').open('w')as f:p=subprocess.run(['make','-f',str(A/'Makefile'),'image'],cwd=R,stdout=f,stderr=subprocess.STDOUT)
  (A/'image.exit').write_text(str(p.returncode)+'\n');p.check_returncode()
  image=subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog-five-step-tracee:c-runner'],text=True).strip()
  command=['make','-f',str(A/'Makefile'),'corpus','STATE='+str(A),'CPUS=20-23','VM_CPUS=8','VM_MEM=12G','APPS=bcc/set','SAMPLES=1','WORKLOAD_DURATION=2'];(A/'command.json').write_text(json.dumps(command,indent=2)+'\n')
  notice('Starting full BCC '+label+' complete frozen-config producer through captured published model '+inputs['source_head']+' and canonical SMAP runtime; original38 '+repr(safety)+'. Functional work retains the captured compatibility recipe. R owns frozen05-29 timing. Runtime admission additions0.')
  with(A/'run.log').open('w')as f:p=subprocess.run(['unshare','--mount','--propagation','private','python3',str(A/'mount.py'),*command],cwd=R,stdout=f,stderr=subprocess.STDOUT)
  (A/'run.exit').write_text(str(p.returncode)+'\n')
  key=str(A.relative_to(D))
  with(A/'collect.log').open('w')as f:q=subprocess.run([sys.executable,str(D/'collect.py'),key],cwd=R,stdout=f,stderr=subprocess.STDOUT)
  (A/'collect.exit').write_text(str(q.returncode)+'\n');q.check_returncode();I=D/'collected'/key
  for f in I.iterdir():
   if f.is_file():shutil.copy2(f,AO/f.name)
  coverage=json.loads((I/'coverage.json').read_text());work=[dict(application=x['application'],status=x['app']['status'],error=x['app'].get('error'),baseline=x['app'].get('baseline'),post_rejit=x['app'].get('post_rejit'))for x in coverage['results']]
  arm=dict(label=label,make_exit=p.returncode,image=image,**{k:coverage[k]for k in ['native_requests','generated','compiled','installed','failed']},work=work);arms.append(arm);(AO/'summary.json').write_text(json.dumps(arm,indent=2)+'\n')
 result=dict(inputs=inputs,original38=safety,arms=arms);(O/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
 (O/'README.md').write_text('# Corrected full BCC canonical control replay\n\nThe original eight-tool BCC set loads with archived canonical O3 control and frontend-frozen-config native payloads. Every application program retains selection through its full native manifest. Both arms use the published model snapshot '+inputs['source_head']+' and retained canonical SMAP image. Original38 outcome '+repr(safety)+'. Actual arm outcomes '+repr([{k:x[k]for k in ['label','make_exit','native_requests','generated','compiled','installed','failed']}for x in arms])+'.\n\nThe frozen May29 CLI binds34 stable fields across seven tools; capable.my_pid stays live and vfsstat retains ordinary codegen. The candidate uses target SMAP kernel BTF; control ELF bytes are the actual canonical kernel-copied P. The candidate binds these values at native frontend before the existing defined-constant division pass/O3. Original C/JIT and kernel copied-P emission retain their definitions. Functional replay uses the captured compatibility workload with one sample and two-second windows. R owns the restored05-29 throughput measurement. Source/model/runtime identities, original38 annotations, actual generated C/B, verifier logs and per-phase work accompany the archives. Runtime admission additions0.\n')
 with tarfile.open(O/'runtime.tar.gz','w:gz')as tar:
  for n in ['controller.py','enter.py','inputs.json','source','original38.json','original38.log','original38.exit']:tar.add(G/n,arcname=n)
  for label in ['control']:
   A=G/(label+'-runtime')
   for n in ['Makefile','guest.py','clang','mount.py','image','image.log','image.exit','command.json','run.log','run.exit','collect.log','collect.exit','summary.json']:tar.add(A/n,arcname=label+'/'+n)
 sys.path.insert(0,str(C));from publish_owned import publish
 commit=publish([str(p.relative_to(R))for p in O.rglob('*')if p.is_file()],'Record corrected BCC canonical control with executable compiler wrapper',G/'publication.json');save('finished',commit=commit,arms=[{k:x[k]for k in ['label','make_exit','native_requests','generated','compiled','installed','failed']}for x in arms]);notice('PUSHED '+commit+' paired full BCC complete frozen-config replay '+repr([{k:x[k]for k in ['label','make_exit','native_requests','generated','compiled','installed','failed']}for x in arms])+'; exact source epoch/original38/actual work retained.')
except BaseException as e:save('requires_continuation',error=str(e),traceback=traceback.format_exc());raise
