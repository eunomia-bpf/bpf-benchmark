"""One authorized default 10 s check of an app, preserving both command and outcome."""
import fcntl
import json
from pathlib import Path
import subprocess
import sys

app, target = sys.argv[1:]
out = Path(target)
out.mkdir(parents=True, exist_ok=True)
command = ['prlimit', '--as=85899345920', '--', 'make', '-C', '/workspaces/repository/kprog/perf/one-image',
           'check', 'ORDER=' + app, 'LOGS=' + str(out / 'guest')]
(out / 'check-command.json').write_text(json.dumps(command, indent=2) + '\n')
status = 1
try:
    locks = Path('/workspaces/.agent-state/kprog-lanes/locks')
    with (locks / 'timing').open('a') as timing, (locks / 'image').open('a') as image:
        fcntl.flock(timing, fcntl.LOCK_EX)
        fcntl.flock(image, fcntl.LOCK_SH)
        (out / 'check-source.txt').write_text(subprocess.check_output(
            ['git', '-C', '/workspaces/repository', 'rev-parse', 'HEAD'], text=True))
        (out / 'check-image.txt').write_text(subprocess.check_output(
            ['docker', 'image', 'inspect', '--format', '{{.Id}}', 'bpf-benchmark/kprog:current'], text=True))
        with (out / 'controller.log').open('w') as log:
            status = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT).returncode
finally:
    (out / 'controller-exit.txt').write_text(str(status) + '\n')
if status == 0:
    (out / 'completed.txt').write_text('Default app check command completed.\n')
raise SystemExit(status)
