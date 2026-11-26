"""Run existing affected compiler regressions, preserving all products/logs."""
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/checked-toolchain/regressions')
BASE=Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
cases=[('private','native-private-stack-20261119',['normalized']),
       ('array','checked-array-c-20261119',[str(BASE/'compile-sim-ir')]),
       ('probe','checked-probe-c-20261119',[]),('hash','hash-c-lto-20261120',[])]
def execute(case):
 name,directory,extra=case
 out=BUILD/name;out.mkdir(parents=True,exist_ok=True)
 script='check.py' if name=='hash' else 'test.py'
 command=['python3',str(ROOT/'kprog/results'/directory/script),str(out),*extra]
 r=subprocess.run(command,text=True,capture_output=True)
 (HERE/(name+'-regression.log')).write_text(r.stdout+r.stderr)
 return dict(case=name,command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr)
with ThreadPoolExecutor(max_workers=4) as pool:rows=list(pool.map(execute,cases))
with tarfile.open(HERE/'regression-products.tar.gz','w:gz') as archive:
 archive.add(BUILD,arcname='regressions')
 archive.add('/var/tmp/kprog-tmp/perf/hash-c-lto',arcname='hash-c-lto')
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 rows=rows,scope='Existing host compiler/helper/UBSan and static current-kernel link regressions. No kernel execution, stock/app acceptance or timing result.')
(HERE/'regression-result.json').write_text(json.dumps(record,indent=2)+'\n')
for row in rows:print(row['case'],row['returncode'],row['stdout'],flush=True)
if any(row['returncode'] for row in rows):raise AssertionError('existing compiler regression failed')
