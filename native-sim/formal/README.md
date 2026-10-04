# Native-simulator formal model

This directory contains the first machine-checked refinement slice shared by
the x86-64 and AArch64 native simulators. Run it with:

```sh
make check
```

`KProgFormal.TagErasure` models a bounded fragment drawn from the simulators:
a 64-bit move, a pointer-shaped 64-bit add, an x86-shaped scalarizing integer
multiply-immediate, and a 64-bit load of the packet or packet-end pointer from
the simulator entry ABI. It proves for any sequence of those abstract
operations that:

1. erasing verifier-facing provenance tags yields the same bits as a pure
   modulo-2^64 architectural execution; and
2. tag transitions follow a separately declared provenance policy.

The pointer-add transition is generated from `ptr_add_spec.json` into both the
Lean model and the C macro used by the x86-64 non-stack LEA and AArch64
non-scalar ADD handler branches. The entry-ABI provenance policy is likewise
generated from `abi_load_spec.json`: it distinguishes XDP from `__sk_buff`,
maps only the architecture-independent `data` and `data_end` offsets to packet
tags, and scalarizes all other 64-bit ABI loads. Compile-time assertions bind
those offsets to both C ABI structs, while the Lean theorem compares the
generated transition against an independently written tag specification.
The complete AArch64 condition-code table is generated from
`arm64_cond_spec.json` into the Lean model and the C branch handler. Lean proves
that all 15 supported predicates select the same next program counter as an
independent architectural condition specification, for either branch
direction.
The AArch64 simulator width encodings and NZCV flag transitions are likewise
generated. `arm64_width_spec.json` produces the `KPROG_ARM64_WIDTH_*` /
`KPROG_ARM64_APPLY_WIDTH` macros and a Lean `GeneratedArm64Width` module; the
central `arm64_width_mask` / `arm64_width_bits` / `arm64_sign_bit` /
`arm64_apply_width` helpers now delegate to those macros, so the AArch64
simulator and the proof contract share one forwarded source for masks, sign
bits, and narrowing. `arm64_flags_spec.json` produces
`KPROG_ARM64_SET_{ADD,SUB,LOGIC}_FLAGS` and Lean
`GeneratedArm64Flags.apply{Add,Sub,Logic}`. Lean proves each generated
transition equal to an independently written NZCV statement over already
width-narrowed operands (ADD/SUB: N=sign, Z=zero, C=carry-out or not-borrow,
V=signed overflow; logical: C=V=0), with concrete theorems pinning an
AArch64 `0xffffffffffffffff + 1` carry/zero, a `0 + 0` subtract carry, a
32-bit `0x7fffffff + 1` overflow, a `1 - 2` borrow, and a logical result that
clears carry/overflow. The previously hand-written
`ARM64_SIM_L_SET_{ADD,SUB,LOGIC}_FLAGS` macros now delegate to the generated
primitives. A host C cross-check (`test_arm64_flags_host.c`) validates the
generated macros against an independent `__int128` carry/overflow oracle over
explicit boundary vectors and a fixed-seed 20000-case sweep of all four
widths; `make check` runs it. Instruction decoding, condition-to-next-PC
selection beyond the earlier condition contract, and native bytes remain
boundaries.
The generic AArch64 ALU handler now has a composed state-transition theorem as
well. `arm64_alu_handler_spec.json` generates the exact C/Lean predicate that
selects the provenance-preserving path only for 64-bit ADD from a non-scalar
source into a non-SP destination. `arm64_alu_handler_refines` proves that this
path, the generated ALU result, pointer-add bits/tag policy, width narrowing,
GPR/SP/XZR/NONE write behavior, and scalarization on every other arithmetic
path agree with an independently enumerated handler specification for all six
ALU operations, four modeled widths, four destination classes, and all modeled
provenance tags. `arm64_alu_operand_handler_refines` now closes its former
free-RHS premise: immediate form selects the raw immediate, while register form
applies any of the eleven proved source modifiers before the full handler
transition. This composition is universal over both forms, operations, widths,
destinations, tags, operands, modifiers, and shifts; a 5632-case host oracle
checks the shared C selector. The theorem still starts after opcode, width,
register value/tag, destination class, and packed-AUX modifier/shift selection;
the parser, C register switch, those selections, and native bytes remain
boundaries. The earlier path-only host cross-check exhausts 168 numeric
selection cases, including unsupported width/opcode values.
The flag-setting arithmetic handlers have a second composed contract.
`arm64_flag_handler_spec.json` generates the ADD/SUB family dispatch used by
the real ADDS/SUBS and CMN/CMP C branches and the matching Lean step.
`arm64_flag_handler_refines` proves two modes against an independent statement:
ADDS/SUBS take one generated result/flag step, perform width-aware scalarizing
writeback (including discarded XZR/NONE writes), and replace NZCV; CMN/CMP
replace the same NZCV while preserving the complete modeled GPR/SP state.
The theorem begins after operand and source-modifier selection. A parallel
logical flag-handler contract routes the real ANDS/BICS/TST/TST-BIC branches
through one generated AND/BIC result-plus-NZCV step.
`arm64_logic_flag_handler_refines` proves width-aware scalarizing writeback for
ANDS/BICS, including discarded XZR/NONE results, and proves that TST/TST-BIC
replace NZCV while preserving the complete modeled GPR/SP state. It covers
both logical families, all modeled widths and destinations, arbitrary operands,
and arbitrary incoming state. A separate 64-case host oracle checks the shared
C step over boundary operands. Both handler theorems begin after typed operand,
width, destination, and source-modifier selection. Conditional compare now has
its own composed contract: `arm64_ccmp_handler_refines` proves that all 15
supported conditions inspect the incoming NZCV, choose SUB-produced flags on
the true path or immediate NZCV[3:0] on the false path, and preserve the
complete modeled GPR/SP state. Its 122880-case host oracle exhausts incoming
flag combinations, supported conditions, widths, boundary operands, and all
4-bit fallbacks. The theorem begins after operand/register selection and AUX
condition/fallback decoding; those selections, the C register switch, and
native bytes remain separate obligations.
The supported x86 condition-code table is likewise generated from
`x86_cond_spec.json` into the C simulator predicate and Lean. Lean proves the
same next-PC refinement for arbitrary flags and branch targets; parity
conditions are outside the accepted simulator subset.
The x86 condition-to-next-PC refinement is additionally bridged to the emitted
code: `generate_x86_branch_emit_spec.py` emits `KPROG_X86_BRANCH_BACKWARD`, the
address-ordering test the simulator's `X86_SIM_X86_JCC_IMPL` now routes its
backward-edge choice through (forward edge: `if (taken) goto target;` with a
fall-through; backward edge: `if (!taken) goto fallthrough; goto target;`).
`X86BranchEmit.lean` proves the emitted shape selects exactly `branchPc`, that
the two shapes select the same next PC (`x86_branch_emit_shape_irrelevant`, so
the direction only decides *how* the jump is written), and that a taken branch
reaches the target and a not-taken branch falls through for either shape — the
exact x86 analogue of the AArch64 emitted-shape bridge. Its host cross-check
(90 cases) pins the direction to an independent ordering oracle including the
equality boundary, and an 1827-case sim-header route oracle drives the real
`X86_SIM_X86_JCC` macro over every accepted and unsupported condition code, both
directions, and an equal-address edge, comparing the selected next PC against
the architectural model.
The legal x86 width encodings, masks, bit counts, narrowing, and zero/sign
observations are generated into the actual C helpers and Lean. Lean checks
their per-width model against an independent enumeration, while C static
assertions bind the numeric encodings. The x86 logical-result flag
transition is also generated into C and Lean. Its
composition theorem covers `CF=OF=0`, `ZF=zero`, and `SF=sign` through the
condition-to-next-PC decision using those observations.
The x86 subtraction flag transition is generated into the central C handler
and Lean. For already narrowed operands/result and a width sign mask, Lean
checks carry/borrow, zero, sign, and signed-overflow flags against an
independent specification and composes them through the condition-to-next-PC
theorem.
The x86 addition flag transition follows the same binding: for arbitrary
already-narrowed operands/result and a sign mask, the shared C/Lean contract
defines carry, zero, sign, and signed overflow and composes them through the
next-PC theorem. It does not prove that the supplied result was produced by
architectural addition.
All five x86 binary SBB operand-form handlers now obtain `a-b-borrow` from one shared
C/Lean expression contract. Lean proves its 64-bit modular result and the
per-width narrowing of that result against independent specifications. This
closes the earlier supplied-result premise for those handler expressions. A
separate generated SBB flag contract covers borrow-in, zero, sign, and overflow
and composes the result/narrowing layers as well as the next-PC decision. Its
overflow test compares the original operands with the final result; using the
wrapped `b+borrow` value is incorrect at boundaries such as 8-bit
`0-127-1=-128`. Decoder selection and sign-mask derivation remain open.
The five x86 ADC binary operand forms use a dedicated generated result and
flag contract. This preserves carry-in through width overflow instead of
folding it into an ordinary ADD operand, and Lean composes modular
`a+b+carry`, per-width narrowing, ADC flags, and next-PC. Decoder selection and
sign-mask derivation remain outside the theorem.
Plain ADD in the central ALU result helper is the zero-carry specialization of
the same generated modular-addition contract. Lean composes that concrete
result, per-width narrowing, and the existing ADD flag transition, eliminating
ADD's earlier free-result premise while retaining decoder/compiler boundaries.
Plain SUB in the central ALU result helper similarly specializes the generated
SBB result contract to `borrow=false`. Lean composes that concrete result,
per-width narrowing, the width-derived sign mask, and the SUB flag transition;
comparison instructions and decoder/compiler boundaries are not covered by
this central-helper theorem. The five compare operand forms separately use the
same generated zero-borrow result and SUB flags contracts; Lean composes that
width-aware compare transition through the condition-to-next-PC decision.
The same generated width contract now supplies the sign-bit mask used by the
C ADD, SUB, ADC, and SBB flag wrappers. The width-aware ADD, ADC, and SBB step
theorems derive that mask from operand width rather than accepting a free
`sign` argument, and Lean checks that mask testing equals the independent sign
observation for every legal width. Decoder-to-handler and C-to-Lean language
correspondence remain boundaries.
The 16 accepted ALU mnemonics and numeric operation codes are generated into
the proof-artifact encoder's Python mapping, the C simulator constants, and
Lean. Lean checks both fields against an independent enumeration. This binds an
already parsed mnemonic to the C ALU code consumed by the handlers; objdump,
assembly parsing, operand-form selection, and handler semantics outside the
separately proved operations remain boundaries.
INC and DEC in the central result helper specialize the generated ADD and SBB
contracts to one and zero carry/borrow. Lean composes each modular result with
width narrowing, the generated ADD/SUB flags, explicit preservation of the
incoming CF, and condition-to-next-PC. This covers register and memory unary
handler values, but not memory access/store or decoder selection.
NEG likewise specializes the generated SBB result to `0-a` with no incoming
borrow and composes the SUB flags through next-PC. Unlike INC/DEC, its CF is
the architectural borrow from zero rather than a preserved input flag; memory
access/store and decoder selection remain outside the theorem.
NOT uses a generated bitwise-result and flag-preservation contract in the
central C handlers and Lean. Lean proves its width-narrowed result and that all
four incoming flags, including flags observed by the next condition, remain
unchanged. Register and memory-unary values are covered; memory access/store,
operand selection, and native compilation remain boundaries.
The x86 shift-count mask is generated into the central C helper and Lean.
Lean proves that its bit mask equals the architectural modulo-32 count for
8/16/32-bit operands and modulo-64 count for 64-bit operands, and proves the
corresponding count bound. Shift results and flags remain separate obligations.
SHL, SHR, SAR, and ROL results are generated into the central C result helper
and Lean. The independent Lean specification uses fixed-width bit vectors and
checks every width and masked count, including narrowing before SHR and
width-local sign fill for SAR. This fixes the prior narrow-width SHR/SAR result
errors. Operand selection, writeback, flags, and native compilation remain
outside these result theorems; SHLD and SHRD are separate operations.
Their flag transition is now generated into the central C handler and Lean as
well. For arbitrary operands, supplied result, incoming flags, legal width, and
masked count, Lean checks every architecturally defined field: count zero
preserves all flags; SHL/SHR/SAR update zero and sign, update carry while the
count is below the operand width for SHL/SHR or with sign saturation for SAR,
and define overflow at masked count one; ROL
preserves zero/sign, updates carry for every nonzero masked count, and defines
overflow at masked count one. The carry rule fixes the
prior 8/16-bit ROL case where a
nonzero masked count equal to the width left carry stale even though the
effective rotate amount was zero. The step theorems compose these flag
obligations with the independent shift-result theorems. SHL/SHR carry at or
beyond the operand width and overflow outside masked count one remain
intentionally unconstrained ISA fields; the generated C/Lean implementation's
deterministic choices for those fields are not claimed as architectural
guarantees.
Register writeback is generated from a shared C/Lean contract as well. Lean
checks an independent bit-update formulation for all four legal widths: a
low-byte 8-bit write and a low-word 16-bit write preserve the old upper bits,
32-bit writes zero-extend, and 64-bit writes replace the register. Every
integer-width write scalarizes simulator provenance.
The generated macros are used by the central C register switch for all 16
general-purpose registers; compile-time assertions bind its union and pointer
sizes and little-endian partial-write layout. The theorem covers the writeback
primitive, not selection of a destination register by a decoded instruction.
The generated primitive also accepts the high-byte lane used by AH/BH/CH/DH.
Lean proves the lane-parametric write and retains the concrete review
counterexample: writing `0xaa` into the high byte of `0x1122334455667788`
produces `0x112233445566aa88`. This primitive theorem alone does not bind
artifact metadata to a handler; the named integrated handlers below add that
composition, while unlisted handlers remain separate obligations. The C
compatibility convention that width zero aliases 64 and behavior for other
invalid numeric widths remain outside the typed Lean model.
Register operand reads now have the matching generated lane contract. Lean
proves that low/high byte observations and low 16/32/64-bit observations agree
with an independent fixed-width extraction specification, including a
concrete AH read regression. The existing full-register C read goes through
this generated primitive at width 64; passing decoded width/lane metadata in
the remaining unlisted operand handlers is still an integration obligation.
For MOV-immediate, MOV-register, register SETcc, register-destination
ADD/ADC/SUB/SBB, register CMP/TEST, and register NOT, a generated 32-bit AUX
layout now carries
the payload plus destination/source byte-lane shifts from the Python artifact
encoder into the C handler. Lean proves all three fields round-trip without
overlap for arbitrary values and both typed lanes; C static assertions bind
the same layout. The pre-existing `mov [mem], ah/bh/ch/dh` source-lane encoding
remains supported; other high-byte operand forms fail during artifact
generation instead of silently being treated as low-byte operands. This does
not cover other ALU operations, compare/ALU memory forms, extend, shift,
memory-load, or specialized handlers.
Register ADD now consumes that lane metadata in both generated C execution
paths. The corresponding Lean handler theorem composes lane-aware destination
and source reads, generated ADD result and flags, and lane-aware writeback for
all widths and lane choices. ADC has the same composed lane theorem, with the
incoming CF captured from the pre-state, and is enabled by the artifact
encoder. SUB now also composes generated subtraction with lane reads and
writeback. SBB likewise consumes the pre-state CF as borrow in its generated
result and flags before lane writeback. CMP composes the selected register
operands with generated subtraction flags and proves that destination bits and
tag are unchanged. TEST composes the selected operands with the generated
logic flags and proves the same destination preservation. The theorems do not
cover immediate decoding, instruction dispatch, compiler output, or native
bytes.
Register NOT also consumes the lane AUX through the shared unary C handler.
Its Lean handler theorem composes lane observation, the generated complement,
selected-lane writeback, scalarized provenance, and preservation of all four
modeled flags. Register INC now has the same lane-aware composition for its
generated increment result and writeback, including preservation of the
incoming carry flag. Register DEC likewise composes the generated decrement,
selected-lane writeback, and incoming carry preservation. Register NEG
composes subtraction from zero with selected-lane writeback and replacement
arithmetic flags. These register-unary operations now support high-byte lanes.
The ADD, ADC, SUB, and SBB register-handler slice then composes the generated
result, width narrowing, flag transition, and register writeback contracts.
For arbitrary old destination bits and tags, right-hand operand, incoming
flags, and legal width, Lean checks the resulting destination bits/tag and all
four modeled flags against an independently assembled handler specification.
This original composition covers the common register writeback reached after
operands are supplied. The lane-specific theorems above additionally refine
register operand observation and high-byte writeback for their named
operations; neither set proves instruction dispatch, immediate decoding, or
memory read/write handlers.
Arithmetic-immediate consumption now has a shared generated C/Lean contract:
the artifact field is reduced to 32 bits and sign-extended only for 64-bit
operations. Lean proves that bitwise implementation against an independent
`BitVec` truncate/sign-extend specification for every raw field and legal
width. This covers the C immediate helper after an encoded field is supplied;
the ADD-, ADC-, SUB-, and SBB-immediate lane theorems additionally compose
that decoded value through their generated result, flags, selected-lane
writeback, and tag scalarization. ADC and SBB consume one immutable pre-state
carry/borrow in both result and flags. CMP-immediate composes the same decode
through subtraction flags and proves the complete destination bits/tag remain
unchanged. TEST-immediate likewise composes the decode through width-local
logic flags and destination preservation. Other immediate opcodes and textual
parsing remain outside this composition.
Logical-immediate consumption now has the matching shared contract: the same
generated immediate-decode theorem applies to AND, OR, and XOR, and each
generated lane handler refines an independently assembled specification that
composes the selected register-lane read, the decoded immediate, the generated
bitwise result, the generated logic-flag transition (CF=OF=0, ZF=zero, SF=sign),
selected-lane writeback, and tag scalarization. Concrete counterexample
theorems pin a high-byte AND, a high-byte OR that turns the zero/sign pair
off/on, a 64-bit XOR exercising the immediate sign-extension path, a 64-bit
SHL whose 96-bit count masks to 32, and a high-byte ROL showing the zero/sign
preservation of rotate flags.
The register-register AND, OR, and XOR handlers follow the same lane
composition with a second read: the C `X86_SIM_L_EXEC_ALU_REG` generic branch
observes the destination lane and the source register lane, computes the
width-local bitwise result, replaces the destination lane, and takes
CF=OF=0 with ZF/SF from the width-narrowed result. Each generated handler
refines an independently assembled specification via the two lane reads,
the generated logic flags, and the lane writeback; concrete theorems pin a
high-byte AND, a high-byte OR that sets the width sign bit, and a 64-bit
XOR. The immediate-decode theorem is not involved because the source lane
supplies the second operand rather than a raw artifact field.
The register-register SHL, SHR, SAR, and ROL handlers are the
register-register logical form with a second read supplying the shift count:
the C `X86_SIM_L_EXEC_ALU_REG` generic branch observes the destination lane
and the source register lane, computes the width-local shift result through
the shared shift-result contract, and replaces the destination lane with the
width-local shift-flag transition (the generated shift flags seeded with
the pre-state flags, per the shared shift-flag contract). Each generated
handler refines an independently assembled specification via the two lane
reads, the generated shift result, the generated shift flags, and the lane
writeback; concrete theorems pin a high-byte SHL and a high-byte SAR
sign-fill. The immediate-decode theorem is not involved because the source
lane supplies the count rather than a raw artifact field, and the op-parametric
immediate shift-flag definedness theorem establishes the architectural flag
contract for these operands.
The x86 IMUL overflow-flag transition is generated from
`x86_imul_flags_spec.json` into the C macro `KPROG_X86_SET_IMUL_FLAGS` and
Lean. The hand-written `X86_SIM_L_SET_IMUL_FLAGS` now computes the
width-narrowed signed magnitudes, the sign-mask limit, and the mixed-sign
headroom, then delegates the guarded-division overflow test
(`a_abs != 0 && b_abs > limit / a_abs`) and the CF/OF assignment to the
generated macro; ZF and SF are preserved. This removes a spurious
`a_abs < b_abs` conjunct that had diverged the generated C from both the
hand-written macro and the Lean model. Lean proves an independent
overflow specification equal to the generated `apply`, and the applied flag
transition equal to an independently stated `x86ImulFlagsApplied`. A host C
cross-check (`test_imul_flags_host.c`) compares the generated macro against
an independent `__int128` signed-product range oracle for 15 explicit
boundary vectors (including `INT64_MIN * -1` in range and `-1 * 2` in range)
and a fixed-seed 20000-case sweep over all four widths.
The immediate and register-register IMUL lane handlers then compose this
contract: `generatedX86ImulImmLaneHandler` / `generatedX86ImulRegLaneHandler`
observe the destination lane (and, for the register form, the source register
lane), decode the raw artifact immediate or read the second operand, compute
the full 64-bit product, write back the selected lane with tag scalarization,
and take CF/OF from the generated IMUL overflow contract while preserving
ZF/SF. Each refines an independently assembled specification via the lane
reads, the immediate decode, the writeback, and
`x86_imul_flags_apply_refines`. Concrete theorems pin a 16-bit overflow
(`0x7fff * 2 -> 0xfffe` with CF=OF set) and in-range cases. The C ALU
dispatch routes both IMUL forms through `X86_SIM_L_SET_IMUL_FLAGS`; instruction
dispatch, operand-form selection, and native bytes remain outside these
theorems.
The generated ALU decode contract also classifies the two carry-sensitive
handlers (ADC and SBB). The register-lane AUX theorem proves that packing a
typed ALU code and extracting its payload selects the same handler as an
independent operation mapping. The C immediate, register, and memory ALU paths
consume the generated predicates for those two special branches. This binds
typed AUX payload extraction to handler class, but not native-byte or textual
mnemonic parsing to that typed operation.
The x86 little-endian memory access contract is generated from
`x86_mem_access_spec.json` into the C macros `KPROG_X86_MEM_LOAD` /
`KPROG_X86_MEM_STORE` and Lean. The central `X86_SIM_L_LOAD_ADDR` /
`X86_SIM_L_STORE_ADDR` macros now delegate to those generated primitives, so
the previously hand-written byte-ladder load and typed-cast store share one
forwarded source. Lean proves the generated `assemble` equal to an independent
little-endian byte-sum specification, the generated `load` equal to that sum
narrowed by the width mask, and the generated per-byte store against an
independent width-masked extraction, for every legal width. A host C
cross-check (`test_mem_access_host.c`) compares the generated macros against an
independent byte-level load/store oracle over explicit boundary vectors and a
fixed-seed 20000-case sweep of all four widths; `make check` runs it. Decoder
selection of the access width, operand-form selection, the C compiler, and
native bytes remain boundaries, and the memory access/store integration noted
for the unary/ALU handlers is now shared with this primitive.
The memory-source arithmetic handler now has a composed state-transition
theorem over ADD, ADC, SUB, and SBB. `x86_mem_arith_handler_refines` starts
after a valid effective address and address-space path have supplied the bytes,
then composes the generated little-endian load, carry/borrow-sensitive result
and flag transitions, low-lane partial-register writeback, 32-bit zero
extension, and provenance scalarization against an independently assembled
specification. An independent host oracle checks 22,048 boundary and
fixed-seed cases using a byte loop plus 128-bit carry/borrow and signed-range
arithmetic. Effective-address calculation, stack/ABI dispatch, memory safety,
opcode/width selection, memory-destination stores, and native bytes remain
outside this theorem.
The complementary memory-destination arithmetic theorem covers
`ADD/ADC/SUB/SBB [mem], rhs` after the effective address and right-hand
operand have been selected. It composes the old-value byte load, the same
carry/borrow-correct result and flag transitions, and the generated
little-endian store. `x86_mem_dest_arith_handler_refines` proves equality of
all modeled flags and every memory byte: exactly `width/8` bytes receive the
width-local result and every byte outside that range is unchanged. A separate
22,048-case host oracle compares the actual generated C load/store and flag
macros with a byte-loop and 128-bit arithmetic. Address derivation and safety,
stack/ABI dispatch, immediate/register RHS decoding, opcode selection, and
non-arithmetic memory handlers remain outside this theorem.
The memory-unary theorem covers the real `X86_OP_ALU_MEM_UNARY` transition for
`INC/DEC/NEG/NOT [mem]` after effective-address, operation, and width
selection. It composes the byte load, the proved unary result/flag transition,
and the width-confined little-endian store, proving equality of every modeled
flag and memory byte. In particular, `INC` and `DEC` preserve incoming carry,
`NOT` preserves all flags, and `NEG` replaces arithmetic flags. A separate
22,048-case oracle checks the actual generated macros against an independent
signed-range and byte-loop model across all 16 incoming flag combinations.
Address derivation and safety, stack/ABI dispatch, and packed-AUX operation
selection remain outside this theorem.
The memory-destination logic theorem covers `AND/OR/XOR [mem], rhs` after a
valid address, RHS, operation, and width have been selected. It composes the
load, width-local logical result and replacement flags, and confined store,
proving equality of every modeled flag and byte. Its independent 21,536-case
oracle checks actual generated macros against a byte-loop model, including all
16 incoming flag combinations to ensure CF/OF are cleared and ZF/SF are
RHS decoding and address-space dispatch remain outside the theorem.
The memory-source shift theorem covers the flagless BMI2 forms
`SHLX/SHRX/SARX dst, [mem], count` and `RORX dst, [mem], imm8`. It composes the
byte load, the width-local shift result (the rotate reaching its result through
the complementary-count rotate-left contract), and the width-confined register
writeback, proving destination equality and that every modeled flag is
preserved. Its independent 21,024-case oracle checks the actual generated
macros, including the architectural 32-bit zero-extension into the 64-bit
Effective-address derivation and count register selection remain outside the
theorem.
The memory-source bit-test theorem covers the legacy `BT [mem], imm8` handler
and the BMI2 `BZHI dst, [mem], count` handler. It composes the byte load with
the generated `bt`/`bzhi` bit-helper contracts, proving that `BT` changes only
CF and writes no register while `BZHI` writes the width-confined destination and
defines CF/ZF/SF/OF, against an independently stated bit-test/kept-mask
specification. Its independent 20,512-case oracle checks the actual generated
macros — including the masked-to-63/31 bit index, the byte-masked count, and the
architectural 32-bit zero-extension — against a byte-loop model. The decoded
The decoded immediate/register second operand and effective-address derivation
remain outside the theorem.
The memory-source multiply theorem covers the legacy `IMUL reg, [mem], imm`
handler. It composes the byte load, the arithmetic-immediate rule, the generated
sign extension of both operands, the divide-based IMUL flag construction, and the
width-confined register writeback, proving destination equality and equality of
every modeled flag against an independently stated specification that decides
CF/OF from whether the mathematical product fits the destination's signed width.
Its independent 43,136-case oracle checks the actual generated macros — including
the 32-bit-truncated immediate, the signed narrow memory read, and the
architectural 32-bit zero-extension — against a byte-loop model. Effective-address
derivation remains outside the theorem.
The register-source multiply theorem covers the legacy `IMUL reg, imm` handler.
It composes the raw 64-bit register read (never sign-extended, unlike the memory
operand), the arithmetic-immediate rule and sign extension of the immediate, the
divide-based IMUL flag construction, and the width-confined register writeback,
proving destination equality and equality of every modeled flag against an
independently stated specification that decides CF/OF from whether the
mathematical product of the width-narrowed operands fits the destination's
signed width. Its independent 41,296-case oracle checks the actual generated
macros — including the 32-bit-truncated and sign-extended immediate, the
width-narrowed source sign extension, and the architectural 32-bit
zero-extension — against an exact-product model. Register selection and
effective-address derivation remain outside the theorem.
The memory-source compare theorem covers the four `CMP/TEST [mem], rhs` forms
and `CMP reg, [mem]`. It composes the byte load with the generated zero-borrow
subtraction flags for the compare forms and the generated logical flags for the
test forms, proving equality of every modeled flag and that no register is
written against an independently stated load/flags specification. Its
independent 40,784-case oracle checks the actual generated macros against a
byte-loop model. Effective-address derivation and RHS source selection remain
outside the theorem.
The two-destination `MULX` theorem covers `X86_SIM_L_EXEC_MULX`. It composes
the 32-bit zero-extended low-word product and the 64-bit four-limb ladder with
the width-confined writeback of both the destination and the auxiliary operand,
proving both register halves equal the halves of an exact 128-bit product and
that the flag word is untouched, against an independently stated
product/writeback specification. Its independent 41,296-case oracle checks the
actual generated write macros against a 128-bit-product model that shares no
arithmetic with the limb ladder. The implicit `RDX` left operand, the
auxiliary-destination decode, and effective-address derivation remain outside
the theorem.
The effective-address and LEA theorem covers `X86_SIM_L_EXEC_LEA`. A dedicated
contract generated from `x86_mem_offset_spec.json` produces the
`KPROG_X86_MEM_OFFSET` macro and a Lean `GeneratedX86MemOffset` module for the
base-plus-scaled-index offset, and `x86_mem_offset_refines` proves the generated
transition equal to an independent statement of the same sum. On top of it,
`x86_lea_step_refines` composes the RODATA fast path (no source register:
writes the raw immediate and scalarizes), the 64-bit stack-pointer path
(resolves through an abstract frame base and tags the result as stack), the
64-bit general path (sums the source pointer and carries its provenance), and
the narrow-width exits (truncate the summed pointer through the
partial-register writeback and scalarize), proving the composed handler equal
to an independently stated step for every destination state, source operand,
immediate, rodata flag, width, and effective-address term. Four further
theorems pin the RODATA fast path, the source-register bypass of it, the stack
base, and the narrow-width independence from the stack-pointer distinction.
Its independent 61,440-case oracle checks the actual generated offset and
write macros against an explicit power-of-two-multiply and partial-writeback
model. The register decode that supplies the index value, the AUX bit layout,
and the mapping from the simulator's stack region to the abstract frame base
remain outside the theorem.
The simulator's `X86_SIM_L_MEM_OFFSET` helper now delegates to that
machine-checked contract instead of restating the offset arithmetic inline:
it resolves the AUX index register through the simulator's own register read
and calls the generated `KPROG_X86_MEM_OFFSET`, so the LEA/MOV/CMP/STORE/test
and base-offset arms and the Lean refinement share one implementation. A host
cross-check includes the simulator header, drives the real helper over
register-AUX forms against an independent signed accumulator built from the
same source register value, checks the no-index form ignores a poisoned
register file, and checks the routed helper agrees with the explicit-value
helper (2,305 cases).
The simulator's memory read path now routes its read-source classification
through the machine-checked `KPROG_X86_MEM_READ_SRC` contract instead of
restating the stack/ABI/ordinary predicate ladder inline. The new
`X86_SIM_L_MEM_READ_SRC` resolves the base register's tag through the
simulator's own register read and delegates to the generated contract; both
`X86_SIM_L_READ_MEM_VALUE` and the `X86_SIM_L_EXEC_MOV_LOAD` arm chain switch
on it (the MOV_LOAD ABI arm keeps its opcode-and-width-64 refinement that falls
back to an ordinary load and write). This mirrors the arm64 read path, which
already routed through its peer contract. A host cross-check includes the
simulator header, drives the real helpers over stack/ABI/ordinary bases and the
ordinary/MOVSX/ABI/ABI-off-width/stack MOV_LOAD cases, and compares both the
written value and the destination register tag against an independent byte
reader and the contract's classification (62 cases).
The simulator's shared `MOV_STORE` body now routes every clause of its
handler composition through the machine-checked `KPROG_X86_STORE_*` contract
instead of restating them inline. New `X86_SIM_L_MEM_STORE_SRC(DST)` delegates
the stack-versus-memory arm to `KPROG_X86_STORE_ARM((DST) == X86_RSP)`, and
`X86_SIM_L_EXEC_STORE` resolves the width (`KPROG_X86_STORE_WIDTH`), the
displacement form (`KPROG_X86_STORE_DISP`), the value source
(`KPROG_X86_STORE_VALUE`), and the AUX source shift
(`KPROG_X86_STORE_SRC_SHIFT` / `KPROG_X86_STORE_SHIFTED_VALUE`) through the
generated contract, switching the arm on the routed selector. This is a plain
two-way arm, unlike the read path's three-way source: the store has no ABI arm
and no sign extension, and both arms keep the same `FLAGS ? FLAGS : 64` width
expression the contract calls a re-derivation. A host cross-check includes the
simulator header, drives the real body over the immediate and register forms,
every width, flat and indexed addressing, the register-form AUX shift, and both
arms, and compares the entire modeled heap and stack against an independent
byte model, plus the routed selector against `KPROG_X86_STORE_ARM` (77 cases).
The simulator's `MOVBE_LOAD` / `MOVBE_STORE` bodies now route their clauses
through the machine-checked `KPROG_X86_MOVBE_*` contract instead of restating
them inline. New `X86_SIM_L_MEM_MOVBE_SRC(DST)` delegates the
stack-versus-memory arm to `KPROG_X86_MOVBE_ARM((DST) == X86_RSP)` — the same
plain two-way arm as the store path, with no ABI arm and no sign extension —
and `X86_SIM_L_EXEC_MOVBE_STORE` resolves the width
(`KPROG_X86_MOVBE_WIDTH`) and the whole-artifact displacement
(`KPROG_X86_MOVBE_DISP`) through the generated contract, switching the arm on
the routed selector; `X86_SIM_L_EXEC_MOVBE_LOAD` resolves the same width and
hands it to the shared read body. One resolved width drives the byte reversal,
the memory access, and the written size in both forms. A host cross-check
includes the simulator header, drives the real load and store bodies over every
width, flat and indexed addressing, and both arms, and compares the entire
modeled heap and stack against an independent byte model plus the written
destination register value and tag against the byte-reversed model, and the
routed selector against `KPROG_X86_MOVBE_ARM` (71 cases).
The register-writing MOV theorem covers `X86_SIM_L_EXEC_MOV_IMM` and
`X86_SIM_L_EXEC_MOV_REG`. `x86_mov_imm_step_refines` composes the
register-destination immediate move over the partial-register writeback
(destination width and explicit byte lane), and `x86_mov_reg_step_refines`
composes the register-source move: the 64-bit stack-pointer arm resolves
through the abstract frame base and tags the result as stack, the 64-bit
general arm copies the source pointer and its provenance, and every narrow
width reads the source through its decoded lane, writes through the
partial-register writeback, and scalarizes. Further theorems pin the
provenance-copying and stack-base arms, the narrow-width independence from the
stack-pointer distinction, and that every narrow move scalarizes. Its
independent 100,448-case oracle checks the actual generated read/write and
pointer-add macros against an explicit lane-read and partial-writeback model.
The register decode that supplies the source value and provenance, the AUX bit
layout, and the mapping from the simulator's stack region to the abstract
frame base remain outside the theorem.
The width-converting register-source MOV theorem covers
`X86_SIM_L_EXEC_MOVX_REG`, the shared body of `X86_OP_MOVZX_REG` and
`X86_OP_MOVSX_REG` (and so of `cdqe` and `movsxd`). `x86_movx_reg_step_refines`
composes both opcodes over the already-proved narrowing and sign-extension
contracts at the decoded source width, then the partial-register writeback at
the decoded destination width. Further theorems pin the two opcode arms, the
`cdqe`/`movsxd` decoding as the 32-bit-source instance, the idempotence of
same-width narrowing, and that every writeback scalarizes. Unlike the
register-source MOV, the MOVX body reads the raw 64-bit register with no byte
lane. Its independent 62,409-case oracle checks the actual generated
narrowing/sign-extension/write macros against an explicit sign-bit model. The
register decode that supplies the source value, the width-code resolution that
turns zero into the 64-bit fallback, and the source-width/destination-width
selection relation remain outside the theorem.
The shared memory read-dispatch theorem covers the value-source selection of
`X86_SIM_L_READ_MEM_VALUE`, the single read body the plain load and store
families share. `x86_mem_dispatch_src_refines` equates the generated
value-source table with an independent predicate nesting over the three facts
the body consults: whether the base register *is* the stack pointer, whether
its memory tag is the ABI tag, and whether the effective width is 64 bits.
Further theorems pin the x86-specific asymmetry against the AArch64 dispatch —
the first test is register identity, not a memory tag, so an ABI-tagged stack
pointer still reads through the stack helper, and the ABI arm is gated on width
64 so an ABI base off width 64 falls through to the ordinary load — plus the
reachability of every arm. This body carries no reloc arm and no per-arm result
tag; the ABI packet tag refinement stays in `X86_SIM_L_EXEC_MOV_LOAD`. Its
independent 3,650-case oracle checks the actual generated dispatch, offset and
byte-ladder load macros against an explicit read-body model. The register
decode that supplies the base pointer and tag, the register-file layout, and
the simulated stack region remain outside the theorem.
The shared `MOV_LOAD` handler-composition theorem covers
`X86_SIM_L_EXEC_MOV_LOAD`, the single body shared by `X86_OP_MOV_LOAD`,
`X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD`. `x86_mov_load_step_refines`
composes the width resolution (`x86_mov_load_resolve_width_refines`, the
64-bit write default and the memory-width fallback to the write width, both
total), the arm table (`x86_mov_load_arm_refines`), the byte-ladder load, the
sign extension, the ABI provenance tag, and the partial-register writeback in
one step relation. Further theorems pin the x86-specific asymmetries: the first
arm test is register identity, so the stack arm overrides the ABI arm and
ignores `_MOVSX_LOAD` sign extension, while the ABI pointer arm requires the
plain `_MOV_LOAD` opcode *and* both resolved widths at 64 bits, so an
ABI-tagged base reached by a narrow opcode is scalarized. The generated
provenance tag is bridged to the declarative `abiTagSpec` policy
(`generated_abi_load_tag_refines`), and every arm is reachable. Its independent
86,461-case oracle checks the actual generated width, arm, offset, load, and
provenance macros against an explicit handler model. The register decode that
supplies the base pointer, register identity and tag, and the effective-address
computation remain outside the theorem.

