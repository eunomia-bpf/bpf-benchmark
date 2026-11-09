# Native simulator verification

Safety uses two facts: the stock verifier accepts B, and B faithfully simulates
P. This directory proves generic simulator and token laws; native-link
preservation lives in [tv/](../tv/). The current
[coverage ledger](../results/kprog_verification_20261107/README.md) records every
operation/token, its exact theorem domain, replay source epoch and remaining
implementation interface. It currently records72 x86-64 C-model token-body equalities and74 of74
AArch64 operation bodies, plus two returning-helper interface equalities. LDADD/STADD0x46, LDSET/STSET0x47 and LDCLR/STCLR0x48 share canonical atomic access, typed success laws and unified token bindings. Full ISA and compiled-simulator closure remain active work.

## Specification and proof scope

The reference ISA is defined once in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean), with shared
[memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean).
These definitions cite Intel/Arm sources and are independent of generated
implementation contracts. [ReferenceMain.lean](ReferenceMain.lean) executes
these same definitions through JSON for hardware and artifact comparisons.
The [Arm ASL state comparison](../results/kprog_verification_20261107/reference-arm-asl.md)
records5016 agreeing observations across74 operation labels and explicit STLXR
monitor profiles. LDADD adds1344 agreeing cases and stated atomic/compiler premises. It retains its source/binary
identities and platform premises alongside the [x86 Sail comparison](../results/kprog_verification_20261107/reference-x86-sail.md),
which, together with the [direct ACL2 comparison](../results/kprog_verification_20261107/reference-x86-acl2.md),
records58 agreeing operation labels, seven model-stopped labels and two explicit
state-difference labels. ACL28.7 retains72 memory-SHIFTX PC-1 observations
with matching GPR/flags/XMM/memory, plus48 REP element/whole-step differences.
Original source/certificate diagnostics and separate CPU evidence remain recorded.

Handler/dispatcher and specialized-token laws compose modeled registers,
PC, ordered memory effects, faults and defined architectural outputs under
their stated operand, address, access and platform premises. Undefined outputs
use the reference step's observation mask; uninitialized memory has arbitrary
values. The theorem statements and coverage rows give each operation's domain.
FreshAux composes the production ANDN/BZHI independent PF/AF choices, proves
complete local output realization and transports a two-position fresh stream.
Global incoming-state/other undefined-output and compiler/ABI transport remain
explicit interfaces.
The x86 pointer bodies share the extended dispatcher and refine resolved moves
for all sixteen registers, including the RSP coordinate. Native symbol/helper
address transport remains an explicit interface. Four memory-call token bodies
include sequential byte effects and the fresh caller-clobber frame; their
native call/ABI and physical memory relations remain explicit. Two helper token
wrappers prove full64-bit sparse ID routing, pre-call capture, result/memory/events
and fresh caller/callee-frame laws over a returning helper-effect interface;
typed arguments, native ABI and successful tail transfer remain explicit. Internal RET includes a total label/unresolved continuation result, with
complete captured read/SP advance in both alternatives. O2 covers its default;
O4 carries CALL -1 decode/error semantics and derives case membership for
accepted entered states under explicit compiled-edge/stock rejection premises.
The shared architectural-fault prefix also has actual byte decode/execution
and a complete scratch/memory/ghost frame at every linked instruction offset,
under literal-copy, entry/reachability, NULL-unmapped and verifier premises.
Actual returning BPF CALL laws also retain the pre-call argument snapshot,
full-width resolved identity, result/memory/effects and caller/callee/ghost frame
through identity-preserving resolution; physical/native ABI and C/compiler
correspondence remain explicit.
Outer invocation/return-slot, physical memory/provenance, native-to-B entry
coverage and C/compiler correspondence remain explicit.

Architectural profiles are stated in the reference and theorem premises:
x86 near control uses 48/57-bit canonical addresses with CET disabled, and
LEAVE uses the LASS-disabled frame profile. ARM uses the Cortex-A72 base
profile with explicit SP alignment, pair-access granularity and exclusive
monitor/order inputs. Each dynamic exclusive attempt receives its own
possible failure outcome. Concurrent memory behavior retains its physical
profile obligations. The safety argument uses generic simulator, token and
link-transformation theorems; historical per-program artifacts stay frozen.

The typed byte atomic kfunc C model now composes ADD/SET/CLR operand truncation,
old-value return and one-byte state commit through the unified dispatcher.
Primitive ordering, kfunc identity/call ABI and compiler transport remain explicit.

The read-only helper return also composes its valid-cell stack-tag map with the
full return observation. Its index origin and signed below-SP policy are proved;
physical frame ownership, helper effects/provenance and ABI remain explicit.

## Trusted boundary

