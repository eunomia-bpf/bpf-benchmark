# ARM libc, clobber and control wrapper extraction

The existing addressing extraction now roots the actual production helper
clobbers, libc memset/memcpy, JCC, W/X compare-and-branch, test-and-branch,
CMP/GT, LINK, exit and return-to bodies. Eleven roots and one raw-register
adapter bring `Arm64Addressing` to43 functions/20,619,432 bytes. The shared
branch predicate has a declaration/output facade and an actual numeric root;
`Arm64Numeric` now has21 functions/171,547 bytes. Its original native expression
and capture order remain intact. No production helper registry, opcode body,
entry policy or simulator ABI is replaced.

Named caller-saved GPR fields bind to the same existing GPR/tag cells. The
CompCert-only expression adapters call existing memory-read and numeric C
roots at the original expression sites. In particular, memcpy keeps destination
resolution before source reads; pre-reading a function argument for a generic
writer would move that observation. Existing root definitions precede these
late facades, so they retain their original C bodies. Ordinary C linking,
state-layout and effect correspondence remain M5 obligations.

Historical4a2b31f48/current-native/CompCert-adapter modes each capture28 complete
clobber frames,2,160 libc frames,5,035 control/link/return frames and the prior
4,320 instruction frames:11,543 states/25,444,240 bytes each. All bytes, callback
kinds/values/order, results and rejection prefixes agree, without masks. The
libc/clobber cases cover seven capacity/bias profiles, including1/7/9/160/200/376
bytes and a bias above32 bits. Independent expectations check forward copy
with overlap, partial/aligned provenance transfer, fresh released bytes,
caller-saved versus preserved GPRs, four flags and all32 vector cells. Tests
use defined private-arena access windows; they do not establish invalid-array
or physical fault behavior.

Control expectations check W narrowing without register writes, full64-bit
predicate kinds/bit masking, forward/backward/equal edges, noncanonical raw flag
bytes, CMP/GT signedness and flags committed before width refusal. Return
checks preserve raw LR/tag checks and reject a nonzero SP before reading the
result. The return-to root deliberately has an empty internal continuation
table; it accepts no unknown target and is not a universal program-return
binding. The native fixture separately exercises a real call/return label case.
The inherited ARM RET discrepancies are unchanged, not declared resolved.

Six new mutations fail their independent assertions: kind truncation,31-bit
bit mask, changed predicate capture order, wrong final vector cell, early
return-result read and wrong memcpy source. The common comparison recipe also
retains the previous five numeric mutations, validated in the prior step;
this turn ran the six new cases. One additional adapter-only physical-read
refusal test checks two committed byte stores, no third store and no subsequent
helper clobbers. Its process-local pointer state is checked independently,
outside the serialized private-state comparison. This is a C import refusal
prefix, not a proof of native hardware faults.

Final `make clight` and all ten Clight modules/47 Lake jobs pass. Addressing
builds in216 seconds on CPU15 with actual `-j1` and the unchanged32GiB address
space limit. Re-exports are deterministic and eight AST-root/program queries
use only propext/Classical.choice/Quot.sound. Extraction CPP is2,179,412 bytes,
not an application-scale expansion factor. The expanded BPF fixture includes
libc effects/clobbers, conditional/test/CMP branches and actual call/return.
Its11,104-byte socket section and five allocated relocations match the prior
headers exactly; current streamed and ordinary compilations also agree.
This is native fixture coverage, not whole-default bytes or runtime performance.

The final oracle review retains the original512 input slots (maximum observed
494) and arms only expected rejection calls, preventing a surprise refusal
from jumping to a stale loop target. Focused native/adapter checks pass after
that harness change, including the read-refusal prefix; the final adapter
capture remains byte-identical to the three-mode comparison. The completed
full C confirmation was not repeated for these test-only changes. Earlier
working-directory, mutation-string and temporary C-string preparation errors
remain in the raw logs; none is hidden as a successful check.

The common recipe `results/m4-arm64-execute/compare.py --output <new-raw-dir>`
streams historical headers in RAM and replaces the existing build products.
Run from `kprog/formal` on CPU15 with the32GiB limit. Full commands, captures,
negative cases and final confirmation are retained under
`/workspaces/kprog-raw/formal/m4-arm64-wrappers`.

M4 still needs the ARM helper registry and entry/program-continuation bindings,
remaining producer/storage profiles, platform correspondence and whole-default
compiled-byte coverage. M5 must then migrate all2,065 actual exported Clight
handler refinements against LNSym/x86lean and recount O1/O2/O4. M6 retirement
and whole-library `lake build` plus `make check` follow in that order.

The subsequent [typed helper step](../m4-arm64-helpers/README.md) extends the
common recipe with95 ABI checks and focused helper negatives. The43-function
counts and original captures above describe this wrapper checkpoint.
