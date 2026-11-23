#!/usr/bin/env python3
"""eBPF side of lookupflow.py: for one program section of a BPF object, the map each bpf_map_lookup_elem
call (call 0x1) receives in r1, by a forward data flow over registers and r10 stack slots with a meet
at joins (a name holds when every predecessor brings the same one); the value of a lookup on map M is
inner(M). Usage: bpfflow.py OBJ SECTION"""
import collections, re, subprocess, sys

obj, sec = sys.argv[1], sys.argv[2]
syms = subprocess.run(['llvm-objdump-18', '-t', obj], capture_output=True, text=True).stdout
maps = {l.split()[-1] for l in syms.splitlines() if ' .maps' in l}
out = subprocess.run(['llvm-objdump-18', '-d', '-r', '--no-show-raw-insn', '--section=' + sec, obj],
                     capture_output=True, text=True).stdout
ins = []
for line in out.splitlines():
    m = re.match(r'^\s*[0-9a-f]+:\s+(R_BPF_\S+)\s+(\S+)', line)
    if m and ins:
        ins[-1]['rel'] = m.group(2); continue
    m = re.match(r'^\s*(\d+):\s+(.*?)\s*$', line)
    if m:
        ins.append({'slot': int(m.group(1)), 't': re.sub(r' <[A-Za-z_.][^ >]*>$', '', m.group(2)), 'rel': None})
by_slot = {x['slot']: i for i, x in enumerate(ins)}

def succs(i):
    t = ins[i]['t']; nxt = [i + 1] if i + 1 < len(ins) else []
    if t == 'exit':
        return []
    m = re.search(r'goto ([+-](?:0x[0-9a-f]+|\d+))$', t)
    if m:
        tgt = by_slot[ins[i]['slot'] + 1 + int(m.group(1), 0)]
        return [tgt] if t.startswith('goto') else nxt + [tgt]
    return nxt

def kill_slots(slots, off, size):
    for o in [o for o in slots if o < off + size and off < o + 8]:
        slots.pop(o)

def transfer(i, st):
    regs, slots = dict(st[0]), dict(st[1]); x = ins[i]; t = x['t']
    if t.startswith('call'):
        m = regs.get('r1')
        for r in ('r0', 'r1', 'r2', 'r3', 'r4', 'r5'):
            regs.pop(r, None)
        if t == 'call 0x1' and m and not m.startswith('inner('):
            regs['r0'] = 'inner(%s)' % m
        return regs, slots
    m = re.fullmatch(r'(r\d) = 0x0 ll', t)
    if m and x['rel']:
        if x['rel'] in maps:
            regs[m.group(1)] = x['rel']
        else:
            regs.pop(m.group(1), None)
        return regs, slots
    m = re.fullmatch(r'(r\d) = (r\d)', t)
    if m:
        if m.group(2) in regs:
            regs[m.group(1)] = regs[m.group(2)]
        else:
            regs.pop(m.group(1), None)
        return regs, slots
    m = re.fullmatch(r'\*\(u(\d+) \*\)\(r10 - (0x[0-9a-f]+)\) = (\S+)', t)
    if m:
        off = -int(m.group(2), 16); kill_slots(slots, off, int(m.group(1)) // 8)
        if m.group(1) == '64' and m.group(3) in regs:
            slots[off] = regs[m.group(3)]
        return regs, slots
    m = re.fullmatch(r'(r\d) = \*\(u64 \*\)\(r10 - (0x[0-9a-f]+)\)', t)
    if m:
        off = -int(m.group(2), 16)
        if off in slots:
            regs[m.group(1)] = slots[off]
        else:
            regs.pop(m.group(1), None)
        return regs, slots
    m = re.match(r'([rw]\d+) ', t)
    if m and not t.startswith('if'):
        regs.pop('r' + m.group(1)[1:], None)
    return regs, slots

n = len(ins); succ = [succs(i) for i in range(n)]
pred = [[] for _ in range(n)]
for i, s in enumerate(succ):
    for k in s:
        pred[k].append(i)
TOP = None; inn = [TOP] * n; outs = [TOP] * n
work = collections.deque(range(n))
while work:
    i = work.popleft()
    if i == 0:
        st = ({}, {})
    else:
        ps = [outs[p] for p in pred[i] if outs[p] is not TOP]
        if not ps:
            continue
        r = dict(ps[0][0]); sl = dict(ps[0][1])
        for a, b in ps[1:]:
            r = {k: v for k, v in r.items() if a.get(k) == v}
            sl = {k: v for k, v in sl.items() if b.get(k) == v}
        st = (r, sl)
    inn[i] = st
    o = transfer(i, st)
    if o != outs[i]:
        outs[i] = o; work.extend(succ[i])
cat = collections.Counter(); names = collections.Counter()
for i, x in enumerate(ins):
    if x['t'] == 'call 0x1':
        m = inn[i][0].get('r1') if inn[i] is not TOP else None
        k = 'unknown' if not m else ('inner' if m.startswith('inner(') else 'map')
        cat[k] += 1; names[m] += 1
print(sec, dict(cat))
for k, v in names.most_common():
    print('  ', v, k)
