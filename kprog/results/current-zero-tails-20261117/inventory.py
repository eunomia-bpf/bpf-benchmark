#!/usr/bin/env python3
"""Inventory identical cold zero tails in actual production link emissions."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import struct
import subprocess

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--replay', type=Path, required=True)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()
report = json.loads(a.replay.read_text())
summary = defaultdict(Counter)
rows = []
for request in report['requests']:
    row = dict(app=request['app'], symbol=request['symbol'], capture=request['capture'],
               returncode=request['returncode'], output=request['output'], tails=[])
    totals = summary[request['app']]
    totals['requests'] += 1
    if request['returncode']:
        row['error_tail'] = request['error_tail']
        totals['errors'] += 1
        rows.append(row)
        continue
    folder = Path(request['output'])
    image = folder / 'image.blob'
    data = image.read_bytes()
    relocs = list(struct.iter_unpack('<IIQ', (folder / 'image.relocs').read_bytes()))
    abi = (folder / 'image.abi').read_text().replace('\\n', '\n').replace('\\t', '\t')
    loads = [tuple(map(int, line.split('\t')[1].split(',')))
             for line in abi.splitlines() if line.startswith('load_site\t')]
    groups = defaultdict(list)
    for region in request['lto_ranges']:
        if region['piece'] != 'probe_read':
            continue
        start, end = region['start'], region['end']
        assembly = subprocess.check_output([
            'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
            '--no-show-raw-insn', f'--start-address={start}', f'--stop-address={end}',
            str(image)], text=True)
        instructions = []
        for line in assembly.splitlines():
            match = re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line)
            if match:
                ip, op, operands = match.groups()
                instructions.append((int(ip, 16), op, operands))
        # The leaf emitters restore the original destination at the sole final
        # zero-fill suffix. Confirm instruction boundaries and the final RET.
        candidates = [ip for ip, op, operands in instructions
                      if op == 'mov' and operands == 'rdi,r8'
                      and (data[ip:ip+11] == bytes.fromhex('4c89c74489c931d283f908')
                           or data[ip:ip+5] == bytes.fromhex('4c89c731d2'))]
        if not candidates:
            continue
        if len(candidates) != 1 or instructions[-1] != (end-1, 'ret', ''):
            raise ValueError(f'zero-tail shape {folder}: {start}:{end}, {candidates}')
        zero = candidates[0]
        protected = [site for site in loads if zero <= site[0] < end]
        nested = [reloc for reloc in relocs if zero <= reloc[0] < end]
        tail = data[zero:end]
        entry = dict(region_start=start, region_end=end, zero_start=zero,
                     bytes=len(tail), byte_sequence=tail.hex(),
                     mode='dynamic' if tail.startswith(bytes.fromhex('4c89c74489c9')) else 'fixed',
                     protected_loads=protected, relocations=nested,
                     instructions=[r for r in instructions if r[0] >= zero])
        row['tails'].append(entry)
        groups[tail].append(entry)
    duplicates = []
    for tail, entries in groups.items():
        if len(entries) > 1:
            # Retain one existing suffix, charge a new success RET and rel32
            # error jump to each duplicate. Original prefix branch retargeting
            # and sizing can change this local bound and need source testing.
            duplicates.append(dict(byte_sequence=tail.hex(), copies=len(entries),
                                   bytes=len(tail), modes=sorted({r['mode'] for r in entries}),
                                   zero_starts=[r['zero_start'] for r in entries],
                                   local_saving_bound=(len(entries)-1)*(len(tail)-6)))
    row['duplicate_groups'] = duplicates
    row['local_saving_bound'] = sum(r['local_saving_bound'] for r in duplicates)
    totals.update(emitted=1, payload_bytes=len(data), probe_ranges=sum(
        r['piece'] == 'probe_read' for r in request['lto_ranges']),
        zero_tails=len(row['tails']), duplicate_groups=len(duplicates),
        duplicate_copies=sum(r['copies']-1 for r in duplicates),
        local_saving_bound=row['local_saving_bound'],
        protected_suffixes=sum(bool(r['protected_loads']) for r in row['tails']),
        relocated_suffixes=sum(bool(r['relocations']) for r in row['tails']))
    rows.append(row)

result = dict(scope='Static bound from decoded current emitted probe regions; exact suffix '
              'bytes, numeric and named helper selection, fixed counts and errors retained. '
              'A duplicate contributes suffix bytes minus six for a success RET and error '
              'JMP. Prefix retargeting/sizing, installed bytes and performance need measurement.',
              replay=str(a.replay), index_errors=report['index_errors'],
              summary={k: dict(v) for k, v in sorted(summary.items())}, requests=rows)
a.output.mkdir(parents=True, exist_ok=True)
(a.output / 'inventory.json').write_text(json.dumps(result, indent=2) + '\n')
lines = [f"{app}: {s.get('emitted',0)}/{s['requests']} emit, "
         f"{s['probe_ranges']} probe regions, {s['zero_tails']} zero tails, "
         f"{s['duplicate_copies']} duplicate copies, {s['local_saving_bound']} B local bound, "
         f"protected/relocated suffixes {s['protected_suffixes']}/{s['relocated_suffixes']}"
         for app, s in result['summary'].items()]
(a.output / 'summary.txt').write_text('\n'.join(lines) + '\n')
print('\n'.join(lines))
