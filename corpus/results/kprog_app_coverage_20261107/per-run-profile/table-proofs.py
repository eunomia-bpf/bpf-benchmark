"""Regenerate every canonical symbol proof for the two changed PIC objects."""
import json,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;RESULT=HERE.parent;CLI=Path('/workspaces/.agent-state/kprog-lanes/C/tail-frame-target/release/native-link')
OUT=HERE/'table-inputs-v2';OUT.mkdir(exist_ok=False);records=[]
for app,stem in [('katran','balancer'),('tetragon','bpf_generic_kprobe_v61')]:
 native=RESULT/'native-options-v2/tables'/app/(stem+'.native.o');target=OUT/app;target.mkdir()
 manifest=json.loads((HERE/'manifests'/(app+'.json')).read_text())
 symbols=sorted({r['symbol'] for r in manifest['objects'] if r['native_object'].endswith(stem+'.native.o')})
 for name in symbols:
  cmd=[str(CLI),'--input',str(native),'--symbol',name,'--mode','proof','--preserve-entry-abi','--output',str(target/(stem+'.'+name+'.proof.o'))]
  p=subprocess.run(cmd,capture_output=True,text=True);records.append(dict(application=app,symbol=name,command=cmd,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr));(OUT/'commands.json').write_text(json.dumps(records,indent=2)+'\n')
  if p.returncode:raise RuntimeError(f'{app} {name}: {p.stderr}')
 (target/(stem+'.native.o')).write_bytes(native.read_bytes())
 print(app,'all canonical symbols generated',flush=True)
