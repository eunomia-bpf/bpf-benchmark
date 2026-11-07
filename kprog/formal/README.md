# Native simulator verification

Current [coverage and totals](../results/kprog_verification_20261107/README.md)
track each declared operation and token. The generic C-model O2 interface covers
28 x86 register tokens; full raw ISA and compiled-simulator closure continue.

Run the complete verification entry point on an x86-64 Linux host:

```sh
make -C kprog/formal check
```

It requires Lean/Elan, Python3, Rust/Cargo, a C compiler with UBSan,
clang18/LLVM18, GNU objdump, and the vendor/libbpf and vendor/linux-framework
submodules. The target builds all Lean modules, checks generated contracts,
rejects proof placeholders, and runs semantic C oracles and executable-reference
checks. Existing build caches are reused. Papers and paper/count checkers are
not inputs.

The reference ISA is defined once in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean), with shared
[memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean).
These definitions cite Intel/Arm sources and import no simulator contracts.
Uninitialized native memory has arbitrary values. Undefined architectural
outputs are masked by the relational step, rather than promised a fixed value.
[ReferenceMain.lean](ReferenceMain.lean) executes these same definitions through
JSON; tools/check_reference* contain concrete input examples. F's hardware
replays and T's artifact checks use this specification.

- [contracts/](contracts/): implementation JSON contracts.
- [generated/](generated/) and [KProgFormal/Generated/](KProgFormal/Generated/):
  generated C/Lean contracts checked against their inputs.
- [KProgFormal/](KProgFormal/): arithmetic, flags, register/tag, memory and
  routing proofs; [Refinement/](KProgFormal/Refinement/) connects implementation
  primitives and selected handlers/dispatchers to the canonical ISA steps.
- [oracles/](oracles/): retained C semantic oracles.
- [tools/](tools/): contract generators and semantic/source checks.
  build/ and .lake/ contain rebuildable incremental outputs.

The handler refinements retain the complete modeled state, PC, ordered memory
accesses and faults under their stated field, address and platform witnesses.
The x86 raw register frame covers RSP offsets and STACK arena pointers, lane
reads/writes, MOV/MOVZX/MOVSX/CMOV/SETCC/XCHG, reversal/count, logical, arithmetic, unary, multiply/MULX, compare and immediate/CL
shift, classic ROR, BMI2 and bit-operation register bodies. Its partial raw
dispatcher composes the published opcode/AUX/width/GPR bindings into the
canonical `Step` relation, retaining actual writes to undefined flags. The AArch64
numeric/code frame composes scalar, memory, vector, exclusive and control
families under its explicit observation and environment relations. Theorem
statements give the exact scope; full77/72 operation coverage, every dispatcher
arm and the compiled-program O2/O4 link are still being completed.

Architectural profiles are explicit. x86 near control uses48/57-bit canonical
addresses with CET disabled; LEAVE checks the wrapping eight-byte frame span
under a LASS-disabled profile. ARM uses the current Cortex-A72 base profile;
SP alignment, pair-access granularity and exclusive monitor/order inputs remain
explicit. A sequential vector footprint does not prove concurrent atomicity.
Exclusive failure remains a possible outcome on each dynamic attempt; the
per-instruction proofs supply no bounded-retry or eventual-success guarantee.

Twenty-two direct and six generic register token bodies have semantic equality to interpreter
dispatch for arbitrary fields and invocations. Safety work is generic per
simulator and token; historical per-program proofs are frozen and excluded
from the argument. Remaining tokens and native-link/compiler preservation
are being connected through [generic composition](../tv/Composition.lean).

The trusted boundary includes Lean's kernel/toolchain, the contract generation
and C/Lean correspondence, native decoding/encoding, and the C/BPF compilers.
Initial ABI, provenance/permissions, physical exclusive monitor/order/site
identity and runtime artifact binding must be established by their callers or
platform certificates. A generated contract is an implementation model, not a
second ISA. Finite hardware/oracle checks complement the universal theorems.

[The dated verification results](../results/kprog_verification_20261107/README.md)
retain exact source hashes, commands, original failures and subsequent checks.
They distinguish focused proofs/oracles from complete make-check outcomes.
[Artifact validation](../tv/README.md) records the separate end-to-end work.
