# Lane V verification checkpoint

<!-- COVERAGE START -->
[Per-operation and per-token coverage](coverage.tsv) records the current partial
formalization. Totals below count distinct numeric operations; each corresponding
specialization token also has its own row.

| Coverage obligation | x86-64 | AArch64 |
| --- | ---: | ---: |
| Requested operation domain | 77 | 72 |
| Production numeric operations / specialization tokens | 75 / 75 | 71 / 71 |
| Reference step family defined | 67/75 | 71/71 |
| Raw register handler refinement | 32/75 | 0/71 |
| Raw register dispatcher arm composition | 32/75 | 0/71 |
| Stack register/immediate/memory model / composed step | 2/75 | 0/71 |
| Addressed memory model / composed step | 13/75 | 0/71 |
| Additional partial-model handler families | 18/75 | 0 |
| Conditional modeled handler / observed dispatcher | 0 | 71/71 |
| Immediate-alias source-emission binding composed | 0 | 2/71 |
| Control handler model / composed step | 2/75 | 0/71 |
| O2 C-model token-body equality | 49/75 | 71/71 |
| Selected CPU/C/reference or QEMU/C/reference agreement | 66/75 | 67/71 |
| Additional explicit-monitor-only replay | 0 | 1/71 |
| Numeric operations awaiting selected replay | 9/75 | 3/71 |

The 49 x86 O2 equalities cover37 direct bodies, ten generic calls and two
branch-handler bodies. PUSH/POP cover their register/immediate/memory field domain and derive base/index
addresses from the same input, with an explicit arena/permission interface.
The remaining18 x86 reference-family handlers have partial model proofs; eight
pseudo operations require environment/native-link binding. ARM conditional
entries carry explicit observation, environment, address, code, monitor and ABI
premises. ARM ADD_IMM/SUB_IMM numeric tokens3/4 now share the published generic
immediate-body gate through unified ExecBinding, source and invocation emission.
ADD_IMM/SUB_IMM/ALU_IMM have three C-model W/X direct-body equalities and
canonical-step composition under the existing field/provenance/platform bindings.
LOAD/STORE/LDRSB/LDRSH/LDRSW/STLXR add six direct memory-body equalities
and observed canonical-step composition. Their site-indexed law retains
each dynamic exclusive outcome and the shared native field, memory, monitor,
address/materialization and compiled-C interfaces.
Fifty-two scalar tokens add direct-body equality and canonical observed-step
composition: NOP, address/move/keep, register ALU, shifts, multiply/unary,
conditional negation, extract/reverse/extend/bitfield, arithmetic/logical flags,
ORN, conditional compare and select. The six logical flag selectors retain
their native inverted-register field condition. The same code/address,
provenance, source-emission and compiled-C interfaces remain explicit.
Nine pair/vector tokens add the same equality/step composition: LDP/STP,
LOAD/STORE D0/Q0, FMOV and CNT/UADDLV. Pair width, fixed D/Q width,
FMOV direction/bank and reduction AUX retain their exact boundaries.
RET adds emitted-return route/body equality through the unified invocation
step. Its source macro captures raw Rn, checks zero-offset RETURN or a finite
CODE case, and observes the same canonical register branch. The71 ARM
entries comprise70 numeric body equalities and one emitted-return control
body equality; complete exit memory/ABI and C/compiler transport remain
explicit universal interfaces.
Whole-simulator raw handler/dispatcher closure, compiled-B,
ABI/definedness and native-link preservation remain universal obligations.

Inventory is pinned to the production headers in each row's `catalog_source`
and `catalog_sha256`. The requested 77/72 domain requires identification of two
additional x86 operation names and one additional ARM operation name against
the current 75/71 numeric catalogs. Five x86 compatibility aliases have separate
rows and are excluded from operation/token totals. Numeric tokens, native
instruction forms and control composites retain their distinct identities.

Replay integration uses F's published input set `92441b38ac8110766058094409f9758fa3cbd68c`
([source ledger](../kprog_fidelity_20261107/differential/replay-inputs/README.md)).
Each `replay_source_epochs` cell records the actual backend, source snapshot,
simulator/executable/reference hashes, selected forms, all three comparison
counts and original evidence paths. Source epochs remain separate. ARM STLXR
adds 4,096 explicit-monitor observations with that projection premise; the
67 ordinary ARM replay totals retain their own scope. Architectural LEAVE64 and
finite control composites retain their separately labeled rows in F's source
ledger. These finite observations support the universal theorem work.

`proved-raw-register`, `proved-stack-memory-model`, `proved-addressed-memory-model`,
`partial-model`,
`conditional-observed`, `conditional-direct-alias`, `proved-C-model`
and `pending` retain their distinct meanings. V updates the table and these
totals with each proof/status-changing publication. V maintains theorem/token/link-law
status and replay-ledger joins; C/A supply architecture-specific replay inputs. Safety evidence follows the
universal simulator, token and transformation laws. Historical individual-program
proof artifacts remain frozen.
LEA's complete raw register-field/frame/dispatcher/token chain now uses the
published C sourceafba4a089, whose header6b3f31731d9d equals the exact prior
8192-case RSP wrapping candidate. JCC/JMP have a unified logical-label control
step, all16 PF-aware conditions and per-token body equality. Production
label/native-PC, return-target fusion, ABI/definedness and compiled-code
correspondence retain their universal completion interfaces.
The added finite CL replay epochs contribute98304 observations and preserve
the66/75 numeric replay total and each original source identity.
Register-writing rows also pin the production9b0aa2b09 epoch: headercf27e323c885
and generatorb8644bc7eaeb. All28 currently covered writer families link the
source receipt; the pure Lean/JSON bit contract retains its original bytes.
The published8aa94baa2 full check and current memory-condition oracles both
use this header. C/Lean and compiler correspondence retain their stated trust
and production interfaces.

The adopted production replay epoch contributes1,144 forms and292,864
real-CPU/C/canonical cases with all three comparison counts agreeing. Its
main6b3f3173/tagged-writecf27e323/executable5188ecde identities retain
the actual initial283,136 cases and9,728 control-completion cases. The source
ledger now carries16 epochs/222 operation-source rows/163 artifact pins;
62 additional source rows extend124 central operation/token rows.

<!-- COVERAGE END -->

<!-- O4 COVERAGE START -->
O4 coverage adds **21 universal transformation/composition rows** to
[coverage.tsv](coverage.tsv), alongside V's operation/token inventory.
The five appended `o4_*` columns record preservation status, theorem,
evidence, completion obligations and publication. `source-snapshot:` pins the
published source input for component/completion rows; `outside-o4-scope` marks existing
operation/token rows. Operation/token totals
continue to count their own `row_kind` values.

| O4 status | Rows | Scope |
| --- | ---: | --- |
| `proved-conditional` | 7 | x86 kind1 slot/table/record layout, ARM kind3 BL26 slot, private-spill projection, generic block relation, checked-effects composition |
| `trusted-kernel-implementation` | 1 | Exact code, entry, ABI and metadata binding; full Artifact equality is the composition premise |
| `partial-universal-component` | 7 | ARM kind2 near/far body, kind4 per-CPU MRS and kind9 exclusive/marker binding, shared kinds5/6/7 and x86/shared mixed-table layout; production, physical consumer, ABI and ARM layout bridges follow |
| `pending-universal-law` | 6 | Readonly kind8, spill insertion/reload/control, helper ABI, tail calls, actual compiled B and invocation ABI |

All nine production relocation kinds have explicit rows. The seven proved
components carry their production correspondence premises in `o4_completion`.
Their published Lean checks and axiom audits have exit 0 and `sorryAx_count=0`;
the table points to the original source-pinned receipts. The rel32 table/layout
results build on the slot law; the generic block/effect results share one
composition receipt. These row counts measure components, with dependencies
and conditional interfaces retained explicitly.

The next completion steps establish actual producer layout and compiler/frame
preservation, the remaining transformations, and production entry/binding
correspondence. V supplies universal O1/O2 token and definedness laws. The
trusted inputs are accepted-B verifier soundness, the canonical ISA semantics
with F's hardware/QEMU fidelity evidence, and the kernel binding code. V continues these O4 rows and this summary after the three-lane handoff,
alongside the operation/token rows and totals. Historical individual-program
material remains frozen.
Shared kinds5/6/7 now link to
[`generic-native-link-literal.json`](../kprog_tv_20261107/generic-native-link-literal.json):
17 universal audits pass with `sorryAx_count=0`. Stable retained-map resolution,
value-offset bounds/callback addition, checked exact8B bytes/readback, byte
initialization and the canonical read event have proved components. The three
rows retain actual producer/C correspondence, mixed-table layout, physical
consumer and helper/entry ABI completion obligations.

[`generic-native-link-patch-table.json`](../kprog_tv_20261107/generic-native-link-patch-table.json)
adds 18 passing universal audits. Ordered mixed CALL/literal tables retain each
complete consumed span and bound literal value; actual final-code CALL decode
has full-state/effect TV and reverse reflection. Protected original instructions
also keep their exact canonical decode and behavior. Typed u32 intervals derive
physical separation for every5B/8B pairing and64-bit base. The actual Rust
instruction/chunk construction and complete consumer/control/ABI correspondence
supply the production bridge recorded in the two updated O4 rows. The8B literal span
covers its field/data; complete consumer instruction/prefix coverage belongs
to that physical-consumer bridge.

[`generic-native-link-movabs.json`](../kprog_tv_20261107/generic-native-link-movabs.json)
adds nine passing universal audits for the actual fixed10B MOVABS consumer,
all16GPR destinations and every64-bit target. Final mixed-table bytes plus the
protected original header decode to exact bound materialization. Forward TV,
reverse reflection and the relational Step theorem retain the full architectural
successor and empty guest trace; stable map-ID/offset/callback witnesses compose
through the same target. Kinds5/6/7 retain component status while actual producer
header/field/PC/chunk correspondence, other GOT/memory-table consumers and
helper/entry ABI supply the surrounding production stages.

[`generic-native-link-guarded-emission.json`](../kprog_tv_20261107/generic-native-link-guarded-emission.json)
adds 11 passing audits for existing sequential emitter guards. Rel32 checks the
current output; literals check the immutable original. Their shared invariant
preserves every original nonzero byte and derives MOVABS header protection.
Original template bytes then compose with field identity, map resolution and
final-code full-state consumption. Actual producer template/field/PC/chunk
correspondence and mixed-field separation retain their completion steps;
other GOT/memory-table consumers and helper/entry ABI follow. Original nonzero
byte protection and final literal-field identity have their separate invariants.

[`generic-native-link-chunk-layout.json`](../kprog_tv_20261107/generic-native-link-chunk-layout.json)
adds 22 passing universal audits.
Existing binding bounds and the group u32 cursor imply an exact logical byte
partition, natural-number size sum and unique chunk ownership. Serializer
subtraction and checked rebase preserve every selected5B/8B record's complete
target, selector and materialized patch at each64-bit final base. Local field
separation supplies whole-table separation through the derived cross-chunk
law; the global table instantiates canonical CALL TV with full state/effects.
Actual Rust instruction offsets/templates, within-chunk separation, complete PC
partition and physical executable chunk-base/byte identity form the next layout
bridge. Other consumer, ABI, ARM and compiler stages retain their own laws.

[`generic-native-link-byte-layout.json`](../kprog_tv_20261107/generic-native-link-byte-layout.json)
adds 21 passing universal audits.
Ordered encoded pieces with a fitting selected field derive global offsets and
complete-span separation. Exact full-image equality supplies original template
slices. The fixed10B MOVABS piece then derives its PC+2 field member, template
location and complete canonical TV through the existing emitter guards. The
loader's complete-span filter and subtraction preserve local fits/separation;
checked chunk metadata composes the table relation. Arbitrary wire permutations
retain separation and full-state/exact-effect CALL/MOVABS TV. Actual Rust/iced
piece construction, complete record identity/permutation and whole-field chunk
coverage, snapshot/final-image identity and complete control/ABI stages supply
the production correspondence interfaces.

[`generic-native-link-chunk-planner.json`](../kprog_tv_20261107/generic-native-link-chunk-planner.json)
adds 22 passing universal audits.
The exact loader boundary scan advances and retains complete5B/8B fields.
Checked group intervals and safe cuts give each record one complete-span owner.
The actual filter/subtraction/rebase reconstructs the original record table as
a permutation, including exact targets, selectors and multiplicities. Encoded
piece containment now supplies that permutation directly to canonical CALL and
MOVABS TV. Readonly one-byte placement anchors preserve each scan step; current
u32 input/capacity bounds keep size arithmetic inside64-bit size_t. Actual
Rust/iced field/image construction and implementation-value correspondence,
final executable bytes/bases, complete PC/ABI and other ARM forms provide the
surrounding production interfaces.

[`trusted-inline-memory-binding.json`](../kprog_tv_20261107/trusted-inline-memory-binding.json)
records the common x86 binding repair
for compiler `memcpy`: its generated inline accesses now share the existing
registered-service target match with `memset`. Kind1, active capsule and direct
context program-type checks remain in that match. Three fresh8/32/96-byte
copy/fill controls bind and execute with exact bytes/returned pointers; an
unsafe scalar destination reaches the verifier's memory rejection. The existing
19 transport controls retain16 expected refusals. Common-service terminal
archives and earlier fixture diagnostics are retained. This is runtime binding
evidence; C supplies the whole-application replay and V/T supply universal
intrinsic/compiler preservation.

[`generic-simulator-composition.json`](../kprog_tv_20261107/generic-simulator-composition.json)
connects V's unified dispatcher and
O2 body equations directly to `Composition.lean`; 14 universal audits pass.
Canonical decoding binds native PC/site execution, and the common-input encoder
reconstructs the complete native state with its invocation stack origin.
Universal field alignment and definedness transport retain all canonical
successors and exact effects. The same-input token equation gives forward TV
and reverse model reflection. Complete-output branches/MOVE derive exact-state
closure. Actual-native coverage includes every block behavior before the bound
accepted-B checked-effects instance applies. The138 Lean inputs use the recorded
published `ae275afec` epoch plus this adapter;142 source/build pins are retained.
Later V PUSH/POP source/cache evolution is recorded separately. Production
PC/field/definedness/ABI and actual compiled-B/link preservation retain their
universal correspondence interfaces.

[`generic-native-link-final-image.json`](../kprog_tv_20261107/generic-native-link-final-image.json) adds 19 passing universal audits.
The x86 emitter calculates relative targets at `final_ip` and writes temporary
storage. Address translation commutes with the canonical scalar writer and
arbitrary mixed patch tables, preserving the final-PC displacement bits and
bound target values. Scratch-to-instruction, instruction-to-writable-pack and
whole-pack-to-final-text copies compose into exact contained fetches. Canonical
final-code decode and every relational step retain full state, ordered effects
and faults; CALL and MOVABS target laws reach that final image directly. Later
patch tables preserve a native range through write separation. Code-storage
translation applies to fetch bytes; architectural data memory and helpers keep
their original addresses. Actual kernel copy/size/cursor correspondence,
post-finalization fixup separation and executable lifetime remain production
interfaces, alongside complete PC/ABI/compiler and ARM transformation laws.
Reproduce with `make -C kprog/tv native-link-final-image-check`.

[`generic-native-link-arm-bl26.json`](../kprog_tv_20261107/generic-native-link-arm-bl26.json) records 20 passing universal audits for
AArch64 relocation kind3. The aligned signed26-unit kernel guard is equivalent
to exact displacement recovery. The actual signed division,32-bit cast, mask
and opcode OR produce the same four bytes consumed by canonical AArch64.decode.
Reference.Memory readback then supplies the actual written instruction. Forward
TV, reverse reflection and the full-state result set X30 to PC+4 and PC to the
bound target while retaining every other architectural field. The BL step has
an empty guest trace; target helper effects compose through the helper ABI law.
The existing offset/full-span/current-placeholder/kernel-target checks remain
production inputs. Complete field/table layout, final text placement, supported
ABI and implementation correspondence supply the surrounding link stages.
Reproduce with `make -C kprog/tv native-link-arm-bl26-check`.

[`trusted-native-resources.json`](../kprog_tv_20261107/trusted-native-resources.json) records the kernel-owned resource capability
extension for native-referenced application maps. `SUBMIT_RESOURCES` adds an
80-byte envelope around the existing64-byte request and copies a signed32 FD
vector during submission. Kernel `bpf_map_get` resolves and retains actual
objects; the registered service queries their real identities, shapes and
inner templates through the existing MAP interface. Source maps and explicitly
submitted native maps form the authorized set. The capsule shares its resource
lifetime with sealed chunks and bound programs. Existing submission, source
context, verifier and proof provenance checks remain active.

The cached x86 KVM regression passes30 expected refusals,3 positive case
outcomes and1 suite summary. Native-only maps survive application FD closure
and vector mutation, while valid maps outside the submitted set are refused.
Partial-copy/FD/duplicate/copyback failures and request completion release map
references. Both native submission routes retain proof-ELF refusal, and the
application proof-upload/service-registration controls pass. The actual
libbpf lookup API returns `-ENOENT` for released objects; its return and errno
are retained in the raw log. C/A connect this kernel epoch to native-symbol
metadata, coherent loader/service images and whole-application execution.
The generic compiler/ISA/ABI and complete Artifact correspondence laws retain
their separate proof stages.

