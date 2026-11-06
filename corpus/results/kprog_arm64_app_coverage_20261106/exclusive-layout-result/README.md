# Exact exclusive-store environment layout

Kernel-mode ARM native-link now accepts --output-environment-layout PATH and
emits version1 sites with source_pc, final native offset, width(4/8) and release.
The source PC is the byte PC in the pre-kernel proof ELF; helper expansion is
included in the final offset. Each site is checked against the actual final
STXR/STLXR word; source PCs are unique, aligned and fit the marker payload.
No native instruction or memory behavior changes. Proof mode and x86 input
reject this ARM kernel sideband; foreign input leaves no partial output.

All75 Rust tests and both release builds pass. Four actual assembled W/X,
STXR/STLXR cases retain exact opcodes while a preceding helper expands the
sourcePC16 store to final offset20. Serialized fields are checked. The first
CLI run used an incorrect --helper spelling; its failure remains. The corrected
real link-plan runs and foreign/proof-mode negatives pass.

Replay command: `make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile exclusive-layout-check PHASE=NEW_NAME`.
The archive includes source/native/proof/blob/plan/layout inputs and every CLI
outcome. This supplies the exact table for T's bound per-site witness descriptor;
it does not claim the exclusive choice marker, memory ordering/atomicity or
exclusive negative-suite repair is already implemented.
