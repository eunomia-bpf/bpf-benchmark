"""Run actual checked ARM C helper emission on Cortex-A57 with kernel-layout models."""
import gzip
import json
from pathlib import Path
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
mixed=len(sys.argv)>1 and sys.argv[1]=='mixed'
prefix='mixed' if mixed else 'helpers'
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
sys.path.insert(0,str(ROOT/'kprog'))
from inline_array import field_offset,hash_layout
from kernel_function_abi import KernelTypes
btf='/workspaces/.agent-state/kprog-ck/build-arm64/vmlinux'
types=KernelTypes(btf)
try:
    array=types.lib.btf__find_by_name_kind(types.btf,b'bpf_array',4)
    mapping=types.lib.btf__find_by_name_kind(types.btf,b'bpf_map',4)
    ops=types.lib.btf__find_by_name_kind(types.btf,b'bpf_map_ops',4)
    task=types.lib.btf__find_by_name_kind(types.btf,b'task_struct',4)
    base=field_offset(types,array,'map')
    fields={key:field_offset(types,array,name)-base for key,name in [
        ('ARRAY_STRIDE','elem_size'),('ARRAY_MASK','index_mask'),('ARRAY_VALUES','value'),('ARRAY_PPTRS','pptrs')]}
    fields.update(ARRAY_LIMIT=field_offset(types,mapping,'max_entries'),
                  MAP_KIND=field_offset(types,mapping,'map_type'),MAP_OPS=field_offset(types,mapping,'ops'),
                  OPS_LOOKUP=field_offset(types,ops,'map_lookup_elem'))
    if mixed:
        fields.update(TASK_PID=field_offset(types,task,'pid'),TASK_TGID=field_offset(types,task,'tgid'))
finally:types.close()
hash_fields=hash_layout(btf)
fields.update({f'HASH_{name.upper()}':hash_fields[name] for name in ['buckets','count','seed','head']})
(BUILD/'helpers-layout.h').write_text(''.join(f'#define {name} {value}\n' for name,value in fields.items()))
commands=[]
for command in [
 ['aarch64-linux-gnu-gcc','-O2','-static','-ffixed-x26','-I'+str(BUILD),str(HERE/('mixed_driver.c' if mixed else 'helpers_driver.c')),str(BUILD/'checked-simulator.native.o'),'-o',str(BUILD/(prefix+'-execute'))],
 ['qemu-aarch64-static','-cpu','cortex-a57',str(BUILD/(prefix+'-execute'))]]:
    r=subprocess.run(command,text=True,capture_output=True)
    commands.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
    (HERE/(prefix+'-execution.json')).write_text(json.dumps(dict(
        recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
        kernel_btf=btf,fields=fields,commands=commands,
        scope='Actual checked-native machine code on QEMU Cortex-A57 with synthetic kernel-layout maps/nofault stubs; empty HASH/LPM only. No kernel/stock/app/timing acceptance.'),indent=2)+'\n')
    print(r.stdout,r.stderr,end='')
    r.check_returncode()
(HERE/(prefix+'-execute.gz')).write_bytes(gzip.compress((BUILD/(prefix+'-execute')).read_bytes(),mtime=0))
