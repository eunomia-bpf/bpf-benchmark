#!/usr/bin/env python3
"""Count existing source bytes and describe a local cold-tail merge, without emitting code."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
source = REPO / 'kprog/x86/native_lab/native_link/src/x86_probe_read.rs'
text = source.read_text()
body = text.split('fn zero_fill(', 1)[1].split('/// copy_from_user_nofault', 1)[0]
literal_lengths = [len(array.split(',')) for array in
                   re.findall(r'extend_from_slice\(&\[([^]]+)\]\)', body)]
branch_count = body.count('append_x86_jcc_rel32(')
# The two source call sites both pass MOV RDI,R8; MOV ECX,R9D (six bytes).
# kernel_routine is used for scalar and string forms; three emitted copies are possible.
saved_bytes = 6
zero_bytes = sum(literal_lengths) + branch_count * 6 + saved_bytes
comparisons = []
for copies in (2, 3):
    before = copies * (zero_bytes + 1)  # existing per-leaf body and RET
    after = copies * (5 + 1) + zero_bytes + 1  # per-leaf error JMP/local success RET, common body/RET
    comparisons.append(dict(emitted_copies=copies, current_local_bytes=before,
                            standalone_shared_tail_local_bytes=after,
                            local_bytes_saved=before-after,
                            successful_path_added_instructions=0,
                            zeroing_path_added_direct_jumps=1))
result = dict(recorded_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
              scope='Existing source-byte count and arithmetic layout proposal for two or three co-emitted read leaves. No machine code generated, patched, assembled or executed; no installed-size or performance measurement, runtime check, cross-program pool or module change.',
              source=str(source.relative_to(REPO)), source_commit='d6b4d335e',
              zero_fill_literal_array_lengths=literal_lengths,
              saved_destination_and_original_count_bytes=saved_bytes,
              near_conditional_branches=branch_count, near_conditional_branch_bytes=6,
              zero_fill_bytes_excluding_ret=zero_bytes, comparisons=comparisons,
              shared_tail_inputs=['RAX=signed helper error', 'R8=original destination', 'R9D=original size'],
              predecessor_obligations=['Policy denial bypasses pagefault enable and SMAP cleanup.',
                  'Copy faults perform the existing domain-specific cleanup before reaching zeroing.',
                  'Scalar success and nonnegative string success keep their existing local return.',
                  'Common tail leaves RAX unchanged and returns to the original helper caller.',
                  'The shared range and existing source-load recovery metadata remain represented.'])
(HERE / 'zero-tail.json').write_text(json.dumps(result,indent=2)+'\n')
print('existing zero_fill:', zero_bytes, 'bytes before RET')
for row in comparisons:
    print(row['emitted_copies'], 'copies:', row['local_bytes_saved'], 'local bytes saved in the source model')
