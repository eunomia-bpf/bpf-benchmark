# Actual standalone LSL0 modifier loop

`Arm64Modified.Modifier.modify_source` is the kernel-checked identity for the actual standalone loop. `execute_lsl_zero` follows its value/kind/shift/amount initialization18steps, original switch and case1 in20steps, then real result assignment and loop exit3steps:41silent steps, for W4/X8/mod1/shift0. It retains all three original mask assignments, exact ten source writes and the same whole heap/e/original k. W uses0xffffffff and X uses allones64; `result_wide` proves the X identity. These are source C expression results, not a replacement native instruction model.

Component236jobs and three public type/axiom queries passed CPU17/j1/32GiB/default proof caps/inherited logical+CompCert semantics only. Exact source hash/logs/timings/axioms and first failed proof diagnostics are in validation.json. Explicit PTree rewrites and explicit W/X branch parameters replace the failed automation; budgets/scope/step counts are unchanged.

Actual helper return and composition with real entry/read remain next, then original CMP flag_rhs/NZCV/native six-call entry. No whole instruction/family claim. M5/O1/O2/O4/M6 open/families0; no runtime application or measurement.
