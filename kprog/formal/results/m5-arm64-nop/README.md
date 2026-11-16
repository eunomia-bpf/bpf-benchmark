# M5 generic ARM NOP body correspondence

`ClightRefinement/Arm64Nop.lean` proves execution of the actual generic exported
`Arm64Program.f_kprog_arm64_program_execute` for opcode 0. It does not introduce
a NOP-specific C fixture or copy an interpreter. Structural projections of that
function's real AST have a proved successful shape; an incompatible shape is
`none`, not a silent empty statement. The exact prefix, width call and NOP gate
are checked by equality with the exported data.

The body execution composes four actual steps to the internal width call, its
six-step proved call, and seven steps to statement completion. It retains:

- Every byte value of `flags`; ignored operands and all other caller temporary
  bindings are arbitrary. `_op` is the actual NOP code 0.
- Arbitrary complete Clight memory, caller environment and continuation.
- Exactly the original memory, environment and continuation at completion.
  Only `_t'1` and `___a64_l_width` compiler temporaries are updated, as specified
  by `resultEnv`. No input function, external call or assembly executes.

`WidthBinding` states ordinary name resolution and absence of local shadowing.
Its `programBinding` witness proves the symbol and actual internal function
lookup in the real exported program. Block 66 is a Clight global block, not an
invented kernel address. Generic global-allocation lemmas prove that later
entries preserve an already allocated block. Separately named list/environment
facts avoid reducing the entire large table in one elaboration. Symbol equality
uses `decide +kernel`, not native evaluation; limits are unchanged.

On the native side, a kernel-checked equality decodes `0xd503201f` with LNSym.
The actual checked step updates only PC. The theorem then follows through
`Reference.AArch64.step`, retaining the complete external machine and kprog's
extra flag word, with an exact empty event/fault delta. Existing arbitrary
memory profiles, byte values, initialization, permissions, monitor state,
system inputs and histories remain in that whole state. The native entry is
error-free and its current PC fetches the supplied NOP word; other model-refusal
entries are not discharged by this successful-execution theorem.

`Represents` equates the full native wrapper state with a heap decoder's full
state at an explicit PC cursor. `corresponds` proves that the real Clight body
preserves that heap while the native checked step yields the complete decoded
post-state at cursor + 4, with no event or fault. It is parametric in the entire
decoder; no architectural field other than the explicitly transported PC is
projected away. **A concrete decoder from actual entry cells, its domain and
admissibility, C function-frame allocation/freeing, compiled-label/PC embedding
and an all-behaviors refinement remain unproved.** This is one conditional
handler-body correspondence, zero complete ISA-handler refinements, not the
O1/O2/O4 recount or completion of the 2,065 migrations.

The new `Globalenv.lean` and `Execution.star_trans` are generic proofs over the
upstream environment and small-step relation. `Arm64Width.cast_argument` proves
the byte ABI cast used by the actual call. No C, export, generator contract,
compiler flag, frozen benchmark, base, image or kernel changes.

Final validation builds all 23 exports and four proof modules (137 Lake jobs),
on CPU 17/32 GiB AS/-j1/default proof limits. All ASTs remain exact to
`67fc62dbd`. The NOP leaf took 21 seconds. Ten actual axiom queries show standard
Lean axioms only for the native, cast and binding laws; the Clight relational
laws additionally expose the existing `CC.externalFunctionsSem` and
`CC.inlineAssemblySem` relation constants, matching the previous foundation.
No new axiom, admission, native tactic or external determinism assumption.

Raw `/workspaces/kprog-raw/formal/m5-arm64-nop` keeps all initial syntax,
simplification, private-state unfolding and lookup resource-limit diagnostics.
The final proof factors those computations without raising limits. Exact
commands and axiom output accompany this receipt. Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64Nop
```

Next M5 work is the concrete entry/native-memory representation and procedure
boundary, followed by other generic handler families and the full migration
recount. M6 and final whole-package checks remain ordered afterward.
