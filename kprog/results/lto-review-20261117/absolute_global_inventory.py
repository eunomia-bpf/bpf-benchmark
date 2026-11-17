#!/usr/bin/env python3
"""Review address encodability and source lengths, without reading live kernel memory."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
MASK = (1 << 64) - 1


def fits_absolute_disp32(address):
    low = address & 0xffffffff
    extended = low if low < (1 << 31) else low | (MASK ^ 0xffffffff)
    return extended == address


plan = Path('/workspaces/repository/corpus/results/shared-hash-regression-20261116/captures/link-ie2fmz97/link-plan.json')
layout = json.loads(plan.read_text())['kernel_layout']['probe_read']
addresses = [dict(field='USER_PTR_MAX', address=hex(layout['user_ptr_max'])),
             dict(field='SMAP capability word', address=hex(
                 layout['boot_cpu_data'] + layout['x86_capability'] + 9*4))]
for row in addresses:
    row['absolute_disp32_encodable'] = fits_absolute_disp32(int(row['address'], 16))
boundaries = [0, 0x7fffffff, 0x80000000, 0xffffffff7fffffff,
              0xffffffff80000000, 0xffffffffffffffff, 0xffff888000000000]
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Captured guest address facts and encoding arithmetic only. No candidate bytes, assembler, compiler, guest, kernel-memory read, new refusal or installed-size/per-call claim. Absolute addressing uses default 64-bit address size, signed disp32 and SIB base/index none; 67h would change semantics. Other addresses can retain existing MOVABS form.',
              retained_plan=str(plan), captured_addresses=addresses,
              boundary_encodability=[dict(address=hex(a), encodable=fits_absolute_disp32(a)) for a in boundaries],
              source_encoding_lengths=[
                  dict(operation='MOV RAX,live qword', before_bytes=13, absolute_bytes=8, instructions_removed=1),
                  dict(operation='TEST live capability dword,imm32', before_bytes=21, absolute_bytes=11, instructions_removed=1),
                  dict(operation='MOVZX ECX,live width byte', before_bytes=18, absolute_bytes=8, instructions_removed=1)],
              qualifications='Width-byte length is a generic source encoding case, not a captured width address here. Test the effective resolved address including field offset for encoding choice. No assumption that heap/map addresses or future guest addresses fit; no address-size override, no RIP-rel32 slot or literal pool needed.')
(HERE / 'absolute-globals.json').write_text(json.dumps(result, indent=2) + '\n')
print('Captured address encodability:', addresses)
