"""Retain alias-safe C lookup grouping checks and actual native code."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

here=Path(__file__).resolve().parent
raw=Path(sys.argv[1])
before=Path('/workspaces/kprog-raw/perf/lookup-grouping-20261120/alias-before-20261120T053109Z')
replays={app:json.loads((raw/app/'replay-result.json').read_text()) for app in ['bcc','otel']}
for app,replay in replays.items():
    for row in replay['rows']:
        (raw/app/f"request-{row['request_id']}.asm").write_bytes(subprocess.run(
            ['llvm-objdump-18','-dr',row['native']['native_object']],capture_output=True,check=True).stdout)
report=dict(source='2cfb5d9fb',raw=str(raw),
    before_alias=json.loads((before/'report.json').read_text()),
    after_alias=json.loads((raw/'host/report.json').read_text()),
    hash_native_api=json.loads((raw/'production/production-result.json').read_text()),
    lpm=json.loads((raw/'lpm/report.json').read_text()),replays=replays,
    scope='Consecutive identical C lookup cases; same-physical-map aliases and first-match order retained. Kernel-header/guarded/native API checks and actual accepted BCC/OTel frontend re-emission. Full reachable proof bytes include workers. No new stock/application timing or isolated runtime gain.')
(here/'grouping-result.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'grouping-evidence.tar.gz','w:gz') as archive:
    archive.add(raw,arcname=raw.name)
    archive.add(before,arcname=before.name)
    for name in ['hash-c-lto','lpm-c-lto']:
        archive.add(Path('/var/tmp/kprog-tmp/perf')/name,arcname=name+'-program-products')
    for app,replay in replays.items():
        for row in replay['rows']:
            archive.add(Path(row['native']['native_object']).parent,
                        arcname=app+'-program-'+str(row['request_id']))
            print(row['symbol'],row['before']['proof']['executable_bytes'],row['after']['proof']['executable_bytes'])
