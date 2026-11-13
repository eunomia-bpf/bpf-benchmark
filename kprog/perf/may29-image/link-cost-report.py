#!/usr/bin/env python3
"""Join retained linker child clocks to shim loads in the same guest.

Only unique PID/interval matches are attributed. Missing or ambiguous matches
remain explicit. The residual includes wrapper startup and every other loader
operation; it does not identify a particular cost such as fork or cache lookup.
"""
import argparse
import collections
import json
from pathlib import Path
import re
import statistics


def distribution(values):
    return dict(count=len(values), total=sum(values), median=statistics.median(values) if values else None)


def union_seconds(intervals):
    total = 0
    end = None
    for first, last in sorted(intervals):
        total += max(0, last - (max(first, end) if end is not None else first))
        end = max(end, last) if end is not None else last
    return total / 1e9


def join(invocations, loads):
    rows = [dict(load=load, children=[]) for load in loads]
    unmatched = []
    for child in invocations:
        command = child['command']
        output = command[command.index('--output') + 1]
        parent = re.search(r'\.tmp\.(\d+)(?:\.|$)', output)
        possible = [index for index, row in enumerate(rows)
                    if parent and row['load']['pid'] == int(parent[1])
                    and row['load']['start_seconds'] <= child['start_monotonic_ns'] / 1e9
                    and row['load']['end_seconds'] >= child['end_monotonic_ns'] / 1e9]
        if len(possible) == 1:
            rows[possible[0]]['children'].append(child)
        else:
            unmatched.append(dict(child=child, candidate_load_indices=possible))
    for row in rows:
        intervals = [(child['start_monotonic_ns'], child['end_monotonic_ns']) for child in row['children']]
        row['child_wall_union_seconds'] = union_seconds(intervals)
        row['outside_recorded_children_seconds'] = row['load']['elapsed_seconds'] - row['child_wall_union_seconds']
    return dict(loads=rows, unmatched_children=unmatched)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('profile', type=Path)
    parser.add_argument('loads', type=Path, help='load-timeline.py JSON, from the same guest')
    args = parser.parse_args()
    invocations = [json.loads(path.read_text()) for path in sorted(args.profile.glob('invocation-*.json'))]
    timelines = json.loads(args.loads.read_text())
    loads = [load for timeline in timelines for load in timeline['completed'] if load['native']]
    result = join(invocations, loads)
    modes = collections.defaultdict(list)
    for invocation in invocations:
        command = invocation['command']
        modes[command[command.index('--mode') + 1]].append(invocation)
    result['modes'] = {mode: dict(wall_seconds=distribution([c['elapsed_seconds'] for c in calls]),
                                  user_seconds=distribution([c['child_usage']['user_seconds'] for c in calls]),
                                  system_seconds=distribution([c['child_usage']['system_seconds'] for c in calls]),
                                  return_codes=dict(collections.Counter(c['returncode'] for c in calls)))
                       for mode, calls in modes.items()}
    result['native_load_seconds'] = distribution([load['elapsed_seconds'] for load in loads])
    result['outside_recorded_children_seconds'] = distribution([row['outside_recorded_children_seconds'] for row in result['loads']])
    result['limits'] = ['Residual includes wrapper startup, spawning and all other loader work; no individual cost is isolated.',
                        'Summed per-load durations may overlap across threads; they are not guest elapsed time.',
                        'Child timing records require the same guest monotonic clock as the shim timeline.']
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
