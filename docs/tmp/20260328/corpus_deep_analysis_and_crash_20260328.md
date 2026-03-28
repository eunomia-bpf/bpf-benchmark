# Corpus Deep Analysis And Crash Investigation (2026-03-28)

## Scope

Read artifacts:

- `runner/corpus/results/vm_corpus_20260328_194356/details/result.json`
- `runner/corpus/results/vm_corpus_20260328_194356/metadata.json`
- `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-*.json`
- `docs/tmp/20260328/corpus-rejit-batch/*.stdout_log.txt`
- `docs/tmp/20260328/vm-tmp/bpfrejit-daemon-*/daemon.{stdout,stderr}.log`
- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`

I also checked the guest batch driver, the two selftest sources, and the daemon retry code to pin down the crash boundary.

## Method And Caveats

- `measured_pairs = 483` means both baseline and REJIT runs returned successfully.
- Only `255` of those `483` have `speedup_ratio != null`.
- The remaining `228` measured pairs have `exec_ns = 0` on at least one side, so they are measured but not speedup-comparable.
- For percentages requested as “占 measured 的百分比”, I use `483` as the denominator.
- For ranking and threshold buckets such as `speedup > 1.05`, I use the `255` comparable pairs.

## Metric Sanity Check

`speedup_ratio` in this artifact is:

`baseline_exec_ns / rejit_exec_ns`

So:

- `> 1` means REJIT is faster
- `< 1` means REJIT is slower

This also matches `summary.by_repo[*].exec_ratio_geomean`, despite the confusing field name.

That means the repo-level readings in the prompt are directionally reversed:

- `calico 1.125x` means `12.5% faster`, not slower
- `linux-selftests 0.874x` means `12.6% slower`, not faster
- `bcc 0.978x` means `2.2% slower`, not faster

## Part 1: Corpus Deep Analysis

### 1. Top 10 Speedup Programs

Raw top 10 by `speedup_ratio`:

| Rank | Program | Speedup | Repo | Prog type | Passes | Sites | Baseline ns | REJIT ns |
| --- | --- | ---: | --- | --- | --- | ---: | ---: | ---: |
| 1 | `calico:xdp_debug.bpf.o:calico_xdp_norm_pol_tail` | 5.1267x | calico | xdp | none | 0 | 769 | 150 |
| 2 | `linux-selftests:.../security_bpf_map.bpf.o:fmod_bpf_map` | 4.1875x | linux-selftests | tracing | `map_inline,const_prop,dce` | 12 | 134 | 32 |
| 3 | `calico:from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 3.8052x | calico | sched_cls | `const_prop` | 25 | 586 | 154 |
| 4 | `calico:to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 3.4824x | calico | sched_cls | `const_prop` | 32 | 592 | 170 |
| 5 | `calico:xdp_debug.bpf.o:calico_xdp_accepted_entrypoint` | 3.1497x | calico | xdp | none | 0 | 463 | 147 |
| 6 | `calico:to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 3.1469x | calico | sched_cls | `const_prop` | 28 | 557 | 177 |
| 7 | `linux-selftests:.../local_storage.bpf.o:socket_post_create` | 2.9118x | linux-selftests | lsm | none | 0 | 396 | 136 |
| 8 | `calico:from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 2.8428x | calico | sched_cls | `const_prop` | 25 | 651 | 229 |
| 9 | `calico:to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 2.6074x | calico | sched_cls | `const_prop` | 32 | 425 | 163 |
| 10 | `calico:to_wep_debug.bpf.o:calico_tc_main` | 2.5526x | calico | sched_cls | `const_prop` | 28 | 485 | 190 |

Observations:

- Raw top 10 is not a clean “best optimized programs” list.
- `3/10` top entries had `no-change`, so they are measurement wins, not pass-driven wins.
- The strongest clearly pass-driven win is `security_bpf_map.bpf.o:fmod_bpf_map`: `4.19x`, `12` applied sites, `map_inline + const_prop + dce`.
- The pass-driven top 10 is dominated by calico `const_prop`-only sched_cls programs.

### 2. Programs With `speedup > 1.05`

- Count: `88`
- Share of measured: `18.22%`
- Share of comparable: `34.51%`

By repo:

