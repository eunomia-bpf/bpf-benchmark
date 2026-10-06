# Benchmark Inventory and Quality Audit

Audit date: 2026-03-12

This audit covers the current benchmark inventory under `config/`, `micro/`, `corpus/`, and `e2e/`, plus the latest result artifacts currently present in the repo.

## Headline Assessment

- The suite is broad on paper: `56` micro benchmarks across `9` categories, a `23`-project corpus with `560` measured object files and `2010` discovered programs, and `4` end-to-end cases.
- The strongest evidence is breadth of coverage and older micro/corpus llvmbpf-vs-kernel analyses.
- The weakest point is freshness/consistency of the canonical result artifacts:
  - the nominal latest micro result was only a `1/56` partial run and was deleted from the worktree during this audit;
  - the freshest full micro summary is older than the current manifest and misses `16` current benchmarks;
  - the freshest corpus llvmbpf-vs-kernel exec/code-size geomeans are from 2026-03-07, while the manifest and recompile batch were refreshed on 2026-03-11.
- The fresh corpus recompile batch is not yet convincing as a win: exec geomean `0.868x`, code-size geomean `0.999x`, `40` improvements versus `107` regressions over `163` measured pairs.
- End-to-end evidence is promising but still limited: `1` case is baseline-only, `1` is partial, and the `2` comparable daemon cases are smoke runs.

## Data Freshness

| Artifact | Path | Generated At |
| --- | --- | --- |
| micro partial result (captured before deletion) | `micro/results/pure_jit.latest.json` | `2026-03-11T23:28:06.063169+00:00` |
| micro full-suite summary | `micro/results/combined_40_summary.md` | `2026-03-08T20:17:15.075061+00:00` |
| corpus manifest | `corpus/config/corpus_manifest.yaml` | `2026-03-11T07:07:47` |
| fresh corpus recompile batch | `corpus/results/corpus_v5_vm_batch_full.json` | `2026-03-11T20:59:25.353666+00:00` |
| fresh tracing corpus inventory | `corpus/results/tracing_corpus_vm.json` | `2026-03-11T22:46:30.920751+00:00` |
| corpus llvmbpf-vs-kernel exec | `corpus/results/real_world_exec_time_v2.json` | `2026-03-07T23:50:39.411451+00:00` |
| corpus llvmbpf-vs-kernel code size | `corpus/results/real_world_code_size_v2.json` | `2026-03-07T23:08:42.939988+00:00` |
| e2e scx | `e2e/results/scx-e2e.json` | `2026-03-11T16:36:43.475678+00:00` |
| e2e bpftrace | `e2e/results/bpftrace-real-e2e.json` | `2026-03-11T16:38:36.319564+00:00` |
| e2e tracee | `e2e/results/tracee-e2e-real.json` | `2026-03-11T16:39:51.842923+00:00` |
| e2e tetragon | `e2e/results/tetragon-real-e2e.json` | `2026-03-11T17:29:08.953023+00:00` |

## 1. Micro Benchmarks

### Inventory

- Manifest: `config/micro_pure_jit.yaml`
- Declared benchmarks: `56`
- Categories: `9`
- Runtimes declared: `3` (`llvmbpf`, `kernel`, `kernel-recompile`)
- IO modes: `51` staged, `5` packet
- Kernel-only benchmarks: `3` (`tc_bitcount`, `tc_checksum`, `cgroup_hash_chain`)
- `python3 micro/run_micro.py --list 2>&1 | head -80` matched the manifest inventory and showed the same `56` benchmark names and `3` runtimes.

### Benchmarks By Category

