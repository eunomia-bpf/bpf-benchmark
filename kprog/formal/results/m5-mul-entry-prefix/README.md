# Original five-call native prefix

`Arm64ProgramEntryMulPrefixNative.entry_corresponds` executes the original 98 input calls, setup and MOV/MOVK/ADD-immediate/ADD-register/MUL prefix. It preserves the exact provider traces and supplied stack provider, actual reached heaps and all predecessor frame-release contracts. Original PC+16 fetch/error admission is transported through the actual mature predecessors. The fifth real caller executes in 441 internal steps to the original `afterMul` successor.

The two scalar operands are derived: D1 survives the fourth writer through Kept3 and D3 is the actual fourth ADD result. The D4 result is mergeWord multiplied by mergeWord + ((original SP + 16) + stack origin), with scalar tag0. Full native/register representation at the original frontier, all predecessor events/faults, caller frame, real final freeList and revoked local permissions, cache, header and allocation bound are retained. No extra provider replay, reached readback/native-result admission or local ISA evaluator.

Focused component and one public type/axiom query passed with the original caps and inherited logical/CompCert semantic axioms only. Exact hash/logs/timings are in validation.json. Whole/root batch remains pending. Complete ISA families: 0; M5/M6 open. No runtime application or measurement.