The body named in that paragraph now routes through the generated contract:
`X86_SIM_L_EXEC_MOV_LOAD` resolves both widths through
`KPROG_X86_MOV_LOAD_WRITE_WIDTH` and `KPROG_X86_MOV_LOAD_MEM_WIDTH`, selects its
arm through `KPROG_X86_MOV_LOAD_ARM`, and classifies its value source through
the shared `KPROG_X86_MEM_READ_SRC` dispatch, so the 64-bit write default, the
memory-width fallback to the write width, the stack-first arm precedence, the
ABI-pointer arm's opcode-and-both-widths-64 gate, and the stack arm's
memory-width read are compile-time expansions of the machine-checked macros
rather than committed literals. The independent `test_x86_mov_load_route_host.c`
oracle includes the simulator header, drives the real body over the three load
opcodes, all five `FLAGS` and five AUX memory-width codes, flat, indexed (all
four scales), stack and ABI (`XDP`/`SKB` offsets) modes, the overlap case, and
the sign-extending arm, and compares the whole modeled register file with its
tags, the heap and the stack against independent byte models. Its planted bases
separate an ABI-tagged register from the stack pointer and from an ordinary
pointer at every case.

The shared `MOV_STORE` handler-composition theorem covers
`X86_SIM_L_EXEC_STORE`, the single body shared by `X86_OP_MOV_STORE_IMM`
(`0x07`) and `X86_OP_MOV_STORE_REG` (`0x08`). `x86_store_step_refines`
composes the width resolution (`x86_store_width_refines`, the 64-bit fallback
for an absent `FLAGS` code, total), the displacement form, the value source,
the AUX shift source, the arm table (`x86_store_arm_refines`), the generated
effective-address offset, and the little-endian byte update in one step
relation. Further theorems pin the x86-specific asymmetries: the handler
resolves exactly one width, used for both the immediate value and the write, so
the stack arm's `X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)` is the same expression as
the memory arm's width (there is no second, AUX-sourced memory width as in the
read body); the immediate form takes `(s32)(IMM >> 32)` while the register form
takes `(s64)IMM`, so the same artifact field yields different displacements;
only the register form consults the AUX source-shift field, and it is read
after the register read, so the immediate form ignores any AUX byte; and the
register source is read at the full 64 bits even at a narrow store width, so a
narrow store of a shifted 64-bit value discards the shift's high half in the
width mask rather than in the read. The register shift amount is the AUX shift
byte modulo 64, because the body's `>>=` on a `__u64` uses the x86 count
truncation while `BitVec`'s `>>>` saturates to zero above the word width; the
statement `x86_store_shift_spec` fixes the reading explicitly. Its independent
48,013-case oracle drives the generated width, displacement, value, shift,
arm, offset, and store macros against an explicit store-body model, comparing
every resulting memory and stack byte. The register decode that supplies the
base pointer, register identity and the register source value, and the
addressing-mode decode remain outside the theorem.
The `SETCC` handler-composition theorem covers `X86_SIM_L_EXEC_SETCC`
(`X86_OP_SETCC`, `0x16`). `x86_setcc_step_refines` composes the condition
decode (`x86_setcc_raw_cond_sound`, the generated `KPROG_X86_EVAL_CC`
expression table pinned to the architectural condition table with the
unsupported codes falling to false), the destination byte-lane decode (the
equality test, `x86_setcc_lane_high_iff`), and the 8-bit register writeback in
one step relation. `x86_setcc_eval_cond_sound` is the content of the generated
table: it is proved by 14 constructor cases, so a transposition of any two
condition arms makes it fail. Further theorems pin the x86-specific
asymmetries: the condition is read from the AUX payload byte alone and the
flags are used as given, so no flag production participates; the write width is
fixed at 8 regardless of the AUX source-shift byte; the destination tag is
scalarized unconditionally, unlike `CMOV`'s pointer-preserving 64-bit arm; and
the lane test is an equality, so a destination shift of 9 selects the low byte
rather than the high one. Its independent 590,726-case oracle sweeps the whole
256-value condition byte space and the whole 256-value destination-shift space
against the real `KPROG_X86_EVAL_CC` expression and a restated write helper,
and drives the full handler over a deterministic 16-register model comparing
every byte and tag. `x86_setcc_cond_matched_refines` lifts the simulator's
routing of the payload byte through the `KPROG_X86_SETCC_COND_MATCHED` fold to
that same raw evaluation: the fold's identity on the accepted subset and the
no-match sentinel elsewhere are swept against every flag assignment, so a
transposed fold arm or a sentinel that collided with an accepted code fails the
proof. The register decode that supplies the destination identity
and the flags remain outside the theorem.
The `SETCC_MEM` handler-composition theorem covers `X86_SIM_L_EXEC_SETCC_MEM`
(`X86_OP_SETCC_MEM`, `0x3e`). `x86_setcc_mem_step_refines` composes the
condition decode (`x86_setcc_mem_raw_cond_sound`, the same generated
`KPROG_X86_EVAL_CC` expression table the register form composes, driven from
the AUX source-shift byte instead of the payload byte), the null-base and
stack-arm selection, the effective address, and the one-byte memory or stack
write in one step relation. It is exactly here that the two x86 forms differ,
and the theorems say so: `x86_setcc_mem_condition_source_differs` pins that the
condition byte is bits 24..31 rather than bits 0..7, so the same AUX word names
different conditions for `SETCC` and `SETCC_MEM`;
`x86_setcc_mem_disp_differs_from_imm_store` pins that the displacement is the
whole artifact rather than the immediate store's high-half slice; and
`x86_setcc_mem_both_arms_use_one_width` pins that the write is one byte wide
regardless of a nonzero AUX memory-width byte and a nonzero FLAGS code, which
is what separates this opcode from the width-selecting stores. The destination
register number drives both selectors, so `x86_setcc_mem_null_base_ignores_dst`
pins that `X86_REG_NONE` forms process null before the arm test and therefore
always takes the memory arm — the null base is not the stack pointer. Its
independent 1,053,191-case oracle sweeps the whole 256-value condition byte
space against the real `KPROG_X86_EVAL_CC`, the whole register space against
both selectors, and drives the full handler over a deterministic
register/memory/stack model comparing every byte of both buffers, with pins on
the source-shift decode, the whole-artifact displacement, the constant width,
the null-base arm, the unsupported parity codes, and the scaled-index offset.
The register decode that supplies the destination identity, the base-pointer
value and the flags remain outside the theorem.

