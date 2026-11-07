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

Original-entry accepted and faulted store paths
---------------------------------------------

`checked-entry-stores-return-final.log` records exit0 for the exact source
`SimpleCheckedBlocks.lean`, after rebuilding its strengthened store dependency.
`passed_guards_store` composes the original entry, both passed guards and all
actual stores up to the first fault or return successor. Exact state-edge
identities, complete architectural shapes, actual spilled memory, exact ordered
writes/fault and corresponding PCs remain explicit. No writable-memory premise
was added. The canonical transition additionally proves no fault iff the BPF
store path reaches PC27.

`passed_guards_complete` appends the actual native trampoline and expanded
BPF JA/EXIT precisely on the no-fault branch, returning2 at native PC84 and
halted BPF PC29. A first fault appends no return and retains both exact
transition witnesses and full architectural shapes. Both original entry states,
guest-memory relation and exact projected read/write/fault trace are retained.
The two previously published rejection paths plus this result cover all guard
outcomes under the stated mapped-context/private-frame entry conditions.

Axioms remain propext/Classical.choice/Lean.ofReduceBool/Quot.sound, without
sorryAx. The initial statement elaboration error (untyped existential witnesses),
its corrected check, and frozen final sources/program inputs are retained in
checked-entry-stores-return-inputs.tar.gz. Whole-invocation safety composition,
CPU-profile and actual emitted-artifact binding are still explicit remaining
obligations; this does not declare a whole-program certificate or validate other
programs. No runtime/ISA/benchmark/paper changed.
