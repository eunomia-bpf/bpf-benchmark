#!/usr/bin/env python3
"""Check each captured duplicate's retained prefix, return and shared target."""
import argparse
import json
from pathlib import Path
import re
import subprocess

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--inventory', type=Path, required=True)
p.add_argument('--before', type=Path, required=True)
p.add_argument('--after', type=Path, required=True)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()
inventory = json.loads(a.inventory.read_text())
before = {r['capture']: r for r in json.loads(a.before.read_text())['requests']}
after = {r['capture']: r for r in json.loads(a.after.read_text())['requests']}

def decode(folder, region):
    text = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
        '-M', 'intel', '--no-show-raw-insn', f"--start-address={region['start']}",
        f"--stop-address={region['end']}", str(folder/'image.blob')], text=True)
    result = []
    for line in text.splitlines():
        if match := re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line):
            ip, op, args = match.groups()
            result.append((int(ip, 16), op, args))
    return result

rows = []
for request in inventory['requests']:
    groups = request.get('duplicate_groups', [])
    if not groups:
        continue
    b, n = before[request['capture']], after[request['capture']]
    bf, nf = Path(b['output']), Path(n['output'])
    old_bytes, new_bytes = (bf/'image.blob').read_bytes(), (nf/'image.blob').read_bytes()
    old_regions = [r for r in b['lto_ranges'] if r['piece'] == 'probe_read']
    new_regions = [r for r in n['lto_ranges'] if r['piece'] == 'probe_read']
    regions = {r['start']: (r, new_regions[i]) for i, r in enumerate(old_regions)}
    tails = {t['zero_start']: t for t in request['tails']}
    for group in groups:
        first = tails[group['zero_starts'][0]]
        first_old, first_new = regions[first['region_start']]
        target = first_new['end'] - group['bytes']
        retained = new_bytes[target:first_new['end']] == bytes.fromhex(group['byte_sequence'])
        for zero in group['zero_starts'][1:]:
            tail = tails[zero]
            old, new = regions[tail['region_start']]
            old_insns, new_insns = decode(bf, old), decode(nf, new)
            bp = [i for i in old_insns if i[0] < zero]
            np = new_insns[:-2]
            errors = []
            if not retained:
                errors.append('retained suffix bytes differ')
            if len(bp) != len(np):
                errors.append('prefix instruction counts differ')
            if new_insns[-2][1] != 'jmp' or int(new_insns[-2][2], 16) != target:
                errors.append('shared error target differs')
            if new_insns[-1] != (new['end']-1, 'ret', ''):
                errors.append('local success RET differs')
            mapped = {bi[0]: ni[0] for bi, ni in zip(bp, np)}
            mapped.update({zero: new_insns[-2][0], old['end']-1: new['end']-1})
            for index, (bi, ni) in enumerate(zip(bp, np)):
                oi, op, operand = bi
                ai, nop, noperand = ni
                if op != nop:
                    errors.append(f'prefix operation {index} differs')
                elif op.startswith('j'):
                    if mapped.get(int(operand, 16)) != int(noperand, 16):
                        errors.append(f'prefix branch {index} differs')
                else:
                    oe = old_insns[index+1][0]
                    ne = new_insns[index+1][0]
                    if old_bytes[oi:oe] != new_bytes[ai:ne]:
                        errors.append(f'prefix bytes {index} differ')
            rows.append(dict(app=request['app'], symbol=request['symbol'],
                capture=request['capture'], zero_start=zero, target=target,
                prefix_instructions=len(bp), errors=errors))
result = dict(scope='Decoded retained policy/copy/cleanup prefix and mapped success/error branches '
              'for every duplicated suffix in the captured emissions; helper ABI/runtime '
              'execution is separately covered by the existing driver matrix.',
              duplicates=len(rows), failures=sum(bool(r['errors']) for r in rows), cases=rows)
a.output.mkdir(parents=True, exist_ok=True)
(a.output/'validation.json').write_text(json.dumps(result, indent=2)+'\n')
print(f"{result['duplicates']} duplicate suffixes; {result['failures']} prefix/target/return failures")
raise SystemExit(int(bool(result['failures'])))
