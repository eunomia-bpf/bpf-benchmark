"""Detect compiling the producer again or losing checked C map/helper semantics."""
import ctypes
import json
from pathlib import Path
import subprocess
import sys
from types import SimpleNamespace
import shutil

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog'))
from trusted_service import adapter, load_service_artifacts

compiler, linker, original, output = map(Path, sys.argv[1:])
output.mkdir(parents=True)
worker = adapter(1)
metadata = dict(version=1, prog_type=1, section='socket', maps=[dict(
    name='logical', map_type=2, key_size=4, value_size=8, max_entries=1, map_flags=0, value_offset=None)])
artifacts = worker.specialize(original.read_bytes(), 'entry', metadata, output/'generated', linker)
# A subprocess transport fixture exercises phase ordering with the REAL native
# compiler. It does not emulate stock verifier acceptance (the guest does that).
loader = output/'loader-fixture.py'
loader.write_text('''#!/usr/bin/python3
import json,sys
from pathlib import Path
phase=sys.argv[1]
directory=Path(sys.argv[8]).parent
native=directory/'checked-simulator.native.o'
if phase=='verify':
    assert not native.exists(), 'compiled before verification'
    if (directory/'reject').exists(): raise SystemExit(7)
else: assert native.is_file(), 'installed producer instead of checked simulator'
print(json.dumps(dict(request_id=int(sys.argv[3]),status=0,prog_id=19,phase=phase)))
''')
loader.chmod(0o755)
args=SimpleNamespace(loader=loader,native_link=linker,execution_mode='checked-sim-c',sim_native_compiler=compiler)
request=SimpleNamespace(request_id=11,source_prog_id=1)
actual=dict(expected_attach_type=0,prog_flags=0,attach_btf_id=0,attach_btf_obj_id=0,attach_prog_id=0,prog_ifindex=0)
with open('/dev/null','rb') as fd:
    load_service_artifacts(args,worker,fd.fileno(),request,actual,dict(maps=[]),artifacts,output)
compiled=json.loads((output/'generated/checked-simulator.json').read_text())['artifacts']
reject=output/'rejected';reject.mkdir()
(reject/'reject').write_text('transport fixture rejection\n')
shutil.copyfile(artifacts['simulator_object'],reject/'proof.bpf.o')
shutil.copyfile(artifacts['simulator_preprocessed'],reject/'simulator.i')
candidate=dict(artifacts,simulator_object=str(reject/'proof.bpf.o'),simulator_preprocessed=str(reject/'simulator.i'))
with open('/dev/null','rb') as fd:
    try: load_service_artifacts(args,worker,fd.fileno(),request,actual,dict(maps=[]),candidate,reject)
    except subprocess.CalledProcessError as error: assert error.returncode==7
    else: raise AssertionError('verification failure swallowed')
assert not (reject/'checked-simulator.i').exists()
assert Path(artifacts['simulator_preprocessed']).read_bytes() == (output/'generated/checked-simulator.i').read_bytes()
assert compiled['native_object'] != artifacts['native_object']
assert compiled['symbol'] == artifacts['simulator_program']
harness = output/'harness.c'
harness.write_text('''#include <stdint.h>
unsigned long long kprog_unspecified_input[1];
unsigned char logical[32];
static uint64_t current;
void configure(uint64_t value) { current=value; }
void *bpf_map_lookup_elem(void *map, const uint32_t *key) {
    if (map != (void *)logical || *key != 0) __builtin_trap();
    return &current;
}
''')
shared = output/'simulator.so'
subprocess.run(['clang-18','-shared','-fPIC',compiled['native_object'],str(harness),'-o',str(shared)],check=True)
library = ctypes.CDLL(str(shared))
library.configure.argtypes = [ctypes.c_uint64]
execute = getattr(library, compiled['symbol'])
execute.argtypes = [ctypes.c_void_p]
execute.restype = ctypes.c_int
rows = []
for value in [0, 1, 29, 73, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000001]:
    library.configure(value)
    observed = execute(None)
    expected = ctypes.c_int(2*value).value
    assert observed == expected, (value, observed, expected)
    rows.append(dict(value=value, observed=observed, expected=expected))
(output/'execution.json').write_text(json.dumps(rows,indent=2)+'\n')
commands=[]
def run(command, expected=0):
    done=subprocess.run([str(x) for x in command],capture_output=True,text=True)
    commands.append(dict(command=[str(x) for x in command],returncode=done.returncode,stdout=done.stdout,stderr=done.stderr))
    (output/'ir-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    assert done.returncode==expected,done.stderr
fixture=ROOT/'kprog/test/checked_sim_ir_fixture.c'
run(['clang-18','-target','bpf','-mcpu=v4','-O2','-emit-llvm','-c',fixture,'-o',output/'widths.bc'])
run([compiler,output/'widths.bc','-o',output/'widths.native.bc'])
run(['clang-18','-shared','-fPIC','-O2',output/'widths.native.bc','-o',output/'widths.so'])
widths=ctypes.CDLL(str(output/'widths.so'))
width_rows=[]
for bits in [8,16,32,64]:
    load=getattr(widths,'load'+str(bits));load.argtypes=[ctypes.c_void_p];load.restype=ctypes.c_uint64
    store=getattr(widths,'store'+str(bits));store.argtypes=[ctypes.c_void_p,ctypes.c_uint64]
    for offset in [3,4,7]:
        for value in [0,0x80,0x8000,0x80000000,0xfedcba9876543210]:
            data=(ctypes.c_ubyte*32)(*([0xa5]*32));address=ctypes.addressof(data)
            store(address+offset-3,value)
            expected=bytearray([0xa5]*32)
            expected[offset:offset+bits//8]=(value&((1<<bits)-1)).to_bytes(bits//8,'little')
            assert bytes(data)==bytes(expected),(bits,offset,value)
            assert load(address+offset+3)==(value&((1<<bits)-1)),(bits,offset,value)
            width_rows.append(dict(bits=bits,offset=offset,value=value))
widths.truncate32.argtypes=[ctypes.c_uint32];widths.truncate32.restype=ctypes.c_uint64
assert widths.truncate32(0xffffffff)==0xffffffff
run(['clang-18','-target','bpf','-mcpu=v4','-O2','-emit-llvm','-c','-DINVALID_ASM',fixture,'-o',output/'invalid.bc'])
run([compiler,output/'invalid.bc','-o',output/'invalid.native.bc'],expected=1)
assert not (output/'invalid.native.bc').exists()
(output/'width-execution.json').write_text(json.dumps(width_rows,indent=2)+'\n')
print(json.dumps(dict(host_vectors=len(rows), exact_checked_source_copy=True,
    width_vectors=len(width_rows), reject_before_compile=True, unknown_asm_error=True,
    executable=compiled['native_object'], scope='host compilation/execution only, no kernel acceptance')))
