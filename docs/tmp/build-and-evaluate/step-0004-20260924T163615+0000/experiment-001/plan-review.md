# Plan Review

## Round 1 — 2026-09-24T16:45:00+00:00

The fresh reviewer returned **blocking revisions required**.

Material findings:

- The proposed throughput audit is only supporting evidence within RQ1.  It
  cannot close RQ1's six-app mechanism and coverage question because the
  historical artifacts do not retain the referenced per-step reports.
- The plan needed concrete commands, a deterministic application/path filter,
  a preflight, a timeout, and an exact output location.
- Every declared artifact must be inspected and any invalid row reported;
  completion cannot depend on favorable data.
- The result classification rule and metric fields needed to be explicit.
- Summed heterogeneous stress-ng bogo ops reproduce the requested historical
  calculation but are not a suitable reader-facing aggregate.
- Artifact-introduction commits establish raw JSON provenance, not the runtime
  software, kernel, or application revision.
- The plan needed to explain why auditing these known batches was not
  cherry-picking or provenance-only activity.

Root disposition: accept all findings.  Revision 1 scopes the result to partial
RQ1 throughput evidence, names the user instruction as the closed source set,
adds executable commands and classifications, keeps Tracee/BCC out of the
paper, and separates artifact provenance from unavailable runtime revision
provenance.  The first analyzer invocation occurred while this review was
pending; it is treated as development validation and will be rerun only after
the revised plan passes follow-up review.

## Round 2 — 2026-09-24T16:51:00+00:00

The reviewer confirmed that the round-1 blockers were resolved, but retained
three blockers: no predeclared uncertainty calculation, causal wording without
per-site engagement evidence, and omission of the six literal full-run
commands.

Root disposition: accept all three.  Revision 2 adds a fixed 100,000-draw
run-level percentile bootstrap, narrows the result to throughput observed
between the baseline and declared load-time-policy phases, and records every
full invocation verbatim.  Bootstrap uncertainty is descriptive and does not
filter a raw result.  The paper will not claim per-site engagement from these
artifacts.

## Round 3 — 2026-09-24T16:56:00+00:00

Verdict: **approved for execution**.  The reviewer found the uncertainty,
non-causal scope, six exact commands, deterministic inputs, invalid-row
retention, and frozen-runner boundaries sufficient.  An official pktgen
citation was left as optional paper-stage bibliography work rather than an
execution blocker.
