# Step 0004 Report: Historical Throughput Recovery

Date: 2026-09-24
Phase: BUILD_AND_EVALUATE
Gates: EXPERIMENT complete; targeted WRITE complete; REVIEW complete

## Objective and instruction alignment

This step advances the independent speculative-optimization paper while OMP
uses the shared KVM for AE/KOperation work and another Codex owns kprog.  It
does not touch frozen workloads, runners, Makefiles, pass policy, KVM state, or
kprog/AE files.  It addresses the user's explicit requirement to verify the
experiment-093, single-pass Cilium, corrected Tracee/BCC, and Katran numbers
through commit history before writing them into the paper.

The repository predates the current orchestration layout and has no
`docs/user-instruction.md` or `docs/idea-story.md`; this step preserves that
legacy state rather than migrating concurrent research control files.  The
current user prompt, root `AGENTS.md`, paper README, `docs/implementation.md`,
and `docs/tmp/20260906-bpf-development-todo.md` were the authority inputs.

## EXPERIMENT gate

Selected question: the narrow throughput-evidence slice within paper RQ1.
`research-experiment-design` admitted consolidation of retained real KVM runs
before a redundant new run.  The reviewed plan, all review rounds, exact
commands, and scope decisions are in
[`experiment-001/plan.md`](experiment-001/plan.md) and
[`experiment-001/plan-review.md`](experiment-001/plan-review.md).

The new analysis-side tool
[`analysis/speculative_workload_history.py`](../../../../analysis/speculative_workload_history.py)
reads a declared Git revision, selects app artifacts deterministically, checks
the completed load-time lifecycle and exact policy, parses raw pktgen or
stress-ng output, reports invalid rows, maps each artifact to its introducing
commit, and computes the predeclared run-level bootstrap interval.  The
existing offline workload parser gained raw kernel-pktgen support.  No
aggregation entered framework or runner code.

Preflight and all six full invocations exited 0.  All 60 declared artifacts
were inspected and none was invalid.  Complete per-run totals and provenance
are in [`experiment-001/raw-results.md`](experiment-001/raw-results.md).
Independent review directly recomputed all 60 Git objects with zero mismatch;
its judgments are in
[`experiment-001/result-review.md`](experiment-001/result-review.md).

Accepted paper-facing results are the four independently collected 180-second
Cilium/Katran pktgen batches:

| App/policy | Geomean policy/baseline | 95% run-level interval | W/L |
| --- | ---: | ---: | ---: |
| Cilium `hot_region_version,map_inline` | 1.0517214715 | [1.0118063845, 1.0938097141] | 8/2 |
| Cilium `hot_region_version` | 1.0504250464 | [1.0311387601, 1.0710336116] | 10/0 |
| Cilium `map_inline` | 1.0666709764 | [1.0392809322, 1.0991746828] | 10/0 |
| Katran `map_inline` | 1.0911970593 | [1.0836097791, 1.0982745206] | 10/0 |

The Tracee (`1.0003915611`) and BCC (`1.0043429528`) historical summed-bogo-op
values were also reproduced, but their intervals cross one and heterogeneous
stressor bogo ops are not a reader-facing aggregate.  They remain internal
boundary evidence.  Cross-day Cilium batches are not compared causally.  The
historical artifacts lack per-step reports and runtime source revisions, so
the result is an observed baseline/policy phase difference rather than proof
of per-site engagement.

## Targeted WRITE gate

The speculative paper's RQ1 placeholder now contains a four-row result table,
raw interval provenance, run-level uncertainty, and the non-causal scope.  Its
README and the parent [`docs/evaluation.md`](../../../evaluation.md) now point
to the verified frontier.  No title, thesis, RQ meaning, mechanism claim, or
paper structure changed.

`git diff --check` and Python bytecode compilation pass.  A deliberate
pass-mismatch regression exits nonzero and prints the invalid row.  The local
offline extractor also returns both Cilium pktgen leaves through
`--tool kernel_pktgen`; this validation exposed and fixed its previous
top-level-only filter for composite workloads.  The local
environment has no `latexmk`, `pdflatex`, `xelatex`, `lualatex`, `tectonic`, or
`chktex`, so a current PDF build could not be executed; the exact failure is
`latexmk: command not found`, not a LaTeX source failure.

## REVIEW gate and routing

The independent result review classified the run as **valid**, the narrow
hypothesis as **supported**, research value as **supporting**, and paper impact
as **additional RQ1 evidence** rather than mechanism proof or RQ closure.  Its
wording corrections were applied.  Scientific contract and paper separation
from KOperation/kprog remain unchanged.

No new repository rule or skill is warranted: this step used an ordinary
analysis-side script and the existing raw-result contract.  Detailed history
stays in this step rather than expanding `AGENTS.md`.

The next highest-value speculative experiment is the pending Make-backed
Cilium run with `KEEP_WORKDIRS=1` after the shared KVM becomes free.  Its
decision value is to recover the missing per-step reports and bytecode for the
four affected tail-target signatures, then decide whether the composed policy
has mechanism evidence beyond the already verified phase-level throughput.
It remains in EXPERIMENT_GATE; this step does not claim RQ1 closure.
