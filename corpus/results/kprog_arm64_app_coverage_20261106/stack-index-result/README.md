# ARM stack index retains native address width

The simulator now retains all 64 bits in arena byte indexes, word indexes,
helper payload indexes and packed tag access. Bias addition uses unsigned
wrapping arithmetic. The generated C/Lean contracts and their callers match
that representation; low-width arena lemmas remain as explicit restrictions.

Existing full-system QEMU load-only controls record eight accepted invalid
addresses before the repair and eight verifier rejections afterward. No invalid
native program was executed. All 13 C-level boundary expectations match after
the repair; the fixed and dynamic positive controls return 2. These records
establish this defect's regression behavior, not simulator-wide ISA fidelity.

The two focused C oracles pass 536 and 71,667 cases. The negative and 29 micro
proof builds pass. Both generated-file checks and the 13-path whitespace
check pass. The immutable candidate's complete Lean build passes all 374 build
jobs, including the full-width index and dependent helper theorems. The overall
`make check` exits 2 afterward: the existing x86 map-lookup fixture passes an
unknown runtime map but still expects array inlining. Current map-identity
selection correctly keeps its generic helper. The exact failure and source
hashes are in `formal-check.tar.gz`; it has been reported to C/V. The prior v38
failure used the pre-repair Lean syntax and remains in the raw archive.

`provenance.json` pins the candidate and archive hashes. `sources.tar.gz`
contains only the 13 defensive repair sources; `raw-logs.tar.gz` retains the
original before/after verifier output and checks. The result does not establish
whole-application completion or hardware performance.

Validation uses `make -C kprog/formal check` on an immutable candidate export,
and `make -C kprog/arm64 micro-proofs-build` with separate build directories.
