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
hash_plan_path = REPO / 'kprog/results/shared-hash-regression-20261116/katran-copy.link-plan.json'
hash_plan = json.loads(hash_plan_path.read_text())
hash_binary = Path('/workspaces/kprog-raw/perf/20261116-shared-hash-regression/katran.copied-hash.bin')
with (HERE / 'hash-dispatch.disassembly.txt').open('w') as output:
    subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
                    '--start-address=0', '--stop-address=71', str(hash_binary)],
                   stdout=output, check=True)
packet = Path('/workspaces/kprog-raw/perf/20261116-cilium-packet/run')
pair = json.loads((packet / 'packet-programs.json').read_text())
installed = json.loads((packet / 'post_rejit.jit-lines.json').read_text())
tail_programs = []
with (HERE / 'cilium-tail.disassembly.txt').open('w') as output:
    output.write('Same-load original/native code evidence; packet test did not execute. Offsets are relative to each dump.\n')
    for arm in ('original', 'native'):
        program = next(p for p in installed['programs'] if p['id'] == pair[arm])
        binary = packet / program['binary']
        decoded = subprocess.check_output([
            'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
            '--no-show-raw-insn', str(binary)], text=True)
        lines = [line for line in decoded.splitlines() if re.match(r'^\s*[0-9a-f]+:', line)]
        sites = []
        output.write(f'\n{arm} id={program["id"]} bytes={program["jited_bytes"]}\n{binary}\n')
        for index, line in enumerate(lines):
            if 'cmp' not in line or 'QWORD PTR [rax],0x21' not in line:
                continue
            sites.append(int(line.split(':', 1)[0], 16))
            end = index + 1
            while end < len(lines) and not re.search(r':\s+jmp\s', lines[end]):
                end += 1
            output.write('\n' + '\n'.join(lines[max(0, index - 7):end + 1]) + '\n')
        tail_programs.append(dict(arm=arm, id=program['id'], name=program['name'],
                                  installed_bytes=program['jited_bytes'], binary=str(binary),
                                  tail_counter_compare_offsets=sites))
tetragon_run = REPO / 'corpus/results/x86_kvm_corpus_20261116_232540_669421'
tetragon_app = json.loads((tetragon_run / 'details/apps/tetragon__observer.json').read_text())
tetragon_result = json.loads((tetragon_run / 'details/result.json').read_text())
tetragon_logs = {phase: tetragon_run / f'details/shim-logs/tetragon__observer.{phase}.log'
                 for phase in ('baseline', 'post_rejit')}
native_loads = []
attachments = {}
for phase, path in tetragon_logs.items():
    hooks = {}
    for line in path.read_text().splitlines():
        match = re.match(r'\[([0-9.]+).*BPF_TASK_FD_QUERY .*fd_type=(\d+) prog_id=(\d+).*symbol=(\S+)', line)
        if match:
            hooks[int(match[3])] = dict(symbol=match[4], monotonic_s=float(match[1]), fd_type=int(match[2]))
        if phase == 'post_rejit':
            match = re.match(r'\[([0-9.]+).*native-loader jit-info native .*? id=(\d+) ', line)
            if match:
                native_loads.append(dict(monotonic_s=float(match[1]), id=int(match[2])))
    attachments[phase] = hooks
native_window = {int(value['id']) for value in tetragon_app['post_rejit']['bpf'].values()}
represented = [row for row in native_loads if row['id'] in native_window]
absent = [row for row in native_loads if row['id'] not in native_window]
last_represented = max(represented, key=lambda row: row['monotonic_s'])
late = [row for row in absent if row['monotonic_s'] > last_represented['monotonic_s']]
outside_attached = []
for load in absent:
    hook = attachments['post_rejit'].get(load['id'])
    if hook:
        baseline_matches = [value for value in tetragon_app['baseline']['bpf'].values()
                            if (candidate := attachments['baseline'].get(int(value['id'])))
                            and candidate['symbol'] == hook['symbol'] and candidate['fd_type'] == hook['fd_type']]
        outside_attached.append(dict(native_id=load['id'], **hook,
                                      baseline_hook_records=[{'id': value['id'], 'calls': value['run_cnt_delta']}
                                                             for value in baseline_matches]))
timeline = dict(run=str(tetragon_run), logs={key: str(path) for key, path in tetragon_logs.items()},
                protocol={key: tetragon_result[key] for key in ('warmups', 'samples', 'workload_seconds')},
                native_loads=len(native_loads), native_window_ids=len(native_window),
                absent_ids=len(absent), last_represented_load=last_represented,
                absent_loaded_later=late, absent_loaded_earlier=[row for row in absent if row not in late],
                outside_window_attached=outside_attached,
                scope='Load/attachment timestamps only, not exact measurement-request times. Hook matches can be nonunique; no equality of exposure or zero-call conclusion.')
(HERE / 'tetragon-timeline.json').write_text(json.dumps(timeline, indent=2) + '\n')
emissions = json.loads((REPO / 'kprog/results/host-link-replay-20261116/emission-report.json').read_text())
wrapper_coverage = collections.defaultdict(lambda: dict(available=0, wrapped_prefix=0))
for entry in emissions['entries']:
    command = entry['command']
    output = Path(command[command.index('--output') + 1])
    prefix = output.read_bytes()[:18]
    row = wrapper_coverage[entry['app']]
    row['available'] += 1
    row['wrapped_prefix'] += int(prefix.startswith(bytes.fromhex('4883ec08e8'))
                                  and prefix[9:14] == bytes.fromhex('4883c408e9'))
wrapper_fixture = Path('/workspaces/kprog-raw/perf/20261116-conditional-tail/after-abi/choose.blob')
fixture_prefix = wrapper_fixture.read_bytes()[:18]
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
    'katran_hash': {'plan': str(hash_plan_path), 'copied_hash': str(hash_binary),
                    'copied_bytes': hash_binary.stat().st_size,
                    'selected_lookup_shapes': [item for item in hash_plan['lookup_maps']
                                               if item['name'] in ('vip_map', 'fallback_cache', 'lru_mapping')],
                    'scope': 'Return offsets include rounded key size, not an exact key-length fact. Copied hash has runtime length dispatch.'},
    'cilium_tail': {'capture': str(packet), 'boot_id': installed['boot_id'],
                    'programs': tail_programs,
                    'scope': 'Same-load shadow original/native functions; live program-array values may already be native. Code-shape evidence, not a standalone eBPF chain or executed packet comparison.'},
    'entry_wrapper_coverage': {'inventory': 'kprog/results/host-link-replay-20261116/emission-report.json',
                                'apps': dict(wrapper_coverage),
                                'positive_fixture': str(wrapper_fixture),
                                'positive_fixture_prefix_hex': fixture_prefix.hex(),
                                'scope': 'Exact 18-byte entry-wrapper opcode shape only, ignoring call/jump displacements. Historical host emissions; Tetragon coverage is only two programs, not the later CEL-loaded set.'},
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
