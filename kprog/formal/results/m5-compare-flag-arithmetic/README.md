# Mature CMP N/Z/C/V arithmetic and exact C masks

`subtraction`, `zero` and `carry` derive the imported AddWithCarry64 result x-y, Z from operand equality and C from unsigned no-borrow. `negative_mask` now proves the actual mature N flag equals the nonzero high-bit sign mask. `overflow_mask` proves the actual mature V flag equals the original XOR/AND high-bit source expression.

The V proof rewrites the actual65bit signed sum as the difference of sign-extended operands, proves it does not overflow65bits and shows native re-extension equality exactly when64bit signed subtraction does not overflow. Core kernel-checked overflow/MSB identities then produce the source XOR mask. `sign_mask` relates the high-bit mask to the real MSB; N normalizes the actual one-bit result. No independent ISA operation or native proof oracle is introduced.

Current component77jobs passed2.305s; seven public type/axiom queries passed1.362s with only inherited logical axioms. CPU16-23/nice19/j1/32GiB/default200000heartbeats/depth512/asyncfalse. Both current source attempts passed (first lacked only the new N lemma); no limit increase, bv_decide or native_decide. Earlier exact-source confirmations/failed history remain nested in validation.json, with baseline source/log snapshots.

Actual CC byte-value binding, full source/native register correspondence and fetched original six-call entry remain open. W native bridge remains open. M5/O1/O2/O4/M6 open; complete ISA families0. No runtime application or measurement.
