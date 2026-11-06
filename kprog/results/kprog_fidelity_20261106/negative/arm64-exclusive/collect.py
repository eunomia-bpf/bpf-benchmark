"""Preserve expected positive controls and every unsafe acceptance separately."""
import json
from pathlib import Path
import re
import sys

ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
from negative import bound_outcome
base,out=map(Path,sys.argv[1:])
rows=json.loads((base/'full-suite/build.json').read_text())['cases']
text=(out/'guest-console.log').read_text().replace('\r','')
observed={n:(m,int(rc)) for n,m,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_]+)\n(.*?)LANE_F_CASE_END \1 (\d+)',text,re.S)}
if 'LANE_F_SUITE_COMPLETE' not in text:raise RuntimeError('guest suite incomplete')
for row in rows:
    if row['stage']=='generated':
        message,rc=observed.pop(row['name'])
        (out/(row['name']+'.log')).write_text(message)
        row.update(message=message,returncode=rc,stage=bound_outcome(message,rc))
    row['positive_control']=row['name'].endswith('_control')
if observed:raise RuntimeError('unexpected guest cases')
(out/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
for row in rows:
    print(row['name'],row['stage'],row['message'].splitlines()[0] if row['message'] else '')
    if row['positive_control']:
        if row['stage']!='accepted_finding' or 'nonzero_generations=1' not in row['message']:raise RuntimeError('positive exclusive program rejected')
    elif row['stage']=='infrastructure_error':raise RuntimeError('infrastructure error is not safety evidence')
    elif out.name=='after' and row['stage']=='accepted_finding':raise RuntimeError('unsafe exclusive program accepted')
