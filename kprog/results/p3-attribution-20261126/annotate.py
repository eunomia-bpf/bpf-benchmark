"""Annotate a captured JIT image from owner-specific workload IP samples."""
import bisect
import collections
import json
from pathlib import Path
import re
import subprocess
import sys
from profile_summary import symbols

out, phase, funcs, code = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3]), Path(sys.argv[4])
summary = json.loads((out / 'phase-summary.json').read_text())
start, length = funcs.read_text().splitlines()[0].split()
start, length = int(start, 16), int(length)
assert code.stat().st_size == length, 'expected one captured JIT function'
dis = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
    '--no-show-raw-insn', '--adjust-vma=' + hex(start), str(code)], text=True)
rows = []
for line in dis.splitlines():
    if match := re.match(r'^\s*([0-9a-f]+):\s+(.*)$', line):
        rows.append((int(match[1], 16), match[2]))
addresses = [a for a, text in rows]
counts = collections.Counter()
for ip, n in summary['phases'][phase]['ip_samples'].items():
    ip = int(ip, 16)
    if start <= ip < start + length:
        counts[bisect.bisect_right(addresses, ip) - 1] += n
names, starts = symbols([out / 'kallsyms.txt', *sorted(out.glob('kallsyms-bpf-*'))])
print('QEMU', summary['qemu_host_pid'], phase, 'window', summary['windows'][phase],
      'image', code, 'bytes', length, 'samples', counts.total())
print('Sample IPs may skid; counts locate instruction regions, not exact instruction latency.')
for index, n in counts.most_common(25):
    print('\n----', n, 'samples at +' + hex(rows[index][0] - start))
    for j in range(max(0, index - 7), min(len(rows), index + 2)):
        address, text = rows[j]
        if match := re.search(r'call\s+0x([0-9a-f]+)', text):
            target = int(match[1], 16)
            k = bisect.bisect_right(starts, target) - 1
            if k >= 0:
                text += ' ; ' + names[starts[k]] + '+' + hex(target - starts[k])
        print(f'{counts[j]:7d} {address-start:6x}: {text}')
