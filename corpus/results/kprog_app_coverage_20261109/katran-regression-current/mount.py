from pathlib import Path
import subprocess,sys,os,json
G=Path('/var/tmp/kprog-tmp/C/katran-regression-runtime');R=Path('/workspaces/repository');V=Path('/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-regression-runtime');E=Path((G/'export-directory').read_text().strip())
subprocess.run(['mount','--bind',str(G),str(V)],check=True)
subprocess.run(['mount','--bind',str(G/'corpus-results'),str(R/'corpus/results')],check=True)
for name in json.loads((G/'source-files.json').read_text()):
 if name.startswith('corpus/results/'):continue
 subprocess.run(['mount','--bind',str(E/name),str(R/name)],check=True)
os.execvp(sys.argv[1],sys.argv[1:])
