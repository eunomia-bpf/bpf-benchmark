# Translation validation increments, 2026-11-07 UTC

`checked-store-spills-final.log` records exit0 for private-spills-check and the
complete checked-first-block-check with its dependencies. The canonical store
transition now supplies complete native/BPF state shapes, actual execution
witnesses, equal ordered events/fault and corresponding PC for every first
fault and success. It runs on two actual memories with equal permissions;
the proof's private spilled memory is never replaced with native memory.
The previous equal-memory observation theorem is derived as its Eq instance.

`PrivateSpills.store_agrees` proves identical canonical writes preserve every
outside-frame byte and initialization bit, including wraparound.
`SimpleCheckedBlocks.store_with_spills` instantiates this relation and carries
both transitions to the exact accepted expanded verifier artifact. All short
writes and faults are retained by the trace projection. Its axioms are
propext/Classical.choice/Lean.ofReduceBool/Quot.sound, without sorryAx;
store_agrees uses only propext. Exact composing sources and generated program
arrays/checked snapshot inputs are in checked-store-spills-inputs.tar.gz.

This is a block composition result. Original-entry store/return paths and
whole-invocation/CPU-profile/binding composition still remain before claiming
the first whole-program certificate. No runtime, ISA, benchmark or paper changed.
