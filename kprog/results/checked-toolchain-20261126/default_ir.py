"""Compare default x86 lowering of existing memory and helper regressions."""
import gzip
import json
from pathlib import Path
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/checked-toolchain')
BASE=Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
phase=sys.argv[1]
commands=[]
def run(command):
 command=list(map(str,command));r=subprocess.run(command,text=True,capture_output=True)
 commands.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (HERE/f'default-{phase}-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 r.check_returncode()
rows=[]
for name,directory,arrays in [
 ('private','native-private-stack-20261119',[]),('array','checked-array-c-20261119',['counts']),
 ('probe','checked-probe-c-20261119',[]),('hash','hash-c-lto-20261120',['map_a','map_same','map_b']),
 ('pid','pid-c-lto-20261120',[])]:
 out=BUILD/name;out.mkdir(parents=True,exist_ok=True)
 input_file=out/'input.bc';output=out/'native.bc'
 if phase=='before':
  run(['clang-18','-target','bpf','-O1','-g','-I/usr/include/x86_64-linux-gnu','-emit-llvm','-c',ROOT/'kprog/results'/directory/'fixture.c','-o',input_file])
  (HERE/f'{name}-input.bc.gz').write_bytes(gzip.compress(input_file.read_bytes(),mtime=0))
 run([BASE/'compile-sim-ir',input_file,'-o',output,'--helper-list',out/'helpers.txt',
      *[arg for name in arrays for arg in ('--array-map',name)]])
 data=output.read_bytes()
 (HERE/f'{name}-{phase}.bc.gz').write_bytes(gzip.compress(data,mtime=0))
 row=dict(case=name,bytes=len(data),helpers=(out/'helpers.txt').read_text().splitlines())
 if phase=='after':row['default_ir_equal']=data==gzip.decompress((HERE/f'{name}-before.bc.gz').read_bytes())
 rows.append(row)
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 phase=phase,rows=rows,scope='Actual default x86 compiler lowering on five existing regression fixtures; IR compatibility only, not complete request or stock/app acceptance.')
(HERE/f'default-{phase}-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(rows,indent=2))