| Category | Count | Families | Benchmarks |
| --- | ---: | --- | --- |
| baseline | 3 | baseline | simple, simple_packet, memory_pair_sum |
| alu-mix | 9 | popcount, log2-fold, mixed-alu-mem, packet-hash, mixed-width, rotate-hash, strength-reduce, hash-chain | bitcount, log2_fold, mixed_alu_mem, packet_rss_hash, alu32_64_pingpong, rotate64_hash, smallmul_strength_reduce, tc_bitcount, cgroup_hash_chain |
| dependency-ilp | 5 | dep-chain, spill-pressure, multi-acc | dep_chain_short, dep_chain_long, spill_pressure, multi_acc_4, multi_acc_8 |
| control-flow | 8 | search, branch-skew, switch-dispatch, branch-density, select-diamond, branch-fanout, deep-guards | binary_search, branch_layout, switch_dispatch, branch_dense, cmov_select, cmov_dense, branch_fanout_32, deep_guard_tree_8 |
| memory-local | 16 | reduction, load-width, causal-isolation, parser, bounds-density, bounds-style, stride-load, byte-compare, field-access, bitfield-extract | checksum, load_word32, load_byte, load_byte_recompose, load_native_u64, packet_parse, bounds_ladder, bounds_check_heavy, stride_load_4, stride_load_16, memcmp_prefix_64, packet_parse_vlans_tcpopts, packet_redundant_bounds, struct_field_cluster, bitfield_extract, tc_checksum |
| loop-shape | 6 | recurrence, fixed-loop, nested-loop | fibonacci_iter, fibonacci_iter_packet, fixed_loop_small, fixed_loop_large, nested_loop_2, nested_loop_3 |
| call-size | 2 | code-clone | code_clone_2, code_clone_8 |
| program-scale | 5 | large-mixed, immediate-stress, mega-block, const-fold | large_mixed_500, large_mixed_1000, imm64_storm, mega_basic_block_2048, const_fold_chain |
| call-overhead | 2 | bpf-local-call | bpf_call_chain, local_call_fanout |

### Families

| Family | Count | Category | Benchmarks |
| --- | ---: | --- | --- |
| baseline | 3 | baseline | simple, simple_packet, memory_pair_sum |
| popcount | 2 | alu-mix | bitcount, tc_bitcount |
| log2-fold | 1 | alu-mix | log2_fold |
| dep-chain | 2 | dependency-ilp | dep_chain_short, dep_chain_long |
| search | 1 | control-flow | binary_search |
| branch-skew | 1 | control-flow | branch_layout |
| switch-dispatch | 1 | control-flow | switch_dispatch |
| branch-density | 1 | control-flow | branch_dense |
| select-diamond | 2 | control-flow | cmov_select, cmov_dense |
| reduction | 2 | memory-local | checksum, tc_checksum |
| load-width | 2 | memory-local | load_word32, load_byte |
| causal-isolation | 2 | memory-local | load_byte_recompose, load_native_u64 |
| parser | 2 | memory-local | packet_parse, packet_parse_vlans_tcpopts |
| bounds-density | 2 | memory-local | bounds_ladder, packet_redundant_bounds |
| bounds-style | 1 | memory-local | bounds_check_heavy |
| stride-load | 2 | memory-local | stride_load_4, stride_load_16 |
| mixed-alu-mem | 1 | alu-mix | mixed_alu_mem |
| spill-pressure | 1 | dependency-ilp | spill_pressure |
| multi-acc | 2 | dependency-ilp | multi_acc_4, multi_acc_8 |
| recurrence | 2 | loop-shape | fibonacci_iter, fibonacci_iter_packet |
| fixed-loop | 2 | loop-shape | fixed_loop_small, fixed_loop_large |
| nested-loop | 2 | loop-shape | nested_loop_2, nested_loop_3 |
| code-clone | 2 | call-size | code_clone_2, code_clone_8 |
| large-mixed | 2 | program-scale | large_mixed_500, large_mixed_1000 |
| bpf-local-call | 2 | call-overhead | bpf_call_chain, local_call_fanout |
| byte-compare | 1 | memory-local | memcmp_prefix_64 |
| packet-hash | 1 | alu-mix | packet_rss_hash |
| immediate-stress | 1 | program-scale | imm64_storm |
| mixed-width | 1 | alu-mix | alu32_64_pingpong |
| branch-fanout | 1 | control-flow | branch_fanout_32 |
| deep-guards | 1 | control-flow | deep_guard_tree_8 |
| mega-block | 1 | program-scale | mega_basic_block_2048 |
| rotate-hash | 1 | alu-mix | rotate64_hash |
| const-fold | 1 | program-scale | const_fold_chain |
| field-access | 1 | memory-local | struct_field_cluster |
| bitfield-extract | 1 | memory-local | bitfield_extract |
| strength-reduce | 1 | alu-mix | smallmul_strength_reduce |
| hash-chain | 1 | alu-mix | cgroup_hash_chain |

