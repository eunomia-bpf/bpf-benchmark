# Step 0068: named `kinsn-6` KINSN-class pass-group KVM x86 `make corpus` full 6-app two-start benchmark

- **Command**: `make corpus BPFREJIT_BENCH_PASSES="kinsn-6"` (`PLATFORM=kvm
  ARCH=x86` defaults, `SAMPLES=3`, `WORKLOAD_DURATION=30`, `JOBS=8
  IMAGE_BUILD_JOBS=8`; all 6 apps). `kinsn-6` =
  `[cond_select, bulk_memory, rotate, extract, endian_fusion, prefetch]`
  from `corpus/config/benchmark_config.yaml` `policy.groups` — the
  KINSN-kfunc-lowering family (in-kernel KINSN modules), **not** the
  `map_inline` userspace pass.
- **Launched**: `2026-10-01T02:51:12Z` attempt 1, **detached from the
  start** (`setsid nohup`, `docs/tmp/build-and-evaluate/step-0068-20261001T025112Z/launch.sh`).
- **prev HEAD**: `830195d59` (step-0067 `br` commit; `origin/master`).
- **Purpose**: the first KVM step exercising a *KINSN-class* named group.
  Steps 0042–0066 were zero-knob default `full-x86` (which includes `kinsn`
  but as a single "all=force" pass, never the individual KINSN-family pass
  names); 0067 exercised the `br` bytecode-rewriting group. This re-derives
  the §6.2.1 KINSN rows at the current tree.

## Observed raw facts (completed)

- `metadata.json`: `status: completed`, `samples: 3`, `started_at:
  2026-10-01T02:56:02Z`, `completed_at: 2026-10-01T03:28:25Z` (~32 min),
  `config.enabled_passes: [cond_select, bulk_memory, rotate, extract,
  endian_fusion, prefetch]` (exact `kinsn-6` expansion).
- `details/result.json`: `status: ok`; `progress.json`: `completed`.
- 6/6 apps `status: ok` with `post_rejit` (progs b/p: bcc 25/25, cilium
  62/53, katran 1/1, otelcol 13/13, tetragon 287/287, tracee 151/151 —
  identical shapes to 0066/0067; cilium drops 9 loader-renamed/merged tc
  progs post).
- **KINSN module load `status: ok`** — all 15 expected in-kernel KINSN modules
  (`bpf_x86_alu`, `bpf_x86_bmi1`, `bpf_x86_bmi2_shift`, `bpf_x86_byteorder`,
  `bpf_x86_cmov`, `bpf_x86_imul`, `bpf_x86_lea`, `bpf_x86_mov`,
  `bpf_x86_movbe`, `bpf_x86_native_lab`, `bpf_x86_not`, `bpf_x86_popcnt`,
  `bpf_x86_prefetch`, `bpf_x86_rotate`, `bpf_x86_shd`) present in-VM
  (`result.json → kinsn_modules.module_load`).
- Clean VM teardown: `reboot: Power down` + `kvm: exiting hardware
  virtualization` final lines (t≈1983.7s); **zero `signal 15`/`Terminated`
  lines**; `CORPUS_EXIT=0`.

### Per-app KINSN-site application (from `details/loadtime-reports/*.jsonl`, KINSN-family steps)

| app | KINSN sites matched / applied | families engaged |
|---|---|---|
| bcc/set | 14 / 14 | bulk_memory, prefetch |
| cilium/agent | 1455 / 1455 | bulk_memory, endian_fusion, prefetch, cond_select, extract |
| katran | 50 / 50 | all six families |
| otelcol/profiling | 519 / 519 | cond_select, prefetch, endian_fusion, bulk_memory |
| tetragon/observer | 2416 / 2416 | prefetch, bulk_memory, cond_select |
| tracee/monitor | 7320 / 7320 | prefetch, bulk_memory, cond_select, endian_fusion |

Unlike 0067 `br` (0 sites — pure generic O3 relift), the KINSN-family passes
**genuinely lower kfunc sites** here, with all KINSN modules loaded in-VM.

### Sanctioned analysis (`analysis/corpus_analyze.py`)

- `--pair-by id` (default): **0 retained** (tree-generation property: the
  kernel reassigns `bpf_prog` ids per two-start; identical on the 0066 and
  0067 trees).
