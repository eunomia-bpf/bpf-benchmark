from pathlib import Path
import subprocess,os
P=Path('/var/tmp/kprog-tmp/C/bcc-scalar-stack-control-replay');V=Path('/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/bcc-scalar-stack-control-replay');O=V.parent/'collected'/V.name
O.mkdir(parents=True,exist_ok=True)
subprocess.run(['mount','--bind',str(P),str(V)],check=True)
subprocess.run(['mount','--bind',str(P/'collected'),str(O)],check=True)
os.execvp('/opt/virtme-ng/bin/python3',['/opt/virtme-ng/bin/python3',str(V/'controller.py')])
