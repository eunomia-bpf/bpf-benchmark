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
if len(sys.argv)>2 and not tail_helpers:raise ValueError(sys.argv[2])
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
for preserve in [False,True]:
    name=('tail_helper_'+('local' if preserve else 'direct') if tail_helpers else
        'entry_abi_'+('preserved' if preserve else 'stripped'))
    source=phase/'native'/(name+'.S');native=source.with_suffix('.native.o')
    text=body.replace('bl bpf_get_current_uid_gid','bl leaf') if tail_helpers else body
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
    (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'+
        f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; if (p+8>e) return 0; bpf_get_current_uid_gid(); *(__u64 *)p=37; return 2; }}\nchar LICENSE[] SEC("license")="GPL";\n')
    (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name[:15],source_btf_symbol=name,
        native_object='/cases/'+native.name,symbol='entry',simulator_object='/cases/'+name+'.bpf.o',
        simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
    rows.append(dict(name=name,expected=37,preserve_entry_abi=preserve))
(phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(phase.parent/'fmov-bank-bound-v2/bound-probe',phase/'bound-probe')
