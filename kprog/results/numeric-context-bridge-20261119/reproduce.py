"""Test native preservation of NUMERIC's concrete bits through the stock frontend."""
import ctypes
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
commands = []
def run(arguments):
    arguments = list(map(str, arguments))
    result = subprocess.run(arguments, text=True, capture_output=True)
    commands.append(dict(command=arguments, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    result.check_returncode()
    return result.stdout

run([root/'kprog/stock-path/bin/clang', '-target', 'bpf', '-O1', '-g',
     '-emit-llvm', '-c', Path(__file__).with_name('fixture.c'), '-o', out/'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',
     out/'input.bc', '-o', out/'native.bc'])
(out/'native.ll').write_text(run(['llvm-dis-18', out/'native.bc', '-o', '-']))
run(['clang-18', '-O3', '-S', '-emit-llvm', out/'native.bc', '-o', out/'optimized.ll'])
run(['clang-18', '-O3', '-shared', '-fPIC', '-mno-red-zone', '-mgeneral-regs-only',
     out/'native.bc', '-o', out/'execute.so'])
library = ctypes.CDLL(str(out/'execute.so'))
library.plain_value.argtypes = library.numeric_value.argtypes = [ctypes.c_ulong]
library.numeric_lane.argtypes = [ctypes.c_ulong, ctypes.c_uint]
for name in ['plain_value', 'numeric_value', 'numeric_lane']:
    getattr(library, name).restype = ctypes.c_ulong
values = [0, 1, 0xffffffff, 0x100000000, 0x123456789abcdef0, 0xffff888012345678]
rows = []
for value in values:
    observed = library.plain_value(value)
    assert observed == value, (value, observed)
    rows.append(dict(function='numeric_value', value=value, expected=value,
                     observed=library.numeric_value(value)))
    for lane in [0, 1, 4]:
        rows.append(dict(function='numeric_lane', value=value, lane=lane,
            expected=(value >> (lane*8)) & 0xffffffff,
            observed=library.numeric_lane(value, lane)))
mismatches = [row for row in rows if row['observed'] != row['expected']]
(out/'result.json').write_text(json.dumps(dict(
    cases=len(rows), plain_control_cases=len(values), mismatches=mismatches,
    mismatch_count=len(mismatches), rows=rows,
    scope='Actual stock frontend/native compiler execution of the NUMERIC bit-preservation boundary; no B stock load, app failure or timing claim.'
), indent=2)+'\n')
print(f'{len(rows)} numeric cases, {len(mismatches)} mismatches; plain ABI controls pass.', flush=True)
assert not mismatches, 'Native numeric conversion lost the concrete input bits'
