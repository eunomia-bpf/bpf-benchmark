# Interpreter families and normal B measurement

2026-11-15T15:42Z:9fc382606 separates all57 interpreter families into static
always-inline functions. Existing branch statements are shared arm bodies;
raw and inline dispatch use one condition chain. The generator instantiates
small constant-opcode call wrappers from the same dispatch, rather than
optimizing one huge unknown-opcode function first. No per-opcode semantics
table or optimization selector. The reference-binding ABI and generic
x86_sim_inline_execute remain; FORMAL must bind the constant wrappers too.
Its separate35+6line CompCert adaptations were left unstaged/untouched.

Latest scoped checks pass1,024native+1,024full-context simulator cases,
normal B compilation, and the independent helper result/clobber/free-stack
oracle (64bytes,24zero-environment choices). No all-program proof claimed.

ec574a17f/4d9fb9aa9 reuse the actual normal bounds/MIR/all-pairs/llc functions
on anonymous seekable stage files, preserving captured older OTel inputs.
Explicit IR/MIR language replaces filename-extension inference; MIR lowering
observations have an independent report path. Ordinary file versus anonymous
transport have identical allocated B sections on the real table fixture:
360code bytes, post-PEI stackSize0. No compiler output is retained twice.
The initial missing report-path failure and all diagnostics remain raw.
This observer measures code and machine frames, not kernel acceptance.

Full OTel frontend+B+frame1054875/Clang1054890 started but is now paused
for C timing; no complete OTel result. Scale100/1000 is queued after this
actual job, independent of success. Older unfinished controls remain alive,
paused and input-preserved. Not-yet-started queues were reordered, their
commands/status retained. P-SPECIALIZE parent/full compile/stack/app remain
open; no runtime speed result or native flags/LTO changes.

**Resource incident:** C KatranAA guest1053026 began15:27:32 during generic
compiler1046429; I did not recheck live processes before the later launch.
The old compiler overlapped through~15:32:40, short transport checks also
ran15:28–29, and family compiler1054890 ran~9CPU seconds15:32:43–52.
Both were on CPUs8–11, but this violates workspace-wide timing isolation.
No kernel/base/image mutation occurred. All raw C data stays; affected
sample interpretation/repetition belongs to C under the14:14 instruction.
The15:32 coordination claim of no guest was wrong and is corrected here.

d5d890c4c fixes the resource exclusion for our work: shared timing lease
before image lease; a pidfd guard waits for C's actual timingEX release,
resumes the existing exact compiler and holds both shared leases until its
Make launcher exits. It is currently waiting and every PERF compiler is
stopped. This changes resource ordering, not benchmark validity or settings.
Future host jobs explicitly pass VERIFIED_TIMING_LOCK; timing jobs own EX.

Raw `/workspaces/kprog-raw/perf/20261115-inline-families` includes full
process/lease ancestry, release fdinfo, pause/lease events, commands, failures
and numerical observations. Prior controls/raw data are retained. No new
worktree/source copy/kernel/image/base, nor paper changes.

2026-11-15T16:18Z measurement continuation: current all-family OTel CPP is
6,019,192 bytes (5.506x generated C), not the earlier generic dispatch's
5,729,367 bytes. Its normal frontend is still paused behind C timing.
The queued scale observer now reads actual post-PEI machine stackSize for
all subprograms, through a pipe, in addition to direct R10-access depth.
Completed preprocessing and B observations are saved before later stages,
so a frame-observer failure preserves them. No extra frontend or retained
MIR build is added. Parser and real normal-B transport checks are queued
behind shared timing/image leases; validation of this observer extension
is pending. Scale100/1000 uses the updated observer when its existing job
starts after OTel. P-SPECIALIZE remains open.

2026-11-15T16:20:06Z: cc83b5d48 observer regression PASSED after actual C
EX release. Nonzero576/zero subprogram frames and missing/duplicate frame
errors pass; real anonymous normal-B continuation still matches every
ordinary allocated section (360code bytes, actual fixture stackSize0).
Whole-object bytes differ through metadata, so equality is scoped to
allocated sections. Result: frame-observer-check.json; full commands/logs
remain under raw inline-families/frame-observer-check. The pidfd guardian
acquired timingSH/imageSH and resumed exact OTel1054890 at16:20:06Z.
Actual OTel frontend+B/frame remain running, not inferred from this test.

