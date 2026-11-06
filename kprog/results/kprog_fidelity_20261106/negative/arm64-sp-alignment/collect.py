from pathlib import Path
import json,re
text=Path('guest-console.log').read_text().replace('\r','')
rows=[]
for name,message,rc in re.findall(r'LANE_F_CASE_BEGIN ([a-z_]+)\n(.*?)LANE_F_CASE_END \1 (\d+)',text,re.S):
 Path(name+'.log').write_text(message)
 rows.append(dict(name=name,returncode=int(rc),message=message,expected='reject' if name=='misaligned_sp' else 'accept'))
Path('outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
if len(rows)!=2 or 'LANE_F_SUITE_COMPLETE' not in text:raise RuntimeError('incomplete guest outcomes')
for row in rows:print(row['name'],row['returncode'],row['expected'])
raise SystemExit(int(any((r['returncode']==0)!=(r['expected']=='accept') for r in rows)))
