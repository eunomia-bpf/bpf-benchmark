# Katran E2E Performance Regression Investigation

Date: `2026-03-20`  
Repo: `/home/yunwei37/workspace/bpf-benchmark`

## Executive Summary

- The current Katran E2E regression (`407.6 -> 507.0 ns`, `+24.4%`) is **most likely a measurement/harness artifact**, not evidence that `WIDE_MEM` is intrinsically regressive on Katran.
- The active E2E run loaded exactly **one** live program, `balancer_ingress` (`XDP`, `2322` insns), with `94` live sites. The applied policy kept exactly **4 `wide-load-2` sites** and dropped nothing.
- The active E2E policy is **not stale**. Current `corpus/policies/katran/` files also look refreshed, matching the post-`2026-03-18` live totals.
- The current Katran harness does **not** use the `#262` same-image `micro_exec run-kernel` path. It does a sequential live measurement:
  1. load/attach
  2. baseline traffic phase
  3. live enumerate + recompile
  4. post-reJIT traffic phase
- The biggest problem is the measurement design:
  - `duration_s` is dead metadata and does not drive load
  - the authoritative run is actually only `sample_count=1`, `packet_repeat=5`
  - that produced just `30` BPF events per phase
  - baseline and post phases reuse the same warmed Katran state/maps
  - there is no repeated paired sampling, no warmup symmetry, and no order randomization
- Code size did **not** regress: `bytes_jited 13412 -> 13364` (`-48 B`, `-0.36%`). If there is any real effect, it is more likely a small full-image code-layout effect than a true code-size/I-cache regression from the 4 wide sites.

## 1. What Programs Are Loaded?

### Active E2E case

From `e2e/results/katran_authoritative_20260319.json`:

- Exactly one live program is attached:
  - `prog_id=7`
  - `name=balancer_ingress`
  - `type=xdp`
  - attach mode: `xdp`
  - device: `eth0`
- `object_inventory` shows `corpus/build/katran/balancer.bpf.o` contributes exactly one relevant program to this case:
  - `balancer_ingress`
  - `section=xdp`
  - `insn_count=2322`

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `167-237`, `255-280`
- `docs/tmp/katran_e2e_feasibility_20260318.md` lines `49-69`

### Live site families on the loaded program

Per-program live counts from the authoritative JSON:

- `branch-flip=56`
- `rotate=20`
- `cmov=8`
- `wide=4`
- `endian=4`
- `extract=2`
- `lea=0`
- `zero-ext=0`
- total `94`

Applied sites:

- `applied_sites=4`
- all 4 are the `wide-load-2` sites at insns `120`, `125`, `266`, `271`

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `399-418`, `424-443`, `896-916`

## 2. Is The Policy Correct? Are There Stale Katran Sites?

### Active E2E policy

The active E2E policy file is narrow and explicit:

- `e2e/cases/katran/balancer_ingress.e2e.policy.yaml`
- contains only 4 entries
- all are `family: wide`, `pattern_kind: wide-load-2`
- no `cmov`, `branch-flip`, `rotate`, `extract`, or `endian`

Evidence:

- `e2e/cases/katran/balancer_ingress.e2e.policy.yaml` lines `1-15`

### Remap result in the live run

The authoritative JSON confirms the policy remap is exact:

- `explicit_sites=4`
- `remapped_sites=4`
- `dropped_sites=0`
- `policy_family_counts = { wide: 4 }`
- `remapped_family_counts = { wide: 4 }`

So the active E2E run is **not** accidentally applying stale or extra sites.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `896-916`

### Current corpus policies

Current checked-in `corpus/policies/katran/` also look refreshed:

- `corpus/policies/katran/balancer/balancer_ingress.policy.yaml`
  - refreshed on `2026-03-18`
  - comment says live totals are `cmov=8, wide=4, rotate=20, extract=2, endian=4, branch-flip=56`
  - entries include the 4 live `wide` sites plus 4 live `endian` sites