2026-11-15T16:22Z: all eight100/1000 scale cases complete through the normal
bounds/all-pairs B pipeline and actual post-PEI frame observation (exit0,
8GiB address-space cap each). Current shared primitive WIP was present;
per-input generated/CPP/native hashes and all stage commands are retained
in scale-small/. Frontend below is the actual optimized LLVM stage, not
preprocessing; RSS is that child's peak. No kernel acceptance or runtime
gain is inferred. Scalar loops mostly fold constants and are not evidence
that arbitrary1000-instruction programs cost the same.

| Native case | Actual insns | CPP bytes | Frontend seconds | Peak KiB | B code bytes | Frame bytes |
|---|---:|---:|---:|---:|---:|---:|
|100 scalar direct|115|3671901|0.491|119004|248|0|
|100 scalar indirect|121|3674412|0.478|118980|256|0|
|100 pointer direct|115|3669597|0.549|117844|2232|32|
|100 pointer indirect|121|3672108|0.548|118400|2248|32|
|1000 scalar direct|1015|3772271|0.901|122480|248|0|
|1000 scalar indirect|1021|3774782|0.822|125212|256|0|
|1000 pointer direct|1015|3824755|2.081|183276|20224|24|
|1000 pointer indirect|1021|3827266|2.146|184004|20240|24|

The one-time handler definitions account for most small-case CPP bytes;
increasing100→1000 adds approximately100–158KiB rather than cloning each
handler per instruction. These are different scale inputs, not a paired
runtime comparison. Full6945-instruction OTel frontend still running.

2026-11-15T16:24:32Z: full captured OTel hotspot completes normal B and actual
post-PEI frame observation (all stages exit0). Same6945-instruction P/proof/
metadata hashes as the earlier observation; source/header hashes are in
`otel-complete.json`. CPP6,019,192bytes, optimized frontend8,381,368bytes;
frontend251.093user+3.541system=254.634CPU seconds, peak5,539,808KiB
(5.28GiB). The raw3096.438s wall includes the explicit15:32:52–16:20:06
pause and must not be presented as uninterrupted compile latency. Three
late debugger samples caught loop analysis/unrolling/induction, not a pass
cost breakdown. Normal bounds/MIR/all-pairs/final object stages take about
9.27s total; independent frame observation adds2.30s.

B executable bytes1,103,248 (137906BPF slots), object2,356,504bytes;
actual allocated frame448bytes. Historic hotspot observations were576bytes
before packing and552after packing; compiler/bounds/storage changed too,
so this is the current combined normal pipeline, not an isolated effect of
one edit. It is under512; no kernel load, checked-native installation,
whole-app acceptance or runtime speed is established by this observer.
B/IR/MIR were anonymous descriptors and closed after measurement; commands,
hashes, resource usage and diagnostics persist without another build copy.
Pidfd guard released both leases after the Make launcher exited16:24:32Z;
resume-events.json records the pause/resume boundary. Old paused controls
and canonical inputs remain untouched.10K/100K scale groups continue.

2026-11-15T16:25:42Z: all four10K cases finish normal B/frame stages,
exit0 under8GiB AS. Per-stage commands/resources and CPP/B hashes are
committed in scale-10k/; original larger runs remain raw.

| Native case | Actual insns | CPP bytes | Frontend seconds | Peak KiB | B code bytes | Frame bytes |
|---|---:|---:|---:|---:|---:|---:|
|10K scalar direct|10036|4789492|11.609|410732|504|0|
|10K scalar indirect|10084|4808289|11.894|408556|328|0|
|10K pointer direct|10036|5389846|26.272|939184|200480|32|
|10K pointer indirect|10084|5408643|25.672|942316|200624|40|

The old same-named scalar/direct production case ended SIGKILL after5693s
and73,891,664KiB RSS before B existed (scale-stock-10k-first/report.md).
This current pipeline completes it with about401MiB frontend peak and a
zero-byte frame. That is a resolved practical failure on this fixture;
the intervening compiler changes and scalar constant folding preclude
attributing an isolated optimization speedup from those two observations.
100K remains running; there is no new stock-kernel or app/runtime result.
