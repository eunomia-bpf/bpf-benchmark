# ARM architectural fault operation bodies

Operator approval: 2026-11-08 09:36 UTC, four classes. The canonical C simulator models incoming SP alignment, pair-load destination overlap, integer transfer/writeback overlap and exclusive status overlap. Each uses the existing verifier-visible fault arm in generated B and applies to every native program.

The five-step QEMU replay uses the paired e2d3 runtime and all 34 existing native-only cases. Four positive cases execute. The other cases use the existing load-only path. Full-system QEMU operation-body replays and the executable Lean reference supply ISA-level evidence.

Rules follow the [Arm A64 instruction manual](https://documentation-service.arm.com/static/67e40f3398aa3c3b6eea6a85): CheckSPAlignment tests incoming SP before address offset/writeback; LDP constrains equal destination fields; LDR/STR and LDP/STP constrain writeback/data overlap for base fields 0..30; STXR/STLXR constrain status/data equality and status/base equality for base fields 0..30. The overlap classes have CONSTRAINED UNPREDICTABLE outcomes; the simulator routes their architecturally partial state to its fault arm. QEMU outcomes are recorded with that distinction.

Lean reference: `spAlignmentFault` at `kprog/formal/KProgFormal/Reference/AArch64.lean:526`, the addressed-memory and pair source witnesses, and the corresponding decode constraints around lines980?1038. V maintains the affected universal O1/O2 rows.

Existing29 micro programs generated and compiled with clang18/O2/BPFv4. The source dispatcher and generated direct dispatcher carry the same operation bodies. Application/compiler defaults retain their current profile.
