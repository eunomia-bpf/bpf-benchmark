"""Post-process one completed run with the frozen May workload parser."""
import ast
import hashlib
import json
import math
from pathlib import Path
import re
import statistics
from types import SimpleNamespace
from typing import Any
import sys

ROOT = Path(__file__).resolve().parents[4]
source = (ROOT/'kprog/docs/archive/native_eval_20260529.py').read_bytes()
# Execute the unchanged metric functions without importing the plot-only
# dependencies or running the archive's paper-output routines.
names = {'text_metrics', 'workload_metric', 'phase_samples', 'bpf_aggregate'}
constants = {'STRESS_RE', 'OPS_RE', 'PPS_RE'}
module = ast.parse(source)
selected = [node for node in module.body if
    (isinstance(node, ast.FunctionDef) and node.name in names) or
    (isinstance(node, ast.Assign) and any(isinstance(n, ast.Name) and n.id in constants for n in node.targets))]
namespace = dict(re=re, math=math, Any=Any)
exec(compile(ast.Module(body=selected, type_ignores=[]), 'native_eval_20260529.metrics', 'exec'), namespace)
parser = SimpleNamespace(**namespace)
run, output = map(Path, sys.argv[1:3])
metadata = json.loads((run/'metadata.json').read_text())
app_files = list((run/'details/apps').glob('*.json'))
rows = []
for path in app_files:
    app = json.loads(path.read_text())
    row = dict(app=app['app'], status=app['status'], error=app.get('error'), run=str(run),
               stats=metadata['bpf_stats'], parser_sha256=hashlib.sha256(source).hexdigest(), samples={}, tracked_programs={}, per_call_ns={})
    errors = 0
    for phase in ('baseline', 'post_rejit'):
        samples = parser.phase_samples(app, phase)
        row['samples'][phase] = [sample[0] for sample in samples]
        errors += sum(sample[2] for sample in samples)
        per_call, retained, tracked = parser.bpf_aggregate(app, phase)
        row['tracked_programs'][phase] = tracked
        row['per_call_ns'][phase] = per_call if math.isfinite(per_call) else None
    baseline, native = (row['samples'][p] for p in ('baseline','post_rejit'))
    row['throughput_native_over_ebpf'] = statistics.median(native)/statistics.median(baseline) if baseline and native else None
    row['workload_errors'] = errors
    log = run/'details/shim-logs'/(app['app'].replace('/','__')+'.post_rejit.log')
    row['native_load_records'] = []
    row['native_load_errors'] = []
    with log.open() as stream:
        for line in stream:
            if 'jit-info native ' in line:
                row['native_load_records'].append(dict(re.findall(r'(\w+)=(\S+)',line)))
            elif 'native-loader failed ' in line:
                row['native_load_errors'].append(line.strip())
    rows.append(row)
output.write_text(json.dumps(rows,indent=2)+'\n')
for row in rows:
    print(row['app'],row['status'],row['throughput_native_over_ebpf'],row['workload_errors'],len(row['native_load_records']))
