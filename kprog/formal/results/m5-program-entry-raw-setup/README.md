# Actual RAW/tag/SP/context initialization

The actual post-vector segment contains 24 stack-tag clears, one signed 64-bit
SP-zero assignment and five context/tag assignments. Each complete segment and
its real successor is checked against the production AST. The last successor
is proved equal to `Arm64ProgramEntryAssignments.beforeHeader`, the boundary
used by the existing header/loop proof.

The stack-tag store and list induction now take the function, local environment,
bindings and successor. The original writable range, alignment, store,
readback and frame construction remain shared. The SP-zero store likewise uses
its original witness with actual function/environment/successor/binding. The
actual instance uses the real signed `tlong` annotation.

The context helpers now take the actual parameter temporary and pointee type.
The source parameter is `void*`; the actual parameter is `__sk_buff*`. The
existing `ValueRep` obligation excludes unsupported values, and the imported
pointer-cast semantics derive both the typed input cast and the subsequent
`void*` store cast. The named GPR union and pointer-member offset are checked
in the actual composite environment. The complete environments need not agree.
The original five scalar/union store witnesses and list induction are shared;
the existing source APIs retain their signatures.

`initialized` executes the actual 30 assignments silently in 90 internal
transitions. It derives all 24 zero tag bytes, SP zero, helper context and ABI
base equal to the original context, x0's pointer payload, x30 tag 10 and x0 tag
1, with source/actual bindings and caller/access/frontier frames. Temporaries
remain unchanged throughout this segment.

`entry_initialized` composes the preceding actual 98-provider traversal with
this silent suffix. The old x0 scalar payload/tag are replaced by the actual
context stores. x30's zero payload survives and its tag becomes 10; the other
GPR words/tags, table targets, flags/LR, all 64 vector words, caches and original
context temporary remain readable in the same reached memory. Provider
contracts and the context `ValueRep` are explicit invocation obligations.
Native/provider/original-context and all-outcome admission remain open.

The existing 638-transition header/loop suffix is the next composition step.
The return-type bridge, ISA refinement and O1/O2/O4 recount remain M5 work.
Completed ISA-family count is zero; M6 follows M5.

Public queries are in `Query.lean`; commands, exits, repaired attempts and final
source hashes are in `validation.json`. Raw data remains under
`/workspaces/kprog-raw/formal/m5-program-entry-raw-setup`. Checks use CPU17,
one worker, 32 GiB address space and unchanged 200000-heartbeat/512-recursion
caps with `Elab.async false`; controls run on CPU16. Host checks follow the
2026-11-19 18:18:59 coordination rule without the guest timing lock. This step
changes formal proofs, receipts and its todo line. Fresh final Lake and
`make check` remain required when M1–M6 close.

Shared context/stack helpers passed 155 jobs. The final focused build passed
193 jobs, all 20 public type/axiom queries passed, and one full Lake build passed
356 jobs. Repaired binding, outer-cast, predicate-transparency and conditional
simplification attempts remain in the raw logs and receipt. Proof limits stay
unchanged. The full build was changed to nice19 on CPU17 after reading the
2026-11-20 00:22:55 batch-priority notice; the exact adjustment is recorded.
Pure source/layout/binding facts use standard logic; execution retains imported
Step2 external and assembly semantic models. No new axiom was added.
