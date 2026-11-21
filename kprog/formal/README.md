# Native simulator verification

## External-base migration (M1–M4 complete, M5 in progress)

The operator's replacement plan is in [todo section 4](../docs/todo.md).
The external bases are forks, pinned as Git submodules; changes needed by
kprog belong in those forks. M3 replaced the local ISA bodies; M4 adapted the
shared simulator C for Clight export. M5 now proves the exported handlers
against those bases; its counts must be recomputed.

Clight imports are [generated build products](results/clight-build/README.md).
`lake build` generates them from C before module-input processing;
`make clight-sources` runs that build step directly. The seven profile C
snapshots live in `c/`, with build symlinks preserving their original export
metadata. Edit C directly. The current proof route is `ClightRefinement` over those exports and the mature
ISA bindings. On the coordinator’s 2026-11-16 19:19 instruction, the superseded
JSON/generated-contract proof route and its generators were deleted; see
[the retirement inventory](results/legacy-retirement/README.md). Historical
counts and migration checkpoints below describe the earlier route, whose
source is retained in Git history. They are not current refinement coverage.
Full build validation is recorded with that inventory; M5 correspondence and
O1/O2/O4 recount remain open.

The [x86 width helper](KProgFormal/ClightRefinement/X86Width.lean) executes the
actual exported C function in six silent Clight transitions for every byte code,
global environment, memory and continuation. Zero selects eight bytes; each
other code retains its value, with the entire memory preserved. Its
[focused build and public audit](../results/kprog_verification_20261107/x86-width-clight.log.gz)
record the existing CompCert external-function/assembly semantic axioms.
This C-helper component retains the current M5 ISA-handler count and root/full
confirmation ownership.
For Kstop calls, every finite relational run is silent and can finish at that
same return; each terminal execution has the original result and memory, and
the complete relation terminates. The [all-behavior audit](../results/kprog_verification_20261107/x86-width-behavior.log.gz)
records all four public contracts at the same semantic assumptions.

The [saved-frame word component](KProgFormal/ControlABI/NativeFrameWord.lean)
proves adjacent qword preservation over wrapping addresses and the exact mature
x86 LEAVE/RET state after a saved-frame store, for every machine state and word.
It derives saved-RBP preservation exactly when the replacement equals the
original word, and specializes the store address under the explicit RSP=RBP
entry relation. Live state and canonical adjacent return address are premises;
physical permissions, emitted wrapper correspondence and native/B projection
remain platform obligations. Its [four public audits](../results/kprog_verification_20261107/native-frame-word.log.gz)
use the existing logical axioms. This O4 component retains the partial M5 scope.

The [x86 shift-count helper](KProgFormal/ClightRefinement/X86ShiftCount.lean)
executes the actual exported C call in six silent Clight transitions for every
64-bit input, byte width, environment, memory and continuation. Its byte result
uses mask 63 at width eight and mask 31 otherwise. For every mature x86 operand
size, the complete call returns exactly X86.Flags.shiftCount applied to the
input's low byte. Every finite Kstop execution is a silent prefix of the same
return, each terminal state has that result and original memory, and the
complete relation terminates. The [five public audits](../results/kprog_verification_20261107/x86-shift-count.log.gz)
record the final standard-library arithmetic proof and existing logical/CompCert
semantic axioms; earlier diagnostics retain their attempt labels. This helper
correspondence remains a component of the open M5 ISA-handler obligation.

The [x86 left-shift result proof](KProgFormal/ClightRefinement/X86ShiftLeft.lean)
executes the actual exported production helper for every pair of 64-bit operands
and all four mature operand sizes. The result is the mature model's width
truncation of the shifted, width-truncated input, using its Flags.shiftCount.
The byte, word, dword and qword calls take 19, 23, 27 and 27 silent internal
transitions respectively, preserving complete memory for every environment and
continuation. Every finite Kstop run is a silent prefix of the same result,
terminal states are unique, and the complete relation terminates. Its
[three public audits](../results/kprog_verification_20261107/x86-shift-left.log.gz)
record the existing logical/CompCert semantic axioms and original proof budgets.
Flag updates, operand writeback and dispatcher composition remain the
surrounding instruction-refinement obligations.

The [actual ALU SHL call proof](KProgFormal/ClightRefinement/X86ShiftLeftAlu.lean)
selects case 5 of the production ALU function, enters the genuine left-shift
callee, and resumes through its original assignment, switch break, loop break
and return. The environment's real symbol and internal-function bindings are
premises; the callee signature and caller continuation are derived from the
actual definitions. The call takes 43, 47, 51 and 51 silent transitions for
byte, word, dword and qword operands, for every operand pair, memory and
continuation. It returns the mature ISA arithmetic result and preserves complete
memory; arbitrary finite Kstop runs have silent prefixes, unique terminal state
and termination. The [three public audits](../results/kprog_verification_20261107/x86-shift-left-alu.log.gz)
record the inherited logical/CompCert semantic axioms. Full instruction flag
updates, operand writeback, dispatcher and enclosing program binding remain open.

The [raw ALU_REG arithmetic-call site proof](KProgFormal/ClightRefinement/X86ShiftLeftSite.lean)
uses its actual generated fragment 59. Given genuine ALU/SHL bindings, an
unshadowed ALU symbol and the four typed incoming operand/code/width temporaries,
it executes 48, 52, 56 and 56 silent steps for the four operand sizes and every
operand pair. It resumes the same caller function, local environment and
continuation, with complete memory preserved. The call and result temporaries
both contain the mature ISA result; every other temporary retains its value.
The [three public audits](../results/kprog_verification_20261107/x86-shift-left-site.log.gz)
record the exact source, dependency build and existing semantic axioms.
Deriving these incoming observations from handler entry, selecting this route
and composing the following flag and writeback stages remain open.

The [actual ALU_REG SHL route](KProgFormal/ClightRefinement/X86ShiftLeftRoute.lean)
has a kernel-checked structural identity with the complete original handler body.
Operation 5 follows its real SBB/ADC gates, executes the original arithmetic
call fragment, and resumes the original flags/writeback remainder. For all
operand pairs and sizes, the route takes 52, 56, 60 and 60 silent steps to that
boundary, retaining complete memory, caller locals and continuation with the
exact source result/call temporary map. The existing typed input and genuine
function-binding premises remain explicit. Its
[four public audits](../results/kprog_verification_20261107/x86-shift-left-route.log.gz)
record the source identity, selected route and relational composition at the
original proof budgets. Entry and operand-read derivation, execution of the
remaining flags/writeback code and enclosing dispatcher remain open.

The [actual old-CF input proof](KProgFormal/ClightRefinement/X86ShiftLeftCarry.lean)
locates the two real exported composite declarations and checks their complete
layouts against the imported type builder. It derives the CF pointer field at
byte offset 120 from those members. With the two matching world-layout records,
the original binding temp and genuine current-memory pointer/byte loads, eleven
silent source steps reach the untouched classifier for every old CF byte and
caller state. The pointer, loaded byte and old-CF temporaries read back exactly;
all other temporaries, complete memory and caller locals retain their values,
with the original loop and writer continuation. Its
[six public audits](../results/kprog_verification_20261107/x86-shift-left-carry.log.gz)
record existing logical/CompCert axioms and original proof budgets. Full world
and entry representation, classification, flag computation and writeback remain open.

The [actual SHL flag classifier](KProgFormal/ClightRefinement/X86ShiftLeftClassify.lean)
follows all nine original comparisons and nine source writes for operation 5.
Thirty-six silent internal steps reach the original switch with kind 7, and
one more selects its original shift flag branch with the real switch
continuation. Every source cast remains in the execution and exact temporary
map. The kind reads back seven; all other temporaries, caller locals and complete
memory retain their values for every incoming map with the typed operation.
The [six public audits](../results/kprog_verification_20261107/x86-shift-left-classify.log.gz)
record the actual classifier/switch identities, relational execution and existing
logical/CompCert axioms at original budgets.

Its universal route composition joins the actual arithmetic route, old-CF
loads and classifier into 100/104/108/108 silent steps for byte/word/dword/qword
operands. The binding and operation observations at the two intermediate states
follow from the preceding temporary frame laws. The endpoint retains the full
heap, caller locals and exact nested temporary map at the original shift flag
branch. Callee bindings, the two source-derived world layouts, typed incoming
operands and genuine current-heap CF loads are explicit input premises. The
[seven public audits](../results/kprog_verification_20261107/x86-shift-left-through-flags.log.gz)
record this composition and the preceding classifier results at original proof
budgets. Entry/world representation, actual flag stores and the writer remain open.

The [actual width-shape helpers](KProgFormal/ClightRefinement/X86WidthShape.lean)
execute the complete exported bit-width and mask functions for every byte code,
heap and continuation. Their original comparison, assignment and cast paths take
6/10/14 steps for codes 1/2/other. For the four mature ISA widths the returned
values are exactly its existing bit count and 64-bit mask. Every finite execution
at the terminal continuation is a silent prefix of the same return; terminal
returns are unique and infinite executions are excluded. The
[ten public audits](../results/kprog_verification_20261107/x86-width-shape.log.gz)
record default proof budgets and the existing logical/CompCert axioms; the two
native value equalities use no axioms. The original shift flag call sites are
linked by the width-prefix proof below; the flag stores remain open.

The [original shift flag width prefix](KProgFormal/ClightRefinement/X86ShiftFlagWidths.lean)
retains the selected source case, loop and switch fallthrough. It performs the
raw-width assignment and all three original effective-width, bit-count and mask
calls, returning to the untouched operand/count/flag code in 45/53/61/61 silent
steps for byte/word/dword/qword widths. Its seven written temporaries read back
the derived ISA values; other temporaries, caller locals and complete memory
retain their incoming values. Real callee bindings, caller symbol lookup and
typed incoming width are explicit input premises. The
[nine public audits](../results/kprog_verification_20261107/x86-shift-flag-widths.log.gz)
record the actual source identity and relational execution at existing proof
budgets and inherited logical/CompCert axioms. Operand/count setup, flag stores,
writeback and entry/world correspondence remain open.

The width-prefix route composition joins original arithmetic dispatch, old-CF
reads, classification and all three real width calls in one 145/157/169/169-step
silent execution. Its typed width at the last call stage follows from the
preceding Site/Carry/Classify temporary frame laws. The full incoming heap and
caller locals survive, with the exact nested source temporary map and original
operand/count/flag continuation. All sizes, operands and old CF bytes share this
theorem under the actual callee/layout/heap input observations. The
[ten public audits](../results/kprog_verification_20261107/x86-shift-through-widths.log.gz)
record the universal composition and the preceding source results at existing
budgets and inherited logical/CompCert axioms. Actual operand/count setup,
flag stores, writeback and entry/world correspondence remain open.

The [original shift flag input preparation](KProgFormal/ClightRefinement/X86ShiftFlagInputs.lean)
executes both operand masks, the real two-argument count call and the source
sign-mask/operation assignments in 25 silent steps. For every pair of 64-bit
operands, result, size and caller heap, six source temporaries read back the
mature truncations/count and derived sign/operation values. Other temporaries,
the complete memory and caller locals retain their input values at the original
flag stage. Callee lookup and genuine incoming operand/width observations remain
explicit premises. The [nine public audits](../results/kprog_verification_20261107/x86-shift-flag-inputs.log.gz)
record actual source identity, relational execution, the mature count equality
and temporary frames at existing budgets and inherited axioms. Composition with
the preceding route, flag stores, writeback and entry/world correspondence remain open.

The [producer proof route](results/m5-unified-producer/README.md) uses Clean's
link of the complete Entry/Program exports as its environment. The linked
foundation sits below Producer; input and callback bindings use the actual
linked blocks. Provider outcomes and the genuine continuation/native
correspondence remain explicit M5 obligations.
The [global-memory proof](results/m5-global-memory/README.md) derives successful
initialization of the linked 186 functions and two data globals, their exact
permissions and frontier 189, and separation from the actual producer locals.
The [linked NOP procedure](results/m5-linked-nop/README.md) executes all 19
transitions in that same environment with actual handler/callee bindings and
retains the concrete register relation. The [producer entry view](results/m5-producer-entry-view/README.md)
connects actual header flag readbacks to its borrowed-entry reader. The
[GPR table view](results/m5-producer-gpr-view/README.md) follows the real word/tag
tables and retains pointer values and tag bits. The [vector view](results/m5-producer-vector-view/README.md)
follows the embedded pointer arrays and all 32 low/high pairs. The
[joint register view](results/m5-producer-register-view/README.md) adds actual
SP readback and assembles the existing GPR/SP/vector/flag relation over one
reached memory. The [RAW setup composition](results/m5-entry-admissibility/README.md)
derives SP, x0 context and x0/x30 tags from the actual preceding stores, with
the source register index as cell map. The [64-visit vector input proof](results/m5-vector-input-sequence/README.md)
derives the vector buffer and composes it with that RAW setup, retaining each
provider trace and post-memory. The [four-flag/LR prefix](results/m5-flag-input-sequence/README.md)
adds the actual masked flag stores and LR-zero assignment, deriving final
NZCV bytes in the combined 68-visit execution. The [x30/table prefix](results/m5-table-prefix-registers/README.md)
derives the zero payload and both pointer tables from 196 actual source
transitions. The [30-GPR traversal](results/m5-gpr-input-sequence/README.md)
now composes the actual producer call through all 98 input visits to the
register relation, deriving its source data and threading both temporary
updates. The [source-initialized NOP contract](results/m5-initialized-nop/README.md)
applies the actual 19-transition procedure to that live entry in the initialized
global world, retaining global permissions and the old producer frontier.
The [register storage proof](results/m5-register-storage/README.md) now carries
actual roots, 62 writable cells, SP data and allocation separation through that
same 98-visit construction; observer APIs project the stronger witnesses.
The [scalar writer contract](results/m5-register-write/README.md) executes the
actual 67-transition procedure for ordinary GPRs at widths 4 and 8, derives its
two stores from those permissions, and preserves other cells and caller memory.
The [writer view proof](results/m5-register-write-view/README.md) retains the
same writable storage, characterizes all GPR reads after writing, and relates
the GPR bank and SP to LNSym's public register write with identity cell binding.
The [complete writer register contract](results/m5-register-write-frame/README.md)
also carries the actual flag/vector pointer bindings, preserves all SIMD/NZCV
reads, and proves every relational execution is a silent prefix of the same
register-refining return, with no infinite execution.
The [MOV immediate dispatch proof](results/m5-arm64-mov-immediate/README.md)
links the complete Numeric unit through the imported linker and proves the
first 54 generic-handler transitions, including real allocation and both
width and path-selector calls. The [complete MOV scalar procedure](results/m5-arm64-mov-suffix/README.md)
continues through the eager NONE read, both register stores and real local-frame
freeing in 203 transitions, retaining the same producer storage and successful
stores. The [final register/MOVZ contract](results/m5-arm64-mov-view/README.md)
transports the complete register relation through that free at the original
frontier, proves unique silent termination, and binds ordinary W/X MOVZ at
shift zero to the actual fetched/decoded LNSym checked step, PC+4 and empty
new event/fault delta. The [wide-immediate contract](results/m5-arm64-mov-wide/README.md)
extends ordinary MOVZ/MOVN to every valid W/X halfword column, using the live
alias normalizer's shift/complement/width-mask literal binding. The
[XZR contract](results/m5-arm64-mov-zr/README.md) proves the actual 38-transition
no-cell writer and 174-transition generic call for WZR/XZR, preserving the
original caller frontier and relating all legal MOVZ/MOVN columns to the
checked native step. The [MOVK source contracts](results/m5-arm64-mov-keep/README.md)
prove its distinct 27-transition dispatch, actual DST reader edge, 26-transition
merge and real writer call, relating the source insertion to LNSym's public
operator. The [complete MOVK zero-register contract](results/m5-arm64-mov-keep-call/README.md)
executes the actual 156-transition call through frame free, preserves the original
register-reader frontier, and composes with the mature checked WZR/XZR step.
The [ordinary MOVK reader](results/m5-arm64-mov-keep-read/README.md) executes in
the actual linked world using its five required layout facts, derives scalar
admission from real loads/stores and composes the 105-transition branch through
the real writer edge. The [ordinary scalar MOVK contract](results/m5-arm64-mov-keep-ordinary/README.md)
composes all 203 actual call transitions, both stores and frame free, retains
the original register-reader frontier, and binds legal W32/X64 insertions to
the mature checked step. Program-level obligations stay open.
The [Numeric global initialization](results/m5-numeric-global-memory/README.md)
derives the complete linked program's initialized memory, 204 frontier and
permissions for all 203 definitions, including the real data globals. Its
actual producer allocation preserves those globals and places every local
beyond them. The older 189-frontier witness remains distinct; provider traversal
and caller admission still need transport into this environment.
The [Numeric producer prefix](results/m5-numeric-producer-prefix/README.md)
now executes the actual 580-transition initialization in that world and reaches
the genuine first input call after 594 transitions, using its actual symbol
binding and Kcall continuation. Both caches remain cold and the original
204-frontier global frame is retained; provider outcomes remain separate.
The [first Numeric provider-return contract](results/m5-numeric-producer-input/README.md)
resumes every admitted scalar outcome at that reached call memory, preserving
its actual world, trace and supplied post-memory through both source stores.
It derives x0/tag readbacks and retains the context temporary; globals frame
from initialization only under the provider's own corresponding frame.
The [Numeric GPR-input sequence](results/m5-numeric-producer-gpr-inputs/README.md)
now executes all 30 actual visits from initialization, with ordered provider
traces and derived word/tag cells. Both caches remain cold, `_ctx` survives,
and the original 204-frontier global frame and allocation permissions remain.
The [Numeric pointer-table composition](results/m5-numeric-producer-tables/README.md)
then executes the 10-transition x30 zero branch and 186 table transitions.
Both real 31-slot tables point to the allocated cells, with all 31 word/tag
readbacks derived, the 30 provider traces retained, and caches/context/global
framing preserved. It reaches the source boundary before the four flags.
The [Numeric flag composition](results/m5-numeric-producer-flags/README.md)
continues through all four flag input visits and the separate LR-zero store.
It derives the masked flag bytes and LR zero while preserving both tables,
all GPR data, caches, context and global framing. The 34 actual provider traces
remain ordered; the result stops before the 64 vector input visits.
The [Numeric vector composition](results/m5-numeric-producer-vectors/README.md)
then executes all 64 vector input visits, deriving each low/high word in its
actual allocated array. All 98 provider traces remain ordered, and the tables,
GPRs, flags, LR, caches, context and global framing survive. The result reaches
`afterVectorInputs`, before RAW/header processing.
The [Numeric stack/context composition](results/m5-numeric-producer-context/README.md)
adds 90 pure transitions: 24 tag clears, SP zero and five context stores. It
derives helper context/ABI values, x0 context with RAW tag 1 and x30 RETURN
tag 10, retaining the tables, other registers, flags, vectors, caches and
98 traces. A represented-context premise keeps the pointer cast defined.
The [Numeric header-pointer composition](results/m5-numeric-producer-header/README.md)
constructs all 12 scalar header pointers in 36 transitions, preserving the
reached register data and 98 traces. Both borrowed cache-storage resources
and their cold values are derived at that same memory; the stores execute once.
The [Numeric null-vector header composition](results/m5-numeric-producer-header-vectors/README.md)
executes the next 64 null pointer stores in 192 transitions, preserving all 12
scalar pointers, input vector words and earlier initialized data. Both cache
resources and cold values are derived again at that reached memory. The 98
provider traces remain unchanged; the header tail and live vector loop follow.
The [Numeric header-tail composition](results/m5-numeric-producer-header-tail/README.md)
adds the last 16 header stores in 48 transitions. Both callback symbols and
function bodies are derived in the actual Numeric environment; stack-tag and
helper-context pointers connect to the earlier locals. All 92 header readbacks,
initialized data, cache resources and 98 traces survive up to the live vector loop.
The [Numeric live-vector loop](results/m5-numeric-producer-vector-loop/README.md)
executes all 32 iterations in 362 transitions, deriving 64 live pointers to
the existing input words and all 32 borrowed-reader pairs. Scalar/tail fields,
other initialized data, cache resources and 98 traces survive. The loop ends
with `_i = 32` and preserves other temporaries, including the retained `_ctx`.
The [Numeric register-storage proof](results/m5-numeric-producer-register-storage/README.md)
derives all 62 writable word/tag cells and the complete GPR/SP/NZCV/vector
reader results at that same reached memory. The joint architectural relation
follows under explicit native register-state bindings; those bindings remain
caller-admission work.
The [Numeric continuation proof](results/m5-numeric-producer-continuation/README.md)
retains the actual continuation parameter through all 98 input visits and
the setup suffix to the same reached storage/view state. Context, data,
resources and traces are preserved; actual callee validity and native bindings
remain the next caller-admission obligations.
Actual provider admissibility, native memory/origin/alias bindings and program
control closure remain open.

