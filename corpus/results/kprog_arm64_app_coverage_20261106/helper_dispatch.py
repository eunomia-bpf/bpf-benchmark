"""Observe both joined native helper cases and a preserved helper-ID register."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir();(phase/'native').mkdir()
rows=[]
for mode in [0,1,2]:
    name='helper_dispatch_'+str(mode)
    body=['stp x19,x30,[sp,#-16]!','ldr x19,[x0]','ldr x2,[x0,#8]',
        'add x3,x19,#8','cmp x3,x2','b.hi 1f']
    if mode<2:
        body+=['ldrb w1,[x19]']
        if mode:body+=['eor w1,w1,#1']
        body+=['mov x8,#14','cbz w1,2f','mov x8,#14','b 3f','2: mov x8,#15','3: blr x8',
            'cmp x0,#0','cset w2,ne','str x2,[x19]']
        expression=f'((*(unsigned char *)p ^ {mode}) ? bpf_get_current_pid_tgid() : bpf_get_current_uid_gid()) != 0'
        expected=mode
    else:
        body=['sub sp,sp,#32','stp x19,x30,[sp]','str x24,[sp,#16]','ldr x19,[x0]',
            'ldr x2,[x0,#8]','add x3,x19,#8','cmp x3,x2','b.hi 1f',
            'mov x24,#15','blr x24','str x24,[x19]']
        expression='(bpf_get_current_uid_gid(),15ULL)';expected=15
    body+=['mov w0,#2','b 4f','1: mov w0,#0','4:']
    if mode==2:body+=['ldr x24,[sp,#16]','ldp x19,x30,[sp]','add sp,sp,#32','ret']
    else:body+=['ldp x19,x30,[sp],#16','ret']
    source=phase/'native'/(name+'.S');native=source.with_suffix('.native.o')
    source.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+'\n'.join(body)+'\n.size entry,.-entry\n')
    subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',native],check=True)
    proof=phase/'native'/(name+'.proof.o')
    subprocess.run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,
        '--symbol','entry','--mode','proof','--output',proof],check=True)
    functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'entry','xdp'),phase/'native')
    (phase/(name+'.bpf.c')).write_text(gen.render_program(name,'entry',functions,'xdp',rodata16=rodata,linked_exit=True))
    (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'+
        f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; if (p+8>e) return 0; *(__u64 *)p={expression}; return 2; }}\nchar LICENSE[] SEC("license")="GPL";\n')
    (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name[:15],source_btf_symbol=name,
        native_object='/cases/'+native.name,symbol='entry',simulator_object='/cases/'+name+'.bpf.o',
        simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
    rows.append(dict(name=name,expected=expected))
name='helper_dispatch_bad'
for suffix in ['native.o','proof.o']:
    shutil.copy2(phase/'native'/('helper_dispatch_0.'+suffix),phase/'native'/(name+'.'+suffix))
original=(phase/'helper_dispatch_0.bpf.c').read_text()
lines=original.splitlines(keepends=True)
removed=[line for line in lines if 'case 14ULL:' in line]
if len(removed)!=1:raise RuntimeError('expected one real helper14 dispatch arm')
(phase/(name+'.bpf.c')).write_text(''.join(line for line in lines if line not in removed).replace('helper_dispatch_0',name))
(phase/(name+'.source.bpf.c')).write_text((phase/'helper_dispatch_0.source.bpf.c').read_text().replace('helper_dispatch_0',name))
(phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name[:15],source_btf_symbol=name,
    native_object='/cases/'+name+'.native.o',symbol='entry',simulator_object='/cases/'+name+'.bpf.o',
    simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
rows.append(dict(name=name,expected=0,reject=True))
(phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(phase.parent/'fmov-bank-bound-v2/bound-probe',phase/'bound-probe')
