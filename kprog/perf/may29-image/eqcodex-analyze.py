#!/usr/bin/env python3
"""Offline equal-work receipts from raw bpftool and collector snapshots.

All aggregates live here, outside the frozen framework and its result.json.
Snapshots retain their map generation and timestamps: a phase-label observed
during app restart does not make a new map an old-arm continuation.
"""
import argparse
import collections
import json
from pathlib import Path
import re


def integer(raw):
    return int.from_bytes(bytes(int(x, 16) for x in raw), 'little')


def decode(path):
    return json.JSONDecoder().raw_decode(path.read_text())[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capture', type=Path)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[3]
    names = re.findall(r'^\s*(metricID_\w+)\s*(?:=\s*\d+)?\s*,',
        (root / 'vendor/bpf/otel/support/ebpf/types.h').read_text(), re.M)
    result = []
    for snapshot in sorted(args.capture.iterdir()):
        if not snapshot.is_dir() or not (snapshot / 'programs.json').exists():
            continue
        programs = decode(snapshot / 'programs.json')
        maps = decode(snapshot / 'maps.json')
        record = dict(snapshot=str(snapshot), time=(snapshot / 'time.txt').read_text().strip(),
            programs=len(programs), inventory=dict(collections.Counter(
                (p.get('name', '<unnamed>') + (' [native stub]' if p['bytes_xlated'] <= 24 else ''))
                for p in programs)), metrics={}, send_failures={}, collector={})
        for mapinfo in maps:
            name = mapinfo.get('name', '')
            path = snapshot / f'map-{mapinfo["id"]}-{name}.json'
            if not path.exists() or not path.stat().st_size:
                continue
            if name == 'metrics':
                record['metrics_map_id'] = mapinfo['id']
                for entry in decode(path):
                    key = integer(entry['key'])
                    record['metrics'][names[key]] = sum(integer(cpu['value']) for cpu in entry['values'])
            if name == 'tg_stats_map':
                record['send_failures_map_id'] = mapinfo['id']
                counts = collections.Counter()
                for cpu in decode(path)[0]['values']:
                    raw = bytes(int(x, 16) for x in cpu['value'])
                    for i in range(len(raw) // 8):
                        value = int.from_bytes(raw[i*8:i*8+8], 'little')
                        if value:
                            counts[f'op={i//7},errno_slot={i%7}'] += value
                record['send_failures'] = dict(counts)
        for port in (8888, 2112):
            path = snapshot / f'collector-{port}.txt'
            if not path.exists():
                continue
            for line in path.read_text().splitlines():
                if line.startswith('#') or not line.strip():
                    continue
                key, value = line.rsplit(' ', 1)
                if key.startswith(('Trace', 'otelcol_exporter_queue_batch_send_size_sum', 'tetragon_events_total')):
                    record['collector'][key] = float(value)
        result.append(record)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
