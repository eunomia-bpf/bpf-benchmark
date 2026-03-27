# map_inline performance strategy (2026-03-27)

Scope: local source/artifact inspection only. I did not run the VM, change code, or generate new measurements.

## Executive answer

- `run-kernel` / `BPF_PROG_TEST_RUN` uses kernel-reported `duration`, which comes from `ktime_get_ns()` and is returned as an integer `u32` nanosecond average. In the runner, that shows up as `sample.exec_ns`.
- The runner already records higher-resolution external timing around the kernel call: `exec_cycles` and `wall_exec_ns` are derived from `rdtsc` on x86.
- Attach-mode programs do not use `BPF_PROG_TEST_RUN`; they use `bpf_stats` (`run_time_ns / run_cnt`) for `exec_ns`, and that kernel timing comes from `sched_clock()`, not `ktime_get_ns()`. The runner also wraps the workload with `rdtsc` there.
- `BPF_PROG_TEST_RUN` itself cannot be switched to return `rdtsc` or perf counters. But the runner can already collect `rdtsc` and perf counters around the syscall/workload.
- There is no ideal current corpus candidate that is both:
  1. clearly slow enough to measure with `exec_ns`, and
  2. a clean v1 `map_inline` showcase.
- The slowest corpus programs in the named families are Calico programs, but their hot-path map work is mostly dynamic route/conntrack/LPM/hash logic, not the constant-key `ARRAY` control-map pattern that best demonstrates `map_inline`.
- The best overall checked-in measurement candidate is not in the corpus: it is Tetragon attach-mode `event_exit_acct`, which already has a known `map_inline` hit and a previously reported baseline around `6.59 us`, large enough for `bpf_stats`/cycles to see.

## 1. What timing source does the runner use?

### `BPF_PROG_TEST_RUN` path

`runner/src/kernel_runner.cpp` stores kernel `duration` directly into `measurement.exec_ns` and separately computes TSC-based `exec_cycles` / `wall_exec_ns` around `bpf_prog_test_run_opts()`:

- `rdtsc_start()` / `rdtsc_end()`: `runner/src/kernel_runner.cpp:89-104`
- `measurement.exec_ns = context.test_opts->duration`: `runner/src/kernel_runner.cpp:408-442`
- `sample.timing_source = "ktime"` and `sample.timing_source_wall = "rdtsc"`: `runner/src/kernel_runner.cpp:2612-2631`

The kernel-side source of that `duration` is `ktime_get_ns()`:

- `bpf_test_timer_enter()` sets `time_start = ktime_get_ns()`: `vendor/linux-framework/net/bpf/test_run.c:36-41`
- `bpf_test_timer_continue()` accumulates `ktime_get_ns() - time_start`, divides by repeat, and stores into `u32 *duration`: `vendor/linux-framework/net/bpf/test_run.c:50-60`
- The UAPI field is only `__u32 duration`: `vendor/linux-framework/include/uapi/linux/bpf.h:1691-1703`

Conclusion:

- Primary `exec_ns` for `TEST_RUN` is integer-nanosecond, averaged over repeat.
- Raw resolution is effectively 1 ns at the API boundary, with additional quantization from integer division and `u32` storage.
- `exec_cycles` is higher resolution because it is based on `rdtsc` and only divided after the batch.

### Attach-mode path

Attach-mode programs use `bpf_stats`:

- `bpf_enable_stats(BPF_STATS_RUN_TIME)`: `runner/src/kernel_runner.cpp:3530-3535`
- `exec_ns = run_time_ns_delta / run_cnt_delta`: `runner/src/kernel_runner.cpp:3568-3581`
- `sample.timing_source = "bpf_stats"` and TSC-derived `exec_cycles` / `wall_exec_ns`: `runner/src/kernel_runner.cpp:3583-3612`

Kernel-side, `bpf_stats` timing uses `sched_clock()`:

- `u64 duration, start = sched_clock();`
- `duration = sched_clock() - start;`
- accumulated into `stats->nsecs`
- `vendor/linux-framework/include/linux/filter.h:700-727`

So the runner has two different kernel-mode timing modes:

- `TEST_RUN`: `ktime_get_ns()` -> integer `duration`
- attach mode: `sched_clock()` via `bpf_stats`

## 2. Can we switch to `rdtsc` / perf counters for kernel-mode measurement?

### Short answer

- Not inside the `BPF_PROG_TEST_RUN` ABI itself.
- Yes at the runner level, because the runner already does it.

### What is and is not possible

