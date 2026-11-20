"""Check late C selection, machine-code semantics and the real compiler API."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository');raw,stock=map(Path,sys.argv[1:]);raw.mkdir(parents=True,exist_ok=True)
tmp=Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')
tool=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir')
here=root/'kprog/results/lpm-c-lto-20261120'
layout=json.loads((here/'report.json').read_text())['layout']
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
from inline_array import lookup_source
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'

def run(args,name):
    child=subprocess.run(list(map(str,args)),capture_output=True,text=True)
    text=child.stdout+child.stderr;(raw/(name+'.log')).write_text(text)
    child.check_returncode();return text

run(['clang-18','-target','bpf','-O1','-emit-llvm','-c',here/'post_b_fixture.c','-o',tmp/'post-b-input.bc'],'fixture-frontend')
rows=[]
for name,extra,expected in [('known',['--array-map','map_a','--array-map','map_b'],1),
                            ('unknown',[],2)]:
    source=tmp/'post-b-helpers.c';helpers=tmp/'post-b-helpers.txt';lowered=tmp/'post-b-native.bc'
    run([tool,tmp/'post-b-input.bc','-o',lowered,'--helper-list',helpers,*extra],name+'-lower')
    selected=helpers.read_text().splitlines()
    assert selected==(['__kprog_array_lookup'] if name=='known' else []),selected
    if selected:
        source.write_text(lookup_source(kernel,[('map_a',16),('map_b',16)]))
        (raw/(name+'-helper.c')).write_text(source.read_text())
        run(['clang-18','-O3','-mgeneral-regs-only','-emit-llvm','-c',source,'-o',tmp/'post-b-helpers.bc'],name+'-helpers')
        run(['llvm-link-18',lowered,tmp/'post-b-helpers.bc','-o',tmp/'post-b-linked.bc'],name+'-link')
        lowered=tmp/'post-b-linked.bc'
    obj=tmp/'post-b.o'
    run(['clang-18','-O3','-march=native','-mgeneral-regs-only','-mno-red-zone','-fomit-frame-pointer',
         '-fno-stack-protector','-c',lowered,'-o',obj],name+'-native')
    exe=tmp/'post-b-execute'
    run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
         *(['-DFIXED_KEY'] if name=='known' else []),'-DEXPECTED_GENERIC='+str(expected),
         *['-D'+k+'='+str(v) for k,v in layout.items()],here/'driver.c',obj,'-o',exe],name+'-driver')
    execution=run([exe],name+'-execution')
    rows.append(dict(name=name,selected=selected,execution=execution.strip()))

verdict=json.loads((stock/'stock-result.json').read_text())['verdict'];assert verdict['stock_loaded']
artifact=json.loads((tmp/'generation/fixture.json').read_text())['artifact']
spec=importlib.util.spec_from_file_location('post_b_specializer',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
native=module.compile_checked_simulator(artifact,root/'kprog/x86/native_lab/native_link/target/release/native-link',tool)
helpers=(tmp/'generation/checked-simulator.helpers.txt').read_text().splitlines()
assert '__kprog_array_lookup' in helpers,helpers
exe=tmp/'post-b-production-execute'
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
     *['-D'+k+'='+str(v) for k,v in layout.items()],here/'post_b_driver.c',native['native_object'],'-o',exe],'production-driver')
result=run([exe],'production-execution')
(raw/'report.json').write_text(json.dumps(dict(fixture=rows,stock=str(stock),stock_verdict=verdict,
    production_helpers=helpers,production_execution=result.strip(),native=native,
    scope='Stock acceptance then actual native compiler API and host C-provider semantics; application installation and timing remain pending.'),indent=2)+'\n')
print(json.dumps(dict(fixture=rows,production_helpers=helpers,production_execution=result.strip()),indent=2))
