"""Catch classifier/asm/word-identity/headlen gaps and overbroad field matches."""
import json
from pathlib import Path
import re
import subprocess
import sys

root=Path('/workspaces/repository')
sys.path[0]=str(root/'kprog/x86')
import trusted_specializer as adapter
out=Path(sys.argv[1]); out.mkdir(parents=True,exist_ok=True)
mode=sys.argv[2]
assert mode in ('before','after'),mode
compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds')
commands=[]
def run(command):
    command=list(map(str,command))
    p=subprocess.run(command,text=True,capture_output=True)
    commands.append(dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode()
    return p.stdout

release=Path('/workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release').read_text().strip()
run(['clang-18','-fsyntax-only','-I'+str(root/'vendor/bpf/targets/x86'/release),Path(__file__).with_name('layout.c')])
source=Path(__file__).with_name('fixture.c')
run([root/'kprog/stock-path/bin/clang',*adapter.COMPILE_FLAGS,'-DSELECTOR_CONTROLS',
     '-emit-llvm','-c',source,'-o',out/'controls.bc'])
run([compiler,out/'controls.bc','-o',out/'controls.lowered.bc'])
lowered=run(['llvm-dis-18',out/'controls.lowered.bc','-o','-'])
(out/'controls.lowered.ll').write_text(lowered)
bodies={name:body for name,body in re.findall(r'define [^@]+@(\w+)\([^\n]*\).*?\{(.*?)^}',lowered,re.S|re.M)}
positive=['head_ge','head_gt','head_not_lt','head_not_le','head_wide','old_tc','old_xdp','asm_tc']
negative=['wrong_root','wrong_offset','wrong_section','equality','signed_negative']
observed={name:'packet_bound' in bodies[name] for name in positive+negative}
(out/'selection.json').write_text(json.dumps(observed,indent=2)+'\n')
if mode=='before':
    assert not any(observed[name] for name in positive[:5]+['asm_tc']),observed
else:
    assert all(observed[name] for name in positive),observed
assert not any(observed[name] for name in negative),observed
assert all(observed[name] for name in ['old_tc','old_xdp']),observed
if mode=='after':
    run([root/'kprog/stock-path/bin/clang',*adapter.COMPILE_FLAGS,'-emit-llvm','-c',source,'-o',out/'fixture.frontend.bc'])
    run([compiler,out/'fixture.frontend.bc','-o',out/'fixture.bounds.bc'])
    adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang',out/'fixture.bpf.c',
        out/'fixture.bpf.o',run,compiled_input=out/'fixture.bounds.bc')
    (out/'b-disassembly.txt').write_text(run(['llvm-objdump-18','-dl',out/'fixture.bpf.o']))
(out/'result.json').write_text(json.dumps(dict(mode=mode,selection=observed,
    b_emitted=mode=='after',scope='Actual IR selection boundaries and normal B emission; no stock or current-app pass.'),indent=2)+'\n')
print(json.dumps(observed),flush=True)
