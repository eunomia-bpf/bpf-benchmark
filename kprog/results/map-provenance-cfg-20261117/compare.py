#!/usr/bin/env python3
"""Compare captured emissions and named helper sites across the map CFG change."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--before', type=Path, required=True)
p.add_argument('--after', type=Path, required=True)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()

def load(path):
    report = json.loads(path.read_text())
    return report, {r['capture']: r for r in report['requests']}

def facts(row):
    folder = Path(row['output'])
    sites = {}
    for line in (folder / 'stderr').read_text().splitlines():
        if line.startswith('native-link-helper-site '):
            site = json.loads(line.split(' ', 1)[1])
            key = (site['symbol'], site['input_offset'], site['helper'])
            if key in sites:
                raise ValueError(f'duplicate helper site {folder}: {key}')
            sites[key] = site['map']
    abi = (folder / 'image.abi').read_text().replace('\\n', '\n').replace('\\t', '\t')
    mask = [line for line in abi.splitlines() if line.startswith('callee_saved_mask\t')]
    patches = (folder / 'image.maps').read_text().replace('\\n', '\n').replace('\\t', '\t')
    names = Counter(line.split('\t')[0] for line in patches.splitlines())
    data = (folder / 'image.blob').read_bytes()
    relocs = list(struct.iter_unpack('<IIQ', (folder / 'image.relocs').read_bytes()))
    helpers = Counter(hex(target) for _, kind, target in relocs if kind == 1)
    tails = Counter((target, data[offset:offset+4].hex())
                    for offset, kind, target in relocs if kind == 10)
    return sites, data, helpers, tails, names, mask

old_report, old = load(a.before)
new_report, new = load(a.after)
summary = defaultdict(Counter)
rows = []
for capture in sorted(old.keys() | new.keys()):
    before, after = old.get(capture), new.get(capture)
    row = dict(capture=capture, before=before, after=after)
    app = (after or before)['app']
    c = summary[app]
    c['requests'] += 1
    if before is None or after is None:
        c['unpaired'] += 1
    elif before['returncode'] or after['returncode']:
        c['errors'] += 1
    else:
        bs, bb, bh, bt, bm, ba = facts(before)
        ns, nb, nh, nt, nm, na = facts(after)
        changes = []
        for key in sorted(bs.keys() | ns.keys()):
            if key not in bs or key not in ns or bs[key] != ns[key]:
                kind = ('added_site' if key not in bs else 'removed_site' if key not in ns
                        else 'gained_map' if bs[key] is None else
                        'lost_map' if ns[key] is None else 'changed_map')
                changes.append(dict(symbol=key[0], input_offset=key[1], helper=key[2],
                                    before=bs.get(key), after=ns.get(key), change=kind))
                c[kind] += 1
                c[kind + ':' + key[2]] += 1
        row.update(before_bytes=len(bb), after_bytes=len(nb), identical=bb == nb,
                   sites_before=len(bs), sites_after=len(ns), binding_changes=changes,
                   helpers_removed=dict(bh - nh), helpers_added=dict(nh - bh),
                   tail_slots_equal=bt == nt, map_patch_names_equal=bm == nm,
                   abi_mask_equal=ba == na)
        c.update(emitted=1, before_bytes=len(bb), after_bytes=len(nb),
                 changed_payloads=int(bb != nb),
                 changed_helper_targets=int(bh != nh),
                 changed_tail_slots=int(bt != nt), changed_patch_names=int(bm != nm),
                 changed_abi_masks=int(ba != na))
    rows.append(row)

report = dict(scope='Paired host-neutral production emissions and existing named-map diagnostics. '
              'All requests, statuses and site changes retained. Installed bytes, run-time work '
              'and per-call performance remain measurements for the image batch.',
              before=str(a.before), after=str(a.after),
              before_index_errors=old_report['index_errors'],
              after_index_errors=new_report['index_errors'],
              summary={k: dict(v) for k, v in sorted(summary.items())}, requests=rows)
a.output.mkdir(parents=True, exist_ok=True)
(a.output / 'comparison.json').write_text(json.dumps(report, indent=2) + '\n')
lines = []
for app, s in report['summary'].items():
    lines.append(f"{app}: {s.get('emitted', 0)}/{s['requests']} emit; "
                 f"{s.get('before_bytes', 0)} -> {s.get('after_bytes', 0)} neutral B; "
                 f"{s.get('changed_payloads', 0)} changed payloads; "
                 f"maps gained/lost/changed {s.get('gained_map', 0)}/"
                 f"{s.get('lost_map', 0)}/{s.get('changed_map', 0)}; "
                 f"sites added/removed {s.get('added_site', 0)}/{s.get('removed_site', 0)}; "
                 f"helper targets changed {s.get('changed_helper_targets', 0)}; "
                 f"tail/map-patch/mask differences {s.get('changed_tail_slots', 0)}/"
                 f"{s.get('changed_patch_names', 0)}/{s.get('changed_abi_masks', 0)}")
(a.output / 'comparison-summary.txt').write_text('\n'.join(lines) + '\n')
print('\n'.join(lines))
