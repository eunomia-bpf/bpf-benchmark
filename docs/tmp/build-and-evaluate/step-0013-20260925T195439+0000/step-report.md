# BUILD_AND_EVALUATE Step 0013 Report

Date: 2026-09-25
Experiment: answer **per-pass throughput causality** — does a candidate pass's own effect survive the restart drift inherent in the two-start measurement protocol — from the tracked May 2026 matched batch
Result: supported as a controlled derivation; the pooled control-corrected geomean over six applications is 0.9751x, and per-app corrections move the raw ratios materially in both directions

## Source ownership and experiment selection

The whole retained-bytecode line (steps 0008-0012) establishes that a candidate
pass *rewrites* a program and that the rewrite reconciles with the reported
instruction counts. It says nothing about whether the rewrite changes the
measured outcome, and the paper's own boundary sentence named exactly that gap:
the fresh runs prove "the rewrite on retained bytecode rather than per-pass
throughput causality". Closing it needs two things a retained-bytecode run does
not provide — workload throughput in both phases, and a way to separate the
pass's effect from the drift between the baseline start and the optimized start.

Launching a new run is the obvious move, but the repository already tracks the
instrument: `corpus/results/x86_kvm_corpus_20260522_*`. For **all six**
applications it holds (a) one `map_inline`-only run, and (b) two no-pass runs
(`config.enabled_passes == []`, `rejit_result.mode == "loadtime"`,
`rejit_result.status == "skipped"`). All runs are single-application,
`suite: corpus`, `run_type: x86_kvm_corpus`, `samples: 3`, and
`workload_seconds: 60.0`. The two no-pass runs are the null: they pair an
optimized and a plain restart of the *same* application at the *identical*
duration, so the ratio between their two phases measures how much of a
raw post/baseline ratio is restart drift rather than pass effect. This is the
only tracked set carrying, for every application, both a single-pass arm and
same-batch nulls; it was chosen over a fresh run precisely because the
comparison only means something when the arm and the null share a batch,
duration, and workload shape.

Nothing frozen changed this step. No workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU/duration setting was touched, and no new run was launched —
the increment is derivation over already-tracked `corpus/results/**` JSON.

Three per-application metric shapes coexist in this batch and each needed
reading correctly: kernel-pktgen `Npps ... errors:` (Katran), wrk
`Requests/sec:` nested inside a `network_lossy_multi_wrk` component (Cilium),
and stress-ng `stress-ng: metrc:` bogo-ops on the workload's own stdout
(bcc/tetragon/tracee) or its single component (otelcol). The renderer's
existing `phase_pps` reads only the pktgen shape and returns 0 for the other
two, so a second, wider extractor (`workload_throughput`) was added rather than
changing `phase_pps` semantics that existing rows depend on.

## Valid result

For each application the derivation is: raw ratio = median(post_rejit
throughput) / median(baseline throughput) over the three samples in each phase;
control ratio = the same quantity for each no-pass run; control-corrected =
raw / median(the two control ratios). Values, reproduced exactly by both the
standalone prototype and the committed renderer:

| application | raw map_inline | controls | control median | control-corrected |
|---|---|---|---|---|
| bcc/set | 0.8318 | 0.9746, 1.1256 | 1.0501 | 0.7921 |
| otelcol | 0.9984 | 0.9958, 1.0044 | 1.0001 | 0.9983 |
| cilium | 0.8885 | 1.1046, 0.7492 | 0.9269 | 0.9585 |
| tetragon | 1.0408 | 1.0177, 0.9027 | 0.9602 | 1.0840 |
| katran | 1.0191 | 0.9726, 0.9976 | 0.9851 | 1.0345 |
| tracee | 0.9243 | 1.0185, 0.8094 | 0.9139 | 1.0114 |

Pooled control-corrected geomean over the six applications: **0.9751x**.

