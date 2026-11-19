"""Exercise the actual B IR compiler and BPF backend on constant ALU32 moves."""
import json
from pathlib import Path
import re
import subprocess
import sys

bounds, out, mode = Path(sys.argv[1]), Path(sys.argv[2]), sys.argv[3]
out.mkdir(parents=True, exist_ok=True)
commands = []
def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    result.check_returncode()
    return result.stdout

fixture = Path(__file__).with_name('fixture.ll')
run([bounds, fixture, '-o', out/'lowered.bc'])
ir = run(['llvm-dis-18', out/'lowered.bc', '-o', '-'])
(out/'lowered.ll').write_text(ir)
for name, value in dict(constant8=8, constant4=4, constant_negative=-1,
                        constant_high=-2147483648).items():
    body = re.search(r'define i32 @'+name+r'\(\).*?^}', ir, re.S|re.M)[0]
    if mode == 'baseline':
        assert 'asm sideeffect "$0 = $0", "=w,0"' in body, body
    else:
        assert 'asm' not in body and f'ret i32 {value}' in body, body
for name in ['live', 'memory_clobber', 'wide']:
    body = re.search(r'define i\d+ @'+name+r'\(.*?^}', ir, re.S|re.M)[0]
    assert 'asm sideeffect "$0 = $0"' in body, body
run(['llc-18', '-O1', '-march=bpf', '-mcpu=v4', '-filetype=obj', out/'lowered.bc', '-o', out/'fixture.o'])
(out/'fixture.asm').write_text(run(['llvm-objdump-18', '-d', out/'fixture.o']))
(out/'result.json').write_text(json.dumps(dict(mode=mode, constants=4,
    live_clobber_wide_preserved=3, bpf_object_emitted=True,
    scope='Compiler IR and BPF emission regression; no stock or app timing claim.'), indent=2)+'\n')
print('Four constant cases and three preservation cases pass; BPF object emitted.')
