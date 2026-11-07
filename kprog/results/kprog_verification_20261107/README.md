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

## Conditional-select and CNEG raw fields and dispatch

`Arm64Condition.decode` models the actual whole-AUX condition comparison, with
exact codes0..14. Code15 and nonzero upper bits reach no condition arm; no low
byte mask or raw NV case is invented. Native NV consumes the existing generated
mnemonic normalization to AL14 while the canonical ISA retains native15.

`Arm64Select.rawStep` composes the generated CSEL/X pointer-preserving gate
before scalar selection. The selected incoming GPR/ZR is written full width
on that numeric path; every other row computes the generated scalar result and
performs the width write. Both the four base forms and four aliases compose
through the actual eight numeric opcodes and condition decoder to the same
canonical complete-state step. The separate opcode65 CNEG arm composes its
condition/value/write with CSNEG's native condition inversion. All five aliases
retain the valid non-AL condition premise; unused second sources remain arbitrary.
Raw invalid-condition and unrelated-opcode paths remain outside these slices.

Old theorem source is unchanged except two shared imports. No runtime, oracle,
test, compiler policy or ISA source changed. Native operand/flag/condition
normalization and Entry/O4 native-address/provenance transport remain explicit
boundaries; this numeric projection does not prove compiler or artifact identity.

Validation: 24 Lean dependency jobs and the focused 27-job reference build
passed, including existing regressions and 3860 AArch64 control/PC complete
states. Six contract freshness checks and generated direct-dispatch freshness
passed. Existing condition/decode/CSEL/pointer/CNEG semantic and CSEL/CNEG actual
route hosts passed 240, 80, 160161, 1024, 40097, 192 and 26400 cases. No proof/test
failures or input filtering; existing C inline warnings remain visible. The
running exact0a9b8757c full check predates this increment.

Exact `0a9b8757c6e7baf6a40fea1c93d9ee3d88edf2f7` completed the full
`make -C kprog/formal check` with exit **0**, including MVN/NEG, MOV and the
multiply-family dispatcher increments plus all prior Lean, contract,
reference/wire/compiler and semantic checks. The immutable source/cache export
was deleted automatically; compressed CALL CPU observations retain this 440-case
full run. Later Extrev, concrete dispatcher-chain and conditional-select work
need their own full validation.

## Consecutive dispatcher segment through CNEG and extract/reverse/extend

`Arm64Select.DispatchChain` extends the prior SHIFT/multiply/unary fragment
with the next production CNEG and extract/reverse/extend branches. The equality
`prefix_preserved` retains every earlier executable-prefix result for its exact
numeric operation set, even when malformed prefix AUX yields None. No refinement
assumption is supplied: both later numeric gates are proved disjoint from all
prefix members. The existing twelve-opcode canonical-step theorems consequently
transport unchanged through this equality.

CNEG's canonical step composes its whole-AUX condition with the unchanged alias
validity/inversion theorem. Each of the six later extract/reverse/extend members
is proved to bypass the earlier fragment and CNEG for arbitrary AUX/SRC3, then
compose to its canonical full-state step. Their unused immediate/SRC2 fields and
EXTR native Fin-width count remain unchanged. Other opcodes pass to surrounding
dispatch as None. No flag/vector/SP/memory/effect changes or extra PC advance
are introduced. This is a concrete nineteen-opcode fragment; the full72 step,
Entry/O4 materialization/provenance and compiled-artifact correspondence remain
open. All earlier theorem source is unchanged except one shared import.

Validation: the 45-job Lean build and focused reference build passed, including
existing regressions and 3860 AArch64 control/PC complete states. Six related
contract freshness checks and generated direct-dispatch freshness passed.
Existing actual operand/family/multiply/unary/CNEG/extrev route hosts passed
3804, 136, 1296, 313, 26400 and 1680 cases. No proof/test failures, new tests or
input filtering; original C host warnings remain visible. No runtime, oracle,
ISA, compiler policy or foreign work changed. A combined full check follows
publication, separate from exact0a9b8757c's already archived full pass.

## CCMP packed condition, fallback and operand dispatcher

`Arm64Arithmetic.ConditionalCompare` connects numeric CCMP26/27 with the
independent generated operand-source rows, proving matching numeric codes and
immediate/register decisions. The actual DST field supplies the left source;
SRC supplies the register right operand, while the native immediate remains
five bits. AUX byte0 supplies the entire condition byte0..14; high condition
bits are not masked away. Byte1 supplies fallback NZCV; only its low four bits
affect flags. Both unused AUX bytes remain arbitrary and independent.

The raw generated CCMP body composes to the existing canonical conditional
compare step, reading incoming flags before replacing NZCV and preserving every
other register/vector/SP/memory/PC-effect component except one PC advance.
Immediate forms ignore SRC, register forms ignore IMM, and aliases remain valid.
Invalid extracted conditions and unrelated opcodes stay outside this slice.
A misleading generated Lean comment about low condition bits was corrected in
its Python renderer and output; generated expressions and C bytes are unchanged.
All earlier theorem source is unchanged except three shared imports. Native
condition normalization/operand/width and Entry/O4 bindings remain separate.

Validation: 48 Lean dependency jobs and focused reference build passed, including
existing regressions with 3860 AArch64 control/PC complete states. Six contract
freshness checks and generated direct-dispatch freshness passed. Existing CCMP
handler/decode/actual-route, flag-operand and flag-route hosts passed 122880,
2105024, 3, 5120 and 1152 cases. Initial proof simplification repeatedly reapplied
fallback normalization; a single rewrite fixed it without changing premises.
No test inputs were filtered, runtime/oracle/test/ISA source is unchanged, and
original C warnings remain visible. Exact19773cca3's full check runs separately;
this increment needs a later combined full validation.

## ADDS/SUBS/CMP/CMN actual numeric and operand dispatch

`Arm64Arithmetic.FlagArithmetic` binds all eight immediate/register labels,
including the independent CMN singleton codes, to the existing generated flag
body and operand selectors. Matching writeback/CMP codes are proved across
the two generated tables. The actual AUX modifier/count extraction composes
all eleven generated modifiers; the C switch's unknown-code identity behavior
is retained instead of inventing an unsupported branch.

One raw-body theorem retains result/flag production and writeback versus
compare-only behavior. Three dispatcher theorems compose to the same canonical
immediate, shifted-register and extended-register steps. Immediate forms ignore
AUX and the RHS register; register forms ignore IMM. Compare forms ignore DST
and replace only NZCV. Native three-kind/width-sized shift bounds, Fin5 extension
amounts and original extended/plain-source aliases remain explicit. Full numeric
state, non-NZCV flags, vectors, SP, memory and empty effects are retained with
one PC advance. Native field/SP-ZR validity, width and Entry/O4 materialization
and provenance still require their producer/platform bindings.

All earlier theorem source is unchanged except one shared import. No runtime,
oracle, test, compiler policy or ISA source changed. Validation: 49 Lean
jobs and focused reference build passed, including existing regressions and
3860 AArch64 control/PC complete states. Seven related freshness checks and
generated direct-dispatch freshness passed. Existing flag-handler/operand/modifier
semantic, two actual flag, AUX and singleton route hosts passed 64, 5120, 225292,
1152, 2089, 1115374 and 11083 cases. No proof/test failure or input filtering;
original C host warnings remain visible. Exact19773cca3's full check predates
this increment; a later combined full validation remains required.

