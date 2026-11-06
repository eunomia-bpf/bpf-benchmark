"""Freeze the canonical executable and replay adapter before reading old CPU states."""
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile

ROOT = Path(__file__).resolve().parents[5]
snapshot = Path(sys.argv[1]).resolve()
snapshot.mkdir(parents=True, exist_ok=True)
for name, source in [('reference', ROOT/'kprog/formal/.lake/build/bin/reference'),
                     ('reference_check.py', ROOT/'kprog/fidelity/reference_check.py'),
                     ('cpu-differential', ROOT/'kprog/fidelity/build-arm64-sp-observer/cpu-differential'),
                     ('coverage.json', ROOT/'kprog/fidelity/build-arm64-sp-observer/coverage.json')]:
    shutil.copy2(source, snapshot/name)
for name in ['forms.tsv', 'native-code.json', 'host.txt']:
    shutil.copyfile(Path('../arm64-sp-reference')/name, Path(name))
with tarfile.open(snapshot/'canonical-source.tar.gz','w:gz') as out:
    for name in ['KProgFormal','KProgFormal.lean','ReferenceMain.lean',
                 'lakefile.toml','lean-toolchain','lake-manifest.json']:
        out.add(ROOT/'kprog/formal'/name, arcname='kprog/formal/'+name)
Path('provenance.txt').write_text(subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True)+
    subprocess.check_output(['git','log','-1','--format=%H %s','--','kprog/formal/KProgFormal/Reference/AArch64.lean','kprog/formal/ReferenceMain.lean'],cwd=ROOT,text=True)+
    f'reference executable modified_ns={ (ROOT/"kprog/formal/.lake/build/bin/reference").stat().st_mtime_ns }\n'+
    subprocess.check_output(['git','status','--short','--','kprog/formal'],cwd=ROOT,text=True)+
    'CPU trace reused read-only from ../arm64-sp-reference/cpu-states.bin\n')
