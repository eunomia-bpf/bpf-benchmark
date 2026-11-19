"""Inspect retained pre-PEI MIR; no rewriting or compiler-limit changes."""
import argparse
from collections import Counter, deque
import json
from pathlib import Path
import re


SLOT = re.compile(r'%stack\.(\d+)')
DECL = re.compile(r'  - \{ id: (\d+),.*type: ([\w-]+),.*size: (\d+), alignment: (\d+),')
BLOCK = re.compile(r'  bb\.(\d+)[^:]*:')
LOAD = re.compile(r'\s*(?:dead )?\$[rw]\d+ = (LDD|LDW32|LDH|LDB) %stack\.(\d+), (-?\d+)(?:,|\s*$)')
STORE = re.compile(r'\s*(STD|STW32|STH32|STB32) (?:killed )?\$[rw]\d+, %stack\.(\d+), (-?\d+)(?:,|\s*$)')
WIDTH = dict(LDD=8, LDW32=4, LDH=2, LDB=1, STD=8, STW32=4, STH32=2, STB32=1)


def inspect(lines):
    slots, blocks, escaped, accesses = {}, {}, set(), {}
    current = None
    in_body = False
    for line in lines:
        if not in_body:
            match = DECL.match(line)
            if match:
                number, kind, size, align = match.groups()
                slots[int(number)] = dict(kind=kind, size=int(size), alignment=int(align))
            if line.startswith('body:             |'):
                in_body = True
            continue
        match = BLOCK.match(line)
        if match:
            current = dict(successors=[], effects=[])
            blocks[int(match[1])] = current
            continue
        if current is None or line.lstrip().startswith('DBG_'):
            continue
        if line.strip().startswith('successors:'):
            current['successors'] = list(map(int, re.findall(r'%bb\.(\d+)', line)))
        referenced = set(map(int, SLOT.findall(line.split('::', 1)[0])))
        if not referenced:
            continue
        load, store = LOAD.match(line), STORE.match(line)
        for number in referenced:
            accesses.setdefault(number, Counter())[line.strip().split(' ', 1)[0] if not load else load[1]] += 1
        if load or store:
            match = load or store
            number = int(match[2])
            width, offset = WIDTH[match[1]], int(match[3])
            if referenced == {number} and 0 <= offset and offset + width <= slots[number]['size']:
                current['effects'].append((number, width, offset, bool(store)))
                continue
        # Address-taking and unfamiliar instructions cannot support a direct
        # byte-lifetime claim. Keep them out of this analysis.
        escaped.update(referenced)
    eligible = sorted(n for n, s in slots.items() if s['kind'] == 'spill-slot' and n not in escaped)
    bits, bases, next_bit = {}, {}, 0
    for number in eligible:
        bases[number] = next_bit
        bits[number] = ((1 << slots[number]['size']) - 1) << next_bit
        next_bit += slots[number]['size']
    predecessors = {number: [] for number in blocks}
    for number, block in blocks.items():
        used = defined = 0
        block['effects'] = [(((1 << width) - 1) << (bases[n] + offset), store)
                            for n, width, offset, store in block['effects'] if n in bits]
        for bit, store in block['effects']:
            if store:
                defined |= bit
            else:
                used |= bit & ~defined
        block.update(used=used, defined=defined, livein=0, liveout=0)
        for successor in block['successors']:
            predecessors[successor].append(number)
    queue = deque(reversed(blocks))
    pending = set(queue)
    visits = 0
    while queue:
        number = queue.popleft()
        pending.remove(number)
        block = blocks[number]
        liveout = 0
        for successor in block['successors']:
            liveout |= blocks[successor]['livein']
        livein = block['used'] | (liveout & ~block['defined'])
        block['liveout'] = liveout
        visits += 1
        if livein != block['livein']:
            block['livein'] = livein
            for predecessor in predecessors[number]:
                if predecessor not in pending:
                    pending.add(predecessor)
                    queue.append(predecessor)
    def byte_count(live):
        return live.bit_count()
    peaks = []
    for number, block in blocks.items():
        live = block['liveout']
        peak = live
        peak_size = byte_count(peak)
        for bit, store in reversed(block['effects']):
            live = live & ~bit if store else live | bit
            size = byte_count(live)
            if size > peak_size:
                peak, peak_size = live, size
        peaks.append(dict(block=number, live_bytes=peak_size, livein_bytes=byte_count(block['livein']),
                          slots=[n for n, bit in bits.items() if peak & bit]))
    return dict(slots=len(slots), declared_bytes=sum(s['size'] for s in slots.values()),
                shapes=dict(Counter(f"{s['kind']}:{s['size']}:{s['alignment']}" for s in slots.values())),
                eligible_spill_slots=len(eligible), excluded_slots=sorted(escaped),
                accesses=accesses,
                blocks=len(blocks), dataflow_visits=visits,
                peaks=sorted(peaks, key=lambda p: p['live_bytes'], reverse=True)[:10],
                scope='Conservative CFG byte liveness, not path feasibility, stock acceptance or a runtime measurement.')


def selftest():
    head = ''.join(f"  - {{ id: {n}, type: spill-slot, size: 8, alignment: 8,\n" for n in range(3))
    # A branch joins a loop. Slot 0 must stay live through the loop, while
    # the partial store to slot 2 does not kill its upper four bytes.
    body = '''body:             |
  bb.0:
    successors: %bb.1, %bb.2
    STD $r1, %stack.0, 0
  bb.1:
    successors: %bb.3
    STD $r1, %stack.1, 0
  bb.2:
    successors: %bb.3
    STD $r2, %stack.1, 0
  bb.3:
    successors: %bb.3, %bb.4
    $r1 = LDD %stack.1, 0
    STW32 $w1, %stack.2, 0
  bb.4:
    $r1 = LDD %stack.0, 0
    $r2 = LDD %stack.2, 0
'''
    result = inspect((head + body).splitlines())
    assert result['eligible_spill_slots'] == 3 and result['excluded_slots'] == [], result
    assert max(p['live_bytes'] for p in result['peaks']) == 24, result
    loop = next(p for p in result['peaks'] if p['block'] == 3)
    assert loop['slots'] == [0, 1, 2] and loop['livein_bytes'] == 20, result
    print('CFG join/loop/partial-store regression passed')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mir', type=Path, nargs='?')
    parser.add_argument('output', type=Path, nargs='?')
    args = parser.parse_args()
    selftest()
    if args.mir:
        with args.mir.open() as stream:
            result = inspect(stream)
        result['source'] = str(args.mir)
        args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps({k: v for k, v in result.items() if k != 'peaks'}))
