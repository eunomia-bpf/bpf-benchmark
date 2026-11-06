"""Exercise joined helper identities through the production native linker."""
import importlib.util
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
OUT = HERE/'native-dispatch'
LINK = HERE/'native-dispatch-link/release/native-link'
NAMES = ('join_dispatch','cmov_dispatch','got_dispatch')
OUT.mkdir(exist_ok=True)

def command(args):
    result = subprocess.run([str(a) for a in args],text=True,capture_output=True,timeout=120)
    with (OUT/'commands.jsonl').open('a') as log:
        log.write(json.dumps(dict(command=[str(a) for a in args],returncode=result.returncode,
                                  stdout=result.stdout,stderr=result.stderr))+'\n')
    if result.returncode:
        raise RuntimeError(result.stderr or result.stdout)
    return result

if sys.argv[1]=='prepare':
    prefix = '''.intel_syntax noprefix
.text
.globl {name}_native
.type {name}_native,@function
{name}_native:
 push rbx
 mov rdx,[rdi]
 mov rcx,[rdi+8]
 lea rax,[rdx+9]
 cmp rax,rcx
 ja .Lbad
 cmp BYTE PTR [rdx+8],0
'''
    for name,body in {
        'join_dispatch': ''' jne .Lone
 mov ebx,14
 jmp .Lcall
.Lone:
 mov ebx,15
.Lcall:
''',
        'cmov_dispatch': ''' mov ebx,14
 mov eax,15
 cmove rbx,rax
''',
        'got_dispatch': ''' jne .Lone
 mov rbx,QWORD PTR [rip+bpf_get_current_pid_tgid@GOTPCREL]
 jmp .Lcall
.Lone:
 mov rbx,QWORD PTR [rip+bpf_get_current_uid_gid@GOTPCREL]
.Lcall:
''',
    }.items():
        result = 'mov eax,2' if name=='got_dispatch' else 'mov eax,ebx'
        (OUT/(name+'.S')).write_text((prefix+body+' call rbx\n '+result+'''
 pop rbx
 ret
.Lbad:
 mov eax,0
 pop rbx
 ret
.size {name}_native,.-{name}_native
.section .note.GNU-stack,"",@progbits
''').format(name=name))
    (OUT/'source.bpf.c').write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int dispatch_source(struct xdp_md *ctx) {
    unsigned char *data=(void *)(long)ctx->data,*end=(void *)(long)ctx->data_end;
    if(data+9>end) return 0;
    int which=data[8]!=0;
#ifdef INVERT
    which=!which;
#endif
    if(which) { bpf_get_current_uid_gid(); return
#ifdef GOT_RESULT
      2;
#else
      15;
#endif
    }
    bpf_get_current_pid_tgid(); return
#ifdef GOT_RESULT
      2;
#else
      14;
#endif
}
char LICENSE[] SEC("license")="GPL";
''')
    (OUT/'host.c').write_text('''#include <stdint.h>
#include <stdio.h>
struct context { void *data,*end; };
unsigned called;
uint64_t host_pid(void) { called=14; return 47; }
uint64_t host_uid(void) { called=15; return 83; }
extern unsigned join_dispatch_blob(struct context *),cmov_dispatch_blob(struct context *);
extern unsigned got_dispatch_blob(struct context *);
int main(void) {
    unsigned char packet[9]={};
    struct context ctx={packet,packet+9};
    for(unsigned bit=0;bit<2;bit++) {
        packet[8]=bit;
        unsigned a=join_dispatch_blob(&ctx),ac=called;
        unsigned b=cmov_dispatch_blob(&ctx),bc=called;
        unsigned c=got_dispatch_blob(&ctx),cc=called;
        printf("input=%u join=%u called=%u cmov=%u called=%u got=%u called=%u\\n",bit,a,ac,b,bc,c,cc);
        if(a!=14+bit || ac!=a || b!=15-bit || bc!=b || c!=2 || cc!=14+bit) return 1;
    }
    return 0;
}
''')
elif sys.argv[1]=='link':
    sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
    spec=importlib.util.spec_from_file_location('dispatch_generator',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    g=importlib.util.module_from_spec(spec);sys.modules[spec.name]=g;spec.loader.exec_module(g)
    plan=OUT/'host-plan.json'
    plan.write_text(json.dumps(dict(version=1,helpers=[dict(name='bpf_get_current_pid_tgid',addr=4096),
                                                      dict(name='bpf_get_current_uid_gid',addr=8192)])))
    for name in NAMES:
        proof=OUT/(name+'.proof.o')
        command([LINK,'--input',OUT/(name+'.o'),'--symbol',name+'_native','--mode','proof',
                 '--preserve-entry-abi','--output',proof])
        # Match the production loader's explicit sibling-proof convention.
        (OUT/(name+'_native.proof.o')).write_bytes(proof.read_bytes())
        insns,subs,end,rodata=g.parse_proof_object_program(name,OUT)
        text=g.render_program(name,insns,subs,exit_addr=end,rodata16=rodata)
        (OUT/(name+'.bpf.c')).write_text(text.replace('#include "../x86_sim_local_bpf.h"',
                                                   f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        blob=OUT/(name+'.blob');relocs=OUT/(name+'.relocs')
        command([LINK,'--input',proof,'--symbol',name+'_native','--mode','kernel',
                 '--link-plan',plan,'--output',blob,'--output-relocs',relocs,'--show'])
        data=blob.read_bytes();records=list(struct.iter_unpack('<IIQ',relocs.read_bytes()))
        assert {r[2] for r in records}=={4096,8192},records
        assert all(kind==7 and data[off:off+8]==bytes(8) for off,kind,target in records),records
        lines=['.text',f'.globl {name}_blob',f'{name}_blob:']
        start=0
        for off,kind,target in sorted(records):
            if off>start: lines.append(f'.incbin "{blob}",{start},{off-start}')
            lines.append('.quad '+{4096:'host_pid',8192:'host_uid'}[target]);start=off+8
        if start<len(data):lines.append(f'.incbin "{blob}",{start},{len(data)-start}')
        lines.extend(['ret','.section .note.GNU-stack,"",@progbits'])
        (OUT/(name+'.host.S')).write_text('\n'.join(lines)+'\n')
        (OUT/(name+'.manifest.json')).write_text(json.dumps(dict(objects=[dict(
            program='dispatch_source',native_object=str(OUT/(name+'.o')),symbol=name+'_native',
            simulator_object=str(OUT/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')])))
        print(name,'kind7 helper table slots',records)
elif sys.argv[1]=='bound':
    for name,expected in [('join_dispatch',14),('cmov_dispatch',15),('got_dispatch',2)]:
        env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
                 BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1')
        args=[str(OUT/'bound-probe'),str(OUT/(name+'.source.bpf.o')),
              str(OUT/(name+'.manifest.json')),'0',str(expected)]
        result=subprocess.run(args,env=env,text=True,capture_output=True,timeout=120)
        (OUT/(name+'.bound.json')).write_text(json.dumps(dict(command=args,returncode=result.returncode,
            stdout=result.stdout,stderr=result.stderr),indent=2)+'\n')
        print(name,result.returncode,result.stdout,result.stderr,flush=True)
        if result.returncode:raise SystemExit(result.returncode)
else:raise SystemExit('expected prepare, link or bound')