- `corpus/policies/katran/healthchecking/healthcheck_encap.policy.yaml`
  - refreshed on `2026-03-18`
  - comment says live totals are `cmov=1, endian=1, branch-flip=7`
  - entry keeps the 1 live endian site

Evidence:

- `corpus/policies/katran/balancer/balancer_ingress.policy.yaml` lines `1-32`
- `corpus/policies/katran/healthchecking/healthcheck_encap.policy.yaml` lines `1-11`

### Conclusion on policy correctness

- **Historical stale-policy issue:** real, and explicitly documented in `#191/#192`
- **Current active E2E path:** **not stale**
- **Current corpus Katran policies:** also appear refreshed

This means the present `407.6 -> 507.0` regression is **not** explained by stale policy artifacts.

## 3. Does Katran E2E Use The `#262` Same-Image Paired Measurement?

Short answer: **no**.

`#262` changed `micro_exec run-kernel --recompile` to:

1. load once
2. stock warmup
3. stock timed pass
4. recompile
5. recompile warmup
6. recompile timed pass

and emit `stock_exec_ns` from the same loaded program image.

Evidence:

- `docs/tmp/same_image_measurement_20260319.md` lines `5-25`

Katran does not use `micro_exec run-kernel`. Its flow is:

1. load/attach live program
2. configure maps/topology
3. run `baseline = measure_phase(...)`
4. `scan_programs(...)`
5. `apply_recompile(...)`
6. run `post = measure_phase(...)`

Evidence:

- `e2e/cases/katran/case.py` lines `1170-1194`

Nuance:

- This is still an **in-place** live recompile on the same `prog_id=7`, so it does avoid a separate reload/new-prog baseline mismatch.
- But it is **not** the `#262` same-image measured-runner methodology, and it does **not** reset datapath state between stock and post-reJIT phases.

## 4. Does The E2E Harness Measure Stock vs Recompile Correctly?

### What is correct

The BPF timing math itself is fine:

- `sample_bpf_stats()` reads `run_cnt` and `run_time_ns`
- `compute_delta()` computes per-program deltas
- `avg_ns_per_run = run_time_delta / run_cnt_delta`

Evidence:

- `e2e/common/metrics.py` lines `108-167`
- `e2e/cases/katran/case.py` lines `1045-1057`

### What is incorrect or too weak

#### 4.1 `duration_s` is unused

`run_katran_case()` computes `duration_s`, but never uses it to generate traffic or bound a measurement loop. It is only written into the result payload.

Evidence:

- `e2e/cases/katran/case.py` line `1095`
- `e2e/cases/katran/case.py` line `1204`

This means the top-level result says `duration_s: 10`, but the actual measurement is not a 10-second run.

#### 4.2 The authoritative run is actually tiny

The saved “authoritative” run is:

- `sample_count = 1`
- `packet_repeat = 5`
- `http_request_count = 5` per phase
- `total_events = 30` per phase

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `277-280`, `928-928`
- `e2e/results/katran_authoritative_20260319.json` lines `18-23`, `25-27`
- `e2e/results/katran_authoritative_20260319.json` lines `297-302`, `304-306`

For a stateful XDP LB datapath, 30 BPF events per phase is not enough to support a strong `+24.4%` conclusion.

#### 4.3 Fixed-order phase bias

The harness always measures:

1. stock first
2. recompile second

There is no:

- repeated pairing
- order randomization
- A/B/A check
- confidence interval / bootstrap

This is exactly the kind of fixed-order one-sample design the broader framework reviews were already warning about.

Evidence:

- `e2e/cases/katran/case.py` lines `1170-1194`
- `docs/tmp/benchmark_framework_review_20260319.md` lines `540-547`

#### 4.4 Stateful Katran maps are reused across phases

The live program keeps stateful maps such as:

- `fallback_cache`
- `lru_mapping`
- `lru_miss_stats`
- `vip_miss_stats`
- `reals_stats`
- `server_id_stats`

These are created once and kept across the baseline and post-reJIT phases. The harness does **not** recreate the session or clear state between the two measurements.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `187-205`
- `e2e/cases/katran/case.py` lines `1147-1195`