### Latest Result State

At audit start, `micro/results/pure_jit.latest.json` existed and contained a partial run:

- generated_at: `2026-03-11T23:28:06.063169+00:00`
- benchmarks with data: `1 / 56` (`1.8%`)
- runtime rows with data: `1`
- measured benchmark: `simple`
- measured runtime: `llvmbpf` only
- sample count: `1`
- `exec_ns` mean: `88`
- `compile_ns` mean: `6,315,746`
- native code bytes: `69`
- result distribution: `{12345678: 1}`

What this means:

- There is no kernel row in the captured `pure_jit.latest.json`.
- There is therefore no `L/K` exec geomean in this file.
- There are no significance results in this file.
- This artifact is a smoke/partial run, not a current full-suite summary.

Reproducibility issue:

- By the end of the audit, `git status --short` showed `D micro/results/pure_jit.latest.json`.
- So the repo currently does not contain a stable canonical latest micro result artifact.

### Best Available Full-Suite Micro Metrics

The freshest fuller suite-level micro summary in the repo is `micro/results/combined_40_summary.md` (generated `2026-03-08T20:17:15.075061+00:00`):

- combined pure-JIT benchmark count: `40`
- exec geomean (`L/K`): `0.844x`
- code-size geomean (`L/K`): `0.528x`
- llvmbpf exec wins: `29`
- kernel exec wins: `11`
- llvmbpf smaller code: `39`
- kernel smaller code: `1`
- significant pure-JIT benchmarks: `33 / 40`
- significant pure-JIT benchmarks excluding sub-resolution kernels: `29 / 35`

Coverage gap versus the current manifest:

- current manifest size: `56`
- covered by latest full-suite summary: `40 / 56` (`71.4%`)
- missing from that summary: `16 / 56` (`28.6%`)
- missing benchmarks:
  - `cmov_select`, `cmov_dense`
  - `load_word32`, `load_byte`, `load_byte_recompose`, `load_native_u64`
  - `bpf_call_chain`
  - `rotate64_hash`
  - `packet_redundant_bounds`
  - `const_fold_chain`
  - `struct_field_cluster`, `bitfield_extract`, `smallmul_strength_reduce`
  - `tc_bitcount`, `tc_checksum`, `cgroup_hash_chain`

### Artifact Completeness Audit

| Check | Result |
| --- | --- |
| Benchmarks missing `.bpf.o` | `0` |
| Benchmarks missing input generators | `0` |
| Benchmarks missing `expected_result` | `0` |
| Benchmarks missing referenced policy files | `0` |
| Benchmarks with `expected_result == 0` | `2` (`checksum`, `tc_checksum`) |

Interpretation:

- The micro manifest is internally complete.
- A zero return is not automatically a failure here; `checksum` and `tc_checksum` intentionally expect `0`.
- The quality issue is not manifest completeness; it is result freshness and canonical result stability.

## 2. Corpus

### Inventory Summary

