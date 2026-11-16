# M5 actual origin-cache readers and scalar materialization

`Arm64OriginCache` proves complete calls of the actual exported
`kprog_arm64_stack_base`, `kprog_arm64_return_base` and
`kprog_arm64_materialize` functions in `Clight/Arm64Address.lean`. Their C
bodies use the production macros through the existing coordinates extraction
ABI. The proof uses the actual exported composite environment and checks its
base/validity offsets with the imported layout algorithm. It does not construct
an initialized specimen heap or replace production storage.

Both base readers complete in fourteen internal transitions. The premises
are exactly the selected validity-byte and base-word typed loads, with any
nonzero byte and arbitrary 64-bit base. Caller memory, pointer block/offset
and continuation remain arbitrary. The complete memory is unchanged.

Scalar materialization covers every 64-bit value and all 256 byte tags. It
agrees with the existing M3 provenance materialization: STACK adds the stack
origin, RETURN adds the return origin, and other tags retain their bits.
Only the selected cache must satisfy `WarmCache`; the other 254 tags need no
memory premise. STACK takes 30 transitions, RETURN 31 and other tags 18.
`materialize_returns` supplies the actual internal-run certificate, and
`materialize_return_unique` proves that every proposed relational return at
`Kstop` has that result, the original complete memory and an empty trace.
Neither the observed result nor its trace is assumed in advance.

Constructor-specific equations are proved against the imported `doStep`;
they keep unknown intermediate states opaque during simplification. The
actual function's entry-name facts and temporary-name inequalities are
kernel-checked. Its closed AST parts are extracted by ordinary elaboration
reduction and checked by a definitional equality to the exported body. No
Clight rules, native ISA operations, external-call implementation or new
axioms are introduced. Initial whole-interpreter expansions exceeded default
simplification/heartbeat budgets; the final proof retains the default limits.
Temporary composition lemmas were removed after the reduction pass, leaving
only this new proof module and receipts/status documentation.

The warm-cache premises are explicit proof conditions, not producer facts
or runtime gates. Production initializes these caches as cold; execution of
`native_lab_entry_input` and establishment of the actual invocation origins
remain to be proved. The scalar theorem takes `Vlong` inputs; it does not yet
prove the pointer-valued union cases from the register relation. The
coordinates extraction ABI also still needs its producer/borrowed-entry
binding. Native memory/payload/permissions and compiled/general caller
control remain open. This adds three C-helper laws and zero complete
ISA-handler refinements. All 2,065 migrations and O1/O2/O4 recount, then M6
and final whole-package checks, remain outstanding.

All 23 unchanged export modules and thirteen proof modules pass 161 Lake
jobs. Five axiom queries and three public type prints pass. Executable laws
use only standard Lean axioms; relational laws additionally expose the two
existing opaque external/assembly relations, without their determinism
assumptions. Builds used CPU 17, 32 GiB AS and `-j1`; queries used CPU 19
and 16 GiB AS. Recursion/heartbeat limits remain unchanged. Canonical C,
exports, external semantic sources and frozen benchmark paths remain exact
to `478436093`. No compiler, kernel, guest, base or image changed. Earlier
diagnostics, including rejected reducibility-attribute experiments, stay in
raw; the final source changes no reducibility attributes or unsafe options.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64OriginCache
lake env lean -j1 results/m5-origin-cache/Axioms.lean
```

Commands and axiom output are retained here. Raw builds and diagnostics stay
at `/workspaces/kprog-raw/formal/m5-origin-cache`.
