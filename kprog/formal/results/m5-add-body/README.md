# Whole original ADD immediate body

Body.execute composes152 original dispatcher/operand transitions,43 actual tag
and eager inline ADD transitions,132 selected pointer/read/write/return
transitions, and four actual inner/outer loop exits. The331-transition run starts
at the unchanged generic handler.fn_body and returns Sskip at its original
continuation with exact reached temporary environment.

All31 ordinary destinations and arbitrary64-bit immediate/source SP values are
covered at width8, opcode3, AUX0 and SRC32. The same reached Storage, complete
register relation and warm cache support every fragment. Temp projections are
derived from kernel-checked exact expansions, not supplied as postconditions.
Only actual derived pointer stores change memory; Result, writable Storage,
raw/tag readbacks, complete register update and canonical cache Kept are retained.
No origin provider is called again or successful-store assumption introduced.

This begins after function allocation. The actual nine-parameter call entry,
generic frame free, original source successor and fetched-native composition
are subsequent work. Completed ISA families0; M5/O1/O2/O4/M6 remain open.
Proof checking uses original200000-heartbeat/512-depth/asyncfalse limits on
CPU17/j1/32GiB. The operator's2026-11-21 verify-only directive is respected:
no benchmark, functional test or measurement is run. Raw proofs and finite
failed attempts are retained under /workspaces/kprog-raw/formal/m5-add-call.

Batch confirmation2026-11-21: lake build KProgFormal passes301 proof jobs
in4.103s; root artifact UTC2026-11-21T16:11:16.945239+00:00.
CPUs16-23/nice19/j1/32GiB AS. Native tools/executables and runtime tests
are excluded. Actual call333, fetched-step/all-behaviors and original caller337
are recorded by the adjacent m5-add-call, m5-add-native-call and
m5-entry-add-call receipts; whole original entry-prefix join remains open.
