"""Read the frozen check's raw app statuses; Make's exit alone is insufficient."""
import json
from pathlib import Path
import re
import sys

raw = Path(sys.argv[1])
rows = []
for line in (raw / 'check/check.log').read_text().splitlines():
    match = re.fullmatch(r'(\S+) check (\S+) rc=(\d+) run=(.*)', line)
    stamp, app, rc, run = match.groups()
    row = dict(stamp=stamp, app=app, command_returncode=int(rc), run=run)
    if run:
        app_file, = (Path(run) / 'details/apps').glob('*.json')
        data = json.loads(app_file.read_text())
        row.update(status=data['status'], error=data['error'])
        for phase in ['baseline', 'post_rejit']:
            value = data[phase]
            if value is None:
                row[phase] = None
                continue
            programs = value['bpf']
            row[phase] = dict(programs=len(programs),
                installed_bytes=sum(p['bytes_jited'] for p in programs.values()),
                run_count=sum(p['run_cnt_delta'] for p in programs.values()),
                run_time_ns=sum(p['run_time_ns_delta'] for p in programs.values()))
    else:
        row.update(status='no_result', error='No app result path in the frozen check log')
    rows.append(row)
result = dict(image=(raw / 'image.id').read_text().strip(),
    kernel_source=(raw / 'kernel-source.commit').read_text().strip(),
    source=(raw / 'source.commit').read_text().strip(),
    scope='Frozen one-image check: one 10-second sample, stats on; functional evidence, not official timing.',
    apps=rows)
(raw / 'summary.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
