# Native simulator verification

Current [coverage and totals](../results/kprog_verification_20261107/README.md)
track each declared operation and token. The generic C-model O2 interface covers
53 x86 register/control/memory tokens and 71 ARM tokens across numeric bodies and emitted-return control; full raw ISA
and compiled-simulator closure continue.

Run the complete verification entry point on an x86-64 Linux host:

```sh
make -C kprog/formal check
```

It requires Lean/Elan, Python3, Rust/Cargo, a C compiler with UBSan,
clang18/LLVM18, GNU objdump, AArch64 cross-GCC and QEMU user emulation,
and the vendor/libbpf and vendor/linux-framework
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
shift, SHLD/SHRD, classic ROR, BMI2 and bit-operation register bodies. Its partial raw
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

Forty-one direct, ten generic and two branch token bodies have semantic
equality to their covered interpreter dispatch for arbitrary fields and
invocations. PUSH/POP register/immediate/memory forms compose full64 stack offsets,
partialSP writeback, old-source/post-increment destination addresses and ordered
observed guest-memory effects. The private-arena/native-memory permission
relation retains its explicit production interface. MOVBE load/store derive
raw effective addresses and compose generated reversal, native source bytes
and RSP/STACK destination writeback with ordered memory/fault effects. CMOV_MEM
and SETCC_MEM bind all16 conditions/PF, eager CMOV reads and false32 writeback,
with packed/whole displacements and exact observed guest effects. Ordinary
MOV_STORE_REG/IMM also compose full numeric-frame stores, native source byte
lanes and packed immediate fields through the same dispatcher/token interface.
Memory INC/DEC/NEG/NOT and classic ROR also compose their captured read,
generated result and flags, observed store and precise fault effects.
Memory CMP/TEST also compose packed/whole displacement fields, numeric
register operands and complete six-flag/read/fault effects.
Memory ADD/ADC/SUB/SBB/AND/OR/XOR/SHL/SHR/SAR/ROL compose the same
full-frame read/modify/write and fault law for immediate and register tokens.
Memory-source ADD/ADC/SUB/SBB/AND/OR/XOR/IMUL also retain captured
addresses, full numeric destination writeback, defined flags and read/fault
effects through the same extended dispatcher/token interface.
Three-operand memory IMUL also composes its packed low32 immediate and
signed high32 displacement, absent/exact memory-width byte, sign extension,
CF/OF and full numeric destination through the same dispatcher/token step.
Their field binding carries packed-immediate/full-register displacement,
low source lanes and CL counting; source-lane normalization and physical
arena/permission correspondence remain explicit production interfaces. ARM numeric3/4
compose their conditional immediate-alias laws through unified ExecBinding,
source and invocation emission.
LOAD/STORE/LDRSB/LDRSH/LDRSW/STLXR have direct-body equality and canonical
observed-step composition with the same memory, monitor and platform witnesses.
The site-indexed interface carries each visit's explicit exclusive outcome.
Fifty-two scalar direct bodies also compose NOP/address/move/keep, register ALU,
shifts, multiply/unary, extract/reverse/extend/bitfield and flag/conditional
families through the same observed step and established W/X field domain.
Nine pair/vector tokens connect pair width, fixed D/Q access, FMOV bank/direction
and reduction AUX through direct-body equality and the same observed step.
RET_TO also has finite-switch/route/body equality and canonical invocation-step
composition under the shared code-label and authenticated outer-LR frame.
Its physical value/CB writes have finite C checks; full exit ABI and compiler
correspondence retain their explicit interfaces. ADD_IMM/SUB_IMM/ALU_IMM have W/X numeric
direct-body equality and canonical-step composition under the shared
field/provenance/platform bindings.
Safety work is generic per
simulator and token; historical per-program proofs are frozen and excluded
from the argument. Remaining tokens and native-link/compiler preservation
are being connected through [generic composition](../tv/Composition.lean).

The trusted boundary includes Lean's kernel/toolchain and bitvector reduction
bridge (`Lean.ofReduceBool`), the contract generation
and C/Lean correspondence, native decoding/encoding, and the C/BPF compilers.
Initial ABI, provenance/permissions, physical exclusive monitor/order/site
identity and runtime artifact binding must be established by their callers or
platform certificates. A generated contract is an implementation model, not a
second ISA. Finite hardware/oracle checks complement the universal theorems.

[The dated verification results](../results/kprog_verification_20261107/README.md)
retain exact source hashes, commands, original failures and subsequent checks.
They distinguish focused proofs/oracles from complete make-check outcomes.
[Artifact validation](../tv/README.md) records the separate end-to-end work.

The LEA raw register-frame core and address normalization are proved; its
production-field/dispatcher/O2 connection uses the tested correction patch
linked by the current coverage report.

Canonical ARM thread-pointer reads cover native MRS TPIDR_EL1/EL2 and all32
Xt fields. `thread_pointer_reads` supplies the resolved CPU/EL access profile;
permitted reads retain full64 values, XZR discards the value, and denied reads
retain the incoming state with an identified system-register fault. The generic
register laws connect a permitted MRS to MOV-immediate and the selected
per-CPU value; kind4 CPU/profile/relocation binding remains its caller interface.

The same entry point checks the generic kind4 per-CPU MRS native-link law and
its existing generic dependencies. It composes the emitted four-byte word and
final-code copy with canonical full-state/effect/fault preservation. The current
CPU/profile, producer field/PC, executable lifetime and complete ABI/compiler
bindings remain the surrounding production interfaces.

The MOV memory oracle compares ordinary, scalar and signed loads with real
x86 instructions over numeric RSP/STACK frames and ABI pointers. Stack MOVSX
applies source-width sign extension; ABI and live XDP pointer loads to RSP
normalize the loaded native value through the numeric stack writer.
