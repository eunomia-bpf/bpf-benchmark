"""Sum the linker's reported emitted ranges, without inferring runtime gains."""
import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--log', type=Path, required=True)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
programs = []
for line in args.log.read_text().splitlines():
    for prefix in ('native-link-lto-audit ', 'native-link-lto-range '):
        _, marker, payload = line.partition(prefix)
        if not marker:
            continue
        record = json.loads(payload)
        if prefix == 'native-link-lto-audit ':
            programs.append(dict(**record, ranges=[], appended_bytes_by_piece={}))
        else:
            program = programs[-1]
            if not 0 <= record['start'] <= record['end'] <= program['payload_bytes']:
                raise ValueError('LTO range exceeds the emitted payload')
            if record['bytes'] != record['end']-record['start']:
                raise ValueError('LTO range byte count disagrees with its endpoints')
            if any(record['start'] < old['end'] and old['start'] < record['end']
                   for old in program['ranges']):
                raise ValueError('LTO ranges overlap')
            program['ranges'].append(record)
            sizes = program['appended_bytes_by_piece']
            sizes[record['piece']] = sizes.get(record['piece'], 0)+record['bytes']
for program in programs:
    program['remaining_payload_bytes'] = program['payload_bytes']-sum(program['appended_bytes_by_piece'].values())
args.output.write_text(json.dumps(dict(programs=programs,
    scope='Exact appended routine bytes in retained-plan host replay; remaining payload includes original code and per-site transformations. Not an isolated per-call gain or a new kernel installation.'), indent=2)+'\n')
