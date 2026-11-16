"""Observe the retained November 14 LRU paths without inventing branch counts.

The reference replay matches the installed payload with relocation immediates
masked. Explicit ranges identify the three ARRAY expansions in that replay.
CPU-clock samples measure sampled activity, not execution or branch frequency.
"""
import argparse
from collections import Counter
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog/perf/profile'))
spec = importlib.util.spec_from_file_location('jit_windows', ROOT/'kprog/perf/profile/jit-window-costs.py')
windows = importlib.util.module_from_spec(spec)
spec.loader.exec_module(windows)

# Source offsets come from the retained proof. Output offsets come from its
# matched kernel replay: setup loads rsp+0x78, then the supposed LRU lookup
# expands to a 1024-entry per-CPU array operation, followed by test rax,rax.
SITES = [(5304, 0x18be, 0x18df), (5743, 0x1b04, 0x1b25),
         (5831, 0x1b7d, 0x1b9e)]


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    match = json.loads((a.match/'jit-source-map.json').read_text())
    capture = json.loads((a.capture/'post_rejit.jit-lines.json').read_text())
    program, = [p for p in capture['programs'] if p['id'] == match['program']]
    function, = program['functions']
    base = function['address'] + match['payload_start']
    binary = (a.capture/program['binary']).read_bytes()
    symbols = {int(fields[0], 16): fields[2]
               for line in (a.capture/'post_rejit.kallsyms').read_text().splitlines()
               if len(fields := line.split()) >= 3}
    replay = json.loads((a.match/'result.json').read_text())
    calls = []
    for row in replay['runtime']['relocations']:
        offset = match['payload_start']+row['offset']
        target = function['address']+offset+5+struct.unpack_from('<i', binary, offset+1)[0]
        calls.append(dict(payload_offset=row['offset'], actual_target=target,
                          actual_symbol=symbols.get(target),
                          replay_helper_names=row['helper_names']))
    commands = []

    def run(arguments, filename):
        command = [str(a.perf), *map(str, arguments)]
        commands.append(command)
        result = subprocess.run(command, text=True, capture_output=True, check=True)
        (a.output/(filename+'.stderr')).write_text(result.stderr)
        return result.stdout

    data = a.capture/'post_rejit.data'
    events = run(['evlist', '-v', '-i', data], 'events')
    (a.output/'events.txt').write_text(events)
    text = run(['script', '-i', data, '-F', 'time,period,ip', '--no-inline'], 'samples')
    (a.output/'samples.txt').write_text(text)
    counts, periods = Counter(), Counter()
    total, on_program = 0, 0
    for stamp, period, chain in windows.records(text.splitlines()):
        total += 1
        offset = chain[0]-base
        if -match['payload_start'] <= offset < program['jited_bytes']-match['payload_start']:
            on_program += 1
        for source, first, last in SITES:
            if first <= offset < last:
                counts[source] += 1
                periods[source] += period
    result = dict(scope=__doc__, capture=str(a.capture), payload_match=match,
        event='cpu-clock', branch_stack_recorded='BRANCH_STACK' in events,
        total_root_samples=total, native_program_root_samples=on_program,
        sites=[dict(source_offset=s, payload_start=f, payload_end=l,
                    installed_start=f+match['payload_start'],
                    root_samples=counts[s], sampled_period_ns=periods[s])
               for s, f, l in SITES],
        exact_branch_counts=None,
        actual_external_calls=calls,
        interpretation='The capture has no branch-stack or instruction trace. '
            'Sample counts cannot recover execution counts, taken fractions, '
            'or a zero-frequency claim for a path with no samples. '
            'Full capture includes warmup; measured-only BPF counters are a different window.',
        commands=commands)
    (a.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k in
                     ('total_root_samples','native_program_root_samples','branch_stack_recorded','sites')}))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('capture', 'match', 'perf', 'output'):
        p.add_argument('--'+name, type=Path, required=True)
    main(p.parse_args())
