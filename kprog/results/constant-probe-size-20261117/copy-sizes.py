#!/usr/bin/env python3
"""Read local fixed-leaf payload and recovery-site sizes from a finished host run."""
import json
from pathlib import Path
import subprocess
import sys

raw=Path(sys.argv[1])
output=Path(sys.argv[2])
reference=Path('/workspaces/kprog-raw/perf/compact-probe-globals-20261117/host-20261117T141057Z-2595751/fixture')
rows=[]
for binary in sorted((raw/'fixture').glob('*-fixed-*.bin')):
    parts=binary.stem.split('-')
    compact=parts[-1]=='compact'
    generic=reference/(parts[0]+('-compact' if compact else '')+'.bin')
    sites=(binary.with_suffix('.sites')).read_text().splitlines()
    rows.append({'domain':parts[0], 'count':int(parts[2]), 'compact':compact,
                 'generic_reference_bytes':generic.stat().st_size,
                 'fixed_bytes':binary.stat().st_size,
                 'protected_source_sites':int(sites[0]),
                 'execution_stdout':binary.with_suffix('.stdout').read_text().strip()})
output.write_text(json.dumps({
    'recorded_utc':subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
    'scope':'Local host leaf payload and static recovery-site counts; no installed app bytes or per-call timing.',
    'raw':str(raw), 'generic_reference':str(reference), 'cases':rows,
},indent=2)+'\n')
print('recorded local fixed-leaf cases:',len(rows))
