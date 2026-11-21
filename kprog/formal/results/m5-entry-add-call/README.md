# Original caller ADD and fetched native step

Validation passes246 proof jobs and four public type/axiom queries.
The source proof factors the exact first statement of
MovCall.afterKeep and its unchanged successor, retaining original wrapper,
allocated environment, arbitrary source temps and continuation. The actual nine
arguments/casts are checked for op3,dst2,SRC32,SRC2/SRC3=255,flags8,aux0,imm16.
It resolves the original target to the actual generic handler at block72.

The checked337-transition segment combines caller enter2, generic call333 and
caller leave2, from original afterKeep to original afterAdd. The admitted fetched
ADD64/SP31/dst2/imm16/no-flags step keeps its real decoder certificate, fetch,
no-error, PC+4, event and fault facts. Returned source resources retain exact
raw SP+16/tag4, complete registers, original observer frontier, caller frame,
generic frame free/release, canonical header and same warm SP cache.

This starts at the reached third caller segment. Joining the preceding actual
98-input/setup/MOV pair, full physical ABI/origin/provider validity, other forms,
later source control and final return remain separate M5 obligations. No complete
ISA family is added; O1/O2/O4 and M6 remain open. Proof-only verification, no
benchmark/functional tests/measurement. Raw m5-add-call retains all attempts.

Batch confirmation2026-11-21: lake build KProgFormal passes301 proof jobs
in4.103s; root artifact UTC2026-11-21T16:11:16.945239+00:00.
CPUs16-23/nice19/j1/32GiB AS. Native tools/executables and runtime tests
are excluded. Actual call333, fetched-step/all-behaviors and original caller337
are recorded by the adjacent m5-add-call, m5-add-native-call and
m5-entry-add-call receipts; whole original entry-prefix join remains open.
