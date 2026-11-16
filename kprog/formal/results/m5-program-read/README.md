# Actual ARM combined-reader prefix

`Arm64RegisterReads.gpr_read_prefix` proves 55 actual internal Clight
transitions of the exported `kprog_arm64_program_read` for every GPR index
0–30. It follows the entry's individual raw and tag pointer tables and reaches
the actual inlined materializer with their loaded values. Complete memory is
unchanged. The premise uses the actual imported loads and ulong cast; it does
not assume a dense register bank or invent native pointer bits.

The ordinary constructor equations shared with `Arm64OriginCache` now live in
`StepEquations`; the actual interpreter and existing cache contracts are
unchanged. Extraction of the stages is checked from the generated function
body by the kernel.

The focused build passes 143 jobs at default limits. The public axiom query
reports only `propext`, `Classical.choice` and `Quot.sound`. Raw attempts are retained
under `/workspaces/kprog-raw/formal/m5-program-read`. The full combined call,
its warm/cold cache and invocation-origin binding remain M5. This is a prefix
law and adds zero complete ISA-handler refinements.

Reproduce: `lake build KProgFormal.ClightRefinement.Arm64RegisterReads
KProgFormal.ClightRefinement.Arm64OriginCache`, then
`LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-read/Query.lean` from `kprog/formal`.
