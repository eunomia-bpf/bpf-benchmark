"""Stream guest PMU samples into phase/function weights using captured kernel symbols."""
import bisect
import collections
import functools
import json
from pathlib import Path
import re
import subprocess
import sys

PERF = '/workspaces/.agent-state/kprog-ck/perf-tool/perf'
SAMPLE = re.compile(r'^\d+ (\d+) \S+ \[\S+\]: PERF_RECORD_SAMPLE\(IP, 0x([45])\): \S+ 0x([0-9a-f]+) ')
FRAME = re.compile(r'^\.\.\.\.\.\s+\d+: ([0-9a-f]+)')
PROGRAM = re.compile(r'^bpf_prog_[0-9a-f]{16}_')
MEASURE = re.compile(r'^\[(\d+\.\d+) .*socket: cmd=measure_(start|finish) ')
LOOKUPS = {'__htab_map_lookup_elem', 'htab_map_hash', 'lookup_nulls_elem_raw', 'jhash',
           'htab_map_lookup_elem', 'htab_lru_map_lookup_elem', 'htab_percpu_map_lookup_elem',
           'htab_lru_percpu_map_lookup_elem', 'htab_of_map_lookup_elem'}

def symbols(paths):
    table = {}
    for path in paths:
        for line in path.read_text().splitlines():
            fields = line.split()
            if len(fields) >= 3 and fields[1] in 'tTwW':
                table[int(fields[0], 16)] = fields[2]
    return table, sorted(table)

def summarize(out):
    run = Path((out / 'run_dir').read_text().strip())
    guest_rt, guest_up = map(float, (out / 'clock.txt').read_text().split())
    host_offset = float((out / 'host-rt-minus-uptime.txt').read_text())
    windows, tables = {}, {}
    snapshots = sorted(out.glob('kallsyms-bpf-*.txt'), key=lambda p: float(p.stem.rsplit('-', 1)[1]))
    for phase in ('baseline', 'post_rejit'):
        log = next((run / 'details/shim-logs').glob('*.' + phase + '.log'))
        text = log.read_text().splitlines()
        events = [(float(m[1]), m[2]) for line in text if (m := MEASURE.match(line))]
        end = max(t for t, event in events if event == 'finish')
        begin = max(t for t, event in events if event == 'start' and t < end)
        # As in profile-20261123/phases.py: the final 54 s before measure_finish.
        # Native measure_start can precede delayed native loading, unlike the 60 s workload.
        windows[phase] = [max(begin, end - 55), end - 1]
        first = float(re.match(r'^\[(\d+\.\d+)', text[0])[1])
        selected = [p for p in snapshots if first <= float(p.stem.rsplit('-', 1)[1]) <= end]
        tables[phase] = symbols([out / 'kallsyms.txt', *selected])

    @functools.lru_cache(maxsize=500000)
    def resolve(phase, address):
        if address < 0xffff800000000000:
            return '[user]', 0
        names, starts = tables[phase]
        index = bisect.bisect_right(starts, address) - 1
        return (names[starts[index]], address - starts[index]) if index >= 0 else ('[unmapped]', 0)

    def group(name):
        canonical = name.removeprefix('__pi_')
        if name.startswith('kprog_htab_elem_k'): return 'p3_hash'
        if name.partition('.')[0] in LOOKUPS: return 'kernel_hash_lookup'
        if canonical.startswith(('memset', '__memset')): return 'memset'
        if canonical.startswith(('memcmp', '__memcmp')): return 'memcmp'
        if PROGRAM.match(name): return 'program_body'
        if name == '[user]': return 'guest_user'
        return 'other_kernel'

    counts = {p: collections.Counter() for p in windows}
    functions = {p: collections.Counter() for p in windows}
    chains = {p: collections.Counter() for p in windows}
    current = None
    def finish():
        if current is None: return
        phase, name, category, frame_seen, bpf = current
        counts[phase][category] += 1
        functions[phase][name] += 1
        chains[phase]['samples_with_noncontext_chain_frame'] += int(frame_seen)
        chains[phase]['samples_with_bpf_body_or_chain'] += int(bpf)
        chains[phase]['memset_samples_with_bpf_caller'] += int(category == 'memset' and bpf)

    with (out / 'summary-perf.log').open('w') as errors:
        process = subprocess.Popen([PERF, 'report', '-D', '-i', str(out / 'host-perf.data')],
                                   stdout=subprocess.PIPE, stderr=errors, text=True)
        for line in process.stdout:
            if 'PERF_RECORD_' in line:
                finish(); current = None
                if not (match := SAMPLE.match(line)): continue
                uptime = int(match[1]) / 1e9 + host_offset - guest_rt + guest_up
                phase = next((p for p, (a, b) in windows.items() if a <= uptime < b), None)
                if phase is None: continue
                name, _ = resolve(phase, int(match[3], 16))
                current = [phase, name, group(name), False, bool(PROGRAM.match(name))]
            elif current is not None and (match := FRAME.match(line)):
                address = int(match[1], 16)
                if address >= 0xfffffffffffff001: continue  # PERF_CONTEXT_MAX (-4095).
                current[3] = True
                current[4] |= bool(PROGRAM.match(resolve(current[0], address)[0]))
        finish()
        if process.wait(): raise RuntimeError('perf dump failed; see summary-perf.log')
    result = dict(run=str(run), event='cpu_core/cycles/', period=1000000, windows=windows, phases={})
    for phase, counter in counts.items():
        total = counter.total()
        kernel = total - counter['guest_user']
        result['phases'][phase] = dict(total_samples=total, kernel_samples=kernel,
            groups=dict(counter), kernel_sample_shares={k: v / kernel for k, v in counter.items() if k != 'guest_user'},
            callchains=dict(chains[phase]), functions=dict(functions[phase].most_common()))
    (out / 'phase-summary.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: v for k, v in result.items() if k != 'phases'}, indent=2), flush=True)
    for phase, values in result['phases'].items():
        print(phase, values['groups'], values['callchains'], flush=True)

for target in sys.argv[1:]:
    summarize(Path(target))
