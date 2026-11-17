#!/usr/bin/env python3
"""Record current range instructions and review a u64 predicate identity."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
capture = Path('/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json')
fixture = json.loads(capture.read_text())
rows = fixture['instructions']
first = next(i for i, row in enumerate(rows) if row[1:] == ['mov', 'rax,rdx'])
current = rows[first:first + 6]
start, end = current[0][0], rows[first + 6][0]
mask = (1 << 64) - 1
limits = [(1 << 47) - 4096, (1 << 56) - 4096]
sizes = [0, 1, 2, 4, 8, 16, 67, 71, 144, 200, 256, 312, 368, 668,
         4096, (1 << 32) - 1]
vectors = []
for limit in limits:
    for size in sizes:
        sources = {0, 1, limit - size, limit - size + 1, limit, limit + 1,
                   1 << 63, mask, mask - size, mask - size + 1}
        if limit > size:
            sources.add(limit - size - 1)
        for source in sorted(x for x in sources if 0 <= x <= mask):
            total = source + size
            original = total <= mask and (total & mask) <= limit
            rewritten = source <= ((limit - size) & mask)
            vectors.append(dict(limit=limit, u32_size=size, source=source,
                                original_accepts=original, rewritten_accepts=rewritten))
outside = dict(limit=0, size=1, source=0, original_accepts=False,
               rewritten_accepts=True,
               reason='Without limit >= size, subtracting the size underflows.')
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Arithmetic/source review only. Uses target-source task_size_max alternatives as model limits, not values measured from a guest. No candidate instructions emitted/assembled/executed; no runtime check or load refusal added.',
    current_fixture=dict(capture=str(capture), range_start=start, range_end=end,
                         range_bytes=end-start, instructions=current,
                         conditional_branches=sum(row[1].startswith('j') for row in current)),
    hypothesis='0 <= u32_size <= limit < 2**64; current helper zero-extends size through R13D.',
    identity='not-carry(source + size) and source + size <= limit iff source <= limit - size',
    modeled_limits=limits, boundary_vector_count=len(vectors),
    agreeing_vectors=sum(v['original_accepts'] == v['rewritten_accepts'] for v in vectors),
    boundary_vectors=vectors, outside_hypothesis_example=outside,
    proposed_shape=['MOVABS R11, &USER_PTR_MAX', 'MOV RAX, [R11]',
                    'SUB RAX, R13', 'CMP RDX, RAX', 'JA existing_denied'],
    proposed_encoding_arithmetic=dict(instructions=5, conditional_branches=1,
                                      bytes_with_existing_rel32_branch=25))
(here / 'user-range.json').write_text(json.dumps(result, indent=2) + '\n')
print('retained range:',end-start,'bytes;',len(current),'instructions;',
      result['current_fixture']['conditional_branches'],'branches')
print('arithmetic agreement:',result['agreeing_vectors'],'/',len(vectors))
