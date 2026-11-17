#!/usr/bin/env python3
"""Read the corrected O3 check logs; count load events, not unique programs."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
runs = [
    ('otelcol-ebpf-profiler__profiling', '033743_984421'),
    ('bcc__set', '034122_540932'),
    ('cilium__agent', '034447_636111'),
    ('tetragon__observer', '034829_591728'),
    ('tracee__monitor', '035153_064790'),
    ('katran', '035600_460257'),
]
prefix = re.compile(r'^\[([^]]+) pid=(\d+) tid=(\d+)\] (.*)$')
load = re.compile(r'BPF_PROG_LOAD type=(\d+) \(([^)]+)\) name=(.*?) insn_cnt=(\d+) ')
returned = re.compile(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)')
publication = re.compile(
    r'BPF_MAP_UPDATE_ELEM prog_array name=(.*?) map_fd=(\d+) key=(\d+) '
    r'prog_fd=(\d+) prog_id=(\d+) flags=(\d+) ret=(-?\d+) errno=(\d+)')
apps = []
for app, suffix in runs:
    run = repo / ('corpus/results/x86_kvm_corpus_20261117_' + suffix)
    log = run / 'details/shim-logs' / (app + '.post_rejit.log')
    result = json.loads((run / 'details/apps' / (app + '.json')).read_text())
    pending = {}
    unmatched = []
    publications = []
    counters = Counter()
    for lineno, line in enumerate(log.read_text().splitlines(), 1):
        match = prefix.match(line)
        if not match:
            continue
        _, pid, tid, message = match.groups()
        thread = (pid, tid)
        if match := load.match(message):
            kind, kind_name, name, count = match.groups()
            pending[thread] = dict(load_line=lineno, pid=int(pid), tid=int(tid),
                                   program=name, type=int(kind), type_name=kind_name,
                                   insn_count=int(count))
        if 'native-loader replaced prog=' in message:
            counters['native_replacement_events'] += 1
        if 'native-loader failed' in message:
            counters['native_loader_failed_events'] += 1
        if 'native-loader skipped feature probe' in message:
            counters['explicit_feature_probe_skip_events'] += 1
        if 'native-loader no manifest match for prog=' in message:
            event = dict(pending[thread], no_match_line=lineno)
            unmatched.append(event)
            pending[thread]['unmatched_index'] = len(unmatched) - 1
        if match := returned.match(message):
            event = pending.pop(thread, None)
            if event is not None and 'unmatched_index' in event:
                fd, errno, prog_id = map(int, match.groups())
                unmatched[event['unmatched_index']].update(
                    return_line=lineno, fd=fd, errno=errno, kernel_prog_id=prog_id)
        if match := publication.match(message):
            name, map_fd, key, fd, prog_id, flags, ret, errno = match.groups()
            publications.append(dict(line=lineno, pid=int(pid), map_name=name,
                                     map_fd=int(map_fd), key=int(key), prog_fd=int(fd),
                                     kernel_prog_id=int(prog_id), flags=int(flags),
                                     ret=int(ret), errno=int(errno)))
    for event in unmatched:
        event['program_array_publications'] = [
            p for p in publications
            if p['kernel_prog_id'] == event['kernel_prog_id'] and
            p['pid'] == event['pid'] and p['line'] > event['return_line']]
    apps.append(dict(app=app, run=str(run.relative_to(repo)),
                     log=str(log.relative_to(repo)), status=result['status'],
                     error=result['error'],
                     native_replacement_events=counters['native_replacement_events'],
                     native_loader_failed_events=counters['native_loader_failed_events'],
                     explicit_feature_probe_skip_events=counters['explicit_feature_probe_skip_events'],
                     no_match_events=len(unmatched),
                     no_match_by_name=dict(Counter(e['program'] for e in unmatched)),
                     unmatched_loads=unmatched))

stage = repo / 'vendor/build/native-bpf/x86/stage/cilium'
manifest = stage / 'manifest.json'
names = {'tail_drop_notif', 'cil_host_policy', 'cil_lxc_policy_'}
keys = ('program', 'native_object', 'symbol', 'prog_type', 'source_map_prefix')
candidates = [{k: e[k] for k in keys if k in e}
              for e in json.loads(manifest.read_text())['objects']
              if e['program'] in names]
symbols = []
for obj, wanted in [('bpf_host.native.o', {'tail_drop_notify', 'cil_host_policy'}),
                    ('bpf_lxc.native.o', {'tail_drop_notify', 'cil_lxc_policy_egress'})]:
    output = subprocess.check_output(['readelf', '-sW', str(stage / obj)], text=True)
    for line in output.splitlines():
        fields = line.split()
        if len(fields) == 8 and fields[3] == 'FUNC' and fields[7] in wanted:
            symbols.append(dict(object=obj, symbol=fields[7], bytes=int(fields[2])))
receipt = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    reviewed_tree=subprocess.check_output(['git', '-C', str(repo), 'rev-parse', '--short', 'HEAD'], text=True).strip(),
    scope='Corrected O3 check load events, including no-match retention. Counts are not unique programs, execution frequencies, timings, or B verification results. Current stage manifest and symbols are inspected separately; no image-byte identity is asserted.',
    apps=apps, current_cilium_manifest=str(manifest.relative_to(repo)),
    cilium_manifest_candidates=candidates, current_cilium_function_sizes=symbols)
(here / 'native-coverage.json').write_text(json.dumps(receipt, indent=2) + '\n')
for app in apps:
    print(app['app'], app['status'], app['native_replacement_events'],
          app['native_loader_failed_events'], app['no_match_by_name'])
