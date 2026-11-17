#!/usr/bin/env python3
"""Extract existing fallback instruction spans; never link or execute them."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
inventory = json.loads((here / 'evidence.json').read_text())['typed_unwinder']
blob = Path(inventory['blob'])
data = blob.read_bytes()
rows = []
for region in inventory['ranges']:
    if region['piece'] not in ('runtime_array', 'lpm_lookup'):
        continue
    start = region['end'] - 14
    code = data[start:region['end']]
    assembly = subprocess.check_output([
        'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
        '--start-address=' + str(start), '--stop-address=' + str(region['end']),
        str(blob)], text=True)
    rows.append(dict(piece=region['piece'], fallback_start=start, bytes=len(code),
                     instruction_bytes=code.hex(),
                     call_opcode_offset=start+4,
                     encoded_destination=start+9+int.from_bytes(code[5:9], 'little', signed=True),
                     disassembly=assembly.split('Disassembly of section .data:\n', 1)[1].strip()))
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              blob=str(blob), payload_bytes=len(data), fallbacks=rows,
              scope='Retained successful typed OTel host emission, before external relocation. Encoded destination of a zero external E8 slot is not its installed helper address. No patch or performance measurement.')
(here / 'dispatch-fallbacks.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps([dict(piece=row['piece'], fallback_start=row['fallback_start'], bytes=row['bytes'])
                  for row in rows]))
