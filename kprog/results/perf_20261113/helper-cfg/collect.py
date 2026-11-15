"""Retain helper identity regressions and the actual-object CFG observation."""
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-helper-cfg')
for stage in ('rust', 'actual', 'actual-fixed', 'final', 'integration', 'integration-fixed'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
shutil.copyfile('/var/tmp/kprog-tmp/perf/helper-cfg/tetragon.json', out/'tetragon.json')
