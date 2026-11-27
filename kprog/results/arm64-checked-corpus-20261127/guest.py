"""The existing checked test wrapper drives frozen BCC/set in this ARM guest."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);case=out/'bcc-set';case.mkdir()
results=ROOT/'corpus/results'
def captures():
 return {p for p in results.iterdir() if p.is_dir() and (p.name.startswith('arm64_qemu_corpus_') or p.name.startswith('verified-captures-'))}
before=captures()
command=['bash',str(ROOT/'kprog/test/run_checked_otel.sh'),str(case),'bcc/set','','','arm64']
r=subprocess.run(command,text=True,capture_output=True)
(case/'stdout').write_text(r.stdout);(case/'stderr').write_text(r.stderr)
new=sorted(captures()-before)
(case/'corpus-paths.json').write_text(json.dumps([str(x) for x in new],indent=2)+'\n')
with tarfile.open(case/'corpus.tar.gz','w:gz') as archive:
 for path in new:archive.add(path,arcname=str(path.relative_to(ROOT)))
row=dict(app='bcc/set',command=command,returncode=r.returncode,corpus_paths=[str(x) for x in new])
(out/'cases.json').write_text(json.dumps([row],indent=2)+'\n');print(json.dumps(row),flush=True)
raise SystemExit(r.returncode)
