# BUILD_AND_EVALUATE Step 0007 Report

Date: 2026-09-25
Experiment: attribute current Cilium `map_inline` report entries
Result: valid supporting evidence; rewrite/causal claim remains open

## Source ownership and experiment selection

The uncommitted three-line change in
`bpfopt/llvm/src/llvm_mapinline.hpp` was traced to the AE supervisor's
September 22 session.  The current x86 runtime image copied a `bpfopt` built
after that edit.  No KVM experiment was started, so this step did not mix the
other owner's optimizer WIP into a speculative artifact or contend with the AE
or kprog sessions.

An initial proposal to treat two Katran reports as observed map-state stability
was rejected before implementation.  Katran's values and `phase-stable` label
come from fixed overlay/hint policy, the proposed artifacts were not the full
eligible population, and report key/value counts lack site identity.  The
rejection is retained in `experiment-001/plan-review.md` so the configured
overlay is not later promoted as observed stability.

## Valid result

`analysis/audit_map_inline_snapshots.py` performs a fail-fast, read-only join
from each Cilium `map_inline` report entry to its workdir-local map metadata and
snapshot dump.  A one-workdir real-path preflight and the complete artifact run
both completed.  The full run found 169 report rows, 47 zero-applied rows, 122
changed load instances, and 3,787 applied-entry occurrences.  Every entry
joined to the sole metadata class: frozen `.rodata.config` array, flags 1152.

An independent reviewer reproduced the row, entry, workdir, map-class, and dump
key totals directly from the raw artifact and accepted the narrow result.  The
formal output and review are in `experiment-002/`.

## Scientific boundary and next action

This is opportunity-source attribution, not a repaired rewrite result.  The
old artifact still has zero retained outputs and overwritten before images, so
it cannot prove bytecode rewriting or throughput causality.  It does establish
that, in this one startup, all optimizer-reported Cilium sites referenced
workdir-local metadata for a frozen `.rodata.config` array rather than
mutable-map metadata.

The paper receives only that scoped RQ2 observation.  The next causal step is
a clean Make-backed single-pass run with `KEEP_WORKDIRS=1`; Katran remains a
strong target because its historical throughput effect is largest.  While the
AE-owned optimizer source prevents that run, the research loop returns to the
next runnable RQ1 mechanism question: map the Cilium reports to directly
attached callers and tail-call descendants so reported sites are attributed to
the program whose runtime counters include their cost.
