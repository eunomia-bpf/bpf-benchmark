#!/usr/bin/env python3
"""Read retained link outputs; no linking, builds, guests or admission checks."""
import collections
import json
from pathlib import Path
import re
import struct
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
RAW = Path('/workspaces/kprog-raw/perf/20261116-inner-array-lto/libbpf')
blob = RAW / 'otel-typed.blob'
data = blob.read_bytes()
ranges = []
for line in (RAW / 'otel-typed-kernel.log').read_text().splitlines():
    if line.startswith('native-link-lto-range '):
        ranges.append(json.loads(line.split(' ', 1)[1]))
array = next(r for r in ranges if r['piece'] == 'runtime_array')
lpm = next(r for r in ranges if r['piece'] == 'lpm_lookup')
call = array['start'] + 57
destination = call + 5 + int.from_bytes(data[call + 1:call + 5], 'little', signed=True)
read = next(r for r in ranges if r['piece'] == 'probe_read')
assembly = subprocess.check_output([
    'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
    '--no-show-raw-insn', str(blob)], text=True)
instructions = []
for line in assembly.splitlines():
    match = re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line)
    if match:
        instructions.append((int(match[1], 16), match[2], match[3], line))
read_calls = []
literal_counts = collections.Counter()
with (HERE / 'read-call-sites.disassembly.txt').open('w') as output:
    output.write('Local windows only: nearby ESI literals are not full CFG proofs or execution frequencies.\n')
    for index, instruction in enumerate(instructions):
        if instruction[1:3] != ('call', hex(read['start'])):
            continue
        read_calls.append(instruction[0])
        window = instructions[max(0, index - 2):index + 1]
        for previous in reversed(window[:-1]):
            if previous[1] == 'mov' and previous[2].startswith('esi,0x'):
                literal_counts[int(previous[2].split(',')[1], 16)] += 1
                break
        output.write('\n' + '\n'.join(item[3] for item in window) + '\n')
tracee = json.loads((REPO / 'kprog/results/host-link-replay-20261116/tracee-inputs.json').read_text())
counts = collections.Counter()
examples = {}
for entry in tracee:
    folder = Path(entry['folder'])
    plan = json.loads((folder / 'link-plan.json').read_text())
    names = collections.defaultdict(list)
    for helper in plan['helpers']:
        names[helper['addr']].append(helper['name'])
    for offset, kind, target in struct.iter_unpack('<IIQ', (folder / 'shared.relocs').read_bytes()):
        aliases = sorted(n for n in names[target] if 'probe_read' in n)
        if kind == 1 and aliases:
            key = '/'.join(aliases)
            counts[key] += 1
            examples.setdefault(key, dict(symbol=entry['symbol'], folder=str(folder), offset=offset))
with (HERE / 'compat-read-sites.disassembly.txt').open('w') as output:
    output.write('External E8 slots remain unpatched; helper identity comes from the retained relocation and plan.\n')
    for aliases, example in examples.items():
        example_blob = Path(example['folder']) / 'shared.blob'
        decoded = subprocess.check_output([
            'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
            '--no-show-raw-insn', str(example_blob)], text=True)
        lines = [line for line in decoded.splitlines() if re.match(r'^\s*[0-9a-f]+:', line)]
        output.write('\n' + aliases + '\n' + str(example_blob) + '\n')
        for index, line in enumerate(lines):
            if int(line.split(':', 1)[0].strip(), 16) == example['offset']:
                output.write('\n'.join(lines[max(0, index - 5):index + 1]) + '\n')
probe_sites = []
for line in (RAW / 'otel-typed.abi').read_text().splitlines():
    if line.startswith('load_site\t'):
        offset, length, destination_register = map(int, line.split('\t')[1].split(','))
        if read['start'] <= offset < read['end'] and destination_register == 11:
            probe_sites.append(dict(offset=offset, instruction_bytes=length,
                                    recovery_register=destination_register))
prefix = [i for i in instructions if 0x74b8 <= i[0] < 0x74c1]
word = [i for i in instructions if 0x74c1 <= i[0] < 0x74e4]
suffix = [i for i in instructions if 0x74e4 <= i[0] < 0x74ec]
copy_model = []
for size in sorted(literal_counts):
    words = size // 8
    path = prefix + word * words + suffix
    copy_model.append(dict(size_bytes=size, word_iterations=words, instructions=len(path),
                           conditional_branches=sum(i[1].startswith('j') for i in path)))
result = {
    'recorded_utc': subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    'review_source_commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=REPO, text=True).strip(),
    'typed_unwinder': {'blob': str(blob), 'payload_bytes': len(data), 'ranges': ranges,
                      'array_fallback_call': call, 'array_fallback_destination': destination,
                      'lpm_start': lpm['start'],
                      'read_call_sites': read_calls,
                      'nearby_esi_literals_bytes': dict(literal_counts),
                      'probe_recovery_sites': probe_sites,
                      'successful_copy_loop_model': copy_model,
                      'copy_model_scope': 'Decoded 0x74b8..0x74ec path, nonzero multiple-of-eight literal sizes, all loads succeed. Excludes policy, cleanup, callees and cycles.',
                      'read_scope': 'Local decoded windows, not a complete CFG constant proof or dynamic frequency.'},
    'tracee': {'inputs': 'kprog/results/host-link-replay-20261116/tracee-inputs.json',
               'captured_programs': len(tracee), 'remaining_static_helper_call_sites': dict(counts),
               'examples': examples,
               'scope': 'Static relocation sites in retained per-entry blobs, not dynamic call counts; shared callee text may recur across entries.'},
}
(HERE / 'evidence.json').write_text(json.dumps(result, indent=2) + '\n')
selected = [r for r in ranges if r['piece'] in ('runtime_array', 'probe_read', 'lpm_lookup')]
with (HERE / 'typed-unwinder.disassembly.txt').open('w') as output:
    output.write('Retained host-linked payload; external helper E8 slots are not yet kernel patched.\n')
    for region in selected:
        output.write('\n' + json.dumps(region) + '\n')
        subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
                        '--start-address=' + str(region['start']), '--stop-address=' + str(region['end']),
                        str(blob)], stdout=output, check=True)
print(json.dumps({'payload_bytes': len(data), 'array_fallback': hex(destination),
                  'tracee_static_sites': dict(counts)}))
