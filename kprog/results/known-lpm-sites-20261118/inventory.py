#!/usr/bin/env python3
"""Count captured direct trie targets before extending named-map LPM lowering."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--replay', type=Path, required=True)
p.add_argument('--system-map', type=Path, required=True)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()
symbols = {}
for line in a.system_map.read_text().splitlines():
    fields = line.split()
    if len(fields) == 3:
        symbols[fields[2]] = int(fields[0], 16)
report = json.loads(a.replay.read_text())
summary = defaultdict(Counter)
rows = []
for request in report['requests']:
    c = summary[request['app']]
    c['requests'] += 1
    row = dict(app=request['app'], symbol=request['symbol'], capture=request['capture'],
               output=request['output'], plan=request['plan'], returncode=request['returncode'])
    if request['returncode']:
        row['error_tail'] = request['error_tail']
        c['errors'] += 1
        rows.append(row)
        continue
    plan = json.loads(Path(request['plan']).read_text())
    helpers = {h['name']: h['addr'] for h in plan['helpers']}
    slide = helpers['bpf_map_lookup_elem'] - symbols['bpf_map_lookup_elem']
    trie = symbols['trie_lookup_elem'] + slide
    anchors = {name: helpers[name]-symbols[name] == slide for name in
               ['bpf_map_update_elem','bpf_map_delete_elem','bpf_get_current_pid_tgid',
                'bpf_get_current_uid_gid'] if name in helpers and name in symbols}
    hashes = [s['target_addr']-symbols['__htab_map_lookup_elem'] == slide
              for s in plan['lookup_maps'] if s['kind'] in
              ['hash','lru_hash','percpu_hash','hash_of_maps']]
    maps = {s['name']: s for s in plan['lookup_maps'] if s['kind'] == 'call' and s['target_addr'] == trie}
    folder = Path(request['output'])
    sites = []
    for line in (folder/'stderr').read_text().splitlines():
        if line.startswith('native-link-helper-site '):
            s = json.loads(line.split(' ',1)[1])
            if s['helper'] == 'bpf_map_lookup_elem' and s['map'] in maps:
                sites.append(s)
    relocs = list(struct.iter_unpack('<IIQ', (folder/'image.relocs').read_bytes()))
    direct = [offset for offset, kind, target in relocs if kind == 1 and target == trie]
    fast = [r for r in request['lto_ranges'] if r['piece'] in ['runtime_array_lpm','lpm_lookup']]
    row.update(boot_slide=slide, trie_target=trie, independent_helper_anchors=anchors,
               hash_anchors=hashes, named_trie_maps=maps, named_trie_sites=sites,
               direct_trie_calls=direct, generic_fast_ranges=fast)
    c.update(emitted=1, named_sites=len(sites), direct_calls=len(direct),
             requests_with_named_sites=int(bool(sites)),
             requests_with_direct_calls=int(bool(direct)),
             requests_with_generic_fast=int(bool(fast)),
             requests_with_both=int(bool(direct) and bool(fast)),
             inconsistent_anchors=int(not all(anchors.values()) or not all(hashes)))
    rows.append(row)
result = dict(scope='Static current captured sites and external call relocations, correlated to '
              'the sole kernel System.map by the captured generic map-helper address and '
              'independent helper/raw-hash anchors. Every status retained. Addresses are '
              'diagnostic correlations; input plans and emitted programs stay unchanged. '
              'Site counts establish code shape, while branch frequency and per-call cost '
              'remain runtime measurements.', replay=str(a.replay), system_map=str(a.system_map),
              index_errors=report['index_errors'],
              summary={k:dict(v) for k,v in sorted(summary.items())}, requests=rows)
a.output.mkdir(parents=True,exist_ok=True)
(a.output/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
lines = [f"{app}: {s.get('emitted',0)}/{s['requests']} emit, {s['named_sites']} named LPM sites, "
         f"{s['direct_calls']} direct trie calls in {s['requests_with_direct_calls']} requests, "
         f"{s['requests_with_both']} also have generic native trie ranges, "
         f"{s['inconsistent_anchors']} inconsistent boot anchors" for app,s in result['summary'].items()]
(a.output/'summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
