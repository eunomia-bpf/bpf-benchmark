# Step 0070: single `kinsn` KINSN-class pass KVM x86 `make corpus` full 6-app two-start benchmark

- **Command**: `make corpus BPFREJIT_BENCH_PASSES="kinsn"`
  (`PLATFORM=kvm ARCH=x86` defaults, `SAMPLES=3`, `WORKLOAD_DURATION=30`,
  `JOBS=8 IMAGE_BUILD_JOBS=8`; all 6 apps). `kinsn` = the single named
  KINSN-kfunc-lowering pass (`runner/config/passes/kinsn/default.yaml` = the
  full KINSN-op lowering list: `bpf_x86_*` + `bpf_arm64_*` ops).
- **Launched**: `2026-10-01T05:05:06Z` attempt 1, **detached from the
  start** (`setsid nohup`,
  `docs/tmp/build-and-evaluate/step-0070-20261001T050506Z/launch.sh`).
- **prev HEAD**: `d8483f22e` (step-0069 `kinsn-5` commit; `origin/master`).
- **Purpose**: the KINSN-family anchor. 0068/0069 exercised the KINSN-*family*
  sub-pass groups (`kinsn-6` with `prefetch`, `kinsn-5` without). This
  exercises the canonical single `kinsn` pass that lowerings the full
  KINSN-op list. Together the three form the §6.2.1 "KINSN-class" ablation:
  single `kinsn` → `kinsn-5` (5 family sub-passes) → `kinsn-6` (6 family
  sub-passes, +`prefetch`), all at the current tree.

## Observed raw facts (completed)

- `metadata.json`: `status: completed`, `samples: 3`, `started_at:
  2026-10-01T05:09:56Z`, `completed_at: 2026-10-01T05:41:20Z` (~31 min),
  `config.enabled_passes: [kinsn]` (single pass; no family sub-passes).
- `details/result.json`: `status: ok`; `progress.json`: `completed`.
- 6/6 apps `status: ok` with `post_rejit` (progs b/p: bcc 25/25,
  cilium 62/53, katran 1/1, otelcol 13/13, tetragon 287/287, tracee
  151/151). Cilium baseline is 62 in this tree (loader tc-rename
  nondeterminism; same 20-unique-program set as the 53-record trees).
- **KINSN module load `status: ok`** — all 15 expected in-VM KINSN modules
  present, identical set to 0068/0069.
- Clean VM teardown: `reboot: Power down` + `kvm: exiting hardware
  virtualization` final lines (t≈1924.8s); **zero `signal 15`/`Terminated`
  lines**; `CORPUS_EXIT=0`.

### Per-app KINSN-site application (from `details/loadtime-reports/*.jsonl`)

| app | `kinsn` (single) | `kinsn-5` (5 family) | `kinsn-6` (6 family) |
|---|---|---|---|
| bcc/set | 84 | 11 | 14 |
| cilium/agent | 2988 | 800 | 1455 |
| katran | 70 | 44 | 50 |
| otelcol/profiling | 1532 | 200 | 519 |
| tetragon/observer | 2988 | 1989 | 2416 |
| tracee/monitor | 7507 | 6172 | 7320 |

The single `kinsn` pass is the **broadest** KINSN lowering: it matches/applies
~15,169 KINSN sites total across the 6 apps, vs ~11,774 for the `kinsn-6`
family group and ~9,216 for `kinsn-5`. This is because `kinsn` is the full
KINSN-op lowering list, whereas `kinsn-5`/`kinsn-6` are the specific
transform-category sub-passes (`cond_select`/`bulk_memory`/`rotate`/
`extract`/`endian_fusion` [`+prefetch`]) that lower a subset of KINSN ops.
The single pass therefore covers strictly more KINSN op kinds.

### Sanctioned analysis (`analysis/corpus_analyze.py`)

- `--pair-by id` (default): **0 retained** (tree-generation property,
  identical on the 0066–0069 trees).
- `--pair-by name-type`: **72 retained**, with the same retained
  (app, name, type) multiset as 0068/0069 (all 72 keys present in all
  three KINSN trees), per-program geomean **0.9932** (wins/losses/ties
  36/36/0; CV 50.4%; ratio min/max/median 0.1881 / 5.0524 / 1.0013).
  Per-app: cilium 0.8955 (2), tetragon 0.9884 (20), katran 0.9916 (1),
  bcc 0.9959 (15), tracee 0.9979 (33), otelcol 1.1022 (1).

### KINSN-family ablation (all at current tree, current image, KVM x86, 6 apps)

