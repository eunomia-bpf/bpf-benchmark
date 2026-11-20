"""Exercise the imported LPM instruction stream in the actual P-to-B API."""
import importlib.util
import json
from pathlib import Path
import shutil
import sys
import tarfile
import traceback

root=Path('/workspaces/repository');raw=Path(sys.argv[1])
tmp=Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')
generation=tmp/'generation'
if generation.exists():
    with tarfile.open(raw/'previous-generated.tar.gz','w:gz') as archive:
        archive.add(generation,arcname='generation')
    shutil.rmtree(generation)
spec=importlib.util.spec_from_file_location('lpm_specializer',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
maps=[dict(name=name,map_type=11,key_size=16,value_size=8,max_entries=64,map_flags=1,value_offset=None)
      for name in ['map_a','map_b']]
try:
    result=module.specialize((tmp/'fixed-entry.o').read_bytes(),'entry',
        dict(prog_type=2,section='kprobe/lpm_fixture',maps=maps),generation,
        root/'kprog/x86/native_lab/native_link/target/release/native-link',
        kernel_btf='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux',
        bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
    row=dict(status='generated',artifact=result)
except Exception:
    row=dict(status='failed',traceback=traceback.format_exc())
(raw/'generation.json').write_text(json.dumps(row,indent=2,default=str)+'\n')
with tarfile.open(raw/'generation-evidence.tar.gz','w:gz') as archive:
    archive.add(tmp/'fixed-entry.o',arcname='source-P.o')
    archive.add(generation,arcname='generation')
print(row['status'],flush=True)
sys.exit(int(row['status']=='failed'))