- `calico`: `31`
- `bcc`: `28`
- `linux-selftests`: `21`
- `coroot-node-agent`: `4`
- `katran`: `2`
- `libbpf-bootstrap`: `2`

By pass combination:

- `none`: `36`
- `const_prop`: `28`
- `map_inline + const_prop + dce`: `24`

Key point:

- `40.9%` of the “good” bucket is `no-change`, so raw win count materially overstates actual REJIT-attributable wins.

### 3. Neutral Programs: `0.95 < speedup < 1.05`

- Count: `64`
- Share of measured: `13.25%`
- Share of comparable: `25.10%`

Pass-hit vs no-change:

- Pass-hit: `49`
- No-change: `15`

Interpretation:

- The neutral bucket is mostly actual pass-hit programs (`76.6%`), but their net effect is small.
- So “pass fired but impact is near zero” is a common outcome.

### 4. Regressions: `speedup < 0.95`

- Count: `103`
- Share of measured: `21.33%`
- Share of comparable: `40.39%`

Pass-hit vs no-change:

- Pass-hit: `69`
- No-change: `34`

Worst 10:

| Rank | Program | Speedup | Slowdown | Repo | Passes | Sites | Baseline ns | REJIT ns |
| --- | --- | ---: | ---: | --- | --- | ---: | ---: | ---: |
| 1 | `linux-selftests:.../bench_local_storage_create.bpf.o:socket_post_create` | 0.1679x | 5.96x | linux-selftests | none | 0 | 69 | 411 |
| 2 | `calico:from_nat_debug.bpf.o:calico_tc_main` | 0.2492x | 4.01x | calico | `const_prop` | 25 | 300 | 1204 |
| 3 | `linux-selftests:test_tc_bpf.bpf.o:cls` | 0.2692x | 3.71x | linux-selftests | none | 0 | 7 | 26 |
| 4 | `calico:from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 0.2717x | 3.68x | calico | `const_prop` | 25 | 150 | 552 |
| 5 | `calico:to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 0.3391x | 2.95x | calico | `const_prop` | 32 | 138 | 407 |
| 6 | `linux-selftests:.../decap_sanity.bpf.o:decap_sanity` | 0.3500x | 2.86x | linux-selftests | none | 0 | 7 | 20 |
| 7 | `calico:from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 0.3598x | 2.78x | calico | `const_prop` | 28 | 145 | 403 |
| 8 | `calico:from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 0.3625x | 2.76x | calico | `const_prop` | 28 | 149 | 411 |
| 9 | `linux-selftests:.../cgroup_ancestor.bpf.o:log_cgroup_id` | 0.3684x | 2.71x | linux-selftests | none | 0 | 7 | 19 |
| 10 | `linux-selftests:.../prepare.bpf.o:program` | 0.3684x | 2.71x | linux-selftests | none | 0 | 7 | 19 |

Regression cause analysis:

- `34/103` regressions had `no-change`.
- Among those `34` no-change regressions:
  - `27/34` had baseline runtime `< 100ns`
  - `26/34` had absolute delta `<= 20ns`
- So a large fraction of the linux-selftests regression bucket looks like measurement noise or tiny-runtime instability.

For pass-hit regressions:

- There is a real pass-induced cluster in calico:
  - `from_nat_debug:calico_tc_main` went `300ns -> 1204ns`
  - `from_nat_debug:new_flow_entrypoint` went `150ns -> 552ns`
  - `to_hep_debug:new_flow_entrypoint` went `138ns -> 407ns`
- There is a real pass-induced cluster in bcc:
  - `tcpconnlat:fentry_tcp_rcv_state_process` went `1003ns -> 1691ns`
  - `tcptracer:tcp_v4_connect` went `1204ns -> 2016ns`
  - `opensnoop:sys_enter_openat` went `210ns -> 333ns`
  - `tcpconnect:tcp_v4_connect` went `1137ns -> 1708ns`

My heuristic split is:

- Likely noise-like regressions: about `50`
- Likely pass-induced regressions: about `37`
- Ambiguous: about `16`

This split is an inference from “pass fired?”, absolute ns delta, and code-size delta, not an oracle.

### 5. By-Repo Analysis

#### calico

The prompt’s interpretation is reversed. In this artifact, calico is `1.125x faster`, not `1.125x slower`.

