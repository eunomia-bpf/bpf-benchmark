"""Retain per-CPU ARRAY component checks and actual program-code growth."""
import json
from pathlib import Path
import sys
import tarfile

here=Path(__file__).resolve().parent;raw=Path(sys.argv[1])
replay=json.loads((raw/'replay/replay-result.json').read_text())
report=dict(source='0a0f4bbfd',raw=str(raw),host=json.loads((raw/'host/report.json').read_text()),
    replay=replay,
    scope='Static type6 native C lookup through unchanged installed ABI. Host CPU translation is a stub, not a kernel-helper execution test. Actual accepted OTel frontends re-emit through native API/proof stage; full reachable bytes include workers. B unchanged; native code grows. Kernel linking/execution, application behavior and performance remain to be measured with all LTO enabled.')
(here/'report.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'evidence.tar.gz','w:gz') as archive:
    archive.add(raw,arcname=raw.name)
    archive.add('/var/tmp/kprog-tmp/perf/percpu-array-c',arcname='native-component-program-products')
    for row in replay['rows']:
        archive.add(Path(row['native']['native_object']).parent,arcname='otel-program-'+str(row['request_id']))
        print(row['symbol'],row['before']['proof']['executable_bytes'],row['after']['proof']['executable_bytes'])
