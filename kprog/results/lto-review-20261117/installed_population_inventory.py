#!/usr/bin/env python3
"""Audit existing size summaries without changing benchmark or result files."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
runs = [
    ('otelcol-ebpf-profiler__profiling', '035907_339709'),
    ('bcc__set', '041017_749964'),
    ('cilium__agent', '042102_276469'),
    ('tetragon__observer', '043157_792401'),
    ('tracee__monitor', '044227_741393'),
]
prefix = re.compile(r'^\[([^]]+) pid=(\d+) tid=(\d+)\] (.*)$')
info = re.compile(
    r'native-loader jit-info (original|native) fd=(\d+) id=(\d+) '
    r'type=(\d+) name=(\S*) tag=\S+ jited_len=(\d+)')
apps = []
for app, suffix in runs:
    run = repo / ('corpus/results/x86_kvm_corpus_20261117_' + suffix)
    log = run / 'details/shim-logs' / (app + '.post_rejit.log')
    raw = json.loads((run / 'details/apps' / (app + '.json')).read_text())
    pending = {}
    pairs = []
    old = {'original': {}, 'native': {}}
    for lineno, line in enumerate(log.read_text().splitlines(), 1):
        if not (match := prefix.match(line)):
            continue
        _, pid, tid, message = match.groups()
        thread = (pid, tid)
        if match := info.match(message):
            kind, fd, prog_id, kind_id, name, size = match.groups()
            row = dict(line=lineno, fd=int(fd), id=int(prog_id),
                       type=int(kind_id), name=name, bytes_jited=int(size))
            pending.setdefault(thread, {})[kind] = row
            old[kind][name] = int(size)
        if message.startswith('native-loader replaced prog='):
            pair = pending.pop(thread)
            pairs.append(dict(pid=int(pid), tid=int(tid), replacement_line=lineno,
                              original=pair['original'], native=pair['native']))
    # IDs identify programs within one boot. Do not pair names across starts.
    by_native_id = {pair['native']['id']: pair for pair in pairs}
    snapshot = list(raw['post_rejit']['bpf'].values())
    matched = [by_native_id[row['id']] for row in snapshot if row['id'] in by_native_id]
    other = [row for row in snapshot if row['id'] not in by_native_id]
    common = old['original'].keys() & old['native'].keys()
    load_original = {pair['original']['id']: pair['original']['bytes_jited'] for pair in pairs}
    load_native = {pair['native']['id']: pair['native']['bytes_jited'] for pair in pairs}
    snapshots = []
    for phase in ('baseline', 'post_rejit'):
        records = list(raw[phase]['bpf'].values())
        counts = Counter((row['type'], row['name']) for row in records)
        snapshots.append(dict(phase=phase, records=len(records),
                              sum_bytes_jited=sum(row['bytes_jited'] for row in records),
                              unique_type_name_pairs=len(counts),
                              duplicate_type_names=[dict(type=kind, name=name, records=n)
                                                    for (kind, name), n in counts.items() if n > 1]))
    apps.append(dict(
        app=app, run=str(run.relative_to(repo)), log=str(log.relative_to(repo)),
        legacy_last_by_name=dict(programs=len(common),
                                 original_bytes=sum(old['original'][name] for name in common),
                                 native_bytes=sum(old['native'][name] for name in common)),
        successful_replacement_events=len(pairs),
        cumulative_unique_original_ids=len(load_original),
        cumulative_unique_native_ids=len(load_native),
        cumulative_original_bytes=sum(load_original.values()),
        cumulative_native_bytes=sum(load_native.values()),
        measurement_snapshots=snapshots,
        native_snapshot_matched_to_loads=dict(
            programs=len(matched),
            companion_original_bytes=sum(pair['original']['bytes_jited'] for pair in matched),
            native_load_bytes=sum(pair['native']['bytes_jited'] for pair in matched)),
        native_snapshot_without_replacement_pair=other,
        replacement_pairs=pairs))
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Five completed O3 stats-on runs. Legacy last-name summaries, cumulative unique load IDs, measurement-window inventories and live-native matched companions are separate populations. No framework/raw result modified; no run rejected; per-call/throughput calculations unchanged. Kernel IDs are only correlated within their own run/boot.',
    apps=apps)
(here / 'installed-populations.json').write_text(json.dumps(result, indent=2) + '\n')
for app in apps:
    matched=app['native_snapshot_matched_to_loads']
    print(app['app'], 'name-last', app['legacy_last_by_name'],
          'load IDs/bytes', app['cumulative_unique_native_ids'], app['cumulative_native_bytes'],
          'snapshot matched', matched,
          'snapshot unpaired', len(app['native_snapshot_without_replacement_pair']))