Facts:

- Measured: `59`
- Comparable: `59`
- Zero-signal measured pairs: `0`
- Repo geomean speedup: `1.1255x`

Why calico looks good overall:

- The `51` `const_prop`-only comparable programs are mildly positive: geomean `1.0366x`.
- The `8` no-change comparable programs are very positive: geomean `1.9014x`.
- Those no-change wins are mostly `xdp_debug` / `xdp_no_log` and dominate the repo average.

Bimodality is the real story:

- Best objects:
  - `xdp_debug.bpf.o`: `2.57x`
  - `from_wep_debug.bpf.o`: `1.47x`
  - `xdp_no_log.bpf.o`: `1.41x`
- Worst objects:
  - `from_nat_debug.bpf.o`: `0.755x`
  - `from_hep_debug.bpf.o`: `0.855x`

So calico is not uniformly good. It has very strong wins and very strong losses, with the wins winning the geomean.

#### linux-selftests

The prompt’s interpretation is reversed. In this artifact, linux-selftests is `0.874x`, ანუ `12.6% slower`, not faster.

Facts:

- Measured: `176`
- Comparable: `70`
- Zero-signal measured pairs: `106`
- Repo geomean speedup: `0.8743x`

Why linux-selftests looks bad overall:

- `63/70` comparable programs are `no-change`.
- Those `63` no-change comparable programs have geomean `0.8580x`.
- The actual pass-hit comparable subset (`6` triple-pass programs) is positive: geomean `1.1342x`.

So the repo slowdown is mostly a no-change / tiny-runtime phenomenon, not an “optimization made selftests slower” story.

Largest positive contributor:

- `security_bpf_map.bpf.o:fmod_bpf_map`: `4.1875x`, `12` sites, `map_inline + const_prop + dce`

Largest negative contributors are mostly tiny-runtime no-change cases:

- `bench_local_storage_create`: `69ns -> 411ns`
- `test_tc_bpf:cls`: `7ns -> 26ns`
- `decap_sanity`: `7ns -> 20ns`

#### bcc

The prompt’s interpretation is reversed. In this artifact, bcc is `0.978x`, ანუ about `2.2% slower`, not faster.

Facts:

- Measured: `206`
- Comparable: `103`
- Zero-signal measured pairs: `103`
- Repo geomean speedup: `0.9785x`

Why bcc is slightly net-negative:

- `94/103` comparable programs are `map_inline + const_prop + dce`.
- That main optimized subset has geomean `0.9691x`.
- The `9` no-change comparable programs are positive: geomean `1.0826x`.

So unlike linux-selftests, bcc’s slight slowdown is a real pass-hit effect, not mainly no-change noise.

Worst bcc objects:

- `tcptracer.bpf.o`: `0.696x`
- `opensnoop.bpf.o`: `0.879x`
- `tcpconnect.bpf.o`: `0.891x`

Best bcc objects:

- `syncsnoop.bpf.o`: `1.309x`
- `tcplife.bpf.o`: `1.212x`
- `statsnoop.bpf.o`: `1.077x`

### 6. `map_inline` Effect

The prompt’s “465 map_inline-hit programs” needs one correction:

- `summary.pass_counts.map_inline = 465` is compile+run observation count
- It is not `465` distinct programs

Actual counts:

- Unique programs with any `map_inline` hit: `258`
- Compile hits: `258`
- Run hits: `207`
- Comparable run hits: `108`

On those `108` comparable run hits:

- Geomean speedup: `0.9755x`
- Arithmetic mean speedup: `1.0044x`
- Slower-than-baseline count: `58`

Why the slowdown is not cleanly attributable to `map_inline` alone:

- `106/108` comparable `map_inline` run hits also had `const_prop + dce`
- There is only one pure `map_inline` comparable sample:
  - `katran:balancer_ingress`: `83ns -> 101ns`, `0.8218x`

So the aggregate “map_inline hit but slower” result is really a combined-pipeline story, not a clean map_inline-only story.

Representative slower `map_inline` hit programs:

- `linux-selftests:core_kern.bpf.o:balancer_ingress`: `0.5776x`
- `bcc:tcpconnlat.bpf.o:fentry_tcp_rcv_state_process`: `0.5931x`
- `bcc:tcptracer.bpf.o:tcp_v4_connect`: `0.5972x`