| Base | Fork / submodule | Pinned source | Upstream toolchain |
|---|---|---|---|
| AArch64 | [eunomia-bpf/LNSym](https://github.com/eunomia-bpf/LNSym), `external/LNSym` | `da428593b21d` | Lean 4.35.0 |
| x86-64 | [eunomia-bpf/x86lean](https://github.com/eunomia-bpf/x86lean), `external/x86lean` | `28640eb74b85` | Lean 4.32.0-rc1 |
| Clight | [eunomia-bpf/clean](https://github.com/eunomia-bpf/clean), `external/clean/export` | `fee9302` | Lean 4.32.1 |

`make -C kprog/formal mature` builds the migration Lake package on Lean 4.35.0,
importing the external `Arm`, `X86`, `CCLib` and `Clightdefs` libraries directly.
The combined build passed on 2026-11-14 (121 Lake jobs), importing all four
libraries on the common toolchain. The x86lean fork patch `74a2e2849cde`
uses an explicit Boolean-decision bridge for the existing masked-count
hypothesis; its theorem statement and instruction semantics are unchanged.
Build output and the earlier failed attempts are retained in
`/workspaces/kprog-raw/formal/m1-compat-2` and `m1-compat-1`.
The main package now uses Lean 4.35.0 and the same three pinned external
path dependencies as the M1 integration package. M1–M4 are complete; the
[M4 closure review](results/m4-closure/README.md) maps the canonical C, 23
exports, bindings, native preservation checks and PERF expansion evidence.
The legacy counts below describe the old foundation, not migrated
Clight-to-external-ISA proofs. Retirement occurs at M6.

LNSym and x86lean retain their Apache-2.0 licenses. Clean retains its own
[LICENSE](external/clean/LICENSE): its tree is under INRIA non-commercial
terms, with the listed components, including `export/`, also offered under
LGPL-2.1-or-later. Keep those license terms separate. Clean explicitly labels
its C-to-Lean exporter/semantics experimental in its upstream README; the
CompCert front end and the Lean export/semantics have separate trust claims.

M3's first native binding (`m3-root-integration`) routes canonical x86 NOP,
MOV, arithmetic, logical, unary, LEA, BSWAP and MOVBE load/store families through
the fork. `plannedReadAddresses` uses the fork's existing access plan to
materialize arbitrary native byte functions into its finite representation;
checked execution then recomputes targets and validates access. Only actual
write effects update the original function, preserving untouched/uninitialized
bytes. Atomic observations retain both old/new values in the existing adjacent
atomic-read/write view. The undefined-bit oracle is internal choice state;
every original architectural field, memory/effect/fault channel and distinct
model refusal remains observed. JSON execution rejects model refusals.

The binding and 38 kernel-decide regression cases passed a 17-job component
build; the unchanged 8,103 fork cases passed 156 combined and 113 standalone
jobs. Seventeen retired local numeric/handler definitions were removed; the
reference module is 19 lines smaller. Its initial whole-package 4.35 baseline
failed in 15 old modules (33 errors, retained), including the old AArch64
decoder and legacy proof/API compatibility. This is not full-package acceptance:
remaining x86 families and provenance integration are still M3 work;
Clight/theorem migration and final checks remain M4-M6. The AArch64 replacement
and ARM comparison have since advanced as follows.

The next x86 binding (`m3-x86-families`) routes CMOV/SETcc/branches,
XCHG, shifts/rotates, BMI, IMUL/MULX, DIV/IDIV, widening/sign-high, POPCNT,
XMM0 moves, stack transfers, CALL and zero-release RET through x86lean's
checked step. Sixty retired local definitions were removed. Native F6/F7 `/4`
now binds unsigned MUL to the existing `muldiv.mul`; no local product function
was added. The shared C implementation remains PERF's implementation, with
Clight refinement still pending M4/M5.

Fork `daad9554c1f7` adds the missing register-only CEXT access plan and
corrects CALL preflight priority: source read, stack-write check, then target
canonicality. The existing hardware replay establishes the denied-write versus
bad-target order. All original checked-access profiles remain; the revised
CALL goldens and 30 new cases pass with the reference and 38 native-memory checks
in 191 Lake jobs. Fourteen existing x86 suites pass 112,704 full-state cases,
including faults, plus the base wire regressions; hardware/encoding checks run
inside those suites also pass. The MOVX suite additionally passes 6144
hardware/handler results and all three BPF compilations after selecting v3 for
the existing ALU32 inline assembly. This changes a formal check command only.
Raw results and all failed attempts are in
`/workspaces/kprog-raw/formal/m3-x86-families`.

The wire checks compare their independent expected masks as data, then allow
only ISA-undefined flag/register bits to vary. All other physical state, memory,
faults and complete event prefixes remain compared. Register-indexed memory BT
now records the fork's selected-byte read; its immediate form retains the word
read. Reconciling that observation with the old C is M5 work. At that step, REP (including
address32 and source segments), RET imm16, LEAVE and UD2 still awaited migration,
along with provenance integration and the x86 Sail comparison. These component
checks are not whole-package acceptance or migrated O1/O2/O4 counts.

REP MOVS/STOS now also use the fork (`m3-x86-rep`). Its shared
`StringContext` carries address32 and the resolved source base into both
numerical execution and checked access. The native wrapper composes exactly
the input RCX/ECX iterations plus the fork's zero-count completion step;
it has no element-copy, stride or counter-decrement interpreter. Each
iteration rematerializes current memory, so overlaps see preceding writes.
Completed iterations and read prefixes survive faults; address32 entry
normalization remains visible even at zero count or the first fault.

The existing REP suite now covers STOS as well: 1360 hardware cases, 80 actual
restart faults and 2150 full-state transitions pass, including counts above 64,
maximal-count first faults, source segments, arbitrary initialization and
wrapping. Original noncanonical maximal-count inputs remain, with the fork's
canonicality-before-permission fault category. The previous 112704 x86 cases
and base regressions pass again on the same executable. Fork `1fb8cfc69363`
adds a 512-case prefix/access/frame matrix and preserves every prior checked-
access case; all pass with the reference in 191 Lake jobs. The stopped-state law
now covers arbitrary contexts, and
two existing REP proofs explicitly unfold the default context without changing
their statements. Raw attempts are in `/workspaces/kprog-raw/formal/m3-x86-rep`.
RET imm16, LEAVE/UD2, provenance and x86 Sail integration still remain M3 work.

The remaining x86 control entries now also execute the fork
(`m3-x86-control`). Fork `28640eb74b85` extends the existing near-RET operation
with an unsigned imm16 release, defaulting to zero for the old API, and adds
LEAVE's incoming-RBP read to checked access. RET imm16, LEAVE and UD2 now have
no local interpreter bodies. Seven original embedded LEAVE/UD2 proof statements
and scripts are retained in the existing `Refinement/X86Dispatcher.lean` for
M5; they are not claimed as proofs against the new basis.

The reference and checked-access suites pass 191 Lake jobs, including 65
native-view cases and 60 new fork control cases. The fork's coverage module
passes 22 standalone jobs on 4.35; its `Tests` namespace is checked there to
avoid the existing root-package overlap with LNSym's `Tests`. The extended
CALL/RET/LEAVE/UD2 harness passes 476 complete CPU/trap observations and 1659
full-state/profile/fault transitions, including 48/57-bit boundaries, imm16
release, ignored old RSP, wrapped reads and malformed input rejection.
Noncanonical LEAVE stack accesses produce hardware #SS (trap 12), while bad
CALL/RET targets produce #GP (trap 13); both retain the flat reference's
`non_canonical` category. All registers, memory and flags before exception
delivery remain checked. All other x86 suites, including REP, pass again;
combined this is 115,234 full-state cases plus base regressions. Signed RET
assembly aliases and the default zero-release API are also retained.
Raw attempts/CPU rows/hashes are in
`/workspaces/kprog-raw/formal/m3-x86-control`. Numerical execution replacement
is complete; provenance and x86 Sail integration remain M3 work. Whole-package
Clight/theorem migration and final checks remain M4-M6.

AArch64 now stores the full LNSym `ArmState` in its thin native wrapper.
The original native word is decoded by LNSym and loaded at the input PC;
`stepi_checked` supplies every numerical step. All GPRs/SP, all32 SIMD cells,
arbitrary byte memory/attributes, per-step exclusive/MRS inputs and complete
external traces remain in that machine. One extra word preserves native flag
bits outside NZCV. The old local decoder, arithmetic and instruction dispatcher
were removed. Model refusals stay distinct from architectural access faults.

The rebuilt `reference` executable passed 184 Lake jobs, including the existing
38 x86 binding checks. ARM protocol checks passed 962 full-state addressed/SIMD/
LSE2 cases,84 exclusive cases,1280 MRS cases and35 input/encoding rejections;
LLVM also independently encoded64 MRS words. LSE2 inputs change actual unaligned
RMW admission, while crossings still fault. Exclusive goldens now retain the
fork's reserve-before-read and translation-permission-before-attempt ordering;
the old failures/raw expectations are preserved. This does not prove the old
simulator C refines those effects: that reconciliation remains M5 work.

[`compare_sail_arm.py`](tools/compare_sail_arm.py) restores the ARM comparison
from the four retained ASL cohorts. It checks every selected archive payload's
size/hash and compares fresh, explicitly identified LNSym output with the pinned
ASL observations. The new run has5016 agreements and the same12 recorded
monitor-profile differences; their original inputs/outcomes and the matching
cohort are all retained (`m3-arm-binding/asl-replay-2`). The old Sail executable's
`/var/tmp` target is absent, so this is **archived ASL observation comparison,
not a live Sail rerun**. Scope remains X0..X30/SP/PC/NZCV/V0/supplied memory;
permissions, typed effects and monitor ordering have separate protocol checks.
The binding uses only the original three standard axioms, with no new admission.

## Operation coverage (M2 complete)

LNSym `da428593b21d6dfa02c6d063600d9ed817747fd5`, x86lean `78534ab3924948a93a3182af95b53728bc0f811b`.

Source inspection, not refinement proofs or conformance results. `present` means an execution path exists; `partial`/`missing` remain M2 work; `layer` identifies linking/ABI transport above an existing ISA form. Memory permissions, initialization, fault prefixes, exclusive ordering and ABI require explicit relations.

LNSym `4a9bc9df5a6e` adds the conditional increment/invert/negate forms through
its existing execution function and expands its random conformance generator.
The combined build and 24 encoded regression vectors passed on 2026-11-14
(`m2-select-3`, 122 Lake jobs). These use upstream-style `native_decide` finite
checks; they are not hardware differential results or migrated refinement counts.

LNSym `093c3a4d9eea` also fixes FMOV field31 to use XZR/WZR rather than SP.
The combined build passed 123 Lake jobs including the conditional-select suite
and the existing XZR suite with four new FMOV regressions (`m2-fmov-zr-1`).

LNSym `7f683544abb7` adds MSUB, UMADDL/UMULL, SMADDL and UMULH plus W/X UDIV.
Twenty-nine encoded vectors and an invalid-width check passed in the combined
124-job build (`m2-multiply-divide/build-1`), covering aliasing, zero division,
32-bit truncation, signed widening, high-half multiplication and the GPR/flag frame.
These are finite regression checks; M2 remains open for the remaining forms.

LNSym `78658b3affc4` adds decoded EXTR/ROR and conditional compare (CCMP/CCMN,
register/imm5), including the flags-only register footprint. Eleven extraction
vectors, 23 comparison vectors and three invalid extraction encodings passed
with the previous suites in a 127-job combined build (`m2-extract-compare/build-1`).

LNSym `de5a36443abd` extends the shared single-register transfer path with signed
GPR loads, halfwords, unscaled GPR, pre-index and register-offset forms. Execution
and register-footprint decoding share the scalar/SIMD load classification; SP
alignment failure commits neither data/writeback nor PC advance. The combined
129-job build passed 68 load vectors, 33 store vectors and four refusal checks,
plus the retained LDST suite (`m2-single-memory/build-2`). Permission, initialization
and ordered-fault profiles remain part of the cross-cutting work below.

LNSym `d1b4b01d8879` adds CNT 8B/16B and all five UADDLV arrangements through
its SIMD dispatcher. The combined 131-job build passed 512 exhaustive byte cases,
126 varied encoded vectors, nine illegal encodings and a retained REV64 check
(`m2-vector-reductions/build-2`). These check upper clearing, V31, aliases and the
GPR/SFP/flag frame within LNSym's enabled-SIMD domain. Exception-level trap profiles
remain separate work. ARM source statuses are 60 present, four missing, eight
partial and two linking-layer labels; these are not migrated theorem counts.

LNSym `9bd0c0f609fb` adds W/X extended-register ADD/ADDS/SUB/SUBS with all eight
extension options, shifts 0..4, SP/ZR distinctions and CMP/CMN footprints. The
combined 133-job build passed 160 retained encoded vectors and 12 invalid shifts
(`m2-extended-arithmetic/build-2`). An expanded 832-case matrix also passed and is
retained in raw; the committed suite uses representative cases to limit fixture
size. ARM source statuses are now 66 present, four missing, two partial and two
linking-layer labels. Exclusives, LSE and the pair/fault profiles remain open.

LNSym `1a5034a5a4d5` adds LSE LDADD/LDCLR/LDSET in B/H/W/X forms and all A/R
variants, including store-only aliases. Each successful RMW records its captured
address, old/new values and effective acquire/release attributes; acquire is
suppressed for Rt=ZR. The combined 143-job build passed 240 encoded vectors,
six refusal paths, encoding/footprint checks and existing memory proofs
(`m2-lse/build-8`). It assumes enabled FEAT_LSE, flat little-endian memory and
natural alignment; permission, initialization, translation and LSE2 profiles
remain open. ARM source statuses are 69 present, one missing, two partial and
two linking-layer labels, with exclusives and pair/fault work still pending.

The same acceptance also passed 108 LNSym symbolic-test jobs in its own package
context, avoiding the two forks' overlapping `Tests` library names. Fork
`dd1cfdb` fixes the initial field-reflexivity proof's type and simplifies
conditional PC updates with the existing validity/alignment premises. A direct
kernel check and a fully proved final-state store regression cover the fixes.
Imported upstream AES-GCM modules still contain existing `sorry` declarations;
this validation is not a claim of migrated M5 refinements or an admission-free
upstream proof corpus.

LNSym `88fcbc0754ee` adds LDXR/LDAXR/STXR/STLXR B/H/W/X and CLREX, with an
explicit physical reservation range and per-attempt virtual/local/global/commit
outcomes. Missing platform inputs are refused. The implementation preserves
monitor-failure versus abort priority, status/ZR/SP identities and acquire/release
observations; failed stores emit no memory write. The 146-job combined build
passed 96 load vectors, 144 store vectors, 22 refusals, 32 CLREX cases and a real
reserve/commit/clear/retry sequence; standalone symbolic checks passed 110 jobs
(`m2-exclusive/build-2`). Pinned Sail ASL2023-03 sources were inspected, without
claiming a new differential run. The flat-memory/natural-alignment profile still
lacks permission/translation/LSE2 fault handling. ARM source statuses are now
70 present, zero missing, two partial and two linking-layer labels; this does
not complete M2's remaining pair/fault and retained-environment work.

LNSym `faa8ac3504f5` fixes the shared pair executor so SP-alignment faults do
not advance PC. The 147-job combined build and 110-job symbolic check passed
75 encoded pair loads, 68 stores and 75 refusal paths across W/X/S/D/Q, LDPSW,
signed-offset/pre/post addressing, ZR/SP, V31, aliases, sign/upper bits, writeback
and both access-history frames (`m2-pair/build-2`). That checkpoint left
LDP/STP partial for permission, initialization, LSE2 granularity and ordered
partial-fault behavior; the checked-memory extension below addresses that gap.

LNSym `581d57515080` adds `stepi_checked`, using the same instruction bodies as
the existing total-memory API. An explicit optional `MemoryProfile` supplies byte
permissions, initialization and SP/pair access attributes. Missing profiles are
refused. Successful writes initialize only written bytes; reads retain actual
values even when their initialization observation is false. Typed memory events
and faults preserve ordered prefixes. A second pair-store fault retains the
first write without committing register/writeback/PC changes; pair-load faults
commit neither destination. Effective single accesses apply to scalar unsigned
pairs; SIMD pairs and LDPSW retain two accesses, as in pinned Sail ASL2023-03.

The 149-job combined build and 111-job standalone symbolic check passed 180
single-transfer and 462 pair-profile cases, plus SP-policy, missing-profile,
unsupported-class and legacy-API checks (`m2-checked-memory/build-3`). Generic
monad normalization rules preserve existing symbolic proofs without adding
admissions or changing their premises. The original total API still has its
original memory domain; M3 must use the checked interface for retained fault
observations. At this checkpoint, checked atomic/exclusive and multiple-structure
SIMD paths were refused; the atomic extension below addresses that class.
Flat little-endian platform binding, x86 memory/canonicality and retained control/system forms remain work. The source
table now has 72 present and two linking-layer ARM labels; M2 remains open.

LNSym `176be60339e6` extends the same checked step with B/H/W/X LSE ADD/CLR/SET
and store aliases. Both read and write byte permissions are checked before
committing an indivisible RMW. One typed atomic event captures old/new values,
ordering and old initialization; only committed bytes become initialized.
SP and effective LSE2 alignment faults preserve data registers, memory and PC.
LSE2 relaxation requires the range to fit one aligned 16-byte quantity and an
explicit platform attribute; pair access shape alone does not enable it.

The 149-job combined build and 111-job standalone symbolic check passed all
prior suites, 1,920 permission/initialization profiles over the existing 240
assembled goldens, and 64 alignment/SP/permission combinations
(`m2-checked-atomic/build-3`). Two earlier build failures (field notation and a
test parser error) remain archived. No new admissions or legacy theorem premise
changes were introduced. These finite checks do not establish MMU, external-abort
or concurrent-memory conformance and are not M5 refinement counts. That
checkpoint still refused checked exclusives and multiple-structure SIMD.

LNSym `909f455bd66d` adds checked B/H/W/X exclusive transfers and CLREX through
the same opcode bodies. Byte permissions, initialization, SP policy and effective
LSE2 alignment use the existing checked access layer. In the pinned Sail ordering,
VA failure precedes translation; once VA passes, write-permission denial precedes
local monitor clearing even if the local/global/commit outcome would fail.
Successful loads record reservation before their read, stores record an attempt
before a committed write, and CLREX records a clear without requiring memory
or exclusive inputs. All actions share the ordered memory-effect trace.

The 149-job combined build and 111-job standalone symbolic check passed 672
load and 1,008 store profile cases over the unchanged 96/144 assembled goldens,
320 alignment/SP/permission/VA/abort-priority combinations, 64 CLREX binding
combinations and a four-step reserve/commit/clear/failure sequence with exact
events and initialization (`m2-checked-exclusive/build-3`). Earlier list-type
and record-layout failures remain archived. Default total-domain behavior and
legacy theorem premises are unchanged; no admissions were added.

The old `Reference/AArch64.lean` currently emits read-before-reserve and models
store permission faults after clearing/recording an attempt, with different
monitor-failure permission gating. This differs from the checked fork's source
ordering. The native binding and retained fault observations need explicit
reconciliation in M2/M3; these finite checks do not migrate those theorems.
MMU/physical external aborts/concurrency remain outside this flat profile.
At this checkpoint, the retained ARM controls and x86 fault/canonicality bindings
were still open. M2 is not complete; M3-M6 have not started.

LNSym `dc8bd3f3ec9d` adds retained TBZ/TBNZ and plain BR/BLR, and fixes register31
in register branches to read XZR. BLR captures its target before writing X30,
including BLR X30. BL/BLR now report X30 in their register footprint. TBZ/TBNZ
have both CFG edges with the actual branch predicate; unresolved BR/BLR targets
are explicitly refused by static CFG analysis rather than classified as RET.
The plain branch projection excludes PAC, GCS and BTI state.

The 151-job combined build and 112-job symbolic check passed 768 bit/PC-wrap
cases covering all 64 tested bits, 40 signed-boundary/ZR cases, 54 indirect
branch/alias/frame cases, six unsupported neighbors and two footprint checks,
plus the original BranchTest regressions (`m2-control-branches/build-3`).
GNU as assembled all 161 positive fixture words independently. Earlier test
elaboration failures remain archived; no instruction assertions or old theorem
premises were weakened, and no admissions were added.

Scope inspection also confirms that LD1/ST1 multiple-structure instructions are
absent from both the 74-operation roster and the old AArch64 reference. Their
checked refusal is retained; expanding that class is not required for this
migration. That checkpoint left MRS thread-pointer inputs, x86 fault and
canonicality bindings, and old exclusive fault observations to reconcile.

LNSym `da428593b21d` adds decoded TPIDR_EL1/TPIDR_EL2 MRS with explicit per-step
`ThreadPointerInputs`. Missing bindings are refused; a bound denial returns typed
`SystemRegisterDenied` with the register encoding, preserving Xt/PC and all effect
histories. Permitted reads write Xt and advance PC; Xt=31 still checks access and
discards the value. Canonical state equality includes the new input component.
The 153-job combined build and 113-job symbolic check passed 288 profiles across
six GNU-as words, two PCs, four values and six independent input bindings, plus
three unsupported MRS forms, a changing-input sequence and NOP frame
(`m2-thread-pointer/build-2`). The initial existing memory proof SAT timeout is
retained; identical-source retry passed without proof or timeout-setting changes.

These are resolved access outcomes for the current EL/trap/virtualization
configuration. In pinned Sail, an EL1 TPIDR_EL2 read may redirect to NVMem under
NV2/NV, trap or be undefined; permitted outcomes are not universally physical
register constants. Full privilege decisions and exception-vector entry remain
outside this projection. M3 must prove binding admissibility and map the typed
denial to the retained fault observation. M2 remains open for x86 fault/canonical
support and native exclusive-observation reconciliation; M3-M6 are untouched.

x86lean `4777fb8e1b84` adds explicit `LinearAddressWidth.la48/la57` to the existing
`canonical`, `Cpu.setRipChecked`, `step` and `run` functions. Default 48-bit
behavior and all prior characterization statements/proofs remain unchanged.
The selected width reaches existing JMP/CALL/Jcc/JCXZ/LOOP/RET target checks and
the bit-string byte-address check. Two generic kernel proofs relate the test to
selected-width sign extension and show that 48-bit canonicality implies 57-bit.
Their inspected axiom dependencies stay within the upstream allowlist
(`propext`, `Classical.choice`, `Quot.sound`); no native-reduction axiom, admission
or proof-policy exception was added.

The 154-job combined build and 113-job independent LNSym symbolic check passed
632 kernel-`decide` checks: literal boundary classifications, actual step target
selection, rejected CALL/RET stack preservation, conditional branches, LOOP,
signed bit-byte addressing, run forwarding and stopped-state stability
(`m2-x86-canonical/build-4`). Earlier lemma-name, conditional-proof and test-layout
failures remain archived, with no assertion removed. These are post-decode AST
checks, not encoded-form/hardware/ACL2 differential results or M5 refinements.
That step uses the external model's refusal convention on noncanonical inputs.
Existing fallthrough and LOOP model-stop behavior is retained. The optional
checked scalar entry below adds flat-memory faults; control transfers remain
unported to that entry. LAM/tag masking and page translation are outside this input.

x86lean `9e6f4fe02488` adds [stepChecked/runChecked](external/x86lean/X86/CheckedMemory.lean)
over the existing numeric step. An explicit byte-permission/initialization profile
surrounds the unchanged Cpu. Effective addresses use the existing Ea.addr;
selected-width canonicality checks every byte before permissions. Successful
reads expose actual bytes and ghost initialization, successful stores initialize
their exact wrapping range, and a denied store retains the read prefix without
committing CPU state. MOV, ordinary binary/unary arithmetic, extending loads,
CMOV and SETcc are supported; LEA/NOP need no memory access. False-condition
CMOV still reads its memory source. UD2/illegal LOCK have typed invalid-opcode
outcomes. Missing profiles and unported instruction classes explicitly refuse;
there is no total-memory fallback. These are flat access outcomes, without MMU,
CR2/error codes, concurrency or exception-vector entry.

The final 156-job combined build and 113-job standalone LNSym check passed
793 kernel-decide cases (712 operand/permission/init, 56 canonical spans,
16 malformed operands, nine capability/terminal/sequence checks), including
literal values, flags/oracle/frame preservation, base/destination aliasing,
RIP-relative/FS/GS addresses and ordered fault prefixes. The stopped-state
theorem uses simp and only the existing allowed axioms. Numeric Semantics,
State, Memory and all existing Theorems files are byte-identical to the entry
pin. Raw `m2-x86-checked-access/build-3` retains the accepted result and earlier
parser failure/successful revision; no assertion removed or admission added.
These are post-decode finite checks, not hardware/ACL2 differential results or
M5 refinements. At that checkpoint, checked stack/control, shifts/rotates,
strings, vectors and atomic classes remained open, alongside ARM native exclusive
binding.

x86lean `ebf6519ea76d` extends that checked entry to shifts/rotations/double shifts,
flagless shifts/rotations, MOVBE, bit counts/scans, BZHI, ANDN, IMUL and
MUL/DIV/MULX; BSWAP needs no memory access. Zero-count memory shifts/rotations
retain read-modify-write permissions and exact initialization. The original
shared division helpers classify typed divide errors after successful source
access: read faults take priority, and divide errors retain the read prefix
without CPU commit. The existing undefined double-shift memory-result refusal
retains its read and does not validate or invent a store.

Another 1,828 kernel-decide cases passed, for 2,621 total in the focused suite:
896 shift/rotate, 192 double-shift, 480 scalar-source, 56 address/destination
alias, 12 register-only, eight undefined-result refusal, 32 invalid operand,
144 division and eight multiplication cases. Signed/unsigned division covers
all four widths, AX byte pairing, zero divisors, overflow, permission priority
and missing profiles. The 156-job combined and 113-job standalone symbolic
builds passed (`m2-x86-scalar/build-3`). Earlier parser/default proof-resource
failures remain archived; identical cases were partitioned without removing
assertions or changing resource-limit settings. Numerical Semantics, State,
Memory, Value, Flags and Theorems files are byte-identical to the entry pin;
actual checked-step/stopped-theorem axiom lists match the existing allowlist.
These remain finite post-decode checks, not M5 refinements. At that checkpoint,
checked stack/control, bit tests, strings, vectors and atomics remained open.
The byte/word access granularity of native bit-test observations also needs an
explicit relation; a constructor match alone does not prove it.

x86lean `be348540d72d` adds checked PUSH/POP (16/64 bits) and near
JMP/Jcc/JCXZ/LOOP/CALL/RET. It extracts shared target/count functions from the
numeric step and reuses Cpu.popValue for POP's post-increment destination
frame. Source reads precede target checks, which precede CALL's stack store;
RET faults keep the read without popping. Typed faults retain the incoming
CPU, including LOOP's counter, while the default step keeps its original
model-refusal behavior. These are the existing CET-disabled near forms,
without instruction fetch, far transfers, shadow stacks or exception entry.

The combined 156-job and standalone 113-job builds passed 4,307 focused
kernel-decide cases (`m2-x86-stack-control/build-3`), including 1,686 new stack,
control, 48/57-bit boundary, counter-width, permission/init, invalid-operand
and call/return sequence cases. Goldens include RSP source/destination/address
and return-slot aliases, 16-bit SP carry/high bits, target-versus-access fault
priority, exact read/write prefixes and unchanged state on fault. Cpu, memory,
Value/Flags, all old theorem files and all prior tests remain unchanged; default
control bodies are factored through shared helpers. Actual helper/checked-step
axioms stay within the existing allowlist. Earlier fixture layout/type errors
and runtime diagnostics are retained; diagnostics are not proof acceptance.

M2 still needs the missing external checked bit/string/vector/atomic execution
capabilities. Native exclusive ordering and byte/word observation relations
belong to M3/M5 binding/refinement work; they are not extra M2 acceptance gates.
All retained domains still require those relations during migration. This
clarifies the phase boundary following the coordinator's 12:30 rule audit.

x86lean `46a30ddcd946` adds checked bit tests/modifications, legacy XMM moves
(full128, half64 and scalar32/64) and MOVS/REP MOVS. Private byte-count spans
cover all128 bits without changing the numeric step. Bit register indices use
the existing selected-byte address helper; immediate indices use the operand
unit. Aligned XMM forms have typed16-byte misalignment faults. Every transferred
byte participates in permissions, initialization and events; legacy YMM high
bits are preserved. MOVS uses the original single iteration, retaining completed
iterations on a later fault and observing prior overlapping writes/init. The
original extra count-zero step completes REP MOVS. Other string/SIMD families
outside the retained roster are not an M2 completion requirement.

The 156-job combined and 113-job standalone builds passed 6,243 focused
kernel-decide checks, including 1,936 new bit/vector/MOVS cases
(`m2-x86-transfers/build-3`). Literal goldens cover negative bit indices,
width-specific stores/CF, 16-byte canonical/permission boundaries, preserved
vector halves, zeroed scalar upper bits, aligned fault priority, both copy
directions, overlap and partial-copy prefixes. Earlier test syntax/enum/binder
errors are retained. Numeric Semantics, State, Memory, Value, Flags, Theorems
and all prior tests are unchanged; checked-step axiom dependencies remain the
existing three standard axioms. These are finite post-decode checks, not M5
refinements or a new hardware differential run.

At that checkpoint M2 still needed retained atomic/XCHG support, including a
reproduced register-first XCHG memory-base alias bug in its default step.

x86lean `fdabbf55107e` fixes that address capture before either write. Two generic
kernel simp theorems characterize the corrected whole-state result and prove
operand-order equivalence for arbitrary widths, addresses, registers and high8
views. All older theorem statements/proofs are retained. Checked memory XCHG
(implicit/explicit LOCK) and legal LOCK binary/unary/bit RMWs now report one
old/new/init event on success; denied stores retain the read prefix without
CPU commit. Incoming public events and exact initialized ranges are preserved.
Register-only XCHG needs no profile. Atomicity remains recorded under the fork's
existing TRUSTBASE, without a new concurrent memory-ordering proof.

The combined 156-job and standalone 113-job builds passed 7,473 focused
kernel-decide cases, including 1,230 new atomic cases (`m2-x86-atomic/build-3`).
Independent goldens cover all four sizes, AH, both operand orders, implicit and
explicit LOCK, base/index/RIP/FS/high-negative/unaligned addresses, old wrong-
address guards, permissions/init/48-57-bit spans, malformed operands and
multi-step atomic/fault prefixes. Earlier source/test fixture/layout failures
remain retained. All prior tests are unchanged, the two new generic laws and
checked-step dependencies use only the standard allowed axioms, and the old
counterexample now leaves the wrong address untouched. These are not M5 counts
or a new hardware/ACL2 differential run.

The source audit matches all 74 ARM names/codes and 75 x86 names, verifies all
linked implementation paths and checked paths for all 34 mapped x86 constructors.
x86lean `f41a556bd92b` closes the retained 16-bit SHLD/SHRD undefined-memory
result gap. Its original double-shift result calculation is shared by the
numeric step and checked execution: six oracle flag bits followed by sixteen
result bits, with read/write validation and exact fault-prefix preservation.
The default differential step and serialization retain their existing refusal;
checked execution can represent every result in that old C helper input domain
without narrowing counts or inventing deterministic ISA results.

The final 156-job combined and 113-job standalone builds passed 8,103 focused
kernel-decide cases, including 630 new count/mask, CL/immediate, independent
flag/result-bit, permission/init/address and fault-boundary checks
(`m2-x86-undefined-memory/build-5`). Three test-fixture syntax/type failures are
retained alongside the successful production-only and final builds. State,
memory, arithmetic/flag libraries and all old theorem files are unchanged;
the old double-shift arithmetic body is unchanged beyond extraction. The helper
uses only propext/Quot.sound; checked execution retains the existing allowed
three axioms. No new admission or proof-resource setting was introduced.

M2 source coverage and fork extensions are complete. Bit-byte/native-word,
vector/native-split and exclusive observation relations remain M3/M5 work;
M3 next replaces the local reference interpreters with thin provenance layers.
These source/finite-check results are not the 2,065 migrated refinements or
O1/O2/O4 counts. M4-M6 and final legacy-package acceptance remain pending.

### AArch64: 74 simulator operations

| Code | Operation | Source status | LNSym source (Arm/Insts unless Arm/) | Constraint / work |
|---|---|---|---|---|
| 0x00 | `NOP` | present | [BR/Hints.lean](external/LNSym/Arm/Insts/BR/Hints.lean) | NOP encoding |
| 0x01 | `MOV_IMM` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x02 | `MOV_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | ORR alias for GPR/ZR; ADD immediate0 alias for SP, keep register identities |
| 0x03 | `ADD_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x04 | `SUB_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x05 | `MOVK` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x06 | `ALU_IMM` | present | [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Requires architectural bitmask encoding |
| 0x07 | `ALU_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x08 | `SHIFT_IMM` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean); [DPI/Extract.lean](external/LNSym/Arm/Insts/DPI/Extract.lean) | LSL/LSR/ASR bitfield aliases and EXTR-based ROR |
| 0x09 | `SHIFT_REG` | present | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | LSLV/LSRV/ASRV/RORV |
| 0x0a | `MADD` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0b | `MSUB` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | W/X forms; accumulator captured before destination write |
| 0x0c | `MUL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0d | `UMULL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | UMADDL alias with Ra=XZR |
| 0x0e | `UDIV` | present | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | W/X forms; divisor zero returns zero, flags unchanged |
| 0x0f | `MVN` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x10 | `NEG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x11 | `EXTR` | present | [DPI/Extract.lean](external/LNSym/Arm/Insts/DPI/Extract.lean) | Decoded W/X extraction, including ROR alias and shift-bound checks |
| 0x12 | `BITFIELD` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x13 | `REV` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x14 | `REV16` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x15 | `SXTH` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x16 | `CMP_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x17 | `CMP_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x18 | `TST_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x19 | `TST_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x1a | `CCMP_IMM` | present | [DPR/Conditional_compare.lean](external/LNSym/Arm/Insts/DPR/Conditional_compare.lean) | Unsigned imm5 operand; arithmetic or literal fallback NZCV, empty GPR footprint |
| 0x1b | `CCMP_REG` | present | [DPR/Conditional_compare.lean](external/LNSym/Arm/Insts/DPR/Conditional_compare.lean) | GPR/ZR operand; arithmetic or literal fallback NZCV, empty GPR footprint |
| 0x1c | `CSEL` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSEL plus CSINC/CSINV/CSNEG, legal S=0/op2[1]=0 |
| 0x1d | `CINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1e | `CSET` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1f | `LOAD` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Unsigned GPR sizes B/H/W/X; unsigned/unscaled/pre/post/register offsets |
| 0x20 | `STORE` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | GPR sizes B/H/W/X; unsigned/unscaled/pre/post/register offsets |
| 0x21 | `LDP` | present | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean); [Arm/Memory/Access.lean](external/LNSym/Arm/Memory/Access.lean) | Checked permission/init/prefix faults; scalar unsigned single-access profile, SIMD/LDPSW ordered accesses; platform binding remains |
| 0x22 | `STP` | present | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean); [Arm/Memory/Access.lean](external/LNSym/Arm/Memory/Access.lean) | Checked permission/init/prefix faults; scalar unsigned single-access profile, SIMD/LDPSW ordered accesses; platform binding remains |
| 0x23 | `FMOV` | present | [DPSFP/Conversion_between_FP_and_Int.lean](external/LNSym/Arm/Insts/DPSFP/Conversion_between_FP_and_Int.lean) | Both GPR directions use ZR for field31; four encoded W/X ZR regressions pass |
| 0x24 | `CNT` | present | [DPSFP/Advanced_simd_two_reg_misc.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_two_reg_misc.lean) | CNT 8B/16B; five UADDLV arrangements; upper clearing, alias and V31 checks |
| 0x25 | `UADDLV` | present | [DPSFP/Advanced_simd_across_lanes.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_across_lanes.lean) | CNT 8B/16B; five UADDLV arrangements; upper clearing, alias and V31 checks |
| 0x26 | `ADRP_GOT` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x27 | `ADRP_RODATA` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x28 | `LOAD_D0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | D load via all five address modes; upper vector bits cleared |
| 0x29 | `STORE_D0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | D store via all five address modes |
| 0x2a | `LOAD_Q0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Q load via all five address modes, including extended/scaled register offsets |
| 0x2b | `STORE_Q0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Q store via all five address modes, including extended/scaled register offsets |
| 0x2c | `TST_BIC_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2d | `ANDS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2e | `UMULH` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Full 128-bit product, high64 result; Ra ignored |
| 0x2f | `SXTW` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x30 | `SUBS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x31 | `ADDS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x32 | `SUBS_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x33 | `CMN_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x34 | `CINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x35 | `ORN_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x36 | `LDRSB` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed byte to W/X across all five address modes; W writes zero-extend in X |
| 0x37 | `ANDS_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x38 | `STLXR` | present | [LDST/Exclusive_single.lean](external/LNSym/Arm/Insts/LDST/Exclusive_single.lean); [BR/Clear_exclusive.lean](external/LNSym/Arm/Insts/BR/Clear_exclusive.lean) | B/H/W/X exclusive loads/stores and CLREX; checked permission/init/SP/LSE2 and ordered monitor effects; retained fault binding needs reconciliation |
| 0x39 | `LDRSW` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed word to X across all five address modes |
| 0x3a | `CMN_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x3b | `UMADDL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Unsigned32 multiplicands widened before multiplication |
| 0x3c | `SXTB` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x3d | `CSINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3e | `CSINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3f | `LDRSH` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed halfword to W/X across all five address modes; W writes zero-extend in X |
| 0x40 | `SMADDL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Signed32 multiplicands widened before multiplication |
| 0x41 | `CNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x42 | `ADDS_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x43 | `BICS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x44 | `CSETM` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x45 | `CSNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x46 | `LDADD` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0x47 | `LDSET` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0x48 | `LDCLR` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0xff | `RET` | present | [BR/Uncond_branch_reg.lean](external/LNSym/Arm/Insts/BR/Uncond_branch_reg.lean) | Plain RET/BR/BLR; XZR for Rn31, BLR captures target before LR update; unresolved indirect CFG targets refuse |

