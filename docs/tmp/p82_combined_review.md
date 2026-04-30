# P82 Combined Cleanup Review

Review base: `8e99747d` (P78 pushed main).

Review head before this document: `436ea7b9`.

Scope: delete the remaining P81 strict-review surfaces requested by P82, commit and push each stage independently, do not refactor runner Python, do not run KVM/AWS.

## Stage Summary

| Stage | Commit | Change | Verification |
| --- | --- | --- | --- |
| 1 | `1bb76903` | Deleted daemon `optimize-all`, removed `OptimizeAllOrderEntry`, rayon, `--jobs`, README example, and related tests. Confirmed runner sends only `cmd: "optimize"`. | daemon build, clippy, test |
| 2 | `08afeb92` | Deleted daemon `profile-save` / `profile-load` and `status.available_passes_help` shell-out. Kept `profile-start` / `profile-stop`. | daemon build, clippy, test |
| 3 | `97492de3` | Deleted `bpfrejit --dry-run` and tests; docs now point dry-run verification users to `bpfverify`. | `bpfrejit` build, clippy, test; daemon build, clippy, test |
| 4 | `16c9134c` | No live `bpfprof --show` code remained; removed the stale design-doc `--show` example. | `bpfprof` build, clippy, test |
| 5 | `2cdad6f0` | Made `bpfget --list` JSON-only by rejecting `--list` without `--json`; removed text output path and updated tests/docs. | `bpfget` build, clippy, test |
| 6 | `f8800f45` | Deleted public `bpfopt scan-map-keys`; moved live map-key scanning into daemon internals through `kernel-sys` / libbpf. | full bpfopt workspace build, clippy, test; daemon build, clippy, test |
| 7 | `436ea7b9` | Deleted unused `passes.performance` and unused benchmark `profiles` from `corpus/config/benchmark_config.yaml`. Runner Python was not changed. | config load smoke test and `git diff --check` |
| 8 | this commit | Added this review and fixed stale plan wording that still mentioned `optimize-all`. | doc-only diff check |

## LOC Delta

Commit-level deltas before this review document:

| Stage | Insertions | Deletions | Net | Cumulative |
| --- | ---: | ---: | ---: | ---: |
| 1 | 8 | 300 | -292 | -292 |
| 2 | 2 | 218 | -216 | -508 |
| 3 | 5 | 141 | -136 | -644 |
| 4 | 1 | 4 | -3 | -647 |
| 5 | 13 | 36 | -23 | -670 |
| 6 | 125 | 324 | -199 | -869 |
| 7 | 0 | 38 | -38 | -907 |

Aggregate before Stage 8 doc: 17 files changed, 154 insertions, 1061 deletions, net -907.

Final aggregate after Stage 8 doc: 18 files changed, 229 insertions, 1062 deletions, net -833.

The P82 requirement was net <= -600 LOC. Final result is -833 LOC, so the requirement is met.

## P81 Priority Status

Done in P82:

- Public `bpfopt scan-map-keys` was deleted and replaced with daemon-internal map-key discovery.
- Daemon socket protocol was slimmed by removing `optimize-all`, profile save/load, and status list-passes capability probing.
- `bpfrejit --dry-run` was deleted.
- `bpfget --list` text mode was deleted.
- Benchmark config duplicate pass list and unused profiles were deleted without touching runner Python.

Already done before P82, from the P78 work this task builds on:

- `disabled_passes` surfaces were deleted end to end.
- The `branch_flip` heuristic fallback and per-pass verify script surface were removed.
- Dead public optimizer APIs and stale `bpfopt analyze` handling were cleaned up.

Not done in P82:

- `bpfprof` PMU / per-insn placeholder fields were not pruned. That is adjacent to Stage 4, but Stage 4 only targeted the `--show` table surface; changing profile schema needs a separate compatibility review.
- Daemon optimize requests were not changed to require `enabled_passes`. Runner already sends the pass list, but making it mandatory is a protocol behavior change outside the eight requested stages.
- Remaining pass-manager complexity, map-inline module splitting, duplicate response/debug fields, and `bpfget --info` were not removed. They are P81 candidates, not part of this P82 stage list, and need separate risk review.
- Runner config loader support for `profiles` and `policy.rules` remains because runner Python was explicitly frozen. P82 only deleted YAML fields that are not consumed by the current runner path.

## Final Checklist

- Eight commits were created in order, and stages 1 through 7 were pushed immediately after verification.
- Stage 8 is documentation only plus one stale active-doc wording fix.
- No `runner/libs/`, `e2e/cases/`, `micro/driver.py`, `vendor/linux-framework`, or `module/` files were edited.
- The only corpus change is `corpus/config/benchmark_config.yaml`.
- No benchmark app loader behavior, ReJIT filtering, app-status filtering, or pass exclusions were added.
- New map-key scanning stays behind daemon/kernel-facing code and uses `kernel-sys` as the syscall boundary.
- No CLI crate dependency on another CLI crate was added.
- KVM and AWS validation were intentionally not run, per P82 constraints.