- `--pair-by name-type`: **72 retained**, per-program geomean **0.9802**
  (wins/losses/ties 39/33/0; CV 66.5%; ratio min/max/median
  0.1242 / 6.7169 / 0.9988). Per-app: cilium 0.9026 (2), tetragon
  0.9269 (20), katran 0.9676 (1), tracee 0.9920 (33), bcc 1.0334 (15),
  otelcol 1.0880 (1).
- **The analyzer's `applied` column is 0 on all apps in this tree
  generation** — a structural property, not an absence of KINSN sites: the
  analyzer reads KINSN-site counts from
  `result.json → results[].rejit_result.per_program[].passes[].bpfopt_summary`,
  but the current driver writes per-app payloads to
  `details/apps/*.json` with an *empty* `rejit_result.per_program` and an
  empty `result.json → results`. The real KINSN-site application is recorded
  only in `details/loadtime-reports/*.jsonl` (table above). This is the
  same `applied`-column-empty condition 0067 observed for `br`, but here it
  coexists with large non-zero KINSN-site application, so 0.9802 measures
  **real KINSN kfunc-lowering + phase variance**, not just relift.
- Comparison with §6.2.1: the "6-pass kinsn + prefetch" row's pooled
  `0.9009` (historical 2026-05-08 trees, `pair_by=id`, 147 retained) is the
  paper record and is not overwritten. The current-state 0.9802 (72
  retained, `name-type` pairing, no bpftrace in the 6-app corpus) is the
  same <1.0 direction on a different retained population; recorded here and
  in the log only, not directly comparable to the historical suite column.

### Determinism pairing (rep-prog baseline-side `run_cnt_delta`)

| app | kinsn-6 | br-0067 | 0066 (default) |
|---|---|---|---|
| bcc `sys_exit` | 554,267,524 | 556,505,633 | 553,208,188 |
| cilium `cil_from_contai` | 56,928,014 | 59,849,174 | 58,352,782 |
| katran `balancer_ingres` | 221,552,336 | 220,263,922 | 222,602,879 |
| otelcol `native_tracer_e` | 722,973 | 723,007 | 723,144 |
| tetragon `generic_tracepo` | 224,313,424 | 225,289,954 | 223,259,828 |
| tracee `trace_sys_exit` | 241,631,272 | 243,711,281 | 242,894,771 |

Sub-percent spread across all 3 trees despite the three different pass
chains (default `full-x86` / `br` / `kinsn-6`) — baseline counters remain
pass-independent, as expected. Raw triplets only.

## Validation

- 6/6 `post_rejit` present; all apps `ok`; KINSN module load `status: ok`,
  all 15 expected modules in-VM.
- KINSN-site application non-zero on every app (loadtime-reports JSONL).
- Clean power-down; zero reaping lines; `CORPUS_EXIT=0`;
  `metadata`/`result`/`progress` all `completed`/`ok`/`completed`.
- `enabled_passes` exactly matches the `kinsn-6` group definition.

## Disposition

- **Clean completed 0068** — the first KINSN-class named-group KVM x86
  two-start benchmark in the chain, re-deriving the §6.2.1 KINSN rows at the
  current tree. Confirms the individual KINSN-family pass names
  (`cond_select`/`bulk_memory`/`rotate`/`extract`/`endian_fusion`/
  `prefetch`) remain fully operational on all 6 apps at the current
  image/kernel, with KINSN modules loaded in-VM. Corrects the 0067 "out of
  scope" note for KINSN groups: AGENTS.md's "Current pass list" includes the
  kinsn-class, so these are in-scope framework pass space (distinct from the
  Kinsn-paper deliverable, which is out of scope for this framework's
  measurement).
- No framework/app/runner/Makefile change; no new gate/skip/validity logic;
  no ratio/geomean/rollup in framework code (analysis via
  `analysis/corpus_analyze.py` + loadtime-reports only).
- Trackable JSON subset committed per the 0066/0067 precedent: 6
  `details/apps/*.json` + 6 `details/loadtime-reports/*.jsonl` +
  `details/result.json` + `details/progress.json` + `metadata.json` +
  this report + research-log append. `shim-logs/` + `loadtime-plans/` stay
  gitignored (`corpus/.gitignore: results/*/details/*`); the step dir's
  `make-corpus-kinsn6.log`/`run-marker.txt` stay gitignored
  (`docs/tmp/**/*.log`, `docs/tmp/**/*.txt`); `launch.sh` untracked provenance.
