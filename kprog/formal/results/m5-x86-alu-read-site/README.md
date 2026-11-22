# Operand-read selection checkpoint

Current canonical source prepares the ten-transition path through the actual
XOR shortcut gates to the original operand-read sequence, for every other
operation. It keeps the complete memory and exact temporary/continuation maps.
Its structural source identity is the original ALU_REG body.

The ten-step subgoal completed within the earlier larger13-step callsite attempt.
The remaining actual-call suffix reached the original recursion limit in that
attempt. The source now factors out the completed control prefix. Its standalone
focused confirmation is queued because the performance run holds locks/timing
exclusively. Treat this as prepared source, with current coverage unchanged.

Raw diagnostics site1..site8, the unlaunched site9 and timing-deferral.json stay
at `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`. Original proof caps stay.
Next: run this same module's focused check when the shared timing lock is
available; then derive the actual first reader call in three additional steps,
its actual callee execution, second read and surrounding handler composition.
Root integration follows the focused source result. Full make-check retains the
architectural-fault failure recorded in [the batch receipt](../m5-batch-20261122/README.md).

The next source-only increment separates the reader expression, four argument
evaluations and unsigned byte-to-long casts from the actual `Step.call`.
`lhs_source` identifies the original call and ABI; `lhs_call` proposes its one
relational transition; `first_read` includes the two original sequence steps;
`to_first_read` composes the ten XOR-gate steps with those three transitions.
`resume_lhs` proposes the actual four-step return and LHS assignment for every
raw returned value. `from_call` proposes the full fifty-transition path from the
original eight handler arguments, deriving reader arguments and helper scope
through the actual allocated environment. It retains the allocated heap.

These statements are **unverified drafts**. At 2026-11-22T12:49Z the performance
run still held the timing lock exclusively, so no Lean/Lake job was launched for
this increment. [Query.lean](Query.lean) prepares eight scoped type/axiom queries
through a direct module import; it has not run. There is no new root import or
accepted coverage. The accepted x86 entry frontier stays thirty-seven transitions.
Original proof budgets (200000 heartbeats, recursion512), one worker and32GiB
remain unchanged. The source factors existing relational transitions rather than
increasing those budgets.

When the shared timing lock becomes available, first run the existing focused
build from this directory's formal package:

```sh
lake build KProgFormal.ClightRefinement.X86AluReadSite
lake env lean -j1 results/m5-x86-alu-read-site/Query.lean
```

Run both inside the shared timing lock with the recorded resource limits, retain
fresh logs below the existing raw directory, and fix any diagnostics before root
integration. Actual reader-body execution, the RHS call and complete handler/
dispatcher composition remain open. The fifty-transition draft reaches the
reader's call state; it does not establish that reader's result.
