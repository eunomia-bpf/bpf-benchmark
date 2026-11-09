from pathlib import Path
import subprocess,os,sys
G=Path(__file__).resolve().parent;V=Path('/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/coherent-six-app-runtime');R=Path("/workspaces/repository")
subprocess.run(["mount","--bind",str(G),str(V)],check=True)
for p in sorted((G/"source").rglob("*")):
 if p.is_file():subprocess.run(["mount","--bind",str(p),str(R/p.relative_to(G/"source"))],check=True)
os.execvp(sys.argv[1],sys.argv[1:])
