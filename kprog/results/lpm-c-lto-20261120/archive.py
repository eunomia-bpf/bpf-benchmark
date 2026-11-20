"""Preserve the completed source/helper checks and their earlier diagnostics."""
import json
from pathlib import Path
import tarfile

here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120')
raw=base/'host-20261120T013826Z'
assert (raw/'exit-code').read_text().strip()=='0'
report=json.loads((raw/'report.json').read_text())
report.update(raw=str(raw),completed=(raw/'finished').read_text().strip(),
    candidate='277e16633 through 10c04de6a',
    array=json.loads((raw/'array/report.json').read_text()),
    lpm_oracle_cases=sum(row['cases'] for row in report['cases']),
    otel_lpm_sites=int((raw/'array/otel-typed.log').read_text().split('typed LPM lookups lowered: ')[1].splitlines()[0]),
    loader_syntax_exit=0,compiler_build_exit=0,
    scope='Host C and imported machine-code semantics, existing ARRAY compatibility, real captured OTel emission and proof/kernel linking. Combined-image acceptance and application speed remain pending.')
(here/'report.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'evidence.tar.gz','w:gz') as archive:
    archive.add(base,arcname='raw')
    archive.add('/var/tmp/kprog-tmp/perf/lpm-c-lto',arcname='host-generated')
print(report['lpm_oracle_cases'],report['otel_lpm_sites'])