Exact `19773cca3108ed099645acbf706930c2d3ce22ae` completed the full
`make -C kprog/formal check` with exit **0**, including Extrev, CSEL/CNEG and the
nineteen-opcode concrete dispatcher segment, plus all prior Lean, contract,
reference/wire/compiler and semantic checks. The immutable source/cache export
was deleted automatically; compressed CALL CPU observations retain this 440-case
full run. The later CCMP and ADDS/SUBS/CMP/CMN actual-field increments still
require their own combined full check.

Exact `be0666ba400f534002b72c0f86a790b6fd0823c6` completed the full
`make -C kprog/formal check` with exit **0**, including CCMP packed fields and
ADDS/SUBS/CMP/CMN actual dispatch, plus all earlier Lean, contract,
reference/wire/compiler and semantic checks. The immutable source/cache export
was deleted automatically; compressed CALL CPU observations retain this 440-case
full run. The later logical-immediate ISA coverage addition is separate and
requires its own validation; it is not implied by this earlier full pass.

## Canonical AArch64 logical-immediate coverage

The single `Reference/AArch64.lean` now decodes logical-immediate native words
into a dedicated immediate step. `decodeLogicalMask` follows Arm's element/run
encoding with a per-output-bit construction, rejecting invalid N/sf, element
size and all-ones runs. Only the four architectural immediate variants enter
this decoder. Non-flag AND/ORR/EOR decode destination31 as SP; ANDS/TST discard
it as ZR, and source31 always reads ZR. W writes zero-extend. Old reference
semantics are byte-identical after removing these added declarations/arms.

