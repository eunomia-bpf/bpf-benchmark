"""CPU-clock periods in shim counter windows; inline text is kept separate."""
import bisect
from collections import Counter
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path('/workspaces/repository')
HERE = ROOT / 'kprog/perf/profile'
sys.path.insert(0, str(HERE))
import symbolize

spec = importlib.util.spec_from_file_location('jit_windows', HERE / 'jit-window-costs.py')
windows = importlib.util.module_from_spec(spec)
spec.loader.exec_module(windows)
raw = Path(sys.argv[1])
capture = raw / 'profile'
run = ROOT / 'corpus/results/x86_kvm_corpus_20261116_184518_934200'
app_name = 'otelcol-ebpf-profiler__profiling'
app = json.loads((run / 'details/apps' / (app_name + '.json')).read_text())
perf = '/var/tmp/kprog-tmp/C/perf-build/perf'

def category(symbol):
    if symbol.startswith(('__htab_', 'htab_', 'lookup_nulls_', 'trie_lookup_',
                          'array_map_lookup_', 'percpu_array_', 'bpf_map_')):
        return 'maps'
    if symbol.startswith(('bpf_', 'copy_from_', '_copy_from_', 'strncpy_from_',
                          'copy_user_', 'perf_event_', 'perf_output_')):
        return 'helpers'
    return 'other_kernel_or_user'

result = {'scope': __doc__, 'run': str(run), 'phases': {}}
for phase in ['baseline', 'post_rejit']:
    measured = app[phase]['bpf']
    live = json.loads((capture / (phase + '.jit-lines.json')).read_text())
    ranges = []
    for p in live['programs']:
        for f in p['functions']:
            ranges.append((f['address'], f['address'] + f['length'], p['id'], p['name']))
    ranges.sort()
    starts = [r[0] for r in ranges]
    addresses, names, _ = symbolize.load_kallsyms(capture / (phase + '.kallsyms'))

    def resolve(ip):
        index = bisect.bisect_right(starts, ip) - 1
        if index >= 0 and ip < ranges[index][1]:
            r = ranges[index]
            return 'jit:' + str(r[2]) + ':' + r[3], r[2], ip - r[0]
        if ip < 0xffff800000000000:
            return '[user]', None, None
        index = bisect.bisect_right(addresses, ip) - 1
        return (names[index] if index >= 0 else '[unknown]'), None, None

    clocks = windows.intervals(run / 'details/shim-logs' / (app_name + '.' + phase + '.log'))
    roots, owned, classes, unresolved_classes, text_offsets = [Counter() for _ in range(5)]
    samples = 0
    for first, last in clocks:
        command = [perf, 'script', '-i', str(capture / (phase + '.data')),
                   '-F', 'time,period,ip', '--no-inline', '--time', f'{first},{last}']
        with (raw / (phase + '.decode.stderr')).open('w') as error:
            child = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=error, text=True)
            for stamp, period, chain in windows.records(child.stdout):
                resolved = [resolve(ip) for ip in chain]
                symbol, ident, offset = resolved[0]
                roots[symbol] += period
                samples += 1
                parent = any(str(r[1]) in measured for r in resolved if r[1] is not None)
                if str(ident) in measured:
                    classes['program_text_including_inline_helpers'] += period
                    if measured[str(ident)]['name'] == 'native_tracer_e':
                        text_offsets[offset] += period
                elif parent:
                    owned[symbol] += period
                    classes[category(symbol)] += period
                else:
                    unresolved_classes[category(symbol)] += period
            child.stdout.close()
            code = child.wait()
            if code:
                raise subprocess.CalledProcessError(code, command)
    calls = sum(p['run_cnt_delta'] for p in measured.values())
    ns = sum(p['run_time_ns_delta'] for p in measured.values())
    result['phases'][phase] = {
        'windows': clocks, 'samples': samples, 'calls': calls,
        'counter_ns_per_call': ns / calls,
        'attributed_sampled_ns_per_call': {k: v / calls for k, v in classes.items()},
        'attributed_period_ns': dict(classes), 'external_roots_on_app_chain': dict(owned.most_common()),
        'unattributed_period_ns': dict(unresolved_classes),
        'all_root_period_ns': dict(roots.most_common()),
        'sampling_entry_offset_period_ns': sorted(text_offsets.items()),
        'installed_bytes': sum(p['bytes_jited'] for p in measured.values()),
    }
(raw / 'costs.json').write_text(json.dumps(result, indent=2) + '\n')
for phase, row in result['phases'].items():
    print(phase, row['counter_ns_per_call'], row['attributed_sampled_ns_per_call'])
