# Actual MOVK call with unrestricted priority

The shared MOVK execution now takes the actual full-width uint64 immediate.
`mergeWord`, `writerTempsWord` and `operandsWord` preserve that argument and
its compiler temporary exactly. `mergeWord_low16` proves separately that only
the low 16 bits affect the selected halfword. Existing immediate16 interfaces
instantiate this path; the reader, merge, writer and free proofs are shared.

`Arm64MovKeep.LinkedWord.call` executes the complete 203-transition scalar
call in the sole fixture/handler/Numeric world. It derives the actual write,
post-free scalar word/tag0, writable Storage, complete register update at the
caller frontier, original caller frame and actual frame-release facts. It
accepts arbitrary uint64 immediates, both widths and any valid call continuation.
Scalar DST word/tag and the initial representation remain invocation inputs.

The source-cached original fixture MOVK call packs shift 16 into AUX's third
byte. Its kernel-checked source equation and pure evaluation derive this
packing. All nine arguments and C casts are evaluated, including unrestricted
uint32 priority widened to the full uint64 parameter. The source call uses
actual symbol 72 and the original void/nine-argument signature.
`keep_enter` and `keep_leave` preserve the actual saved source continuation;
`execute_keep` composes the complete 206-transition statement/call/return path
to the original source successor. It retains the scalar readbacks, full register
relation, caller frame, actual free and released permissions.

The prior MOV_IMM proof reaches precisely this call statement and retains its
word/tag0. Joining the two calls across their advancing allocation frontiers,
then relating fetched native instructions and physical ABI/provenance admission,
remains M5 work. No ISA family or whole entry refinement is claimed complete.

Focused validation and public type/axiom queries use CPU 17, nice 0, one worker,
32 GiB address space and the original 200000-heartbeat/512-depth caps. Whole
proof-library confirmation follows this source checkpoint. No executable/tool
build is performed under the current directive. Failed finite attempts stay
in `/workspaces/kprog-raw/formal/m5-entry-movk`; validation.json records final
checks and inherited logic/external-semantics axioms. M5/M6 remain open;
completed ISA-family count is zero.
