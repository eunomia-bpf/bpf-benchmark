"""Exercise the real shim context C ABI with a nonzero BPF load flag."""
import json
import os
from pathlib import Path
import subprocess
import shutil
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=HERE/'context-runtime';OUT.mkdir(exist_ok=True)
manifest=OUT/'manifest.json'
manifest.write_text(json.dumps(dict(objects=[dict(program='runtime_source',
    native_object=str(HERE/'pushpop-build/imm8_positive.proof.o'),symbol='imm8_positive_native',
    simulator_object=str(HERE/'pushpop-build/imm8_positive.bpf.o'),simulator_program='imm8_positive_x86_sim_xdp')]),indent=2)+'\n')
for name,flags in [('flags-zero',0),('flags-freq',8)]:
    log=OUT/(name+'.shim.log')
    env=dict(os.environ,LD_PRELOAD=str(HERE/'context-runtime-shim.so'),
        BPFREJIT_SHIM_NATIVE_LOADER='1',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
        BPFREJIT_SHIM_NATIVE_MANIFEST=str(manifest),
        BPFREJIT_NATIVE_LINK_BINARY=str(HERE/'native-dispatch-link/release/native-link'),
        BPFREJIT_NATIVE_LOADER_SO=str(ROOT/'kprog/libnativeloader/build-ccontext/libnative_loader.so'),
        BPFREJIT_SHIM_DIR=str(OUT/name),BPFREJIT_SHIM_LOG=str(log),BPFREJIT_SHIM_SOCK_DIR=str(OUT/name/'sockets'))
    command=[str(OUT/'startup'),str(OUT/'source.bpf.o'),str(flags)]
    result=subprocess.run(command,env=env,text=True,capture_output=True,timeout=120)
    row=dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
    (OUT/(name+'.json')).write_text(json.dumps(row,indent=2)+'\n')
    print(name,result.returncode,result.stdout,result.stderr,flush=True)
    assert result.returncode==0 and 'nonzero_generations=1 invocations=1 retval=127' in result.stdout,row
    assert f'source-context flags={flags} token_fd=-1' in log.read_text(),log

# An actual older bound-proof library has ABI version1 but lacks the context
# export. A fatal dlsym failure must precede any old-entry/native fallback.
legacy=OUT/'input/legacy-libnative_loader.so'
shutil.copy2(ROOT/'kprog/libnativeloader/build-capplication/libnative_loader.so',legacy)
name='missing-context-export'
log=OUT/(name+'.shim.log')
env.update(BPFREJIT_NATIVE_LOADER_SO=str(legacy),
    BPFREJIT_SHIM_DIR=str(OUT/name),BPFREJIT_SHIM_LOG=str(log),
    BPFREJIT_SHIM_SOCK_DIR=str(OUT/name/'sockets'))
command=[str(OUT/'startup'),str(OUT/'source.bpf.o'),'8']
result=subprocess.run(command,env=env,text=True,capture_output=True,timeout=120)
(OUT/(name+'.json')).write_text(json.dumps(dict(command=command,
    returncode=result.returncode,stdout=result.stdout,stderr=result.stderr),indent=2)+'\n')
print(name,result.returncode,result.stdout,result.stderr,flush=True)
assert result.returncode==97,result
assert 'dlsym failed:' in log.read_text() and 'native_loader_load_from_fd_with_manifest_path_btf_and_context' in log.read_text(),log
