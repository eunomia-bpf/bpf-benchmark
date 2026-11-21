# Complete ADD source call and mature fetched step

Validation passes237 proof jobs and two public type/axiom queries.
The source contract composes the333-step
real generic Clight call/free with Native.reference_step from mature LNSym.
Decoded fields admit ADD64/SP31/no flag write/ordinary destination, all imm12
values and both immediate shifts, with genuine instruction validity, fetch
and incoming no-error evidence. No local ISA interpreter is introduced.

The existing represented SP relation derives physicalSP=rawSP+stackOrigin.
Native.pointer_update joins (rawSP+immediate)/STACK4 to the mature ADD result,
materializing the origin once. The exact native PC+4, empty new event/fault delta,
full register relation and source raw/tag/header/cache/free/caller resources
are retained. Full physical memory/ABI/origin/provider validity, other forms,
original source continuation and final return remain M5 work. Completed ISA
families0; no O1/O2/O4 recount or M6 completion. This is proof-only verification.

The checked all_behaviors contract also covers arbitrary relational traces:
every finite execution is a silent prefix of the same return, every stuck
endpoint is that return, and no infinite execution exists. No silence or
external determinism premise is added.

Batch confirmation2026-11-21: lake build KProgFormal passes301 proof jobs
in4.103s; root artifact UTC2026-11-21T16:11:16.945239+00:00.
CPUs16-23/nice19/j1/32GiB AS. Native tools/executables and runtime tests
are excluded. Actual call333, fetched-step/all-behaviors and original caller337
are recorded by the adjacent m5-add-call, m5-add-native-call and
m5-entry-add-call receipts; whole original entry-prefix join remains open.
