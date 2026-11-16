# M5 ARM materialization of represented values

`Arm64OriginCache.materialize_represents` extends the actual exported
`kprog_arm64_materialize` call to both scalar and pointer-valued register
union reads. It consumes the existing `Arm64Registers.ValueRep` relation.
For every represented input, its returned Clight value represents the M3
materialized native bits. The complete caller memory remains unchanged.

For the 254 tags other than STACK and RETURN, a pointer returns as exactly
the same Clight pointer in eighteen internal transitions. Its native bits
remain bound through the original block origin and full pointer offset;
there is no pointer-to-arbitrary-integer conversion. These tags require no
cache or memory-read premise. Scalar STACK/RETURN cases reuse the existing
30/31-step execution laws and only the selected warm cache.

The actual ulong cast accepts both `Vlong` and `Vptr` on this target. The
pass-through branch is now proved once for any value accepted by that cast;
the existing scalar proof reuses it. The imported `Cop.semBinarith` integer
addition accepts long operands, so relative STACK/RETURN payloads must be
scalar offsets. This remains an explicit producer admissibility condition,
not a runtime check or a claim that all pointer/tag combinations execute.
Undefined and unbound values gain no fabricated native bits.

`materialize_return_represents` covers every proposed relational return at
`Kstop`, with arbitrary proposed trace, value and memory. The existing
internal-path uniqueness theorem gives an empty trace, the original complete
memory, and the represented materialized result without external determinism
assumptions. General resumed caller control remains separate.

This step changes proof code only. It adds zero complete ISA-handler
refinements. Actual producer/tag/cell/origin admissibility, cold materializer
composition, native memory and general compiled control remain M5; all 2,065
migrations and O1/O2/O4 recount, then M6 and final whole-package checks, remain.
Canonical C, all exports and imported semantics stay unchanged.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64OriginCache
lake env lean -j1 results/m5-pointer-materialization/Axioms.lean
```

All 23 exports and thirteen proof modules pass 161 Lake jobs. Four axiom
queries and two public type prints pass. Executable laws retain standard Lean
axioms only; relational laws additionally expose the existing opaque external
and assembly relations, without external determinism assumptions. Source
comparison against `f07136724` passes for C, exports, imported semantics and
frozen benchmark paths. Commands and output are recorded in `commands.json`
and `axioms.txt`. Worker CPU 17 uses 32 GiB AS and `-j1`;
queries use CPU 19 and 16 GiB AS. Default heartbeat and recursion limits stay
unchanged. Raw diagnostics are retained under
`/workspaces/kprog-raw/formal/m5-pointer-materialization`.
