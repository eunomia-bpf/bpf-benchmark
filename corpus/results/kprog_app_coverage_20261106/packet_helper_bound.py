"""Build an XDP context-adjustment regression through the real bound loader."""
from pathlib import Path
import json
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
OUT=HERE/'packet-helper-bound';OUT.mkdir()
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
commands=[]
def run(args):
 args=list(map(str,args));r=subprocess.run(args,text=True,capture_output=True)
 commands.append(dict(command=args,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (OUT/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 if r.returncode:raise RuntimeError(r.stderr)
source=OUT/'source.bpf.c';source.write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int packet_ctx(struct xdp_md *ctx) {
 if (bpf_xdp_adjust_head(ctx,0)) return 0;
 unsigned long long *data=(void *)(long)ctx->data;
 if ((void *)(data+1)>(void *)(long)ctx->data_end) return 0;
 *data=42;return XDP_PASS;
}
char LICENSE[] SEC("license")="GPL";
''')
assembly=OUT/'entry.S';assembly.write_text('''.text
.globl packet_ctx
.type packet_ctx,@function
packet_ctx:
 push %rbx
 mov %rdi,%rbx
 xor %esi,%esi
 call bpf_xdp_adjust_head
 test %rax,%rax
 jnz 1f
 mov (%rbx),%rdi
 lea 8(%rdi),%rcx
 cmp 8(%rbx),%rcx
 ja 1f
 movq $42,(%rdi)
 mov $2,%eax
 jmp 2f
1: xor %eax,%eax
2: pop %rbx
 ret
.size packet_ctx,.-packet_ctx
.section .note.GNU-stack,"",@progbits
''')
native=OUT/'entry.native.o';proof=OUT/'entry.proof.o'
run(['cc','-c',assembly,'-o',native])
run([ROOT/'kprog/x86/native_lab/native_link/target-c-tail/release/native-link','--input',native,'--symbol','packet_ctx','--mode','proof','--preserve-entry-abi','--output',proof])
insns,subs,end,rodata=gen.parse_proof_object_program('entry',OUT)
text=gen.render_program('packet_ctx',insns,subs,'xdp',exit_addr=end,rodata16=rodata)
simulator=OUT/'sim.bpf.c';simulator.write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
flags=['clang','-g','-O2','-target','bpf','-Wno-c23-extensions','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu']
for src,obj in [(source,OUT/'source.bpf.o'),(simulator,OUT/'sim.bpf.o')]:run(flags+['-c',src,'-o',obj])
(OUT/'manifest.json').write_text(json.dumps(dict(objects=[dict(program='packet_ctx',prog_type=6,native_object=str(native),symbol='packet_ctx',simulator_object=str(OUT/'sim.bpf.o'),simulator_program='packet_ctx_x86_sim_xdp')]),indent=2)+'\n')
print('real XDP adjust0 -> reload packet window -> store42 -> XDP_PASS fixture built')
