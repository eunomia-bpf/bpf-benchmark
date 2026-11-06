"""Archive raw evidence, including generated files referenced outside the report."""
import json
from pathlib import Path
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
def ordinary(info):
    return None if info.type in (tarfile.FIFOTYPE,tarfile.CHRTYPE,tarfile.BLKTYPE) else info
paths=[*sorted(HERE.glob('bcc-real-[1-7]')),*sorted(HERE.glob('bcc-real-*-*.log')),
    *sorted(HERE.glob('raw-context*.log')),HERE/'raw-context',HERE/'raw-entry-host.log',
    HERE/'context-runtime',HERE/'context-runtime-kvm.log',HERE/'context-runtime-final-kvm.log',HERE/'context-runtime-shim.so',
    HERE/'context-runtime-arm64-shim.so',HERE/'entry-input',HERE/'raw-source-revision.txt']
rows=[json.loads(line) for line in (HERE/'raw-entry-census/programs.jsonl').read_text().splitlines()]
census=[HERE/'raw-entry-census',HERE/'raw-entry-census.log',*sorted({Path(row['source']).parent for row in rows})]
for name,inputs in [('raw-entry-artifacts.tar.gz',paths),('raw-entry-census-artifacts.tar.gz',census)]:
  with tarfile.open(HERE/name,'w:gz',dereference=True) as archive:
    for path in inputs:
        if not path.exists():raise FileNotFoundError(path)
        archive.add(path,arcname=str(path.relative_to(ROOT)),filter=ordinary)
