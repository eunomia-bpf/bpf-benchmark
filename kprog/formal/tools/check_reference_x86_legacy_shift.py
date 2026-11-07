#!/usr/bin/env python3
"""Legacy shifts: numeric/CPU flags, byte lanes, RMW faults and exact state."""
import copy
import ctypes
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1
STATUS = 0x8D5


def numeric(kind, bits, value, count, old):
    mask = (1 << bits) - 1
    a = value & mask
    n = count & (63 if bits == 64 else 31)
    k = n % bits
    if kind == 'shl': result = (a << n) & mask
    elif kind == 'shr': result = a >> n
    elif kind == 'sar': result = ((a - (1 << bits) if a >> (bits - 1) else a) >> n) & mask
    elif kind == 'rol': result = ((a << k) | (a >> (bits - k))) & mask
    else: result = ((a >> k) | (a << (bits - k))) & mask
    if not n: return result, old, MASK
    if kind == 'rol': cf = result & 1
    elif kind == 'ror': cf = result >> (bits - 1)
    elif kind == 'shl': cf = (a >> (bits - n)) & 1 if n <= bits else 0
    elif n <= bits: cf = (a >> (n - 1)) & 1
    else: cf = (a >> (bits - 1)) if kind == 'sar' else 0
    sf = result >> (bits - 1)
    of = (sf ^ (result >> (bits - 2) & 1)) if kind == 'ror' else (sf ^ cf) if kind in ('shl', 'rol') else (a >> (bits - 1)) if kind == 'shr' else 0
    flags = (old & ~1) | cf
    if n == 1: flags = (flags & ~0x800) | (of << 11)
    defined = MASK if kind in ('rol', 'ror') else MASK ^ 16
    if n != 1: defined &= ~0x800
    if kind not in ('rol', 'ror'):
        flags = (flags & ~0xC4) | (sf << 7) | (int(result == 0) << 6) | (int((result & 255).bit_count() % 2 == 0) << 2)
        if kind in ('shl', 'shr') and n >= bits: defined &= ~1
    return result, flags, defined


