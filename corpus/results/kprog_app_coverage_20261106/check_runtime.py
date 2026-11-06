"""Check real shim startup: bound execution, missing proof and missing entry."""
import json
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
OUT = HERE/'verified-runtime'
OUT.mkdir(exist_ok=True)
entry = dict(program='runtime_source',
             native_object=str(HERE/'pushpop-build/imm8_positive.proof.o'),
             symbol='imm8_positive_native',
             simulator_object=str(HERE/'pushpop-build/imm8_positive.bpf.o'),
             simulator_program='imm8_positive_x86_sim_xdp')
rows = []
for name, objects, code, message in (
    ('bound', [entry], 0, 'nonzero_generations=1 invocations=1 retval=127'),
    ('missing-proof', [{k:v for k,v in entry.items() if not k.startswith('simulator_')}],
     97, 'requires a generation-bound simulator proof'),
    ('missing-entry', [dict(entry,program='different_program')], 97, 'has no manifest entry'),
    ('old-abi', [entry], 97, 'requires native-loader bound-proof ABI version 1'),
):
    manifest = OUT/(name+'.manifest.json')
    manifest.write_text(json.dumps(dict(objects=objects),indent=2)+'\n')
    log = OUT/(name+'.shim.log')
    env = dict(os.environ, LD_PRELOAD=str(HERE/'verified-runtime-shim.so'),
               BPFREJIT_SHIM_NATIVE_LOADER='1', BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
               BPFREJIT_SHIM_NATIVE_MANIFEST=str(manifest),
               BPFREJIT_NATIVE_LINK_BINARY=str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'),
               BPFREJIT_NATIVE_LOADER_SO=str(ROOT/'kprog/libnativeloader/build-capplication/libnative_loader.so'),
               BPFREJIT_SHIM_DIR=str(OUT/name), BPFREJIT_SHIM_LOG=str(log),
               BPFREJIT_SHIM_SOCK_DIR=str(OUT/name/'sockets'))
    command = [str(OUT/'startup'),str(OUT/'source.bpf.o')]
    if name == 'old-abi':
        env['BPFREJIT_NATIVE_LOADER_SO'] = '/lib/x86_64-linux-gnu/libc.so.6'
    result = subprocess.run(command,env=env,text=True,capture_output=True,timeout=90)
    row = dict(name=name,command=command,returncode=result.returncode,
               stdout=result.stdout,stderr=result.stderr)
    (OUT/(name+'.json')).write_text(json.dumps(row,indent=2)+'\n')
    print(name,'returncode',result.returncode,flush=True)
    assert result.returncode == code, row
    assert message in result.stdout+result.stderr+log.read_text(), row
    rows.append(row)
(OUT/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
