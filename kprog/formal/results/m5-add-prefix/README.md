# Original ADD immediate operand prefix

The two recovered source modules connect the original generic handler body to
its original tag/arithmetic tail. `body_operands` proves 152 internal transitions:
the actual 39-transition dispatcher followed by 113 operand transitions, including
the warm SP reader (71), the actual immediate selector (29), and source call,
return and sequencing edges. Both W and X widths and every 64-bit immediate are
covered, with arbitrary original environment and caller continuation.

`Operands.branch_source` and `tail_source` kernel-check the exact original ALU
branch and arithmetic successor. The reached temporary environment contains the
represented native SP as LHS and the original full-width immediate as RHS. Memory
is exactly unchanged. The existing reached register representation and warm SP
cache discharge the reader; no origin provider is called again. The actual
immediate branch skips SRC2 according to its checked Clight control flow.

Focused checking and public theorem/axiom queries are recorded in validation.json.
Original heartbeat 200000 and recursion 512 limits remain. Failed attempts and raw
logs are retained under /workspaces/kprog-raw/formal/m5-add-dispatch and
/workspaces/kprog-raw/formal/m5-add-prefix.

This is an already-entered handler prefix. Tag read, inline ADD, pointer selection,
raw SP read, write, generic frame free, original caller successor and native-step
composition remain open. No complete ISA family is added; M5, O1/O2/O4 and M6
remain open. Whole-library confirmation follows at this batch end.

Batch confirmation (2026-11-21): `lake build KProgFormal` passed all 294 jobs
in 30.436 seconds, with the root artifact at 2026-11-21T15:24:43.564922+00:00.
CPUs16-23/nice19/one worker/32GiB AS; native tools/executables excluded.
This confirms the three changed proof steps together; no complete handler
count, O1/O2/O4 recount, final default Lake build or make check is claimed.
