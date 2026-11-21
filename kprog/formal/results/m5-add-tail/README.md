# Original ADD tag and eager candidate

The actual handler tail calls program_tag for selector SP32, retains STACK4,
and executes its inline ALU64 switch ADD case. Tail.evaluate proves all43
internal transitions to the original pointer/scalar selection statement, for
arbitrary lhs/rhs, pointed entry, memory, environment and caller continuation.
It preserves the complete memory and the exact reached temporary environment,
including the eager candidate lhs+rhs. Neither the pointer branch nor a standalone
Numeric result call replaces the original candidate computation.

Tail.source checks the exact structural factoring of the unchanged handler
fragment already connected to the full body by Operands.tail_source. The real
tag symbol/body at block65 and its fifteen-transition SP call are reused. The
source argument still has the actual pointer ABI; no provider call is added.

Validation and public types/axioms are in validation.json and Query.lean. Raw
attempts are retained in /workspaces/kprog-raw/formal/m5-add-tail. Original
heartbeat200000/depth512/asyncfalse limits remain. Complete pointer selection,
write/free, full source/native composition and M5/O1/O2/O4/M6 remain open;
completed ISA families0. Whole-library confirmation follows at batch end.

Batch confirmation2026-11-21: lake build KProgFormal passes297 jobs in4.948s.
Root artifact UTC2026-11-21T15:40:27.922020+00:00; CPUs16-23/nice19/j1/32GiB AS.
Native tools/executables excluded. Actual axiom names are parsed directly from
the retained queries; the initial empty-list extraction is corrected forward.
