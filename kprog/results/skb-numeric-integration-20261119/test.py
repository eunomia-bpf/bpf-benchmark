"""Execute shared SKB field macros through native and context lowering."""
import ctypes
import json
from pathlib import Path
import subprocess
import sys

root, tools = Path('/workspaces/repository'), Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
commands = []
def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, capture_output=True, text=True)
    commands.append(dict(command=command, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    result.check_returncode()
    return result.stdout

public, physical = tools/'public-layout.json', tools/'physical-layout.json'
(out/'public-layout.json').write_bytes(public.read_bytes())
(out/'physical-layout.json').write_bytes(physical.read_bytes())
rules = {row['field']: row for row in json.loads(physical.read_text()) if row['kind'] == 'skb'}
run([root/'kprog/stock-path/bin/clang', '-target', 'bpf', '-O1', '-g',
     '-D__TARGET_ARCH_x86', '-I', '/usr/include/x86_64-linux-gnu',
     '-I', root/'vendor/libbpf/include/uapi', '-I', root/'vendor/libbpf/src',
     '-emit-llvm', '-c', Path(__file__).with_name('fixture.c'), '-o', out/'input.bc'])
run([tools/'compile-sim-ir', out/'input.bc', '-o', out/'native.bc'])
(out/'native.ll').write_text(run(['llvm-dis-18', out/'native.bc', '-o', '-']))
run([tools/'context-lower', out/'native.bc', '--public-layout', public,
     '--physical-layout', physical, '-o', out/'context.bc'])
(out/'context.ll').write_text(run(['llvm-dis-18', out/'context.bc', '-o', '-']))
run(['clang-18', '-O3', '-mno-red-zone', '-mgeneral-regs-only', '-shared', '-fPIC',
     out/'context.bc', '-o', out/'execute.so'])
library = ctypes.CDLL(str(out/'execute.so'))
for name in ['data_value', 'end_value', 'mark_value', 'data_lane', 'end_lane']:
    function = getattr(library, name)
    function.restype = ctypes.c_ulong
    function.argtypes = [ctypes.c_void_p] + ([ctypes.c_uint] if name.endswith('_lane') else [])
rows = []
for value in [0, 1, 0x123456789abcdef0, 0xffff888012345678]:
    context = ctypes.create_string_buffer(bytes([0xa5])*512)
    end = (value+0x1020304) & ((1 << 64)-1)
    for field, bits in [('data', value), ('data_end', end), ('mark', 0x12345678)]:
        rule = rules[field]
        ctypes.memmove(ctypes.addressof(context)+rule['offset'],
                       bits.to_bytes(rule['width'], 'little'), rule['width'])
    for name, expected in [('data_value', value), ('end_value', end), ('mark_value', 0x12345678)]:
        rows.append(dict(function=name, value=value, expected=expected,
                         observed=getattr(library, name)(context)))
    for name, bits in [('data_lane', value), ('end_lane', end)]:
        for lane in [0, 4]:
            rows.append(dict(function=name, value=value, lane=lane,
                expected=(bits >> (lane*8)) & 0xffffffff,
                observed=getattr(library, name)(context, lane)))
mismatches = [row for row in rows if row['observed'] != row['expected']]
(out/'result.json').write_text(json.dumps(dict(cases=rows, mismatches=mismatches,
    scope='Actual shared macros and compiler stages on host buffers using the sole kernel layouts; '
          'no stock B load, guest, corpus path or timing claim.'), indent=2)+'\n')
print(f'{len(rows)} context cases, {len(mismatches)} mismatches', flush=True)
assert not mismatches, 'SKB native/context lowering lost the physical field or pointer bits'
