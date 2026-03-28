# E2E Full VM Run Results - 2026-03-28

## Run Summary

- Commands executed:
  - `make daemon`
  - `make runner`
  - `make vm-e2e TARGET=x86`
- No `sudo` was used.
- No manual BPF loading was performed.
- No kernel code was modified.
- No userspace code changes were required for this run.
- Console log: `docs/tmp/20260328/vm_e2e_full_run_console_20260328.log`
- VM session start: `2026-03-28 07:22:00 -0700`
- VM session end: `2026-03-28 07:52:43 -0700`
- Wall clock duration: `30m43s`
- kinsn modules loaded in VM: `6/6`
- Harness result from `make vm-e2e TARGET=x86`: `e2e: ALL PASSED`

Status in this report means harness completion status for each case. Data validity is called out separately because several PASS cases completed but did not produce a full stock-vs-ReJIT comparison.

## Result Artifacts

- Authoritative JSON files:
  - `e2e/results/tracee_authoritative_20260328.json`
  - `e2e/results/tetragon_authoritative_20260328.json`
  - `e2e/results/bpftrace_authoritative_20260328.json`
  - `e2e/results/scx_authoritative_20260328.json`
  - `e2e/results/katran_authoritative_20260328.json`
  - `e2e/results/bcc_authoritative_20260328.json`
- Latest per-case result directories from this run:
  - `e2e/results/tracee_20260328_142203`
  - `e2e/results/tetragon_20260328_143149`
  - `e2e/results/bpftrace_20260328_143337`
  - `e2e/results/scx_20260328_143743`
  - `e2e/results/katran_20260328_143919`
  - `e2e/results/bcc_20260328_144102`

## Overall Summary

| Case | Status | Data validity | Key performance result | Apply / optimization summary | Errors / anomalies |
| --- | --- | --- | --- | --- | --- |
| tracee | PASS | Full | `exec_storm +1775.63%`, `file_io +8.46%`, `network +5.06%` app throughput | 1/1 selected program optimized, `130/130` sites applied; effective passes: `const_prop`, `dce` | No usable BPF avg ns in this run |
| tetragon | PASS | Baseline only | Baseline only: `250.91 ops/s`, `151.18 events/s`, `4620.27 ns` | 2 programs selected, `0` sites applied | `event_execve` ReJIT failed with `BPF_PROG_REJIT: Permission denied`; no post-ReJIT data |
| bpftrace | PASS | Baseline only | `6` baseline successes, `0` ReJIT successes, geomean speedup `n/a` | `4` scripts had eligible sites, `21` total sites, but no successful post-ReJIT phase | Artifact does not retain a per-script daemon error summary |
| scx | PASS | Partial / baseline only | Baseline only: `hackbench 5.96 runs/s`, `stress-ng 11621.65`, `sysbench 17651.11` | `13` scanned programs, `3345` total sites; ReJIT succeeded for 2 programs totaling `889` sites | `11` programs failed `BPF_PROG_GET_FD_BY_ID`; no post-ReJIT measurements |
| katran | PASS | Full | Throughput `+1.78%`, latency p99 `-2.21%`, BPF ns `-4.55%`, speedup `1.0477x` | Direct-map control plane, not daemon; `balancer_ingress` had `map_inline=2` per cycle | No harness error |
| bcc | PASS | Mostly full | `10` baseline successes, `9` ReJIT successes, geomean speedup `0.983x` | `9/10` tools had sites; aggregate sites `3165` with `map_inline=183`, `const_prop=300`, `dce=2674` | `vfsstat` had `0` sites so no ReJIT phase |

## Tracee

- Result dir: `e2e/results/tracee_20260328_142203`
- Authoritative file: `e2e/results/tracee_authoritative_20260328.json`
- Status: `PASS`
- Mode: `tracee_daemon`
- Data validity: full stock-vs-ReJIT comparison for all 3 workloads

