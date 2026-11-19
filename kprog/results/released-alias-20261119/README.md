# Released private-stack address forms

PERF 2026-11-19T10:04:14Z. P-x86-released-alias follows the LOCK fix. The
coordinator's freeze/LOCK BCC batch remains intact; this experiment changes
results files only and runs under timing SH on CPU 19 with a 4 GiB limit.

The real shared C compares RSP, fixed tagged-stack aliases and indexed
tagged-stack aliases reaching arena byte 40, at widths 1/2/4/8. Both live
and released storage are exercised through READ_MEM_VALUE and MOV_LOAD.
The input provider returns one explicit distinct value and counts visits.
The test records all 48 observations before requiring equal values and
input visits for each equal-address group. A failing assertion is expected
from the current fixed-load discrepancy. It supplies no stock, app, runtime
or hardware proof and adds no benchmark gate. Raw failures remain retained.

Source: x86_sim_local_bpf.h:1460 selects KPROG_X86_MEM_LOAD_FIXED when no
index is present, bypassing NATIVE_DATA_LOAD_TAGGED_INTO's released-byte
observation at lines 975–983. MOV_LOAD has the same shape at 1632–1638.
RSP uses STACK_READ and the indexed alias enters the tagged read. The prior
LOCK regression preserved those existing contracts. No request-time header,
generator, compiler, service, loader or formal export is edited here.

PERF 2026-11-19T10:08:32Z: Worker 334315 completed at 10:06:57Z with Make
exit 2 at the expected semantic assertion, source 97cf863dd. All 48 cases
were written before the assertion: the eight live groups agree, and all
eight released groups differ (two families x four widths). For the byte
case, fixed aliases read 0x88 with zero input visits, while RSP and indexed
aliases return the supplied 0x80 with one visit. Wider cases show the same
stored-value versus environment-value distinction. result.json retains all
observations and grouped differences; complete commands and the assertion
remain under /workspaces/kprog-raw/perf/released-alias-20261119/
reproduce-20261119T100657Z-334315. This is a reproduced shared-I discrepancy,
not a compiler/setup failure or an app performance result.

The next source change should preserve the fixed physical access, including
its constant displacement and base barrier, then apply the same tagged
released-stack observation used by the indexed path. A shared post-load
observation can serve fixed and indexed reads without replacing the fixed
access with a different load hook. Apply it in READ_MEM_VALUE and MOV_LOAD;
retain the physical read before tag/input evaluation, so an access failure
consumes no extra input. Live and non-stack accesses retain their values and
input visits. Test all address forms and byte widths again, together with
the existing fixed-load/base-barrier and LOCK regressions.

This is a phase-1 source/model change. It introduces no program filter,
refusal, runtime limit, mode switch or new benchmark condition. Its exact
shared-header freeze scope must cite this new evidence when implemented;
the earlier LOCK exception is not a substitute. FORMAL's primitive and
memory observation obligations remain explicit. No source patch or guest
was started during coordinator batch 327120, whose request-time inputs
remain those of 3f80b472e.

PERF 2026-11-19T10:22:12Z: e490f5065 extends this regression with eight
ordinary non-stack reads and four protected-page fault-order cases. Ordinary
reads must retain the physical value and their existing input visits;
MOV_LOAD's scalar recovery observation remains distinct from the tagged
released-byte observation. Protected fixed/indexed STACK-tagged reads must
fault before invoking the released-value provider. The signal test checks
user-mode physical access order, not kernel exception delivery or a formal
fault refinement theorem. The original 48-case/eight-group result stays as
recorded above; no extended-test pass is claimed yet.

Detached worker 337201 was queued at 10:16:25Z, raw
/workspaces/kprog-raw/perf/released-alias-20261119/
reproduce-20261119T101625Z-337201, launcher
/workspaces/kprog-raw/perf/released-alias-fault-launch-20261119.log. It waits
on timing SH behind the coordinator's BCC guest; started/exit-code/result
are pending. Preserve that worker and its committed scripts/fixture until
it finishes. No request-time input, image, base or benchmark setting changed.

PERF 2026-11-19T10:33:14Z: repair.patch now contains the exact deferred
header change, with 19 added and 18 removed lines. A shared post-load stack
observation serves the existing address/indexed loaders and a fixed-load
wrapper. Only the two affected default fixed-load branches are redirected;
the ABI-specific pointer paths remain as they are. The fixed wrapper still
calls KPROG_X86_MEM_LOAD_FIXED with the original displacement and width,
before evaluating its stack tag and environment input.

`git apply --check kprog/results/released-alias-20261119/repair.patch` passes
against the active header. This validates patch context only: the patch is
not applied, compiled, stock-verified or timed. It changes no active source
or build input and is not a second source tree. After the batch and queued
reader finish, add the defect-specific freeze row and apply the delta in
the single checkout. Run the expanded alias test, shared LOCK checks and
fixed-load/base-barrier regressions before committing the source fix. The
item and its runtime/proof obligations remain open.

PERF 2026-11-19T10:48:19Z: Worker 337201 ran after timing released and
finished Make 2 at the intended final address-form assertion. All eight
ordinary reads and four physical-fault ordering cases passed first. The
same eight released groups remain unequal. baseline-with-guards.json
retains all observations; complete raw output remains in its original run.
The batch and reader are terminal, so the prepared source repair can now
be applied without changing either completed cohort.

PERF 2026-11-19T10:52:22Z: The delta is now applied to the single header, with a
new defect-specific freeze row. Minimal source diff is +17/-16 lines; there
is no active kernel, module, loader, compiler binary or benchmark change.
The new post-load observation preserves the fixed physical access and its
base barrier, and is shared with the pre-existing indexed/address routes.

Focused checks under timing SH pass: all 48 address-form observations now
agree, all eight ordinary reads and four physical-fault ordering cases pass;
17,424 LOCK hardware vectors, 80,000 concurrent increments, live/released
aliases, recovery and negative displacement cases pass; all 22 B/native
atomic compilations retain LOCK; 1,024 integer/pointer/clobber/address-boundary
executions pass, including the generated base barrier. fixed-result.json
and the regression receipts retain these results. Raw fixed-alias/lock/bpf/
barrier-20261119T1050Z directories preserve commands and the tested source
diff, including earlier failed baselines in their original directories.

Actual BCC checked-corpus functional confirmation is next; installed bytes,
app stock acceptance and any runtime effect of this alias change are not
yet measured. The completed 1.007x freeze/LOCK timing predates this repair.
No duplicate timing or new benchmark gate is introduced. FORMAL's memory
observation and atomic refinement obligations remain explicit.

PERF 2026-11-19T11:08:16Z: Canonical BCC functional worker 344181 is terminal 0,
app ok, run x86_kvm_corpus_20261119_105515_135901. Its archived service
confirms programs/native/B-generated/B-stock 25/25/25/25, all checked,
zero fallback or failed requests. coverage.json retains the actual source
b77ae773c and complete outcomes. Installed native is 8,628 B versus JIT
7,965 B across 25 programs, the same byte count as the preceding cohort.
This 1 x 10 s run supplies functional coverage, not an official speed ratio
or proof of byte-for-byte code identity. P-x86-released-alias is complete;
full-application stock coverage and FORMAL's memory correspondence remain
open. All raw logs, failed baselines and source/test receipts are retained.
