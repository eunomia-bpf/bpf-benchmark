# Native simulator verification

This directory proves components of the kprog C simulators against external
Lean ISA models. The current route executes the actual exported C in Clight
and relates its state to the native model. The M5/M6 work combines these
components into per-instruction handler refinement, dispatcher composition,
and the complete O1/O2/O4 arguments. Current coverage comes from the Clight
proof receipts, and the [verification worklist](../docs/todo.md) tracks the
next composition steps.

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
Current proofs use the pinned external ISA specifications described above.

## Checked components and composition work

The checked components include actual x86 width/count/shift helpers,
ALU/flag calls and scalar byte-register writeback; AArch64 register readers,
writers, condition/select and MOVK components; and shared allocation,
framing, deallocation, entry and caller composition laws. Every theorem's
premises and result receipt define its exact scope. The worklist organizes
their composition into instruction handlers and dispatcher-step theorems
for each ISA.

The [x86 entry-storage receipt](results/m5-x86-entry-storage/README.md)
connects the real handler allocation and caller permissions to the 169-step
ordinary scalar byte writer. [ARM pointer-value execution](results/m5-pointer-values/README.md)
and [selected-operand matching](results/m5-select-matched/README.md) record the
parallel ARM work. Each receipt records the checked behavior and next
composition steps.

The [scalar reader](results/m5-x86-reader-scalar/README.md) and
[XOR entry](results/m5-x86-xor-result-entry/README.md) receipts establish real
calls within their explicit value domains. The
[pointer-call receipt](results/m5-x86-pointer-call/README.md) proves that a
genuine pointer-cell reader call reaches the imported Clight model's numeric
shift boundary. Extending this domain requires concrete-address correspondence;
this obligation remains part of full handler composition.

The [logical byte tail](results/m5-x86-logic-byte-tail/README.md) derives real
flag stores, register writeback and local release from initial permissions.
The [canonical byte step](results/m5-x86-canonical-byte-logic/README.md) gives
the same reference ISA's full-state logical-register result, including oracle
and PC updates. The [genuine XOR byte calls](results/m5-x86-xor-byte-all/README.md)
now cover every ordinary scalar/tag0 register-slice aliasing route through
actual stores, local release and return, with final GPR and flag views of that
same ISA output. The [dword calls](results/m5-x86-xor-dword-all/README.md)
also cover all ordinary scalar/tag0 register aliasing, using the real
197-step writer and actual return. Their matched shortcut additionally
covers old represented pointer/tag cells. The [qword calls](results/m5-x86-xor-qword-all/README.md)
cover the same ordinary scalar/tag0 aliasing domain through the original
selectors, repeated tag calls, 252-step writer and actual return. The
[word-width calls](results/m5-x86-xor-word-all/README.md) cover that same
scalar/tag0 aliasing domain through the actual 181-step partial writer,
preserving 48 upper bits. General pointer arithmetic and dispatcher
composition remain proof work. The actual OR/AND calls now cover the same
ordinary scalar/tag0 register domain at all four widths, including legal
low/high-byte slices and all aliasing, through the
[canonical outputs](results/m5-x86-logic-register-root/README.md).
The [RSP-aware logical calls](results/m5-x86-rsp-logic-root/README.md) extend
OR/AND at all four widths to RSP sources through the genuine native-base
reader calls and the same canonical full-state outputs. The
[RSP-source XOR calls](results/m5-x86-native-xor-byte-all/README.md) now
provide the same all-width extension, including every ordinary register
alias, with the original shortcuts and reader-dependent execution lengths. Their destination
remains an ordinary scalar/tag0 register; legal byte slices are explicit.
The [RSP storage prefix](results/m5-x86-write-rsp-storage/README.md) executes
reverse materialization and both table stores to the exact stack-release
frontier. The [RSP destination calls](results/m5-x86-rsp-dword-root/README.md)
refine the same canonical OR/AND step through free and return for non-increasing
raw SP: qword with tag0, dword with any initial tag and real zero-extension.
The [byte/word RSP calls](results/m5-x86-logic-rsp-partial-native/README.md)
also refine the same canonical full-state OR/AND step through actual
partial stores, reverse/table writes, non-increasing release, free and return,
preserving native upper56/48 bits. Their scalar/tag0 destination and legal
byte slices remain explicit. Volatile partial writes, increasing-SP release,
other qword tags and remaining pointer operand domains stay open.

The [RSP XOR calls](results/m5-x86-xor-rsp-root/README.md) cover every legal
source-register alias at all four widths within those destination tag and
non-increasing raw-SP conditions. They retain the original 77-step zero
shortcut for the same RSP/lane and both real native reader calls for distinct
registers, then refine the same canonical full-state step through return.

The [complete RSP release source](results/m5-x86-release-assembly-root/README.md)
now composes real reverse materialization and table stores, both signed-SP
branches, all six word/eight-byte slots, frame-helper clears, original loop
exits and handler free/return. Initial reads and permissions derive every
later store and release observation. Tagged GPR/provenance observations and
all five flags survive under explicit cache/ghost ownership and actual-provider
ABI premises. Binding those premises to the production provider and caller
allocation, then composing canonical operation inputs, remains open.
The [whole qword writer](results/m5-x86-qword-release-return/README.md) also
starts at its original selectors and derives saved-SP reads, local allocation
rights, both helper scopes and every intermediate view through return.
The [full-width tail](results/m5-x86-full-width-release-return/README.md)
additionally covers the actual dword overwrite and zero-extension.
The [complete NOP handler](results/m5-x86-nop-native/README.md) refines the
same canonical checked step for arbitrary heaps, tags and ignored operands,
preserving the entire native state except PC. The existing
[generic dispatcher NOP case](results/m5-x86-nop-dispatch/README.md) now
composes its actual width helper, opcode guard, handler call and return in
27 transitions, for every byte flag/operand code and arbitrary heap. The
other dispatch arms and fetched call-site composition remain open.

## Trust boundary

Lean's kernel checks proof terms against the pinned definitions, with the
standard logical axioms. Executing imported Clight additionally uses the
existing `CC.externalFunctionsSem` and `CC.inlineAssemblySem` assumptions;
scoped `#print axioms` output records their occurrence. Provider memory frames
remain explicit ABI premises: the imported external-call interface supplies
determinacy and trace-length laws, without memory-frame laws. The trust argument
includes the C front end, C-to-Lean exporter, imported semantics and their
correspondence to the production simulator. The pinned ISA models supply
architectural specifications; hardware/oracle comparisons check instruction
results on the sampled cases. Lean refinement statements express universal
correspondence within their stated premises.

The worklist extends the end-to-end argument across specialization, native
linking/LTO, artifact binding, platform memory/provider assumptions and
verifier execution. Component receipts record the established executions
and the next composition steps for that argument.

## Run

From the Workspace checkout, with its recorded Lean toolchain and submodules:

```sh
make -C kprog/formal check
```

This builds the proof library and executable reference and runs the semantic
oracles. The checks compare instruction values, registers, flags, memory
effects and fault behavior, including division faults and memory permissions.
Benchmark workloads and settings retain their frozen definition. The existing
`clight-sources` Make target generates C imports for inspection; `make check`
is the complete verification entry point. Focused development builds and
public queries are recorded in the corresponding result receipts.
