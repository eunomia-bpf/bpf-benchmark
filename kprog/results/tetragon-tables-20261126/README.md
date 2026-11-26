# Tetragon table-generation boundary

PERF 2026-11-26T15:53:59Z.

The section0 phase1 item lists14 relative-table liveness refusals and10
finite-indirect-target refusals. This replay uses the retained proof objects
and metadata from omp-five-20261120/tetragon/session-6f0mwwi2. It does not
change P, its flags, the image, kernel, workload or LTO selection.

`make reproduce` initially reproduces request12's live-result refusal and
request9's unresolved jmp-rax at0x3580. reproduction-before.json and
reproduce-before.log retain
those outcomes. Request12's first observation is the call at0x292 to
filter_inet, whose actual body starts at0x3c2 in the same proof. The old
analysis instead fabricates six arguments and arithmetic-flag inputs for
that known local call, rejecting private R8/RDX table results as observed.

The common x86_relative_tables.py analysis now visits a known direct callee's
actual instruction effects as well as its caller continuation. It preserves
the old private masks in the continuation, deliberately crediting no callee
kills. Local returns are checked through that continuation, while the
original function's return remains an RAX observation. The worklist keeps
those return contexts distinct. Unresolved calls retain their previous
conservative treatment. No private memory spill is erased and no runtime
check, per-app rule, new compiler option or alternate pipeline is added.

`make check-calls` assembles calls.S, links each selected entry with the
canonical native-link and reads its byte-bound instruction effects through
the normal generator. All9 cases pass: unused local inputs and discarded
local returns are accepted; callee/caller register observations, callee/caller
flag observations, an observed return and an unresolved external call are
rejected; the existing zero-argument helper treatment is unchanged.
`make check-calls REVISION=c47fa6a15` runs the same expectations against the
prior source loaded from Git into memory. It fails the two positive local
cases, as recorded in call-checks-before.json/log. No private source copy is
created. The initial seven-case and intermediate boundary records also stay.

The14-request breadth replay is:

```
make reproduce REQUESTS='12 16 23 33 38 39 41 49 58 62 64 71 75 80 9'
```

Requests39 and62 now pass table lowering, each4,252→4,244 instructions.
The other12 live-result cases reach a later original-function return with
live RAX bits (0x5e0, or0x588 in requests38/64). They remain refused. This
is not a claim that all14 requests generate B or pass the stock verifier.
Request9 remains refused: its table base is hoisted into R15 at0x3560
before a loop; the load/add/jump at0x3579..0x3580 no longer has the adjacent
base-LEA pattern the current lowering requires. Neither remaining condition
is bypassed by this fix. lowering-breadth.json and breadth.log retain every
outcome and the first actual observation.

Checks run under shared timing on CPUs16–17 with an8GiB address-space cap;
no guest or sole-image rebuild is needed for this B-analysis-only change.
Full B source generation/compilation and stock acceptance remain separate
next steps for the two advancing requests. Main-configuration coverage and
the Tetragon/OTel performance objective remain open. Full timing is frozen.

Full B source generation now also passes requests39 and62 through the normal
generator, including definedness, map annotation and instruction rendering.
Both sources have608,257 bytes and identical text. reproduction.json and
source-generation.log record that next boundary; the generated sources stay
beside their retained proof inputs. They are not stock-verifier acceptance.

The next `make compile` uses request39's source through the installed normal
stock-input wrapper, packet-bounds compiler, whole-word spill pass and BPF
backend, with their existing flags. It records each actual command/outcome,
the final object size and the equality to request62's source. This avoids a
duplicate compile of identical input, without a per-program production
policy. The finite job records its own result and wakes the lane on either
outcome. No compiler, base or image rebuild, new LTO setting or native flag
change is involved. Actual stock/app acceptance remains open.