- Corpus manifest: `corpus/config/corpus_manifest.yaml`
- Manifest projects: `23`
- `.bpf.o` files under manifest scope (`corpus/build`): `560`
- `.bpf.o` files under the entire `corpus/` tree: `632`
- Discovered programs: `2010`
- Loadable programs: `1280` (`63.7%`)
- Programs with directive sites: `293` (`14.6%`)
- True runnable programs: `391` (`19.5%`)
- Packet-candidate programs: `314`
- Packet-runnable programs: `176` (`56.1%` of packet candidates)
- Tracing-candidate programs: `1057`
- Tracing-positive programs: `215` (`20.3%` of tracing candidates)
- Per-program policy files in `corpus/policies/`: `157`
- Unique policy-bearing object stems: `147`

### Projects

| Project | Objects | Programs | Loadable | With Sites | Runnable | Types |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| KubeArmor | 3 | 63 | 0 | 0 | 0 | kprobe, lsm, tracepoint |
| bcc | 57 | 365 | 289 | 30 | 91 | kprobe, perf_event, raw_tracepoint, tracepoint, tracing |
| calico | 8 | 59 | 59 | 44 | 59 | sched_cls, xdp |
| cilium | 3 | 0 | 0 | 0 | 0 | - |
| coroot-node-agent | 1 | 46 | 46 | 16 | 16 | kprobe, tracepoint |
| datadog-agent | 2 | 1 | 1 | 0 | 0 | kprobe |
| katran | 5 | 5 | 5 | 2 | 5 | sched_cls, xdp |
| libbpf-bootstrap | 12 | 21 | 20 | 0 | 12 | kprobe, lsm, perf_event, sched_cls, tracepoint, tracing |
| linux-selftests | 369 | 892 | 565 | 59 | 138 | cgroup_skb, cgroup_sock, cgroup_sock_addr, cgroup_sockopt, ext, flow_dissector, kprobe, lsm, netfilter, perf_event, raw_tracepoint, sched_cls, sk_lookup, sk_msg, sk_reuseport, sk_skb, sock_ops, socket_filter, struct_ops, syscall, tracepoint, tracing, unspec, xdp |
| loxilb | 3 | 18 | 0 | 0 | 0 | unspec |
| manual-test | 2 | 4 | 4 | 0 | 4 | tracing |
| netbird | 1 | 0 | 0 | 0 | 0 | - |
| opentelemetry-ebpf-profiler | 3 | 0 | 0 | 0 | 0 | - |
| real_world_code_size | 15 | 24 | 23 | 0 | 14 | kprobe, lsm, perf_event, sched_cls, socket_filter, tracepoint, tracing |
| scx | 4 | 85 | 39 | 13 | 0 | struct_ops, syscall, tracepoint, tracing |
| suricata | 2 | 2 | 2 | 2 | 2 | xdp |
| systemd | 6 | 14 | 9 | 4 | 0 | cgroup_skb, cgroup_sock, cgroup_sock_addr, cgroup_sysctl, kprobe, lsm |
| tetragon | 23 | 90 | 14 | 0 | 0 | kprobe, lsm, raw_tracepoint, tracepoint, tracing, unspec |
| tracee | 2 | 170 | 170 | 110 | 26 | cgroup_skb, kprobe, lsm, raw_tracepoint |
| tubular | 1 | 1 | 0 | 0 | 0 | unspec |
| xdp-examples | 0 | 0 | 0 | 0 | 0 | - |
| xdp-tools | 13 | 99 | 5 | 3 | 4 | tracing, xdp |
| xdp-tutorial | 25 | 51 | 29 | 10 | 20 | sched_cls, tracepoint, unspec, xdp |

### Freshest Corpus Result Metrics

The repo currently contains two different corpus result families:

1. Fresh corpus recompile batch on the current manifest:

   - artifact: `corpus/results/corpus_v5_vm_batch_full.json`
   - generated_at: `2026-03-11T20:59:25.353666+00:00`
   - targets attempted: `166`
   - compile pairs: `163`
   - measured pairs: `163`
   - applied programs: `92`
   - exec-time geomean: `0.868x`
   - code-size geomean: `0.999x`
   - improvements: `40`
   - regressions: `107`

   Interpretation:

   - This is the freshest corpus performance artifact in the repo.
   - It measures recompile-vs-stock, not llvmbpf-vs-kernel.
   - The fresh result is net negative on execution time and basically neutral on code size.