The two bodies named in those paragraphs now route through the generated
contracts. `X86_SIM_L_EXEC_SETCC_STEP` — the extracted composition both the
`X86_SIM_L_EXEC_SETCC` macro and the `X86_OP_SETCC` dispatcher arm call —
decodes the destination shift, selects the byte lane through
`KPROG_X86_SETCC_LANE`, reads the condition from the AUX payload byte through
the contract's `KPROG_X86_SETCC_COND_MATCHED` fold, and hands the lane to the
write helper's own `== 8` branch, so the lane is the contract's equality test
rather than a restated one. The matched fold is the identity on the accepted
condition subset and the no-match sentinel elsewhere; both the sentinel and
every unaccepted byte are rejected by `KPROG_X86_EVAL_CC`'s promoted comparison,
so the route is the raw evaluation, which
`x86_setcc_cond_matched_refines` in `X86SetccHandler.lean` machine-checks by
sweeping every payload byte against every flag assignment (the handler's table
`x86MatchedCodeTable` is written from the architectural condition names, so a
transposed generated arm or a sentinel that collided with an accepted code
fails the proof rather than the oracle); `X86_SIM_L_EXEC_SETCC_MEM` reads the
condition through `KPROG_X86_SETCC_MEM_CONDITION`, forms the base through
`KPROG_X86_SETCC_MEM_BASE`, selects the arm through `KPROG_X86_SETCC_MEM_ARM`
over the destination's equality with `KPROG_X86_SETCC_MEM_RSP_REG`, and writes
at the constant `KPROG_X86_SETCC_MEM_WIDTH_CODE`. The independent
`test_x86_setcc_route_host.c` oracle includes the simulator header, sweeps the
accepted condition codes and an out-of-subset code, the whole destination-shift
byte space, all 16 destination registers, all 16 flag nibbles and both dispatch
routes, and compares the destination register and tag against an independent
lane-selected write model, pinning that `KPROG_X86_SETCC_LANE` is an equality
test and the two lane codes (2,433,038 cases). The independent
`test_x86_setcc_mem_route_host.c` oracle sweeps the condition byte, the
destination register space, the constant width code, several displacements, the
index register and scale, all 16 flag nibbles and both dispatch routes, drives
the real body over a deterministic heap and 64-byte stack frame, and compares
every heap and stack byte against an independent addressing model with its own
arm selection, plus dedicated probes for the null-base arm, the indexed stack
destination, and the selector tables (8,958,727 cases).
The `CMOV` / `CMOV_MEM` handler-composition theorem covers
`X86_SIM_L_EXEC_CMOV` (`X86_OP_CMOV`, `0x15`) and
`X86_SIM_L_EXEC_CMOV_MEM` (`X86_OP_CMOV_MEM`, `0x40`).
`x86_cmov_step_refines` composes both bodies in one step relation over the
generated condition, write-width, access-width, displacement, and writeback
contracts: the register form's condition is the whole AUX word, evaluated
through the same generated `KPROG_X86_EVAL_CC` expression table the
`SETCC` forms compose, with unsupported words falling to the C default
false, while the memory form's condition is the AUX source-shift byte at
bits 24..31; the write width is the FLAGS code with a 64-bit fallback, the
memory form's access width a two-level fallback through the memory-width
byte, and the writeback a width-keyed table that selects the
pointer-preserving write at 64 bits and the scalarizing partial-register
write otherwise. Both forms are conditional — the entire body, value
production included, is inside the condition test — so
`x86_cmov_false_condition_no_write` pins that a false condition leaves the
destination exactly as it was. The register form's 64-bit arm preserves the
source's provenance tag while every narrower arm scalarizes,
`x86_cmov_w64_arm_preserves_source_tag` and
`x86_cmov_narrow_arm_scalarizes`; the memory form instead writes through
the partial-register write at every width, including the 64-bit one, and so
never preserves a provenance tag. `x86_cmov_condition_sources_differ` pins
the register form's whole-word condition against the memory form's
source-shift byte — one AUX word names two different conditions, so
`x86_cmov_whole_word_not_low_byte_equality` pins that the whole-word
table, not the low-byte decode, is the register form's faithful statement.
`x86_cmov_mem_width_two_level_fallback` pins the two-level fallback, and
`x86_cmov_mem_disp_differs_from_setcc_mem` pins that the memory form's
displacement is the high half of the instruction artifact, the immediate
store's slice, unlike the whole artifact the memory `SETCC` consumes.
`x86_cmov_unsupported_example` pins that an unsupported parity code
evaluates to false for both opcodes. Its independent 484,369-case oracle
sweeps the whole-word and byte condition spaces against the real
`KPROG_X86_EVAL_CC` expression, the writeback width contracts, and both
handler bodies against a hand-written C model, with pins on the false
condition, the 64-bit tag preservation, the memory form's scalarization,
the two-level width fallback, and the high-half displacement. The register
decode that supplies the source, the base-pointer value, and the flags
remain outside the theorem.

