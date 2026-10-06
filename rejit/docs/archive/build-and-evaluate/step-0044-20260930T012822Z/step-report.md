# Step 0044 — KVM bcc/set corpus run at `897291237`

Date: 2026-09-30 UTC (attempt 1 01:26Z; attempt 2 01:35Z → 01:46:41Z;
VM suite 01:39:38 → 01:46:15)

## Scope

Second post-selftest corpus increment on the KVM line:
`BPFREJIT_CORPUS_APPS="bcc/set" make corpus` — default
`PLATFORM=kvm ARCH=x86`, default policy (`SAMPLES=3`,
`WORKLOAD_DURATION=30`), zero extra env vars. HEAD `897291237`
(= `origin/master` after step 0043). x86 image cached from the step 0041
build.

## Attempt 1 — `bcc,set` typo (failed fast, recorded)

`BPFREJIT_CORPUS_APPS="bcc,set" make corpus` (make PID 334899,
RUN_TOKEN `b273c81c`) failed at the driver's fail-fast check before any VM
suite work: `BPFREJIT_CORPUS_APPS references unknown apps: ['bcc', 'set'];
available: ['bcc/set', 'cilium/agent', 'katran', otelcol-ebpf-profiler/
profiling, 'tetragon/observer', 'tracee/monitor']`. No run dir created; VM
powered down cleanly; `make: *** [Makefile:276: corpus-kvm-x86] Error 2`.
Failure preserved verbatim in `make-corpus-failed-attempt1.log` and
noted in `run-marker.txt` — recorded, not hidden. The app key is the
single `app/tool` entry `bcc/set`; the comma-separated list `bcc,set`
split it into two unknown names. This is a mechanical invocation typo,
not a suite failure; no diagnosis of the suite needed for the retry.

## Attempt 2 — `bcc/set` (success)

- Run `corpus/results/x86_kvm_corpus_20260930_013937_924928/`
  `status: completed`, `suite_name: macro_apps`, `samples: 3`,
  `workload_seconds: 30.0`, `workload_only: False`; VM powered down
  cleanly; no make error markers in the 478-line retained log.
- `bcc/set` `status: ok` (no `error`); rejit `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce, kop]`;
  selected workload `stress_ng_bcc_hook_hot` (3 stress-ng samples, all
  `returncode: 0`; raw per-run metric lines: `stress-ng: metrc: [pid]
  stressor bogo ops real time usr time sys time bogo ops/s ...`, no
  scalar counters).
- Raw two-start BPF counters (`details/apps/bcc__set.json`, raw only, no
  ratios):

  | start  | prog       | id  | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |--------|------------|-----|-----------------|---------------------|---------------|----------------|
  | baseline   | `sys_enter` | 75  | 541,768,543 | 44,316,208,484 | 108 | 168 |
  | baseline   | `sys_exit`  | 77  | 541,768,554 | 47,526,478,291 | 406 | 656 |
  | post_rejit | `sys_enter` | 718 | 546,561,845 | 44,314,841,636 | 69  | 112 |
  | post_rejit | `sys_exit`  | 908 | 546,561,851 | 47,147,870,673 | 262 | 408 |

- Prior-run anchor (Sep-15 tracked run `x86_kvm_corpus_20260915_223707_648561`):
  `sys_enter` `run_cnt_delta 61,011,788` / `run_time_ns_delta 5,105,141,555`;
  `sys_exit` `61,011,792` / `5,299,360,726` — different stress-ng duration,
  so this is an anchor, not a comparison (analysis per
  `rejit/docs/evaluation.md` §5).

## Evidence pointers

- `make-corpus.log` (this dir): retained 478-line host log (attempt 2).
- `make-corpus-failed-attempt1.log` (this dir): failed typo attempt.
- `run-marker.txt` (this dir): attempt-1 failure note + retry.
- `corpus/results/x86_kvm_corpus_20260930_013937_924928/` run dir.

## Caveats

- Single-app subset (`bcc/set`); the 5 other corpus apps are out of scope
  for this increment.
- Raw BPF program counters only; no ratio, geomean, or rollup computed —
  analysis per `rejit/docs/evaluation.md` §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from step 0041
  build. Paper-B speculative evidence stays blocked.

## Open

- Additional `make micro` benches; `PLATFORM=aws ARCH=arm64` within caps if
  the local KVM line saturates.
