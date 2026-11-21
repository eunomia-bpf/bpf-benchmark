# Actual fourth ADD-register native step

Arm64AddRegisterNative checks the mature LNSym ADD X3,X1,X2,LSL0 body, its fetched/decoded checked wrapper, and the Reference step with PC+4, empty new events/fault and preserved histories. Both operand words follow from the same existing register representation and actual D1 scalar0 / D2 STACK4 cell loads: lhs and raw+origins.stack. No separate native-address or result premise is added.

The component build passes253 jobs2.045s; all four public type/axiom queries pass1.731s with only propext, Classical.choice and Quot.sound. Exact source hash and retained logs are in validation.json. Zero shift is proved at the original shift_reg boundary before dependent-width unfolding. No ISA/source-model change, admission, new axiom, native oracle or proof-limit increase. Actual source-call/native composition, original-entry bridge and whole-library confirmation remain next. M5/O1/O2/O4/M6 open; complete ISA families0. No application/runtime tests/measurement.

The completed call/native batch is now confirmed through the whole library and root:319 jobs1904.522s, eight public type/axiom queries2.158s, exact source snapshot unchanged and inherited axioms only. Earlier pending whole-library statements above describe the component checkpoint. Original-entry composition and universal M5/O1/O2/O4/M6 remain open; complete ISA families0.
