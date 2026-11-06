"""Run an actual libbpf object startup including every successful probe it loads."""
import json
import os
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/anonymous-source')
OUT=HERE/sys.argv[1];OUT.mkdir()
raw=(HERE/'bpf-lift/zero.bpf.bin').read_bytes().hex()
zero=dict(program='',prog_type=1,source_bytecode_hex=raw,
    native_object=str(HERE/'bpf-lift/zero/zero.native.o'),symbol='bpf_main',
    simulator_object=str(HERE/'bpf-lift/zero.socket.bpf.o'),simulator_program='zero_socket_x86_sim_xdp')
entries=[zero,dict(zero,program='libbpf_nametest')]
for name,program,kind in [('object_coarse','',1),('object_arg_ctx','det_arg_ctx',2),('object_sock','',9)]:
    entry=json.loads((HERE/'startup-lift'/name/'manifest-entry.json').read_text())
    if name=='object_coarse' and 'KPROG_TEST_COARSE_NATIVE' in os.environ:
        entry.update(native_object=os.environ['KPROG_TEST_COARSE_NATIVE'],symbol=os.environ['KPROG_TEST_COARSE_SYMBOL'],
                     simulator_object=os.environ['KPROG_TEST_COARSE_SIM'],simulator_program=os.environ['KPROG_TEST_COARSE_PROGRAM'])
    entries.append(dict(entry,program=program,prog_type=kind))
entries.append(dict(program='runtime_source',prog_type=6,
    native_object=str(HERE/'pushpop-build/imm8_positive.proof.o'),symbol='imm8_positive_native',
    simulator_object=str(HERE/'pushpop-build/imm8_positive.bpf.o'),
    simulator_program='imm8_positive_x86_sim_xdp'))
manifest=OUT/'manifest.json';manifest.write_text(json.dumps(dict(objects=entries),indent=2)+'\n')
for name,flags in [('zero',0),('freq',8)]:
    directory=OUT/name;directory.mkdir(exist_ok=True)
    command=[str(HERE/'context-runtime/startup'),str(HERE/'context-runtime/source.bpf.o'),str(flags)]
    env=dict(os.environ,LD_PRELOAD=os.environ.get('KPROG_TEST_SHIM',str(SOURCE/'shim-after.so')),BPFREJIT_SHIM_NATIVE_LOADER='1',
        BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',BPFREJIT_SHIM_NATIVE_MANIFEST=str(manifest),
        BPFREJIT_NATIVE_LINK_BINARY=os.environ.get('KPROG_TEST_LINK',str(ROOT/'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link')),
        BPFREJIT_NATIVE_LOADER_SO=os.environ.get('KPROG_TEST_LOADER',str(SOURCE/'build/libnative_loader.so')),
        BPFREJIT_SHIM_DIR=str(directory),BPFREJIT_SHIM_LOG=str(directory/'shim.log'),
        BPFREJIT_SHIM_SOCK_DIR=str(directory/'sockets'))
    result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120)
    row=dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
    (directory/'result.json').write_text(json.dumps(row,indent=2)+'\n')
    print(name,result.returncode,result.stdout,result.stderr,flush=True)
    if result.returncode:raise RuntimeError(row)
    log=(directory/'shim.log').read_text()
    if 'skipped feature probe' in log or 'skipped internal' in log:raise RuntimeError('probe bypass')
    replaced=log.count('native-loader replaced prog=')
    loads=log.count('BPF_PROG_LOAD type=')
    if replaced!=loads or replaced!=6:raise RuntimeError((replaced,loads))
    print(name,'all',loads,'actual successful startup loads replaced with bound native programs',flush=True)
