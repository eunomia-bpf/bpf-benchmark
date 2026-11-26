"""A native checked leg must consume the same frontend input as its B object."""
import importlib.util
import json
import os
import shutil
import time
from pathlib import Path
import subprocess
import sys
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/checked-toolchain/frontend')
BUILD.mkdir(parents=True,exist_ok=True)
phase=sys.argv[1];commands=[]
generated=BUILD/'generated'
if generated.exists():
    retained=HERE/f'frontend-{phase}-prior-products.tar.gz'
    with tarfile.open(retained,'w:gz') as previous:
        previous.add(generated,arcname='generated')
    with tarfile.open(retained) as previous:
        for path in generated.rglob('*'):
            if path.is_file() and previous.extractfile('generated/'+str(path.relative_to(generated))).read()!=path.read_bytes():
                raise AssertionError('unarchived prior frontend product: '+str(path))
    shutil.rmtree(generated)
def run(command):
 command=list(map(str,command));r=subprocess.run(command,text=True,capture_output=True)
 commands.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (HERE/f'frontend-{phase}-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 r.check_returncode();return r.stdout
spec=importlib.util.spec_from_file_location('arm_frontend',ROOT/'kprog/arm64/trusted_specializer.py')
worker=importlib.util.module_from_spec(spec);spec.loader.exec_module(worker)
linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
native=BUILD/'input.o'
run(['clang-18','--target=aarch64-linux-gnu','-O3','-mtune=neoverse-n1','-mgeneral-regs-only','-mno-outline-atomics','-ffixed-x26','-fPIC','-fno-stack-protector','-c',HERE/'frontend_fixture.c','-o',native])
broker=None
if phase=='broker':
    state=BUILD/'broker-state'
    command=['python3',str(ROOT/'kprog/trusted_compile.py'),'serve','--scope',str(BUILD),'--state',str(state),'--clang',str(ROOT/'kprog/stock-path/bin/clang')]
    broker_log=(HERE/'frontend-broker-server.log').open('w')
    broker=subprocess.Popen(command,stdout=broker_log,stderr=subprocess.STDOUT)
    while not (state/'ready.json').exists():
        if broker.poll() is not None:raise RuntimeError('compiler broker exited before ready')
        time.sleep(0.01)
    os.environ['KPROG_TRUSTED_COMPILE_STATE']=str(state)
try:
    artifacts=worker.specialize(native.read_bytes(),'entry',dict(version=1,prog_type=2,section='kprobe/trusted',maps=[]),generated,linker)
    source=Path(artifacts['simulator_source'])
    (HERE/f'frontend-{phase}-b.dis').write_text(run(['llvm-objdump-18','-d',artifacts['simulator_object']]))
    # The source is service-owned; this simulates a workspace input changing
    # between verification and native generation, without touching shared headers.
    original=source.read_bytes()
    source.write_text('int trusted_arm64_arm64_sim_xdp(void *ctx) { (void)ctx; return 99; }\n')
    result=worker.compile_checked_simulator(artifacts,linker,Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
    run(['aarch64-linux-gnu-gcc','-O2','-static','-ffixed-x26',HERE/'frontend_driver.c',result['native_object'],'-o',BUILD/'execute'])
    execution=run(['qemu-aarch64-static','-cpu','cortex-a57',BUILD/'execute'])
    source.write_bytes(original)
finally:
    if broker is not None:
        os.environ.pop('KPROG_TRUSTED_COMPILE_STATE')
        (state/'STOP').write_text('test complete\n')
        broker_status=broker.wait(timeout=10)
        broker_log.close()
        if broker_status:raise RuntimeError('compiler broker failed: '+str(broker_status))
with tarfile.open(HERE/f'frontend-{phase}-evidence.tar.gz','w:gz') as archive:
 archive.add(BUILD,arcname='frontend')
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 phase=phase,artifacts=artifacts,execution=execution,
 scope='Actual ARM P generation/B compilation and native worker execution on Cortex-A57 with deliberate private generated-source mutation after B. B is not submitted to a stock verifier; no kernel/app/timing acceptance.')
(HERE/f'frontend-{phase}-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(execution,end='')
if phase in ('after','broker') and execution!='native_return=7\n':raise AssertionError('native compiler reread changed C instead of B frontend')