This matters because Katran is a stateful LB datapath: baseline traffic can warm caches / connection-selection state / neighbor state, so post-reJIT may be executing a **different steady-state path** than the initial baseline even before we talk about code generation.

#### 4.5 There is visible warmup drift even in the saved HTTP latencies

Baseline per-request latency:

- first request: `25.56 ms`
- remaining requests: roughly `10.8-11.9 ms`

Post-reJIT per-request latency:

- all requests: roughly `7.9-11.0 ms`

So the first phase is visibly colder than the second phase at the application level.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `42-82`
- `e2e/results/katran_authoritative_20260319.json` lines `321-360`

This does not directly prove the BPF delta is wrong, but it is further evidence that the two phases are not equally warmed.

#### 4.6 The case is still direct-map emulation, not the full authoritative design

The current case reports:

- `mode = katran_dsr_direct_map_emulation`
- `control_plane_mode = bpftool_direct_map`

and the case code resolves `katran_server_grpc` only to record its path. It does not actually launch the server or use it to load/configure the datapath.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `127-147`, `254-280`
- `e2e/cases/katran/case.py` lines `1122-1140`, `1201-1209`
- `docs/tmp/katran_e2e_grpc_fix_20260319.md` lines `69-77`

This is acceptable for a balancer-only MVP, but it means the current result should not be over-interpreted as the fully authoritative Katran path described in `#202`.

## 5. Could This Just Be VM Noise? What Are The Repeat/Iteration Counts?

Yes, VM noise and phase-order/state drift are both plausible, and the current repeat counts are far too small:

- `sample_count = 1`
- `packet_repeat = 5`
- baseline BPF events = `30`
- post BPF events = `30`

That is a single paired observation over very little traffic.

The broader framework review already recommended:

- repeated paired samples
- same loaded-program comparisons
- more Katran sampling before using it as a main result

Evidence:

- `docs/tmp/benchmark_framework_review_20260319.md` lines `542-547`

## 6. Is There A Code-Size Regression That Could Explain I-Cache Issues?

### Direct answer

There is **no code-size regression** in the current E2E run.

Per-program bytes:

- baseline `bytes_jited = 13412`
- post-reJIT `bytes_jited = 13364`

So the recompiled image is actually **48 bytes smaller**.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `7-15`
- `e2e/results/katran_authoritative_20260319.json` lines `286-294`

### What still remains possible

`#153` already established that re-JIT is a **full-image recompile**, not a site-local patch. That means:

- non-site bytes can change
- downstream relative branches can move
- layout-sensitive performance changes are possible even when size shrinks

Evidence:

- `docs/kernel-jit-optimization-plan.md` line `630`

So if there is any real performance effect here, it is more likely:

- a small code-layout / branch-alignment effect

than:

- a code-size blow-up

### How strong is that explanation here?

Not very strong as an explanation for the full observed `+24.4%`, because:

- size change is tiny (`-48 B`)
- only 4 sites are applied
- the run is extremely lightly sampled

Recent corpus-side evidence also points to a **small** Katran sensitivity, not a giant cliff:

- `balancer_ingress`: `54ns -> 61ns` (`0.885x`) with applied `wide+endian`

Evidence:

- `docs/tmp/corpus_improvement_analysis_20260319.md` lines `190-199`

That is directionally negative, but much smaller and still in the same “layout-sensitive small effect” class.

## 7. Actual JSON Per-Program Breakdown

There is only one contributing program in the authoritative Katran E2E JSON:

- `prog_id=7`
- `balancer_ingress`
- `type=xdp`

Baseline:

- `run_cnt_delta = 30`
- `run_time_ns_delta = 12228`
- `avg_ns_per_run = 407.6`
- `bytes_jited = 13412`

Post-reJIT:

- `run_cnt_delta = 30`
- `run_time_ns_delta = 15211`
- `avg_ns_per_run = 507.033...`
- `bytes_jited = 13364`

