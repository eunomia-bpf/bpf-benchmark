"""Retain failed and corrected runtime-cache integration receipts."""
import hashlib
import json
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-lto-symbol-cache')
prior = Path('/workspaces/kprog-raw/perf/20261115-normal-layout-plan')


def copy(source, target):
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source, target)


for stage in ('syntax', 'publication', 'kernel-probe', 'kernel-maps', 'kernel-array', 'kernel-table', 'kernel-map-table'):
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        copy(raw/stage/'job'/name, out/stage/name)
for name in ('source-head.txt', 'tool-sha256.txt', 'published'):
    copy(raw/'publication'/name, out/'publication'/name)
    copy(prior/'publication'/name, out/'first-publication'/name)
archives = []
for stage in ('kernel-probe', 'kernel-maps', 'kernel-array'):
    for path in (raw/stage).rglob('*'):
        if not path.is_file(): continue
        if path.name in ('execution.jsonl', 'service.log', 'runtime-manifest.json', 'kernel.release', 'guest-input-sha256', 'input-sha256'):
            copy(path, out/stage/path.relative_to(raw/stage))
        if path.name == 'service.tar.gz':
            with path.open('rb') as stream: digest = hashlib.file_digest(stream, 'sha256').hexdigest()
            archives.append(dict(path=str(path), bytes=path.stat().st_size, sha256=digest))
for current, previous in [('kernel-table', Path('/workspaces/kprog-raw/perf/20261115-checked-codegen/kernel')),
                          ('kernel-map-table', Path('/workspaces/kprog-raw/perf/20261115-map-table-lookup/kernel'))]:
    for label, source in [('first-failure', previous), ('corrected', raw/current)]:
        for name in ('result.json', 'command.json', 'load-command.json', 'verify.stderr', 'load.stderr'):
            copy(source/'replay'/name, out/current/label/name)
stop = Path('/workspaces/kprog-raw/perf/20261115-stop-old-routes')
for name in ('stop.json', 'stop-scale-tree.json'):
    copy(stop/name, out/'stopped-old-routes'/name)
(out/'archives.json').write_text(json.dumps(archives, indent=2)+'\n')
