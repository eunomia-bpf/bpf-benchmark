# Actual caller first width-helper prefix

The original label0 outer loop calls arm64_width_effective with constant8, casts and stores the return in its real width temporary, then reaches the actual inner loop150/151. Actual global lookup resolves the internal helper; the same caller allocation cannot shadow its name.

The two exports use different compiler temporary identifiers. This proof executes the actual CallerUnit helper body under imported CompCert rules, rather than asserting equality with the old Arm64Program function. Six prefix steps, six actual helper steps and four return/set steps total16 internal steps, with the entire memory unchanged.

Seven public queries check source, call_source, callee_lookup, unshadowed, call_ready, helper and execute. This proves only the actual width prefix; complete instruction/native correspondence and whole-entry extension remain separate. All actual logs are retained; CPU17/j1/nice0/32GiB and Lean caps remain fixed, outside timingSH under coordinator2026-11-28T05:43Z during x86 rotate, with formal-full-check exclusion.

The first direct check diagnosed two implicit allocation parameters and opaque uchar/uint cast goals. Stage2 supplies m explicitly and unfolds those actual types; statements, counts and resource limits are unchanged. Both actual direct logs are retained.

The second check reduced the remaining call goals to zero pointer-offset equality and the actual helper signature. Stage3 unfolds Ptrofs equality/zero and the actual helper definition at that call. Both failures and the successful direct log are retained; no limits or step counts change.
