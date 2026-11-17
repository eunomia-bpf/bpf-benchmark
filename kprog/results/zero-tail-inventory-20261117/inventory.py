#!/usr/bin/env python3
"""Inventory zero tails and retained helper combinations without rewriting code."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
capture = Path('/workspaces/kprog-raw/perf/20261116-host-link-replay')
fixture = Path('/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117/host-20261117T174028Z-2683911/fixture')
entries = json.loads((capture / 'emission-current/report.json').read_text())['entries']
roles = {
    'bpf_probe_read_user': ['scalar-user'],
    'bpf_probe_read_kernel': ['scalar-kernel'],
    'bpf_probe_read': ['scalar-user', 'scalar-kernel'],
    'bpf_probe_read_compat': ['scalar-user', 'scalar-kernel'],
    'bpf_probe_read_user_str': ['string-user'],
    'bpf_probe_read_kernel_str': ['string-kernel'],
    'bpf_probe_read_str': ['string-user', 'string-kernel'],
    'bpf_probe_read_compat_str': ['string-user', 'string-kernel'],
}

# Only the current generic handler has this setup. Decode from the start of
# each existing leaf so a byte match alone does not establish an instruction.
tails = []
tail_bytes = None
for stem in ['kernel', 'kernel-compact', 'user', 'user-compact',
             'kernel-string', 'kernel-string-compact', 'user-string', 'user-string-compact']:
    binary = fixture / (stem + '.bin')
    data = binary.read_bytes()
    assembly = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
        '-M', 'intel', '--no-show-raw-insn', str(binary)], text=True)
    instructions = []
    for line in assembly.splitlines():
        if match := re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line):
            ip, operation, operands = match.groups()
            instructions.append((int(ip, 16), operation, operands))
    marker = bytes.fromhex('4c89c74489c931d283f908')
    starts = [ip for ip, operation, operands in instructions
              if operation == 'mov' and operands == 'rdi,r8' and data[ip:ip+len(marker)] == marker]
    assert len(starts) == 1, stem
    start = starts[0]
    decoded = [row for row in instructions if row[0] >= start]
    assert decoded[-1][1] == 'ret' and decoded[-1][0] == len(data)-1, stem
    current = data[start:]
    if tail_bytes is None:
        tail_bytes = current
    else:
        assert current == tail_bytes, stem
    tails.append(dict(stem=stem, binary=str(binary), leaf_bytes=len(data), tail_start=start,
                      tail_bytes=len(current), instructions=decoded))

generic_bytes = len(tail_bytes)
# Keep the original RET for success; an error JMP rel32 needs five bytes.
# One existing tail remains as the shared target. This is an upper bound:
# fixed counts, changed branch widths and metadata/layout costs can reduce it.
per_duplicate_bound = generic_bytes - 1 - 5
rows = []
summaries = defaultdict(lambda: Counter(requests=0, payload_bytes=0, read_requests=0,
    multi_leaf_requests=0, read_helper_relocations=0, leaf_roles=0, extra_leaf_roles=0,
    generic_sharing_upper_bound_bytes=0))
distributions = defaultdict(Counter)
for entry in entries:
    command = entry['command']
    proof = Path(command[command.index('--input') + 1])
    assembly = subprocess.check_output(['readelf', '-rW', str(proof)], text=True)
    calls = Counter()
    for line in assembly.splitlines():
        fields = line.split()
        if len(fields) >= 5 and fields[2] == 'R_X86_64_PLT32' and fields[4] in roles:
            calls[fields[4]] += 1
    leaves = sorted({role for name in calls for role in roles[name]})
    extras = max(len(leaves)-1, 0)
    bound = extras * per_duplicate_bound
    row = dict(app=entry['app'], symbol=entry['symbol'], index=entry['index'],
        request=entry['request'], proof=str(proof), plan=entry['plan'],
        captured_payload_bytes=entry['payload_bytes'], helper_relocations=dict(calls),
        possible_leaf_roles=leaves, generic_sharing_upper_bound_bytes=bound)
    rows.append(row)
    c = summaries[entry['app']]
    c.update(requests=1, payload_bytes=entry['payload_bytes'], read_requests=bool(leaves),
        multi_leaf_requests=len(leaves)>1, read_helper_relocations=sum(calls.values()),
        leaf_roles=len(leaves), extra_leaf_roles=extras, generic_sharing_upper_bound_bytes=bound)
    distributions[entry['app']][len(leaves)] += 1

result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Static inventory, not a new emission, installed-byte measurement or per-call experiment. '
          'PLT32 relocations in 239 retained 2026-11-16 extracted entry proofs identify possible '
          'read leaves under the current selection. Numeric transfers and future loaded programs '
          'are not inferred. Fixed count/domain meets are deliberately not guessed. All counted '
          'leaves treated as generic gives an upper bound; current constant tails, branch-width '
          'changes and layout/metadata cost can lower it. Historical payload totals are context '
          'only and are not current image installed totals.',
    generic_tail_bytes_including_ret=generic_bytes,
    shared_error_jump_bytes=5, local_success_ret_bytes=1,
    maximum_bytes_saved_per_additional_generic_leaf=per_duplicate_bound,
    fixture_tails=tails,
    summaries={app: dict(c, leaf_role_distribution=dict(distributions[app]))
               for app, c in sorted(summaries.items())}, requests=rows)
(args.output / 'inventory.json').write_text(json.dumps(result, indent=2)+'\n')
lines = ['app requests reads multi_leaf extra_roles upper_bound_bytes historical_payload_bytes']
for app, c in sorted(summaries.items()):
    lines.append(f"{app} {c['requests']} {c['read_requests']} {c['multi_leaf_requests']} "
                 f"{c['extra_leaf_roles']} {c['generic_sharing_upper_bound_bytes']} {c['payload_bytes']}")
(args.output / 'summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
print(f'{len(tails)} decoded current generic tails identical, {generic_bytes} bytes each; '
      f'upper bound {per_duplicate_bound} bytes per extra leaf')
