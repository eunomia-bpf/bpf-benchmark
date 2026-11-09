"""Run emitted tail-call code in a userspace copy of the stock JIT frame.

The Rust tail_call_frame_resolves_actual_jit_depth test exports tail.bin and
its two relocation offsets through KPROG_TAIL_TEST_OUTPUT.
"""
import ctypes as c
import json
import mmap
from pathlib import Path
import struct
import sys

out = Path(sys.argv[1])
code = (out / 'tail.bin').read_bytes()
count_slot, stack_slot = map(int, (out / 'tail-offsets.txt').read_text().split())
results = []
for depth in (0, 1, 7, 8, 9, 63, 64, 65, 128, 255, 256, 511, 512):
    rounded = (depth + 7) & ~7
    for initial in (0, 1, 32, 33, 34):
        body = bytearray(code)
        struct.pack_into('<i', body, count_slot, -16 - rounded)
        struct.pack_into('<I', body, stack_slot, rounded)
        # Entry saves RBP once; each tail transfer enters at the stack allocation.
        entry = b'\x55\x48\x89\xe5\xb8' + struct.pack('<I', initial)
        tail_entry = len(entry)
        entry += b'\x48\x81\xec' + struct.pack('<I', rounded)
        entry += b'\x50\x48\x89\xe0\x50\x53\x41\x55\x41\x56\x41\x57'
        exit_code = b'\x41\x5f\x41\x5e\x41\x5d\x5b\x58\x58\x48\x81\xc4' + struct.pack('<I', rounded) + b'\xc9\xc3'
        payload = entry + body + exit_code
        image = mmap.mmap(-1, len(payload), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC)
        image.write(payload)
        address = c.addressof(c.c_char.from_buffer(image))
        target = (c.c_uint64 * 1)(address + tail_entry)
        array = (c.c_uint64 * 2)(1, c.addressof(target))
        fn = c.CFUNCTYPE(c.c_uint64, c.c_void_p, c.c_void_p, c.c_uint64)(address)
        for mode in ('populated', 'empty', 'index'):
            array[1] = c.addressof(target) if mode != 'empty' else 0
            observed = fn(None, c.addressof(array), 1 if mode == 'index' else 0)
            expected = max(initial, 33) if mode == 'populated' else initial
            assert observed == expected, (depth, initial, mode, observed, expected)
            results.append(dict(depth=depth, initial=initial, mode=mode, count=observed))
        image.close()
(out / 'tail-host.json').write_text(json.dumps(results, indent=2) + '\n')
print(f'x86 tail-call frame execution: PASS ({len(results)} runs, count limit 33)')
