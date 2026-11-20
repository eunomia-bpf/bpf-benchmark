"""Check that source probe inlining reaches the existing P-to-B pipeline."""
import importlib.util
import json
from pathlib import Path
import sys
import traceback

root=Path('/workspaces/repository')
raw=Path(sys.argv[1]); raw.mkdir(parents=True,exist_ok=True)
tmp=Path('/var/tmp/kprog-tmp/perf/runtime-profile-user')
spec=importlib.util.spec_from_file_location('source_probe_specializer',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
rows=[]
for name in ['user8','compat']:
    try:
        result=module.specialize((tmp/'user.o').read_bytes(),name,
            dict(prog_type=2,section='kprobe/source_probe',maps=[]),tmp/'generation'/name,
            root/'kprog/x86/native_lab/native_link/target/release/native-link',
            kernel_btf='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux',
            bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
        row=dict(symbol=name,status='generated',artifact=result)
    except Exception:
        row=dict(symbol=name,status='failed',traceback=traceback.format_exc())
    rows.append(row)
    (raw/'source-generation.json').write_text(json.dumps(rows,indent=2,default=str)+'\n')
    print(name,row['status'],flush=True)
sys.exit(int(any(row['status']=='failed' for row in rows)))
