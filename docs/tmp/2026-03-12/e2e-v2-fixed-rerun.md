# E2E v2 Fixed Rerun

Generated: 2026-03-12

## Run Notes

- Framework guest kernel: `7.0.0-rc2-ge52504a75c05-dirty` from `vendor/linux-framework/arch/x86/boot/bzImage`.
- Result JSONs:
  - `e2e/results/tracee-e2e-v2-fixed.json`
  - `e2e/results/tetragon-e2e-v2-fixed.json`
  - `e2e/results/bpftrace-e2e-v2-fixed.json`
- Tracee used the built-in VM wrapper:
  - `python3 e2e/run.py tracee --vm --kernel vendor/linux-framework/arch/x86/boot/bzImage ...`
- `e2e/run.py` still has no `--vm` path for `tetragon` or `bpftrace`, so those two were run inside the same framework-kernel guest via `vng --run ... --exec 'sudo -n python3 e2e/run.py <case> ...'`.
- The bpftrace rerun used `--skip-build`, because guest-side `make -C micro` tried to rebuild `spdlog`; existing host-built `micro/build/runner/micro_exec` and `scanner/build/bpf-jit-scanner` were reused.

## Top Line

Compared with the previous failed rerun in `docs/tmp/e2e-v2-policy-rerun.md`, config-mode v2 apply is now working for the programs that actually have v2 corpus policies:

- Previous rerun: `0` config-mode applies across all three cases, with measured post phases coming from blind fallback.
- This rerun: `16` configured programs, `16/16` config-mode applies, `0` blind applies.
- `bpftrace` now confirms the steady-state fix: no policy means stock/no-op rather than implicit blind `--all`.

| Case | Programs | Config hits | Stock fallbacks | Config applies | Blind applies | Live sites on configured programs | Kept/applied rules |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Tracee | `15` | `13` | `2` | `13/13` | `0` | `158` | `47` |
| Tetragon | `5` | `3` | `2` | `3/3` | `0` | `43` | `43` |
| bpftrace | `7` attached | `0` | `7` | `0` | `0` | `13` eligible sites across `3` scripts | `0` |

Across all three cases:

- attached / discovered programs: `27`
- configured by v2 policy files: `16`
- stock fallbacks: `11`
- config apply success rate: `16/16`
- blind apply count: `0`

## Policy / Remap Stats

The repaired corpus policies are family-driven v2 YAMLs (`default: apply`, optional `families:`, `sites: []`). Because there are no explicit per-site entries to rewrite, every `policy_remap` summary correctly reports:

- `explicit_sites=0`
- `remapped_sites=0`
- `dropped_sites=0`

That does not mean remap was skipped. The live scan still ran before apply, and `policy_remap.live_total_sites` records the live site census that config-mode filtered against.

### Tracee

- Live sites on configured programs: `158`
  - `cmov=111`
  - `branch-flip=42`
  - `extract=5`
- Kept/applied rules: `47`
  - `branch-flip=42`
  - `extract=5`
- Effective behavior: all `111` live `cmov` sites were filtered out, matching repaired policies such as `sys_enter_submit.policy.yaml` (`default: apply` + `families: { cmov: skip }`).

### Tetragon

- Live sites on configured programs: `43`
  - `cmov=15`
  - `branch-flip=28`
- Kept/applied rules: `43`
  - `cmov=15`
  - `branch-flip=28`
- Effective behavior: all live sites were kept for the three matched programs; those specific v2 policies did not carry a `cmov: skip` family override.

### bpftrace

- Attached programs: `7`
- Config hits: `0`
- Stock fallbacks: `7`
- Eligible site-positive programs: `3`
- Config applies: `0`
- Blind applies: `0`

This is the intended post-fix behavior for a no-policy case: the site-positive programs stayed stock and the harness did not fall back to `scanner apply --all`.

## Stock vs v2-policy-recompile

### Tracee

All `13` policy-hit programs applied successfully in config mode. The workload deltas were uniformly positive, and BPF avg ns improved on all three workloads.

| Workload | Stock app throughput | v2-policy throughput | App delta | Stock BPF avg ns | v2-policy BPF avg ns | BPF delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `exec_storm` | `167.04` | `189.75` | `+13.60%` | `61.86` | `60.62` | `-2.01%` |
| `file_io` | `872275.54` | `889503.47` | `+1.98%` | `30.71` | `30.39` | `-1.03%` |
| `network` | `4990.50` | `5062.17` | `+1.44%` | `41.58` | `41.47` | `-0.24%` |

### Tetragon

All `3` policy-hit programs applied successfully in config mode. The result is mixed: `stress_exec` improved substantially, `file_io` stayed flat, `open_storm` regressed slightly, and `connect_storm` regressed heavily.

| Workload | Stock app throughput | v2-policy throughput | App delta | Stock BPF avg ns | v2-policy BPF avg ns | BPF delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `stress_exec` | `920.14` | `1767.78` | `+92.12%` | `5774.48` | `4726.29` | `-18.15%` |
| `file_io` | `1137097.55` | `1137006.93` | `-0.01%` | `5731.62` | `5371.08` | `-6.29%` |
| `open_storm` | `217196.02` | `216664.49` | `-0.24%` | `3019.89` | `3551.00` | `+17.59%` |
| `connect_storm` | `1509.07` | `746.84` | `-50.51%` | `4428.43` | `4346.14` | `-1.86%` |

Arithmetic means across the four Tetragon workloads were nearly flat on application throughput (`339180.69 -> 339046.51`, `-0.04%`) and improved on BPF avg ns (`4738.60 -> 4498.63`, `-5.06%`).

### bpftrace

There is no valid stock-vs-v2-policy post phase for this rerun:

- `configured_programs=0`
- `eligible_programs=3`
- `applied_programs=0`
- `blind_applies=0`

So the output is intentionally a stock-only benchmark. The important semantic result is that `bpftrace` no longer silently turns a policy miss into blind all-apply.

## Takeaways

- The E2E drift fix is effective for repaired v2 policies: Tracee and Tetragon both reached successful config-mode apply on live VM programs.
- The repaired v2 policy shape is behaving as intended in E2E: Tracee filtered out live `cmov` sites while keeping `branch-flip` / `extract`; Tetragon kept all live sites for the matched policies.
- The steady-state semantics fix is also visible in E2E: `bpftrace` had `0/7` policy hits and `0` blind applies, so misses now stay stock.
- The remaining E2E gap is artifact coverage, not drift wiring: `bpftrace` still lacks corpus policy/object artifacts, so it cannot exercise config-mode v2 apply yet.
