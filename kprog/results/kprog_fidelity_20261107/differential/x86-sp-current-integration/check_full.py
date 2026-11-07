#!/usr/bin/env python3
"""Check current SP integration incrementally; never export duplicate builds."""
from pathlib import Path
import hashlib,json,os,subprocess,time,traceback
R=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;S=Path('/workspaces/.agent-state/kprog-lanes/F');rc=1
files=['kprog/x86/x86_sim_local_bpf.h','kprog/fidelity/x86_stack.py']
files+=['kprog/formal/oracles/'+p.name for p in (R/'kprog/formal/oracles').glob('*route_host.c')]
files+=['kprog/formal/oracles/x86_no_helpers_host.h']
def pins():return {rel:hashlib.sha256((R/rel).read_bytes()).hexdigest() for rel in files}
def full_running():
 for proc in Path('/proc').iterdir():
  if not proc.name.isdigit():continue
  try:
   args=[x.decode(errors='replace') for x in (proc/'cmdline').read_bytes().split(b'\0') if x]
   cwd=(proc/'cwd').resolve()
  except (OSError,ProcessLookupError):continue
  if args and Path(args[0]).name=='make' and 'check' in args[1:]:
   if str(cwd).endswith('/kprog/formal') or any('kprog/formal' in p for p in args[1:]):return True
 return False

try:
 before=pins();(OUT/'source-pins-before.json').write_text(json.dumps(before,indent=2)+'\n')
 with (OUT/'final-routes.log').open('w') as log:
  subprocess.run(['taskset','-c','16-19','python3',str(OUT/'check_routes.py'),'--out',str(OUT/'final-routes'),'--skip-lean'],cwd=R,stdout=log,stderr=subprocess.STDOUT,check=True)
 old={x['source'] for x in json.loads((OUT/'routes.json').read_text())};new=json.loads((OUT/'final-routes/routes.json').read_text());assert old<={x['source'] for x in new};assert all(x['compile_returncode']==0 and x['run_returncode']==0 for x in new)
 (S/'sp-current-full.state').write_text('waiting for sole FULL slot; focused51routesPASS\n')
 while full_running():time.sleep(10)
 (S/'sp-current-full.state').write_text('running shared incremental make check\n')
 env=dict(os.environ,PATH='/root/.elan/bin:/usr/local/cargo/bin:'+os.environ['PATH'])
 with (OUT/'full.log').open('w') as log:rc=subprocess.run(['taskset','-c','16-19','make','-C',str(R/'kprog/formal'),'check'],cwd=R,env=env,stdout=log,stderr=subprocess.STDOUT).returncode
 after=pins();(OUT/'source-pins-after.json').write_text(json.dumps(after,indent=2)+'\n');assert before==after,'F runtime/route inputs changed during validation'
except Exception:
 traceback.print_exc();rc=1 if rc==0 else rc
finally:
 (OUT/'full.exit').write_text(str(rc)+'\n');(S/'sp-current-full.exit').write_text(str(rc)+'\n');(S/'sp-current-full.state').write_text('finished '+str(rc)+'; shared caches retained\n')
 print('FULL finished',rc,flush=True)
