"""Inventory spill interference on archived MIR; no compiler policy change."""
from collections import deque
import json
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
from whole_word_spills import machine_blocks, remove_dead_frame_addresses, narrow_scalar_storage

def bits(mask):
    while mask:
        bit = mask & -mask
        yield bit.bit_length()-1
        mask ^= bit

def inspect(text):
    head, body = text.split('body:             |', 1)
    slots = {int(n): int(size) for n, size in re.findall(
        r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', head)}
    low_bits = sum(1 << (2*n) for n in slots)

    def objects(live):
        return (live | (live >> 1)) & low_bits
    blocks = machine_blocks(body)
    parents = {n: set() for n in blocks}
    accesses = {}
    for n, block in blocks.items():
        accesses[n] = []
        for child in block['successors']:
            parents[child].add(n)
        for line in block['lines']:
            if line.lstrip().startswith('DBG_'):
                continue
            selected = set(map(int, re.findall(r'%stack\.(\d+)', line))) & slots.keys()
            if not selected:
                continue
            if len(selected) != 1:
                raise ValueError('multiple spill operands: ' + line)
            slot = selected.pop()
            store = re.fullmatch(r'\s*(STD|STW32) (?:killed )?\$[rw]\d+, %stack\.\d+, 0(?:, debug-location !\d+)?', line)
            load = re.fullmatch(r'\s*(?:dead )?\$[rw]\d+ = (LDD|LDW32) %stack\.\d+, 0(?:, debug-location !\d+)?', line)
            operation = store or load
            width = 8 if operation is not None and operation[1] in {'STD', 'LDD'} else 4
            if operation is None or slots[slot] < width:
                raise ValueError('unsupported spill access: ' + line)
            accesses[n].append((slot, store is not None, (3 if width == 8 else 1) << (2*slot)))
    entry, outgoing = dict.fromkeys(blocks, 0), dict.fromkeys(blocks, 0)
    queue, queued = deque(reversed(blocks)), set(blocks)
    while queue:
        n = queue.popleft(); queued.remove(n)
        live = 0
        for child in blocks[n]['successors']:
            live |= entry[child]
        outgoing[n] = live
        for slot, store, mask in reversed(accesses[n]):
            live = live & ~mask if store else live | mask
        if entry[n] != live:
            entry[n] = live
            for parent in parents[n]-queued:
                queue.append(parent); queued.add(parent)
    neighbors, peak = dict.fromkeys(slots, 0), 0
    for n in blocks:
        live = outgoing[n]
        peak = max(peak, objects(live).bit_count())
        for slot, store, mask in reversed(accesses[n]):
            neighbors[slot] |= objects(live) & ~(1 << (2*slot))
            live = live & ~mask if store else live | mask
            peak = max(peak, objects(live).bit_count())
    # Live-in values also interfere even if this function has no defining store.
    initial = objects(entry[next(iter(blocks))])
    for bit in bits(initial):
        neighbors[bit//2] |= initial & ~(1 << bit)
    for slot, mask in list(neighbors.items()):
        for other in bits(mask):
            neighbors[other//2] |= 1 << (2*slot)
    colors = {}
    for slot in sorted(slots, key=lambda n: (-neighbors[n].bit_count(), n)):
        occupied = {colors[n//2] for n in bits(neighbors[slot]) if n//2 in colors}
        color = 0
        while color in occupied:
            color += 1
        colors[slot] = color
    return dict(blocks=len(blocks),spill_objects=len(slots),peak_live_spill_objects=peak,
        greedy_colors_ignoring_size_classes=max(colors.values(), default=-1)+1,
        scope='Static CFG liveness/interference. Colors ignore size classes and escaped/default storage; not an emitted layout or a verifier result.')

rows = []
for stage in ('before', 'packed'):
    path = HERE.relative_to(ROOT) / 'request-39' / ('trusted_x86.bpf.' + stage + '.mir')
    text = subprocess.check_output(['git', 'show', 'fab61404f:' + str(path)], cwd=ROOT, text=True)
    text = next(document for document in text.split('\n---\n') if 'body:             |' in document)
    if stage == 'before':
        text, _ = remove_dead_frame_addresses(text)
        text, _ = narrow_scalar_storage(text)
    rows.append(dict(revision='fab61404f',path=str(path),stage=stage,**inspect(text)))
(HERE / 'spill-liveness.json').write_text(json.dumps(rows, indent=2) + '\n')
print(json.dumps(rows, indent=2))
