#!/usr/bin/env python3
"""Catch forced successors, wrong variable extents and lost path state/effects."""
import copy
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1
BASE = 0x12340000
initial = dict(registers=[0x100 + i for i in range(16)], flags=0x202,
    pc=BASE, fs_base=0x8000, gs_base=0x9000, xmm0=(1 << 127) + 123,
    memory=[dict(address=0x2000, value=0xa5, readable=True, writable=False, initialized=False)])
cases = []
rejects = []


def request(code, path, state=None, base=BASE):
    return dict(isa='x86_64', state=copy.deepcopy(initial if state is None else state),
        native_bytes=code, native_base=base,
        native_path=[dict(offset=offset, length=length) for offset, length in path])


def expected(q, end):
    s = copy.deepcopy(q['state'])
    s.update(pc=(q['native_base'] + end) & MASK, defined_flags=MASK, events=[], fault=None)
    return s


for bits in range(64):
    cf, pf, af, zf, sf, of = [bool(bits & (1 << n)) for n in range(6)]
    flags = 0x202 | cf | (pf << 2) | (af << 4) | (zf << 6) | (sf << 7) | (of << 11)
    truth = [of, not of, cf, not cf, zf, not zf, cf or zf, not cf and not zf,
        sf, not sf, pf, not pf, sf != of, sf == of, zf or sf != of, not zf and sf == of]
    for cc, taken in enumerate(truth):
        for backward in (False, True):
            if backward:
                code = [0xeb, 7, 0xb8, 1, 0, 0, 0, 0xeb, 7, 0xb8, 0, 0, 0, 0, 0x70 + cc, 0xf2]
                path = [(0, 2), (9, 5), (14, 2)] + ([(2, 5), (7, 2)] if taken else [])
            else:
                code = [0x70 + cc, 7, 0xb8, 0, 0, 0, 0, 0xeb, 5, 0xb8, 1, 0, 0, 0]
                path = [(0, 2)] + ([(9, 5)] if taken else [(2, 5), (7, 2)])
            q = request(code, path)
            q['state']['flags'] = flags
            e = expected(q, len(code)); e['registers'][0] = int(taken)
            cases.append((q, e))
            if bits == 0:
                bad = copy.deepcopy(q)
                bad['native_path'][1]['offset'] = 2 if path[1][0] != 2 else 9
                rejects.append((bad, 'native path successor mismatch'))

# Wrapped PCs, an interior entry and multi-prefix extent all use real decoder PCs.
q = request([0x66, 0x90, 0x90], [(0, 2), (2, 1)], base=MASK)
q['state']['pc'] = MASK
cases.append((q, expected(q, 3)))
q = request([0xff] * 5 + [0x90], [(5, 1)])
q['state']['pc'] = BASE + 5
cases.append((q, expected(q, 6)))
q = request([], [])
cases.append((q, expected(q, 0)))

# False CMOV still faults on its memory source; a certificate cannot step past it.
q = request([0x48, 0x0f, 0x44, 0x03, 0x90], [(0, 4)])
q['state']['registers'][3] = 0x3000
fault = dict(kind='read', address=0x3000, bytes=8)
e = expected(q, 0); e.update(fault=fault, events=[dict(kind='fault', fault=fault)])
cases.append((q, e))
bad = copy.deepcopy(q); bad['native_path'].append(dict(offset=4, length=1))
rejects.append((bad, 'native path continues after fault'))

# Full memory/write-permission state and ordered events survive multiple steps.
q = request([0x88, 0x03, 0x8a, 0x0b], [(0, 2), (2, 2)])
q['state']['registers'][0] = 0x12345678
q['state']['registers'][3] = 0x2000
q['state']['memory'][0]['writable'] = True
e = expected(q, 4); e['memory'][0].update(value=0x78, initialized=True)
e['registers'][1] = (e['registers'][1] & ~255) | 0x78
e['events'] = [dict(kind=kind, address=0x2000, value=[0x78], initialized=True) for kind in ['write', 'read']]
cases.append((q, e))

for code, path, message in [
    ([0x90, 0x90], [(0, 2)], 'native path instruction extent differs from canonical decode'),
    ([0x90], [(0, 0)], 'native path instruction extent must be in [1,15]'),
    ([0x90] * 16, [(0, 16)], 'native path instruction extent must be in [1,15]'),
    ([0x90], [(0, 2)], 'native path instruction extent outside artifact'),
    ([0x48, 0x89, 0xd8], [(0, 2)], 'truncated native encoding'),
    ([0x0f, 0x0c, 0xc0], [(0, 3)], 'unrecognized native opcode'),
]:
    rejects.append((request(code, path), message))
bad = request([0x90], [(0, 1)]); bad.pop('native_base')
rejects.append((bad, 'native_base'))

binary = ROOT / '.lake/build/bin/reference'
completed = subprocess.run([str(binary)], input=''.join(json.dumps(q) + '\n' for q, _ in cases),
    text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True)
outputs = [json.loads(line) for line in completed.stdout.splitlines()]
assert len(outputs) == len(cases), (len(outputs), len(cases))
for index, ((q, e), output) in enumerate(zip(cases, outputs)):
    assert output == e, (index, q, output, e)
for q, message in rejects:
    result = subprocess.run([str(binary)], input=json.dumps(q) + '\n', text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    assert result.returncode != 0 and not result.stdout and message in result.stderr, (q, message, result)
print(f'x86 canonical paths: {len(cases)} full-state cases, {len(rejects)} precise rejections PASS')
