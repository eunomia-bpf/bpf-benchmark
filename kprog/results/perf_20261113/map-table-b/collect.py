"""Retain bounded source/host receipts; compiled products stay in their one build."""
import hashlib
import json
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-map-table-b')
build = Path('/var/tmp/kprog-tmp/perf/map-pointer-tables')


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


for stage in ('liveness', 'host', 'host-fixed', 'final', 'relative-final'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
    if stage in ('liveness', 'relative-final'):
        for name in ('result.json', 'commands.json'):
            shutil.copyfile(raw/stage/'jump-tables'/name, destination/name)
    elif stage == 'final':
        for name in ('result.json', 'commands.json'):
            shutil.copyfile(raw/stage/'map-table-b'/name, destination/name)
(out/'build-inputs.json').write_text(json.dumps({name: dict(path=str(build/name), sha256=digest(build/name))
    for name in ('fixture.native.o', 'fixture.proof.o', 'fixture.kernel.bin', 'fixture.map-patches.tsv')}, indent=2)+'\n')
