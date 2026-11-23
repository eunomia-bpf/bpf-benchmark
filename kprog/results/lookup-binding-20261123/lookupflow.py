#!/usr/bin/env python3
"""Count x86 native bpf_map_lookup_elem calls whose map is known in %rdi, under four rules:
  A  straight-line code, registers only (today's linker: names forgotten at every branch target)
  B  straight-line code, registers and 8-byte %rsp stack slots
  C  control-flow meet (a name holds at a join when every predecessor brings the same one), registers
  D  control-flow meet, registers and stack slots
Usage: lookupflow.py OBJ [OBJ...]"""
import re, subprocess, sys, collections

REG64 = {}
for fam, names in {
    'rax': 'rax eax ax al ah', 'rbx': 'rbx ebx bx bl bh', 'rcx': 'rcx ecx cx cl ch', 'rdx': 'rdx edx dx dl dh',
    'rsi': 'rsi esi si sil', 'rdi': 'rdi edi di dil', 'rbp': 'rbp ebp bp bpl', 'rsp': 'rsp esp sp spl',
}.items():
    for n in names.split():
        REG64[n] = fam
for i in range(8, 16):
    for suf in ('', 'd', 'w', 'b'):
        REG64['r%d%s' % (i, suf)] = 'r%d' % i
CALLER = {'rax', 'rcx', 'rdx', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11'}
INS = re.compile(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*?)\s*(#.*)?$')
REL = re.compile(r'^\s*([0-9a-f]+):\s+(R_X86_64_\S+)\s+(\S+?)(?:[-+]0x[0-9a-f]+)?$')
FUNC = re.compile(r'^([0-9a-f]+) <(.+)>:$')
NONMAP = re.compile(r'^(bpf_|ktime_|jiffies|__kprog|__native|\.L|\.rodata|\.data|\.bss)')

def parse(obj):
    out = subprocess.run(['objdump', '-dr', '--no-show-raw-insn', obj], capture_output=True, text=True).stdout
    funcs = collections.OrderedDict(); cur = None
    for line in out.splitlines():
        m = FUNC.match(line)
        if m:
            cur = funcs.setdefault(m.group(2), []); continue
        if cur is None:
            continue
        m = REL.match(line)
        if m and cur:
            cur[-1]['rel'] = (m.group(2), m.group(3)); continue
        m = INS.match(line)
        if m:
            cur.append({'ip': int(m.group(1), 16), 'mn': m.group(2), 'ops': m.group(3), 'rel': None})
    return funcs

def split_ops(ops):
    parts, depth, cur = [], 0, ''
    for ch in ops:
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
        if ch == ',' and depth == 0:
            parts.append(cur.strip()); cur = ''
        else:
            cur += ch
    if cur.strip():
        parts.append(cur.strip())
    return parts

def reg(op):
    m = re.fullmatch(r'%(\w+)', op or '')
    return REG64.get(m.group(1)) if m else None

def rsp_slot(op):
    m = re.fullmatch(r'(-?0x[0-9a-f]+|-?\d+)?\(%rsp\)', op or '')
    if not m:
        return None
    return int(m.group(1), 0) if m.group(1) else 0

def is_map_got(insn):
    r = insn['rel']
    return insn['mn'].startswith('mov') and r and 'GOTPC' in r[0] and not NONMAP.match(r[1])

def transfer(insn, st, slots_on):
    regs, slots = st
    regs = dict(regs); slots = dict(slots) if slots_on else {}
    mn, ops = insn['mn'], split_ops(insn['ops'])
    dst = ops[-1] if ops else None
    if mn.startswith('call'):
        m = regs.get('rdi')
        for r in CALLER:
            regs.pop(r, None)
        rel = insn['rel']
        if INNER and m and not m.startswith('inner(') and rel and rel[1] == 'bpf_map_lookup_elem':
            regs['rax'] = 'inner(%s)' % m   # the value of a map-of-maps lookup is its inner map
        return regs, slots
    if is_map_got(insn) and reg(dst):
        regs[reg(dst)] = insn['rel'][1]; return regs, slots
    if mn in ('mov', 'movq') and len(ops) == 2:
        s, d = ops
        if reg(s) and reg(d) and re.fullmatch(r'%r\w+', s) and re.fullmatch(r'%r\w+', d) and not re.fullmatch(r'%r\d+[dwb]', s):
            if reg(s) in regs:
                regs[reg(d)] = regs[reg(s)]
            else:
                regs.pop(reg(d), None)
            return regs, slots
        if slots_on and re.fullmatch(r'%r\w+', s) and not re.fullmatch(r'%r\d+[dwb]', s) and rsp_slot(d) is not None:
            off = rsp_slot(d)
            for o in [o for o in slots if abs(o - off) < 8]:
                slots.pop(o)
            if reg(s) in regs:
                slots[off] = regs[reg(s)]
            return regs, slots
        if slots_on and rsp_slot(s) is not None and re.fullmatch(r'%r\w+', d) and not re.fullmatch(r'%r\d+[dwb]', d):
            off = rsp_slot(s)
            if off in slots:
                regs[reg(d)] = slots[off]
            else:
                regs.pop(reg(d), None)
            return regs, slots
    if mn.startswith(('push', 'pop')) or (reg(dst) == 'rsp'):
        slots = {}
    if mn.startswith(('xchg', 'xadd', 'cmpxchg')):
        for o in ops:
            if reg(o):
                regs.pop(reg(o), None)
    if dst and reg(dst) and not mn.startswith(('cmp', 'test', 'bt', 'j', 'push')):
        regs.pop(reg(dst), None)
    if mn.startswith(('pop', 'cpuid', 'rdtsc', 'mul', 'imul', 'div', 'idiv', 'cqto', 'cltq', 'cltd', 'rep', 'stos', 'movs', 'cmpxchg')):
        for r in ('rax', 'rdx', 'rcx', 'rdi', 'rsi'):
            regs.pop(r, None)
    if slots_on and dst and rsp_slot(dst) is not None and not mn.startswith(('cmp', 'test', 'bt')):
        off = rsp_slot(dst)
        for o in [o for o in slots if abs(o - off) < 8]:
            slots.pop(o)
    return regs, slots

def succs(insns, i):
    insn = insns[i]; mn = insn['mn']
    nxt = [i + 1] if i + 1 < len(insns) else []
    if mn.startswith('ret') or mn.startswith('ud2'):
        return [], False
    if mn.startswith('j'):
        m = re.match(r'([0-9a-f]+)\s*<', insn['ops'])
        if not m:
            return nxt, True          # indirect jump
        t = int(m.group(1), 16)
        tgt = [k for k, x in enumerate(insns) if x['ip'] == t]
        if mn in ('jmp', 'jmpq'):
            return tgt, False
        return nxt + tgt, False
    return nxt, False

def analyze(insns, flow, slots_on):
    n = len(insns)
    if n == 0:
        return []
    succ = []; indirect = False; targets = set()
    for i in range(n):
        s, ind = succs(insns, i); succ.append(s); indirect |= ind
        if insns[i]['mn'].startswith('j'):
            targets.update(k for k in s if k != i + 1)
    pred = [[] for _ in range(n)]
    for i, s in enumerate(succ):
        for k in s:
            pred[k].append(i)
    TOP = None
    inn = [TOP] * n; outs = [TOP] * n
    inn[0] = ({}, {})
    work = collections.deque(range(n))
    def meet(states):
        states = [s for s in states if s is not TOP]
        if not states:
            return TOP
        r = dict(states[0][0]); sl = dict(states[0][1])
        for regs, slots in states[1:]:
            r = {k: v for k, v in r.items() if regs.get(k) == v}
            sl = {k: v for k, v in sl.items() if slots.get(k) == v}
        return r, sl
    while work:
        i = work.popleft()
        if i == 0:
            st = ({}, {})
        elif indirect:
            st = ({}, {})
        elif not flow and i in targets:
            st = ({}, {})
        elif not flow:
            st = outs[i - 1] if i - 1 >= 0 and outs[i - 1] is not TOP and i in [k for k in succ[i - 1]] else ({}, {})
        else:
            st = meet([outs[p] for p in pred[i]])
            if st is TOP:
                continue
        inn[i] = st
        o = transfer(insns[i], st, slots_on)
        if o != outs[i]:
            outs[i] = o
            for k in succ[i]:
                work.append(k)
    res = []
    for i, insn in enumerate(insns):
        r = insn['rel']
        if insn['mn'].startswith('call') and r and r[1] == 'bpf_map_lookup_elem':
            st = inn[i]
            res.append(st[0].get('rdi') if st is not TOP else None)
    return res

INNER = False

def main():
    global INNER
    tot = collections.Counter(); inner_maps = collections.Counter()
    for obj in sys.argv[1:]:
        funcs = parse(obj)
        c = collections.Counter()
        for name, insns in funcs.items():
            for mode, flow, sl in (('A', False, False), ('B', False, True), ('C', True, False), ('D', True, True)):
                INNER = False
                r = analyze(insns, flow, sl)
                c[mode + 'known'] += sum(1 for x in r if x)
                if mode == 'A':
                    c['lookups'] += len(r)
            INNER = True
            r = analyze(insns, True, True)
            for x in r:
                if x and x.startswith('inner('):
                    c['inner'] += 1; inner_maps[(obj.split('/')[-1], name, x)] += 1
        tot += c
        print('%-50s lookups %4d  A %4d  B %4d  C %4d  D %4d  inner %4d' % (obj.split('native-bpf/')[-1][-50:], c['lookups'], c['Aknown'], c['Bknown'], c['Cknown'], c['Dknown'], c['inner']))
    print('%-50s lookups %4d  A %4d  B %4d  C %4d  D %4d  inner %4d' % ('TOTAL', tot['lookups'], tot['Aknown'], tot['Bknown'], tot['Cknown'], tot['Dknown'], tot['inner']))
    for k, v in sorted(inner_maps.items()):
        print('   inner site', v, *k)

main()
