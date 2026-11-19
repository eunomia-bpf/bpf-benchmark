"""Compile the correlated pointer/tag case through the actual B backend."""
import ctypes
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
tools = Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
out = Path(sys.argv[1])
mode = sys.argv[2] if len(sys.argv) > 2 else 'baseline'
assert mode in ('baseline', 'fixed'), mode
out.mkdir(parents=True, exist_ok=True)
sys.path.insert(0, str(root/'kprog/x86'))
import trusted_specializer as adapter

commands = []
def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    result.check_returncode()
    return result.stdout

source = Path(__file__).with_name('fixture.c')
run([root/'kprog/stock-path/bin/clang', *adapter.COMPILE_FLAGS,
     '-emit-llvm', '-c', source, '-o', out/'frontend.bc'])
run([tools/'packet-bounds', out/'frontend.bc', '-o', out/'bounds.bc'])
for stage in ['frontend', 'bounds']:
    (out/(stage+'.ll')).write_text(run(['llvm-dis-18', out/(stage+'.bc'), '-o', '-']))
if mode == 'fixed':
    assert 'asm sideeffect "$0 -= $2", "=r,0,r"' in (out/'bounds.ll').read_text()
adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang',
    out/'fixture.bpf.c', out/'fixture.bpf.o', run, compiled_input=out/'bounds.bc')
(out/'b-disassembly.txt').write_text(run(['llvm-objdump-18', '-dl', out/'fixture.bpf.o']))
run([tools/'compile-sim-ir', out/'frontend.bc', '-o', out/'native.bc'])
run(['clang-18', '-O3', '-shared', '-fPIC', '-mno-red-zone', '-mgeneral-regs-only',
     out/'native.bc', '-o', out/'execute.so'])
program = ctypes.CDLL(str(out/'execute.so')).guarded_difference
program.argtypes = [ctypes.c_void_p]
program.restype = ctypes.c_int
rows = []
for scalar in [0, 1, 0x12345678, 0xffffffff]:
    for queue in [0, 1, 2, 3]:
        context = (ctypes.c_uint32 * 6)(0, 0, 0, scalar, queue, 123)
        rows.append(dict(scalar=scalar, queue=queue, expected=ctypes.c_int(115 if queue & 1 else scalar).value,
                         observed=program(context)))
(out/'result.json').write_text(json.dumps(dict(cases=rows,
    scope='Actual B compile/disassembly and native execution of the source fixture; '
          'no stock verifier, app coverage or timing result.'), indent=2)+'\n')
assert all(row['observed'] == row['expected'] for row in rows), rows
if mode == 'fixed':
    # Catch broadening to scalar subtraction, narrow truncation or one-pointer
    # arithmetic, and prove that the two pointer casts alone select this class.
    controls = '''define i64 @pair(ptr %a, ptr %b) {
      %x = ptrtoint ptr %a to i64
      %y = ptrtoint ptr %b to i64
      %d = sub i64 %x, %y
      ret i64 %d
    }
    define i64 @scalar(i64 %a, i64 %b) { %d = sub i64 %a, %b ret i64 %d }
    define i32 @narrow(ptr %a, ptr %b) {
      %x = ptrtoint ptr %a to i32
      %y = ptrtoint ptr %b to i32
      %d = sub i32 %x, %y
      ret i32 %d
    }
    define i64 @offset(ptr %a, i64 %b) {
      %x = ptrtoint ptr %a to i64
      %d = sub i64 %x, %b
      ret i64 %d
    }
    '''
    (out/'controls.ll').write_text(controls)
    run([tools/'packet-bounds', out/'controls.ll', '-o', out/'controls.bc'])
    lowered = run(['llvm-dis-18', out/'controls.bc', '-o', '-'])
    (out/'controls-lowered.ll').write_text(lowered)
    assert lowered.count('asm sideeffect "$0 -= $2", "=r,0,r"') == 1
    assert lowered.count('sub i64') == 2 and lowered.count('sub i32') == 1
print(f'{len(rows)} native pointer/tag cases pass; inspect emitted B separately.', flush=True)