Compilation completed with returncode0: all8 recorded subprocesses succeeded,
including the three preprocessing pieces and the installed packet-bounds,
spill and final backend stages. The B ELF is1,939,680 bytes, including debug
information. compile-status.json/compile-commands.jsonl/compile.log retain
the actual outcomes. compiler-evidence.tar.zst (9,133,233 bytes) publishes
the joined input, both bitcode stages, both MIR stages, spill record and
final ELF; uncompressed artifacts stay locally. The normal preprocessing
cleanup is recorded in cleanup-log.md. The first launch failed before Make
because an optional /usr/bin/time wrapper was unavailable; its log and
launch metadata remain separate from this successful compilation.

The subsequent detached stock replay reaches the sole kernel with114,694
instructions and rejects request39 at instruction2 for an R10-528 write.
It therefore advances into the existing B stack-pressure class; no stock
acceptance or checked-native installation is claimed. See stock/README.md
and the full verifier log. Request62 is not separately stock-loaded.

PERF 2026-11-26T16:41:11Z — Actual return destinations

The successful eight-stage request39 compile and its later stock R10-528
rejection remain the actual callback result. The next common refinement
uses the existing ABI analysis on the original native image to collect
return-address destinations, including the outer-return sentinel. Liveness
now follows known local callees through their actual writes and those return
edges. Unioning contexts adds possible paths; it cannot invent a kill.
Unknown return addresses refuse live private state. Other callers of the
liveness routine retain the prior conservative behavior. Full RAX reads at
callers and outer returns remain full-width observations. No callee ABI
clobber assumption, runtime guard, app selection or compiler flag is added.

The original request12 caller tests full RAX at0x301. The old unchanged
continuation masks therefore refused the RET at0x5e0 even though the actual
filter_32ty_map call defines its result. return-paths.json records72
context-specific RET facts and a248-byte native stack extent from the
existing ABI analysis; this is not the generated B verifier stack usage.

All16 assembled/linked cases pass, including the original nine, full and
partial return writes, a conditional non-write path, nested calls, flag
kills, a deliberately redirected return and an unknown return. Prior source
ea8b962bc fails four positive cases; both before logs and earlier fixture
records are retained. These tests use actual native-link effects and ABI
return facts, not a substitute instruction model.

All14 retained liveness cases now complete lowering and full B C rendering.
Exact source groups are12/16/23/33/41/49/58/71/75/80 (371430bytes),
38/64 (370458bytes), and39/62 (608257bytes). The39 source is unchanged
from its successful compilation. reproduction-local-calls.json retains the
previous outcome; reproduction.json and reproduce-return-paths.log are the
new breadth result. New groups12 and38 still need normal B compilation and
stock verification. The separate ten hoisted-base/finite-target cases remain
open. No main-config app acceptance or runtime gain is claimed. P, image,
kernel, workload, common flags and combined LTO selection are unchanged;
full timing stays frozen.

PERF 2026-11-26T16:50:44Z — Stack-alias boundary and remaining breadth

Forward correction after fab61404f: return-fact extraction requires an
actual integer RSP offset. An external/scalar alias is represented by False;
Python dictionary lookup would otherwise equate False with private offset0
and incorrectly reuse the outer return address. Two actual relocated-table
fixtures exercise the whole lower_relative_tables path. The18 total cases
pass; fab61404f incorrectly accepts table_external_stack, as retained in
check-return-stack-alias-before.log/call-checks-before.json. No runtime
check is added. All14 real cases still lower after this correction, and all
recorded original RET stack offsets are integers (return-paths.json and
breadth-status.json). Their generated sources therefore remain unchanged.

Fresh breadth9/20/25/32/47/50/55/72/77/83 confirms all ten finite-target
failures at0x3580. Their proof object bytes equal request9. The full context
now includes LEA R15 at0x3560, loop entry0x356b, load0x3579/add0x357d.
This class needs a proof for the persistent table base across the loop;
merely accepting a nonadjacent LEA would lose that obligation. No production
change for it is included. hoisted-breadth.json/log retain these failures;
reproduction.json again names the successful14-case stage, also preserved
as reproduction-return-paths.json.

