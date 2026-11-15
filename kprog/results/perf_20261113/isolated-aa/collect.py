"""Save the running control's protocol, without inventing a completed result."""
from pathlib import Path
import shutil

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-isolated-aa')
for source, name in [(raw/'protocol.json', 'protocol.json'), (raw/'dry-run.txt', 'dry-run.txt'),
                     (raw/'job/make-command.txt', 'make-command.txt'), (raw/'job/started', 'started')]:
    shutil.copyfile(source, out/name)