2. Older llvmbpf-vs-kernel corpus comparison:

   - exec artifact: `corpus/results/real_world_exec_time_v2.json`
   - generated_at: `2026-03-07T23:50:39.411451+00:00`
   - paired programs: `98`
   - exec geomean (`llvmbpf/kernel`): `0.514x`

   - code-size artifact: `corpus/results/real_world_code_size_v2.json`
   - generated_at: `2026-03-07T23:08:42.939988+00:00`
   - paired programs: `162`
   - code-size geomean (`llvmbpf/kernel`): `0.618x`

   Interpretation:

   - These are still the best llvmbpf-vs-kernel corpus geomeans in the repo.
   - They are stale relative to the current 2026-03-11 manifest and corpus expansion work.

### Fresh Tracing Coverage Result

`corpus/results/tracing_corpus_vm.json` (generated `2026-03-11T22:46:30.920751+00:00`) adds fresh tracing runnability coverage:

- programs considered: `724`
- ready programs: `473`
- skipped programs: `251`
- inventory failures: `88`
- ready by project: `bcc 237`, `linux-selftests 229`, `libbpf-bootstrap 7`

Dominant skip reasons:

- missing attach target in section name: `34`
- workload heuristics missing for many tracing sections/programs

### Policy Coverage

- Policy files: `157`
- Coverage versus site-bearing programs: `53.6%` (`157 / 293`)
- Coverage versus measured objects: `28.0%` (`157 / 560`)
- Coverage versus discovered programs: `7.8%` (`157 / 2010`)

Interpretation:

- Policy coverage is meaningful but incomplete even within the site-bearing subset.
- The corpus has many candidate programs that still have no dedicated per-program policy artifact.

## 3. End-to-End Benchmarks

### Cases Present

Actual case directories under `e2e/cases/`:

- `bpftrace`
- `scx`
- `tetragon`
- `tracee`

### Latest Results

| Case | Generated At | Baseline Data | Recompile Data | Applied Programs | Site/Requested Programs | Key Result | Notes |
| --- | --- | --- | --- | ---: | --- | --- | --- |
| scx | 2026-03-11T16:36:43.475678+00:00 | yes | no | 0 | 7 | baseline only | post-ReJIT measurements are unavailable |
| bpftrace | 2026-03-11T16:38:36.319564+00:00 | yes | partial | 2 | 2 | speedup geomean 0.992x | 5 scripts, 2 comparable |
| tracee | 2026-03-11T16:39:51.842923+00:00 | yes | yes | 8 | 15 | 3 workloads comparable | smoke=true |
| tetragon | 2026-03-11T17:29:08.953023+00:00 | yes | yes | 1 | 5 | 4 workloads comparable | smoke=true |

### Which Cases Have Real Recompile Data?

- `scx`: no real post-recompile comparison data; baseline-only.
- `bpftrace`: partial real recompile data.
  - `5` scripts selected.
  - `2` scripts had eligible sites and successful re-JIT measurements.
  - Geomean speedup: `0.9917x`.
  - `open_latency` improved (`1.012x`), `scheduler_latency` regressed (`0.971x`), `3` scripts were baseline-only because they had no eligible sites.
- `tracee`: yes, real post-recompile data.
  - `8 / 15` requested programs applied.
  - Comparable across `3` workloads.
  - Workload app throughput deltas: `+21.7%`, `+5.1%`, `+1.3%`.
  - BPF avg ns deltas: `-2.63%`, `-0.19%`, `+1.86%`.
  - Still a smoke run.
