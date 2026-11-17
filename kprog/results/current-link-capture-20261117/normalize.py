#!/usr/bin/env python3
"""Render completed replay counters as integers without repeating any emission."""
import json
from pathlib import Path

here = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/current-link-capture-20261117/replay-20261117T190803Z-2714324')
result = json.loads((raw/'replay.json').read_text())
for counts in result['summaries'].values():
    counts['ok'] = int(counts['ok'])
    counts['failed'] = int(counts['failed'])
(here/'replay.json').write_text(json.dumps(result,indent=2)+'\n')
lines = ['app requests ok failed payload_bytes generic_zero_tails sharing_upper_bound_bytes']
for app,c in sorted(result['summaries'].items()):
    lines.append(' '.join([app,*[str(c[key]) for key in ['requests','ok','failed','payload_bytes','generic_zero_tails','sharing_upper_bound_bytes']]]))
lines.append(f"index_errors {len(result['index_errors'])}")
(here/'replay-summary.txt').write_text('\n'.join(lines)+'\n')
print('Normalized integer counters from completed raw replay; request rows and payloads unchanged.')
