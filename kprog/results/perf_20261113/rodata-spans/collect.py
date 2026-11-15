"""Retain code-table slicing, normal B and sole-kernel acceptance receipts."""
import hashlib
import json
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-rodata-spans')
build = Path('/var/tmp/kprog-tmp/perf/helper-cfg')
for stage in ('rust', 'shared-b', 'stock-inputs', 'stock'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
    if stage in ('shared-b', 'stock-inputs'):
        for name in ('result.json', 'commands.json'):
            shutil.copyfile(raw/stage/name, destination/name)
for name in ('tetragon.json', 'shared-tables.json', 'shared-compile-command.json'):
    shutil.copyfile(build/name, out/name)
for name in ('kernel.release', 'stock.jsonl', 'original.verifier.log', 'generated.verifier.log'):
    shutil.copyfile(raw/'stock'/name, out/'stock'/name)
(out/'build-inputs.json').write_text(json.dumps({name: dict(path=str(build/name),
    sha256=hashlib.sha256((build/name).read_bytes()).hexdigest()) for name in
    ('shared.native.o', 'shared.proof.o', 'shared.bpf.o', 'shared.original.bpf.o')}, indent=2)+'\n')
