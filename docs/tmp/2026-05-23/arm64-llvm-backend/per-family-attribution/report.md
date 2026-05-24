# ARM64 REV / EXTR Per-Family Attribution

Date: 2026-05-23.

## Summary

The per-family attribution run completed on AWS ARM64 `t4g.small`.

The experiment compares four configurations:

| Configuration | Meaning |
|---|---|
| `baseline` | normal clang |
| `control-disabled` | custom `llc`, ARM64 target selected, all kinsns disabled |
| `treatment-rev-only` | custom `llc`, ARM64 `REV` enabled only |
| `treatment-extr-only` | custom `llc`, ARM64 `EXTR` enabled only |

Each successful configuration completed 29 micro benchmarks across `native`
and `kernel` runtimes with 174 samples and 0 failed samples.

Main result:

- `REV-only` selected 2 `bpf_arm64_rev_*` symbols in 1 benchmark. The selected
  benchmark median was neutral: `1.000000` for both `native` and `kernel`.
- `EXTR-only` selected 7 `bpf_arm64_extr_*` symbols in 7 benchmarks. The selected
  `kernel` median treatment/control was `0.959916`; selected `native` was
  `1.000000`.
- Therefore the earlier combined `REV+EXTR` selected-kernel improvement is
  primarily attributable to `EXTR`, not `REV`.

This is still an implementation attribution run, not a paper-grade performance
claim.

## What The LLVM Backend Does Here

This ARM64 work is not a normal AArch64 LLVM backend. It extends the LLVM BPF
backend with an ARM64 kinsn-aware path:

```text
BPF IR / MachineInstr
  -> LLVM BPF backend selector
  -> ARM64 kinsn pseudo MachineInstr
  -> AsmPrinter payload packing
  -> KINSN_SIDECAR + KINSN_CALL in the BPF object
  -> extern bpf_arm64_* kfunc symbol
  -> kernel verifier / module proof-expansion checks
  -> runtime lowering to native ARM64 instructions
```

The LLVM side is responsible for selecting the right pattern, emitting the
right pseudo, and packing a payload that matches the decoder ABI under:

```text
/home/ruoji/github/bpf-opt/code/module/arm64
```

It does not directly emit AArch64 machine code. Native lowering happens on the
kernel/module side after the BPF object is loaded.

In this experiment:

- `REV` means the ARM64 endian / byteswap family. The implemented symbols are
  `bpf_arm64_rev16_w`, `bpf_arm64_rev_w`, and `bpf_arm64_rev_x`; this run
  selected the first two.
- `EXTR` means the ARM64 rotate / extract family. The implemented symbols are
  `bpf_arm64_extr_w` and `bpf_arm64_extr_x`; this run selected both.

Correctness is judged by more than symbol presence:

- `control-disabled` must produce 0 `bpf_arm64_*` and 0 `bpf_x86_*` symbols.
- `treatment-rev-only` must produce only `bpf_arm64_rev_*` symbols.
- `treatment-extr-only` must produce only `bpf_arm64_extr_*` symbols.
- AWS ARM64 `native` and `kernel` runtimes must load and execute the objects.
- Every runtime sample must match the benchmark's configured expected result.

All four successful configurations completed 29 benchmarks with 174 samples and
0 failed samples.

## Micro Benchmark Suite

This experiment ran the micro suite from:

```text
/home/ruoji/github/bpf-opt/code/micro
```

The benchmark configuration file is:

```text
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

Each case has a fixed `base_name`, input generator, input size, expected result,
and tag set. This run used:

```text
RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

It did not run the `llvmbpf` userspace runtime because that runtime still does
not support `bpf_arm64_*` externs. Treatment objects containing ARM64 kinsns
must currently be validated through `native` and `kernel`.

"Affected by kinsn" means the generated object for that treatment contains an
actual `bpf_arm64_*` kfunc symbol. Source-level shifts or rotates alone are not
enough; the LLVM selector must see the canonical MachineInstr pattern, the
register constraints must fit the kinsn ABI, and the family mode must be
enabled.