`BPF_PROG_TEST_RUN` only returns `retval`, output buffers, and `duration`; there is no ABI field for cycles or perf counters: `vendor/linux-framework/include/uapi/linux/bpf.h:1691-1706`.

So:

- You cannot ask the kernel to make `BPF_PROG_TEST_RUN` return `rdtsc`.
- You cannot ask `BPF_PROG_TEST_RUN` to return perf event counts.

But the runner already measures around the kernel execution:

- `rdtsc` wraps `bpf_prog_test_run_opts()` in `execute_kernel_test_run()`: `runner/src/kernel_runner.cpp:417-441`
- perf counters are collected around the same callback with `include_kernel = true`: `runner/src/kernel_runner.cpp:464-473`
- counter definitions include `cycles`, `instructions`, `branches`, `branch_misses`, etc.: `runner/src/perf_counters.cpp:27-38`
- perf events are opened on the current task and can include kernel time: `runner/src/perf_counters.cpp:40-52`

Important caveat:

- Those external `rdtsc` / perf measurements are not as pure as kernel-internal `duration`; they include syscall/harness overhead.
- Repeat amortization helps, but for ultra-short programs the fixed syscall cost can still dominate.

Practical answer:

- For tiny `TEST_RUN` programs, use `exec_cycles` and perf `instructions/cycles` as the primary metric, not `exec_ns`.
- For attach-mode programs, `bpf_stats` + `exec_cycles` is already the right measurement stack.

## 3. What does the 2026-03-26 corpus metadata actually tell us?

`corpus/results/vm_corpus_20260326_174240/metadata.json` is summary-only in this checkout:

- it points to `details_dir = "details"`: `corpus/results/vm_corpus_20260326_174240/metadata.json:693`
- but the only file present under that artifact directory is `metadata.json`

So question 4 has a hard limit: that file cannot identify individual slow programs by itself.

What it does contain is by-source aggregate data:

| Source | Measured pairs | Applied programs | Exec ratio geomean |
| --- | ---: | ---: | ---: |
| `calico` | `59` | `54` | `0.7557543207447964` |
| `tetragon` | `10` | `9` | `1.2080898456649063` |
| `katran` | `5` | `0` | `1.08895321224139` |
| `tracee` | `4` | `4` | `0.549851650576271` |

Source: `corpus/results/vm_corpus_20260326_174240/metadata.json:735-939`

This is useful for source-level direction, but not for selecting individual programs.

## 4. Fallback per-program timing data

Because the March 26 artifact has no checked-in detail rows here, the best local fallback is the older per-program artifact:

- `corpus/results/corpus_authoritative_20260320.json`

That file does contain per-program `baseline_run.sample.exec_ns`, and among the requested families the slowest rows are:

| Source | Object | Program | Baseline `exec_ns` |
| --- | --- | --- | ---: |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `729` |
| `calico` | `corpus/build/calico/xdp_debug.bpf.o` | `calico_xdp_drop` | `389` |
| `calico` | `corpus/build/calico/xdp_debug.bpf.o` | `calico_xdp_main` | `211` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_main` | `186` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_main` | `177` |
| `katran` | `corpus/build/katran/balancer.bpf.o` | `balancer_ingress` | `52` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_ingress` | `24` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_egress` | `24` |

Implications:

- The only clearly `>100 ns` corpus candidates in these families are Calico.
- Katran and Tracee corpus rows are still too short for `ktime`-based `exec_ns` to be trustworthy.
- I do not have comparable per-program Tetragon corpus rows from the March 26 artifact in this checkout.

## 5. Which programs are the best candidates?

### Strictly within the corpus

#### Best timing candidates

These are the slow-enough corpus programs, but they are weak `map_inline` demonstrations:

1. `calico_tc_skb_new_flow_entrypoint` (`729 ns`)
2. `calico_xdp_drop` (`389 ns`)
3. `calico_xdp_main` (`211 ns`)
4. `calico_tc_main` (`186 ns`, `177 ns`)

Why they are weak:

- Calico does have some constant-key singleton state lookups, e.g. `state_get()` / `state_get_globals_*()` from `cali_state`, but that map is `BPF_MAP_TYPE_PERCPU_ARRAY`: `runner/repos/calico/felix/bpf-gpl/jump.h:19-45`
- The hot-path logic is dominated by dynamic map work such as route lookups in an `LPM_TRIE`, conntrack/NAT hash lookups, Maglev, QoS, etc.: for example `cali_rt_lookup()` in `runner/repos/calico/felix/bpf-gpl/routes.h:46-69`
- That is not the clean v1 `ARRAY + constant key + fixed-offset load` pattern described in the design doc: `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md:5-12`, `:27-45`

