"""One authorized default 10 s check of an app, preserving both command and outcome."""
import json
from pathlib import Path
import subprocess
import sys

app, target = sys.argv[1:]
out = Path(target)
out.mkdir(parents=True, exist_ok=True)
command = ['flock', '-x', '/workspaces/.agent-state/kprog-lanes/locks/timing',
           'flock', '-s', '/workspaces/.agent-state/kprog-lanes/locks/image',
           'prlimit', '--as=85899345920', '--', 'make', '-C', '/workspaces/repository/kprog/perf/one-image',
           'check', 'ORDER=' + app, 'LOGS=' + str(out / 'guest')]
(out / 'check-command.json').write_text(json.dumps(command, indent=2) + '\n')
with (out / 'controller.log').open('w') as log:
    result = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
(out / 'controller-exit.txt').write_text(str(result.returncode) + '\n')
if result.returncode == 0:
    (out / 'completed.txt').write_text('Default app check command completed.\n')
raise SystemExit(result.returncode)