Finite job642075, source ae0a2546d, compiles new groups12 and38 under
separate16GiB address-space limits on CPUs16 and17 with shared timing lock,
then stock-loads successful compiler products using the existing detached
Make entry, sole kernel and2vCPU/2GiB guest on18-19. Per-stage archives,
commands, statuses and publication log live in return-pipeline. This source
change affects only rejecting unknown RSP facts; the14 accepted sources
have integer RET offsets. Compilation/stock results remain pending here.
All raw data is retained, and full timing remains frozen.

PERF 2026-11-26T17:03:10Z — Completed return-group pipeline

Controller642075 completed1 at16:57:53Z. Both normal B compilations succeed,
seven child commands0 each: request12 ELF6594560bytes, request38
ELF6508304bytes. Complete compiler evidence is archived per case; commands,
statuses, source revision ae0a2546d and kernel83e0fabe355d are retained.
Actual stock guest16:57:47–16:57:53Z submits412628 instructions for12 and
406458 for38. Both returnrc2/errno13 and stock_loaded=false. Request12
fails insn1 at R10-976;38 fails insn1 at R10-968; each processes2insns.
The initial arg#0 UNKNOWN/-22 message is also retained. Together with the
previous39/62 representative rejection at R10-528, every distinct generated
source group has now reached and failed stock verification on B stack
pressure. Equal-source peers were not separately loaded; no checked-native
or app acceptance is claimed. These are real failures to fix within the
existing pipeline, not a reason to alter the kernel stack limit or exclude
programs. Full timing remains frozen.

All four successful preprocessing commands and their eight normal piece
removals were inspected again: all pieces remain absent, joined .i and
compiler evidence remain. The own cleanup-log line was committed in
7949ec26a; no additional removal occurred. return-pipeline-outcome.json
records the actual outcomes and this reinspection. Raw compiler evidence
publications are e1797f3c5/1fd28da00, stock publication99841361e.

PERF 2026-11-26T17:20:28Z — Persistent table bases

The request9 probe establishes that its persistent R15 base has no other
observation after dispatch substitution. Production now recognizes a
nonadjacent LEA as a candidate only: the existing original-image ABI
analysis exports actual CFG edges, including stack-tracked RET destinations.
A backwards walk from each load must encounter that LEA on every rooted
path before another write to the base. Unknown return CFGs remain refused.
A separate forward private-state proof over the proposed dispatches rejects
any other use of the base. Target and ADD-flag liveness remains checked on
the original image. The LEA becomes a NOP in B so its code identity stays
valid for entry/branch/return references; P/native bytes are untouched.
Shared adjacent/nonadjacent uses are checked together. There is no new
runtime guard, application selection, ISA value interpreter or compile flag.

All26 actual assembly/link cases pass:18 existing call/table cases plus8
persistent-base cases. Both a loop and a shared base are accepted. Another
reaching definition, a bypass, a callee clobber, a RET that skips the LEA,
an external base observation and live ADD flags are refused. Prior7949ec26a
fails both positive persistent cases. Initial fixture-link/layout errors
and intermediate expectation failures remain in their logs; final linked
proofs and exact errors are retained.

All24 retained Tetragon requests now lower and fully render B source. The
ten former finite-target refusals have identical717038-byte generated C
(4917→4900 instructions each); the previous14 source texts are unchanged.
all24-generation.json, all24-source-groups.json and all26-checks.log record
the result. This closes generation for these24 captures, not phase1 stock
or application acceptance: the three earlier source groups failed the
stock stack checks above. The new9 group still needs normal compilation
and stock verification. The same finite driver can now run a selected
evidence group/destination; make hoisted-pipeline does that for9, not a
production policy. Future compiler archives stream into48000000-byte
parts to keep tracked evidence below the repository file limit. Raw old
archives and compiler products remain. All LTO pieces stay together; image,
P/common flags, kernel/workloads and full timing are unchanged.

PERF 2026-11-26T18:14:13Z — Hoisted-group emission outcome

