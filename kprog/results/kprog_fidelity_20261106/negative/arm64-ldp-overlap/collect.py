"""Retain every bound load-only outcome, including unsafe acceptances."""
import json
from pathlib import Path
import re
import sys

build, out = map(Path, sys.argv[1:])
rows = json.loads((build/'build.json').read_text())
text = (out/'guest-console.log').read_text().replace('\r','')
observed = {n:(m,int(rc)) for n,m,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_]+)\n(.*?)LANE_F_CASE_END \1 (\d+)',text,re.S)}
if 'LANE_F_SUITE_COMPLETE' not in text:
    raise RuntimeError('guest suite incomplete')
for row in rows:
    if row['stage']=='generated':
        message, rc = observed.pop(row['name'])
        (out/(row['name']+'.log')).write_text(message)
        row.update(returncode=rc,message=message,stage='bound_load_accepted' if rc==0 else 'load_error')
if observed:
    raise RuntimeError(f'unexpected guest cases: {list(observed)}')
(out/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
for row in rows:
    print(row['name'],row['stage'],row['message'].strip())
if out.name=='before':
    if not all(r['stage']=='bound_load_accepted' and 'nonzero_generations=1' in r['message'] for r in rows):
        raise RuntimeError('before-repair outcomes did not reach all expected bound loads')
else:
    for row in rows:
        if row['name']=='ldp_distinct_control':
            if row['stage']!='bound_load_accepted' or 'nonzero_generations=1' not in row['message']:
                raise RuntimeError('valid distinct-destination LDP stopped binding')
        elif row['stage']!='specialization_rejected' or 'constrained-unpredictable native LDP destination overlap' not in row['message']:
            raise RuntimeError(f'unsafe LDP not rejected: {row}')
