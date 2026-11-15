"""Collect bounded codegen receipts; preserve vectors and full logs in raw storage."""
import hashlib
import json
from pathlib import Path
import shutil

raw = Path('/workspaces/kprog-raw/perf/20261115-checked-codegen')
out = Path(__file__).resolve().parent


def copy(source, destination):
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source, destination)


source = raw/'subsets/table/result.json'
table = json.loads(source.read_text())
vectors = table.pop('cases')
table.update(cases=len(vectors), equal=sum(row['actual'] == row['expected'] for row in vectors),
             raw_result=str(source), raw_sha256=hashlib.sha256(source.read_bytes()).hexdigest())
(out/'table').mkdir(parents=True, exist_ok=True)
(out/'table/result.json').write_text(json.dumps(table, indent=2)+'\n')
for name in ('commands.json', 'native-commands.jsonl', 'checked-simulator.json', 'frontend-ir-reuse.json'):
    copy(raw/'subsets/table'/name, out/'table'/name)
for name in ('commands.json', 'result.json'):
    copy(raw/'subsets/fault'/name, out/'fault'/name)
copy(raw/'subsets/packet/execution.json', out/'packet/execution.json')
copy(raw/'subsets/packet/target-btf.json', out/'packet/target-btf.json')
for mode in ('xdp', 'tc', 'cgroup_skb'):
    copy(raw/'subsets/packet'/mode/'link.json', out/'packet'/mode/'link.json')
for stage in ('build', 'host', 'subsets'):
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        copy(raw/stage/'job'/name, out/stage/name)
