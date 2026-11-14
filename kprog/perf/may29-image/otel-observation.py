#!/usr/bin/env python3
"""Join retained OTel counter generations and query clocks to shim measurements."""
import argparse
import importlib.util
import json
from pathlib import Path
import re


def module(name, filename):
    spec = importlib.util.spec_from_file_location(name, Path(__file__).with_name(filename))
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


CLOCKS = module('measurement_clocks', 'tetragon-observation.py')
COUNTERS = module('phase_counters', 'phase-counters.py')


def map_generations(run):
    records = []
    for phase in ['baseline', 'post_rejit']:
        pending = {}
        path = run / ('details/shim-logs/otelcol-ebpf-profiler__profiling.' + phase + '.log')
        for line in path.read_text().splitlines():
            header = re.match(r'^\[([0-9.]+) pid=(\d+) tid=(\d+)\] (.*)', line)
            if not header:
                continue
            seconds, pid, tid, message = header.groups()
            if message.startswith('BPF_MAP_CREATE '):
                pending[pid, tid] = message
            elif message.startswith('  MAP_CREATE -> '):
                request = pending.pop((pid, tid), None)
                if request is not None and re.search(r'\bname=metrics(?:\s|$)', request):
                    response = re.search(r'fd=(-?\d+) errno=(\d+) kernel_map_id=(\d+)', message)
                    if response is None:
                        raise ValueError('metrics map response lacks the recorded kernel identity: ' + line)
                    fd, error, ident = map(int, response.groups())
                    records.append(dict(phase=phase, pid=pid, tid=tid, seconds=float(seconds),
                                        fd=fd, errno=error, map_id=ident))
    return records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capture', type=Path)
    parser.add_argument('run', type=Path)
    args = parser.parse_args()
    intervals = CLOCKS.measurement_intervals(args.run, 'otelcol-ebpf-profiler__profiling')
    generations = map_generations(args.run)
    types = Path(__file__).resolve().parents[3] / 'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/types.h'
    ids = COUNTERS.load_ids(types)
    result = dict(measurement_intervals=intervals, map_generations=generations,
                  counter_types_source=str(types), snapshots=[],
                  scope='Retained query clocks and current map identities only. Missing/overlapping reads remain recorded; no application equivalence gate or certification.')
    for snapshot in sorted(args.capture.iterdir()):
        if not snapshot.is_dir():
            continue
        for path in sorted(snapshot.glob('map-*-metrics.json')):
            ident = int(path.name.split('-')[1])
            timing = json.loads(path.with_suffix('.json.timing.json').read_text())
            owners = [row for row in generations if row['errno'] == 0 and row['map_id'] == ident]
            matches = [dict(owner=owner, measurement_matches=CLOCKS.clock_matches(intervals, owner['pid'], timing))
                       for owner in owners]
            result['snapshots'].append(dict(snapshot=snapshot.name, map_id=ident,
                                            clock=timing, owners=matches,
                                            metrics=COUNTERS.read_dump(path, ids)))
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
