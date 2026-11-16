"""Guest-only PMU roots in actual shim windows; periods are cycles, not ns.

No callchains were recorded. External helper/map roots include other guest
activity and cannot be assigned to an OTel caller. Program text includes inline
helpers. Captured JIT ranges take precedence over nearest kallsyms symbols.
"""
import bisect
from collections import Counter
import importlib.util
import json
from pathlib import Path
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
raw = Path(sys.argv[1])
capture = raw / 'pmu/profile'
run = ROOT / 'corpus/results/x86_kvm_corpus_20261116_190848_302838'
app_name = 'otelcol-ebpf-profiler__profiling'
app = json.loads((run / 'details/apps' / (app_name + '.json')).read_text())
samples = host.parse_samples((raw / 'pmu/samples.txt').read_text())
host_clock = json.loads((capture / 'host.start.clock.json').read_text())
result = dict(scope=__doc__, run=str(run), samples=len(samples), phases={})
native_live = json.loads((capture / 'post_rejit.jit-lines.json').read_text())
native_bytes = {p['id']: (capture / p['binary']).read_bytes() for p in native_live['programs']}
# Boundaries come from decoding the captured instructions, not P offsets.
# Mask only the rel32 displacement of each appended routine's external call.
templates = [
    ('array_dispatch', native_bytes[48][7368:7435], range(58, 62)),
    ('kernel_probe', native_bytes[48][7435:7690], range(25, 29)),
    ('lpm_lookup', native_bytes[48][7690:8020], range(321, 325)),
    ('user_probe', native_bytes[28][29583:29909], range(50, 54)),
]
for phase in ['baseline', 'post_rejit']:
    measured = app[phase]['bpf']
    live = json.loads((capture / (phase + '.jit-lines.json')).read_text())
    guest_clock = json.loads((capture / (phase + '.start.clock.json')).read_text())
    guest_end = json.loads((capture / (phase + '.end.clock.json')).read_text())
    ranges, programs = [], {}
    for p in live['programs']:
        programs[p['id']] = dict(id=p['id'], name=p['name'], bytes=p['jited_bytes'],
                                 samples=0, cycles=0, offsets=Counter())
        offset = 0
        for f in p['functions']:
            ranges.append((f['address'], f['address'] + f['length'], p['id'], offset))
            offset += f['length']
    ranges.sort()
    starts = [r[0] for r in ranges]
    addresses, names, _ = symbolize.load_kallsyms(capture / (phase + '.start.kallsyms'))
    intervals = windows.intervals(run / 'details/shim-logs' / (app_name + '.' + phase + '.log'))
    host_intervals = [host.host_window(dict(start_seconds=a, end_seconds=b),
                                       guest_clock, host_clock) for a, b in intervals]
    symbols, periods, modes = Counter(), Counter(), Counter()
    for sample in samples:
        if not any(a <= sample['time_ns'] <= b for a, b in host_intervals):
            continue
        modes[sample['misc']] += 1
        if 'G' not in sample['misc'] or 'g' in sample['misc']:
            continue
        ip, period = sample['ip'], sample['period']
        i = bisect.bisect_right(starts, ip) - 1
        if i >= 0 and ip < ranges[i][1]:
            first, _, ident, offset = ranges[i]
            p = programs[ident]
            p['samples'] += 1
            p['cycles'] += period
            p['offsets'][offset + ip - first] += period
            symbol = 'jit:' + str(ident) + ':' + p['name']
        else:
            i = bisect.bisect_right(addresses, ip) - 1
            symbol = (names[i] if i >= 0 and ip >= 0xffff800000000000
                      and ip - addresses[i] <= (1 << 21) else '[unknown-guest-kernel]')
        symbols[symbol] += 1
        periods[symbol] += period
    for p in programs.values():
        p['offset_cycles'] = sorted(p.pop('offsets').items())
        if phase == 'post_rejit':
            binary = native_bytes[p['id']]
            regions = []
            for label, template, masked in templates:
                start = 0
                while (start := binary.find(template[:18], start)) >= 0:
                    candidate = binary[start:start + len(template)]
                    if len(candidate) == len(template) and all(
                            a == b for i, (a, b) in enumerate(zip(candidate, template)) if i not in masked):
                        regions.append(dict(kind=label, start=start, end=start + len(template)))
                    start += 1
            classes = Counter()
            for offset, cycles in p['offset_cycles']:
                label = 'remaining_program_text'
                for region in regions:
                    if region['start'] <= offset < region['end']:
                        label = region['kind']
                classes[label] += cycles
            p['inline_regions'] = regions
            p['text_class_cycles'] = dict(classes)
        p['measured_counters'] = measured.get(str(p['id']))
        if p['measured_counters'] and p['measured_counters']['run_cnt_delta']:
            p['sampled_text_cycles_per_call'] = p['cycles'] / p['measured_counters']['run_cnt_delta']
    calls = sum(p['run_cnt_delta'] for p in measured.values())
    ns = sum(p['run_time_ns_delta'] for p in measured.values())
    result['phases'][phase] = dict(windows=intervals, host_windows_ns=host_intervals,
        guest_clock_offset_drift_ns=host.clock_offset(guest_end) - host.clock_offset(guest_clock),
        calls=calls, counter_ns_per_call=ns / calls,
        installed_bytes=sum(p['bytes_jited'] for p in measured.values()), modes=dict(modes),
        root_samples=dict(symbols.most_common()), root_cycles=dict(periods.most_common()),
        programs=[p for p in programs.values() if p['samples'] or p['measured_counters']])
    print(phase, 'counter ns/call', ns / calls, 'modes', dict(modes))
    print('top root cycles', periods.most_common(15))
(raw / 'pmu/costs.json').write_text(json.dumps(result, indent=2) + '\n')
