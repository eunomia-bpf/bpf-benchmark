# Native simulator verification

This directory executes the actual exported kprog C simulator bodies in
Clight and proves correspondence with external Lean ISA models. The goal is
refinement for every implemented operation and one composed dispatcher-step
theorem per ISA. That complete argument is still in progress; the
[worklist](../docs/todo.md) records the remaining work.

## Specification and layout

- [Reference/](KProgFormal/Reference/) contains the shared specification
  bindings used by proofs and executable differential tests.
  [X86.lean](KProgFormal/Reference/X86.lean) binds
  [x86lean](external/x86lean/); [AArch64.lean](KProgFormal/Reference/AArch64.lean)
  binds [LNSym](external/LNSym/). Git records the pinned submodule revisions.
  Numerical instruction semantics live in those external models.
- [ClightRefinement/](KProgFormal/ClightRefinement/) contains actual-source
  execution, memory, caller and native-state refinement proofs.
  [KProgFormal.lean](KProgFormal.lean) exposes the integrated library.
- [c/](c/) contains C export profiles. The existing Clight export target
  generates imports from them; [build/](build/) holds build products.
- [oracles/](oracles/) and [tools/](tools/) contain semantic comparisons and
  their drivers. [ReferenceMain.lean](ReferenceMain.lean) uses the same
  specification bindings as the proofs.
- [results/](results/) contains scoped receipts, commands, validation output
  and public type/axiom queries. [HISTORY.md](HISTORY.md) preserves the prior
  narrative. The coordinator-authorized [retirement inventory](results/legacy-retirement/README.md)
  records the obsolete JSON/generated-contract route; it is not an active
  reference ISA or a second verification entry point.

## What is proved

The library proves actual helper/handler executions, typed loads and stores,
allocation and deallocation, memory frames, register/tag/provenance and flag
views, and source-to-native caller compositions. The
[integrated public queries](results/m5-x86-release-cache-frame-root/README.md)
retain the prior interfaces and expose each theorem's precise premises.
AArch64 source/caller/native fixture prefixes are also integrated in that
library; they do not establish all AArch64 operations.

The complete x86 NOP handler and its actual generic dispatcher case refine
the same checked ISA step on arbitrary heaps. Scoped logical-register calls
cover all widths and aliases. RSP OR/AND/XOR calls at all four widths additionally
execute both signed-SP release branches, all real cache/metadata updates,
loops and free/return, yielding GPR and flag views of the same canonical
output. The dword writer zero-extends for arbitrary initial RSP tags; qword, byte
and word calls retain their scalar/tag0 destination domain. Byte/word writes
preserve the upper 56/48 bits. Initial source domains,
legal slices, cache/ghost ownership and
provider ABI remain explicit. Native-memory/provider-trace correspondence,
remaining operand domains and operations, fetched call-site correspondence,
and complete universal dispatcher-step theorems remain open.

## What is trusted

Lean's kernel checks the proof terms against the pinned definitions, with
standard logical axioms. Imported Clight execution also uses the existing
`CC.externalFunctionsSem` and `CC.inlineAssemblySem` assumptions; public
`#print axioms` output records their occurrence. Growing-SP release requires
explicit provider availability, permission/frontier preservation and memory
frame premises. The imported external-call interface supplies determinacy
and trace-length laws; those laws do not establish the provider memory ABI.
Actual byte/word release stores, all six slots, the metadata helper and
free/return additionally preserve cache reads at or above new SP. This uses
explicit stronger provider preservation, cache/ghost separation and initial
cache lifetime premises. Binding them to the real provider/producer and
composing the finer frame through whole writers remain open.

The argument also trusts the C front end/exporter, imported semantics and
their correspondence to production C, artifact binding and platform memory
assumptions. Hardware/oracle comparisons check sampled instruction results;
they complement the universal statements within each theorem's premises.
The full specialization, linking/LTO and verifier argument remains work in
progress.

## Run

From this checkout, with the recorded toolchain and submodules:

```sh
make -C kprog/formal check
```

This builds the proof library and executable reference, then runs semantic
oracles covering values, registers, flags, memory effects and faults,
including division faults and permissions. Focused development builds and
public queries are recorded in receipts. Benchmark settings remain frozen.
