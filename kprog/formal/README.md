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

The library proves actual C helper/handler executions, typed memory effects,
allocation/freeing, caller frames and native register/scalar/cache views.
[Public type and axiom queries](results/m5-x86-producer-push-boundary-root/README.md)
expose every theorem's precise premises and retain prior interfaces.

The complete NOP handler and its actual generic dispatcher case refine the
checked ISA on arbitrary heaps. Scoped logical-register calls cover widths,
aliases and real RSP release/store/free paths within their stated domains.
AArch64 source/caller/native fixture prefixes are also integrated.

The original producer's first PUSH executes initialization, dispatch, real
stores/freeing and entry into the next source label. Its same final heap
represents GPRs, six flag bytes, XMM0 and initialized cache bytes of the exact
canonical PUSH step on its explicit successful-access domain. The proof binds
the actual kind-1 stack origin, original byte-fold memory effects, real cache
assignment observation and concrete byte53 decoding/one-byte fall-through.
Input native memory remains arbitrary. Native ELF/code-storage binding,
general source/guest trace simulation, platform/input-oracle correspondence,
remaining operand/fault domains and all149 universal handler/dispatcher-step
goals remain unfinished.

## What is trusted

Lean's kernel checks terms against the pinned definitions, with standard
logical axioms. Imported Clight execution uses the existing
`CC.externalFunctionsSem` and `CC.inlineAssemblySem` assumptions; public
`#print axioms` output records their occurrence. The argument also trusts the
C front end/exporter, imported semantics, production-artifact binding and
platform memory assumptions.

Initial register/scalar/cache relations, operand/tag/provenance domains,
ownership, permissions and provider availability/frame guarantees remain
explicit premises. Growing-SP release requires stronger cache preservation
than the basic provider frame. External-call determinacy and trace-length
laws do not establish these memory ABIs. Protected typed loads across
providers do not imply raw byte equality. PUSH's private Clight cache write
is silent; its proved logical guest-write observation is a separate view,
not equality of the two external traces.

Hardware/oracle comparisons check sampled instruction values, registers,
flags, memory effects and faults. They complement universal statements within
their premises. Full specialization, linking/LTO and verifier correctness
also remain work in progress.

## Run

From this checkout, with the recorded toolchain and submodules:

```sh
make -C kprog/formal check
```

This builds the proof library and executable reference and runs semantic
oracles, including division faults and permissions. Focused commands and
validation output are retained in receipts. Benchmark settings stay frozen.
