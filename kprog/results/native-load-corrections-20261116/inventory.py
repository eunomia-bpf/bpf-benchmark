"""Compare real native load IDs with the retained Tetragon counter window."""
from collections import Counter
import json
from pathlib import Path
import re
import sys

run, output = map(Path, sys.argv[1:])
data = json.loads(next((run / 'details/apps').glob('*.json')).read_text())
log = (run / 'details/shim-logs/tetragon__observer.post_rejit.log').read_text()
pending, loaded = {}, {}
for line in log.splitlines():
    match = re.search(r'pid=(\d+) tid=(\d+).*native-loader jit-info (original|native) fd=(\d+) id=(\d+) type=(\d+) name=(\S+).*jited_len=(\d+) xlated_len=(\d+)', line)
    if not match:
        continue
    pid, tid, kind, fd, ident, typ, name, jited, xlated = match.groups()
    row = dict(id=int(ident), type=int(typ), name=name, bytes_jited=int(jited), bytes_xlated=int(xlated))
    if kind == 'original':
        pending[pid, tid] = row
    else:
        loaded[int(ident)] = dict(native=row, original=pending.pop((pid, tid)))
window = data['post_rejit']['bpf']
seen = {v['id'] for v in window.values()}
missing = [v for ident, v in loaded.items() if ident not in seen]
result = dict(run=str(run), native_load_ids=len(loaded), native_window_ids=len(seen),
    baseline_window_ids=len(data['baseline']['bpf']),
    positive_records={ph:sum(v['run_cnt_delta'] > 0 for v in data[ph]['bpf'].values()) for ph in ['baseline','post_rejit']},
    loaded_outside_window=len(missing),
    outside_window_names=dict(Counter(v['native']['name'] for v in missing)),
    window_ids_not_in_load_log=sorted(seen-loaded.keys()),
    outside_window=missing,
    scope='An absent counter-window record does not prove zero calls or an attachment failure. No program is filtered; B-stock and path equivalence remain separate.')
output.write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps({k:v for k,v in result.items() if k != 'outside_window'},indent=2))
