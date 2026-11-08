# Native simulator verification

Safety uses two facts: the stock verifier accepts B, and B faithfully simulates
P. This directory proves generic simulator and token laws; native-link
preservation lives in [tv/](../tv/). The current
[coverage ledger](../results/kprog_verification_20261107/README.md) records every
operation/token, its exact theorem domain, replay source epoch and remaining
implementation interface. It currently records 72 x86-64 and 71 AArch64 C-model token
body equalities, plus two returning-helper interface equalities. Full ISA and compiled-simulator closure remain active work.

## Specification and proof scope

The reference ISA is defined once in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean), with shared
[memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean).
These definitions cite Intel/Arm sources and are independent of generated
implementation contracts. [ReferenceMain.lean](ReferenceMain.lean) executes
these same definitions through JSON for hardware and artifact comparisons.

Handler/dispatcher and specialized-token laws compose modeled registers,
PC, ordered memory effects, faults and defined architectural outputs under
their stated operand, address, access and platform premises. Undefined outputs
use the reference step's observation mask; uninitialized memory has arbitrary
values. The theorem statements and coverage rows give each operation's domain.
The x86 pointer bodies share the extended dispatcher and refine resolved moves
for all sixteen registers, including the RSP coordinate. Native symbol/helper
address transport remains an explicit interface. Four memory-call token bodies
include sequential byte effects and the fresh caller-clobber frame; their
native call/ABI and physical memory relations remain explicit. Two helper token
wrappers prove full64-bit sparse ID routing, pre-call capture, result/memory/events
and fresh caller/callee-frame laws over a returning helper-effect interface;
typed arguments, native ABI and successful tail transfer remain explicit. Internal
RET includes its finite continuation switch; outer invocation/return-slot,
physical memory/provenance and C/compiler correspondence remain explicit.

Architectural profiles are stated in the reference and theorem premises:
x86 near control uses 48/57-bit canonical addresses with CET disabled, and
LEAVE uses the LASS-disabled frame profile. ARM uses the Cortex-A72 base
profile with explicit SP alignment, pair-access granularity and exclusive
monitor/order inputs. Each dynamic exclusive attempt receives its own
possible failure outcome. Concurrent memory behavior retains its physical
profile obligations. The safety argument uses generic simulator, token and
link-transformation theorems; historical per-program artifacts stay frozen.

## Trusted boundary

The boundary includes Lean's kernel/toolchain and executable reduction bridge
(`Lean.ofReduceBool`), contract generation and C/Lean correspondence, native
decoding/encoding, and the C/BPF compilation path. Entry ABI, physical
memory/provenance, exclusive monitor/order/site identity and native address
transport are caller/platform interfaces. The ledger distinguishes proved
model laws, finite oracle/hardware evidence and complete-check outcomes.
[Composition](../tv/Composition.lean) and the
[artifact work](../tv/README.md) track the generic link/compiler obligations.

## Run

```sh
make -C kprog/formal check
```

Use an x86-64 Linux host with BMI1/BMI2 and POPCNT, Lean/Elan, Python3,
Rust/Cargo, a C compiler with UBSan, clang 18/LLVM 18, GNU objdump,
AArch64 cross-GCC, QEMU user emulation, and the vendor/libbpf and
vendor/linux-framework submodules. This entry point builds all Lean modules,
checks generated contracts and proof hygiene, and runs retained semantic C
oracles and executable-reference comparisons. Existing build caches are reused.
The dated ledger retains exact source hashes, commands and original outcomes.

## Layout

- [Reference/](KProgFormal/Reference/): canonical ISA and memory specifications.
- [contracts/](contracts/), [generated/](generated/) and
  [Generated/](KProgFormal/Generated/): JSON inputs and generated C/Lean contracts.
- [KProgFormal/](KProgFormal/) and [Refinement/](KProgFormal/Refinement/):
  primitives, full-state refinements, dispatcher/token and environment laws.
- [oracles/](oracles/): retained semantic C oracles.
- [tools/](tools/): generators and semantic/source tooling.
  build/ and .lake/ hold incremental outputs.
