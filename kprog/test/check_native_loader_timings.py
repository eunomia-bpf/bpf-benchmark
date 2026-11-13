"""Check phase names, raw values and complete concurrent records from the real emitter."""
import json
from pathlib import Path
import subprocess
import sys

done = subprocess.run(sys.argv[1:], check=True, capture_output=True, text=True)
path = Path(done.stdout.strip())
rows = [json.loads(line) for line in path.read_text().splitlines()]
assert len(rows) == 80
assert sorted(row['original_fd'] for row in rows) == list(range(80))
phases = ['source_context_ns', 'manifest_ns', 'companion_total_ns', 'data_symbols_ns',
          'companion_map_ptr_extract_ns', 'companion_lookup_spec_ns', 'cache_lookup_ns',
          'native_link_exec_ns', 'native_link_read_ns', 'map_patch_ns', 'upload_ns', 'prog_load_ns']
for row in rows:
    assert [row[name] for name in phases] == list(range(1, 13))
    assert row['start_ns'] == 100 and row['end_ns'] == 200 and row['total_ns'] == 100
    assert row['replaced'] is True and row['native_fd'] == 23
    assert row['pid'] > 0 and row['tid'] > 0
assert len({row['tid'] for row in rows}) == 4
print(f'loader phase log PASS: 80 complete records, 12 phases, clock/FD fields, four writers; {path}')
