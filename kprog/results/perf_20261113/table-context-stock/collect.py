"""Keep a small receipt in git; full vectors remain in persistent raw storage."""
import hashlib
import json
from pathlib import Path

source = Path('/workspaces/kprog-raw/perf/20261115-table-context/final/result.json')
result = json.loads(source.read_text())
result['raw_result'] = str(source)
result['raw_result_sha256'] = hashlib.sha256(source.read_bytes()).hexdigest()
for key in ('host_executions', 'shared_simulator_executions'):
    rows = result.pop(key)
    result[key] = dict(cases=len(rows), equal=sum(row['actual'] == row['expected'] for row in rows))
(Path(__file__).resolve().parent/'host/result.json').write_text(json.dumps(result, indent=2)+'\n')
