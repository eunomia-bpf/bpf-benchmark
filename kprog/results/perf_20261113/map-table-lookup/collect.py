"""Copy bounded lookup-consumer evidence, leaving one canonical compiled build."""
import hashlib
import json
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-map-table-lookup')
build = Path('/var/tmp/kprog-tmp/perf/map-table-lookup')
for stage in ('proof', 'proof-fixed', 'compile'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
for name in ('commands.json', 'result.json', 'native.disassembly', 'native.relocations',
             'proof.disassembly', 'proof.relocations'):
    shutil.copyfile(raw/'compile'/name, out/'compile'/name)
for name in ('compile-command.json', 'proof-result.json', 'lookup.map-patches.tsv', 'lookup.helper-slots.json'):
    shutil.copyfile(build/name, out/name)
(out/'build-inputs.json').write_text(json.dumps({name: dict(path=str(build/name),
    sha256=hashlib.sha256((build/name).read_bytes()).hexdigest()) for name in
    ('lookup.native.o', 'trusted_x86.proof.o', 'lookup.kernel.bin', 'original.bpf.o',
     'trusted_x86.bpf.o', 'trusted_x86.bpf.i', 'trusted_x86.bpf.bounds-input.bc')}, indent=2)+'\n')
shutil.copyfile(raw/'kernel'/'dry-run.txt', out/'kernel-dry-run.txt')
