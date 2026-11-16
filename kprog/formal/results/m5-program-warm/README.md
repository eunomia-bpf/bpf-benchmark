# Actual combined GPR reader with warm origin cells

`Arm64RegisterReads.gpr_read_warm` follows the actual exported Program reader
through its borrowed STACK or RETURN cache. The entry holds separate pointers
to the validity and base cells. A nonzero validity byte takes the warm path;
the complete call returns the wrapped 64-bit payload plus the loaded base in
91 STACK or 92 RETURN internal transitions. The entire Clight memory remains
unchanged. No provider call or outcome premise is used, and the read-only path
requires no additional cache alias exclusion.

`gpr_read_materializes` composes these paths with the existing 73-transition
non-relative path. It covers all 31 GPR indices and all 256 tags, including
represented pointers for non-relative tags. Relative payloads being scalar
and the selected cache containing its invocation origin are explicit producer
conditions. Other tags require no cache condition. The result represents the
existing M3 materialized native bits. `gpr_read_all_tags_return_corresponds`
extends this result to every proposed relational return at `Kstop`, with an
empty trace and unchanged complete memory.

The paths use the generated function's checked stages and imported Clight
loads, expression evaluation and transitions. They do not establish producer
initialization, compact mappings, physical PC/label origins, native-memory
permissions or a complete ISA-handler refinement. Cold Program cache paths,
SP and general compiled control remain M5; the complete ISA-handler count is
still zero. Remaining M5 migration/recount precedes M6 closure.

Reproduce from `kprog/formal` with the documented CPU/memory allocation:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64RegisterReads
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-warm/Query.lean
lake build
```

Raw attempts and query output stay in
`/workspaces/kprog-raw/formal/m5-program-warm`. Canonical simulator C and all
23 Clight exports are unchanged by this proof step. The previous full
`make check` passed at `5236c0e96`; this Lean-only step requires no new C or
native benchmark run.

Validation: focused build passes 141 jobs; the final whole `lake build` passes
270 jobs with zero failures. Three public type/axiom queries pass. They report
the standard three axioms and clean's existing opaque `externalFunctionsSem`
and `inlineAssemblySem` constants occurring in `Step2`; neither boundary is
executed. No external determinism premise or new semantic axiom is added.
All 23 generated exports (243,488,732 bytes) compare byte-identical with
`9c617740f`. Compact results are in `validation.json`; earlier failed
simplification and proof-budget attempts remain in the raw directory.