- `tetragon`: yes, real post-recompile data.
  - `1 / 5` requested programs applied.
  - Comparable across `4` workloads.
  - Workload app throughput deltas: from `-10.2%` to `+6.7%`.
  - BPF avg ns deltas: from `-26.2%` to `-1.0%`.
  - Still a smoke run.

## 4. Quality Issues

### Micro

- The micro manifest is complete, but the canonical latest result is not.
- The captured `pure_jit.latest.json` only measured `simple` with `llvmbpf`, so it cannot support current suite-level `L/K` geomeans or significance claims.
- The freshest full micro summary (`combined_40_summary.md`) is stale against the current `56`-benchmark manifest and misses `16` current benchmarks.
- The nominal latest micro artifact disappeared during the audit (`git status` showed `D micro/results/pure_jit.latest.json`), which is a reproducibility problem.
- No micro benchmark is currently missing its `.bpf.o`, input generator, or `expected_result`.
- The only expected-zero benchmarks are `checksum` and `tc_checksum`; zero return values there are intentional, not failures.

### Corpus

- Runnability is still the main bottleneck.
  - Only `391 / 2010` discovered programs are true runnable.
  - `11 / 23` projects have zero runnable programs: `KubeArmor`, `cilium`, `datadog-agent`, `loxilb`, `netbird`, `opentelemetry-ebpf-profiler`, `scx`, `systemd`, `tetragon`, `tubular`, `xdp-examples`.
  - `7 / 23` projects have zero loadable programs.
- The fresh recompile batch is not yet a strong positive result.
  - exec geomean `0.868x`
  - code-size geomean `0.999x`
  - `40` improvements versus `107` regressions
- There were no timeouts in the fresh `corpus_v5_vm_batch_full.json` batch, but there were repeatable compile failures:
  - `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple`
  - `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple`
  - `corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter`
- Failure reasons in that fresh batch were:
  - `bpf_object__load failed: Permission denied (exit=1)` = `4`
  - `bpf_object__load failed: Argument list too long (exit=1)` = `2`
  - recompile failures: `BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7)` = `4`
- The older llvmbpf-vs-kernel exec result has many kernel test-run failures:
  - `61` kernel `bpf_prog_test_run_opts failed: Unknown error 524`
  - `1` kernel `Bad address`
  - `62` llvmbpf runs skipped because the kernel peer run failed
  - `2` llvmbpf unknown errors
- Those older failures are clustered heavily in the BCF Cilium objects:
  - `*_bpf_sock.o` variants dominate exec-time failures
  - `*_bpf_lxc.o`, `*_bpf_host.o`, and `*_bpf_overlay.o` dominate code-size kernel failures across many compiler-versioned variants
- The fresh tracing inventory still has `88` inventory failures, mostly concentrated in `linux-selftests` CO-RE/selftest artifacts that `list-programs` cannot inventory cleanly in this environment.

### End-to-End

- `scx` has no post-recompile measurement at all because `BPF_PROG_JIT_RECOMPILE` did not apply.
- `bpftrace` only has `2` comparable scripts out of `5`.
- `tracee` and `tetragon` have real comparisons, but both are `smoke=true`.
- There is still no convincing end-to-end datapath benchmark for a production XDP/TC stack with before/after recompile comparison.

### Stale / Outdated Result Files

Definitely stale relative to the current inventory:

- `micro/results/combined_40_summary.md`
- `micro/results/pure_jit_authoritative_analysis.md`
- `micro/results/performance_deep_analysis.md`
- `corpus/results/real_world_exec_time_v2.json`
- `corpus/results/real_world_code_size_v2.json`

Why they are stale:

- they predate the 2026-03-11 corpus manifest refresh or the current 56-benchmark micro manifest;
- they remain useful historical evidence, but they are not current authoritative snapshots of the present suite.

## 5. Representativeness

### What Is Strongly Covered

- Micro codegen shapes:
  - scalar ALU mixes
  - dependency chains / ILP
  - branch density and select diamonds
  - packet parsing and bounds-heavy memory access
  - loop shapes
  - code size / mega-block scaling
  - BPF-to-BPF local calls
  - packet-mode and TC/cgroup kernel-only variants
