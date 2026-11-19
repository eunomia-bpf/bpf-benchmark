"""Compile the changed simulator for retained Tetragon P through normal O1."""
from datetime import datetime, timezone
import fcntl
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile
import time

root=Path('/workspaces/repository')
sys.path[0]=str(root/'kprog/x86')
import trusted_specializer as adapter

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
retained=Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/'
              'production-20261119T063707Z-211523/tetragon6')
capsule=Path('/workspaces/kprog-raw/verified/20261118-checked-hot/'
             'tetragon-c/state/session-4u0ra04z/requests/6.success.tar.gz')
commands=[]
def run(command):
    command=list(map(str,command))
    lease=None
    if command[0]=='/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds':
        lease=open('/workspaces/.agent-state/kprog-lanes/locks/image','a')
        fcntl.flock(lease,fcntl.LOCK_SH)
    started=datetime.now(timezone.utc).isoformat()
    (out/'progress.json').write_text(json.dumps(dict(command=command,started=started))+'\n')
    begin=time.monotonic()
    try:
        p=subprocess.run(command,text=True,capture_output=True)
    finally:
        if lease is not None:lease.close()
    commands.append(dict(command=command,started=started,seconds=time.monotonic()-begin,
        returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode()
    return p.stdout

with tarfile.open(capsule) as archive:
    metadata=json.load(archive.extractfile('request/generation.metadata.json'))
instructions,functions,exit_addr,rodata=adapter.gen.parse_native_linked_program('trusted_x86',retained)
source=adapter.gen.render_program('trusted_x86',instructions,functions,kind='raw',
    exit_addr=exit_addr,rodata16=rodata,program_section=metadata['section'],
    trusted_map_bindings=[dict(native_symbol=m['name'],value_offset=m.get('value_offset'))
                          for m in metadata['maps']])
source=source.replace('#include "../x86_sim_local_bpf.h"',
                      '#include '+json.dumps(str(root/'kprog/x86/x86_sim_local_bpf.h')))
path=out/'trusted_x86.bpf.c';path.write_text(source)
declaration=next(line for line in source.splitlines() if line.startswith('#define X86_SIM_STACK_VALUE_WORDS'))
(out/'generation.json').write_text(json.dumps(dict(retained_proof=str(retained/'trusted_x86.proof.o'),
    metadata_capsule=str(capsule),cache_words=[int(x) for x in re.findall(r'M\((\d+)\)',declaration)],
    source_bytes=path.stat().st_size,flags=list(map(str,adapter.COMPILE_FLAGS))),indent=2)+'\n')
obj=out/'trusted_x86.bpf.o'
adapter.compile_simulator(root/'kprog/stock-path/bin/clang',path,obj,run,
    bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
disassembly=run(['llvm-objdump-18','-d',obj])
(out/'b-disassembly.txt').write_text(disassembly)
(out/'result.json').write_text(json.dumps(dict(b_emitted=True,b_object_bytes=obj.stat().st_size,
    max_direct_r10_displacement=max([int(v,0) for v in re.findall(r'r10 - (0x[0-9a-f]+|[0-9]+)',disassembly)]+[0]),
    scope='Changed-C compilation for retained Tetragon P, normal O1/backend/packing; no stock acceptance, fresh producer/app coverage or timing claim.'),indent=2)+'\n')
