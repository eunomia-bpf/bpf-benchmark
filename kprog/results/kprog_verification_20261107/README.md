# Lane V verification checkpoint

Published source increments retain the previous theorems and semantic oracles.
This checkpoint archives the results before removing finished private exports,
scratch probes, raw output and private Git indexes. Shared Lean/Cargo caches are
retained; no clean rebuild is required.

| Published increment | Validation observed |
| --- | --- |
| `1b114d3e45c83fd8ac41814a4e0f3758df2342c7` classic ROR | Full `make check` exit 0 |
| `0f118e0e606e94240ede73a6ebec30f79e2cde99` MULX | Full `make check` exit 0 |
| `6d84c21c37ef24d824567cf7ee3cf612c1e35472` SHLD/SHRD | Full `make check` exit 0; undefined destination bits are relationally masked |
| `5e2dc9999fb2a3e4b163d8fe36da705875a460b1` XMM0 | Full `make check` exit 0; 2176 CPU cases, 32 actual faults, 128 GNU encodings and 8872 reference states |
| `590894d60723243b8363e420ef954c90c5c476b5` REP MOVS | Exact published full `make check` exit 0; 1120 CPU cases, 64 restart faults and 1774 reference states |
| `0fb9f53597ae49a1e36aca118afa6e30ac32e507` near CALL/RET | All Lean modules built; 440 CPU cases and 1279 reference states including four CALL/RET paths; existing REP, XMM, conditions, paths and ARM reference regressions passed |
| `d495572d3b9124d7b9ac9116f2145ef6e9a55883` named-map fixture | Focused exit 0; all 90 ARRAY/PERCPU_ARRAY full-state paths and four named direct-call targets retained; two opaque-map controls retain the generic helper target |
| `X86RegWrite.lean` projected byte-MOV lemmas in this commit | Incremental `lake build KProgFormal.X86RegWrite` exit 0 |

`call-cpu.jsonl.gz` retains the final 440 native CPU observations. The focused
CALL/RET run v7 explicitly built all Lean modules; v8 verified identical Lean
source hashes and strengthened page-fault read/write/fetch-bit and fault-address
checks. Both exited 0. Earlier failed proof scripts were proof elaboration
failures, not discarded native inputs. The semantic failure found during this
work is retained in `call-fault-priority.json.gz`: CALL to a noncanonical target
with an inaccessible stack faults on the stack access first. The corrected
canonical step and final CPU suite enforce this ordering.

The map fixture's first attempts exposed lost identity through a non-PIC LEA,
then the intentional raw-ELF proof-ABI rejection, and finally the loader's zero
MOVABS relocation placeholder. The published fixture uses legitimate proof-mode
normalization with PIC/GOT identity and applies the typed map-pointer patches;
it bypasses no production check and changes no production selector.

The two projected byte-MOV lemmas preserve prior useful proof work; they do not
enable a link-time optimization. Those optimizations are deferred by the current
operator priorities.

The combined post-cleanup full check at exact `aacc36597` exited 2: three
modules importing both X86RegWrite and X86ShiftResult encountered duplicate
`GeneratedX86Width.Width.enumToBitVec` definitions. The forward fix preserves
the MOV theorem statement and exposes its constant-width bit-vector goal before
`bv_decide`. All three affected import compositions then passed an incremental
81-job focused build. A new combined full check is required after publication.
None of the
focused results above establishes all 77/72 handler refinements or a complete
dispatcher-step theorem. XMM C lane projection still assumes successful aligned
access; REP C core assumes bounded matching count, forward/default addressing
and successful accesses. CALL/RET internal core lifts require materialized native
addresses and access/canonicality witnesses; helper and outer-invocation
certificates remain separate. The CPU profile is trusted environment data:
48/57-bit paging with CET disabled, not authority supplied by an application.

