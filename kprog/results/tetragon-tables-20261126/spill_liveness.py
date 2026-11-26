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
            accesses[n].append((slot, store is not None, (3 if width == 8 else 1) << (2*slot), line))
    entry, outgoing = dict.fromkeys(blocks, 0), dict.fromkeys(blocks, 0)
    queue, queued = deque(reversed(blocks)), set(blocks)
    while queue:
        n = queue.popleft(); queued.remove(n)
        live = 0
        for child in blocks[n]['successors']:
            live |= entry[child]
        outgoing[n] = live
        for slot, store, mask, line in reversed(accesses[n]):
            live = live & ~mask if store else live | mask
        if entry[n] != live:
            entry[n] = live
            for parent in parents[n]-queued:
                queue.append(parent); queued.add(parent)
    neighbors, peak, witness = dict.fromkeys(slots, 0), 0, None

    def observe(live, block, line):
        nonlocal peak, witness
        count = objects(live).bit_count()
        if count > peak:
            peak = count
            selected = [bit//2 for bit in bits(objects(live))]
            witness = dict(block=block, label=blocks[block]['label'], access=line.strip(),
                successors=blocks[block]['successors'], live_slots=selected,
                live_object_bytes=sum(slots[i] for i in selected),
                live_32bit_halves=live.bit_count(), block_lines=blocks[block]['lines'])
    for n in blocks:
        live = outgoing[n]
        observe(live, n, '<block exit>')
        for slot, store, mask, line in reversed(accesses[n]):
            neighbors[slot] |= objects(live) & ~(1 << (2*slot))
            live = live & ~mask if store else live | mask
            observe(live, n, line)
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
        peak_witness=witness,
        scope='Static CFG liveness/interference. Colors ignore size classes and escaped/default storage; not an emitted layout or a verifier result.')

mode = sys.argv[1:]
if mode not in [[], ['peaks'], ['tag-only-peaks']]:
    raise SystemExit('usage: spill_liveness.py [peaks|tag-only-peaks]')
revision = '09cd90f09' if mode == ['tag-only-peaks'] else 'fab61404f'
rows = []
for stage in ('before', 'packed'):
    path = HERE.relative_to(ROOT) / 'request-39' / ('trusted_x86.bpf.' + stage + '.mir')
    text = subprocess.check_output(['git', 'show', revision + ':' + str(path)], cwd=ROOT, text=True)
    metadata = dict(re.findall(r'^\s*!(\d+) = (.+)$', text, re.M))
    text = next(document for document in text.split('\n---\n') if 'body:             |' in document)
    if stage == 'before':
        text, _ = remove_dead_frame_addresses(text)
        text, _ = narrow_scalar_storage(text)
    result = inspect(text)
    if mode:
        witness = result['peak_witness']
        locations = set(re.findall(r'debug-location !(\d+)', '\n'.join(witness['block_lines'])))
        witness['debug_locations'] = {n: metadata[n] for n in sorted(locations, key=int)}
    else:
        result.pop('peak_witness')
    rows.append(dict(revision=revision,path=str(path),stage=stage,**result))
output = 'tag-only-spill-peaks.json' if mode == ['tag-only-peaks'] else 'spill-peaks.json' if mode else 'spill-liveness.json'
(HERE / output).write_text(json.dumps(rows, indent=2) + '\n')
print(json.dumps(rows, indent=2))
