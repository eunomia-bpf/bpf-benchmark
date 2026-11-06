"""Preserve address-taken instruction targets through both native link stages."""
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=HERE/'code-dispatch'
LINK=HERE/'native-dispatch-link/release/native-link'
OUT.mkdir(exist_ok=True)
NAMES=('join','cmov','call','pc32')

def run(args):
    result=subprocess.run([str(a) for a in args],text=True,capture_output=True,timeout=120)
    row=dict(command=[str(a) for a in args],returncode=result.returncode,
             stdout=result.stdout,stderr=result.stderr)
    with (OUT/'commands.jsonl').open('a') as stream:stream.write(json.dumps(row)+'\n')
    if result.returncode:raise RuntimeError(row)
    return result

if sys.argv[1]=='prepare':
    for name in NAMES[:3]:
        (OUT/(name+'.S')).write_bytes((HERE/'indirect-build'/(name+'.S')).read_bytes())
    (OUT/'pc32.S').write_text('''.intel_syntax noprefix
.text
.globl pc32_native
.type pc32_native,@function
pc32_native:
 lea rax,[rip+pc32_callee+1]
 call rax
 ret
.size pc32_native,.-pc32_native
.section .text.pc32_callee,"ax",@progbits
.type pc32_callee,@function
pc32_callee:
 nop
 mov eax,42
 ret
.size pc32_callee,.-pc32_callee
.section .note.GNU-stack,"",@progbits
''')
    (OUT/'pc32-original.bpf.c').write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int dispatch_orig(struct xdp_md *ctx) { return 42; }
char LICENSE[] SEC("license")="GPL";
''')
    (OUT/'original.bpf.c').write_bytes((HERE/'indirect-build/original.bpf.c').read_bytes())
    (OUT/'host.c').write_text('''#include <stdio.h>
struct context { void *data,*end; };
extern unsigned join_blob(struct context *),cmov_blob(struct context *),call_blob(struct context *);
extern unsigned pc32_blob(struct context *);
int main(void) {
    unsigned char packet[9]={}; struct context ctx={packet,packet+9};
    for(unsigned bit=0;bit<2;bit++) {
        packet[8]=bit;
        unsigned a=join_blob(&ctx),b=cmov_blob(&ctx),c=call_blob(&ctx),d=pc32_blob(&ctx);
        printf("input=%u join=%u cmov=%u nested_call=%u pc32=%u\\n",bit,a,b,c,d);
        if(a!=(bit?17:42)||b!=a||c!=(bit?14:6)||d!=42)return 1;
    }
    return 0;
}
''')
elif sys.argv[1]=='link':
    sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
    spec=importlib.util.spec_from_file_location('code_generator',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    g=importlib.util.module_from_spec(spec);sys.modules[spec.name]=g;spec.loader.exec_module(g)
    for name in NAMES:
        native=OUT/(name+'.native.o');proof=OUT/(name+'.proof.o')
        run([LINK,'--input',native,'--symbol',name+'_native','--mode','proof',
             '--preserve-entry-abi','--output',proof,'--show'])
        (OUT/(name+'_native.proof.o')).write_bytes(proof.read_bytes())
        insns,subs,end,rodata=g.parse_proof_object_program(name,OUT)
        text=g.render_program(name,insns,subs,exit_addr=end,rodata16=rodata)
        (OUT/(name+'.bpf.c')).write_text(text.replace('#include "../x86_sim_local_bpf.h"',
                                                    f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        blob=OUT/(name+'.blob')
        run([LINK,'--input',proof,'--symbol',name+'_native','--mode','kernel',
             '--output',blob,'--show'])
        (OUT/(name+'.host.S')).write_text(f'.text\n.globl {name}_blob\n{name}_blob:\n.incbin "{blob}"\nret\n.section .note.GNU-stack,"",@progbits\n')
        (OUT/(name+'.manifest.json')).write_text(json.dumps(dict(objects=[dict(
            program='dispatch_orig',native_object=str(native),symbol=name+'_native',
            simulator_object=str(OUT/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')])))
elif sys.argv[1]=='bound':
    failures=[]
    for name in NAMES:
        source = 'original-call.bpf.o' if name=='call' else 'pc32-original.bpf.o' if name=='pc32' else 'original.bpf.o'
        args=[str(OUT/'bound-probe'),str(OUT/source),
              str(OUT/(name+'.manifest.json')),'0','6' if name=='call' else '42']
        result=subprocess.run(args,text=True,capture_output=True,timeout=120,
            env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
                     BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1'))
        row=dict(command=args,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
        (OUT/(name+'.bound.json')).write_text(json.dumps(row,indent=2)+'\n')
        print(name,result.returncode,result.stdout,result.stderr,flush=True)
        if result.returncode:failures.append(name)
    raise SystemExit(int(bool(failures)))
else:raise SystemExit('expected prepare, link or bound')
