"""Post-process one completed run with the frozen May workload parser."""
import importlib.util
import json
import math
from pathlib import Path
import re
import statistics
import sys

ROOT = Path(__file__).resolve().parents[4]
spec = importlib.util.spec_from_file_location('may_evaluation', ROOT/'kprog/docs/archive/native_eval_20260529.py')
parser = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = parser
spec.loader.exec_module(parser)
run, output = map(Path, sys.argv[1:3])
metadata = json.loads((run/'metadata.json').read_text())
app_files = list((run/'details/apps').glob('*.json'))
rows = []
for path in app_files:
    app = json.loads(path.read_text())
    row = dict(app=app['app'], status=app['status'], error=app.get('error'), run=str(run),
               stats=metadata['bpf_stats'], samples={}, tracked_programs={}, per_call_ns={})
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