The subsequent ARM exclusive core increment composes generated LDAXR-width reads,
STLXR-width stores and W-status writes with the same canonical monitor semantics.
Load refinement includes native access faults after explicit SP/natural alignment
witnesses. Store refinement includes either externally supplied failure-bit
outcome, source/status aliases, and preservation of all other state. Its failure
preflight condition permits inaccessible memory when the architecture does not
check it. The success/failure bit must equal the canonical monitor/commit result;
monitor state and acquire/release/conditional-commit events are explicit ghost
annotations requiring a platform witness, not implemented C monitor guards or a
proof of hardware atomicity. The new proof and the three x86 import-composition
regressions passed; existing exclusive wire checks passed 82 complete-state,
effect and fault cases and 10 encoding/input rejections. One early proof attempt
failed on redundant record updates in the failure arm; restructuring that arm
removed the redundant update without weakening any theorem or filtering inputs.

## Published whole-check result

Exact `6e64f4a3e91b407c4ee5ce46c581080b9e667c27` completed
`make -C kprog/formal check` with exit **0**. The immutable export included the
CALL/RET, named-map fixture, import-composition fix and exclusive-core proofs;
all Lean modules, reference regressions, generated contracts, compiler/wire
checks and existing C semantic/route hosts passed. The final existing ARM stack
arena route host checked 2,814,832 cases and the decode host 1,410 cases.
The temporary source/cache export was deleted immediately. Its obsolete raw
outputs are removed after this summary is committed; shared incremental caches
are retained. The compressed CALL CPU observations now come from this successful
whole-check run rather than the earlier focused v8 run. Later source changes
require their own validation; this result does not include the subsequent D0
full-state proof work or other lanes' uncommitted runtime changes.

## D0 handler and native pointer-read increment

The concurrent V continuation published `b1cc1a232` (native pointer-read fix and
compiler regression) and `ce776d453` (D0 full-state/index and two singleton-arm
composition). The local continuation verified the same source bytes and keeps
those commits. This follow-up enables UBSan on the two existing real DQ/vector
route hosts and lets Clang's actual target definitions select the BPF path; no
synthetic `__BPF__` definition is needed. A duplicate pointer-check recipe added
by the overlapping continuations was removed before publication.

Validation: incremental Lean/reference build passed; 959 addressed/vector
complete-state cases and 18 precise rejects passed. Existing real DQ and vector
route hosts passed 62,418 and 62,445 cases with UBSan. The new primitive check
passed 512 native reads covering every alignment, and six actual compiled BPF
functions retained exactly one 8-byte read at the required address, including
literal context offset88, negative offsets, signed16 limits and the large-offset
path. Existing simple_packet and cilium_ct_nat_tuple_rewrite ARM micro programs
compiled successfully with the production BPF flags.

The original pointer macro had C alignment/effective-type UB on unaligned ABI
reads. Alignment1 alone was rejected: it fixed host UB but compiled into eight
reordered byte reads. The final primitive keeps an exact-width typed BPF read
and preserves literal context displacements; the host branch uses an aligned1,
may_alias pointer type. `arm64-pointer-counterexamples.json.gz` retains the
failing primitive and numeric byte-access counterexample. No inputs, sanitizer
checks or architectural effects were removed to obtain passing results.

D0 proofs currently cover V0 native8B loads/stores without writeback, including
immediate and extended/scaled register offsets, exact effects/faults and all
other state preservation under the explicit SP-alignment witness. The checked
memory branches introduce no new C runtime permission guards. Pre/post writeback
and Q16B versus two8B effect composition remain separate obligations; these two
singleton arms are not the complete72-operation dispatcher theorem.

The interrupted V continuation also left a validated base-update draft. Its
SP/GPR/zero-delta cases are now retained in Arm64VectorMemory. The universal
`bump_refines` theorem connects the actual numeric update branches to canonical
base writeback, and `writeback_base_refines` composes the generated pre/post
deltas for all three modes. Incremental Lean build passed (27 dependency jobs).
This preserves the draft's useful proof work; it proves base-update algebra,
not the outstanding intervening-memory/fault composition for a complete
pre/post-indexed D0 handler.

