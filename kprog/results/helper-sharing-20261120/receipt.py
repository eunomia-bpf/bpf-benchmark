"""Record helper semantics and complete reachable proof-code footprints."""
import json
from pathlib import Path
import tarfile

here=Path(__file__).resolve().parent
raw=Path('/workspaces/kprog-raw/perf/helper-sharing-20261120/subset-20261120T045153Z')
record=dict(source='307c28752',raw=str(raw),make_exit=int((raw/'exit-code').read_text()),
    lpm=json.loads((raw/'lpm/report.json').read_text()),
    hash=json.loads((raw/'hash/production-result.json').read_text()),
    replay=json.loads((raw/'replay-result.json').read_text()),
    array_cases=1008,array_generic_controls=2,probe_cases=99,probe_proof_and_kernel_links=8,
    scope='C/native helper semantics and real native API on unchanged archived accepted B frontends. Proof executable bytes include reachable workers and local helpers. Native object totals include unreferenced definitions. No application execution or speed gain inferred.')
(here/'report.json').write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(here/'evidence.tar.gz','w:gz') as archive:
    archive.add(raw,arcname=raw.name)
    archive.add('/var/tmp/kprog-tmp/perf/helper-sharing',arcname='replayed-native-program-products')
    for directory in ['array','probe']:
        archive.add(Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')/directory,arcname='compatibility-'+directory)
for row in record['replay']['rows']:
    print(row['symbol'],row['before']['proof']['executable_bytes'],row['after']['proof']['executable_bytes'])
