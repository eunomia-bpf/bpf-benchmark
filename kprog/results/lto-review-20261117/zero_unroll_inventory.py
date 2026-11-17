#!/usr/bin/env python3
"""Inventory retained constant zero-fill definitions and decode one output."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
report = repo / 'kprog/results/host-link-replay-20261116/emission-report.json'
entries = json.loads(report.read_text())['entries']
definitions = []
pattern = re.compile(
    r'  - (__native_link_local_memset_zero_(\d+)) '
    r'\(vaddr (0x[0-9a-f]+), (\d+) bytes\)')
for entry in entries:
    command = entry['command']
    log = Path(command[command.index('--output') + 1]).parent / 'stderr'
    for lineno, line in enumerate(log.read_text().splitlines(), 1):
        if match := pattern.fullmatch(line):
            name, count, address, size = match.groups()
            if int(count) >= 128:
                definitions.append(dict(app=entry['app'], entry=entry['symbol'],
                                        routine=name, zero_bytes=int(count),
                                        input_function_bytes=int(size),
                                        input_function_address=int(address, 16),
                                        log=str(log), line=lineno))
groups = []
for app, length in sorted({(e['app'], e['zero_bytes']) for e in definitions}):
    selected = [e for e in definitions if (e['app'], e['zero_bytes']) == (app, length)]
    groups.append(dict(app=app, zero_bytes=length, definitions=len(selected),
                       distinct_entry_symbols=len({e['entry'] for e in selected}),
                       input_function_sizes=dict(Counter(e['input_function_bytes'] for e in selected)),
                       summed_input_function_bytes=sum(e['input_function_bytes'] for e in selected)))

blob = Path('/workspaces/kprog-raw/perf/20261116-host-link-replay/emission-current/301-0/image.blob')
data = blob.read_bytes()
rows = []
assembly = subprocess.check_output([
    'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
    '--no-show-raw-insn', str(blob)], text=True)
for line in assembly.splitlines():
    if match := re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)', line):
        address, operation, operands = match.groups()
        rows.append((int(address, 16), operation, operands))
decoded = []
for i, row in enumerate(rows):
    if data[row[0]:row[0] + 6] != bytes.fromhex('4889f84531c0'):
        continue
    tail = rows[i:]
    end = next(j for j, instruction in enumerate(tail) if instruction[1] == 'ret')
    body = tail[:end + 1]
    stores = [instruction for instruction in body
              if instruction[1] == 'mov' and instruction[2].startswith('QWORD PTR [rdi')]
    decoded.append(dict(start=row[0], end=body[-1][0] + 1,
                        bytes=body[-1][0] + 1 - row[0],
                        instructions=len(body), qword_stores=len(stores),
                        zero_bytes=len(stores) * 8, disassembly=body,
                        static_direct_calls=[call[0] for call in rows
                                             if call[1:] == ('call', hex(row[0]))]))
receipt = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    source_report=str(report.relative_to(repo)),
    scope='Historical per-entry input-function definitions, not dynamic calls or app installed bytes. Representative final emitted bodies are decoded separately. The >=128 selection only bounds this report; no new production cutoff or check is proposed.',
    groups=groups, definitions=definitions,
    final_output_example=dict(blob=str(blob), bytes=len(data),
                              entry='cgroup_bpf_run_filter_skb', zero_routines=decoded))
(here / 'zero-unroll.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(groups)
print('final example:', [(e['zero_bytes'], e['bytes'], e['instructions'],
                          len(e['static_direct_calls'])) for e in decoded])