Sources are Arm DDI0602 AND/ORR/EOR/ANDS immediate descriptions
(https://documentation-service.arm.com/static/68da52dfbd7cab51328c0622), with
Arm-authored DecodeBitMasks shared pseudocode mirrored at Stanford
(https://www.scs.stanford.edu/~zyedidia/arm64/shared_pseudocode.html).
No simulator/generated implementation definitions are imported by the ISA.
`Arm64Logic.immediate_step_refines` composes existing generated logical values,
width writes (including SP) and NZCV production against the same canonical
complete-state step. No synthetic source GPR is introduced. Native mask/value,
operation/width and Entry/O4 address/provenance bindings still require their
producer/platform evidence; this is not compiler or whole-program certification.

The existing reference checker now constructs masks from semantic run strings,
checks every 45312 valid raw encoding independently with LLVM18, then compares
48384 complete states including every source register, aliases, SP/ZR, W high
clearing, all32 vector banks, opaque flags, memory permissions/init and wrapping
PC. All invalid N/sf/imms classes are checked at five rotation positions across
all four operations: 1580 decoder rejects. The exact old negative 0x72024680
was LLVM-confirmed legal ANDS W0,W20,#0xc000ffff and retained as a positive
full-state regression, not dropped. An initial run exposed a stale linked
reference binary; rebuilding the existing `reference` target fixed it with
unchanged inputs. No test failures remain or native programs are filtered.

Validation: all376 incremental Lean jobs, seven related freshness checks,
generated direct-dispatch freshness, existing3860 control states, addressed
memory959states/18rejects and existing C ALU/logic-flags/flag/operand/route hosts
(336/64/1152/21688/4470cases) passed. No runtime/generator/header/kernel policy
or wire schema changed. F hardware replay and complete77/72 dispatch/O2 remain
separate obligations. A new immutable full check follows publication.

Exact `ea2b294825a777b3f19adfe3c94813e739a1a750` completed the full
`make -C kprog/formal check` with exit **0**, including the canonical
logical-immediate addition, all45312 LLVM encodings/48384 complete states/
1580 reserved-field rejects and all prior Lean, contract, reference/wire/compiler
and C semantic checks. The immutable source/cache export was deleted automatically;
compressed CALL CPU observations retain this 440-case run. This exact checkpoint
predates the subsequent actual logical-dispatch proof and other lanes' later WIP;
it is not a full check of those later changes or a whole77/72/O2 certificate.

## Actual logical operation fields and dispatcher refinement

`Arm64Logic.ImmediateDispatch` binds ALU_IMM code6 to the independent generated
RHS table and AUX byte0 ALU selectors. AND/ORR/EOR and normalized BIC values
compose with the actual width/SP write to the canonical logical-immediate step.
BIC here describes a normalized complemented operand, not a native immediate
encoding. Arithmetic ALU members remain in their own slice. The production
ORR stack-pointer branch is retained: generated pointer addition of disjoint
bits equals ORR for all64bit words, without adding an alignment, scalar-source
or small-offset premise to that numeric identity. Both generated ADD/SUB
pointer gates are proved false for every logical choice. Native pointer reads
still need the same materialized word/provenance via Entry/O4.

`Arm64Logic.FlagDispatch` binds the six actual numeric ANDS/TST immediate/register
and BICS/TST-BIC register gates, with membership equality against family and
singleton tables. It composes generated operand selection, AND/BIC, NZCV and
writeback against the same canonical full-state steps. TST aliases read DST as
left operand and SRC as right; writeback reads SRC/SRC2. All reads precede the
write, including aliases. Immediate forms ignore arbitrary AUX and RHS fields;
register forms ignore IMM and AUX bytes0/3. Shifted forms retain all four native
shift kinds and width-sized bounds. Bare NONE ignores arbitrary amount bytes:
its untrimmed temporary and LSL0 produce identical width results, writes and
flags. Register field31 discards the destination; no native register-SP logical
form is invented. The local modifier decoder describes certified native forms;
None for extensions/unknown bytes does not assert a new production C rejection.

All earlier theorem source is byte-identical; no canonical ISA, runtime,
generator, oracle or test inputs changed. Both focused Lean Logic/Arithmetic modules
passed, then the exact-source ARM-only build and ten contract freshness checks,
direct-dispatch freshness and existing dispatcher-model check passed. Eleven
existing semantic/actual-route hosts passed 336,5632,256,21688,64,5120,1152,136,
11083,1115374,225292 cases; original compiler warnings remain visible. A combined
ReferenceMain build encountered T's concurrent new x86 packet-tail decoder
lemma at Reference/X86.lean1553, with unresolved immediate-read loop goals;
that foreign WIP was preserved and reported to T, not changed or hidden as a
passing check. Native field/mask/width bindings, all77/72 dispatcher steps,
compiled artifact correspondence and O2/O4 remain open. ExactEA's full pass
above predates this new dispatcher increment; a new immutable full check follows.

## Generic ALU register logical dispatcher

`Arm64Logic.ImmediateDispatch.dispatchRegister` now binds ALU_REG7 and its
independent operand-source code to the same generated logical body. Register
RHS selection precedes that body; its scalar identity selector neither creates
a synthetic guest register nor adds a second PC advance. AUX byte0 selects
AND/BIC/EOR/ORR, byte1 the modifier and byte2 its count. Unused IMM and byte3
remain arbitrary. All four native shifts with width-sized bounds and bare
NONE with an arbitrary ignored amount compose to the existing canonical
register-logic step. NONE's untrimmed temporary and LSL0 have identical width
results; only64bit ORR can enter the retained stack-pointer branch. The prior
universal pointer-ORR identity therefore applies without a scalar-source
premise. Register field31 remains ZR, including discarded destinations.

Validation: focused Logic41 and Arithmetic50 dependency builds, seven contract
freshness checks, generated direct-dispatch and dispatcher-model checks passed.
Seven existing C semantic/actual-route hosts passed336,5632,256,21688,136,
1115374,225292cases. Final proof SHA remained unchanged through checks; original
compiler warnings remain visible. All prior theorem bodies are unchanged; no
canonical ISA, runtime, generator, oracle or test inputs changed. Modifier
None outside this native-form slice is not a new C rejection. Native field and
Entry/O4 materialization/provenance bindings, full77/72 dispatcher steps and
O2 remain open; exact88ddc9d14's running FULL predates this increment.

Exact `88ddc9d140ec4f4728406c93970cd2d63a56b299` completed the full
`make -C kprog/formal check` with exit **0**, including actual logical-immediate
ALU selection, the six logical flag dispatch rows and every earlier Lean,
contract, reference/wire/compiler and C semantic check. The immutable source/cache
export was deleted automatically; compressed CALL CPU observations retain this
440-case run. Later ALU_REG logical and non-flag ADD/SUB dispatcher increments
remain separate from this exact pass and require a subsequent full check.

## Non-flag ADD/SUB actual ALU dispatcher

`Arm64Arithmetic.AluDispatch` binds both ALU numeric rows6/7 and the independent
generated immediate/register selector, then AUX byte0 ADD/SUB. It retains the
production branch order: stack ORR (proved impossible for ADD/SUB), private-stack
SUB, general pointer ADD and scalar width write. All source provenance choices
remain quantified; no scalar-source premise removes a pointer branch. Generated
pointer addition of the negated64bit word equals modular subtraction for every
word. The same full-state body theorem therefore composes the actual result,
width/SP write and one PC advance to canonical non-flag arithmetic, retaining
all flags, vectors, memory and effects.

Three concrete dispatch theorems cover immediate, shifted-register and
extended-register canonical steps. Immediate RHS ignores all three unused AUX
bytes and the arbitrary RHS register. Register RHS ignores IMM, extracts byte1
through the existing eleven-modifier/unknown-identity switch and byte2 as count;
byte3 is arbitrary. Native three-kind/width-sized shifts, Fin5 extensions and
plain-register/LSL aliases retain their original normalization bounds. SP/ZR
roles and native field validity still require producer binding; native pointer
reads must project to the same materialized word/provenance through Entry/O4.

All old declarations are byte-identical. Validation: focused50-job Lean build,
seven existing contract freshness checks, direct-dispatch/model checks and
seven existing C semantic/actual-route hosts passed336,5632,256,21688,136,
1115374,225292cases with unchanged final proof SHA. No proof placeholders,
new tests, input filtering, canonical ISA, runtime, generator or oracle changes;
original C warnings remain visible. The full77/72 dispatcher and compiled-body
O2/O4 obligations remain open. A subsequent immutable full check includes this
increment and the preceding generic ALU_REG logical increment together.

Exact `2827f8b5c760e20cd7c69b897160d7398a05c61d` completed the full
`make -C kprog/formal check` with exit **0**, including generic ALU_REG logical
and non-flag ADD/SUB dispatch, T's published packet-tail decoding and every prior
Lean, contract, reference/wire/compiler and C semantic check. The immutable
source/cache export was deleted automatically; compressed CALL CPU observations
retain this440-case run. Later actual register-byte and leading-dispatcher
composition work is separate and requires its own subsequent full validation.

## Actual register bytes and leading dispatcher step

`Arm64Move.Fields` connects all256 operand byte values to the production
SP-first read/write and generated GPR presence/cell tables. ZR31, SP32,
NONE255 and other absent cells retain their distinct routing behavior; an
unknown byte that classifies writable still cannot write a nonexistent cell.
Typed GPR/SP/ZR operands round-trip through the real byte encoding, and complete
numeric-state writes compose to the same canonical writeData. Native SP offset
materialization and pointer/tag transport remain the existing Entry/O4 relation.

The existing register-dispatch JSON now binds stack_number32. Its generated
Lean constant is consumed by the codec, and the existing generator checks
ARM64_SP in the actual production header. The generated C header is
byte-identical, so no active ARM runtime/compiler input changes. An isolated
SP33 fixture fails with the exact drift diagnostic. Original cell entries and
all existing theorem/ISA definitions are unchanged.

`Arm64Dispatcher.dispatchPrefix` follows the actual first four gates in order:
NOP, GOT/rodata address writes, pointer-first MOV and MOVK. Individual gate
proofs compose generated operand/value/width primitives through actual byte
reads and writes into complete canonical states with exactly one PC advance.
MOV-immediate GPR/ZR and native MOV-bitmask ORR-with-ZR are separate normalization
cases; the latter includes SP destinations without inventing a MOVZ-to-SP form.
MOVK keeps native column bounds and all unused AUX/source fields. Both address
kinds retain exact native address/relocation and provenance obligations.

One `step_refines` theorem covers every constructor of the prefix Binding
relation. Its premises state only field/code/address identities, with no
handler-refinement or step-equality premise. This is the normalization boundary
for the covered prefix, not a native-byte-decoder certificate or a full72-op
step theorem. Other operations pass to the remaining dispatcher as None.

Validation: the32-job focused build and affected-family/reference
build passed, nine existing contract freshness checks, generated direct-dispatch,
dispatcher-model and mutation-source checks passed. Fourteen existing semantic/
actual-route hosts passed1280,337,20145,61,257,1024,512,6913,257,6401,260,6401,
11083,3804cases. Final proof/source hashes stayed unchanged through checks;
the JSON received only a format-preserving single-field addition, with a final
generator recheck. No source programs/oracles were filtered, no proof placeholders,
new test suite, runtime/header/kernel/ISA or paper changes; original C warnings
remain visible. Whole77/72 dispatch, native-field/artifact and O2/O4 bindings
remain open; a new immutable full check follows publication.

## Uniform byte ALU composed with the leading dispatcher

`Arm64Dispatcher.dispatch` extends the preceding NOP/address/MOV/MOVK prefix
with the actual next ALU gate6/7. One byte-field body consumes every generated
ALU choice ADD/SUB/AND/BIC/EOR/ORR, generated immediate/register RHS selection,
AUX byte1 modifier and byte2 amount. All three production pointer branches
remain in order: stack ORR, stack SUB, pointer ADD, then scalar width write.
SP32 is tested and read/written explicitly, with no silent conversion to ZR31;
all incoming scalar/stack provenance predicates remain quantified.

The arithmetic-body and logical-body equalities derive correspondence with
the already-proven family pipelines. Concrete complete-state theorems cover
arithmetic immediate, shifted and extended-register steps, plus logical
immediate, all four native register shifts and bare NONE. Immediate forms
ignore arbitrary SRC2 bytes, including absent/SP encodings; register forms
ignore IMM and unused AUX byte3. Unknown modifier-byte identity remains the
actual C behavior. Native shift/extension bounds and SP/ZR validity are kept.
Normalized BIC-immediate describes a complemented operand, not an invented
native BIC immediate encoding.

The extended DispatchBinding relation contains field/code/address identities
only. Its single dispatch_step_refines theorem now composes both earlier and
ALU cases into the same canonical ISA step, retaining every state component,
ordered empty effects and exactly one PC advance. No constructor assumes a
handler-refinement or step-equality premise. Native-byte decoding, raw-width,
materialized address/provenance and compiled-artifact correspondence still
need their producer/platform bindings; this is not the full72-op ISA theorem.

All earlier declarations are byte-identical except the additional shared
Arithmetic import. Focused58-job and affected-family/reference Lean builds,
eight existing contract freshness checks, direct-dispatch/model checks and
ten existing semantic/route hosts passed336,5632,256,21688,136,1115374,225292,
6401,6913,337cases. Final proof SHA stayed unchanged through checks, with no
placeholders, new tests, input filtering or runtime/generator/oracle/ISA changes.
Original compiler warnings remain visible. A subsequent immutable full check
will include this extension; the ongoing exact96dac03b8 check predates it.

Exact `96dac03b8960700355201726f4ee856f969baf49` completed the full
`make -C kprog/formal check` with exit **0**, including actual register bytes,
SP source binding and the leading dispatcher step, plus every prior Lean,
contract, reference/wire/compiler and C semantic check. The immutable source/cache
export was deleted automatically; compressed CALL CPU observations retain this
440-case run. The later uniform-byte ALU composition is a separate increment
and requires its own subsequent full check; no full77/72/O2/O4 claim follows.

## Uniform byte SHIFT composed after the ALU

`Arm64Dispatcher.dispatchThroughShift` extends the same concrete prefix and
ALU with the next production SHIFT gate8/9. Its body selects count through
the independent generated operand table, reads actual byte-coded registers,
computes the generated shift and performs the real width write. All four
kinds compose to the same canonical immediate/register shifts. Immediate
forms ignore any count byte, including SP32 and NONE255; register forms keep
the full incoming count word and the existing architectural width mask.
All three unused AUX bytes remain arbitrary; no scalar/tag premise removes
a branch, no raw SP byte is converted to ZR and no second PC advance occurs.

Literal opcode disjointness proves both SHIFT rows bypass the earlier gates.
Every prior DispatchBinding result transports unchanged through the extension.
One step_through_shift_refines theorem covers the field-only ShiftBinding,
including all earlier constructors and both new rows, without a component
semantic/refinement premise. Native register/width/byte decoding and Entry/O4
materialization/provenance/compiled-artifact obligations remain explicit;
the remaining ISA families still need composition into the full72-op theorem.

Validation: focused58-job and affected-family/reference Lean builds, seven
existing contract freshness checks, direct-dispatch/model checks and nine
existing semantic/route hosts passed20513,5120,3804,136,1115374,6401,6913,1280,
337cases. Final proof SHA stayed unchanged through checks. All old declaration
bytes remain unchanged; no placeholders, runtime/generator/oracle/ISA edits,
new tests or filtered inputs. Original compiler warnings remain visible.
A combined immutable full check follows publication, including this and the
preceding uniform-byte ALU extension; exact96's archived full pass is earlier.

## Uniform byte multiply/divide composed after SHIFT

`Arm64Dispatcher.dispatchThroughMultiply` adds the next production gate and
all eight generated operations, using actual SRC3 bytes. Only UDIV narrows
both incoming inputs before the generated value. Every operation uses the
same byte-coded destination/width write and advances PC once. The typed-body
equality derives the existing complete canonical multiply-step refinement,
including aliased operands, ZR/discarded destinations and native X-width
conditions for long/high operations. No flags, vectors or memory change.

MUL/UMULL/UDIV/UMULH read but ignore the accumulator. Their independent
refinement allows every SRC3 byte, including SP32 and NONE255; accumulating
forms bind the native accumulator register. All earlier prefix/ALU/SHIFT
results transport with arbitrary unused SRC3, AUX and IMM fields. Numeric
opcode disjointness derives actual gate reachability. The single
step_through_multiply_refines theorem covers the extended field-only binding
without a component-step or refinement premise. Native-byte/raw-width and
Entry/O4 pointer/provenance/artifact bindings, the remaining ISA families and
the full77/72 operation theorem still require completion.

Validation: focused74-job dispatcher/affected-family/reference Lean build,
seven existing contract freshness checks, direct dispatch/model checks and
11 existing semantic/route hosts passed 40080 cases,5120 cases,3804 cases,2072 cases,136 cases,160161 cases,1296 cases,512 cases,6913 cases,257 cases,6401 cases . The multiply
primitive host retains UBSan. Final proof SHA256 is
`0f0d710b375416f31874b2b49ce967638c8c0836f2fb38d86a1ff68e9c94eb1f` and remained unchanged throughout validation.
All prior declarations are byte-identical except the shared Mul import.
No proof placeholders, new tests, input filtering, runtime/generator/oracle/
ISA or paper changes. Original C warnings remain visible. Exact95bad0374's
ongoing immutable full check predates this extension.

Exact `95bad0374160198157abed4f80b8abb88f37448e` completed the full
`make -C kprog/formal check` with exit **0**. This includes the uniform byte
ALU and SHIFT dispatcher compositions and every preceding Lean, contract,
reference/wire/compiler and C semantic check. The immutable source/cache
export was deleted automatically. Compressed CALL CPU observations retain
this440-case run. The later multiply/divide and unary compositions are
separate increments and are not included in this full pass. The complete
77/72 dispatcher and O2/O4 bindings remain open.

## Uniform byte MVN/NEG composed after multiply

`Arm64Dispatcher.dispatchThroughUnary` adds both actual MVN/NEG rows after
the multiply gate. Its byte-coded body extracts AUX byte1/byte2, applies the
shared generated modifier and unary value, then writes the real destination
with width and a single PC advance. The actual modifier switch retains all
11 selectors and unknown-byte identity; no native-form filter is added to
the body. Complete canonical refinements bind all four native MVN shifts,
three native NEG shifts and omitted modifiers. NEG-with-ROR is not invented.
Omitted modifiers ignore any amount byte, including values outside the
native immediate bound; all unused SRC2/SRC3/IMM/AUX0/AUX3 remain arbitrary.

Numeric disjointness derives reachability through every preceding gate,
and prior results transport unchanged. One step_through_unary_refines theorem
covers the field-only binding for this complete prefix without assuming
handler-step equalities. Native byte/width/normalization, provenance, compiled
body and Entry/O4 transport still need their witnesses; the remaining ISA
families and full77/72 theorem are not yet composed.

Validation: focused74-job dispatcher/affected-family/reference Lean build,
nine existing contract freshness checks, direct dispatch/model checks and
10 existing semantic/route hosts passed 40080 cases,2072 cases,136 cases,225292 cases,40081 cases,313 cases,512 cases,6913 cases,257 cases,6401 cases. Final proof
SHA256 `c2548e069595ba7ef0ff659d77fd807d78856be382ac37655a8fa0278f18ed55` stayed unchanged; every earlier declaration
is byte-identical. No placeholders, new tests, filtering, ISA/runtime/generator/
oracle/paper changes. Original compiler warnings remain visible. Exact95's
full pass predates both this extension and the multiply composition.

## Uniform byte CNEG and extract/reverse/extend composed next

`Arm64Dispatcher.dispatchThroughExtrev` appends the actual CNEG gate and then
all six EXTR/REV/REV16/SXTH/SXTW/SXTB rows to the same prefix. CNEG decodes the
whole AUX word, computes the incoming NZCV predicate and composes the generated
negation with actual byte read/write. Its non-AL alias condition remains the
native CSNEG inversion; no raw15 condition or truncated-AUX behavior is added.
EXTR alone narrows both inputs before the generated concatenation window and
retains native shift bounds. The other five rows read full inputs and ignore
any second-source byte and immediate, including SP32/NONE255. All unused SRC3
and earlier fields remain arbitrary. Destination aliases, ZR, W zero-extension,
unchanged flags/vectors/memory and one PC advance follow the existing complete
canonical family steps through derived body equalities.

Numeric opcode disjointness derives reachability through every earlier gate,
and all prior results transport unchanged. A single step_through_extrev_refines
theorem covers the field/code/condition/amount-only ExtrevBinding without a
component semantic/refinement premise. The remaining ISA families, native
byte/raw-width normalization and O2/O4 provenance/artifact bindings are still
open; this does not establish the full77/72 theorem.

Validation: focused74-job dispatcher/affected-family/reference Lean build,
nine existing contract freshness checks, direct dispatch/model checks and
12 existing semantic/route hosts passed 240 cases,40080 cases,2072 cases,136 cases,120145 cases,26400 cases,1680 cases,40097 cases,512 cases,6913 cases,257 cases,6401 cases. The exact proof
SHA256 `08bc91c71321078616fec93498329a384f69fc8e35dfeb14fdae022aa691821b` stayed unchanged through checks. Every old
declaration is byte-identical except the shared Select import. No placeholders,
new tests, input filtering, runtime/generator/oracle/ISA or paper changes.
Original C warnings remain visible. An immutable combined full check follows
publication; the already archived exact95 pass predates these extensions.

## Uniform byte BITFIELD composed after EXTR

`Arm64Dispatcher.dispatchThroughBitfield` adds the next production BITFIELD
gate with five kinds UBFX/SBFX/UBFIZ/BFXIL/BFI. The actual byte body reads
both incoming SRC and DST, extracts AUX byte1 LSB and byte2 count, applies
the generated primitive and performs the width write with one PC advance.
AUX byte0 independently selects the kind. Native typed bounds and kind
identity are retained; no runtime bounds guard is invented. Destination/source
aliases, ZR/discarded destinations and all other state components follow the
existing complete canonical bitfield step. SRC2/SRC3/IMM/AUX3 remain arbitrary.

Numeric disjointness derives reachability after every preceding gate, and
all earlier results transport unchanged. The single step_through_bitfield_refines
covers the field/kind/bounds-only binding without a component semantic premise.
The remaining ISA families, raw native decoding/width and O2/O4 transport
still require completion; this is not the full77/72 theorem.

Validation: focused77-job dispatcher/reference build, eight existing contract
freshness checks, direct-dispatch/model checks and10 existing semantic/route
hosts passed 40080 cases,2072 cases,136 cases,126246 cases,512 cases,6913 cases,257 cases,6401 cases,586829 cases,1115374 cases. Exact proof SHA256
`2171ceb79b9321305e570fea54e9e4ee2b9c80ea009665a29b42a92d3ca514ce` remained unchanged during validation. Every prior
declaration is byte-identical except the shared Bitfield import. No placeholders,
new tests, filtering, ISA/runtime/generator/oracle/paper changes. Original C
warnings remain visible. The active exact261 full check predates this extension.

## Uniform byte flag arithmetic composed after BITFIELD

`Arm64Dispatcher.dispatchThroughFlagArithmetic` adds all eight generated
ADDS/SUBS/CMP/CMN immediate/register rows. Its actual byte body distinguishes
production roles: writeback reads SRC/SRC2 and writes DST, whereas compare-only
reads DST/SRC and does not write registers. The independent generated operand
selector, all11 source modifiers and unknown-byte identity, generated arithmetic
result/NZCV, full-width flag word preservation and one PC advance remain explicit.
Flag-setting operations never take the non-flag pointer-ADD branch; all incoming
provenance booleans remain quantified. SP32 is not silently mapped to ZR31.

The derived typed-body equality feeds existing complete canonical immediate,
shifted and extended-register steps, retaining native bounds and omitted shifts.
Immediate rows ignore any physical RHS bytes; compares ignore any SRC2 byte.
SRC3 and unused AUX bytes stay arbitrary, including absent/SP encodings. Numeric
opcode disjointness derives reachability past all preceding gates. The single
step_through_flag_arithmetic_refines theorem covers the field/role/modifier/
amount-only binding and every earlier case, with no semantic/refinement premise.
The remaining ISA families, native byte/raw-width decoding and O2/O4 transport
still require completion; this is not the full77/72 theorem.

Validation: focused77-job dispatcher/reference Lean build (first build passed),
12 existing contract freshness checks, direct-dispatch/model checks and13 existing
semantic/route hosts passed 40080 cases,60144 cases,5120 cases,64 cases,2072 cases,136 cases,225292 cases,512 cases,6913 cases,257 cases,6401 cases,586829 cases,1115374 cases. Exact proof SHA256
`16409a2ec38ff028001de2214b0b113fe57da5d14391eb86dab2c841faebee90` stayed unchanged throughout validation. All prior
declarations remain byte-identical. No placeholders, new tests, input filtering,
ISA/runtime/generator/oracle/paper edits. Original C warnings remain visible.
The active exact261 full check predates both this and BITFIELD composition.

## Uniform byte logical flags composed after arithmetic flags

`Arm64Dispatcher.dispatchThroughFlagLogic` appends all six TST/ANDS/BICS
numeric rows. The actual byte body keeps DST/SRC test roles versus SRC/SRC2
writeback roles, independent generated operand selection, complete modifier
switch (including extensions and unknown identity), generated logical result
and NZCV, destination width write and one PC advance. No native-form modifier
filter is added to the runtime projection. Native shifted and omitted-modifier
cases retain all four kinds and bounds; no BIC-immediate native form is invented.

Immediate tests ignore arbitrary SRC/SRC2, writeback immediates ignore arbitrary
SRC2, and all register tests ignore arbitrary SRC2. All rows ignore SRC3; NONE
ignores any amount byte and unused AUX0/3 remain arbitrary. Derived typed-body
equalities compose existing full canonical states, retaining aliases, zero
register/discard semantics, flag-word bits outside NZCV and untouched memory.
Literal opcode disjointness proves the actual gate is reached. One
step_through_flag_logic_refines theorem covers the field-only binding and
all earlier rows with no component semantic premise. Remaining families,
native byte/raw-width and O2/O4 transport are still open.

Validation: focused77-job dispatcher/reference build (first compile passed),
12 existing contract freshness checks, direct-dispatch/model checks and13
existing semantic/route hosts passed 40080 cases,60144 cases,5120 cases,64 cases,2072 cases,136 cases,225292 cases,512 cases,6913 cases,257 cases,6401 cases,586829 cases,1115374 cases. Exact proof SHA256
`6fdd4a4ad2987d4246dcab78e36a3c918aa0d20dd1cfed982cfd10adff5583bc` remained stable. Every old declaration is byte-identical;
no placeholders, new tests, input filtering, ISA/runtime/generator/oracle/paper
changes. Original C warnings remain visible. Active exact261 full check predates
BITFIELD and both flag-family compositions.

## Uniform byte ORN composed after logical flags

`Arm64Dispatcher.dispatchThroughOrn` appends the actual ORN numeric gate.
Its byte-coded body consumes the full modifier switch, AUX byte1/byte2,
generated complemented-OR value and width write with one PC advance and no
NZCV change. All four native shifts retain native amount bounds. An independent
width-level equality proves NONE agrees with LSL0 after generated ORN narrowing;
NONE ignores any amount byte, without adding a shift guard. SRC3/IMM/AUX0/AUX3
remain arbitrary. Aliased operands and ZR/discarded destinations retain the
existing complete canonical logical step. No pointer path or source-tag premise
is invented for this scalar operation.

Literal disjointness derives reachability through all previous gates; every
earlier result transports unchanged. The single step_through_orn_refines covers
the field/modifier/amount-only binding, with no assumed component step equality.
Remaining families, native byte/raw-width and O2/O4 transport are still open.

Validation: focused77-job dispatcher/reference Lean build (first compile passed),
nine existing contract freshness checks, direct-dispatch/model checks and12
existing semantic/route hosts passed 40080 cases,2072 cases,136 cases,225292 cases,701 cases,40401 cases,512 cases,6913 cases,257 cases,6401 cases,586829 cases,1115374 cases. Exact proof SHA256
`1c6145fe2cd4a660d527ee8b639a5f273a92bdec6224d29304fc8be42e7fc27c` remained unchanged. Every old declaration is byte-identical;
no placeholders, new tests, input filtering, ISA/runtime/generator/oracle/paper
changes. Original C warnings remain visible. Exact261's just-finished full pass
predates BITFIELD, arithmetic/logical flags and this ORN composition.

Exact `26137eada3d767c3d9fe170e0b2ca2ec98ae1739` completed the full
`make -C kprog/formal check` with exit **0**, including the uniform-byte
multiply/divide, MVN/NEG, CNEG and EXTR/REV/SXT dispatcher compositions and
all earlier Lean, contract, executable-reference/wire/compiler and C semantic
checks. The immutable source/cache export was deleted automatically. Compressed
CALL CPU observations retain this440-case run. BITFIELD, arithmetic/logical
flag rows and ORN are later increments and are not included in this pass.
The complete77/72 theorem and O2/O4 bindings remain open.

## Uniform byte CCMP composed after ORN

`Arm64Dispatcher.dispatchThroughCompare` appends both actual CCMP numeric
rows. Its byte body reads physical DST as the left operand and selects SRC
or IMM with the independent generated operand table. The packed condition
byte controls generated subtraction flags versus fallback NZCV; only the
fallback ignores its upper four bits. Full flag-word bits outside NZCV,
all registers/vectors/memory and a single PC advance are preserved. Both
condition outcomes follow the same canonical reference, with no branch premise.

The derived typed-body equality composes existing full immediate/register
compare steps. Immediate values retain the native five-bit bound and ignore
any SRC byte; SRC2/SRC3/AUX2/AUX3 stay arbitrary for both rows. Literal opcode
disjointness derives reachability past all preceding gates. One
step_through_compare_refines theorem covers the field/code/condition/fallback
binding and every earlier case without assuming component-step equalities.
Native byte/raw-width and O2/O4 transport, remaining families and the complete
77/72 step theorems still need completion.

Validation: focused77-job dispatcher/reference Lean build,10 existing contract
freshness checks, direct dispatch/model checks and13 existing semantic/route
hosts passed 240 cases,40080 cases,5120 cases,122880 cases,2105024 cases,2072 cases,136 cases,512 cases,6913 cases,257 cases,6401 cases,586829 cases,1115374 cases. Exact proof SHA256
`15c64e35da9e350e580b53201dd74d7cc25301adb2188e8e80752099ecaf6960` stayed unchanged throughout checks. Every earlier
declaration remains byte-identical. No placeholders, new tests, filtering,
ISA/runtime/generator/oracle/paper changes. Original compiler warnings remain
visible. The active exact45d full check predates this extension.

## Uniform byte conditional selects composed after CCMP

`Arm64Dispatcher.dispatchThroughSelect` appends all eight actual conditional
select numeric rows. Its byte body evaluates the whole AUX condition and keeps
the generated CSEL/X pointer-copy branch before scalar generated selection and
width write. No scalar provenance premise removes that pointer branch. Native
value/provenance materialization remains Entry/O4. Each body preserves all
other state components and advances PC once, including aliased sources/destinations.

Derived typed-body equality feeds the four direct CSEL/CSINC/CSINV/CSNEG
canonical steps and four CINC/CINV/CSET/CSETM aliases. Alias non-AL validity,
condition inversion and ZR sources remain explicit. Native NV15 uses the actual
producer AL14 normalization while retaining code15 in the canonical step; raw
whole-AUX15 or larger is not interpreted as a low-byte condition. CINC/CINV
ignore arbitrary SRC2, and CSET/CSETM ignore arbitrary SRC and SRC2, including
SP32/NONE255. SRC3 and IMM are unused for every row. Literal numeric disjointness
derives reachability through all prior gates. One step_through_select_refines
covers field/code/condition-only bindings and every earlier result with no
semantic/component-refinement premise. Remaining memory/control/vector families,
native byte/raw-width and compiled-artifact/O2/O4 bindings remain open.

Validation: focused77-job dispatcher/reference Lean build (first compile passed),
eight existing contract freshness checks, direct-dispatch/model checks and12
existing semantic/route hosts passed 240 cases,80 cases,40080 cases,2072 cases,136 cases,192 cases,160161 cases,1024 cases,512 cases,6913 cases,257 cases,6401 cases. Exact proof SHA256
`80f2016b1cc898a888b65453961b4b152b2a929c0869d0d533680785328496af` stayed unchanged; all earlier declaration bytes
remain identical. No placeholders, new tests, input filtering, ISA/runtime/
generator/oracle/paper changes. Original C warnings remain visible. Active
exact45d's full check predates CCMP and this select extension.

## Memory base bytes and scalar-memory width binding

`Arm64Dispatcher.memoryBaseCode` binds native memory base field31 to actual
simulator SP32, while data field31 continues to read/discard ZR. Complete-state
byte read/write equalities connect this codec to the single canonical memory
base operations, with all GPRs, aliases, SP, flags, vectors, memory and PC retained.
The actual numeric pre/post base step keeps its zero-delta no-write behavior
and full-width nonzero update; derived equality composes the existing generated
pre/post deltas into the same native base update. Pointer materialization and
tag transport remain explicit Entry/O4 obligations.

Raw FLAGS binding separately retains all scalar-memory widths1/2/4/8. Zero
selects exactly the production doubleword default; it never turns byte/halfword/
word or16-byte vector accesses into an arbitrary integer W/X operation. These
are field identities only. This increment proves base-update algebra before an
intervening transfer; it does not establish permissions/access success, erase
faults, identify one16-byte event with two8-byte accesses, or complete memory
dispatch. Native byte/width/compiled-body and full77/72/O2/O4 transport remain open.

Validation: focused88-job dispatcher/reference Lean build, seven existing
contract freshness checks, direct-dispatch/model checks and12 existing semantic/
route hosts passed 40080 cases,20168 cases,512 cases,22115 cases,512 cases,6913 cases,257 cases,6401 cases,15 cases,205324 cases,4608 cases,135170 cases. Exact proof SHA256
`46f2ac87f4ff5225098a199d8d917a85144fb6ff47946797e8917ba759e04751` stayed unchanged. Earlier declaration bytes remain
identical except the shared VectorMemory import. No placeholders, new tests,
input filtering, ISA/runtime/generator/oracle/paper changes. Original compiler
warnings remain visible. Exact45d's full pass predates CCMP/select and these
memory-field bridges.

Exact `45d56a97a2f3313a87d78cc82ca0e41cd7144962` completed the full
`make -C kprog/formal check` with exit **0**. This includes the byte-field
BITFIELD, arithmetic/logical flags and ORN dispatcher compositions plus all
preceding Lean, contract, executable-reference/wire/compiler and C semantic
checks. The immutable source/cache export was deleted automatically; compressed
CALL CPU observations retain this440-case run. CCMP/select and memory-base/
width bridges are later increments and are not included in this full pass.
The complete77/72 theorem and O2/O4 transport remain open.

## Actual byte-field scalar memory body

`Arm64Dispatcher.scalarMemoryBody` now composes the actual numeric pre/access/
post sequence using byte-coded base/data/index fields. The physical index byte,
not the duplicate AUX0 lane, controls index presence. Its independent generated
presence/value selectors feed the full modifier switch and generated offset.
The sentinel index255 ignores all modifier/shift bytes and leaves AUX0 arbitrary.
Full flag-byte identities retain native offset/pre/post modes and generated deltas.

The transfer consumes generated native-width load/store ladders and actual byte
reads/writes. LOAD retains both generated scalar/tag-preserving branches for
every incoming tag predicate; no scalar premise removes a branch. All four
widths, aliases/ZR/discarded destinations and one PC advance compose to the
existing complete canonical immediate memory step under the original explicit
SP-alignment, access and native non-overlap witnesses. Ordered events use only
the selected bytes; the packed8-byte load word is a ghost, not an extra read.
No runtime permission guard or fault-success replacement is introduced. Entry/
O2/O4 must still establish materialized pointer/shadow/provenance correspondence
and native permissions; faulting writeback and dispatcher integration remain open.

Validation: focused94-job dispatcher/reference Lean build,11 existing contract
freshness checks, direct-dispatch/model checks and16 existing semantic/route
hosts passed 40080 cases,2048 cases,20168 cases,512 cases,22115 cases,512 cases,6913 cases,257 cases,6401 cases,20024 cases,20024 cases,16486328 cases,17 cases,3015 cases,4608 cases,135170 cases. Exact proof SHA256
`186a2324dc5bc31af519981d8f852c4e6601e00a1d63f642d45c458b32e369cd` stayed unchanged. Earlier declaration bytes remain
identical except the shared WritebackMemory and two generated imports. No
placeholders, new tests, input filters, ISA/runtime/generator/oracle/paper changes.
Original compiler warnings remain visible. Active exact2c9 full check predates
this body extension; full77/72/O2/O4 are not discharged.

Exact `2c9bc4f3bb668ec41ad59d5900850425a3099df8` completed the full
`make -C kprog/formal check` with exit **0**, including CCMP/select dispatch
and memory-base byte/raw-width bridges plus every preceding Lean, contract,
executable-reference/wire/compiler and C semantic check. The immutable source/
cache export was deleted automatically. Compressed CALL CPU observations retain
this440-case run. The actual byte-field memory body and subsequent LOAD dispatcher
are separate increments not included in this full pass. Full77/72/O2/O4 remain open.

## Raw-FLAGS prefix and actual LOAD dispatcher composition

`Arm64Dispatcher.dispatchThroughLoad` consumes actual FLAGS bytes instead of
coercing byte/halfword memory widths to integer W/X. The certified scalar prefix
normalizes only W/X native fields (including zero→X), then the LOAD gate decodes
all four memory widths from the same generated effective code. Other widths pass
to their own families at this normalization boundary; no C rejection policy is
added. Literal opcode disjointness proves LOAD bypasses every preceding gate,
and all prior SelectBinding results transport unchanged with raw width identity.

The actual byte body composes offset/pre/post immediate loads and native
register-index addressing, including UXTW/SXTW/LSL/SXTX, optional width scaling,
ZR indexes and omitted unscaled X modifiers. Only the physical NONE255 byte
suppresses the index; AUX0 remains arbitrary. Omitted NONE agrees with native
LSL0/SXTX0 by a derived value equality, not a value premise. Native register-offset
forms bind IMM0 and no writeback. Both scalar/tag-preserving LOAD branches remain
quantified, as do unused fields and all source/destination/index aliases permitted
by the native form. Exact memory bytes/events/full state and one PC advance follow
the same canonical ISA.

One step_through_load_refines theorem covers all earlier gates plus both LOAD
addressing classes. LoadBinding contains field/code/width/modifier/amount identities
only; scalarMemoryAccess separately states the original native SP-alignment and
per-byte access premises. It does not infer native permissions from writable
shadow memory, add runtime guards, erase faults or assume component step equality.
Entry/O2/O4 must establish these access/materialization/provenance premises from
an admitted artifact. Faulting writeback, remaining families and full77/72/O2/O4
completion remain open.

Validation: focused94-job dispatcher/reference Lean build,13 existing contract
freshness checks, direct-dispatch/model checks and17 existing semantic/route
hosts passed 40080 cases,225292 cases,2048 cases,20168 cases,512 cases,22115 cases,512 cases,6913 cases,257 cases,6401 cases,20024 cases,20024 cases,16486328 cases,17 cases,3015 cases,4608 cases,135170 cases. Exact proof SHA256
`b0b79dd12d3b052a2e51a6c103a35b89181febaff37ab2684d43e55082b4788a` stayed unchanged through validation. Every previously
published declaration remains byte-identical. No placeholders, new tests, input
filtering, ISA/runtime/generator/oracle/paper edits. Original warnings remain
visible. Exact2c9's archived full pass predates this and the actual memory body.

## Actual byte signed loads composed after LOAD

`Arm64Dispatcher.dispatchThroughSigned` adds all three LDRSB/LDRSH/LDRSW numeric
rows immediately after LOAD. Actual byte bodies select native memory width and
the generated shared sign operation from the opcode, then apply the independent
FLAGS-selected W/X destination write. Input width never substitutes for output
width, and register-index scaling uses input width. Native output validity is
explicit, retaining the canonical decoder's reserved W-output word sign-load.

Derived byte-to-typed success/core equalities compose offset/pre/post immediate
and native register-index forms, including UXTW/SXTW/LSL/SXTX, optional scaling,
ZR, omitted unscaled X modifiers and permitted aliases. Physical index255 and
SP32 remain distinct from native ZR31; unused AUX0/SRC3 and immediate-form modifier
bytes remain arbitrary. Ordered native-width events/init/full state and one PC
advance follow the existing canonical signed memory steps. No C alignment or
permission guard is added; original native access witnesses stay explicit.

Literal numeric disjointness derives reachability through every preceding gate.
One step_through_signed_refines theorem covers the field-only SignedBinding and
all earlier cases, separately requiring scalarMemoryAccess. It assumes no component
semantic equality and derives no permission from a writable shadow/tag. Native
producer/compiled-body/Entry/O2/O4 transport and faulting writeback remain open;
this is not full77/72 completion.

Validation: focused94-job dispatcher/reference Lean build (first compile passed),
12 existing contract freshness checks, direct-dispatch/model checks and18 existing
semantic/route hosts passed 40080 cases,120145 cases,1680 cases,256 cases,256 cases,98197 cases,20168 cases,512 cases,22115 cases,512 cases,6913 cases,257 cases,6401 cases,20024 cases,17 cases,3015 cases,4608 cases,135170 cases. Exact proof SHA256
`8d57537bbccaa2f54422a93c520f21cb10a4c122af2cef091ae76d9fc9b0a5d7` remained stable. Every older declaration is byte-identical;
no placeholders, new tests, input filtering, ISA/runtime/generator/oracle/paper edits.
Original compiler warnings remain visible. Active exactb757 full check predates
this signed-load extension.

## Actual byte STORE composed after signed loads

`Arm64Dispatcher.dispatchThroughStore` adds the next production STORE gate,
using physical DST as base, SRC as data and SRC2 as index. The same raw FLAGS
byte selects exact1/2/4/8-byte stores, independently of signed-load output width.
Derived body/core equalities compose native offset/pre/post immediate and indexed
UXTW/SXTW/LSL/SXTX forms, including scaling, ZR data/index, omitted unscaled X
modifiers and native alias/non-overlap conditions. Index presence uses actual
SRC2/NONE255, with unused AUX0/SRC3 arbitrary. Source values are read before the
transfer, exact native-width bytes become initialized and ordered write events
match the same canonical ISA; PC advances once and other state is retained.

Literal numeric disjointness derives reachability after all prior gates. One
step_through_store_refines theorem composes every earlier case plus both store
addressing classes. StoreBinding contains only field/code/width/modifier/amount
identities; scalarMemoryAccess separately requires original native SP alignment
and per-byte WRITABLE permissions. Read permission, private shadow writability
or tag predicates do not establish that native premise. No runtime guard,
fault-success replacement or assumed component step equality is introduced.
Faulting writeback, native producer/compiled-body/Entry/O2/O4 transport, remaining
families and full77/72 completion are still open.

Validation: focused94-job dispatcher/reference Lean build (first compile passed),
11 existing contract freshness checks, direct-dispatch/model checks and17 existing
semantic/route hosts passed 40080 cases,225292 cases,20168 cases,512 cases,22115 cases,512 cases,6913 cases,257 cases,6401 cases,20024 cases,16486328 cases,24 cases,17758119 cases,17 cases,3015 cases,4608 cases,135170 cases. Exact proof SHA256
`7dfe53aa926d4cc4521201ee1734af201fa55d94bfc8c94904a4bb12bdd23d46` stayed unchanged through checks. Every prior declaration
is byte-identical. No placeholders, new tests, input filtering, ISA/runtime/
generator/oracle/paper changes; original compiler warnings remain visible.
The active exactb757 full check predates signed-load and STORE extensions.

Exact `b7575b328c02d2db1cdee3f7c39ee2d4cfec28f7` completed the full
`make -C kprog/formal check` with exit **0**, including actual byte memory
bodies and raw-FLAGS LOAD offset/pre/post/indexed dispatch plus every preceding
Lean, contract, executable-reference/wire/compiler and C semantic check. The
immutable source/cache export was deleted automatically. Compressed CALL CPU
observations retain this440-case run. Signed-load and STORE extensions are
later increments not included in this full pass. Native access/producer/artifact
bindings, remaining operations and full77/72/O2/O4 completion remain open.

## Actual STLXR bytes and explicit exclusive observation

`dispatchThroughExclusive` adds the next actual gate after STORE. Physical DST
is the fixed-W status, SRC is data and SRC2 is base (native SP31 becomes actual
SP32). NONE index and zero displacement are proved to suppress every AUX byte;
SRC3 is unused. Both outcomes retain exact native-width bytes and source-before-
status aliases, with one PC advance and no NZCV change. `dispatchThroughExclusiveAt`
queries the original physical IMM site and Booleanizes the complete64-bit result,
including nonzero values with zero low32 bits. The raw numeric dispatcher adds
no monitor or ordering events.

The separate `observeExclusiveStore` attaches the existing canonical ghost
monitor and attempt/release event. Derived byte-to-core equality and
`step_through_exclusive_at_observed_refines` compose all earlier rows plus STXR/
STLXR under field-only `ExclusiveBinding` and explicit native environment
premises: monitor/commit outcome, original-SP/natural alignment and conditional
per-byte writability. Failure may avoid memory access exactly when the canonical
profile permits it. This observed theorem does not establish C atomicity/order,
recover release from the shared opcode, bind the site to the native word, or
certify LDXR/LDAXR aliases of ordinary LOAD. Those producer/platform/O2/O4
obligations, remaining operations and full77/72 completion stay open.

Validation: Lean93/93 dispatcher build,11 existing generated contracts and
dispatch-model checks pass. Fifteen of19 existing semantic hosts compile and
pass; four fail compilation in the current production XDP read branch
(`arm64_sim_unmapped_xdp_read` attribute error), including `stlxr_route_host`,
`test_arm64_store_bytes_route_host`, `test_arm64_mem_base_src_route_host` and
`test_arm64_mem_prepost_route_host`. Failed-host stale binaries were never run.
All prior declaration bytes are unchanged except the new import. Three new
proof audits report only propext, Classical.choice, Lean.ofReduceBool and
Quot.sound; no placeholders/new tests/ISA/runtime/oracle changes. Exact proof
SHA256: `bd445348a58c1134f7ee83ded9487bdd8daaf8ba52c9baf0cb185681346a5bd6`.

The combined immutable full `make check` at
`967fc6b49608634cd5566dfd6a2925aa828cdcbe` (signed loads/STORE, A's production
XDP fix and C's exact-count repair) exits **2**, first failing the unchanged
`test_arm64_imm_operand_route_host.c:348` compilation at Makefile:457 with
the same unmapped-XDP diagnostic. It predates this exclusive proof extension.
This is an integration failure, not a full pass or an unsafe execution result.
A owns the production repair; no oracle was weakened or removed. Exact pins,
command exits and complete compressed original full/focused logs are retained
in `arm64-xdp-host-integration.json` and `arm64-xdp-host-integration.log.gz`.
The temporary full source/cache export was deleted automatically; shared
incremental caches and every semantic oracle remain intact.

## Actual LDP/STP byte fields and combined observed step

`dispatchThroughPair` adds both next production gates after STLXR. LDP takes
first/second destinations from DST/SRC and base from SRC2; STP takes data from
SRC/SRC2 and base from DST. SRC3 is the real index byte, bound to NONE for
native pair-immediate forms; AUX0/modifier bytes stay arbitrary. Raw FLAGS
binds W/X widths, including zero's doubleword default. Second-element stride
is WIDTH, so W pairs use four bytes. Both LOAD tag branches preserve the same
numeric values. Addresses are captured before destination writes; native
base/destination aliases and canonical writeback non-overlap stay intact.

Derived byte-to-typed success/body equalities retain ordered element events,
exact initialized write bytes, all other state and one PC advance. The single
`step_through_pair_observed_refines` theorem composes every preceding gate and
both pair rows through field-only `PairBinding`. Separate `pairMemoryAccess`
requires original SP alignment, permissions for each element and the canonical
two-access profile. No LSE2 atomic-access equivalence is asserted; preceding
exclusive monitor/order observations and their environment witnesses remain
explicit. Faulting writeback/producer/artifact/O2/O4 and full77/72 stay open.

Validation: Lean93/93 and12 existing contract/model checks pass;10 of13
existing semantic hosts pass (including465696 pair-value and4096 pair-tag
cases). Three existing route hosts fail compilation in the unchanged
production XDP read branch: pair_mem_route, mem_base_src_route and
mem_prepost_route. Failed stale binaries were not executed. The previously
archived exact967 full failure is unchanged; no duplicate full was started.
The same integration JSON/compressed archive now retains the complete pair
commands and original log. No source/ISA/runtime/oracle/test weakening.
Four proof audits use only propext/Quot.sound plus the existing
Classical.choice/Lean.ofReduceBool dependencies. Prior declaration bytes
remain identical; proof SHA256 `952a1a7ae78a4eb56111819b7c828544787ca0ea06a95bf41996138328628f1f`.
