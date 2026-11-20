"""Retain HASH semantic checks and full native-code closure comparisons."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

here=Path(__file__).resolve().parent
raw=Path(sys.argv[1])
replay=json.loads((raw/'bcc/replay-result.json').read_text())
for row in replay['rows']:
    command=['llvm-objdump-18','-dr',row['native']['native_object']]
    (raw/'bcc'/f"request-{row['request_id']}.asm").write_bytes(
        subprocess.run(command,capture_output=True,check=True).stdout)
report=dict(source='709c1c486',raw=str(raw),
    host=json.loads((raw/'host/report.json').read_text()),
    native_api=json.loads((raw/'production/production-result.json').read_text()),
    unchanged_b_stock=json.loads((raw/'production/stock-result.json').read_text()),
    replay=replay,
    scope='Native C HASH tail-word loads, existing kernel-header/guarded-key/restart and compiler-API checks. Same archived accepted BCC frontends, full reachable proof bytes including workers. B unchanged; old stock receipt reused. No app/runtime speed claim.')
(here/'hash-tail-result.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'hash-tail-evidence.tar.gz','w:gz') as archive:
    archive.add(raw,arcname=raw.name)
    archive.add('/var/tmp/kprog-tmp/perf/hash-c-lto',arcname='hash-native-program-products')
    for row in replay['rows']:
        archive.add(Path(row['native']['native_object']).parent,
                    arcname='bcc-program-'+str(row['request_id']))
for row in replay['rows']:
    print(row['symbol'],row['before']['proof']['executable_bytes'],row['after']['proof']['executable_bytes'])
