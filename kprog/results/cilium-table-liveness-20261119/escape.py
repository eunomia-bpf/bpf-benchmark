"""Actual native counterexample to spill elision from readback liveness alone."""
import ctypes
import fcntl
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter
from x86_relative_tables import private_results_dead

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
build = Path('/var/tmp/kprog-tmp/perf/cilium-private-spill'); build.mkdir(parents=True, exist_ok=True)
commands = []
def run(command):
    command = list(map(str, command))
    process = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=process.returncode,
                         stdout=process.stdout, stderr=process.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    process.check_returncode()

source = Path(__file__).with_name('escape.S')
run(['clang-18', '-c', source, '-o', build/'escape.o'])
run(['clang-18', '-shared', build/'escape.o', '-o', build/'escape.so'])
native = ctypes.CDLL(str(build/'escape.so'))
rows = []
with open('/workspaces/.agent-state/kprog-lanes/locks/image', 'a') as lock:
    fcntl.flock(lock, fcntl.LOCK_SH)
    for name in ('escaped_before', 'private_only'):
        directory = out/name; directory.mkdir(exist_ok=True)
        run([root/'kprog/x86/native_lab/native_link/target/release/native-link',
             '--input', build/'escape.o', '--symbol', name, '--mode', 'proof',
             '--preserve-entry-abi', '--output', directory/'fixture.proof.o'])
        instructions, functions, exit_addr, _ = adapter.gen.parse_native_linked_program('fixture', directory)
        assert not functions, functions
        following = {a.addr: b.addr for a, b in zip(instructions, instructions[1:])}
        readback = next(i for i in instructions if i.mnemonic == 'mov' and i.operands[0] == 'esi'
                        and adapter.gen.is_mem(i.operands[1]))
        readback_dead = private_results_dead(instructions, [following[readback.addr]],
            ('X86_RSI',), 0, adapter.gen, exit_addr, {}, {}, initial=(0xffffff00, 0))
        assert readback_dead, name
        partial = next(i for i in instructions if i.mnemonic == 'mov' and i.operands[0] == 'al')
        original_store_dead = private_results_dead(instructions, [partial.addr],
            ('X86_RAX',), 0, adapter.gen, exit_addr, {}, {})
        if name == 'escaped_before':
            assert not original_store_dead, 'the escaped spill is an observable definition'
        incoming = {}
        adapter.gen.check_definedness(instructions, {}, exit_addr, adapter.gen, incoming_states=incoming)
        regs = tuple(dict.fromkeys(info[0] for info in adapter.gen.REGS.values())) + ('X86_XMM0',)
        rcx = regs.index('X86_RCX')
        escaped = [i for i in instructions if i.mnemonic == 'mov'
                   and i.operands == ('QWORD PTR [rdi]', 'rcx')]
        if escaped:
            aliases = [s.aliases[rcx] for (_, pc), s in incoming.items() if pc == escaped[0].addr]
            assert aliases and all(type(alias) is int for alias in aliases), aliases
        function = getattr(native, name)
        function.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.c_uint32]
        function.restype = ctypes.c_uint32
        observed = []
        for value in (0, 0x12345600, 0xdeadbe00, 0xffffff00):
            holder = ctypes.c_void_p()
            result = function(ctypes.byref(holder), value)
            expected = (value & 0xffffff00) | 5 if escaped else 5
            assert result == expected, (name, value, result, expected)
            observed.append(dict(input=value, result=result))
        assert (len({row['result'] for row in observed}) > 1) == bool(escaped), observed
        rows.append(dict(name=name, local_readback_upper_bits_dead=readback_dead,
                         original_store_dead=original_store_dead,
                         pointer_escaped_before_spill=bool(escaped), native=observed))
(out/'result.json').write_text(json.dumps(dict(cases=rows,
    scope='Actual native execution and bound proof-effect liveness; the escaped case proves local readback liveness alone cannot justify spill elision. No production lowering or stock acceptance.'), indent=2)+'\n')
print(json.dumps(rows), flush=True)
