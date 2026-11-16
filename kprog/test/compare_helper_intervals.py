"""Compare reference lookup code between unchanged non-lookup helper anchors.

This observes static code from existing linker replays and retains all source
lookups. Dynamic branch frequency, program safety and runtime work are separate
questions.
"""
import argparse
import json
from pathlib import Path
import re


def compare(a):
    source = json.loads(a.source.read_text())['runtime']['helper_sites']
    reference = json.loads(a.reference.read_text())['runtime']['relocations']
    plan = json.loads(a.plan.read_text())
    helpers = {h['name']: h['addr'] for h in plan['helpers']}
    targets = {r['target'] for r in reference}
    anchors = {s['helper'] for s in source if s['helper'] != 'bpf_map_lookup_elem'
               and helpers.get(s['helper']) in targets}
    by_address = {helpers[name]: name for name in anchors}
    lookup_targets = {helpers['bpf_map_lookup_elem']}
    for group in ('lookup_sites', 'lookup_maps'):
        lookup_targets.update(s['target_addr'] for s in plan[group])
    source_intervals, source_anchors, pending = [], [], []
    for site in source:
        if site['helper'] == 'bpf_map_lookup_elem':
            pending.append(site)
        elif site['helper'] in anchors:
            source_intervals.append(pending)
            pending = []
            source_anchors.append(dict(helper=site['helper'], offset=site['input_offset']))
    source_intervals.append(pending)
    reference_intervals, reference_anchors, pending = [], [], []
    for relocation in sorted(reference, key=lambda r:r['offset']):
        target = relocation['target']
        if target in by_address:
            reference_intervals.append(pending)
            pending = []
            reference_anchors.append(dict(helper=by_address[target], offset=relocation['offset']))
        elif target in lookup_targets:
            pending.append(relocation)
    reference_intervals.append(pending)
    aligned = ([s['helper'] for s in source_anchors] ==
               [s['helper'] for s in reference_anchors])
    intervals = []
    if aligned:
        for index, (sites, calls) in enumerate(zip(source_intervals, reference_intervals)):
            intervals.append(dict(
                previous_anchor=source_anchors[index-1] if index else None,
                next_anchor=source_anchors[index] if index < len(source_anchors) else None,
                source_lookups=sites, reference_external_lookups=calls,
                lru_sites=[s['input_offset'] for s in sites if s['input_offset'] in a.lru_site]))
    reference_text = a.disassembly.read_text()
    offsets = {m['value_offset'] for m in plan['lookup_maps'] if m['kind'] == 'lru_hash'}
    ref_stores = []
    for line in reference_text.splitlines():
        # The preserved emitter's LRU postprocessing stores1 to [rax+ref].
        for offset in offsets:
            address = 'rax' if not offset else r'rax\+0?'+format(offset, 'x')+'h'
            if re.search(r'\bmov byte \['+address+r'\],1\b', line.lower()):
                ref_stores.append(line)
    result = dict(scope=__doc__, source=str(a.source), reference=str(a.reference),
        plan=str(a.plan), helper_anchor_sequences_equal=aligned,
        source_anchors=source_anchors, reference_anchors=reference_anchors,
        intervals=intervals, expected_lru_sites=a.lru_site,
        lru_ref_offsets=sorted(offsets), direct_reference_lru_ref_stores=ref_stores,
        interpretation='External-call and ref-store presence describe the static output in each aligned interval. Multiple source sites in an interval share the same reported reference calls. Actual branch frequency awaits runtime observation.')
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(dict(anchors_equal=aligned, anchors=len(source_anchors),
        direct_lru_ref_stores=len(ref_stores),
        lru_intervals=[dict(lru_sites=i['lru_sites'],
                           reference_external_lookups=len(i['reference_external_lookups']))
                       for i in intervals if i['lru_sites']])))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('source', 'reference', 'plan', 'disassembly', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--lru-site', type=int, action='append', default=[])
    compare(parser.parse_args())
