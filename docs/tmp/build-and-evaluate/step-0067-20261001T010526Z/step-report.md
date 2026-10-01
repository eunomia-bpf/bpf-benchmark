# Step 0067: named `br` pass-group KVM x86 `make corpus` full 6-app two-start benchmark

- **Command**: `make corpus BPFREJIT_BENCH_PASSES="br"` (`PLATFORM=kvm ARCH=x86`
  defaults, `SAMPLES=3` default, `WORKLOAD_DURATION=30` default, `JOBS=8
  IMAGE_BUILD_JOBS=8` host-memory mitigation; all 6 apps; the `br` group =
  `[noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec]`
  from `corpus/config/benchmark_config.yaml` `policy.groups`).
- **Launched**: `2026-10-01T01:05:26Z` attempt 1, **detached from the start**
  (`setsid nohup … & < /dev/null`, `docs/tmp/build-and-evaluate/step-0067-20261001T010526Z/launch.sh`), so OMP's
  session-boundary reaper never owned the process tree. No reaping attempts
  (unlike 0066's attempts 1–3).
- **prev HEAD**: `6aa33210e` (docs: fill BR suite-geomean cell 0.8917; in
  lockstep with `origin/master`).
- **Purpose**: the first KVM step that selects a *named* pass group. Steps
  0042–0066 were all zero-knob default `full-x86` `make corpus`; no KVM step
  ever exercised a group token. This re-derives the `br` (all-bytecode-
  rewriting) conclusion at the current tree/image/kernel — the §6.2.1 row was
  just backfilled from the historical 2026-05-08 pool.
- **Result token**: `corpus/results/x86_kvm_corpus_20261001_011124_022384/`.

## Observed raw facts (completed)

- VM lifecycle: in-VM `7.0.0-rc2+`, hostname `virtme-ng`; `virtme-ng-init:
  Setting hostname` at t≈0.68s; `kvm: exiting hardware virtualization` at
  t≈2042.36s, `reboot: Power down` final line (log line 390/390) — ~34 min
  in-VM window. **Zero `signal 15`/`terminating`/`Terminated` lines** in the
  whole log (detached launch; single attempt).
- `metadata.json`: `status: completed`, `run_type: x86_kvm_corpus`,
  `samples: 3`, `started_at: 2026-10-01T01:11:24Z`, `completed_at:
  2026-10-01T01:44:44Z`, `config.enabled_passes:
  [noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec]`
  (confirms the `br` expansion).
- `details/result.json`: `status: ok`, `skip_rejit: false`.
- `details/progress.json`: `status: completed` (all three status files green).
- 6/6 apps `status: ok` with `post_rejit` present, `rejit_result.status: ok`
  / `mode: loadtime` — **including tetragon without any `VMLINUX_BTF`
  override**, matching the 0066 zero-override control (the KVM in-VM build
  uses the framework kernel BTF, not the host `7.3.0-070300rc3` BTF that
  lacks `mm_struct::user_ns`).
- `CORPUS_EXIT=0` captured (launch script appends the exit marker — the one
  gap 0066 noted is absent here).

### Per-app representative raw counters (br post vs. baseline; raw, no ratios — analysis per `docs/evaluation.md` §5)

| app | progs b/p | representative prog (name, post id) | post `run_cnt_delta` | baseline `run_cnt_delta` |
|---|---|---|---|---|
| bcc/set | 25/25 | `sys_exit` (id 577) | 554,379,884 | 556,505,633 |
| cilium/agent | 62/53 | `cil_from_contai` (id 2279) | 61,718,911 | 59,849,174 |
| katran | 1/1 | `balancer_ingres` (id 4922) | 223,299,819 | 220,263,922 |
| otelcol/profiling | 13/13 | `native_tracer_e` (id 821) | 723,356 | 723,007 |
| tetragon/observer | 287/287 | `generic_tracepo` (id 4158) | 210,606,521 | 225,289,954 |
| tracee/monitor | 151/151 | `trace_sys_exit` (id 5220) | 244,668,918 | 243,711,281 |

(cilium drops 9 programs post vs. baseline — the loader renamed/merged some
tc programs across the two starts; raw counts, no interpretation.)

### Determinism pairing vs. 0066 (same rep-prog, baseline-side `run_cnt_delta`)

| app | 0067 br baseline | 0066 default baseline |
|---|---|---|
| bcc/set `sys_exit` | 556,505,633 | 553,208,188 |
| cilium/agent `cil_from_contai` | 59,849,174 | 58,352,782 |
| katran `balancer_ingres` | 220,263,922 | 222,602,879 |
| otelcol `native_tracer_e` | 723,007 | 723,144 |
| tetragon `generic_tracepo` | 225,289,954 | 223,259,828 |
| tracee/monitor `trace_sys_exit` | 243,711,281 | 242,894,771 |

Sub-percent spread on all 6 despite the two trees running different pass
chains (default full-x86 vs. `br`) — baseline counters are pass-independent,
as expected. Raw triplets only.

### Sanctioned analysis (`analysis/corpus_analyze.py`; analysis only, no framework change)

- `--pair-by id` (tool default): **0 retained** — on the current two-start
  in-VM layout the kernel reassigns `bpf_prog` ids per start (baseline ids
  31–78 vs. post ids 385–677 in bcc), so id-keyed pairs never match. The
  0066 default-policy tree shows the identical 0-retained under `id`
  pairing, so this is a property of the current tree generation, not of
  this run.
- `--pair-by name-type`: **72 retained**, per-program geomean **0.9669**
  (wins/losses/ties 41/31/0; CV 62.3%; min/max/median ratio
  0.0949 / 6.2779 / 0.9968). Per-app: tetragon 0.8782 (20 progs),
  cilium 0.9205, otelcol 0.9735, katran 0.9848, tracee 1.0050, bcc
  1.0144.
- Comparison with the §6.2.1 `br` row's pooled `0.8917` (historical
  2026-05-08 trees, 148 retained, computed under `pair_by=id` on a tree
  generation where ids aligned): the 0.9669 current-state geomean is in the
  same <1.0 direction with a comparable spread, on a different retained
  population (72 vs 148; current corpus has no bpftrace, so the historical
  7-app suite column is not directly comparable to the current 6-app
  corpus). No doc cell is overwritten; the historical row and its pool
  remain as the paper record.

