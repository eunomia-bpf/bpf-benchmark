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