| Workload | App stock | App ReJIT | App delta | Events/s stock | Events/s ReJIT | CPU stock | CPU ReJIT | BPF avg ns |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| exec_storm | `2.5418 bogo-ops/s` | `47.6740 bogo-ops/s` | `+1775.63%` | `6480.7993` | `6514.5981` | `9.9487%` | `9.5312%` | `n/a` |
| file_io | `5109.3627 IOPS` | `5541.4762 IOPS` | `+8.46%` | `7.7636` | `7.7246` | `0.2000%` | `0.1333%` | `n/a` |
| network | `6179.7810 req/s` | `6492.2285 req/s` | `+5.06%` | `6182.0261` | `6494.2946` | `19.3499%` | `19.9666%` | `n/a` |

Daemon / apply summary:

- Selected Tracee programs: `1`
- Applied Tracee programs: `1`
- Program optimized: `sys_enter_submit` / `sys_enter_submi`
- Scan summary: `130` total sites, `site_summary = const_prop=32 dce=98 bulk_memory=1`
- ReJIT applied sites: `130 / 130`
- Effective passes: `const_prop=32`, `dce=98`
- `map_inline` was scanned but did not apply; it was skipped because the program contains `bpf_tail_call`

Notes:

- All drop counters stayed at zero in both phases.
- No usable `bpf_avg_ns` was recorded for this run, so BPF exec time speedup is not available.

## Tetragon

- Result dir: `e2e/results/tetragon_20260328_143149`
- Authoritative file: `e2e/results/tetragon_authoritative_20260328.json`
- Status: `PASS`
- Mode: `tetragon_daemon`
- Data validity: baseline only

Baseline metrics:

- Application throughput mean: `250.9107 ops/s`
- Events/s mean: `151.1808`
- Agent CPU mean: `13.2979%`
- BPF avg ns mean: `4620.2684`

Program scan / apply summary:

- Selected Tetragon programs: `2`
- Applied Tetragon programs: `2` selected for attempt, but `0` sites were applied successfully
- `execve_rate`: `0` sites
- `event_execve`: `224` sites, `site_summary = const_prop=19 dce=204 const_prop=1`
- ReJIT result counts: `0 / 0` applied sites

Error:

- `event_execve` failed during ReJIT with `BPF_PROG_REJIT: Permission denied (os error 13)`
- The error includes a verifier log, so the likely cause is verifier rejection of the rewritten program rather than harness setup failure

Impact:

- No post-ReJIT metrics were produced
- Comparison is explicitly marked `Comparable: False` with reason `rejit did not apply successfully`

## bpftrace

- Result dir: `e2e/results/bpftrace_20260328_143337`
- Authoritative file: `e2e/results/bpftrace_authoritative_20260328.json`
- Status: `PASS`
- Mode: `full`
- Data validity: baseline only

Summary:

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `0`
- Scripts with eligible sites: `4`
- Aggregate sites: `21` total, all `wide`
- Geomean speedup: `n/a`

Per-script metrics:

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s stock | Ops/s ReJIT | CPU% stock | CPU% ReJIT |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | `8` | `924.48` | `n/a` | `n/a` | `23.21` | `n/a` | `0.07` | `n/a` |
| biosnoop | `4` | `3943.93` | `n/a` | `n/a` | `13620.78` | `n/a` | `0.03` | `n/a` |
| runqlat | `0` | `180.07` | `n/a` | `n/a` | `61.63` | `n/a` | `0.03` | `n/a` |
| tcpretrans | `3` | `n/a` | `n/a` | `n/a` | `21.69` | `n/a` | `0.03` | `n/a` |
| capable | `6` | `257.26` | `n/a` | `n/a` | `336.14` | `n/a` | `0.00` | `n/a` |
| vfsstat | `0` | `35.37` | `n/a` | `n/a` | `13133.30` | `n/a` | `0.03` | `n/a` |

Daemon / apply summary:

- The run used `daemon/target/release/bpfrejit-daemon`
- The authoritative artifact preserves aggregate scan totals and overall success counts, but it does not keep a per-script daemon apply/error summary
- Operationally, no script produced a successful ReJIT phase in this run

Likely causes:

- `runqlat` and `vfsstat` had `0` eligible sites, so no meaningful ReJIT phase exists for those scripts
- The remaining scripts had eligible sites but still produced no post-ReJIT measurements
- The authoritative artifact shows `rejit = null` rather than a detailed error payload, so the exact failure point is not recoverable from the saved summary alone

## scx

