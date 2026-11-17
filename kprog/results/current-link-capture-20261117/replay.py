#!/usr/bin/env python3
"""Replay every actual captured kernel request with the current host linker."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
here = Path(__file__).resolve().parent
reference = Path('/workspaces/kprog-raw/perf/clock-field-operands-20261117/host-20261117T182038Z-2700640/fixture/kernel-compact.bin')
generic_tail = reference.read_bytes()[-42:]
summaries = defaultdict(Counter)
rows = []
index_errors = []
for name in ['otelcol-ebpf-profiler_profiling', 'bcc_set', 'cilium_agent',
             'tetragon_observer', 'tracee_monitor', 'katran']:
    try:
        index = json.loads((here / (name+'.json')).read_text())
    except (OSError, ValueError) as error:
        index_errors.append(dict(app=name, error=str(error)))
        continue
    for request in index['captures']:
        capture = Path(request['capture'])
        folder = args.output / name / capture.name
        folder.mkdir(parents=True)
        command = [str(Path('/workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link')),
                   *json.loads((capture / 'adapter.json').read_text())['argv']]
        for option, value in [('--input', request['proof']), ('--link-plan', request['plan']),
                              ('--output', str(folder/'image.blob')), ('--output-relocs', str(folder/'image.relocs')),
                              ('--output-map-patches', str(folder/'image.maps')), ('--output-abi', str(folder/'image.abi'))]:
            command[command.index(option)+1] = value
        if '--show' not in command:
            command.append('--show')
        (folder/'command.json').write_text(json.dumps(command, indent=2)+'\n')
        with (folder/'stdout').open('w') as stdout, (folder/'stderr').open('w') as stderr:
            status = subprocess.run(command, stdout=stdout, stderr=stderr).returncode
        row = dict(app=request['app'], symbol=request['symbol'], capture=str(capture),
            proof=request['proof'], plan=request['plan'], output=str(folder),
            captured_linker_returncode=request['linker_returncode'], returncode=status)
        c = summaries[request['app']]
        c.update(requests=1, ok=status==0, failed=status!=0)
        if status == 0:
            data = (folder/'image.blob').read_bytes()
            previous = capture/'image.blob'
            regions = [json.loads(line.split(' ',1)[1]) for line in (folder/'stderr').read_text().splitlines()
                       if line.startswith('native-link-lto-range ')]
            generic = [region for region in regions if region['piece']=='probe_read'
                       and data[region['start']:region['end']].endswith(generic_tail)]
            bound = max(0, len(generic)-1)*36
            row.update(payload_bytes=len(data), captured_payload_bytes=previous.stat().st_size if previous.is_file() else None,
                lto_ranges=regions, generic_zero_tail_ranges=generic,
                generic_zero_tail_sharing_upper_bound_bytes=bound)
            c.update(payload_bytes=len(data), generic_zero_tails=len(generic), sharing_upper_bound_bytes=bound)
        else:
            row['error_tail'] = (folder/'stderr').read_text()[-2500:]
        (folder/'result.json').write_text(json.dumps(row, indent=2)+'\n')
        rows.append(row)
        print(request['app'], request['symbol'], 'returncode', status, flush=True)
result = dict(scope='Current host linker, exact paired actual capture inputs and flags; no added layout facts. '
    'Request counts are not installed-program counts. Byte totals are neutral host payloads, not installed '
    'native/JIT sizes or timing. Generic-tail bounds use exact emitted suffixes and are not a candidate '
    'measurement; branch/layout cost and fixed tails require separate accounting.',
    summaries={app:dict(c) for app,c in sorted(summaries.items())}, index_errors=index_errors, requests=rows)
(args.output/'replay.json').write_text(json.dumps(result,indent=2)+'\n')
lines = ['app requests ok failed payload_bytes generic_zero_tails sharing_upper_bound_bytes']
for app,c in sorted(summaries.items()):
    lines.append(' '.join([app, *[str(c[key]) for key in ['requests','ok','failed','payload_bytes','generic_zero_tails','sharing_upper_bound_bytes']]]))
lines.append(f'index_errors {len(index_errors)}')
(args.output/'replay-summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines),flush=True)
raise SystemExit(int(bool(index_errors) or any(c['failed'] for c in summaries.values())))