Normal compile9 ran17:28:27–18:00:21Z. Eight child commands: the first
seven return0, including whole_word_spills; final llc returns1 with repeated
BPF stack-limit errors under the existing -bpf-stack-size=4096 setting.
The script records1/ELFbytesnull, Make returns2, controller1. No usable
ELF was emitted; there is no stock/result.json or verifier log because
stock was not attempted. Generation success is not compiler or stock
acceptance. Full commands/errors/status and20001885-byte archive part
remain; tar/zstd/split statuses are all0. Three successful preprocessing
commands removed six generated pieces after joining; inspected absent and
listed in cleanup-log.md, joined/intermediate products retained.

The shared stack problem remains: three earlier groups emit B but stock
rejects R10-528/-976/-968; group9 fails emission itself. No limit is raised.
The next diagnostic uses the preserved LLVM module embedded in the smaller
39 baseline MIR to test a common O2 machine backend without rerunning the
large frontend/GVN pipeline. This is a compiler control, not an adopted
per-program policy. Production flags, P, image, LTO selection and full
timing remain unchanged.

PERF 2026-11-26T18:31:35Z — Backend control input correction

First control backend-o2-control stopped before LLVM: the MIR literal reader
rejected a valid unindented blank line. Fixed in2449c5f7b; all initial
records remain. Retry backend-o2-retry-20261126T182605Z ran the O2 machine
backend and packing, but final emission failed stack diagnostics. This
recreated354 eight-byte non-spill objects (plus304-byte native storage),
where the baseline MIR had one8-byte object plus304. The embedded IR has
355 allocas but lifetime.start references only2 distinct objects; original
bounds IR references359. Counts/commands are in backend-input-lifetimes.json
and per-case records. Recompiling a post-machine-pass IR snapshot changes
allocation/lifetime information, so this failure does not isolate backend
level. No stock guest ran and no production policy was adopted.

The corrected control emits LLVM IR from the preserved bounds.bc using the
normal O1 compiler flags, before instruction selection, then uses the same
fixed O2 machine backend and existing spill packing. All prior inputs and
products remain archived; current case products are replaced in place.
The next retry retains this input-stage correction explicitly. No frontend
source reprocessing, P/image change, per-program flag policy or limit raise;
all LTO pieces and full timing stay as before.

PERF 2026-11-26T18:44:46Z — Proper machine-only control, no improvement

backend-o2-ir-stage completes normal O1 IR emission, O2 pre-PEI, existing
packing and O2 final emission (all4commands0); ELF1939680bytes. Its entire
ELF is byte-for-byte equal to the archived normal39 baseline, including
917232-byte kprobe/trusted and320-byte .text code sections. Stock submits
114694 instructions and rejects insn2 at R10-528/errno13, processed3, just
as baseline. backend-o2-instruction-comparison.json records the comparison.
No production backend policy is changed by this control.

The next fixed recipe tests O2 IR optimization after the existing bounds
canonicalization, followed by the same O2 machine pipeline. Original C
frontend staysO1; generated C is not reprocessed, all cases use the same
post-bounds policy, and P/runtime image/all LTO pieces remain unchanged.
This tests the IR stage that the machine-only control left unchanged.
Archive/raw baseline and both failed input controls are retained. Full
timing remains frozen; no stock acceptance is claimed.

PERF 2026-11-26T19:31:51Z — Post-bounds O2 outcome and spill audit

postbounds-o2-control completes all four compiler children0 and emits
1647536-byte ELF. Stock submits88947 instructions but rejects insn1 at
R10-1304 (processed2, errno13, rc2). This is smaller code than normal39's
114694 instructions, but still stack-unsafe; the recipe is not adopted.
The first rejected offset does not measure the total frame. All archived
intermediates and completed logs remain, including the prior machine-only
O2 control with byte-identical normal ELF. Production B remainsO1; P flags,
image and all LTO pieces stay unchanged. Full timing remains frozen.

spill_liveness.py reads normal39 MIR from Git fab61404f into memory. Its
backward CFG audit models both32-bit halves of each spill, including partial
stores. After existing dead-frame-address/scalar normalization, pre-packing
139 spill objects peak134 live; packed133 peak127 live, greedy coloring132
ignoring size classes and default/escaped storage. These conservative
static counts do not prove the minimum frame or a production packing fix.
Failed initial access-parser trials and final audit logs are retained.