- Result dir: `e2e/results/scx_20260328_143743`
- Authoritative file: `e2e/results/scx_authoritative_20260328.json`
- Status: `PASS`
- Mode: `scx_rusty_loader`
- Data validity: partial / baseline only

Baseline metrics:

- `hackbench`: `5.9645 runs/s`, `lat_p50 = 155.0 ms`, `ctx/s = 959809.5035`, `agent_cpu = 0.1333%`
- `stress-ng-cpu`: `11621.65 bogo-ops/s`, `ctx/s = 134.7588`, `agent_cpu = 0.3000%`
- `sysbench-cpu`: `17651.11 events/s`, `lat_p50 = 0.23 ms`, `ctx/s = 124.6012`, `agent_cpu = 0.3667%`

Scan / apply summary:

- Scanned programs: `13`
- Site-bearing programs: `13`
- Aggregate sites: `3345`
- ReJIT result count: `889 / 889` applied sites before later failures prevented a full case-level comparison
- Successful ReJIT programs:
  - `rusty_select_cp`: `25` sites, `site_summary = map_inline=7 const_prop=3 dce=15`
  - `rusty_enqueue`: `788` sites, `site_summary = map_inline=30 const_prop=51 dce=707`
- Programs scanned but not successfully reopened for apply or follow-up handling:
  - `rusty_dispatch`: `118` sites
  - `rusty_runnable`: `192` sites
  - `rusty_running`: `5` sites
  - `rusty_stopping`: `3` sites
  - `rusty_quiescent`: `192` sites
  - `rusty_set_weigh`: `22` sites
  - `rusty_set_cpuma`: `978` sites
  - `rusty_init_task`: `995` sites
  - `rusty_exit_task`: `5` sites
  - `rusty_init`: `19` sites
  - `rusty_exit`: `3` sites

Error:

- ReJIT terminated with exit code `1`
- Error string: repeated `BPF_PROG_GET_FD_BY_ID(...): No such file or directory (os error 2)` for program IDs `856` through `866`

Impact:

- The saved result explicitly marks comparison as `Comparable: False`
- No post-ReJIT measurements were available for the case as a whole

Likely cause:

- The scheduler loader path made the programs visible for scan, but most struct_ops programs could not be reopened later by prog id
- This looks like a control-plane / program lifetime issue in the userspace orchestration path, not a harness boot problem

Additional benchmark limitation from the artifact:

- `bpftool` does not expose per-program `run_cnt` / `run_time_ns` for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable even when load succeeds

## Katran

- Result dir: `e2e/results/katran_20260328_143919`
- Authoritative file: `e2e/results/katran_authoritative_20260328.json`
- Status: `PASS`
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Control plane: `bpftool_direct_map`
- Data validity: full paired comparison

Performance summary:

- Baseline HTTP successes: `189998 / 189998`
- ReJIT HTTP successes: `189857 / 189857`
- Throughput median: `6009.1454 -> 6116.0228 req/s` (`+1.7786%`)
- Packet PPS median: `36054.8725 -> 36696.1368` (`+1.7786%`)
- Latency p99 median: `1.2889 -> 1.2604 ms` (`-2.2095%`)
- System CPU busy median: `8.9087% -> 8.7076%` (`-2.2579%`)
- BPF avg ns/run median: `283.0289 -> 270.1524` (`-4.5495%`)
- BPF speedup ratio: `1.047664x`

Optimization summary:

- This case does not use the daemon apply path; it uses direct-map / bpftool control
- Live program: `balancer_ingress`
- Across all three paired cycles, the scanned program is `balancer_ingres`
- Per cycle site summary: `map_inline=2 wide_mem=4 endian_fusion=2`
- Effective pass: `map_inline`
- `const_prop` and `dce` did not contribute in this case

Limitations:

- Throughput includes guest-side Python client overhead because the traffic generator is built into the benchmark
- Phase order is always stock then ReJIT inside the same image cycle

## BCC

- Result dir: `e2e/results/bcc_20260328_144102`
- Authoritative file: `e2e/results/bcc_authoritative_20260328.json`
- Status: `PASS`
- Mode: `full`
- Data validity: mostly full