[`generic-native-link-arm-helper.json`](../kprog_tv_20261107/generic-native-link-arm-helper.json) records30 passing universal audits
for the legacy ARM kind2 helper body. Actual MOVNlow/MOVK16/MOVK32/BLRx10
words decode through the canonical AArch64 ISA. Four ordered u32 stores retain
every complete instruction word. The existing load-time signed-range choice
selects either the single BL plus its three preserved NOPs, or the four-word
far body. Both bodies have full-state/exact-effect TV for every finite prefix
and reverse reflection through `Composition.lean`'s token/block closure.

Canonical materialization proves the exact low48 reconstruction and target
equality precisely when the upper16 bits are all ones. The supported far-entry
result sets X10 to the target, X30 to PC+16 and PC to the target. Near BL uses
X30=PC+4; its original three NOPs advance the returned state to PC+16. These
architectural differences remain explicit for the helper/caller ABI law.
Kind2 has component status while actual field/table/final-image correspondence,
the supported helper-pointer profile and complete callee/entry ABI compose the
surrounding production stages. Current kernel target checks cover the negative
pointer half; `Kernel48` identifies the exact far-encoding equality interface.
Reproduce with `make -C kprog/tv native-link-arm-helper-check`.

[`generic-native-link-arm-helper-guard.json`](../kprog_tv_20261107/generic-native-link-arm-helper-guard.json) connects the actual far-writer
acceptance check to exact target reconstruction. The kernel writer checks the
upper16 target bits before its four stores and returns `ERANGE` for targets
outside that encoding range; the caller propagates this through the existing
JIT error path. Every accepted far entry reaches the bound target. Near BL keeps
its existing range choice and link address. Nine universal Lean audits pass;
accepted emitted bytes supply the same block TV and reverse execution relation.
The source-extracted C writer passes262,144 cases on the host and262,144 on
AArch64 QEMU user mode with UBSan: each has65,539 accepted targets retaining
prior bytes and196,605 refused targets retaining buffer canaries. This closes
the far-address representability interface. Actual whole-module adoption,
field/table/final-image correspondence and complete helper/caller/entry ABI
supply the remaining production stages. Reproduce with
`make -C kprog/tv native-link-arm-helper-guard-check`.

[`generic-native-link-arm-placement.json`](../kprog_tv_20261107/generic-native-link-arm-placement.json) records12 passing universal audits
connecting ARM word-index emission to final byte PCs. Aligned offset division,
physical image/start-index positions and final-slot positions agree exactly.
The complete16B bound covers all four helper words. The same canonical scalar
stores commute with the temporary-storage view; near BL bits use the final PC
while the physical write location moves. Successful checked near/far emission
then supplies its canonical block TV and reverse execution relation at final
executable addresses, for every finite prefix and complete architectural state.
The ARM scratch-word loop and whole-pack finalization compose through explicit
byte-copy relations. Actual C copy/cursor/field extraction, final-fixup separation,
executable lifetime and complete helper/caller/entry ABI form the surrounding
production interfaces. Reproduce with
`make -C kprog/tv native-link-arm-placement-check`.

[`generic-native-link-arm-exclusive.json`](../kprog_tv_20261107/generic-native-link-arm-exclusive.json) records16 passing universal audits
for kind9's exclusive-byte and proof-marker binding components. Every accepted
STXR/STLXR word selects the canonical width, release bit and status/data/base
registers. The exact native site retains full architectural state, ordered
effects and faults, with forward block TV and reverse reflection for every
finite prefix. Full32-bit descriptor index/source-PC fields round-trip.

The exact one/two-word proof scanner advances monotonically, excludes every
LDDW continuation from its instruction boundaries and fits the kernel's current
one-million-instruction u32 bound. The bound BPF marker consumes the complete
source PC and current dynamic visit, advances the visit once, and preserves the
remaining state. The verifier's fresh `[0,1]` scalar interval represents exactly
both Boolean outcomes. The existing C++ regression passes131,072 actual kernel
matcher width/order/register triples, plus continuation and following-boundary
controls for all four width/order forms. Actual byte/field/scanner correspondence,
sealed-group descriptor coverage, dynamic platform exclusive inputs and complete
specialized-body/compiled-B/PC/ABI composition supply the remaining production
interfaces. Reproduce with
`make -C kprog/tv native-link-arm-exclusive-check`.

<!-- O4 COVERAGE END -->



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

Validation: Lean93/93,12 existing contracts and dispatch-model checks pass;10 of13
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

## Actual D0 byte-field gates composed after pair transfers

`dispatchThroughD` adds LOAD_D0 and STORE_D0. Actual LOAD base is SRC,
STORE base is DST, SRC2 is index, and the unused other operand/SRC3 bytes
remain arbitrary. FLAGS is fully unused for these gates: neither width nor
bank is taken from it. `dByteBody` composes the real pre/access/post sequence
with the existing generated eight-byte D-success primitive, retaining low
lane transfer and generated high-half clearing.

Immediate offset/pre/post and native UXTW/SXTW/LSL/SXTX indexed forms share
the original canonical vector-memory specification. Indexed forms retain
scale3, ZR, NONE255 and omitted unscaled X modifiers; base31 maps to SP32.
Derived byte/core equalities and the single
`step_through_d_observed_refines` theorem preserve all prior cases, exact
eight-byte events/init/full state and one PC advance. `DBinding` contains
field identities; `vectorMemoryAccess` separately retains original-native SP
alignment and read/write permissions. No shadow-derived permission, runtime
guard or component semantic equality premise is introduced. Existing
exclusive observation/environment and pair profile witnesses stay explicit.

Validation: Lean93/93,11 existing contracts and dispatch-model checks pass.
Nine of15 existing hosts pass (including9504 DQ and9504 vector-value cases);
six existing route hosts fail compilation at the same production unmapped-XDP
read branch: dq_mem, dq_mem_extra, vreg, vreg_field, mem_base_src and
mem_prepost. Failed stale binaries were not executed. Their exact commands,
exits and original log are appended to the integration receipt/archive.
Three new proof audits report only propext/Classical.choice/Lean.ofReduceBool/
Quot.sound; all previous declarations remain byte-identical, with no
placeholders or ISA/runtime/oracle/test changes. Proof SHA256:
`27f3c854152e76cbc8984787171455466473ddbcd4f8a82946253d4d5694406e`.

The complete check is still failed at exact967's immutable snapshot, not
rerun or declared passed. A owns the forward production integration repair.
Q0's two C eight-byte events versus the canonical16-byte event, faulting
writeback, remaining vector/control operations, full77/72 and native producer/
compiled-body/Entry/O2/O4 transport remain open.

## Q0 raw lane core and proved architectural observation

`Arm64VectorMemory.qSuccess` retains two separate ordered8-byte events and
the actual low/high value and memory updates. `joinQEvents` joins only exactly
two same-direction events at consecutive8-byte addresses with both lengths8;
every other shape passes unchanged. `q_byte_positions` proves conservation
of every ordered byte's access kind, wrapping address and value. Read bytes
and initialization concatenate exactly; high store bytes are proved by bit
extensionality, without adding an axiom or relying on the solver that failed.
`observeQ` preserves the entire state and fault fields.

`q_success_observation` derives the grouped16-byte event from the original
raw lanes; no semantic equality is supplied by callers. Successful Q0
pre/access/post bodies then refine the SAME canonical vector-memory step
through `q_writeback_observed_refines`, with original-SP alignment and
all16 original-native read/write permissions explicit. This closes the
sequential successful core's event-grouping/value/init/writeback obligation.
It does not establish hardware single-copy atomicity, concurrency/order,
faulting writeback, producer/compiled-body transport or Q0 global dispatcher
reachability; those remain separate. No ISA/runtime/oracle changes.

Validation: Lean27-job vector target and93-job dependent dispatcher target
pass;8 proof-axiom audits report only propext/Classical.choice/Quot.sound plus
the existing Lean.ofReduceBool dependency. Nine existing contracts and dispatch-model
checks plus6 of10 existing semantic hosts pass (9504DQ,21extra,9504vector,
7field,20168offset,4608pre/post cases). Four unchanged dynamic route hosts
(dq_mem,dq_mem_extra,vreg,vreg_field) fail compilation at the production
unmapped-XDP branch; failed stale binaries were never run. All8 pinned
source files stayed unchanged during checks; old declaration bytes are
identical. Exact proof SHA256 `c9cc458244547e07a068dcfcad90d1ea5c7c549555bfeb89240343570248da0d`.
Full original focused log and command/source pins are appended to the
existing integration archive/JSON. The prior immutable967 full remains
EXIT2, no repeated full or full-pass claim. A owns that forward integration
repair; full77/72/O2/O4 completion remains open.

## Actual Q0 gates and combined observed dispatcher step

`dispatchThroughQ` now adds the actual LOAD_Q0/STORE_Q0 gates after D0.
Raw FLAGS remains unused; bank0 and16 transferred bytes are fixed. LOAD
uses physical SRC base, STORE uses DST, both use SRC2 index, and unused
integer fields/SRC3 remain arbitrary bytes. The numeric body retains both
8-byte accesses; `observeQDispatch` applies the previously proved checked
event grouping only to those two Q codes. Earlier rows preserve their raw
transitions and exclusive ghost observation unchanged.

`QBinding` contains only native/encoded field identities. Derived core
equalities cover immediate offset/pre/post plus indexed UXTW/SXTW/LSL/
SXTX, native Q scale4, ZR, NONE255 and omitted unscaled X modifiers. No
scalar-width surrogate is used for Q indexing. The single
`step_through_q_observed_refines` theorem composes all preceding gates and
these forms with separate original-native vector access/SP permissions.
Successful sequential byte/event/state/writeback composition is proved;
hardware atomicity/concurrency, faulting writeback, producer/artifact/O2/O4
transport, remaining vector/control families and full77/72 remain open.

Validation: Lean93-job dispatcher,5 axiom audits,10 existing contracts,
dispatch-model check and ALL14 existing semantic hosts pass:
9504DQ,62418DQroute,21extra,62424extra-route,9504vector,62445vector-route,
7field,62427field-route,20168offset,4608pre/post,512index,22115index-route,
17index-value,3015index-value-route. All8 source pins stayed unchanged.
Prior declaration bytes remain identical; no placeholders, new tests,
ISA/runtime/oracle edits. Exact dispatcher SHA256 `1a2a8534e6fe9ac4e69e83089709f5d8d33b6a91aff60698acafcef9667e2479`.

This focused run uses A's entry-selector header repair WIP, SHA256
`d382995ce88de3076d4c7650566d3a5961733c2a624becd8c8de3ddb08118126`,
not the previous published failing header. Owner publication and the new
immutable complete check are still pending at this checkpoint. The earlier
full EXIT2 and all failed logs remain intact; they are not relabeled as a
pass. Complete new command exits/source pins and original PASS log are
appended to the existing integration JSON/compressed archive. V does not
commit A's header or change a host model/guard to obtain this result.

## Actual FMOV/reduction tail and complete L_EXEC observed step

`dispatchExec` now follows every actual L_EXEC branch gate through the
final FMOV/CNT/UADDLV cases. `fmovByteBody` uses physical byte reads/writes
and generated direction/value/destination selectors. Every inactive integer
operand/SRC3/IMM remains arbitrary; vector bank selection is independent of
GPR/ZR, retaining all32 banks and legacy NONE255→bank0. Whole AUX selects
the four directions. Vector destinations ignore FLAGS, retain S_FROM_W
low32 truncation and clear high64; integer destinations use raw FLAGS with
native W/X width. Reduction ignores all integer fields/FLAGS/IMM and tests
the complete AUX word for16, retaining low-only/wide CNT/UADDLV behavior.

The single `exec_observed_step_refines` theorem derives the entire L_EXEC
branch composition through field-only `ExecBinding`. It preserves preceding
Q-byte observation, exclusive ghost/environment, native access/SP/pair
profile witnesses and complete state/events. No caller assumes component
semantic equality. This completes the modeled numeric L_EXEC branch order;
it is NOT the outer control/helper/native-entry/return step theorem or
full72/77/O2/O4/compiled-artifact/platform completion. Faulting writeback
and concurrency/atomicity/entry permission transport remain open.

Validation:98-job Lean dependency graph,5 axiom audits,10 existing contracts,
dispatch-model check and ALL16 existing semantic hosts pass:
20145FMOV,256destination,20017reduction,21reduction-route,40080width,
1280effective-width,257register,6401register-route,586829AUX,1115374AUX-route,
62418DQ-route,62445vector-route,3804immediate-operand-route,686110STLXR-route,
122891pair-route,135170pre/post-route. All8 source pins stayed unchanged;
all earlier declaration bytes are identical except the added Reduction
import. No placeholders/new tests/ISA/runtime/oracle edits. Proof audits
report only propext/Classical.choice/Lean.ofReduceBool/Quot.sound.
Dispatcher SHA256 `183be56113e11495b4a6887459e846d151f6a6aea7581ab0dfd777917ff2a8e1`.

This run still uses A's pinned entry-selector header repair WIP, SHA256
`d382995ce88de3076d4c7650566d3a5961733c2a624becd8c8de3ddb08118126`.
Source-owner publication and a new immutable full check are pending; the
old exact967 full EXIT2 is retained unchanged. All commands/source pins and
complete original output are appended to the existing integration receipt
and compressed log. V commits only its proof/doc/result paths.

## Outer direct branches composed with L_EXEC

`Emission` models the production emitter's choice between numeric L_EXEC
and the separate B/B.cond/CBZ/CBNZ/TBZ/TBNZ C macros. It is not an ISA
decoder or another numeric opcode table. `dispatchEmission` composes their
actual predicate, register byte, W truncation and low6 bit-mask behavior
with every preceding L_EXEC case in one `emission_step_refines` theorem.
Native NV15 retains its actual AL normalization, and the actual forward/
backward code shape is selected using source-label coordinates.

`EmissionBinding` contains encoded/source/current/lexical-next/target address
identities. The label→native-PC map remains explicit: source coordinates
are not assumed to be native runtime addresses. No branch-outcome or
component semantic equality premise is introduced. Original-native access/
exclusive/pair/vector witnesses remain separate for L_EXEC. Calls, ADR/code
tokens, indirect/RET/helper/entry/compiled-body/platform transport and
full77/72/O2/O4 remain open. In particular the current CODE materializer
leaves source tokens unchanged, unlike STACK/RETURN bases; real code-word
transport cannot be silently inferred for the next call/ADR proof.

Validation:98-job Lean graph,3 axiom audits,8 existing contracts, model
check and ALL12 existing semantic hosts pass:80256branch,64emit,1201emit-route,
240condition,80condition-decode,40080width,1280effective-width,257register,
6401register-route,586829AUX,1115374AUX-route,3804immediate-route cases.
All9 source pins stayed unchanged, all previous declaration bytes are
identical, and no placeholders/new tests/ISA/runtime/oracle edits appear.
Proof SHA256 `027adbfbfbdf8cf8d361a88439da8a799f569260e59e170ab5dd5f6b27744edd`.

The publication waiter froze exact
`900422f7c3a4cc364f1597f76aefc5a583e3c32a` after A published its tested
ARM entry-selector repair. That full `make check` exits **2**, at
Makefile176 / `tools/check_x86_popcount_memory.py`; the generated dynamic
C harness triggers `x86_sim_unmapped_xdp_read` at x86 header941. It includes
published L_EXEC/Q proofs and the ARM repair, and predates this direct-
branch extension. C/A own the forward integration investigation; no oracle
is skipped or weakened. Original complete logs/source manifest are appended
to the existing compressed archive, with exact pins and focused exits in JSON.

The private full runner initially recorded the correct make EXIT2 but
returned Python0 to its waiter. Its status propagation is now fixed; the
waiter metadata was corrected from the authoritative make exit/log. This
was never a complete-check pass. Immutable export was deleted automatically;
shared caches and permanent STOP are retained.

## Source CODE tokens and derived internal-call observation

`CodeState` retains the actual source-token GPR payloads and CODE-tag mask.
It layers over the existing numeric observation of non-CODE stack/return/
data fields. `nativeCodeView` uses the bound source-label→native-byte map
to materialize only CODE cells and PC; no second ISA or decoder is added.
`native_code_write/read/pc` derive the exact complete-state correspondence
for actual GPR/ZR token/tag writes, reads and control transfers.

`source_call_observed_refines` proves LINK plus goto against canonical BL,
using exact target/successor layout identities.
`source_address_observed_refines` proves the emitted ADR CODE write and
fallthrough against canonical ADR. `code_target_observed_refines` proves
the actual CODE-tag finite-target BR/BLR/internal-RET arm against the same
canonical register branch, with the incoming target captured before LINK,
including BLR X30. CODE-tag and finite-membership premises are the actual
branch guards; no component semantic equality is assumed. The unlinked
arm imposes no successor-address condition. Full numeric state and empty
guest-event/fault effects are retained under the explicit observation.

These primitive proofs preserve original raw source tokens. Current C
READ_REG materialization still leaves CODE unchanged, so the projection
alone establishes no ordinary code-pointer arithmetic/memory transport,
source/native layout identity, compiled-body correspondence or arbitrary
program composition. Untagged helper and outer RETURN-tag paths remain
separate; no path is silently reclassified as a successful no-op/rejection.
Full77/72/O2/O4 and the outer invocation/return interface are not complete.

