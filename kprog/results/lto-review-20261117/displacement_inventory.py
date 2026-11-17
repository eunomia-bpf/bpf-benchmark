#!/usr/bin/env python3
"""Inspect retained scalar field-access encodings; never emit a replacement candidate."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
evidence = json.loads((HERE / 'evidence.json').read_text())['typed_unwinder']
piece = next(r for r in evidence['ranges'] if r['piece'] == 'lpm_lookup')
assembly = subprocess.check_output([
    'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel', '--insn-width=15',
    '--start-address=' + str(piece['start']), '--stop-address=' + str(piece['end']),
    evidence['blob']], text=True)
rows = []
for line in assembly.splitlines():
    match = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*(.+)$', line)
    if not match or '[' not in match[3]:
        continue
    raw = bytes.fromhex(match[2])
    pos = 0
    while raw[pos] in (0x66, 0x67, 0xf0, 0xf2, 0xf3, 0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65) or 0x40 <= raw[pos] <= 0x4f:
        pos += 1
    opcode = raw[pos]
    modrm_at = pos + (2 if opcode == 0x0f else 1)
    scalar = opcode in (0x80, 0x81, 0x83, 0x8b, 0x8d, 0x3b, 0x33, 0xf7) or (opcode == 0x0f and raw[pos+1] == 0xb6)
    if not scalar or raw[modrm_at] >> 6 != 2:
        continue
    rm = raw[modrm_at] & 7
    sib = rm == 4
    base = (raw[modrm_at+1] & 7) if sib else rm
    disp_at = modrm_at + 1 + int(sib)
    displacement = int.from_bytes(raw[disp_at:disp_at+4], 'little', signed=True)
    shorter = 0 if displacement == 0 and base != 5 else (1 if -128 <= displacement <= 127 else 4)
    rows.append(dict(offset=int(match[1], 16), instruction=match[3].strip(), original_bytes=raw.hex(),
                     displacement=displacement, current_displacement_bytes=4,
                     possible_displacement_bytes=shorter, local_bytes_saved=4-shorter))
plan = Path('/workspaces/repository/corpus/results/shared-hash-regression-20261116/captures/link-ie2fmz97/link-plan.json')
facts = json.loads(plan.read_text())
lru = [{k: m[k] for k in ('name', 'key_offset', 'value_offset')}
       for m in facts['lookup_maps'] if m['kind'] == 'lru_hash']
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Retained LPM scalar base/index field accesses and Katran plan facts only. Byte arithmetic assumes the same addressing registers and immediate widths. No replacement bytes assembled/emitted/executed, no runtime check or whole-image/per-call claim. LRU facts do not count actual emitted or executed LRU sites.',
              blob=evidence['blob'], original_lpm_bytes=piece['bytes'], accesses=rows,
              eligible_accesses=sum(r['local_bytes_saved'] > 0 for r in rows),
              local_displacement_bytes_saved=sum(r['local_bytes_saved'] for r in rows),
              katran_plan=str(plan), retained_lru_map_facts=lru)
(HERE / 'displacements.json').write_text(json.dumps(result, indent=2) + '\n')
print('LPM eligible accesses:', result['eligible_accesses'], '; local bytes:', result['local_displacement_bytes_saved'])
print('Retained LRU facts:', lru)
