#!/usr/bin/env python3
"""Inventory retained Tetragon policy/action/event observations, offline.

Snapshot labels can span a restart: PID, address, map IDs and timestamps are
retained so consumers can separate generations. Short event subscriptions
sample delivery only; empty output does not count all kernel emissions.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import re


def read_json(path):
    return json.JSONDecoder().raw_decode(path.read_text())[0]


def measurement_intervals(run, app='tetragon__observer'):
    intervals = []
    pattern = re.compile(r'^\[([0-9.]+) pid=(\d+) tid=\d+\] socket: cmd=(measure_start|measure_finish) ')
    for phase in ('baseline', 'post_rejit'):
        pending = {}
        path = run / f'details/shim-logs/{app}.{phase}.log'
        for line in path.read_text().splitlines():
            match = pattern.match(line)
            if not match:
                continue
            timestamp, pid, event = match.groups()
            if event == 'measure_start':
                if pid in pending:
                    intervals.append(pending.pop(pid))
                pending[pid] = dict(phase=phase, pid=pid, start_seconds=float(timestamp))
            else:
                record = pending.pop(pid, dict(phase=phase, pid=pid))
                record['end_seconds'] = float(timestamp)
                intervals.append(record)
        intervals.extend(pending.values())
    return intervals


def clock_matches(intervals, pid, timing):
    first = timing['start']['monotonic_ns'] / 1e9
    last = timing['end']['monotonic_ns'] / 1e9
    return [dict(phase=item['phase'], relation=(
                 'inside' if first >= item['start_seconds'] and last <= item['end_seconds'] else 'overlap'))
            for item in intervals if item['pid'] == pid and 'start_seconds' in item and 'end_seconds' in item
            and last >= item['start_seconds'] and first <= item['end_seconds']]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capture', type=Path)
    parser.add_argument('run', type=Path)
    parser.add_argument('--measurement-clock', action='store_true',
                        help='retain query clocks and match PID/time to actual shim measurement intervals')
    args = parser.parse_args()
    app = read_json(args.run / 'details/apps/tetragon__observer.json')
    result = dict(run=str(args.run), capture=str(args.capture), app_status=app['status'],
                  app_error=app['error'], phases={}, snapshots=[])
    if args.measurement_clock:
        result['measurement_intervals'] = measurement_intervals(args.run)
    for phase in ('baseline', 'post_rejit'):
        programs = app[phase]['bpf']
        result['phases'][phase] = dict(programs=len(programs),
            name_type_counts=dict(Counter(f'{p["type"]}:{p["name"]}' for p in programs.values())))
    for snapshot in sorted(args.capture.iterdir()):
        if not snapshot.is_dir() or not (snapshot / 'programs.json').exists():
            continue
        programs = read_json(snapshot / 'programs.json')
        maps = read_json(snapshot / 'maps.json')
        record = dict(snapshot=snapshot.name, time=(snapshot / 'time.txt').read_text().strip(),
                      programs=len(programs), tiny_xlated_programs=sum(p['bytes_xlated'] <= 32 for p in programs),
                      send_failures_map_ids=[m['id'] for m in maps if m.get('name') == 'tg_stats_map'])
        command = snapshot / 'tetragon-command.bin'
        if command.exists() and command.stat().st_size:
            argv = command.read_bytes().decode().split('\0')
            record['server_address'] = argv[argv.index('--server-address') + 1]
            record['pid'] = (snapshot / 'tetragon-pid.txt').read_text().strip()
        policy = snapshot / 'tracingpolicies.json'
        if policy.exists():
            record['policy_query_rc'] = int(policy.with_suffix('.json.rc').read_text())
            record['policy_query_stderr'] = policy.with_suffix('.json.stderr').read_text()
            if args.measurement_clock:
                timing = policy.with_suffix('.json.timing.json')
                record['policy_query_clock'] = read_json(timing) if timing.exists() else None
                record['policy_query_measurement_matches'] = (
                    clock_matches(result['measurement_intervals'], record['pid'], record['policy_query_clock'])
                    if record['policy_query_clock'] is not None else None)
            if record['policy_query_rc'] == 0:
                record['policies'] = read_json(policy).get('policies', [])
        events = snapshot / 'events.jsonl'
        if events.exists():
            record['events_query_rc'] = int(events.with_suffix('.jsonl.rc').read_text())
            record['events_query_stderr'] = events.with_suffix('.jsonl.stderr').read_text()
            record['sampled_events'] = [json.loads(line) for line in events.read_text().splitlines() if line.strip()]
        result['snapshots'].append(record)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
