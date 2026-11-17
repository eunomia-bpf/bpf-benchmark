#!/usr/bin/env python3
"""Count individually shortenable branches in retained generated routines.

This does not rewrite, encode, build or execute any candidate code.
"""
from collections import Counter
import json
from pathlib import Path
import re
import struct
import subprocess

here = Path(__file__).resolve().parent
captured = Path('/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json')
fixture = json.loads(captured.read_text())
evidence = json.loads((here / 'evidence.json').read_text())['typed_unwinder']
blob = Path(evidence['blob'])
historical = blob.read_bytes()
assembly = subprocess.check_output([
    'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
    '-M', 'intel', '--no-show-raw-insn', str(blob)], text=True)
decoded = []
for line in assembly.splitlines():
    if match := re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line):
        address, operation, operands = match.groups()
        decoded.append((int(address, 16), operation, operands))

def inventory(data, instructions, first, last, piece):
    counters = Counter()
    candidates = []
    unshortened = []
    for ip, operation, operands in instructions:
        if not first <= ip < last:
            continue
        if data[ip:ip + 1] == b'\xe8' and operation == 'call':
            counters['call_rel32_slots_preserved'] += 1
        conditional = operation.startswith('j') and operation != 'jmp'
        if conditional and len(data) > ip + 5 and data[ip] == 15 and 128 <= data[ip + 1] <= 143:
            old_length, saving, displacement_at = 6, 4, ip + 2
        elif operation == 'jmp' and data[ip:ip + 1] == b'\xe9':
            old_length, saving, displacement_at = 5, 3, ip + 1
        else:
            continue
        kind = 'conditional' if conditional else 'unconditional'
        counters['near_' + kind] += 1
        displacement = struct.unpack_from('<i', data, displacement_at)[0]
        target = ip + old_length + displacement
        # If this branch alone shrinks, a forward target moves with it;
        # a backward target does not, shortening the backward distance.
        short_displacement = displacement + (saving if target < ip else 0)
        row = dict(offset=ip, operation=operation, target=target,
                   current_length=old_length,
                   displacement_if_only_this_branch_shrinks=short_displacement)
        if first <= target < last and -128 <= short_displacement <= 127:
            counters['shortenable_' + kind] += 1
            counters['local_bytes_removable'] += saving
            row['bytes_removable'] = saving
            candidates.append(row)
        else:
            unshortened.append(row)
    return dict(piece=piece, start=first, end=last, bytes=last-first,
                counts=dict(counters), independently_shortenable=candidates,
                other_near_branches=unshortened)

current = bytes.fromhex(fixture['instruction_bytes'])
reports = [dict(artifact='captured 4/2/1 user-read fixture', source=str(captured),
                routines=[inventory(current, fixture['instructions'], 0, len(current),
                                    'user_probe_read')])]
reports.append(dict(artifact='historical OTel typed-inner host emission', source=str(blob),
                    routines=[inventory(historical, decoded, r['start'], r['end'], r['piece'])
                              for r in evidence['ranges']]))
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Static branch widths in existing generated code ranges. Candidates fit signed rel8 when each is shrunk in isolation. No candidate bytes emitted, cycle estimate, installed-image size, or whole-image saving is claimed. External transfers, CALL slots, fault sites and relocations require their existing contracts.',
    artifacts=reports)
(here / 'branch-widths.json').write_text(json.dumps(result, indent=2) + '\n')
for report in reports:
    for routine in report['routines']:
        print(report['artifact'], routine['piece'], routine['bytes'], routine['counts'])
