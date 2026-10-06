# Step 0069: named `kinsn-5` KINSN-class pass-group KVM x86 `make corpus` full 6-app two-start benchmark

- **Command**: `make corpus BPFREJIT_BENCH_PASSES="kinsn-5"`
  (`PLATFORM=kvm ARCH=x86` defaults, `SAMPLES=3`, `WORKLOAD_DURATION=30`,
  `JOBS=8 IMAGE_BUILD_JOBS=8`; all 6 apps). `kinsn-5` =
  `[cond_select, bulk_memory, rotate, extract, endian_fusion]`
  from `corpus/config/benchmark_config.yaml` `policy.groups` — the
  KINSN-kfunc-lowering family **minus `prefetch`**.
- **Launched**: `2026-10-01T04:01:52Z` attempt 1, **detached from the
  start** (`setsid nohup`,
  `docs/tmp/build-and-evaluate/step-0069-20261001T040152Z/launch.sh`).
- **prev HEAD**: `c0da1d785` (step-0068 `kinsn-6` commit; `origin/master`).
- **Purpose**: the KINSN-group ablation follow-on. Step 0068 exercised
  `kinsn-6` (KINSN family **with** `prefetch`); this isolates the effect of
  `prefetch` by dropping it. Together the two rows re-derive the §6.2.1
  KINSN rows at the current tree on a KINSN-group-identity basis.

## Observed raw facts (completed)

- `metadata.json`: `status: completed`, `samples: 3`, `started_at:
  2026-10-01T04:06:43Z`, `completed_at: 2026-10-01T04:38:58Z` (~32 min),
  `config.enabled_passes: [cond_select, bulk_memory, rotate, extract,
  endian_fusion]` (exact `kinsn-5` expansion; `prefetch` absent).
- `details/result.json`: `status: ok`; `progress.json`: `completed`.
- 6/6 apps `status: ok` with `post_rejit` (progs b/p: bcc 25/25,
  cilium 53/53, katran 1/1, otelcol 13/13, tetragon 287/287, tracee
  151/151). The cilium baseline count moved 53 (this tree) vs 62 (0068
  `kinsn-6`) — cilium loader tc-rename nondeterminism (same baseline/post
  pair in both trees, 20 unique programs each).
- **KINSN module load `status: ok`** — all 15 expected in-VM KINSN modules
  present (`result.json → kinsn_modules.module_load`), identical set to 0068.
- Clean VM teardown: `reboot: Power down` + `kvm: exiting hardware
  virtualization` final lines (t≈1976.9s); **zero `signal 15`/`Terminated`
  lines**; `CORPUS_EXIT=0`.

### Per-app KINSN-site application (from `details/loadtime-reports/*.jsonl`, KINSN-family steps)

| app | `kinsn-5` matched | `kinsn-6` matched | delta = prefetch |
|---|---|---|---|
| bcc/set | 11 | 14 | 3 |
| cilium/agent | 800 | 1455 | 655 |
| katran | 44 | 50 | 6 |
| otelcol/profiling | 200 | 519 | 319 |
| tetragon/observer | 1989 | 2416 | 427 |
| tracee/monitor | 6172 | 7320 | 1148 |

`kinsn-5` ≤ `kinsn-6` on every app, with the delta equal to `prefetch`'s
contribution. KINSN-site application is non-zero on every app.

### Sanctioned analysis (`analysis/corpus_analyze.py`)

- `--pair-by id` (default): **0 retained** (tree-generation property,
  identical on the 0066/0067/0068 trees).
- `--pair-by name-type`: **72 retained**, with the retained
  (app, name, type) multiset **identical** to 0068 `kinsn-6` (all 72 keys
  present in both), per-program geomean **0.9855**
  (wins/losses/ties 39/33/0; CV 68.3%; ratio min/max/median
  0.1260 / 6.6906 / 0.9980). Per-app: cilium 0.9061 (2), tetragon
  0.9212 (20), katran 0.9749 (1), tracee 1.0056 (33), bcc 1.0352 (15),
  otelcol 1.1155 (1).
