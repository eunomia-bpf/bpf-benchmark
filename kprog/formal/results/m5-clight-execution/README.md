# M5 Clight execution foundation

M4 is complete in `ccc6e8fe0`. This step begins M5 with actual Clight execution,
rather than extending the old generated numerical model.

`ClightRefinement/Execution.lean` composes the upstream `CC.doStep` while
retaining the complete trace and state. `steps_sound` derives the upstream
`CC.Star (CC.Step2 ge)` relation from every successful composition, using
`CC.doStep_sound`. It supplies no external-call interpretation or new
instruction semantics; an unsupported executable step remains refused.

`ClightRefinement/Arm64Width.lean` proves a complete call of the actual exported
`Arm64Program.f_arm64_width_effective`, not a copied Lean body. For every byte
input, Clight global environment, continuation and memory:

- The call takes six executable steps, including parameter binding, the real
  branch, unsigned return cast and function return.
- The result is 8 for absent code 0, and the original byte otherwise.
- The trace is empty and the entire memory is unchanged. Memory is arbitrary;
  no initialized private arena, special heap or chosen free input is supplied.
- `returns` constructs the corresponding complete relational execution.

These are a generic soundness lemma and one C-helper execution specification.
They are not ISA-handler simulations, an all-behaviors theorem, migrated
O1/O2/O4 counts, or discharge of the 2,065 old theorem migrations. The ISA-handler
refinement count remains zero. Generic state/view relations and actual
Clight-to-LNSym/x86lean composition remain M5 work.

Final validation builds both proof modules with all 23 Clight modules (62 Lake
jobs), on CPU 17 with 32 GiB AS, `-j1` and default proof limits. `executes` uses
only `propext`, `Classical.choice` and `Quot.sound`. The relational theorems also
expose `CC.externalFunctionsSem` and `CC.inlineAssemblySem`, exactly as upstream
`CC.doStep_sound` does. These are the existing uninterpreted semantic relations
in `external/clean/export/CCLib/Events.lean`, not new handler-correctness axioms.
No external call or assembly executes in this width function. Native platform
bindings and their interpretations must still be supplied for handlers that
use them; determinism assumptions are not imported into these proofs.

The initial BV tactic proof introduced two native checker axioms. It was
replaced before publication by kernel-checked `BitVec.setWidth` and bitwise-AND
lemmas. No native tactic, admission or new axiom remains in either new module.
The intermediate tactic attempts and their diagnostics stay in
`/workspaces/kprog-raw/formal/m5-clight-execution`; final commands/results and
actual axiom output accompany this receipt. No simulator C, compiler flag,
frozen benchmark, image, base or kernel changes in this step.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Execution KProgFormal.ClightRefinement.Arm64Width
```

Next, use these actual-call laws in generic exported-handler proofs and the
memory/entry/native-state relations. M5 must finish all migrations and recount
O1/O2/O4 before M6 archives old generators/contracts/Lean artifacts and completes
the whole-package `lake build` and `make check`.
