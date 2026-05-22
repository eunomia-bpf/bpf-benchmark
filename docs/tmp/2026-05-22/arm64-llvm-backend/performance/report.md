# ARM64 LLVM Backend Performance Validation

## Summary

The current ARM64 `REV` and `EXTR` implementation completed a full ARM64 micro
benchmark run on AWS. This is an implementation validation run, not a
paper-grade performance result: each configuration used only 3 samples and no
confidence intervals were computed.

The experiment compares three configurations:

| Configuration | Meaning |
|---|---|
| `baseline` | normal BPF object generation |
| `control-disabled` | same custom `llc`, ARM64 target selected, all kinsns disabled |
| `treatment-rev-extr` | same custom `llc`, ARM64 `REV` and `EXTR` enabled |

All three configurations completed 29 benchmarks across `native` and `kernel`
runtimes, with 174 total samples per configuration and 0 failed samples.

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

The `llvmbpf` runtime was not included because it does not currently support
BPF objects that reference `bpf_arm64_*` externs.

## Commands

Baseline:

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Control:

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable" \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Treatment:

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force" \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

## Results

Configuration summary:

```text
attempt             benchmarks  runs  failed_samples  status     object_count  kfunc_symbols  arm64_rev_symbols  arm64_extr_symbols  x86_symbols
baseline            29          174   0               completed  29            0              0                  0                   0
control-disabled    29          174   0               completed  29            0              0                  0                   0
treatment-rev-extr  29          174   0               completed  29            9              2                  7                   0
```

Median treatment/control summary:

```text
scope     runtime  benchmarks  median_treatment_over_control  wins_lt_0_98  losses_gt_1_02  neutral
all       native   29          1.000000                       2             6               21
all       kernel   29          1.000000                       5             3               21
selected  native   7           1.006711                       0             2               5
selected  kernel   7           0.968354                       4             0               3
```

The `selected` scope contains the 7 benchmarks whose treatment objects contain
at least one `bpf_arm64_*` symbol.

Selected benchmark detail:

```text
benchmark                              runtime  baseline_ns  control_disabled_ns  treatment_rev_extr_ns  treatment_over_control  kfuncs
bcc_tcpconnect_ipv4_tuple_filter       kernel   322          320                  315                    0.984375                1
bcc_tcpconnect_ipv4_tuple_filter       native   151          149                  150                    1.006711                1
bpftrace_string_search_prefix_scan     kernel   513          512                  511                    0.998047                1
bpftrace_string_search_prefix_scan     native   352          357                  362                    1.014006                1
cilium_ct_nat_tuple_rewrite            kernel   475          474                  459                    0.968354                1
cilium_ct_nat_tuple_rewrite            native   197          197                  201                    1.020305                1
flow_5tuple_rss_hash                   kernel   48           47                   38                     0.808511                1
flow_5tuple_rss_hash                   native   18           18                   19                     1.055556                1
katran_lb_consistent_hash_select       kernel   61           61                   58                     0.950820                3
katran_lb_consistent_hash_select       native   28           27                   27                     1.000000                3
payload_prefix_memcmp_scan             kernel   293          288                  289                    1.003472                1
payload_prefix_memcmp_scan             native   168          169                  170                    1.005917                1
siphash_rotate64_mixer                 kernel   160          160                  116                    0.725000                1
siphash_rotate64_mixer                 native   44           44                   44                     1.000000                1
```

Interpretation:

- Correctness: all configurations had 0 failed samples.
- Target isolation: treatment emitted 9 `bpf_arm64_*` symbols and 0
  `bpf_x86_*` symbols.
- Coverage: only 7 of 29 micro benchmarks used the new ARM64 kinsns, so the
  full-suite median remains `1.000000`.
- Kernel runtime has the clearest signal for selected benchmarks:
  median treatment/control is `0.968354`, with 4 benchmarks below `0.98` and
  0 above `1.02`.
- Native runtime does not show a stable benefit in this small sample:
  median treatment/control is `1.006711`.

## Cost

Price sources:

- EC2: AWS Pricing API, `t4g.small`, Linux, US East (N. Virginia), On-Demand,
  `$0.0168/hour`.
- EBS: AWS Pricing API, gp3 storage, US East (N. Virginia), `$0.08/GB-month`.
- Root volume: 32 GB.
- EBS month conversion: 730 hours/month.

Cost summary:

```text
attempt             instance_id           wall_seconds  ec2_usd      ebs_usd      total_usd    state
baseline            i-089b8041c31b2abbd   549           0.002562000  0.000534795  0.003096795  terminated
control-disabled    i-0627910b86b270d2e   470           0.002193333  0.000457839  0.002651172  terminated
treatment-rev-extr  i-0418498a591888bda   532           0.002482667  0.000518234  0.003000901  terminated
```

Total estimated cost:

```text
$0.008748868
```

The estimate excludes data transfer, taxes, free tier, credits, Savings Plans,
Reserved Instances, and account-level discounts.

## Data

Summary data:

```text
data/run-result-summary.tsv
data/perf-directional-summary.tsv
data/perf-selected-kfunc-benchmarks.tsv
data/perf-median-comparison.tsv
data/treatment-kfunc-symbols-normalized.tsv
data/aws-cost-summary.tsv
data/aws-cost-total.txt
```

Raw runner result JSON:

```text
data/baseline-result.json
data/control-disabled-result.json
data/treatment-rev-extr-result.json
```

Large transient session directories, JIT dumps, and code-compare markdown files
are intentionally not copied into this report directory.
