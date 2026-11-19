"""Check original integer identities fold while address/memory barriers survive."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
topic = root / 'kprog/results/native-integer-identities-20261119'
out = Path(sys.argv[1])
folded = sys.argv[2] == 'folded'
out.mkdir(parents=True, exist_ok=True)
commands = []


def run(args):
    command = [str(arg) for arg in args]
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
    return result.stdout


run(['clang-18', '-target', 'bpf', '-O1', '-g', '-emit-llvm', '-c',
     topic / 'fixture.c', '-o', out / 'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',
     out / 'input.bc', '-o', out / 'native.bc'])
ir = run(['llvm-dis-18', out / 'native.bc', '-o', '-'])
(out / 'native.ll').write_text(ir)


def body(text, name):
    return text.split('@' + name + '(', 1)[1].split('\n}', 1)[0]


for name in ['identity_constant', 'identity_live']:
    assert ('asm sideeffect' not in body(ir, name)) == folded
    if folded:
        assert 'freeze i64' in body(ir, name)
for name in ['pointer_identity', 'clobber_identity', 'memory_barrier']:
    assert 'asm sideeffect' in body(ir, name)
assert body(ir, 'memory_load').count('asm sideeffect "", "=r,0"') == 1
assert 'load volatile i64' in body(ir, 'memory_load')
run(['clang-18', '-O3', '-mno-red-zone', '-mgeneral-regs-only', '-S',
     '-emit-llvm', out / 'native.bc', '-o', out / 'optimized.ll'])
optimized = (out / 'optimized.ll').read_text()
assert ('ret i64 15' in body(optimized, 'identity_constant')) == folded
run(['clang-18', '-O3', '-mno-red-zone', '-mgeneral-regs-only', '-c',
     out / 'native.bc', '-o', out / 'native.o'])
run(['gcc', '-O3', '-fsanitize=undefined', '-fno-sanitize-recover=all',
     topic / 'driver.c', out / 'native.o', '-o', out / 'execute'])
result = run([out / 'execute'])
(out / 'summary.json').write_text(json.dumps(dict(
    mode=sys.argv[2], result=result, constant_folded=folded,
    pointer_and_memory_barriers_retained=True, generated_address_barrier_retained=True,
    scope='Host compiler identity/effect contract; no stock acceptance or app timing.'
), indent=2) + '\n')
print(result, end='')
