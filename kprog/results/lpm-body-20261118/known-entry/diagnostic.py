#!/usr/bin/env python3
"""Compare the retained native body with a host jump past known-shape guards."""
import csv
import json
from pathlib import Path
from statistics import median
import struct
import subprocess
import sys

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T013414Z-2855681')
driver=Path('/workspaces/kprog-raw/perf/lpm-body-20261118/host-20261118T011625Z-2846223/driver')
facts=json.loads((source/'extraction.json').read_text())
original=(source/'native-host.bin').read_bytes()
# This captured layout uses key_prefixlen=0, encoded by the current emitter.
assert facts['layout']['key_prefixlen']==0
instruction=bytes.fromhex('448b5600')
entry=original.index(instruction)
assert original.count(instruction)==1
code=bytearray(original)
code[:5]=b'\xe9'+struct.pack('<i',entry-5)
(out/'known-host.bin').write_bytes(code)
metadata=dict(source=str(source),body_bytes=facts['native_range_bytes'],layout=facts['layout'],
              known_entry=entry,patch=dict(offset=0,original=original[:5].hex(),replacement=code[:5].hex()),
              invocation=[str(driver),str(source/'native-host.bin'),str(out/'known-host.bin')],
              driver_arm_labels=dict(kernel='guarded-native',native='known-entry'),
              scope='Host entry-JMP diagnostic on the same existing native body and driver. '
                    'Stable LPM12 fixtures; query bound/child/fallback code remains. '
                    'The extra entry jump contributes cost; production routing and app effects remain separate.')
(out/'input.json').write_text(json.dumps(metadata,indent=2)+'\n')
with (out/'samples.csv').open('w') as stdout,(out/'stderr').open('w') as stderr:
    status=subprocess.run(metadata['invocation'],stdout=stdout,stderr=stderr).returncode
(out/'driver-exit-code').write_text(str(status)+'\n')
if status:sys.exit(status)
checks=[];series={}
for row in csv.reader((out/'samples.csv').open()):
    if row[0]=='check':checks.append(row)
    else:
        _,case,sample,arm,calls,elapsed,result_sum=row
        series.setdefault(case,{}).setdefault(metadata['driver_arm_labels'][arm],[]).append(dict(
            sample=int(sample),calls=int(calls),elapsed_ns=int(elapsed),ns_per_call=int(elapsed)/int(calls),
            return_sum=int(result_sum)))
for case in series.values():
    case['median_guarded_over_known']=median(s['ns_per_call'] for s in case['guarded-native'])/median(
        s['ns_per_call'] for s in case['known-entry'])
(out/'summary.json').write_text(json.dumps(dict(input=metadata,checks=checks,series=series),indent=2)+'\n')
for name,case in series.items():
    print(name,'guarded',[round(s['ns_per_call'],3) for s in case['guarded-native']],
          'known entry',[round(s['ns_per_call'],3) for s in case['known-entry']],
          'median guarded/known',round(case['median_guarded_over_known'],4))
