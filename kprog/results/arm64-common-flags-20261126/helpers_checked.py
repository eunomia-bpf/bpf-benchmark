"""Exercise the ARM checked worker's shared C helper boundary."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tarfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
phase = sys.argv[1]
commands=[]
def run(command, required=True):
    command=list(map(str,command))
    r=subprocess.run(command,text=True,capture_output=True)
    commands.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
    (HERE/f'helpers-{phase}-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if required:r.check_returncode()
    return r
spec=importlib.util.spec_from_file_location('arm_helpers_checked',ROOT/'kprog/arm64/trusted_specializer.py')
worker=importlib.util.module_from_spec(spec)
spec.loader.exec_module(worker)
source=HERE/'helpers_fixture.c'
bpf=BUILD/'helpers.bpf.o'
run([ROOT/'kprog/stock-path/bin/clang',*worker.b_flags(),'-c',source,'-o',bpf])
prepared=BUILD/'helpers.i'
run(['clang-18','-E',source,'-o',prepared])
btf=Path('/workspaces/.agent-state/kprog-ck/build-arm64/vmlinux')
maps=[dict(name=name,map_type=kind,key_size=key_size,value_size=8,max_entries=2,value_offset=None)
      for name,kind,key_size in [('array_map',2,4),('hash_map',1,4),('lpm_map',11,8),('percpu_map',6,4)]]
artifacts=dict(simulator_source=str(prepared),simulator_object=str(bpf),
    simulator_program='array_entry',maps=maps,context_kind='raw',kernel_btf=str(btf))
linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
r=worker.compile_checked_simulator(artifacts,linker,Path('/tmp/cc_compile-sim-ir'))
obj=Path(r['native_object'])
undefined=run(['llvm-nm-18','-u','-j',obj]).stdout.splitlines()
plan=BUILD/'helpers-plan.json'
plan.write_text(json.dumps(dict(version=1,maps=[dict(name=m['name'],addr=0x200000+i*0x1000) for i,m in enumerate(maps)],
    helpers=[dict(name=n,addr=0x100000+i*0x1000) for i,n in enumerate(
        ['bpf_map_lookup_elem','copy_from_user_nofault','copy_from_kernel_nofault','bpf_this_cpu_ptr','memset','memcmp'])])))
rows=[]
for entry in ['array_entry','hash_entry','lpm_entry','percpu_entry','dynamic_entry','user_entry','kernel_entry']:
    proof=BUILD/'helpers.proof.o'
    run([linker,'--input',obj,'--symbol',entry,'--mode','proof','--preserve-entry-abi','--output',proof])
    linked=run([linker,'--input',proof,'--symbol',entry,'--mode','kernel','--link-plan',plan,
        '--output',BUILD/'helpers-linked.bin','--output-relocs',BUILD/'helpers-linked.relocs'],required=False)
    rows.append(dict(entry=entry,kernel_link_returncode=linked.returncode,error=linked.stderr))
with tarfile.open(HERE/f'helpers-{phase}-evidence.tar.gz','w:gz') as archive:
    for path in sorted(BUILD.glob('checked-simulator.*')):archive.add(path,arcname=path.name)
    archive.add(BUILD/'native-commands.jsonl',arcname='native-commands.jsonl')
    archive.add(bpf,arcname=bpf.name)
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
    phase=phase,kernel_btf=str(btf),undefined=undefined,rows=rows,
    scope='Actual ARM checked worker compile/proof/kernel-link diagnostic with sole ARM BTF and synthetic map addresses. No stock B, kernel execution, application or timing result.')
if phase=='after':
    with tarfile.open(HERE/'helpers-before-evidence.tar.gz') as before:
        record['frontend_ir_unchanged']=before.extractfile('checked-simulator.bc').read()==(BUILD/'checked-simulator.bc').read_bytes()
(HERE/f'helpers-{phase}-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2))
if phase=='after' and (any(x['kernel_link_returncode'] for x in rows) or not record['frontend_ir_unchanged']):
    raise AssertionError('ARM checked helper regression')
