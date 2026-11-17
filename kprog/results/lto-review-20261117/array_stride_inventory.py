#!/usr/bin/env python3
"""Read retained lookup shapes/instructions; model equivalent integer arithmetic only."""
from collections import Counter
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
plan_path = REPO / 'corpus/results/shared-hash-regression-20261116/captures/link-ie2fmz97/link-plan.json'
blob_path = Path('/workspaces/kprog-raw/perf/20261116-host-link-replay/emission-current/114-0/image.blob')
plan = json.loads(plan_path.read_text())
shapes = [{key: row[key] for key in ('map_name','kind','elem_size','max_entries','value_offset')}
          for row in plan['lookup_maps'] if row['kind'] == 'array' and row['elem_size'] == 24]
site_counts = Counter(row['map_name'] for row in plan['lookup_sites']
                      if row['kind'] == 'array' and row['elem_size'] == 24)
blob = blob_path.read_bytes()
# Original 16-byte IMUL-imm32 / ADD-register / ADD-accumulator sequence only.
original = bytes.fromhex('4869c0180000004801f8480530010000')
positions = [offset for offset in range(len(blob)) if blob.startswith(original, offset)]
windows = []
disassembly = []
for offset in positions:
    windows.append(dict(offset=offset, original_bytes=blob[offset:offset+len(original)].hex(),
                        original_arithmetic_bytes=len(original), source_model_arithmetic_bytes=12,
                        source_model_bytes_saved=4, source_model_instructions_removed=1))
    disassembly.append(subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64',
        '--start-address=' + str(offset), '--stop-address=' + str(offset+len(original)),
        str(blob_path)], text=True))
mask = (1 << 64) - 1
illustrations = []
for key in (0,1,4095,4096,0x7fffffff,0xffffffff):
    for base in (0,0xffff888000001000,0xfffffffffffffff0):
        product = (key * 24) & mask
        current = (((product + base) & mask) + 304) & mask
        folded = (base + product + 304) & mask
        illustrations.append(dict(u32_key=key, base=hex(base), product=product,
                                  current_result=hex(current), folded_result=hex(folded),
                                  equal=current == folded))
result = dict(recorded_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
              scope='Retained Katran load facts and original native bytes, plus finite unsigned arithmetic examples. Static site counts are not dynamic frequencies. Model savings are not an emitted or installed candidate, per-call result or admission check. No machine code generated/assembled/executed.',
              plan=str(plan_path.relative_to(REPO)), blob=str(blob_path), blob_bytes=len(blob),
              shapes=shapes, static_bound_sites=dict(site_counts), original_windows=windows,
              scalar_immediate_bytes_before_after=[7,4], pointer_add_bytes_before_after=[9,8],
              arithmetic_illustrations=illustrations)
(HERE / 'array-strides.json').write_text(json.dumps(result,indent=2)+'\n')
(HERE / 'array-strides.disassembly.txt').write_text('\n'.join(disassembly))
print(len(shapes),'retained 24-byte-stride ARRAY shapes;',dict(site_counts),'static bound sites')
print(len(windows),'original arithmetic windows; four local bytes and one instruction per model window')
print(len(illustrations),'arithmetic illustrations;',sum(not row['equal'] for row in illustrations),'differences')
