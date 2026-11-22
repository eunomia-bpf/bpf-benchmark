# Original CMP scalar operand prefix

`Arm64Compare.Prefix.rhs_scalar` derives all real pointer/table/slot/value/tag loads from existing reached source storage and the typed scalar word/tag0 cells. Source field addresses0/8 are kernel-checked; no returned helper value or new native/readback relation is assumed.

`execute` follows actual DST LHS80 + actual modified SRC RHS/caller selection138:218silent steps from the original CMP branch to its untouched original NZCV loop. Both W/X paths retain the same complete memory/e/original k and exact five source temp writes. `values` derives the captured LHS and actual width-masked RHS from that exact map. Opcode/AUX/width/source conditions after the LHS are derived through temp frames.

Component239jobs and three public type/axiom queries passed CPU17/j1/32GiB/default proof limits/inherited logical+CompCert semantics only. Exact source hash/logs/timings/axioms are in validation.json. Actual NZCV stores/full register-frame representation and mature native six-call entry remain next. No whole instruction/family claim; M5/O1/O2/O4/M6 open/families0. No runtime application or measurement.
