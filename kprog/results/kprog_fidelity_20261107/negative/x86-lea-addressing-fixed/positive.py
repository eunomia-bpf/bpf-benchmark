#!/usr/bin/env python3
"""Ensure the fault repair still admits and executes valid nonzero-high DIV."""
from pathlib import Path
import json
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity/build-lea-final-published/source/kprog/fidelity'))
import negative

def build(path):
    fixtures={}
    for dst,expected in [('ax',0x1122334455665678),('eax',0x12345678),('rax',0x12345678),
                         ('r8w',0x1122334455665678),('r8d',0x12345678),('r8',0x12345678)]:
        result='r8' if dst.startswith('r8') else 'rax'
        fixtures['absolute_'+dst]=(f'mov rax,0x1122334455667788; mov r8,0x1122334455667788; '
            f'lea {dst},[0x12345678]; mov r10,{expected}; cmp {result},r10; jne 1f; '
            'mov eax,2; ret; 1: mov eax,0; ret')
    for dst in ['rax','r8']:
        for label,address,expected in [('legacy','[eax+ecx*4-7]',3),('extended','[r8d+r9d*8+127]',0x95)]:
            fixtures['addr32_'+dst+'_'+label]=(f'mov rax,0x12345678fffffffe; mov ecx,3; '
                f'mov r8,0x12345678fffffffe; mov r9,0xabcdef0100000003; '
                f'lea {dst},{address}; cmp {dst},{expected}; jne 1f; '
                'mov eax,2; ret; 1: mov eax,0; ret')
    negative.FIXTURES['x86']=fixtures
    negative.build('x86',path)

def check(build_dir,out):
    out.mkdir(parents=True,exist_ok=True)
    manifest=json.loads((build_dir/'build.json').read_text())
    failed=False
    for row in manifest['cases']:
        if row['stage']!='generated':failed=True;continue
        name=row['name']
        plan={'objects':[dict(program='neg_source',native_object=str((build_dir/f'{name}.native.o').resolve()),symbol='entry',simulator_object=str((build_dir/f'{name}.bpf.o').resolve()),simulator_program=f'{name}_x86_sim_xdp')]}
        plan_path=out/f'{name}.manifest.json';plan_path.write_text(json.dumps(plan,indent=2)+'\n')
        command=[str(ROOT/'kprog/fidelity/build-lea-private-probe/bound-probe'),str(ROOT/'kprog/fidelity/build-x86/negative-companion.bpf.o'),str(plan_path.resolve()),'0','2']
        run=subprocess.run(command,cwd=ROOT/'kprog/fidelity',text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        (out/f'{name}.log').write_text(run.stdout)
        row.update(stage='correct_native_bound' if run.returncode==0 else 'failed',returncode=run.returncode,command=command,message=run.stdout)
        failed |= run.returncode!=0
    (out/'outcomes.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({r['name']:r['stage'] for r in manifest['cases']}))
    return int(failed)

if __name__=='__main__':
    if sys.argv[1]=='build':build(Path(sys.argv[2]))
    elif sys.argv[1]=='check':raise SystemExit(check(Path(sys.argv[2]),Path(sys.argv[3])))
    else:raise ValueError('expected build or check')