The two bodies named in that paragraph now share one
`X86_SIM_L_EXEC_CMOV_STEP` composition that routes the condition through the
machine-checked `KPROG_X86_CMOV_CONDITION` / `KPROG_X86_CMOV_MEM_CONDITION`
selectors, the write width through `KPROG_X86_CMOV_WIDTH`, the memory access
width through `KPROG_X86_CMOV_MEM_WIDTH`, the displacement through the shared
memory read as the generated `KPROG_X86_CMOV_MEM_DISP`, and the writeback arm
through `KPROG_X86_CMOV_WRITEBACK`, so the
register form (which samples the pointer and provenance at 64 bits) and the
memory form (which scalarizes at every width) cannot drift and the per-opcode
condition source is a compile-time literal at each wrapper. The independent
`test_x86_cmov_route_host.c` oracle includes the simulator header, drives both
real bodies — directly and through the `X86_SIM_L_EXEC` dispatcher arms that
route to them — over the whole-word and source-shift condition spaces, every
`FLAGS` code, the AUX memory-width byte, four displacements, both index modes
and both scales, and every destination / source register. It plants a non-zero
low half in the memory form's instruction artifact, so a displacement taken
from the whole-artifact slice instead of the routed `KPROG_X86_CMOV_MEM_DISP`
high half reads a different address, and compares the whole register file with
its tags and all four flags against an independent model. Its planted registers
give the source register a provenance tag
distinct from scalar at 64 bits, so a body that scalarizes the register form's
64-bit write, takes the memory form's whole-word condition instead of its
source-shift byte (one AUX word naming two different conditions), skips the
memory-width fallback, or inverts the writeback arm is numerically
distinguishable at every case.

The `MOVBE_LOAD` / `MOVBE_STORE` handler-composition theorem covers
`X86_SIM_L_EXEC_MOVBE_LOAD` (`X86_OP_MOVBE_LOAD`, `0x28`) and
`X86_SIM_L_EXEC_MOVBE_STORE` (`X86_OP_MOVBE_STORE`, `0x29`).
`x86_movbe_load_step_refines` and `x86_movbe_store_step_refines` compose the two
bodies over the generated width, displacement, arm, and shared read-dispatch
contracts: both forms resolve one width — the FLAGS code with a 64-bit fallback
— used for the byte reversal, the memory access, and the written size alike, so
`x86_movbe_one_width_rides_all` pins that a single resolved width rides the
reversal and the access and `x86_movbe_store_both_arms_use_one_width` pins that
the store's stack arm does not re-derive a second effective width the way the
shared `MOV_LOAD` does; the load classifies its base through the shared read
dispatch (`GeneratedX86MemDispatch.valueSrc`), taking the stack,
ABI-pointer-load, or ordinary-load arm, and always scalarizes through the
partial-register write, so `x86_movbe_load_scalarizes` pins that it has no
pointer-preserving arm and `x86_movbe_load_no_sign_extension` pins that, unlike
the shared `MOVSX` load, an 8-bit reversal of `0x80` stays `0x80`; the store
takes the register-identity arm through `x86_movbe_arm_refines`, reading a
separate 64-bit source register and reversing before the arm split.
`x86_movbe_disp_differs_from_imm_store` pins that both forms take the whole
instruction-immediate artifact `(s64)IMM`, never the immediate store's
high-half slice `(s32)(IMM >> 32)`; `x86_movbe_store_load_round_trip` pins that
the reversal is an involution, so a load of what a store of the same width
reversed recovers the width-masked original. Its independent 4,675-case oracle
sweeps the width space, the shared dispatch table over all eight selector
combinations, and both handler bodies against a hand-written C model over a
deterministic register/memory/stack model, with pins on the whole-artifact
displacement, the 8-bit no-sign-extension, the ABI-tagged scalarizing load, the
width-64-gated ABI arm, the reversal involution, and the single-width narrowing.
The register decode that supplies the source, the base-pointer value, and the
flags remain outside the theorem.

The `MOV_LOAD_MAP_PTR` / `MOV_LOAD_HELPER_ID` pointer-write provenance theorem
covers the two `X86_SIM_L_EXEC` arms for `X86_OP_MOV_LOAD_MAP_PTR` (`0x2c`) and
`X86_OP_MOV_LOAD_HELPER_ID` (`0x2d`), the opcodes whose register write installs
pointer bits together with a provenance tag. It is the first handler whose sim C
routes through the generated contract rather than restating it: both arms call
`KPROG_X86_PTR_WRITE_TAG` (the generated opcode-to-tag selector) and gate the
helper-id arm's preliminary width-64 scalar lane write on
`KPROG_X86_PTR_WRITE_IS_HELPER_ID`, then perform the pointer write through
`X86_SIM_L_WRITE_REG_PTR_TAG`. `x86_ptr_write_step_refines` composes the two
arms over the generated tag table, width-64 fact, and the reused
`generatedX86MovPointerWrite`/`generatedX86RegWrite` primitives.
`x86_ptr_write_tag_all_reachable` pins that every tag the C chain can select has
a Lean counterpart and that the all-false fallthrough (both opcode facts unset)
maps to `none`, so the generated selector is total;
`x86_ptr_write_map_ptr_writes_no_width` pins that the map-pointer arm writes no
width at all, whereas the helper-id arm's width-64 scalar lane write is replaced
bit for bit by the pointer write, so `x86_ptr_write_helper_id_absorbs_scalar`
pins the two writes are observationally one pointer+tag write. Its independent
318-case oracle exercises the tag table, the selector over all four fact pairs,
the helper-id test over all 256 tag bytes, and the whole arm over a
deterministic register file, with pins on the map-pointer arm's absent lane, the
helper-id arm's single erased lane, the flag-free write, the `X86_REG_NONE`
no-write, and the distinct provenance of identical pointer bits. The register
decode that selects the destination and supplies the immediate remains outside
the theorem.

The `LOAD_XMM0` / `STORE_XMM0` pair-move theorem covers the two
`X86_SIM_L_EXEC` arms for `X86_OP_LOAD_XMM0` (`0x30`) and `X86_OP_STORE_XMM0`
(`0x31`), the opcodes that move the XMM0 pair as two 8-byte lanes. The two arms
share one module because they are the two directions of one pair move:
`generatedX86Xmm0Direction` reads the opcode's direction, `generatedX86Xmm0Arm`
selects the stack arm from the single stack-pointer test (a `X86_REG_NONE`
operand is the *same* ordinary arm, not a third one), and
`generatedX86Xmm0LaneOffset` places the two lanes at offsets 0 and 8, low lane
first. The pair is modeled as `X86Xmm0Pair` (`lo`/`hi : BitVec 64`), matching
the two scalar state fields the sim uses. `generated_x86_xmm0_load_step_refines`
composes the load over the arm, base-pointer, offset-adding, addressing-offset,
and little-endian load contracts; `generated_x86_xmm0_store_step_refines`
composes the store the same way.
The headline fact is the ordinary arm's base-form asymmetry:
`x86_xmm0_ordinary_addr_load_ignores_offset` pins that the load's `X86_REG_NONE`
operand *is* the raw instruction-immediate artifact with the addressing offset
*discarded*, whereas `x86_xmm0_ordinary_addr_store_uses_offset` pins the store's
`X86_REG_NONE` operand is the *null pointer* with the offset *always added*;
`x86_xmm0_ordinary_addr_reg_base_agrees` pins that every register operand
nonetheless agrees between the two opcodes. `x86_xmm0_disp_forms_whole` fixes
the displacement as the whole `x86_simm` artifact, never the immediate store's
high-half slice; `x86_xmm0_pair_layout`, `x86_xmm0_lane_width_is_64`, and
`x86_xmm0_store_bytes_above_pair_unchanged` pin the two-lane geometry. Its
independent 283-case oracle exercises the generated tables, the full load and
store compositions over a deterministic register and memory model, and pins the
base-form asymmetry, the whole-artifact displacement, the lane order, the
untouched register file and tags, the non-vacuous memory access, and the stack
arm round trip. The register decode that supplies the operand and immediate
remains outside the theorem.

The two `X86_SIM_L_EXEC_{LOAD,STORE}_XMM0` handler bodies now route the
stack-pointer arm through the machine-checked `KPROG_X86_XMM0_ARM` selector,
the two lane offsets through `KPROG_X86_XMM0_LANE_OFFSET`, and the ordinary
arm's base form through `KPROG_X86_XMM0_BASE_FORM` / `_ADDS_DISP` /
`_BASE_PTR`, so the bodies and the Lean refinement share one XMM0
implementation rather than a restated inline ladder. The independent
`test_x86_xmm0_route_host.c` oracle includes the simulator header, drives the
real bodies over the stack arm, a register base, the `X86_REG_NONE` base form
of each opcode (load: raw absolute immediate with the offset discarded; store:
null base with the offset added), and indexed addressing including an index
riding a `X86_REG_NONE` base (the case that separates the two base forms), and
compares the whole modeled heap and stack and the written XMM0 pair against an
independent byte model.

The `CALL_MEMCPY` / `CALL_MEMSET` block-copy/fill theorem covers the four
`X86_SIM_L_EXEC` arms for `X86_OP_CALL_MEMCPY` (`0x3f`), `X86_OP_CALL_MEMCPY_REG`
(`0x46`), `X86_OP_CALL_MEMSET` (`0x3c`), and `X86_OP_CALL_MEMSET_REG` (`0x45`),
the opcodes that move a block of bytes one at a time. The four arms share one
module because they are one composition under three per-opcode facts:
`x86CallMemKindSpec` fixes the array body's shape (copy or fill),
`x86CallMemCountSpec` fixes whether the moved length comes from the
instruction-immediate artifact or the RDX register, and `x86CallMemBoundSpec`
fixes whether the array bound is the hardcoded literal `1024` or the immediate.
`callMemcpy`/`callMemset` (immediate count) iterate to the literal `1024` and
move `min(count, 1024)` bytes; `callMemcpyReg`/`callMemsetReg` (RDX count) are
bounded by the immediate artifact and move `min(RDX, immediate)` bytes. The
headline fact is that the bound form and the count source are *independent* —
the immediate-count bodies take the literal bound, the register-count bodies
the artifact, the opposite of their length source — which
`x86_call_mem_bound_and_count_are_independent` pins by reading the two
selections apart even though their codes coincide (both fixed/immediate are
`0`). `generated_x86_call_mem_step_refines` composes the whole arm over the
kind, count-source, and bound-form selections plus the shared little-endian
byte load/store at width 8; `x86_call_mem_byte_refines` is function-level (the
destination buffer is equal as a function of the index), a copy writes the
source byte and a fill writes the source register's low byte, and
`x86_call_mem_beyond_bound_unchanged` pins that bytes at or beyond the bound —
and at or beyond the count — keep their old values. `x86_call_mem_fixed_bound_is_literal`
and `x86_call_mem_fill_byte_is_low_byte` pin the literal and the low-byte
extraction. Its independent 875-case oracle exercises the generated tables, the
full composition over a deterministic register and memory model, and pins the
literal-vs-artifact bound asymmetry, the copy-vs-fill byte behavior, the
bound/count canaries, the destination-pointer-with-destination-tag `RAX` write,
and the untouched register file and flags. The register decode that selects the
opcode and supplies the immediate remains outside the theorem.

The four `X86_SIM_L_EXEC_CALL_{MEMCPY,MEMSET}{,_REG}` handler bodies now share
one `X86_SIM_L_EXEC_CALL_MEM_STEP` composition that routes the array shape
through the machine-checked `KPROG_X86_CALLMEM_KIND` selector, the
copied/filled length's source through `KPROG_X86_CALLMEM_COUNT_SOURCE`, and the
array bound through `KPROG_X86_CALLMEM_BOUND_FORM` / `_FIXED_BOUND`, so the four
bodies and the Lean refinement share one block-copy/fill implementation rather
than four restated loop ladders. The independent `test_x86_callmem_route_host.c`
oracle includes the simulator header, drives the four real bodies over flat and
overflowing counts and both count sources, and compares the whole modeled heap
and the result-register write against an independent byte model, planting per
opcode a case where each routed fact is numerically distinguishable from the
wrong selection (an artifact-exceeds-`1024` immediate case that a bound-form
swap would run past the literal, and an `RDX`-exceeds-artifact register case
that both a bound-form and a count-source swap would move).

The `PUSH` / `POP` stack-step theorem covers the two `X86_SIM_L_EXEC` arms for
`X86_OP_PUSH` (`0x12`) and `X86_OP_POP` (`0x13`), the opcodes that move one
value between a register and the stack frame. The two arms share one module
because they are one composition under two per-opcode facts:
`x86PushPopStepDirectionSpec` fixes whether the stack pointer steps before the
body's single memory access (PUSH: decrement then store) or after the load and
destination write (POP), and `x86PushPopWidthSourceSpec` fixes whether the body
hardcodes the 64-bit step width (PUSH) or resolves the opcode's FLAGS code with
a 64-bit fallback (POP). `x86_push_pop_facts` pins the headline asymmetry: the
body that pre-decrements is exactly the body that hardcodes 64, and the body
that post-increments is exactly the body that resolves the FLAGS code —
`x86_push_pop_push_ignores_flags` and `x86_push_pop_pop_absent_defaults` read
the two selections apart even though their codes coincide (`preDecrement` and
`hardcoded64` are both `0`). `x86_push_pop_step_amount_is_eight` and
`x86_push_pop_step_independent_of_width` fix the byte amount both bodies step
by: `stackStep` is the literal `8`, and POP steps by it whatever width its FLAGS
code resolves to. `x86_push_pop_push_addr_is_new_rsp` and
`x86_push_pop_pop_addr_is_old_rsp` fix the effective address each body touches
relative to the pointer step, and `x86_push_pop_rsp_round_trip` pins that a pair
returns the pointer. `generated_x86_push_pop_step_refines` composes the whole
arm over the direction and width-source selections plus the shared
`resolveWidth` table (absent FLAGS defaults to `b64`) and the shared
little-endian byte store/load at the resolved width; the POP destination write
goes through `generatedX86RegWrite`, and `x86_push_pop_push_has_no_dst` /
`x86_push_pop_pop_writes_dst` pin that PUSH writes no register while POP does.
Its independent 463-case oracle exercises the generated tables, the full
composition over a deterministic register, stack-frame and flags model, and
pins the direction/width-source independence, the hardcoded-vs-resolved width
asymmetry, the eight-byte step of both directions, the push/pop round trip, the
untouched register file, the narrow-pop partial writeback, and the untouched
flags. The register decode that selects the opcode and supplies the FLAGS code
remains outside the theorem.

The two `X86_SIM_L_EXEC_{PUSH,POP}` handler bodies now share one
`X86_SIM_L_EXEC_PUSH_POP_STEP` composition that routes the step direction
through the machine-checked `KPROG_X86_PUSH_STEP_DIRECTION` selector, the
body that honours the FLAGS code through `KPROG_X86_PUSH_WIDTH_SOURCE`, the
absent-FLAGS default through `KPROG_X86_PUSH_FLAGS_WIDTH`, and the stack step
amount through `KPROG_X86_PUSH_STACK_STEP`, so the two bodies and the Lean
refinement share one stack-transfer implementation rather than two restated
step sequences. The independent `test_x86_pushpop_route_host.c` oracle
includes the simulator header, drives both real bodies — directly and through
the `X86_SIM_L_EXEC` dispatcher arms that route to them — over both directions,
every FLAGS code, and a range of stack pointers, and compares the whole
register file, the whole stack frame, the stack pointer, and the flags against
an independent model. It plants per opcode a case where each routed fact is
numerically distinguishable from the wrong selection: a `PUSH` carrying a
narrow FLAGS code that must still move the stack pointer by eight and store all
eight bytes, a `POP` carrying the absent code that must still read and write
eight bytes, and a direction swap that must move the stack pointer the opposite
way.

The `REP MOVS` block-copy theorem covers the `X86_SIM_L_EXEC_REP_MOVS` arm for
`X86_OP_REP_MOVS` (`0x3a`), the opcode that copies `RSI`-addressed bytes to
`RDI` a bounded number of times. The copy width is the FLAGS-resolved width
`FLAGS ? FLAGS : 64` (`x86_rep_movs_width_refines`,
`x86_rep_movs_width_is_flags_resolved`), the loop bound is the literal `64`
(`x86_rep_movs_bound_refines`, `x86_rep_movs_bound_is_sixty_four`), and the
count the body copies is the raw instruction immediate, not `RCX`
(`x86_rep_movs_count_is_immediate`): the body copies `min 64 count` elements
(`x86_rep_movs_element_count_refines`, `x86_rep_movs_element_count_bounded`)
while each pointer still advances by the full raw count times the copy stride
(`x86_rep_movs_overshoot_beyond_bound`,
`x86_rep_movs_advance_uses_flags_width`). The trailing `RCX` writeback is
independent of the copy width — it zeroes `RCX` at the fixed 64-bit width and
scalarizes its tag whatever `FLAGS` resolved to
(`x86_rep_movs_count_width_refines`, `x86_rep_movs_step_rcx_zeroed`), while the
two pointers keep the provenance tags they were read with
(`x86_rep_movs_tags_preserved`). `x86_rep_movs_step_refines` composes the whole
body over the generated width/`countWidth` tables, the literal bound, and the
shared register-write; its independent 67-case oracle exercises the generated
tables, the full composition over a deterministic register and copy-buffer
model, and pins the narrow-width advance, the bound-vs-raw-count saturation
asymmetry, the zero-count no-op, the fixed 64-bit `RCX` zeroing under a narrow
copy width, the preserved tags, the byte-for-byte copy, and the untouched
flags. The register decode that selects the opcode and supplies the immediate
remains outside the theorem.