### 7. Code Size Analysis

Applied programs:

- Count: `364`
- Grew: `63`
- Shrunk: `196`
- Unchanged: `105`

Distribution:

- Applied-program size-ratio geomean: `1.0112x`
  - Interpreted as about `1.1%` average shrink in `baseline/rejit` terms
- Median code-size delta: `-0.1718%`
- Min delta: `-46.8927%`
- Max delta: `+6.9565%`

Extremes:

- Maximum shrink:
  - `katran:xdp_pktcntr.bpf.o:pktcntr`
  - `-46.89%`
  - Passes: `map_inline + const_prop + dce`
  - Sites: `12`
- Maximum bloat:
  - `bcc:libbpf-tools/hardirqs.bpf.o:irq_handler_entry_btf`
  - `+6.96%`
  - Passes: `map_inline + const_prop + dce`
  - Sites: `242`

Takeaway:

- The pipeline does shrink code overall.
- That shrink does not translate monotonically into runtime wins.

## Part 2: Crash Bug Investigation

### 1. What The Logs Actually Show

From `metadata.json`:

- `completed_objects = 288`
- `current_target_index = 288`
- `current_target = linux-selftests:.../test_map_init.bpf.o`
- guest exit = `139`

From the guest partial result file:

- `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`
- it contains exactly `288` completed object records
- the last completed object record is `test_map_init.bpf.o`

From the target list:

- 0-based object slot `287` is `test_map_init.bpf.o`
- 0-based object slot `288` is `test_map_lookup_percpu_elem.bpf.o`

From the guest progress emission logic:

- `corpus/modes.py` writes the object record first
- then emits `program_progress`

So `current_target_index = 288` does **not** mean “the crash happened inside test_map_init”.

It means:

- object #288 in the 1-based progress stream was already written
- that object was `test_map_init`
- the **next** object, i.e. `test_map_lookup_percpu_elem.bpf.o`, is the first one with no record

This is consistent with the partial result file and the target list.

### 2. Is It A C++ Runner Crash Or A VM Kernel Crash?

Best-supported answer:

- It is **not** a normal `batch_runner.cpp` exception path.
- It is **not** a plain `libbpf` load failure.
- The crash boundary is in the **guest-side daemon/REJIT path**, and the most likely failure domain is the **VM kernel + REJIT interaction**, not host userspace logic.

Why:

- `runner/src/batch_runner.cpp` catches normal exceptions and writes partial batch results. That did not happen here.
- `runner/src/kernel_runner.cpp` only calls `daemon_socket_optimize()` after the object has already been opened and loaded successfully.
- The daemon logs reached a live program ID for the next object, so `bpf_object__load()` had already succeeded.
- The top-level shell only reports `python3 corpus/driver.py` dying with `SIGSEGV`; a child `micro_exec` exit alone would not normally SIGSEGV the Python parent.

### 3. Is It `libbpf` Load Or Daemon Communication?

It is **not** a `libbpf` load crash.

Evidence:

- No `bpf_object__load failed: ...` record exists for the missing object.
- The daemon already logged a concrete optimize attempt for:
  - `prog 136333 (sysenter_getuid): 21 sites, 72 -> 57 insns`

That means the program was already loaded and had a valid live `prog_id`.

The last daemon stderr line is:

`WARN: pass 'dce' caused post-verifier REJIT failure (BPF_PROG_REJIT: Invalid argument (os error 22)) for prog 136333 (sysenter_getuid)`

followed by:

`Disabling 'dce', retrying...`

and then the logs stop.

So the failure is in the daemon-driven `BPF_PROG_REJIT` apply/retry path, not in `bpf_object__load()`.

### 4. Relevant Runner Path

The relevant path is:

- `run-batch` serial job execution in `runner/src/batch_runner.cpp`
- `prepare_kernel()` in `runner/src/kernel_runner.cpp`
- `build_prepared_program_compile_sample()` in `runner/src/kernel_runner.cpp`
- `maybe_apply_prepared_daemon_rejit()` in `runner/src/kernel_runner.cpp`

Important detail:

- For a REJIT compile-only program job, `build_prepared_program_compile_sample()` calls `maybe_apply_prepared_daemon_rejit()` before any attach/run workload.
- So this crash most likely happened during the REJIT compile stage of the next object, before attach-trigger execution.

### 5. What Is Special About `test_map_init` And `test_map_lookup_percpu_elem`?

`test_map_init.bpf.o` is simple:

- one tracepoint program
- one `BPF_MAP_TYPE_PERCPU_HASH`
- one guarded `bpf_map_update_elem()`
- with default globals in corpus, it is effectively a no-op at runtime

So `test_map_init` is mostly special because it is the **last successfully recorded object**, not because it is the most suspicious program shape.

`test_map_lookup_percpu_elem.bpf.o` is much more special:

- one main tracepoint program plus one callback subprog
- three per-cpu maps:
  - `PERCPU_ARRAY`
  - `PERCPU_HASH`
  - `LRU_PERCPU_HASH`
- uses `bpf_loop()`
- callback performs `bpf_map_lookup_percpu_elem()`

The object-file disassembly shows:

- callback subprog `read_percpu_elem_callback`
- main program `sysenter_getuid`
- total live-program instruction count matches the daemon log’s `72 -> 57 insns`

This matches the exact program name and instruction counts where the daemon stopped.

### 6. Most Likely Root Cause

Most likely root cause is **helper-callback subprog handling in the optimization pipeline**, especially `dce`.

Why this is the leading hypothesis:

- The failing object uses `bpf_loop(..., read_percpu_elem_callback, ...)`, i.e. helper callback subprograms.
- The daemon warning explicitly attributes the first failure to `dce`.
- The daemon’s subprog reachability elimination only treats **pseudo-calls** as edges into subprogs.
- It does **not** model helper callback targets as reachability roots.

That matters because `bpf_loop` / `bpf_for_each_map_elem` style callbacks are not normal pseudo-calls.

So the likely bad sequence is:

1. `dce` rewrites the program while not fully modeling helper-callback reachability.
2. The first `BPF_PROG_REJIT` attempt fails post-verifier.
3. The daemon disables `dce` and retries.
4. During or immediately after that retry path, the guest crashes before returning a structured daemon response.

Two layers of bug may be present:

- A pass-framework bug: helper-callback subprogs are not modeled correctly.
- A kernel / REJIT robustness bug: retrying this program shape can take the guest down instead of returning a clean error.

That second point is an inference, but it fits the abrupt stop after `Disabling 'dce', retrying...`.

### 7. Fix Plan

Recommended fix sequence:

1. Fix helper-callback CFG modeling in the daemon.
   - Extend subprog discovery / reachability so helper callbacks are treated as real edges.
   - Cover at least `bpf_loop` and `bpf_for_each_map_elem`.
   - Make `dce` preserve callback subprogs unless it can prove them dead through helper-callback edges as well.

2. Add a dedicated regression test.
   - Reproduce with just:
     - `test_map_lookup_percpu_elem.bpf.o`
     - program `sysenter_getuid`
   - Validate:
     - baseline load succeeds
     - daemon REJIT either succeeds or returns a structured error
     - no guest SIGSEGV

3. Harden failure behavior.
   - If helper-callback programs are still unsupported, fail this program **explicitly** with a clear daemon error.
   - Do not silently skip it and do not silently fall back.
   - This matches the repo’s zero-silent-failure policy.

4. Improve crash forensics.
   - When `micro_exec run-batch` exits abnormally, persist:
     - active object/program name
     - live `prog_id`
     - enabled/disabled pass set
     - daemon stdout/stderr tail
   - Right now the guest artifact loses the exact failing job boundary.

### 8. Bottom Line

- The corpus data itself is usable, but almost half of measured pairs (`228/483`) are zero-signal and should not be mixed into speedup buckets.
- The repo-level interpretation in the prompt is reversed: calico is faster, linux-selftests is slower, bcc is slightly slower.
- The crash is not really “at test_map_init”.
- `test_map_init` is the last recorded object.
- The first missing object is `test_map_lookup_percpu_elem.bpf.o`.
- The best current explanation is: daemon REJIT retry on a helper-callback/per-cpu-map selftest hit a DCE-related correctness hole and then triggered a guest-side hard crash instead of a clean error.
