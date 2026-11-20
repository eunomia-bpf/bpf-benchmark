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

Focused checks pass: shared scalar call 189 jobs, actual-world call 200 jobs,
actual fixture edge 228 jobs and 12 public type/axiom queries. They use CPU 17,
nice 0, one worker, 32 GiB address space and the original 200000-heartbeat/512-depth
caps. The entire `lake build KProgFormal` proof library/root passes 277 jobs
on CPUs 16–23, nice 19, one worker and 32 GiB address space. Host Lake runs
without the timing lock under the coordinator notice of 2026-11-19T18:18:59Z;
the initial unstarted shared-lock waiter was ended before the sole full run.
No executable/tool build is performed under the current directive. Failed finite attempts stay
in `/workspaces/kprog-raw/formal/m5-entry-movk`; validation.json records final
checks and inherited logic/external-semantics axioms. M5/M6 remain open;
completed ISA-family count is zero.
