"""usage: origin.py <outcomes.json.gz> <rows.json>

Classify the origin of the scalar base register for every census body rejected with Rn invalid mem access 'scalar'."""
import json, gzip, re, collections, sys
o = json.load(gzip.open(sys.argv[1]))
inst = json.load(open('/workspaces/repository/corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped/instances.json'))['programs']
weights = collections.Counter(p['body_sha256'] for p in inst)
INS = re.compile(r'^(\d+): \((\w\w)\) (.*?)(?:\s+; (.*))?$')
def origin(lines, reg, idx, depth=0):
    # walk back from idx to the instruction that last wrote reg
    for j in range(idx - 1, -1, -1):
        m = INS.match(lines[j])
        if not m: continue
        text = m.group(3)
        if re.match(r'call ', text) and reg == 'r0':
            return 'helper ' + text.split()[1].split('#')[0]
        if re.match(rf'{reg} = \*\(u(\d+) \*\)\((r\d+) ([+-]\d+)\)', text):
            w, base, off = re.match(rf'{reg} = \*\(u(\d+) \*\)\((r\d+) ([+-]\d+)\)', text).groups()
            st = m.group(4) or ''
            bt = re.search(rf'\b{base.upper()}=(\w+)', st)
            btype = bt.group(1) if bt else '?'
            if base == 'r10': btype = 'fp'
            if btype == 'scalar' and depth < 4:
                return f'load u{w} via scalar <- ' + origin(lines, base, j, depth + 1)
            return f'load u{w} from {btype}'
        mm = re.match(rf'{reg} = (r\d+)$', text)
        if mm:
            return origin(lines, mm.group(1), j, depth)
        if re.match(rf'{reg} (\S+)= ', text):
            mm = re.match(rf'{reg} (\S+)= (\S+)', text)
            src = mm.group(2)
            if re.match(r'r\d+$', src) and mm.group(1) == '+':
                a = origin(lines, reg, j, depth); b = origin(lines, src, j, depth)
                return f'({a}) + ({b})'
            continue  # arithmetic with constant keeps origin
        if re.match(rf'{reg} = ', text) or re.match(rf'w{reg[1:]} = ', text):
            return 'set ' + re.sub(r'0x[0-9a-f]+', 'K', text.split('=', 1)[1].strip())[:40]
    return 'entry'
rows = []
for k, v in o.items():
    if '/before-' in k: continue
    d = v.get('diagnostic') or ''
    i = d.find("invalid mem access 'scalar'")
    if i < 0: continue
    tail = d[:i].rsplit('\n', 400)[-400:]
    err = d[i - 8:i].split('\n')[-1].strip()
    reg = 'r' + re.search(r'R(\d+)', d[i - 8:i]).group(1)
    lines = [l for l in tail if INS.match(l)]
    last = INS.match(lines[-1]).group(3)
    rows.append(dict(body=k, app=v['application'], name=v['name'], instances=weights[k], insn=last,
                     origin=origin(lines, reg, len(lines) - 1)))
c, b = collections.Counter(), collections.Counter()
for r in rows:
    key = re.sub(r'u\d+', 'uN', r['origin'])
    c[key] += r['instances']; b[key] += 1
for key, n in c.most_common(): print(n, 'instances', b[key], 'bodies', key)
json.dump(rows, open(sys.argv[2], 'w'), indent=1)
