"""Detect lost source subprogram arguments/callee-saved values on CPU and bound KVM."""
import ctypes
import json
import os
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/anonymous-source')
PREFIX=sys.argv[2] if len(sys.argv)==3 else ''
OUT=HERE/(PREFIX+'source-call-results');OUT.mkdir(exist_ok=True)
CASES={PREFIX+name:expected for name,expected in {'five_args':165,'saved_r6':177,'backwards':165}.items()}

def run(args,**kwargs):
    result=subprocess.run(list(map(str,args)),capture_output=True,text=True,timeout=120,**kwargs)
    with (OUT/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(command=list(map(str,args)),returncode=result.returncode,
                                    stdout=result.stdout,stderr=result.stderr))+'\n')
    if result.returncode:raise RuntimeError(result.stderr or result.stdout)
    return result

if sys.argv[1]=='cpu':
    for name,expected in CASES.items():
        shared=OUT/(name+'.so')
        run(['cc','-shared',HERE/'startup-lift'/name/'entry.native.o','-o',shared])
        function=ctypes.CDLL(str(shared)).bpf_main
        function.argtypes=[ctypes.c_void_p];function.restype=ctypes.c_uint64
        actual=function(None)
        if actual!=expected:raise RuntimeError((name,actual,expected))
        print(name,'actual CPU',actual,'PASS',flush=True)
elif sys.argv[1]=='bound':
    entries=json.loads((HERE/'anonymous-startup-results/manifest.json').read_text())['objects']
    for name in CASES:
        entry=json.loads((HERE/'startup-lift'/name/'manifest-entry.json').read_text())
        entries.append(dict(entry,prog_type=1))
    manifest=OUT/'manifest.json';manifest.write_text(json.dumps(dict(objects=entries),indent=2)+'\n')
    for name,expected in CASES.items():
        directory=OUT/name;directory.mkdir(exist_ok=True)
        env=dict(os.environ,LD_PRELOAD=str(SOURCE/'shim-after.so'),BPFREJIT_SHIM_NATIVE_LOADER='1',
            BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',BPFREJIT_SHIM_NATIVE_MANIFEST=str(manifest),
            BPFREJIT_NATIVE_LINK_BINARY=str(ROOT/'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link'),
            BPFREJIT_NATIVE_LOADER_SO=str(SOURCE/'build/libnative_loader.so'),
            BPFREJIT_SHIM_DIR=str(directory),BPFREJIT_SHIM_LOG=str(directory/'shim.log'),
            BPFREJIT_SHIM_SOCK_DIR=str(directory/'sockets'))
        result=run([HERE/'anonymous-startup',HERE/'source-call-inputs'/(name.removeprefix(PREFIX)+'.bpf.bin'),expected],env=env)
        if 'nonzero_generations=1' not in result.stdout:raise RuntimeError(result.stdout)
        print(name,result.stdout.strip(),'PASS',flush=True)
else:raise SystemExit('expected cpu or bound')
