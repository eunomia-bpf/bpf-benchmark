"""Catch cross-function RET edges, lost context unions and unknown-set narrowing."""
import ctypes
import fcntl
import json
from pathlib import Path
import re
import subprocess
import sys

root = Path('/workspaces/repository')
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter
gen = adapter.gen
tools = Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)

def instructions(start, assembly):
    result = []
    for pc, text in enumerate(assembly, start):
        op, args = text.split(' ', 1) if ' ' in text else (text, '')
        result.append(gen.NativeInsn(pc, text, op, gen.split_operands(args)))
    return result

main = instructions(0, ['mov ebx,DWORD PTR [rdi]', 'call 0x20', 'test ebx,ebx',
    'je 0x8', 'add rax,1', 'call 0x40', 'add rax,2', 'jmp 0x9', 'add rax,3', 'ret'])
functions = dict(a=instructions(0x20, ['test ebx,ebx', 'je 0x24', 'call 0x40',
    'ret', 'mov eax,10', 'ret']), b=instructions(0x40, ['mov eax,20', 'ret']))

def render(functions):
    sites, by_pc = set(), {}
    gen.check_definedness([*main, *(i for fn in functions.values() for i in fn)],
        {}, None, gen, return_sites=sites, return_sites_by_pc=by_pc)
    source = gen.render_program('returns', main, functions, kind='raw', program_section='kprobe/trusted')
    dispatches = {label: [int(v, 16) for v in re.findall(r'case 0x([0-9a-f]+)ULL:', body)]
        for label, body in re.findall(r'(x86_sim_ret_dispatch_[0-9a-f]+):\n\tswitch \(__x86_sim_ret_addr\) \{(.*?)\n\t}', source, re.S)}
    return sites, by_pc, source, dispatches

sites, by_pc, source, dispatches = render(functions)
assert sites == {2, 6, 0x23}, sites
assert by_pc[0x23] == by_pc[0x25] == {2}, by_pc
assert by_pc[0x41] == {6, 0x23}, by_pc
assert sorted(dispatches.values()) == [[2], [6, 0x23]], dispatches
assert source.count('X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch_23);') == 2
assert source.count('default: __x86_sim_unresolved_indirect_target();') == 2
rows = [dict(case='nested_and_multiple_returns', dispatches=dispatches)]

# Both analysis arrival orders must let an unknown saved address dominate.
for unknown_first in (False, True):
    branch = ['mov QWORD PTR [rsp],rdi', 'jmp 0x25', 'nop'] if unknown_first else [
        'nop', 'jmp 0x25', 'mov QWORD PTR [rsp],rdi']
    changed = dict(functions, a=instructions(0x20, ['test ebx,ebx', 'je 0x24',
        *branch, 'mov eax,10', 'ret']))
    union, local, _, tables = render(changed)
    assert local[0x26] is None, local
    assert tables['x86_sim_ret_dispatch_26'] == sorted(union), tables
    rows.append(dict(case='unknown_first' if unknown_first else 'unknown_last', dispatches=tables))

# A sibling helper's JMP consumes the same saved native return address.
tail = gen.NativeInsn(0x20, 'jmp bpf_get_prandom_u32', 'jmp', ('0x0',),
                     reloc_symbol='bpf_get_prandom_u32')
_, local, _, tables = render(dict(functions, a=[tail]))
assert local[0x20] == {2} and tables['x86_sim_ret_dispatch_20'] == [2], (local, tables)
rows.append(dict(case='tail_helper', dispatches=tables))
(out/'selection.json').write_text(json.dumps(rows, indent=2)+'\n')

commands = []
def run(command):
    command = list(map(str, command))
    p = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=p.returncode, stdout=p.stdout, stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    p.check_returncode()
    return p.stdout

fixture = out/'returns.bpf.c'
fixture.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
    '#include '+json.dumps(str(root/'kprog/x86/x86_sim_local_bpf.h'))))
with open('/workspaces/.agent-state/kprog-lanes/locks/image', 'a') as lock:
    fcntl.flock(lock, fcntl.LOCK_SH)
    adapter.compile_simulator(root/'kprog/stock-path/bin/clang', fixture,
        out/'returns.bpf.o', run, bounds_compiler=tools/'packet-bounds')
    run([tools/'compile-sim-ir', fixture.with_suffix('.bounds-input.bc'), '-o', out/'native.bc'])
run(['clang-18', '-O3', '-shared', '-fPIC', '-mno-red-zone', '-mgeneral-regs-only',
     out/'native.bc', '-o', out/'execute.so'])
program = ctypes.CDLL(str(out/'execute.so')).returns_x86_sim_xdp
program.argtypes = [ctypes.c_void_p]; program.restype = ctypes.c_int
execution = []
for value in [0, 1, 0xffffffff]:
    context = ctypes.c_uint32(value)
    expected = 22 if value else 13
    actual = program(ctypes.byref(context))
    execution.append(dict(input=value, expected=expected, observed=actual))
    assert actual == expected, execution
(out/'result.json').write_text(json.dumps(dict(selection=rows, native_execution=execution,
    b_emitted=True, scope='Generator finite return sets, normal B emission and native execution; no stock/app/timing claim.'), indent=2)+'\n')
print(json.dumps(execution), flush=True)
