from pathlib import Path
import importlib.util,json,os,subprocess,sys,traceback
G=Path(sys.argv[1]);R=Path('/workspaces/repository');OLD=Path('/workspaces/.agent-state/kprog-lanes/C/design-only/safety');OUT=G/'safety';OUT.mkdir(exist_ok=True)
spec=importlib.util.spec_from_file_location('existing_safety',OLD/'check.py');old=importlib.util.module_from_spec(spec);spec.loader.exec_module(old)
rows=json.loads((OLD/'complete/cases.json').read_text());(OUT/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
state=OUT/'requests';state.mkdir(mode=0o700,exist_ok=True)
argv=[sys.executable,str(R/'kprog/trusted_service.py'),'--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(state),'--native-link',str(G/'runtime/native-link'),'--loader',str(G/'runtime/trusted-native-loader')]
service=subprocess.Popen(argv,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);log=[];outcomes=[]
env=dict(os.environ,CLANG='/usr/lib/llvm-18/bin/clang',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1')
try:
 line=service.stdout.readline();log.append(line);print('SERVICE',line.strip(),flush=True)
 for row in rows:
  negative=row['negative'];context=OLD/'build'/('context_hash.bpf.o' if negative else 'context_array.bpf.o')
  command=[str(G/'canonical-probe'),str(context),str(OLD/'build'/(row['name']+'.native.o'))]
  if not negative:command+=['0','2']
  done=subprocess.run(command,cwd=R,env=env,text=True,capture_output=True)
  (OUT/(row['name']+'.stdout')).write_text(done.stdout);(OUT/(row['name']+'.stderr')).write_text(done.stderr)
  if done.returncode and 'trusted specializer refused native program:' not in done.stderr:
   raise RuntimeError('producer/setup failure before completion: '+row['name']+'\n'+done.stderr)
  line=service.stdout.readline();log.append(line);record=json.loads(line)
  result=dict(row,command=command,returncode=done.returncode,request=record,unsafe_native_executed=False)
  if negative:
   if record['status']==0:stage,message='accepted_finding',done.stdout+done.stderr
   else:stage,message=old.classify(record)
  else:stage,message=('valid_executed' if record['status']==0 and done.returncode==0 else 'positive_infrastructure_error'),done.stdout+done.stderr
  result.update(stage=stage,message=message);outcomes.append(result);(OUT/'outcomes.json').write_text(json.dumps(outcomes,indent=2)+'\n');print(row['name'],stage,flush=True)
finally:
 service.terminate();tail=service.communicate()[0];log.append(tail);(OUT/'service.log').write_text(''.join(log))
