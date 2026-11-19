"""Regression for private-arena scope; global/mixed/atomic effects must remain."""
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);expected=sys.argv[2];out.mkdir(parents=True,exist_ok=True);commands=[]
def run(args):
    p=subprocess.run([str(x) for x in args],text=True,capture_output=True)
    commands.append(dict(command=[str(x) for x in args],returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');p.check_returncode();return p.stdout
run(['clang-18','-target','bpf','-O1','-g','-emit-llvm','-c',ROOT/'kprog/results/native-private-stack-20261119/fixture.c','-o',out/'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',out/'input.bc','-o',out/'native.bc'])
ir=run(['llvm-dis-18',out/'native.bc','-o','-']);(out/'native.ll').write_text(ir)
def body(name):return ir.split('@'+name+'(',1)[1].split('\n}',1)[0]
counts={name:body(name).count(' volatile ') for name in ['private_sum','global_access','pointer_access','mixed','other_local','atomic_local']}
assert (counts['private_sum']==0)==(expected=='normalized'),counts
assert all(counts[n]>0 for n in ['global_access','pointer_access','mixed','other_local','atomic_local']),counts
run(['clang-18','-O3','-mno-red-zone','-mgeneral-regs-only','-c',out/'native.bc','-o',out/'native.o'])
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',ROOT/'kprog/results/native-private-stack-20261119/driver.c',out/'native.o','-o',out/'execute'])
result=run([out/'execute']);(out/'summary.json').write_text(json.dumps(dict(mode=expected,volatile_counts=counts,result=result,
    scope='Host private-memory normalization and preserved effects; no app runtime result'),indent=2)+'\n');print(counts,result,flush=True)
