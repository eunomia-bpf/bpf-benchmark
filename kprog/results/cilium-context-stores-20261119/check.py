"""Catch an unsafe broadening of the exact TC class-id store conversion."""
import json
from pathlib import Path
import re
import subprocess
import sys

root = Path('/workspaces/repository')
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter
out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
compiler = '/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'
commands = []
def run(command):
    command = list(map(str, command))
    p = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=p.returncode, stdout=p.stdout, stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode()
    return p.stdout

source = Path(__file__).with_name('fixture.c')
run([root/'kprog/stock-path/bin/clang', *adapter.COMPILE_FLAGS, '-DSELECTOR_CONTROLS',
     '-emit-llvm', '-c', source, '-o', out/'controls.bc'])
run([compiler, out/'controls.bc', '-o', out/'controls.lowered.bc'])
lowered = run(['llvm-dis-18', out/'controls.lowered.bc', '-o', '-'])
(out/'controls.lowered.ll').write_text(lowered)
bodies = {name:body for name,body in re.findall(r'define [^@]+@(\w+)\([^\n]*\).*?\{(.*?)^}',lowered,re.S|re.M)}
observed = {name:'*(u32 *)($0 + 72) = $1' in body for name,body in bodies.items()}
assert observed['class_store'], observed
assert not any(observed[name] for name in ('wrong_root','wrong_offset','wrong_section','wrong_width','variable_offset')), observed
run([root/'kprog/stock-path/bin/clang', *adapter.COMPILE_FLAGS,
     '-emit-llvm', '-c', source, '-o', out/'fixture.frontend.bc'])
run([compiler, out/'fixture.frontend.bc', '-o', out/'fixture.bounds.bc'])
adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang', out/'fixture.bpf.c',
    out/'fixture.bpf.o', run, compiled_input=out/'fixture.bounds.bc')
(out/'b-disassembly.txt').write_text(run(['llvm-objdump-18','-dl',out/'fixture.bpf.o']))
(out/'result.json').write_text(json.dumps(dict(selection=observed,b_emitted=True,
    scope='Actual store-selection boundaries and B emission; stock and app coverage separate.'),indent=2)+'\n')
print(json.dumps(observed),flush=True)
