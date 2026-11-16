"""Retain conditional function tails through proof and kernel linking."""
import ctypes
import json
import mmap
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
linker = root / 'kprog/x86/native_lab/native_link/target/release/native-link'
plan = root / 'corpus/results/shared-hash-regression-20261116/captures/link-ie2fmz97/link-plan.json'
source, output = map(Path, sys.argv[1:])
rows = []
for symbol in ['entry', 'choose']:
    row = dict(symbol=symbol)
    proof = output / (symbol + '.proof.o')
    blob = output / (symbol + '.blob')
    for mode, src, dest in [('proof', source, proof), ('kernel', proof, blob)]:
        command = [str(linker), '--input', str(src), '--symbol', symbol,
                   '--mode', mode, '--output', str(dest)]
        if mode == 'kernel':
            command += ['--link-plan', str(plan)]
        with (output / (symbol + '.' + mode + '.log')).open('w') as log:
            child = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
        row[mode] = dict(command=command, returncode=child.returncode)
        if child.returncode:
            break
    if row.get('kernel', {}).get('returncode') == 0:
        code = blob.read_bytes() + b'\xc3'
        with mmap.mmap(-1, len(code), prot=mmap.PROT_READ | mmap.PROT_WRITE | mmap.PROT_EXEC) as region:
            region.write(code)
            view = ctypes.c_char.from_buffer(region)
            entry = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.c_void_p, ctypes.c_void_p,
                                     ctypes.c_size_t)(ctypes.addressof(view))
            row['returns'] = [entry(None, None, n) for n in [0, 1, 2, 255]]
            row['expected'] = [22, 11, 11, 11]
            row['code_bytes'] = len(code) - 1
            del entry, view
    rows.append(row)
result = dict(scope='Host control-flow execution; no app timing or B stock claim', entries=rows)
(output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