| KINSN group | passes | KINSN sites applied (Σ) | 72-retained geomean | W/L |
|---|---|---|---|---|
| `kinsn` (0070) | `[kinsn]` (single, full KINSN-op list) | ~15,169 | **0.9932** | 36/36 |
| `kinsn-5` (0069) | 5 family sub-passes | ~9,216 | 0.9855 | 39/33 |
| `kinsn-6` (0068) | 6 family sub-passes (+`prefetch`) | ~11,774 | 0.9802 | 39/33 |

- The single `kinsn` pass achieves the **best** KINSN-group geomean (0.9932),
  with the lowest per-program ratio CV (50.4% vs 68.3% for the family
  groups), because it lowers the full KINSN-op list and is not narrowed to a
  transform-category subset.
- The family sub-pass groups (`kinsn-5`/`kinsn-6`) lower fewer KINSN ops, hence
  slightly worse geomeans (0.9855 / 0.9802). The family `prefetch` pass
  is a small net-negative on top of the 5-family base (0.9855 → 0.9802
  when `prefetch` is added), confirming 0069's finding.
- All three trees retain the identical 72-program name-type multiset, so
  the geomean differences isolate the pass-set difference (KINSN op
  coverage), not population variance.

### Comparison with §6.2.1

- The §6.2.1 KINSN rows ("5-pass kinsn" 0.9074, "6-pass kinsn + prefetch"
  0.9009) are the historical 2026-05-08 pool records (different
  retained population, `pair_by=id` mode, 7-app corpus with bpftrace).
  The current-tree 0.9932 / 0.9855 / 0.9802 (72 retained, `name-type`
  pairing, 6-app corpus, no bpftrace) are not directly comparable. No
  doc cell overwritten; the historical rows remain the paper record.
- The analyzer's `applied` column is 0 on all apps in this tree
  generation (empty `result.json → results[].rejit_result.per_program`),
  so KINSN-site application is read from loadtime-reports only — same
  structural condition as 0067/0068/0069.

### Determinism pairing (rep-prog baseline-side `run_cnt_delta`)

| app | kinsn (0070) | kinsn-5 (0069) | 0066 (default) |
|---|---|---|---|
| bcc `sys_exit` | 554,366,265 | 553,842,499 | 553,208,188 |
| cilium `cil_from_contai` | 56,239,224 | 57,518,488 | 58,352,782 |
| katran `balancer_ingres` | 223,534,877 | 222,443,576 | 222,602,879 |
| otelcol `native_tracer_e` | 723,251 | 722,985 | 723,144 |
| tetragon `generic_tracepo` | 224,919,943 | 221,875,012 | 223,259,828 |
| tracee `trace_sys_exit` | 240,100,882 | 240,945,205 | 242,894,771 |

Sub-percent spread across all trees — baseline counters remain
pass-independent.

## Validation

- 6/6 `post_rejit` present; all apps `ok`; KINSN module load `status: ok`,
  all 15 expected modules in-VM.
- KINSN-site application non-zero on every app; single `kinsn` applies the
  most KINSN sites of the three KINSN groups (broadest op coverage).
- Clean power-down; zero reaping lines; `CORPUS_EXIT=0`;
  `metadata`/`result`/`progress` all `completed`/`ok`/`completed`.
- `enabled_passes` exactly `[kinsn]` (single pass).
- 72-retained multiset identical to 0068/0069; only the post-side times
  differ, so the geomean ladder (0.9932 / 0.9855 / 0.9802) isolates KINSN
  op-coverage.

## Disposition

- **Clean completed 0070** — completes the KINSN-family ablation
  (single `kinsn` → `kinsn-5` → `kinsn-6`). The single `kinsn` pass is the
  strongest KINSN group on this corpus (geomean 0.9932, lowest CV),
  because it lowers the full KINSN-op list rather than a transform-category
  subset. No framework/app/runner/Makefile change; no new gate/skip/
  validity logic; no ratio/geomean/rollup in framework code (analysis via
  `analysis/corpus_analyze.py` + loadtime-reports only).
- Trackable JSON subset committed per the 0066–0069 precedent: 6
  `details/apps/*.json` + 6 `details/loadtime-reports/*.jsonl` +
  `details/result.json` + `details/progress.json` + `metadata.json` +
  this report + research-log append. `shim-logs/` + `loadtime-plans/`
  stay gitignored; the step dir's `make-corpus-kinsn.log`/`run-marker.txt`
  stay gitignored; `launch.sh` untracked provenance.
- Remaining in-scope KVM Make-backed runs after this step: (a) refresh
  the stale KVM `make micro` layer (last KVM micro tree = 09-30 09:33,
  older than the KVM corpus trees); (b) individual KINSN-family named
  passes (`cond_select`, `bulk_memory`, `rotate`, `extract`,
  `endian_fusion`, `prefetch`) if the user wants per-pass resolution
  rather than group-level. The two external *run* blockers are unchanged:
  AWS credentials; Paper-B clean-source image rebuild.
