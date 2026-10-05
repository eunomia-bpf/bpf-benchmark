# Tracee Regression Analysis (2026-04-24)

## Scope

Target run: `e2e/results/tracee_20260424_034316_100164`

- `result.md` reports `app_delta_mean = -2.5237%`, `event_delta_mean = -4.0585%`, `app_p = 1.0`
- Summary means in `result.json` are `5023.1 -> 4700.2 ops/s` (`-6.43%`), `15600.9 -> 14967.8 events/s` (`-4.06%`), `221.0 -> 228.8 ns` (`+3.54%`)
- The `-2.5%` number is the paired-cycle delta mean; the `-6.43%` number is the ratio of phase means. Both are in the artifact.

## 1. What ReJIT actually applied

From `result.json -> rejit_result["0"]` and `metadata.json -> optimization_summary -> rejit_result["0"]`:

- Requested programs: `158`
- Applied successfully: `157`
- Not applied: `1`
- Changed programs: `122`
- Total touched sites: `2073`
- One program failed apply: `syscall__init_module` (`prog_id=113`, `BPF_PROG_REJIT: Invalid argument`)

Kept pass coverage across changed programs:

| pass | programs | kept sites |
| --- | ---: | ---: |
| `map_inline` | 108 | 140 |
| `dce` | 98 | 1299 |
| `bulk_memory` | 99 | 109 |
| `const_prop` | 15 | 298 |
| `wide_mem` | 5 | 181 |
| `extract` | 9 | 37 |
| `endian_fusion` | 2 | 4 |
| `cond_select` | 1 | 1 |
| `rotate` | 0 | 0 |

Observations:

- The hot-path cluster is overwhelmingly `map_inline + dce + bulk_memory`
- `rotate` never actually applied
- `cond_select` is negligible

## 2. Which programs slowed down

Only `64` programs had comparable benchmark-time `bpf_stats` in `comparison.programs`; the rest were cold in this workload. Among those `64`, `52` were changed and `12` were unchanged.

### Top slowed changed programs

Approximate impact below uses `delta_ns * baseline run_cnt_delta` as a weighting proxy.

| program | passes kept | sites | stock ns | rejit ns | delta | approx added time |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `trace_sys_enter` | `map_inline,dce,bulk_memory` | 3 | 195.58 | 211.40 | `+8.09%` | `+30.46 ms` |
| `trace_sys_exit` | `map_inline,dce,bulk_memory` | 3 | 173.25 | 187.61 | `+8.29%` | `+27.66 ms` |
| `tracepoint__sched__sched_switch` | `map_inline,dce,bulk_memory` | 6 | 253.35 | 263.23 | `+3.90%` | `+15.08 ms` |
| `cgroup_bpf_run_filter_skb` | `map_inline,const_prop,dce,bulk_memory` | 63 | 298.31 | 324.34 | `+8.73%` | `+7.80 ms` |
| `trace_ret_sock_alloc_file` | `const_prop,dce,bulk_memory` | 99 | 329.59 | 410.23 | `+24.47%` | `+4.75 ms` |
| `trace_ret_vfs_write` | `map_inline,bulk_memory` | 2 | 214.72 | 230.19 | `+7.20%` | `+1.68 ms` |
| `trace_fd_install` | `map_inline,dce,bulk_memory` | 40 | 328.25 | 340.68 | `+3.79%` | `+1.36 ms` |
| `trace_ret_do_mmap` | `map_inline,dce,bulk_memory` | 12 | 496.83 | 509.73 | `+2.60%` | `+1.10 ms` |

These are the main modified-program regressors. The dominant pattern is not `wide_mem` or `extract`; it is the `map_inline + dce + bulk_memory` cluster on very hot entry/exit programs.

### Important: hot unchanged programs also slowed down

This matters because it means the post-rejit slowdown is not explained purely by transformed programs.

| program | changed? | stock ns | rejit ns | delta | approx added time |
| --- | --- | ---: | ---: | ---: | ---: |
| `tracepoint__raw_syscalls__sys_exit` | no | 264.98 | 294.56 | `+11.17%` | `+56.99 ms` |
| `tracepoint__raw_syscalls__sys_enter` | no | 156.95 | 165.29 | `+5.31%` | `+16.05 ms` |

These two untouched raw tracepoints alone contribute about `+73 ms` of weighted added BPF time. That is too large to ignore and strongly suggests run-level/system-level variance in the post-rejit phase.

## 3. Pass and rollback analysis

### Verifier rollback exists, and it is mostly `const_prop`

Programs with verifier rollback attempts: `113`

Rollback distribution:

| pass | programs with rollback | rollback entries | rollback sites |
| --- | ---: | ---: | ---: |
| `const_prop` | 106 | 189 | 6538 |
| `dce` | 19 | 19 | 370 |
| `map_inline` | 9 | 9 | 77 |
| `bulk_memory` | 8 | 8 | 10 |
| `wide_mem` | 2 | 2 | 6 |

Notes:

- The hottest slowed changed programs (`trace_sys_enter`, `trace_sys_exit`, `sched_switch`) all saw `const_prop` rollback attempts, then kept `map_inline + dce + bulk_memory`
- This makes `const_prop` a likely interaction risk, but not a run-specific explanation: the same rollback pattern also appears in earlier positive runs

### Does a specific pass explain this regression?

Evidence against a simple “pass X broke this run” theory:

- `tracee_20260424_034316_100164`, `tracee_20260424_020311_620228`, and `tracee_20260423_225754_021437` have the same enabled pass set
- Flattening `rejit_result["0"]` shows the same transformed program set and the same pass/site/rollback profile across those runs
- Yet the paired app delta swings from `+16.17%` (`020311`) and `+12.55%` (`225754`) to `-2.52%` (target)

So:

- `wide_mem` is not the primary suspect: only 5 programs, modest impact, no code-size growth
- `rotate` and `cond_select` are effectively irrelevant here
- If a pass-level bisect is still needed, start with `map_inline`, `dce`, and `bulk_memory` on `trace_sys_enter`, `trace_sys_exit`, `sched_switch`
- Treat `const_prop` as an interaction suspect because of rollback frequency, not because this run uniquely changed its behavior

## 4. Code size / I-cache hypothesis

There is no evidence that this regression came from code-size growth.

- Changed programs: `122`
- Instruction count increased: `0`
- Instruction count unchanged: `8`
- Instruction count decreased: `114`

Largest shrinks:

- `cgroup_skb_ingress`: `3603 -> 2935` (`-668 insns`)
- `cgroup_skb_egress`: `3603 -> 2935` (`-668 insns`)
- `trace_ret_sock_alloc_file`: `1674 -> 1504` (`-170 insns`)
- `cgroup_bpf_run_filter_skb`: `1086 -> 942` (`-144 insns`)

Conclusion:

- A pure I-cache-pressure explanation from bigger code is not supported
- If there is a microarchitectural regression, it is more likely due to changed JIT code shape on hot paths than due to larger programs

## 5. Comparison to earlier positive runs

### `tracee_20260424_020311_620228`

- Paired app delta mean: `+16.17%`
- Paired BPF delta mean: `+2.56%`
- Same `rejit_result` profile as target

### `tracee_20260423_225754_021437`

- Paired app delta mean: `+12.55%`
- Paired BPF delta mean: `-1.00%`
- Same `rejit_result` profile as target

### What changed in the target run

The target run is dominated by pair-level variance:

- Cycle 0: ops `4392.3 -> 5647.2` (`+28.57%`), BPF `217.7 -> 233.2 ns` (`+7.11%`)
- Cycle 1: ops `5653.9 -> 3753.3` (`-33.62%`), BPF `224.3 -> 224.5 ns` (`+0.08%`)

This is the strongest signal in the data:

- The bad cycle's throughput collapsed while BPF average latency was essentially flat
- `app_p = 1.0` in the paired significance test
- That means the reported app regression is not statistically convincing, and it is not tightly coupled to the measured BPF slowdown

## Conclusion

Most likely root cause:

1. There is a mild BPF slowdown on several hot modified programs, especially `trace_sys_enter`, `trace_sys_exit`, and `sched_switch`, all using `map_inline + dce + bulk_memory`
2. But the overall app regression in `tracee_20260424_034316_100164` is primarily benchmark variance / post-rejit phase instability, not a new deterministic transform difference
3. The strongest evidence is that untouched hot programs also slowed, the bad cycle had flat BPF latency, and earlier positive runs used an identical `rejit_result`

## Recommended next steps

1. Increase tracee paired-cycle count beyond `2` before gating on app delta; with two pairs and opposite-sign outcomes, the benchmark is too noisy.
2. Add a control measurement after the daemon/reload step but before ReJIT changes take effect, to separate “reload/system perturbation” from “optimized program effect”.
3. Bisect `map_inline`, `dce`, and `bulk_memory` specifically on `trace_sys_enter`, `trace_sys_exit`, and `tracepoint__sched__sched_switch`.
4. Add artifact output that explicitly compares changed vs unchanged hotspot programs; the untouched raw syscalls entry/exit probes are currently a major confounder.
5. Instrument rollback-heavy programs to record the final kept pipeline after `const_prop` rejection; rollback frequency is high enough that it deserves dedicated visibility.
