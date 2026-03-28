# Data Summary Report (2026-03-28)

## Scope

Authoritative inputs used for this report:

- `e2e/results/tracee_authoritative_20260328.json`
- `e2e/results/tetragon_authoritative_20260328.json`
- `e2e/results/katran_authoritative_20260328.json`
- `e2e/results/bcc_authoritative_20260328.json`
- `e2e/results/bpftrace_authoritative_20260328.json`
- `e2e/results/scx_authoritative_20260328.json`
- `runner/corpus/results/vm_corpus_20260328_191636/metadata.json`
- `docs/tmp/20260328/post_build_fix_static_verify_20260328.md`

## Executive Summary

- The six authoritative E2E files all have `status: ok`, but they do not all represent equally strong stock-vs-ReJIT evidence.
- Clean changed-program + paired comparison exists for `katran` and `bcc`.
- `tracee` changed code and has paired workload measurements, but its selected program recorded `run_cnt_delta=0` / `run_time_ns_delta=0` in both phases, so there is no BPF exec-time speedup number.
- `bpftrace` has paired stock/post-ReJIT runs for 6/6 scripts, but daemon-applied sites are `0`, so the reported geomean speedup is not attributable to changed BPF code.
- `tetragon` still fails with `BPF_PROG_REJIT: Permission denied (os error 13)` on `prog 213`, so there is no paired stock-vs-ReJIT comparison.
- `scx` partially applies on 2 of 13 struct_ops programs (`101 + 788 = 889` applied sites), but 11 programs fail with `BPF_PROG_GET_FD_BY_ID(...): No such file or directory`, so post-ReJIT measurements are unavailable.
- Corpus data is an incomplete in-flight snapshot: `status: running`, `finished_at: null`, `objects_attempted: 45`. Using the macro-object denominator from the static-verify note, this is `45/469 = 9.6%` object coverage so far.
- Static verify passed end-to-end: `531` objects, `1241` programs, `345` applied, `345` verifier-accepted, exit code `0`.

## E2E Overview

| Case | Programs touched by case | Daemon apply result | True paired stock-vs-ReJIT? | Perf takeaway |
| --- | ---: | --- | --- | --- |
| `tracee` | 1 selected raw tracepoint program | `map_inline,const_prop,dce`; `131/131` sites applied | Paired workloads yes; BPF exec-time pair no | `exec_storm` throughput `2.45 -> 71.60` (`+2827.71%`), `file_io` `+14.54%`, `network` `+1.51%` |
| `tetragon` | 2 selected tracepoint programs | ReJIT failed; `0/0` sites applied | No | Baseline only: `5142.13 ns/run`, app throughput `64.22 ops/s`; still `Permission denied` |
| `katran` | 1 XDP program across 3 paired cycles | `map_inline`; `2/2` sites applied in each cycle | Yes | Paired-cycle median: BPF speedup `1.01138x`, app throughput delta `-6.79%` |
| `bcc` | 10 tools / 36 programs | Case summary sites `3174` over `map_inline,const_prop,dce`; 10/10 baseline and 10/10 rejit success | Yes | BPF speedup geomean `1.03087x`; best `opensnoop 1.41639x` |
| `bpftrace` | 6 scripts / 12 programs | `21` scanned `wide` sites, `0` applied sites, `0` changed scripts | Paired runs yes; changed-program comparison no | Geomean `1.03688x`, but no code change happened |
| `scx` | 13 struct_ops programs | 2 programs changed (`101 + 788 = 889` sites), 11 programs failed with `ENOENT` | No | Baseline throughput mean `9739.16`, median `11570.64`; no post-ReJIT metrics |

## E2E Details

### 1. Tracee

Daemon apply:

- Selected / applied programs: `1` program, `sys_enter_submit` (`raw_tracepoint`, prog id `20`)
- Passes applied: `map_inline`, `const_prop`, `dce`
- Applied sites: `131/131`
- Program shape: `3774 -> 3678` insns (`-96`)

Performance:

| Workload | Baseline throughput | Post-ReJIT throughput | Throughput delta | Baseline BPF ns/run | Post-ReJIT BPF ns/run | Events/s delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `exec_storm` | `2.4455` | `71.5970` | `+2827.71%` | n/a | n/a | `+13.16%` |
| `file_io` | `5352.0255` | `6129.9878` | `+14.54%` | n/a | n/a | `-0.33%` |
| `network` | `6215.4620` | `6309.3723` | `+1.51%` | n/a | n/a | `+1.51%` |

Paired-comparison status:

- `comparison.comparable = true`
- There is a real paired baseline/post-ReJIT workload comparison.
- There is not a usable paired BPF exec-time comparison: the selected program reports `active_programs = 0`, `total_events = 0`, and `total_run_time_ns = 0` in both phases.

