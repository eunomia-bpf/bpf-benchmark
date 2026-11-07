#!/usr/bin/env python3
"""Build and replay the current full x86 matrix through existing make targets."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,os,subprocess,time,traceback
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent;S=Path('/workspaces/.agent-state/kprog-lanes/F')
files=[p for p in (R/'kprog/x86').glob('*.h')]+list((R/'kprog/formal/generated').glob('*.h'))+list((R/'kprog/x86/micro-prog').glob('*.py'))
files+=[R/'kprog/fidelity'/n for n in ['generate.py','driver.c','driver.h','reference_check.py','Makefile']]
def pins():return {str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
def root_formal_busy():
 for p in Path('/proc').iterdir():
  if not p.name.isdigit():continue
  try:
   a=[x.decode(errors='replace') for x in (p/'cmdline').read_bytes().split(b'\0') if x];cwd=(p/'cwd').resolve()
  except (OSError,ProcessLookupError):continue
  if a and Path(a[0]).name=='make' and 'check' in a[1:] and (cwd==R/'kprog/formal' or any(x in ['kprog/formal',str(R/'kprog/formal')] for x in a[1:])):return True
 return False
state=dict(started=datetime.now(timezone.utc).isoformat(),source_head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip(),commands=[],completed=False)
def run(cmd,name):
 with (O/(name+'.log')).open('w') as log:r=subprocess.run(cmd,cwd=R,env=dict(os.environ,PATH='/root/.elan/bin:/usr/local/cargo/bin:'+os.environ['PATH']),stdout=log,stderr=subprocess.STDOUT)
 state['commands'].append(dict(command=cmd,returncode=r.returncode,log=name+'.log'));(O/'state.json').write_text(json.dumps(state,indent=2)+'\n');return r.returncode
try:
 (O/'source-pins-before.json').write_text(json.dumps(pins(),indent=2)+'\n');(S/'matrix-current.state').write_text('incremental make fidelity build\n')
 rc=run(['taskset','-c','16-19','make','-C','kprog/fidelity','build','ARCH=x86'],'build');assert rc==0,'matrix build failed'
 (O/'source-pins-after-build.json').write_text(json.dumps(pins(),indent=2)+'\n')
 (S/'matrix-current.state').write_text('waiting for root formal writer, then warm reference build\n')
 while root_formal_busy():time.sleep(10)
 rc=run(['taskset','-c','16-19','make','-C','kprog/fidelity','reference-build'],'reference-build');assert rc==0,'canonical reference build failed'
 ref=R/'kprog/formal/.lake/build/bin/reference';state['reference_sha256']=hashlib.sha256(ref.read_bytes()).hexdigest();state['binary_sha256']=hashlib.sha256((R/'kprog/fidelity/build-x86/cpu-differential').read_bytes()).hexdigest()
 (S/'matrix-current.state').write_text('real CPU and canonical reference replay running\n')
 rc=run(['taskset','-c','16-19','make','-C','kprog/fidelity','reference-check','ARCH=x86','CASES=1024','OUT='+str(O)],'replay');state['returncode']=rc
 state['reference_sha256_after']=hashlib.sha256(ref.read_bytes()).hexdigest();state['completed']=True
except Exception:
 state['error']=traceback.format_exc();state['returncode']=1
finally:
 state['finished']=datetime.now(timezone.utc).isoformat();(O/'source-pins-after.json').write_text(json.dumps(pins(),indent=2)+'\n');(O/'state.json').write_text(json.dumps(state,indent=2)+'\n');(S/'matrix-current.state').write_text('finished '+str(state['returncode'])+'; inspect per-form output and source drift\n');(S/'matrix-current.exit').write_text(str(state['returncode'])+'\n')
