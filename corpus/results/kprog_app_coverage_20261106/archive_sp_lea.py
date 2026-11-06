"""Retain the complete LEA repair and interrupted runtime setup evidence."""
import hashlib
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/sp-check-source')
rows=[json.loads(line) for line in (HERE/'sp-lea-census/programs.jsonl').read_text().splitlines()]
def source_filter(info):
    return None if any(part in {'.lake','target','build','__pycache__'} for part in Path(info.name).parts) else info
with tarfile.open(HERE/'sp-lea-artifacts.tar.gz','w:gz',dereference=True) as archive:
    archive.add(SOURCE,arcname='sp-check-source',filter=source_filter)
    paths=[HERE/'sp-lea',HERE/'raw-context',HERE/'bcc-real-8',HERE/'sp-lea-census',
        HERE/'sp-source-revision.txt',*sorted(HERE.glob('sp-lea-*.log')),
        *sorted(HERE.glob('bcc-real-8-*.log')),
        *sorted({Path(row['source']).parent for row in rows})]
    for path in paths:archive.add(path,arcname=str(path.relative_to(ROOT)))
package=HERE/'bcc-runtime-7'
hashes={str(path.relative_to(package)):hashlib.sha256(path.read_bytes()).hexdigest()
    for path in sorted(package.rglob('*')) if path.is_file()}
(HERE/'runtime-package-sha256.json').write_text(json.dumps(hashes,indent=2)+'\n')
result=subprocess.run(['docker','image','inspect','bpf-benchmark/kprog-bcc:c-20261106-7',
    'bpf-benchmark/kprog-paired-context:c-20261106'],text=True,capture_output=True,check=True)
images=json.loads(result.stdout)
metadata=[{key:entry[key] for key in ('Id','RepoTags','Architecture','Os','RootFS')} for entry in images]
(HERE/'runtime-image-identities.json').write_text(json.dumps(metadata,indent=2)+'\n')
pair=HERE/'runtime-pair-input'
pair.mkdir(exist_ok=True)
container=subprocess.run(['docker','create','bpf-benchmark/kprog-paired-context:c-20261106','/bin/true'],
    text=True,capture_output=True,check=True).stdout.strip()
try:
    for source,target in [('/artifacts/kinsn',pair),
            ('/artifacts/kernel/bzImage',pair/'bzImage'),
            ('/artifacts/manifest.json',pair/'manifest.json'),
            ('/usr/local/lib/bpfrejit/libnative_loader.so',pair/'libnative_loader.so')]:
        subprocess.run(['docker','cp',container+':'+source,str(target)],check=True)
finally:
    subprocess.run(['docker','rm',container],check=True,capture_output=True)
with tarfile.open(HERE/'runtime-install-artifacts.tar.gz','w:gz') as archive:
    paths=[package,pair,HERE/'runtime-package-sha256.json',HERE/'runtime-image-identities.json',
        HERE/'paired-modules-kvm.log',HERE/'paired-runtime-image.log',
        *sorted(HERE.glob('bcc-runtime-7-*.log'))]
    for path in paths:archive.add(path,arcname=path.name)
