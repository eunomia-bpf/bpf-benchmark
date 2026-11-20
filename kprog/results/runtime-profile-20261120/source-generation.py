"""Check that source probe inlining reaches the existing P-to-B pipeline."""
import importlib.util
import json
import os
from pathlib import Path
import shutil
import sys
import tarfile
import traceback

root=Path('/workspaces/repository')
os.environ['CLANG']=str(root/'kprog/stock-path/bin/clang')
raw=Path(sys.argv[1]); raw.mkdir(parents=True,exist_ok=True)
tmp=Path('/var/tmp/kprog-tmp/perf/runtime-profile-user')
spec=importlib.util.spec_from_file_location('source_probe_specializer',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
generation=tmp/'generation'
if generation.exists():
    with tarfile.open(raw/'previous-generated.tar.gz','w:gz') as archive:
        archive.add(generation,arcname='generation')
    shutil.rmtree(generation)
rows=[]
for name in ['user8','compat','kernel8','kernel_dynamic','kernel_str8','kernel_str_dynamic']:
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