Exact `ef02edb2f7ced694a25efe0bc05f148d0e503f21` subsequently completed
`make -C kprog/formal check` with exit **0**, including the D0/index/singleton
proofs, writeback base algebra, native-pointer compiler regression and both
existing DQ/vector route suites under UBSan. All other Lean modules, generated
contracts, reference/wire/compiler checks and C semantic hosts also passed.
The immutable source/cache export was deleted immediately. The compressed CALL
CPU observations have been refreshed to this successful full run. This result
precedes the subsequent full D0 pre/access/post transfer composition work.

## D0 pre/access/post transfer composition

Arm64VectorMemory now composes the generated pre-delta, actual eight-byte D0
transfer and post-delta in C-body order for offset, pre-index and post-index
modes. `d_writeback_refines` proves complete numeric state and ordered effects
against the existing single AArch64 reference. `dispatch_d_success_refines`
composes the two production singleton predicates with that theorem; every other
singleton is left to its own arm. These are two dispatcher arms, not a complete
72-operation simulator-step theorem.

The theorem explicitly requires the actual eight-byte access to be permitted
and the original incoming SP alignment check to pass. It does not impose
alignment on the updated SP or extra natural alignment on ordinary D memory.
Loads clear V0's high half, stores preserve vectors, and all other registers,
flags, memory properties, monitor/environment fields and PC behavior are kept.
The core contains no fabricated runtime permission guard. Materialized numeric
values and their tag/address transport remain Entry/O4 obligations; unsuccessful
pre/post accesses and Q16B/two8B effect composition are not silently identified.

Validation: the complete incremental Lean dependency build passed (36 jobs),
plus the existing 959 addressed/vector full-state cases and 18 precise rejects.
Early failed proof attempts involved record syntax and simplifier/if-case glue;
no reference semantics, theorem premise or native test input was weakened or
filtered. Every previous D0/Q/base-update theorem remains unchanged.

Exact `68c78982090f7c9153803ffa03c8d39f9bb6f84b` completed the full
`make -C kprog/formal check` with exit **0**, including the D0 pre/access/post
success and dispatcher-arm proofs above, every previous Lean theorem and the
existing generated, reference, compiler, wire and C semantic checks. The private
immutable source/cache export was deleted automatically. The compressed CALL
CPU observations now retain this successful full run; shared incremental caches
remain intact. Subsequent scalar-writeback work requires separate validation.

## Scalar pre/access/post transfer composition

`Refinement/Arm64WritebackMemory.lean` composes the generated pre-delta,
byte-width load/store primitives, load narrowing/sign extension, register
write and generated post-delta in actual body order. `core_refines` proves
complete numeric state and exact ordered byte effects against the existing
`AArch64.step (.addressedMemory ...)` for all immediate modes and widths.
The canonical instruction's existing `noOverlap` proof discharges writeback
alias restrictions; no extra restriction is imposed on no-writeback aliases.
`indexed_refines` also composes generated UXTW/SXTW/LSL/SXTX modifiers, all
four scalar scales and ZR indexes before access, allowing a load to overwrite
its own base or index. LOAD and STORE singleton predicates are composed with
the same core theorem; signed loads retain their explicit signed destination
parameter and are not mislabeled as unsigned LOAD dispatch.

The numeric core contains no invented permission/alignment guard. Refinement
requires successful access at the computed native address and alignment of the
original incoming SP. Faulting writeback paths and tag/address transport remain
separate Entry/O4 obligations. No Q16B/two8B trace abstraction or new reference
specification is introduced, and no complete 72-operation dispatcher is claimed.
Every prior theorem and semantic oracle is retained; runtime source is unchanged.

Validation: incremental Lean/reference dependency build passed (37 jobs), the
existing addressed/vector reference suite passed 959 complete-state cases and
18 precise rejects, and the existing actual pre/post route host passed 135,170
cases. Early attempts failed on dependent record syntax and proof rewriting;
no architectural input was filtered and no reference/premise was weakened.
The full check of this increment is run separately after publication.

## Signed-load operation and dispatcher composition