There is no hidden second program driving the regression.

Evidence:

- `e2e/results/katran_authoritative_20260319.json` lines `7-23`
- `e2e/results/katran_authoritative_20260319.json` lines `286-302`

## Root Cause Analysis

### Primary root cause

The current `407.6 -> 507.0` Katran E2E delta is best explained by **measurement methodology**, not by a policy bug and not by evidence that `WIDE_MEM` is fundamentally bad on Katran.

The key reasons are:

1. **Active policy is correct**
   - only 4 `wide` sites
   - all 4 remap successfully
   - no stale-site drop

2. **No unexpected families were applied**
   - `cmov`, `branch-flip`, `rotate`, `extract`, `endian` are present live but not enabled by the active E2E policy

3. **The run is too small**
   - 1 sample
   - 5 HTTP requests
   - 30 BPF events

4. **The phases are not symmetric**
   - fixed stock-then-recompile order
   - no warmup symmetry
   - no repeated paired sampling
   - no state reset between phases

5. **Katran is stateful**
   - the second phase runs on warmed maps/state
   - this is especially problematic for LRU/fallback/neighbor-sensitive datapaths

### Secondary possible contributor

There may still be a **small real layout effect** from full-image recompile. `#153` makes that plausible in principle. But with the current harness, the data are too weak to separate:

- small real layout sensitivity

from:

- fixed-order phase drift
- warmed-state bias
- VM noise

### What this is not

This is **not** primarily:

- a stale-policy miss
- accidental `cmov`/`branch-flip` application
- a code-size growth regression

## Suggested Fix

## Short-term recommendation

- **Do not change the Katran policy based on the current `407.6 -> 507.0` number.**
- **Do not treat this BPF delta as paper-authoritative.**
- Keep Katran in the table as:
  - functional datapath proof
  - performance pending measurement fix / repeated paired rerun

This matches the current status note for `#205`: setup/runtime integration is fixed, performance is still unresolved.

## Specific changes to make the result trustworthy

### 1. Fix the Katran harness before tuning policy

Target file: `e2e/cases/katran/case.py`

Recommended changes:

1. Make `duration_s` real
   - either drive a time-based traffic loop with it
   - or delete it from the payload and expose only explicit request counts

2. Increase sampling substantially
   - raise defaults from `sample_count=1`, `packet_repeat=5`
   - use at least repeated paired samples (`>=10`)
   - and much larger per-sample traffic (`>=100-1000` requests, or a duration-based loop)

3. Add symmetric warmup
   - warm up both stock and post-reJIT phases before timing

4. Eliminate state carry-over bias
   - best option: recreate the topology/session/maps for each paired measurement
   - acceptable option: explicitly clear/reinitialize Katran stateful maps between stock and post phases

5. Report repeated-pair statistics
   - median
   - p25/p75 or CI
   - per-pair raw deltas

### 2. Keep the current case labeled as MVP/direct-map unless the full design is implemented

Target files:

- `e2e/cases/katran/case.py`
- result/status docs

Recommended change:

- keep calling the current path what it actually is:
  - `bpftool_direct_map`
  - `katran_dsr_direct_map_emulation`

If the goal is a fully authoritative Katran deployment result, then finish the `#202` design:

- official server path
- external/raw traffic generator
- authoritative PPS-oriented workload

### 3. Only revisit policy after the harness fix

After the measurement fix, rerun these comparisons:

1. stock vs current E2E `wide-only`
2. stock vs current corpus `wide+endian`
3. repeated fresh pairs across multiple VM boots or recreated topologies

Only if the repeated paired signal remains negative should Katran be switched to:

- stock / skip in E2E
- or a narrower allowlist

## Bottom Line

- The active Katran E2E regression is **not** explained by stale policy.
- It is **not** a hidden multi-family apply.
- It is **not** a code-size blow-up.
- The strongest explanation is that the current Katran harness is still too light and too stateful to support a reliable stock-vs-recompile BPF timing claim.
- The correct next step is a **harness/measurement fix**, not a policy rollback.
