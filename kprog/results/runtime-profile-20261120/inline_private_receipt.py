"""Retain the inline binding's private-memory source and execution evidence."""
import difflib
import json
from pathlib import Path
import tarfile

root = Path('/workspaces/repository')
here = Path(__file__).resolve().parent
base = Path('/workspaces/kprog-raw/perf/runtime-profile-20261120')
before = base/'inline-private-before-20261120T035007Z'
after = base/'inline-private-after-20261120T035116Z'
rows = []
for directory in [before, after]:
    text = (directory/'inline-private.ll').read_text()
    log = (directory/'run.log').read_text()
    rows.append(dict(raw=str(directory), make_exit=int((directory/'exit-code').read_text()),
        execution=[json.loads(line) for line in log.splitlines() if line.startswith('{"tag_alias_')],
        volatile_ir_accesses=text.count(' volatile ')))
delta = list(difflib.unified_diff((before/'inline-private.ll').read_text().splitlines(),
                                (after/'inline-private.ll').read_text().splitlines(), n=0))
record = dict(before_source='87cb3101f', source='76c41e98a', runs=rows,
    private_ir_delta=[line for line in delta if line.startswith(('+', '-')) and
                      ('volatile' in line or 'store i64' in line)],
    scope='Existing host UBSan alias/tag/partial/release execution and O1 IR through actual inline bindings. Remaining raw/context accesses retain volatility. No compiler build, B stock retry, application gain or formal completion claimed.',
    app_job=dict(pid=639209, waits_for=633047,
        raw='/workspaces/kprog-raw/perf/lpm-c-lto-20261120/prefix-otel-20261120T033956Z'))
(here/'inline-private-result.json').write_text(json.dumps(record, indent=2)+'\n')
with tarfile.open(here/'inline-private-evidence.tar.gz', 'w:gz') as archive:
    for directory in [before, after]:
        archive.add(directory, arcname=directory.name)
    for path in ['kprog/x86/x86_sim_inline.h', 'kprog/x86/x86_sim_local_bpf.h',
                 'kprog/results/sparse-stack-cache-20261119/oracle.c']:
        archive.add(root/path, arcname=path)
    archive.add('/var/tmp/kprog-tmp/perf/runtime-profile-private/inline-private', arcname='native-execution')
print(json.dumps(record['runs'], indent=2))
