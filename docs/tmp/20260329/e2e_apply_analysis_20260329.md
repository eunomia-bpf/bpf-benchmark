# 2026-03-29 E2E apply analysis

## Scope and method

Latest directories selected from `ls -lt e2e/results/`:

- `bcc`: `e2e/results/bcc_20260329_085144`
- `bpftrace`: `e2e/results/bpftrace_20260329_083931`
- `katran`: `e2e/results/katran_20260329_085002`
- `scx`: `e2e/results/scx_20260329_084651`
- `tetragon`: `e2e/results/tetragon_20260329_083750`
- `tracee`: `e2e/results/tracee_20260329_081351`

Primary data source per case:

- `metadata.json`
- `details/result.json`

Metric definitions used below:

- `total programs`: actual `rejit_result.per_program` entries, not tool/script count
- `applied_flag`: per-program `applied == true`, meaning the daemon produced an apply result for that program
- `changed programs`: `summary.program_changed == true`
- `applied sites`: `summary.total_sites_applied`
- `insn before/after`: `debug_result.program.orig_insn_count` and `debug_result.program.final_insn_count`

Important distinction:

- `applied_flag` is not the same as "really changed bytecode"
- several cases have `applied_flag = true` but `program_changed = false` or `total_sites_applied = 0`

Shorthand used in program summaries:

- `mi` = `map_inline`
- `cp` = `const_prop`
- `dce` = `dce`
- `bm` = `bulk_memory`
- `wm` = `wide_mem`
- `ex` = `extract`
- `ef` = `endian_fusion`

## One-page summary

For cyclic cases, counts are reported per cycle unless noted otherwise.

| case | latest dir | total BPF programs | applied_flag | changed programs | applied sites | scanned sites | headline |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `bcc` | `bcc_20260329_085144` | 36 | 36 | 28 | 651 | 1016 | BPF geomean `1.015x` |
| `bpftrace` | `bpftrace_20260329_083931` | 12 | 12 | 3 | 14 | 22 | BPF geomean `1.140x` |
| `katran` | `katran_20260329_085002` | 1 live program/cycle (`3` instances total) | 1/cycle | 1/cycle | 19/cycle | 19/cycle | BPF `1.022x`, app throughput `+1.78%` |
| `scx` | `scx_20260329_084651` | 13 | 2 | 2 | 202 | 732 | `hackbench +54.6%` |
| `tetragon` | `tetragon_20260329_083750` | 8 discovered, 2 selected for apply | 1 | 0 | 0 | 99 | not comparable |
| `tracee` | `tracee_20260329_081351` | 13/cycle (`5` cycles, identical footprint) | 13/cycle | 10/cycle | 851/cycle | 1868/cycle | app deltas small / insignificant |

## Kinsn modules

结论：`kinsn` modules 对这批 E2E 结果是已加载的。

Evidence chain:

- `runner/libs/vm.py` always prefixes guest commands with `module/load_all.sh`, so every VM guest command loads kinsn modules before running the case.
- `module/load_all.sh` loads all arch-specific kinsn modules except `bpf_barrier`, then prints `kinsn modules: ${loaded}/${total} loaded`.
- same-day VM corpus logs show the expected load sequence: `Loaded bpf_bulk_memory`, `Loaded bpf_endian`, `Loaded bpf_extract`, `Loaded bpf_rotate`, `Loaded bpf_select`, then `kinsn modules: 5/5 loaded`.
- captured E2E daemon stderr logs show `kinsn discovery:` followed by `bpf_rotate64`, `bpf_select64`, `bpf_extract64`, `bpf_memcpy_bulk`, and `bpf_endian_load16/32/64`.

Inference note:

- the per-case `metadata.json` files here are artifact summaries and do not embed the guest stdout/stderr directly
- so the "kinsn loaded" conclusion is inferred from shared VM launcher code plus same-day VM/daemon logs, not from a case-local boot log inside each `metadata.json`

## bcc

### Summary

- 36 programs all entered apply, and 28 of them really changed.
- 651 of 1016 scanned sites landed.
- changed programs sum to `5434 -> 4018` instructions, net `-1416`.
- headline BPF geomean is only `1.015x`, so this is a coverage-good / workload-coupling-weak case.

Tool-level summary:

| tool | programs | changed | applied sites | BPF speedup |
| --- | ---: | ---: | ---: | ---: |
| `tcplife` | 1 | 1 | 39 | `1.012x` |
| `biosnoop` | 4 | 4 | 50 | `1.291x` |
| `runqlat` | 3 | 3 | 62 | `1.016x` |
| `syscount` | 2 | 2 | 65 | `0.996x` |
| `execsnoop` | 2 | 2 | 67 | `0.996x` |
| `opensnoop` | 6 | 6 | 129 | `0.870x` |
| `capable` | 2 | 2 | 57 | `1.013x` |
| `vfsstat` | 8 | 0 | 0 | `1.008x` |
| `tcpconnect` | 4 | 4 | 76 | `0.951x` |
| `bindsnoop` | 4 | 4 | 106 | `1.047x` |

