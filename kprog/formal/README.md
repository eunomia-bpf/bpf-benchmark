# Native simulator verification

This directory proves components of the kprog C simulators against external
Lean ISA models. The current route executes the actual exported C in Clight
and relates its state to the native model. Per-instruction handler refinement,
dispatcher composition, and the complete O1/O2/O4 obligations remain unfinished
(M5/M6 open). Earlier generated-contract counts do not measure current coverage.
Current work is tracked in the [verification worklist](../docs/todo.md).

## Specification and layout

- [Reference/](KProgFormal/Reference/): the shared ISA bindings used by proofs
  and the executable reference oracle. [X86.lean](KProgFormal/Reference/X86.lean)
  binds [x86lean](external/x86lean/); [AArch64.lean](KProgFormal/Reference/AArch64.lean)
  binds [LNSym](external/LNSym/). The submodule revisions recorded by Git pin
  these specifications. Numerical instruction semantics live in those models.
- [ClightRefinement/](KProgFormal/ClightRefinement/): execution and refinement
  proofs over real handler bodies, memory frames, native views and callers.
  [KProgFormal.lean](KProgFormal.lean) exposes the integrated public proofs.
- [c/](c/): C export profiles. Clight imports in [build/](build/) are generated
  by the existing Clight export Make target, also invoked by `lake build`.
- [external/](external/): the ISA models and Clean's CompCert/Clight export and
  semantics. Each dependency retains its own license.
- [oracles/](oracles/) and [tools/](tools/): executable semantic comparisons
  and their drivers. [ReferenceMain.lean](ReferenceMain.lean) exposes the same
  reference bindings to the differential tools.
- [results/](results/): scoped proof receipts, public type/axiom queries and
  validation evidence. [HISTORY.md](HISTORY.md) retains development history.

The obsolete JSON/generated-contract proof route and its generators were
retired under the coordinator's 2026-11-16 instruction; the
[retirement inventory](results/legacy-retirement/README.md) records that change.
No second ISA specification is maintained in generated contracts.

## Established components and remaining scope

The checked components include actual x86 width/count/shift helpers,
ALU/flag calls and scalar byte-register writeback; AArch64 register readers,
writers, condition/select and MOVK components; and shared allocation,
framing, deallocation, entry and caller composition laws. Every theorem's
premises define its exact scope. These components do not establish all
simulator operations or one complete dispatcher-step theorem per ISA.

The [x86 entry-storage receipt](results/m5-x86-entry-storage/README.md)
connects the real handler allocation and caller permissions to the 169-step
ordinary scalar byte writer. [ARM pointer-value execution](results/m5-pointer-values/README.md)
and [selected-operand matching](results/m5-select-matched/README.md) record the
parallel ARM work. Consult each receipt for pending composition obligations.

## Trust boundary

Lean's kernel checks proof terms against the pinned definitions, with the
standard logical axioms. Executing imported Clight additionally uses the
existing `CC.externalFunctionsSem` and `CC.inlineAssemblySem` assumptions;
scoped `#print axioms` output records their occurrence. The C front end,
C-to-Lean exporter, imported semantics and their correspondence to the
production simulator remain part of the trust argument. External models are
specifications, not proofs of physical hardware. Hardware/oracle comparisons
provide sampled fidelity evidence rather than universal refinement.

The end-to-end argument also needs specialization, native linking/LTO,
artifact binding, platform memory/provider assumptions and verifier execution.
The current component proofs do not discharge all of these obligations.

## Run

From the Workspace checkout, with its recorded Lean toolchain and submodules:

```sh
make -C kprog/formal check
```

This builds the proof library and executable reference and runs the semantic
oracles. It does not modify benchmark workloads or settings. Use the existing
`clight-sources` Make target only when inspecting the generated C imports;
`make check` is the complete verification entry point. Focused development
builds and public queries are recorded in the corresponding result receipts.
