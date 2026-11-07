"""Pin the entry frame and its local slot across both ARM proof ABI modes."""
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
tail_helpers=len(sys.argv)>2 and sys.argv[2]=='tail'
stack_sub=len(sys.argv)>2 and sys.argv[2]=='sub'
context=len(sys.argv)>2 and sys.argv[2]=='context'
divide=len(sys.argv)>2 and sys.argv[2]=='divide'
if len(sys.argv)>2 and not (tail_helpers or stack_sub or context or divide):raise ValueError(sys.argv[2])
body='''stp x19,x30,[sp,#-32]!
ldr x19,[x0]
ldr x2,[x0,#8]
add x3,x19,#8
cmp x3,x2
b.hi 1f
mov x4,#37
str x4,[sp,#16]
bl bpf_get_current_uid_gid
ldr x4,[sp,#16]
str x4,[x19]
mov w0,#2
b 2f
1: mov w0,#0
2: ldp x19,x30,[sp],#32
ret
'''
rows=[]
# Independent fixed boundary values; both ABI modes must execute the same word.
divisions=[('xz',64,37,0,5),('wz',32,37,0,5),('wtrunc',32,(1<<32)+37,1<<32,5),
    ('wupper',32,(1<<32)+37,(1<<32)+3,5),('xfull',64,(1<<64)-1,3,5),
    ('xalias',64,(1<<64)-1,3,6),('walias',32,(1<<32)-1,3,6),('same',64,(1<<64)-1,(1<<64)-1,5)]
for preserve,division in [(abi,case) for abi in [False,True] for case in (divisions if divide else [None])]:
    name=(('tail_helper_'+('local' if preserve else 'direct')) if tail_helpers else
        ('divide_'+division[0]+'_' if divide else 'helper_ctx_' if context else 'stack_sub_' if stack_sub else 'entry_abi_')+('preserved' if preserve else 'stripped'))
    source=phase/'native'/(name+'.S');native=source.with_suffix('.native.o')
    text=body.replace('bl bpf_get_current_uid_gid','bl leaf') if tail_helpers else body
    if stack_sub:
        text=body.replace('bl bpf_get_current_uid_gid',
            'add x8,sp,#24\nsub x0,x8,#8\nmov w1,#8\nmov x2,xzr\nbl bpf_probe_read_kernel')
    if context:
        text='''stp x19,x30,[sp,#-32]!
mov x19,x0
ldp x4,x3,[x19]
add x6,x4,#8
cmp x6,x3
b.hi 1f
mov w1,#4
bl bpf_xdp_adjust_head
cbnz x0,1f
ldp x4,x3,[x19]
add x6,x4,#8
cmp x6,x3
b.hi 1f
mov x5,#37
str x5,[x4]
mov w0,#2
b 2f
1: mov w0,#0
2: ldp x19,x30,[sp],#32
ret
'''
    if divide:
        _,width,lhs,rhs,dst=division
        mask=(1<<width)-1;expected=(lhs&mask)//(rhs&mask) if rhs&mask else 0
        moves=lambda reg,value:'\n'.join(f'{"movz" if shift==0 else "movk"} x{reg},#{(value>>shift)&65535},lsl #{shift}' for shift in [0,16,32,48])
        lane='x' if width==64 else 'w'
        text=('ldr x19,[x0]\nldr x2,[x0,#8]\nadd x3,x19,#8\ncmp x3,x2\nb.hi 1f\n'+
            moves(5,lhs)+'\n'+moves(6,rhs)+'\ncmp x5,x5\n'+
            f'udiv {lane}{dst},{lane}5,{lane}6\nb.ne 1f\nstr x{dst},[x19]\nmov w0,#2\nret\n1: mov w0,#0\nret\n')
    text='.text\n.global entry\n.type entry,%function\nentry:\n'+text+'.size entry,.-entry\n'
    if tail_helpers:
        text+='\n.global leaf\n.type leaf,%function\nleaf:\nb '+('leaf2' if preserve else 'bpf_get_current_uid_gid')+'\n.size leaf,.-leaf\n'
        if preserve:text+='\n.global leaf2\n.type leaf2,%function\nleaf2:\nb bpf_get_current_uid_gid\n.size leaf2,.-leaf2\n'
    source.write_text(text)
    subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',native],check=True)
    proof=phase/'native'/(name+'.proof.o')
    command=[ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,'--symbol','entry',
        '--mode','proof','--output',proof]
    if preserve or tail_helpers:command.append('--preserve-entry-abi')
    subprocess.run(command,check=True)
    shutil.copy2(proof,phase/'native'/(name+'.entry.proof.o'))
    functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'entry','xdp'),phase/'native')
    (phase/(name+'.bpf.c')).write_text(gen.render_program(name,'entry',functions,'xdp',rodata16=rodata,linked_exit=True))
    workload=('__u64 value=37; bpf_probe_read_kernel(&value,8,(void *)0); *(__u64 *)p=value;' if stack_sub else
        'bpf_get_current_uid_gid(); *(__u64 *)p=37;')
    if context:
        workload='if (bpf_xdp_adjust_head(ctx,4)) return 0; p=(void *)(long)ctx->data; e=(void *)(long)ctx->data_end; if (p+8>e) return 0; *(__u64 *)p=37;'
    if divide:workload=f'*(__u64 *)p={expected}ULL;'
    (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'+
        f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; if (p+8>e) return 0; {workload} return 2; }}\nchar LICENSE[] SEC("license")="GPL";\n')
    (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name[:15],source_btf_symbol=name,
        native_object='/cases/'+native.name,symbol='entry',simulator_object='/cases/'+name+'.bpf.o',
        simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
    rows.append(dict(name=name,expected=expected if divide else 0 if stack_sub else 37,preserve_entry_abi=preserve))
(phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(phase.parent/'fmov-bank-bound-v2/bound-probe',phase/'bound-probe')
