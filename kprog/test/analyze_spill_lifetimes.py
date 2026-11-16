"""Diagnose byte liveness of direct, nonescaping MIR spill slots before PEI."""
import argparse
import json
from pathlib import Path
import re


def analyze(path):
    text = path.read_text()
    head, body = text.split('body:             |', 1)
    sizes = {int(i): int(n) for i, n in re.findall(
        r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', head)}
    offsets, slot_masks, cursor = {}, {}, 0
    for slot, size in sizes.items():
        offsets[slot] = cursor
        slot_masks[slot] = ((1 << size)-1) << cursor
        cursor += size
    blocks = {}
    for line in body.splitlines():
        match = re.match(r'  bb\.(\d+)[^:]*:', line)
        if match:
            current = int(match[1])
            blocks[current] = dict(successors=[], events=[])
        elif line.strip().startswith('successors:'):
            blocks[current]['successors'] = list(map(int, re.findall(r'%bb\.(\d+)', line)))
        elif not line.lstrip().startswith('DBG_'):
            operands = [int(i) for i in re.findall(r'%stack\.(\d+)', line)]
            spills = set(operands) & sizes.keys()
            if spills:
                match = re.search(r'\b(LDD|LDW32|LDW|LDH|LDB|STD|STW32)\b.*%stack\.(\d+), 0(?:,| |$)', line)
                if not match or len(operands) != 1:
                    raise ValueError(f'Unhandled spill access: {line}')
                operation, slot = match[1], int(match[2])
                width = dict(LDD=8, LDW32=4, LDW=4, LDH=2, LDB=1, STD=8, STW32=4)[operation]
                mask = ((1 << min(width, sizes[slot]))-1) << offsets[slot]
                blocks[current]['events'].append((slot, operation.startswith('ST'), mask))
    live_in = {block: 0 for block in blocks}
    live_out = dict(live_in)
    uses, definitions = {}, {}
    for block, data in blocks.items():
        used = defined = 0
        for slot, store, mask in data['events']:
            if store:
                defined |= mask
            else:
                used |= mask & ~defined
        uses[block], definitions[block] = used, defined
    rounds = 0
    changed = True
    while changed:
        rounds += 1
        changed = False
        for block, data in reversed(blocks.items()):
            outgoing = 0
            for successor in data['successors']:
                outgoing |= live_in[successor]
            incoming = uses[block] | (outgoing & ~definitions[block])
            if incoming != live_in[block] or outgoing != live_out[block]:
                live_in[block], live_out[block] = incoming, outgoing
                changed = True
    conflicts = {slot: 0 for slot in sizes}
    max_live = max_bytes = 0
    def live_slots(mask):
        return sum(1 << slot for slot in sizes
                   if mask & slot_masks[slot])
    for block, data in blocks.items():
        live = live_out[block]
        for slot, store, mask in reversed(data['events']):
            bit = 1 << slot
            if store:
                # A store clobbers the slot even when its result is dead.
                conflicts[slot] |= live_slots(live) & ~bit
                live &= ~mask
            else:
                live |= mask
            words = live_slots(live)
            for other in sizes:
                if words & (1 << other):
                    conflicts[other] |= words & ~(1 << other)
            max_live = max(max_live, words.bit_count())
            max_bytes = max(max_bytes, live.bit_count())
    pairs = [[a, b] for a in sizes for b in sizes if a < b and
             not (conflicts[a] & (1 << b) or conflicts[b] & (1 << a))]
    return dict(input=str(path), blocks=len(blocks), slots=sizes, rounds=rounds,
                conservative_maximum_live_slots=max_live, noninterfering_pairs=pairs,
                maximum_live_bytes=max_bytes,
                scope='Byte-precise CFG liveness; slot merging still excludes any simultaneously live slot parts and dead-store clobbers. No rewrite, verifier acceptance or execution.')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mir', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    result = analyze(args.mir)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))
