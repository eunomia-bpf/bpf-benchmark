# Native simulator verification

With Lean/Elan, Python 3, Rust/Cargo, a C compiler with UBSan, clang18/LLVM18 tools, and the `vendor/libbpf` and `vendor/linux-framework` submodules
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
ANDN, BMI2 shifts/rotates, BSWAP/MOVBE, ordinary MOV, ADD/ADC/SUB/SBB/CMP and register/immediate/memory PUSH/POP handlers to that reference, including registers,
flags, XMM0, memory, PC and ordered access/fault effects. MOV includes AL/AH,
REX byte registers, partial/zero-extending writes, immediate/ModRM/moffs forms,
prefix ordering and source/destination aliases. Its shared scalar primitives
operate on materialized native register values. Arithmetic covers all four widths,
six status flags, incoming carry/borrow, byte lanes, native immediates, CMP
without data writeback, and ordered read/write faults. PF uses independent
low-byte parity and AF uses widened nibble arithmetic in the reference;
production C macros are checked against an independent integer oracle.
AND/OR/XOR/TEST use the same scalar operands and ordered memory effects;
CF/OF clear, SF/ZF/PF follow the operand-width result, and AF is undefined.
TEST preserves its data destination. Native group/immediate forms share the
arithmetic decoder, including64-bit sign extension. ABI masks track logical
zero/one bits so a mask may discard unspecified register bits before use.
All sixteen native conditions refine the reference, including PF, through
CMOV, SETcc and direct branches. SETcc includes high-byte/REX destinations,
exact one-byte stores and write faults; CMOV retains eager read faults.
Native branch displacement decoding, PC wrap and ordinary NOPs are covered.
The encoder admits defined parity uses and rejects observations of undefined
flags/results, including16-bit SHLD/SHRD counts17..31. CL-count forms use the
actual count register, including destination aliases, and compile to BPF.
The AArch64 multiply/divide, conditional-select, extract/reverse/extend, shift/unary, logical-register, MOVK, move-immediate, register-move, all32 SIMD/GPR bit-transfer (FMOV), byte-vector reduction (CNT/UADDLV), conditional-compare (CCMP), ADD/SUB immediate/shifted-register/extended-register, NOP, ordinary-branch, scalar immediate-memory and LDP/STP signed-offset
families connect through their modules in `Refinement/`, including native
aliases, all raw NZCV predicates, ZR/SP separation including MOV destinations, legal extract immediates,
shifted source modifiers, exact NZCV updates and W zero-extension. Arithmetic NZCV uses width-sized operands
with independent signed/unsigned widened sums for overflow and carry. All eight
register extensions narrow at the operand size before extending and shifting.
Branch offsets are signed native bytes; both generated goto shapes preserve
the same PC choice, with W/ZR and tested-bit widths handled explicitly.
Scalar memory includes all unsigned and signed load widths, stores, signed
unscaled and unsigned scaled offsets, exact byte permissions/initialization,
ordered accesses and faults. Its handler theorem takes the admission witness
that SP alignment is valid; it does not insert a runtime alignment guard.
LDP/STP captures both load values before register writes and uses a4/8-byte
stride at W/X width. Pair events follow the selected architectural profile;
a second separate-store fault retains the first store. Duplicate LDP destinations
are constrained-unpredictable (including UNDEF/NOP) and fail source validation.

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
restatement of ISA semantics. `tools/check_reference_x86_scalar.py` adds concrete
MOV/prefix/byte-lane cases. `tools/check_x86_memory_widths.py` compiles the actual
C memory contract to BPF and checks access kind, address, width and count;
unaligned host accesses use alignment-one alias types and remain UBSan-checked.

For AArch64, send `isa: "aarch64"` to the same executable. Supply exactly four
little-endian native bytes, `registers` as X0..X30 followed by SP (32 words),
`flags` with NZCV in bits31..28, `vector0` as an unsigned128-bit word, `pc`
and the same explicit `memory` cells. Outputs use `vector0` in place of `xmm0`
and omit x86 segment bases. To access nonzero SIMD registers, also supply
`vectors` as exactly32 unsigned128-bit words V0..V31, with `vectors[0]` equal
to `vector0`; outputs preserve and return that complete bank. V0-only legacy
requests remain valid, but cannot access an omitted SIMD register. Arithmetic field31 denotes ZR, independently of SP.
`sp_alignment_check` selects the effective SCTLR.SA/SA0 setting and defaults
to Linux's enabled setting. When enabled, an SP-base transfer tests the incoming
SP's16-byte alignment, independently of its effective address; faults use
`sp_alignment`. `pair_single_access` selects FEAT_LSE2's one double-sized
architectural pair access; its default is false, matching Cortex-A72. Both
profile settings are preserved in outputs when supplied. The memory model is
sequential, with architectural events grouping the handler's byte operations.
The default ISA remains x86-64; `isa: "x86_64"` is also explicit.