Outside the 74-operation roster, LDXR/LDAXR/STXR and CLREX now execute in the fork. B/B.cond/CBZ/CBNZ/TBZ/TBNZ, plain BR/BLR and TPIDR_EL1/EL2 MRS have paths; system access outcomes need explicit per-step bindings. These are not extra completed operation tokens.

### x86-64: 75 simulator operations

| Code | Operation | Source status | x86lean constructor | Constraint / work |
|---|---|---|---|---|
| 0x00 | `nop` | present | [nop](external/x86lean/X86/Syntax.lean) |  |
| 0x01 | `movImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x02 | `movReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x03 | `addImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x04 | `addReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x05 | `xorReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x06 | `movLoad` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x07 | `movStoreImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x08 | `movStoreReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x09 | `lea` | present | [lea](external/x86lean/X86/Syntax.lean) |  |
| 0x0a | `aluImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0b | `aluReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0c | `cmpImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0d | `cmpReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0e | `testImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0f | `testReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x10 | `jcc` | present | [jcc](external/x86lean/X86/Syntax.lean) |  |
| 0x11 | `jmp` | present | [jmp](external/x86lean/X86/Syntax.lean) |  |
| 0x12 | `push` | present | [push](external/x86lean/X86/Syntax.lean) |  |
| 0x13 | `pop` | present | [pop](external/x86lean/X86/Syntax.lean) |  |
| 0x14 | `call` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x15 | `cmov` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x16 | `setcc` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x17 | `bswap` | present | [bswap](external/x86lean/X86/Syntax.lean) |  |
| 0x18 | `popcnt` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x19 | `xchg` | present | [xchg](external/x86lean/X86/Syntax.lean) |  |
| 0x1a | `div` | present | [muldiv .div / .idiv](external/x86lean/X86/Syntax.lean) | Signed/unsigned subopcodes, all sizes |
| 0x1b | `shldImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1c | `shrdImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1d | `cmpMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1e | `testMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1f | `cmpMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x20 | `movzxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x21 | `movsxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x22 | `movsxLoad` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x23 | `aluMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x24 | `cmpRegMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x25 | `movLoadScalar` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x26 | `shiftx` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x27 | `rorx` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x28 | `movbeLoad` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x29 | `movbeStore` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x2a | `shiftxMem` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x2b | `rorxMem` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x2c | `movLoadMapPtr` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2d | `movLoadHelperId` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2e | `callHelper` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2f | `callReg` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x30 | `loadXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x31 | `storeXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x32 | `aluMemUnary` | present | [un / shift](external/x86lean/X86/Syntax.lean) |  |
| 0x33 | `aluMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x34 | `bzhi` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x35 | `bzhiMem` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x36 | `aluMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x37 | `bt` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x38 | `imulImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x39 | `mulx` | present | [mulx](external/x86lean/X86/Syntax.lean) |  |
| 0x3a | `repMovs` | present | [repstrop .rep .movs](external/x86lean/X86/Syntax.lean) | Rep semantics and fault-prefix transport remain explicit |
| 0x3b | `testMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x3c | `callMemset` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x3d | `andn` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x3e | `setccMem` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x3f | `callMemcpy` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x40 | `cmovMem` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x41 | `imulMemImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x42 | `btImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x43 | `btMemImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x44 | `andnMem` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x45 | `callMemsetReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x46 | `callMemcpyReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x47 | `popcntMem` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x48 | `ror` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0x49 | `rorMem` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0xff | `ret` | present | [ret](external/x86lean/X86/Syntax.lean) | Native stack pop; simulator return modes need relation |

Cross-cutting gaps: X86.Mem retains its finite byte association list with implicit zero background and total default reads/writes. Its optional checked step now handles explicit permissions, initialization, canonical spans and ordered flat/divide faults for the scalar subset above, including shifts and retained scalar-source families; other instruction classes refuse. The default step selects 48/57-bit canonicality for its existing target/bit-byte checks. Checked near stack/control transfers now share the original target/count logic and preserve typed fault prefixes. Checked retained bit/XMM/MOVS transfers now use byte-count spans over the same numerical step. Retained memory XCHG and legal LOCK ALU/unary/bit RMWs now record old/new/init in one event; checked undefined16-bit double-shift memory results use the shared oracle helper while the default differential entry keeps its refusal. Other unused string/SIMD families are not migration gates. Native observation/fault-delivery relations are M3/M5 work. LNSym retains its total-byte-memory API and now also has a checked step for single/pair/exclusive transfers and LSE RMWs with byte permissions, initialization and ordered fault observations. That profile must be bound explicitly; it is not a full MMU/concurrency model. LSE RMWs retain old/new/order metadata in one checked effect; exclusives bind physical-monitor inputs and ordered monitor/memory effects. Out-of-roster multiple-structure SIMD paths remain explicitly refused. Old exclusive fault/trace bindings differ and require reconciliation in M3/M5. Thread-pointer outcomes now bind explicitly; native admissibility and the remaining memory/platform bindings are open. These are not closed by listing instruction constructors; M2/M3 must preserve the existing theorem domains through external-model extensions and explicit relations. x86lean takes post-decode Instr.op/len. BZHI is absent from the differential roster, not absent from step: do not duplicate its semantics.

## Legacy foundation (migration pending)

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

x86 raw handler/dispatcher refinement covers34/75 operations. JCC/JMP now
retain the full raw GPR/tag/flags/memory frame and select PC through generated
source shapes and a native label map. Source ordering and native address
ordering can differ. Ten control laws compile with module/root0 and sorryAx0;
the existing entry image and native/source/physical/compiler interfaces retain
their domains.

ARM raw handler/dispatcher refinement covers58/74 operations: immediate moves,
multiply/divide, shift/unary, ORN, extract/reverse/extension, conditional select,
bitfields, conditional compare, logical flags, arithmetic flags, MOV_REG, resolved GOT/RODATA addresses, CNT/UADDLV vector reductions, ADD/SUB immediate aliases, shared ALU tokens and FMOV.
One hundred and ninety-four laws audit and compile with module/root0 and sorryAx0. All raw64-bit
words, byte tags, STACK4/RETURN10 materialization, register aliases/XZR and the
complete architectural image compose through one58-operation emission step theorem.
CSEL/X retains its selected raw word/tag; scalar results use width/scalar-tag
writes. CNT/UADDLV capture both input halves and retain the complete raw GPR/tag,
SP, flags, memory, exclusive and other vector-bank frame. FMOV covers all32 vector banks and four directions, full raw/tag materialization,
vector high-half clearing and scalar-tag GPR width writes. Their token laws cover
all ignored fields; the current scalar producer policy retains its own domain. The six ALU selectors cover the arithmetic and logical domains of ALU_IMM/REG:
source provenance derives from captured tags, pointer increments commute with
materialization, and SP32/STACK writes retain their relative coordinates.
Native shifts/extensions and immediate aliases share the production dispatcher. STACK ORR transports its low-bit update through an explicitly aligned entry
stack origin; preceding emission bindings retain their origin domains. CCMP updates NZCV and preserves its complete raw GPR/tag frame. ANDS/BICS scalarize their destination; TST preserves the full raw tag map. ADDS/SUBS/CMP/CMN retain SP32-source materialization, shifted/extended operands and the full compare-only frame. MOV retains full raw/tag copies and SP coordinate writes; address writes retain generated GOT7/RODATA8 tags and resolved-IMM identities. SHIFT and conditions consume the actual whole AUX, while unary uses
AUX byte1/byte2. Native widths, amount/alias domains and NV normalization stay
explicit. The ledger retains production dispatcher equalities and arbitrary
unused-field domains. Entry origin identity, C extraction/union and physical/
compiler transport remain interfaces independent of B forwarding storage. Six
additional source-emitted branch families (B/B.cond/CBZ/CBNZ/TBZ/TBNZ) compose
with these58 numeric operations through one source-emission step theorem.
Source/current/next/target label-to-native-address identities stay explicit;
NZCV/value/bit tests derive the outcome and preserve the entire data/tag frame.
Their source-operation/token rows retain a separate6/6 raw count.


## Specification and proof scope

M3 replaces the local ISA definitions in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean) with bindings over
the external steps. All canonical AArch64 and x86 numerical/control execution
uses those steps, including complete REP composition. The historical handler
claims and counts below still await M5 migration to exported Clight; they are
not accepted as new Clight refinements.

The thin [provenance layer](KProgFormal/Reference/Provenance.lean) retains the
actual C raw words and all256 byte tags. ARM STACK4/RETURN10 use distinct entry
origins; SP is a distinct stack offset. x86 RSP is an offset for every tag,
while another STACK4 word is a private-arena pointer: subtract the arena before
adding the native stack origin. Every other tag keeps its numeric bits. These
are the existing C materialization rules, not a new instruction evaluator.
`image` projects all31 ARM/16 x86 GPRs over the complete external state;
`execute` calls its checked step. `observe` projects the actual handler's
output, retaining its entire ordered effects/fault. The existing native `Step`
relation compares these complete images. Output tags must come from C; the
layer does not choose an arbitrary tag-transfer function or claim that a tag
supplies memory permission. Program/guest memory addresses, arena-to-native
memory correspondence, entry origins, labels and C ghost updates retain their
explicit M5 witnesses. Existing Arm64RawRegister and X86Dispatcher.RawControl
now use these state/image/observation definitions; their old handler scripts
still need M5 and are not counted as migrated proofs.

The 2026-11-14 provenance check passes192 component build jobs, retaining all
previous checked/native cases and adding256 tag projection vectors plus17
machine vectors (x86 four tagged MOVs and one denied read; ARM four each of
NOP,ADD,LDR fault). ARM checks all31 GPRs,SP,32 SIMD cells, unmodeled flag bits,
program/memory/profile/initialization, exclusive histories, MRS inputs and old
access prefixes. ADD consumes materialized source bits; denied LDR faults at
the materialized address. The public LNSym r/w/fetch helpers are irreducible
for symbolic simulation, so literal ARM checks use Lean's kernel evaluator
(`decide +kernel`), with no native-computation axiom, unsafe reducibility
override or raised resource limits. All eight projection/execution axiom
queries have no axioms or only propext/Classical.choice/Quot.sound. The
reference ELF stays byte-identical to the Sail run. Raw attempts, final build8
and axiom evidence stay in `/workspaces/kprog-raw/formal/m3-provenance`.
M3 is complete; M4-M6 and final whole-library `lake build`/`make check` remain
open, including all2065 old theorem migrations and the O1/O2/O4 recount.

M4 has started with CompCert's actual C frontend, after PERF's17:37:30 shared
header writer agreement (VERIFIED's09:40 handoff makes PERF its owner). The
`clightgen` build uses the existing clean fork configured with `-clightgen
x86_64-linux`; Coq8.18/OCaml4.14/Menhir build its proofs and extraction. Run
`make clight` to build that frontend incrementally and regenerate the checked-in
[Clight module](KProgFormal/Clight/X86Numeric.lean) from
[c/X86Numeric.c](c/X86Numeric.c). The C unit directly calls the production
`x86_alu_result`, retaining that actual static function and its four shift
callees; an include-only unit is removed by the frontend's unused-function
cleanup and is insufficient. The final export contains six real function
bodies, not just builtin declarations. Byte-for-byte regeneration and229 Lake
component jobs pass, including the rooted Clight AST and retained native/access
checks. All six AST axiom queries use only the three standard Lean axioms.
These are syntax/type checks, not M5 refinement theorems.

The first canonical C change is [the ALU result header](generated/x86_alu_result.h):
its existing16-arm/default switch now has a standard-C `INTO` output entry.
The original expression macro remains a facade over that one body, and
`x86_sim.h` uses the output form. No arithmetic formula, case number, helper
body or public macro signature is replaced. A matched real Cilium proof39
compilation preserves every allocated code/data byte and202 allocated
relocations. Its44 BTF types normalize identically; BTF function information
and CO-RE relocation blocks are unchanged. Full ELF bytes differ in debug,
BTF string and line metadata; full-file identity is not claimed. The existing
numeric oracle still passes6304 cases. The older routing oracle already failed
288 tag expectations before this edit and fails identically afterward (exact
stdout digest retained); it has not been relabeled passing or narrowed.
Raw C/request/object/log/source identities stay in
`/workspaces/kprog-raw/formal/m4-c-subset`.

The next M4 slice adds [c/Platform.h](c/Platform.h), preserving the complete
vendor/libbpf UAPI `__sk_buff`, `xdp_md` and `bpf_dynptr` layouts (41 named
fields). Only padding syntax changes: named64-bit union padding replaces the
anonymous64-bit bitfields, and the reserved24 bits become three bytes. Both
GCC against the real vendor UAPI and CompCert against the adapter check every
field offset/size plus complete structure size/alignment (88 layout assertions,
plus the64-bit pointer assertion). The UAPI's GPL-2.0 WITH Linux-syscall-note
and original copyright remain on this adapter; normal builds keep the original
Linux/vmlinux declarations. `make clight` runs this actual ABI check through
both frontends. The two full header translation units now parse successfully;
that is not an export/acceptance of their unexpanded handler macros.

The unsupported `__builtin_trap` sites use `KPROG_C_TRAP`: native/BPF builds
retain the exact builtin, while CompCert imports a named nonreturning platform
primitive. Its terminal external semantics remains a required fault-proof
interface, not a successful return/zero fallback. Existing memory-access
vectors pass40260 cases and nine native invalid-width trap probes retain
SIGILL. CompCert now selects the same free kind6 entry input as production
BPF for both ISAs' unspecified values, rather than the legacy host zero
fixture. The ABI check exports both actual input calls and rejects either
zero substitution (two negative fixtures). Final ABI export typechecking and
all229 component jobs pass. This slice also preserves all code/data bytes,
202 allocated relocs,44 BTF types/function-info/CO-RE for the matched Cilium
proof39; only debug/line metadata changes. Its final default preprocessor
stream is byte-identical to the measured after-object input. Numeric6304PASS
and the existing288 routing failures remain unchanged. Full raw evidence is
in `/workspaces/kprog-raw/formal/m4-bpf-abi`.

The next M4 slice replaces the eleven GNU empty aggregate initializers in
both shared simulator headers with standard C zero initialization. Both actual
raw entrypoints now export through CompCert; the expanded dispatchers proceed
to the next GNU statement-expression failure. The initial entry exports exceeded
Lean's default recursion depth in the exporter's nested sequence syntax;
complete-handler acceptance remains open. Clean fork `fee9302` now splits long
statement syntax into named `Stmt` definitions, without changing the statement
tree or raising Lean limits. Both entries typecheck on4.35 with36/65 parts;
unfolding the parts reproduces the earlier exported syntax exactly. The upstream
demo and256-statement regression pass on4.32.1; all229 root component jobs
pass on4.35. The matched
Cilium compiler input differs only in initializer syntax; all allocated bytes
and202 relocations remain equal. `make clight` passes. Evidence and the two
entry typecheck failures remain in `/workspaces/kprog-raw/formal/m4-standard-c`.

[c/Arm64Numeric.c](c/Arm64Numeric.c) now roots thirteen actual numeric bodies:
ALU result, modifier, shift, bitfield, multiply/divide, extraction/reversal,
unary, conditional select/negate, FMOV value/destination, immediate operand
and ADRP tag selection. Each canonical header has a standard C output form;
the existing expression facade uses that same body. Arithmetic, casts, operand
evaluation and unsupported branches are unchanged. `make clight` exports the
[thirteen Clight functions](KProgFormal/Clight/Arm64Numeric.lean); deterministic
regeneration,230 component jobs and all1,038,547 existing UBSan oracle cases
pass. Their native extraction objects retain all allocated bytes and203
relocations; this is numeric-root parity, not whole-application ARM parity.
All thirteen AST axiom queries retain only the standard three axioms.
Raw evidence is in `/workspaces/kprog-raw/formal/m4-arm64-numeric`;
`validation-2.json` corrects the initial receipt's baseline classification:
eleven oracle binaries predate the first edit, while the last two are post-edit
validation only. The complete native-object baseline predates every edit.
These exports are not stateful dispatcher exports or M5 refinements.

[c/X86Pointer.c](c/X86Pointer.c) roots the production pointer-load handler
through the existing `x86_sim_state` ABI, with arbitrary incoming stack-tag
and pointer-fact arrays. It does not reset them to a zero fixture. The pointer
tag selectors, register-tag read and stack-coordinate materialization now have
standard C output forms over the same bodies. Only the empty register-asm
identity barrier becomes a no-op for CompCert; native compilation retains the
asm. The structured stack union also gains the missing16/32-bit views already
used by the standalone stack. Its allocation/layout stays unchanged; this fixes
the existing condition test's missing-member compilation failure.

`make clight` retains the actual handler and its `x86_width_effective` callee.
Their export regenerates identically, typechecks and uses only the standard
three axioms;231 component jobs pass. Existing production checks pass2,097,152
pointer-load frames,71,657 stack cases,1,024 condition/flag rows,5,305,340
arithmetic cases and72,866 register-routing cases. The old288 ALU routing
failures remain byte-for-byte identical in their output. The final native
handler preserves allocated bytes; the matched real Cilium proof39 preserves
all code/data and202 relocations. These are not whole-app acceptance or M5
refinements. Raw evidence is in `/workspaces/kprog-raw/formal/m4-x86-pointer`.

The same archived OTel main is also preprocessed with current headers and
PERF's243 constant-helper substitutions (all other source text identical).
Original generated C is731,104 bytes; the selected form is726,973 bytes.
PERF's historical expansions were1,011,998,390 bytes before selection and
370,116,027 afterward; that M4 step expands to376,481,164 bytes. The additional
output facades increase the latter size; no compile-time gain or new whole-main
byte parity is inferred. All three preprocessed pieces and the joined input
are retained in the same raw directory. Full dispatcher C-subset conversion
and the memory/ABI bindings remain open.

The x86 register read, write, MOV-immediate, MOV-register and MOVX bodies
now also export from `c/X86Pointer.c`, retaining arbitrary register numbers,
widths, lanes, provenance and incoming stack facts. Register reads and stack
alias conversion use standard C output forms; the move handlers consume those
forms. MOVX's nonvolatile empty-asm identity retains that qualifier in native
builds and uses the CompCert identity adapter. The module contains six public
roots and four actual callees; all ten typecheck and regenerate identically.
The existing move/register/stack/flag oracles pass, and the old288 ALU-route
failures retain their exact output. `make clight` and231 component jobs pass.
The matched default Cilium code/data and202 relocations remain unchanged.
The generic host MOV-register extraction object shrinks from8464 to5898 bytes;
host-object byte parity is not claimed. This is separate from the default BPF
comparison and is not a runtime gain. Raw evidence is in
`/workspaces/kprog-raw/formal/m4-register-moves`; rebuildable preprocessing/IR
is under `/var/tmp/kprog-tmp/formal/m4-register-moves`, with commands retained.
The same full OTel source preprocessed to375,915,574 bytes after this
register conversion (the same243 literal helper substitutions). After the
profile bindings below, it expands to375,916,486 bytes:912 additional declaration
bytes. The three archived pieces are unchanged; joining retains the first
prefix once and all post-marker bodies, with exact reconstruction of the prior
joined file checked. The current pieces stay in scratch; join offsets, commands
and sizes stay in `m4-profile-bindings/otel-expansion.json` under the raw root.
No compile-time or runtime gain is inferred from these size measurements.

[c/Arm64Address.c](c/Arm64Address.c) exports eight production coordinate,
register-read/write and ADRP bodies with incoming cache payloads/validity,
register tags and private bytes/facts supplied by the caller. Standard C output
forms retain lazy SP/return input requests, cache updates and64-bit wrapping.
The tag expression also retains its original unsigned-int promotion type; the
new type regression check caught a byte-valued facade before it was corrected.
All eight Clight functions regenerate identically and typecheck; `make clight`
and232 component jobs pass. The59,904-case cache/SP-frame oracle passes against
both pre-edit and post-edit x86 and AArch64 native objects (AArch64 via user-mode
QEMU), checking cold/hot inputs, request order, arbitrary tag bytes, high register
identifiers, wrapping and released-byte/ghost intervals. Existing ADRP, memory,
scalar/vector-token, helper-pointer, arena and operand-routing checks pass.

The existing return-token oracle still fails at `src=0 tag=10 value=0 table=0
profile=2`: both the pre-edit and current header return while that oracle expects
callee-frame rejection. Only its diagnostic was extended; its assertions and
inputs remain unchanged. This discrepancy remains for the full migration.
Generic native objects have small layout differences, so their byte parity is
not claimed. A focused BPF fixture at the production ARM O2/v4 flags preserves
all allocated code/data and386 relocations. This is a fixture comparison, not
whole-application ARM acceptance. The first historical-header comparison had
incorrect preamble ordering and is superseded; the corrected streamed current
input also matches the normal fixture build. Raw receipts are under
`/workspaces/kprog-raw/formal/m4-arm64-address` (`header-fidelity-final/`);
large rebuildable inputs stay in scratch.

[tools/compare_c_header.py](tools/compare_c_header.py) reproduces that comparison
without a second checkout or header copy. It substitutes the historical header
at the actual include location and checks the current stream against an ordinary
current build, retaining compiler logs, commands and the current header patch.
For example, from this directory:

```sh
python3 tools/compare_c_header.py --before ef13f6356 \
  --header ../arm64/arm64_sim_local_bpf.h \
  --source oracles/arm64_address_compile.bpf.c \
  --output /workspaces/kprog-raw/formal/NEW-COMPARISON \
  -- \
  ../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf \
  -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 \
  -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
  -I/usr/include/x86_64-linux-gnu
