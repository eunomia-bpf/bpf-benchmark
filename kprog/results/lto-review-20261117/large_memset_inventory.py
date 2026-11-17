#!/usr/bin/env python3
"""Decode the retained OTel zero-fill example; never emit or execute code."""
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
blob = Path('/workspaces/kprog-raw/perf/20261116-host-link-replay/emission-current/130-0/image.blob')
assembly = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
                                    '-M', 'intel', '--no-show-raw-insn', str(blob)], text=True)
rows = []
for line in assembly.splitlines():
    match = re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)', line)
    if match:
        rows.append((int(match[1], 16), match[2], match[3]))
start = 0x1ad5
end = next(row[0]+1 for row in rows if row[0] >= start and row[1] == 'ret')
calls = [dict(offset=row[0], preceding_instructions=rows[max(0, i-3):i+1])
         for i, row in enumerate(rows) if row[1:] == ('call', hex(start))]


def region(first, last):
    return [row for row in rows if first <= row[0] < last]


# Decoded successful 668-byte path: 20*32 + 3*8 + 4; no 2/1-byte tail.
path = (region(start, 0x1ae1) + region(0x1ae1, 0x1afe)*20 +
        region(0x1afe, 0x1b04) + region(0x1b04, 0x1b15)*3 +
        region(0x1b15, 0x1b21) + region(0x1b21, 0x1b26) +
        region(0x1b2e, 0x1b33) + region(0x1b36, end))
stage = here.parents[2] / 'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o'
stage_assembly = subprocess.check_output(['objdump', '-drw', '-M', 'intel',
                                         '--disassemble=native_tracer_entry', str(stage)], text=True).splitlines()
stage_calls = [stage_assembly[max(0, i-1):i+4] for i, line in enumerate(stage_assembly)
               if 'edx,0x29c' in line]
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              blob=str(blob), helper_start=start, helper_bytes=end-start,
              direct_call_sites=calls, helper_disassembly=region(start, end),
              successful_668_byte_path=dict(instructions=len(path),
                   conditional_branches=sum(row[1].startswith('j') for row in path),
                   loop32_iterations=20, loop8_iterations=3, final_store_bytes=4),
              stage_P=dict(path=str(stage), mtime_ns=stage.stat().st_mtime_ns,
                           literal_668_windows=stage_calls,
                           scope='Current producer P only; not a post-context installed object.'),
              scope='Historical host-emitted local memset body and static successful path. Excludes caller setup/CALL and other program work; no dynamic frequency, current installed-cost, cycle or speedup claim.')
(here / 'large-memset.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(helper_bytes=end-start, direct_calls=len(calls),
                      successful_path=result['successful_668_byte_path'])))