`Arm64WritebackMemory` now pins the generated LDRSB/LDRSH/LDRSW operation codes
to both their native memory widths and their independently selected
SXTB/SXTH/SXTW operations. `signedSuccess` explicitly composes the generated
load ladder, selected shared sign extension and destination-width write.
`signed_core_refines` lifts that transfer in actual pre/access/post order;
`dispatch_signed_refines` composes all three numeric family case labels.
`signed_indexed_refines` and its dispatcher theorem retain the generated
register modifiers and scalar scales for no-writeback forms, including legal
base/destination/index aliases. Other opcode numbers return no result for this
arm, preserving the rest of the dispatcher.

The same canonical instruction, writeback-alias validity, original-SP alignment
and successful-memory witnesses are used. The pipeline retains the independent
W/X destination parameter; native-byte decoding must establish the valid source
form and its flags (including X destination for LDRSW). Materialization,
provenance and Entry/O4 bindings remain separate. This increment changes no
runtime source, claims no faulting-writeback correspondence or complete
72-operation dispatcher theorem, and preserves every previous theorem verbatim.

Validation: 40 Lean/reference dependency jobs passed; the existing addressed
reference suite passed 959 full-state cases and 18 precise rejects. Both existing
LDRSX generated-contract freshness checks passed. The two existing scalar
contract hosts each passed 256 cases; the actual LDRSX route host passed
2,315,529 cases and the actual sign-selector route host passed 98,197 cases.
An initial proof failed only to reduce an Option.map application before rewriting;
explicitly exposing that application fixed it without changing any premise,
reference behavior or test input. Exact `ad409c6de` full validation was still
running separately when this increment was published.

Exact `ad409c6deaf6cae900d62b01d8401f86f48122d0` subsequently completed
`make -C kprog/formal check` with exit **0**, including the scalar actual-order,
indexed and LOAD/STORE singleton-arm proofs. All previous Lean modules,
generated contracts, reference/wire/compiler checks and C semantic hosts also
passed. The private immutable source/cache export was deleted automatically;
compressed CALL CPU observations now retain this full run. This result precedes
the signed-load selector increment `f112d2fb8` and the subsequent pair-body work,
which require their own full validation.

## Pair pre/access/post transfer composition

`pairSuccess` composes generated pair direction, scalar load/store primitives,
width-dependent element stride and register writes for W/X LDP/STP. Both native
addresses are captured before writes, both ordered element effects are retained,
and the final PC advances once. `pair_core_refines` composes this with the actual
generated pre/access/post base-update order, equating the complete numeric state
and events to the same canonical addressed-pair step. `dispatch_pair_refines`
composes the LDP/STP singleton predicates with the matching decoded direction;
other singleton opcodes return no result for this slice.

The explicit `pairSingleAccess = false` environment witness selects the two-access
profile. The theorem also requires original-SP alignment and permission for each
element. Existing canonical pair validity supplies distinct load destinations and
writeback-base non-overlap; stores may repeat their source, and no-writeback forms
retain legal base/destination aliases. No permission guard or fault rollback is
invented in the C body. The model is sequential: no single-copy atomicity, faulting
pre/post correspondence, Q16B event merge or Entry/O4 transport is inferred.
All previous scalar, signed-load and other theorems remain unchanged.

Validation: 40 Lean/reference dependency jobs passed, plus the existing 959
addressed/vector full-state cases and 18 precise rejects. The pair contract
freshness check passed. Existing pair semantics, actual pair-route and actual
pre/post-route hosts passed 465,696, 165,895 and 135,170 cases respectively.
Early proof attempts exposed only rewrite order, record layout and transition
eta-expansion obligations; the final proof retains every original architectural
input and premise. Runtime and oracle source are unchanged. A new immutable full
check is queued for this published increment together with the signed-load work.

