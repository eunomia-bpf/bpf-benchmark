"""Regress full-write extents, opaque copies and finite helper-call joins."""
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as g
from helper_abi import HELPER_FULL_WRITES, helper_prototypes

rows = []

def check(name, body, accepted, targets=None):
    insns = []
    for i, text in enumerate(body.split('; ')):
        op, _, operands = text.partition(' ')
        insns.append(g.NativeInsn(i,text,op,g.split_operands(operands),
                                 reloc_symbol=operands if op=='call' and operands.startswith('bpf_') else None))
    try:
        g.check_definedness(insns, targets or {}, None, g)
    except ValueError as error:
        if accepted or 'undefined native ABI' not in str(error): raise
        rows.append(dict(name=name,accepted=False,message=str(error)))
    else:
        assert accepted, name+' manufactured defined native bytes'
        rows.append(dict(name=name,accepted=True))

for name, (dst, size) in HELPER_FULL_WRITES.items():
    params = helper_prototypes()[name].arguments.split(',')
    regs = ('rdi','rsi','rdx','rcx','r8')
    setup = ['push rbx']
    for i in range(len(params)):
        if i == dst: setup.append('mov '+regs[i]+', rsp')
        elif i == size: setup.append('mov '+regs[i]+', 4')
        elif i != 0 or name in {'bpf_probe_read','bpf_probe_read_user','bpf_probe_read_kernel','bpf_copy_from_user','bpf_get_current_comm'}:
            setup.append('mov '+regs[i]+', 0')
    prefix = '; '.join(setup+['call '+name])
    check(name+'_written4', prefix+'; mov eax, DWORD PTR [rsp]; add rsp, 8; ret', True)
    check(name+'_suffix_opaque', prefix+'; mov rax, QWORD PTR [rsp]; shr rax, 32; add rsp, 8; ret', False)

for name in ('bpf_probe_read_kernel_str','bpf_probe_read_user_str'):
    check(name+'_suffix', 'push rbx; mov rdi, rsp; mov esi, 8; mov edx, 0; call '+name+
          '; mov eax, DWORD PTR [rsp+4]; add rsp, 8; ret', False)

check('probe_copies_opaque', 'push rbx; push rax; mov rdi, rsp; mov esi, 8; lea rdx, [rsp+8]; call bpf_probe_read_kernel; mov eax, DWORD PTR [rsp]; add rsp, 16; ret',False)
check('probe_copies_defined_prefix', 'push rbx; mov DWORD PTR [rsp], 7; push rax; mov rdi, rsp; mov esi, 8; lea rdx, [rsp+8]; call bpf_probe_read_kernel; mov eax, DWORD PTR [rsp]; add rsp, 16; ret',True)
check('probe_preserves_opaque_copy_suffix', 'push rbx; mov DWORD PTR [rsp], 7; push rax; mov rdi, rsp; mov esi, 8; lea rdx, [rsp+8]; call bpf_probe_read_kernel; mov rax, QWORD PTR [rsp]; shr rax, 32; add rsp, 16; ret',False)
body = 'push rbx; mov rdi, rsp; mov esi, 8; mov edx, 0; call r12; mov eax, DWORD PTR [rsp]; add rsp, 8; ret'
check('all_targets_must_write',body,False,{4:(('scalar',113),('scalar',7))})
check('both_probe_targets_write',body,True,{4:(('scalar',113),('scalar',112))})
# A join may point to native private stack or external memory. Keep every
# possible stack origin: neither a load nor a weak store may erase ABI taint.
check('joined_external_defined_stack',
      'push rbx; mov QWORD PTR [rsp], 7; mov rcx, rdi; test edi, edi; je 6; mov rcx, rsp; mov rax, QWORD PTR [rcx]; add rsp, 8; ret',True)
check('joined_external_opaque_stack',
      'push rbx; mov rcx, rdi; test edi, edi; je 5; mov rcx, rsp; mov rax, QWORD PTR [rcx]; add rsp, 8; ret',False)
check('joined_store_cannot_initialize_other_path',
      'push rbx; mov rcx, rdi; test edi, edi; je 5; mov rcx, rsp; mov QWORD PTR [rcx], 7; mov rax, QWORD PTR [rsp]; add rsp, 8; ret',False)
check('joined_store_cannot_escape_opaque_bits',
      'push rbx; mov rcx, rdi; test edi, edi; je 5; mov rcx, rsp; mov QWORD PTR [rcx], rbx; mov eax, 2; add rsp, 8; ret',False)
check('joined_two_stack_origins_keep_opaque_alternative',
      'push rbx; push rbx; mov QWORD PTR [rsp], 7; mov rcx, rsp; lea rdx, [rsp+8]; test edi, edi; cmove rcx, rdx; mov rax, QWORD PTR [rcx]; add rsp, 16; ret',False)
check('joined_two_defined_stack_origins',
      'push rbx; push rbx; mov QWORD PTR [rsp], 7; mov QWORD PTR [rsp+8], 9; mov rcx, rsp; lea rdx, [rsp+8]; test edi, edi; cmove rcx, rdx; mov rax, QWORD PTR [rcx]; add rsp, 16; ret',True)
check('joined_copy_source_keeps_opaque_stack_bits',
      'mov rdx, rdi; push rbx; test edi, edi; je 5; mov rdx, rsp; push rax; mov rdi, rsp; mov esi, 8; call bpf_probe_read_kernel; mov rax, QWORD PTR [rsp]; add rsp, 16; ret',False)
check('joined_copy_source_defined_on_every_path',
      'mov rdx, rdi; push rbx; mov QWORD PTR [rsp], 7; test edi, edi; je 6; mov rdx, rsp; push rax; mov rdi, rsp; mov esi, 8; call bpf_probe_read_kernel; mov rax, QWORD PTR [rsp]; add rsp, 16; ret',True)
(HERE/'helper-effects-regression.json').write_text(json.dumps(rows,indent=2)+'\n')
print('helper memory effect regressions:',len(rows),'passed')
