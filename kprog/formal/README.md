# Native simulator verification

With Lean/Elan, Python 3, Rust/Cargo, a C compiler with UBSan, and the `vendor/libbpf` and `vendor/linux-framework` submodules
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
The ISA reference lives in `KProgFormal/Reference/`; it imports no simulator
contracts. The step refinements in `Refinement/` connect CMOV, BT, BZHI,
ANDN, BMI2 shifts/rotates, BSWAP/MOVBE and register/immediate/memory PUSH/POP handlers to that reference, including registers,
flags, XMM0, memory, PC and ordered access/fault effects. The AArch64 multiply/divide, conditional-select, extract/reverse/extend, shift/unary, logical-register, MOVK, move-immediate, register-move and V0/GPR bit-transfer (FMOV) and byte-vector reduction (CNT/UADDLV)
families connect through their modules in `Refinement/`, including native
aliases, all raw NZCV predicates, ZR/SP separation including MOV destinations, legal extract immediates,
shifted source modifiers, exact NZCV updates and W zero-extension.

Layout:

- `KProgFormal/Reference/`: the executable ISA semantics and shared memory/effects.
- `KProgFormal/Refinement/`: compositions against that ISA reference.
- `KProgFormal/`: existing bounded handler proofs and their independently stated
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
The lifts take architectural register values; connecting virtual stack/code/helper
encodings to those values is part of the ongoing dispatcher proof.
`Refinement/EntryEnvironment.lean` states the same-invocation SP/code/return
relation with explicit source/body biases and argument/return witnesses. Its
address arithmetic and partial-write proofs require materializing native bits;
the kernel/JIT and per-program ABI certificates must establish the witnesses.

The checked reference also builds as `.lake/build/bin/reference`: JSON lines
on stdin, one JSON transition per line on stdout. Inputs contain `state`
(registers, flags, PC, XMM0, FS/GS bases and explicit memory cells) and
`native_bytes`; the ISA decoder determines operands and the next PC. Outputs
include `defined_flags`, the ISA-defined RFLAGS bits; the relational step permits
any values for undefined bits, and faults preserve every flag. Memory cells must supply a
value, read/write permissions and initialization status; absent cells fault.
`tools/check_reference.py` supplies concrete wire examples and checks the
CPU counterexamples and the encoder's signed displacement packing. The binary
executes the same Lean definitions used by the proofs, without a C/Python
restatement of ISA semantics.

For AArch64, send `isa: "aarch64"` to the same executable. Supply exactly four
little-endian native bytes, `registers` as X0..X30 followed by SP (32 words),
`flags` with NZCV in bits31..28, `vector0` as an unsigned128-bit word, `pc`
and the same explicit `memory` cells. Outputs use `vector0` in place of `xmm0`
and omit x86 segment bases. Arithmetic field31 denotes ZR, independently of SP.
The default ISA remains x86-64; `isa: "x86_64"` is also explicit.