Exact `0afcda79cb766709a5896f7aea07779a0e12c340` completed the full
`make -C kprog/formal check` with exit **0**, including the signed-load selector
and pair actual-order/dispatcher increments. All prior Lean modules, generated
contracts, reference/wire/compiler checks and C semantic hosts also passed.
The private immutable source/cache export was deleted automatically; compressed
CALL CPU observations now retain this successful full run. The subsequent
FMOV/reduction raw-field dispatcher work requires its own full validation.

## FMOV and reduction dispatcher tail

`Arm64Fmov.rawStep` exposes the actual generated value/destination selectors,
S_FROM_W truncation, vector-high clearing and independently supplied GPR/ZR
fields and destination width. `raw_step_refines` relates every native direction
to the existing banked FMOV reference. Numeric singleton and AUX decoding then
compose with all32 vector-bank indices and the legacy NONE=255→V0 mapping.
The existing guard is retained for invalid bank or direction fields.

`Arm64Reduction.dispatch` binds opcode36/37 to the generated CNT/UADDLV
primitive and the actual AUX==16 high-half selector. `dispatchTail` composes
the production FMOV-first, reduction-next order and proves each of the three
operation arms against the same canonical full-state step, including legacy
FMOV. Unrelated opcodes return no result for this slice, preserving the rest
of the dispatcher. Reduction ignores the unused FMOV fields exactly as the
production chain does.

This is a numeric projection for well-formed generated input fields. Native
byte decoding and Entry/O4 must bind live GPR/ZR representations, the bounded
vector-selector field, valid direction/arrangement and FMOV width flags; these
are not application-supplied authority. No runtime, oracle or ISA-specification
source changed. Every earlier FMOV/reduction theorem remains byte-identical.
The tail is not a complete72-operation dispatcher or compiled-artifact proof.

Validation: 27 Lean/reference dependency jobs passed. Existing AArch64 reference
regressions passed, including 3860 internal-control/PC-address complete-state
cases, plus 959 addressed/vector states and 18 precise rejects. All three
related generated-contract freshness checks passed. Existing FMOV value,
FMOV destination and reduction semantic hosts passed 20,145, 256 and 20,017
cases; actual FMOV and two reduction route hosts passed 127,016, 11,223 and
21 cases. The FMOV route suite includes all32 banks, NONE and invalid bank
controls. A new immutable full check follows publication; exact0afcda79c's
successful full result above precedes this increment.

## BITFIELD packed fields and dispatcher

`Arm64Bitfield.packed_fields` composes the existing generated AUX packer and
byte extractors: the five operation codes, LSB and bit count round-trip without
interference from one another or the unused high byte. `rawStep` consumes those
actual fields through the generated bitfield value and width-specific register
write. `dispatch_refines` composes numeric opcode18, kind decoding and the old
full-state theorem against the same canonical ISA. Invalid kind bytes and other
operation codes retain the unsupported/no-result branch.

The existing typed native instruction supplies field bounds; no runtime bounds
guard is inserted. W/X narrowing, GPR/ZR and source/destination aliases preserve
the same complete numeric state and empty effects. Native byte/operand/flag and
Entry/O4 transport remain separate. Only the five currently implemented aliases
are covered; no extra ISA operation or compiled-artifact certificate is invented.
Every prior theorem remains unchanged.

Validation: 28 Lean/reference dependency jobs passed, plus the existing reference
regressions including 3860 control/PC-address states and 959 addressed/vector
states with 18 precise rejects. Four generated-contract freshness checks passed.
Existing independent bitfield semantics checked 126,246 cases; actual AUX and
singleton route hosts checked 1,115,374 and 11,083 cases. Initial proof attempts
failed on argument parentheses and a free-variable decide goal; explicit field
proofs fixed these without changing any premise or filtering inputs. Current
combined full validation is recorded separately from the earlier tail source.

Exact `6ded5f0d5a497b7fe511cd8fe7139103d663f854` completed
`make -C kprog/formal check` with exit **0**, including FMOV/CNT/UADDLV raw
fields and the concrete dispatcher tail, plus all prior Lean modules, generated
contracts, reference/wire/compiler checks and C semantic hosts. The immutable
source/cache export was deleted automatically; compressed CALL CPU observations
now retain this successful full run. Subsequent packed BITFIELD/MOVK work needs
its own full validation.

