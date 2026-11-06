"""Regress CFG joins, stale targets and real native indirect call/return paths."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
BUILD = HERE / 'indirect-build'
BUILD.mkdir(exist_ok=True)
sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
spec = importlib.util.spec_from_file_location('generator', ROOT / 'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)

# Native entry has the real native XDP ABI (data and data_end pointers).
prefix = '''
.intel_syntax noprefix
.text
.globl {name}_native
.type {name}_native,@function
{name}_native:
 mov rdx, [rdi]
 mov rcx, [rdi+8]
 lea rax, [rdx+9]
 cmp rax, rcx
 ja .Lbad
 cmp BYTE PTR [rdx+8], 0
'''
join = '''
 jne .Lchoose
 lea rax, [rip+.Lzero]
 jmp .Ldispatch
.Lchoose:
 lea rax, [rip+.Lone]
.Ldispatch:
 jmp rax
.Lzero:
 mov eax, 42
 ret
.Lone:
 mov eax, 17
 ret
.Lbad:
 mov eax, 0
 ret
'''
cmov = '''
 lea rax, [rip+.Lzero]
 lea rcx, [rip+.Lone]
 cmovne rax, rcx
 jmp rax
.Lzero:
 mov eax, 42
 ret
.Lone:
 mov eax, 17
 ret
.Lbad:
 mov eax, 0
 ret
'''
call = '''
 jne .Lchoose
 lea rax, [rip+callee_zero]
 jmp .Ldispatch
.Lchoose:
 lea rax, [rip+callee_one]
.Ldispatch:
 call rax
 add eax, 2
 ret
.Lbad:
 mov eax, 0
 ret
.size {name}_native, .-{name}_native
.type callee_zero,@function
callee_zero:
 mov eax, 4
 ret
.size callee_zero, .-callee_zero
.type callee_one,@function
callee_one:
 lea rax, [rip+callee_zero]
 call rax
 add eax, 8
 ret
.size callee_one, .-callee_one
'''
fixtures = {'join': join, 'cmov': cmov, 'call': call}
if sys.argv[1] == 'prepare':
    (BUILD/'original.bpf.c').write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int dispatch_orig(struct xdp_md *ctx) {
    unsigned char *data=(void *)(long)ctx->data;
    unsigned char *end=(void *)(long)ctx->data_end;
    if (data+9>end) return 0;
#ifdef CALL_FIXTURE
    return data[8] ? 14 : 6;
#else
    return data[8] ? 17 : 42;
#endif
}
char LICENSE[] SEC("license")="GPL";
''')
    for name, body in fixtures.items():
        (BUILD / f'{name}.S').write_text((prefix + body + ('' if name=='call' else '\n.size {name}_native, .-{name}_native\n')).format(name=name) + '\n.section .note.GNU-stack,"",@progbits\n')
    (BUILD / 'main.c').write_text('''#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
struct native_ctx { void *data, *data_end; };
static unsigned char packet[9];
''' + '\n'.join(f'int {n}_native(struct native_ctx *);\nint {n}_x86_sim_xdp(struct xdp_md *);' for n in fixtures) + '''
int main(void) {
    int failures = 0;
    struct native_ctx native_ctx = {packet, packet+9};
    struct xdp_md ctx = {.data=(uintptr_t)packet, .data_end=(uintptr_t)(packet+9)};
    for (unsigned i=0; i<2; ++i) {
        packet[8] = i;
''' + '\n'.join(f'''        {{ int native={n}_native(&native_ctx), sim={n}_x86_sim_xdp(&ctx);
           int expected={"(i ? 14 : 6)" if n == "call" else "(i ? 17 : 42)"};
           printf("{n} input=%u native=%d simulator=%d expected=%d\\n",i,native,sim,expected);
           failures += native != expected || sim != native; }}''' for n in fixtures) + '''
    }
    return failures != 0;
}
''')
elif sys.argv[1] == 'generate':
    for name in fixtures:
        insns, subs, end, rodata = g.parse_proof_object_program(name, BUILD)
        targets = g.indirect_targets([*insns, *(i for fn in subs.values() for i in fn)], end,
                                     {insns[0].addr, *(fn[0].addr for fn in subs.values())})
        assert any(len(ts) == 2 for ts in targets.values()), (name, targets)
        assert all(k == 'code' for ts in targets.values() for k, _ in ts)
        text = g.render_program(name, insns, subs, exit_addr=end, rodata16=rodata)
        text = text.replace('#include "../x86_sim_local_bpf.h"',
                            f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"')
        (BUILD / f'{name}.bpf.c').write_text(text)
        print(name, {hex(a): sorted(ts) for a, ts in targets.items()})
    # Regression: all paths into a join matter, including unknown and stale writes.
    def i(addr, op, args):
        return g.NativeInsn(addr, op + ' ' + ','.join(args), op, args)
    base = [i(0, 'mov', ('rax', '14')), i(1, 'call', ('rax',)), i(2, 'ret', ())]
    assert g.indirect_targets(base)[1] == frozenset({('scalar',14)})
    for overwrite in [i(1, 'mov', ('al', '15')), i(1, 'mov', ('rax', 'QWORD PTR [rdi]')),
                      i(1, 'mul', ('rbx',)), i(1, 'call', ('rbx',))]:
        code = [base[0], overwrite, i(2,'call',('rax',)), i(3,'ret',())]
        try:
            g.indirect_targets(code)
        except ValueError as error:
            assert 'indirect target' in str(error), error
        else:
            raise AssertionError(('stale target survived', overwrite))
    code = [i(0,'mov',('rax','14')), i(1,'je',('4',)), i(2,'mov',('rax','15')),
            i(3,'jmp',('5',)), i(4,'mov',('rax','QWORD PTR [rdi]')),
            i(5,'call',('rax',)), i(6,'ret',())]
    try:
        g.indirect_targets(code)
    except ValueError as error:
        assert 'unresolved finite' in str(error)
    else:
        raise AssertionError('unknown path discarded at join')
    code[4] = i(4,'mov',('rax','16'))
    assert g.indirect_targets(code)[5] == frozenset({('scalar',15),('scalar',16)})
    print('stale/partial/implicit writes and unknown CFG join rejected; finite helper join preserved')
elif sys.argv[1] == 'bound':
    failed=False
    for name in fixtures:
        manifest=BUILD/f'{name}.manifest.json'
        manifest.write_text(json.dumps({'objects':[dict(program='dispatch_orig',
            native_object=str(BUILD/f'{name}.proof.o'),symbol=f'{name}_native',
            simulator_object=str(BUILD/f'{name}.bpf.o'),simulator_program=f'{name}_x86_sim_xdp')]}))
        command=[str(BUILD/'bound-probe'),str(BUILD/('original-call.bpf.o' if name=='call' else 'original.bpf.o')),
                 str(manifest),'0','6' if name=='call' else '42']
        result=subprocess.run(command,text=True,capture_output=True,timeout=60)
        (BUILD/f'{name}.bound.json').write_text(json.dumps(dict(command=command,
            returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))+'\n')
        print(name,'bound returncode',result.returncode,flush=True)
        failed |= result.returncode != 0
    raise SystemExit(int(failed))
elif sys.argv[1] == 'verify':
    failed = False
    for name in fixtures:
        for value in (0,1):
            payload = BUILD / f'input-{value}.bin'
            payload.write_bytes(bytes([value])+bytes(63))
            expected = (14 if value else 6) if name == 'call' else (17 if value else 42)
            command = [str(ROOT/'kprog/loader/target/debug/reversesim-loader'),
                       '--object',str(BUILD/f'{name}.bpf.o'),'--program',f'{name}_x86_sim_xdp',
                       '--input',str(payload),'--expected-result','0','--expect-retval',str(expected),
                       '--repeat','1','--verifier-log',str(BUILD/f'{name}-{value}.verifier.log')]
            result = subprocess.run(command,text=True,capture_output=True,timeout=60)
            (BUILD/f'{name}-{value}.json').write_text(json.dumps(dict(
                command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))+'\n')
            print(name,value,'returncode',result.returncode,flush=True)
            failed |= result.returncode != 0
    raise SystemExit(int(failed))
else:
    raise SystemExit('expected prepare, generate or verify')
