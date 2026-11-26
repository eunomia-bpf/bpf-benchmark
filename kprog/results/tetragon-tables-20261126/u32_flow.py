"""Measure cross-block opportunities using the existing scalar-width rules.

Synthetic moves/stores query the existing local abstract-width routine only;
they are never emitted to B. No native ISA value model or runtime check.
"""
from collections import deque
import json
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
from whole_word_spills import local_u32_stores, machine_blocks, remove_dead_frame_addresses

revision = sys.argv[1] if len(sys.argv) > 1 else 'd2bda6f56'
output_prefix = sys.argv[2] if len(sys.argv) > 2 else 'u32-flow'
source = HERE.relative_to(ROOT) / 'request-39/trusted_x86.bpf.before.mir'
text = subprocess.check_output(['git', 'show', revision + ':' + str(source)], cwd=ROOT, text=True)
document = next(d for d in text.split('\n---\n') if 'body:             |' in d)
document, _ = remove_dead_frame_addresses(document)
head, body = document.split('body:             |', 1)
slots = {int(i): int(size) for i, size in re.findall(r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', head)}
blocks = machine_blocks(body)
parents = {n: set() for n in blocks}
for n, block in blocks.items():
    for child in block['successors']:
        parents[child].add(n)
sentinel = max(slots) + 1
full_store = re.compile(r'\s*STD (?:killed )?\$r\d+, %stack\.(\d+), 0(?:, debug-location !\d+)?$')
full_load = re.compile(r'\s*(?:dead )?\$r(\d+) = LDD %stack\.(\d+), 0(?:, debug-location !\d+)?$')
references = {slot: [] for slot in slots}
for line in body.splitlines():
    for slot in set(map(int, re.findall(r'%stack\.(\d+)', line))) & slots.keys():
        references[slot].append(line)
direct = re.compile(r'\s*(?:(?:STD|STW32) (?:killed )?\$[rw]\d+, |(?:dead )?\$[rw]\d+ = (?:LDD|LDW32) )%stack\.\d+, 0(?:, debug-location !\d+)?$')
eligible = {slot for slot, lines in references.items() if lines and all(direct.fullmatch(line) for line in lines)}
baseline = local_u32_stores(body) & eligible
known_slots = baseline | {i for i, size in slots.items() if size == 4 and i in eligible}
rounds = []
while True:
    outputs = {n: set(range(10)) for n in blocks}
    queue, queued = deque(blocks), set(blocks)
    store_results = {}
    while queue:
        n = queue.popleft(); queued.remove(n)
        incoming = set.intersection(*(outputs[p] for p in parents[n])) if parents[n] else set()
        if n == next(iter(blocks)):
            incoming = set()
        lines = [f'$w{r} = MOV_ri_32 0' for r in sorted(incoming)]
        written = set()
        for line in blocks[n]['lines']:
            lines.append(line)
            store = full_store.fullmatch(line)
            if store:
                written.add(int(store[1]))
            load = full_load.fullmatch(line)
            if load and int(load[2]) in known_slots:
                lines.append(f'$w{load[1]} = MOV_ri_32 0')
        lines.extend(f'STD $r{r}, %stack.{sentinel+r}, 0' for r in range(10))
        proven = local_u32_stores('\n'.join(lines))
        store_results[n] = {slot: slot in proven for slot in written}
        outgoing = {r for r in range(10) if sentinel+r in proven}
        if outgoing != outputs[n]:
            outputs[n] = outgoing
            for child in set(blocks[n]['successors']) - queued:
                queue.append(child); queued.add(child)
    stores = {}
    for result in store_results.values():
        for slot, scalar in result.items():
            stores[slot] = stores.get(slot, True) and scalar
    discovered = ({slot for slot, scalar in stores.items() if scalar} & eligible) - known_slots
    rounds.append(dict(known_slots=len(known_slots), discovered=sorted(discovered)))
    if not discovered:
        break
    known_slots.update(discovered)
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=revision, source=str(source), blocks=len(blocks), rounds=rounds,
              local_only=sorted(baseline), cross_block_additions=sorted(known_slots-baseline-{i for i,s in slots.items() if s == 4}),
              scope='Read-only must-width opportunity census, reuses existing local transfer rules and direct nonescaping spill eligibility. No storage rewrite, emitted B, accepted frame or performance gain.')
(HERE / (output_prefix + '.json')).write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
