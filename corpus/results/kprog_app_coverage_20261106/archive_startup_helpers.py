"""Keep raw fixture/census files and the immutable tested source exports."""
import json
from pathlib import Path
import tarfile
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/anonymous-source')
FORMAL=Path('/workspaces/.agent-state/kprog-lanes/C/helper-check-source')

def source_filter(info):
    if any(part in {'.lake','target','build','__pycache__'} for part in Path(info.name).parts):return None
    if info.type in (tarfile.FIFOTYPE,tarfile.CHRTYPE,tarfile.BLKTYPE):return None
    return info

rows=[json.loads(line) for phase in ('readonly-census','startup-helper-census')
      for line in (HERE/phase/'programs.jsonl').read_text().splitlines()]
paths=[HERE/name for name in ['anonymous-startup-results','object-startup-results','object-startup-results-3',
       'bpf-lift','startup-lift','source-call-inputs','source-call-results','helper-micro','helper-micro-negative',
       'anonymous-manifest-host-cases','readonly-census','startup-helper-census']]
paths += sorted({Path(row['source']).parent for row in rows})
with tarfile.open(HERE/'startup-helper-artifacts.tar.gz','w:gz',dereference=True) as archive:
    for path in paths:archive.add(path,arcname=str(path.relative_to(ROOT)),filter=source_filter)
    for name in ['kprog/libnativeloader','bpfopt/shim','bpfopt/shim-before']:
        archive.add(SOURCE/name,arcname='private-startup-source/'+name,filter=source_filter)
    for name in ['kprog/formal','kprog/x86/x86_sim_local_bpf.h','kprog/x86/micro-prog/generate_micro_sim_proofs.py']:
        archive.add(FORMAL/name,arcname='helper-check-source/'+name,filter=source_filter)
