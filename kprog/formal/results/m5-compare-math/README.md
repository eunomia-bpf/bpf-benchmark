# Original CMP SUB arithmetic prefix

`Arm64Compare.Math.execute` follows the actual CMP flag loop, constant SUB-family switch and nested source loop: selection5 + W/X width-mask/sign preparation30 + masked lhs/rhs/subtraction9 =44 silent steps. Both width branches preserve every source cast, all eleven temporary writes, complete memory, locals and original pending continuation. `loop_source`/`sub_source` are kernel-checked original AST identities. `values` derives the five operands used by the pending original Z/N/C/V stores from that exact temporary map.

The proof starts with captured source operands and effective width4/8, matching the preceding operand-prefix frontier. It derives the masked subtraction; no resulting flag/native state or extra readback is assumed. The original four pointer loads and byte stores remain unexecuted at the endpoint.

Component240jobs passed7.734s; four public type/axiom queries passed1.741s. CPU17/nice0/j1/32GiB, default200000 heartbeats/depth512, asyncfalse. Only inherited logical axioms and CompCert external/assembly semantics occur. Exact hashes, raw logs, failed source attempts and timings are retained in validation.json. A depth512 simplification failure was resolved by evaluating the actual arithmetic expressions and explicit temporary observations separately, without increasing proof limits.

Four stores/full register and memory frame/mature native sixth-call and original six-call composition remain next. Whole-library/root batch awaits that meaningful CMP advance and latest stable V handoff. M5/O1/O2/O4/M6 remain open; complete ISA families0. No runtime application or measurement.
