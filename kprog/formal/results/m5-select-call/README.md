# Original CSEL caller and actual callee entry

`Arm64ProgramEntrySelectCall` extracts the genuine seventh call immediately after CMP and its untouched `afterSelect` continuation. The actual linked symbol/function and all nine original argument expressions/casts yield op28, DST5, SRC1, SRC2=2, SRC3=255, width8, EQ0 and IMM0. Two real source steps invoke the handler; `entry_valid` binds its complete original generic frame and parameters through FunctionEntry2; two real return steps restore the original caller, locals, temporaries and continuation. Memory is arbitrary and unchanged by these caller arcs.

The exported AST distinguishes RUN_OP3's explicit signed255 from CMP's macro-supplied unsigned255U. The first source identity exposed that mismatch; exact AST inspection and a signed source literal fixed the proof at unchanged limits. This does not change any C source, runtime semantics or native model.

Exact194line source passed 250 targeted jobs in 46.586698s and four public type/axiom queries in 1.508724s, CPU17/nice0/j1/32GiB/default200000heartbeats/depth512/async=false. Only existing logical/CompCert semantic axioms. validation.json records exact source/dependency/query hashes, initial failed source and raw logs. A fresh timestamped raw directory is used, with reuse of existing result names refused.

This is caller/callee-entry infrastructure. Actual CSEL body/condition/operand/selected-tag writeback, mature native refinement and original seventh-call composition remain open. Complete ISA families remain zero; M5/M6 and O1/O2/O4 remain open. No new global/root confirmation: V's active Writeback differed from its accepted revision when checked. No runtime/loader/benchmark/gate change.

Later composition: the actual generic CSEL call, including body execution and
frame release, is recorded separately in [m5-select-generic-call](../m5-select-generic-call/README.md).
The remaining-body obligations above describe this earlier caller-entry stage.