## MOVK packed column and dispatcher

`Arm64Movk.packed_column` binds AUX byte2 to the actual 0/16/32/48 bit column,
independently of all three unused bytes. `decodeShift` reflects the production
switch exactly; an invalid shift returns no result instead of taking the old
bounded helper's default column48. `dispatch_refines` composes numeric opcode5,
column decoding, generated insertion and width-specific destination write with
the same canonical MOVK step. The typed native instruction admits only the
legal two W columns or four X columns, preserving every complementary bit and
W zero extension. Other opcodes retain their own dispatcher arms.

These are source-validity and numeric-state proofs, with no extra runtime guard,
ISA operation, oracle, test or compiler policy. Native byte/operand/width and
Entry/O4 bindings remain separate; every previous MOVK theorem is unchanged.

Validation: 31 Lean/reference dependency jobs passed together with the new
BITFIELD module and existing AArch64 reference regressions, including 3860
control/PC-address states. Three related generated-contract freshness checks
passed. Existing independent MOVK semantics checked 20,145 cases; actual AUX
and singleton route hosts checked 1,115,374 and 11,083 cases. All checks passed
without failures or input filtering. A new immutable combined full check follows
publication of this increment; exact6ded5f0d5's full result precedes it.

Exact `db3066318d7b5a6d6ebda69ee7b47292624d9f43` completed
`make -C kprog/formal check` with exit **0**, including packed BITFIELD/MOVK
fields and dispatcher refinements, all earlier Lean modules, generated contracts,
reference/wire/compiler checks and C semantic hosts. The immutable source/cache
export was deleted automatically; compressed CALL CPU observations now retain
this full run. Subsequent SHIFT field/operand composition is a separate increment
requiring its own full validation.

## SHIFT immediate/register fields and dispatcher

`Arm64Shift.decodeOpcode` binds the real numeric SHIFT_IMM/SHIFT_REG case labels
to the generated operand-source table. `decoded_operand` proves both the same
numeric code and the same immediate/register decision across the two generated
tables. The low AUX byte independently selects LSL/LSR/ASR/ROR; all three unused
bytes leave that selection unchanged. `rawStep` then selects the count, reads
the incoming source, invokes the generated width-aware shift and writes the
result before advancing PC once.

`dispatch_immediate_refines` and `dispatch_register_refines` compose those fields
with the existing canonical full-state step for both W/X widths, all four
shift kinds and legal aliases. Immediate forms ignore the count-register value;
register forms ignore the immediate and retain architectural count masking.
Typed native immediate bounds are explicit. Invalid kind bytes and unrelated
opcodes return no result for this slice, including other families with their
own immediate-selection rule. All previous unary and shift theorems remain
unchanged; this increment covers SHIFT_IMM/REG, not an invented all-opcode theorem.
Native byte/operand/width and Entry/O4 transport remain separate obligations.

Validation: 37 Lean/reference dependency jobs passed, including the existing
AArch64 reference regressions with 3860 control/PC-address states. Five related
contract freshness checks passed. Existing independent shift, operand-selection
and family hosts checked 20,513, 5,120 and 2,072 cases; actual operand, family and
AUX route hosts checked 3,804, 136 and 1,115,374 cases. There were no proof/test
failures or input filtering. Runtime, oracle, test and ISA source are unchanged;
T's appended public x86 decode lemma was preserved. A new immutable full check
follows publication; exactdb3066318's successful full result precedes this work.

## MVN/NEG packed modifiers and dispatcher

`Arm64Shift.Unary` connects actual numeric15/16 labels, AUX byte1 source
modifier, byte2 count, generated unary value and width write to the existing
canonical full-state MVN/NEG steps. MVN covers four shift kinds; NEG retains
the architectural three-kind restriction. Native amount bounds, W/X widths,
GPR/ZR and source/destination aliases remain explicit. The identity modifier
composes to the same canonical zero-shift instruction for any unused count
byte. Both other AUX bytes are independent, and unrelated opcodes stay outside
this slice. No flags, memory or extra effects are introduced; PC advances once.

