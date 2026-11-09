from pathlib import Path
import subprocess,os
P=Path('/var/tmp/kprog-tmp/C/rep-movs-full-count');V=Path('/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/rep-movs-full-count')
subprocess.run(['mount','--bind',str(P),str(V)],check=True)
os.execvp('python3',['python3',str(V/'guest-controller.py')])