| Case | Main coverage | Current ARM64 kinsn impact |
|---|---|---|
| `simple` | Minimal runner/runtime baseline | none |
| `simple_packet` | Packet-backed baseline | none |
| `bitmap_popcount_scan` | Bitmap scan and popcount | none |
| `sorted_rule_binary_search` | Sorted rule-table binary search | none |
| `bcc_runqlat_log2_histogram_bucket` | BCC runqlat-style log2 histogram bucket | none |
| `trace_event_type_switch_dispatch` | Trace event type switch dispatch | none |
| `packet_checksum_fold` | Checksum fold / memory scan | none |
| `payload_prefix_memcmp_scan` | Payload prefix memcmp / byte-compare scan | `EXTR` |
| `packet_vlan_tcpopt_parser` | VLAN / TCP option parser, bounds and variable offsets | none |
| `bpf_local_call_fanout_dispatch` | BPF-to-BPF local calls, fanout, register pressure | none |
| `flow_5tuple_rss_hash` | Packet 5-tuple parse and RSS/hash | `EXTR` |
| `katran_lb_consistent_hash_select` | Katran LB hash / backend select, endian and rotate | `REV` + `EXTR` |
| `cilium_policy_guard_tree_filter` | Cilium policy guard tree / nested branches | none |
| `siphash_rotate64_mixer` | SipHash rotate-heavy mixer | `EXTR` |
| `packet_record_bounds_window` | Packet bounds / redundant-check window | none |
| `flow_record_field_scan` | Fixed-offset record field scan | none |
| `packed_header_bitfield_decode` | Packed header bitfield extract | none currently; future `UBFM` candidate |
| `bpftrace_string_search_prefix_scan` | bpftrace-style string prefix search | `EXTR` |
| `tracee_syscall_name_table_lookup` | Tracee syscall id/name lookup dispatch | none |
| `tracee_http_method_prefix_detect` | HTTP method prefix detect / string branch | none |
| `cilium_socket_lb_service_select` | Cilium socket LB service/backend select | none |
| `bcc_tcpconnect_ipv4_tuple_filter` | BCC tcpconnect IPv4 tuple filter | `EXTR` |
| `tetragon_process_event_arg_filter` | Tetragon process event arg / string filter | none |
| `otel_stack_frame_unwind_scan` | OpenTelemetry stack frame field scan | none |
| `cilium_ct_nat_tuple_rewrite` | Cilium conntrack/NAT tuple rewrite | `EXTR` |
| `packet_toeplitz_rss_hash` | Packet Toeplitz RSS hash | none |
| `bpftrace_comm_key_fnv_hash` | bpftrace comm-key FNV hash | none |
| `tc_packet_checksum_fold` | TC-style checksum fold | none |
| `cgroup_skb_hash_chain` | cgroup skb hash chain | none |

Selected symbols by affected case:

| Case | `REV-only` symbols | `EXTR-only` symbols |
|---|---|---|
| `katran_lb_consistent_hash_select` | `bpf_arm64_rev_w`, `bpf_arm64_rev16_w` | `bpf_arm64_extr_w` |
| `bcc_tcpconnect_ipv4_tuple_filter` | none | `bpf_arm64_extr_w` |
| `bpftrace_string_search_prefix_scan` | none | `bpf_arm64_extr_x` |
| `cilium_ct_nat_tuple_rewrite` | none | `bpf_arm64_extr_w` |
| `flow_5tuple_rss_hash` | none | `bpf_arm64_extr_w` |
| `payload_prefix_memcmp_scan` | none | `bpf_arm64_extr_x` |
| `siphash_rotate64_mixer` | none | `bpf_arm64_extr_x` |

## Completeness Boundary

This is a complete development attribution run for the current `REV` and `EXTR`
families because it includes:

- normal clang baseline,
- same custom `llc` with `all=disable`,
- `REV-only` and `EXTR-only` family treatments,
- object-level symbol isolation,
- AWS ARM64 `native` / `kernel` full micro correctness,
- selected-benchmark performance attribution,
- AWS wall-time, cost, and cleanup records.

It is not yet a paper-grade performance result: each configuration has only 3
samples, there are no confidence intervals, there is no corpus benchmark, and
CPU/noise control is still limited.

## Environment

Commands were launched from:

```text
/home/ruoji/github/bpf-opt
```

Environment:

| Field | Value |
|---|---|
| Platform | AWS ARM64 |
| Region | `us-east-1` |
| Instance type | `t4g.small` |
| Remote user | `ec2-user` |
| Kernel | `7.0.0-rc2+` |
| Runtime container | `bpf-benchmark/runner-runtime:arm64` |
| Root volume | 32 GB gp3 |
| Runtimes | `native kernel` |
| Samples | `SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000` |
| Custom `llc` | `/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc` |

## Results

Run summary:

```text
attempt              benchmarks  runs  failed_samples  status     object_count  kfunc_symbols  arm64_rev_symbols  arm64_extr_symbols  arm64_symbols  x86_symbols
baseline             29          174   0               completed  29            0              0                  0                   0              0
control-disabled     29          174   0               completed  29            0              0                  0                   0              0
treatment-rev-only   29          174   0               completed  29            2              2                  0                   2              0
treatment-extr-only  29          174   0               completed  29            7              0                  7                   7              0
```