### 2. Tetragon

Daemon apply:

- Selected / apply-target programs: `2` tracepoints, `execve_rate` (prog `210`) and `event_execve` (prog `213`)
- ReJIT result: `applied = false`
- Applied sites: `0/0`
- No successful pass list was emitted for this authoritative run because apply failed before completion.

Performance:

- Baseline app throughput: `64.2185 ops/s`
- Baseline BPF exec time: `5142.1288 ns/run`
- Baseline events: `8085`
- Baseline events/s: `142.5608`

Paired-comparison status:

- `comparison.comparable = false`
- Reason: `rejit did not apply successfully`

Permission-denied status:

- `Permission denied` is not fixed in this authoritative file.
- The recorded error is `prog 213: BPF_PROG_REJIT: Permission denied (os error 13)`.

### 3. Katran

Daemon apply:

- Same-image paired mode with `3` cycles
- Live program: `balancer_ingress` (`xdp`, prog id `999`)
- Scan summary for the live XDP program: `8` candidate sites total
- Site mix: `map_inline=2`, `wide=4`, `endian=2`
- Actual changed pass: `map_inline`
- Applied sites per cycle: `2/2`

Cycle-level paired results:

| Cycle | Applied sites | Passes | Throughput `stock -> rejit` | Throughput delta | BPF ns/run `stock -> rejit` | BPF speedup | p99 latency delta |
| --- | ---: | --- | --- | ---: | --- | ---: | ---: |
| `0` | `2/2` | `map_inline` | `5937.47 -> 6168.77 rps` | `+3.90%` | `269.39 -> 262.50` | `1.02623x` | `-10.85%` |
| `1` | `2/2` | `map_inline` | `6618.21 -> 5961.36 rps` | `-9.92%` | `268.46 -> 273.39` | `0.98195x` | `+19.57%` |
| `2` | `2/2` | `map_inline` | `6722.40 -> 6454.49 rps` | `-3.99%` | `263.92 -> 265.44` | `0.99428x` | `+10.61%` |

Aggregate paired-cycle-median result:

- Baseline median app throughput: `6618.2085 rps`
- Post-ReJIT median app throughput: `6168.7673 rps`
- App throughput delta: `-6.79098%`
- Baseline median BPF exec time: `268.4583 ns/run`
- Post-ReJIT median BPF exec time: `265.4382 ns/run`
- BPF speedup ratio: `1.0113778462x`
- Baseline HTTP successes: `192814/192814`
- Post-ReJIT HTTP successes: `185874/185874`

Paired-comparison status:

- `comparison.comparable = true`
- This is the cleanest single-program paired E2E comparison in the current dataset.

### 4. BCC

Case summary:

- Selected tools: `10`
- Programs across the 10 tools: `36`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with sites: `9`
- Case-level site totals from authoritative summary: `3174`
- Site mix from authoritative summary: `map_inline=183`, `const_prop=300`, `dce=2683`
- BPF speedup geomean: `1.0308739286x`

Per-tool detail:

| Tool | Programs | Sites (record summary) | Applied sites (daemon counts) | BPF speedup | App throughput delta |
| --- | ---: | ---: | ---: | ---: | ---: |
| `tcplife` | `1` | `52` | `52` | `0.87998x` | `+5.83%` |
| `biosnoop` | `4` | `149` | `149` | `0.91624x` | `+0.04%` |
| `runqlat` | `3` | `104` | `116` | `0.98862x` | `+0.16%` |
| `syscount` | `2` | `78` | `78` | `1.02741x` | `-0.90%` |
| `execsnoop` | `2` | `1759` | `1759` | `1.11232x` | `+7.21%` |
| `opensnoop` | `6` | `501` | `501` | `1.41639x` | `+0.89%` |
| `capable` | `2` | `102` | `100` | `1.00798x` | `+261.29%` |
| `vfsstat` | `8` | `0` | `0` | `0.99169x` | `+5.71%` |
| `tcpconnect` | `4` | `221` | `221` | `1.10109x` | `-14.71%` |
| `bindsnoop` | `4` | `208` | `202` | `0.95442x` | `-0.37%` |

Paired-comparison status:

- 10/10 tools have both baseline and post-ReJIT measurements.
- 9/10 tools show nonzero daemon-applied sites; only `vfsstat` remains unchanged.

Data note:

- The authoritative case summary reports `3174` total sites, but summing per-record `rejit_result.counts.applied_sites` gives `3178`.
- The mismatch comes from per-record differences in `runqlat` (`104` vs `116`), `capable` (`102` vs `100`), and `bindsnoop` (`208` vs `202`).
- For case aggregate I treat `summary.site_totals` as authoritative; for per-tool apply I treat `rejit_result.counts` as authoritative.