PERF 2026-11-26T19:32:47Z — Exact return-PC facts after LEA

An actual assembled saved-return-PC load, LEA by+1/-1, store and RET
incorrectly retained the original continuation in x86_abi. offset_pointer
now forgets exact ReturnAddress facts after nonzero displacement, keeping
zero-offset copies precise. This conservative analysis fix changes no
native instruction or runtime policy. The three actual assembly/link cases
pass; prior06d05f8f0 fails both displaced cases. Existing18call-liveness
and8persistent-table tests also pass. Initial fixture-link and outer-RET
selection mistakes are recorded in the trial logs; final tests inspect
only RETs reached under a real local-call context. Full24-source breadth
replay is running separately; stock frame failures remain open.

PERF 2026-11-26T19:35:41Z — Breadth and uninterrupted-backend control

The full24captured requests again generate B C successfully; all24source
texts are byte-for-byte unchanged after the return-PC fact fix.
return-lea-breadth.json/log retains the actual replay. Static archived ELF
R10memory operand inventory backend-stack-operands.json finds normal39
minimum directFPoffset-1376, machine-onlyO2 also-1376, post-boundsO2-2056.
These are direct memory operands only, not total frame measurements; the
normal stock first rejection-528 never implied only16bytes excess.

The next result-only unsplit-control uses preserved normal bounds.bc and
the same production O1 flags, emits B in one uninterrupted Clang invocation
without MIR serialization/packing, then attempts the same sole-kernel stock
load. It tests that compiler boundary rather than another optimization
level. It is one fixed recipe, no production per-program selection or
runtime setting. Existing MIR/backend-input.ll are archived untouched and
are not outputs of this control. Prior generated artifacts remain in their
committed archives; the canonical B object is replaced in place. Dry Make
commands are retained in unsplit-dry-run.log. Production B/P flags, image,
all LTO components and frozen full timing stay unchanged.

PERF 2026-11-26T19:39:25Z: uninterrupted-O1 controller708379 compiled39 at19:37:29–19:37:39Z, one child0/ELF1791576. Static executable sections have96458instructions including40in .text, directFP memory offsets reach-1424. The archive9350013bytes has tar/zstd/split all0. Stock and final publication remain pending; this is no verifier acceptance or production-policy change. Recipe/fresh24replay publishedd3532f653, exact launch texts retained because the job started from18d696405 while that publication ran.

PERF 2026-11-26T19:43:10Z — Actual uninterrupted-O1 stock failure

Controller708379 completes1; stock19:38:43–19:38:48Z submits96458instructions
and rejects insn28 atR10-808, processed28/errno13/rc2/stock_loadedfalse.
Raw publicationsfffad8a3d/f429c0220 retain compiler archive9350013bytes and
stock metadata; completed ignored logs are now explicitly committed.
Removing MIR serialization/packing alone does not fix stack bounds. No
production recipe is adopted and no claim of a unique layout cause is made.
The original normal three stock failures and9emission failure remain.

The return-fact audit also found return_from indexing its saved-value map
with False (external-pointer marker), which Python equates with offset0.
An actual local callee copies its savedPC to private offset0, changesRSPto
externalRDI and returns;18d696405 invented the original continuation.
The common analysis now requires an actual integer private stack offset,
matching the existing table-fact consumer guard. Four return-safety cases,
18call-liveness and8persistent-table cases pass (30total). Prior18d fails
the new external-stack case. This fixes analysis correctness only; nativeP,
flags, image and runtime LTO stay unchanged. Four source-group representative
replays are in progress; full timing remains frozen.

PERF 2026-11-26T19:44:05Z: after the external-RSP integer guard, representatives9/12/38/39 all regenerate B C and each source text is byte-for-byte unchanged. return-stack-breadth.json/log records these four distinct-source classes, not a new full24replay or stock acceptance. The earlier full24replay after the LEA fix remains separately retained. No B rebuild or native/image change is justified by identical source text. All finite controls and their publications have completed; current compiler controls are diagnostics only and none is adopted.