Validation: Lean98-job graph,6 axiom audits,7 existing contracts/model
checks and ALL9 existing semantic hosts pass:13call/ret,1201branch-route,
257register,6401register-route,40080width,1280effective-width,586829AUX,
1115374AUX-route,3804immediate-route cases. All9 source pins stayed
unchanged; all prior declaration bytes are identical, no placeholders/
new tests/ISA/runtime/oracle edits. Exact proof SHA256
`512312c97fc9321ae3abee94653607b9d56675a1cb2e88036eeb45528118fc85`.
Complete original output/commands/source pins are appended to the existing
integration archive/JSON. Exact900 full EXIT2 remains the complete-check
result; no redundant full was started against its unchanged x86 harness
failure. Private status propagation is fixed; shared caches/STOP retained.

## One observed source-emission interface

`SourceEmission` joins prior numeric/direct branch emissions with the
proved source-token LINK/ADR/CODE-target arms.
`source_emission_step_refines` is one step theorem over that interface and
the SAME canonical ISA. Its `SourceBinding` retains layout and actual CODE/
finite-target guards; original-native permissions, SP, pair profile and
exclusive environment remain separate. Each case reuses a proved primitive,
with no handler semantic equality supplied by the caller.

This composes the modeled emission families, while ordinary code-word
arithmetic/memory and compiled-frame/native-layout/ABI transport remain
explicitly unproved. Untagged helper and outer RETURN-tag interfaces are
still separate. The theorem does not complete full77/72/O2/O4.

Fresh validation:98-job Lean target and one axiom audit PASS, reporting only
propext/Classical.choice/Lean.ofReduceBool/Quot.sound. All9 input pins stayed
unchanged; non-proof inputs are byte-identical to the preceding CODE proof
check. Its9 existing C-host results are reused without repeating them for
this composition-only change. Old declarations remain byte-identical, with
no placeholders/new tests/ISA/runtime/oracle edits. Proof SHA256
`689a2e46aae8d849ce59844a15673ef378b7ea7521bcf76f4e1a88f525e467d6`.
The fresh original proof log and source/predecessor pins are appended to the
existing integration archive/JSON. Exact900 full EXIT2 remains unchanged;
no new full was run against its unresolved dynamic x86 host failure.
## Actual outer RETURN and finite CODE return routes

`returnCodeState` materializes RETURN offset cells using the authenticated
same-invocation outer LR and leaves CODE source tokens for the existing
layout observation. `returnRoute` follows actual RET_TO branch order and
tag bytes: raw zero plus RETURN10 selects outer exit; CODE9 plus finite
membership selects an emitted goto; other inputs retain rejection. The
producer emits those per-site cases as gotos. ZR has no tag cell.

`return_route_observed_refines` derives the exact same canonical register
branch for every successful route and every source register, preserving
all other numeric state/events. Its route premise is the concrete macro
guard, never component semantic equality. Outer PC is an explicit
continuation observation; this does not certify the physical C return.
`outer_return_value` separately derives the actual low32 materialized X0
result, with ordinary CODE data transport still explicit through its
not-CODE condition. SKB cb synchronization, physical ABI/continuation,
helper effects, compiled bodies and full77/72/O2/O4 remain open.

Validation:98-job Lean dependency graph,4 axiom audits,2 existing register
contracts/model check, and the existing13-case CALL/RET host under UBSan
all pass. All9 source pins stayed unchanged, earlier declaration bytes
are identical, and no placeholders/ISA/runtime/oracle/test edits were
introduced. The two failed proof-normalization attempts and complete final
commands/output/source pins are retained in the existing integration
archive/JSON. Exact900 full `make check` EXIT2 at the x86 dynamic POPCNT
harness remains unchanged; no redundant full was run against that failure.
Proof SHA256 `5cbf3b6a9f1cd4d0d20c2604976cb81985a1ecf87b9ad11b72b722491abd63c3`.

## One observed invocation-emission step

`dispatchInvocationEmission` puts prior source emissions and actual RET_TO
routes under the same invocation RETURN/CODE frame. Its single
`invocation_emission_step_refines` theorem combines numeric L_EXEC,
direct branches, source-token LINK/ADR/finite CODE branches, and both
outer RETURN and finite CODE return routes against the SAME canonical ISA.
`InvocationBinding` contains prior layout/field relations or literal raw-zero,
tag and finite-target guards. It assumes no component transition equation;
native access/SP/profile/exclusive premises stay separate.

This is a modeled observed step, not a full72/77 or O2/O4 completion claim.
Ordinary CODE-word data transport, compiled/native frame and layout,
helpers, SKB exit copies and physical ABI/continuation remain open.

Fresh98-job Lean target and one axiom audit pass with only propext,
Classical.choice, Lean.ofReduceBool and Quot.sound. All8 pins stayed
unchanged; non-proof inputs and the preceding13-case UBSan CALL/RET host
source are byte-identical to the published return-route check, whose host
result is reused without rerunning it. Prior declarations remain identical;
no placeholders/ISA/runtime/oracle/test edits were introduced. Exact proof
SHA256 `861aa645b1a0820dc61aa67632c8b26966f474f210b4e972fe699f1d76d861f5`.
Complete original proof output/commands/source pins are appended to the
integration archive/JSON. Exact900 full EXIT2 remains unchanged.

## x86 raw stack-register frame and MOV transport

`X86NumericAddress.RegisterState` retains raw register cells plus the STACK
predicate over the existing memory/flags/PC observation. The native view
adds the invocation stack origin to RSP's offset, and translates other STACK
arena pointers using pointer-minus-arena followed by native-base addition.
The origins are independent. Actual generated STACK_PTR arithmetic keeps
all64 offset bits and its biased origin is related without a32-bit window.

The numeric write proof composes the generated lane writer with the actual
byte/word materialize-before-merge sequence, dword zero extension, qword
replacement and one destination-RSP normalization. Full MOV retains the
actual destination-RSP numeric arm, source-RSP arena rebind and other raw
pointer/tag copies. The derived immediate/register MOV steps preserve the
entire canonical state/events for every width, high/low lane and alias,
including self MOV and RSP as either or both operands. Only the STACK
predicate is represented; other provenance and the initial ABI/private
memory/compiled-B relation are not certified by this component.

Validation:17-job Lean graph and7 axiom audits PASS, reporting only propext,
Classical.choice, Lean.ofReduceBool and Quot.sound. Four existing generated
contracts and all three existing MOV hosts pass under UBSan:100448 handler,
72866 arm-route and23396 full-route cases. All7 proof and11 host input pins
remain unchanged; earlier declarations are byte-identical except imports.
No ISA/runtime/oracle/test edits or proof placeholders. Complete original
failed proof-normalization logs and final commands/output/pins are appended
to the existing integration JSON/gzip. Full exact900 `make check` EXIT2 at
the unresolved dynamic x86 POPCNT harness remains unchanged; no redundant
full was run. Full77/72/dispatcher/O2/O4 completion is not claimed.
Proof SHA256 `9185aa823802161136a3ea98a76eb032ee98b22c12972751d305e86fb768f63b`.

## x86 register CMOV through the raw stack frame

`conditional_move_frame_refines` composes actual register CMOV branches with
the same RSP-offset/STACK-arena native view. It derives the condition from
complete native RFLAGS through the existing generated condition theorem;
no branch-result premise is introduced. Taken64 uses the RSP-aware pointer
MOV path, taken16/32 use the numeric writer, false32 writes and zero-extends
the old native value, and false16/64 preserve the representation. All typed
conditions, legal widths, source/destination/self aliases and all other
architectural state/events are retained. Initial ABI/private-memory,
compiled-B/whole-dispatch/full77/72/O2/O4 obligations remain open.

Lean49-job graph and one axiom audit PASS, with only the existing propext,
Classical.choice, Lean.ofReduceBool and Quot.sound dependencies. Older
proof declarations are byte-identical except the CMOV import. The focused
canonical reference includes F's FF/4 decoder-only work; its complete typed
semantics prefix is byte-identical to published HEAD, and V changes no ISA.
All7 proof source pins stayed unchanged.

Fresh canonical UBSan checks: three contracts and the existing484369-case
CMOV handler host PASS. The unchanged route host FAILS at source405,
expanding `X86_SIM_L_LOAD_PTR_ADDR`'s misaligned volatile pointer load. That
failure is preserved. A PRIVATE host-only aligned(1),may_alias pointer type
candidate passes the SAME484369 handler and26526735 route cases; the route
oracle body changes only its header include at the original include point.
Both __BPF__ and __bpf__ preprocessed translation units are BYTEIDENTICAL
to the canonical header. This is preprocessing equality, not compiled-BPF
execution evidence. All candidate/canonical pins stay unchanged.

The candidate is NOT promoted: C owns the shared header and its pinned
census inputs. Its exact patch and complete source/logs/commands, the initial
failed force-include setup, original UBSan failure and repaired candidate
are archived separately in the existing integration JSON/gzip. The canonical
host cache binary was restored by compilation without reexecuting its known
UBSan failure. No shared header/ISA/runtime/oracle/test edits or sanitizer
skips. Full exact900 POPCNT compile EXIT2 remains a separate unresolved
complete-check result. Proof SHA256 `80efca20fcb8480e935eb9d0503873001c02a4142929d0fa8bd0888a1fa0f747`.

## x86 XCHG operand snapshots through the raw stack frame

`writeCapturedPointer` separates the immutable input snapshot from the current
destination state. Its complete native-view theorem derives RSP scalar
normalization and other-cell pointer/STACK writes from the captured input,
while retaining all current fields outside that destination. The generated
XCHG selector then composes two such pointer writes at64 bits, or two numeric
writes at8/16/32 bits. Both input values are captured before the first write;
the second partial destination merge observes the state after it.

`exchange_register_frame_refines` reuses the existing canonical X86Exchange
step for low register slices at every width and every register alias,
including source/destination RSP and RSP/RSP. It assumes no disjointness or
caller-supplied captured-value equality. This is the low-slice register
handler; high-byte producer routing, initial ABI/private-memory/other
provenance, compiled B and full77/72/dispatcher/O2/O4 remain separate.

Lean52-job graph and3 axiom audits PASS with only propext, Classical.choice,
Lean.ofReduceBool and Quot.sound. Three existing generated contracts and both
existing XCHG hosts pass under UBSan:260 handler and62725 route cases. All7
proof and9 host input pins stayed unchanged. Older declarations are identical
except the Exchange import; no placeholders/ISA/runtime/header/oracle/test
edits. Complete failed normalization attempts and final commands/output/pins
are appended to the existing integration JSON/gzip. The known full exact900
POPCNT compile EXIT2 and separate canonical CMOV-route unaligned-pointer UB
remain unresolved; no full pass or private-candidate promotion is claimed.
Proof SHA256 `73b1487713565e8e1fe0c9b405edb5f28cf33f8329e7fb8804c118519c9684ca`.

## XCHG encoder admission matches the low-slice refinement

The existing production encoder's early high-byte guard rejects AH/AL and
other high-byte XCHG operands before the later XCHG field branch is reached.
Inspecting that later branch alone suggested a possible dropped-lane bug;
the actual encoder call disproves that admission assumption. No accepted
semantic counterexample was obtained, and no C/native/reference execution
ran for the rejected probe. The first import-path setup failure and subsequent
actual ValueError are retained as different investigation outcomes.

A finite check of all16x16x4=1024 low-register width pairs verifies actual
producer opcode, destination, source, width and AUX0 fields. Six existing
high-byte rejections are retained verbatim. This confirms the existing
accepted-field boundary of the low-slice XCHG frame theorem; V introduces
no new rejection or coverage exclusion. It is an encoder-field test, not
a proof of Python/compiler correctness or a native execution certificate.
All five source pins remained unchanged. Complete records and original
probe diagnostics are in the existing compressed integration archive;
JSON stores the summary and source/archive hashes without duplicating all
1024 rows. Production source, ISA, oracles and tests remain untouched.

## x86 raw-field NOP/MOV dispatch prefix

The new `Refinement/X86Dispatcher.lean` uses the generated opcode table,
GPR-cell contract, width fallback and AUX getters. `MoveBinding` consists
only of encoded fields and native operand/next-PC/immediate identities.
`step_through_move_refines` derives one complete canonical step for NOP,
MOV-immediate and MOV-register under the published raw stack-register frame.
The production pointer-load/libc/helper gates before MOV are explicitly
retained as unproved branches. No handler equation or state/value equality
is an assumption. Other operation bodies and compiled/native ABI/private
memory transport remain open; this is not the whole77-operation theorem.

GPR byte selection agrees with the generated contract on every byte,
including absent16..255. Legal FLAGS retain absent0->64. Byte lanes retain
low GPRs and high AH/CH/DH/BH slices; wider MOV ignores unused lane bytes.
NOP ignores all operand/width/AUX fields and MOV-immediate ignores SRC.
`None` denotes an unproved or out-of-binding interface case, not a new
runtime guard, rejection or successful no-op for malformed fields/opcodes.

Validation: focused56-job Lean graph and5 axiom audits PASS; only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies occur.
Six existing generated checks and all five existing field hosts pass under
UBSan:258 register,6401 register-route,7629 AUX,1280 width,518 width-route.
The default incremental `lake build KProgFormal` library target also passes
(371-job graph); a cached follow-up includes the root entry in all371
unchanged source pins. All369 library Lean source files pass the code-token placeholder audit after nested
comments/strings are removed. Shared caches are retained. No new test,
ISA/runtime/header/oracle or build configuration changes were made.

All original focused normalization failure and successful build/contract/
C-host/library output, source hashes and commands are appended to the
existing integration JSON/gzip. Full exact900 `make check` POPCNT EXIT2
and the separate canonical CMOV-route pointer-alignment UBSan failure remain
unresolved; no complete-check or whole77/72/O2/O4 pass is claimed.
Proof SHA256 `63c715ee643a0754de4b703e8e87f10ea4e0c0849b62c91a3883d3e1ac639823`.

## Single canonical LEAVE64 for the actual JIT tail

The existing X86 reference now decodes C9 LEAVE64 and executes its implicit
8-byte read at incoming RBP. Only a successful read commits RSP=oldRBP+8,
RBP=loaded word and the fall-through PC. A read fault retains the complete
input state, including old RSP/RBP, with the original fault effect. Every
outcome preserves memory and all flags. Five public decode/success/fault/
unreadable/frame lemmas let T reuse this same rule in wrapper certificates.
Old reference declarations are retained; only the new instruction cases
extend decode, step, fall-through and defined-flags selection.

