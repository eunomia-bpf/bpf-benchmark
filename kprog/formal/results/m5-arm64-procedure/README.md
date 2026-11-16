# M5 ARM NOP procedure and caller frame

`ClightRefinement/Arm64NopCall.lean` extends the actual generic ARM NOP body
proof from `dec7e3a19` through Clight function entry and return. Proving entry
first exposed the [identifier freshness defect](../m4-clight-identifiers/README.md);
that frontend repair and regeneration precede this procedure proof. It starts at
`Callstate` of `Arm64Program.f_kprog_arm64_program_execute`, performs actual
local allocation, parameter binding and the internal width call, and reaches
`Returnstate Vundef` with the original call continuation and an empty trace.
Successful freeing of that allocated frame is an explicit premise.

Function entry itself is proved for every initial Clight memory and flags byte.
All seven ignored operands remain arbitrary Clight values, including pointers
and undefined values. The nine parameters are bound over all 11,870 actual
undef temporaries. The allocator allocates all 266 address-taken locals even
on this NOP path. The actual exported declarations prove unique local and
parameter names, parameter/temporary disjointness and absence of a local
shadow for the internal width function. The previous real-program symbol and
function lookup then supplies its binding without an extra caller assumption.
The counts are executable observations of the exported fields; the name laws
are independent kernel-checked proofs.

`Arm64NopDeclarations.lean` checks the existing four local chunks and 128
temporary chunks separately, then composes those facts about the actual fields.
This factors expensive identifier reductions without copying the AST or
introducing another production generator. Elaboration is sequential in that
module; recursion and heartbeat limits remain at their defaults. Closed name facts use `decide +kernel`, with no native checker axiom.
Standard `List.all` reflection proves the original disjointness and distinctness
propositions from finite Boolean computations over the actual identifiers.
This avoids constructing large bounded-universal decision proofs. `Prod.eta` avoids
unfolding the entire 266-allocation computation simply to reconstruct its pair.

`ClightRefinement/Frame.lean` proves a raw frame over the upstream CompCert
memory. Allocation and a successful free-list of fresh blocks preserve the
complete contents and Cur/Max permission functions of every block below the
caller's original `nextblock`, at every offset. This includes undefined bytes,
inaccessible blocks and failed typed loads. It also proves monotonic allocation,
typed-load equality. The actual entry name lookup reuses upstream
`CC.allocVariables_env_other`; no duplicate local-shadowing proof is kept. The whole
memory structure is not equated: allocating locals advances `nextblock`, and
freeing them clears their permissions.

`entry_frame` instantiates this law with the actual C allocator. `return_frame`
composes allocation and free-list framing under explicit enumeration freshness
and free-success premises. `call_corresponds` combines the real procedure
execution, that raw frame and the existing full LNSym/reference NOP step. A
full-state heap decoder must respect the old memory frame; it then yields the
exact native post-state at cursor + 4, with an empty event/fault delta. Native
error-free entry and actual NOP instruction fetch remain explicit.

**This remains one conditional NOP correspondence and zero complete ISA-handler
refinements.** Freshness and successful freeing of the actual enumerated local
blocks, a concrete decoder/domain and its frame law, compiled-label/PC embedding
and all-behaviors refinement remain to be discharged. The other handler
families, all 2,065 historical theorem migrations and O1/O2/O4 recount remain
M5 work. M6 and final whole-package `lake build` / `make check` follow in order.

The preceding frontend repair updates the clean fork and all Clight exports.
This procedure step adds proof modules only. Canonical C, generator contracts,
benchmarks, compiler flags, kernel, base and image remain unchanged. Final commands and actual axiom
output accompany this receipt. Raw diagnostics, including the initial bounded
memory failure, factored heartbeat failures and thread-creation failure, stay
at `/workspaces/kprog-raw/formal/m5-arm64-procedure`.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64NopCall
lake env lean -j1 results/m5-arm64-procedure/Axioms.lean
```

Final validation passes all 23 Clight exports and seven proof modules (140
Lake jobs), all seven existing Lean metadata/layout/link oracles, the canonical
codec regression and 15 actual axiom queries. The ARM links each retain 136
internal bodies; x86 helper/read composition retains 117. All queries use only
standard Lean axioms, with the procedure relations additionally exposing the
existing opaque `CC.externalFunctionsSem` and `CC.inlineAssemblySem`. No new
axiom, admission, native checker or external determinism assumption. Source
comparison against `dec7e3a19` confirms canonical C and frozen paths unchanged.
Checks ran on CPUs 17–19, Lean -j1/32 GiB AS/default proof limits.

The subsequent [local deallocation step](../m5-local-deallocation/README.md)
proves the enumerated-local freshness and free-success obligations discussed
above. Current `call_returns` and `call_corresponds` construct a return memory
without these caller premises. This receipt records the earlier `ac0f772d1`
procedure step; its historical validation and remaining concrete-representation
and all-behaviors obligations are retained.
