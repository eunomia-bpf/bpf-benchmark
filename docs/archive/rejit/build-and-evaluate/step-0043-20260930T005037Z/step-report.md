# Step 0043 — KVM katran corpus run at `1207dbb06`

Date: 2026-09-30 UTC (run 00:41Z → 00:52:42Z; VM suite 00:46:30 → 00:51:12)

## Scope

First post-selftest corpus evidence on the KVM line:
`BPFREJIT_CORPUS_APPS=katran make corpus` — default `PLATFORM=kvm ARCH=x86`,
default policy (`SAMPLES=3`, `WORKLOAD_DURATION=30`), zero extra env vars.
HEAD `1207dbb06` (= `origin/master` after step 0042). make PID 317784,
`RUN_TOKEN=06e78ce0`. x86 image cached from the step 0041 build (dirty
`llvm_mapinline.hpp` source state, inherited).

## Verification

- Suite `status: completed`, `progress.json` `status: completed`,
  `suite_name: macro_apps`, `samples: 3`, `warmups: 1`, `workload_seconds:
  30.0`, `workload_only: False`, `skip_rejit: False`.
- katran `status: ok` (no `error`); rejit `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce, kop]`;
  selected workload `xdp_pktgen`.
- Raw two-start counters (`details/apps/katran.json`, raw only, no
  ratios):

  | start  | `balancer_ingres` id | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |--------|------|-----------------|---------------------|---------------|----------------|
  | baseline   | 9  | 219,971,021 | 38,647,805,320 | 13,641 | 23,840 |
  | post_rejit | 87 | 236,092,608 | 36,630,391,333 | 11,778 | 19,392 |

- Raw pktgen `pkts-sofar` / `errors` per workload (same file):
  baseline `23,985,728 / 25,997,023`, `24,776,575 / 27,529,992`,
  `5,606,892 / 5,997,366`; post_rejit `25,892,525 / 27,086,961`,
  `15,686,193 / 13,641,759`, `25,472,272 / 24,123,226`.
- VM powered down cleanly (`kvm: exiting hardware virtualization`,
  `reboot: Power down`); no make error markers in the 458-line retained
  log (image cached → short build stage).
- Tracked-file pattern identical to the 09-24 KVM runs: `metadata.json`,
  `details/result.json`, `details/progress.json`, `details/apps/katran.json`,
  `details/loadtime-reports/katran.jsonl` (`.gitignore` negations);
  `shim-logs/` and `loadtime-plans/` stay ignored.

## Evidence pointers

- `make-corpus.log` (this dir): retained 458-line host log.
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_004629_965759/` run dir.

## Caveats

- Single-app subset (`katran`); the 5 other corpus apps are out of scope
  for this increment.
- `run_cnt_delta`/`run_time_ns_delta` are raw per-start BPF program
  counters; no ratio, geomean, or rollup computed here — analysis per
  `docs/evaluation.md` §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from step 0041
  build. Paper-B speculative evidence stays blocked.

## Open

- `BPFREJIT_CORPUS_APPS=bcc,set make corpus` (previously `ok`).
- Additional `make micro` benches; `PLATFORM=aws ARCH=arm64` within caps if
  the local KVM line saturates.