[Intel SDM Vol2A, LEAVE](https://cdrdv2-public.intel.com/812383/253666-sdm-vol-2a.pdf)
and F's published hardware receipt `1e18c95cbabc07a19e2c6d31daa661754882ae87`
provide the operation and fault evidence. Its8192 saved states include4096
successes and4096 faults preserving every incoming GPR; a valid frame works
even with a noncanonical OLD RSP. F retains the concrete #PF/#SS traps and
raw delivery flags. The shared memory abstraction represents the failed
stack read; concrete trap delivery, including RF, is a platform obligation.
No simulator LEAVE handler or complete JIT/ABI/O2/O4 result is inferred.
16-bit LEAVE remains outside this extension; no previously accepted form is
removed. F owns independent replay of those same saved states against this
canonical executable; that comparison is pending at this publication.

Default incremental `lake build` passes its378-job graph, including every
library module and the relinked reference executable. Five axiom audits
report only propext and Quot.sound. The corrected physical-source manifest
includes all library files and entry/configuration inputs, with no source
drift; the first successful build's shared-index manifest omission of the
new X86Dispatcher is retained and corrected by a cached follow-up. Original
syntax failures and every successful command/output/source pin are retained
in the existing integration JSON/gzip. No header, generator, oracle, test,
build configuration, paper, shared cache or other ISA semantics change.
The separate full exact900 POPCNT compile EXIT2 and canonical CMOV-route
unaligned-pointer UBSan failure remain open; this is not `make check` PASS.
Canonical source SHA256 `9fca3291b55b8ef0bfdfa8fab8afe8935210e5fd30f6c0314f7db53661b7afa8`; validation pins 372.

## All16 CMOV conditions through the raw register frame

`conditionalMoveWord` follows the existing generated full-condition table
on the complete32-bit AUX word, including parity/even and parity/odd.
`conditional_move_word_frame_refines` composes that evaluation with the
actual64-bit RSP-aware pointer write,16/32-bit numeric writes and false32
zero extension. Widths, aliases, STACK predicates and every incoming flag
bit remain arbitrary. The native condition code supplies an encoded AUX
identity; no branch-result or state/value equality premise is introduced.
Unsupported whole words retain the implementation false default, without
adding a producer/runtime restriction or truncating AUX to a byte.

The older14-condition proof and all other previous declarations are retained
byte-for-byte except one import. Focused58-job Lean graph, including the
existing X86Dispatcher consumer, and one axiom audit PASS (only propext,
Classical.choice, Lean.ofReduceBool, Quot.sound). The existing full-condition
generated-contract check and existing full-condition C host pass under
UBSan. All physical proof/host input pins stay unchanged. Complete initial
proof-normalization failure and final commands/output/manifests are appended
to the existing integration JSON/gzip. No ISA, header, generator, oracle,
test, build configuration or paper changes. Whole dispatcher, compiled B,
initial ABI and full77/72/O2/O4 remain open; no full `make check` is rerun
against the unchanged POPCNT harness compile failure or separate CMOV-route
unaligned-pointer failure. F's newly published LEAVE fault-kind discrepancy
is separately acknowledged for the canonical owner correction, not hidden
by this CMOV proof.

## Joined raw register dispatcher for MOV, CMOV and XCHG

`register_dispatch_step_refines` joins the existing NOP/MOV prefix to the
later generated singleton gates for register CMOV and XCHG. Every generated
opcode identity is distinct; intervening unproved opcode bodies stay outside
the partial dispatcher, without a new runtime guard or a successful-no-op
claim. The same canonical whole-state step uses the raw RSP/STACK frame.

RegisterBinding carries encoded opcode, width, GPR bytes, next-PC and native
operand identities only. CMOV uses complete32-bit AUX and all16 conditions,
including parity, with the actual64-bit pointer arm and false32 clearing.
XCHG ignores AUX/immediate at every width, as its production handler does;
both operands are captured before either write. All aliases and RSP source/
destination cases remain covered. MOV high/low-byte bindings are retained.
No handler-semantic, condition-result, state-value or register-disjointness
premise is added. The producer's earlier high-byte XCHG rejection is already
recorded separately; no admitted form is excluded by a new producer rule.

Focused58-job Lean graph and two axiom audits PASS with only the existing
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies; all372
physical proof/configuration pins remain unchanged. Original declarations
are byte-identical; no ISA/runtime/header/generator/oracle/test/configuration
changes. Existing underlying CMOV/XCHG hosts and raw-field checks are the
separately recorded evidence, not silently rerun or counted as new cases.
Full logs/audits/commands/pins are appended to the existing integration archive.
All other x86 handlers, all77/72 completion, compiled B, initial ABI/O2/O4,
full-check POPCNT and CMOV-route failures remain open. The strict LEAVE
noncanonical fault-kind discrepancy likewise awaits its canonical correction;
this proof does not coarsen or hide that hardware failure.

## BSWAP and POPCNT through the raw register frame

`byte_swap_register_frame_refines` composes materialized native reads,
generated byte reversal and scalarizing32/64-bit writeback with the same
canonical BSWAP step. `population_count_register_frame_refines` similarly
composes16/32/64-bit source narrowing, generated population count, all six
flag outputs and writeback. Both retain the full native state, PC and ordered
effects through the raw RSP-offset/STACK-arena frame. RSP may be either
operand; POPCNT source/destination aliases still use the original source
for the result and flags. BSWAP preserves every incoming flag. The flag-cell
projection is separately proved; no numeric-state or computed-result premise
is supplied. Older declarations are identical except two imports.

Focused86-job Lean graph and three axiom audits PASS, using only the existing
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. Three
existing generated-contract checks and five existing hosts pass under UBSan:
20028 reversal,6802 BSWAP route,40009 count,4 flag-table and5940 flag-route
cases. Compiler warnings remain verbatim in the archive. All372 physical
proof pins and every compiler-discovered local host dependency remain
unchanged. Original failed proof normalization, final commands/output,
source hashes and audits are appended to the existing integration JSON/gzip.

No ISA/runtime/header/generator/oracle/test/configuration changes or new
private build tree. Memory-source proofs, compiled B, initial ABI, full
77/72 operations and whole-dispatch/O2/O4 remain open. The unchanged full
POPCNT-memory compile failure and separate CMOV-route unaligned-pointer UB
are not retested or hidden by these register-only results. F's new33792
LEAVE boundary observations show why the private canonical-span candidate
is not yet promoted: an actual userspace LASS profile adds stack faults for
upper-canonical addresses. Fault-profile diagnosis remains separate; the
strict original1024 fault-kind counterexamples stay preserved.

## LEAVE fault precision at canonical gaps and address wrap

The single canonical C9 step now checks incoming RBP and RBP+7 modulo2^64
against the existing48/57-bit canonical-address profile before reading.
A bad span emits nonCanonical at the frame start without a read or state
change. A good span retains the same success or read-fault transition.
There is no old-RSP check or nonwrapping restriction. Read-success, read-fault
and unreadable lemmas now require the canonical-span premise; the new
leave64_noncanonical lemma proves the address fault. Memory and every flag
remain preserved on all outcomes. T must derive the address premise for
caller-frame proofs. Earlier9fca snapshots remain historical evidence.

F's original strict8192 replay failed1024 noncanonical-frame fault classes;
that published failure stays unchanged. New same-static-observer data
separates two33792-case profiles with independent DS/SS load controls. Direct
V tabulation of all33792 no-LASS KVM records confirms zero state/memory
differences: positive canonical-gap crossings1..7 give #SS before paging;
upper-canonical start and all8 wrap groups give #PF. An early handwritten
F notice incorrectly called wrap faults #SS. The obsolete nonwrap prototype
and its interrupted owner-only build are archived, without a pass claim.
The corrected rule preserves the actual wrap fault behavior.

The host upper-half faults are separate from the guest no-LASS profile.
[Intel's LASS specification, chapter9](https://cdrdv2-public.intel.com/819680/architecture-instruction-set-extensions-programming-reference.pdf)
describes a user/supervisor policy before paging; no user-only address guard
is imported into the kernel-payload ISA. This LEAVE profile explicitly
disables LASS. Hardware here exercises48-bit mode, not active57-bit mode.
No CPL0 platform equivalence or whole JIT/ABI proof is inferred. F owns
independent same8192 and no-LASS33792 canonical replay, pending here.

Default incremental lake build passes its378-job graph, including every
library module and the relinked reference executable. All372 physical
source/configuration pins remain stable. Six public-lemma axiom audits
report only propext and Quot.sound. Prototype/correction/interruption details,
final commands/logs/pins, raw-hardware tabulation and canonical diff are in
the existing integration JSON/gzip. F's collector finalized summary metadata
after the first raw tabulation; both hashes are retained and the actual raw
streams/profile bytes stayed unchanged. No header/generator/oracle/test/
configuration/paper edits. Full exact900 POPCNT compile EXIT2 and the separate
CMOV-route unaligned-pointer UB remain open; no full-check or full77/72/O2/O4
pass is claimed.
Canonical SHA256:494c5413e9d8a4f073dac915c7af294a7bf51de8826c69f5b0738d74b81df13b.

## Seven raw register opcode gates in one step theorem

The same `register_dispatch_step_refines` now includes generated BSWAP and
POPCNT singleton gates between CMOV and XCHG. BSWAP binds32/64-bit width and
destination only; SRC/AUX/immediate stay arbitrary and unused. POPCNT binds
16/32/64-bit width and both GPRs; AUX/immediate stay arbitrary and unused.
All width fields retain the production absent0-to64 fallback. Existing
NOP/MOV byte lanes, all16 CMOV conditions and XCHG snapshot/alias behavior
are retained. No admitted operation is removed, no result or semantic
handler equation becomes a premise, and no runtime guard is added.

The joined theorem derives the complete same canonical step through the
raw RSP/STACK frame, including all input flags and arbitrary register aliases.
This covers seven raw opcode gates, not the full77 x86 operations or the
72 AArch64 operations. Unproved intervening handlers remain outside the
partial interface. Compiled-body/initial ABI/private-memory transport and
O2/O4 remain separate obligations.

Focused86-job Lean graph and two axiom audits PASS using only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. All372
physical proof/configuration pins remain stable, including the published
494c LEAVE reference. Earlier theorem declarations and all existing binding
cases are retained with the two new cases. The complete command/output/audit/
pin record is appended to the integration JSON/gzip. The three contracts and
five UBSan hosts for underlying count/reversal/flags were already checked
for c9e345fd3; they are not rerun or counted twice here. No ISA/header/producer/
oracle/test/configuration/paper edits. Full-check POPCNT compile and CMOV
route alignment failures remain open; no whole-check pass is claimed.

## Same-register XOR specialization through the raw frame

C's actual OTel failure involves self-XOR on a verifier pointer value. The
new self_xor_value and self_xor_flags lemmas derive that identical native
operand lanes give the same generated result and flag outputs as literal
zero operands. self_xor_register_frame_refines composes those existing
ALU/flag/write primitives through the raw RSP/STACK frame against the SAME
canonical register-XOR step. All four widths, high/low byte slices, arbitrary
incoming flags and STACK/raw pointer encodings are covered. Byte/word writes
still preserve untouched lanes; RSP normalization still happens once.
No old-pointer-value, result, state-equality or condition premise is supplied.

The two native operands are the SAME RegisterSlice. AL/AH cross-lane XOR is
not a same-slice case and cannot use the identity. C owns the raw producer
same-GPR/same-shift predicate and its concrete candidate compiler/CPU work;
this theorem does not certify that predicate, promote a header, prove a C
compiler or close compiled-B/O2/ABI transport. V introduces no producer or
runtime rejection and claims no new C-host cases for this proof-only change.

Focused91-job Lean graph, including the seven-opcode dispatcher consumer,
and three axiom audits PASS with only the existing propext/Classical.choice/
Lean.ofReduceBool/Quot.sound dependencies. All372 physical source/configuration
pins remain stable, including published494c canonical LEAVE. Older proof
declarations are identical except one import. Complete commands/logs/audits/
pins are appended to the existing integration archive. No ISA/header/
generator/oracle/test/configuration/paper changes. Full77/72/whole-dispatch/
compiled-B/O2/O4 and the separate known complete-check failures remain open.

## Independent LEAVE replay closes the reported fault-kind discrepancy

F published4bf280aea6415514a1935a08cbeb889f22aefeac against V213d's exact494c
canonical reference: original8192 states plus no-LASS KVM33792 boundary states
are41984 exact matches, zero mismatches and zero unavailable cases. Comparison
retains all16 GPRs, full RFLAGS after removing exception-delivery RF only,
PC, memory and modeled fault presence/class. The previously failing1024
noncanonical-frame cases now report the matching address fault. All wrap
cases retain the native read-fault outcome; no nonwrap guard is introduced.

V separately verified the remote commit ancestry, exact committed summary
blobs, both actual raw-trace hashes and the identical committed/current
canonical source. The compact integration JSON records those receipts and
hashes. Full raw traces, CPU binaries, executable reference, source closure,
adapter commands and the earlier failure remain in F's dated artifacts;
V does not duplicate or reinterpret them. F's adapter only added explicit
33-class counting and computed totals; fault and state comparisons remain
unchanged. Historical failure347c4c1e9 and old decoder-refusal data are retained.

This closes the measured LEAVE fault-kind discrepancy for those inputs.
Hardware mode is48-bit and LASS is disabled for the boundary reference replay.
Host LASS behavior, active57-bit execution, unobserved SIMD/segments, CPL0
platform correspondence, simulator LEAVE support and whole JIT/ABI/O2/O4
remain separate. Neither the complete formal check nor full77/72 coverage
is claimed by this one-instruction result.

## Register AND/OR/XOR/TEST through the raw frame

logic_register_frame_refines composes both materialized native lane reads,
the existing generated logical result/flag primitives and the real raw
width-aware writer against the SAME canonical register-logic step. Both
operands and flags are captured from the input before writeback. AND/OR/XOR
scalarize their destination; TEST updates only flags/PC and retains raw
register values and STACK predicates. Byte/word writes preserve untouched
lanes, dword writes zero-extend and RSP normalization occurs once.

The theorem derives the complete state and empty register-only effects for
all typed logical kinds/widths/lanes, source/destination aliases and input
flags, under the same raw RSP-offset/STACK-arena frame. No operand-value,
computed-result, chosen flags or state-equality premise is supplied. This
is the register-logic core; actual operation/AUX field decoding, singleton/
family dispatch composition, immediate-production semantics, memory routes,
compiled B and initial ABI remain separate. The existing seven-opcode raw
dispatcher is recompiled as a consumer; it is not relabeled as already
covering these new raw opcode/ALU payload combinations.

Focused91-job Lean graph and one axiom audit PASS with only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. All372
physical source/configuration pins remain stable, including canonical494c.
All older declarations are byte-identical; no ISA/header/generator/oracle/
test/configuration/paper change. Complete commands/log/audit/pins are appended
to the existing integration archive. This proof-only composition does not
rerun or recount underlying existing C oracles. Full77/72/dispatcher/O2/O4
and the known complete-check failures remain open.

## Raw logical family and TEST register dispatch

register_dispatch_step_refines now composes AND/OR/XOR payloads of the
ALU_REG/ADD_REG/XOR_REG family and the separate TEST_REG row with all prior
seven raw register gates. The existing generated family table is proved to
match the raw opcode predicate for every family constructor. All three ALU
rows pass AUX unchanged, so their names do not force the operation: the low
payload byte selects AND/OR/XOR. Other ALU payloads still need their own
body lifts; this is not full coverage of those operation families or all77.

Width, physical GPR bytes and both AUX lane shifts are decoded using the
existing bindings. Byte high/low lanes and aliases, wider unused lane bytes,
absent0-to64 widths, next PC and unused immediate fields are retained.
TEST_REG consumes the lane bytes but ignores the payload and high AUX byte,
then changes only native flags/PC through the same raw RSP/STACK frame.
No handler-semantic, computed-value, chosen-flag or state-equality premise
is added, and None still denotes an unproved interface case rather than a
new runtime guard or successful no-op.

C's current same-GPR/same-shift XOR zero-operand path is represented explicitly.
The raw payload, GPR-byte and shift equality gate is retained. Its field
bindings derive both native XOR and equal RegisterSlice operands; the whole
body then uses the published zero-body theorem. Other inputs use the proved
generic body. AL/AH cross-lane inputs remain distinct, without an assumed
same-value equality. The C owner retains the producer/header/compiler work;
this does not close compiled-B or initial ABI transport.

Focused92-job Lean graph and four axiom audits PASS with only the existing
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies (the
family bridge has no axioms). All372 proof inputs remain stable. Five existing
generated checks and all five existing UBSan hosts PASS on a stable input
snapshot:7629 AUX,2603 family,1141 family-route,2913 comparison and47529
comparison-route cases. Compiler warnings are retained verbatim. The first
run also returned0 for every command, but C's authorized header promotion
changed its source during the run; that record retains metadata exit1 and
its old pins. A second stable-source run is recorded separately.

The tested C-owner header has SHA256
d30d4ff18738cc24ab19776b986bc340fe8a4b8d6a539f4e0bb3008de3895327.
At this validation its physical source is an owner candidate; publication
identity will be checked when C commits it. Its complete input snapshot,
header diff, original/final proofs and host commands/output/pins are in the
existing integration JSON/gzip, without creating another runtime header.
No ISA/header/generator/oracle/test/configuration/paper changes by V. Full
77/72/whole-dispatch/O2/O4 and complete make-check completion remain open.

## Logical immediates through generated value production and the raw frame

logic_immediate_frame_refines composes the actual generated arithmetic-
immediate helper, materialized destination-lane read, generated logical flags
and raw width-aware writeback against the SAME canonical immediate-logic step.
The helper consumes low imm32 and sign-extends it for64-bit operations. Its
ImmediateBinding compares only native operand-width bits, so narrow native
immediates may retain different unused high bits. This is an encoded operand
identity, not an assumed result, chosen flags or numeric-state equality.

The result and flag lemmas derive insensitivity to those unused operand bits.
All four logical kinds and widths, legal high/low lanes, arbitrary flags and
RSP/STACK aliases are covered. TEST preserves raw register/tag state; other
kinds use the actual materialize/merge/zero-extend/scalarizing writer. Raw
immediate opcode/AUX family composition is the next step; this component
does not claim compiled B, initial ABI or full77/72/O2/O4 completion.

Focused92-job Lean graph and three axiom audits PASS with only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. All372
physical proof/configuration pins remain stable. The existing immediate
contract check and existing CMP/TEST host pass under UBSan (2913 cases,
including its immediate consumers); this reuses the retained oracle rather
than adding a new one or new coverage. An initial auxiliary runner referenced
a nonexistent standalone immediate-host filename; its setup failure executed
no oracle and is retained separately. All11 actual host inputs remain stable.
Older declarations are byte-identical except one import. Commands, logs,
audits and source pins are appended to the existing integration JSON/gzip.
No ISA/header/generator/oracle/test/configuration/paper changes accompany
this proof. The POPCNT harness repair is separate uncommitted work here.

The formal entry README is shortened to its requested role: what is proved,
the single reference, layout, trusted assumptions and one make-check entry.
Detailed chronological results stay in this dated log and the existing
structured/compressed archive. No theorem or semantic oracle is removed.

## POPCNT memory harness: preserve entry mode and use the native XDP ABI

The previously blocking make-check component now passes, with GCC and Clang18
both executing the same88,704 complete-state and memory comparisons under
UBSan. All21 width/address/alias variants,64 flag combinations and66 value
patterns remain. Five malformed encodings are rejected. Three raw BPF probes
still contain exactly one load of their respective16/32/64-bit width; the
readonly relocation remains checked.

The state-struct host fixture now inlines its wrappers and snapshots the
actual immutable entry-mode field before opaque compiler barriers, as the
production local-state entry does. Each raw-memory case explicitly writes its
already-zero mode before invocation. The snapshot changes no operand, memory,
flag, register, tag or oracle expectation; complete-state memcmp is retained.
Only the host fixture alias is rebound; generated BPF uses unmodified
production macros. Initial inline, explicit-mode and working-copy attempts
failed under Clang; their source, output and optimized IR remain in the
archive. The ineffective working copy is absent from the final check.

The old rendered XDP fixtures incorrectly treated the native context pointer
as packet data: native data/data_end fields are64-bit pointers. Their direct
16/32-bit context reads remain as two negative compilation checks requiring
the unmapped-context diagnostic, and the direct64-bit context case still
compiles. Three positive memory programs first load the native packet-data
pointer and then perform the original POPCNT. Together with the readonly
program, all five positive programs compile. No ISA/encoder/header/ABI rule
is weakened and no original check is silently discarded.

The final command exits0 with no drift among all input pins, using C's
physical d30d4ff1 header candidate; its HEAD publication was still pending at
validation. Full make-check has not yet been rerun, and this component pass
does not close77/72/O2/O4. Exact failures, final sources, assembly, relocation
output, commands, logs and source identities are appended to the existing
integration JSON/gzip.

## Logical immediate opcode/AUX dispatch composition

The existing register_dispatch_step_refines theorem now also composes the
ALU_IMM10/ADD_IMM3 logical payloads and TEST_IMM14 through the raw dispatcher.
The generated family bridge checks all24 family constructors. Both ALU rows
pass AUX unchanged, so the ADD-named opcode does not incorrectly force an
addition. The low AUX byte selects AND/OR/XOR; destination-lane and effective-
width fields feed the prior raw-frame proof. The generated low-imm32 helper
and operand-width ImmediateBinding feed the SAME canonical immediate operand.
SRC, source-shift and unused AUX bytes remain unconstrained; TEST_IMM ignores
the payload and preserves all raw register/tag fields.

Every prior register binding and theorem case remains. No result, flags,
condition outcome, whole-word immediate equality or native-state equality is
assumed. Focused92-job Lean build and three axiom audits PASS; the family
bridge has no axioms, and the composed theorem uses only the previously
reported propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies.
All372 proof/configuration pins are stable. Four generated checks and all
five existing UBSan hosts PASS:7629 lane,2603 family,1141 family-route,2913
comparison and47529 comparison-route cases. This increment reuses the
existing host binaries after checking all source/dependency and binary hashes;
no duplicate builds or new oracles are introduced.

C's af2f58c89 header publication has now been independently checked against
origin/master and the exact d30d4ff1 physical input used by this and the
preceding logical-register/POPCNT checks. Earlier candidate-at-validation
records remain historical; a later publication receipt is added separately.
Commands, pins, complete proof diff and logs are appended to the existing
integration JSON/gzip. The logical ALU subsets are partial family coverage;
full77/72/whole-dispatch/O2/O4 completion remains open.

## CMP register/immediate raw-frame and dispatcher refinement

CMP_REG13 and CMP_IMM12 now use the same raw dispatcher-step theorem as the
existing register families. The two bodies materialize the destination and
register-source lanes (or the generated low-imm32 immediate), compute the
existing generated subtraction flags including PF/AF, and update only flags
and PC. Raw GPRs, provenance tags, stack and memory are preserved. The theorem
covers every legal high/low slice, width, alias and incoming flag combination,
including RSP and private-STACK representations. Opcode, width, lane and
immediate operand-bit identities are its only bindings; no chosen result,
flag, native-state or whole-word-immediate equality is assumed. Unused AUX
payload/high bytes are unconstrained, as are immediate-form SRC/source-shift.

A reusable generated-narrowing lemma derives that unused high immediate bits
cannot change any arithmetic flag. The former core declarations are retained
byte-for-byte with one additional import. All previous dispatcher cases also
compile. Focused92-job Lean build and four audits PASS with only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. All372
proof/configuration pins remain stable. Three existing generator checks and
the cached UBSan comparison-handler2913/route47529 hosts pass with unchanged
source/dependency and binary hashes; no new tests or duplicate build is added.
The component-only initial pass is retained separately from the final composed
pass. Sources, exact diffs, commands, pins, logs and audits are appended to the
existing integration JSON/gzip.

The sole complete make-check run is still checking immutable5c7549242, which
precedes this CMP increment. It has passed the repaired POPCNT component and
DIV at this observation, but is not yet a full PASS. This later CMP increment
has its own focused validation; full77/72/whole-ISA/O2/O4 work remains open.

## Immutable5c754 full check and CL/parity fixture repair

The complete make-check command on published5c7549242 finished with actual
exit2 at Makefile177, check_x86_flag_definedness.py. The repaired POPCNT and
preceding DIV/rotate/high-load components passed. The new failure was the
SHLD positive compilation fixture reading DWORD directly from the native XDP
context; native data/data_end fields are64-bit pointers. Full commands, all
1140 exported source hashes, compiler output, queue/runner controls and call
CPU trace are retained here; the private source/cache export was deleted and
the sole FULL slot released. This is a failed full run, not a partial PASS.
The later CMP c1b proof is separately validated outside that fixed snapshot.

The CL/parity positive fixtures now first load the native packet-data pointer
before their existing DWORD load. The original jp7 target is rebased to jp8,
so it still reaches the same mov eax,2 instruction. Both original context-
read programs remain as negative compiles requiring the exact unmapped-read
diagnostic. Neither the encoder, production header nor ABI rule is changed.

The entire corrected component passes with no input drift: all132 existing
ABI/undefined-state cases,3072 UBSan width/count/destination-alias cases,
both SHLD/SHRD packet-memory BPF compiles,19 actual widening host/BPF programs,
and five impossible-width/REX rejections remain. The two original narrow-
context programs are checked explicitly as rejections. Exact old/final tool
sources, generated C, diagnostics, commands and pins accompany the full-run
failure in the existing integration JSON/gzip. A new full run after this
repair will be a separate immutable record; no full77/72/O2/O4 claim follows.

## ADD/SUB/ADC/SBB raw-frame and dispatcher composition

The same raw dispatcher-step theorem now includes ADD/SUB/ADC/SBB payloads
through both actual register and immediate ALU families. The generated
handlerForCode table selects SBB/ADC before generic ADD/SUB. A field lemma
also derives that none of these payloads takes a logical or self-XOR branch.
The opcode name does not override AUX. Every prior binding still compiles.

The raw bodies capture both materialized lane operands and carry from the
original RFLAGS before flags or writeback. They compose the existing generated
arithmetic result/flag helpers and the RSP/STACK-aware numeric writer against
the SAME canonical arithmetic step. Every legal width and high/low byte lane,
destination/source alias and incoming carry is covered. The immediate form
uses the generated low-imm32/sign-extension helper and only operand-width
bit identity; unused high native immediate bits remain unconstrained. The
result, all six flags, destination merge/zero-extension/scalarization and
unchanged frame fields are derived without a chosen result/state premise.
Current production ALU bodies have no separate pointer-preserving ADD arm;
the existing numeric read/write normalization supplies the raw-frame lift.

Focused92-job Lean build and six audits PASS with only the previously
reported propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies.
All372 proof/configuration pins are stable. Five existing generated checks
and the unchanged ALU-result-route/flag-route/decode oracles pass under UBSan:
760337, 776162, 3256 cases respectively, with stable dependency pins.
No new test/oracle or production header/encoder/reference change accompanies
this increment. Exact original/final proofs, diffs, commands, source pins,
compiler warnings and logs are appended to the existing integration JSON/gzip.
The immutable464cddd94 full check still runs independently and predates this
increment; its outcome is not yet a PASS. Other ALU payloads and the remaining
operation families, whole-ISA dispatch and compiled-B/O2/O4 remain active work.

## INC/DEC/NEG/NOT raw-frame and dispatcher composition

The same raw dispatcher step now composes all four unary payloads through
both register and immediate ALU families. The destination lane is materialized
before the existing generated value/flag helpers and numeric writeback. Every
legal width/slice, RSP/STACK representation and incoming flag word is covered:
INC/DEC preserve CF, NOT preserves all flags, and NEG derives all arithmetic
flags. The body preserves every non-destination architectural field. There is
no chosen output or state-equality premise and no source-value assumption.

The actual generated unary result formulas ignore arbitrary RHS bits, proved
universally. SRC, source-shift and immediate are therefore unconstrained for
these bindings; register-source slice decoding remains required only by
binary payloads. Selector lemmas derive exclusion of logical, carry-sensitive
and self-XOR branches from AUX. All previous bindings still compile.
Focused93-job Lean build and five audits PASS with only the prior reported
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. All372
proof/configuration pins are stable. Six existing generated checks and the
cached UBSan ALU-result/flag/decode hosts pass with unchanged source/dependency
and binary hashes (760337/776162/3256 cases). No oracle, test, encoder, header
or canonical ISA is added or changed. Detailed proofs/diffs/commands/pins/logs
are appended to the existing integration JSON/gzip.

The separate immutable464cddd94 full check finished with actual exit2 at
Makefile508, a64_route_host: the fixture plants an unrelated ABI-tagged buffer
but expects the real-XDP field tag, and its include-guard scene expects the
former synthetic-ABI entry pointer. The fixed x86 POPCNT/CL-parity components
passed. All1140 source identities, command/output, CPU trace and queue controls
are retained here. The private source/cache export was deleted and the FULL
slot released. That run predates arithmetic687 and this unary increment;
focused validations stay separate. The ARM oracle fixture is being corrected
without changing production ISA/header behavior. No full77/72/O2/O4 claim.

## AArch64 route oracle: real context identity

The original Makefile508 failure was reproduced independently on the exact
same production header and oracle bytes as immutable464cddd94. The old
fixture tagged an unrelated buffer ABI but expected native XDP field0/8 tags;
current production tag selection uses the address relative to the actual
entry context. Its guard scene also expected the former synthetic ABI pointer
although XDP x0 now names the real context. The production header and canonical
ISA are unchanged by this fix.

The positive field-tag cases now plant the actual input xdp_ctx pointer. The
original unrelated ABI-tagged buffer remains an explicit scalar-tag control;
no field identity is inferred from its tag alone. The guard still checks both
live entry tag and exact pointer after re-include, now against the real entry
context. Existing synthetic-ABI field checks and every other route scene,
whole-register/tag/SP/NZCV/exit/path assertion remain. A stale reset comment
is corrected to match entry order and XDP versus SKB pointer identity.

The complete existing route oracle passes both ordinary Makefile-equivalent
compilation and UBSan:4471 cases each (the extra retained unrelated-buffer
control adds one case). All dependency pins, including the unchanged production
header, are stable. Exact initial failure, original/final C, compiler warnings,
commands, source identities and diff are appended to the existing integration
JSON/gzip. A fresh full make-check after publication will be a separate record;
this focused pass does not replace the failed464 result or close77/72/O2/O4.

## Complete make-check PASS on published5a44604f5

The full make-check command on immutable published
5a44604f56437a0975de525f39897256a69fb69a completed with actual exit0; the
queue also propagated exit0. It includes the arithmetic687, unarydbb and
ARM routeecb increments, all retained semantic oracles and all reference/
generated/Lean checks. The prior POPCNT, CL/parity and ARM route fixture
failures are resolved without dropping their semantic controls.

All1140 exported input hashes were independently checked against the exact
published Git blobs and the commit is an origin/master ancestor. Full runner/
queue controls, commands, source manifest, compiler warnings, complete output
and call CPU trace are appended to the existing integration JSON/gzip. Warm
Lean/native-link caches and shared vendor symlinks were reused; the manifest
describes selected repository inputs, not an immutable vendor snapshot. The
private source/cache export was deleted and the sole FULL slot released.

This is a full PASS for that exact snapshot. New IMUL raw-frame/dispatcher
work is outside it and will carry separate validation; full77/72 operation,
whole-ISA dispatch and compiled-B/O2/O4 remain active work. Earlier failed
full runs and their original inputs/output remain separately retained.

## IMUL raw-frame and dispatcher refinement

Three actual IMUL bodies now compose into the same raw dispatcher theorem:
the register ALU payload, the ALU-immediate payload and dedicated IMUL_IMM56.
The first two perform their actual width reads; dedicated IMUL_IMM reads SRC
rather than the old destination and sign-extends its simulator immediate at
the destination width. The proofs cover all16 GPRs, legal16/32/64-bit widths,
identical/different source and destination, RSP normalization and private-STACK
aliases. Both operands are captured before writeback. Product truncation,
CF/OF overflow, merge/zero-extension/scalarization and every unchanged frame
field are derived against the SAME canonical multiply step. The C-selected
preserved values of ISA-undefined flags remain within the existing mask.

Operand-bit lemmas connect early narrowing to signed magnitude, mixed sign
and overflow without assuming a product or overflow decision. ALU-immediate
lowimm32/sign extension is derived; dedicated immediate bindings compare only
encoded operand-width bits. AUX selector lemmas exclude logical/arithmetic/
unary/self-XOR branches and establish generic routing. Unused wide operand
lane bytes and dedicated-immediate AUX remain unconstrained. Opcode names do
not override AUX. All previous dispatcher cases compile.

Importing the multiply helpers exposes a legacy global Word alias; architectural
field types are now explicitly Reference.Word so that alias cannot silently
change their types. Initial GPR-extensionality/name-resolution proof failures
and exact saved inputs are retained; final proofs contain no placeholder.
Focused94-job Lean build, five audits and the complete default Lean library+
executable-reference build PASS with stable input pins and only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. Eight
existing generated checks and unchanged IMUL-route, register-source-immediate
and wide-flag hosts pass under UBSan:261121/41296/2048 cases. No new test,
oracle, production header, encoder or canonical ISA change is introduced.

Original/final proofs, full diff, failed and successful commands/output/pins
are appended to the existing integration JSON/gzip. Full5a446 PASS remains
its exact earlier snapshot; this increment has the separate complete Lean
and focused/oracle validations above. A new immutable full will be recorded
separately. Raw shift payloads and other operation families, whole-ISA dispatch
and compiled-B/O2/O4 remain active work.

## SHL/SHR/SAR/ROL raw frames and same-input CL resolution

The same raw dispatcher-step theorem now composes all four legacy shift/
rotate-left payloads through the register and immediate ALU families. The
actual width/lane read precedes the generated result/flag helpers and numeric
writer. Every legal width and destination slice, arbitrary incoming flags,
masked count, zero-count writeback and RSP/STACK representation is covered.
The existing undefined-output masks remain unchanged.

Immediate count resolution derives the native imm8 from the generated low-
imm32 helper. For variable forms, CL is derived from the SAME incoming native
state, not assumed: the width-read count and the native RCX low byte have the
same architectural5/6 count bits. Destination RCX/CH aliases still sample the
original state before writeback. No product/result/flag/count-value or native-
state equality is a premise. RegisterBinding now takes the input native state
explicitly to resolve this operand; all previous constructors remain available
for arbitrary input states and all old theorem cases still compile. The
canonical ISA already uses resolved counts/addresses, so no second ISA or
canonical-definition change is introduced.

Selector and generic-result lemmas establish the actual ALU path and exclusion
of earlier logical/carry/unary/IMUL/self-XOR branches. A universal enum theorem
shows that all16 declared ALU tokens select a proved payload family under the
legal native width/operand bindings. This does not claim malformed fields,
arbitrary raw payload bytes or the remaining77/72 opcode coverage.

Focused98-job Lean build, six audits and the complete default Lean library+
executable-reference build PASS with stable input pins and only the prior
propext/Classical.choice/Lean.ofReduceBool/Quot.sound dependencies. Seven
existing generated checks and unchanged UBSan shift-flags/flag-route/ALU-route
hosts pass:90112/6504961/760337 cases. One initial proof needed its masked-count
binding unfolded; that failed elaboration and exact source are retained.
The tested header is C's published4fe6817/b46de606c CMP update, independently
matched against its Git blob; V changes no header, encoder, oracle or ISA.
Detailed commands, source pins, proofs, diffs, warnings and logs are appended
to the existing integration JSON/gzip.

The separate complete make-check on published231cbde41 also finished with
actual exit0 and queue0. All1140 source hashes were independently verified
against the exact published Git blobs. Its full output, CPU trace, source
manifest and runner/queue controls are retained here; the private source/cache
export was removed and FULL slot released. Warm caches and shared vendor
symlinks were reused. That full snapshot includes IMULbc3b, and predates this
shift increment and C's new CMP header; later input differences are explicitly
recorded. It is not relabeled as a current-HEAD PASS. Whole-ISA dispatch and
compiled-B/O2/O4 remain active work.

## Current CMP OF assignment is now in the core refinement

C's publishedb46de606c/4fe6817 CMP body computes the existing zero-borrow SUB
flags and then assigns OF = SF xor signedLT(width-signextended lhs,rhs).
The core now models that exact assignment with the actual generated sign-
extension helper. A universal all4-width identity uses SF/OF from the SAME
preceding subtraction, without a free result/SF/borrow premise. The entire
flag word, including PF/AF and all preserved bits, is derived equal to the
prior generated CMP flags and the SAME canonical arithmetic step.

The canonical word law assessed independently by T inb0ad7c7cf is integrated
into the core; its two original published archive/review blobs, Lean/source/
canonical hashes and actual C-added lines were independently verified. The
promoted C additions byte-match T's reviewed candidate. The new bridge adds
the generated helper correspondence and actual flags assignment, rather than
leaving the assessment as an isolated candidate proof. Raw CMP_REG/CMP_IMM
models now call this compareFlags body; their whole-frame and the existing
dispatcher theorem are re-established. No ISA, generated contract, production
header, encoder, oracle or test is changed by V.

Focused98-job Lean build, five audits and complete378-job default library+
executable-reference build PASS. Standard propext/Classical.choice/
Lean.ofReduceBool/Quot.sound dependencies remain explicit, with no sorryAx.
Four existing generated checks and unchanged UBSan comparison handler/route/
memory hosts PASS:2913/47529/40784 cases, with all input pins stable. Initial
doc-placement elaboration and an unnecessary BV enum-support name collision
are retained as actual failed phases; the local flag-restoration subproof now
excludes its unrelated context, and the entire library imports successfully.
Exact old/new source, diffs, commands, logs, input identities and provenance
are appended to the existing integration JSON/gzip. A new complete make-check
on this published model/current C header will be a separate immutable record;
prior full231 PASS is not relabeled. Other opcodes and O2/O4 remain active.


### Full published a07627419 check and classic ROR register dispatcher

`make check` completed with actual exit0 (queue exit0) at immutable published
`a076274192b88e7c3865b57ceac53d3145ef2a93`. All1,140 selected source SHA256s
were independently checked against that commit's Git blobs. It includes the
legacy ALU shifts and current CMP overflow identity with production header
4fe6817. Warm incremental caches were copied; shared vendor submodules were
used. The temporary export was deleted. Later source drift is recorded in
JSON; this snapshot predates the new ROR lift.

Classic ROR's production register body now refines the canonical rotate-right
step through the raw numeric frame and the existing dispatcher theorem.
Legal byte/high-byte/word/dword/qword destinations, RSP/STACK aliases, imm8
and the encoder's actual pre-write CL expression are covered. RCX/CH aliases
sample the same incoming state. No chosen output, flag or state equation is
assumed. Zero masked count preserves flags; counts equal to byte/word width
still use the architectural CF/OF rule and the actual partial-register writer.

Focused113-module and complete default Lean builds passed, with six axiom
audits and stable input hashes. Unchanged checks passed504 encoded handlers,
17,640 register/CL/flag/RMW results,40 rendered BPF artifacts and20,320
independent rotate-result cases under UBSan; five generator checks passed.
Two initial elaboration failures and their inputs are retained. C changed the
physical RORX body after these stable checks; the tested4fe header is archived
and its classic ROR body remains byte-identical. No reference ISA, C handler,
encoder or oracle was changed by V. Memory ROR, remaining operations and the
compiled O2/O4 link remain open.


### BMI2 raw register dispatcher

SHLX, SHRX and SARX now use the raw SHIFTX gate's AUX count register and
IMM32 ALU selector. RORX uses its separate imm8 gate and the same value/write
proof. The handlers sample full materialized source/count registers in the
same incoming state, including every source/destination/count alias, RSP and
private STACK pointers. Both architectural widths are covered. The theorem
retains the entire modeled state and leaves all flags and memory unchanged.
The existing dispatcher-step theorem composes these gates with earlier ones.

The focused 113-module and complete default Lean builds passed. Five axiom
audits contain no proof placeholders. Five generator checks and the existing
195,841-case routed host oracle passed under UBSan with stable source hashes.
The production header is exactly C's published `2b1ab2c29` RORX extraction
(SHA256 `47fb5565`); its generated value is the same primitive used by this
proof. V changed no production handler, contract, oracle or canonical ISA.
The archived first count-decoder elaboration failure was corrected without
changing a theorem premise. Memory-source BMI forms, remaining operations,
whole-ISA coverage and compiled O2/O4 remain open. The next full check will
use a new published snapshot; the prior a076 full pass remains separate.


### Full 9e7f86146 check and actual bit-operation flags

The complete `make check` at immutable published
`9e7f86146306fe75089391470d9a04dc22aebbdb` finished with actual exit 0 and
queue exit 0. All 1,140 selected source hashes were independently verified
against published Git blobs. It includes classic ROR, register BMI2 and C's
RORX extraction; the new bit-operation lift below comes later. Shared vendor
submodules and warm copied caches were used. The export was deleted; full
logs, commands, manifest and CPU trace are archived, with later drift listed.

ANDN, BZHI, BT and BT_IMM now compose their actual raw fields and register
frame through the same dispatcher. Legal 32/64-bit ANDN/BZHI and 16/32/64-bit
BT forms cover every GPR, RSP/STACK projection and operand alias. ANDN's
production shared logic macro writes PF parity, whereas canonical PF/AF are
undefined. The model retains that real write. The dispatcher theorem now
returns the actual transition and the existing canonical `Step` relation;
all earlier per-operation exact equality proofs remain. No ISA mask or
production handler changed, and no output/state equality is a premise.

Focused 113-module and complete default Lean builds passed; seven axiom
audits contain no proof placeholders. Four generator checks and existing
UBSan route oracles passed 356,404 ANDN, 356,405 BZHI and 534,606 BT cases.
The ANDN oracle now plants opposite PF parity and checks preserved AF, adding
a missing real-behavior assertion without dropping any old case. A private
control omitting only the PF assignment was rejected with 10,800 differences;
every difference was independently verified to be PF alone. Original failed
elaborations and corrected source hashes are retained. Remaining opcodes,
memory routes and compiled O2/O4 are still open.


### SETCC raw register dispatcher

All sixteen conditions, including parity and inverse parity, now pass through
SETCC's actual low AUX payload, full matched-condition decoder and byte-lane
writer in the same raw dispatcher theorem. Legal high/low register bytes,
RSP/STACK projection and arbitrary input flags are covered. Flags, vector,
memory and every other register byte are retained. The macro ignores FLAGS,
SRC and IMM; the binding leaves those unused fields unconstrained.

The focused 113-module and complete default Lean builds passed, as did three
axiom audits and three generator checks. Existing checks passed 15,371
canonical condition/width/lane/branch/memory/fault cases and 2,433,038 routed
SETCC host cases under UBSan, with stable recorded inputs. The initial
let-reduction elaboration failure and exact corrected proof sources are
archived. C changed the shared memory-load header after the first stable host pass;
those original inputs/results and the observed drift are archived, and these
host checks were rerun successfully against the new load-cast header. V
changed no production source, oracle or canonical ISA in this increment. The next full check will include both bit-operation and SETCC
proof changes; the complete 9e7 full pass remains a preceding snapshot.


### Generic simulator argument and direct token bodies

The operator's 19:13 order prohibits per-program proofs, certificates and
validation files. Current safety work consists of universal simulator,
per-token and native-link preservation theorems. Frozen historical program
proofs are not current safety evidence and are neither extended nor rechecked
by this increment.

Ten direct tokens now have semantic C-model bodies separate from the ordered
interpreter gates: MOV_IMM, MOV_REG, CMOV, SETCC, ROR, RORX, ANDN, BT, BT_IMM
and IMUL_IMM. `specialized_register_body_matches` proves their complete body
result equals interpreter dispatch for every raw field, state, frame and
invocation. The generated token spelling and direct dispatch class are also
proved to agree. This is a state-transformer theorem, beyond the earlier
macro-name table check. Unsupported modeled fields remain `none`, without
claiming a production runtime guard or unlifted token coverage.

`register_dispatch_native_matches` and
`specialized_register_native_matches` quantify over any canonical successor
from the same projected input. They retain events, faults and all defined
architectural outputs. Composing masked states across instructions still
requires a generic definedness/ABI invariant. These C-model equalities do not
silently replace a compiler or actual-B preservation law; the C/Lean
correspondence and compiler trust boundary remain explicit.

Focused 114-module and complete default Lean builds passed, with six axiom
audits and stable selected inputs. Four generator checks, dispatch-model and
undefined-output checks passed; unchanged UBSan hosts passed 205 chain and
534 specialization cases. No per-program file, production source, contract
or oracle was edited. Original elaboration failures and proof inputs remain
in the archive. O1's remaining operations, both complete dispatcher steps,
the remaining O2 tokens and generic compiled/native-link preservation continue.

The preceding immutable full check at
`a6bc0aad3567a58363b003619aecdf532b5fc56c` completed with actual exit 0 and
queue exit 0. All 1,140 selected source hashes match published Git blobs;
full commands/logs/manifest/CPU trace and later drift are retained. Shared
vendor submodules and warm caches were used; the temporary export was deleted.
That snapshot predates these new token theorems and C's c0b load casts. The
focused token checks used the published new load header, SHA256 `3ba4bc78`.


### Standalone memory-width fixture type dependencies

The full check at published `43a7fa48d2390b7c2b643628595434040aa6a273`
ended with actual/queue exit 2 at Makefile line 180. Its BPF memory-width
fixture declared only u8/u64; C's published narrow-load return casts also use
u16/u32. All 1,140 source hashes match that Git snapshot. The original
compiler errors, command, complete log, manifest and CPU trace are retained.

The fixture now declares the matching unsigned 16/32-bit aliases. Its semantic
cases remain unchanged. The generator check and existing memory-width checker
passed all ten generic and twenty fixed load forms, fixed/signed-limit
displacements, three invalid-offset rejections and twelve MOVX access-width
checks against the new production header. Source hashes stayed stable. The
production generator/header, access count/width/address and canonical ISA were
unchanged by this repair. The next full check includes the published fixture
repair and subsequent generic token-family proof work.


### Uniform ALU, compare and generic-token O2 families

The uniform semantic interface now covers 25 x86 register tokens. Nine new
direct entries are ADD_IMM/ALU_IMM, ADD_REG/XOR_REG/ALU_REG and the four
CMP/TEST register/immediate forms. Their ALU bodies are shared with the
interpreter exactly as the production C macros are shared. Six generic entries
(NOP, BSWAP, POPCNT, XCHG, SHIFTX, BZHI) forward the unchanged opcode and fields
to RUN_OP. `register_token_body_matches` proves full step equality for all
fields/states/frames; `register_token_step_refines` and
`register_token_native_matches` compose the existing O1 interface. The earlier
direct-token theorem API and all per-operation refinement statements remain.

Focused 114-module and complete default Lean builds passed, with six axiom
audits. Prior generic semantic host checks from 43a7 were reused after every
recorded production input byte was independently verified unchanged; this is
not a new execution result. The published standalone type repair d657 fixes
the preceding full-check compiler failure. A new immutable full check follows.

`coverage.tsv` implements the coordinator's per-operation/per-token report.
Every current numeric header entry has separate operation and token rows;
source aliases are listed separately. Reference families, raw register proofs,
conditional ARM observations, C-model token equalities and exact-epoch finite
replays retain distinct status labels. The live 75/71 numeric inventories and
the requested 77/72 totals are recorded as an explicit scope reconciliation.
The table adds no invented operation, proof or coverage count. Generic ABI,
definedness, compiled-B and native-link preservation remain part of the
whole-simulator proof work, with individual-program certificates frozen.

Full `make check` at published snapshot `2ccfa5a8dc63343363c09a78d4fe37975a190d95` completed with make exit **0** and queue exit **0**. All **1,140** selected source hashes match that commit's Git blobs; remote ancestry is verified. The source epoch includes the memory-width fixture typedef repair and 25-token O2 interface. The complete log, source manifest, scripts, exit records and CPU trace are retained in the integration archive under `FULL MAKE CHECK 2CCFA5A8D PASS`. The private export has been retired and the shared incremental caches retained. The subsequent MOVX proof increment has its own validation record.

The MOVZX/MOVSX register increment lifts the generated C source-width fallback
and128..131 high-byte source selectors through the raw RSP/STACK frame, ordered
dispatcher and shared direct specialization body. Source capture precedes every
destination write, including aliases. `movx_source_width_binding` and
`movx_encoded_source_binding` derive the field relations from ordinary native
widths and source codes. The canonical ISA and production C retain their existing
definitions. Coverage advances to **27** raw register operations and **27** token
C-model equalities (21 direct and six generic).

Validation: focused117 and all378 default Lean targets completed; eleven axiom
audits retain standard Lean axioms. Existing UBSan oracles passed: MOVX route
23,761, MOVX shape route118,803, generic specialization chain205 and specialization
534 cases. The executable reference checked1,415 widening cases; sign-high
retained6,144 actual CPU/encoded-handler results and three BPF compilations.
Full `make check` at `2ccfa5a8d` retains its exact published source attribution.
A full check including this increment follows its publication through the shared
incremental verification entry point.

F's published `a13de4544` ledger supplies four additional numeric replay entries
(ADD_IMM, ADD_REG, XOR_REG, MOV_LOAD_SCALAR):32 raw/direct groups and32,768
CPU/C/reference comparisons with all differences zero. Their source, header,
executable and reference hashes remain in the table. Selected x86 replay totals
advance to **66/75**, with nine numeric operations awaiting selected replay.

The MULX raw-frame increment captures implicit RDX and the explicit source
before either destination assignment. The low write precedes the high write;
every destination/source alias, high=low, RSP offset and STACK-projected value
is quantified. Separate product-half write lemmas preserve the complete native
projection across each actual numeric writer. The ordered dispatcher consumes
actual width/GPR/AUX fields; the direct token body has equality through the
same shared macro semantics. Coverage advances to **28** raw x86 handler and
dispatcher operations and **28** C-model O2 tokens (22 direct and six generic).

Focused123 and all378 default Lean targets passed, with thirteen axiom audits.
The existing MULX reference suite checked2,904 actual CPU products/aliases/flags,
8,192 GNU encodings and9,228 complete native/fault states. Existing UBSan MULX
route and generic specialization hosts retain their original cases and stable
recorded inputs; exact command/results are archived. All earlier dispatcher
theorem signatures are retained verbatim. The canonical ISA, contracts,
production C and oracle sources retain their published definitions.

The ARM table now records two declared numeric dispatch gaps explicitly:
ADD_IMM(3) and SUB_IMM(4). The actual generated ALU gate accepts ALU_IMM(6)
and ALU_REG(7), matching the existing universal model's `aluCode` selector.
Canonical arithmetic families remain defined, and conditional modeled entries
now total **69/71**. F's private gate/operand-selector candidate and A's source
adoption carry separate replay/publication identities. Universal O1/O2 work
continues against the actual published production definitions.

Full `make check` at published `5b999fc5b7cf41b6964b245d39a32f79ae1022a9` completed with actual make exit **0** and queue exit **0**. All **1140** selected source hashes match that published commit. This snapshot includes the MOVZX/MOVSX raw frame, dispatcher and27-token O2 interface. Complete commands/logs/source manifest/CPU trace remain in `FULL MAKE CHECK 5B999FC5B PASS`; the private export is retired and incremental caches retained. The later MULX increment retains its own focused/default Lean and oracle results.

The SHLD/SHRD raw-frame increment covers16/32/64-bit immediate and CL forms.
The count mask is proved invariant under byte extraction. `double_shift_cl_binding`
derives the real RCX byte read from the same incoming raw frame, retaining
source/destination/RCX aliases. Zero count preserves the physical16/64-bit
representation;32-bit zero count performs its architectural zero extension.
Every nonzero count uses the actual value/flag writers and the canonical
undefined-output masks. The ordered dispatcher and unchanged generic RUN_OP
bodies compose through the uniform per-token theorem. Coverage advances to
**30** raw x86 handler/dispatcher operations and **30** C-model O2 tokens
(22 direct and eight generic), with37 additional partial-model families.

Focused129 and all378 default Lean targets passed. Twelve axiom audits retain
standard Lean axioms. The existing reference suite covers15,360 actual CPU
cases,3,072 GNU encodings and32,256 complete reference states. The unchanged
routed double-shift oracle passed under UBSan; exact command/count/output and
all source pins are archived. Earlier generic205-chain/534-specialization
observations from `0c4eb35e4` are reused after every relevant recorded input byte
is verified equal, with their original execution identity retained. Every prior
dispatcher theorem signature, oracle case and canonical ISA definition remains.
A complete full check follows the published source through the shared warm
verification entry point; the completed full5b999 epoch remains separate.

LEA source review confirmed two generic correction points. A64-bit index-only
RCX address at unit scale shares AUX=1 with the rodata marker. The original
encoder/handler produced8,064 differences over8,192 instruction-form CPU cases;
normalizing the address to the equivalent RCX base form produced zero CPU or
canonical-reference differences across16 destinations,8 signed displacements
and64 incoming RCX words. Twenty adjacent encoder controls retain every field.
The recorded76 project/vendor compiler inputs match the published main-header
epoch and actual vendor heads. The normalization preserves the complete
canonical step for every input state, as proved by `unit_index_step_refines`.

The memory-offset helper's signed accumulation raises UBSan on1+LONG_MAX.
The prepared generator/header correction uses unsigned64-bit arithmetic and
retains the signed offset result type, JSON contract and generated Lean bytes.
The existing routed oracle retains all old cases and extends to8,401 boundary
cases: the original header retains its signed-overflow diagnostic, and the
candidate completes all8,401 with zero differences. The combined patch applies
cleanly to the captured production source. C's active service epochs retain
their source; the correction patch supplies the next coherent adoption input.

The raw LEA core covers optional bases, source/destination aliasing, RSP
normalization, STACK pointer preservation,16/32/64-bit writeback and the
address-size32/64-bit-destination normalization. All378 Lean targets and seven
axiom audits passed. The audit records `propext`, `Classical.choice`,
`Quot.sound` and the bitvector reduction bridge `Lean.ofReduceBool` explicitly.
LEA remains a partial handler entry while its raw-field dispatcher and
production correction are synchronized. The source ISA and existing semantic
oracle cases retain their definitions.

Full `make check` at `8db6eb61a81f80ed80124314dac9ab11cd9fad11` completed
with actual make exit0 and queue exit0. All1,140 selected source hashes match
that published commit. Complete log, source manifest, commands and CPU trace
are archived under `FULL MAKE CHECK 8DB6EB61A PASS`. This snapshot contains the
30-operation MULX/SHLD/SHRD dispatcher and O2 interface. The later LEA core,
source findings and candidate comparisons retain their separate identities.

The same offset helper was compiled with clang18 for the BPF target. The
original signed accumulation emits `add nsw i64`; the unsigned correction
emits `add i64`, preserving modular64-bit arithmetic in the compiled proof
body. Both LLVM IR files, source and compiler receipt are archived under
`LEA MEMORY OFFSET BPF WRAPPING IR`, alongside the8,401-case UBSan result.

### LEA fields, dispatcher and token continuation

The optional-register decoder, full AUX index/scale/displacement reads and the
readonly-literal priority now connect the LEA raw-frame core through the ordered
dispatcher. Ordinary addressing and address-size32 use the same incoming native
projection; unit-scale RCX normalization derives its original effective address
for every destination and wrapping displacement. The direct LEA token shares
the body with its interpreter arm. All39 existing dispatcher theorem signatures
are retained.

The focused132-target build, default Lean build and12 axiom audits pass. Audits
record propext, Classical.choice, Quot.sound and Lean.ofReduceBool; token identity
uses the kernel's decidable reduction. Existing UBSan oracles pass48553 routed
LEA,62400 composed LEA and8401 offset cases. The composition oracle retains its
original vectors/random cases and adds63/64/127/255 scale boundaries. Its earlier
UBSan failure at scale200 and the original modulo-shift expectation remain in
the archived diagnostics. The generated Lean and canonical ISA bytes are retained.

An actual RSP-source macro boundary at LONG_MAX+1 exposes a remaining signed
addition. The published one-expression unsigned patch passes8192 whole-frame
cases across16 source words,16 displacements,16 destinations and two flag seeds.
C owns its adoption into a coherent source epoch. LEA therefore carries one
proved wrapping-model dispatcher/token arm while raw production totals retain30.
The integration JSON/raw archive records all inputs, failures and passing receipts.

### Published LEA source full check

`make check` on the immutable published635e79efb source exits0. All1140
exported source SHA256 values independently match that commit’s Git blobs,
and the temporary export has been retired. The full log, source manifest,
CPU trace and exit receipt are in the integration archive under
`full_make_check_635e79efb`. This result covers the LEA dispatcher and total
offset arithmetic at that epoch; later DIV work and the C-owned RSP-source
addition correction retain their separate completion evidence.

### DIV raw register dispatcher and generic token

Unsigned DIV now lifts all four operand widths through the actual SRC selector
and ordered register dispatcher. The proof captures divisor/RAX/RDX from the
same incoming frame, derives zero-divisor and quotient-overflow faults, and
composes byte AH:AL packing or ordered quotient/remainder writes. Qword zero-high
and restoring long-division branches share the verified arithmetic result. The
producer’s captured high-byte SRC_NONE/IMM expression has its own input binding.
All77 existing numeric-frame and41 dispatcher theorem signatures are retained.

The135-target focused build, default Lean build and16 axiom audits pass.
Audits retain propext, Classical.choice, Quot.sound and Lean.ofReduceBool as
reported by the existing trust boundary. Fresh UBSan oracles pass260 selector
and110885 full routed checks. The canonical executable passes1298 full-state
cases including699 divide/read faults. The existing semantic handler oracle
passes18432 real-CPU/encoded register-memory/high-byte observations,9 valid BPF
compiles,9 retained fault markers,2 narrow-ABI and2 undefined-RDX controls.
All captured oracle source inputs keep their SHA256 values through execution.

The C-model O2 interface now covers32 tokens:23 direct bodies and nine generic
RUN_OP calls. Raw register handler/dispatcher coverage is31/75, with LEA
retaining its separate wrapping-model arm pending the C-owned signed-stack sum
repair. DIV memory-source capture/read-fault/effect composition, whole-ISA raw
coverage and generic ABI/definedness/C correspondence/compiler/native-link
preservation retain their explicit completion interfaces.

### Published DIV source full check

`make check` on immutable publishedaf38184ef exits0. Every1140 exported
source SHA256 matches that commit’s Git blob; its temporary export is retired.
The full log, source manifest, CPU trace and exit receipt are archived under
`full_make_check_af38184ef`. The later JCC/JMP proofs and adopted LEA header
retain their separate source identities.

### Unified register and branch-handler step

`dispatchStep` and `StepBinding` compose the existing register step with JCC/JMP
branch handlers. All16 PF-aware conditions use the actual AUX selector; the
forward/backward emission contract chooses the same mapped target/fallthrough
PC. Registers, tags, flags and memory retain their input values. The unified
per-token equality and native-successor theorem cover34 tokens while all42
existing dispatcher theorem signatures remain available. The logical-label
model carries explicit native-PC/layout, return-target fusion, ABI/definedness,
C correspondence and compiler/native-link completion interfaces.

The137-target focused build, default Lean build and12 axiom audits pass with
the recorded propext/Classical.choice/Quot.sound/Lean.ofReduceBool trust boundary.
Expanded existing UBSan route checks pass3561cases, retaining every old PF=0
vector and adding PF=1, full register/tag/flag preservation and JMP directions.
The full-condition oracle passes1024cases, branch-shape oracle90cases and the
canonical executable15371condition/width/lane/branch/memory/fault cases.

Published C sourceafba4a089 adopts the exact earlier LEA unsigned-RSP correction:
headerSHA6b3f31731d9d127a36183e3e35cd6b39335d8b5865649a8282fc503a7be0dc11.
Its prior8192case execution identity is retained as candidate evidence. LEA now
contributes to32raw register operations; JCC/JMP add two control-model operations,
and33 reference-family operations retain partial models. O2 covers34tokens
(23direct/ninegeneric/twobranch). Coverage318rows/24columns retain every T O4 cell.

### Published unified-step source full check

`make check` on immutable publishedae275afec exits0. All1140 exported source
SHA256 values match its Git blobs; the private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_ae275afec`. This epoch includes the unified JCC/JMP step and
adopted LEA header. Subsequent PUSH/POP work keeps its own source identity.

### PUSH/POP raw stack frame and direct tokens

PUSH register/immediate and POP register routes now compose through
`StackBinding`, `dispatchStep` and the existing universal per-token laws. The
raw frame advances its complete64-bit RSP offset, captures PUSH sources before
that advance, and writes POP destinations afterward. Every GPR, STACK alias,
legal16/64/default width and partialSP merge is covered. Generated byte stores,
observed guest memory, flags, vectors, PC, ordered events and fault rollback
agree with the canonical step. Mode2 memory effective addresses and the private
arena/guest permission relation retain their production interfaces.

The focused and default Lean builds pass with14 audited theorems and140 stable
proof inputs. All81 prior numeric-frame and47 dispatcher theorem signatures
remain available. Audits report propext, Classical.choice, Quot.sound and
Lean.ofReduceBool. Existing UBSan selector and route oracles pass463 and112144
checks; the route retains its original vectors and adds all16 cells, four
native stack bases, STACK aliases, immediate AUX and all six preserved flags.
The executable reference passes its stack/memory/fault suite,1214 scalar cases
with72 CPU anchors, and15371 condition/width/lane/branch/memory/fault cases.
All156 actual compiled input hashes remain stable through the final run.

O2 now covers36 C-model tokens (25direct/ninegeneric/twobranch). Coverage keeps
32 pure register operations, two control models and two stack-register models
separate. F's publishedbc8015a5d LEA epoch adds768 groups/196608 CPU/C/reference
observations; its captured47fb header and production correspondence retain
their stated source scope. Existing totals remain66/75 x86 and65/71 ordinary
ARM replay operations. The integration archive records source identities,
initial elaboration diagnostics and final checks under
`x86_stack_raw_frame_dispatch_tokens`.

### PUSH/POP memory AUX and effective-address composition

PUSH/POP now include mode2 memory operands in the same unified step and token
laws. Raw AUX selects optional base/index cells and the scale. PUSH samples
that address and its complete source before the stack decrement. POP forms
the destination after advancing RSP, including RSP used as an index, and keeps
its source load at the incoming stack pointer. Full initialization metadata,
ordered read/write events, read faults, write faults and frame rollback agree
with the canonical reference. The input bindings derive addresses from shared
state fields; each operation retains its generic per-token/native-successor law.
The private-arena/native-memory permission, ABI/definedness/C correspondence,
compiler and native-link production interfaces retain their universal scope.

Focused/default Lean and10 axiom audits pass with140 stable proof inputs.
All88 prior numeric-frame and49 dispatcher theorem signatures are retained.
The existing UBSan route oracle passes347152 checks, preserving its112144
register/immediate checks and adding6912 memory-transfer cases. These cover
stack, heap, STACK aliases, absent bases, scaled/RSP/aliased indexes, three
native bases, overlapping accesses, both direct and dispatcher routes, all
GPR/tag cells, six flags and XMM0. The first invalid64-byte fixture offset and
early elaboration diagnostics remain in the raw archive alongside final exits.
All156 compiled input hashes remain stable. Canonical stack/memory/fault,
1214scalar plus72CPU anchors, and15371condition checks pass.

Coverage keeps36 C-model O2 tokens,32 pure register operations, two control
models and two stack-memory models. `x86_stack_memory_dispatch_tokens` records
the expanded domain, exact source pins and preserved prior interfaces.

### Published raw-stack source full check

`make check` on immutable published7a7893bc9 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_7a7893bc9`. This epoch covers PUSH/POP register/immediate raw
frames and adopted production tagged writes. The subsequent mode2 memory and
effective-address expansion retains its separate source identity.

### MOVBE addressed frame and generic/direct tokens

MOVBE load/store now derive optional base/index/scale addresses and legal
FLAGS/default widths from their raw fields, then compose generated byte-ladder
access and reversal with the RSP/STACK-aware numeric frame. Load captures its
read before writeback, including destination/source/index aliases and partial
STACK or SP destinations. Store captures native numeric source bytes before
its exact-width memory update. Complete observed guest memory, initialization,
GPRs, vectors, flags, PC, ordered events and fault rollback agree with the same
canonical ISA. `EndianBinding` enters the existing unified step. MOVBE_LOAD's
generic RUN_OP and MOVBE_STORE's direct macro have uniform per-token equality
and native-successor laws. Private-arena/native-memory permission, ABI,
definedness, C correspondence and compiler/native-link remain production
interfaces.

Focused/default Lean builds and9 axiom audits pass with140 stable proof inputs.
All90 prior numeric-frame and51 dispatcher theorem signatures remain available.
Audits report propext, Classical.choice, Quot.sound and Lean.ofReduceBool.
The expanded existing route oracle passes1671239 UBSan checks, retaining71
original observations and adding49152 full-frame scenarios over all16 data
registers, three native bases, four base/index kinds, four scales, each legal
width/default, aliasing and direct/dispatcher routes. Each frame checks every
GPR/tag, guest byte, all six flags and XMM0. The selector oracle passes4675 UBSan checks after its synthetic pointer read
uses alignment-safe byte copying. Its original misalignment diagnostic and
source remain archived. Canonical stack/memory/fault,1214scalar/72CPU-anchor
and15371condition suites pass; all162 actual compiled input hashes stay stable. O2 now covers38 tokens
(26direct/tengeneric/twobranch); coverage keeps32 pure register operations,
two control, two stack-memory and two addressed-memory models separate.

The full-runner input marker correction has its own receipt. The mistakenly
repeated7a7893bc9 run ended with actual make signal-15 after its exact process
and source epoch were recorded; its private export is retired. The replacement
runner reads `stack-memory-result-published.txt` and asserts exactc435a1dac
before exporting sources. Its actual full result is collected independently.
The wrong-source logs, manifest, script and signal receipt remain archived
under `full_runner_marker_correction`; MOVBE proof/source/oracle evidence is
under `x86_endian_addressed_dispatch_tokens`.

### Published addressed-stack source full check

`make check` on immutable publishedc435a1dac exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_c435a1dac`. This is the corrected runner’s actual addressed-stack
epoch. The earlier redundant7a7893bc9 signal-15 remains recorded separately;
subsequent MOVBE source has its own completion evidence.

### Memory condition bodies and full-frame token composition

CMOV_MEM and SETCC_MEM now bind every16 condition code, including PF, from
AUX's high byte into the unified simulator step and direct-token laws. Optional
base/index/scale fields derive the memory address from the same input frame.
CMOV uses the signed high32 displacement, a matched memory/target width or its
fallback, and captures its complete source read before evaluating the condition.
True writeback scalarizes the captured value; false32 zero-extends the old
native destination, while false16/64 retain the raw representation. SETCC uses
the complete displacement word and an exact one-byte store. Initialization,
ordered memory effects, faults, rollback, flags, vectors and all GPR/tag cells
retain the canonical observation through RSP/STACK normalization. The generic
private-arena/native-memory permission, ABI/definedness, C correspondence,
compiler and native-link interfaces retain their production scope.

The141-target focused/default Lean builds and9 axiom audits pass with140 stable
proof inputs. All92 prior numeric-frame and52 dispatcher theorem signatures
remain available. The trust record retains propext, Classical.choice,
Quot.sound and Lean.ofReduceBool. The existing CMOV route oracle passes28180495
UBSan observations: its26526735 original checks remain, and48640 new full-frame
scenarios add1653760 observations. The condition matrix includes all16 codes
and32 relevant flag combinations; address cases cover all16 CMOV destinations,
partialSP/STACK aliases, matched/fallback widths, scaled indexes, three native
bases, memory/register aliases, direct/dispatcher routes, six flags and XMM0.
SETCC also exercises an absent base and ignored FLAGS/memory-width fields.
All156 compiled input hashes stay stable. Canonical stack/memory/fault,
1214scalar/72CPU-anchor and15371condition suites pass.

O2 now covers40 C-model tokens (28direct/tengeneric/twobranch). Coverage keeps
32 pure register operations, two control, two stack-memory and four addressed
memory models separate;27 further reference-family models retain their raw
field/frame completion interfaces. `x86_condition_memory_dispatch_tokens`
records the proofs, source identities, original route count and complete checks.

### Published source full check 8aa94baa2

`make check` on immutable published8aa94baa2 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_8aa94baa2`. Every check retains its exact published source identity.

### Production partial-register source epoch

The coordinator’s9b0aa2b09 register-write update is checked against the current
physical files, published Git blobs and8aa94baa2 full-source manifest. Header
cf27e323c885 preserves whole storage for tagged byte/word writes through its
volatile temporary; generatorb8644bc7eaeb emits those branches. The generated
Lean model06cf3092860b and JSON0aea09b5a5c2 are byte-identical to the parent
commit. Fresh regeneration and three existing register-write axiom audits pass.
The bit/lane/scalarization and RSP/STACK frame theorems retain their scope.

All28 covered writer families (56 operation/token rows) now link this source
receipt. The complete8aa94baa2 `make check` exits0 and all1140 source hashes
match Git, including all four register-write inputs. Its existing MOV/MOVX/CMOV
route observations and the current28180495 memory-condition UBSan checks use
headercf27. Universal C/Lean and compiler correspondence remains its explicit
production interface. `x86_register_write_9b0_epoch` records the source pins,
unchanged pure contracts, original full-log observations and row list.

### Published source full check 6e51953dc

`make check` on immutable published6e51953dc exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_6e51953dc`. Every check retains its exact published source identity.

### Ordinary memory-store frame, dispatcher and token refinement

MOV_STORE_REG and MOV_STORE_IMM now compose through the universal x86 step and
per-token laws. Register stores capture the numeric source before storing its
low bytes, including the four high-byte registers and RSP/STACK aliases. Input
field bindings distinguish complete register-form displacements from signed
high32 immediate displacements and the low32 immediate value/sign extension.
Both widths/defaults and optional base/index/scale derive addresses from the
same input. The proofs retain complete observed state, byte initialization,
ordered writes and permission-fault rollback. Private arena/permission, ABI,
definedness, C-model correspondence, compiler and native-link interfaces remain
explicit. The existing general AUX-shift contracts and oracle cases are retained;
these native bindings use defined shifts0/8.

Focused141-module and default Lean builds and ten theorem axiom audits passed;
all143 transitive proof/toolchain input hashes are checked against publication.
The original94 NumericAddress and53 Dispatcher public signatures are retained.
The existing store route oracle passed1,292,621 UBSan observations:77 original
checks plus38,016 complete-frame scenarios with34 observations each. It covers
all16 source GPRs, legal high-byte sources, five widths/defaults, packed sign
boundaries, three native origins, scaled indices/address aliases, heap/stack
stores and both direct/dispatcher routes. Finite immediate fixtures use three
present-base kinds and small indices so their displacement fits signed32; the
theorems retain the complete bound address domain. Actual C inputs are pinned
and archived, including main6b3f31731d9d and reg-writecf27e323c885.

Coverage becomes42 O2 tokens (30 direct, ten generic, two branch), six addressed
memory models and25 additional partial families. Raw-register32, stack2,
control2 and replay totals retain their scopes. The audits report propext,
Classical.choice, Quot.sound and Lean.ofReduceBool. Raw logs, initial proof
diagnostics, source bytes and hashes are retained in the integration archive
under `x86_store_memory_dispatch_tokens`.

### Published source full check 23a3cfde9

`make check` on immutable published23a3cfde9 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_23a3cfde9`. Every check retains its exact published source identity.

### Memory unary and rotate read/modify/write refinement

ALU_MEM_UNARY and ROR_MEM now compose through the universal x86 dispatcher
step and per-token body/native-successor laws. A shared numeric-frame memory
transfer preserves the completed read before a write fault and commits the
result, flags and PC on a permitted write. Native input fields derive the
base/index/scale address from the complete displacement. Unary composition
uses the actual RHS1 generated result for INC/DEC/NEG/NOT and all six status
flags; ROR consumes the high AUX byte as its raw count and preserves PF/AF/
ZF/SF. The observed frame includes memory initialization, ordered effects
and fault rollback. Private arena/permission, ABI, definedness, C-model
correspondence, compiler and native-link interfaces retain their scope.

Focused141-module and default Lean builds and ten axiom audits passed. The
143 transitive proof/toolchain inputs and78 published replay inputs match
their221 publication hashes. All98 NumericAddress and54 Dispatcher public
signatures are retained. The existing ALU-memory route oracle passed
26,547,217 UBSan observations:261,137 original checks plus773,120 complete
frames with34 observations each. Address matrices cover heap/RSP/STACK/
absent-base forms, four index modes/scales, three native origins, widths
8/16/32/64/default and both direct/dispatcher routes. Separate matrices cover
all64 incoming six-flag combinations, width-specific signed boundaries and
every raw ROR count0..255 with mixed source bits. The actual156 C inputs
remain stable. Initial proof diagnostics and the earlier successful fixture
revision are retained with the final source, logs and hashes.

F's published1fb265102 replay ledger supplies the adopted production epoch
01ce447e7:1,144 forms/292,864 real-CPU/C/canonical observations, with zero
differences in each comparison. All72 artifact pins and six ledger files
match published Git. Each of124 updated central rows retains its preceding
epochs exactly. Numeric replay totals retain66/75 x86 and65/71 ARM plus the
separate monitor projection. Coverage becomes44 O2 tokens (32 direct, ten
generic, two branch), eight addressed-memory models and23 partial families.
The audits report propext, Classical.choice, Quot.sound and Lean.ofReduceBool.
The integration archive records `x86_modify_memory_dispatch_tokens` and
`production_replay_1fb_epoch`.

### Published source full check 0df15f53f

`make check` on immutable published0df15f53f exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_0df15f53f`. Every check retains its exact published source identity.

### Memory compare/test frame, dispatcher and token refinement

CMP_MEM_IMM, TEST_MEM_IMM, CMP_MEM_REG, TEST_MEM_REG and CMP_REG_MEM now
compose the complete numeric read/flags frame through the unified x86 step
and per-token body/native-successor laws. The field binding derives optional
base/index/scale addresses from the incoming state. CMP_MEM_REG and
CMP_REG_MEM use complete64-bit displacements; TEST_MEM_REG and both immediate
forms use signed high32 displacement. The immediate value uses low32 with
sign extension at64/default width. Numeric register reads cover RSP and STACK
aliases; operand-bit lemmas connect them to native low lanes. CMP's actual
OF=SF xor signedLT assignment uses its existing identity theorem. The model
preserves complete GPR/vector/memory state and retains all six status flags,
initialization metadata and ordered read/fault effects. Arena/permission, ABI,
definedness, C-model correspondence, compiler and native-link stages retain
their universal interfaces.

Focused141-module x86 and current ARM/default Lean builds passed, together
with16 theorem axiom audits. All100 NumericAddress and55 Dispatcher public
signatures are retained. The existing CMP-memory oracle passed22,371,524
UBSan observations:2,244 original checks plus657,920 complete frames with34
observations each. Address matrices cover all16 data GPRs, widths/default,
heap/RSP/STACK/absent-base forms, source/base/index aliases, scales, three
native origins and direct/dispatcher routes. Packed displacement fixtures
use three present-base kinds and small indices for representable signed32
deltas; the formal bindings retain the complete native field domain. Separate
matrices cover all64 incoming six-flag combinations and width-specific value
boundaries. Actual C/proof source hashes and initial proof diagnostics remain
in the existing integration archive under `x86_compare_memory_dispatch_tokens`.

The source audit also records A's publishedf0517e493 numeric3/4 immediate
aliases. All17 current generic source files match that publication, HEAD and
the passing0df15f53f full-check manifest. The universal direct dispatcher/
arithmetic alias theorems pass fresh audits; their conditional direct status
is explicit in four central operation/token rows. Unified ExecBinding/source-
emission alias transport and per-token specialized-body equality continue as
separate universal stages. The existing ARM observation and ABI premises
retain their scope. Coverage now has49 x86 O2 tokens (37 direct, ten generic,
two branch),13 addressed-memory models and18 additional partial families.
Replay rows and all T O4 cells retain their values.

### Adopted ARM immediate-alias replay correspondence

F's published92441b38a ledger connects the existing60 raw/direct groups and
61,440 QEMU/C/canonical observations to the adoptedf0517e493 immediate-alias
source. Each comparison has zero differences. The ADD_IMM, SUB_IMM and
ALU_IMM rows each retain20 groups/20,480 observations, the original candidate
time/binary/reference/trace identities and their separate production bridge.
All72 compiled C headers equal the adopted source;77 of79 captured source
files match it exactly, while two Python producer epochs retain their own
hashes. The current encoder reproduces all60 bindings for10 native forms
and30 raw/direct native byte pairs. The original candidate's adoption marker
remains part of its historical summary.

All163 artifact pins and six ledger files match published Git. Six central
operation/token rows add this source epoch while preserving every prior entry.
ARM sampled replay coverage becomes67/71 plus one explicit-monitor projection;
ADRP_GOT, ADRP_RODATA and RET retain their pending selected-replay status.
The ledger records16 epochs and222 operation/source rows. Formal O1/O2 counts
retain their distinct scopes:49 x86 C-model tokens,69 ARM observed conditional
models and two ARM direct immediate-alias components. Universal alias-emission,
compiler, ABI and native-link stages continue. The receipt
`arm_immediate_alias_replay_924_epoch` retains the complete source bridge.

### Published source full check 518d33529

`make check` on immutable published518d33529 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_518d33529`. Every check retains its exact published source identity.

### ARM immediate token bodies and alias binding

`ADD_IMM`, `SUB_IMM` and `ALU_IMM` now have three W/X numeric C-model
body equalities and canonical-step composition. Their generated direct macros
select `DIRECT_BODY_4`, use literal opcodes3/4/6 and obtain the immediate decision
from the captured generated selector. AUX continues to select the ALU operation.
The complete numeric dispatcher retains every field, state component, event and
fault. `ExecBinding.immediateAlias` transports a generic6 field binding into
numeric3/4; `source_immediate_alias_binding` carries that result through the
existing source and invocation emission theorems. Source/code/provenance,
permissions, ABI/definedness and C/compiler correspondence retain their explicit
production interfaces.

Default `lake build`, five generator/source checks, ten axiom audits and the
four existing semantic C oracles pass. The oracles retain all37,616 cases under
UBSan;192 existing theorem signatures retain their exact types. All395 focused
proof/producer inputs stayed stable, and19 unchanged production/contract files
match the adopted `f0517e493` Git epoch. The source snapshots, initial Lean
diagnostics and final checks are losslessly archived under
`arm_immediate_tokens_and_alias_binding` in
[the integration receipt](arm64-xdp-host-integration.json) and its existing gzip.
The central table now records71/71 conditional ARM modeled dispatcher rows and
3/71 ARM C-model O2 tokens; x86 stays49/75. The prior published `518d33529`
full `make check` separately passed with all1,140 source identities verified in
`full_make_check_518d33529`.

### Published source full check fe6049ac8

`make check` on immutable publishedfe6049ac8 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_fe6049ac8`. Every check retains its exact published source identity.

### Canonical ARM thread-pointer reads for kind4

The single ARM reference now decodes MRS TPIDR_EL1/EL2 for all32 Xt fields.
`State.threadPointer` supplies the resolved per-step CPU/EL/virtualization access
profile. The wire interface requires explicit `thread_pointer_reads` values for
MRS: each register carries a full64 value or an access-denial outcome. Successful
reads equal same-value MOV64 in the complete modeled state; XZR discards the
value while preserving SP. Access denial retains the incoming state and emits
an identified system-register fault. The generic register module also proves
decode, XZR, denial and EL-selection laws for T's kind4 composition. Current
CPU/profile resolution, exception-entry syndrome/vector, per-CPU relocation and
compiled/native-link correspondence retain their explicit production interfaces.

Default incremental `lake build`, the existing general/ARM/exclusive/addressed
reference checks, seven fresh V axiom audits and seven published T dependency
modules pass. MRS checks execute1,280 complete-state/profile/fault observations,
assemble64 native encodings independently with LLVM and exercise seven wire/
decode refusal cases. All383 focused proof inputs stayed stable; two additional
published C/Rust source pins match the production X10 words. Every original ARM
reference code line and its decoder prefix remain exact; the original register
module prefix remains exact. The source snapshots, initial diagnostics, final
logs and executed reference binary are retained under
`canonical_arm_thread_pointer_reference` in
[the integration receipt](arm64-xdp-host-integration.json) and its gzip archive.

The canonical ARM source is `082b90154c33c374ea58c5afb5259fc39b5b735fbcce2e6c0e0e6364785deb56`;
the executed reference binary is `f84cb2ecff4f0c68976e0c572d5b7e9fc15c3e7ab9cee7c17f39a2360d735a5a`.
The75/71 numeric catalogs,49/3 C-model O2 token totals and selected replay totals
retain their current domains. These two native system-register consumers
provide the kind4 reference interface. The separately published full
`make check` at `fe6049ac8` passed with all1,140 Git source identities verified
in `full_make_check_fe6049ac8`.

The captured MRS reference executable now uses lossless XZ inside the existing
archive. Its144,167,840 bytes round-trip to the same `f84cb2ecff4f` SHA256;
the gzip receipt shrinks from83,017,288 to51,243,874 bytes. Every preceding
gzip member retains its exact bytes. `binary_archive_compaction` records the
compression source, output and round-trip identities; all proof/source/check
results and coverage totals retain their published values.

### Published source full check a2fb22739

`make check` on immutable publisheda2fb22739 exits0. All1140 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_a2fb22739`. Every check retains its exact published source identity.

### Universal kind4 per-CPU MRS component

[The kind4 receipt](../kprog_tv_20261107/generic-native-link-arm-percpu.json)
adds18 passing universal audits. The exact alignment/u32 span/current EL1-X10
placeholder guards select the kernel's EL1/EL2 word under VHE. Four-byte
stores preserve surrounding bytes and code permissions; the temporary-storage
view and complete-copy relation carry canonical decode into final text.
Canonical full-state/effect/fault TV covers every finite prefix and reverse
execution reflection. A resolved current CPU/EL profile supplies the full64
per-CPU word or its access fault; the permitted read equals canonical MOV64.

The source-extracted production C case passes81,996 UBSan cases on host and
81,996 on AArch64 QEMU-user, each2,048 accepted and79,948 refused, with complete
buffer canaries and exact errors. All393 proof/tool inputs stayed stable, and
the generic Make target passes. It now joins `make -C kprog/formal check`,
reusing shared incremental caches. Initial diagnostics, final checks, sources
and proof artifact identities are retained in the receipt and its gzip archive.
Actual producer descriptor/PC and C-to-model correspondence, complete-copy/
fixup separation, executable lifetime, dynamic CPU/EL/VHE/profile binding and
complete invocation/compiler ABI remain the surrounding interfaces. O4 totals
are7 conditional,7 component,6 pending and1 trusted implementation; operation/
token and replay totals retain their published domains. V continues the O4
line following the three-lane handoff. The prior published `a2fb22739` complete
formal check separately passed in `full_make_check_a2fb22739`.

### Published source full check c68a23e2d

`make check` on immutable publishedc68a23e2d exits0. All1160 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_c68a23e2d`. Every check retains its exact published source identity.

ARM memory-token composition (`arm64_memory_token_bodies` in the existing
[integration receipt](arm64-xdp-host-integration.json)) adds six generic O2
body equalities and observed canonical-step laws: LOAD, STORE, LDRSB, LDRSH,
LDRSW and STLXR. Four axiom audits and the default Lean build pass; the prior
198 dispatcher theorem statements and module prefix retain their exact bytes.
The actual generated direct header equals the C dispatcher extraction, and
53,728 host UBSan cases compare complete register/tag/vector/NZCV snapshots,
independent store bytes and the exclusive input site/call count. The source set
contains177 stable inputs. The site-indexed theorem preserves the fresh0/1
outcome on each invocation under the existing native-field, monitor, memory,
source-emission and ABI relations. C/compiler and complete simulator closure
continue through those universal interfaces. Raw source, generated classifier,
executed binary, initial diagnostics and final checks are archived together.

ARM scalar-token composition (`arm64_scalar_token_bodies` in the existing
[integration receipt](arm64-xdp-host-integration.json)) adds52 generic O2
body equalities and canonical observed-step composition. The complete scalar
families retain their actual opcode/AUX/source/result/writeback choices and
established W/X domain. Two axiom audits and the default Lean build pass;
the prior202 dispatcher theorems and module prefix retain exact bytes.
Actual generated direct macros and L_EXEC agree on2,885,376 host UBSan cases,
with all16 NZCV inputs, all34 destination/first-source fields and full
register/tag/vector/memory snapshots. The prior53,728 memory checks also pass.
All175 inputs are stable:173 root Git blobs and two headers from the pinned
libbpf Git revision. Actual binaries/proof output use lossless XZ inside the
raw receipt; each compressed and original hash is verified. ARM C-model O2
coverage reaches61/71; complete raw/compiled, native field/address/provenance,
source-emission and invocation ABI interfaces continue through universal laws.

### Published source full check 01fba1f4d

`make check` on immutable published01fba1f4d exits0. All1161 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_01fba1f4d`. Every check retains its exact published source identity.

ARM pair/vector-token composition (`arm64_vector_token_bodies` in the existing
[integration receipt](arm64-xdp-host-integration.json)) adds nine generic O2
body equalities and canonical observed-step composition: LDP/STP, D0/Q0
loads/stores, FMOV and CNT/UADDLV. Two axiom audits and the default Lean build
pass; the prior204 dispatcher theorem statements and module prefix retain
exact bytes. The actual C macros agree on188,160 additional host UBSan cases,
including all32 FMOV banks/default bank, fixed D/Q widths, pair widths,
pre/post/index/displacement fields, all16 NZCV inputs and independent complete
store buffers. The earlier2,885,376 scalar and53,728 memory cases also pass.
All175 inputs retain stable hashes and published Git identities. ARM C-model
O2 reaches70/71; RET's outer-return token relation is the remaining token item.
Complete raw/compiled closure continues through the explicit native-field,
memory/profile/effect, provenance, source-emission and invocation ABI interfaces.

ARM emitted-return token composition (`arm64_return_token_body` in the existing
[integration receipt](arm64-xdp-host-integration.json)) adds literal-switch,
route/body equality and canonical invocation-step composition for RET_TO.
Four axiom audits and the default Lean build pass; the prior206 dispatcher
theorems and module prefix retain exact bytes. Actual production C macros pass
9,437,184 host UBSan cases:2,976 outer returns,4,960 internal targets and
9,429,248 explicit refusals. Full GPR/tag/vector/NZCV preservation, private LR
scratch, whole-context canaries, two skb CB writes, materialized low32 X0 and
entry-input counts agree. The actual generator passes132 operand/site cases.
The181 stable inputs have179 root Git and two pinned libbpf Git identities.
ARM C-model token coverage reaches71/71:70 numeric bodies and one emitted-return
control body. Complete native code/provenance, physical exit memory/ABI and
compiled-BPF correspondence continue through the explicit universal interfaces.

The full check at source d2246b5c8 records linker ENOSPC and an interrupted
CPU-trace finalizer (`failed_full_check_d2246b5c8_resource`). Its1161 source
hashes match both Git and the retired export; the complete CPU trace and raw
failure controls are recovered and archived. The latest published source
continues through the complete check with the existing incremental caches.

### Published source full check 2ea4ef3f3

`make check` on immutable published2ea4ef3f3 exits0. All1162 exported source
SHA256 values match its Git blobs; its private export is retired. Full log,
source manifest, CPU trace and exit receipt are archived under
`full_make_check_2ea4ef3f3`. Every check retains its exact published source identity.