```

The x86 [storage binding](c/X86Pointer.h) now passes arena capacity and byte/word
views explicitly. Its fact descriptors address either array cells or separately
scalarized cells; scalar registers reuse the canonical field declarations without
an embedded fixed-size arena. Legacy state size, alignment and every named offset
remain unchanged for capacities64/200/376. `make clight` links one generic root
object against canonical array profiles1/7/9/64/200/376 and scalar profiles64/200/376,
including the real Cilium25-cell and OTel47-cell layouts. Each checks102,816
executions with identical arena addresses/free-input streams, comparing all
registers, private bytes, facts and frames. Fixed64-capacity and wrong-cell
mutants fail. The matched Cilium object still has identical allocated bytes and
202 relocations. Raw evidence: `/workspaces/kprog-raw/formal/m4-profile-bindings`.

The descriptor contract requires matching byte/word views of the same arena,
complete fact cells for the producer capacity, and separate live storage for
registers, descriptors and facts. M5 must prove this field/cell relation, including
scalar-list versus loop transport; these finite tests do not prove refinement.
The ARM [address binding](c/Arm64Address.h) also takes capacity and signed bias
for its three writing roots. One generic object matches the canonical bodies at
(capacity,bias) profiles(1,0), (7,-3), (9,4), (160,96), (200,160) and (376,280):
245,760 executions each, with all256 tags, full-width register selectors, cache
validities0/1/2/255, released bytes, packed-tag padding, and input identities/order
observed. These are storage fixtures, not measurements of ARM applications.
Fixed160-capacity, fixed96-bias and zero-unspecified-input mutants fail. The
59,904-case independent cache/SP oracle now supplies and checks the production
kind6 stream rather than the old host-only zero choice; its cache request order
and frame assertions remain. `make clight`, deterministic regeneration and130
component Lake jobs pass with standard axioms only. The focused production ARM
fixture retains identical allocated bytes and386 relocations; whole-app ARM
parity and M5's universal representation proofs remain open.

[c/Arm64Stack.c](c/Arm64Stack.c) now exports six actual private-stack roots:
owned/released reads, tag reads, owned/released writes and pointer formation.
Packed-tag reads, byte extraction and the nested payload unmaterialization use
standard-C output forms, with the original expression facades sharing those
bodies. Native index-opacity asm is unchanged; CompCert uses its value-preserving
identity. Capacity, signed bias, coordinate caches, byte/word views, tags and
payload cells are caller inputs. Aligned words retain the word path, unaligned
accesses retain byte lanes, and released bytes retain individual kind6 inputs.

The independent [stack oracle](oracles/test_arm64_stack_binding_host.c) passes
3,440,640 checks on both pre-edit and converted native root objects. Eight arena
profiles include positive/negative biases above32 bits, all256 width codes and
tags, aligned/unaligned and mapped escaped windows, and cold/nonboolean cache
states. It compares bytes, packed-tag padding, payloads, caches and input order;
mutations dropping payload writes, misplacing packed tags or zeroing kind6 fail.
The converted roots also pass all3,440,640 checks as UBSan AArch64 objects under
`qemu-aarch64-static` user-mode execution; no VM/image/base is involved.
Existing memory/scalar/vector-token, stack arena/tag-route and byte-lane oracles
also pass. Six actual Clight functions regenerate identically and typecheck;
`make clight` and131 targeted component jobs pass with standard axioms only.
The focused [BPF fixture](oracles/arm64_stack_compile.bpf.c) exercises dynamic
width/alignment, payloads and release: allocated socket bytes6072 and6 relocations
are identical before/after, and the current replay equals the normal build.
`compare_c_header.py --also-header` replays the byte-lane header at its actual
nested include as well as the canonical header, avoiding a mixed old/new baseline.
Following the single-output rule, header comparisons now replace the fixture's
`build/<source-stem>.o` and `.i` in place. Before/current observations stay in
memory; raw stage logs, commands, section sizes and relocations remain. Completed
duplicate M4 products are removed with paths recorded in the cleanup log.
Raw evidence: `/workspaces/kprog-raw/formal/m4-arm64-stack`. These checks do not
establish universal storage/refinement relations, full-app ARM parity, or the
remaining nonarena/unaligned/context/fault ABI; those obligations remain open.

[c/Arm64Access.c](c/Arm64Access.c) exports the production nonarena numeric
load/store and typed pointer read. Its CompCert-only unaligned adapter uses the
existing Clean `EF_memcpy` semantics with alignment1 and sizes1/2/4/8; the pointer
path copies eight bytes into a pointer-typed local. This keeps source/destination
alignment arbitrary and retains pointer fragments. Native volatile accesses and
BPF assembly remain the same bodies; width selection and literal context offsets
are preserved. No new uninterpreted memory function is introduced.

The [access oracle](oracles/test_arm64_access_host.c) checks19,968 cases in native
and exact adapter modes, on x86 and AArch64 user-mode execution. It covers every
width byte, signed offsets beyond the BPF immediate range, aligned/unaligned
locations, full pointer bits, adjacent-byte frames, and one complete alignment-1
copy per operation. Alignment8, narrowed reads and widened stores fail the oracle.
One object/executable path is replaced between configurations. `make clight`,132
targeted component jobs and in-place deterministic regeneration pass; standard
axioms only. The new [BPF fixture](oracles/arm64_access_compile.bpf.c) has identical
allocated code/data (socket600B) before/after and current replay equals normal.
Raw evidence: `/workspaces/kprog-raw/formal/m4-single-output-2`. Binding the actual
Clight memory to native addresses, initialization, volatile observations and
ordered normal/fault outcomes remains a universal proof obligation. These access
roots do not yet export the whole context/handler/fault chain or establish M5.

[c/Arm64Addressing.c](c/Arm64Addressing.c) first exports eight production consumers:
modified register, memory offset, helper argument/context pointers, pre/post
writeback, memory tag and payload recovery. They use the canonical numerical
bodies and caller-owned register/cache/private storage, capacity/bias and live
helper coordinates. Immediate suppression, lazy index/payload branches, raw ABI
tags, invalid-register observations and nonboolean cache validity are retained.

The new [oracle](oracles/test_arm64_addressing_host.c) exposed a pre-existing host
C issue: ignored-register writeback computed an offset from null before ignoring
the destination. The address primitive now uses existing wrapping pointer bits
for host/Clight and keeps the original BPF pointer operand form. Invalid and zero
address-word tests remain; source-body conversion and adapter equivalence still
need their M5 proofs. An initial all-bits lowering changed the dynamic BPF fixture;
the failure and disassembly remain, and isolation showed the operand form caused
it. The final [dynamic fixture](oracles/arm64_addressing_compile.bpf.c) has identical
allocated socket3856B and18 relocations, including runtime writeback flags.

All245,843 coordinate/request/routing/frame/error cases pass on x86 and AArch64
user-mode execution. Pre alignment faults preserve their input prefix/frame;
relocation offsets reject; non-pointer payloads retain lazy index evaluation.
Suppression, overbroad helper substitution, dropped payload and zero6 mutations
fail. Existing modifier/offset/dispatch/helper/prepost/memory-token oracles pass.
`make clight`,133 targeted component jobs and in-place deterministic exports pass
with standard axioms only. Because the ABI selector is shared with x86, the actual
matched Cilium pipeline was replayed too: code/data and202 relocations are exact.
`compare_c_header.py --ir-pass` applies the production LLVM pass in place before
the backend; optional `--objdump` retains stage disassembly in raw diagnostics.
Raw evidence: `/workspaces/kprog-raw/formal/m4-arm64-addressing`. The complete
context-read/fault chain, pointer/native-memory relation and full default-byte
coverage remain open before M4/M5 acceptance.

Five more roots export XDP/SKB reads, SKB writes and the ordered `cb` byte
read/write ladders. Their output forms retain the native expression APIs and
BPF asm. CompCert uses two explicit platform operations: select the full pointer
by actual context, ABI kind and UAPI field offset, and expose that pointer's
bits for partial reads. The kernel's `xdp_convert_ctx_access` and
`bpf_convert_ctx_access` in `vendor/linux-framework/net/core/filter.c` explain
why copying the UAPI `__u32` fields would truncate the native value. The imports
have no arbitrary-input or zero implementation. Their memory, provenance,
permissions and ordered fault interpretation must be bound in M5; declaring
them does not establish a refinement.

The [context oracle](oracles/test_arm64_context_host.c) supplies a fixture
interpretation and passes112,368 full-pointer/partial-lane/context-identity,
displaced-base, raw-access, `cb` and whole-frame cases on x86 and AArch64 user
mode. Three mutations (pointer truncation, wrong field and wrong `cb` offset)
fail. A nested macro-variable collision found by the first BPF comparison was
fixed; both diagnostics remain. The final
[XDP/TC fixture](oracles/arm64_context_compile.bpf.c) retains exact code/data
(1152B/1896B) and four relocations, including dynamic `cb` reads and writes.
`make clight`,133 targeted jobs, deterministic exports and standard-axiom checks
pass. The other two regenerated modules change anonymous composite names only.
Raw evidence: `/workspaces/kprog-raw/formal/m4-arm64-context`. The full instruction
dispatcher and fault chain still await C-subset conversion; these context roots do not
complete M4 or migrate any of the2,065 theorems.

The next two roots in `Arm64Addressing.c` export the complete memory read/write
consumers, including stack observation, ABI typed loads, relocation-offset
rejection, raw accesses and SKB stores. The binding gains the caller's live
`q` view, which must alias `b` as in the canonical private union. CompCert uses
the general base-plus-offset access instead of the compiler's known-context
operand shortcut; native BPF keeps that shortcut. Their address, pointer and
effect correspondence remains an explicit M5 obligation, including nonreturning
rejection and the previously documented platform imports.

The [complete-consumer oracle](oracles/test_arm64_memory_binding_host.c) checks
49,152 read/write profiles against independent byte/frame/input expectations,
before and after conversion on x86, and after conversion on AArch64 user mode,
in native and CompCert-adapter modes. It covers all256 tag bytes, four widths,
SP and GPR bases, three storage profiles, cold coordinates, suppressed
immediates, released bytes and relocation rejection. Dropped extra offsets,
owned-only reads and missing relocation guards fail. The context oracle now
also drives the complete consumers with decoded index/pre-post/extra operands.
Both BPF fixtures retain exact code/data and relocations: XDP1152B/TC1896B+4,
and the expanded stack/raw/relocation fixture socket4624B+19. `make clight`,133
targeted jobs, deterministic export and standard-axiom checks pass. Raw evidence:
`/workspaces/kprog-raw/formal/m4-arm64-memory`. Instruction dispatch, fault
selection/recovery, remaining C-subset work and full default-byte coverage remain.

Four more `Arm64Addressing` roots export the fault predicate and complete scalar
LOAD, signed LOAD and STORE bodies (19 functions total). Dispatcher and direct
entries now share those three bodies. Fault selection retains lazy SP/stack/
relocation/context exclusions, full-width zero-page/pre-index arithmetic and
the actual kind6 outcome. Recovery still precedes overlap checks and writeback;
stores retain their original path. Native caller hooks, destination-width
capture, pointer tags, relative spill payloads and SP release are preserved.
The load-tag and signed-load selectors now have standard output forms with
their original expression facades.

The extended consumer oracle passes221,184 fault-domain/address/input profiles,
1,200 scalar recovery/transfer/writeback profiles,1,280 tag/payload profiles
and36 source/index input-order profiles,
alongside its49,152 memory profiles. Baseline/current x86 and current AArch64
user mode pass in native and adapter modes. Four mutations fail: discarded high
draw bits, omitted recovery, overlap checks before recovery and lost pointer
tags. A new cold-coordinate regression caught and corrected eager source capture:
the resolved store now observes its index before its source. Native after-include
hook behavior is checked separately. `make clight`,
133 targeted jobs, deterministic export and standard-axiom checks pass. The
same-source BPF fixture adds all five scalar operations and a dynamic scalar
fault address; socket5208B and23 allocated relocations remain exact, with all
five changed headers replayed together. Raw evidence:
`/workspaces/kprog-raw/formal/m4-arm64-scalar-memory`. This exports the existing
recovery selection, not a proof of the actual exception-site/native/Clight
correspondence. Pair/vector/atomic and remaining instruction dispatch still
require C-subset conversion; all2,065 refinements and recount remain M5 work.
The protected-read recovery regression passes. The separate read-follow-up
oracle retains ten memcpy discrepancies, with byte-identical diagnostics against
the preceding commit; its original assertions and inputs remain unresolved.

Two further roots export the shared LDP/STP and D/Q vector memory bodies
(21 functions total). Pair duplicate/overlap checks precede fault selection;
recovery clears both GPR destinations. Pair values are read before either GPR
commit; vector halves commit in transfer order, with D loads clearing the high
half. Each store resolves its index and observes its source before that slot's
write/free inputs, then proceeds to the next slot. Native expression operands
are retained at paired store sites to preserve LLVM stack allocation; Clight
uses statement outputs through the same read/tag/write bodies. Their memory,
source-observation and native exception correspondence remains an M5 obligation.

The existing consumer oracle adds1,984 raw pair/vector and3,024 private-memory
profiles, passing against the previous header and on current x86 and AArch64
user mode in native/adapter forms. It checks whole GPR/SIMD, byte/tag/payload,
coordinate/input-order and writeback frames. Sixteen adapter-only second-copy
failures check actual partial C effects; they do not establish native recovery.
Wrong stride, missing second recovery/payload and omitted D high clearing are
caught by mutations. `make clight`,133 targeted Lean jobs, deterministic export
and standard-axiom checks pass. The expanded same-source BPF fixture retains
socket10872B and27 relocations exactly; current replay equals normal compilation.
Raw evidence: `/workspaces/kprog-raw/formal/m4-arm64-pair-vector`.
Atomic/exclusive/control/helper and remaining full dispatcher conversion,
full default-byte coverage and the previously recorded failures remain open.

The exclusive-store root now exports the shared STLXR dispatcher/direct body
(22 functions). It retains overlap rejection, SP alignment, one explicit failure
choice at the truncated32-bit site and success-only transfer before32-bit status
writeback, including the original SP/ignored-field and release behavior.
The CompCert statement adapter retains the existing host input protocol's exact
non-Boolean error and exit1; the native private instruction/header is unchanged.
Its choice, stdio/nonreturning exit, monitor, memory and native-fault bindings
remain M5 obligations.

The existing oracle adds7,200 whole-state/input-order cases and four invalid
choice exit/message cases. Previous direct-body replay and current x86/AArch64
user mode pass in native and adapter forms. Four mutations are caught: querying
before rejection, writing after failure, omitted SP alignment and accepting an
invalid choice. `make clight`,133 targeted Lean jobs, deterministic export and
standard-axiom checks pass. The expanded BPF fixture retains socket12448B and
30 relocations exactly, with all three changed headers replayed together and
current replay equal to normal compilation. Raw evidence:
`/workspaces/kprog-raw/formal/m4-arm64-exclusive`. Remaining atomic/control/helper
and full dispatcher/default-byte coverage still keep M4 open.

Three atomic RMW roots (LDADD/LDSET/LDCLR) and the shared metadata-transfer root
bring `Arm64Addressing` to26 functions. The frontend probe treated the GCC atomic
names as unprototyped `int` externs, so the export now uses an explicit64-bit
atomic boundary with byte width, operation and ordering. Native GCC/BPF operands
and narrow kfuncs retain their original form. The primitive's indivisible
old/new effects, ordering, permissions, initialization and fault interpretation
remain M5 obligations; its declaration does not supply those semantics.

The oracle adds38,880 atomic state/input/ABI profiles and13,440 metadata
copy/partial/overlap/release profiles, passing with previous native bodies and
current x86/AArch64 user mode in native and adapter forms. Twelve adapter-only
refusals retain the source-before-call/no-commit prefix. Six mutations catch
old-value truncation, wrong ordering, lost CLR complement, missing released
value, missing atomic tag clearing and missing copied tags. `make clight`,133
targeted Lean jobs, deterministic export and26 standard-axiom checks pass.
The BPF fixture retains socket18000B and36 relocations exactly. Its comparator
now compares the resolved symbol name without its string-table offset; actual
ELF mutations reproduce the old false difference and still detect retargeting.
Current replay equals normal compilation. The ten read-follow-up discrepancies
remain identical to the previous header. Raw evidence:
`/workspaces/kprog-raw/formal/m4-arm64-atomic`.

The coordinator paused FORMAL on2026-11-15, then the operator explicitly
resumed it at14:18 UTC (see [todo section0](../docs/todo.md)). FORMAL again owns
M4–M6; PERF owns the production inline refactor and its scale measurements.
The remaining full dispatcher/default-byte coverage, all2,065 refinements,
recount, archival and whole-package checks remain open.

PERF's production interpreter now calls inline family functions with constant
instruction fields. The extraction input [c/X86Inline.c](c/X86Inline.c) roots
that actual dispatcher and its callees through references to the producer's
existing cells, flags, arena and ghost facts. Its stack/fact array capacity
remains a producer profile; an export with one capacity cannot establish all
profiles. CompCert register-read and tag adapters use the same statement-output
primitive bodies as the native expression facades, and width resolution reuses
the existing byte-parameter helper. Native facades retain their folding behavior.
The new oracle checks580,608 defined-lane/register/tag/origin/frame cases,
including absent unused references and restoration of the caller's macros.
`X86Pointer` is regenerated for the current named/indexed register-cell ABI.
At that checkpoint, full inline extraction stopped at tagged-memory GNU
expressions; `X86Inline` had no accepted Clight export or refinement. Raw probes and
validation are retained under `/workspaces/kprog-raw/formal/m4-x86-inline`.

The next slice shares statement-output tagged-load bodies with their native
expression facades and all direct consumers. Physical reads still precede tag,
alias and released-value input observations. Three actual alias/tagged-load
roots extend `X86Pointer` to14 functions, including its physical-load callee.
CompCert uses the upstream alignment-1 copy builtin into a volatile local before
returning the value: reduced C type alignment alone cannot relax Clight chunk
loads. The AST contains size1/2/4/8 copies with source alignment1. Native GCC
and BPF accesses retain their typed/asm forms. Native/global volatile events,
pointer fragments, permission/init and fault interpretation remain M5 work.

Historical and current native bodies and the CompCert host adapter pass58,320
capacity/width/full-tag/release/frame cases plus eight protected-access probes.
The adapter also checks the copy's actual source, byte count and alignment.
Four mutations catch lost width masking, eager tag reads, truncated tags and
wrong copy alignment; the three earlier binding mutations are also detected.
`make clight`,38 targeted Lean jobs, deterministic regeneration and four
standard-axiom queries pass. The expanded producer-interface fixture exercises
indexed scalar/XMM loads, memcpy and REP MOVS: socket1448B and11 allocated
relocations match the historical headers exactly, and replay equals normal
compilation. The extraction TU expands to2,870,798 bytes at its explicit profile;
this is not a whole-app scale result. At that checkpoint, full inline extraction stopped at
`READ_RECOVERY_AT` and its lazy effective-address expression. No full-I export,
M4 completion or migrated theorem is accepted. Raw evidence:
`/workspaces/kprog-raw/formal/m4-x86-tagged` and the completed inline receipts.

Recovery and effective-address kernels now also use shared statement outputs.
Five new roots bring `X86Pointer` to19 functions. CompCert-only inline adapters
capture decoded scalar fields and keep state-derived address/index reads inside
the original gates; REP MOVS uses the actual recovery output directly. Full
operand comparisons, low-address short circuit, low-bit input selection and
RSP fault-before-write behavior remain unchanged. Historical/current native
and host-adapter runs pass68,400 offset cases and36,288 recovery/frame cases,
plus32 lazy capture probes. Inline bindings also compare normal and fault paths
without initializing unused flags or ghost references. Five mutations catch
wrong input bits, a changed address boundary, a pre-fault SP write, eager index
evaluation and a shift by64. `make clight`,38 targeted Lean jobs, deterministic
875,320B regeneration and five standard-axiom queries pass. The same fixture
retains socket1448B and11 allocated relocations; replay equals normal build.
The extraction TU is2,676,777B at its explicit profile. At that checkpoint full inline export
stopped at the MOV-load width selectors; no full-I export or migrated theorem
was accepted. Small [run receipts](results/m4-x86-recovery/README.md) are committed;
large logs and exact replay recipes stay in
`/workspaces/kprog-raw/formal/m4-x86-recovery`.

The MOV-load write-width, memory-width and arm selectors now also have actual
Clight roots (`X86Pointer`:22 functions). Shared declaration/output kernels
retain raw truth-before-byte capture, the nonzero flags expression's second
evaluation, AUX-first/lazy fallback and the arm's delayed tag read. The native
expression and const initializer forms remain; CompCert uses statement outputs
for the same declaration sequence. Historical/current native and host-adapter
runs pass199,680 width/AUX cases,7,350 arm/capture cases,3,993,600 partial-state
binding/frame declarations and48 fallback capture probes. Four mutants catch
byte truth tests, eager flags/tag reads and tag truncation. `make clight`,38
Lean jobs, deterministic881,269B regeneration and three standard-axiom queries
pass. The producer-interface fixture remains socket1448B+11 allocated
relocations, replay equal to normal compilation. Extraction CPP is2,676,915B
at its explicit profile; at that checkpoint full inline export stopped at the SKB context-read
expression. [Small receipts](results/m4-x86-mov-selectors/README.md) are committed;
full logs/recipes stay under `/workspaces/kprog-raw/formal/m4-x86-mov-selectors`.
No full-I export or migrated theorem is accepted.

The next slice exports actual SKB/XDP/cb reads and the existing ABI tag
selector in [X86Context](KProgFormal/Clight/X86Context.lean):four roots and two
callees. All context-read and adjacent tag consumers use shared statement-output
bodies. Native fixed-offset/constant-predicate/asm operands are retained; the
CompCert pointer fields reuse the typed context-pointer/pointer-bits boundary,
covering full64-bit values rather than a host UAPI32 cast. The sole kernel's
context conversion source confirms pointer-sized field loads. Native host
fixtures retain their original32-bit field values; this is not kernel execution
or proof of entry/view correspondence.

Final native/adapter runs pass19,654 context/partial/scalar/cb/fallback/tag/frame
cases and six guarded byte probes; historical native reads pass19,584 cases.
Five mutations catch pointer truncation, wrong UAPI field, byte shift, eager
fallback and swapped packet/end tags. `make clight`,39 Lean jobs, deterministic
100,519B regeneration and four standard-axiom queries pass. New BPF consumers
retain XDP360B/TC760B+4 allocated relocations; the ordinary fixture remains
1448B+11. Both historical replays equal normal compilation. Extraction CPP is
2,678,818B at its explicit profile. At that checkpoint full inline export stopped
at the memory read-source selector. Logical/native context view coherence, actual entry
bindings and memory/volatile/fault interpretation remain M5 obligations, not
results of these declarations or finite fixtures. No full-I export or migrated
theorem is accepted. [Small receipts](results/m4-x86-context/README.md) are
committed; full logs/recipes stay under `/workspaces/kprog-raw/formal/m4-x86-context`.

The memory-read source selector now shares its original declaration body
between the native expression facade and standard statement output. A CompCert
inline adapter takes the binding by reference, preserving stack-first selection
and lazy tag-before-width reads. One actual scalar root brings `X86Pointer`
to23 functions. Historical/current native/adapter runs pass338,000 full-operand
and ordered-evaluation cases each; the real inline adapter passes48,384 lazy
binding/frame cases with unused references absent. Five semantic mutations are
caught. `make clight`,38 targeted Lean jobs, deterministic883,116B export and a
standard-axiom query pass. Four-header replay retains ordinary1448B/11relocs and
XDP360B/TC760B/4relocs, equal to normal compilation. The first replay recipe
omitted an intermediate header and stopped before compilation; its failed
receipt stays in raw. Profile extraction CPP is2,674,873B. Full inline export
at that checkpoint stopped at `STACK_READ`/`STACK_READ_OWNED` GNU expressions. These checks do
not establish Clight/native-memory refinements. [Small receipts](results/m4-x86-read-source/README.md)
are committed; raw commands and observations stay under
`/workspaces/kprog-raw/formal/m4-x86-read-source`.

Private-stack owned/released and ghost-fact reads now share statement bodies
with the original native expression/initializer forms. Three actual roots bring
`X86Pointer` to26 functions; the generic binding adds active16/32-bit views of
the same arena alongside b/q. CompCert inline adapters retain physical read
before SP/release/input, byte width capture, aligned/byte routes and lazy ghost
payload reads. Historical/current native/adapter modes each pass133,974 read
and1,462,272 metadata/frame cases across six capacities, including partial
words and200/376. Four guarded read sizes, two first-fault probes and224
protected-SP/operand-count probes pass;4,296 inline binding cases and seven
semantic mutations pass their expected outcomes. `make clight`,39 targeted
Lean jobs, deterministic970,802B export and three standard-axiom queries pass.
The stack fixture is2856B/8relocs; ordinary1448B/11 and contextXDP360B/TC760B/4
remain exact against historical headers and normal compilation. Full inline
export at that checkpoint advanced to MOVBE width/shared-read GNU expressions. CPP2,593,834B is
profile extraction only. Native arena-view/volatile/permission/fault relations
remain proof work. [Small receipts](results/m4-x86-stack-read/README.md) are
committed; complete raw evidence stays under
`/workspaces/kprog-raw/formal/m4-x86-stack-read`.

MOVBE width/arm and shared read declarations now have standard output forms
and CompCert by-reference inline adapters. `X86Memory` exports four roots,
including the full MOVBE-load body, in15 functions. Its calls name actual
`X86Pointer` C definitions/exports; Clight linking/type/effect correspondence
remains M5 work. Unaligned pointer slots use upstream alignment-one copying
into a volatile pointer local on CompCert; native BPF/host forms remain.
Historical/current native/adapter modes pass260 selector/51,520 read-frame/
4,060 handler-composition cases each, seven guarded/nonreturn probes and eight
mutation checks. The context oracle adds the full shared read to its19,200
context/frame cases per native/adapter mode. `make clight`,40 targeted Lean
jobs, deterministic189,714B regeneration and four standard-axiom queries pass.
Native memory1680B/5relocs, stack2856B/8, ordinary1448B/11 and contextXDP360B/
TC760B/4 match historical replay and normal compilation. Full inline export
now stops at MOV-store width/displacement/value GNU selectors. Profile CPP is
2,442,636B; no whole-default byte/performance or refinement claim follows.
[Small receipts](results/m4-x86-memory-read/README.md) are committed; raw
commands/failed harness attempts remain under
`/workspaces/kprog-raw/formal/m4-x86-memory-read`.

The store-selector and physical-store checkpoints are now validated. Seven
selector/prefix roots bring `X86Pointer` to33 functions, preserving native const
initializers, raw truth/second capture, signed immediate slices and lazy
register/AUX reads. Historical/current native/adapter modes pass260 width/
320 scalar-capture/336,960 prefix-frame cases each; nine mutations are caught.
The physical store reuses Platform's alignment-one copy on CompCert and retains
native volatile/BPF bodies. Its actual root and store callee bring `X86Memory`
to17 functions;896 byte-frame cases, seven guard/fault/refusal probes and three
mutations pass. `make clight`/40 targeted Lean jobs pass, followed by the small
38-job physical subset. Genuine exports repeat987,949B and194,324B with the
usual axioms only. Context export changes only printer-generated names.
Store2272B/13relocs, memory1680B/5, ordinary1448B/11 and contextXDP360B/TC760B/4
are exact against historical replay and normal compilation. The timing queue
acquired SH at19:44:34 UTC after Katran released EX; both workers are terminal.
At that checkpoint full inline export stopped at a declaration after a default
label, with profile CPP2,443,378B. These are component checks, not migrated refinements or
whole-default identity. [Selector receipts](results/m4-x86-store-selectors/README.md)
and [physical-store receipts](results/m4-x86-physical-store/README.md) record the
results; full raw evidence stays in their linked directories.

Two empty statements now make the MOV-store/MOVBE-store default-label
declarations standard C without changing scope. Focused historical comparisons
retain2272B/13relocs and1680B/5, equal to normal compilation. Full export now
reaches the XMM0 arm selector's GNU expression. No existing rooted AST changes
for this syntax-only follow-up; raw: `/workspaces/kprog-raw/formal/m4-x86-store-labels`.

The XMM0 arm now shares declaration/output forms with its native expression
facade. Both actual load/store bodies export through the existing generic
arena/fact binding; the existing address-add helper retains BPF pointer operand
forms and gives host/CompCert the address-bit form for null-base stores.
Absolute loads still select their immediate/index lazily. Low-before-high
commits, recovery and released-stack observations are retained. Historical,
native and CompCert-adapter modes each pass1,848 complete two-lane/state/fact
frames,260 selector/lazy cases and two guarded second-lane C-prefix probes;
four mutations are caught. These fault prefixes are C observations, with ISA
exception correspondence still unproved. `make clight`/40 targeted Lean jobs,
deterministic988,925B Pointer/458,974B Memory exports and three standard-axiom
queries pass. Pointer has34 functions and Memory20; these are AST counts.
XMM3424B/21relocs and ordinary1448B/11 match historical and normal compilation.
Full inline export now stops at CMOV writeback's GNU expression; profile CPP
is2,443,837B. [Receipts](results/m4-x86-xmm0/README.md) link the raw evidence.

The conditional handlers now share standard-C output selectors while retaining
their native expression facades. Four actual CMOV/SETCC register/memory roots
bring `X86Memory` to28 functions. Historical/native/CompCert-adapter modes each
pass78,336 CMOV,77,568 memory-CMOV,13,056 SETCC and13,056 memory-SETCC complete
frames,260 selector groups and three fault/nonreturn probes. Condition decoding
is independent; write composition uses the separately tested exported writer.
All16 conditions, parity, whole-word versus byte AUX, noncanonical flag bytes,
false32 zero extension, recovery and stack effects are covered. Eight mutations,
`make clight`,40 targeted Lean jobs, deterministic1,808,925B Memory output and
eight standard-axiom queries pass. Historical conditional1008B/4relocs and
ordinary1448B/11 are exact. Header replay now resolves nested include locations
and replaces every occurrence of guarded headers. Full inline export advances
to ten struct-return errors; the suggested `-fstruct-passing` probe exports115
functions successfully, with Lean validation recorded separately.
[Receipts](results/m4-x86-conditional/README.md) retain the distinctions.

The full production x86 inline interpreter now exports and builds as
[Clight/X86Inline.lean](KProgFormal/Clight/X86Inline.lean):115 functions,
19,427,933B, including the actual by-reference entry and all family bodies.
`make clight` uses CompCert's existing `-fstruct-passing` frontend transformation.
Clean fork `3df8ae2` keeps long statement/local-list syntax shared during Lean
code generation; no AST value, numerical semantics or proof limit changes.
The regression checks1,600 variable entries,2,001 scalar temporaries and2,001
mixed function-pointer temporaries, including order/types and native codegen.
The exact failing1667-temporary fields also pass in isolation after chunking.
The all-ten-module Clight build passes47 jobs; full re-export is deterministic
and five AST-root axiom queries use only the standard three. Lake now passes
`-j1` explicitly through `weakLeanArgs`; the environment setting alone had not
enforced one worker, and the earlier32GiB virtual-memory failure is retained.
The successful build keeps that same memory limit. This is the explicit64-byte
inline profile, not all producer capacities or a Clight refinement theorem.
[Full export receipts](results/m4-x86-inline-export/README.md) record the scope.

The actual ARM instruction dispatcher `ARM64_SIM_L_EXEC` now exports through
`kprog_arm64_execute`, with caller-owned capacity/bias/storage and flags/vector
references. `Arm64Addressing` exports31 functions/18,806,455B and `Arm64Numeric`
20 functions/167,556B. Shared declaration/output kernels retain native numeric
initializers; existing exported register primitives remove duplicated write
expansion. The same32GiB/`-j1` Lean build passes after the initial larger export
exhausted that limit. Historical/current-native/adapter modes each agree on
4,320 whole numeric/vector frames and ordered callbacks (7,827,228B each).
The independent memory oracle also runs scalar/signed/pair/exclusive/atomic
consumers through the dispatcher, retaining primitive tests as primitive scope.
Five mutations, `make clight`, all ten Clight modules/47 jobs, deterministic
re-exports and six standard-axiom queries pass. The native numeric/vector/live
condition fixture is exact:5,288B/one allocated relocation. Entry initialization,
helper/libc calls and program control wrappers remain separate; these results
are extraction checks, not migrated refinements.
[ARM receipts](results/m4-arm64-execute/README.md) retain complete scope and failures.

The actual ARM libc/clobber and branch/link/return wrapper roots now bring
`Arm64Addressing` to43 functions/20,619,432B and `Arm64Numeric` to21/171,547B.
The shared branch predicate retains native capture order; extraction reuses
existing C reads at their original sites. Historical/native/adapter modes
agree on11,543 complete frames/25,444,240B each, including2,160 libc and28 full
clobber states. Six new mutations and one independent adapter read-refusal
prefix pass their intended checks. Final `make clight`, all ten Clight modules/
47 jobs, deterministic exports and eight standard-axiom queries pass; the
expanded native fixture is exact at11,104B/five relocations. The return-to root
has an empty continuation table; actual program label/PC bindings and the
inherited ARM RET discrepancies remain explicit. These are C extraction checks,
with no migrated refinement count.
[Wrapper receipts](results/m4-arm64-wrappers/README.md) record the precise scope.

All95 ARM helper macros now have typed-callee extraction roots, bringing
`Arm64Addressing` to138 functions/22,050,154B. The explicit parameter table
matches pinned libbpf types and IDs; native helper selection remains unchanged.
Four void-call forms retain their native expression while CompCert uses standard
statements. XDP refresh reuses the existing full-pointer context boundary with
ordered partial commits. Final historical/native/adapter captures match12,823
states/28,557,200B each, with1,280 typed-helper cases, six new negative checks
and independent full-width-length/context refusal probes. `make clight`, all
ten Clight modules/47 jobs, deterministic exports and eight standard-axiom
queries pass; native socket11,104B/XDP15,320B/eight relocations are exact.
Typed callees still require an actual helper binding/effect relation in M5;
this is C extraction and ABI coverage, not kernel-helper correctness.
[Helper receipts](results/m4-arm64-helpers/README.md) retain the scope.

The actual RAW/XDP/SKB entries now export through typed continuations borrowing
their live locals in [Arm64Entry](c/Arm64Entry.c). The default 160-byte/bias 96
AST has 3 functions/840,530B; all eleven Clight modules/48 Lean jobs pass. Native
and adapter tests check 448 continuations per profile across six storage profiles,
including distinct SKB context-cast results, ordered context/cast refusal and
six negative mutations. Two native fixtures retain exact allocated bytes and
relocations. The entry export leaves an explicit program-body continuation hole;
it does not bind arbitrary producer return tables or establish a refinement.
[Entry receipts](results/m4-arm64-entry/README.md) distinguish host profile checks
from the checked-in default profile and whole-default byte coverage.

The borrowed program binding now exports the actual instruction/libc/helper
bodies in [Arm64Program](c/Arm64Program.c): 111 functions/11,497,120B. Extraction
wrappers include the unchanged CALL/RET and XDP/SKB fixtures, preserving their
real labels and nonempty return table. All 14 Clight modules/51 Lean jobs and
the mature library's link computations pass. Five C modes agree on 12,823 full
frames and 840 closed RAW program return/input-stream observations per mode;
the independent memory dispatcher and five new negative cases pass. Native
fixture allocated bytes and relocations remain exact. Entry's shared constructor
now records actual declaration sizes; its current export is 3 functions/837,600B.
[Program receipts](results/m4-arm64-program/README.md) separate borrowed-handler
cases from retained control-root cases and describe the full-payload profile.
This supplies concrete C program composition, not a migrated refinement theorem.

Payload callbacks now compile the actual producer LOAD/STORE macros after its
profile declarations, so compact ranks reach the shared C handlers. An assembled
ARM input passed through the real producer selects logical slots 0,1,3 in a
32-byte frame and stores their payloads in 3 words. Two copies exercise the
nonidentity mapping in both directions. Three C modes agree on 16 high64/return/
input cases; index and truncation negatives fail as intended. `make clight`, all
15 Clight modules/52 jobs, deterministic exports, standard-axiom queries and
three mature linker computations pass. Native fixture sections and relocations
remain exact. [Producer-layout receipts](results/m4-arm64-payload-profile/README.md)
record the current export sizes and distinguish these checks from refinements.

The x86 producer's 200-byte and 376-byte scalar-fact profiles now export as
`Clight/X86StackProfile200.lean` and `Clight/X86StackProfile376.lean`. The actual
parser and renderer consume the assembled `oracles/x86_stack_profile.S`; they
derive 25 and 47 separately named fact cells. No production interpreter change
is needed. The host oracle checks each live reference, pointer recovery and
clearing, along with a closed program return depending on high stack-base bits.
[Profile receipts](results/m4-x86-producer-profile/README.md) distinguish these
actual producer declarations from arbitrary-profile refinements.

The 81 canonical x86 helper macros now export with exact libbpf-typed callee
parameters through [X86Helpers](KProgFormal/Clight/X86Helpers.lean). They reuse
the existing capacity/arena/fact bindings and register-reader C bodies. Three
void forms use a CompCert statement adapter while retaining their original
native expansion. Each host mode passes 5,832 paired full-state/ABI/input cases
and 20 output-alias/refusal executions. Seven negatives, all 18 Clight modules,
the mature helper/read link and native fixture byte comparisons pass.
[Helper receipts](results/m4-x86-helpers/README.md) state the remaining callee
interpretation and whole-program obligations.

An assembled x86 program now passes through the actual producer with one
subroutine, two return sites and a clock helper. The formal export hook binds
public helper types to named platform callees before the inline C bodies are
compiled; native expansion is unchanged. `Clight/X86ProgramProfile.lean` has
126 internal functions. The actual label/layout/callee checks, all 19 Clight
modules, native/bound return and refusal-prefix captures and five negatives pass.
[Program receipts](results/m4-x86-program/README.md) preserve the scope and
separate the platform-callee interpretation from a refinement theorem.

M4's [closure review](results/m4-closure/README.md) supersedes the earlier
open-ended producer/storage status notes. The shared C and current exports
clear the source/frontend tasks; M5 must prove representation, platform and
control composition against the external steps. Preserve
unaligned memory and real context-pointer domains when binding the Clight
memory/ABI semantics; header parsing does not establish those relations.
The old generator's `--check` still expects its historical C rendering and
will disagree with this directly edited canonical header. Its comparisons and
old artifacts await the ordered M6 retirement; do not regenerate this C from
the old JSON contracts. M5 must prove the actual exported handlers against
the mature steps and recount O1/O2/O4; no theorem migration is inferred here.

Shared [native memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean)
form the platform view rather than a second numerical ISA. [ReferenceMain.lean](ReferenceMain.lean) executes
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

The maintained [x86 Sail comparison](tools/compare_sail_x86.py) also replays
fresh x86lean execution against the pinned selected register and memory/control
archive epochs. On 2026-11-14 all5052 requests completed:4524 agree,480 retain
Sail's model-stopped outcome,48 retain the recorded REP difference. Register
and memory cohorts stay separate (1692=1464+228;3360=3060+252+48). Every modeled
GPR, PC and defined flag is compared; the fixed cohort also compares all512
mapped bytes and the exact ordered data-byte read/write values. The comparator
refuses changed observation masks and changed REP output/trace rather than
classifying from the old status alone. Nine comparator checks include deliberate
GPR/flag/PC/memory/trace/payload corruption and a changed REP frame. Raw requests,
outputs, source/ELF/archive/payload hashes and cohort summaries are retained at
`/workspaces/kprog-raw/formal/m3-x86-sail`. The executable SHA256 remains
`00b2765fd68c811079d3865fd5b1ce58078d633a109cabb15307bcf51d6bbcc1`.
Run from this directory with `python3 tools/compare_sail_x86.py --archive
../results/kprog_verification_20261107/reference-x86-sail.log.gz --output
/workspaces/kprog-raw/formal/NEW-OUTPUT` (one shell command). Its original
`--model` mode is retained. These are archived Sail observations compared with
a fresh fork executable, **not a live Sail rerun**; the old temporary model
binary is absent. Stopped cases are not agreements. REP keeps the documented
first-element/whole-instruction and pinned F3/ZF disagreement; no fabricated
Sail completion is substituted. ARM's maintained archived ASL comparison above
also remains distinct from a live model execution.

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

The retained Tetragon wake program now has checked-in plain C in
[c/TetragonWake.c](c/TetragonWake.c) and a real 144-body Clight export. Its
indirect target reads and conditional branches use the shared C adapters;
call-only helper aliases preserve public struct tags. See the
[retained-program receipts](results/m4-x86-retained-program/README.md) for
selected host paths, exact native code comparisons and remaining M4/M5 limits.

Actual x86 XDP and SKB producer entries now export through the same bindings,
including context reads before and after a typed helper call. The
[context-program receipts](results/m4-x86-context-program/README.md) record
the entry layouts, full-pointer adapter checks and their explicit limits.

The actual linked readonly producer profile now also exports through the shared
selector and upstream alignment-1 copy adapter. Its 124 Clight bodies, initial
readonly memory, native byte parity and explicitly scoped host checks are
recorded in [the M4 readonly receipt](results/m4-x86-readonly/README.md).
These checks add no migrated refinement count; M4 closure is recorded separately.

The existing x86 CALL profile also covers a helper-tail subroutine. A symbolic
helper relocation must survive return normalization even when its placeholder
looks like an end-of-object branch. The [helper-tail receipt](results/m4-x86-helper-tail/README.md)
records the regression, actual Clight call/return sequence and six negatives.

M5 entry checking exposed a [Clight identifier defect](results/m4-clight-identifiers/README.md):
the old canonical temporary interval overflowed and made the generic ARM
function's `op` both a parameter and a temporary. The imported frontend now
allocates above actual named/local IDs, and Lean uses the exact canonical
identifier encoding. All exports are regenerated; canonical simulator C and
benchmark settings remain unchanged.

M5 now has a [Clight execution foundation](results/m5-clight-execution/README.md):
upstream step composition and a complete relational call of the actual exported
ARM width function for every byte input and arbitrary memory. The theorem
preserves all memory and emits no events. Its C-helper law does not add an
ISA-handler refinement count; all 2,065 migrations and O1/O2/O4 recount remain.

The [generic ARM NOP body proof](results/m5-arm64-nop/README.md) now composes the
actual internal width call and statement completion with LNSym's checked step
and the full native wrapper state. It proves one conditional body correspondence
under explicit binding, entry and representation conditions. Concrete heap
representation, function frames and compiled-label/all-behaviors obligations
remain before it can count as a complete handler refinement.

The [NOP procedure proof](results/m5-arm64-procedure/README.md) discharges
actual function entry for every initial memory and flags byte, with all nine
parameter bindings and 266 real local allocations. The subsequent
[deallocation proof](results/m5-local-deallocation/README.md) also proves that
those locals free successfully and preserves every old byte and permission.
The public call/return correspondence takes no freshness or free-success
premises. Concrete representation and decoder stability, compiled control
points and all-behaviors refinement still keep the complete-handler count at
zero; M5 and M6 remain open.

The [entry-read proof](results/m5-entry-reads/README.md) now follows the actual
entry fields, individual GPR/tag pointers and embedded vector pointer arrays.
Their checked reads survive the complete NOP call, and the four materialized
NZCV bytes remain related to LNSym without a heap-decoder stability premise.
This is a partial representation proof: producer admissibility, compact cell
mapping, pointer/native-memory representation and compiled control still remain.

The [internal-run proof](results/m5-internal-runs/README.md) certifies all 19
actual NOP call transitions. At its `Kstop` procedure boundary, every finite
execution is a silent prefix of that return, every stuck endpoint is the same
full return state, and no infinite execution exists. The concrete NZCV law
now covers every such relational return. These results need no external-call
determinism assumptions; general caller control and full representation remain.

The [register-representation proof](results/m5-register-representation/README.md)
now relates actual entry reads to all 31 GPRs, SP, 32 vector registers and NZCV.
It uses existing provenance materialization and explicit pointer-block origins
and cell-map bindings. The relation determines every covered register bit and
survives the actual NOP call and every return at `Kstop`. Producer admissibility,
native memory and general compiled caller control remain open.

The [origin-cache proof](results/m5-origin-cache/README.md) now executes both
exported C base readers and the scalar materializer against the existing M3
coordinate function. Every nonzero validity byte is covered; only a selected
STACK or RETURN cache needs a warm-cache premise. Calls preserve all memory,
and every materializer return at `Kstop` has the specified result. Cold input
calls, pointer-valued materialization and producer admissibility remain open.

The [cold-cache proof](results/m5-cold-cache/README.md) now binds the actual
exported input function and executes both cold base readers through its real
external-call relation. Writable-field premises construct the two cache stores
and establish `WarmCache`, preserving the provider outcome's trace and memory
before those writes. Relating that provider to native origins, pointer-valued
materialization and producer admissibility remain open M5 obligations.

The [represented-value materializer proof](results/m5-pointer-materialization/README.md)
also covers pointer-valued union inputs. Non-relative tags return the same
Clight pointer and retain its existing native block-origin binding. Scalar
relative cases reuse the warm-cache laws; relative payloads being scalar
remains an explicit producer condition. Every return at `Kstop` preserves
the complete memory and represents the M3 materialized native bits.

The [actual GPR-reader proof](results/m5-register-reads/README.md) now connects
the exported raw-value and tag functions to the checked entry observations.
For every GPR index 0–30, each call completes 28 internal transitions and
preserves all memory. Every pair of returns at `Kstop` agrees with the
represented native GPR through the default export's actual cell selection.
Producer initialization and compact source-profile bindings remain open.

The [SP/pointer-view proof](results/m5-sp-pointer-reads/README.md) extends
those reads to the actual pointer export and C's distinct SP selector 32.
Pointer GPR reads preserve their union representative in 28 transitions;
both SP value views return the borrowed relative offset in 21. The SP tag
branch returns STACK in 15 transitions with no memory-read premise. Their
Kstop return laws preserve complete memory and retain the explicit native
origin in the SP correspondence.

The [combined-reader proof](results/m5-program-read/README.md) now completes the
actual exported GPR `program_read` call for the 254 non-relative tags. Its
55-transition read prefix and 18-transition materialization tail preserve the
represented scalar or pointer and all memory. Every Kstop return has the M3
materialized bits. STACK/RETURN caches, SP and producer/native-memory bindings
remain open; these helper laws add no complete ISA-handler count.

The [warm combined-reader proof](results/m5-program-warm/README.md) completes
STACK and RETURN GPR paths through the actual borrowed cache cells in 91/92
internal transitions. Its all-tag return law represents M3 materialization
and preserves complete memory, with explicit scalar-relative-payload and
selected-origin-cache producer conditions. Cold Program paths, SP and the
producer/native-memory/control bindings remain open.

The [combined SP-reader proof](results/m5-program-sp/README.md) completes the
actual SP selector in 71 internal transitions and preserves all memory.
Every Kstop return matches native SP through the register relation and an
explicit warm stack-origin binding. Cold Program caches and producer,
native-memory and compiled-control obligations remain M5.

The [cold STACK Program-reader proof](results/m5-program-cold/README.md)
follows the real kind-1 provider outcome through both cache stores and the
complete GPR/SP reader return. It retains the provider trace and post-memory,
constructing a warm cache from explicit writable storage and pointer/range
bindings. The provider may change cache pointers; its native-origin binding
and the cold RETURN Program path remain open.

The [cold RETURN Program-reader proof](results/m5-program-return/README.md)
completes the other relative GPR branch through the real kind-3 provider
and borrowed cache stores. It shares the checked stage extraction and storage
constructor with STACK while retaining RETURN's own continuation. Native
provider/origin, producer storage and full-handler bindings remain M5.

The [raw producer allocation/cache proof](results/m5-producer-cache/README.md)
establishes actual function entry and distinct owned writable cache locals
without caller allocation or permission premises. The actual four-initializer
stage takes 12 internal transitions, zeros both invalid caches and frames all
caller blocks. Connecting the preceding producer body, header construction
and continuation remains open.

The [actual raw-prefix proof](results/m5-producer-prefix/README.md) connects
function entry through all 189 preceding assignments and cache initialization
in 580 internal transitions. It derives the stage memory from actual execution,
frames all caller blocks and retains the allocated frame's permissions and
frontier. Later input calls, header construction and the consumer continuation
remain open.

The [first producer-input proof](results/m5-producer-input/README.md) reaches
the actual kind-6 call in 594 internal transitions with the caches still cold.
Each stated scalar provider outcome then resumes the real continuation and
writes x0's declaration initializer and tag in nine transitions. The provider
trace/post-memory and explicit local-permission ABI binding are retained;
this does not establish the final architectural register or native origin.

The [remaining register declaration proof](results/m5-producer-registers/README.md)
binds all 31 actual blocks and their successor chain. The shared execution law
covers x0--x29's real provider calls and writebacks; x30's zero branch completes
without a provider. Each writeback retains the explicit provider post-memory
permission premise and preserves other local loads relative to that memory.
The shared first continuation is connected to the existing raw-producer prefix.

The [pointer-table proof](results/m5-producer-tables/README.md) constructs all
31 cell pointers and 31 tag pointers from actual allocated locals. The real
source segment completes in 186 internal transitions, with exact pointer
readback and other-local/caller framing. Composing the preceding x30 zero
branch gives 196 transitions and preserves its zero word and tag observations.

The [flag-input proof](results/m5-producer-flags/README.md) binds the actual N,
Z, C and V declaration blocks. Every stated scalar provider outcome resumes
the real continuation and stores a checked zero-or-one byte in four internal
transitions. The preceding complete pointer tables reach the first flag call
in 189 transitions and remain readable there. Provider post-memory and local
permission ABI premises remain explicit.

The [LR/vector initializer proof](results/m5-producer-vectors/README.md) binds
all 64 actual vector word inputs to their real low/high field offsets. Each
stated scalar outcome writes and reads back the complete word while framing
other lanes and locals relative to provider post-memory. The real LR-zero
declaration reaches the first vector call in six internal transitions; its
zero word remains readable at that boundary.

The [stack-tag/SP initializer proof](results/m5-producer-stack/README.md)
executes all 24 actual tag-byte clears and the signed-long SP-zero assignment
in 75 internal transitions. Every byte and the SP word read back zero, while
other declared locals and caller blocks retain their contents and permissions.
This is the metadata/SP initializer; stack payload and physical native-origin
correspondence remain separate.

M5 Numeric consumer boundary: `Arm64NumericProducerConsumer` derives the actual
entry argument, retained target, silent sequence step and local Freeable ranges
at the reached `initialized_storage` memory. With genuine callee/signature facts,
two call steps append to its original trace; a given body run and post-body
ownership compose with the three-step return/free suffix. Lifetime's original
APIs remain projections of world-bound laws. The kernel checks that the generic
void/nine-argument handler has a different ABI from the one-pointer/uint32
continuation. Its source body wrapper and binding remain open; this is partial
composition, with complete ISA-family count zero. See
[the receipt](results/m5-numeric-producer-consumer/README.md).

M5 MOVK caller composition: universal Continuation laws transport every imported
Clight transition, including actual label lookup, to a valid enclosing call.
Arm64MovKeepContext reuses the same203-step ordinary call, derives old-block
permission preservation and producer-local Freeable ranges, and retains the
mature checked native step at the same post-memory. This segment resumes its
caller; source-body factoring and native admission remain open, with completed
ISA-family count zero. See [the receipt](results/m5-arm64-mov-keep-context/README.md).