Expected outcome:

- Calico can show measurable runtime movement because it is slow enough.
- But any observed speedup would be hard to attribute specifically to `map_inline`, and might be small if the inlineable part is not on the hot path.

#### Best mechanism candidates

These are the clearest `map_inline` stories, but they are too fast:

1. Katran `pktcntr`
2. Tracee `cgroup_skb_ingress`
3. Tracee `cgroup_skb_egress`

Evidence:

- Katran `pktcntr` has a constant-key `ARRAY` lookup on `ctl_array[0]`: `runner/repos/katran/katran/lib/bpf/xdp_pktcntr.c:31-61`
- Tracee uses singleton `ARRAY` config maps such as `config_map` / `netconfig_map`: `runner/repos/tracee/pkg/ebpf/c/maps.h:80-128`
- Tracee program context setup reads `event_data_map[0]` and `config_map[0]`: `runner/repos/tracee/pkg/ebpf/c/common/context.h:123-132`
- Tracee `cgroup_skb_*` entrypoints are real checked-in `map_inline` hits with large code shrink: `docs/tmp/20260326/map_inline_3hits_analysis_20260326.md:32-43`

But the timings remain tiny:

- `tracee:cgroup_skb_ingress` and `egress` were measured around `13-18 ns` in prior isolated validation: `docs/tmp/20260326/map_inline_performance_validation_20260326.md:33-56`
- Katran `pktcntr` was even smaller and clearly noise-dominated: `docs/tmp/20260326/katran_map_inline_perf_test_20260326.md:20-35`, `:59-63`

### Best overall candidate outside the corpus

If the goal is to demonstrate a significant `map_inline` speedup, the strongest checked-in candidate is Tetragon attach-mode `event_exit_acct`, not a corpus program:

- source entrypoint: `runner/repos/tetragon/bpf/process/bpf_exit.c:46-53`
- known map usage on this path includes `execve_map_get_noinit(...)` and `exit_heap_map[0]`: `runner/repos/tetragon/bpf/process/bpf_exit.h:24-77`
- prior analysis reported `177 -> 121` instructions, with `1` `map_inline` site and `49` downstream DCE eliminations: `docs/tmp/20260326/map_inline_perf_post_fix_20260326.md:141-161`
- prior analysis also reported baseline single-run cost around `6,585.67 ns`: `docs/tmp/20260326/recompile_overhead_analysis_20260326.md:114-126`

Why this matters:

- `6.59 us` is no longer in the `ktime` sub-resolution regime.
- The runner would measure this path with `bpf_stats` + `rdtsc`, not `TEST_RUN` `duration`.
- This is the first checked-in case where the program is both slow enough and known to have a real `map_inline` hit.

Current blocker:

- the latest checked-in E2E note says REJIT still failed verifier for `event_exit_acct`, so there is no stable post-REJIT runtime comparison yet: `docs/tmp/20260327/vm_e2e_perf_passes_results_20260327.md:67-88`

## 6. What is the theoretical benefit of eliminating `bpf_map_lookup_elem`?

The main trap here is overestimating lookup cost by assuming every map lookup pays the full generic helper + vtable path.

### Generic helper path

The generic helper is just:

- `return map->ops->map_lookup_elem(map, key);`
- `vendor/linux-framework/kernel/bpf/helpers.c:44-57`

But for JITed 64-bit programs, the verifier often patches `BPF_FUNC_map_lookup_elem` into map-specific logic:

- if `ops->map_gen_lookup` exists, the verifier emits map-specific lookup instructions instead of the generic helper path
- otherwise it patches directly to `ops->map_lookup_elem`
- `vendor/linux-framework/kernel/bpf/verifier.c:24283-24325`, `:24348-24352`

### `ARRAY` map lookup cost

For `ARRAY`, the kernel already has a short inlineable lookup sequence:

- load key
- bounds check
- optional mask
- scale by element size
- add base pointer
- null on fail

Source:

- C helper body: `vendor/linux-framework/kernel/bpf/arraymap.c:167-176`
- generated BPF lookup sequence: `vendor/linux-framework/kernel/bpf/arraymap.c:219-248`

That generated sequence is only about `7` BPF instructions in the common non-inner-map case.

Practical interpretation:

- A raw `ARRAY` lookup elimination by itself is probably not a `15-30 ns` win on a hot JITed path.
- A more realistic expectation is:
  - low tens of cycles, or
  - low single-digit nanoseconds to maybe around `10 ns`, depending on CPU and cache state.

