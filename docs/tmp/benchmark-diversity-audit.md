# Benchmark Diversity Audit

Generated: 2026-03-11

Scope read for this audit:

- `config/micro_pure_jit.yaml`
- `config/micro_runtime.yaml`
- all `67` files under `micro/programs/*.bpf.c`
- `corpus/config/corpus_manifest.yaml`
- `corpus/build/**/*.bpf.o` via `micro_exec list-programs`
- `corpus/run_corpus_runnability.py`
- `corpus/_driver_impl_run_corpus_v5_framework.py`
- `corpus/_driver_impl_run_corpus_perf.py`
- `e2e/run.py` and `e2e/cases/*`
- `docs/kernel-jit-optimization-plan.md`

Kernel references used for `BPF_PROG_TEST_RUN` / `BPF_PROG_RUN` support:

- [docs.kernel.org/bpf/bpf_prog_run.html](https://docs.kernel.org/bpf/bpf_prog_run.html)
- [docs.kernel.org/bpf/libbpf/program_types.html](https://docs.kernel.org/bpf/libbpf/program_types.html)

## Executive Summary

- Current micro coverage is still overwhelmingly XDP. Across both suites there are `67` configured micro benchmarks: `64` XDP, `2` tc, and `1` cgroup_skb. There are `0` tracing, `0` LSM, and `0` struct_ops micro benchmarks.
- `micro_runtime` is narrower than `micro_pure_jit`: all `11` runtime-sensitive micros are XDP, so runtime diversity is effectively missing today.
- The corpus is much richer than the micro layer. Successful inventory finds `2010` programs from `463` objects (`560` objects on disk, `97` inventory failures). Of those, `1918` are non-XDP.
- The harness diversity gap is not the same as the corpus diversity gap. Current repo automation only treats `314` programs as generic packet `test_run` candidates, while `1057` tracing-family programs are still attach-trigger only, `75` LSM programs need custom harnesses, and `118` struct_ops programs need registration.
- E2E coverage is the mirror image of micro: it covers tracing/kprobe/LSM/struct_ops through real attach + workload, but has no XDP/tc/cgroup deployment benchmark.
- The biggest short-term win is to add tc and cgroup_skb timed corpus benchmarks now, then close the raw_tracepoint / `BPF_PROG_TYPE_TRACING` harness gap.

## 1. Current Benchmark Type Distribution

### 1.1 Micro Benchmarks

#### Top-line counts

| Suite | Benchmarks | XDP | tc | cgroup_skb | tracing | LSM | struct_ops |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `micro_pure_jit` | 56 | 53 | 2 | 1 | 0 | 0 | 0 |
| `micro_runtime` | 11 | 11 | 0 | 0 | 0 | 0 | 0 |
| Total | 67 | 64 | 2 | 1 | 0 | 0 | 0 |

#### What the suites really measure

- None of the micro suites are compile-only. The runner records both `compile_ns` and `exec_ns`, but the benchmark comparison is steady-state runtime execution in both llvmbpf and kernel.
- `micro_pure_jit` is codegen-focused, not runtime-free:
  - `48` cases are `staged` XDP and still do one `input_map` staging lookup in the wrapper.
  - `5` cases are `packet` XDP and remove staging helpers, so they are the cleanest codegen-oriented path.
  - `3` non-XDP breadth checks (`2` tc + `1` cgroup_skb) are `map`-backed wrappers and therefore still execute through map/result-map plumbing.
- `micro_runtime` intentionally mixes code generation with runtime service cost:
  - `8` cases are `map`-backed and dominated by map/helper/runtime mechanics.
  - `3` cases are staged helper-call stressors.

#### Scope legend

- `CJ-S`: codegen-focused runtime, staged input (`input_map` + XDP wrapper)
- `CJ-P`: codegen-focused runtime, packet-fed/helper-free XDP path
- `CJ-M`: codegen-focused breadth control, but still map-backed wrapper
- `RT-M`: runtime-dominant map/helper path
- `RT-H`: runtime-dominant helper path on staged input

#### `micro_pure_jit` inventory

| Benchmark | Type | Dominant content | Scope |
| --- | --- | --- | --- |
| `simple` | XDP | baseline floor | `CJ-S` |
| `simple_packet` | XDP | baseline floor | `CJ-P` |
| `memory_pair_sum` | XDP | fixed-width memory loads | `CJ-S` |
| `bitcount` | XDP | scalar ALU / popcount loop | `CJ-S` |
| `log2_fold` | XDP | scalar ALU + branches | `CJ-S` |
| `dep_chain_short` | XDP | dependency-chain compute | `CJ-S` |
| `dep_chain_long` | XDP | dependency-chain compute | `CJ-S` |
| `binary_search` | XDP | branch/search lowering | `CJ-S` |
| `branch_layout` | XDP | branch layout / predictability | `CJ-S` |
| `switch_dispatch` | XDP | switch / dispatch lowering | `CJ-S` |
| `branch_dense` | XDP | dense branch mesh | `CJ-S` |
| `cmov_select` | XDP | select-diamond / cmov-sensitive control flow | `CJ-S` |
| `cmov_dense` | XDP | dense select-diamond control flow | `CJ-S` |
| `checksum` | XDP | sequential memory reduction | `CJ-S` |
| `load_word32` | XDP | 32-bit load width path | `CJ-S` |
| `load_byte` | XDP | byte-at-a-time control path | `CJ-S` |
| `load_byte_recompose` | XDP | byte-recompose causal isolation | `CJ-S` |
| `load_native_u64` | XDP | aligned native 64-bit loads | `CJ-S` |
| `packet_parse` | XDP | packet-style parse + bounds checks | `CJ-S` |
| `bounds_ladder` | XDP | dense bounds ladder | `CJ-S` |
| `bounds_check_heavy` | XDP | repeated dependent bounds checks | `CJ-S` |
| `stride_load_4` | XDP | stride-based memory access | `CJ-S` |
| `stride_load_16` | XDP | wider-stride memory access | `CJ-S` |
| `mixed_alu_mem` | XDP | mixed ALU + memory | `CJ-S` |
| `spill_pressure` | XDP | register-pressure / spill stress | `CJ-S` |
| `multi_acc_4` | XDP | ILP / multi-accumulator compute | `CJ-S` |
| `multi_acc_8` | XDP | ILP / multi-accumulator compute | `CJ-S` |
| `fibonacci_iter` | XDP | loop recurrence | `CJ-S` |
| `fibonacci_iter_packet` | XDP | loop recurrence | `CJ-P` |
| `fixed_loop_small` | XDP | fixed-trip loop compute | `CJ-S` |
| `fixed_loop_large` | XDP | fixed-trip loop compute | `CJ-S` |
| `nested_loop_2` | XDP | nested-loop compute | `CJ-S` |
| `nested_loop_3` | XDP | nested-loop compute | `CJ-S` |
| `code_clone_2` | XDP | code-size / straight-line clone | `CJ-S` |
| `code_clone_8` | XDP | code-size / straight-line clone | `CJ-S` |
| `large_mixed_500` | XDP | large mixed compute + memory body | `CJ-S` |
| `large_mixed_1000` | XDP | large mixed compute + memory body | `CJ-S` |
| `bpf_call_chain` | XDP | BPF-to-BPF local calls | `CJ-S` |
| `memcmp_prefix_64` | XDP | byte compare + early-exit branching | `CJ-S` |
| `packet_parse_vlans_tcpopts` | XDP | variable-offset packet parse | `CJ-P` |
| `local_call_fanout` | XDP | BPF-to-BPF local-call fanout | `CJ-S` |
| `packet_rss_hash` | XDP | packet hash / endian / parse | `CJ-P` |
| `imm64_storm` | XDP | immediate-heavy straight-line body | `CJ-S` |
| `alu32_64_pingpong` | XDP | mixed-width ALU | `CJ-S` |
| `branch_fanout_32` | XDP | high-fanout branch control flow | `CJ-S` |
| `deep_guard_tree_8` | XDP | nested guard tree | `CJ-S` |
| `mega_basic_block_2048` | XDP | very large straight-line block | `CJ-S` |
| `rotate64_hash` | XDP | rotate/hash ALU pattern | `CJ-S` |
| `packet_redundant_bounds` | XDP | packet bounds redundancy | `CJ-P` |
| `const_fold_chain` | XDP | constant-heavy mixed-width compute | `CJ-S` |
| `struct_field_cluster` | XDP | clustered fixed-offset field loads | `CJ-S` |
| `bitfield_extract` | XDP | bitfield extract / field packing | `CJ-S` |
| `smallmul_strength_reduce` | XDP | LEA-like strength reduction | `CJ-S` |
| `tc_bitcount` | tc | compute control under tc wrapper | `CJ-M` |
| `tc_checksum` | tc | memory reduction under tc wrapper | `CJ-M` |
| `cgroup_hash_chain` | cgroup_skb | compute control under cgroup_skb wrapper | `CJ-M` |

#### `micro_runtime` inventory

| Benchmark | Type | Dominant content | Scope |
| --- | --- | --- | --- |
| `map_lookup_churn` | XDP | repeated array-map lookup | `RT-M` |
| `map_roundtrip` | XDP | lookup + update roundtrip | `RT-M` |
| `map_lookup_repeat` | XDP | repeated same-key lookup | `RT-M` |
| `hash_map_lookup` | XDP | hash-map lookup | `RT-M` |
| `percpu_map_update` | XDP | per-CPU map update | `RT-M` |
| `helper_call_1` | XDP | single helper dispatch | `RT-H` |
| `helper_call_10` | XDP | repeated helper dispatch | `RT-H` |
| `helper_call_100` | XDP | heavy helper dispatch | `RT-H` |
| `probe_read_heavy` | XDP | `bpf_probe_read_kernel` heavy path | `RT-M` |
| `get_time_heavy` | XDP | `bpf_ktime_get_ns` heavy path | `RT-M` |
| `atomic_counter_xadd` | XDP | map-value atomic update | `RT-M` |

#### Micro diversity conclusion

- If the paper wants program-type diversity across `XDP`, `tc`, `tracing/kprobe`, `LSM`, `cgroup`, and `struct_ops`, the current micro layer only covers:
  - `XDP`: strong
  - `tc`: token presence only (`2` compute controls)
  - `cgroup`: token presence only (`1` cgroup_skb compute control)
  - `tracing/kprobe`, `LSM`, `struct_ops`: completely absent
- Current runtime-sensitive micro coverage is even narrower:
  - `11/11` cases are XDP
  - `0` tc runtime cases
  - `0` cgroup runtime cases
  - `0` tracing/LSM/struct_ops runtime cases

### 1.2 Corpus Benchmarks

#### Inventory summary

- Objects on disk: `560`
- Successful inventory: `463`
- Inventory failures: `97`
- Programs discovered from successful inventory: `2010`
- Non-XDP programs: `1918`

Inventory failures are concentrated in:

- `cilium` static `tc/tail` / `xdp/tail` objects that current libbpf inventory rejects
- `netbird`
- `opentelemetry-ebpf-profiler`
- many `linux-selftests` artifacts with no real loadable program section

#### Program-type buckets relevant to the paper

| Bucket | Programs | Current repo timed path | Notes |
| --- | ---: | --- | --- |
| `xdp` | 92 | packet `test_run` | already dominant in micro |
| `tc` | 186 | packet `test_run` | strongest immediate non-XDP opportunity |
| `tracing_family` | 1306 | attach-trigger today | `549` kprobe, `453` tracing, `166` tracepoint, `118` raw_tracepoint, `21` perf_event |
| `lsm` | 83 | custom harness only | no generic timed path |
| `cgroup` | 40 | mixed | `8` cgroup_skb packet `test_run`, `32` other cgroup types need custom harness |
| `struct_ops` | 118 | registration required | `60` from `scx`, `58` from `linux-selftests` |
| `other` | 185 | mixed | includes syscall, socket, netfilter, unspec |

#### What can run today

- Current generic packet `test_run` candidate coverage in this repo: `314` programs
  - `92` XDP
  - `186` tc (`sched_cls`)
  - `8` cgroup_skb
  - `28` other packet-capable non-paper types (`socket_filter`, `flow_dissector`, `sk_skb`, `sk_msg`)
- Current successful packet-runnable subset recorded in the manifest: `176` programs
- Current paired packet comparisons recorded in the manifest: `84` programs
- Current attach-trigger coverage: `1057` tracing-family programs
- Current custom-harness buckets without generic timing:
  - `75` LSM
  - `118` struct_ops
  - `32` non-skb cgroup programs

#### Important mismatch: corpus diversity vs harness diversity

- The corpus already contains abundant non-XDP material, but the benchmark automation exposes only a slice of it.
- In particular, current upstream kernel docs list `RAW_TRACEPOINT`, `TRACING`, and `STRUCT_OPS` under `BPF_PROG_RUN` support, but the repo still routes:
  - all `118` raw_tracepoint programs to attach-trigger
  - all `453` `BPF_PROG_TYPE_TRACING` programs to attach-trigger
  - all `118` struct_ops/ext programs to registration-required
- So the repo’s current timed path is narrower than both the corpus and current upstream documentation.

#### Per-project distribution

Counts below are per-program counts from successful inventory. `pkt/tr/true` means:

- `pkt`: packet `test_run`-runnable programs
- `tr`: tracing-positive programs under attach-trigger
- `true`: total programs with a meaningful timed path in current repo data

| Project | xdp | tc | tracing | lsm | cgroup | struct_ops | other | pkt/tr/true |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| `KubeArmor` | 0 | 0 | 55 | 8 | 0 | 0 | 0 | `0/0/0` |
| `bcc` | 0 | 0 | 365 | 0 | 0 | 0 | 0 | `0/91/91` |
| `calico` | 8 | 51 | 0 | 0 | 0 | 0 | 0 | `59/0/59` |
| `coroot-node-agent` | 0 | 0 | 46 | 0 | 0 | 0 | 0 | `0/16/16` |
| `datadog-agent` | 0 | 0 | 1 | 0 | 0 | 0 | 0 | `0/0/0` |
| `katran` | 3 | 2 | 0 | 0 | 0 | 0 | 0 | `5/0/5` |
| `libbpf-bootstrap` | 0 | 1 | 19 | 1 | 0 | 0 | 0 | `1/11/12` |
| `linux-selftests` | 17 | 130 | 467 | 56 | 32 | 58 | 132 | `178/57/138` |
| `loxilb` | 0 | 0 | 0 | 0 | 0 | 0 | 18 | `0/0/0` |
| `manual-test` | 0 | 0 | 4 | 0 | 0 | 0 | 0 | `0/4/4` |
| `real_world_code_size` | 0 | 1 | 21 | 1 | 0 | 0 | 1 | `2/12/14` |
| `scx` | 0 | 0 | 14 | 0 | 0 | 60 | 11 | `0/0/0` |
| `suricata` | 2 | 0 | 0 | 0 | 0 | 0 | 0 | `2/0/2` |
| `systemd` | 0 | 0 | 1 | 7 | 6 | 0 | 0 | `2/0/0` |
| `tetragon` | 0 | 0 | 81 | 8 | 0 | 0 | 1 | `0/0/0` |
| `tracee` | 0 | 0 | 166 | 2 | 2 | 0 | 0 | `2/24/26` |
| `tubular` | 0 | 0 | 0 | 0 | 0 | 0 | 1 | `0/0/0` |
| `xdp-tools` | 42 | 0 | 57 | 0 | 0 | 0 | 0 | `42/0/4` |
| `xdp-tutorial` | 20 | 1 | 9 | 0 | 0 | 0 | 21 | `21/0/20` |

Projects currently missing or effectively absent from program-level counts:

- `cilium`: inventory blocked by static tail-program layout
- `netbird`: inventory failure
- `opentelemetry-ebpf-profiler`: inventory failure
- `xdp-examples`: no object promoted into current manifest

### 1.3 E2E Benchmarks

Current E2E is entirely live-attach/live-workload based. There is no `BPF_PROG_TEST_RUN` path in `e2e/run.py` or the case modules.

| Case | Types exercised | Measurement path | Notes |
| --- | --- | --- | --- |
| `tracee` | raw_tracepoint + kprobe + LSM | real daemon attach or manual live attach + workload | good security/tracing coverage, no packet data-plane |
| `tetragon` | tracepoint + kprobe | real daemon attach or manual live attach + workload | good tracing coverage, no tc/xdp/cgroup |
| `bpftrace` | tracepoint + kprobe/kretprobe | live attach + workload | broad tracing scripts, no network datapath |
| `scx` | struct_ops | real scheduler registration + scheduler-sensitive workload | only struct_ops case today |

E2E diversity gap:

- strong for tracing/kprobe/struct_ops
- some LSM coverage via `tracee`
- zero XDP E2E
- zero tc E2E
- zero cgroup E2E

## 2. `BPF_PROG_TEST_RUN` Support Matrix

The kernel docs use `BPF_PROG_RUN` / `bpf_prog_test_run_opts()`. This report uses “`test_run`” as shorthand for that same path.

### 2.1 Current upstream support vs current repo support

| Paper bucket | Canonical prog types / sections | Upstream `BPF_PROG_RUN` docs | Current repo timed path | Practical mechanism | Reuse `micro_exec`? |
| --- | --- | --- | --- | --- | --- |
| `XDP` | `BPF_PROG_TYPE_XDP` | Yes | Yes | raw packet + `xdp_md` | Yes |
| `tc` | `BPF_PROG_TYPE_SCHED_CLS/SCHED_ACT` | Yes | Yes | raw packet + `__sk_buff` | Yes |
| `tracing` | `BPF_PROG_TYPE_TRACING` (`fentry/fexit/fmod_ret/tp_btf/iter`) | Yes | No, repo uses attach-trigger | synthetic callback context or attach-trigger | Partial |
| `raw_tracepoint` | `BPF_PROG_TYPE_RAW_TRACEPOINT` | Yes | No, repo uses attach-trigger | synthetic raw-args context or attach-trigger | Partial |
| `kprobe` | `BPF_PROG_TYPE_KPROBE` style sections | Not listed in current docs | attach-trigger only | live attach + workload + `bpf_prog_info` runtime stats | No |
| `tracepoint` | `BPF_PROG_TYPE_TRACEPOINT` | Not listed in current docs | attach-trigger only | live attach + workload + `bpf_prog_info` runtime stats | No |
| `LSM` | `BPF_PROG_TYPE_LSM` / `lsm*` | Not listed in current docs | custom harness only | live attach to security hooks | No |
| `cgroup_skb` | `BPF_PROG_TYPE_CGROUP_SKB` | Yes | Yes | raw packet + `__sk_buff` | Yes |
| other `cgroup_*` | `cgroup_sock*`, `cgroup_sysctl`, `lsm_cgroup` | Not listed in current docs | custom harness only | cgroup/socket/sysctl-specific setup | No |
| `struct_ops` | `BPF_PROG_TYPE_STRUCT_OPS` | Yes | No generic path; only E2E registration path | synthetic callback ctx or real registration + workload | Partial / High effort |

### 2.2 What the current kernel docs explicitly cover

Current upstream docs explicitly list `BPF_PROG_RUN` support for:

- `SOCKET_FILTER`
- `SK_SKB`
- `XDP`
- `SCHED_CLS`
- `FLOW_DISSECTOR`
- `CGROUP_SKB`
- `SK_MSG`
- `RAW_TRACEPOINT`
- `TRACING`
- `SYSCALL`
- `NETFILTER`
- `STRUCT_OPS`

Implications for this repo:

- The current repo classification of `xdp`, `tc`, and `cgroup_skb` as packet `test_run` is aligned with current docs.
- The current repo classification of `raw_tracepoint` and `tracing` as attach-trigger only is conservative and now leaves documented `test_run` support unused.
- `kprobe`, `tracepoint`, and `LSM` still do not have a generic `test_run` path in the current docs, so attach-trigger or custom harness remains the right default.

## 3. Diversity Gap Analysis

### 3.1 Micro-layer gaps

- Current micro benchmarks are almost all XDP:
  - `64/67` total micro benchmarks are XDP
  - `2/67` are tc
  - `1/67` is cgroup_skb
- The three non-XDP micros are not realistic hook-path benchmarks. They are map-fed compute controls used for breadth, not true tracing/security/scheduler workloads.
- There are no micro benchmarks at all for:
  - `kprobe`
  - `tracepoint`
  - `raw_tracepoint`
  - `BPF_PROG_TYPE_TRACING`
  - `LSM`
  - `struct_ops`
- `micro_runtime` does not test non-XDP runtime mechanisms at all.

### 3.2 Corpus-layer gaps

- The corpus itself is not the bottleneck. It already contains:
  - `186` tc programs
  - `83` LSM programs
  - `40` cgroup programs
  - `118` struct_ops programs
  - `1306` tracing-family programs
- The bottleneck is measurement path diversity:
  - generic packet `test_run`: strong for `tc`, `xdp`, `cgroup_skb`
  - attach-trigger: strong for tracing/kprobe/tracepoint/raw_tracepoint
  - LSM / struct_ops / non-skb cgroup: weak or absent
- Non-XDP corpus size is already large enough for the paper:
  - `1918 / 2010` programs are non-XDP
  - but only `222 / 1918` non-XDP programs are on the current generic `test_run` path

### 3.3 E2E-layer gaps

- E2E already covers:
  - tracing / kprobe
  - some LSM
  - struct_ops
- E2E does not cover:
  - XDP deployment
  - tc deployment
  - cgroup deployment

### 3.4 Paper-alignment gap

Per `docs/kernel-jit-optimization-plan.md`, the paper framing spans networking, tracing/observability, security, and scheduling. In the concrete type taxonomy requested for the paper:

- `XDP`: over-covered in micro, present in corpus, absent in E2E
- `tc`: under-covered in micro, abundant in corpus, absent in E2E
- `tracing/kprobe`: absent in micro, abundant in corpus, strong in E2E
- `LSM`: absent in micro, present in corpus, light E2E presence
- `cgroup`: token micro presence, present in corpus, absent in E2E
- `struct_ops`: absent in micro, strong in corpus, present in E2E

So the main diversity problem is not global absence. It is layer imbalance:

- micro is too XDP-heavy
- corpus is diverse but under-executed
- E2E is tracing/struct_ops-heavy and has no network datapath case

## 4. Feasibility Analysis By Missing Type

| Type | Kernel `test_run` status | Alternative exec-time path if no generic `test_run` | Effort | Can reuse current `micro_exec`? | Audit verdict |
| --- | --- | --- | --- | --- | --- |
| `tc` | supported | not needed | Low | Yes | easiest missing paper bucket to scale immediately |
| `cgroup_skb` | supported | not needed | Low | Yes | easiest security-adjacent non-XDP addition |
| `raw_tracepoint` | supported in current docs | attach-trigger already exists | Medium | Partially | repo should promote this from attach-only to optional `test_run` |
| `BPF_PROG_TYPE_TRACING` | supported in current docs | attach-trigger already exists | Medium | Partially | promising, but needs type-aware synthetic contexts |
| `kprobe` / `tracepoint` | no generic support in current docs | attach-trigger + `bpf_prog_info.run_time_ns/run_cnt` | Medium | No | existing corpus/e2e machinery is the right reuse point |
| `LSM` | no generic support in current docs | live attach to security hooks + workload trigger | High | No | feasible, but hook-specific harness work is unavoidable |
| non-skb `cgroup_*` | no generic support in current docs | cgroup/socket/sysctl harness | Medium/High | No | useful for security breadth, but not the fastest path |
| `struct_ops` | supported in current docs | real registration + workload already exists in `scx` E2E | High | Partial | synthetic support is possible, but realistic evaluation still wants registration |

Key practical note:

- For `raw_tracepoint` and `tracing`, “supported by current kernel docs” does not mean the repo can immediately benchmark every such program with a zero-filled `ctx_in`. Meaningful use still needs per-type context synthesis and validation.
- For `kprobe`, `tracepoint`, and `LSM`, the existing attach-trigger path is already the right measurement model because it measures real hook execution, not a synthetic surrogate.

## 5. Concrete Recommendations

### 5.1 Highest-priority benchmark additions

| Priority | Program | Type | Measures | Corpus source | What to change | Effort |
| --- | --- | --- | --- | --- | --- | --- |
| `P0` | `calico_tc_main` | tc | main tc classifier / policy path | `calico` | add to corpus timed shortlist; no runner changes | Low |
| `P0` | `calico_tc_skb_send_tcp_rst` | tc | nontrivial tc packet rewrite / response path | `calico` | add to corpus timed shortlist; no runner changes | Low |
| `P0` | `cgroup_skb_ingress` | cgroup_skb | cgroup packet policy on ingress | `tracee` | add to corpus timed shortlist; no runner changes | Low |
| `P0` | `direct_packet_access` | cgroup_skb | direct packet access under cgroup hook | `linux-selftests` | add to corpus timed shortlist; no runner changes | Low |
| `P1` | `handle_sched_switch` | raw_tracepoint | scheduler event accounting | `bcc/runqlat.bpf.o` | either add to attach-trigger shortlist now, or add raw-tracepoint `ctx_in` generation in `micro/runner/src/kernel_runner.cpp` and relax classifier in `corpus/run_corpus_runnability.py` | Medium |
| `P1` | `block_rq_issue_btf` | tracing (`tp_btf`) | block-I/O tracing hot path | `bcc/biolatency.bpf.o` | add to tracing shortlist now; later add `BPF_PROG_TYPE_TRACING` synthetic context support | Medium |
| `P1` | `tracepoint__syscalls__sys_enter_execve` | tracepoint | syscall-entry tracing path | `bcc/execsnoop.bpf.o` | add trigger mapping / tracing shortlist; no `micro_exec` changes if attach-trigger | Medium |
| `P2` | `tcp_v4_connect` | kprobe | connect-path tracing | `bcc/tcpconnect.bpf.o` | add trigger mapping / tracing shortlist; no `micro_exec` changes if attach-trigger | Medium |
| `P2` | `exec` (`lsm.s/bprm_committed_creds`) | LSM | exec security hook | `linux-selftests/local_storage.bpf.o` | add LSM attach-trigger harness, likely reusing Tracee/Tetragon-style live attach patterns | High |
| `P3` | `test_1` | struct_ops | minimal struct_ops callback dispatch | `linux-selftests/dummy_st_ops_success.bpf.o` | either implement struct_ops `BPF_PROG_RUN` support in `micro_exec`, or add corpus registration harness derived from `e2e/cases/scx` | High |

### 5.2 Suggested code changes by path

#### A. Low-effort path: expand current packet `test_run` coverage

Use this first. It closes the paper’s `tc` and `cgroup_skb` gaps without touching the runner.

Likely files:

- `corpus/run_corpus_runnability.py`
- `corpus/_driver_impl_run_corpus_v5_framework.py`
- whichever target-selection layer you use for the timed corpus subset

Work:

- add explicit tc and cgroup_skb targets to the timed shortlist
- report them separately in the paper tables instead of letting them disappear inside “packet-runnable”

#### B. Medium-effort path: promote raw_tracepoint / tracing from attach-only to optional `test_run`

This is the biggest harness capability gap.

Likely files:

- `micro/runner/src/kernel_runner.cpp`
- `corpus/run_corpus_runnability.py`
- `corpus/_driver_impl_run_corpus_v5_framework.py`

Work:

- add type-aware `ctx_in` builders for `RAW_TRACEPOINT` and `TRACING`
- keep attach-trigger as fallback when a synthetic context is not trustworthy
- report these as a new “context `test_run`” bucket, separate from packet `test_run`

#### C. High-effort path: add real LSM / struct_ops timed harnesses

These are important for paper completeness, but they are not the fastest wins.

Likely reuse points:

- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/scx/case.py`
- `e2e/common/agent.py`

Work:

- for `LSM`: hook-specific live attach + workload mapping
- for `struct_ops`: either synthetic callback contexts or real registration + workload, with `scx` as the natural reuse path

## 6. Answers To The Specific Audit Questions

### What types are the current micro benchmarks?

- `64` XDP
- `2` tc
- `1` cgroup_skb
- `0` tracing
- `0` LSM
- `0` struct_ops

### How many non-XDP corpus programs are there? Can they run `test_run`?

- Non-XDP corpus programs: `1918 / 2010`
- Classified onto the current repo generic packet `test_run` path: `222`
  - `186` tc
  - `8` cgroup_skb
  - `28` other packet-capable non-paper types
- Successfully packet-runnable in the current manifest-backed measurements: a smaller subset of `176` total packet-runnable programs across all types
- Additional headroom left unused by current repo policy:
  - `118` raw_tracepoint programs have current upstream `BPF_PROG_RUN` docs support
  - `453` `BPF_PROG_TYPE_TRACING` programs have current upstream `BPF_PROG_RUN` docs support
  - `118` struct_ops/ext programs are also documented upstream, but realistic benchmarking still needs registration-aware handling

### Which types can only do code-size comparison today?

In the current repo, the strongest “code-size-only or loadability/site-only” buckets are:

- `LSM`
- `struct_ops` / `ext`
- non-skb `cgroup_*`
- `netfilter`
- several socket-lifecycle types
- inventory-failing projects such as `cilium`, `netbird`, and `opentelemetry-ebpf-profiler`

### Which types already have a real exec-time path?

- generic packet `test_run`: `XDP`, `tc`, `cgroup_skb`, plus some socket/filter/sockmap classes
- attach-trigger: `kprobe`, `tracepoint`, `raw_tracepoint`, `tracing`
- real E2E: tracing/kprobe/LSM/struct_ops through Tracee, Tetragon, bpftrace, and scx

## 7. Bottom Line

The repository already has enough corpus diversity for the paper, but the benchmark layers do not expose that diversity evenly:

- micro is still an XDP codegen study with only token non-XDP controls
- corpus has strong `tc`, `tracing/kprobe`, `LSM`, `cgroup`, and `struct_ops` presence, but only `tc` and `cgroup_skb` are easy generic timed paths today
- E2E covers tracing/security/scheduling, but misses network datapath types entirely

If the goal is to close the paper’s type-coverage gap quickly, the correct sequence is:

1. add tc and cgroup_skb corpus timed benchmarks now
2. add raw_tracepoint / `BPF_PROG_TYPE_TRACING` context `test_run` support
3. add one LSM attach-trigger benchmark
4. add one struct_ops synthetic or registration-backed corpus benchmark
