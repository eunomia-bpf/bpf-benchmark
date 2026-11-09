from pathlib import Path
import fcntl,hashlib,json,os,subprocess
R=Path('/workspaces/repository');A=Path('/workspaces/.agent-state/kprog-lanes/A')
def git(args,**kw):return subprocess.check_output(['git',*args],cwd=R,**kw)
def _publish(paths,message,label):
 if git(['branch','--show-current'],text=True).strip()!='master':raise RuntimeError('branch changed')
 subprocess.run(['git','status','--short','--branch','--',*paths],cwd=R,check=True)
 pins={p:hashlib.sha256((R/p).read_bytes()).hexdigest() for p in paths}
 P=Path('/var/tmp/kprog-tmp/A/publication');P.mkdir(parents=True,exist_ok=True)
 env=dict(os.environ,GIT_INDEX_FILE=str(P/(label+'.index')))
 msg=P/(label+'.msg');msg.write_text(message+'\n')
 while True:
  base=git(['rev-parse','HEAD'],text=True).strip()
  git(['read-tree',base],env=env);git(['add','-f','--',*paths],env=env)
  names=git(['diff','--cached','--name-only',base],env=env,text=True).splitlines()
  if set(names)-set(paths):raise RuntimeError('private scope changed '+repr(names))
  git(['diff','--cached','--check',base],env=env)
  result=subprocess.run(['git','commit','-F',str(msg),'--',*paths],cwd=R,env=env,text=True,capture_output=True)
  print(result.stdout,result.stderr,flush=True)
  if result.returncode==0:
   import re
   match=re.search(r'^\[master ([0-9a-f]+)\]',result.stdout,re.M)
   commit=git(['rev-parse',match.group(1)],text=True).strip()
   subprocess.run(['git','show','--stat','--oneline',commit],cwd=R,check=True)
   break
  if git(['rev-parse','HEAD'],text=True).strip()==base:result.check_returncode()
 changed=git(['diff-tree','--no-commit-id','--name-only','-r',commit],text=True).splitlines()
 if set(changed)-set(paths):raise RuntimeError('committed scope differs')
 for p,h in pins.items():
  if hashlib.sha256(git(['show',commit+':'+p])).hexdigest()!=h or hashlib.sha256((R/p).read_bytes()).hexdigest()!=h:raise RuntimeError('own source drift '+p)
 pushed=subprocess.run(['git','push','origin','HEAD:master'],cwd=R)
 if pushed.returncode:
  pushed=subprocess.run(['git','push','origin','HEAD:master'],cwd=R)
 remote=git(['ls-remote','origin','refs/heads/master'],text=True).split()[0]
 delivered=subprocess.run(['git','merge-base','--is-ancestor',commit,remote],cwd=R)
 if delivered.returncode:
  pushed.check_returncode()
  delivered.check_returncode()
 return dict(commit=commit,paths=paths,sha256=pins,remote_ancestor_verified=True)
def publish(paths,message,label):
 with (A/'publication.lock').open('a') as lock:
  fcntl.flock(lock,fcntl.LOCK_EX)
  return _publish(paths,message,label)
if __name__=='__main__':
 paths=['corpus/results/kprog_arm64_app_coverage_20261106/trusted_service_arm64.py','corpus/results/kprog_arm64_app_coverage_20261106/Makefile','corpus/results/kprog_arm64_app_coverage_20261107/README.md','corpus/results/kprog_arm64_app_coverage_20261107/transport-preflight.json']
 result=publish(paths,'Run all ARM corpus apps through the native-only two-start transport','six-app-transport-publication')
 (A/'six-app-transport-publication.json').write_text(json.dumps(result,indent=2)+chr(10));print(json.dumps(result,indent=2))