So the large win is usually not the lookup itself. The large win is the cascade:

- remove the lookup result load(s)
- make a branch constant
- remove null-checks / comparisons
- unlock DCE on whole blocks

That matches the empirical evidence:

- Katran: `22 -> 12` insns with only one inline site
- Tracee cgroup-skb: `3602 -> 3203`
- Tetragon `event_exit_acct`: `177 -> 121`, with `49` DCE eliminations after one inline

### `HASH` map lookup cost

For hash maps, the kernel path is much heavier:

- compute `jhash` / `jhash2`: `vendor/linux-framework/kernel/bpf/hashtab.c:674-679`
- select bucket: `vendor/linux-framework/kernel/bpf/hashtab.c:681-688`
- walk nulls hlist and `memcmp` keys: `vendor/linux-framework/kernel/bpf/hashtab.c:709-724`
- the BPF-side `map_gen_lookup` still emits a call to `__htab_map_lookup_elem` plus a null check and pointer fixup: `vendor/linux-framework/kernel/bpf/hashtab.c:732-785`

Practical interpretation:

- A hot hash lookup can plausibly cost tens of nanoseconds.
- `50-100 ns` is a defensible upper-bound heuristic for a hot-cache, non-trivial hash lookup, but I would treat it as an estimate, not something proved directly by source inspection.
- Unlike `ARRAY`, `HASH` has enough intrinsic work that full elimination could be large.

But the design caveat matters:

- v1 explicitly focuses the strongest form of inlining on constant-key `ARRAY` maps and excludes the general `HASH/LRU_HASH/LPM/PERCPU_*` case: `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md:7-12`, `:27-45`

So the best near-term performance story is still:

- use `ARRAY` cases where the inline triggers const-prop/DCE,
- not “we removed a whole expensive hash lookup.”

## 7. Recommended measurement strategy

### If restricted to corpus

Use corpus only to find programs that are slow enough, but do not expect a clean `map_inline` story from the current Calico-heavy slow set.

Recommended ordering:

1. Treat Calico as a timing feasibility check, not the headline demo.
2. Use `exec_cycles` and perf `instructions` / `cycles` as primary metrics.
3. Keep `exec_ns` as secondary evidence only.

### If allowed to use the best real target

Use attach-mode Tetragon `event_exit_acct` once verifier acceptance is fixed.

Why:

- already known `map_inline` hit
- already known large instruction shrink
- baseline is in microseconds, not low tens of nanoseconds
- attach path uses `bpf_stats` plus `rdtsc`, which is much more suitable here

### Metrics to report

For `TEST_RUN` programs:

1. `exec_cycles` as the primary steady-state metric
2. perf `instructions`
3. perf `cycles`
4. derived IPC / cycles-per-invocation
5. `exec_ns` only as a secondary, noisy indicator

For attach-mode programs:

1. `bpf_stats` `exec_ns`
2. `exec_cycles`
3. perf `instructions` / `cycles`
4. `run_cnt_delta` to prove the average is based on enough samples

### Experimental shape

Use paired same-image stock vs REJIT runs and avoid comparing a single low-ns median.

Recommended setup:

1. Hold program, object, workload, CPU placement, and repeat fixed.
2. Use enough repeat/workload so the total measured work dwarfs fixed syscall overhead.
3. Compare ratios on `exec_cycles` and perf `instructions` first.
4. Only claim an `exec_ns` win when the signal is clearly above integer-ns quantization noise.

### What I would present as the paper/demo story

1. Mechanism proof:
   `map_inline` removes a constant-key config lookup and triggers a large const-prop/DCE cascade.
2. Tiny-program caution:
   low-ns `TEST_RUN` programs are structurally improved, but `ktime` `exec_ns` is too quantized to show it cleanly.
3. Real performance demo:
   use a slower attach-mode Tetragon target such as `event_exit_acct`, measured with `bpf_stats` + `exec_cycles`.

## Bottom line

If the question is strictly “which current corpus programs are slow enough?”, the answer is “mostly Calico, and those are poor `map_inline` showcases.”

If the question is “what is the best way to demonstrate significant `map_inline` speedup?”, the answer is:

- do not rely on integer `TEST_RUN exec_ns` for 5-20 ns programs,
- use `exec_cycles` / perf counters for tiny `TEST_RUN` cases,
- and prefer a slower attach-mode Tetragon program, especially `event_exit_acct`, for the actual headline demonstration.
