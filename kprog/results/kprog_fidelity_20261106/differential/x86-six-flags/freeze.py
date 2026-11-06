"""Freeze V's canonical executable and its current source for the CPU replay."""
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile

ROOT=Path(__file__).resolve().parents[5]
build=Path(sys.argv[1])
shutil.copy2(ROOT/'kprog/formal/.lake/build/bin/reference',build/'reference')
with tarfile.open(build/'canonical-source.tar.gz','w:gz') as archive:
    for name in ['KProgFormal','KProgFormal.lean','ReferenceMain.lean','lakefile.toml','lean-toolchain','lake-manifest.json']:
        archive.add(ROOT/'kprog/formal'/name,arcname='kprog/formal/'+name)
Path('reference-provenance.txt').write_text(subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True)+
    subprocess.check_output(['git','status','--short','--','kprog/formal'],cwd=ROOT,text=True))
