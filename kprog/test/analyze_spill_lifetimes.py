"""Diagnose CFG liveness of direct, nonescaping MIR spill slots before PEI."""
import argparse
import json
from pathlib import Path
import re


def analyze(path):
    text = path.read_text()
    head, body = text.split('body:             |', 1)
    sizes = {int(i): int(n) for i, n in re.findall(
        r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', head)}
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
                complete_store = ((operation == 'STD' and sizes[slot] == 8) or
                                  (operation == 'STW32' and sizes[slot] == 4))
                blocks[current]['events'].append((slot, operation.startswith('ST'), complete_store))
    live_in = {block: 0 for block in blocks}
    live_out = dict(live_in)
    uses, definitions = {}, {}
    for block, data in blocks.items():
        used = defined = 0
        for slot, store, complete_store in data['events']:
            bit = 1 << slot
            if complete_store:
                defined |= bit
            elif not defined & bit:
                used |= bit
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
    max_live = 0
    for block, data in blocks.items():
        live = live_out[block]
        for slot, store, complete_store in reversed(data['events']):
            bit = 1 << slot
            if store:
                # A store clobbers the slot even when its result is dead.
                conflicts[slot] |= live & ~bit
                if complete_store:
                    live &= ~bit
            if not complete_store:
                live |= bit
                for other in sizes:
                    if live & (1 << other):
                        conflicts[other] |= live & ~(1 << other)
            max_live = max(max_live, live.bit_count())
    pairs = [[a, b] for a in sizes for b in sizes if a < b and
             not (conflicts[a] & (1 << b) or conflicts[b] & (1 << a))]
    return dict(input=str(path), blocks=len(blocks), slots=sizes, rounds=rounds,
                conservative_maximum_live_slots=max_live, noninterfering_pairs=pairs,
                scope='Direct spill CFG diagnostic; partial stores keep the whole old slot live. No rewrite, verifier acceptance or execution.')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mir', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    result = analyze(args.mir)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))
