#!/usr/bin/env python3
"""Count external helper relocations in retained host emissions, not executions."""
import collections
import json
from pathlib import Path
import re
import struct
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
inventory = repo / 'kprog/results/host-link-replay-20261116/emission-report.json'
entries = json.loads(inventory.read_text())['entries']
wanted = {'bpf_get_current_task', 'bpf_get_current_task_btf',
          'bpf_get_smp_processor_id', 'bpf_jiffies64',
          'bpf_get_current_pid_tgid', 'bpf_get_current_uid_gid', 'bpf_get_current_comm',
          'bpf_ktime_get_ns', '__native_x86_ktime_get_mono_fast_ns', 'ktime_get_mono_fast_ns',
          'bpf_ktime_get_boot_ns'}
counts = collections.defaultdict(collections.Counter)
examples = {}
programs = collections.defaultdict(set)
emission_entries = collections.defaultdict(collections.Counter)
for entry in entries:
    counts[entry['app']]
    entry_names = set()
    helpers = collections.defaultdict(list)
    for helper in json.loads(Path(entry['plan']).read_text())['helpers']:
        helpers[helper['addr']].append(helper['name'])
    command = entry['command']
    relocs = Path(command[command.index('--output-relocs') + 1])
    blob = Path(command[command.index('--output') + 1])
    for offset, kind, target in struct.iter_unpack('<IIQ', relocs.read_bytes()):
        names = set(helpers[target]) & wanted
        if kind != 1 or not names:
            continue
        name = '/'.join(sorted(names))
        entry_names.add(name)
        counts[entry['app']][name] += 1
        programs[(entry['app'], name)].add(entry['symbol'])
        key = (entry['app'], name)
        if key not in examples:
            assembly = subprocess.check_output([
                'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
                '--no-show-raw-insn', str(blob)], text=True).splitlines()
            index = next(i for i, line in enumerate(assembly)
                         if re.match(r'^\s*' + format(offset, 'x') + r':', line))
            examples[key] = dict(app=entry['app'], helper=name, symbol=entry['symbol'],
                                 blob=str(blob), relocations=str(relocs), offset=offset,
                                 helper_aliases=sorted(helpers[target]),
                                 disassembly=assembly[max(0, index-2):index+4])
    for name in entry_names:
        emission_entries[entry['app']][name] += 1
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              source_inventory=str(inventory), emitted_entries=len(entries),
              scope='External CALL relocations in historical host outputs; static per-entry sites can repeat shared source callees. No dynamic-frequency or current-image claim.',
              external_calls_by_app=dict(counts),
              emission_entries_with_calls_by_app=dict(emission_entries),
              represented_programs=[dict(app=app, helper=name, distinct_entry_symbols=len(values))
                                    for (app, name), values in programs.items()],
              examples=list(examples.values()))
(here / 'helper-parity.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(counts)))
