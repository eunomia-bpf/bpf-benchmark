"""Lane C result publication through path-scoped commits on shared master."""
from pathlib import Path
import json,os,re,subprocess,tempfile
R=Path('/workspaces/repository')
def publish(paths,message,receipt):
 paths=sorted(paths);base=Path('/var/tmp/kprog-tmp/C');base.mkdir(parents=True,exist_ok=True)
 fd,name=tempfile.mkstemp(prefix='publication-',suffix='.message',dir=base);os.close(fd)
 msg=Path(name);idx=msg.with_suffix('.index');msg.write_text(message.rstrip()+'\n')
 env=dict(os.environ,GIT_INDEX_FILE=str(idx))
 def run(args,**kw):return subprocess.run(['git',*args],cwd=R,env=env,check=True,**kw)
 try:
  run(['read-tree','HEAD']);run(['add','--',*paths])
  done=run(['-c','core.abbrev=40','commit','-F',str(msg),'--',*paths],capture_output=True,text=True);print(done.stdout,flush=True)
  commit=re.search(r'^\[[^\]]+ ([0-9a-f]{40})\]',done.stdout,re.M)[1]
  show=run(['show','--stat','--oneline',commit],capture_output=True,text=True);print(show.stdout,flush=True)
  run(['push','origin','master'])
  remote=run(['ls-remote','origin','refs/heads/master'],capture_output=True,text=True).stdout.split()[0]
  tree=run(['ls-tree',commit,'--',*paths],capture_output=True,text=True).stdout.splitlines()
  blobs={line.split('\t',1)[1]:line.split('\t',1)[0].split()[2]for line in tree}
  Path(receipt).write_text(json.dumps(dict(commit=commit,remote=remote,paths=paths,blobs=blobs),indent=2)+'\n')
  print('PUSHED',commit,'EXACT_OWN_PATHS',len(paths),flush=True);return commit
 finally:
  msg.unlink(missing_ok=True);idx.unlink(missing_ok=True)
