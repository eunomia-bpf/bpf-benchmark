#!/usr/bin/env python3
"""Retain live linkage metadata around the existing guest Make command."""
import json
import os
from pathlib import Path
import shlex
import subprocess
import sys
import time

ROOT = Path('/workspaces/repository')
SNAPSHOT = '''import hashlib,json,pathlib
root=pathlib.Path('/tmp/native_kernel_link_cache')
rows=[]
for plan in sorted(root.glob('*.link-plan.json')):
 stem=plan.name.removesuffix('.link-plan.json')
 key=stem.partition('.tmp.')[0]
 files=[]
 diagnostics={}
 for path in sorted(root.glob(key+'.*')):
  if path.is_file():
   with path.open('rb') as source: digest=hashlib.file_digest(source,'sha256').hexdigest()
   files.append(dict(name=path.name,bytes=path.stat().st_size,sha256=digest))
   if path.name.endswith('.stderr.txt'): diagnostics[path.name]=path.read_text()
 rows.append(dict(name=plan.name,cache_key=key,plan=json.loads(plan.read_text()),
  cache_template_files=files,diagnostics=diagnostics))
print(json.dumps(rows))
'''


def guest(output, command):
    output.mkdir(parents=True, exist_ok=True)
    child = subprocess.Popen(['bash', '-c', command])
    record = dict(command=command, observations=[], errors=[])
    seen = set()

    def run(argv):
        result = subprocess.run(list(map(str, argv)), capture_output=True, text=True)
        record['observations'].append(dict(command=list(map(str, argv)),
            returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
        result.check_returncode()
        return result.stdout

    try:
        while child.poll() is None and len(seen) < 2:
            progress = (output/'make.log').read_text()
            for phase in ('baseline', 'post_rejit'):
                if phase in seen or f'"event": "measurement_start", "phase": "{phase}"' not in progress:
                    continue
                seen.add(phase)
                run(['python3', ROOT/'kprog/perf/profile/jit-lines.py', output/(phase+'.jit-lines.json')])
                containers = run(['docker', 'ps', '--filter', 'ancestor=bpf-benchmark/kprog:current',
                                  '--format', '{{.ID}}']).splitlines()
                for container in containers:
                    text = run(['docker', 'exec', container, 'python3', '-c', SNAPSHOT])
                    plans = json.loads(text)
                    folder = output/(phase+'-'+container)
                    folder.mkdir()
                    for row in plans:
                        (folder/row['name']).write_text(json.dumps(row['plan'], indent=2)+'\n')
                    (folder/'metadata.json').write_text(json.dumps(plans, indent=2)+'\n')
            time.sleep(2)
    except Exception as error:
        # Observation errors are retained separately while the original suite
        # finishes. Its raw measurements and exit status remain observable.
        record['errors'].append(str(error))
    status = child.wait()
    record.update(command_returncode=status, observed_phases=sorted(seen))
    (output/'observations.json').write_text(json.dumps(record, indent=2)+'\n')
    return status if status else int(bool(record['errors']))


if __name__ == '__main__':
    mode, *args = sys.argv[1:]
    if mode == 'vng':
        output = Path(os.environ['KPROG_TIMING_CAPTURE_DIR'])
        index = args.index('--exec')+1
        original = args[index]
        (output/'original-guest-command.json').write_text(json.dumps(dict(command=original))+'\n')
        args[index] = shlex.join(['python3', str(Path(__file__).resolve()), 'guest', str(output), original])
        os.execv('/opt/virtme-ng/bin/vng', ['/opt/virtme-ng/bin/vng', *args])
    elif mode == 'guest':
        raise SystemExit(guest(Path(args[0]), args[1]))
    else:
        raise ValueError('Expected vng or guest mode')
