#!/usr/bin/env python3
"""Current-manifest selection for the Tetragon programs of the paired image.

The census keeps 152 Tetragon rows on the previous census object+symbol because
their resident bytecode lengths (2026-11-08 run, tetragon-stack-values) differ
from the manifest's source_bytecode_len, which the paired source build carries.
This check applies the census selector (corpus_resident_census.collect: program
name, source_bytecode_len against insn_cnt * 8, prog_type) to every Tetragon
BPF_PROG_LOAD record in the JIT-arm (baseline) shim logs of C's whole-application
runs on the paired image, and compares each selection with the census's
carried-forward identity for the same program role. Helper and map-prefix
selectors need xlated dumps and map ids, which these runs leave out, so they
stay unapplied here and every candidate they would separate is listed.

  tetragon-current-selection.py <manifest.json> <output.json> <run-dir>...
"""
from pathlib import Path
import collections
import importlib.util
import json
import sys

ROOT = Path('/workspaces/repository')
CENSUS = ROOT / 'corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped'


def main():
    manifest_path, output, runs = Path(sys.argv[1]), Path(sys.argv[2]), sys.argv[3:]
    spec = importlib.util.spec_from_file_location('census_collect', ROOT / 'kprog/corpus_resident_census.py')
    census = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(census)
    manifest = json.loads(manifest_path.read_text())['objects']
    result = json.loads((CENSUS / 'result.json').read_text())
    rows = {r['source_prog_id']: r for r in json.loads((CENSUS / 'instances.json').read_text())['programs']
            if r['application'] == 'tetragon/observer'}
    carried = collections.defaultdict(lambda: dict(rows=0, stages=collections.Counter()))
    for body in result['bodies']:
        if body['application'] != 'tetragon/observer':
            continue
        for member in body['member_ids']:
            if rows[member]['selection_kind'] != 'previous census identity on current payload':
                continue
            entry = carried[(body['native_object'], body['symbol'])]
            entry['rows'] += 1
            entry['stages'][body['failure_class']] += 1
            entry['name'] = rows[member]['name'][:15]
    loads = collections.Counter()
    for run in runs:
        log = Path(run) / 'details/shim-logs/tetragon__observer.baseline.log'
        for record in census.load_contexts(log.read_text()).values():
            loads[(Path(run).name, record['name'], int(record['type']), int(record['insn_cnt']) * 8)] += 1
    selections = []
    for (run, name, kind, length), count in sorted(loads.items()):
        candidates = []
        for entry in manifest:
            if entry['program'] != name[:15]:
                continue
            if 'source_bytecode_len' in entry and entry['source_bytecode_len'] != length:
                continue
            if 'prog_type' in entry and entry['prog_type'] != kind:
                continue
            pair = (entry['native_object'], entry.get('symbol', name))
            if pair not in candidates:
                candidates.append(pair)
        selections.append(dict(run=run, name=name, prog_type=kind, bytecode_len=length,
                               loads=count, candidates=[list(c) for c in candidates]))
    identities = []
    for (native, symbol), entry in sorted(carried.items()):
        current = [s for s in selections if [native, symbol] in s['candidates']]
        manifest_len = sorted({e.get('source_bytecode_len') for e in manifest
                               if (e['native_object'], e.get('symbol')) == (native, symbol)}, key=str)
        identities.append(dict(native_object=native, symbol=symbol, program=entry['name'],
            census_rows=entry['rows'], census_outcomes=dict(entry['stages']),
            manifest_bytecode_len=manifest_len,
            current_image_loads=[dict(run=s['run'], bytecode_len=s['bytecode_len'], loads=s['loads'],
                                      candidates=len(s['candidates'])) for s in current]))
    summary = dict(manifest=str(manifest_path), runs=runs,
        carried_forward_rows=sum(i['census_rows'] for i in identities),
        identities=len(identities),
        identities_selected_in_current_image=sum(bool(i['current_image_loads']) for i in identities),
        identities_selected_uniquely=sum(any(l['candidates'] == 1 for l in i['current_image_loads'])
                                         for i in identities),
        load_records=sum(loads.values()),
        load_records_with_one_candidate=sum(s['loads'] for s in selections if len(s['candidates']) == 1),
        load_records_without_candidate=sum(s['loads'] for s in selections if not s['candidates']),
        identities_detail=identities, selections=selections)
    output.write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps({k: v for k, v in summary.items() if k not in ('identities_detail', 'selections')}, indent=2))
    for i in identities:
        print(i['program'], i['native_object'], i['symbol'], 'rows', i['census_rows'],
              'manifest', i['manifest_bytecode_len'],
              'current', [(l['bytecode_len'], l['loads'], l['candidates']) for l in i['current_image_loads']])


if __name__ == '__main__':
    main()
