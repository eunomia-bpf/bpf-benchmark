"""Replay every captured packet rejection, keeping each command and failure."""
from concurrent.futures import ThreadPoolExecutor, as_completed
import json
from pathlib import Path
import re
import subprocess
import sys
import time

root=Path('/workspaces/repository')
sys.path[0]=str(root/'kprog/x86')
import trusted_specializer as adapter
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
inputs=Path(sys.argv[2])
requests=json.loads(inputs.read_text())['requests']
compiler='/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'

def replay(row):
    directory=out/str(row['request']);directory.mkdir(exist_ok=True)
    commands=[]
    def run(command):
        command=list(map(str,command));started=time.monotonic()
        p=subprocess.run(command,text=True,capture_output=True)
        commands.append(dict(command=command,returncode=p.returncode,
            seconds=time.monotonic()-started,stdout=p.stdout,stderr=p.stderr))
        (directory/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        p.check_returncode()
        return p.stdout
    result=dict(request=row['request'],frontend=row['frontend'])
    try:
        run([compiler,row['frontend'],'-o',directory/'bounds.bc'])
        result['predicates_lowered']=int(re.search(r'packet length predicates lowered=(\d+)',commands[-1]['stderr'])[1])
        adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang',
            directory/'replay.bpf.c',directory/'replay.bpf.o',run,compiled_input=directory/'bounds.bc')
        result.update(status=0,b_emitted=True)
    except subprocess.CalledProcessError as error:
        result.update(status=error.returncode,b_emitted=False,error=str(error))
    (directory/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    return result

results=[]
with ThreadPoolExecutor(max_workers=4) as pool:
    futures=[pool.submit(replay,row) for row in requests]
    for future in as_completed(futures):
        result=future.result();results.append(result)
        (out/'result.json').write_text(json.dumps(dict(requests=sorted(results,key=lambda r:r['request']),
            scope='Captured frontend-to-B replay only; no stock/current-app or runtime result.'),indent=2)+'\n')
        print(json.dumps(result),flush=True)
sys.exit(1 if any(row['status'] for row in results) else 0)