### 5. BPFTrace

Case summary:

- Selected scripts: `6`
- Programs across the 6 scripts: `12`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with scanned sites: `4`
- Case-level scanned sites: `21`
- Site mix from authoritative summary: `wide=21`, everything else `0`
- Total daemon-applied sites across the case: `0`
- Changed scripts: none
- Geomean speedup reported by the file: `1.0368767677x`

Per-script detail:

| Script | Programs | Scanned sites | Applied sites | BPF speedup | App throughput delta |
| --- | ---: | ---: | ---: | ---: | ---: |
| `tcplife` | `1` | `8` | `0` | `1.26192x` | `+10.66%` |
| `biosnoop` | `2` | `4` | `0` | `0.93421x` | `-0.00%` |
| `runqlat` | `3` | `0` | `0` | `1.02309x` | `+1.46%` |
| `tcpretrans` | `1` | `3` | `0` | n/a | `+11.48%` |
| `capable` | `1` | `6` | `0` | `0.98752x` | `-62.22%` |
| `vfsstat` | `4` | `0` | `0` | `1.00623x` | `+3.72%` |

Paired-comparison status:

- 6/6 scripts have paired baseline/post runs.
- But there is no real changed-program stock-vs-ReJIT comparison here: applied sites are `0`, and all runs are effectively identity ReJIT.
- Therefore the reported geomean speedup is measurement noise / run-to-run variance, not evidence of successful optimization.

### 6. SCX

Daemon apply:

- Scheduler object: `corpus/build/scx/scx_rusty_main.bpf.o`
- Scheduler programs: `13`
- Scan summary: `13` scanned programs, `13` site-bearing programs, `3345` total candidate sites
- ReJIT changed only 2 programs:
  - `rusty_select_cpu` (prog `961`): `101` applied sites, passes `map_inline,const_prop,dce`, insns `733 -> 647`
  - `rusty_enqueue` (prog `963`): `788` applied sites, passes `map_inline,const_prop,dce`, insns `2194 -> 1488`
- Aggregate apply counts before failure: `889/889`
- 11 remaining struct_ops programs (`964` through `974`) failed with `BPF_PROG_GET_FD_BY_ID(...): No such file or directory`

Performance:

- Baseline throughput mean: `9739.1628`
- Baseline throughput median: `11570.64`
- Baseline throughput range: `5.7185` to `17641.13`
- BPF exec-time metrics are unavailable on this kernel for these struct_ops programs.

Paired-comparison status:

- `comparison.comparable = false`
- Reason: `post-ReJIT measurements are unavailable`
- This case does not provide a valid stock-vs-ReJIT speedup number.

## Corpus (`runner/corpus/results/vm_corpus_20260328_191636/metadata.json`)

### Snapshot Status

- `status: running`
- `started_at: 2026-03-28T19:16:36.012956+00:00`
- `finished_at: null`
- `objects_attempted: 45`
- Using the `469` macro-object denominator from the static-verify note, this is `45/469 = 9.6%` object coverage so far.

### Summary

- `targets_attempted: 351`
- `compile_pairs: 172`
- `applied_programs: 165`
- `measured_pairs: 139`
- `code_size_ratio_geomean: 1.0144545295`
- `exec_ratio_geomean: 0.9985765519`
- `exec_ratio_median: 0.9940476190`
- `exec_ratio_min: 0.7440758294`
- `exec_ratio_max: 2.0`
- `code_size_delta_median_pct: -1.3029315961`
- Pass counts across all attempted corpus work:
  - `map_inline: 295`
  - `const_prop: 306`
  - `dce: 303`
- Run-pass counts over measured pairs:
  - `map_inline: 135`
  - `const_prop: 139`
  - `dce: 138`

Coverage ratios over attempted targets:

- Compile pairs: `172/351 = 49.0%`
- Applied programs: `165/351 = 47.0%`
- Measured pairs: `139/351 = 39.6%`

Per-repo summary:

| Repo | Programs | Compile pairs | Measured pairs | Applied programs | Code-size ratio geomean | Exec-ratio geomean |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `bcc` | `288` | `172` | `139` | `165` | `1.0144545295` | `0.9985765519` |
| `KubeArmor` | `63` | `0` | `0` | `0` | n/a | n/a |

Leading attempted objects:

| Object | Programs | Applied programs | Measured pairs | Code-size ratio geomean | Exec-ratio geomean |
| --- | ---: | ---: | ---: | ---: | ---: |
| `bcc:libbpf-tools/klockstat.bpf.o` | `73` | `73` | `59` | `1.0145687229` | `0.9916558068` |
| `bcc:libbpf-tools/mountsnoop.bpf.o` | `12` | `12` | `12` | `1.0027666514` | n/a |
| `bcc:libbpf-tools/sigsnoop.bpf.o` | `7` | `7` | `7` | `1.0240584422` | `1.4364614349` |
| `bcc:libbpf-tools/opensnoop.bpf.o` | `6` | `6` | `6` | `1.0381937385` | `1.1120047760` |
| `bcc:libbpf-tools/runqslower.bpf.o` | `6` | `6` | `6` | `1.0300731545` | `1.0338918734` |

Largest zero-progress objects in the attempted subset:

| Object | Programs | Applied programs | Measured pairs |
| --- | ---: | ---: | ---: |
| `KubeArmor:system_monitor.bpf.o` | `55` | `0` | `0` |
| `bcc:libbpf-tools/memleak.bpf.o` | `32` | `0` | `0` |
| `bcc:libbpf-tools/fsdist.bpf.o` | `20` | `0` | `0` |
| `bcc:libbpf-tools/fsslower.bpf.o` | `16` | `0` | `0` |
| `bcc:libbpf-tools/cachestat.bpf.o` | `11` | `0` | `0` |

### Failure Reasons

Important data-shape note:

- Top-level `failure_reasons` in `metadata.json` is `null`.
- The populated failure summary is nested at `.summary.failure_reasons`.

Raw reasons from `.summary.failure_reasons`:

| Failure reason | Count |
| --- | ---: |
| `prepared ... baseline ... bpf_object__load failed: Invalid argument` | `208` |
| `prepared ... rejit ... bpf_object__load failed: Invalid argument` | `208` |
| `prepared ... baseline ... bpf_object__load failed: No such process` | `142` |
| `prepared ... rejit ... bpf_object__load failed: No such process` | `142` |
| `bpf_program__attach failed: No such file or directory` | `40` |
| `bpf_program__attach failed: Operation not supported` | `20` |
| `prepared ... baseline ... bpf_object__load failed: Permission denied` | `8` |
| `prepared ... rejit ... bpf_object__load failed: Permission denied` | `8` |
| `bpf_program__attach failed: Invalid argument` | `4` |
| `bpf_program__attach failed: Device or resource busy` | `2` |

Phase-collapsed view of the same reasons:

| Failure reason (baseline/rejit collapsed) | Count |
| --- | ---: |
| `prepare failed: bpf_object__load failed: Invalid argument` | `416` |
| `prepare failed: bpf_object__load failed: No such process` | `284` |
| `bpf_program__attach failed: No such file or directory` | `40` |
| `bpf_program__attach failed: Operation not supported` | `20` |
| `prepare failed: bpf_object__load failed: Permission denied` | `16` |
| `bpf_program__attach failed: Invalid argument` | `4` |
| `bpf_program__attach failed: Device or resource busy` | `2` |

Interpretation:

- The dominant blockers are object prepare/load failures, not late-stage ReJIT failures.
- `Invalid argument` during `bpf_object__load` is the single largest blocker (`416` phase-occurrences).
- `No such process` during prepare is the second-largest blocker (`284` phase-occurrences).
- KubeArmor contributes no successful compile/apply/measured pairs in this partial snapshot.

## Static Verify (`docs/tmp/20260328/post_build_fix_static_verify_20260328.md`)

Build / verify status:

- `python3 runner/scripts/build_corpus_objects.py --max-sources 0`
- `make daemon && make runner`
- `make vm-static-test TARGET=x86`
- All three steps completed successfully in the note.

Corpus rebuild note:

- Generated at: `2026-03-28T18:46:23.879380+00:00`
- `built: 0`
- `failed: 8`
- `available: 469`
- The note explicitly says this rebuild staged existing objects rather than rebuilding them.

Static verify result:

- Generated at: `2026-03-28T19:15:16.569968+00:00`
- Objects: `531`
- Programs: `1241`
- Applied: `345`
- Verifier accepted: `345`
- Acceptance on applied programs: `345/345 = 100%`
- Applied-program ratio over all scanned programs: `345/1241 = 27.8%`
- Object composition from the note: `469` macro objects + `62` micro objects
- `vm-static-test` exit code: `0`

## Bottom Line

- On 2026-03-28, the strongest changed-program E2E evidence comes from `katran` and `bcc`.
- `tracee` is useful for paired app-level measurements but not for BPF exec-time measurement.
- `bpftrace` currently provides paired reruns, not paired changed-program comparisons.
- `tetragon` is still blocked by `Permission denied`.
- `scx` is still blocked by post-apply loader / FD-liveness issues.
- Corpus execution is still only a partial snapshot, while static verify already shows `345` programs can be safely rewritten and re-verified.
