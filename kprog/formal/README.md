# Native simulator verification

Safety uses two facts: the stock verifier accepts B, and B faithfully simulates
P. This directory proves generic simulator and token laws; native-link
preservation lives in [tv/](../tv/). The current
[coverage ledger](../results/kprog_verification_20261107/README.md) records every
operation/token, its exact theorem domain, replay source epoch and remaining
implementation interface. It currently records71 x86-64 complete current C-model token-body equalities and73 of74
AArch64 operation bodies, plus an explicit current RET exit-contract interface
and two returning-helper interface equalities. LDADD/STADD0x46, LDSET/STSET0x47 and LDCLR/STCLR0x48 share canonical atomic access, typed success laws and unified token bindings. Additional helper macro-routing and two-mode RET control laws retain their
parametric/source bindings and do not increase the71 complete current x86 bodies.
Full ISA and compiled-simulator closure remain active work. The production DIV signed AUX1 branch has its canonical signed reference and554 semantic scenes. Signed/unsigned AUXbit0 dispatch and arbitrary fresh flags compose through the generic step/token laws. The current signed DIV raw/tag body directly executes all four widths of word arithmetic, the complete restoring loop/zero-high fast path, word-limit comparison and unsigned sign restoration, composing captured operands and whole state/fresh flags through current dispatcher/O2 laws. Both unsigned and signed domains now meet the concrete C-model token category used by the other complete rows. C-source extraction, compiled-B and physical/ABI transport remain explicit interfaces.

`X86RemainingTokenO2.StackRelease` adds seventeen universal component laws for
internal RET lifetime: ordered fresh-byte writes over the released signed
interval, clearing every declared below-SP word tag/valid field, preserving
pointer/scalar payloads and live cells, pre-release saved-word capture and
selected/default token transport. Sparse declared-word lists and arbitrary fresh
bytes are quantified. Source owned-read/forwarding, signed-coordinate validity,
live-stack/native-memory representation and compiler/physical transport remain
explicit interfaces; RET retains its partial category.

Nine additional owned-read laws cover full64 scalar forwarding, unaligned byte
assembly, saved-word projection, live-read preservation and byte reads after
reallocation. Source byte/scalar coherence supplies the saved-read premise;
computed index, union memory and physical/compiler transport retain their
explicit source profile.

Twelve source-coordinate/coherence laws connect the actual wrapping generated
stack index, signed raw-SP coordinate and native byte addresses. An allocated
eight-byte return interval derives exact signed RSP advance and supplies the
source read projection. The live byte/scalar relation survives release and
composes current source RET with the reference step and selected/default token.
C/compiler establishment of that relation, producer mode and physical control
transport remain explicit interfaces.

`ControlABI.ArmReturn` adds twelve current ARM RET component laws: raw target
decides RETURN-tag invocation or CODE-tag finite continuation/default, with
complete scratch capture and tag-aware X0 numeric materialization. Internal
branches refine the reference branch step in the stated numeric image, and
outer source callee/SP guards derive the native ABI contract. Actual producer
operand/table extraction and physical LR/code-PC/compiler transport remain
explicit; ARM RET retains its partial category.

Actual compiled scalar coverage is16 of75 x86 operations across158 combined
units, including two partial returning-helper units. Classic ROR adds five
width/lane units with arbitrary values, counts and fresh inputs; actual BPF
execution preserves memory/exclusive state and consumes the23 captured input
positions. Whole flags/tag/frame and physical/compiler embedding retain their
explicit simulator interfaces.

ADD_IMM contributes five actual scalar units for8-bit low/high lanes and16/32/64-bit
writeback, with the encoded imm32 sign extension at64-bit width. Seven execution
laws quantify every operand, immediate, fresh stream and initial visit, preserving
memory/exclusive state, consuming23 inputs and reaching the stated result.
The complete flags/tag/register frame and physical/compiler embedding remain
explicit interfaces.

ADD_REG adds seven actual scalar units: all four low/high byte-lane pairs and
16/32/64-bit writeback. Nine execution laws quantify every operand and fresh
stream and preserve memory/exclusive state with23 consumed inputs. Complete
flags/tag/GPR-frame, operand mapping and physical/compiler transport remain
explicit interfaces.

ARM raw-register refinement covers NOP, MOV_IMM and MOVK across all32 native
destination fields, raw64-bit register values and the full byte-tag domain.
Thirteen laws derive concrete cell reads/writes, STACK/RETURN materialization,
XZR discard and one opcode/field-bound dispatcher-step theorem. The complete
projected architectural state matches the single AArch64 reference. Entry
origin identity, C extraction/union access and physical/compiler transport
remain explicit. These laws are independent of stack-forwarding storage.