This native-form lift does not reclassify generated extension modifiers as C
rejections: those modifiers remain implemented by the shared primitive for other
families, outside these MVN/NEG native forms. No runtime, oracle, test, compiler
policy or ISA specification changed. Native decoding, typed operand/width and
Entry/O4 transport remain separate; this is not the complete72 dispatcher or a
compiled-artifact certificate. All earlier theorem source remains unchanged.

Validation: 28 Lean dependency jobs passed, followed by the focused reference
build and existing reference regressions, including 3860 AArch64 control/PC
complete states. Four contract freshness checks passed. Existing unary/modifier
semantic hosts passed 40,081 and 225,292 cases; actual unary/AUX/decode hosts
passed 313, 1,115,374 and 1410 cases. Two final identity-to-canonical composition
lemmas also passed the 28-job build. Initial proof attempts exposed parsing,
rewrite and redundant-tactic errors, corrected without weakening premises.
C route builds retain their existing __always_inline redefinition warnings.
Exact1c4a46960 full checking remains queued behind the shared full-check slot;
this increment requires its own full check after publication.

## MOV operand-source and body dispatch

`Arm64Move` now binds numeric MOV_IMM/MOV_REG labels1/2 and the independent
operand-source table to the actual pointer-preserving-first body order.
Full-width register moves read the incoming SP/GPR/ZR and use the full write;
W moves select the scalar register operand and narrow/zero-extend. Immediate
moves select the immediate independently of the supplied source, then perform
the scalar width write. `scalar_destination_write` connects their GPR/ZR field
to the same generated register cells, preserving field31 as ZR rather than SP.
Register moves retain separately typed SP and ZR operands. The immediate is
irrelevant to register moves, and unrelated opcodes cannot enter this slice.

Both dispatcher theorems compose to the existing canonical complete-state steps,
retaining aliases, flags, memory, vectors and ordered empty effects with one PC
advance. All previous theorem source remains unchanged. This is a numeric
projection; Entry/O4 must materialize native SP/address values and bind source
identity, provenance and width flags. It does not prove arbitrary pointer casts,
compiler correctness or the complete72 dispatcher. No runtime, oracle, test,
configuration or ISA specification changed.

Validation: 17 Lean dependency jobs and the focused reference build passed,
including existing reference regressions and 3860 AArch64 control/PC complete
states. All three related contract freshness checks passed. Existing move/operand
semantic, actual operand, register-cell semantic and actual register route hosts
passed 1024, 5120, 3804, 257 and 6401 cases respectively. No proof/test failures or inputs were filtered.
Existing C warnings about inline redefinition, unused host state and potentially
uninitialized non-selected macro arms remain visible. Exact1c4a46960 full check
is running separately; this newer increment awaits its own full validation.

Exact `1c4a46960955370dde5f4d56201f3274a6dbc951` completed the full
`make -C kprog/formal check` with exit **0**, including SHIFT opcode/operand/AUX
composition, all earlier Lean modules, contracts, reference/wire/compiler checks
and semantic hosts. The immutable source/cache export was deleted automatically;
compressed CALL CPU observations retain this successful 440-case full run.
Subsequent MVN/NEG, MOV and multiply-family increments need their own full check.
This result is distinct from the mutable shared-tree CMOV failure owned by F.

## Multiply-family actual input widths and dispatcher

`Arm64Mul.decodeOpcode` now binds all eight actual numeric case labels to the
same generated operations. `rawStep` follows the production body: both inputs
are narrowed to the decoded width only for UDIV; other operations read full
inputs, all read the incoming accumulator, and the result uses the generated
destination-width write. The MUL/UMULL aliases ignore the actual accumulator,
while MADD/MSUB/UMADDL/SMADDL retain it. UMULH retains the full high product;
UDIV retains zero division and W input truncation before division.