The body named in that paragraph now routes through the generated contract:
`X86_SIM_L_EXEC_REP_MOVS` resolves the copy width through
`KPROG_X86_REP_MOVS_WIDTH`, bounds its element loop by
`KPROG_X86_REP_MOVS_BOUND`, and zeroes `RCX` at
`KPROG_X86_REP_MOVS_COUNT_WIDTH`, so the FLAGS width resolution, the literal
loop bound and the fixed 64-bit count-write width are compile-time expansions of
the machine-checked macros rather than committed literals. The independent
`test_x86_rep_movs_route_host.c` oracle includes the simulator header, drives
the real body over all five `FLAGS` codes and counts from zero through past the
literal bound, with separate source/destination windows and distinct provenance
tags on `RSI`/`RDI`, and compares the whole modeled register file with its tags,
`RCX`, and both buffers byte for byte against an independent forward-order
element model. It also restates the closed width-resolution, bound and count
width tables against the routed selectors.

The `ANDN` / `ANDN_MEM` theorem covers the `X86_SIM_L_EXEC_ANDN` and
`X86_SIM_L_EXEC_ANDN_MEM` arms for `X86_OP_ANDN` (`0x3d`) and `X86_OP_ANDN_MEM`
(`0x44`), the opcodes that compute `(~src1) & src2`. The destination write
width is the FLAGS-resolved width `FLAGS ? FLAGS : 64` for both bodies
(`x86_andn_write_width_refines`), and the second-operand source is a per-opcode
table entry (`x86_andn_source_refines`): only the memory form reads memory at
all. The headline fact is the memory-read width, which is *independently
selected* and not the destination write width: the memory form reads at the AUX
field's own width when that field names one, and falls back to the resolved
FLAGS write width when it is absent (`x86_andn_mem_width_refines`,
`x86_andn_mem_width_arm_refines`) — so a narrow AUX width reads narrowly while
the destination still writes at the FLAGS width. `x86_andn_step_refines`
composes the whole body over the generated source/write-width/memory-width
tables and the shared register read, memory load, complement/and, logic-flag
production, and partial-register writeback; its independent 1849-case oracle
exercises the generated tables, the full composition over a deterministic
register and source-memory model, and pins the register/memory source split,
the named-AUX-versus-FLAGS-width divergence, the absent-AUX fallback, the
CF=OF=0 logic-flag production at the write width, the partial-register
writeback, and the write-free memory. The register decode that selects the
opcode remains outside the theorem.

The two `X86_SIM_L_EXEC_ANDN` and `X86_SIM_L_EXEC_ANDN_MEM` handler bodies now
share one `X86_SIM_L_EXEC_ANDN_STEP` composition that routes the second-operand
source through the machine-checked `KPROG_X86_ANDN_SOURCE` selector, the
destination write width through `KPROG_X86_ANDN_WRITE_WIDTH`, and the
*independently selected* memory-read width through `KPROG_X86_ANDN_MEM_WIDTH`,
so the two bodies and the Lean refinement share one complement-and
implementation rather than two restated step sequences. The independent
`test_x86_andn_route_host.c` oracle includes the simulator header, drives both
real bodies — directly and through the `X86_SIM_L_EXEC` dispatcher arms that
route to them — over both opcodes, every FLAGS code, every AUX memory-width
code, several displacements, and several source/destination registers, and
compares the whole register file with its tags and all four flags against an
independent model. It plants per opcode a case where each routed fact is
numerically distinguishable from the wrong selection: a memory form carrying a
named AUX width that differs from the FLAGS write width, so a body reading at
the write width would load the wrong bytes, an absent AUX width that must fall
back to the resolved FLAGS width, and a register-versus-memory source pair.

The `BZHI` / `BZHI_MEM` theorem covers the `X86_SIM_L_EXEC_BZHI` and
`X86_SIM_L_EXEC_BZHI_MEM` arms for `X86_OP_BZHI` (`0x34`) and `X86_OP_BZHI_MEM`
(`0x35`), the BMI2 opcodes that clear the bits at or above a byte-masked bit
count. Both bodies resolve *one* width `FLAGS ? FLAGS : 64`
(`x86_bzhi_width_refines`) and use it for the value read, the count comparison,
and the destination write — there is no second AUX-selected memory width here,
unlike `ANDN_MEM`. The value and count sources are per-opcode table entries
(`x86_bzhi_value_source_refines`, `x86_bzhi_count_source_refines`): `BZHI` reads
its value from `SRC` and its count from `COUNT`, `BZHI_MEM` reads its value from
memory at the resolved width and its count from the register the AUX shift byte
names. The headline fact is the hand-defined flag set
(`x86_bzhi_flags_refines`): `OF = SF = 0` *outright* while `ZF` is the real zero
test of the result, so `SF` is not the result's sign as the shared logic-flag
production would make it; and `CF` is the byte-masked count reaching the
*width's* bit count (`x86_bzhi_cf_is_count_versus_width`), not any property of
the result. The count is byte-masked, so a register holding `0x1ff` behaves as
`0xff` (`x86_bzhi_count_masks_to_byte`). `x86_bzhi_step_refines` composes the
whole body over the generated value/count/width tables and the shared register
read, memory load, `bzhi` bit-clear, hand-defined flag set, and
partial-register writeback; its independent 3264-case oracle exercises the
generated tables, the full composition over a deterministic register and
source-memory model, and pins the register/memory value split, the `COUNT`-vs-AUX
count split, the count byte-masking, the count-versus-width CF, the
SF-cleared/ZF-real asymmetry, the partial-register writeback, and the write-free
memory. The register decode that selects the opcode remains outside the theorem.

The two `X86_SIM_L_EXEC_BZHI` and `X86_SIM_L_EXEC_BZHI_MEM` handler bodies now
share one `X86_SIM_L_EXEC_BZHI_STEP` composition that routes the value source
through the machine-checked `KPROG_X86_BZHI_VALUE_SOURCE` selector, the count
source through `KPROG_X86_BZHI_COUNT_SOURCE`, the byte mask through
`KPROG_X86_BZHI_COUNT_MASK`, and the one width both the read and the write use
through `KPROG_X86_BZHI_WRITE_WIDTH`, so the two bodies and the Lean refinement
share one bit-clear implementation rather than two restated step sequences. The
independent `test_x86_bzhi_route_host.c` oracle includes the simulator header,
drives both real bodies — directly and through the `X86_SIM_L_EXEC` dispatcher
arms that route to them — over both opcodes, every FLAGS code, every AUX width
code, several displacements, and several value/count/destination registers, and
compares the whole register file with its tags and all four flags against an
independent model. It plants per opcode a count whose low byte differs per
register and whose high bit is set, so a body that reads its count (or its
value) from the wrong place lands on a different byte-masked count and a body
that skips the mask clears different bits, with the count's upper bytes
carrying bits a mask wider than `0xff` would fold into the CF comparison.

The `BT` / `BT_IMM` / `BT_MEM_IMM` theorem covers the `X86_SIM_L_EXEC_BT`,
`X86_SIM_L_EXEC_BT_IMM` and `X86_SIM_L_EXEC_BT_MEM_IMM` arms for `X86_OP_BT`
(`0x37`), `X86_OP_BT_IMM` (`0x42`) and `X86_OP_BT_MEM_IMM` (`0x43`), the three
opcodes that test one bit and assign it to `CF`. All three resolve *one* width
`FLAGS ? FLAGS : 64` and narrow the tested base to it before the bit test
(`x86_bt_write_width_refines`); there is no second memory width. The base and
index sources are per-opcode table entries (`x86_bt_base_source_refines`,
`x86_bt_index_source_refines`): `BT` reads its base from a register and its
index from `SRC`, `BT_IMM` reads its base from a register and its index from the
literal immediate, and `BT_MEM_IMM` reads its base from memory at the resolved
width and its index from the immediate widened to 32 bits. The headline fact is
that index-width asymmetry (`x86_bt_imm32_drops_high_bits`): an immediate with a
high bit set selects a different bit through the memory form than through the
immediate form, because `BT_MEM_IMM` drops the high bits while `BT`/`BT_IMM`
keep them. All three bodies write no register and touch only `CF`
(`x86_bt_preserves_dst`, `x86_bt_only_cf`). `x86_bt_step_refines` composes the
whole body over the generated base/index/width tables and the shared register
read, memory load, `bt` bit test, and flag pass-through; its independent
4883-case oracle exercises the generated tables, the full composition over a
deterministic register and source-memory model, and pins the base-source split,
the three-way index-source split, the index-width asymmetry, the `CF`-only
write, the register-preserving write-free memory, and the absent-width default.
The register decode that selects the opcode remains outside the theorem.

The `X86_SIM_L_EXEC_BT`, `X86_SIM_L_EXEC_BT_IMM` and
`X86_SIM_L_EXEC_BT_MEM_IMM` handler bodies now share one
`X86_SIM_L_EXEC_BT_STEP` composition that routes the tested base through the
machine-checked `KPROG_X86_BT_BASE_SOURCE` selector, the bit index through
`KPROG_X86_BT_INDEX_SOURCE`, and the one resolved width through
`KPROG_X86_BT_WRITE_WIDTH`, so the three bodies and the Lean refinement share
one bit-test implementation rather than three restated step sequences. The
independent `test_x86_bt_route_host.c` oracle includes the simulator header,
drives all three real bodies — directly and through the `X86_SIM_L_EXEC`
dispatcher arms that route to them — over all three opcodes, every FLAGS code,
every AUX width code, four displacements, and three base / index / destination
registers, and compares the whole register file with its tags and all four
flags against an independent model. Its planted register low bytes carry bit 5
and its values carry bits above bit 32, so a body that resolves the wrong
index mask (`& 63` at 64 bits, `& 31` below) or that narrows the base to 32
bits instead of the resolved width is numerically distinguishable; for the
memory form it complements the tested bit of the loaded byte against the
pointer value the base register holds, so a body that reads the base register
instead of memory reports the opposite `CF` at every index source.

The `CMP_IMM` / `CMP_REG` / `TEST_IMM` / `TEST_REG` theorem covers the
`X86_SIM_L_EXEC_CMP_IMM_OP` and `X86_SIM_L_EXEC_CMP_REG_OP` arms for
`X86_OP_CMP_IMM` (`0x0c`), `X86_OP_CMP_REG` (`0x0d`), `X86_OP_TEST_IMM`
(`0x0e`) and `X86_OP_TEST_REG` (`0x0f`), the four opcodes that compare or test
without writing a register. All four resolve *one* width `FLAGS ? FLAGS : 64`
and read their destination lane through the width/lane register read
(`x86_cmpop_write_width_refines`). Two per-opcode facts separate them, both
table entries (`x86_cmpop_rhs_source_refines`, `x86_cmpop_flag_kind_refines`):
the right-hand side is the decoded immediate for the `_IMM` forms
(`x86ImmediateValueSpec`) and the width/lane register read of `SRC` for the
`_REG` forms, and the flag kind is the zero-borrow subtraction flags for the
`CMP` opcodes and the logical flags of the width-narrowed conjunction for the
`TEST` opcodes. The tables are provably independent
(`x86_cmpop_tables_independent`): `CMP_IMM`/`TEST_IMM` share a source but differ
in flag kind, and `CMP_IMM`/`CMP_REG` share flags but differ in source, so no
row is a function of another. All four write no register
(`x86_cmpop_preserves_dst`, `x86_cmpop_flag_production`). `x86_cmpop_step_refines`
composes the whole body over the generated source/flag-kind/width tables and the
shared register read, immediate decode, subtraction/logical flag production, and
register pass-through; its independent 2904-case oracle exercises the generated
tables, the full composition over a deterministic register model at both AUX
lanes, and pins the immediate/register source split, the CMP/TEST flag-kind
split, the destination-lane and `SRC`-lane reads, the immediate sign-extension
at the resolved width, the absent-width default, and register-preserving
write-free memory. The register decode that selects the opcode remains outside
the theorem.

The four bodies named in that paragraph now share one
`X86_SIM_L_EXEC_CMP_REG_STEP` composition that routes the right-hand-side
source through the machine-checked `KPROG_X86_CMPOP_RHS_SOURCE` selector, the
flag kind through `KPROG_X86_CMPOP_FLAG_KIND`, and the one resolved width
through `KPROG_X86_CMPOP_WRITE_WIDTH`, so the four bodies and the Lean
refinement share one compare/test step rather than four restated sequences and
the per-opcode selector is compile-time at each wrapper. The independent
`test_x86_cmpop_route_host.c` oracle includes the simulator header, drives all
four real bodies — directly and through the `X86_SIM_L_EXEC` dispatcher arms
that route to them — over both register/immediate source forms, every FLAGS
code, both AUX lanes, and three destination / source registers, and compares
the whole register file with its tags and all four flags against an
independent model. Its planted registers carry the immediate-incompatible high
word `0xa5a5…` and bits above bit 32, so a body that resolves the wrong
right-hand side, produces the wrong flag kind (`CMP` clears `OF` and computes
`CF` from the borrow, `TEST` clears both), or narrows to 32 bits instead of the
resolved width is numerically distinguishable at every opcode, width, and lane.

The AArch64 `.D0` / `.Q0` vector memory-transfer theorem covers the four bodies
`ARM64_SIM_L_LOAD_D0_MEM`, `LOAD_Q0_MEM`, `STORE_D0_MEM`, and `STORE_Q0_MEM` for
`ARM64_OP_LOAD_D0` (`0x28`), `ARM64_OP_STORE_D0` (`0x29`), `ARM64_OP_LOAD_Q0`
(`0x2a`), and `ARM64_OP_STORE_Q0` (`0x2b`), the opcodes that move a SIMD
register's low 64-bit lane (`.D0`) or both 64-bit lanes (`.Q0`) to or from
memory. The address offset (`MEM_BASE_OFF`) and the pre/post base adjustment
(`MEM_PRE` / `MEM_POST`) stay in the macros with their own proved contracts, so
the generated `arm64_dq_mem` tables fix only *which* lanes each opcode moves and
in *what* order: two per-opcode facts, provably independent, are the access
direction (`arm64_dq_mem_access_dispatch`) -- `LOAD_D0`/`LOAD_Q0` move memory
into the register, `STORE_D0`/`STORE_Q0` move it out -- and the ordered lane plan
(`arm64_dq_mem_lane_plan`) -- `.D0` moves `[0]`, `.Q0` moves `[0, 8]`, so the two
lanes of a `.Q0` transfer are the low lane at the base offset and the high lane
one 64-bit lane stride higher, never the same lane twice
(`arm64_dq_mem_q0_moves_distinct_lanes`). `arm64_dq_mem_refines` pins the
generated lane offsets to the independent plan literally, and
`arm64_dq_mem_lane_count_refines` pins the generated lane count to the plan
length. Its independent 9,216-case oracle drives the generated selectors and
restates the same four bodies from the raw opcode, comparing the SIMD lanes, the
whole GPR file, memory and the stack; four binding mutations -- an access
direction swap, a lane count swap, a lane-stride change (caught by the C static
assertion) and a selector-arm swap -- each change the observable result. The
register decode that selects the opcode remains outside the theorem.

The four bodies named in that paragraph now share one
`ARM64_SIM_L_DQ_MEM_STEP` that routes the access direction through
`KPROG_ARM64_DQ_MEM_*_ACCESS`, the lane count through
`KPROG_ARM64_DQ_MEM_*_LANES`, the arm index through
`KPROG_ARM64_DQ_MEM_INDEX`, and the lane plan through
`KPROG_ARM64_DQ_MEM_LANE_STRIDE` / `KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE`, so the
four thin opcode wrappers cannot drift and the direction, lane count and lane
stride are machine-checked facts rather than restated sequences. The independent
`test_arm64_dq_mem_route_host.c` oracle includes the simulator header, drives all
four real bodies — directly and through the `ARM64_SIM_L_EXEC` dispatcher arms
that route to them — over the four opcodes, five base-register classes (scalar,
ABI pointer, relocation address, a stack-pointer-register alias and the stack
pointer itself), every pre/post flag combination, both index modes and three
immediates, and compares the whole GPR file with its tags, the stack pointer, the
SIMD quarters, the whole stack image with its slot tags, and all 4 KiB of the
memory window against an independent byte-image model. Its planted base
registers carry distinct provenance classes and its planted SIMD lanes carry
distinct patterns, so a body that swaps the direction, selects the wrong lane
count, moves the wrong lane into the high half, or drops the second `.Q0` lane is
numerically distinguishable at every case.

