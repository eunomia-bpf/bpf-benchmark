"""Check shared atomic operations survive the B and native compilation paths."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
out, build = map(Path, sys.argv[1:])
out.mkdir(parents=True, exist_ok=True)
build.mkdir(parents=True, exist_ok=True)
commands = []


def run(args):
    command = list(map(str, args))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out / 'shared-bpf-commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    if result.returncode:
        print(result.stderr, flush=True)
    result.check_returncode()
    return result.stdout


common = ['clang-18', '-target', 'bpf', '-O1', '-g', '-mcpu=v4',
          '-I' + str(root / 'vendor/libbpf/src'),
          '-I' + str(root / 'vendor/libbpf/include/uapi'),
          '-I/usr/include/x86_64-linux-gnu']
run(common + ['-emit-llvm', '-c', root / 'kprog/results/lock-prefix-review-20261119/shared_bpf.c',
              '-o', build / 'shared.bpf.bc'])
ir = run(['llvm-dis-18', build / 'shared.bpf.bc', '-o', '-'])
(out / 'shared.bpf.ll').write_text(ir)
assert 'atomicrmw' in ir and 'cmpxchg' in ir and 'seq_cst' in ir
run(['llc-18', '-O1', '-march=bpf', '-mcpu=v4', '-filetype=obj',
     build / 'shared.bpf.bc', '-o', build / 'shared.bpf.o'])
undefined = run(['llvm-nm-18', '--undefined-only', build / 'shared.bpf.o'])
assert not undefined.strip(), undefined
(out / 'shared.bpf.asm').write_text(run(['llvm-objdump-18', '-dr', build / 'shared.bpf.o']))
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',
     build / 'shared.bpf.bc', '-o', build / 'shared.native.bc'])
run(['clang-18', '-target', 'x86_64-unknown-linux-gnu', '-O3', '-mno-red-zone',
     '-mgeneral-regs-only', '-S', build / 'shared.native.bc', '-o', build / 'shared.native.s'])
native = (build / 'shared.native.s').read_text()
(out / 'shared.native.s').write_text(native)
for width in [4, 8]:
    for name in ['add', 'sub', 'adc', 'sbb', 'and', 'or', 'xor', 'inc', 'dec', 'not', 'neg']:
        body = native.split(f'{name}{width}:', 1)[1].split('.Lfunc_end', 1)[0]
        assert 'lock' in body, (name, width, body)
print('22 shared 32/64-bit operations compile through B and native; all native bodies retain LOCK')
