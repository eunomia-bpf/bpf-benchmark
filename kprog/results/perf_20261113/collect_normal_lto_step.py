"""Collect small receipts; retain original archives, logs and build inputs in place."""
import hashlib
import io
import json
from pathlib import Path
import shutil
import tarfile

ROOT = Path(__file__).resolve().parents[3]
RAW = Path('/workspaces/kprog-raw/perf')
OUT = Path(__file__).resolve().parent


def copy(source, destination):
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source, destination)


def write(destination, value):
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(value, indent=2) + '\n')


def digest(path):
    with path.open('rb') as source:
        return hashlib.file_digest(source, 'sha256').hexdigest()


normal = RAW/'20261115-normal-layout-plan'
target = OUT/'normal-layout-plan'
for group in ('kernel-layout', 'maps', 'jump-tables'):
    for filename in ('result.json', 'commands.json', 'commands.jsonl'):
        source = normal/'authoritative'/group/filename
        if source.exists():
            copy(source, target/group/filename)
for group in ('authoritative', 'boot-ready'):
    for filename in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        copy(normal/group/'job'/filename, target/group/filename)
for group in ('recovery', 'boot-recovery', 'pairing'):
    copy(normal/group/'receipt.json', target/group/'receipt.json')
copy(normal/'job/make.log', target/'initial-make.log')
for filename in ('kernel.release', 'kernel-layout.json'):
    copy(normal/'boot-ready'/filename, target/'boot-ready'/filename)
write(target/'boot-ready/raw-inputs.json', {
    name: {'path': str(normal/'boot-ready'/name),
           'sha256': digest(normal/'boot-ready'/name)}
    for name in ('kernel.btf', 'kernel.kallsyms')})

otel = RAW/'20261114-otel-whole-word-checked'
target = OUT/'otel-whole-word-final'
for name in ('queue.log', 'finished', 'exit-code', 'queued.json'):
    copy(otel/name, target/name)
with tarfile.open(otel/'service.tar.gz') as archive:
    journal = archive.extractfile('service/requests/requests.jsonl').read()
    (target/'requests.jsonl').write_bytes(journal)
    nested = archive.extractfile('service/requests/5.failure.tar.gz').read()
with tarfile.open(fileobj=io.BytesIO(nested)) as archive:
    for name in ('verify.stderr', 'generation.metadata.json'):
        (target/name).write_bytes(archive.extractfile('request/'+name).read())
write(target/'archive.json', {'path': str(otel/'service.tar.gz'),
      'bytes': (otel/'service.tar.gz').stat().st_size,
      'sha256': digest(otel/'service.tar.gz')})

for raw, target in [('20261114-context-body-replay', 'context-replay-final/initial'),
                    ('20261115-context-body-replay', 'context-replay-final/current')]:
    for name in ('result.json', 'commands.jsonl'):
        source = RAW/raw/name
        if source.exists():
            copy(source, OUT/target/name)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        source = RAW/raw/'job'/name
        if source.exists():
            copy(source, OUT/target/name)

census = RAW/'20261114-census-resume/control/outcomes.jsonl'
rows = [json.loads(line) for line in census.read_text().splitlines()]
selected = [row for row in rows if 92 <= row['body_group'] <= 98]
write(OUT/'census-late-linker-pairing/rows.json', selected)
write(OUT/'census-late-linker-pairing/source.json', {
    'path': str(census), 'sha256': digest(census), 'rows_at_collection': len(rows),
    'scope': 'Retained producer, submitted-native load only; no execution or timing'})
