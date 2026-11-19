"""Fresh production B generation and native compile from retained real P."""
import ctypes as c
import io
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile
import time
ROOT=Path('/workspaces/repository');sys.path.insert(0,str(ROOT/'kprog/x86'))
from trusted_specializer import COMPILE_FLAGS, specialize, compile_checked_simulator
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
lib=c.CDLL('libbpf.so.1');lib.bpf_object__open_file.argtypes=[c.c_char_p,c.c_void_p];lib.bpf_object__open_file.restype=c.c_void_p
lib.libbpf_get_error.argtypes=[c.c_void_p];lib.libbpf_get_error.restype=c.c_long;lib.bpf_object__close.argtypes=[c.c_void_p]
assert '-O1' in COMPILE_FLAGS and '-O3' not in COMPILE_FLAGS
cases=sys.argv[2:] or ['bcc1','bcc7','tetragon6']
rows=[]
for name in cases:
    directory=out/name  # specialize owns creation of each fresh request directory
    (out/'progress.txt').write_text(name+' generation '+time.strftime('%Y-%m-%dT%H:%M:%SZ',time.gmtime())+'\n')
    if name.startswith('bcc'):
        with tarfile.open('/workspaces/kprog-raw/verified/20261118-deletion-check/bcc/service.tar.gz') as outer:
            packed=outer.extractfile('service/requests/'+name[3:]+'.success.tar.gz').read()
    else:
        packed=Path('/workspaces/kprog-raw/verified/20261118-checked-hot/tetragon-c/state/session-4u0ra04z/requests/6.success.tar.gz').read_bytes()
    with tarfile.open(fileobj=io.BytesIO(packed)) as request:
        native=request.extractfile('request/generated/request.native.o').read()
        metadata=json.load(request.extractfile('request/generation.metadata.json'))
        original=json.load(request.extractfile('request/generated/artifacts.json'))
    begin=time.perf_counter()
    artifacts=specialize(native,original['symbol'],metadata,directory,
        ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
        kernel_btf='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux',
        bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
    elapsed=time.perf_counter()-begin
    obj=Path(artifacts['simulator_object']);pointer=lib.bpf_object__open_file(str(obj).encode(),None)
    error=lib.libbpf_get_error(pointer)
    if not error:lib.bpf_object__close(pointer)
    row=dict(case=name,symbol=original['symbol'],b_generation_seconds=elapsed,libbpf_open_error=error,
             b_flags=[str(x) for x in COMPILE_FLAGS],native_status='not compiled',stock_status='not run')
    rows.append(row);(out/'summary.json').write_text(json.dumps(rows,indent=2)+'\n');print(row,flush=True)
    assert error==0
    dis=subprocess.run(['llvm-objdump-18','-d',str(obj)],text=True,capture_output=True,check=True).stdout
    (directory/'B.asm').write_text(dis)
    row['max_direct_r10_displacement']=max([int(v,0) for v in re.findall(r'r10 - (0x[0-9a-f]+|[0-9]+)',dis)]+[0])
    (out/'progress.txt').write_text(name+' native '+time.strftime('%Y-%m-%dT%H:%M:%SZ',time.gmtime())+'\n')
    begin=time.perf_counter()
    result=compile_checked_simulator(artifacts,ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
        Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
    row['native_compile_seconds']=time.perf_counter()-begin
    row['native_status']='host compiled, not installed'
    commands=[json.loads(line) for line in (directory/'native-commands.jsonl').read_text().splitlines()]
    native_command=next(item['command'] for item in commands if '-target' in item['command'] and 'x86_64-linux-gnu' in item['command'] and '-emit-llvm' not in item['command'])
    assert '-O3' in native_command
    row['native_flags']=native_command[1:-4]
    (out/'summary.json').write_text(json.dumps(rows,indent=2)+'\n');print(name,'native O3 compiled',flush=True)
(out/'progress.txt').write_text('done '+time.strftime('%Y-%m-%dT%H:%M:%SZ',time.gmtime())+'\n')
