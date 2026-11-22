# Mature CMP subtraction, zero and carry arithmetic

`Arm64Compare.FlagArithmetic.subtraction` derives the actual imported AddWithCarry result x-y from its existing theorem. `zero` derives the mature zero flag from operand equality. `carry` derives the mature carry flag as one exactly when unsigned subtraction needs no borrow. The proof uses the actual65bit unsigned sum, proves its exact natural value and establishes when truncation/re-extension preserves it. No local ISA arithmetic or native proof oracle is introduced.

Component77jobs passed2.116s; three public type/axiom queries passed1.548s using only inherited logical axioms. Existing low-priority CPU16-23/nice19/j1/32GiB/default200000heartbeats/depth512/asyncfalse. Exact source/logs/timings/axioms and the failed initial source are retained in validation.json. No raised limits or bv_decide/native_decide.

Native N/V equality to the C sign/xor masks, actual C byte binding, full source/native flag/register representation and original six-call entry remain open. The separate9file Storage permission rebuild remains independent. M5/O1/O2/O4/M6 open; complete ISA families0. No runtime application or measurement.