The boundary includes Lean's kernel/toolchain and executable reduction bridge
(`Lean.ofReduceBool`), contract generation and C/Lean correspondence, native
decoding/encoding, and the C/BPF compilation path. Entry ABI, physical
memory/provenance, exclusive monitor/order/site identity and native address
transport are caller/platform interfaces. The ledger distinguishes proved
model laws, finite oracle/hardware evidence and complete-check outcomes.
The generic readonly finite-case law also composes object identity and shifted
aliases with canonical memory reads; final byte transfer transports its frozen
image premise. Every permitted canonical guest write preserves the frozen
image and its write permissions. Physical symbol/map lifetime, helper/platform
state effects and C/compiler transport stay explicit.
The private-spill projection also proves actual decoded STXDW/LDXDW pair execution,
whole BPF register/input-frame and public-memory preservation, and exact owned
event erasure for every signed16-bit offset. Finite disjoint-write histories
preserve the saved read; actual decoded spill/arbitrary finite body/reload
composition restores the captured word and preserves the other body state
and ordered projected trace. Actual compiler ownership/layout, body control
and slot/frame liveness plus physical frame/ABI correspondence remain explicit.
[Composition](../tv/Composition.lean) and the
[artifact work](../tv/README.md) track the generic link/compiler obligations.

The existing X86StackIndex module also proves inactive stack-ghost payload
initialization/replacement is erased through finite save/invalidate/frame/clear
histories and complete lookup traversals, retaining active STACK pointers.
This metadata C-model law leaves C definedness and compiler/physical ABI explicit.

Arm64NumericAddress also proves sparse tag-table store/clear/copy preservation
under explicit initial-support and producer-domain coverage premises, plus
packed-word whole-byte-table store refinement. Actual CFG producer soundness
and C/clang storage correspondence remain explicit interfaces.

## Run

```sh
make -C kprog/formal check
```

Use an x86-64 Linux host with BMI1/BMI2 and POPCNT, Lean/Elan, Python3,
Rust/Cargo, a C compiler with UBSan, clang 18/LLVM 18, GNU objdump,
AArch64 cross-GCC, QEMU user emulation, and the vendor/libbpf and
vendor/linux-framework submodules. This entry point builds all Lean modules,
checks generated contracts and proof hygiene, and runs retained semantic C
oracles and executable-reference comparisons. The existing compiled CMOV unit covers all16 conditions and16/32/64 widths
through decoded clang bytes, arbitrary fresh inputs and whole-memory preservation;
The same fixture proves all32 SETCC condition/low-high-byte units and their actual
decoded executions, with arbitrary old value/flags/fresh inputs and whole-memory preservation;
BSWAP adds both32/64-bit widths with complete arbitrary BPF register/memory/ghost-frame
preservation and actual decoded executions. Their scalar-register mapping,
initial scratch state and invocation interface remain explicit. MOV_REG adds7 scalar byte-lane/width units with arbitrary whole memory and both
ghost indices; pointer/RSP frame and physical ABI embedding remain explicit.
MOVZX/MOVSX add15 scalar source-lane/width units with canonical extension,
whole memory and both ghost indices; register/tag frame and ABI embedding
remain explicit.
SHIFTX adds6 scalar width/count units with arbitrary counts and both SARX
control paths; complete register/flag/tag frame and ABI embedding remain
explicit.
UD2 adds exact0f0b decode and an unchanged-state #UD terminal, plus the
actual shared architectural-fault byte prefix and generic O2/O4 transport.
Its12 ACL2 observations retain the explicit model RIP+2 profile difference.
Compiler/link/entered-state and stock-soundness premises remain explicit.
ANDN adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
POPCNT adds3 scalar width/writeback units, with high48 preservation at16
bits and zero extension at32 bits; full flags/register/tag frame and ABI
embedding remain explicit.
Existing build caches are reused. Generator checks compare locked numeric contracts
and generated artifacts; compiled oracles exercise the current production bodies.
The dated ledger retains exact source hashes, commands and original outcomes.

Caller-owned helper frames preserve exact saved reads through disjoint memory
effects; actual returning BPF CALL/LDXDW Execution retains the full helper/read
trace. Selected helper footprint, pointer lifetime and native ABI stay explicit.

Native x86 CALL/RET laws account for the actual RSP-8 return-slot write,
separate caller and return-slot footprints, saved PC and unsigned SP release.
Selected native helper stack restoration and physical native-to-B ABI remain explicit.

Conditional scalar read-recovery laws above the raw ISA account for stock-frame
x86/ARM zero-and-resume, including nativeX5/XZR and the raw fault prefix.
Actual site/table/exception-class/B-observation and O3 correspondence stay open.

x86 exception-table encoding also composes saved-GPR offsets, fixup fields and
relative final-PC entries with whole-register/PC recovery. Actual frame/site/table
lifetime and B/physical fault correspondence remain explicit.

## Layout

- [Reference/](KProgFormal/Reference/): canonical ISA and memory specifications.
- [contracts/](contracts/), [generated/](generated/) and
  [Generated/](KProgFormal/Generated/): JSON inputs and generated C/Lean contracts.
- [KProgFormal/](KProgFormal/) and [Refinement/](KProgFormal/Refinement/):
  primitives, full-state refinements, dispatcher/token and environment laws.
- [oracles/](oracles/): retained semantic C oracles.
- [tools/](tools/): generators and semantic tooling.
  build/ and .lake/ hold incremental outputs.
