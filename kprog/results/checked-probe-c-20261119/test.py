"""Test native C helper ABI, error zeroing, and actual kernel symbol linking."""
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);commands=[]
compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir')
link=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
def run(args):
    p=subprocess.run([str(v) for v in args],text=True,capture_output=True)
    commands.append(dict(command=[str(v) for v in args],returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');p.check_returncode();return p.stdout
fixture=ROOT/'kprog/results/checked-probe-c-20261119/fixture.c'
run(['clang-18','-target','bpf','-I/usr/include/x86_64-linux-gnu','-O3','-emit-llvm','-c',fixture,'-o',out/'input.bc'])
run([compiler,out/'input.bc','--helper-list',out/'helpers.txt','-o',out/'native.bc'])
assert set((out/'helpers.txt').read_text().splitlines())=={'__kprog_probe_read_user','__kprog_probe_read_kernel'}
run(['clang-18','-O3','-mgeneral-regs-only','-emit-llvm','-c',ROOT/'kprog/x86/micro-prog/inline_probe.c','-o',out/'helpers.bc'])
run(['llvm-link-18',out/'native.bc',out/'helpers.bc','-o',out/'linked.bc'])
run(['clang-18','-O3','-mgeneral-regs-only','-mno-red-zone','-fomit-frame-pointer','-fno-stack-protector','-c',out/'linked.bc','-o',out/'native.o'])
asm=run(['llvm-objdump-18','-dr',out/'native.o']);(out/'native.asm').write_text(asm)
for name in ['user8','kernel8','user_dynamic','kernel_dynamic']:
    body=asm.split('<'+name+'>:')[1].split('\n\n')[0]
    assert '__kprog_probe_read' not in body and 'bpf_probe_read' not in body,body
    assert 'copy_from_' in body,body
run(['clang-18','-O3','-fsanitize=undefined',ROOT/'kprog/results/checked-probe-c-20261119/driver.c',out/'native.o','-o',out/'execute'])
result=run([out/'execute'])
symbols={}
for line in (Path('/workspaces/.agent-state/kprog-ck/build-x86/System.map')).read_text().splitlines():
    address,kind,name=line.split();symbols[name]=int(address,16)
plan=dict(version=1,helpers=[dict(name=name,addr=symbols[name]) for name in ['copy_from_user_nofault','copy_from_kernel_nofault','memset']])
(out/'plan.json').write_text(json.dumps(plan,indent=2)+'\n')
for name in ['user8','kernel8','user_dynamic','kernel_dynamic']:
    run([link,'--input',out/'native.o','--symbol',name,'--mode','proof','--preserve-entry-abi','--output',out/(name+'.proof.o')])
    run([link,'--input',out/'native.o','--symbol',name,'--mode','kernel','--link-plan',out/'plan.json','--output',out/(name+'.bin'),
         '--output-relocs',out/(name+'.relocs'),'--output-abi',out/(name+'.abi')])
(out/'summary.json').write_text(json.dumps(dict(result=result,kernel_bindings=list(v['name'] for v in plan['helpers']),
    proof_and_kernel_entries=4,scope='Host wrapper ABI/zeroing and static current-kernel bindings; no kernel copy execution or app timing'),indent=2)+'\n')
print(result,end='')
