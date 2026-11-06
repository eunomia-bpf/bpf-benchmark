from pathlib import Path
import gzip
import shutil
import sys
import tarfile
p=Path(sys.argv[1])
shutil.copy2(p/'.lake/build/bin/reference','reference')
with tarfile.open('canonical-source.tar.gz','w:gz') as archive:
    for name in ['KProgFormal','KProgFormal.lean','ReferenceMain.lean','lakefile.toml','lean-toolchain','lake-manifest.json','path.mk','contracts/arm64_dq_mem_spec.json','tools/generate_arm64_dq_mem_spec.py','tools/check_reference_arm64_addressed_memory.py','generated/arm64_dq_mem.h']:
        archive.add(p/name,arcname='kprog/formal/'+name)
with open('reference','rb') as src,gzip.open('reference.gz','wb') as dst:
    shutil.copyfileobj(src,dst)