Directional summary:

```text
treatment  scope     runtime  benchmarks  median_treatment_over_control  wins_lt_0_98  losses_gt_1_02  neutral
rev        all       native   29          1.000000                       1             4               24
rev        all       kernel   29          1.000604                       1             5               23
rev        selected  native   1           1.000000                       0             0               1
rev        selected  kernel   1           1.000000                       0             0               1
extr       all       native   29          1.000000                       1             6               22
extr       all       kernel   29          1.000000                       5             6               18
extr       selected  native   7           1.000000                       0             2               5
extr       selected  kernel   7           0.959916                       4             1               2
```

Selected benchmark detail:

```text
benchmark                           runtime  baseline_ns  control_disabled_ns  treatment_rev_only_ns  rev_over_control  rev_kfuncs  treatment_extr_only_ns  extr_over_control  extr_kfuncs
bcc_tcpconnect_ipv4_tuple_filter    native   150          149                  150                    1.006711          0           170                     1.140940           1
bcc_tcpconnect_ipv4_tuple_filter    kernel   322          319                  320                    1.003135          0           344                     1.078370           1
bpftrace_string_search_prefix_scan  native   352          352                  358                    1.017045          0           363                     1.031250           1
bpftrace_string_search_prefix_scan  kernel   516          516                  517                    1.001938          0           517                     1.001938           1
cilium_ct_nat_tuple_rewrite         native   197          197                  198                    1.005076          0           197                     1.000000           1
cilium_ct_nat_tuple_rewrite         kernel   474          474                  475                    1.002110          0           455                     0.959916           1
flow_5tuple_rss_hash                native   18           18                   18                     1.000000          0           18                      1.000000           1
flow_5tuple_rss_hash                kernel   47           48                   48                     1.000000          0           38                      0.791667           1
katran_lb_consistent_hash_select    native   28           27                   27                     1.000000          2           27                      1.000000           1
katran_lb_consistent_hash_select    kernel   63           61                   61                     1.000000          2           58                      0.950820           1
payload_prefix_memcmp_scan          native   169          169                  169                    1.000000          0           169                     1.000000           1
payload_prefix_memcmp_scan          kernel   289          288                  288                    1.000000          0           289                     1.003472           1
siphash_rotate64_mixer              native   44           44                   44                     1.000000          0           44                      1.000000           1
siphash_rotate64_mixer              kernel   162          160                  162                    1.012500          0           107                     0.668750           1
```

Symbol-level attribution:

```text
treatment-rev-only   katran_lb_consistent_hash_select       bpf_arm64_rev_w,bpf_arm64_rev16_w
treatment-extr-only  bcc_tcpconnect_ipv4_tuple_filter       bpf_arm64_extr_w
treatment-extr-only  bpftrace_string_search_prefix_scan     bpf_arm64_extr_x
treatment-extr-only  cilium_ct_nat_tuple_rewrite            bpf_arm64_extr_w
treatment-extr-only  flow_5tuple_rss_hash                   bpf_arm64_extr_w
treatment-extr-only  katran_lb_consistent_hash_select       bpf_arm64_extr_w
treatment-extr-only  payload_prefix_memcmp_scan             bpf_arm64_extr_x
treatment-extr-only  siphash_rotate64_mixer                 bpf_arm64_extr_x
```

## Cost

Cost summary:

```text
attempt              instance_id          wall_seconds  ec2_usd      ebs_usd      total_usd    state
baseline             i-06d826def0fce2e3c  295           0.001376667  0.000287367  0.001664033  terminated
control-disabled     i-051214484052842f1  351           0.001638000  0.000341918  0.001979918  terminated
treatment-rev-only   i-0f81d4555d47846b5  340           0.001586667  0.000331202  0.001917869  terminated
treatment-extr-only  i-0403fcb77552967c9  336           0.001568000  0.000327306  0.001895306  terminated
```

Total estimated cost:

```text
$0.007457126
```

The estimate excludes data transfer, taxes, free tier, credits, Savings Plans,
Reserved Instances, and account-level discounts.

No tagged ARM64 instance remained active after the runs.

## Data

Summary data:

```text
data/run-result-summary.tsv
data/object-symbol-summary.tsv
data/perf-directional-summary.tsv
data/perf-selected-kfunc-benchmarks.tsv
data/aws-cost-summary.tsv
data/aws-cost-total.txt
data/aws-active-after-runs.json
data/aws-volumes-after-runs.json
data/run-contract.json
```

Raw failed-attempt logs:

```text
data/baseline-run.stdout.log
data/baseline-run.stderr.log
data/baseline-exit-code.txt
```

Full local experiment record:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
```