ARM raw multiply/divide adds eight operations to the preceding three gates,
bringing raw handler/dispatcher coverage to11/74. Concrete tagged operand reads,
UDIV source narrowing and width/tag writeback compose through the production
multiply arm and one eleven-operation step theorem. Native long/high products
retain their X-width domain; unused SRC3 bytes keep their full byte domain.
Ten new laws plus the13 preceding laws compile and audit together. Entry,
C extraction/union and physical/compiler transport remain interfaces.

ARM raw SHIFT_IMM/SHIFT_REG/MVN/NEG extends the unified step to15/74.
Seventeen new laws plus23 prior laws audit and compile with module/root0.
SHIFT binds the whole AUX kind0..3 used by its C switch and producer; the
numerical handler, dispatcher and scalar token also decode the complete AUX. Unary consumes
AUX byte1/byte2, retains arbitrary unused bytes and omitted-modifier amounts,
and preserves the native NEG/MVN modifier domains. Complete raw words/tags,
register aliases/XZR and architectural image compose independently of B layout.
Entry, C extraction/union and physical/compiler transport remain interfaces.

ARM raw EXTR/REV/REV16/SXTB/SXTH/SXTW/CNEG extends the unified step to22/74.
Fourteen new laws and40 prior laws audit with module/root0 and sorryAx0.
Concrete operand/tag materialization, EXTR input narrowing, CNEG input NZCV
and scalarizing width/tag writes preserve the complete architectural image.
Production dispatcher equality covers arbitrary unused byte fields, including
NONE255, and immediate values for the rows that ignore them. Native EXTR
amount and CNEG alias-condition domains remain explicit. Entry/C extraction/
union and physical/compiler transport remain interfaces independent of B layout.

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
records63 agreeing operation labels and four ANDN/BZHI model-stopped labels
in the current selected comparison. Historical source epochs retain their observations. ACL28.7 retains72 memory-SHIFTX PC-1 observations
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
The existing x86/ARM callee-tag/value/SP exit predicates now derive the
quantified ABI contract and exact normal-return value/frame. The x86 RET-token
guard and native-return/JIT-result laws compose this contract under explicit
snapshot, stack-origin and tag-projection inputs. Internal return stack erasure,
ARM return-mode/LR binding, native-to-B entry and C/compiler/physical transport
remain explicit.

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
Two returning helper scalar units (lookup1/ktime5) retain argument/result,
complete helper memory/effects and independent clobbers under a matched platform
contract; full helper registry/tag/frame/native ABI/compiler transport remains
explicit. These are partial helper-body units, not a completed token family.
RORX adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
MOV_IMM adds5 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
BZHI adds2 scalar width/writeback units with width32 zero extension;
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

ARM native-marker and paired-register fields likewise compose with whole-X/PC4
recovery, X5/XZR semantics and the actual raw fault state. Production site/frame
and B ordered-prefix correspondence remain explicit.

BPFPlatform also models seven kernel-internal nonarena PROBE_MEM/SX load
codes with full success/fault/frame and decoded-step laws. Actual conversion,
physical guard and O3/native fault-prefix correspondence remain explicit.

## Layout

- [Reference/](KProgFormal/Reference/): canonical ISA and memory specifications.
- [contracts/](contracts/), [generated/](generated/) and
  [Generated/](KProgFormal/Generated/): JSON inputs and generated C/Lean contracts.
- [KProgFormal/](KProgFormal/) and [Refinement/](KProgFormal/Refinement/):
  primitives, full-state refinements, dispatcher/token and environment laws.
- [oracles/](oracles/): retained semantic C oracles.
- [tools/](tools/): generators and semantic tooling.
  build/ and .lake/ hold incremental outputs.

Canonical ARM LDP recovery also proves first-element, second-element and
FEAT_LSE2 double-width fault paths, retaining ordered read events and clearing
both whole X destinations from the input frame before PC4 continuation.
Physical site/frame, pre/post writeback and compiled-B/O3 bindings remain explicit.

Kind4 per-CPU final-byte laws compose the selected entered thread-pointer
profile with canonical X10 materialization, preserving the full state and
empty trace through the final copied word. Physical CPU/profile and C/compiler
entry/copy/lifetime bindings remain explicit.

LEA adds12 scalar width/scale units with canonical writeValue, complete memory
and exclusive-index preservation and actual decoded execution. Field/address
mapping, pointer/RSP and physical native frame/compiler embedding remain explicit.
The current lookup1/ktime5 units include their decoded private byte store at
R10-8: the full execution has exact scratch memory and ordered store event,
under explicit successful-store/slot ownership premises. Prefix and suffix
composition retains the complete helper result and effects.