Applied program details:

- `tcplife`: `2527 inet_sock_set_s [39 = mi12 + cp7 + dce20, 309 -> 261]`
- `biosnoop`: `2869 block_io_start [5 = mi1 + cp1 + dce3, 31 -> 23]`; `2871 blk_account_io_ [5 = mi1 + cp1 + dce3, 31 -> 23]`; `2872 block_rq_issue [26 = mi6 + cp6 + dce14, 165 -> 69]`; `2873 block_rq_comple [14 = mi3 + cp2 + dce9, 136 -> 99]`
- `runqlat`: `2936 sched_wakeup [10 = mi3 + cp2 + dce5, 32 -> 20]`; `2938 sched_wakeup_ne [10 = mi3 + cp2 + dce5, 32 -> 20]`; `2939 sched_switch [42 = mi8 + cp8 + dce26, 261 -> 171]`
- `syscount`: `3000 sys_enter [10 = mi3 + cp2 + dce5, 31 -> 18]`; `3002 sys_exit [55 = mi10 + cp11 + dce34, 120 -> 52]`
- `execsnoop`: `3064 tracepoint__sys [63 = mi63, 2236 -> 2236]`; `3066 tracepoint__sys [4 = mi4, 64 -> 64]`
- `opensnoop`: `3128 tracepoint__sys [23 = mi6 + cp3 + dce14, 46 -> 19]`; `3130 tracepoint__sys [23 = mi6 + cp3 + dce14, 46 -> 19]`; `3131 tracepoint__sys [23 = mi6 + cp3 + dce14, 56 -> 29]`; `3132 tracepoint__sys [20 = mi2 + cp4 + dce14, 213 -> 70]`; `3133 tracepoint__sys [20 = mi2 + cp4 + dce14, 213 -> 70]`; `3134 tracepoint__sys [20 = mi2 + cp4 + dce14, 213 -> 70]`
- `capable`: `3195 kprobe__cap_cap [17 = mi4 + cp2 + dce11, 38 -> 20]`; `3197 kprobe__cap_cap [40 = mi7 + cp9 + dce22 + ex2, 142 -> 57]`
- `vfsstat`: 8 programs, `0` sites, `0` code changes
- `tcpconnect`: `3327 tcp_v4_connect [13 = mi4 + cp2 + dce7, 32 -> 18]`; `3329 tcp_v4_connect_ [25 = mi6 + cp8 + dce11, 171 -> 84]`; `3330 tcp_v6_connect [13 = mi4 + cp2 + dce7, 32 -> 18]`; `3331 tcp_v6_connect_ [25 = mi6 + cp8 + dce11, 174 -> 84]`
- `bindsnoop`: `3393 ipv4_bind_entry [12 = mi3 + cp2 + dce7, 30 -> 15]`; `3395 ipv4_bind_exit [41 = mi3 + cp9 + dce26 + ex2 + ef1, 275 -> 187]`; `3396 ipv6_bind_entry [12 = mi3 + cp2 + dce7, 30 -> 15]`; `3397 ipv6_bind_exit [41 = mi3 + cp9 + dce26 + ex2 + ef1, 275 -> 187]`

Why the improvement stays small:

- this is not an apply-coverage problem; the suite already landed `651` sites on `28` programs
- it is mostly a hotness / measurement-composition problem: many tools spend substantial time outside the rewritten BPF path
- concrete examples: `biosnoop` gets `1.291x` BPF speedup yet workload ops still fall; `opensnoop` lands `129` sites but regresses to `0.870x`; `tcpconnect` lands `76` sites and still shows `0.951x`

## bpftrace

### Summary

- 12 programs all produced apply results, but only 3 programs really changed.
- only `14` of `22` scanned sites landed.
- headline BPF geomean is `1.140x`, but that number is mostly a `tcplife` outlier and not a successful apply story.

Script-level summary:

| script | programs | changed | applied sites | BPF speedup |
| --- | ---: | ---: | ---: | ---: |
| `tcplife` | 1 | 0 | 0 | `1.941x` |
| `biosnoop` | 2 | 1 | 5 | `0.962x` |
| `runqlat` | 3 | 0 | 0 | `0.981x` |
| `tcpretrans` | 1 | 1 | 3 | `n/a` |
| `capable` | 1 | 1 | 6 | `1.051x` |
| `vfsstat` | 4 | 0 | 0 | `0.999x` |

Applied program details:

- `biosnoop`: only `1128 block_io_done [5 = mi1 + wm4, 181 -> 163]` changed; sibling `1127 block_io_start` did not
- `tcpretrans`: `1252 tcp_retransmit_ [3 = wm3, 191 -> 182]`
- `capable`: `1313 cap_capable [6 = wm6, 156 -> 138]`

Notable no-op / rejected items:

- `tcplife`: `1066 tcp_set_state`, `8` `wide_mem` sites scanned, `0` applied, `401 -> 401`
- on `tcplife`, `wide_mem` was verifier-rejected and `map_inline` sites were skipped for constant-key / fixed-offset / missing-key reasons
- `runqlat`'s 3 programs and `vfsstat`'s 4 programs had `0` sites

Why `bpftrace 1.14x` looks good:

- the summary number is dominated by `tcplife = 1.941x`
- but `tcplife` had `0` successful sites and `0` instruction change, so that headline is not caused by successful apply
- if `tcplife` is removed, the geomean of scripts with numeric speedups drops to `0.998x`
- if only scripts with real code changes are kept, the geomean is only about `1.005x`

Bottom line:

- `bpftrace` does not have a "many sites landed and all got faster" story
- it has a small real apply footprint (`14` sites total), one modest positive case (`capable`), one negative case (`biosnoop`), and one big non-causal outlier (`tcplife`)

## katran

### Summary

- there is one live XDP program per paired cycle, and all three cycles are effectively identical
- each cycle lands `19` sites on `balancer_ingress`
- each cycle shrinks only `2542 -> 2523`, net `-19` instructions
- headline is BPF `1.022x`, with app throughput `+1.78%`

Per-cycle details:

| cycle | prog_id | program | applied sites | passes | insn before/after |
| --- | ---: | --- | ---: | --- | --- |
| `0` | 1777 | `balancer_ingress` | 19 | `mi6 + dce7 + wm4 + ef2` | `2542 -> 2523` |
| `1` | 2027 | `balancer_ingress` | 19 | `mi6 + dce7 + wm4 + ef2` | `2542 -> 2523` |
| `2` | 2277 | `balancer_ingress` | 19 | `mi6 + dce7 + wm4 + ef2` | `2542 -> 2523` |

What the pass trace says:

- `map_inline` applied `6` sites but skipped `64` more, mostly because `PERCPU_ARRAY value differs across CPUs`, non-constant keys, non-fixed-offset loads, unsupported map types, or mutable uses
- `rotate` and `cond_select` found candidates but did not apply
- the explicitly whitelisted katran-specific risky transforms are very small: the policy file allows only `4` `wide-load-2` sites and `2` `endian-load-swap-32` sites, while `2` `endian-swap-store-16` sites are intentionally excluded because they previously caused timeouts

Why `katran 1.022x` is small:

- code shrink is tiny: `-19` instructions on a `2542`-instruction XDP program, only about `0.75%`
- the measured BPF improvement is also tiny: `bpf_avg_ns_per_run_delta_pct = -2.17%`
- that BPF path is only one component in the full request path, so it turns into only `+1.78%` app throughput
- the safe policy is deliberately conservative, so katran is operating with limited rewrite surface by design

## scx

### Summary

- 13 scheduler programs were discovered
- only 2 programs successfully applied and changed
- those 2 programs landed `202` of `732` scanned sites
- the other 11 programs failed at `BPF_PROG_GET_FD_BY_ID(...): No such file or directory`

Successful applied programs:

| prog_id | program | applied sites | passes | insn before/after |
| --- | --- | ---: | --- | --- |
| `1739` | `rusty_select_cpu` | 32 | `mi8 + cp6 + dce18` | `733 -> 634` |
| `1741` | `rusty_enqueue` | 170 | `mi30 + cp51 + dce89` | `2194 -> 1408` |

Failed after scan:

- `1742 rusty_dispatch [32 sites]`
- `1743 rusty_runnable [45 sites]`
- `1744 rusty_running [9 sites]`
- `1745 rusty_stopping [6 sites]`
- `1746 rusty_quiescent [45 sites]`
- `1747 rusty_set_weight [6 sites]`
- `1748 rusty_set_cpumask [166 sites]`
- `1749 rusty_init_task [177 sites]`
- `1750 rusty_exit_task [6 sites]`
- `1751 rusty_init [32 sites]`
- `1752 rusty_exit [6 sites]`

That failed set leaves `530` scanned sites unapplied.

Workload deltas:

| workload | throughput delta |
| --- | ---: |
| `hackbench` | `+54.59%` |
| `stress-ng-cpu` | `+0.15%` |
| `sysbench-cpu` | `-0.19%` |

Why `scx +54.6%` is real:

- unlike `bpftrace`, the big number here lines up with real code changes on hot paths
- `rusty_enqueue` is the hottest scheduler path in this workload, and it alone shrinks from `2194 -> 1408`
- `rusty_select_cpu` also shrinks meaningfully, `733 -> 634`
- `hackbench` is scheduler-sensitive and pounds exactly these paths, so concentrated wins on these two programs translate into a large end-to-end gain

Why the result is still incomplete:

- coverage is narrow: only `2/13` programs changed
- 11 programs failed before apply with `GET_FD_BY_ID`
- especially large missed opportunities remain in `rusty_set_cpumask` (`166` sites) and `rusty_init_task` (`177` sites)

## tetragon

### Summary

- 8 programs were discovered, but only 2 were selected for apply in this run
- 1 program produced an apply result with no code change
- 1 program failed outright
- final result is correctly marked `not comparable`

Program details:

- `985 execve_rate`: `12` scanned sites, `0` applied, `241 -> 241`
  - `map_inline` tried `2` sites but verifier rejected them
  - skips/rejections are dominated by `PERCPU_ARRAY value differs across CPUs`, non-fixed-offset scalar loads, and non-inlineable map types
  - `bulk_memory` also skipped one site due alias-safety
- `987 event_execve`: `87` scanned sites, no final output program
  - daemon error is `BPF_PROG_REJIT: Invalid argument (os error 22)`
  - daemon warnings show pass-level skips on `map_inline` and `const_prop`, then final REJIT failure

Why there is no improvement story:

- there are candidate sites (`99` total), but none become a stable changed program
- `execve_rate` is blocked by verifier rejection
- `event_execve` fails in final REJIT

## tracee

### Summary

- cycle `0` is representative; all 5 paired cycles have the same apply footprint
- per cycle, 13 programs produce apply results, 10 really change, and 851 of 1868 scanned sites land
- despite that large footprint, app-level deltas stay small and statistically insignificant

Workload deltas:

| workload | app throughput mean pct delta | p-value | significant |
| --- | ---: | ---: | --- |
| `exec_storm` | `+3.09%` | `0.1875` | `false` |
| `file_io` | `+1.71%` | `0.1875` | `false` |
| `network` | `-0.65%` | `0.3125` | `false` |

Changed programs in cycle `0`:

- `19 sys_enter_init [42 = cp12 + dce30, 579 -> 529]`
- `20 sys_enter_submit [104 = mi1 + cp32 + dce70 + bm1, 3773 -> 3632]`
- `22 sys_exit_init [39 = cp11 + dce28, 482 -> 435]`
- `23 sys_exit_submit [107 = cp31 + dce70 + bm1 + ex5, 2469 -> 2329]`
- `24 syscall__execve_enter [49 = mi1 + cp15 + dce33, 3956 -> 3903]`
- `25 syscall__execve_exit [49 = mi1 + cp15 + dce33, 3958 -> 3905]`
- `26 syscall__execveat_enter [54 = mi1 + cp17 + dce36, 4011 -> 3953]`
- `27 syscall__execveat_exit [54 = mi1 + cp17 + dce36, 4012 -> 3954]`
- `28 sys_dup_exit_tail [120 = mi1 + cp36 + dce81 + bm2, 2342 -> 2188]`
- `29 tracepoint__sched__sched_process_fork [233 = mi1 + cp74 + dce157 + bm1, 4042 -> 3674]`

Notable non-changes:

- `17 tracepoint__raw_syscalls__sys_enter`: `0` applied sites, `29 -> 29`
- `21 tracepoint__raw_syscalls__sys_exit`: `0` applied sites, `36 -> 36`
- `33 lkm_seeker_modtree_loop`: `1022` scanned sites, `0` applied, `14236 -> 14236`
  - this single program accounts for about `54.7%` of all scanned sites in the cycle
  - `map_inline`, `const_prop`, and `dce` all hit verifier rejection here

Why the improvement stays small:

- tracee is the opposite of `scx`: it has broad apply coverage, but weaker workload coupling
- even across the 10 changed programs, the aggregate instruction count only moves from `29624 -> 28502`, net `-1122`
- many rewrites are spread across large `2k` to `4k` instruction programs, so each individual hot-path shortening is modest
- the biggest site-bearing program, `lkm_seeker_modtree_loop`, rejects completely, removing the largest potential upside from the run
- measured app deltas are also noisy enough that none of the three workloads reach statistical significance

## Bottom line

- `scx` is the cleanest "real improvement" case: a small number of heavily exercised scheduler programs changed a lot, and `hackbench` moved a lot.
- `katran` is small because the policy is conservative and the actual code shrink is only `19` instructions per cycle.
- `bpftrace`'s `1.14x` headline looks strong but is mostly carried by `tcplife`, which did not successfully apply any site.
- `bcc` and `tracee` both show that landing many sites is not enough by itself; if the rewritten BPF paths are not dominant in the end-to-end workload, the visible gain stays small.
