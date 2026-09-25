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
Address derivation and safety, stack/ABI dispatch, packed-AUX operation
selection, and logical, shift, bit, compare, and multiply memory handlers
remain outside this theorem.
The memory-destination logic theorem covers `AND/OR/XOR [mem], rhs` after a
valid address, RHS, operation, and width have been selected. It composes the
load, width-local logical result and replacement flags, and confined store,
proving equality of every modeled flag and byte. Its independent 21,536-case
oracle checks actual generated macros against a byte-loop model, including all
16 incoming flag combinations to ensure CF/OF are cleared and ZF/SF are
replaced. RHS decoding, address-space dispatch, and shift, bit, compare, and
multiply memory handlers remain outside the theorem.
`make check` rejects stale generated outputs before checking the theorem. This
mechanically binds the pointer-add bits/tag policy and ABI-load offset/tag
policy, both ISA flag-to-control-flow decisions, x86 width narrowing, x86
logical/ADD/SUB/ADC/SBB flag production, the x86 little-endian memory
load/store contract, and AArch64 width, generic ALU handler writeback/path
selection, ADDS/SUBS/CMN/CMP, ANDS/BICS/TST/TST-BIC, and CCMP composition,
plus ADD/SUB/logical NZCV production;
other flag production, the decoder-to-handler
mapping, renderer, C compiler, and all other
operations remain in the trusted computing base.
The correspondence between C unsigned bit operations and Lean `BitVec`
operations remains a trusted language-semantics premise; these theorems do not
verify the C compiler or native instruction bytes.

This is still a deliberately bounded proof. It does not establish full
equivalence between the simulator and native instruction bytes, cover complete
instruction decoding/dispatch, multi-step control-flow traces, helpers, or the
full workload-derived instruction subsets, or prove the paper's complete
O1--O4 obligations. The proved branch predicates and AArch64 emitted-shape
bridge are local control-flow refinements, not a whole-program trace theorem.
The ABI-load model still abstracts away base-register identity, width checks,
and memory-boundary checks.