- Corpus program types:
  - `xdp`, `sched_cls`
  - `kprobe`, `tracepoint`, `tracing`, `raw_tracepoint`
  - `lsm`
  - multiple `cgroup_*` types
  - `socket_filter`, `flow_dissector`, `sk_*`, `sock_ops`
  - `struct_ops`
- End-to-end products:
  - `bpftrace`
  - `tracee`
  - `tetragon`
  - `scx`

### What Is Missing or Weakly Covered

- Fresh full-suite micro comparisons for the current manifest.
- A canonical fresh micro result that includes both `llvmbpf` and `kernel`.
- Fresh corpus llvmbpf-vs-kernel exec/code-size geomeans on the current 23-project manifest.
- High-runnability coverage for important production projects:
  - `KubeArmor`
  - `systemd`
  - `tetragon`
  - `scx`
  - `loxilb`
- End-to-end datapath evaluation for a real XDP/TC service stack such as `calico`, `cilium`, `katran`, or `xdp-tools`.
- End-to-end cgroup / LSM policy evaluation with comparable before/after recompile data.
- Non-smoke long-duration daemon measurements for `tracee` and `tetragon`.

### Overall Representativeness Judgment

The suite is broad enough to be interesting and much more representative than a pure synthetic micro-only evaluation. The corpus covers real projects and many BPF program types. The problem is not breadth of declared inventory; it is that fresh, comparable, authoritative measurements lag the inventory.

## 6. Recommendations

1. Recreate a canonical full micro result.
   - Run the full `56`-benchmark micro suite with at least `llvmbpf` and `kernel`, and ideally `kernel-recompile`.
   - Regenerate a single authoritative summary and point `pure_jit.latest.json` or an equivalent `latest` artifact at it.

2. Refresh corpus llvmbpf-vs-kernel metrics on the current manifest.
   - Regenerate exec-time and code-size results for the current `23`-project, `560`-object corpus.
   - Publish explicit `latest` pointers for corpus exec and code-size results.

3. Improve runnable coverage before claiming corpus representativeness.
   - Prioritize `KubeArmor`, `systemd`, `tetragon`, `scx`, and `loxilb`.
   - Reduce tracing inventory failures and fill missing workload heuristics / attach-target mappings.

4. Expand policy coverage.
   - `157` policy files is a good start, but it is only `53.6%` of site-bearing programs and `7.8%` of all discovered programs.
   - Increase coverage for high-value site-bearing programs first.

5. Add stronger end-to-end anchors.
   - One production datapath E2E benchmark with real pre/post recompile data.
   - One policy/security E2E benchmark with cgroup or LSM emphasis.
   - At least one non-smoke daemon benchmark run for `tracee` and `tetragon`.

6. Separate smoke from authoritative outputs.
   - The repo currently mixes smoke, spotcheck, and authoritative results under similar naming.
   - Add clear naming or directory conventions so “latest authoritative” is unambiguous.

## 7. Summary Narrative

If the goal is to show that the project already has a broad and thoughtfully designed benchmark inventory, the answer is yes. The micro suite is structurally strong, the corpus is large and diverse, and there are credible real-world and end-to-end hooks.

If the goal is to show that the current checked-in evaluation data is already fully convincing, the answer is no. The main issues are freshness, canonical result stability, and runnable coverage. The older micro and corpus llvmbpf-vs-kernel numbers are directionally strong, but they are not fully current. The freshest corpus recompile batch is actually net negative on execution time. The end-to-end results are useful but still too narrow and too smoke-heavy to carry the whole evaluation.

The current state is best described as: strong inventory, mixed measurement quality, and a clear path to a much more convincing evaluation with one refreshed micro sweep, one refreshed corpus llvmbpf-vs-kernel sweep, and 2-3 stronger end-to-end anchors.