`raw_step_refines` and `dispatch_refines` connect every member to the same
canonical full-state step, including source/destination aliases and ZR.
The four long/high members explicitly require their valid native X destination;
this is a decoded-source premise, not an invented C rejection or runtime guard.
Other opcodes remain outside this slice. Registers, flags, vectors, memory,
SP and empty effects are retained, with one PC advance. All old theorem source
is unchanged; no runtime, oracle, test, configuration or ISA source changed.
Native decoding, width/operand identity and Entry/O4 transport remain separate.

Validation: 16 Lean dependency jobs, focused reference build and existing
reference regressions passed, including 3860 AArch64 control/PC complete states.
Both related freshness checks passed. Existing UBSan multiply semantics,
actual multiply route, wide-input and additional multiply route hosts passed
160,161, 1296, 27,648 and 150 cases. No proof/test failure or input filtering;
existing C inline redefinition warnings remain visible. The exact1c4a46960 full
pass precedes this increment; new combined full validation follows publication.

## Extract/reverse/extend actual inputs and dispatcher

`Arm64Extrev` binds EXTR/REV/REV16/SXTB/SXTH/SXTW numeric labels to their
generated values and actual input-width selector. Only EXTR narrows both
incoming sources before the shift pair. The other five rows read full sources;
their second source and immediate may be arbitrary and cannot affect the step.
Three raw-body and three dispatcher theorems compose this selection with the
existing canonical extract, reverse and signed-extension full-state steps.
EXTR retains native Fin-width amount bounds. W/X writes, ZR, aliases, flags,
vectors, SP, memory and empty effects are preserved with one PC advance.

Other opcodes remain outside this slice. This adds no native form, runtime guard,
compiler assumption, oracle or second ISA. Existing theorem source is unchanged;
native decoding/operand/width and Entry/O4 bindings remain separate. It is not
a complete72 dispatcher or a compiled-artifact certificate.

Validation: 19 Lean dependency jobs, focused reference build and existing
reference regressions passed, including 3860 AArch64 control/PC complete states.
Both related freshness checks passed. The existing independent semantic and
actual-dispatch oracle hosts passed 120,145 and 1680 cases; no proof/test failures
or filtered inputs. Existing inline redefinition warnings remain visible.
Exact0a9b8757c's Unary/MOV/MUL full check is queued separately behind F; this
later increment requires its own combined full validation.

## Consecutive SHIFT, multiply and unary dispatcher composition

`Arm64Mul.DispatchChain.dispatch` composes the production SHIFT → multiply →
unary branch order. Its canonical-step theorems cover both shift rows, all eight
multiply rows and both unary rows, retaining the same immediate/register count,
AUX, native amount/width and identity-modifier conditions. Numeric disjointness
is proved against every preceding family; a later operation cannot be consumed
or overwritten by an earlier branch. Unused SRC2/SRC3/immediate fields remain
arbitrary where the body ignores them. Unrelated opcodes pass to the surrounding
dispatcher as None rather than inventing a simulator transition.

These are concrete full-state compositions of the generated operation bodies,
not assumptions that handlers refine or a count-based completion claim. Existing
flags, vectors, SP, memory and ordered effects are retained with one PC advance.
This twelve-opcode fragment and the earlier FMOV/reduction tail still leave
other ISA dispatcher branches and Entry/O4/native artifact transport to complete.
No runtime, oracle, ISA, compiler or test source changed. All old theorem source
is unchanged except the additional shared Shift import.

Validation: the 34-job Lean dependency build passed. The final focused build
also passed after renaming a local variable flagged by the constructor-name
linter. Existing reference regressions include 3860 AArch64 control/PC complete
states. All nine related contract freshness checks and generated direct-dispatch
freshness passed. Existing actual operand/family/multiply/unary/AUX route hosts
passed 3804, 136, 1296, 313 and 1,115,374 cases; original C host warnings remain
visible. No proof/test failures or input filtering. Exact0a9b8757c's separate
full check is running; this later composition requires its own full validation.