Summary:

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `9`
- Tools with eligible sites: `9`
- Aggregate sites: `3165`
- Aggregate pass totals: `map_inline=183`, `const_prop=300`, `dce=2674`
- Geomean speedup: `0.983x`

Per-tool metrics:

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s stock | Ops/s ReJIT | CPU% stock | CPU% ReJIT |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | `52` | `1360.82` | `1392.38` | `0.977x` | `26.32` | `27.02` | `0.07` | `0.10` |
| biosnoop | `149` | `5705.07` | `5721.13` | `0.997x` | `15059.01` | `15394.32` | `0.00` | `0.07` |
| runqlat | `104` | `222.17` | `204.42` | `1.087x` | `53.92` | `59.57` | `0.00` | `0.00` |
| syscount | `78` | `68.50` | `68.31` | `1.003x` | `7604.24` | `7570.73` | `0.00` | `0.00` |
| execsnoop | `1750` | `1904.80` | `2128.06` | `0.895x` | `55.45` | `55.35` | `0.23` | `0.27` |
| opensnoop | `501` | `634.70` | `758.61` | `0.837x` | `7537.81` | `7621.79` | `0.07` | `0.03` |
| capable | `102` | `257.98` | `252.10` | `1.023x` | `132.63` | `362.32` | `0.20` | `0.23` |
| vfsstat | `0` | `23.22` | `n/a` | `n/a` | `13783.47` | `n/a` | `0.03` | `n/a` |
| tcpconnect | `221` | `3190.61` | `3021.98` | `1.056x` | `23.88` | `22.24` | `0.07` | `0.07` |
| bindsnoop | `208` | `221.80` | `223.35` | `0.993x` | `389260.18` | `394178.80` | `6.80` | `6.97` |

Daemon / apply summary:

- The run used `daemon/target/release/bpfrejit-daemon`
- Effective passes are visible in aggregate site totals: `map_inline`, `const_prop`, and `dce` all fired during this case
- `9` tools had eligible sites and `9` tools produced a ReJIT phase
- `vfsstat` had `0` sites, so its ReJIT columns are correctly `n/a`

## Errors and Exceptions

There was no harness-level case failure. The important data-path exceptions were:

1. `tetragon`
   - `event_execve` failed with `BPF_PROG_REJIT: Permission denied (os error 13)`
   - Verifier log was present, which strongly suggests a verifier rejection during the rewritten-program apply path
2. `bpftrace`
   - No script produced post-ReJIT metrics
   - The saved authoritative artifact does not preserve a script-level daemon error summary, so this run is only baseline-valid for this case
3. `scx`
   - `BPF_PROG_GET_FD_BY_ID(...): No such file or directory (os error 2)` for prog IDs `856..866`
   - This prevented a full case-level post-ReJIT measurement set even though two programs were successfully rewritten
4. `tracee`
   - No usable BPF avg ns was exported, so only application throughput and event-rate comparisons are available
5. `bcc`
   - `vfsstat` had zero eligible sites, so there is no ReJIT phase for that single tool

## Conclusions

- The full VM E2E suite completed successfully from the harness perspective: all six cases ran and `make vm-e2e TARGET=x86` exited `0`.
- The strongest full end-to-end wins in this run are:
  - `tracee` on app throughput
  - `katran` on throughput, latency, CPU, and BPF exec time
- `bcc` is mostly healthy and comparable, but the aggregate geomean was slightly below parity at `0.983x`
- `tetragon`, `bpftrace`, and `scx` need orchestration or verifier-path follow-up before they can be treated as fully comparable ReJIT benchmarks

## Recommendations

1. Prioritize `tetragon` verifier-path debugging for `event_execve`; this is the clearest hard apply failure in the run.
2. Investigate `scx` userspace program lifetime / reopen logic around `BPF_PROG_GET_FD_BY_ID`, because scan sees 13 programs but only 2 survive the later apply flow.
3. Improve `bpftrace` artifact retention so each script records why `rejit` is `null`; right now the summary is not sufficient for root-cause analysis after the run.
4. Add or restore BPF runtime export for `tracee` so app-level gains can be paired with direct BPF exec time.
5. Keep `katran` as a reference-quality E2E case in the short term; it produced the cleanest paired stock-vs-ReJIT measurement in this run.