The AArch64 `LDP` / `STP` pair-move theorem covers the two bodies
`ARM64_SIM_L_LDP` and `ARM64_SIM_L_STP` for `ARM64_OP_LDP` (`0x21`) and
`ARM64_OP_STP` (`0x22`), the load/store-pair opcodes that move two 64-bit slots
between memory and a register pair. As with the `.D0`/`.Q0` theorem the address
offset (`MEM_BASE_OFF`) and the pre/post base adjustment (`MEM_PRE` /
`MEM_POST`) stay in the macros with their own proved contracts, so the generated
`arm64_pair_mem` tables fix only *which* slots each opcode moves and in *what*
order. Two per-opcode facts, provably independent, are the access direction
(`arm64_pair_mem_access_dispatch`) -- `LDP` moves memory into the register pair,
`STP` moves it out -- and the ordered slot plan (`arm64_pair_mem_slot_plan`) --
both opcodes move `[0, 8]`, so the pair's two slots are the low slot at the base
offset and the high slot one 64-bit slot stride higher, never the same slot twice
(`arm64_pair_mem_moves_distinct_slots`). The register-pair mapping is the
distinctive composition: on a load the low slot lands in `DST` and the high slot
in `SRC`; on a store the low slot comes from `SRC` and the high slot from `SRC2`.
`arm64_pair_mem_refines` pins the generated slot offsets to the independent plan
literally, and `arm64_pair_mem_slot_count_refines` pins the generated slot count
to the plan length. Its independent multi-hundred-thousand-case oracle drives
the generated selectors and restates both bodies from the raw opcode
read-before-write -- gathering both slots before writing the register pair, so a
target register that is also the base still reads the original base -- comparing
the whole GPR file, tags, memory and the stack; four binding mutations -- an
access-direction swap, a slot-count swap, a slot-stride change, and a
selector-arm swap -- each change the observable result. The register decode that
The AArch64 `LDP` / `STP` pair-move bodies now share one
`ARM64_SIM_L_PAIR_MEM_STEP` that routes the access direction through
`KPROG_ARM64_PAIR_MEM_*_ACCESS` (via the `KPROG_ARM64_PAIR_MEM_INDEX` arm
selector), the slot count through `KPROG_ARM64_PAIR_MEM_SLOT_COUNT`, and the slot
plan through the parameterized slot-index-times-access-width offset, so the two
thin opcode wrappers cannot drift and the direction, slot count and slot stride
are machine-checked facts rather than restated sequences. The independent
`test_arm64_pair_mem_route_host.c` oracle includes the simulator header, drives
both real bodies -- directly and through the `ARM64_SIM_L_EXEC` dispatcher arms
that route to them -- over both opcodes, five base-register classes (scalar, ABI
pointer, relocation address, a stack-pointer-register alias and the stack pointer
itself), every pre/post flag combination, all four access widths, both index
modes and three immediates, and compares the whole GPR file with its tags, the
stack pointer, the whole stack image with its slot tags, and all 4 KiB of the
memory window against an independent byte-image model. A body that swaps the
direction or the arm, selects the wrong slot count or stride, drops the second
slot, or takes the low store value from the high source register is numerically
distinguishable at every case. The register decode that selects the opcode
remains outside the theorem.

