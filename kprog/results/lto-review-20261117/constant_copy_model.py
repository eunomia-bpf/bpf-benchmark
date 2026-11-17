#!/usr/bin/env python3
"""Count scalar-copy schedules; emit no candidate instruction bytes."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
retained = json.loads((here / 'remainder-paths.json').read_text())

def fixed_words(words):
    # MOV RAX,[RSI+off]; TEST R11D,R11D; JE fault; MOV [RDI+off],RAX.
    # Address operands are three bytes at zero, four with disp8, seven
    # with disp32; TEST is three bytes and the existing near JE six.
    return dict(instructions=words * 4, conditional_branches=words,
                bytes=sum(2 * (3 if i == 0 else 4 if i * 8 <= 127 else 7) + 3 + 6
                          for i in range(words)))

paths = []
for length in (8, 16, 144):
    words = length // 8
    # Existing 0dcf source: initial size compare/branch, nine-instruction
    # qword loop, then the new zero-remainder TEST/JE.
    paths.append(dict(size=length,
                      empty_remainder_source_model=dict(
                          instructions=2 + 9 * words + 2,
                          conditional_branches=1 + 2 * words + 1),
                      fully_unrolled_copy_only=fixed_words(words)))
block = fixed_words(4)
tail = fixed_words(2)
hybrid = dict(
    size=144, bulk_iterations=4, bulk_bytes=32, tail_bytes=16,
    source_access_order=[i * 8 for i in range(18)],
    # MOV ECX,4; four iterations of four protected loads/stores,
    # ADD RDI,32; ADD RSI,32; DEC ECX; JNE loop; two protected tail words.
    instructions=1 + 4 * (block['instructions'] + 4) + tail['instructions'],
    conditional_branches=4 * (block['conditional_branches'] + 1) + tail['conditional_branches'],
    static_copy_only_bytes=5 + block['bytes'] + (4 + 4 + 2 + 6) + tail['bytes'],
    bulk_word_load_instruction_lengths=[3, 4, 4, 4],
    tail_word_load_instruction_lengths=[3, 4])
current_copy_bytes = len(bytes.fromhex(retained['captured_new_copy_instruction_bytes'])) + 8
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Static successful-copy scalar instruction/encoding arithmetic only; no assembler, optimizer, emitted candidate or execution. Excludes policy, frame, SMAP, copy-setup, success-result, cleanup and zeroing. Fault branches retain current six-byte form; actual installed size/cycles unmeasured.',
    base_receipt='remainder-paths.json',
    generic_copy_region_bytes_source_model=current_copy_bytes,
    source_model_change='0dcf97880 adds two-byte TEST ECX,ECX and six-byte JE before existing remainder; zero remainder skips every old tail test.',
    constant_paths=paths, counted_144_copy_only=hybrid,
    fault_contract='One protected qword load, R11 status test and fault branch before its store. Keep original load order, no overreads, full-destination zeroing/error on first failed load, and actual per-site instruction lengths. No checks are coalesced across loads.')
(here / 'constant-copy-model.json').write_text(json.dumps(result, indent=2) + '\n')
print('generic copy-region source-model bytes:',current_copy_bytes)
print('constant models:',paths)
print('144-byte counted model:', {k:hybrid[k] for k in
      ('instructions','conditional_branches','static_copy_only_bytes')})
