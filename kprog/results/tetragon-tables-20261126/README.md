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
