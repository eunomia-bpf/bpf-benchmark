from pathlib import Path
import re,json
p=Path('positive-after');text=(p/'guest-console.log').read_text().replace('\r','')
rows=[dict(name=n,message=m,returncode=int(rc)) for n,m,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_]+)\n(.*?)LANE_F_CASE_END \1 (\d+)',text,re.S)]
(p/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
if len(rows)!=3 or 'LANE_F_SUITE_COMPLETE' not in text:raise RuntimeError('incomplete positive outcomes')
for row in rows:
 (p/(row['name']+'.log')).write_text(row['message']);print(row['name'],row['returncode'])
raise SystemExit(int(any(r['returncode'] or 'nonzero_generations=1' not in r['message'] for r in rows)))
