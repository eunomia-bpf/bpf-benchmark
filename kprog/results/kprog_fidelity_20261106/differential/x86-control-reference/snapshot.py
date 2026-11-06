from pathlib import Path
import gzip
import shutil
import sys
import tarfile
p=Path(sys.argv[1])
shutil.copy2(p/'.lake/build/bin/reference','reference')
for name in ['forms.tsv','native-code.json','host.txt']:
    shutil.copy2(Path('../x86-full-conditions')/name,name)
with tarfile.open('canonical-source.tar.gz','w:gz') as archive:
    for name in ['KProgFormal','KProgFormal.lean','ReferenceMain.lean','lakefile.toml','lean-toolchain','lake-manifest.json','path.mk','PrintPath.lean','tools/check_reference_x86_path.py']:
        archive.add(p/name,arcname='kprog/formal/'+name)
with open('reference','rb') as src,gzip.open('reference.gz','wb') as dst:
    shutil.copyfileobj(src,dst)
