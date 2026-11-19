"""Read every completed functional check without treating counts as a gate."""
import json
from pathlib import Path
import re
import sys

snapshot = json.loads(Path(sys.argv[1]).read_text())
info = re.compile(
    r'pid=(\d+) tid=(\d+)\] native-loader jit-info '
    r'(original|native) fd=\d+ id=(\d+) type=\d+ name=\S* '
    r'tag=\S+ jited_len=(\d+)')
rows = []
for completed in snapshot['check_completed_apps']:
    run = Path(completed['run'])
    logs = sorted((run/'details/shim-logs').glob('*post_rejit*'))
    pending, pairs, failures = {}, {}, []
    replaced = 0
    for log in logs:
        for line_number, line in enumerate(log.read_text().splitlines(), 1):
            replaced += 'native-loader replaced ' in line
            if 'native-loader failed' in line:
                failures.append(dict(log=str(log), line=line_number, text=line))
            match = info.search(line)
            if match:
                pid, tid, kind, program_id, length = match.groups()
                key = (pid, tid)
                if kind == 'original':
                    pending[key] = int(length)
                elif key in pending:
                    pairs[program_id] = dict(
                        native_id=int(program_id), jit_bytes=pending.pop(key),
                        installed_bytes=int(length))
    rows.append(dict(
        **completed, suite_status=json.loads((run/'details/result.json').read_text())['status'],
        shim_logs=list(map(str, logs)), replacement_events=replaced,
        installed_programs=len(pairs), loader_failures=failures,
        jit_bytes=sum(pair['jit_bytes'] for pair in pairs.values()),
        installed_bytes=sum(pair['installed_bytes'] for pair in pairs.values()),
        programs=list(pairs.values())))
    print(f"{completed['app']}: rc={completed['exit_code']}, "
          f"{replaced} replacement events, {len(pairs)} installed IDs, "
          f"{len(failures)} loader failures")
Path(sys.argv[2]).write_text(json.dumps(dict(
    batch=snapshot['batch'], image_id=snapshot['image_id'], apps=rows,
    scope='Direct-native P functional check only. Counts are observations, '
          'not an admission gate, a B stock-verification census or timing.'
), indent=2)+'\n')
