"""Disjoint guest PMU roots in shim windows, with explicit ownership limits.

Counter ns/call is measured. PMU periods are cycles; external roots include
other guest work and are never converted into a fabricated body/helper/map
nanosecond split. Exact inline-template ranges separate maps/helpers in native
text. Remaining text also contains context, clock, percpu and tail operations.
"""
import bisect
from collections import Counter
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path('/workspaces/repository')
PROFILE = ROOT / 'kprog/perf/profile'
sys.path.insert(0, str(PROFILE))
import symbolize


def module(name, filename):
    spec = importlib.util.spec_from_file_location(name, PROFILE / filename)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


host = module('host_costs', 'host-costs.py')
windows = module('jit_windows', 'jit-window-costs.py')
raw, case = Path(sys.argv[1]), sys.argv[2]
capture = raw / case
run = Path(re.search(r'"artifact_run_dir":\s*"([^"]+)"', (capture / 'guest.log').read_text()).group(1))
app_file, = (run / 'details/apps').glob('*.json')
app_name = app_file.stem
app = json.loads(app_file.read_text())
with (capture / 'samples.txt').open('w') as output, (capture / 'decode.stderr').open('w') as error:
    subprocess.run(['/var/tmp/kprog-tmp/C/perf-build/perf', 'script', '-i', str(capture / 'host.data'),
                    '--guestkallsyms', str(capture / 'baseline.start.kallsyms'),
                    '-F', 'time,misc,ip,pid,tid,cpu,period', '--no-inline', '--hide-call-graph', '--ns'],
                   stdout=output, stderr=error, check=True)
samples = host.parse_samples((capture / 'samples.txt').read_text())
host_clock = json.loads((capture / 'host.start.clock.json').read_text())
# Exact routines from the retained same-image OTel PMU capture, with only each
# external call's rel32 displacement excluded. These are not source offsets.
reference = Path('/workspaces/kprog-raw/perf/20261116-otel-regression/pmu/profile')
ref_live = json.loads((reference / 'post_rejit.jit-lines.json').read_text())
ref_bytes = {p['id']: (reference / p['binary']).read_bytes() for p in ref_live['programs']}
templates = [
    ('map_array_dispatch', ref_bytes[48][7368:7435], range(58, 62)),
    ('helper_kernel_probe', ref_bytes[48][7435:7690], range(25, 29)),
    ('map_lpm_lookup', ref_bytes[48][7690:8020], range(321, 325)),
    ('helper_user_probe', ref_bytes[28][29583:29909], range(50, 54)),
    ('map_copied_hash', (raw / 'katran.copied-hash.bin').read_bytes(), range(2435, 2439))]
result = dict(scope=__doc__, case=case, run=str(run), status=app.get('status'), phases={})
for phase in ['baseline', 'post_rejit']:
    measured = app[phase]['bpf']
    live = json.loads((capture / (phase + '.jit-lines.json')).read_text())
    guest_clock = json.loads((capture / (phase + '.start.clock.json')).read_text())
    guest_end = json.loads((capture / (phase + '.end.clock.json')).read_text())
    intervals = windows.intervals(run / 'details/shim-logs' / (app_name + '.' + phase + '.log'))
    bounds = [host.host_window(dict(start_seconds=a, end_seconds=b), guest_clock, host_clock)
              for a, b in intervals]
    ranges, programs = [], {}
    for p in live['programs']:
        regions = []
        if phase == 'post_rejit':
            binary = (capture / p['binary']).read_bytes()
            for label, template, masked in templates:
                start = 0
                while (start := binary.find(template[:18], start)) >= 0:
                    candidate = binary[start:start + len(template)]
                    if len(candidate) == len(template) and all(
                            a == b for i, (a, b) in enumerate(zip(candidate, template)) if i not in masked):
                        regions.append(dict(kind=label, start=start, end=start + len(template)))
                    start += 1
        programs[p['id']] = dict(name=p['name'], bytes=p['jited_bytes'], regions=regions,
                                 cycles=Counter(), measured=measured.get(str(p['id'])))
        offset = 0
        for f in p['functions']:
            ranges.append((f['address'], f['address'] + f['length'], p['id'], offset))
            offset += f['length']
    ranges.sort()
    starts = [r[0] for r in ranges]
    addresses, names, _ = symbolize.load_kallsyms(capture / (phase + '.start.kallsyms'))
    roots, external = Counter(), Counter()
    for sample in samples:
        if not any(a <= sample['time_ns'] <= b for a, b in bounds):
            continue
        if 'G' not in sample['misc'] or 'g' in sample['misc']:
            continue
        ip, period = sample['ip'], sample['period']
        index = bisect.bisect_right(starts, ip) - 1
        if index >= 0 and ip < ranges[index][1]:
            first, _, ident, offset = ranges[index]
            p = programs[ident]
            label = 'remaining_program_text'
            for region in p['regions']:
                if region['start'] <= offset + ip - first < region['end']:
                    label = region['kind']
            p['cycles'][label] += period
        else:
            index = bisect.bisect_right(addresses, ip) - 1
            symbol = (names[index] if index >= 0 and ip >= 0xffff800000000000
                      and ip - addresses[index] <= (1 << 21) else '[unknown-guest-kernel]')
            roots[symbol] += period
            external[host.root_category(symbol)] += period
    calls = sum(p['run_cnt_delta'] for p in measured.values())
    ns = sum(p['run_time_ns_delta'] for p in measured.values())
    for p in programs.values():
        p['cycles'] = dict(p['cycles'])
        if p['measured'] and p['measured']['run_cnt_delta']:
            count = p['measured']['run_cnt_delta']
            p['counter_ns_per_call'] = p['measured']['run_time_ns_delta'] / count
            p['text_cycles_per_call'] = {label: value / count for label, value in p['cycles'].items()}
    result['phases'][phase] = dict(calls=calls, counter_ns_per_call=ns / calls,
        installed_bytes=sum(p['bytes_jited'] for p in measured.values()),
        clock_offset_drift_ns=host.clock_offset(guest_end) - host.clock_offset(guest_clock),
        external_root_cycles_per_app_call_without_caller_ownership={key: value / calls for key, value in external.items()},
        external_root_cycles=dict(roots.most_common()), programs=programs)
(capture / 'costs.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(case=case, run=str(run), status=result['status'], phases={
    name: {key: p[key] for key in ('calls', 'counter_ns_per_call', 'installed_bytes')}
    for name, p in result['phases'].items()}), indent=2))