The controls are not idle: their own ratios spread as widely as the arms (e.g.
Cilium 0.7492 vs 1.1046; Tracee 0.8094 vs 1.0185), so the correction is
load-bearing rather than cosmetic — it moves bcc/set from 0.8318 to 0.7921 and
flips tracee (0.9243 raw, 1.0114 corrected) across parity. The result is
therefore that this batch does not resolve a single consistent small
per-application pass effect: the null is comparable in magnitude to the
signal, which is exactly why the control subtraction is required before any
causality statement.

The renderer emits seven new rows — six per-application plus one pooled — all
reading `PASS`. The row set moves from 55 to 62 data rows. The 55 pre-existing
row labels are byte-identical to the pre-edit dump, the five `PARTIAL` rows are
unchanged, and `OVERALL AE EVIDENCE` remains `INCOMPLETE`.

`PASS` is gated on frozen declared constants derived from this batch
(`MAP_INLINE_CAUSALITY_DECLARED`, `MAP_INLINE_CAUSALITY_POOLED = "0.9751"`). The
paper declares no single-pass causality constant, so there is no external
figure to compare against; the declared values are the batch's own, and any
drift degrades the row to `PARTIAL` rather than silently re-baselining. This
criterion is stated in the row provenance and in the guide.

The self-test fixture drives the identical derivation over synthetic matched
runs and mutates each gate in turn. Verified load-bearing: the `map_inline`
policy gate, the control no-pass gate, the `samples != 3` gate, the
`workload_seconds` gate, the `bpf_stats` gate, the `CAUSALITY_WORKLOAD_SECONDS`
constant, the wrk extraction branch, the per-application `controlled` append,
and the pooled-length guard. Each mutation makes the fixture fail; restoring it
returns `self-test: OK (11 evidence classes)`. A drifting post-phase flips the
row to `PARTIAL` (`0.900000x; no-pass controls`), not a silent re-baseline.

The packaging path was extended too, because the causality inputs live under
the excluded `corpus/results` tree: `package-atc26.sh` now stages the eighteen
May runs' `metadata.json`, `details/progress.json`, and the per-run app record,
lists representative entries in `required=(…)`, and enumerates the batch in
`README-ARTIFACT.md`. A clean-extraction smoke build — staging exactly the
files the packager stages into a scratch root and running the renderer against
it — reproduces all seven rows as `PASS`, proving the ZIP will contain
everything the rows read.

## Scientific boundary and next action

Latitude, stated plainly.

- This is a controlled derivation over a **tracked historical batch**, not a
  newly measured experiment, and the batch retains **no per-step bytecode**
  (`git ls-files` shows only `details/apps/*.json`, `details/progress.json`,
  `details/result.json`, `metadata.json`). No site counts are therefore claimed,
  and the causality rows carry none. The May-batch ratios are a separate
  generation from the paper's June ratios and are never merged with them.
- The controls differ **by application**, so the pooled 0.9751x is the geomean
  of six individually controlled ratios, not the sum of one independently
  measured effect. It is not a claim that `map_inline` is uniformly ~2.5%
  faster.
- `run_cnt_delta`-based BPF cost is recorded for context only
  (bcc/set 85.304 → 86.242 ns/run, katran 107.470 → 105.037, tetragon 541.908 →
  520.972, etc.); with the null of comparable size, none of these is asserted as
  a paper-grade speedup.
- These runs predate the recorded-`command` format (`metadata.command` and
  `source_revision` are `None`, as in the already-accepted May-era
  `CILIUM_RQ2` records), so no `receipt.json` is generated for them. That is a
  provenance caveat, not a validity gate.

With per-pass throughput causality now answered from the matched batch, the
next runnable question is a **fresh, provenance-complete causality run** that
also retains loadtime artifacts, so a single experiment carries both the
causality ratio and the applied-site count. It was not needed for this
increment (the batch already answers the question) and remains the natural
follow-up.

## Delivery

Two commits shipped and were pushed to `origin/master`.

- `4b7a99d13` — "Add controlled map_inline per-pass throughput-causality rows":
  the widened throughput extractor, the seven renderer rows with frozen
  declared constants, the mutation-tested self-test fixture, the
  `package-atc26.sh` staging/`required`/README additions, and additive AE-doc
  narrative plus the May-batch run-status table row.
- the step-0013 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
