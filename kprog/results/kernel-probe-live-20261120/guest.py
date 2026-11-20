"""Execute native program inputs with installed tools, without building tools."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository');base=Path('/workspaces/.agent-state/kprog-ck')
out=Path(sys.argv[1]);inputs=Path('/var/tmp/kprog-tmp/perf/kernel-probe-live')
client=root/'kprog/libnativeloader/build/trusted-service-client'
loader=base/'verified-loader/trusted-native-loader'
linker=root/'kprog/x86/native_lab/native_link/target/release/native-link'
names=['kernel-stack','kernel-null','kernel-user-address','kernel-fault',
       'kernel-zero-null','kernel-string-stack','kernel-string-null','kernel-string-fault',
       'kernel-zero-stack','compat-kernel-fault','user-null','user-zero-null']
tools=[client,loader,linker,base/'verified-compiler/compile-sim-ir']
(out/'tools.json').write_text(json.dumps({str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in tools},indent=2)+'\n')
rows=[]
for name,program in [('control',inputs/'control.o')]+[(name,inputs/f'case-{i}.o') for i,name in enumerate(names)]:
    directory=out/name;directory.mkdir(parents=True,exist_ok=True)
    argv=[sys.executable,root/'kprog/trusted_service.py','--arch','1',
        '--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer',
        '--module',base/'verified-module/bpf_x86_native_lab.ko',
        '--state',directory/'state','--results',directory/'service.tar.gz',
        '--native-link',linker,'--loader',loader,'--execution-mode','checked-sim-c',
        '--sim-native-compiler',base/'verified-compiler/compile-sim-ir',
        '--sim-context-compiler',base/'verified-compiler/context-lower',
        '--sim-public-layout',base/'verified-compiler/public-layout.json',
        '--sim-physical-layout',base/'verified-compiler/physical-layout.json',
        '--sim-bounds-compiler',base/'verified-compiler/packet-bounds',
        '--run',client,program]
    result=subprocess.run(list(map(str,argv)),capture_output=True,text=True)
    (directory/'stdout').write_text(result.stdout);(directory/'stderr').write_text(result.stderr)
    row=dict(name=name,program=str(program),command=list(map(str,argv)),returncode=result.returncode)
    rows.append(row);(out/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
    print(json.dumps(row),flush=True)
    if name=='control' and result.returncode:
        raise RuntimeError('Installed service client control failed; see control/stderr, no probe cases executed')
if any(row['returncode'] for row in rows):
    raise RuntimeError('Native probe cases failed; all attempted cases and logs retained')
