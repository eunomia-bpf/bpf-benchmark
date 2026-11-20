"""Generate B, then compile native C only after its actual stock acceptance."""
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository');here=Path(__file__).resolve().parent
out=Path(sys.argv[1]);stage=sys.argv[2];out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/hash-c-lto')
os.environ['CLANG']=str(root/'kprog/stock-path/bin/clang')
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
from inline_array import hash_layout
spec=importlib.util.spec_from_file_location('hash_specializer',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
def run(args):
    args=list(map(str,args));p=subprocess.run(args,capture_output=True,text=True)
    with (out/'production-commands.jsonl').open('a') as f:
        f.write(json.dumps(dict(command=args,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))+'\n')
    p.check_returncode();return p.stdout
linker=root/'kprog/x86/native_lab/native_link/target/release/native-link'
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
if stage=='generation':
    run([os.environ['CLANG'],'-O3','-march=native','-Xclang','-fembed-bitcode=all','-fPIC',
         '-mgeneral-regs-only','-mno-red-zone','-fomit-frame-pointer','-fno-stack-protector',
         '-c',here/'program.c','-o',build/'program.o'])
    maps=[dict(name='map_a',map_type=1,key_size=8,value_size=8,max_entries=64,map_flags=0,value_offset=None)]
    artifact=module.specialize((build/'program.o').read_bytes(),'hash_fixture',
        dict(prog_type=2,section='kprobe/hash_fixture',maps=maps),build/'generation',linker,
        kernel_btf=kernel,bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
    (build/'generation/fixture.json').write_text(json.dumps(dict(artifact=artifact),indent=2)+'\n')
    (out/'generation.json').write_text(json.dumps(artifact,indent=2)+'\n')
elif stage=='native':
    stock=json.loads((out/'stock-result.json').read_text());assert stock['verdict']['stock_loaded'],stock
    artifact=json.loads((build/'generation/fixture.json').read_text())['artifact']
    native=module.compile_checked_simulator(artifact,linker,
        Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
    layout=hash_layout(kernel)
    run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
         '-I'+str(root/'vendor/linux-framework/include'),
         *['-D'+k.upper()+'='+str(v) for k,v in layout.items()],
         here/'production_driver.c',native['native_object'],'-o',build/'production-execute'])
    result=run([build/'production-execute'])
    (out/'production-result.json').write_text(json.dumps(dict(native=native,layout=layout,execution=result.strip(),
        scope='Actual stock accepted B then installed native compiler API/host execution; no app/performance claim'),indent=2)+'\n')
    print(result,flush=True)
else:
    raise ValueError('unknown production stage: '+stage)
