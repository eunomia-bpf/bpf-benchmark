"""Actual libbpf/shim/NativeLoader loads: no anonymous probe or reserved-name bypass."""
import json
import os
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/anonymous-source')
OUT=HERE/'anonymous-startup-results';OUT.mkdir(exist_ok=True)
entries=[]
for name in ('zero','one','clock'):
    entries.append(dict(program='',prog_type=1,
        source_bytecode_hex=(HERE/'bpf-lift'/(name+'.bpf.bin')).read_bytes().hex(),
        native_object=str(HERE/'bpf-lift'/name/(name+'.native.o')),symbol='bpf_main',
        simulator_object=str(HERE/'bpf-lift'/(name+'.socket.bpf.o')),
        simulator_program=name+'_socket_x86_sim_xdp'))
entries.append(dict(entries[0],program='native_lab_stub'))
entries.append(dict(entries[0],program='libbpf_nametest'))
coarse=json.loads((HERE/'startup-lift/coarse_call/manifest-entry.json').read_text())
entries.append(dict(coarse,prog_type=1))
manifest=OUT/'manifest.json';manifest.write_text(json.dumps(dict(objects=entries),indent=2)+'\n')

def run(name, case, before=False, program=None, manifest_path=manifest, expected_status=0):
    directory=OUT/name;directory.mkdir(exist_ok=True)
    expected={'zero':0,'one':1,'clock':1}[case]
    command=[str(HERE/'anonymous-startup'),str(HERE/'bpf-lift'/(case+'.bpf.bin')),str(expected)]
    if program is not None:command.append(program)
    env=dict(os.environ,LD_PRELOAD=str(SOURCE/('shim-before.so' if before else 'shim-after.so')),
        BPFREJIT_SHIM_NATIVE_LOADER='1',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
        BPFREJIT_SHIM_NATIVE_MANIFEST=str(manifest_path),
        BPFREJIT_NATIVE_LINK_BINARY=str(ROOT/'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link'),
        BPFREJIT_NATIVE_LOADER_SO=str(SOURCE/'build/libnative_loader.so'),
        BPFREJIT_SHIM_DIR=str(directory),BPFREJIT_SHIM_LOG=str(directory/'shim.log'),
        BPFREJIT_SHIM_SOCK_DIR=str(directory/'sockets'))
    result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120)
    row=dict(command=command,returncode=result.returncode,expected_status=expected_status,
             stdout=result.stdout,stderr=result.stderr)
    (directory/'result.json').write_text(json.dumps(row,indent=2)+'\n')
    print(name,result.returncode,result.stdout,result.stderr,flush=True)
    if result.returncode!=expected_status:raise RuntimeError(row)
    if expected_status==0 and 'nonzero_generations=1' not in result.stdout:raise RuntimeError(row)
    if before and 'nonzero_generations=0' not in result.stdout:raise RuntimeError(row)
    if not before and expected_status==0 and 'skipped feature probe' in (directory/'shim.log').read_text():
        raise RuntimeError('successful application probe was skipped')

run('before-anonymous','zero',before=True,expected_status=9)
run('before-name-collision','zero',before=True,program='native_lab_stub',expected_status=9)
for case in ('zero','one','clock'):run('after-'+case,case)
run('after-name-collision','zero',program='native_lab_stub')
missing=OUT/'missing-selector.json';missing.write_text(json.dumps(dict(objects=[{k:v for k,v in entries[0].items() if k!='source_bytecode_hex'}])))
run('missing-selector','zero',manifest_path=missing,expected_status=97)
wrong=OUT/'wrong-selector.json';wrong.write_text(json.dumps(dict(objects=entries[1:])))
run('wrong-selector','zero',manifest_path=wrong,expected_status=97)
print('anonymous startup generation binding PASS: 4 actual positive loads, 2 former bypasses, 2 fail-fast selectors',flush=True)