def main():
    build = ROOT / 'build/legacy-shift-reference'
    build.mkdir(parents=True, exist_ok=True)
    source = ['#include <stdint.h>']
    for kind in ('shl', 'shr', 'sar', 'rol', 'ror'):
        for bits, suffix, operand in ((8, 'b', '%b0'), (16, 'w', '%w0'), (32, 'l', '%k0'), (64, 'q', '%0')):
            source.append('uint64_t %s%d(uint64_t a,uint64_t n,uint64_t old,uint64_t *out){uint64_t f;'
                '__asm__ volatile("pushfq;pushq %%3;popfq;%s%s %%%%cl,%s;pushfq;popq %%1;popfq"'
                ':"+a"(a),"=r"(f):"c"(n),"r"(old):"cc","memory");*out=f;return a;}' % (kind, bits, kind, suffix, operand))
    (build / 'cpu.c').write_text('\n'.join(source) + '\n')
    subprocess.run(['cc', '-O2', '-shared', '-fPIC', '-mno-red-zone', build / 'cpu.c', '-o', build / 'cpu.so'], check=True)
    cpu = ctypes.CDLL(str(build / 'cpu.so'))
    cases = []
    cpu_cases = 0
    for kind, group in (('rol', 0), ('ror', 1), ('shl', 4), ('shr', 5), ('sar', 7)):
        for bits, prefix in ((8, ''), (16, '66'), (32, ''), (64, '48')):
            width = bits // 8
            mask = (1 << bits) - 1
            fn = getattr(cpu, kind + str(bits))
            fn.argtypes = [ctypes.c_uint64] * 3 + [ctypes.POINTER(ctypes.c_uint64)]
            fn.restype = ctypes.c_uint64
            for count in (0, 1, 7, 8, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 255):
                for lane_value in (0, 1, mask, mask >> 1, 1 << (bits - 1), (0xAB81F00D12345678 & mask)):
                    old_value = (0xABCDEF0123456789 & ~mask) | lane_value
                    for flags in (0x202, 0xAD7):
                        value, out_flags, defined = numeric(kind, bits, lane_value, count, flags)
                        native_flags = ctypes.c_uint64()
                        native_value = fn(old_value, count, flags, ctypes.byref(native_flags))
                        written = value if bits == 32 else (old_value & ~mask) | value
                        assert native_value == written, (kind, bits, count, hex(native_value), hex(written))
                        assert (native_flags.value ^ out_flags) & defined & STATUS == 0, (kind, bits, count, flags, native_flags.value, out_flags, defined)
                        cpu_cases += 1
                        for route in ('immediate', 'cl', 'one'):
                            if route == 'one' and count != 1: continue
                            byte = int(bits != 8)
                            op = (0xC0 if route == 'immediate' else 0xD2 if route == 'cl' else 0xD0) + byte
                            tail = bytes([count]) if route == 'immediate' else b''
                            for memory in (False, True):
                                code = bytes.fromhex(prefix) + bytes([op, (0 if memory else 0xC0) + group * 8 + (7 if memory else 0)]) + tail
                                for fault in ((None, 'read', 'write') if memory else (None,)):
                                    state = dict(registers=[0xABC0000000000000 + 17 * i for i in range(16)], flags=flags,
                                        pc=MASK - 3, xmm0=(1 << 127) + 19, fs_base=0x12000, gs_base=0x34000, memory=[])
                                    state['registers'][0] = old_value
                                    state['registers'][1] = 0xF123456789000000 | count
                                    state['registers'][7] = 0x2001
                                    if memory:
                                        state['memory'] = [dict(address=0x2001 + i, value=(lane_value >> (8*i)) & 255,
                                            readable=not(fault == 'read' and i == width - 1),
                                            writable=not(fault == 'write' and i == width - 1), initialized=False) for i in range(width)]
                                    expected = copy.deepcopy(state)
                                    expected.update(pc=(state['pc'] + len(code)) & MASK, events=[], fault=None, flags=out_flags, defined_flags=defined)
                                    if memory and fault != 'read':
                                        expected['events'].append(dict(kind='read', address=0x2001, value=list(lane_value.to_bytes(width, 'little')), initialized=False))
                                    if fault:
                                        expected.update(pc=state['pc'], flags=flags, defined_flags=MASK,
                                            fault=dict(kind=fault, address=0x2001, bytes=width))
                                        expected['events'].append(dict(kind='fault', fault=expected['fault']))
                                    elif memory:
                                        data = list(value.to_bytes(width, 'little'))
                                        expected['events'].append(dict(kind='write', address=0x2001, value=data, initialized=True))
                                        for cell, byte_value in zip(expected['memory'], data): cell.update(value=byte_value, initialized=True)
                                    else: expected['registers'][0] = written
                                    cases.append((dict(isa='x86_64', native_bytes=list(code), state=state), expected))
            # AH/CH use the incoming source even when CL supplies the count;
            # an active REX40 selects SPL instead of AH.
            if bits == 8:
                for code, reg, lane, amount in [('d2'+f'{0xC4+group*8:02x}', 0, 8, 8),
                    ('d2'+f'{0xC5+group*8:02x}', 1, 8, 8),
                    ('40d2'+f'{0xC4+group*8:02x}', 4, 0, 8)]:
                    state = dict(registers=[0x1122334455668108] * 16, flags=0xAD7, pc=0x1000,
                        xmm0=17, fs_base=0, gs_base=0, memory=[])
                    value, flags, defined = numeric(kind, 8, state['registers'][reg] >> lane, amount, state['flags'])
                    expected = copy.deepcopy(state)
                    expected['registers'][reg] = (state['registers'][reg] & ~(255 << lane)) | (value << lane)
                    expected.update(pc=state['pc']+len(bytes.fromhex(code)), flags=flags, events=[], fault=None, defined_flags=defined)
                    cases.append((dict(isa='x86_64',native_bytes=list(bytes.fromhex(code)),state=state),expected))
    binary = ROOT / '.lake/build/bin/reference'
    # Keep one process per bounded batch; every batch compares every state field.
    for start in range(0, len(cases), 2048):
        batch = cases[start:start+2048]
        result = subprocess.run([str(binary)], input=''.join(json.dumps(r)+'\n' for r,_ in batch), text=True, capture_output=True, check=True)
        actual = [json.loads(line) for line in result.stdout.splitlines()]
        assert len(actual) == len(batch)
        for (request, expected), observed in zip(batch, actual): assert observed == expected, (request, observed, expected)
    for code in ('c1e0', '48d3', 'c1d001', '66'*14+'d0e0'):
        request = copy.deepcopy(cases[0][0]); request['native_bytes'] = list(bytes.fromhex(code))
        result = subprocess.run([str(binary)], input=json.dumps(request)+'\n', text=True, capture_output=True)
        assert result.returncode == 1 and result.stderr.startswith('reference:'), (request, result)
    print(f'x86 legacy shifts: {cpu_cases} real CPU/numeric cases, {len(cases)} full-state reference cases including RMW faults/lanes/counts OK')


if __name__ == '__main__': main()
