# M5 actual ARM GPR value/tag readers

`Arm64RegisterReads` proves complete calls of the actual exported
`kprog_arm64_program_raw` and `kprog_arm64_program_tag` functions in
`Clight/Arm64Program.lean`. Each call takes 28 internal transitions for every
architectural GPR index 0–30 and preserves the complete caller memory.
The proof uses the imported `doStep`/`Step2` semantics, actual declarations,
composites, field offsets and typed pointer-table loads.

`Arm64EntryMemory.gpr_loads` decomposes the existing checked observation into
its actual header, table-slot, union-cell and tag loads. Cells remain
individually supplied pointers; aliases are allowed and no dense register
bank or initialized specimen heap is introduced. `load_pointer` preserves
the frontier ownership fact and connects each successful checked read to
its imported load. Undefined values are retained by these observations;
`gpr_returns` uses the existing `ValueRep` to require a represented value
before executing the actual return cast. A pointer-valued cell returns as
the same pointer, with its native block-origin binding retained.

The C byte-index cast is checked for arbitrary `Fin 31`. C integer promotion
then selects signed-int pointer addition; the proof establishes its exact
eight-byte slot offset, including wrapping pointer arithmetic. Actual field
and union offsets are kernel-checked. Imported pointer operations stay intact
while zero-offset/index equalities normalize their uses. No semantics,
reducibility attributes, unsafe options or proof limits are changed.

`register_return_corresponds` consumes the existing full-register relation
with the actual default export's identity cell mapping. Every proposed pair
of raw/tag returns at `Kstop` has empty traces, original complete memories,
and values agreeing with the native GPR through `ValueRep` and M3
materialization. The observed traces, values and memories are arbitrary.
This result uses internal-step uniqueness without external determinism.

This binds the reader expressions to the checked entry observations. Actual
producer initialization, compact source-profile mappings and tag/cache/origin
admissibility remain separate obligations. SP has a distinct C selector of
32 and is outside these GPR-index laws. Cold materialization, native memory
and general compiled control remain M5. The complete ISA-handler count stays
zero; all 2,065 migrations and O1/O2/O4 recount, then M6 and final whole-package
checks, remain outstanding. Canonical C and all exports stay unchanged.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64RegisterReads
lake env lean -j1 results/m5-register-reads/Axioms.lean
```

All 23 exports and fourteen proof modules pass 162 Lake jobs. Four axiom
queries and two public type prints pass. Load-decomposition laws use only
standard Lean axioms; relational reader laws additionally expose the existing
opaque external/assembly relations, without external determinism assumptions.
Source comparison to `a9358a301` passes for C, exports, imported semantics,
execution infrastructure and frozen benchmark paths.

Commands and output are retained here. The first combined build after a
reduction pass omitted required pointer-size normalization; restoring that
normalization passes the target and final combined build. Both command
outcomes and all earlier diagnostics are retained. Builds use CPU 17,
32 GiB AS and `-j1`; queries use CPU 19 and 16 GiB AS. Raw iterations stay at
`/workspaces/kprog-raw/formal/m5-register-reads`.
