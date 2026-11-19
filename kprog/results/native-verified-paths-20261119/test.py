"""Check only the two verifier-invalid forms lose native traps and checks."""
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);mode=sys.argv[2];out.mkdir(parents=True,exist_ok=True);rows=[]
def run(args):
    p=subprocess.run([str(x) for x in args],text=True,capture_output=True)
    rows.append(dict(command=[str(x) for x in args],returncode=p.returncode,stdout=p.stdout,stderr=p.stderr));(out/'commands.json').write_text(json.dumps(rows,indent=2)+'\n');p.check_returncode();return p.stdout
run(['clang-18','-target','bpf','-O1','-g','-emit-llvm','-c',ROOT/'kprog/results/native-verified-paths-20261119/fixture.c','-o',out/'input.bc'])
before=run(['llvm-dis-18',out/'input.bc','-o','-'])
assert 'call -1' in before and 'r0 = 0;' in before
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',out/'input.bc','-o',out/'native.bc'])
after=run(['llvm-dis-18',out/'native.bc','-o','-'])
assumes=after.count('call void @llvm.assume(i1 false)');traps=after.count('call void @llvm.trap()')
assert (assumes,traps)==((2,0) if mode=='verified' else (0,2)),(assumes,traps)
run(['clang-18','-O3','-mno-red-zone','-mgeneral-regs-only','-S','-emit-llvm',out/'native.bc','-o',out/'optimized.ll'])
optimized=(out/'optimized.ll').read_text()
for name in ['verified_dispatch','verified_memory']:
    body=optimized.split('@'+name+'(',1)[1].split('\n}',1)[0]
    assert ('llvm.trap' not in body)==(mode=='verified'),body
    if mode=='verified':assert 'icmp' not in body,body
ordinary=optimized.split('@program_check(',1)[1].split('\n}',1)[0]
assert 'icmp' in ordinary and '99' in ordinary
run(['clang-18','-O3','-mno-red-zone','-mgeneral-regs-only','-c',out/'native.bc','-o',out/'native.o'])
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',ROOT/'kprog/results/native-verified-paths-20261119/driver.c',out/'native.o','-o',out/'execute'])
result=run([out/'execute'])
(out/'summary.json').write_text(json.dumps(dict(mode=mode,assumes=assumes,traps=traps,ordinary_check_retained=True,result=result,
    scope='Host post-verification contract test. Invalid-domain native calls are not executed; no stock or app runtime result.'),indent=2)+'\n');print(result,end='')
