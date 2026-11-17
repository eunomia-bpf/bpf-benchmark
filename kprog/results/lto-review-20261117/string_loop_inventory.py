#!/usr/bin/env python3
"""Finite source-loop illustrations, not a native-code test or timing gate."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent


def model(count, nul_at, fault_at, reordered):
    data = [65 + i % 26 for i in range(count + 1)]
    if nul_at is not None:
        data[nul_at] = 0
    destination = [0xa5] * (count + 2)
    reads = []
    writes = []
    loop_instructions = 0
    if not count:
        return dict(result=0, destination=destination, reads=reads, writes=writes,
                    loop_instructions=0, final_zero_store=False)
    remaining = count
    cursor = 0
    while True:
        reads.append(cursor)
        loop_instructions += 3  # source load, recovery-status TEST, fault branch
        if cursor == fault_at:
            for offset in range(count):
                destination[offset] = 0
                writes.append(dict(offset=offset, value=0, kind='fault_zero'))
            return dict(result=-14, destination=destination, reads=reads, writes=writes,
                        loop_instructions=loop_instructions, final_zero_store=False)
        value = data[cursor]
        destination[cursor] = value
        writes.append(dict(offset=cursor, value=value, kind='copy'))
        cursor += 1
        loop_instructions += 3  # store, destination increment, source increment
        if reordered:
            loop_instructions += 2  # byte TEST, NUL branch
            if value == 0:
                final_zero = False
                break
            remaining -= 1
            loop_instructions += 2  # DEC count, loop JNE using DEC's flags
            if not remaining:
                final_zero = True
                break
        else:
            remaining -= 1
            loop_instructions += 3  # DEC count, byte TEST, NUL branch
            if value == 0:
                final_zero = True
                break
            loop_instructions += 2  # count TEST, loop JNE
            if not remaining:
                final_zero = True
                break
    if final_zero:
        destination[cursor - 1] = 0
        writes.append(dict(offset=cursor - 1, value=0, kind='final_zero'))
    return dict(result=cursor, destination=destination, reads=reads, writes=writes,
                loop_instructions=loop_instructions, final_zero_store=final_zero)


rows = []
for count in (0, 1, 2, 4, 8, 16):
    for nul_at in sorted({0, max(0, count - 1), count}):
        for fault_at in [None, *range(count + 1)]:
            before = model(count, nul_at, fault_at, False)
            after = model(count, nul_at, fault_at, True)
            comparable = ('result', 'destination', 'reads')
            rows.append(dict(count=count, nul_at=nul_at, fault_at=fault_at,
                             before=before, after=after,
                             same_result_destination_and_source_accesses=all(
                                 before[key] == after[key] for key in comparable),
                             successful_loop_instructions_removed=before['loop_instructions'] - after['loop_instructions'],
                             stores_removed=len(before['writes']) - len(after['writes'])))
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Finite source-loop model of reordering DEC after the NUL branch, eliminating count TEST and skipping only the already-zero successful NUL store. Existing caller clears the full destination after -EFAULT. Policy denial and signed-int return conversion stay outside the modeled loop; no native code emitted, assembled or executed, no memory fault injected, no performance/implementation proof or new admission gate.',
              source='kprog/x86/native_lab/native_link/src/x86_probe_read.rs:189-199 at d6b4d335e',
              rows=rows,
              differing_observations=sum(not row['same_result_destination_and_source_accesses'] for row in rows))
(HERE / 'string-loop.json').write_text(json.dumps(result, indent=2) + '\n')
# Existing sole-kernel code, not a generated candidate.
helper = subprocess.check_output(['objdump', '-d', '--no-show-raw-insn',
    '--disassemble=strncpy_from_kernel_nofault',
    '/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'], text=True)
(HERE / 'kernel-string-copy.disassembly.txt').write_text(helper)
print(len(rows), 'source-loop illustrations;', result['differing_observations'],
      'result/destination/source-access differences')
