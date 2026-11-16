# Actual combined SP reader

`Arm64RegisterReads.sp_read_prefix` follows the actual exported
`kprog_arm64_program_read(entry, 32)` through 35 internal transitions. It reads
the borrowed signed-long SP offset and produces the constant STACK tag,
without a GPR table read. The function's stages and exact temporary environment
are checked against the generated Clight body.

`sp_read_warm` composes that prefix with the existing checked STACK tail. The
complete call takes 71 internal transitions, returns the wrapped offset plus
cached origin and preserves every byte and permission of the complete Clight
memory. The origin/validity cells are individually borrowed through the actual
entry fields. No provider outcome or additional read-only alias exclusion is
assumed.

`sp_read_return_corresponds` connects every proposed return at `Kstop` to the
native SP in `Arm64Registers.Represents`, with an empty trace and original
memory. The selected warm cache containing the invocation stack origin stays
an explicit producer binding. This is a helper-component law, adding zero
complete ISA-handler refinements. Cold Program caches, producer/compact/PC
bindings, native-memory semantics, compiled control and the O1/O2/O4 recount
remain M5, before remaining M6 closure.

Reproduce from `kprog/formal` using the lane's assigned CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64RegisterReads
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-sp/Query.lean
lake build
```

Raw output stays at `/workspaces/kprog-raw/formal/m5-program-sp`. This step
changes no simulator C, generated export, external semantic source or frozen
benchmark file. The last full `make check` passed at `5236c0e96`; these
additional Lean-only proofs require no new native test run.

Validation: the focused build passes 141 jobs and final whole `lake build`
passes 270 jobs with zero failures, at the unchanged default proof limits.
Three public type/axiom queries pass. The executable prefix uses only the
standard three axioms; relational laws additionally name clean's existing
opaque external/assembly semantic constants present in `Step2`. Neither
external boundary executes and no external determinism axiom is used.
