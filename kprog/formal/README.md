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

The decoded width code a body operates at — where an unused width field (code
0) falls back to the 64-bit default — is likewise a generated contract rather
than a restatement. `generate_x86_width_spec.py` emits
`KPROG_X86_WIDTH_ABSENT_CODE`, `KPROG_X86_WIDTH_EFFECTIVE_DEFAULT` and
`KPROG_X86_WIDTH_EFFECTIVE` alongside the width tables, and the generated Lean
`effective` resolves a decoded code to the code a body operates at. `X86Width.lean`
proves that resolution equal to an independent `if c = 0 then 8 else c`, that the
absent code names no width (`x86_absent_code_names_no_width`), that the fallback
code is exactly the 64-bit width's code (`x86_default_code_is_w64`, pinned to the
generated decode so it cannot drift), and that the resolution is the identity on
every real width (`x86_effective_identity_on_width`); the earlier mask, bit-count,
narrowing, zero and sign theorems remain. Every site in `x86_sim_local_bpf.h`
that restated `WIDTH ? WIDTH : X86_WIDTH_64` now routes through
`X86_SIM_L_EFFECTIVE_WIDTH`, whose kernel is the generated
`KPROG_X86_WIDTH_EFFECTIVE`. A generated-header oracle sweeps the full decoded
code domain (0..255) plus the width codes and the absent code's neighbours
against the independent model and the pinned width table (1,280 cases); a
sim-header route oracle drives every routed register/stack/flag/ALU/move/compare/
`IMUL`/`MULX` body and compares the whole modeled register file with tags, the
flags, the modeled heap and the stack against an independent model (518 cases).
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
The 36 accepted `jcc`/`cmovcc`/`setcc` condition mnemonics are likewise
generated from `x86_cc_decode_spec.json` into the encoder's Python `CC_AUX`
mapping, the C `generated/x86_cc_decode.h`, and Lean. Each mnemonic is a family
prefix plus a condition suffix; the generator re-reads `x86_cond_spec.json` on
every `--check` and rejects a suffix that names no condition, so the 12 suffixes
the encoder reaches are exactly the condition contract's names minus the parity
pair `o`/`no`. Lean checks the generated mnemonic, token, and code projection
against an independent enumeration and each code against the shared condition
contract. This binds the encoder's *condition* text to the C condition code
consumed by the evaluators; assembly parsing and the rest of the textual
mnemonic remain boundaries.
The 17 accepted AArch64 condition mnemonics are generated the same way from
`arm64_cc_decode_spec.json` into the encoder's Python `COND` mapping, the C
`generated/arm64_cc_decode.h`, and Lean. The generator re-reads
`arm64_cond_spec.json` on every `--check` and rejects a mnemonic that names no
condition; the 15 canonical mnemonics name every condition exactly once, and
the two architectural aliases `hs`/`lo` name the same conditions as `cs`/`cc`,
so the 17 mnemonics cover 15 distinct codes. Lean checks the generated
`(mnemonic, token, code)` projection against an independent enumeration, each
code against the shared condition contract, the canonical mnemonics against the
full condition order, and the alias set and alias-equal-code facts
(`arm64_cc_decode_alias_same_code`). This binds the encoder's *condition* text
to the C condition code the evaluators consume; assembly parsing and the rest
of the textual mnemonic remain boundaries.
The 61 AArch64 BPF helper-ident rows are generated the same way from
`arm64_helper_idents_spec.json` into the encoder's Python
`generated_arm64_helper_idents.py`, the C `generated/arm64_helper_idents.h`
(the `KPROG_ARM64_HELPER_ROW` by-id selector with its out-of-range default and
the five `KPROG_ARM64_HELPER_DELEGATE_*` compact-slot pins), and
`KProgFormal/GeneratedArm64HelperIdents.lean`. The generator re-reads the
simulator header on every `--check` and rejects a row whose name is not a
sim-header body macro, a duplicate id or name, and a forwarding target that
names no source or target macro; the body-macro set must biject the 61 spec
names. The per-program compact table the encoder emits renumbers a program's
called helpers to their 1-based lexicographic rank over the used names, and
the five sim-header forwarding macros pin that rank of their targets over the
full 61-name table, so the pins are proved facts, not a restatement. Lean
checks the generated `(id, name)` projection against an independent
enumeration, the names' pairwise distinctness and the ids' strict
increase, each forwarding target's pinned slot against its full-table rank
(`helper_delegate_ranks`), and every name's own slot against its rank
(`helper_slot_ranks`); the host oracle drives the row selector over every
kernel id, the out-of-range default, the two counts, and the five forwarding
slots against an independent restatement. The `KPROG_ARM64_HELPER_ROW`
out-of-range default and the sim-header body macros remain boundaries.
The three AArch64 stack-write slot-tag actions are generated the same way
from `arm64_stack_write_tag_action_spec.json` into the C
`generated/arm64_stack_write_tag_action.h` (the
`KPROG_ARM64_STACK_WRITE_TAG_ACTION` plain-ternary 3-way selector, the
action-code defines, and the count, distinctness, and selection
`_Static_assert`s) and `KProgFormal/GeneratedArm64StackWriteTagAction.lean`.
The generator re-reads the simulator header on every `--check` and rejects a
write region that names no generated selector or still names a hand
`KPROG_ARM64_STACK_TAG(` gate. The simulator's `ARM64_SIM_L_STACK_WRITE_TAG`
write helper routes through the generated selector, so the hand gate is out
of the write path and the read-side slot-tag helper still uses it. Lean
checks the generated selector against an independent literal over every
fact pair, the name and code tables against independent enumerations, the
code round-trip and out-of-range facts, the four-case dispatch, the write
word/tag arm against the read-side slot-tag predicate
(`arm64_stack_write_tag_action_matches_read_tag`), the word arm's qword
write against the width-64 active-lane footprint
(`arm64_stack_write_tag_action_word_writes_full_qword`), and both byte
actions' footprint against the width's active byte lanes
(`arm64_stack_write_tag_action_byte_footprint`); the host oracle drives the
generated selector against an independent 3-way restatement, and the route
oracle drives the real write through the generated selector against an
independent byte-image and slot-tag model with the read-back through the
real read helper. The out-of-range width codes and the byte-ladder lanes
remain boundaries.
The two AArch64 stack slot-tag read sources are generated the same way
from `arm64_stack_read_tag_source_spec.json` into the C
`generated/arm64_stack_read_tag_source.h` (the
`KPROG_ARM64_STACK_READ_TAG_SOURCE` plain-ternary 2-way selector, the
source-code defines, and the count, distinctness, and selection
`_Static_assert`s) and
`KProgFormal/GeneratedArm64StackReadTagSource.lean`. The generator
re-reads the simulator header on every `--check` and rejects a read
region that names no generated selector or still names a hand
`KPROG_ARM64_STACK_TAG(` gate. The simulator's
`ARM64_SIM_L_STACK_READ_TAG` read helper routes through the generated
selector, so the hand gate is out of the read path and the write-side
routing of Step 0137 is unchanged. This is the read-side mirror of the
write-side 3-way action: the `.stackTagArray` source fires on the same
fact pair the 0121 slot-tag predicate and the 0137 word-and-tag action
fire on. Lean checks the generated selector against an independent
literal over every fact pair, the name and code tables against
independent enumerations, the code round-trip and out-of-range facts,
the four-case dispatch, the read stack-tag-array source against the
read-side slot-tag predicate
(`arm64_stack_read_tag_source_matches_read_tag`), and the read
stack-tag-array source against the 0137 write word-and-tag action
(`arm64_stack_read_tag_source_matches_write_word_arm`); the host oracle
drives the generated selector against an independent 2-way
restatement, and the route oracle drives the real read through the
generated selector against an independent slot-tag-array and
byte-image model with each write commit mirrored into the model. The
out-of-range source codes remain boundaries.
The two AArch64 BPF helper-argument pointer sources are generated the same
way from `arm64_helper_arg_ptr_spec.json` into the C
`generated/arm64_helper_arg_ptr.h` (the
`KPROG_ARM64_HELPER_ARG_PTR_BODY` plain-ternary 2-way selector, the
source-code defines, and the count, distinctness, exact-code, and selection
`_Static_assert`s) and `KProgFormal/GeneratedArm64HelperArgPtr.lean`. The
generator re-reads the simulator header on every `--check` and rejects a
helper region that names no generated selector or still names the hand
register-tag `?` gate. The simulator's `ARM64_SIM_L_HELPER_ARG_PTR` helper
routes through the generated selector, so the hand gate is out of the helper
path and the stack-read and stack-write routings of Steps 0138/0137 are
unchanged. This extends the stack slot-tag family: the `.stackArenaPtr`
source fires on the same stack-tag fact the 0121 slot-tag predicate names.
Lean checks the generated selector against an independent literal over
every fact value, the name and code tables against independent
enumerations, the code round-trip and out-of-range facts, the two-case
dispatch, the stack-arena-pointer arm firing exactly on the stack-tag fact
(`arm64_helper_arg_ptr_source_selects_stack`), and the arena byte the
stack-arena-pointer arm addresses against the 0112 stack index contract
(`arm64_helper_arg_ptr_stack_index`); the 14-case host oracle drives the
generated selector against an independent 2-way restatement, and the route
oracle declares the full register file and stack, plants each register's
pointer and provenance tag, and drives the real helper over every
general-purpose register and every provenance class plus the stack pointer
against an independent model of the selection (786 cases). The out-of-range
source codes remain boundaries.
The two AArch64 memory base-address sources are generated the same way from
`arm64_mem_base_src_spec.json` into the C
`generated/arm64_mem_base_src.h` (the `KPROG_ARM64_MEM_BASE_SRC`
plain-ternary 2-way selector, the source-code defines, and the count,
distinctness, exact-code, and selection `_Static_assert`s) and
`KProgFormal/GeneratedArm64MemBaseSrc.lean`. The generator re-reads the
simulator header on every `--check` and rejects a memory-helper region that
names no generated selector or still names the hand `== ARM64_SP ? __a64_sp`
gate. The simulator's `ARM64_SIM_L_MEM_READ`, `ARM64_SIM_L_MEM_READ_TAG`,
and `ARM64_SIM_L_MEM_WRITE` helpers all route through the generated
selector, so the hand gate is out of the helper path (the three bodies
previously repeated it verbatim) and the offset contract, the arm/source
selection of Step 0123, and the stack-read/stack-write routings of Steps
0138/0137 are unchanged. This extends the stack slot-tag family: the
`.spRegister` source fires on the same base-is-SP fact the 0123 store-body
selection and the 0121 slot-tag predicate name. Lean checks the generated
selector against an independent literal over every fact value, the name and
code tables against independent enumerations, the code round-trip and
out-of-range facts, the two-case dispatch, the stack-pointer arm firing
exactly on the base-is-SP fact (`arm64_mem_base_src_selects_sp`), and the two
cross-contracts tying the source to the store-body selection
(`arm64_mem_base_src_matches_write_arm`) and to the read value source
(`arm64_mem_base_src_matches_read_src`); the 15-case host oracle drives the
generated selector against an independent 2-way restatement over the real
computed register-is-32 fact, and the route oracle declares the full
register file and stack, plants the stack pointer and a stack-tagged
register's pointer at distinct arena indices, and drives the real read,
read-tag, and write helpers at both base-address sources over every width
and several value patterns against an independent base-address model
(205324 cases). The out-of-range source codes remain boundaries.
The AArch64 vector memory step's per-lane extra offset is generated the same
way from `arm64_dq_mem_extra_spec.json` into the C
`generated/arm64_dq_mem_extra.h` (the `KPROG_ARM64_DQ_MEM_EXTRA`
plain-ternary 3-way selector, the outcome-code and byte-offset defines, and
the count, distinctness, exact-code, high-lane-stride, base-offset, and
fact-pair selection `_Static_assert`s) and
`KProgFormal/GeneratedArm64DqMemExtra.lean`. The generator re-reads the
simulator header on every `--check` and rejects a vector memory step region
that names no generated selector or still names the hand first-position
ternary. The simulator's shared `ARM64_SIM_L_DQ_MEM_STEP` step routes its
per-lane extra offset through the generated selector, so the hand nested
ternary on `__a64_vreg_p == 0U` / `__a64_dq_lanes > 1U` is out of the step
and the DQ lane plan, the vector half plan of Step 0143, the offset contract,
and the base-address source of Step 0140 are unchanged. This extends the
stack slot-tag family to the vector memory path: the `.highLane` offset fires
on the closed ordered fact pair (not the first plan position, and a high lane
present) the two preceding contracts already consume. Lean checks the
generated selector against an independent 3-way literal over every fact pair,
the name and code tables against independent enumerations, the code round-trip
and out-of-range facts, the three distinct plan effects, the four-case
dispatch, the high-lane arm firing exactly on the closed ordered fact pair
(`arm64_dq_mem_extra_selects_high_lane`), the three offsets' distinctness,
and the two cross-contracts tying the high-lane offset to the DQ lane stride
(`arm64_dq_mem_extra_matches_dq_stride`) and to the vector half offset
(`arm64_dq_mem_extra_matches_vreg_half`); the 21-case host oracle drives the
generated selector against an independent 3-way restatement over both facts
and the four opcode lanes, and the route oracle declares the full register
file and stack, plants the base registers' pointers and provenance tags, and
drives the real step in both directions over every opcode, base class,
pre/post flag combination, index mode, and several immediates against an
independent model that walks the lane plan position-by-position and recomputes
each position's extra offset from its own fact pair (62424 cases), so a
dropped or added high-lane offset is numerically distinguishable.
The AArch64 memory address offset's index-value source is generated the same
way from `arm64_mem_index_value_spec.json` into the C
`generated/arm64_mem_index_value.h` (the `KPROG_ARM64_MEM_INDEX_VALUE`
plain-ternary 2-way selector, the `…_REGISTER` / `…_ZERO` source codes, and
the count, distinctness, exact-code, and fact/value selection
`_Static_assert`s) and `KProgFormal/GeneratedArm64MemIndexValue.lean`. The
generator re-reads the simulator header on every `--check` and rejects a
memory-base-offset region that names no generated selector or still picks its
index value by hand through the `has_index` ternary. The simulator's
`ARM64_SIM_L_MEM_BASE_OFF` offset routes the value its present index register
contributes through the generated selector, so the hand ternary on the
computed `__a64_mbo_has_index` fact is out of the body while
`ARM64_SIM_L_MOD_VALUE((INDEX), …)` is still called as the register source's
argument; the index-presence contract of Step 0102, the writeback-suppress
decode, the offset contract, the base-address source of Step 0140, and the
pre/post step are unchanged. This extends the memory family with the one
value-selection fact the offset already resolves: the register source fires
on the presence contract's own byte fact (not the sentinel index operand), and
the zero source carries no index contribution into the offset. Lean checks the
generated selector against an independent 2-way literal over the one fact, the
name and code tables against independent enumerations, the code round-trip
and out-of-range facts, the two distinct effects, the two-case dispatch, the
register source firing exactly on the has-index fact
(`arm64_mem_index_value_selects_register`), the agreement with the 0102
presence fact (`arm64_mem_index_value_matches_present`), and the two
cross-contracts tying the register source to the index register *value*
(`arm64_mem_index_value_register_is_index`) and to
`GeneratedArm64MemOffset.value`'s index argument
(`arm64_mem_index_value_matches_offset`); the 17-case host oracle drives the
compiled selector over both raw presence facts and the sentinel's neighbours
against an independent 2-way restatement, and the 3015-case route oracle
includes the simulator header, declares the full register file and stack,
seeds every general register with a distinct per-register pattern, plants a
nonzero value at each candidate index register, and drives the real offset
over every index operand, AUX index lane, flag byte, register value and
immediate against an independent model that restates the presence fact, the
index-value source selection, and the immediate suppression from the raw
`AUX` word, so a collapsed selection or a swapped pair of arms is numerically
distinguishable.
The AArch64 vector memory step's half state-field selection is generated the
same way from `arm64_vreg_field_spec.json` into the C
`generated/arm64_vreg_field.h` (the `KPROG_ARM64_VREG_FIELD` plain-ternary
2-way selector, the `…_LOW_FIELD` / `…_HIGH_FIELD` field codes, and the
count, distinctness, exact-code, and half-offset/fact selection
`_Static_assert`s) and `KProgFormal/GeneratedArm64VregField.lean`. The
generator re-reads the simulator header on every `--check` and rejects a
vector memory step region that names no generated selector or still picks its
field by hand through the `if (__a64_vreg_off == …HIGH_OFFSET)` test. The
simulator's shared `ARM64_SIM_L_DQ_MEM_STEP` step routes the field each moved
lane lands in through the generated selector on both the load and the store
arm, so the two hand offset tests are out of the body; the DQ lane plan of
Step 0141, the per-lane extra offset, the offset contract, the base-address
source of Step 0140, and the pre/post step are unchanged. This extends the
vector memory step with the one field-selection fact the lane offset already
resolves: the high field fires exactly on the closed offset-equals-high fact,
and Lean ties the selection to the 0054 vector half plan for every half so the
two contracts cannot disagree about which state field a lane lands in. Lean
checks the generated selector against an independent 2-way literal over the
one fact, the field-name and field-code tables against independent
enumerations, the code round-trip and out-of-range facts, both distinct
effects, the two-case dispatch, the high field firing exactly on the fact
(`arm64_vreg_field_selects_high_field`), and the cross-contracts to the half
plan (`arm64_vreg_field_matches_vreg_half`,
`arm64_vreg_field_matches_vreg_plan`,
`arm64_vreg_field_offsets_are_half_offsets`); the 7-case host oracle drives
the compiled selector over the raw computed offset against an independent
2-way restatement, and the 62427-case route oracle includes the simulator
header, declares the full register file and stack, plants the base registers'
pointers and provenance tags, and drives the real step in both directions
over every opcode, base class, pre/post flag combination, index mode, and
several immediates against an independent model that restates the half-field
selection from the raw offset, so a body that always wrote one field, or
swapped the two fields, is numerically distinguishable.
The AArch64 write-register width body-selection is generated the same way from
`arm64_write_arm_spec.json` into the C `generated/arm64_write_arm.h` (the
`KPROG_ARM64_WRITE_ARM` plain-ternary 2-way selector, the `…_FULL` /
`…_NARROW` arm codes, and the count, distinctness, exact-code, and per-width
selection `_Static_assert`s) and `KProgFormal/GeneratedArm64WriteArm.lean`. The
generator re-reads the simulator header on every `--check` and rejects a
writeback-body region that names no generated selector or still picks its body
by hand through the `if ((WIDTH) == ARM64_WIDTH_32)` test. The simulator's
writeback body `ARM64_SIM_L_WRITE_REG_WIDTH`, which every GPR write routes
through, now selects its body through the generated selector, so the hand width
test is out of the body; the `SP` branch, the destination-presence guard, the
pre-truncation `KPROG_ARM64_APPLY_WIDTH`, and the pointer-writeback helper
`ARM64_SIM_L_WRITE_REG_PTR` are unchanged. Because the value is masked to the
width before the body choice, the two bodies are observationally equal for
every width the simulator reaches, so the split is a genuine no-op on state and
only a wrong selector code or a swapped body assignment is observable. Lean
checks the generated selector against an independent 2-way literal over the
width fact, the arm-name and arm-code tables against independent enumerations,
the code round-trip and out-of-range facts, both bodies, the 32-bit literal's
binding to the width contract's own code
(`arm64_write_arm_w32_spec_bound`), the per-width map of `[w8, w16, w32, w64]`
to `[full, full, narrow, full]` (`arm64_write_arm_over_widths`), the two-case
dispatch, and that the narrow body is selected exactly at the width the
pre-truncation step masks to 32 bits
(`arm64_write_arm_narrow_matches_pre_truncation`); the 260-case host oracle
drives the compiled selector over the raw width fact against an independent
2-way restatement, and the 6401-case route oracle includes the simulator
header, declares the full register file and stack, seeds every general register,
and drives the real writeback body over the full register-number range, all four
width codes, and several values against an independent model that masks first
and then truncates exactly when the width code is the 32-bit code, so a wrong
selector code or a swapped body assignment is numerically distinguishable.
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
The x86 opcode-number contract is generated from `x86_opcode_spec.json` into
the C `_Static_assert` table `generated/x86_opcode.h`, the Lean
`KProgFormal.GeneratedX86Opcode` family, and the artifact encoder's
`generated_x86_opcode.py`. It pins all 72 canonical `X86_OP_*` tokens to their
codes and the five width-suffixed aliases as identities with their target
tokens. The generator re-reads `kprog/x86/x86_sim.h` on every `--check` and
fails on a renumbered, renamed, added, or dropped token, so the simulator, the
Lean model, and the encoder cannot silently disagree about what a token means.
Lean proves the generated token/code projection equal to an independent
enumeration. The artifact encoder resolves every opcode it emits through the
generated table and exits on an unknown name. Textual mnemonic parsing and
native bytes remain outside this contract.
The x86 specialization-preservation contract is generated from
`x86_specialization_spec.json` into the C dispatch header
`generated/x86_specialization.h`, the Lean
`KProgFormal.GeneratedX86Specialization` family, and the artifact encoder's
`generated_x86_specialization.py`. It pins, per canonical `X86_OP_*` token,
whether the artifact encoder emits a specialized `X86_SIM_L_EXEC_*`/
`X86_SIM_BPF_CALL_*` body (`directMacro`, with the six AUX-gated overrides),
the control-transfer path (`branchHandler`), or the generic `X86_SIM_L_EXEC`
chain (`genericRunOp`), and names the chain arm macro for each token. The
generator re-reads `kprog/x86/x86_sim_local_bpf.h` on every `--check` and fails
on a class change, a dropped or added row, or a drifted chain/direct/aux
target, so the simulator's dispatch chain, the Lean model, and the encoder
cannot silently disagree about which handler a token runs. Two host oracles
check the live chain text and prove at run time that the chain and the
hand-restated encoder body leave identical machine state. Textual mnemonic
parsing and native bytes remain outside this contract.
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
written against an independently stated load/flags specification. It also pins
the shared `KPROG_X86_CMPOP_*` left-source (memory) and displacement-kind
(store, except the whole-immediate `CMP_MEM_REG`) facts to independent
restatements (`x86_mem_compare_lhs_source_refines`, `x86_mem_compare_disp_kind`).
Its independent 40,784-case oracle checks the actual generated macros against a
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
The index-register presence decision shared by that helper is itself a generated
contract: `generate_x86_mem_index_spec.py` emits `KPROG_X86_MEM_INDEX_PRESENT`
and `KPROG_X86_MEM_INDEX_ARM`, `X86MemIndex.lean` proves the presence predicate
equals an independent `decide (indexByte != 0xff)` (the `X86_REG_NONE`
sentinel), that the two arms invert each other and are both reachable, and that
the two presence cases are exactly the two `hasIndex` cases
`KPROG_X86_MEM_OFFSET` consumes. `X86_SIM_L_MEM_OFFSET` now resolves both its
presence flag and its index-value selector through that bridge, so the sentinel
test is no longer restated in the simulator. A generated-header oracle drives
the presence and arm macros over all 256 index bytes against an independent
`byte != 0xff` test (512 cases), and a sim-header route oracle drives the real
helper over register-AUX forms and the sentinel against an independent
presence/value oracle (957 cases).
The x86-64 operand-register presence decision that the memory-read/write paths
and the `MULX`/`MOVBE`/`LEA`/`ALU`-memory bodies guarded on a restated
`(REG) != X86_REG_NONE` test is now a generated contract:
`generate_x86_reg_presence_spec.py` emits `KPROG_X86_REG_PRESENT`,
`KPROG_X86_REG_ABSENT`, `KPROG_X86_REG_ARM` and the `KPROG_X86_REG_SENTINEL`
sentinel, and `X86RegPresence.lean` proves the presence predicate equals an
independent `decide (reg != 0xff)` and the absence predicate the independent
`decide (reg = 0xff)`, that the two arms invert each other and are both
reachable, and -- pinning the constant the simulator decode fixes -- that the
sentinel is `0xff` and equals the packed-`AUX` memory-index sentinel
(`x86_reg_presence_sentinel_is_index_sentinel`), so the operand-presence and
index-presence decoders cannot disagree about "no register". x86-64 has no
zero register, so unlike the AArch64 mirror the contract has a single sentinel
rather than a zero/sentinel pair. The routed sites replace the inline sentinel
test in the read source-resolution, the MULX second-destination guard, the
MOVBE base-pointer selection, the two LEA source-presence clauses, and the
base-pointer guards of the three `ALU`-memory writeback bodies. A
generated-header oracle drives the presence, absence and arm macros over all
256 register numbers against an independent `reg != 0xff` test, checks the
complementarity and arm gaps, and pins the sentinel against the simulator's own
`X86_REG_NONE` and the memory-index sentinel (768 cases); a sim-header route
oracle drives the real bodies over the present/absent/non-GPR/stack cases, every
width, and both pointer forms, comparing the whole register file with tags and
the modeled heap and stack against an independent model (891 cases).
The x86-64 register-number -> dispatch-cell binding -- the last openly
uncontracted x86 decode -- is itself a generated contract:
`generate_x86_reg_dispatch_spec.py` emits `KPROG_X86_GPR_COUNT` (16) and
`KPROG_X86_GPR_CELL`, and `X86RegDispatch.lean` proves the generated
`cellNumbers` / `cellNames` tables equal an independent `List.finRange 16`
construction (so the dispatch cell index equals the register number and cell
`i` names the corresponding general-purpose register, in the
`rax rcx rdx rbx rsp rbp rsi rdi r8..r15` order), that the table holds exactly
16 distinct entries, that `cellOf` maps exactly the numbers `0..15` and none of
the sentinel (`0xff`) or any byte above `15`, and -- pinning the constants the
presence contract fixes -- that the dispatch `none` case is a subset of the
presence `absent` case (`x86_reg_dispatch_cell_implies_present`), that a present
register is not a `dispatch none` (`x86_reg_dispatch_absent_not_dispatch_some`),
and that the dispatch sentinel is both the operand-presence and the memory-index
sentinel, so the x86 register-number, operand-presence and memory-index decoders
cannot disagree about "no register". The generated header's per-number
`_Static_assert(X86_R<n> == <n>U, ...)` drift checks and the three cell-selector
asserts the sim header adds bind the hand-written `X86_SIM_L_FOR_EACH_GPR`
X-macro order to the generated table, and `X86_SIM_L_REG_VALUE`'s independent
read-path ternary chain is bound by an equality theorem, so neither hand-written
order can drift from the generated cell table. A generated-header oracle drives
the count and cell macros over all 256 register numbers against an independent
`number <= 15 ? number : -1` binding (258 cases), and a sim-header route oracle
drives the real register read and width-narrowed writeback bodies over all 256
register numbers, all four widths and several values, observing which of the
simulator's own 16 cells each write changes and comparing it against the
generated cell selector (6,401 cases).
The x86-64 helper-id -> helper-body binding the call ladder
(`X86_SIM_BPF_CALL_ID`) and its routed register form
(`X86_SIM_BPF_CALL_REG`, the chain's `X86_OP_CALL_REG` arm) select is itself a
generated contract: `generate_x86_helper_dispatch_spec.py` emits
`KPROG_X86_HELPER_COUNT` (7), `KPROG_X86_HELPER_SLOT_NONE` (0xff) and
`KPROG_X86_HELPER_SLOT`, and `X86HelperDispatch.lean` proves the generated
`helperIds` / `helperNames` / `helperBodies` tables equal an independent literal
construction (the armed ids from `List.range 7`, the bodies from the
`"X86_SIM_BPF_CALL_" ++` prefix), that the id table is strictly increasing and
duplicate-free, that the tables hold exactly 7 entries, that `slotOf` maps
exactly the armed ids `1..7` (slot `i` for id `i+1`) and names the zero id, the
first unarmed named id `8`, the last named id `21`, and an id beyond the named
space as no slot, that the id and slot tables invert each other over the armed
range, and that the default arm body is the RAX zero-write the ladder's
`default` arm runs. The routed ladder now consumes that selector (STEP 0132):
`X86_SIM_BPF_CALL_ID` is a `switch` over `KPROG_X86_HELPER_SLOT((__u64)(ID))`
with one `case KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_bpf_<name>):` per armed
body, replacing the former inline `__x86_helper_id == …` chain, and the
generator rejects a ladder that does not switch on the selector or that restates
an inline id comparison. `X86HelperDispatch.lean` additionally proves the
routed body spec `x86HelperDispatchRoutedBodySpec` runs the table body at each
armed id (`x86_helper_dispatch_route_body_refines`), that the selector's slots
over the armed ids are exactly `0..6` in distinct order
(`x86_helper_dispatch_route_labels_distinct`), and that the routed table names
the lookup and ktime bodies at the ends
(`x86_helper_dispatch_route_body_is_table`). The generated header is included
in the sim header just after the `X86_SIM_HELPER_bpf_*` id defines, so its
per-id `_Static_assert`s bind all 21 hand-written id values (and the ladder-arm
order) to the generated table. A generated-header oracle drives the count and
slot macros over ids `0..4096` and the named ids against an independent
`id in 1..7 ? id - 1 : -1` model (4,100 cases), and a sim-header route oracle
drives the real `X86_SIM_BPF_CALL_ID` routed ladder and the routed
`X86_SIM_BPF_CALL_REG` body over every armed id, the zero id, the unarmed named
ids and beyond, and all 256 register numbers, serving the four host-calling
helpers with fixed-return stubs and comparing the whole changed register state
against an independent id-to-body model (2,882 cases).
The x86-64 `XCHG` arm's choice of body on the resolved operand width is itself
a generated contract: `generate_x86_xchg_spec.py` emits
`KPROG_X86_XCHG_FULL_WIDTH` (8), `KPROG_X86_XCHG_ARM_COUNT` (2), the two arm
defines, and the `KPROG_X86_XCHG_ARM(WIDTH)` selector, and `X86XchgHandler.lean`
proves the generated `armOf` equal to an independent selector (the pointer-swap
arm at the width contract's own `x86WidthCodeSpec .w64`, the subword-swap arm at
every other code), that the arm-name and arm-code tables equal an independent
literal order, that the tables hold exactly `armCount` entries and the codes are
duplicate-free, that `armOfCode` inverts `codeOfArm` on the two arms and names
no arm beyond them, that the resolved width code is 8 bits and the full-width
code is exactly the 64-bit width's code, and---the semantic split---that the two
arms are *bit-identical at 64 bits* (so the selector distinguishes an
implementation, not a value) while the subword arm exchanges each cell's
low-lane window, preserves the upper bytes at 8 and 16 bits, and zero-extends at
32. The generated header is included in the sim header, and the routed arm
selects its body through `KPROG_X86_XCHG_ARM(__x86_l_width)` instead of
restating the width test. A generated-header oracle drives the count and
full-width macros and the selector over the whole resolved-width-code domain
against an independent full-width-code binding (260 cases), and a sim-header
route oracle drives the real `XCHG` body over every operand pair and every
resolved width against an independent model that exchanges whole 64-bit cells
and low-lane windows below, comparing the whole register file with its tags and
requiring no third cell to move and the flags to stay put (62,725 cases).
The x86-64 `DIV` arm's choice of quotient/remainder body on the resolved operand
width is likewise a generated contract: `generate_x86_div_spec.py` emits
`KPROG_X86_DIV_ARM_COUNT` (4), the four arm defines, and the nested-ternary
`KPROG_X86_DIV_ARM(WIDTH)` selector, and `X86DivHandler.lean` proves the
generated `armOf` equal to an independent selector built from the width
contract's own `x86WidthCodeSpec` literals (the byte case at `w8`, word at
`w16`, dword at `w32`, qword at every other code — the total/default arm), that
the arm-name and arm-code tables equal an independent literal order, that the
tables hold exactly `armCount` entries and the codes are duplicate-free, that
`armOfCode` inverts `codeOfArm` on the four arms and names no code beyond them,
that the resolved width code is 8 bits and the opcode is `X86_OP_DIV`, and — the
semantic split — that each arm's width code, write count, high-half dividend
register, and high-half gate match the architectural `DIV` split: the byte case
makes exactly one 16-bit partial-register write of the packed quotient/remainder
with no high-half dividend, the three wider cases write both quotient and
remainder registers, and only the qword case gates its split on the high-half
dividend being zero. The generated header is included in the sim header, and the
routed arm selects its body through `KPROG_X86_DIV_ARM(__x86_l_width)` instead
of restating the width ladder. A generated-header oracle drives the width
selector over the whole resolved-width-code domain against an independent
arm ladder (260 cases), and a sim-header route oracle drives the real `DIV` body
over five flag codes (including 0), two source registers, and explicit
dividend/high/divisor tables against an independent quotient/remainder model,
comparing the whole register file with its tags and requiring the flags to stay
put (48,515 cases).
The x86-64 `MULX` arm's choice of which of its two bodies runs is likewise a
generated contract: `generate_x86_mulx_arm_spec.py` emits
`KPROG_X86_MULX_SPECIAL_WIDTH` (4), `KPROG_X86_MULX_ARM_COUNT` (2), the two arm
defines, and the `KPROG_X86_MULX_ARM(WIDTH)` selector, and `X86MulxArmHandler.lean`
proves the generated `armOf` equal to an independent selector built from the
width contract's own `x86WidthCodeSpec .w32` (the single-product arm at the
32-bit code, the four-limb ladder at every other code), that the arm-name table
equals an independent literal order, that the tables hold exactly `armCount`
entries and the codes are duplicate-free, that `armOfCode` inverts `codeOfArm`
on the two arms and names no code beyond them, that the resolved width code is
8 bits and the special-width code is exactly the 32-bit width's code, and---the
semantic split---that the single-product arm is selected exactly at the 32-bit
code and the ladder at every other code, so the band choice is a proved table
rather than a restated `__x86_l_width == X86_WIDTH_32` test. The generated
header is included in the sim header just after the `X86_OP_MULX`/width
decodes, and the routed arm selects its body through
`KPROG_X86_MULX_ARM(__x86_l_width)`; the register reads, the low/high split, and
the two destination writes stay in the composed arm body. A generated-header
oracle cross-checks the compiled selector against an independent literal model
whose arm codes are fixed numbers rather than the generated defines (261 cases),
and a sim-header route oracle drives the real `MULX` body over the four widths
and the absent-code fallback, every `AUX` destination form (including the
no-register sentinel), and a spread of source/destination pairs against an
independent `RDX`-left-operand two-destination model, comparing the whole
register file with its tags (168,965 cases).
The x86-64 register-writeback body `X86_SIM_L_WRITE_REG_WIDTH_SHIFT`, which every
GPR write routes through, likewise selects its writeback body through a
generated contract: `generate_x86_write_width_arm_spec.py` from
`x86_write_width_arm_spec.json` emits the C
`generated/x86_write_width_arm.h` — the `KPROG_X86_WRITE_WIDTH_ARM(CODE)`
nested-ternary 4-way selector, the four `KPROG_X86_WRITE_WIDTH_ARM_B8`/`_B16`/
`_B32`/`_B64` arm codes, `KPROG_X86_WRITE_WIDTH_ARM_COUNT`, and the count,
distinctness, per-width selection, and absent-code `_Static_assert`s — and the
Lean `KProgFormal/GeneratedX86WriteWidthArm.lean`. The generator re-reads the
simulator header on every `--check` and rejects a write-width region that names
no generated selector, omits any of the four bodies or their case macros, or
still contains the hand width ladder `if (__x86_wr_width == X86_WIDTH_8)`. The
body previously resolved the decoded width through `X86_SIM_L_EFFECTIVE_WIDTH`
and then picked, by hand, one byte lane at the 8-bit code, the low word at the
16-bit code, the low dword at the 32-bit code, and the full qword at every other
code; it now routes each body through the generated selector, so the hand ladder
is out of the body, while the effective-width bridge, the delegating wrapper
`X86_SIM_L_WRITE_REG_WIDTH`, and the pointer-writeback helpers are unchanged.
`X86WriteWidthArmShape.lean` proves the generated `armOf` equal to an independent
4-way width-code ladder built on the width contract's own `x86WidthCodeSpec`
literals (`x86_write_width_arm_refines`), the arm-name and arm-code tables, the
code round-trip and out-of-range facts, the per-width map of
`[w8, w16, w32, w64]` to `[b8, b16, b32, b64]`
(`x86_write_width_arm_over_widths`), each body's width code bound to the width
contract's own code for that size (`x86_write_width_arm_width_codes`), the four
distinct bodies and case macros, the width classes, the ladder's totality, and
that an absent width reaches the default qword body
(`x86_write_width_arm_default_is_qword`). Unlike the AArch64 write-register body
(Step 0144, whose value is masked before the body choice, making its two bodies
observationally equal), the x86 width is applied *inside* each body's write macro
and the written value is not pre-masked, so the four bodies write the destination
register genuinely differently; the 258-case host oracle drives the compiled
selector over the raw resolved width code against an independent 4-way
restatement, and the 30726-case sim-header route oracle declares the full
register file, seeds every GPR, and drives the real
`X86_SIM_L_WRITE_REG_WIDTH_SHIFT` over every GPR, the widths `{0, 8, 16, 32, 64,
3}`, the destination shifts `{0, 8}`, and several values against an independent
model that applies the width inside each body (byte lane per shift,
word-preserving, zero-extending dword, full qword), comparing the whole register
file with its tags, so a wrong selector code or a swapped body assignment is
numerically distinguishable.
The x86-64 stack helpers' per-lane width gating is likewise a generated contract:
`generate_x86_stack_write_lanes_spec.py` from `x86_stack_write_lanes_spec.json`
emits `KPROG_X86_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)` with the plain-expression
low-bit mask `KPROG_X86_STACK_WRITE_MASK(WIDTH)` (`w8`→`0x01`, `w16`→`0x03`,
`w32`→`0x0f`, `w64`→`0xff`), which activates byte lane `k` exactly when
`k < byteCount(width)`, and `X86StackWriteLanesShape.lean` proves the generated
mask-bit activation equal to an independent lane-index-versus-byte-count bound
(`x86_stack_write_lanes_refines`), that the byte counts, masks, and lane numbers
equal their independent literals, that the mask is each width's low-bit set, that
an active lane stays active at every wider access while a lane at or above the
byte count is never touched, that the lane's byte extraction is the
`GeneratedX86StackArena` byte, that the width codes are the `X86Width`
contract's own codes, and --- connecting this to the memory-side ladder --- that
the stack and memory byte ladders activate the same lanes and width codes at
every width (`x86_stack_write_lanes_matches_store_bytes`). Unlike the AArch64
Step 0124 write-only helper, the x86-64 read helper `X86_SIM_L_STACK_READ` is
itself a hand-written eight-lane assemble ladder, so the one contract is routed
through *both* `X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ`: each now gates
its eight lane writes (resp. eight lane assemblies) through the generated
predicate instead of the four hand-written
`>= X86_WIDTH_16`/`>= X86_WIDTH_32`/`== X86_WIDTH_64` gate blocks, leaving the
byte-window arithmetic and the little-endian value composition in the composed
bodies. A generated-header oracle checks the compiled predicate's mask bit,
count, and activation against an independent literal oracle over every
width/lane pair (291 cases), and a sim-header route oracle drives the real write
then read over every width and many arena offsets against independent models of
the activation and of the little-endian assembly (1,401,654 cases).
The x86-64 flag-setting entry's token→body selection is likewise a generated
contract: `generate_x86_alu_flag_arm_spec.py` from `x86_alu_flag_arm_spec.json`
emits the C `generated/x86_alu_flag_arm.h` — the
`KPROG_X86_ALU_FLAG_ARM(ALU)` nested-ternary selector, the ten
`KPROG_X86_ALU_FLAG_ARM_*` arm codes, `KPROG_X86_ALU_FLAG_ARM_COUNT`, the
sixteen token-code drift checks, and the count, distinctness, per-token
selection, default and unknown-token `_Static_assert`s — and the Lean table
`GeneratedX86AluFlagArm.lean`, and routes `X86_SIM_L_SET_ALU_FLAGS`'s body
through the selector with the logic body as the default. The generator
cross-checks each arm's token defines against the ALU-decode contract (the
mnemonic lower-cased → `X86_ALU_` + upper), asserts the two collapses (the ADD
and ADC codes both reach the add body; the SHL/SHR/SAR/ROL codes all reach the
shift body) and the total coverage of all sixteen codes, and re-reads the sim
header to require the routed selector, the `__x86_l_old_cf` save/restore, the
INC/DEC carry restores, the `KPROG_X86_PRESERVE_FLAGS()` not arm and the default
logic body while dropping the hand token ladder (`X86_ALU_ADD ||`, …). The hand
module proves the generated `armOf` equal to an independent token ladder built
on the ALU contract's own `x86AluCodeSpec` codes
(`x86_alu_flag_arm_refines`), the ten arm-name/flag-body/case-macro/effect
refinements, the two token collapses (`x86_alu_flag_arm_collapses`), that the
carry-restoring arms are exactly the increment/decrement families
(`x86_alu_flag_arm_cf_restores`), the token-ladder totality and default, and
the code round-trip and out-of-range facts. The 259-case host oracle drives the
compiled header against an independent per-token oracle, and the 776,162-case
route oracle declares the full register file and drives the real flag-setting
entry over all sixteen tokens, every modeled width and several operand triples
against an independent per-token model (including the INC/DEC carry-preserve
behaviour), so a wrong selector code, a swapped body, a dropped carry-restore or
a dropped token is numerically distinguishable.
The x86-64 dispatcher's ten opcode-family membership gates are likewise a
generated contract: `generate_x86_dispatch_family_spec.py` emits
`KPROG_X86_<F>_HANDLED(OP)` for the `MOV_LOAD_PTR`, `MOVX_REG`, `MOV_LOAD`,
`MOV_STORE`, `ALU_IMM`, `ALU_REG`, `CMP_IMM`, `CMP_REG`, `CMP_MEM` and
`DOUBLE_SHIFT` arms over the twenty-four opcodes they name in chain order
(the map-pointer/helper-id load pair `44`/`45`, the MOVZX/MOVSX register pair
`32`/`33`, the `MOV_LOAD` triple `6`/`37`/`34`, the store pair `7`/`8`, the
ALU-immediate pair `10`/`3`, the ALU-register triple `11`/`4`/`5`, the
CMP/TEST immediate pair `12`/`14`, the CMP/TEST register pair `13`/`15`, the
CMP/TEST memory quad `29`/`30`/`31`/`59`, and the SHLD/SHRD pair `27`/`28`),
each a plain-expression disjunction usable inside `_Static_assert`, with every
member opcode `_Static_assert`-pinned to `x86_sim.h` and the generator
requiring verbatim names and codes, rejecting dup names and <2-member
families, and re-reading the sim header to require the ten routed gates and no
raw hand disjunction. `X86DispatchFamily.lean` proves every generated family
membership equal to an independent named-list statement
(`x86_dispatch_<f>_refines` for all ten), that a family member is handled by
some gate and an opcode outside every family by none
(`x86_dispatch_member_handled` / `x86_dispatch_nonmember_unhandled`), that the
generated opcode table matches the `X86_OP_*` numbers
(`x86_dispatch_code_dispatch`, `x86_dispatch_code_in_range`), and that the ten
families are pairwise disjoint across all 45 pairs
(`x86_dispatch_families_disjoint`), so the ordered chain takes at most one
gate per opcode. The generated C header carries the 10 macros, 24 code-drift
asserts, and 24 coverage asserts and no member-count define; the host oracle
sweeps all 256 byte values against every family from an independent switch
oracle plus explicit member and pairwise-distinctness rows (2603 cases), the
chain oracle re-runs the whole specialization chain against the generated
families after reading the gate macros back out of the header (192 cases), and
the route oracle drives the real dispatcher — seven families through their
body macro with the arm's exact argument tuple, three inline-bodied families
through independent models, and a byte-identical non-member probe — over
widths × ops × aux × widths (1141 cases), so a wrong gate, a dropped token, a
family overlap, or a misroute is numerically distinguishable.
The x86-64 `SHLD`/`SHRD` immediate arm's choice of body and flag family on the
opcode is likewise a generated contract: `generate_x86_doubleshift_arm_spec.py`
emits `KPROG_X86_DOUBLESHIFT_ARM_COUNT` (2), the two arm defines, and two
opcode-keyed selectors — `KPROG_X86_DOUBLESHIFT_ARM(OP)` for the body and
`KPROG_X86_DOUBLESHIFT_ARM_FLAGS(OP)` for the `X86_ALU_*` flag family, both
keyed on the same opcode so the body and the family cannot diverge — and
`X86DoubleShiftArmHandler.lean` proves the generated `armOf` equal to an
independent selector from the opcode literals (the left double-shift body at
`X86_OP_SHLD_IMM`, the right at every other opcode — the total/default arm),
that `armOfFlags` equals an independent family selector built from the ALU
contract's own `x86AluCodeSpec .shl`/`.shr` codes and that `resultOfArm` equals
an independent double-shift-function selector over the same opcode literals,
that the arm-name and arm-code tables equal an independent literal order, that
the tables hold exactly `armCount` entries and the codes are duplicate-free,
that `armOfCode` inverts `codeOfArm` on the two arms and names no code beyond
them, that the opcode the arm keys on is 8 bits and the two independent opcode
literals are the codes the opcode contract names for
`X86_OP_SHLD_IMM`/`X86_OP_SHRD_IMM`, and — the
semantic split — that the two bodies compute the two double shifts `x86_shld` /
`x86_shrd` with the SHL and SHR flag families, and that the count-zero step gate
is the architectural `SHLD`/`SHRD` no-op: at a hardware-masked count of zero the
shift-flag contract leaves the flags untouched and both bodies leave the
destination window unchanged, so neither the body nor the family is observable.
The generated header is included in the sim header, and the routed arm selects
both its body and its flag family through the generated selectors instead of a
hand-written `if ((OP) == X86_OP_SHLD_IMM)` test, behind the count-zero step
gate. A generated-header oracle drives both selectors over the whole byte
opcode domain against an independent opcode-keyed model (517 cases), and a
sim-header route oracle drives the real `SHLD`/`SHRD` arm over both opcodes,
five flag codes (including 0), eleven immediates (including count-zero and
count-one), and several destination/source pairs against an independent
bit-by-bit double-shift model and an independent shift-flag model, comparing the
whole register file with its tags and all four flags (326,703 cases).
The x86-64 `POPCNT` arm's arithmetic flag block is likewise a generated
contract: `generate_x86_popcnt_flags_spec.py` emits
`KPROG_X86_SET_POPCNT_FLAGS(C_CF, C_ZF, C_SF, C_OF, ZERO)`, which clears `CF`,
`SF`, and `OF` and sets `ZF` from its single `ZERO` input, and
`X86PopcntFlags.lean` proves the generated transition equal to an independent
statement built from the width contract's own narrowing — `ZF` is
`x86ZeroSpec` of the width-narrowed source, which is exactly the narrowed
source being zero — that the generated opcode equals the independent literal
and is the code the opcode contract names for `X86_OP_POPCNT`, and that the
generated selector names the narrowed-source zero predicate; it further proves
the three clears independent of the source, a zero source setting `ZF` and a
nonzero source clearing it at every width, `SF` cleared even for a source whose
sign bit is set (the semantic split from the logical shape, which would derive
`SF` from the result's sign), and — the narrowing observable — that a source
whose low byte is zero but whose upper bytes are set still clears `ZF` at the
8-bit width. The generated header is included in the sim header, and the routed
arm sets its flags through the `X86_SIM_L_SET_POPCNT_FLAGS` wrapper instead of
restating the clear/set sequence, feeding it the width-narrowed source so the
`ZF` input matches the proven narrowing. A generated-header oracle drives the
macro against an independent literal model from a planted all-set pre-state
(4 cases), and a sim-header route oracle drives the real `POPCNT` arm over five
flag codes (including 0), twelve source values (spanning zero, all-ones,
single-bit, and values whose low byte is zero but whose upper bytes are set),
and three destination/source pairs against an independent bit-by-bit
population-count model and an independent flag model, comparing the whole
register file with its tags and all four flags (5,940 cases).
The x86-64 dispatcher's remaining forty-three individually-gated singleton
opcodes are likewise a generated contract:
`generate_x86_dispatch_singleton_spec.py` emits
`KPROG_X86_DISP_<NAME>_HANDLED(OP)` for the NOP, CALL_MEMCPY, CALL_MEMSET,
CALL_MEMCPY_REG, CALL_MEMSET_REG, CALL_REG, MOV_IMM, MOV_REG, MOVBE_LOAD,
MOVBE_STORE, LOAD_XMM0, STORE_XMM0, LEA, ALU_MEM, ALU_MEM_UNARY, ALU_MEM_IMM,
ALU_MEM_REG, CMP_REG_MEM, CMOV, CMOV_MEM, SETCC, SETCC_MEM, BSWAP, POPCNT,
SHIFTX, SHIFTX_MEM, RORX, RORX_MEM, BZHI, BZHI_MEM, BT, BT_IMM, BT_MEM_IMM,
IMUL_IMM, IMUL_MEM_IMM, MULX, REP_MOVS, ANDN, ANDN_MEM, XCHG, DIV, PUSH and POP
arms, each the plain expression `((OP) == X86_OP_X)` with its `X86_OP_*`
number `_Static_assert`-pinned to `x86_sim.h` and a coverage assert pinning the
macro to its own opcode, and `X86DispatchSingleton.lean` proves every generated
membership equal to an independent named singleton list
(`x86_disp_singleton_<name>_refines` for all forty-three), that a member of one
singleton is handled by some gate and an opcode outside every singleton by none
(`x86_dispatch_singleton_member_handled` /
`x86_dispatch_singleton_nonmember_unhandled`), that the generated opcode table
matches the `X86_OP_*` numbers (`x86_singleton_code_dispatch`,
`x86_singleton_code_in_range`), that the forty-three codes are duplicate-free
(`x86_singleton_codes_nodup`), and — as the cross-contract to the dispatch
families — that the combined singleton and family opcode numbers are pairwise
distinct (`x86_dispatch_chain_codes_nodup`), so the ordered chain selects
exactly one arm per opcode. `X86_SIM_L_EXEC` now selects each singleton arm
through the generated predicate instead of the forty-three hand-written raw
comparisons, leaving the per-arm operand selection and the composed handler
bodies, and the neighboring XCHG, DIV, MOV_REG, double-shift and POPCNT arm
contracts read the routed arms through the generated gates. A generated-header
oracle decides membership from an independent switch oracle over all 256 byte
values for each singleton and a byte-identical non-member probe (11,094 cases),
and a sim-header route oracle drives each singleton through the real dispatcher
— inline-bodied singletons through independent models and the body-macro
singletons through their argument tuples — plus a non-member probe reaching the
unsupported arm exactly once (582 cases).
The x86-64 `BZHI`/`BZHI_MEM` arms' flag block is likewise a generated
contract: `generate_x86_bzhi_flags_spec.py` emits
`KPROG_X86_SET_BZHI_FLAGS(C_CF, C_ZF, C_SF, C_OF,
COUNT_AT_LEAST_WIDTH_BITS, RESULT_IS_ZERO)`, which clears `SF` and `OF`, sets
`CF` from its count-versus-width input, and sets `ZF` from its result-zero
input, and `X86BzhiFlags.lean` proves the generated transition equal to an
independent statement built from its two predicate inputs, that the generated
opcodes equal the independent literals and are the codes the opcode contract
names for `X86_OP_BZHI`/`X86_OP_BZHI_MEM`, that the generated flag sources
agree with the spec, and that the two inputs are ordered count-then-result;
it further proves the `SF`/`OF` clears, the `CF` count-versus-width and
`ZF` result-zero characterisations, and the threshold and below-width
behaviour at the 8- and 64-bit widths. Unlike `POPCNT` the block takes
**two** inputs, so a single-input logic-flag reuse would be wrong. The
generated header is included in the sim header, and the routed step sets its
flags through the `X86_SIM_L_SET_BZHI_FLAGS` wrapper instead of restating the
comparison sequence, feeding it the byte-masked count, the resolved width's
bit count, and the cleared result so both inputs match the proven contract. A
generated-header oracle drives the macro against an independent literal model
from a planted all-set pre-state (7 cases), and a sim-header route oracle
drives the real `BZHI`/`BZHI_MEM` arms over five width codes, counts sweeping
every width's bit count, and sources whose cleared result is zero and nonzero,
comparing the whole register file with its tags and all four flags (36,961
cases).
The x86-64 `MOVZX`/`MOVSX` register arm's choice of which extension function
widens the raw source register is likewise a generated contract:
`generate_x86_movx_shape_spec.py` emits `KPROG_X86_MOVX_SHAPE(OP)`, which names
the sign extension at `X86_OP_MOVSX_REG` and the zero extension at every other
opcode (so the default is the zero extension), and `X86MovxShape.lean` proves
the generated selector equal to an independent opcode-literal statement that
names the sign extension exactly at `X86_OP_MOVSX_REG`, that the generated
opcodes are the literals the opcode contract already names for
`X86_OP_MOVZX_REG`/`X86_OP_MOVSX_REG`, that the arm result names agree with the
generated table, that the two opcodes are distinct, that an arm code beyond the
two named arms is unrecognised, and — connecting this selection contract to
the value composition — that the selected arm's per-opcode extension picks the
`X86MovxRegHandler` extension (`sign_extend` at `MOVSX`, `zero_extend` at
`MOVZX`). Both the standalone `X86_SIM_L_EXEC_MOVX_REG` body and the inline
`X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm compute the selector and branch the
widened value through the selected function, leaving only the partial-register
writeback in the composed arm bodies. The source width both bodies widen at is
itself a generated contract (STEP 0133): `generate_x86_movx_shape_spec.py` also
emits `KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE` (0) and the plain-ternary
`KPROG_X86_MOVX_SRC_WIDTH(AUX, WIDTH)`, re-deriving the four width codes from the
public `x86_width_spec.json` so the contract is stated against the width names
the rest of the simulator uses, and `X86MovxShape.lean` proves the generated
`srcWidth` refines an independent `x86MovxSrcWidthSpec`, that it is the identity
on every real width and resolves only the absent code to the effective width,
that it covers exactly the four width codes, and that it composes with the width
kernel so a resolved source width is never the absent code. Both live bodies now
compute `__x86_l_src_width = KPROG_X86_MOVX_SRC_WIDTH((AUX), __x86_l_width)`
instead of the former inline `(AUX) ? (AUX) : __x86_l_width` fallback, and the
generator rejects a body that does not route through the selector or that
restates the inline fallback. A generated-header oracle cross-checks the
compiled opcode-shape selector over the whole opcode byte range and the compiled
source-width selector over the whole `aux` byte range crossed with the real
effective widths against an independent literal model of each selection (1,289
cases), and a
sim-header route oracle drives the real `MOVX` arm over both opcodes, five flag
codes (including 0), several AUX source widths (including the absent-code
fallback), high-bit source values, and register pairs against an independent
sign/zero-extension model, comparing the whole register file with its tags
(118,803 cases).
The x86-64 `MOV_REG` register arm's choice of which body a `mov` runs is
likewise a generated contract: `generate_x86_mov_reg_arm_spec.py` emits
`KPROG_X86_MOV_REG_ARM(W, RSP)`, which names the stack-base pointer write at
the full 64-bit width code when the encoded source register is the stack
pointer, the provenance-preserving pointer write at the full width for every
other source, and the narrow scalarizing lane write at every other width code
whatever the source (the stack-pointer test nested inside the width test), and
`X86MovRegShape.lean` proves the generated `armOf` equal to an independent
width/register-literal statement that names the stack-pointer body exactly at
the full-width/`X86_RSP` pair, that the generated opcode is the literal the
opcode contract already names for `X86_OP_MOV_REG`, that the arm result names
agree with the generated table, that the arm codes are distinct and their
lookup is a left inverse, and — connecting this selection contract to the value
composition — that the selected arm's effect is the per-arm step
`X86MovHandler` proves (the stack-base write at `stackPtr`, the provenance
copy at `pointer`, the RSP-ignoring narrow write at `narrow`). Both the
standalone `X86_SIM_L_EXEC_MOV_REG_AUX` body and the inline `X86_OP_MOV_REG`
arm compute the selector and branch through the selected body, leaving the
register reads, the stack-base addition, and the destination writeback in the
composed arm bodies. A generated-header oracle cross-checks the compiled
selector against an independent literal model over all 256×256 width/register
byte pairs (65,540 cases), and a sim-header route oracle drives the real
`MOV_REG` arm over five flag codes (including the absent-code 64-bit fallback),
four AUX lane-shift words, several source/destination values, and register
pairs (including `dst == src` and both `RSP` orderings) against an independent
lane read/write and stack-base model, comparing the whole register file with
its tags (79,202 cases).
The two x86-64 stack helpers' choice of which body moves a word through the
frame is likewise a generated contract: `generate_x86_stack_arm_spec.py` emits
`KPROG_X86_STACK_ARM(IS_W64, IS_ALIGNED)`, which names the word-arena access at
the full 64-bit width code on a qword-aligned resolved index and the
little-endian byte ladder at every other width and every unaligned index, and
`X86StackArmShape.lean` proves the generated `armOf` equal to an independent
width/alignment-literal statement that names the word body exactly at the
full-width/aligned pair and the byte body at the other three cases, that the
arm result names agree with the generated table, that the arm codes are
distinct and their lookup is a left inverse, and — connecting this selection
contract to the arena contract — that the chosen body matches the
`X86StackArena` word/byte split. Both `X86_SIM_L_STACK_WRITE` and
`X86_SIM_L_STACK_READ` compute the two-fact selector and branch through the
selected body, leaving the byte-window arithmetic, the narrow-value masking,
and the little-endian assembly in the composed bodies. A generated-header
oracle cross-checks the compiled selector against an independent literal model
over all 256×256 boolean-fact pairs (65,540 cases), and a sim-header route
oracle drives the real stack helpers over every resolved index (aligned and
unaligned), five width codes (including the absent-code 64-bit fallback), and
several values against an independent little-endian byte model, comparing the
whole byte arena and the read-back (117,782 cases).
The AArch64 stack *read* helper's choice of which body reads a word through
the frame is likewise a generated contract: `generate_arm64_stack_arm_spec.py`
emits `KPROG_ARM64_STACK_ARM(IS_W64, IS_ALIGNED)`, which names the word-arena
access at the full 64-bit width code on a qword-aligned resolved index and the
little-endian byte ladder over `b[]` at every other width and every unaligned
index, and `Arm64StackArmShape.lean` proves the generated `armOf` equal to an
independent width/alignment-literal statement that names the word body exactly
at the full-width/aligned pair and the byte body at the other three cases, that
the arm result names agree with the generated table, that the arm codes are
distinct and their lookup is a left inverse, and — connecting this selection
contract to the arena contract — that the chosen body matches the
`Arm64StackArena` word/byte split. `ARM64_SIM_L_STACK_READ` computes the
two-fact selector and branches through the selected body, leaving the
byte-window arithmetic and the little-endian assembly in the composed bodies;
the stack *write* helper already routed its slot-tag gate through the
machine-checked `KPROG_ARM64_STACK_TAG` contract, so only the read body choice
was open. A generated-header oracle cross-checks the compiled selector against
an independent literal model over all 256×256 boolean-fact pairs (65,540
cases), and a sim-header route oracle drives the real read helper over every
resolved index and every width against an independent model of both bodies and
the selected arm, plus the real write/read round-trip, comparing each read
against the body the independent selector names (167,478 cases).
The AArch64 memory store's little-endian width ladder is likewise a generated
contract: `generate_arm64_store_bytes_spec.py` emits
`KPROG_ARM64_STORE_BYTES(ADDR, WIDTH, VALUE)` (from
`arm64_store_bytes_spec.json`), which resolves the width through
`KPROG_ARM64_APPLY_WIDTH`, writes each in-range byte of the value exactly once
through a `volatile __u8 *` pointer, leaves every byte above the width
untouched, and writes no NZCV, and `Arm64StoreBytes.lean` proves the generated
`image` (the masked truncation `value &&& 0xff`/`0xffff`/`0xffffffff`/`value`)
equal to an independent lane-by-lane write-then-read statement, that the byte
counts are 1/2/4/8 and the width codes 1/2/4/8, that a narrow store leaves the
covered word's higher bytes zero, and — connecting this contract to the load
contract — that the store `image` equals `arm64LoadBytesSpec` at every width
(`arm64_store_bytes_load_agree`). `ARM64_SIM_L_STORE_ADDR` (and so the
`ARM64_SIM_L_MEM_WRITE` caller) routes through the generated macro, leaving the
address arithmetic and the destination selection in the composed bodies. A
generated-header oracle pre-fills a heap buffer with a sentinel and checks the
whole image (covered bytes written, higher bytes untouched) against an
independent byte-pointer oracle over six boundary patterns and 20000 fixed-seed
values across all four widths (20,024 cases); a sim-header route oracle drives
the real write over those inputs against an independent width-masked scatter
model of the whole heap, plus a store/read-back round trip through the routed
load at every width (16,486,328 cases).
The AArch64 store helper's choice of which body writes the resolved access is
likewise a generated contract: `generate_arm64_mem_write_arm_spec.py` emits
`KPROG_ARM64_MEM_WRITE_ARM(BASE_IS_SP, TAG)`, which names the stack arena body
(`ARM64_SIM_L_STACK_WRITE_TAG`) when the base register is the stack pointer or
its resolved tag names a stack slot and the plain little-endian byte store
(`ARM64_SIM_L_STORE_ADDR`) at every other base, and
`Arm64MemWriteArmShape.lean` proves the generated `armOf` equal to an
independent disjunction statement that names the stack arm at exactly the four
`(base-is-SP, stack-tagged)` cases where either fact holds, that the arm names
and codes agree with the generated table, that the arm codes are distinct and
their lookup is a left inverse, and — connecting this selection contract to the
load dispatch — that the chosen destination matches the `KPROG_ARM64_MEM_READ_SRC`
space/source table (so the two cannot drift). `ARM64_SIM_L_MEM_WRITE` computes
the two-fact selector and branches through the selected body, leaving the
address arithmetic and the composed bodies. A generated-header oracle
cross-checks the compiled selector against an independent disjunction oracle
over every `(base-is-SP, tag)` pair and against the generated load dispatch's
own space table (24 cases), and a sim-header route oracle drives the real write
over four base kinds (the stack pointer, a stack-tagged register, a scalar
register, and a non-stack-tagged register) at every width and twelve
arena/heap indices against an independent model of both bodies and the
slot-tag rule, plus the real write/read round-trip, comparing the whole heap
image, the whole stack byte image, and the whole slot-tag image (17,758,119
cases).
The AArch64 stack write helper's per-lane width gating is likewise a generated
contract: `generate_arm64_stack_write_lanes_spec.py` emits
`KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)` with the plain-expression
low-bit mask `KPROG_ARM64_STACK_WRITE_MASK(WIDTH)` (`w8`→`0x01`, `w16`→`0x03`,
`w32`→`0x0f`, `w64`→`0xff`), which activates byte lane `k` exactly when
`k < byteCount(width)`, and `Arm64StackWriteLanesShape.lean` proves the
generated mask-bit activation equal to an independent
lane-index-versus-byte-count bound, that the byte counts, masks, and lane
numbers equal their independent literals, that the mask is each width's low-bit
set and its set-bit count is the byte count, that an active lane stays active at
every wider access while a lane at or above the byte count is never written, and
--- connecting this to the memory-side ladder and the byte-lane extraction ---
that the stack and memory byte ladders activate the same lanes and width codes
at every width (`arm64_stack_write_lanes_matches_store_bytes`).
`ARM64_SIM_L_STACK_WRITE_TAG` now gates each of its eight byte-arena lane writes
through the generated predicate instead of the four hand-written
`>= ARM64_WIDTH_16`/`>= ARM64_WIDTH_32`/`== ARM64_WIDTH_64` gate blocks, leaving
the byte-window arithmetic and the little-endian value composition in the
composed bodies. A generated-header oracle checks the compiled predicate's mask
bit, count, and activation against an independent literal oracle over every
width/lane pair (291 cases), and a sim-header route oracle drives the real write
over every width and many arena offsets against an independent model of the
activation, plus the real store/read round-trip (3,843,511 cases).
The AArch64 dispatcher's eight immediate/register opcode-family gates are
likewise a generated contract: `generate_arm64_dispatch_family_spec.py` emits
`KPROG_ARM64_<F>_HANDLED(OP)` for the ALU, SHIFT, SUBS, ADDS, CMP, TST, ANDS and
CCMP arms, each a plain-expression disjunction over its two member opcodes with
each member's `ARM64_OP_*` number `_Static_assert`-pinned to `arm64_sim.h`, and
`Arm64DispatchFamily.lean` proves every generated membership equal to an
independent named-list membership statement
(`arm64_dispatch_<F>_refines`), that the eight families are pairwise disjoint so
the ordered chain takes at most one gate per opcode, and that the generated
opcode table matches the `ARM64_OP_*` numbers
(`arm64_dispatch_code_dispatch`), so a member reaches its arm and a non-member
reaches the caller's unsupported arm. `ARM64_SIM_L_EXEC` now selects each arm
through the generated predicate instead of the eight hand-written `||` pairs,
leaving the per-arm operand selection and the composed handler bodies. A
generated-header oracle decides membership from an independent switch oracle
over all 256 byte values for each family (2072 cases), and a sim-header route
oracle drives both members of each family through the real dispatcher with equal
operands and requires the whole-state snapshots to agree, the right
destinations to be written, the flags-only arms to leave the destination
untouched, and a non-member opcode to reach the unsupported arm exactly once
(136 cases).
The dispatcher's remaining sixteen individually-gated singleton opcodes are
likewise a generated contract: `generate_arm64_dispatch_singleton_spec.py` emits
`KPROG_ARM64_DISP_<NAME>_HANDLED(OP)` for the NOP, MOVK, BITFIELD, CMN_IMM,
CMN_REG, TST_BIC_REG, BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0, STORE_D0,
LOAD_Q0, STORE_Q0 and FMOV arms, each the plain expression
`((OP) == ARM64_OP_X)` with its `ARM64_OP_*` number `_Static_assert`-pinned to
`arm64_sim.h` and a coverage assert pinning the macro to its own opcode, and
`Arm64DispatchSingleton.lean` proves every generated membership equal to an
independent named singleton list (`arm64_disp_<name>_refines`), that a
non-member reaches the caller's unsupported arm, that all sixteen opcodes lie in
the C opcode-byte range, and — as the cross-contract to the dispatch families —
that the combined singleton and dispatch-family opcode numbers are pairwise
distinct (`arm64_dispatch_chain_codes_nodup`), so the ordered chain selects
exactly one arm per opcode. `ARM64_SIM_L_EXEC` now selects each singleton arm
through the generated predicate instead of the sixteen hand-written raw
comparisons, leaving the per-arm operand selection and the composed handler
bodies. A generated-header oracle decides membership from an independent switch
oracle over all 256 byte values for each singleton (4128 cases), and a sim-header
route oracle drives each singleton through the real dispatcher over an
independent flat byte-image model, planting scalar/stack-tagged/ABI-tagged bases
and sweeping widths × ops × bases × flags × index × immediate with a non-member
probe reaching the unsupported arm (11083 cases).
The dispatcher's two remaining operand-source selections are likewise a
generated contract: `generate_arm64_imm_operand_spec.py` emits
`KPROG_ARM64_IMM_RHS(OP, IMM, REG)` for the move arm (MOV_IMM/MOV_REG, register
form reads the source) and the shift arm (SHIFT_IMM/SHIFT_REG, register form
reads the second source), a statement expression that seeds its result with
`(REG)` and sets it to `(IMM)` exactly on the two `_IMM` opcodes, with each
`ARM64_OP_*` number `_Static_assert`-pinned to `arm64_sim.h`, and
`Arm64ImmOperand.lean` proves the generated `immediate` predicate equal to an
independent named-list membership (`arm64_imm_operand_refines`), that exactly
the `_IMM` member of each pair is immediate
(`arm64_imm_operand_pairs_exclusive`), that the two families are disjoint, and
that all four opcodes lie in the C opcode-byte range. `ARM64_SIM_L_EXEC` now
selects both operands through the generated macro instead of the two hand-written
ternaries. A generated-header oracle decides immediate membership from an
independent switch oracle over all 256 byte values × five immediates × four
register expressions (5120 cases), and a sim-header route oracle drives the
generated selector through the real dispatcher arms over an independent
whole-state model with distinct immediate and register values, all four widths,
every shift kind and a non-member probe (3804 cases).
The sign-extending load arm is likewise a generated contract:
`generate_arm64_ldrsx_op_spec.py` emits `KPROG_ARM64_LDRSX_SXOP(OP, UNSUPPORTED)`
for the LDRSB/LDRSW/LDRSH arms, a statement expression that seeds its result with
`0` and selects `ARM64_OP_SXTB`/`ARM64_OP_SXTW`/`ARM64_OP_SXTH` exactly on the
`case 54U`/`57U`/`63U` load opcodes, forwarding every other opcode to the
caller-supplied unsupported arm, with each `ARM64_OP_*` number
`_Static_assert`-pinned to `arm64_sim.h`, and `Arm64LdrsxOp.lean` proves the
generated `sxCode` equal to an independent code-keyed statement
(`arm64_ldrsx_op_refines`), that the derived opcode is determined by the load
opcode alone (`arm64_ldrsx_op_code_determined`), that each derived opcode is a
member of the independent sign-opcode table
(`arm64_ldrsx_op_selects_member`) and is never itself a load opcode
(`arm64_ldrsx_op_sx_not_load`), that the load opcodes and sign opcodes are each
pairwise distinct, that the sign position pinned by `signBits` matches the
well-tested load-width contract (`arm64_ldrsx_op_signbits_match_width`), and that
every load opcode lies in the numeric case-label range the shared macro
addresses. `ARM64_SIM_L_EXEC` now derives the sign-extending opcode through the
generated macro instead of the hand-written ternary. A generated-header oracle
decides the derived opcode from an independent switch oracle over all 256 byte
values (256 cases), and a sim-header route oracle drives the generated selector
through the real dispatcher arm over an independent flat byte-image model with an
independent cast-ladder sign extension, comparing the whole post-state across
widths, loaded values, registered sign patterns and a non-member probe (98197
cases).
The ALU arm's operand-source decision is likewise a generated contract:
`generate_arm64_alu_operand_select_spec.py` emits
`KPROG_ARM64_ALU_OPERAND_SELECT(OP)` for the generic ALU arm
(`ALU_IMM`/`ALU_REG`), a statement expression that seeds its result with `0`
(the register form) and sets it to `1` exactly on the `ALU_IMM` case, every other
code falling through to the register form, with each `ARM64_OP_*` number
`_Static_assert`-pinned to `arm64_sim.h`; the macro returns the 0/1 *decision*
that the existing `KPROG_ARM64_ALU_RHS` value contract takes as its first
argument, so the two compose rather than duplicate. `Arm64AluOperandSelect.lean`
proves the generated `immediate` predicate equal to an independent named-list
membership (`arm64_alu_operand_select_refines`), that no register-form opcode
selects the immediate (`arm64_alu_operand_select_reg_never_immediate`), that the
two opcode lists are disjoint (`arm64_alu_operand_select_lists_disjoint`), the
exact 6/7 code dispatch and case-label range, the operand-value `Mode` bridge,
and the composition into `arm64_alu_operand_handler_refines`
(`arm64_alu_operand_select_composes`). `ARM64_SIM_L_EXEC` now routes the ALU
arm's source decision through the generated macro instead of the hand-written
opcode test. A generated-header oracle decides the source from an independent
switch oracle over all 256 byte values (256 cases), and a sim-header route
oracle drives the generated selector through the real dispatcher arm over an
independent flat byte-image model, comparing the whole post-state across four
widths, six ALU operations, the immediate and register forms, a non-member probe,
the pointer-preserving 64-bit ADD path, a scalar-source path and an SP
destination (21688 cases).
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

The `CMP_IMM` / `CMP_REG` / `TEST_IMM` / `TEST_REG` / `CMP_MEM_IMM` /
`TEST_MEM_IMM` / `CMP_MEM_REG` / `TEST_MEM_REG` theorem covers all eight
compare/test opcodes: the register forms `X86_OP_CMP_IMM` (`0x0c`),
`X86_OP_CMP_REG` (`0x0d`), `X86_OP_TEST_IMM` (`0x0e`), `X86_OP_TEST_REG`
(`0x0f`) and the memory forms `X86_OP_CMP_MEM_IMM` (`0x1d`),
`X86_OP_TEST_MEM_IMM` (`0x1e`), `X86_OP_CMP_MEM_REG` (`0x1f`),
`X86_OP_TEST_MEM_REG` (`0x3b`) — the opcodes that compare or test without
writing a register. All eight resolve *one* width `FLAGS ? FLAGS : 64` and read
their register-operand lanes through the width/lane register read
(`x86_cmpop_write_width_refines`). Four per-opcode facts separate them, each a
table entry (`x86_cmpop_rhs_source_refines`, `x86_cmpop_flag_kind_refines`,
`x86_cmpop_lhs_source_refines`, `x86_cmpop_disp_kind_refines`): the left-hand
side is the destination register for the register forms and the addressed
memory operand for the memory forms (`x86_cmpop_lhs_refines`); the right-hand
side is the decoded immediate for the `_IMM` forms (`x86ImmediateValueSpec`) and
the register read of `SRC` for the `_REG` forms; the flag kind is the
zero-borrow subtraction flags for the `CMP` opcodes and the logical flags of the
width-narrowed conjunction for the `TEST` opcodes; and the memory-form
displacement is the whole immediate as a signed displacement for `CMP_MEM_REG`
alone and the high 32 bits as a store displacement for the other memory forms
(the register forms' displacement is unused and reads as the signed-immediate
form). The facts are provably independent (`x86_cmpop_tables_independent`,
`x86_cmpop_lhs_disp_independent`): `CMP_IMM`/`TEST_IMM` share a left/right source
but differ in flag kind, `CMP_IMM`/`CMP_REG` share flags but differ in source,
and `TEST_MEM_REG` is memory-left/register-right yet store-displacement, so no
row is a function of another. The memory right-hand side is read whole at 64
bits (letting the flag production narrow it), which the register forms' lane
read does not do (`x86_cmpop_lhs_arms`); the final flags are identical. All
eight write no register (`x86_cmpop_preserves_dst`,
`x86_cmpop_flag_production`, `x86_cmpop_mem_reg_borrow_w64`). `x86_cmpop_step_refines`
composes the whole body over the generated source/flag-kind/left-source/disp-kind/width
tables and the shared register/memory read, immediate decode,
subtraction/logical flag production, and register pass-through; its independent
oracle exercises the generated tables, the full composition over a deterministic
register model at both AUX lanes, and pins the register/memory left-hand-side
split, the immediate/register right-hand-side split, the `CMP`/`TEST` flag-kind
split, the displacement-kind split, the destination-lane and `SRC`-lane reads,
the immediate sign-extension at the resolved width, the absent-width default,
and register-preserving write-free memory. The register decode that selects the
opcode remains outside the theorem.

The eight bodies named in that paragraph now share one
`X86_SIM_L_EXEC_CMP_STEP` composition that routes the left-hand-side source
through the machine-checked `KPROG_X86_CMPOP_LHS_SOURCE` selector, the
right-hand-side source through `KPROG_X86_CMPOP_RHS_SOURCE`, the flag kind
through `KPROG_X86_CMPOP_FLAG_KIND`, the memory displacement kind through
`KPROG_X86_CMPOP_DISP_KIND`, and the one resolved width through
`KPROG_X86_CMPOP_WRITE_WIDTH`, so the eight bodies and the Lean refinement share
one compare/test step rather than restated sequences and the per-opcode selector
is compile-time at each wrapper. The independent `test_x86_cmpop_route_host.c`
oracle includes the simulator header and drives the four register bodies —
directly and through the `X86_SIM_L_EXEC` dispatcher arms that route to them —
over both register/immediate source forms, every FLAGS code, both AUX lanes, and
three destination / source registers, comparing the whole register file with its
tags and all four flags against an independent model; its planted registers
carry the immediate-incompatible high word `0xa5a5…` and bits above bit 32, so a
body that resolves the wrong right-hand side, produces the wrong flag kind
(`CMP` clears `OF` and computes `CF` from the borrow, `TEST` clears both), or
narrows to 32 bits instead of the resolved width is numerically distinguishable
at every opcode, width, and lane. The independent `test_x86_cmp_mem_route_host.c`
oracle drives all four *memory* bodies — directly and through the
`X86_SIM_L_EXEC` dispatcher arm — over the modeled heap, stack, and ABI
pointer-load arms, every FLAGS width, the identity and scaled-index addressing,
and both displacement forms, comparing the whole register file with its tags,
the heap, the stack, and all four flags against an independent model. Its
displacement pair (`imm = 8` with the store form reading the heap at offset 0
and the whole-immediate form at offset 8, whose bytes differ) makes a body that
routes the wrong displacement kind numerically distinguishable, and its planted
ABI pointer value makes a body that misclassifies the load arm observable.

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

The AArch64 load/store index-register presence decision shared by that offset
macro is itself a generated contract: `generate_arm64_mem_index_spec.py` emits
`KPROG_ARM64_MEM_INDEX_PRESENT` and `KPROG_ARM64_MEM_INDEX_ARM`, and
`Arm64MemIndex.lean` proves the presence predicate equals an independent
`decide (indexByte != 0xff)` (the `ARM64_REG_NONE` sentinel), that the two arms
invert each other and are both reachable, that the two presence cases are
exactly the two `hasIndex` cases `KPROG_ARM64_MEM_OFFSET` consumes, and -- with
no x86 analogue -- that the memory-index sentinel narrows to the `AUX` layout's
`ARM64_REG_NONE` sentinel (`arm64_mem_index_sentinel_is_aux_reg_none`), so the
two independently generated sentinels cannot drift. `ARM64_SIM_L_MEM_BASE_OFF`
now resolves both its presence flag and its index-value selector through that
bridge, so the sentinel test is no longer restated in the simulator. A
generated-header oracle drives the presence and arm macros over all 256 index
bytes against an independent `byte != 0xff` test (512 cases), and a sim-header
route oracle drives the real macro over index operands (deliberately allowed to
disagree with the `AUX` index lane), the sentinel and every raw flag byte
against an independent presence/value oracle (22,115 cases).

The AArch64 write-register destination-presence decision shared by the three
writeback bodies `ARM64_SIM_L_WRITE_REG_WIDTH`, `ARM64_SIM_L_WRITE_REG_PTR` and
`ARM64_SIM_L_WRITE_REG_PTR_TAG` is itself a generated contract:
`generate_arm64_reg_presence_spec.py` emits `KPROG_ARM64_REG_WRITABLE`,
`KPROG_ARM64_REG_CLASS` and the `KPROG_ARM64_REG_XZR` / `KPROG_ARM64_REG_NONE`
sentinels, and `Arm64RegPresence.lean` proves the presence predicate equals an
independent `decide (reg != 31 && reg != 0xff)`, that the class selector equals
the literal-number table (both boundaries included), that all three classes are
reachable, and -- pinning the constants the simulator decode fixes -- that the
zero-register number is `31` (`ARM64_XZR`), the no-register number is the
all-ones byte (`ARM64_REG_NONE`), and the sentinel is the memory-index sentinel
(`arm64_reg_presence_none_is_index_sentinel`), so the destination-presence and
memory-index decoders cannot disagree about "no register". All three writeback
bodies now guard their GPR dispatch on `KPROG_ARM64_REG_WRITABLE(REG)`, so the
`(REG) != ARM64_XZR && (REG) != ARM64_REG_NONE` test is no longer restated in
the simulator (the `SP` branch stays separate, evaluated before the guard). A
generated-header oracle drives the presence and class macros over all 256
register numbers against an independent `reg != 31 && reg != 0xff` test and the
class table (512 cases), and a sim-header route oracle drives the three real
writeback bodies over all 256 register numbers, all four widths and both pointer
forms, comparing the whole register file with tags and the stack pointer against
an independent model that writes only when the number is neither `31` nor `0xff`
(6,913 cases).

The width *body* that writeback body then picks is likewise a generated
contract: `generate_arm64_write_arm_spec.py` emits `KPROG_ARM64_WRITE_ARM` and
the `…_FULL` / `…_NARROW` arm codes, and `Arm64WriteArmShape.lean` proves the
selector equals an independent 2-way literal over the width fact, the arm-name
and arm-code tables, the code round-trip and out-of-range facts, both bodies,
the 32-bit literal's binding to the width contract's own code
(`arm64_write_arm_w32_spec_bound`), the per-width map of `[w8, w16, w32, w64]`
to `[full, full, narrow, full]` (`arm64_write_arm_over_widths`), the two-case
dispatch, and that the narrow body is selected exactly at the width the
pre-truncation step masks to 32 bits
(`arm64_write_arm_narrow_matches_pre_truncation`), so the body choice and the
pre-truncation step cannot disagree about which width truncates. Because the
value is masked to the width before the body choice, the two bodies are
observationally equal for every width the simulator reaches, so the split is a
genuine no-op on state and only a wrong selector code or a swapped body
assignment is observable. `ARM64_SIM_L_WRITE_REG_WIDTH` now selects its body
through the generated selector, so the hand `if ((WIDTH) == ARM64_WIDTH_32)`
test is no longer restated in the simulator (the `SP` branch and the
destination-presence guard stay separate). A generated-header oracle drives the
selector and the two arm-code defines over the raw width fact against an
independent 2-way restatement (260 cases), and a sim-header route oracle drives
the real writeback body over all 256 register numbers, all four width codes and
several values against an independent model that masks first and then truncates
exactly when the width code is the 32-bit code (6,401 cases).

The AArch64 register-number -> dispatch-cell binding -- the last openly
uncontracted AArch64 decode -- is itself a generated contract:
`generate_arm64_reg_dispatch_spec.py` emits `KPROG_ARM64_GPR_COUNT` and
`KPROG_ARM64_GPR_CELL`, and `Arm64RegDispatch.lean` proves the generated
`cellNumbers` / `cellNames` tables equal an independent `List.finRange 31`
construction (so the dispatch cell index equals the register number and cell
`i` names `x{i}`), that the table holds exactly `gprCount` distinct entries,
that `cellOf` maps exactly the general-purpose register numbers `0..30` and
none of the zero register (`31`), the stack pointer (`32`) or the sentinel
(`0xff`), and -- pinning the constants the presence contract fixes -- that the
dispatch count begins exactly where the write-presence decoder starts
discarding (`arm64_reg_dispatch_count_is_xzr`), that the zero register and the
sentinel name no cell, and that the dispatch `none` case is a subset of the
presence `discard` case
(`arm64_reg_dispatch_cell_implies_writable`,
`arm64_reg_dispatch_writable_not_dispatch_none`); a further theorem fixes the
dispatch sentinel as the memory-index sentinel, so the three arm64 decoders
cannot disagree about "no register". The hand-written
`ARM64_SIM_L_FOR_EACH_GPR` order is bound to the generated table both by the
generated header's per-number `_Static_assert(ARM64_X<n> == <n>U, ...)` drift
checks and by the three cell-selector asserts the sim header adds, so the
X-macro dispatch order can no longer drift from the generated cell table. A
generated-header oracle drives the count and cell macros over all 256 register
numbers against an independent number-is-cell binding (257 cases), and a
sim-header route oracle drives the real `ARM64_SIM_L_READ_REG` /
`READ_REG_PTR` / `WRITE_REG_WIDTH` bodies over all 256 register numbers, all
four write widths and several values, observing which of the sim's own 31 GPR
cells each write changes and comparing it against the generated cell selector
(6,401 cases).

The whole-program control-flow trace contract lifts the per-edge
conditional-transfer emission facts to an arbitrary-length path. A trace is a
list of conditional edges, each edge an already-evaluated predicate value and a
candidate target; the generated
`GeneratedControlFlowTrace.emittedStep`/`walk`/`walkPolicy` fold the per-edge
`nextPc` next-PC selection over the path, threading the program counter and --
in `walkPolicy` -- recomputing the direction shape at every edge from the running
program counter and the edge target, exactly as the simulator calls
`KPROG_X86_BRANCH_BACKWARD` / `KPROG_ARM64_BRANCH_BACKWARD` at each conditional
transfer. The hand-written `ControlFlowTrace.archWalk` is the independent
architectural walk, stated directly over the shared `branchPc` model with no
reference to any emitted shape or direction policy, and
`control_flow_trace_walk_refines` / `control_flow_trace_walk_policy_refines`
prove the emitted walks equal it for every direction shape and every per-edge
policy -- the whole-program lift of `x86_branch_emit_refines` /
`arm64_branch_emit_refines`, so the per-edge direction computation is a
machine-checked whole-program no-op. Supporting lemmas fix the walk's induction
behaviour (`control_flow_trace_walk_append`), that the direction shape is
irrelevant to a whole trace (`control_flow_trace_walk_shape_irrelevant`) and
that an all-fall-through trace advances by exactly its length
(`control_flow_trace_walk_all_fallthrough`). A generated-header oracle folds the
edge macro `KPROG_CONTROL_FLOW_EDGE_NEXT` over random traces against an
independent `taken ? target : pc + 1` walk while cross-checking the direction
macro and both emitted goto/fall-through shapes (845 cases), and a route oracle
folds the real `X86_SIM_X86_JCC` and `ARM64_SIM_A64_JCC` macros -- each routed
through its own generated direction macro -- over random traces for both ISAs
against the same independent walk (3,108 cases).

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

The AArch64 decoded width a body operates at — the arm64 analogue of the x86
effective-width resolution — is now the same generated contract rather than an
inline fallback. `generate_arm64_width_spec.py` emits
`KPROG_ARM64_WIDTH_ABSENT_CODE`, `KPROG_ARM64_WIDTH_EFFECTIVE_DEFAULT` and
`KPROG_ARM64_WIDTH_EFFECTIVE` alongside the width tables, and the generated Lean
`effective` resolves a decoded code to the code a body operates at.
`Arm64Width.lean` proves that resolution equal to an independent
`if c = 0 then 8 else c` (`arm64_effective_refines`), that the absent code names
no width (`arm64_absent_code_names_no_width`), that the fallback code is exactly
the 64-bit width's code (`arm64_default_code_is_w64`, pinned to the generated
decode so it cannot drift), and that the resolution is the identity on every real
width (`arm64_effective_identity_on_width`). The AArch64 dispatcher resolves the
width exactly once, at the `ARM64_SIM_L_EXEC` prologue, and every arm below it
operates at that effective width; that one site now routes through
`ARM64_SIM_L_EFFECTIVE_WIDTH`, whose kernel is the generated
`KPROG_ARM64_WIDTH_EFFECTIVE`. A generated-header oracle sweeps the full decoded
code domain (0..255) plus the width codes and the absent code's neighbours
against the independent model and the pinned width table (1,280 cases); a
sim-header route oracle drives fifteen width-reading dispatcher arms —
move/move-immediate/MOVK, ALU immediate/register, LSL/ROR shift, MVN, NEG,
compare-immediate, both CCMP forms, CSEL and the ADDS/SUBS writeback pair — at
each of the four widths and at the absent code, and checks that a raw code and
its effective code produce identical whole modeled state: all 31 general
registers with tags, the stack pointer, NZCV, LR, the SIMD quarters, and the
whole stack arena with its slot tags (337 cases). Because the resolution is
total on the width codes, driving the absent code must reproduce the 64-bit
behavior exactly; the oracle's regression tripwire is that raw-0 equals raw-8.

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

The AArch64 condition-mnemonic decode contract binds the `ARM64_COND_*` codes
the artifact encoder's `COND` mapping selects for its 17 condition mnemonics.
`Arm64CcDecode.lean` projects the generated table to
`(mnemonic, token, code)` triples and proves the projection equal to an
independent enumeration (`arm64_cc_decode_refines`), proves each code equal to
the shared condition contract's code for the condition name the mnemonic
selects (`arm64_cc_decode_code_matches_cond`), proves the reached conditions are
exactly the contract's fifteen (`arm64_cc_decode_conds_exact`), proves the
canonical mnemonics cover every condition once
(`arm64_cc_decode_canonical_covers`), and proves the aliases are exactly
`hs`/`lo` and land on the same codes as `cs`/`cc`
(`arm64_cc_decode_aliases_exact`, `arm64_cc_decode_alias_same_code`,
`arm64_cc_decode_alias_not_canonical`). The host cross-check includes
`generated/arm64_cc_decode.h` and drives the generated selector over every
mnemonic code, a dense out-of-range slice, the alias-equal-code facts, and a
per-condition reachability sweep. Thirty-two binding mutations---five spec
distortions, a condition-contract code shift, two generator-table changes,
seven generated-C header distortions, five generated-Lean changes, four
hand-refinement changes, two encoder-table changes, an encoder-import rename,
and two regenerated generator/render drifts---each change the oracle or the
refinement theorem, and a renamed encoder import and a drifted encoder table
value are caught by the encoder's live `COND`.

The AArch64 BPF helper-ident and compact-slot contract binds the 61 kernel
helper ids the AArch64 simulator recognizes, the helper name each one
denotes, and the per-program compact renumbering the artifact encoder
emits. `Arm64HelperIdents.lean` projects the generated table to `(id, name)`
pairs and proves the projection equal to an independent hand enumeration
(`helper_idents_refines`), the names pairwise distinct
(`helper_idents_names_nodup`), the ids strictly increasing
(`helper_idents_ids_strictly_increasing`), each forwarding macro's pinned
compact slot equal to the 1-based lexicographic rank, over the full
61-name table, of the helper it forwards to (`helper_delegate_ranks`), and
every name's own slot equal to its rank over the used names
(`helper_slot_ranks`)---deliberately not a restatement of the generated
match arms. The host cross-check includes `generated/arm64_helper_idents.h`
and drives the generated row selector over every kernel id, the out-of-range
default, the two counts, and the five forwarding slots against an
independent restatement. Twenty-nine binding mutations---five spec
distortions, two simulator-body macro add/remove and a retargeted
forwarding macro, two generator-table changes, five generated-C header
distortions, two generated-Lean changes, four hand-refinement changes,
three encoder-table changes, an encoder-import rename, two regenerated
generator/render drifts, and two genuine-equivalence rewrites---each of the
first twenty-seven changes the oracle, the generator check, or a refinement
theorem, while the last two are equivalences the proof correctly does not
flag.

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

The x86 ALU op-step result is likewise a generated contract: the sixteen
`if/else-if` arms of the simulator's `x86_alu_result` dispatcher
(`kprog/x86/x86_sim.h`) are `KPROG_X86_ALU_RESULT(LHS, RHS, OP, WIDTH,
UNSUPPORTED)` in `generated/x86_alu_result.h`, emitted by
`generate_x86_alu_result_spec.py` from `x86_alu_result_spec.json`, and the
dispatcher is a one-line wrapper running the caller's `(void)0` action at the
default arm. Each arm keeps the expression the hand dispatcher had — the
`KPROG_X86_ADC_RESULT`/`KPROG_X86_SBB_RESULT`/`KPROG_X86_NOT_RESULT` one-step
macros, the generated `kprog_x86_{shl,shr,sar,rol}_result` helpers at the
caller's width, and the bitwise/product formulas — and the generator
cross-checks the sixteen codes against the ALU-decode contract's table, that
the four shift arms delegate through the shift contract and the NOT arm
consumes no RHS, so the case labels track the `X86_ALU_*` constants
part-for-part. The generated Lean twin `GeneratedX86AluResult.result` mirrors
the arms over `GeneratedX86AluDecode`'s closed 16-constructor `Alu` tokens,
delegating to `GeneratedX86Adc`/`GeneratedX86SbbResult`/`GeneratedX86Not`/
`GeneratedX86ShiftResult`, and `X86AluResultSpec.lean` states the
independent `x86AluResultSpec` over `x86AluCodeSpec` literals and proves
`x86_alu_result_refines` arm-by-arm through the add/subtract/shift result
refinements the tokens already had, plus `x86_alu_result_code_dispatch`
(generated codes equal the independent literals) and
`x86_alu_result_code_in_range`. The host oracle drives the real macro and the
routed wrapper over 16 tokens × 6 lhs × 8 rhs × 4 widths from independent
per-op arithmetic identities (never the macro's own helpers), pins the
case-label table and its distinctness, and pins the default arm keeping the
left operand at the sixteen out-of-range operation bytes
(OK (6304 cases) rows in `make check`).

The route-oracle sibling includes `kprog/x86/x86_sim_local_bpf.h` and drives
the *real* `X86_SIM_L_EXEC_ALU_IMM` and `X86_SIM_L_EXEC_ALU_REG` bodies as
dispatched by the simulator, reproducing the bodies' input staging (the
register files planted with dst/src cell values and tags, the
`KPROG_X86_REG_LANE_AUX` dst/src lanes, the seeded incoming flags), comparing
the full register file with tags and the four flags against an independent
model written from the generated formulas over 16 op tokens × 5 width codes ×
2 destination-lane shifts × 2 flag seeds × 6 left values × 6 right values × 2
forms (23,040 routed pairs, 760,320 full-state checks plus 17 selector pins,
760,337 rows in `make check`).  An 87-mutation harness over the observed
surfaces --- 41 caught at the spec/generator stage, 30 by the Lean chain, 7 by
the host oracle, 5 by the route oracle (the dst/src lane reads dropping one
byte lane, the SBB/ADC handler arms dropping the live carry/borrow, a dropped
`SET_ALU_FLAGS` wiring, and a writeback ignoring the destination shift), and 4
genuine equivalences that survive --- closes the drift paths between the
generated result/flag formulas and the shipped arm bodies.

The routed memory-operand sibling extends the route oracle to the four MEM
bodies the dispatcher arms route for `X86_OP_ALU_MEM`/`_UNARY`/`_IMM`/`_REG`
(`X86_SIM_L_EXEC_ALU_MEM`, `..._UNARY`, `..._IMM`, `..._REG` in
`kprog/x86/x86_sim_local_bpf.h`). It drives the *real* bodies as dispatched,
reproducing their staged input (dst/src register values and tags, the
`KPROG_X86_REG_LANE_AUX` memory-descriptor lane, the seeded incoming flags,
the ELF-heap and stack frames planted at `X86_SIM_HEAP_ORIGIN` and
`X86_SIM_STACK_BYTES`), and compares the full register file with tags, the
four flags, and the addressed heap/stack bytes against an independent model
over 4 forms × 16 op tokens × 5 width codes × 2 incoming flag seeds ×
2 carry/borrow seeds × 6 immediate/displacement values = 61,440 routed
quadruples, 261,137 rows in `make check` (each row is one full check: state,
flags, and bytes per token). The model's little-endian byte ladders were
corrected during bring-up (the bit-width count was used where the byte count
belonged: `k < w` became `k < w / 8`... where a width code is a byte count
`k < w` stands), and the mutation harness gains a fifth detector
(`route_mem`: cc + run of the 0155 oracle) with the four MEM-body
anchored-rewrite mutants `simlocal_mem_unary_rhs_drift` (constant rhs 1 -> 2),
`simlocal_mem_imm_disp_drift` (upper-half displacement decode gets the whole
immediate), `simlocal_mem_rhs_mode_drift` (memory rhs lane 0 -> 1),
`simlocal_mem_reg_rhs_drift` (register rhs X86_SIM_L_READ_REG(SRC) ->
X86_RBX), and `simlocal_mem_stack_flip_drift` (form-1 store displacement
shifted by one byte) — totalling 92 mutations, 0 failures
(`gen=41 lean_chain=30 host=7 route=5 route_mem=5`), plus the four
genuine equivalences that survive.

The x86-64 SHIFTX/RORX routed sibling extends the route oracle to the four
inline SHIFTX/RORX arm bodies the dispatcher arms route for
`X86_OP_SHIFTX`/`_MEM` and `X86_OP_RORX`/`_MEM`
(`KPROG_X86_DISP_SHIFTX_HANDLED`, `..._SHIFTX_MEM_HANDLED`,
`..._RORX_HANDLED`, `..._RORX_MEM_HANDLED`; the bodies are inlined in
`X86_SIM_L_EXEC` in `kprog/x86/x86_sim_local_bpf.h` --- the last four x86
dispatcher arms without a sim-header route oracle). It drives the *real*
dispatcher forms with the planted staging (dst/src register values and tags,
the `KPROG_X86_REG_LANE_AUX` memory-descriptor lane with the COUNT_REG source
shift, the seeded incoming flags, the ELF-heap and stack frames planted at
`X86_SIM_HEAP_ORIGIN` and `X86_SIM_STACK_BYTES`), and compares the full
register file with tags, the four flags, and the addressed heap/stack bytes
against an independent model over 3 shift tokens × 5 width codes ×
2 incoming flag seeds × 2 index seeds × 6 displacements × 6 counts (the RORX
forms share the count lane with no token lane) = 5,760 routed cases, 195,841
rows in `make check`. The flags-preservation pin (neither body writes flags,
so every case fixes all four model flags equal to the seeded pre-flags) is
the sixth harness detector's target: `route_shiftx` (cc + run of the 0156
oracle) with the four SHIFTX/RORX-body anchored-rewrite mutants
`simlocal_shiftx_r_count_drift` (SHIFTX body register-operand count read
`X86_SIM_L_READ_REG(AUX)` -> `(SRC)`), `simlocal_shiftx_m_lane_drift`
(SHIFTX memory-index lane `X86_REG_AUX_GET_SRC_SHIFT(AUX)` ->
`X86_MEM_AUX_MEM_WIDTH(AUX)`, a different AUX channel),
`simlocal_rorx_r_count_drift` (register-operand rotate count `(IMM)` ->
`(IMM) + 1`), and `simlocal_rorx_m_count_drift` (memory-operand rotate count
`(__u8)(IMM)` -> `(__u8)(IMM) + 1`) --- totalling 96 mutations, 0 failures
(`gen=41 lean_chain=30 host=7 route=5 route_mem=5 route_shiftx=4`), plus the
same four genuine equivalences that survive.

The x86-64 MOVX register-source routed sibling completes the route-oracle
family: `test_x86_movx_route_host.c` drives the inline
`KPROG_X86_MOVX_REG_HANDLED` arm of `X86_SIM_L_EXEC` (the shared
`X86_OP_MOVZX_REG` (0x20) / `X86_OP_MOVSX_REG` (0x21) body) and compares the
register file with tags and the four flags against an independent model over
2 opcodes × 5 width codes × 6 AUX source-width codes (the absent code 0, the
four real width codes, and the out-of-domain byte 33 as the boundary probe
the plain masks fall through on) × 6 source values × 2 incoming flag seeds =
720 routed cases, 23,761 rows in `make check`. The model restates the
extension shape on the raw opcode (sign at 0x21, zero everywhere else), the
absent-code source-width fallback to the FLAGS-resolved effective width, and
the width-local partial-register writeback exactly as the generated
`x86_movx_shape.h` / `x86_width.h` contracts define them, without the
macro's own helpers. The flags-preservation pin is the seventh harness
detector's target: `route_movx` (cc + run of the 0157 oracle) with the
four MOVX-body anchored-rewrite mutants `simlocal_movx_shape_drift`
(sign/zero shape condition `==` -> `!=`, sign↔zero swap),
`simlocal_movx_src_width_drift` (decoded AUX source-width lane
`(AUX)` -> `0U`, so a non-absent AUX decodes as the absent code),
`simlocal_movx_src_lane_drift` (source-lane read
`X86_SIM_L_READ_REG(SRC)` -> `(DST)`), and `simlocal_movx_wb_width_drift`
(writeback width `__x86_l_width` -> `__x86_l_src_width`) --- totalling 100
mutations, 0 failures (`gen=41 lean_chain=30 host=7 route=5 route_mem=5
route_shiftx=4 route_movx=4`), plus the same four genuine equivalences that
survive.

The x86 condition-mnemonic decode contract binds the `X86_CC_*` codes the
artifact encoder's `CC_AUX` mapping selects for its 36 `jcc`/`cmovcc`/`setcc`
mnemonics. `X86CcDecode.lean` projects the generated table to
`(mnemonic, token, code)` triples and proves the projection equal to an
independent enumeration (`x86_cc_decode_refines`), proves each code equal to
the shared condition contract's code for the same suffix name
(`x86_cc_decode_code_matches_cond`), proves the reached suffixes are exactly the
non-parity names (`x86_cc_decode_suffixes_exact`), and proves every mnemonic is
its family prefix plus its suffix (`x86_cc_decode_mnemonic_composition`). The
host cross-check includes `generated/x86_cond.h` and
`generated/x86_cc_decode.h` and drives the generated selector over every
suffix code, an out-of-range slice, each mnemonic's hand-derived suffix, and the
parity absence. Thirty binding mutations---six spec distortions, a
condition-contract code shift, two generator-table changes, six generated-C
header distortions, four generated-Lean changes, four hand-refinement changes,
two encoder-table changes, an encoder-import rename, and two regenerated
generator/render drifts---each change the oracle or the refinement theorem, and
a renamed encoder import and a drifted encoder table value are caught by the
encoder's live `CC_AUX`.

The x86-64 multiply op-step routed sibling closes the two multiply arms: `test_x86_imul_route_host.c` drives the inline `X86_OP_IMUL_IMM` (0x38) / `X86_OP_IMUL_MEM_IMM` (0x41) bodies of `X86_SIM_L_EXEC` and compares the register file with tags, the four flags, and the heap image against an independent model over 5 width codes × 8 left values × 6 immediate artifacts × 2 flag seeds for the flagged form plus 5 width codes × 5 AUX memory-width codes × 8 heap fill patterns × 6 immediate artifacts × 3 addressing modes × 2 flag seeds for the memory form = 7,680 routed cases, 261,121 rows in `make check`. The model restates the whole-immediate right operand at the FLAGS-resolved width, the re-resolved store immediate, the effective displacement `(s32)((u64)(s32)(imm >> 32) >> 32)` (the routed body passes the store-half displacement through the whole-immediate slot of the addressed-read body, which re-extracts it), the raw-left vs widened-left flag split, and the generated `KPROG_X86_SET_IMUL_FLAGS` division funnel. The flags-preservation pin is the eighth harness detector's target: `route_imul` (cc + run of the 0158 oracle) with the four IMUL-body anchored-rewrite mutants `simlocal_imul_imm_lhs_drift` (register-form left read `SRC` -> `DST`), `simlocal_imul_imm_rhs_width_drift` (whole-immediate sign-extension width `__x86_l_width` -> `X86_WIDTH_8`), `simlocal_imul_mem_lhs_raw_drift` (memory-product left operand un-signed-extended), and `simlocal_imul_mem_flags_raw_mw_drift` (flag left operand signed-extended instead of raw) --- totalling 104 mutations, 0 failures (`gen=41 lean_chain=30 host=7 route=5 route_mem=5 route_shiftx=4 route_movx=4 route_imul=4`), plus the same four genuine equivalences that survive.

The x86-64 LEA routed sibling extends the route-oracle family to the address-forming arm: `test_x86_lea_route_host.c` drives the inline `X86_OP_LEA` (0x09) arm body of `X86_SIM_L_EXEC` and compares the register file with tags, the four flags, the heap image, and the stack-arena bytes against an independent model over 3 source roots (NONE, the stack pointer, a general mapped-pointer register) × 5 width codes (the absent code plus the four real codes) × 4 addressing modes (no index, the RODATA gate, an index at scale 1, an index at scale 8) × 4 immediate artifacts × 2 destination lanes × 2 flag seeds = 960 routed cases, each comparing 16 registers + 16 tags + the heap and stack images + the flag row (34 rows) plus the one selector row, 32,641 rows in `make check`. The model restates the sign-extended immediate plus the present-index scaled lane sum through the machine-checked `X86_SIM_L_MEM_OFFSET` chain, the four exits (the `X86_LEA_AUX_RODATA` fast path writing the RAW immediate as a scalar, the 64-bit stack-pointer arena rebind stamping `X86_SIM_TAG_STACK`, the 64-bit general pointer add carrying the source tag, and the narrower-width scalarize through the width-local partial-register write), the NONE-source null-pointer base contribution, and the write-free contract: no flag byte and no memory byte change, so the planted heap and stack images come back unchanged. The flags-preservation pin is the ninth harness detector's target: `route_lea` (cc + run of the 0159 oracle) with the four LEA-body anchored-rewrite mutants `simlocal_lea_width_drift` (the width line plus its following offset line replaced with a literal `1U` width --- a two-line anchor because the single width line recurs in fifteen exec macros), `simlocal_lea_offset_index_drift` (the offset AUX register byte `(AUX)` -> `0U`, forcing the no-index decode), `simlocal_lea_rodata_gate_drift` (the RODATA gate `X86_LEA_AUX_RODATA` -> `0U`, making every AUX word take the raw-immediate exit), and `simlocal_lea_stack_src_drift` (the stack-pointer test `(SRC) == X86_RSP` -> `(SRC) == 0U`, spilling the general-register form into the arena arm) --- totalling 108 mutations, 0 failures (`gen=41 lean_chain=30 host=7 route=5 route_mem=5 route_shiftx=4 route_movx=4 route_imul=4 route_lea=4`), plus the same four genuine equivalences that survive.

The x86-64 MOV routed sibling extends the route-oracle family to the two move
opcodes: `test_x86_mov_route_host.c` drives the inline `X86_OP_MOV_IMM` (0x01)
and `X86_OP_MOV_REG` (0x02) singleton arm bodies of `X86_SIM_L_EXEC` (and their
`X86_SIM_L_EXEC_MOV_IMM_AUX` / `X86_SIM_L_EXEC_MOV_REG_AUX` wrappers) and
compares the register file with tags, the four flags, and the stack-arena image
against an independent model over 4 destinations × 5 width codes × 4 immediate
artifacts × 2 AUX lane words for the immediate arm plus 6 source/destination
pairs (including `rsp` as destination, as source, and as both) × 5 width codes ×
4 source values × 2 destination values × 2 AUX lane words for the register arm
= 640 routed cases, each comparing 16 registers + 16 tags + the flag row + the
stack image (34 rows) plus the four selector rows, 21,764 rows in `make check`.
The model restates the zero-extended immediate at the FLAGS-resolved width, the
whole-cell source copy with stack-pointer rebind through the 32-bit window, the
map/pointer-tag provenance copy, and the narrow partial reads and writes at the
AUX lane shifts (scalarizing the tag), and the 112-mutation harness adds four
MOV-body mutants (the immediate lane shift, the width decode, the stack tag,
and the narrow source shift) to the Step 0159 count, totalling 112 mutations,
0 failures (`gen=41 lean_chain=30 host=7 route=5 route_mem=5 route_shiftx=4
route_movx=4 route_imul=4 route_lea=4 route_mov=4`), with the same four
genuine equivalences surviving.

The x86-64 BSWAP routed sibling extends the route-oracle family to the
byte-reversing arm: `test_x86_bswap_route_host.c` drives the inline
`X86_OP_BSWAP` (0x17) arm body of `X86_SIM_L_EXEC` -- the one dispatcher arm
whose value computation stays inline in the chain -- and compares the register
file with tags, the four flags, and the stack-arena image against an
independent model over 4 destinations × 5 width codes (the absent code plus
the four real codes) × 5 destination values (a byte-lane-swapping showcase,
the mapped-pointer base a body must not dereference, two byte probes, and the
pattern scalar) × 2 AUX words (the plain zero word a real dispatcher route
hands the singleton and the high-byte lane word the arm must ignore) = 200
routed cases, each comparing 16 registers + 16 tags + the flag row + the stack
image (34 rows) plus the two selector rows, 6,802 rows in `make check`. The
model restates the whole-cell 64-bit read, the byte reversal at the
FLAGS-resolved width with the bytes above it cleared, and the width-local
writeback (byte/word/dword/qword) scalarizing the narrowed tag, and the
116-mutation harness adds four BSWAP-body mutants (the bswap width forced to
the byte code at the call site, the whole-cell read taken from the wrong
register, the reversal dropped to the identity, the writeback width forced to
the full cell) to the Step 0160 count, totalling 116 mutations, 0 failures
(`gen=41 lean_chain=30 host=7 route=5 route_mem=5 route_shiftx=4 route_movx=4
route_imul=4 route_lea=4 route_mov=4 route_bswap=4`), with the same four
genuine equivalences surviving.

The x86-64 PUSH/POP routed sibling extends the route-oracle family to the
stack-transfer arm: `test_x86_pushpop_route_host.c` drives the shared
`X86_SIM_L_EXEC_PUSH_POP_STEP` body of `x86_sim_local_bpf.h` -- the
composition both one-line opcode wrappers (`X86_SIM_L_EXEC_PUSH`,
`X86_SIM_L_EXEC_POP`) instantiate and the two `X86_SIM_L_EXEC` dispatcher
arms route -- and compares the whole register file with tags, the four
flags, and the stack-arena image against an independent model over both
opcodes × both drive modes (the direct wrapper call and the dispatcher arm)
× 5 FLAGS codes (the absent code plus the four real codes) × 5 stack
pointers × 3 sources × 3 destinations = 900 routed transfer steps, each
comparing the stack pointer, 16 registers, 16 tags, the whole stack frame,
and the flag row (35 comparison points) plus the four selector rows,
31,504 comparison points in `make check`. The model restates the
pre-decrement store of the whole source register at the hardcoded 64-bit
width, the post-increment load-and-writeback of the decoded partial width,
and the flag-free contract (neither body writes a flag), and the 46-mutation
harness over the six observed surfaces catches 42 changes against the same
four detectors (19 at the specification/generator stage, 9 by the Lean
chain, 3 by the host oracle, 11 by the route oracle) plus four genuine
equivalences that survive. Five spec rows (both opcode codes, the stack
step, PUSH as postIncrement, POP as hardcoded64), six generator rows
(the op-code table, both direction/width tables, the phase table, the
stack step, the collapse check dropped), eleven generated-C rows (both
opcodes' static asserts, the four table defines, the absent width, the
step literal; the direction flux absorbed by the selector comparison),
five generated-Lean rows (both tables, the b16 row, the absent resolve,
the stack step), five hand-Lean rows (both selector definitions, the step
amount, the fact rows) and thirteen simulator-header body rows (the
direction test dropped, the width-source test re-anchored, the
absent-FLAGS test dropped and inverted, the step literal doubled, both
pointer steps dropped to identity writes, the PUSH source read from
`DST`, the POP writeback widened to a whole-cell store, the PUSH store
narrowed to 8 bits, and the POP read shifted one byte); 11 of the 13
header rows catch, and the reintroduced hand stack-write guard (Step 0120
proved the two guards equal) plus the unchanged-step restatement are
genuine route-equivalences. The run repaints whitespace, adds a hand-Lean
comment, resolves the generator root equivalently, and keeps that guard
(the four genuine equivalences that survive by design). The tally is 46
mutations, 0 failures (`gen=19 lean_chain=9 host=3 route=11`,
`ALL AS EXPECTED`).

The x86-64 XCHG routed sibling extends the route-oracle family to the
width-keyed arm-selection body: `test_x86_xchg_route_host.c` drives the
`X86_OP_XCHG` dispatcher arm of `X86_SIM_L_EXEC` in
`x86_sim_local_bpf.h` -- the arm that selects its body through the
generated `KPROG_X86_XCHG_ARM` contract (the pointer-swap arm at the
full 64-bit code, the subword-value-swap arm at every other code) --
and compares the whole register file with tags and the four flags
against an independent model over 256 operand pairs x 5 width codes
(the absent code plus the four real codes) = 1,280 routed swaps, each
comparing the 16 cells (value, tag, and no third-cell movement) and
the flag row (49 comparison points) plus the five selector rows,
62,725 comparison points in `make check`. The model restates the
whole-cell exchange at 64 bits, the low-lane-window exchange below
(upper bytes kept at 8 and 16 bits, zero-extension at 32), and the
scalarization of both cells' tags, and the 69-mutation harness over
the six observed surfaces catches 65 changes against the same four
detectors (38 at the specification/generator stage, 14 by the Lean
chain, 13 by the route oracle) plus four genuine equivalences that
survive. Eleven spec rows (the selector spelling, the opcode, the
full-width code with its define, both arm names, both effects, both
width classes, both arm defines, the pointer full-width flag, and the
width-code width), eleven generator rows (both arms-table rows, the
width and opcode constants, the opcode define name, the full-width
code, the arm-selector string, the pointer-read macro name, the
subword-write macro name, the armOf if-expression; the paired
width-change with regeneration stays `--check`-green but is caught by
the routed grid, and the pointer-read/subword-write macro-name drops
are routed-grid catches too), twelve generated-C rows (the count,
full-width, and both-arm defines, all six static asserts, and the two
selector-macro body lines), fourteen generated-Lean rows (the count,
width-code, opcode, and full-width defs, both tables, both arms'
code/effect/class rows, the armOf if-expression, and the armOfCode
zip-lookup; the constant and armOf spellings at the generator stage,
the arm pattern rows and the zip-lookup by the Lean chain), seven
hand-Lean rows (the arm-spec, name-table, pointer and subword body
definitions, the over-widths table, and three theorem statements whose
retargeted goals break the thin `exact` proofs), and ten
simulator-header body rows (the generated-header include dropped, the
arm selector unhooked from the generated macro, both pointer-arm reads
drifted to neighbouring cells, both pointer-arm writes echoed back to
their own cell, both subword reads swapped across the two operands,
and both subword writes hardcoded to the 64-bit width); all ten
header rows catch. The run parenthesizes a pointer-macro argument,
repaints selector-line whitespace (the generator's arm-region check
collapses whitespace), adds a hand-Lean comment, and resolves the
generator root equivalently (the four genuine equivalences that
survive by design); the 260-case generated-header host oracle holds
the four-detector baseline gate. The x86-64 `DIV` case-dispatch sibling extends the routed dispatcher-arm
body coverage to the four quotient/remainder arms Step 0115 generated (the
byte case that packs the quotient and remainder into one 16-bit partial
write, the word and dword cases that divide the high:low pair and write both
halves at the access width, and the qword default that alone gates the split
on the high-half dividend being zero). The route oracle drives the real
`X86_SIM_L_EXEC` body against an independent quotient/remainder model over
2 `x` 5 width codes (the absent code plus the four real codes) `x` 7
dividends `x` 3 high halves `x` 7 divisors = 1,470 routed divides, each
comparing the 16 cells (value, tag, and no third-cell movement) and the
flag row (49 comparison points) plus the five selector rows, 48,515
comparison points in `make check`. The 90-mutation harness over the six
observed surfaces catches 86 changes against the same four detectors (41 at
the specification/generator stage, 27 by the Lean chain, 18 by the route
oracle) plus four genuine equivalences that survive. Thirteen spec rows
(the selector spelling, the opcode, the opcode define name, the width-code
width, both arm names, the byte arm define, the qword high half-gate flag,
the byte write count, the byte high-half name, both effects with the byte
one named twice, and the full width class), thirteen generator rows
(every `_ARMS` tuple mutated in place --- the byte write count, the word
write count, the dword high-half register, the qword width code --- plus
the width and opcode constants, the opcode define name, the arm-selector
string, and the width-write/high-read macro names; the latter two pair
with matching sim-header drift and are caught by the routed grid because
the generated macros live in whitespace-collapsed arm regions), fourteen
generated-C rows (the count and both boundary arm defines, all seven
static asserts, and the four selector-macro comparison/branch lines), and
sixteen generated-Lean rows (the count, opcode, and width-code defs, both
tables, the full width-code/write-count/high-half/gate ladders, the named
effect and class rows, the armOf if-expression ladder, and the armOfCode
zip-lookup) are caught at the generator stage or by the Lean chain; the
seventeen hand-Lean rows mutate the arm-spec and name-table definitions,
the over-widths table, the bytecode-quirk theorems, and eleven statement
bodies of thin-proof theorems (roundtrip, opcode, count, ladder-total,
dispatch, nondefault-gated, width-codes, gated-ladder, byte-upper,
byte-spec, wide-def, wide-both, write-count-effect, beyond-none); all
seventeen catch because mutating a goal breaks the exact-refine proof even
when the name is unused. The twelve simulator-header body rows cover the
three operand reads drifted to neighbouring cells, the byte pack-order
swap, write-target, and write-width drifts, the word pair write-target
drift, the dword dividend window and divisor truncation drifts and the
dword write-width drift, the qword gate flip and tautology-gate drop, and
the qword quotient/remainder overflow-default drifts; all twelve catch.
The run parenthesizes a register-file argument, repaints default-arm
whitespace the generator's arm-region check collapses, adds a hand-Lean
comment, and resolves the generator root equivalently (the four genuine
equivalences that survive by design); the 260-case generated-header host
oracle holds the four-detector baseline gate. The tally is 90 mutations,
0 failures (`gen=41 lean_chain=27 route=18`, `ALL AS EXPECTED`).

The AArch64 `CNT`/`UADDLV` byte-lane reduction contract family gets sibling
mutation coverage. The family binds the two reduction opcodes whose handlers
load the generated `KPROG_ARM64_REDUCTION_VALUE` statement expression: the
`Cnt` arm (`ARM64_OP_CNT` = 36 = `0x24`) popcounts each of the eight source
bytes into its own byte lane, and the `UADDLV` arm (`ARM64_OP_UADDLV` = 37 =
`0x25`) sums the eight byte lanes into the low result byte (the arithmetic
cap is 2040, the 8-byte all-set lane ceiling). The suspect family is the six
files that carry the reduction contract: the shared spec
(`arm64_reduction_spec.json`), the generator
(`generate_arm64_reduction_spec.py`), the generated C
(`generated/arm64_reduction.h`), the generated Lean
(`KProgFormal/GeneratedArm64Reduction.lean`), the hand refinement
(`KProgFormal/Arm64Reduction.lean`), and the sim-header opcode source the
generator re-reads (`kprog/arm64/arm64_sim.h`). The 61-mutation harness
runs three detectors - generator `--check`, the Lean chain
(`lake build` + `lean`), and the host 20017-case generated-header oracle -
with no route detector because the family has no route test: the wrapper
body `ARM64_SIM_L_REDUCTION_VALUE` is reached only through the host test.
The 61 rows catch 57 changes (`gen=27 lean_chain=13 host=13`) and four
genuine equivalences survive by design: the generator comment, the
sim-header define spacing, a hand-Lean comment, and the generator `ROOT`
spelling. Two lookahead rows mutate the `ARM64_OP_{CNT,UADDLV}` sim-header
define lines themselves and are caught by `gen` (the generator re-reads the
sim header and fails with an opcode-drift message); the rest cover the
spec rows (names, both opcode codes, the operation tag, the order), the
generator rows (the injected body fragments, both per-opcode tables, the
torsor codes/mnemonics), the generated-C rows (both opcode static asserts,
the coverage asserts, the two case labels, the lane masks/shifts, the
switch/default runes), the generated-Lean rows (codes, mnemonics, both arm
bodies, the popcount ladder), and the hand-Lean rows (the spec statement,
the byte-popcount cells, both arm bodies, the refinement goal, the range
and bound facts, and the four example oracle rows). The tally is 61 mutations, 0 failures (`gen=27 lean_chain=13 host=13`, `ALL AS EXPECTED`).

The AArch64 `MVN`/`NEG` unary value contract family gets sibling mutation
coverage. The family binds the two unary opcodes whose handlers load the
generated `KPROG_ARM64_UNARY_VALUE` statement expression: the `MVN` arm
(`ARM64_OP_MVN` = 15 = `0x0f`) writes the destination-width-narrowed bitwise
complement of the source, and the `NEG` arm (`ARM64_OP_NEG` = 16 = `0x10`)
writes the destination-width-narrowed two's-complement negation. The suspect
family is the six files that carry the unary contract: the shared spec
(`arm64_unary_spec.json`), the generator
(`generate_arm64_unary_spec.py`), the generated C
(`generated/arm64_unary.h`), the generated Lean
(`KProgFormal/GeneratedArm64Unary.lean`), the hand refinement
(`KProgFormal/Arm64Unary.lean`), and the sim-header opcode source the
generator re-reads (`kprog/arm64/arm64_sim.h`). The 59-mutation harness
runs three detectors - generator `--check`, the Lean chain (`lake build` +
`lean`), and the host 40081-case generated-header oracle - with no route
detector because the family has no route test: the wrapper body
`ARM64_SIM_L_UNARY_VALUE` is reached only through the host test. The 59 rows
catch 55 changes (`gen=27 lean_chain=15 host=13`) and four genuine
equivalences survive by design: the generator comment, a hand-Lean comment,
the generator `ROOT` spelling, and the spec-whitespace repaint. One
retarget: `generated_c_result_seed_drift` moved from the host oracle to the
generator comparator, because seeding the statement expression's result slot
is absorbed by every arm's unconditional assign (real arms and the
unsupported arm alike) - a no-op the host test cannot observe - while the
byte-compared artifact catches the repaint. Two lookahead rows mutate the
`ARM64_OP_{MVN,NEG}` sim-header define lines themselves and are caught by
`gen` (the generator re-reads the sim header and fails with an opcode-drift
message); the rest cover the spec rows (names, both opcode codes, the
operation tag, the order), the generator rows (the injected body fragments
and both Lean arm bodies), the generated-C rows (both opcode static asserts,
the coverage assert, the handled-arm disjuncts, both case labels, both arm
bodies, the width-mask call, the switch/default runes, and both seed lines),
the generated-Lean rows (the code-mnemonic pair, both arm bodies, and the
flag row), and the hand-Lean rows (the independent spec arms, the refinement
goal, the returned-constant rows, the self-inverse and cancellation facts,
the word bound, and the three example oracle rows). The tally is 59
mutations, 0 failures (`gen=27 lean_chain=15 host=13`, `ALL AS EXPECTED`).

The AArch64 extract/reverse/extend value contract family (`ARM64_OP_EXTR`
= 17 = `0x11`, `ARM64_OP_REV` = 19 = `0x13`, `ARM64_OP_REV16` = 20 = `0x14`,
`ARM64_OP_SXTH` = 21 = `0x15`, `ARM64_OP_SXTW` = 47 = `0x2f`, and
`ARM64_OP_SXTB` = 60 = `0x3c`) gets the same mutation build-out in
`build/mut_arm64_extrev.py` (untracked): 132 mutants across the shared spec,
the generator, the flags spec (one rejected REV flag-family import), the
generated C and Lean tables, the hand refinement, and the sim-header
opcode source, with the sim header restored byte-for-byte after every
mutant. The three detectors are unchanged (generator `--check`, Lean
chain, host 120145-case oracle). 124 mutants catch (`gen=62
lean_chain=30 host=32`) and 8 survive: the four genuine equivalences by
design (the generator comment, a hand-Lean comment, the generator `ROOT`
spelling, and the spec-whitespace repaint) plus four detector-invisible
rows kept as survivors: the generated-C `REV32` result seed, absorbed by
every arm's unconditional assign; both generated-Lean mnemonic rows,
because no chain consumer reads `mnemonic` in this family; and one
hand-Lean case-split row, because the mutated `by_cases` mask still proves
the unchanged theorem statement. Lean blind spots found during shakedown:
the `value` match arms for the `SXT` ops have no Lean consumer (the family
refinement opens the `signExtend` function directly), so the `.sxth` arm
row was retargeted to a compile-error mutant; and def-line comment
repaints are not Lean-visible, so the five hand spec-def rows and the
two generator-comment regeneration rows were retargeted to real body
mutations (dropped mask bit, byte rotation, sign-mask bit).

The AArch64 condition-gated-negation and complemented-OR pair (`ARM64_OP_CNEG` = 65 = `0x41` and `ARM64_OP_ORN_REG` = 53 = `0x35`) gets the same
mutation build-out in `build/mut_arm64_cneg_orn.py` (untracked), a
combined two-family harness over ten contract files: 78 mutants across
the two shared specs, the two generators, the generated C and Lean
tables, the hand refinements, and the two sim-header opcode sources,
sim header restored byte-for-byte after every mutant; the gen detector
runs both generator `--check` rows, the Lean chain both family pairs,
and the host compiles/runs both oracles (40,097 + 40,401 cases). 70 catch
(`gen=26 lean_chain=25 host=19`) and 8 survive: the three genuine
equivalences by design (the generator `ROOT` spelling, a hand-Lean
comment, and the spec-whitespace repaint) plus five detector-invisible
rows kept as survivors: the generated-C result seed (absorbed by the
unconditional arm assign), both generated-Lean mnemonic rows (no chain
consumer reads `mnemonic` in these families), and both hand-Lean
flags-unchanged proof repaints (the `rfl` rewrites still prove the
unchanged theorem statement).

The AArch64 shift-value family (`ARM64_SHIFT_LSL`/`LSR`/`ASR`/`ROR`, codes
0..3) gets the same mutation build-out in `build/mut_arm64_shift.py`
(untracked), a single-family harness over five contract files: the shared
spec (`arm64_shift_spec.json`, 4 rows), its generator, the generated C
table (`generated/arm64_shift.h`, the static asserts, the handled/unsupported
gate, the k-mask ternary, the width-mask and the four per-op arms), the
generated Lean module (`GeneratedArm64Shift`), and the hand Lean refinement
(`Arm64Shift.lean`), with the same three detectors. 78 mutants catch
(`gen=31 lean_chain=23 host=24`) and 7 survive: the three genuine equivalences
by design (the generator `ROOT` spelling, a hand-Lean comment, and the
spec-whitespace repaint) plus four detector-invisible rows kept as survivors:
the generated-C result seed (every arm assigns before the switch's only
consumer reads it), the generated-Lean LSL inner-narrow drop and the hand-Lean
LSL pre-mask drop (the width-mask of the shift is subsumed by the result's own
width mask, what `bv_decide` proves), and the rename of the consumers-free
`arm64_shift_amount_masked` theorem (grep-verified: no file imports it). One
shakedown retarget: the generator's `ctors` f-string is computed but never
interpolated in the shift template (the Lean inductive comes from the decode
generator), so the ctor-spelling row was retargeted to the `[0, 1, 2, 3]`
codes-range cross-check.

The AArch64 bitfield-composition family (`ARM64_BITFIELD_UBFX`/`SBFX`/`UBFIZ`/
`BFXIL`/`BFI`, codes 0..4) gets the same mutation build-out in
`build/mut_arm64_bitfield.py` (untracked), a single-family harness over the
same five contract files --- the shared spec (`arm64_bitfield_spec.json`, 5
rows), its generator, the generated C table (`generated/arm64_bitfield.h`,
the code asserts, the handled/unsupported gate, the coverage asserts, the
switch, the guard ternaries and the per-op arms), the generated Lean module
(`GeneratedArm64Bitfield`), and the hand Lean refinement (`Arm64Bitfield.lean`)
--- with the same three detectors and no regen or sim-header stage (the 5-row
scalar spec bakes both codes and arms into the generated files directly; the
sim header only adds the zero-extended-LSB/BITS wrapper plus the
`ARM64_SIM_L_UNSUPPORTED_OPCODE` call, and the wrapper routes by
`ARM64_OP_BITFIELD` dispatch like every other value family, so there is no
route detector). 94 mutants catch (`gen=33 lean_chain=30 host=31`) and 10
survive: the two live-probed equivalences (the unused-default-label rename
`defaultX:`, only a `-Wunused-label` warning because the never-executed default
arm falls out of the sweep, and the hand-Lean `hb`/`h64` packet-hypothesis
repaints since the refines theorem statement is unchanged) join the
seven-documented-redundant survivors (the dead result-seed literal, the
spec-name regex, the conditional-subsumption guard repaints, the
triple-concat SASS-layout comment, the unreachable-default UNSUPPORTED-arm
name, the reach-only proof-support lemma, and the duplicate-case recast).
Doc-shake findings: the UBFX coverage assert (`HANDLED(ARM64_BITFIELD_UBFX)`)
amounts to reasserting a `_Static_assert`-already-pinned code, and the default
`break;`-repaint row (the fourth proven-redundant one) was replaced by a
duplicate-case-4U label row the compiler rejects outright.

The shared AArch64 ALU op-step result contract (the six operations
`add`/`sub`/`and`/`bic`/`eor`/`orr`, codes 0..5, the `KPROG_ALU64_RESULT`
switch macro inlining into the simulator's `ARM64_SIM_L_EXEC_ALU`) gets the
same mutation build-out in `build/mut_arm64_alu_result.py` (untracked), a
single-family harness over the same five contract files --- the shared spec
(`arm64_alu_result_spec.json`, 6 rows), its generator, the generated C
switch macro (`generated/arm64_alu_result.h`, the per-op case arms, the
shared result seed, the switch/default/unsupported tail, and the result
expression), the generated Lean module (`GeneratedArm64AluResult`), and the
hand Lean refinement (`Arm64AluResult.lean`, including the independent
`lhs + ~~~rhs + 1` subtraction form, the flag-composition rewrites, and the
canonical examples) --- with the same three detectors and no regen or
sim-header stage (the simulator header only `#include`s the generated
header and inline-expands `KPROG_ALU64_RESULT`, so a generated-header drift
is observable only through the host oracle, which reaches the macro through
the same include). 47 mutants catch (`gen=16 lean_chain=20 host=11`) and 4
survive: the three documented equivalences (the generator `ROOT` spelling
repaint, the generated-Lean doc-comment typo, and the hand-Lean EOR
counterexample restatement whose theorem still proves) plus the
dead-result-seed survivor (every switch arm assigns
`__kprog_alu64_res` before the macro's single tail expression reads it).
No shakedown retargets were needed: all draft anchors were caught on the
first full run.


The AArch64 ADRP relocation-tag contract (the two page-address opcodes
`ARM64_OP_ADRP_GOT` = 38 = `0x26` and `ARM64_OP_ADRP_RODATA` = 39 = `0x27`,
the `KPROG_ARM64_ADRP_TAG` switch macro inlining into the simulator's
`ARM64_SIM_L_EXEC` ADRP arm) gets the same mutation build-out in
`build/mut_arm64_adrp.py` (untracked), a single-family harness over the same
five contract files --- the shared spec (`arm64_adrp_spec.json`, 2 rows), its
generator, the generated C switch macro (`generated/arm64_adrp.h`, the two
case arms, the tag seed, the switch/default/unsupported tail, and the `GOT`
handled disjunct), the generated Lean module (`GeneratedArm64Adrp`), and the
hand Lean refinement (`Arm64Adrp.lean`, including the independent
Boolean-indexed `7 + if got-kind then 0 else 1` selection form) --- with the
same three detectors and no regen or sim-header stage (there is no ADRP route
test; the simulator header only `#include`s the generated header and
inline-expands `KPROG_ARM64_ADRP_TAG`, so a generated-header drift is
observable only through the host oracle, whose exhaustive 256-byte opcode
fork sweep reaches the macro through the same include). 45 mutants catch
(`gen=26 lean_chain=11 host=8`) and 5 survive: the three documented
equivalences (the generator `ROOT` spelling repaint, the spec-whitespace
repaint, and the generated-Lean `.rodata` `isGot`-false arm the independent
classification already pins) plus two detector-invisible rows kept as
survivors: the generated-C tag seed (every case arm assigns
`__kprog_a64_adrp_tag` before the macro's single tail expression reads it)
and the generated-Lean `.got` mnemonic row (no chain consumer reads
`mnemonic` in this family). One shakedown retarget was needed: the first
draft's goal-side flip of `arm64_adrp_tag_refines` survives because
`Eq` is symmetric under `rfl`, so the row was retargeted to an
independent-`isGot`-index drift that the `cases op <;> rfl` proof no longer
closes.

The AArch64 condition-code contract binds the fifteen-member flag-decision
family `eq`/`ne`/`cs`/`cc`/`mi`/`pl`/`vs`/`vc`/`hi`/`ls`/`ge`/`lt`/`gt`/`le`/
`al` (codes 0..14, the fourteen `ARM64_COND_*` numbers plus the
always-true `al`, the `KPROG_ARM64_EVAL_COND` chained-ternary macro) that
the simulator's `ARM64_SIM_L_EVAL_COND` wrapper threads the live
`__a64_n`/`__a64_z`/`__a64_c`/`__a64_v` flag variables into and that is
inlined at those wrapper's seven call sites (`jcc`, the conditional-select
and extract conditions, the conditional-branch and compare-and-branch
next-PC predicates). It gets the same mutation build-out in
`build/mut_arm64_cond.py` (untracked), a single-family harness over the
same five contract files --- the shared spec (`arm64_cond_spec.json`, 15
rows), its generator (`generate_arm64_cond_spec.py`), the generated C
ternary chain (`generated/arm64_cond.h`, the fifteen static asserts, the
chained per-condition ternary arms, and the `UNSUPPORTED; 0` tail), the
generated Lean module (`GeneratedArm64Cond`, the inductive, the codes, and
the per-condition `eval` arms), and the hand Lean refinement
(`Arm64Cond.lean`, including the `Arm64Flags` record, the reindexed
`generatedArm64Cond`, the soundness/range/dispatch/distinctness theorems,
and the AL/complements examples) --- with the same three detectors and no
regen or sim-header stage (the simulator header re-declares the fifteen
`ARM64_COND_*` numbers and the wrapper only threads the live flag
variables, so a generated-header drift is observable only through the host
oracle, whose 4 NZCV-flag-only states crossed with the 15 codes --- 240
truth-table cases, each condition's full table checked --- plus the
forked 241 out-of-range code sweep reaches the macro through the same
include). 68 mutants catch (`gen=38 lean_chain=22 host=9`) and 1 survives:
the generator `ROOT` spelling repaint, a documented equivalence by design.
Two shakedown retargets were needed: a weakened generator
canonicalization gate (`or` -> `and` between the name and code checks)
approves a canonical spec silently --- the row was retargeted to also
drift one spec row on both fields, forcing the weakened gate to fire ---
and the first draft's soundness-tactic repaint (`rfl` -> `trivial`)
survives because the post-`cases` goals are propositionally trivial: the
row was retargeted to a `decide` repaint the free flag variables reject
(`decide` cannot close a goal over variables, the error points at the
`al` case).


The AArch64 conditional-select pointer-path contract decides which register
write carries the selected source register's provenance tag across the
eight-member `csel`/`cinc`/`cset`/`cinv`/`csinv`/`csinc`/`csetm`/`csneg`
family: only the plain `csel` at doubleword width writes through
`ARM64_SIM_L_WRITE_REG_PTR_TAG`; every other member and every sub-word width
computes a fresh scalar written through the tag-dropping width-narrowed
`ARM64_SIM_L_WRITE_REG_WIDTH`. The simulator's `ARM64_SIM_L_CSEL` wrapper
threads the live width through `KPROG_ARM64_CSEL_PTR_TAG_PATH` at its single
call site and branches the two write paths off the result. It gets its own
mutation build-out in `build/mut_arm64_csel_ptr.py` (untracked, 59
single-anchor rows) over six contract files --- the pointer-path spec
(`arm64_csel_ptr_spec.json`), the family spec it cross-links
(`arm64_csel_spec.json`, the eight opcodes the generated switch and the
opcode cross-check consume), its generator
(`generate_arm64_csel_ptr_spec.py`, including the four illustrative-lean
guards whose failure paths are behaviorally reachable and the stale output
comparison), the generated C switch macro (`generated/arm64_csel_ptr.h`,
the eight `_Static_assert` opcode pins and the per-opcode case arms), the
generated Lean table (`GeneratedArm64CselPtr`, the `ptrTagPath`
(op, width) match), and the hand Lean refinement (`Arm64CselPtr.lean`, the
independent `arm64CselPtrSpec`, the refinement/only-csel/iff/sub-word/
family-drops theorems, the eight-way code dispatch, the in-range pin, and
the ptr/family/sub-word examples) --- with the same three detectors: gen
(`generate_arm64_csel_ptr_spec.py --check`), lean_chain (`lake build
KProgFormal.GeneratedArm64CselPtr` then `lake env lean
KProgFormal/Arm64CselPtr.lean`), and host (the 1024-case
`test_arm64_csel_ptr_host.c` oracle --- the opcode swept over all 256 byte
values crossed with all four widths in forked children, a non-family
opcode asserted to abort with `SIGABRT` through the generated unsupported
arm, the oracle an independent opcode-class switch structurally different
from the generated macro). 57 catch (`gen=30 lean_chain=17 host=12`) and 2
survive: the generator `ROOT` spelling repaint and the macro's path-seed
initialization (dead code --- every reachable case arm assigns before any
read, out-of-family opcodes abort first), both documented equivalences by
design. Shakedown retargets were needed for four generator message
repaints whose firing branches are unreachable on a green `--check` (the
family-order repaint became the order-comparison repaint, the
pointer-uniqueness and opcode-table guards became check inversions, and
the stale comparison became its own inversion, each live-probed); for the
refinement theorem (rename and `Bool`-ascription goal paint survive ---
nothing downstream binds the theorem and the ascription is propositional
--- retargeted to a goal with the `op`/`width` operands swapped, which the
elaborator rejects); for the soundness tactic (`trivial` discharges the
post-`cases` goals propositionally --- retargeted to `simp_all`, which
makes no progress) and the iff tactic (`cases <;> decide` and decide-only
both close it --- retargeted to decide-only whose free `width` variable
`decide` cannot close, error pointing at the free variable); and for the
in-range pin (repainting the upper bound 69 to either 68 or 28 stays
provable since `csel` is 28 --- retargeted to the lower bound 28 -> 29,
which `decide` refutes).


The AArch64 store-exclusive status contract is the one value the simulator's
`STLXR` handler writes back to the status register: the store-exclusive
succeeds unconditionally in this simulator, so the status is the success code
`0` narrowed to the destination width, and the status register write is
`ARM64_SIM_L_WRITE_REG_WIDTH` at the fixed `ARM64_WIDTH_32` inside the
`ARM64_SIM_L_EXEC` dispatch. The status is derived rather than restated: the
generated macro computes it as the destination-width mask with itself
subtracted, and the independent Lean statement does the same
(`narrow (mask width - mask width) width`). It gets its own mutation
build-out in `build/mut_arm64_stlxr.py` (untracked, 53 single-anchor rows)
over five contract files --- the status spec (`arm64_stlxr_spec.json`), its
generator (`generate_arm64_stlxr_spec.py`, including the order/macros/
no-opcodes/opcode-drift guards and the stale-output comparison), the
generated C switch macro (`generated/arm64_stlxr.h`, the `_Static_assert`
code pin, the `KPROG_ARM64_STLXR_HANDLED` guard, the coverage assertion, and
the per-opcode case arm), the generated Lean table
(`GeneratedArm64Stlxr`, the `value`/`code`/`mnemonic`/`flagsUnchanged`
definitions), and the hand Lean refinement (`Arm64Stlxr.lean`, the
independent `arm64StlxrSpec`, the refinement and zero-status theorems, the
in-range pin, the code dispatch, the flags-unchanged theorem, the w32
high-half bound, and the two examples) --- with the same three detectors:
gen (`generate_arm64_stlxr_spec.py --check`), lean_chain (`lake build
KProgFormal.GeneratedArm64Stlxr` then `lake env lean
KProgFormal/Arm64Stlxr.lean`), and host (the 1028-case
`test_arm64_stlxr_host.c` oracle --- the known opcode required to return the
width-mask-minus-itself masking oracle status at all four destination
widths, the opcode byte tracked through all 256 values at every width with a
non-family byte asserted to abort with `SIGABRT` through the generated
unsupported arm, and the masking oracle an independent shift-of-one
derivation rather than the macro's width-mask ladder). 49 catch
(`gen=26 lean_chain=15 host=8`, one of the host catches through a compile
failure) and 4 survive: the generator `ROOT` spelling repaint, the
generated table's mnemonic repaint kept behind a trailing comment, the
same trailing-comment repaint written on the hand side, and the macro's
width-seed initialization (dead code --- the status arm is the width mask
subtracting itself, identical for every width mask, so any width repaint
still observes `0 - 0`), all documented equivalences by design. Shakedown
retargets were needed for the `HANDLED` guard: a coverage-assertion message
repaint is unobservable by a green `--check` and equally unobservable to
the host compile (the message is not checked), so the row was retargeted to
the guard itself inverted `==` -> `!=`, which the `_Static_assert` coverage
check rejects at compile time; for the generated value arm, a
`narrow 0 (Width.w32)` repaint equals `narrow 0 width` at every width (zero
is zero at any width), so the row was retargeted to `narrow 1 width`, which
both the refinement and the host oracle reject; and for the refinement
tactic, the `bv_decide` -> `native_decide` repaint stays sound, and the
row was retargeted to dropping the independent-spec unfold
(`simp only [value, narrow, mask]` without `arm64StlxrSpec`), which
`bv_decide` refutes with an opaque `arm64StlxrSpec` counterexample.


The AArch64 move-wide insertion contract is the 16-bit halfword insert the
simulator's `MOVK` handler computes: the low 16 bits of the immediate land at
one of the four architectural columns 0/16/32/48 and every other destination bit
is kept, the column coming from the packed AUX word's lane-2 shift field. The
generated macro is `KPROG_ARM64_MOVK_INSERT` from `generated/arm64_movk.h` (the
`KPROG_ARM64_MOVK_HANDLED` column guard with the four coverage static
assertions, the switch over the column with per-column case arms, and the
mask/shift insert statement), and `KProgFormal/GeneratedArm64Movk.lean` carries
the four-member `MovkShift` table with `column` and `value`. `Arm64Movk.lean`
proves the generated masked insert equal to an independent statement --- the
destination with the 16-bit column cleared or'd with the narrowed immediate
shifted into place, deliberately not a restatement of the generated mask pair
--- the width-narrowed composition over every width, the closed column set, the
four-column dispatch, and six native-decide examples. It gets its own mutation
build-out in `build/mut_arm64_movk.py` (untracked, 74 single-anchor rows) over
five contract files --- the column spec (`arm64_movk_spec.json`), its generator
(`generate_arm64_movk_spec.py`, including the four expected columns, the name
and order pins, the `ARM64_AUX_MOVK` lane-2 alias regex that re-checks
`kprog/arm64/arm64_sim.h` on every `--check`, and the stale-output comparison),
the generated C switch macro (`generated/arm64_movk.h`), the generated Lean
table (`GeneratedArm64Movk`), and the hand Lean refinement (`Arm64Movk.lean`)
--- with the same three detectors: gen (`generate_arm64_movk_spec.py
--check`), lean_chain (`lake build KProgFormal.GeneratedArm64Movk` then
`lake env lean KProgFormal/Arm64Movk.lean`), and host (the 20,145-case
`test_arm64_movk_host.c` oracle --- 24 boundary vectors over all four columns,
the 20,000-iteration fixed-seed sweep crossed with the columns, and the forked
column-8 abort through the generated unsupported arm; the oracle writes the
destination into a byte array and replaces the target halfword's two bytes from
the immediate's low two bytes, structurally separate from the macro's
shift/mask pair). 68 catch (`gen=30 lean_chain=19 host=18`, three of the host
catches through compile failures: the column-0 HANDLED repaint the coverage
static assertion rejects, the dropped `imm` operand of the insert, and the
`>>=` mask ladder repaint) and 6 survive: the generated-Lean precedence
repaint (`|||` binds looser than `&&&`, so dropping the inner parentheses
recomputes the same value), a generator comment probe, a hand dispatch
doc-comment repaint, the hand-Lean column repaint (the hand probes re-read the
generated column through `open ... (column)`, so the truth is carried by the
generated table and the dispatch theorem, not by the hand restatement), the
compact spec JSON spacing paint, and the macro's dead default-arm mask seed
(the unsupported arm aborts; the mask assign feeds nothing). All six are
documented equivalences by design. Shakedown retargets were needed for two
draft anchors: the bare `dst` repaint in the generated-Lean value row is not a
Lean identifier (the elaborator rejects the term before any semantics, so the
row became `imm <<< s` -> `imm >>> s`, which the refinement pins (the
insertion direction flips) and `bv_decide` refutes with the drift
counterexample); and the hand-Lean column-value repaint `column .col16 = 15`
survives --- the hand theories unfold the generated `column`, so the hand
repaint is a doc-level equivalence --- and the row was retargeted to the same
value inside `arm64_movk_column_dispatch`, there proved by `decide` against
the generated table, which fails.

The AArch64 packed-AUX layout contract gets its own mutation build-out in `build/mut_arm64_aux.py` (untracked, 92 single-anchor rows) over nine contract files --- the shared layout spec (`arm64_aux_spec.json`: four lanes b0..b3 at shifts 0/8/16/24 with the 0xff `reg_none`, `arm64Aux`, schema 1), its generator (`generate_arm64_aux_spec.py`: the `EXPECTED` mirror, the lane-shift check, the Lean packer/decoder recipes and the C packer/decoder recipes, and the stale-output comparison), the generated C header (`generated/arm64_aux.h`: the `KPROG_ARM64_AUX` packer and the four `KPROG_ARM64_AUX_B0..B3` decoders plus `KPROG_ARM64_AUX_REG_NONE`), the generated Lean module (`KProgFormal/GeneratedArm64Aux.lean`: `pack` and the four byte decoders plus `regNone`), the hand Lean refinement (`KProgFormal/Arm64Aux.lean`), both alias sheets (the sim-header packer aliases `ARM64_AUX`, `_ALU`, `_SHIFT`, `_MOVK`, `_MEM`, `_BITFIELD`, `_CCMP` and the sim-local decoder aliases `ARM64_SIM_L_MOD`..`_CCMP_NZCV`), and both host oracles (`test_arm64_aux_host.c` and `test_arm64_aux_route_host.c`). Five detectors, one regen stage: `gen` (`generate_arm64_aux_spec.py --check`), `movk_gen` (`generate_arm64_movk_spec.py --check`, whose `ARM64_AUX_MOVK` regex owns the sim-header's MOVK alias), `lean_chain` (`lake build KProgFormal.GeneratedArm64Aux` then `lake env lean KProgFormal/Arm64Aux.lean`), `host` (the 586,829-case packer-alias oracle over an independent `(aux >> 8k) & 0xff` restatement), and `route` (the 1,115,374-case sim-local decoder-alias oracle). 88 catch (`gen=21 movk_gen=1 lean_chain=27 host=9 route=30` --- 11 spec rejections, 9 stale generator renders plus 4 regen-drift pairs whose repaint lands live in the artifacts, 15 Lean rows over the generated and hand modules, and the alias-driving rows the route oracle sees through the real sim macros) and 4 survive, all documented equivalences by design: the alias-sheet doc-comment repaint, the host oracle's redundant `AUX` vs `AUX_ALU` equality repaint (both sides repaint identically, so the comparison recomputes the same equality), and the two summary-line repaints (the success line carries no result bit). Shakedown retargets: the hand-Lean lane-1 shared-theorem row first repainted the goal's conjunction order (swapping the two conjunct pairs keeps every `rfl` valid and survives, an equivalence the run exposed), so the row was retargeted to drop the first conjunct --- the two-conjunct `rfl` constructor then fails on the constructor count, which catches; the Lean/C decoder anchors were first drawn at the shift-zero branch, which the generator shares with the shifted branch, and were retargeted to the `aux >>>` and `>> {shift}` shift-expressions only the shifted branches render; and the sim-header `ARM64_AUX_MOVK` drift row turned out to be owned by the movk generator's regex (the aux generator never reads the sim header), so it became the fifth detector's single row.
The AArch64 conditional-select value contract gets its own mutation build-out
in `build/mut_arm64_csel.py` (untracked, 112 single-anchor rows) over nine
contract files --- the shared value spec (`arm64_csel_spec.json`: the per-arm
safety predicates and MOS-mask bit compositions pinned in schema 1), its
generator (`generate_arm64_csel_spec.py`: the `EXPECTED` mirror, the
sim-header opcode cross-check, the family-order guard, and the Lean/C
recipes), the generated C header (`generated/arm64_csel.h`: the
`KPROG_ARM64_CSEL_VALUE` ternary-switch mux, the `KPROG_ARM64_CSEL_HANDLED`
dispatch gate, and the `KPROG_ARM64_CSEL_PTR_TAG_PATH` cross-link), the
generated Lean module (`KProgFormal/GeneratedArm64Csel.lean`), the hand
refinement (`KProgFormal/Arm64Csel.lean`), the 160,161-case host mux oracle
(`test_arm64_csel_host.c`: boundary vectors, a 20,000-iteration two-outcome
eight-opcode value sweep over all four widths, and the forked non-family
abort probe), and the 337-case width-effective route scanner
(`test_arm64_width_effective_route_host.c`) that drives the whole dispatch
through the sim-local `ARM64_SIM_L_CSEL_VALUE` wrapper. Four detectors run
per mutation: the generator's `--check` re-render, the Lean chain (`lake
build` + elaboration), the host oracle (in-process plus a forked child for
the unsupported-opcode abort), and the route scanner (in-process only; the
semantics at the absent width code are defined, not fatal). 105 rows catch
(43 at the generator stage, 31 by the Lean chain, 26 by the host oracle, 5
by the route scanner), and 7 survive as documented equivalences: the
`__kprog_a64_cv_result` seed initialization every executed arm overwrites,
the wrapper second-source repaint (both operand exercises under the
scanner's zeroed flags and the host oracle pass explicit sources, so the
drift never selects the second source), three summary-line repaints, the
generator's comment-only appendix, the `trivial` proof repaint of
the flag-identity theorem, and the doc-comment line of the hand module.
Shakedown retargets: two sim-local repaints invisible to the width-self-pair
scanner --- a forced-take drift keyed on the effective width and an inverted
pointer-path gate, both self-consistent because both legs of every
width comparison pair re-derive the same dispatch --- were retargeted to drifts
raw-width drifts the absent-to-doubleword escalation exposes
(forced condition interception keyed on the raw absent width code, and
routing the pointer-path gate through the raw width word, probing the route
scanner into the pointer path at the doubleword leg only), a generator
error-message repaint and a three-NOOP cluster (flags-spec check inversion,
codes-assert repaint, coverage-gate constant) were retargeted to the live
comparisons they guard, and the spec's family-order row needs comma-joined
adjacency because the emitted JSON members carry trailing commas verbatim.


The AArch64 compare-and-branch predicate contract gets the same mutation
build-out in `build/mut_arm64_branch.py` (untracked, 101 single-anchor rows)
over six contract files --- the predicate spec (`arm64_branch_spec.json`: the
four kinds with per-kind Lean taken-predicates pinned in schema 1), its
generator (`generate_arm64_branch_spec.py`: the `EXPECTED` mirror, the
kind-name/code order pins, and the Lean/C recipes), the generated C header
(`generated/arm64_branch.h`: the `KPROG_ARM64_BRANCH_TEST` switch macro over
the four kinds with the `& 63` bit mask, the `KPROG_ARM64_BRANCH_HANDLED`
coverage gate, and the per-kind static asserts), the generated Lean module
(`KProgFormal/GeneratedArm64Branch.lean`), the hand Lean refinement
(`KProgFormal/Arm64Branch.lean`: bit-mask/mod-64 equivalence, `bitOf`, the
four-way `rfl`/`decide_eq_decide` refinement, next-PC composition, and the
four canonical examples), and the 80,256-case host oracle
(`test_arm64_branch_host.c`: boundary vectors over eight values x eight bit
indices x four kinds plus a 20,000-iteration fixed-seed two-outcome sweep).
Three detectors run per mutation: the generator `--check` re-render, the Lean
chain (`lake build` plus elaboration), and the host oracle recompiled per row.
93 rows catch (`gen=46 lean_chain=27 host=28`) and 8 survive as documented
equivalences: the generator's stale-mirror guard disarmed (`data !=
EXPECTED` made unreachable --- the mirror specifically guards spec-file
drift, which the 16 spec rows already trip independently), the
`__kprog_a64_br_taken` seed line every executed arm overwrites (the four-arm
switch is total over the covered kind set, and no row probes the uncovered
default fallthrough), the duplicated `kinds[]` entry that drops `TBNZ` from
the host sweep table (TBNZ stays pinned gen-side by the spec/generated Lean
rows), the fixed-seed sweep constant reseed (macro and oracle agree on every
input by the proved contract), the two boundary-vector/bit-list repaints
(each list re-paints the same set membership), and the two summary-line
repaints carrying no result bit. Shakedown retargets: the four-per-case
`break;` lines are the only per-arm distinguisher, retargeted to the
tbz-arm-plus-break pair; the shared `decide_eq_decide` /
`arm64BranchBitOf` rewrite lines appear twice (both tbz/tbnz halves) and were
context-qualified through their per-arm `BitVec.toNat (0|1 : BitVec 64)`
`simp` calls; the sim-local `ARM64_SIM_A64_{CBZ,CBNZ,TBZ,TBNZ}` wrappers in
`arm64_sim_local_bpf.h` steer 43 downstream kernel-side consumers through
`goto` macros and are intentionally left to the kernel-side micro-sim suite
(the compile-only checker cannot see a kind-argument swap, so no route
detector applies to this family here); and both order-swap rows need
comma-joined adjacency because the emitted JSON members carry trailing
commas verbatim.

### Step 0180 — AArch64 branch-emission shape mutation coverage

The `arm64_branch_emit` contract (`arm64_branch_emit_spec.json` 1 line,
`generate_arm64_branch_emit_spec.py` 115 lines,
`generated/arm64_branch_emit.h` 13 lines,
`KProgFormal/GeneratedArm64BranchEmit.lean` 27 lines,
`KProgFormal/Arm64BranchEmit.lean` 54 lines,
`test_arm64_branch_emit_host.c` 93 lines) covers the only emission-level
bridge in the formal tree: two code shapes the generator emits for every
branch — a backward edge (target at or below the current address) rendered
as an inverted conditional jump to a local fall-through label followed by
an unconditional jump, and a forward edge rendered as a plain conditional
jump with a fall-through — both selecting one shared next-PC. The
direction bit is carried by `KPROG_ARM64_BRANCH_BACKWARD(CURRENT, TARGET)`
as `((__u8)(((TARGET) <= (CURRENT)) ? 1 : 0))`, and every consumer that
needs the shape reads this one directive.

The hand Lean side proves the bridge in two pieces:
`arm64BranchEmitShapeSpec = decide (target <= current)` refined against
`GeneratedArm64BranchEmit.backward (shape current target)` via
`by_cases h : target <= current <;> simp [h]`, then the emission theorem
`arm64_branch_emit_refines` proving the shared next-PC equals `branchPc`
via `split <;> split <;> rfl` — the same 2×2 shape/taken grid the host
oracle enumerates as its 64-case 8x8 current/target lattice with both
directions asserted per case.

`build/mut_arm64_branch_emit.py` (474 lines) perturbs the six files with
71 rows across the three detectors, 'untracked, 71 single-anchor rows':
29 catch at the generator stage (spec JSON repaints and order/inclusion
swaps, generator mirror and order pins, file-path and C-body recipe
drifts, Lean recipe and next-PC recipe drifts), 26 catch through the Lean
chain (spec-body, theorem-goal and tactic, shape and nextPc recipe holes,
ctor injection, import and namespace drift, and the proof-strength probes
that must fail when a directive is genuinely wrong), and 16 catch by the
host oracle (oracle comparison drifts, emitted backward/forward steering
swap, branch_pc drifts, `KPROG_ARM64_BRANCH_BACKWARD` macro insert/race
hole, and address-grid resampling that keeps the 64-case lattice closed).
14 rows survive as documented equivalences: 'the disarmed spec-mirror
guard the shape rows already trip', the generator message repaint and
comment-only import repaint (green-run-invisible guard paths), three
consumers-free theorem renames (the emitted-side theorems plus the
`arm64_branch_emit_shape_refines` declaration line, whose statement the
file re-proves independently of the name), the `split`-chain tail repaint
that re-proves the same fully-split conjunction, the directive
irrelevance `arm64_branch_emit_shape_irrelevant` already states (both
shapes pick the same next PC), the lattice fall-through-constant repaint
(0x1000/0x2000 -> 0x1001/0x2001) the proved contract makes invisible, and
two summary-line repaints carrying no result bit. Shakedown retargets:
the drafted `hand_branchpc_two_valued_drift` self-referential goal anchor
did not match the real file (the refinement's RHS is `branchPc`, retargetd
to drop `GeneratedArm64BranchEmit.shape` from the unfold line — still
provable, split's auto-unfolding closes it, so the row became the
`equivalent_refines_tac_extra_split_survives` equivalence); the drafted
`host_addrs_grid_drift` lattice-rewrite survives (any sample of plain
addresses keeps the lattice closed because oracle and directive compute
the same function, an equivalence the `arm64_branch_emit_shape_irrelevant`
theorem states), so the retargeted rows label as equivalences; a comment
repaint of the re-rendered C header's top comment is catchable by the
`--check` mirror even though the byte-probe itself is inert; two
detector-invisible rows from the draft (the emitted `backward`-flag call
swap and the empty-arm bracket) were replaced by retargeted catchable
rows; the spec `@@`-swap placeholder needed a direct reordered-JSON edit
because single-line JSON has no standalone-token boundary to anchor the
placeholder against.
### Step 0181 — AArch64 byte-lane extraction mutation coverage

The `arm64_byte_lane` contract (`arm64_byte_lane_spec.json` 1 line,
`generate_arm64_byte_lane_spec.py` 138 lines,
`generated/arm64_byte_lane.h` 70 lines,
`KProgFormal/GeneratedArm64ByteLane.lean` 38 lines,
`KProgFormal/Arm64ByteLane.lean` 69 lines,
`test_arm64_byte_lane_host.c` 117 lines) covers the inverse half of the
generated load contract: the stack byte scatter takes byte `i` of a
64-bit word as `(value >> 8*i) & 0xff`. `KPROG_ARM64_BYTE_AT` is a total
eight-way switch over the lane index whose default arm reaches the
caller-supplied unsupported hook (SIGABRT-enforced by the host oracle)
and the direction the load ladder's reassembly needs. The hand Lean side
proves three things: `arm64_byte_lane_refines` equalizes the generated
shift-then-narrow `byteAt` with the independent masked-shift form
(`cases lane <;> simp only [...]] <;> bv_decide`),
`arm64_byte_lane_shift_dispatch` pins the eight shifts to `0, 8, ..., 56`
so the C switch's case set covers every lane exactly once, and
`arm64_byte_lane_load_inverse` reassembles all eight lanes through the
byte-lane shifts back into the load contract's value for every width,
plus two `native_decide` canonical examples (lane 2 and 7 of
`0x0123456789abcdef`).

`build/mut_arm64_byte_lane.py` (62 rows) perturbs the six files with the
three detectors, 'untracked, 62 single-anchor rows': 30 catch at the
generator stage (spec JSON drifts and lane inclusion/order rests,
generator mirror and pin drifts, file-path and Lean/C recipe drifts,
case and shift-line repaints in the generated C, generated-Lean ctor
and index/shift drift, and the nine Lean-chain holes), 9 catch through
the Lean chain (spec-body mask rewrite, dispatch goal/tail drifts,
inverse goal/tail drifts, example repaints, import drift), and 6 catch
by the host oracle (oracle byte-view rewrite, comparison flip, sweep
modulus, unsupported-lane reachability, unsupported-wait repaint).
17 rows survive as documented equivalences: 'the disarmed spec-mirror
guard the spec rows already trip', the generator message repaint and
comment-only import repaint (green-run-invisible guard paths), the
narrowing `__u16` repaint (a two-step narrowing store keeps the same
low byte), the stale index-definition repaint (the definition is
unfolded away but never load-bearing), the `0xffff` mask repaint (any
aligned mask of at least eight bits narrows to the same lane byte),
three consumers-free theorem renames and simp-set shrinks `bv_decide`
closes without, the boundary lane-sweep shrink the 20,000-iteration
random sweep already covers at every lane, the fixed-seed reseed and
value-grid resamples (pure workload-sample repaints the proved contract
makes invisible), a no-op self-assignment insertion, and two
summary-line repaints carrying no result bit. Shakedown retargets: none
were needed; every drafted anchor landed byte-exact, and the eight
survivor rows were relabeled `equivalent_*` after the first run
confirmed each repaint was semantics-preserving (the narrowing-store
and mask-width rows surprised: both keep the low byte by construction).
### Step 0182 — AArch64 little-endian load mutation coverage

The `arm64_load_bytes` contract (`arm64_load_bytes_spec.json` 1 line,
`generate_arm64_load_bytes_spec.py` 156 lines,
`generated/arm64_load_bytes.h` 42 lines,
`KProgFormal/GeneratedArm64LoadBytes.lean` 47 lines,
`KProgFormal/Arm64LoadBytes.lean` 70 lines,
`test_arm64_load_bytes_host.c` 114 lines) covers the load value ladder
itself: the stack reads `byteCount(width)` bytes from memory and
assembles each at its own lane (`__kprog_a64_lb_value |= addr[i] <<
8*i`, gated by the `>= ARM64_WIDTH_16/32` and `== ARM64_WIDTH_64`
comparison chain), zeroing every byte above the width. The generated
Lean side carries the lane-assembly `value` over the four widths; the
hand Lean side states the independent contract as a masked truncation
(`arm64LoadBytesSpec` over `GeneratedArm64Width.mask`) and proves:
`arm64_load_bytes_refines` (lane assembly = masked truncation,
`cases width <;> simp only [...] <;> bv_decide`),
`arm64_load_bytes_width_dispatch` (byte counts 1/2/4/8 and width codes
1/2/4/8 as eight `rfl`s, so the C ladder's comparison chain covers each
width exactly once), `arm64_load_bytes_upper_cleared` (bytes above the
width are zero), and three `native_decide` canonical examples
(halfword `0xcdef`, word `0x89abcdef`, doubleword identity).

`build/mut_arm64_load_bytes.py` (63 rows) perturbs the six files with
the three detectors, 'untracked, 63 single-anchor rows': 29 catch at
the generator stage (spec JSON drifts and width swaps/drops/dups,
generator mirror and pin drifts, file-path drifts, the lane `>>>`
shift drift and a lane XOR repaint, the generated C static asserts
and ladder-gate drifts, and the generated-Lean ctor/code/byteCount
context drifts), 16 catch through the Lean chain (generated `value`
arm repaints at the w16/w32/w64 tails, the `value` definition rename,
the hand spec-arm cross-width repaints, the dispatch goal and 8-tuple
tail shrink (7 `rfl`s close only 7 goals), the upper-byte goal widening
(a `>>> 16 = 0` claim on the w32 arm is false), the example repaints,
the import drift, and one proof-strength probe: the refinement
simp-set shrink dropping the masked-truncation unfolding genuinely
breaks the proof (kept as a catch)), and 5 catch by the host oracle
(byte-count drift, oracle shift repaint, comparison flip, high-byte
check inversion, byte-1/3/7 lane repaints in the C ladder). 13 rows
survive as documented equivalences: 'the disarmed spec-mirror guard',
the generator message repaint and comment-only import repaint
(green-run-invisible guard paths), three consumers-free theorem
renames and simp-set changes (`bv_decide` closes the refinement after
the arm repaints too), the high-byte mask repaint biased one lane high
(the cleared ladder already zeroed that bit), the weakened w8-upper
claim (`>>> 16 = 0` still implied by the single cleared lane), the
boundary pattern repaint, the fixed-seed reseed and sweep-width
rotation (pure workload-sample repaints the proved contract makes
invisible), and two summary-line repaints carrying no result bit.
Shakedown retargets: three generated-Lean anchors were ambiguous
(`| .w8 => 1` appears in both the `widthCode` and `byteCount` blocks;
the w32 lane tail appears in both the w32 and w64 arms) and were
re-anchored on whole-context blocks; the sweep-width anchor needed the
C source's three-tab depth; and one survivor row was relabeled
`equivalent_*` after the first run confirmed the weakened upper-byte
claim remains a theorem.
### Step 0183 — AArch64 ALU handler path mutation coverage

The `arm64_alu_handler` contract (`arm64_alu_handler_spec.json` 1 line,
`generate_arm64_alu_handler_spec.py` 83 lines,
`generated/arm64_alu_handler.h` 9 lines,
`KProgFormal/GeneratedArm64AluHandler.lean` 16 lines,
`KProgFormal/Arm64AluHandler.lean` 175 lines,
`test_arm64_alu_handler_host.c` 44 lines) fixes the pointer-provenance
dispatch of the generic ALU handler: `KPROG_ARM64_ALU_USE_POINTER` is
true only for a 64-bit ADD whose destination is not SP and whose source
provenance is non-scalar. The generated Lean predicate is a flat
conjunction; the hand Lean side independently enumerates the same
condition as a four-key match (`arm64AluUsePointerSpec`, no reuse of
the generated form), proves the equal-up-to-interface refinement
(`cases width <;> cases op <;> cases dst <;> cases srcTag <;> decide`)
plus scalar/pointer writeback refinements and the composed handler
theorem, and four `native_decide` examples (tagged add keeps provenance,
tagged sub scalarizes, SP add writes only SP, w32 add zero-extends and
scalarizes). The host oracle sweeps a 6×7×2×2 grid (widths × ops × sp ×
scalar) against an independent C restatement — 168 cases.

`build/mut_arm64_alu_handler.py` (45 rows) perturbs the six files with
the three detectors, 'untracked, 45 single-anchor rows': 18 catch at
the generator stage (spec JSON drifts on every predicate field,
generator mirror and pin drifts, file-path drifts, the generated-Lean
predicate body repaint, and the C conjunction repaints), 12 catch
through the Lean chain (the generated predicate body repaint, open/
namespace drift, the hand match-arm repaints making SP or scalar false
arms true or the fall-through arm true, the path-body repaint, the
path-tactic shrink dropping the SP/tag enumeration, the rich-blind
main-refinement repaint, the split-simpset shrink dropping
`Bool.false_eq_true`, the scalar-writeback width-case drop, and the
path theorem rename — the main refinement `rw`s it by name, so the
rename breaks the build and is a catch, unlike consumers-free example
renames), and 3 catch by the host oracle (the not-SP conjunct drop,
the oracle repaint, and the macro comparison negation). 12 rows
survive as documented equivalences: 'the disarmed spec-mirror guard',
the generator message repaint and comment-only import repaint
(green-run-invisible guard paths), the generated-Lean tail comment
repaint, the hand namespace comment repaint, the main-refinement
`rw` list repaint with a trailing comma (Lean accepts the syntax),
the scalar-writeback tactic shrink (`cases width <;> rfl` — every
branch is definitionally closed by `rfl` after the case split), two
consumers-free example-theorem renames, the host ops-grid drift
(oracle and macro repaint together), the host widths-grid shrink
(coverage caveat recorded, handshake stays consistent), and two
summary-line repaints carrying no result bit. Shakedown relabeled six
drafted rows `equivalent_*` after the first run confirmed each
survivor: notably the path-theorem rename is NOT one of them — it was
retained as a catch because the main refinement cites the name.
### Step 0184 — AArch64 CCMP handler mutation coverage

The `arm64_ccmp_handler` contract (`arm64_ccmp_handler_spec.json` 1
line, `generate_arm64_ccmp_handler_spec.py` 103 lines,
`generated/arm64_ccmp_handler.h` 18 lines,
`KProgFormal/GeneratedArm64CcmpHandler.lean` 26 lines,
`KProgFormal/Arm64CcmpHandler.lean` 113 lines,
`test_arm64_ccmp_handler_host.c` 125 lines) fixes the CCMP flag
transition: `KPROG_ARM64_EXEC_CCMP` runs
`KPROG_ARM64_EVAL_COND` on the incoming NZCV, takes
`KPROG_ARM64_SET_SUB_FLAGS` on the true path, and loads
`(C_N,C_Z,C_C,C_V)` from the fallback immediate's shifts 3/2/1/0 on the
false path, touching no register state. The generated Lean side
carries `fallbackFlags` (mask `0x8/0x4/0x2/0x1`) and the `apply` step;
the hand Lean side states the fallback independently (`getLsbD 3..0`,
bits above NZCV[3:0] intentionally ignored, matching the C
extraction), refines fallback/condition/step/handler, and proves four
`native_decide` examples (true path via SUB flags with regs preserved,
false path via fallback, w32 overflow, fallback high-nibble
discard). The host oracle sweeps incoming NZCV × condition × 8
operand vectors × 4 widths × fallback nibble — 122,880 cases.

`build/mut_arm64_ccmp_handler.py` (57 rows) perturbs the six files
with the three detectors, 'untracked, 57 single-anchor rows': 17
catch at the generator stage (spec JSON drifts on every field
including false-path bit assignments and preserves_registers,
generator mirror drifts, the canonical condition-table message, the
Lean flag-row and C-assignment recipe repaints, file-path drifts, the
generated C eval/nibble/z/macro drifts), 17 catch through the Lean
chain (fallback-bit repaints, apply condition-argument order, apply
operand swap, fallback-shift repaint, namespace drift, the hand
`getLsbD` drifts, the condition-refinement `change` and
`condition_sound` repaints, the step `rw` and both split-branch
rewrites, the handler tail `rw`, the import drift, and two
consumer-cited refinement renames — `arm64_ccmp_fallback_refines` is
rw'd by `arm64_ccmp_step_refines`'s else branch and its simp-set
shrink drops the independent-spec unfolding, so both are retained as
catches), and 10 catch by the host oracle (conditional flip,
want_n/want_c/want_v fallback-bit drifts, the operand swap in the
EXEC call, the comparison flip, and the true-path result repaints).
13 rows survive as documented equivalences: 'the disarmed spec-mirror
guard', the generator message repaint and comment-only import repaint
(green-run-invisible guard paths), the cond-table message repaint
(guarded error text keyed to a check the -check run never trips),
the generated-Lean comment repaint and hand namespace comment repaint,
the fallback-refinement rename drafted and re-judged (retained as a
catch because the step theorem cites it), three consumers-free
example-theorem renames, the host loop-start shrinks (incoming/
cond/fallback starting at 1: pure sample-grid resamples the
proved contract makes invisible), and two summary-line repaints

### Step 0185 — AArch64 ALU operand mutation coverage

The `arm64_alu_operand` contract (`arm64_alu_operand_spec.json` 1 line,
`generate_arm64_alu_operand_spec.py` 84 lines,
`generated/arm64_alu_operand.h` 9 lines,
`KProgFormal/GeneratedArm64AluOperand.lean` 18 lines,
`KProgFormal/Arm64AluOperandHandler.lean` 86 lines,
`test_arm64_alu_operand_host.c` 106 lines) fixes the RHS selection the
generic ALU handler consumes: `KPROG_ARM64_ALU_RHS` is the immediate
value when the mode is immediate and `KPROG_ARM64_MOD_VALUE` (the
shared modifier semantics) when the mode is register, so the operand
composition closes the free-RHS premise of the ALU-path theorem
without re-proving the modifier. The hand Lean side mirrors the
mode dispatch independently (`arm64AluRhsSpec` over
`arm64ModValueSpec`), refines rhs via `arm64_mod_refines`, composes
the operand handler over the already-proven `arm64_alu_handler_refines`,
and proves four `native_decide` examples (immediate bypass, sxtx
pointer add, lsl w32 scalarize+narrow, immediate SP write). The host
oracle sweeps mode × 11 modifiers × 8 vectors × 8 shifts × 4 widths =
5,632 cases against a C modifier oracle covering none/lsl/lsr/asr/
ror/uxtw/sxtw/uxth/sxth/uxtb/sxtb.

`build/mut_arm64_alu_operand.py` (42 rows) perturbs the six files
with the three detectors, 'untracked, 42 single-anchor rows': 14
catch at the generator stage (spec field drifts on both mode rows,
register_path, and the generator mirror; the rhs register-arm
argument-order drift; the generated C immediate-value and modifier
argument repaints that transpose VALUE and SHIFT; file-path drifts),
9 catch through the Lean chain (generated and hand mode-arm repaints
including both operand-order mirrors, mode-constructor drifts,
namespace drift, import drift, the rhs tail `rw` by name), and 8 
catch by the host oracle (LSL shift-direction repaint, ASR w32
shift-direction repaint, UXTW shift-direction repaint, SXTB type
repaint, want-line modifier-argument transpose, comparison flip,
and the two term-level drifts the mode/vec grid rows expose). 11 rows
survive as documented equivalences: 'the disarmed spec-mirror guard',
the generator message repaint and comment-only import repaint
(green-run-invisible guard paths), the modifier-table message repaint
(guarded error text keyed to a check the -check run never trips),
three consumers-free example-theorem renames, the
`arm64_alu_handler_refines`/`arm64_alu_rhs_refines` rw-order repaint
(disjoint subterms close in either order), the host mode-loop
shrink (register-half grid coverage caveat), the mirrored host
vector walk (`vectors[i]`/`vectors[7-i]` transpose keeps the check
pair coverage identical), and two summary-line repaints carrying no
result bit. Shakedown relabeled two drafted rows: the rw-order
repaint survives (disjoint subterms close in either order) and the
modifier-table message repaint survives as guarded error text.

### Step 0186 — AArch64 CNEG mutation coverage

The `arm64_cneg` contract (`arm64_cneg_spec.json` 1 line,
`generate_arm64_cneg_spec.py` 202 lines,
`generated/arm64_cneg.h` 44 lines,
`KProgFormal/GeneratedArm64Cneg.lean` 31 lines,
`KProgFormal/Arm64Cneg.lean` 89 lines,
`test_arm64_cneg_host.c` 146 lines) fixes the condition-gated
negation value: a taken condition negates the source (generated
form `0 - src`, hand form `~~~src + 1` — the same two's-complement
identity stated independently), an untaken condition passes it
through, both arms narrow with the shared width mask, opcode 65
(`ARM64_OP_CNEG`), and no NZCV bit is written. The generator
re-parses the opcode define from `kprog/arm64/arm64_sim.h` on every
run and pins code drift with a `_Static_assert`; the host oracle
re-derives the width mask from a shift of one (never the macro's
mask ladder), cross-checks the invert-and-add-one identity the Lean
statement uses, and asserts an out-of-family opcode reaches the
caller-supplied unsupported arm via SIGABRT. The hand Lean side
refines value over both condition outcomes and all four widths,
proves code-in-range/dispatch/flags-unchanged, cancel and identity
identities, the w32 bound, and four canonical `native_decide`
examples. The host sweep is 40,097 cases (boundary vectors plus a
40,000-iteration fixed-seed random walk).

`build/mut_arm64_cneg.py` (46 rows) perturbs the six files with the
three detectors, 'untracked, 46 single-anchor rows': 15 catch at
the generator stage (spec operation/name/code/macro drifts,
generator mirror drifts, the generated Lean arm swap, the generated
C body repaints (mask complement, operand swap), case-label drift,
handled/value macro renames, the code-drift static-assert repaint,
and sim-header repointing), 7 catch through the Lean chain (the
generated value-arm swap and opcode repaint, flagsUnchanged
repaint, namespace drift, the hand spec-arm swap (taken/untaken
exchanged), the `decide` for `bv_decide` downgrade), and 9 catch by
the host oracle (raw-negation repaint, the identity gate drift,
the width-mask ladder w31 repaint, comparison flip, operand swap,
and the out-of-family abort disarm when the probe re-uses the
supported opcode). 15 rows survive as documented equivalences: the
disarmed spec-mirror guard, the four guarded error-message
repaints (spec/order/macros/opcode/drift text the green run never
trips), the comment-only import repaint, five consumers-free
theorem renames (flags-unchanged, taken-cancel, untaken-identity,
and two canonical examples), the code-range bound relaxation
(65 ≤ 65 ∧ 65 ≤ 66 stays a theorem the weaker statement still
proves), and two summary-line repaints carrying no result bit.
Shakedown relabeled two drafted rows after the first run: the spec
message repaint and the code-range bound66 repaint (the promote-
to-catch candidates both shake green as weaker-but-true repaints).
### Step 0187 — AArch64 logic-flag handler mutation coverage

The `arm64_logic_flag_handler` contract
(`arm64_logic_flag_handler_spec.json` 1 line,
`generate_arm64_logic_flag_handler_spec.py` 135 lines,
`generated/arm64_logic_flag_handler.h` 24 lines,
`KProgFormal/GeneratedArm64LogicFlagHandler.lean` 35 lines,
`KProgFormal/Arm64LogicFlagHandler.lean` 99 lines,
`test_arm64_logic_flag_handler_host.c` 70 lines) fixes the AND/BIC
result-plus-NZCV step: value = shared ALU result (families 2/3
cross-checked against the ALU decode table), flags = shared logic
policy (`KPROG_ARM64_SET_LOGIC_FLAGS` — N from the top result lane,
Z on all-zero, C=V=0), and the handler composition where ANDS/BICS
write back the narrowed scalar (`generatedArm64ScalarWrite`) while
TST/TST-BIC leave register/SP state untouched. The hand Lean side
restates the result and flag policy independently
(`arm64AluResultSpec`, `arm64LogicNzc`), refines step and handler
through the already-proven `arm64_alu_result_refines` /
`arm64_logic_flags_refines` / `arm64_scalar_write_refines`, and
proves four `native_decide` examples (ANDS w32 scalarize + negative,
BICS through XZR discarding the result, TST preserving state,
TST-BIC no writeback). The host oracle sweeps 8 operand vectors × 
4 widths × 2 families = 64 cases against a direct AND/BIC restatement.

`build/mut_arm64_logic_flag_handler.py` (49 rows) perturbs the six
files with the three detectors, 'untracked, 49 single-anchor rows':
16 catch at the generator stage (spec family/mode field drifts,
generator mirror drifts, the ALU-arm drift, the result-recipe
operand swap, the logic-to-SUB policy repaint in both the C and
Lean recipes, decode-table repointing, and file-path drifts), 13
catch through the Lean chain (both hand family-arm drifts, the NZCV
tail repaint, the step-refinement rewrite repaints (both arms), the
writeback/test mode exchanges in both refinements, the handler-tail
rewrite repaint, the import drift, and the namespace drift), and 8 
catch by the host oracle (the BIC-mask repaint `lhs | ~rhs`, the
negative-bit shift repaint, the zero-check flip, the comparison
flip including the V-arm, the operand swap in the EXEC call, the
trailing-coma-free comparator repaints, and the EXEC-argument
repaints). 12 rows survive as documented equivalences: the disarmed
spec-mirror guard, the generator spec/ALU message repaints and
comment-only import repaint (green-run-invisible guard paths), the
generated family-constant repaints (`FAMILY_AND` 2U→4U and
`FAMILY_BIC` 3U→4U) and the generated Lean code-arm repaint (the
bookkeeping values are consumed by name — the macro switch and the
host driver both reference the macros/constants as identifiers, so
a value repaint never rebinds), four consumers-free example-theorem
renames, and two summary-line repaints carrying no result bit.
Shakedown relabeled three drafted rows after the first run — the
two family-constant repains and the code-arm repaint (all three
shake green because the consumers bind names, not values).

### Step 0188 — AArch64 memory address-offset mutation coverage

The `arm64_mem_offset` contract (`arm64_mem_offset_spec.json` 1
line, `generate_arm64_mem_offset_spec.py` 128 lines,
`generated/arm64_mem_offset.h` 32 lines,
`KProgFormal/GeneratedArm64MemOffset.lean` 17 lines,
`KProgFormal/Arm64MemOffset.lean` 49 lines,
`test_arm64_mem_offset_host.c` 94 lines) fixes the load/store
address offset: an offset access contributes the immediate, a
pre/post-indexed access contributes no immediate here (its
writeback applies it separately), an indexed access additionally
adds the already source-modified index register, and the
accumulation is 64-bit two's-complement wrapping stated two ways —
signed `__s64` addition in the C statement-expression macro
(evaluate-once locals, no NZCV), `BitVec 64` addition in the Lean
contract, with that bit-pattern equivalence as the refinement
statement. The generated Lean side carries both the let/if form and
an independent four-case `valueSpec` table; the hand side proves
the refinement `bv_decide`-wise, the four-case dispatch lemma, the
prepost-immediate-independence lemma, and three canonical examples.
The host oracle reconstructs the offset through an `__int128`
signed accumulator (a different expression tree from the macro's
if-nesting) over a 168-case boundary grid plus a 20,000-iteration
fixed-seed random sweep = 20,168 cases.

`build/mut_arm64_mem_offset.py` (45 rows) perturbs the six files
with the three detectors, 'untracked, 45 single-anchor rows': 15
catch at the generator stage (spec field drifts, generator mirror
drifts including the base-reciprocal drift and the four-case table
swaps mirrored into both backends, and path drifts), 13 catch
through the Lean chain (both generated let/if drifts, all four
generated table swaps, the namespace drift, the hand
`unfold`/`cases` tactic shrinks, and the four dispatch-lemma
repaints), and 5 catch by the host oracle (the acc-gate flip
`if (prepost)`, the index-negation drift, and the truncation-mask
repaint). 12 rows survive as documented equivalences: the disarmed
spec-mirror guard, the guarded spec/order message repaints, the
comment-only import repaint, the evaluate-once assignment comment
repaints (the C locals carry no observer), four consumers-free
theorem/example renames (the refines theorem and prepost lemma are
declared and never cited elsewhere, as are the three canonical
examples), and two summary-line repaints carrying no result bit.
Shakedown relabeled two drafted rows after the first run — the
refines-theorem rename and the prepost-lemma rename (both shake
green because neither theorem has downstream consumers).

### Step 0189 — AArch64 ADD/SUB flag-handler mutation coverage

The `arm64_flag_handler` contract (`arm64_flag_handler_spec.json`
1 line, `generate_arm64_flag_handler_spec.py` 161 lines,
`generated/arm64_flag_handler.h` 40 lines,
`KProgFormal/GeneratedArm64FlagHandler.lean` 41 lines,
`KProgFormal/Arm64FlagHandler.lean` 113 lines,
`test_arm64_flag_handler_host.c` 94 lines) fixes the ADD/SUB
result-plus-NZCV step: value = shared ALU result (families 0/1
cross-checked against the ALU decode table), flags =
`applyAdd`/`applySub` on the same operands (the generated C emits
two macros — `KPROG_ARM64_EXEC_ARITH_WRITEBACK` adding the result
assignment, `KPROG_ARM64_EXEC_ARITH_COMPARE` flags-only), and the
handler composition where ADDS/SUBS write back the narrowed scalar
(`generatedArm64ScalarWrite`) while CMP/CMN leave register/SP state
untouched. The hand Lean side restates the step independently
(`arm64AluResultSpec` + `arm64AddNzc`/`arm64SubNzc`), refines step
and handler, and proves four `native_decide` examples (ADDS w32
overflow writeback, SUBS through XZR discarding the result, CMP
preservation, CMN carry without writeback). The host oracle
re-derives flags through a signed `__int128` comparison — carry as
an out-of-range test for ADD, an operand compare for SUB — and
sweeps 8 operand vectors × 4 widths × 2 families = 64 cases
against both macros with parked sentinel values.

`build/mut_arm64_flag_handler.py` (47 rows) perturbs the six files
with the three detectors, 'untracked, 47 single-anchor rows': 16
catch at the generator stage (spec family/mode field drifts
including the add-flags/sub-alu transposes, generator mirror
drifts including the result-recipe operand swap and the
flags-macro repaint across both write arms, and decode-table or
path repoints), 13 catch through the Lean chain (both generated
family-arm and flags-arm swaps, the value/flags apply transpose,
the hand step flags transposes, both writeback comparisons in the
step refinement, the writeback no-op exchange, the handler-tail
rewrite repaint, and the import/namespace drifts), and 7 catch by
the host oracle (the want-operand swap, the carry-arms transpose,
the overflow-polarity flip, the zero-vs-negative-bit gate repaint,
the family-constant repaint causing switch-default abort, and the
comparison gate repaint `cz != want_n` another vector still
condemns). 11 rows survive as documented equivalences: the
disarmed spec-mirror guard, the guarded spec/ALU message and
comment-only import repaints (green-run-invisible), the generated
Lean code-arm value repaint (no consumer — 0187 precedent), the
ADD-operand swap in the generated result assignment (commutative
at every masked width for every input), four consumers-free
example-theorem renames, and two summary-line repaints carrying no
result bit. The shakedown also documents a detector-relevant
contrast with Step 0187: repainting the family
user-facing constant (`ARITH_FAMILY_ADD 0U→3U`) is a catch here
because the host threads raw literals 0/1 through the macro
switch, while the logic-flag handler's repaint survived because its
driver re-uses the generated macros as identifiers.

### Step 0190 — AArch64 stack-index mutation coverage

The `arm64_stack_index` contract (`arm64_stack_index_spec.json`
1 line, `generate_arm64_stack_index_spec.py` 130 lines,
`generated/arm64_stack_index.h` 9 lines,
`KProgFormal/GeneratedArm64StackIndex.lean` 14 lines,
`KProgFormal/Arm64StackIndex.lean` 93 lines,
`test_arm64_stack_index_host.c` 102 lines) fixes the
frame-offset -> arena-byte map: `index bias off =
truncate-32(wrapping64 bias + off)` — the biased window such that
the frame-base offset `-bias` lands at index 0 and offset 0 at
byte `bias` — while `ptrIndex` keeps the full 64-bit sum for the
stack-pointer helper. The hand Lean side restates the map
independently (`BitVec.setWidth 32 (bias + off)`), proves the
refinement plus the frame-base / base-is-bias / affine-step /
`2^32`-aliasing / ptr-truncation / ptr-sum laws and two concrete
bias-96 examples (frame base, word slot 13, arena top, and the
below-base wrap to `0xffffffff`). The host oracle re-derives the
map with an unsigned 64-bit restatement and 536 cases including
alias launches at +`2^32`.

`build/mut_arm64_stack_index.py` (41 rows) perturbs the six files
with the three detectors, all untracked, 41 single-anchor rows:
14 catch at the generator stage (the five spec field drifts
including the mask-bits and accumulation repaints, the expected
op/mask/acc mirror drifts, the template truncation repaint and
the template summand swap — which re-renders to different
generated bytes and fails the staleness check — both C-template
sum/pointer repaints, the generated-path repoint, and the
generated-header guard repaint), 9 catch through the Lean chain
(the generated index/ptr definition drifts including the sumand
reorder and the off-by-one, the proof-sketch disruption in the
refinement, and every law repaint including the alias-law
shift-count change, the affine-step off-by-one, and the
ptr-truncation width change), and 3 catch by the host oracle
(the low-32 mask repaint in the restatement, the index
sum-to-difference flip, and the macro-name repaint). 15 rows
survive as documented equivalences: the spec mirror-guard
disarm, the guarded message repaint, the module-docstring
repaint (non-emitted bytes), the plus-zero summand repaint, the
independent restatement's sumand swap (setWidth-32 distributes
over the summand order), three theorem renames without
downstream consumers (`frame_base`, `example`, `wrap_example`),
the alias-step repaint to another 2^32 multiple, the
u32-bias cast repaint on the index macro (numerically identical
for every in-range input at bias 96), the unsigned-u64-bias
pointer repaint, the summary-line repaint, the native_decide
pairing repaint (each goal closed before the vacuous second
tactic), and the host bias-constant repaint (bias is a parameter
both sides re-derive).

### Step 0191 — AArch64 stack slot-tag mutation coverage

The `arm64_stack_tag` contract (`arm64_stack_tag_spec.json`
1 line, `generate_arm64_stack_tag_spec.py` 127 lines,
`generated/arm64_stack_tag.h` 16 lines,
`KProgFormal/GeneratedArm64StackTag.lean` 33 lines,
`KProgFormal/Arm64StackTag.lean` 43 lines,
`test_arm64_stack_tag_host.c` 71 lines) fixes the stack
slot-tag selection: only a 64-bit access at a qword-aligned slot
carries the slot's stored tag (`(isW64 && isAligned)`), a closed
two-condition pair routed through a total four-case classifier
(`qword`, `sub_qword_aligned`, `qword_unaligned`,
`sub_qword_unaligned`) and its tagged table. The generated Lean
module restates the conjunction independently (`taggedSpec`) and
refines classify-then-table to it; the hand module proves
totality, the refinement via `decide`, the dispatch table, and
that unaligned access is never tagged; twin shape contracts
(`Arm64StackReadTagSourceShape`,
`Arm64StackWriteTagActionShape`) bind
`tagged(classify ...)` as the read/write slot-tag firing
predicate. The host oracle sweeps 4 widths x 8 offsets plus all
four boolean pairs = 36 cases against a plain-conjunction
oracle.

`build/mut_arm64_stack_tag.py` (39 rows) perturbs the six files
with the three detectors, all untracked, 39 single-anchor rows:
10 catch at the generator stage (the op/table-row spec drifts
including the qword-untagged and sub-qword-tagged flips, the
expected-table repaint, the tagged-spec `||` repaint, the
C-ternary `||` repaint, the generated-path repoint, and the
spec-mirror stale-gate disarm's catch sibling), 10 catch through
the Lean chain (the qword-table untagging and the three
sub-arm tagging repaints, the qword-routing classifier repaint,
the tagged-spec disjunction repaint, the totality `simp`
citation drift, the refine `cases` and namespace drifts), and 5
catch by the host oracle (the conjunction-to-disjunction and
polarity oracle-body repaints, the w64-sense and aligned-sense
class repaints' catch twins, and the macro-name drift). 14 rows
survive as documented equivalences: the order/table error-message
repaints unreachable on valid data, the spec mirror-guard
disarm, classifier-arm repaints renaming an emitted case label
within the same tagged class (every consumer binds
`tagged(classify ...)` — never the case identity), the
`rfl`-to-`decide` tactic repaint, three consumers-free theorem
renames, the `simp` lemma-list reorder, the host
summary-line repaint, and host grid repaints that mislabel
which concrete offset/width carries each boolean class while
still injecting both classes into macro and oracle alike.

### Step 0192 — AArch64 memory-index mutation coverage

The `arm64_mem_index` contract (`arm64_mem_index_spec.json`
1 line, `generate_arm64_mem_index_spec.py` 155 lines,
`generated/arm64_mem_index.h` 30 lines,
`KProgFormal/GeneratedArm64MemIndex.lean` 26 lines,
`KProgFormal/Arm64MemIndex.lean` 91 lines,
`test_arm64_mem_index_host.c` 74 lines) fixes the memory-index
presence selection: the `AUX` index lane's sentinel byte `0xff`
(`ARM64_REG_NONE`) names the absent arm, every other byte the
present arm. The generated side carries the `Arm` inductive,
`indexSentinel`, `arm`/`present` selectors, and the
`KPROG_ARM64_MEM_INDEX_PRESENT`/`_ARM` macros; the hand module
restates the selector and presence test independently against
the literal `0xff`, proves both refinements, pins the sentinel
against `0xff`/`.absent`/`GeneratedArm64Aux.regNone`, proves the
absent/present complement, the `hasIndex` consumption by the
offset contract, two-arm dispatch reachability, and five
concrete examples. The host oracle sweeps all 256 index bytes
over both macros plus an arm/present cross-consistency check =
512 cases.

`build/mut_arm64_mem_index.py` (45 rows) perturbs the six files
with the three detectors, all untracked, 45 single-anchor rows:
14 catch at the generator stage (the op/bits/sentinel/arm spec
drifts, the expected-table sentinel and absent-flag repaints,
the rendered Lean `if` selector repaint, both rendered C macro
repaints, and the generated-path repoint), 11 catch through the
Lean chain (the generated arm-`if` swap, both table-row flips,
the sentinel drift, the `present` match-body repaint, the
namespace drift, the hand independent-spec selector swap, both
refinement-statement repaints, the sentinel-pin drifts, the
complement inversion, and the consumption vignette repaint), and
8 catch by the host oracle (the want-present polarity flip, both
want-arm/cross-check arm repaints, the sentinel self-check
drift, and the generated constant/macro drifts). 12 rows survive
as documented equivalences: four unreachable error-message
repaints and the spec mirror-guard disarm (all
green-run-invisible), five consumers-free theorem renames, the
arm-constant repaint whose every use-site re-derives from the
identifier, and the host summary-line repaint.

### Step 0193 — AArch64 register-presence mutation coverage

The `arm64_reg_presence` contract (`arm64_reg_presence_spec.json`
1 line, `generate_arm64_reg_presence_spec.py` 169 lines,
`generated/arm64_reg_presence.h` 34 lines,
`KProgFormal/GeneratedArm64RegPresence.lean` 31 lines,
`KProgFormal/Arm64RegPresence.lean` 103 lines,
`test_arm64_reg_presence_host.c` 82 lines) fixes the
write-register destination-presence selection: a decoded
register number is a destination (a GPR) unless it is the zero
register `31` (`ARM64_XZR`) or the no-register sentinel `0xff`
(`ARM64_REG_NONE`), both of which discard the write. The
generated side carries the three-class `Class` inductive,
`xzrNumber`/`noneNumber`, `classify`/`writable`, and the
`KPROG_ARM64_REG_WRITABLE`/`_CLASS` macros; the hand module
restates the class table and presence test against the literal
numbers, proves both refinements, pins both numbers, links the
sentinel to the memory-index sentinel, and proves both discard
arms, reachability, and canonical examples. The host oracle
sweeps all 256 register bytes over both macros plus a
class/writable cross-consistency check and two constant
self-checks = 512 cases.

`build/mut_arm64_reg_presence.py` (56 rows) perturbs the six
files with the three detectors, all untracked, 56 single-anchor
rows: 18 catch at the generator stage (the
op/bits/xzr/none/class-code spec drifts, the expected-table
writable-flag repaints, the class-rows generator repaint, the
rendered Lean classifier swap, both rendered C macro repaints,
and the generated-path repoint), 16 catch through the Lean chain
(the classifier swap, all three class-table row flips, both
number-constant drifts, the `writable` match-body repaint, the
namespace drift, and the hand independent-spec selector swap,
refinement renames, number-pin drifts, the sentinel-link width
repaint, and both discard/receive flips), and 9 catch by the
host oracle (the want-writable `||` repaint, the want-class and
cross-check class swaps, the sentinel self-check drifts, and
the generated polarity/`&&`-repaint/swap trio). 13 rows survive
as documented equivalences: five unreachable error-message
repaints (including the zero/sentinel collide message) and the
spec mirror-guard disarm (all green-run-invisible), five
consumers-free theorem renames, the GPR class-constant repaint
whose every use-site re-derives from the identifier, the
decimal-to-hex literal repaint of the host XZR self-check
(`31U` and `0x1fU` being the same number), and the host
summary-line repaint.

### Step 0194 — AArch64 load-tag mutation coverage

The `arm64_load_tag` contract (`arm64_load_tag_spec.json`
1 line, `generate_arm64_load_tag_spec.py` 147 lines,
`generated/arm64_load_tag.h` 42 lines,
`KProgFormal/GeneratedArm64LoadTag.lean` 26 lines,
`KProgFormal/Arm64LoadTag.lean` 81 lines,
`test_arm64_load_tag_host.c` 116 lines) fixes the plain-load
provenance-routing decision: the destination is written through
the tag-copy register write (`ARM64_SIM_L_WRITE_REG_PTR_TAG`,
attaching the memory-read tag) exactly when the access width is
the doubleword width and the tag is not the bare scalar tag
(`width == .w64 && !tagIsScalar`); any other opcode reaches the
caller-supplied unsupported arm. The generated side carries
`code`, `preserve`, and a congruence lemma in Lean plus the
switch-based C macro whose case label `31U` is static-asserted
against `ARM64_OP_LOAD` and cross-checked against
`kprog/arm64/arm64_sim.h` at `--check` time; the hand module
restates the rule against the bit count, proves the refinement,
the sub-word and scalar drop laws, the w64-preserving
inversion, the iff, the opcode pins, and two canonical
examples. The host oracle forks a child per case over all 256
opcodes x 4 widths x 2 tag classes = 2048 cases: a known load
must match an independent oracle and an unknown opcode must
abort with SIGABRT through the generated unsupported arm.

`build/mut_arm64_load_tag.py` (49 rows) perturbs the six files
with the three detectors, all untracked, 49 single-anchor rows:
14 catch at the generator stage (the op/name/code/rule spec
drifts, the name/rule check rewrites, the rendered Lean body
`||` repaint, both rendered C case-arm repaints, and the
generated-path repoint), 13 catch through the Lean chain (the
code drift, both preservation-body repaints, the namespace
drift, and the hand spec `||` and tag-equality repaints, the
sub-word bound loosening, both drop-law flips, the iff right
side, the opcode pins, and both example flips), and 10 catch by
the host oracle (the oracle-op inversion, the width-32 and
tag-equality repaints, the exit-bit shift, the SIGFPE repaint,
the want-sign inversion, and the generated case/width/case-
body drifts). 12 rows survive as documented equivalences: six
unreachable error-message repaints (all green-run-invisible),
four consumers-free theorem renames, a true weaker range-pin
repaint (30 ≤ code ≤ 32 remains provable while the exact
`code_dispatch` pin stands), and the non-scalar tag-value grid
repaint that keeps both tag classes injected.

### Step 0195 — AArch64 FMOV destination-routing mutation coverage

The `arm64_fmov_dest` contract (`arm64_fmov_dest_spec.json`
1 line, `generate_arm64_fmov_dest_spec.py` 169 lines,
`generated/arm64_fmov_dest.h` 46 lines,
`KProgFormal/GeneratedArm64FmovDest.lean` 19 lines,
`KProgFormal/Arm64FmovDest.lean` 71 lines,
`test_arm64_fmov_dest_host.c` 105 lines) fixes the FMOV
destination-routing decision: a direction code routs the moved
value to the vector register `v0` exactly when it is one of the
four in-range direction codes with an even parity
(`dirCode < 4 && dirCode % 2 == 0`, d_from_x and s_from_w); the
two register-half directions write the general-purpose
destination through the width-narrowed register write; any
other code reaches the caller-supplied unsupported arm. The
generated side carries `code`, the four-arm
`vectorDestination` match in Lean, and the switch-based C macro
whose case labels are static-asserted against the
`ARM64_FMOV_*` defines and re-checked against
`kprog/arm64/arm64_sim.h` at `--check` time; the hand module
restates the rule arithmetically, proves the refinement, the
parity tuple, the out-of-range law, the complement iff, the
opcode pins, and two canonical examples. The host oracle forks
a child per case over all 256 direction codes: an in-range code
must match an independent parity oracle and an out-of-range
code must abort with SIGABRT.

`build/mut_arm64_fmov_dest.py` (51 rows) perturbs the six files
with the three detectors, all untracked, 51 single-anchor rows:
16 catch at the generator stage (the op/code/rule spec drifts,
the per-direction vector-destination flips, the codes and
routing check repaints, the rendered-C case emitter drift, the
assignment-polarity repaint, and the generated-path repoint),
11 catch through the Lean chain (the code drift, the match-arm
flip, the wildcard repaint, the namespace drift, and the hand
parity repaints, range repaints, parity-tuple flip, out-of-range
loosening, opcode pins, and example flips), and 11 catch by the
host oracle (the oracle parity repaint, the out-of-range bound
loosening, the exit-bit shift, the SIGFPE repaint, the
want-sign inversions, and the generated case-label, static
assert, macro-header, unsupported, and default repaints). 13
rows survive as documented equivalences: eight unreachable
error-message repaints (all green-run-invisible), two
consumers-free theorem renames (the parity tuple rename; the
spawn-side detach-equivalent complement rename indirectly cites
the refinement elsewhere in the same module), a true weaker
range-pin repaint (34 ≤ code ≤ 36 remains provable while the
exact `code_dispatch` pin stands), and both harness-grid bound
repaints (the 255-direction host sweep and the parity-tuple
lemma's `rfl`-closed conjunction) that keep both routing
classes exercised.

### Step 0196 — AArch64 MOV provenance mutation coverage

The `arm64_mov` contract (`arm64_mov_spec.json` 1 line,
`generate_arm64_mov_spec.py` 176 lines,
`generated/arm64_mov.h` 45 lines,
`KProgFormal/GeneratedArm64Mov.lean` 28 lines,
`KProgFormal/Arm64Mov.lean` 71 lines,
`test_arm64_mov_host.c` 114 lines) fixes the shared move routing
decision: `ARM64_OP_MOV_IMM` (1) always writes a width-narrowed
value, dropping any source provenance tag (the source is an
immediate), and `ARM64_OP_MOV_REG` (2) copies the source
register's tag through the tag-copy register write exactly at
doubleword width, else the width-narrowed scalar write; an
opcode outside the family reaches the caller-supplied
unsupported arm behind `KPROG_ARM64_MOV_HANDLED`, whose both
family opcodes are coverage static-asserted and re-checked
against `kprog/arm64/arm64_sim.h` at `--check` time. The
generated side carries the two-constructor `Mov`, `code`,
`mnemonic`, and the two-arm `ptrTagPath` match in Lean plus the
switch-based C macro; the hand module restates
`op = movReg && width = w64`, proves the refinement, the
never-preserve law, the w64 iff, the sub-word drop law, both
opcode pins with in-range bounds, the width-matters law, and
two canonical examples. The host oracle forks a child per case
over all 256 opcodes x 4 widths = 1024 cases.

`build/mut_arm64_mov.py` (50 rows) perturbs the six files with
the three detectors, all untracked, 50 single-anchor rows: 15
catch at the generator stage (the operation/row drifts, the
order and macros check repaints, the rendered code-table drift,
the width-code repaint in the rendered case arm, the
handled-join repaint, and the generated-path repoint), 10 catch
through the Lean chain (the code drift, the tag-path arm flip,
the wildcard repaint, the namespace drift, and the hand
conjunction repaint, the iff right side, the sub-word bound
repaint, the opcode pin, and both example flips), and 12 catch
by the host oracle (all three oracle repaints, the exit-bit
shift, the SIGFPE repaint, the want-sign inversion, and the
generated case-1 sets-path injection, case-label renumber,
polarity flip, handled `&&` repaint, and both coverage/pointer
assert repaints). 13 rows survive as documented equivalences:
six unreachable error-message repaints (all
green-run-invisible), three consumers-free theorem renames (the
refines rename among them — nothing downstream cites it), a
true weaker range-pin repaint (0 ≤ imm ≤ 3 remains provable
while the exact `code_dispatch` pin stands), and the width-grid
permutation that keeps all four width classes injected.

### Step 0197 — AArch64 LDRSX-the-LOAD-WIDTH mutation coverage

The `arm64_ldrsx` contract (`arm64_ldrsx_spec.json` 1 line,
`generate_arm64_ldrsx_spec.py` 190 lines,
`generated/arm64_ldrsx.h` 50 lines,
`KProgFormal/GeneratedArm64LdrSx.lean` 35 lines,
`KProgFormal/Arm64LdrSx.lean` 94 lines,
`test_arm64_ldrsx_host.c` 114 lines) pins the load width the three
sign-extending loads read before sign-extending into the
destination: `LDRSB` (54) reads a byte, `LDRSW` (57) a word, and
`LDRSH` (63) a halfword — the load width is fixed by the opcode
and independent of the destination access width, so a mislabeled
load reads the wrong number of bytes; an opcode outside the family
reaches the caller-supplied unsupported arm behind
`KPROG_ARM64_LDRSX_HANDLED`, whose three opcodes are coverage
static-asserted and re-checked against `kprog/arm64/arm64_sim.h`
at `--check` time. The generated side carries the
three-constructor `LdrSx`, `code`, `mnemonic`, the three-arm
`loadWidth` match, and the constant-true `flagsUnchanged` in Lean
plus the switch macro returning the `ARM64_WIDTH_*` code; the hand
module restates the load width keyed on the numeric code, proves
the refinement, the code-determined law, the pairwise
distinctness, the bytes-match law, the strictly-sub-64 law, all
three opcode pins with in-range bounds, the flags law, and two
canonical examples. The host oracle forks a child per case over
all 256 opcodes.

`build/mut_arm64_ldrsx.py` (58 rows) perturbs the six files with
the three detectors, all untracked, 58 single-anchor rows: 19
catch at the generator stage (the operation/row drifts, the
order/widths/macro-pair check repaints, the mnemonic-suffix
repaint, the rendered arms/case-label/width repaints, the
handled-join repaint, and the generated-path repoint), 14 catch
through the Lean chain (both code drifts, the load-width arm
repaints, the wildcard flip, the namespace drift, the hand
code-keyed repaint, the distinctness-pair repaint, the
bytes-match repaint, the sub-64 bound repaint, the opcode pin,
the flags flip, and both example repaints), and 14 catch by the
host oracle (all three oracle repaints, the zero-sentinel
repaint, the exit-mask shift, the SIGFPE repaint, the want-zero
and want-comparison swaps, and the case-54 label/shared-arm
repaints). 11 rows survive as documented equivalences: seven
unreachable error-message repaints (all green-run-invisible)
including the stale-gate, two consumers-free theorem renames
(the refinement and the mnemonic repaint's downstream freedom),
a true weaker range-pin repaint (53 ≤ imm ≤ 63 remains provable
while the exact `code_dispatch` pin stands), and the generated
mnemonic repaint that no downstream proof derives.

### Step 0198 — AArch64 width/narrowing mutation coverage

The `arm64_width` contract (`arm64_width_spec.json` 1 line,
`generate_arm64_width_spec.py` 146 lines,
`generated/arm64_width.h` 34 lines,
`KProgFormal/GeneratedArm64Width.lean` 43 lines,
`KProgFormal/Arm64Width.lean` 71 lines,
`test_arm64_width_host.c` 153 lines) fixes the four simulator
widths in both encodings (`w8`/`w16`/`w32`/`w64` carry codes
1/2/4/8, masks `0xff`/`0xffff`/`0xffffffff`/`0xffffffffffffffff`,
sign masks `0x80`/`0x8000`/`0x80000000`/`0x8000000000000000`, and
bit counts 8/16/32/64), `narrow` as the mask conjunction, `zero`
as the narrow-equals-zero test, `sign` as the narrow's top-lsb
observation, and the effective-width resolution that sends the
absent decoded code 0 to the default doubleword code 8 while
leaving every real code untouched. The generated side carries
`Width`, `code`, `mask`, `signMask`, `bits`, `narrow`, `zero`,
`sign`, `absentCode`, `defaultCode`, and `effective` in Lean plus
the C ternary-mask macros, `KPROG_ARM64_APPLY_WIDTH`, the
absent-code and default defines, and the effective ternary; the
hand module restates the codes as the refines wall and proves four
refines, the sign-mask observation law bridging mask test to
shift test with `bv_decide`, the effective refines plus
absent-is-default, the absent-names-no-width disjointness, the
default-is-w64 pin, and the identity-on-real-widths law. The host
oracle takes `expected_bits` from a code-keyed switch and checks
bits/mask/sign_mask, 18 boundary vectors per width, and a
20000-iteration fixed-seed LCG sweep over all four widths (40080
cases).

`build/mut_arm64_width.py` (87 rows) perturbs the six files with
the three detectors, all untracked, 87 single-anchor rows: 30
catch at the generator stage (the operation/row drifts, the
length/row/zip/set/absent-code/collision/default/default-bits
check repaints, the rendered Lean tables, the C aggregator and
apply/eff repaints, and the generated-path repoint), 23 catch
through the Lean chain (the code/mask/sign/bit drifts on both
sides, the xor/!=/Lsb-0 repaints of narrow, zero, and sign, the
default repaint, the effective fallthrough swap, the namespace
drift, the absent repaint, and the code/mask/bits/effective
spec repaints), and 12 catch by the host oracle (the width-code
repaints, the three modulo tails, the apply
`|`-for-`&` repaint, and the low-mask/sign orn/check-polarity and
sign-observation shift repaints). 22 rows survive as documented
equivalences: ten unreachable error-message repaints (all
green-run-invisible), six consumers-free theorem renames, and six
value/unused-path repaints that keep every protocol invariant
intact (the collider disarmed check, the never-evaluated
effective-path defines, the never-fired unknown-width default
branch, a boundary-vector value, and the fixed-seed LCG addend).

### Step 0199 — AArch64 pair-load-tag mutation coverage

The `arm64_pair_load_tag` contract (`arm64_pair_load_tag_spec.json`
1 line, `generate_arm64_pair_load_tag_spec.py` 167 lines,
`generated/arm64_pair_load_tag.h` 55 lines,
`KProgFormal/GeneratedArm64PairLoadTag.lean` 25 lines,
`KProgFormal/Arm64PairLoadTag.lean` 95 lines,
`test_arm64_pair_load_tag_host.c` 129 lines) fixes the two-slot
routing decision of the LDP handler (opcode 33): the outer pair
gate (`width == 64 && (lo != SCALAR || hi != SCALAR)`) guards two
per-slot tag-class decisions; the result is a two-bit mask, bit 0
selecting the tag-copy register write for the low slot, bit 1 for
the high slot, a clear bit the tag-dropping width-narrowed scalar
write, and an opcode outside the family reaching the
caller-supplied unsupported arm. The generated side carries
`code`, `slotCount`, `slotPreserve`, `pairGate`, and the
gate-then-per-slot `routeMask` in Lean plus the switch-based C
macro with the gate, the two slot-bit conditionals, and the
`ROUTE_LOW`/`ROUTE_HIGH` accessors; the hand module restates the
routing keyed on each slot's bit-count class (deliberately not
through the gate, proving the gate redundant with the per-slot
rule) and proves the refinement, the both-scalar-zero law, the
gate-iff law, the sub-word drop law, the only-high/only-low/
both-preserve examples, the w64-only routing law, the slot-count
pin, the opcode pin with in-range bound, and two canonical
examples. The host oracle forks a child per case over all 256
opcodes crossed with the four widths and the four tag-class pairs
(4096 cases): a known pair load must match the independent
per-slot oracle and an unknown opcode must abort with SIGABRT
through the generated unsupported arm.

### Step 0200 — AArch64 memory-space dispatch mutation coverage

The `arm64_mem_dispatch` contract (`arm64_mem_dispatch_spec.json`
1 line, `generate_arm64_mem_dispatch_spec.py` 195 lines,
`generated/arm64_mem_dispatch.h` 54 lines,
`KProgFormal/GeneratedArm64MemDispatch.lean` 47 lines,
`KProgFormal/Arm64MemDispatch.lean` 73 lines,
`test_arm64_mem_dispatch_host.c` 105 lines) fixes the closed
four-space classification of every load base register: a stack or
stack-pointer base reads through the stack helper and keeps the
stack value tag; an ABI base at width 64 does a pointer load tagged
with the ABI kind; a reloc-address base at width 64 reads the base
pointer tagged as a map pointer; every other base does the ordinary
load and yields a scalar tag, and no space changes its selection off
width 64 (the no-widening property the C chain relies on after its
stack test). The generated side carries the `Space`/`ValueSrc`/
`ResultTag` inductives plus the exhaustive Peano tables `valueSrc`/
`valueTag` in Lean and the `KPROG_ARM64_MEM_SRC_*`/`KPROG_ARM64_
MEM_TAG_*` define families plus the if/else-chain
`KPROG_ARM64_MEM_READ_SRC`/`KPROG_ARM64_MEM_READ_TAG` macros in C;
the hand module restates the classification as predicate nestings
(the C chain's shape), proves the two refinements over all spaces
and both widths, the no-widening law, the stack width-independence,
and the reloc behaviors. The host oracle is an independent predicate
nesting sweeping is_sp x 9 tags x 4 widths (72 cases) and checks
src/tag against it plus the src/tag family-split invariant.

`build/mut_arm64_mem_dispatch.py` (64 rows) perturbs the six files
with the three detectors: 11 catch at the generator stage (the
spec's operation/stack-row/normal-row/ABI-w64/reloc-tag drifts and
the generator's operation repaint, ABI-row tag drift, order-check
inversion, Peano upper-key row drift, fallback repaint, w64-only
filter inversion, and path repoint), 12 catch through the Lean chain
(the space enumeration drift, five Peano-row repaints, the two
predicate-nesting repaints, the no-widening and reloc-law statement
repaints, and the generated-module repoint), and 20 catch by the
host oracle (the first-chain `||`→`&&` repaint, the ABI branch's
tag/width/assignment repaints, the reloc branch's chain repaint,
the tag-chain assign repaints, both else-arm repaints, and the
oracle repaints). 21 rows survive as documented equivalences: three
unreachable error-message repaints, five consumers-free theorem
renames (both refines, no-widening, stack width-independence, and
the reloc law), eight coherent define renumberings (`0U`→`5U` on
the SRC/TAG identifiers) that the reflected oracle and
family-split check both consume as renamed, the swapped src/tag
macro reads whose two code families coincide numerically, and the
sweep-shape repaints the all-equal oracle cannot distinguish (an
extra ninth tag, a duplicated width column, and the OK-line
message).

`build/mut_arm64_pair_load_tag.py` (75 rows) perturbs the six
files with the three detectors, all untracked, 75 single-anchor
rows: 18 catch at the generator stage (the operation/opcode/slot
drifts, the name/slot-count and preserve-rule check repaints, the
rendered Lean code and C static-assert/case-label drifts, the
gate loose-end repaint, the low-or-set-bit swaps, and the
generated-module repoint), 19 catch through the Lean chain (the
generated code/slot repaints, the slotPreserve width repaint, the
gate condition swap, the complement/shift/false-through repaints
of the slot terms, the namespace drift, and the route-spec,
law, and example repaints on the hand side), and 26 catch by the
host oracle (the case/width drifts, the gate `&&`/`||` repaints,
the per-slot condition and bit-set swaps, the default-arm
repaint, the static assert, the route-define rename, the accessor
bit swaps, the header guard, the unsupported-arm undeclared
repaint, and the oracle/exit/waitpid repaints). 12 rows survive
as documented equivalences: five unreachable error-message
repaints, five consumers-free theorem renames (refines, gate-iff,
sub-word, w64-only, and the `33 ≤ code ≤ 34` range loosening
whose bound still holds), and two value repaints that keep the
protocol intact (the opcode loop window and the exit message).


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

The route-oracle sibling includes `kprog/x86/x86_sim_local_bpf.h` and drives
the *real* `X86_SIM_L_SET_SHIFT_FLAGS` wrapper as dispatched from
`case KPROG_X86_ALU_FLAG_ARM_SHIFT` in `X86_SIM_L_SET_ALU_FLAGS`, reproducing
the wrapper's input derivation (width narrowing, bit count, sign bit, masked
shift count), comparing the full register file and the four flags against an
independent walk written from the generated Lean semantics over 4 shift
tokens × 5 width codes × 8 lhs values × 11 rhs values × 7 result values
(6,504,961 routed cases), with rhs tables pinning count-zero preservation,
the count-one OF boundary, and the 31/32/63/64 mask-count boundaries.  A
72-mutation harness over the six observed surfaces --- 22 caught at the
spec/generator stage, 30 by the Lean chain, 13 by the host oracle, 4 by the
route oracle, and 3 genuine equivalences that survive --- closes the drift
paths between the generated header bytes and the shipped wrapper
(e.g. the count-guard survive-on-host/catch-on-route split, because only the
route grid covers rhs=0).

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
policy, both ISA flag-to-control-flow decisions, x86 width narrowing and the
x86 `BZHI`/`BZHI_MEM` two-input flag-block transition (and the simulator's
routing of the step's flags through the generated clear-`SF`/`OF`,
set-`CF`-from-count-versus-width, set-`ZF`-from-result-zero contract),
x86 effective-width resolution (and the simulator's routing of its
register/stack/flag/ALU/move/compare bodies through it), x86
logical/ADD/SUB/ADC/SBB flag production, x86 shift-flag production, the
x86 ALU op-step result composition (and the simulator's routing of the
`X86_SIM_L_EXEC_ALU_*` arm results through the generated 16-arm
`KPROG_X86_ALU_RESULT` contract), the routed `X86_SIM_L_EXEC_ALU_IMM`/`_REG`
arm bodies (dst/src lane reads, live-carry/borrow handler arms, flag wiring,
width-and-lane writeback), the x86 effective-address offset (and the
simulator's routing of `X86_SIM_L_MEM_OFFSET` through it),
x86 operand-register presence (and the simulator's routing of its memory-read,
MULX, MOVBE, LEA and ALU-memory bodies through it), x86 register-number
dispatch-cell binding (and the simulator's binding of its write/tag X-macro
dispatch and its `X86_SIM_L_REG_VALUE` read ternary chain to the generated cell
selector),
x86 helper-id dispatch-body binding (and the simulator's routing of its
`X86_SIM_BPF_CALL_ID` call ladder through the generated `KPROG_X86_HELPER_SLOT`
selector and its binding of its id defines to the generated helper table),
x86 `XCHG` resolved-width arm selection (and the simulator's routing of the
`X86_OP_XCHG` arm body through the generated full-width selector),
x86 `DIV` resolved-width quotient/remainder case selection (and the simulator's
routing of the `X86_OP_DIV` arm bodies through the generated width-keyed
selector),
x86 `MULX` resolved-width arm selection (and the simulator's routing of the
`X86_OP_MULX` arm body through the generated width-keyed selector),
x86 `SHLD`/`SHRD` immediate opcode-keyed body and flag-family selection (and the
simulator's routing of the arm body and its shift-flag family through the
generated opcode-keyed selectors behind the count-zero step gate),
x86 `POPCNT` flag-block transition (and the simulator's routing of the arm's
arithmetic flags through the generated clear-`CF`/`SF`/`OF`, set-`ZF`-from-
narrowed-source contract),
x86 `MOVZX`/`MOVSX` register opcode-keyed extension-shape selection (and the
simulator's routing of both the standalone `MOVX` body and its inline arm
through the generated opcode-keyed selector and its routing of both bodies'
source-width resolution through the generated `KPROG_X86_MOVX_SRC_WIDTH`
selector),
x86 `MOV_REG` width/register-keyed body selection (and the simulator's routing
of both the standalone `MOV_REG` body and its inline arm through the generated
selector),
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
`CMP_IMM`/`CMP_REG`/`TEST_IMM`/`TEST_REG`/`CMP_MEM_IMM`/`TEST_MEM_IMM`/
`CMP_MEM_REG`/`TEST_MEM_REG` left/right-source, flag-kind and displacement-kind
composition (and the simulator's routing of all eight bodies through the
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
the whole-program control-flow trace contract (and the simulator's per-edge
routing of both `X86_SIM_X86_JCC_IMPL` and `ARM64_SIM_A64_JCC_IMPL` through the
generated direction macros, proved equal to the architectural `branchPc` walk
for every direction shape and every per-edge direction policy),
the x86 little-endian memory
memory-source bit-test/zero-high-bits composition, the memory-source
multiply, the register-source multiply, two-destination `MULX`, and compare
compositions, and
AArch64 width, the AArch64 effective-width resolution (and the simulator's
routing of its dispatcher's single width-resolution site through it), generic
ALU handler writeback/path
`.D0`/`.Q0` vector memory-transfer (and the simulator's routing of all four
bodies through the `KPROG_ARM64_DQ_MEM_*` contract), `LDP`/`STP` pair-move
(and the simulator's routing of both bodies through the `KPROG_ARM64_PAIR_MEM_*`
contract), pre/post-indexed
address-writeback, load/store index-register presence, write-register
destination presence, register-number dispatch-cell binding,
vector-register-file half mapping, MVN/NEG unary-value, and
CNEG condition-gated negation, ORN complemented-logical-OR composition, ADRP
relocation-tag selection, STLXR exclusive-store-status encoding, MOV
provenance-path routing, sign-extending-load width selection, and plain-load
provenance preservation, pair-load provenance routing, FMOV
destination routing, conditional-select pointer-path routing, flag-family
operand-source selection, and the ALU-arm operand-source selection (and the
simulator's routing of the ALU arm's source decision through
`KPROG_ARM64_ALU_OPERAND_SELECT`),
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
instruction decoding/dispatch, helpers, or the full workload-derived instruction
subsets, or prove the paper's complete O1--O4 obligations. The proved branch
predicates and the AArch64 and x86 emitted-shape bridges are local control-flow
refinements (one conditional edge at a time); the whole-program control-flow
trace contract chains those edges over arbitrary-length paths, but the emitted
shapes are still not tied to concrete native instruction bytes.

### Step 0201 — AArch64 stack-arena mutation coverage

The `arm64_stack_arena` contract (`arm64_stack_arena_spec.json`
1 line, `generate_arm64_stack_arena_spec.py` 112 lines,
`generated/arm64_stack_arena.h` 11 lines,
`KProgFormal/GeneratedArm64StackArena.lean` 16 lines,
`KProgFormal/Arm64StackArena.lean` 105 lines,
`test_arm64_stack_arena_host.c` 231 lines) fixes the two
overlapping views over the one union storage of the simulator's
stack: the byte arena `b[]` indexed directly by the 32-bit stack
byte index and the word arena `q[]` indexed by that index shifted
right 3, usable only under the low-three-bits alignment guard so
the 64-bit fast path skips no byte, plus the slot count a byte
capacity rounds up to (`+7 / 8`, exactly 20 slots for the enabled
160-byte arena and one slot even for the disabled 1-byte arena,
so the word view always covers the byte view). The generated side
carries three Lean definitions (`wordIndex` shift, `wordAligned`
mask test, `words` round-up) and the four C macros
`KPROG_ARM64_STACK_WORD_INDEX`, `_WORD_ALIGNED`, `_WORDS`,
`_TAG_SLOTS`; the hand module restates each independently
(division, remainder, shift-plus-carry round-up instead of the
generator's `+7` fold) and proves the three refinements, the
views-coincide property, the byte lane-0 agreement with the
byte-lane contract, and six canonical examples. The host oracle
drives the generated macros over 70558 cases: an index/capacity
grid with independent division/remainder/round-up restatements,
coverage and tightness bounds, a word round-trip through the
byte-lane contract, an aliasing sweep of a filled arena, and an
exhaustive 256x256 sweep of indices, capacities, and words.

`build/mut_arm64_stack_arena.py` (62 rows) perturbs the six files
with the three detectors: 16 catch at the generator stage (the
four spec-field drifts and expected-field drifts and both
rendered-C/Lean template repaints), 17 catch through the Lean
chain (the namespace drift, all three generated definitions, all
three independent restatements, the views-coincide goal, the
module open list, and every canonical-example value), and 15
catch by the host oracle (the generated C macro bodies that the
oracle exercises, every per-case check, and the grid tables). 14
rows survive as documented equivalences: two unreachable
error-message repaints, four consumers-free theorem renames (the
three refinements and views-coincide), the doc-comment shift
repaint Lean cannot see, the header-guard repaint no detector
compiles, the sweep-shape grid repaints (a dropped index, a zero
capacity, a duplicate index, a plus-seven capacity shift, and a
zero-capacity append the round-up absorbs), and the OK-line
message.

### Step 0202 — AArch64 flag-operand mutation coverage

The `arm64_flag_operand` contract (`arm64_flag_operand_spec.json`
1 line, `generate_arm64_flag_operand_spec.py` 188 lines,
`generated/arm64_flag_operand.h` 59 lines,
`KProgFormal/GeneratedArm64FlagOperand.lean` 52 lines,
`KProgFormal/Arm64FlagOperand.lean` 90 lines,
`test_arm64_flag_operand_host.c` 92 lines) pins the ISA decision the
six NZCV-producing AArch64 flag-arm pairs
(`SUBS`/`ADDS`/`CMP`/`TST`/`ANDS`/`CCMP`) share: the `_IMM` member of
each pair selects the decoded immediate as the right-hand operand and
every other opcode selects the caller-supplied register expression.
The generated side carries a twelve-constructor `FlagOp` enum with its
opcode `code` table and the `immediate` selection match, plus a
twelve-entry `_Static_assert` block and a six-case
`KPROG_ARM64_FLAG_RHS` statement-expression switch; the hand module
restates the selection independently (a membership test over named
immediate and register lists, structurally separate from the
generated per-constructor match) and proves the refinement on all
twelve opcodes, the immediate iff-membership biconditional, the
register-only rule, list disjointness, one immediate and one register
member per family, the full code dispatch, the 66-bounded code range,
and three canonical examples. The host oracle sweeps all 256 opcode
byte values (5120 cases) with distinct immediate and register
constants: an immediate-form opcode must return the immediate,
everything else the register expression.

`build/mut_arm64_flag_operand.py` (69 rows) perturbs the six files
with the three detectors: 19 catch at the generator stage (all six
spec opcode drifts plus the operation repaint and the expected-field
drifts at both the compared dict and every rendered Lean and C
template), 22 catch through the Lean chain (the namespace and
inductive repaints, every code and selection row of the generated
match, every hand independent restatement, the exclusive-pairs and
example values, and the module open list), and 8 catch by the host
oracle (the generated case labels and macro name the oracle exercises,
the oracle's own case labels, selection variables, and mismatch
verdict). 20 rows survive as documented equivalences: five unreachable
generator error-message repaints, ten consumers-free hand theorem and
example renames (no module imports the hand module; its own bodies
still check), the header-guard repaint no green detector compiles,
the host sweep-value repaints (distinct immediates and registers and a
shrunken opcode range whose verdicts are already equal — the six
immediate codes all lie below 128), and the OK-line message.

### Step 0203 — AArch64 FMOV direction mutation coverage

The `arm64_fmov` contract (`arm64_fmov_spec.json` 1 line,
`generate_arm64_fmov_spec.py` 186 lines,
`generated/arm64_fmov.h` 55 lines,
`KProgFormal/GeneratedArm64Fmov.lean` 40 lines,
`KProgFormal/Arm64Fmov.lean` 83 lines,
`test_arm64_fmov_host.c` 120 lines) pins the AArch64 FMOV value
routing between the vector register `v0` and a general-purpose
register across the four directions (`D_FROM_X`, `X_FROM_D`,
`S_FROM_W`, `W_FROM_S`, codes 0..3): the vector-destination
directions select the source register, the register-destination
directions keep `v0`, a code outside the four reaches the
caller-supplied unsupported arm, and the caller applies the width
(`writesReg` selects the caller's `narrow`). The generated side
carries the four-constructor `Fmov` enum with its `code`,
`mnemonic`, and `writesReg` tables and the `value` selection match,
plus two `_Static_assert` rosters (drift and coverage), the
`KPROG_ARM64_FMOV_HANDLED` macro, and the four-case
`KPROG_ARM64_FMOV_VALUE` statement-expression switch with the
unsupported default; the hand module restates the routing
independently (a two-destination disjunction that narrows through an
explicit `narrow`) and proves the refinement over all four
directions and widths, the code range, the per-arm code/write
dispatch, the vector- and register-destination value identities, and
two round-trip/narrowing examples. The host oracle sweeps the four
directions over a value-table grid plus a 20000-case fixed-seed
random sweep and requires a code outside 0..3 to abort through the
generated unsupported arm (20145 cases).

`build/mut_arm64_fmov.py` (70 rows) perturbs the six files with the
three detectors: 21 catch at the generator stage (the spec direction
code and writes_reg drifts plus the operation repaint, and every
expected-row and rendered Lean/C template repaint), 18 catch through
the Lean chain (the namespace and inductive repaints, every code and
writesReg row, every value-selection row, the hand disjunction, the
narrow widths, every hand theorem body and example value, and the
module open list), and 11 catch by the host oracle (the generated
case/label result assignments and macro names the oracle exercises,
the oracle's own direction table, return selection, mismatch
verdict, macro calls, unsupported-arm exit, and remapped direction
calls). 20 rows survive as documented equivalences: six unreachable
generator error-message repaints, the header-guard repaint no green
detector compiles, the two generated-mnemonic string repaints no Lean
module and no C path consume, nine consumers-free hand theorem renames
(no module imports the hand module; its own bodies still check), the
host sweep repaints (a remapped direction call, a remapped grid call,
and a swapped value-table entry whose verdicts are already equal),
and the OK-line message.

### Step 0204 — AArch64 NZCV flags mutation coverage

The `arm64_flags` contract (`arm64_flags_spec.json` 1 line,
`generate_arm64_flags_spec.py` 163 lines,
`generated/arm64_flags.h` 48 lines,
`KProgFormal/GeneratedArm64Flags.lean` 48 lines,
`KProgFormal/Arm64Flags.lean` 128 lines,
`test_arm64_flags_host.c` 163 lines) pins the AArch64 NZCV flag
transitions shared by the three families — ADD/ADD-immediate (C is the
unsigned carry-out, V the signed overflow), SUB/CMP/SUB-immediate (C is
NOT borrow, i.e. lhs >= rhs, V the signed overflow), and logical
AND/ORR/EOR/BIC/MOV/TST (C and V cleared) — over the four widths, all
computed from width-narrowed operands. The spec is an exact-match dict
(families table, width_rule, overflow doc) verified byte-for-byte by
`load()`; the generator re-renders the whole generated module and header
and `--check` compares rendered text. The generated side carries the
`KPROG_ARM64_SET_ADD_FLAGS`/`SET_SUB_FLAGS`/`SET_LOGIC_FLAGS` macros
(the four NZCV assignments per family) and the Lean
`addCarry`/`addOverflow`/`applyAdd`/`subCarry`/`subOverflow`/`applySub`/
`applyLogic` definitions; the hand module restates the same NZCV
statement independently as the `Arm64NzcSpec` record plus the
`arm64{Add,Sub,Logic}Nzc` constructions and proves the three
refinements by `cases width <;> rfl`, then five canonical examples
(carry w64, sub-zero w64, signed-overflow w32, borrow w64,
logical-clears w32) each by `native_decide`. The host oracle checks all
three families against an independent `__int128` oracle over 12
boundary vectors across 4 widths plus a 20000-case fixed-seed random
sweep (60144 cases).

`build/mut_arm64_flags.py` (65 rows) perturbs the six files with the
three detectors: 9 catch at the generator stage (the spec family
carry/overflow/opcode/width-rule/overflow-doc repaints and the
expected-dict value drifts) and 53 catch downstream (22 through the
Lean chain: the namespace and structure repaints, every generated and
hand add/sub/logic definition, the generated and hand masked-equality
overflow conditions, the hand refines theorem renames that Arm64AluResult
Lean chain, host oracle split: refines theorem
generated macro repaints per family, the per-family refactor
cross-family macro-name repaints, the malformed-include and macro-call
repaints, the per-family mismatch-condition repaints, the mismatch-
table remap, the widths repaint, and the include repaint). 12 rows
survive as documented equivalences: two unreachable generator
error-message repaints, the header-guard repaint no green detector
compiles, three consumers-free hand renames (add/sub/logic refines;
no module imports the hand module), the `native_decide` -> `decide`
tactic swap (both discharge every example), the host add-carry
`!= 0` -> `== 1` narrowing (the shifted sum is 0 or 1), the
width-sequence remap and widths-table swap (verdicts are re-derived
identically from the repainted inputs), and the OK/FAILED message
repaints.

### Step 0205 — AArch64 ORN mutation coverage

The `arm64_orn` contract (`arm64_orn_spec.json` 1 line,
`generate_arm64_orn_spec.py` 201 lines,
`generated/arm64_orn.h` 44 lines,
`KProgFormal/GeneratedArm64Orn.lean` 30 lines,
`KProgFormal/Arm64Orn.lean` 82 lines, `test_arm64_orn_host.c` 177
lines) pins the single AArch64 complemented logical OR arm
(`orn_reg`, opcode 53 aka `ARM64_OP_ORN_REG` 0x35U): the value is the
OR of the first source with the bitwise complement of the already
source-modified second source, narrowed to the destination width, the
complement inlined so the C macro needs no helper; an opcode outside
the family reaches the caller-supplied unsupported arm and no arm
writes NZCV. The spec is an exact-match dict verified byte-for-byte
plus an opcode drift cross-check against `kprog/arm64/arm64_sim.h`;
the generator re-renders the whole generated Lean module and C header
and `--check` compares byte-for-byte. The generated side carries the
one-constructor `Orn` enum (`code` 53, `mnemonic` "ORN",
`value` the `narrow (lhs ||| ~~~rhs)` match, `flagsUnchanged` true)
and the `KPROG_ARM64_ORN_VALUE` macro (the `case 53U` arm over the
width mask with the outer `UNSUPPORTED` arm). The hand module restates
the arm independently in its De Morgan complement form
`narrow (~~~((~~~lhs) &&& rhs))`, proves the refinement by
`cases op <;> cases width <;> simp only [...]; bv_decide` (the De
Morgan identity between the two operand forms is discharged the same
way), and adds the code-range/dispatch statements (53 within [53,53]),
the flags-unchanged statement, the zero-operand identities all-ones
and complement, the w32 upper bound, and two canonical examples
(0xf0 complemented with 0x0f, the w32 truncation) by
`native_decide`. The host oracle checks the macro against an
independent `(1 << bits) - 1` mask oracle that cross-checks both
forms `lhs | ~rhs` and `~(~lhs & rhs)`, over the 10x10 boundary-grid
vectors across every modifier code (11 mods, composed through
`KPROG_ARM64_MOD_VALUE`) across 4 widths plus a 40000-case fixed-seed
random sweep plus the unsupported-abort check (40401 cases).

`build/mut_arm64_orn.py` (50 rows) perturbs the six files with the
three detectors: 11 catch at the generator stage (the generated Lean
code-line and mnemonic templates, the generated C arm and
handled-predicate templates, and the expected-dict/spec drifts), 8
catch through the Lean chain (the namespace, one-constructor enum,
code, value-arm, and flags-arm repaints in the generated module; the
hand spec rename to `arm64OrnXSpec` and the De Morgan hand-statement
repaints; the open-line rename; the goal repaints the checker
catches), and 10 catch by the host oracle (the static-assert and
handled/coverage/case-label repaints, the macro-body repaint, the
value-decl repaint, the include repaint, the De Morgan oracle
repaints, the direct-form repaint, and the cond repaint). 21 rows
survive as documented equivalences: six unreachable generator
error-message repaints, the generated-mnemonic string repaint no Lean
or C consumer reads, the header-guard repaint, nine consumers-free
hand renames (no module imports the hand module; its own refines and
De Morgan proofs re-discharge), the code-range 53-to-52 weaken (still
a true, decide-provable statement), the canonical-main 0x0f-to-0x1f
repaint (0xf0 complemented with 0x1f is still 0xfffffffffffffff0),
and the OK/FAILED message repaints.






### Step 0237 — x86 popcount SWAR mutation coverage

The popcount contract pins the 64-bit population count the simulator's POPCNT handler applies to the narrowed source operand: `kprog_x86_popcount_value` and `GeneratedX86Popcount.value` are the standard SWAR reduction (the pairwise `v1`/`v2`/`v3` masking steps, then the byte-gather multiply shifted right by 56), and the hand module (`X86Popcount.lean`) states the independent claim as eight byte lanes (`laneByte` extracts `x >>> 8*i` masked to `0xff`, `bytePop` walks the eight bits explicitly with no shared constant) whose per-lane counts sum via `setWidth 64` (`x86PopcountSpec`) — proving `x86_popcount_refines` by `bv_decide` over the two unrelated encodings, plus the bounded (≤64), zero, one-bit, all-bits, and alternating canonical theorems. The single-line spec pins the schema/operation metadata and the SWAR shape fields (bits 64, lanes 8, shape `swar`); the generator re-checks the whole expected dictionary exact and renders `GeneratedX86Popcount.lean` and `generated/x86_popcount.h` byte-for-byte. The macro is consumed in `x86_sim.h`'s `x86_popcount64` (the `KPROG_X86_DISP_POPCNT_HANDLED` arm of the local-BPF dispatch applies it), by the dispatch-singleton route host, and by a dedicated contract host sweeping both a boundary vector set and a 20000-iteration LCG sweep against a one-bit-at-a-time oracle, with an additive split-consistency check. `build/mut_x86_popcount.py` (untracked) runs 45 rows over the six files with three detectors (`gen` byte-exact check; `lean_chain` = `lake build KProgFormal.X86Popcount` olean refresh then `lake env lean` over the hand module itself — popcount has no downstream handler Lean consumers; `host`). 35 rows catch (25 at the generator stage covering the spec fields, the byte-exact renders, header bytes, and the SWAR bit-mask arms; 8 through the Lean chain — the `laneByte`/`bytePop` helpers, the per-lane sum, and the `x86_popcount_refines` rename; 2 in the contract-host sweep — the oracle walk's bit mask and the split-consistency operator) and 10 survive as documented equivalents: the two failure-path-only generator message repaints, the bytePop lane-0-swap and lane-7-drop mutations (same lane sum, so the refinement proof still closes), five consumer-free hand-theorem renames (`bounded`, `zero`, `one`, `full`, `alternating`), and the two host OK/FAIL banner repaints no consumer validates. Two consecutive green shakes reported `ALL AS EXPECTED`; all six watched files byte-identical after each run (popcount watchlist verified); `make check` stayed at 210 `: OK`.

### Step 0281 — x86 stack-index map contract

The stack-index contract fixes the frame-offset-to-arena-index map:
`x86_stack_index_spec.json` pins the `capacity` index base, unit
step, `wrapping64` accumulation, and 32-bit mask;
`generate_x86_stack_index_spec.py --check` byte-re-renders
`generated/x86_stack_index.h` (the `KPROG_X86_STACK_INDEX` macro) and
`KProgFormal/GeneratedX86StackIndex.lean` (the
`(capacity + off).truncate 32` map). The hand
`KProgFormal/X86StackIndex.lean` records the affine
`capacity - base + delta` statement, frame-base-at-zero,
top-at-capacity, the mod-2^32 wrap, aliases, and an example.
`build/mut_x86_stack_index.py` (untracked, census 154 -> 155) plants
19 rows over the five-file watchlist: `--check`, two `lake env lean`
elaborations, and the compiled pinned-OK-banner oracle (`x86 stack
index host cross-check: OK (690 cases)`). 13 catches (9 generator
byte-render rows, 3 Lean elaboration rows, 1 compiled-host drift) and
6 documented equivalences (green-run failure-path message repaints,
spec spacing, and theorem renames with no internal references). Four
byte-identical green shakes (`/tmp/run0281_{1..4}.txt`, all md5
`359c9b8ed37a4a16a8f755662b35ed74`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0279 — x86 shift-result semantics contract

The shift-result contract pins the five shift/rotate result
semantics: `x86_shift_result_spec.json` pins the operation set
`{shl, shr, sar, rol, ror}`, the `x86ShiftCount` count contract, the
`narrow` operand rule, and `unsigned_sign_fill` SAR;
`generate_x86_shift_result_spec.py --check` byte-re-renders
`generated/x86_shift_result.h` (the five
`kprog_x86_{shl,shr,sar,rol,ror}_result` static inlinings) and
`KProgFormal/GeneratedX86ShiftResult.lean` (the five `BitVec`
functions). The hand `KProgFormal/X86ShiftResult.lean` proves each
against an independent per-width statement
(`x86_{shl,shr,sar,rol,ror}_result_refines`) with concrete
rotate/width examples. `build/mut_x86_shift_result.py` (untracked,
census 152 -> 153) plants 25 rows over the five-file watchlist (the C
consumer is `x86/x86_sim.h`'s straight include, so no sim-header
watch): `--check`, two `lake env lean` elaborations, and the two
compiled pinned-OK-banner oracles (`x86 ror result host cross-check:
OK (20320 cases)` and `x86 memory-shift host cross-check: OK (21024
cases)`). 20 catches (15 generator byte-render rows, 3 Lean
elaboration rows, 1 compiled-host ror drift, 1 memory-shift host
drift) and 5 documented equivalences (green-run failure-path message
repaints, spec spacing, a theorem rename with references outside the
family's chain, and a doc-comment repaint). Four byte-identical green
shakes (`/tmp/run0279_{1..4}.txt`, all md5
`e93288fdbcbe63a163f2a08110147086`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0277 — x86 push/pop handler-composition contract

The push/pop contract pins one composition under two opcodes:
`x86_pushpop_spec.json` pins the opcode rows (PUSH `0x12`
pre-decrement / hardcoded-64, POP `0x13` post-increment /
flags-or-64), the step/width/flags define rows, and the eight-byte
stack step; `generate_x86_pushpop_spec.py --check` byte-re-renders
`generated/x86_pushpop.h` (the `_Static_assert` opcode pins and the
`KPROG_X86_PUSH_STEP_DIRECTION`/`_WIDTH_SOURCE`/`_FLAGS_WIDTH`
selectors) and `KProgFormal/GeneratedX86PushPop.lean` (the enums, the
two per-opcode tables, `flagsWidth`/`resolveWidth`, `stackStep`). The
hand `KProgFormal/X86PushPopHandler.lean` proves both tables equal
independent statements, pins the step-direction/width-source facts
independent, and derives the width/addr/rsp/frame round trips and
examples. `build/mut_x86_pushpop.py` (untracked, census 150 -> 151)
plants 35 rows over the six-file watchlist: `--check`, `lake build` +
two `lake env lean` elaborations, and the two compiled pinned-OK-banner
oracles (`x86 pushpop handler host cross-check: OK (463 cases)` and
`x86 pushpop route host cross-check: OK (31504 cases)` over the real
`X86_SIM_L_EXEC_PUSH_POP_STEP` composition). 29 catches (16 generator
byte-render rows, 6 Lean elaboration rows, 2 compiled-host macro
drifts, 5 route-host selector/sim drifts) and 6 documented
equivalences (green-run failure-path message repaints, spec spacing,
theorem renames with no internal references, and a doc-comment
repaint). Four byte-identical green shakes
(`/tmp/run0277_{1..4}.txt`, all md5
`7efd5de0fee0501628fe5ed7ba067de9`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0275 — x86 memory-index presence contract

The memory-index presence contract pins the addressing-mode index
selector the offset contract consumes: `x86_mem_index_spec.json` pins
the two arms (present at every non-sentinel index byte, absent at the
`0xff` sentinel) at `index_byte_bits 8`; `generate_x86_mem_index_spec.py
--check` re-derives the arm order/codes/flags and byte-re-renders
`generated/x86_mem_index.h` (the `KPROG_X86_MEM_INDEX_PRESENT`/`_ARM`
macros) and `KProgFormal/GeneratedX86MemIndex.lean` (the `Arm` enum,
`indexSentinel`, `absent`, and the `arm`/`present` selectors). The hand
`KProgFormal/X86MemIndex.lean` proves the selector equals the
independent `decide (indexByte != 0xff)` comparison and that the two
presence cases match the offset contract's `hasIndex` arms.
`build/mut_x86_mem_index.py` (untracked, census 148 -> 149) plants 35
rows over the six-file watchlist: `--check`, `lake build` + two `lake
env lean` elaborations, and the two compiled pinned-OK-banner oracles
(`x86 mem index host cross-check: OK (512 cases)` and
`x86 mem index route host cross-check: OK (957 cases)` — the latter
over the real `X86_SIM_L_MEM_OFFSET` bridge). 28 catches (19 generator
byte-render rows, 6 Lean elaboration rows, 1 compiled-host macro drift,
2 route-host selector/bridge drifts) and 7 documented equivalences
(green-run failure-path message repaints, spec spacing, theorem renames
with no internal references, and a doc-comment repaint). Four
byte-identical green shakes (`/tmp/run0275_{1..4}.txt`, all md5
`ef3656feeb417af1b4a156afa459fd9d`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0273 — whole-program control-flow trace contract

The control-flow trace contract pins the sequential composition the
emitted branch code threads through: `control_flow_trace_spec.json` pins
the one-line contract `{schema_version 1, operation controlFlowTrace,
composer sequential, fallthrough_step 1}`;
`generate_control_flow_trace_spec.py --check` re-derives the expected
dict and byte-re-renders `generated/control_flow_trace.h` (the
`KPROG_CONTROL_FLOW_SEQUENTIAL_STEP 1U` constant and the
`KPROG_CONTROL_FLOW_EDGE_NEXT(TAKEN, PC, TARGET)` conditional macro) and
`KProgFormal/GeneratedControlFlowTrace.lean` (the `fallthroughStep`,
`emittedStep`, `walk`, and `walkPolicy` folds, with `emittedStep` built
from `GeneratedX86BranchEmit.nextPc`). The hand
`KProgFormal/ControlFlowTrace.lean` states the architectural walk
independently (`archEdge` as `branchPc taken (pc + 1) target`, `archWalk`
folding it) and proves `control_flow_trace_{step,walk,walk_policy}_refines`
plus `control_flow_trace_walk_shape_irrelevant`: every emitted walk equals
the architectural walk for every direction shape and every per-edge
policy. `build/mut_control_flow_trace.py` (untracked, census 146 -> 147)
plants 37 rows over the five-file watchlist: `--check`, `lake build` +
`lake env lean ControlFlowTrace.lean`, and the two compiled
pinned-OK-banner oracles (`control flow trace host cross-check: OK
(845 cases)` over `KPROG_CONTROL_FLOW_EDGE_NEXT` itself and `control
flow trace route host cross-check: OK (3108 cases)` walking the direction
macro against both shape oracles). 31 catches (19 generator byte-render
rows, 9 Lean elaboration rows, 2 compiled-host macro drifts, 1
route-host step drift) and 6 documented equivalences (green-run
failure-path message repaints, spec spacing, the internally-unreferenced
`walk_policy`/`shape_irrelevant` theorem renames, and a doc-comment
repaint). Four byte-identical green shakes (`/tmp/run0273_{1..4}.txt`,
all md5 `08496835a03e16c5a6556e15d9235f06`) and the golden `make check`
gate (rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0271 — x86 shift-count masking contract

The shift-count masking contract pins the two-mask rule every shift,
double-shift, and rotate lane resolves through: `x86_shift_count_spec.json`
pins `{schema_version 1, operation x86ShiftCount, non_64_mask 31,
width_64_mask 63}`; `generate_x86_shift_count_spec.py --check` re-derives the
expectation dict and byte-re-renders both artifacts (`generated/x86_shift_count.h`
with the `KPROG_X86_SHIFT_COUNT(RHS, WIDTH) ((RHS) & ((WIDTH) == X86_WIDTH_64 ?
63U : 31U))` macro and `KProgFormal/GeneratedX86ShiftCount.lean` with the
`mask`/`count` BitVec 64 pair). The hand `KProgFormal/X86ShiftCount.lean`
proves `x86_shift_count_refines` against the refined modulo semantics
(`rhs.toNat % 64` at width 64, `% 32` otherwise) plus the strict bound, and
`X86ShiftFlags.lean` rewrites through the refinement. Every consumer is
observed: the generated `x86_shift_result.h` shift/rotate family masks through
the macro, the generated doubleshift helper's `k = KPROG_X86_SHIFT_COUNT(...)`
drives both oracle and simulator sides, `x86/x86_sim.h` wraps the macro in the
`x86_shift_count` route helper for the shift-flag block and the double-shift
immediate arm's nonzero gate, and `__x86_sh_count`/the imm-arm gate are the two
`x86_sim_local_bpf.h` call sites. `build/mut_x86_shift_count.py` (untracked,
census 144 -> 145) plants 56 rows over the seven-file watchlist (spec JSON +
generator + generated header + generated Lean + hand Lean + the two sim
headers): `--check`, a five-module `lake build` fan-in plus three `lake env
lean` elaborations (`X86ShiftCount`, `X86ShiftResult`, `X86ShiftFlags`), and
four compiled pinned-OK-banner oracles (`x86 doubleshift host cross-check:
OK (32544 cases)`, `x86 memory-shift host cross-check: OK (21024 cases)` —
its oracle masks 63/31 independently at its line 72 — `x86 shift flags route
host cross-check: OK (6504961 cases)`, and `x86 doubleshift arm route host
cross-check: OK (326703 cases)`). 50 catches (24 generator byte-render rows,
13 Lean-chain rows, 9 sim-header include/return/param and local-header call
drifts observed across the two route hosts, 4 compiled-host macro drifts) and
6 documented equivalences (green-run failure-path message repaints, the
no-consumer `x86_shift_count_bound` rename, a const-parameter helper repaint,
and comment repaints). Four byte-identical green shakes
(`/tmp/run0271_{1..4}.txt`, all md5 `bc29da1095fa18f097123210f359b153`) and
the golden `make check` gate (rc 0, 210 `cross-check: OK` banners, 0 error
lines, `0 core dumps` after the fork-abort host cleanup) pin the family.
Genuinely-surviving repaints stay visible: the `--check` stale-message text
and the spec-parse error message are green-run failure paths, the bound
theorem rename has no downstream consumer, and pure comment repaints in the
route arm are byte drift without behavior, so they are recorded as
equivalences rather than inflated into catches.

### Step 0296 - x86 chunked renderer

The chunked sub-renderer pinned end to end: the self-call-forced
multi-chunk path inside the x86 generator (`render_chunked_program` and
its helpers `flatten_chunk_insns`, `chunk_for_addr`,
`append_chunk_transfer`, `append_chunk_call`, the chunk-level `ret` arm
of `append_chunk_branch_or_ret`, and `render_chunk_function`) emitted
calls but no row mutated it; Step 0295 pinned the non-chunked pipeline.
`build/mut_x86_chunked_render.py` (untracked, harness census
169 -> 170) closes the gap with 25 rows over a one-file watchlist (the
x86 generator, byte-exact restore each row) and one in-process
detector: a battery over fixture `NativeInsn`s in a fresh
`python -B -c` interpreter with the module `__pycache__` purged around
every battery, all in-process (no objdump). The battery pins
`flatten_chunk_insns` (sequence stitching, fall-through next-addrs, the
none tail, the subroutine tag), `chunk_for_addr` (hit/hit/miss),
`append_chunk_transfer` (in-chunk `goto x86_l_7;` versus off-chunk
`return 153ULL;`), `append_chunk_call`'s four lines (rsp push,
`X86_SIM_L_STACK_WRITE` return-address write, depth increment, target
goto), the chunk-level `ret` emission line-for-line (depth-zero
PC_DONE guard, depth decrement, stack read, pointer pop, return), a
self-call-forced three-instruction full render with 18 text pins
(state-struct define, chunk function, depth inc, ret read, entry
loop, dispatch call, PC_DONE loop test, XDP abi kind, `xdp_abi` bind,
RAX write, license, prelude carry, case-12 transfer, PC_DONE default,
1027U iteration cap, state bind, pc init, tag stamp), a tc-kind
sibling, an 802-instruction program whose chunk boundaries emit the
`return 1922ULL;`/`return 3842ULL;` last-next tails, the else-done arm
text, and the external-jump ValueError. All 24 single-guard/constant
flips must break the battery (no equivalence rows): 25 caught; four
byte-identical green shakes (`TOTAL 25 mutations, 0 failures, 0
equivalence rows`, all md5 `f52a1e72b096e113050a91308809d596`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0385 - x86 write-one driver residual

The write-one driver residual the enc-driver battery leaves
unrowed: the 14-row untracked `build/mut_x86_write_one0385.py`
rows `write_one`'s head repaint, the bench-name pick, the
parse-proof-object payload tuple, the empty-insns raise, the
stage2-else kind pick, and the `render_program` write-text call,
plus the driver tail's `print(path)` tile and the argparse
constructor/options paint (micro-programs, output-dir,
proof-object-dir, config, only) and the parse-args call.
In-process battery pins the load-benches fixture (name/kind),
the written-path identity, the tc section/entry template, the
MOV_IMM payload inside the rendered source, the empty-insns
ValueError message, and the end-to-end main() run under a temp
argv (return code, printed path, generated-N summary) (count==1
anchors; 14 catches). Run `14/14 rows caught` with 3 clean rerun
shakes (census 258 -> 259); golden gate `make check` rc 0 with
210 `cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0403 - x86 branch-or-ret and config plumbing

The x86 step-lowering, branch-or-ret, and
config-plumbing cells the encode and branch batteries
leave unrowed: the 35-row untracked
`build/mut_x86_branch_cfg0403.py` rows the
append_encoded_step direct select, step-macro indent,
opcode, and flags payload repaints, the
append_branch_or_ret signature defaults (indent,
next-addr, call-functions, ret-statement,
return-targets), branch/jmp macro picks,
case-label/jmp-tile/jmp-label f-string tiles,
call-functions and next-addr gates, return-address
ValueError, next-addr hex, and append-step fallthrough
repaints, the program_kind tags/tc/xdp/cgroup-skb
return repaints, the load_benches signature/yaml/
bench-comp repaints, the source_prelude
signature/read/match/replace/include-literals/return
repaints, and the dst==src equal-arg zero. The battery
arms append_branch_or_ret directly over reloc-target
insns (subroutine jcc/jmp, jcc case, jmp, call tile,
three ValueErrors) plus a real source_prelude fixture
over a temp .bpf.c with a SEC banner, a real
load_benches fixture over a temp yaml, and
program_kind checks (count==1 anchors; 35 catches). Run
`35/35 rows caught` with 3 clean rerun shakes (census
276 -> 277); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0402 - x86 tail cells

The x86 generator tail cells the residual batteries
leave unrowed: the 15-row untracked
`build/mut_x86_tail_cells0402.py` rows the
proof_kind_for_source underscore sink and kind return
repaints, render_x86_subroutine's rodata-idents default
signature, call-functions keyword, and SUB_RET macro
repaints, the self-call gate's has-self-call,
reloc-none, branch-target-line, and for-item repaints,
write_one's kind/exit-addr/rodata16 keyword repaints,
and main's def, __main__ guard, and SystemExit
repaints. The battery pins the SUB_RET tile inside an
end-to-end render_program output, the
proof_kind_for_source kind identity, and a --help
subprocess over the generator entry (usage banner gates
the __main__ guard), beside the stubbed write_one pair
(count==1 anchors; 15 catches). Run `15/15 rows
caught` with 3 clean rerun shakes (census 275 -> 276);
golden gate `make check` rc 0 with 210 `cross-check:
OK` banners, final arm64 decode host 1410 cases.

### Step 0401 - x86 render residual

The x86 render residual the render body, chunked, and
driver batteries leave unrowed: the 24-row untracked
`build/mut_x86_render_resid0401.py` rows the chunk loop
break repaint, ret-statement default repaint,
annotated-fanout repaint, total-insns repaint,
entry-addr repaint, has-direct-branch-target gate
repaint, chunk-threshold gate repaint, xdp declare pick
repaint, sim-header path repaint, call-functions keyword
repaint, write_one output-path/prelude-gate/render-kwarg/
return repaints, and main mkdir, srcdir pick, only set,
written decl, bench loop, only filter, written append,
path loop, generated summary, and rc-0 return repaints.
The battery pins the xdp/tc/cgroup_skb declare picks,
the self-call fan-out, the chunked boundary fixture, the
stubbed write_one pair, and the end-to-end main run
including the rc-0 return (count==1 anchors; 24
catches). Run `24/24 rows caught` with 3 clean rerun
shakes (census 274 -> 275); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0400 - x86 render program body

The x86 non-chunked render_program body the chunk
batteries leave unrowed: the 28-row untracked
`build/mut_x86_render_prog0400.py` rows the
signature-default repaints, self-call gate repaint,
chunked fan-out repaint, addrs-exit repaint, subroutine
label map repaint, return-addrs fan-out repaint, stack
gates repaints, next-addrs map repaint, include repaint,
declare repaint, label repaints, append_branch_or_ret
argument repaints, exit tile repaints (label, comment,
ret), subroutine render gate, ret-dispatch repaints
(name, switch, case loop, close), the closing+license
repaints, write_one's empty-parse raise and kind pick
repaints, and main's print-loop repaint. The battery runs
render_program end to end over a stack fixture with a
subfunction and rodata plus a self-call fixture forcing
the chunked fan-out, a stubbed write_one pair (written
file, empty-parse ValueError), and an end-to-end main run
pinning the printed path and the generated summary
(count==1 anchors; 28 catches). Run `28/28 rows caught`
with 3 clean rerun shakes (census 273 -> 274); golden
gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0399 - x86 chunk driver tiles

The x86 chunked-render region the chunk batteries leave
unrowed: the 32-row untracked
`build/mut_x86_chunk_driver0399.py` rows
append_chunk_call's signature repaint,
append_chunk_branch_or_ret's signature repaint,
render_chunk_function's chunk-name/signature/switch-open/
case-head/default/last-next/ret-last/ret-done/return-next
repaints, and render_chunked_program's flat-chunk slicing,
addrs-set, call-targets fan-out, stack gates, lead-in,
first-address, max-steps, pc belt (iter guard, pc-done
gate, chunk call, else arm, beldone, pc-nonzero gate, RAX
write, X86 ret), and min/max/prefix belt repaints. The
battery runs render_chunked_program end to end over a
stack fixture (push, ALU, jmp, call into a subfunction,
ret) plus a 386-insn boundary fixture pinning the chunk
function head, the case/default switch, the boundary
return-next tile, the belt dispatch, and the stack and
RAX write tiles (count==1 anchors; 32 catches). Run
`32/32 rows caught` with 3 clean rerun shakes (census
272 -> 273); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0398 - arm64 render body tiles

The arm64 non-compact render_program body the render
batteries leave unrowed: the 8-row untracked
`build/mut_arm64_render_body0398.py` rows the next-by-addr
map repaint, the return-addrs fan-out repaint, the
return-cases define repaint, the case-tail repaint, the
case emit repaint, the rodata emit loop repaint, the
rodata low-half repaint, and the native-subroutine comment
repaint. The battery runs render_program end to end over a
two-function xdp fixture with rodata and a bl (pinning the
return-cases define and goto labels, the rodata constant,
the native subroutine comment, and the linked W tile) plus
a cgroup_skb variant pinning the SEC clause and the return
tile (count==1 anchors; 8 catches). Run `8/8 rows caught`
with 3 clean rerun shakes (census 271 -> 272); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0397 - arm64 interp loop arms

The arm64 compact interpreter-loop region the compact-render
batteries leave unrowed: the 36-row untracked
`build/mut_arm64_interp_loop0397.py` rows the ten step-field
load repaints, the OP kind-arm repaint, the op-switch
repaint, the loop-variable repaint, the case-head and
EXEC-fan-out repaints, the break repaint, the
JMP/JCC/CBZ/TBZ/CALL/RET/HELPER arm-head repaints, the JCC
eval repaint, the CBZ read/take repaints, the TBZ
shift/take repaints, the CALL lr/x30 repaints, the RET
lr-gate/pc/lr0/continue/RET repaints, the HELPER call
repaint, the else-arm and unsupported-opcode repaints, and
the linked-exit and return repaints. The battery runs
render_program_compact end to end over a mixed-branch
fixture (ALU add, b, b.eq, cbz, tbz, ret) and pins the load
fan-out, the OP switch case/EXEC tiles, the arm heads, the
linked W and RET tiles, and the return tile (count==1
anchors; 36 catches). Run `36/36 rows caught` with 3 clean
rerun shakes (census 270 -> 271); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode
host 1410 cases.

### Step 0396 - arm64 compact render head

The arm64 render_program_compact head region the
compact-render batteries leave unrowed: the 23-row
untracked `build/mut_arm64_compact_head0396.py` rows the
uses-stack scan repaint, the steps fan-out repaint, the
helper-set pick and kind-gate repaints, the used-ops sort
repaint, the ten ARM64_SIM_C_* kind-define repaints, the
stack define gate, the helper-defines extend repaint, the
helper-switch call repaint, the rodata emit loop repaint,
the step-table f-string repaints, the step-table struct
name repaint, the step emit loop and payload repaints, the
guard-limit repaint, and the pc-gate repaint. The battery
runs render_program_compact end to end and pins the xdp
render (entry macro, SEC clause, local header include, pc
init, guard limit, step table), the tc render with prelude
and rodata, the helper define, and the stack-define absence
on stack-free programs (count==1 anchors; 23 catches). Run
`23/23 rows caught` with 3 clean rerun shakes (census
269 -> 270); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0395 - arm64 compact_step signature tiles

The arm64 compact_step region the compact batteries leave
unrowed: the 12-row untracked
`build/mut_arm64_compact_sig0395.py` rows the signature
repaints (all_addrs, addr_to_index, helper_call,
rodata_idents, reloc_idents), the JCC CompactStep repaint,
the JMP arm repaint, the CBZ/CBNZ and TBZ/TBNZ kind picks,
the bl helper CompactStep repaint, the bl all_addrs gate
repaint, the bl CALL repaint, and the blr-not-taken repaint.
The battery calls compact_step directly over b.eq/b/cbz/
cbnz/tbz/tbnz/bl/blr/ret/add fixtures and pins the JCC/JMP/
CBZ/CBNZ/TBZ/TBNZ kinds and indexed targets, the HELPER and
CALL CompactSteps, the unsupported-call-target raise, the
unsupported-indirect-call raise, the RET kind, and the OP
kind (count==1 anchors; 12 catches). Run `12/12 rows
caught` with 3 clean rerun shakes (census 268 -> 269);
golden gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0394 - arm64 helper defines/switch

The arm64 compact-helper emission helpers the compact
batteries leave unrowed: the 12-row untracked
`build/mut_arm64_helper_switch0394.py` rows
compact_helper_defines' enumerate-loop repaint and the
per-helper define repaint, plus
append_compact_helper_switch's signature repaint and the
call-helper macro head/do/switch/case-head/case-tail/
default/brace/while tiles it emits. The battery calls
compact_helper_defines and append_compact_helper_switch
directly over two-helper and one-helper fixtures and pins
the indexed ARM64_SIM_C_HELPER defines, the trailing blank,
and the exact backslash-continued ARM64_SIM_C_CALL_HELPER
do/switch/case/default/while(0) switch text (count==1
anchors; 12 catches). Run `12/12 rows caught` with 3 clean
rerun shakes (census 267 -> 268); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode
host 1410 cases.

### Step 0393 - arm64 append_insn branch tiles

The arm64 append_insn region the decode/branch batteries
leave unrowed: the 18-row untracked
`build/mut_arm64_append_insn0393.py` rows the signature
repaints (all_addrs, next_addr, reloc idents), the comment
tile repaint, the jcc/jmp/cbz/cbnz/tbz/tbnz emit repaints,
the cbz and tbz macro picks, the bl helper-call emit
repaint, the bl call-target pick and gate repaint, the bl
call emit repaint, the blr helper-call emit repaint, the ret
emit repaint, and the run-op tail repaints (op line and
width/aux/imm line). The battery calls append_insn directly
over mov/b.eq/b/cbz/cbnz/tbz/tbnz/bl/blr/ret/add fixtures
and pins the comment tile, the exact JCC/JMP/CBZ/CBNZ/TBZ/
TBNZ emits, the helper-call emits, the CALL tile with the
return address, the unsupported-call-target raise, the RET
tile, and the RUN_OP3 tail (count==1 anchors; 18 catches).
Run `18/18 rows caught` with 3 clean rerun shakes (census
266 -> 267); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0392 - x86 chunk dispatcher tail

The append_chunk_branch_or_ret signature and tail tiles the
chunk-branch battery leaves unrowed: the 8-row untracked
`build/mut_x86_chunk_disptail0392.py` rows the
addrs/call/return/rodata signature repaints, the insn pick
repaint, the indent pick repaint, the nested and plain
chunk-transfer call repaints, the stack-read payload
repaints (ret-addr local and rsp pointer), the ret-addr
return repaint, and the run-op tail repaint. The battery
calls append_chunk_branch_or_ret directly over
mov/jmp/je/call/ret fixtures and pins the comment/run tiles,
the jcc tower and nested goto, the jcc-to-return done
return, the external-branch and external-jump raises, the
plain goto, the jmp-to-return done return, the call
stack-write/depth/return tiles, the ret tower (depth gate,
done return, depth decrement, stack read, rsp pop, ret-addr
return), and the full stack-read line (count==1 anchors; 8
catches). Run `8/8 rows caught` with 3 clean rerun shakes
(census 265 -> 266); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0391 - x86 render_program + ret dispatch

The x86 non-chunked program-render region the chunked and
driver batteries leave unrowed: the 25-row untracked
`build/mut_x86_render_retdisp0391.py` rows
`render_program`'s signature defaults repaints (subfunctions,
kind, exit_addr, prelude, rodata), the call filter repaint,
the exit-addr addrs repaint, the subroutine-label map
repaints, the return-addrs pick, the TC declare repaint, the
per-insn label pick and emit repaints, the branch-or-ret
kwargs repaints (ret_statement, return_targets), the
exit-block repaints (label, fallthrough text, ret tile), the
subfunctions branch repaint and render call repaints, the
ret-dispatch repaints (label, switch head, per-case emit,
addr iteration), and the terminal bracket and license tail
repaint. In-process battery pins the xdp render (entry
declare, mov tile, CALL tile, exit label and fallthrough
exit block, subroutine banner, SUB_RET tile), the
ret-dispatch switch and case tiles, the no-stack/no-exit
negatives, and the tc/prelude/rodata variants (count==1
anchors; 25 catches). Run `25/25 rows caught` with 3 clean
rerun shakes (census 264 -> 265); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode
host 1410 cases.

### Step 0390 - x86 chunked-program render residual

The x86 chunked-program region the chunk-render batteries
leave unrowed: the 44-row untracked
`build/mut_x86_chunked_resid0390.py` rows
`render_chunk_function`'s current-chunk set repaint, the
case-emit tile repaint, the default arm repaint, the
branch-or-ret call repaints (call and args) and the
last-next pick, the in-chunk gate repaint, the done and
next-addr return paints, plus `render_chunked_program`'s
head repaints (name, subfunctions, kind, prelude, rodata
params), the flatten pick repaint, the chunks/slice/range
repaints, the addrs repaint, the call-targets repaints and
flat-add, the flat bool repaint, the stack scans, the
mem-scan repaint, the rodata-ident repaint, the abi-pass
repaint, the chunk loop and render-chunk-function call
repaints, the first-addr and max-steps repaints, the main
tail's storage/bind/init/rdi/tag/pc/iter repaints, the
done-check and break repaints, the min/max addr repaints,
the prefix repaints (if/else-if chain, range gate, hi line,
chunk call), the one-done arm repaint, and the write/x-ret
repaints. In-process battery pins the chunk-0 render
(switch cases, default, depth gate, stack read/pop/ret
tiles), the full xdp/tc/cgroup renders (abi kinds, skb ctx
maps, the PC-loop else arm, the write-out and ret tiles),
the rodata emit, the stack/deep defines, a push render, the
400-insn next-addr return paint, the two-count done return
paint, and a direct render_chunk_function tile pair
(count==1 anchors; 44 catches). Run `44/44 rows caught` with
3 clean rerun shakes (census 263 -> 264); golden gate `make
check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0389 - arm64 render_program + driver tail

The arm64 non-compact program-render region the compact
batteries leave unrowed, plus the generate_one/main driver
tail: the 34-row untracked
`build/mut_arm64_render_driver0389.py` rows
`render_program`'s head repaint, the next-addr map repaints,
the return-addrs pick, the RETURN_CASES define and per-case
line paints, the rodata loop repaints, and the subroutine
banner, plus `generate_one`'s head repaint, the
proof-object-dir repaint, the parse pick, the source join, the
write call, the compact-render pick, the encoding repaint, and
the return, plus `main`'s head repaint, the parser repaint,
the output-dir/proof-object-dir/config/only/compact argument
paints, the parse-args pick, the output mkdir, the source-dir
pick, the stage2 branch repaint, the only-set repaint, the
written-list pick, the generate_one call repaint, the compact
kwarg repaint, the written loop repaint, the per-path print,
and the generated-N summary. In-process battery renders the
two-function fixture (mov-imm, bl, blr with a known helper
register, sp raw, ret, add, ret) via direct render_program
pins under the xdp/tc kinds and linked-exit/no-exit variants,
a generate_one run with a stubbed parse under a temp output
dir, and end-to-end main() runs over the only-filter and the
stage2-prelude branch (count==1 anchors; 34 catches). Run
`34/34 rows caught` with 3 clean rerun shakes (census
262 -> 263); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0388 - x86 chunk-plumbing helpers

The x86 chunk-plumbing region the chunk-render batteries leave
unrowed: the 27-row untracked
`build/mut_x86_chunk_plumbing0388.py` rows
`render_x86_subroutine`'s head repaint, the call-functions dict
pick, the addrs repaint, the banner payload, the per-insn label
emit, the branch-or-ret call repaint, the step-macro name tile,
the SUB_RET payload, and the join tail, plus
`flatten_chunk_insns`'s head repaint, the out and sequences
inits, the subfunction extend, the iteration repaint, the
next-addr pick, and the ChunkInsn append, plus
`chunk_for_addr`'s head repaint, the any-scan repaint, and the
index/None returns, plus `append_chunk_transfer`'s head
repaint, the in-chunk gate, and the goto/return tiles, plus
`append_chunk_call`'s head repaint, the rsp tile, the
stack-write payload, the depth tile, and the transfer call.
In-process battery pins the subroutine banner/labels/JMP/RET
tiles, the flatten output order, subroutine flags, and next
addrs, the chunk-for-addr hit/miss, the transfer
goto/return/indent outputs, the call rsp/stack-write/depth/
transfer outputs, and a RUN_OP bswap render (count==1 anchors;
27 catches). Run `27/27 rows caught` with 3 clean rerun shakes
(census 261 -> 262); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0387 - arm64 render_program_compact region

The arm64 compact program-render region the compact-step
battery leaves unrowed: the 18-row untracked
`build/mut_arm64_compact_render0387.py` rows
`render_program_compact`'s head repaint, the uses-stack scan
repaint, the step-ident repaint, and the dispatcher's JCC/CBZ/
TBZ shape tiles (JCC select, CBZ/CBNZ and TBZ/TBNZ kind gates,
the bit-test value payload, and the take paints), plus the
tail's C-call-helper repaint, the linked-exit gate, the exit
write payload, the no-exit return paint, the license closer
repaint, and the step-table header and C-step row paints.
In-process battery renders a two-function fixture (mov-imm,
b.eq, blr with a known helper register, sp raw, ret, add, bl,
ret) under the xdp/tc/cgroup-skb kinds and a linked-exit
variant, pinning the def/entry/section templates, the steps
array identity, helper names, the STACK define, the 72U guard
limit, the step-line, and the linked-exit write/ret tiles
(count==1 anchors; 18 catches). Run `18/18 rows caught` with 3
clean rerun shakes (census 260 -> 261); golden gate `make
check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0386 - arm64 compact step + helper defines

The arm64 compact region the compact-switch battery leaves
unrowed: the 22-row untracked
`build/mut_arm64_compact_step0386.py` rows `compact_step`'s
head repaint, the addr-to-index dict pick, the CompactStep
return-type repaint, the JCC/JMP repaints plus the COND
condition pick, the cbz/cbnz branch-target operand pick and
kind ternary, the cbz src-reg operand pick, the tbz/tbnz
branch-target and kind-ternary repaints plus the parse-imm
payload and src-reg operand pick, the bl/blr opcode gates, the
helper-symbol gate and helper-name payloads for both bl and
blr, the external-target check, the CALL target arithmetic,
the blr no-helper raise, the RET repaint, the OP-tail encode
payload repaint, plus `compact_helper_defines`'s head repaint,
the enumerate base and #define payload, and the `if lines:`
gate. In-process battery pins the
JCC/JMP/CBZ/CBNZ/TBZ/TBNZ/CALL/HELPER/RET/OP arm outputs
(kind, reg src, imm payload, helper name, target index), the
blr/bl raise messages, and the helper-defines list and
helper-switch banner lines (count==1 anchors; 22 catches). Run
`22/22 rows caught` with 3 clean rerun shakes (census 259 ->
260); golden gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0384 - x86 program render dispatch + native ret-dispatch

The program renderer's dispatch head and the native
ret-dispatch tail: the 35-row untracked
`build/mut_x86_program_render0384.py` rows `render_program`'s
head repaint, the subfunctions/kind/exit-addr/prelude/rodata
signature paints, the chunked-program fan-out gate repaint, the
self-call mnemonic gate repaint, the include header payload,
the subroutine label/count maps, the addrs/return-addrs/next-map
scans, the stack-gate paints, the label and declare emits, the
branch-or-ret payload repainting, the native-link exit lane
(addrs/label/comment/ret-statement), the ret-dispatch
head/switch/case/loop paint, and the closing extend repaint,
plus the chunked-program tail rows (chunk call repaint, pc-else
arm, PC_DONE repaint, done check, RAX width write, X86_RET
tile). In-process battery pins the xdp/entry template, the
call/jmp/ret macros, the subfunction banner and SUB_RET
dispatch cases, the exit lane, the self-call chunk fan-out, the
chunked tail rows, and the license closers (count==1 anchors;
35 catches). Run `35/35 rows caught` with 3 clean rerun shakes
(census 257 -> 258); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0383 - x86 chunked case-switch head

The chunked program's switch-case head and the entry-dispatch
lane: the 17-row untracked `build/mut_x86_chunk_render0383.py`
rows `render_chunk_function`'s head repaint, the function header
name/args repaints, the switch repaint, the case-label emit
repaint, the PC_DONE default repaint, the label emit repaint,
and the closing extend repaint, plus `render_chunked_program`'s
head repaint, the skb ctx/abi kind/state storage/bind repaints,
the addrs-set scan, the chunk-emitter dispatch, the first-addr
init paint, and the rdi abi/tag payload tile. In-process battery
pins the chunk-case switch rows, the entry template rows (pc
init, iter loop, break, chunk dispatch, RAX write, RET,
LICENSE), and the chunked program end-to-end (count==1 anchors;
17 catches). Run `17/17 rows caught` with 3 clean rerun shakes
(census 256 -> 257); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0382 - x86 subroutine walker + chunk flatten

The subroutine body walker and its chunk-item flatten: the
15-row untracked `build/mut_x86_subroutine0382.py` rows
`render_x86_subroutine`'s head repaint and count-annotate tail,
the native-subroutine banner and `x86_l_` label emits, the
`append_branch_or_ret` subroutine flag, the RUN_OP step-macro
and SUB_RET ret-statement repaints, the addrs-set scan, the
next-addrs map pick, plus `flatten_chunk_insns`'s head repaint,
the main-sequences init, the subfunction extend, the next-addr
payload, the chunked-loop tail, and `chunk_for_addr`'s head
repaint and in-chunk hit arm. In-process battery pins the
subroutine banner/label/MOV_IMM/CALL/SUB_RET/SUB_JCC emits, the
external-target raise, the register-call lane, the flatten
sequence payload, and the addr hits/miss (count==1 anchors; 15
catches). Run `15/15 rows caught` with 3 clean rerun shakes
(census 255 -> 256); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0381 - x86 chunked branch-or-ret + call stack

The chunked x86 renderer's branch/ret/call walker and its stack
plumbing: the 21-row untracked `build/mut_x86_chunk_branch0381.py`
rows `append_chunk_branch_or_ret`'s head repaint, the jcc gate with
its EVAL_CC return-target tile, the jcc/jmp external-target raises,
the jmp gate with its CHUNKED_PROOF_PC_DONE return tile, the call
gate repaint with the helper-symbol and register-operand arms and
their `append_encoded_step` tails, the `call_targets`+`next_addr`
gate feeding `append_chunk_call`, the ret arm's call-depth gate,
depth decrement, stack pop, and ret-addr return, plus
`append_chunk_call`'s rsp push, STACK_WRITE return-addr payload,
depth increment, and the `append_chunk_transfer` in-chunk goto /
out-of-chunk return arms. In-process battery drives the walker over
jcc/jmp (in-chunk, return-target, external-raise), the ret depth
chain, the bpf_/memcpy/register/absolute call lanes, and the chunk
call/transfer emit pairs (count==1 anchors; 21 catches). Run
`21/21 rows caught` with 3 clean rerun shakes (census 254 -> 255);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0380 - x86 direct-step + fixed-count annotator

The x86 generator head the specialization and count-annot
batteries leave unrowed beside their mnemonic gates: the 11-row
untracked `build/mut_x86_direct_step0380.py` rows the
DIRECT/AUX macro-table dict inits L931-932 (their MOV_IMM entry
deletions), the `direct_step_statement` aux gate L951, the AUX
`.get` pick L952, the aux-format dst field L956, the DIRECT
`.get` None-return gate L963-964, the direct-format dst/src
field tiles L967-968, and `annotated_fixed_count_ops`'s values
dict init L981, the `annotated = insn` default L984, and the
xor src canonical pick L1005. In-process battery pins the table
inits, the direct/aux template outputs (MOV_IMM and MOV_REG
with their field orders), the aux-miss fall-through to the
DIRECT template, and the fixed-count rep/call annotation truth
table (rcx/rdx counts, absent registers, xor-diff pops,
xor-self zeros) (count==1 anchors; 11 catches). Run `11/11 rows
caught` with 3 clean rerun shakes (census 253 -> 254); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0379 - arm64 append_insn + helper-calls walk

The arm64 generator tail the render and else batteries leave
unrowed beside their gate picks: the 12-row untracked
`build/mut_x86_arm_annot0379.py` rows the `helper_calls_by_addr`
copy-propagation tail (the mov-source gate L676, the register
copy L677, the helper-ident track L678; the stale-value pop and
the dict return repaint value-inert — waived) and `append_insn`'s
head banner L690, the jcc COND split L694, the tbz imm-operand
pick L708, the bl helper-symbol emit L712, the unsupported-call
raise gate L715, the next-addr call tile L717, the blr helper
emit L721, plus compact_step's bl helper tile L765 and RET kind
L775. In-process battery pins the jcc/jmp/cbz/cbnz/tbz/tbnz
branch emits, the bl helper/call/raise paths with the next-addr
tile, the blr helper emit, the ret lane, the RUN_OP3 fallback,
the helper_calls_by_addr copy chain (imm-then-copy reg_imms
carry to blr; helper-ident fallback through last_helper_imms
after a stale overwrite), and the compact bl/ret steps
(count==1 anchors; 12 catches). Run `12/12 rows caught` with 3
clean rerun shakes (census 252 -> 253); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode host
1410 cases.

### Step 0378 - x86 bitop shift tail arms

The x86 `encode()` bitop/shift tail arms the cmp/test and
body-mid batteries leave unrowed beside their cells: the
26-row untracked `build/mut_x86_arm_annot0378.py` rows the
mulx/andn/rep/bzhi picks and token pairs L767-820, the
bswap/popcnt/xchg/movbe tokens L828-856, the shiftx/rorx
op-set picks, ALU chooser tokens, and REG/MEM token pairs
L857-893, the div token L894, and the shld/shrd imm tokens
L903-908. In-process battery pins the mulx/andn/bzhi register
and memory tokens with SRC_SHIFT aux tiles, the rep movs
success/bound/variable-length paths, the movbe load/store
pair, the shiftx ALU tokens with packed mem immediates, the
rorx reg/mem pair, the xchg/div/bt register forms, and the
shld/shrd imm tokens (count==1 anchors; 26 catches). Run
`26/26 rows caught` with 3 clean rerun shakes (census
251 -> 252); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0377 - x86 cmp/test and ALU arms

The x86 `encode()` cmp/test and ALU arms the dispatch and
body-mid batteries leave unrowed beside their cells: the 24-row
untracked `build/mut_x86_arm_annot0377.py` rows the cmp/test
width default L632, imm/reg token picks L634/643, the imm lane
pick L636, the cmp-mem gate L646 with its REG_MEM token and
TEST_MEM_REG arm L658/659, the CMP/TEST_MEM_IMM token L665,
the unsupported-memory raises L671/744, the imul three-arg gate
and token pair L693/698/705, the ALU width-mismatch gate L717
and ALU_REG/ALU_MEM/ALU_MEM_REG/ALU_MEM_IMM tokens
L721/725/732/738, the unary inc/dec imm pick L689, and the bt
arm gate/token pair L747/753/758. In-process battery pins the
cmp/test token truth table with mem/reg/imm operand forms, the
alu unary/reg/mem tokens with ALU_OP aux tiles, the imul and
bt tokens, and the two unsupported-form raise messages
(count==1 anchors; 24 catches). Run `24/24 rows caught` with 3
clean rerun shakes (census 250 -> 251); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final
arm64 decode host 1410 cases.

### Step 0376 - x86 encode dispatch head

The x86 `encode()` dispatch head the driver and body-mid
batteries leave unrowed beside their cells: the 16-row untracked
`build/mut_x86_arm_annot0376.py` rows the jmp imm tile L471,
the jcc CC-guard L472, the call helper token L477, the
memcpy/memset reloc picks with their REG/imm tokens L478-489,
the call register pick L491, the direct-call token L494, the
push/pop register tiles L497/501, the setcc-mem token/aux
tiles L507/508, and the cmov-mem token L518. In-process battery
pins the jmp imm with and without operands, the jcc
condition-aux tokens, the call helper/memcpy/memset/register/
direct tokens and their imm payloads, the push/pop register
picks, the setcc-mem aux shift, and the cmov-mem token
(count==1 anchors; 16 catches). Run `16/16 rows caught` with 3
clean rerun shakes (census 249 -> 250); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final
arm64 decode host 1410 cases.

### Step 0375 - x86 encode body-mid residual

The x86 `encode()` body-mid residual the high-supported and
mem-terms batteries leave unrowed beside their arms: the 18-row
untracked `build/mut_x86_arm_annot0375.py` rows the cmov aux
shift pick L521 and reg-cmov return L525, the mov
MOV_LOAD_HELPER_ID token/imm tile L546/547, the scalar-rodata
raise tile L550, the MOV_LOAD_MAP_PTR token L551, the
MOV_LOAD token L553, the MOV_STORE_IMM token/imm tile
L560/563, the MOV_STORE_REG token/src tile L565/566, the
load-xmm arm token pair L579/581 and store-xmm token L584, the
MOVZX_REG pick L596, the movzx-mem MOV_LOAD token L602, the
cdqe rax/rax tile L610, and the lea rodata/mem return tokens
L620/623. In-process battery pins the cmov aux shift and reg
token, the mov helper/map/load/store tokens with their imm
payloads, the xmm load/store tokens with the rodata ident, the
movzx reg/mem tokens, the cdqe rax/rax tile, and the lea
rodata/mem tokens (count==1 anchors; 18 catches). Run
`18/18 rows caught` with 3 clean rerun shakes (census 248 ->
249); golden gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0374 - arm64 helper sub-decoders

The arm64 helper sub-decoder head the render/helper batteries
leave unrowed beside their picks: the 9-row untracked
`build/mut_x86_arm_annot0374.py` rows the blr_target_reg early
return L619, the written_gpr GPR write gate L623, operand head
L627, empty-gate L625, and dst strip L629, the mov_immediate
operand pick L639, the mov_source_gpr strip L649, the
helper_calls_by_addr reg_imms dict-init repaint L654, and the
arm64 `rodata_ident_map` reversed-enumerate repaint L361. 
In-process battery pins the blr x-strip, the written_gpr x/w
accepts and str/mov rejects, the mov_immediate #imm parse, the
mov_source_gpr x/w strips and immediate reject, the direct-blr
and register-copy helper_calls_by_addr paths, and the rodata
pair map (the `mov` mnemonic guards n=2 and the parse_imm
except repaint are inert — waived; count==1 anchors; 9
catches). Run `9/9 rows caught` with 3 clean rerun shakes
(census 247 -> 248); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0373 - x86 encode high-supported arms

The x86 `encode()` high-supported gate arms the dispatch and
encoder batteries leave unrowed beside their picks: the 7-row
untracked `build/mut_x86_arm_annot0373.py` rows the mov/movabs
arm op-set L446, the add/adc/sub/sbb arm op-set L450, the
cmp/test arm op-set L453, the dec/inc/neg/not arm op-set L456,
the setcc CC_AUX membership and `startswith("set")` picks L458
(two paints on one line), and the unsupported high-byte raise
message tile L463. In-process battery drives `encode()` on
high-byte register operands (ah/bh/ch) across the arms and pins
the op tokens (MOV_REG, MOV_IMM, MOV_STORE_REG, ALU_IMM, ALU_REG,
CMP_IMM, CMP_REG, TEST_IMM, SETCC), the gate raise for
mem+high-reg on add/adc/cmp, and the message tile text (count==1
anchors; 7 catches). Run `7/7 rows caught` with 3 clean rerun
shakes (census 246 -> 247); golden gate `make check` rc 0 with
210 `cross-check: OK` banners, final arm64 decode host
1410 cases.

### Step 0372 - x86 mem-terms head

The x86 memory-operand head the mem-terms battery leaves unrowed
beside its bracket/dash/index picks: the 12-row untracked
`build/mut_x86_arm_annot0372.py` rows the `parse_mem_terms`
defaults (base L367, index L368, disp L370), the star gate L372,
the scale split pick L373, the scale parse L377, the reg_info
call sites L374 and L380, the return quadruple L389, the
`mem_aux` src_shift emit L400, the `branch_target` hex-or-decimal
regex left arm L409, and the `rodata_ident_map` reversed-enumerate
repaint L435. In-process battery pins the `parse_mem_terms` truth
tables (rr16, only-base, scale, negative displacement through the
dash flip, non-bracket input), the `mem_aux` FULL/plain/src_shift
shapes, the `branch_target` hex/decimal/space parses, the rodata
pair map reverse, and the x86 helper-symbol truth table (the
`mem_disp` [3]->[2] pick is inert under the balanced truth table —
waived; count==1 anchors; 12 catches). Run `12/12 rows caught`
with 3 clean rerun shakes (census 245 -> 246); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final
arm64 decode host 1410 cases.

### Step 0371 - arm64 render head

The arm64 render head the render batteries leave unrowed beside
their picks: the 9-row untracked `build/mut_x86_arm_annot0371.py`
rows the compact `uses_stack` scan pick L822, the compact
section-entry dict xdp and tc rows L824-825, the non-compact
`next_by_addr` value pick L1013, the `bl` return-addrs gate
L1022 with its zz value repaint, the non-compact section-entry
dict xdp and cgroup_skb rows L1025-1027, and the rodata emit
block's `rodata_ident_map` reversed-input repaint L1044 — dict
block anchors separate the compact and non-compact twins.
In-process battery renders compact and non-compact programs from
synthetic NativeInsns and pins the helper emit, the stack define,
the section entry text, the return-case line, the `.maps` map,
the rodata pair order, and single-insn tc and cgroup_skb renders
(count==1 anchors; tc.sec/cg.sec pins added in paint round 3; the
compact cgroup repaint is inert — waived; 9 catches, no
equivalence rows). Run `9/9 rows caught` with 3 clean rerun
shakes (census 244 -> 245); golden gate `make check` rc 0 with
210 `cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0370 - x86 normalize/scalar tail

The entry-return normalize arms and the scalar/text interrogation
helpers the native-link and encoder-selection batteries leave
unrowed beside their picks: the 10-row untracked
`build/mut_x86_arm_annot0370.py` rows the normalize jmp pick
L258, the ret tag tile L265-267, the empty-operand tile L268-269,
the passthrough else append L270-271, the `is_helper_symbol`
prefix pick L319, the `parse_int` hex/decimal fork L324, the
`is_int` signed fullmatch L328, the `c_ptr_u64` cast shape L336,
and the `is_mem` bracket gates L344. In-process battery pins the
normalize output triple (ret rewrite with tag raw and empty
operands, passthrough identity, off-blob jmp kept), the helper
prefix truth table, the hex/decimal/negative parses, the
signed-int accept/reject row set, the pointer-cast shape, and the
memory-operand truth table (count==1 anchors; 10 catches, no
equivalence rows). Run `10/10 rows caught` with 3 clean rerun
shakes (census 243 -> 244); golden gate `make check` rc 0 with
210 `cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0369 - x86 native-link program tail

The `parse_native_linked_program` segmentation arms the
native-link batteries leave unrowed beside their gate picks: the
10-row untracked `build/mut_x86_arm_annot0369.py` rows the address
set L285, the exit fan-out head L287 and its conditional-jmp guard
L290, the operand guard L291, the sub pick's reloc-target
preference L296, the start admission L303, the entry exclusion
L304, the no-sub split L306-307, the sub-end boundary L313, the
empty-sub guard L314-315, and the sub-name tile L316. In-process
battery stubs `parse_native_link_blob` and pins the entry/sub
split under a mid-blob call, the off-blob jump extension, a call
whose direct operand disagrees with its reloc target, a call
landing on the entry address, and a sub boundary landing on the
section-size byte (count==1 anchors; 10 catches, no equivalence
rows). Run `10/10 rows caught` with 3 clean rerun shakes (census
242 -> 243); golden gate `make check` rc 0 with 210 `cross-check:
OK` banners, final arm64 decode host 1410 cases.

### Step 0368 - x86 rodata/section tail

The object-file section-reader free arms the native-link and
scalar-helpers batteries leave unrowed beside their gate picks:
the 7-row untracked `build/mut_x86_arm_annot0368.py` rows the
`section_size` hex return L167, its missing-section raise message
L168, the `rodata_bytes` failed-objdump early return L176, the
address-text hex gate L180, the byte-pair extend step L185, the
full-bytes return L186, and the `load_rodata16` no-data empty map
L190-192. In-process battery compiles a 16-byte
`.native_link_rodata` fixture and pins the hex size parse, the
raise message text, the failed-objdump empty map, the address-gate
rejection, the byte-pair little-endian assembly, the returned
bytes identity, and the symbol-pair tap (count==1 anchors; 7
catches, no equivalence rows). Run `7/7 rows caught` with 3 clean
rerun shakes (census 241 -> 242); golden gate `make check` rc 0
with 210 `cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0367 - x86 operand split

The `split_operands` depth-walk free arms the head-route and
scalar-helpers batteries leave unrowed beside the
depth-zero-comma gate pick: the 6-row untracked
`build/mut_x86_arm_annot0367.py` rows the bracket-open increment
L118, the bracket-close decrement L120, the split-append paint
L123, the boundary-advance L124, the tail strip L125, and the
tail-if guard L126-127. In-process battery pins the bracket-comma
retention pair, the bracket-boundary split, the bracketed-comma
part paint, the three-operand boundary advance, the whitespace
strip, and the trailing-comma empty-tail drop (count==1 anchors;
6 catches, no equivalence rows). Run `6/6 rows caught` with 3
clean rerun shakes (census 240 -> 241); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode host
1410 cases.

### Step 0366 - x86 parse-row tail

The x86 parse-row tail free arms the head-route and parse-asm
batteries leave unrowed beside their push picks: the 2-row
untracked `build/mut_x86_arm_annot0366.py` rows the `addr_text`
strip L142 and the empty/angle-bracket asm skip L149-150.
In-process battery pins the padded-prefix address parse, the
comment-only field skip, and the angle-bracket field skip
(count==1 anchors; 2 catches, no equivalence rows). Run `2/2 rows
caught` with 3 clean rerun shakes (census 239 -> 240); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0365 - x86 parse-asm rows

The x86 objdump row-walk free arms the head-route battery leaves
unrowed beside its colon/reloc picks: the 6-row untracked
`build/mut_x86_arm_annot0365.py` rows the no-colon skip L139, the
hex-prefix fullmatch L143, the tab-field split L145, the `lock`
prefix consume L151, the lowercase-mnemonic match L153, and the
NativeInsn push with its hex address parse L156. In-process battery
pins the no-colon skip, the hex and non-hex prefix pair, the
2-field skip, the lock-prefix mnemonic rewrite, the
uppercase-mnemonic reject, and the emitted record's addr/raw
fidelity (count==1 anchors; 6 catches, no equivalence rows). Run
`6/6 rows caught` with 3 clean rerun shakes (census 238 -> 239);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0364 - x86 memory terms

The x86 memory-term parse free arms the operand-wrappers and
scalar-helpers batteries leave unrowed: the 5-row untracked
`build/mut_x86_arm_annot0364.py` rows the `parse_mem_terms` bracket
regex L363, its dash-to-`+-` negate trick L366, the else-index
register pick L384-385, the `mem_aux` FULL-width emit L396, and the
plain `mem_aux` emit L398. In-process battery pins the greedy
two-bracket scan, the scale/index/disp quadruple over a
scaled-negated operand, the register-only and no-bracket baselines,
the else-index pick, the FULL-width aux string, the plain aux
string, and the SRC_SHIFT wrap (count==1 anchors; 5 catches, no
equivalence rows). Run `5/5 rows caught` with 3 clean rerun shakes
(census 237 -> 238); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0363 - arm64 compact step table

The arm64 compact-render free arms the render-unit and
render-pipeline batteries leave unrowed: the 7-row untracked
`build/mut_x86_arm_annot0363.py` rows the compact step-table
fan-out head and tail L914-916, the guard-loop limit and pc check
L928-931, the step fetch L933, the per-op L_EXEC emit L954, and the
`uses_stack` scan L822. In-process battery pins the MOV_REG and JCC
step rows with their COND_EQ target, the guard limit 24 and pc
check 3 arithmetic, the step fetch ident, the L_EXEC dispatch, the
xdp section lane, and the ENABLE_STACK presence/absence pair
(count==1 anchors; 7 catches, no equivalence rows). Run `7/7 rows
caught` with 3 clean rerun shakes (census 236 -> 237); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0362 - arm64 helper switch

The arm64 helper-define and compact-switch free arms the emit-ops
and render-unit batteries leave unrowed: the 4-row untracked
`build/mut_x86_arm_annot0362.py` rows the `compact_helper_defines`
index numeration L784, the switch `case` emit line pair L798-799,
and the switch `default` L_UNSUPPORTED_OPCODE arm L802. In-process
battery pins the two-helper define numeration with its trailing
blank and the empty-set baseline, the C_CALL_HELPER header/switch
shape, the case-line helper call with its break, the default arm,
and the do-while trailer (count==1 anchors; 4 catches, no
equivalence rows). Run `4/4 rows caught` with 3 clean rerun shakes
(census 235 -> 236); golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0361 - x86 parse-text splits

The x86 parse-text free arms the head-route and operand-wrappers
batteries leave unrowed: the 3-row untracked
`build/mut_x86_arm_annot0361.py` rows the `parse_int`
negative-recursion tail L322-323, the `split_operands` zero-depth
comma gate L122, and the `parse_asm_text` relocation scan regex
L134. In-process battery pins the negative and plain/hex parse_int
reads, the bracketed-operand and bracket-comma splits, and the
objdump-line relocation capture with its plain no-reloc baseline
(count==1 anchors; 3 catches, no equivalence rows). Run
`3/3 rows caught` with 3 clean rerun shakes (census 234 -> 235);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0360 - arm64 append-insn emits

The arm64 `append_insn` emit arms the render-unit and emit-ops
batteries leave unrowed: the 5-row untracked
`build/mut_x86_arm_annot0360.py` rows the JCC emit f-string L694,
the JMP emit f-string L698, the helper-call emit L712, the A64_CALL
emit f-string L717, and the RUN_OP3 footer f-string L728. In-process
battery pins the JCC/JMP branch emits with their labels, the
helper-call blr emit, the in-address call lane with the next-addr
return, and the RUN_OP3 fallback over a reg-reg mov (count==1
anchors; 5 catches, no equivalence rows). Run `5/5 rows caught` with
3 clean rerun shakes (census 233 -> 234); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode host
1410 cases.

### Step 0359 - rodata-map and compact JCC

The rodata-map, step-plumb, and compact-JCC arms the earlier
batteries leave unrowed: the 3-row untracked
`build/mut_x86_arm_annot0359.py` rows the x86 `rodata_ident_map`
enumeration return L435, the x86 `append_step`
encode/comment/passthrough cell L1022-1024, and the arm64
`compact_step` JCC CompactStep return L742-743. In-process battery
pins the rodata enumeration and empty-map cases, the bare-comment
step emit, the mem-imm and cmp step emissions with the MEMOP
override, and the JCC branch step with its COND pick and the
off-blob KeyError arm (count==1 anchors; 3 catches, no equivalence
rows). Run `3/3 rows caught` with 3 clean rerun shakes (census 232
-> 233); golden gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0358 - branch-harvest paints

The x86 `append_branch_or_ret` free arms the branch batteries leave
unrowed: the 3-row untracked `build/mut_x86_branch_harvest0358.py`
rows the implicit `return_targets` empty-set default L1051, the JCC
branch-macro emit f-string L1064-1066, and the `X86_SIM_X86_CALL`
function-target emit f-string L1109-1113. In-process battery pins
the return-target jcc/jmp ret-statement flows, the in-address JCC
and JMP macro emits with their `x86_l_` labels, the
external-target raises, the memcpy-helper and register-indirect
call steps, the function-target call lane, and the bare ret arm
(count==1 anchors; 3 catches, no equivalence rows). Run `3/3 rows
caught` with 3 clean rerun shakes (census 231 -> 232); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0357 - direct-step and arm64 prelude

The x86 direct-step emit cell and the arm64 else-gate arms the
earlier batteries row only partially: the 7-row untracked
`build/mut_x86_arm_annot0357.py` rows the x86
`append_encoded_step` RUN_OP gate L1029, direct-emit line L1032,
and macro fallback L1034-1038, the
`normalize_native_link_entry_returns` ret-tag paint L265, and the
arm64 `mov_source_gpr` register-pick return L649, `source_prelude`
SEC scanner L250, no-SEC arm L251-252. In-process battery pins the
pump-arm triple (AUX-direct, DIRECT-eq, MEMOP override) and the
unknown-op macro fallback, the jmp-to-entry ret repaint in both
hit and miss flows, the helper-gpr carry flow feeding a helper blr,
and the prelude parse with its include rewrite (count==1 anchors;
7 catches, no equivalence rows). Run `7/7 rows caught` with 3 clean
rerun shakes (census 230 -> 231); golden gate `make check` rc 0
with 210 `cross-check: OK` banners, final arm64 decode host 1410
cases.

### Step 0356 - count-annotator and fixture helpers

The x86 generator helper arms the earlier batteries row only
partially: the 13-row untracked `build/mut_x86_annot0356.py` rows
the `text_symbol_addrs` six-field `.text` gate L220, the
`section_size` missing-section raise L168, the `is_int` fullmatch
regex L328, the `is_mem` bracket gate L344, the `branch_target`
pre-pick match L409, the `source_prelude` SEC scanner L1139, the
`annotated_fixed_count_ops` rep/call/mov/xor mnemonic gates
L985/L989/L995/L1003, and the `render_x86_subroutine`
banner/label/ret-macro lines L1164/L1166/L1171. In-process battery
pins the fixture-driven symbol/section reads and the
missing-section message, the minus and bracket gates, the hex
pre-pick, the prelude parse with its include rewrite, the
rep/call/mov/xor gates and self-zeroing xor over a mov-fed stream,
the subroutine painting, and the macro emit (count==1 anchors;
13 catches, no equivalence rows). Run `13/13 rows caught` with 3
clean rerun shakes (census 229 -> 230); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners, final arm64 decode host
1410 cases.

### Step 0355 - parse-flats and map arms

The parse-side arm64 generator helpers the earlier batteries row
only partially: the 7-row untracked `build/mut_parse_flat0355.py`
rows the arm64 `split_operands` tail-part flush pick L161-162, the
`parse_flat_instructions` relocation scan regex L169, the
`load_rodata16` `.native_link_rodata` index pick L132, the
`rodata_bytes` objdump-reject empty return L108-109, the
`program_kind` xdp fall-through L219, the `default_program_symbol`
`_xdp` suffix pick L228, and the `mem_aux` ARM64_AUX_MEM f-string
L353 of `kprog/arm64/micro-prog/generate_micro_sim_proofs.py` —
arms the split-pointer, parse-flat, native-entry, parse-rodata,
small-helpers, and encoder-selection batteries leave unrowed beside
their siblings. In-process battery pins the operand tuple split,
the objdump-reject empty return, the kind/suffix paints, a
fixture-driven rodata16 symbol-table read (`subprocess`-stubbed
line with a `rodata_bytes` override), the relocation annotator over
a bl-with-reloc flat disassembly line, and the AUX_MEM paint
(count==1 anchors; 7 catches, no equivalence rows). Run `7/7 rows
caught` with 3 clean rerun shakes (census 228 -> 229); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0354 - generator micro-helper residual

The walker-side arm64 generator helpers the render pipeline battery
only partially rows, plus the x86 reg_info residual: the 10-row
untracked `build/mut_gen_helpers_0354.py` rows the arm64
`written_gpr` GPR_WRITE_OPS gate, `[wx]` dst pattern pick, and
empty-operands None gate L620-628, the `mov_immediate` parse_imm
arm and except-None tail L630-639, the `blr_target_reg`
`target[1:]` pick L613-620, and the `c_ident` charset-mask body
L364-367 of `kprog/arm64/micro-prog/generate_micro_sim_proofs.py`,
together with the x86 `parse_mem_terms` index-branch gate/body and
base-branch pick/gate L374-383 that the operand-wrappers battery
leaves unrowed beside its overflow pick. In-process battery imports
both generator modules side by side and pins the
`helper_calls_by_addr` walker flow (mov-immediate feeds a blr
helper call at addr 8), the direct helper returns including the
write-gate raise arm, the digit-lead `c_ident` paint, and the x86
mem base/index picks over eax/ecx/rax/rbx/r12/r13/rsp with a -0x10
displacement (count==1 anchors; 10 catches, no equivalence rows).
Run `10/10 rows caught` with 3 clean rerun shakes (census 227 ->
228); golden gate `make check` rc 0 with 210 `cross-check: OK`
banners, final arm64 decode host 1410 cases.

### Step 0353 - generator helper trio + scale assign

The tiny arm64 generator helpers the encode/render batteries row
only at call sites, plus the x86 scale residual: the 5-row untracked
`build/mut_gen_helpers_0353.py` rows the arm64 `c_u64` ULL suffix
and 64-bit mask payload L260-261, the `width_const` table pick
L301-302, and the `reg_or_imm` `#`-immediate gate L356-357 of
`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`, together
with the x86 `parse_mem_terms` residual
`scale = parse_int(scale_text)` L377 that the scalar-helpers
battery leaves unrowed beside its scale-map claim. In-process
battery imports both generator modules side by side and pins the
direct helper outputs (positive/negative/hex `c_u64` payloads, the
`ARM64_WIDTH_*` table picks, the `#` gate booleans) and the x86 mem
scale picks 4->log2 1, 8->log2 3, `*1` -> 0, and the no-scale case
(count==1 anchors; 5 catches, no equivalence rows). Run `5/5 rows
caught` with 3 clean rerun shakes (census 226 -> 227); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0352 - x86 enc resolver + driver tail

The `enc()` opcode-contract resolver cell and the `write_one`/
`main()` driver tail: the 19-row untracked
`build/mut_x86_enc_driver.py` rows the L417-427 and L1576-1614
regions of
`kprog/x86/micro-prog/generate_micro_sim_proofs.py` — the
`X86_OPCODE_NAME.get(op, op)` canonical fallback, the
`X86_OPCODE.get(name)` define pick, the `define is None` reject
guard, the `EncodedInsn(define, ...)` payload order, the
signature-default flags/dst paints, the output/source path joins,
the render_program kind/exit/prelude/rodata fan-out, the write_one
return identity, the only-filter default, the written-list
declaration, bench loop, per-path print loop, generated-N summary
text, and the STAGE2_PROGRAMS prelude gate the stage2-wiring
battery leaves unrowed. In-process battery pins the direct `enc()`
six-tuple outputs and unknown-token SystemExit, a stubbed
`parse_proof_object_program` write_one fixture, and end-to-end
`main()` runs over the only-filter and generated-1 summary banner
(count==1 anchors, every repaint live-probed). Run `TOTAL 19
mutations, 0 failures, 0 equivalence rows` (census 225 -> 226);
goldengate `make check` rc 0 with 210 `cross-check: OK` banners,
final arm64 decode host 1410 cases.

### Step 0351 - x86 encode region

The `encode()` data-path sites the dispatch/residual batteries leave
unrowed: the 20-row `build/mut_x86_encode.py` rows the L466-918
region of
`kprog/x86/micro-prog/generate_micro_sim_proofs.py` — the ret/nop
arm tokens, the mov-imm lane-aux payload and immediate emit, the
setcc/cmov startswith gates, the lea/movaps/movx arity and
operand-pick raises, the movx else-raise and load token, the imul
mem-imm gate and width pick, and the cmp/test width-mismatch raise.
In-process `python -B -c` battery probes `encode()` directly (the
six-tuple op/dst/src/flags/aux/imm outputs, raise message shapes,
rc=1 unknown-opcode baselines); mutation detector classifies
rc/TOTAL after each exact-string source edit (count==1 anchors,
every repaint live-probed to an observable delta before rowing).
Run `TOTAL 20 mutations, 0 failures, 0 equivalence rows` (untracked,
census 224 -> 225); 222-battery sibling sweep re-run serially (218
in-glob + 4 outside-glob; 0 failures, 0 retries); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners, final arm64
decode host 1410 cases.

### Step 0350 - arm64 encode region

The `encode()` data-path sites the dispatch/ops batteries leave
unrowed: the 27-row `build/mut_arm64_encode.py` rows the L372–608
region of
`kprog/arm64/micro-prog/generate_micro_sim_proofs.py` — the
adrp/movk data arms, payload-slot wiring for
mul/umaddl/ldp/stp/ldrsb/ldrsw/stlxr/ands-reg/q0/d0, the load/store
width tables, the cmp/cmn/ands modifier and shifted-immediate index
seams, and the adrp reject-message bracket repaint. In-process
`python -B -c` battery probes `encode()` directly (rodata/GOT imm
strings, `ARM64_AUX_*` payloads, slot registers, widths, reject
`ValueError`s including the message shape); mutation detector
classifies rc/TOTAL after each exact-string source edit (count==1
anchors). Run `TOTAL 27 mutations, 0 failures, 0 equivalence rows`
(untracked, census 223 -> 224); 222-battery sibling sweep re-run
serially after repairing 16 zero-byte/truncated `.olean` modules
(ENOSPC-era corruption; `lean_chain` baselines went green after
targeted `lake build` rebuilds — environment artifacts, not
regressions); golden gate `make check` rc 0 with 210 `cross-check:
OK` banners, final arm64 decode host 1410 cases.

### Step 0349 - arm64 compact renderer regions

The compact renderer residual sites the sibling batteries leave
unrowed: the 13-row `build/mut_arm64_render_compact.py` rows the
`render_program_compact` region of
`kprog/arm64/micro-prog/generate_micro_sim_proofs.py` — the
`compact_step` op/cbz/tbz arms and their pc increments, the
guard/pc bounds (`{max(len(steps) * 8, len(steps) + 1)}U` /
`if (__a64_c_pc >= {len(steps)}U)`), the dispatch-head test order,
the jcc-taken swap, call/ret lr handling, the OP-arm advance
`__a64_c_pc++` -> `+= 2`, and the `append_compact_helper_switch`
`UNPAINTED` default arm. Source-literal anchors on the generator
line rows (count == 1 each), four detector families; run `TOTAL 13
mutations, 0 failures, 0 equivalence rows` (untracked, census 222
-> 223). A throwaway /tmp meta-battery over the detector's three
conditions observed 1/3; the two unpinned condition rows are
observationally indistinguishable on the pristine tree and add no
coverage over the 13 real rows + baseline pins, so the harness is
accepted without them.

### Step 0348 - arm64 stack-arm route anchor recount

repaired rather than re-rowed: `build/mut_arm64_stack_arm.py`
(untracked, harness census 221 -> 222) had a pre-existing
anchor-count drift from commit `a23a35a63` (the typed-store width
contract replaced the third `KPROG_ARM64_APPLY_WIDTH(` call site
-- the `__a64_sta_value` typed store -- inside
`kprog/arm64/arm64_sim_local_bpf.h`; Step 0256 recorded the
counterpart as out of scope). The `route`-detector
`local_assemble_drift` row now expects the two remaining call
sites (the `ARM64_SIM_L_WRITE_REG_WIDTH` body and the
`ARM64_SIM_L_STACK_WRITE_TAG` helper) and repaints
`KPROG_ARM64_APPLY_WIDTHX(`, still observable through the same
routed binary. Final run: `TOTAL 48 mutations, 0 failures` /
`ALL AS EXPECTED`; golden gate `make check` rc 0 with 210
`cross-check: OK` banners, final arm64 decode host 1410 cases.

### Step 0347 - x86 chunked flatten seam

The flatten seam residual sites the chunked/unit batteries leave
unrowed: the 4-row `build/mut_x86_chunk_flatten.py`
(untracked, harness census 220 -> 221) rows the
`flatten_chunk_insns` seed entry `(False, insns)`, the `next_addr`
`index + 1 < len(fn_insns) else None` tail pick, the
`flat = flatten_chunk_insns(insns, subfunctions)` call-site
argument, and the `max_steps = max(len(flat) * 4, len(flat) +
1024)` loop bound. Caught through an in-process battery pinning
exact flatten order and subroutine markers (the entry-marker pin
catches the seed flip), the 8196U iterative upper bound, the
1125U additive-range bound (a 101-insn chunked render: 4 * 101 <
101 + 1024, so the additive term dominates and a repaint of the
1024 constant shifts the emitted cap), and the same-chunk call
push return-address plus depth/`goto` join. 4 catches, no
equivalence rows; generator sha256 unchanged; golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0346 - arm64 non-compact render residual

The render_program residual sites the tails battery leaves
unrowed: the 9-row `build/mut_arm64_render_residual.py`
(untracked, harness census 219 -> 220) rows the non-compact
`next_by_addr` dict-comp's `index`/`index + 1` pair (the compact
renderer's tail-driven `all_addrs` clone differs), the
`helper_by_addr` join's addr/helper unpack (the bl-with-reloc pair
never consumes it; the blr branch-hint fixup does), the
`cgroup_skb/egress` section paint, the `uses_stack` gate arm
(the no-stack tc/cgroup renders share the stack define's absence),
the `if rodata_idents` blank-line gate (pinned on the rodata-less
render lacking the decl block), the map-symbols filter's rodata
and helper conjuncts, the `{ctx}ctx` entry-signature paint, and
the case-ladder `__a64_lr = 0` zero -- four anchors widened past
the compact twin's collisions. Caught through an in-process
battery pinning rodata adrp, a helper bl with blr relay,
sub-routine call, tc/irq rejects, and a rodata-less adrp program.
9 catches, no equivalence rows; three byte-identical green shakes
(generator sha256s unchanged); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0345 - arm64 render_program collector tails

The render_program collector tail the plumbing/unit/pipeline
batteries leave unrowed: the 10-row
`build/mut_arm64_render_tails.py` (untracked, harness census 218
-> 219) rows the `rodata16 or {}` None-gate, the `all_insns`
function flatten, the `all_addrs` set, the
`helper_calls_by_addr(insns).items()` join, the `cgroup_skb` tag
triple, the `rodata_ident_map(rodata16)` pick, the
`enumerate(map_symbols)` ident numbering, the `\t{entry}` entry
paint, the `ARM64_SIM_LICENSE();` tail, and the `"\\n".join` return
-- shared anchors counted across `render_program_compact`
(nine double-site rows, one render_program-only). Caught through an
in-process battery pinning a two-function xdp render with rodata,
helper blr, sub-routine banner, return-case ladder, map decls, and
cgroup/tc variants. 10 catches, no equivalence rows; three
byte-identical green shakes (generator md5s unchanged); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0344 - arm64 imm/prelude/bench tails

The parse_imm/parse_shifted_imm picks and the source_prelude /
load_benches whole-def lines the earlier batteries leave unrowed:
the 9-row `build/mut_arm64_imm_prelude_bench.py` (untracked,
harness census 217 -> 218) rows parse_imm's leading-space strip,
parse_shifted_imm's immediate-part value pick and modifier-index
pick, load_benches's tuple paints (swapped symbol/kind, wrong name
suffix, wrong benchmarks key), source_prelude's no-SEC arm (the
SEC-without-int matcher that would accept a data anchor), and the
utf-8 decode fidelity — caught through an in-process battery
pinning spaced immediates, one-token `lsl #N` modifiers, whole
Bench tuples over a temp YAML, and include-rewrite/no-SEC/no-int/
banner prelude fixtures with non-ASCII decode. 9 caught, no
equivalence rows; three byte-identical green shakes (generator
md5s unchanged); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0343 - arm64 helper_calls_by_addr walker

The `helper_calls_by_addr` call-range walker the render_pipeline
battery leaves unrowed: the 9-row `build/mut_arm64_helper_calls.py`
(untracked, harness census 216 -> 217) rows the register-table
pick, the last-helper fallback pick, the per-addr record paint,
the no-dst gate, the helper-immediate last mark (+1 shift), the
copy-arm `not in` guard, the copy-mark continue, the register pop
tail, and the blr-target pick — caught through an in-process
battery pinning direct/copy/last-fallback calls, unknown-register
misses, kill-then-chain-copy flows, a w-register blr reject, and
the phantom-record flow a non-call write would paint. 9 caught,
no equivalence rows (the `or`-phantom-key pickups for `dst` and
`target` are observably inert under the blr-target/copy-src regex
gates and were replaced with gate flips and a target-bypass pick
instead); three byte-identical green shakes (generator md5s
unchanged); golden gate `make check` rc 0 with 210 `cross-check:
OK` banners.

### Step 0342 - arm64 parse_mem head/body

The `parse_mem` operand parts the encoder_selection battery leaves
unrowed: the 9-row `build/mut_arm64_parse_mem_head.py` (untracked,
harness census 215 -> 216) rows the indexed-part strip (replaced
with a wrong-part selector after the lowercase strip proved
equivalent for every case-insensitive downstream consumer), the
postfix-`#` parts gate and its parse_imm pick, the `!` pre-index
flag arm and its `flags |= 1` bit, the bracket fullmatch and its
raise arm, the inner split and base pick, the `post if post else 0`
offset, the inner `#` immediate arm, the index-register arm's
`parse_modifier(inner, 2)` position, and the `MemRef(...)`
positional tail — caught through an in-process battery pinning
bracket/dereferenced-flag splits, postfix/immediate offsets,
inner-index scale terms, both-flag `!` + `#` operands, and the
unsupported-memory raise. 9 caught, no equivalence rows; three
byte-identical green shakes (generator md5s unchanged); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0341 - arm64 imm/modifier scalar tails

The arm64 scalar-parse tails the encoder/decode batteries leave
unrowed: the 27-row `build/mut_arm64_imm_mod_tails.py` (untracked,
harness census 214 -> 215) rows `split_operands` (bracket depth
arms, depth-zero comma gate, part strip, tail-append gate,
duplicate-char append, tuple paint), `program_kind`'s xdp
fallthrough, `default_program_symbol`'s stage2 gate and xdp paint,
`parse_imm` (strip, `#` prefix gate, radix-0), `parse_modifier`
(none gate boundary, joined-text lowercase strip, shift radix-0,
extend default-0 arm, raise arm), `parse_shifted_imm` (index+1
boundary gate, shift paint, LSL gate arm), `reg_const` (sp arm,
raise arm, `ARM64_X` paint), and `mem_aux` (PRE/POST flag arms and
the AUX paint) — caught through an in-process battery pinning
bracket-nesting splits, tag->kind/symbol maps, `#`-immediate
radix/strip separates, shifted-amount radix and boundary arms,
modifier-raise rejects, register/sp rejects, and PRE/POST/zero
flag paints. 27 caught, no equivalence rows; three byte-identical
green shakes (generator md5s unchanged); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners.

### Step 0340 - x86 scalar helper layer

The scalar helper functions the render/encode batteries leave
unrowed: the 22-row `build/mut_x86_scalar_helpers.py` (untracked,
harness census 213 -> 214) rows `parse_int` (hex radix gate,
negative-sign arm, whitespace strip), `is_int` (fullmatch vs match,
grouped negative sign), `c_ptr_u64`'s long-cast paint, `reg_info`
(lowercase strip, none-or-default pick), `is_mem` (two-bracket
conjunction), `operand_width` (PTR-width scan via stripped-case
gate, per-width return, register-width pick, default),
`parse_mem_terms` (no-bracket gate, space/negative inner strip,
scale-log2 map, displacement summation), `mem_aux`'s
`X86_MEM_AUX_FULL` arm, `mem_disp`'s tuple pick, and
`branch_target` / `has_direct_branch_target` (hex radix,
strip-dependent match gate) — caught through an in-process battery
pinning radix/sign/whitespace separates, unbalanced-bracket
rejects, the lowercase `PTR` fixture, scaled/offset mem terms, and
space-padded branch targets. 22 caught, no equivalence rows; three
byte-identical green shakes (generator md5s unchanged); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.


### Step 0339 - x86 direct-step lowering tails

The `direct_step_statement` / `append_encoded_step` lines the
branch-ladder battery leaves unrowed: the 7-row
`build/mut_x86_direct_step.py` (untracked, harness census 212 ->
213) rows the `encoded.aux != "0"` arm gate, the direct-table
`None` gate, `append_encoded_step`'s `X86_SIM_RUN_OP` gate, the
`direct is not None` condition, the direct-emit early return, and
the two module-level macro-table validation loops (`DIRECT_STEP_
MACROS` / `AUX_STEP_MACROS` keys must be defined opcodes or
import-time `SystemExit`) — caught through an in-process battery
pinning the lowered `X86_SIM_L_EXEC_*` macro paints (aux-0 direct,
nonzero-aux `*_AUX` template, no-template `None`), the fallback
`X86_SIM_RUN_OP(...)` shape, the non-run-op passthrough, and the
exact emit lines. 7 caught, no equivalence rows; three
byte-identical green shakes (generator md5s unchanged); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0338 - x86 native-link parse head and program split

The native-link blob layer `parse_native_link_blob` leaves unrowed:
the 24-row `build/mut_x86_native_link_program.py` (untracked,
harness census 211 -> 212) rows the missing-object gate and its
exact `RuntimeError` message raw, the `load_rodata16` probe order,
the `objdump -dr -Mintel` command shape, the symbol-relocation
join arm, and the `section_size(proof_obj, ".text")` blob-length
pick; plus `parse_native_linked_program`'s split flow: the
`parse_proof_object_program` passthrough, the no-insns early
return, the off-blob exit-target scan (CC-aux arm, jmp arm,
not-already-instruction filter), the `sub_starts` comprehension
conjuncts, the no-sub early return, the `entry_end = sub_starts[0]`
pick, the exit `max(...)`, the half-open subfunction range, the
entry `< entry_end` pick, the `native_link_sub_{start:x}` key
paint, and the entry-return normalizer (jmp-to-blob-len gate, its
`ret` replacement, the `; native-link entry RET` raw suffix, and
the address keep) — caught through an in-process fake-`objdump`
battery (section/symbol/rodata/disassembly fixtures, six program
shapes including an indirect relocated call, an off-blob jmp/jcc
pair, and a two-subfunction split). 24 caught, no equivalence
rows; three byte-identical green shakes (generator md5s
unchanged); golden gate `make check` rc 0 with 210 `cross-check:
OK` banners.

### Step 0337 - x86 flat render program tail

The flat `render_program` body lines the render batteries leave
unrowed: the 9-row `build/mut_x86_render_flat.py` (untracked,
harness census 210 -> 211) rows the `total_insns` subfunction sum,
the `entry_addr` head pick, the chunk-gate
`total_insns >= CHUNKED_PROOF_INSN_THRESHOLD or has_self_call`, the
`has_self_call` reloc-arm and direct-arm picks, the cgroup_skb
elif's exact section paint, the rodata blank-line guard, the
closing `X86_SIM_LICENSE()` tail, and the
`subroutine_label_by_addr` comprehension's `if fn_insns` guard —
caught through the flat/chunked fork itself (a direct self-call, a
relocated self-call, the 2047/2048 threshold-boundary pair, an
empty-subfunction raise pinned at the exact
`unsupported unresolved call target` message). 9 caught, no
equivalence rows; three byte-identical green shakes (generator md5s
unchanged); golden gate `make check` rc 0 with 210 `cross-check:
OK` banners.

### Step 0336 - x86 encode high-byte guard

The `encode()` high-byte pre-guard (dispatch batteries row only the
`high_supported = (` line): the 14-row
`build/mut_x86_encode_high_guard.py` (untracked, harness census
209 -> 210) rows the `high_regs` comprehension, the `reg[2] != 0`
high-position pick, the armed raise gate and message raw, and the
five arm shapes inside `high_supported` — the `{"mov", "movabs"}`
2-op set with its dst-pick/`is_int`-or-register/memory-form
disjuncts, the `{"add", "adc", "sub", "sbb"}` set, the
`{"cmp", "test"}` set, the `{"dec", "inc", "neg", "not"}` 1-op set,
and the setcc arm's `op.startswith("set")`/length picks — caught
through supported high-lane fixtures (`mov/movabs ah, 9`,
`add/adc/sub/sbb ah, 9`, `cmp/test ah, 9`, `inc/dec/neg/not ah`,
`seta ah`), the low-byte neighbors (`add al, 9`, `add al, bl`), and
the exact-message must-raise gates `xor ah, 9` and `imul ah`. 14
caught, no equivalence rows; three byte-identical green shakes
(generator md5s unchanged); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0335 - x86 fixed-count annotation pass

The `annotated_fixed_count_ops` pass (plus `canonical_reg`) runs
before every render path; the render-pipeline harness rows four of
its lines, and the 16-row `build/mut_x86_count_annot.py` (untracked,
harness census 208 -> 209) rows the rest: the rep gate and
`values.get("X86_RCX")` pick (a `r9d` lane fixture and a no-track
`rep` miss the tracking), the memcpy/memset call gate and
`values.get("X86_RDX")` pick (the no-symbol `call memcpy`, a `bpf_*`
helper, and a no-track call miss the reloc set), the two
`count is not None` guards and `replace(insn, sim_imm=count)` emits,
the `{"memcpy", "memset"}` set membership (a memset-only repaint
falls to the memcpy fixture), the mov length gate and `is_int`
set-or-pop pick (a `mov ecx, rax` register repaint kills a tracked
count), the mov `continue` shielding tracked counts from the
trailing first-operand pop, the xor length gate and the dst==src
zero set versus dst!=src pop (caught with a tracked `ecx` so the
pop empties the later `rep`), the trailing `if insn.operands` pop
arm with its first-operand pick, and `canonical_reg`'s info[0]
payload. Every fixture feeds one `NativeInsn` list through one pass
and compares per-insn `(mnemonic, sim_imm)` pairs; 16 caught, no
equivalence rows; three byte-identical green shakes (generator md5s
unchanged); golden gate `make check` rc 0 with 210 `cross-check: OK`
banners.

### Step 0334 - x86 branch and residual encoder arms

The `encode()` arms the dispatch battery and per-arm batteries leave
unrowed at encoder-line level: the 40-row
`build/mut_x86_encode_branch_resid.py` (untracked, harness census
207 -> 208) rows the jmp arm's gate/immediate, the JCC mnemonic
gate/token/aux/target (`X86_CC_*` pick and the `branch_target` read,
separated by the no-operand `jle`/`js` fixtures), the SETCC memory
gate/token/base/disp and the `X86_REG_AUX_SRC_SHIFT(CC_AUX[op])` aux
join, the SETCC register raise-shield/token/lane, the CMOV memory
gate/base/flags/aux/displacement, the CMOV register gate/token/
flags (no width-mismatch check — an accepted divergence pinned
as-is), the mov load arm's helper-id gate/immediate, scalar-rodata
rejection raise, `X86_OP_MOV_LOAD_MAP_PTR` token/`c_ptr_u64`
immediate, and the plain load's nested PTR-default flags/aux/
displacement picks (`mov rax, DWORD PTR [rdi]` separates the width;
`[rdi+rbx*4]` separates the index/scale aux paint), and the
movaps/movups `X86_OP_LOAD_XMM0`/`X86_OP_STORE_XMM0` gates, rodata
rejection, tokens, aux and displacement picks. Six exact-message
must-raise gates; 40 caught, no equivalence rows (the xmm rodata-imm
`.get` repaint is unobservable — the gate raises first — and is not
a row); three byte-identical green shakes (x86 generator md5
unchanged `6793ca9e824336df8da78a9955c9d22c`); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0333 - x86 default ALU lane and unary arms

The `encode()` default `ALU_AUX` lane the per-family batteries leave
unrowed: the 29-row `build/mut_x86_encode_alu_lane.py` (untracked,
harness census 206 -> 207) rows the unary block (`inc/dec/not/neg`
dispatch set, arity gate, dst-None raise shield, the inc/dec-vs-
not/neg immediate pick, and the `X86_OP_ALU_IMM` register emit with
its dst-width pick and `KPROG_X86_REG_LANE_AUX` paint) and the
memory-unary arm's `is_mem` conjunction, width default (caught
through the bracket-no-PTR `inc [rdi]` fixture), token, base/flags/
disp picks and `X86_MEM_AUX_ALU_OP` paint; plus the generic ALU
arms' `is_int` entry gate, `len != 2` gate, register-arm gate,
`X86_OP_ALU_MEM` token, the nested `operand_width(ops[1],
dst_reg[1])` pick (separated by `add eax, BYTE PTR [rdi]`: FLAGS
keep the dst width W32 while the AUX carries the memory W8), the
mem-reg arm's gate/width (separated by `add BYTE PTR [rdi], eax`)/
token/base/src picks, the mem-imm arm's gate and width default
(separated by `add DWORD PTR [rdi], 7`), the
unsupported-memory-ALU raise (message-level via the exact-message
fixture `add qword ptr [rdi], qword ptr [rsi]`), and the
fall-through cannot-encode message (via `add rax, rb5x`). Every
fixture compares the fully-populated `EncodedInsn` six-tuple; six
must-raise gates; 29 caught, no equivalence rows; three
byte-identical green shakes (x86 generator md5 unchanged
`6793ca9e824336df8da78a9955c9d22c`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0332 - x86 bt/mulx/andn/bzhi/rep encoder arms

The `encode()` bitops arms the family batteries leave unpinned:
the 37-row `build/mut_x86_encode_bitops.py` (untracked, harness
census 205 -> 206) rows the bt arity gate, the `X86_OP_BT_IMM`
token/width/immediate emit, the `X86_OP_BT_MEM_IMM` width default
(caught only through the bracket-no-PTR `bt [rdi], 7` fixture; the
PTR width always wins the default for PTR-mem fixtures), the
oversized `disp<<33` packed paint and the packed immediate, and
the `X86_OP_BT` token/width pick; the mulx arity and None gates,
dst/src-lo picks, `WIDTH_CONST[lo[1]]` width (separated by
`mulx eax, ebx, r8`) and hi-aux paint; the andn memory arm's
nested-width pick (separated by `andn eax, ebx, QWORD PTR [rdi]`),
base-shift aux, displacement, token and fall-through gate plus the
register src2-aux/width/token; the bzhi None gate (or-to-and,
caught through the mem-count raise), register width (separated by
`bzhi rax, rbx, cl`), count-aux, memory shift-aux and displacement;
and the rep movs arity/movs-shape/mem gates, `sim_imm` None gate,
both bound comparisons (`sim_imm = 0` catches the `>= 1` lower
repaint, `sim = 2**40` the upper), the ops[0] width pick
(separated by the mixed QWORD/DWORD rep fixture) and the count
immediate. Every fixture compares the fully-populated
`EncodedInsn` six-tuple; nine must-raise gates; 37 caught, no
equivalence rows; three byte-identical green shakes (x86 generator
md5 unchanged `6793ca9e824336df8da78a9955c9d22c`); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0331 - x86 two-op imul and cmp/test encoder forms

The `encode()` two-operand `imul` fall-through and the CMP/TEST
reg-reg/reg-mem/mem-reg arms between the 0293 dispatch smoke pins
and the residual battery: the 16-row
`build/mut_x86_encode_alu_cmp.py` (untracked, harness census 204
-> 205) rows the `X86_ALU_IMUL` aux paints on the immediate and
register forms with the dst-width flags picks and immediate emit,
the `{add, adc, sub, sbb}` mismatched-width raise set, the
`X86_OP_CMP_REG`/`X86_OP_TEST_REG` token pick and byte-lane aux
paint, the CMP reg-mem flags/nested-width-aux/displacement, the CMP
mem-reg gate/`operand_width(ops[0], src_reg[1])` pick/aux/immediate,
and the TEST mem-reg gate and token. Cross-width fixtures
(`cmp eax, QWORD PTR [rdi]`, `cmp DWORD PTR [rdi], bl`) separate
the nested-width repaints, an `ah`/`cl` pair separates the lane
aux; every fixture compares the fully-populated `EncodedInsn`
six-tuple; two must-raise gates (imul arity-1, `sbb rax, ebx`);
16 caught, no equivalence rows; three byte-identical green shakes
(x86 generator md5 unchanged `6793ca9e824336df8da78a9955c9d22c`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0330 - x86 mov register-store encoder arm

The `encode()` register-store arm between the 0326 mov-family and
0328 store-immediate batteries: the 5-row
`build/mut_x86_encode_store_reg.py` (untracked, harness census 203
-> 204) rows the `X86_OP_MOV_STORE_REG` token, the dst-width
`operand_width(dst)` flags pick, the
`mem_aux(dst, src_shift=src_reg[2])` source-shift aux paint, the
`is_mem(dst) and src_reg` gate, and the memory-displacement
immediate (rowed through the raise-line-disambiguated anchor after
the bare form proved shared with the store-immediate arm). Every
fixture compares the fully-populated `EncodedInsn` six-tuple (an
`ah` source separates the `X86_REG_AUX_SRC_SHIFT(8)` paint) plus two
must-raise gates (non-register source, memory-mem pair); 5 caught,
no equivalence rows; three byte-identical green shakes (x86
generator md5 unchanged `6793ca9e824336df8da78a9955c9d22c`); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0329 - x86 call memcpy/memset bound and push/pop arms

The `encode()` memcpy/memset bound gates and push/pop arms: the
15-row `build/mut_x86_encode_call_push.py` (untracked, harness
census 202 -> 203) rows both `reloc_symbol` arms' `X86_OP_
CALL_MEMCPY[_REG]`/`X86_OP_CALL_MEMSET[_REG]` token pairs with the
`MAX_MEMSET_COUNT` fall-through literal, both `< 0`/`> MAX` bound
comparisons (the `>=` flip caught by a `sim_imm == MAX` boundary
fixture, the `< -1` low-side flip by a zero-length in-bound
fixture), the in-bound emit tags, and the push/pop register-pick
rows with their `WIDTH_CONST.get` flags paints. The `.get`
fallback-default repaints are equivalence-documented (every REGS
entry carries width in {8, 16, 32, 64}) and rowed as the width-paint
flips instead. Every fixture compares the fully-populated
`EncodedInsn` six-tuple plus four must-raise gates; 15 caught, no
equivalence rows; three byte-identical green shakes (x86 generator
md5 unchanged `6793ca9e824336df8da78a9955c9d22c`); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0328 - x86 imul/store-immediate/movbe encoder arms

The `encode()` three-operand `imul` register form, `mov`
store-immediate arm, and `movbe` pair: the 11-row
`build/mut_x86_encode_movbe_imulstore.py` (untracked, harness census
201 -> 202) rows the `X86_OP_IMUL_IMM` token, dst-width flags pick,
immediate emit, and the always-trip repainted `is_int` guard (the
plain shield drop is masked by the parse_int cursor raising the same
ValueError), the store-immediate arm's packed `imm32 | disp32<<32`
immediate (the packing-order swap row; the simpler `^` repaint is
bit-disjoint from the `|` parts and unobservable), the
`operand_width(dst)` flags pick, the masked-imm32 paint, and the
`is_mem(dst) and is_int(src)` gate, and the `movbe` load-form width
pick (dst width over the nested memory width), store-form width
paint, arity gate, and both opcode tokens. Every fixture compares
the fully-populated `EncodedInsn` six-tuple plus the six must-raise
gates (imul non-int and register-None, movbe one-operand, reg-reg
fall-through, no-mem/no-reg pairs); 11 caught, no equivalence rows;
three byte-identical green shakes (x86 generator md5 unchanged
`6793ca9e824336df8da78a9955c9d22c`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0327 - x86 unary/double-shift encoder arms

The `encode()` shld/shrd twins, `div` arm, and unary `bswap`/`popcnt`/
`xchg` arms: the 16-row `build/mut_x86_encode_unary_dbshift.py`
(untracked, harness census 200 -> 201) rows the shld/shrd opcode-token
emits and their arity/None/`is_int` guards (both twins), the twin
`WIDTH_CONST` flags picks and c_u64 immediate emits, the `div` arm's
width pick and `X86_REG_NONE` fall-through (guards absent by design),
the `bswap` dst gate and token, the `popcnt` two-int gate and
dst-width flags pick, and the `xchg` dst pick. Every fixture compares
the fully-populated `EncodedInsn` six-tuple plus the nine must-raise
gates (shld arity 2/4/non-int third operand, bswap no operands,
popcnt/src-none, xchg/src-none), with a mixed-width popcnt fixture
(rax/bl) distinguishing the dst/src width-source repaints; the
drop-`is_int`-shield row was probed masked (the parse_int cursor
still raises the identical ValueError) and repainted `or True`
instead; 16 caught, no equivalence rows; three byte-identical green
shakes (x86 generator md5 unchanged
`6793ca9e824336df8da78a9955c9d22c`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0326 - x86 mov-family encoder arms

The `encode()` move-family residual arms past the 0293 dispatch pins:
the 10-row `build/mut_x86_encode_movx.py` (untracked, harness census
199 -> 200) rows the MOVZX/MOVSX register-form opcode pick (the
`{"movsx", "movsxd"}` ternary against `X86_OP_MOVZX_REG`), the
load-form opcode pick against `X86_OP_MOV_LOAD` and its
`X86_OP_MOVSX_LOAD` twin, the movsxd 32-bit default-load width pick
over a PTR-less memory operand, the load aux
`mem_aux(ops[1], mem_width)` FULL-form emit, the register-form
source-width aux emit, the `cdqe` arity gate, the `cdqe` RAX/RAX/
W64/W32 six-tuple emit and aux, and the
`{"movzx", "movsx", "movsxd"}` dispatch set literal. Every fixture
compares the fully-populated `EncodedInsn` six-tuple plus the two
must-raise gates (cdqe-with-operands, unknown-mnemonic fall-off) and
the battery purges `__pycache__`; stock stays green and every row
must flip a pin (no equivalence rows): 10 caught; three byte-identical
green shakes (x86 generator md5 unchanged
`6793ca9e824336df8da78a9955c9d22c`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0325 - x86 encoder residual arms

The `encode()` arms left unpinned by the 0293 dispatch battery and
its per-family successors: the 12-row `build/mut_x86_encode_residual.py`
(untracked, harness census 198 -> 199) rows the LEA rip-relative rodata
arm and the ordinary LEA memory arm's `mem_aux` emit, the STORE_XMM0
opcode token, the three-operand `imul` memory-immediate packed
`disp<<32|imm` emit, the compare register-vs-memory arm gate, the ALU
memory-register and memory-immediate arms' `X86_MEM_AUX_ALU_OP` OR and
packed immediates, the BMI2 SHIFTX trio's `sarx` ALU-op pick and mem
form's packed `disp|op` immediate (mask `0xffffffff` narrowed), the
RORX reg and mem forms' count masks, and the `{"mov", "movabs"}` set
literal. Every fixture compares the fully-populated `EncodedInsn`
six-tuple and the battery purges `__pycache__`; stock stays green and
every row must flip a pin (no equivalence rows): 12 caught; three
byte-identical green shakes (x86 generator md5 unchanged
`6793ca9e824336df8da78a9955c9d22c`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0324 - x86 helper-symbol glue and pointer casts

The x86 twin of the arm64 parser-helper battery: the 10-row
`build/mut_x86_split_helpers.py` (untracked, harness census
197 -> 198) rows the `is_helper_symbol` `bpf_` prefix repaint and
its `and`->`or` conjunction, the encode call arm and mov-load
helper-ident arm gates, the append/branch helper early-return gate on
a non-default step macro, the chunked twin's `{memcpy, memset}` gate
(observed through the chunked memcpy direct-macro emission), the
`c_ptr_u64` `(long)` cast repaint, the mov-load map-pointer `&sym`
imm arm, the xmm0 rodata ident pick over a two-entry map, and the
`proof_kind_for_source` `bench.kind` pass-through; one gold battery
over direct helper pins, `encode` arm pins, an `append_branch_or_ret`
non-default-macro flow, and a threshold-forced chunked
`render_program` with helper and `memcpy` calls; 10 catches, no
equivalence rows, with the xmm `rodata_idents.get` repick and the
`write_one` stage2 kind-gate repaint probed equivalent and documented
instead of rowed; three byte-identical green shakes; golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0323 - arm64 operand-split depth and pointer cast

The last unrowed arm64 parser helper: the 7-row
`build/mut_arm64_split_ptr.py` (untracked, harness census
196 -> 197) rows `split_operands`' bracket-depth loop (the `[`
depth increment, the `]` decrement, the top-level comma gate, the
comma cut's `continue`, the in-loop strip append, and the
tail-append `if cur:` guard) plus the `c_ptr_u64` `(long)` cast
repaint observed through the `adrp` rodata arm; one gold battery
over direct `split_operands` fixture strings (top-level commas,
nested and two-deep brackets, whitespace strips, trailing comma
tail) and a `render_program` gold noncompact fixture with a rodata
`adrp`; the `depth == 0` comma gate raised to `depth <= 0` probed
equivalent (the bracket scan order keeps depth nonnegative at every
comma) and documented instead of rowed; 7 catches, no equivalence
rows; three byte-identical green shakes; golden gate `make check`
rc 0 with 210 `cross-check: OK` banners.

### Step 0322 - x86 noncompact subfunction plumbing

The `render_program` subfunction plumbing and subroutine emission the
0312 exit-tail battery left open: the 5-row
`build/mut_x86_render_plumbing.py` (untracked, harness census
195 -> 196) rows the subfunction `annotated_fixed_count_ops` coercion
(`(subfunctions or {})` proved through a no-subfunction fixture), the
call return-address comprehension feeding the ret-dispatch case loop,
the subroutine-local `next_addrs` copy (scoped against the main
renderer's twin), the subroutine blank-line tail before the joined
body, and the `if subfunctions:` render loop; one gold battery with a
call/jne/ret/jmp-to-exit main flow plus an fn body carrying an
internal call, a `SUB_JCC`, and push/pop; `addrs.add(exit_addr)` is
verified equivalent (the `return_targets = {exit_addr}` arm
pre-empts every in-`addrs` branch test) and documented instead of
rowed; 5 catches, no equivalence rows; three byte-identical green
shakes; golden gate `make check` rc 0 with 210 `cross-check: OK`
banners.

### Step 0321 - arm64 noncompact render plumbing

The `render_program` declaration plumbing and return-case ladder that
0314 pinned only through cascade output: the 13-row
`build/mut_arm64_render_plumbing.py` (untracked, harness census
194 -> 195) rows the `bool(return_addrs)` ladder gate, the ladder
`tail` continuation, the `case 0xN: __a64_lr = 0; goto` paint, the
rodata `[2]`-element paint, the rodata blank separator, the rodata
ident loop ordering, the helper-reloc exclusion composed with the
`reloc_idents` arm, the `__arm64_reloc` prefix (`c_ident` fallback
proved on a digit-leading map symbol), the map `struct {` decl head,
the `.maps` section paint, the `int {name}_arm64_sim_xdp({ctx}ctx)`
entry head, the non-main function gate, and the per-insn label line;
one gold battery with a nine-insn xdp program (bl-return ladder,
cbnz/tbnz, helper call, adrp map symbol, `[sp` stack, subroutine
comment) plus tc, cgroup linked-exit, two-rodata ordering, and
digit-symbol fixtures; 13 catches, no equivalence rows; two
verified-equivalent probes documented instead of rows (`reloc_idents
.get` is key-equal by construction, `or ""` is short-circuit shadow);
three byte-identical green shakes (`TOTAL 13 mutations, 0 failures,
0 equivalence rows` each); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0320 - arm64 compact renderer residuals

The `render_program_compact` internals 0313's output pins
underconstrained (most of the 154-line body was unpinned): the 32-row
`build/mut_arm64_render_compact_residual.py` (untracked, harness
census 193 -> 194) rows the prelude `rstrip`, the stack-enabled
define, the map descriptor fields, the six step-struct tail fields,
the step-row paint, the `ARM64_SIM_L_EXEC` argument order (proved on
an `madd` fixture whose row really uses both `src2` and `src3`), the
per-kind runner arms (the JMP assignment, the JCC conditional select,
the CBZ zero-take and bit-test arms, the CALL `__a64_lr`/`x30`/pc
transfer, the RET `pc`-rewind and `__a64_lr` zap, the helper delegate
and `pc` advance), the guard-limit formula, the pc bound, the step
fetch, and the entry-function paint; every row is anchored to make
its mutation uniquely pin one line (renderer-scoped multi-line bans
for the six lines the noncompact renderer duplicates); one gold
battery with a nine-insn compact program (branch/cond/tbz/helper /
`madd` tail) plus stack, cgroup, linked-exit, map-symbol, and
rodata-ident variants; 32 catches, no equivalence rows; three
byte-identical green shakes (`TOTAL 32 mutations, 0 failures, 0
equivalence rows` each); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.


### Step 0319 - x86 flat-disassembly parser

The x86 twin of 0318: the remaining unrowed `parse_asm_text` arms that
0297 pinned only through the two whole-fixture splits. The 11-row
`build/mut_x86_parse_asm.py` (untracked, harness census 192 -> 193)
rows the relocation arms (the `\S+` capture with a symbol-less
`R_X86_64_64` line staying unmatched, the `and insns` orphan gate with
a leading unprefixed relocate line crashing `insns[-1]`, the `+0xN`
suffix strip keeping the reloc-type prefix under `group(0)`, the
repaint replacing the captured symbol), the `:` column gate (the
or-`True` repaint crashes on the no-colon junk line), the address
fullmatch (testing the raw prefix instead crashes the same way), the
hex radix (base-8 rejects `8`), the `#`-comment operand cut (dropping
the split keeps the comment in operands and raw), the `lock` prefix
strip (`LOCK` keeps the prefix), the no-mnemonic reject (an
operand-only `%eax` body crashes the append under `pass`), and the
mnemonic/operand split (`\s*` to `\s+` rejects bare mnemonics);
the battery feeds synthetic objdump `-dr` text directly (reloc-fixture
entry body, label-with-bytes reject, bare reloc, orphan reloc,
no-colon junk, bad-addr junk, hex address, branch-operand call,
no-mnemonic operand body); 11 catches, no equivalence rows; the `<`
asm gate observed redundant (every line it rejects also fails the
anchored mnemonic match) and documented instead of recounted; three
byte-identical green shakes (`TOTAL 11 mutations, 0 failures, 0
equivalence rows` each); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.


### Step 0318 - arm64 flat-disassembly parser

The arm64 flat-disassembly parser internals, the last
`parse_flat_instructions` arms that 0310 pinned only behaviorally:
`build/mut_arm64_parse_flat.py` (untracked, harness census 191 -> 192)
rows 9 lines --- the insn-line regex tail (`(.*)` to `(.*)\s$`, where a
line whose `raw` ends mid-token no longer matches), the relocate-only
`\S+` capture (`\S*` makes a symbol-less `R_AARCH64_JUMP26` line match
and rewrite the previous insn with an empty symbol), the `and insns`
orphan gate (repainted `and True` crashes on a leading relocate-only
line), the `+0xN` suffix strip (`group(1)` to `group(0)` keeps the
reloc-type prefix), the unmatched-line `continue` (dropped crashes on
`nonsense line`), the `//`-comment operand cut (`//` to `;` keeps the
comment in operands), the `asm` strip, the hex-address pick
(`group(1)` to `group(2)` throws on the mnemonic), and the
`NativeInsn` append; the battery feeds synthetic objdump `-dr` text
directly (orphan-reloc-leading body, comment body, hex address, bare
reloc, junk, empty); 9 catches, no equivalence rows; three
byte-identical green shakes (`TOTAL 9 mutations, 0 failures, 0
equivalence rows` each); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.


### Step 0317 - arm64 native-link entry and rodata readers

The arm64 native-link entry glue and its two rodata readers, an
assembly layer that 0310 covered only through `parse_flat_instructions`
and reader arms in isolation: `build/mut_arm64_native_entry.py`
(untracked, harness census 190 -> 191) rows 24 lines --- `rodata_bytes`'s
objdump `-s -j .native_link_rodata` launch shape (args triple and
`check=False`), the nonzero-returncode `b""` gate, the address-substring
gate (`fields[0]` pick), the per-field hex/parity gate (`len(field) % 2`
- odd fields kill their line), the fields[1:] loop start, and the
two-byte pair walk (`range(0, len(field), 2)`);
`load_rodata16`'s `-t` launch shape, the `.native_link_rodata`
membership gate, the short-record gate (`idx + 2 >= len(fields)`, where
a 4-field row with in-bounds data distinguishes `>=` from `>` through a
bogus size-named key), the `offset`/`size` picks (`fields[0]` /
`fields[idx + 1]`), the `size >= 16` gate, and the two 8-byte little
endian slices; `parse_native_linked_program`'s missing-object gate (a
`b1.proof.o` directory fails `is_file` while `exists` holds --- the
fixture pins the gate without touching a real objdump), its message
formatting (`...for <bench>: <path>`), the `rodata16 = load_rodata16`
wire-in, the `-dr` launch shape, the empty-disassembly raise, and the
single-entry `OrderedDict([(symbol, insns)])` return; and
`source_prelude`'s `\nSEC(\"...\")\s+int\s+` regex (a source ending at `int` pins the trailing `\s+` --- dropping it shifts the match), the
`match is None` empty arm, the `text[:match.start()]` slice direction,
and the include rewrite; the battery drives all three reads with FAUX
subprocess runners (canned `-s`/`-t`/`-dr` texts routed by arg probe);
24 catches, no equivalence rows; three byte-identical green shakes
(`TOTAL 24 mutations, 0 failures, 0 equivalence rows` each); golden
gate `make check` rc 0 with 210 `cross-check: OK` banners.


### Step 0316 - x86 operand-scalar unit

The x86 operand-scalar layer pinned at unit level: Steps 0290 and
0298 covered `is_mem`/`mem_disp`/`operand_width`/`mem_aux`/
`split_operands` only indirectly through their callers, but the scalar
one-liners themselves stayed unrowed. `build/mut_x86_operand_scalars.py`
(untracked, harness census 189 -> 190) rows 24 lines --- `is_mem`'s
conjunction dropped and or-painted (the `a]b` open-only/close-only pins
split the arms), `mem_disp` repainted to `parse_mem_terms(operand)[2]`
(the scale entry), `operand_width`'s case-sensitive
`startswith(f"{name} PTR")` arm repainted to the lowercase literal
(uppercase fixtures fall through to the default), its
`reg_info(stripped)` arm repainted to `parsed[2]`, the `default` arm
repainted to a constant 64, and each of the four `PTR_WIDTH` entries
repainted (`BYTE` 8->9, `WORD` 16->17, `DWORD` 32->33, `QWORD` 64->65);
`mem_aux`'s `X86_MEM_AUX_FULL` f-string repainted to embed the raw
`mem_width`, its `X86_MEM_AUX` plain arm suffixed and duplicated
(index/scale swapped), the `src_shift` gate repainted to `src_shift > 1`,
the value-destructure repainted to reindex all four `parse_mem_terms`
positions, the `{WIDTH_CONST[mem_width]}` key repainted to
`X86_WIDTH_BAD`, and the shift append repainted to `src_shift + 1`;
`split_operands`' `enumerate(text)` start repainted to
`enumerate(text, 1)`, the `[` open arm repainted to `]`, the `]` close
`depth -= 1` repainted to `depth += 1`, the depth-0 comma gate repainted
to `and True`, the part capture suffixed with `?`, the `start` advance
repainted to `start = index`, and the tail gate repainted to
`if not tail`; 24 catches, no equivalence rows (two sweep casualties
recorded not rowed: `reversed(PTR_WIDTH.items())` is observably
identical for every operand because the BYTE/WORD/DWORD/QWORD keys are
pairwise prefix-disjoint, and is_mem's
`"[" in operand` -> `"]" in operand and "[" in operand` repaint is
literally equivalent for every string); three byte-identical green
shakes (md5 70e604cc4c7d5e70a57a373adbe0c193 across each `TOTAL 24
mutations, 0 failures, 0 equivalence rows`); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners.


### Step 0315 - x86 render head route and scalar helper unit

The x86 `render_program` head route and its scalar helper layer pinned at
unit level: Steps 0296/0298/0305/0312 rowed the chunked body, the branch
ladder, the exit tail, and the first-op decode, but the route decision
itself (`total_insns >= CHUNKED_PROOF_INSN_THRESHOLD or has_self_call`)
and the flattening/scalar layers stayed unrowed.
`build/mut_x86_head_route.py` (untracked, harness census 188 -> 189)
rows 14 lines --- the threshold/self-call branch over a small flat
fixture (chunk markers absent) flipping to route a 3-insn program into
`render_chunked_program`, the self-call reloc-target arm and its
direct-target twin over `call <self>`/`call 0x0` fixtures (chunked
before, flat after the repaint), the `entry_addr` compute repaint over
the reloc self-call fixture, the `total_insns` subfunction sum
repainted to a constant 2048 over the one-entry +
`native_link_sub_10` fixture (flat before, chunked after), the
`return_targets` repaint to an empty set over the `je 0x40` exit
rewrite fixture (the guarded `X86_SIM_X86_RET();` ladder disappears),
the `next_addrs` `insns[:-1]` window repainted to `enumerate(insns)`
(IndexError at the last instruction), the cgroup_skb arm repainted so
`kind == "cgroup_skb"` falls to the xdp fallback (the
`SEC("cgroup_skb/egress")` + `X86_SIM_ENTRY_SKB(ctx);` pair swaps to
`SEC("xdp")` + `struct xdp_md *`), the
`extract_sub_sequences`/`flatten_chunk_insns` subfunction feed
repainted to iterate `subfunctions` keys (AttributeError:
`'str' object has no attribute 'addr'`), and the scalar helpers
(`is_int`'s decimal-digit alternative dropped, `parse_int`'s hex base
repainted to base-10 over the `0x1a` seed, the negative-arm minus
dropped over the `mov rcx, -5` seed, `c_comment`'s `*/` spacing
repainted, and `canonical_reg`'s `info[0]` pick repainted to the width
entry); 14 catches and no equivalence rows (the `addrs.add(exit_addr)`
line is masked by the return-target rewrite ordering --- a masked
equivalence, recorded here rather than rowed; second sweep casualty:
`ChunkInsn.is_subroutine` has no consumer, discovered while auditing
the `(False, insns)` feed); three byte-identical green shakes (md5
18acb1bbc90a6731cbfe53485d357e0b across each `TOTAL 14 mutations, 0
failures, 0 equivalence rows`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.


### Step 0314 - arm64 noncompact render unit

The arm64 noncompact `render_program` pinned at unit level: Steps 0296
and 0313 rowed the chunked and compact siblings but `render_program`
itself only carried pipeline-level rows (Step 0293) and scattered pins.
`build/mut_arm64_render_unit.py` (untracked, harness census 187 -> 188)
rows 40 lines --- the render_program surface (the sorted
`return_addrs` over a backward-call fixture feeding `RETURN_CASES`
steps 0x8/0x1c, the xdp/tc section-context pair, the include/prelude
arm padded so `rstrip` -> `lstrip` breaks the pin, the two-symbol
`rodata_idents` order pin, the `next_by_addr` feed into
`append_insn`, the label arm, the subroutine comment and its `*/`
escaping, the helper-arm `ARM64_SIM_A64_RET();`, the linked-exit X7
write-back and the `return 0;` tail), the `compact_step` per-kind arms
re-pinned at unit level (JCC cond, the JMP/CALL targets, CBZ/TBZ kind
and immediate repaints, the CALL target/helper/raise ladder, RET, and
the OP record), the helper surface (`is_helper_symbol` via
`HELPER_IDENTS.values()` over integer keys, `c_ident` suffix and
`helper_defines` idents, the helper-switch `switch (ID)`/case/default
ladder), and the `generate_one`/`main` glue (`program_kind`/
`default_program_symbol`, the in-process `generate_one` write loop
over the real corpus assets, and the `main()` surface pinned through a
nested subprocess run of the generator: the `--only` write filter and
the `generated 1 proof sources` banner). 40 rows = 40 catches and no
equivalence rows; three byte-identical green shakes (md5
7c388f6b8af9de928224a79c68f506ee across each `TOTAL 40 mutations, 0
failures, 0 equivalence rows`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.


### Step 0313 - arm64 compact step runner unit

The arm64 compact step-runner layer pinned at unit level: Steps 0294 and
0308 reached `render_program_compact` only through individual pins,
leaving its kind-defines/include block, prelude/rodata/map declarations,
step struct and table, guard/pc plumbing, and most of the per-kind
runner arms unrowed. `build/mut_arm64_render_compact.py` (untracked,
harness census 186 -> 187) rows them with 33 single-anchor flips run
against an in-process battery pinning the kinds block exactly (the
`#define ARM64_SIM_C_OP 1U` through `10U` ladder over a fixture whose
step kind requires the `cr.usedops` OP-set repaint), the
`compact_helper_defines` output and the
`../arm64_sim_local_bpf.h` include line, the padded prelude line pin
(`" // pre313 "` arrives right-stripped but left-kept, so
`rstrip` -> `lstrip` breaks the pin), the rodata cell pair
(`lo, hi = rodata16[rodata_symbol]` over a `{34ULL, 51ULL}` fixture),
the map declaration arm pinned in sorted-symbol order over a
fixture whose adrp symbols (`map_zz`/`map_aa`) emit the idents
`map_aa_0`/`map_zz_1`/`prog_2` (`c_ident` appends the enumerate
index), the compact-step struct, table, step row, and step-ident
repaints, the guard-limit/unroll/pc-bound/fetch-offset repaints (the
bound and fetch painted over a 9-step fixture whose mover pins
`__a64_c_pc + 1`), the fnhead `section` repaint, and the runner arms
(OP default + the OP `__a64_c_pc++` repaint, the JMP/exit-target
tail, the CBZ/TBZ value/take/pc ladder over the guard-72 fixture
whose branch rows pin cond constants, the CALL lr capture and
exit-target tail, the RET `if (__a64_lr)` switch plus write-back and
clr rows and the retfall `ARM64_SIM_RET();` pointer repaint, the
HELPER call+pc rows, the else-arm split, and the linked-exit tail pinned
through the False case (`return 0;` no-WRRW render)): 33 rows = 33
catches and no equivalence rows; three byte-identical green shakes (md5
fbc86ab31f139df27a87bc2576fb6433 across each `TOTAL 33 mutations, 0 failures, 0 equivalence rows`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0312 - x86 non-chunked exit tail and subroutine unit

The x86 non-chunked exit tail and subroutine layer pinned at unit level:
Steps 0293/0311 had pinned the render pipeline and the chunked twins, but
`render_program`'s own tail (exit fallthrough block, return dispatch),
`render_x86_subroutine`'s unit surface, and `write_one`'s error paths
stayed unrowed. `build/mut_x86_render_sub.py` (untracked, harness census
185 -> 186) rows them with 15 single-anchor flips run against an
in-process battery pinning the exit fallthrough triple (`x86_l_{exit}:`
label with a non-overlapping 0x40 exit address, the
`/* native-link entry fallthrough exit */` comment, the
`\tX86_SIM_X86_RET();` statement), the return-dispatch banner
(`x86_sim_ret_dispatch:` + `switch (__x86_sim_ret_addr)`) and its
`case 0x{addr:x}ULL: goto x86_l_{addr:x};` labels pinned in SORTED order
over a fixture whose return-address set iterates unsorted under
`list(...)` (main call next at 0x12 inserted before fn call next at 0xa,
both hashing to the same small-int slot), the
`subroutine_label_by_addr` first-address map pinned through the
`X86_SIM_X86_CALL(x86_l_30, ` transfer paint, the `call_functions` kwarg
and the `next_addrs.get` feed, the push/pop mnemonic probe (push-only
fixture with no subfunctions) and the `[rsp`/`[rbp` memory probe, the
sorted-vs-list dispatch order again via `return_addrs = sorted({`,
`render_x86_subroutine`'s head/label/ret/annotation pins (sub-jcc
in-bounds `X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x30, 0x32, x86_l_32);` paint
driven through the subfunction `annotated_fixed_count_ops` address set,
the sub `X86_SIM_X86_SUB_RETX(x86_sim_ret_dispatch);` statement, the
`X86_SIM_RUN_OP` step macro), and `write_one`'s no-native-insns
`ValueError` pinned through a stubbed parser: 15 rows = 15 catches and
no equivalence rows (survivor fixes: the exit label check moved to a
non-overlapping exit address 0x40 after the 0xc fixture collided with
the last-insn label; the sorted pin needed a same-slot unsorted fixture;
the push/pop probe needed a subfunction-free fixture because
`bool(subfunctions)` masks the mnemonic arm); three byte-identical green
shakes (md5 `74e7420e4e2a7f1aca89e5126c8ba355` across each `TOTAL 15
mutations, 0 failures, 0 equivalence rows`); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners.

### Step 0311 - x86 chunked render unit

The x86 chunked render unit layer pinned at unit level: Step 0298's
`mut_x86_branch_ladder.py` and Step 0296's `mut_x86_chunked_render.py`
reached `render_chunk_function`/`render_chunked_program` only through
end-to-end renders, leaving the two functions' own emission lines
unrowed. `build/mut_x86_chunk_unit.py` (untracked, harness census
184 -> 185) rows both functions with 28 single-anchor flips run
against an in-process battery pinning the chunk-function header nine
lines exactly (name/index signature, state/pc arg tail, the
`switch (__x86_pc)` entry, per-chunk case-goto labels and the PC_DONE
default), the chunk ret tail (`return __x86_sim_ret_addr;` plus the
last-next `return 12ULL;` paint and the PC_DONE fallback), the
`annotated_fixed_count_ops` flow over subfunctions (a sub-memcpy call
loses its fixed `rdx` count when the annotation pass is dropped), the
chunk slicing window `flat[index:index + CHUNKED_PROOF_CHUNK_INSNS]`
(painted by an exact `__x86_pc <= 1532ULL` range boundary over a
401-insn fixture), both call-target sets (the `flat[0]` entry seed and
the per-subfunction first-address set, painted by an in-chunk
subfunction call and an unresolved-target raise), the push/pop and
`[rsp`/`[rbp` stack probes plus the `bool(subfunctions)` fallback,
the stack/state defines and include block, the bridge maps' lo/hi
order, the tc/cgroup_skb/xdp section-ctx-abi-kind arms with their
skb-ctx initialization dataflow, the dispatch prefix `if`/`else if`
and its `>=`/`<=` range comparisons, the write-back PC_DONE guard,
and the entry signature/license/state-storage lines: 28 rows = 28
catches and no equivalence rows (cf.sig's `{index + 1}` repaint,
rcp.slice one-insn shrink, rcp.stack.push's push/pop pair kill, and
rcp.range's literal/`else if` count pins were all first-draft
survivors painted by exact-value count fixtures, no rows dropped);
three byte-identical green shakes (md5 `f7bd80b0eccf0d295e5afe9fba52da51`
across each `TOTAL 28 mutations, 0 failures, 0 equivalence rows`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0310 - arm64 rodata load and flat parse

The arm64 native-link data loaders pinned at unit level:
`rodata_bytes`/`load_rodata16` reading the `.native_link_rodata`
section from the proof object and `parse_flat_instructions`
parsing the FAUX `objdump -dr` text had no rows in any prior
harness. `build/mut_arm64_parse_rodata.py` (untracked, harness
census 183 -> 184) rows both surfaces with 18 single-anchor flips
run against a FAUX-subprocess battery (the generator's object
probes called with stubbed runners): the rodata rows pin the exact
`-s -j` objdump argument list, the nonzero-returncode empty-blob
error path, the decimal address-line gate, the per-field hex +
even-length parity gate with its odd-field break, the
little-endian 2-nibble decode, the empty-data record-map error
path, the `-t` symbol-table section gate, the `idx + 2` missing
size-field boundary, the `offset + 16` record-in-range boundary,
and the little `(lo, hi)` pair order; the parse rows pin the
`R_AARCH64_` reloc scan, the `+0x4` suffix strip, the
interior-symbol rewrite keeping an explicit empty symbol (an empty
reloc symbol is written, not replaced by None), the
instruction-line regex both its lowercase mnemonic class (a
capital-X probe mnemonic stays unparsed) and its exactly-8-nibble
bytes column (a 7-nibble probe stays unparsed), the `//` comment
strip (a `#` suffix survives), the asm shape, and the hex address
decode: 18 rows = 18 catches and no equivalence rows (three
first-draft survivors --- the record offset boundary, the mnemonic
character class, and the bytes column width --- were painted by
boundary fixtures, no rows dropped); three byte-identical green
shakes (`TOTAL 18 mutations, 0 failures, 0 equivalence rows`, all
md5 `8f1fbfe6a7ce741a4832cf8a84ffe3ba`); golden gate `make check`
rc 0 with 210 `cross-check: OK` banners.

### Step 0309 - x86 branch/call ladder and flat parse

The x86 branch/call/return emission ladder and the FAUX-objdump
parse layer pinned at unit level: Step 0298's
`mut_x86_branch_ladder.py` drove `append_branch_or_ret` only
through full `render_program` outputs (and had no
`parse_asm_text` rows), and Step 0296's `mut_x86_chunked_render.py`
pinned the chunk machinery end-to-end, leaving the unit-level
per-arm lines and the objdump-runner regexes unrowed.
`build/mut_x86_branch_lads.py` (untracked, harness census
182 -> 183) rows both layers with 31 single-anchor flips: the
ladder pins (JCC/SUB-JCC/JMP/SUB-JMP macro choices and
`0x{addr}, 0x{target}, x86_l_{target}` argument orders, the
`ret_statement` default plus the guarded/bare return-target
rewrites and a custom `ret_statement`, the helper/memorycp
gate widening, the `X86_SIM_X86_CALL(x86_l_18, 0x19ULL);` return
address, the `cannot compute return address` raise, and the chunk
twin `append_chunk_branch_or_ret` --- the in-chunk/out-chunk,
guarded/bare PC_DONE rewrites, the depth/stack-rw/return ret
block, `append_chunk_call`'s four-line sequence, all three raises,
and the helper/reg-call step paints) plus the parse pins (the
reloc-symbol `+0x4` suffix strip, the `R_X86_64_` scan, the hex
fullmatch gate keyed on a hex-letter address probe, the lowercase
mnemonic regex keyed on `endbr64`'s digits, the lock-prefix
strip, the `#`-comment strip, and the three-field tab minimum):
31 rows = 31 catches and no equivalence rows (three first-draft
survivors --- the chunk unresolved-call gate, the address
fullmatch, and the mnemonic digits regex --- were fixed by
strengthening the battery with exact-paint fixtures and a
return-targets/call_targets corrective probe, no rows dropped);
three byte-identical green shakes (`TOTAL 31 mutations, 0
failures, 0 equivalence rows`, all md5
`6d82f2a1ddd678ec738b0351f05e61a3`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0308 - arm64 append_insn/compact_step emission

The ARM64 emission layer pinned as data: Step 0294's
`mut_arm64_render_pipeline.py` pinned the two renderers' full-text
lines over a mixed fixture, and Step 0307's
`mut_arm64_encode_ops.py` pinned the per-arm `Encoded` picks, but
`append_insn`'s per-arm emitted lines and `compact_step`'s per-arm
`CompactStep` records were still unrowed as a surface.
`build/mut_arm64_emit_ops.py` (untracked, harness census
181 -> 182) rows both layers with 34 single-anchor flips: the
 emitted-line pins (`ARM64_SIM_A64_JCC/JMP/CBZ/CBNZ/TBZ/TBNZ/CALL/
RET` macro choices, argument orders, the `ARM64_SIM_BPF_CALL_`
helper macro forms, the `ARM64_SIM_RUN_OP3(...)` rep with its
width/aux/imm tail, the `/* 0x.. */` comment line, and the
unsupported-call-target raise) and the record pins (`CompactStep`
kinds, the cbz src/width pick, the tbz immediate operand, the OP
slot order (dst, src, src2, src3), the alu aux repaints in both
reg- and imm-arm forms, and the `ARM64_SIM_C_HELPER_` define index,
name, blank-line tail, and the `ARM64_SIM_C_CALL_HELPER` switch
block bytes): 34 rows = 34 catches and no equivalence rows; three
byte-identical green shakes
(`TOTAL 34 mutations, 0 failures, 0 equivalence rows`, all md5
`8b005b5bea0f3847cde1dd0f5e8f1cd8`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0307 - arm64 encode tier-2 per-arm picks

The ARM64 encoder's per-arm `Encoded` picks inside `encode()` pinned
as data: Step 0292's `mut_arm64_encode_dispatch.py` rows the fork
*guards* (imm-vs-reg starts-with checks, mode picks, the wzero
bics destination repaint), but the per-arm bodies that build each
`Encoded` were still unrowed. `build/mut_arm64_encode_ops.py`
(untracked, harness census 180 -> 181) follows the same in-process
battery convention: one fixture `NativeInsn` per arm, exact
`Encoded` field pins (`op`, `dst`/`src`/`src2` slot order, `width`,
`aux`, `imm`), and 26 single-anchor repaints that must each lose the
battery. Rows: the mul/umull/umulh/udiv singleton-map picks (4),
the umaddl/smaddl fixed-width pair return (3: `ARM64_OP_MADD`
repaint and the `ARM64_WIDTH_64` -> `ARM64_WIDTH_32` return flip),
the `adds`/`orn` reg-form picks (2), `extr`'s fourth-operand
immediate repaint (1), the `ARM64_AUX_BITFIELD(lsb, width)` operand
order swap (1), the rev/rev16/sxtb/sxth/sxtw singleton-map picks
(2), the q0/d0 `ldr`/`str` early-return picks (4), the
`ldrsb`/`ldrsh` picks (2), the `ldp` register-slot order swap (1),
the cinv/csinv/csinc/csneg CONDITION-register picks (4), and the
`cnt`/`uaddlv` no-operand picks (2). One row survived the first
battery draft (the `ldp` slot swap — the draft pinned only the
opcode and width) and was admitted after the standing survivor rule
strengthened the battery with three exact slot pins
(`ldp.dst`/`ldp.src`/`ldp.base`), not dropped: 26 rows = 26 catches
and no equivalence rows; three byte-identical green shakes
(`TOTAL 26 mutations, 0 failures, 0 equivalence rows`, all md5
`8fa2d1a24f2107615531d023a12de63f`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0306 - arm64 main-layer wiring

The ARM64 generator's main-layer wiring pinned end to end: `generate_one` (the
`{bench.name}.bpf.c` output name, the `source_prelude(source) if source_dir ==
STAGE2_PROGRAMS else ""` gate, the `render_program_compact if compact else
render_program` picker, and the `linked_exit=True` ride-along) and `main()`'s
argparse surface (the `output_dir.mkdir(parents=True, exist_ok=True)`, the
`"stage2" in args.config.stem` conditional that flips the source dir to
`STAGE2_PROGRAMS`, the `only` subset filter, and the `MICRO_PROGRAMS` default).
After Step 0305 the module tables were the last module-scope surface; these nine
wiring lines were the last unpinned decision layer in the ARM64 generator.
`build/mut_arm64_main_wiring.py` (untracked, harness census 179 -> 180) closes
the layer with 8 rows over the one-file watchlist (the ARM64 generator,
byte-exact restore each row) and one in-process detector: a battery in a fresh
`python -B -c` interpreter that (a) pins `generate_one`'s decisions through
sentry-patched `parse_native_linked_program`/`render_program`/`source_prelude`
with exact write-path, prelude-read, compact-route, and `linked_exit` assertions
plus a real prelude read over the actual `STAGE2_PROGRAMS` dir, and (b) drives
`main()` through real `sys.argv` with `load_benches`/`generate_one` replaced by
sentinels — the `--only a` subset run, a `cfg-stage2.yaml` stem run (both benches
must route to `STAGE2_PROGRAMS`), a plain-config default run (both must stay
`MICRO_PROGRAMS`), a `--compact` ride-along, and a pre-created output dir. All 8
single-anchor flips must break the battery (no equivalence rows): go_outname,
go_preludesel, go_compact_pick, go_linked_exit, mn_dir_mkdir, mn_stage2_stem,
mn_only_filter, mn_micro_default; 8 caught. Battery temp roots were made
deterministic (`shutil.rmtree` + fixed `/tmp/batt0306_*` paths) after the first
shakes surfaced `mkdtemp` path nondeterminism in the detector output; battery
rc held 0 across all probes and three byte-identical green shakes
(`TOTAL 8 mutations, 0 failures, 0 equivalence rows`, all md5
`783fe8511c08f404d747c936c21dda96`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0305 - arm64 module tables

The ARM64 generator's two module-level tables pinned as data: `WIDTH_CONST` (the
byte-size to `ARM64_WIDTH_*` name map `width_const()` indexes) and `GPR_WRITE_OPS`
(the 59-entry mnemonic set gating `written_gpr`'s destination scan, whose
membership content is the load/store/ALU/atomic `x*-written` contract). Step 0304's
class scan confirmed the five dataclasses are annotation-only (no methods to row),
leaving the module tables as the last unrowed module-scope surface.
`build/mut_arm64_module_tables.py` (untracked, harness census 178 -> 179) closes
the pair with 5 rows over the one-file watchlist (the ARM64 generator, byte-exact
restore each row) and one in-process detector: a battery in a fresh `python -B -c`
interpreter pinning the exact `WIDTH_CONST` dict, `width_const(4)`/`(8)` name picks,
`len(GPR_WRITE_OPS) == 59`, ten present-probe mnemonics (`add`, `ldr`, `stlxr`,
`cset`, `fmov`, `umull`, `ubfx`, `rev16`, `sxtw`, `csel`), seven absent-probes
(`str`, `stur`, `ldar`, `br`, `b`, `blr`, `cmp`), and the `written_gpr`
membership-gate ride-along (`add x0,x1` -> `0`, `mov w8,#1` -> `8`,
`str x0,[sp]` -> `None`). All 5 single-anchor flips must break the battery (no
equivalence rows): wc_val, wc_key, gwo_drop, gwo_add, gwo_len; 5 caught; three
byte-identical green shakes (`TOTAL 5 mutations, 0 failures, 0 equivalence rows`,
all md5 `d1bd6cecd06f10e845c6fa3218297cd1`); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0304 - arm64 bench-loader and naming helpers

The arm64 generator's three small helpers pinned: `rodata_ident_map` (the
`enumerate(rodata16)` order rendered through the fixed `__arm64_rodata_` prefix),
`c_ident` (the two-pass `re.sub` sanitization with underscore collapse + strip and
the digit-lead `prefix_{ident}` rename), and `load_benches` (the YAML config
schema flowing `Bench(name, symbol, kind)` through `default_program_symbol`'s
stage2/cgroup/tc tag ladder and `program_kind`'s cgroup/tc/xdp kind pick). The
x86 program-wide scan had saturated (both anchor tiers empty after Step 0303), so
the same two-tier scan ran over the ARM64 generator (md5
`cbe4f3f3d4c94344b8ea76e88a20e7c9`): `load_benches`, `rodata_ident_map`, and
`c_ident` surfaced as the only thin-anchored names. `build/mut_arm64_small_helpers.py`
(untracked, harness census 177 -> 178) closes them with 6 rows over the one-file
watchlist (the ARM64 generator, byte-exact restore each row) and one in-process
detector: a battery in a fresh `python -B -c` interpreter pinning the
rodata-ident map over a two-symbol fixture (exact dict, empty dict), the
c_ident idents (`ro_0x10_2_x_3`, digit-lead `ro_123_7`, blank `ro__9`, plain
`main_loop_0`), and an end-to-end `load_benches` over a 4-entry temp YAML
(names, `[xdp, cgroup_skb, tc, xdp]` kinds, `[alpha, beta_prog, gamma_prog,
delta_xdp]` symbols). All 6 single-anchor flips must break the battery (no
equivalence rows): rim_prefix, rim_enum_sh, ci_digitlead, ci_collapse,
lb_sym_tags, lb_kind_tc; 6 caught (the `ci_san` regex-flip candidate survived ---
underscore erasure is behaviorally identical through the collapse+strip pipeline
--- and was dropped per the equivalence rule); three byte-identical green
shakes (`TOTAL 6 mutations, 0 failures, 0 equivalence rows`, all md5
`9ee1a77e509a0d3b0eb62ff6f0229971`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0303 - x86 per-step append delegation

The per-step append delegation pinned end to end: `append_step` --- the three-line
glue every render loop reaches one instruction through (the `encode(insn,
rodata_idents or {})` wiring that keeps the rodata-ident table observably live (an
xmm0 `[rip+...]` load must re-render with the caller's ident symbol), the comment
line `f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */"` carrying the real
address and raw text, and the `append_encoded_step(lines, encoded, indent,
step_macro)` delegation with its `"X86_SIM_RUN_OP"` default macro). Step 0297's
branch-ladder battery pinned `append_encoded_step` and `c_comment` separately but no
row ever mutated `append_step`'s own glue; the step-0302 scan flagged it as the last
thin-anchored name and `build/mut_x86_append_step.py` (untracked, harness census
176 -> 177) closes it with 4 rows over the one-file watchlist (the x86 generator,
byte-exact restore each row) and one in-process detector: a battery in a fresh
`python -B -c` interpreter calling `append_step` directly over ret/mov/movaps
fixtures, pinning exact 2-line output pairs (comment + RUN_OP), default and
custom indents, the `X86_SIM_L_EXEC_MOV_REG` route for reg-reg movs, the
rodata-ident pass-through (`((__u64)(long)ro_rb_x)` in the emitted line), and
append-mode accumulation. All 4 single-anchor flips must break the battery (no
equivalence rows): as_encode_drop, as_comment_addr, as_delegate, as_macro_default;
4 caught; three byte-identical green shakes (`TOTAL 4 mutations, 0 failures,
0 equivalence rows`, all md5 `bc7cb4a64c92a1766178e1e2fd3287f5`); golden gate
`make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0302 - x86 chunk-for-address lookup

The chunk-for-address lookup pinned end to end: `chunk_for_addr`'s linear scan over the
chunked renderer's chunk list --- the `enumerate(chunks)` index source, the
`any(item.insn.addr == addr for item in chunk)` membership test on the nested
`ChunkInsn.insn.addr` field, the hit `return index`, and the miss `return None`
sentinel (the main-render emission loops at 1405/1425 reuse the same idiom but render
text; this is the only pinned consumer of the lookup itself). Step 0295's chunk battery
called it (`cf.hit`/`cf.hit2`/`cf.miss`) but planted no row over its body; Step 0301's
function-census cross-check flagged the four still-unanchored names, and
`build/mut_x86_chunk_lookup.py` (untracked, harness census 175 -> 176) closes the last
one with 4 rows over the one-file watchlist (the x86 generator, byte-exact restore each
row) and one FAUX-battery detector: an in-process battery in a fresh `python -B -c`
interpreter building `ChunkInsn`-shaped fixtures and pinning three hits, the empty-list
miss, an internal empty chunk (the `any`/`all` distinction), double-call determinism,
and the payload-field coupling (a decoy top-level `.addr` at 0x99 must not satisfy a
0x42 lookup). All 4 single-anchor flips must break the battery (no equivalence rows):
cfa_index_repaint, cfa_eq_flip, cfa_miss_sentinel, cfa_enum_shift; 4 caught; three
byte-identical green shakes (`TOTAL 4 mutations, 0 failures, 0 equivalence rows`, all
md5 `a5f392474e31856c0e0df5106d8acb0b`); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0301 - x86 native-link blob dispatch

The native-link blob dispatch boundary pinned end to end: `parse_native_link_blob`'s
missing-proof-object gate and raise (the `if not proof_obj.is_file():` guard and the
`missing proof object for {name}: {proof_obj}` message, the `f"{name}.proof.o"` name
formatting the gate resolves against), the objdump feed it launches (`["objdump", "-dr",
"-Mintel", str(proof_obj)]` --- the `-dr` flags the FAUX router keys on, the
`str(proof_obj)` target the run pin checks), the relocation arm
(`replace(insn, reloc_target=symbols.get(insn.reloc_symbol))` --- a symbol the symtab
names gets the symtab address, a ghost reloc keeps `None`), and the one-line
`parse_proof_object_program` pass-through whose return reaches every renderer consumer.
`build/mut_x86_blob_dispatch.py` (untracked, harness census 174 -> 175) closes the
gap with 6 rows over a one-file watchlist (the x86 generator, byte-exact restore each
row) and one FAUX-objdump detector: a battery in a fresh `python -B -c` interpreter
stubbing `subprocess.run` (argv-keyed on `-h`/`-s`/`-t`/`-dr` over one toy proof
object with text symbols, rodata-local symbols, a rep movs entry, and one call
relocation) pinning the raise message and name formatting, blob-level rodata/size/
call-reloc pins, the program-level split (`entry` length, `native_link_sub_20`, the
`exit_addr` off both the disasm and section table), and the dispatcher's propagation
of the missing-proof raise. All 6 single-anchor flips must break the battery (no
equivalence rows): blob_isfile_inv, blob_raise_msg, blob_name_fmt, blob_dr_flag,
blob_reloc_none, ppp_dispatch; 6 caught; three byte-identical green shakes
(`TOTAL 6 mutations, 0 failures, 0 equivalence rows`, all md5
`5df78bfd42518b596fa96b13e70010af`); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0300 - x86 operand-classifier wrappers

The operand-classifier wrapper quartet pinned:
`mem_base_reg` (`parse_mem_terms(operand)[0]` --- the base pick over
the four-tuple), `parse_mem_terms`'s bracket arm (the
`re.search(r"\[(.*?)\]", operand)` lazy-bracket reader the whole
mem-operand duct starts from, with the no-bracket
`X86_REG_NONE, X86_REG_NONE, 0, 0` sentinel return and the
first-vs-second register base/index overflow assignment), 
`has_direct_branch_target` (the
`re.match(r"(0x[0-9a-fA-F]+|[0-9a-fA-F]+)", operand.strip())` head ---
two hex arms over the stripped operand), and `canonical_reg` (the
`reg_info(reg)` wrapper returning `info[0]`). The interior terms rows
(negative-displacement rewrite, scale map, displacement add) stay in
Step 0300's separate `mut_x86_encoder_selection.py` harness; no row
had mutated the four wrappers or the bracket/no-bracket/overflow/
strip arms they wrap. `build/mut_x86_operand_wrappers.py` (untracked,
harness census 173 -> 174) closes the gap with 7 rows over a one-file
watchlist (the x86 generator, byte-exact restore each row) and one
in-process detector: a unit battery in a fresh `python -B -c`
interpreter pinning `mem_base_reg` (base-only, base-plus-disp,
numeric-only `X86_REG_NONE`, bracketless sentinel),
`parse_mem_terms` (the full `[rbx+rsi*4+0x10]` tuple, space-stripped
`[rbx + rsi * 8]` scale-3 pick, `[rbx-8]` negative displacement,
bracketless sentinel tuple, `[rax+rbx]` overflow-to-index,
`[0x10+rax]` numeric-with-base), `has_direct_branch_target` (`0x`-hex,
bare hex, `<label`-operand false, register name false, leading-space
hex after the strip), and `canonical_reg` (lowercase, uppercase, and
the unknown-name `None`). All 7 single-anchor flips must break the
battery (no equivalence rows): mbr_pick, pmt_bracket_arm,
pmt_none_ret, pmt_overflow, hdb_regex, hdb_strip, cr_pick; 7 caught;
three byte-identical green shakes (`TOTAL 7 mutations, 0 failures, 0
equivalence rows`, all md5 `735900ff058c5832e4a26c9eeac8eec4`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0299 - x86 write-one/CLI wiring

The write-one/CLI assembly layer pinned end to end: `write_one` (the
name-driven proof-object parse, the `.bpf.c` output name, the
`source_dir == STAGE2_PROGRAMS` prelude/kind gates, and the
`render_program` fields `kind`/`exit_addr`/`source_prelude`/
`rodata16`), `proof_kind_for_source` (the `bench.kind` identity with
the `source` parameter kept only as a call-site contract), and
`main()` (`args.output_dir.mkdir(parents=True, exist_ok=True)`, the
`--micro-programs` override or the `stage2`-stem conditional pick of
`STAGE2_PROGRAMS` vs `MICRO_PROGRAMS`, `only = set(args.only or [])`,
the `--only` subset filter, the `written.append(write_one(...))`
accumulator, the printed per-file paths, and the
`generated N proof sources` summary with `return 0`). Step 0297 pinned
the parse layer the proof-object parse calls but no row touched this
assembly layer, and the 0293/0295 batteries called `render_program`
directly without going through `write_one`/`main()`.
`build/mut_x86_stage2_wiring.py` (untracked, harness census
172 -> 173) closes the gap with 8 rows over a one-file watchlist (the
x86 generator, byte-exact restore each row) and one in-process
detector: a battery with FAUX substitutes in a fresh `python -B -c`
interpreter with the module `__pycache__` purged around every battery
(`subprocess.run` stub returning canned objdump `-h`/`-s`/`-t`/`-dr`
text for the proof objects, a `yaml.safe_load` router for the
in-memory configs, tempdirs for `--output-dir`, and three toy sources
self-scaffolded into `kprog/test`/`micro/programs` and unlinked at
exit). The battery drives unit `write_one` calls for the stage2 pair
(`toy_a` with the SEC banner, rewritten include, prelude comment in
the body, and the `cgroup-skb`-normalized kind; `toyb` without a SEC
anchor --- empty prelude), the micro singleton (`toyc` rendered from
`micro/programs` with no prelude and kind from the bench row), unit
`source_prelude` probes (banner capture, no-SEC empty, un-SEC'd
include rewritten unconditionally), `load_benches` over the in-memory
stage2/micro fixtures, and two end-to-end `main()` calls (stage2 pair
into a two-layer-deep outdir pinned for both toy files, the toyz
exclusion, the banner, the rewritten include, and the clean toyb; the
micro singleton into a deep outdir pinned for file existence, kind,
and clean text), with the FAUX objdump text carrying 3 sub-function 
targets and the exit top border behind `parse_native_linked_program`.
All 8 single-guard/literal flips must break the battery (no
equivalence rows): outdir_parents, outdir_omit, stage2_pick,
only_filter, wb_append, main_rc1, micro_kind_xdp, prelude_norewrite;
8 caught; three byte-identical green shakes (`TOTAL 8 mutations, 0
failures, 0 equivalence rows`, all md5
`7ef071a7d5f4c29f5002b0e9d822f267`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0298 - x86 branch-ladder emission

The plain branch/call/return emission ladder pinned:
`append_branch_or_ret`'s four arms (`jcc` with the `CC_AUX` condition
map, `jmp`, `ret`, and the `call` arm's helper/reg-indirect/full-target
priority order), the exit-target rewrite that repaints `je`/`jmp` into
`ret` for return targets (both the guarded
`if (X86_SIM_L_EVAL_CC(...))` shape and the bare shape), the subroutine
twins `X86_SIM_X86_SUB_JCC`/`X86_SIM_X86_SUB_JMP`/`X86_SIM_X86_SUB_RET`
under `render_x86_subroutine`, and the step-statement layer
`direct_step_statement`/`append_encoded_step` (AUX table versus DIRECT
table versus caller `step_macro`, with the `RUN_OP` fallback shape).
`build/mut_x86_branch_ladder.py` (untracked, harness census 171 -> 172)
closes the gap with 11 rows over a one-file watchlist (the x86
generator, byte-exact restore each row) and one detector: a battery
driving the ladder through FAUX `NativeInsn` fixtures in a fresh
`python -B -c` interpreter with the module `__pycache__` purged around
every battery (no real objdump, no chunked path --- the chunked
renderer keeps its own Step 0296 harness). The battery pins the entry
flow (`X86_SIM_X86_JCC`/`JMP`/`RET`/`CALL` rows plus the fallthrough
exit), both exit-target rewrite shapes announced line-by-line, the
helper-call step (`X86_SIM_L_EXEC_CALL_MEMCPY(64ULL);`), the
reg-indirect `X86_SIM_BPF_CALL_REG(X86_RAX);` row, the subroutine
header plus `SUB_JCC`/`SUB_JMP`/`SUB_RET` twins and the
external-branch `ValueError`, and the statement layer exact strings
(AUX lane-aux `mov bh` pick, plain DIRECT picks, the three `RUN_OP`
fallback shapes). All 11 single-guard/literal flips must break the
battery (no equivalence rows): 11 caught; three byte-identical green
shakes (`TOTAL 11 mutations, 0 failures, 0 equivalence rows`, all md5
`72517c50b2389a94a2ac2fa1c293c403`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0297 - x86 native-link parse coverage

The native-link objdump-feed parse path pinned: `parse_asm_text` (the
objdump `-dr` line reader with relocations and comments),
`section_size`/`rodata_bytes`/`load_rodata16` (the `-h`/`-s` rodata
doubleword map keyed by symtab rodata symbols), `text_symbol_addrs`
(the `-t` `.text` symbol table), `rodata_ident_map` (the generated
`__x86_rodata_{n}` idents), `parse_native_link_blob` (relocation
targets resolved through those symbols),
`normalize_native_link_entry_returns` (the entry-final
`jmp blob_len` repaint into `ret` with the `; native-link entry RET`
marker), and `parse_native_linked_program` (entry/sub split at
non-helper `call` targets plus the external-branch-aware
`max` exit). `build/mut_x86_native_link_parse.py` (untracked, harness
census 170 -> 171) closes the gap with 22 rows over a one-file
watchlist (the x86 generator, byte-exact restore each row) and one
in-process detector: a battery driving the parse layer through FAUX
objdump text in a fresh `python -B -c` interpreter with the module
`__pycache__` purged around every battery, all in-process (no real
objdump). The battery pins `parse_asm_text` over two fixture disasms
(ten-insn locked-`rep movs%` entry ending in a `.text` call with a
`R_X86_64_PLT32` fixup, an inline comment, a `<directived>` label
pseudo-line, plus a two-sub 0x35 blob whose entry ends in an external
`jmp`), `load_rodata16` over a two-symbol fixture (base and octal-safe
offset layers), `rodata_ident_map`, `text_symbol_addrs`,
`section_size`, the blob's `reloc_target` wiring, and one hand-built
normalize-entry probe (the painted `; native-link entry RET` marker
pinned byte-for-byte), plus the entry/sub split for both
fixtures. All 22 single-guard/literal flips must break the battery (no
equivalence rows): 22 caught; four byte-identical green shakes
(`TOTAL 22 mutations, 0 failures, 0 equivalence rows`, all md5
`e1976c6998b37654716aa7199725e4f4`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0295 - x86 render/emission pipeline

The x86 mirror of the arm64 render/emission step: the generator's
render/emission pipeline -- loaders and emitters (`source_prelude`,
`program_kind`, `load_benches`, `annotated_fixed_count_ops`,
`render_program`) -- emitted calls; Step 0293 pinned the encode() ladder
and Step 0290 the parser/AUX layer, but no row mutated the pipeline
itself. `build/mut_x86_render_pipeline.py` (untracked, harness census
168 -> 169) closes the gap with 23 rows over a one-file watchlist (the
x86 generator, byte-exact restore each row) and one in-process detector:
a battery over fixture `NativeInsn`s in a fresh `python -B -c`
interpreter with the module `__pycache__` purged around every battery,
all in-process (no objdump). The battery pins the include rewrite plus
no-SEC empty case, the `c_u64`/`c_ptr_u64` literal shapes, the tag map
over tc/cgroup-skb/xdp plus a YAML fixture driving `load_benches`, the
rep/memcpy fixed-count dataflow (count capture, xor-zero reset, and
overwrite kill), and full-text emission of `render_program` with a
`memcpy` subfunction, a return-dispatch switch, rodata, stack defines,
`X86_SIM_L_EXEC_CMP_MEM` direct step macros, and an xdp-control
variant, plus the external-branch and unresolved-call rejection paths.
Twenty-one guard/constant flips must break the battery and two declared
equivalences (the unsupported-branch and call-message repaints) must
stay green: 21 caught, 2 equivalence; four byte-identical green shakes
(`TOTAL 23 mutations, 0 failures, 2 equivalence rows`, all md5
`d63bb12f8d6536466fdf138e6d733a9e`); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0294 — arm64 render/emission pipeline

The arm64 mirror beyond the encode() ladder: the generator's
render/emission pipeline -- loader/emission helpers (`label`,
`blr_target_reg`, `written_gpr`, `mov_immediate`, `mov_source_gpr`,
`helper_calls_by_addr`, `program_kind`, `default_program_symbol`,
`c_comment`) -- emitted calls; Step 0292 pinned the encode() ladder the
OP arms call, and Step 0290 the parser/AUX selection layer, but no row
mutated the pipeline itself. `build/mut_arm64_render_pipeline.py`
(untracked, harness census 167 -> 168) closes the gap with 21 rows over
a one-file watchlist (the arm64 generator, byte-exact restore each row)
and one in-process detector: a battery over fixture `NativeInsn`s in a
fresh `python -B -c` interpreter with the module `__pycache__` purged
around every battery, all in-process (no objdump). The battery pins the
mode-kind tag map (tc/cgroup-skb/xdp) and default program symbols,
comment/label/c-literal formats, the `blr`-target/written/mov-ext
extractors over their w/x/z/`str` counterexamples, the
`helper_calls_by_addr` dataflow (load id -> blr, copy-through, kill
plus last-ident fallback, `str` preserves flow, unknown reg empty), and
full-text emission pins for `render_program` (stack define,
return-case case-addr, rodata cell, CALL next-address, RET macro,
RUN_OP3 MOV line, prelude carry, SEC + fn name) and
`render_program_compact` (dict/guard/rodata/TC/RET-row/runner PC/JCC
eval/helper dispatch/ret PC), plus map `BPF_MAP_TYPE_ARRAY` +
sanitized-ident emission, the linked-exit writeback tail, and the
compact helper define/switch/call lines. Nineteen guard/constant flips
must break the battery and two declared equivalences (the
call-target and indirect-call message repaints) must stay green: 19
caught, 2 equivalence; four byte-identical green shakes (`TOTAL 21
mutations, 0 failures, 2 equivalence rows`, all md5
`c4fd541d49d861dbf65b5a48df6c0e72`); golden gate `make check` rc 0
with 210 `cross-check: OK` banners.

### Step 0293 — x86 encode() mnemonic dispatch

The x86 mirror of Step 0292: the encode() case ladder in the x86
proof-artifact encoder (`kprog/x86/micro-prog/generate_micro_sim_proofs.py`)
turns each parsed `NativeInsn` into the `EncodedInsn` artifact the
renderer emits; the Step 0290 watchlist pinned the parser/AUX selection
helpers it calls and the per-family harnesses pin the opcode-contract/
CC tables it reads, but no row mutated the dispatch arms themselves.
`build/mut_x86_encode_dispatch.py` (untracked, harness census 166 ->
167) closes the gap with 15 rows over a one-file watchlist (the x86
encoder, byte-exact restore each row) and one in-process detector: a
28-pin battery of `encode()` fixture calls over hand-built `NativeInsn`s
in a fresh `python -B -c` interpreter with the module `__pycache__`
purged around every battery, all in-process (no objdump). The battery
pins the nop/ret arms, JMP/JCC branch targets, PUSH/POP cells,
plain-vs-register CALL, the MOV imm/reg/load/store arms with cell
orderings, the helper-ident load arm, the ALU imm/reg forks, CMP
mem-imm, TEST reg width, CMOV reg/mem arms with the CC AUX, the
high-byte lane AUX (mov bh/mov bh,cl supported with lane AUX;
`or bh, 1` rejected unsupported), DEC/INC-mem/NEG/NOT, SETCC reg/mem,
the scalar-rodata rejection, and the unknown-opcode SystemExit raise.
Fourteen arms must break the battery (the ret/nop arm swaps, the JMP
arm, the MOV immediate/register/load forks, the helper-ident guard,
the scalar-rodata guard, the high_supported disjunction, the SETCC
width repaint, the CMOV memory-arm guard, the PUSH/POP arms, and the
register-CALL arm) and one declared equivalence (the unknown-opcode
message repaint with no pinned observer) must stay green: 14 caught,
1 equivalence; four byte-identical green shakes (`TOTAL 15 mutations,
0 failures, 1 equivalence rows`, all md5 `2af7c44747a5d96ebd526b65d2db4af6`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0292 — arm64 encode() mnemonic dispatch

The encode() case ladder in the arm64 proof-artifact encoder
(`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`) turns each
parsed `NativeInsn` into the `Encoded` artifact the renderer emits
(opcode constant, register cells, width, AUX string, immediate); the
Step 0291 watchlist pinned the selection helpers it calls and the
per-family harnesses pin the ALU/SHIFT/BITFIELD/COND tables it reads,
but no row mutated the dispatch arms themselves (the per-family spec
harnesses mutate the spec JSON/generators/hosts, never the ladder).
`build/mut_arm64_encode_dispatch.py` (untracked, harness census 165 ->
166) closes the gap with 17 rows over a one-file watchlist (the arm64
encoder, byte-exact restore each row) and one in-process detector: a
42-pin battery of `encode()` fixture calls over hand-built `NativeInsn`s
in a fresh `python -B -c` interpreter with the module `__pycache__`
purged around every battery, all in-process (no objdump). The battery
pins the nop/mov-imm/mov-reg arms, the MOVK shift AUX, the ALU and SHIFT
imm-vs-reg forks, the CMP/TST imm fork with its `ARM64_REG_NONE` source
repaint and register modifier parse, the bics-wzr TST-BIC arm with both
wzr and xzr zero pins and destination repaint, the SUBS/ADDS imm forks,
the CCMP condition/nfz AUX imm fork, the CSEL/CSET condition AUX, the
ANDS imm fork with its ror modifier, the load/store width table
(ldrb/ldrh vs ldr), the str base/data cell ordering, the POST/STP-PRE/
stlxr-status register forms, LDRSW, the CMN imm fork, the four FMOV
forms, MVN/CNEG, MADD/UMULL, the ADRP rodata/GOT/helper-rejection arms,
and the unsupported-instruction ValueError raise. Sixteen arms must
break the battery (the mov/ALU/SHIFT/CMP-TST/ADDS/SUBS/CCMP/CMN/ANDS
immediate forks, the movk LSL guard polarity, the bics zero-set arm, the
ldrb/ldrh width table, the store base/data cell swap, the stlxr
status-width pick, the adrp helper-sentinel guard, and the
unsupported-instruction raise) and one declared equivalence (the
unsupported-instruction message repaint with no pinned observer) must
stay green: 16 caught, 1 equivalence; four byte-identical green shakes
(`TOTAL 17 mutations, 0 failures, 1 equivalence rows`, all md5
`cbefd02bf15e5db95106ad0e1db895de`); golden gate `make check` rc 0 with
210 `cross-check: OK` banners.

### Step 0291 — arm64 encoder parse-to-AUX selection

The arm64 mirror of Step 0290: the proof-artifact generator
`kprog/arm64/micro-prog/generate_micro_sim_proofs.py` parses the
`aarch64-linux-gnu-objdump -dr` listing and selects the AUX payload every
emitted step carries, and its consumed tables are pinned
(`mut_arm64_cc_decode.py`, `mut_arm64_helper_idents.py`) while the
selection functions were not: `parse_flat_instructions` (the
bytes/mnemonic line regex, the `//` comment strip, the `R_AARCH64_*`
relocation-symbol attachment to the previous instruction), the
bracket-protected `split_operands`, `reg_const` (the xzr/wzr zero pair,
`sp`, the xN/wN 0..30 range with x31 rejected), `reg_width` (w = 4 bytes
else 8), `parse_imm` (#-prefixed), `parse_shifted_imm` (LSL-only),
`parse_modifier` (the shift `{lsl,lsr,asr,ror}` and extend
`{uxtw,sxtw,uxth,sxth,uxtb,sxtb}` tables), `parse_mem` (the PRE `!` flag
bit 1, the following `#imm` POST flag bit 2, the `inner[1]`
offset-vs-register pick with its modifier), the `mem_aux`
`ARM64_AUX_MEM(...)` string with its `ARM64_MEM_PRE`/`ARM64_MEM_POST` flag
names, and `branch_target`/`reg_or_imm`.
`build/mut_arm64_encoder_selection.py` (untracked, harness census 164 ->
165) closes the gap with 17 rows over a one-file watchlist (the arm64
encoder, byte-exact restore each row) and one in-process detector: the
Step 0290 battery discipline (subprocess `python -B -c` importing the
mutated encoder module with the module's `__pycache__` purged around
every battery) applied preemptively, before any same-size stale-cache
observation could recur. The battery pins a five-instruction arm64 parse
(add shifted-index, pre-indexed str, bl with `R_AARCH64_ABS64` relocation
attachment and symbol capture, ldr with a `//` trailing comment dropped,
and a plain add), the bracket-protected operand split, the zero- pair,
sp/range/x31-rejection, and register-width pins, the `#`-immediate and
LSL-only shifted-immediate pins, the shift/extend modifier pins, and the
memory pins (sign-extended negative offset, index+modifier, PRE/POST/
plain `mem_aux` flag strings, hex branch targets). Sixteen leaves must
break the battery (the relocation attach, the comment strip, the
8-hex-byte width filter, the raw operand/mnemonic repaint, the
zero-register pair, the x30 range bound, the w-width arm, the
`#`-prefix guard, the LSL-only guard, the ror shift arm, the sxtw extend
arm, the POST flag bit, the index pick, the PRE and POST aux repaints,
and the branch hex radix) and one declared equivalence (a duplicate
zero-set member the membership test ignores) must stay green: 16 caught,
1 equivalence; four byte-identical green shakes (`TOTAL 17 mutations, 0
failures, 1 equivalence rows`, all md5 `168dc5e466d0adcbbf4b546bef40f368`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.

### Step 0290 — x86 encoder parser-to-AUX selection

The open-items audit left one uncovered family in the encoder: the
proof-artifact generator `kprog/x86/micro-prog/generate_micro_sim_proofs.py`
parses the `objdump -Mintel` listing and selects the AUX payload every
emitted step carries, and while its consumed tables are pinned (Step 0134's
`mut_x86_cc_decode.py` for CC_AUX, `mut_arm64_helper_idents.py` for the
helper idents) and the simulator-side index/AUX consumers are covered
(`mut_x86_mem_index.py`, `mut_x86_mem_aux.py`), nothing mutated the
selection functions themselves: the objdump-line parser `parse_asm_text`
(address/fields filters, the `lock `-prefix strip, the `#`-comment strip,
the `R_X86_64_*` relocation-symbol attachment to the previous instruction),
the bracket-protected `split_operands`, the register-triple lookup
`reg_info`, the `operand_width` PTR-width arm and default, the
`parse_mem_terms` term parse (base pick, overflow-to-index pick, the
`{1:0,2:1,4:2,8:3}` scale map, the `-`->`+-` negative-displacement rewrite,
integer-displacement accumulation), the `mem_aux` width-keyed
`X86_MEM_AUX_FULL`/`X86_MEM_AUX` pick with its `X86_REG_AUX_SRC_SHIFT` OR,
the `mem_disp`/`branch_target` hex parses with the no-match zero, and the
`enc` opcode resolution whose unknown token exits 1.
`build/mut_x86_encoder_selection.py` (untracked, harness census 163 -> 164)
closes the gap with 12 rows over a one-file watchlist (the encoder,
byte-exact restore each row) and one in-process detector: a pinned fixture
battery run as `python -B -c` against the mutated encoder module, importing
it from `kprog/x86/micro-prog` with the module's `__pycache__` purged around
every battery (a same-size flip like `+=` -> `-=` preserves the file's size,
so a stale bytecode cache could otherwise serve the mutated bytecode even
after the byte-exact restore --- observed live during bring-up). The battery
pins a five-instruction intel-object parse (mov/lea/lock-prefix subl/call,
a relocation line attaching to the previous call, a trailing-comment line,
a label-only and a no-colon skip), the bracket-protected operand split with
a nested comma, the register triple and width pins (PTR case, register
width, default 64), the `enc` resolved `X86_OP_MOV_REG` tuple + dataclass
shape + unknown-token `SystemExit`, and the term-parse pins (base+disp,
negative-disp rewrite, `[rax*4]` scale 2, `[rsp+rax*8]` scale 3, unknown
scale 0, displacement accumulation, the `mem_aux` index/scale/shift string
forms, `mem_disp`, branch targets 0x500/0x1f2 plus the junk-zero, and the
`bpf_` helper-symbol test). Eleven leaves must break the battery (the
fields filter, the lock strip, the comment strip's induced syntax break,
the bracket-depth arm, the register-name lowercasing, the PTR-width case
arm, the negative-displacement rewrite, the scale map swap, the
displacement accumulation sign, the AUX shift OR-to-AND repaint, and the
branch-target no-match fallback) and one declared equivalence (a duplicated
comment-strip repaint the `#` arm discards anyway) must stay green: 11
caught, 1 equivalence; four byte-identical green shakes (`TOTAL 12
mutations, 0 failures, 1 equivalence rows`, md5
`a5fcc91c786fce53c4b73aee84fc1a8a`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0289 — x86 stack-region frame-base resolution chain

The open-items audit left one uncovered piece inside the "mapping from the
simulator's stack region to the abstract frame base": the simulator header's
own resolution chain. Step 0119's `mut_x86_stack_index.py` pins the generated
`KPROG_X86_STACK_INDEX` contract and `mut_x86_stack_arm.py` /
`mut_x86_stack_write_lanes.py` pin the arena routing and the write-lane
region markers, but nothing mutated the header's use of the map:
`X86_SIM_L_STACK_INDEX(OFF) = KPROG_X86_STACK_INDEX(OFF, X86_SIM_STACK_BYTES)`
(the index binding), the `X86_SIM_L_STACK_PTR(OFF)` resolver body (the byte
arena `__x86_stack_mem.b[...]` pick and its sign-extended offset), and the
provenance stamps at the consuming arms (`X86_SIM_TAG_STACK` on the routed
LEA stack arm and on the routed `X86_OP_MOV_REG` stack arm).
`build/mut_x86_stack_region.py` (untracked, harness census 162 -> 163) closes
the gap with 8 rows over a one-file watchlist (`kprog/x86/x86_sim_local_bpf.h`,
byte-exact restore each row) and two detectors
(`det_lea` = rebuild and run `test_x86_lea_route_host`, whose independent
model re-derives the stack-base address; `det_mov` = same for
`test_x86_mov_route_host` over the routed MOV stack arm): five resolver rows
(byte-vs-word arena pick, one-bit index shift, +1 stack-offset drift,
add-inverted index binding, LEA-arm tag repaint) all caught by `det_lea`, two
routed-MOV rows (a `X86_RBP`-pinned source-lane read and a tag repaint) all
caught by `det_mov`, and one equivalence row (the declared stack panel's
inline `(X86_SIM_STACK_BYTES + 7U) / 8U` word count must stay the exact twin
of the generated `KPROG_X86_STACK_WORDS(CAPACITY)` spelling) that must stay
green. All 7 mutations caught, 1 equivalence row green; four byte-identical
green shakes (`TOTAL 8 mutations, 0 failures, 1 equivalence rows`, md5
`7165f21e3283acbec2ebd8500c5af7cd`); golden gate `make check` rc 0 with 210
`cross-check: OK` banners.

### Step 0288 — x86 register-form SETCC spec chain

The spec/generator/artifact chain audit after Step 0287 found exactly one
contract artifact no harness mutates: the register-form SETCC spec JSON
(`x86_setcc_spec.json`) plus its generator (`generate_x86_setcc_spec.py`)
and the rendered `generated/x86_setcc.h` / `KProgFormal/GeneratedX86Setcc.lean`
pair. `mut_x86_setcc.py` mutates the hand module and the host; `mut_x86_cond.py`
runs the generator's `--check` as a shared detector but never rolls a row
against this spec. `build/mut_x86_setcc_chain.py` (untracked, harness census
161 -> 162) closes the gap with 12 rows over a six-file watchlist (spec,
generator, generated header, generated Lean, hand
`X86SetccHandler.lean`; the `test_x86_setcc_host.c` source is snapshotted as
a detector input): four spec-value flips (condition code, boolean
expression, lane name, schema stamp) — each must trip the generator's
pinned-EXPECTED validation inside `--check`; three generator repaints and
two generated-artifact repaints (a condition code 4->43, a lane define
rename, the no-match sentinel 0xffff->0xfffe, the C lane-table repaint, and
the header sentinel assert) — each must stale the byte re-render; three
lean-chain rows over the generated `condOf` table, the generated lane
table, and the hand proof's `cases cond <;> rfl` line — each must fail
`lake build KProgFormal.X86CmovHandler` (the chain that pulls
GeneratedX86Setcc through both setcc handlers and the cmov consumer).
All 12 rows caught; four byte-identical green shakes (`TOTAL 12
mutations, 0 failures, 0 equivalence rows`, md5 `8b4d37f391b5af404694db2476809bbd`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.


### Step 0287 — simulator route/oracle host oracle coverage

The audit of `Makefile`'s 210 host probes against the 160 mutation harnesses
found exactly twelve hosts no earlier harness drove: the arm64 stack-arena,
mem-index, pair_mem, reg-dispatch, reg-presence, vreg, and width-effective
route hosts and the x86 cmp-mem, mov-load, reg-presence, store, and
memory-bit oracles. Every family module behind them is already watched
(rename-bystander coverage), so the new risk these hosts carried was drift
in their own independent-model code — the side that would have to notice a
routed-body regression. `build/mut_route_hosts.py` (untracked, harness
census 160 -> 161) gives each host one row: one single-occurrence anchor
flip in that host's own model (ref_index bias offset +3, absent-width
fallback 64->32, model_index_value witness +1, pair_mem access-arm
inversion, reg-dispatch witness +1, writable polarity flip, vreg acc-arm
lane boundary 2->3, model sign-predicate inversion, ABI-source arm
repaint, sentinel 0xff->0xfe, store width fallback 64->32, and the BT
oracle index mask 0xffffffff->0xfffffffe), then recompiles the mutated
host with the pinned include path and requires the pinned
`cross-check: OK` banner to disappear. All 12 rows caught; four
byte-identical green shakes (`TOTAL 12 mutations, 0 failures`);
golden gate `make check` rc 0 with 210 `cross-check: OK` banners.


### Step 0286 — x86 memory-source ALU handler contract

The memory-source arithmetic composition is hand-written once:
`KProgFormal/X86MemAluHandler.lean` defines the `X86MemArithOp` enum
(add/adc/sub/sbb; consumed by `X86MemStoreAluHandler.lean`'s eight
store-composition theorems), `generatedX86MemArithHandler` (generated
byte-load plus lane arithmetic handlers), `x86MemArithHandlerSpec` (the
independent load/handler specs), `x86_mem_arith_handler_refines` (per-arm
refinement through `x86_mem_load_refines`), and two `native_decide`
examples (16-bit ADC carrying over `0xffff` with packet-to-scalar
provenance; 32-bit borrow with zero-extension).
`build/mut_x86_mem_alu_handler.py` (untracked, census 159 -> 160) plants
11 rows over a two-file watchlist (the family plus its store-front
consumer so the enum alpha rename restores cleanly): a paired lean
detector (full-library `lake build` olean refresh plus `lake env lean`
over both files) and the compiled pinned-OK-banner oracle `x86
memory-ALU handler host cross-check: OK (22048 cases)`. 6 catches
(enum-arm repaint, generated/spec arm swaps, proof-RW drop, per-arm
tactic swap, and expected-state repaint) and 5 documented equivalences
(alpha renames of the spec, the enum across both files, and an example
theorem, plus doc and blank-line repaints). Four byte-identical green
shakes (`/tmp/run0286_{1..4}.txt`, all md5
`5aadd1ec589000f3f924cd4c34e8b0d2`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0285 — shared arm64/x86 next-PC contract

The architectural branch-next-PC model is hand-written once:
`KProgFormal/Arm64ControlFlow.lean` defines `branchPc (take) (fallthrough)
(target) := if take then target else fallthrough`, which all 39 reference
sites across 16 x86 and arm64 branch families compose (both BranchEmit
pairs, the trace walker, and every flag module's `*_branch_refines`), and
proves `arm64_conditional_branch_refines` (`generatedArm64Cond` selects
the same next PC as `arm64CondSpec`). `build/mut_arm64_control_flow.py`
(untracked, census 158 -> 159) plants 9 rows over a 16-module watchlist:
a paired lean detector (full-library `lake build` olean refresh plus
`lake env lean` over `Arm64ControlFlow.lean`, `ControlFlowTrace.lean`,
`Arm64Branch.lean`, and `X86ControlFlow.lean`) and the compiled
pinned-OK-banner oracle `arm64 condition host cross-check: OK (240
cases)`. 5 catches (inverted next-PC select caught by the trace walker,
type repaint, proof-RW drop, binder rename, import drop) and 4
documented equivalences (the 16-file consistent `branchPc` alpha rename
across all 39 sites, the zero-external-ref theorem rename, a
doc-comment repaint, and a blank-line repaint). Four byte-identical
green shakes (`/tmp/run0285_{1..4}.txt`, all md5
`6679b51dc0483e18df9a441a682d40dc`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0284 — x86 ADD/SUB result identity contract

The thin arithmetic-identity modules are hand-written:
`KProgFormal/X86AddResult.lean` proves `ADC(a, b, false) = a + b` plus
the narrowed add-flag step, and `KProgFormal/X86SubResult.lean` proves
`SBB(a, b, false) = a - b`, the narrowed sub-flag step, and the CMP
branch-PC composition; their theorem names are consumed downstream by
`X86AluResultSpec.lean`, `X86AluWriteback.lean`,
`X86CmpOpHandler.lean`, and `X86MemCompareHandler.lean`.
`build/mut_x86_addsub_result.py` (untracked, census 157 -> 158) plants
11 rows over the four-file watchlist (`X86AddResult.lean` +
`X86SubResult.lean` + the two edit-only consumer files
`X86AluWriteback.lean`/`X86AluResultSpec.lean` so alpha-rename restores
are covered): a paired lean detector (`lake build
KProgFormal.X86AluWriteback` olean refresh plus `lake env lean` over
both family modules) and the two compiled pinned-OK-banner oracles
(`x86 alu result arm host cross-check: OK (6304 cases)` and `x86 alu
result route host cross-check: OK (760337 cases)`). 7 catches (spec
repaints `a+b+1`/`a-b-1`, theorem renames, proof-RW reduction in both
step proofs, and the CMP-composition `rw` drop) and 4 documented
equivalences (full alpha renames across every reference site of the
renamed symbols). Four byte-identical green shakes
(`/tmp/run0284_{1..4}.txt`, all md5
`635ba42bcaefb5c946c1c796aa789387`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0283 — x86 INC/DEC flag-body contract

The register INC/DEC contract is hand-written:
`KProgFormal/X86IncDec.lean` states INC as `ADC(value, 1, false)` and
DEC as `SBB(value, 1, false)`, pins the add-arm/sub-arm flag bodies
(incoming carry preserved, ZF/SF/OF regenerated) plus NEG
(`SBB(0, a, false)`), and proves the result, narrowed step, and
branch-PC refinements whose theorem names are consumed downstream by
`X86UnaryWriteback.lean` (the lane handlers) and
`X86CmpOpHandler.lean`. `build/mut_x86_incdec.py` (untracked, census
156 -> 157) plants 19 rows over the two-file watchlist
(`X86IncDec.lean` + `X86UnaryWriteback.lean`): a paired lean detector
(`lake build KProgFormal.X86UnaryWriteback` olean refresh plus
`lake env lean` over both modules) and the compiled pinned-OK-banner
oracle `x86 alu flag arm host cross-check: OK (259 cases)`. 10 catches
(generated/spec result repaints, CF-pin repaint, DEC ZF repaint,
generated flag-body operand drift, downstream lane-handler composition
edits) and 9 documented equivalences (full alpha renames of
definition/theorem names with zero references outside the watched
pair). Four byte-identical green shakes (`/tmp/run0283_{1..4}.txt`,
all md5 `7f87a0b336873af8ae6a2190e9ebd354`) and the golden `make
check` gate (rc 0, 210 `cross-check: OK` banners, cores cleaned) pin
the family.

### Step 0282 — x86 XCHG width-keyed selector contract

The XCHG contract fixes the width-keyed arm selection:
`x86_xchg_spec.json` pins the selector order, the 8-bit width code,
opcode `0x19`, the full-width code, and the two arms;
`generate_x86_xchg_spec.py --check` re-derives the live `X86_OP_XCHG`
arm from the simulator header and byte-re-renders
`generated/x86_xchg.h` (the `KPROG_X86_XCHG_ARM` selector plus five
`_Static_assert`s) and `KProgFormal/GeneratedX86Xchg.lean` (the `Arm`
table, `armOf`/`armOfCode`, effects, width classes). The hand
`KProgFormal/X86XchgHandler.lean` proves the selector, the
pointer-swap cell effect (swap, scalarize, involution), and the
subword width-window writeback. `build/mut_x86_xchg.py` (untracked,
census 155 -> 156) plants 22 rows over the six-file watchlist:
`--check`, two `lake env lean` elaborations, and the two compiled
pinned-OK-banner oracles (`x86 xchg host cross-check: OK (260 cases)`
and `x86 xchg route host cross-check: OK (62725 cases)`). 18 catches
(10 generator byte-render/arm-reroute rows, 4 Lean elaboration rows,
1 compiled-host static-assert drift, 3 route-host selector/cell
drifts) and 4 documented equivalences (green-run failure-path message
repaints and spec spacing). Four byte-identical green shakes
(`/tmp/run0282_{1..4}.txt`, all md5
`43a5f1b28f44876ad879f58b3b5d0c2b`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0280 — x86 stack-arena storage-model contract

The stack-arena contract fixes the arithmetic the stack helpers use to
reach the byte/word union arena: `x86_stack_arena_spec.json` pins the
word shift (3), the 8-alignment mask, the ceil-8 capacity rounding,
the `b-q-union` aliasing, and little-endian8 assembly;
`generate_x86_stack_arena_spec.py --check` byte-re-renders
`generated/x86_stack_arena.h` (the five `KPROG_X86_STACK_*` macros)
and `KProgFormal/GeneratedX86StackArena.lean` (`wordIndex`,
`wordAligned`, `byteAt`, `assembleByte`, `words`). The hand
`KProgFormal/X86StackArena.lean` proves the two views address the same
storage. `build/mut_x86_stack_arena.py` (untracked,
census 153 -> 154) plants 28 rows over the five-file watchlist:
`--check`, two `lake env lean` elaborations, and the compiled
pinned-OK-banner oracle (`x86 stack arena host cross-check: OK
(70571 cases)`). 23 catches (17 generator byte-render rows, 5 Lean
elaboration rows, 1 compiled-host alignment drift) and 5 documented
equivalences (green-run failure-path message repaints, spec spacing,
a theorem rename, and a doc-comment repaint). Four byte-identical
green shakes (`/tmp/run0280_{1..4}.txt`, all md5
`b09ec15f6d54a30acec9f64c3ee37619`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0278 — x86 SETCC_MEM memory-store contract

The SETCC_MEM contract pins one opcode (`0x3e`), one constant byte
width, the AUX source-shift condition byte, and the two
destination-driven tables: `x86_setcc_mem_spec.json` pins the
opcode/condition/width/register rows and the base/arm rows;
`generate_x86_setcc_mem_spec.py --check` byte-re-renders
`generated/x86_setcc_mem.h` (the `KPROG_X86_SETCC_MEM_CONDITION`
extract, the `_BASE`/`_ARM` statement expressions, three
`_Static_assert`s) and `KProgFormal/GeneratedX86SetccMem.lean`
(`conditionCode`, `condOf`/`evalRaw` composed with the generated
register-form table, the register-number tests, `Base`/`arm`, `.w8`).
The hand `KProgFormal/X86SetccMemHandler.lean` proves the condition
composition, base and arm refinements, the null-base facts, and the
raw-aux composes/sound lemmas. `build/mut_x86_setcc_mem.py` (untracked,
census 151 -> 152) plants 33 rows over the six-file watchlist:
`--check`, `lake build` + two `lake env lean` elaborations, and the two
compiled pinned-OK-banner oracles (`x86 setcc_mem handler host
cross-check: OK (1053191 cases)` and `x86 setcc_mem route host
cross-check: OK (8958727 cases)` over the real simulator `SETCC_MEM`
block). 29 catches (17 generator byte-render rows, 8 Lean elaboration
rows, 1 compiled-host condition drift, 3 route-host condition/base
drifts) and 4 documented equivalences (green-run failure-path message
repaints, spec spacing, and a doc-comment repaint). Four byte-identical
green shakes (`/tmp/run0278_{1..4}.txt`, all md5
`ec37c1831ab6ae306e3fc1f39a48ca00`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0276 — x86 memory-offset accumulation contract

The memory-offset accumulation contract pins the effective-address sum
the simulator resolves through: `x86_mem_offset_spec.json` pins
`{base disp, indexed disp_plus_index_scaled, scale shift_log2,
accumulate wrapping64}`; `generate_x86_mem_offset_spec.py --check`
byte-re-renders `generated/x86_mem_offset.h` (the
`KPROG_X86_MEM_OFFSET(AUX, DISP, INDEX_VALUE, HAS_INDEX)` statement
expression — single-evaluation inputs, the index read skipped when
`HAS_INDEX` is false, the `<< scale` contribution cast back to `__s64`)
and `KProgFormal/GeneratedX86MemOffset.lean` (the `value` conditional
over `disp + (index <<< scale)` and the independent `valueSpec` case
table). The hand `KProgFormal/X86MemOffset.lean` proves the generated
conditional equals the case table, the case dispatch, that the plain
arm ignores scale/index, and concrete indexed/wrap examples.
`build/mut_x86_mem_offset.py` (untracked, census 149 -> 150) plants 24
rows over the six-file watchlist: `--check`, `lake build` + two `lake
env lean` elaborations, and the compiled pinned-OK-banner oracle
(`x86 mem offset route host cross-check: OK (2305 cases)` over the real
`X86_SIM_L_MEM_OFFSET` call). 19 catches (13 generator byte-render
rows, 4 Lean elaboration rows, 2 route-host shift/call drifts) and 5
documented equivalences (green-run failure-path message repaints, spec
spacing, a theorem rename, and a doc-comment repaint). Four
byte-identical green shakes (`/tmp/run0276_{1..4}.txt`, all md5
`2f4b2cceec5ec8e16bff1eb7f66f1f07`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0274 — x86 DIV resolved-width case dispatch

The DIV case-dispatch contract pins the four quotient/remainder bodies
the `X86_OP_DIV` arm selects between on the resolved operand width:
`x86_div_spec.json` pins the arms table (b8 byte packed, b16 word, b32
dword, b64 qword with the high_half gate) with width codes 1/2/4/8,
write counts 1/2/2/2, `dividend_high` none/rdx/rdx/rdx, and exactly one
`high_gate` on the default qword arm; `generate_x86_div_spec.py
--check` re-derives the arms/column invariants, re-derives the *live*
arm region from the simulator header (selector routed, each non-default
define routed, default arm, width write, high-half read), and
byte-re-renders `generated/x86_div.h` (the `KPROG_X86_DIV_ARM(WIDTH)`
ternary ladder plus the opcode/count/distinct/width/absent
`_Static_assert` drift checks) and `KProgFormal/GeneratedX86Div.lean`
(the `Arm` enum, per-column `*OfArm` tables, total `armOf` ladder, and
`armOfCode` lookup). The hand `KProgFormal/X86DivHandler.lean` proves
`x86_div_arm_refines` (the generated selector equals the independent
`x86DivArmSpec` width-code ladder), `x86_div_names_refine`,
`x86_div_arm_over_widths`, and the `armOfCode` roundtrip/ddup facts.
`build/mut_x86_div.py` (untracked, census 147 -> 148) plants 39 rows
over the six-file watchlist (spec JSON + generator + generated header +
generated Lean + hand Lean + `x86_sim_local_bpf.h`): `--check`,
`lake build` + two `lake env lean` elaborations, and the two compiled
pinned-OK-banner oracles (`x86 div host cross-check: OK (260 cases)` and
`x86 div route host cross-check: OK (48515 cases)`). 33 catches (23
generator byte-render and arm-region rows, 5 Lean elaboration rows, 1
compiled-host selector drift, 4 route-host case-body drifts) and 6
documented equivalences (green-run failure-path message repaints,
doc-comment repaints, spec spacing, and a theorem rename with no
internal references). Four byte-identical green shakes
(`/tmp/run0274_{1..4}.txt`, all md5
`9d0829df3dfae2e69bfa9587f83a1878`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, cores cleaned) pin the family.

### Step 0272 — x86 pointer-add transition contract

The pointer-add transition contract pins the shared pointer sum +
provenance copy that the LEA, MOV-load-pointer, and arm64 ALU lanes
resolve through: `ptr_add_spec.json` pins the one-line contract
`{schema_version 1, operation ptrAdd64, bits {op add, lhs src, rhs rhs},
tag {op copy, source src}}`; `generate_ptr_add_spec.py --check` re-derives
the field set/operation/bits-expression guards and byte-re-renders both
artifacts (`KProgFormal/GeneratedPtrAdd.lean` with the generic
`{α : Type} [Add α] bits : src + rhs` and `tag : src`, and
`generated/ptr_add.h` with the `KPROG_PTR_ADD64_BITS(SRC_PTR, RHS)
((__u8 *)(SRC_PTR) + (RHS))` / `KPROG_PTR_ADD64_TAG(SRC_TAG) (SRC_TAG)`
macro pair). The consumers are four call sites: the LEA lane's TAG +
BITS pair in `x86/x86_sim_local_bpf.h`, the ALU pointer arm's BITS +
TAG pair in `arm64/arm64_sim_local_bpf.h`, and the hand
`X86LeaHandler.lean` / `X86MovHandler.lean` refinements whose spec
states spell the explicit sum. `build/mut_ptr_add.py` (untracked,
census 145 -> 146) plants 44 rows over the eight-file watchlist (spec
JSON + generator + generated header + generated Lean + hand LEA/MOV
Lean + the two sim headers): `--check`, a five-module `lake build`
fan-in plus two `lake env lean` elaborations, and four compiled
pinned-OK-banner oracles (`x86 LEA host cross-check: OK (61440 cases)`,
`x86 MOV host cross-check: OK (100448 cases)`, `x86 lea route host
cross-check: OK (32641 cases)`, and `arm64 alu operand select route
host cross-check: OK (21688 cases)`). 37 catches (20 generator
byte-render rows, 8 consumer-leak Lean elaborations, 7 sim-header
call-site drifts across the two route hosts, 2 compiled-host macro
drifts) and 7 documented equivalences (green-run failure-path message
repaints, a free-variable tag repaint, a no-op count-0 row, and
comment repaints that keep the line continuation intact). Four
byte-identical green shakes (`/tmp/run0272_{1..4}.txt`, all md5
`a64d478bd3da804dd8b32afde872cb8a`) and the golden `make check` gate
(rc 0, 210 `cross-check: OK` banners, 0 error lines, cores cleaned)
pin the family.

### Step 0270 — ABI-load provenance-tag contract

The ABI-load provenance-tag contract (the two-kind entry discipline every
simulator-side tag stamp resolves through; the spec
`kprog/formal/abi_load_spec.json` pins `{schema_version 1, operation
abiLoad64Tag, kinds [{xdp, data 0 / data_end 8}, {skb, data 208 /
data_end 80}], unknown_tag scalar}` and `kprog/formal/generate_abi_load_spec.py`
re-derives the schema/kind-set/order/ambiguity guards and byte-re-renders both
artifacts — `KProgFormal/GeneratedAbiLoad.lean` (the `Kind` inductive and
`tag {α : Type} (scalar packet packetEnd : α) : Kind -> Int -> α` offset
trees) and `generated/abi_load.h` (the `KPROG_ABI_KIND_{XDP 0U, SKB 1U}` /
`KPROG_ABI_{XDP,SKB}_DATA{,_END}_OFF` defines plus the statement-expression
`KPROG_ABI_LOAD_TAG(KIND, OFFSET, SCALAR, PACKET, PACKET_END)` — on every
`--check`; the hand `TagErasure.lean` carries `readAbi`/`abiTagSpec`, the
`loadAbi64` arms of `stepTagSpec`/`stepArch`/`stepProof`, and the
`step_bits_sound`/`step_tags_sound`/`run_tags_sound` theorems; both sim
headers stamp tags only through the generated macro and `_Static_assert` the
ABI offsets against their entry structs)
now has its own mutation harness, `build/mut_abi_load.py`:
85 rows over the seven-file watchlist (spec JSON + generator + generated
header + generated Lean + hand Lean + both sim headers), snapshotted and
restored byte-exact around every row, four detectors (the generator `--check`
equality and byte renders, `lake build KProgFormal.GeneratedAbiLoad +
GeneratedPtrAdd + TagErasure` then `lake env lean TagErasure.lean`, and the
two compiled, exact-OK-banner-checked route hosts — `x86 mem dispatch route
host cross-check: OK (62 cases)` and `arm64 mem_prepost route host
cross-check: OK (135170 cases)`, driving the x86 ABI pointer-arm route logic
and the arm64 imms {0, 8, -8} grid that keeps all three tag lanes live).
- Catches 66: the 12 spec rows (schema/operation, the xdp/skb data and
  data-end offsets, both kind names, the unknown tag, the kind-order swap,
  and both data-offset key repaints) at the `--check` equality; the 21
  generator rows (the three consumed path constants, the field-set /
  operation / unknown-tag / kind-count / expected-names structural checks,
  the `==`-ambiguity check, the Lean template head/ctors/tagdef rows, the
  C template guard/kind/macro-head/(PACKET)/(PACKET_END)/(SCALAR)/offset
  rows, and the backtick-quoted f-string prefix the Python import
  rejects); the 11 generated-render rows (the two kind defines, the four
  offset defines, the packet-arm repaint, guard + doc repaint on both
  artifacts, and the generated-Lean `Kind`/`tag` renames + xdp arm drift
  the byte compare rejects); the 14 TagErasure Lean rows (the
  `stepTagSpec` loadAbi collapse, the `abiTagSpec` rename and xdp
  packetEnd arm repaint, the `readAbi` rename, the `stepArch` loadAbi
  collapse, the `stepProof` tag drift, the `GeneratedAbiLoad` import and
  namespace bookends, the three soundness-theorem renames each consumed
  inside the module, the `stepTagSpec` def rename, and the `writeTag`
  r0-arm drift); and the 8 sim-header rows (both include repaints, the
  x86 packet tag-arg swap the 62-case host drives to `FAIL (1)`, the
  arm64 packet-end and scalar tag-arg repaints the 135170-case host
  drives to `FAIL (20)` / `FAIL (26)`, and the skb-offset define drift
  breaking both hosts' `_Static_assert`s at compile time).
- Equivalences 19: the nine generator failure-path messages the green run
  never exercises; the four entry-macro declaration lines (x86 XDP/SKB and
  arm64 XDP/SKB kind constants) no watched host instantiates; the two
  pure assert-message repaints per header the pinned runs cannot observe;
  the two in-macro tag-arg repaints the naive restamp-everything route
  hosts cancel; the `GeneratedAbiLoad` doc-line repaint; and the
  `readAbi` skb scalar-vs-packetEnd swap `cases env <;> rfl` still
  discharges.
- Run: four consecutive byte-identical green shakes, `TOTAL 85
  mutations, 0 failures, 19 equivalences survived (66 catches, 19
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~37 s each), tree
  restored each time (no new `git status` entries beyond the pre-existing
  dirty set), census 143 -> 144 untracked harnesses, 0 core dumps;
  `make check` stayed 210 `: OK`.

### Step 0269 — x86 specialization binding

The x86 specialization-dispatch contract (every decided token the simulator
chain, the Lean model, and the artifact encoder route through the five-column
binding is pinned by the generated contract the three consumers share; the
single-line spec `x86_specialization_spec.json` pins 72 `{token, dispatch,
chain_macro, direct_call, aux_call}` rows (49 `directMacro` whose aux-0 call
is the specialized macro, 4 `branchHandler`, 19 `genericRunOp`) plus the
`aux_gated` list of the 6 registers (`MOV_IMM`/`MOV_REG`/`CMP_IMM`/`CMP_REG`/
`TEST_IMM`/`TEST_REG`) whose encoder emits the aux-gated `*_AUX`/`*_STEP`
spelling for nonzero aux; `generate_x86_specialization_spec.py` re-derives
both expected tables, re-parses the `X86_SIM_L_EXEC` chain window in
`kprog/x86/x86_sim_local_bpf.h` against the `KPROG_X86_*_HANDLED` family
gates, and re-renders `generated/x86_specialization.h` (72 lookup cases +
`KPROG_X86_SPEC_COUNT 72U`), `GeneratedX86Specialization.lean` (the `Op`
inductive with the dispatch/chainMacro/directMacro/auxMacro projections), and
the encoder's `x86/micro-prog/generated_x86_specialization.py` (the three
`X86_SPECIALIZATION_*` maps) byte-for-byte on every `--check`; the hand
module `X86Specialization.lean` restates all 72 rows as an independent
`native_decide` table and proves the `stripSuffix`/`noInsertion` lemmas; and
the two hosts discharge the behavioral surface at run time (the 192-case
`test_x86_specialization_chain_host.c` chain oracle re-parses the chain
window and walks every `else`-`if` arm against its SPEC row plus the
whole-namespace token walk, and the 483-case
`test_x86_specialization_host.c` differential contract host drives the real
`X86_SIM_RUN_OP` against the hand-restated emits over both AUX words x both
widths x two value shapes, pinning the 49 direct macros and the full
classification table))
now has its own mutation harness, `build/mut_x86_specialization.py`:
178 rows over the eight-file watchlist (spec JSON + generator + generated
header + generated Lean + hand Lean + the two hosts + the encoder map),
snapshotted and restored byte-exact around every row, four detectors (the
generator `--check` equality and byte renders, `lake env lean` over the
generated and hand modules, and the two compiled, exact-OK-banner-checked
hosts).
- Catches 152: the 102 generator rows the expected-table heads, schema
  guard, canonical lowering, both regex scanners, the nine consumed paths,
  `same_body`/`strip_aux`/`strip_step`, the three Lean templates' joins and
  doc lines, the C count/count-keyword/cases/default renders, and the
  encoder-map rows the byte-exact re-render compares reject; the 20 Lean
  rows (import/namespace bookends, token body, stripSuffix arms,
  no-insertion body, spec/ctor/table drifts, the 2x refines goal, and the
  erased-dups/length arms the elaboration rejects); the 18 chain-oracle
  rows (SPEC table rows, the four header/session reads, the chain-window
  bookends, the opcode walk and 0x gate, the family prefix/member scans,
  the arm-prefix scans, and the OK-banner text the exact pin rejects); and
  the 12 contract-host rows (the header include, the classification-table
  rows, the 49 direct pin, the two emit call sites, the trip wire, and the
  OK-banner text).
- Equivalences 26: the seven failure-path generator messages, the two
  dormant equality guards, and the paren-repair join the green run never
  exercises; the three no-consumer hand theorem renames and one doc
  repaint the chain re-discharges; the chain oracle's ten failure-path
  message repaints plus the dormant family-prefix and count gates; and the
  contract host's default trip-wire the green run cannot observe.
- Run: four consecutive byte-identical green shakes, `TOTAL 178
  mutations, 0 failures, 26 equivalences survived (152 catches, 26
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~93 s each), tree
  restored each time (no new `git status` entries beyond the pre-existing
  dirty set), census 142 -> 143 untracked harnesses, 0 core dumps;
  `make check` stayed 210 `: OK`.

### Step 0268 — x86 opcode mutation coverage

The x86 opcode-number contract (every token the simulator body, the Lean
model, and the artifact encoder name through the symbolic `X86_OP_*` spellings
is pinned to its numeric code by the generated contract the three consumers
share; the single-line spec `x86_opcode_spec.json` pins 72 `{name, define,
code}` cells (`nop` 0x00 through `callMemcpyReg` 0x46 plus the 0xff `ret` gap)
and 5 `{name, define, target}` alias cells resolving the width-suffixed
`movImm64`/`movReg64`/`addImm64`/`addReg64`/`xorReg32` tokens to their
canonicals; `generate_x86_opcode_spec.py` re-derives both expected tables,
re-reads `kprog/x86/x86_sim.h` live through the two define regexes, and
re-renders `generated/x86_opcode.h` (72 token drift asserts + 5 alias identity
asserts + `KPROG_X86_OPCODE_COUNT 72U`), `GeneratedX86Opcode.lean` (the
`Op` inductive with `code`/`define` projections), and the encoder's
`x86/micro-prog/generated_x86_opcode.py` (the `X86_OPCODE` name map and
`X86_OPCODE_NAME` reverse map) byte-for-byte on every `--check`; the hand
module `X86Opcode.lean` restates the 72 explicit token/code pairs and the
constructor list and proves the `x86_opcode_refines` native-decide equality
plus the `x86_opcode_codes_distinct` five-pair sample; and the 2778-case
`test_x86_opcode_host.c` contract host is the sole runtime oracle (the
compile-time asserts pin every token through the `../x86/x86_sim.h` it
includes, and run time re-parses that header so an added, renamed, or dropped
token is caught, not only a changed value: 72 lookup/value cases, the 2556
all-pairs distinctness cases, the whole-namespace coverage walk, and the 5
alias gates plus the count; there is no separate route host))
now has its own mutation harness, `build/mut_x86_opcode.py`:
105 rows over the seven-file watchlist (spec JSON + generator + generated
header + generated Lean + hand Lean + contract host + the encoder map),
snapshotted and restored byte-exact around every row, three detectors (the
generator `--check` equality, all three byte renders, and the live sim-header
scan; `lake env lean` over the generated and hand modules; and the compiled
and exact-OK-banner-checked 2778-case contract host).
- Catches 78: the 7 spec-file rows at the `--check` equality (schema/
  operation and the nop/movImm/ret cells plus two alias-cell drifts), the 26
  generator rows the expected-dict heads/tails, the schema/field guard, the
  five consumed paths, the canonical-name derivation, both regex scanners,
  the seen-set update, and the three render templates' joins and doc lines
  the byte-exact re-render compares, the 8 generated-C header rows (three
  token drift asserts, two alias asserts, count macro, guard, doc line), the
  9 generated-Lean rows (namespace/end bookends, two ctors, two code arms,
  two define arms, doc line), the 12 hand-Lean rows (import/namespace
  bookends, the two def renames, three pair/ctor drifts, the refines goal,
  and the distinctness arm the elaboration rejects), the 10 host rows (the
  sim-header include, two table rows, the `sim_define_value` call, the walk
  prefix and gate, two alias gates, the count pin, and the OK-banner text
  the exact pin rejects), and the 6 encoder-map rows (the two table blobs
  and the nop/ret entries in both directions).
- Equivalences 27: the twelve failure-path generator messages and seven
  dormant equality-guard repaints the green run never exercises, the two
  no-consumer hand theorem renames and one doc repaint the chain
  re-discharges, and the host's dormant duplicate-check guard, three
  FAIL-path message repaints, and doc line the pinned-OK run cannot observe.
- Run: four consecutive byte-identical green shakes, `TOTAL 105
  mutations, 0 failures, 27 equivalences survived (78 catches, 27
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~15 s each), tree
  restored each time (no new `git status` entries beyond the pre-existing
  dirty set), census 141 -> 142 untracked harnesses, 0 core dumps;
  `make check` stayed 210 `: OK`.

### Step 0267 — x86 register-dispatch mutation coverage

The x86 sixteen-cell register-number contract (every register-lane helper and
the simulator's subgroup/filter operations consume the register number through
the hand-written `X86_SIM_L_FOR_EACH_GPR` X-macro dispatch and the
`X86_SIM_L_REG_VALUE` read ternary chain; the single-line spec
`x86_reg_dispatch_spec.json` pins sixteen `{name, define, number}` rows
`rax..r15` in `X86_RAX..X86_R15` order with numbers `0..15`, the 8-bit number
width (`reg_bits`), the `gpr_count` 16, and the `0xff` no-register sentinel;
`generate_x86_reg_dispatch_spec.py` re-renders `generated/x86_reg_dispatch.h`
and `GeneratedX86RegDispatch.lean` byte-for-byte; the generated header pins
`KPROG_X86_GPR_COUNT 16U`, the identity cell selector
`KPROG_X86_GPR_CELL(REG) ((__u8)((REG)))`, and sixteen `_Static_assert`s
binding the hand-written `X86_R<n>` decodes plus the count assert; the hand
module `X86RegDispatch.lean` restates the `finRange` twin tables and the
literal-bound `cellOf` and proves twenty theorems including
`first_non_gpr_is_none`, `sentinel_is_none`, `full_range`, and
`case_dispatch`; the 258-case `test_x86_reg_dispatch_host.c` contract host
drives the generated cell/count macros over all 256 number bytes plus the
count pin and four decode constants, and the 6401-case
`test_x86_reg_dispatch_route_host.c` route host plants each of the 256
numbers through the real `X86_SIM_L_WRITE_REG_WIDTH` write dispatch observing
the changed cell via the cell tag at 4 widths x 6 values, then reads back
through the real `X86_SIM_L_READ_REG` chain)
now has its own mutation harness, `build/mut_x86_reg_dispatch.py`:
118 rows over the eight-file watchlist (spec JSON + generator + generated
header + generated Lean + hand Lean + contract host + route host + the
`x86_sim_local_bpf.h` routing region: the generated-header include, the
three cell-drift asserts, the `X86_SIM_L_FOR_EACH_GPR` X-macro rows, the
`X86_SIM_L_REG_VALUE` ternary chain, and the `X86_SIM_L_READ_REG` width
wrapper), snapshotted and restored byte-exact around every row, four
detectors (the generator `--check` equality and byte renders, `lake build
KProgFormal.GeneratedX86RegDispatch` + both Lean elaborations, the compiled
and exact-OK-banner-checked 258-case contract host, and the 6401-case route
host compile/run).
- Catches 100: the 7 spec-file rows at the `--check` equality (schema/
  operation/reg_bits/gpr_count/sentinel and two cell drifts), the 34
  generator rows the expected-dictionary keys and render templates the
  byte-exact re-render compares, the 5 generated-C header rows (count/cell
  macro bodies, count assert, guard, and the include doc-line the byte
  compare rejects), the 9 generated-Lean rows (namespace/end/count/bits/
  tables/cellOf/none-repoint drifts the build rejects), the 24 hand-Lean
  rows (signature/theorem-body/goal drifts the build or elaboration
  rejects), the 21 route-detector rows (the sim-header include/X-row/
  drift-assert/read-chain drifts and the route host's model/count/banner
  drifts), and the 6 contract-host rows (model/count/banner drifts the
  exact-pin rejects).
- Equivalences 18: the six failure-path generator messages and the
  duplicated define-load repaint the OK run never prints, the one no-consumer
  generated-Lean doc repaint (`gprCount` comment), the seven no-consumer
  hand theorem renames the chain re-discharges, the two FAIL-banner
  repaints the rc-only checks cannot see, and the shadowed
  `X86_SIM_L_READ_REG` wrapper-shift repaint the width-shift call sites
  control.
- Run: four consecutive byte-identical green shakes, `TOTAL 118
  mutations, 0 failures, 18 equivalences survived (100 catches, 18
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~29 s each), tree
  restored each time (no new `git status` entries beyond the pre-existing
  dirty set), census 140 -> 141 untracked harnesses, 0 core dumps;
  `make check` stayed 210 `: OK`.

### Step 0266 — x86 ptr-write handler mutation coverage

The x86 two-opcode pointer-write provenance contract (`X86_OP_MOV_LOAD_MAP_PTR`
0x2c / `X86_OP_MOV_LOAD_HELPER_ID` 0x2d install pointer bits together with a
provenance tag and no width-confined lane: the chained selector
`KPROG_X86_PTR_WRITE_TAG(IS_MAP_PTR, IS_HELPER_ID)` tests the two opcode facts
in that order (scalar 0 / mapPtr 5 / helperId 7, pinned to the sim's
`X86_SIM_TAG_*` values, out-of-range fallthrough
`KPROG_X86_PTR_WRITE_TAG_ANY 0xff`), `KPROG_X86_PTR_WRITE_IS_HELPER_ID` gates
the helper-id arm's preliminary width-64 scalar lane write which the pointer
write then replaces bit for bit, both arms perform the pointer write through
`X86_SIM_L_WRITE_REG_PTR_TAG`, and a tag code is not a width so neither opcode
consults the FLAGS width the dispatch chain computed;
`x86_ptr_write_spec.json` -> `generate_x86_ptr_write_spec.py` re-checks the
whole exact-match expected dictionary and byte-for-byte re-renders
`GeneratedX86PtrWrite.lean` + `generated/x86_ptr_write.h`, which adds the
`0x2c`/`0x2d` opcode and three tag static asserts plus the two selector
macros; the hand module `X86PtrWriteHandler.lean` restates the tag/code/
selector/width64 tables and the whole-immediate pointer bits and proves the
step refinement, the helper-id absorb and map-pointer no-scalar-write and
never-scalarizes lemmas, the `X86_REG_NONE` fallthrough, and the canonical
examples; the 318-case `test_x86_mov_load_map_ptr_host.c` contract host drives
the generated macros exactly as the two `X86_SIM_L_EXEC` arms call them
against a hand-written arm model comparing the whole register file, the
lane-write count, and the flags)
now has its own mutation harness, `build/mut_x86_ptr_write.py`:
121 rows over the six-file watchlist (spec JSON + generator + generated
header + generated Lean + hand Lean + contract host), snapshotted and
restored byte-exact around every row, three detectors (the generator
`--check` equality and byte renders, `lake build
KProgFormal.GeneratedX86PtrWrite` + both Lean elaborations, and the compiled
and exact-OK-banner-checked host, banner `OK (318 cases)` pinned).
- Catches 106: the spec-file rows (schema/operation/selector keys, the tag
  and opcode table cells, the width64 flips, and the tag crosspaints), the
  40 generator rows the expected-dictionary and render-template byte
  compares catch, the generated-C macro bodies the `--check` byte
  compare rejects, the generated-Lean code/tagOf/width64 arms and selector
  rows, and the hand-Lean signature/theorem-body rows the build rejects
  (the 24 Lean catches split 9 generated-Lean and 21 hand-Lean rows; no
  host-detector or banner rows exist in this harness).
- Equivalences 15: the three failure-path generator message repaints
  (stale/order/duplicate) the OK run never prints, and the twelve no-consumer
  hand theorem renames the chain re-discharges
  (tag-code/tag-select/all-reachable/width64-map/step/step-fields/bits-id/
  bits-example/none-fallthrough/helper-absorbs/map-no-scalar/
  never-scalarizes).
- Run: four consecutive byte-identical green shakes, `TOTAL 121
  mutations, 0 failures, 15 equivalences survived (106 catches, 15
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~33 s each), tree
  restored each time (no new `git status` entries beyond the pre-existing
  dirty set), census 139 -> 140 untracked harnesses, 0 core dumps;
  `make check` stayed 210 `: OK` (no new oracle hosts).

### Step 0265 — x86 IMUL reg-imm handler mutation coverage

The x86 register-source `IMUL` immediate handler-composition contract
(the hand Lean restatement `X86ImulRegImmHandler.lean` is the whole
contract: `generated_imul_reg` decodes the whole raw immediate through
`KPROG_X86_IMMEDIATE_VALUE` and sign-extends it at the destination
width, multiplies in 64-bit wrap-around arithmetic, drives the
`KPROG_X86_SET_IMUL_FLAGS` funnel over the two abs values and the
sign-or-complement limit branch, and writes back through the
width-confined `generatedX86RegWrite`, the spec twin restates the same
composition over `x86RegWriteSpec`/`x86ImulFlagsApplied`, and the
module proves the step refinement, the preserve lemma, and the
w16/w64/w8 example pins; the 41296-case
`test_x86_imul_reg_imm_handler_host.c` differential host drives the
generated macros against an independent `__int128` oracle over the
18-element boundary table (418 sweep scenes x 4 widths) plus 40,000
LCG iterates)
now has its own mutation harness, `build/mut_x86_imul_regimm.py`
(untracked, census 138 -> 139): 92 rows over the two-file watchlist
(hand Lean + contract host), snapshotted and restored byte-exact
around every row, two detectors (`lake build
KProgFormal.X86ImulRegImmHandler` + the module elaboration, and the
compiled and exact-OK-banner-checked host, banner `OK (41296 cases)`
pinned).
- Catches 63: the Lean side (both def names, the full
  writeback+flags-body composite drifts the build rejects, the spec
  rhs/flags composite, the preserve lemma zf-gap, the snext-val and
  the w16/w64/w8-mix/w8-in example dst/output/flag drifts), and the
  host side (the width/mask/sext/immediate tables, the generated
  rhs/abs/limit/flags/writeback arms, the oracle rhs/cast/lo/hi/
  overflow-bound/write arms, the same-result compare tail, the check
  want-swap, the sweep width/a/c dims, the LCG iterate dim, and the
  OK banner repaint the exact-pin check catches).
- Equivalences 29: the Lean theorem renames and the preserves rfl
  proof-comment repaint the chain re-discharges, the w16 example
  state drift the drive recomputes, the host flag-seed shift repaints
  and the check name repaint the shared-input lockstep cannot
  distinguish, the v-table and w-table boundary drifts both drives
  recompute identically, the sweep imm-index swap (`(a+c)` ->
  `(c+a)`), the LCG seed/constant/call-index repaints the checked
  outputs cannot observe, and the failure-path banner/mismatch
  repaints the OK run never prints.
- Run: three consecutive byte-identical green shakes, `TOTAL 92
  mutations, 0 failures, 29 equivalences survived (63 catches, 29
  equivalent survivors)` / `ALL AS EXPECTED` rc 0 (~17 s each), tree
  restored each time (no new `git status` entries beyond the
  pre-existing dirty set), census 138 -> 139 untracked harnesses, 0
  core dumps; `make check` stayed 210 `: OK` (no new oracle hosts).

### Step 0264 — x86 IMUL route handler mutation coverage

The x86 `IMUL` route contract (the signed-multiply flag funnel the
simulator applies through `X86_SIM_L_SET_IMUL_FLAGS`: the effective
width resolves through `X86_SIM_L_EFFECTIVE_WIDTH`, the two operand
abs values narrow through `x86_signed_abs_width`, the limit is the
sign-or-complement branch `(LHS ^ RHS) & sign ? sign : sign - 1`,
and the generated `KPROG_X86_SET_IMUL_FLAGS` macro folds
`ov = a_abs != 0 && b_abs > limit / a_abs` into `cf` and `of`;
`X86_SIM_L_EXEC_IMUL_IMM`/`_MEM_IMM` restate the body over the sign-
extended immediate and its dispatcher arms; the hand Lean restatement
`X86ImulRegImmHandler.lean` proves the reg-imm step refinement, the
preserve lemma, and the w16/w64/w8 example pins;
`X86MemImulHandler.lean` the memory-side one; the 518-case
`test_x86_width_effective_route_host.c` route host drives the funnel
scenes, the exact `(0xff, 2)` mc input, and the imul-imm/mem-imm
scenes on the `(w, eff_of(w))` pair)
now has its own mutation harness, `build/mut_x86_imul_route.py`:
52 rows over the five-file watchlist (hand Lean + mem Lean + signed
Lean + route host + sim header), snapshotted and restored byte-exact
around every row, two detectors (`lake build` + both Lean
elaborations, and the compiled and exact-OK-banner-checked route
host).
- Catches 26: the hand restatement (generated/spec ext widths,
  the reg-imm flags-apply and writeback narrowing, the spec rhs
  swap, the preserve-pair swap, the w16/w64/w8 example value and
  tag drifts, the doubled-`not_false` decide), the mem side
  (generated/spec load and result widths and the
  `x86MemLoadSpec` hload rename), the signed arm (`.w16` sign bit)
  and its `simp` tail, the route host (the mc `of` inversion, the
  two model-only literal drifts — value divergence or the exact
  `518 cases` banner), and the sim header (the `1U` sign-extend
  width and the two broken `#define` param renames).
- Equivalences 26: the reg-imm theorem renames and the simp-list
  reorder (the chain re-discharges), the scene-operand repaints
  (`check_equiv` drives a scene against itself at `(w, eff_of(w))`,
  so operand shifts move both drives identically), the mc fixed
  `(0xff, 2)` grid whose funnel computes `ov = 0` at every width
  the model mirrors, the `x86_signed_abs_width` boundary
  coincidences at `+1`, the flag-arm-table rows the 518 host never
  drives (the ARM selector oracle belongs to
  `mut_x86_alu_flag_arm`), and the dispatcher arm rotation the
  scenes cannot distinguish.
- Run: three consecutive byte-identical green shakes, `TOTAL 52
  mutations, 0 failures, 26 equivalences survived` / `ALL AS
  EXPECTED` rc 0 (~40 s each), tree restored each time (no new `git
  status` entries beyond the pre-existing dirty set), census 137 ->
  138 untracked harnesses, 0 core dumps; `make check` stayed
  210 `: OK` (no new oracle hosts).

### Step 0263 — x86 MOVX register-source handler mutation coverage

The x86 `MOVX` register-source contract (the sign/zero-extension
composition the simulator's register-source MOVX arm applies through
`X86_SIM_L_EXEC_MOVX_REG`: the source width is the decoded AUX code
`KPROG_X86_MOVX_SRC_WIDTH` with the effective-width default for the
absent code, the shape is the opcode selector
`KPROG_X86_MOVX_SHAPE` — MOVZX narrows the source lane, MOVSX
sign-extends it — and the writeback is the effective width with a
scalar tag; the hand Lean module `X86MovxRegHandler.lean` restates
`x86MovxRegStepSpec` and proves the step refinement, the scalar tag
stamp, the narrowing idempotence, the upper-source-bit irrelevance,
and the `cdqe`/`movsxd` decodings; the 62,409-case
`test_x86_movx_reg_host.c` contract host drives the generated macros
against a sign-arith oracle over every (opcode, raw width, source
width) triple with boundary sources and the fixed-seed LCG sweep; the
518-case `test_x86_width_effective_route_host.c` route host pins the
absent-code-equals-64 route identically on both drives)
now has its own mutation harness, `build/mut_x86_movx_reg.py`:
84 rows over the five-file watchlist (hand Lean + contract host +
shape Lean + route host + sim header), snapshotted and restored
byte-exact around every row, three detectors (`lake build` +
both Lean elaborations, the compiled and exact-OK-banner-checked
contract host, and the route host).
- Catches 53: the hand restatement (generated/spec arm widths, refine
  `simp` names, the refine equality itself, the `cdqe`/`movsxd`
  decode pins, the example and idempotence/tag/upper-mask theorems),
  the contract host (the sign/zero arm calls, the write-back byte
  lanes and width cases, the oracle masks/sign/zero-return/
  sign-taken arms, the output tag, the LCG iteration drop, the
  identity-check polarity, and the OK banner), and the route host
  (the `movx_reg` call drop, the model w32 mask arm, and the
  widths-loop truncation — divergence or the exact `518 cases`
  banner).
- Equivalences 31: the grader-side fixture repaints both drives
  recompute (the `zx16_want_lo` value drift is caught by the example
  pin while the gh-tag renames just repaint), the incoming-seed and
  LCG-constant drifts the checked outputs cannot observe, the
  orphaned `0x7fffffff` movzx/movsx coincidence, the failure-path
  banner/label repaints success never prints, the single-driver value
  coincidences the w32 model arms keep, and the six `aux==0` inert
  sim-header body lines (`X_SA_SIGN`/`X_SA_ZERO`/`X_RT_SIGN`/
  `X_RT_ZERO`/`X_SA_WR`/`X_RT_WR`) whose sign-vs-zero arm value and
  writeback width the raw-vs-effective pair cannot distinguish on
  `src_width == width` (the value-level dispatcher oracle lives in
  `mut_x86_movx_shape.py`'s `model_movx` pair).
- Run: three consecutive byte-identical green shakes, `TOTAL 84
  mutations, 0 failures, 31 equivalences survived` / `ALL AS
  EXPECTED` rc 0 (~60 s each), tree restored each time (no new `git
  status` entries beyond the pre-existing dirty set), census 136 ->
  137 untracked harnesses, 0 core dumps; `make check` stayed
  210 `: OK` (no new oracle hosts).

### Step 0262 — x86 REP MOVS block-copy mutation coverage

The x86 `REP MOVS` block-copy contract (`x86_rep_movs_spec.json`
-> `generate_x86_rep_movs_spec.py` -> `generated/x86_rep_movs.h`
+ `KProgFormal/GeneratedX86RepMovs.lean`, restated independently by
`KProgFormal/X86RepMovsHandler.lean`, checked by the 67-case
`test_x86_rep_movs_host.c` oracle over the five width codes and ten
counts, and consumed by the real `X86_OP_REP_MOVS` arm in
`x86/x86_sim_local_bpf.h` through
`KPROG_X86_REP_MOVS_WIDTH/_BOUND/_COUNT_WIDTH`, which the 127-case
route-oracle `test_x86_rep_movs_route_host.c` drives through
`X86_SIM_L_EXEC_REP_MOVS` over the same sweeps plus
offset/window/absent-width/clobber variants and the nine macroChecks)
now has its own mutation harness, `build/mut_x86_rep_movs.py`:
149 rows over the eight-file watchlist (spec JSON + generator +
generated header + generated Lean + hand Lean + contract host + route
host + sim header), snapshotted and restored byte-exact around every
row, with four detectors (generator `--check` byte-exactness — it
byte-compares BOTH rendered files, so any generated-C or generated-Lean
drift the lean chain no longer binds is still caught there —, the
`lake build KProgFormal.GeneratedX86RepMovs/GeneratedX86Width` +
`lake env lean X86RepMovsHandler.lean` chain, the contract host
compile/run, and the route host compile/run).
- Catches 107: the spec schema/operation/selector/opcode/bound/width
  drifts, the generator expected-table and render-template drifts (the
  stale-gate repaint, the Lean bound/default/count rows, the resolve
  ladder, the element-count line, the POP-doc drift, and the rendered
  C block/width/bound comments and macro assert), the generated-C
  constants (caught by `--check` byte-diff or by route-host
  assertion/compile), the generated-Lean bound/default/count/resolve
  drifts, the hand-Lean restatement drifts (bound, width arms, element
  count and count width, RCX zeroing, stride/advance bodies, and the
  proof-tail `simp`/`rfl` anchors), host model/contract/part2/pin
  drifts, route-model/bound/elements/copy/pointer/config-check drifts,
  and the 14 sim-header routed-body repaints (guard, addresses,
  load/store call forms, exec width/count/tags/loop/pointers/RCX)
  whose compile breaks on the repainted identifiers or whose behavior
  diverges the 127-case sweep.
- Equivalences 42: the 24 hand-Lean theorem renames (the hand module
  has zero external Lean consumers — renames still elaborate), the
  four generator error-message wording repaints (`--check` never reads
  the invalid-input paths), the host and route OK-banner repaints, the
  part2/macro fixture repaints that both sides recompute symmetrically
  (scenario-list value drifts keep every model-vs-body comparison
  true), the pin-2 count 100-to-101 drift past the literal bound (all
  pins still hold), the RCX sentinel value repaint (the body zeroes
  RCX after the plant), the dst-memcmp one-byte tail shorten (the tail
  never diverges: expected is copied from the pristine buffer before
  the run), and the sim-header displacement-gate/exec-line comment
  repaints.
- Run: three consecutive byte-identical green shakes, `TOTAL 149
  mutations, 0 failures, 42 equivalences survived` / `ALL AS EXPECTED`
  rc 0 (~43 s each), tree restored each time (no new `git status`
  entries beyond the pre-existing dirty set), census 135 -> 136
  untracked harnesses, `make check` expected still 210 `: OK` (no new
  oracle hosts).

### Step 0261 — x86 DIV resolved-width case-dispatch mutation coverage

The x86 `DIV` case-dispatch contract (`x86_div_spec.json`
-> `generate_x86_div_spec.py` -> `generated/x86_div.h`
+ `KProgFormal/GeneratedX86Div.lean`, restated independently by
`KProgFormal/X86DivHandler.lean`, checked by the 260-case
`test_x86_div_host.c` oracle over the whole selector byte range, and
consumed by the real `X86_OP_DIV` arm in `x86/x86_sim_local_bpf.h`,
which the 48515-case route-oracle `test_x86_div_route_host.c` drives
through `X86_SIM_L_EXEC` over the five resolved width codes, 2 source
registers, 7 dividends, 3 high halves, and 7 divisors) now has its own
mutation harness, `build/mut_x86_div_route.py`: 114 rows over the
eight-file watchlist (spec JSON + generator + generated header +
generated Lean + hand Lean + contract host + route host + sim header),
snapshotted and restored byte-exact around every row, with four
detectors (generator `--check` byte-exactness — the only detector that
reads the generator and the sim header, so it also catches routed-arm
gate repaints —, the `lake build` + `lake env lean X86DivHandler.lean`
chain, the contract host compile/run, and the route host compile/run).
- Catches 88: spec drifts, the generator expected-table and template
  drifts (including the `ARM_*` sim-header window anchors, the rendered
  Lean ladder join and C width tests/distinct assert), the generated-C
  constants (collide at rendered constants count, byte-diff at `--check`),
  generated-Lean drifts, the hand-Lean restatement swaps, host model and
  check drifts, the route-host model/state-desync drift, selector and
  scalarization catches, resolve-width drift, and the five sim-header arm
  repaints.
- Equivalences 26: the 21 consumed hand-Lean theorem renames, the host
  and route OK-banner repaints, the unreachable route MISMATCH message
  repaint, the flags comment repaint, and the IMM-1 unconsumed
  engineering call (live-proven: 48515 cases unchanged, including the
  untouched flags).
- Run: three consecutive byte-exact green shakes, `TOTAL 114 mutations,
  0 failures, 26 equivalences survived` / `ALL AS EXPECTED` rc 0
  (~34 s each), tree restored each time (no new `git status` entries
  beyond the pre-existing dirty set), census 134 -> 135 untracked
  harnesses, `make check` expected still 210 `: OK` (no new oracle
  hosts).

### Step 0260 — x86 register-presence mutation coverage

The x86 operand-register presence contract (`x86_reg_presence_spec.json`
-> `generate_x86_reg_presence_spec.py` -> `generated/x86_reg_presence.h`
+ `KProgFormal/GeneratedX86RegPresence.lean`, restated independently by
`KProgFormal/X86RegPresence.lean`, checked by the 768-case
`test_x86_reg_presence_host.c` oracle over the full byte range, and
consumed by the memory-operand bodies in `x86/x86_sim_local_bpf.h`
through the `KPROG_X86_REG_PRESENT`/`KPROG_X86_REG_ABSENT` guards at
more than a dozen sites) now has its own single-anchor mutation harness,
`build/mut_x86_reg_presence.py`: 56 rows over the six-file watchlist
(spec JSON + generator + generated header + generated Lean + hand Lean
+ contract host driver), snapshotted and restored byte-exact around
every row, with three detectors (generator `--check` byte-exactness, the
`lake build KProgFormal.GeneratedX86RegPresence/MemIndex/MemAux` +
`lake env lean X86RegPresence.lean` chain — consumer-aware, since the
hand module plays the sentinel links to the memory-index and packed-AUX
sentinels — and the contract host compile/run).
- Catches 45: spec operation/reg_bits/sentinel/arm-flag drifts, the
  generator EXPECTED/render-template drifts (Lean arm selector and both
  row ladders, C present/absent/arm ternaries), generated-C
  present/absent polarity and swap drifts, the arm-code constants (both
  directions, caught exactly when the two arm codes collide), the
  sentinel drift, generated-Lean arm swap/row flips/sentinel drift and
  namespace repaint, hand-Lean arm/present/absent spec swaps, the
  complement-line tag, the sentinel `_0xff`-pin drift, the
  sentinel-absent arm flip, the index-sentinel link width repaint, the
  namespace drift, and the host oracle polarity/swap/want-arm/cross/
  arm-agree/sentinel-check drifts.
- Equivalences 11: five unreachable generator error-message repaints
  and the stale-gate repaint (the `--check` branch no longer reads
  EXPECTED drift), the three hand-module consumed-theorem renames that
  the elaboration does not bind textually (`arm_refines`,
  `present_refines`, `absent_refines`), the two hand-module
  conclusion renames (`case_dispatch`, `examples`), and the host
  OK-banner repaint.
- Run: three consecutive byte-exact green shakes, `TOTAL 56 mutations,
  0 failures, 11 equivalences survived` / `ALL AS EXPECTED` rc 0
  (~11 s each), tree restored each time (no new `git status` entries
  beyond the pre-existing dirty set), census 133 -> 134 untracked
  harnesses, `make check` expected still 210 `: OK` (no new oracle
  hosts).

### Step 0259 — x86 register-lane AUX mutation coverage

The x86 register-lane AUX packed-layout contract
(`x86_reg_lane_aux_spec.json` -> `generate_x86_reg_lane_aux_spec.py` ->
`generated/x86_reg_lane_aux.h` + `KProgFormal/GeneratedX86RegLaneAux.lean`,
restated independently by `KProgFormal/X86RegLaneAux.lean`, checked by the
7629-case `test_x86_reg_lane_aux_host.c` oracle, the sim-header
static-assert lane pins, and the routed decoders inside
`x86/x86_sim_local_bpf.h`'s ALU/CMP/MOV/SETCC step bodies that the
760337-case `test_x86_alu_result_route_host.c` and 21764-case
`test_x86_mov_route_host.c` oracles drive via the vendor libbpf include
path, plus the fourth `--check` render target
`x86/micro-prog/generated_x86_reg_lane_aux.py` consumed by
`generate_micro_sim_proofs.py`) now has its own single-anchor mutation
harness, `build/mut_x86_reg_lane_aux.py`: 111 rows over the eight-file
watchlist (spec JSON + generator + generated header + generated Lean +
hand Lean + contract host driver + encoder + the routed
`x86/x86_sim.h`/`x86_sim_local_bpf.h` call sites), snapshotted and
restored byte-exact around every row, with four detectors (generator
`--check` byte-exactness, the `lake build
KProgFormal.X86RegLaneAux/X86AluDecode/X86SetccHandler` +
`lake env lean` chain — consumer-aware, since X86AluDecode and
X86SetccHandler play the hand-module roundtrip theorems — the contract
host compile/run, and the ALU-result + cmpop route hosts compile/run).
- Catches 90: spec field-name/shift/mask/order and
  `valid_byte_shifts` drifts, the generator EXPECTED/render template
  drifts (Lean pack/decoders, C packer/decoders, the encoder
  `VALID_BYTE_SHIFTS` policy), generated-C packer/decoder drifts caught
  at host compile/run, generated- and hand-Lean packer/decoder drifts and
  the consumed-theorem renames caught by the lake chain
  (`payload_roundtrip`/`dst_roundtrip` renamed under
  `X86SetccHandler`/`X86AluDecode`), the sim-header static-assert
  value repaints caught at host compile, and the routed call-site
  repaints caught through the route hosts (ALU immediate payload lane,
  ALU register source lane zeroing, CMP mem-reg lane swaps).
- Equivalences 21: three unreachable generator error-message repaints,
  the unconsumed hand renames (`src_roundtrip`, `pack_refines`,
  `fields_non_interfering`, `typed_lanes_roundtrip`, `example`, the
  `x86ByteShiftSpec src` + 0 tautology), byte-level surface repaints
  that no driven byte distinguishes (decoder trailing-whitespace and the
  `dst_shift + 0` f-string repaint are caught, but the sibling-decoder
  swaps at the MOV-IMM/MOV-REG/SETCC/UNARY call sites and the
  `0xaU ^ 0xff` payload-lane pin survive because the driven aux lanes
  are always equal), the host top-byte pin drop (the 19^3 grid already
  forces byte lanes), the exhaustive-loop transpose, the case-count
  print gate, the OK-banner repaint, the failure-gate repaint, and the
  packer trailing-whitespace repaint.
- Run: three consecutive byte-exact green shakes, `TOTAL 111 mutations,
  0 failures, 21 equivalences survived` / `ALL AS EXPECTED` rc 0
  (~59 s each), tree restored each time (no new `git status` entries
  beyond the pre-existing dirty set), census 132 -> 133 untracked
  harnesses, `make check` expected still 210 `: OK` (no new oracle
  hosts).

### Step 0258 — x86 memory-AUX mutation coverage

The x86 memory-AUX packed-layout contract (`x86_mem_aux_spec.json` ->
`generate_x86_mem_aux_spec.py` -> `generated/x86_mem_aux.h` +
`KProgFormal/GeneratedX86MemAux.lean`, restated independently by
`KProgFormal/X86MemAux.lean`, checked by the 7904-case
`test_x86_mem_aux_host.c` oracle and the sim-header alias asserts +
3650-case `test_x86_mem_read_dispatch_host.c` route oracle) now has its
own single-anchor mutation harness, `build/mut_x86_mem_aux.py`: 90 rows
over the seven-file watchlist (spec JSON + generator + generated header +
generated Lean + hand Lean + contract host driver + the routed
`x86/x86_sim.h` AUX alias region), snapshotted and restored byte-exact
around every row, with four detectors (generator `--check`
byte-exactness, the `lake build KProgFormal.X86MemAux` +
`lake env lean` chain, the contract host compile/run, and the
mem-read-dispatch route host compile/run requiring the vendor libbpf
include path).
- Catches 82: spec field-name/shift/repaint/order/word-bits drifts, the
  generator EXPECTED/render template drifts caught by `--check`
  staleness, generated-C packer/decoder/none-macro drifts caught at host
  compile/run, generated/hand Lean packer and decoder drifts caught by
  the lake chain (pack 1 2 3 4 falsification, num-lane repaints, the
  `indexNone = 0xfe` drift), the sim-header alias and static-assert
  repaints caught through both host paths, and the route quads-region
  repaint caught by route compile.
- Equivalences 8: two unreachable generator error-message repaints, the
  consumer-free hand renames (`x86_mem_aux_pack_refines`,
  `x86MemAuxSpec`) and the surviving informativeness renames
  (`hd_spec_rename`, `hd_pack_refines_rename`), the failures-counter
  drop (the 7904-case oracle still passes), the exhaustive-loop
  transpose (the loop still sweeps all lanes), the OK-banner repaint,
  the case-count print gate (-1 case still true), and the routed
  allocator comment repaint.
- Run: three consecutive byte-exact green shakes, `TOTAL 90 mutations,
  0 failures, 8 equivalences survived` / `ALL AS EXPECTED` rc 0
  (~18 s each), tree restored each time (no new `git status` entries
  beyond the pre-existing dirty set), census 131 -> 132 untracked
  harnesses, `make check` expected still 210 `: OK` (no new oracle
  hosts).

### Step 0257 — x86 stack trio mutation coverage

The three stack contracts the x86 simulator's frame helpers route through —
the frame-offset-to-arena-index map (step 0074), the b/q union storage model
with its word/byte ladder (step 0075), and the word-path/byte-ladder arm
selection (step 0120) — now share one merged mutation harness,
`build/mut_x86_stack_trio.py`: 86 single-anchor rows over the twenty-file
watchlist (per-family spec JSON + generator + generated header + generated
Lean + hand Lean + host driver for index/arena, the three-file arm set plus
the arm route host, and the routed `x86/x86_sim_local_bpf.h` write/read
regions shared by the arm family) snapshotted and restored byte-exact around
every row, with ten detectors (per-family gen `--check`, per-family
`lake build KProgFormal.GeneratedX86Stack{Index,Arena,Arm}` +
`lake env lean` hand module, per-family compiled host cross-check, and the
arm route cross-check requiring the vendor libbpf include path).
- Catches 79: spec-key repaints (operation/base/step/accumulate/mask bits
  for index; operation/word_shift/word_mask/capacity_round/arena_alias/
  assemble for arena; arm/body/define/name/w64/word/width64/selector for
  arm), generator render drifts caught by `--check` staleness or by
  regen-pairing the drift into all artifacts, generated-C macro drifts
  caught at host compile/run (index truncation, arena word-index/byte/
  assemble/words, arm word/byte codes and the inverted 1:0 ternary),
  generated/hand Lean drifts caught by the lake chain (wordIndex/wordAligned/
  words/byteAt, armCount/width64Code/names/codes/armOf/case codes/qword
  body, hand example value falsification `words 64 = 9`), the drop of the
  arm include from the sim header, the word-arena/word-index/byte-ladder
  repaints of the routed write/read bodies (route compile fails on the
  missing `.z` union member), and the hand-selection reintroduction
  (`X86_WIDTH_64 &&` back in the routed region) tripping the generator's
  region check.
- Equivalences 3: comment-only additions in the sim header include line and
  the hand index Lean module, the generator `ROOT` reshape
  (`resolve().parent` -> `parent.resolve()`), and the schema-version
  whitespace relaxations on both compact spec JSONs.
- Run: three consecutive byte-exact green shakes, `TOTAL 86 mutations,
  0 failures` / `ALL AS EXPECTED` rc 0 (~19 s each), tree restored each
  time (no new `git status` entries beyond the pre-existing dirty set),
  census 130 -> 131 untracked harnesses, `make check` expected still 210
  `: OK` (no new oracle hosts). The 0120-era per-family stack-arm harness
  `build/mut_x86_stack_arm.py` remains the detector-naming template the
  trio mirrors; the red ARM64 counterpart
  (`build/mut_arm64_stack_arm.py`, pre-existing anchor-count drift from
  commit a23a35a63) is unchanged and out of scope here.

### Step 0256 — x86 XMM0 route mutation coverage

The XMM0 route contract pins the routing layer the two pair-move bodies hang
from: the dispatcher crosses in `x86_sim_local_bpf.h`
(`KPROG_X86_DISP_LOAD_XMM0_HANDLED` ->
`X86_SIM_L_EXEC_LOAD_XMM0((SRC), (AUX), (IMM))`,
`KPROG_X86_DISP_STORE_XMM0_HANDLED` ->
`X86_SIM_L_EXEC_STORE_XMM0((DST), (AUX), (IMM))`) plus the shared selector
macros the bodies consume — the arm table `X86_SIM_L_MEM_XMM0_ARM` over
`KPROG_X86_XMM0_ARM` register identity (RSP to the stack helper through
`X86_SIM_L_STACK_READ/STACK_WRITE`, everything else into the ordinary arm),
the opcode-opposite base form `KPROG_X86_XMM0_BASE_FORM` (load 1U =
`absImmPtr`, store 0U = `nullBasePlusDisp`; a `X86_REG_NONE` load's address
is the raw artifact with the offset discarded, a `X86_REG_NONE` store's is
the offset on a null base), `KPROG_X86_XMM0_ADDS_DISP` adding the
displacement only on the `absImmPtr` form, and the
`KPROG_X86_XMM0_LANE_OFFSET(1)` lane geometry (the high lane exactly one
lane width past the address) — pinned byte-for-byte by the generated
`generated/x86_xmm0.h` over `x86_xmm0_spec.json` through
`generate_x86_xmm0_spec.py --check` and restated independently by the hand
Lean module `X86Xmm0Handler.lean` (`x86Xmm0ArmSpec` one-test nesting,
`x86Xmm0LaneOffsetSpec`, `x86Xmm0BaseFormSpec`). The dedicated route
cross-check `test_x86_xmm0_route_host.c` drives the real macro chain over 59
cases (the 15-case load scenario, the 14-case store scenario, the 16
arm/lane/base-form macro checks, and the 14 routing-macro pins) and prints
`x86 xmm0 route host cross-check: OK (59 cases)` while still exiting 0 with
a failures counter on stderr, so the route detector — like 0255's host
detector — treats any banner other than the exact clean-run string as a
catch; a stale generated header additionally busts the
`static assert x86 xmm0 lanes not consecutive` at compile time and a Lean
table repaint busts `lake build`, so all three detectors (route recompile +
banner grep, gen `--check` staleness, lean hand-module elaboration) trip on
distinct files.
- Shaken: `build/mut_x86_xmm0_route.py` (untracked) 58 single-anchor rows
  over the seven-file watchlist (route host + sim header + spec JSON +
  generator + generated header + generated Lean + hand Lean, all
  snapshotted and restored byte-exact around every row — the widening from
  0255's two-file WATCHED is the direct finding of this step, because the
  first shakes' interrupted runs left the five non-watched gen/lean files
  mutated, the leaks that produced the step's md5-restore re-shakes) split
  route 41 / gen 13 / lean 4.
- Reclassified: the pre-fix shakes' three sticky rows — the dispatcher
  cross (`hdr_dispatch_xmm0_cross`, the load/store body swap is preserved
  by the mirrored 59-case membership: the swapped store body writes exactly
  the pair the oracle planted and the swapped load body reads it fresh, so
  the comparator keys hold — a real invariant the route oracle documents,
  not a harness miss) and the two plant repaints (`route_plant_lo_repaint`,
  `route_plant_hi_repaint`, the plant seeds only feed both the simulator
  bodies and the oracle's `put_lane`/`get_lane` lanes
  through the same variable, so a repaint moves both sides together) — were
  probed against the live run (each rc 0 + `OK (59 cases)`) and pinned
  equivalent before the greens; the `spec_store_baseform_repaint` anchor
  widened to its three-line context after the load-side repaint made the
  one-line anchor ambiguous (two `nullBasePlusDisp` sites).
- Catches: 41 (24 route / 13 gen / 4 lean): the base-form shape swaps
  (`hdr_load_base_form_swap`, `hdr_store_base_form_swap`,
  `hdr_arm_bridge_invert`), the ADDS_DISP eliminations both directions, the
  lane-offset-on-address repaints, the stack-index repaints, and the
  message repaints the stderr counter never touches (route); all 13 spec
  repaints tripping `--check` staleness on the input side
  (`schema_version`, `operation`, `selector`, load
  op_code/direction/base_form, store base form; plus the generator's
  EXPECTED `OP_CODES`/`LANE_OFFSETS` rows and the C-header
  `LANE_HI`/`BASE_ABS_IMM` pin repaints the render diff re-delivers); all 4
  lean repaints (`lean_lane_spec_repaint`, `lean_arm_spec_repaint` on the
  hand module, `gen_lean_lane_hi_repaint`,
  `gen_lean_baseform_load_repaint` breaking the hand module's
  refine-by-rfl chain at `lake build`).
- Equivalences (17): the dispatcher cross, the two plant repaints, the two
  arena fill repaints, the absimm repaint the base-form-agnostic memory arm
  rides on, the banner blank-line repaint, the 4 mismatch-message repaints,
  and the 8 msg1/msg2 message repaints the failures counter never reaches.
- Run: byte-identical greens `rows: 58 as-expected: 58 unexpected: 0
  broken: 0` / `ALL AS EXPECTED` rc 0 (~11 s each) across three shakes,
  watched pins `9f2a0902ae72ee0dde00ee70b1631af8` (route host) +
  `7b7536548126903d61ac07ba24846800` (sim header) +
  `595867dfb5d09730da67b8f77a6acf29` (hand module) +
  `67a97459a96b3816c185c4512154425c` (generated header) verified after
  every batch, census 129 -> 130 untracked harnesses, `make check` stayed
  at 210 `: OK`.

### Step 0255 — x86 XMM0 pair-move mutation coverage

The XMM0 pair-move contract pins how the two `X86_OP_LOAD_XMM0` (0x30) /
`X86_OP_STORE_XMM0` (0x31) bodies move one two-lane scalar pair: the hand Lean
module `X86Xmm0Handler.lean` is the whole contract (no other module consumes
a single declaration of it); `x86Xmm0DispSpec` takes the displacement as the
whole immediate (`(s32)(IMM >> 32)` high-half is the contrasted near-miss,
pinned by `x86_xmm0_disp_forms_whole`), the arm is the one register-identity
test (`arm isRsp`: the stack arm reads/writes through the stack helper, the
memory arm through the process-memory byte functions, at the hardcoded width
64 for both lanes — the low at the address, the high one lane width past it,
no reversal or interleave, `x86_xmm0_load_store_round_trip`), and the
ordinary arm's base form is opcode-opposite: `absImmPtr` for the load means a
`X86_REG_NONE` operand IS the raw artifact with the addressing offset
discarded, while `nullBasePlusDisp` for the store means a `X86_REG_NONE`
destination contributes the null pointer and the offset added
(`x86_xmm0_ordinary_addr_load_ignores_offset` /
`x86_xmm0_ordinary_addr_store_uses_offset` pin the asymmetry, and the
`x86_xmm0_store_writes_pair` / `x86_xmm0_store_bytes_above_pair_unchanged`
theorems pin the pointwise two-lane write); the dedicated host
`test_x86_xmm0_host.c` drives the real `KPROG_X86_XMM0_*` macro chain and
`KPROG_X86_MEM_LOAD/STORE` against an independent restated oracle (byte-loop
`oracle_load`/`oracle_store`, modulo-64 stack helpers, `oracle_mem_offset`)
over 283 cases: tables (base form, arm, lane offsets, adds-disp), the 192-case
load composition grid (2 opcodes x 4 bases x 3 index registers x 2 scales x
4 immediates) and 72-case store grid against the hand restatements, and the
8 asymmetry pins (whole-vs-high-half slice, NONE-load-ignores-offset,
register-base agreement, both-lane layout, both-lane store, no-GPR-no-tag,
the probe-then-wipe pin, the stack/ordinary round trip);
`build/mut_x86_xmm0.py` (untracked) runs 50 single-anchor rows over the two
files with the two detectors (`lean` = `lake build KProgFormal.X86Xmm0Handler`
then `lake env lean`, `host` = direct `cc -Wall -Wextra -O1 -I.` recompile
then run). The host detector needed the sticky finding of this family: the
host binary prints `x86 xmm0 handler host cross-check: OK (N cases)` AND
still exits 0 when a part's comparator fires (the part returns 0, `main`
keeps counting), so rc alone cannot see a catch — the detector compares the
printed case count against the clean 283 and treats any other banner as rc 1.
Three byte-identical greens: `rows: 50 as-expected: 50 unexpected: 0 broken:
0` `ALL AS EXPECTED` rc 0 (~30 s each) after 27 anchor + classification
findings; 23 pinned equivalences (the four membership-invisible repaints —
slot modulus, synthetic, pointer stride, tag seed — the two stack-index sign
inversions and the retain-oracle-load swap the 283-case sweep preserves, the
two comparator-gate repaints the lifted `got.lo`/lo-lane check and the
duplicated `result_xmm0_hi` line the case count never changes, the
`return 1` pin repaint, the four stderr message repaints, the banner
blank-line repaint, and nine zero-external-consumer theorem renames — the
whole module is consumer-free); 27 catches: the oracle load/store byte-loop
shifts (the 64 increment the span itself proves), the offset-index
inversion, the arm/base/lane table repaints, the lane-geometry pin, the load
NONE-address and NONE-base-pointer repaints (the raw-artifact asymmetry),
the stack-hi-offset repaint, the store lo-to-hi lane repaints, the inverted
whole-vs-high-half pin, the probe-immediate repaint, and — the lean finding
— three renames `x86_xmm0_arm_refines`, `x86_xmm0_store_bytes_refines`,
`x86Xmm0DispSpec` that reach the file's own proof scripts (`lake build`
fails with unknown-identifier errors, the module is its own consumer) plus
the two example-output repaints `load_none_example_out` /
`base_form_example_out` `native_decide` refutes; pins
`e9591e72b71f45a091ae1a6f069ad724` (host) +
`595867dfb5d09730da67b8f77a6acf29` (hand module), census 128 -> 129
untracked harnesses, `make check` stayed at 210 `: OK`.

### Step 0254 — x86 SETCC register+memory mutation coverage

The two conditional-set handler-composition contracts pin the byte-lane
write and the memory-arm selection: the register-form hand module
`X86SetccHandler.lean` restates the generated `x86SetccStep` body
independently as `x86SetccStepSpec` (the AUX byte packs
`(dst_shift << 8) | payload`, the condition table resolves 14 accepted
codes, and the byte write goes through the scalarizing `KPROG_X86_WRITE_REG8`
kernel at lane `(dst_shift == 8)`, the truthiness trap — lane 9 selects the
low byte so the test must be an equality), the memory-form hand module
`X86SetccMemHandler.lean` restates `x86SetccMemStepSpec` (the address forms
through `GeneratedX86MemAccess.load byte memWidth` and
`GeneratedX86MemDispApply.apply`; the RSP arm dereferences the stack or
indexes `8 + 2*index`, the null-base arm reads the scratch memory, and the
otherwise arm always loads its own byte; every width arm resolves the same
`.w8`, the immutable-width invariant
`x86_setcc_mem_width_refines`/`x86_setcc_mem_width_constant` pair; the AUX
decodes bridge through `x86_setcc_mem_step_aux_refines` and
`x86_setcc_mem_step_fields_refines`); the dedicated host oracles
`test_x86_setcc_host.c` (590,726 cases: 256x256 cond/data sweep, 256-way
lane truthiness sweep, 16-reg x 256-payload x 8-shift x 16-flags
composition vs the hand model, a second 16x16x256 full-shift lane sweep, a
256-shift write8 sweep, and the asymmetric pins including the lane-9
writes-low pin) and `test_x86_setcc_mem_host.c` (1,053,191 cases: 256-arm x
16-cond decode sweep, the 256 base table, the 256 offset arm table, the
786,432-case composition grid over 64 stack dsts x 256 conds x 16 flags x 2
indexed x 2 widths x 4 immediates, and the asymmetric pins li the
null-base-scratch and stack-scaled-arm pins) drive the real
`KPROG_X86_SETCC_*` and `KPROG_X86_WRITE_REG8` macros against independent
restated models; `build/mut_x86_setcc.py` (untracked) runs 117 single-anchor
rows over the four files with the three detectors (`lean` = `lake build`
both hand modules then `lake env lean` each; `host`/`host_mem` = direct
`cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile binaries are
cache-mtime-stale). Three byte-identical greens:
`rows: 117 as-expected: 117 unexpected: 0 broken: 0` `ALL AS EXPECTED` rc 0
(~128 s each) after 23 anchor-fix and 21 classification iterations;
shake 1's findings: 21 rows the membership semantics classify as
equivalent (gate-vacuous comparator repaints and return-path repaints the
sweep membership preserves, e.g. the part-fail-msg repaint since both
greens, unchanged-decode and self-disabled gate spellings), four real
catches the harness reported correctly (`lean_mem_arm_refines` breaks
`X86CmovHandler.lean`'s consumption of `x86SetccMemDispSpec` through the
shared arm theorem, `lean_mem_width_refines` breaks the
`x86SetccMemWidthSpec` bridge the mem module itself consumes in
`x86_setcc_mem_step_refines`, `host_p6_probe_byte` and
`host_mem_p4_flags_probe` self-fail the clean binary's own probes), the
theorem-rename semantics: only `x86_setcc_eval_cond_sound` (register form,
consumed by `X86CmovHandler.lean` at two exact references) and
`x86SetccMemDispSpec` (memory form, ditto) have external consumers, all
other renames elaborate cleanly and survive; pins
`a5a6667e96a6216894d355d44b1d08a2` (register Lean) +
`3fa9f22adae924435df2bfffd02f4553` (memory Lean) +
`8bbda33a5a080075aa1fe6514b5c34f4` (register host) +
`b4c27120559104068775b5df5a7cc07a` (memory host), and `make check` stayed
at 210 `: OK`.

### Step 0253 — x86 effective-address LEA mutation coverage

The effective-address `LEA` step pins how the composed simulator body forms
an address and writes it back: `generatedX86LeaStep` takes the offset from the
shared dedicated contract (`GeneratedX86MemOffset.value`: displacement plus
index<<scale, both shifts reduced mod 64), then splits the three 64-bit exits
through `generatedX86LeaPointerWrite`, the writeback the real
`KPROG_PTR_ADD64_BITS`/`KPROG_PTR_ADD64_TAG` macros mirror — the RODATA fast
path (`src.isNone && isRodata`) writes the raw immediate and scalarizes
provenance, the RSP exit resolves `stackBase + src.bits + off` into `.stack`
provenance, the plain 64-bit exit keeps the source tag, and every narrower
width writes the partial-register pointer sum through the scalarizing
writeback; the hand module restates all three exits independently
(`x86LeaStepSpec` over `GeneratedX86MemOffset.valueSpec` and the pointer-write
twin) and proves
`x86_lea_step_refines` (`cases width <;> cases src.isNone <;> cases isRodata
<;> cases src.isRsp <;> simp only [...]`), the rodata fast-path and
needs-no-source theorems, the RSP-uses-stack_base and narrow-ignores-RSP
theorems, and four `native_decide` examples (rodata, indexed, stack pointer,
w32); the dedicated host `test_x86_lea_handler_host.c` drives `generated_lea`
— the real `KPROG_X86_MEM_OFFSET` macro and `KPROG_PTR_ADD64_*` under the
tagged `union reg_storage` — against an independent oracle
(`offset_oracle` signed-accumulate truncated on return, `oracle_lea`
re-deriving all three exits, `oracle_write` the partial-register write) over
61,440 cases (the encoded offset boundary loop at both index arms plus a
20,000-iterate LCG offset sweep, the LEA boundary grid over 3 source
registers x 4 widths x 8 displacements x 6 scales x 2 index arms with the
rodata arm, plus a 40,000-iterate LCG LEA sweep);
`build/mut_x86_lea.py` (untracked) runs 45 single-anchor rows over the two
files with the two detectors (`lean` = `lake build
KProgFormal.X86LeaHandler` then `lake env lean`; `host` = direct
`cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile binary is
cache-mtime-stale). Three byte-identical greens: 29 caught (26 host /
3 lean) — the oracle write masks/sums/tags and rodata fast-path arms, the
offset accumulate and write-truncation prongs, the generated
narrow/RSP/generic exit arms and tag/bit writes, the `same_lea` comparator
gate and rc check, the offset monitor return, the sweep-swap arms, and the
three exact-bits example repaints — and 16 pinned equivalents (the w64
keepold oracle arm and w32 writeback repaints the 61,440-case membership
preserves because no case reaches them; the rodata src/aux repaints the
gated fast path ignores; the offset index-arm mask drop; the has_rodata
prong inversion; the `same_lea` label and `check_offset` want repaints the
rc-0 detector never sees; two LCG sweep-seed repaints the membership
preserves; and five zero-external-consumer theorem renames/repaints — no
module imports `X86LeaHandler`); the 0252 `end KProgFormal` namespace
repaint pattern cannot be an equivalence here because Lean exports the
declared namespace (the rename fails `lake build` rc 200) and was
reimplemented as an example-tactic repaint (`:= by` -> `:= b y`). Pins:
`20c5881d5d498a9a54d7855fc24f282c` (host) + `e6fd2c681a9c05bae66e278d8686c64a`
(hand module).

### Step 0252 — x86 two-destination MULX mutation coverage

The two-destination `MULX` handler-composition contract pins the product's
two-register writeback (the hand Lean module `X86MulxHandler.lean` is the whole
contract — no dedicated spec/generator exists for this family): unlike the
single-destination arithmetic handlers it writes two registers — the low half
of the product into the destination and the high half into the auxiliary
operand — and produces no flags at all; `generatedX86MulxStep` splits on the
width: the 32-bit form multiplies the zero-extended low words and splits that
single 64-bit product (`(lhs &&& 0xffffffff) * (rhs &&& 0xffffffff)`,
`product >>> 32` into aux), while every other width computes the plain 64-bit
product for dst and the `x86MulxHighLadder` four-limb radix-`2^32` ladder for
aux; the ladder is proved equal to the 128-bit high word by *reuse*, not
re-derivation: `x86MulxHighLadderEqUmulhAlg` (`simp only [...]` + `ac_rfl`)
shows the ladder equals the AArch64 `UMULH` ladder up to cross-term order, and
`arm64MulUmulhLadderEqHighWord` from `Arm64Mul.lean` closes the high-word
equality; `x86_mulx_step_refines` (`cases width <;> simp only [...],
rw [x86_reg_write_refines], by_cases auxPresent <;> simp only [...,
x86MulxHighLadderEqHighWord]`), `x86_mulx_preserves_flags` (no flag written),
`x86_mulx_aux_absent_preserves_aux` (the `if ((AUX) != X86_REG_NONE)` guard),
`x86_mulx_dst_tag_scalar`/`x86_mulx_aux_tag_scalar` (both writebacks
scalarize), and `x86MulxMask32EqSetWidth` (`bv_decide` on the small
mask-vs-`setWidth` bridge) close the module, four `native_decide` examples pin
the w64 max*max (`2^128 - 2^65 + 1`: low word 1, high `0xfffffffffffffffe`),
the w32 max*max split, the aux-absent tag-preservation case, and the w16
limb-branch case, and the dedicated host `test_x86_mulx_handler_host.c` drives
`generated_mulx` — the real macro chain `KPROG_X86_WRITE_REG8/16/32/64` under
the tagged `union reg_storage` — against an independent
exact-`__int128`-product oracle (`oracle_mulx`/`oracle_write` share no
arithmetic with the limb ladder) over the 18x18 limb-boundary sweep at all
four widths plus a 40,000-iterate three-advance LCG sweep, each with and
without the auxiliary destination = 41,296 cases comparing dst/aux values and
all four flags; `build/mut_x86_mulx.py` (untracked) runs 71 single-anchor rows
over the two files with the two detectors (`lean_chain` = `lake build
KProgFormal.X86MulxHandler` olean refresh then `lake env lean`; `host` =
direct `cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile binary is
cache-mtime-stale). Three byte-identical greens: 45 caught (19 host / 26 lean)
and 26 pinned equivalents (the `low = lhs * rhs` -> `rhs * lhs` operand
commutation and the flag-seed decode, aux-boundary-loop bound, LCG width
position, `w`/`v` table repaints, dst/aux derived-seed repaints, LCG
seed/constant repaints the 41,296-case membership preserves; the `same_mulx`
dst-arm drop and dst_tag re-arm the four-arm aux+flags comparison keeps after
live probing (the differential pair always agrees on the aux and flag arms so
dropping dst never fires, and dst_tag survives the writeback chain identically
on both sides); five banner/mismatch repaints no oracle validates; and six
zero-external-consumer theorem/example renames — the step-refine theorem's
rename survives because the file re-elaborates its own self-contained proof
chain and no later module consumes this family). Pins:
`fe4f1e7bdebe2d4d43ca49e3d7b6fa8a` (host) + `f140fb1ddbab840bcc0caab46ed5c484`
(hand module).

### Step 0251 — x86 memory-source imul + compare mutation coverage

The memory-source imul contract pins the `IMUL reg, [mem], imm` composition (the hand Lean module `X86MemImulHandler.lean` is the whole contract — no dedicated spec/generator exists for this family): `generatedX86MemImulStep` loads via `GeneratedX86MemAccess.load byte memWidth` at the memory operand's own width, signs up the decoded immediate via `GeneratedX86Signed.signExtend (GeneratedX86Immediate.value rawImm width) width`, multiplies the mem-width sign-extended loaded value by it, and writes back through `generatedX86RegWrite state.dst result width` with `generatedX86ImulFlags lhs rhs width state.flags` seeing the *raw* loaded lhs and the senior-extended immediate; `x86_mem_imul_step_refines` (`simp only [generatedX86MemImulStep, x86MemImulStepSpec, x86_mem_load_refines, x86_immediate_value_refines, x86_sign_extend_refines, x86_reg_write_refines, x86_imul_flags_apply_refines]`), `x86_mem_imul_preserves_zf_sf`/`x86_mem_imul_cf_eq_of`/`x86_mem_imul_tag_scalar` (`rfl`-family), `x86_mem_imul_bytes_congruent` (per-width `simp only [...]` + `h i (by decide)` chains), and `x86_mem_imul_rhs_narrow_reads_low_bits` (`refine ⟨?_, ?_, ?_⟩ <;> simp only [...] <;> bv_decide`) close the contract, four `native_decide` examples pin the w16 `0x7fff x 2` overflow (`0xfffe` + CF/OF together), the w64/w8 narrow-mem sign-extend (`0xff` -> `-3`, flags off), the w8 mixed-sign `-128 x 2` overflow, and the w8 in-range merge, and the dedicated host `test_x86_mem_imul_handler_host.c` drives `generated_imul` — the real macro chain `KPROG_X86_MEM_LOAD` at `mem_width`, `KPROG_X86_IMMEDIATE_VALUE` + `kprog_x86_sign_extend_value`, `kprog_x86_abs_width_value` + `KPROG_X86_SET_IMUL_FLAGS(self-computed limit)`, `KPROG_X86_WRITE_REG{8,16,32,64}` under the tagged `union reg_storage` — against an independent `oracle_imul` (own byte-loop load, explicit sign-bit `oracle_sign_extend`, 128-bit signed product, `overflow = product outside [-2^(bits-1), 2^(bits-1)-1]`, `oracle_write` w8/w16 byte-merge vs w32 zero-extend) over 4 dst widths x 4 mem widths x 14 mem seeds x 14 immediates = 3,136 boundary cases plus a 40,000-iterate three-advance LCG sweep = 43,136 cases comparing destination value + tag + four flags; `build/mut_x86_mem_imul.py` (untracked) runs 67 single-anchor rows over the two files with the two detectors (`lean_chain` = `lake build KProgFormal.X86MemImulHandler` olean refresh then `lake env lean`; `host` = direct `cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile-wired binary is cache-mtime-stale). Three byte-identical greens: 40 caught (21 host / 19 lean) and 27 pinned equivalents (the `KPROG_X86_SET_IMUL_FLAGS(cf, of, ...)` -> `(of, cf, ...)` argument swap the both-zero-or-both-set convention absorbs — live-probed rc 0, OK 43136; the `got_mem`/`want_mem` call-site buffer swap and the equal-fill mem repaint the 43,136-case membership preserves; the flag-seed decode repaint, inner-boundary-loop-bound (`c < 14` -> `c < 13`), width-key `(i>>1)`/`(i>>3)` swap, vector/width-table repaint, LCG seed/constant repaints, and six banner/mismatch/sweep-bound repaints no oracle validates; and ten zero-external-consumer theorem renames — the hand module's own proof chain closes over its own defs; the step refine-theorem rename survives because no other module imports the family). Pins: `c3e00bfd63db0ff2f313511e6f16065b` (host) + `7ab398afbaef1ea4126c471368b2e6fe` (hand module), re-verified after every probe batch.

The memory-source compare contract pins the `CMP/TEST [mem], rhs` + `CMP reg, [mem]` composition (the hand Lean module `X86MemCompareHandler.lean` is the whole contract — no dedicated spec/generator exists for this family): it carries its own `X86MemCompareOp` bridge over the shared `GeneratedX86CmpOp` tables (`x86MemCompareOpToCmpOp` + per-table `*Spec` restatements with three `cases op <;> rfl` refines and the `disp_kind` dependency-break conjunction), `generatedX86MemCompareStep` loads via `GeneratedX86MemAccess.load byte width`, routes the right-hand side through the shared `rhsSource` table to `GeneratedX86Immediate.value` or the register bits, and dispatches `flagKind` to `generatedX86SubFlags` over narrowed `GeneratedX86SbbResult.result lhs rhs false` or `generatedX86LogicFlags` over the narrowed conjunction; `x86_mem_compare_step_refines` (`cases op <;> simp only [...18 names...] <;> first | rw [x86_sub_step_refines] | rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]`), the cmp/test flag-kind theorems (`refine ⟨rfl, rfl, ?_, ?_⟩ <;> simp only [...] <;> rw [...]`), `x86_mem_compare_contract_refines` (four `exact` bullets), `generatedX86CmpRegMemStep`/`x86CmpRegMemStepSpec` with `x86_cmp_reg_mem_step_refines`, and `x86_mem_compare_handler_refines` close both compositions, four `native_decide` examples pin the w32 equal compare, the w8 borrow, the w16 test-zero, and the w64 reg-mem borrow, and the dedicated host `test_x86_mem_compare_handler_host.c` drives `generated_cmp_mem` + `generated_cmp_reg_mem` — the real macro chain `KPROG_X86_MEM_LOAD`, `KPROG_X86_IMMEDIATE_VALUE`, `KPROG_X86_SET_SUB_FLAGS` via `generated_sub_flags` handing the sign *mask*, `KPROG_X86_SET_LOGIC_FLAGS` — against an independent oracle (own byte-loop load, explicit immediate rule, `oracle_sub_flags` cf/zf/sf/of and `oracle_logic_flags` from width-masked operands) over 4 ops in the mem sweep + cmp-reg-mem at every width: 4 widths x 14 x 14 = 784 boundary cases plus a 40,000-iterate three-advance LCG sweep = 40,384 cases comparing all four flags; `build/mut_x86_mem_compare.py` (untracked) runs 99 single-anchor rows over the two files with the two detectors (same `lean_chain`/`host` split). Three byte-identical greens: 69 caught (26 host / 43 lean) and 30 pinned equivalents (the generated-side `KPROG_X86_WIDTH_SIGN_MASK` drop and `KPROG_X86_MEM_LOAD(mem, 0)` width repaint the read macro's internal masking absorbs — both live-probed rc 0, OK 40784; the `is_reg`/`is_test` predicate swaps the four-op boundary sweep covers through the other op's arm; the `v[13-a]` reg-index repaint and `w[0] 1->8` width repaint the 40,384-case membership preserves; the equal-fill mem repaint; five banner/mismatch/sweep-bound/LCG repaints; and 13 zero-external-consumer theorem renames plus the `rhs_source_refines` proof-line reorder and the four example theorem renames — the contract-level refine theorem names ARE caught at `lake build` when a later theorem consumes them). Pins: `8c98667923a8f28687fb01bc6b1b88ae` (host) + `9ee027c3bd0b92d7e023964e94a91560` (hand module).

### Step 0250 — x86 memory-unary handler-composition mutation coverage

The memory-unary contract pins the `INC/DEC/NEG/NOT [mem]` composition (the hand Lean module `X86MemUnaryHandler.lean` is the whole contract — no dedicated spec/generator exists for this family; it composes the load, the proved unary lane handlers from `X86UnaryWriteback.lean`, and the width-confined store): `generatedX86MemUnaryStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{Inc,Dec,Neg,Not}LaneHandler` at the `.low` lane; `generatedX86MemUnaryByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; `x86_mem_unary_step_refines` (`cases op <;> simp only […] <;> rw [x86_mem_load_refines]` then one `exact x86_{inc,dec,neg,not}_lane_handler_refines` per op), `x86_mem_unary_byte_refines` (`rw [x86_mem_unary_step_refines, x86_mem_byte_count]` + `by_cases` + `rw [x86_mem_store_byte_refines]` in the in-bound arm), and `x86_mem_unary_handler_refines` (flags ∧ per-byte conjunction) close the composition, and a `native_decide` example pins the w8 `NEG 0x80` minimum (byte 0 stays `0x80` after negation, byte 1 unchanged at `0xa5`, flags out `{ cf, !zf, sf, of }`). The dedicated host `test_x86_mem_unary_handler_host.c` drives `generated_run` — the real macro chain `KPROG_X86_MEM_LOAD` & width mask, per-op `KPROG_X86_ADC_RESULT`/`KPROG_X86_SBB_RESULT`/`KPROG_X86_NOT_RESULT` + `KPROG_X86_SET_{ADD,SUB}_FLAGS`/`KPROG_X86_PRESERVE_FLAGS`, `KPROG_X86_MEM_STORE` — against an independent modular-`__int128`/`signed_value` oracle (2^width wrapping +1/−1/0−a/~a, `out.of = sr < lo || sr > hi` signed-overflow bounds, per-byte store-back) over 4 ops × 4 widths × 8 lhs vectors × 16 flag tuples = 2,048 boundary cases plus a 20,000-iterate LCG sweep = **22,048** cases, comparing `memcmp(got_mem, want_mem, 16)` + four flag fields. `build/mut_x86_mem_unary.py` (untracked): 83 single-anchor rows over the two files with two detectors (`lean_chain` = `lake build KProgFormal.X86MemUnaryHandler` olean refresh then `lake env lean`; `host` = direct `cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile-wired binary is cache-mtime-stale). Three byte-identical greens: 63 caught (26 host / 37 lean) and 20 pinned equivalents (the MEM_LOAD `& m` drop the read macro's internal width masking absorbs — live-probed rc 0, OK 22048; the uniform mem-fill/seed repaint and the f-bit decode repaint the 22,048-case membership preserves; the `- 1` memcmp-length repaint the byte-exact 16-byte image not-absorbs because lane bytes beyond the width coincide; six banner/mismatch string repaints no oracle validates; the vector/width-table/loop-bound/LCG keep-alives (constant +1, LCG bound −1, `v[1] 1→3`, `w[2] 4→8`, `a<7` and `f<15` loops, `i&3`→`i&2` op spread, `(i>>2)`→`(i>>1)` width spread); the `rw`-lemma reorder proving the same goal; and the two zero-external-consumer theorem renames (`x86_mem_unary_handler_refines`, `x86_mem_unary_neg_w8_min_example` — the hand module's own proof chain closes over its own defs, while byte/step refine-theorem renames ARE caught at `lake build` because the handler conjunction consumes the byte lemma and the example consumes the step theorem). Pins: `ef930c35189855f121015b5c4be1cc1b` (host) + `fbf485f0c3106b91da3d975d4d49c0d1` (hand module), re-verified after every probe batch; `make check` stayed at 210 `: OK`.

### Step 0249 — x86 memory-store ALU handler-composition mutation coverage

The memory-store ALU contract pins the `ADD/ADC/SUB/SBB [mem], rhs` composition every register-destination-memory arithmetic handler shares (the hand Lean module `X86MemStoreAluHandler.lean` is the whole contract — no dedicated spec/generator exists for this family; it composes the load, the proved four-op arithmetic/register-ALU step, and the width-confined store): `generatedX86MemDestArithStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{Add,Adc,Sub,Sbb}Handler` from `X86MemAluHandler.lean`; `generatedX86MemDestArithByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; `x86_mem_dest_arith_step_refines` (`cases op <;> simp only […] <;> rw [x86_mem_load_refines]` then one `exact x86_{add,adc,sub,sbb}_handler_refines` per op), `x86_mem_dest_arith_byte_refines` (`rw [x86_mem_dest_arith_step_refines, x86_mem_byte_count]`, `by_cases`, `rw [x86_mem_store_byte_refines]` in the in-bound arm), and `x86_mem_dest_arith_handler_refines` (flags ∧ per-byte conjunction) close the composition, and a `native_decide` example pins the w16 `ADC 0xffff` with `cf := true, sf := true, of := true` (zero result with carry propagated, byte 2 unchanged at `0xa5`, flags out `{ cf, zf, !sf, !of }`). The dedicated host `test_x86_mem_store_alu_handler_host.c` drives `generated_run` — the real macro chain `KPROG_X86_MEM_LOAD` & width mask, `KPROG_X86_ADC_RESULT` + `KPROG_X86_SET_{ADD,ADC,SUB,SBB}_FLAGS` per op, `KPROG_X86_MEM_STORE` — against an independent modular-`__int128`/`signed_value` oracle (`oracle_run`: 2^width wrapping add-with-carry/sub-with-borrow, `out.cf = wide >= mod` vs `a < b+carry`, `out.of = sr < lo || sr > hi`, per-byte store-back) over 4 ops × 4 widths × 8 lhs vectors × 8 rhs vectors × 2 carry tuples = 2,048 boundary cases plus a 20,000-iterate LCG sweep = **22,048** cases, comparing `memcmp(got_mem, want_mem, 16)` + four flag fields. `build/mut_x86_store_alu.py` (untracked): 65 single-anchor rows over the two files with two detectors (`lean_chain` = `lake build KProgFormal.X86MemStoreAluHandler` olean refresh then `lake env lean`; `host` = direct `cc -Wall -Wextra -O1 -I.` recompile then run — the Makefile-wired binary is cache-mtime-stale). Three byte-identical greens: 48 caught (34 host / 14 lean — the narrow `typedef` break of the `MEM_LOAD` shift widths, oracle load/sign/store repaints that break the 22,048-comparison, the four register-ALU arm repaints that the byte-exact memory cross-check validates, plus the `theorem`-statement deterministic-equality theorems (2 examples; example value/byte/flag repaints caught in the lean-detector-equivalent generated-arm direction), and 17 pinned equivalents (MEM_LOAD `& m` drop-over-absorb — the read macro's internal width masking absorbs the narrowing (live-probed rc 0, OK 22048); uniform-alias `got_mem`/`want_mem` swap the equal-fill equalizes; the six banner/mismatch string repaints no oracle validates; the vector/width-table/loop-bound/LCG keep-alives the 22,048-case membership preserves (constant +1, LCG bound −1, `i&2`/`(i>>2)&2` op/width spreads, `v[1] 1→3`, `w[2] 4→8`, `a<7` and `c<1` loops); `rw`-lemma reorder; four zero-external-consumer theorem renames — the hand module's own proof chain closes over its own defs and lake build catches the mutation everywhere the rename is load-bearing). Pins: `e830477045b30bb73282c6c8bb1d252e` (host) + `b0c6d5d4449d89bb3a49e0f76839f52d` (hand module), re-verified after every probe batch; `make check` stayed at 210 `: OK`.
### Step 0248 — x86 BMI2 memory-source shift mutation coverage

The BMI2 memory-source shift/rotate contract pins the four-opcode composition the `SHLX/SHRX/SARX dst, [mem], count` and `RORX dst, [mem], imm8` handlers share (the hand Lean module `X86MemShiftHandler.lean` is the whole contract — no dedicated spec/generator exists for this family; it composes the load, the flagless shift kernels, and the width-confined writeback): `generatedX86MemShiftStep` loads via `GeneratedX86MemAccess.load byte width` and dispatches `op` to `GeneratedX86ShiftResult.{shl,shr,sar} lhs count width`, `generatedX86MemRorxStep` rotates via `GeneratedX86ShiftResult.ror`, both write back through `generatedX86RegWrite state.dst result width` and thread the incoming flags through unchanged (the architectural property separating the BMI2 forms from their flag-writing legacy counterparts — `x86_mem_shift_preserves_flags`, `x86_mem_rorx_preserves_flags`); `x86_mem_shift_step_refines` (`cases op <;> simp only […]` against `x86MemShiftStepSpec`'s independently stated `x86MemLoadSpec`/`x86{Shl,Shr,Sar}ResultSpec`/`x86RegWriteSpec` chain) and `x86_mem_rorx_step_refines` against the complementary-count `x86RorResultSpec` close the two compositions, and three `native_decide` examples pin the 32-bit `SHLX` sing-extension (`0xffffffffffffffff → 0x0000000000000002` with the scalar tag), the 8-bit `SARX` sign-fill (`0x80 → 0x…c0`, upper bytes preserved), and the 8-bit `RORX` low-bit-to-top (faith `0x81 → 0xc0`). The dedicated host `test_x86_mem_shift_handler_host.c` drives `generated_run` — the real macro chain `KPROG_X86_MEM_LOAD`/`kprog_x86_{shl,shr,sar,ror}_result`/`KPROG_X86_WRITE_REG{8,16,32,64}` — against an independent byte-loop oracle (per-byte little-endian `oracle_load`, width-masked shift/rotate with the 63/31 BMI2 `KPROG_X86_SHIFT_COUNT` mask, w8/w16 byte-merge vs w32 zero-extension `oracle_write`) over 4 ops × 4 widths × 8 mem vectors × 8 count vectors = 1,024 boundary cases plus a 20,000-iterate LCG sweep = **21,024** cases total. `build/mut_x86_mem_shift.py` (untracked): 70 single-anchor rows over the two files with two detectors (`lean_chain` = `lake build KProgFormal.X86MemShiftHandler` olean refresh then `lake env lean`; `host` = direct `cc -Wall -Wextra -O2 -I.` recompile then run — the Makefile-wired binary is cache-mtime-stale). Three consecutive byte-identical greens: 42 caught (18 host / 24 lean — op-arm and writeback repaints break the step/refines/docs theorems at both stages) and 28 pinned equivalents (scalar-tag `(void)`-no-op, tags the `(void)tag` absorbs; oracle `0xfffff`-bound/byte-shifted mem fill/buffer-alias repaints the uniform mem bytes equalize; the acceptance-preserving vector/width-table/loop-bound/LCG-member keep-alives; the six banner/mismatch string repaints no oracle validates; per-rename and `rw`-lemma-list reorder survivors; the `x86MemRorxStepSpec` flags-rewrite preserving the value-provable statement). Rows/classified-after-probes: `lean_step_rw_sar` (lemma-name repaint caught at the `lake build` stage), `host_gen_write_w8` scalar-tag repaint (direct live probe rc 0), `lean_rorx_flags_body` and `lean_ex_rorx_value` (direct live probes).

### Step 0247 — x86 AND/OR/XOR [mem] handler-composition mutation coverage

The memory-logic contract pins the composition every `AND/OR/XOR [mem], rhs` handler shares (the hand Lean module `X86MemLogicHandler.lean` is the whole contract — no dedicated spec/generator exists for this family; it composes the existing load/writeback/store pieces: `generatedX86MemLogicStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{And,Or,Xor}RegLaneHandler` from `X86AluWriteback.lean` at `.low .low` lanes; `generatedX86MemLogicByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; three refine theorems close: `x86_mem_logic_step_refines` (`cases op <;> simp only […] <;> rw [x86_mem_load_refines]` then one `exact x86_{and,or,xor}_reg_lane_handler_refines` per op), `x86_mem_logic_byte_refines` (`rw [x86_mem_logic_step_refines, x86_mem_byte_count]`, `by_cases h`, `rw [x86_mem_store_byte_refines]` in the in-bound arm), and `x86_mem_logic_handler_refines` (flags ∧ per-byte conjunction)); the host `test_x86_mem_logic_handler_host.c` (Makefile-wired two-detector check: `lake build KProgFormal.X86MemLogicHandler` olean refresh then `lake env lean KProgFormal/X86MemLogicHandler.lean`, then cc+run) drives the real macro set `KPROG_X86_MEM_LOAD … & KPROG_X86_WIDTH_MASK`, `KPROG_X86_SET_LOGIC_FLAGS(…, r == 0, !!(r & KPROG_X86_WIDTH_SIGN_MASK(w)))`, and `KPROG_X86_MEM_STORE` through `generated_run` against an independent 128-bit-mod `oracle_run` — over 3 ops × 4 widths × 8 vector pairs × 16 flag tuples = 1,536 boundary cases plus a 20,000-iteration fixed-seed LCG sweep = 21,536 cases, comparing `memcmp(got_mem, want_mem, 16)` + four flag fields. Shake `build/mut_x86_mem_logic.py`: 66 single-anchor rows over the two files with the two detectors (`lean_chain` olean-refresh + `lake env lean`; `host` direct `cc -Wall -Wextra -O2 -I.` compile of the host source into `build/` then execution — via `make` the binary is cached when only source mtimes change, so the direct compile is what the detector must probe), 44 caught (30 host — 12 against the generated arm: mem-load masking vs raw load rows the load macro absorbs, and/arm, or/arm, xor-arm rows, `KPROG_X86_SET_ADD_FLAGS` macro swap, ZF/SF argument repaint, result-vs-lhs store row, oracle row repaints — the byte-exact cross-check validates the oracle against the generated composition, so 17k+ rows catch any accept-side oracle repaint, memory-shift repaint —, 18 by oracle-side acceptance repaints, …) and 22 equivalences pinned (the seven `lake env lean` unable to catch a rename in the same file LCG72 reshape rows that keep `_lean` names, the four flag-lane bit-repack rows that still deliver the right flag lane, the six banner/mismatch-message repaints, the three mem-byte repaint the comparison never observes rows, and the vector-table `0→2` repaint whose class is preserved at `~0`/`0x7fffffff`/`0x80000000`). Green runs `TOTAL 66 mutations, 0 failures, 66 equivalences survived`, `ALL AS EXPECTED` rc 0; both watched files byte-identical after every run; untracked harness retained; `make check` stayed at 210 `: OK`.

### Step 0246 — x86 logical-result flag transition mutation coverage

The logic-flags contract pins the two-input logical-result flag transition every ALU results write through (`KPROG_X86_SET_LOGIC_FLAGS(C_CF, C_ZF, C_SF, C_OF, ZERO, SIGN)` — `CF = 0`, `ZF = ZERO`, `SF = SIGN`, `OF = 0` with the generated Lean `GeneratedX86LogicFlags.eval` restating the same four arms — the hand module (`X86LogicFlags.lean`) states the independent spec `x86LogicFlagsSpec`, proves `x86_logic_flags_refine` by `rfl`, and bridges the flags through the condition-to-next-PC decision with `x86_logic_branch_refines` (`rw [x86_logic_flags_refine, x86_condition_sound]`); `X86AluWriteback.lean` consumes both sides at sixteen sites, and the simulator's `X86_SIM_L_SET_LOGIC_FLAGS` wrapper (ALU-flag dispatch default arm, the ANDN body, and the CMP/TEST logic arm) is the macro's only C consumer. The single-line spec pins the schema/operation metadata and the four flag expressions (`cf`/`of` const-false, `zf` input `zero`, `sf` input `sign`); the generator re-checks the whole expected dictionary (the `{"schema_version","operation","flags"}` shape gate, the canonical `["cf","zf","sf","of"]` order, and the three-arm expression whitelist) exactly and re-renders the Lean module and the C header byte-for-byte. `build/mut_x86_logic_flags.py` (untracked): 82 rows over the five contract files with two detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86LogicFlags` olean refresh then `lake env lean` over the hand module; no dedicated host: the macro's only C consumer is exercised through the other families' hosts, so 0231's reg-read precedent applies). 71 rows catch (58 by the generator byte-exact check, 13 through the Lean chain, including `cond` binder renaming inside the branch statement and the swapped-spec-arm bridge repaints) and 11 survive as documented equivalents (the four failure-path-only generator message repaints, the two `expr()` literal-token repaints whose repaints stay value-identical for this spec's arms, the `is_file`-check elimination and newline-appending write repaints into the regenerate-only branch the check never executes, the `#endif` comment repaint, the zero-external-consumer `x86_logic_branch_refines` theorem rename, and the `rw` lemma-list reorder that proves the same goal). Shake reported `TOTAL 82 mutations, 0 failures, 82 equivalences survived` with 71 catches and 11 pinned equivalents; syscalls were confirmed clean via the byte-identical triple-green shakes.

### Step 0245 — x86 branch-emission shape mutation coverage

The branch-emit contract pins the emitted shape behind the simulator's `X86_SIM_X86_JCC` conditional-branch emission (the generated macro `KPROG_X86_BRANCH_BACKWARD(CURRENT, TARGET)` is the bare address-ordering test `TARGET <= CURRENT` — the equality boundary is the backward shape — plus the generated Lean defs `GeneratedX86BranchEmit.shape` and `GeneratedX86BranchEmit.nextPc`, two one-armed constructor shapes whose next PC is `target` exactly when the predicate holds and falls through otherwise). The hand module (`X86BranchEmit.lean`) states the independent spec `x86BranchEmitShapeSpec` as `decide (target ≤ current)`, proves `x86_branch_emit_shape_refines` against it, and proves the emission bridge `x86_branch_emit_refines` (`nextPc (shape current target) taken fallthrough target = branchPc taken fallthrough target`, both shapes, by `split <;> split <;> rfl` on `target ≤ current` and then `taken`), plus the shape-irrelevance pair `x86_branch_emit_shape_irrelevant` and the per-shape direction facts `x86_branch_emit_taken`/`x86_branch_emit_not_taken` — the direction decides only how the jump is written, never whether it is taken. `ControlFlowTrace` folds the generated `emittedStep` over whole traces, so the bridge feeds the trace-level refinement too. Got its own single-family harness (Step 0245; 110 rows over 7 files — `x86_branch_emit_spec.json`, `generate_x86_branch_emit_spec.py`, `generated/x86_branch_emit.h`, `KProgFormal/GeneratedX86BranchEmit.lean`, `KProgFormal/X86BranchEmit.lean`, `test_x86_branch_emit_host.c`, `test_x86_branch_emit_route_host.c`; detectors — split gen 53 (spec pins, EXPECTED mirror, render recipes, stale--check gate, and the generated-file repaints) / lean_chain 31 (hand-module def/goal/tactic drifts) / host 16 (oracle and emitted-arm repaints) / route 44 (real `X86_SIM_X86_JCC` model arms, direction-oracle polarity, store flips, and unsupported-code sweeps), 32 equivalences: the cc-code set and unsupported repaints are sweep-membership-preserving, the contract-host 9-entry address sample resample is boundary-preserving, and banner/fail-return repaints have no validating consumer). Note the route-host resamples keep the equal and strictly-greater boundary probes live (`addrs[i]`/`addrs[i] + 1`), so direction-boundary repaints stay caught while pure membership drifts equivocate.

### Step 0244 — x86 SHLD/SHRD doubleshift mutation coverage

The doubleshift contract pins the two simulator double-precision shift bodies behind the per-width count/value kernels `kprog_x86_shld_value`/`kprog_x86_shrd_value`/`GeneratedX86DoubleShift.shld`/`GeneratedX86DoubleShift.shrd` (the pair registers `pairDS` puts `(dst,src)` into one 128-bit doubled word and `pairSD` the reverse, SHLD shifts `dst` left filling from the top of `src`, SHRD shifts `dst` right filling from the bottom; the count is the simulator's `KPROG_X86_SHIFT_COUNT` — 63 for 64-bit, 31 otherwise — so at narrow widths the count exceeds the width and the `k >= bits` arm is live, taking the whole result from `src` shifted by the excess; both are total over the four `X86_WIDTH_*` codes and write no flags, the handlers setting them separately), the direct consumer of the `X86DoubleShiftArmHandler` count-zero gate and canonical-example theorems. Shake `build/mut_x86_doubleshift.py`: 112 rows over six files with three detectors (`gen` byte-exact via `python3 generate_x86_doubleshift_spec.py --check`; `lean_chain` = `lake build KProgFormal.X86DoubleShift` olean refresh then `lake env lean` over `KProgFormal/X86DoubleShift.lean`; `host` the 32544-case contract sweep at `test_x86_doubleshift_host.c`), 88 caught (55 gen — 5 spec + 26 generator + 12 stale-C + 12 stale-Lean —, 20 lean_chain, 13 host), 24 equivalences (the four failure-path generator message repaints, five measured survivors joining four renames predicted from the zero-consumer scan (`x86_shld_refines`, `x86_shrd_refines`, `x86_shld_w64_example`, `x86_shrd_w8_example`), the whitespace-collapsed spec repaint that still satisfies the parsed-dict `--check`, the `pairDS` bits guard the sweep never drives to the painted arm, banner/mismatch-format and sweep-bound repaints no consumer reads, and three host message/banner repaints no oracle output validates). Green runs `TOTAL 112 mutations, 0 failures, 112 equivalences survived`, `ALL AS EXPECTED` rc 0; all six watched files byte-identical after each run; untracked harness retained; `make check` stayed at 210 `: OK`.

### Step 0243 — x86 CALL_MEMCPY/CALL_MEMSET mutation coverage

The callmem handler-composition contract pins the four simulator bodies sharing one composed block-copy/block-fill step (the four `X86_OP_CALL_MEMCPY` 0x3f / `X86_OP_CALL_MEMCPY_REG` 0x46 / `X86_OP_CALL_MEMSET` 0x3c / `X86_OP_CALL_MEMSET_REG` 0x45 bodies behind the per-opcode kind/count-source/bound-form tables: the kind table `KPROG_X86_CALLMEM_KIND(OP_IS_COPY)` picks the byte-by-byte copy body for the two `MEMCPY` opcodes and the masked-byte fill body for the two `MEMSET` opcodes, the count source `KPROG_X86_CALLMEM_COUNT_SOURCE(OP_IS_REG)` reads the length from the instruction immediate for the plain opcodes and from `RDX` for the `_REG` opcodes, and the bound form `KPROG_X86_CALLMEM_BOUND_FORM(OP_IS_REG)` is the hardcoded literal `KPROG_X86_CALLMEM_FIXED_BOUND` = 1024 for the plain opcodes and the immediate for the `_REG` opcodes — the generator pins their independence (`bound_is_imm` iff `count_source_is_reg`, rejecting any collapse) — per byte `i < min(bound, count)` the copy transfers `dst[i] := src[i]` and the fill stores the value's low byte, and every byte at or past the count stays untouched), the direct consumer of the `GeneratedX86MemAccess.storeByte` masked-byte store. Shake `build/mut_x86_callmem.py`: 153 rows over seven files with four detectors (`gen` byte-exact via `python3 generate_x86_callmem_spec.py --check`; `lean_chain` = `lake build KProgFormal.X86CallMemHandler` olean refresh then `lake env lean` over `KProgFormal/X86CallMemHandler.lean`; `host` the 875-case contract sweep at `test_x86_callmem_host.c`; `route` the 52-case sweep over the real `X86_SIM_L_EXEC_CALL_MEM*` bodies at `test_x86_callmem_route_host.c`), 136 caught (80 gen — 13 spec + 47 generator + 12 stale-C + 8 stale-Lean —, 45 lean_chain, 0 host, 11 route), 17 equivalences (the four failure-path generator message repaints, ten consumer-free handler renames — the hand module restates every table independently and its proofs close over its own defs, and the six measured survivors join four matching renames predicted from the zero-consumer scan (`generated_x86_call_mem_bound_refines`, `x86_call_mem_fixed_bound_refines`, `x86_call_mem_step_refines`, `x86_call_mem_beyond_bound_unchanged`) —, the consistent `i ≤ count` boundary repaint through both statements of the byte function, and three banners no consumer validates). Green runs `TOTAL 153 mutations, 0 failures, 153 equivalences survived`, `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after each run; untracked harness retained; `make check` stayed at 210 `: OK`.

### Step 0242 — x86 CMOV/CMOV_MEM mutation coverage

The CMOV handler-composition contract pins the two simulator bodies sharing one composed conditional-move step (the two `X86_OP_CMOV` 0x15 / `X86_OP_CMOV_MEM` 0x40 bodies with condition sources `wholeWord` (the whole AUX word, `KPROG_X86_CMOV_CONDITION(AUX) (AUX)`, not the SETcc family's low byte) vs `sourceShift` (the AUX high half, `KPROG_X86_CMOV_MEM_CONDITION(AUX) ((__u8)(((AUX) >> 24) & 0xffU))`), the 14 accepted condition codes (o no b ae e ne be a s ns l ge le g at 0-9 then 12-15, rejecting the parity pair 10/11), the width chain `KPROG_X86_CMOV_WIDTH(FLAGS) ((FLAGS) ? (FLAGS) : X86_WIDTH_64)` with `X86_WIDTH_64 == 8U`, the memory form's two-level width fallback (`KPROG_X86_CMOV_MEM_WIDTH(AUX, FLAGS)`: the AUX `mem_width` byte when it names one, the resolved-FLAGS fallback when it does not — a second width independent of the write width), the sign-extended high-half displacement `KPROG_X86_CMOV_MEM_DISP(IMM) ((__s64)(__s32)((IMM) >> 32))`, and the writeback selection `IS_64 ? KPROG_X86_CMOV_WRITEBACK_POINTER_TAG (0U) : KPROG_X86_CMOV_WRITEBACK_SCALARIZE (1U)` so only the 64-bit width can preserve the source's provenance tag while every narrower resolution scalarizes), the direct consumer of the 0235 bswap pointer-write kernel and shared `GeneratedX86MemDispatch.valueSrc` selector. Shake `build/mut_x86_cmov.py`: 162 rows over seven files with four detectors (`gen` byte-exact via `python3 generate_x86_cmov_spec.py --check`; `lean_chain` = `lake build KProgFormal.X86CmovHandler` olean refresh then `lake env lean` over the hand module; `host` contract sweep at `test_x86_cmov_host.c`; `route` real `X86_SIM_L_EXEC_CMOV`/`X86_SIM_L_EXEC_CMOV_MEM` bodies at `test_x86_cmov_route_host.c`), 128 caught (88 gen, 40 lean_chain, 0 host, 0 route), 34 equivalences (5 failure-path generator repaints, 26 consumer-free hand-theorem renames, three banners across the contract and route hosts). Green runs `TOTAL 162 mutations, 0 failures, 162 equivalences survived`, `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after each run; `make check` stayed at 210 `: OK`.

### Step 0241 — x86 MOVBE_LOAD/MOVBE_STORE mutation coverage

The MOVBE handler-composition contract pins the two simulator bodies sharing one composed byte-reversal store/load pair (the two `X86_OP_MOVBE_LOAD` 0x28 / `X86_OP_MOVBE_STORE` 0x29 bodies behind the `opcode_operand_then_register_identity_arm` selector, movbeLoad's `memoryReadDispatch` arm family vs movbeStore's `registerStoreArm`, the five `KPROG_X86_MOVBE_WIDTH(FLAGS_WIDTH)` width rows with `FLAGS ? FLAGS : 64` resolution 0→8 absent then 1/1 2/2 4/4 8/8 driving the byte reversal, the memory access, and the written size for both forms, both disp rows `signedImm` taking the whole field sign-extended (`KPROG_X86_MOVBE_DISP`, never the immediate store's high-half slice), the `KPROG_X86_MOVBE_ARM(BASE_IS_RSP)` stack-vs-memory store arms with `is_rsp` → `stackWrite` (`KPROG_X86_MOVBE_ARM_STACK 0U`) and otherwise `memoryStore` (`KPROG_X86_MOVBE_ARM_MEMORY 1U`), the `KPROG_X86_MOVBE(FLAGS_WIDTH)`-family statement expressions shared with the 0235 bswap contract, and no flags written), the direct consumer of the 0235 byte-reversal kernel. Shake `build/mut_x86_movbe.py`: 114 rows over seven files with four detectors (`gen` byte-exact; `lean_chain` = `lake build KProgFormal.X86MovbeHandler` olean refresh then `lake env lean` over the hand module; `host` contract sweep; `route` real EXEC_MOVBE bodies), 84 caught (48 gen, 36 lean_chain, 0 host, 0 route), 30 equivalences (14 failure-path generator repaints, 13 consumer-free hand-theorem renames, three banners across the contract and route hosts). Green runs `TOTAL 114 mutations, 0 failures, 114 equivalences survived`, `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after each run; `make check` stayed at 210 `: OK`.

### Step 0240 — x86 BZHI/BZHI_MEM mutation coverage

The BZHI handler-composition contract pins the two simulator bodies sharing one composed bit-clear step (per-opcode value/count source tables, `FLAGS ? FLAGS : 64` width for both the value read and the destination write, byte-masked count, hand-defined flags `OF=SF=0`/real-`ZF`/`CF` count-versus-width, `GeneratedX86Bitops.bzhi` result), the 0236 bitops contract's per-width consumer. Shake `build/mut_x86_bzhi.py`: 90 rows over seven files with four detectors (`gen` byte-exact; `lean_chain` = `lake build KProgFormal.X86BzhiHandler` olean refresh then `lake env lean` over the hand module; `host` contract sweep; `route` real EXEC_BZHI bodies), 58 caught (37 gen, 21 lean_chain, 0 host, 0 route), 32 equivalences (ten failure-path generator repaints, 19 consumer-free hand-theorem renames, three banners across the contract and route hosts). Green runs `TOTAL 90 mutations, 0 failures, 90 equivalences survived`, `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after each run; `make check` stayed at 210 `: OK`.

### Step 0239 — x86 BT/BT_IMM/BT_MEM_IMM mutation coverage

The BT handler-composition contract pins the three simulator bodies sharing one composed bit-test step (per-opcode base/index source tables, `FLAGS ? FLAGS : 64` width, `GeneratedX86Bitops.bt` carry, only-CF writes), the 0236 bitops contract's per-width consumer. Shake `build/mut_x86_bt.py`: 75 rows over seven files with four detectors (`gen` byte-exact; `lean_chain` = `lake build KProgFormal.X86BtHandler` olean refresh then `lake env lean` over the hand module; `host` contract sweep; `route` real EXEC_BT bodies), 46 caught (35 gen, 11 lean_chain, 0 host, 0 route), 29 equivalences (nine failure-path generator repaints + the `INDEX_ORDER` permutation, 16 consumer-free hand-theorem renames, three banners across the contract and route hosts). Green runs `TOTAL 75 mutations, 0 failures, 75 equivalences survived`, `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after each run; `make check` stayed at 210 `: OK`.

### Step 0238 — x86 signed-value mutation coverage

The signed-value contract pins the two width-parameterised signed operations the IMUL handlers rely on: `kprog_x86_sign_extend_value`/`GeneratedX86Signed.signExtend` widen the narrowed operand from the access width's sign bit (the generated complement-and-subtract form `((v & mask) ^ sign) - sign`, with the 64-bit width the identity; the hand module restates it independently via `BitVec.signExtend` over `setWidth` — `x86SignExtendSpec` — and proves `x86_sign_extend_refines` by case-bash `bv_decide`), and `kprog_x86_abs_width_value`/`GeneratedX86Signed.absWidth` compute the width-domain magnitude (narrow, negate when the width's sign bit is set, re-narrow; the independent `x86AbsWidthSpec` mirrors the shape with `mask`/`signMask`; the module also proves the idempotent-magnitude, magnitude-bounded-by-the-sign-mask, the two canonical examples, and the cross-contract `x86_abs_width_agrees_imul` agreement with the independently generated `GeneratedX86ImulFlags.signedAbs`). The single-line spec pins the schema/operation metadata and the four width rows (mask/sign/bits); the generator re-checks the whole expected dictionary exact plus the per-row bit-count check and renders the Lean module and C header byte-for-byte. Consumers: `x86_sim.h`'s `x86_sign_extend64`/`x86_abs_width64` wrappers, the IMUL-reg-imm/mem-imul/mov-load/movx Lean handlers rewriting with `x86_sign_extend_refines` (and the route dispatch host using `kprog_x86_sign_extend_value`), and a dedicated contract host sweeping both helpers over a boundary vector set plus a 20000-iteration LCG sweep against oracle re-implementations. `build/mut_x86_signed.py` (untracked) runs 48 rows over the six files with three detectors (`gen` byte-exact check; `lean_chain` = `lake build KProgFormal.X86Signed` olean refresh then `lake env lean` over the downstream `X86MovLoadHandler` consumer; `host`). 37 rows catch (29 at the generator stage covering the spec fields, per-row checks, byte-exact renders, header bytes, and the sign-extension/abs arms; 6 through the Lean chain — both independent spec defs, the w8 sign-extension arm, the w8 abs condition flip, and the `x86_sign_extend_refines` rename the IMUL/mov handlers consume; 2 in the contract-host sweep — the oracle w8 mask and the abs negation test) and 11 survive as documented equivalents: the three failure-path-only generator message repaints, seven consumer-free hand-theorem renames (`x86AbsWidthSpec`'s own def rename, `x86_abs_width_refines`, `idempotent`, `bounded`, the two canonical examples, and `x86_abs_width_agrees_imul`), and the two host OK/FAIL banner repaints no consumer validates. Two consecutive green shakes reported `ALL AS EXPECTED`; all six watched files byte-identical after each run (signed watchlist verified); `make check` stayed at 210 `: OK`.

### Step 0236 — x86 bitops BT/BZHI mutation coverage

The bitops contract pins the two bit-indexed kernels the BT and BZHI handler families apply through the generated-width path: `bt` reads the carry as the indexed bit of the narrowed base (`kprog_x86_bt_value`, `GeneratedX86Bitops.bt`) with the index hardware-masked to `width == 64-bit ? 63 : 31` — deliberately *not* the width's bit count for narrow widths — and `bzhi` clears every bit at or above the byte-masked index (`kprog_x86_bzhi_value`, `GeneratedX86Bitops.bzhi`) keeping the whole narrowed base when the index reaches the width. Spec pins the schema/operation metadata and the four width rows (code/bits/index_mask 1/8/31, 2/16/31, 4/32/31, 8/64/63); the generator re-checks the whole expected dictionary exact plus the per-row bit-count mask-list checks and renders `GeneratedX86Bitops.lean` and `generated/x86_bitops.h` byte-for-byte; the hand module (`X86Bitops.lean`) restates the independent width mask from `2^(8*code)` (`x86BitopsMaskCode`) and proves `x86_bt_refines`/`x86_bzhi_refines` per width code by `bv_decide`, the closed width-code case set, the width-indexed `x86_bt_refines_width`/`x86_bzhi_refines_width` bridges, the bzhi within-width and max-index-keeps bounds, and the four canonical examples. Consumers: the C macros are called inside `X86_SIM_L_EXEC_BZHI*` and `X86_SIM_L_EXEC_BT*` in `x86_sim_local_bpf.h`, the Lean side is consumed by `X86BtHandler`, `X86BzhiHandler` (`x86BitopsMaskCode` at the spec simp), and `X86MemBitHandler` (both width bridges), and a dedicated contract host sweeps both macros against independent bit-mask oracles. `build/mut_x86_bitops.py` (untracked) runs 59 rows over the six files with three detectors (`gen` byte-exact check; `lean_chain` = `lake build KProgFormal.X86Bitops` olean refresh then `lake env lean` over the downstream `X86BtHandler` consumer — the `x86_bzhi_refines_width` rename row runs a second downstream `X86MemBitHandler` compile because the BtHandler consumer never references that bridge; `host`). 47 rows catch (36 at the generator stage covering the spec fields, per-row checks, byte-exact renders, header bytes, and generated-Lean arms; 9 through the Lean chain — both independent spec defs, the `x86BitopsMaskCode` body, the two per-code refines renames, the closed-case rename, and both width-bridge renames; 2 in the contract-host sweep — the BT one-bit mask scale and the BZHI kept/or-kept-mask flip) and 12 survive as documented equivalents: the four failure-path-only generator message repaints, five consumer-free hand-theorem renames (`within_width`, `max_index_keeps`, and the three canonical examples), and the two host OK/FAIL banner repaints no consumer validates. Two consecutive green shakes reported `ALL AS EXPECTED`; all six watched files byte-identical after each run (bitops watchlist verified); `make check` stayed at 210 `: OK`.

### Step 0235 — x86 bswap/movbe byte-reversal mutation coverage

The bswap/movbe contract pins the shared byte-reversal kernel behind the `BSWAP`, `MOVBE_LOAD`, and `MOVBE_STORE` handlers: `kprog_x86_bswap_value(value, width)` and `GeneratedX86Bswap.value` reverse the access width's byte order and clear the bytes above it (w8 masked identity, w16 two-lane swap, w32 half-reversal of the swapped word (`swapped >> 32`), w64 eight-lane reversal) with a closed width set, so there is no unsupported arm. Spec pins the schema/operation metadata and the four width rows (name/bytes/code: 1/1, 2/2, 4/4, 8/8); the generator re-checks the whole expected dictionary exact plus the per-row byte-count and code-list checks and renders `GeneratedX86Bswap.lean` and `generated/x86_bswap.h` byte-for-byte; the hand module (`X86Bswap.lean`) restates the reversal independently as `x86BswapSpec` (per-byte `lane8` extractions re-assembled in reverse) and proves `x86_bswap_refines` by `bv_decide`, the involution `x86_bswap_involutive` (`value (value v width) width = v &&& mask width`), the w32 high-word clearing, and the three canonical byte-order examples. Consumers: `x86_sim.h` calls `kprog_x86_bswap_value` in the byte-reversal step (available to every width-aware handler), `X86MovbeHandler.lean` rewrites with `x86_bswap_refines` and closes its movbe-elimination proof with `exact x86_bswap_involutive value width`, and two dedicated hosts sweep the contract — the contract host drives the macro against a byte-array reversal oracle and the route host drives the real BSWAP/MOVBE simulator bodies. `build/mut_x86_bswap.py` (untracked) runs 54 rows over the seven files with four detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86Bswap` olean refresh then `lake env lean` over the downstream `X86MovbeHandler` consumer, `host`, `route_host`). 43 rows catch (37 at the generator stage covering the spec fields, per-row checks, byte-exact renders, header bytes, and generated-Lean arms, 5 through the Lean chain — the `lane8` helper, the `x86BswapSpec` w64 arm, and the `x86_bswap_refines`/`x86_bswap_involutive` renames the movbe handler consumes — 1 in the contract-host sweep (an oracle byte-assembly shift), 0 in the route-host sweep) and 11 survive as documented equivalents: the three failure-path-only generator message repaints, the four consumer-free hand-theorem renames (`w32_clears_high`, the three example theorems), and the four host banner/stderr repaints no consumer validates. Two consecutive green shakes reported `ALL AS EXPECTED`; all seven watched files byte-identical after each run (bswap watchlist verified); `make check` stayed at 210 `: OK`.

### Step 0234 — x86 not mutation coverage

The not contract pins the one-opcode unary complement kernel: the result arm is the bytewise `~VALUE` expression (`KPROG_X86_NOT_RESULT`) and the flag arm is the identity preservation of `CF`/`ZF`/`SF`/`OF` (`KPROG_X86_PRESERVE_FLAGS`, a `do{(void)0;}while(0)` no-op the ALU flag-dispatch step calls in the NOT arm). Spec pins the schema/operation metadata, the `bit_not`/`value` result row, and the `preserve` row listing the four flag inputs; generator re-checks the whole expected dictionary exactly and renders `GeneratedX86Not.lean` and `generated/x86_not.h` byte-for-byte; the generated Lean module carries the `Flags` structure, the `BitVec.not`-based result, and the pass-through `flags` builder; the hand module (`X86Not.lean`) adds the width-aware `x86NotWidthResultSpec` (narrow to the write width, then complement over the width mask) and proves the result refinement against `GeneratedX86Width.narrow (GeneratedX86Not.result ...)`, the flag-preservation refinement, and the branch refinement consumed further downstream. The C macros are consumed inside `X86_SIM_L_EXEC_ALU_FLAG_STEP` (arm NOT of the ALU flag dispatcher, via `KPROG_X86_PRESERVE_FLAGS`) and `test_x86_mem_unary_handler_host.c` (via `KPROG_X86_NOT_RESULT`) — no dedicated hosts; the Lean side feeds `GeneratedX86AluResult` (ALU op `.not`) and `X86UnaryWriteback` (the unary lane handler chain, whose `x86_not_lane_handler_refines` rewrites with `x86_not_flags_refine` and `x86_not_narrowed_result_refines`). `build/mut_x86_not.py` (untracked) runs 52 rows over the five contract files with two detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86Not` olean refresh then `lake env lean` over the downstream `X86UnaryWriteback` consumer). 49 rows catch (44 at the generator stage covering the spec fields, byte-exact renders, header bytes, and generated-Lean arms, 5 through the Lean chain) and 3 survive as documented equivalences: the two failure-path-only generator message repaints and the `x86_not_branch_refines` rename with no post-definition consumer (`x86_not_flags_refine` and `x86_not_narrowed_result_refines` renames, by contrast, are catches through the downstream rewrite). Two consecutive green shakes reported `ALL AS EXPECTED`; all five watched files byte-identical after each run (not watchlist verified); `make check` stayed at 210 `: OK`.



### Step 0233 — x86 register-write mutation coverage

The register-write contract pins the scalar-tagged partial-register writeback kernel every composed simulator body writes its destination register through (`KPROG_X86_WRITE_REG8/16/32/64`: the 8-bit form takes its byte lane from the selected shift (`BYTE_SHIFT == 8U` writes `b[1]`, otherwise `b[0]`), the 16-bit form stores `w`, and the 32/64-bit forms store the zero-extended/full value through a pointer-tagged union cell, with every form stamping the scalar tag). Spec pins the schema/operation/tag metadata, the two byte lanes with their shifts (low 0, high 8), and the four widths with their bits and `preserve_upper` flags; generator re-checks the whole expected dictionary exactly and renders `GeneratedX86RegWrite.lean` and `generated/x86_reg_write.h` byte-for-byte; the generated Lean module carries the `Result`/`ByteLane` types, `byteShift`, the `bits` width table, the lane-aware `bitsAt`/`writeAt` over it, and the tag-stamping `write`; the header emits the four writeback macros; the hand module (`X86RegWrite.lean`) restates the tables as `x86ByteShiftSpec`/`x86RegWriteBitsAtSpec`/`x86RegWriteBitsSpec` (written as XOR-masked updates rather than the generated or-masks) and proves fourteen refinements, from `x86_reg_write_at_refines` to the upper-preservation, high-lane, counterexample, zero-extension, replacement, and scalarization facts. No dedicated hosts: the writeback macros' C consumers are exercised through the other families' route hosts and the Lean primitives by every handler chain. `build/mut_x86_reg_write.py` (untracked) runs 78 rows over the five contract files with two detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86RegWrite` olean refresh then `lake env lean` over the downstream `X86RegLaneAux` consumer). 72 rows catch (66 at the generator stage covering the spec fields, byte-exact renders, header bytes, and generated-Lean arms, 6 through the Lean chain) and 6 survive as documented equivalences: the two failure-path-only generator message repaints and four refinement-theorem renames with no post-definition consumer. Two consecutive green shakes reported `ALL AS EXPECTED`; all five watched files byte-identical after each run (reg-write watchlist verified); `make check` stayed at 210 `: OK`.



### Step 0232 — x86 andn mutation coverage

The andn contract pins the two-opcode complement-and handler kernel the simulator consumes through `KPROG_X86_ANDN_WRITE_WIDTH` / `SOURCE` / `MEM_WIDTH_ARM` / `MEM_WIDTH` (`X86_OP_ANDN` 0x3d reads its second operand from a register, `X86_OP_ANDN_MEM` 0x44 from memory at an *independently selected* width: the `AUX` mem-width field when it names one, the `FLAGS`-resolved write width when the field is absent; both bodies compute `(~src1) & src2`, take CF=OF=0, derive `ZF`/`SF` from the result at the resolved write width, and write the destination through the partial-register primitive). Spec pins the schema/selector metadata, both opcode rows with their sources, both mem-width arms with their defines, and the 64-bit write-width default; generator re-checks the whole expected dict exactly and renders `GeneratedX86Andn.lean` and `generated/x86_andn.h` byte-for-byte; the header adds static-assert opcode pins plus the four selector macros; the hand module (`X86AndnHandler.lean`) restates each table and proves the twenty refinements including `x86_andn_step_refines`.

`build/mut_x86_andn.py` (untracked) runs 98 rows over the seven contract files with four detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86AndnHandler` olean refresh then `lake env lean` over the module itself, `host` 1849-case contract host, `route_host` 356404-case simulator route host). 79 rows catch (72 at the generator stage covering the spec fields, byte-exact renders, and host-compiled headers, 7 through the Lean chain) and 19 survive as documented equivalences: eleven failure-path-only generator message repaints, the four Lean theorem renames (no external module imports `X86AndnHandler`, so refinement names have zero consumers), the three contract-host and one route-host banner/stderr repaints no consumer validates. Two consecutive green shakes `TOTAL 98 mutations, 0 failures, 98 equivalences survived` / `ALL AS EXPECTED` rc 0; all seven watched files byte-identical after every row; `make check` stayed at 210 `: OK`.

### Step 0231 — x86 register-read mutation coverage

The register-read contract pins the byte-lane/width operand-observation kernel every composed simulator body reads its register operands through (`KPROG_X86_READ_REG_AT(VALUE, WIDTH, BYTE_SHIFT)`: byte-width reads take the lane byte at the selected shift, wider widths always observe the low lane — the generated `KProgFormal/GeneratedX86RegRead.readAt` table pins `w8`/`low` = `value & 0xff`, `w8`/`high` = `(value >>> 8) & 0xff`, `w16` = `value & 0xffff`, `w32` = `value & 0xffffffff`, and the `w64` identity, and the hand module `KProgFormal/X86RegRead.lean` restates the same table as `x86RegReadAtSpec` and proves `x86_reg_read_at_refines` plus the `low8`/`high8` underline lemmas and the high-byte counterexample; the single C consumer is `X86_SIM_L_READ_REG_WIDTH_SHIFT`, whose selector the spec pins end to end). The single-line spec (`x86_reg_read_spec.json`) pins the schema, the operation name, the two byte lanes with their shifts, and the four widths with their bits; the generator (`generate_x86_reg_read_spec.py`) re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte; the header emits the single selector macro with the `WIDTH == X86_WIDTH_8 ? BYTE_SHIFT : 0U` lane gate behind `KPROG_X86_APPLY_WIDTH`.

`build/mut_x86_reg_read.py` (untracked) runs 64 rows over the five contract files with two detectors (`gen` byte-exact check, `lean_chain` = `lake build KProgFormal.X86RegRead` olean refresh then `lake env lean` over the dependent `X86AluWriteback.lean` — no dedicated host: the selector's only consumer is exercised through the other families' hosts). 61 rows catch (17 at the spec file, 32 at the generator stage covering the header and generated-Lean pins, 8 through the Lean chain) and 3 survive as documented equivalences: the two failure-path-only generator message repaints and the `x86_reg_read_low8` theorem rename (no post-definition consumer in the dependent chain). The load-bearing detector fix this shake caught was the Lean side: without a `lake build` olean refresh in front of `lake env lean`, every hand-module mutation silently passed against a stale `X86RegRead.olean`.

### Step 0230 — x86 callmem mutation coverage

The callmem contract pins the four-opcode block-copy/block-fill handler-composition kernel the simulator consumes through `KPROG_X86_CALLMEM_KIND` / `COUNT_SOURCE` / `BOUND_FORM` / `FIXED_BOUND` (`X86_OP_CALL_MEMCPY` 0x3f, `X86_OP_CALL_MEMCPY_REG` 0x46, `X86_OP_CALL_MEMSET` 0x3c, `X86_OP_CALL_MEMSET_REG` 0x45; the kind table selects the byte-by-byte copy body for the two `MEMCPY` opcodes and the masked-byte fill body for the two `MEMSET` opcodes, the count-source table reads the length from the instruction-immediate artifact for the plain opcodes and the `RDX` register ABI for the `_REG` opcodes, and the bound-form table independently takes the hardcoded literal 1024 bound for every immediate-count opcode and the immediate bound for every register-count opcode). The single-line spec (`x86_callmem_spec.json`) pins the schema/selector metadata, the literal bound, all four opcode rows, the kind/count-source/bound-form rows with their defines, and the duplicate-opcode and bound/count-collapse predicates; the generator (`generate_x86_callmem_spec.py`) re-checks the whole expected dictionary exactly (schema, opcodes, kinds, count sources, bound forms, duplicate opcodes, and the bound/count independence oracle) and renders `KProgFormal/GeneratedX86CallMem.lean` and `generated/x86_callmem.h` byte-for-byte; the header pins all four opcodes with static asserts and emits the kind/count-source/bound-form selector macros; the hand module (`KProgFormal/X86CallMemHandler.lean`) restates each table independently and proves the fifteen refinements, including `x86_call_mem_bound_and_count_are_independent`. Two hosts sweep the contract: `test_x86_callmem_host.c` (875 cases) and `test_x86_callmem_route_host.c` (52 cases). The 154-row shake catches 104 mutations (22 at the spec file, 31 at the generator, 7 at the generated header, 10+24 through the Lean modules, 11 by the contract host, 9 by the route host) with 50 documented equivalents: failure-path-only generator message repaints and the check/is-file flags the byte-exact comparator ignores, spec spacing repaints the checker does not compare, the Lean doc-comment wipes the Lean chain does not read, in-module-unreferenced refinement-theorem renames, the fixed-bound alias substitution the two statements share, immediate `MEMCPY` count overshoots the macro body absorbs into the exp model, route banner/message repaints no consumer validates, and host banner/stderr repaints no consumer validates.


### Step 0229 — x86 cmov mutation coverage

The cmov contract pins the two-form conditional-move kernel the simulator consumes through `KPROG_X86_CMOV_WIDTH` / `CONDITION` / `CONDITION_BYTE` / `MEM_CONDITION` / `MEM_WIDTH` / `MEM_DISP` / `WRITEBACK` (`X86_OP_CMOV` 0x15, `X86_OP_CMOV_MEM` 0x40; register-source `wholeWord` for the register form and `sourceShiftByte` at bits 24–31 for the memory form; the write width is the `FLAGS` code with a 64-bit fallback, the memory access width a two-level fallback from the AUX memory-width byte through that write width, the memory displacement the sign-extended high half of the artifact, and the write-back table selects the tagged pointer write at 64-bit widths and the scalarizing partial-register write otherwise — the memory form writes through the partial-register path at every width). The single-line spec (`x86_cmov_spec.json`) pins the schema/operation metadata, both opcode rows, the two source-byte definitions, all fourteen condition-code rows, the width and memory-width rows, and the displacement and write-back definitions; the generator (`generate_x86_cmov_spec.py`) re-checks the whole expected dictionary exactly (schema, opcodes, sources, every row, duplicate condition codes) and renders `KProgFormal/GeneratedX86Cmov.lean` and `generated/x86_cmov.h` byte-for-byte; the header pins both opcodes and the 64-bit width with static asserts and emits the seven selectors (the `KPROG_X86_CMOV_WRITEBACK` macro's `if (IS_64)` arm split); the hand module (`KProgFormal/X86CmovHandler.lean`) restates each table independently and proves the refinements, with `x86CmovByteConditionTable` sharing the x86-setcc condition table. Two hosts sweep the contract: `test_x86_cmov_host.c` (484369 cases) and `test_x86_cmov_route_host.c` (26526735 cases). The 170-row shake catches 141 mutations (41 at the spec file, 48 at the generator, 14 at the generated header, 33 through the Lean modules, 5 by the two hosts) with 29 documented equivalents: failure-path-only generator message repaints and the source-check flip the byte-exact comparator ignores, spec spacing and padding repaints the checker does not compare, a generated-Lean word-table arm swap whose table is definitionally self-referential, in-module-unreferenced refinement-theorem renames, and host banner/stderr repaints no consumer validates.

### Step 0228 — x86 cond mutation coverage

The cond contract pins the sixteen-entry x86 condition-code table the simulator consumes through `KPROG_X86_EVAL_CC` (`X86_CC_O` 0 … `X86_CC_G` 15, each code a flag predicate over CF/ZF/SF/OF: of, !of, cf, !cf, zf, !zf, cf||zf, !cf&&!zf, sf, !sf, sf!=of, sf==of, zf||(sf!=of), !zf&&(sf==of), 0, 0). The single-line spec pins every condition row; the generator re-checks the whole expected table (order, codes, duplicate codes, predicate-shape arms flag/not/and/or/eq/ne) and renders `KProgFormal/GeneratedX86Cond.lean` and `generated/x86_cond.h` byte-for-byte; the header adds the static-assert code pins plus the `KPROG_X86_EVAL_CC` ternary ladder (`((CC) == X86_CC_O ? OF : … : 0)`); the hand module (`KProgFormal/X86ControlFlow.lean`) defines `x86CondSpec` over `X86Flags` and proves `x86_condition_sound`, and generated setcc and cmov modules restate `evalCond`/`condOf` from it. Six hosts sweep the contract: `test_x86_cmov_host.c` (484369 cases), `test_x86_setcc_host.c` (590726), `test_x86_cc_decode_host.c` (152), `test_x86_cmov_route_host.c` (26526735), `test_x86_setcc_route_host.c` (2433038), `test_x86_setcc_mem_route_host.c` (8958727). The 114-row shake catches 103 mutations (24 at the spec file, 22 at the generator, 57 through the Lean chain) with 11 documented equivalents: failure-path-only message repaints, list-spacing and row-padding repaints the checker does not compare, generated-file banner repaints no consumer validates, and the branch-refinement theorem rename without in-module consumers.

### Step 0227 — x86 cmpop mutation coverage

The cmpop contract pins the shared CMP/TEST opcode kernel eight bodies route through (`KPROG_X86_CMPOP_RHS_SOURCE` / `FLAG_KIND` / `LHS_SOURCE` / `DISP_KIND` / `WRITE_WIDTH` selectors over defines `X86_OP_CMP_IMM` 0x0c, `CMP_REG` 0x0d, `TEST_IMM` 0x0e, `TEST_REG` 0x0f, `CMP_MEM_IMM` 0x1d, `TEST_MEM_IMM` 0x1e, `CMP_MEM_REG` 0x1f, `TEST_MEM_REG` 0x3b; right-hand side immediate for the `_IMM` forms and register otherwise, subtraction flags for CMP and logic flags for TEST, memory left-hand side and store/simm displacement for the memory forms, and 64 bits the default write width when the opcode carries no width code). The single-line spec pins all eight rows; the generator re-checks the whole expected table and renders `KProgFormal/GeneratedX86CmpOp.lean` and `generated/x86_cmpop.h` byte-for-byte; the header pins every opcode with a static assert plus the `KPROG_X86_CMPOP_OP_*` per-opcode table and selectors; the hand module (`KProgFormal/X86CmpOpHandler.lean`) restates each table and proves the 18 refinements. Two hosts sweep the contract: `test_x86_cmpop_host.c` (2913 cases, the table against an independent decode/flags model) and `test_x86_cmpop_route_host.c` (47529 cases, the real simulator bodies across five width codes, both displacement lanes, flag dispatch and direct execution). The 123-row shake catches 93 mutations (32 at the generator, 30 through the Lean chain, 9 on the contract host, 23 on the route host) with 30 documented equivalences: the in-module-unreferenced thin theorem renames, failure-path-only printf/banner repaints, and the simulator-helper repaints the routed result does not observe.

### Step 0226 — x86 width-table mutation coverage

The width-table contract pins the operand-width kernel every simulator body and Lean handler composition routes through (`KPROG_X86_WIDTH_MASK` / `GeneratedX86Width.mask`): four widths (8/16/32/64-bit with codes 1/2/4/8) each pin a mask, sign mask, and bit count, and a decoded width code of 0 (an absent width field) resolves to the 64-bit width (`KPROG_X86_WIDTH_EFFECTIVE`, absent-code pin, 64-bit default). The single-line spec JSON (`x86_width_spec.json`) pins the schema/operation metadata, the four rows with their mask/sign-mask/bits fields, and the effective entry; the generator (`generate_x86_width_spec.py`) re-checks the whole expected table exactly (length, per-row keys, absent code not colliding with a width code, default) and renders the Lean `Width` module and the C header byte-for-byte. The hand module (`KProgFormal/X86Width.lean`) restates code/mask/signMask/bits plus `narrow`/`zero`/`sign` and proves the eight refinements, the effective-resolution laws (absent names no width, default is the 64-bit code, identity on real widths), and the sign-mask observability law. Two hosts sweep the contract: `test_x86_width_effective_host.c` (1280 cases, the `EFFECTIVE` macro against an independent `code ? code : 64` model over the full decoded byte range) and `test_x86_width_effective_route_host.c` (518 cases, the simulator's routed register/stack/memory/LEA/move/ALU/IMUL/flag bodies against the same model plus the code-0-equals-code-64 observable on every scenario). `build/mut_x86_width.py` (untracked) runs 168 rows over the seven contract files with four detectors (generator byte-exact check, two-module Lean chain, effective host, route host); 119 rows catch (43 generator, 40 Lean, 11 effective host, 25 route host) and 49 survive as documented equivalences: the self-consistent spec/generator helper renames, `zip` strict-flag semantics on equal-length lists, dead generator collision branches, generated-file doc-comment repaints invisible outside the render check, failure-path-only printf/banner repaints, the 0..254 sweep prefix of an already-agreeing pair, in-module-unreferenced theorem names, include-guard repaints, and single-TU observable-but-equivalent sign/bits arms.


### Step 0225 — x86 arithmetic-immediate mutation coverage

The arithmetic-immediate contract pins the shared widening rule consumed by every handler that takes an instruction immediate (`KPROG_X86_IMMEDIATE_VALUE` / `GeneratedX86Immediate.value`): the 64-bit artifact field carries the immediate, the low 32 bits are the encoded value with exactly one sign-extend flag (`sign_extend_width: w64`), so 64-bit operations sign-extend the low word and every narrower width consumes the zero-extended low word. The single-line spec JSON (`x86_immediate_spec.json`) pins the five metadata fields, the generator (`generate_x86_immediate_spec.py`) re-checks the whole expected dictionary exactly on every `--check` and renders the Lean `value` combinator (`BitVec.and raw 0xffffffff`, `0x80000000` test, `0xffffffff00000000` recombination) and the C macro byte-for-byte, and the hand module (`KProgFormal/X86Immediate.lean`) restates the rule independently (`raw.setWidth 32`, `.w64` sign-extend 64, else `setWidth 64`) and proves `x86_immediate_value_refines` with `cases width <;> simp <;> bv_decide`, plus two `native_decide` examples (`0x0000000080000001` sign-extends under `w64` to `0xffffffff80000001` and does not under `w32`).


### Step 0224 — x86 MOV_STORE handler-composition mutation coverage

The MOV_STORE handler-composition contract pins the single body `X86_SIM_L_EXEC_STORE`, shared by `X86_OP_MOV_STORE_IMM` (0x07) and `X86_OP_MOV_STORE_REG` (0x08): the opcode's `FLAGS` code resolves the single write width (`KPROG_X86_STORE_WIDTH`, 64 bits when the opcode carries none — the same width serves the immediate value and the memory write, and the stack arm re-derives the same `FLAGS ? FLAGS : 64` expression, unlike the read body's second, AUX-sourced memory width), the displacement form splits the instruction-immediate artifact (`KPROG_X86_STORE_DISP`: the immediate store takes `(s32)(IMM >> 32)`, the register store the whole artifact), the value source is the width-aware immediate rule or the full-64-bit register read (`KPROG_X86_STORE_VALUE`), the AUX source shift is read only on the register form and taken modulo 64 (`KPROG_X86_STORE_SRC_SHIFT`/`SHIFTED_VALUE`), and the one-fact arm chain (`KPROG_X86_STORE_ARM`) sends a stack-pointer destination through the stack helper and every other destination through the ordinary little-endian store. The spec JSON pins the whole metadata template byte-for-byte (selector wording `opcode_operand_then_register_identity_arm`, operation tag `x86StoreHandler`, and the five width, two displacement, two value, two shift, and two arm rows); the generator re-checks every row order and resolution on every `--check`, and renders the Lean `Code`/`resolveWidth`/`DispForm`/`ValueSource`/`ShiftSource`/`Arm` module and the C macros byte-for-byte. The hand module restates all five selectors independently and proves the refinements, the not-absent totality law, the stack-arm identity law (`x86_store_arm_stack_iff`), the two modulo-64 shift laws, the width-narrowed byte-update bridge shared with the movbe/push-pop/setcc-memory handlers, the full step composition, and the two-forms-differ examples.

`build/mut_x86_store.py` (untracked) runs 73 rows over the six contract files with three detectors; the host is `test_x86_store_host.c`, which verifies the width macro over the five codes and the arm macro over both selector values, then drives the whole handler (width, displacement slice, value source, AUX shift, offset, arm, little-endian store or stack write) against a hand-written body model — 48013 cases. 53 rows catch (32 at the generator stage, 12 through the Lean chain, 9 by the host oracle) and 20 survive as documented equivalences. Shake reclassified 2 rows to their final classes: the `KPROG_X86_STORE_WIDTH_ABSENT` define repaint is caught by nothing because the width macro can only emit one of the five real codes and the host's absent pin compares `got` against a constant the resolution cannot produce, and the generated `(IS_STORE_IMM) != 0 ? 0U :` branch repaint is tautological C for the 0/1 selector input.

### Step 0223 — x86 MOV_LOAD handler-composition mutation coverage

The MOV_LOAD handler-composition contract pins the single body `X86_SIM_L_EXEC_MOV_LOAD`, shared by `X86_OP_MOV_LOAD`, `X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD`: the write width defaults to 64 bits when the opcode carries none (`KPROG_X86_MOV_LOAD_WRITE_WIDTH`), the memory width falls back to the resolved write width when the addressing mode carries none (`KPROG_X86_MOV_LOAD_MEM_WIDTH`), and the arm chain (`KPROG_X86_MOV_LOAD_ARM`) tests register identity first — a stack-pointer base always reads the stack at the resolved memory width, at any width and for any opcode — then the ABI pointer arm, gated on the plain `_MOV_LOAD` opcode, both resolved widths being 64 bits, and an ABI-tagged non-stack base, with every other access taking the ordinary scalar load at the memory width, sign-extended for `_MOVSX_LOAD` and confined to the write width by the partial-register writeback. The spec JSON pins the whole metadata template byte-for-byte (selector wording, operation tag `x86MovLoadHandler`, and the 25-code width-resolution table plus the 32-row arm table over the `is_rsp`/`is_mov_load`/`mem_is_64`/`write_is_64`/`base_is_abi` facts); the generator re-checks both row orders and every row's resolution against `WIDTH_ORDER` and `ARM_ORDER` on every `--check`, and renders the Lean `Code`/`resolveWidth`/`Arm`/`arm` module and the C macros byte-for-byte. The hand module restates both width fallbacks and the arm predicate nesting independently and proves the two refinements, the not-absent totality law, the stack-arm register-identity law (`x86_mov_load_arm_stack_ignores_op_and_tag`), the ABI conjunction law (`x86_mov_load_arm_abi_iff`), the all-arms-reachable theorem, and the full step composition against the byte-ladder, sign-extend, writeback, and ABI-tag contracts, plus seven `native_decide` examples.

`build/mut_x86_mov_load.py` (untracked) runs 87 rows over the six contract files with three detectors; the host is `test_x86_mov_load_host.c`, which verifies both width macros over all 25 code pairs and the arm macro over all 32 selector combinations against independent fallback and branch-chain oracles, then drives the whole handler (width resolution, arm selection, offset, byte-ladder load, ABI provenance, partial-register writeback) against a hand-written body model — 86461 cases. 59 rows catch (21 at the generator stage, 15 through the Lean chain, 23 by the host oracle) and 28 survive as documented equivalences. Shake reclassified 12 rows to their final classes: the dead `ARM_CODES` map repaint is invisible (`arm_defines` renders from inline tuples), the three `KPROG_X86_MOV_LOAD_ARM_STACK`/`ABI_PTR`/`ORDINARY` code renumberings are self-consistent in macro and oracle, the include-guard repaint is invisible to a single-TU host build, the `x86MovLoadResolveWidthSpec` rename is caught (consumed inside the module), and the seven in-module-only theorem renames survive (no module imports X86MovLoadHandler's theorems beyond the file itself).

### Step 0222 — x86 memory read dispatch mutation coverage

The memory read-dispatch contract pins the value-source selector the shared x86 read body applies before the offset and load contracts run: a stack-pointer base reads through the stack helper at any width and whatever its tag (register identity first — the x86 asymmetry against AArch64's tag-first dispatch), an ABI-tagged base reaches the 64-bit pointer load only at width 64, and every other access takes the ordinary byte-ladder load. The spec JSON pins the whole metadata template byte-for-byte (selector wording, operation tag, and eight `is_rsp`/`is_abi`/`w64` rows with their `src` defines), the generator validates row order against the pinned `ORDER` tuple and each row's source against the `SRC_DEFINES` map, and renders the Lean `ValueSrc`/`valueSrc` table and the C `KPROG_X86_MEM_READ_SRC` predicate byte-for-byte. The hand module restates the dispatch as the C-shaped predicate nesting and proves the refinement plus four laws: `stack_overrides_tag`, `abi_requires_width64`, `no_tag_widening`, and `all_arms_reachable`; two handler modules (cmov, movbe) consume the generated `valueSrc`, and the refinement feeds two `rw` lists in those modules, so both renames break downstream proofs.

`build/mut_x86_mem_dispatch.py` (untracked) runs 56 rows over the six contract files with three detectors; the host is `test_x86_mem_read_dispatch_host.c`, which compares the macro against an independent oracle (register identity tested before the tag) over 2 base-kinds × 5 tags × 4 widths plus stack-override/width-gate/arm-reachability probes, then drives the dispatch together with the offset and byte-ladder load contracts over a deterministic register/memory/stack model — 3650 cases. 40 rows catch (19 at the generator stage, 9 through the Lean chain, 12 by the host oracle) and 16 survive as documented equivalences. Shake reclassified 5 rows to their final classes: the `KPROG_X86_MEM_SRC_STACK` 0U→5U and `KPROG_X86_MEM_SRC_NORMAL_LOAD` 2U→7U renumberings are self-consistent in macro and oracle (a STACK/ABI collision at 2U is caught), the refinement theorem rename is caught (it feeds `rw` lists in X86CmovHandler and X86MovbeHandler), and the `stack_overrides_tag`/`abi_requires_width64` renames survive (self-contained: no module imports those names).

### Step 0221 — x86 little-endian memory access mutation coverage

The little-endian memory-access contract pins load and store byte semantics: load assembles the access width's bytes (byte `i` contributes bits `8i..8i+8`) and narrows the result with the width mask, and store masks the value then writes the width's bytes in little-endian order, leaving bytes at or above the width untouched. The spec JSON pins the whole metadata template byte-for-byte (little endianness, the `zero_is_64` width rule, the load/store/byte_rule wordings, and the four width rows), and the generator renders the Lean `byteCount`/`assemble`/`load`/`storeByte`/`store` module and the C `KPROG_X86_MEM_LOAD`/`KPROG_X86_MEM_STORE` macros byte-for-byte. The hand module restates assemble, load, and storeByte through the width bridge and proves the three refinements, the byte-count law, and two `native_decide` examples (the `0x12345678` `w32` load and the `0xaabb` `w16` store bytes).

`build/mut_x86_mem_access.py` (untracked) runs 49 rows over the six contract files with three detectors; the host is `test_mem_access_host.c`, which compares both macros against an independent byte-level oracle over 5 fixed vectors across all four widths plus a 20000-iteration LCG sweep of random loads and stores. 40 rows catch (17 at the generator stage, 16 through the Lean chain, 7 by the host oracle) and 9 survive as documented equivalences. Shake reclassified 4 rows to their final classes: the `X86MemByte` abbreviation rename and the store-byte refine theorem rename are caught (both are consumed by the ten-plus memory handler modules), the host `cases += 3` repaint is invisible to every detector (reported counter only), and three declared rows had silent no-op probes (an f-string suffix repaint that is not in the file, and three signature-lines repaints that left the rows self-identical) replaced with real semantics repaints (oracle byte-0 skip, checker `+1` bias, store reference-byte shift).

### Step 0220 — x86 IMUL flags mutation coverage

The IMUL-flags contract pins the multiply overflow rule: CF and OF are set together exactly when the width-narrowed signed product leaves the signed width range --- the signed magnitude of one factor must be nonzero and the other magnitude must exceed the limit divided by it, with the sign mask minus one for same-sign products and the full sign mask for mixed-sign products --- while ZF and SF are preserved. The spec JSON pins the whole metadata template byte-for-byte (inputs, `zero_is_64` width rule, the `signed_abs`/`limit`/`overflow` wordings, and the per-field overflow/preserve actions), and the generator renders the Lean `signedAbs`/`mixedSign`/`apply` module and the C `KPROG_X86_SET_IMUL_FLAGS` macro byte-for-byte. The hand module restates the overflow rule through the width bridge and proves the defined law, the apply refinement, and two `native_decide` boundary theorems (the `w16` overflow edge and the `w8` minimum that stays in range).

`build/mut_x86_imul_flags.py` (untracked) runs 48 rows over the six contract files with three detectors; the host is `test_imul_flags_host.c`, which compares the macro against an independent `__int128` signed-product oracle over 15 fixed vectors (including the `0x0164`/`0xfe3c` `w16` spurious-conjunct discriminator) plus a 20000-iteration LCG sweep round-robining widths. 39 rows catch (19 at the generator stage, 11 through the Lean chain, 9 by the host oracle) and 9 survive as documented equivalences. Shake reclassified 7 rows to their final classes: the two in-module-only hand theorem renames and the doc-comment repaint are compiler-invisible; the host limit repaint needed the mixed-sign headroom removed (`sign - 1` on both arms), the oracle minimum repaint moved up (`-h + 1`, the `-h - 1` product edge is unreachable in range), and the C_OF assignment repaint needed the 27-space run matched exactly (a 13-space pattern silently no-ops).

### Step 0219 — x86 SBB flags mutation coverage

The SBB-flags contract generates the four subtract-with-borrow flag transitions: CF is the borrow chain `(a <u b) || (borrow && a == b)`, ZF is `r == 0`, SF is `(r & sign) != 0`, and OF is the signed-borrow product `(a ^ b) & ((a ^ r) & sign) != 0`. The spec is a typed expression tree over the `a`/`b`/`r`/`sign` word atoms, the `borrow`/`zero` atoms, and the `lor`/`land`/`band`/`ult`/`eq`/`xor`/`nonzero` operators (`lor`/`land` render as `||`/`&&`; `band` renders as a BitVec AND); `load()` pins the schema, operation tag, and flag order, and the generator renders Lean and the C `KPROG_X86_SET_SBB_FLAGS` macro byte-for-byte. The hand module `X86SbbFlags.lean` restates all four flags independently and proves the flags refinement, the width-narrowed step composition (narrowing `a`, `b`, and the SBB-result word before re-deriving the flags), the branch-PC composition, and two `native_decide` boundary theorems pinning signed overflow exactly at the `-1 - 127 - 1` edge.

`build/mut_x86_sbb_flags.py` (untracked) runs 58 rows over the six contract files with three detectors: 41 rows catch (19 at the generator stage, 13 through the Lean chain, 9 by the host oracle), and 17 survive as documented equivalences. The host side drives the memory-ALU handler's SBB arm (the same 22048-case composition as Steps 0214-0218) against the 128-bit borrow oracle. Shake reclassified 3 rows: the 0x7f/0x80 boundary constants sit inside the pinned-OF plateau (swapping either flips `OF` on both sides identically), so both `native_decide` repaints are equivalences, not catches.

### Step 0218 — x86 SBB result mutation coverage

The SBB-result contract generates the subtract-with-borrow word value shared by the x86 simulator, the Lean model, and the memory-ALU handler: the result expression is `(a - b) - borrow`, with the C rendering extending the borrow bit through `!!(BORROW)` and Lean through `if borrow then 1 else 0`. The spec is a typed expression tree over the `a`/`b` word atoms, the `borrow` atom, and the `sub` binary node; `load()` pins the schema, operation tag, and the single `result` expression name, and the generator renders Lean and the C `KPROG_X86_SBB_RESULT` macro byte-for-byte. The hand module `X86SbbResult.lean` restates the result independently and proves the outright refinement and the width-narrowed composition (`x86_narrow_refines`); eight Lean modules (ALU-result, writeback, cmpop, inc/dec, mem-compare, SBB-flags, sub-result, unary) import the generated or hand module, so renames break the chain.

`build/mut_x86_sbb_result.py` (untracked) runs 40 rows over the six contract files with three detectors: 24 rows catch (13 at the generator stage, 6 through the Lean chain, 5 by the host oracle), and 16 survive as documented equivalences. The host side drives the memory-ALU handler's SUB and SBB arms (the same 22048-case composition as Steps 0214-0217) against the 128-bit borrow oracle. Shakedown reclassified 1 row: `(!!(BORROW))` -> `(BORROW)` in the generated C macro is value-preserving over the 0/1 borrow domain the arms pass, so it is an equivalence, not a catch.

### Step 0217 — x86 SUB flags mutation coverage

The SUB-flag contract generates the four subtraction flag transitions shared by the x86 simulator, the Lean model, and the memory-ALU handler composition: CF is unsigned borrow `a <u b`, ZF is `a == b`, SF is `(r & sign) != 0`, and OF is the signed-borrow product `(a ^ b) & ((a ^ r) & sign) != 0`. The spec is a typed expression tree over the `a`/`b`/`r`/`sign` word atoms with `ult`/`eq`/`and`/`xor`/`nonzero` operators (the subtraction generator drops addition's `zero` and `not` nodes); `load()` pins the schema, operation tag, and flag order, and the generator renders Lean (BitVec combinators) and the C `do/while` macro `KPROG_X86_SET_SUB_FLAGS` byte-for-byte. The hand module `X86SubFlags.lean` restates all four flags independently and proves the flags refinement and the branch-PC composition; seven Lean modules (compare, cmpop, sbb-result, sub-result, unary, inc/dec, writeback handlers) import the hand module, so hand renames break the chain.

`build/mut_x86_sub_flags.py` (untracked) runs 53 rows over the six contract files with three detectors: 38 rows catch (18 at the generator stage, 11 through the Lean chain, 9 by the host oracle), and 15 survive as documented equivalences. The host side drives the memory-ALU handler's SUB arm (the same 22048-case composition as Steps 0214/0216) against the 128-bit borrow oracle. First build was green with no reclassifications.

### Step 0216 — x86 ADD flags mutation coverage

The ADD-flag contract generates the four addition flag transitions shared by the x86 simulator, the Lean model, and the memory-ALU handler composition: CF is unsigned carry-out `r <u a`, ZF is `r == 0`, SF is `r & sign != 0`, and OF is `~(a ^ b) & ((a ^ r) & sign) != 0`. The spec is a typed expression tree over the `a`/`b`/`r`/`sign` word atoms with `ult`/`eq`/`and`/`xor`/`not`/`nonzero`/`zero` operators; `load()` pins the schema, operation tag, and flag order, and the generator renders Lean (BitVec combinators) and the C `do/while` macro `KPROG_X86_SET_ADD_FLAGS` byte-for-byte. The hand module `X86AddFlags.lean` restates all four flags independently and proves the flags refinement and the branch-PC composition; `X86AddResult`, `X86AluWriteback`, and `X86IncDec` import the hand module, so hand renames break the chain.

`build/mut_x86_add_flags.py` (untracked) runs 57 rows over the six contract files with three detectors: 41 rows catch (21 at the generator stage, 11 through the Lean chain, 9 by the host oracle), and 16 survive as documented equivalences. The host side drives the memory-ALU handler's ADD arm (the same 22048-case composition as Step 0214) against the 128-bit oracle. Shakedown reclassified 1 row: the generated Lean module's header-comment repaint is compiler-invisible, so it is an equivalence, not a catch.

### Step 0215 — x86 ALU decode mutation coverage

The ALU decode contract pins the parsed-mnemonic code table shared by the x86 simulator, the Lean model, and the artifact encoder: sixteen operations (add, sub, xor, or, and, shl, shr, sar, rol, imul, inc, not, sbb, dec, neg, adc) with mnemonic = name, codes 0-15, and the handler split - sbb maps to the borrow-sensitive handler, adc to the carry-sensitive handler, everything else generic. The spec loader rejects any wrong name/code/handler column and any unknown top-level key, the generator renders the Lean inductive with `code`/`mnemonic`/`handlerForCode`, the C header's sixteen `X86_ALU_*` defines plus the two handler-selector macros, and the app-side `ALU_AUX` python mapping byte-for-byte. The hand module `X86AluDecode.lean` restates all three columns independently and proves the code, mnemonic, and handler refinements plus the packed-AUX round-trip (`x86_alu_aux_handler_refines` extracts the same handler from a typed ALU code shipped through the register-lane AUX); `X86AluResultSpec` and `GeneratedX86AluResult` import the generated module, so generated renames break the chain.

`build/mut_x86_alu_decode.py` (untracked) runs 48 rows over seven files (the six contract files plus the app-side python mapping, which the generator byte-checks) with three detectors: 41 rows catch (15 at the generator stage, 13 through the Lean chain, 13 by the host oracle), and 7 survive as documented equivalences. The host side (`test_x86_alu_decode_host.c`, which includes `x86_sim.h`) compares every generated constant against an independent mnemonic table, drives the real `x86_alu_result` dispatcher against arithmetic-identity recomputations over a 16x6x8x4 operand/width spread, and binds both handler-selector macros plus their mutual exclusion to the dispatcher's own identity checks (3256 cases). Shakedown reclassified 1 row: appending an entry to the app-side `ALU_AUX` mapping is a generator-detectable repaint (the byte-check re-renders the mapping), not an equivalence.

### Step 0214 — x86 ADC mutation coverage

The ADC contract generates the carry-propagating 64-bit add and the four flag expressions shared by the x86 simulator, the Lean model, and the memory-ALU handler composition: the word result is `(a + b) +` the carry-in re-extended to 0/1, CF is unsigned carry-out `(r <u a) || (carry && r == a)`, ZF is `r == 0`, SF is `r & sign != 0`, and OF is `~(a ^ b) & ((a ^ r) & sign) != 0`. The spec is a typed expression tree: `validate()` type-checks every node against word/bool atoms and operator arities (exiting 1 on any ill-typed tree), `load()` pins the schema, operation tag, and the four flag names in order, and the generator renders Lean (BitVec combinators, `carry` as `if carry then 1 else 0`) and C (`(!!(CARRY))` inside `KPROG_X86_ADC_RESULT`, the flags as a `do/while` assignment macro) byte-for-byte. The hand module `X86Adc.lean` restates the result and flags independently and proves the result and flags refinements plus the width-narrowed step refinement and the branch-PC composition; five Lean modules import the generated module, so generated renames break the whole chain.

`build/mut_x86_adc.py` (untracked) runs 71 rows over the six contract files with three detectors: 51 rows catch (23 at the generator stage, 13 through the Lean chain, 15 by the host oracle), and 20 survive as documented equivalences. The host side drives the memory-ALU handler's ADC arm (`test_x86_mem_alu_handler_host.c`, which also composes the width, mem-access, and write contracts) against a 128-bit carry/borrow oracle over 4 widths x 4 ops x 8x8 boundary dsts x 2 carry-in boundaries plus a 20000-case fixed-seed random sweep (22048 cases). Shakedown reclassified 5 rows: dropping the `((!!(CARRY)))` normalization keeps the value for every 0/1 carry-in (equivalence), the self-contained `generatedX86AdcFlags` rename compiles green, and three host-repaint rows whose new text formed invalid integer literals are compile-break catches, not equivalences.

### Step 0213 — AArch64 vector-lane (D0/Q0) mutation coverage

The four vector memory-transfer opcodes — `ARM64_OP_LOAD_D0` 0x28, `ARM64_OP_LOAD_Q0` 0x2a, `ARM64_OP_STORE_D0` 0x29, `ARM64_OP_STORE_Q0` 0x2b — move the SIMD register's low 64-bit lane or both 64-bit lanes to or from memory: `LDR .D0` loads the low lane, `LDR .Q0` loads low then high, and the two `STR` forms store one or both lanes back out in the same order. `arm64_dq_mem_spec.json` is an exact-match dict (`load()` compares the whole structure against EXPECTED, re-checks every column against per-opcode dictionaries, exits 1 on a duplicate define, and pins `lane_stride` = `ARM64_WIDTH_64` and `high_lane_stride` = 8); the generator re-renders the generated Lean module and C header byte-for-byte, and the header re-pins the four opcodes with static asserts, the access codes, per-opcode ACCESS/LANES/INDEX macros, and the four-way `KPROG_ARM64_DQ_MEM_INDEX` chain whose `else` makes the selector total off the opcode set (0xff falls through to arm 3, as in the pair-move chain). The contract deliberately does not restate the address offset or the pre/post-indexed base adjustment, which live in the memory-offset and writeback macro contracts; it fixes only *which* lanes each opcode transfers and in which order, each a full 64-bit scalar access. The hand module restates the ordered lane plan (`[0]` for `.D0`, `[0, 8]` for `.Q0`) independently of the generated index arithmetic and proves the transfer-list and lane-count refinements, the access dispatch, the lane plan, the lane stride, the distinct-lane property (a body that re-reads lane 0 into the high lane's place provably fails the plan), the arm-index dispatch, and the low/high lane examples. No external Lean module imports the generated `GeneratedArm64DqMem` or the hand handler, so generated-arm mutations must be caught by the fresh-olean hand chain and hand-internal renames stay compile-green equivalences.

`build/mut_arm64_dq_mem.py` (untracked) runs 83 rows over the seven contract files with three detectors: 54 rows catch (17 at the generator stage, 19 through the Lean chain — which rebuilds the generated olean before the hand check so a stale cache cannot hide a generated-arm repaint — and 18 by the host oracle), and 29 survive as documented equivalences. The host oracle part 1 checks the lane-stride, access-code, lane-count, access-direction, and index constants plus the four `INDEX(ops)` selections and the total default arm; part 2 drives the full composition of both bodies (lane-order reads and writes, pre/post writeback, x0/x1 mapping) over 4*32*3*4*6 = 9216 grid cases. Route recheck: `test_arm64_dq_mem_route_host.c` (62418 cases) re-derives the contract through the simulator macro and stays green after every host-detector run.

### Step 0212 — AArch64 decode-table mutation coverage

The `arm64_decode` contract (`arm64_decode_spec.json` 1 line,
`generate_arm64_decode_spec.py` 152 lines,
`generated/arm64_decode.h` 33 lines,
`KProgFormal/GeneratedArm64Decode.lean` 112 lines,
`KProgFormal/Arm64Decode.lean` 99 lines,
`test_arm64_decode_host.c` 198 lines, and the artifact-encoder
output `../arm64/micro-prog/generated_arm64_decode.py`) pins the
four mnemonic-to-code tables shared by the encoder, the C simulator
constants, the Lean model, and the Python encoder module: ALU
add/sub/and/bic/eor/orr -> `ARM64_ALU_*` 0..5, SHIFT lsl/lsr/asr/ror
-> `ARM64_SHIFT_*` 0..3, MOD ""/lsl/lsr/asr/ror + uxtw/sxtw/uxth/
sxth/uxtb/sxtb -> `ARM64_MOD_*` 0..10 (the empty mnemonic maps to
the `none` constructor), and BITFIELD ubfx/sbfx/ubfiz/bfxil/bfi ->
`ARM64_BITFIELD_*` 0..4. `load()` checks the top-level key set, the
table set, per-table lengths, per-row canonical keys, and the
per-row mnemonic/macro/code triplet against the exact-match
EXPECTED dict; the generator re-renders three outputs
byte-for-byte (the Lean module spans four namespace/inductive/
code/mnemonic blocks, the C header is the sole source of the
`ARM64_*` codes, and the encoder dicts are consumed at import time
by the micro-program builder). The hand module restates all four
tables as independent mnemonic/code lists, the constructor
enumerations, proves each table's projection refinement with
`native_decide`, and the per-table code-distinctness theorems;
fourteen Lean modules consume the generated decode types (the
ALU/mod/shift/bitfield handlers and their generated siblings), so
generated and hand renames both break the compile - unlike the
pair-move hand module, which nothing imports.

`build/mut_arm64_decode.py` (78 rows) perturbs the seven files with
the three detectors: 15 catch at the generator stage (one spec row
per table plus the operation tag; the seven generator
expected/schema/render anchors), 24 catch through the Lean chain
(the four namespaces, constructor renames, code and mnemonic arms,
the import rename, the hand table-body repaints, constructor-list
repaints, the projection goal, and the four distinctness goals),
and 22 catch by the host oracle (the seven header macros, the four
independent-table rows, the four macro-array repaints, the
expect_eq sense, the duplicate check, the AUX ALU and shift pack
repaints, both byte-extractor shifts, the MOVK source repaint). 17
rows survive as documented equivalences: the five unreachable
generator error-message repaints, the four bare hand-theorem
renames (single occurrence each, compile green), the four
table-call label repaints (error strings only), the
duplicate-detection message, the OK banner, and the probe-line
label and bitfield-loop-bound repaints.

### Step 0211 — AArch64 pair-move mutation coverage

The `arm64_pair_mem` contract (`arm64_pair_mem_spec.json` 1 line,
`generate_arm64_pair_mem_spec.py` 199 lines,
`generated/arm64_pair_mem.h` 53 lines,
`KProgFormal/GeneratedArm64PairMem.lean` 31 lines,
`KProgFormal/Arm64PairMemHandler.lean` 96 lines,
`test_arm64_pair_mem_host.c` 529 lines) pins what the two pair-move
opcodes do before the address macros take over: `ARM64_OP_LDP` 0x21
loads two 64-bit slots into a register pair (low slot into DST, high
slot one 64-bit stride higher into SRC) and `ARM64_OP_STP` 0x22
stores the pair back out in the same order (low from SRC, high from
SRC2). `load()` re-checks the exact-match dict per column, exits 1 on
duplicate defines, and pins the non-contiguous codes against
`kprog/arm64/arm64_sim.h` at generation time; the generated header
re-pins them with static asserts and emits the slot/high-slot
strides, the access codes, the per-opcode ACCESS/INDEX macros, and
the two-way `KPROG_ARM64_PAIR_MEM_INDEX` chain whose `else` makes the
selector total off the opcode set (any other code, e.g. `0xff`,
dispatches to the STP arm index). The contract deliberately does not
restate the address offset (`MEM_BASE_OFF`) or the pre/post writeback
(`MEM_PRE`/`MEM_POST`) -- those live in the macro contracts with
their own proved steps; the pair contract fixes only which two slots
each opcode transfers and in which order, a full 64-bit access
each. The hand module restates the ordered slot plan independently
(`arm64PairMemSlotPlanSpec` is `[0, 8]` for both opcodes) and proves
the refinement, the slot-count refinement, the access-direction
dispatch, the slot-plan/count facts, the distinct-slot property, the
stride, the arm-index dispatch, and the low/high slot examples. The
host oracle part 1 checks every constant and selector (including the
total default arm and a collide check that the two access codes
differ); part 2 drives the full composition of both bodies -
pre/post writeback, the read-before-write ordering of the load (an
LDP whose target register is also the base still reads the original
base), and the register-pair mapping - over the 7-register x
7-register x 2-tag x 33-base x 3-flags x 4-index x 6-imm grid plus a
fixed-seed randomized sweep (6984 + 458712 = 465696 cases), and
`test_arm64_pair_mem_route_host.c` re-derives the same plan through
the simulator macro (122891 cases).

`build/mut_arm64_pair_mem.py` (90 rows) perturbs the six files with
the three detectors: 10 catch at the generator stage (the LDP code,
code index, STP access string, slot count, and high-slot stride in
the spec; the order, codes, access, and high-stride tables in the
generator), 17 catch through the Lean chain (the namespace and LDP
constructor renames, both access arms, both arm indexes, the slot
count and offset bodies, the import/open renames, the independent
plan arms (`[0, 8]` -> `[0, 9]`), the access-dispatch goal, the
distinct-slot goal, the arm-index goal, and the two example goals),
and 32 catch by the host oracle (the two opcode asserts, the slot
stride define, the high-slot stride, the slot count, both access
codes, both per-opcode access macros, both index macros, the two-way
chain's LDP compare and both arm assignments, the contract step's
slots/index/access-pick/load-compare and the slot-stride multiply,
and the model step's slots/index/is-load repaints). 31 rows survive
as documented equivalences: the seven unreachable generator
error-message repaints, a whitespace-only generated offset-arm edit,
the slot-stride assert message repaint, the eleven self-contained
hand renames (nothing imports the hand module - unlike
`X86MulxHandler` consuming the multiply ladder - so a
definition-and-all-references rename compiles green), and the
eleven message/probe repaints (the nine part-one failure messages,
the OK/FAIL banner repaints, and the randomized-sweep seed).

### Step 0210 — AArch64 multiply family mutation coverage

The `arm64_mul` contract (`arm64_mul_spec.json` 0 lines -- the spec
file is the compact one-line JSON, `generate_arm64_mul_spec.py` 284
lines, `generated/arm64_mul.h` 108 lines,
`KProgFormal/GeneratedArm64Mul.lean` 51 lines,
`KProgFormal/Arm64Mul.lean` 370 lines, `test_arm64_mul_host.c` 178
lines) pins the eight multiply arms the simulator's `ARM64_SIM_L_EXEC`
handler applies before the width-narrowing register write:
`ARM64_OP_MADD` 0x0a, `MSUB` 0x0b, `MUL` 0x0c, `UMULL` 0x0d,
`UDIV` 0x0e, `UMULH` 0x2e, `UMADDL` 0x3b, `SMADDL` 0x40. The family
is not a decode table -- the opcodes are non-contiguous -- so
`load()` parses `kprog/arm64/arm64_sim.h` and exits 1 on any
opcode drift, cross-checks `arm64_flags_spec.json` so no multiply
mnemonic is declared a flag family (the family writes no NZCV), and
the emitted static asserts pin the same values at compile time. Each
spec row carries name/code/macro plus per-arm `lean`/`c` strings;
UMULH is special-cased: its C arm is the hoisted four-partial-product
radix-`2^32` ladder (lo, mid1, mid2, hi, one carry out of the 32-bit
column) rather than an expression string, and its Lean arm is the
same ladder as a `let` chain. The spec is an exact-match dict; the
generator re-renders the generated Lean module (`Mul` constructors,
`code`, `mnemonic`, `value` arms) and C header (per-opcode asserts,
the `HANDLED` cover, the eight `case` arms, `default: UNSUPPORTED`)
with byte-for-byte `--check`. The hand module restates everything
independently: the radix decomposition and carry lemmas, the
algebraic `arm64MulUmulhNatAlg`, the ladder identity against the
`Nat` high word (also consumed by `X86MulxHandler`), the sign
extension helper, the independent `arm64MulValueSpec` (MSub via
`addend + ~~~(lhs * rhs) + 1`, UMULH via the 128-bit product
`setWidth 64`, SMADDL via the sign-extension helper), the refinement
per arm (`simp`/`bv_decide`/ladder lemma), the width composition,
the NZCV identity, the code range and dispatch, and eight canonical
`native_decide` examples. The host oracle drives the macro over
20 boundary vectors x 8 ops plus a 20000-iteration fixed-seed LCG
sweep (160160 value cases) against an architectural
`unsigned __int128` UMULH oracle, and forks the `default` arm to
prove unsupported opcodes invoke the caller's `UNSUPPORTED` (abort)
instead of silently returning 0.

`build/mut_arm64_mul.py` (72 rows) perturbs the six files with the
three detectors: 4 catch at the generator stage (the MADD/UDIV/
SMADDL spec codes and the MADD `lean` string; the generator's own
UMULH ladder rows are rendered, not re-parsed), 34 catch through the
Lean chain (the namespace and MADD constructor renames, the
`.umulh`/`.smaddl` code arms, the MADD/MSUB/UMULL/UDIV/UMULH/
UMADDL generated value-arm repaints including the two
UMULH-ladder repaints, the import/open renames, the
self- and externally-consumed `arm64MulUmulhNatAlg`/
`arm64MulUmulhAlg`/`arm64MulUmulhLadderEqHighWord`/
`arm64MulSignExt32Spec`/`arm64MulValueSpec` renames, the
MADD/MSUB/UMULL/UDIV/UMULH/SMADDL independent-spec repaints, the
flags/range/dispatch renames and dispatch-value repaint, and seven
of the eight example repaints), and 15 catch by the host oracle
(the MADD/UDIV/SMADDL opcode asserts, the UDIV case arm, both
UMULH case/final repaints, the coverage-assert text repaint, and
the eight oracle arms MADD/MSUB/UMADDL/UDIV/UMULH/SMADDL/MUL
repaints). 19 rows survive as documented equivalences: the ten
unreachable generator error-message repaints (spec, order x2,
macros, opcodes, no-defines, drift, flags, no-NZCV, stale), the
unused `mnemonic` string repaint, the whitespace-only generated
arm edit, the coverage assert repainted onto another family
opcode (the predicate is true for every member), the
not-externally-consumed `arm64_mul_flags_unchanged` and
`arm64_mul_code_in_range` renames, the unsupported-probe code
repaint (8U reaches the same default/`UNSUPPORTED` arm as 9U), the
two OK/FAIL message repaints, and the randomized-sweep LCG seed
bump (the sweep is seeded randomness, not an oracle).

### Step 0209 — AArch64 vector register mutation coverage

The `arm64_vreg` contract (`arm64_vreg_spec.json` 45 lines,
`generate_arm64_vreg_spec.py` 291 lines,
`generated/arm64_vreg.h` 87 lines,
`KProgFormal/GeneratedArm64Vreg.lean` 62 lines,
`KProgFormal/Arm64Vreg.lean` 104 lines,
`test_arm64_vreg_host.c` 546 lines) pins how the four vector
memory-transfer opcodes (`ARM64_OP_LOAD_D0` 0x28, `LOAD_Q0` 0x2a,
`STORE_D0` 0x29, `STORE_Q0` 0x2b) map onto the simulator's two
64-bit vector-register state fields: `__a64_v0` is the low half at
slot offset 0 and `__a64_v0_hi` is the high half at slot offset 8,
a `.D0` transfer touches the low half only, a `.Q0` transfer
touches the low half and then the high half, and the two halves
are distinct slots. The spec is an exact-match dict (selector,
state fields, offsets, and the four-opcode table with
define/code/codeIndex/access/halves columns) re-checked per
column, for duplicate defines, offset agreement, half-aliasing,
and the state-field names against
`../arm64/arm64_sim_local_bpf.h`; the generator re-renders the
generated Lean module and C header with byte-for-byte `--check`.
The generated Lean module spans the four `Op` constructors plus
the `Access`/`Half`/`Halves` codomain types, the per-opcode
`access`/`halves`/`armIndex` selectors, `halfCount`, `halfOffset`,
and the per-opcode ordered `plan`. The generated C header pins
each opcode code with a static assert, the `HANDLED` cover, the
slot offsets plus the alias assert, the `HALF_LOW`/`HALF_HIGH`/
`ACCESS_*` codes, the half-offset macro, per-opcode
`ACCESS`/`HALVES`/`INDEX`/`SELECT(N)` macros, and the four-way
`INDEX` chain. The hand module restates the four ordered half
plans independently (`arm64VregPlanSpec`), builds the transfer
list, proves the plan refinement and half-count refinement by
`cases <;> rfl`, the access dispatch, the half plans, the
distinct-slot and `.Q0`-distinct-halves facts, the arm-index
dispatch, and the low and high half slot-offset examples. The host
oracle drives the `SELECT`/`HALF_OFFSET`/`INDEX`/`ACCESS`/`HALVES`
selectors against a full reimplementation of all four transfer
bodies over a pristine register file, memory, tags, and stack
(9216 cases).

`build/mut_arm64_vreg.py` (57 rows) perturbs the six files with the
three detectors: 6 catch at the generator stage (the `loadD0` code
row and the two slot offsets in the spec, plus the half-plan
table, the two-half C selector text, and the `__a64_v0` state-field
driver repaints), 26 catch through the Lean chain (the namespace,
the `loadD0` constructor rename, every `access`/`halves`/
`halfCount`/`halfOffset`/`plan`/`armIndex` arm repaint on the
generated side, and on the hand side the `open` member repaint, the
`arm64VregPlanSpec` and `arm64VregTransferList` renames, the plan
d0/q0 repaints, every consumed-goal repaint: refinement, half
count, access dispatch, half plan, distinct halves, `.Q0` get
arms, arm-index dispatch, and both slot-offset examples), and 15
catch by the host oracle (the `loadD0`/`storeQ0` opcode asserts,
both slot offsets, the `LOAD_D0` select low-half repaint, the
`STORE_Q0` select arm swap, the access and half-count repaints,
the `LOAD_D0` index repaint, the oracle's selector, half-offset,
index, access, and halves macro renames). 10 rows survive as
documented equivalences: seven unreachable generator error-message
repaints (spec, column, duplicate, offsets, alias, state drift,
stale), the internally-consistent low-half-index repaint (`HALF_LOW`
0U to 2U; the macro feeds only its own comparisons and the
`HALF_OFFSET` ternary, so macro and oracle repaint symmetrically),
and the two host OK/FAIL message repaints.

### Step 0208 — AArch64 source modifier mutation coverage

The `arm64_mod` contract (`arm64_mod_spec.json` 1 line,
`generate_arm64_mod_spec.py` 228 lines,
`generated/arm64_mod.h` 112 lines,
`KProgFormal/GeneratedArm64Mod.lean` 25 lines,
`KProgFormal/Arm64Mod.lean` 160 lines,
`test_arm64_mod_host.c` 188 lines) pins the eleven-arm AArch64
source-modifier value the simulator applies through
`ARM64_SIM_L_MOD_VALUE` before an ALU step: the identity arm plus
shift (LSL/LSR/ASR), rotate (ROR), and extend
(UXTW/SXTW/UXTH/SXTH/UXTB/SXTB) arms, with the shift amount `k`
masked to the width (`& 31` on `w32`, `& 63` otherwise) and the
extend arms applying the raw shift field exactly like the C macro.
The spec is an exact-match dict verified byte-for-byte (schema,
operation, and the eleven operations in
`none/lsl/lsr/asr/ror/uxtw/sxtw/uxth/sxth/uxtb/sxtb` order with
codes 0..10 and per-arm `lean`/`c` expression strings), re-checked
for order, codes, and code drift against the `mod` table of
`arm64_decode_spec.json`; the generator re-renders the generated
Lean match and the C `switch` macro with byte-for-byte `--check`.
The generated Lean module defines `value` over the
`GeneratedArm64ModDecode (Mod)` codes; the generated C header pins
the 11 `ARM64_MOD_*` codes with static asserts, defines the total
`KPROG_ARM64_MOD_HANDLED` cover and the eleven-arm
`KPROG_ARM64_MOD_VALUE` statement expression. The hand module
restates all eleven arms independently (`arm64ModValueSpec`:
narrow/shift/rotate, masked complement-and-subtract sign extension,
truncation shift pairs), proves the refinement by
`cases <;> bv_decide`, the code-range theorem (`code mod < 11` by
`decide`), the code dispatch equalities, the `__u8` shift-vector
magnitude lemma, the `shift &&& 0x3f` amount-masking quartet, the
extend-shift refinement over the `arm64ModShiftOfByte` image, the
fed-ALU composition through `GeneratedArm64AluResult.result .add`
and `arm64_alu_result_refines`, and six canonical examples
(UXTB/SXTB/SXTW boundary values, the LSL w32/w64 shift masking, the
ROR byte rotation, the identity arm) by `native_decide`. The host
oracle drives `KPROG_ARM64_MOD_VALUE` against an independent
plain-C oracle over the 15 boundary vectors x 11 modifiers x 8
shifts x 4 widths plus a 20000-iteration fixed-seed LCG sweep
(extends restricted to shift < 64) and the HANDLED membership
checks (225292 cases).

`build/mut_arm64_mod.py` (60 rows) perturbs the six files with the
three detectors: 8 catch at the generator stage (the spec row
repaint, the expected-dict, order, code, and decode-table check
repaints, the rendered Lean arm and C separator repaints, and the
masked-amount repaints on both render sides), 24 catch through the
Lean chain (the namespace, every generated and hand modifier arm,
the let-k masks, the consumed `arm64ModValueSpec`/
`arm64_mod_refines` renames, the refinement/range/dispatch goal
repaints, every boundary-example repaint, the shift magnitude
repaint, and the internally-consumed `arm64ModShiftOfByte` rename),
and 11 catch by the host oracle (the code asserts, the handled
cover, the value macro rename, the case-10 repaint, the extend
cast, and the model LSL/LSR/NONE/UXTB repaints). 17 rows survive as
documented equivalences: six unreachable generator error-message
repaints, the header-guard repaint, five consumers-free hand
theorem renames (code-in-range, code dispatch, masked quartet,
extend refinement, fed-ALU), and five all-equal-oracle input-side
repaints (the shift classifier and LCG seed/stream change inputs
fed symmetrically to macro and oracle, and the OK/FAIL message
repaints).

### Step 0207 — AArch64 register dispatch mutation coverage

The `arm64_reg_dispatch` contract (`arm64_reg_dispatch_spec.json` 39
lines, `generate_arm64_reg_dispatch_spec.py` 153 lines,
`generated/arm64_reg_dispatch.h` 60 lines,
`KProgFormal/GeneratedArm64RegDispatch.lean` 27 lines,
`KProgFormal/Arm64RegDispatch.lean` 167 lines,
`test_arm64_reg_dispatch_host.c` 106 lines) pins the
register-number -> dispatch-cell binding: the 31 general-purpose
registers are the register numbers `0 .. 30`, in `x0 .. x30` order,
so the `ARM64_SIM_L_FOR_EACH_GPR` dispatch cell index equals the
register number, and the zero register (`31`, the stack pointer
`32`, the no-register sentinel `0xff`) are not dispatch cells. The
spec is an exact-match dict verified byte-for-byte (schema,
operation, `reg_bits`, `gpr_count`, and the 31 `x{n}` -> `n` cells),
re-checked for cell order, cell numbers, and cell-count/gpr_count
agreement; the generator re-renders the generated Lean module and C
header with byte-for-byte `--check`. The generated side carries
`gprCount`/`regBits`, the `cellNumbers`/`cellNames` tables, the
`cellOf` selector, the inverse `numberOfName`/`nameOfNumber` lookups,
and the C macros `KPROG_ARM64_GPR_COUNT`/`KPROG_ARM64_GPR_CELL` with
31 `ARM64_X<n>` static-assert drift checks. The hand module restates
the tables against independent `List.finRange` constructions
and proves the lengths, `Nodup`, the `cellOf` literal-bound
equivalence, the x0/x30/zero/stack-pointer/sentinel boundary
examples, the full-range round trip, the name<->number round trips,
and the cross-contract agreements with the register-presence and
memory-index contracts (`gprCount = xzrNumber`, dispatch none ⇔
presence discard, sentinel shared), plus the dispatch-subset-of-
writable classification proofs. The host oracle recompiles with the
macros and compares `KPROG_ARM64_GPR_CELL` against the identity
binding over the full byte range (257 cases).

`build/mut_arm64_reg_dispatch.py` (71 rows) perturbs the six files
with the three detectors: 21 catch at the generator stage (the spec
bit/count/cell/operation/schema drifts, the expected-dict and
order/numbers/length check repaints, and the rendered
cellNumbers/cellNames/cellOf/lookup table and C macro repaints), 30
catch through the Lean chain (the generated count/tables/cellOf/
lookup repaints; the hand spec-def repaints consumed by the refine
theorems, the length-bound weakenings, the `Nodup ∧ False` repaint,
the bits-is-8 flip, every boundary-goal repaint, the full-range and
round-trip-goal repaints, and the cross-contract goal repaints), and
5 catch by the host oracle (the model-cell and got/want repaints, the
count-vs-31 repaint, and the include repaint). 15 rows survive as
documented equivalences: five unreachable generator error-message
repaints, the header-guard repaint, six consumers-free hand theorem
renames, the `Eq.refl _` proof-term swap for the sentinel-equality
theorem, and the OK/FAIL message repaints.

### Step 0206 — AArch64 pre/post writeback mutation coverage

The `arm64_mem_prepost` contract (`arm64_mem_prepost_spec.json` 1
line, `generate_arm64_mem_prepost_spec.py` 178 lines,
`generated/arm64_mem_prepost.h` 43 lines,
`KProgFormal/GeneratedArm64MemPrepost.lean` 40 lines,
`KProgFormal/Arm64MemPrepost.lean` 103 lines,
`test_arm64_mem_prepost_host.c` 184 lines) pins the
pre/post-indexed address-writeback decode: the packed memory-flag
byte of an `ARM64_AUX_MEM` operand is its top byte (`>> 24`, mask
255); `MEM_PRE` (bit 1) applies the immediate before the access and
`MEM_POST` (bit 2) after it as independent facts (both set applies the
same immediate twice), an offset access contributes the immediate in
the address offset, so the offset suppresses the immediate exactly
when either bit is set; each macro evaluates the flag byte once and
writes no NZCV. The spec is an exact-match dict verified byte-for-byte
plus an `ARM64_MEM_PRE`/`MEM_POST` drift cross-check against
`kprog/arm64/arm64_sim.h`; the generator re-renders the whole
generated Lean module and C header with byte-for-byte `--check`. The
generated side carries the top-byte `flags` decode, the
`preWriteback`/`postWriteback` gates, `suppressOffset`,
`preDelta`/`postDelta`, the independent raw-flag statements
`preDeltaSpec`/`postDeltaSpec`/`suppressOffsetSpec`/
`writebackFormSpec`, and the four `KPROG_ARM64_MEM_PREPOST_*` C
macros with their PRE/POST static asserts. The hand module restates
the flag byte as the `(aux.toNat >>> 24) &&& 255` decode, proves the
gate equalities by `rfl` and `simp`, the delta refinements by
`exact ⟨rfl, rfl⟩`, the form-ordinal sum by `rfl` and its bound by
`split <;> split <;> omega`, and three canonical examples (offset 0,
post 2, both 3) by `decide`. The host oracle compares the macros with
an independent model in two parts: constants against literals and
ARM64_MEM_PRE/MEM_POST, then the full decode/select sweep over every
flag byte 0-255, three low-byte noise words, and six immediates
(4608 cases).

`build/mut_arm64_mem_prepost.py` (59 rows) perturbs the six files
with the three detectors: 21 catch at the generator stage (the spec
bit/shift/mask/selector/operation/schema drifts, the expected-dict
selector drift, and the PRE/POST constant, rendered gate/delta/
suppress template, and C macro repaints), 20 catch through the Lean
chain (the namespace, flags decode, gate bodies, suppress, deltas,
and spec-statement repaints; the hand open-line rename, the
flags gate/bound/delta goal repaints, and the three example-goal
repaints), and 5 catch by the host oracle (the include repaint, the
model top-byte/pre/post/suppress repaints). 13 rows survive as
documented equivalences: five unreachable generator error-message
repaints, the header-guard repaint, the consumers-free
`suppressOffsetSpec` (no module reads it) and hand `flags_refines`
theorem renames, the weaker form-bound `≤ 2` to `≤ 3` repaint (the
weaker statement stays omega-provable), the low-byte noise 0x5a to
0x5b and immediate 0x1000 to 0x1001 drifts (every case's verdict is
re-derived identically from the repainted inputs), and the OK/FAILED
message repaints.

The ABI-load model still abstracts away base-register identity, width checks,
and memory-boundary checks.
