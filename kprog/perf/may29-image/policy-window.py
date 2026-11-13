#!/usr/bin/env python3
"""Retain policy-counter endpoints wholly inside each recorded measurement.

Absent protobuf counters stay absent. Negative differences stay visible; neither
condition filters a run or supplies a workload validity decision.
"""
import argparse
from collections import Counter
import json
from pathlib import Path


def windows(report):
    result = []
    for interval in report['measurement_intervals']:
        observations = [s for s in report['snapshots']
                        if s.get('pid') == interval['pid'] and s.get('policy_query_rc') == 0
                        and dict(phase=interval['phase'], relation='inside')
                        in (s.get('policy_query_measurement_matches') or [])]
        observations.sort(key=lambda s: s['policy_query_clock']['start']['monotonic_ns'])
        row = dict(interval=interval, observations=len(observations),
                   policy_states=dict(Counter(p.get('state', 'unspecified')
                                             for s in observations for p in s['policies'])))
        if observations:
            first, last = observations[0], observations[-1]
            row['endpoints'] = [dict(snapshot=s['snapshot'], clock=s['policy_query_clock'])
                                for s in (first, last)]
            endpoints = [{p['name']: p for p in s['policies']} for s in (first, last)]
            row['policies'] = []
            for name in sorted(endpoints[0].keys() | endpoints[1].keys()):
                policy = dict(name=name, endpoints=[e.get(name) for e in endpoints])
                if all(name in e for e in endpoints):
                    counters = [e[name].get('stats', {}).get('action_counters', {}) for e in endpoints]
                    policy['action_counter_deltas'] = {
                        key: (int(counters[1][key]) - int(counters[0][key])
                              if all(key in c for c in counters) else None)
                        for key in sorted(counters[0].keys() | counters[1].keys())}
                row['policies'].append(policy)
        result.append(row)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('report', type=Path)
    args = parser.parse_args()
    print(json.dumps(dict(source=str(args.report), windows=windows(json.loads(args.report.read_text()))), indent=2))


if __name__ == '__main__':
    main()
