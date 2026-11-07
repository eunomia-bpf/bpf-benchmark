#!/usr/bin/env python3
"""Run the13 unchanged stage2 inputs through native-only trusted specialization."""
from pathlib import Path
import argparse,hashlib,json,os,subprocess,sys,yaml
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent;PROBE=R/'kprog/formal/build/fidelity-trusted/bound-probe'
def build():
 rows=[]
 for bench in yaml.safe_load((R/'micro/config/micro_stage2.yaml').read_text())['benchmarks']:
  n=bench['name'];native=R/'kprog/test/build-x86'/(n+'.native.o');source=R/'kprog/test/build-x86'/(n+'.bpf.o')
  assert native.is_file() and source.is_file()
  manifest=O/(n+'.manifest.json');manifest.write_text(json.dumps({'objects':[dict(program=n[:15],native_object=str(native),symbol=n)]},indent=2)+'\n')
  rows.append(dict(name=n,source_bpf=str(source),source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),native_object=str(native),native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),manifest=str(manifest),expected_result=bench['expected_result'],expected_retval=bench.get('expected_retval',2)))
 assert len(rows)==13 and PROBE.is_file();(O/'inputs.json').write_text(json.dumps(dict(cases=rows,producer=str(PROBE),producer_sha256=hashlib.sha256(PROBE.read_bytes()).hexdigest()),indent=2)+'\n')
def check():
 state=O/'requests';state.mkdir(mode=0o700,exist_ok=True);assert not list(state.iterdir()),'preserve existing request evidence'
 service=subprocess.Popen([sys.executable,str(R/'kprog/trusted_service.py'),'--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(state),'--native-link',str(R/'kprog/x86/native_lab/native_link/target/release/native-link'),'--loader',str(R/'kprog/libnativeloader/build/trusted-native-loader')],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 log=[];outcomes=[];env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1')
 try:
  line=service.stdout.readline();log.append(line);assert json.loads(line)['ready']
  for row in json.loads((O/'inputs.json').read_text())['cases']:
   assert hashlib.sha256(Path(row['native_object']).read_bytes()).hexdigest()==row['native_sha256']
   assert hashlib.sha256(Path(row['source_bpf']).read_bytes()).hexdigest()==row['source_sha256']
   command=[str(PROBE),row['source_bpf'],row['manifest'],str(row['expected_result']),str(row['expected_retval'])]
   done=subprocess.run(command,cwd=R,env=env,text=True,capture_output=True);(O/(row['name']+'.stdout')).write_text(done.stdout);(O/(row['name']+'.stderr')).write_text(done.stderr)
   if done.returncode and 'trusted specializer refused native program:' not in done.stderr:raise RuntimeError('producer failure before expected completion: '+row['name']+'\n'+done.stderr)
   line=service.stdout.readline();log.append(line);record=json.loads(line);assert record['native_sha256']==row['native_sha256']
   result=dict(row,command=command,returncode=done.returncode,request=record,stage='passed' if done.returncode==0 and record['status']==0 else 'failed',stdout=done.stdout,stderr=done.stderr);outcomes.append(result);(O/'outcomes.json').write_text(json.dumps(outcomes,indent=2)+'\n');print(row['name'],result['stage'],flush=True)
  assert len(outcomes)==13 and all(r['stage']=='passed' for r in outcomes),'inspect recorded failures'
 finally:
  service.terminate();log.append(service.communicate()[0]);(O/'service.log').write_text(''.join(log))
p=argparse.ArgumentParser();p.add_argument('mode',choices=['build','check']);a=p.parse_args();(build if a.mode=='build' else check)()
