#!/usr/bin/env python3
from pathlib import Path
import os,subprocess,time
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent/'after/focused';O.mkdir(parents=True,exist_ok=True)
def full_running():
 for p in Path('/proc').iterdir():
  if not p.name.isdigit():continue
  try:
   a=[x.decode(errors='replace') for x in (p/'cmdline').read_bytes().split(b'\0') if x];cwd=(p/'cwd').resolve()
  except (OSError,ProcessLookupError):continue
  if a and Path(a[0]).name=='make' and 'check' in a[1:] and (str(cwd).endswith('/kprog/formal') or any('kprog/formal' in x for x in a[1:])):return True
 return False
while full_running():time.sleep(10)
cmd=['taskset','-c','16-19','python3',str(R/'kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/check_routes.py'),'--out',str(O),'--only','test_x86_cmpop_route_host','test_x86_cmov_route_host','cmov_step_route_host','test_x86_mov_reg_arm_route_host','test_x86_write_width_arm_route_host','test_x86_dispatch_singleton_route_host','--skip-lean']
with (O/'run.log').open('w') as log:rc=subprocess.run(cmd,cwd=R,stdout=log,stderr=subprocess.STDOUT).returncode
(Path('/workspaces/.agent-state/kprog-lanes/F')/'projection-focused.exit').write_text(str(rc)+'\n')
raise SystemExit(rc)
