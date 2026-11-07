#!/usr/bin/env python3
"""Ensure the fault repair still admits and executes valid nonzero-high DIV."""
from pathlib import Path
import json
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import negative

def build(path):
    fixtures={}
    for width in [8,16,32,64]:
        low=512 if width==8 else 6
        high=0 if width==8 else 1
        quotient,remainder=divmod(low if width==8 else (high<<width)+low,7)
        assert quotient<(1<<width)
        setup=f'mov rax, {low}; mov edx, {high}; mov ecx, 7; '
        operand={8:'cl',16:'cx',32:'ecx',64:'rcx'}[width]
        if width==8: check=f'cmp ax, {quotient+(remainder<<8)}; jne 1f; '
        else:
            result={16:'ax',32:'eax',64:'rax'}[width]
            rem={16:'dx',32:'edx',64:'rdx'}[width]
            expected=f'mov r8, {quotient}; cmp rax, r8' if width==64 else f'cmp {result}, {quotient}'
            check=f'{expected}; jne 1f; cmp {rem}, {remainder}; jne 1f; '
        fixtures[f'div{width}_valid']=setup+f'div {operand}; '+check+'mov eax, 2; ret; 1: mov eax, 0; ret'
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
        command=[str(ROOT/'kprog/fidelity/build-x86/bound-probe'),str(ROOT/'kprog/fidelity/build-x86/negative-companion.bpf.o'),str(plan_path.resolve()),'0','2']
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