PERF 2026-11-26T19:55:54Z — Full-stage acceptance audit launched

The coordinator's18:17Z request checks whether06d05f8f0's four persistent-base
proof conditions reject an input previously accepted. stage_acceptance.py
wraps the unchanged restore-529-20261121/offline_link.py: it retains every
current explicit(object,symbol), its real proof/kernel commands and stand-in
link plan, and additionally renders complete B C from a preserve-entry
proof with both pre06d and current generator/ABI/table modules. Historical
Python comes from Git into memory; no checkout/source copy or tool rebuild.
Both renderings use identical ELF-derived section/context and map/global
externs. This is offline generation/link compatibility, not B compilation,
stock acceptance or live map/context binding; .text helper entries are
retained and labeled with their actual section, not called real app loads.

P3's older289/289 aggregate lacks its matching manifest snapshot. The
current stage has286explicit pairs plus49runtime-resolved groups, as already
recorded by the cmov trial census. The full current explicit set is checked
once without renaming its count289; all49unresolved entries are retained
in catalog.json. The three historical pair identities cannot be reconstructed
from the aggregate receipt alone. This scope limitation remains explicit.

Both historical/current generation pass the existing tiny call fixture with
identical1556-byte C; actual smoke/dry Make logs are retained. Finite
controller715897 started2026-11-26T19:54:29Z onCPU16/AS16GiB under
existing shared timing/image locks. Input stage278MiB is captured in
compressed parts<=48000000bytes; one canonical proof/kernel output set is
replaced in place and each completed pair's evidence is archived first.
Journal/progress update per pair; each application is published, then the
final acceptance comparison and any regression IDs are published/wake the
lane. First26BCCpairs link and render before/current with unchanged texts.
No final no-regression conclusion yet; all LTO/nativeP/image/settings stay
unchanged and full timing remains frozen.

The five queued compiler callbacks were reread in callback-audit-20261126T195326Z.json; actual
statuses still match the committed outcomes. Firstcontrol failed in its
MIR input reader before commands, retry finalemitter1, machineO2 emits the
identical normalELF then stockR10-528, postIR2 stockR10-1304, uninterrupted
O1 stockR10-808. No preprocessing command/newpiece cleanup occurred in any
of these controls; original9cleanup is already committed and rechecked.

PERF 2026-11-26T20:11:51Z — Full current-stage acceptance result

Finite controller715897 completed0 at20:03:34Z; final publication2450cf92c.
All286explicit current pairs link. Complete C rendering accepts285before
pre06d parentd229ed691 and285current source0be40eef0; those285 C texts are
byte-for-byte identical. Zero newly refused, zero missing pairs and zero
unexpected generation errors. Per-app pairs/generated-before/current:
BCC26/26/26,Cilium61/61/61,Katran3/3/3,OTel24/24/24,
Tetragon76/75/75,Tracee96/96/96. Thus every request accepted by the pre06d
generator in this entire current explicit catalog remains accepted; the
four persistent-base proof conditions introduce no refusal on that set.
This is not a claim about stock B verification or live app safety.

One pre-existing refusal is unchanged: case188, Tetragon
bpf_multi_usdt_v61.native.o:try_preload_arg (.text helper),
`ABI CFG target 0x40f2 is not an instruction`. This is not a06dregression;
it is a separate phase1 generator issue to inspect next. Every one of286
per-case archives has been opened, its case.json matched against the journal
and its before/current source bytes compared directly when generated.
The native input archive tar/zstd/split statuses are all0.

The scope remains286current explicit pairs plus49unresolved runtime groups,
not the historical P3aggregate289. That older receipt has no matching
manifest snapshot, so three old pair identities are unknown. The49groups
are retained in catalog.json, not resolved or skipped at app runtime by
this audit. No source/policy/flag/image change or new preprocessing/removal
occurred. Full timing stays frozen and all LTO pieces remain together.