- **Ablation delta** `kinsn-6` − `kinsn-5` = `0.9802 − 0.9855 = −0.0053`:
  removing `prefetch` slightly **worsens** the geomean, so `prefetch` is
  a small net-positive contributor to the KINSN pass-group on this corpus.
  The per-app ordering is stable: `cilium < tetragon < katran` on both
  rows; `tracee`/`bcc`/`otelcol` straddle 1.0 on both rows with the
  same direction (slight loss).
- The analyzer's `applied` column is 0 on all apps in this tree
  generation (its source `result.json → results[].rejit_result.
  per_program` is empty; the current driver writes per-app payloads to
  `details/apps/*.json` with an empty `rejit_result.per_program`), so
  KINSN-site application is only visible via the loadtime-reports JSONL.
  Same structural condition as 0067/0068.
- Comparison with §6.2.1: the "5-pass kinsn" pooled `0.9074` row is the
  historical 2026-05-08 record; the "6-pass kinsn + prefetch" pooled
  `0.9009` row is the historical 2026-05-08 record. The current-state
  0.9855 / 0.9802 (72 retained, `name-type` pairing, 6-app corpus, no
  bpftrace) are not directly comparable (different retained population,
  different pairing mode). No doc cell overwritten; the historical rows
  remain the paper record.

### Determinism pairing (rep-prog baseline-side `run_cnt_delta`)

| app | kinsn-5 | kinsn-6 | 0066 (default) |
|---|---|---|---|
| bcc `sys_exit` | 553,842,499 | 554,267,524 | 553,208,188 |
| cilium `cil_from_contai` | 57,518,488 | 56,928,014 | 58,352,782 |
| katran `balancer_ingres` | 222,443,576 | 221,552,336 | 222,602,879 |
| otelcol `native_tracer_e` | 722,985 | 722,973 | 723,144 |
| tetragon `generic_tracepo` | 221,875,012 | 224,313,424 | 223,259,828 |
| tracee `trace_sys_exit` | 240,945,205 | 241,631,272 | 242,894,771 |

Sub-percent spread across all 4 trees (0066 default `full-x86` / 0068
`kinsn-6` / 0069 `kinsn-5` / plus 0067 `br` for the 6-app corpus) — baseline
counters remain pass-independent, as expected.

## Validation

- 6/6 `post_rejit` present; all apps `ok`; KINSN module load `status: ok`,
  all 15 expected modules in-VM.
- KINSN-site application non-zero on every app (loadtime-reports JSONL).
- Clean power-down; zero reaping lines; `CORPUS_EXIT=0`;
  `metadata`/`result`/`progress` all `completed`/`ok`/`completed`.
- `enabled_passes` exactly matches the `kinsn-5` group definition
  (no `prefetch`).
- `kinsn-5` retained set is identical to `kinsn-6` (same 72
  name-type keys); only the post-side times differ, so the geomean
  delta (−0.0053) isolates `prefetch`'s effect.

## Disposition

- **Clean completed 0069** — the KINSN-group ablation follow-on. Confirms
  the KINSN-class pass-group family is fully operational on the current
  KVM x86 image; `prefetch` is a small net-positive contributor to the
  KINSN-group geomean on this corpus (adding it moves 0.9855 → 0.9802).
- No framework/app/runner/Makefile change; no new gate/skip/validity
  logic; no ratio/geomean/rollup in framework code (analysis via
  `analysis/corpus_analyze.py` + loadtime-reports only).
- Trackable JSON subset committed per the 0066/0067/0068 precedent: 6
  `details/apps/*.json` + 6 `details/loadtime-reports/*.jsonl` +
  `details/result.json` + `details/progress.json` + `metadata.json` +
  this report + research-log append. `shim-logs/` + `loadtime-plans/`
  stay gitignored; the step dir's `make-corpus-kinsn5.log`/`run-marker.txt`
  stay gitignored; `launch.sh` untracked provenance.
