# Native simulator verification

With Lean/Elan, Python 3, a C compiler, and the `vendor/libbpf` submodule
available, run the complete local check:

```sh
make -C kprog/formal check
```

The target builds the Lean library, checks generated contracts and simulator
routing, rejects proof placeholders, and compiles and runs the C semantic
oracles. It does not read papers or require a separate build command.

The current proofs cover arithmetic and flags, register/tag writeback, memory
accesses, control flow, and selected handler compositions for x86-64 and
AArch64. Dispatcher coverage and exclusivity theorems concern the modeled
routing tables; they are **not yet a full simulator-step refinement theorem**.
Completing that composition for every implemented operation remains lane V's
next proof task.

Layout:

- `KProgFormal/`: Lean refinement proofs and their independently stated
  bounded semantics.
- `KProgFormal/Generated/`: emitted Lean contracts, with stable declaration
  namespaces; the Lake library glob builds every theorem module.
- `contracts/`: JSON input contracts. These describe implementation slices,
  not a complete independent ISA model.
- `tools/`: generators and semantic checks; `tools/mutations/` retains the
  tracked semantic mutation batteries.
- `generated/`: emitted C contracts used by the production simulators. Their
  include paths stay stable for simulator consumers.
- `oracles/`: semantic cross-checks, including the route hosts formerly kept
  under `build/`. Each host compares a contract or simulator path with an
  independently calculated expected result.
- `build/` and `.lake/`: disposable compiled outputs, never oracle sources.

Trust boundary: Lean checks the Lean models, not C source or compiled BPF.
The Lean kernel and toolchain are trusted; `native_decide` proofs additionally
trust compiled evaluation. The JSON-to-C and JSON-to-Lean generators emit
separate expressions. Generator freshness checks and C semantic oracles test
that boundary but do not prove arbitrary C compilation correct. Hardware
fidelity, verifier acceptance, helper behavior, and artifact binding require
separate evidence; these local proofs do not establish them by themselves.
