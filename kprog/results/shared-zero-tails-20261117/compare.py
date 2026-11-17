#!/usr/bin/env python3
"""Pair actual emissions, preserving helper, map, recovery and tail observations."""
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
before = json.loads(a.before.read_text())
after = json.loads(a.after.read_text())
old = {r['capture']: r for r in before['requests']}
new = {r['capture']: r for r in after['requests']}

def facts(row):
    folder = Path(row['output'])
    data = (folder / 'image.blob').read_bytes()
    relocs = list(struct.iter_unpack('<IIQ', (folder / 'image.relocs').read_bytes()))
    text = (folder / 'image.abi').read_text().replace('\\n', '\n').replace('\\t', '\t')
    loads = [tuple(map(int, line.split('\t')[1].split(',')))
             for line in text.splitlines() if line.startswith('load_site\t')]
    maps = (folder / 'image.maps').read_text().replace('\\n', '\n').replace('\\t', '\t')
    return dict(data=data,
        helpers=Counter(t for _, k, t in relocs if k == 1),
        tails=Counter((t, data[o:o+4].hex()) for o, k, t in relocs if k == 10),
        maps=Counter(line.split('\t')[0] for line in maps.splitlines()),
        masks=[line for line in text.splitlines() if line.startswith('callee_saved_mask\t')],
        recovery=Counter((length, dest) for _, length, dest in loads),
        r11=Counter((length, data[offset:offset+length].hex())
                    for offset, length, dest in loads if dest == 11),
        probe=sum(r['bytes'] for r in row['lto_ranges'] if r['piece'] == 'probe_read'))

summary = defaultdict(Counter)
rows = []
for capture in sorted(old.keys() | new.keys()):
    b, n = old.get(capture), new.get(capture)
    app = (n or b)['app']
    c = summary[app]
    c['requests'] += 1
    row = dict(app=app, symbol=(n or b)['symbol'], capture=capture,
               before_output=b['output'] if b else None, after_output=n['output'] if n else None,
               before_status=b['returncode'] if b else None, after_status=n['returncode'] if n else None)
    if b is None or n is None:
        c['unpaired'] += 1
    elif b['returncode'] or n['returncode']:
        c['errors'] += 1
        row.update(before_error=b.get('error_tail'), after_error=n.get('error_tail'))
    else:
        bf, nf = facts(b), facts(n)
        row.update(before_bytes=len(bf['data']), after_bytes=len(nf['data']),
                   identical=bf['data'] == nf['data'],
                   before_probe_bytes=bf['probe'], after_probe_bytes=nf['probe'])
        c.update(emitted=1, before_bytes=len(bf['data']), after_bytes=len(nf['data']),
                 before_probe_bytes=bf['probe'], after_probe_bytes=nf['probe'],
                 changed_payloads=int(bf['data'] != nf['data']),
                 grew=int(len(nf['data']) > len(bf['data'])))
        row['size_delta_is_probe_delta'] = len(bf['data'])-len(nf['data']) == bf['probe']-nf['probe']
        c['other_size_delta'] += int(not row['size_delta_is_probe_delta'])
        for name in ['helpers', 'tails', 'maps', 'masks', 'recovery', 'r11']:
            row[name + '_equal'] = bf[name] == nf[name]
            c[name + '_differences'] += int(bf[name] != nf[name])
    rows.append(row)
result = dict(scope='Actual paired host-neutral emissions; all requests and statuses retained. '
              'R11 instruction bytes/lengths and all recovery shapes, map names, ABI masks, '
              'external helper targets and four-byte tail slots compared. Installed/time '
              'and full semantic equivalence remain the image-batch measurements.',
              before=str(a.before), after=str(a.after),
              before_index_errors=before['index_errors'], after_index_errors=after['index_errors'],
              summary={k: dict(v) for k, v in sorted(summary.items())}, requests=rows)
a.output.mkdir(parents=True, exist_ok=True)
(a.output / 'comparison.json').write_text(json.dumps(result, indent=2)+'\n')
lines = []
for app, s in result['summary'].items():
    lines.append(f"{app}: {s.get('emitted',0)}/{s['requests']} emit, "
                 f"{s.get('before_bytes',0)} -> {s.get('after_bytes',0)} neutral B, "
                 f"{s.get('changed_payloads',0)} changed / {s.get('grew',0)} grew, "
                 f"other size delta {s.get('other_size_delta',0)}; "
                 + ' '.join(f"{name}:{s.get(name+'_differences',0)}" for name in
                          ['helpers','tails','maps','masks','recovery','r11']))
(a.output / 'comparison-summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