The AArch64 pre/post-indexed address-writeback theorem covers the two bodies
`ARM64_SIM_L_MEM_PRE` and `ARM64_SIM_L_MEM_POST`, which apply the address-offset
immediate to the base register before (pre-index) or after (post-index) an
access. This contract is a *decode* of the packed memory-flag byte that both
bodies and the offset macro share: the byte is the top byte of the packed `AUX`
word (`aux >>> 24 & 0xff`, matching `ARM64_SIM_L_MEM_FLAGS`), `MEM_PRE` (`1`) and
`MEM_POST` (`2`) are independent bits, and each body's gate is the matching bit
`arm64_mem_prepost_pre_writeback` / `arm64_mem_prepost_post_writeback`. The
offset macro (`MEM_BASE_OFF`) suppresses its immediate exactly when either bit is
set (`arm64_mem_prepost_suppress_offset`), so `[base, imm]!` and `[base], imm`
contribute the immediate as their own writeback rather than in the offset, and
because the bits are independent a byte with both set applies the same immediate
twice, once before and once after
(`arm64_mem_prepost_delta_refines`, `arm64_mem_prepost_form_is_sum`), with the
writeback count bounded by the two bits (`arm64_mem_prepost_form_bounded`). Its
independent oracle drives the generated decode/select macros over every flag byte
crossed with low-byte noise that must not leak into the flag byte and a spread of
immediates, restating the top-byte decode, the suppression gate and the two
gated deltas from the raw `AUX` word; three binding mutations -- a bit swap in the
C macro, a flag-shift change, and a pre-delta gate swap -- each change the
observable result (a fourth, a Lean bit change, is caught by the refinement
theorem). The register and opcode decode that frame a pre/post access remain
outside the theorem, but both bodies now call the generated `arm64_mem_prepost.h`
macros (`KPROG_ARM64_MEM_PREPOST_PRE_DELTA` / `_POST_DELTA`, and the offset
macro's `KPROG_ARM64_MEM_PREPOST_SUPPRESS` gate), so the writeback selection is
the proved decode and only the untouched register/opcode decode remains in the
trusted computing base. A second, sim-header-driven oracle plants distinct
base-register provenance classes (scalar, ABI pointer, relocation address, a
stack-tagged register and the stack pointer itself) and drives both real bodies
both directly and through the `ARM64_OP_LOAD` / `ARM64_OP_STORE` dispatcher arms
over every flag combination, both index modes, all four access widths and three
immediates, comparing the whole register file with tags, the stack pointer and
the memory image against an independent raw-flag model; a swapped delta macro,
a zeroed or constant suppression argument and a mis-set flag bit are numerically
distinguishable.

The AArch64 vector-register-file half-mapping theorem covers the four
vector memory-transfer bodies `ARM64_SIM_L_LOAD_D0_MEM`, `LOAD_Q0_MEM`,
`STORE_D0_MEM` and `STORE_Q0_MEM`, which move a SIMD register's low 64-bit half
(`.D0`) or both halves (`.Q0`) between memory and the two independent
vector-register state fields `__a64_v0` (low half, slot offset 0) and
`__a64_v0_hi` (high half, slot offset 8). This contract fixes *which state field
each half maps into and in which order the halves are touched*: a `.D0` transfer
touches the low half only (`arm64_vreg_plan`) while a `.Q0` transfer touches the
low half and then the high half (`arm64_vreg_refines`, `arm64_vreg_half_plan`),
the two halves are distinct slots (`arm64_vreg_halves_distinct`) and a `.Q0`
plan touches two distinct halves (`arm64_vreg_q0_touches_distinct_halves`), and
the four-way `LOAD_D0 / LOAD_Q0 / STORE_D0 / STORE_Q0` chain covers each opcode
once in the order the generated arm index names (`arm64_vreg_arm_index_dispatch`)
with the load/store direction a per-opcode fact (`arm64_vreg_access_dispatch`).
This is distinct from the `.D0`/`.Q0` lane-plan contract, which fixes the
*memory* lanes a transfer touches, not the vector-register state field each lane
maps into. Its independent oracle drives the generated
`KPROG_ARM64_VREG_HALF_OFFSET` / per-opcode `SELECT` / `HALVES` / `ACCESS` macros
over every opcode crossed with all 32 base registers, the pre/post flag set and a
spread of immediates and vector-register state pairs, restating the same bodies
from the raw opcode; eight binding mutations -- a half-offset swap, a D0/Q0
selector swap, a half-count swap and a Q0 order reversal in the C macros, a
state-field-name swap and an offset alias in the spec, and a plan-literal and a
generated-offset change in Lean -- each change the observable result. The four
bodies now route through the generated `arm64_vreg.h` macros: the shared
`ARM64_SIM_L_DQ_MEM_STEP` selects the half count and per-position half from the
`KPROG_ARM64_VREG_INDEX` chain and the per-opcode `HALVES` / `SELECT`
constants, maps each half through `KPROG_ARM64_VREG_HALF_OFFSET` into the low
`__a64_v0` or high `__a64_v0_hi` state field, and touches the halves in the
generated plan order, so the field mapping and write order are the proved
contract and only the untouched opcode decode remains in the trusted computing
base. A second, sim-header-driven oracle drives the four real bodies both
directly and through the `ARM64_SIM_L_EXEC` dispatcher arms over every opcode
crossed with the five planted base-provenance classes (scalar, ABI pointer,
relocation address, stack-tagged register and the stack pointer), the pre/post
flag set, both index modes and three immediates, comparing the whole register
file with tags, the stack pointer, the two vector state fields, the whole stack
image with its slot tags and the whole memory window against an independent
raw-opcode model; a pinned arm index, a dropped high half, a swapped half
selector or a flattened half offset is numerically distinguishable at every
case.

The AArch64 MVN/NEG unary-value theorem covers the two unary value bodies
`ARM64_OP_MVN` and `ARM64_OP_NEG`, which write the destination-width-narrowed
bitwise complement (`MVN`) or two's-complement negation (`NEG`) of a source
register. The contract is the two opcode labels and the width-narrowed raw
value: `arm64_unary_refines` proves the generated
`KPROG_ARM64_UNARY_VALUE` arm equals an independent statement whose MVN arm is
an exclusive-or with the all-ones word (`src ^^^ 0xffffffffffffffff`) and whose
NEG arm is the invert-and-add-one identity (`~~~src + 1`) -- deliberately not
the complement or subtraction operator the generated arm uses -- over both
operations and all four destination widths. Both opcodes are pinned inside the
`15..16` case-label range (`arm64_unary_code_in_range`, `arm64_unary_code_dispatch`),
neither writes NZCV (`arm64_unary_flags_unchanged`), the doubleword complement is
self-inverse (`arm64_unary_mvn_self_inverse`) and a doubleword negation cancels
its source (`arm64_unary_neg_add_cancel`). Its independent oracle derives the
destination width mask from a shift of one (never the macro's width-mask ladder),
sweeps the two operations over boundary vectors and all four widths plus a
fixed-seed random sweep, and checks that an opcode outside the two aborts; five
binding mutations -- the C case-body swap, a dropped NEG width mask, a spec
code swap, and a Lean NEG-identity and MVN-narrowing change -- each change the
observable result or the refinement theorem. Unlike the two preceding AArch64
contracts, the dispatch body now calls the generated `arm64_unary.h` macro, so
the unary value itself is lifted out of the trusted computing base; the
surrounding register read and width-narrowed register write remain outside the
theorem.

The AArch64 CNEG condition-gated negation theorem covers the one value body
`ARM64_OP_CNEG`, which on a taken condition writes the destination-width-negated
source and otherwise passes the source through unchanged. The contract is the
opcode label, the already evaluated condition result, and the width-narrowed raw
value: `arm64_cneg_refines` proves the generated `KPROG_ARM64_CNEG_VALUE` arm
equals an independent statement whose taken arm is the invert-and-add-one
identity (`~~~src + 1`) -- deliberately not the subtraction operator the
generated arm uses -- over both condition outcomes and all four destination
widths. The opcode is pinned inside its `65` case-label range
(`arm64_cneg_code_in_range`, `arm64_cneg_code_dispatch`), it writes no NZCV
(`arm64_cneg_flags_unchanged`), a taken negation cancels its source
(`arm64_cneg_taken_cancel`), an untaken condition is the identity
(`arm64_cneg_untaken_identity`), and a word-width result carries no bits above
bit 31 (`arm64_cneg_w32_bound`). Its independent oracle derives the destination
width mask from a shift of one (never the macro's width-mask ladder), checks the
negation against both the subtraction operator and the invert-and-add-one
identity, sweeps both condition outcomes over boundary vectors and all four
widths plus a fixed-seed random sweep, and checks that an opcode outside the
family aborts; seven binding mutations -- a dropped condition gate, an inverted
condition gate, and a dropped width mask in the generated C, a spec code move,
a Lean branch swap and narrowing drop, and an independent-spec narrowing drop --
each change the observable result or the refinement theorem. As with the
preceding unary contract, the dispatch body calls the generated `arm64_cneg.h`
macro, so the condition-gated negation value is lifted out of the trusted
computing base; the surrounding register read, condition evaluation, and
width-narrowed register write remain outside the theorem.

The AArch64 ORN complemented-logical-OR theorem covers the one value body
`ARM64_OP_ORN_REG`, which writes the destination-width-narrowed OR of the first
source with the bitwise complement of the already source-modified second source.
The contract is the opcode label and the width-narrowed raw value:
`arm64_orn_refines` proves the generated `KPROG_ARM64_ORN_VALUE` arm equals an
independent De Morgan statement (`~~~((~~~lhs) &&& rhs)`) -- deliberately not the
OR-with-complement the generated arm uses -- over all four destination widths,
and `arm64_orn_de_morgan` proves the two forms agree. The opcode is pinned inside
its `53` case-label range (`arm64_orn_code_in_range`, `arm64_orn_code_dispatch`),
it writes no NZCV (`arm64_orn_flags_unchanged`), a zero second source yields the
all-ones word (`arm64_orn_zero_rhs_all_ones`), a zero first source yields the
complement of the second (`arm64_orn_zero_lhs_complement`), and a word-width
result carries no bits above bit 31 (`arm64_orn_w32_bound`). Its independent
oracle derives the destination width mask from a shift of one (never the macro's
width-mask ladder), applies both the De Morgan and the direct OR-with-complement
forms and requires them equal, composes the existing `KPROG_ARM64_MOD_VALUE`
contract for the right-hand source modification, sweeps both operands over
boundary vectors and every modifier code across all four widths plus a fixed-seed
random sweep, and checks that an opcode outside the family aborts; seven binding
mutations -- a dropped complement, a swapped OR, and a dropped width mask in the
generated C, a spec code move, a Lean complemented-lhs swap, and an
independent-spec complement drop and narrowing drop -- each change the observable
result or the refinement theorem. The dispatch body calls the generated
`arm64_orn.h` macro, so the complemented-OR value is lifted out of the trusted
computing base; the surrounding register reads, source modification, and
width-narrowed register write remain outside the theorem.

The AArch64 ADRP relocation-tag theorem covers the two page-address opcodes
`ARM64_OP_ADRP_GOT` and `ARM64_OP_ADRP_RODATA`, one contract under two per-opcode
facts: the GOT form tags the page-address write as a relocation address
(`ARM64_SIM_TAG_RELOC_ADDR`) and the RODATA form as a read-only-data address
(`ARM64_SIM_TAG_RODATA_ADDR`), and both write through the same tagged-pointer
register write. The contract is the opcode label and the selected provenance tag;
`arm64_adrp_tag_refines` proves the generated `KPROG_ARM64_ADRP_TAG` table equals
an independent Boolean-indexed selection (a relocation-tag base plus a GOT/RODATA
offset), deliberately not a restatement of the two-arm match, and
`arm64_adrp_isgot_refines` proves the GOT/RODATA classification matches the
opcode itself. The two opcodes are pinned (`arm64_adrp_code_dispatch`), the two
tags are distinct and inside the `ARM64_SIM_TAG_*` range
(`arm64_adrp_tags_distinct`, `arm64_adrp_tag_in_range`), so a mislabeled split or
a swapped tag changes the observable result. Its independent oracle classifies
the opcode itself (never the macro's tag ladder), requires the two tags distinct
and in range, and exhaustively drives all 256 opcode bytes in forked children,
requiring each known kind to return the oracle's tag and each unknown byte to
abort through the generated unsupported arm; seven binding mutations -- a swapped
relocation tag, a moved case label, a spec code move, and a spec tag change, plus
a generated-table value change, an independent-spec base change, and a flipped
GOT classification in Lean -- each change the observable tag or the refinement
theorem. The dispatch body calls the generated `arm64_adrp.h` macro, so the
relocation-tag selection is lifted out of the trusted computing base; the
immediate page address, the register-file lookup, and the tagged-pointer write
remain outside the theorem.

The AArch64 STLXR exclusive-store-status theorem covers the one value body
`ARM64_OP_STLXR`: the store-release-exclusive succeeds unconditionally in this
simulator, so the status written back to the destination register is the success
code `0`, narrowed to the word width the handler writes
(`ARM64_SIM_L_WRITE_REG_WIDTH((DST), …, ARM64_WIDTH_32)`). `arm64_stlxr_refines`
proves the generated `KPROG_ARM64_STLXR_VALUE` arm equals an independent
statement that derives the status as the destination-width mask with itself
subtracted (`narrow (mask width - mask width) width`) -- deliberately not a bare
restatement of the literal `0` -- and `arm64_stlxr_success_zero` proves that
status is the zero code at every width. The opcode is pinned to its case-label
code 56 (`arm64_stlxr_code_dispatch`, `arm64_stlxr_code_in_range`),
`arm64_stlxr_flags_unchanged` records that the handler writes no NZCV, and
`arm64_stlxr_w32_bound` bounds the word-width status. Its independent oracle
derives the destination width mask from a shift of one rather than the macro's
width-mask ladder, forms the success code as that mask with itself subtracted and
requires it zero at every width, then sweeps the opcode over all 256 byte values
and all four destination widths in forked children, requiring each known opcode
to return the zero status and each unknown byte to abort through the generated
unsupported arm; six binding mutations -- a nonzero success status, a dropped
width narrowing, and a moved case label in the generated C, a spec code move, and
a nonzero generated status and a nonzero independent-spec code in Lean -- each
change the observable status or the refinement theorem. The dispatch body calls
the generated `arm64_stlxr.h` macro, so the success-status encoding is lifted out
of the trusted computing base; the memory write, the source-register value and
tag reads, and the status-register write remain outside the theorem.

The AArch64 MOV provenance-path theorem covers the two move opcodes
`ARM64_OP_MOV_IMM` and `ARM64_OP_MOV_REG`, one routing decision under two
per-opcode facts: the simulator writes the destination register either through
the tag-copy register write (which carries the source register's provenance) or
through a width-narrowed scalar write (which drops it), and the choice is fixed
by the mnemonic plus the access width. `arm64_mov_path_refines` proves the
generated `KPROG_ARM64_MOV_PTR_TAG_PATH` table equals an independent predicate
"register-source move and doubleword width", deliberately not a restatement of
the macro's switch, so only the register-source move at doubleword width preserves
provenance; `arm64_mov_imm_never_ptr`, `arm64_mov_reg_ptr_iff_w64` and
`arm64_mov_reg_sub_word_drops` pin the three asymmetric cases, and
`arm64_mov_width_matters` shows each move has a tag-dropping width, so the width
is load-bearing rather than the mnemonic alone. The two opcodes are pinned
(`arm64_mov_code_dispatch`, `arm64_mov_imm_code_in_range`,
`arm64_mov_reg_code_in_range`). Its independent oracle decides tag preservation
from the mnemonic class and the access width (never the macro's switch) and
sweeps the opcode over all 256 byte values and all four widths in forked
children, requiring each known move to return the oracle path and each unknown
opcode to abort through the generated unsupported arm; seven binding mutations --
a MOV_IMM that wrongly takes the tag-copy path, a MOV_REG tag-copy that ignores
the width, a moved case label, and a dropped coverage disjunct in the generated
C, a spec code swap, and a generated sub-word register-move tagging and an
independent-width-condition drop in Lean -- each change the observable path or
the refinement theorem. The dispatch body calls the generated `arm64_mov.h`
macro, so the routing decision is lifted out of the trusted computing base; the
source value and tag reads and the two register writes remain outside the theorem.

The AArch64 sign-extending-load width theorem covers the three load opcodes
`ARM64_OP_LDRSB`, `ARM64_OP_LDRSW`, and `ARM64_OP_LDRSH`. Each handler read a
hardcoded memory width before sign-extending the loaded value into the
destination; the load width is now the generated contract. `arm64_ldrsx_width_refines`
proves the generated `KPROG_ARM64_LDRSX_LOAD_WIDTH` table equals an independent
statement keyed on the numeric opcode code---deliberately not a restatement of the
macro's switch---so the byte load reads a byte, the halfword load a halfword, and
the word load a word. The load width is fixed by the opcode's code alone
(`arm64_ldrsx_width_code_determined`), the three widths are pairwise distinct
(`arm64_ldrsx_widths_distinct`), the bit count matches the bytes read
(`arm64_ldrsx_bytes_match`), every width is strictly below 64 so the shared
sign-extension step is always load-bearing (`arm64_ldrsx_width_lt_64`), and the
three opcodes are pinned (`arm64_ldrsx_code_dispatch` and the three independent
range pins). Its independent oracle decides the load width from the numeric
opcode code (never the macro's switch) and sweeps the opcode over all 256 byte
values in forked children, requiring each known load to return the oracle width
and each unknown opcode to abort through the generated unsupported arm; seven
binding mutations---a byte load that reads a word, a word load that reads a
halfword, a moved case label, and a dropped coverage disjunct in the generated C,
a spec load-width swap, and a generated halfword-load that reads a byte and an
independent code-to-word mislabel in Lean---each change the observable width or
the refinement theorem. The dispatch body calls the generated `arm64_ldrsx.h`
macro, so the load-width decision is lifted out of the trusted computing base; the
memory read, the load-width-keyed sign-extension operand selection, and the
destination write remain outside the theorem.

The AArch64 plain-load provenance-preservation theorem covers the ordinary
`LDR` (`ARM64_OP_LOAD`). Its handler chose between the tag-copy register write
(which attaches the memory-read provenance tag) and the tag-dropping
width-narrowed scalar write with an inline `width == 64 && tag != SCALAR`;
whether a load preserves provenance is now the generated contract.
`arm64_load_tag_refines` proves the generated `KPROG_ARM64_LOAD_TAG_PRESERVE`
table equals an independent statement keyed on the width's bit count and the
tag's scalar class---deliberately not a restatement of the macro's conjunction---
so the tag survives only at doubleword width and only when it is not the bare
scalar tag. `arm64_load_tag_sub_word_drops`, `arm64_load_tag_scalar_drops`,
`arm64_load_tag_w64_non_scalar_preserves` and `arm64_load_tag_preserve_iff` pin
the three cases, `arm64_load_tag_preserving_width_is_w64` shows only the
doubleword width can carry provenance, and the opcode is pinned
(`arm64_load_tag_code_dispatch`, `arm64_load_tag_code_in_range`). Its independent
oracle decides preservation from the width and the tag class (never the macro's
switch) and sweeps the opcode over all 256 byte values crossed with the four
widths and the two tag classes in forked children, requiring each known load to
return the oracle routing bit and each unknown opcode to abort through the
generated unsupported arm; seven binding mutations---a preservation that ignores
the width, one that ignores the scalar class, a moved case label, a wrongly
inverted scalar guard, and a spec preserve-rule change, a generated guard drop and
an independent scalar-class inversion in Lean---each change the observable path or
the refinement theorem. The dispatch body calls the generated `arm64_load_tag.h`
macro, so the routing decision is lifted out of the trusted computing base; the
memory read, the tag read, and both register writes remain outside the theorem.

The AArch64 pair-load provenance-preservation theorem covers `LDP`
(`ARM64_OP_LDP`). Its handler read two 64-bit slots, each with its own
memory-read provenance tag, and decided per slot whether to write through the
tag-copy register write (attaching that slot's tag) or the tag-dropping
width-narrowed scalar write, under an outer pair gate
`width == 64 && (tagLo != SCALAR || tagHi != SCALAR)`; the routing decision is
now the generated contract. `arm64_pair_load_tag_refines` proves the generated
gate-then-per-slot `routeMask` equals an independent per-slot statement keyed on
the width's bit count and each tag's scalar class---deliberately not phrased
through the generated gate, so the theorem shows the gate is redundant with the
per-slot rule---and `arm64_pair_load_tag_gate_iff`,
`arm64_pair_load_tag_both_scalar`, `arm64_pair_load_tag_sub_word_drops`,
`arm64_pair_load_tag_only_low_preserves`, `arm64_pair_load_tag_only_high_preserves`,
`arm64_pair_load_tag_both_preserve` and
`arm64_pair_load_tag_routing_width_is_w64` pin the gate and each slot case;
`arm64_pair_load_tag_slot_count` and the opcode lemmas
(`arm64_pair_load_tag_code_dispatch`, `arm64_pair_load_tag_code_in_range`) close
the layout. Its independent oracle decides each slot's bit from the width and
that slot's tag class (never the macro's gate) and sweeps the opcode over all 256
byte values crossed with the four widths and the four tag-class pairs in forked
children, requiring each known pair load to return a mask whose two slot bits
match the oracle and each unknown opcode to abort through the generated
unsupported arm; seven binding mutations---a gate that drops the width conjunct, a
high slot routed by the low slot's tag, a moved case label, swapped slot route
bits, and a spec preserve-rule change, a generated gate width-drop and an
independent slot-weight swap in Lean---each change the observable mask or the
refinement theorem. The dispatch body calls the generated `arm64_pair_load_tag.h`
macro and its two slot accessors, so the routing decision is lifted out of the
trusted computing base; the two memory reads, the two tag reads, and the four
register writes remain outside the theorem.

The AArch64 FMOV destination-routing theorem covers `ARM64_OP_FMOV`. Its handler
applies the generated value selection to the moved value and then decides which
register file receives it: a vector-destination direction writes `v0`, while a
register-destination direction writes the general-purpose destination through
the ordinary width-narrowed register write. The routing was inlined as the
disjunction `AUX == D_FROM_X || AUX == S_FROM_W`; whether the result goes to the
vector file is now the generated contract. `arm64_fmov_dest_refines` proves the
generated `vectorDestination` routing equals an independent parity-and-range
statement keyed on the direction code---deliberately not a restatement of the
generated match arms---and `arm64_fmov_dest_parity`,
`arm64_fmov_dest_out_of_range`, `arm64_fmov_dest_complement`,
`arm64_fmov_dest_code_dispatch` and `arm64_fmov_dest_code_in_range` pin each
direction, the out-of-range behaviour, the complement relation and the opcode
layout. Its independent oracle decides the routing bit from the direction code's
parity and range (never the macro's switch) and sweeps the direction over all 256
byte values in forked children, requiring each in-range code to return the oracle
bit and each out-of-range code to abort through the generated unsupported arm;
seven binding mutations---two direction arms flipped onto the wrong register
file, a moved case label, an opcode static-assert drift, a spec routing-rule
change, a generated routing arm parity drop and an independent parity flip in
Lean---each change the observable routing bit or the refinement theorem. The
dispatch body calls the generated `arm64_fmov_dest.h` macro, so the routing
decision is lifted out of the trusted computing base; the value selection, the
width-narrowed register write, and the `v0` assignment remain outside the
theorem.

The AArch64 conditional-select pointer-path theorem covers the eight-member
`CSEL`/`CINC`/`CSET`/`CINV`/`CSINV`/`CSINC`/`CSETM`/`CSNEG` family
(`KPROG_ARM64_CSEL_HANDLED`). Its handler inlines an
`(OP) == ARM64_OP_CSEL && width == 64` test that selects between the tag-copy
register write (which carries the selected source register's provenance tag) and
the tag-dropping width-narrowed scalar write; which write path runs is now the
generated contract. `arm64_csel_ptr_refines` proves the generated
`ptrTagPath` table agrees with an independent statement---the plain `CSEL` at
doubleword width is the pointer-preserving operation, every other family member
and every sub-word width is not---and `arm64_csel_ptr_only_csel`,
`arm64_csel_ptr_csel_iff_w64`, `arm64_csel_ptr_csel_sub_word_drops`,
`arm64_csel_ptr_family_drops`, `arm64_csel_ptr_code_dispatch` and
`arm64_csel_ptr_code_in_range` pin each binding case. The host cross-check
verifies `KPROG_ARM64_CSEL_PTR_TAG_PATH` against an independent opcode-class and
width oracle (never the macro's switch) and sweeps the opcode over all 256 byte
values and all four widths in forked children, requiring each family opcode to
return the oracle bit and each non-family opcode to abort through the generated
unsupported arm; seven binding mutations---the pointer family arm inverted, a
sub-word width accepted on the pointer arm, a family arm flipped onto the
width test, a moved case label, an opcode static-assert drift, a spec pointer-op
change, and a generated/independent pointer-rule divergence in Lean---each change
the observable routing bit or the refinement theorem. The dispatch body calls
the generated `arm64_csel_ptr.h` macro, so the pointer-path routing decision is
lifted out of the trusted computing base; the condition evaluation, the register
reads, the tag value, and the two register writes remain outside the theorem.

The AArch64 flag-family operand-source theorem covers the six NZCV-producing arm
pairs `SUBS`/`ADDS`/`CMP`/`TST`/`ANDS`/`CCMP` (`SUBS_IMM`/`SUBS_REG` and the
five other pairs). Each arm inlined the same
`(OP) == ARM64_OP_<F>_IMM ? immediate : register` selection for its right-hand
operand; which operand the flags are produced from is now the generated
contract. `arm64_flag_operand_refines` proves the generated twelve-member table
agrees with an independent statement---an opcode selects the decoded immediate
exactly when it is one of the six immediate-form opcodes, a membership test over
a named list rather than a case per constructor---and
`arm64_flag_operand_immediate_iff_mem`, `arm64_flag_operand_reg_never_immediate`,
`arm64_flag_operand_lists_disjoint`, `arm64_flag_operand_pairs_exclusive`,
`arm64_flag_operand_code_dispatch` and `arm64_flag_operand_code_in_range` pin
each binding case. The host cross-check verifies `KPROG_ARM64_FLAG_RHS` against an
independent opcode-class oracle (never the macro's switch) and sweeps the opcode
over all 256 byte values crossed with distinct immediate and register values,
requiring an immediate-form opcode to return the immediate and every other opcode
the register expression; nine binding mutations---a generated family arm
inverted, a non-family default upgraded to the immediate, a moved case label, a
dropped CCMP immediate case, an opcode static-assert drift, a spec code change,
a generated/independent immediate-arm divergence in Lean, a dropped independent
list member, and a negated independent membership rule---each change the
observable operand or the refinement theorem. The dispatch bodies call the
generated `arm64_flag_operand.h` macro, so the operand-source decision is lifted
out of the trusted computing base; the immediate decode, the source-modifier
rewrite (or the bare `CCMP` register read), the flag production, and the
writeback remain outside the theorem.

The AArch64 width/narrowing contract is the arm64 counterpart of the x86 width
theorem. `GeneratedArm64Width` (from `arm64_width_spec.json`) defines the four
width codes, the low-bit mask, the sign mask, the bit count, and the
`narrow`/`zero`/`sign` observations; `arm64_width_code_refines`,
`arm64_width_mask_refines`, `arm64_width_sign_mask_refines`,
`arm64_width_bits_refines`, `arm64_narrow_refines`, `arm64_zero_refines`,
`arm64_sign_refines` and `arm64_sign_mask_observes` prove each generated
definition equal to an independent restatement, including that testing the
width sign mask against the narrowed value agrees with the shift-based sign
observation, so the C `KPROG_ARM64_WIDTH_SIGN_MASK` test and the generated
`sign` definition pick the same bit. The host cross-check verifies
`KPROG_ARM64_WIDTH_MASK`/`_SIGN_MASK`/`_BITS`/`KPROG_ARM64_APPLY_WIDTH` against
an independent oracle built only from the width bit count and sweeps boundary
vectors plus a fixed-seed random stream over all four widths; nine binding
mutations---a width mask, a sign mask, a bit count, an APPLY_WIDTH mask drop, a
width-code static-assert drift, a spec mask change, a generated mask flip, an
independent sign-mask flip, and an independent bit-count change---each change
the oracle or the refinement theorem. The x86 precedent already carried the
same independent module (`X86Width.lean`); the arm64 side previously restated
only the mask and narrowing inline in `Arm64AluResult.lean`, which now imports
`Arm64Width` instead.

The AArch64 condition-code contract is now a standalone module rather than a
fragment of the branch-PC module. `GeneratedArm64Cond` (from
`arm64_cond_spec.json`) defines the fifteen `Cond` constructors, their
`ARM64_COND_*` `code` numbers, and the `eval` predicate; `Arm64Cond.lean`
restates the flag semantics independently, proves the generated `eval` equal to
that restatement (`arm64_condition_sound`), proves the code table occupies the
contiguous 0..14 range the C macro switches on (`arm64_cond_code_in_range`),
pins every dispatch value (`arm64_cond_code_dispatch`), and adds complement and
always-true observations. The host cross-check verifies `KPROG_ARM64_EVAL_COND`
against an independent switch oracle over all fifteen conditions crossed with
all sixteen NZCV combinations, and sweeps every byte value outside 0..14 in
forked children to confirm the unsupported arm aborts. Ten binding
mutations---a HI guard drop, GE/LT and LE/GE polarity flips, a code
static-assert drift, a spec predicate change, a generated arm flip, a generated
code shift, an independent predicate flip, an independent dispatch-value shift,
and an independent range-bound change---each change the oracle or the
refinement theorem. The condition semantics and its soundness theorem moved out
of `Arm64ControlFlow.lean`, which now imports `Arm64Cond` and keeps only the
`branchPc` model and the branch refinement.

The AArch64 mnemonic-to-code decode contract binds the `ARM64_{ALU,SHIFT,MOD,
BITFIELD}_*` constants that the encoder, the simulator constants, and the Lean
model share. `Arm64Decode.lean` projects each generated table to
`(mnemonic, code)` pairs and proves the projection equal to an independent
specification list (`arm64_{alu,shift,mod,bitfield}_decode_refines`), so a drift
in either a generated code or a mnemonic breaks the proof, and adds per-table
distinctness lemmas so dispatch on the numeric code selects exactly one
operation. The host cross-check includes `arm64_sim.h` and drives the generated
constants through the real shared `ARM64_AUX_*` codec, reading every packed
field back with an independent extractor and sweeping each generated code
through each AUX field it belongs to, including the 0/255 field boundaries.
Twelve binding mutations---generated ALU/MOD code shifts, a duplicate bitfield
code, three AUX-field packing distortions in the simulator header, a renamed
spec mnemonic, two generated-code shifts, two generated-mnemonic changes, and an
independent-list code change---each change the oracle or a refinement theorem.

The x86 ALU mnemonic-to-code decode contract binds the `X86_ALU_*` constants
that the x86 simulator dispatcher and the Lean model share.
`X86AluDecode.lean` refines the generated table against an independent
specification per constructor. The host cross-check includes `x86_sim.h` and
drives every generated code through the real `x86_alu_result` dispatcher over
an operand/width grid, comparing against an independently recomputed
arithmetic identity; it pins the dispatcher contract (the arithmetic/logical/
negate family is computed at full 64-bit width and `width` is consumed only by
the shift family, narrowing being the caller's register write) and drives both
generated handler-selector macros against the dispatcher's identity checks. Ten
binding mutations---two generated-code duplicates, a rebound handler selector,
four dispatcher distortions in the simulator header, a spec code change, and an
independent Lean code-spec shift---each change the oracle or the refinement
theorem.

The x86 shift-flag contract binds the `KPROG_X86_SET_SHIFT_FLAGS` macro that
the simulator's `X86_SIM_L_SET_SHIFT_FLAGS` calls for the `SHL`/`SHR`/`SAR`/
`ROL` operations. `X86ShiftFlags.lean` proves the generated flag production
against an independent per-op specification of the architecturally defined
CF/ZF/SF/OF cases (leaving the undefined cases unconstrained). The host
cross-check includes `x86_sim.h` and `generated/x86_shift_flags.h`, reproduces
the simulator wrapper's input derivation (width narrowing, bit count, sign bit,
masked shift count), drives the *real* generated macro, and compares each of
CF/ZF/SF/OF against an independent restatement of the shift-flag semantics over
a value/amount/width/old-flags grid.

The x86 packed-AUX layout contract binds the `KPROG_X86_MEM_AUX` packer and its
four `KPROG_X86_MEM_AUX_*` byte decoders that `x86_sim.h` aliases its
`X86_MEM_AUX*` / `X86_REG_AUX_*` macros to, so every simulator AUX word shares
one machine-checked layout: index register in bits 0-7, scale exponent in bits
8-15, memory-width code / register source lane in bits 16-23, and the ALU-opcode
/ source-byte-shift / condition-code byte in bits 24-31. `X86MemAux.lean` proves
the generated C-shaped masked-or packer equal to an independent little-endian
byte concatenation, proves each of the four field roundtrips, proves the
`X86_REG_NONE` sentinel roundtrip, and proves the four fields pairwise
non-interfering. The host cross-check includes `x86_sim.h`, drives the *real*
sim-path `X86_MEM_AUX`/`X86_MEM_AUX_FULL`/`X86_MEM_AUX_ALU_OP`/`X86_REG_AUX_*`
macros and the decoders, and compares every field against an independent
`(aux >> 8k) & 0xff` restatement over a byte grid, the sentinel, and all 256
values of each single field (7,904 cases).

The x86 register-lane AUX contract binds the `KPROG_X86_REG_LANE_AUX` packer
and its three byte decoders that the simulator's register/immediate ALU bodies
and its width/lane read-write macros call for the ALU code and the two byte
lanes: the payload (ALU code or source byte) in bits 0-7, the destination byte
lane in bits 8-15, and the source byte lane in bits 16-23, with the top byte
unused. `X86RegLaneAux.lean` proves the generated masked-or packer equal to an
independent little-endian byte concatenation, proves each of the three field
roundtrips, proves the three fields pairwise non-interfering, and carries the
typed-lane roundtrip over the two valid byte lanes. The host cross-check
includes `x86_sim.h`, drives the *real* generated macros, and compares every
field against an independent `(aux >> 8k) & 0xff` restatement over a byte grid
and all 256 values of each single field, and pins the unused top byte
(7,629 cases).

The x86 stack-index contract binds `KPROG_X86_STACK_INDEX(OFF, CAPACITY)`, the
map the simulator's stack helpers (`X86_SIM_L_STACK_INDEX`, and through it
`X86_SIM_L_STACK_PTR` / `_STACK_READ` / `_STACK_WRITE`) use to resolve an
abstract frame offset into a byte index in the fixed `X86_SIM_STACK_BYTES`
arena: the offset is added to the arena capacity and the sum is truncated to
the helpers' 32-bit index type, so the frame base (offset `-capacity`) lands at
index 0 and the arena top at index `capacity`. `X86StackIndex.lean` proves the
generated truncation equal to an independent low-32-bits statement, proves the
frame base lands at zero and the top at the capacity, proves that two offsets
differing by a multiple of `2^32` alias, and carries a concrete frame example.
The host cross-check drives the *real* generated macro over a grid that
includes the frame base, the arena top, offsets below the base, and offsets
with the high 32 bits set, and compares it against the independent
unsigned-64-bit low-32-bits restatement (690 cases).

The x86 stack-arena storage contract binds `KPROG_X86_STACK_WORDS`,
`KPROG_X86_STACK_WORD_INDEX`, `KPROG_X86_STACK_WORD_ALIGNED`,
`KPROG_X86_STACK_BYTE`, and `KPROG_X86_STACK_ASSEMBLE` — the arithmetic the
simulator's stack helpers use to reach the arena, which is a union of two
overlapping views (`__u8 b[X86_SIM_STACK_BYTES]` and the word array
`__u64 q[KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES)]`). `X86StackArena.lean`
proves the generated word-slot shift and alignment guard equal independent
quotient/remainder statements, proves the rounded-up word count covers the
capacity without wasting a whole slot, proves the 8-aligned-index roundtrip,
and proves that the little-endian byte split of a word reassembles to the word
itself — so the 64-bit fast path through `q[]` and the byte path through `b[]`
address the same storage. The host cross-check drives the *real* generated
macros over a capacity/index/value grid and an exhaustive two-page sweep,
comparing each against independent shift/mask restatements and checking that a
value stored through the word view reloads byte-for-byte through the byte view
(70,571 cases).


`make check` rejects stale generated outputs before checking the theorem. This
mechanically binds the pointer-add bits/tag policy and ABI-load offset/tag
policy, both ISA flag-to-control-flow decisions, x86 width narrowing, x86
logical/ADD/SUB/ADC/SBB flag production, x86 shift-flag production, the x86 effective-address offset (and the simulator's routing of `X86_SIM_L_MEM_OFFSET` through it),
packed-AUX layout,
register-lane AUX layout,
AArch64 packed-AUX layout,
x86 stack-arena storage model,
x86 stack-index frame-offset mapping,
AArch64 stack-arena storage model (word-slot shift, alignment guard, and
rounded-up word/tag-slot count for the `b`/`q` union) and AArch64
stack-index frame-offset mapping,
LEA, register-writing MOV, width-converting register MOV, shared memory
read-dispatch (and the simulator's routing of its read path through
`KPROG_X86_MEM_READ_SRC`), and the
shared store (`MOV_STORE`) handler composition (and the simulator's routing of
its store body through the `KPROG_X86_STORE_*` contract), the
`MOVBE_LOAD`/`MOVBE_STORE` handler composition (and the simulator's routing of
both MOVBE bodies through the `KPROG_X86_MOVBE_*` contract); the pointer-write
provenance composition, the XMM0 pair-move
composition (and the simulator's routing of both XMM0 bodies through the
`KPROG_X86_XMM0_*` contract), the `CALL_MEMCPY`/`CALL_MEMSET` block-copy/fill
composition (and the simulator's routing of all four call-memory bodies through
the `KPROG_X86_CALLMEM_*` contract), the `PUSH`/`POP` stack-step composition
(and the simulator's routing of both bodies through the `KPROG_X86_PUSH_*`
contract), the `REP_MOVS` block-copy composition (and the simulator's routing
of the body through the `KPROG_X86_REP_MOVS_*` contract), the
`ANDN`/`ANDN_MEM` source-split/memory-width composition (and the simulator's
routing of both bodies through the `KPROG_X86_ANDN_*` contract), the
`BT`/`BT_IMM`/`BT_MEM_IMM` base/index-source/width composition (and the
simulator's routing of all three bodies through the `KPROG_X86_BT_*`
contract), the
`BZHI`/`BZHI_MEM` single-width value/count-source composition (and the
simulator's routing of both bodies through the `KPROG_X86_BZHI_*` contract), the
`CMP_IMM`/`CMP_REG`/`TEST_IMM`/`TEST_REG` register/immediate source/flag-kind
composition (and the simulator's routing of all four bodies through the
`KPROG_X86_CMPOP_*` contract), the
`CMOV`/`CMOV_MEM` whole-word/source-shift condition, two-level access-width,
high-half displacement, and source-provenance writeback composition (and the
simulator's routing of
both bodies through the `KPROG_X86_CMOV_*` contract), the
`MOV_LOAD` two-width-resolution/arm-select/read-dispatch composition (and the
simulator's routing of the `MOV_LOAD` body through the `KPROG_X86_MOV_LOAD_*`
and `KPROG_X86_MEM_READ_SRC` contracts), the
`MOV_STORE`/`SETCC`/`SETCC_MEM`/`MOVBE` handler
compositions (and the simulator's routing of both `SETCC` bodies through the
`KPROG_X86_SETCC_*` and `KPROG_X86_SETCC_MEM_*` contracts, the register form's
condition byte through the `KPROG_X86_SETCC_COND_MATCHED` fold),
the x86 conditional-branch emitted-shape contract (and the simulator's routing
of `X86_SIM_X86_JCC_IMPL`'s backward-edge choice through
`KPROG_X86_BRANCH_BACKWARD`, proved equal to the architectural `branchPc` for
both shapes),
the x86 little-endian memory
memory-source bit-test/zero-high-bits composition, the memory-source
multiply, the register-source multiply, two-destination `MULX`, and compare
compositions, and
AArch64 width, generic ALU handler writeback/path
`.D0`/`.Q0` vector memory-transfer (and the simulator's routing of all four
bodies through the `KPROG_ARM64_DQ_MEM_*` contract), `LDP`/`STP` pair-move
(and the simulator's routing of both bodies through the `KPROG_ARM64_PAIR_MEM_*`
contract), pre/post-indexed
address-writeback, vector-register-file half mapping, MVN/NEG unary-value, and
CNEG condition-gated negation, ORN complemented-logical-OR composition, ADRP
relocation-tag selection, STLXR exclusive-store-status encoding, MOV
provenance-path routing, sign-extending-load width selection, and plain-load
provenance preservation, pair-load provenance routing, FMOV
destination routing, conditional-select pointer-path routing, and flag-family
operand-source selection,
plus ADD/SUB/logical NZCV production;
other flag production, the decoder-to-handler
mapping, renderer, C compiler, and all other
operations remain in the trusted computing base.
The two `ARM64_SIM_L_MEM_{PRE,POST}` handler bodies do not call the generated
`arm64_mem_prepost.h` macros — that header is exercised only by the host oracle —
so both bodies remain in the trusted computing base.

The AArch64 packed-AUX layout contract binds the `KPROG_ARM64_AUX` packer and
its four `KPROG_ARM64_AUX_B0..B3` lane decoders plus the
`KPROG_ARM64_AUX_REG_NONE` sentinel — the 32-bit operand word the simulator's
ALU, shift, MOVK, memory, bitfield and CCMP handlers share, with lane 0 (ALU
opcode / memory index register / bitfield kind / shift kind) in bits 0-7, lane
1 (source modifier / bitfield LSB / CCMP NZCV) in bits 8-15, lane 2 (shift
amount / bitfield width / MOVK column) in bits 16-23, and the memory-flag byte
in bits 24-31. `Arm64Aux.lean` proves the four lane decoders recover exactly
the packed bytes, that the lanes do not interfere, and that the
`ARM64_REG_NONE` sentinel round-trips; the six simulator packers
(`ARM64_AUX`, `_ALU`, `_SHIFT`, `_MOVK`, `_MEM`, `_BITFIELD`, `_CCMP`) and seven
simulator decoders (`ARM64_SIM_L_MOD`, `_SHIFT`, `_MEM_INDEX`, `_MEM_FLAGS`,
`_BITFIELD_LSB`, `_BITFIELD_WIDTH`, `_CCMP_NZCV`) are thin aliases of that one
machine-checked layout, so the *lane assignment* the handlers share is no longer
in the trusted computing base. The sim-header route oracle drives the real
decoders and packers against an independent `(aux >> 8k) & 0xff` restatement and
the host cross-check drives the generated macros directly (1,115,374 and 586,829
cases).

The AArch64 stack-arena storage contract binds `KPROG_ARM64_STACK_WORD_INDEX`,
`KPROG_ARM64_STACK_WORD_ALIGNED`, `KPROG_ARM64_STACK_WORDS`, and
`KPROG_ARM64_STACK_TAG_SLOTS` — the arithmetic the simulator's stack helpers
use to reach the arena, a union of two overlapping views
(`__u8 b[ARM64_SIM_STACK_BYTES]` and
`__u64 q[KPROG_ARM64_STACK_WORDS(ARM64_SIM_STACK_BYTES)]`, 160 bytes and 20
qwords when the arena is enabled). `Arm64StackArena.lean` proves the generated
word-slot shift and alignment guard equal independent quotient/remainder
statements, proves the rounded-up word count covers the capacity without
wasting a whole slot, proves a word-aligned index times eight round-trips, and
proves the word arena's byte 0 is the value's low byte, so the 64-bit fast path
through `q[]` and the byte path through `b[]` reach the same storage. The
AArch64 stack-index contract binds `KPROG_ARM64_STACK_INDEX(OFF, BIAS)` and
`KPROG_ARM64_STACK_PTR_INDEX(OFF, BIAS)`, the map from an abstract frame offset
to a byte index in the biased arena: the offset is added to the bias
(`ARM64_SIM_STACK_BIAS`, 96) and truncated to the helpers' 32-bit index type, so
the frame base lands at index 0 and an offset of zero at byte `bias`.
`Arm64StackIndex.lean` proves the generated truncation equal to an independent
low-32-bits statement, proves the frame base lands at zero, proves the index is
affine in the offset, and proves that two offsets differing by a multiple of
`2^32` alias. The host cross-checks drive the *real* generated macros over
capacity/index/value grids and exhaustive sweeps (70,558 and 536 cases), and the
sim-header route oracle drives the real `ARM64_SIM_L_STACK_{INDEX,WRITE,
WRITE_TAG,READ,READ_TAG,PTR}` helpers against an independently maintained byte
and tag arena over the full frame window, every width and tag (2,754,329 cases).

The correspondence between C unsigned bit operations and Lean `BitVec`
operations remains a trusted language-semantics premise; these theorems do not
verify the C compiler or native instruction bytes.

This is still a deliberately bounded proof. It does not establish full
equivalence between the simulator and native instruction bytes, cover complete
instruction decoding/dispatch, multi-step control-flow traces, helpers, or the
full workload-derived instruction subsets, or prove the paper's complete
O1--O4 obligations. The proved branch predicates and the AArch64 and x86
emitted-shape bridges are local control-flow refinements (one conditional edge
at a time), not a whole-program trace theorem.
The ABI-load model still abstracts away base-register identity, width checks,
and memory-boundary checks.
