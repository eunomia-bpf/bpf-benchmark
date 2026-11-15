"""Retain the completed MIR experiment without copying compiler products."""
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-otel-hotspot-spills')
for stage in ('replay', 'lifetimes'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
for name in ('result.json', 'command.json', 'inputs.json', 'lowering.json',
             'request__generated__commands.jsonl', 'request__verify.stderr'):
    shutil.copyfile(raw/'replay'/name, out/'replay'/name)
shutil.copyfile(raw/'lifetimes'/'lifetimes.json', out/'lifetimes'/'lifetimes.json')
