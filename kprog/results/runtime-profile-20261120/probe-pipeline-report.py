"""Record the source probe pipeline correction and exact input evidence."""
import json
from pathlib import Path
import tarfile

here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/runtime-profile-20261120')
before=base/'source-generation-20261120T014314Z'
after=base/'source-generation-20261120T014607Z'
assert (after/'exit-code').read_text().strip()=='0'
old=json.loads((before/'source-generation.json').read_text())
current=json.loads((after/'source-generation.json').read_text())
assert [(r['symbol'],r['status']) for r in current]==[('user8','generated'),('compat','generated')]
report=dict(correction='942a4062f',before=str(before),after=str(after),
    before_entries=[dict(symbol=r['symbol'],status=r['status'],diagnostic=r.get('traceback','')) for r in old],
    after_entries=[dict(symbol=r['symbol'],status=r['status']) for r in current],
    host_controls=99,proof_and_kernel_links=4,
    native_wrapper='Existing after-B checked-sim-c C wrapper in compile_sim_ir.cpp/inline_probe.c',
    scope='Source provider/ABI checks, real-symbol links and production P-to-B emission. Stock acceptance, combined image and application timing remain pending.')
(here/'probe-pipeline-result.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'probe-pipeline-evidence.tar.gz','w:gz') as archive:
    for raw in [before,base/'source-generation-20261120T014505Z',after]:
        archive.add(raw,arcname=raw.name)
print([(r['symbol'],r['status']) for r in current])
