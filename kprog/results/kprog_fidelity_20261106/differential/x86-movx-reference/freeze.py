from pathlib import Path
import gzip
import shutil
import subprocess
import tarfile
ROOT=Path(__file__).resolve().parents[5]
reference=Path('/workspaces/.agent-state/kprog-lanes/F/reference-movx')
with reference.open('rb') as source,gzip.open('reference.gz','wb') as target:
    shutil.copyfileobj(source,target)
shutil.copy2(reference,'reference')
with tarfile.open('canonical-source.tar.gz','w:gz') as archive:
    for name in ['KProgFormal','ReferenceMain.lean','KProgFormal.lean','lakefile.toml','lean-toolchain','lake-manifest.json']:
        archive.add(ROOT/'kprog/formal'/name,arcname='kprog/formal/'+name)
Path('source-provenance.txt').write_text(subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True)+subprocess.check_output(['git','diff','HEAD','--','kprog/formal/KProgFormal/Reference','kprog/formal/KProgFormal/Reference/X86Path.lean','kprog/formal/ReferenceMain.lean'],cwd=ROOT,text=True))
for name in ['reference-mismatches.jsonl','reference-unavailable.jsonl']:
    with open(name,'rb') as source,gzip.open(name+'.gz','wb') as target:
        shutil.copyfileobj(source,target)
