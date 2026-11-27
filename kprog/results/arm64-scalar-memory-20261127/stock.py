"""Guest-side paired verifier loads; empty map shapes are not live app binding."""
import json
from pathlib import Path
import subprocess
import sys
import time
ROOT=Path('/workspaces/repository');OUT=Path(sys.argv[1]);pilot='--pilot' in sys.argv
prepared=json.loads((OUT/'prepare-controller.json').read_text());RAW=Path(prepared['raw']);tool=RAW/'tools/archive-stock'
compiled=json.loads((OUT/('pilot-controller.json' if pilot else 'compile-controller.json')).read_text());assert compiled['controller_status']==0
record=dict(scope='Paired stock verifier loads on the identical ARM kernel using production relocations and fresh empty map shapes. Live application binding/native install/workload and frozen startup remain separate.',cases=[])
name='pilot-stock.json' if pilot else 'stock.json'
def save():(RAW/name).write_text(json.dumps(record,indent=2)+'\n')
prepared={r['index']:r for r in prepared['inputs']}
for item in compiled['cases']:
 row=dict(index=item['index'],app=item['app'],request=item['request'],symbol=item['symbol'],original_stock_passed=item['original_stock_passed'],loads={});case=RAW/str(item['index'])
 for phase,obj in [('before',case/item['baseline_object']),('after',case/'after.bpf.o')]:
  prefix=case/('stock-'+phase);command=[str(tool),str(obj),str(case/'generation.metadata.json'),str(case/'kernel.facts.json'),str(prefix)+'.verifier.log'];start=time.monotonic()
  r=subprocess.run(command,stdin=subprocess.DEVNULL,capture_output=True,text=True);prefix.with_suffix('.stdout').write_text(r.stdout);prefix.with_suffix('.stderr').write_text(r.stderr)
  load=dict(command=command,returncode=r.returncode,wall_seconds=time.monotonic()-start)
  try:load['result']=json.loads(r.stdout)
  except json.JSONDecodeError:load['preparation_error']=r.stderr
  row['loads'][phase]=load
 record['cases'].append(row);save();print(json.dumps(row),flush=True)
record['controller_status']=int(any(load['returncode'] not in [0,2] for row in record['cases'] for load in row['loads'].values()));save()
raise SystemExit(record['controller_status'])