## Validation

- 6/6 `post_rejit` present; all apps `ok`; `rejit_result: ok` ×6 loadtime.
- Clean VM teardown (`reboot: Power down` final line; `kvm: exiting
  hardware virtualization` before it); zero reaping lines; `CORPUS_EXIT=0`.
- `metadata.json`/`result.json`/`progress.json` all `completed`/`ok`/
  `completed`.
- `enabled_passes` in metadata exactly matches the `br` group definition.

## Disposition

- **Clean completed 0067** — the first named-group KVM x86 two-start
  benchmark in the chain (`br` across all 6 apps at `6aa33210e`), valid
  benchmark evidence (not record-only). Confirms `br`'s 6 passes remain
  fully operational on all 6 apps at the current image/kernel, with no
  `VMLINUX_BTF` override needed in KVM.
- No framework/app/runner/Makefile change; no new gate/skip/validity
  logic; no ratio/geomean/rollup in framework code (analysis via
  `analysis/corpus_analyze.py` only).
- Trackable JSON subset committed per the 0066 precedent
  (`e9b1f735f`): 6 `details/apps/*.json` + 6
  `details/loadtime-reports/*.jsonl` + `details/result.json` +
  `details/progress.json` + `metadata.json` + this report + research-log
  append. `shim-logs/` + `loadtime-plans/` stay gitignored (rule
  `corpus/.gitignore: results/*/details/*`); the step dir's
  `make-corpus-br.log`/`run-marker.txt` stay gitignored (rules
  `docs/tmp/**/*.log`, `docs/tmp/**/*.txt`). `launch.sh` is on-disk
  provenance, untracked.
