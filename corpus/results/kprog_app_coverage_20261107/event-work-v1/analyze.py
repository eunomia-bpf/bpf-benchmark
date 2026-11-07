"""Raw app-owned policy submission/failure counters; no timing interpretation."""
import collections,json,struct,hashlib
from pathlib import Path
HERE=Path(__file__).resolve().parent;OUT=HERE/'actual-guest'
def raw(value):return bytes(int(v,16) if isinstance(v,str) else v for v in value)
def decode(path):
 x=json.loads(path.read_text());out={'map_counts':dict(collections.Counter(m['name'] for m in x['maps'])),'policy_actions':[0]*10,'send_failures_by_opcode_reason':{},'helper_errors':[]}
 for m in x['maps']:
  rows=x['values'][str(m['id'])]
  for row in rows:
   vals=row.get('values',[{'value':row.get('value')}])
   for value in vals:
    data=raw(value['value'])
    if m['name']=='policy_stats':
     assert len(data)==80
     out['policy_actions']=[a+b for a,b in zip(out['policy_actions'],struct.unpack('<10Q',data))]
    elif m['name']=='tg_stats_map':
     assert len(data)==256*7*8
     for i,n in enumerate(struct.unpack('<1792Q',data)):
      if n:out['send_failures_by_opcode_reason'][f'{i//7}:{i%7}']=out['send_failures_by_opcode_reason'].get(f'{i//7}:{i%7}',0)+n
    else:
     assert len(data)==4
     out['helper_errors'].append(dict(key=row['key'],cpu=value.get('cpu'),count=int.from_bytes(data,'little')))
 return out
result={}
for arm in ['jit','native']:
 before=decode(OUT/(arm+'-event-counters-before.json'));after=decode(OUT/(arm+'-event-counters-after.json'))
 keys=before['send_failures_by_opcode_reason'].keys()|after['send_failures_by_opcode_reason'].keys()
 result[arm]=dict(before=before,after=after,policy_action_deltas=[b-a for a,b in zip(before['policy_actions'],after['policy_actions'])],send_failure_deltas={k:after['send_failures_by_opcode_reason'].get(k,0)-before['send_failures_by_opcode_reason'].get(k,0) for k in sorted(keys)},work=json.loads(json.loads((OUT/(arm+'-work.json')).read_text())['stdout']))
(HERE/'summary.json').write_text(json.dumps(result,indent=2)+chr(10))
print({a:dict(policy_posts=v['policy_action_deltas'][1],failures=v['send_failure_deltas']) for a,v in result.items()})
