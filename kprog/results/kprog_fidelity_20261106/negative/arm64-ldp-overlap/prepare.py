"""Build genuine pair-load encodings through the production specializer."""
from collections import OrderedDict
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT/'kprog/fidelity'))
from tcb import includes, imports
sys.path.insert(0, str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen

build = Path(sys.argv[1]).resolve()
build.mkdir(parents=True, exist_ok=True)
fixtures = build/'fixtures'
fixtures.mkdir(exist_ok=True)
paired = ROOT/'kprog/fidelity/build-arm64/sp-alignment-bound'
for name in ['bound-probe', 'init', 'bpf_arm64_native_lab.ko', 'native-link', 'companion.bpf.o', 'Image']:
    shutil.copyfile(paired/name, build/name)
snapshot = build/'snapshot'
for path in includes(ROOT/'kprog/arm64/arm64_sim_local_bpf.h') | imports(Path(gen.__file__)):
    target = snapshot/path.relative_to(ROOT)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(path, target)
cases = [
    ('ldp_same_x_used', 'ldp x1,x1,[sp];mov w0,w1'),
    ('ldp_same_x_overwritten', 'ldp x1,x1,[sp];mov x1,#2;mov w0,#2'),
    ('ldp_same_w_used', 'ldp w1,w1,[sp];mov w0,w1'),
    ('ldp_same_zr', 'ldp xzr,xzr,[sp];mov w0,#2'),
    ('ldp_distinct_control', 'ldp x1,x2,[sp];mov w0,w2'),
]
rows = []
for name, body in cases:
    assembly = 'sub sp,sp,#16;mov x1,#2;stp x1,x1,[sp];'+body+';add sp,sp,#16;ret'
    source = fixtures/(name+'.S')
    source.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+assembly.replace(';','\n')+'\n.size entry,.-entry\n')
    compiler = subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',fixtures/(name+'.native.o')], text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (fixtures/(name+'.assemble.log')).write_text(compiler.stdout)
    if compiler.returncode:
        raise RuntimeError(f'{name}: assembler rc{compiler.returncode}: {compiler.stdout}')
    disassembly = subprocess.check_output(['aarch64-linux-gnu-objdump','-dr',fixtures/(name+'.native.o')], text=True)
    (fixtures/(name+'.asm')).write_text(disassembly)
    row = dict(name=name, assembly=assembly, stage='generated', message='')
    try:
        proof = gen.render_program(name,'entry',OrderedDict(entry=gen.parse_flat_instructions(disassembly)),'xdp')
    except ValueError as error:
        row.update(stage='specialization_rejected', message=str(error))
        rows.append(row)
        continue
    proof = proof.replace('#include "../arm64_sim_local_bpf.h"',f'#include "{snapshot}/kprog/arm64/arm64_sim_local_bpf.h"')
    path = fixtures/(name+'.bpf.c')
    path.write_text(proof)
    command = ['clang','-g','-O2','-target','bpf','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(path),'-o',str(fixtures/(name+'.bpf.o'))]
    result = subprocess.run(command,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    (fixtures/(name+'.compile.log')).write_text(result.stdout)
    if result.returncode:
        raise RuntimeError(f'{name}: compiler rc{result.returncode}: {result.stdout}')
    plan = {'objects':[dict(program='neg_source',native_object=name+'.native.o',symbol='entry',simulator_object=name+'.bpf.o',simulator_program=name+'_arm64_sim_xdp')]}
    (fixtures/(name+'.manifest.json')).write_text(json.dumps(plan,indent=2)+'\n')
    rows.append(row)
(build/'build.json').write_text(json.dumps(rows,indent=2)+'\n')
(build/'cases').write_text(''.join(r['name']+'\n' for r in rows if r['stage']=='generated'))
for row in rows:
    print(row['name'],row['stage'],row['message'])
