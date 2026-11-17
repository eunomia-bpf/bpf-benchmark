#!/usr/bin/env python3
"""Use actual current-linker ranges to cover numeric as well as named helpers."""
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
root = Path('/workspaces/repository')
prior = Path('/workspaces/kprog-raw/perf/20261116-host-link-replay/emission-current/report.json')
fixture = Path('/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117/host-20261117T174028Z-2683911/fixture/kernel-compact.bin')
generic = fixture.read_bytes()[-42:]
assert generic[:11] == bytes.fromhex('4c89c74489c931d283f908') and generic[-1] == 0xc3
summaries = defaultdict(lambda: Counter(requests=0, ok=0, failed=0, payload_bytes=0,
    probe_ranges=0, generic_tails=0, requests_with_duplicate_generic_tails=0,
    removable_generic_tail_bytes_upper_bound=0))
rows = []
for entry in json.loads(prior.read_text())['entries']:
    folder = args.output / f"{entry['index']}-{entry['request']}"
    folder.mkdir()
    command = list(entry['command'])
    for option, name in [('--output', 'image.blob'), ('--output-relocs', 'image.relocs'),
                         ('--output-map-patches', 'image.maps'), ('--output-abi', 'image.abi')]:
        command[command.index(option)+1] = str(folder / name)
    command.append('--show')
    (folder / 'command.json').write_text(json.dumps(command, indent=2)+'\n')
    with (folder / 'stdout').open('w') as stdout, (folder / 'stderr').open('w') as stderr:
        status = subprocess.run(command, stdout=stdout, stderr=stderr).returncode
    row = dict(app=entry['app'], symbol=entry['symbol'], index=entry['index'],
               request=entry['request'], proof=command[command.index('--input')+1],
               plan=entry['plan'], output=str(folder), returncode=status)
    c = summaries[entry['app']]
    c.update(requests=1, ok=status==0, failed=status!=0)
    if status == 0:
        data = (folder / 'image.blob').read_bytes()
        ranges = []
        for line in (folder / 'stderr').read_text().splitlines():
            if line.startswith('native-link-lto-range '):
                region = json.loads(line.split(' ', 1)[1])
                if region['piece'] == 'probe_read':
                    ranges.append(region)
        tails = []
        for region in ranges:
            start, end = region['start'], region['end']
            if not data[start:end].endswith(generic):
                continue
            tail_start = end-len(generic)
            assembly = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
                '-M', 'intel', '--no-show-raw-insn', '--start-address='+str(start),
                '--stop-address='+str(end), str(folder / 'image.blob')], text=True)
            decoded = []
            for line in assembly.splitlines():
                if match := re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line):
                    ip, operation, operands = match.groups()
                    decoded.append((int(ip, 16), operation, operands))
            assert (tail_start, 'mov', 'rdi,r8') in decoded
            assert decoded[-1] == (end-1, 'ret', '')
            tails.append(dict(range_start=start, range_end=end, tail_start=tail_start,
                              tail_bytes=len(generic)))
        bound = max(len(tails)-1, 0) * (len(generic)-6)
        row.update(payload_bytes=len(data), probe_ranges=ranges, generic_tails=tails,
                   removable_generic_tail_bytes_upper_bound=bound)
        c.update(payload_bytes=len(data), probe_ranges=len(ranges), generic_tails=len(tails),
            requests_with_duplicate_generic_tails=len(tails)>1,
            removable_generic_tail_bytes_upper_bound=bound)
    else:
        row['error_tail'] = (folder / 'stderr').read_text()[-2500:]
    rows.append(row)
    (folder / 'result.json').write_text(json.dumps(row, indent=2)+'\n')
    print(entry['app'], entry['symbol'], 'returncode', status, flush=True)

result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    source_commit=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
    scope='Current linker kernel-mode replay of all 239 retained extracted entry proofs and their '
          'captured helper/map/layout facts. No current-P re-extraction, new load, guest, image or '
          'timing. Actual emitted range tails include numeric helper transfers; only exact '
          'decoded generic-tail duplicates are counted. Fixed-count tails and generated programs '
          'not in these requests are outside this saving bound. Five-byte error jump plus a '
          'local success RET is charged for each duplicate, with the first tail reused. Branch '
          'widening and layout costs can reduce the gain. These are host payload bytes, not '
          'kernel-installed bytes or a measured candidate saving.',
    summaries={app: dict(c) for app, c in sorted(summaries.items())}, requests=rows)
(args.output / 'emitted-inventory.json').write_text(json.dumps(result, indent=2)+'\n')
lines = ['app requests ok failed probe_ranges generic_tails duplicate_requests upper_bound_bytes payload_bytes']
for app, c in sorted(summaries.items()):
    lines.append(f"{app} {c['requests']} {c['ok']} {c['failed']} {c['probe_ranges']} "
                 f"{c['generic_tails']} {c['requests_with_duplicate_generic_tails']} "
                 f"{c['removable_generic_tail_bytes_upper_bound']} {c['payload_bytes']}")
(args.output / 'emitted-summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines), flush=True)
raise SystemExit(int(any(c['failed'] for c in summaries.values())))
